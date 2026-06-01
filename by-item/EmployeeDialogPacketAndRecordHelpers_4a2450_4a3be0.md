*** UID:0000UL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0

## Status

- Confidence: strong for `0x004a2450`, `0x004a2f60`, and `0x004a34d0`; medium for raw-code-shaped `0x004a3be0`.
- IDA caveat: `0x004a3be0` has a normal prologue/body and internal behavior matching the dispatcher upsert path, but IDA has no function object at that address and no direct xrefs to that start. Treat it as an observed raw-code helper until a real entry boundary is proven.
- Proposed owner file: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- Exact memory range: [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)

## Helper Summary

| Address range | Proposed name | Behavior |
| --- | --- | --- |
| `0x004a2450-0x004a2531` | `HandleEmployeeInventoryItem` | Looks up selected item metadata through `dword_67A748`, clears `this[264]`, opens [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md) when the item requires a count, or sends employee command `5` directly through `sub_5975E0`. |
| `0x004a2f60-0x004a322c` | `HandleEmployeeDialogPacket` | Handles employee response packet `0x4f/0x01`, validates the employee entity id at `this+0x7a8`, dispatches cases `0..4`, and repaints after record/status mutations. |
| `0x004a34d0-0x004a3644` | `DeserializeEmployeeRecord` | Parses one variable-length employee record into a `0x41c` `EmployeeRecord`, converts the name to wide text, appends percent text when the packet percent byte is not `0xff`, and returns bytes consumed. |
| `0x004a3be0-0x004a3c9f` | `UpdateEmployeeRecord` | Raw code-shaped helper that parses one record, searches the `this+0x84c` record array by id or empty slot, copies `0x41c` bytes into the target slot, rebuilds the list, and invalidates/repaints through the pane vtable. |

## IDA MCP Evidence

Checked on 2026-05-30:

- `ida_funcs.get_func` reports `sub_4A2450` as `0x004a2450-0x004a2531` size `225`, `sub_4A2F60` as `0x004a2f60-0x004a322c` size `716`, and `sub_4A34D0` as `0x004a34d0-0x004a3644` size `372`.
- `0x004a2450` has no direct xrefs. Hex-Rays shows it reading the selected item id from the packet byte, using `dword_67A748` item metadata, opening quantity dialog object id `628` for count-required items, otherwise sending command `5` with item slot/count data.
- `0x004a2f60` has a data/vtable xref at `0x00618f70` and no direct code callers. Hex-Rays shows packet-byte gates `0x4f` then `0x01`, entity-id validation against `this+0x7a8`, and a five-case subcommand switch.
- `0x004a2f60` case `0` loads the full list through `sub_4A3A90`; case `1` upserts a parsed record and repaints; case `2` marks a matching record removed by clearing id and setting state word `1`; case `3` delegates to `sub_4A3E10`; case `4` copies a multibyte status string into a wide buffer at `this+0x4a8` and repaints.
- `0x004a34d0` is called from `0x004a300d` in `sub_4A2F60`, `0x004a3bb1` in `sub_4A3A90`, and raw code at `0x004a3c05`. Hex-Rays shows it writing id, state, flag, wide name, display percent suffix, and trailing DWORD fields at `0x40c`, `0x410`, and `0x414`.
- `ida_funcs.get_func(0x004a3be0)` returns no function and xrefs to that start are empty. Disassembly still shows a full prologue/body: stack allocation `0x420`, call to `sub_4A34D0`, scan of `[this+0x538]` records at `[this+0x84c]` with stride `0x41c`, record copy via `rep movsd`/`0x107` dwords, call to `sub_4A33E0`, and a repaint/invalidate virtual call through vtable offset `+0x20`.

## Ownership Decision

These helpers belong with `EmployeeDialogPane.cpp`. They should not be folded into generic packet infrastructure or `ItemDialogs.cpp`: every data path references the employee dialog entity id, employee record array, selected-slot state, or employee command interface.

## Cross-References

- [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- [UID:00004C][EmployeeDialogPane](by-class/EmployeeDialogPane.md)
- [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)
- [UID:0001UD][EmployeeRecord](by-type/by-struct/EmployeeRecord.md)

## Changes

- Before: the page had `COMPLETION:0` and `CONFIDENCE:0`, used older 2026-05-24/25 evidence, and described `0x004a3be0` partly in terms of generated output behavior.
- Changed to: `COMPLETION:70` and `CONFIDENCE:82`, with current IDA-backed function bounds, xrefs, dispatcher cases, and raw-code caveat for `0x004a3be0`.
- Summary/evidence: IDA MCP on 2026-05-30 confirmed real function objects for `0x004a2450`, `0x004a2f60`, and `0x004a34d0`, confirmed only a data/vtable xref for `0x004a2f60`, confirmed `0x004a34d0` callers including raw `0x004a3c05`, and confirmed no function object/xrefs for `0x004a3be0` despite coherent update-record instructions.
