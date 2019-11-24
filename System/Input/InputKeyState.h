#pragma once
namespace app {
	namespace system {
		enum KeyState {
			KEY_DOWN,		//キーが押された瞬間
			KEY_DOWN_KEEP,	//キーを押し続けている状態
			KEY_UP,			//キーから離した瞬間
			KEY_UP_KEEP		//キーを押していない状態
		};
	}
}