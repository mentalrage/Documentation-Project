*** UID:0000SE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pTabPane

## Status

- Confidence: strong for address, lifecycle, and class owner; medium-high for final declaration owner.
- Address: `0x0069adfc`
- Current aliases: `dword_69ADFC`, `DAT_0069adfc`
- Kind: process-wide singleton pointer to [UID:0000EB][TabPane](by-class/TabPane.md)
- Proposed owner module: [UID:0000OF][TabPane](by-file/TabPane.md)
- Exact storage page: [UID:00029C][0x0069adfc-0x0069ae00.g_pTabPane](by-memory/0x0069adfc-0x0069ae00.g_pTabPane.md)
- Evidence basis: live IDA MCP xrefs and instruction windows, rechecked on 2026-05-30.

## Lifecycle

- `0x0069adfc` is a 4-byte `.data` item named `dword_69ADFC`; live IDA MCP reports 5 data xrefs.
- Set in `TabPane::TabPane` at `0x004cf9a4`.
- Cleared by the non-deleting cleanup helper at `0x004cf9ea`.
- Cleared by the scalar deleting destructor at `0x004cfe20`.
- Read during main UI shutdown at `0x00504936`.
- Also read by application/message handling at `0x0049e5e6`.

## Ownership Notes

This global tracks the active `TabPane` instance. It is adjacent to [UID:0000R6][g_pIconsPane](by-global/g_pIconsPane.md), but `0x0069adfc` is consistently written by `TabPane` lifecycle paths and should not be folded into `IconsPane` ownership.

## Assignment Gate

The global remains attached to [UID:0000OF][TabPane](by-file/TabPane.md). The direct file parent is now `86/85`, and this page is now `86/89`, so the corrected `85/85` gate is satisfied. The exact memory storage child [UID:00029C][0x0069adfc-0x0069ae00.g_pTabPane](by-memory/0x0069adfc-0x0069ae00.g_pTabPane.md) is the concrete four-byte `.data` slot for this global and can attach here without pulling in the neighboring `g_pSimpleHelpPane` slot.

## Data Caveats

Recovered class-output views can omit the cleanup helper and some compiler glue that also clear this global. Use the IDA-confirmed lifecycle above when migrating global ownership.

## Cross-References

- [UID:0000EB][TabPane](by-class/TabPane.md)
- [UID:0000OF][TabPane](by-file/TabPane.md)
- [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
- [UID:0000JZ][IconsPane](by-file/IconsPane.md)

## Changes

- 2026-06-05: Marked reconstructable and attached to [UID:0000OF][TabPane](by-file/TabPane.md) to resolve the global unclassified coverage row.
  - Reasoning: live IDA xrefs bind the singleton to the `TabPane` constructor, cleanup helper, scalar deleting destructor, application/message read, and main UI shutdown read. No score change and no reconstruction C++ were added.
- What existed before: this page had the correct lifecycle outline but unevaluated completion/confidence metadata and an evidence-basis line that mixed source output with IDA checks.
- What changed to: the page now cites live IDA MCP evidence for storage shape and all five direct xrefs. Completion/confidence were set to `82/88`.
- Summary and evidence: IDA MCP on 2026-05-30 verified `0x0069adfc` / `dword_69ADFC` as a 4-byte `.data` singleton pointer with five xrefs: application/message read at `0x0049e5e6`, constructor assignment at `0x004cf9a4`, cleanup clear at `0x004cf9ea`, scalar deleting destructor clear at `0x004cfe20`, and main UI shutdown read at `0x00504936`.
- 2026-06-07 A008 Batch 037 parent-gate refresh:
  - Changed to: `COMPLETION:86`, `CONFIDENCE:89`.
  - Summary/evidence: added the exact storage child [UID:00029C][0x0069adfc-0x0069ae00.g_pTabPane](by-memory/0x0069adfc-0x0069ae00.g_pTabPane.md) and documented the corrected assignment gate. The direct file parent [UID:0000OF][TabPane](by-file/TabPane.md) now clears `85/85`, while this global's direct five-xref lifecycle evidence already distinguishes it from adjacent `IconsPane` and `SimpleHelpPane` storage.
