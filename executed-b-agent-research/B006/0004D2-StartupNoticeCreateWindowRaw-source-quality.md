** TARGET-REPORT-UID:0004D2 **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# UID0004D2 StartupNoticeCreateWindowRaw Source-Quality Research


## Finalized Report / Current Recommendation
- Current recommendation after implementation callback: UID0004D2 remains reconstructable StartupWindow source code emitted through [UID:0000O5][StartupWindow](by-file/StartupWindow.md), and the accepted callback has been applied. The target now emits source-facing `StartupNoticeCreateWindow`, uses `CS_CLASSDC`, uses `WS_POPUP | WS_CLIPCHILDREN`, and keeps create-window x/y at `CW_USEDEFAULT` unless the desktop rectangle is successfully read.
- Final disposition: exact raw helper child, not a public StartupWindow API and not dead padding. It remains a private/file-local StartupWindow notice helper whose source retention is plausible in a non-function-level-linked object even though no direct start route is currently found.
- Applied action: target metadata is now `COMPLETION:88`, `CONFIDENCE:90`, with `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, and blank optional position preserved. The exact formal C++ block below was inserted into the target. Target/support docs preserve no-IDA-function/no-direct-start-route proof as a confidence cap. The stale support wording and sibling RunUpdateCheck constants were also updated because the same MCP evidence proved the shared stale constants.
- Confidence: high enough for corrected first-draft C++ and metadata improvement; capped below final-audit levels by the absent IDA function object, absent direct code/data/pointer route to `0x005819d0`, and inferred source-facing helper name.

## Supporting Research
- Lifecycle/status notes: this report began as a report-only B006 artifact and passed supervisor Gate 1 for SHA256 `1368EC636B7DD6EEB407F223974EC0D61E0D3CEDB4D8BF0BDE7BCD14812B389D`. The implementation callback is now complete: accepted target/support by-* docs were edited under leases, scoped validators were run, generated `StartupWindow.cpp` refreshed through the validator, and B006 did not run `execute_report`, lifecycle/archive commands, manual report moves, generated-file edits, coverage-report edits, validator-state edits, or supervisor-ledger edits.
- MCP incident context: before supervisor restore, MCP was listener-up but had no usable IDB session. This final report does not rely on that fallback state. Current evidence was redone against restored active session `13191102`.
- Current MCP session: `idb_list` on 2026-07-04 returned one active worker session `13191102` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `11632`, `is_analyzing:false`. `server_health` for `13191102` returned `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- Prior reports used as leads only: executed B010 `0001IO-StartupWindowUpdateCheck-source-quality.md` identified `0x005819d0-0x00581b75` as a raw alternate notice setup helper with no start refs; executed B008 `0000O5-StartupWindow-empty-emitter-family-source-quality.md` created UID0004D2 as an exact child and inserted the current first-draft C++. Those reports were not copied blindly; current MCP revalidated the raw range and found new source-quality corrections in the formal C++ constants.

