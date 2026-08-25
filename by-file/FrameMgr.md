*** UID:0000JM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# FrameMgr And FrameHandler

## 2026-08-14 B003 ScreenPane Dependency Incorporation

- UID00005G owns the generated guarded `FrameMgr.h` declaration for FrameHandler and the CPP include/children route through this file. UID00005H FrameMgr remains a separate class in the same compilation unit.
- ScreenPane consumes the complete FrameHandler base. No ChangePasswordDialogPane behavior is owned here. Current file authority is `COMPLETION:94`, `CONFIDENCE:94`; the earlier `88/91` state is dated transition history only.

## Status

- Confidence: very strong for scheduler role, complete class/layout/source grouping, singleton ownership, direct file-root assignment, vtable/global refs, queue behavior, and generic wrapper ownership; private lexical spelling and dormant-drain liveness cap the score.
- Proposed module: `ui/core/FrameMgr.cpp`
- Alternate placement considered: `util/FrameMgr.cpp`
- Main address range: `0x004b6cb0-0x004b7112`

## File Role

This module owns the client frame-callback scheduler. `FrameMgr` is a singleton list manager stored in `g_frameRegistry`; `FrameHandler` is the small base/handler object that unregisters itself from the registry when destroyed. The scheduler stores handlers in due-frame order and dispatches callbacks as the global frame tick advances.

The name "frame" here means animation/frame-tick scheduling, not UI border artwork. Keep it separate from the historical [UID:0000JL][FrameChrome](by-file/FrameChrome.md) grouping, whose genuinely remaining scope is the AboveFrame border/tab family. [UID:000578][FramePartPane](by-file/FramePartPane.md), not FrameChrome, owns the `FRMPART` FramePartPane source unit and [UID:00022F][0x004b7120-0x004b731f.BuildFramePartPanes](by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md).

The queue storage is backed by shared [UID:0000KR][LinkedList](by-file/LinkedList.md) / `std::list` support helpers. `FrameMgr.cpp` should own frame-specific ordering, dispatch, and `FrameHandler` lifetime logic; generic node allocation and list cleanup are non-emitting STL/Dinkumware support rather than custom `util/LinkedList.cpp` source.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `FrameHandler` | `0x004b6cb0-0x004b6db2` | Handler base/destructor that unregisters from `g_frameRegistry`. |
| `FrameMgr` | `0x004b6dc0-0x004b7112` | Singleton frame callback queue with sorted insertion, removal, dispatch, and teardown. |
| [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md) / [UID:0002AT][0x0069ae10-0x0069ae14.g_frameRegistry](by-memory/0x0069ae10-0x0069ae14.g_frameRegistry.md) | `0x0069ae10-0x0069ae14` | External `FrameMgr *g_frameRegistry` declaration and sole loader-zero-filled definition; `g_pIdleDispatchQueue` is retained only as a rejected role-incomplete historical alias. |
| schedule wrapper helpers | `0x004b6d00`, `0x004b6d20`, `0x004b6d30` neighborhood | Thin generic `FrameHandler` helpers that call `FrameMgr::Insert`/`RemoveFrame`; `0x004b6d30` is `FrameHandler::ScheduleFrameCallback`, not a ScreenPane-owned wrapper. |

## Evidence Notes

