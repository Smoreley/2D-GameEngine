#pragma once

// Forward Declarations
class Renderer;

extern bool TestMe();

namespace Beserk {
	
	class Engine
	{
	public:
		/* Constructor/Destructor */
		Engine();
		~Engine();

		bool Init(void);
		void Run(void);
		void Update();


		void Test();

		Renderer& GetRenderer(void) { return *m_pRenderSystem; }

	private:

		// Render System
		Renderer* m_pRenderSystem;

	};
}

extern Beserk::Engine *g_pEngine;