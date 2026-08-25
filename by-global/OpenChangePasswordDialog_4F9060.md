*** UID:0000TA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// OpenChangePasswordDialog is emitted by exact helper [UID:00019Q][0x004f9060-0x004f90b4.OpenChangePasswordDialog](by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md); this address-suffixed global page remains a search/support alias and does not duplicate the retained launcher body.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# OpenChangePasswordDialog_4F9060

## Status

- Confidence: very strong for byte range, behavior, constructor target, duplicate active path, singleton publication, accepted void opener source shape, and current unreferenced status; medium-high for why the wrapper was retained.
- Address range: [UID:00019Q][0x004f9060-0x004f90b4.OpenChangePasswordDialog](by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md)
- Symbol kind: retained duplicate main-menu/account launcher helper.
- Current IDA name: accepted B010 report session `875bf182` and implementation-check session `b001_000241_20260627` both report the misleading `___std_parallel_algorithms_hw_threads@0_0`; this page keeps `OpenChangePasswordDialog_4F9060` as the address-suffixed support/search alias.
- Likely owner file: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md), with target behavior in [UID:0000I3][ChangePasswordDialogPane](by-file/ChangePasswordDialogPane.md)
- Autogen status: reconstructable retained launcher attached to [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md). The current child `88/90` and parent `89/86` clear the strict `85/85` route; the attachment is still confidence-capped because the helper itself remains unreferenced in the active call graph.
- C++ status: alias/support page stays blank to avoid duplicate emission; exact emitted body belongs to [UID:00019Q][0x004f9060-0x004f90b4.OpenChangePasswordDialog](by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md) as `static void OpenChangePasswordDialog()`.

## Behavior

`OpenChangePasswordDialog_4F9060` names the retained helper at `0x004f9060`. The exact body allocates `0x26c` / 620 bytes and constructs [UID:00001L][ChangePasswordDialogPane](by-class/ChangePasswordDialogPane.md) on success. The accepted source-facing function is a side-effect opener, `static void OpenChangePasswordDialog()`, because no caller or callback route consumes a returned pointer and the constructor publishes the live dialog through [UID:0002XM][0x0069b48c-0x0069b490.g_pChangePasswordDialogPane](by-memory/0x0069b48c-0x0069b490.g_pChangePasswordDialogPane.md).

Observed behavior:

- calls [UID:000196][0x004f4aa0-0x004f4ab4.OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md) with size `0x26c` / 620;
- on success calls the `ChangePasswordDialogPane` constructor at `0x004fdd40`, documented in [UID:0002QA][0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore](by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md);
- leaves any final `EAX` pointer as an unconstrained machine artifact; accepted source does not model a returned-pointer contract.

IDA reports no direct caller/xref to the helper start in the current database. The active [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md) action handler case `2` directly allocates `0x26c` / 620 bytes through [UID:000196][0x004f4aa0-0x004f4ab4.OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md), calls the same `ChangePasswordDialogPane` constructor, and then breaks without consuming the constructed pointer. This wrapper is best treated as retained duplicate `MainMenuPane.cpp` launcher code; missing callback-route proof caps confidence but no longer blocks the exact child from emitting first-draft C++.

## Source-Shape Decision

The address-suffixed symbol remains useful for search and historical IDA/generated output, but final source should use `OpenChangePasswordDialog` without the `_4F9060` suffix. The accepted exact child C++ lives only on [UID:00019Q][0x004f9060-0x004f90b4.OpenChangePasswordDialog](by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md); this alias page intentionally keeps its formal block blank.

Rejected alternatives:

| Alternative | Rejection reason |
| --- | --- |
| `static ChangePasswordDialogPane *OpenChangePasswordDialog()` | No caller, callback table, active duplicate path, or singleton lifecycle evidence proves a source-level returned-pointer contract. |
| Duplicate formal C++ on this alias page | The exact by-memory child owns the emitted body; this by-global page is support-only. |
| Keep C++ blank on the exact child | Current evidence supports a first-draft side-effect opener; no-xref/no-pointer evidence is a confidence cap. |
| Move owner to `ChangePasswordDialogPane`, MemoryMan, runtime/library, no-owner, or generated-only | The helper belongs to the retained main-menu launcher family; constructor and allocator are dependencies, not owners. |

