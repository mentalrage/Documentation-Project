** TARGET-REPORT-UID:00026R **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# 00026R TransferServerReadOnlyData Source-Quality Report

## Finalized Report / Current Recommendation

- B004 completed the accepted implementation callback without running `execute_report`, moving/archiving this report, or manually editing generated, tracker, audit, supervisor, validator-state, lifecycle, or manual coverage files. Report validation/execution/counting/path/archive state remains external supervisor/validator-owned.
- UID00026R was preserved while its destination was corrected to `by-memory/0x0062e47c-0x0062e578.TransferServerReadOnlyData.md`. The old `[0x0062e480,0x0062e57c)` path is absent and the UID is unique.
- UID00026R is now a reviewed non-emitting split index at `92/94`, `CANONICAL_OWNER:0000F7`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank position, blank managed C++, and relative `Nested:-8`.
- Three exact non-emitting children were registered: UID0004MS `[0x0062e47c,0x0062e504)` vtable/RTTI data, UID0004MT `[0x0062e504,0x0062e574)` `TRANSSVR` literals, and UID0004MU `[0x0062e574,0x0062e578)` `0.03f`. Their blank blocks are exhaustive no-code dispositions.
- `NexusTK/ui/dialogs/TransferServerDialogPane.cpp` now emits one closed Pane-plus-Singleton class declaration, five exact source-authored methods, and one source global. RTTI/vtables, EH cleanup, adjustors, scalar wrapper, physical data, indexes, and storage remain compiler/generated non-emitters.
- UID0001KD is now a non-emitting `92/94` split index over registered source children UID0004MV/0004MW/0004MX/0004MY/0004MZ and compiler-support children UID0004N0/0004N1/0004N2.
- The source-facing override names are `bool OnTimer(int timerId, int arg0, int arg1)` and `void OnPaint()`. Historical `OnTimerEvent` and `OnPaintFrame` are descriptive aliases, not final declarations.
- The object is exactly `0x100` bytes. `Pane` occupies `0x000..0x0f7`; `+0x90` is inherited `GrafPort::m_alpha`; the only TransferServerDialogPane-owned fields are `int m_currentFrame` at `+0x0f8` and `int m_frameCount` at `+0x0fc`. The empty `Singleton<TransferServerDialogPane>` base overlaps at `+0x0f8` by EBO.
- The target remains blank by exhaustive no-code proof: its RTTI, three vtable views, four source literals, and float constant are all reproduced by the declaration and method bodies below. A raw table/array, covered-by comment, sample body, or duplicate literal declaration would be reverse-engineering scaffolding rather than plausible source.
- Report validation, execution, counting, path movement, and archive state are external supervisor/validator-owned facts. This artifact neither asserts nor directs those lifecycle states.

## Supporting Research

- At the final evidence snapshot on 2026-07-13, streamable MCP `idb_list` returned one adopted worker-backed NexusTK session, `supervisor_nexustk_20260713`, PID/worker PID `2236`. `server_health` returned `status=ok`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, string cache ready, and cache size `2067`.
- A real bounded `lookup_funcs(0x005992f0)` returned `sub_5992F0`, size `0xb6`. A real bounded `get_bytes(0x0062e47c,8)` returned `54 19 65 00 e0 93 59 00`, proving the primary complete-object-locator pointer followed by the primary scalar-deleting-destructor slot. Health and availability are evidence-time facts only, not indefinite current-state assertions.
- Full MCP work included function lookup/decompilation, disassembly, xrefs, bytes, names, RTTI, vtable slots, caller/callee review, and string/constant consumers over the target, executable owner, singleton slot, and immediate neighbors.
- Historical search terms were `UID00026R`, `UID:00026R`, `0x0062e480`, `0x0062e47c`, `0x0062e57c`, `TransferServerReadOnlyData`, `TransferServerDialogPane`, `TRANSSVR`, `UID0000F7`, `UID0000OW`, `UID0001KD`, `UID0000VJ`, `UID0000SL`, and `Singleton<TransferServerDialogPane>`.
- At research search time, active B-agent research roots returned no matching report. Only B004 assignment/control text named UID00026R; no then-active report duplicated this target.
- Executed report matches opened and classified:
  - `executed-b-agent-research/B003/00026P-ThreadReadOnlyData-source-quality.md`: direct predecessor-boundary precedent; it repaired UID00026Q to begin at `0x0062e334` and established the mixed `.rdata` index/exact-child pattern.
  - `executed-b-agent-research/B003/0002Q6-OpenTransferServerDialog-source-quality.md`: direct constructor/liveness support; proves the singleton guard, `0x100` allocation, `TransferServerDialogPane(true)`, and MainMenu ownership of the launcher rather than the dialog implementation.
  - `executed-b-agent-research/B005/0001KC-TotemFrame-source-quality.md`: direct executable predecessor proof; confirms TotemFrame ends at `0x00598ecf` and `0x00598ecf-0x00598ed0` is one `0xcc` byte before TransferServerDialogPane.
  - `executed-b-agent-research/B014/0001KE-UniAPIInit-source-quality.md`: direct successor proof; identifies the UniAPI static-object declaration, one-slot vtable, generated scalar destructor, and compiler/static-lifetime no-code disposition.
  - `executed-b-agent-research/B011/0002P0-UrlAlertPaneVtableData-source-quality.md`: direct successor proof; retains `[0x0062e580,0x0062e624)` for UrlAlertPane and confirms `0x0062e578-0x0062e580` belongs to UniAPIInit after the corrected boundary.
  - `executed-b-agent-research/B002/0001GF-waterfilter-update-caustic-source-quality.md`: direct inherited-layout corroboration; identifies GrafPort `+0x90` as `m_alpha`, matching TransferServerDialogPane fade accesses.
  - `executed-b-agent-research/B003/00036Y-MainMenuPaneCore-source-quality.md`: caller/dependency context; includes TransferServerDialogPane close/create behavior but does not own the class.
  - `executed-b-agent-research/B007/0000FE-UniAPIInit-class-source-quality.md`, `B011/0001KF-UrlAlertPane-source-quality.md`, `B011/0000HE-AlertPanes-empty-emitter-family-source-quality.md`, and `B015/0000WD-WideApiDispatchInit-source-quality.md`: successor-family context only; all preserve source declarations with compiler-emitted vtable/static support.
  - `executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch9.md`: caller context only; confirms MapPane transfer paths construct the pane but do not own its implementation.
