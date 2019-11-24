#include "Fps.h"

#include "DxLib.h"

namespace app {
	namespace system {

		const int FPS = 60;					//設定フレーム数
		const int STRING_COLOR = 0xffffff;	//文字の色

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
			if (frame_count_ == FPS) {	//FPSで設定した値なら平均を計算
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
			int elapsed_time = GetNowCount() - start_time_;	//経過時間
			int waitTime = frame_count_ * 1000 / FPS - elapsed_time;	//待機時間

			if (waitTime > 0) {
				Sleep(waitTime);
			}
		}
	}
}