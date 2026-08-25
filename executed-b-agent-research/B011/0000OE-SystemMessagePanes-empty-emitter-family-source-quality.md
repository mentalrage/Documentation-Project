** TARGET-REPORT-UID:0000OE **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000OE SystemMessagePanes Empty-Emitter Family Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0000OE][SystemMessagePanes](../../../../../by-file/SystemMessagePanes.md) as the source root for `NexusTK/social/SystemMessagePanes.cpp`; clear the current 18 empty markers with a mix of four exact singleton declarations, two best-inferred resource pointer table declarations, and twelve formal disposition comments for class, folded-helper, address-storage, singleton-aggregate, and table-aggregate pages.
- Final disposition: implementation-ready report for the current empty markers in `auto-generated/NexusTK/social/SystemMessagePanes.cpp`. Do not apply changes until supervisor validation and a separate implementation callback.
- Required target action after acceptance: update the file page and the 18 marker docs listed below. Do not change the target by-file root, generated output by hand, coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, or lock files during this report-only pass.
- Confidence: high for file ownership, route, singleton declarations, and resource-table ownership; medium-high for the two inferred table names and the class no-code dispositions because the source ABI can be made worse by premature class shells, as audited below.

## Target

- Target UID: `0000OE`.
- Target path: `by-file/SystemMessagePanes.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` Files With Empty Emitters row for `SystemMessagePanes`.
- Current queue row: 19 total emitters, 1 filled, 18 marked empty, 5.3% complete.
- Current generated output: `auto-generated/NexusTK/social/SystemMessagePanes.cpp`.
- Current generated header observed by B011: `validator-command-id: 000000002158`, `validator-refreshed-at: 2026-06-30T03:43:19-04:00`, source by-file UID `0000OE`, file timestamp `2026-06-30T07:43:24.5046070Z`, length `2699` bytes.
- Current source-root metadata: `COMPLETION:89`, `CONFIDENCE:86`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/social/"`, `CANONICAL_OWNER:FILE`.
- Recommended source-root metadata after implementation: keep `COMPLETION:89`, `CONFIDENCE:86`, same projected path, same `CANONICAL_OWNER:FILE`. The marker disposition is implementation-ready, but the root score should not move while seven class declarations remain intentionally withheld after score-blocker audit.

## Current Generated Inventory

The generated file currently has one filled emitter and eighteen empty markers.

| UID | Path | Score | Current role | Report disposition |
| --- | --- | ---: | --- | --- |
| `00016F` | `by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md` | `87/90` | shared single-line callback helper | Already coded; no action. |
| `000030` | `by-class/ColorStringSystemMessage.md` | `85/88` | colored text system-message entry class | Formal no-code comment after declaration-shell audit; exact methods/field `+0x04` are documented, but a shell would have to invent the base/interface ABI. |
| `00005D` | `by-class/FooterSystemMessage.md` | `85/88` | footer marker entry class | Formal no-code comment after marker audit; factory/vtable slots are documented, but representing folded slots now would falsely choose between inherited default and folded overrides. |
| `000061` | `by-class/HeaderSystemMessage.md` | `85/88` | header marker entry class | Formal no-code comment after marker audit; factory/vtable slots are documented, but representing folded slots now would falsely choose between inherited default and folded overrides. |
| `00009B` | `by-class/NewSystemMessageModifyHeightPane.md` | `85/87` | new-message height resize handle | Formal no-code comment after offset/vtable audit; exact constructor/handler/destructor family is documented, but no safe declaration shell exists without base and event ABI. |
| `00009C` | `by-class/NewSystemMessagePane.md` | `85/86` | new system-message wrapper panel | Formal no-code comment after constructor/vtable audit; exact lifecycle is documented, but a shell would misrepresent child/member layout and inherited virtuals. |
| `00009T` | `by-class/OldSystemMessagePane.md` | `85/88` | legacy system-message pane | Formal no-code comment after legacy-pane audit; exact lifecycle is documented, but the three-vtable layout and helper inventory are not declaration-safe. |
| `0000EA` | `by-class/SystemMessagePane.md` | `86/87` | main/current scrollable message viewport | Formal no-code comment after scroll-pane audit; method islands are source-bearing, but a shell would not regenerate the three-view vtable layout or member offsets safely. |
| `0002WV` | `by-global/g_pChattingViewport.md` | `87/90` | current viewport singleton | Emit pointer declaration. |
| `0002WW` | `by-memory/0x0067adc4-0x0067adc8.g_pChattingViewport.md` | `87/90` | exact storage child for `g_pChattingViewport` | Formal covered-by comment; global page emits declaration. |
| `0000R2` | `by-global/g_pHeightModifyPane.md` | `86/89` | height-handle singleton | Emit pointer declaration. |
| `0000RU` | `by-global/g_pNewSystemMessagePane.md` | `85/90` | new-panel singleton | Emit pointer declaration. |
| `0003ED` | `by-global/g_pOldSystemMessagePane.md` | `86/90` | old-panel singleton | Emit pointer declaration. |
| `0002W7` | `by-memory/0x0069b4c8-0x0069b4cc.g_pOldSystemMessagePane.md` | `87/92` | exact storage child for `g_pOldSystemMessagePane` | Formal covered-by comment; global page emits declaration. |
| `000246` | `by-memory/0x0058af40-0x0058af48.HeaderFooterSystemMessageDefaultTrueVirtual.md` | `86/90` | folded header/footer one-line virtual | Formal no-code comment; no standalone helper body. |
| `0002AO` | `by-memory/0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md` | `86/89` | two singleton slots plus reviewed reserved dword | Formal covered-by/reserved-data comment. |
| `0002ZV` | `by-memory/0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable.md` | `86/88` | first 0xf0-byte resource pointer table | Emit best-inferred file-static `s_systemMessagePaneResourcePointers[60]` declaration. |
| `0002AP` | `by-memory/0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables.md` | `88/88` | two-table writable-data aggregate | Formal aggregate comment; exact child pages emit the two table declarations. |
| `0002ZW` | `by-memory/0x0069bd08-0x0069bdf8.OldSystemMessagePaneResourcePointerTable.md` | `86/88` | second 0xf0-byte resource pointer table | Emit best-inferred file-static `s_oldSystemMessagePaneResourcePointers[60]` declaration. |

## Supervisor Active Recheck

