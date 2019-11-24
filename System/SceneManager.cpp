#include "SceneManager.h"
#include "Scene\\TitleScene.h"
#include "Scene\SceneType.h"

#include "Input\\InputKey.h"

#include <windows.h>

#include <cassert>

namespace app {
	namespace system {
		SceneManager::SceneManager()
		{
			current_scene_ = new TitleScene();
		}


		SceneManager::~SceneManager()
		{
			delete current_scene_;
		}

		void SceneManager::Input(const InputKey* key) const {
			assert(current_scene_ != nullptr);
			current_scene_->Input(key);
		}

		void SceneManager::Update() const {
			assert(current_scene_ != nullptr);
			current_scene_->Update();
		}

		void SceneManager::Render() const {
			assert(current_scene_ != nullptr);
			current_scene_->Render();
		}

		void SceneManager::ChangeScene() {
			assert(current_scene_ != nullptr);

			//シーン遷移するかをチェック
			if (current_scene_->IsNextScene() == false) {
				return;
			}

			SceneType nextScene = current_scene_->NextSceneType();

			if (current_scene_) {
				delete current_scene_;
			}

			switch (nextScene)
			{
			case TITLE:
				current_scene_ = new TitleScene();
				break;
			default:
				MessageBox(nullptr, TEXT("nextSceneが正しくありません")
					, TEXT("エラー"), MB_OK);
				break;
			}

		}
	}
}