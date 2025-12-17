// dllmain.cpp: точка входа DLL

#include "pch.h"

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        // DLL загружена
        break;
    case DLL_THREAD_ATTACH:
        // Создан новый поток
        break;
    case DLL_THREAD_DETACH:
        // Поток завершен
        break;
    case DLL_PROCESS_DETACH:
        // DLL выгружается
        break;
    }
    return TRUE;
}