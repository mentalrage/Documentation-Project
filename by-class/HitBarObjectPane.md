*** UID:000067 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class HitBarObjectPane : public AttachedObjectPane
{
public:
    HitBarObjectPane(
        LivingObjectPane *livingObjectPane,
        int mapY,
        int mapX,
        unsigned short primaryValue,
        unsigned short primaryMaximum,
        unsigned char style);
    HitBarObjectPane(
        LivingObjectPane *livingObjectPane,
        int mapY,
        int mapX,
        unsigned short primaryValue,
        unsigned short primaryMaximum,
        unsigned short secondaryValue,
        unsigned short secondaryMaximum);
    virtual ~HitBarObjectPane();

    void SetValues(
        unsigned short primaryValue,
        unsigned short primaryMaximum,
        unsigned short secondaryValue,
        unsigned short secondaryMaximum);
    bool IsActive() const;

    virtual void ClearOutputRects(
        RectBounds *firstBounds,
        RectBounds *secondBounds);
    virtual void RenderFrame(
        GrafPort *target,
        const RectBounds *bounds);
    virtual void UpdatePosition();

private:
    unsigned short m_primaryValue;       // 0x12c
    unsigned short m_primaryMaximum;     // 0x12e
    unsigned char m_style;               // 0x130
    bool m_active;                       // 0x131
    unsigned short m_secondaryValue;     // 0x132
    unsigned short m_secondaryMaximum;   // 0x134
};