- Assignment: report-first research for [UID:0000OE] `by-file/SystemMessagePanes.md` from the Files With Empty Emitters queue.
- MCP requirement: satisfied. I used live IDA MCP schema-current calls from active database session `supervisor_resume_20260629`.
- MCP health facts: `idb_list` reported one active worker session, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, pid/worker pid `17592`, `is_analyzing:false`. `server_health` reported `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and strings cache size `2067`.
- Schema note: `tools/list` confirmed current `tools/call` shape and that `lookup_funcs`, `xrefs_to`, `get_bytes`, `get_int`, `callees`, and `analyze_function` require a `database` argument; `xrefs_to` currently uses `addrs`, not `addr`.
- Report-only constraint: no target/support `by-*` docs, generated files, coverage reports, validator/tool state, IDA DB state, executed archives, supervisor ledgers, or lock files were edited.
- Lease constraint: no leases taken. This report-only phase only creates the B011 report in Agent-B011's research folder.

## Evidence Checked

Read-only local evidence:

- `tools/leaser/Agents/Agent-B011/goal.md`
- `by-structure.md`
- `by-file/-guidance.md`, `by-class/-guidance.md`, `by-global/-guidance.md`, `by-memory/-guidance.md`
- `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
- `.codex/skills/ntk-b-agent-workflow/references/score-blocker-audit-standard.md`
- `by-file/SystemMessagePanes.md`
- `auto-generated/NexusTK/social/SystemMessagePanes.cpp`
- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-file-coverage.md`, `-ag-class-coverage.md`, `-ag-global-coverage.md`, and `-ag-memory-coverage.md`
- All eighteen current marker docs listed in the generated inventory
- The seven direct class pages: `ColorStringSystemMessage`, `FooterSystemMessage`, `HeaderSystemMessage`, `NewSystemMessageModifyHeightPane`, `NewSystemMessagePane`, `OldSystemMessagePane`, and `SystemMessagePane`
- Exact vtable/read-only-data support pages: [UID:00026M], [UID:0003DI], [UID:0003GD], [UID:0003GE], [UID:0003GF], [UID:0003GM], [UID:0003GN], and [UID:0003DM]
- Writable data support pages: [UID:0002AO], [UID:0002AP], [UID:0002ZV], and [UID:0002ZW]

Prior reports and notes used as leads:

- B006 [UID:0001J6] `0001J6-SystemMessagePanes-source-quality.md`
- B002 [UID:00016F] `00016F-ConstantLineCountHelper-source-quality.md`
- B003 [UID:0001GG] `0001GG-SharedBooleanVirtualStubs-live-goal2-no-owner-pass.md`
- B002 [UID:0001B5] `B002-MEMTOOL-00514E60-SystemMessageMarkerScalarDeletingDestructor.md`
- B001 [UID:0003GP] `0003GP-SystemMessagePaneHelpResourceString-advanced-scan.md`
- B006 `0000IZ-Effects-empty-emitter-family-source-quality.md` as the closest accepted empty-emitter family implementation pattern: declaration C++, exact method bodies where safe, and formal no-code comments where source shape is intentionally withheld.

## IDA MCP Facts

### Function And Boundary Facts

`lookup_funcs` on current MCP reported these exact starts:

| Query | Result |
| --- | --- |
| `0x00584ea0` | `sub_584EA0`, size `0x339` / 825 bytes (Verified with `int_convert.py`) |
| `0x00587890` | `sub_587890`, size `0x6f` / 111 bytes (Verified with `int_convert.py`) |
| `0x00587900` | `sub_587900`, size `0x6f` / 111 bytes (Verified with `int_convert.py`) |
| `0x00587970` | `sub_587970`, size `0x9f` |
| `0x00587ae0` | `sub_587AE0`, size `0x73` / 115 bytes (Verified with `int_convert.py`) |
| `0x005881f0` | `sub_5881F0`, size `0xc5` / 197 bytes (Verified with `int_convert.py`) |
| `0x00588560` | `sub_588560`, size `0x238` / 568 bytes (Verified with `int_convert.py`) |
| `0x00588e30` | `sub_588E30`, size `0x343` / 835 bytes (Verified with `int_convert.py`) |
| `0x0058af40` | `sub_58AF40`, size `0x8` / 8 bytes (Verified with `int_convert.py`) |
| `0x0058af48` | not a function |
| `0x0058af50` | `sub_58AF50`, size `0x19e` |
| `0x0069bc0c` | not a function |

`get_bytes 0x0058af3b size 21` returned five `0xcc` bytes, the `0x0058af40` helper bytes `b8 01 00 00 00 c2 08 00`, then eight `0xcc` bytes. This reconfirms `0x0058af40-0x0058af48` is the successor helper after [UID:0001J6] and that `0x0058af48` is padding, not another function.

### Singleton And Data Xrefs

Current MCP `xrefs_to` and byte reads confirm:

| Address | Current evidence |
| --- | --- |
| `0x0069bc0c` | 7 refs: `0x00588239`, `0x00588240`, `0x005882da`, `0x00588620`, `0x00588627`, `0x0058aaa0`, `0x0058ace0`. |
| `0x0069bc10` | 6 refs: `0x005883c0`, `0x005885b8`, `0x005885bf`, `0x005887e9`, `0x0058aab0`, `0x0058ad6c`. |
| `0x0069bc14` | 0 refs. |
| `0x0067adc4` | 16 refs, including `SystemMessagePane` constructor/destructor/clear refs and current-mode UI consumers. |
| `0x0069b4c8` | 7 refs, including `OldSystemMessagePane` constructor/fallback writes, old-mode consumers, clear helper, and destructor clear. |
| `0x0058af40` | exactly 2 data refs: header marker vtable cell `0x0062d6c4` and footer marker vtable cell `0x0062d6e8`. |
| `0x0069bc18` | 2 refs in `sub_586480`: `0x0058668d` and table-base load `0x00586a08`. |
| `0x0069bd08` | 2 refs in `sub_589D30`: `0x00589e56` and table-base load `0x0058a1d1`. |

`get_bytes 0x0069bc0c size 12` returned twelve zero bytes. `get_int u32le` at `0x0069bc0c`, `0x0069bc10`, and `0x0069bc14` returned zero. `get_bytes` and `get_int` also showed zero-initialized leading dwords for `0x0069bc18` and `0x0069bd08`.

### Representative Decompilation Facts

Current MCP `analyze_function` confirms:

- `0x00584ea0` constructs `SystemMessagePane`, publishes `unk_67ADC4`, installs three `SystemMessagePane` vtables, initializes ten tile/resource contexts, allocates the message-list container, and is called from `0x0058875e` and `0x005889b6`.
- `0x00587890` allocates 4 bytes, constructs an `LObject` shell through `sub_4F4A80`, installs `HeaderSystemMessage` vtable, and returns null on allocation failure.
- `0x00587900` has the same factory shape for `FooterSystemMessage`.
- `0x00587ae0` is vtable-backed at `0x0062d70c`, reads text from this object's `+0x04` slot, calls `sub_4BB070` with text length and width, and clamps the result to at least one line.
- `0x005881f0` constructs `NewSystemMessageModifyHeightPane`, publishes or clears `unk_69BC0C`, installs three vtable views, clears byte `+256`, reads config height state, and initializes the preview rectangle.
- `0x00588560` constructs `NewSystemMessagePane`, publishes `unk_69BC10`, constructs a nested `NewSystemMessageModifyHeightPane` of `0x114` / 276 bytes (Verified with `int_convert.py`), constructs `SpelledPane`, initializes the embedded name/source buffer, constructs the child `SystemMessagePane`, and has direct caller `0x004b88ae`.
- `0x00588e30` constructs `OldSystemMessagePane`, publishes `unk_69B4C8`, installs three vtable views, builds ten tile contexts, uses `off_62D974`, seeds message entries, and has direct caller `0x004f8861`.
- `0x0058af40` decompiles as `int __stdcall sub_58AF40(int a1, int a2) { return 1; }`, has no callees, and is referenced only by the header/footer vtable cells.
- `0x00586480` is the current `SystemMessagePane` help/resource path. It calls `sub_4F0350`, uses `off_62D98C`, and its xrefs to `0x0069bc18` are the first resource pointer table evidence.
- `0x00589d30` is the old-system-message help/resource path. Its decompilation writes `unk_69BD08` and subsequent `unk_69BDxx` cells from `sub_4F0350` resource lookups and empty-string fallback, matching the second resource pointer table.

## Heuristic / Source-Quality Reanalysis

The empty markers are not a single missing-body problem. I re-ran the score-blocker audit in three buckets: class declaration shells, exact data declarations, and folded/generated-binary routes.

- The four by-global singleton pages have exact names, exact storage, exact xrefs, and direct source-family ownership. They are ready for first-draft pointer declarations using C++98-era `0`, with local forward declarations for the class types.
- The two exact singleton storage by-memory pages should not duplicate declarations. The by-global parents are the source symbols; the by-memory children should use formal covered-by comments.
- The `0x0069bc0c-0x0069bc18` aggregate should not declare all three dwords. Two live declarations are owned by the by-global pages; `0x0069bc14` has zero xrefs and remains reviewed reserved storage.
- The resource pointer table children are declaration-ready at first-draft quality. The exact pages prove two 0xf0-byte writable pointer arrays, each with 60 dword slots, separate initializer functions, table-base xrefs, zero-initialized storage, and common ownership under [UID:0000OE]. The best source-facing declarations are file-static arrays named by their owning class paths: `s_systemMessagePaneResourcePointers[60]` for [UID:0002ZV] and `s_oldSystemMessagePaneResourcePointers[60]` for [UID:0002ZW]. The aggregate [UID:0002AP] should stay comment-only because it has no independent source symbol beyond the two exact child arrays.
- The `0x0058af40` helper is exact code, but not a standalone source helper. It is a vtable-slot implementation of the header/footer marker one-line count behavior. A free `HeaderFooter...` function would be a binary artifact because the body has no direct calls, no callees, and only two marker vtable-cell refs. The implementation-ready plan is comment-only for [UID:000246] now, then explicit virtual line-count behavior in the `HeaderSystemMessage` and `FooterSystemMessage` class declarations when those declarations become safe.
- [UID:0001J6] remains correctly non-emitting. It is not the source owner and should not re-enter `SystemMessagePanes.cpp` as an aggregate marker or body.

## Per-Class Declaration-Shell Audits

Each class marker was checked for constructor/destructor route, vtable slots, method inventory, field/offset evidence, base class evidence, direct child ownership, and whether a declaration shell with `[[CHILDREN]]` would be safe. The decision is not based on missing original symbols; it is based on the current source ABI risk for each class.

### [UID:000030] ColorStringSystemMessage

- Evidence checked: constructor `0x00587970-0x00587a0f`, `Clone` `0x00587a70-0x00587ae0`, `GetLineCount` `0x00587ae0-0x00587b53`, `Draw` `0x00587b60-0x00587ba4`, scalar deleting destructor `0x0058ab50-0x0058abe7`, exact vtable child [UID:0003GF], shared false marker slots [UID:0001GG], shared `GetSingleLineCount` helper [UID:00016F], and current class page field evidence.
- Constructor/destructor route: source-owned by [UID:0000OE], with heap-owned UTF-16 text storage and cleanup in the scalar deleting destructor. The method map is strong enough for documentation and future implementation.
- Vtable slots: exact child [UID:0003GF] proves destructor, inherited/runtime slots, two false marker predicates at `+0x0c/+0x10`, `Clone` at `+0x14`, `GetLineCount` at `+0x18`, and `Draw` at `+0x1c`.
- Field/offset evidence: the `+0x04` text pointer is proven by `GetLineCount`; color/style fields are behavior-backed by constructor/clone/draw, but the object base and exact member declarations are not separated into an ABI-safe layout.
- Direct child ownership: vtable data routes to this class; executable method bodies are in the broad [UID:0001J6] split index and not split into exact by-memory child pages for `[[CHILDREN]]` insertion.
- Declaration-shell test: unsafe. A shell with `[[CHILDREN]]` would currently import no exact method bodies and would have to invent the `LObject`-derived interface and member layout. A shell with virtual declarations would choose final prototypes for `Clone`, `GetLineCount`, and `Draw` before the base/interface ABI is documented. No-code comment is the rare no-improvement exception for this marker.

### [UID:000061] HeaderSystemMessage

- Evidence checked: factory `0x00587890-0x005878ff`, shared scalar deleting destructor [UID:0001B5], shared true/false marker stubs [UID:0001GG], one-line virtual [UID:000246], exact vtable child [UID:0003GD], and class page vtable layout.
- Constructor/destructor route: the factory allocates four bytes, constructs an `LObject` shell, installs the `HeaderSystemMessage` vtable, and returns null only on allocation failure. The destructor slot is shared `LObject` scalar-delete glue reused outside this marker pair.
- Vtable slots: [UID:0003GD] proves slot `+0x00` shared destructor, `+0x04/+0x08` inherited/runtime slots, `+0x0c` true `IsHeaderMarker` pattern, `+0x10` false `IsFooterMarker` pattern, `+0x14` factory, `+0x18` one-line virtual at `0x0058af40`, and `+0x1c` null/inherited slot.
- Field/offset evidence: the instance body is only the vptr in the recovered factory; there are no class-owned data fields beyond the `LObject` shell.
- Direct child ownership: vtable data routes to this class, while folded helper bodies are shared/no-owner or file-level because their physical bodies are reused outside this exact class.
- Declaration-shell test: unsafe. A shell with only `[[CHILDREN]]` would not represent the slot layout, and a shell with virtual methods would have to decide whether `+0x18` is inherited from an unmodeled marker-entry base or two identical folded overrides. Current implementation should use a formal comment. Future class-source implementation should express the one-line count behavior on the header class, not as a free helper body.

### [UID:00005D] FooterSystemMessage

- Evidence checked: factory `0x00587900-0x0058796f`, shared scalar deleting destructor [UID:0001B5], shared true/false marker stubs [UID:0001GG], one-line virtual [UID:000246], exact vtable child [UID:0003GE], and class page vtable layout.
- Constructor/destructor route: the factory allocates four bytes, constructs an `LObject` shell, installs the `FooterSystemMessage` vtable, and returns null only on allocation failure. The destructor slot is shared `LObject` scalar-delete glue reused outside this marker pair.
- Vtable slots: [UID:0003GE] proves slot `+0x00` shared destructor, `+0x04/+0x08` inherited/runtime slots, `+0x0c` false `IsHeaderMarker` pattern, `+0x10` true `IsFooterMarker` pattern, `+0x14` factory, `+0x18` one-line virtual at `0x0058af40`, and `+0x1c` null/inherited slot.
- Field/offset evidence: the instance body is only the vptr in the recovered factory; there are no class-owned data fields beyond the `LObject` shell.
- Direct child ownership: vtable data routes to this class, while folded helper bodies are shared/no-owner or file-level because their physical bodies are reused outside this exact class.
- Declaration-shell test: unsafe for the same concrete reason as the header marker: current evidence cannot distinguish inherited default slot from folded identical overrides, and no exact method-body children exist for `[[CHILDREN]]`. Current implementation should use a formal comment. Future class-source implementation should express the one-line count behavior on the footer class, not as a free helper body.

### [UID:00009B] NewSystemMessageModifyHeightPane

- Evidence checked: constructor `0x005881f0-0x005882b4`, cleanup `0x005882c0-0x005882e8`, drag handler `0x005882f0-0x005884ab`, paint `0x00588500-0x0058855b`, singleton clear helper `0x0058aaa0-0x0058aaaa`, scalar deleting destructor `0x0058acc0-0x0058ad1e`, exact vtable child [UID:0003GM], singleton slot [UID:0002AO], and global [UID:0000R2].
- Constructor/destructor route: constructor publishes `g_pHeightModifyPane`, installs three vtable views, reads persisted height, and initializes drag/preview state; cleanup/destructor clear the singleton and restore/tear down pane state.
- Vtable slots: [UID:0003GM] proves three vtable views at `0x0062d7b4`, `0x0062d800`, and `0x0062d830`, with lifecycle refs from constructor, cleanup, nested construction, and scalar deleting destructor.
- Field/offset evidence: offsets `+160/+164` are adjusted vtable views, `+248` is saved height state, `+256` is a drag byte, and `+260` begins preview rect/state. Delete size is `0x114` / 276 bytes (Verified with `int_convert.py`).
- Direct child ownership: vtable data and singleton global route to this class; the neighbor constructor `0x00588560` is explicitly owned by `NewSystemMessagePane`, not this class.
- Declaration-shell test: unsafe. A shell would have to choose the base pane class/interface, event parameter type, rect/member types, and nested owner relationship. A `[[CHILDREN]]` shell has no exact child method pages to pull in and would not fix the generated partition issue. The safe implementation is a class disposition comment.

### [UID:00009C] NewSystemMessagePane

- Evidence checked: constructor `0x00588560-0x00588797`, `RebuildMessagePanes` `0x00588800-0x00588c0c`, `RefreshWorldMapPane` `0x00588d50-0x00588d6e`, `OnPaint` `0x00588d90-0x00588dfb`, tiny virtual helpers `0x00588e00-0x00588e15`, clear helper `0x0058aab0-0x0058aaba`, thunks `0x0058ab07-0x0058ab1d`, scalar deleting destructor `0x0058ad20-0x0058adab`, exact vtable child [UID:0003GN], global [UID:0000RU], and direct caller `0x004b88ae`.
- Constructor/destructor route: constructor publishes `g_pNewSystemMessagePane`, constructs nested `NewSystemMessageModifyHeightPane` of `0x114` / 276 bytes, creates `SpelledPane`, constructs child `SystemMessagePane`, and installs three vtable views. Destructor clears the singleton and conditionally deletes storage of `0x304` / 772 bytes (Verified with `int_convert.py`).
- Vtable slots: [UID:0003GN] proves three vtable views at `0x0062d83c`, `0x0062d88c`, and `0x0062d8bc`, with constructor/destructor/scalar-delete refs and successor `OldSystemMessagePane` boundary.
- Field/offset evidence: child-pane/member roles are behavior-backed, but the recovered constructor still exposes raw layout and generated mispartition. The child `SystemMessagePane` and `SpelledPane` ownership relationship is documented but not declaration-ready.
- Direct child ownership: vtable data and singleton global route to this class; exact method children are not split for source insertion.
- Declaration-shell test: unsafe. A shell would encode member order and base virtual interface before the new-pane wrapper layout is stable. `[[CHILDREN]]` alone would not import the constructor/body facts and could imply a complete class declaration that the current docs do not support.

### [UID:00009T] OldSystemMessagePane

- Evidence checked: constructor `0x00588e30-0x00589173`, support helpers `0x00589180-0x0058948f`, scroll metrics `0x00589540-0x00589668`, help handler `0x00589670-0x005896c0`, secondary helper `0x005896c0-0x005898f3`, draw `0x00589920-0x00589c0c`, total line count `0x00589c80-0x00589cea`, thunks `0x0058ab1d-0x0058ab33`, destructor `0x0058adb0-0x0058af00`, exact vtable child [UID:0003DM], global [UID:0003ED], and direct caller `0x004f8861`.
- Constructor/destructor route: constructor publishes old singleton storage at `0x0069b4c8`, installs three vtable views, constructs ten tile contexts, uses resource tail `0x0062d974`, and seeds message entries. Destructor clears the singleton, walks entries, tears down ten tile contexts, and destroys the scrollable pane base.
- Vtable slots: [UID:0003DM] proves three vtable heads at `0x0062d8c8`, `0x0062d93c`, and `0x0062d96c`, each with constructor/reset/destructor lifecycle refs.
- Field/offset evidence: offsets include three vtable views at `+0/+0xa0/+0xa4`, message-list/refresh state around `+0x130/+0x134`, and ten tile contexts beginning around `+312`; these are behavior-backed but not a complete source class layout.
- Direct child ownership: vtable data routes to this class; method bodies remain inside [UID:0001J6] and are not exact child pages for `[[CHILDREN]]`.
- Declaration-shell test: unsafe. A declaration would have to choose the scrollable base class ABI, adjusted-base inheritance layout, and ten tile-context member declarations. A `[[CHILDREN]]` shell has no exact body children and would leave the most important source facts outside the declaration.

### [UID:0000EA] SystemMessagePane

- Evidence checked: constructor `0x00584ea0-0x005851d9`, destructor `0x005851e0-0x00585358`, refresh/prune `0x00585360-0x005854ac`, append helpers `0x005854b0`, `0x005854d0`, `0x00585560`, insert helper `0x00585580-0x005856e9`, scroll metrics `0x005856f0-0x005858c8`, key handler `0x005858d0-0x00585920`, packet handler `0x00585920-0x00585b53`, paint `0x00585b80-0x00586200`, content-height `0x00586370-0x0058643b`, thunks `0x0058ab33-0x0058ab49`, scalar deleting destructor `0x0058af00-0x0058af3b`, exact vtable child [UID:0003DI], and global [UID:0002WV].
- Constructor/destructor route: constructor publishes `g_pChattingViewport`, installs three vtable views, initializes ten normal-mode tile contexts or high-resolution dynamic entries, and creates the message list. Destructor deletes entries/list storage, tears down tile contexts, clears `g_pChattingViewport`, and destroys base pane state.
- Vtable slots: [UID:0003DI] proves primary/secondary/tertiary vtable heads at `0x0062d5fc`, `0x0062d670`, and `0x0062d6a0`, with constructor/destructor store pairs and successor `HeaderSystemMessage` locator boundary.
- Field/offset evidence: current docs prove `m_refreshOnAppend` behavior around `+0x130`, message list at `+0x134`, adjusted vtable views at `+0xa0/+0xa4`, and tile contexts around `+312`, but not enough to declare the full base/subobject layout.
- Direct child ownership: vtable data and singleton global route to this class; method body islands remain in [UID:0001J6] and are not exact child pages for `[[CHILDREN]]`.
- Declaration-shell test: unsafe. A shell would need inherited scroll/tile API names, adjusted-base declarations, list/member types, and virtual prototypes. `[[CHILDREN]]` alone cannot carry the method bodies and would not regenerate the vtable family.

## Resource Pointer Table Declaration Audit

- [UID:0002ZV] is the first `0xf0`-byte table from `0x0069bc18-0x0069bd08`: 60 writable dword slots (Verified with `int_convert.py`) initialized by `sub_586480`, with table-base refs at `0x0058668d` and `0x00586a08`.
- [UID:0002ZW] is the second `0xf0`-byte table from `0x0069bd08-0x0069bdf8`: 60 writable dword slots (Verified with `int_convert.py`) initialized by `sub_589D30`, with table-base refs at `0x00589e56` and `0x0058a1d1`.
- Both initializers call `sub_4F0350` with resource IDs, fall back through `word_60DB20`, and then iterate from the table base. Both exact children are owned by [UID:0000OE].
- Best inferred declaration shape: file-static writable arrays in `social/SystemMessagePanes.cpp`, not member arrays. The table storage is zero-initialized at file scope, has global data addresses, and is filled by file-local helper paths rather than by object construction as per-instance members.
- Best inferred names: `s_systemMessagePaneResourcePointers` and `s_oldSystemMessagePaneResourcePointers`. These names preserve the documented class path and avoid raw `dword_69BC18` labels. They are stronger than comment-only because the two child pages already prove owner, bounds, initializer, and role. The aggregate [UID:0002AP] remains comment-only so the source does not declare a third symbol for a physical cluster.

## Header/Footer One-Line Virtual Audit

- The body at `0x0058af40-0x0058af48` is exact: `mov eax, 1; retn 8`, size `0x8` / 8 bytes (Verified with `int_convert.py`), no callees, and exactly two data refs from header/footer vtable cells `0x0062d6c4` and `0x0062d6e8`.
- It is not a standalone helper: no direct code callers, no address-taken refs outside the two vtable cells, and no evidence for a source-level free function name.
- It should not be emitted as a shared local helper in this report. That would make a binary folding artifact part of the source API.
- It should not be emitted as an inline body on [UID:000246] because [UID:000246] is a physical by-memory helper page, not a class declaration page.
- Implementation-ready class plan: when `HeaderSystemMessage` and `FooterSystemMessage` class declarations are safe, represent slot `+0x18` as the marker entry line-count virtual returning one line on both classes, using the same pane/context and width argument shape documented by `ColorStringSystemMessage::GetLineCount`. If later evidence proves an inherited marker-entry base with that default, route it through that base; current evidence does not justify introducing such a base now.

## Formal C++ / No-Code Blocks

These are exact formal insertion blocks for a supervisor-approved implementation callback. Metadata not listed here should stay unchanged unless the callback explicitly accepts the target file score update.

### [UID:000030] `by-class/ColorStringSystemMessage.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ColorStringSystemMessage belongs to social/SystemMessagePanes.cpp, but the
// class declaration is intentionally withheld here after B011 audited the
// constructor, Clone, GetLineCount, Draw, destructor, exact vtable child
// [UID:0003GF], text pointer at +0x04, and shared GetSingleLineCount dependency.
// A [[CHILDREN]] shell would currently import no exact method-body children and
// a virtual declaration shell would invent the LObject-derived interface ABI.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00005D] `by-class/FooterSystemMessage.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// FooterSystemMessage is a tiny marker-entry class in social/SystemMessagePanes.cpp.
// B011 audited its 4-byte LObject factory, exact vtable child [UID:0003GE],
// shared destructor slot, marker predicate slots, and +0x18 one-line virtual.
// No declaration shell is emitted here because current evidence cannot safely
// choose between an inherited default and identical folded marker overrides.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:000061] `by-class/HeaderSystemMessage.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// HeaderSystemMessage is a tiny marker-entry class in social/SystemMessagePanes.cpp.
// B011 audited its 4-byte LObject factory, exact vtable child [UID:0003GD],
// shared destructor slot, marker predicate slots, and +0x18 one-line virtual.
// No declaration shell is emitted here because current evidence cannot safely
// choose between an inherited default and identical folded marker overrides.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00009B] `by-class/NewSystemMessageModifyHeightPane.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// NewSystemMessageModifyHeightPane belongs to social/SystemMessagePanes.cpp, but
// class-level source is intentionally withheld here. Current evidence proves the
// constructor, drag/commit handler, paint path, singleton lifecycle, and destructor
// family, including exact vtable child [UID:0003GM], +248/+256/+260 state, and
// 0x114-byte allocation size. A declaration shell would have to invent the base
// pane/event ABI and member layout, so this marker records disposition only.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00009C] `by-class/NewSystemMessagePane.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// NewSystemMessagePane belongs to social/SystemMessagePanes.cpp, but the full
// class declaration is intentionally withheld here. MCP confirms constructor
// ownership at 0x00588560, caller 0x004b88ae, nested 0x114-byte height-pane
// construction, SpelledPane creation, child SystemMessagePane construction,
// exact vtable child [UID:0003GN], and singleton lifecycle. A shell would encode
// unproven member order, child ownership fields, and inherited virtual slots.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00009T] `by-class/OldSystemMessagePane.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// OldSystemMessagePane belongs to social/SystemMessagePanes.cpp, but the class
// declaration is intentionally withheld here. MCP confirms constructor ownership
// at 0x00588e30, caller 0x004f8861, singleton publication, vtable installs,
// resource/tile setup, message-entry seeding, exact vtable child [UID:0003DM],
// and destructor cleanup. A declaration shell would have to invent the scrollable
// base ABI, adjusted-base layout, and ten tile-context member declarations.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0000EA] `by-class/SystemMessagePane.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// SystemMessagePane is the current scrollable system-message viewport in
// social/SystemMessagePanes.cpp. Constructor/destructor, append/prune helpers,
// packet handling, rendering, line metrics, and g_pChattingViewport lifecycle are
// documented, including exact vtable child [UID:0003DI], +0x130 refresh behavior,
// +0x134 message list, and three vtable views. A declaration shell would have to
// invent inherited scroll/tile APIs, adjusted-base declarations, and member types.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0002WV] `by-global/g_pChattingViewport.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SystemMessagePane;

