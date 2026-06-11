*** UID:0001V9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:00008K | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ModelessDialogPane Layout

## Status

- Entity kind: class layout / secondary-view event-state notes.
- Covered class: [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md).
- Likely owner header/source: [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md).
- Confidence: strong for vtable offsets and mouse-event offset mapping; medium for final field names.
- Autogen parent: attached to [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md); the class scores `86/84` and this layout scores `82/88`, so both sides satisfy the 80/80 parent gate.

## Layout Summary

`ModelessDialogPane` uses the same three-view layout as [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md) over [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md). IDA did not identify a class-specific destructor or a separate derived tail during this pass. Its class-specific behavior is concentrated in the constructor, `IsModal`, and the secondary-view mouse-event handler.

| Base object offset | Field/state | Evidence |
| --- | --- | --- |
| `+0x00` | primary vptr, `0x00618c48` | Constructor `0x004a0760` installs the primary table at `0x004a07bd`. |
| `+0xa0` | secondary event/input vptr, `0x00618ca8` | Constructor installs at `0x004a07c4` and registers `this + 0xa0` with the event dispatcher. |
| `+0xa4` | tertiary event/update vptr, `0x00618cd8` | Constructor installs at `0x004a07ca`; table is the common short tertiary view. |
| `+0x0f8-+0x268` | inherited `DialogPane` title/config/control/mouse/background state | See [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md). `HandleMouseEvent` reuses the inherited mouse/control state. |

## Secondary-View Offset Mapping

`ModelessDialogPane::HandleMouseEvent` at `0x004a0840` receives `ecx == object + 0xa0`. In IDA disassembly the local `esi` is that secondary-view pointer, and the core `DialogPane` pointer is recovered with `esi - 0xa0`. Therefore generated offsets such as `context + 360` are secondary-relative and must be translated back to base-object offsets.

| IDA access | Base object offset | Field/state hypothesis | Evidence |
| --- | --- | --- | --- |
| `[esi+0x158]` | `+0x1f8` | dialog config id | Release path checks for `0xffff` before saving bounds/focus state. |
| `[esi+0x15c]` | `+0x1fc` | control manager/list pointer | Mouse-down/release paths use this pointer to look up control entries. |
| `[esi+0x168]` | `+0x208` | title-drag/capture active byte | Mouse-down on hit type `10` sets it to `1`; release clears it to `0`. |
| `[esi+0x169]` | `+0x209` | saved pane/input mode byte | Mouse-down saves byte `[esi+0x15]`; release restores it through `sub_5446B0`. |
| `[esi+0x16c]` | `+0x20c` | drag origin X | Mouse-down stores the current mouse X; move subtracts it while updating position. |
| `[esi+0x170]` | `+0x210` | drag origin Y | Mouse-down stores the current mouse Y; move subtracts it while updating position. |
| `[esi+0x174]` | `+0x214` | previous hover/control id | Mouse-down compares the hit id against this field before invoking hover candidate callback. |
| `[esi+0x178]` | `+0x218` | pressed-control active byte | Mouse-down sets it; release clears it before dispatching release behavior. |
| `[esi+0x17c]` | `+0x21c` | pressed control id | Mouse-down stores the hit id; move/release compare and dispatch through it. |
| `[esi+0x180]` | `+0x220` | pressed hit type byte | Mouse-down stores the hit type; release checks it before activating. |
| `[esi+0x184]` | `+0x224` | prior hover/reset control id | Release resets this field to `-1` after clearing a previous control state. |
| `[esi+0x188]` | `+0x228` | prior hover/reset hit type byte | Release resets this to hit type `10`; mouse code treats `10` as title/chrome or neutral state. |
| `[esi+0x189]` | `+0x229` | drag clamp enabled byte | Move path checks this before clamping to min/max bounds. |
| `[esi+0x18c]` | `+0x22c` | minimum Y bound candidate | Drag move clamps top position against this field. |
| `[esi+0x190]` | `+0x230` | minimum X bound candidate | Drag move clamps left position against this field. |
| `[esi+0x194]` | `+0x234` | maximum Y bound candidate | Drag move clamps bottom position against this field. |
| `[esi+0x198]` | `+0x238` | maximum X bound candidate | Drag move clamps right position against this field. |

