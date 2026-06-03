*** UID:0000DM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SpellInputPaneState

## Status

- Confidence: strong for helper behavior and target-selection ownership, medium for final state type/field names.
- Likely source file: [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md), with [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md) as a consumer/neighbor.
- Address range: [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md)
- Current recovered file: `source-3/simroot_v2/class_SpellInputPaneState.cpp`
- Autogen status: reconstructable state helper class attached to [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md); C++ is intentionally blank because final state type and field names are not source-quality yet.

## Class Purpose

`SpellInputPaneState` is currently represented by one small helper that writes an input-mode byte at offset `+0xfa`. The caller fanout sits in spell and shared target-input flows, so this should be treated as a state/layout helper rather than a standalone feature module.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SetInputModeFlag` | `0x0057c430-0x0057c43f` | Stores the passed byte to `this + 0xfa`. |

## Evidence Notes

- IDA confirms `0x0057c430` as a real 0x10-byte function.
- `simroot_v2` emits only this helper in `class_SpellInputPaneState.cpp`.
- IDA xrefs come from spell input methods and destructor/helper paths, which supports shared state-helper placement near spell/target input code.
- The exact memory page records the pure setter decompilation, raw bytes `55 8b ec 8a 45 08 88 81 fa 00 00 00 5d c2 04 00`, empty callee list, caller family table, and immediate boundary evidence around `0x0057c410`, `0x0057c430`, and `0x0057c440`.
- [UID:00006Y][ItemWhoInputPaneState](by-class/ItemWhoInputPaneState.md) is the item-target sibling with the same one-byte setter body at `0x0057d0a0`, supporting a paired state-helper treatment in the target-selection module.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `70` | The class page now records the known helper, owner choice, source-layout caveat, memory evidence summary, sibling state helper, and parent relationship. Completion remains capped because only one state helper is known and the final class declaration, state layout, and field names are unresolved. |
| Confidence `82` | Confidence is supported by the exact by-memory setter page, byte-level evidence, caller fanout, sibling helper, and a parent file already scored at 80 confidence. It stays below higher-confidence class scores because the original source may have represented this as an inline/private state helper rather than a standalone named class. |

## Cross-References

- [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md)
- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0000DX][SpellWhoInputPane](by-class/SpellWhoInputPane.md)
- [UID:00006Y][ItemWhoInputPaneState](by-class/ItemWhoInputPaneState.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `68`, confidence `76`.
- Evidence: the page documents the exact helper behavior, field offset, IDA function size, and caller-family placement; completion stays limited because this is probably a state/layout helper rather than a standalone class and the final owner source is open.
- 2026-06-03: Raised completion/confidence from `68/76` to `70/82`, marked the page reconstructable, and attached it to [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md).
  - Evidence: [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md) records IDA-backed byte/decompile/caller/callee/boundary evidence, and [UID:00006Y][ItemWhoInputPaneState](by-class/ItemWhoInputPaneState.md) already documents the sibling state-helper pattern. C++ remains blank below the final-source gate.
