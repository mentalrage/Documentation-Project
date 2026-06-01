*** UID:000067 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HitBarObjectPane

## Status

- Confidence: strong for role and anchors.
- Likely source file: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- Current recovered file: `source-3/simroot_v2/class_HitBarObjectPane.cpp`
- Current Wave3 grade: `97.3`
- Current Wave3 coverage: 8 modeled methods, zero missing target refs.

## Class Purpose

`HitBarObjectPane` renders the hit/health bar overlay attached to a map object. It supports single-bar and dual-bar construction, calculates owner-relative bounds, draws dead-sign art when needed, and fills bar regions by current/max values.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor, style form | `0x00538d50-0x00538dbb` | Builds a single/status-style hit bar. |
| constructor, dual form | `0x00538dc0-0x00538e3a` | Builds a dual-value hit bar. |
| `UpdateHitBarBounds` | `0x00538ec0-0x00538f81` | Computes current screen bounds from owner position and bar mode. |
| `GetBarRectOffsets` | `0x00538f90-0x00539021` | Returns mode-specific relative bar rectangle offsets. |
| `RenderHitBar` | `0x00539030-0x0053922b` | Draws dead sign or filled HP/secondary bars. |
| scalar deleting destructor | `0x0053d240-0x0053d2d7` | Tears down attached-object base and frees from the object pool when requested. |

## Evidence Notes

- Constructor callers are in MapPane damage/hit event handlers around `0x0050e4c0`, `0x0050e690`, and `0x0050edd0`.
- Wave3 reports `0x0050e690` as unknown even though IDA confirms it as a real constructor caller in the MapPane packet cluster.

## Cross-References

- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md)
- [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md)
- [UID:00003F][DamageNumberObjectPane](by-class/DamageNumberObjectPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `76/86`. Summary: attached hit-bar overlay role, constructor variants, bounds, rectangle offsets, rendering, destructor, and MapPane caller anchors are documented with strong confidence; remaining work is deeper field naming and final C++ body reconstruction. Evidence: `ObjectOverlayPanes`, AttachedObjectPane, DamageNumberObjectPane, and constructor caller notes.
