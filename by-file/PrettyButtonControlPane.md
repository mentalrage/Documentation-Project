*** UID:0000MP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# PrettyButtonControlPane

## Status

- Confidence: strong for two-class grouping, generic controls placement, executable/vtable boundaries, and constructor fan-in; medium for final field/resource/callback naming.
- Proposed module: `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.
- Current recovered sources: `source-3/simroot_v2/class_PrettyButtonControlPane.cpp` and `class_PrettyButtonControlPane2.cpp`.
- Exact executable cluster: [UID:0001F9][0x0054b5e0-0x0054bcbd.PrettyButtonControls](by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md)
- Exact vtable data: [UID:0002UW][0x006222d8-0x00622378.PrettyButtonControlPaneVtableData](by-memory/0x006222d8-0x00622378.PrettyButtonControlPaneVtableData.md) and [UID:0002UX][0x00622378-0x0062241c.PrettyButtonControlPane2VtableData](by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md)

## File Role

`PrettyButtonControlPane` and `PrettyButtonControlPane2` are styled button variants that extend the generic button/text-button control family with custom EPF/PAL frame selection, hover/press animation, callback ownership, and special disabled-state rendering.

They are address-local around `0x0054b5e0-0x0054bcbd` and both call into the base button-control construction path. IDA MCP reports 30 direct xrefs to the `PrettyButtonControlPane` constructor and 2 direct xrefs to the `PrettyButtonControlPane2` constructor.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `PrettyButtonControlPane` | `0x0054b5e0-0x0054b878`, `0x0054bb9f-0x0054bcbd` | Styled button with callback object, hover/enable state, frame rendering, click handling, and destructor. |
| `PrettyButtonControlPane2` | `0x0054b8c0-0x0054bc3c` | Alternate styled button using explicit EPF/PAL file strings and normal/pressed/hover/disabled frame ids. |
| `PrettyButtonControlPane` vtables | `0x006222d8-0x00622378` | Source-declared/generated-binary data with primary, secondary, and tertiary vtable views. |
| `PrettyButtonControlPane2` vtables | `0x00622378-0x0062241c` | Source-declared/generated-binary data with primary, secondary, and tertiary vtable views. |

## Source Placement And Boundaries

- Keep the source root under `NexusTK/ui/controls/` beside [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md). Both constructors call the generic button-control construction path at `0x00494eb0`, and the caller fan-in points to a reusable control family rather than a single feature dialog.
- Treat the exact vtable pages as class declaration output. Recreate their source semantics through the two class declarations and virtual method implementations, not by hand-porting `.rdata` bytes.
- Keep the lower neighbor [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md) outside this source root; the executable cluster begins after `0x0054b5d5-0x0054b5e0` alignment.
- Keep the upper neighbor [UID:0001FA][0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt](by-memory/0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt.md) outside this source root; `0x0054bcbd-0x0054bcc0` is alignment after the pretty-button destructor/thunk tail.
- Preserve the `0x006222d4` primary-RTTI boundary caveat documented by the read-only-data pages. The current exact `PrettyButtonControlPane` vtable child starts at the first vtable label `0x006222d8`, while the RTTI locator dword sits in the prior [UID:000266][0x00622158-0x006222d8.PowerPaneReadOnlyData](by-memory/0x00622158-0x006222d8.PowerPaneReadOnlyData.md) aggregate boundary.

## Evidence Notes

- Both constructors call through the generic `ButtonControlPane` path at `0x00494eb0`.
- Both classes use the same small address neighborhood and destructor thunk pattern.
- The proposed source tree already places this source beside `ButtonControlPane.cpp` under `ui/controls`, and the page documents generic styled-button behavior rather than a feature-local dialog implementation.
- The read-only data page [UID:000267][0x006222d8-0x006224c0.ButtonPrimePursuitReadOnlyData](by-memory/0x006222d8-0x006224c0.ButtonPrimePursuitReadOnlyData.md) records the adjacent `PrettyButtonControlPane` and `PrettyButtonControlPane2` vtable blocks.
- [UID:0001F9][0x0054b5e0-0x0054bcbd.PrettyButtonControls](by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md) now records both class method clusters, constructor fan-in, rebuild handling, generic control ownership, and the final destructor endpoint `0x0054bcbd`.
- [UID:0002UW][0x006222d8-0x00622378.PrettyButtonControlPaneVtableData](by-memory/0x006222d8-0x00622378.PrettyButtonControlPaneVtableData.md) records three `PrettyButtonControlPane` vtable bases, constructor/destructor store xrefs, draw/state/click slots, and the next-class boundary at `0x00622378`.
- [UID:0002UX][0x00622378-0x0062241c.PrettyButtonControlPane2VtableData](by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md) records three `PrettyButtonControlPane2` vtable bases, constructor/destructor store xrefs, state/draw/click slots, and the `PrimeNumberGenerator` RTTI boundary at `0x0062241c`.
- The generated summaries mention user-creation dialogs, but the current documentation keeps the placement in generic controls until caller clustering is reviewed more broadly.
- 2026-06-07 A001 IDA MCP `lookup_funcs` confirms modeled functions for the two constructor islands, virtual slots, and scalar deleting destructors: `0x0054b5e0` size `0xc4`, `0x0054b750` size `0x62`, `0x0054b7c0` size `0xb9`, `0x0054b880` size `0x39`, `0x0054b8c0` size `0xcd`, `0x0054ba30` size `0x62`, `0x0054baa0` size `0xa8`, `0x0054bb50` size `0x39`, `0x0054bbc0` size `0x7d`, and `0x0054bc40` size `0x7d`.
- 2026-06-07 A001 IDA MCP caller review confirms the constructor fan-in remains broad and UI-control-like: `PrettyButtonControlPane` constructor `0x0054b5e0` has 30 direct callers clustered in three creation functions (`0x0052a540`, `0x0052c360`, `0x0052dd30`), while `PrettyButtonControlPane2` constructor `0x0054b8c0` has two direct callers in `0x0052c360`. The scalar deleting destructors have no direct call sites, matching vtable-driven destruction.
- 2026-06-07 A001 IDA MCP callee review confirms both constructors call the shared base button-control construction path `0x00494eb0` plus shared string/object helper `0x00582560`, while both scalar deleting destructors call common callback/object/string cleanup helpers and guard-check glue. This supports a reusable controls module rather than a feature-dialog owner.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | The page records the two styled-button classes, executable cluster, exact vtable children, generic button-constructor dependency, constructor fan-in, modeled function boundaries, neighboring boundaries, `0x006222d4` RTTI caveat, projected `NexusTK/ui/controls/` path, and final-source blockers. It stays at the low end of high completion because exact field/resource/callback names and final C++ are not ready. |
| Confidence | 86 | Fresh 2026-06-07 MCP checks now confirm the function boundaries, constructor caller pattern, base-constructor callees, destructor cleanup callees, and exact vtable children. Confidence remains below final-audit range because the class pages still need exact field/resource/callback naming and the primary RTTI locator boundary correction remains open. |

## Cross-References

- [UID:0000AR][PrettyButtonControlPane](by-class/PrettyButtonControlPane.md)
- [UID:0000AS][PrettyButtonControlPane2](by-class/PrettyButtonControlPane2.md)
- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:0001F9][0x0054b5e0-0x0054bcbd.PrettyButtonControls](by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md)
- [UID:000267][0x006222d8-0x006224c0.ButtonPrimePursuitReadOnlyData](by-memory/0x006222d8-0x006224c0.ButtonPrimePursuitReadOnlyData.md)
- [UID:0002UW][0x006222d8-0x00622378.PrettyButtonControlPaneVtableData](by-memory/0x006222d8-0x00622378.PrettyButtonControlPaneVtableData.md)
- [UID:0002UX][0x00622378-0x0062241c.PrettyButtonControlPane2VtableData](by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md)

## Changes

- 2026-06-07 A001 parent-gate update:
  - What existed before: scores were `82/84`, the page still recorded a current-session MCP-unavailable limitation, and [UID:0002UW][0x006222d8-0x00622378.PrettyButtonControlPaneVtableData](by-memory/0x006222d8-0x00622378.PrettyButtonControlPaneVtableData.md) could not be assigned because the direct file parent was below `85/85`.
  - Changed to: completion `85`, confidence `86`, current IDA MCP boundary/caller/callee evidence, and parent-gate support for assigning the exact `PrettyButtonControlPane` vtable-data child to this file root.
  - Summary/evidence: 2026-06-07 A001 MCP checks confirm modeled method boundaries for both styled-button classes, 30 direct callers for `0x0054b5e0`, 2 direct callers for `0x0054b8c0`, shared base button-constructor callees, destructor cleanup callees, and the existing exact vtable child evidence. The page remains below final-source quality because field/resource/callback names and the `0x006222d4` boundary correction are still open.
- 2026-06-07 A010 evidence consolidation:
  - What existed before: scores were `80/82`; the page had generic control placement and broad executable/vtable aggregate links but did not summarize the exact vtable children, `0x006222d4` RTTI boundary caveat, or neighboring source boundaries.
  - Changed to: completion `82`, confidence `84`.
  - Summary/evidence: integrated [UID:0001F9][0x0054b5e0-0x0054bcbd.PrettyButtonControls](by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md), [UID:0002UW][0x006222d8-0x00622378.PrettyButtonControlPaneVtableData](by-memory/0x006222d8-0x00622378.PrettyButtonControlPaneVtableData.md), and [UID:0002UX][0x00622378-0x0062241c.PrettyButtonControlPane2VtableData](by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md) into the file-source summary. IDA MCP was unavailable in this session, and final C++ remains blocked by field/resource/callback naming.
- Before: the `PrettyButtonControlPane` destructor/thunk coverage ended at `0x0054bcbc`.
- Changed to: the destructor/thunk coverage and containing memory page end at `0x0054bcbd`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows `0x0054bcbc` is the final operand byte of the `retn 4` in `sub_54BC40`; `0x0054bcbd-0x0054bcc0` is alignment padding before `PrimeNumberGeneratorGetPrimeAt`.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `76`, confidence `72`.
- Summary/evidence: the page documents the two-class grouping, constructor caller count, address-locality evidence, range correction, and basic cross-references; scores remain lower because method-level behavior, resource details, and caller clustering are still summarized.

- Before: `PROPOSED_RECONSTRUCTION_PATH` was blank, keeping the file-root autogen entry in error state.
- Changed to: projected path `NexusTK/ui/controls/`, completion `80`, and confidence `82`.
- Summary/evidence: existing project-structure documentation places `PrettyButtonControlPane.cpp` under `ui/controls` beside `ButtonControlPane.cpp`; this page now records that path, links the executable cluster and read-only vtable aggregate, and keeps the score below final-source levels because exact fields, resource constants, and caller clustering still need deeper review.