SystemMessagePane *g_pChattingViewport = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0002WW] `by-memory/0x0067adc4-0x0067adc8.g_pChattingViewport.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted declaration for this exact storage is covered by [UID:0002WV]
// g_pChattingViewport. This page carries the address, byte, xref, and lifecycle
// proof for the storage slot rather than a second source declaration.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0000R2] `by-global/g_pHeightModifyPane.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class NewSystemMessageModifyHeightPane;

NewSystemMessageModifyHeightPane *g_pHeightModifyPane = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0000RU] `by-global/g_pNewSystemMessagePane.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class NewSystemMessagePane;

NewSystemMessagePane *g_pNewSystemMessagePane = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0003ED] `by-global/g_pOldSystemMessagePane.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class OldSystemMessagePane;

OldSystemMessagePane *g_pOldSystemMessagePane = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0002W7] `by-memory/0x0069b4c8-0x0069b4cc.g_pOldSystemMessagePane.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted declaration for this exact storage is covered by [UID:0003ED]
// g_pOldSystemMessagePane. This page carries the address, byte, xref, and
// lifecycle proof for the storage slot rather than a second source declaration.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:000246] `by-memory/0x0058af40-0x0058af48.HeaderFooterSystemMessageDefaultTrueVirtual.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// This exact 0x0058af40 body is the folded HeaderSystemMessage/FooterSystemMessage
// +0x18 marker line-count virtual. It returns 1, consumes the pane/context and
// width stack arguments, and has only two vtable-cell refs. Do not emit a free
// helper; future safe marker declarations should express this as the header and
// footer one-line virtual behavior.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0002AO] `by-memory/0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// The live singleton declarations in this storage cluster are emitted by
// [UID:0000R2] g_pHeightModifyPane and [UID:0000RU] g_pNewSystemMessagePane.
// The third dword at 0x0069bc14 is reviewed zero-initialized reserved storage
// with no current xrefs, so this aggregate emits only this disposition marker.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0002ZV] `by-memory/0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static const wchar_t *s_systemMessagePaneResourcePointers[60] = { 0 };
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0002AP] `by-memory/0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// This aggregate covers the two 0xf0-byte resource pointer tables owned by
// social/SystemMessagePanes.cpp. Exact children [UID:0002ZV] and [UID:0002ZW]
// emit the two file-static array declarations; this aggregate has no independent
// source declaration to emit.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0002ZW] `by-memory/0x0069bd08-0x0069bdf8.OldSystemMessagePaneResourcePointerTable.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static const wchar_t *s_oldSystemMessagePaneResourcePointers[60] = { 0 };
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Support Docs To Update After Acceptance

