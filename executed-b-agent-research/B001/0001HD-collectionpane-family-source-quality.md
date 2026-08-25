** TARGET-REPORT-UID:0001HD **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001-goal2-collectionpane-family-source-quality-0001HD-20260617

## Summary Recommendation

Primary target [UID:0001HD] `by-memory/0x0056e940-0x0056fe75.CollectionPane.md` should become a non-emitting split/index, not a reconstructable/emitting aggregate. The physical range spans two source classes (`CollectionPane` and `CollectionPane2`), an unmodeled ordinary `CollectionPane` destructor body, two unmodeled rectangle helpers, one raw `CollectionPane2` constructor, vtable-only virtual stubs, and internal padding. A single formal source body for the aggregate would be wrong.

Recommended metadata for [UID:0001HD]:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `82` | `88` |
| `CONFIDENCE` | `88` | `91` |
| `CANONICAL_OWNER` | `0000IC` | `0000IC` |
| `RECONSTRUCTABLE` | `TRUE` | `FALSE` |
| `EMITTER_UIDS` | `0000IC` | blank |
| C++ | blank | keep blank |

Keep [UID:0000IC] `CollectionPane.cpp` as the file owner for the family, with direct class routing through [UID:00002X] `CollectionPane` and [UID:00002Y] `CollectionPane2`. Do not fold `ScrollCollectionPane` into this file; current evidence still supports it as a generic scrollbar dependency under `ScrollCollectionPane` / possible `ScrollBar` ownership. Do not move `g_pCollectionData` to CollectionPane; it is a `UserPane`/local-player-state pointer with a collection typed view.

## Evidence Checked

- Read active B001 rules, `Supervisor.md`, `notes.md`, `by-structure.md`, and `inference_research.md`.
- Read target [UID:0001HD], file [UID:0000IC], classes [UID:00002X]/[UID:00002Y], exact children [UID:0001HE]-[UID:0001HJ], vtable children [UID:00038U]/[UID:00038V], scalar destructors [UID:00038Y]/[UID:00038Z], adjustor thunks [UID:00023Y], resource docs [UID:0001R8]/[UID:0003F1]/[UID:0003FA], `CollectionPlayerDataLayout`, `g_pCollectionData`, `g_pCollectionDialogPane`, `ScrollCollectionPane`, and `CollectionDialogPane`.
- Live IDA MCP session `b003_00018a_ime_comp_20260617` was healthy against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, imagebase `0x400000`, Hex-Rays ready.
- `lookup_funcs` confirmed modeled starts and sizes from `0x0056e940` through `0x0056fe80`.
- `get_bytes`/`insn_query` found previously undocumented raw code in supposed padding:
  - `0x0056e9f0-0x0056ea25`: ordinary `CollectionPane` destructor body, not an IDA function.
  - `0x0056fb60-0x0056fb7a`: raw invalid slot rectangle helper, not an IDA function.
  - `0x0056fb80-0x0056fbd3`: raw visible slot rectangle helper, not an IDA function.
- `find_bytes` found no raw pointer hits for `0x0056e9f0`, `0x0056fb60`, `0x0056fb80`, or `0x0056fd70`.
- `xrefs_to` confirmed vtable-only or direct caller routes:
  - `0x0056ea30` via vtable slot `0x00624628`.
  - `0x0056ec50` via vtable slot `0x006245ec`.
  - `0x0056edc0` via vtable slot `0x00624624`.
  - `0x0056f660` via vtable slot `0x00624638`.
  - `0x0056f670` via vtable slot `0x00624634`.
  - `0x0056f800` via vtable slot `0x00624640`.
  - `0x0056fad0` via vtable slot `0x00624610`.
  - `0x0056fb40` via vtable slot `0x00624618`.
  - `0x0056fdd0`, `0x0056fdc0`, `0x0056fe60`, `0x0056fe50`, and `0x0056fe70` via `CollectionPane2` vtable slots.
  - `0x0056f810` has callers from `0x0056ea30` and external packet/dialog route helper `0x005147a2`.
  - `0x0056fa90` is called by `ScrollCollectionPaneUpdatePositionFromCursor` at `0x005631e5`.
  - `0x0056fbe0` and `0x0056fc80` are called by the input handler.

## Exact Range And Split Recommendations

Use half-open ranges below. Several current prose rows use last-byte-style endpoints; supervisor should normalize them when creating exact children.

