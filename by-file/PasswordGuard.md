*** UID:0000MG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/auth/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# PasswordGuard

## Status

- Confidence: strong for exact function boundaries, guard globals, decompiled transform behavior, and caller split; medium-high for the exact original folder/name.
- Proposed module: `NexusTK/auth/PasswordGuard.cpp`.
- Main address docs: [UID:0000YS][0x004657d0-0x00467406.PasswordGuardAndFatalError](by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md), [UID:0002VG][0x004657d0-0x00465827.SetProtectedPasswordToken](by-memory/0x004657d0-0x00465827.SetProtectedPasswordToken.md), [UID:0002VH][0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError](by-memory/0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md), [UID:00035L][0x0066d410-0x0066d412.PasswordGuardXorSeed](by-memory/0x0066d410-0x0066d412.PasswordGuardXorSeed.md), [UID:000275][0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals](by-memory/0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals.md), and [UID:000290][0x0067a940-0x0067a980.PasswordGuardProtectedToken](by-memory/0x0067a940-0x0067a980.PasswordGuardProtectedToken.md)
- Evidence basis: live IDA MCP lookup, caller, xref, decompile, disassembly, bytes, and data reads through B005's restored-MCP pass on 2026-07-02, B008 session `e63ee655` for UID000290's source-ready token declaration, and B008 current MCP session `b006-0000xu` for UID0002VG's source-ready setter plus UID00035L seed declaration.

## Responsibility

This module caches the active login password in an XOR-obfuscated wide-character buffer and prevents the user from sending chat/input text that contains that password. On a match, it loads `PASS_ENG.STR`, builds a localized wide error message, and throws `PasswordError`.

## Likely Contents

- `static wchar_t g_protectedPasswordToken[32]`, emitted by [UID:000290][0x0067a940-0x0067a980.PasswordGuardProtectedToken](by-memory/0x0067a940-0x0067a980.PasswordGuardProtectedToken.md) at emitter position `10`.
- `static unsigned short g_passwordProtectSeed = 0xd544`, emitted by [UID:00035L][0x0066d410-0x0066d412.PasswordGuardXorSeed](by-memory/0x0066d410-0x0066d412.PasswordGuardXorSeed.md) at emitter position `20`.
- [UID:0002VG][0x004657d0-0x00465827.SetProtectedPasswordToken](by-memory/0x004657d0-0x00465827.SetProtectedPasswordToken.md), now source-ready as `void SetProtectedPasswordToken(const wchar_t *password)` at emitter position `30`.
- [UID:00055E][0x00465830-0x0046588c.GetProtectedPasswordTokenRaw](by-memory/0x00465830-0x0046588c.GetProtectedPasswordTokenRaw.md), source-ready as `wchar_t *GetProtectedPasswordToken(wchar_t *destination, size_t destinationChars)` at emitter position `40`.
- [UID:0002VH][0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError](by-memory/0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md), source-ready as `void ValidateChatInputOrThrowPasswordError(const wchar_t *text)` at emitter position `50`.
- [UID:00055F][0x00612e8c-0x00612ea6.PasswordGuardPassEngString](by-memory/0x00612e8c-0x00612ea6.PasswordGuardPassEngString.md), exact `PASS_ENG.STR` UTF-16 source literal at emitter position `60`, source-covered by the validator body rather than a standalone table.
- Dependency on [UID:0000A8][PasswordError](by-class/PasswordError.md), whose class implementation belongs with [UID:0000J5][Error](by-file/Error.md). The exact constructor [UID:0002VJ][0x00467160-0x00467181.PasswordErrorConstructor](by-memory/0x00467160-0x00467181.PasswordErrorConstructor.md) is now source-ready as `PasswordError::PasswordError(const wchar_t *message) : MyError(message) {}` and still emits through the Error hierarchy, not this guard file.

## Source Split

