// Copyright (c) Microsoft Corporation.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include <internal_shared.h>

#include <Windows.h>

#include <initguid.h>

DEFINE_GUID(NO_SUBGROUP_GUID, 0xfea3413e, 0x7e05, 0x4911, 0x9a, 0x71, 0x70, 0x03, 0x31, 0xf1, 0xc2, 0x94);
DEFINE_GUID(GUID_NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

extern "C" BOOL APIENTRY DllMain(HMODULE, DWORD, LPVOID) noexcept {
    return TRUE;
}
