*** UID:0000MP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# PrettyButtonControlPane

## Status

- Confidence: strong for two-class grouping and generic controls placement, medium for final field/resource naming.
- Proposed module: `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.
- Current recovered sources: `source-3/simroot_v2/class_PrettyButtonControlPane.cpp` and `class_PrettyButtonControlPane2.cpp`.

## File Role

`PrettyButtonControlPane` and `PrettyButtonControlPane2` are styled button variants that extend the generic button/text-button control family with custom EPF/PAL frame selection, hover/press animation, callback ownership, and special disabled-state rendering.

They are address-local around `0x0054b5e0-0x0054bcbd` and both call into the base button-control construction path. IDA MCP reports 30 direct xrefs to the `PrettyButtonControlPane` constructor and 2 direct xrefs to the `PrettyButtonControlPane2` constructor.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `PrettyButtonControlPane` | `0x0054b5e0-0x0054b878`, `0x0054bb9f-0x0054bcbd` | Styled button with callback object, hover/enable state, frame rendering, click handling, and destructor. |
| `PrettyButtonControlPane2` | `0x0054b8c0-0x0054bc3c` | Alternate styled button using explicit EPF/PAL file strings and normal/pressed/hover/disabled frame ids. |

## Evidence Notes

- Both constructors call through the generic `ButtonControlPane` path at `0x00494eb0`.
- Both classes use the same small address neighborhood and destructor thunk pattern.
- The proposed source tree already places this source beside `ButtonControlPane.cpp` under `ui/controls`, and the page documents generic styled-button behavior rather than a feature-local dialog implementation.
- The read-only data page [UID:000267][0x006222d8-0x006224c0.ButtonPrimePursuitReadOnlyData](by-memory/0x006222d8-0x006224c0.ButtonPrimePursuitReadOnlyData.md) records the adjacent `PrettyButtonControlPane` and `PrettyButtonControlPane2` vtable blocks.
- The generated summaries mention user-creation dialogs, but the current documentation keeps the placement in generic controls until caller clustering is reviewed more broadly.

## Cross-References

- [UID:0000AR][PrettyButtonControlPane](by-class/PrettyButtonControlPane.md)
- [UID:0000AS][PrettyButtonControlPane2](by-class/PrettyButtonControlPane2.md)
- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:0001F9][0x0054b5e0-0x0054bcbd.PrettyButtonControls](by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md)
- [UID:000267][0x006222d8-0x006224c0.ButtonPrimePursuitReadOnlyData](by-memory/0x006222d8-0x006224c0.ButtonPrimePursuitReadOnlyData.md)

## Changes

- Before: the `PrettyButtonControlPane` destructor/thunk coverage ended at `0x0054bcbc`.
- Changed to: the destructor/thunk coverage and containing memory page end at `0x0054bcbd`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows `0x0054bcbc` is the final operand byte of the `retn 4` in `sub_54BC40`; `0x0054bcbd-0x0054bcc0` is alignment padding before `PrimeNumberGeneratorGetPrimeAt`.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `76`, confidence `72`.
- Summary/evidence: the page documents the two-class grouping, constructor caller count, address-locality evidence, range correction, and basic cross-references; scores remain lower because method-level behavior, resource details, and caller clustering are still summarized.

- Before: `PROPOSED_RECONSTRUCTION_PATH` was blank, keeping the file-root autogen entry in error state.
- Changed to: projected path `NexusTK/ui/controls/`, completion `80`, and confidence `82`.
- Summary/evidence: existing project-structure documentation places `PrettyButtonControlPane.cpp` under `ui/controls` beside `ButtonControlPane.cpp`; this page now records that path, links the executable cluster and read-only vtable aggregate, and keeps the score below final-source levels because exact fields, resource constants, and caller clustering still need deeper review.
