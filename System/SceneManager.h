#pragma once

namespace app {
	namespace system {
		class Scene;
		class InputKey;

		class SceneManager
		{
		public:
			SceneManager();
			~SceneManager();

			void Input(const InputKey* key) const;
			void Update() const;
			void Render() const;

			void ChangeScene();	//ƒV[ƒ“Ø‚è‘Ö‚¦
		private:
			Scene* current_scene_;
		};
	}
}
