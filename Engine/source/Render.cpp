#include "Render.h"

/* Include glew (helps in loading openGL and gives us access to higher versions) */
#define GLEW_STATIC
#include <GL/glew.h>

/* Include GLFW (window context creation) */
#include <GLFW/glfw3.h>
#include <stdlib.h>

#include <iostream>

void static APIENTRY opengl_debug_callback(
	GLenum source, GLenum type, GLuint id, GLenum severity,
	GLsizei length, const GLchar* message, const void* userParm) {

	std::cout << "I was called " << message << std::endl;

}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	// Hit escape key to exit window
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

namespace Beserk {

	bool Render::Init() {

		window_parms wind_data;
		wind_data.height = 540;
		wind_data.width = 960;
		//wind_data.title = new char[32];
		wind_data.title = "All the things";
		const char* tempor = wind_data.title;

		// Setup GLFW
		if (GLFW_TRUE != glfwInit()) {

			return EXIT_FAILURE;
		}

		// OpenGL Version
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);

		// Only the new stuff
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		// Other Hints
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
		//glfwWindowHint(GLFW_DECORATED, GL_FALSE);

		/*GLFWwindow* window;*/
		window = glfwCreateWindow(wind_data.width, wind_data.height,  tempor, NULL, NULL);
		//delete[] wind_data.title;

		// If failed to create window
		if (!window) {
			glfwTerminate();
			return EXIT_FAILURE;
		}

		// Set callbacks
		glfwSetKeyCallback(window, key_callback);

		glfwMakeContextCurrent(window);
		glewExperimental = true;

		// Initiate GLEW
		if (GLEW_OK != glewInit()) {
			return EXIT_FAILURE;
		}

		// Debug
		glEnable(GL_DEBUG_OUTPUT);
		glDebugMessageCallback(opengl_debug_callback, nullptr);

		return true;
	}

	void Render::Destory() {
		glfwTerminate();
	}

	// Just proof this is working
	bool Render::TestRenderer() {

		// Clear
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Swap back and front buffers
		glfwSwapBuffers(window);

		return true;
	}
}