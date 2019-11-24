#pragma once

#include "DxLib.h"

namespace app {

	/**
	*	�����蔻��p�̃I�u�W�F�N�g�̊��N���X
	*/
	class Object
	{
	public:
		Object() {};
		~Object() {};

		virtual void Update() = 0;

		//! �I�u�W�F�N�g�̕`��
		virtual void Render() const = 0;	

		void SetCenter(const VECTOR center) { center_ = center; }
		void SetColor(const COLOR_U8 color) { color_ = color; }

		////! ���_���X�V
		//virtual void UpdateVertex() = 0;	//���_�X�V

								//�I�u�W�F�N�g�̎�ނ��擾
		virtual unsigned int GetObjectCode() const = 0;	//���g�̃^�C�v��Ԃ�(Crc�l)

	protected:
		VECTOR center_;		//���S���W
		COLOR_U8 color_;	//�F
	};
}