typedef char HitBarObjectPaneSizeMustBe312[
    sizeof(HitBarObjectPane) == 0x138 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# HitBarObjectPane

## UID0003TH Single-Value Constructor And Timer Liveness - 2026-07-15

- [UID:0003TH][0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPane](by-memory/0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPane.md) is the only caller of the single-value constructor at `0x00538d50`. It passes the typed LivingObjectPane owner, map row/column, unsigned-short current and maximum values, and a style byte.
- `ObjectStatusBlob::HumanObject` selects style `1`; every other status kind selects style `0`. The target keeps separate ordinary-new branches matching the two allocation/constructor/EH sites rather than collapsing them into a source ternary.
- After construction, UID0003TH installs the pane in the owner's `m_hitBarObjectPane` slot, adds it to ObjectList, and directly schedules its inherited TimerHandler view for event `0` after `500` ms. The TimerHandler-view callback at `0x005386a0` handles event `0` by deleting the complete HitBarObjectPane, proving the temporary lifetime.
- UID0003TH then calls `UpdatePosition`, gets inherited GrafPort bounds, and invalidates those bounds. Pool allocation, EH, vptr stores, TimerHandler adjustment, and deleting-destructor lowering are compiler mechanics; the target does not alter this class's constructor/destructor/vtable/pool ownership.
- Score `90/93`, owner/emitter UID0000HJ, position 20, complete class/constructor formal C++, and every unrelated sibling behavior remain unchanged.

## UID0003TC Complete Class Integration - 2026-07-15

- This page now emits the complete source-safe `HitBarObjectPane` declaration at `90/93`, position `20`, after [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md) position `10`. The class stays owned/emitted by [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md); `[[CHILDREN]]` remains the insertion point for class-owned definitions.
- Exact base size is `0x12c`; exact complete size is `0x138`. Explicit fields are `unsigned short m_primaryValue` at `+0x12c`, `unsigned short m_primaryMaximum` at `+0x12e`, `unsigned char m_style` at `+0x130`, `bool m_active` at `+0x131`, `unsigned short m_secondaryValue` at `+0x132`, and `unsigned short m_secondaryMaximum` at `+0x134`. The remaining two tail bytes are implicit compiler alignment, not an invented source member.
- The style constructor `[0x00538d50,0x00538dbb)` initializes the AttachedObjectPane base with object type 7, stores the owner at `+0x128`, initializes the primary pair/style, and clears active at `+0x131`. The dual constructor `[0x00538dc0,0x00538e3a)` initializes both pairs and writes word `0x0101` across style/active, proving style 1 plus active true.
- `SetValues` `[0x00538e60,0x00538ea3)` updates both unsigned-short pairs only while active and then invalidates through virtual slot `+0x20` with a null rectangle. `IsActive` `[0x00538eb0,0x00538eb7)` returns the byte at `+0x131` as `bool`.
- The final no-argument AttachedObjectPane virtual slot is accepted as `UpdatePosition`. Base cell `0x006205b8` is `__purecall`; aligned HitBar, DamageNumber, and ObjectInfo cells resolve to `0x00538ec0`, `0x00539400`, and `0x00539700`. Each derived body recomputes owner-relative screen bounds before calling `SetBounds`.
- `ClearOutputRects` `[0x00538f90,0x00539021)` and `RenderFrame` `[0x00539030,0x0053922b)` are the source-facing override names. Historical `GetBarRectOffsets` and `RenderHitBar` remain descriptive aliases only. Historical `UpdateHitBarBounds` is superseded by the shared `UpdatePosition` contract.
- [UID:0003TC][0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane](by-memory/0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md) and the inline twin in UID0003TB are the exact two callers of the dual constructor and `SetValues`; UID0003TD supplies the third `IsActive` use. UID0003TC updates an active instance or removes/deletes/recreates/registers/positions/invalidates it in exact MapPane order.
- [UID:0002WP][0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage](by-memory/0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage.md) remains the sole file-local pool definition, `static PoolAllocator g_hitBarObjectPanePool(0x138, 4);`. Vtable UID000353 and resource UID0002YR remain covered/generated support; do not duplicate raw RTTI/vtable arrays or the `DEADSIGN.EPF` literal definition here.
- Ordinary source uses `new` and `delete`. Pool allocation/free, constructor-unwind helper `[0x00538e40,0x00538e5f)`, scalar deleting destructor flags, vptr stores, EH state, cookie checks, and raw storage release are compiler or class-lifetime products and are not handwritten in this declaration.
- Confidence stops at 93 because exact original field and helper spellings are stripped and unrelated rendering details remain elsewhere; exact offsets, sizes, constructor modes, call routes, and virtual slot are binary-proven.

## Status

- Confidence: very strong for role, anchors, vtable refs, static-pool refs, and attached-overlay source ownership.
- Likely source file: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- Vtable data: [UID:000353][0x00620734-0x006207e8.HitBarObjectPaneVtableData](by-memory/0x00620734-0x006207e8.HitBarObjectPaneVtableData.md)
- Dead-sign resource string: [UID:0002YR][0x00620bc0-0x00620bdc.DeadSignResourceString](by-memory/0x00620bc0-0x00620bdc.DeadSignResourceString.md)
- Static pool storage: [UID:0002WP][0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage](by-memory/0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage.md)
- Recovered-source/Wave references are historical only; current source-quality decisions come from by-* docs, MCP evidence, scoped validators, and the [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) source route.

## Class Purpose

`HitBarObjectPane` renders the hit/health bar overlay attached to a map object. It supports single-bar and dual-bar construction, calculates owner-relative bounds, draws dead-sign art when needed, and fills bar regions by current/max values.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor, style form | `0x00538d50-0x00538dbb` | Builds a single/status-style hit bar. |
| constructor, dual form | `0x00538dc0-0x00538e3a` | Builds a dual-value hit bar. |
| constructor-unwind cleanup | `0x00538e40-0x00538e5f` | Restores the three HitBar vtable views and delegates attached-object cleanup during constructor failure. |
| `SetValues` | `0x00538e60-0x00538ea3` | When `m_active` is set, updates primary and secondary value/maximum fields and calls virtual `UpdatePosition`. |
| `IsActive` | `0x00538eb0-0x00538eb7` | Returns `m_active` at `this + 0x131`; MapPane uses it before updating or replacing the pane. |
| `UpdatePosition` | `0x00538ec0-0x00538f81` | Implements the final shared AttachedObjectPane virtual and computes current screen bounds from owner position and bar mode; historical `UpdateHitBarBounds` is descriptive only. |
| `ClearOutputRects` | `0x00538f90-0x00539021` | Handles mode-specific relative output rectangles; historical `GetBarRectOffsets` is descriptive only. |
| `RenderFrame` | `0x00539030-0x0053922b` | Draws dead sign or filled primary/secondary bars; historical `RenderHitBar` is descriptive only. |
| scalar deleting destructor | `0x0053d240-0x0053d2d7` | Tears down attached-object base and frees from the object pool when requested. |

## Evidence Notes

- Constructor callers are in MapPane damage/hit event handlers around `0x0050e4c0`, `0x0050e690`, and `0x0050edd0`.
- Historical recovered-output notes treated `0x0050e690` as unknown, but current IDA/by-* evidence confirms it as a real constructor caller in the MapPane packet cluster.
- 2026-06-07 Batch 090 live IDA MCP on `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` reconfirmed the function objects and half-open ends: `0x00538d50-0x00538dbb`, `0x00538dc0-0x00538e3a`, `0x00538e40-0x00538e5f`, `0x00538e60-0x00538ea3`, `0x00538eb0-0x00538eb7`, `0x00538ec0-0x00538f81`, `0x00538f90-0x00539021`, `0x00539030-0x0053922b`, and `0x0053d240-0x0053d2d7`, with `0xcc` alignment after each modeled body.
- The two constructors and the unwind/destructor paths reference HitBar vtable views at `0x00620738`, `0x006207b0`, and `0x006207e0`; current source-facing `UpdatePosition`, `ClearOutputRects`, and `RenderFrame` are reached from those vtable tables. Older aliases are retained only in the historical integration notes above.
- Live caller evidence ties the helpers to MapPane event/update paths: the dual constructor is called from `0x0050e4c0` and `0x0050e690`, the style constructor from `0x0050edd0`, the bounds/state helper from `0x0050e4c0`/`0x0050e690`, and the active-flag accessor from `0x0050e4c0`, `0x0050e690`, and `0x0050e810`.
- The scalar deleting destructor is called from two adjustor thunks at `0x0053cefc`/`0x0053cf07` and from vtable data, restores HitBar vtables, calls the attached-object base cleanup at `0x00538100`, and gates pool release through the static pool byte at `0x0069b934`.
- Direct parent assignment is now justified to [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md): this child is `85/89`, and the direct file parent has been refreshed to `85/85` with matching attached-overlay, MapPane caller, vtable, destructor, and static-pool evidence.
- 2026-06-10 B001-035 read-only data split confirmed exact HitBar-owned `.rdata` children: [UID:000353][0x00620734-0x006207e8.HitBarObjectPaneVtableData](by-memory/0x00620734-0x006207e8.HitBarObjectPaneVtableData.md) covers the three HitBar vtable views at `0x00620738`, `0x006207b0`, and `0x006207e0`, and [UID:0002YR][0x00620bc0-0x00620bdc.DeadSignResourceString](by-memory/0x00620bc0-0x00620bdc.DeadSignResourceString.md) covers the dead-sign resource string at `0x00620bc0`.
- 2026-07-01 B009 accepted empty-emitter implementation populated the exact support markers without adding formal class C++: [UID:000353][0x00620734-0x006207e8.HitBarObjectPaneVtableData](by-memory/0x00620734-0x006207e8.HitBarObjectPaneVtableData.md) is now `88/91` with a formal no-raw-vtable marker; [UID:0002YR][0x00620bc0-0x00620bdc.DeadSignResourceString](by-memory/0x00620bc0-0x00620bdc.DeadSignResourceString.md) is now `86/91` with a source-literal marker for `DEADSIGN.EPF`; and [UID:0002WP][0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage](by-memory/0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage.md) is now `88/93` and emits first-draft `static PoolAllocator g_hitBarObjectPanePool(0x138, 4);`. Current MCP evidence reads the pool storage as zero-filled and confirms startup wrapper `0x0041a0c0`, cleanup wrapper `0x0060c360`, and allocation/free/destructor refs. Exact original pool spelling/linkage remains inferred, so the pool child keeps numeric constants until a final class-layout pass can safely use `sizeof(HitBarObjectPane)`.

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
- 2026-07-01 B009 accepted AttachedObjectPane empty-emitter first batch:
  - Score unchanged at `85/89`; formal class C++ remains blank for the existing field-name and final body-shape blockers.
  - Updated support evidence for [UID:000353][0x00620734-0x006207e8.HitBarObjectPaneVtableData](by-memory/0x00620734-0x006207e8.HitBarObjectPaneVtableData.md), [UID:0002YR][0x00620bc0-0x00620bdc.DeadSignResourceString](by-memory/0x00620bc0-0x00620bdc.DeadSignResourceString.md), and [UID:0002WP][0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage](by-memory/0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage.md). The vtable and resource-literal children now carry formal marker coverage, and the pool child now emits `static PoolAllocator g_hitBarObjectPanePool(0x138, 4);` with current zero-filled storage evidence.