| Range | Owner | Recommended source-facing name/signature | Score |
| --- | --- | --- | --- |
| `0x0056e940-0x0056e9e2` | [UID:00002X] | `CollectionPane::CollectionPane()` | `87/90` |
| `0x0056e9f0-0x0056ea25` | [UID:00002X] | `CollectionPane::~CollectionPane()` ordinary/non-deleting body; raw no-function/no-direct-xref | `86/90` |
| `0x0056ea30-0x0056ec44` | [UID:00002X] | `CollectionPane::InitializeCollectionData(const uint8_t* packet)` or existing `Initialize` if class convention favors the short name | `87/90` |
| `0x0056ec50-0x0056ecd8` | [UID:00002X] | `CollectionPane::UpdateRenderRegion(const RectBounds& bounds)` / set-bounds override that places the scroll child | `86/90` |
| `0x0056ece0-0x0056edb1` | [UID:00002X] | `CollectionPane::UpdateScrollRange()` | `87/90` |
| `0x0056edc0-0x0056f655` | [UID:00002X] | `CollectionPane::OnPaint()` | `87/90` |
| `0x0056f660-0x0056f665` | [UID:00002X] | `CollectionPane` secondary false-return virtual; final inherited slot name unproven | `86/91` |
| `0x0056f670-0x0056f7f4` | [UID:00002X] | `CollectionPane::OnInputEvent(Event* event)` / `HandleInput`, secondary view at `this+0xa0` | `87/90` |
| `0x0056f800-0x0056f805` | [UID:0001HE] | keep class-owned false-return virtual; final slot name unproven | keep `88/92` |
| `0x0056f810-0x0056fa8a` | [UID:00002X] | `CollectionPane::LoadCollectionGroupRecords(CollectionGroupRecord* group)` | `87/90` |
| `0x0056fa90-0x0056fac8` | [UID:00002X] | `CollectionPane::OnScrollPositionChanged(...)` | `87/90` |
| `0x0056fad0-0x0056fb36` | [UID:00002X] | `CollectionPane::AttachToLayer(...)` | `86/90` |
| `0x0056fb40-0x0056fb56` | [UID:00002X] | `CollectionPane::DetachFromLayer()` | `86/90` |
| `0x0056fb60-0x0056fb7a` | [UID:00002X] | raw `CollectionPane::SetInvalidGroupSlotRect(uint16_t slot, RectBounds* out)` helper; first arg unused | `84/88` |
| `0x0056fb80-0x0056fbd3` | [UID:00002X] | raw `CollectionPane::GetVisibleGroupSlotRect(uint16_t visibleSlot, RectBounds* out)` | `85/89` |
| `0x0056fbe0-0x0056fc73` | [UID:00002X] | `CollectionPane::HitTestVisibleGroupSlot(int x, int y)` returns `0..4` or `-1` | `87/90` |
| `0x0056fc80-0x0056fd61` | [UID:0001HF] | `CollectionPane::OpenOrRequestGroupDetail(int groupIndex)` | raise/reroute to `87/90`, owner/emitter [UID:00002X] |
| `0x0056fd70-0x0056fda0` | [UID:0001HG] | `CollectionPane2::CollectionPane2()` raw constructor | keep/reraise `86/90`, owner [UID:00002Y] |
| `0x0056fda0-0x0056fdbf` | [UID:0001HH] | `CollectionPane2::~CollectionPane2()` ordinary/non-deleting body | reroute owner/emitter [UID:00002Y], `86/91` |
| `0x0056fdc0-0x0056fdcc` | [UID:0001HI] | compiler-emitted/source-declared forwarding thunk through class layout | keep `86/91`, no handwritten C++ |
| `0x0056fdd0-0x0056fe41` | [UID:00002Y] | `CollectionPane2::OnPaint()` / `DrawCollectionInventoryFrame` | `87/91` |
| `0x0056fe50-0x0056fe55` | [UID:00002Y] | `CollectionPane2` false-return virtual, slot `0x006246c4` | `86/91` |
| `0x0056fe60-0x0056fe65` | [UID:00002Y] | `CollectionPane2` false-return virtual, slot `0x006246c0` | `86/91` |
| `0x0056fe70-0x0056fe75` | [UID:0001HJ] | keep class-owned false-return virtual, slot `0x006246cc` | keep `86/91` |

## Heuristic / Inference Reanalysis And Validation

### Aggregate policy

Best conclusion: [UID:0001HD] should be a non-emitting split/index. It is not a source method, class, or data object; it is a physical executable island over two source classes plus raw/helper code. Keeping it reconstructable/emitting would let generated output create an artificial source unit for a mixed range and would hide exact child method ownership. Rejected alternative: keep current `RECONSTRUCTABLE:TRUE` aggregate under [UID:0000IC]. That preserves broad coverage but conflicts with by-structure mixed-aggregate rules and misses the newly found raw destructor/rectangle helpers.

### Constructor/destructor lifecycle

`CollectionPane::CollectionPane` is modeled at `0x0056e940-0x0056e9e2`, has one direct caller at `0x004b851f`, calls `PanelPane` constructor `0x00545090`, installs three `CollectionPane` vtable views, zeroes byte `+0x104`, allocates `0x110` bytes for `ScrollCollectionPane`, calls its constructor with orientation `0`, stores the result at `+0x108`, and enables it.

The raw `0x0056e9f0-0x0056ea25` block is a real ordinary destructor body, not padding. It restores the same three vtables, reads/deletes the child at `+0x108`, and tail-jumps to `PanelPane` cleanup. It has no direct xrefs or raw pointer hits, but its vtable constants match the constructor and scalar deleting destructor [UID:00038Z]. Best action is an exact child page as `CollectionPaneNonDeletingDestructor`, class-owned by [UID:00002X]. Rejected alternative: ignore as padding. The instructions clearly include vtable stores, child cleanup, and base tail jump.

