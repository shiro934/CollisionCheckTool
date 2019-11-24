#include "Resident.h"

namespace app {
	namespace system {
		Resident::Resident()
		{
			input_key_ = new InputKey();
			fps_calc_ = new Fps();
			scene_manager_ = new SceneManager();
		}


		Resident::~Resident()
		{
			if (input_key_) {
				delete input_key_;
				input_key_ = nullptr;
			}
			if (fps_calc_) {
				delete fps_calc_;
				fps_calc_ = nullptr;
			}
			if (scene_manager_) {
				delete scene_manager_;
				scene_manager_ = nullptr;
			}
		}
	}
}