## Evidence

- IDA MCP `lookup_funcs 0x004f9060` reports a real function of size `0x54`.
- IDA MCP `decompile 0x004f9060` shows allocation followed by `sub_4FDD40(result)`.
- IDA MCP `callers` and `xrefs_to` for `0x004f9060` return no direct references.
- IDA MCP `callers 0x004fdd40` reports constructor call sites at `0x004f7b49` and `0x004f90a0`.
- 2026-06-04 live IDA reports exact function boundaries at `0x004f9060-0x004f90b4`, with eleven `0xcc` bytes before the helper and twelve `0xcc` bytes before the next helper at `0x004f90c0`.
- 2026-06-04 live disassembly records the SEH/security-cookie frame, allocator immediate `0x26c`, null check, `ecx = eax`, and constructor call at `0x004f90a0`.
- 2026-06-04 live IDA reports no xrefs to the helper entry, exactly two xrefs to the constructor (`0x004f7b49` and `0x004f90a0`), and zero loaded dword hits for `0x004f9060`.
- 2026-06-04 live decompile/disassembly of `sub_4F7A10` confirms main-menu action case `2` directly duplicates the `sub_4F4AA0(620)` plus `sub_4FDD40` construction path.
- 2026-05-26 IDA recheck still reports no code or data refs to `0x004f9060`; keep reachability weak until an indirect callback table or dead-code decision is proven.
- 2026-05-27 IDA raw-pointer scan across loaded segments found no dword equal to `0x004f9060`.
- 2026-05-28 IDA MCP recheck still reports no code/data refs, no little-endian pointer byte match for `60 90 4F 00`, and no immediate-value search hits for `0x004f9060`.
- 2026-05-28 IDA MCP decompile of `0x004f7a10` shows main-menu case `2` directly allocating `620` bytes and calling `0x004fdd40`, matching this wrapper's behavior without calling the wrapper.
- 2026-06-10 A001 live MCP recheck reconfirmed `0x004f9060` as the misleadingly named `___std_parallel_algorithms_hw_threads@0_0`, size `0x54`, with no callers and no xrefs to the entry.
- 2026-06-10 `xrefs_to 0x004fdd40` reports exactly two constructor call sites: `0x004f7b49` inside `MainMenuPane::ActivateMenuItem` and `0x004f90a0` inside this retained helper.
- 2026-06-10 `callees 0x004f9060` reports only [UID:000196][0x004f4aa0-0x004f4ab4.OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md) and the `0x004fdd40` `ChangePasswordDialogPane` constructor target.
- 2026-06-10 `lookup_funcs` reconfirmed the sibling launcher boundaries: `0x004f8fa0` size `0xb5`, this helper `0x004f9060` size `0x54`, story helper `0x004f90c0` size `0x7f`, history helper `0x004f9140` size `0x7f`, and terminal helper `0x004f91c0` size `0xbd`.
- 2026-06-10 `xrefs_to 0x004f4aa0` was truncated after confirming 1,785 project-wide code references, matching the [UID:000196][0x004f4aa0-0x004f4ab4.OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md) ownership evidence and confirming this helper is using shared allocation plumbing rather than a feature-local allocator.
- Live IDA MCP on 2026-06-14 rechecked the retained helper: `lookup_funcs` still reports `___std_parallel_algorithms_hw_threads@0_0` at `0x004f9060`, size `0x54`, 84 decimal bytes (Verified with int_convert.py); `xrefs_to 0x004f9060` still reports zero references; `analyze_function` reports no callers and callees limited to `sub_4F4AA0` and `sub_4FDD40`; and `xrefs_to 0x004fdd40` still reports exactly two constructor call sites, `0x004f7b49` in `MainMenuPane::ActivateMenuItem` and `0x004f90a0` inside this retained helper.
- 2026-06-16 C001 live IDA MCP rechecked and then saved the low-risk function label `OpenChangePasswordDialog`. Post-save `lookup_funcs` reports `OpenChangePasswordDialog` at `0x004f9060`, size `0x54`.
- 2026-06-16 `xrefs_to 0x004f9060` still reports zero references, while `xrefs_to 0x004fdd40` still reports exactly two constructor call sites: active main-menu case `0x004f7b49` and this retained helper's `0x004f90a0`.
- 2026-06-16 decompilation of `OpenChangePasswordDialog` still contains only `sub_4F4AA0(620)`, a null check, and successful `sub_4FDD40(result)` construction; decompilation of `sub_4F7A10` case 2 still directly duplicates the same allocation/constructor sequence.
- 2026-06-27 B010 accepted report session `875bf182` and implementation-check session `b001_000241_20260627` confirm the current live IDA name has reverted/remains `___std_parallel_algorithms_hw_threads@0_0` at `0x004f9060`, size `0x54`; this is a misleading label for a password-dialog allocation wrapper, not runtime/library code.
- B010 records `0x54` / 84 byte function size and `0x26c` / 620 allocation size verified with `tools/int_convert.py`, no callers, zero xrefs to `0x004f9060`, zero accepted VA/RVA pointer-byte route, exactly two constructor refs (`0x004f7b49` active case and `0x004f90a0` retained helper), and five `g_pChangePasswordDialogPane` refs at `0x004f69bf`, `0x004fdd96`, `0x004fdd9d`, `0x005023a0`, and `0x00502656`.