`CollectionPane2::CollectionPane2` at `0x0056fd70-0x0056fda0` remains raw/no-function/no-direct-xref/no-pointer-hit, but the bytes are a complete constructor, and vtable store targets match [UID:00038V]. Keep it reconstructable class-owned, with explicit raw-start caveat. Do not infer strong runtime liveness beyond class/vtable emission until a real caller is found.

[UID:0001HH] is behaviorally and semantically `CollectionPane2::~CollectionPane2()`, so its metadata should be rerouted from file [UID:0000IC] to class [UID:00002Y]. The body restores three `CollectionPane2` vtables and jumps to `PanelPane` cleanup; the scalar deleting destructor [UID:00038Y] owns optional delete.

### Field and layout names

Best defensible `CollectionPane` fields:

| Offset | Recommended name | Evidence |
| --- | --- | --- |
| `+0xf8` | `groupCount` or `collectionGroupCount` | Constructor zeroes related byte, init copies packet group count and mirrors to player data `+0x1340c8`; paint/scroll use this count. |
| `+0xfc` | `collectionsTable` | Init loads `MetaMan` table `"Collections"` and stores pointer at `this[63]`. |
| `+0x100` | `groupNamesTable` | Init loads `MetaMan` table `"GroupNames"` and stores pointer at `this[64]`. |
| `+0x104` | `visibleStartIndex` / `scrollPosition` | Update range, wheel handling, and scroll callback update byte `+260`; open helper adds this value to visible slot. |
| `+0x105` | `visibleGroupCount` / `totalGroupCountSnapshot` | `UpdateScrollRange` copies collection group count to byte `+261`; used with `visibleStartIndex` to clamp. |
| `+0x108` | `scrollPane` | Constructor stores allocated `ScrollCollectionPane`; layout/attach/detach/input paths all dereference it. |

Best defensible `CollectionPlayerDataLayout` field names remain view names, not final global ownership:

| Offset | Recommended view name | Evidence |
| --- | --- | --- |
| `+0x1340c8` | `collectionGroupCount` | Written by init, read by scroll/paint/input. |
| `+0x1340c9` | `collectionMetadataLoaded` | Init guard/set byte. |
| `group + 0x3ec8` | `loadedFlag` | Detail opener gates request vs dialog on it. |
| `group + 0x3ec9` | `groupVolumeId` / `groupType` | Dialog and request path use as volume/type byte; `CLTVOL%d` confirms volume semantics. |
| `group + 0x3eca` | `totalEntries` | Paint/progress and detail controls. |
| `group + 0x3ecb` | `collectedEntries` | Paint/progress. |

Rejected alternative: name `dword_67A748` as a CollectionPane-owned global. `g_pCollectionData` docs and UserPane lifetime xrefs prove it is a broad player-state pointer with collection aliases.

### Resource and source placement

Best source placement remains `NexusTK/ui/panels/CollectionPane.cpp` for `CollectionPane` and `CollectionPane2`. `CollectionDialogPane.cpp` owns the detail dialog, singleton, dialog child controls, and `DLGCLT`/`CLTENTRY`/`CLTBAR` resource family. `CollectionPane.cpp` owns `CLTINV`, `CLTLIST`, `"Collections"`, `"GroupNames"`, the five-row list, the request/open helper, and `CollectionPane2`'s lightweight inventory frame.

Rejected alternatives:

- Put `CollectionPane2` in `SelfLookPane2` or look-pane files: contradicted by RTTI/vtable names, constructor/destructor stores, and `CLTINV` resource xrefs.
- Put `ScrollCollectionPane` under `CollectionPane.cpp`: constructor and callback evidence show CollectionPane uses it, but ScrollCollectionPane docs show generic scrollbar behavior and a separate `ui/core`/`ScrollBar` unresolved placement.
- Put `g_pCollectionDialogPane` under CollectionPane: singleton lifetime belongs to `CollectionDialogPane`; CollectionPane only checks it before opening.

### Input/event semantics

`0x0056f670` is a secondary-interface input method. IDA's `this` is the `+0xa0` subobject; complete-object fields are reached through `this - 0xa0`. Source-facing signature should normalize this as a `CollectionPane` virtual, not as a free function or primary-object method taking an already adjusted `this`.

Event semantics from EventMan docs:

- Type `1`: left-button down.
- Type `2`: left double-click / thresholded click.
- Type `3`: left-button release, not used by this handler for row open.
- Type `7`: mouse wheel.

CollectionPane handling:

- If player-state byte `dword_67A748 + 0x13eb1d` is set, returns `false` immediately.
- Type `7` checks the event point inside pane bounds, subtracts wheel delta at event `+0x14`, clamps through `ScrollCollectionPane`, updates `visibleStartIndex`, refreshes scroll range, and invalidates.
- Types `1` and `2` both can open/request a visible row depending on config byte `g_pConfig + 0x28de5a`: type `1` opens when the config byte is clear; type `2` opens when the config byte is set. This is best described as click-mode gating.
- It then forwards the adjusted event to the `ScrollCollectionPane` secondary input view after subtracting the child origin and restores event coordinates afterward.

Rejected alternative: model this as a primary `CollectionPane` method with no subobject adjustment. The body's repeated `this - 160` and scroll-child secondary call prove a multiple-inheritance/input-interface route.

