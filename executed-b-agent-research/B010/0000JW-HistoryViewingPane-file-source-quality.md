# UID0000JW HistoryViewingPane Whole-File Source-Quality Report
** TARGET-REPORT-UID:0000JW **
** TARGET-REPORT-ADDITIONAL-UIDS:000066,0000R3,0001A0,0001A1,0001A7,0001AB,0001AG,0001PU **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


## Finalized Report / Current Recommendation

- Reconstruct [UID:0000JW] as the standalone, source-authored `NexusTK/login/HistoryViewingPane.cpp` and `HistoryViewingPane.h` compilation unit. The class is not owned by `MainMenuPane`, `ChattingColorPane`, `BackStoryDialogPane`, or `NewHistoryDialogPane`; those modules are consumers or adjacent classes.
- Emit only the human-authored class declaration, private `AdvancePage`, constructor, key/mouse/timer/paint overrides, the singleton pointer definition, and `Singleton<HistoryViewingPane>` constructor/destructor specializations. Do not emit the constructor-unwind island, singleton-clear thunk, destructor adjustors, scalar-deleting wrapper, vtable arrays, COLs, RTTI descriptors, or padding.
- Replace decompiler-shaped or contradicted source with the current source-facing API: `InvalidateRect(&m_visibleBounds)`, `GetEntryCount`, `LookupLayoutEntry`, `RenderTileFrame`, `AddToLayer`, `SetPaneOrder(NULL, g_pScreenPane)`, `ScheduleTimer`, `RemovePendingTimers`, `HandleKeyOrTextEvent`, `HandlePointerOrMouseEvent`, `OnTimer`, and `OnPaint`.
- Model `HistoryViewingPane` as `Pane` plus direct empty `Singleton<HistoryViewingPane>` inheritance. The exact 32-bit layout is `Pane` at `+0x0` through `+0xf7`, `m_frameIndex` at `+0xf8`, `m_lastFrameIndex` at `+0xfc`, `m_pageDelayMs` at `+0x100`, and `mystr::StringBase<wchar_t> m_resourceName` at `+0x104`, total `0x108` bytes.
- Let the implicit virtual destructor regenerate the observed member destruction, Singleton clear, base destruction, deleting wrapper, and adjustors. The existing explicit `m_resourceName.Release()`/manual singleton clear body is rejected because current `StringBase` has no such source API and the compiler-generated order already follows member/base destruction.
- Split exact vtable/RTTI bytes `[0x0061d9cc,0x0061da54)` from mixed aggregate [UID:00025Q] into a physical non-emitting by-memory child and a semantic `by-type/by-vtable/HistoryViewingPaneVtables.md` page, both class-owned. UID00025Q is affected support only, not an additional report target; UID allocation is validator-owned.
- Make [UID:0000JW] explicitly reconstructable and raise it from `87/87` to `93/94`. The remaining confidence cap is original spelling rather than unresolved behavior, ownership, layout, routing, or source eligibility.

## Supporting Research

- Live canonical read-only IDA MCP session: `supervisor_uid0000md_persistverify_20260816`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Public schema-1 runtime attestation at `2026-08-16T10:47:34Z` returned `ok:true`, `errors:[]`, exact canonical path match, listener PID `14320`, stateful worker PID `17660`, and the expected loaded NexusTK module. Health returned `status:ok`, image base `0x00400000`, Hex-Rays ready, strings cache ready with `2068` entries, and `auto_analysis_ready:false`. Bounded function, byte, type, xref, disassembly, decompile, stack-frame, comment, and string queries all succeeded, so the analysis-ready flag is context rather than an MCP outage.
- Current target/support documentation read: UIDs `0000JW`, `000066`, `0001A0`, `0001A1`, `0001A7`, `0001AB`, `0001AG`, `0000R3`, `0001PU`, `00025Q`, `0001RF`, `0001RG`, `00019R`, `0003H6`, `0003H7`, `0000L0`, `00007O`, `0000MC`, `0000A2`, `0001EA`, `00004N`, `0000J7`, `0000F0`, `0000OT`, `0000K2`, `0000QU`, `0000L1`, `0004VF`, `0000HG`, `00000D`, `0000S7`, `0000CB`, and `0000OA`.
- Matching archived/executed-report searches used `0000JW`, `HistoryViewingPane`, `004ffd40`, `004ffd80`, `004ffed0`, `005023b0`, `005024b6`, `00502760`, `0061d9cc`, `0069b494`, `NPAL4.PAL`, `OpenStoryViewingPane`, and `OpenHistoryViewingPane`. Prior B001/B004/B006/B007/B010/B011 work was retained as historical lead material and rechecked against the current canonical session.
- Dated generated source snapshot observed during the report audit at `auto-generated/NexusTK/login/HistoryViewingPane.cpp`: validator command `000000024879`, refresh `2026-08-16T06:40:10-04:00`, SHA256 `6A13AFD5DE7F392418049C593FE3C0ECBD93AD86FEB00E34D00A1A54D46E7D13`, `3015` bytes, `105` physical lines. No `HistoryViewingPane.h` existed in that snapshot.
- Shared generated headers/source from the same dated snapshot were read rather than inferred: `Pane.h` SHA256 `72AF7B6ABC7FF055602C61FBD6DC515C47401BE03B160C1C53417C14139EF141`; `MainUiGraph.h` SHA256 `6DFF2C618398FED73118B99352A5333A11CDF4F91B102AF8F42158320365EA67`; `MainMenuPane.cpp` SHA256 `8E910AED72BD5797848E464194B27805C469CBF974CD546D96E89E16785F1D3B`; `MainMenuPane.h` SHA256 `5ED9C9D9F743400CAF7D8F2A37B6AA8C9FFA364DBF380CB126C2084C62B8D88C`; `Application.h` SHA256 `AF3D28B130734E51C4A6A22F31D9561384E82C12094CA7F2F3E2BAEF76BA8218`.
- Manual coverage rows for every declared UID, support-only UID00025Q, and the two resource pages were read. They are stale in score, source naming, destructor disposition, storage initializer, and vtable-child completeness; Section 28 supplies exact supervisor-owned replacements plus complete literal allocated rows and placement anchors for UID00054H/UID00054I. B010 did not edit coverage.

## Target

- Primary: `[UID:0000JW] by-file/HistoryViewingPane.md`.
- Additional declared targets: `[UID:000066] by-class/HistoryViewingPane.md`; `[UID:0001A0] by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md`; `[UID:0001A1] by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md`; `[UID:0001A7] by-memory/0x005023b0-0x005023bb.HistoryViewingPaneSingletonClear.md`; `[UID:0001AB] by-memory/0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks.md`; `[UID:0001AG] by-memory/0x00502760-0x005027cc.HistoryViewingPaneDestructor.md`; `[UID:0000R3] by-global/g_pHistoryViewingPane.md`; `[UID:0001PU] by-memory/0x0069b494-0x0069b498.g_pHistoryViewingPane.md`.
- Affected but not additionally declared support: `[UID:00025Q] by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md`, limited to the exact HistoryViewingPane child/link, source-owner, manual-row, and unchanged-score maintenance; resource UIDs `0001RF/0001RG`; MainMenu launch UIDs `00019R/0003H6/0003H7`; Pane UIDs `0000MC/0000A2/0001EA`; MainUiGraph/global UIDs `0000L1/0004VF`; Event/Timer/ImageLib/StringBase/Application/ScreenPane support pages. No report coverage is claimed for UID00025Q.
- Exact owned executable spans: `0x004ffd40-0x004ffd79`, `0x004ffd80-0x0050008b`, compiler-only `0x005023b0-0x005023bb`, `0x005024b6-0x005024cc`, and `0x00502760-0x005027cc`.
- Exact owned data spans: singleton storage `[0x0069b494,0x0069b498)` and class vtable/COL physical cluster `[0x0061d9cc,0x0061da54)`; associated RTTI graph is rooted at COLs `0x0064a8cc`, `0x0064a97c`, and `0x0064a990`.

## Current Target State

- The accepted ordinary callback is applied. [UID:0000JW] is `93/94`, retains `NexusTK/login/` and `FILE` ownership, and routes through validator-assigned file-shell [UID:00054J] at position `0`. UID00054J carries the exact CPP include shell and H guard.
- [UID:000066] is `93/95`, owned by UID0000JW and emitted through UID00054J at position `10`; [UID:0001A0] is `92/94` at class position `10`; [UID:0001A1] is `93/95` at class position `20`. Their accepted CPP/H is physically generated.
- [UID:0001A7] and [UID:0001AB] are `90/94`, non-reconstructable, and non-emitting. [UID:0001AG] is `92/95`, non-reconstructable/non-emitting with blank formal CPP/H; its old explicit destructor source is rejected history.
- [UID:0000R3] is `92/94`, emitted through UID00054J at position `20`, and owns the NULL global, Singleton specializations, and extern. Physical storage [UID:0001PU] is `92/95`, retains UID0000R3 as canonical owner, has exact zero bytes, and is deliberately non-emitting.
- Validator assigned [UID:00054H] to exact physical `[0x0061d9cc,0x0061da54)` vtable/COL documentation and [UID:00054I] to semantic `HistoryViewingPaneVtables`. UID00025Q remains support-only at `86/92`.
- Dated repair refresh `000000025051` produced `HistoryViewingPane.cpp` SHA256 `A32C735CA1EEF01325D6FC3479A02F24FC2382E359C43D4BBD49D6722F360245` and `HistoryViewingPane.h` SHA256 `10EB8180DE4847605FA7376BECF85D6D060236B277D29E22D63D56B1CE7A048C`. The pair contains all accepted bodies/declarations and no explicit destructor, empty marker, placeholder, stub, stale virtual/field/API name, raw vtable/COL/RTTI array, or compiler-page marker. Command `000000024998` remains dated evidence of the initial callback; command `000000025051` is the latest dated B010-observed snapshot and remains subordinate to a fresh supervisor reread at Gate 2A/final validation.
- The same command `000000025051` produced `MainMenuPane.cpp` with `#include "HistoryViewingPane.h"`, `Pane.h` with `SetPaneOrder(Pane *beforePane, Pane *afterPane)`, and `MainUiGraph.h` with a compile-visible `Layer` forward plus `extern Layer *g_pStatusPaneLayer;`.
- Only C0JW-054 manual coverage, C0JW-055 through C0JW-057 IDA/no-UDT verification, and C0JW-060 lifecycle authority remain supervisor-owned and unchecked. C0JW-055 now limits the singleton handoff to a direct regular address comment at unchanged unnamed `0x0069b494`; it does not authorize a global rename. B010 did not edit coverage or IDA and did not run a lifecycle command.

## Executive Recommendation

1. Complete the source module as one conventional late-1990s/mid-2000s pair: `HistoryViewingPane.cpp/.h`.
2. Route source-authored definitions in order: by-file include shell; class child shell; `AdvancePage`; core constructor and four virtual methods; then global definition/Singleton specializations. Route declarations through by-file include guard, class H, and global H.
3. Remove the explicit destructor source and let the compiler regenerate member/base cleanup, singleton clear, deleting wrapper, and adjustors from an implicit virtual destructor.
4. Add exact physical/semantic vtable documentation, but leave compiler data non-emitting.
5. Correct shared `Pane::SetPaneOrder` to two Pane pointers; expose `g_pStatusPaneLayer`; include `HistoryViewingPane.h` from MainMenuPane.
6. Preserve launch helpers in MainMenuPane and resources in the resource pages. They establish reachability/configuration but are not members of the HistoryViewingPane compilation unit.
7. Apply the deterministic IDA handoff only after supervisor Gate 1. The supported executable-body actions are function renames/types/comments; singleton storage `0x0069b494` retains stored name absent and receives only the direct regular address comment specified by A0JW-13.2. Do not create a partial HistoryViewingPane UDT; current IDA has no complete class type and existing base-facet types safely describe machine receivers.

## Supervisor Active Recheck

- Historical recheck trigger: the report-only assignment explicitly required a fresh whole-file pass because direct/additional report coverage was `0/0`, the file's reconstructability field was blank, the dated generated C++ was partial/stale, and a required header was absent at that pre-callback snapshot.
- Canonical MCP was live and bounded throughout research. No fallback-only evidence was used.
- Active recheck corrected prior names rather than accepting previous scores: `IsInteractive` is the tertiary `TimerHandler::OnTimer`; the two input functions are EventHandler overrides; the paint function is `OnPaint`; `m_resourceName` is a pointer-sized wide `StringBase`, not a custom object with `Assign/Release`; and `Pane::SetPaneOrder` has two Pane-pointer arguments.
- Active recheck confirmed the only source-authored file members are the class declaration, five non-constructor methods, constructor, singleton definition/specializations, and required declarations/includes. Every other discovered class-specific item has compiler-only or support-page disposition below.
- Historical report-only boundary: B010 did not mutate an ordinary doc, generated artifact, manual coverage row, IDA state, validator state, tracker, audit file, goal, notes, or lifecycle artifact during the pre-callback research pass. The later accepted ordinary callback and its validator-owned generated side effects are recorded in Sections 31 and 32.

## Inference Research Guidance Check

- Exact behavior has priority over style. Every source branch, field offset, timer operation, singleton transition, draw argument, and resource literal is grounded in current machine evidence.
- Human source shape has priority over preserving decompiler residue. No final formal source uses `sub_`, `unk_`, `_DWORD`, raw vtable calls, manual vtable stores, explicit scalar-delete flags, raw offsets, or tool-derived file names.
- Inferred names use established subsystem style: `g_pHistoryViewingPane`, `m_frameIndex`, `m_lastFrameIndex`, `m_pageDelayMs`, `m_resourceName`, `AdvancePage`, `HandleKeyOrTextEvent`, `HandlePointerOrMouseEvent`, `OnTimer`, and `OnPaint`.
- Style consistency is subordinate to direct evidence. Decorated RTTI/vtable names are preserved unchanged; source-facing names are inferred only where original symbols are absent.
- Mid-period compatibility is preserved: `NULL`, include guards, ordinary virtual declarations, and no `override`, `nullptr`, range-for, lambdas, smart pointers, or modern header-only restructuring.
- Wave2/Wave3 references encountered in old material were ignored as stale and did not contribute evidence.

## Heuristic / Inference Reanalysis And Validation

| Question | Evidence examined | Best-supported resolution | Residual impact |
| --- | --- | --- | --- |
| Standalone file or MainMenu fold | Dedicated contiguous method family, singleton, three-view RTTI, generated route, six constructor callers | Standalone `login/HistoryViewingPane.cpp/.h`; MainMenu owns only creation decisions | None |
| Exact inheritance | Pane size `0xf8`, secondary views `+0xa0/+0xa4`, direct Singleton RTTI PMD `+0xf8`, class size `0x108` | `class HistoryViewingPane : public Pane, public Singleton<HistoryViewingPane>` | Original access specifier is inferred |
| Frame fields | Reads/writes at `+0xf8/+0xfc`; ctor stores count minus one | `m_frameIndex`, `m_lastFrameIndex`; comparison is inclusive-last semantics | Exact spelling inferred |
| Delay field | Literal `10000` at `+0x100`; ScheduleTimer uses it after input | `unsigned int m_pageDelayMs` | Exact spelling inferred |
| Resource member | default construction, wide assignment, c_str lookup, automatic destruction at `+0x104` | `mystr::StringBase<wchar_t> m_resourceName` | Alias spelling follows current project type |
| `0x004fff90` | tertiary TimerHandler vtable slot `+4`, `retn 0xc`, always true | `bool OnTimer(int,int,int)`; reject `IsInteractive` | None |
| Mouse inlining | helper has one key caller; mouse body duplicates exact clamp/increment/invalidate | Source calls `AdvancePage()` in both; optimizer inlined one call | Strong inference, behavior exact |
| Destructor source | member-dtor call, Singleton clear, Pane dtor, delete flags; StringBase lacks `Release()` | implicit virtual destructor; no authored destructor body | None |
| Singleton publication | direct empty-base RTTI at `+0xf8`, constructor publish, unwind/destructor clear | explicit Singleton template specializations plus global definition | Exact template style matches project precedent |
| Vtable ownership | three constructor/destructor stores, decorated names, RTTI hierarchy | class-owned compiler data, physical child under UID00025Q, semantic vtable page | Applied as physical UID00054H and semantic UID00054I |
| Layer global | constructor reads `0x0069b378`; current global doc identifies `g_pStatusPaneLayer` | add extern to MainUiGraph H; reject `g_pMainUiLayer` | None |
| Pane ordering API | body `0x00544d30` forwards two Pane facets; call pushes NULL and screen pane | `SetPaneOrder(Pane *beforePane, Pane *afterPane)` | Parameter spellings inferred |
| Resource extensions | callers pass HISTORY/STORY EPF/EPD variants; same class consumes name | constructor intentionally accepts any compatible wide resource name | Missing legacy EPD payload remains packaging evidence only |
| ChattingColor pollution | no current generated occurrence; class-specific RTTI/callers exclude chat | preserve as superseded generated-routing history only | None |

