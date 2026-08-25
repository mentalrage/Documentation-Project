** TARGET-REPORT-UID:0004GR **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# UID0004GR NewUserMiscDialogPane ShowControlHelp Source-Quality Report


## Finalized Report / Current Recommendation
- Current callback disposition: implementation callback complete. [UID:0004GR] `by-memory/0x004fc780-0x004fc9e7.NewUserMiscDialogPaneShowControlHelp.md` has been converted from a reviewed non-emitting exact child into a source-ready `NewUserMiscDialogPane::ShowControlHelp` method body routed through [UID:00009F] `NewUserMiscDialogPane`.
- Final disposition: source-authored virtual help/description handler for `NewUserMiscDialogPane`, not a raw helper, not switch data, not a `CashShopRequest`, `HelpPanes`, `LanguageMan`, `CreateUserDialogs`, or mixed-parent body.
- Applied target state: `COMPLETION:89`, `CONFIDENCE:92`, `CANONICAL_OWNER:00009F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009F`, blank `EMITTER_POSITION_OPTIONAL`, and the first-draft formal C++ below inserted into the target `RECONSTRUCTION_CPP CODE` block.
- Confidence: strong for exact range, vtable reachability, behavior, dependencies, and owner/emitter route. Confidence is capped below final-audit level because the original event type name, exact inherited control-hit-test helper name, and exact coordinate field spelling are inferred rather than recovered from IDA type data.

## Supporting Research
- Historical research assignment: Agent-B004 report-only research for UID0004GR produced this report and did not edit target/support by-* docs, generated files, coverage reports, validator state, report lifecycle files, archives, or supervisor ledgers during the report-only pass.
- Current callback state: supervisor Gate 1 passed for SHA256 `99D39888E93F1389181D4CC6AD00885A69D5833C651C652A7BC232510E0A1FF1`, and Agent-B004 applied the accepted implementation to target/support by-* docs, ran scoped validators, updated this report ledger/checklist, and did not run `execute_report` or any lifecycle/archive command.
- MCP availability: supervisor restored MCP and placed this work in the active wave. Current usable session is `eb7ce28b`.
- Active MCP proof: `idb_list` request id `75` returned one active worker session `eb7ce28b` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_active:true`, `is_analyzing:false`, worker pid `17696`. `server_health` request id `60` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- Historical/stale note: current target/support docs cite MCP session `3a33af0b` from B013's split pass. That evidence was useful for creating the child pages, but the implementation should replace or historicalize current-session wording with the refreshed `eb7ce28b` evidence recorded here.
- Old-report search terms used with `rg`: `0004GR`, `004fc780`, `NewUserMiscDialogPaneShowControlHelp`, `ShowControlHelp`, `004fc9e8`, `0004GS`, and `NewUserMiscDialogPane`. Matching executed reports were B013 `0002Q7-NewUserMiscDialogPaneCoreAndPacketHelpers-source-quality.md`, B010 `0002XL-g_pNewUserMiscDialogPane-source-quality.md`, B001 legacy MEMTOOL `004FB630`, and specialized-control ownership reports. These were treated as leads; current MCP and current by-* docs are the evidence authority.
- Historical generated state checked as read-only input during research: `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` header command `000000005895` emitted only UID0002XL `NewUserMiscDialogPane *g_pNewUserMiscDialogPane;` plus the class empty marker, while generated coverage/tracker listed UID0004GR as non-emitting at `82/89`.
- Current generated freshness after callback validators: `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` header is `validator-command-id: 000000005963`, `validator-refreshed-at: 2026-07-04T00:44:50-04:00`, and lines 194-195 include UID0004GR at `Completion:89 | Confidence:92` with `bool NewUserMiscDialogPane::ShowControlHelp(ControlPaneEvent *event)`. `auto-generated/-ag-memory-coverage.md` now lists UID0004GR as `coded`; `auto-generated/-ag-research-tracker.md` now lists `89/92`, combined `90.5`, reports `0`.

## Target
- Target UID: `0004GR`.
- Target path: `by-memory/0x004fc780-0x004fc9e7.NewUserMiscDialogPaneShowControlHelp.md`.
- Source queue/report row at research start: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`; row was `82/89`, combined `85.5`, reports `0`.
- Current generated tracker row after callback validators: `89/92`, combined `90.5`, reconstructable `true`, reports `0`. Supervisor execution remains pending.
- Current supervisor classification: not-covered reconstructable by-memory item.
- Current scores and parent state: target `89/92`, direct class owner [UID:00009F] `85/88`, source file route [UID:0000LX] `85/87`, parent nested index [UID:0002Q7] `88/91` and non-emitting by design.

## Current Target State
- Pre-callback metadata: `COMPLETION:82`, `CONFIDENCE:89`, `CANONICAL_OWNER:00009F`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Current implemented metadata: `COMPLETION:89`, `CONFIDENCE:92`, `CANONICAL_OWNER:00009F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009F`, blank `EMITTER_POSITION_OPTIONAL`, formal C++ populated.
- Current owner/emitter/reconstructable state: owner is still the correct direct semantic owner, [UID:00009F] `NewUserMiscDialogPane`; the old missing-emitter coverage blocker is resolved.
- Current C++/emitter state: target now emits the formal `NewUserMiscDialogPane::ShowControlHelp(ControlPaneEvent *event)` body from this report.
- Stale assumptions corrected: the target historicalizes the older `3a33af0b` split-session evidence, records current session `eb7ce28b`, exact switch/resource-id behavior, helper/global dependency normalization, the `0x004fc9e7` one-byte `0x90` alignment, and the full 14-dword switch-table extent to `0x004fca20`.
- Related target/support docs checked: [UID:00009F] `by-class/NewUserMiscDialogPane.md`, [UID:0000LX] `by-file/NewUserMiscDialogPane.md`, [UID:0002Q7] parent nested index, [UID:0004GS] switch table page, [UID:0000S9] `g_pSimpleHelpPane`, [UID:0000RC] `g_pLanguageMan`, [UID:00048E] `SimpleHelpPane` constructor, [UID:000228] help-pane singleton close helpers, generated coverage/tracker rows, and current generated C++.
- Current artifact/lifecycle status: this report remains in Agent-B004's `research/` folder for supervisor Gate 2 review/execution. Agent-B004 did not run `execute_report`, dry-run/probing variants, lifecycle/archive commands, registry commands, manual report moves, generated/manual coverage edits, or supervisor-ledger edits. Scoped by-* validators were run only for the implementation callback.

