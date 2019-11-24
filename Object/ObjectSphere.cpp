
#include "ObjectSphere.h"
#include "DxLib.h"

#include "../ImGui/imgui.h"
#include "../ImGui/imgui_impl_dxlib.h"

namespace app {
	ObjectSphere::ObjectSphere(VECTOR center, float radius, const COLOR_U8 color, const char* unique_name)
		: unique_name_(unique_name)
		, radius_(radius)
	{
		SetCenter(center);
		SetColor(color);
	}

	ObjectSphere::~ObjectSphere() {

	}
	void ObjectSphere::Update()
	{
		float center[3] = { center_.x, center_.y, center_.z };

		ImGui::Begin(unique_name_);
		//’†S‚Ì‘€ì
		if (ImGui::SliderFloat3("center", center, -1000.0f, 1000.0f)) {
			SetCenter(VGet(center[0], center[1], center[2]));
		}
		// ”¼Œa‚Ì‘€ì
		ImGui::SliderFloat("radius", &radius_, 0.1f, 500.0f);

		ImGui::End();
	}

	void ObjectSphere::Render() const
	{
		DrawSphere3D(center_, radius_, 8, GetColor(color_.r, color_.g, color_.b)
			, GetColor(color_.r, color_.g, color_.b), TRUE);
	}
}