#pragma once

#include "Object.h"

namespace app {

	/**
	*	当たり判定用のオブジェクトの基底クラス
	*/
	class ObjectSphere : public Object
	{
	public:
		ObjectSphere(VECTOR center, float radius, COLOR_U8 color, const char* unique_name);
		~ObjectSphere();


		void Update() override;

		void Render() const override;
		unsigned int GetObjectCode() const override { return 0x447f0037; }	//自身のタイプを返す(Crc値)

		VECTOR GetCenter() const { return center_; }
		float GetRadius() const { return radius_; }
	private:
		void SetVertex();	//頂点座標を設定

		float radius_;
		const char* unique_name_;
	};
}