## Target
- Target UID: `0004D2`.
- Target path: `by-memory/0x005819d0-0x00581b75.StartupNoticeCreateWindowRaw.md`.
- Historical pre-callback source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable` listed UID0004D2 at `86/88`, reconstructable `true`. Current post-callback target/generator state is `COMPLETION:88`, `CONFIDENCE:90`, reconstructable `true`, emitted through [UID:0000O5], with generated `StartupWindow.cpp` refreshed and showing the corrected UID0004D2 body.
- Current supervisor classification: implementation callback complete; awaiting supervisor Gate 2 verification and supervisor-owned execution.
- Current scores and parent state after callback: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank optional position.

## Current Target State
- Existing metadata after callback: target is reconstructable and emitted through StartupWindow at `88/90`.
- Existing owner/emitter/reconstructable state: owner and emitter both point to [UID:0000O5][StartupWindow](by-file/StartupWindow.md). This remains correct because the body uses StartupWindow WndProc, notice strings, class atom, and `this+0x0c` HWND storage.
- Existing C++/emitter state after callback: the formal block emits `static bool StartupNoticeCreateWindow(StartupWindow *startupWindow)` with `CS_CLASSDC`, `WS_POPUP | WS_CLIPCHILDREN`, and `CW_USEDEFAULT` fallback coordinates until desktop rectangle lookup succeeds.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims: `Raw` remains only in the stable by-memory filename/search label, not the source-facing formal helper name. No direct start xrefs or IDA function object exist for `0x005819d0`, so the helper's final original source name and source retention reason remain inferred. The body is source-shaped and valid, so the no-route fact is a confidence cap rather than a no-code blocker.
- Related target/support docs checked: `by-file/StartupWindow.md`, `by-class/StartupWindow.md`, parent [UID:0001IO], raw-helper tracker [UID:0000VI], sibling [UID:0004CS], WndProc [UID:0004CT], asset helper [UID:0004D1], callback [UID:0001IP], pointer data [UID:000288], global atom [UID:0002ZQ], generated `auto-generated/NexusTK/app/StartupWindow.cpp`, generated research tracker and by-memory generated coverage.
- Current artifact/lifecycle status: implementation callback complete, scoped validators recorded below, no `execute_report` run by B006, awaiting supervisor Gate 2 verification and supervisor-owned execution.

## Executive Recommendation
- Best direct owner: [UID:0000O5][StartupWindow](by-file/StartupWindow.md) remains the best source-file owner. The helper consumes only StartupWindow notice-window state: WndProc `0x00581100`, `g_startupWindowClassAtom`, notice class/title pointers, Win32 create/register APIs, and `StartupWindow *` receiver storage at `this+0x0c`.
- Reclassification/split/rename: no range split is needed. The range `0x005819d0-0x00581b75` is exact and followed by eleven `0xcc` bytes. Do not merge it into [UID:0004CS] `RunUpdateCheck`; it is a separate raw source body with no fallthrough from the preceding asset helper. Do not rename/recreate the by-memory file unless the supervisor wants filename cleanup; the formal C++ should use source-facing `StartupNoticeCreateWindow` without the reverse-engineering `Raw` suffix.
- C++ outcome: formal C++ was applied after correction because the target is reconstructable, has a valid emitter route, and has current IDA-backed behavior evidence. The exact formal block in this report is the applied target block.
- Remaining condition: supervisor Gate 2 verification and supervisor-owned `execute_report` if accepted. No further by-* edits are pending from this callback.

## Supervisor Active Recheck
- Triggering instruction: supervisor/user assigned Agent-B006 to produce the report-only UID0004D2 research report with MCP evidence, then later authorized this implementation callback after Gate 1 pass.
- Split repair: not required. B008 already split UID0004D2 into an exact by-memory child. Current MCP reconfirms exact start/end and padding.
- Source-bearing child status: UID0004D2 is the source-bearing child. The accepted repair was applied to that exact child rather than creating another child or moving code to the aggregate.

## Inference Research Guidance Check
- `by-structure.md` gates applied: a reconstructable by-memory item may emit only when ownership, emitter route, score, and source-quality evidence support formal C++. UID0004D2 clears the owner/emitter gate through StartupWindow, but its formal code must represent its own range exactly and must not use decompiler/raw names.
- Existing assumptions treated as uncertain: the prior `StartupNoticeCreateWindowRaw` helper name, `CS_OWNDC`, `WS_POPUP | WS_BORDER | WS_SYSMENU`, and direct `windowRect.left/top` fallback were treated as leads. Current disassembly rejects the constants/fallback and downgrades `Raw` to a historical/documentation suffix.
- Evidence separation: IDA facts are the active session `13191102` function lookup, bytes, instruction list, xrefs, searches, imports, and strings. Documentation evidence is the existing StartupWindow split family. Inference is the source-facing helper name `StartupNoticeCreateWindow`, the source-file placement, and the confidence cap from absent caller/source-route proof.
- Wave2/Wave3: only generated `auto-generated` output and old reports were used as lead material; stale Wave2/Wave3 source was not treated as authority.

## Heuristic / Inference Reanalysis And Validation
- Raw helper liveness: current MCP proves no IDA function object and no direct start xrefs at `0x005819d0`, while `insn_query` proves 135 valid instructions ending in `retn` at `0x00581b74`. This is source-shaped raw code, not padding. The lack of direct route remains a confidence cap because MSVC object linking can retain unreferenced file-local code when function-level dead stripping is not used.
- Range and padding: `get_bytes` proves four `0xcc` bytes at `0x005819cc-0x005819d0`, a `0x1a5` / 421-byte body at `0x005819d0-0x00581b75` (Verified with int_convert.py), and eleven `0xcc` bytes at `0x00581b75-0x00581b80`. No split or range extension is recommended.
- Source-facing name: `StartupNoticeCreateWindowRaw` is accepted as a by-memory path/search label but is not final source style. `StartupNoticeCreateWindow` is the best current source-facing static helper name because sibling helpers use `StartupNoticeLoadAssets`, `StartupNoticeInvalidateButton`, `StartupNoticeSetButtonState`, etc. Original name proof is unavailable, so confidence stays capped.
- Constant correction: instruction `0x005819f5` writes style `0x40` / 64 (Verified with int_convert.py), which maps to Win32 `CS_CLASSDC`, not `CS_OWNDC`. Instructions `0x00581a36` and `0x00581b42` use `0x82000000`, which maps to `WS_POPUP | WS_CLIPCHILDREN`, not `WS_POPUP | WS_BORDER | WS_SYSMENU`. `0x00581b4e` pushes `0x40000` / `WS_EX_APPWINDOW` (Verified with int_convert.py), which the current code already gets right.
- Window positioning: binary initializes `edi` and `[ebp-28]` to `0x80000000` before desktop checks, then only replaces them with `windowRect.left/top` after `GetDesktopWindow()` and `GetWindowRect()` succeed. Therefore formal C++ must keep `int x = CW_USEDEFAULT; int y = CW_USEDEFAULT;` and update those only in the success branch.
- Behavior: the body builds `WNDCLASSEXA`, uses `StartupWindowUpdateCheckWindowProc`, gets module handle and arrow cursor, adjusts a 500 by 430 client rectangle, optionally centers it on the desktop, registers class atom if not cached, creates an app window with the class/title pointer data, stores the HWND at `startupWindow->m_noticeWindow`, and returns success/failure.
- Rejected alternatives: no-code treatment is rejected because source-shaped bytes and existing emitter route support formal C++; public `StartupWindow` method treatment is rejected because there is no caller or member-call route; Browser/ImageLoaders/MiniMap ownership is rejected because this body only creates the startup notice HWND; [UID:0001IO] aggregate emission is rejected because exact children now carry source bodies; raw/decompiler constants are rejected by current instruction operands.
- Unresolved issue: no defensible proof of the original helper name or why the source kept this alternate helper while `RunUpdateCheck` has an inline similar setup path. This limits confidence to `90`, not the behavior itself.

## Evidence Standards Used
- MCP evidence types: `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `insn_query`, `xrefs_to`, `find code_ref`, `find data_ref`, `find immediate`, `find_bytes`, `get_string`, `imports_query`, `decompile`, `callees`, `xref_query`, and `make_signature_for_range`.
- Documentation evidence: current by-* pages for StartupWindow file/class/aggregate/raw-helper tracker and exact child pages; generated `StartupWindow.cpp`; generated research tracker and by-memory coverage; executed B008/B010 reports as historical leads only.
- Evidence strength: exact range, imports, globals, strings, and body behavior are direct binary facts. Source owner and source name are inferences validated by the StartupWindow-local state and sibling naming pattern. The lack of start refs prevents a stronger score.
- Tool limitations: Hex-Rays cannot decompile `0x005819d0` because the IDB has no function object there; the report uses targeted disassembly and raw bytes instead of decompiler output for the target.

## Evidence Checked
- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `idb_list` -> active session `13191102`; `server_health` -> `status:ok`.
  - `lookup_funcs` for `0x005819cc`, `0x005819d0`, `0x00581b75`, `0x00581b80`, `0x00580870`, `0x00581100`, and `0x005818d0`: target start/end are not functions; successor `0x00581b80` is `sub_581B80`; parent/sibling functions remain modeled.
  - `get_bytes` for `0x005819cc`, `0x005819d0` size `421`, and `0x00581b75`: four predecessor `0xcc`, target body bytes, and eleven successor `0xcc`.
  - `insn_query` over `0x005819d0-0x00581b75`: 135 instructions, no function metadata, complete body ending at `0x00581b74`.
  - `xrefs_to` for target start/end and support addresses: zero refs to `0x005819d0` and `0x00581b75`; expected support refs to WndProc, atom, and pointer slots.
  - `find code_ref`, `find data_ref`, `find immediate`, and `find_bytes` for target start: no code/data/immediate/VA/RVA route.
  - `decompile 0x005819d0`: failed, as expected for no IDA function object.
  - `imports_query`: confirmed imported Win32 APIs used by the body.
  - `get_string`: confirmed `"BaramNoticeWnd_Class"` at `0x0062d418` and `"Notice"` at `0x0062d430`.
  - `make_signature_for_range`: unique signature for `0x005819d0-0x00581b75`.