## Source Placement

Keep this as a retained private helper in the login/main-menu family for address-matching reconstruction. It belongs with `login/MainMenuPane.cpp` beside other retained launch helpers; the dialog class/file owns the constructed dialog, singleton, validation, submit, packet helpers, and reply handling. A behavior-only source rebuild can rely on the direct action-handler construction path unless later evidence proves this wrapper is reachable.

Under the current strict `85/85` child/parent gate, the route to [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) is now valid. Do not use this retained helper as proof for additional child assignment beyond the current launcher page until a direct callback/source grouping path is proven; the helper remains behavior-strong but reachability-weak.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `88` | The page documents exact behavior, allocation size, constructor target, boundary/padding checks, repeated no-xref checks, raw pointer/immediate searches, active duplicate main-menu path, singleton publication evidence, disassembly-level instruction shape, linked allocator/constructor owners, current sibling-boundary verification, current misleading IDA name correction, valid parent/emitter route, accepted void source shape, and alias/support-only C++ disposition. Completion remains lower than final audit because the reason for retention is unresolved. |
| Confidence `90` | Confidence is very strong for what the helper does, the current misleading-IDB-name correction, and the current unreferenced/duplicate status after the B010 recheck. It is not higher because no live caller or callback table has been found even though the MainMenuPane parent now clears `89/86`. |
| Parent [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) | Exact child [UID:00019Q][0x004f9060-0x004f90b4.OpenChangePasswordDialog](by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md) is now `88/90` and direct parent `89/86` clears the strict `85/85` gate; the nonblank emitter route targets `auto-generated/NexusTK/login/MainMenuPane.cpp`. |

2026-06-16 refresh score update: the misleading IDA name was safely corrected and the current no-entry-xref, duplicate active path, exact constructor-target, and sibling-boundary evidence were all rechecked. The remaining blocker is real: no callback table, raw pointer, or direct caller currently reaches this wrapper, so final helper grouping and final C++ emission remain unresolved.

2026-06-27 B010 implementation raises completion to `88` and keeps confidence `90`. The exact by-memory child now emits first-draft `static void OpenChangePasswordDialog()` C++; this by-global alias stays blank and support-only.

## Cross-References

- [UID:00019Q][0x004f9060-0x004f90b4.OpenChangePasswordDialog](by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md)
- [UID:000196][0x004f4aa0-0x004f4ab4.OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md)
- [UID:0002QA][0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore](by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md)
- [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0000I3][ChangePasswordDialogPane](by-file/ChangePasswordDialogPane.md)
- [UID:00001L][ChangePasswordDialogPane](by-class/ChangePasswordDialogPane.md)

## Changes