## Heuristic / Inference Reanalysis And Validation
- Source-quality blocker: target was `non-emits` despite an exact modeled function and a class owner. Reanalysis result: the only remaining target blocker was child-level source-body review, not ownership. The body decompiles cleanly, is vtable-reached from `0x0061d488`, has a stable method role, and has a valid class-to-file emitter chain through [UID:00009F] -> [UID:0000LX].
- Helper/source-quality blocker: `sub_49FB10` is not a NewUserMisc-owned helper. MCP decompile request id `71` shows it scans the inherited child-control collection at `this[127]`, tests rectangles through `sub_4B7E80`, ignores hit-disabled controls through `sub_494BF0`, stores the hit child index through the out parameter, and returns a control event/status byte. Best source-facing role in this method is an inherited/descriptive `FindControlAtPoint` or `FindControlAtEventPoint`; exact spelling remains inferred.
- Fallback/source-quality blocker: `sub_49E240` is a broad inherited control/event handler, not a second NewUserMisc method body. MCP decompile request id `72` shows it handles general event types, dragging, hit testing, active-help closure, and dispatch to nested panes. In the UID0004GR source body it is best represented as a base-class fallback when `event->type != 4`.
- Tooltip dependency blocker: `sub_4C6F90` is accepted in [UID:00048E] as `SimpleHelpPane::SimpleHelpPane(const wchar_t *text, Pane *owner, int x, int y, int timeoutMs)`. The target's `sub_4F4AA0(0xfc)` / null-check / call to `sub_4C6F90` is ordinary C++ `new SimpleHelpPane(...)` lowering, not a raw allocation helper to preserve in source.
- Active-tooltip close blocker: `unk_69AE00` is [UID:0000S9] `g_pSimpleHelpPane`. The local inline vtable-slot-zero call with flag `1` matches the accepted pattern in BackPane helpers and HelpPanes singleton close helpers; source should use `g_pSimpleHelpPane->Close(true)` or equivalent helper, not `unk_69AE00`.
- Localization dependency blocker: `dword_67A750` / `sub_4F0350` is [UID:0000RC] `g_pLanguageMan` and exact child [UID:00040P] `LanguageMan::GetLocalizedString`. Source should use a localized string lookup with ids `178..182`, not raw `dword_67A750` or `sub_4F0350`.
- Pre-callback range/split blocker: the switch-table support page range was incomplete. MCP `get_bytes` request id `70` shows the table starts at `0x004fc9e8`, contains 14 dwords, and the last two entries are at `0x004fca18` and `0x004fca1c` before the raw create sender prologue starts at `0x004fca20`. The old `by-memory/0x004fc9e8-0x004fca18...` filename only covered 12 dwords if interpreted end-exclusive. Callback implementation corrected this support page to `0x004fc9e8-0x004fca20`.
- C++ readiness blocker: remaining unknowns are names/types rather than behavior. The method still lacks recovered IDB type/UDT names for `NewUserMiscDialogPane`, the event struct, and the helper name, but the project workflow allows evidence-backed source-facing names when original names are lost. Those uncertainties cap confidence; they do not justify keeping a source-authored virtual handler non-emitting.
- Rejected alternatives validated: no direct code caller is needed because vtable data xref is the correct reachability for a virtual method; switch table data is compiler-generated and not a separate source body; `HelpPanes` and `LanguageMan` are dependencies, not owners; `CreateUserDialogs` is only an umbrella; packet sender/raw helper pages do not own this UI help handler.

