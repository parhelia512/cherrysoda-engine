#include "ChunkGraphicsComponent.h"

#include "Program.h"

#include <CherrySoda/Engine.h>
#include <CherrySoda/Graphics/Graphics.h>
#include <CherrySoda/Util/Color.h>
#include <CherrySoda/Util/Math.h>
#include <CherrySoda/Util/NumType.h>
#include <CherrySoda/Util/STL.h>

namespace crsd = cherrysoda;
using crsd::Engine;
using crsd::Entity;
using crsd::Math;
using crsd::Color;
using crsd::Graphics;
using crsd::STL;

void ChunkGraphicsComponent::EntityAwake()
{
	constexpr int chunkSize = Chunk::Size();
	constexpr float halfChunkSize = chunkSize * 0.5f;
	Origin(Math::Vec3(halfChunkSize));

	m_transformCache = GetChunkTransformMatrix();

	m_mesh.SetIsDynamic(true);
	RebuildMesh();
}

void ChunkGraphicsComponent::RebuildMesh()
{
	constexpr int chunkSize = Chunk::Size();
	constexpr float halfChunkSize = chunkSize * 0.5f;

	m_mesh.Clear();
	Chunk* chunk = (Chunk*)GetEntity();
	if (chunk == nullptr) return;
	STL::Vector<STL::Action> pendingActions;

	int overallQuadAmount = 0;
	for (int i = 0; i < chunkSize; ++i) {
		for (int j = 0; j < chunkSize; ++j) {
			for (int k = 0; k < chunkSize; ++k) {
				if (chunk->GetBlockType(i, j, k) == Block::Type::White) {
					if (overallQuadAmount * 4 + 8 > UINT16_MAX) {
						continue;
					}
					int planeMask = chunk->GetBlockSurrounding(i, j, k);
					if (planeMask > 0) {
						for (int i = 0; i < 6; ++i) {
							overallQuadAmount += (planeMask & (1 << i)) != 0;
						}
						STL::Add(pendingActions, [planeMask, i, j, k, this]() { AddCube(Math::Vec3(i, j, k), 1.f, Color::White, planeMask); });
					}
				}
			}
		}
	}
	m_mesh.ReserverAdditional(overallQuadAmount * 4, overallQuadAmount * 6);
	for (auto action : pendingActions) {
		action();
	}
	m_mesh.UpdateBuffer();
}

void ChunkGraphicsComponent::Update()
{
	// YRotation(YRotation() + Engine::Instance()->DeltaTime());
}

void ChunkGraphicsComponent::Render()
{
	if (!m_mesh.IsValid()) return;
	Graphics::SetSamplerTexCube(&GameApp::ms_texCube);
	Graphics::SetSamplerTexCubeIrr(&GameApp::ms_texCubeIrr);
	Graphics::Instance()->SetTransformMatrix(m_transformCache);
	Graphics::Instance()->SetMesh(&m_mesh);
	Graphics::SetStateDefault();
	Graphics::Instance()->Submit();
}

void ChunkGraphicsComponent::AddQuad(const Math::Vec3& pos, float size, const Color& color, const Math::Vec3& normal)
{
	bool positive = (normal == Math_Abs(normal));
	if (normal[1] != 0) positive = !positive;
	const auto pVec = (Vec3_One - Math_Abs(normal)) * size;
	const auto pVecH = normal[0] == 0.f ? Math::Vec3(size, 0.f, 0.f) : Math::Vec3(0.f, size, 0.f);
	const auto pVecV = normal[2] == 0.f ? Math::Vec3(0.f, 0.f, size) : Math::Vec3(0.f, size, 0.f);
	const auto cU32 = color.U32ABGR();
	if (positive) {
		m_mesh.AddQuad(
			VertexType::MakeVertex(pos + pVecV, cU32, normal),
			VertexType::MakeVertex(pos, cU32, normal),
			VertexType::MakeVertex(pos + pVec, cU32, normal),
			VertexType::MakeVertex(pos + pVecH, cU32, normal)
		);
	}
	else {
		m_mesh.AddQuad(
			VertexType::MakeVertex(pos + pVec, cU32, normal),
			VertexType::MakeVertex(pos + pVecH, cU32, normal),
			VertexType::MakeVertex(pos + pVecV, cU32, normal),
			VertexType::MakeVertex(pos, cU32, normal)
		);
	}
}

void ChunkGraphicsComponent::AddCube(const Math::Vec3& pos, float size, const Color& color, int planeMask)
{
	if (planeMask & (1 << 0)) AddQuad(pos + Vec3_XUp * size, size, color,  Vec3_XUp);
	if (planeMask & (1 << 1)) AddQuad(pos                  , size, color, -Vec3_XUp);
	if (planeMask & (1 << 2)) AddQuad(pos + Vec3_YUp * size, size, color,  Vec3_YUp);
	if (planeMask & (1 << 3)) AddQuad(pos                  , size, color, -Vec3_YUp);
	if (planeMask & (1 << 4)) AddQuad(pos + Vec3_ZUp * size, size, color,  Vec3_ZUp);
	if (planeMask & (1 << 5)) AddQuad(pos                  , size, color, -Vec3_ZUp);
}

const crsd::Math::Mat4 ChunkGraphicsComponent::GetChunkTransformMatrix() const
{
	return Math::TranslateMat4(
		Math::ScaleMat4(
			Math_Rotate(
				Math::TranslateMat4(
					Mat4_Identity,
					RenderPosition()),
				YRotation(), Vec3_YUp),
			Scale()),
		-Origin());
}