#include <windows.h>

HHOOK hHook = NULL;

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        KBDLLHOOKSTRUCT *p = (KBDLLHOOKSTRUCT *)lParam;
        if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN) {
            if (p->vkCode == VK_INSERT) {
                keybd_event(VK_OEM_PLUS, 0, 0, 0);  // Simula tecla "+"
                return 1;
            }
        }
    }
    return CallNextHookEx(hHook, nCode, wParam, lParam);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, hModule, 0);
        break;
    case DLL_PROCESS_DETACH:
        if (hHook) UnhookWindowsHookEx(hHook);
        break;
    }
    return TRUE;
}