No reasonable whole-file blocker remains deferred. Exact original spellings cannot be recovered from a stripped binary, so the report selects the highest-probability names rather than retaining compiler/decompiler labels.

## Evidence Standards Used

- `original-proof`: exact decorated RTTI/vtable identities, literal bytes/addresses, current package names, or exact current generated hashes.
- `very-strong`: current modeled ranges, disassembly/decompile, frames, xrefs, field offsets, constructor/destructor stores, and corroborating support APIs.
- `strong`: source-facing spelling, private/public visibility, and file/header organization inferred from complete binary/source-family context.
- Documentation and old reports are leads only. A recommendation does not receive current-fact status unless current IDA, exact current generated output, current manual row text, or a mature independently verified support declaration corroborates it.
- Negative claims were tested with no-function checks, xref queries, pointer-pattern searches where relevant, collision lookups, current generated-tree search, and exact predecessor/successor boundaries.

## Evidence Checked

- IDA function/range/bytes/frame/comment/type/xref evidence at every assigned span and all three table views; exact constructor callers and class-global reads/writes; collision checks for every proposed source-facing symbol.
- Whole-file docs and support docs listed in Supporting Research, plus source-tree paths and current generated CPP/H dependencies.
- Historical pre-callback generated audit: command `000000024879` produced `HistoryViewingPane.cpp` with no sibling `HistoryViewingPane.h`; the same dated snapshot included `Pane.h`, `Event.h`, `ImageLib.h`, `EPFTileContext.h`, `GrafPort.h`, `TimerHandler.h`, `StringBase.h`, `Singleton.h`, `ScreenPane.h`, `MainUiGraph.cpp/.h`, `MainMenuPane.cpp/.h`, and `Application.h`. Initial callback output was reread under command `000000024998`; Gate 2A stale-active-prose repairs were scoped-validated by commands `000000025041` through `000000025050`, and the coherent final repair snapshot was physically reread under command `000000025051` as recorded in Sections 31 and 32.
- Manual by-file, by-class, by-memory, by-global, and by-resource coverage rows for all declared/affected entries.
- Archived/executed-report searches by UID, exact address, current/stale names, singleton, palette, vtable, and launch-helper family. Valid historical evidence was retained; current contradictions were historicalized.
- Negative checks: no current HistoryViewingPane UDT; no current `class_ChattingColorPane.cpp` pollution; no ordinary callers to compiler thunks; no modeled function at cleanup island `0x004ffed0`; no source pointer route requiring launch helpers to move; no fourth vtable view; no additional class-owned executable member in the bounded neighborhood; no interior vtable split xref.
- Failed/unavailable checks: none. `auto_analysis_ready:false` did not block bounded live queries and is recorded without treating MCP as down.
- Whole-file completeness searches reconciled 6 source-authored function bodies, 1 implicit destructor source effect, 4 non-contiguous compiler executable artifacts/spans, 1 global, 1 physical singleton slot, 1 class layout, 3 vtable views, 3 COLs and one 7-base RTTI graph, 3 relevant resource families, 6 constructor call sites, all padding/boundaries, all related by-* pages, and generated CPP/H state.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C0JW-001 | 0000JW | Preserve the exhaustive HistoryViewingPane whole-file inventory and all source/compiler/support dispositions. | very-strong | Canonical ranges, xrefs, RTTI, docs, and generated audit. | UID0000JW inventory/evidence | incorporate | applied |
| C0JW-002 | 0000JW | Set reconstructable TRUE and retain standalone path NexusTK/login. | very-strong | Complete source route and no owner ambiguity. | UID0000JW metadata | incorporate | applied |
| C0JW-003 | 0000JW | Confirm standalone HistoryViewingPane.cpp/.h rather than MainMenu or chat folding. | strong | Dedicated class cluster, singleton, RTTI, six consumers. | UID0000JW ownership/source placement | incorporate | applied |
| C0JW-004 | 0000JW | Emit file CPP/H shells with deterministic class/global child order. | strong | Complete declaration/definition dependency audit. | UID0000JW formal CPP/H | incorporate | applied |
| C0JW-005 | 000066 | Document Pane plus direct Singleton inheritance, exact fields, offsets, and 0x108 size. | very-strong | Pane size, RTTI PMDs, field accesses. | UID000066 layout | incorporate | applied |
| C0JW-006 | 000066 | Record the complete authored method inventory and implicit destructor disposition. | very-strong | All three vtables and bounded code inventory. | UID000066 methods | incorporate | applied |
| C0JW-007 | 0001A0 | Replace stale AdvancePage fields/API with last-index semantics and InvalidateRect(m_visibleBounds). | very-strong | Exact bytes and shared Pane API. | UID0001A0 behavior/CPP | reject-stale | applied |
| C0JW-008 | 0001A1 | Reconstruct constructor initialization, resource count, layer/order, and timer scheduling exactly. | very-strong | Constructor disassembly/decompile and callees. | UID0001A1 constructor/CPP | incorporate | applied |
| C0JW-009 | 0001A1 | Reconstruct HandleKeyOrTextEvent with event translation and Enter/Escape/Space behavior. | very-strong | Event type, key literals, one AdvancePage caller. | UID0001A1 key method/CPP | reject-stale | applied |
| C0JW-010 | 0001A1 | Reclassify 0x004fff90 from IsInteractive to TimerHandler OnTimer. | original-proof | Tertiary vtable slot and retn 0xc. | UID0001A1 timer method/CPP | reject-stale | applied |
| C0JW-011 | 0001A1 | Reconstruct HandlePointerOrMouseEvent and source-call AdvancePage despite optimized inline lowering. | very-strong | Event values, duplicate state machine, one helper xref. | UID0001A1 mouse method/CPP | incorporate | applied |
| C0JW-012 | 0001A1 | Reconstruct OnPaint with EPFTileContext, LookupLayoutEntry, RenderTileFrame, and NPAL4.PAL. | very-strong | Exact calls, literal xref, current APIs. | UID0001A1 paint method/CPP | reject-stale | applied |
| C0JW-013 | 0000R3 | Define g_pHistoryViewingPane as NULL-initialized source global. | original-proof | Zero-filled storage and six lifecycle xrefs. | UID0000R3 CPP/H | incorporate | applied |
| C0JW-014 | 0000R3 | Emit Singleton constructor/destructor specializations for publication/clear. | very-strong | EBO RTTI, ctor/unwind/dtor sequence, project pattern. | UID0000R3 CPP | incorporate | applied |
| C0JW-015 | 0001AG | Retire explicit destructor body and classify wrapper as compiler-covered implicit destruction. | very-strong | StringBase/member/Singleton/base/delete sequence. | UID0001AG metadata/no-code | reject-stale | applied |
| C0JW-016 | 0001A1 | Preserve cleanup island 0x004ffed0-0x004fff0a as constructor-unwind compiler code. | original-proof | Not modeled function; exact vtable/member/global/base cleanup. | UID0001A1 range/compiler evidence | incorporate | applied |
| C0JW-017 | 0001A7 | Preserve singleton clear 0x005023b0-0x005023bb as compiler EH helper with blank code. | original-proof | Exact bytes and constructor EH xref. | UID0001A7 no-code evidence | incorporate | applied |
| C0JW-018 | 0001AB | Preserve both destructor adjustors as ABI compiler thunks with blank code. | original-proof | Exact -0xa0/-0xa4 adjustments and vtable refs. | UID0001AB no-code evidence | incorporate | applied |
| C0JW-019 | 0001AG | Preserve scalar-deleting wrapper/vtable/base/delete mechanics as compiler output. | original-proof | Exact function body and thunk/vtable refs. | UID0001AG compiler evidence | incorporate | applied |
| C0JW-020 | 00025Q | As support-only maintenance, create the exact physical child for 0x0061d9cc-0x0061da54 under the mixed aggregate without claiming UID00025Q report coverage. | original-proof | Exact predecessor/successor and 136 bytes. | UID00025Q support child inventory | incorporate | applied |
| C0JW-021 | 000066 | Create semantic HistoryViewingPaneVtables support page owned by the class. | very-strong | Three complete slot tables and RTTI graph. | new by-type/by-vtable page | incorporate | applied |
| C0JW-022 | 000066 | Preserve seven-base RTTI hierarchy and direct Singleton EBO at +0xf8. | original-proof | Three COLs, CHD, base array, PMDs. | UID000066 RTTI | incorporate | applied |
| C0JW-023 | 0001RF | Synchronize HISTORY resource ownership and viewer behavior without moving resources into source ownership. | very-strong | Caller literals, package evidence, ctor parameter. | UID0001RF HistoryViewingPane linkage | incorporate | applied |
| C0JW-024 | 0001RG | Synchronize STORY resource ownership and retained launcher evidence. | very-strong | Wrapper/direct caller literals and package evidence. | UID0001RG HistoryViewingPane linkage | incorporate | applied |
| C0JW-025 | 0001A1 | Preserve NPAL4.PAL as viewer paint palette and reject PAL01/NPAL8 ownership. | original-proof | String xref at 0x00500061 and resource matrix. | UID0001A1/resource cross-reference | incorporate | applied |
| C0JW-026 | 00019R | Keep launch aggregate and exact helper children under MainMenuPane. | very-strong | Resource-selection behavior and source boundaries. | UID00019R ownership note | already-present | already-present |
| C0JW-027 | 0000L0 | Preserve four active direct MainMenu constructor call sites. | original-proof | Xrefs 0x4f7b8d/0x4f7bc3/0x4f7c07/0x4f7c3d. | UID0000L0 caller inventory | incorporate | applied |
| C0JW-028 | 0003H6 | Preserve retained OpenStory/OpenHistory wrappers as real MainMenu helpers, not History members. | very-strong | Modeled bodies and ctor calls 0x4f912b/0x4f91ab. | UID0003H6/0003H7 ownership | already-present | already-present |
| C0JW-029 | 0000A2 | Correct Pane SetPaneOrder declaration to two Pane pointer arguments. | very-strong | Body 0x00544d30 and call-site pushes. | UID0000A2 formal H/signature evidence | reject-stale | applied |
| C0JW-030 | 0004VF | Add extern Layer *g_pStatusPaneLayer to MainUiGraph header route. | very-strong | Constructor data read and global owner page. | UID0004VF formal H | incorporate | applied |
| C0JW-031 | 0001A1 | Use current Event/EventMan and TimerHandler source APIs rather than synthetic KeyEvent/MouseEvent/timer member APIs. | very-strong | Shared formal headers and facet vtables. | UID0001A1 dependencies/CPP | reject-stale | applied |
| C0JW-032 | 0001A1 | Use ImageLib/EPFTileContext/GrafPort source APIs rather than EpfFrame/GetFrame/DrawEpfFrame. | very-strong | Current shared headers and exact calls. | UID0001A1 dependencies/CPP | reject-stale | applied |
| C0JW-033 | 000066 | Adopt inferred human names m_lastFrameIndex, m_pageDelayMs, m_resourceName, and AdvancePage. | strong | Offsets, semantics, subsystem style. | UID000066 naming/layout | incorporate | applied |
| C0JW-034 | 0000JW | Historicalize and reject old class_ChattingColorPane generated pollution. | very-strong | Current tree absence and class-specific RTTI/callers. | UID0000JW history | historicalize | applied |
| C0JW-035 | 0000JW | Record the dated generated CPP hash, three empty markers, stale bodies, and missing H, subordinate to fresh dynamic reread. | original-proof | Physical generated readback at command 24879. | UID0000JW generated audit | incorporate | applied |
| C0JW-036 | 0000JW | Apply exact by-file CPP include shell and H include-guard child shell. | strong | Complete source dependency/order analysis. | UID0000JW formal CPP/H | incorporate | applied |
| C0JW-037 | 000066 | Apply class CPP child shell and complete formal class H declaration. | very-strong | Full method/layout/RTTI inventory. | UID000066 formal CPP/H | incorporate | applied |
| C0JW-038 | 0001A0 | Apply exact formal AdvancePage CPP and blank H. | very-strong | Exact behavior and private declaration on class H. | UID0001A0 formal CPP/H | incorporate | applied |
| C0JW-039 | 0001A1 | Apply exact formal constructor/input/timer/paint CPP and blank H. | very-strong | Complete core behavior and class declarations. | UID0001A1 formal CPP/H | incorporate | applied |
| C0JW-040 | 0000R3 | Apply exact global/specialization CPP and extern H. | very-strong | Singleton/global lifecycle proof. | UID0000R3 formal CPP/H | incorporate | applied |
| C0JW-041 | 0001AG | Keep formal CPP/H blank after compiler-only reclassification. | very-strong | Implicit destructor regenerates full wrapper. | UID0001AG formal CPP/H | reject-stale | applied |
| C0JW-042 | 0000JW | Set emitter positions to file shell 0, class 10, methods 10/20, global 20 with deterministic child order. | strong | Required generated declaration/definition ordering. | target/support emitter metadata | incorporate | applied |
| C0JW-043 | 0000JW | Raise file metadata to 93/94 and reconstructable TRUE. | very-strong | Whole-file closure and exact remaining cap. | UID0000JW scores/metadata | incorporate | applied |
| C0JW-044 | 000066 | Raise class metadata to 93/95 while preserving owner/emitter UID0000JW. | very-strong | Complete layout, methods, RTTI, formal H. | UID000066 scores/metadata | incorporate | applied |
| C0JW-045 | 0001A0 | Raise AdvancePage to 92/94. | very-strong | Exact body, caller, fields, formal source. | UID0001A0 scores | incorporate | applied |
| C0JW-046 | 0001A1 | Raise core to 93/95. | very-strong | Complete range/behavior/dependencies/formal source. | UID0001A1 scores | incorporate | applied |
| C0JW-047 | 0001A7 | Set singleton clear, thunks, and destructor wrapper to 90/94, 90/94, and 92/95 non-reconstructable/no-emitter. | very-strong | Exhaustive compiler-only proof. | UID0001A7/0001AB/0001AG metadata | incorporate | applied |
| C0JW-048 | 0000R3 | Raise global/storage to 92/94 and 92/95 and correct zero initializer. | very-strong | Exact bytes, xrefs, source route. | UID0000R3/0001PU scores/state | incorporate | applied |
| C0JW-049 | 00025Q | As support-only maintenance, keep the broad aggregate at 86/92 and add the exact HistoryViewingPane child/link and semantic route; UID00025Q receives no report coverage. | very-strong | Aggregate remains a mixed support index; the HistoryViewingPane child is complete. | UID00025Q support inventory/unchanged-score rationale | incorporate | applied |
| C0JW-050 | 0001RF | Preserve resource scores and add corrected viewer method/source names. | very-strong | Current resource evidence already high quality. | UID0001RF/0001RG support text | incorporate | applied |
| C0JW-051 | 0000L0 | Add HistoryViewingPane.h include and corrected consumer/source boundary to MainMenuPane. | strong | Compile-visible construction and six callers. | UID0000L0 formal CPP/support | incorporate | applied |
| C0JW-052 | 0000A2 | Preserve exact two-Pane SetPaneOrder ABI evidence in Pane class/file/core docs. | very-strong | Complete body and multiple call-site shapes. | UID0000A2/0000MC/0001EA | incorporate | applied |
| C0JW-053 | 0004VF | Preserve status-layer global source/header ownership in MainUiGraph docs. | very-strong | Exact storage/xref and current source route. | UID0004VF/0000L1 | incorporate | applied |
| C0JW-054 | 0000JW | Supply exact supervisor-owned manual coverage replacements/inserts without editing coverage. | original-proof | Current physical manual rows plus complete literal UID00054H/UID00054I rows and exact placement anchors in Section 28. | Section 28/manual coverage | incorporate | proposed |
| C0JW-055 | 0000JW | Apply deterministic supported function rename/type/comment recommendations and the direct singleton `set_address_comments` payload `{database,items:[{addr,comment}]}` on unchanged unnamed address 0x0069b494 only after fresh supervisor prestate checks; do not rename the singleton. | very-strong | Live literal function/address prestates, function-name collision checks, failed fallback-label data-rename dry runs, and exact singleton item `{addr:"0x0069b494", comment:"HistoryViewingPane Singleton pointer; zero-initialized and cleared by Singleton destruction."}`. | Section 21/IDA Gate 2B | incorporate | proposed |
| C0JW-056 | 0000JW | Preserve compiler entities/decorated tables and add semantic comments without changing boundaries. | original-proof | Exact bytes/names/types/comments/xrefs. | Section 21/IDA Gate 2B | incorporate | proposed |
| C0JW-057 | 000066 | Do not create a partial HistoryViewingPane IDA UDT; preserve current safe base-facet types. | very-strong | Complete UDT absent; existing support UDTs present. | Section 21/type safety | not-applicable | proposed |
| C0JW-058 | 0000JW | Run scoped validators and coherent waited generated CPP/H verification only after accepted callback. | strong | Validator-owned source generation contract. | Section 31/follow-up | incorporate | applied |
| C0JW-059 | 0000JW | Preserve superseded assumptions with rejection reasons rather than deleting history. | very-strong | Current evidence contradicts prior names/routes. | target/support history sections | historicalize | applied |
| C0JW-060 | 0000JW | Preserve B-agent no-IDA/no-coverage/no-lifecycle-mutation boundary and supervisor lifecycle authority. | original-proof | Current assignment and skill contract. | report/Section 32 | not-applicable | proposed |

