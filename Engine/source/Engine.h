#pragma once

extern bool TestMe();

namespace Beserk {
	
	class Engine
	{
	public:
		/* Constructor/Destructor*/
		Engine();
		~Engine();

		bool Init(void);
		void Run(void);
		void Update();

		void Test();

	private:

	};
}

extern Beserk::Engine *g_pEngine;