// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>

typedef int(__fastcall* Tload_buffer_csl)(int a1, __int64 a2, __int64 a3, int a4, __int64 a5);
Tload_buffer_csl load_buffer = (Tload_buffer_csl)((uintptr_t)GetModuleHandleA("citizen-scripting-lua.dll") + 0x34BE0);
Tload_buffer_csl org;

int l_state = NULL;

int loadbffr_detour(int a1, __int64 a2, __int64 a3, int a4, __int64 a5) {
    if(!l_state) {
        l_state = (int)a1;
    }
    return org(a1, a2, a3, a4, a5);
}