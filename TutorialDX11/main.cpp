#include <Windows.h>
#include "Window.h"
#include "Renderer.h"
#include "Triangle.h"

int WinMain(HINSTANCE appInstance, HINSTANCE previnstance, LPSTR cmdLine, int cmdCount) {
	
	Window window(800, 600);
	Renderer renderer(window);
	Triangle triangle(renderer);
	
	MSG msg = { 0 };
	while (true) {
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT) break;
		}

		// ... Main loop ...
		// Update
		// Draw
		renderer.beginFrame();
		// Render all you stuff!
		triangle.draw(renderer);
		renderer.endFrame();
	}

	return 0;
}