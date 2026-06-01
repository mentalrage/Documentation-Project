*** UID:00003U | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DialogSession

## Status

- Confidence: strong for core behavior; medium for final source-folder placement.
- Likely source file: [UID:0000IU][DialogSession](by-file/DialogSession.md)
- Address range: [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md)
- Current recovered file: `source-3/simroot_v2/class_DialogSession.cpp`
- Type docs: [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md)
- Vtables: [UID:0001XD][DialogSessionVtables](by-type/by-vtable/DialogSessionVtables.md), exact data [UID:0002NB][0x00618d30-0x00618e50.DialogSessionVtableData](by-memory/0x00618d30-0x00618e50.DialogSessionVtableData.md)

## Class Purpose

`DialogSession` is a full-screen `Pane`-derived session container for session-bound dialogs. It owns a list of tracked dialogs, keeps the active selection index at `+0xfc`, pushes new dialogs onto the stack, closes or removes active dialogs, and releases session renderer state during teardown.

See [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md) for the IDA-confirmed `+0xf8` tracked-list pointer and `+0xfc` active-index byte.

## Method Notes

| Method or range | Address | Role |
| --- | --- | --- |
| `DialogSession` | `0x004a0d80-0x004a0e6e` | Constructs the base `Pane`, creates the tracked dialog list, initializes active index to `0xff`, applies full-screen bounds, and attaches renderer state. |
| `~DialogSession` | `0x004a0e70-0x004a0f3c` | Releases tracked entries/list, shared session resource, pane state, and base object. |
| close all / teardown stack | `0x004a0f40-0x004a0fbc` | Closes active dialog if present, releases all tracked dialogs, frees the list, and invalidates pane/session state. |
| push dialog | `0x004a0fc0-0x004a10d1` | Removes dialogs above the active index, inserts a new dialog, applies bounds/parenting, and shows/activates it. |
| pop/close current dialog | `0x004a10e0-0x004a11dc` | Removes current dialog, optionally restores prior dialog state, and tears down the session when the stack becomes empty. |
| previous dialog lookup | `0x004a1250-0x004a12a2` | Finds a dialog in the tracked list and returns its previous entry when one exists. |
| screen dimmer factory dependency | [UID:000133][0x004a12b0-0x004a1360.CreateScreenDimmerFactory](by-memory/0x004a12b0-0x004a1360.CreateScreenDimmerFactory.md) | Shared `CreateScreenDimmer_4A12B0` helper used by session/dialog callers; source owner is [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md). |
| shared resource release | `0x004a1360-0x004a1371` | Releases `dword_69AE08` through its deleting destructor if present. |
| list entry accessor | `0x004a1390-0x004a13a7` | Returns a tracked dialog list entry by index. |
| destructor thunks | `0x004a1485`, `0x004a1490`, `0x004a1500` | Secondary/tertiary adjustor thunks and scalar deleting destructor. |

## Vtable Evidence

| View | Vtable | Key slots |
| --- | --- | --- |
| primary | `0x00618d30` | Scalar deleting destructor `0x004a1500` at `+0x00`; pane bounds/interaction slots at `+0x30` and `+0x3c`. |
| secondary | `0x00618d7c` | Adjustor thunk `0x004a1485` at `+0x00`, shared pane/event slots through `+0x28`. |
| tertiary | `0x00618dac` | Adjustor thunk `0x004a1490` at `+0x00`, base event slot `0x00544e90` at `+0x04`. |

The constructor stores these vtables at `0x004a0dc1`, `0x004a0dc7`, and `0x004a0dd1`. The non-deleting destructor and scalar deleting destructor reinstall the same three vtables before cleanup.

## Evidence Notes

- IDA MCP confirms all listed function starts.
- Active simroot output currently emits only the constructor, destructor, and scalar deleting destructor. It omits the stack/list helpers from `0x004a0f40-0x004a1390`.
- `xrefs_to 0x004a0d80` shows construction from the bulletin session constructor at `0x00471186`.
- `xrefs_to 0x004a0f40`, `0x004a0fc0`, `0x004a10e0`, and `0x004a1250` shows broad bulletin/session-family callers. `0x004a12b0` also has those callers, but it is a shared [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md) factory dependency rather than `DialogSession` implementation.
- Disabled generated output lists `0x004a1485` as missing code, but IDA confirms it is a real `0xb` thunk forwarding to `0x004a1500` with `this - 0xa0`.
- Current Wave3 metadata reports `vtable_count: 0` for `DialogSession` despite the IDA-confirmed constructor/destructor stores for all three vtables.

## Cross-References

- [UID:0000IU][DialogSession](by-file/DialogSession.md)
- [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md)
- [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md)
- [UID:0001XD][DialogSessionVtables](by-type/by-vtable/DialogSessionVtables.md)
- [UID:0002NB][0x00618d30-0x00618e50.DialogSessionVtableData](by-memory/0x00618d30-0x00618e50.DialogSessionVtableData.md)
- [UID:000134][0x004a146f-0x004a149b.DialogSessionAdjustorThunks](by-memory/0x004a146f-0x004a149b.DialogSessionAdjustorThunks.md)
- [UID:00003S][DialogInSession](by-class/DialogInSession.md)
- [UID:0000HX][BulletinSession](by-file/BulletinSession.md)
- [UID:0000A2][Pane](by-class/Pane.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `80/84`.
  - Summary/evidence: session container role, tracked-list layout, constructor/destructor/stack management helpers, vtable stores, screen-dimmer dependency split, caller evidence, and generated omission caveats are documented; remaining uncertainty is final source-folder placement and some helper names.
- 2026-05-31 reconstructability:
  - Before: `RECONSTRUCTABLE` was blank.
  - After: `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP reconfirms the session constructor/destructor/helper island and vtable stores as NexusTK-owned dialog infrastructure. Parent/code autogen remains blank because helper names and final source declarations are not fully audited.
