*** UID:0003JB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00003T | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00003T | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DialogPane Vtables

## Status

- Entity kind: source-local vtable cluster.
- Covered class: [UID:00003T][DialogPane](by-class/DialogPane.md).
- Likely source file: [UID:0000IT][DialogPane](by-file/DialogPane.md).
- Exact memory page: [UID:0003AW][0x00618a60-0x00618afc.DialogPaneVtableData](by-memory/0x00618a60-0x00618afc.DialogPaneVtableData.md).
- Non-emitting aggregate source: [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md).
- Autogen parent: [UID:00003T][DialogPane](by-class/DialogPane.md), which clears `85/86`.
- Verification: A004 Batch 336 live IDA MCP against `b001_nexustk` on 2026-06-12.

## Vtable Bases

| Object offset | Vtable base | Preceding locator | Notes |
| --- | --- | --- | --- |
| `+0x00` | `0x00618a64` | `0x00618a60` | Primary `DialogPane` view; first slot is scalar deleting destructor `0x0048c350`. |
| `+0xa0` | `0x00618ac4` | `0x00618ac0` | Secondary handler view; first slot is adjustor thunk `0x0048c27b`. |
| `+0xa4` | `0x00618af4` | `0x00618af0` | Tertiary handler view; first slot is adjustor thunk `0x0048c286`. |

Offsets `0xa0` and `0xa4` are 160 and 164 respectively (Verified with `int_convert.py`).

## Evidence

- IDA MCP `entity_query` confirms decorated table names `??_7DialogPane@@6B@`, `??_7DialogPane@@6B@_0`, and `??_7DialogPane@@6B@_1` at `0x00618a64`, `0x00618ac4`, and `0x00618af4`; the next decorated base is `AlertPane` at `0x00618b00`.
- `lookup_funcs` reports constructor `0x0049d8a0-0x0049d9e8`, cleanup/destructor-family body containing `0x0049da10` at `0x0049d9f0-0x0049dacb`, scalar deleting destructor slot `0x0048c350-0x0048c38b`, and 11-byte adjustor thunks at `0x0048c27b` and `0x0048c286`.
- `xrefs_to` reports constructor stores at `0x0049d8e0`, `0x0049d8e6`, and `0x0049d8f0`, plus cleanup/destructor stores at `0x0049da17`, `0x0049da1d`, and `0x0049da27`.
- `get_int` reads final inherited tertiary slot `0x00544e90` at `0x00618af8`, neighboring `AlertPane` RTTI at `0x00618afc`, and `AlertPane` primary base at `0x00618b00`. The exact range is `0x9c` / 156 bytes (Verified with `int_convert.py`).
- The primary table's `+0x48` cell is at `0x00618aac` and points to `0x0041b6c0`, the two-argument `DialogPane::OnControlCommand(int controlIndex, int notifyCode)` contract inherited or overridden by feature dialogs. This slot is behaviorally distinct from hover selection.
- The primary table's `+0x58` cell is at `0x00618abc` and points to exact [UID:0004RI][0x0049fc00-0x0049fc4c.DialogPaneSetHoverControl](by-memory/0x0049fc00-0x0049fc4c.DialogPaneSetHoverControl.md). MacroDialog and IntegrateMacroDialog inherit that base cell; SpellMacroDialog and NewMacroDialog use forwarding overrides that preserve the one-int `SetHoverControl` contract. The exact body deactivates the prior child, activates the new child, and stores `m_activeControlId`; it performs no Event dispatch.
- `DialogPane::DispatchInputToControl(Event *, int)` is the separate modeled body at `0x0049fda0-0x0049fe12`. Its child-relative coordinate translation and restoration cannot be assigned to either primary `+0x48` or the exact `+0x58` hover helper.

## Complete Source Contract

- Primary inherited Pane span through `+0x2c` includes runtime class, change-message default, UpdateRenderRegion, the three-argument no-op extension hook, Show, Hide, exact `GetParentPane` at `+0x1c`, InvalidateRect, GetDescription, GetScreenBounds, and SetBounds.
- DialogPane primary extensions are:
  - `+0x30` OnCreate;
  - `+0x34` inherited Pane::InsertInLayer;
  - `+0x38` OnDestroy;
  - `+0x3c` OnShow;
  - `+0x40` OnHide;
  - `+0x44` OnPaint;
  - `+0x48` OnControlCommand;
  - `+0x4c` UpdateActionButton;
  - `+0x50` DrawBackground;
  - `+0x54` DrawBorder;
  - `+0x58` SetHoverControl.
