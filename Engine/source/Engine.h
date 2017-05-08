#pragma once

extern bool TestMe();

namespace Beserk {
	
	class Engine
	{
	public:
		Engine();
		~Engine();

		void Test();

	private:

	};
}

extern Beserk::Engine *g_pEngine;