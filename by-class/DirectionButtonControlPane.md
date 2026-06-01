*** UID:00003X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:62 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:66 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DirectionButtonControlPane

## Status

- Confidence: medium overall; standalone constructor boundary remains projected and unproven.
- Likely source file: [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)
- Memory range: [UID:0001A4][0x00500640-0x00502754.SpecializedButtonPanes](by-memory/0x00500640-0x00502754.SpecializedButtonPanes.md)
- Current recovered file: `source-3/simroot_v2/class_DirectionButtonControlPane.cpp`
- Type docs: [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md), [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md)

## Class Purpose

`DirectionButtonControlPane` is a button-like control that renders directional arrow sprites from `DIREC.EPD`, updates its direction/enabled state, and chains through the generic button/control destruction pattern.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `DirectionButtonControlPane` | `0x005007a0-0x005007e7` | Wave3 constructor range; not an IDA-recognized function start, with no direct callers/xrefs or raw pointer hits observed. |
| `SetEnabled` | `0x005007f0`, size `0x2e` | Updates direction state and delegates enabled handling; vtable data xref at `0x0061dc7c`. |
| `OnPaint` | `0x00500820`, size `0x99` | Draws `DIREC.EPD` frame and disabled styling; vtable data xref at `0x0061dc78`. |
| Destructor/thunks | `0x0050248a`, `0x00502495`, `0x005026a0` size `0x55` | This-adjustor and scalar deleting destructor; vtable data xrefs at `0x0061dc9c`, `0x0061dccc`, and `0x0061dc34`. |

## Evidence Notes

- Wave3 effective grade is 96.7.
- 2026-05-24 IDA MCP reports no function, callers, or xrefs at `0x005007a0`; the previous function is `0x00500700-0x00500797`, and the next recognized function is `0x005007f0-0x0050081e`.
- 2026-05-24 IDA MCP recognizes `0x005007f0`, `0x00500820`, and `0x005026a0`, all reached by vtable data rather than direct code callers.
- The `NewUserMiscDialogPane` constructor inlines direction-button child setup at `0x004fba68-0x004fba91` and `0x004fbaee-0x004fbb17`, matching the control behavior without proving a standalone constructor body.
- 2026-05-26 IDA MCP confirmed primary vtable `0x0061dc34`, secondary vtable `0x0061dc9c`, and tertiary vtable `0x0061dccc`. Inline setup allocates `0x114` bytes and writes subclass fields at `+0x10c` and `+0x110`.
- 2026-05-27 IDA MCP recheck still reports `0x005007a0` as `NOFUNC` with no xrefs, and a raw dword scan across loaded segments found no pointers to `0x005007a0`. The virtual methods remain confirmed through vtable refs at `0x0061dc78` and `0x0061dc7c`.

## Cross-References

- [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)
- [UID:0001A4][0x00500640-0x00502754.SpecializedButtonPanes](by-memory/0x00500640-0x00502754.SpecializedButtonPanes.md)
- [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md)
- [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `62/66`.
  - Summary/evidence: render/control role, confirmed virtual methods, destructor/thunks, vtable refs, inline setup evidence, and projected-constructor caveat are documented; score remains lower because the standalone constructor boundary is still unproven and has no direct xrefs.