## Evidence Standards Used
- Direct IDA/MCP facts: `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, `disasm`, `get_bytes`, `find_bytes`, `make_signature_for_range`, `entity_query`, and `type_query` against session `eb7ce28b`.
- Documentation evidence: target/support by-* docs, exact helper/global pages, current generated C++ and generated coverage/tracker rows, and executed B-agent reports used only as search-gated leads.
- Inference standard: direct binary facts establish boundaries, behavior, reachability, and dependencies; by-* docs establish accepted source-facing names for dependencies; inference supplies source method/event/helper spellings where IDA has no current UDT/type/name evidence.
- Numeric conversion standard: `tools/int_convert.py` verified `0x267 == 615`, `0xfc == 252`, `0x1388 == 5000`, `0xa0 == 160`, and resource ids `0xb2..0xb6 == 178..182` (Verified with `int_convert.py`).
- Confidence cap: IDA type/name queries did not recover exact source names/types, and the coordinate field spelling/order remains inferred from event offsets and `SimpleHelpPane` constructor argument order.

## Evidence Checked
- MCP active-session checks:
  - `idb_list` id `75`: active session `eb7ce28b`, path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker pid `17696`.
  - `server_health` id `60`: `status:ok`, imagebase `0x400000`, Hex-Rays ready.
  - `lookup_funcs` id `61`: `0x004fc780` is `sub_4FC780`, size `0x267`; `0x004fc9e7`, `0x004fc9e8`, `0x004fca18`, and `0x004fca20` are not IDA function starts; sibling modeled starts `0x004fc5f0` and `0x004fc010` remain functions.
  - `xrefs_to` id `62`: `0x004fc780` has one data xref at `0x0061d488`; `0x004fc9e8` has one internal switch xref from `0x004fc7eb`; no xrefs to `0x004fc9e7`, `0x004fca18`, or `0x004fca20`.
  - `callees` id `68`: callees are `sub_49FB10`, `sub_4F4AA0`, `sub_4F0350`, `sub_4C6F90`, and `sub_49E240`.
  - `decompile` id `65`: confirmed event type guard at event `+4`, inherited fallback on non-type-4 events, hit-test helper, active `g_pSimpleHelpPane` close, switch on hit child index, resource ids `178..182`, allocation size `252`, timeout `5000`, and return `1`.
  - `disasm` id `66`: confirmed SEH/security-cookie compiler prologue, `cmp byte ptr [eax+4], 4`, `lea esi,[ecx-0xa0]`, `call sub_49FB10`, `jmp ds:jpt_4FC7EB[eax*4]`, case labels, pushes for `0xfc`, `0x1388`, resource ids `0xb2..0xb6`, tail `retn 4`, and EH cleanup fragment at `0x006019fe` calling `sub_4F4AC0(Block)`.
  - `get_bytes` id `70`: confirmed function entry bytes, tail/NOP/table bytes, table dwords through `0x004fca1c`, and raw create helper prologue at `0x004fca20`.
  - `find_bytes` id `59`: VA pointer pattern for target start `80 C7 4F 00` appears only at `0x0061d488` vtable slot; RVA target-start pattern has no hits; target end `0x004fc9e7` and RVA end have no hits; switch table VA pattern `E8 C9 4F 00` appears at internal operand `0x004fc7ee`; switch end `0x004fca18` patterns have no hits.
  - `make_signature_for_range` id `67`: unique IDA-format signature for `0x004fc780-0x004fc9e7`, beginning `55 8B EC 6A FF 68 8D 1A 60 00 ...`.
  - `decompile` id `71`: `sub_49FB10` scans child controls, writes the hit child index to the out parameter, and returns a control event/status byte.
  - `decompile` id `72`: `sub_49E240` is a broad inherited event handler/fallback.
  - `entity_query` id `73`: bounded name query for `NewUserMisc|ShowControl|ControlHelp|Help` in `0x004fb000-0x00503000` returned zero IDB names.
  - `type_query` id `74`: filters `*NewUserMiscDialogPane*`, `*ControlHelp*`, and `*Help*` returned zero IDB types.
- Local docs checked: target, [UID:00009F], [UID:0000LX], [UID:0002Q7], [UID:0004GS], [UID:00048E], [UID:0000D6], [UID:0000RC], [UID:0000S9], [UID:000228].
- Negative checks performed: no direct code xref to target start, no xrefs to target exclusive end, no xrefs to successor raw start, no target-start RVA pointer hit, no target-end VA/RVA pointer hit, no IDB UDT/name for exact class/event/helper symbols, no evidence that the local switch table is source-authored code, and no evidence that helper/global dependencies own the method.
- Failed or corrected checks: `callees` request id `63` used obsolete singular `addr` schema and returned a schema error; retried with current `addrs` schema as id `68`. `get_bytes` request id `64` used obsolete `ranges/start` fields and returned a schema error; retried with current `regions/addr` fields as id `70`. These are schema-correction notes, not MCP instability.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| GR-001 | UID0004GR is an exact modeled `sub_4FC780` function, size `0x267` / 615 bytes (Verified with `int_convert.py`), representing `NewUserMiscDialogPane::ShowControlHelp`. | 94 | MCP `lookup_funcs` id `61`; current target/class docs. | Target `Status`/`Current MCP Evidence`; class method row; file proposed contents row; parent child inventory. | incorporate | applied: target summary/evidence updated, class/file/parent rows updated, validators `000000005955` and `000000005963` passed. |
| GR-002 | Target reachability is vtable/data xref `0x0061d488`, not a direct code caller; this is normal virtual-method reachability. | 93 | MCP `xrefs_to` id `62`; pointer pattern id `59`. | Target current MCP/negative evidence; class method row. | incorporate | applied: target records vtable-only route and pointer-pattern negatives; class row records slot `0x0061d488`. |
| GR-003 | The target should emit through direct class owner [UID:00009F], while [UID:0000LX] remains the file route. | 91 | Current target owner, class/file docs, B013 split, valid class emitter chain. | Target metadata; class/file source-route notes. | incorporate | applied: target `EMITTER_UIDS:00009F`; class formal comment and file status/proposed contents name UID0004GR as emitted through [UID:00009F]. |
| GR-004 | Event type `+4 != 4` falls back to inherited/base event handling through `sub_49E240`; type `4` is the help/description path. | 90 | MCP decompile id `65`; helper decompile id `72`. | Target behavior evidence and formal C++. | incorporate | applied: target C++ uses `event->type != 4` fallback; behavior section records `sub_49E240`. |
| GR-005 | `sub_49FB10` is an inherited child-control hit-test helper that stores the hit child index; source should use a descriptive inherited helper name, not raw `sub_49FB10`. | 88 | MCP decompile id `71`; target decompile id `65`. | Target behavior/source-quality notes and formal C++. | incorporate | applied: target behavior explains `sub_49FB10`; C++ uses inferred `FindControlAtPoint`; confidence cap recorded. |
| GR-006 | Active simple help popup closure uses [UID:0000S9] `g_pSimpleHelpPane`; source should use `g_pSimpleHelpPane->Close(true)` or equivalent, not `unk_69AE00`. | 92 | MCP disasm/decompile ids `65`/`66`; `g_pSimpleHelpPane` and close-helper docs. | Target behavior/formal C++; dependency docs. | incorporate | applied: target C++ and behavior use `g_pSimpleHelpPane->Close(true)`; dependency proof already-present in `by-global/g_pSimpleHelpPane.md` lines 10, 27, 33 and close-helper page lines 47, 54. |
| GR-007 | New popup creation is ordinary `new SimpleHelpPane(...)`, with allocation size `0xfc` / 252 bytes and timeout `0x1388` / 5000 ms (Verified with `int_convert.py`). | 92 | MCP disasm/decompile ids `65`/`66`; [UID:00048E] constructor docs. | Target behavior/formal C++; generated output. | incorporate | applied: target C++ creates `new SimpleHelpPane(...)`; behavior records size/timeout; generated C++ command `000000005963` includes the method body. |
| GR-008 | Localized string ids map by control-index groups: default/cases 9,10 -> `178`; cases 3,4 -> `179`; 5,6,7,8 -> `180`; 11,12 -> `181`; 13,14,15,16 -> `182` (Verified with `int_convert.py`). | 91 | MCP decompile id `65`; disasm id `66`; int_convert. | Target behavior/formal C++; class/file/parent support notes. | incorporate | applied: target C++ and behavior preserve exact ids/cases; class/file/parent rows summarize ids `178..182`. |
| GR-009 | `dword_67A750` / `sub_4F0350` is [UID:0000RC] `g_pLanguageMan` / localized string lookup dependency, not target ownership. | 92 | Current LanguageMan docs; MCP decompile refs. | Target dependency note; LanguageMan docs. | incorporate | applied: target uses `g_pLanguageMan->GetLocalizedString`; dependency proof already-present in `by-global/g_pLanguageMan.md` lines 24, 31 and `by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md` lines 10, 31, 35. |
| GR-010 | The `0x004fc9e7` byte is a one-byte `0x90` alignment gap after function return and before the switch table. | 90 | MCP `get_bytes` id `70`; `lookup_funcs` end-exclusive id `61`. | Target range/split note; parent inventory; switch-table notes. | incorporate | applied: target summary/range notes, parent row/change note, and switch-table source-quality notes record the one-byte `0x90` alignment. |
| GR-011 | The switch table is 14 dwords from `0x004fc9e8` to `0x004fca20` exclusive, not only `0x004fc9e8-0x004fca18` if end-exclusive. | 93 | MCP `disasm` id `66`; `get_bytes` id `70`; internal xref id `62`. | Switch-table page rename/range correction; parent inventory. | incorporate | applied: UID0004GS moved to `by-memory/0x004fc9e8-0x004fca20.NewUserMiscDialogPaneHelpSwitchTable.md`; validator `000000005958` recorded `path_update`. |
| GR-012 | The switch table is compiler-generated data for UID0004GR, not a source-authored helper body. | 94 | MCP xref/table/disasm ids `62`, `66`, `70`; current [UID:0004GS] docs. | Switch-table support page; target split note. | incorporate | applied: switch-table page stays `RECONSTRUCTABLE:FALSE`, blank emitter/C++, and states no source body; target range notes reject source merge. |
| GR-013 | `sub_4F4AA0`, SEH setup, security-cookie logic, local `Block` cleanup at `0x006019fe`, and raw allocator/null-check details are compiler/runtime lowering and should not appear as explicit source helper calls. | 89 | MCP disasm/decompile ids `65`/`66`; SimpleHelpPane constructor docs. | Target rejected alternatives and C++ rationale. | incorporate | applied: target range/compiler-lowering notes and C++ body exclude allocator/SEH/security-cookie details. |
| GR-014 | Current IDB lacks recovered names/types for `NewUserMiscDialogPane`, `ControlHelpEvent`, and the exact helper; use inferred source-facing names and cap confidence. | 88 | MCP `entity_query` id `73`, `type_query` id `74`. | Target confidence caps; score rationale; IDA rename/type section. | incorporate | applied: target confidence caps and score rationale record inferred `ControlPaneEvent`/`FindControlAtPoint`; no IDA DB edits requested or made. |
| GR-015 | Reject moving ownership to `HelpPanes`, `LanguageMan`, `CashShopRequest`, `CreateUserDialogs`, `NewUserDialogPane`, specialized controls, or UID0002Q7 parent. | 91 | Dependency direction, class/file docs, B013 split report/current docs, MCP callees. | Target rejected alternatives; class/file/parent source-placement notes. | incorporate | applied: target rejected alternatives list all rejected owners; class/file/parent keep [UID:00009F]/[UID:0000LX] route and parent non-emitting. |
| GR-016 | Recommended score is `COMPLETION:89`, `CONFIDENCE:92`, not `95+`, because behavior is source-ready but event/helper/type exact spellings remain inferred. | 90 | Score blocker audit, current evidence, IDA negative type/name checks. | Target metadata and score rationale. | incorporate | applied: target metadata is `89/92`; score rationale records the cap. |
| GR-017 | Formal C++ should be inserted into the target block as the exact first-draft body in this report, using source-facing names and preserving switch/resource behavior. | 89 | MCP decompile/disasm, helper/global docs, BackPane/HelpPanes accepted source patterns. | Target `RECONSTRUCTION_CPP CODE`; generated C++ output. | incorporate | applied: target formal block contains the exact body; generated C++ command `000000005963` includes UID0004GR lines 194-195. |
| GR-018 | Generated output previously lacked UID0004GR; after implementation validators should refresh/check `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` for the method body. | 89 | Historical generated C++ header command `000000005895`; generated coverage row `non-emits`; validator outputs. | Validator/generation notes and checklist. | incorporate | applied: generated header is `validator-command-id: 000000005963`, refreshed `2026-07-04T00:44:50-04:00`, and now includes UID0004GR method body; coverage row now says `coded`. |

## Positive Evidence Summary
- Exact function evidence: `lookup_funcs` maps `0x004fc780` to one modeled function `sub_4FC780`, size `0x267`; the target page range matches the modeled function body end-exclusive.
- Reachability evidence: one data xref at `0x0061d488` points to the target, matching virtual method dispatch for this class. Lack of direct callers is not a raw/no-route blocker for a vtable slot.
- Behavior evidence: decompile and bounded disassembly agree on the event type guard, inherited fallback, child-control hit test, active tooltip close, switch-index groups, localized string ids, `SimpleHelpPane` construction, timeout, and handled return.
- Dependency evidence: accepted by-* docs already identify `g_pSimpleHelpPane`, `SimpleHelpPane::SimpleHelpPane`, `g_pLanguageMan`, and the helper-close pattern used by sibling tooltip code.
- Source-placement evidence: [UID:00009F] owns this method in its method table, [UID:0000LX] is the valid source file route, and parent [UID:0002Q7] is already a non-emitting nested index whose child pages carry exact source bodies.
- Strongest inference chain: target is a vtable-reached class method; its behavior is exact enough for formal C++; dependency names are already accepted elsewhere; unresolved exact event/helper spellings are normal source-polish caveats, not emit blockers.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004fc5f0-0x004fc77c` | [UID:0004GQ] `NewUserMiscDialogPaneOnKeyDown` | sibling virtual key/help path | true | [UID:00009F] | `82/89` | sibling context only |
| `0x004fc780-0x004fc9e7` | [UID:0004GR] target | `NewUserMiscDialogPane::ShowControlHelp` | true | [UID:00009F] | current `82/89`, recommend `89/92` | source-ready exact method |
| `0x004fc9e7-0x004fc9e8` | no exact page currently | one-byte `0x90` alignment after function return | false | compiler alignment | not scored | recommend documenting in target/support; no source body |
| `0x004fc9e8-0x004fca20` | [UID:0004GS], current filename stops at `0x004fca18` | 14-dword switch table for UID0004GR | false | [UID:00009F] / UID0004GR compiler output | `90/92` | support range should be corrected to full end-exclusive extent |
| `0x004fca20-0x004fcab8` | [UID:0004GT] raw create request sender | raw no-function packet sender island | true, no-route | [UID:00009F] | separate child | successor; not part of UID0004GR |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0061d488 -> 0x004fc780` | data xref | virtual dispatch/vtable reachability for target method |
| `0x004fc7eb -> 0x004fc9e8` | internal table operand | switch statement in UID0004GR references local jump table |
| `0x004fc7c7 -> 0x0049fb10` | callee | inherited control hit-test/index helper |
| `0x004fc7cc` / `0x004fc7da` | `g_pSimpleHelpPane` read and first-vtable-slot call with flag `1` | close active simple help popup before showing replacement |
| `0x004fc9a3` / `0x004fc9a9` | `g_pLanguageMan` and localized string lookup | resource ids `178..182` provide help text |
| `0x004fc9b2 -> 0x004c6f90` | `SimpleHelpPane` constructor | creates the timed help pane |
| `0x004fc9ce -> 0x0049e240` | fallback call | inherited/base event handling for non-type-4 events |
| `0x006019fe -> 0x004f4ac0` | EH cleanup fragment | compiler cleanup for allocated block, not source logic |

## Documentation Evidence And IDA Status
- Target doc correctly identifies the method as `ShowControlHelp`, owner [UID:00009F], reconstructable true, and the following switch table. It is stale/incomplete because it keeps blank emitter/C++ and only cites old session `3a33af0b`.
- [UID:00009F] method row already lists `ShowControlHelp` as the help/description display handler. It should be raised from a role-only row to source-ready method notes with the `g_pSimpleHelpPane`, `g_pLanguageMan`, `SimpleHelpPane`, event type `4`, and switch id facts.
- [UID:0000LX] proposed contents already included UID0004GR before the callback but generated output then contained only UID0002XL and the empty class marker. The implementation callback updated the file route so generated output now includes UID0004GR as an exact child method body through the class route.
- [UID:0002Q7] already says exact child pages carry future source-body work. It should update UID0004GR from candidate to source-ready and correct the switch-table range/end.
- [UID:0004GS] correctly classifies the switch table as compiler-generated data, and the implementation callback corrected its filename/range from `0x004fc9e8-0x004fca18` to the full 14-dword `0x004fc9e8-0x004fca20` exclusive extent.
- Generated `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` previously had command id `000000005895` and contained no UID0004GR method body. After callback validation it has command id `000000005963`, refreshed `2026-07-04T00:44:50-04:00`, and includes UID0004GR at lines 194-195.

## Ranked Ownership Analysis

### 1. [UID:00009F] NewUserMiscDialogPane
- Evidence for: target is already owned by [UID:00009F]; class method table lists `ShowControlHelp`; the method is vtable-reached through `0x0061d488`; surrounding exact children are all NewUserMiscDialogPane methods/raw islands; `this` is adjusted by `0xa0` to the full pane object before child-control hit testing; source file route [UID:0000LX] is valid.
- Evidence against: no recovered IDB class/type name for the exact method signature, and exact event/helper names are inferred. These are confidence caps only.
- Decision: best and sufficient direct owner/emitter. Set `EMITTER_UIDS:00009F`.

### 2. [UID:0000LX] NewUserMiscDialogPane source file
- Evidence for: valid `NexusTK/login/` file route, source family owns the class, generated output already routes the singleton declaration through this file.
- Evidence against: direct method bodies should attach to the class, not directly to the by-file page, so file ownership alone is too broad as canonical owner for this method.
- Decision: keep as source route through the class emitter chain, not direct target owner.

### 3. [UID:0000JU] HelpPanes / [UID:0000S9] g_pSimpleHelpPane / SimpleHelpPane
- Evidence for: method closes an active simple help pane and constructs a new `SimpleHelpPane`.
- Evidence against: these are tooltip dependencies; no target storage, receiver, vtable slot, or method body belongs to HelpPanes. The caller owns when and what help text to show.
- Decision: reject as owner; retain as dependency/support refs.

### 4. [UID:0000KK]/[UID:0000RC] LanguageMan
- Evidence for: method uses `g_pLanguageMan` string lookup for resource ids `178..182`.
- Evidence against: localization is a read-only dependency used by many callers; it does not own UI help behavior.
- Decision: reject as owner; retain as dependency.

### 5. CreateUserDialogs / NewUserDialogPane / CashShopRequest / specialized controls / UID0002Q7 parent
- Evidence for: source-family/caller/neighbor context exists around create-user UI and packet helpers.
- Evidence against: none are the direct receiver/vtable owner for this method. UID0002Q7 is explicitly a non-emitting index. Packet helpers and specialized controls are separate dependencies or consumer-side setup.
- Decision: reject as owner/emitter.

## Source Placement
- Recommended source file/class placement: `NewUserMiscDialogPane::ShowControlHelp` as a class method under [UID:00009F], routed through [UID:0000LX] `NexusTK/login/NewUserMiscDialogPane.cpp`.
- Why placement fits: the method is in the contiguous NewUserMiscDialogPane exact-child run, is vtable-reached through the class vtable data, uses the dialog's inherited child-control collection, and chooses help text for this dialog's controls.
- Rejected placements: `HelpPanes` owns the popup implementation, not this caller; `LanguageMan` owns localization; `CashShopRequest` owns packet queue behavior; `CreateUserDialogs` is an umbrella; `NewUserDialogPane` is a neighboring/caller dialog; the mixed aggregate and UID0002Q7 parent must remain non-emitting indices.
- Remaining placement uncertainty: final project may later fold `NewUserMiscDialogPane.cpp` into `CreateUserDialogs.cpp`, but current by-file route remains [UID:0000LX]. That possible source-file fold does not block class-level method emission through [UID:00009F].

## Range / Split / Padding / Reclassification Analysis
- Exact range facts: `lookup_funcs` id `61` reports `0x004fc780` size `0x267`, so the modeled function is `0x004fc780-0x004fc9e7` exclusive. `get_bytes` id `70` shows a one-byte `0x90` at `0x004fc9e7` before the switch table starts.
- Target range disposition: keep UID0004GR range as-is for the function body. Add evidence that the exclusive-end byte after the function is alignment/padding, not source-authored method code.
- Switch table facts: disassembly id `66` reports a 14-case switch and table operand `jpt_4FC7EB` at `0x004fc9e8`; bytes id `70` show 14 dwords:
  - `0x004fc7f2`, `0x004fc823`, `0x004fc83c`, `0x004fc86d`, `0x004fc886`, `0x004fc89f`, `0x004fc97b`, `0x004fc97b`, `0x004fc8b8`, `0x004fc8e9`, `0x004fc902`, `0x004fc930`, `0x004fc949`, `0x004fc962`.
- Support split correction applied: [UID:0004GS] was renamed/corrected to `by-memory/0x004fc9e8-0x004fca20.NewUserMiscDialogPaneHelpSwitchTable.md`, because `0x004fca18` and `0x004fca1c` are table entries and `0x004fca20` begins the successor raw create request sender.
- Reclassification: UID0004GR stays reconstructable source-authored code; UID0004GS stays `RECONSTRUCTABLE:FALSE` compiler-generated switch data; the one-byte `0x90` at `0x004fc9e7` should be treated as alignment/padding.

## Negative Evidence Summary
- No direct code xref to `0x004fc780`; only vtable/data xref `0x0061d488`. This rejects a free raw-helper route and supports virtual method dispatch.
- No xrefs to `0x004fc9e7`, the modeled exclusive end; no pointer-pattern hits to the end VA/RVA.
- No xrefs to `0x004fca20` successor raw helper start in the current `xrefs_to` set; do not merge UID0004GR with raw packet sender pages.
- No IDB names from bounded `entity_query` for `NewUserMisc`, `ShowControl`, `ControlHelp`, or `Help` in the local range; source-facing method/helper/type names remain inferred.
- No IDB types from bounded `type_query` for `NewUserMiscDialogPane`, `ControlHelp`, or `Help`; final event type and helper declaration spelling remain confidence caps.
- No evidence that `sub_4F4AA0`, `sub_4F4AC0`, SEH records, or security-cookie code are handwritten source; they are allocation/compiler cleanup lowering.
- No evidence that `HelpPanes`, `LanguageMan`, `CashShopRequest`, `CreateUserDialogs`, `NewUserDialogPane`, specialized controls, or parent UID0002Q7 own this method body.
- No evidence that the local switch table is source-authored code; it is compiler-generated data for the target switch.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing names/types/comments:
  - `NewUserMiscDialogPane::ShowControlHelp`: strong descriptive method name, already used by target/class/support docs and supported by vtable reachability plus behavior.
  - `ControlPaneEvent` or equivalent event type with fields `type`, `x`, and `y`: inferred descriptive type for the event pointer; binary offsets are `+4`, `+8`, `+12`.
  - `FindControlAtPoint` / `FindControlAtEventPoint`: inferred inherited helper role for `sub_49FB10`, which scans child controls, tests rectangles, skips ignored controls, and writes the hit child index.
  - `controlIndex`, `stringId`, `mouseX`, `mouseY`: source-facing locals replacing decompiler `a2`, `v2`, `v4`, `Block`, and temporary labels.
  - `g_pSimpleHelpPane`, `SimpleHelpPane`, `g_pLanguageMan`, `GetLocalizedString`: already accepted source-facing names/types in support docs.
- Evidence for each name/type/comment: MCP decompiles/disasm ids `65`, `66`, `71`, and `72`; target/class/file docs; SimpleHelpPane constructor and g_pSimpleHelpPane/g_pLanguageMan support docs; local BackPane accepted tooltip C++ patterns.
- Items intentionally left unchanged:
  - Do not claim recovered original spellings for `ShowControlHelp`, `ControlPaneEvent`, or `FindControlAtPoint`; IDA name/type queries returned no proof.
  - Do not rename raw IDA labels in the IDB from this report/callback; IDA DB edits were not requested by the supervisor.
  - Do not create a source enum for the control-index groups yet; resource ids and case groups are known, but original enum names are not.
  - Do not rename/merge UID0004GS as code; it remains switch data. Range correction is recommended, not source-body promotion.
- Whether IDA DB edits are safe: not requested in the report-only assignment or implementation callback. Any future IDA labels should be supervisor/C-agent controlled; by-* documentation can use source-facing inferred names without changing IDA.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes. The target is reconstructable, has a valid direct owner/emitter route, current combined recommended score is above the active code-entry gate, behavior is exact, and remaining unknowns are naming/type polish rather than behavior/route blockers.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` insertion text for UID0004GR:

```cpp
bool NewUserMiscDialogPane::ShowControlHelp(ControlPaneEvent *event)
{
    if (event->type != 4)
        return ControlPane::ShowControlHelp(event);

    int controlIndex = -1;
    const int mouseY = event->y;
    const int mouseX = event->x;

    FindControlAtPoint(mouseY, mouseX, &controlIndex);

    if (g_pSimpleHelpPane != NULL)
        g_pSimpleHelpPane->Close(true);

    int stringId = 178;
    switch (controlIndex)
    {
    case 3:
    case 4:
        stringId = 179;
        break;

    case 5:
    case 6:
    case 7:
    case 8:
        stringId = 180;
        break;

    case 11:
    case 12:
        stringId = 181;
        break;

    case 13:
    case 14:
    case 15:
    case 16:
        stringId = 182;
        break;

    default:
        stringId = 178;
        break;
    }

    new SimpleHelpPane(g_pLanguageMan->GetLocalizedString(stringId),
                       this,
                       mouseX,
                       mouseY,
                       5000);

    return true;
}
```

- Reason it preserves exact original behavior: the draft preserves the type-4 guard and inherited fallback, the child-control hit-test/output-index route, active popup closure, exact case groups, exact resource ids `178..182`, `SimpleHelpPane` construction, and timeout `5000`. It intentionally represents allocator/null-check/SEH cleanup as ordinary `new SimpleHelpPane(...)`, matching accepted SimpleHelpPane/BackPane reconstruction style.
- Reason it matches plausible original mid-2000s source shape: it is an ordinary virtual UI method, uses class/global/helper names already accepted in the project, uses a simple switch rather than a hand-written jump table, and avoids decompiler temporaries, raw labels, manual vtable calls, and explicit allocator cleanup.
- Inferred source-facing names/types/fields used: `ControlPaneEvent`, `FindControlAtPoint`, `controlIndex`, `mouseX`, `mouseY`, and `stringId` are inferred/descriptive. `g_pSimpleHelpPane`, `SimpleHelpPane`, and `g_pLanguageMan` are accepted support names.
- Naming/coding style convention used: existing generated/project C++ uses direct class methods, simple `if` guards, `NULL` checks in older-style source, and explicit singleton globals. The draft follows the accepted BackPane tooltip helper pattern for `g_pSimpleHelpPane->Close(true)` and `new SimpleHelpPane(...)`.
- Reason code should not remain blank: current non-emitting state is stale after this evidence pass. The target has a source method, a vtable route, a direct owner/emitter, exact behavior, and dependency names with accepted support docs.
- Confidence caveat: if later class/header work proves the event type or helper has a different exact source spelling, preserve the behavior and case mapping while updating the names. This is a polish cap, not a blocker.