- by-* docs, support docs, old reports, generated reports, and trackers checked:
  - Target `by-memory/0x005819d0-0x00581b75.StartupNoticeCreateWindowRaw.md`.
  - `by-file/StartupWindow.md`, `by-class/StartupWindow.md`, [UID:0001IO] aggregate, [UID:0000VI] raw-helper tracker.
  - Siblings [UID:0004CS], [UID:0004CT], [UID:0004D1], [UID:0001IP].
  - Data/global docs [UID:000288] and [UID:0002ZQ].
  - Generated `auto-generated/NexusTK/app/StartupWindow.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`.
  - Executed reports B008 `0000O5-StartupWindow-empty-emitter-family-source-quality.md` and B010 `0001IO-StartupWindowUpdateCheck-source-quality.md`.
- Negative checks performed: no IDA function object; no decompile; no code/data xrefs to target start; no immediate or byte-pattern route for VA/RVA start; no xrefs to target end; no fallthrough from preceding helper due four `0xcc` bytes and prior `ret`.
- Failed, unavailable, or intentionally skipped checks and why: initial wrapper call used PowerShell automatic variable `$args` and stripped `database`; it produced client-side "database is required" errors and was discarded. Retried with `$toolArgs` and succeeded. No broad callgraph, broad search, IDA DB edits, or validator/lifecycle commands were run.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| D2-001 | UID0004D2 is exact range `0x005819d0-0x00581b75` with four predecessor and eleven successor `0xcc` bytes. | 98 | MCP `get_bytes` id 20; `insn_query` id 21. | Target Status/Evidence; parent [UID:0001IO] covered row; raw-helper tracker. | incorporate | applied: target evidence, parent row, and tracker row now state exact range/padding/body details; validators `000000006404`, `000000006421`, `000000006422` passed. |
| D2-002 | Target has no IDA function object and no Hex-Rays decompile at `0x005819d0`. | 98 | `lookup_funcs` id 19 and `decompile` id 31. | Target Evidence and confidence cap. | incorporate | applied: target, parent, class/file notes, and tracker preserve no-function/no-decompile as confidence cap; validators passed. |
| D2-003 | Target has no direct start route: zero xrefs, code refs, data refs, immediates, or VA/RVA byte-pattern hits to `0x005819d0`. | 96 | `xrefs_to` id 22; `find` ids 24-26; `find_bytes` id 27. | Target no-route proof; support docs. | incorporate | applied: target and support docs now state no direct route/no public API proof; pointer/global/WndProc docs were already-present for direct refs. |
| D2-004 | Body is source-shaped code, not padding/dead bytes: 135 instructions, security-cookie prologue, Win32 calls, two returns, HWND store. | 96 | `insn_query` id 21. | Target Evidence/Behavior. | incorporate | applied: target and support rows describe the 135-instruction source-shaped body and HWND store. |
| D2-005 | `WNDCLASSEXA.style` is `0x40` / `CS_CLASSDC`, not `CS_OWNDC`. | 96 | `0x005819f5` operand; int_convert verified `0x40` / 64. | Target formal C++; sibling [UID:0004CS] formal C++ support sync. | incorporate | applied: target and [UID:0004CS] formal C++ now use `CS_CLASSDC`; generated `StartupWindow.cpp` refreshed during B006 validation and final observed header remains current at command `000000006440`. |
| D2-006 | Window style is `0x82000000` / `WS_POPUP | WS_CLIPCHILDREN`, not `WS_POPUP | WS_BORDER | WS_SYSMENU`. | 96 | `0x00581a36` and `0x00581b42`; int_convert verified `0x82000000`. | Target formal C++; sibling [UID:0004CS] formal C++ support sync. | incorporate | applied: target and [UID:0004CS] formal C++ now use `const DWORD windowStyle = WS_POPUP | WS_CLIPCHILDREN`; generated search found no stale `WS_BORDER`/`WS_SYSMENU` in StartupWindow.cpp. |
| D2-007 | Fallback x/y coordinates remain `CW_USEDEFAULT` until desktop window and rectangle lookup both succeed. | 95 | `insn_query`: initializes `edi` and `[ebp-28]` to `0x80000000`, only assigns rect left/top after `GetWindowRect`. | Target formal C++; sibling [UID:0004CS] already partly correct except style constants. | incorporate | applied: target formal C++ now initializes `x`/`y` to `CW_USEDEFAULT` and assigns `windowRect.left/top` only in the success branch; [UID:0004CS] already had that coordinate shape. |
| D2-008 | Class/title pointer slots and strings are StartupWindow-owned support data, with raw helper refs at `0x005819e1` and `0x00581b47`. | 96 | `xrefs_to` id 22; `get_string` id 28; [UID:000288]. | Target Evidence; [UID:000288] check. | already-present | already-present: [UID:000288] already records both pointer slots, refs `0x005819e1`/`0x00581b47`, string targets, and no-public-API caveat; target evidence was also refreshed. |
| D2-009 | The helper uses WndProc `0x00581100` at `0x005819fc`, and WndProc ownership remains StartupWindow-local. | 96 | `insn_query` id 21; `xrefs_to 0x00581100` id 22. | Target Evidence; [UID:0004CT] check. | incorporate | applied: target and support rows cite `0x005819fc`; [UID:0004CT] was inspected and already states WndProc refs from RunUpdateCheck and raw setup. |
| D2-010 | The helper checks/stores `g_startupWindowClassAtom` at `0x00581af4` and `0x00581b08`; total atom refs remain four. | 96 | `xrefs_to 0x0069bac4` id 22; [UID:0002ZQ]. | Target Evidence; [UID:0002ZQ] check. | incorporate | applied: target and support rows cite atom refs; [UID:0002ZQ] was inspected and already records the raw setup path checks/stores and four total refs. |
| D2-011 | Direct owner/emitter remains [UID:0000O5] StartupWindow; Browser/ImageLoaders/MiniMap/libcurl are dependencies or unrelated. | 92 | Target state, support docs, body dependencies. | Target metadata; by-file/by-class support. | incorporate | applied: target owner/emitter preserved; by-file/by-class notes keep UID0004D2 under StartupWindow and preserve rejected dependency-owner alternatives. |
| D2-012 | Source-facing helper name should drop `Raw` in formal C++ as `StartupNoticeCreateWindow`; filename can remain unless supervisor approves rename cleanup. | 86 | Sibling naming pattern and source-quality rules; no original name proof. | Target formal C++; support notes. | incorporate | applied: target formal C++ and generated output use `StartupNoticeCreateWindow`; by-memory path remains stable and support docs label `Raw` as path/search identity only. |
| D2-013 | Metadata should move from `86/88` to `88/90` after current MCP correction; not higher due no-route/name uncertainty. | 90 | All above evidence and unresolved cap. | Target metadata. | incorporate | applied: target metadata set to `COMPLETION:88`, `CONFIDENCE:90`; owner/reconstructable/emitter/optional position preserved. |
| D2-014 | Pre-callback generated `StartupWindow.cpp` emitted UID0004D2 at command `000000006384`, refreshed `2026-07-04T17:49:11-04:00`, with stale constants; post-callback generated output was refreshed after by-* repair. | 95 | Generated file read-only check and post-callback generated header. | Report generated freshness; supervisor implementation checklist. | incorporate | applied: pre-callback generated state is historical; final observed generated header is command `000000006440`, refreshed `2026-07-04T18:28:15-04:00`, and UID0004D2 emits corrected `StartupNoticeCreateWindow` body with no stale constants. |