## Positive Evidence Summary

- All six source-authored executable methods are bounded and class-connected by direct vtable/caller evidence. The constructor has six exact callers; the private helper has one exact key-handler caller; the paint/input/timer methods occupy exact class vtable slots.
- Three constructor/destructor/cleanup store sets use the same primary/secondary/tertiary table heads. Three COLs use one HistoryViewingPane type descriptor and one seven-base hierarchy. This excludes accidental adjacency or a generic Pane owner.
- Field offsets and destruction order close the complete `0x108` layout. No unaccounted storage remains.
- The constructor and paint body bind source dependencies to exact current project APIs and globals. The resource name flows from six creation sites into entry-count and frame lookup; `NPAL4.PAL` has a direct paint xref.
- The Singleton EBO and lifecycle writes explain publication, normal destruction, and constructor-unwind clear without manual class-body writes.
- The historical command-`000000024879` generated snapshot independently proved that the emitter family was already routed to `NexusTK/login/HistoryViewingPane.cpp`; its then-current defects were incomplete/stale content rather than file-owner uncertainty. The accepted callback repaired those defects, as shown by dated command `000000024998`.
- Strongest inference chain: dedicated class RTTI plus exact method/table/global lifecycle plus six external constructors plus complete field layout plus current source-tree route is sufficient to identify one standalone compilation unit and distinguish source-authored code from compiler products.

## IDA MCP Facts

- Function facts: `0x004ffd40` size `0x39`; `0x004ffd80` size `0x149`; `0x004ffed0` code but not a modeled function; `0x004fff10` size `0x74`; `0x004fff90` size `0x5`; `0x004fffa0` size `0x7a`; `0x00500020` size `0x6b`; `0x005023b0` size `0xb`; `0x005024b6` and `0x005024c1` size `0xb`; `0x00502760` size `0x6c`.
- Current function types: `0x004ffd40 int __thiscall(_DWORD *this)`; `0x004ffd80 int __thiscall(int this,unsigned __int16 *)`; `0x004fff10 char __thiscall(TimerHandler *this,_BYTE *)`; `0x004fff90 char __stdcall(int,int,int)`; `0x004fffa0 char __thiscall(TimerHandler *this,int)`; `0x00500020 void __thiscall(GrafPort *this)`; `0x005023b0 void()`; adjustors `void **__thiscall(void **this,char)`; destructor wrapper `void **__thiscall(void **Block,char)`.
- Exact AdvancePage bytes: `8b 81 f8 00 00 00 3b 81 fc 00 00 00 7d 2a 83 f8 03 7d 15 b8 03 00 00 00 89 81 f8 00 00 00 8d 41 44 8b 11 50 ff 52 20 c3 40 89 81 f8 00 00 00 8d 41 44 8b 11 50 ff 52 20 c3`.
- Exact OnTimer bytes: `b0 01 c2 0c 00`. Exact singleton-clear bytes: `c7 05 94 b4 69 00 00 00 00 00 c3`. Exact adjustor bytes: `81 e9 a0 00 00 00 e9 9f 02 00 00 81 e9 a4 00 00 00 e9 94 02 00 00`.
- Cleanup island `[0x004ffed0,0x004fff0a)` restores the three class vtables, destroys the `+0x104` wide StringBase, clears `0x0069b494`, and transfers to Pane cleanup. It is not an independent source function.
- Core frame facts: constructor frame has local Pane pointer, four-byte argument-list scratch, one `RectBounds` local of `0x10`, unwind temporaries, saved registers/return, and two four-byte arguments. OnPaint has one `EPFTileContext` local of `0x28` plus one four-byte unwind local. Other methods have only the physical saved/return/argument rows required by their signatures.
- Xrefs: constructor callers at `0x004f7b8d`, `0x004f7bc3`, `0x004f7c07`, `0x004f7c3d`, `0x004f912b`, and `0x004f91ab`; AdvancePage caller `0x004fff52`; paint/input/timer vtable refs at `0x0061da14`, `0x0061da20`, `0x0061da24`, and `0x0061da50`; singleton refs at `0x004f69dd`, `0x004ffdd6`, `0x004ffddd`, `0x004ffefa`, `0x005023b0`, and `0x0050278d`.
- Singleton storage `0x0069b494` has stored name absent, current type `Pane *`, neither modeled code nor data head, exact bytes `00 00 00 00`, blank regular/repeatable address comments, and exact xrefs at `0x004f69dd`, `0x004ffdd6`, `0x004ffddd`, `0x004ffefa`, `0x005023b0`, and `0x0050278d`. Renderer strings `unk_69B494` and `dword_69B494` are fallback labels, not stored names. Public data-rename dry runs against both fallback labels returned `Global ... not found`; therefore no singleton rename is supported. A complete HistoryViewingPane UDT is absent, so the physical type is protected until a complete UDT is introduced independently.
- Table cluster bytes span exactly 136 bytes `[0x0061d9cc,0x0061da54)`. COL cells are four-byte data with name absent and type absent. Vtable heads retain exact decorated names, four-byte data items, and type absent.
- Primary COL `0x0064a8cc`: signature `0`, offset `0`, cdOffset `0`, type descriptor `0x00677438`, CHD `0x0064a8e0`. Secondary COL `0x0064a97c`: offset `0xa0`, same type/CHD. Tertiary COL `0x0064a990`: offset `0xa4`, same type/CHD.
- CHD `0x0064a8e0` has attributes `1`, seven bases, and base array `0x0064a8f0`: HistoryViewingPane, Pane, GrafPort, LObject, EventHandler, TimerHandler, Singleton<HistoryViewingPane>. The Singleton direct-base PMD is `+0xf8`.
- Proposed source-facing function-name collision lookups were absent/free for all eleven recommendations. Current regular/repeatable function comments are absent. Current address regular comments are absent except literal `Block` at `0x005024b6` and `0x005024c1`; those two comments are protected as current prestate unless the supervisor intentionally replaces them with the exact semantic comments below.
- Negative facts: no HistoryViewingPane UDT; no fourth table view; no modeled cleanup-island function; no ordinary thunk callers; no interior table boundary xref; no current ChattingColor generated owner; no additional class-owned function in the bounded predecessor/successor survey.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `HistoryViewingPane.cpp` | 0000JW by-file | include shell and complete compilation-unit root | TRUE | FILE | 93/94; historical 87/87 | UID00054J CPP/H shells are applied; dated command `000000025051` generated complete CPP/H, subordinate to fresh supervisor reread |
| `HistoryViewingPane` class | 000066 by-class | class declaration and method-child container | TRUE | 0000JW | 93/95; historical 88/86 | complete class H and CPP child shell are applied and physically generated |
| `0x004ffd40-0x004ffd79` | 0001A0 | private `AdvancePage` | TRUE | 000066/0000JW | 92/94; historical 88/91 | formal CPP is applied; private declaration is present in UID000066 H |
| `0x004ffd79-0x004ffd80` | no UID | seven-byte alignment | FALSE | physical neighborhood | n/a | compiler padding; no code/doc split needed |
| `0x004ffd80-0x004ffec9` | 0001A1 | constructor | TRUE | 000066/0000JW | part of current 93/95; historical 89/91 | formal CPP is applied; declaration is present on UID000066 H |
| `0x004ffec9-0x004ffed0` | 0001A1 | seven-byte post-constructor alignment | FALSE | 0001A1 | part of target | preserve exact padding evidence; no code |
| `0x004ffed0-0x004fff0a` | 0001A1 | constructor-unwind cleanup island | FALSE | 0001A1 | part of target | compiler-covered; no function/no CPP |
| `0x004fff0a-0x004fff10` | 0001A1 | six-byte alignment | FALSE | 0001A1 | part of target | no code |
| `0x004fff10-0x004fff84` | 0001A1 | `HandleKeyOrTextEvent` | TRUE | 000066/0000JW | part of current target | formal CPP is applied; virtual declaration is present on UID000066 H |
| `0x004fff84-0x004fff90` | 0001A1 | twelve-byte alignment | FALSE | 0001A1 | part of target | no code |
| `0x004fff90-0x004fff95` | 0001A1 | `OnTimer` true-return override | TRUE | 000066/0000JW | part of current target | accepted `OnTimer` source is applied; stale `IsInteractive` is retained only as rejected history |
| `0x004fff95-0x004fffa0` | 0001A1 | eleven-byte alignment | FALSE | 0001A1 | part of target | no code |
| `0x004fffa0-0x0050001a` | 0001A1 | `HandlePointerOrMouseEvent` | TRUE | 000066/0000JW | part of current target | formal CPP is applied and the reconstructed source calls `AdvancePage` |
| `0x0050001a-0x00500020` | 0001A1 | six-byte alignment | FALSE | 0001A1 | part of target | no code |
| `0x00500020-0x0050008b` | 0001A1 | `OnPaint` | TRUE | 000066/0000JW | part of current target | formal CPP with current render APIs is applied |
| `0x0050008b-0x00500090` | no UID | five-byte successor padding | FALSE | physical neighborhood | n/a | excludes BackStory successor |
| `0x005023b0-0x005023bb` | 0001A7 | constructor-EH Singleton clear helper | FALSE | 000066 | 84/90 -> 90/94 | compiler-only blank code |
| `0x005024b6-0x005024c1` | 0001AB | EventHandler deleting-destructor adjustor | FALSE | 000066 | 84/90 -> 90/94 | compiler-only blank code |
| `0x005024c1-0x005024cc` | 0001AB | TimerHandler deleting-destructor adjustor | FALSE | 000066 | same | compiler-only blank code |
| `0x00502760-0x005027cc` | 0001AG | scalar-deleting destructor wrapper | FALSE | 000066 | 88/91 -> 92/95 | retire explicit source; implicit dtor causes body |
| `0x0069b494-0x0069b498` | 0001PU/0000R3 | zero-initialized singleton pointer storage | TRUE as source global | 0000R3 -> 0000JW | 88/91 and 88/89 -> 92/95 and 92/94 | global/specializations emit via 0000R3; storage child blank |
| class layout `0x108` | 000066 | Pane + Singleton + four members | TRUE | 000066 | part of class | complete formal H and size assertion |
| primary table/COL `[0x61d9cc,0x61da18)` | 00054H by-memory | Pane/GrafPort primary view, 18 slots | FALSE | 00025Q physical / 000066 semantic | 93/95 | assigned compiler-data child; blank CPP/H |
| secondary table/COL `[0x61da18,0x61da48)` | 00054H by-memory | EventHandler view, 11 slots | FALSE | 00025Q physical / 000066 semantic | 93/95 | documented in the assigned compiler-data child; blank CPP/H |
| tertiary table/COL `[0x61da48,0x61da54)` | 00054H by-memory | TimerHandler view, two slots | FALSE | 00025Q physical / 000066 semantic | 93/95 | documented in the assigned compiler-data child; blank CPP/H |
| RTTI graph at `0x64a8cc/0x64a97c/0x64a990` | 00054I by-type/by-vtable | three COLs, CHD, seven bases | TRUE as semantic documentation | 000066 | 93/95 | assigned semantic page is applied; no raw source arrays; compiler-covered |
| `HISTORY.*` resources | 0001RF | viewer frames/resource argument | resource reconstructable | resource owner | 90/93 unchanged | support linkage, not file-owned bytes |
| `STORY.*` resources | 0001RG | viewer frames/resource argument | resource reconstructable | resource owner | 89/92 unchanged | support linkage, not file-owned bytes |
| `NPAL4.PAL` | 0001RF/0001RG support | paint palette literal | resource reconstructable | resource owner | unchanged | direct viewer dependency |
| six creation sites | 0000L0/0003H6/0003H7 | consumers/launch helpers | TRUE in MainMenu source | MainMenuPane | unchanged | excluded from History file, include History header |
| Pane ordering API | 0000A2/0000MC/0001EA | shared two-pane ordering declaration | TRUE | Pane | unchanged | accepted two-`Pane *` H signature is applied and physically generated |
| status layer global | 0004VF/0000L1 | constructor layer dependency | TRUE | MainUiGraph | unchanged | accepted `extern Layer *g_pStatusPaneLayer;` H declaration is applied and physically generated |

Inventory totals: six authored executable method bodies including constructor; one implicit authored destructor effect; four compiler executable artifacts/spans (cleanup island, clear helper, two adjustors, with scalar wrapper separately inventoried); one source global plus one physical slot; one complete class layout; three table views; three COLs plus one seven-base hierarchy; three resource dependencies; six creation call sites; all local padding and source boundaries. Every source-bearing row has a formal CPP/H or explicit compiler-covered/no-code disposition.

### Dated Historical Pre-Callback Inventory State

