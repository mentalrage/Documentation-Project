*** UID:00006Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ItemWhoInputPaneState

## Status

- Confidence: strong for helper behavior, caller mode semantics, and target-selection ownership; medium for final state type/field names.
- Likely source file: [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md), with [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) as a consumer/neighbor.
- Address range: [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md)
- Autogen status: reconstructable state helper class attached to [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md); C++ is intentionally blank because final state type and field names are not source-quality yet.

## Class Purpose

`ItemWhoInputPaneState` is currently represented by one small helper that writes an input-mode byte at offset `+0xfa` on the state object returned by `sub_4B85F0(dword_67A874, 3)`. Item-target creation checks this byte before allocating an `ItemWhoInputPane`, sets it to `1` while the item-target prompt is active, and clears it through the item-target teardown paths.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SetInputModeFlag` | `0x0057d0a0-0x0057d0af` | Stores the passed byte to `this + 0xfa`. |

## Evidence Notes

- 2026-06-03 live IDA MCP confirms `0x0057d0a0` as `sub_57D0A0`, a real `0x10`-byte function with no callees.
- IDA decompilation/disassembly remains the exact setter shape: copy the byte argument to `this[250]` / `[ecx+0xfa]` and return it.
- IDA caller evidence includes 17 call sites. The item-use path `0x005a3e30` reads `state+0xfa`, allocates a `0x10c`-byte `ItemWhoInputPane` only when the byte is clear, then calls this setter with `1`.
- The item-target non-deleting destructor `0x005aed40` and scalar deleting destructor `0x005b7a20` call this setter with `0` after reconciling the saved target globals.
- Shared spell/target constructors and destructors call this item-state setter when `byte_66DA97 == 1`; the paired spell-state setter is used on the other branch.
- The exact memory page records the pure setter decompilation, raw bytes `55 8b ec 8a 45 08 88 81 fa 00 00 00 5d c2 04 00`, empty callee list, caller family table, and immediate boundary evidence around `0x0057d080`, `0x0057d0a0`, and `0x0057d0b0`.
- The caller fanout supports [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md) as the best current parent because the helper participates in item target-use, spell target prompt constructors, and input-pane destructor paths instead of only the direct item-action input module.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `76` | The class page records the known helper, owner choice, source-layout caveat, memory evidence summary, parent relationship, item-use guard semantics, teardown clearing behavior, and paired spell/item mode selection. Completion remains capped because only one state helper is known and the final class declaration, state layout, and field names are unresolved. |
| Confidence `86` | Confidence is supported by the exact by-memory setter page, byte-level evidence, 17 live IDA caller sites, representative caller decompilation, sibling helper comparison, and a parent file already scored at 80 confidence. It stays below higher-confidence class scores because the original source may have represented this as an inline/private state helper rather than a standalone named class. |

## Cross-References

- [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001IJ][0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag](by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md)
- [UID:0000DX][SpellWhoInputPane](by-class/SpellWhoInputPane.md)
- [UID:0000DM][SpellInputPaneState](by-class/SpellInputPaneState.md)

## Changes

- 2026-06-03: Raised completion/confidence from `70/82` to `76/86`.
  - Summary/evidence: live IDA MCP reconfirmed `0x0057d0a0` as a `0x10`-byte pure `this+0xfa` setter with no callees; caller/decompile evidence now documents the item-use allocation guard, active-prompt set-to-`1`, teardown set-to-`0`, and `byte_66DA97` branch that selects the paired spell or item state setter. The page remains below the final C++ gate because the source-facing state type and field name are still unresolved.
- 2026-06-02: Raised completion/confidence from `62/76` to `70/82`, marked the page reconstructable, and attached it to [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md). This uses the exact setter memory page's IDA-recorded byte, caller, callee, and boundary evidence while keeping C++ blank because the final state declaration and field names are not source-quality.
- Completion/confidence score update: existed before as `0/0`; changed to `62/76`. Summary: the one known helper, input-mode flag offset, cross-flow xrefs, and likely owner modules are documented, but the page is intentionally incomplete as a standalone class because final ownership belongs with broader spell/item target-state paths. Evidence: `ItemWhoInputPaneStateSetFlag`, TargetSelectionInputPanes, ItemActionInputPanes, SpellWhoInputPane, and SpellInputPaneState.