## Positive Evidence Summary
- Direct facts supporting the chosen recommendation: exact raw body bytes, valid instruction stream, Win32 notice-window creation behavior, StartupWindow WndProc pointer, StartupWindow class/title pointers, StartupWindow class atom, and `this+0x0c` HWND store all point to a StartupWindow notice helper.
- Corroborating documentation/generated-report evidence: current by-file/class/aggregate docs already place the raw helper family under StartupWindow; generated `StartupWindow.cpp` emits UID0004D2; generated by-memory coverage records it as reconstructable.
- Strongest inference chain: a source-shaped body inside the StartupWindow update-notice split uses only StartupWindow notice state and produces exactly a notice HWND. Even without a direct caller, the best source reconstruction is a private file-local helper retained in the StartupWindow object file. Corrected formal C++ improves exact behavior without changing ownership.

## IDA MCP Facts
- Function/range facts: `lookup_funcs` reports `0x005819d0` and `0x00581b75` as not functions; successor `0x00581b80` is `sub_581B80`, size `0x166`; parent `0x00580870` is `StartupWindow__RunUpdateCheck`, size `0x88d`; WndProc `0x00581100` is size `0x4aa`.
- Data/table/padding facts: `get_bytes` returned `cc cc cc cc` at `0x005819cc-0x005819d0`, the 421-byte target body, and eleven `cc` bytes at `0x00581b75-0x00581b80`.
- Xref facts: zero xrefs to `0x005819d0`; support xrefs include `0x005819fc` -> WndProc, atom refs at `0x00581af4`/`0x00581b08`, class-name pointer ref at `0x005819e1`, and title pointer ref at `0x00581b47`.
- Vtable/global/type facts: not vtable-driven. Global support is `g_startupWindowClassAtom` and class/title pointer data. `get_string` confirms `"BaramNoticeWnd_Class"` and `"Notice"`.
- Negative IDA facts: decompilation fails; code_ref/data_ref/immediate/find_bytes route checks for `0x005819d0` and `0x001819d0` are empty.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005819cc-0x005819d0` | by-memory ignored alignment | Four `0xcc` bytes after [UID:0004D1]. | false/ignored | n/a | n/a | Already documented as padding. |
| `0x005819d0-0x00581b75` | [UID:0004D2] target | Raw StartupWindow notice create/register helper. | true | [UID:0000O5] | recommend `88/90` | Formal C++ repair recommended. |
| `0x00581b75-0x00581b80` | by-memory ignored alignment | Eleven `0xcc` bytes before [UID:0001IP]. | false/ignored | n/a | n/a | Already documented as padding. |
| `0x00580870-0x005810fd` | [UID:0004CS] sibling | `StartupWindow::RunUpdateCheck`; shares the same stale WNDCLASS/window style constants. | true | [UID:0000DZ] | `88/90` | Support sync recommended for constants only. |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005819d0` | zero xrefs | No direct start route; confidence cap. |
| `0x005819fc` | data ref to `0x00581100` | Stores StartupWindow WndProc in `WNDCLASSEXA.lpfnWndProc`. |
| `0x00581af4` / `0x00581b08` | refs to `0x0069bac4` | Checks/stores `g_startupWindowClassAtom`. |
| `0x005819e1` | ref to `0x00670260` | Loads `g_szBaramNoticeWndClass`. |
| `0x00581b47` | ref to `0x00670264` | Loads `g_szNoticeTitle`. |
| `0x00581b53` | call to `CreateWindowExA` | Creates the notice HWND and stores result at `this+0x0c`. |
| `0x00581b80` | data refs from `0x00580c6f` and `0x00580efb` | Successor curl callback child, proving target end boundary. |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion: target, [UID:0001IO], [UID:0000VI], [UID:000288], and [UID:0002ZQ] already record the raw helper role, no-function/no-xref caveat, class/title refs, atom refs, range, and padding.
- Pre-callback stale docs that were repaired: target formal C++ and [UID:0004CS] formal C++ used `CS_OWNDC` and `WS_POPUP | WS_BORDER | WS_SYSMENU`, contradicted by current MCP operands. Target formal also used the `Raw` suffix in source and lost the `CW_USEDEFAULT` fallback branch. The callback updated the target, sibling RunUpdateCheck constants, and directly stale UID0004D2 support rows in file/class/aggregate/tracker docs.
- Generated/coverage report state after callback: `auto-generated/NexusTK/app/StartupWindow.cpp` refreshed during B006 scoped validation and final observed header now records validator command `000000006440` at `2026-07-04T18:28:15-04:00`. It contains UID0004D2 `StartupNoticeCreateWindow`, `CS_CLASSDC`, `WS_POPUP | WS_CLIPCHILDREN`, and `CW_USEDEFAULT`; targeted generated search found no UID0004D2 `StartupNoticeCreateWindowRaw(` formal name and no stale `CS_OWNDC`, `WS_BORDER`, or `WS_SYSMENU` constants.

