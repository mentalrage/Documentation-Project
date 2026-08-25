*** UID:0000PX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_equipmentSlotKeys / word_630BD8

## Status

- Confidence: strong for address, fixed table contents, exact memory child, `TakeOffInputPane` use, direct `ItemActionInputPanes` parent, and current MCP source-declaration evidence; medium-high for final source-level symbol spelling.
- Address: `0x00630bd8`
- Size: `0x2e` / decimal `46` bytes (Verified with `int_convert.py`), 23 UTF-16 code units
- IDA name: `word_630BD8`
- Primary memory doc: [UID:0001OF][0x00630bd8-0x00630c06.g_equipmentSlotKeys](by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md)
- Likely owner/emitter: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md). The exact emitted table definition is carried by [UID:0001OF][0x00630bd8-0x00630c06.g_equipmentSlotKeys](by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md), while this page remains the semantic global/route record.

## Purpose

This table maps one-character equipment take-off input keys to one-based equipment selector values. [UID:0000EC][TakeOffInputPane](by-class/TakeOffInputPane.md) scans 23 entries and sends selector index `+1` when the typed character matches, using opcode `0x1f` / decimal `31` (Verified with `int_convert.py`) for the single-slot removal path.

[UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md) consumes the same selector numbering through caller-provided constants, but it does not read this table directly. The helper sends the selector byte it receives; `TakeOffInputPane::ProcessUnequipCommand` performs the table scan for typed single-slot commands and emits that packet inline, while the uppercase `A` all-equipment branch calls the helper for the valid selector set.

Observed UTF-16 contents:

```text
wash#nlr####fm#c###[]12
```

The `#` entries are placeholder or unused selector slots. The table is not a C string terminator-delimited value; it is a fixed 23-entry lookup table.

The source-facing declaration is now represented by [UID:0001OF][0x00630bd8-0x00630c06.g_equipmentSlotKeys](by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md) as `static const wchar_t g_equipmentSlotKeys[23]`. This global page intentionally emits only a `[[CHILDREN]]` insertion point so the exact memory child contributes the table declaration through the existing route without duplicating the table on the semantic symbol page. The earlier plain comment marker did not assemble the routed child and is superseded by this by-structure-compliant child insertion route.

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
- B006 2026-06-21 source-quality recheck of [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md) confirms the helper parameter should be named `equipmentSlotSelector`, and that the helper shares this table's one-based selector IDs without owning or reading the table.
- 2026-06-28 B014 current MCP session `agent_b009_0002my_20260628` replaces the older live-MCP-timeout caveat. `server_health` was `ok` with auto-analysis and Hex-Rays ready. `get_bytes 0x00630bd8 size 46` returned the exact 23 UTF-16 code units for `w a s h # n l r # # # # f m # c # # # [ ] 1 2`; `get_string 0x00630bd8` returned only `"w"`, proving IDA string typing is not the right representation; `xrefs_to` and bidirectional `xref_query` found the one data xref at `0x005b28f0`; the complete 46-byte table pattern was unique at `0x00630bd8`; and the only `D8 0B 63 00` hit was the address operand at `0x005b28f4`, not an independent pointer table.
- The same B014 pass reconfirmed `sub_5B2830` size `0x13b`, the `word_630BD8[index]` scan bounded by `0x17` / 23 entries, the uppercase `A` all-equipment branch, selector `index + 1`, opcode `0x1f`, and length `2`. Boundary reads keep the range as exactly `0x00630bd8-0x00630c06`: the predecessor ends before the table, and the successor starts with a zero word followed by `Invalid...`.

## Assignment Decision

Keep `CANONICAL_OWNER:0000KC` and `EMITTER_UIDS:0000KC`. This table is source-declared data used by the equipment-removal command path; the global page now clears `90/90`, the direct file parent is `90/85`, and the exact memory child [UID:0001OF][0x00630bd8-0x00630c06.g_equipmentSlotKeys](by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md) emits the table definition under this route.

