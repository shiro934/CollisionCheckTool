#pragma once

#include "../Object/Object.h"
#include "../Object/ObjectAABB.h"
#include "../Object/ObjectSphere.h"

namespace app {
	namespace system {
		//オブジェクトのCRC値
		enum ObjectCode {
			OBJECT_AABB = 0xec54ac27,
			OBJECT_SPHERE = 0x447f0037,

			OBJECT_CODE
		};

		class CollisionCheck {
		public :
			static bool CheckAnyToAny(const Object* target, const Object* target2);

			static bool CheckAABBToAny(const ObjectAABB* target, const Object* target2);

			static bool CheckAABBToAABB(const ObjectAABB* target, const ObjectAABB* target2);
			static bool CheckAABBToSphere(const ObjectAABB* target, const ObjectSphere* target2);
			
		private  : 
			CollisionCheck() {};
			~CollisionCheck() {};
		};
	}
}