## Ranked Ownership Analysis

### 1. StartupWindow file [UID:0000O5]
- Evidence for: target lies inside the accepted StartupWindow executable split; uses StartupWindow WndProc, notice class/title data, StartupWindow class atom, Win32 create-window sequence, and stores the result into `StartupWindow *` field `+0x0c`. Sibling docs already route exact raw notice helpers through the file root.
- Evidence against: no direct start refs and no IDA function object. The helper duplicates the window setup shape inside `RunUpdateCheck`, so exact source retention reason is inferred.
- Decision: accepted best owner/emitter. Keep `CANONICAL_OWNER:0000O5` and `EMITTER_UIDS:0000O5`.

### 2. StartupWindow class [UID:0000DZ]
- Evidence for: receiver is a `StartupWindow *`, and the body stores an HWND field. It is semantically class-related.
- Evidence against: body is file-local/static helper shape, not a `thiscall` modeled member. Current sibling pattern keeps many raw notice helpers as static file helpers emitted through the file root, while the class page emits only a route marker.
- Decision: class is support context, not direct canonical owner for this raw helper page.

### 3. Parent aggregate [UID:0001IO]
- Evidence for: physical containing range and current split index.
- Evidence against: [UID:0001IO] is reviewed `RECONSTRUCTABLE:FALSE`, non-emitting split/index page. Routing exact child C++ through it would duplicate or block the accepted child split.
- Decision: support/coverage parent only, not owner/emitter.

### 4. Browser, ImageLoaders, MiniMapVersionManager, libcurl, Win32, or no-owner
- Evidence for: broader StartupWindow source file uses Browser, PCX loaders, minimap manager, libcurl, and Win32 APIs.
- Evidence against: UID0004D2 itself does not implement those dependencies; it only creates a StartupWindow notice HWND. Win32 APIs are external dependencies, not source owners. No-owner fallback is weaker than the direct StartupWindow state evidence.
- Decision: rejected.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: no new file. Keep `NexusTK/app/StartupWindow.cpp`.
- Likely full contents: existing StartupWindow constructor/destructor, RunUpdateCheck, WndProc, notice helpers, curl/string helpers, globals and notice pointer data.
- Candidate related items that belong: UID0004D2 and sibling StartupNotice helpers already belong in this file route.
- Candidate related items rejected: Browser implementation, ImageLoaders PCX implementation, MiniMapVersionManager cache mutation, libcurl internals, Win32 APIs.
- Standalone, narrow, or broad source-file inference: narrow file-local helper in a broad StartupWindow source module.

## Source Placement
- Recommended source file/class/global/module placement: private/static helper in `NexusTK/app/StartupWindow.cpp`, emitted through [UID:0000O5]. The formal source helper name should be `StartupNoticeCreateWindow`, with the by-memory path's `Raw` label treated as historical documentation search text.
- Why this placement fits source-tree and subsystem context: all referenced state is startup notice state, the helper is adjacent to other StartupWindow notice helpers, and `RunUpdateCheck` contains a sibling modeled create-window sequence using the same data.
- Rejected placements and why: class member placement lacks call/prototype proof; [UID:0001IO] aggregate emission duplicates child source; Browser/ImageLoaders/MiniMap/libcurl own dependencies only; a new helper file is unnecessary and unsupported.
- Remaining placement uncertainty: the binary does not prove whether the original developers wrote this as a static helper, an unused member-like helper, or a retained old alternate setup function. Static file helper is the best source shape.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: target is half-open `0x005819d0-0x00581b75`, length `0x1a5` / 421 bytes (Verified with int_convert.py). Predecessor padding `0x005819cc-0x005819d0` is four `0xcc`; successor padding `0x00581b75-0x00581b80` is eleven `0xcc`.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: no new child pages. Keep UID0004D2 exact. Preserve ignored padding rows. Do not merge into [UID:0004D1] or [UID:0001IP].
- Padding/table/data/code distinctions: target is code, not padding. Pointer data and class atom remain separate data/global pages.
- Parent/container impact after callback: [UID:0001IO] and [UID:0000VI] remain non-emitting split/index/tracker pages; their UID0004D2 rows were updated where stale after target repair.

