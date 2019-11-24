#pragma once

#include "Object.h"

namespace app {

	/**
	*	�����蔻��p�̃I�u�W�F�N�g�̊��N���X
	*/
	class ObjectAABB : public Object
	{
	public:
		ObjectAABB(VECTOR left_top, VECTOR right_under, COLOR_U8 color, const char* unique_name);
		~ObjectAABB();


		void Update() override;

		void Render() const override;
		unsigned int GetObjectCode() const override { return 0xec54ac27; }	//���g�̃^�C�v��Ԃ�(Crc�l)

		VECTOR GetLeftTop()const { return left_top_; }
		VECTOR GetRightUnder()const { return right_under_; }

//		void UpdateVertex() override;
	private :
		void SetVertex();	//���_���W��ݒ�

		VECTOR left_top_;	//����̍��W
		VECTOR right_under_;	//�E���̍��W

		VERTEX3D vertex_[8];	//AABB�̍��W
		unsigned short vertex_index_[36];	//���_�C���f�b�N�X

		const char* unique_name_;
//		bool is_vertex_change_;	//���_���ω�����
	};
}