1. `by-file/SystemMessagePanes.md`
   - Keep `COMPLETION:89`, `CONFIDENCE:86`.
   - Add an empty-emitter family disposition section that names this B011 report, confirms 18 empty markers, and records the four singleton declarations, two resource pointer table declarations, and twelve formal disposition comments.
   - Preserve current source root `NexusTK/social/`, file owner `FILE`, and the [UID:0001J6] non-emitting split-index rule.

2. All eighteen marker docs listed in the inventory:
   - Keep current `CANONICAL_OWNER`, `RECONSTRUCTABLE`, and `EMITTER_UIDS` unless the implementation callback narrows scope differently.
   - Insert the exact formal C++/comment block from this report.
   - Add a short change note explaining whether the block is a source declaration, a covered-by marker, or a formal no-code disposition.

3. Do not edit [UID:00016F] unless a fresh validator run changes formatting. It is already the only coded emitter in the file.

4. Do not edit [UID:0001J6] during this empty-marker callback. B006 already reclassified it as non-emitting; the current generated file no longer lists it as an empty marker.

## Rejected Alternatives

| Alternative | Decision |
| --- | --- |
| Treat all eighteen markers as missing source bodies | Rejected. The markers mix class declarations, global declarations, exact storage proof pages, folded helpers, and aggregate data. |
| Clear `EMITTER_UIDS` to remove the markers | Rejected for this callback. The routes are valid and surface to a live by-file root; the problem is missing formal block disposition, not source ownership. |
| Emit full class declarations for all seven classes now | Rejected after per-class audits above. Each class has source ownership, but current exact children are vtable/data pages rather than method-body children, and a declaration shell would invent base/interface ABI, adjusted-base layout, member layout, or folded-helper treatment. |
| Emit a standalone function body for [UID:000246] | Rejected. The binary body is a folded marker line-count virtual referenced by two marker vtable cells, not a source-level free helper. Future safe class declarations should express equivalent header/footer virtual behavior. |
| Duplicate singleton declarations in exact by-memory storage children | Rejected. The by-global pages are the source symbols; exact by-memory pages should carry address proof only. |
| Leave [UID:0002ZV] and [UID:0002ZW] as table comments only | Rejected. The exact child pages already prove source ownership, 0xf0-byte/60-slot bounds, initializer functions, base refs, and writable zero-initialized storage. Best inferred file-static array names are safer than keeping live source data empty. |
| Emit one declaration from aggregate [UID:0002AP] | Rejected. The aggregate has no independent source symbol; exact children [UID:0002ZV] and [UID:0002ZW] carry the two arrays. |
| Move the file root under `Chatting.cpp` now | Rejected. `g_pChattingViewport` is chat-adjacent, but the current/old/new system-message classes, vtables, singleton slots, help-resource paths, and pointer tables form a coherent `SystemMessagePanes.cpp` root. |
| Route ForcedInform, TerminalPane, or shared destructor/boolean-stub bodies into this file | Rejected. Existing exact pages keep those separate; this file-family report should not undo accepted split work. |