- At historical validator snapshot command `000000024879`, the UID0000JW CPP/H shells were still required, generated CPP was incomplete, and `HistoryViewingPane.h` was absent. UID000066 still required its class H and child shell; UID0001A0 and UID0001A1 still required formal authored-method replacements and their class-H declarations.
- At that same dated pre-callback snapshot, the physical vtable/COL child and semantic vtable page had not yet received validator-assigned UIDs and were described as a `new physical child` and `new semantic vtable page`; the Pane two-pointer H correction and status-layer extern H declaration were also still required.
- Those statements are superseded current state. The accepted callback and dated repair/refresh chain through command `000000025051` applied the shells, complete class/method CPP/H, Pane signature, status-layer extern, physical UID00054H, and semantic UID00054I. Current generated authority remains subject to fresh supervisor reread rather than permanence of that dated snapshot.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004ffd40` | caller `0x004fff52`; no ordinary callee | private key-path advance helper; mouse equivalent was inlined |
| `0x004ffd80` | callers `0x004f7b8d`, `0x004f7bc3`, `0x004f7c07`, `0x004f7c3d`, `0x004f912b`, `0x004f91ab` | four active MainMenu branches plus retained Story/History helpers |
| constructor | Pane ctor, StringBase ctor/assign, ImageLib count, rect init, AddToLayer, SetPaneOrder, ScheduleTimer | complete construction dependency graph |
| `0x004ffed0` | no function xref route; EH continuation from constructor metadata | compiler unwind only |
| `0x004fff10` | data ref from secondary vtable `0x0061da24` | key/text virtual override |
| `0x004fff90` | data ref from tertiary vtable `0x0061da50`; no callees | TimerHandler OnTimer override |
| `0x004fffa0` | data ref from secondary vtable `0x0061da20` | pointer/mouse virtual override |
| `0x00500020` | data ref from primary vtable `0x0061da14`; string ref to `NPAL4.PAL` | paint virtual override |
| `0x005023b0` | constructor EH reference `0x00601e9c` | compiler clear helper |
| `0x005024b6` | secondary vtable slot `0x0061da1c`; jumps to destructor | EventHandler receiver adjustor |
| `0x005024c1` | tertiary vtable slot `0x0061da4c`; jumps to destructor | TimerHandler receiver adjustor |
| `0x00502760` | primary vtable `0x0061d9d0`; code refs from both adjustors | scalar-deleting wrapper |
| `0x0069b494` | reads/writes at `0x4f69dd`, `0x4ffdd6`, `0x4ffddd`, `0x4ffefa`, `0x5023b0`, `0x50278d` | consumer cleanup, publish, fallback/unwind clear, normal clear |
| `0x0061d9d0` | constructor `0x4ffdf1`, cleanup `0x4ffed9`, destructor `0x50276c` | primary table installation parity |
| `0x0061da1c` | constructor `0x4ffdf7`, cleanup `0x4ffedf`, destructor `0x502772` | EventHandler table installation parity |
| `0x0061da4c` | constructor `0x4ffe01`, cleanup `0x4ffee9`, destructor `0x50277c` | TimerHandler table installation parity |
| COL cells | no ordinary refs; adjacent table-head interpretation | compiler RTTI locator words, not source globals |
| `NPAL4.PAL` | one data ref at `0x00500061` | exact viewer paint palette |
| `g_pStatusPaneLayer` | constructor read at `0x004ffe1d` | full-screen overlay layer dependency |
| `g_pScreenPane` | constructor pushes pointer before SetPaneOrder | after/before ordering dependency, not cursor manager |

No file-owned function/global lacks a caller/xref/read/write or an explicit negative disposition.

## Documentation Evidence And IDA Status

- Historical pre-callback documentation state: support docs correctly identified the broad owner, singleton, resources, and most ranges, but several names and source forms predated mature Pane/Event/Timer/ImageLib/StringBase documentation.
- Superseded claims repaired by the accepted ordinary callback: `m_totalFrames`, `m_delayTimer`, `m_bounds`, `Invalidate`, `GetFrameCount`, `Create`, `SetCursor`, `m_timerHandler.Start/Cancel`, `OnKeyDown`, `IsInteractive`, `OnMouseEvent`, `OnDraw`, `EpfFrame`, `DrawEpfFrame`, explicit `m_resourceName.Release()`, manual global clear, initial `0xffffffff`, one-pointer-plus-bool `SetPaneOrder`, and ChattingColor ownership pollution. They remain listed only as rejected history.
- Correct historical facts to preserve: earlier generated files did route some History fragments under `class_ChattingColorPane.cpp`; older sessions used raw helper names; direct Story/History wrappers can remain with no external xrefs while active inline branches call the same constructor; legacy EPD payloads are absent from current archives.
- Current IDA still uses raw names/types for executable bodies. Singleton address `0x0069b494` has stored name absent; displayed `unk_69B494`/`dword_69B494` text is renderer fallback only, while decorated vtable/RTTI names are exact stored identities and should not be normalized away. The source-facing global remains `g_pHistoryViewingPane` in reconstructed C++ without asserting that IDA currently stores or can safely apply that name.
- Generated source is validator-owned dated evidence rather than permanent authority over the live binary or support headers. Historical command `000000024879` proved the pre-callback routing defects; callback command `000000024998` proved initial ordinary assembly; repair command `000000025051` proves the latest B010-observed coherent output after stale-active-prose correction. A fresh supervisor reread remains authoritative for later gates.

## Ranked Ownership Analysis

### 1. Standalone `NexusTK/login/HistoryViewingPane.cpp/.h`

- Evidence for: one dedicated class RTTI identity; contiguous authored method family; dedicated singleton; complete class layout; three-view vtable; six external construction sites; current source-tree route; independent resource parameterization; no source overlap with adjacent classes.
- Evidence against: the class is launched only from MainMenuPane and shares login resources. This is dependency/consumer evidence, not ownership.
- Decision: accepted with strong source-shape confidence.

### 2. Fold into `MainMenuPane.cpp/.h`

- Evidence for: all six constructor calls originate in MainMenuPane source, and the class exists to present menu-selected Story/History resources.
- Evidence against: MainMenuPane has separate class identity, source root, layout, methods, and responsibilities; HistoryViewingPane has its own RTTI, vtables, singleton, fields, virtual family, and current generated file.
- Decision: rejected. MainMenu owns helper callers and adds an include only.

### 3. Fold into ChattingColor, BackStory, or NewHistory modules

- Evidence for: historical generated pollution and adjacent read-only-data order can superficially suggest shared ownership.
- Evidence against: no class RTTI, field, caller, vtable, resource, or executable-range evidence connects HistoryViewingPane internals to ChattingColor. BackStory/NewHistory are distinct dialog classes with separate vtables and resources.
- Decision: rejected and preserved as superseded history.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: retain existing `NexusTK/login/HistoryViewingPane.cpp/.h`.
- Likely full contents: source includes; HistoryViewingPane declaration; `AdvancePage`; constructor; key/mouse/timer/paint methods; singleton pointer definition and specializations.
- Related items belonging only as compiler documentation: cleanup island, clear helper, adjustors, scalar wrapper, vtables/COL/RTTI.
- Rejected from file: MainMenu launch helper definitions and resource payload ownership.
- Grouping inference: narrow standalone class module, not a broad UI aggregate.

## Source Placement

- CPP root [UID:0000JW] supplies includes and `[[CHILDREN]]`. Class [UID:000066] supplies a CPP child placeholder and the complete class declaration in H. [UID:0001A0] and [UID:0001A1] supply method definitions. [UID:0000R3] supplies global definition, Singleton specializations, and extern declaration after the class.
- H root [UID:0000JW] supplies one include guard around class/global children. It must generate a real sibling `HistoryViewingPane.h`.
- MainMenuPane remains the creation consumer and must include `HistoryViewingPane.h`; resource docs remain packaging owners.
- Pane owns the corrected shared `SetPaneOrder(Pane *, Pane *)` declaration. MainUiGraph owns the status-layer extern. HistoryViewingPane must not duplicate either declaration locally.
- Final source order: includes; class declaration in H; private/public declarations and fields; global extern; CPP includes; methods in machine/source order; global definition and Singleton specializations. Compiler artifacts remain documentation only.
- Remaining placement uncertainty: only whether the original developers placed Singleton specializations immediately after the global or near template utilities. Existing project precedent and local ownership favor the class CPP after method definitions; this does not affect behavior or emitted symbols.

## Range / Split / Padding / Reclassification Analysis

- Preserve exact method boundaries and all `0xcc` padding enumerated in the inventory. Do not widen UID0001A0 into UID0001A1 or emit the cleanup island as a helper.
- UID0001A1 remains the core aggregate covering constructor, cleanup island, four virtual methods, and internal padding. Its formal CPP emits only source-authored bodies inside that range.
- Reclassify UID0001AG from reconstructable/emitting source body to non-reconstructable/non-emitting compiler wrapper. The source cause is the class layout plus implicit virtual destructor, member destructor, Singleton base destructor, and Pane base destructor.
- Keep UID0001A7 and UID0001AB separate non-emitting compiler evidence pages.
- Split `[0x0061d9cc,0x0061da54)` from UID00025Q as one exact physical child; do not split each table view into separate physical pages because the three COL/table views form one contiguous class compiler cluster.
- Create one semantic vtable page for slots/RTTI/layout. Do not emit raw arrays or duplicate physical bytes.
- Exact predecessor is StaffsDialogPane ending at `0x0061d9cc`; exact successor is BackStoryDialogPane beginning at `0x0061da54`. No padding or shared cell exists at either boundary.
- UID0001PU remains the exact physical slot and UID0000R3 the source global; do not merge away either documentation role.

## Negative Evidence Summary

- No live HistoryViewingPane UDT exists, so this report does not recommend a partial class-UDT mutation that would obscure base facets or introduce an incomplete layout.
- No ordinary call reaches the singleton-clear helper or destructor adjustors. Their references are EH/vtable/compiler routes.
- No source-level evidence supports an explicit destructor body. The observed body is exactly compiler-regenerated member/base/deleting behavior.
- No evidence supports `IsInteractive`, custom `KeyEvent`/`MouseEvent`, embedded timer-handler member, cursor-manager setup, `Create`, `GetFrameCount`, `EpfFrame`, or `DrawEpfFrame`; mature shared APIs contradict them.
- The resource callers do not prove source ownership. They only select the wide resource name passed to the standalone class.
- Adjacency to BackStory/NewHistory/Staffs vtables does not prove shared source ownership; all carry distinct decorated types and constructors.
- A previous ChattingColor generated location does not prove original ownership. Current emitter root, class RTTI, and caller evidence reject it.
- The missing legacy `HISTORY.EPD`/`STORY.EPD` archives do not make the class unreconstructable; constructor behavior accepts names supplied by callers, and current EPF packages prove the same layout role.
- The lack of original private/member spellings does not justify raw names. Complete semantics permit realistic source-facing names with an explicit confidence cap.

## IDA Rename / Type / Comment Recommendations

The rows below are semantic Gate 2B handoff, not an executable transaction. Every action requires a fresh supervisor readback from the canonical IDB. Function regular/repeatable comments are currently absent unless explicitly noted. A destination-name collision with another entity, range/byte/xref drift, non-literal prestate mismatch, parser rejection, frame drift beyond the stated expected normalization, or comment-channel mismatch is a hard stop.

| Action ID | Exact entity/range | Literal current or dependency-stage prestate | One semantic endpoint / classification | Evidence and protections | Complete expected poststate |
| --- | --- | --- | --- | --- | --- |
| A0JW-01 | local type `HistoryViewingPane` | type absent | no change recommended | Do not create a partial UDT; preserve existing Pane/EventHandler/TimerHandler/Event/EPFTileContext types. | type remains absent; no member, base, size, or layout mutation |
| A0JW-02.1 | function `[0x004ffd40,0x004ffd79)` | name `sub_4FFD40`; type `int __thiscall(_DWORD *this)`; regular/function-regular/repeatable/function-repeatable comments absent; frame `__return_address/_UNKNOWN */+0x0/4` | public `rename` endpoint, pure function rename to `HistoryViewingPane__AdvancePage` | destination absent/free; exact 57 bytes, range, sole caller, and frame are hard stops | name `HistoryViewingPane__AdvancePage`; old type; all comments absent; exact one-row frame; bytes/range/xrefs unchanged |
| A0JW-02.2 | function `[0x004ffd40,0x004ffd79)` | name `HistoryViewingPane__AdvancePage`; type `int __thiscall(_DWORD *this)`; all comments absent; frame `__return_address/_UNKNOWN */+0x0/4` | public `set_type` endpoint with `void __thiscall HistoryViewingPane__AdvancePage(Pane *this)` | return unused; primary Pane receiver; hard stop on any frame/range/byte/xref/comment drift | exact proposed type; exact one-row frame unchanged; name retained; all comments absent; bytes/range/xrefs unchanged |
| A0JW-02.3 | function `[0x004ffd40,0x004ffd79)` | name and type from A0JW-02.2; all comment channels absent; exact one-row frame | public `set_function_comments` endpoint with `Advances the story/history frame index, clamps the first advance to frame 3, and invalidates the visible bounds.` | exact helper behavior; only function-regular channel may change | exact name/type/frame; exact function-regular comment; address regular, address repeatable, and function repeatable absent |
| A0JW-03.1 | function `[0x004ffd80,0x004ffec9)` | name `sub_4FFD80`; type `int __thiscall(int this,unsigned __int16 *)`; all comment channels absent; frame `var_2C/Pane */+0x10/4`, `var_28/_DWORD/+0x14/4`, `ArgList/char[4]/+0x18/4`, `bounds/struct RectBounds/+0x1c/0x10`, `var_10/_DWORD/+0x2c/4`, `var_C/_DWORD/+0x30/4`, `var_4/_DWORD/+0x38/4`, `__saved_registers/_DWORD/+0x3c/4`, `__return_address/_UNKNOWN */+0x40/4`, `arg_0/_DWORD/+0x44/4`, `arg_4/_DWORD/+0x48/4` | public `rename` endpoint, pure function rename to `HistoryViewingPane__Constructor` | destination absent/free; range, callers, vtable stores, locals, and frame hard-stopped | new name; exact old type/frame/comments; bytes/range/callers/stores unchanged |
| A0JW-03.2 | function `[0x004ffd80,0x004ffec9)` | name `HistoryViewingPane__Constructor`; old type; all comments absent; exact eleven-row frame from A0JW-03.1 | public `set_type` endpoint with `Pane *__thiscall HistoryViewingPane__Constructor(Pane *this, const wchar_t *resourceName)` | machine returns this and consumes one wide-string source argument; local rows are protected | exact proposed type; locals/saved/return rows unchanged; `arg_0/const wchar_t */+0x44/4`; `arg_4/_DWORD/+0x48/4` unchanged; comments absent; hard stop on any other frame normalization |
| A0JW-03.3 | function `[0x004ffd80,0x004ffec9)` | exact name/type/frame from A0JW-03.2; all comments absent | public `set_function_comments` endpoint with `Constructs the full-screen story/history viewer, publishes its Singleton, attaches it to the status layer, orders it before the screen pane, and schedules the page timer.` | complete constructor evidence; only function-regular channel may change | exact name/type/eleven-row frame; exact function-regular comment; other comment channels absent; range/bytes/xrefs unchanged |
| A0JW-04.1 | function `[0x004fff10,0x004fff84)` | name `sub_4FFF10`; type `char __thiscall(TimerHandler *this,_BYTE *)`; all comment channels absent; frame `__saved_registers/_DWORD/+0x4/4`, `__return_address/_UNKNOWN */+0x8/4`, `arg_0/_DWORD/+0xc/4` | public `rename` endpoint, pure function rename to `HistoryViewingPane__HandleKeyOrTextEvent` | destination absent/free; exact range, secondary slot, bytes, and frame hard-stopped | new name; exact old type/three-row frame/comments; range/bytes/xrefs unchanged |
| A0JW-04.2 | function `[0x004fff10,0x004fff84)` | renamed name; old type; all comments absent; exact three-row frame from A0JW-04.1 | public `set_type` endpoint with `bool __thiscall HistoryViewingPane__HandleKeyOrTextEvent(EventHandler *eventHandlerFacet, Event *event)` | secondary facet at +0xa0; exact Event UDT exists | exact proposed type; frame `__saved_registers/_DWORD/+0x4/4`, `__return_address/_UNKNOWN */+0x8/4`, `event/Event */+0xc/4`; comments absent; hard stop on any other frame drift |
| A0JW-04.3 | function `[0x004fff10,0x004fff84)` | exact name/type/frame from A0JW-04.2; all comments absent | public `set_function_comments` endpoint with `Handles key-down Enter, Escape, or Space by advancing/rescheduling the viewer or marking it for deletion.` | exact event/key branches; only function-regular channel may change | exact name/type/three-row frame; exact function-regular comment; other comments absent; bytes/range/xrefs unchanged |
| A0JW-05.1 | function `[0x004fff90,0x004fff95)` | name `sub_4FFF90`; type `char __stdcall(int,int,int)`; all comment channels absent; frame `__return_address/_UNKNOWN */+0x0/4` | public `rename` endpoint, pure function rename to `HistoryViewingPane__OnTimer` | destination absent/free; tertiary slot, five bytes, `retn 0xc`, and current frame hard-stopped | new name; exact old type/one-row frame/comments; bytes/range/xrefs unchanged |
| A0JW-05.2 | function `[0x004fff90,0x004fff95)` | renamed name; old type; all comments absent; one-row frame from A0JW-05.1 | public `set_type` endpoint with `bool __thiscall HistoryViewingPane__OnTimer(TimerHandler *timerHandlerFacet, int timerId, int arg0, int arg1)` | tertiary +0xa4 facet and exact `retn 0xc`; hard stop on parser rejection or body drift | exact proposed type; frame `__return_address/_UNKNOWN */+0x0/4`, `timerId/int/+0x4/4`, `arg0/int/+0x8/4`, `arg1/int/+0xc/4`; comments absent; bytes/range/xrefs unchanged |
| A0JW-05.3 | function `[0x004fff90,0x004fff95)` | exact name/type/four-row frame from A0JW-05.2; all comments absent | public `set_function_comments` endpoint with `Acknowledges the HistoryViewingPane timer callback.` | body always returns true; only function-regular channel may change | exact name/type/frame; exact function-regular comment; other comments absent; bytes/range/xrefs unchanged |
| A0JW-06.1 | function `[0x004fffa0,0x0050001a)` | name `sub_4FFFA0`; type `char __thiscall(TimerHandler *this,int)`; all comment channels absent; frame `__saved_registers/_DWORD/+0x4/4`, `__return_address/_UNKNOWN */+0x8/4`, `arg_0/_DWORD/+0xc/4` | public `rename` endpoint, pure function rename to `HistoryViewingPane__HandlePointerOrMouseEvent` | destination absent/free; secondary slot, exact range/bytes/frame hard-stopped | new name; exact old type/three-row frame/comments; bytes/range/xrefs unchanged |
| A0JW-06.2 | function `[0x004fffa0,0x0050001a)` | renamed name; old type; all comments absent; exact three-row frame from A0JW-06.1 | public `set_type` endpoint with `bool __thiscall HistoryViewingPane__HandlePointerOrMouseEvent(EventHandler *eventHandlerFacet, Event *event)` | event types 3/6 and secondary +0xa0 receiver | exact proposed type; frame `__saved_registers/_DWORD/+0x4/4`, `__return_address/_UNKNOWN */+0x8/4`, `event/Event */+0xc/4`; comments absent; hard stop on any other frame drift |
| A0JW-06.3 | function `[0x004fffa0,0x0050001a)` | exact name/type/frame from A0JW-06.2; all comments absent | public `set_function_comments` endpoint with `Handles left/right button release by advancing and rescheduling the viewer or marking it for deletion.` | exact state machine; only function-regular channel may change | exact name/type/three-row frame; exact function-regular comment; other comments absent; bytes/range/xrefs unchanged |
| A0JW-07.1 | function `[0x00500020,0x0050008b)` | name `sub_500020`; type `void __thiscall(GrafPort *this)`; all comment channels absent; frame `outContext/EPFTileContext/+0x8/0x28`, `var_4/_DWORD/+0x30/4`, `__saved_registers/_DWORD/+0x34/4`, `__return_address/_UNKNOWN */+0x38/4` | public `rename` endpoint, pure function rename to `HistoryViewingPane__OnPaint` | destination absent/free; primary slot, exact locals/range/bytes hard-stopped | new name; exact old type/four-row frame/comments; bytes/range/xrefs unchanged |
| A0JW-07.2 | function `[0x00500020,0x0050008b)` | renamed name; old type; all comments absent; exact four-row frame from A0JW-07.1 | public `set_type` endpoint with `void __thiscall HistoryViewingPane__OnPaint(Pane *this)` | complete-object primary receiver and current EPFTileContext type | exact proposed type; exact four-row frame unchanged; comments absent; hard stop on local/frame drift |
| A0JW-07.3 | function `[0x00500020,0x0050008b)` | exact name/type/frame from A0JW-07.2; all comments absent | public `set_function_comments` endpoint with `Looks up the current story/history frame and renders it with NPAL4.PAL into the visible bounds.` | exact calls/string xref; only function-regular channel may change | exact name/type/frame; exact function-regular comment; other comments absent; bytes/range/xrefs unchanged |
| A0JW-08 | address range `[0x004ffed0,0x004fff0a)` | not a modeled function; name absent; type absent; regular address comment absent; repeatable address comment absent | public `set_address_comments` endpoint with `HistoryViewingPane constructor-unwind cleanup: destroy resource name, clear Singleton, and continue Pane cleanup.` | preserve exact bytes/boundaries and no-function state | name/type remain absent; exact regular address comment; repeatable absent; no function/frame created |
| A0JW-09.1 | function `[0x005023b0,0x005023bb)` | name `sub_5023B0`; type `void()`; all comments absent; frame `__return_address/_UNKNOWN */+0x0/4` | public `rename` endpoint, pure function rename to `HistoryViewingPane__SingletonCleanupThunk` | destination absent/free; exact 11 bytes, EH xref, frame protected | new name; exact type/frame/comments; bytes/range/xrefs unchanged |
| A0JW-09.2 | function `[0x005023b0,0x005023bb)` | name from A0JW-09.1; type `void()`; all comments absent; exact one-row frame | public `set_function_comments` endpoint with `Compiler-generated constructor-EH Singleton clear helper for HistoryViewingPane.` | only function-regular channel may change | exact name/type/frame; exact function-regular comment; other comments absent; bytes/range/xrefs unchanged |
| A0JW-10.1 | function `[0x005024b6,0x005024c1)` | name `sub_5024B6`; type `void **__thiscall(void **this,char)`; function comments absent; address regular `Block`; address repeatable absent; frame `__return_address/_UNKNOWN */+0x0/4` | public `rename` endpoint, pure function rename to `HistoryViewingPane__EventHandlerDeletingDestructorAdjustor` | destination absent/free; exact -0xa0 adjustment/jump/table ref protected | new name; exact type/frame/comments including address regular `Block`; bytes/range/xrefs unchanged |
| A0JW-10.2 | function start `0x005024b6` | renamed name; exact old type/frame; function comments absent; address regular `Block`; address repeatable absent | public `set_address_comments` endpoint with `Compiler-generated -0xa0 EventHandler deleting-destructor adjustor for HistoryViewingPane.` | only address-regular channel may change | exact name/type/frame; address regular replaced by exact semantic text; address repeatable and function comments absent; bytes/range/xrefs unchanged |
| A0JW-11.1 | function `[0x005024c1,0x005024cc)` | name `sub_5024C1`; type `void **__thiscall(void **this,char)`; function comments absent; address regular `Block`; address repeatable absent; frame `__return_address/_UNKNOWN */+0x0/4` | public `rename` endpoint, pure function rename to `HistoryViewingPane__TimerHandlerDeletingDestructorAdjustor` | destination absent/free; exact -0xa4 adjustment/jump/table ref protected | new name; exact type/frame/comments including address regular `Block`; bytes/range/xrefs unchanged |
| A0JW-11.2 | function start `0x005024c1` | renamed name; exact old type/frame; function comments absent; address regular `Block`; address repeatable absent | public `set_address_comments` endpoint with `Compiler-generated -0xa4 TimerHandler deleting-destructor adjustor for HistoryViewingPane.` | only address-regular channel may change | exact name/type/frame; address regular replaced by exact semantic text; address repeatable and function comments absent; bytes/range/xrefs unchanged |
| A0JW-12.1 | function `[0x00502760,0x005027cc)` | name `sub_502760`; type `void **__thiscall(void **Block,char)`; all comments absent; frame `__saved_registers/_DWORD/+0x4/4`, `__return_address/_UNKNOWN */+0x8/4`, `arg_0/int/+0xc/4` | public `rename` endpoint, pure function rename to `HistoryViewingPane__ScalarDeletingDestructor` | destination absent/free; body/thunk/table refs and frame protected | new name; exact old type/frame/comments; bytes/range/xrefs unchanged |
| A0JW-12.2 | same exact function range | renamed name; exact old type/three-row frame; all comments absent | public `set_function_comments` endpoint with `Compiler-generated scalar-deleting destructor wrapper for the implicit HistoryViewingPane destructor.` | only function-regular channel may change | exact name/type/frame; exact function-regular comment; other comments absent; bytes/range/xrefs unchanged |
| A0JW-13.1 | address range `[0x0069b494,0x0069b498)` | stored name absent; renderer may display fallback `unk_69B494` or `dword_69B494`; type `Pane *`; regular/repeatable address comments absent; bytes `00 00 00 00`; neither modeled code nor data head; exact xrefs `0x004f69dd`, `0x004ffdd6`, `0x004ffddd`, `0x004ffefa`, `0x005023b0`, `0x0050278d` | deterministic no-change name disposition; do not call `rename`. The public data-rename schema is `{old,new}`; pure dry runs using each rendered fallback as `old` returned `Global 'unk_69B494' not found` and `Global 'dword_69B494' not found`, so neither fallback is a stored identity and no address-targeted rename endpoint is invented | preserve stored-name absence, exact type/width/bytes/xrefs/comments/item boundaries, and no-code/no-data-head state; hard stop if any field differs | stored name remains absent; type `Pane *`; regular/repeatable address comments remain absent; bytes `00 00 00 00`; exact six xrefs and no-code/no-data-head state unchanged |
| A0JW-13.2 | address range `[0x0069b494,0x0069b498)` | stored name absent after A0JW-13.1; renderer fallback is non-authoritative; type `Pane *`; regular/repeatable address comments absent; bytes `00 00 00 00`; neither modeled code nor data head; exact xrefs `0x004f69dd`, `0x004ffdd6`, `0x004ffddd`, `0x004ffefa`, `0x005023b0`, `0x0050278d` | public `set_address_comments` endpoint with exact schema `{database,items:[{addr,comment}]}` and literal item `{addr:"0x0069b494", comment:"HistoryViewingPane Singleton pointer; zero-initialized and cleared by Singleton destruction."}`; no rename stage | only the address-regular comment may change; hard stop on name appearance, type/width/bytes/xref/item-boundary drift, creation of code/data head, repeatable-comment change, or any write outside `0x0069b494` | stored name remains absent; type remains `Pane *`; exact bytes `00 00 00 00`, six xrefs, item boundaries, and no-code/no-data-head state remain unchanged; regular address comment is exactly `HistoryViewingPane Singleton pointer; zero-initialized and cleared by Singleton destruction.`; repeatable address comment remains absent |
| A0JW-14 | COL cell `0x0061d9cc` | name absent; type absent; four-byte data value `0x0064a8cc`; regular/repeatable comments absent | public `set_address_comments` endpoint with `HistoryViewingPane primary Pane/GrafPort complete-object locator.` | exact table start/value/data width protected | name/type absent; value/data width unchanged; exact regular comment; repeatable absent |
| A0JW-15 | primary table head `0x0061d9d0` | exact decorated HistoryViewingPane vftable name present; type absent; four-byte data head; comments absent | public `set_address_comments` endpoint with `HistoryViewingPane primary Pane/GrafPort vtable, 18 slots.` | no rename/type action; all 18 values and boundary protected | decorated name unchanged; type absent; exact regular comment; repeatable absent; all values unchanged |
| A0JW-16 | COL cell `0x0061da18` | name absent; type absent; four-byte data value `0x0064a97c`; comments absent | public `set_address_comments` endpoint with `HistoryViewingPane EventHandler secondary complete-object locator, offset 0xa0.` | exact value/data width/boundary protected | name/type absent; value unchanged; exact regular comment; repeatable absent |
| A0JW-17 | secondary table head `0x0061da1c` | exact decorated HistoryViewingPane EventHandler vftable name present; type absent; four-byte data head; comments absent | public `set_address_comments` endpoint with `HistoryViewingPane EventHandler secondary vtable, 11 slots.` | exact name, 11 values, and boundary protected | decorated name unchanged; type absent; exact regular comment; repeatable absent; values unchanged |
| A0JW-18 | COL cell `0x0061da48` | name absent; type absent; four-byte data value `0x0064a990`; comments absent | public `set_address_comments` endpoint with `HistoryViewingPane TimerHandler tertiary complete-object locator, offset 0xa4.` | exact value/data width/boundary protected | name/type absent; value unchanged; exact regular comment; repeatable absent |
| A0JW-19 | tertiary table head `0x0061da4c` | exact decorated HistoryViewingPane TimerHandler vftable name present; type absent; four-byte data head; comments absent | public `set_address_comments` endpoint with `HistoryViewingPane TimerHandler tertiary vtable, two slots.` | exact name, two values, and boundary protected | decorated name unchanged; type absent; exact regular comment; repeatable absent; values unchanged |

No source-level member/local rename is proposed without a complete current UDT/local proof. The supervisor may stop after safe function/global/comment actions; document scores do not depend on forcing a partial UDT into IDA.

## First-Draft C++ Recommendation

- Eligible: by-file shell, class declaration, AdvancePage, core authored methods, singleton global/specializations, and three shared dependency declarations/includes.
- Ineligible/no-code: cleanup island, clear helper, adjustors, scalar-deleting wrapper, physical singleton page, vtable/COL/RTTI pages, and padding.

Formal CPP for `[UID:0000JW] by-file/HistoryViewingPane.md`:

```cpp
#include "HistoryViewingPane.h"

