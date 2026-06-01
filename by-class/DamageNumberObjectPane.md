*** UID:00003F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DamageNumberObjectPane

## Status

- Confidence: strong for role and anchors.
- Likely source file: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- Current recovered file: `source-3/simroot_v2/class_DamageNumberObjectPane.cpp`
- Current Wave3 grade: `97.5`
- Current Wave3 coverage: 8 modeled methods, zero missing target refs.

## Class Purpose

`DamageNumberObjectPane` displays floating damage or healing numbers attached to a map object. It chooses the display style from source/sign, formats the numeric text, schedules a short animation, computes display bounds from the owner object, and renders digit frames from `DMGNUM.EPF`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x00539230-0x0053935e` | Initializes owner, sign/style flags, number text, and animation timer. |
| `UpdateAnimationState` | `0x00539380-0x005393f8` | Updates host/animation state around the object-pane anchor. |
| `ComputeDisplayBounds` | `0x00539400-0x005394a5` | Positions the floating number relative to the attached object bounds. |
| `Copy128BitValue` | `0x005394b0-0x005394c3` | Copies packed draw vector values. |
| `RenderDamageText` | `0x005394d0-0x005395a7` | Loads and renders digit frames from `DMGNUM.EPF`. |
| scalar deleting destructor | `0x0053d060-0x0053d0f7` | Tears down attached-object base and frees from the object heap when requested. |

## Evidence Notes

- Constructor callers are in MapPane action/damage handlers at `0x0050ef00` and `0x00512960`.
- Wave3 models `0x00512960` as `MapPane::HandleActionPacket`, but currently reports `0x0050ef00` as unknown despite IDA confirming the function.

## Cross-References

- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md)
- [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md)
- [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `74/84`.
  - Summary/evidence: overlay role, constructor, animation/bounds/render helpers, destructor, MapPane caller anchors, and sibling object-pane links are documented; remaining work is deeper field naming and the unresolved unknown caller classification.
