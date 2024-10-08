#ifndef _MAINSCENE_H_
#define _MAINSCENE_H_

#include <CherrySoda/Scene.h>
#include <CherrySoda/Util/BitTag.h>

namespace cherrysoda {
class Entity;
class EverythingRenderer;
class SingleTagRenderer;
} // namespace cherrysoda

namespace main {

class MainScene : public cherrysoda::Scene
{
public:
	typedef cherrysoda::Scene base;

	void Begin() override;

	void InitializeTileObject(int id, cherrysoda::Entity* entity, int tileWidth, int tileHeight);

	static float GetControlAxisX();
	static float GetControlAxisY();
	static bool GetControlDownPressed();
	static bool JumpButtonPressed();
	static bool JumpButtonCheck();
};

} // namespace main

#endif // _MAINSCENE_H_
