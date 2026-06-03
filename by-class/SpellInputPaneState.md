*** UID:0000DM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SpellInputPaneState

## Status

- Confidence: strong for helper behavior, caller mode semantics, and target-selection ownership; medium for final state type/field names.
- Likely source file: [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md), with [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md) as a consumer/neighbor.
- Address range: [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md)
- Autogen status: reconstructable state helper class attached to [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md); C++ is intentionally blank because final state type and field names are not source-quality yet.

## Class Purpose

`SpellInputPaneState` is currently represented by one small helper that writes an input-mode byte at offset `+0xfa` on the state object returned by `sub_4B85F0(dword_67A874, 3)`. Shared spell/target constructors and destructors choose this setter on the non-item branch of the `byte_66DA97` mode test, with the paired item-state setter used when item-target mode is active.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SetInputModeFlag` | `0x0057c430-0x0057c43f` | Stores the passed byte to `this + 0xfa`. |

## Evidence Notes

- 2026-06-03 live IDA MCP confirms `0x0057c430` as `sub_57C430`, a real `0x10`-byte function with no callees.
- IDA decompilation/disassembly remains the exact setter shape: copy the byte argument to `this[250]` / `[ecx+0xfa]` and return it.
- IDA caller evidence includes 14 call sites from spell/target prompt constructors and scalar deleting destructors.
- Representative decompilation shows constructors such as `0x005adfd0` and `0x005ae380` call the item-state setter when `byte_66DA97 == 1`, otherwise call this spell-state setter with `0`.
- Representative scalar deleting destructors such as `0x005b7c20` and `0x005b8100` use the same branch before base cleanup and optional storage deletion.
- The exact memory page records the pure setter decompilation, raw bytes `55 8b ec 8a 45 08 88 81 fa 00 00 00 5d c2 04 00`, empty callee list, caller family table, and immediate boundary evidence around `0x0057c410`, `0x0057c430`, and `0x0057c440`.
- [UID:00006Y][ItemWhoInputPaneState](by-class/ItemWhoInputPaneState.md) is the item-target sibling with the same one-byte setter body at `0x0057d0a0`, supporting a paired state-helper treatment in the target-selection module.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `76` | The class page records the known helper, owner choice, source-layout caveat, memory evidence summary, sibling state helper, parent relationship, and the live branch semantics that select spell-state versus item-state clearing. Completion remains capped because only one state helper is known and the final class declaration, state layout, and field names are unresolved. |
| Confidence `86` | Confidence is supported by the exact by-memory setter page, byte-level evidence, 14 live IDA caller sites, representative caller decompilation, sibling helper comparison, and a parent file already scored at 80 confidence. It stays below higher-confidence class scores because the original source may have represented this as an inline/private state helper rather than a standalone named class. |

## Cross-References

- [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md)
- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0000DX][SpellWhoInputPane](by-class/SpellWhoInputPane.md)
- [UID:00006Y][ItemWhoInputPaneState](by-class/ItemWhoInputPaneState.md)

## Changes

- 2026-06-03: Raised completion/confidence from `70/82` to `76/86`.
  - Summary/evidence: live IDA MCP reconfirmed `0x0057c430` as a `0x10`-byte pure `this+0xfa` setter with no callees; caller/decompile evidence now documents the 14-site spell/target constructor and destructor fanout plus the `byte_66DA97` branch that selects this spell-state setter versus the item-state sibling. The page remains below the final C++ gate because the source-facing state type and field name are still unresolved.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `68`, confidence `76`.
- Evidence: the page documents the exact helper behavior, field offset, IDA function size, and caller-family placement; completion stays limited because this is probably a state/layout helper rather than a standalone class and the final owner source is open.
- 2026-06-03: Raised completion/confidence from `68/76` to `70/82`, marked the page reconstructable, and attached it to [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md).
  - Evidence: [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md) records IDA-backed byte/decompile/caller/callee/boundary evidence, and [UID:00006Y][ItemWhoInputPaneState](by-class/ItemWhoInputPaneState.md) already documents the sibling state-helper pattern. C++ remains blank below the final-source gate.
