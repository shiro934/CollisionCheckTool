#pragma once

namespace app {
	namespace system {

		const int SET_KEY_NUM = 256;	//�ێ�����L�[�̑���

		enum KeyState;

		class InputKey
		{
		public:
			InputKey();
			~InputKey();

			void SetKey();
			KeyState CheckKeyState(const unsigned int key) const { return key_state_[key]; }
		private:
			char pre_key_[SET_KEY_NUM];		//�O�t���[���̃L�[���
			KeyState key_state_[SET_KEY_NUM]; //���̃t���[���̃L�[�̉������
		};
	}
}