#include "../app/Application.h"
#include "../render/EPFTileContext.h"
#include "../render/ImageLib.h"
#include "../ui/MainUiGraph.h"
#include "../ui/core/Event.h"
#include "../ui/core/ScreenPane.h"

[[CHILDREN]]
```

Formal H for `[UID:0000JW] by-file/HistoryViewingPane.md`:

```cpp
#ifndef NEXUSTK_LOGIN_HISTORYVIEWINGPANE_H
#define NEXUSTK_LOGIN_HISTORYVIEWINGPANE_H

[[CHILDREN]]

#endif
```

Formal CPP for `[UID:000066] by-class/HistoryViewingPane.md`:

```cpp
[[CHILDREN]]
```

Formal H for `[UID:000066] by-class/HistoryViewingPane.md`:

```cpp
#include "../ui/core/Pane.h"
#include "../util/Singleton.h"
#include "../util/StringBase.h"

class Event;

class HistoryViewingPane : public Pane,
                           public Singleton<HistoryViewingPane>
{
public:
    explicit HistoryViewingPane(const wchar_t *resourceName);

protected:
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    void AdvancePage();

    int m_frameIndex;
    int m_lastFrameIndex;
    unsigned int m_pageDelayMs;
    mystr::StringBase<wchar_t> m_resourceName;
};

typedef char HistoryViewingPaneSizeMustBe264[
    sizeof(HistoryViewingPane) == 0x108 ? 1 : -1];
```

Formal CPP for `[UID:0001A0]`:

```cpp
void HistoryViewingPane::AdvancePage()
{
    if (m_frameIndex >= m_lastFrameIndex)
        return;

    if (m_frameIndex < 3)
        m_frameIndex = 3;
    else
        ++m_frameIndex;

    InvalidateRect(&m_visibleBounds);
}
```

Formal H for `[UID:0001A0]`: blank; its private declaration is in UID000066 H.

Formal CPP for `[UID:0001A1]`:

```cpp
HistoryViewingPane::HistoryViewingPane(const wchar_t *resourceName)
    : Pane(0),
      m_frameIndex(0),
      m_lastFrameIndex(g_pEPFLib->GetEntryCount(resourceName) - 1),
      m_pageDelayMs(10000)
{
    m_resourceName = resourceName;

    RectBounds bounds;
    bounds.SetLTRB(0, 0, g_screenWidth, g_screenHeight);
    AddToLayer(&bounds, 0, NULL, g_pStatusPaneLayer);
    SetPaneOrder(NULL, g_pScreenPane);
    ScheduleTimer(0, m_pageDelayMs, 0, 0);
}

bool HistoryViewingPane::HandleKeyOrTextEvent(Event *event)
{
    if (event->m_type == kEventKeyDown)
    {
        unsigned char key = g_pEventMan->TranslateEventKey(
            event->m_payload.m_key.m_key,
            event->m_payload.m_key.m_modifiers);

        if (key == '\r' || key == kPaneKeyEscape || key == ' ')
        {
            if (m_frameIndex < m_lastFrameIndex)
            {
                AdvancePage();
                RemovePendingTimers();
                ScheduleTimer(0, m_pageDelayMs, 0, 0);
            }
            else
            {
                MarkForDeletion();
            }
        }
    }

    return true;
}

bool HistoryViewingPane::OnTimer(int, int, int)
{
    return true;
}

bool HistoryViewingPane::HandlePointerOrMouseEvent(Event *event)
{
    if (event->m_type != kEventLeftButtonUp &&
        event->m_type != kEventRightButtonUp)
        return true;

    if (m_frameIndex >= m_lastFrameIndex)
    {
        MarkForDeletion();
        return true;
    }

    AdvancePage();
    RemovePendingTimers();
    ScheduleTimer(0, m_pageDelayMs, 0, 0);
    return true;
}

void HistoryViewingPane::OnPaint()
{
    EPFTileContext frame;
    frame.Initialize();
    g_pEPFLib->LookupLayoutEntry(
        m_resourceName.c_str(), m_frameIndex, &frame);
    RenderTileFrame(
        &frame, &frame.bounds, &m_visibleBounds,
        0, L"NPAL4.PAL", NULL);
}
```

Formal H for `[UID:0001A1]`: blank; declarations and fields are in UID000066 H.

Formal CPP for `[UID:0000R3] by-global/g_pHistoryViewingPane.md`:

```cpp
HistoryViewingPane *g_pHistoryViewingPane = NULL;

template <>
Singleton<HistoryViewingPane>::Singleton()
{
    g_pHistoryViewingPane = static_cast<HistoryViewingPane *>(this);
}

template <>
Singleton<HistoryViewingPane>::~Singleton()
{
    g_pHistoryViewingPane = NULL;
}
```

Formal H for `[UID:0000R3]`:

```cpp
extern HistoryViewingPane *g_pHistoryViewingPane;
```

Formal H replacement for the stale method declaration on `[UID:0000A2] by-class/Pane.md`:

```cpp
    virtual void SetPaneOrder(Pane *beforePane, Pane *afterPane);
