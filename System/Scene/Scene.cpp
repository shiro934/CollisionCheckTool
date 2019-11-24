#include "Scene.h"

#include "..\\Input\InputKey.h"
#include "SceneType.h"

namespace app {
	namespace system {
		Scene::Scene()
			: next_scene_flag_(false)
		{
		}


		Scene::~Scene()
		{
		}
	}
}