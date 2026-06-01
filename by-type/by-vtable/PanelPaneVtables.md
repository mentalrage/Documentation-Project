*** UID:0001YD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PanelPane Vtables

## Status

- Disposition: vtable inventory for reconstructable UI-core panel base code.
- Covered source owner: [UID:0000ME][PanelPane](by-file/PanelPane.md)
- Covered class: [UID:0000A4][PanelPane](by-class/PanelPane.md)
- Exact vtable-data range: [UID:0002OG][0x00621a6c-0x00621af8.PanelPaneVtableData](by-memory/0x00621a6c-0x00621af8.PanelPaneVtableData.md)
- Confidence: strong for table bases, constructor/destructor stores, and adjustor thunks.
- Verification: IDA MCP `list_globals`, `xrefs_to`, `lookup_funcs`, `disasm`, `callers`, `callees`, and `py_eval` checks on 2026-05-26; IDA MCP `py_eval` recheck of exact vtable-data dwords, boundaries, data xrefs, and thunk/function extents on 2026-06-01.

## Table Bases

| Object offset | Vtable symbol | Address | First slot | Notes |
| --- | --- | --- | --- | --- |
| `+0x00` | `??_7PanelPane@@6B@` | `0x00621a70` | `0x00545110` | Primary `Pane` view; scalar deleting destructor followed by inherited pane virtuals. |
| `+0xa0` | `??_7PanelPane@@6B@_0` | `0x00621ac0` | `0x005450ef` | Secondary event/timer-handler view; destructor adjustor subtracts `0xa0`. |
| `+0xa4` | `??_7PanelPane@@6B@_1` | `0x00621af0` | `0x005450fa` | Tertiary event/timer-handler view; destructor adjustor subtracts `0xa4`. |

## Slot Evidence

| Table | Slot | Target | Interpretation |
| --- | --- | --- | --- |
| primary | `+0x00` | `0x00545110` | `PanelPane` scalar deleting destructor. |
| primary | `+0x04` through `+0x48` | `0x004f4b10`, `0x0041b6c0`, `0x004b8e20`, `0x0041d680`, `0x00544730`, `0x00544750`, `0x005447a0`, `0x00544800`, `0x00544a20`, `0x00544b80`, `0x00544bd0`, `0x00544c70`, `0x00544cb0`, `0x00544ce0`, `0x00544d30`, `0x00544d70`, `0x0041b6a0`, `0x005ca28c` | Inherited `Pane`/base interface slots. |
| secondary | `+0x00` | `0x005450ef` | Adjustor thunk subtracting `0xa0`, then jumping to `0x00545110`. |
| secondary | `+0x04` through `+0x28` | `0x00544db0`, `0x00544dc0`, `0x00544dd0`, `0x00544de0`, `0x00544df0`, `0x00544e00`, `0x004a89f0`, `0x00544e10`, `0x00544e30`, `0x00544e70` | Inherited handler-interface slots. |
| tertiary | `+0x00` | `0x005450fa` | Adjustor thunk subtracting `0xa4`, then jumping to `0x00545110`. |
| tertiary | `+0x04` | `0x00544e90` | Inherited handler-interface slot. |

Do not read the tertiary table past slot `+0x04`. The next dword at `0x00621af8` is RTTI metadata for neighboring [UID:0001XF][EditablePaperPaneVtables](by-type/by-vtable/EditablePaperPaneVtables.md), not a `PanelPane` virtual.

## Constructor and Destructor Stores

IDA `xrefs_to` reports all three vtable bases written from the constructor, non-deleting destructor, and scalar deleting destructor:

- Constructor `0x00545090`: writes primary at `0x005450a1`, secondary at `0x005450a9`, and tertiary at `0x005450b3`.
- Non-deleting destructor `0x005450d0`: writes primary at `0x005450d0`, secondary at `0x005450d6`, and tertiary at `0x005450e0`, then tail-jumps to `Pane` teardown at `0x00544580`.
- Scalar deleting destructor `0x00545110`: writes primary at `0x00545116`, secondary at `0x0054511c`, and tertiary at `0x00545126`, calls `Pane` teardown at `0x00544580`, then conditionally frees storage.

## Wave3 Data Issue

Current generated `class_PanelPane.cpp.disabled` marks `0x005450ef` as missing code, but IDA recognizes it as a real 11-byte function with the vtable data xref at `0x00621ac0`. The active destructor body also routes through a `TextButtonExControlPane` owner label even though IDA disassembly shows a direct tail jump to the `Pane` destructor path. This is tracked in [wave3 data issues](../../wave3_data_issues.md).

## Cross References

- [UID:0002OG][0x00621a6c-0x00621af8.PanelPaneVtableData](by-memory/0x00621a6c-0x00621af8.PanelPaneVtableData.md)
- [UID:0001EC][0x00545090-0x00545165.PanelPane](by-memory/0x00545090-0x00545165.PanelPane.md)
- [UID:0001ED][0x005450ef-0x00545104.PanelPaneAdjustorThunks](by-memory/0x005450ef-0x00545104.PanelPaneAdjustorThunks.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000ME][PanelPane](by-file/PanelPane.md)

## Changes

- 2026-06-01:
  - What existed before: this vtable page had strong slot and constructor/destructor-store evidence, but the validator-tracked completion/confidence header remained `0/0` and there was no exact `by-memory` child for the `0x00621a6c-0x00621af8` RTTI/vtable-data island.
  - Changed to: scored the page as a strong but non-final vtable inventory, marked it reconstructable, and linked [UID:0002OG][0x00621a6c-0x00621af8.PanelPaneVtableData](by-memory/0x00621a6c-0x00621af8.PanelPaneVtableData.md) as the exact address-range evidence page.
  - Summary/evidence: IDA MCP `py_eval` on 2026-06-01 read the RTTI/vtable dwords from `0x00621a6c` through `0x00621af8`, confirmed data xrefs from `PanelPane` constructor/destructor bodies to all three vtable bases, confirmed `0x005450ef` and `0x005450fa` as real 11-byte adjustor thunks, and confirmed `0x00621af8` starts neighboring `EditablePaperPane` RTTI.
