// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MG
// Source by-file doc: by-file/PasswordGuard.md
// UID:000290 | by-memory/0x0067a940-0x0067a980.PasswordGuardProtectedToken.md | Completion:92 | Confidence:95
#include "PasswordGuard.h"
#include "../archive/DATFile.h"
#include "../util/Error.h"
#include <string.h>
#include <wchar.h>
#include <windows.h>

static wchar_t g_protectedPasswordToken[32];

// UID:00035L | by-memory/0x0066d410-0x0066d412.PasswordGuardXorSeed.md | Completion:92 | Confidence:95
static unsigned short g_passwordProtectSeed = 0xd544;

// UID:0002VG | by-memory/0x004657d0-0x00465827.SetProtectedPasswordToken.md | Completion:93 | Confidence:95
void SetProtectedPasswordToken(const wchar_t *password)
{
    wcsncpy_s(g_protectedPasswordToken, 32, password, 32);
    g_protectedPasswordToken[31] = L'\0';

    unsigned int seed = g_passwordProtectSeed;
    for (wchar_t *scan = g_protectedPasswordToken;
         *scan != L'\0';
         ++scan, ++seed)
    {
        *scan = static_cast<wchar_t>(*scan ^ seed);
    }
}

// UID:00055E | by-memory/0x00465830-0x0046588c.GetProtectedPasswordTokenRaw.md | Completion:93 | Confidence:95
wchar_t *GetProtectedPasswordToken(
    wchar_t *destination,
    size_t destinationChars)
{
    if (destinationChars == 0)
    {
        destination[0] = L'\0';
        return destination;
    }

    wcsncpy_s(
        destination,
        destinationChars,
        g_protectedPasswordToken,
        destinationChars);
    destination[destinationChars - 1] = L'\0';

    unsigned int seed = g_passwordProtectSeed;
    for (wchar_t *scan = destination;
         *scan != L'\0';
         ++scan, ++seed)
    {
        *scan = static_cast<wchar_t>(*scan ^ seed);
    }

    return destination;
}

// UID:0002VH | by-memory/0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md | Completion:94 | Confidence:95
void ValidateChatInputOrThrowPasswordError(const wchar_t *text)
{
    wchar_t decodedPassword[32];
    GetProtectedPasswordToken(decodedPassword, 32);

    if (text != NULL)
    {
        if (wcsstr(text, decodedPassword) != NULL)
        {
            DATFile passwordMessageFile;
            passwordMessageFile.Open(L"PASS_ENG.STR");

            wchar_t message[1024];
            memset(message, 0, sizeof(message));

            char line[200];
            wchar_t wideLine[200];
            for (;;)
            {
                int lineLength =
                    passwordMessageFile.ReadLineChars(line, 200);
                line[lineLength] = '\0';

                int wideChars = MultiByteToWideChar(
                    CP_ACP, 0, line, -1, wideLine, 199);
                wideLine[wideChars] = L'\0';

                if (lineLength <= 1)
                    break;

                wcsncat_s(message, 1024, wideLine, 200);
            }

            message[1023] = L'\0';
            throw new PasswordError(message);
        }

        memset(decodedPassword, 0, sizeof(decodedPassword));
    }
}

// UID:00055F | by-memory/0x00612e8c-0x00612ea6.PasswordGuardPassEngString.md | Completion:92 | Confidence:95
// The exact PASS_ENG.STR data is source-covered by the literal in
// ValidateChatInputOrThrowPasswordError; no standalone table is emitted.
