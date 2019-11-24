#pragma once

#include "DxLib.h"

namespace app {

	/**
	*	当たり判定用のオブジェクトの基底クラス
	*/
	class Object
	{
	public:
		Object() {};
		~Object() {};

		virtual void Update() = 0;

		//! オブジェクトの描画
		virtual void Render() const = 0;	

		void SetCenter(const VECTOR center) { center_ = center; }
		void SetColor(const COLOR_U8 color) { color_ = color; }

		////! 頂点を更新
		//virtual void UpdateVertex() = 0;	//頂点更新

								//オブジェクトの種類を取得
		virtual unsigned int GetObjectCode() const = 0;	//自身のタイプを返す(Crc値)

	protected:
		VECTOR center_;		//中心座標
		COLOR_U8 color_;	//色
	};
}