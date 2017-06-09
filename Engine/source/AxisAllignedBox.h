#pragma once
#include "BeserkStd.h"

namespace Beserk {

	//class AxisAlignedBox;
	class AxisAllignedBox {
	public:
		enum Extent {
			EXTENT_NULL,
			EXTENT_FINITE,
			EXTENT_INFINITE
		};

		typedef enum {
			FAR_LB = 0,	// Far_Left_Bottom
			FAR_LT = 1,
			FAR_RT = 2,
			FAR_RB = 3,

			NEAR_RB = 7,	// Near_Right_Bottom
			NEAR_LB = 6,
			NEAR_LT = 5,
			NEAR_RT = 4
		} CornerEnum;

		inline AxisAllignedBox() : m_min(vec3(0)), m_max(vec3(1)), m_corners(0) {
			// Default to a null box
			SetMinimum(vec3(-0.5));
			SetMaximum(vec3(0.5f));
			m_extent = EXTENT_NULL;
		}

		inline void SetMinimum(const vec3& vec) {
			m_extent = EXTENT_FINITE;
			m_min = vec;
		}

		inline void SetMaximum(const vec3& vec) {
			m_extent = EXTENT_FINITE;
			m_max = vec;
		}

	protected:
		vec3 m_min;
		vec3 m_max;
		Extent m_extent;
		mutable vec3* m_corners;

	};

}	// End-of Namespace