- IDA storage and call patterns show `FrameMgr` is an `LObject`-based singleton with a circular linked list at offset `0x10`.
- IDA MCP reports `FrameMgr::FrameMgr` has one direct constructor caller and `DispatchDueFrameCallbacks` is called from the application/event dispatch path.
- IDA MCP xrefs on 2026-05-26 confirm `dword_69AE10` is written by `FrameMgr::FrameMgr`, cleared by `FrameMgr::ScalarDeletingDestructor`, used by the `FrameHandler` wrappers, and used by [UID:000142][0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md).
- IDA labels `FrameHandler` functions as Boost exception symbols, but call patterns and `g_frameRegistry` use match project frame-handler logic.
- `ScreenPane`, `WorldMapPane`, and other frame-driven objects embed or use `FrameHandler`.
- IDA MCP on 2026-05-24 confirms `0x004b6d00` schedules the current handler at `currentFrame + 1`, `0x004b6d20` removes the current handler from the registry, and both have broad callers outside `WorldMapPane`. Treat WorldMap ownership for those wrappers as generated caller-biased noise.
- 2026-06-07 Batch 004 IDA MCP gate audit reconfirmed all scheduler method boundaries: `0x004b6cb0-0x004b6cf3`, `0x004b6d00-0x004b6d14`, `0x004b6d20-0x004b6d2d`, `0x004b6d30-0x004b6d4c`, `0x004b6d50-0x004b6db3`, `0x004b6dc0-0x004b6e63`, `0x004b6ea0-0x004b6f0e`, `0x004b6f10-0x004b6f56`, `0x004b6f60-0x004b703d`, and `0x004b70c0-0x004b7112`.
- The same audit reconfirmed constructor call-in from `0x004a6b9c`, idle-dispatch call-in from `0x004a6cd0`, broad frame-driven callers for the handler schedule/remove wrappers, `g_frameRegistry` refs at `0x0069ae10`, vtable refs for `FrameHandler` base `0x0061a7e0` and `FrameMgr` base `0x0061a7ec`, one `0xcc` byte before the scheduler range, and `0xcc` padding at `0x004b7112-0x004b7120`.
- 2026-06-16 A002 live IDA refresh reconfirmed the same starts and sizes in the active `NexusTK.exe` session: handler destructor `0x004b6cb0` size `0x43`, wrappers `0x004b6d00`/`0x004b6d20`/`0x004b6d30`, handler scalar deleting destructor `0x004b6d50`, manager constructor `0x004b6dc0`, insert/remove/dispatch `0x004b6ea0`/`0x004b6f10`/`0x004b6f60`, manager scalar deleting destructor `0x004b70c0`, and no function at `0x004b7112`.
- Current `xrefs_to` still shows broad scheduler use rather than one feature owner: `0x0069ae10` has 13 direct refs from application idle work, handler wrappers/destructors, manager construction/ordinary cleanup, scalar cleanup, and the constructor-unwind `Singleton<FrameMgr>` base-cleanup body at `0x004b70b0`; `0x0061a7e0` has 6 FrameHandler vtable refs from scheduler destructors and embedding constructors; `0x0061a7ec` has 3 FrameMgr vtable refs from manager construction/destruction.
- Decompilation checked the wrapper semantics directly: `0x004b6d00` inserts the handler at the registry's next frame, `0x004b6d30` inserts at an explicit delay relative to the current frame counter, and `0x004b6f60` advances dispatch state, unlinks due nodes, frees list nodes, and invokes the handler callback virtual. These resolve the wrapper role but not the exact original method names.
- `analyze_component` still ties the manager to the shared [UID:0000KR][LinkedList](by-file/LinkedList.md) helpers (`0x00457550`, `0x004570e0`, and `0x00457430`) and shows no string/resource dependency that would move it into visible frame chrome or a feature pane.
- Boundary bytes remain clean: `0x004b6caf` is `0xcc`, and `0x004b7112-0x004b7120` is `0xcc` padding.

## Corrected Parent Gate Audit

- At the 2026-06-16 audit this file-root score was `COMPLETION:86`, `CONFIDENCE:88`; the later `88/91` state closed direct global storage and lifecycle but still predated complete class/source reconciliation. The accepted current score is `94/94` after the full ordinary source route and every physical/compiler disposition were closed.
- Direct child now eligible: [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md), whose Batch 004 audit raises it to `85/90`.
- Assignment basis: `FrameMgr.cpp` is the direct source root for the scheduler aggregate because the range owns both `FrameHandler` wrappers and `FrameMgr` queue policy, all direct scheduler calls route through `g_frameRegistry`, and the proposed source tree already places `FrameMgr.cpp` under `NexusTK/ui/core/`.
- Historical 2026-06-16 caveat: final field names and every embedding-owner layout were below that audit's then-used `95/95` final-source threshold. UID00005G/UID00005H and the global/storage contributors now emit complete source; UID00015M and UID0002V3 remain blank because they are physical/compiler indexes, not because source behavior is unresolved.

## Blocker Investigation

- Source placement: checked the proposed source tree, [UID:0000JL][FrameChrome](by-file/FrameChrome.md), [UID:0000KR][LinkedList](by-file/LinkedList.md), current wrapper callers, and live global/vtable refs. `NexusTK/ui/core/FrameMgr.cpp` remains supported; `FrameChrome` owns visible art, and `LinkedList` owns generic node helpers.
- Caller/reachability: checked wrapper xrefs, `g_frameRegistry` refs, `FrameHandler` and `FrameMgr` vtable refs, and component callees. Broad callers support a generic scheduler module; no caller-biased owner such as WorldMapPane, ScreenPane, or GroupListPane is defensible.
- Field/type names: exact offsets and roles now support `FrameUpdateContext`, `FrameScheduleEntry`, `m_context`, and `m_callbacks`; these source-facing spellings are inferred consistently and no longer block complete source. Lost private lexemes remain a confidence cap.
- Support-page sync: UID00005G and UID00005H now carry the complete guarded H and authored CPP bodies; UID0000Q0/UID0002AT carry the one extern/definition-plus-Singleton route. The aggregate and vtable pages stay blank by exact no-code disposition.