## Final Recommendation
- Exact changes applied: UID0004GR is now `89/92`, has `EMITTER_UIDS:00009F`, contains the formal C++ above, and replaces the old brief `3a33af0b` current-state note with report-level `eb7ce28b` evidence.
- Exact parent assignments recommended: keep `CANONICAL_OWNER:00009F`; route output through class [UID:00009F] to file [UID:0000LX]. Keep parent [UID:0002Q7] non-emitting.
- Exact items left non-emitting and why: UID0004GS switch table remains `RECONSTRUCTABLE:FALSE` compiler-generated data; UID0002Q7 remains a non-emitting nested index; the one-byte `0x90` at `0x004fc9e7` is alignment.
- Exact future work outside this assignment: final header/class declaration pass should settle the exact event type name, inherited helper declaration, and coordinate field names. That should not block applying the target C++ now.

## Recommended Target Doc Changes
- Target path: `by-memory/0x004fc780-0x004fc9e7.NewUserMiscDialogPaneShowControlHelp.md`.
- Metadata/score changes:
  - `COMPLETION:89`
  - `CONFIDENCE:92`
  - keep `CANONICAL_OWNER:00009F`
  - keep `RECONSTRUCTABLE:TRUE`
  - set `EMITTER_UIDS:00009F`
  - keep blank `EMITTER_POSITION_OPTIONAL`
