#include "Fps.h"

#include "DxLib.h"

namespace app {
	namespace system {

		const int FPS = 60;					//�ݒ�t���[����
		const int STRING_COLOR = 0xffffff;	//�����̐F

		Fps::Fps()
			: start_time_(0)
			, frame_count_(0)
			, fps_(0)
		{
		}


		Fps::~Fps()
		{
		}

		void Fps::Update() {
			if (frame_count_ == 0) {
				start_time_ = GetNowCount();
			}
			if (frame_count_ == FPS) {	//FPS�Őݒ肵���l�Ȃ畽�ς��v�Z
				int time = GetNowCount();
				fps_ = 1000.0f / (static_cast<float>(time - start_time_) / FPS);
				frame_count_ = 0;
				start_time_ = time;
			}
			frame_count_++;
		}

		void Fps::DrawFPS() const {
			DrawFormatString(0, 0, STRING_COLOR, "%.1f", fps_);
		}

		void Fps::Wait() const {
			int elapsed_time = GetNowCount() - start_time_;	//�o�ߎ���
			int waitTime = frame_count_ * 1000 / FPS - elapsed_time;	//�ҋ@����

			if (waitTime > 0) {
				Sleep(waitTime);
			}
		}
	}
}