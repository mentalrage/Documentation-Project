*** UID:0000PX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_equipmentSlotKeys / word_630BD8

## Status

- Confidence: strong for address, fixed table contents, exact memory child, `TakeOffInputPane` use, and direct `ItemActionInputPanes` parent; medium-high for final source-level symbol spelling.
- Address: `0x00630bd8`
- Size: `0x2e` / decimal `46` bytes (Verified with `int_convert.py`), 23 UTF-16 code units
- IDA name: `word_630BD8`
- Primary memory doc: [UID:0001OF][0x00630bd8-0x00630c06.g_equipmentSlotKeys](by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md)
- Likely owner: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) or shared equipment-action command code.

## Purpose

This table maps one-character equipment take-off input keys to one-based equipment selector values. [UID:0000EC][TakeOffInputPane](by-class/TakeOffInputPane.md) scans 23 entries and sends selector index `+1` when the typed character matches, using opcode `0x1f` / decimal `31` (Verified with `int_convert.py`) for the single-slot removal path.

Observed UTF-16 contents:

```text
wash#nlr####fm#c###[]12
```

The `#` entries are placeholder or unused selector slots. The table is not a C string terminator-delimited value; it is a fixed 23-entry lookup table.

## Selector Mapping

| Selector | Key | Notes |
| ---: | --- | --- |
| 1 | `w` | Valid single-slot removal key. |
| 2 | `a` | Valid single-slot removal key; distinct from uppercase `A` all-equipment command. |
| 3 | `s` | Valid single-slot removal key. |
| 4 | `h` | Valid single-slot removal key. |
| 5 | `#` | Placeholder/unused slot. |
| 6 | `n` | Valid single-slot removal key. |
| 7 | `l` | Valid single-slot removal key. |
| 8 | `r` | Valid single-slot removal key. |
| 9-12 | `#` | Placeholder/unused slots. |
| 13 | `f` | Valid single-slot removal key. |
| 14 | `m` | Valid single-slot removal key. |
| 15 | `#` | Placeholder/unused slot. |
| 16 | `c` | Valid single-slot removal key. |
| 17-19 | `#` | Placeholder/unused slots. |
| 20 | `[` | Valid single-slot removal key. |
| 21 | `]` | Valid single-slot removal key. |
| 22 | `1` | Valid single-slot removal key. |
| 23 | `2` | Valid single-slot removal key. |

The typed all-equipment branch is not a table entry. The command handler compares the input wchar to `0x0041` / decimal `65` (`A`) (Verified with `int_convert.py`) before iterating the fixed selector set.

## Evidence Notes

- IDA `py_eval` on 2026-05-27 read 23 UTF-16 words at `0x00630bd8` and produced the fixed key string above.
- IDA `xrefs_to 0x00630bd8` reports a data reference from `0x005b28f0` inside `TakeOffInputPane::ProcessUnequipCommand`.
- IDA decompilation of `0x005b2830` compares a one-character input against `word_630BD8[index]` and sends selector `index + 1` via opcode `0x1f`.
- [UID:0001OF][0x00630bd8-0x00630c06.g_equipmentSlotKeys](by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md) records the exact `0x00630bd8-0x00630c06` range, predecessor/successor boundaries, placeholder selector semantics, and source-declared/generated-binary rebuild handling.
- [UID:0001M1][0x005b2720-0x005b296b.TakeOffInputPane](by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md) records the command handler, `A` all-equipment branch, table scan, `g_activeDialogCount` gate, and selector list.
- 2026-06-11 A001 live IDA MCP refresh attempt: the combined `xrefs_to 0x00630bd8`, `decompile 0x005b2830`, and `lookup_funcs` request timed out with `Invoke-WebRequest -TimeoutSec 30`; follow-up individual `xrefs_to 0x00630bd8` and `lookup_funcs` requests also timed out after `15` seconds each. No new live-IDB claim is introduced by this pass.

## Assignment Decision

Keep `AUTOGEN_PARENT_UID:0000KC` on [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md). This table is source-declared data used by the equipment-removal command path; the global page now clears `88/86`, and the direct file parent is `90/85`, so the strict child/direct-parent `85/85` gate is satisfied.

Do not attach the table directly to [UID:0000EC][TakeOffInputPane](by-class/TakeOffInputPane.md). The class page documents the only known consumer, but the table is a fixed source-level lookup object whose current rebuild placement is better represented as file-level equipment-action command data until final declaration spelling is proven.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 88 | Exact address/range, byte size, fixed UTF-16 contents, selector mapping, placeholder semantics, opcode/all-equipment distinction, memory child, consumer class/method, source-module parent, and gate rationale are documented. |
| Confidence | 86 | Prior written IDA evidence proves contents, xref, and consumer behavior, and supporting pages document boundaries and ownership. Confidence remains below higher scores because this pass's live IDA refresh timed out and the original C++ symbol spelling/declaration form is still inferred. |

## Cross-References

- [UID:0001OF][0x00630bd8-0x00630c06.g_equipmentSlotKeys](by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md)
- [UID:0000EC][TakeOffInputPane](by-class/TakeOffInputPane.md)
- [UID:0001M1][0x005b2720-0x005b296b.TakeOffInputPane](by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md)
- [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md)
- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0000PQ][g_activeDialogCount](by-global/g_activeDialogCount.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/80`. Summary/evidence: the page documents address, fixed UTF-16 table contents, take-off command behavior, IDA table/xref/decompilation evidence, memory refs, and source-owner caveat.
- 2026-06-05: Marked reconstructable under [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md). Evidence: live IDA MCP reports the only xref to `0x00630bd8` at `0x005b28f0` inside `0x005b2830`, and decompilation shows `word_630BD8[index]` used by the TakeOff input path before sending selector `index + 1`.
- 2026-06-11 A001 gate and selector refresh:
  - Changed scores from `86/80` to `88/86`.
  - Summary/evidence: added verified `0x2e`/`0x1f`/`0x0041` conversions, selector-by-selector mapping, supporting memory-child and TakeOff command links, explicit assignment decision, and score rationale. Current-session live IDA MCP refresh timed out as documented above, so the score increase relies on existing written 2026-05-27/2026-06-02 IDA evidence and supporting pages rather than new live output.
