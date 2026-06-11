*** UID:00006I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000K5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# IMEStatusPane

## Status

- Likely source file: [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- Address range: [UID:000189][0x004e70f0-0x004e8433.IMEPaneFamily](by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md), with destructor wrappers in [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md)
- Current recovered file: `source-3/simroot_v2/class_IMEStatusPane.cpp`
- Confidence: very strong for the status-pane role, method boundaries, vtable evidence, and pane-family source ownership.

## Class Purpose

`IMEStatusPane` is the small ENG/IME mode label. It measures and positions status text near the lower-right screen edge, updates text on IME mode-change events, and paints a compact framed status indicator.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SetText` | `0x004e70f0-0x004e71bc` | Clamps/copies status text, measures width, positions near screen edge, and invalidates. |
| `IMEStatusPane` | `0x004e71c0-0x004e728a` | Constructs base pane, clears text buffer, initializes text as `Closed`, attaches hidden to root pane. |
| `~IMEStatusPane` | `0x004e7290-0x004e72af` | Resets vtables and destroys base pane. |
| `OnIMEModeChange` | `0x004e72b0-0x004e72f8` | Handles IME mode event type `11` and switches text between `IME` and `ENG`. |
| `OnPaintFrame` | `0x004e7300-0x004e737b` | Paints background, outline, and current status text. |
| `ScalarDeletingDestructor` | [UID:00031L][0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor](by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md) | Deleting destructor wrapper. |

## Evidence Notes

- IDA MCP confirms all listed starts and sizes.
- IDA xrefs to `SetText` come from the constructor and mode-change handler.
- `class_IMEStatusPane.cpp.disabled` emits one adjustor thunk body but omits sibling thunk `0x004e8629`; IDA confirms both are real thunks.
- 2026-05-26 IDA MCP recheck records the omitted `0x004e8629` sibling in [UID:00018D][0x004e85dc-0x004e8634.IMEAdjustorThunks](by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md); treat it as compiler-generated layout evidence, not a handwritten method.
- 2026-06-07 Batch 090 live IDA MCP on `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` reconfirmed the status-pane method boundaries: `SetText` `0x004e70f0-0x004e71bc`, constructor `0x004e71c0-0x004e728a`, ordinary destructor `0x004e7290-0x004e72af`, mode-change handler `0x004e72b0-0x004e72f8`, paint handler `0x004e7300-0x004e737b`, and scalar deleting destructor `0x004e8800-0x004e8855`, with `0xcc` alignment after each body.
- The constructor, ordinary destructor, and scalar deleting destructor reference the three `IMEStatusPane` vtable views at `0x0061c364`, `0x0061c3b0`, and `0x0061c3e0`; `OnIMEModeChange` and `OnPaintFrame` are vtable-referenced from that same table family.
- `SetText` has exactly two direct code callers in this class (`0x004e7249` from the constructor and `0x004e72ec` from the mode-change handler), supporting a compact status-label helper rather than a shared text utility.
- The scalar deleting destructor is reached from adjustor thunks at `0x004e861e` and `0x004e8629` and from the vtable, matching the existing destructor-island evidence.
- Direct parent assignment is justified to [UID:0000K5][IMEPanes](by-file/IMEPanes.md): this child is `86/89`, and the direct file parent has been refreshed to `89/86` with matching IME pane-family, vtable, destructor-island, singleton, and InputMan-boundary evidence.
- 2026-06-08 A001 Batch131 split [UID:00031L][0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor](by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md) as the exact scalar deleting destructor reached by the two status-pane adjustor thunks. That child is `85/89`, and this class now clears `86/89`.

## Cross-References

- [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- [UID:000189][0x004e70f0-0x004e8433.IMEPaneFamily](by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md)
- [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md)
- [UID:00018D][0x004e85dc-0x004e8634.IMEAdjustorThunks](by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md)
- [UID:00031L][0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor](by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md)

## Changes

- 2026-06-08 A001 Batch131 scalar-destructor split:
  - Before: score was `85/88`.
  - Changed to: score `86/89`.
  - Summary/evidence: exact child page [UID:00031L][0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor](by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md) now documents the scalar deleting destructor with live IDA adjustor-caller and callee evidence, strengthening the class-level lifecycle inventory.
- Completion/confidence score update: existed before as `0/0`; changed to `78/86`. Summary: IME status label purpose, text update/paint lifecycle, constructor/destructor, mode-change handling, and adjustor-thunk caveat are documented with strong confidence; remaining work is detailed field naming and final C++ reconstruction. Evidence: `IMEPaneFamily`, `IMECandidateQueueAndDestructors`, and `IMEAdjustorThunks` cross-references plus IDA-confirmed method starts.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the IME status label pane unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE`; left `AUTOGEN_PARENT_UID` blank because the class score is `78/86`, below the 80 completion attachment gate.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x004e70f0`, `0x004e71c0`, `0x004e7290`, `0x004e72b0`, `0x004e7300`, and `0x004e8800`, with `SetText` callers from the constructor and mode-change handler.
- 2026-06-07 Batch 090 parent-gate refresh:
  - Before: scores were `78/86`, and `AUTOGEN_PARENT_UID` was blank.
  - Changed to: scores `85/88` and `AUTOGEN_PARENT_UID:0000K5`.
  - Summary/evidence: live IDA MCP reconfirmed method bounds, `SetText` caller closure, vtable refs at `0x0061c364`/`0x0061c3b0`/`0x0061c3e0`, scalar-destructor thunk refs, and the direct [UID:0000K5][IMEPanes](by-file/IMEPanes.md) parent. Final C++ stays blank because detailed field/message-structure names and exact source declarations remain below the 95/95 final-code gate.