- Formal C++ change: insert the exact `NewUserMiscDialogPane::ShowControlHelp(ControlPaneEvent *event)` body from `## First-Draft C++ Recommendation`.
- Exact report facts to incorporate:
  - MCP session `eb7ce28b`, `server_health` ok, active IDB path.
  - `lookup_funcs 0x004fc780` -> `sub_4FC780`, size `0x267`; `0x004fc9e7`, `0x004fc9e8`, `0x004fca18`, `0x004fca20` not function starts.
  - vtable/data xref `0x0061d488`; no xrefs to exclusive end/successor; target-start VA pattern only at vtable slot; no target-start RVA/end pointer hits.
  - event `+4` type guard for `4`; fallback to inherited `sub_49E240`; hit test through `sub_49FB10`; full-object adjustment by `0xa0` / 160 bytes (Verified with `int_convert.py`).
  - active `g_pSimpleHelpPane` close; `g_pLanguageMan` lookups for string ids `178..182`; `SimpleHelpPane` allocation/constructor with size `252` and timeout `5000` (Verified with `int_convert.py`).
  - switch groups and exact resource ids; compiler EH cleanup and allocator details excluded from source.
  - one-byte `0x90` alignment at `0x004fc9e7`; switch table starts at `0x004fc9e8`.
- Historical/stale assumptions and negative evidence to preserve:
  - `3a33af0b` was the previous split-session evidence, not the current evidence source for this report.
  - no direct code xrefs is a virtual-method confidence cap only, not a no-route blocker.
  - not a raw helper/free function; not owned by HelpPanes/LanguageMan/CashShopRequest/CreateUserDialogs/NewUserDialogPane/specialized controls; no raw switch-table/source merge.

