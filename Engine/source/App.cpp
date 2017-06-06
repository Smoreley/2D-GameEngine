// Core Entry Point
#include "Renderer.h"
#include "Engine.h"
#include <iostream>

//using namespace Beserk;

Beserk::Engine *g_pEngine;
//Beserk::Renderer *g_pRenderSystem;

#include <GLFW\glfw3.h>

int main(int argc, char* args[]) {
	g_pEngine = new Beserk::Engine();

	g_pEngine->Init();

	bool quit = false;

	//g_pRenderSystem = new Beserk::Renderer();
	//g_pRenderSystem->Init();

	g_pEngine->Test();

	/*while (!glfwWindowShouldClose(g_pRenderSystem->GetWindow())) {*/
	while (!glfwWindowShouldClose(g_pEngine->GetRenderer().GetWindow())) {

		glfwPollEvents();					// Poll for events

		//g_pRenderSystem->TestRenderer();	// Render test
		g_pEngine->GetRenderer().TestRenderer();

	}

	//g_pRenderSystem->Destory();

	return EXIT_SUCCESS;
}