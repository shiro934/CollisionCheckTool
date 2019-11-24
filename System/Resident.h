#pragma once

#include "Fps.h"
#include "Input\\InputKey.h"
#include "SceneManager.h"

namespace app {
	namespace system {

		class Resident
		{
		public:
			Resident();
			~Resident();

			SceneManager* scene_manager_;
			InputKey* input_key_;
			Fps* fps_calc_;
		};
	}
}