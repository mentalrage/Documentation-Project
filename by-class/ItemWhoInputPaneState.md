*** UID:00006Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ItemWhoInputPaneState

## Status

- Confidence: strong for helper behavior and target-selection ownership, medium for final state type/field names.
- Likely source file: [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md), with [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) as a consumer/neighbor.
- Address range: [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md)
- Current recovered file: `source-3/simroot_v2/class_ItemWhoInputPaneState.cpp`
- Autogen status: reconstructable state helper class attached to [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md); C++ is intentionally blank because final state type and field names are not source-quality yet.

## Class Purpose

`ItemWhoInputPaneState` is currently represented by one small helper that writes an input-mode byte at offset `+0xfa`. It is used by item target-input flows and by nearby shared spell/item target state paths.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SetInputModeFlag` | `0x0057d0a0-0x0057d0af` | Stores the passed byte to `this + 0xfa`. |

## Evidence Notes

- IDA confirms `0x0057d0a0` as a real 0x10-byte function.
- `simroot_v2` emits only this helper in `class_ItemWhoInputPaneState.cpp`.
- IDA xrefs include item target-input methods, spell input methods, and destructor/helper paths, so this should not be treated as a one-class source file in final layout.
- The exact memory page records the pure setter decompilation, raw bytes `55 8b ec 8a 45 08 88 81 fa 00 00 00 5d c2 04 00`, empty callee list, caller family table, and immediate boundary evidence around `0x0057d080`, `0x0057d0a0`, and `0x0057d0b0`.
- The caller fanout supports [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md) as the best current parent because the helper participates in item target-use, spell target prompt constructors, and input-pane destructor paths instead of only the direct item-action input module.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `70` | The class page now records the known helper, owner choice, source-layout caveat, memory evidence summary, and parent relationship. Completion remains capped because only one state helper is known and the final class declaration, state layout, and field names are unresolved. |
| Confidence `82` | Confidence is supported by the exact by-memory setter page, byte-level evidence, caller fanout, and a parent file already scored at 80 confidence. It stays below higher-confidence class scores because the original source may have represented this as an inline/private state helper rather than a standalone named class. |

## Cross-References

- [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md)
- [UID:0000DX][SpellWhoInputPane](by-class/SpellWhoInputPane.md)
- [UID:0000DM][SpellInputPaneState](by-class/SpellInputPaneState.md)

## Changes

- 2026-06-02: Raised completion/confidence from `62/76` to `70/82`, marked the page reconstructable, and attached it to [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md). This uses the exact setter memory page's IDA-recorded byte, caller, callee, and boundary evidence while keeping C++ blank because the final state declaration and field names are not source-quality.
- Completion/confidence score update: existed before as `0/0`; changed to `62/76`. Summary: the one known helper, input-mode flag offset, cross-flow xrefs, and likely owner modules are documented, but the page is intentionally incomplete as a standalone class because final ownership belongs with broader spell/item target-state paths. Evidence: `ItemWhoInputPaneStateSetFlag`, TargetSelectionInputPanes, ItemActionInputPanes, SpellWhoInputPane, and SpellInputPaneState.