### Rectangle helpers and hit testing

`0x0056fb60-0x0056fb7a` and `0x0056fb80-0x0056fbd3` are not padding. They are raw helper bodies with `push ebp` prologues, `retn 8`, and calls to `InitRectBounds` (`sub_4B7C50`).

Best names:

- `SetInvalidGroupSlotRect(uint16_t slot, RectBounds* out)`: writes `(-1,-1,-1,-1)` to `out`; ignores the first arg.
- `GetVisibleGroupSlotRect(uint16_t visibleSlot, RectBounds* out)`: for slots `0..4`, writes `RectBounds(6, 14 + 50*slot, 161, 62 + 50*slot)`; otherwise writes invalid `(-1,-1,-1,-1)`.
- `HitTestVisibleGroupSlot(int x, int y)`: loops over five of the same rectangles, uses point-in-rect `sub_4B7E80`, and returns slot index or `-1`.

The raw rectangle helpers currently have no xrefs and no pointer hits. That prevents a stronger liveness score, but they are exact source-shaped helpers and should not remain hidden inside a "padding" gap.

### Collection detail packet semantics

[UID:0001HF] should be class-owned by [UID:00002X] and renamed around `OpenOrRequestGroupDetail`. It is called from input at `0x0056f7a7` with `visibleSlot + visibleStartIndex`.

Behavior:

- Computes `groupIndex * 0x2604` into the `g_pCollectionData` view.
- If group `loadedFlag` at `+0x3ec8` is clear, sends a four-byte packet through `dword_67A7EC`.
- Packet byte evidence: opcode `0x27`, then bytes `0`, `1`, and `groupVolumeId`, with the second byte of the final variable buffer cleared before send. Best semantic name: `RequestCollectionGroupDetail`.
- If loaded and `g_pCollectionDialogPane` is null, allocates `0x270` bytes and constructs `CollectionDialogPane(result, 0, groupVolumeId)`.

Rejected alternative: route this helper to `CollectionDialogPane`. The helper opens the dialog, but all selection, group-index math, and request dispatch are from the summary `CollectionPane` interaction flow.

### CollectionPane2 virtual slots

`CollectionPane2` should stay in `CollectionPane.cpp` as a small companion class. Its raw constructor, ordinary destructor, scalar deleting destructor, vtables, render method, forwarding thunk, and false stubs all match `CollectionPane2` RTTI/vtable data.

Best source-facing names:

- `CollectionPane2::OnPaint()` for `0x0056fdd0-0x0056fe41`; "DrawCollectionInventoryFrame" is a useful descriptive alias. It draws `CLTINV.EPF` using shared `ITEMINV.PAL`/EPF lookup and blits through `dword_69B3E8` with `this + 0x44` bounds.
- `0x0056fdc0-0x0056fdcc` should remain represented as source-declared/generated-binary forwarding thunk through class layout. Do not hand-author C++ for this exact body.
- False stubs at `0x0056fe50`, `0x0056fe60`, and `0x0056fe70` are real vtable targets. Exact inherited slot names are still not defensible from current evidence; name them by slot or role until Pane/interface slots are audited.

Rejected alternative: make [UID:0001HI] non-reconstructable ignored compiler glue. It is compiler-emitted, but current project convention for this page is source-declared/generated-binary with class layout obligation; retaining `RECONSTRUCTABLE:TRUE` and blank C++ is acceptable as long as it is not emitted as handwritten logic.

## First-Draft C++ Recommendation

Do not populate formal C++ for [UID:0001HD]. It should become `RECONSTRUCTABLE:FALSE` with blank emitters, so it is not eligible for a first-draft C++ body.

Also do not populate formal C++ for the existing or proposed child pages in this pass. Several exact children clear the numeric gate, but final output would require coordinated declarations for the Pane input interface, inherited virtual slot names, `RectBounds`, `ScrollCollectionPane`, `CollectionPlayerDataLayout`, and packet/event helper names. The strongest source-facing action is to split and route exact pages first, then populate C++ on a later pass after class/layout declarations are stable.

If the supervisor accepts only one immediate C++ blocker reason, use this one: the primary target is a mixed physical island and the correct source representation is exact child methods plus class declarations, not aggregate C++.

## Support Docs To Update

- [UID:0001HD] target page: convert to non-emitting split/index; add `0x0056e9f0`, `0x0056fb60`, `0x0056fb80`; normalize half-open child endpoints; add explicit no-C++ policy.
- [UID:00002X] `CollectionPane`: add ordinary destructor body, raw rectangle helpers, vtable slot `0x00624638 -> 0x0056f660`, secondary input `this+0xa0` explanation, and field names above.
- [UID:00002Y] `CollectionPane2`: add exact child recommendations for `0x0056fdd0`, `0x0056fe50`, `0x0056fe60`; keep raw constructor liveness caveat; clarify false-slot names are not final.
- [UID:0000IC] file page: update contents to reflect target [UID:0001HD] as split/index and list missing exact method children.
- [UID:0001HF] metadata: reroute owner/emitter from [UID:0000IC] to [UID:00002X]; rename/descriptive name to `OpenOrRequestGroupDetail`.
- [UID:0001HH] metadata: reroute owner/emitter from [UID:0000IC] to [UID:00002Y].
- [UID:0003F1]/[UID:0001R8] resource docs: no required score change; optionally add that `CollectionPane2::OnPaint` also uses `CLTINV.EPF`.
- [UID:0001TZ] `CollectionPlayerDataLayout`: no required route change; optionally add `CollectionPane` field-name consumer notes for `visibleStartIndex` and `groupCount`.

