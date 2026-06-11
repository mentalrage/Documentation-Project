*** UID:000081 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MenuVarietyPane

## Status

- Confidence: strong for class role and boundaries.
- Likely source file: [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)
- Main address range: [UID:0001NP][0x005bc610-0x005bfd98.MenuVarietyPanes](by-memory/0x005bc610-0x005bfd98.MenuVarietyPanes.md)
- Current recovered file: `source-3/simroot_v2/class_MenuVarietyPane.cpp`
- Shared destructor/thunk tail: [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)

## Class Purpose

`MenuVarietyPane` is the in-game menu button pane. It draws `MENUVAR.EPF`, opens or refreshes `MenuVarietySelectPane`, and pulses its owner when the selector state changes.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x005bc610-0x005bc65f` | `MenuVarietyPane::MenuVarietyPane()` | Constructs the dialog/pane state and sets `g_pMenuVarietyPane`. |
| `0x005bc660-0x005bc688` | cleanup body | Reinstalls vtables, clears [UID:0000RI][g_pMenuVarietyPane](by-global/g_pMenuVarietyPane.md), and runs pane base cleanup. |
| `0x005bc690-0x005bc7f9` | `HandleClick(int inputEvent)` | Opens or refreshes the selector pane when the menu button is clicked. |
| `0x005bc800-0x005bc874` | `DrawMenuArtwork()` | Draws `MENUVAR.EPF` using selected/open frame. |
| `0x005bc880-0x005bc88a` | Tiny virtual helper | Vtable helper currently not named by Wave3. |
| `0x005bfc0b-0x005bfc21` | Adjustor/thunk helpers | Destructor adjustor thunks. |
| `0x005bfc80-0x005bfcdf` | `ScalarDeletingDestructor(...)` | Clears global pointer, destroys base pane, and optionally deletes. |

## Evidence Notes

- Wave3 grades the class at effective `97.5`.
- IDA MCP confirms all listed starts as exact functions.
- Current emitted source omits `0x005bc880`, `0x005bfc0b`, and `0x005bfc16` bodies/markers.

## Cross-References

- [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)
- [UID:000082][MenuVarietySelectPane](by-class/MenuVarietySelectPane.md)
- [UID:0000RI][g_pMenuVarietyPane](by-global/g_pMenuVarietyPane.md)
- [UID:0000RJ][g_pMenuVarietySelectPane](by-global/g_pMenuVarietySelectPane.md)
- [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)

## Changes

- 2026-06-05: Marked reconstructable and attached to [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md) because the class is `80/86` and the parent is `86/82`, satisfying the 80/80 parent gate. Live IDA MCP evidence: `lookup_funcs` confirms exact starts at `0x005bc610`, `0x005bc660`, `0x005bc690`, `0x005bc800`, `0x005bc880`, and `0x005bfc80`; `callers` confirms constructor use from `0x004f82fc` inside the main UI graph setup path.
- Completion/confidence score update: existed before as `0/0`; changed to `80/86`. Summary: the in-game menu button pane has strong class role, singleton, method boundary, artwork, click/selector behavior, destructor/thunk, and omission notes, with final helper naming and source-level rewrite still incomplete. Evidence: linked `MenuVarietyPanes` and shared destructor/thunk ranges, IDA-confirmed starts, `g_pMenuVarietyPane`, `g_pMenuVarietySelectPane`, and generated omitted-body notes.