## Cross-References

- [UID:00005H][FrameMgr](by-class/FrameMgr.md)
- [UID:00005G][FrameHandler](by-class/FrameHandler.md)
- [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md)
- [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md)
- [UID:0000KR][LinkedList](by-file/LinkedList.md)
- [UID:0000NB][ScreenPane](by-file/ScreenPane.md)
- [UID:0000JL][FrameChrome](by-file/FrameChrome.md)

## g_frameRegistry Source Definition Synchronization

- Source route and one-definition policy: this file owns the external-linkage `FrameMgr *g_frameRegistry` object. [UID:00005G][FrameHandler](by-class/FrameHandler.md) carries the `FrameMgr` forward declaration, [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md) carries the sole `extern FrameMgr *g_frameRegistry;` declaration, and [UID:0002AT][0x0069ae10-0x0069ae14.g_frameRegistry](by-memory/0x0069ae10-0x0069ae14.g_frameRegistry.md) carries the sole definition. No second alias object, raw byte array, address binding, section pragma, or explicit lifecycle assignment belongs in `FrameMgr.cpp`.
- Current storage evidence: live IDA MCP read `00 00 00 00` at `[0x0069ae10,0x0069ae14)`, with SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`. The object lies in the virtual-only tail of `.data`: target RVA `0x29ae10`, section RVA `0x26d000`, raw size `0xd800`, virtual size `0x2fe24`; it is `0x20610` bytes beyond the raw-backed end and `0x2014` bytes before the virtual end. The loader therefore supplies static zero initialization and the source-facing definition uses an omitted initializer.
- Reference inventory: the object has exactly 13 direct references at `0x004a6bfa`, `0x004a6cc9`, `0x004a7e0c`, `0x004b6cd9`, `0x004b6d02`, `0x004b6d21`, `0x004b6d35`, `0x004b6d7b`, `0x004b6e03`, `0x004b6e0a`, `0x004b6e83`, `0x004b70b0`, and `0x004b70d6`. A target-VA byte-pattern search also returns 13 matches, while the RVA pattern returns none.
- Type and lifecycle: allocation size `0x18`, the FrameMgr vtable, method receivers, and RTTI prove `FrameMgr *`. RTTI identifies direct `Singleton<FrameMgr>` inheritance with PMD displacement `+4`, explaining publication and fallback/clear behavior through the base. The constructor, ordinary cleanup island, scalar-deleting wrapper, and the unwind sequence `0x005ff128-0x005ff12e -> 0x004b70b0` are source/base/compiler decomposition, not extra public helpers or extra global definitions.
- Relevant `FrameMgr` shape remains `0x18`: `LObject`/vptr at `+0x00`, the empty `Singleton<FrameMgr>` base overlapping the first manager counter at `+0x04`, a second counter at `+0x08`, a state byte at `+0x0c`, natural padding at `+0x0d-+0x0f`, and list state at `+0x10-+0x17`. These facts support the accepted complete inferred declaration used by the current `94/94` source reconstruction. Original private member, callback-record, and container spellings remain inferred, but that lexical uncertainty does not prevent a complete declaration.
- Naming and placement: `g_frameRegistry` is the strongest established source-facing descriptive name but remains lexically inferred because no symbol/debug record survives. `g_pIdleDispatchQueue`, `dword_69AE10`, and `unk_69AE10` are rejected as source definitions. Broad FrameHandler wrappers and application-idle consumers support generic `NexusTK/ui/core/FrameMgr.cpp` ownership; EventDispatcher, Application, ScreenPane, WorldMapPane, FrameChrome, TimerMgr, and shared list support are users, adjacent modules, or compiler/library support rather than storage owners.
- Historical correction: the 2026-06-05 `ff ff ff ff` / `0xffffffff` description and the older no-fresh-IDA caveat are superseded by current bytes and PE mapping. The older reading of `0x004b70b0` as a possible public helper is superseded by the constructor-EH `Singleton<FrameMgr>` base-cleanup path. These remain provenance only and do not describe current source state.
- Score rationale: completion/confidence `94/94` reflects complete source/header routing, exact storage/reference/layout/queue behavior, every authored/compiler/raw disposition, and corrected dependent callback declarations. Unrecovered original global/private lexemes and zero-xref drain liveness prevent a higher claim.

## Changes

- 2026-07-14 B003 UID0002AT source-quality synchronization:
  - Before: scores were `86/88`; the file identified the singleton generally but retained an ambiguous idle-dispatch alias and did not close the loader-zero-filled sole-definition route.
  - Changed to: scores `88/91`; linked UID0000Q0 as declaration carrier and UID0002AT as sole definition carrier; added exact bytes/hash, PE virtual-tail arithmetic, 13-reference inventory, direct `Singleton<FrameMgr>` PMD `+4` lifecycle cause, relevant `0x18` layout, source/compiler decomposition, owner negatives, and historical corrections.
  - Preserved: all scheduler functions and ranges, broad callers, shared-list boundary, raw-island/compiler distinctions, source path, and unresolved full-class member/callback/container spelling blockers.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:84`.
  - Summary/evidence: frame-callback scheduler role, FrameMgr/FrameHandler grouping, global scheduler ownership, wrapper helper roles, IDA/global xref evidence, frame-chrome distinction, LinkedList boundary, and cross-references are documented; completion is moderate because the page is compact and lacks exhaustive per-method pseudocode.
