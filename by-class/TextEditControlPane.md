*** UID:0000EM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TextEditControlPane

## Status

- Disposition: reconstructable NexusTK project code.
- Likely source file: [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md)
- Main address ranges: `0x004988d0-0x00499021` and `0x0049b6c0-0x0049b731`
- Rebuild handling: source-authored control adapter; final C++ remains blank until the private layout and method names are source-ready.
- IDA MCP evidence pass: 2026-06-05.
- Confidence: strong for ownership, embedded-editor pointer, constructor/destructor behavior, and vtable reachability; medium-high for final private helper names.

## Class Purpose

`TextEditControlPane` is a [UID:000038][ControlPane](by-class/ControlPane.md) adapter that owns an embedded [UID:0000EO][TextEditPane](by-class/TextEditPane.md). It provides the dialog-control surface for text editing: construction from control bounds and style options, layer attach/detach, show/hide/focus forwarding, text-access helpers, editor state synchronization, border painting, and destruction of the child editor.

## Observed State

Important live state:

```text
+0x0ff  initialized flag
+0x101  wrapper/editor state-sync guard
+0x102  selection/full-edit state flag
+0x108  input mode byte
+0x109  border/inset-text-bounds flag
+0x10c  embedded TextEditPane*
+0x110  cached byte copied from embedded TextEditPane offset +0x0b5
```

The full layout still needs a named struct pass, but the embedded editor pointer at `+0x10c` is stable across the constructor, destructor, text helpers, lifecycle virtuals, and state-sync methods.

## Method Families

| Family | Addresses | Role |
| --- | --- | --- |
| Construction | `0x004988d0-0x00498b8d` | Small constructor-like body plus full constructor. The full constructor builds `ControlPane` type `5`, allocates a `372`-byte `TextEditPane`, computes scrollbar-adjusted bounds, applies width scale, editability, max length, line count, local bounds, and optional initial text. |
| Embedded editor destruction | `0x00498b90-0x00498bcf`, [UID:000127][0x0049b6c0-0x0049b731.TextEditControlPaneDestructor](by-memory/0x0049b6c0-0x0049b731.TextEditControlPaneDestructor.md) | Non-deleting helper and scalar deleting destructor both restore wrapper vtables, delete the embedded editor at `+0x10c`, clear the slot, and chain base pane teardown; the scalar wrapper conditionally frees the wrapper allocation. |
| Text and editor-state forwarding | `0x00498bd0-0x00498ce1`, [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder.md) | Max-length/max-line setters, activation/dirty helper, read-text accessor, buffer export, empty-text predicate, replacement-text helper, and three unreferenced raw forwarding stubs. |
| Lifecycle virtuals | `0x00498cf0-0x00498dc8` | Attach/detach to the layer/parent context and forward show/hide/focus behavior through embedded editor subobject vtable slots. |
| State synchronization | `0x00498dd0-0x00498f4c` | Synchronizes wrapper guard bytes with embedded editor state, updates cached editor byte `+0x110`, invalidates wrapper bounds at `+0x44`, and toggles full-selection/edit state. |
| Paint | `0x00498f50-0x00499021` | Draws the older border/inset frame when byte `+0x109` is enabled, using color slots `0x80`, `0x88`, and `0x8c`. |

## Evidence Notes

- `lookup_funcs(0x004988d0)` reports no function, but bounded disassembly confirms a complete small constructor-like body ending with `retn 0x0c` immediately before the full constructor.
- `lookup_funcs(0x00498920)` reports size `0x26d`; `callers(0x00498920)` reports `85` ordinary constructor callers across dialog/control setup paths.
- The full constructor calls the base `ControlPane` constructor with type `5`, allocates a `372`-byte editor, calls the `TextEditPane` constructor at `0x0058dce0`, writes the editor pointer at `+0x10c`, applies max length `1024`, max lines `1`, style/visibility/editability state, and optional initial text.
- `callers` confirms broad reusable-helper fan-in: the limit setters, activation helper, read-text forwarder, buffer export, empty predicate, and replacement helper have `23`, `16`, `19`, `69`, `5`, `21`, and `22` ordinary callers respectively.
- `xrefs_to` confirms lifecycle/state/paint helpers are primarily vtable-reached through cells in the `0x00618130-0x00618218` and `0x0061a294-0x0061a2bc` regions.
- [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder.md) forwards bounded text-copy requests to [UID:0000EO][TextEditPane](by-class/TextEditPane.md), confirming callers can read text through the wrapper without owning text-editor implementation details.
- [UID:000127][0x0049b6c0-0x0049b731.TextEditControlPaneDestructor](by-memory/0x0049b6c0-0x0049b731.TextEditControlPaneDestructor.md) confirms the scalar deleting destructor, two adjustor thunks, primary vtable refs, embedded editor cleanup, and conditional object-free behavior.

## Cross-References

- [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md)
- [UID:0000EO][TextEditPane](by-class/TextEditPane.md)
- [UID:00011H][0x004988d0-0x00499020.TextEditControlPaneCore](by-memory/0x004988d0-0x00499020.TextEditControlPaneCore.md)
- [UID:000127][0x0049b6c0-0x0049b731.TextEditControlPaneDestructor](by-memory/0x0049b6c0-0x0049b731.TextEditControlPaneDestructor.md)
- [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder.md)

## Changes

- 2026-06-05: Live IDA refresh.
  - What existed before: the page was scored `84/86`, cited a recovered-source path, and summarized only the larger constructor/lifecycle/paint/destructor families.
  - Changed to: completion `86`, confidence `90`, stale recovered-source reference removed, helper map expanded with the omitted text accessors and state-sync helpers, and live caller/vtable/destructor evidence added.
  - Summary/evidence: live IDA confirms class ownership, the embedded editor pointer at `+0x10c`, constructor caller fan-in, broad text-helper callers, vtable-only lifecycle/state/paint reachability, and scalar deleting destructor behavior. Final C++ remains blank because the page is below the 95/95 reconstruction-code bar.
