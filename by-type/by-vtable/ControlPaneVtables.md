*** UID:0003J9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000038 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000038 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ControlPane Vtables

## Status

- Entity kind: source-local vtable cluster.
- Covered class: [UID:000038][ControlPane](by-class/ControlPane.md).
- Likely source file: [UID:0000IG][ControlPane](by-file/ControlPane.md).
- Exact memory page: [UID:0003J8][0x00617a8c-0x00617b30.ControlPaneVtableData](by-memory/0x00617a8c-0x00617b30.ControlPaneVtableData.md).
- Non-emitting aggregate source: [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md).
- Autogen parent: [UID:000038][ControlPane](by-class/ControlPane.md), after Batch 336 parent refresh to `85/86`.
- Verification: A004 Batch 336 live IDA MCP against `b001_nexustk` on 2026-06-12.

## Vtable Bases

| Object offset | Vtable base | Preceding locator | Notes |
| --- | --- | --- | --- |
| `+0x00` | `0x00617a90` | `0x00617a8c` | Primary `ControlPane` view; first slot is scalar deleting destructor `0x0049b170`. |
| `+0xa0` | `0x00617af8` | `0x00617af4` | Secondary handler view; first slot is adjustor thunk `0x0049af3d`. |
| `+0xa4` | `0x00617b28` | `0x00617b24` | Tertiary handler view; first slot is adjustor thunk `0x0049af48`. |

Offsets `0xa0` and `0xa4` are 160 and 164 respectively (Verified with `int_convert.py`).

## Evidence

- IDA MCP `entity_query` confirms decorated table names `??_7ControlPane@@6B@`, `??_7ControlPane@@6B@_0`, and `??_7ControlPane@@6B@_1` at `0x00617a90`, `0x00617af8`, and `0x00617b28`; the next decorated base is `ProgressBarControlPane` at `0x00617b34`.
- `lookup_funcs` reports constructor `0x004949e0-0x00494a81`, scalar deleting destructor `0x0049b170-0x0049b1ab`, 11-byte adjustor thunks at `0x0049af3d` and `0x0049af48`, and fixed virtual `0x0041d690-0x0041d695`.
- `trace_data_flow backward` reports constructor stores at `0x00494a23`, `0x00494a29`, and `0x00494a33` to the three bases.
- `get_int` reads the locator dwords at `0x00617a8c`, `0x00617af4`, and `0x00617b24`, final inherited tertiary slot `0x00544e90` at `0x00617b2c`, and neighboring `ProgressBarControlPane` RTTI at `0x00617b30`. The exact range is `0xa4` / 164 bytes (Verified with `int_convert.py`).

## Assignment Gate

This page is a single-owner `ControlPane` vtable declaration record. The child clears `88/93`; [UID:000038][ControlPane](by-class/ControlPane.md) was refreshed to `85/86`, so the strict child/direct-parent gate clears. The broader [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md) remains parentless because it spans five direct owners.

## Reconstruction Notes

Do not emit literal vtable bytes from this page. Reconstruct the source-level `ControlPane` class declaration and virtual method set; the secondary and tertiary destructor entries are compiler adjustor thunks.

## Cross-References

- [UID:000038][ControlPane](by-class/ControlPane.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)
- [UID:0003J8][0x00617a8c-0x00617b30.ControlPaneVtableData](by-memory/0x00617a8c-0x00617b30.ControlPaneVtableData.md)
- [UID:0002PB][0x004949e0-0x00494a81.ControlPaneConstructor](by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md)
- [UID:000120][0x0049af3d-0x0049af52.ControlPaneAdjustorThunks](by-memory/0x0049af3d-0x0049af52.ControlPaneAdjustorThunks.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)

## Changes

- 2026-06-12 A004 Batch 336:
  - Created this exact source-local vtable page from the previous mixed [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md) aggregate.
  - Evidence: live IDA MCP confirmed decorated bases, constructor store triad, function sizes, adjustor-thunk sizes, raw bytes, and the `ProgressBarControlPane` successor boundary.
  - Gate: assigned to [UID:000038][ControlPane](by-class/ControlPane.md) after the class and file docs were refreshed past the strict `85/85` gate.
