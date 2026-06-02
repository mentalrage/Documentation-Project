*** UID:0000MG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/auth/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# PasswordGuard

## Status

- Confidence: strong for function behavior and current `auth/PasswordGuard.cpp` placement; medium-high for the exact original folder/name.
- Proposed module: `auth/PasswordGuard.cpp`.
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

## Source Split

| Entity | Rebuild owner | Evidence/caveat |
| --- | --- | --- |
| `SetProtectedPasswordToken` | `auth/PasswordGuard.cpp` | Called from [UID:0002Q5][0x004fb2d0-0x004fb62a.SendLoginRequest](by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md) after login packet submission, proving login/session code supplies the protected token. |
| `ValidateChatInputOrThrowPasswordError` | `auth/PasswordGuard.cpp` | Called by chat/social input submitters such as [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md), [UID:0001MB][0x005b34d0-0x005b37ea.SayInputPane](by-memory/0x005b34d0-0x005b37ea.SayInputPane.md), [UID:0001LZ][0x005b1ec0-0x005b2152.SayToGroupMessageInputPane](by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md), and [UID:0001MF][0x005b4260-0x005b43bc.ShoutInputPane](by-memory/0x005b4260-0x005b43bc.ShoutInputPane.md). |
| `g_protectedPasswordToken[32]` | `auth/PasswordGuard.cpp` | [UID:000290][0x0067a940-0x0067a980.PasswordGuardProtectedToken](by-memory/0x0067a940-0x0067a980.PasswordGuardProtectedToken.md) documents the static wide buffer and ownership. |
| `word_66D410` seed | `auth/PasswordGuard.cpp` | [UID:000275][0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals](by-memory/0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals.md) documents the initialized `0xd544` seed and both transform xrefs. |
| `PasswordError` class | [UID:0000J5][Error](by-file/Error.md) | Constructed by the guard, but the class/vtable/error hierarchy belongs with the shared error source. |
| `FatalError` | unresolved app/error helper | Keep out of `PasswordGuard.cpp` until caller review decides between `app/Application.cpp`, `util/Error.cpp`, or a small fatal-dialog source. |

## Evidence

- Wave3 summarizes `SetProtectedPasswordToken` as copying up to 32 wide characters and XOR-obfuscating each character with an incrementing seed.
- Wave3 summarizes `ValidateChatInputOrThrowPasswordError` as rejecting outbound text containing the cached login password and throwing a `PasswordError` built from `PASS_ENG.STR`.
- IDA MCP confirms `0x004657d0-0x00465827` and `0x00465890-0x00465ae2` as real function ranges.
- IDA caller samples for `0x00465890` include multiple text/chat input submit paths, consistent with a shared input guard rather than one dialog class.
- IDA MCP xrefs tie `word_66D410` at [UID:000275][0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals](by-memory/0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals.md) to both encode/decode loops: `SetProtectedPasswordToken` loads it at `0x004657e5`, and `ValidateChatInputOrThrowPasswordError` loads it at `0x004658d2` before XORing each wchar with the incrementing seed.
- [UID:0002Q5][0x004fb2d0-0x004fb62a.SendLoginRequest](by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md) records `0x004657d0` as the post-submit password-token helper after the login packet is queued.
- Chat/social input pages record `0x00465890` as a callee before message sanitizer/packet send paths, establishing this as a shared outbound-text guard rather than a single chat-pane method.
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already stages `PasswordGuard.cpp` under `auth/` and separately documents the final-folder caveat.

## Placement Notes

Use a dedicated file during reconstruction. Keeping this code separate from generic error formatting avoids spreading password-filter globals across the error hierarchy. The current staged folder is `NexusTK/auth/`, because one side of the API is login/session token capture and the other side is outbound text protection. A later final-source audit can still rename or move the file if original-name evidence appears.

## Open Questions

- Decide whether the seed source name should remain `g_passwordProtectSeed` or use a password-token-specific constant name.
- Decide whether any additional non-chat/social caller of `ValidateChatInputOrThrowPasswordError` changes the final folder from `auth/` to a more specific chat/login module.
- Decide whether the `PASS_ENG.STR` load helper should be local to this file or part of a string-resource utility.

## Cross-References

- [UID:0000YS][0x004657d0-0x00467406.PasswordGuardAndFatalError](by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md)
- [UID:0002Q5][0x004fb2d0-0x004fb62a.SendLoginRequest](by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md)
- [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md)
- [UID:0001MB][0x005b34d0-0x005b37ea.SayInputPane](by-memory/0x005b34d0-0x005b37ea.SayInputPane.md)
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
- Before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the page kept `auth/` versus chat/login placement fully open.
- After: the page stages `NexusTK/auth/`, raises the score to `74/84`, and records a source-split table separating guard helpers/globals from `PasswordError` and `FatalError`.
- Evidence: `proposed-source-tree.md` already places `PasswordGuard.cpp` under `auth/`; `SendLoginRequest` records the `0x004657d0` post-submit token call, and chat/social input pages record `0x00465890` as the shared outbound-text validation guard.
