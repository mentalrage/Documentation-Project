*** UID:0000NN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# SelfSaveOKPane

## Status

- Proposed source path: `ui/dialogs/SelfSaveOKPane.cpp`.
- Confirmed local range: [UID:0001B0][0x005147d0-0x00514914.SelfSaveOKPane](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md)
- Current generated source: `source-3/simroot_v2/class_SelfSaveOKPane.cpp`
- Confidence: strong for the small pane island and generated-owner pollution; medium-high for final original file placement.

## File Role

The recoverable SelfSaveOKPane-specific source is a small `TextBoxPane`-based confirmation/status pane. It sets a localized caption, attaches itself to the screen/render layer, and self-dismisses through a timer-handler facet.

This page is mostly a guardrail against bad migration: the generated file currently mixes unrelated ownership into `class_SelfSaveOKPane.cpp`.

The pane is packet-created. [UID:0000L3][MapPane](by-file/MapPane.md) packet case `0x21` contains an inline construction block around `0x00508516-0x005085ed`; IDA also has a standalone constructor at `0x005147d0` and an unreferenced factory-like helper at [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md).

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:0000CX][SelfSaveOKPane](by-class/SelfSaveOKPane.md) constructor | `0x005147d0-0x005148d5` | Builds the text-box pane and localized caption. |
| `SelfSaveOKPane::OnTimerExpired` | `0x005148e0-0x00514913` | Timer-handler facet method reached through vtable slot `0x0061e850`. |
| SelfSaveOKPane factory/helper | [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md) | Allocates and constructs the same pane sequence; no direct xrefs currently reported. |
| [UID:0001YV][SelfSaveOKPane_vtables](by-type/by-vtable/SelfSaveOKPane_vtables.md) | `0x0061e7a4`, `0x0061e81c`, `0x0061e84c` | Three vtables installed by the constructor/inline construction paths; timer virtual slot points at `0x005148e0`. |

## Explicit Exclusions

The following generated contents should not be assigned to this source file without new evidence:

- [UID:0000NZ][SpelledPane](by-file/SpelledPane.md) entry-list methods at `0x0056bca0-0x0056c0da`.
- SpelledPane entry-vector insert/erase helpers at `0x00572fd0-0x00573231` and `0x00573900-0x00573961`.
- Shared text-control methods at `0x0058e270-0x005905f0`, which have broad callers and should be reviewed with [UID:0000ON][TextEditPane](by-file/TextEditPane.md) / [UID:0000OJ][TextBoxPane](by-file/TextBoxPane.md).

## Evidence Notes

- `simroot_v2/class_SelfSaveOKPane.meta_wave3` records 24 methods under this class, but IDA caller checks split those methods across at least three source families.
- IDA MCP confirms no direct callers to `0x005147d0` or `0x005148e0` in the current database, but `xrefs_to` confirms `0x005148e0` is present in the timer-facet vtable at `0x0061e850`.
- IDA MCP confirms the SelfSaveOKPane vtable bases are written by `0x005147d0`, [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md), and [UID:0000L3][MapPane](by-file/MapPane.md) packet case `0x21`. This resolves the earlier live/dead ambiguity enough to treat the small pane as packet-created UI.
- 2026-06-01 IDA MCP reconfirms `0x00513800`, `0x005147d0`, and `0x005148e0` boundaries, the three shared SelfSaveOKPane vtable writes, and the one-slot timer facet at `0x0061e850`. The project source tree already carries `ui/dialogs/SelfSaveOKPane.cpp`, so the file page now uses `NexusTK/ui/dialogs/` as the reconstruction path while keeping C++ blank in child pages.
- IDA MCP confirms the supposed SelfSave entry-list helpers are called by self-look/system-message paths and by `SpelledPane` refresh flow.
- 2026-05-26 IDA `py_eval` recheck confirms current active metadata still reports `vtable_count: 0` and `method_count: 24` for `SelfSaveOKPane`, while IDA shows the narrow pane island has three vtables and the extra methods have non-SelfSave caller evidence.

## Cross-References

- [UID:0000CX][SelfSaveOKPane](by-class/SelfSaveOKPane.md)
- [UID:0001B0][0x005147d0-0x00514914.SelfSaveOKPane](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md)
- [UID:0000NZ][SpelledPane](by-file/SpelledPane.md)
- [UID:0000OJ][TextBoxPane](by-file/TextBoxPane.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0001YV][SelfSaveOKPane_vtables](by-type/by-vtable/SelfSaveOKPane_vtables.md)
- [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md)
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md)
## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `78`.
  - Evidence: document captures the narrow pane island, packet-created construction paths, factory/helper, vtable refs, explicit generated-owner exclusions, IDA evidence, and cross-references; confidence is limited by final original file placement.
- 2026-06-01: Set `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` and raised confidence to `80`.
  Evidence: the proposed source tree includes `ui/dialogs/SelfSaveOKPane.cpp`, and IDA MCP reconfirms the compact SelfSaveOKPane constructor/factory/timer/vtable island plus MapPane packet-case construction evidence. Placement is now strong enough for child attachment, but still below final-source quality.
