// Core Entry Point
#include "Engine.h"
#include "Renderer.h"
#include <iostream>

//using namespace Beserk;

#define SAFE_DELETE(p) {if (p) { delete(p) : (p)=NULL; }}

Beserk::Engine *g_pEngine;
Beserk::Renderer *g_pRenderSystem;

#include <GLFW\glfw3.h>

int main(int argc, char* args[]) {
	g_pEngine = new Beserk::Engine();

	bool quit = false;

	g_pRenderSystem = new Beserk::Renderer();
	g_pRenderSystem->Init();


	g_pEngine->Test();


	while (!glfwWindowShouldClose(g_pRenderSystem->GetWindow())) {

		glfwPollEvents();


		g_pRenderSystem->TestRenderer();

	}

	g_pRenderSystem->Destory();


	return EXIT_SUCCESS;
}