- 2026-06-05 path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, which left the file row in error state despite the proposed tree placing `FrameMgr.cpp` under `ui/core`.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/"`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` lists `FrameMgr.cpp` beside `EventDispatcher`, `FrameChrome`, and other UI core scheduler/pane infrastructure; live IDA MCP xrefs to [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md) confirm the singleton is constructed/cleared by the frame scheduler and used by the application idle scheduler.
- 2026-06-07 Batch 004 gate audit:
  - Before: `COMPLETION:82`, `CONFIDENCE:84`; the page had a valid path and scheduler summary but was below the corrected direct-parent assignment gate.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:86`.
  - Summary/evidence: live IDA reconfirmed all `FrameHandler`/`FrameMgr` function endpoints, direct constructor/dispatch callers, broad wrapper callers, singleton refs, vtable refs, proposed source-tree placement, and boundary padding. The page now explicitly supports direct parenting for the FrameScheduler aggregate while leaving final C++ blank.
- 2026-06-16 A002 file-completion refresh:
  - Before: scores were `85/86`; the file was routable but still had unresolved source-quality questions listed only compactly.
  - Changed to: scores `86/88`; added current IDA lookup/xref/decompile/padding evidence, explicit source-placement and reachability blocker investigation, and direct `FrameHandler` support-page sync.
  - Summary/evidence: live IDA kept the scheduler in `FrameMgr.cpp`, rejected caller-biased feature ownership, reconfirmed `g_frameRegistry` and vtable surfaces, and narrowed remaining blockers to original field/type/member names rather than ownership or boundary uncertainty.

## 2026-08-24 B001 UID0000JM Accepted Whole-File Callback

### Metadata And Source Order

- Raised `88/91 -> 94/94`, set `RECONSTRUCTABLE:TRUE`, and preserved `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/"` and `CANONICAL_OWNER:FILE`.
- Exact direct contributor order is UID00005G/UID0000Q0/UID0002AT/UID00005H/UID00015M/UID0002V3 at positions `0/10/20/30/40/50`.

| Contributor | CPP disposition | H disposition |
| --- | --- | --- |
| UID00005G FrameHandler | self-include, destructor and three void wrappers, then children | guard/open includes; exact context/handler/entry declarations and size guards |
| UID0000Q0 g_frameRegistry declaration | blank | sole `extern FrameMgr *g_frameRegistry;` |
| UID0002AT global storage | sole definition plus Singleton constructor/destructor specializations | blank |
| UID00005H FrameMgr | constructor, stable insert, remove-all, two-phase dispatch, retained drain | exact `0x18` class/size guard and closing `#endif` |
| UID00015M scheduler physical index | blank; authored bodies already routed above | blank |
| UID0002V3 RTTI/vtable data | blank; compiler-generated from declarations | blank |

### Complete File Inventory And Disposition