| Entity | Rebuild owner | Evidence/caveat |
| --- | --- | --- |
| `static wchar_t g_protectedPasswordToken[32]` | `auth/PasswordGuard.cpp` | [UID:000290][0x0067a940-0x0067a980.PasswordGuardProtectedToken](by-memory/0x0067a940-0x0067a980.PasswordGuardProtectedToken.md) emits the source-ready static wide buffer declaration at position `10`, before functions that use it. B008 session `e63ee655` confirms the exact all-zero 64-byte range, setter refs at `0x004657db`, `0x004657f7`, `0x004657fe`, orphan helper ref at `0x0046584b`, validator ref at `0x004658c5`, terminator write at `0x004657ee`, seed-paired XOR behavior, and `0x0067a980` successor boundary. |
| `static unsigned short g_passwordProtectSeed = 0xd544` | `auth/PasswordGuard.cpp` | Exact child [UID:00035L][0x0066d410-0x0066d412.PasswordGuardXorSeed](by-memory/0x0066d410-0x0066d412.PasswordGuardXorSeed.md) now emits the initialized seed at position `20`. Current B008 MCP session `b006-0000xu` confirms bytes `44 d5`, matching `0xd544` / 54596, and seed xrefs at `0x004657e5`, `0x00465866`, and `0x004658d2`; mixed aggregate [UID:000275][0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals](by-memory/0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals.md) remains non-emitting. |
| [UID:0002VG][0x004657d0-0x00465827.SetProtectedPasswordToken](by-memory/0x004657d0-0x00465827.SetProtectedPasswordToken.md) | `auth/PasswordGuard.cpp` | Source-ready as `void SetProtectedPasswordToken(const wchar_t *password)` at position `30`. Called from [UID:0002Q5][0x004fb2d0-0x004fb62a.SendLoginRequest](by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md) after login packet submission, proving login/session code supplies the protected token; current B008 MCP session `b006-0000xu` reconfirms exact `0x57` size, one caller at `0x004fb60b`, and `_wcsncpy_s` as only callee. |
| [UID:00055E][0x00465830-0x0046588c.GetProtectedPasswordTokenRaw](by-memory/0x00465830-0x0046588c.GetProtectedPasswordTokenRaw.md) | `auth/PasswordGuard.cpp` | Exact 92-byte caller-buffer decoder at position `40`; zero-count branch still writes `destination[0]`, positive-count path copies, forces `destination[destinationChars-1]` to NUL, incrementally XOR-decodes, and returns the destination. Zero inbound xrefs plus fixed-size equivalent lowering inside UID0002VH support an externally retained same-TU helper rather than dead/padding code. |
| [UID:0002VH][0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError](by-memory/0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md) | `auth/PasswordGuard.cpp` | Complete `void` throwing guard at position `50`, with 13 exact outbound-input callers, UID00055E decoding, DATFile `ReadLineChars`, exact PASS literal, convert-before-short-line-break lowering, PasswordError throw, and conditional normal-path clear. |
| [UID:00055F][0x00612e8c-0x00612ea6.PasswordGuardPassEngString](by-memory/0x00612e8c-0x00612ea6.PasswordGuardPassEngString.md) | `auth/PasswordGuard.cpp` | Exact 26-byte `PASS_ENG.STR` plus NUL source literal at position `60`, one xref at `0x0046592d`, two-byte alignment, `Aborted` successor excluded; source-covered by the open call. |
| `PasswordError` class | [UID:0000J5][Error](by-file/Error.md) | Constructed by the guard, but the class/vtable/error hierarchy belongs with the shared error source. [UID:0002VJ][0x00467160-0x00467181.PasswordErrorConstructor](by-memory/0x00467160-0x00467181.PasswordErrorConstructor.md) now emits the source-ready derived constructor body through `PasswordError`/`Error.cpp`; the guard remains only the throw-site consumer. |
| `FatalError` | [UID:0000HG][Application](by-file/Application.md) | Excluded from PasswordGuard. Current [UID:0002VI][0x00465cb0-0x00465ce0.FatalErrorDialogAndBreak](by-memory/0x00465cb0-0x00465ce0.FatalErrorDialogAndBreak.md) authority places the application/resource fatal-dialog helper with Application; the former unresolved-owner wording is historical. |

