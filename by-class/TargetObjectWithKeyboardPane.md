*** UID:0000ED | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TargetObjectWithKeyboardPane

## Status

- Confidence: strong for class behavior and IDA boundaries; medium for exact original file split.
- Likely source file: [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- Address range: [UID:0001L8][0x005af390-0x005b050d.TargetSelectionInputPanes](by-memory/0x005af390-0x005b050d.TargetSelectionInputPanes.md)
- Current recovered file: `source-3/simroot_v2/class_TargetObjectWithKeyboardPane.cpp`

## Class Purpose

`TargetObjectWithKeyboardPane` is a [UID:000077][LineInputPane](by-class/LineInputPane.md)-derived target selector for the target-dispatch flow. It prompts the player to use arrow keys and press `v`, tracks the selected target id in `dword_69BF2C`, highlights the current target, and forwards target confirmation into the overlay/dispatch code.

It is close in structure to [UID:0000CT][SelectObjectWithKeyboardPane](by-class/SelectObjectWithKeyboardPane.md), but it uses a separate singleton/state set and confirms with `v` rather than Enter.

## Method Notes

| Method/helper | Address | Role |
| --- | --- | --- |
| constructor | [UID:0001LI][0x005afef0-0x005affde.TargetObjectWithKeyboardPaneConstructor](by-memory/0x005afef0-0x005affde.TargetObjectWithKeyboardPaneConstructor.md) | Builds the line-input base, stores the active singleton in `dword_69BF64`, installs three vtable views, chooses the initial target, highlights it, and attaches to the input capture pane. |
| non-deleting destructor | [UID:0001LJ][0x005affe0-0x005b0009.TargetObjectWithKeyboardPaneDestructor](by-memory/0x005affe0-0x005b0009.TargetObjectWithKeyboardPaneDestructor.md) | Resets vtables, clears `dword_69BF64`, and calls the base cleanup helper. |
| `HandleTargetKeyboardEvent` | [UID:0001LK][0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent](by-memory/0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent.md) | Handles cancel, previous/next target keys, self target, tab/`v` dispatch-mode keys, and target highlight changes. |
| `HandleTargetMouseEvent` | [UID:0001LL][0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent](by-memory/0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent.md) | Converts mouse coordinates to map space, updates selected living object, and participates in target confirmation/cancel behavior. |
| object-list helper | `0x005b0510-0x005b05a3` | Sibling helper that parses underscore-prefixed object-list payloads, checks the saved `dword_69BF2C` target id against four-byte object-id entries, and falls back to the local player/highlight state when the saved target is no longer present. Pending split into an exact by-memory page. |
| clear-current-target helper | `0x005b05b0-0x005b05cf` | Resolves `dword_69BF2C` through the active map pane and clears the selected target highlight; called by the keyboard cancel path and mouse confirm paths. Pending split into an exact by-memory page. |
| target navigation raw helper island | `0x005b05d0-0x005b06ef` | Three source-authored helper bodies that IDA does not model as function starts: previous/up traversal through `sub_506AE0`, next/down traversal through `sub_506B30`, and local-player retargeting. They update or clear `dword_69BF2C` and toggle highlights. Pending split into an exact by-memory page. |
| target-dispatch forward helper | `0x005b06f0-0x005b077a` | Handles Tab/`v` dispatch-mode forwarding by priming active-map temporary target state, setting `byte_69BEDA`, copying `dword_69BF2C` into `dword_69BF30`, dismissing the selector, then forwarding the event to the line-input base as Tab. Pending split into an exact by-memory page. |
| adjustor thunks | [UID:0001NB][0x005b7912-0x005b7928.TargetObjectWithKeyboardPaneAdjustorThunks](by-memory/0x005b7912-0x005b7928.TargetObjectWithKeyboardPaneAdjustorThunks.md) | Secondary/tertiary vtable thunks to the scalar deleting destructor; source reconstruction excludes them through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:0001NL][0x005b81d0-0x005b822f.TargetObjectWithKeyboardPaneScalarDeletingDestructor](by-memory/0x005b81d0-0x005b822f.TargetObjectWithKeyboardPaneScalarDeletingDestructor.md) | Delete wrapper; repeats vtable/singleton cleanup, calls base cleanup, and frees when requested. |

