/* Credit to www.directxtutorial.com */

#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "Catch.hpp"
#if _WIN32
	#include <windows.h>
#endif

#if 0
#include "Catch.hpp" //this defines <windows.h>
int main(int argc, char* const argv[])
{
	//global setup
	int result = Catch::Session().run(argc, argv);
	//global cleanup
	printf("Ampersand Program Begins...\n");
	std::cin.get();
}
#endif

#if _WIN32

//The windows proc function, for processing messages
LRESULT CALLBACK WindowProc(HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam);

//The entry point for any windows program
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	INT nCmdShow)
{
	//handle for window
	HWND hWnd;
	//window information class
	WNDCLASSEX wc;

	//clear out the window information class for use
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	//fill in struct with the needed information
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = "WindowClass1";

	//register the window class
	RegisterClassEx(&wc);

	//create the window and use the results as the handle
	hWnd = CreateWindowEx(NULL,
		"WindowClass1", //name of the window class
		"Our First Windowed Program", //title of the window
		WS_OVERLAPPEDWINDOW, //window style
		300, // x-position of the window
		300, //y-position of the window
		500, // with of the window
		400, // height of the window
		NULL, // we have no parent window, NULL
		NULL, // we aren't using menus, NULL
		hInstance, // application handle
		NULL); // used with mltiple windows, NULL

	//display the window on screen
	ShowWindow(hWnd, nCmdShow);

	//enter the main loop
	//this struct holds the windows event messages
	MSG msg;

	// wait for the next message in the queue, store the results in 'msg'
	while (GetMessage(&msg, hWnd, 0, 0))
	{
		//translate keystroke messages into the right format
		TranslateMessage(&msg);

		// send the message to the WindowProc function
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

// this is the main message handler for the program
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//sort through an find what code to run for the message given
	switch(message)
	{
		// this message is read when the window is closed
		case WM_DESTROY:
		{
			// close the application entirely
			PostQuitMessage(0);
			return 0;
		} break;
	}

	// Handle any messages the switch statement didn't
	return DefWindowProc(hWnd, message, wParam, lParam);
}
#endif