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

			int GetFrameCount() const { return frame_count_; }	//���t���[���ڂ���Ԃ�
		private:
			unsigned int start_time_;		//����J�n����
			int frame_count_;
			float fps_;			//�v�Z�����t���[����
		};
	}
}