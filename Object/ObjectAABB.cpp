
#include "ObjectAABB.h"
#include "DxLib.h"

#include "../ImGui/imgui.h"
#include "../ImGui/imgui_impl_dxlib.h"

namespace app {
	ObjectAABB::ObjectAABB(VECTOR left_top, VECTOR right_under, const COLOR_U8 color, const char* unique_name)
		: unique_name_(unique_name)
	{
		left_top_ = left_top;
		right_under_ = right_under;

		SetColor(color);

		// 頂点の設定
		SetVertex();

		//頂点インデックスの初期化
		vertex_index_[0] = 0;
		vertex_index_[1] = 1;
		vertex_index_[2] = 2;

		vertex_index_[3] = 1;
		vertex_index_[4] = 3;
		vertex_index_[5] = 2;

		vertex_index_[6] = 0;
		vertex_index_[7] = 6;
		vertex_index_[8] = 4;

		vertex_index_[9] = 0;
		vertex_index_[10] = 2;
		vertex_index_[11] = 6;

		vertex_index_[12] = 2;
		vertex_index_[13] = 7;
		vertex_index_[14] = 6;

		vertex_index_[15] = 2;
		vertex_index_[16] = 3;
		vertex_index_[17] = 7;

		vertex_index_[18] = 1;
		vertex_index_[19] = 5;
		vertex_index_[20] = 7;

		vertex_index_[21] = 1;
		vertex_index_[22] = 7;
		vertex_index_[23] = 3;

		vertex_index_[24] = 0;
		vertex_index_[25] = 4;
		vertex_index_[26] = 5;

		vertex_index_[27] = 0;
		vertex_index_[28] = 5;
		vertex_index_[29] = 1;

		vertex_index_[30] = 6;
		vertex_index_[31] = 4;
		vertex_index_[32] = 5;

		vertex_index_[33] = 5;
		vertex_index_[34] = 7;
		vertex_index_[35] = 6;
	}

	ObjectAABB::~ObjectAABB() {

	}
	void ObjectAABB::Update()
	{
		float left_top[3] = { left_top_.x, left_top_.y, left_top_.z };
		float right_under[3] = { right_under_.x, right_under_.y, right_under_.z };
		float center[3] = { center_.x, center_.y, center_.z };

		ImGui::Begin(unique_name_);
		if (ImGui::SliderFloat3("left_top", left_top, -1000.0f, 1000.0f)) {
			left_top_.x = left_top[0];
			left_top_.y = left_top[1];
			left_top_.z = left_top[2];
		}
		if (ImGui::SliderFloat3("right_under", right_under, -1000.0f, 1000.0f)) {
			right_under_.x = right_under[0];
			right_under_.y = right_under[1];
			right_under_.z = right_under[2];
		}
		if (ImGui::SliderFloat3("center", center, -1000.0f, 1000.0f)) {
			left_top_.x += center[0] - center_.x;
			left_top_.y += center[1] - center_.y;
			left_top_.z += center[2] - center_.z;

			right_under_.x += center[0] - center_.x;
			right_under_.y += center[1] - center_.y;
			right_under_.z += center[2] - center_.z;
		}

		SetVertex();

		ImGui::End();
	}

	void ObjectAABB::Render() const
	{
		DrawPolygonIndexed3D(vertex_, 8, vertex_index_, 12, DX_NONE_GRAPH, FALSE);
	}

	void ObjectAABB::SetVertex()
	{
		vertex_[0].pos = left_top_;
		vertex_[0].norm = VGet(0.0f, 0.0f, -1.0f);
		vertex_[0].dif = color_;

		vertex_[1].pos = VGet(right_under_.x, left_top_.y, left_top_.z);
		vertex_[1].norm = VGet(0.0f, 0.0f, -1.0f);
		vertex_[1].dif = color_;

		vertex_[2].pos = VGet(left_top_.x, left_top_.y, right_under_.z);
		vertex_[2].norm = VGet(0.0f, 0.0f, -1.0f);
		vertex_[2].dif = color_;

		vertex_[3].pos = VGet(right_under_.x, left_top_.y, right_under_.z);
		vertex_[3].norm = VGet(0.0f, 0.0f, -1.0f);
		vertex_[3].dif = color_;

		vertex_[4].pos = VGet(left_top_.x, right_under_.y, left_top_.z);
		vertex_[4].norm = VGet(0.0f, 0.0f, -1.0f);
		vertex_[4].dif = color_;

		vertex_[5].pos = VGet(right_under_.x, right_under_.y, left_top_.z);
		vertex_[5].norm = VGet(0.0f, 0.0f, -1.0f);
		vertex_[5].dif = color_;

		vertex_[6].pos = VGet(left_top_.x, right_under_.y, right_under_.z);
		vertex_[6].norm = VGet(0.0f, 0.0f, -1.0f);
		vertex_[6].dif = color_;

		vertex_[7].pos = right_under_;
		vertex_[7].norm = VGet(0.0f, 0.0f, -1.0f);
		vertex_[7].dif = color_;

		VECTOR center;
		center.x = (right_under_.x + left_top_.x) / 2.0f;
		center.y = (left_top_.y + right_under_.y) / 2.0f;
		center.z = (right_under_.z + left_top_.z) / 2.0f;

		SetCenter(center);
	}
}