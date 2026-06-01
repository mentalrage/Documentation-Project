*** UID:0000MG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:60 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:75 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# PasswordGuard

## Status

- Confidence: medium for module boundary, strong for function behavior.
- Proposed module: `auth/PasswordGuard.cpp` or a chat/login input-filter source.
- Current Wave3 files: `SetProtectedPasswordToken_004657D0.cpp`, `ValidateChatInputOrThrowPasswordError_00465890.cpp`, and `class_PasswordError.cpp`
- Main address docs: [UID:0000YS][0x004657d0-0x00467406.PasswordGuardAndFatalError](by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md), [UID:000275][0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals](by-memory/0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals.md), and [UID:000290][0x0067a940-0x0067a980.PasswordGuardProtectedToken](by-memory/0x0067a940-0x0067a980.PasswordGuardProtectedToken.md)
- Evidence basis: `simroot_v2/recovered`, Wave3 global summaries, and IDA MCP lookup/xref checks on 2026-05-23.

## Responsibility

This module caches the active login password in an XOR-obfuscated wide-character buffer and prevents the user from sending chat/input text that contains that password. On a match, it loads `PASS_ENG.STR`, builds a localized wide error message, and throws `PasswordError`.

## Likely Contents

- `SetProtectedPasswordToken` at `0x004657d0`.
- `ValidateChatInputOrThrowPasswordError` at `0x00465890`.
- `g_protectedPasswordToken[32]`.
- `g_passwordProtectSeed`, initialized from `word_66D410 = 0xd544`.
- Private helpers for token decode and `PASS_ENG.STR` message loading.
- Dependency on [UID:0000A8][PasswordError](by-class/PasswordError.md), whose class implementation belongs with [UID:0000J5][Error](by-file/Error.md).

## Evidence

- Wave3 summarizes `SetProtectedPasswordToken` as copying up to 32 wide characters and XOR-obfuscating each character with an incrementing seed.
- Wave3 summarizes `ValidateChatInputOrThrowPasswordError` as rejecting outbound text containing the cached login password and throwing a `PasswordError` built from `PASS_ENG.STR`.
- IDA MCP confirms `0x004657d0-0x00465827` and `0x00465890-0x00465ae2` as real function ranges.
- IDA caller samples for `0x00465890` include multiple text/chat input submit paths, consistent with a shared input guard rather than one dialog class.
- IDA MCP xrefs tie `word_66D410` at [UID:000275][0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals](by-memory/0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals.md) to both encode/decode loops: `SetProtectedPasswordToken` loads it at `0x004657e5`, and `ValidateChatInputOrThrowPasswordError` loads it at `0x004658d2` before XORing each wchar with the incrementing seed.

## Placement Notes

Use a dedicated file during reconstruction. Keeping this code separate from generic error formatting avoids spreading password-filter globals across the error hierarchy. The final folder may move from `auth/` to `chat/` if caller review shows the original code was owned by chat input.

## Open Questions

- Decide whether the seed source name should remain `g_passwordProtectSeed` or use a password-token-specific constant name.
- Review all callers of `SetProtectedPasswordToken` to decide whether the original owner was login/session code.
- Decide whether the `PASS_ENG.STR` load helper should be local to this file or part of a string-resource utility.

## Cross-References

- [UID:0000YS][0x004657d0-0x00467406.PasswordGuardAndFatalError](by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md)
- [UID:000275][0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals](by-memory/0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals.md)
- [UID:000290][0x0067a940-0x0067a980.PasswordGuardProtectedToken](by-memory/0x0067a940-0x0067a980.PasswordGuardProtectedToken.md)
- [UID:0000A8][PasswordError](by-class/PasswordError.md)
- [UID:0000J5][Error](by-file/Error.md)
- [UID:0001QH][client_network](by-meta/client_network.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- Before: the file listed `g_passwordProtectSeed` as an owned symbol but left its initialization location open.
- After: the file links the seed to `word_66D410 = 0xd544` in the initialized data range at [UID:000275][0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals](by-memory/0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals.md), while keeping the final source-level seed name open.
- Evidence: IDA MCP read-only checks show `word_66D410` loaded by both password guard transform paths at `0x004657e5` and `0x004658d2`, and decompiled loops XOR the token characters with an incrementing seed.
