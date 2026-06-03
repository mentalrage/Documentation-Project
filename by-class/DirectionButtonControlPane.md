*** UID:00003X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DirectionButtonControlPane

## Status

- Confidence: strong for class role, vtable identity, layout fields, and virtual methods; medium-high for the raw constructor start because IDA still does not model `0x005007a0` as a function object.
- Likely source file: [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)
- Memory range: [UID:0001A4][0x00500640-0x00502754.SpecializedButtonPanes](by-memory/0x00500640-0x00502754.SpecializedButtonPanes.md)
- Current recovered file: `source-3/simroot_v2/class_DirectionButtonControlPane.cpp`
- Type docs: [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md), [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md)

## Class Purpose

`DirectionButtonControlPane` is a button-like control that renders directional arrow sprites from `DIREC.EPD`, updates its direction/enabled state, and chains through the generic button/control destruction pattern.

## Rebuild Handling

- Reconstructability: true for the class declaration, direction/visual-state fields, recognized virtual methods, and destructor behavior.
- Parent handling: attach to [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) at autogen position `10`. The file page is now a `76/82` provisional `NexusTK/ui/controls/` source root, so the child and parent meet the 80+ confidence attachment rule. This is class-level attachment only; method C++ remains blank.
- C++ handling: leave final C++ blank. The source should eventually model a normal specialized button-control class, but the constructor start at `0x005007a0` remains raw/non-IDA-function and inherited slot names are not final-source quality.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `DirectionButtonControlPane` | `0x005007a0-0x005007e7` | Wave3 constructor range; not an IDA-recognized function start, with no direct callers/xrefs or raw pointer hits observed. |
| `SetEnabled` | `0x005007f0`, size `0x2e` | Updates direction state and delegates enabled handling; vtable data xref at `0x0061dc7c`. |
| `OnPaint` | `0x00500820`, size `0x99` | Draws `DIREC.EPD` frame and disabled styling; vtable data xref at `0x0061dc78`. |
| Destructor/thunks | `0x0050248a`, `0x00502495`, `0x005026a0` size `0x55` | This-adjustor and scalar deleting destructor; vtable data xrefs at `0x0061dc9c`, `0x0061dccc`, and `0x0061dc34`. |

## Field Evidence

| Offset | Field hypothesis | Evidence |
| ---: | --- | --- |
| `0x10c` | direction index | `NewUserMiscDialogPane` inline setup writes `0` for one direction button and `1` for the other. [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md) records `OnPaint` using this value as `2 * directionIndex` for the `DIREC.EPD` frame index. |
| `0x110` | visual-state frame offset | Inline setup clears the field. `SetEnabled` writes this offset when incoming state/key `0x0b` arrives, and `OnPaint` adds it to the selected direction frame. |

## Vtable Evidence

- [UID:0002OW][0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData](by-memory/0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData.md) records exact primary, secondary, and tertiary vtable data for this class.
- Primary vtable `0x0061dc34` has store xrefs from inline setup at `0x004fba6d` and `0x004fbaf3`, the raw constructor body at `0x005007bd`, and destructor reset at `0x005026a6`.
- Secondary vtable `0x0061dc9c` has store xrefs at `0x004fba73`, `0x004fbaf9`, `0x005007c3`, and `0x005026ac`.
- Tertiary vtable `0x0061dccc` has store xrefs at `0x004fba7d`, `0x004fbb03`, `0x005007cd`, and `0x005026b6`.
- Key slots tie `0x00500820` to paint at primary `+0x44`, `0x005007f0` to state/update at primary `+0x48`, and `0x005026a0` to the scalar deleting destructor at primary `+0x00`.

## Evidence Notes