Do not attach the table directly to [UID:0000EC][TakeOffInputPane](by-class/TakeOffInputPane.md). The class page documents the only known consumer, but the table is fixed module-scope lookup data, not instance state or a proven class-static member. Do not duplicate the table declaration in this global page; [UID:0001OF][0x00630bd8-0x00630c06.g_equipmentSlotKeys](by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md) carries the exact source definition, and this page's `[[CHILDREN]]` marker is only the generated-output insertion point for that routed child.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 90 | Exact address/range, byte size, fixed UTF-16 contents, selector mapping, placeholder semantics, opcode/all-equipment distinction, memory child, consumer class/method, source-module parent, route rationale, current MCP evidence, and non-duplicating child insertion route are documented. |
| Confidence | 90 | Current B014 MCP evidence proves contents, xref, unique full-pattern match, scan semantics, and boundary placement. Confidence remains below higher scores because the original C++ symbol spelling is still inferred and broader consumer method helper names/return convention remain separate source-quality work. |

## Cross-References

- [UID:0001OF][0x00630bd8-0x00630c06.g_equipmentSlotKeys](by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md)
- [UID:0000EC][TakeOffInputPane](by-class/TakeOffInputPane.md)
- [UID:0001M1][0x005b2720-0x005b296b.TakeOffInputPane](by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md)
- [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md)
- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0000PQ][g_activeDialogCount](by-global/g_activeDialogCount.md)

## Changes

- 2026-06-28 B014 accepted source-quality implementation:
  - Changed scores from `88/86` to `90/90`, kept owner/emitter [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md), and inserted the non-duplicating marker `// Emitted code for g_equipmentSlotKeys is covered by [UID:0001OF][0x00630bd8-0x00630c06.g_equipmentSlotKeys](by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md).`.
  - Evidence: current MCP session `agent_b009_0002my_20260628` confirms health, exact 46 bytes, one xref at `0x005b28f0`, unique full-table byte pattern, `get_string` one-character caveat, `sub_5B2830` scan semantics, selector `index + 1`, and exact predecessor/successor boundaries. [UID:0001OF][0x00630bd8-0x00630c06.g_equipmentSlotKeys](by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md) owns the emitted table declaration.
- 2026-06-28 B014 correction callback:
  - Replaced the plain non-duplicating comment marker with `[[CHILDREN]]` because validator/by-structure generated assembly requires an explicit child insertion point for [UID:0001OF][0x00630bd8-0x00630c06.g_equipmentSlotKeys](by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md)'s formal table declaration to appear under this semantic global route. This preserves the same owner/emitter chain, keeps the table declaration only on the exact memory child, and avoids a duplicate declaration on this global page.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/80`. Summary/evidence: the page documents address, fixed UTF-16 table contents, take-off command behavior, IDA table/xref/decompilation evidence, memory refs, and source-owner caveat.
- 2026-06-05: Marked reconstructable under [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md). Evidence: live IDA MCP reports the only xref to `0x00630bd8` at `0x005b28f0` inside `0x005b2830`, and decompilation shows `word_630BD8[index]` used by the TakeOff input path before sending selector `index + 1`.
- 2026-06-11 A001 gate and selector refresh:
  - Changed scores from `86/80` to `88/86`.
  - Summary/evidence: added verified `0x2e`/`0x1f`/`0x0041` conversions, selector-by-selector mapping, supporting memory-child and TakeOff command links, explicit assignment decision, and score rationale. Current-session live IDA MCP refresh timed out as documented above, so the score increase relies on existing written 2026-05-27/2026-06-02 IDA evidence and supporting pages rather than new live output.
- 2026-06-21 B006 SendTakeOffPacket support sync:
  - Documented that [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md) uses the same one-based selector domain by argument/caller constants but does not read the table directly. No score or ownership change.
