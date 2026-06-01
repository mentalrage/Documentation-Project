*** UID:0000CN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrollSpellInventoryPane

## Status

- Confidence: strong for scrollbar behavior, medium for one reset-helper boundary.
- Likely source file: [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md), or folded into [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md)
- Address range: [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md)
- Layout: [UID:0001W1][ScrollSpellInventoryPaneLayout](by-type/by-struct/ScrollSpellInventoryPaneLayout.md)
- Vtables: [UID:0001YS][ScrollSpellInventoryPaneVtables](by-type/by-vtable/ScrollSpellInventoryPaneVtables.md)
- Current recovered file: `source-3/simroot_v2/class_ScrollSpellInventoryPane.cpp`

## Class Purpose

`ScrollSpellInventoryPane` is the EPF-backed scrollbar pane used by spell inventory UI. It manages scroll range, position, activation, drag/click state, repeat timers, painting, part rectangles, hover part updates, and reset-to-idle behavior.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ScrollSpellInventoryPane` | `0x0055f450-0x0055f4f1` | Constructs scrollbar pane with orientation and initial state. |
| `SetMaxRange` | `0x0055f560-0x0055f5ba` | Clamps max range and current position. |
| `SetScrollPosition` | `0x0055f5c0-0x0055f5e6` | Updates scroll position and invalidates. |
| `Activate` | `0x0055f5f0-0x0055f609` | Shows the scrollbar and triggers initial paint. |
| `HandleMouseEvent` | `0x0055f650-0x0055f830` | Handles mouse drag and click interactions. |
| `OnScrollRepeat` | `0x0055f850-0x0055f882` | Auto-repeats scroll action while a button is held. |
| `OnPaint` | `0x0055f890-0x0055ff6f` | Paints track sections and scroll button. |
| `GetPartRect` | `0x00560290-0x00560516` | Calculates rectangles for scrollbar parts. |
| `SetHoverPart` | `0x00560520-0x0056058f` | Updates hover part and invalidates affected regions. |
| `UpdateFromDrag` candidate | [UID:0001GN][0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag](by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md) | Recomputes the scroll position from drag/click geometry and notifies the owning spell inventory pane. |
| `ResetScrollState` candidate | [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) | Raw method-shaped reset helper; IDA does not currently define a function at this start. |

## Evidence Notes

- IDA MCP confirms constructor, paint, and part-rect function boundaries.
- IDA MCP caller check on 2026-05-24 shows the constructor `0x0055f450` is only directly called from `NewSpellInventoryPane::NewSpellInventoryPane` at `0x0057d013`.
- IDA MCP lookup confirms the activation helper `0x0055f5f0` as a real `0x1a`-byte function.
- IDA reports no function at `0x005608a0`; previous modeled function is `0x00560710-0x0056089d`, and raw disassembly shows method-shaped reset code through `0x005608fc` before the next function at `0x00560900`. Treat the reset-helper function-table mismatch as data debt.
- IDA-backed allocation and constructor evidence records the same `0x110` scrollbar tail field pattern as the item-inventory scrollbar; see [UID:0001W1][ScrollSpellInventoryPaneLayout](by-type/by-struct/ScrollSpellInventoryPaneLayout.md).
- 2026-05-26 IDA MCP confirms vtable bases `0x00623e94`, `0x00623ee0`, and `0x00623f10`, with paint, mouse, and repeat slots mapped in [UID:0001YS][ScrollSpellInventoryPaneVtables](by-type/by-vtable/ScrollSpellInventoryPaneVtables.md).

## Cross-References

- [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md)
- [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md)
- [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md)
- [UID:0001W1][ScrollSpellInventoryPaneLayout](by-type/by-struct/ScrollSpellInventoryPaneLayout.md)
- [UID:0001YS][ScrollSpellInventoryPaneVtables](by-type/by-vtable/ScrollSpellInventoryPaneVtables.md)
- [UID:00009A][NewSpellInventoryPane](by-class/NewSpellInventoryPane.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `80/78`.
  - Before: The page was unevaluated despite documenting the spell-inventory scrollbar methods, caller, layout, vtables, and reset-helper mismatch.
  - After: Scored as high completion with medium-high confidence because scrollbar behavior is strong, while one raw reset-helper boundary and source placement remain unresolved.
  - Evidence: Existing method notes, IDA caller/evidence notes, layout/vtable references, and NewSpellInventoryPane relationship support the score.
- 2026-05-31: Marked `RECONSTRUCTABLE:TRUE`.
  - Before: The class page documented project-owned behavior but had no validator reconstructable flag.
  - Changed to: The page is flagged as rebuild-owned while `AUTOGEN_PARENT_UID` and C++ remain blank.
  - Evidence: IDA MCP confirms `NewSpellInventoryPane::NewSpellInventoryPane` allocates a 0x110-byte pane, calls the `0x0055f450` constructor, and owns the spell-inventory scrollbar; final source-file placement and source-quality C++ are not at the 95+ gate.