## Exact Supervisor-Owned Coverage Rows

Placement: replace the current [UID:0001HD] row and its existing immediate child rows [UID:0001HE]-[UID:0001HJ] in `by-memory/-coverage-report.md`, between the `0x0056e939-0x0056e940` padding row and [UID:0001HK] `SelfLookPane2`. Keep/create UIDs for existing pages as shown; new child UIDs are `UID:TBD` for supervisor assignment.

```text
    - [UID:0001HD][0x0056e940-0x0056fe75.CollectionPane](by-memory/0x0056e940-0x0056fe75.CollectionPane.md) 0x0056e940-0x0056fe75 | split index | CollectionPane and CollectionPane2 executable family index : non-reconstructable : 88% : strong : B001 2026-06-17 source-quality reanalysis recommends this broad range become a non-emitting split/index over exact CollectionPane and CollectionPane2 method children; live IDA confirms modeled starts/sizes, raw non-deleting CollectionPane destructor at 0x0056e9f0, raw slot-rectangle helpers at 0x0056fb60 and 0x0056fb80, raw CollectionPane2 constructor at 0x0056fd70, vtable-only stubs, resource routes, internal padding, and successor SelfLookPane2 boundary. Formal C++ remains blank because the aggregate is not a source body.
    - [UID:TBD][0x0056e940-0x0056e9e2.CollectionPaneConstructor](by-memory/0x0056e940-0x0056e9e2.CollectionPaneConstructor.md) 0x0056e940-0x0056e9e2 | constructor | CollectionPane constructor : reconstructable : 87% : strong : Constructor called from GeneralPurposePanel, calls PanelPane constructor, installs three CollectionPane vtable views, creates/enables ScrollCollectionPane at +0x108, and initializes visible-start state.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056e9e2-0x0056e9f0 | padding | CollectionPane constructor to non-deleting destructor alignment : ignored : 100% : strong : IDA confirms 0xcc alignment bytes before raw destructor body.
    - [UID:TBD][0x0056e9f0-0x0056ea25.CollectionPaneNonDeletingDestructor](by-memory/0x0056e9f0-0x0056ea25.CollectionPaneNonDeletingDestructor.md) 0x0056e9f0-0x0056ea25 | raw destructor body | CollectionPane non-deleting destructor : reconstructable : 86% : strong : Raw no-function/no-direct-xref destructor body restores CollectionPane vtables, releases the ScrollCollectionPane child at +0x108, and tail-jumps to PanelPane cleanup; pointer search found no raw address refs.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056ea25-0x0056ea30 | padding | CollectionPane non-deleting destructor to InitializeCollectionData alignment : ignored : 100% : strong : IDA confirms 0xcc alignment bytes.
    - [UID:TBD][0x0056ea30-0x0056ec44.CollectionPaneInitializeCollectionData](by-memory/0x0056ea30-0x0056ec44.CollectionPaneInitializeCollectionData.md) 0x0056ea30-0x0056ec44 | method | CollectionPane initialize collection data : reconstructable : 87% : strong : Loads Collections and GroupNames MetaMan tables, parses collection group packet bytes, writes group count/load flags into the UserPane collection data view, calls LoadCollectionGroupRecords, updates scroll range, and invalidates.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056ec44-0x0056ec50 | padding | InitializeCollectionData to UpdateRenderRegion alignment : ignored : 100% : strong : IDA confirms 0xcc alignment bytes.
    - [UID:TBD][0x0056ec50-0x0056ecd8.CollectionPaneUpdateRenderRegion](by-memory/0x0056ec50-0x0056ecd8.CollectionPaneUpdateRenderRegion.md) 0x0056ec50-0x0056ecd8 | method | CollectionPane update render region and scroll child bounds : reconstructable : 86% : strong : Vtable slot method computes the scroll child rectangle from the pane bounds, calls the scroll child layout slot, chains to base bounds handling, and refreshes scroll range.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056ecd8-0x0056ece0 | padding | UpdateRenderRegion to UpdateScrollRange alignment : ignored : 100% : strong : IDA confirms 0xcc alignment bytes.
    - [UID:TBD][0x0056ece0-0x0056edb1.CollectionPaneUpdateScrollRange](by-memory/0x0056ece0-0x0056edb1.CollectionPaneUpdateScrollRange.md) 0x0056ece0-0x0056edb1 | method | CollectionPane update scroll range : reconstructable : 87% : strong : Synchronizes group count/visible-start fields, clamps current scroll position, updates ScrollCollectionPane max/current values, and is called by initialization, layout, input, scroll callback, and attach.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056edb1-0x0056edc0 | padding | UpdateScrollRange to OnPaint alignment : ignored : 100% : strong : IDA confirms 0xcc alignment bytes.
    - [UID:TBD][0x0056edc0-0x0056f655.CollectionPaneOnPaint](by-memory/0x0056edc0-0x0056f655.CollectionPaneOnPaint.md) 0x0056edc0-0x0056f655 | method | CollectionPane OnPaint : reconstructable : 87% : strong : Draws CLTINV/CLTLIST resources, formats group names/progress, reads group type/total/collected bytes from the collection data view, and uses CollectionPane-local packed rectangle constants.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056f655-0x0056f660 | padding | OnPaint to CollectionPane false stub alignment : ignored : 100% : strong : IDA confirms 0xcc alignment bytes.
    - [UID:TBD][0x0056f660-0x0056f665.CollectionPaneFalseStubA](by-memory/0x0056f660-0x0056f665.CollectionPaneFalseStubA.md) 0x0056f660-0x0056f665 | virtual stub | CollectionPane false-return virtual slot 0x00624638 : reconstructable : 86% : strong : Five-byte vtable-only false-return body, no callers/callees/state, adjacent padding confirmed; final inherited slot name remains unproven.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056f665-0x0056f670 | padding | CollectionPane false stub to OnInputEvent alignment : ignored : 100% : strong : IDA confirms 0xcc alignment bytes.
    - [UID:TBD][0x0056f670-0x0056f7f4.CollectionPaneOnInputEvent](by-memory/0x0056f670-0x0056f7f4.CollectionPaneOnInputEvent.md) 0x0056f670-0x0056f7f4 | method | CollectionPane secondary input event handler : reconstructable : 87% : strong : Vtable-only secondary input handler normalizes this-0xa0, handles event types 1/2 through click-mode row open/request logic, handles event type 7 wheel scrolling, forwards adjusted event coordinates to ScrollCollectionPane, and returns the child handler result.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056f7f4-0x0056f800 | padding | OnInputEvent to CollectionPaneFalseStub alignment : ignored : 100% : strong : IDA confirms 0xcc alignment bytes.
    - [UID:0001HE][0x0056f800-0x0056f805.CollectionPaneFalseStub](by-memory/0x0056f800-0x0056f805.CollectionPaneFalseStub.md) 0x0056f800-0x0056f805 | virtual stub | CollectionPane false-return virtual slot 0x00624640 : reconstructable : 88% : strong : Exact class-owned five-byte false-return vtable target, no callers/callees/state, adjacent padding confirmed; final inherited virtual name remains unproven.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056f805-0x0056f810 | padding | CollectionPaneFalseStub to LoadCollectionGroupRecords alignment : ignored : 100% : strong : IDA confirms 0xcc alignment bytes.
    - [UID:TBD][0x0056f810-0x0056fa8a.CollectionPaneLoadCollectionGroupRecords](by-memory/0x0056f810-0x0056fa8a.CollectionPaneLoadCollectionGroupRecords.md) 0x0056f810-0x0056fa8a | helper method | CollectionPane load collection group records : reconstructable : 87% : strong : Copies MetaMan collection row data into the collection group record layout, uses 0x4c entry stride and SimpleUString fields, and is called both by CollectionPane initialization and external packet/dialog route helper 0x005147a2.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056fa8a-0x0056fa90 | padding | LoadCollectionGroupRecords to OnScrollPositionChanged alignment : ignored : 100% : strong : IDA confirms 0xcc alignment bytes.
    - [UID:TBD][0x0056fa90-0x0056fac8.CollectionPaneOnScrollPositionChanged](by-memory/0x0056fa90-0x0056fac8.CollectionPaneOnScrollPositionChanged.md) 0x0056fa90-0x0056fac8 | callback method | CollectionPane scroll-position callback : reconstructable : 87% : strong : Called by ScrollCollectionPaneUpdatePositionFromCursor, updates visibleStartIndex when changed, synchronizes ScrollCollectionPane position, refreshes scroll range, and invalidates the pane.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056fac8-0x0056fad0 | padding | OnScrollPositionChanged to AttachToLayer alignment : ignored : 100% : strong : IDA confirms 0xcc alignment bytes.
    - [UID:TBD][0x0056fad0-0x0056fb36.CollectionPaneAttachToLayer](by-memory/0x0056fad0-0x0056fb36.CollectionPaneAttachToLayer.md) 0x0056fad0-0x0056fb36 | method | CollectionPane attach to layer : reconstructable : 86% : strong : Vtable slot attaches base pane, obtains scroll child bounds, attaches ScrollCollectionPane child with owner/callback context, and refreshes scroll range.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056fb36-0x0056fb40 | padding | AttachToLayer to DetachFromLayer alignment : ignored : 100% : strong : IDA confirms 0xcc alignment bytes.
    - [UID:TBD][0x0056fb40-0x0056fb56.CollectionPaneDetachFromLayer](by-memory/0x0056fb40-0x0056fb56.CollectionPaneDetachFromLayer.md) 0x0056fb40-0x0056fb56 | method | CollectionPane detach from layer : reconstructable : 86% : strong : Vtable slot detaches ScrollCollectionPane child through its detach slot and tail-jumps to base pane detach.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056fb56-0x0056fb60 | padding | DetachFromLayer to raw invalid slot rectangle helper alignment : ignored : 100% : strong : IDA confirms 0xcc alignment bytes.
    - [UID:TBD][0x0056fb60-0x0056fb7a.CollectionPaneSetInvalidGroupSlotRectRaw](by-memory/0x0056fb60-0x0056fb7a.CollectionPaneSetInvalidGroupSlotRectRaw.md) 0x0056fb60-0x0056fb7a | raw helper method | CollectionPane invalid group slot rectangle helper : reconstructable : 84% : strong : Raw no-function/no-xref helper writes RectBounds(-1,-1,-1,-1) through InitRectBounds and returns with retn 8; first argument is unused; pointer search found no raw address refs.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056fb7a-0x0056fb80 | padding | InvalidGroupSlotRectRaw to GetVisibleGroupSlotRectRaw alignment : ignored : 100% : strong : IDA confirms 0xcc alignment bytes.
    - [UID:TBD][0x0056fb80-0x0056fbd3.CollectionPaneGetVisibleGroupSlotRectRaw](by-memory/0x0056fb80-0x0056fbd3.CollectionPaneGetVisibleGroupSlotRectRaw.md) 0x0056fb80-0x0056fbd3 | raw helper method | CollectionPane visible group slot rectangle helper : reconstructable : 85% : strong : Raw no-function/no-xref helper maps visible slots 0..4 to RectBounds(6, 14+50*slot, 161, 62+50*slot), otherwise writes invalid bounds; pointer search found no raw address refs.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056fbd3-0x0056fbe0 | padding | GetVisibleGroupSlotRectRaw to HitTestVisibleGroupSlot alignment : ignored : 100% : strong : IDA confirms 0xcc alignment bytes.
    - [UID:TBD][0x0056fbe0-0x0056fc73.CollectionPaneHitTestVisibleGroupSlot](by-memory/0x0056fbe0-0x0056fc73.CollectionPaneHitTestVisibleGroupSlot.md) 0x0056fbe0-0x0056fc73 | helper method | CollectionPane visible group slot hit-test : reconstructable : 87% : strong : Called by OnInputEvent, loops over the five row rectangles, uses InitRectBounds and point-in-rect, returns visible slot 0..4 or -1.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056fc73-0x0056fc80 | padding | HitTestVisibleGroupSlot to OpenOrRequestGroupDetail alignment : ignored : 100% : strong : IDA confirms 0xcc alignment bytes.
    - [UID:0001HF][0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail](by-memory/0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail.md) 0x0056fc80-0x0056fd61 | helper method | CollectionPane open or request group detail : reconstructable : 87% : strong : Reroute owner/emitter to CollectionPane class; called by OnInputEvent, checks loaded flag at collection group +0x3ec8, sends opcode 0x27 four-byte request when absent, or allocates/constructs CollectionDialogPane when data is loaded and singleton is clear.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056fd61-0x0056fd70 | padding | OpenOrRequestGroupDetail to CollectionPane2RawConstructor alignment : ignored : 100% : strong : IDA confirms 0xcc alignment bytes.
    - [UID:0001HG][0x0056fd70-0x0056fda0.CollectionPane2RawConstructor](by-memory/0x0056fd70-0x0056fda0.CollectionPane2RawConstructor.md) 0x0056fd70-0x0056fda0 | raw constructor bytes | CollectionPane2 raw constructor : reconstructable : 86% : strong : Still no IDA function object, no direct xrefs, and no raw pointer hits, but bytes show PanelPane base construction, three CollectionPane2 vtable stores, eax=this, and normal return.
    - [UID:0001HH][0x0056fda0-0x0056fdbf.CollectionPane2Destructor](by-memory/0x0056fda0-0x0056fdbf.CollectionPane2Destructor.md) 0x0056fda0-0x0056fdbf | destructor | CollectionPane2 non-deleting destructor : reconstructable : 86% : strong : Reroute owner/emitter to CollectionPane2 class; restores three CollectionPane2 vtable views and tail-jumps to PanelPane cleanup.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056fdbf-0x0056fdc0 | padding | CollectionPane2Destructor to CollectionPane2ForwardingThunk alignment : ignored : 100% : strong : IDA confirms single 0xcc alignment byte.
    - [UID:0001HI][0x0056fdc0-0x0056fdcc.CollectionPane2ForwardingThunk](by-memory/0x0056fdc0-0x0056fdcc.CollectionPane2ForwardingThunk.md) 0x0056fdc0-0x0056fdcc | forwarding thunk | CollectionPane2 source-declared/generated forwarding thunk : reconstructable : 86% : strong : Vtable-only thunk at slot 0x006246b4 dispatches through primary vtable +0x20 with this+0x44; keep C++ blank and regenerate through class layout.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056fdcc-0x0056fdd0 | padding | CollectionPane2ForwardingThunk to CollectionPane2OnPaint alignment : ignored : 100% : strong : IDA confirms 0xcc alignment bytes.
    - [UID:TBD][0x0056fdd0-0x0056fe41.CollectionPane2OnPaint](by-memory/0x0056fdd0-0x0056fe41.CollectionPane2OnPaint.md) 0x0056fdd0-0x0056fe41 | method | CollectionPane2 OnPaint / draw collection inventory frame : reconstructable : 87% : strong : Vtable-only render method draws CLTINV.EPF using shared ITEMINV.PAL/EPF resource lookup and blits through render callback with this+0x44 bounds.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056fe41-0x0056fe50 | padding | CollectionPane2OnPaint to CollectionPane2 false slot 0x006246c4 alignment : ignored : 100% : strong : IDA confirms 0xcc alignment bytes.
    - [UID:TBD][0x0056fe50-0x0056fe55.CollectionPane2FalseStubC4](by-memory/0x0056fe50-0x0056fe55.CollectionPane2FalseStubC4.md) 0x0056fe50-0x0056fe55 | virtual stub | CollectionPane2 false-return virtual slot 0x006246c4 : reconstructable : 86% : strong : Five-byte vtable-only false-return body, no callers/callees/state; final inherited slot name remains unproven.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056fe55-0x0056fe60 | padding | CollectionPane2 false slot 0x006246c4 to false slot 0x006246c0 alignment : ignored : 100% : strong : IDA confirms 0xcc alignment bytes.
    - [UID:TBD][0x0056fe60-0x0056fe65.CollectionPane2FalseStubC0](by-memory/0x0056fe60-0x0056fe65.CollectionPane2FalseStubC0.md) 0x0056fe60-0x0056fe65 | virtual stub | CollectionPane2 false-return virtual slot 0x006246c0 : reconstructable : 86% : strong : Five-byte vtable-only false-return body, no callers/callees/state; final inherited slot name remains unproven.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056fe65-0x0056fe70 | padding | CollectionPane2 false slot 0x006246c0 to false slot 0x006246cc alignment : ignored : 100% : strong : IDA confirms 0xcc alignment bytes.
    - [UID:0001HJ][0x0056fe70-0x0056fe75.CollectionPane2FalseStub](by-memory/0x0056fe70-0x0056fe75.CollectionPane2FalseStub.md) 0x0056fe70-0x0056fe75 | virtual stub | CollectionPane2 false-return virtual slot 0x006246cc : reconstructable : 86% : strong : Existing class-owned five-byte false-return vtable target, no callers/callees/state, adjacent padding and successor boundary confirmed.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056fe75-0x0056fe80 | padding | CollectionPane to SelfLookPane2 alignment : ignored : 100% : strong : IDA confirms 0xcc alignment bytes.
```

