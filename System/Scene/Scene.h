#pragma once

namespace app {
	namespace system {

		enum SceneType;
		class InputKey;

		class Scene
		{


		public:
			Scene();
			~Scene();

			virtual void Input(const InputKey* key) = 0;
			virtual void Update() = 0;
			virtual void Render() const = 0;

			virtual SceneType NextSceneType() const = 0;	//���̃V�[���^�C�v��Ԃ�

			bool IsNextScene() const { return next_scene_flag_; }	//�V�[���J�ڂ����邩�Ԃ�
		protected:
			bool next_scene_flag_;	//���̃V�[���֑J�ڂ��邩
		};
	}
}