#pragma once

#include "Scene.h"
#include "..\..\Object\Object.h"

namespace app {
	namespace system {

		class TitleScene :
			public Scene
		{
		public:
			TitleScene();
			~TitleScene();

			void Input(const InputKey* key) override final;
			void Update() override final;
			void Render() const override final;

			SceneType NextSceneType() const override final;

		private : 
			void ChangeObject();	//another_target�̃I�u�W�F�N�g�̐؂�ւ�

			int object_code_;	//���݂̃I�u�W�F�N�g�̃R�[�h

			Object* target_;
			Object* another_target_;
		};
	}
}
