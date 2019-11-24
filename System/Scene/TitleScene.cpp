#include "TitleScene.h"

#include "SceneType.h"
#include "..\Input\InputKey.h"
#include "..\Input\InputKeyState.h"

#include "DxLib.h"

#include "../../Object/ObjectAABB.h"
#include "../../Object/ObjectSphere.h"

#include "../../System/CollisionCheck.h"

#include "../../ImGui/imgui.h"
#include "../../ImGui/imgui_impl_dxlib.h"

namespace app {
	namespace system {
		const unsigned int STRING_COLOR = 0x00ffff;	//文字の色

		TitleScene::TitleScene()
		{
			target_ = new ObjectAABB(VGet(200.0f, 300.0f, 0.0f), VGet(400.0f, 200.0f, 400.0f), GetColorU8(255, 0, 0, 255), "Target");
			another_target_ = new ObjectAABB(VGet(500.0f, 150.0f, 0.0f), VGet(600.0f, 100.0f, 200.0f), GetColorU8(0, 0, 255, 255), "AnotherTarget");

			object_code_ = another_target_->GetObjectCode();
		}

		TitleScene::~TitleScene()
		{
			if (target_) {
				delete target_;
				target_ = 0;
			}
			if (another_target_) {
				delete another_target_;
				another_target_ = 0;
			}
		}

		void TitleScene::Input(const InputKey* key) {
			//次のシーンへ遷移するフラグを立てる
			if (key->CheckKeyState(KEY_INPUT_SPACE) == KEY_DOWN) {
				next_scene_flag_ = true;
			}
		}

		void TitleScene::Update() {
			target_->Update();
			another_target_->Update();

			if (app::system::CollisionCheck::CheckAnyToAny(target_, another_target_)) {
				target_->SetColor(GetColorU8(255, 255, 0, 255));
				another_target_->SetColor(GetColorU8(0, 255, 0, 255));
			}
			else {
				target_->SetColor(GetColorU8(255, 0, 0, 255));
				another_target_->SetColor(GetColorU8(0, 0, 255, 255));
			}

			// ターゲットの切り替えメニュー
			ImGui::Begin("Menu");
			if (ImGui::Button("Change")) {
				ChangeObject();
			}
			ImGui::RadioButton("AABB", &object_code_, app::system::OBJECT_AABB);
			ImGui::RadioButton("Sphere", &object_code_, app::system::OBJECT_SPHERE);

			ImGui::End();
		}

		void TitleScene::Render() const {
	
			target_->Render();
			another_target_->Render();
		}

		SceneType TitleScene::NextSceneType() const {
			return TITLE;
		}

		void TitleScene::ChangeObject()
		{
			if (another_target_) {
				delete another_target_;
			}

			switch (object_code_) {
			case app::system::OBJECT_AABB: //AABB
				another_target_ = new ObjectAABB(VGet(500.0f, 150.0f, 0.0f), VGet(600.0f, 100.0f, 200.0f), GetColorU8(0, 0, 255, 255), "AnotherTarget");
				break;

			case app::system::OBJECT_SPHERE: //Sphere
				another_target_ = new ObjectSphere(VGet(500.0f, 150.0f, 0.0f), 100.0f, GetColorU8(0, 0, 255, 255), "AnotherTarget");
				break;
			}
		}
	}
}