#include "CollisionCheck.h"

namespace app {
	namespace system {
		bool CollisionCheck::CheckAnyToAny(const Object * target, const Object * target2)
		{
			bool is_collision = false;
			switch (target->GetObjectCode()) {
			case OBJECT_AABB: //AABB
				is_collision = CheckAABBToAny(reinterpret_cast<const ObjectAABB*>(target), target2);
				break;
			}

			return is_collision;
		}
		bool CollisionCheck::CheckAABBToAny(const ObjectAABB * target, const Object * target2)
		{
			bool is_collision = false;
			switch (target2->GetObjectCode()) {
			case OBJECT_AABB: //AABB
				is_collision = CheckAABBToAABB(target, reinterpret_cast<const ObjectAABB*>(target2));
				break;
			case OBJECT_SPHERE : //Sphere
				is_collision = CheckAABBToSphere(target, reinterpret_cast<const ObjectSphere*>(target2));
				break;
			}

			return is_collision;
		}

		bool CollisionCheck::CheckAABBToAABB(const ObjectAABB* target, const ObjectAABB* target2) {
			VECTOR target_left_top_ = target->GetLeftTop();
			VECTOR target_right_under_ = target->GetRightUnder();
			VECTOR target2_left_top_ = target2->GetLeftTop();
			VECTOR target2_right_under_ = target2->GetRightUnder();

			// 左上ー右下が範囲外か
			if (target_left_top_.x > target2_right_under_.x) {
				return false;
			}
			if (target_left_top_.y < target2_right_under_.y) {
				return false;
			}
			if (target_left_top_.z > target2_right_under_.z) {
				return false;
			}

			if (target_right_under_.x < target2_left_top_.x) {
				return false;
			}
			if (target_right_under_.y > target2_left_top_.y) {
				return false;
			}
			if (target_right_under_.z < target2_left_top_.z) {
				return false;
			}

			return true;
		}

		bool CollisionCheck::CheckAABBToSphere(const ObjectAABB * target, const ObjectSphere * target2)
		{
			VECTOR left_top = target->GetLeftTop();
			VECTOR right_under = target->GetRightUnder();

			VECTOR sphere_center = target2->GetCenter();

			float length = 0;	//球の中心とAABBの距離
			// x座標の距離
			if (left_top.x > sphere_center.x) {
				length += (left_top.x - sphere_center.x) * (left_top.x - sphere_center.x);
			}
			else if(right_under.x < sphere_center.x){
				length += (right_under.x - sphere_center.x) * (right_under.x - sphere_center.x);
			}

			//y座標の距離
			if (left_top.y < sphere_center.y) {
				length += (left_top.y - sphere_center.y) * (left_top.y - sphere_center.y);
			}
			else if (right_under.y > sphere_center.y) {
				length += (right_under.y - sphere_center.y) * (right_under.y - sphere_center.y);
			}
			//z座標の距離
			if (left_top.z > sphere_center.z) {
				length += (left_top.z - sphere_center.z) * (left_top.z - sphere_center.z);
			}
			else if (right_under.z < sphere_center.z) {
				length += (right_under.z - sphere_center.z) * (right_under.z - sphere_center.z);
			}

			float r = target2->GetRadius();

			//　AABBと球の判定をとる
			if ((r * r) > length) {
				return true;
			}
			else {
				return false;
			}
		}


	}
}
