*** UID:000077 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000K7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LineInputPane

## Status

- Confidence: strong for class role, IDA boundaries, vtable lifecycle, prompt/text child ownership, and shared cleanup fanout; medium for exact field names.
- Likely source file: [UID:0000K7][InputPanes](by-file/InputPanes.md)
- Main address range: [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- Related derived handler: [UID:0001ME][0x005b3e80-0x005b4071.LineInputPaneHistoryNavigation](by-memory/0x005b3e80-0x005b4071.LineInputPaneHistoryNavigation.md) is now attributed to [UID:0000C7][SayToUserNameInputPane](by-class/SayToUserNameInputPane.md); it delegates unhandled keys to `LineInputPane::HandleKeyInput`.
- Compiler adjustors: [UID:00018Z][0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks.md)
- Vtables: [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)

## Class Purpose

`LineInputPane` is the reusable one-line prompt base. It creates optional label text plus a `TextEditPane`, positions them differently for normal/high-resolution layouts, registers itself as the active line-input pane, forwards most input to the edit child, and handles Enter/Escape/Tab dismissal and owner notification.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x004f1c00-0x004f2009` | constructor | Creates label/edit child panes, positions the prompt, updates active line-input state, and notifies input manager. |
| `0x004f2010-0x004f2092` | shared cleanup/lifecycle body | Restores the three `LineInputPane` vtable views, removes prompt/edit children through the pane manager, and chains to inherited pane cleanup. |
| `0x004f20a0-0x004f22f4` | `SetPromptText` | Measures, creates, updates, and repositions the prompt label text child and paired edit child. |
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

## Evidence Notes

- IDA MCP confirms every listed function start.
- 2026-05-26 IDA MCP confirms `LineInputPane` vtables at `0x0061ca58`, `0x0061caa8`, and `0x0061cad8`, with constructor/destructor stores in the `0x004f1c00` cluster.
- 2026-06-06 IDA MCP confirms the early lifecycle/prompt sequence: the constructor is `0x004f1c00-0x004f2009`, `0x004f2010-0x004f2092` is the shared cleanup body, [UID:00018Y][0x004f20a0-0x004f22f4.LineInputPaneSetPromptText](by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md) is the shared prompt setter, and the intervening spans are `0xcc` alignment padding.
- Decompilation of `0x004f2010` shows cleanup at `this+0xf8` and `this+0xfc`; the prompt setter page documents the same two child slots as prompt label and companion input child, making those offsets stable class-layout evidence even though final field names remain unresolved.
- IDA confirms the secondary/tertiary destructor entries are two-instruction compiler thunks, not handwritten methods.
- IDA decompilation of `0x004f25a0` shows real input handling despite an imported/generated body omission; track the omission under [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md).
- The previously listed `0x005b3e80` non-contiguous helper is not directly owned by `LineInputPane`: live IDA shows it in a `SayToUserNameInputPane` secondary vtable slot, with `LineInputPane::HandleKeyInput` used only as its fallback delegate.

## Cross-References

- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:00018Y][0x004f20a0-0x004f22f4.LineInputPaneSetPromptText](by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md)
- [UID:00018Z][0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks.md)
- [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- [UID:00001P][CharInputPane](by-class/CharInputPane.md)
- [UID:00009L][NumberInputPane](by-class/NumberInputPane.md)
- [UID:00001O][CharArgsInputPane](by-class/CharArgsInputPane.md)
- [UID:00009J][NumberArgsInputPane](by-class/NumberArgsInputPane.md)
- [UID:00008T][MultiLineInputPane](by-class/MultiLineInputPane.md)
- [UID:000035][ConfirmInputPane](by-class/ConfirmInputPane.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)
- [UID:0000C7][SayToUserNameInputPane](by-class/SayToUserNameInputPane.md)

## Changes

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000K7][InputPanes](by-file/InputPanes.md) because this class is 84/82 and the parent file is 88/82. Live IDA MCP on `NexusTK.exe` confirmed the constructor/layout/input/destructor cluster from `0x004f1c00` through `0x004f2ea0` and the null virtual at `0x004f2790`.
- Completion/confidence score update: existed before as `0/0`; changed to `84/82`. Summary: the one-line prompt base is documented with a detailed method map, vtables, compiler adjustors, and missing-body caveat, but exact field names and final source-level C++ remain incomplete. Evidence: IDA-confirmed function starts, input-pane vtable family, destructor thunk notes, and imported/generated body-omission tracking.
- 2026-06-05: Raised confidence from `82` to `84` and corrected the `0x005b3e80` ownership note.
  - Before: this page listed [UID:0001ME][0x005b3e80-0x005b4071.LineInputPaneHistoryNavigation](by-memory/0x005b3e80-0x005b4071.LineInputPaneHistoryNavigation.md) as a non-contiguous `LineInputPane` helper.
  - After: this page treats that helper as [UID:0000C7][SayToUserNameInputPane](by-class/SayToUserNameInputPane.md) code that depends on `LineInputPane::HandleKeyInput` for fallback behavior.
  - Evidence: 2026-06-05 IDA MCP reports the sole function xref to `0x005b3e80` at `0x0062fccc`, the `SayToUserNameInputPane` secondary vtable slot; the function's adjusted offsets match recipient-name history fields initialized by `0x005b3cb0`.
- 2026-06-06: Raised completion/confidence from `84/84` to `86/88` after filling the missing early lifecycle/prompt entries.
  - Before: the class method map jumped from the constructor to layout/update helpers and did not list the shared cleanup body or prompt setter.
  - After: the method map records the corrected constructor end, `0x004f2010` cleanup body, and linked `LineInputPaneSetPromptText` child page, with evidence for the shared child slots at `this+0xf8` and `this+0xfc`.
  - Evidence: IDA MCP `lookup_funcs`, `decompile`, `disasm`, and byte checks on 2026-06-06.
