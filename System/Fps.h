#pragma once

namespace app {
	namespace system {
		class Fps
		{
		public:
			Fps();
			~Fps();

			void Update();
			void DrawFPS() const;
			void Wait() const;

			int GetFrameCount() const { return frame_count_; }	//何フレーム目かを返す
		private:
			unsigned int start_time_;		//測定開始時刻
			int frame_count_;
			float fps_;			//計算したフレーム数
		};
	}
}