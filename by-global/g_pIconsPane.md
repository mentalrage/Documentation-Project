*** UID:0000R6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pIconsPane

## Status

- Confidence: strong for address, lifecycle, and owner; medium-high for final source declaration spelling.
- Address: `0x0069b41c`
- Exact storage doc: [UID:0002XU][0x0069b41c-0x0069b420.g_pIconsPane](by-memory/0x0069b41c-0x0069b420.g_pIconsPane.md)
- Current aliases: `dword_69B41C`, `DAT_0069b41c`
- Kind: process-wide singleton pointer to [UID:00006B][IconsPane](by-class/IconsPane.md)
- Likely type: `IconsPane*`
- Proposed owner module: [UID:0000JZ][IconsPane](by-file/IconsPane.md)
- Rebuild handling: source-declared module/global singleton pointer; exact address and binary initializer are rebuilt by the linker.
- Autogen parent: [UID:0000JZ][IconsPane](by-file/IconsPane.md); final C++ remains blank because the exact static declaration/header placement is below the `95+` source gate.
- Evidence basis: IDA MCP xrefs/decompilation.

## Lifecycle

- Set in `IconsPane::IconsPane` at `0x004cf215`.
- Cleared by the non-deleting cleanup helper at `0x004cf260`.
- Cleared by the scalar deleting destructor at `0x004cfda0`.
- Read during main UI shutdown at `0x00504a07`.
- Read by option UI paths around `0x0053da72` and `0x0053dec2`, which call `IsShowingAllIcons`, `ShowAllIcons`, and `ShowReducedIcons`.

## Evidence Table

| Site | Use | Evidence owner |
| --- | --- | --- |
| `0x004cf215` | Constructor stores the active `IconsPane` singleton. | [UID:00016Z][0x004cf1f0-0x004cf8d5.IconsPaneCore](by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md) and [UID:0000JZ][IconsPane](by-file/IconsPane.md). |
| `0x004cf260` | Non-deleting cleanup helper clears the singleton while restoring IconsPane vtables. | Same IconsPane core range and file owner. |
| `0x004cfda0` | Scalar deleting destructor clears the singleton before base cleanup/delete handling. | [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md). |
| `0x00504a07` | Main UI shutdown reads the pointer before child removal. | Main UI graph shutdown consumer; lifecycle owner remains `IconsPane.cpp`. |
| `0x0053da72`, `0x0053dec2` | Option UI reads the pointer to query/toggle full/reduced icon mode. | External option-panel consumers of the old-layout icon strip. |

## Ownership Notes

This global is the singleton for the old-layout icon strip. It should be owned by `IconsPane.cpp`, not by [UID:0000OF][TabPane](by-file/TabPane.md), even though the two classes are adjacent and their destructor thunks are interleaved.

Keep the singleton with `IconsPane.cpp` rather than `OptionPane.cpp` or main UI graph ownership. Those modules read or remove the pane; constructor/cleanup/destructor code owns the storage lifetime.

## Data Caveats

The main UI shutdown and option UI consumers sit outside the `IconsPane` lifecycle island, so use the IDA-confirmed lifecycle above and the memory pages when migrating global ownership.

## Cross-References

- [UID:00006B][IconsPane](by-class/IconsPane.md)
- [UID:0000JZ][IconsPane](by-file/IconsPane.md)
- [UID:00016Z][0x004cf1f0-0x004cf8d5.IconsPaneCore](by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md)
- [UID:0002XU][0x0069b41c-0x0069b420.g_pIconsPane](by-memory/0x0069b41c-0x0069b420.g_pIconsPane.md)
- [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
- [UID:0000R4][g_pHourPane](by-global/g_pHourPane.md)

## Changes

- 2026-06-06 A010 singleton evidence consolidation:
  - Before: `COMPLETION:82`, `CONFIDENCE:78`, with lifecycle bullets but no explicit rebuild handling, likely pointer type, source-gate note, or evidence table.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`, source-declared singleton handling, likely `IconsPane*` type, final declaration caveat, lifecycle/user evidence table, and clearer owner separation from `TabPane`, `OptionPane`, and main UI shutdown.
  - Summary/evidence: existing IDA-backed docs record constructor store at `0x004cf215`, cleanup/destructor clears at `0x004cf260` and `0x004cfda0`, shutdown read at `0x00504a07`, and option UI reads at `0x0053da72` and `0x0053dec2`; the by-file page owns the old-layout icon strip under `NexusTK/ui/panels/`.
- 2026-05-30: Changed completion/confidence from `0/0` to `82/78`.
  - Before: The page had strong lifecycle/address notes but was unscored and still described active output as omitting helper functions that clear the singleton.
  - After: The page records that constructor, cleanup helper, and scalar deleting destructor singleton writes/clears are known, while consumer paths remain outside this file.
  - Evidence: IDA notes record writes/clears at `0x004cf1f0`, `0x004cf260`, and `0x004cfda0`, plus reads from main UI shutdown and option UI paths.
- 2026-06-05: Marked reconstructable under [UID:0000JZ][IconsPane](by-file/IconsPane.md). Evidence: live IDA MCP reports six xrefs to `0x0069b41c`; decompilation confirms constructor `0x004cf1f0`, cleanup helper `0x004cf260`, and scalar deleting destructor `0x004cfda0` write/clear `dword_69B41C`.
- 2026-06-07 A007 Batch 041 split-link update: added the exact by-memory storage doc [UID:0002XU][0x0069b41c-0x0069b420.g_pIconsPane](by-memory/0x0069b41c-0x0069b420.g_pIconsPane.md) after the mixed Hour/Icons singleton range was split into separate `HourPane` and `IconsPane` slots.
