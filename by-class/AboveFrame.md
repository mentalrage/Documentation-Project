*** UID:000005 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000577 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000577 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "AboveFrame.h"
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "Pane.h"
#include "EPFTileContext.h"
#include "RectBounds.h"

class AboveFrame : public Pane
{
public:
    AboveFrame(int frameIndex, int top, int left);
    virtual ~AboveFrame();

protected:
    virtual void OnPaint();
    virtual void OnChangeMessage(LObject *owner, Message *message);

private:
    EPFTileContext m_tileContext;
    RectBounds m_bounds;
    unsigned char m_framePaletteMode;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AboveFrame

## Status

- Confidence: very strong for frame-chrome behavior, vtable ownership, source-family placement, field roles, class/header channel split, and exact slot topology; medium-high for exact original private field spelling.
- Active source file: [UID:000577][AboveFrame](by-file/AboveFrame.md)
- Address range: [UID:0000YH][0x004610f0-0x0046178a.AboveFrame](by-memory/0x004610f0-0x0046178a.AboveFrame.md)
- Vtable/layout anchor: [UID:0003I2][AboveFrameVtables](by-type/by-vtable/AboveFrameVtables.md); mixed index [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md); exact data child [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md)
- Historical umbrella: [UID:0000JL][FrameChrome](by-file/FrameChrome.md), now non-emitting.

## Class Purpose

`AboveFrame` is a `Pane`-derived frame chrome object. It loads one frame or tab piece from `FRMPART.EPF`, `TABS.EPF`, or legacy `FRMPART.EPD`, positions it at a supplied origin, registers through inherited `g_pBackPane->RegisterChangeListener(this, kPaneTagGoog, false)`, handles the shared notification through `OnChangeMessage(LObject *, Message *)`, and draws the loaded tile with the appropriate palette.

## Observed State

Live IDA decompilation and linked layout pages support these object fields:

| Offset | Meaning |
| --- | --- |
| `+0x000` | primary Pane-derived object/vtable |
| `+0x0a0` | secondary vtable view |
| `+0x0a4` | tertiary vtable view |
| `+0x0f8` | `m_tileContext`, `EPFTileContext` storage loaded from `FRMPART.EPF`, `TABS.EPF`, or `FRMPART.EPD`; its embedded bounds remain the source tile bounds used by paint. |
| `+0x120` | `m_bounds`, the one explicit positioned `RectBounds` copied from `m_tileContext.bounds` and offset by constructor `left`/`top`. |
| `+0x130` | `m_framePaletteMode`, palette/resource mode byte used by `OnPaint`. |
| `+0x131-0x133` | tail padding required by the observed `0x134` allocation size. |

The constructor argument order is `AboveFrame(int frameIndex, int top, int left)`, not the weaker `frameIndex, left, top` interpretation. For frame indices below `4`, EPF mode loads `FRMPART.EPF`. For frame indices `4` and above, EPF mode loads `TABS.EPF`, using the compact binary expression `frameIndex + (((frameIndex - 4) < 2) ? 1 : 0) - 5`; observed frame `4` maps to tab index `0`, frame `5` maps to `1`, and dynamic values are derived from `g_pGeneralPurposePanel->m_activeChildIndex + 5`. Legacy mode loads `FRMPART.EPD`. `OnPaint` selects `FRMPART.PAL`, `TABS.PAL`, or `NPAL5.PAL` from the same mode/index evidence.

The visible frame objects are indexed semantically through nonemitting [UID:0000PN][FrameChromeSlots](by-global/FrameChromeSlots.md), while exact source storage emits directly from [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md). The accepted file-static names are `g_pAboveFrameTop`, `g_pAboveFrameRight`, `g_pAboveFrameLeft`, `g_pDynamicAboveFrame`, `g_pLegacyAboveFrameTopLeft`, `g_pLegacyAboveFrameLeftSide[5]`, and `g_pLegacyAboveFrameRightSide[5]`. Their loader-zero storage contains a no-source alignment gap at `0x0067a844-0x0067a848`; it is not a class member or pointer slot.

The fixed pointers are builder-written program-lifetime state with no cleanup xrefs. The dynamic slot is released/rebuilt by [UID:0000YI][0x004615b0-0x00461658.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md) after general-purpose panel tab switches. Release deletes without clearing; recreate overwrites it with `AboveFrame(g_pGeneralPurposePanel->m_activeChildIndex + 5, 0x4f, 0x328)` or null on allocation failure. GeneralPurposePanel supplies the active index but does not own this class or the slot definitions.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `AboveFrame::AboveFrame` | `0x004610f0-0x00461299` | Initializes pane, loads frame/tab EPF/EPD resource, positions bounds, registers notification. |
| `~AboveFrame` | `0x004612a0-0x00461309` | Unregisters notification and destroys base pane. |
| `OnPaint` | `0x00461660-0x004616af` | Selects `FRMPART.PAL`, `TABS.PAL`, or `NPAL5.PAL` and draws the tile; older descriptive alias was `DrawFrame`. |
| `OnChangeMessage` | `0x004616b0-0x004616c8` | Common LObject callback; handles `message->m_type == 0x676f6f67` (`goog`) by destroying/dismissing itself. The owner argument is unused here. |
| `ScalarDeletingDestructor` | `0x004616e0-0x0046178a` | Destructor and optional delete wrapper. |

## C++ Placement

This class page emits the complete `AboveFrame.h` declaration through `RECONSTRUCTION_H CODE` and emits only `#include "AboveFrame.h"` through `RECONSTRUCTION_CPP CODE`. The include is position `0` under [UID:000577][AboveFrame](by-file/AboveFrame.md), before position `1` file-static definitions and all method/helper users. Source-authored constructor, destructor, `OnPaint`, and `OnChangeMessage` bodies belong to [UID:0000YH][0x004610f0-0x0046178a.AboveFrame](by-memory/0x004610f0-0x0046178a.AboveFrame.md); [UID:0000U2][BuildAboveFrameBorder_00461310](by-item/BuildAboveFrameBorder_00461310.md) owns the builder; and [UID:0000YI][0x004615b0-0x00461658.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md) owns release/recreate. Adjustor thunks, the scalar deleting wrapper, vtable/RTTI bytes, alignment, and pooled literals remain compiler/linker output with no handwritten source.

Generated-order preflight after command 18111 proved an explicit emitter position is required: unpositioned UID0001P1 definitions otherwise followed their function users. This class uses position `0` so the header include is first; UID0001P1 uses position `1` so definitions immediately follow it and precede every blank-position helper body.

## Evidence Notes

- IDA MCP reports the factory at `0x00461310` calls the constructor nine times; the tenth direct constructor ref is the dynamic recreate helper at `0x004615d0`.
- IDA MCP reports `0x004615b0` releases the dynamic `AboveFrame` slot and the adjacent helper rebuilds it, despite the misleading IDA name on the creator.
- 2026-06-04 exact xref recheck splits the ten direct constructor refs into nine from the border factory at `0x00461310` and one from the dynamic recreate helper at `0x004615d0`.
- IDA MCP confirms three `AboveFrame` vtable bases at `0x00610edc`, `0x00610f28`, and `0x00610f58`.
- 2026-05-31 IDA MCP proves exact vtable-data child [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md), starting at the primary RTTI locator and ending before UTF-16 `FRMPART.EPF` string data at `0x00610f60`.
- 2026-06-12 A004 split refresh adds source-local by-vtable child [UID:0003I2][AboveFrameVtables](by-type/by-vtable/AboveFrameVtables.md), routed here at child `88/93` with this direct parent at `85/90`; live IDA MCP reconfirmed the three decorated `AboveFrame` table bases, constructor/destructor/scalar-destructor vptr stores, slot target sizes, unique signature, and `FRMPART.EPF` successor boundary.
- The address-like value `0x00520046` is adjacent UTF-16 `FRMPART.EPF` string data after the short tertiary vtable, not an `AboveFrame` method.
- Live IDA string decoding ties the class to `FRMPART.EPF`, `FRMPART.EPD`, `TABS.EPF`, `FRMPART.PAL`, `TABS.PAL`, and `NPAL5.PAL`.
- `EPFLibrary::LoadFrame`-style calls should be treated as `ResourceLayoutTable`/`g_pEPFLib` registry calls until an actual `EPFLibrary` class is proven.
- 2026-06-11 A005 live IDA MCP parent-gate refresh reconfirms `AboveFrame` constructor/destructor/draw/notify/scalar-deleting-destructor boundaries, all three vtable bases, vptr stores at `0x00461139`/`0x0046113f`/`0x00461149`, `0x004612cc`/`0x004612d2`/`0x004612dc`, and `0x0046170c`/`0x00461712`/`0x0046171c`, and the exact `0x00610ed8-0x00610f60` vtable-data boundary before UTF-16 `FRMPART.EPF`.
- 2026-06-20 B006 local PE/exported-record recheck agrees with the existing route and refines the declaration-level draft: `m_framePaletteMode` is a byte at `+0x130`, `OnPaint` is the preferred source-facing paint slot name with `DrawFrame` only a descriptive alias, and the scalar deleting destructor/adjustor thunks remain compiler output generated from this class declaration. The former `OnNotify`/tagged-message interpretation is superseded by the 2026-07-13 common LObject callback evidence.
- 2026-06-21 B007 Rule 26 report review found no missing class-level facts after the B003/B006 incorporation. The report's valid class facts are already present here: constructor order `frameIndex, top, left`, `EPFTileContext` and bounds fields, byte-sized `m_framePaletteMode`, `FRMPART`/`TABS` resource and palette selection, `goog` tag handling through `message + 4`, dynamic slot rebuild from `g_pGeneralPurposePanel->m_activeChildIndex + 5`, FrameChrome source placement, and generated no-code treatment for adjustor/scalar destructor support. B007's `DrawFrame` wording remains only a descriptive alias; `OnPaint` is the source-facing virtual name used by this class page.
- 2026-07-26 B004 UID0001P1 evidence confirms the class pointer storage as five file-static scalars plus two five-entry arrays, all loader-zero and used only by FrameChrome. The current IDB lacks an `AboveFrame` named type, but that decompiler prestate does not weaken the complete documentation-backed class declaration; the supervisor Gate 2B plan uses a pointer-safe forward type for data modeling rather than inventing a partial complete UDT.

## Assignment Gate

This class clears the strict gate at `93/95` with [UID:000577][AboveFrame](by-file/AboveFrame.md) as its active source root. The score reflects a complete `0x134` layout, formal declaration, all source-authored methods, active startup/dynamic routes, slots, resources, and exact compiler-product exclusions. It is capped below final certainty because the historical basename and private spellings are inferred rather than symbol-proven. The source-local vtable page [UID:0003I2][AboveFrameVtables](by-type/by-vtable/AboveFrameVtables.md) and exact vtable-data child [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md) attach to this class but emit no raw tables.

## Cross-References

- [UID:000577][AboveFrame](by-file/AboveFrame.md)
- [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- [UID:0000YH][0x004610f0-0x0046178a.AboveFrame](by-memory/0x004610f0-0x0046178a.AboveFrame.md)
- [UID:0003I2][AboveFrameVtables](by-type/by-vtable/AboveFrameVtables.md)
- [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md)
- [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md)
- [UID:0000YJ][0x004616c8-0x004616de.AboveFrameAdjustorThunks](by-memory/0x004616c8-0x004616de.AboveFrameAdjustorThunks.md)
- [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md)
- [UID:0000YI][0x004615b0-0x00461658.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md)
- [UID:0000U2][BuildAboveFrameBorder_00461310](by-item/BuildAboveFrameBorder_00461310.md)
- [UID:00005I][FramePartPane](by-class/FramePartPane.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)

## Changes

### 2026-08-25 - UID0000JL accepted split implementation

- Changed `89/93 -> 93/95`, moved canonical owner/emitter from the synthetic FrameChrome umbrella to [UID:000577][AboveFrame](by-file/AboveFrame.md), and replaced the translation-unit include with `AboveFrame.h` at source position `0`.
- Replaced the duplicate/unproved two-bounds declaration with the accepted `0x134` layout: one `EPFTileContext`, one explicit positioned `RectBounds`, one mode byte, and three tail-padding bytes. The complete H block now includes its direct dependencies.
- Preserved every resource, caller, vtable, slot, and compiler-product fact while making the destructor distinction explicit: `AboveFrame::~AboveFrame` unregisters its listener but does not invent a `RemoveFromLayer()` call absent from the observed body.

### 2026-07-26 - Agent-B004 UID0001P1 callback synchronization

- Changed `88/92 -> 89/93`, moved the existing complete `AboveFrame` declaration from CPP to H byte-for-text, and replaced the CPP channel with exact `#include "FrameChrome.h"`.
- Added accepted file-static slot names/linkage, loader-zero storage, five-scalar/two-array topology, the no-source linker gap, fixed program-lifetime state, dynamic delete-without-clear/recreate behavior, direct UID0000JL route, and current IDA type prestate while preserving every class layout/method/resource/vtable fact and compiler-glue exclusion.
- Generated-order preflight correction: set emitter position `0` after command 18111 showed that a blank position did not guarantee the required include-before-definition order.

### 2026-07-13 - Agent-B003 UID0000ZW callback synchronization

- Changed `87/91` to `88/92` and replaced the stale `OnNotify(void *, const TaggedPaneMessage *)` declaration with the common `OnChangeMessage(LObject *, Message *)` virtual proved by ChangeMan dispatch and this vtable slot.
- Recorded the inherited BackPane registration expression and retained constructor, paint, resources, layout offsets, FrameChrome ownership, and all generated destructor/thunk exclusions.
- Removed raw offset and audit comments from the formal declaration while preserving every layout fact in `Observed State`; kept source-facing `virtual` declarations without relying on newer `override` syntax.

### 2026-06-20 - B003 AboveFrame source-quality implementation

- Before: `85/90`; class fields and helper routing were documented but the class page still used older `DrawFrame`/raw-slot wording, stale refresh-helper path `0x00461657`, and no formal declaration.
- After: `87/91`; added declaration-only C++, source-facing constructor order `frameIndex/top/left`, field names `m_tileContext`, `m_tileBounds`, `m_positionedBounds`, and `m_framePaletteMode`, `OnPaint`/`OnNotify` naming, dynamic slot `g_pDynamicAboveFrame`, and the `g_pGeneralPurposePanel->m_activeChildIndex + 5` recreate input.
- Summary/evidence: accepted B003 report revalidated the exact method/helper split, resource and palette literals, ten constructor refs, `goog` message field `+4`, FrameChrome slot ownership, and generated-code separation. Method bodies remain child-routed; compiler adjustor/scalar destructor glue remains no-code.

### 2026-06-20 - B006 AboveFrame Rule 26 reconciliation

- Score unchanged at `87/91`; the B006 report independently rechecked local PE bytes, exported function records, and existing IDA-derived docs, and found the same FrameChrome ownership/source split.
- Incorporated details: declaration draft now uses an override destructor, protected `OnPaint`/`OnNotify`, byte-sized `m_framePaletteMode`, exact `TABS.EPF` index expression, and an explicit rejection of the old `frameIndex, left, top` coordinate interpretation. Remaining uncertainty is final original private spelling, not class identity or source placement.

### 2026-06-21 - B007 Rule 26 report review

- Score unchanged at `87/91`; B007's conservative `86/90` aggregate recommendation does not lower this class page because the class declaration and evidence notes already contain the same class-level facts with stronger existing support.
- Verified/reconciled: class owns the method semantics, [UID:0000JL][FrameChrome](by-file/FrameChrome.md) owns the source route, exact method/body children carry source bodies, `BuildAboveFrameBorder` and refresh helpers remain file helpers, and compiler adjustor/scalar destructor glue remains no-code.

### 2026-06-04 - Live IDA refresh and parent assignment

- Before: score was `72/88`, autogen parent was blank, and the page still used stale recovered-source wording for layout evidence.
- Changed to: score is now `84/90`, attached to [UID:0000JL][FrameChrome](by-file/FrameChrome.md), and replaced stale source wording with live IDA offset/resource/vtable evidence.
- Summary/evidence: live IDA confirms constructor/destructor/draw/notify/scalar-deleting-destructor ranges, ten constructor call sites, vtable bases `0x00610edc/0x00610f28/0x00610f58`, offsets `+0xf8/+0x108/+0x120/+0x130`, resources `FRMPART.EPF`, `TABS.EPF`, `FRMPART.EPD`, palettes `FRMPART.PAL`, `TABS.PAL`, `NPAL5.PAL`, notification tag `goog`, and boundary padding.

- Before: the `AboveFrame` memory range and scalar deleting destructor ended at `0x00461789`.
- After: the range and scalar deleting destructor end at `0x0046178a`.
- Summary/evidence: IDA MCP reports the scalar deleting destructor as `0x004616e0-0x0046178a`; byte checks show `0x00461789` is part of the final return encoding and `0x0046178a-0x00461790` is padding.
- 2026-05-31:
  - Before: class metadata did not explicitly mark the class reconstructable, and vtable evidence named the bases without an exact `.rdata` child.
  - After: class metadata is reconstructable, scoring is `72/88`, and the exact vtable-data child [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md) is linked.
  - Summary/evidence: IDA MCP dword and xref checks prove the exact RTTI/vtable span and exclude the adjacent UTF-16 `FRMPART.EPF` bytes from the vtable.

### 2026-06-11 - Parent-Gate Refresh For Vtable Data

- Before: the class had strong local evidence but remained at `84/90`, which blocked the exact `AboveFrame` vtable-data page under the strict child/direct-parent gate.
- After: completion is `85`, and the assignment-gate text identifies this class as the direct parent for [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md).
- Summary/evidence: live IDA MCP reconfirmed function boundaries, constructor/destructor/scalar-destructor vtable stores, the three vtable bases, and the exact `FRMPART.EPF` string boundary.

### 2026-06-12 - Source-Local Vtable Split

- Before: this class pointed at the mixed [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md) page as the only by-vtable anchor.
- After: this class points at [UID:0003I2][AboveFrameVtables](by-type/by-vtable/AboveFrameVtables.md) as its source-local by-vtable child; score remains `85/90`.
- Summary/evidence: A004 live IDA MCP rechecked the `0x00610ed8-0x00610f60` `AboveFrame` cluster, lifecycle vptr stores, slot target sizes, unique signature, and successor `FRMPART.EPF` boundary, proving the child can route here under the strict gate.