```

Formal H addition for `[UID:0004VF] by-global/g_pStatusPaneLayer.md` through `MainUiGraph.h`:

```cpp
extern Layer *g_pStatusPaneLayer;
```

Formal CPP include addition for `[UID:0000L0] by-file/MainMenuPane.md`:

```cpp
#include "HistoryViewingPane.h"
```

No third-party import applies. The code preserves exact behavior while using current project APIs and plausible period source. Inferred names replace raw labels; compiler-only ABI material is intentionally omitted. The source style matches current subsystem conventions and remains subordinate to exact binary behavior.

## Final Recommendation

- Preserve the applied ordinary state: UID0000JW standalone ownership, UID00054J file shell, UID000066 class declaration/container, UID0001A0/UID0001A1 source methods, UID0000R3 singleton source, and compiler-only pages with blank output.
- Preserve validator-assigned UID00054H physical and UID00054I semantic vtable documentation without raw source arrays; UID00025Q remains only the broad support index.
- Preserve the applied Pane/MainUiGraph/MainMenu dependency declarations and the resource/launch-helper ownership boundaries. Generated files remain validator-owned dated readback, never direct edit targets.
- Supervisor-owned next work is limited to independent Gate 2A verification, exact manual coverage, fresh Gate 2B prestate/action verification, and lifecycle authority.
- This report does not assert execution/archive state; that state derives only from the current artifact path and validator-owned history.
- B010 applied the accepted ordinary callback and no supervisor-owned coverage, IDA, or lifecycle mutation. Lifecycle authority derives only from the report's current path plus validator-owned status/history metadata.

## Recommended Target Doc Changes

- Applied: `by-file/HistoryViewingPane.md` is `93/94` with exhaustive standalone inventory and UID00054J shell route.
- Applied: `by-class/HistoryViewingPane.md` is `93/95` with exact inheritance/layout/method/vtable/RTTI evidence and complete formal CPP/H.
- Applied: UID0001A0 is `92/94` and UID0001A1 is `93/95`, with accepted formal source, exact evidence, and deterministic class child order.
- Applied: UID0001A7/UID0001AB are `90/94` compiler-only pages; UID0001AG is `92/95`, non-reconstructable/non-emitting, with the old explicit body retained only as rejected history.
- Applied: UID0000R3 is `92/94` with exact global/specialization CPP and extern H; UID0001PU is `92/95`, zero-filled, canonically owned by UID0000R3, and non-emitting physical evidence.

## Recommended Support Doc Changes

- Applied: UID00025Q retains `86/92` and links exact compiler child UID00054H and semantic class-owned UID00054I; no UID00025Q report coverage is claimed.
- Applied: UID00054H is the complete non-emitting 136-byte physical three-view/COL page; UID00054I is the complete non-emitting semantic slots/RTTI/layout/source-cause page.
- Applied and independently repaired: the mixed aggregate's active inventory now identifies UID00054H/UID00054I rather than a pending split; resource pages preserve scores while using current `OnPaint`, `LookupLayoutEntry`, `RenderTileFrame`, `NPAL4.PAL`, standalone source, and retained launcher boundaries. Superseded predecessor-only and `OnDraw`/one-off-render-helper assumptions are isolated in explicit historical sections with contradiction and replacement reasons.
- Verified already present: UID00019R plus UID0003H6/UID0003H7 remain MainMenu-owned launch support. MainMenu class/file docs now provide the complete History header include and six-consumer boundary.
- Applied: Pane class/file/core carry the exact two-Pane `SetPaneOrder` ABI. UID0004VF and MainUiGraph carry the status-layer definition/header route. Mature Event/Timer/ImageLib/EPFTileContext/GrafPort/StringBase/Singleton/Application/ScreenPane declarations were consumed without duplicate local definitions.
- Generated CPP/H were never edited directly; commands `000000024995` and `000000024998` refreshed them through validator-owned assembly.

## Score And Metadata Recommendation

| UID | Current | Recommended | Metadata/source reason |
| --- | --- | --- | --- |
| 0000JW | Historical `87/87`, reconstructability blank | Applied `93/94`; standalone owner with UID00054J shell | whole-file/source/header/ownership closure |
| 000066 | Historical `88/86`, owner/emitter 0000JW | Applied `93/95`, owner 0000JW, emitter 00054J position 10 | full layout/method/RTTI/formal H |
| 0001A0 | Historical `88/91` | Applied `92/94`, emitter 000066 position 10 | exact source/API correction |
| 0001A1 | Historical `89/91` | Applied `93/95`, emitter 000066 position 20 | complete range/method/dependency source |
| 0001A7 | Historical `84/90` | Applied `90/94`, FALSE/no emitter | exact EH-helper proof |
| 0001AB | Historical `84/90` | Applied `90/94`, FALSE/no emitter | exact adjustor proof |
| 0001AG | Historical `88/91`, TRUE/emitting | Applied `92/95`, FALSE/no emitter | entire body compiler-covered |
| 0000R3 | Historical `88/89` | Applied `92/94`, emitter 00054J position 20 | global/specialization source closure |
| 0001PU | Historical `88/91`, empty-emitting | Applied `92/95`, owner 0000R3/no emitter | exact zero bytes/xrefs/source route |

- Support-only metadata recommendation, not report coverage: [UID:00025Q] remains `86/92`, `RECONSTRUCTABLE:FALSE`; the mixed aggregate stays broad while the exact HistoryViewingPane child/link fixes its local inventory completeness.
- Coverage routing for the allocated support pages is exact and supervisor-owned: UID00054H is inserted in `by-memory/-coverage-report.md` immediately after UID0004VJ and before UID0004WA; UID00054I is inserted in `by-type/by-vtable/-coverage-report.md` immediately after UID0003HK and before UID0001XQ. Section 28 contains both complete literal rows.
- Reason not higher: exact original private/member/parameter spellings are stripped, and supervisor-owned IDA/manual coverage verification remains outside B010 authority. Vtable UID allocation, ordinary implementation, and generated readback are complete.
- Reason not lower: ranges, behavior, class layout, all callers/xrefs, compiler artifacts, resources, source owner, CPP/H route, and formal source are closed with live canonical evidence.
- Every former blocker was actively researched: wrong virtual names resolved by vtable facets; destructor ambiguity resolved by member/base order; singleton ambiguity resolved by direct EBO RTTI; source fold resolved by dedicated class evidence; missing header resolved with full declaration contract; shared API mismatch resolved by body/call-site analysis; vtable gap resolved with exact split plan.

## Open Questions With Attempted Resolution

- Exact original private/member spellings: no symbols or source strings survive. Binary semantics, surrounding naming style, and current mature support headers support the chosen names at high probability. This caps confidence but does not justify raw labels.
- Original placement of Singleton specializations: constructor/destructor lowering and project precedent prove their source cause; placement after globals in `HistoryViewingPane.cpp` is the most plausible local choice. No behavior or symbol difference follows from nearby source order.
- Source helper call versus mouse inlining: one machine caller and byte-equivalent mouse logic were checked. One source helper used by both paths is the more human, nonduplicated source; optimizer inlining accounts for the one-xref result.
- `OnTimer` purpose: exact tertiary slot/signature/body prove the override and its true return. No additional action is present; inventing page advancement would violate the binary. It remains a minimal acknowledgment override.
- Legacy EPD payload absence: package/resource docs were checked. The executable accepts caller-provided resource names, so source reconstruction is complete; only archival resource packaging for unavailable legacy files remains outside this source-file assignment.
- Exact SetPaneOrder parameter names: body and all calls prove two Pane pointers and ordering semantics; `beforePane`/`afterPane` are the highest-probability names. Exact original names remain unavailable without source/PDB.
- Source-facing singleton name versus IDA identity: six lifecycle xrefs, zero-filled storage, and the owning global documentation support `g_pHistoryViewingPane` in reconstructed C++, but public inspection proves the live IDB stores no name at `0x0069b494`. Both `unk_69B494` and `dword_69B494` are renderer fallbacks, and pure `{old,new}` rename dry runs fail because neither is a stored global. The deterministic resolution is no IDA rename and one direct regular address comment while preserving name absence, `Pane *`, bytes, xrefs, boundaries, and the no-data-head state.
- No reasonable in-scope question remains as generic future investigation. The remaining uncertainties affect naming confidence or archival payload availability, not behavior, ownership, source placement, reconstructability, or formal source eligibility.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

B010 read the current manual rows and did not edit any coverage file. Physical line positions are mutable and are not permanent authority. After implementation verification, the supervisor should replace the exact UID-keyed rows with:

- `by-file/-coverage-report.md`, replace UID0000JW row with: `- [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md) : reconstructable : 93% : very-strong : Complete standalone login/HistoryViewingPane.cpp/.h source family with exhaustive authored-method, implicit-destruction, Singleton/global, three-view vtable/RTTI, resource, launch-caller, CPP/H dependency, generated-output, and compiler-only cleanup/thunk inventory; source behavior and ownership are closed, with original private spellings as the remaining confidence cap.`
- `by-class/-coverage-report.md`, replace UID000066 row with: `- [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md) : reconstructable : 93% : very-strong : Pane plus direct Singleton<HistoryViewingPane> class, exact 0x108 layout, complete constructor/input/timer/paint/private-helper inventory, implicit virtual destructor disposition, three-view vtables and seven-base RTTI, complete formal H, and standalone UID0000JW owner/emitter route.`
- `by-memory/-coverage-report.md`, replace UID0001A0 row with: `    - [UID:0001A0][0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage](by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md) : reconstructable : 92% : very-strong : Exact private AdvancePage helper with one key-path caller, byte-complete clamp/increment behavior, m_frameIndex/m_lastFrameIndex semantics, inherited m_visibleBounds invalidation, mouse-path inline equivalence, exact padding, and corrected formal source.`
- `by-memory/-coverage-report.md`, replace UID0001A1 row with: `    - [UID:0001A1][0x004ffd80-0x0050008b.HistoryViewingPaneCore](by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md) : reconstructable : 93% : very-strong : Complete constructor, constructor-unwind island, HandleKeyOrTextEvent, OnTimer, HandlePointerOrMouseEvent, OnPaint, padding, six callers, exact frames/xrefs, full-screen status-layer/screen ordering, timer, EPF/resource and NPAL4.PAL behavior, and source-ready current Pane/Event/Timer/ImageLib formal C++.`
- `by-memory/-coverage-report.md`, replace UID0001A7 row with: `    - [UID:0001A7][0x005023b0-0x005023bb.HistoryViewingPaneSingletonClear](by-memory/0x005023b0-0x005023bb.HistoryViewingPaneSingletonClear.md) : not_reconstructable : 90% : very-strong : Exact eleven-byte constructor-EH Singleton clear helper with one EH reference, no ordinary source body, and deterministic compiler-covered relation to Singleton<HistoryViewingPane>::~Singleton().`
- `by-memory/-coverage-report.md`, replace UID0001AB row with: `    - [UID:0001AB][0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks](by-memory/0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks.md) : not_reconstructable : 90% : very-strong : Exact -0xa0 EventHandler and -0xa4 TimerHandler deleting-destructor adjustors with vtable refs, scalar-wrapper jumps, protected ABI identity, and blank compiler-covered C++.`
- `by-memory/-coverage-report.md`, replace UID0001AG row with: `    - [UID:0001AG][0x00502760-0x005027cc.HistoryViewingPaneDestructor](by-memory/0x00502760-0x005027cc.HistoryViewingPaneDestructor.md) : not_reconstructable : 92% : very-strong : Exact scalar-deleting destructor wrapper regenerated by the implicit virtual HistoryViewingPane destructor, wide StringBase member destruction, Singleton clear, Pane destruction, delete flags and secondary adjustors; formal C++ is intentionally blank.`
- `by-global/-coverage-report.md`, replace UID0000R3 row with: `- [UID:0000R3][g_pHistoryViewingPane](by-global/g_pHistoryViewingPane.md) : reconstructable : 92% : very-strong : Zero-initialized HistoryViewingPane Singleton pointer with six exact lifecycle refs, source global definition/extern, direct empty-base Singleton constructor/destructor specializations, constructor-unwind and normal-destruction closure, and standalone UID0000JW source order.`
- `by-memory/-coverage-report.md`, replace UID0001PU row with: `    - [UID:0001PU][0x0069b494-0x0069b498.g_pHistoryViewingPane](by-memory/0x0069b494-0x0069b498.g_pHistoryViewingPane.md) 0x0069b494-0x0069b498 | global pointer | g_pHistoryViewingPane : reconstructable : 92% : very-strong : Exact four-byte zero-initialized HistoryViewingPane Singleton slot with six current refs, UID0000R3 source owner/emitter, constructor publish, unwind/clear/destructor lifecycle, consumer cleanup read, and blank physical-child C++.`
- Support-only manual-row maintenance, with no UID00025Q report coverage: in `by-memory/-coverage-report.md`, insert into the existing UID00025Q row after the sentence identifying HistoryViewingPane at `0x0061d9cc`: `The HistoryViewingPane addition creates one exact nested compiler-only child for [0x0061d9cc,0x0061da54), with three vtable/COL views, 18/11/2 slots, constructor/unwind/destructor stores, seven-base RTTI, direct Singleton +0xf8 EBO, semantic owner UID000066, exact StaffsDialog predecessor and BackStory successor, and blank non-emitting C++.`
- `by-resource/-coverage-report.md`, replace UID0001RF row with: `- [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md) : reconstructable : 90% : very-strong : Main-menu history resources with exact literals/xrefs and package evidence; HISTORY.EPF/HISTORY.EPD are constructor-selected HistoryViewingPane inputs, NPAL4.PAL is the viewer paint palette, HISTORYN belongs to the newer dialog family, and missing legacy EPD payloads remain an archival packaging limitation rather than a source-code blocker.`
- `by-resource/-coverage-report.md`, replace UID0001RG row with: `- [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md) : reconstructable : 89% : very-strong : STORY.EPF/STORY.EPD resource family and retained MainMenu launch-helper evidence for standalone HistoryViewingPane, with exact constructor parameter flow, NPAL4.PAL viewer paint role, BackStory/NewHistory boundary, and missing legacy STORY.EPD payload preserved as packaging history.`
- `by-memory/-coverage-report.md`, insert immediately after the existing UID0004VJ row and before UID0004WA under UID00025Q: `        - [UID:00054H][0x0061d9cc-0x0061da54.HistoryViewingPaneVtableData](by-memory/0x0061d9cc-0x0061da54.HistoryViewingPaneVtableData.md) 0x0061d9cc-0x0061da54 | compiler vtable/RTTI data | HistoryViewingPaneVtableData : not_reconstructable : 93% : very-strong : Exact 136-byte HistoryViewingPane primary Pane/GrafPort, EventHandler, and TimerHandler vtable/COL cluster physically nested under mixed aggregate UID00025Q and semantically owned by class UID000066, with 18/11/2 slots, three COLs, seven-base RTTI, direct Singleton +0xf8 EBO, complete constructor/unwind/destructor stores, exact StaffsDialogPane predecessor and BackStoryDialogPane successor, source regenerated through UID00054J from the human class declaration, and blank non-emitting CPP/H.`
- `by-type/by-vtable/-coverage-report.md`, insert immediately after UID0003HK GroupPostInputPaneVtables and before UID0001XQ HumanImageLibVtable: `- [UID:00054I][HistoryViewingPaneVtables](by-type/by-vtable/HistoryViewingPaneVtables.md) : reconstructable : 93% : very-strong : Non-emitting semantic HistoryViewingPane primary Pane/GrafPort, EventHandler, and TimerHandler vtable/RTTI inventory owned by class UID000066 and sourced through standalone file UID0000JW/file shell UID00054J, with exact physical backing UID00054H, 18/11/2 slots, four authored virtual roles, compiler destructor/adjustors, three COLs, seven-base hierarchy, direct Singleton +0xf8 EBO, complete lifecycle stores, and declaration-driven regeneration without raw table source.`

These are supervisor-owned manual edits because concurrent B-agent coverage writes are forbidden and physical coverage rows are shared collision points.

## Follow-Up Actions

- Supervisor: perform fresh exact-artifact Gate 1 and independent Gate 2A verification against the ordinary paths, hashes, receipts, and generated readback below.
- Supervisor: verify/apply C0JW-054 manual coverage without B010 coverage writes, including the exact UID00054H/UID00054I literal rows and anchors in Section 28, then perform fresh C0JW-055 through C0JW-057 IDA prestates and only supported Section 21 actions: executable-body function renames/types/comments, direct singleton address comment with stored name remaining absent, compiler-table comments, and no partial UDT.
- Lifecycle execution/archive authority remains exclusively supervisor-owned and derives from the current artifact path plus validator-owned history. B010 did not run `execute_report` or any lifecycle probe.
- No A-agent task is required. No new B010 target derives from this report; any later assignment derives solely from current supervisor state.

## Confidence

- Ownership/source placement: very strong.
- Runtime behavior and range inventory: very strong.
- Layout/inheritance/vtable/RTTI: very strong to original-proof.
- Formal source behavior: very strong; exact original spelling/style: strong.
- Score recommendation: very strong.
- Ordinary implementation confidence: very strong; scoped validators returned `ok:1`, final coherent generation completed, and physical CPP/H readback matched the accepted inventory with a clean negative scan.
- Remaining uncertainty is limited to stripped private/parameter spellings, exact Singleton-specialization source position, unavailable legacy EPD payloads, and supervisor-owned IDA/coverage verification. None changes runtime behavior, owner/emitter route, reconstructability, class layout, or the applied formal source.

## Validator Results

### Gate 2A Stale-Active-Prose Repair Matrix

| Claim | Repaired ordinary destination(s) | Current accepted state and preserved history |
| --- | --- | --- |
| `C0JW-001` | `by-file/HistoryViewingPane.md` | Active inventory now separates A0/A1 authored source, R3 source global, and A7/AB/AG compiler products; earlier mixed/current-looking inventory is preserved only in `Historical Superseded Assumptions` and the dated generated audit. |
| `C0JW-005` | `by-class/HistoryViewingPane.md` | Active layout is Pane plus direct empty Singleton, exact `+0xf8/+0xfc/+0x100/+0x104` members and `0x108` size; old generic `SimpleUString`/field names are historically explained and replaced. |
| `C0JW-006` | `by-class/HistoryViewingPane.md` | Active method inventory uses constructor, AdvancePage, HandleKeyOrTextEvent, OnTimer, HandlePointerOrMouseEvent, OnPaint, and implicit destruction; old virtual labels and explicit destructor are historical only. |
| `C0JW-007` | `by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md` | Active behavior uses `m_lastFrameIndex` and `InvalidateRect(&m_visibleBounds)`; `m_totalFrames`, `m_bounds`, and `Invalidate` are preserved with the evidence that disproved them. |
| `C0JW-008` | `by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md` | Constructor prose now matches formal source: base initialization, GetEntryCount, accepted members, status layer, screen ordering, and timer schedule; raw constructor writes remain physical evidence rather than authored statements. |
| `C0JW-009` | `by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md` | Active key/text method uses Event/EventMan translation and accepted key constants; `OnKeyDown`/ctype draft source is historicalized. |
| `C0JW-010` | `by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md` | Active `0x004fff90` role is `OnTimer(int,int,int)` from the TimerHandler view; `IsInteractive` is explicitly superseded. |
| `C0JW-011` | `by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md` | Active pointer/mouse method uses accepted event names, `AdvancePage`, timer removal/reschedule, and deletion; the `OnMouseEvent`/manual-inline draft is historical. |
| `C0JW-012` | `by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md`; both resource pages | Active paint route is `OnPaint` plus `EPFTileContext`, `LookupLayoutEntry`, `RenderTileFrame`, and `NPAL4.PAL`; `OnDraw`/GetFrame/DrawEpfFrame remains explicit rejected history. |
| `C0JW-013` | `by-global/g_pHistoryViewingPane.md`; physical UID0001PU page | Active source route contains the NULL definition/extern and physical zero-filled storage; old unresolved/no-C++ and `0xffffffff` statements are historicalized. |
| `C0JW-014` | `by-global/g_pHistoryViewingPane.md`; physical UID0001PU page | Active Singleton specializations explain publication/clear and emit through UID00054J; manual class-method assignment and score-threshold deferral are superseded. |
| `C0JW-015` | `by-memory/0x00502760-0x005027cc.HistoryViewingPaneDestructor.md`; class/file/core pages | Active disposition is implicit destruction and non-emitting compiler scalar wrapper; the old authored `Release`/manual-clear body is preserved verbatim with contradiction and replacement reasoning. |
| `C0JW-019` | `by-memory/0x00502760-0x005027cc.HistoryViewingPaneDestructor.md` | Vtable/member/Singleton/Pane/delete mechanics are current compiler evidence, not a source-ready body; owner/emitter rejection is explicit. |
| `C0JW-020` | `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md` | Active inventory names exact physical child UID00054H and semantic UID00054I; the former predecessor-only/pending-split state is retained in an explicit historical section. |
| `C0JW-023` | `by-resource/main-menu-history-resources.md` | Active HISTORY/STORY viewer resource route uses OnPaint/LookupLayoutEntry/RenderTileFrame and retains packaging ownership; old render names are historical only. |
| `C0JW-031` | class/file/core pages | Active Event/EventMan and TimerHandler APIs replace synthetic KeyEvent/MouseEvent and embedded timer-member calls; old names are isolated as source-shape history. |
| `C0JW-032` | core and both resource pages | Active ImageLib/EPFTileContext/GrafPort route replaces EpfFrame/GetFrame/DrawEpfFrame without losing exact resource/xref evidence. |
| `C0JW-033` | class/file/Advance/core pages | Active human names are `m_lastFrameIndex`, `m_pageDelayMs`, `m_resourceName`, and `AdvancePage`; old offset-derived names are preserved with replacement rationale. |
| `C0JW-034` | class/file/core/global-storage pages | ChattingColor ownership is rejected in active ownership sections and retained only as dated generated-routing pollution. |
| `C0JW-035` | `by-file/HistoryViewingPane.md`; core generated-state section | Exact pre-callback command `000000024879`, CPP hash/size/lines, three empty defects, stale A1/A1G source, and missing H are preserved as dated historical evidence subordinate to dynamic output. |
| `C0JW-049` | mixed aggregate UID00025Q | Current summary and inventory agree on the exact UID00054H/UID00054I split while keeping `86/92`, FALSE, support-only status. |
| `C0JW-050` | both resource pages | Current viewer method/API names are active; resource scores, literals, xrefs, package boundaries, and legacy payload questions remain intact. |
| `C0JW-059` | all repaired destinations above | Valuable old claims were moved under explicit `Historical Superseded Assumptions`/`Historical Change Log` headings with why they were plausible, contradicting evidence, and accepted replacements; no evidence was pruned. |

- Exact working directory for every receipt: `E:\NTK\GhidraBridge\source-3\project-documentation`. Every command exited `0`, reported `ok:1`, and produced no target-specific warning or error. Commands `000000024939` through `000000024997` deferred generation unless explicitly marked completed; command `000000024998` is the dated initial callback snapshot. Gate 2A repair commands `000000025041` through `000000025050` deferred generation, and command `000000025051` is the latest dated coherent B010-observed repair snapshot. All generated snapshots remain subordinate to fresh dynamic supervisor reread.

| Command ID | Timestamp | Exact single-line command | Result / refresh / side effects |
| --- | --- | --- | --- |
| `000000024939` | `2026-08-16T07:52:25-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x0061d9cc-0x0061da54.HistoryViewingPaneVtableData.md' --apply --queue-timeout 240` | UID00054H assigned; `ok:1`; generated refresh deferred; UID/reference/registry/stat metadata updated. |
| `000000024949` | `2026-08-16T07:53:36-04:00` | `python .\tools\validator.py --mode file --file 'by-type\by-vtable\HistoryViewingPaneVtables.md' --apply --queue-timeout 240` | UID00054I assigned; `ok:1`; generated refresh deferred; UID/reference/registry/stat metadata updated. |
| `000000024958` | `2026-08-16T07:55:08-04:00` | `python .\tools\validator.py --mode file --file 'by-item\HistoryViewingPaneFileShell.md' --apply --queue-timeout 240` | UID00054J assigned; `ok:1`; generated refresh deferred; UID/reference/registry/stat metadata updated. |
| `000000024959` | `2026-08-16T07:59:03-04:00` | `python .\tools\validator.py --mode file --file 'by-class\HistoryViewingPane.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; score/emitter/formal-code registry updated. |
| `000000024960` | `2026-08-16T07:59:06-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; score/emitter/formal-code registry updated. |
| `000000024961` | `2026-08-16T07:59:08-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x004ffd80-0x0050008b.HistoryViewingPaneCore.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; score/emitter/formal-code registry updated. |
| `000000024962` | `2026-08-16T07:59:11-04:00` | `python .\tools\validator.py --mode file --file 'by-global\g_pHistoryViewingPane.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; score/emitter/CPP/H registry updated. |
| `000000024963` | `2026-08-16T07:59:13-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x0069b494-0x0069b498.g_pHistoryViewingPane.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; score and empty-emitter removal registered. |
| `000000024969` | `2026-08-16T08:00:33-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x005023b0-0x005023bb.HistoryViewingPaneSingletonClear.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; score metadata updated. |
| `000000024970` | `2026-08-16T08:00:36-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; score metadata updated. |
| `000000024971` | `2026-08-16T08:00:39-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x00502760-0x005027cc.HistoryViewingPaneDestructor.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; owner/reconstructable/emitter/formal-code reclassification registered. |
| `000000024972` | `2026-08-16T08:00:41-04:00` | `python .\tools\validator.py --mode file --file 'by-file\HistoryViewingPane.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; scores and UID references updated. |
| `000000024973` | `2026-08-16T08:00:43-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; UID00054H/00054I references indexed. |
| `000000024979` | `2026-08-16T08:02:11-04:00` | `python .\tools\validator.py --mode file --file 'by-resource\main-menu-history-resources.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; resource stats row updated. |
| `000000024980` | `2026-08-16T08:02:23-04:00` | `python .\tools\validator.py --mode file --file 'by-resource\main-menu-story-resources.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; resource stats row updated. |
| `000000024981` | `2026-08-16T08:02:35-04:00` | `python .\tools\validator.py --mode file --file 'by-class\MainMenuPane.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; formal CPP registry updated. |
| `000000024982` | `2026-08-16T08:02:48-04:00` | `python .\tools\validator.py --mode file --file 'by-file\MainMenuPane.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; helper UID links normalized. |
| `000000024990` | `2026-08-16T08:03:55-04:00` | `python .\tools\validator.py --mode file --file 'by-class\Pane.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; exact formal H registered. |
| `000000024991` | `2026-08-16T08:04:03-04:00` | `python .\tools\validator.py --mode file --file 'by-file\Pane.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; documentation indexed. |
| `000000024992` | `2026-08-16T08:04:09-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x00544460-0x00545086.PaneCore.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; documentation indexed. |
| `000000024993` | `2026-08-16T08:04:14-04:00` | `python .\tools\validator.py --mode file --file 'by-global\g_pStatusPaneLayer.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; formal H/reference route indexed. |
| `000000024994` | `2026-08-16T08:04:24-04:00` | `python .\tools\validator.py --mode file --file 'by-file\MainUiGraph.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; support links indexed. |
| `000000024995` | `2026-08-16T08:04:50-04:00` | `python .\tools\validator.py --mode file --file 'by-file\HistoryViewingPane.md' --apply --wait-generated --queue-timeout 240` | `ok:1`; generated refresh completed; global diagnostics were unrelated existing marker/no-code rows (`6/72/61/1`) and no target error. Physical readback exposed and triggered the two ordinary support-header fixes recorded next. |
| `000000024996` | `2026-08-16T08:06:43-04:00` | `python .\tools\validator.py --mode file --file 'by-global\g_pStatusPaneLayer.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; independent `Layer` forward plus extern registered. |
| `000000024997` | `2026-08-16T08:06:54-04:00` | `python .\tools\validator.py --mode file --file 'by-class\MainMenuPane.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; empty H child marker removed. |
| `000000024998` | `2026-08-16T08:07:20-04:00` | `python .\tools\validator.py --mode file --file 'by-file\HistoryViewingPane.md' --apply --wait-generated --queue-timeout 240` | `ok:1`; generated refresh completed; global unrelated diagnostics remained `6` fallback inserts, `72` marker-missing, `61` no-code emitters, and `1` header-marker warning; target negative scan returned zero. Registry rebuilt with `5711` nodes/`4428` edges; generated metadata and research tracker refreshed as validator side effects. |
| `000000025041` | `2026-08-16T08:44:52-04:00` | `python .\tools\validator.py --mode file --file 'by-file\HistoryViewingPane.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; current whole-file inventory, explicit historical sections, and dated pre-callback generated audit registered. |
| `000000025042` | `2026-08-16T08:47:39-04:00` | `python .\tools\validator.py --mode file --file 'by-class\HistoryViewingPane.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; accepted fields/methods/layout/implicit-destruction prose and superseded-history separation registered. |
| `000000025043` | `2026-08-16T08:49:31-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; active last-index/visible-bounds/InvalidateRect behavior and historical old-field/API evidence registered. |
| `000000025044` | `2026-08-16T08:51:19-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x004ffd80-0x0050008b.HistoryViewingPaneCore.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; accepted constructor/event/timer/paint prose, compiler no-code boundaries, scores, and superseded source-shape history registered. |
| `000000025045` | `2026-08-16T08:51:58-04:00` | `python .\tools\validator.py --mode file --file 'by-global\g_pHistoryViewingPane.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; resolved singleton CPP/H placement and score rationale registered; validator normalized UID00054J reference to its by-item file-shell path. |
| `000000025046` | `2026-08-16T08:52:33-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x0069b494-0x0069b498.g_pHistoryViewingPane.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; parent-emitted no-duplication disposition and historical `0xffffffff` correction registered. |
| `000000025047` | `2026-08-16T08:53:31-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x00502760-0x005027cc.HistoryViewingPaneDestructor.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; compiler-only implicit-destruction disposition and verbatim rejected authored-destructor history registered. |
| `000000025048` | `2026-08-16T08:54:15-04:00` | `python .\tools\validator.py --mode file --file 'by-memory\0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; active UID00054H/UID00054I inventory replaced the superseded pending-split row. |
| `000000025049` | `2026-08-16T08:54:47-04:00` | `python .\tools\validator.py --mode file --file 'by-resource\main-menu-history-resources.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; `OnPaint`/`LookupLayoutEntry`/`RenderTileFrame` current route and historical old-render naming registered; resource stats row updated. |
| `000000025050` | `2026-08-16T08:55:14-04:00` | `python .\tools\validator.py --mode file --file 'by-resource\main-menu-story-resources.md' --apply --queue-timeout 240` | `ok:1`; generated refresh deferred; story-viewer `OnPaint`/render route and historical generic-draw naming registered; resource stats row updated. |
| `000000025051` | `2026-08-16T08:56:08-04:00` | `python .\tools\validator.py --mode file --file 'by-file\HistoryViewingPane.md' --apply --wait-generated --queue-timeout 240` | `ok:1`; generated refresh completed; registry rebuilt with `5713` nodes/`4428` edges; unrelated global diagnostics were `6` fallback inserts, `72` child-marker-missing rows, `61` no-code emitters, and `1` header-marker warning; generated metadata/tracker refreshes were validator side effects and no target-specific error occurred. |