## Recommended Support Doc Changes
- `by-class/NewUserMiscDialogPane.md`: update the UID0004GR method row and notes to say source-ready `ShowControlHelp` through [UID:00009F], with event type `4`, inherited fallback, child-control hit-test index switch, `g_pSimpleHelpPane` close, `g_pLanguageMan` ids `178..182`, `SimpleHelpPane` timeout `5000`, and confidence caps for inferred event/helper names.
- `by-file/NewUserMiscDialogPane.md`: update proposed contents/source-output notes so UID0004GR is no longer just a pending child review item; it emits through the class route into `NexusTK/login/NewUserMiscDialogPane.cpp` after validation. Keep `CreateUserDialogs` as umbrella only.
- `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md`: update child inventory row for UID0004GR to source-ready exact child; update switch-table row to full `0x004fc9e8-0x004fca20` extent; keep parent `RECONSTRUCTABLE:FALSE` and no parent C++.
- `by-memory/0x004fc9e8-0x004fca20.NewUserMiscDialogPaneHelpSwitchTable.md`: renamed/corrected from the stale shorter filename, preserved `RECONSTRUCTABLE:FALSE`, owner [UID:00009F], blank emitter/C++, and compiler-generated switch-data classification.
- `by-global/g_pSimpleHelpPane.md`, `by-memory/0x004c6f90-0x004c7287.SimpleHelpPaneConstructor.md`, `by-memory/0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers.md`, `by-global/g_pLanguageMan.md`, and exact LanguageMan lookup child docs were read-only inspected and are already present at same-or-greater detail for dependency names and ownership. No direct contradiction was found, so no dependency by-* edits were made.

## Score And Metadata Recommendation
- Pre-callback score/metadata: target `82/89`, owner [UID:00009F], reconstructable true, blank emitter, blank C++.
- Current implemented score/metadata: `COMPLETION:89`, `CONFIDENCE:92`, `CANONICAL_OWNER:00009F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009F`, blank optional position, formal C++ populated.
- Score rationale: completion rises because the report closes the child-level review blocker with current MCP function/xref/decompile/disasm/byte/pointer-pattern/type/name checks, exact behavior, dependency names, range/table split, formal C++ shape, rejected alternatives, and validator/generation plan. Confidence rises because the binary facts and support docs agree on method role and behavior.
- Reason not higher: exact original method spelling, event type name, inherited hit-test helper name, coordinate field names, and final class/header declarations are inferred rather than recovered; the adjacent switch-table support page needs range correction; no final full class audit exists.
- Reason not lower: the target is a modeled vtable method with precise behavior and accepted dependency names, not a raw no-route island.
- Metadata fields to change or leave unchanged: change only target completion/confidence/emitter and C++; preserve owner/reconstructable; no target split/UID change.
- Score-improvement attempts:
  - Checked owner/emitter route through target/class/file/parent docs: resolved.
  - Checked direct/vtable reachability, pointer patterns, and xrefs: resolved with virtual route and negative direct-route evidence.
  - Checked helper/dependency names through docs and MCP decompiles: resolved enough for source-facing names, with exact spelling cap.
  - Checked range/switch table boundary: resolved; support range correction required.
  - Checked generated state: target was absent from generated output before implementation; callback validators refreshed `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` to command `000000005963` with UID0004GR present.

## Open Questions With Attempted Resolution
- Exact event type name: MCP `type_query` returned no matching IDB type. Best current source-facing placeholder is `ControlPaneEvent`; confidence cap only.
- Exact helper name for `sub_49FB10`: MCP decompile proves role but not original spelling. Best current source-facing name is `FindControlAtPoint` / `FindControlAtEventPoint`; confidence cap only.
- Coordinate field names/order: the binary uses event offsets `+8` and `+12`, passes them to hit-test and `SimpleHelpPane`; accepted constructor order is `(text, owner, x, y, timeoutMs)`. The formal draft uses `mouseX`/`mouseY` to express source intent, while report evidence preserves raw offset/order for later header cleanup.
- Exact localized text for ids `178..182`: not decoded in this pass because the method only references numeric ids through `LanguageMan`; source-quality readiness does not require embedding the strings. Future resource documentation may name the help text constants.
- Should the switch-table page be renamed: resolved during callback. Evidence proves `0x004fc9e8-0x004fca20` exclusive, and validator command `000000005958` recorded the UID0004GS `path_update`.
- Should IDA DB labels/types be changed: no. Documentation can use inferred names; IDA DB edits require explicit supervisor/C-agent approval and were not requested in this callback.