- `project-documentation/archived/**`, `tools/leaser/Agents/Older-Research/**`, and `tools/leaser/Agents/SpecialReports/**` were searched with the same terms and returned no match. There is no prior exact UID00026R report to incorporate or supersede.
- Every affected manual coverage file was inspected read-only: `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, `by-global/-coverage-report.md`, `by-item/-coverage-report.md`, `by-resource/-coverage-report.md`, `by-type/-coverage-report.md`, `by-type/by-struct/-coverage-report.md`, and `by-type/by-vtable/-coverage-report.md`. Exact supervisor-owned row operations are supplied below; validator-generated coverage is not treated as a substitute.

## Target

- UID: `00026R`.
- Historical B004 research/implementation-callback artifact path before any external supervisor lifecycle: `tools/leaser/Agents/Agent-B004/research/00026R-TransferServerReadOnlyData-source-quality.md`. External validator history/current path is authoritative after any lifecycle event.
- Implemented UID-preserving destination: `by-memory/0x0062e47c-0x0062e578.TransferServerReadOnlyData.md`; the old path is absent.
- Historical pre-report tracker snapshot from the assignment: `86/90`, report count `0`. That snapshot is not frozen as current implementation truth.
- Binary target after correction: `.rdata` `[0x0062e47c,0x0062e578)`, `0xfc` / 252 bytes, SHA256 `3B841A8ACE1202121273BAEA729A1F0BFB80B6F8734823E21D7E407D954EB6F0`.
- Generated lead at research evidence time, inspected read-only: `auto-generated/NexusTK/ui/dialogs/TransferServerDialogPane.cpp`, validator command `000000010132`, SHA256 `1B9EE117E5D79C5422DA81126BA01AB7C50621FF64295FF110CC5FA6802DBD85`. It contained Empty Emitter Markers for UID0000F7, UID0000SL, UID0002XO, UID0000VJ, UID0001KD, and UID00026R.

## Current Target State

- Implemented metadata is `92/94`, owner `0000F7`, false/non-emitting, blank emitter/position/managed C++, and `Nested:-8`.
- Exact current range is `[0x0062e47c,0x0062e578)`, including the Transfer primary COL and excluding the UniAPIInit COL. The target has no padding and all bytes route through UIDs 0004MS/0004MT/0004MU.
- UID0001KD is `92/94` false/non-emitting with eight registered exact children. UID0000F7 and UID0000OW are `92/94`; UID0000VJ is `91/94` false; UID0000SL emits the exact `90/93` source global; UID0002XO is `90/94` false; UID00029W retains `90/93` with all-zero current wording.
- UID00026Q/UID0003E4 end at `0x0062e47c`; UID00026S/UID0003E5 start at `0x0062e578`; successor and executable nesting deltas are implemented exactly.
- Historical `86/90`, old paths, stale ownership/emitter state, missing children, blank-source blockers, and `0xffffffff` summaries are preserved only as explicitly historical evidence elsewhere in this report.

## Executive Recommendation

Adopt a split-first source model. UID00026R becomes a non-emitting physical index, while exact `.rdata` children document generated vtable/RTTI data, source literals, and the fade constant without duplicating source output. The executable aggregate likewise becomes a non-emitting split index. Five source children emit a mid-2000s class implementation, three compiler-only children remain blank, the class page emits the declaration, and the global page emits `TransferServerDialogPane *g_pTransferServerDialog = 0;`.

This closes every named blocker: exact range, inherited slots, direct bases, destructor representation, two real fields, timer/paint signatures, resource placement, singleton declaration, compiler glue, source path, source order, child inventory, score movement, and manual coverage synchronization text.

## Supervisor Active Recheck

- Every destination was re-read before bounded edit. Thirteen new pages were registered serially before cross-references: UIDs 0004MS through 0004N4 in the exact inventory below.
- The implemented matrix contains 46 applied atomic claims, 20 exact formal destinations, 13 registered new pages, corrected neighbor paths/nesting, real-UID manual coverage text, scoped validator proof, and checked callback verification.
- B004 performed implementation and validator work only. B004 performed no report execute/move/archive/lifecycle action and does not assert current external validation/execution/archive/count state.
- Manual coverage application remains external supervisor-owned. B004 inspected and supplied exact real-UID row text but did not manually edit any `-coverage-report.md` file; two rename validators made validator-managed reverse-link side effects that are recorded below.

## Inference Research Guidance Check

| Required route | Work performed | Resolution |
| --- | --- | --- |
| Exact bytes/range | Read boundary dwords, complete target bytes, neighboring RTTI/string/constant data, and hashes. | Corrected to `[0x0062e47c,0x0062e578)` with no internal padding. |
| Vtables/RTTI | Decoded three COLs, table bases, every slot, constructor/destructor stores, RTTI hierarchy. | One class with primary, EventHandler-facet, and TimerHandler-facet views; compiler emitted. |
| Source methods | Decompiled/disassembled every function in UID0001KD and classified all gaps. | Five source bodies, three compiler-support children, exact padding. |
| Layout/types | Traced every derived-tail and alpha access; compared Pane/GrafPort/Singleton support. | Only `m_currentFrame` and `m_frameCount`; inherited `m_alpha`; EBO at `+0xf8`; size `0x100`. |
| Liveness | Checked vtable routes, ordinary calls, constructor callers, global xrefs, EH route. | No child deferred for "no caller"; each route/disposition is resolved. |
| Names/signatures | Compared callback vtable contracts and related source-ready pages. | `OnTimer(int,int,int)` returning bool and `OnPaint()` returning void. |
| Resources/constants | Decoded four UTF-16 strings and `0.03f`; traced all consumers. | Literals remain in owning method bodies, not raw data arrays. |
| Source placement | Ranked class/file/caller/dependency owners and searched prior reports. | `NexusTK/ui/dialogs/TransferServerDialogPane.cpp`. |
| Generated disposition | Inspected generated output and source declaration requirements. | Parent/data/compiler helpers non-emitting; class/method/global children emit. |
| Manual coverage | Read every affected manual coverage row/root. | Exact replacement/addition text supplied; no "not applicable" shortcut used. |

## Heuristic / Inference Reanalysis And Validation

| Question | Direct facts | Inference tested | Decision |
| --- | --- | --- | --- |
| Is `0x0062e47c` predecessor padding? | Dword is `0x00651954`, one of three Transfer COLs sharing type descriptor/CHD; next dword is table slot `0x005993e0`. | Could remain with Totem string child. | Rejected. It is Transfer primary RTTI and moves into UID00026R/vtable child. |
| Is `0x0062e578` Transfer tail data? | Dword is `0x00651a2c`, UniAPIInit COL; `0x0062e57c` is UniAPI one-slot vtable `0x00599a10`. | Could be second Transfer float/tail dword. | Rejected. UID00026S/UID0003E5 start at `0x0062e578`. |
| Are EventHandler/TimerHandler direct source bases? | RTTI shows facets at `+0xa0/+0xa4`; Pane layout already contains those facets; constructor invokes only Pane plus empty Singleton semantics. | Declare three direct bases from three views. | Rejected. Source direct bases are Pane and Singleton only. |
| Is `+0x90` a Transfer field? | GrafPort constructor and unrelated derived panes use `+0x90` as alpha; Transfer reads/writes same inherited slot. | Declare `float m_alpha` in Transfer. | Rejected as duplicate base storage. |
| Are `+0xf8/+0xfc` source fields? | Constructor writes 0/34, timer reads/updates, paint indexes by current frame. | Compiler cookie or singleton storage. | Rejected. They are `m_currentFrame` and `m_frameCount`; Singleton EBO overlaps without storage. |
| Is `0x00599220` a helper rather than destructor? | Full vptr restoration, singleton clear, Pane teardown; scalar wrapper duplicates it with delete flag. | Retained cleanup helper body. | Rejected. Highest-probability source is ordinary virtual destructor with only the singleton clear handwritten. |
| Is `0x005993b0` source helper? | Sole xref from constructor EH/unwind data; body only clears singleton. | File-local `ClearTransferServerSingleton`. | Rejected. It is compiler-emitted constructor-unwind cleanup for the published Singleton state. |
| Are adjustor thunks source bodies? | Exact `this -= 0xa0/0xa4`, tail-forward to scalar wrapper, only vtable refs. | Explicit methods. | Rejected as compiler glue. |
| Should paint return int? | EAX has incidental callback result; vtable/Pane paint contract and callers consume no return. | `int OnPaintFrame()`. | Rejected. `void OnPaint()`. |
| Should timer have a specialized name? | Tertiary TimerHandler slot and three-argument `ret 0x0c`; all paths return 1. | `OnTimerEvent`/`OnTimerTick`. | Rejected as historical aliases. Use inherited `OnTimer`. |
| Should frame bounds be zero-initialized? | Binary does not seed the union accumulator before first `UnionWith`. | Add `{}` for safety. | Rejected because it changes observed behavior/source lowering. Formal body preserves an unseeded local. |
| Should zero frame count be guarded? | Binary computes modulo `m_frameCount` directly; constructor stores 34. | Add defensive `if (m_frameCount)`. | Rejected because no binary branch exists. |
| Should alpha be clamped with `min`/unconditional assignment? | Binary computes `fmaxf(0, alpha-0.03f)`, then assigns only if result `<=1.0f`. | Simplify to max/min. | Rejected because conditional assignment preserves NaN and above-one behavior. |
| Should EPFTileContext be released? | Paint initializes a borrowed frame view and performs no release call. | Add RAII/release. | Rejected; no binary behavior supports it. |
| Should strings/constants get standalone globals? | All literals/constants have bounded method consumers and no source symbol evidence. | Emit named arrays/constants. | Rejected. Keep literals inline in the five method bodies. |

## Evidence Standards Used

- Direct evidence: live IDA MCP function boundaries, decompilation, disassembly, RTTI, table dwords, names, xrefs, bytes, strings, constants, callers/callees, and global data.
- Independent local evidence: exact PE/IDB byte hashes, destination documents as read at research time, generated output as read at research time, and manual coverage rows.
- Corroborating evidence: executed prior reports were used only where they independently establish adjacent boundaries, caller ownership, inherited layout, or successor generated-data disposition.
- Inference is labeled when original symbols/source are absent. Inferred human names are accepted only where ABI, class contract, behavior, callers, and neighboring project conventions converge.
- Negative evidence is not used alone to erase source. No-route source-shaped bodies were checked for EH, vtable, inline-copy, and compiler-support explanations.
- No generated output, old report, or stale current doc was treated as scoring authority when it contradicted live bytes.

## Evidence Checked

- Target and direct supports read in full: UID00026R, UID0001KD, UID0000F7, UID0000OW, UID0000VJ, UID0000SL, UID0002XO, and UID00029W.
- Boundary supports: UID00026Q, UID0003E4, UID00026S, UID0003E5, UID0002P0, UID00026T, UID0001KC, and UID000249.
- API/type supports: Pane, GrafPort, TimerPane, TimerHandler, EventHandler, Singleton, RectBounds, EPFTileContext, ResourceLayoutTable/ImageLib, PaletteLib, Surface render callback table, MainUiLayerSlots, screen/map pane globals, SoundManager, and `g_useEpfAssets`.
- Live target bytes: `[0x0062e47c,0x0062e578)`, SHA256 `3B841A8ACE1202121273BAEA729A1F0BFB80B6F8734823E21D7E407D954EB6F0`.
- Live executable bytes: `[0x00598ed0,0x0059943f)`, 1391 bytes, SHA256 `A58398FE2188027117E5FAA986BAEB68743C43D68653B32C6D3F046D1ED3433D`.
- Generated file read-only check at research evidence time: validator command `000000010132`, timestamp `2026-07-13T14:47:58-04:00`, source UID0000OW, six relevant Empty Emitter Markers, no source definitions.
- Prior-report roots and exact matched paths are enumerated under Supporting Research. Active, archived, Older-Research, and SpecialReports roots had no direct report; all 12 executed matches were opened and classified.
- Manual coverage inspected read-only:
  - `by-memory/-coverage-report.md` current rows 2875 (UID0001KD), 3302-3306 (UID00026Q/R/S, UID0002P0, UID00026T), 3547/3551 (UID00029W/UID0002XO); exact children are absent.
  - `by-class/-coverage-report.md` line 565 UID0000F7 is stale.
  - `by-file/-coverage-report.md` line 290 UID0000OW is stale.
  - `by-global/-coverage-report.md` line 151 UID0000SL is stale.
  - `by-item/-coverage-report.md` line 77 UID0000VJ is stale.
  - `by-resource/-coverage-report.md` line 39 UID0001RR retains the old UID0003E4 end `0x0062e480`.
  - `by-type/-coverage-report.md`, `by-type/by-struct/-coverage-report.md`, and `by-type/by-vtable/-coverage-report.md` have no TransferServer layout/vtable rows; root and subfolder additions are required.

## Claim And Incorporation Ledger

| ID | Atomic claim | Confidence | Evidence | Destination | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID00026R starts at `0x0062e47c`, including the primary COL pointer. | Very high | Dwords, RTTI, shared type descriptor/CHD, bounded bytes. | UID00026R, UID00026Q, UID0003E4 | incorporate | applied |
| C02 | UID00026R ends at `0x0062e578`; the dword there is UniAPIInit COL. | Very high | Boundary bytes, UniAPI RTTI/vtable support. | UID00026R, UID00026S, UID0003E5 | incorporate | applied |
| C03 | Corrected target is 252 bytes with SHA256 `3B841...6F0`. | Very high | Exact byte read/hash. | UID00026R | incorporate | applied |
| C04 | Corrected target contains Transfer RTTI/vtables, four UTF-16 names, and one `0.03f` constant only. | Very high | Complete byte/name inventory. | UID00026R and three children | incorporate | applied |
| C05 | There is no padding inside `[0x0062e47c,0x0062e578)`. | Very high | Complete dword/string decode. | UID00026R | incorporate | applied |
| C06 | UID00026R is a non-emitting split index, not a source emitter. | Very high | Generated-data/source-declaration disposition. | UID00026R | incorporate | applied |
| C07 | UID00026R metadata becomes `92/94`, owner `0000F7`, false, blank emitter/position/C++. | High | Closed inventory and exact source routes. | UID00026R | incorporate | applied |
| C08 | UID00026R relative nesting is `-8`. | Very high | Address-sorted cumulative nesting audit. | UID00026R | incorporate | applied |
| C09 | Create three exact target children serially; first `Nested:+8`, rest `0`, all non-emitting. | Very high | Natural owner/content boundaries. | New by-memory pages | incorporate | applied |
| C10 | Rename UID00026Q/UID0003E4 end to `0x0062e47c`; remove stale "alignment" ownership. | Very high | Primary Transfer COL at boundary. | UID00026Q, UID0003E4, UID0001RR | incorporate | applied |
| C11 | Rename UID00026S/UID0003E5 start to `0x0062e578`. | Very high | UniAPI COL at 578 and vtable at 57c. | UID00026S, UID0003E5 | incorporate | applied |
| C12 | Successor nesting is UID00026S `-8`, UID0003E5 `+8`, UID0002P0 `0`, UID00026T `-8`. | Very high | Validator README relative-delta semantics and address order. | Four successor pages | incorporate | applied |
| C13 | UID0001KD bytes/hash and all function/padding boundaries are exact. | Very high | MCP/byte hashes. | UID0001KD | incorporate | applied |
| C14 | UID0001KD becomes `92/94`, owner `0000F7`, false/non-emitting, blank formal block, Nested 0. | High | Complete exact-child source/compiler split. | UID0001KD | incorporate | applied |
| C15 | Create eight executable children in ascending address order; first `Nested:+4`, rest `0`; UID000249 closes with `-4`. | Very high | Function/gap/address/nesting audit. | New children, UID000249 | incorporate | applied |
| C16 | All internal executable gaps are exact parent-only `0xcc` padding. | Very high | Byte scan. | UID0001KD | incorporate | applied |
| C17 | Constructor source signature is `explicit TransferServerDialogPane(bool autoClose)` with exact body below. | High | Nine calls, bool pushes, Pane(3), fields/resources/timers/sound. | New constructor child, class/file | incorporate | applied |
| C18 | Constructor preserves the unseeded `RectBounds frameBounds` accumulator. | Very high behavior / medium source intent | No binary initialization before `UnionWith`. | Constructor child | incorporate | applied |
| C19 | Constructor preserves active-map origin call, 144 centering, EPF `-100/-100`, screen fallback, clamp, layer/order, timers, and sound. | Very high | Decompiled/disassembled call/data flow. | Constructor child | incorporate | applied |
| C20 | `0x00599220` is ordinary destructor source; handwritten body only clears global. | High | Vptr/base teardown lowering and scalar parity. | Destructor child, class | incorporate | applied |
| C21 | `0x00599250` is `void ResetOpacityAndRepaint()` and sets inherited alpha to 0 then invalidates. | Very high | Two direct calls and exact body. | Reset child, class | incorporate | applied |
| C22 | `0x00599270` is `bool OnTimer(int,int,int)` with exact alpha/frame/reschedule/delete behavior. | Very high | Timer vtable slot, ABI, decompile. | Timer child, class | incorporate | applied |
| C23 | `0x005992f0` is `void OnPaint()` with exact resource/palette/blit behavior and no release. | Very high | Primary slot +0x44, ABI, decompile. | Paint child, class | incorporate | applied |
| C24 | `OnTimerEvent` and `OnPaintFrame` remain historical aliases only. | High | Inherited callback contracts. | All Transfer supports | reject-stale | applied |
| C25 | `0x005993b0` is compiler EH/unwind singleton cleanup and emits no source body. | Very high | Sole EH xref `0x00609c11`. | New unwind child, item/aggregate | incorporate | applied |
| C26 | `[0x005993bb,0x005993d1)` is two compiler adjustors `-0xa0/-0xa4`; one blank child records both. | Very high | Exact bytes/vtable refs/tail target. | New adjustor child, item/aggregate | incorporate | applied |
| C27 | `0x005993e0` is compiler scalar deleting destructor; blank child. | Very high | Delete flag, vtable route, ordinary destructor parity. | New scalar child, item/aggregate | incorporate | applied |
| C28 | Direct bases are Pane and empty Singleton; object size/fields are exact. | High | RTTI, constructor, offset family, EBO. | Class and layout pages | incorporate | applied |
| C29 | Class declaration closes before `[[CHILDREN]]` and includes extern global. | Very high | Validator generation convention and source ordering. | UID0000F7 | incorporate | applied |
| C30 | Create a non-emitting TransferServerDialogPaneLayout support page. | High | Exact offsets/object size/base facets. | New by-struct page | incorporate | applied |
| C31 | Create a non-emitting TransferServerDialogPaneVtables support page. | Very high | Complete three-view slot/RTTI inventory. | New by-vtable page | incorporate | applied |
| C32 | UID0000OW remains `NexusTK/ui/dialogs/TransferServerDialogPane.cpp` and becomes `92/94`. | High | Ownership/caller/resource ranking. | UID0000OW | incorporate | applied |
| C33 | UID0000VJ becomes `91/94`, owner `0000F7`, false/non-emitting compatibility index. | High | Exact child replacement of broad thunk island. | UID0000VJ | incorporate | applied |
| C34 | UID0000SL emits `TransferServerDialogPane *g_pTransferServerDialog = 0;` at `90/93`. | Very high | Initial bytes, lifecycle xrefs, source module. | UID0000SL | incorporate | applied |
| C35 | UID0002XO becomes `90/94`, owner `0000SL`, false/non-emitting; zero-byte summary corrected. | Very high | Exact storage bytes and source-global route. | UID0002XO | incorporate | applied |
| C36 | UID00029W keeps `90/93` false but its Item Summary must say all four slots are zero. | Very high | Its own slot table and live bytes. | UID00029W | incorporate | applied |
| C37 | Three RTTI views share one seven-base hierarchy; Singleton EBO overlaps derived tail. | Very high | COL/CHD/base descriptors. | Vtable/layout/class/target | incorporate | applied |
| C38 | Constructor has nine direct call sites in five caller functions; callers are consumers, not owners. | Very high | Xref inventory. | Constructor/file/class | incorporate | applied |
| C39 | Global has exactly 20 refs across publish/clear/guard/consumer paths. | Very high | Xref inventory. | Global/storage/file/class | incorporate | applied |
| C40 | Resource xrefs are EPF 3, EPD 3, PAL 1, PAD 1; float has one timer ref. | Very high | Xref inventory. | Target/string/constant/method pages | incorporate | applied |
| C41 | Source placement is dialog UI file, not MainMenu/Map/Surface/ResourceLayout/Totem/PlatformApi. | High | Ownership ranking. | File/class/all children | incorporate | applied |
| C42 | Reject raw table/array, duplicate strings/constants, explicit vptr/facet/cookie fields, extra direct bases, and defensive semantic changes. | Very high | Source-era plausibility and binary parity. | Target/support prose | reject-stale | applied |
| C43 | Preserve executed-report findings only as classified historical/support evidence. | High | Exact report-root search. | Target/support history | incorporate | applied |
| C44 | Expected generated result is one class/global and five method definitions, no parent/compiler/storage/item empty markers or duplicate ABI bodies. | High | Managed source routing. | Generated verification plan | incorporate | applied |
| C45 | Manual coverage rows are stale/absent and require the exact supervisor-owned operations below. | Very high | Read-only manual coverage audit. | Nine manual coverage files | incorporate | applied |
| C46 | All in-scope score, empty-emitter, source-shape, range, ownership, helper, and layout blockers are resolved; residual uncertainty caps confidence only. | High | Full matrix above. | Entire destination set | incorporate | applied |

## Callback Claim-by-Claim Proof

| Claim | Applied destination proof | Independent verification |
| --- | --- | --- |
| C01 | UID00026R moved once to `[0x0062e47c,0x0062e578)`; UID00026Q and UID0003E4 end at `0x0062e47c`. | Commands `000000010267`, `10269`, and `10270`; old paths absent, each UID unique. |
| C02 | UID00026R ends before UniAPI COL; UID00026S/UID0003E5 begin at `0x0062e578`. | `10267`, `10272`, `10273`; current pages identify dword `0x00651a2c` and table at `0x0062e57c`. |
| C03 | Target records 252 bytes and SHA256 `3B841A8ACE1202121273BAEA729A1F0BFB80B6F8734823E21D7E407D954EB6F0`. | Scoped target validator `10267`, exit 0/ok 1. |
| C04 | UID00026R inventories only UID0004MS vtables/RTTI, UID0004MT four strings, and UID0004MU float. | Child registration validators `10219`, `10220`, `10222`; parent `10267`. |
| C05 | Parent and children state no internal padding; exact transitions are `504`, `574`, `578`. | Complete child ranges plus target hash validated by `10219`/`10220`/`10222`/`10267`. |
| C06 | UID00026R is false/non-emitting with blank formal block. | `10267` changed autogen true to false and cleared emitter UID. |
| C07 | UID00026R is `92/94`, owner `0000F7`, false, blank emitter/position/C++. | `10267` completion/confidence/owner/autogen updates and ok 1. |
| C08 | UID00026R applies `Nested:-8`. | Final target header readback after `10267`. |
| C09 | Three read-only children registered serially as UID0004MS/0004MT/0004MU with `+8/0/0`, accepted scores, false and blank blocks. | `10219` at 15:48:46, `10220` at 15:49:30, `10222` at 15:49:59; each exit 0 and parent lease released. |
| C10 | UID00026Q/UID0003E4 paths end `47c`; false alignment removed; UID0001RR link/boundary updated. | `10269`, `10270`, `10287`; reverse-only refreshes `10288-10294` removed all stale ordinary links. |
| C11 | UID00026S/UID0003E5 paths start `578` and retain UniAPI/UrlAlert source ownership. | `10272`, `10273`; reverse-only refreshes `10295-10299` removed stale ordinary links. |
| C12 | Successor nesting is UID00026S `-8`, UID0003E5 `+8`, UID0002P0 `0`, UID00026T `-8`. | Headers validated by `10272`, `10273`, `10274`, and `10275`. |
| C13 | UID0001KD retains exact aggregate hash, eight function ranges/hashes, five gaps, and one-byte outside pads. | Parent split-index validator `10279`, exit 0/ok 1. |
| C14 | UID0001KD is `92/94`, owner `0000F7`, false/non-emitting, blank block, Nested 0. | `10279` updated completion/confidence/owner/autogen/emitter and added eight child references. |
| C15 | Eight executable children registered in ascending order as 0004MV/MW/MX/MY/MZ/N0/N1/N2; first Nested `+4`, others `0`; UID000249 is `-4`. | `10223`, `10225`, `10226`, `10228`, `10229`, `10230`, `10235`, `10245`, then UID000249 `10280`. |
| C16 | UID0001KD preserves exact `7/14/7/10/15` parent-only `cc` gaps. | Accepted Exact Split and Address Range validated by `10279`. |
| C17 | Constructor signature/body is exact in UID0004MV and declared `explicit` in UID0000F7. | Constructor `10223`, class `10281`, generated one-definition count under `10300`. |
| C18 | Constructor retains uninitialized `RectBounds frameBounds`. | UID0004MV body/readback under `10223`; generated body after `10300` retains the declaration without `{}`. |
| C19 | Constructor retains origin call, 144 centering, EPF -100 offsets, screen fallback, clamp, layer/order, timers, and sound. | UID0004MV full body `10223`; generated one constructor after `10300`. |
| C20 | UID0004MW is the ordinary destructor with only singleton clear in human source; class declares virtual destructor. | `10225`, class `10281`, generated destructor count 1. |
| C21 | UID0004MX emits exact `ResetOpacityAndRepaint`. | `10226`, class `10281`, generated count 1 after `10300`. |
| C22 | UID0004MY emits exact `bool OnTimer(int,int,int)` including fmaxf/conditional/modulo/reschedule/delete/true. | `10228`, class `10281`, generated count 1 after `10300`. |
| C23 | UID0004MZ emits exact void `OnPaint`, resource/palette branches, destination normalization and sprite callback with no release. | `10229`, class `10281`, generated count 1 and no release addition after `10300`. |
| C24 | Source-facing current docs use `OnTimer`/`OnPaint`; old names are historical aliases only. | Class/file `10281`/`10282`; generated old-name count 0. |
| C25 | UID0004N0 records sole-EH-route constructor-unwind singleton clear and remains false/blank. | `10230`; generated compiler UID/body count 0. |
| C26 | UID0004N1 records both `-0xa0/-0xa4` adjustors and both hashes, false/blank. | `10235`; generated adjustor name/body count 0. |
| C27 | UID0004N2 records scalar deleting wrapper and conditional deallocation, false/blank. | `10245`; generated scalar-wrapper name/body count 0. |
| C28 | UID0000F7 and UID0004N3 encode Pane plus empty Singleton, inherited alpha, facets, EBO, two fields, and size `0x100`. | Class `10281`, layout registration `10257`; generated class declaration count 1. |
| C29 | UID0000F7 closes the class before `[[CHILDREN]]` and declares extern global. | Class validator `10281`; generated methods occur at namespace scope after line 29. |
| C30 | Non-emitting layout support registered as UID0004N3 at `91/94`, owner 0000F7, blank. | Registration `10257`, exit 0. |
| C31 | Non-emitting vtable support registered as UID0004N4 at `92/95`, owner 0000F7, complete three-view inventory, blank. | Registration `10265`, exit 0. |
| C32 | UID0000OW retains `NexusTK/ui/dialogs/` and is `92/94` with source order, dependencies, callers and exclusions. | File validator `10282`, exit 0/ok 1. |
| C33 | UID0000VJ is `91/94`, owner 0000F7, false/non-emitting compatibility index with exact child routes. | Item validator `10283` changed owner/autogen/emitter and removed reconstructable stats row. |
| C34 | UID0000SL is `90/93`, owner/emitter 0000OW, and emits exact zero-initialized pointer definition. | Global `10284`; generated global count 1. |
| C35 | UID0002XO is `90/94`, owner 0000SL, false/non-emitting, blank, exact all-zero storage with 20 refs. | Storage `10285` changed true to false and cleared emitter. |
| C36 | UID00029W remains `90/93` false and its current Item Summary says all four slots are `0x00000000`; historical `0xffffffff` notes remain labeled stale. | Aggregate validator `10286`, exit 0/ok 1. |
| C37 | UID0004MS/UID0004N4/UID0004N3/UID0000F7 consistently record three views, seven-base hierarchy, and Singleton EBO. | `10219`, `10265`, `10257`, `10281`. |
| C38 | UID0004MV, UID0001KD, UID0000F7, and UID0000OW preserve nine constructor calls in five consumers and reject caller ownership. | `10223`, `10279`, `10281`, `10282`. |
| C39 | UID0000SL/UID0002XO/class/file preserve exactly 20 publish/clear/guard/consumer refs. | `10284`, `10285`, `10281`, `10282`. |
| C40 | Parent/string/float/method pages preserve EPF 3, EPD 3, PAL 1, PAD 1, and one timer-float route. | `10267`, `10220`, `10222`, `10223`, `10228`, `10229`. |
| C41 | File route is dialog UI; MainMenu/Map/Surface/resource/Totem/PlatformApi remain callers, dependencies, or neighbors. | UID0000OW `10282`, class `10281`, target/boundary validators. |
| C42 | All raw table/array/vptr/facet/cookie/duplicate literal/defensive-change alternatives remain rejected in destination prose and absent from output. | Destination readback plus generated raw-vptr/old-name/compiler-body counts all 0 after `10300`. |
| C43 | Executed-report, negative, rejected, hash, padding, liveness and historical assumptions remain in the report and destination evidence; no IDA state was edited. | Changed-file diff/readback and all scoped validators; MCP was not needed during callback because no new binary uncertainty arose. |
| C44 | Generated output has one class, global, constructor, destructor, reset, timer, and paint definition; no parent/compiler/old-name/raw-vptr/target-empty artifacts. | Waited command `000000010300`; generated SHA256 `2651F40328C8DD24B4E58A0D242F74838C39CC539890044A3C56FF5F17D72ACF`. |
| C45 | Every manual coverage root was left manually untouched; exact row operations below now use all real UIDs 0004MS-MU/MV-N4. | Placeholder audit count 0. Validator-managed reverse-link side effects from rename commands are distinguished below; row content remains supervisor-owned. |
| C46 | Scores, paths, nesting, ownership, source shape, helpers, layout, output, stale links and leases all pass the callback matrix. | 29 accepted-page scoped validators, 12 validator-managed reverse-link refreshes, final `10300`, stale-path count 0, UID counts 1, and no B004 lease. |

## Positive Evidence Summary

- The corrected island is byte-complete and single semantic owner: all three COLs share TransferServerDialogPane RTTI, all four strings are consumed only by its constructor/paint path, and `0.03f` is consumed only by its timer override.
- The executable cluster is complete: every modeled function and every byte gap has a disposition, with exact hashes and no unexplained body.
- RTTI, constructor allocation, inherited Pane layout, vtable facets, and field accesses converge on `sizeof(TransferServerDialogPane)==0x100` with two derived integers.
- Five methods have stable source contracts and complete binary behavior. Destructor/compiler support can be separated without inventing source helpers.
- Nine constructor calls and 20 global refs prove broad runtime liveness while preserving implementation ownership in the dialog file.
- Existing project APIs provide source-ready names for Pane, TimerHandler contract, RectBounds, EPFTileContext, ResourceLayoutTable, PaletteLib, SoundManager, and Surface sprite blit callback.
- The target score can improve from historical `86/90` to `92/94` without emitting raw `.rdata`: completeness comes from exact inventory and reproduction routes, not handwritten binary arrays.

## IDA MCP Facts

- Database used for all final live evidence: `supervisor_nexustk_20260713`.
- Evidence-time health: `status=ok`, module `NexusTK.exe`, image base `0x400000`, analysis/Hex-Rays/strings ready, 2067 cached strings.
- Corrected target dwords:
  - `0x0062e47c = 0x00651954` primary COL; `0x0062e480 = 0x005993e0` primary table first slot.
  - `0x0062e4c8 = 0x00651a04` secondary COL; `0x0062e4cc = 0x005993bb` secondary table first slot.
  - `0x0062e4f8 = 0x00651a18` tertiary COL; `0x0062e4fc = 0x005993c6`, `0x0062e500 = 0x00599270`.
  - `0x0062e504..0x0062e573`: four NUL-terminated UTF-16 `TRANSSVR` names.
  - `0x0062e574 = 0x3cf5c28f` (`0.03f`).
  - `0x0062e578 = 0x00651a2c` UniAPIInit COL; `0x0062e57c = 0x00599a10` UniAPIInit vtable.
- Primary vtable base `0x0062e480` has these 18 literal slots:

| Table cell / offset | Target | Source disposition |
| --- | --- | --- |
| `0x0062e480 / +0x00` | `0x005993e0` | TransferServerDialogPane scalar deleting destructor, compiler emitted. |
| `0x0062e484 / +0x04` | `0x004f4b10` | Inherited LObject runtime-class accessor. |
| `0x0062e488 / +0x08` | `0x0041b6c0` | Inherited default/null virtual. |
| `0x0062e48c / +0x0c` | `0x004b8e20` | Inherited `Pane::UpdateRenderRegion`. |
| `0x0062e490 / +0x10` | `0x0041d680` | Inherited default/null virtual. |
| `0x0062e494 / +0x14` | `0x00544730` | Inherited `Pane::Show`. |
| `0x0062e498 / +0x18` | `0x00544750` | Inherited `Pane::Hide`. |
| `0x0062e49c / +0x1c` | `0x005447a0` | Inherited `Pane::Repaint`. |
| `0x0062e4a0 / +0x20` | `0x00544800` | Inherited `Pane::InvalidateRect`. |
| `0x0062e4a4 / +0x24` | `0x00544a20` | Inherited `Pane::GetDescription`. |
| `0x0062e4a8 / +0x28` | `0x00544b80` | Inherited `Pane::GetScreenBounds`. |
| `0x0062e4ac / +0x2c` | `0x00544bd0` | Inherited `Pane::SetBounds`. |
| `0x0062e4b0 / +0x30` | `0x00544c70` | Inherited `Pane::AddToLayer`. |
| `0x0062e4b4 / +0x34` | `0x00544cb0` | Inherited `Pane::InsertInLayer`. |
| `0x0062e4b8 / +0x38` | `0x00544ce0` | Inherited `Pane::RemoveFromLayer`. |
| `0x0062e4bc / +0x3c` | `0x00544d30` | Inherited `Pane::SetPaneOrder`/order dispatcher. |
| `0x0062e4c0 / +0x40` | `0x00544d70` | Inherited `Pane::UnregisterEventHandler`. |
| `0x0062e4c4 / +0x44` | `0x005992f0` | Source-authored `TransferServerDialogPane::OnPaint`. |

- Secondary table base `0x0062e4cc`, for the inherited EventHandler facet at object `+0xa0`, has these 11 literal slots. The exact inherited source names beyond the destructor are owned by EventHandler/Pane support; none is a Transfer-local override:

| Table cell / offset | Target | Source disposition |
| --- | --- | --- |
| `0x0062e4cc / +0x00` | `0x005993bb` | Compiler destructor adjustor, `this -= 0xa0`. |
| `0x0062e4d0 / +0x04` | `0x00544db0` | Inherited EventHandler/Pane virtual. |
| `0x0062e4d4 / +0x08` | `0x00544dc0` | Inherited EventHandler/Pane virtual. |
| `0x0062e4d8 / +0x0c` | `0x00544dd0` | Inherited EventHandler/Pane virtual. |
| `0x0062e4dc / +0x10` | `0x00544de0` | Inherited EventHandler/Pane virtual. |
| `0x0062e4e0 / +0x14` | `0x00544df0` | Inherited EventHandler/Pane virtual. |
| `0x0062e4e4 / +0x18` | `0x00544e00` | Inherited EventHandler/Pane virtual. |
| `0x0062e4e8 / +0x1c` | `0x004a89f0` | Inherited EventHandler/Pane virtual. |
| `0x0062e4ec / +0x20` | `0x00544e10` | Inherited EventHandler/Pane virtual. |
| `0x0062e4f0 / +0x24` | `0x00544e30` | Inherited EventHandler/Pane virtual. |
| `0x0062e4f4 / +0x28` | `0x00544e70` | Inherited EventHandler/Pane virtual. |

- Tertiary table base `0x0062e4fc`, for the inherited TimerHandler facet at object `+0xa4`, has exactly two slots: `0x0062e4fc/+0x00 -> 0x005993c6`, compiler destructor adjustor `this -= 0xa4`; and `0x0062e500/+0x04 -> 0x00599270`, source-authored `TransferServerDialogPane::OnTimer`.
- RTTI base array has seven entries: TransferServerDialogPane, Pane, GrafPort, LObject, EventHandler at `+0xa0`, TimerHandler at `+0xa4`, and Singleton<TransferServerDialogPane> at `+0xf8`.
- Original string-symbol search found only `.?AVTransferServerDialogPane@@` and `.?AV?$Singleton@VTransferServerDialogPane@@@@`; no PDB/source path or recoverable original member names were present.

## Function / Child Inventory

| Half-open binary range | Size | SHA256 | Source disposition | Proposed child |
| --- | ---: | --- | --- | --- |
| `[0x00598ed0,0x00599220)` | 848 | `D10CD8D1163258DD09132DDCD6A56ECBCF65217ABA85236D911C9F5717ADE4B2` | Source constructor | `0x00598ed0-0x0059921f.TransferServerDialogPaneConstructor.md` |
| `[0x00599220,0x00599249)` | 41 | `B8E7A6FF240102BD7657DABA0BC1C77D345CB8C053081CA245567F64D0CE9BDB` | Source ordinary destructor plus compiler lowering | `0x00599220-0x00599248.TransferServerDialogPaneDestructor.md` |
| `[0x00599250,0x00599262)` | 18 | `486A98FCBD798575CA57E32E79E5799CCF71283C9E5148213AB6EB84E95A24DF` | Source method | `0x00599250-0x00599261.TransferServerDialogPaneResetOpacityAndRepaint.md` |
| `[0x00599270,0x005992e9)` | 121 | `AF5BAE297B3ED158E9D07C8FA52FEB7A6ADEE689F0B3D3A645C5E15D5F35B887` | Source timer override | `0x00599270-0x005992e8.TransferServerDialogPaneOnTimer.md` |
| `[0x005992f0,0x005993a6)` | 182 | `E273F05A2CD6C41AE6C29B8E4070B42930AB0577A449A6F90B73CF28CDD4C83C` | Source paint override | `0x005992f0-0x005993a5.TransferServerDialogPaneOnPaint.md` |
| `[0x005993b0,0x005993bb)` | 11 | `3D21F94D67AEC593FDB59D9D0CBA75ED7970DC326754B0B74042F214DF2D1EE4` | Compiler EH cleanup | `0x005993b0-0x005993ba.TransferServerDialogPaneConstructorUnwindClearSingleton.md` |
| `[0x005993bb,0x005993d1)` | 22 | first thunk SHA256 `9910A1B667C587D2BF626DA1F49B097F1E88C8097BB6D195EB1756A6A46F0E60`; second thunk SHA256 `001BD22E06AE1148A95F25C61707EE5FECC18B3B51EC7FDD30B21BE1AD2B5E9A` | Two compiler adjustors | `0x005993bb-0x005993d0.TransferServerDialogPaneDestructorAdjustorThunks.md` |
| `[0x005993e0,0x0059943f)` | 95 | `88983469638C0AA86AFD0DE14C34A20F40E3E9755C02E1EAD224311208D8133E` | Compiler scalar deleting destructor | `0x005993e0-0x0059943e.TransferServerDialogPaneScalarDeletingDestructor.md` |

Parent-only padding is exactly: `[0x00599249,0x00599250)` 7 `cc`; `[0x00599262,0x00599270)` 14 `cc`; `[0x005992e9,0x005992f0)` 7 `cc`; `[0x005993a6,0x005993b0)` 10 `cc`; `[0x005993d1,0x005993e0)` 15 `cc`. The predecessor and successor one-byte pads are `[0x00598ecf,0x00598ed0)` and `[0x0059943f,0x00599440)`.

## Direct Xref / Caller Inventory

- Constructor direct calls: `0x004f748b`, `0x004f8f7d`, `0x00507d63`, `0x00507dc5`, `0x0050ff65`, `0x0050ffce`, `0x0051012e`, `0x00510299`, `0x005102fb`, grouped in five caller functions.
- Ordinary destructor `0x00599220`: no direct code xref; source identity is proven by ordinary/scalar parity, lifecycle, vptr resets, base teardown, and vtable family.
- Reset `0x00599250`: two direct calls, `0x005aad05` and `0x005aae78`, both inside the transfer packet path at `0x005aac80` before dialog removal/state changes.
- Timer `0x00599270`: vtable data route at `0x0062e500`; no ordinary call expected.
- Paint `0x005992f0`: vtable data route at `0x0062e4c4`; no ordinary call expected.
- Unwind clear `0x005993b0`: sole code xref `0x00609c11` from constructor EH/unwind metadata.
- Adjustors: vtable data routes `0x0062e4cc` and `0x0062e4fc`; both tail-forward to scalar wrapper.
- Scalar deleting destructor: primary vtable data route `0x0062e480` plus adjustor forwards.
- `g_pTransferServerDialog` has exactly 20 refs: `0x004f7460`, `0x004f7497`, `0x004f8f55`, `0x00506f81`, `0x00507d38`, `0x00507d9b`, `0x0050ff3d`, `0x0050ffa0`, `0x00510271`, `0x005102d4`, `0x00598f21`, `0x00598f28`, `0x0059923a`, `0x005993b0`, `0x00599400`, `0x005a5c23`, `0x005aacfb`, `0x005aad0a`, `0x005aae6e`, `0x005aae7d`.
- Resource xrefs: `TRANSSVR.EPF` at `0x00598f7d`, `0x00598f9b`, `0x00599326`; `TRANSSVR.EPD` at `0x00599096`, `0x005990bb`, `0x00599337`; `TRANSSVR.PAL` at `0x00599330`; `TRANSSVR.PAD` at `0x00599341`; `0.03f` at the timer decrement.

## Documentation Evidence And IDA Status

- Historical pre-callback UID00026R had the correct broad owner family and generated-data concept but incomplete endpoints, split state, owner type, metadata, nesting, and support reconstruction; the callback resolved all of them.
- Historical pre-callback UID0001KD had accurate broad behavior/ranges but stale raw names, blank source, unresolved fields/destructor language, and no exact children; it is now the complete non-emitting split index.
- Historical pre-callback UID0000F7/UID0000OW deferred source and treated `+0x90` as possibly local; the implemented class/file pages now identify inherited `m_alpha` and emit exact source.
- Historical pre-callback UID0000VJ was emitting/reconstructable; it is now the false/non-emitting compatibility index with exact child routes.
- Historical pre-callback UID0000SL had a blank block and UID0002XO had stale summary/disposition; the global now emits and exact storage is false/all-zero.
- Historical pre-callback UID0003E4 mislabeled the Transfer COL as Totem alignment and UID0003E5 started four bytes late; both boundaries are now corrected.
- At evidence collection time the IDA session was healthy and real target calls succeeded. This sentence records historical evidence-time status only and does not assert ongoing session availability.

## Ranked Ownership Analysis

1. `TransferServerDialogPane` class UID0000F7, emitted through file UID0000OW: overwhelming. RTTI, every local vtable slot, constructor/destructor stores, all resource consumers, timer constant, object fields, and singleton lifecycle agree.
2. `TransferServerDialogPane.cpp` file UID0000OW: very high. It is the narrow coherent module containing declaration, methods, resource spellings, and global definition.
3. Pane/GrafPort/TimerHandler/EventHandler: dependency/base owners only. They explain inherited slots and storage but not Transfer-specific overrides/resources.
4. ResourceLayoutTable/ImageLib, PaletteLib, Surface, SoundManager: callee/dependency owners only.
5. MainMenuPane/MapPane/session handlers: caller/consumer owners only; constructor fan-in does not transfer implementation ownership.
6. TimerPane/TotemFrame: immediate physical/source-family neighbors only; exact byte boundaries reject overlap.
7. UniAPIInit/UrlAlertPane: successor owners only; corrected boundary excludes their COL/vtables.

## Source Placement

- Keep `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` and source file `NexusTK/ui/dialogs/TransferServerDialogPane.cpp`.
- Source order: class declaration with `extern` global, then exact source child definitions through `[[CHILDREN]]`, then the global definition. Non-emitting aggregate/data/compiler/item/storage pages must not add output.
- Preserve blank `EMITTER_POSITION_OPTIONAL` on UID0000F7 and UID0000SL. Give all five source method children blank positions as well: their exact address order under UID0000F7 deterministically yields constructor, destructor, reset, timer, and paint definitions, matching the established TimerPane child convention without synthetic numeric positions. Every non-emitting destination also keeps a blank position.
- Resource strings are ordinary literals at their use sites in constructor/paint. The fade constant is the `0.03f` expression in `OnTimer`. No separate asset-source C++ or by-resource emitter is justified.
- This is not a third-party source import. No `third_party_embeds/` directive applies.

## Range / Split / Padding / Reclassification Analysis

- Read-only address order and cumulative nesting:
  - UID00026Q parent cumulative 0; first child UID0003E0 `+8`; later children, including UID0003E4, remain cumulative 8.
  - UID00026R must apply `-8` to return cumulative depth to 0.
  - New target vtable child applies `+8`; new string/constant children use `0`.
  - UID00026S applies `-8`; UID0003E5 applies `+8`; UID0002P0 uses `0`; UID00026T applies `-8`.
- Executable address order and cumulative nesting:
  - UID0001KC already closes TimerPane children with `Nested:-4`; UID0001KD remains at cumulative 0 with `Nested:0`.
  - New constructor child applies `+4`; all seven following exact children use `0`; UID000249 applies `-4`.
- Target child boundaries align to semantic data, not arbitrary alignment: RTTI/vtables end at string start `0x0062e504`, strings end at `0x0062e574`, constant ends at foreign COL `0x0062e578`.
- UID00026R and UID0001KD become false/non-emitting because children carry exact ownership/output. This is reclassification, not evidence loss: parent pages retain complete inventories, hashes, gaps, history, and child links.

## Negative Evidence Summary

- No original TransferServerDialogPane PDB path, source file name, method/member symbols, or standalone resource/global symbols survive beyond RTTI class/template names.
- No padding exists inside the corrected target; no unexplained data remains.
- No direct call to ordinary destructor exists, but vtable/scalar/base-teardown parity supplies stronger destructor identity than a generic no-route blocker.
- No direct call to timer/paint is expected; both have exact vtable slots.
- No ordinary source route exists for unwind helper, adjustors, or scalar wrapper; their EH/vtable/delete routes prove compiler support.
- No evidence supports direct EventHandler/TimerHandler inheritance, a Transfer-owned alpha field, explicit vptr/cookie/facet fields, a third derived field, or a non-empty Singleton base.
- No evidence supports `OnTimerEvent`, `OnTimerTick`, `OnPaintFrame`, `int OnPaint`, explicit helper clear, raw vtable arrays, raw RTTI declarations, standalone literal arrays, or a named fade constant.
- No branch supports frame-count zero defense, EPFTileContext release, initialized union accumulator, unconditional alpha assignment, or rewritten clamp semantics.
- No active/archived/Older-Research/SpecialReports exact report duplicates this target.

## IDA Rename / Type / Comment Recommendations

- Safe function names after callback, if IDA naming is separately authorized: `TransferServerDialogPane__Constructor` at `0x00598ed0`, `TransferServerDialogPane__Destructor` at `0x00599220`, `TransferServerDialogPane__ResetOpacityAndRepaint` at `0x00599250`, `TransferServerDialogPane__OnTimer` at `0x00599270`, and `TransferServerDialogPane__OnPaint` at `0x005992f0`.
- Compiler-support names may be descriptive: constructor unwind clear at `0x005993b0`, destructor adjustors at `0x005993bb/0x005993c6`, scalar deleting destructor at `0x005993e0`.
- Type the primary object as `TransferServerDialogPane`; inherited callback facet receivers at `+0xa0/+0xa4` should adjust to the enclosing object rather than create duplicate fields/bases.
- Type `0x0069b4b0` as `TransferServerDialogPane *g_pTransferServerDialog` with initial zero.
- Retain historical raw names only in evidence/history sections. This report does not change IDA state.

## First-Draft C++ Recommendation

The following are the complete managed destination blocks. There are 20 blocks. Blank blocks are intentional exhaustive no-code destinations, not omitted work.

### UID00026R corrected target

Destination: `by-memory/0x0062e47c-0x0062e578.TransferServerReadOnlyData.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### New TransferServerDialogPane vtable-data child

