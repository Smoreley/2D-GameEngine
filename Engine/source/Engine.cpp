#include "BeserkStd.h"
#include "Renderer.h"
#include "Engine.h"

namespace Beserk {

	Engine::Engine() {

	}

	Engine::~Engine() {

		/* Clean-Up */

		m_pRenderSystem->Destory();
		delete m_pRenderSystem;

	}

	bool Engine::Init() {

		m_pRenderSystem = new Beserk::Renderer();
		m_pRenderSystem->Init();

		return EXIT_SUCCESS;
	}

	void Engine::Test() {
		TestMe();

	}
}