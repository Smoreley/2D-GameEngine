// Core Entry Point
#include "CEngine.h"
#include "CRender.h"
#include <iostream>

//using namespace Beserk;

#define SAFE_DELETE(p) {if (p) { delete(p) : (p)=NULL; }}

Beserk::CEngine *gp_engine;
Beserk::CRender *gp_RenderSystem;

#include <GLFW\glfw3.h>

int main(int argc, char* args[]) {
	gp_engine = new Beserk::CEngine();

	bool quit = false;

	gp_RenderSystem = new Beserk::CRender();
	gp_RenderSystem->Init();

	while (!glfwWindowShouldClose(gp_RenderSystem->GetWindow())) {

		glfwPollEvents();


		gp_RenderSystem->TestRenderer();

	}

	gp_RenderSystem->Destory();


	return EXIT_SUCCESS;
}