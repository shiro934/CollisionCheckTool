/**
*	Main.cpp
*	メインクラス
*/

#include "ImGui\imgui.h"
#include "ImGui\imgui_impl_dxlib.h"

#include "DxLib.h"

#include "Constants\WindowInfo.h"
#include "System\Resident.h"

LRESULT CALLBACK WndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow) {
	//! ウインドウモードで起動
	ChangeWindowMode(TRUE);

	SetGraphMode(app::system::WND_SIZE_X, app::system::WND_SIZE_Y, 32);

	//! ウインドウタイトル
	SetMainWindowText("CollisionCheckTool");

	//! DXライブラリの初期化
	if (DxLib_Init() == -1) {
		return -1;	//エラー終了
	}

	SetDrawScreen(DX_SCREEN_BACK);

	// Zバッファを有効にする
	SetUseZBuffer3D(TRUE);

	// Zバッファへの書き込みを有効にする
	SetWriteZBuffer3D(TRUE);

	// メッセージをフックするウインドウプロージャを登録する
	//注意：DxLib_Initを呼んだ後でないと　登録されない。
	SetHookWinProc(WndProc);
	//ＩＭＥを使用する
	SetUseIMEFlag(TRUE);

	// Setup ImGui binding
	ImGui_ImplDxLib_Init();

	//日本語フォント設定
	ImGuiIO& io = ImGui::GetIO();
	io.Fonts->AddFontFromFileTTF("ImGui\\mplus-1p-regular.ttf", 20.0f, NULL,
		io.Fonts->GetGlyphRangesJapanese());

	bool show_test_window = true;
	bool show_another_window = false;
	ImVec4 clear_col = ImColor(114, 144, 154);
	SetBackgroundColor((int)(clear_col.x * 255.0f),
		(int)(clear_col.y * 255.0f),
		(int)(clear_col.z * 255.0f));

	app::system::Resident* resident = new app::system::Resident();

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		//! ウインドウメッセージを処理
		if (ProcessMessage() != 0) {
			break;
		}

		//! 入力状態をセット
		resident->input_key_->SetKey();

		//! 画面の絵を削除
		ClearDrawScreen();

		ImGui_ImplDxLib_NewFrame();

		//シーン処理
		resident->scene_manager_->ChangeScene();
		resident->scene_manager_->Input(resident->input_key_);
		resident->scene_manager_->Update();
		resident->scene_manager_->Render();

		//! fps処理
		resident->fps_calc_->Update();
		resident->fps_calc_->DrawFPS();
		resident->fps_calc_->Wait();

		ImGui::Render();

		// 裏画面の内容を表画面に反映
		ScreenFlip();
	}

	if (resident) {
		delete resident;
		resident = nullptr;
	}

	ImGui_ImplDxLib_Shutdown();

	//! DXライブラリ使用の終了処理
	DxLib_End();

	return 0;	//終了
}

LRESULT CALLBACK WndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplDxLib_WndProcHandler(wnd, msg, wParam, lParam)) {
		SetUseHookWinProcReturnValue(TRUE);
		return 1;
	}

	//IME関連はOSに任せる
	switch (msg)
	{
		//WM_IME_SETCONTEXTを受け取ったときに
		//lParam = 0;とするとIME関連の表示が行われなくなります。
	case WM_IME_SETCONTEXT:
	case WM_IME_STARTCOMPOSITION:
	case WM_IME_ENDCOMPOSITION:
	case WM_IME_COMPOSITION:
	case WM_IME_NOTIFY:
	case WM_IME_REQUEST:
		SetUseHookWinProcReturnValue(TRUE);
		return DefWindowProc(wnd, msg, wParam, lParam);

	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU) { // Disable ALT application menu
			SetUseHookWinProcReturnValue(TRUE);
			return 0;
		}
		break;
	}

	return 0;
}