- Secondary EventHandler view is destructor adjustor, HandlePointerOrMouseEvent, HandleKeyOrTextEvent, HandleImeEvent, inherited false HandlePacketEvent at `0x0041d6b0`, HandleSystemOrControlEvent, HandleType19Event, ForwardHandlerOrder, GetLocalEventPair, GetScreenEventPair, and ShouldAcceptEvent.
- Tertiary TimerHandler view is destructor adjustor plus inherited true `OnTimer(int,int,int)`.
- UID00003T now declares OnPaint, HandleImeEvent, DrawBackground, and DrawBorder explicitly while preserving all previously accepted methods and field layout. That declaration is sufficient to regenerate DialogPane and all DialogInSession inherited cells.

## Assignment Gate

This page is a single-owner `DialogPane` vtable declaration record at `90/94`. The direct class is now `92/94` and the source file remains `90/92`; the broader [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md) remains parentless because it spans five direct owners.

## Reconstruction Notes

Do not emit literal vtable bytes from this page. R18 remains intentionally blank. Reconstruct the source-level [UID:00003T][DialogPane](by-class/DialogPane.md) class declaration and virtual method set; exact UID0004RI supplies the one source body for `SetHoverControl`, while secondary and tertiary destructor entries are compiler adjustor thunks reused by derived dialog classes. The class declaration is the source mechanism that regenerates all three table views, COL/RTTI records, adjustors, and deleting-wrapper links; none may be handwritten as arrays or ABI wrapper code.

## Score Rationale

- Completion `90` reflects exact primary/secondary/tertiary bases and boundaries, constructor/destructor stores, explicit `+0x48`/`+0x58` method identities, exact UID0004RI route, derived inheritance/override matrix, and complete compiler-generation disposition.
- Confidence `94` reflects decorated table symbols, raw cell reads, exact method body/ABI/callers, constructor and cleanup store triads, and independent class/file support. The remaining gap to maximum is lexical source provenance rather than table or behavior uncertainty.

## Cross-References

- [UID:00003T][DialogPane](by-class/DialogPane.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:0003AW][0x00618a60-0x00618afc.DialogPaneVtableData](by-memory/0x00618a60-0x00618afc.DialogPaneVtableData.md)
- [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md)
- [UID:0004RI][0x0049fc00-0x0049fc4c.DialogPaneSetHoverControl](by-memory/0x0049fc00-0x0049fc4c.DialogPaneSetHoverControl.md)
- [UID:00010U][0x0048c27b-0x0048c290.DialogPaneAdjustorThunks](by-memory/0x0048c27b-0x0048c290.DialogPaneAdjustorThunks.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)

## Changes

- 2026-07-16 B004 UID0002NB accepted support synchronization:
  - Preserved `90/94`, owner/emitter UID00003T, reconstructable true, blank position/formal, exact bases, stores, COL boundaries, compiler adjustors, SetHoverControl child, coordinate-dispatch distinction, and all unrelated history.
  - Added the complete inherited/introduced primary slot map, exact secondary EventHandler order including the false packet default, tertiary OnTimer route, and the four newly explicit UID00003T source declarations.
  - No score, owner, emitter, or formal inflation was applied.
- 2026-07-15 B003 UID00049G implementation callback: raised `88/93` to `90/94`; retained owner/emitter UID00003T, true, blank position, and exact blank R18; recorded primary `+0x48` OnControlCommand and `+0x58` UID0004RI SetHoverControl cells, distinct `0x0049fda0` coordinate dispatch, derived family inheritance/override routes, and the declaration-caused compiler vtable/RTTI/no-raw-array disposition while preserving all existing bases, COL boundaries, adjustors, and history.

- 2026-06-12 A004 Batch 336:
  - Created this exact source-local vtable page from the previous mixed [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md) aggregate.
  - Evidence: live IDA MCP confirmed decorated bases, constructor and cleanup/destructor store triads, function sizes, adjustor-thunk sizes, raw dwords, and the corrected `AlertPane` successor boundary.
  - Gate: assigned to [UID:00003T][DialogPane](by-class/DialogPane.md) because the child and direct parent both clear the strict `85/85` gate.
- 2026-06-19 B011 source-quality sync:
  - Kept metadata `88/93` and owner/emitter [UID:00003T][DialogPane](by-class/DialogPane.md).
  - Summary/evidence: [UID:00003T][DialogPane](by-class/DialogPane.md) now carries declaration-only first-draft C++; this vtable page remains the non-emitting support record proving that the declaration/virtual method set should regenerate the three DialogPane table views and compiler adjustor entries rather than emitting literal vtable data or thunk bodies.
- 2026-06-22 B014 support sync: corrected the visible DialogPane adjustor thunk support range to `0x0048c27b-0x0048c291`; backing file rename remains a supervisor/coverage task.
