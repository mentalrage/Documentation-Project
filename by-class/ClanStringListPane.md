*** UID:00002L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanStringListPane

## Status

- Confidence: strong for shared draw behavior and vtable evidence; medium for class reconstruction while the standalone constructor boundary remains projected.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Memory evidence: [UID:00010I][0x00488610-0x004888f0.ClanListPaneVirtuals](by-memory/0x00488610-0x004888f0.ClanListPaneVirtuals.md), [UID:0002NP][0x00488630-0x00488674.ClanStringListPaneRawConstructor](by-memory/0x00488630-0x00488674.ClanStringListPaneRawConstructor.md), [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md), and [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md)
- Current recovered file: `source-3/simroot_v2/class_ClanStringListPane.cpp`

## Class Purpose

`ClanStringListPane` is a small clan string-list base/variant for drawing clan-related strings. Its row draw implementation is reused by the `ClanJoinListPane` and `ClanEnlistListPane` vtables.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw constructor-shaped block | [UID:0002NP][0x00488630-0x00488674.ClanStringListPaneRawConstructor](by-memory/0x00488630-0x00488674.ClanStringListPaneRawConstructor.md) | Calls the shared list-pane base constructor and installs `ClanStringListPane` vtables; IDA reports this is not a function and has no xrefs. |
| `DrawItem` | [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) | Draws one clan string list row; shared by `ClanStringListPane`, `ClanJoinListPane`, and `ClanEnlistListPane` vtables. |

## Evidence Notes

- IDA MCP rechecked on 2026-05-24: `0x00488630` is not a function and has no xrefs.
- IDA confirms `DrawItem` at `0x004887d0` with size `0xf1`.
- IDA MCP recheck on 2026-05-26 reconfirms `DrawItem` at `0x004887d0-0x004888c1` and the absence of a function/xrefs at projected constructor start `0x00488630`.
- 2026-05-31 IDA MCP raw disassembly confirms `0x00488630-0x00488674` is a constructor-shaped block that installs `ClanStringListPane` vtables and returns `this`, with no IDA function object or inbound xrefs.
- 2026-05-31 IDA MCP split `DrawItem` into exact by-memory page [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md).
- `DrawItem` has data xrefs at `0x0061572c`, `0x006157f0`, and `0x006158b4`, corresponding to vtable slot `+0x80` for `ClanStringListPane`, `ClanJoinListPane`, and `ClanEnlistListPane`.
- The draw routine highlights selected rows with background color `128`, uses font/color `143`, truncates text with `L"..."` to `right - 50`, and draws at `x = 50` near the row vertical center.
- Adjacent function `0x004888d0-0x004888f0` is a `ClanJoinListPane` selected-row action vtable slot, not a generic `ClanStringListPane` method.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:00010I][0x00488610-0x004888f0.ClanListPaneVirtuals](by-memory/0x00488610-0x004888f0.ClanListPaneVirtuals.md)
- [UID:0002NP][0x00488630-0x00488674.ClanStringListPaneRawConstructor](by-memory/0x00488630-0x00488674.ClanStringListPaneRawConstructor.md)
- [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md)
- [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md)
- [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md)
- [UID:00002H][ClanJoinListPane](by-class/ClanJoinListPane.md)
- [UID:00002C][ClanEnlistListPane](by-class/ClanEnlistListPane.md)
- [Clan data issue note](../wave3_data_issues.md)

## Changes

- What existed before: the page documented shared row drawing, vtable data refs, and projected constructor caveats, but metadata was still `0/0`.
- What it was changed to: scores were set to `74/82`.
- Summary and evidence: shared renderer behavior and vtable evidence are strong; standalone constructor modeling and final class declaration remain incomplete.
- 2026-05-31: Replaced raw constructor/draw addresses with exact by-memory links. Evidence: IDA MCP `lookup_funcs`, `decompile`, `xrefs_to`, and raw disassembly split the constructor-shaped block and shared draw method into exact child pages.