## Validator Results
- Scoped validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` for every edited by-* file.

| File | Command | command_id | command_timestamp | Exit | ok | Warnings / errors | Generated refresh |
| --- | --- | --- | --- | ---: | ---: | --- | --- |
| `by-memory/0x004fc780-0x004fc9e7.NewUserMiscDialogPaneShowControlHelp.md` | `python .\tools\validator.py --mode file --file by-memory/0x004fc780-0x004fc9e7.NewUserMiscDialogPaneShowControlHelp.md --apply --queue-timeout 240` | `000000005955` | `2026-07-04T00:43:31-04:00` | 0 | 1 | Transient `missing_ref_target:1` for UID0004GS old path before the switch-table rename was validated. | `generated_refresh: deferred` |
| `by-memory/0x004fc9e8-0x004fca20.NewUserMiscDialogPaneHelpSwitchTable.md` | `python .\tools\validator.py --mode file --file by-memory/0x004fc9e8-0x004fca20.NewUserMiscDialogPaneHelpSwitchTable.md --apply --queue-timeout 240` | `000000005958` | `2026-07-04T00:43:45-04:00` | 0 | 1 | No warnings/errors; `path_update` recorded UID0004GS was `by-memory/0x004fc9e8-0x004fca18.NewUserMiscDialogPaneHelpSwitchTable.md`. | `generated_refresh: deferred` |
| `by-class/NewUserMiscDialogPane.md` | `python .\tools\validator.py --mode file --file by-class/NewUserMiscDialogPane.md --apply --queue-timeout 240` | `000000005959` | `2026-07-04T00:43:59-04:00` | 0 | 1 | No warnings/errors. | `generated_refresh: deferred` |
| `by-file/NewUserMiscDialogPane.md` | `python .\tools\validator.py --mode file --file by-file/NewUserMiscDialogPane.md --apply --queue-timeout 240` | `000000005960` | `2026-07-04T00:44:08-04:00` | 0 | 1 | No warnings/errors. | `generated_refresh: deferred` |
| `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md` | `python .\tools\validator.py --mode file --file by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md --apply --queue-timeout 240` | `000000005961` | `2026-07-04T00:44:16-04:00` | 0 | 1 | No warnings/errors. | `generated_refresh: deferred` |
| `by-memory/0x004fc780-0x004fc9e7.NewUserMiscDialogPaneShowControlHelp.md` rerun after UID0004GS path update | `python .\tools\validator.py --mode file --file by-memory/0x004fc780-0x004fc9e7.NewUserMiscDialogPaneShowControlHelp.md --apply --queue-timeout 240` | `000000005963` | `2026-07-04T00:44:50-04:00` | 0 | 1 | No warnings/errors. | `generated_refresh: deferred`; generated C++ header caught up to this command. |

- Generated freshness: `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` now has `validator-command-id: 000000005963` and `validator-refreshed-at: 2026-07-04T00:44:50-04:00`, equal to the final clean target validator. It includes UID0004GR at lines 194-195 with `Completion:89 | Confidence:92` and `bool NewUserMiscDialogPane::ShowControlHelp(ControlPaneEvent *event)`.
- Generated coverage/tracker freshness: `auto-generated/-ag-memory-coverage.md` lists UID0004GR as `coded`; `auto-generated/-ag-research-tracker.md` lists `89/92`, combined `90.5`, reconstructable `true`, reports `0`.
- Validator side effects: scoped validators updated generated C++, generated/projected stats, and validator registry state through validator-owned mechanisms. Agent-B004 did not hand-edit generated output, `project-level` reports, or validator state.

## Changed Files
- Modified by Agent-B004 in callback: `by-memory/0x004fc780-0x004fc9e7.NewUserMiscDialogPaneShowControlHelp.md`; `by-class/NewUserMiscDialogPane.md`; `by-file/NewUserMiscDialogPane.md`; `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md`; this report file.
- Renamed/corrected by Agent-B004 in callback: `by-memory/0x004fc9e8-0x004fca18.NewUserMiscDialogPaneHelpSwitchTable.md` -> `by-memory/0x004fc9e8-0x004fca20.NewUserMiscDialogPaneHelpSwitchTable.md`.
- Validator-owned side effects observed: `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` refreshed to command `000000005963`; `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-research-tracker.md`, `project-level/-auto-completion-stats.md`, and `tools/validator.ini` were updated by scoped validator commands.
- Leases: B004 leased the five edited by-* docs immediately before the edit/validator batch. Release after validation reported `Rejected[No active lease]` because the short leases had already expired; a subsequent lease-table check showed no active `B004` or `NewUserMisc` leases.
- Agent lifecycle boundary: Agent-B004 did not run `execute_report`, dry-run/probing variants, lifecycle/archive commands, registry commands, manual report moves, generated/manual coverage edits, validator-state edits by hand, or supervisor-ledger edits. After any supervisor execution, validator-owned lifecycle history/archive state is authoritative.

## Implementation Tracking Checklist

Implementation callback pass:
- [x] Supervisor validation before implementation: Gate 1 passed for SHA256 `99D39888E93F1389181D4CC6AD00885A69D5833C651C652A7BC232510E0A1FF1`; callback authorized.
- [x] Target `by-memory/0x004fc780-0x004fc9e7.NewUserMiscDialogPaneShowControlHelp.md`: set `COMPLETION:89`, `CONFIDENCE:92`, kept `CANONICAL_OWNER:00009F`, kept `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:00009F`, kept blank optional position.
- [x] Target formal C++: inserted exact `NewUserMiscDialogPane::ShowControlHelp(ControlPaneEvent *event)` block from `## First-Draft C++ Recommendation`.
- [x] Target evidence: incorporated MCP session `eb7ce28b`, health/IDB proof, size `0x267` / 615 bytes, vtable xref `0x0061d488`, no direct/end/successor xrefs, pointer-pattern results, decompile/disasm behavior, helper/global dependencies, unique signature prefix, one-byte `0x90`, and full switch-table extent.
- [x] Target behavior: recorded event type `4`, inherited fallback through `sub_49E240`, hit-test/index helper `sub_49FB10`, active `g_pSimpleHelpPane` close, localized ids `178..182`, allocation size `252`, timeout `5000`, and source exclusion of allocator/SEH/security-cookie cleanup.
- [x] Target negative evidence: preserved rejection of raw-helper/free-function route, HelpPanes/LanguageMan/CashShopRequest/CreateUserDialogs/NewUserDialogPane/specialized-control/mixed-parent ownership, switch-table code merge, and exact original-name/type proof.
- [x] Support `by-class/NewUserMiscDialogPane.md`: updated UID0004GR row/method notes to source-ready through [UID:00009F] with behavior and confidence caps.
- [x] Support `by-file/NewUserMiscDialogPane.md`: updated proposed contents/status/generated-output notes so UID0004GR emits through the class route; kept [UID:0000LX] as file route and `CreateUserDialogs` as umbrella only.
- [x] Support `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md`: updated UID0004GR child status and switch-table range/end; kept parent non-emitting.
- [x] Support `by-memory/0x004fc9e8-0x004fca20.NewUserMiscDialogPaneHelpSwitchTable.md`: renamed/corrected from the stale shorter path, documented all 14 dwords, and preserved compiler-generated non-source-body classification.
- [x] Dependency docs `g_pSimpleHelpPane`, `SimpleHelpPaneConstructor`, `HelpPaneSingletonCloseHelpers`, `g_pLanguageMan`, and exact LanguageMan lookup docs: read-only inspected and marked already-present. Proof includes `by-global/g_pSimpleHelpPane.md` lines 10/27/33, close-helper lines 47/54, constructor lines 10/18/95, `by-global/g_pLanguageMan.md` lines 24/31, and `LanguageManGetLocalizedString` lines 10/31/35.
- [x] Claim And Incorporation Ledger: updated every GR row to `applied` with destination/proof; dependency support docs marked already-present inside rows GR-006/GR-009.
- [x] Validators: ran scoped validators for every edited by-* file only; command ids `000000005955`, `000000005958`, `000000005959`, `000000005960`, `000000005961`, and clean target rerun `000000005963` recorded above.
- [x] Generated freshness: checked `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp`; header is equal to final target validator command `000000005963` and UID0004GR appears as expected.
- [x] Generated/manual coverage exclusions: no generated files, generated reports, manual `-coverage-report.md`, validator state, report lifecycle files, archives, or supervisor ledgers were hand-edited. Generated/projected stats and `tools/validator.ini` changes were validator-owned side effects.
- [x] Leases: leased only the immediate edit batch; release command found no active leases because they had expired; follow-up lease-table check showed no active B004/NewUserMisc leases.
- [x] Remaining unapplied accepted items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000005991","destination_path":"executed-b-agent-research/B004/0004GR-NewUserMiscDialogPaneShowControlHelp-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0004GR-NewUserMiscDialogPaneShowControlHelp-source-quality.md","timestamp":"2026-07-04T02:52:58-04:00","uid":"0004GR"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
