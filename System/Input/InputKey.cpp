#include "InputKey.h"

#include "InputKeyState.h"

#include "DxLib.h"

namespace app {
	namespace system {
		InputKey::InputKey()
		{
			GetHitKeyStateAll(pre_key_);
		}


		InputKey::~InputKey()
		{
		}

		void InputKey::SetKey() {
			char key[SET_KEY_NUM];
			GetHitKeyStateAll(key);

			for (int i = 0; i < SET_KEY_NUM; i++) {
				if (key[i] == 0) {	//�L�[��������Ă��Ȃ�
					if (pre_key_[i] == key[i]) {
						key_state_[i] = KEY_UP_KEEP;
						continue;
					}
					key_state_[i] = KEY_UP;
					continue;
				}

				//�L�[��������Ă���
				if (pre_key_[i] == key[i]) {
					key_state_[i] = KEY_DOWN_KEEP;
					continue;
				}
				key_state_[i] = KEY_DOWN;
			}

			//! ����̃L�[��Ԃ�ێ�
			for (int i = 0; i < SET_KEY_NUM; i++) {
				pre_key_[i] = key[i];
			}
		}

	}
}