The disassembly also reads `[esi-0x5c]`, `[esi-0x54]`, and `[esi-0x50]`, which translate to base `Pane`/`DialogPane` rectangle and extent state. Those are inherited fields, not `ModelessDialogPane`-specific members.

## IDA Evidence

Checked on 2026-05-26:

- Constructor `0x004a0760` calls `DialogPane::DialogPane(title, -1, 1)`, installs three `ModelessDialogPane` vtables, initializes default bounds `(100,100)-(200,200)`, initializes pane interaction, and registers the secondary view with the event dispatcher.
- `IsModal` at `0x004a0830` returns false and is referenced from secondary vtable `0x00618ca8 + 0x08`.
- `HandleMouseEvent` at `0x004a0840` is referenced from secondary vtable `0x00618ca8 + 0x04`, computes `dialogCore = this - 0xa0`, and uses the translated offsets above for drag, hover, pressed-control, and clamp behavior.
- No direct constructor callers were found in this pass, but vtable references and executable method bodies make this a real reconstructable class.

Rechecked on 2026-05-31:

- IDA MCP `lookup_funcs` reports `0x004a0760` size `0xc7`, `0x004a0830` size `0x5`, and `0x004a0840` size `0x44e`.
- IDA MCP decompilation confirms the constructor calls `DialogPane::DialogPane(title, -1, 1)`, writes the primary/secondary/tertiary vtables, creates default bounds `(100,100)-(200,200)`, initializes pane interaction, and registers `this + 0xa0` through the event dispatcher.
- IDA MCP `xrefs_to` confirms constructor data writes to vtables `0x00618c48`, `0x00618ca8`, and `0x00618cd8`; it also confirms data references to `IsModal` at `0x00618cb0` and `HandleMouseEvent` at `0x00618cac`.
- IDA MCP disassembly confirms `HandleMouseEvent` stores `ecx` in `esi` as the secondary-view pointer and repeatedly uses `lea ..., [esi-0xa0]` for the base `DialogPane` object, so the `+0x168..+0x198` accesses are secondary-relative views of base-object fields.

## Reconstruction Notes

- Do not create a separate modeless tail for the generated `context + 360` through `context + 408` fields. Those are secondary-relative views of inherited `DialogPane +0x208` through `+0x238` state.
- `ModelessDialogPane` should still remain its own class/source file because it installs its own vtables and owns the modeless event handler.
- Final field names should be coordinated with [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md) so modal/modeless/session dialogs use one inherited layout.

## Cross-References

- [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md)
- [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md)
- [UID:00012Z][0x004a0760-0x004a0c8e.ModelessDialogPane](by-memory/0x004a0760-0x004a0c8e.ModelessDialogPane.md)
- [UID:0001Y6][ModelessDialogPaneVtables](by-type/by-vtable/ModelessDialogPaneVtables.md)
- [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md)
- [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-06-06: Attached the layout to [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md). Scores remain `82/88`; the update only syncs parent metadata for the already documented three-view dialog layout.
- Before: completion/confidence were `0/0`, and `RECONSTRUCTABLE` was blank despite the page containing IDA-backed layout research.
- Changed to: completion `82`, confidence `88`, and `RECONSTRUCTABLE:TRUE`.
- Summary/evidence: 2026-05-31 IDA MCP rechecked function boundaries, constructor vtable stores, secondary vtable references for `IsModal` and `HandleMouseEvent`, and the `this + 0xa0` secondary-view offset translation. Scores remain below `95` because final inherited field names and live allocation sites are still not fully resolved.
