#pragma once
#include "Options.h"	// Initialization

// Forward Declarations
class Renderer;

// Not yet created forward declars
//class IGameView;

extern bool TestMe();

namespace Beserk {
	
	class Engine
	{
	public:
		/* Constructor/Destructor */
		Engine();
		~Engine();

		bool Init(void);			// Initialize Engine
		bool Shutdown(void);		// Shutdown Engine
		void Run(void);				// Main-Game loop

		// ideas for update look
		//void UpdateLogic();
		//void UpdateViews();

		void Test();

		Renderer& GetRenderer(void) { return *m_pRenderSystem; }

		//struct GameOptions m_Options;

	protected:

		bool m_bIsRunning;		// True if everything is initialized and we are now running in the main loop.
		bool m_bQuitting;		// True if the app is running the exit sequence.

		
		//typedef list<IGameView> GameViewList;
		//GameViewList m_gameViews;					// Views that are attached to our game

	private:

		// Render System
		Renderer* m_pRenderSystem;

	};
}	// End-of Namespace

extern Beserk::Engine *g_pEngine;