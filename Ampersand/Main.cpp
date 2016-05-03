/* Credit to www.directxtutorial.com */
#include <d3d11.h>
//#include <d3dx11.h>
//#include <d3dx10.h>
#pragma comment (lib, "d3d11.lib")
//#pragma comment (lib, "d3dx11.lib")
//#pragma comment (lib, d3dx10.lib")

// define the screen resolution
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "Catch.hpp" //this defines <windows.h>
#if _WIN32
	#include <windows.h> //redundant  ^ but can we count on catch always being there? -TS
#endif

int z_main(int argc, char* const argv[])
{
	//global setup
	int result = Catch::Session().run(argc, argv);
	//global cleanup
	printf("Ampersand Program Begins...\n");
	return result;
}

#if _WIN32

static bool temp_fix_wm_destroy_flag;
IDXGISwapChain *swapchain;
ID3D11Device *dev;
ID3D11DeviceContext *devcon;
ID3D11RenderTargetView *backbuffer;

void RenderFrame(void);

void InitD3D(HWND hWnd)
{
	DXGI_SWAP_CHAIN_DESC scd;
	ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));
	scd.BufferCount = 1;
	scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	scd.BufferDesc.Width = SCREEN_WIDTH;
	scd.BufferDesc.Height = SCREEN_HEIGHT;
	scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	scd.OutputWindow = hWnd;
	scd.SampleDesc.Count = 4;
	scd.Windowed = TRUE;
	scd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

	D3D11CreateDeviceAndSwapChain(NULL,
		D3D_DRIVER_TYPE_HARDWARE,
		NULL,
		D3D11_CREATE_DEVICE_DEBUG,
		NULL,
		NULL,
		D3D11_SDK_VERSION,
		&scd,
		&swapchain,
		&dev,
		NULL,
		&devcon);

	// get the address of the back buffer
	ID3D11Texture2D *pBackBuffer;
	swapchain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);

	//uise the back buffer address to create the render target
	dev->CreateRenderTargetView(pBackBuffer, NULL, &backbuffer);
	pBackBuffer->Release();

	//set the render target as the back buffer
	devcon->OMSetRenderTargets(1, &backbuffer, NULL);

	//set the view[port
	D3D11_VIEWPORT viewport;
	ZeroMemory(&viewport, sizeof(D3D11_VIEWPORT));

	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;
	viewport.Width = SCREEN_WIDTH;
	viewport.Height = SCREEN_HEIGHT;

	devcon->RSSetViewports(1, &viewport);
}

void RenderFrame(void)
{
	float color[4]{0, 0.2f, 0.4f, 1.0f};
	// clear the back buffer to a deep blue
	devcon->ClearRenderTargetView(backbuffer, color);

	// do 3D rendering on the back buffer here

	// switch the back buffer and the front buffer
	swapchain->Present(0, 0);
}

void CleanupD3D()
{
	swapchain->SetFullscreenState(FALSE, NULL); //switch to windowed mode

	swapchain->Release();
	backbuffer->Release();
	dev->Release();
	devcon->Release();
}

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
	char *const temp_fake_args[1]{lpCmdLine};
	z_main(0, temp_fake_args);
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
	//wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = "WindowClass1";

	//register the window class
	RegisterClassEx(&wc);

	RECT wr = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, false);
	//create the window and use the results as the handle
	hWnd = CreateWindowEx(NULL,
		"WindowClass1", //name of the window class
		"Our First Windowed Program", //title of the window
		WS_OVERLAPPEDWINDOW, //window style
		300, // x-position of the window
		100, //y-position of the window
		wr.right - wr.left, // with of the window
		wr.bottom - wr.top, // height of the window
		NULL, // we have no parent window, NULL
		NULL, // we aren't using menus, NULL
		hInstance, // application handle
		NULL); // used with mltiple windows, NULL

	//display the window on screen
	ShowWindow(hWnd, nCmdShow);

	//initialize d3d11
	InitD3D(hWnd);

	//enter the main loop
	//this struct holds the windows event messages
	MSG msg = { 0 };

	//windows game loop
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			//translate keystrokes
			TranslateMessage(&msg);

			//send to windproc
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT)
				break; //exit loop

			RenderFrame();
		}
		else
		{
			//whatev dog
		}
	}

	//release d3d resources
	CleanupD3D();

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
			//PostQuitMessage is not exiting the program for unknown reasons, just flag to end loop for now -TS
			temp_fix_wm_destroy_flag = true;
			return 0;
		} break;
	}

	// Handle any messages the switch statement didn't
	return DefWindowProc(hWnd, message, wParam, lParam);
}
#endif