- 2026-06-04: Raised completion/confidence from `72/80` to `80/86` after live IDA verified exact boundaries, adjacent padding, no helper-entry xrefs, zero loaded dword hits for `0x004f9060`, constructor xrefs, instruction-level helper shape, and the matching active `MainMenuPane` case `2` construction path.
- Before: the global summary recorded the retained opener behavior but lacked current boundary/padding and raw instruction evidence.
- After: the symbol page now mirrors the stronger by-memory evidence while still keeping final source grouping and C++ emission unresolved.
- Why: live IDA proves the helper's behavior and current unreferenced duplicate status more strongly, but still does not recover a caller or callback table.
- Evidence: 2026-06-04 IDA MCP function lookup, raw bytes, `xrefs_to`, loaded pointer scan, helper disassembly, and `sub_4F7A10` decompile/disassembly.
- 2026-06-02: Raised completion/confidence from `65/65` to `72/80`, marked reconstructable, and attached to [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md). C++ remains blank because this retained launcher is below the final-code gate and live reachability remains unresolved.
- Before: documented as a retained opener with weak unresolved reachability.
- After: documented as a retained duplicate launcher whose lack of current refs has been rechecked; the active main-menu action path is now recorded as directly duplicating the allocation/constructor sequence.
- Why: IDA MCP found no direct or raw-pointer references to `0x004f9060`, while `0x004f7a10` case `2` performs the same `620`-byte allocation and `0x004fdd40` constructor call.
- Evidence: 2026-05-28 IDA MCP `xrefs_to`, `callers`, `find_bytes`, immediate `search`, and `decompile 0x004f7a10`.

### 2026-06-10 A001 linked-helper and strict-gate refresh

- What existed before: score was `80/86`; behavior was documented, but the page still leaned on raw generated names `sub_4F4AA0`, `sub_4F7A10`, and `sub_4FDD40` without linking the stable allocator, active main-menu aggregate, or exact password-dialog core page.
- What changed: score raised to `84/88`, linked the allocator and constructor owner pages, added current MCP evidence, and made the strict `85/85` parent-gate caveat explicit.
- Summary and evidence: live MCP reconfirmed the `0x004f9060` size `0x54` helper has no entry xrefs/callers, calls only the shared [UID:000196][0x004f4aa0-0x004f4ab4.OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md) and the `0x004fdd40` constructor, and shares the constructor target with `MainMenuPane::ActivateMenuItem` at `0x004f7b49`. At that time the parent confidence was still below the strict gate; the 2026-06-14 refresh below records the current valid route and remaining retained-helper reachability caveat.
- 2026-06-14 A003 score refresh:
  - Before: `84/88`; the page still had stale text saying the MainMenuPane parent was below the strict confidence gate.
  - Changed to: `85/89`, retaining [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) as canonical owner/emitter and keeping reconstruction C++ blank.
  - Summary/evidence: live IDA MCP rechecked `0x004f9060`, `0x54` / 84-byte size (Verified with int_convert.py), zero entry xrefs, no callers, allocator/constructor-only callees, and exactly two `ChangePasswordDialogPane` constructor xrefs. Parent [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) now clears `89/86`, so the route is valid; final code remains blocked by unresolved retained-helper reachability and grouping.
- 2026-06-16 C001 Goal 2 refresh:
  - Before: `85/89`; the helper still carried the misleading IDA runtime-like name.
  - Changed to: `86/90`, with owner/emitter unchanged as [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md).
  - Summary/evidence: dry-run rename succeeded and C001 saved `OpenChangePasswordDialog`; post-save lookup reports the expected `0x54` function. Live xrefs still show zero references to `0x004f9060`, exactly two `0x004fdd40` constructor call sites, and the active `sub_4F7A10` case 2 duplicate path. Skipped unsafe edits to prototypes, source grouping, and final C++ because retained-helper reachability remains unresolved.
- 2026-06-27 B010 accepted implementation:
  - Changed to: `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter unchanged as [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md), alias C++ remains blank, and the exact [UID:00019Q][0x004f9060-0x004f90b4.OpenChangePasswordDialog](by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md) child owns the formal first-draft `static void OpenChangePasswordDialog()` body.
  - Summary/evidence: current MCP still reports `___std_parallel_algorithms_hw_threads@0_0`; the function is an exact password-dialog allocation wrapper with no direct xrefs, no accepted VA/RVA pointer route, active duplicate case-2 construction that ignores the pointer, and constructor publication through `g_pChangePasswordDialogPane`. Pointer-return, blank-child-C++, dialog-owner, MemoryMan, runtime/library, no-owner, and generated-only alternatives are rejected.