## Negative Evidence Summary
- No IDA function object at `0x005819d0`; no Hex-Rays decompile.
- No direct xrefs to `0x005819d0` and no xrefs to `0x00581b75`.
- `find code_ref`, `find data_ref`, `find immediate`, and `find_bytes` found no route for VA `0x005819d0` or RVA `0x001819d0`.
- No fallthrough from the prior helper because the prior body ends before four `0xcc` bytes.
- No evidence that this is a public `StartupWindow` API. The helper should remain static/private and preserve no-start-route wording.
- No evidence for Browser/ImageLoaders/MiniMap/libcurl ownership; those are dependencies or neighboring source modules.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing names/types/comments: use `StartupNoticeCreateWindow` in formal C++ instead of `StartupNoticeCreateWindowRaw`. Keep `StartupWindow *startupWindow`, `WNDCLASSEXA`, `RECT`, `HWND`, and `DWORD windowStyle`.
- Evidence for each proposed name/type/comment: sibling helper names use `StartupNotice...`; `WNDCLASSEXA` layout is proven by `cbSize=0x30`, `style=0x40`, WndProc pointer, instance, cursor, and class name fields; `this+0x0c` HWND storage matches current StartupWindow field usage.
- Items intentionally left unchanged and why: by-memory filename can remain `StartupNoticeCreateWindowRaw.md` unless supervisor wants a rename; UID is the stable identity. `g_szBaramNoticeWndClass`, `g_szNoticeTitle`, and `g_startupWindowClassAtom` already have support docs and should not be renamed from this target.
- Whether IDA DB edits are safe, unsafe, or not requested: no IDA DB edits requested. The target has no modeled function; this report is documentation-only.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes. The target is reconstructable, has a valid StartupWindow emitter route, and the body is now disassembly-verified.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` header/block insertion text:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static bool StartupNoticeCreateWindow(StartupWindow *startupWindow)
{
    WNDCLASSEXA windowClass = {};
    windowClass.cbSize = sizeof(windowClass);
    windowClass.style = CS_CLASSDC;
    windowClass.lpfnWndProc = StartupWindowUpdateCheckWindowProc;
    windowClass.hInstance = GetModuleHandleW(NULL);
    windowClass.hCursor = LoadCursorA(NULL, IDC_ARROW);
    windowClass.lpszClassName = g_szBaramNoticeWndClass;

    const DWORD windowStyle = WS_POPUP | WS_CLIPCHILDREN;
    RECT windowRect = { 0, 0, 500, 430 };
    AdjustWindowRect(&windowRect, windowStyle, FALSE);

    int x = CW_USEDEFAULT;
    int y = CW_USEDEFAULT;
    HWND desktopWindow = GetDesktopWindow();
    RECT desktopRect;
    if (desktopWindow != NULL && GetWindowRect(desktopWindow, &desktopRect)) {
        OffsetRect(&windowRect,
                   desktopRect.left + (desktopRect.right - desktopRect.left) / 2 - (windowRect.right - windowRect.left) / 2 - windowRect.left,
                   desktopRect.top + (desktopRect.bottom - desktopRect.top) / 2 - (windowRect.bottom - windowRect.top) / 2 - windowRect.top);
        x = windowRect.left;
        y = windowRect.top;
    }

    if (g_startupWindowClassAtom == 0) {
        g_startupWindowClassAtom = RegisterClassExA(&windowClass);
        if (g_startupWindowClassAtom == 0) {
            return false;
        }
    }

    startupWindow->m_noticeWindow = CreateWindowExA(WS_EX_APPWINDOW,
                                                   g_szBaramNoticeWndClass,
                                                   g_szNoticeTitle,
                                                   windowStyle,
                                                   x,
                                                   y,
                                                   windowRect.right - windowRect.left,
                                                   windowRect.bottom - windowRect.top,
                                                   GetDesktopWindow(),
                                                   NULL,
                                                   windowClass.hInstance,
                                                   NULL);
    return startupWindow->m_noticeWindow != NULL;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive, when applicable: not applicable; this is NexusTK source-authored StartupWindow code, not a third-party embed.
- Reason it preserves exact original behavior: matches `CS_CLASSDC`, `WS_POPUP | WS_CLIPCHILDREN`, `CW_USEDEFAULT` fallback, class atom registration failure return, HWND parent from `GetDesktopWindow`, class/title pointer data, and `this+0x0c` storage.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: file-local Win32 helper, direct Win32 structures/APIs, simple `RECT` math, and StartupWindow-local static globals are consistent with the surrounding source style.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `StartupNoticeCreateWindow`, `startupWindow`, `m_noticeWindow`, `g_startupWindowClassAtom`, `g_szBaramNoticeWndClass`, `g_szNoticeTitle`.
- Naming/coding style convention used and evidence for consistency: `StartupNotice...` follows sibling static helpers; `m_noticeWindow` follows existing generated StartupWindow fields. Original spelling remains inferred.
- Reason code should remain blank, if applicable: not applicable.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation
- Exact changes applied: UID0004D2 metadata is `88/90`, owner/emitter/reconstructable state was kept, and the formal C++ was replaced with the block above. Item evidence was refreshed with MCP session `13191102`, exact range/padding, no-route proof, corrected constants, class/title/atom refs, and source-name caveat.
- Exact parent assignments after callback: keep `CANONICAL_OWNER:0000O5`; keep `EMITTER_UIDS:0000O5`.
- Exact items left no-owner/non-emitting and why: none for the target. Parent [UID:0001IO] and tracker [UID:0000VI] remain non-emitting support/index pages.
- Exact future work outside this assignment scope: if the supervisor wants filename cleanup, a later rename could drop `Raw` from the by-memory path, but UID0004D2 was repaired without a path rename. No broader style-constant cleanup remains pending for [UID:0004CS] from this report; that support sync was applied.

## Recommended Target Doc Changes
- Callback application state: applied to `by-memory/0x005819d0-0x00581b75.StartupNoticeCreateWindowRaw.md` and validated by command `000000006404`.
- Target path: `by-memory/0x005819d0-0x00581b75.StartupNoticeCreateWindowRaw.md`.
- Exact report facts incorporated:
  - Current MCP session `13191102`, server health OK.
  - No function object/decompile at `0x005819d0`; exact `0x1a5` / 421-byte body (Verified with int_convert.py), 135 instructions, four predecessor `0xcc`, eleven successor `0xcc`.
  - Zero direct code/data/immediate/VA/RVA route to the target start.
  - WNDCLASS style `0x40` / `CS_CLASSDC`; window style `0x82000000` / `WS_POPUP | WS_CLIPCHILDREN`; `CW_USEDEFAULT` fallback x/y; dimensions `0x1f4` / 500 and `0x1ae` / 430 (Verified with int_convert.py).
  - WndProc `0x00581100` ref at `0x005819fc`; atom refs at `0x00581af4` and `0x00581b08`; class/title pointer refs at `0x005819e1` and `0x00581b47`; `CreateWindowExA` at `0x00581b53`; HWND store at `0x00581b61`.
- Metadata/score/owner/emitter/reconstructable/C++ changes applied: set `COMPLETION:88`, `CONFIDENCE:90`; kept `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank `EMITTER_POSITION_OPTIONAL`; replaced formal C++ with the exact block above.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: previous `Raw` suffix as historical search label only; prior `CS_OWNDC` and border/sysmenu style rejected; no public API proof; no direct route; no Browser/ImageLoaders/MiniMap/libcurl ownership; no aggregate emission.

## Recommended Support Doc Changes
- Callback application state: stale support sync applied to [UID:0004CS], by-file, by-class, parent aggregate, and raw-helper tracker; pointer/global/WndProc support was inspected and already contained the accepted direct-ref evidence.
- Support path: `by-memory/0x00580870-0x005810fd.StartupWindowRunUpdateCheck.md`.
  - Exact report facts incorporated: the same current MCP operands prove `windowClass.style = CS_CLASSDC` and `windowStyle = WS_POPUP | WS_CLIPCHILDREN`; callback replaced the stale `CS_OWNDC` and `WS_POPUP | WS_BORDER | WS_SYSMENU` in its formal C++. All other RunUpdateCheck behavior outside this report remains unchanged.
  - Metadata/link/score/coverage/source-placement changes: no score/owner/emitter change required from this target alone.
