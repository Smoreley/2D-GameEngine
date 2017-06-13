/* Engine */
#include "BeserkStd.h"
#include "Renderer.h"
#include "Engine.h"

#include <GLFW\glfw3.h>

namespace Beserk {

	Engine::Engine() {

	}

	Engine::~Engine() {

		/* Clean-Up */

		m_pRenderSystem->Destory();
		delete m_pRenderSystem;

		cout << "I WAS CALLED" << endl;
	}

	bool Engine::Init() {

		m_pRenderSystem = new Beserk::Renderer();
		m_pRenderSystem->Init();

		return EXIT_SUCCESS;
	}

	bool Engine::Shutdown(void) {
		cout << "Shutting Down Engine" << endl;

		return EXIT_SUCCESS;
	}

	void Engine::Run(void) {

		while (!glfwWindowShouldClose(GetRenderer().GetWindow())) {
			glfwPollEvents();				// Poll for events

			GetRenderer().TestRenderer();	// Render
		}


	}

	// Testing function
	void Engine::Test() {
		TestMe();

	}

}	// End-of Namespace