- Final repair physical readback under command `000000025051`: `HistoryViewingPane.cpp` SHA256 `A32C735CA1EEF01325D6FC3479A02F24FC2382E359C43D4BBD49D6722F360245`, `3374` bytes, `121` lines; `HistoryViewingPane.h` `10EB8180DE4847605FA7376BECF85D6D060236B277D29E22D63D56B1CE7A048C`, `1468` bytes, `45` lines; `MainMenuPane.cpp` `F5D3ADF56922D528A3B4D78189A3F93AB21A35531A89B697CF7DF7E0EBE83DCC`, `31428` bytes, `857` lines; `MainMenuPane.h` `EBCEE983CC9EC39F38DEBFA70074B65759E72E35190A2D6C28504B6AAD22406B`, `1538` bytes, `45` lines; `Pane.h` `0E1D04DFE4791A2EC243B9800852FD759ACB66CB72A2482FCD7654DD0929B375`, `3103` bytes, `85` lines; `MainUiGraph.h` `9D6351421527FC0607033A49D82916D363947F6421BDF4D2713B6C6AB7681365`, `784` bytes, `27` lines.
- Physical reconciliation: exact source/class/global order, six authored method definitions, complete H declaration/size check, one singleton definition/extern, MainMenu include, two-Pane signature, and status-layer declaration are present. No explicit History destructor, UID0001A7/0001AB/0001AG/0001PU marker, empty emitter, `[[No Children Attached]]`, TODO, placeholder, stub, or raw vtable/COL/RTTI material remains in the six checked artifacts.

## Changed Files

- Created ordinary pages: `by-memory/0x0061d9cc-0x0061da54.HistoryViewingPaneVtableData.md` SHA256 `87AEBC5C52191B6AF16918FE673A5E2DE74116EC08EE9B67D46047EC3C5448F8`; `by-type/by-vtable/HistoryViewingPaneVtables.md` `D309ACBA349781887EE04A9A977EB1751009F178A578F5F4E89EA9AD0631054A`; `by-item/HistoryViewingPaneFileShell.md` `679003D2BC3F58ECA858643AE36E1284020ECEC2CD361F07D3AEE366DC1826EB`.
- Modified target/source pages, current post-repair hashes: `by-file/HistoryViewingPane.md` `65F4F8428E6F1F2B3BAB7AD4399707835BE11C4A35870D384A2F13876C7B2C06`; `by-class/HistoryViewingPane.md` `824D544E6C2F3D5878C076AAE9FD5DE64432C1DEEDA91738D2BC1D2C0AC237F3`; `by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md` `A05252C4476BC9DE21CEA5CBB71BEFBBAC9318FD8A9FD645D339647AAE562245`; `by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md` `922ACA728F316E833F94555C9BF1E33A91FB937EA98D4DD9408ED5EC55FC5066`; `by-memory/0x005023b0-0x005023bb.HistoryViewingPaneSingletonClear.md` `17D9CA7147070AB41199A118AAE5F04ACEB3FDEC3D776163F86EC75DF6B39C53`; `by-memory/0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks.md` `46EBF2268548FE01560D0986EDC48C89150E9C87DE1C3C85A4FFA6A440BFC4E6`; `by-memory/0x00502760-0x005027cc.HistoryViewingPaneDestructor.md` `8EC23E15C5BD1B5F29FBE3EFEA7690382EBA858F967CB64096260F05DA49639A`; `by-global/g_pHistoryViewingPane.md` `7FAF7D34C585901103A5172463AAFA3157032339486414720913A9410AB60A29`; `by-memory/0x0069b494-0x0069b498.g_pHistoryViewingPane.md` `B38789885006C55662E8F6EA1B2F2CF69F50B3BE8C200DAB8A447C48EC33E2DF`.
- Modified support pages, current post-repair hashes: `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md` `6C725BEE262BD393E95A6043458BED68D61392DFF15BF5ACE6965F43104638F9`; `by-resource/main-menu-history-resources.md` `3125CFCA3EC24F530D68EC7B1BD016BB4B8532E9AB9E2815E034989C456231AE`; `by-resource/main-menu-story-resources.md` `7F53B332D0CE41CB50DE557A96513BC377098F9818C6BCC4236C3614285C8194`; `by-class/MainMenuPane.md` `7D11866F470813AACED5022388AC770254281AC0FC4B510039FB9AA347CAA91E`; `by-file/MainMenuPane.md` `0CFC5B09B815D4C054415A090C25E95AF0B33443D9093966B0D4C0E33C432FA5`; `by-class/Pane.md` `499796983401D7882948E4F10A9D05A6D39951B308DD5BB9D26B96C245440D3F`; `by-file/Pane.md` `B032DCE97BA3C8002E88C3630A1094A4501B39928530F5799A1BF774ECD511B9`; `by-memory/0x00544460-0x00545086.PaneCore.md` `4D5181EF11B0BF6928864FF1DBFDAD767CBE06A16EEBEFEEF2BC997794206399`; `by-global/g_pStatusPaneLayer.md` `5F06F266331130FE2BC6C7A6379D17A4D251A624983A535B5109E2700A45F9EB`; `by-file/MainUiGraph.md` `6588BE54E3BD790760BDF55C4E7A28D5CB1CCD4815B0A26E4412EED1843F2B58`.
- Updated this same report in place with exact claim twins, assigned UIDs, receipts, generated readback, hashes, current-state wording, and implementation evidence. Renamed/moved: none.
- Report lifecycle boundary: execution/archive status is supervisor-owned and authoritative only from the artifact path and validator-owned status/history being acted on; no ordinary report prose asserts a current lifecycle phase.
- B010 ran only the scoped/waited ordinary validators listed in Section 31. B010 did not mutate IDA, edit coverage/generated/tracker/audit/lifecycle files directly, execute a report, or move/archive an artifact; generated/stat/tracker changes were validator-owned side effects.

