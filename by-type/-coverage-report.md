*** UID:0001RU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# by-type Coverage Report

## Summary

- Last generated: 2026-05-26
- Folder: `by-type`
- Coverage summary: 1 covered reconstructable row, 0 covered ignored rows, 1 uncovered inventory placeholder row.
- Confidence summary: baseline report generated from existing documentation pages and `-ignored.md`; ignored rows are driven by the local ignored ledger, while reconstructable row confidence is heuristic until IDA/MCP or manual verification raises it.
- Ordering: alphabetic by item name, except `by-memory`, which is sorted by the first address in the row.

## Covered Items To Replicate

- [UID:000559][ArgumentedItemConfirmInputDialogPaneLayout](by-type/by-struct/ArgumentedItemConfirmInputDialogPaneLayout.md) : reconstructable : 92% : very-strong : Exact 0x27c DialogPane-derived layout owned/emitted by UID00000F, with inherited primary/secondary/tertiary views, list-context pointer at +0x26c, max quantity at +0x270, expected price at +0x274, argument id at +0x278, natural size closure, constructor/action consumers, and no duplicate source body.
- [UID:00055C][ArgumentedItemInputDialogVtables](by-type/by-vtable/ArgumentedItemInputDialogVtables.md) : reconstructable : 92% : very-strong : Complete six-view quantity/confirm vtable contract owned/emitted by UID0000HH through ordinary class declarations; exact primary/secondary/tertiary slots, two seven-base RTTI graphs, adjustor/destructor folding, constructor stores, and no hand-authored vtable arrays.
- [UID:000556][ArgumentedItemQuantityInputDialogPaneLayout](by-type/by-struct/ArgumentedItemQuantityInputDialogPaneLayout.md) : reconstructable : 92% : very-strong : Exact 0x274 DialogPane-derived layout owned/emitted by UID00000G, with inherited primary/secondary/tertiary views, list-context pointer at +0x26c, unsigned argument id at +0x270, natural size closure, constructor/action consumers, and no duplicate source body.
- [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md) : reconstructable : 94% : very-strong : Exact 0x26c DialogPane inherited layout with primary, +0xa0 EventHandler, and +0xa4 TimerHandler views, complete field/bounds/background evidence, and class-declaration route.
- [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md) : reconstructable : 92% : very-strong : Exact EmployeeDialogPane primary/secondary/tertiary vtable topology with UID0003L4 deleting wrapper, 0xa0/0xa4 adjustors, constructor/destructor stores, and source-declared/generated-binary no-hand-authored-vtable policy.
- [UID:0001UD][EmployeeRecord](by-type/by-struct/EmployeeRecord.md) : reconstructable : 88% : very-strong : Exact 0x41c employee record layout consumed as a heap array through EmployeeDialogPane pointer +0x84c, with parser/load/update/paint/property consumers and remaining lexical field-name caveats.
- [UID:0001V9][ModelessDialogPaneLayout](by-type/by-struct/ModelessDialogPaneLayout.md) : reconstructable : 88% : very strong : B015 source-quality sync confirms three-view ModelessDialogPane layout, secondary-view `this == object+0xa0` mapping, inherited DialogPane `+0x208..+0x238` field roles for drag/hover/pressed/selection/clamp behavior, no derived tail, corrected mouse event map, raw PE constructor-store/vtable-only reachability, and exact post-handler jump-table boundary.
- [UID:0001Y6][ModelessDialogPaneVtables](by-type/by-vtable/ModelessDialogPaneVtables.md) : reconstructable : 87% : very strong : B015 source-quality sync keeps the direct [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md) owner, rejects stale Wave3 `vtable_count:0`, confirms primary/secondary/tertiary vtable bases and constructor stores, secondary slots for `HandleMouseEvent`/`IsModal`, two-slot tertiary boundary before `0x00618ce0`, and source-declared/generated-binary no-hand-authored-vtable policy.
- [UID:00054F][NewInventoryPaneLayout](by-type/by-struct/NewInventoryPaneLayout.md) : reconstructable : 94% : very-strong : Exact allocator-proven `0x158` NewInventoryPane storage map documenting class-owned fields without duplicate emission.
- [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md) : reconstructable : 85% : very-strong : Pane/GrafPort inherited layout through the +0xf8 derived boundary; +0x44 is GrafPort m_visibleBounds, +0xac/+0xb0 are Point m_origin.y/m_origin.x, +0xb4 remains the Show/Hide visibility byte, and +0xf6 is the inherited m_drawOnTarget direct-target paint mode cleared by Pane, set by Rain/Snow/Swallow constructors, and tested to bypass generic virtual OnPaint during Layer dirty-region traversal; all handler/layer/region/motion/deletion evidence remains intact.
- [UID:0001VP][RectBoundsLayout](by-type/by-struct/RectBoundsLayout.md) : reconstructable : 94% : very-strong : Exact duplicate four-int RectBounds layout support with left/top/right/bottom at +0/+4/+8/+0c, sole declaration ownership in UID0000BU, no distinct IDA UDT/source entity, blank formal CPP/H, and no emitter.
- [UID:0001VX][ScheduledTimerEvent](by-type/by-struct/ScheduledTimerEvent.md) : reconstructable : 85% : very strong : 20-byte TimerMgrTimerQueue event record with owner, `timerId`/`eventId`, dueTick, arg0, and arg1 fields; B015 adds the callback-facing `timerId` naming policy and `OnTimer(int timerId, int arg0, int arg1)` model while preserving generic arg names until caller-family evidence proves stronger semantics.
- [UID:0001WD][TimerMgrLayout](by-type/by-struct/TimerMgrLayout.md) : reconstructable : 86% : very strong : TimerMgr 0x24-byte support layout with B015-normalized `m_timerQueue.*`, `m_currentTick`, `m_timerPeriod`, and `m_nextDueTick` names, low-level queue aliases preserved, tick mirror names marked inferred, and exact TimerMgr/TimerMgrTimerQueue child evidence backing each field family.
- [UID:0004N3][TransferServerDialogPaneLayout](by-type/by-struct/TransferServerDialogPaneLayout.md) : ignored : 91% : very-strong : Non-emitting exact 0x100 layout support for Pane/GrafPort through +0xf7, inherited m_alpha at +0x90, EventHandler/TimerHandler facets at +0xa0/+0xa4, empty Singleton EBO at +0xf8, and only m_currentFrame/m_frameCount at +0xf8/+0xfc; class UID0000F7 owns the declaration.
- [UID:0004N4][TransferServerDialogPaneVtables](by-type/by-vtable/TransferServerDialogPaneVtables.md) : ignored : 92% : very-strong : Non-emitting exact three-view TransferServerDialogPane RTTI/vtable support at 0x0062e480, 0x0062e4cc, and 0x0062e4fc with complete slots, COLs/base hierarchy, constructor/destructor stores, OnPaint/OnTimer overrides, -0xa0/-0xa4 adjustors, and compiler-generation route through class UID0000F7.
- [UID:0004P6][UserCreateAppearanceControlLayouts](by-type/by-struct/UserCreateAppearanceControlLayouts.md) : reconstructable : 90% : very-strong : Exact five-class object sizes/fields and source-bearing 8-byte UserCreateColorSwatchItem declaration.
- [UID:0004P8][UserCreateAppearanceControlVtables](by-type/by-vtable/UserCreateAppearanceControlVtables.md) : ignored : 91% : very-strong : Exact five-class primary/secondary/tertiary RTTI/vtable map, override slots, adjustor routes, and source-declared/generated-binary disposition.

## Covered Items To Ignore

- None recorded yet.

## Uncovered Items

- by-type inventory baseline : uncovered : 0% : open : Full authoritative inventory for by-type is not yet proven complete; compare this report against Wave3 when OPERATIONAL, simroot_v2, and IDA/MCP evidence.
