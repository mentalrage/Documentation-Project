*** UID:0000MG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/auth/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# PasswordGuard

## Status

- Confidence: strong for exact function boundaries, guard globals, decompiled transform behavior, and caller split; medium-high for the exact original folder/name.
- Proposed module: `NexusTK/auth/PasswordGuard.cpp`.
- Main address docs: [UID:0000YS][0x004657d0-0x00467406.PasswordGuardAndFatalError](by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md), [UID:000275][0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals](by-memory/0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals.md), and [UID:000290][0x0067a940-0x0067a980.PasswordGuardProtectedToken](by-memory/0x0067a940-0x0067a980.PasswordGuardProtectedToken.md)
- Evidence basis: live IDA MCP lookup, caller, xref, decompile, and data reads on 2026-06-04.

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

- IDA MCP lookup confirms `SetProtectedPasswordToken` at `0x004657d0-0x00465827`, `ValidateChatInputOrThrowPasswordError` at `0x00465890-0x00465ae2`, and the adjacent-but-separate `FatalError` helper at `0x00465cb0-0x00465ce0`.
- IDA decompilation of `0x004657d0` copies up to 32 wide characters into `word_67A940`, sets `word_67A97E = 0`, loads `word_66D410`, and XOR-obfuscates each nonzero wchar with the incrementing seed.
- IDA decompilation of `0x00465890` copies `word_67A940` into a local 32-wchar buffer, decodes it with the same `word_66D410` incrementing-seed loop, checks `wcsstr(Str, SubStr)`, loads `PASS_ENG.STR` via `off_612E8C`, converts/appends resource lines into a wide message, constructs `PasswordError`, and throws it with `_CxxThrowException`.
- IDA caller evidence for `0x004657d0` is a single login caller at `0x004fb60b` in `sub_4FB2D0`, matching token capture after login submission.
- IDA caller evidence for `0x00465890` includes 13 text/social submit sites: `0x00477606`, `0x00477612`, `0x0047de03`, `0x0047de0f`, `0x0059e480`, `0x005ae0a0`, `0x005b1680`, `0x005b1aa0`, `0x005b1fc0`, `0x005b23d0`, `0x005b36d1`, `0x005b3aa1`, and `0x005b42b2`, consistent with a shared outbound-input guard rather than one pane method.
- IDA MCP xrefs tie `word_66D410` at [UID:000275][0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals](by-memory/0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals.md) to both encode/decode loops: `SetProtectedPasswordToken` loads it at `0x004657e5`, and `ValidateChatInputOrThrowPasswordError` loads it at `0x004658d2` before XORing each wchar with the incrementing seed.
- IDA xrefs tie the protected token buffer at `word_67A940` to setter accesses `0x004657db`, `0x004657f7`, `0x004657fe` and validator access `0x004658c5`; the setter writes the terminal word at `word_67A97E` via `0x004657ee`.
- IDA data reads identify `off_612E8C` as the wide string `PASS_ENG.STR`, `word_66D410` as initialized to `0xd544`, and `0x006125bc` as the `Password Warning` descriptor returned by `PasswordError`'s descriptor virtual.
- IDA lookup/decompile confirms `PasswordError` constructor `0x00467160-0x00467181` is called from `0x00465abe` inside the guard throw path, while the destructor `0x00467300-0x00467338` and descriptor helper `0x00467400-0x00467406` are class/error-hierarchy members.
- IDA caller evidence for `FatalError` is application/error oriented (`Application__Constructor` at `0x00463964`, repeated `sub_4639D0` startup/error sites, `sub_467410`, and `sub_4918E0` sites), supporting its exclusion from `PasswordGuard.cpp`.
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

- 2026-06-04 live IDA refresh:
  - Before: the page still relied on older non-IDA summaries for the two guard functions and had not recorded the full live caller/global split.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:88`.
  - Summary/evidence: live IDA MCP verified exact function ranges, the single login caller for `0x004657d0`, the 13 outbound-input callers for `0x00465890`, the `word_67A940`/`word_67A97E` token-buffer xrefs, the `word_66D410 = 0xd544` seed, the `PASS_ENG.STR` resource path, the `PasswordError` throw path, and the separate `FatalError` caller fanout. The score remains below reconstruction-ready because original source filename/folder and the local resource helper shape are still not proven.
