#pragma once

#include "Object.h"

namespace app {

	/**
	*	当たり判定用のオブジェクトの基底クラス
	*/
	class ObjectAABB : public Object
	{
	public:
		ObjectAABB(VECTOR left_top, VECTOR right_under, COLOR_U8 color, const char* unique_name);
		~ObjectAABB();


		void Update() override;

		void Render() const override;
		unsigned int GetObjectCode() const override { return 0xec54ac27; }	//自身のタイプを返す(Crc値)

		VECTOR GetLeftTop()const { return left_top_; }
		VECTOR GetRightUnder()const { return right_under_; }

//		void UpdateVertex() override;
	private :
		void SetVertex();	//頂点座標を設定

		VECTOR left_top_;	//左上の座標
		VECTOR right_under_;	//右下の座標

		VERTEX3D vertex_[8];	//AABBの座標
		unsigned short vertex_index_[36];	//頂点インデックス

		const char* unique_name_;
//		bool is_vertex_change_;	//頂点が変化した
	};
}