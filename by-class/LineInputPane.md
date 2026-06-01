*** UID:000077 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LineInputPane

## Status

- Confidence: strong for class role and IDA boundaries; medium for exact field names.
- Likely source file: [UID:0000K7][InputPanes](by-file/InputPanes.md)
- Main address range: [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- Non-contiguous helper: [UID:0001ME][0x005b3e80-0x005b4071.LineInputPaneHistoryNavigation](by-memory/0x005b3e80-0x005b4071.LineInputPaneHistoryNavigation.md)
- Compiler adjustors: [UID:00018Z][0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks.md)
- Vtables: [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- Current recovered file: `source-3/simroot_v2/class_LineInputPane.cpp`

## Class Purpose

`LineInputPane` is the reusable one-line prompt base. It creates optional label text plus a `TextEditPane`, positions them differently for normal/high-resolution layouts, registers itself as the active line-input pane, forwards most input to the edit child, and handles Enter/Escape/Tab dismissal and owner notification.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x004f1c00-0x004f2008` | constructor | Creates label/edit child panes, positions the prompt, updates active line-input state, and notifies input manager. |
| `0x004f2320-0x004f242e` | layout update | Recomputes label width and positions label/edit child panes. |
| `0x004f2430-0x004f24b4` | attach children | Attaches and shows label/edit children. |
| `0x004f24c0-0x004f24e4` | show/invalidate children | Invalidates label/edit panes and base pane. |
| `0x004f24f0-0x004f2579` | hit-test adjuster | Adjusts event coordinates for label/edit split and forwards to edit pane. |
| `0x004f2580-0x004f2597` | active-child forwarder | Forwards to the text-edit active interface. |
| `0x004f25a0-0x004f2754` | `HandleKeyInput` | Handles Enter/Escape/Tab, pending-submit state, owner notification, dismissal, and menu-state cleanup. Active generated output omits the body. |
| `0x004f2790` | no-op virtual | Empty leaf slot. |
| `0x004f2dd0-0x004f2e58` | non-deleting destructor | Dismisses child panes and tears down pane base. |
| `0x004f2e59-0x004f2e6e` | secondary/tertiary destructor adjustors | Compiler thunks that subtract `0xa0` or `0xa4` and tail-jump to the shared scalar deleting destructor. |
| `0x004f2ea0-0x004f2f62` | scalar deleting destructor | Destructor wrapper with conditional delete. |
| `0x005b3e80-0x005b4071` | `HandleHistoryNavigation` | Handles recent/fallback recipient history cycling for selected chat modes before falling back to `HandleKeyInput`. |

## Evidence Notes

- IDA MCP confirms every listed function start.
- 2026-05-26 IDA MCP confirms `LineInputPane` vtables at `0x0061ca58`, `0x0061caa8`, and `0x0061cad8`, with constructor/destructor stores in the `0x004f1c00` cluster.
- IDA confirms the secondary/tertiary destructor entries are two-instruction compiler thunks, not handwritten methods.
- IDA decompilation of `0x004f25a0` shows real input handling despite the active simroot body omission; track the omission under [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md).
- `HandleHistoryNavigation` uses user-pane recipient history structures and writes text into the embedded edit pane.

## Cross-References

- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:00018Z][0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks.md)
- [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- [UID:00001P][CharInputPane](by-class/CharInputPane.md)
- [UID:00009L][NumberInputPane](by-class/NumberInputPane.md)
- [UID:00001O][CharArgsInputPane](by-class/CharArgsInputPane.md)
- [UID:00009J][NumberArgsInputPane](by-class/NumberArgsInputPane.md)
- [UID:00008T][MultiLineInputPane](by-class/MultiLineInputPane.md)
- [UID:000035][ConfirmInputPane](by-class/ConfirmInputPane.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `84/82`. Summary: the one-line prompt base is documented with a detailed method map, vtables, compiler adjustors, non-contiguous history helper, and missing-body caveat, but exact field names and final source-level C++ remain incomplete. Evidence: IDA-confirmed function starts, input-pane vtable family, destructor thunk notes, history navigation range, and active simroot omission tracking.
