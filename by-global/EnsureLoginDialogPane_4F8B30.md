*** UID:0000PL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EnsureLoginDialogPane

## Status

- Confidence: strong for behavior, source-family placement, recovered alias mapping, and duplicate-emission avoidance.
- Source-facing helper name: `EnsureLoginDialogPane`.
- Recovered/global alias: `EnsureLoginDialogPane_4F8B30`.
- Exact source-bearing range: [UID:00019L][0x004f8b30-0x004f8b8d.EnsureLoginDialogPane](by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md).
- Likely owner source: [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md) / `login/LoginDialogPane.cpp`.
- Rebuild handling for this by-global page: non-emitting recovered-symbol/index page because [UID:00019L][0x004f8b30-0x004f8b8d.EnsureLoginDialogPane](by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md) carries the formal helper body. This avoids duplicate `EnsureLoginDialogPane()` emission.

## Function Role

`EnsureLoginDialogPane()` lazily creates a [UID:00007F][LoginDialogPane](by-class/LoginDialogPane.md) if [UID:0000RE][g_pLoginDialogPane](by-global/g_pLoginDialogPane.md) is null. The compiled body calls the project-wide MemoryMan-backed global `operator new` wrapper at [UID:000196][0x004f4aa0-0x004f4ab4.OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md) with `0x26c` / `620` bytes (Verified with `int_convert.py`) and then calls [UID:0002Q4][0x004fa7a0-0x004fb2d0.LoginDialogPaneCore](by-memory/0x004fa7a0-0x004fb2d0.LoginDialogPaneCore.md) at `0x004fa7a0` if allocation returns non-null. The constructor publishes or clears the singleton; the helper itself does not assign `g_pLoginDialogPane`.

The helper is currently used by [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md) teardown after the accepted forced-inform flow needs to return the client to the login dialog.

## Evidence Notes

- IDA MCP `lookup_funcs 0x004f8b30` reports a real function of size `0x5d`.
- IDA MCP callers are the two forced-inform destructor paths at `0x005880db` and `0x0058ac52`.
- IDA MCP callees are allocator `0x004f4aa0` and `LoginDialogPane::LoginDialogPane` at `0x004fa7a0`.
- IDA MCP `xrefs_to 0x0069b484` confirms this helper reads `g_pLoginDialogPane`.
- IDA MCP recheck on 2026-06-05 confirmed `sub_4F8B30`, size `0x5d`, the same two forced-inform callers, allocator `0x004f4aa0`, and login-dialog constructor `0x004fa7a0`.
- 2026-06-14 A003 live IDA MCP refresh confirmed `sub_4F8B30` is `0x5d` / `93` bytes (Verified with int_convert.py), has seven basic blocks, two direct callers (`sub_588080` and `sub_58ABF0`), and only two callees: allocator `sub_4F4AA0` and `LoginDialogPane` constructor `sub_4FA7A0`.
- 2026-06-14 decompilation reduces to a singleton guard: if `unk_69B484` is null, call `sub_4F4AA0(620)`, and only call `sub_4FA7A0` when allocation succeeds. There are no prompt strings, packet side effects, or forced-inform fields in this helper.
- 2026-06-14 `xrefs_to 0x0069b484` returned 12 refs; this helper contributes the read at `0x004f8b53`, while constructor/destructor/clear refs remain in the LoginDialogPane family. This supports keeping ownership with [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md), not the forced-inform caller file.

## Source Layout Decision

Keep this helper with `login/LoginDialogPane.cpp` or a nearby login helper section. It is not a `ForcedInformMessageDialog` method even though the current caller set is forced-inform teardown.

This page preserves the recovered symbol and address-suffixed alias. It must not also emit the helper body while [UID:00019L][0x004f8b30-0x004f8b8d.EnsureLoginDialogPane](by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md) is the exact source-bearing by-memory page. If a future policy moves the C++ body back to a by-global symbol page, the by-memory target must be made non-emitting at the same time.

## Autogen And Score Rationale

- Owner remains [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md), which has a valid `NexusTK/login/` reconstruction path and surfaces to `auto-generated/NexusTK/login/LoginDialogPane.cpp`.
- This alias page is intentionally `RECONSTRUCTABLE:FALSE` with blank `EMITTER_UIDS` because the exact source-bearing body now lives on [UID:00019L][0x004f8b30-0x004f8b8d.EnsureLoginDialogPane](by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md).
- Completion is `88` because the page records the source-facing helper name, recovered alias, exact source-bearing range, function size, caller set, callee set, singleton read, allocation size, constructor target, source-owner rejection for forced-inform callers, and duplicate-emission policy.
- Confidence is `90` because the current IDA decompilation is very small and directly matches the exact memory child [UID:00019L][0x004f8b30-0x004f8b8d.EnsureLoginDialogPane](by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md). It stays below final-audit levels because original source spelling and the broader login/account dialog source split are not proven by debug/source metadata.

## Cross-References

- [UID:00019L][0x004f8b30-0x004f8b8d.EnsureLoginDialogPane](by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md)
- [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `82/88`.
  - Before: page documented lazy login-dialog creation, callers, callees, global read, and source-layout decision but remained unevaluated.
  - After: score reflects documented behavior, allocation/constructor path, forced-inform caller context, and login-owner assignment.
  - Evidence: IDA notes confirm function size, forced-inform destructor callers, allocator and `LoginDialogPane` constructor callees, and `g_pLoginDialogPane` xrefs.
- 2026-06-05: Marked reconstructable and attached to [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md).
  - Reason: live IDA MCP recheck confirms source-authored lazy login-dialog construction; the helper allocates and constructs `LoginDialogPane`, so it belongs with the login dialog source despite forced-inform callers.
- 2026-06-14 A003 goal2 score pass: raised `82/88` to `86/90`.
  - Evidence: live IDA MCP reconfirmed `0x004f8b30` as a `0x5d` / `93`-byte helper (Verified with int_convert.py), two forced-inform callers, allocator/constructor-only callee set, and the `g_pLoginDialogPane` read at `0x004f8b53` among the LoginDialogPane singleton refs.
  - Code-entry decision: no reconstruction C++ was added; the minimum route/score gate is now met, but final helper spelling, allocator wrapper naming, and login/account source split are still below source-quality evidence.
- 2026-06-20 B001 Rule 26 alias/source-body split:
  - Changed to: `COMPLETION:88`, `CONFIDENCE:90`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank C++.
  - Summary/evidence: [UID:00019L][0x004f8b30-0x004f8b8d.EnsureLoginDialogPane](by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md) now carries the first-draft `EnsureLoginDialogPane()` helper body, so this by-global page is retained as the recovered `EnsureLoginDialogPane_4F8B30` alias/index only. B001 resolved source-facing spelling, documented `0x004f4aa0(620)` as compiler output for `new LoginDialogPane`, preserved forced-inform as caller context, and rejected duplicate emission from both the by-global and by-memory pages.
