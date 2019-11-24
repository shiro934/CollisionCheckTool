#include "CollisionCheck.h"

namespace app {
	namespace system {
		bool CollisionCheck::CheckAnyToAny(const Object * target, const Object * target2)
		{
			bool is_collision = false;
			switch (target->GetObjectCode()) {
			case 1 : //AABB
				is_collision = CheckAABBToAny(reinterpret_cast<const ObjectAABB*>(target), target2);
				break;
			}

			return is_collision;
		}
		bool CollisionCheck::CheckAABBToAny(const ObjectAABB * target, const Object * target2)
		{
			bool is_collision = false;
			switch (target2->GetObjectCode()) {
			case 1: //AABB
				is_collision = CheckAABBToAABB(target, reinterpret_cast<const ObjectAABB*>(target2));
				break;
			}

			return is_collision;
		}

		bool CollisionCheck::CheckAABBToAABB(const ObjectAABB* target, const ObjectAABB* target2) {
			VECTOR target_left_top_ = target->GetLeftTop();
			VECTOR target_right_under_ = target->GetRightUnder();
			VECTOR target2_left_top_ = target2->GetLeftTop();
			VECTOR target2_right_under_ = target2->GetRightUnder();

			// ¶ã[‰E‰º‚ª”ÍˆÍŠO‚©
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


	}
}