- Support path: `by-file/StartupWindow.md`.
  - Exact report facts incorporated: UID0004D2 remains source-ready and its formal C++ is corrected to source-facing `StartupNoticeCreateWindow`, `CS_CLASSDC`, `WS_POPUP | WS_CLIPCHILDREN`, and `CW_USEDEFAULT` fallback; UID0004CS shared the style-constant support defect and was corrected. The no-direct-start-route caveat is preserved.
  - Metadata/link/score/coverage/source-placement changes: no file metadata change required.
- Support path: `by-class/StartupWindow.md`.
  - Exact report facts incorporated: alternate setup helper is still private/static helper support, not a public class method. The method note was repaired with current UID0004D2 evidence.
  - Metadata/link/score/coverage/source-placement changes: no class metadata change required.
- Support path: `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md` and `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md`.
  - Exact report facts incorporated: UID0004D2 row/support text was updated with current MCP session `13191102`, corrected constants, source-facing helper name, and no-route confidence cap.
  - Metadata/link/score/coverage/source-placement changes: keep both pages non-emitting; no parent metadata change.
- Support path: `by-memory/0x00670260-0x00670268.StartupWindowNoticePointerData.md`, `by-global/g_startupWindowClassAtom.md`, and WndProc [UID:0004CT].
  - Exact report facts already present: these docs already contain same-or-greater pointer/atom/WndProc relationship detail; no stale contradiction was found during callback inspection.
  - Metadata/link/score/coverage/source-placement changes: none expected.

## Score And Metadata Recommendation
- Historical pre-callback score/metadata: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank optional position.
- Current post-callback score/metadata: `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter/reconstructable unchanged.
- Score rationale and reason not higher/lower: completion rises because current MCP revalidates exact bytes/range/padding/body and identifies concrete formal C++ fixes. Confidence rises because the constants/fallback are no longer guessed. Scores stay below `91+` because no IDA function object, no direct start route, no original helper name proof, and source retention reason remains inferred.
- Score-improvement attempt: checked function modeling, decompile, bytes, instruction stream, xrefs, code/data/immediate routes, VA/RVA byte patterns, strings, imports, generated output, old reports, and support docs. The direct behavior blockers were resolved; no-route/name blockers remain real and evidence-backed.
- Metadata fields changed or left unchanged: changed only completion/confidence and formal C++; kept owner/emitter/reconstructable/optional position.

## Open Questions With Attempted Resolution
- Is `0x005819d0` reachable? Evidence checked: xrefs, code_ref/data_ref/immediate, VA/RVA byte patterns, predecessor/successor padding, old reports. Resolution: no direct route found. This is a confidence cap, not proof of padding or no-code.
- What was the original helper name? Evidence checked: by-* naming, sibling helper names, generated output, old reports, IDA names. Resolution: original name unavailable; `StartupNoticeCreateWindow` is best source-facing name, while `Raw` should not appear in formal C++.
- Should it be a class method? Evidence checked: calling convention shape, no caller, `ECX` receiver saved to stack, sibling helper pattern. Resolution: static/file-local helper with explicit `StartupWindow *` is safer than member method.
- Should style constants remain as the pre-callback formal C++? Evidence checked: current disassembly operands. Resolution: no; pre-callback formal constants were wrong and have been corrected.
- Should support docs be edited beyond target? Evidence checked: sibling [UID:0004CS] had the same stale constants; file/class/aggregate/tracker support docs were synced where stale. Pointer/global docs already contained same-or-greater detail.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Not applicable. Generated `auto-generated/-ag-*` reports refreshed through scoped validators after accepted by-* edits. No manual `-coverage-report.md` or supervisor-owned tracker edit is requested.

## Follow-Up Actions
- Supervisor actions: perform Gate 2 verification against the accepted report, changed by-* docs, validator results, and generated freshness; if accepted, supervisor runs the owned `execute_report` lifecycle command.
- A-agent actions: none.
- B006 future research actions: none for this callback unless supervisor returns a Gate 2 repair. B006 did not run `execute_report`.

## Confidence
- Recommendation confidence: high for target ownership, exact behavior, constant correction, and formal C++ repair.
- Score confidence: `88/90` is appropriate after current MCP; higher would overstate original name/reachability proof.
- Remaining uncertainty: original source spelling, whether the helper was intentionally unused/alternate in the source file, and whether the by-memory filename should be renamed to drop `Raw`.

## Validator Results
- Scoped file validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`; all exited `0` with `ok: 1`.
- `python .\tools\validator.py --mode file --file by-memory/0x005819d0-0x00581b75.StartupNoticeCreateWindowRaw.md --apply --queue-timeout 240 --wait-generated`
  - `command_id: 000000006404`; `command_timestamp: 2026-07-04T18:14:33-04:00`; exit `0`; `ok: 1`; generated refresh completed.
  - Target score updates applied: `COMPLETION:88`, `CONFIDENCE:90`; `auto-generated/NexusTK/app/StartupWindow.cpp` refreshed as validator-owned output.
- `python .\tools\validator.py --mode file --file by-memory/0x00580870-0x005810fd.StartupWindowRunUpdateCheck.md --apply --queue-timeout 240 --wait-generated`
  - `command_id: 000000006406`; `command_timestamp: 2026-07-04T18:14:50-04:00`; exit `0`; `ok: 1`; generated refresh completed.
- `python .\tools\validator.py --mode file --file by-file/StartupWindow.md --apply --queue-timeout 240 --wait-generated`
  - `command_id: 000000006418`; `command_timestamp: 2026-07-04T18:24:21-04:00`; exit `0`; `ok: 1`; generated refresh completed; `auto-generated/NexusTK/app/StartupWindow.cpp` refreshed as validator-owned output.
- `python .\tools\validator.py --mode file --file by-class/StartupWindow.md --apply --queue-timeout 240 --wait-generated`
  - `command_id: 000000006419`; `command_timestamp: 2026-07-04T18:24:37-04:00`; exit `0`; `ok: 1`; generated refresh completed.
- `python .\tools\validator.py --mode file --file by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md --apply --queue-timeout 240 --wait-generated`
  - `command_id: 000000006421`; `command_timestamp: 2026-07-04T18:24:52-04:00`; exit `0`; `ok: 1`; generated refresh completed.
- `python .\tools\validator.py --mode file --file by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md --apply --queue-timeout 240 --wait-generated`
  - `command_id: 000000006422`; `command_timestamp: 2026-07-04T18:25:08-04:00`; exit `0`; `ok: 1`; generated refresh completed.
