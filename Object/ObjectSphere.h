#pragma once

#include "Object.h"

namespace app {

	/**
	*	�����蔻��p�̃I�u�W�F�N�g�̊��N���X
	*/
	class ObjectSphere : public Object
	{
	public:
		ObjectSphere(VECTOR center, float radius, COLOR_U8 color, const char* unique_name);
		~ObjectSphere();


		void Update() override;

		void Render() const override;
		unsigned int GetObjectCode() const override { return 0x447f0037; }	//���g�̃^�C�v��Ԃ�(Crc�l)

		VECTOR GetCenter() const { return center_; }
		float GetRadius() const { return radius_; }
	private:
		void SetVertex();	//���_���W��ݒ�

		float radius_;
		const char* unique_name_;
	};
}