Destination: `by-memory/0x0062e47c-0x0062e504.TransferServerDialogPaneVtableData.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### New TransferServer resource-string child

Destination: `by-memory/0x0062e504-0x0062e574.TransferServerResourceStringData.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### New TransferServer fade-step child

Destination: `by-memory/0x0062e574-0x0062e578.TransferServerFadeStepConstant.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0001KD executable split index

Destination: `by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### New constructor child

Destination: `by-memory/0x00598ed0-0x0059921f.TransferServerDialogPaneConstructor.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
TransferServerDialogPane::TransferServerDialogPane(bool autoClose)
    : Pane(3),
      m_currentFrame(0),
      m_frameCount(34)
{
    g_pTransferServerDialog = this;
    m_alpha = 0.9f;

    RectBounds frameBounds;
    RectBounds frameRect;
    unsigned short frameCount;

    if (g_useEpfAssets == 1) {
        frameCount = g_pEPFLib->GetEntryCount(L"TRANSSVR.EPF");
        for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex) {
            g_pEPFLib->GetEntryRect(L"TRANSSVR.EPF", frameIndex, &frameRect);
            frameBounds.UnionWith(&frameRect);
        }
    } else {
        frameCount = g_pEPFLib->GetEntryCount(L"TRANSSVR.EPD");
        for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex) {
            g_pEPFLib->GetEntryRect(L"TRANSSVR.EPD", frameIndex, &frameRect);
            frameBounds.UnionWith(&frameRect);
        }
    }

    if (frameBounds.right - frameBounds.left > g_screenWidth)
        frameBounds.right = frameBounds.left + g_screenWidth;
    if (frameBounds.bottom - frameBounds.top > g_screenHeight)
        frameBounds.bottom = frameBounds.top + g_screenHeight;

    if (g_activeMapPane != 0) {
        Point unusedOrigin;
        RectBounds mapBounds;
        g_activeMapPane->GetOrigin(&unusedOrigin);
        g_activeMapPane->GetBounds(&mapBounds);

        int offsetX = (mapBounds.right - mapBounds.left - 144) / 2;
        int offsetY = (mapBounds.bottom - mapBounds.top - 144) / 2;
        if (g_useEpfAssets == 1) {
            offsetX -= 100;
            offsetY -= 100;
        }
        frameBounds.Offset(offsetX, offsetY);
    } else {
        frameBounds.Offset((g_pScreenPane->GetScreenWidth() - 144) / 2,
                           (g_pScreenPane->GetScreenHeight() - 144) / 2);
    }

    AddToLayer(&frameBounds, 0, 0, g_mainUiLayerSlots.overlayPaneLayerContext);
    SetPaneOrder(0, 0);
    ScheduleTimer(0, 100, 0, 0);
    if (autoClose)
        ScheduleTimer(1, 5000, 0, 0);
    g_pSoundManager->PlaySound(0x19c, 100);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

`frameBounds` is intentionally not value-initialized. That unusual source shape preserves the observed binary rather than silently repairing it.

### New ordinary-destructor child

Destination: `by-memory/0x00599220-0x00599248.TransferServerDialogPaneDestructor.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
TransferServerDialogPane::~TransferServerDialogPane()
{
    g_pTransferServerDialog = 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### New ResetOpacityAndRepaint child

Destination: `by-memory/0x00599250-0x00599261.TransferServerDialogPaneResetOpacityAndRepaint.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void TransferServerDialogPane::ResetOpacityAndRepaint()
{
    m_alpha = 0.0f;
    InvalidateRect(0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### New OnTimer child

Destination: `by-memory/0x00599270-0x005992e8.TransferServerDialogPaneOnTimer.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool TransferServerDialogPane::OnTimer(int timerId, int arg0, int arg1)
{
    if (timerId == 0) {
        float newAlpha = fmaxf(0.0f, m_alpha - 0.03f);
        if (newAlpha <= 1.0f)
            m_alpha = newAlpha;

        m_currentFrame = (m_currentFrame + 1) % m_frameCount;
        InvalidateRect(0);
        ScheduleTimer(0, 100, 0, 0);
    } else if (timerId == 1) {
        MarkForDeletion();
    }

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### New OnPaint child

Destination: `by-memory/0x005992f0-0x005993a5.TransferServerDialogPaneOnPaint.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void TransferServerDialogPane::OnPaint()
{
    EPFTileContext frame;
    frame.Initialize();

    void *palette;
    if (g_useEpfAssets == 1) {
        g_pEPFLib->LookupLayoutEntry(L"TRANSSVR.EPF", m_currentFrame, &frame);
        palette = g_pPaletteLib->GetPaletteByName(L"TRANSSVR.PAL");
    } else {
        g_pEPFLib->LookupLayoutEntry(L"TRANSSVR.EPD", m_currentFrame, &frame);
        palette = g_pPaletteLib->GetPaletteByName(L"TRANSSVR.PAD");
    }

    RectBounds destination = frame.bounds;
    destination.Offset(-frame.bounds.left, -frame.bounds.top);
    g_pfnBlitSprite(this,
                    &frame,
                    &frame.bounds,
                    &destination,
                    1,
                    palette,
                    0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### New constructor-unwind child

Destination: `by-memory/0x005993b0-0x005993ba.TransferServerDialogPaneConstructorUnwindClearSingleton.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### New destructor-adjustor child

Destination: `by-memory/0x005993bb-0x005993d0.TransferServerDialogPaneDestructorAdjustorThunks.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### New scalar-deleting-destructor child

Destination: `by-memory/0x005993e0-0x0059943e.TransferServerDialogPaneScalarDeletingDestructor.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0000F7 class declaration

Destination: `by-class/TransferServerDialogPane.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class TransferServerDialogPane : public Pane,
                                 public Singleton<TransferServerDialogPane>
{
public:
    explicit TransferServerDialogPane(bool autoClose);
    virtual ~TransferServerDialogPane();

    void ResetOpacityAndRepaint();

protected:
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual void OnPaint();

private:
    int m_currentFrame;
    int m_frameCount;
};

extern TransferServerDialogPane *g_pTransferServerDialog;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

The class closes before `[[CHILDREN]]`; exact child definitions must emit at namespace scope.

### New TransferServerDialogPaneLayout support

Destination: `by-type/by-struct/TransferServerDialogPaneLayout.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### New TransferServerDialogPaneVtables support

Destination: `by-type/by-vtable/TransferServerDialogPaneVtables.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0000VJ compatibility item

Destination: `by-item/TransferServerDialogPaneThunks_599220_5993e0.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0000SL source global

Destination: `by-global/g_pTransferServerDialog.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
TransferServerDialogPane *g_pTransferServerDialog = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0002XO exact storage

Destination: `by-memory/0x0069b4b0-0x0069b4b4.g_pTransferServerDialog.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID00029W mixed singleton-slot index

Destination: `by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Final Recommendation

Accept C01-C46 as one bounded split/source-quality callback. The target itself must remain blank and non-emitting, but blank target C++ is now a proven generated-data disposition rather than a deferred default. The exact source reconstruction lives in the class, five source method children, and singleton global. Three compiler-support children and every physical data/index/storage support remain blank.

The formal source intentionally preserves the binary's unusual behaviors: unseeded rectangle union accumulator, no frame-count guard, conditional alpha assignment after `fmaxf`, explicit unused `GetOrigin`, second `g_useEpfAssets` read for map offset, no EPFTileContext release, and exact timer/sound/layer constants.

## Recommended Target Doc Changes

The following is the accepted callback specification and is retained as durable implementation history. B004 applied every item; it is not a pending instruction list.

1. Lease old UID00026R path only immediately before edit; perform one UID-preserving move to `0x0062e47c-0x0062e578.TransferServerReadOnlyData.md`; validate the new path in ordinary file mode; confirm old path absent and UID unique; release immediately.
2. Apply `92/94`, owner `0000F7`, false, blank emitter/position/formal block, `Nested:-8`.
3. Replace Range, Summary, Observed Contents, Ownership Map, Evidence, Boundary Evidence, score rationale, reconstruction notes, related links, and Changes with the complete corrected facts in this report. Preserve historical prior ranges/scores explicitly as superseded history.
4. Create/register the three exact target children serially in address order, capture real UIDs, then add cross-references. All three are owner `0000F7`, false/non-emitting, blank position/formal C++, first `Nested:+8`, rest `0`.
5. Suggested child scores: vtable data `92/95`; resource strings `91/94`; fade constant `91/95`.

## Recommended Support Doc Changes

The following accepted support specification was applied and scoped-validated. Imperative phrasing is historical specification text, not outstanding work.

- UID00026Q: UID-preserving rename end `0x0062e480 -> 0x0062e47c`; retain `87/93`, false/non-emitting/mixed-owner state; state that its last exact child ends before Transfer primary COL.
- UID0003E4: UID-preserving rename to `0x0062e460-0x0062e47c.TotemFrameResourceStringData.md`; retain score/owner/emitter/body disposition; remove false trailing-alignment ownership and update all links.
- UID0001RR: update only UID0003E4 range/link and successor boundary; preserve score, DAT/frame-index questions, resource semantics, and formal disposition.
- UID00026S: UID-preserving rename to `0x0062e578-0x0062e624.UniApiUrlAlertReadOnlyData.md`; preserve `86/92`, false/non-emitting, content, and owners; `Nested:-8`.
- UID0003E5: UID-preserving rename to `0x0062e578-0x0062e580.UniAPIInitVtableData.md`; preserve `85/91`, owner/emitter/content, blank formal C++; `Nested:+8`; document COL at 578 and table at 57c.
- UID0002P0: preserve path/content/score/formal block; change only relative `Nested:0` and corrected predecessor links if needed.
- UID00026T: preserve path/content/score/formal block; change relative `Nested:-8` to close UID00026S children.
- UID0001KD: apply `92/94`, owner `0000F7`, false, blank emitter/position/formal block, Nested 0; retain full aggregate evidence and add eight exact child links/hashes/padding.
- Create/register eight executable children serially in ascending address order before cross-referencing. Suggested metadata: source children owner/emitter `0000F7`, true, blank emitter positions; constructor `92/94`, destructor `91/94`, reset `91/93`, timer `92/95`, paint `92/95`; compiler children owner `0000F7`, false, blank emitter/position/C++, unwind `91/95`, adjustors `92/96`, scalar `92/96`. Constructor `Nested:+4`; remaining children `0`.
- UID000249: preserve every score/body/detail; apply relative `Nested:-4` only.
- UID0000F7: apply `92/94`, retain owner/emitter UID0000OW, true; insert exact class block; replace stale method names/layout/blockers; add exact child/layout/vtable links and full evidence.
- Create `by-type/by-struct/TransferServerDialogPaneLayout.md`: `91/94`, owner `0000F7`, false/non-emitting, blank formal block; exact `0x100` layout, Pane/GrafPort inherited offsets, EventHandler/TimerHandler facets, Singleton EBO, two derived fields, rejected explicit-vptr/cookie/direct-base alternatives.
- Create `by-type/by-vtable/TransferServerDialogPaneVtables.md`: `92/95`, owner `0000F7`, false/non-emitting, blank formal block; all three COLs/tables/slots/stores/RTTI bases/adjustors and source declaration reproduction route.
- UID0000OW: apply `92/94`; preserve reconstruction path; replace blank blockers with final contents/source order/dependencies/caller exclusions and complete target/child support links.
- UID0000VJ: apply `91/94`, owner `0000F7`, false, blank emitter/position/formal block; retain detailed helper evidence as a compatibility index and route exact children.
- UID0000SL: apply `90/93`, retain owner/emitter UID0000OW, true; insert exact global definition; preserve 20 refs and source ownership.
- UID0002XO: apply `90/94`, owner `0000SL`, false, blank emitter/position/formal; correct Item Summary to zero initialization; preserve all xrefs/history.
- UID00029W: preserve `90/93`, owner NONE, false, blank block; correct only stale Item Summary/all-zero wording while preserving four-slot inventory and historical superseded `0xffffffff` notes.
- Pages explicitly unchanged except validator-managed reverse-link propagation: Pane, GrafPort, EventHandler, TimerHandler, Singleton, RectBounds, EPFTileContext, ResourceLayoutTable/ImageLib, PaletteLib, Surface callback docs, SoundManager, MainUiLayerSlots, MainMenuPane, MapPane, OpenTransferServerDialog, TotemFrame executable/class/file, UniAPIInit class/executable/static slot, UrlAlertPane class/executable/vtable support, and all unrelated scores/formal blocks.

## Score And Metadata Recommendation

| Destination | Historical pre-callback | Implemented | Owner/emitter | Reconstructable/formal | Nested |
| --- | --- | --- | --- | --- | ---: |
| UID00026R corrected target | 86/90 | 92/94 | owner 0000F7; no emitter | false; blank | -8 |
| UID0001KD executable aggregate | 88/88 | 92/94 | owner 0000F7; no emitter | false; blank | 0 |
| UID0000F7 class | 87/88 | 92/94 | owner/emitter 0000OW | true; class block | unchanged |
| UID0000OW file | 88/88 | 92/94 | FILE | source route | n/a |
| UID0000VJ compatibility item | 86/91 | 91/94 | owner 0000F7; no emitter | false; blank | n/a |
| UID0000SL global | 87/90 | 90/93 | owner/emitter 0000OW | true; global body | n/a |
| UID0002XO storage | 87/90 | 90/94 | owner 0000SL; no emitter | false; blank | 0 |
| UID00029W mixed storage index | 90/93 | unchanged | NONE/no emitter | false; blank | 0 |
| New target children | absent | 92/95, 91/94, 91/95 | owner 0000F7; no emitter | false; blank | +8,0,0 |
| New source method children | absent | 91-92/93-95 | owner/emitter 0000F7 | true; exact bodies | +4, then 0 |
| New compiler children | absent | 91-92/95-96 | owner 0000F7; no emitter | false; blank | 0 |
| New layout/vtable supports | absent | 91/94 and 92/95 | owner 0000F7; no emitter | false; blank | n/a |

Completion rises because all bytes, slots, methods, layout, ownership, source contracts, generated dispositions, neighbors, padding, callers, and manual coverage effects are closed. Confidence remains below final/perfect because original member/method/file spellings and exact source formatting do not survive, `frameBounds` source initialization intent is inferred from absence of lowering, and external headers may spell some dependency types differently.

## Open Questions With Attempted Resolution

| Question | Routes attempted | Resolution / score effect |
| --- | --- | --- |
| Original class file name? | RTTI strings, source-path strings, callers, current routing, neighboring UI modules, prior reports. | No original path survives. `ui/dialogs/TransferServerDialogPane.cpp` is highest probability and no longer blocks C++; caps confidence only. |
| Original field names? | Offset/xref matrix, TimerPane conventions, resource semantics, decompilation. | `m_currentFrame`/`m_frameCount` are stable descriptive names; exact spellings cap confidence only. |
| Is `m_alpha` local? | GrafPort/WaterFilter/Chatting/Transfer offset comparisons and constructor chains. | No; inherited GrafPort field. Closed. |
| Direct base list? | RTTI CHD, constructor calls, Pane layout, vtable facets, EBO. | Pane + Singleton only. Closed. |
| Ordinary destructor source body? | Non-deleting/scalar parity, EH, base teardown, vtable stores, global lifecycle. | Only global clear is handwritten. Closed. |
| Unwind helper liveness? | Code xrefs, EH metadata, pointer scans. | Compiler EH cleanup at `0x00609c11`; no source helper. Closed. |
| Paint callback return/name? | Primary vtable contract, inherited Pane docs, ABI, sibling source. | `void OnPaint()`. Closed. |
| Timer callback return/name? | Tertiary vtable contract, ABI, all return paths, TimerPane precedent. | `bool OnTimer(int,int,int)`. Closed. |
| Resource declaration style? | String symbols/xrefs, source-era patterns, existing render methods. | Inline wide literals in constructor/paint; no standalone arrays. Closed. |
| Union accumulator initialization? | Raw bytes/decompile/disassembly and RectBounds helper behavior. | Binary has no seed; preserve uninitialized local and document risk. Closed for parity, confidence cap only. |
| Initial singleton bytes? | Live get_bytes, slot docs, parent table, historical notes. | Exactly zero; stale `0xffffffff` summaries rejected. Closed. |
| Asset archive/frame semantics? | Resource docs and consumers. | Not needed for source reconstruction: count/rect/frame lookup remains through ResourceLayoutTable. Excluded from target blocker set. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

These are supervisor-owned manual coverage operations. B004 must not apply them. For new pages, tokens such as `0004MS` mean the exact validator-assigned UID captured during serial registration; substitute that UID before inserting the row. There are no tracker edits proposed by B004.

No deletion-only operation is required. Each stale existing row identified below is deleted as part of an atomic same-UID replacement; no existing page row is removed without replacement. Rows for newly registered pages are additions at the stated placement after their tokens are replaced with exact validator-assigned UIDs.

### `by-memory/-coverage-report.md`

Replace the current UID0001KD row at the TransferServer executable position with this parent row, then insert the eight child rows immediately below it in ascending address order:

```markdown
    - [UID:0001KD][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md) 0x00598ed0-0x0059943f | split class-method/compiler-support index | TransferServerDialogPane : ignored : 92% : very-strong : Complete non-emitting TransferServerDialogPane executable index with exact 1391-byte hash, five source-authored children, three compiler-support children, all padding, nine constructor calls, callback/global liveness, 0x100-byte layout, TRANSSVR resources, and source route through UID0000F7/UID0000OW; no parent body or duplicate ABI glue.
        - [UID:0004MV][0x00598ed0-0x0059921f.TransferServerDialogPaneConstructor](by-memory/0x00598ed0-0x0059921f.TransferServerDialogPaneConstructor.md) 0x00598ed0-0x0059921f | constructor | TransferServerDialogPane::TransferServerDialogPane : reconstructable : 92% : very-strong : Exact Pane(3), singleton publish, inherited alpha, frame count/union/clamp, map-or-screen placement, layer/order, timers, and sound body with unseeded union accumulator preserved.
        - [UID:0004MW][0x00599220-0x00599248.TransferServerDialogPaneDestructor](by-memory/0x00599220-0x00599248.TransferServerDialogPaneDestructor.md) 0x00599220-0x00599248 | destructor | TransferServerDialogPane::~TransferServerDialogPane : reconstructable : 91% : very-strong : Ordinary virtual destructor source clears g_pTransferServerDialog; vptr restoration and Pane teardown remain compiler/base lowering.
        - [UID:0004MX][0x00599250-0x00599261.TransferServerDialogPaneResetOpacityAndRepaint](by-memory/0x00599250-0x00599261.TransferServerDialogPaneResetOpacityAndRepaint.md) 0x00599250-0x00599261 | method | TransferServerDialogPane::ResetOpacityAndRepaint : reconstructable : 91% : very-strong : Two-call source helper sets inherited GrafPort m_alpha to 0.0f and invalidates the pane.
        - [UID:0004MY][0x00599270-0x005992e8.TransferServerDialogPaneOnTimer](by-memory/0x00599270-0x005992e8.TransferServerDialogPaneOnTimer.md) 0x00599270-0x005992e8 | timer override | TransferServerDialogPane::OnTimer : reconstructable : 92% : very-strong : Exact TimerHandler callback preserves fmaxf/conditional alpha assignment, modulo frame advance without zero guard, repaint/reschedule, auto-close delete, and true return.
        - [UID:0004MZ][0x005992f0-0x005993a5.TransferServerDialogPaneOnPaint](by-memory/0x005992f0-0x005993a5.TransferServerDialogPaneOnPaint.md) 0x005992f0-0x005993a5 | paint override | TransferServerDialogPane::OnPaint : reconstructable : 92% : very-strong : Exact TRANSSVR EPF/EPD and PAL/PAD selection, frame lookup, destination offset, and slot-2 sprite blit with no invented release.
        - [UID:0004N0][0x005993b0-0x005993ba.TransferServerDialogPaneConstructorUnwindClearSingleton](by-memory/0x005993b0-0x005993ba.TransferServerDialogPaneConstructorUnwindClearSingleton.md) 0x005993b0-0x005993ba | compiler EH cleanup | TransferServerDialogPane constructor unwind clear : ignored : 91% : very-strong : Sole EH/unwind route clears the published singleton; compiler-generated support, blank formal C++.
        - [UID:0004N1][0x005993bb-0x005993d0.TransferServerDialogPaneDestructorAdjustorThunks](by-memory/0x005993bb-0x005993d0.TransferServerDialogPaneDestructorAdjustorThunks.md) 0x005993bb-0x005993d0 | compiler adjustor thunks | TransferServerDialogPane destructor adjustors : ignored : 92% : very-strong : Exact -0xa0/-0xa4 receiver adjustors from secondary/tertiary vtable views into the scalar wrapper; blank formal C++.
        - [UID:0004N2][0x005993e0-0x0059943e.TransferServerDialogPaneScalarDeletingDestructor](by-memory/0x005993e0-0x0059943e.TransferServerDialogPaneScalarDeletingDestructor.md) 0x005993e0-0x0059943e | compiler scalar deleting destructor | TransferServerDialogPane scalar deleting destructor : ignored : 92% : very-strong : Compiler deleting wrapper over ordinary destructor/base teardown and conditional deallocation; blank formal C++.
```

Replace UID000249's current row with this row to reflect the current page score and the child-level closure placement; its content/body remains unchanged:

```markdown
    - [UID:000249][0x00599440-0x005995a7.PlatformStringConversionHelpers](by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md) 0x00599440-0x005995a7 | global helpers | PlatformStringConversionHelpers : reconstructable : 88% : strong : PlatformApi-owned default-codepage ANSI/wide allocation/free helper island with modeled source bodies, exact padding, MAPI/stream caller evidence, and unchanged PlatformApi ownership; follows and closes the TransferServerDialogPane exact-child run.
```

Replace the current UID00026Q, UID00026R, UID00026S, UID0002P0, and UID00026T rows, add UID0003E4/UID0003E5 where absent, and insert the three new UID00026R children as follows:

```markdown
    - [UID:00026Q][0x0062e334-0x0062e47c.TimerTotemReadOnlyData](by-memory/0x0062e334-0x0062e47c.TimerTotemReadOnlyData.md) 0x0062e334-0x0062e47c | split vtable/string-data index | TimerTotemReadOnlyData : ignored : 87% : very-strong : Non-emitting mixed Timer/Totem read-only index ending before the TransferServerDialogPane primary COL at 0x0062e47c; existing exact children retain timer/totem source ownership.
        - [UID:0003E4][0x0062e460-0x0062e47c.TotemFrameResourceStringData](by-memory/0x0062e460-0x0062e47c.TotemFrameResourceStringData.md) 0x0062e460-0x0062e47c | string-data | TotemFrameResourceStringData : reconstructable : 87% : very-strong : Exact UTF-16 TOTFRAME.EPD source literal and terminator consumed once by TotemFrame::OnPaint; ends immediately before TransferServerDialogPane RTTI with no claimed trailing alignment.
    - [UID:00026R][0x0062e47c-0x0062e578.TransferServerReadOnlyData](by-memory/0x0062e47c-0x0062e578.TransferServerReadOnlyData.md) 0x0062e47c-0x0062e578 | split vtable/string/constant index | TransferServerReadOnlyData : ignored : 92% : very-strong : Exact non-emitting 252-byte TransferServerDialogPane read-only island with primary/secondary/tertiary RTTI-vtables, four TRANSSVR UTF-16 source literals, one 0.03f timer constant, complete source reproduction routes, no padding, and corrected UniAPI successor boundary.
        - [UID:0004MS][0x0062e47c-0x0062e504.TransferServerDialogPaneVtableData](by-memory/0x0062e47c-0x0062e504.TransferServerDialogPaneVtableData.md) 0x0062e47c-0x0062e504 | vtable/RTTI data | TransferServerDialogPaneVtableData : ignored : 92% : very-strong : Exact three-view TransferServerDialogPane RTTI/vtable cluster regenerated from the Pane-plus-Singleton class declaration, virtual destructor, OnPaint/OnTimer overrides, and compiler adjustor/deleting-destructor support.
        - [UID:0004MT][0x0062e504-0x0062e574.TransferServerResourceStringData](by-memory/0x0062e504-0x0062e574.TransferServerResourceStringData.md) 0x0062e504-0x0062e574 | UTF-16 source literals | TransferServerResourceStringData : ignored : 91% : very-strong : Exact TRANSSVR.EPF/EPD/PAL/PAD bytes and constructor/paint xrefs; literals reproduce through accepted method bodies with no standalone array emission.
        - [UID:0004MU][0x0062e574-0x0062e578.TransferServerFadeStepConstant](by-memory/0x0062e574-0x0062e578.TransferServerFadeStepConstant.md) 0x0062e574-0x0062e578 | float constant | TransferServerFadeStepConstant : ignored : 91% : very-strong : Exact 0x3cf5c28f / 0.03f timer fade-step constant reproduced by TransferServerDialogPane::OnTimer; no standalone constant emission.
    - [UID:00026S][0x0062e578-0x0062e624.UniApiUrlAlertReadOnlyData](by-memory/0x0062e578-0x0062e624.UniApiUrlAlertReadOnlyData.md) 0x0062e578-0x0062e624 | split vtable-data index | UniApiUrlAlertReadOnlyData : ignored : 86% : strong : Non-emitting mixed UniAPIInit/UrlAlertPane index beginning at the UniAPIInit complete-object-locator pointer 0x0062e578; exact children retain PlatformApi and AlertPanes ownership.
        - [UID:0003E5][0x0062e578-0x0062e580.UniAPIInitVtableData](by-memory/0x0062e578-0x0062e580.UniAPIInitVtableData.md) 0x0062e578-0x0062e580 | RTTI/vtable-data | UniAPIInitVtableData : reconstructable : 85% : strong : Exact UniAPIInit complete-object-locator pointer plus one-slot vtable regenerated by the UniAPIInit static-object declaration and virtual destructor support; no handwritten dwords.
        - [UID:0002P0][0x0062e580-0x0062e624.UrlAlertPaneVtableData](by-memory/0x0062e580-0x0062e624.UrlAlertPaneVtableData.md) 0x0062e580-0x0062e624 | vtable-data | UrlAlertPaneVtableData : reconstructable : 86% : strong : Exact three-view UrlAlertPane RTTI/vtable cluster regenerated from its declaration, virtual destructor, OnPrimaryButton override, and compiler adjustor/deleting-destructor glue.
    - [UID:00026T][0x0062e624-0x0062e8fc.UserInfoReadOnlyData](by-memory/0x0062e624-0x0062e8fc.UserInfoReadOnlyData.md) 0x0062e624-0x0062e8fc | vtable/string-data | UserInfoReadOnlyData : reconstructable : 88% : strong : UserInfoDialogPane RTTI/vtable, title, validation, USERINFO.EPF, and option-string source companion data with generated-vtable handling and unchanged UserInfo ownership; closes the preceding UniAPI/UrlAlert exact-child run.
```

Replace UID00029W and UID0002XO rows with:

```markdown
    - [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md) 0x0069b4a4-0x0069b4b4 | global singleton pointer cluster | MainMenuDialogSingletonSlots : ignored : 90% : very-strong : Parentless non-emitting mixed-owner four-slot pre-login dialog singleton index; all four exact dwords are zero-initialized, with 6/6/7/20 xrefs and exact child/global routes for create-user, server-select, and transfer-server owners.
        - [UID:0002XO][0x0069b4b0-0x0069b4b4.g_pTransferServerDialog](by-memory/0x0069b4b0-0x0069b4b4.g_pTransferServerDialog.md) 0x0069b4b0-0x0069b4b4 | global pointer storage | g_pTransferServerDialog : ignored : 90% : very-strong : Exact zero-initialized TransferServerDialogPane singleton storage with 20 publish/clear/guard/consumer refs; source declaration/definition emits through UID0000SL/UID0000OW, so the physical storage page remains blank.
```

### `by-class/-coverage-report.md`

Replace UID0000F7 row with:

```markdown
- [UID:0000F7][TransferServerDialogPane](by-class/TransferServerDialogPane.md) : reconstructable : 92% : very-strong : Source-ready Pane-plus-Singleton animated transfer overlay declaration with exact 0x100 layout, inherited GrafPort alpha, two derived frame fields, virtual destructor, ResetOpacityAndRepaint, OnTimer/OnPaint overrides, eight exact executable children, three-view generated vtables, TRANSSVR resources, global lifecycle, and ui/dialogs source route.
```

### `by-file/-coverage-report.md`

Replace UID0000OW row with:

```markdown
- [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md) : reconstructable : 92% : very-strong : Complete NexusTK/ui/dialogs/TransferServerDialogPane.cpp source root containing the class declaration, five exact source method bodies, zero-initialized g_pTransferServerDialog definition, compiler-only destructor/vtable support dispositions, corrected read-only split, nine constructor calls, 20 singleton refs, resource/palette/render dependencies, and explicit caller/neighbor exclusions.
```

### `by-global/-coverage-report.md`

Replace UID0000SL row with:

```markdown
- [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md) : reconstructable : 90% : very-strong : Source-emitting zero-initialized TransferServerDialogPane pointer at 0x0069b4b0 with exactly 20 constructor publish/fallback-clear, destructor/unwind/scalar-clear, launcher-guard, login/map/session, and transfer-packet refs; emitted once through TransferServerDialogPane.cpp while exact storage UID0002XO remains non-emitting.
```

### `by-item/-coverage-report.md`

Replace UID0000VJ row with:

```markdown
- [UID:0000VJ][TransferServerDialogPaneThunks_599220_5993e0](by-item/TransferServerDialogPaneThunks_599220_5993e0.md) : ignored : 91% : very-strong : Non-emitting compatibility index for the ordinary destructor, constructor-unwind clear, -0xa0/-0xa4 destructor adjustors, and scalar deleting destructor; exact by-memory children now carry source/compiler dispositions and no broad thunk body is emitted.
```

### `by-resource/-coverage-report.md`

Replace UID0001RR row only to correct the exact literal child boundary; preserve score and unresolved DAT/frame semantics:

```markdown
- [UID:0001RR][totem-frame-resources](by-resource/totem-frame-resources.md) : reconstructable : 87% : strong : Totem frame resources with exact source-literal child [UID:0003E4][0x0062e460-0x0062e47c.TotemFrameResourceStringData](by-memory/0x0062e460-0x0062e47c.TotemFrameResourceStringData.md), sole TotemFrame::OnPaint xref, OldUserStatusPane::GetSpiritId selector evidence, shared NPAL7.PAL exclusion, DAT/source-payload boundary, and corrected end immediately before TransferServerDialogPane RTTI at 0x0062e47c.
```

### `by-type/by-struct/-coverage-report.md`

Insert alphabetically after the last `T...` entry at the exact `TransferServerDialogPaneLayout` sort position:

```markdown
- [UID:0004N3][TransferServerDialogPaneLayout](by-type/by-struct/TransferServerDialogPaneLayout.md) : ignored : 91% : very-strong : Non-emitting exact 0x100 layout support for Pane/GrafPort through +0xf7, inherited m_alpha at +0x90, EventHandler/TimerHandler facets at +0xa0/+0xa4, empty Singleton EBO at +0xf8, and only m_currentFrame/m_frameCount at +0xf8/+0xfc; class UID0000F7 owns the declaration.
```

### `by-type/by-vtable/-coverage-report.md`

Insert alphabetically at `TransferServerDialogPaneVtables`:

```markdown
- [UID:0004N4][TransferServerDialogPaneVtables](by-type/by-vtable/TransferServerDialogPaneVtables.md) : ignored : 92% : very-strong : Non-emitting exact three-view TransferServerDialogPane RTTI/vtable support at 0x0062e480, 0x0062e4cc, and 0x0062e4fc with complete slots, COLs/base hierarchy, constructor/destructor stores, OnPaint/OnTimer overrides, -0xa0/-0xa4 adjustors, and compiler-generation route through class UID0000F7.
```

### `by-type/-coverage-report.md`

The root manual type report also carries selected struct/vtable rows. Insert both new rows at the exact alphabetical `TransferServerDialogPane...` position, using the same validator-assigned UIDs captured above:

```markdown
- [UID:0004N3][TransferServerDialogPaneLayout](by-type/by-struct/TransferServerDialogPaneLayout.md) : ignored : 91% : very-strong : Non-emitting exact 0x100 layout support for Pane/GrafPort through +0xf7, inherited m_alpha at +0x90, EventHandler/TimerHandler facets at +0xa0/+0xa4, empty Singleton EBO at +0xf8, and only m_currentFrame/m_frameCount at +0xf8/+0xfc; class UID0000F7 owns the declaration.
- [UID:0004N4][TransferServerDialogPaneVtables](by-type/by-vtable/TransferServerDialogPaneVtables.md) : ignored : 92% : very-strong : Non-emitting exact three-view TransferServerDialogPane RTTI/vtable support at 0x0062e480, 0x0062e4cc, and 0x0062e4fc with complete slots, COLs/base hierarchy, constructor/destructor stores, OnPaint/OnTimer overrides, -0xa0/-0xa4 adjustors, and compiler-generation route through class UID0000F7.
```

## Follow-Up Actions

- No research or implementation item remains unresolved inside the accepted scope. C01-C46, all 20 formal destinations, 13 registrations, path/nesting corrections, support synchronization, validators, reverse links, and generated checks are complete.
- Manual coverage application and report validation/execution/counting/path movement/archive state are external supervisor/validator-owned facts. This artifact supplies exact real-UID coverage text and implementation proof but neither asserts nor directs those external lifecycle states.
- Residual original-spelling and asset-package questions are confidence caps or separately scoped resource research, not blockers to the recommended source.

## Confidence

- Range/data/vtable/function/padding/global facts: very high (`94-96`).
- Source ownership and class layout: high to very high (`94`).
- Human method contracts and method bodies: high to very high (`93-95`).
- Exact original field/file/private-helper spellings: medium-high; descriptive names are internally consistent and ABI-safe.
- Overall implemented result: high. Target `92/94` is validated; perfect confidence is withheld because stripped symbols cannot prove exact original lexical spellings or whether historical source factored tiny expressions into constants/helpers.

## Validator Results

- Every command was run from `source-3/project-documentation` as `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240`; command `000000010300` additionally used `--wait-generated`. Every command exited 0. `ok` below is the validator's literal `ok:` count; `n/a` means a successful new-page registration emitted mutation rows but no `ok:` field.

| Command / timestamp (2026-07-13 EDT) | Scoped path | Exit / ok | Principal side effects | Lease release |
| --- | --- | --- | --- | --- |
| `000000010219` / `15:48:46` | `by-memory/0x0062e47c-0x0062e504.TransferServerDialogPaneVtableData.md` | `0 / n/a` | Assigned UID0004MS; path, 92/95, owner 0000F7, false/blank registry, 3 refs; generated deferred. | Parent UID00026R lease released immediately. |
| `000000010220` / `15:49:30` | `by-memory/0x0062e504-0x0062e574.TransferServerResourceStringData.md` | `0 / n/a` | Assigned UID0004MT; path, 91/94, owner, false/blank registry, refs/link normalization; deferred. | Parent lease released. |
| `000000010222` / `15:49:59` | `by-memory/0x0062e574-0x0062e578.TransferServerFadeStepConstant.md` | `0 / n/a` | Assigned UID0004MU; path, 91/95, owner, false/blank registry, refs; deferred. | Parent lease released. |
| `000000010223` / `15:50:48` | constructor UID0004MV | `0 / n/a` | Assigned UID; 92/94 owner/emitter 0000F7, managed-body hash, refs; deferred. | UID0001KD parent lease released. |
| `000000010225` / `15:51:17` | destructor UID0004MW | `0 / n/a` | Assigned UID; 91/94 owner/emitter, managed-body hash, refs; deferred. | Parent lease released. |
| `000000010226` / `15:51:40` | reset UID0004MX | `0 / n/a` | Assigned UID; 91/93 owner/emitter, managed-body hash, refs; deferred. | Parent lease released. |
| `000000010228` / `15:52:08` | timer UID0004MY | `0 / n/a` | Assigned UID; 92/95 owner/emitter, managed-body hash, refs; deferred. | Parent lease released. |
| `000000010229` / `15:52:38` | paint UID0004MZ | `0 / n/a` | Assigned UID; 92/95 owner/emitter, managed-body hash, refs; deferred. | Parent lease released. |
| `000000010230` / `15:53:05` | unwind UID0004N0 | `0 / n/a` | Assigned UID; 91/95 owner 0000F7, false/blank registry, refs; deferred. | Parent lease released. |
| `000000010235` / `15:53:30` | adjustors UID0004N1 | `0 / n/a` | Assigned UID; 92/96 owner, false/blank registry, refs; deferred. | Parent lease released. |
| `000000010245` / `15:54:01` | scalar wrapper UID0004N2 | `0 / n/a` | Assigned UID; 92/96 owner, false/blank registry, refs; deferred. | Parent lease released. |
| `000000010257` / `15:54:32` | layout UID0004N3 | `0 / n/a` | Assigned UID; 91/94 owner, false/blank registry, refs; deferred. | UID0000F7 parent lease released. |
| `000000010265` / `15:55:17` | vtables UID0004N4 | `0 / n/a` | Assigned UID; 92/95 owner, false/blank registry, refs; deferred. | Parent lease released. |
| `000000010267` / `15:56:59` | renamed UID00026R final path | `0 / 1` | UID path update; 92/94/owner/false/emitter updates; reverse-link and manual-coverage link side effects; deferred. | Old-path lease released. |
| `000000010269` / `15:58:16` | renamed UID00026Q final path | `0 / 1` | UID path and 15 reverse-source updates; validator-managed manual coverage link update; deferred; missing-ref warnings preserved. | Old-path lease released. |
| `000000010270` / `15:58:55` | renamed UID0003E4 final path | `0 / 1` | Registered existing UID path/metadata, inserted header blank, 6 refs; deferred. | Old-path lease released. |
| `000000010272` / `15:59:41` | renamed UID00026S final path | `0 / 1` | UID path and 13 reverse-source/23 link updates including validator-managed coverage link; deferred. | Old-path lease released. |
| `000000010273` / `16:00:19` | renamed UID0003E5 final path | `0 / 1` | Registered existing UID path/metadata, inserted header blank, refs/link updates; deferred. | Old-path lease released. |
| `000000010274` / `16:00:44` | UID0002P0 | `0 / 1` | Nested 0 retained; corrected UID0003E5 links; deferred. | Lease released. |
| `000000010275` / `16:01:02` | UID00026T | `0 / 1` | Nested -8 validated; one pre-existing missing-ref warning; deferred. | Lease released. |
| `000000010279` / `16:01:48` | UID0001KD | `0 / 1` | 92/94 owner/false/emitter updates; eight child references; deferred. | Lease released. |
| `000000010280` / `16:02:03` | UID000249 | `0 / 1` | Nested -4 scoped validation; deferred. | Lease released. |
| `000000010281` / `16:02:59` | UID0000F7 class | `0 / 1` | 92/94, managed class-block hash/type, 13 new refs; deferred. | Lease released. |
| `000000010282` / `16:03:41` | UID0000OW file | `0 / 1` | 92/94 and 10 new refs/12 normalized links; deferred. | Lease released. |
| `000000010283` / `16:04:04` | UID0000VJ item | `0 / 1` | 91/94 owner/false/emitter updates, 4 child refs, reconstructable stats-row removal; deferred. | Lease released. |
| `000000010284` / `16:04:33` | UID0000SL global | `0 / 1` | 90/93, managed global-block hash/type, storage link, stats-row removal; deferred. | Lease released. |
| `000000010285` / `16:05:01` | UID0002XO storage | `0 / 1` | 90/94, true-to-false and emitter clear; deferred. | Lease released. |
| `000000010286` / `16:05:40` | UID00029W storage index | `0 / 1` | All-zero current summary validated; score/formal state unchanged; deferred. | Lease released. |
| `000000010287` / `16:06:13` | UID0001RR resource | `0 / 1` | Corrected UID0003E4 ref and projected stats row; deferred. | Lease released. |

Validator-managed reverse-link propagation on pages otherwise explicitly unchanged:

| Command / timestamp | Scoped page | Exit / ok | Link updates | Lease release |
| --- | --- | --- | ---: | --- |
| `000000010288` / `16:07:25` | `by-memory/0x0062e334-0x0062e340.TimerHandlerVtableData.md` | `0 / 1` | 7 | immediate |
| `000000010289` / `16:07:28` | `by-memory/0x0062e344-0x0062e354.TimerMgrVtableData.md` | `0 / 1` | 1 | immediate |
| `000000010290` / `16:07:40` | `by-memory/0x0062e3dc-0x0062e460.TotemFrameVtableData.md` | `0 / 1` | 1 | immediate |
| `000000010291` / `16:07:52` | `by-class/TotemFrame.md` | `0 / 1` | 5 | immediate |
| `000000010292` / `16:08:05` | `by-file/TotemFrame.md` | `0 / 1` | 4 | immediate |
| `000000010293` / `16:08:13` | `by-memory/0x00598cc0-0x00598ecf.TotemFrame.md` | `0 / 1` | 2 | immediate |
| `000000010294` / `16:08:21` | final UID00026Q page | `0 / 1` | 3 | immediate |
| `000000010295` / `16:08:33` | `by-class/UniAPIInit.md` | `0 / 1` | 4 | immediate |
| `000000010296` / `16:08:44` | `by-memory/0x005995b0-0x00599a34.UniAPIInit.md` | `0 / 1` | 1 | immediate |
| `000000010297` / `16:08:53` | `by-memory/0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot.md` | `0 / 1` | 1 | immediate |
| `000000010298` / `16:09:05` | `by-memory/-ignored.md` | `0 / 1` | 3 | immediate |
| `000000010299` / `16:09:17` | final UID00026S page | `0 / 1` | 2 | immediate |

- Final waited command `000000010300`, timestamp `2026-07-13T16:09:50-04:00`, scoped `by-class/TransferServerDialogPane.md`, exited 0 with `ok:1`, `generated_refresh: completed`, command/timestamp matching `10300`. Side effects were validator-owned registry rebuild (`4729` nodes, `3838` edges), projected stats, and `281` generated metadata refresh rows; B004 manually edited none of them. The class lease was released immediately.
- Generated readback: `auto-generated/NexusTK/ui/dialogs/TransferServerDialogPane.cpp`, 5019 bytes, SHA256 `2651F40328C8DD24B4E58A0D242F74838C39CC539890044A3C56FF5F17D72ACF`. Counts: class 1, global 1, constructor 1, destructor 1, reset 1, OnTimer 1, OnPaint 1. Counts were zero for UID00026R target empty marker, UID0001KD parent body, compiler UIDs 0004N0/N1/N2, old callback names, raw vptr/vtable-address text, scalar/unwind/adjustor source names, and source-emitter empty markers.
- Generated source preserves the unseeded `frameBounds`, exact EPF/EPD/PAL/PAD branches, map/screen placement, unguarded modulo, conditional alpha assignment, no invented tile-context release, and exact zero-initialized global.
- Subsequent read-only pre-return readback found that external validator command `000000010313` had refreshed only the generated provenance header at `2026-07-13T16:17:03-04:00`; the current file remained 5019 bytes with SHA256 `6AF08B3BF63D69DC9B3A3D7A2E5449F539074B15E22B5566CDA97AD044A6E89B`, all seven positive source counts still exactly one, and every preceding negative check still zero. B004 did not run command `10313` or edit the generated file.
- Final read-only artifact audit: all 20 report-managed destination blocks matched their current destination bytes (`20/20`, zero mismatches); all 26 checked target/support metadata invariants matched (`26/26`, zero mismatches); C01-C46 had 46 legal `applied` states and zero `proposed` states; all callback checklist boxes were checked; every validator-assigned UID appeared exactly once; all five superseded paths were absent; no placeholder UID, stale pending/readiness assertion, or B004 lease remained.
- MCP calls remained research evidence only. No MCP process was managed and no new callback binary uncertainty required another query.

## Changed Files

- B004 implementation destinations, each scoped-validated:
  - `by-memory/0x0062e47c-0x0062e578.TransferServerReadOnlyData.md` (renamed from old UID00026R path).
  - `by-memory/0x0062e47c-0x0062e504.TransferServerDialogPaneVtableData.md`, `0x0062e504-0x0062e574.TransferServerResourceStringData.md`, `0x0062e574-0x0062e578.TransferServerFadeStepConstant.md`.
  - `by-memory/0x0062e334-0x0062e47c.TimerTotemReadOnlyData.md` and `0x0062e460-0x0062e47c.TotemFrameResourceStringData.md` (renamed old UID00026Q/UID0003E4 paths).
  - `by-memory/0x0062e578-0x0062e624.UniApiUrlAlertReadOnlyData.md` and `0x0062e578-0x0062e580.UniAPIInitVtableData.md` (renamed old UID00026S/UID0003E5 paths).
  - `by-memory/0x0062e580-0x0062e624.UrlAlertPaneVtableData.md`, `0x0062e624-0x0062e8fc.UserInfoReadOnlyData.md`.
  - `by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md` and eight new children `0x00598ed0-0x0059921f.TransferServerDialogPaneConstructor.md`, `0x00599220-0x00599248.TransferServerDialogPaneDestructor.md`, `0x00599250-0x00599261.TransferServerDialogPaneResetOpacityAndRepaint.md`, `0x00599270-0x005992e8.TransferServerDialogPaneOnTimer.md`, `0x005992f0-0x005993a5.TransferServerDialogPaneOnPaint.md`, `0x005993b0-0x005993ba.TransferServerDialogPaneConstructorUnwindClearSingleton.md`, `0x005993bb-0x005993d0.TransferServerDialogPaneDestructorAdjustorThunks.md`, `0x005993e0-0x0059943e.TransferServerDialogPaneScalarDeletingDestructor.md`.
  - `by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md`.
  - `by-class/TransferServerDialogPane.md`, `by-type/by-struct/TransferServerDialogPaneLayout.md`, `by-type/by-vtable/TransferServerDialogPaneVtables.md`.
  - `by-file/TransferServerDialogPane.md`, `by-item/TransferServerDialogPaneThunks_599220_5993e0.md`, `by-global/g_pTransferServerDialog.md`.
  - `by-memory/0x0069b4b0-0x0069b4b4.g_pTransferServerDialog.md`, `0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md`, and `by-resource/totem-frame-resources.md`.
- Validator-managed reverse-link-only pages, with no B004 substantive edit: `by-memory/0x0062e334-0x0062e340.TimerHandlerVtableData.md`, `0x0062e344-0x0062e354.TimerMgrVtableData.md`, `0x0062e3dc-0x0062e460.TotemFrameVtableData.md`, `0x00598cc0-0x00598ecf.TotemFrame.md`, `0x005995b0-0x00599a34.UniAPIInit.md`, `0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot.md`, `by-class/TotemFrame.md`, `by-class/UniAPIInit.md`, `by-file/TotemFrame.md`, and `by-memory/-ignored.md`. UID00026Q/UID00026S also received later validator-only link refreshes after their substantive validators.
- This same report was updated in place: `tools/leaser/Agents/Agent-B004/research/00026R-TransferServerReadOnlyData-source-quality.md`.
- Validator-owned side effects included registry/projected-stat state, known reverse links, two manual-coverage path-link updates from rename validation, and the final generated refresh. B004 did not manually edit any generated, manual coverage, tracker, audit, supervisor, validator-state, lifecycle, queue, lock, IDA, or archive file.

## Implementation Tracking Checklist

### Report-Only Phase

- [x] Supervisor independently audited and accepted the pre-callback report revision; this post-callback revision still requires fresh supervisor Gate 1 and Gate 2 review, and this artifact does not assert either future review outcome.
- [x] Supervisor has accepted the corrected range, target false/non-emitting disposition, three read-only children, eight executable children, and source declaration/emitter route.
- [x] Supervisor has accepted the exact manual coverage replacement/addition text and validator-UID substitution plan.

### Implementation Callback Phase

- [x] Re-read every authorized destination and preserve concurrent/unrelated content.
- [x] UID-preserving rename UID00026R to `0x0062e47c-0x0062e578.TransferServerReadOnlyData.md`; apply C01-C09 and exact blank formal block; validate new path; prove old path absent/UID unique; release lease.
- [x] UID-preserving rename/update UID00026Q and UID0003E4 to end at `0x0062e47c`; update UID0001RR boundary/link; validate each changed page under its own short lease.
- [x] Create/register the three target read-only children serially in ascending address order; capture real UIDs before adding cross-references; apply exact scores/metadata/nesting/blank blocks and complete evidence.
- [x] UID-preserving rename/update UID00026S and UID0003E5 to start at `0x0062e578`; apply UID00026S/UID0003E5/UID0002P0/UID00026T nesting deltas exactly; validate/release each.
- [x] Update UID0001KD to the exact `92/94` false/non-emitting split index with complete hashes, gaps, inventory, history, and blank block.
- [x] Create/register all eight executable children serially in ascending address order; capture real UIDs before cross-referencing; apply every exact body/no-code block, score, owner/emitter, position, nesting, behavior, xref, hash, padding, rejection, and history fact.
- [x] Change UID000249 only to `Nested:-4` plus validator-managed reverse links; preserve score/formal body/unrelated content.
- [x] Update UID0000F7 to `92/94` with the exact class-before-children block, inheritance/layout/method/vtable/resource/global evidence, and historical aliases.
- [x] Create/register non-emitting `TransferServerDialogPaneLayout` and `TransferServerDialogPaneVtables` support pages with complete report-level evidence and blank blocks.
- [x] Update UID0000OW to `92/94`, retaining its path and adding the complete source inventory/order/dependencies/exclusions without unrelated changes.
- [x] Update UID0000VJ to `91/94`, owner `0000F7`, false/non-emitting compatibility index with exact-child routes and blank block.
- [x] Update UID0000SL to `90/93` with the exact global definition and all 20 refs.
- [x] Update UID0002XO to `90/94`, owner `0000SL`, false/non-emitting with zero-byte correction and blank block.
- [x] Update UID00029W Item Summary from all-`0xffffffff` to all-zero while preserving `90/93`, split inventory, body evidence, and historical superseded notes.
- [x] Run one scoped validator per changed ordinary `by-*` page from `source-3/project-documentation`; record exact command, ID, timestamp, exit, ok count, side effects, and lease release in this same report.
- [x] Confirm every lease is released immediately after its bounded edit/validation and no B004 lease remains.
- [x] Run one authorized final `--wait-generated` refresh and verify `NexusTK/ui/dialogs/TransferServerDialogPane.cpp` contains one class declaration, one global definition, and exactly one each constructor/destructor/reset/OnTimer/OnPaint definition.
- [x] Verify generated output has no UID00026R or UID0001KD parent body/Empty Emitter Marker, no target read-only child body, no compiler-child body, no UID0000VJ/UID0002XO/UID00029W duplicate body, no explicit vptr/cookie/facet fields, and no old-name `OnTimerEvent`/`OnPaintFrame` definition.
- [x] Verify generated output preserves unseeded frame-bounds accumulator, exact resource branches, map/screen placement, no zero-frame guard, conditional alpha assignment, no invented EPFTileContext release, and source-global initialization.
- [x] Update C01-C46 to legal callback actions/states with claim-by-claim proof; update Validator Results, Changed Files, current-state wording, and both checklist phases without compressing research.
- [x] Exact manual coverage replacement/addition text above now contains all validator-assigned real UIDs; B004 did not manually edit supervisor-owned coverage rows, and their application remains external state rather than pending implementation work in this artifact.
- [x] External supervisor/validator lifecycle is not asserted or tracked as pending implementation work by this artifact.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000010378","destination_path":"executed-b-agent-research/B004/00026R-TransferServerReadOnlyData-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00026R-TransferServerReadOnlyData-source-quality.md","timestamp":"2026-07-13T16:47:46-04:00","uid":"00026R"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
