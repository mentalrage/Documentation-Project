*** UID:000067 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HitBarObjectPane

## Status

- Confidence: very strong for role, anchors, vtable refs, static-pool refs, and attached-overlay source ownership.
- Likely source file: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- Vtable data: [UID:000353][0x00620734-0x006207e8.HitBarObjectPaneVtableData](by-memory/0x00620734-0x006207e8.HitBarObjectPaneVtableData.md)
- Dead-sign resource string: [UID:0002YR][0x00620bc0-0x00620bdc.DeadSignResourceString](by-memory/0x00620bc0-0x00620bdc.DeadSignResourceString.md)
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
| constructor-unwind cleanup | `0x00538e40-0x00538e5f` | Restores the three HitBar vtable views and delegates attached-object cleanup during constructor failure. |
| bounds/state refresh helper | `0x00538e60-0x00538ea3` | Updates four short bounds fields and invalidates through virtual slot `+0x20` when the active flag is set. |
| active-flag accessor | `0x00538eb0-0x00538eb7` | Returns the byte at `this + 0x131`; used by MapPane hit/update paths before refreshing bounds. |
| `UpdateHitBarBounds` | `0x00538ec0-0x00538f81` | Computes current screen bounds from owner position and bar mode. |
| `GetBarRectOffsets` | `0x00538f90-0x00539021` | Returns mode-specific relative bar rectangle offsets. |
| `RenderHitBar` | `0x00539030-0x0053922b` | Draws dead sign or filled HP/secondary bars. |
| scalar deleting destructor | `0x0053d240-0x0053d2d7` | Tears down attached-object base and frees from the object pool when requested. |

## Evidence Notes

- Constructor callers are in MapPane damage/hit event handlers around `0x0050e4c0`, `0x0050e690`, and `0x0050edd0`.
- Wave3 reports `0x0050e690` as unknown even though IDA confirms it as a real constructor caller in the MapPane packet cluster.
- 2026-06-07 Batch 090 live IDA MCP on `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` reconfirmed the function objects and half-open ends: `0x00538d50-0x00538dbb`, `0x00538dc0-0x00538e3a`, `0x00538e40-0x00538e5f`, `0x00538e60-0x00538ea3`, `0x00538eb0-0x00538eb7`, `0x00538ec0-0x00538f81`, `0x00538f90-0x00539021`, `0x00539030-0x0053922b`, and `0x0053d240-0x0053d2d7`, with `0xcc` alignment after each modeled body.
- The two constructors and the unwind/destructor paths reference HitBar vtable views at `0x00620738`, `0x006207b0`, and `0x006207e0`; `UpdateHitBarBounds`, `GetBarRectOffsets`, and `RenderHitBar` are reached from those vtable tables.
- Live caller evidence ties the helpers to MapPane event/update paths: the dual constructor is called from `0x0050e4c0` and `0x0050e690`, the style constructor from `0x0050edd0`, the bounds/state helper from `0x0050e4c0`/`0x0050e690`, and the active-flag accessor from `0x0050e4c0`, `0x0050e690`, and `0x0050e810`.
- The scalar deleting destructor is called from two adjustor thunks at `0x0053cefc`/`0x0053cf07` and from vtable data, restores HitBar vtables, calls the attached-object base cleanup at `0x00538100`, and gates pool release through the static pool byte at `0x0069b934`.
- Direct parent assignment is now justified to [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md): this child is `85/89`, and the direct file parent has been refreshed to `85/85` with matching attached-overlay, MapPane caller, vtable, destructor, and static-pool evidence.
- 2026-06-10 B001-035 read-only data split confirmed exact HitBar-owned `.rdata` children: [UID:000353][0x00620734-0x006207e8.HitBarObjectPaneVtableData](by-memory/0x00620734-0x006207e8.HitBarObjectPaneVtableData.md) covers the three HitBar vtable views at `0x00620738`, `0x006207b0`, and `0x006207e0`, and [UID:0002YR][0x00620bc0-0x00620bdc.DeadSignResourceString](by-memory/0x00620bc0-0x00620bdc.DeadSignResourceString.md) covers the dead-sign resource string at `0x00620bc0`.

## Cross-References

- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:000353][0x00620734-0x006207e8.HitBarObjectPaneVtableData](by-memory/0x00620734-0x006207e8.HitBarObjectPaneVtableData.md)
- [UID:0002YR][0x00620bc0-0x00620bdc.DeadSignResourceString](by-memory/0x00620bc0-0x00620bdc.DeadSignResourceString.md)
- [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md)
- [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md)
- [UID:00003F][DamageNumberObjectPane](by-class/DamageNumberObjectPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `76/86`. Summary: attached hit-bar overlay role, constructor variants, bounds, rectangle offsets, rendering, destructor, and MapPane caller anchors are documented with strong confidence; remaining work is deeper field naming and final C++ body reconstruction. Evidence: `ObjectOverlayPanes`, AttachedObjectPane, DamageNumberObjectPane, and constructor caller notes.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the attached hit-bar overlay unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE`; left `AUTOGEN_PARENT_UID` blank because the class score is `76/86`, below the 80 completion attachment gate.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x00538d50`, `0x00538dc0`, `0x00538ec0`, `0x00538f90`, `0x00539030`, and `0x0053d240`, with constructor callers from MapPane-side event handlers.
- 2026-06-07 Batch 090 parent-gate refresh:
  - Before: scores were `76/86`, and `AUTOGEN_PARENT_UID` was blank.
  - Changed to: scores `85/89` and `AUTOGEN_PARENT_UID:0000HJ`.
  - Summary/evidence: live IDA MCP reconfirmed the constructors, constructor-unwind cleanup, bounds/state helper, active-flag accessor, virtual bounds/offset/render methods, scalar deleting destructor, HitBar vtable refs, static pool byte `0x0069b934`, and MapPane caller paths. Final C++ stays blank because field names and source body form are not at the 95/95 final-code gate.
- 2026-06-10 B001-035 read-only split update:
  - Added exact `.rdata` children for the HitBar vtable block and dead-sign string after IDA MCP confirmed both are HitBar-specific artifacts.
  - No score change; the existing `85/89` class score already supported assigning both exact children to this parent.