## Evidence

- IDA MCP lookup confirms `SetProtectedPasswordToken` at `0x004657d0-0x00465827`, `ValidateChatInputOrThrowPasswordError` at `0x00465890-0x00465ae2`, and the adjacent-but-separate `FatalError` helper at `0x00465cb0-0x00465ce0`.
- IDA decompilation of `0x004657d0` copies up to 32 wide characters into `word_67A940`, sets `word_67A97E = 0`, loads `word_66D410`, and XOR-obfuscates each nonzero wchar with the incrementing seed.
- B008 current MCP session `b006-0000xu` reconfirms `SetProtectedPasswordToken` as `sub_4657D0` size `0x57`, one direct caller at `0x004fb60b`, `_wcsncpy_s` as only callee, token refs `0x004657db`/`0x004657f7`/`0x004657fe`, terminator write `0x004657ee`, seed load `0x004657e5`, seed bytes `44 d5` / `0xd544`, and the all-zero 64-byte protected-token buffer at `0x0067a940-0x0067a980`.
- IDA decompilation of `0x00465890` copies `word_67A940` into a local 32-wchar buffer, decodes it with the same `word_66D410` incrementing-seed loop, checks `wcsstr(Str, SubStr)`, loads `PASS_ENG.STR` via `off_612E8C`, converts/appends resource lines into a wide message, constructs `PasswordError`, and throws it with `_CxxThrowException`.
- IDA caller evidence for `0x004657d0` is a single login caller at `0x004fb60b` in `sub_4FB2D0`, matching token capture after login submission.
- IDA caller evidence for `0x00465890` includes 13 text/social submit sites: `0x00477606`, `0x00477612`, `0x0047de03`, `0x0047de0f`, `0x0059e480`, `0x005ae0a0`, `0x005b1680`, `0x005b1aa0`, `0x005b1fc0`, `0x005b23d0`, `0x005b36d1`, `0x005b3aa1`, and `0x005b42b2`, consistent with a shared outbound-input guard rather than one pane method.
- IDA MCP xrefs tie `word_66D410` at exact child [UID:00035L][0x0066d410-0x0066d412.PasswordGuardXorSeed](by-memory/0x0066d410-0x0066d412.PasswordGuardXorSeed.md) to both encode/decode loops: `SetProtectedPasswordToken` loads it at `0x004657e5`, and `ValidateChatInputOrThrowPasswordError` loads it at `0x004658d2` before XORing each wchar with the incrementing seed.
- IDA xrefs tie the protected token buffer at `word_67A940` to setter accesses `0x004657db`, `0x004657f7`, `0x004657fe` and validator access `0x004658c5`; the setter writes the terminal word at `word_67A97E` via `0x004657ee`.
- B008 MCP session `e63ee655` updates UID000290 to source-ready data: `get_bytes` reports the full `0x0067a940-0x0067a980` token buffer as 64 zero bytes, `insn_query` over the PasswordGuard cluster finds exactly five token uses including the orphan helper-shaped block at `0x00465830-0x0046588b`, and `xrefs_to 0x0067a980` reaches only successor/global code rather than the token. The current emitted name remains `g_protectedPasswordToken`; `g_passwordGuardToken` is treated as a stale project-level alias unless a later coordinated rename updates the setter, validator, and target declaration together.
- IDA data reads identify `off_612E8C` as the wide string `PASS_ENG.STR`, `word_66D410` as initialized to `0xd544`, and `0x006125bc` as the `Password Warning` descriptor returned by `PasswordError`'s descriptor virtual.
- IDA lookup/decompile confirms `PasswordError` constructor `0x00467160-0x00467181` is called from `0x00465abe` inside the guard throw path, while the destructor `0x00467300-0x00467338` and descriptor helper `0x00467400-0x00467406` are class/error-hierarchy members. B013's 2026-06-28 MCP-backed callback confirms the constructor itself is now source-ready as `PasswordError::PasswordError(const wchar_t *message) : MyError(message) {}`; the compiled vtable write remains ABI output from the Error/PasswordError declaration route.
- B005's 2026-07-02 restored-MCP implementation pass reconfirms `ValidateChatInputOrThrowPasswordError` as `sub_465890` size `0x252`, `0x00465ae2` as not a function, all 13 outbound-input callers, `word_66D410` seed bytes `44 d5`, UTF-16 `PASS_ENG.STR` bytes at `0x00612e8c`, DAT line-reader calls, `MultiByteToWideChar`, source-ready `PasswordError` construction at `0x00465abe`, and `_CxxThrowException`. The pass resolves the helper's source contract as a `void` guard that throws; `__int16` is a decompiler return artifact.
- 2026-06-05 exact child split records [UID:0002VG][0x004657d0-0x00465827.SetProtectedPasswordToken](by-memory/0x004657d0-0x00465827.SetProtectedPasswordToken.md) and [UID:0002VH][0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError](by-memory/0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md) as the two PasswordGuard-owned code ranges; [UID:0002VI][0x00465cb0-0x00465ce0.FatalErrorDialogAndBreak](by-memory/0x00465cb0-0x00465ce0.FatalErrorDialogAndBreak.md) remains excluded from this file because its callers are application/resource fatal-error paths.
- IDA caller evidence for `FatalError` is application/error oriented (`Application__Constructor` at `0x00463964`, repeated `sub_4639D0` startup/error sites, `sub_467410`, and `sub_4918E0` sites), supporting its exclusion from `PasswordGuard.cpp`.
- [UID:0002Q5][0x004fb2d0-0x004fb62a.SendLoginRequest](by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md) records `0x004657d0` as the post-submit password-token helper after the login packet is queued.
- Chat/social input pages record `0x00465890` as a callee before message sanitizer/packet send paths, establishing this as a shared outbound-text guard rather than a single chat-pane method.
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already stages `PasswordGuard.cpp` under `auth/` and separately documents the final-folder caveat.

