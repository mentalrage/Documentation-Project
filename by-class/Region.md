*** UID:0000BV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "Region.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_CORE_REGION_H
#define NEXUSTK_UI_CORE_REGION_H

#include "../../util/LObject.h"
#include "RectBounds.h"

class Region : public LObject
{
public:
    Region();
    virtual ~Region();

    bool IsEmpty() const;
    void SetEmpty();
    void SetRect(const RectBounds *bounds);
    void CopyRectFrom(const Region &region);
    bool IntersectWith(const Region &region);
    bool IntersectWithRect(const RectBounds *bounds);
    void UnionWithRect(const RectBounds *bounds);
    void UnionWith(const Region &region);
    void SubtractRect(const RectBounds *bounds);
    void SubtractRectFrom(const Region &region);
    void Offset(int dx, int dy);
    bool IntersectsRect(const RectBounds *bounds) const;
    bool Intersects(const Region &region) const;
    bool ContainsRect(const RectBounds *bounds) const;
    bool Contains(const Region &region) const;
    bool HasSameBoundsAs(const Region &region) const;
    RectBounds *GetRect(RectBounds *outBounds) const;

private:
    RectBounds m_bounds;
};

typedef char RegionSizeMustBe20[sizeof(Region) == 0x14 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Region

## Status

- Source file: [UID:0000N3][Region](by-file/Region.md) / `NexusTK/ui/core/Region.cpp` and `Region.h`; [UID:0000LL][Motion](by-file/Motion.md) is the separate timer-driven animation source family.
- Address range: [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md)
- Current reconstructed module: `NexusTK/ui/core/Region.cpp` and `Region.h`; `source-3/simroot_v2/class_Region.cpp` is a historical recovered grouping only.
- Vtable: [UID:0001YL][RegionVtable](by-type/by-vtable/RegionVtable.md)
- Confidence: very strong for the complete nineteen-method API, exact `0x14` UDT, compiler-generated RTTI/vtable data, source brackets, nested child order, and Region.cpp/Region.h ownership. UID0001FW and this class are both `94/94`; only exact original private spellings and formatting remain inferred.

## Class Purpose

`Region` is a small rectangle/region wrapper used by UI and rendering dirty-region code. Its local constructor initializes an empty `RECT`, and its local methods intersect with source rectangles and destroy the base object.

## UID0000N3 Current Region Source Contract - 2026-08-11

- The canonical source type is the one `Region : public LObject` class shown in the formal H channel. Current IDA UDT, RTTI, vtable, constructor/destructor brackets, continuous method island, and every accepted formal agree on this identity; no second layout-compatible dirty-region `Motion` class exists.
- The complete source API has nineteen bodies in physical order: constructor, source destructor, `IsEmpty`, `SetEmpty`, `SetRect`, `CopyRectFrom`, `IntersectWith`, `IntersectWithRect`, `UnionWithRect`, `UnionWith`, `SubtractRect`, `SubtractRectFrom`, `Offset`, `IntersectsRect`, `Intersects`, `ContainsRect`, `Contains`, `HasSameBoundsAs`, and pointer-returning `GetRect`.
- `Region` is exactly `0x14` bytes: the `LObject`/vptr view occupies `+0x00` and `RectBounds m_bounds` occupies `+0x04-+0x13`. The class has no second rectangle, animation state, hidden reserve, or multiple-inheritance view.
- The four child methods are emitted inside [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md), between `IntersectsRect` and `GetRect`, in positions 10/20/30/40. Their filenames retain historical `Motion*` provenance, but their source receivers and declarations are `Region`.
- The scalar-deleting wrapper and Region RTTI/vtable bytes are compiler-generated consequences of this declaration and source destructor. They remain documented by UID0002OP/UID0001YL and are not handwritten members.
- Region has no file-owned globals, statics, strings, resources, imports, or tables. Free geometry helpers remain `RectBounds.cpp/.h` declarations and definitions rather than Region members.
- The generated completion requirement is one ordered `Region.cpp` containing all nineteen bodies and one guarded `Region.h` containing the complete declaration above, with no duplicate, placeholder, empty-emitter, Motion-owned, or behaviorally partial item.

## UID000090 Complete Region Declaration - 2026-07-31

- The formal H now declares the full `Region : public LObject` dirty-rectangle API, not only `IntersectsRect`. It includes exact empty/set/copy/intersection/union/subtraction/offset/containment/equivalence/get-rect methods and the one `RectBounds m_bounds` field at `+0x04`.
- The complete type remains exactly `0x14` bytes and is guarded by `RegionSizeMustBe20`. `LObject` is the sole base; no `Motion` base, second rectangle, animation state, or hidden reserve fields are introduced.
- C134 compile closure wraps the canonical declaration in `NEXUSTK_UI_CORE_REGION_H` and removes the declaration-channel empty-child marker. Region is reached directly and transitively through GrafPort and Pane; one guarded definition preserves the exact `0x14` assertion, while repeated unguarded declarations caused the false redefinition/negative-size cascade in command20473.
- Canonical source receiver and parameter type is `Region`. Historical `Motion` spellings in the same physical source island are preserved below as superseded reconstruction history, not as a second dirty-region class declaration. Timer-driven animation `Motion` remains a separate source family.
- The CPP formal remains a self-header include plus `[[CHILDREN]]`; exact method bodies stay on UID0001FW and the four exact child pages.

Historical assumption: earlier documentation described a layout-compatible dirty-region `Motion` helper/record family because those bodies use a receiver header at `+0x00` and `RectBounds m_bounds` at `+0x04`. Current whole-file evidence shows that this was the Region layout itself, not a second class; callsites and old queue terminology that mixed `Region` and dirty `Motion` are retained only as provenance for the superseded interpretation.

Current generated output for `class_Region.cpp` is polluted with unrelated methods such as `GetUsagePercent`, `ToLong`, a wide-string constructor, and `SimpleUString::c_str`. The `0x0041a580` `GetUsagePercent` helper is now documented as [UID:0000WG][0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers](by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md), not dirty-region `Region`. Use only the local rectangle range as Region ownership evidence and keep the file-level source grouping in [UID:0000N3][Region](by-file/Region.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `Region::Region` | `0x00554680-0x005546e1` | Source-ready through [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md); constructs an empty region rectangle after `LObject` construction. |
| `Region::IntersectsRect` | `0x00554a00-0x00554a18` | Source-ready predicate wrapper; calls `IntersectRects(&m_bounds, bounds, NULL)` and returns whether the region intersects the source rectangle without writing an output rectangle. |
| `Region::~Region` source route | `0x00554b00-0x00554b38` | Source-ready empty destructor body; binary range is scalar-deleting wrapper evidence that performs base teardown and optional delete. |

## Primary Vtable And Current UDT

- Current live IDA defines `Region` at exact size `0x14`, with `vftable` at `+0x00` size 4 and `RectBounds m_bounds` at `+0x04` size `0x10`. This directly matches the existing formal and its `RegionSizeMustBe20` assertion.
- The complete-object locator at `0x00622f54` names Region. Its hierarchy descriptor contains exactly Region and zero-displacement `LObject`, matching the formal's public single inheritance; there is no multiple- or virtual-inheritance evidence.
- The primary vtable at `0x00622f58` has three entries: the MSVC scalar-deleting wrapper for source virtual `~Region()`, inherited `LObject::GetRuntimeClass`, and inherited `LObject::OnChangeMessage`. The latter is the typed shared default no-op at `0x0041b6c0`, not the historical unresolved `nullsub_18` identity.
- The constructor stores this exact vtable at `0x005546c1`, after `LObject` construction and before clearing `m_bounds`. Slot zero's wrapper is compiler-only support for the declared virtual destructor; it must not appear as a separate handwritten source method.
- [UID:0002OP][0x00622f54-0x00622f64.RegionVtableData](by-memory/0x00622f54-0x00622f64.RegionVtableData.md) and [UID:0001YL][RegionVtable](by-type/by-vtable/RegionVtable.md) therefore use covered-by formals. This class remains the source emitter whose declaration causes MSVC to generate the RTTI/vtable bytes.

## Historical Dirty-Region Motion Compatibility Assumption

Earlier reconstruction treated several methods in `0x00554680-0x00554b38` as a layout-compatible dirty-region `Motion` record routed through Region.cpp. Current whole-file evidence supersedes that interpretation: the bodies are `Region` methods. The table is retained as historical provenance for the old spellings and explains why they were rejected rather than deleted.

| Helper | Evidence page | Region class compatibility note |
| --- | --- | --- |
| Historical `Motion::Intersects` | [UID:00042Q][0x00554a20-0x00554a3c.MotionIntersectsRaw](by-memory/0x00554a20-0x00554a3c.MotionIntersectsRaw.md) | Superseded by `Region::Intersects`; exact `+0x04` bounds use was Region evidence, not proof of a second class. |
| Historical `Motion::ContainsRect` | [UID:00042R][0x00554a40-0x00554a56.MotionContainsRectRaw](by-memory/0x00554a40-0x00554a56.MotionContainsRectRaw.md) | Superseded by `Region::ContainsRect`; `RectContainsRect` order remains `innerBounds, outerBounds`. |
| Historical `Motion::Contains` | [UID:00042S][0x00554a60-0x00554a9b.MotionContains](by-memory/0x00554a60-0x00554a9b.MotionContains.md) | Superseded by `Region::Contains`; older MapPane prose conflated queue terminology with class identity. |
| Historical `Motion::HasSameBoundsAs` | [UID:00042T][0x00554aa0-0x00554adb.MotionHasSameBoundsAsRaw](by-memory/0x00554aa0-0x00554adb.MotionHasSameBoundsAsRaw.md) | Superseded by `Region::HasSameBoundsAs`; equivalence behavior is unchanged. |

The formerly named `Motion::SetRect`, `Motion::CopyRectFrom`, and `Motion::GetRect` are likewise historical aliases for current `Region` methods. Region.cpp owns the complete dirty-region class; [UID:0000LL][Motion](by-file/Motion.md) owns only the distinct timer-driven animation class.

The 2026-07-04 B014 UID0001FW callback made the modeled non-child bodies source-ready but still described several receivers as dirty-region `Motion`. The 2026-08-11 whole-file pass supersedes those receiver spellings with `Region`; the previous `Motion::GetNormalizedRect` and `Motion::IntersectWithRect` labels for `0x005547e0` are historical, while current source is `Region::IntersectWithRect`.

## Evidence Notes

- Historical 2026-07-04 B014 UID0001FW checkpoint: MCP session `nexustk_supervisor_20260704` reconfirmed exact modeled ranges, xrefs, and Region vtable/RTTI support but found no local project UDT/source-name records at that time. Current 2026-07-24 IDA now contains the exact `Region` UDT described below, so only the old no-UDT portion is superseded; the range/xref evidence remains valid.
- Older Wave2 notes already identify `0x00554680` as `Region::Region`.
- IDA caller/callee evidence places the adjacent [UID:00008R][Motion](by-class/Motion.md) rectangle helpers in the same dirty-region pipeline.
- IDA MCP checks on 2026-05-24 confirmed real function starts at `0x00554680`, `0x005546f0`, `0x00554760`, `0x005547a0`, `0x005547e0`, `0x00554a00`, and `0x00554b00`.
- 2026-05-26 IDA `py_eval` recheck confirms all mapped function starts from `0x00554680` through `0x00554b00`; representative xref counts include 90 callers for the constructor, 51 callers for the helper now source-facing as `Region::IntersectsRect`, and 32 callers for the offset helper.
- The same pass confirms `Region` vtable `0x00622f58`, constructor store `0x005546c1`, destructor slot `0x00554b00`, and `Region` RTTI/name records. See [UID:0001YL][RegionVtable](by-type/by-vtable/RegionVtable.md).
- [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md) is attached to [UID:0000N3][Region](by-file/Region.md) and documents the exact `Region` constructor, intersection helper, scalar deleting destructor, neighboring `Motion` rectangle helpers, broad UI/render caller fanout, and the raw helper pocket at `0x00554a20`, `0x00554a40`, and `0x00554aa0`.
- [UID:0002OP][0x00622f54-0x00622f64.RegionVtableData](by-memory/0x00622f54-0x00622f64.RegionVtableData.md) now documents the exact 16-byte COL/three-slot table at `92/94`, including current RTTI, UDT, constructor, inherited-slot, and boundary evidence plus its covered-by formal.
- [UID:0001YL][RegionVtable](by-type/by-vtable/RegionVtable.md) is reconstructable at `92/94` and points back to the exact vtable-data child. Its covered-by formal records compiler generation without duplicating this class declaration.
- [UID:0000N3][Region](by-file/Region.md) is currently reconstructable at `94/94` and keeps the complete local dirty-rectangle implementation under `NexusTK/ui/core/Region.cpp`; [UID:0000LL][Motion](by-file/Motion.md) explicitly keeps animation/vector ownership separate from this dirty-rectangle source root. The older `86/85` source-parent checkpoint is historical and superseded by the completed whole-file inventory, formal CPP/H, emitter ordering, and compiler-data boundary.
- Generated `class_Region.cpp` includes unrelated string/numeric methods outside the local rectangle neighborhood; those should be re-owned before migration.
- 2026-05-27 IDA recheck assigns generated `Region::GetUsagePercent` at `0x0041a580` to [UID:0001UI][FittingRoomDownloadProgressState](by-type/by-struct/FittingRoomDownloadProgressState.md) because its only direct caller is `FittingRoomDialog::HandleFittingAction` at `0x0041cbbc`.
- 2026-06-11 IDA MCP live refresh reconfirmed the class-local code/data evidence: constructor `0x00554680-0x005546e1` has 90 xrefs and stores the `Region` vtable at `0x005546c1`, the predicate now source-facing as `Region::IntersectsRect` remains `0x00554a00-0x00554a18` with 51 xrefs, and the scalar deleting destructor wrapper remains `0x00554b00-0x00554b38` with its data ref from the vtable slot at `0x00622f58`.
- The same pass reconfirmed the exact primary vtable cells: COL `0x00622f54 -> 0x0064ebbc`, destructor slot `0x00622f58 -> 0x00554b00`, inherited/shared slot `0x00622f5c -> 0x004f4b10`, no-op/default slot `0x00622f60 -> 0x0041b6c0`, and `RightButtonMenuPane` RTTI starts at `0x00622f64`.
- 2026-07-24 B003 current audit identifies the shared slots as `RuntimeClass *__thiscall LObject__GetRuntimeClass(LObject *this)` and `void __thiscall LObject__OnChangeMessage(LObject *this, LObject *owner, Message *message)`. Exact table dwords establish the Region slot identities even though current IDA does not materialize those two cells among the shared functions' 489 and 517 incoming xrefs.
- The same current audit read the Region/LObject RTTI hierarchy and exact `Region` UDT (`0x14` bytes, `vftable` +0x00, `RectBounds m_bounds` +0x04). These current facts supersede the older absence-of-UDT checkpoint without erasing its historical context.
- 2026-06-26 B008 [UID:0002R9][0x00554a20-0x00554adb.RegionRawRectangleHelpers](by-memory/0x00554a20-0x00554adb.RegionRawRectangleHelpers.md) implementation proves the raw helper pocket can be split into four exact Region.cpp dirty-region `Motion` methods. The modeled `Motion::Contains` child has four live xrefs, including [UID:0002QG][0x005046d0-0x005047e8.MapPaneQueuedMotionMessage](by-memory/0x005046d0-0x005047e8.MapPaneQueuedMotionMessage.md), and the zero-xref raw starts remain source-shaped retained helpers bounded by `0xcc` alignment.

## Parent And Score Rationale

| Topic | Rationale |
| --- | --- |
| Source parent | [UID:0000N3][Region](by-file/Region.md) is currently `94/94` and is the documented owner for the complete dirty-rectangle implementation in `NexusTK/ui/core/Region.cpp`; the earlier `86/85` gate rationale is historical and superseded. |
| Class-owned methods | The local constructor, source-facing `Region::IntersectsRect` predicate, and source destructor route have exact starts, callsite/vtable evidence, and consistent `LObject`-derived rectangle state usage. |
| Vtable/data boundary | [UID:0001YL][RegionVtable](by-type/by-vtable/RegionVtable.md) and [UID:0002OP][0x00622f54-0x00622f64.RegionVtableData](by-memory/0x00622f54-0x00622f64.RegionVtableData.md), both `92/94`, cover the compact Region vtable range and cleanly stop before neighboring read-only data. Their covered-by formals route compiler output back to this declaration without raw-table duplication. |
| Residual confidence limits | Current `94/94` reflects the complete nineteen-method class/header contract, exact `0x14` UDT, source ownership, nested children, and compiler-generated RTTI/vtable route. The older generated-owner-pollution and raw-helper-pocket blockers are superseded; only exact original private spellings and formatting remain inferred. |

This class currently clears the direct-parent gate at `94/94`; [UID:0001YL][RegionVtable](by-type/by-vtable/RegionVtable.md) attaches here as the source-level class declaration that emits the primary vtable. The former `85/86` checkpoint is historical and superseded.

## Cross-References

- [UID:0000N3][Region](by-file/Region.md)
- [UID:0000LL][Motion](by-file/Motion.md)
- [UID:00008R][Motion](by-class/Motion.md)
- [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md)
- [UID:0002R9][0x00554a20-0x00554adb.RegionRawRectangleHelpers](by-memory/0x00554a20-0x00554adb.RegionRawRectangleHelpers.md)
- [UID:00042Q][0x00554a20-0x00554a3c.MotionIntersectsRaw](by-memory/0x00554a20-0x00554a3c.MotionIntersectsRaw.md)
- [UID:00042R][0x00554a40-0x00554a56.MotionContainsRectRaw](by-memory/0x00554a40-0x00554a56.MotionContainsRectRaw.md)
- [UID:00042S][0x00554a60-0x00554a9b.MotionContains](by-memory/0x00554a60-0x00554a9b.MotionContains.md)
- [UID:00042T][0x00554aa0-0x00554adb.MotionHasSameBoundsAsRaw](by-memory/0x00554aa0-0x00554adb.MotionHasSameBoundsAsRaw.md)
- [UID:0001YL][RegionVtable](by-type/by-vtable/RegionVtable.md)
- [UID:0002OP][0x00622f54-0x00622f64.RegionVtableData](by-memory/0x00622f54-0x00622f64.RegionVtableData.md)
- [UID:0000WG][0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers](by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md)
- [UID:000073][Layer](by-class/Layer.md)
- [UID:00005V][GrafPort](by-class/GrafPort.md)

## Changes

- 2026-08-11 B006 UID0000N3 implementation callback: raised the class to `94/94`, completed the exact nineteen-method `Region` declaration with `Intersects` and pointer-returning `GetRect`, recorded the complete one-class source contract and compiler-data boundary, and historicalized the former layout-compatible dirty-region Motion interpretation without pruning its provenance.

- Historical/superseded 2026-07-24 B003 UID0002OP support checkpoint: Preserved `85/86` at that time, UID0000N3 ownership/emission, and the complete formal unchanged. Added current exact `Region` UDT, Region/LObject RTTI hierarchy, inherited `GetRuntimeClass`/`OnChangeMessage` slots, constructor vptr store, deleting-wrapper/source-destructor distinction, and compiler-output route through the covered-by UID0002OP/UID0001YL pages. Historicalized the older no-local-UDT and blank-source assumptions rather than pruning them; the later B006 whole-file callback supersedes that score with `94/94`.

- 2026-07-04 B014 UID0001FW implementation sync:
  - Preserved class scores and owner/emitter metadata.
  - Updated Method Notes to source-ready `Region::Region`, predicate `Region::IntersectsRect`, and source destructor `Region::~Region` while preserving scalar-deleting wrapper evidence.
  - Recorded that the modeled non-child dirty-region `Motion` helpers now emit through UID0001FW and that exact source spelling/local UDT recovery remain confidence caps rather than blank-C++ blockers.

- 2026-06-26 B008 [UID:0002R9][0x00554a20-0x00554adb.RegionRawRectangleHelpers](by-memory/0x00554a20-0x00554adb.RegionRawRectangleHelpers.md) implementation sync:
  - Preserved scores and metadata.
  - Added Region/Motion dirty-rectangle layout compatibility notes, four exact split-child helper references, MapPane queue compatibility evidence, and the source-placement guard that Motion-prefixed dirty-region helpers remain Region.cpp-owned.
  - Updated remaining-blocker wording so the old raw helper pocket is no longer treated as future-work uncertainty.

- 2026-06-06 A008:
  - Before: completion/confidence were `82/78` and `AUTOGEN_PARENT_UID` was blank even though the class, source file, memory aggregate, and vtable-data child were all above the parent-attach gate.
  - After: changed completion/confidence to `84/82`, attached the class to [UID:0000N3][Region](by-file/Region.md), and added parent/score rationale.
  - Evidence: [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md) documents exact Region/Motion rectangle ranges and caller fanout; [UID:0002OP][0x00622f54-0x00622f64.RegionVtableData](by-memory/0x00622f54-0x00622f64.RegionVtableData.md) documents the compact vtable data range; [UID:0000N3][Region](by-file/Region.md) owns the dirty-rectangle source root while [UID:0000LL][Motion](by-file/Motion.md) preserves the split-owner guard.

- 2026-06-11 A004 normal task:
  - Before: the class was `84/82`, so [UID:0001YL][RegionVtable](by-type/by-vtable/RegionVtable.md) could not attach under the strict `85/85` direct-parent gate.
  - Historical after-state, now superseded: raised the class to `85/86`, retained [UID:0000N3][Region](by-file/Region.md) as the source parent, and documented the class as a valid direct parent for the primary vtable page.
  - Historical evidence at that checkpoint: live IDA MCP reconfirmed constructor/intersection/destructor boundaries, caller/data refs, the exact vtable cells, and the successor `RightButtonMenuPane` boundary; [UID:0000N3][Region](by-file/Region.md) then cleared `86/85`. Both checkpoint scores are superseded by the current `94/94` class and file evidence.

- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and left `AUTOGEN_PARENT_UID` blank.
  - Before: The local dirty-region rectangle class remained unclassified in autogen coverage despite documented constructor, helper, vtable, and generated-owner pollution evidence.
  - After: The class is reconstructable but unassigned because the class confidence score remains below the 80/80 parent-attach gate.
  - Evidence: Live IDA MCP lookup confirms mapped starts from `0x00554680` through `0x00554b00`; existing notes keep unrelated generated string/numeric helpers outside `Region` ownership.

- 2026-05-30:
  - Before: completion/confidence were `0/0` even though the local rectangle-region methods, vtable, generated-owner pollution, and re-owned stray method were documented.
  - After: changed completion/confidence to `82/78`.
  - Evidence: existing evidence notes confirm local function starts, vtable data, constructor/destructor behavior, broad caller counts, and `GetUsagePercent` re-ownership; confidence remains below strong because generated `class_Region.cpp` contains unrelated string/numeric methods outside the local range.

- 2026-05-28:
  - Before: `Region::ScalarDeletingDestructor` and the local rectangle island ended at `0x00554b37`.
  - After: corrected the destructor and island end to `0x00554b38`.
  - Evidence: IDA MCP disassembly shows `0x00554b37` is the final byte of `retn 4`; padding begins at `0x00554b38`.

## 2026-07-23 B004 Accepted UID0002E6 Reconciliation (0000BV)

- Accepted source: B004 UID0002E6 report, Gate 1 SHA F8FE25AA9AD6922244A4C7EC84D390D41DE9782819D15DCD6D192A58C1D7EF26.
- The complete LObject-derived 0x14 Region declaration is installed with RectBounds storage and exact constructor/destructor interface; UID0002DL uses a normal stack Region object.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C2E6-090 | 0000BV | `Region` is a complete `LObject`-derived 0x14-byte type with `RectBounds m_bounds`; automatic construction/destruction is source-real and static `Region::Construct/Destroy` is not. | Strong | Constructor/destructor/vtable/layout evidence and exact GrafPort clip callers. | UID0000BV complete formal; UID0000N3 header/source placement; UID0002DL. | reject-stale | implemented |