- Wave3 effective grade is 96.7.
- 2026-05-24 IDA MCP reports no function, callers, or xrefs at `0x005007a0`; the previous function is `0x00500700-0x00500797`, and the next recognized function is `0x005007f0-0x0050081e`.
- 2026-05-24 IDA MCP recognizes `0x005007f0`, `0x00500820`, and `0x005026a0`, all reached by vtable data rather than direct code callers.
- The `NewUserMiscDialogPane` constructor inlines direction-button child setup at `0x004fba68-0x004fba91` and `0x004fbaee-0x004fbb17`, matching the control behavior without proving a standalone constructor body.
- 2026-05-26 IDA MCP confirmed primary vtable `0x0061dc34`, secondary vtable `0x0061dc9c`, and tertiary vtable `0x0061dccc`. Inline setup allocates `0x114` bytes and writes subclass fields at `+0x10c` and `+0x110`.
- 2026-05-27 IDA MCP recheck still reports `0x005007a0` as `NOFUNC` with no xrefs, and a raw dword scan across loaded segments found no pointers to `0x005007a0`. The virtual methods remain confirmed through vtable refs at `0x0061dc78` and `0x0061dc7c`.
- 2026-06-01 aggregate and vtable-data pages add exact raw-constructor stores, vtable child boundaries, slot targets, and field-layout evidence for `+0x10c` and `+0x110`.
- 2026-06-03 IDA MCP recheck again reports `0x005007a0` as `NOFUNC` with no xrefs or raw pointer hits. It reconfirmed `0x005007f0`, `0x00500820`, and `0x005026a0` as real functions, primary vtable slots `0x0061dc34+0x44 -> 0x00500820`, `+0x48 -> 0x005007f0`, and `+0x00 -> 0x005026a0`, plus constructor/inline/destructor vtable store refs at `0x004fba6d`, `0x004fbaf3`, `0x005007bd`, and `0x005026a6`.

## Reconstruction Notes

- Model this as a concrete button-control subclass with direction-index and visual-state fields layered over the inherited button/control layout.
- The direction argument should drive frame selection from `DIREC.EPD`; the state override should only adjust the frame offset before delegating to the base button/control state handler.
- Treat `0x0050248a` and `0x00502495` as compiler-generated adjustor thunks, not source methods.
- Keep the constructor source provisional until the raw start/no-xref issue is resolved or accepted as an inlined/unreferenced constructor artifact.

## Cross-References

- [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)
- [UID:0001A4][0x00500640-0x00502754.SpecializedButtonPanes](by-memory/0x00500640-0x00502754.SpecializedButtonPanes.md)
- [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md)
- [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md)
- [UID:0002OW][0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData](by-memory/0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `62/66`.
  - Summary/evidence: render/control role, confirmed virtual methods, destructor/thunks, vtable refs, inline setup evidence, and projected-constructor caveat are documented; score remains lower because the standalone constructor boundary is still unproven and has no direct xrefs.
- 2026-06-02:
  - Before: the page remained in the low-both queue even though adjacent IDA-backed aggregate, layout, vtable, and exact vtable-data pages had been raised.
  - After: raised to `74/82` and marked `RECONSTRUCTABLE:TRUE`; parent and C++ remain blank.
  - Summary/evidence: exact vtable child [UID:0002OW][0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData](by-memory/0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData.md), aggregate method map [UID:0001A4][0x00500640-0x00502754.SpecializedButtonPanes](by-memory/0x00500640-0x00502754.SpecializedButtonPanes.md), and layout fields [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md) support the class role and rebuild shape while preserving the `0x005007a0` raw-constructor caveat.
- 2026-06-03 parent attachment update:
  - Before: `AUTOGEN_PARENT_UID` was blank because the likely file parent was below the 80+ confidence threshold and had no projected path.
  - Changed to: `AUTOGEN_PARENT_UID:0000NY` and position `10`; reconstruction C++ remains blank.
  - Summary/evidence: [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) is now a `76/82` provisional `NexusTK/ui/controls/` parent after a fresh IDA MCP recheck reconfirmed direction-button vtable/function evidence while preserving the raw constructor caveat.
