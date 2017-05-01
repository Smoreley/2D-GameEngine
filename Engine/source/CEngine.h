#pragma once

extern bool TestMe();

namespace Beserk {

	
	class CEngine
	{
	public:
		CEngine();
		~CEngine();

		void Test();

	private:

	};
}

extern Beserk::CEngine *gp_engine;