## Placement Notes

Use a dedicated file during reconstruction. Keeping this code separate from generic error formatting avoids spreading password-filter globals across the error hierarchy. The current staged folder is `NexusTK/auth/`, because one side of the API is login/session token capture and the other side is outbound text protection. A later final-source audit can still rename or move the file if original-name evidence appears.

## Open Questions

- Exact historical symbol spellings and original filename remain unrecovered. The coordinated reconstruction names and `NexusTK/auth/PasswordGuard.cpp/.h` route are source-ready and should change only in a later whole-family rename.
- The earlier helper-future, chat-folder, PASS-owner, and unresolved-FatalError questions are closed by UID00055E/UID00055F, the full caller inventory, and UID0002VI's Application route. They remain preserved below as dated history rather than active blockers.

## Cross-References

- [UID:0000YS][0x004657d0-0x00467406.PasswordGuardAndFatalError](by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md)
- [UID:0002VG][0x004657d0-0x00465827.SetProtectedPasswordToken](by-memory/0x004657d0-0x00465827.SetProtectedPasswordToken.md)
- [UID:0002VH][0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError](by-memory/0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md)
- [UID:00055E][0x00465830-0x0046588c.GetProtectedPasswordTokenRaw](by-memory/0x00465830-0x0046588c.GetProtectedPasswordTokenRaw.md)
- [UID:00055F][0x00612e8c-0x00612ea6.PasswordGuardPassEngString](by-memory/0x00612e8c-0x00612ea6.PasswordGuardPassEngString.md)
- [UID:0002VI][0x00465cb0-0x00465ce0.FatalErrorDialogAndBreak](by-memory/0x00465cb0-0x00465ce0.FatalErrorDialogAndBreak.md)
- [UID:0002Q5][0x004fb2d0-0x004fb62a.SendLoginRequest](by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md)
- [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md)
- [UID:0001MB][0x005b34d0-0x005b37ea.SayInputPane](by-memory/0x005b34d0-0x005b37ea.SayInputPane.md)
- [UID:00035L][0x0066d410-0x0066d412.PasswordGuardXorSeed](by-memory/0x0066d410-0x0066d412.PasswordGuardXorSeed.md)
- [UID:000275][0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals](by-memory/0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals.md)
- [UID:000290][0x0067a940-0x0067a980.PasswordGuardProtectedToken](by-memory/0x0067a940-0x0067a980.PasswordGuardProtectedToken.md)
- [UID:0000A8][PasswordError](by-class/PasswordError.md)
- [UID:0000J5][Error](by-file/Error.md)
- [UID:0001QH][client_network](by-meta/client_network.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-08-17 B001 UID0000MG whole-file implementation callback:
  - Raised `86/90 -> 94/95`; established the complete six-position inventory: UID000290 token `10`, UID00035L seed `20`, UID0002VG setter `30`, UID00055E decoder `40`, UID0002VH validator `50`, and UID00055F PASS literal marker `60`.
  - Added complete sibling `PasswordGuard.h` ownership through UID0002VG, complete owner preamble through UID000290, Error/File/DATFile dependencies, exact raw-helper and PASS children, and complete generated-output contract.
  - Exact code/data inventory: setter `[0x004657d0,0x00465827)` 87 bytes/29 instructions/SHA256 `4A39F094D96B94DC500339D35A80ABDA39790F057141B081CDC59C872918A458`; decoder `[0x00465830,0x0046588c)` 92 bytes/40 instructions/SHA256 `9BD60E8D2DD9C9884BF51BF2832478794893255660D651DB2F66DD500DF72582`; validator `[0x00465890,0x00465ae2)` 594 bytes/181 instructions/SHA256 `B146DDF03BFB7C64FBED4EFA773EA872AEB85E8331479DBE79FE26D7CF0BB363`; PASS `[0x00612e8c,0x00612ea6)` 26 bytes/SHA256 `30D258B7089D410DE374D94245465C8A7C82E45FC852B2687814BA343D7798D2`; token semantic range 64 zero bytes/SHA256 `F5A5FD42D16A20302798EF6ED309979B43003D2320D9F0E8EA9831A92759FB4B`; seed bytes `44 d5`.
  - Internal padding is exactly G1 `[0x00465827,0x00465830)` nine `cc` bytes, SHA256 `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`; G2 `[0x0046588c,0x00465890)` four `cc` bytes, SHA256 `8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA`; G3 `[0x00465ae2,0x00465af0)` fourteen `cc` bytes, SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`.
  - The one setter caller plus 13 validator calls yield 14 PasswordGuard calls: `0x004fb60b`; `0x00477606`, `0x00477612`, `0x0047de03`, `0x0047de0f`, `0x0059e480`, `0x005ae0a0`, `0x005b1680`, `0x005b1aa0`, `0x005b1fc0`, `0x005b23d0`, `0x005b36d1`, `0x005b3aa1`, and `0x005b42b2`.
  - Historicalized, without deleting, the former two-function-only, helper-future/dead-code, direct duplicate decoder, blank-H, unresolved PASS owner, unresolved FatalError owner, chat-folder-open, and generated-complete assumptions. The complete generated contract is one CPP with two statics/three definitions/exact literal and one sibling H with three declarations; all consumer includes must resolve, with no raw IDA name, empty marker, duplicate definition/declaration, helper shorthand, or missing NewMail/clan call.

- 2026-07-05 B008 UID0002VG implementation callback:
  - Score unchanged at `86/90`.
  - Updated likely contents, source split, evidence, and placement/order notes to record the current PasswordGuard emitted order: token declaration position `10`, seed declaration position `20`, `SetProtectedPasswordToken` position `30`, and `ValidateChatInputOrThrowPasswordError` position `40`.
  - Summary/evidence: current MCP session `b006-0000xu` reconfirmed UID0002VG exact `0x57` size, one caller at `0x004fb60b`, `_wcsncpy_s` as only callee, token/terminator/seed xrefs, seed bytes `44 d5` / `0xd544`, and all-zero token buffer evidence. UID0002VG now emits `void SetProtectedPasswordToken(const wchar_t *password)`, and UID00035L now emits `static unsigned short g_passwordProtectSeed = 0xd544;`.

- 2026-07-03 B008 UID000290 declaration sync:
  - Score and metadata unchanged.
  - Updated the source split and evidence to record that [UID:000290][0x0067a940-0x0067a980.PasswordGuardProtectedToken](by-memory/0x0067a940-0x0067a980.PasswordGuardProtectedToken.md) now emits `static wchar_t g_protectedPasswordToken[32];` through this file.
  - Summary/evidence: B008 MCP session `e63ee655` confirmed the all-zero 64-byte range, setter refs `0x004657db`/`0x004657f7`/`0x004657fe`, terminator write `0x004657ee`, orphan helper ref `0x0046584b`, validator ref `0x004658c5`, seed value/use, `0x00465830-0x0046588b` helper-shaped token copy/decode support, and `0x0067a980` successor-boundary proof. The stale alias `g_passwordGuardToken` remains rejected as current emitted name.

- 2026-07-02 B005 UID0002VH source-ready implementation sync:
  - Score unchanged.
  - Updated the `ValidateChatInputOrThrowPasswordError` source split and evidence to record that [UID:0002VH][0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError](by-memory/0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md) now emits first-draft C++ through `auth/PasswordGuard.cpp` as `void ValidateChatInputOrThrowPasswordError(const wchar_t *text)`.
  - Summary/evidence: B005 restored-MCP session `supervisor_resume_20260629` reconfirmed exact bounds, 13 outbound-input callers, protected-token decode, `word_66D410` seed bytes `44 d5`, UTF-16 `PASS_ENG.STR`, DAT read/convert/append loop, source-ready `PasswordError` constructor call at `0x00465abe`, and the rejected alternatives: PasswordError/Error ownership, chat-pane ownership, broad aggregate emission, and a standalone resource-loader owner.

- 2026-06-28 B013 PasswordError constructor consumer-route sync:
  - Score unchanged.
  - Added that [UID:0002VJ][0x00467160-0x00467181.PasswordErrorConstructor](by-memory/0x00467160-0x00467181.PasswordErrorConstructor.md) now emits its exact constructor through [UID:0000A8][PasswordError](by-class/PasswordError.md) / [UID:0000J5][Error](by-file/Error.md), while this file continues to own the protected-token setter, outbound-text validator, globals, resource-loading throw path, and `_CxxThrowException` call site only.
  - Summary/evidence: live MCP session `supervisor_20260628_resume` reconfirmed the constructor's `MyError` base call, compiler-generated vtable store, and PasswordGuard caller at `0x00465abe`; no class/vtable/RTTI/descriptor ownership moved into `auth/PasswordGuard.cpp`.

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

- 2026-06-05 exact child split:
  - Before: the file relied on the mixed aggregate for both PasswordGuard-owned functions.
  - Changed to: exact child pages [UID:0002VG][0x004657d0-0x00465827.SetProtectedPasswordToken](by-memory/0x004657d0-0x00465827.SetProtectedPasswordToken.md) and [UID:0002VH][0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError](by-memory/0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md) now hold the function-level evidence; score raised to `86/90`.
  - Summary/evidence: IDA MCP reverified boundaries, callers, seed/token globals, `PASS_ENG.STR`, and the PasswordError throw path while preserving the exclusion of FatalError from `auth/PasswordGuard.cpp`.

- 2026-06-10 B001-040 seed child split:
  - Score unchanged at `86/90`.
  - Added exact seed child [UID:00035L][0x0066d410-0x0066d412.PasswordGuardXorSeed](by-memory/0x0066d410-0x0066d412.PasswordGuardXorSeed.md) as the PasswordGuard-owned initialized seed split from mixed aggregate [UID:000275][0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals](by-memory/0x0066d408-0x0066d414.DisplayStartupAndPasswordGuardGlobals.md).
  - Evidence: prior IDA-backed docs show both PasswordGuard transform loops load `word_66D410`; Application/display globals and padding remain outside this file.
