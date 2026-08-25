// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000ML
// Source by-file doc: by-file/PlatformApi.md
// UID:0002AS | by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md | Completion:90 | Confidence:90
#pragma once

#include <stdio.h>
#include <sys/stat.h>
#include <windows.h>

extern FILE *(__cdecl *g_pfnWideOpenFile)(const wchar_t *path, const wchar_t *mode);
extern int (__cdecl *g_pfnWideStat)(const wchar_t *path, struct _stat64i32 *buffer);
extern wchar_t (__cdecl *g_pfnReadUtf16CodeUnitFromFile)(FILE *stream);
extern HANDLE (WINAPI *g_pfnCreateFileW)(
    LPCWSTR fileName,
    DWORD desiredAccess,
    DWORD shareMode,
    LPSECURITY_ATTRIBUTES securityAttributes,
    DWORD creationDisposition,
    DWORD flagsAndAttributes,
    HANDLE templateFile);
extern DWORD (WINAPI *g_pfnGetCurrentDirectoryW)(DWORD bufferLength, LPWSTR buffer);
extern DWORD (WINAPI *g_pfnCharUpperBuffW)(LPWSTR text, DWORD length);
extern BOOL (WINAPI *g_pfnCreateDirectoryW)(
    LPCWSTR pathName, LPSECURITY_ATTRIBUTES securityAttributes);
extern BOOL (WINAPI *g_pfnDeleteFileW)(LPCWSTR fileName);
extern BOOL (WINAPI *g_pfnSetFileAttributesW)(
    LPCWSTR fileName, DWORD fileAttributes);
