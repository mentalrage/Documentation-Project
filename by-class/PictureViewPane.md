*** UID:0000AH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;

class PictureViewPane : public Pane
{
public:
    PictureViewPane();
    virtual ~PictureViewPane();

    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PictureViewPane

## Status

- Confidence: very strong for class identity, exact method ranges, source-clean declaration, EventHandler virtual names, vtable slots, `Pane::MarkForDeletion` behavior, destructor/thunk split, and source placement.
- Likely source file: [UID:0000MK][PhotoPane](by-file/PhotoPane.md)
- Main address range: `0x00549a30-0x00549bc5`
- Parent attachment: [UID:0000MK][PhotoPane](by-file/PhotoPane.md) is the current `NexusTK/map/PhotoPane.cpp` route; this class is attached because live IDA confirms it is the viewer base used by the adjacent `PhotoPane` island.
- Emission order: position 10, before derived [UID:0000AG][PhotoPane](by-class/PhotoPane.md) at position 20; the class closes before `[[CHILDREN]]` so method definitions are emitted outside the declaration.

## Class Purpose

`PictureViewPane` is a full-screen picture/viewer pane base. It initializes itself against [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md), uses that pane's bounds and the main UI layer slots, and provides close/delete message handlers for derived picture panes such as [UID:0000AG][PhotoPane](by-class/PhotoPane.md).

## Method Families

| Range | Function | Role |
| --- | --- | --- |
| `0x00549a30-0x00549ad6` | [UID:0004RL][0x00549a30-0x00549ad6.PictureViewPaneConstructor](by-memory/0x00549a30-0x00549ad6.PictureViewPaneConstructor.md) | Human source initializes `Pane(0)`, fetches `g_activeMapPane` bounds, calls `SetPaneOrder(NULL, g_activeMapPane)`, and attaches through the main UI layer head; vptr stores are compiler lowering. |
| `0x00549ae0-0x00549aff` | [UID:0004RM][0x00549ae0-0x00549aff.PictureViewPaneDestructor](by-memory/0x00549ae0-0x00549aff.PictureViewPaneDestructor.md) | Empty out-of-line virtual source destructor; vptr resets and Pane teardown are compiler lowering. |
| `0x00549b00-0x00549b22` | [UID:0004RN][0x00549b00-0x00549b22.PictureViewPaneHandlePointerOrMouseEvent](by-memory/0x00549b00-0x00549b22.PictureViewPaneHandlePointerOrMouseEvent.md) | Handles `kEventLeftButtonUp` and `kEventRightButtonUp` through inherited `Pane::MarkForDeletion()` and always returns true. |
| `0x00549b30-0x00549b4d` | [UID:0004RO][0x00549b30-0x00549b4d.PictureViewPaneHandleKeyOrTextEvent](by-memory/0x00549b30-0x00549b4d.PictureViewPaneHandleKeyOrTextEvent.md) | Handles `kEventKeyDown` through inherited `Pane::MarkForDeletion()` and always returns true without reading key payload. |
| `0x00549b4d-0x00549b63` | [UID:0004RP][0x00549b4d-0x00549b63.PictureViewPaneDestructorAdjustorThunks](by-memory/0x00549b4d-0x00549b63.PictureViewPaneDestructorAdjustorThunks.md) | Secondary/tertiary vtable glue; compiler-generated `-0xa0`/`-0xa4` thunks to `0x00549b70`, no handwritten source. |
| `0x00549b70-0x00549bc5` | scalar deleting destructor | Reset vtables, destroy the base pane, and optionally delete. |

## Ownership Notes

Earlier non-authoritative handler labels name the close helper as `BulletinSession::MarkForDeletion`. B014 rejects that as generated-owner pollution: the helper at `0x00544690` is [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md)'s broad `Pane::MarkForDeletion`, reached by subtracting `0xa0` from the `PictureViewPane` secondary handler subobject to recover the complete pane object. The body does not inspect bulletin-specific article/session state.

`PictureViewPane` stays linked to [UID:0000AG][PhotoPane](by-class/PhotoPane.md) as its confirmed base. The constructor caller, destructor chain, contiguous island, and ordered class definitions support their shared [UID:0000MK][PhotoPane](by-file/PhotoPane.md) route.

2026-06-04 live IDA MCP recheck confirms `0x00549b00` handles message codes `3` and `6`, `0x00549b30` handles code `8`, and both paths dispatch only `Pane::MarkForDeletion(this - 160)`. IDA lookup/disassembly also confirms the adjacent `0x00549b4d` and `0x00549b58` starts are adjustor thunks that jump to the scalar deleting destructor.

## Evidence Notes

- Live IDA MCP reports the PictureView functions as `0x00549a30-0x00549ad6`, `0x00549b00-0x00549b22`, `0x00549b30-0x00549b4d`, `0x00549b4d-0x00549b58`, `0x00549b58-0x00549b63`, and scalar deleting destructor `0x00549b70-0x00549bc5`.
- The constructor is called by [UID:0000AG][PhotoPane](by-class/PhotoPane.md) at `0x0054965d`, installs PictureViewPane vtables `0x006220d0`, `0x0062211c`, and `0x0062214c`, reads [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md) / [UID:0001OW][0x0067a764-0x0067a768.ActiveMapPaneSingleton](by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md), and uses [UID:00029M][0x0069b364-0x0069b370.MainUiLayerSlotsHead](by-memory/0x0069b364-0x0069b370.MainUiLayerSlotsHead.md).
- Vtable data references place close handlers at slots `0x00622084`, `0x00622088`, `0x00622120`, and `0x00622124`; the secondary/tertiary destructor thunks are referenced at `0x0062211c` and `0x0062214c`.
- The scalar deleting destructor resets the same three PictureViewPane vtables, calls pane teardown `0x00544580`, and optionally frees storage through `0x004f4ac0`.
- The public virtual names are fixed by the current EventHandler contract as `HandlePointerOrMouseEvent(Event *)` and `HandleKeyOrTextEvent(Event *)`; historical `HandleClose...` and `On...` aliases are rejected. Method bodies remain on exact by-memory children rather than being duplicated in the class block.
- 2026-06-14 live IDA MCP session `a001_goal2_class_batch` reconfirmed constructor `0x00549a30` size `0xa6`, close handlers `0x00549b00` size `0x22` and `0x00549b30` size `0x1d`, destructor thunks `0x00549b4d`/`0x00549b58` size `0xb` each, and scalar deleting destructor `0x00549b70` size `0x55`.
- The constructor still has a single code xref from [UID:0000AG][PhotoPane](by-class/PhotoPane.md) construction at `0x0054965d`, which keeps `PictureViewPane` as the direct full-screen viewer base inside the [UID:0000MK][PhotoPane](by-file/PhotoPane.md) source module.
- Constructor decompilation calls the pane base initializer, writes vtable heads `0x006220d0`, `0x0062211c`, and `0x0062214c`, reads active view/root state through `g_activeMapPane`, and initializes the view attachment with `MainUiLayerSlotsHead` / `g_mainUiLayerSlotsHead`.
- Close-handler decompilation reconfirmed the first handler accepts message codes `3` and `6`, the second accepts code `8`, and both call only the adjusted `Pane::MarkForDeletion(this - 160)` helper path.
- Vtable xrefs to `0x006220d0`, `0x0062211c`, and `0x0062214c` are confined to constructor/destructor-family stores, supporting direct child attachment for [UID:0001F3][0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks](by-memory/0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks.md) once this class clears 85/85.

## Cross-References

- [UID:0000MK][PhotoPane](by-file/PhotoPane.md)
- [UID:0000AG][PhotoPane](by-class/PhotoPane.md)
- [UID:0001F2][0x00549620-0x00549bc5.PhotoAndPicturePanes](by-memory/0x00549620-0x00549bc5.PhotoAndPicturePanes.md)
- [UID:0001F3][0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks](by-memory/0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks.md)
- [UID:0004RL][0x00549a30-0x00549ad6.PictureViewPaneConstructor](by-memory/0x00549a30-0x00549ad6.PictureViewPaneConstructor.md)
- [UID:0004RM][0x00549ae0-0x00549aff.PictureViewPaneDestructor](by-memory/0x00549ae0-0x00549aff.PictureViewPaneDestructor.md)
- [UID:0004RN][0x00549b00-0x00549b22.PictureViewPaneHandlePointerOrMouseEvent](by-memory/0x00549b00-0x00549b22.PictureViewPaneHandlePointerOrMouseEvent.md)
- [UID:0004RO][0x00549b30-0x00549b4d.PictureViewPaneHandleKeyOrTextEvent](by-memory/0x00549b30-0x00549b4d.PictureViewPaneHandleKeyOrTextEvent.md)
- [UID:0004RP][0x00549b4d-0x00549b63.PictureViewPaneDestructorAdjustorThunks](by-memory/0x00549b4d-0x00549b63.PictureViewPaneDestructorAdjustorThunks.md)

## Changes

- Before: `PictureViewPane` and its scalar deleting destructor ended at `0x00549bc4`.
- Changed to: both end at `0x00549bc5`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows `0x00549bc4` is the final operand byte of the destructor's `retn 4`.
- Before: the constructor row used the inclusive-looking end `0x00549ad5`.
- Changed to: the constructor row now uses the exact IDA start-inclusive/end-exclusive range `0x00549a30-0x00549ad6`.
- Summary/evidence: 2026-06-01 IDA MCP function-boundary review reports `sub_549A30` as `0x00549a30-0x00549ad6`, followed by `0xcc` alignment through `0x00549ae0`.
- Before: completion/confidence metadata were `0/0` even though the page already documented constructor, close handlers, adjustor thunks, destructor, ownership caveat, and endpoint correction.
- Changed to: `COMPLETION:78` and `CONFIDENCE:76`.
- Evidence: full-screen viewer role, active/root pane bounds setup, message codes `3`, `6`, and `8`, generic deletion path, thunk/destructor ranges, and polluted `BulletinSession` owner label are documented; confidence remains medium-high because final owner names in message handlers are unresolved.
- 2026-06-04: raised from `78/76` to `82/84`, marked `RECONSTRUCTABLE:TRUE`, and attached to [UID:0000MK][PhotoPane](by-file/PhotoPane.md).
  - Summary/evidence: live IDA MCP confirms exact function boundaries, constructor caller from `PhotoPane`, PictureViewPane vtable installs and vtable slots, active-view/root globals, message-code tests, adjusted owner-close helper calls, destructor thunks, and scalar deleting destructor behavior; parent file [UID:0000MK][PhotoPane](by-file/PhotoPane.md) is already `86/80` with valid `NexusTK/map/` placement.
  - Remaining gaps at that point: final C++ remained blank because the owner-close helper name and containing-object type for the adjusted close path were not yet source-quality; the 2026-06-22 B014 entry supersedes that helper blocker.
- 2026-06-14: raised from `82/84` to `85/86` after live IDA MCP session `a001_goal2_class_batch` reconfirmed function sizes, the single constructor caller from `PhotoPane`, constructor vtable/root-view setup, close-handler event tests, destructor thunk routing, and the direct class-child route for [UID:0001F3][0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks](by-memory/0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks.md). Final C++ stayed blank at that time because the adjusted close helper declaration and containing-object type were not yet source-quality; B014 now resolves the helper identity and keeps only exact child emission/name policy as the active C++ reason.
- 2026-06-22 B014 Rule 26 source-quality incorporation:
  - Before: `COMPLETION:85`, `CONFIDENCE:86`, with generated `BulletinSession::MarkForDeletion`, `dword_67A764`, and `unk_69B364` labels still treated as unresolved source-quality issues.
  - After: `COMPLETION:86`, `CONFIDENCE:88`.
  - Summary/evidence: B014 reanalysis resolves the close helper to `Pane::MarkForDeletion`, rejects Bulletin ownership, names `g_activeMapPane` and `MainUiLayerSlotsHead`, preserves handler behavior for codes `3`/`6` and `8`, and keeps only final event-handler public names as medium-high confidence.
- 2026-07-15 B004 UID0001F3 source-graph closure:
  - Before: `86/88`, no formal declaration, unresolved handler aliases, and no exact constructor/destructor/handler children.
  - After: `92/94`, file emitter position 10, complete source-clean class declaration closed before `[[CHILDREN]]`, and exact children UID0004RL/UID0004RM/UID0004RN/UID0004RO.
  - UID0001F3 remains the non-emitting mixed target index and UID0004RP remains compiler-only. ABI complete-object adjustments, vptr stores, scalar-delete flags, and thunk bodies are retained as evidence but excluded from handwritten C++.
