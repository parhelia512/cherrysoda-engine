#include <CherrySoda/Entity.h>

#include <CherrySoda/Scene.h>
#include <CherrySoda/Colliders/Collide.h>
#include <CherrySoda/Colliders/Collider.h>
#include <CherrySoda/Components/CollidableComponent.h>
#include <CherrySoda/Components/Component.h>
#include <CherrySoda/InternalUtilities/ComponentList.h>
#include <CherrySoda/InternalUtilities/EntityList.h>
#include <CherrySoda/InternalUtilities/TagLists.h>
#include <CherrySoda/Util/BitTag.h>
#include <CherrySoda/Util/Math.h>
#include <CherrySoda/Util/Pool.h>
#include <CherrySoda/Util/Profile.h>
#include <CherrySoda/Util/STL.h>

namespace cherrysoda {

Entity::Entity(const Math::Vec3& position)
{
	m_position = position;
	m_components = new ComponentList(this);
}

Entity::~Entity()
{
	delete m_components;
	m_components = nullptr;
}

void Entity::SceneBegin(Scene* scene)
{
}

void Entity::SceneEnd(Scene* scene)
{
	for (auto component : *m_components) {
		component->SceneEnd(scene);
	}
}

void Entity::Awake(Scene* scene)
{
	for (auto component : *m_components) {
		component->EntityAwake();
	}
}

void Entity::Update()
{
	CHERRYSODA_PROFILE_FUNCTION();

	m_components->Update();
}

void Entity::Render()
{
	CHERRYSODA_PROFILE_FUNCTION();

	m_components->Render();
}

void Entity::Tag(BitTagValueType tag)
{
	if (m_tag == tag) {
		return;
	}
	if (m_scene != nullptr) {
		for (int i = 0; i < BitTag::TotalTags(); ++i) {
			BitTagValueType check = 1 << i;
			bool add = (tag & check) != 0;
			bool has = (m_tag & check) != 0;
			if (has != add) {
				if (add) {
					STL::Add(m_scene->Tags()->operator[](i), this);
				}
				else {
					STL::Remove(m_scene->Tags()->operator[](i), this);
				}
			}
		}
	}
	m_tag = tag;
}

const STL::List<Entity*> Entity::CollideAll(const BitTag& tag) const
{
	CHERRYSODA_ASSERT(m_scene != nullptr, "Can't collide check an Entity against a tag list when it is not a member of a Scene\n");
	return Collide::All(this, (*m_scene)[tag]);
}

bool Entity::CollideCheck(const BitTag& tag) const
{
	CHERRYSODA_ASSERT(m_scene != nullptr, "Can't collide check an Entity against a tag list when it is not a member of a Scene\n");
	return Collide::Check(this, (*m_scene)[tag]);
}

bool Entity::CollideCheck(const BitTag& tag, const Math::Vec2& at)
{
	CHERRYSODA_ASSERT(m_scene != nullptr, "Can't collide check an Entity against a tag list when it is not a member of a Scene\n");
	return Collide::Check(this, (*m_scene)[tag], at);
}

bool Entity::CollideCheck(const Entity* other) const
{
	return Collide::Check(this, other);
}

bool Entity::CollideCheck(const Entity* other, const Math::Vec2& at)
{
	return Collide::Check(this, other, at);
}

bool Entity::CollideCheck(const CollidableComponent* other) const
{
	return Collide::Check(this, other);
}

bool Entity::CollideCheck(const CollidableComponent* other, const Math::Vec2& at)
{
	return Collide::Check(this, other, at);
}

bool Entity::CollidePoint(const Math::Vec2& point) const
{
	return Collide::CheckPoint(this, point);
}

bool Entity::CollideLine(const Math::Vec2& from, const Math::Vec2& to) const
{
	return Collide::CheckLine(this, from, to);
}

int Entity::CollideCount(const BitTag& tag) const
{
	CHERRYSODA_ASSERT(m_scene != nullptr, "Can't collide check an Entity against a tag list when it is not a member of a Scene\n");
	return Collide::Count(this, (*m_scene)[tag]);
}

Entity* Entity::CollideFirst(const BitTag& tag) const
{
	CHERRYSODA_ASSERT(m_scene != nullptr, "Can't collide check an Entity against a tag list when it is not a member of a Scene\n");
	return Collide::First(this, (*m_scene)[tag]);
}

float Entity::Left() const { return GetCollider() ? PositionX() + GetCollider()->Left() : PositionX(); }
float Entity::Right() const { return GetCollider() ? PositionX() + GetCollider()->Right() : PositionX(); }
float Entity::Bottom() const { return GetCollider() ? PositionY() + GetCollider()->Bottom() : PositionY(); }
float Entity::Top() const { return GetCollider() ? PositionY() + GetCollider()->Top() : PositionY(); }

void Entity::Left(float left)
{
	if (GetCollider()) {
		PositionX(left - GetCollider()->Left());
	}
	else {
		PositionX(left);
	}
}

void Entity::Right(float right)
{
	if (GetCollider()) {
		PositionX(right - GetCollider()->Right());
	}
	else {
		PositionX(right);
	}
}

void Entity::Bottom(float bottom)
{
	if (GetCollider()) {
		PositionY(bottom - GetCollider()->Bottom());
	}
	else {
		PositionY(bottom);
	}
}

void Entity::Top(float top)
{
	if (GetCollider()) {
		PositionY(top - GetCollider()->Top());
	}
	else {
		PositionY(top);
	}
}

void Entity::Add(Component* component)
{
	m_components->Add(component);
}

void Entity::Remove(Component* component)
{
	m_components->Remove(component);
}

void Entity::Add(const ComponentList::IterableComponents& components)
{
	m_components->Add(components);
}

void Entity::Remove(const ComponentList::IterableComponents& components)
{
	m_components->Remove(components);
}

void Entity::RemoveAllComponents()
{
	ComponentList::IterableComponents componentsCopy = m_components->m_components;
	m_components->Remove(componentsCopy);
}

void Entity::AutoDeleteWhenRemoved(PoolInterface* pool)
{
	m_onRemoved =
		[pool](Entity* entity, Scene* scene)
		{
			pool->INTERNAL_Hide(entity);
			entity->SetCollider(nullptr);
			entity->RemoveAllComponents();
			scene->AddActionOnEndOfFrame(
				[pool, entity]()
				{
					pool->INTERNAL_Destroy(entity);
				}
			);
		};
}

void Entity::Depth(int depth)
{
	if (m_depth != depth) {
		m_depth = depth;
		if (m_scene != nullptr) {
			m_scene->INTERNAL_SetActualDepth(this);
		}
	}
}

void Entity::DebugRender(Camera* camera)
{
	if (GetCollider() != nullptr)
		GetCollider()->Render(camera, Collidable() ? Color::Yellow : Color::DarkYellow);
	m_components->DebugRender(camera);
}

void Entity::HandleGraphicsReset()
{
	m_components->HandleGraphicsReset();
}

void Entity::HandleGraphicsCreate()
{
	m_components->HandleGraphicsCreate();
}

void Entity::RemoveSelf()
{
	if (m_scene != nullptr) {
		m_scene->Entities()->Remove(this);
	}
}

void Entity::Added(Scene* scene)
{
	m_scene = scene;
	for (auto component : *m_components) {
		component->EntityAdded(scene);
	}
	m_scene->INTERNAL_SetActualDepth(this);
}

void Entity::Removed(Scene* scene)
{
	for (auto component : *m_components) {
		component->EntityRemoved(scene);
	}
	if (m_onRemoved) {
		m_onRemoved(this, scene);
	}
	m_scene = nullptr;
}

void Entity::SetCollider(Collider* collider)
{
	if (m_collider == collider) {
		return;
	}
	CHERRYSODA_ASSERT(collider == nullptr || collider->GetEntity() == nullptr, "Setting an Entity's Collider to a Collider already in use by another object\n");

	if (m_collider != nullptr) {
		m_collider->Removed();
	}
	m_collider = collider;
	if (m_collider) {
		m_collider->Added(this);
	}
}

void Entity::AutoDeleteAllInsideWhenRemoved()
{
	AutoDeleteWhenRemoved();
	if (m_collider != nullptr) {
		m_collider->AutoDeleteWhenRemoved();
	}
	for (auto component : *m_components) {
		component->AutoDeleteWhenRemoved();
	}	
}

void Entity::CleanAndDeleteEntity(Entity* entity, Scene* scene)
{
	entity->SetCollider(nullptr);
	entity->RemoveAllComponents();
	scene->AddActionOnEndOfFrame([entity](){ delete entity; });
}

} // namespace cherrysoda
