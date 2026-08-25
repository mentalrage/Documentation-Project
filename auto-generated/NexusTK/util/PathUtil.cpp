// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MI
// Source by-file doc: by-file/PathUtil.md
// UID:0001IZ | by-memory/0x00582460-0x00582495.PathExistsViaStat.md | Completion:95 | Confidence:95
#include "PathUtil.h"
#include "../platform/PlatformApi.h"

bool PathExistsViaStat(const wchar_t *path)
{
    struct _stat64i32 statBuffer;

    return g_pfnWideStat(path, &statBuffer) != -1;
}

// UID:00022K | by-memory/0x004b81f0-0x004b821e.FileExists.md | Completion:95 | Confidence:95
bool FileExists(const wchar_t *path)
{
    FILE *file = g_pfnWideOpenFile(path, L"rb");
    if (file == NULL)
        return false;

    fclose(file);
    return true;
}