## Implementation Tracking Checklist

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C0JW-001 | 0000JW | Preserve the exhaustive HistoryViewingPane whole-file inventory and all source/compiler/support dispositions. | very-strong | Canonical ranges, xrefs, RTTI, docs, and generated audit. | UID0000JW inventory/evidence | incorporate | applied |
| [x] | C0JW-002 | 0000JW | Set reconstructable TRUE and retain standalone path NexusTK/login. | very-strong | Complete source route and no owner ambiguity. | UID0000JW metadata | incorporate | applied |
| [x] | C0JW-003 | 0000JW | Confirm standalone HistoryViewingPane.cpp/.h rather than MainMenu or chat folding. | strong | Dedicated class cluster, singleton, RTTI, six consumers. | UID0000JW ownership/source placement | incorporate | applied |
| [x] | C0JW-004 | 0000JW | Emit file CPP/H shells with deterministic class/global child order. | strong | Complete declaration/definition dependency audit. | UID0000JW formal CPP/H | incorporate | applied |
| [x] | C0JW-005 | 000066 | Document Pane plus direct Singleton inheritance, exact fields, offsets, and 0x108 size. | very-strong | Pane size, RTTI PMDs, field accesses. | UID000066 layout | incorporate | applied |
| [x] | C0JW-006 | 000066 | Record the complete authored method inventory and implicit destructor disposition. | very-strong | All three vtables and bounded code inventory. | UID000066 methods | incorporate | applied |
| [x] | C0JW-007 | 0001A0 | Replace stale AdvancePage fields/API with last-index semantics and InvalidateRect(m_visibleBounds). | very-strong | Exact bytes and shared Pane API. | UID0001A0 behavior/CPP | reject-stale | applied |
| [x] | C0JW-008 | 0001A1 | Reconstruct constructor initialization, resource count, layer/order, and timer scheduling exactly. | very-strong | Constructor disassembly/decompile and callees. | UID0001A1 constructor/CPP | incorporate | applied |
| [x] | C0JW-009 | 0001A1 | Reconstruct HandleKeyOrTextEvent with event translation and Enter/Escape/Space behavior. | very-strong | Event type, key literals, one AdvancePage caller. | UID0001A1 key method/CPP | reject-stale | applied |
| [x] | C0JW-010 | 0001A1 | Reclassify 0x004fff90 from IsInteractive to TimerHandler OnTimer. | original-proof | Tertiary vtable slot and retn 0xc. | UID0001A1 timer method/CPP | reject-stale | applied |
| [x] | C0JW-011 | 0001A1 | Reconstruct HandlePointerOrMouseEvent and source-call AdvancePage despite optimized inline lowering. | very-strong | Event values, duplicate state machine, one helper xref. | UID0001A1 mouse method/CPP | incorporate | applied |
| [x] | C0JW-012 | 0001A1 | Reconstruct OnPaint with EPFTileContext, LookupLayoutEntry, RenderTileFrame, and NPAL4.PAL. | very-strong | Exact calls, literal xref, current APIs. | UID0001A1 paint method/CPP | reject-stale | applied |
| [x] | C0JW-013 | 0000R3 | Define g_pHistoryViewingPane as NULL-initialized source global. | original-proof | Zero-filled storage and six lifecycle xrefs. | UID0000R3 CPP/H | incorporate | applied |
| [x] | C0JW-014 | 0000R3 | Emit Singleton constructor/destructor specializations for publication/clear. | very-strong | EBO RTTI, ctor/unwind/dtor sequence, project pattern. | UID0000R3 CPP | incorporate | applied |
| [x] | C0JW-015 | 0001AG | Retire explicit destructor body and classify wrapper as compiler-covered implicit destruction. | very-strong | StringBase/member/Singleton/base/delete sequence. | UID0001AG metadata/no-code | reject-stale | applied |
| [x] | C0JW-016 | 0001A1 | Preserve cleanup island 0x004ffed0-0x004fff0a as constructor-unwind compiler code. | original-proof | Not modeled function; exact vtable/member/global/base cleanup. | UID0001A1 range/compiler evidence | incorporate | applied |
| [x] | C0JW-017 | 0001A7 | Preserve singleton clear 0x005023b0-0x005023bb as compiler EH helper with blank code. | original-proof | Exact bytes and constructor EH xref. | UID0001A7 no-code evidence | incorporate | applied |
| [x] | C0JW-018 | 0001AB | Preserve both destructor adjustors as ABI compiler thunks with blank code. | original-proof | Exact -0xa0/-0xa4 adjustments and vtable refs. | UID0001AB no-code evidence | incorporate | applied |
| [x] | C0JW-019 | 0001AG | Preserve scalar-deleting wrapper/vtable/base/delete mechanics as compiler output. | original-proof | Exact function body and thunk/vtable refs. | UID0001AG compiler evidence | incorporate | applied |
| [x] | C0JW-020 | 00025Q | As support-only maintenance, create the exact physical child for 0x0061d9cc-0x0061da54 under the mixed aggregate without claiming UID00025Q report coverage. | original-proof | Exact predecessor/successor and 136 bytes. | UID00025Q support child inventory | incorporate | applied |
| [x] | C0JW-021 | 000066 | Create semantic HistoryViewingPaneVtables support page owned by the class. | very-strong | Three complete slot tables and RTTI graph. | new by-type/by-vtable page | incorporate | applied |
| [x] | C0JW-022 | 000066 | Preserve seven-base RTTI hierarchy and direct Singleton EBO at +0xf8. | original-proof | Three COLs, CHD, base array, PMDs. | UID000066 RTTI | incorporate | applied |
| [x] | C0JW-023 | 0001RF | Synchronize HISTORY resource ownership and viewer behavior without moving resources into source ownership. | very-strong | Caller literals, package evidence, ctor parameter. | UID0001RF HistoryViewingPane linkage | incorporate | applied |
| [x] | C0JW-024 | 0001RG | Synchronize STORY resource ownership and retained launcher evidence. | very-strong | Wrapper/direct caller literals and package evidence. | UID0001RG HistoryViewingPane linkage | incorporate | applied |
| [x] | C0JW-025 | 0001A1 | Preserve NPAL4.PAL as viewer paint palette and reject PAL01/NPAL8 ownership. | original-proof | String xref at 0x00500061 and resource matrix. | UID0001A1/resource cross-reference | incorporate | applied |
| [x] | C0JW-026 | 00019R | Keep launch aggregate and exact helper children under MainMenuPane. | very-strong | Resource-selection behavior and source boundaries. | UID00019R ownership note | already-present | already-present |
| [x] | C0JW-027 | 0000L0 | Preserve four active direct MainMenu constructor call sites. | original-proof | Xrefs 0x4f7b8d/0x4f7bc3/0x4f7c07/0x4f7c3d. | UID0000L0 caller inventory | incorporate | applied |
| [x] | C0JW-028 | 0003H6 | Preserve retained OpenStory/OpenHistory wrappers as real MainMenu helpers, not History members. | very-strong | Modeled bodies and ctor calls 0x4f912b/0x4f91ab. | UID0003H6/0003H7 ownership | already-present | already-present |
| [x] | C0JW-029 | 0000A2 | Correct Pane SetPaneOrder declaration to two Pane pointer arguments. | very-strong | Body 0x00544d30 and call-site pushes. | UID0000A2 formal H/signature evidence | reject-stale | applied |
| [x] | C0JW-030 | 0004VF | Add extern Layer *g_pStatusPaneLayer to MainUiGraph header route. | very-strong | Constructor data read and global owner page. | UID0004VF formal H | incorporate | applied |
| [x] | C0JW-031 | 0001A1 | Use current Event/EventMan and TimerHandler source APIs rather than synthetic KeyEvent/MouseEvent/timer member APIs. | very-strong | Shared formal headers and facet vtables. | UID0001A1 dependencies/CPP | reject-stale | applied |
| [x] | C0JW-032 | 0001A1 | Use ImageLib/EPFTileContext/GrafPort source APIs rather than EpfFrame/GetFrame/DrawEpfFrame. | very-strong | Current shared headers and exact calls. | UID0001A1 dependencies/CPP | reject-stale | applied |
| [x] | C0JW-033 | 000066 | Adopt inferred human names m_lastFrameIndex, m_pageDelayMs, m_resourceName, and AdvancePage. | strong | Offsets, semantics, subsystem style. | UID000066 naming/layout | incorporate | applied |
| [x] | C0JW-034 | 0000JW | Historicalize and reject old class_ChattingColorPane generated pollution. | very-strong | Current tree absence and class-specific RTTI/callers. | UID0000JW history | historicalize | applied |
| [x] | C0JW-035 | 0000JW | Record the dated generated CPP hash, three empty markers, stale bodies, and missing H, subordinate to fresh dynamic reread. | original-proof | Physical generated readback at command 24879. | UID0000JW generated audit | incorporate | applied |
| [x] | C0JW-036 | 0000JW | Apply exact by-file CPP include shell and H include-guard child shell. | strong | Complete source dependency/order analysis. | UID0000JW formal CPP/H | incorporate | applied |
| [x] | C0JW-037 | 000066 | Apply class CPP child shell and complete formal class H declaration. | very-strong | Full method/layout/RTTI inventory. | UID000066 formal CPP/H | incorporate | applied |
| [x] | C0JW-038 | 0001A0 | Apply exact formal AdvancePage CPP and blank H. | very-strong | Exact behavior and private declaration on class H. | UID0001A0 formal CPP/H | incorporate | applied |
| [x] | C0JW-039 | 0001A1 | Apply exact formal constructor/input/timer/paint CPP and blank H. | very-strong | Complete core behavior and class declarations. | UID0001A1 formal CPP/H | incorporate | applied |
| [x] | C0JW-040 | 0000R3 | Apply exact global/specialization CPP and extern H. | very-strong | Singleton/global lifecycle proof. | UID0000R3 formal CPP/H | incorporate | applied |
| [x] | C0JW-041 | 0001AG | Keep formal CPP/H blank after compiler-only reclassification. | very-strong | Implicit destructor regenerates full wrapper. | UID0001AG formal CPP/H | reject-stale | applied |
| [x] | C0JW-042 | 0000JW | Set emitter positions to file shell 0, class 10, methods 10/20, global 20 with deterministic child order. | strong | Required generated declaration/definition ordering. | target/support emitter metadata | incorporate | applied |
| [x] | C0JW-043 | 0000JW | Raise file metadata to 93/94 and reconstructable TRUE. | very-strong | Whole-file closure and exact remaining cap. | UID0000JW scores/metadata | incorporate | applied |
| [x] | C0JW-044 | 000066 | Raise class metadata to 93/95 while preserving owner/emitter UID0000JW. | very-strong | Complete layout, methods, RTTI, formal H. | UID000066 scores/metadata | incorporate | applied |
| [x] | C0JW-045 | 0001A0 | Raise AdvancePage to 92/94. | very-strong | Exact body, caller, fields, formal source. | UID0001A0 scores | incorporate | applied |
| [x] | C0JW-046 | 0001A1 | Raise core to 93/95. | very-strong | Complete range/behavior/dependencies/formal source. | UID0001A1 scores | incorporate | applied |
| [x] | C0JW-047 | 0001A7 | Set singleton clear, thunks, and destructor wrapper to 90/94, 90/94, and 92/95 non-reconstructable/no-emitter. | very-strong | Exhaustive compiler-only proof. | UID0001A7/0001AB/0001AG metadata | incorporate | applied |
| [x] | C0JW-048 | 0000R3 | Raise global/storage to 92/94 and 92/95 and correct zero initializer. | very-strong | Exact bytes, xrefs, source route. | UID0000R3/0001PU scores/state | incorporate | applied |
| [x] | C0JW-049 | 00025Q | As support-only maintenance, keep the broad aggregate at 86/92 and add the exact HistoryViewingPane child/link and semantic route; UID00025Q receives no report coverage. | very-strong | Aggregate remains a mixed support index; the HistoryViewingPane child is complete. | UID00025Q support inventory/unchanged-score rationale | incorporate | applied |
| [x] | C0JW-050 | 0001RF | Preserve resource scores and add corrected viewer method/source names. | very-strong | Current resource evidence already high quality. | UID0001RF/0001RG support text | incorporate | applied |
| [x] | C0JW-051 | 0000L0 | Add HistoryViewingPane.h include and corrected consumer/source boundary to MainMenuPane. | strong | Compile-visible construction and six callers. | UID0000L0 formal CPP/support | incorporate | applied |
| [x] | C0JW-052 | 0000A2 | Preserve exact two-Pane SetPaneOrder ABI evidence in Pane class/file/core docs. | very-strong | Complete body and multiple call-site shapes. | UID0000A2/0000MC/0001EA | incorporate | applied |
| [x] | C0JW-053 | 0004VF | Preserve status-layer global source/header ownership in MainUiGraph docs. | very-strong | Exact storage/xref and current source route. | UID0004VF/0000L1 | incorporate | applied |
| [ ] | C0JW-054 | 0000JW | Supply exact supervisor-owned manual coverage replacements/inserts without editing coverage. | original-proof | Current physical manual rows plus complete literal UID00054H/UID00054I rows and exact placement anchors in Section 28. | Section 28/manual coverage | incorporate | proposed |
| [ ] | C0JW-055 | 0000JW | Apply deterministic supported function rename/type/comment recommendations and the direct singleton `set_address_comments` payload `{database,items:[{addr,comment}]}` on unchanged unnamed address 0x0069b494 only after fresh supervisor prestate checks; do not rename the singleton. | very-strong | Live literal function/address prestates, function-name collision checks, failed fallback-label data-rename dry runs, and exact singleton item `{addr:"0x0069b494", comment:"HistoryViewingPane Singleton pointer; zero-initialized and cleared by Singleton destruction."}`. | Section 21/IDA Gate 2B | incorporate | proposed |
| [ ] | C0JW-056 | 0000JW | Preserve compiler entities/decorated tables and add semantic comments without changing boundaries. | original-proof | Exact bytes/names/types/comments/xrefs. | Section 21/IDA Gate 2B | incorporate | proposed |
| [ ] | C0JW-057 | 000066 | Do not create a partial HistoryViewingPane IDA UDT; preserve current safe base-facet types. | very-strong | Complete UDT absent; existing support UDTs present. | Section 21/type safety | not-applicable | proposed |
| [x] | C0JW-058 | 0000JW | Run scoped validators and coherent waited generated CPP/H verification only after accepted callback. | strong | Validator-owned source generation contract. | Section 31/follow-up | incorporate | applied |
| [x] | C0JW-059 | 0000JW | Preserve superseded assumptions with rejection reasons rather than deleting history. | very-strong | Current evidence contradicts prior names/routes. | target/support history sections | historicalize | applied |
| [ ] | C0JW-060 | 0000JW | Preserve B-agent no-IDA/no-coverage/no-lifecycle-mutation boundary and supervisor lifecycle authority. | original-proof | Current assignment and skill contract. | report/Section 32 | not-applicable | proposed |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"additional_uids":["000066","0000R3","0001A0","0001A1","0001A7","0001AB","0001AG","0001PU"],"agent":"B010","command_id":"000000025198","destination_path":"executed-b-agent-research/B010/0000JW-HistoryViewingPane-file-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0000JW-HistoryViewingPane-file-source-quality.md","timestamp":"2026-08-16T11:28:35-04:00","uid":"0000JW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
