#pragma once
#include "BeserkStd.h"

namespace Beserk {

	class Intersection {
		float m_fDist;
		float m_dwFace;
		float m_fBarycentric1, m_fBarycentric2;
		float m_tU, m_tV;

		ActorId m_actorId;
		vec3 m_worldLocation;
		vec3 m_actorLocation;
		vec3 m_normal;
	};

	typedef vector<Intersection> IntersectionArray;

	class Raycast {
	public:
		Raycast(vec2 point, int maxIntersections = 16);

		unsigned int m_maxIntersections;
		unsigned int m_countIntersections;
		bool m_allHits;
		vec2 point;

		vec3 m_rayDirection;
		vec3 m_rayOrigin;

		IntersectionArray m_intersections;

		void Sort();		// Sort the intersections

	protected:

	};

}	// End-of Namespace