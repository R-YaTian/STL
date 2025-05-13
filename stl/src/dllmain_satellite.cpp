// Copyright (c) Microsoft Corporation.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include <Windows.h>

#include <initguid.h>

DEFINE_GUID(NO_SUBGROUP_GUID, 0xfea3413e, 0x7e05, 0x4911, 0x9a, 0x71, 0x70, 0x03, 0x31, 0xf1, 0xc2, 0x94);
DEFINE_GUID(GUID_NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

// DllMain for 'satellite' DLLs which don't need TLS.

extern "C" BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID) noexcept {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        if (!DisableThreadLibraryCalls(hModule)) {
            return FALSE;
        }
    }

    return TRUE;
}
