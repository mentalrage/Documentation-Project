// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MG
// Source by-file doc: by-file/PasswordGuard.md
// UID:0002VG | by-memory/0x004657d0-0x00465827.SetProtectedPasswordToken.md | Completion:93 | Confidence:95
#ifndef NEXUSTK_AUTH_PASSWORD_GUARD_H
#define NEXUSTK_AUTH_PASSWORD_GUARD_H

#include <stddef.h>

void SetProtectedPasswordToken(const wchar_t *password);
wchar_t *GetProtectedPasswordToken(
    wchar_t *destination,
    size_t destinationChars);
void ValidateChatInputOrThrowPasswordError(const wchar_t *text);

#endif