- Validator warnings/side effects: project-wide known warnings remained (`autogen_emitter_has_no_code`, `autogen_children_marker_missing`, `autogen_children_fallback_insert`); no target-specific validator errors were reported. Validator-owned generated/state side effects included generated metadata refresh, research tracker/memory coverage refresh, projected stats update, registry rebuild/update, and generated backups; B006 did not edit generated files or validator state manually.
- Generated freshness: `auto-generated/NexusTK/app/StartupWindow.cpp` header now records `validator-command-id: 000000006440`, `validator-refreshed-at: 2026-07-04T18:28:15-04:00`. It contains UID0004D2 `StartupNoticeCreateWindow`, `CS_CLASSDC`, `WS_POPUP | WS_CLIPCHILDREN`, and `CW_USEDEFAULT`; targeted search found no UID0004D2 `StartupNoticeCreateWindowRaw(` formal name and no stale `CS_OWNDC`, `WS_BORDER`, or `WS_SYSMENU` constants.

## Changed Files
- Modified by B006 in the implementation callback:
  - `by-memory/0x005819d0-0x00581b75.StartupNoticeCreateWindowRaw.md`
  - `by-memory/0x00580870-0x005810fd.StartupWindowRunUpdateCheck.md`
  - `by-file/StartupWindow.md`
  - `by-class/StartupWindow.md`
  - `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`
  - `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md`
  - `tools/leaser/Agents/Agent-B006/research/0004D2-StartupNoticeCreateWindowRaw-source-quality.md`
- Inspected and left already-present: `by-memory/0x00670260-0x00670268.StartupWindowNoticePointerData.md`, `by-global/g_startupWindowClassAtom.md`, and `by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md`.
- Validator-owned generated refresh side effects observed: `auto-generated/NexusTK/app/StartupWindow.cpp`, generated coverage/metadata reports, research tracker, projected stats, registry rebuild/update, and validator autogen backups. These were not manually edited by B006.
- Renamed: none.
- Report execution: not run. B006 did not run `execute_report`, dry-run/probing variants, registry lifecycle commands, manual report moves, archive commands, generated/manual coverage edits, validator-state edits, or supervisor-ledger edits.
- Leases:
  - First batch leased and released: `by-memory/0x005819d0-0x00581b75.StartupNoticeCreateWindowRaw.md`, `by-memory/0x00580870-0x005810fd.StartupWindowRunUpdateCheck.md`. A mistaken `release` command failed harmlessly because the leaser command is `unlease`; the correct `unlease` immediately succeeded.
  - Second batch leased and released: `by-file/StartupWindow.md`, `by-class/StartupWindow.md`, `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`, `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md`.
  - Final lease check found no active B006 leases.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation: completed; Gate 1 passed for SHA256 `1368EC636B7DD6EEB407F223974EC0D61E0D3CEDB4D8BF0BDE7BCD14812B389D`.
- [x] Target/support docs to update: target, [UID:0004CS], by-file, by-class, parent aggregate, and raw-helper tracker were edited; pointer/global/WndProc docs were inspected and already-present.
- [x] Current target state and actual evidence checked recorded: MCP session `13191102`, range/padding/body/no-route/support refs documented above.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: rows D2-001 through D2-014 now record callback `applied` or `already-present` proof.
- [x] Metadata/score changes to apply: target set to `COMPLETION:88`, `CONFIDENCE:90`; owner/reconstructable/emitter/position preserved.
- [x] Score-limiting blockers researched to resolution: no-route/name/source-retention blockers retained as confidence caps; stale constants resolved.
- [x] Owner/emitter/reconstructable changes to apply: none; `0000O5` owner/emitter and `RECONSTRUCTABLE:TRUE` preserved.
- [x] Split/rename/new-child changes to apply: no split, rename, or child creation; by-memory filename retained.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: range kept; no IDA DB edits; formal helper name now drops `Raw`.
- [x] First-draft C++ or no-code proof to apply: target formal C++ replaced with exact accepted `StartupNoticeCreateWindow` block.
- [x] Third-party import directive to apply or confirm not applicable: not applicable.
- [x] Exact target/support doc facts incorporated at report-level detail: current MCP `13191102`, no-function/no-route proof, exact padding, constants, imports, strings, refs, source-name caveat, rejected alternatives.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: prior `CS_OWNDC`, border/sysmenu style, direct coordinate fallback, public API route, no-code route, aggregate emission, Browser/ImageLoaders/MiniMap/libcurl ownership.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: generated output used as lead only; no Wave2/Wave3 authority used.
- [x] Open questions to close or document as evidence-backed unresolved: original helper spelling/source retention and no-route state documented as confidence caps.
- [x] Validators to run after callback: scoped validators run for every edited by-* file; command IDs and timestamps listed in `Validator Results`.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: generated `auto-generated/NexusTK/app/StartupWindow.cpp` refreshed by validator and shows UID0004D2 with corrected constants and `StartupNoticeCreateWindow`; no manual coverage/tracker edit.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation: Gate 1 pass SHA256 `1368EC636B7DD6EEB407F223974EC0D61E0D3CEDB4D8BF0BDE7BCD14812B389D`.
- [x] All accepted target/support doc details incorporated at report-level detail: target, [UID:0004CS], by-file, by-class, parent aggregate, and raw-helper tracker updated; pointer/global/WndProc docs already-present.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: D2-001 through D2-014 updated.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: target `88/90`; owner/emitter/reconstructable/optional position preserved; no split/rename; exact formal C++ inserted.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: no-route/no-public-API confidence cap, stale constant rejection, dependency-owner rejection, aggregate/no-code rejection, and `Raw` filename caveat retained.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: original source name and source retention reason remain confidence caps.
- [x] Validators run and results recorded: six scoped validators passed with `ok: 1`; command IDs `000000006404`, `000000006406`, `000000006418`, `000000006419`, `000000006421`, and `000000006422`.
- [x] Generated report refresh completed by validator or explicit manual supervisor-owned coverage/tracker text supplied/confirmed unchanged: generated header now `validator-command-id: 000000006440`, refreshed `2026-07-04T18:28:15-04:00`; no manual coverage/tracker text needed.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000006445","destination_path":"executed-b-agent-research/B006/0004D2-StartupNoticeCreateWindowRaw-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0004D2-StartupNoticeCreateWindowRaw-source-quality.md","timestamp":"2026-07-04T18:53:07-04:00","uid":"0004D2"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