## Evidence Notes

- `simroot_v2` emits the constructor, keyboard handler, mouse handler, one adjustor thunk, and scalar deleting destructor.
- IDA confirms the omitted non-deleting destructor at `0x005affe0` and the disabled/missing-code thunk at `0x005b791d`.
- IDA data xrefs place `0x005b0010` and `0x005b0290` in `TargetObjectWithKeyboardPane` vtable slots.
- 2026-05-26 IDA recheck confirms `0x005b7912` and `0x005b791d` forward to `0x005b81d0` after `this - 0xa0` and `this - 0xa4`; both are tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).
- The generated scalar destructor body references base cleanup through a generic helper; do not interpret any base-helper name pollution as source ownership outside this class.
- 2026-06-06 A007 IDA helper inventory confirms `lookup_funcs` models `0x005b0510` as `sub_5B0510`, size `0x93`; `0x005b05b0` as `sub_5B05B0`, size `0x1f`; and `0x005b06f0` as `sub_5B06F0`, size `0x8a`. Byte checks show `0x005b050d-0x005b0510`, `0x005b05a3-0x005b05b0`, and `0x005b077a-0x005b0780` are `0xcc` alignment.
- `xrefs_to 0x005b05b0` reports calls from the keyboard handler at `0x005b0082` and the mouse handler at `0x005b0422`/`0x005b0495`; `xrefs_to 0x005b06f0` reports keyboard-handler calls at `0x005b00ce` and `0x005b00f4`.
- The raw helper island at `0x005b05d0-0x005b06ef` is executable target-selection code between two modeled helpers, but IDA does not currently model starts at `0x005b05d0`, `0x005b0640`, or `0x005b06b0`. Bounded disassembly shows the same previous/next/local-player retarget pattern used by the keyboard handler and the sibling `SelectObjectWithKeyboardPane` helper island.
- Exact by-memory pages for `0x005b0510-0x005b077a` are deferred until validator state and generated coverage files are free; keep the helper names provisional until those split pages are created and validated.

## Cross-References

- [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- [UID:0001L8][0x005af390-0x005b050d.TargetSelectionInputPanes](by-memory/0x005af390-0x005b050d.TargetSelectionInputPanes.md)
- [UID:0001NB][0x005b7912-0x005b7928.TargetObjectWithKeyboardPaneAdjustorThunks](by-memory/0x005b7912-0x005b7928.TargetObjectWithKeyboardPaneAdjustorThunks.md)
- [UID:0000CT][SelectObjectWithKeyboardPane](by-class/SelectObjectWithKeyboardPane.md)
- [UID:00006X][ItemWhoInputPane](by-class/ItemWhoInputPane.md)
- [UID:000077][LineInputPane](by-class/LineInputPane.md)

## Changes

- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md).
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the documented constructor, destructor, keyboard handler, mouse handler, adjustor thunks, and scalar deleting destructor starts at `0x005afef0`, `0x005affe0`, `0x005b0010`, `0x005b0290`, `0x005b7912`, `0x005b791d`, and `0x005b81d0`; this page and parent [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md) both meet the 80/80 parent gate. No C++ was emitted because the page is below the 95/95 reconstruction-code bar.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Evidence: the page documents target-selector behavior, constructor/destructor/keyboard/mouse/destructor-thunk memory docs, vtable refs, singleton state, generated omissions, and sibling selector relationships; confidence remains capped by exact original file split.
- 2026-06-06 A007 helper inventory:
  - Before: the class page stopped at the documented keyboard/mouse methods and destructor thunks, while the target-object object-list, clear-target, dispatch-forward, and raw navigation helpers after `0x005b050d` were only visible indirectly from sibling method pages.
  - After: added class-level helper inventory for `0x005b0510-0x005b077a` and documented modeled function sizes, xrefs, alignment, touched globals, raw-island shape, and the pending by-memory split work.
  - Evidence: live IDA MCP `lookup_funcs`, `xrefs_to`, decompilation, bounded raw disassembly, and byte checks for helper boundaries. Scores remain `86/80` until the exact helper pages and validator-generated references are added.