- Thirteen scheduler bodies are exact: FrameHandler destructor/wrappers/scalar wrapper at `[0x004b6cb0,0x004b6db3)`; FrameMgr constructor, ordinary cleanup, Insert, RemoveFrame, DispatchDueFrameCallbacks, retained drain, Singleton EH cleanup, and scalar wrapper across `[0x004b6dc0,0x004b7112)`. UID00015M records each exact range, current identity/type, callers/xrefs/callees, and CPP/compiler/no-change destination.
- Fourteen CC-or-padding boundary items are `[0x004b6caf,0x004b6cb0)`, `[0x004b6cf3,0x004b6d00)`, `[0x004b6d14,0x004b6d20)`, `[0x004b6d2d,0x004b6d30)`, `[0x004b6d4c,0x004b6d50)`, `[0x004b6db3,0x004b6dc0)`, `[0x004b6e63,0x004b6e70)`, `[0x004b6e93,0x004b6ea0)`, `[0x004b6f0e,0x004b6f10)`, `[0x004b6f56,0x004b6f60)`, `[0x004b703d,0x004b7040)`, `[0x004b70a5,0x004b70b0)`, `[0x004b70bb,0x004b70c0)`, and `[0x004b7112,0x004b7120)`. Excluded successor function `[0x004b7120,0x004b731f)` is UID00022F under [UID:000578][FramePartPane](by-file/FramePartPane.md), never FrameMgr or current FrameChrome source.
- Data inventory is one owned external global `[0x0069ae10,0x0069ae14)`, zero target-owned file statics, one excluded adjacent global/padding item, one shared list-length string, seven owned RTTI/vtable cells, and one excluded successor table cell. UID0002AT/UID0000Q0 own the global source; UID0002V3 is compiler-covered; all neighbors remain excluded.
- Dependency inventory is 18 shared/runtime/EH items: three old-Dinkumware list helpers, LObject constructor/destructor, allocation/free, purecall, cookie, C++ EH, terminate, list-length error, delete wrapper, guard no-op, and four EH items/funclets. All are source-cause or liveness evidence, not duplicate FrameMgr helpers.
- Callback/type inventory is ScreenPane, SpelledPane, and WorldMapPane frame callbacks; exact FrameHandler/FrameUpdateContext/FrameScheduleEntry/FrameMgr source types; and existing complete ScreenPane/WorldMapPane layouts. There are zero target-owned resources and zero target-owned imports.

### Behavior And Compiler Boundary

- `FrameScheduleEntry` is exactly 8 bytes. `FrameUpdateContext` is exactly 12 bytes. FrameMgr is exactly `0x18` with direct LObject/Singleton bases, context at `+0x04`, and old-Dinkumware `std::list<FrameScheduleEntry>` state at `+0x10`.
- Insert preserves stable ascending due-frame order by advancing past equal keys. RemoveFrame erases all matching handlers. Due dispatch updates currentFrame, drains `< target` while dispatching true, drains `== target` while false, pops before callback, and ends with callbackFrame equal to target. Retained `AdvanceCallbackFrame` drains `<= currentFrame` and increments callbackFrame.
- No explicit FrameMgr destructor source exists. Implicit member/base teardown plus Singleton specializations regenerate the ordinary cleanup, scalar wrappers, EH cleanup, global clear, vptr stores, RTTI/vtables, and list machinery. Raw ranges `[0x004b6e70,0x004b6e93)` and `[0x004b7040,0x004b70a5)` remain exact physical no-change evidence; no IDA function creation is part of ordinary implementation.
- ScreenPane now owns one exact void callback body and no duplicate context; SpelledPane uses a void declaration/body and standalone 50-frame schedule call; WorldMapPane has the void context-pointer declaration while UID0003SN remains an explicit blank 284-instruction body obligation; EventDispatcher CPP includes `FrameMgr.h` while its H and UID000142 body remain unchanged.

### Historical And Generated Baseline

- Historical blank-source, bool-callback, stale raw-function, command-27631, and old-session statements remain dated provenance only. The accepted callback uses the complete ordinary source above and leaves IDA/coverage/lifecycle authority with the supervisor.
- Pre-callback generated evidence was command `000000027684`: FrameMgr.cpp had no authored bodies/misplaced extern/three empty markers and FrameMgr.h lacked the complete manager/global route. The final callback validator must produce one guarded H, one definition/declaration route, four FrameHandler plus four FrameMgr authored methods and retained drain, and only UID00015M/UID0002V3 empty FrameMgr markers.

## 2026-08-25 B001 UID0000JM Gate 2A Documentation-Drift Repair

- Corrected the active File Role and complete inventory to route the `FRMPART` FramePartPane scope and excluded UID00022F successor through [UID:000578][FramePartPane](by-file/FramePartPane.md). The superseded broad FrameChrome grouping is retained only as historical AboveFrame border/tab context.
- Preserved `94/94` metadata, reconstruction path/owner, contributor order, formal source route, exact FrameMgr range and inventories, generated contract, and all prior history.

## 2026-08-25 B001 UID0000JM Gate 2A Incorporation Repair

- Reconciled the active ScreenPane-dependency statement to current `94/94` file authority. The former `88/91` value remains only in dated score-transition history and no longer describes current state.
- Preserved metadata, formal CPP/H, source path/ownership, complete inventory, generated contract, and all earlier history.
