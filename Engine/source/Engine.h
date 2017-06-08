#pragma once

// Forward Declarations
class Renderer;


// Not yet created forward declars
class IGameView;


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

	protected:

		
		//typedef list<IGameView> GameViewList;
		//GameViewList m_gameViews;					// Views that are attached to our game



	private:

		// Render System
		Renderer* m_pRenderSystem;

	};
}

extern Beserk::Engine *g_pEngine;