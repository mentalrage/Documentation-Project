*** UID:0000AH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PictureViewPane

## Status

- Confidence: strong for class identity, function boundaries, vtable slots, close-handler behavior, destructor/thunk endpoints, and parent placement; medium for the final owner-close helper name and containing-object type.
- Likely source file: [UID:0000MK][PhotoPane](by-file/PhotoPane.md)
- Main address range: `0x00549a30-0x00549bc5`
- Parent attachment: [UID:0000MK][PhotoPane](by-file/PhotoPane.md) is `86/80` with projected path `NexusTK/map/`; this class is attached because live IDA confirms it is the viewer base used by the adjacent `PhotoPane` island.

## Class Purpose

`PictureViewPane` is a full-screen picture/viewer pane base. It initializes itself against the active view/root pane, uses that pane's bounds, and provides close/delete message handlers for derived picture panes such as [UID:0000AG][PhotoPane](by-class/PhotoPane.md).

## Method Families

| Range | Function | Role |
| --- | --- | --- |
| `0x00549a30-0x00549ad6` | constructor | Initialize `Pane`, install `PictureViewPane` vtables, fetch active view bounds, attach the sprite/view parent, and run create/show setup. |
| `0x00549b00-0x00549b22` | message handler | Handles event codes `3` and `6` by invoking an owner deletion helper through a `this - 0xa0` adjustment. |
| `0x00549b30-0x00549b4d` | message handler | Handles event code `8` through the same owner deletion path. |
| `0x00549b4d-0x00549b63` | adjustor thunks | Secondary vtable glue; compiler-generated thunks to `0x00549b70`. |
| `0x00549b70-0x00549bc5` | scalar deleting destructor | Reset vtables, destroy the base pane, and optionally delete. |

## Ownership Notes

Earlier non-authoritative handler labels name the close helper as `BulletinSession::MarkForDeletion`. Treat that as suspect. The behavior is a generic owner-close/delete path reached by subtracting `0xa0` from the `PictureViewPane` subobject, and the body does not inspect bulletin-specific article/session state.

`PictureViewPane` should stay linked to [UID:0000AG][PhotoPane](by-class/PhotoPane.md) until another derived viewer class is confirmed. The destructor chain and contiguous memory island make a shared or adjacent source file likely.

2026-06-04 live IDA MCP recheck confirms `0x00549b00` handles message codes `3` and `6`, `0x00549b30` handles code `8`, and both paths dispatch only `sub_544690(this - 160)`. IDA lookup/disassembly also confirms the adjacent `0x00549b4d` and `0x00549b58` starts are adjustor thunks that jump to the scalar deleting destructor.

## Evidence Notes

- Live IDA MCP reports the PictureView functions as `0x00549a30-0x00549ad6`, `0x00549b00-0x00549b22`, `0x00549b30-0x00549b4d`, `0x00549b4d-0x00549b58`, `0x00549b58-0x00549b63`, and scalar deleting destructor `0x00549b70-0x00549bc5`.
- The constructor is called by [UID:0000AG][PhotoPane](by-class/PhotoPane.md) at `0x0054965d`, installs PictureViewPane vtables `0x006220d0`, `0x0062211c`, and `0x0062214c`, reads the active view/root pane global `0x0067a764`, and uses root/sprite state `0x0069b364`.
- Vtable data references place close handlers at slots `0x00622084`, `0x00622088`, `0x00622120`, and `0x00622124`; the secondary/tertiary destructor thunks are referenced at `0x0062211c` and `0x0062214c`.
- The scalar deleting destructor resets the same three PictureViewPane vtables, calls pane teardown `0x00544580`, and optionally frees storage through `0x004f4ac0`.
- Remaining uncertainty is limited to the final source name of the owner-close helper and the exact containing-object type for the `this - 0xa0` adjustment, so final reconstruction C++ stays blank.

## Cross-References

- [UID:0000MK][PhotoPane](by-file/PhotoPane.md)
- [UID:0000AG][PhotoPane](by-class/PhotoPane.md)
- [UID:0001F2][0x00549620-0x00549bc5.PhotoAndPicturePanes](by-memory/0x00549620-0x00549bc5.PhotoAndPicturePanes.md)
- [UID:0001F3][0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks](by-memory/0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks.md)

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
  - Remaining gaps: final C++ remains blank because the owner-close helper name and containing-object type for the adjusted close path are not yet at the 95/95 threshold.