## Validation Commands

I did not run validator on by-* docs because this was report-only and I did not edit by-* files. Recommended supervisor validation after applying documentation/coverage changes:

> Executable block R001 was removed from this report and preserved verbatim in [0001HD-collectionpane-family-source-quality-removed.md](0001HD-collectionpane-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

For each new child page the supervisor creates, run:

> Executable block R002 was removed from this report and preserved verbatim in [0001HD-collectionpane-family-source-quality-removed.md](0001HD-collectionpane-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Live IDA checks used/recommended:

```text
server_health(database=b003_00018a_ime_comp_20260617)
lookup_funcs(0x0056e940,0x0056e9f0,0x0056ea30,0x0056fb60,0x0056fb80,0x0056fd70,0x0056fe80)
insn_query(start=0x0056e9e0,end=0x0056ea30,include_disasm=true)
insn_query(start=0x0056fb50,end=0x0056fbe0,include_disasm=true)
xrefs_to(0x0056e9f0,0x0056fb60,0x0056fb80,0x0056fd70,0x0056f670,0x0056fc80,0x0056fdd0)
find_bytes(F0 E9 56 00,60 FB 56 00,80 FB 56 00,70 FD 56 00)
```

## Remaining Blockers And Impact

- Final inherited virtual slot names for `0x0056f660`, `0x0056f800`, `0x0056fe50`, `0x0056fe60`, and `0x0056fe70` are not defensible from current evidence alone. Impact: keep C++ blank for those exact pages and name by vtable slot/descriptive false-return role.
- `CollectionPane2` raw constructor and raw `CollectionPane` rectangle helpers have no direct xrefs and no raw pointer hits. Impact: keep scores below final-audit range and explicitly document raw/no-direct-xref liveness.
- Exact source type names for `Event`, `RectBounds`, `CollectionGroupRecord`, `ScrollCollectionPane`, `MetaTable`, and packet sender helpers remain coordinated project-wide names. Impact: do not populate formal C++ yet.
- `ITEMINV.EPD` package provenance remains unresolved in the resource docs, but this does not block the `CollectionPane` split decision because `CollectionPane2::OnPaint` uses the code-facing `ITEMINV.PAL`/`CLTINV.EPF` route already documented.

## Changed Files And Leases

- Changed files: this report only, `tools/leaser/Agents/Agent-B001/research/0001HD-collectionpane-family-source-quality.md`.
- No by-* docs, generated reports, source files, IDA DB, generated source, or `by-memory/-coverage-report.md` were edited.
- No lease was used; B001 rules allow report creation in the agent research folder without a by-* lease.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001HD-collectionpane-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001HD"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001HD-collectionpane-family-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001HD-collectionpane-family-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001HD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