## Score Rationale

Recommended [UID:0000OE] score after implementation: keep `89/86`.

- Completion stays `89`: the file page already documents the source root, class family, executable split index, vtables, resource strings, singleton slots, and support data. This report adds implementation-ready marker disposition and two resource table declarations, but seven source-bearing class declarations still remain intentionally comment-only after audit.
- Confidence stays `86`: current MCP rechecks confirm the key function starts, singleton xrefs, byte state, folded helper refs, constructor callers, and resource-table refs. Confidence should not rise while the exact split from broader `social/Chatting.cpp` and the class declaration ABI remain below final-source quality.

Child page scores should stay unchanged in this implementation. The formal blocks clear empty markers and record disposition, but they do not newly resolve the class declaration ABI blockers.

## Validation Plan For Implementation Callback

After supervisor acceptance, run validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for every edited by-* doc. Use this form for each marker doc and the file root:

> Executable block R001 was removed from this report and preserved verbatim in [0000OE-SystemMessagePanes-empty-emitter-family-source-quality-removed.md](0000OE-SystemMessagePanes-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Recommended final generated freshness command:

> Executable block R002 was removed from this report and preserved verbatim in [0000OE-SystemMessagePanes-empty-emitter-family-source-quality-removed.md](0000OE-SystemMessagePanes-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected edited docs after acceptance:

- `by-file/SystemMessagePanes.md`
- `by-class/ColorStringSystemMessage.md`
- `by-class/FooterSystemMessage.md`
- `by-class/HeaderSystemMessage.md`
- `by-class/NewSystemMessageModifyHeightPane.md`
- `by-class/NewSystemMessagePane.md`
- `by-class/OldSystemMessagePane.md`
- `by-class/SystemMessagePane.md`
- `by-global/g_pChattingViewport.md`
- `by-memory/0x0067adc4-0x0067adc8.g_pChattingViewport.md`
- `by-global/g_pHeightModifyPane.md`
- `by-global/g_pNewSystemMessagePane.md`
- `by-global/g_pOldSystemMessagePane.md`
- `by-memory/0x0069b4c8-0x0069b4cc.g_pOldSystemMessagePane.md`
- `by-memory/0x0058af40-0x0058af48.HeaderFooterSystemMessageDefaultTrueVirtual.md`
- `by-memory/0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md`
- `by-memory/0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable.md`
- `by-memory/0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables.md`
- `by-memory/0x0069bd08-0x0069bdf8.OldSystemMessagePaneResourcePointerTable.md`

Report each validator command id, command timestamp, exit code, `ok` count, generated-refresh state, and any pre-existing missing-ref warnings. Do not manually edit generated output or coverage reports.

## Claim And Incorporation Ledger

| ID | Claim | Confidence | Destination after acceptance | Callback verification state |
| --- | --- | --- | --- | --- |
| C01 | `SystemMessagePanes.cpp` has 19 emitters, 1 coded and 18 empty, under by-file UID `0000OE`. | High | `by-file/SystemMessagePanes.md` | Applied in `## B011 Empty-Emitter Family Disposition`: the file records [UID:00016F] as already coded and the 18 former empty markers as six declarations plus twelve formal disposition comments. Final generated `auto-generated/NexusTK/social/SystemMessagePanes.cpp` renders those former empty slots as comments/declarations. |
| C02 | Keep [UID:0000OE] as `NexusTK/social/SystemMessagePanes.cpp` source root and keep score `89/86`; do not raise to `90/88` while seven class declarations remain comment-only. | High | `by-file/SystemMessagePanes.md` | Applied: header still has `COMPLETION:89`, `CONFIDENCE:86`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/social/"`, and `CANONICAL_OWNER:FILE`; new B011 section documents the rejected `90/88` raise. |
| C03 | [UID:000030] should use a formal no-code comment after audit of constructor, clone, line-count, draw, destructor, vtable child [UID:0003GF], and field `+0x04`; no declaration shell is safe. | High | `by-class/ColorStringSystemMessage.md` | Applied: exact formal comment inserted; `## B011 Declaration-Shell Audit` preserves constructor `0x00587970`, `Clone`, `GetLineCount`, `Draw`, destructor, [UID:0003GF], false marker slots, [UID:00016F], and offset `+0x04` proof. |
| C04 | [UID:000061] and [UID:00005D] should use formal no-code comments after marker audits; factories/vtable slots are proven, but the `+0x18` one-line virtual should be represented in future class declarations, not as a free helper. | High | `by-class/HeaderSystemMessage.md`, `by-class/FooterSystemMessage.md` | Applied: exact formal comments inserted; both class audit sections preserve the four-byte factory routes, exact vtable children [UID:0003GD]/[UID:0003GE], shared destructor/boolean slots, [UID:000246], and the inherited-default versus folded-override blocker. |
| C05 | [UID:00009B] should use a formal no-code comment after offset/vtable audit; constructor/handler/destructor evidence is strong but the base/event/member ABI is not declaration-safe. | High | `by-class/NewSystemMessageModifyHeightPane.md` | Applied: exact formal comment inserted; B011 audit section preserves constructor/cleanup/drag/paint/destructor family, [UID:0003GM], `+248/+256/+260`, singleton relationship, and `0x114` allocation proof. |
| C06 | [UID:00009C] should use a formal no-code comment after constructor/vtable audit; exact lifecycle is known but child/member layout and inherited virtuals are not declaration-safe. | High | `by-class/NewSystemMessagePane.md` | Applied: exact formal comment inserted; B011 audit section preserves constructor `0x00588560`, caller `0x004b88ae`, nested height-pane, `SpelledPane`, child `SystemMessagePane`, [UID:0003GN], singleton lifecycle, `0x304` layout evidence, and rejected shell rationale. |
| C07 | [UID:00009T] should use a formal no-code comment after legacy-pane audit; exact lifecycle is known but adjusted-base layout and tile/member declarations are not safe. | High | `by-class/OldSystemMessagePane.md` | Applied: exact formal comment inserted; B011 audit section preserves constructor `0x00588e30`, caller `0x004f8861`, singleton route, three-view vtable evidence, tile-context setup, [UID:0003DM], destructor cleanup, and rejected adjusted-base/member shell rationale. |
| C08 | [UID:0000EA] should use a formal no-code comment after scroll-pane audit; exact method islands and global lifecycle are known but three-view vtable/member layout is not safe. | High | `by-class/SystemMessagePane.md` | Applied: exact formal comment inserted; B011 audit section preserves constructor/destructor/helper/packet/render/metrics inventory, [UID:0003DI], `+0x130`, `+0x134`, three vtable views, `g_pChattingViewport`, and rejected scroll/tile ABI shell rationale. |
| C09 | Four singleton globals should emit pointer declarations with C++98-era `0` initialization. | Medium-high | `0002WV`, `0000R2`, `0000RU`, `0003ED` | Applied: `by-global/g_pChattingViewport.md`, `by-global/g_pHeightModifyPane.md`, `by-global/g_pNewSystemMessagePane.md`, and `by-global/g_pOldSystemMessagePane.md` emit the accepted forward declaration plus pointer initialization blocks. |
| C10 | Exact singleton storage by-memory children should be covered-by comments, not duplicate declarations. | High | `0002WW`, `0002W7` | Applied: exact storage pages now carry formal covered-by comments and B011 covered-by sections; summaries were refreshed to current zero-filled storage rather than stale `0xffffffff`/unassigned wording. |
| C11 | [UID:000246] should not emit a standalone body despite exact behavior; it is folded header/footer marker line-count virtual behavior. | High | [UID:000246] | Applied: formal folded-virtual comment inserted; B011 section preserves `mov eax, 1; retn 8`, size `0x8`, two vtable-cell refs, no direct callers, no free-helper evidence, and future Header/Footer class-representation plan. |
| C12 | Singleton-slot aggregate should be a covered-by/reserved-data formal marker. | High | [UID:0002AO] | Applied: formal covered-by/reserved-storage marker inserted; B011 section preserves live declarations through [UID:0000R2]/[UID:0000RU], zero-xref reserved `0x0069bc14`, predecessor/successor boundaries, and no third dword declaration. |
| C13 | [UID:0002ZV] should emit `static const wchar_t *s_systemMessagePaneResourcePointers[60] = { 0 };`. | Medium-high | [UID:0002ZV] | Applied: exact static array declaration inserted; B011 table section preserves `0xf0` bytes/60 dword slots, zero initialization, `sub_586480`, table-base refs, `sub_4F0350`, `word_60DB20`, and no aggregate duplicate. |
| C14 | [UID:0002ZW] should emit `static const wchar_t *s_oldSystemMessagePaneResourcePointers[60] = { 0 };`. | Medium-high | [UID:0002ZW] | Applied: exact static array declaration inserted; B011 table section preserves `0xf0` bytes/60 dword slots, zero initialization, `sub_589D30`, table-base refs, `sub_4F0350`, `word_60DB20`, and no aggregate duplicate. |
| C15 | [UID:0002AP] should remain an aggregate formal comment because exact children emit the two table declarations. | High | [UID:0002AP] | Applied: formal aggregate comment inserted; B011 aggregate section preserves two-table physical cluster, common [UID:0000OE] ownership, exact split at `0x0069bd08`, singleton predecessor boundary, shared lookup/fallback model, and no third wrapper/table symbol. |
| C16 | Current MCP health and schema are available and sufficient for report evidence. | High | Report evidence section | Already present for accepted report. Implementation callback did not require new MCP calls because the supervisor accepted the MCP-backed report and requested doc incorporation/validation. |
| C17 | No implementation edits, generated edits, validators, or leases should occur in report-only phase. | High | Report final/checklist | Superseded by accepted implementation callback: callback edits were applied only to accepted by-* docs plus this report, generated output was refreshed only by validators, and B011 leases were released after validation. |

## Implementation Callback Validator Proof

Working directory for all validators: `E:\NTK\GhidraBridge\source-3\project-documentation`.

| Path | Command id | Timestamp | Exit | Ok | Generated refresh | Warnings/side effects |
| --- | --- | --- | --- | --- | --- | --- |
| `by-class/ColorStringSystemMessage.md` | `000000002188` | `2026-06-30T04:42:56-04:00` | 0 | 1 | deferred | `missing_ref_uid` count 8 for pre-existing vtable/support UID refs; registry/stats/projected-stats updated by validator. |
| `by-class/FooterSystemMessage.md` | `000000002189` | `2026-06-30T04:43:24-04:00` | 0 | 1 | deferred | `missing_ref_uid` count 10 for pre-existing vtable/support UID refs. |
| `by-class/HeaderSystemMessage.md` | `000000002190` | `2026-06-30T04:43:27-04:00` | 0 | 1 | deferred | `missing_ref_uid` count 10 for pre-existing vtable/support UID refs. |
| `by-class/NewSystemMessageModifyHeightPane.md` | `000000002191` | `2026-06-30T04:43:28-04:00` | 0 | 1 | deferred | `missing_ref_uid` count 8 for pre-existing vtable/support UID refs. |
| `by-class/NewSystemMessagePane.md` | `000000002192` | `2026-06-30T04:43:30-04:00` | 0 | 1 | deferred | `missing_ref_uid` count 8 for pre-existing vtable/support UID refs. |
| `by-class/OldSystemMessagePane.md` | `000000002193` | `2026-06-30T04:43:32-04:00` | 0 | 1 | deferred | `missing_ref_uid` count 8 for pre-existing vtable/support UID refs. |
| `by-class/SystemMessagePane.md` | `000000002194` | `2026-06-30T04:43:34-04:00` | 0 | 1 | deferred | `missing_ref_uid` count 10 for pre-existing vtable/support UID refs. |
| `by-global/g_pChattingViewport.md` | `000000002195` | `2026-06-30T04:43:36-04:00` | 0 | 1 | deferred | No missing-ref warnings. |
| `by-memory/0x0067adc4-0x0067adc8.g_pChattingViewport.md` | `000000002196` | `2026-06-30T04:43:38-04:00` | 0 | 1 | deferred | `missing_ref_uid` count 3 for pre-existing refs. |
| `by-global/g_pHeightModifyPane.md` | `000000002197` | `2026-06-30T04:43:39-04:00` | 0 | 1 | deferred | No missing-ref warnings. |
| `by-global/g_pNewSystemMessagePane.md` | `000000002199` | `2026-06-30T04:43:41-04:00` | 0 | 1 | deferred | No missing-ref warnings. |
| `by-global/g_pOldSystemMessagePane.md` | `000000002200` | `2026-06-30T04:43:43-04:00` | 0 | 1 | deferred | No missing-ref warnings. |
| `by-memory/0x0069b4c8-0x0069b4cc.g_pOldSystemMessagePane.md` | `000000002201` | `2026-06-30T04:43:45-04:00` | 0 | 1 | deferred | No missing-ref warnings. |
| `by-memory/0x0058af40-0x0058af48.HeaderFooterSystemMessageDefaultTrueVirtual.md` | `000000002203` | `2026-06-30T04:43:47-04:00` | 0 | 1 | deferred | `missing_ref_uid` count 3 for pre-existing refs. |
| `by-memory/0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md` | `000000002205` | `2026-06-30T04:43:59-04:00` | 0 | 1 | deferred | No missing-ref warnings. |
| `by-memory/0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable.md` | `000000002207` | `2026-06-30T04:44:11-04:00` | 0 | 1 | deferred | No missing-ref warnings. |
| `by-memory/0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables.md` | `000000002209` | `2026-06-30T04:44:23-04:00` | 0 | 1 | deferred | No missing-ref warnings. |
| `by-memory/0x0069bd08-0x0069bdf8.OldSystemMessagePaneResourcePointerTable.md` | `000000002211` | `2026-06-30T04:44:35-04:00` | 0 | 1 | deferred | No missing-ref warnings. |
| `by-file/SystemMessagePanes.md --wait-generated` | `000000002319` | `2026-06-30T04:54:53-04:00` | 0 | 1 | completed | `missing_ref_uid` count 12 for pre-existing vtable/support UID refs; validator refreshed generated C++ metadata, generated reports, projected stats, and validator registry. This was a target-only rerun after shared deferred generated-refresh jobs briefly rewrote `SystemMessagePanes.cpp` to an older support-doc header. |

Generated freshness proof: `auto-generated/NexusTK/social/SystemMessagePanes.cpp` header has `validator-command-id: 000000002319` and `validator-refreshed-at: 2026-06-30T04:54:53-04:00`, equal to the final command `000000002319` / `2026-06-30T04:54:53-04:00`. The generated file contains the accepted singleton declarations, the two static resource pointer arrays, the folded virtual disposition comment, the aggregate table disposition comment, and the seven class disposition comments.

## Implementation Tracking Checklist

Report-only pass:

- [x] Read the updated Agent-B011 goal and project B-agent workflow guidance.
- [x] Re-read target and generated output current state.
- [x] Search current generated/coverage reports and existing B-agent reports for `0000OE`, `SystemMessagePanes`, prominent child UIDs, and related source-family names.
- [x] Satisfy MCP requirement with schema-current live IDA calls.
- [x] Repaired rejected report without rewriting from scratch.
- [x] Added per-class audits for [UID:000030], [UID:00005D], [UID:000061], [UID:00009B], [UID:00009C], [UID:00009T], and [UID:0000EA].
- [x] Re-audited [UID:0002ZV], [UID:0002AP], and [UID:0002ZW] and converted exact child table dispositions to source declarations.
- [x] Re-audited [UID:000246] and tied the comment-only disposition to a future Header/Footer class implementation plan.
- [x] Re-evaluated [UID:0000OE] score recommendation and kept `89/86`.
- [x] Produce implementation-ready formal C++/comment blocks for every current empty marker.
- [x] Do not edit target/support by-* docs, generated output, coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, or lock files.
- [x] Do not spawn subagents.
- [x] Do not take leases during report-only phase.

Implementation callback checklist after supervisor acceptance:

- [x] Lease only the by-* docs about to be edited immediately. Proof: B011 lease batch succeeded for all 19 accepted by-* paths before the final edit/validator batch.
- [x] Update `by-file/SystemMessagePanes.md`: kept `89/86`, preserved `NexusTK/social/` and `CANONICAL_OWNER:FILE`, added B011 empty-emitter family disposition, recorded six declarations and twelve comments, and preserved [UID:0001J6] as non-emitting split index.
- [x] Update `by-class/ColorStringSystemMessage.md`: inserted the exact [UID:000030] formal comment and B011 audit/change note covering constructor/Clone/GetLineCount/Draw/destructor, [UID:0003GF], field `+0x04`, and rejected declaration shell.
- [x] Update `by-class/HeaderSystemMessage.md`: inserted the exact [UID:000061] formal comment and B011 audit/change note covering factory `0x00587890`, [UID:0003GD], shared destructor, marker slots, [UID:000246], and rejected inherited-default/folded-override choice.
- [x] Update `by-class/FooterSystemMessage.md`: inserted the exact [UID:00005D] formal comment and B011 audit/change note covering factory `0x00587900`, [UID:0003GE], shared destructor, marker slots, [UID:000246], and rejected inherited-default/folded-override choice.
- [x] Update `by-class/NewSystemMessageModifyHeightPane.md`: inserted the exact [UID:00009B] formal comment and B011 audit/change note covering constructor/drag/paint/destructor family, [UID:0003GM], `+248/+256/+260` state, and `0x114` allocation.
- [x] Update `by-class/NewSystemMessagePane.md`: inserted the exact [UID:00009C] formal comment and B011 audit/change note covering constructor `0x00588560`, caller `0x004b88ae`, nested height-pane, `SpelledPane`, child `SystemMessagePane`, [UID:0003GN], singleton lifecycle, and rejected layout shell.
- [x] Update `by-class/OldSystemMessagePane.md`: inserted the exact [UID:00009T] formal comment and B011 audit/change note covering constructor `0x00588e30`, caller `0x004f8861`, singleton, three vtable views, tile contexts, [UID:0003DM], and rejected adjusted-base/member shell.
- [x] Update `by-class/SystemMessagePane.md`: inserted the exact [UID:0000EA] formal comment and B011 audit/change note covering constructor/destructor/helpers, [UID:0003DI], `+0x130`, `+0x134`, three vtable views, and rejected scroll/tile ABI shell.
- [x] Update `by-global/g_pChattingViewport.md`, `by-global/g_pHeightModifyPane.md`, `by-global/g_pNewSystemMessagePane.md`, and `by-global/g_pOldSystemMessagePane.md`: inserted the exact singleton pointer declarations.
- [x] Update `by-memory/0x0067adc4-0x0067adc8.g_pChattingViewport.md` and `by-memory/0x0069b4c8-0x0069b4cc.g_pOldSystemMessagePane.md`: inserted covered-by comments for their by-global declarations and refreshed stale storage-summary wording to current zero-filled storage.
- [x] Update `by-memory/0x0058af40-0x0058af48.HeaderFooterSystemMessageDefaultTrueVirtual.md`: inserted the exact folded virtual disposition comment and preserved the future Header/Footer class plan.
- [x] Update `by-memory/0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md`: inserted the covered-by/reserved-storage aggregate comment.
- [x] Update `by-memory/0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable.md`: inserted `static const wchar_t *s_systemMessagePaneResourcePointers[60] = { 0 };` and added proof for 0xf0 bytes/60 slots, initializer `sub_586480`, and table-base refs.
- [x] Update `by-memory/0x0069bd08-0x0069bdf8.OldSystemMessagePaneResourcePointerTable.md`: inserted `static const wchar_t *s_oldSystemMessagePaneResourcePointers[60] = { 0 };` and added proof for 0xf0 bytes/60 slots, initializer `sub_589D30`, and table-base refs.
- [x] Update `by-memory/0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables.md`: inserted aggregate comment that exact children emit both arrays.
- [x] Preserve existing owner/emitter/source-root route unless supervisor narrows scope. Proof: no owner/emitter/source-root changes were made; [UID:0000OE] remains `FILE`, and support docs retain their accepted owners/emitters.
- [x] Add change notes and proof text to each touched doc. Proof: every touched support doc has a 2026-06-30 B011 change note plus a B011 audit/disposition section where applicable.
- [x] Run scoped validators on every touched doc. Proof: validator table above lists all 19 changed by-* files, all exit 0 with `ok: 1`.
- [x] Run the final `by-file/SystemMessagePanes.md --wait-generated` freshness validator. Proof: command `000000002319`, timestamp `2026-06-30T04:54:53-04:00`, exit 0, `ok: 1`, `generated_refresh: completed`.
- [x] Confirm `auto-generated/NexusTK/social/SystemMessagePanes.cpp` no longer has blank accepted empty markers. Proof: generated header `validator-command-id: 000000002319` / `2026-06-30T04:54:53-04:00`; former empty markers now render as accepted class/storage/helper/table comments or declarations.
- [x] Record command ids, timestamps, exit codes, ok counts, generated-refresh state, and warnings. Proof: `## Implementation Callback Validator Proof` table above.
- [x] Release all leases immediately after the edit/validator batch and verify no Agent-B011 leases remain. Proof: B011 unlease command returned `Success` for all 19 paths; subsequent search of `tools/leaser/Agents/current_leases.md` found no `B011` entries.
- [x] Update this report ledger/checklist with applied/already-present/excluded states during implementation callback. Proof: this section and the ledger above were updated after validation.

## Implementation Callback Changed Files

Updated by B011:

- `by-file/SystemMessagePanes.md`
- `by-class/ColorStringSystemMessage.md`
- `by-class/FooterSystemMessage.md`
- `by-class/HeaderSystemMessage.md`
- `by-class/NewSystemMessageModifyHeightPane.md`
- `by-class/NewSystemMessagePane.md`
- `by-class/OldSystemMessagePane.md`
- `by-class/SystemMessagePane.md`
- `by-global/g_pChattingViewport.md`
- `by-memory/0x0067adc4-0x0067adc8.g_pChattingViewport.md`
- `by-global/g_pHeightModifyPane.md`
- `by-global/g_pNewSystemMessagePane.md`
- `by-global/g_pOldSystemMessagePane.md`
- `by-memory/0x0069b4c8-0x0069b4cc.g_pOldSystemMessagePane.md`
- `by-memory/0x0058af40-0x0058af48.HeaderFooterSystemMessageDefaultTrueVirtual.md`
- `by-memory/0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md`
- `by-memory/0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable.md`
- `by-memory/0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables.md`
- `by-memory/0x0069bd08-0x0069bdf8.OldSystemMessagePaneResourcePointerTable.md`
- `tools/leaser/Agents/Agent-B011/research/0000OE-SystemMessagePanes-empty-emitter-family-source-quality.md`

Validator-owned/generated side effects observed and not manually edited: `auto-generated/NexusTK/social/SystemMessagePanes.cpp` refreshed current for command `000000002319` via matching generated header `000000002319`; validator also reported generated metadata refreshes, generated report refreshes, projected stats updates, validator registry rebuild/update, and generated-file backups under `tools/validator_autogen_backup/`.

Not edited by B011: manual `-coverage-report.md` files, generated/project-level reports by hand, validator/tool state by hand, IDA DB, executed archives, supervisor ledgers, and lock files.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/0000OE-SystemMessagePanes-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/0000OE-SystemMessagePanes-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T05:01:25","uid":"0000OE"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000OE-SystemMessagePanes-empty-emitter-family-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/0000OE-SystemMessagePanes-empty-emitter-family-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000OE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
