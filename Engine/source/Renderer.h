#pragma once

struct GLFWwindow;

namespace Beserk {

	struct window_parms {
		int height;
		int width;
		char *title;
	};

	// Render Class

	class Renderer
	{
	public:
		//CRender();
		//~CRender();

		bool TestRenderer();

		bool Init(void);
		void Destory(void);

		GLFWwindow* GetWindow() { return window; }

	private:
		GLFWwindow* window;

	};
}	// End-of Namespace