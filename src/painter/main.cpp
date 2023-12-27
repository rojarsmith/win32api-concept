#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include "main_window.hpp"
#include "resource.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    MainWindow win;

    if (!win.Create(L"Painter", WS_OVERLAPPEDWINDOW))
    {
        return 0;
    }

    HACCEL hAccel = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDR_ACCEL1));

    ShowWindow(win.Window(), nCmdShow);

    // Run the message loop.

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        /*
          The main function of the TranslateAccelerator function is to compare messages
           with the defined keys in the accelerator table.
          If it identifies a shortcut key, it converts the corresponding key message
           into a WM_COMMAND or WM_SYSCOMMAND message and sends it to the window's message handling function.
         */
        if (!TranslateAccelerator(win.Window(), hAccel, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return 0;
}
