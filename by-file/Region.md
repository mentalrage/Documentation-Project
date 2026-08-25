*** UID:0000N3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Region

## Status

- Confidence: very strong for the complete Region.cpp/Region.h inventory, exact `0x14` layout, behavior, source order, ownership, emitter routing, compiler-data distinction, and source-family boundaries. Original private symbol spelling and exact formatting remain inferred.
- Proposed module: `ui/core/Region.h` for the complete `Region` declaration and `ui/core/Region.cpp` for all 19 source methods. Historical `Motion` receiver spellings are superseded reconstruction provenance, not animation `Motion.cpp` ownership evidence.
- Historical recovered-source note: `source-3/simroot_v2/class_Region.cpp` and the rectangle-helper portion of `class_Motion.cpp` were useful intermediate groupings, but they are not the current source contract.
- Main address doc: [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md)
- UID0001FW source status: the main address doc is source-ready at `94/94`, carries the 15 parent bodies, and nests UID00042Q/R/S/T at source positions `10/20/30/40` immediately before pointer-returning `GetRect`. Exact original spelling for a few private helpers remains a confidence cap; UDT, ownership, source placement, declaration, and code coverage are resolved.

## File Role

`Region.cpp` owns the single `Region` rectangle/dirty-region class used by pane, layer, GrafPort, scroll, and render invalidation code. The exact source island is `0x00554680-0x00554b38`: construction/destruction plus empty, set, copy, intersection, union, subtraction, offset, containment, same-bounds, and get-rect methods over `RectBounds m_bounds` at `+0x04`. The historical `Motion` names for parts of this island are rejected active source identities. The timer-driven animation `Motion` class is a separate `0x1c` object in `NexusTK/render/Motion.cpp` with different inheritance, fields, constructor, vtables, and behavior.

## UID000090 Canonical Region Source Contract - 2026-07-31

- `NexusTK/ui/core/Region.h` owns one complete `Region : public LObject` declaration with `RectBounds m_bounds` at `+0x04`, exact size `0x14`, and the full empty/set/copy/intersection/union/subtraction/offset/containment/equivalence/get-rect API.
- `NexusTK/ui/core/Region.cpp` owns the constructor/destructor and all exact method bodies in `0x00554680-0x00554b38`. UID0001FW and exact children UID00042Q/UID00042R/UID00042S/UID00042T now emit canonical `Region` receiver/type spelling without moving or merging any range.
- Historical `Motion` receiver spellings in this page and earlier reports are retained as superseded source-name assumptions. They do not establish a second dirty-region declaration, animation-class ownership, or a `Motion.cpp` implementation route.
- `RectBounds.h` remains the lower-level value-type dependency. Region's vtable/RTTI remain compiler-generated consequences of the declaration and are not authored as raw tables in this file.

The companion `Region.h` carries the complete `class Region : public LObject` declaration, virtual destructor, intersection declaration, and `RectBounds m_bounds`. Current IDA's exact `0x14` Region UDT and two-entry Region/LObject RTTI hierarchy match that source shape. MSVC generates [UID:0002OP][0x00622f54-0x00622f64.RegionVtableData](by-memory/0x00622f54-0x00622f64.RegionVtableData.md) and [UID:0001YL][RegionVtable](by-type/by-vtable/RegionVtable.md) from the declaration; neither table is reproduced as raw address data in Region.cpp.

Keep the lower-level four-int [UID:0000N2][RectBounds](by-file/RectBounds.md) value object and point/rectangle free helpers in their own source family. `Region` consumes those primitives for dirty-region behavior, but it should not absorb the broad `0x004b78d0-0x004b7f87` geometry helper island.

This is UI-core/render-support infrastructure. It should not absorb the timer-driven animation `Motion` constructor/timer cluster at `0x00539bc0-0x0053a10c`, the discontiguous Motion scalar deleting destructor at `0x0053d590-0x0053d614`, the message/dialog packet dispatcher at `0x0054c200`, or `Motion.tbl` vector helpers used by `NewHumanImageLib`.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `Region` parent methods | `0x00554680-0x00554a18`, `0x00554ae0-0x00554b38` through UID0001FW | Constructor, empty/set/copy/intersection/union/subtraction/offset/predicate/get-rect methods plus the source destructor represented by compiler deleting-wrapper bytes. |
| `Region` nested methods | `0x00554a20-0x00554adb`, indexed by UID0002R9 and emitted by UID00042Q/R/S/T | `Intersects`, `ContainsRect`, `Contains`, and `HasSameBoundsAs`, routed through UID0001FW at positions `10/20/30/40`. |
| stored rectangle layout | current IDA `Region` UDT plus constructor/RTTI | Exact `0x14` bytes: `vftable` at `+0x00`, four-int `RectBounds m_bounds` at `+0x04`; RTTI records public zero-displacement `LObject` inheritance. |
| compiler-generated Region RTTI/vtable | [UID:0002OP][0x00622f54-0x00622f64.RegionVtableData](by-memory/0x00622f54-0x00622f64.RegionVtableData.md), [UID:0001YL][RegionVtable](by-type/by-vtable/RegionVtable.md) | COL plus three slots: deleting-destructor wrapper, inherited `LObject::GetRuntimeClass`, and inherited `LObject::OnChangeMessage`; generated from `Region.h`, not authored as a Region.cpp table. |

The current parent formal emits `Region::Region`, `Region::~Region`, `IsEmpty`, `SetEmpty`, `SetRect`, `CopyRectFrom`, `IntersectWith`, `IntersectWithRect`, `UnionWithRect`, `UnionWith`, `SubtractRect`, `SubtractRectFrom`, `Offset`, `IntersectsRect`, and pointer-returning `GetRect`. The four exact child bodies remain separate formals and expand at the parent's `[[CHILDREN]]` marker; they are not duplicated by the parent.

## Historical Dirty-Region Motion Helper Notes - Superseded 2026-08-11

Earlier documentation treated the raw helper pocket as four Region.cpp methods with a dirty-region `Motion` receiver. That was a useful intermediate assumption, but the current `Region` UDT, Region constructor/destructor brackets, Region RTTI/vtable, exact receiver layout, and incompatible animation `Motion` UDT supersede it. The old spellings are retained below only as historical aliases:

| Current method | Historical alias | Range | Current source route | Behavior |
| --- | --- | --- | --- | --- |
| `Region::Intersects(const Region &region) const` | `Motion::Intersects` | [UID:00042Q][0x00554a20-0x00554a3c.MotionIntersectsRaw](by-memory/0x00554a20-0x00554a3c.MotionIntersectsRaw.md) | UID0001FW nested position `10` | Tests both stored bounds through `IntersectRects(..., NULL)`. |
| `Region::ContainsRect(const RectBounds *bounds) const` | `Motion::ContainsRect` | [UID:00042R][0x00554a40-0x00554a56.MotionContainsRectRaw](by-memory/0x00554a40-0x00554a56.MotionContainsRectRaw.md) | UID0001FW nested position `20` | Tests whether this stored bounds contains supplied bounds. |
| `Region::Contains(const Region &region) const` | `Motion::Contains` | [UID:00042S][0x00554a60-0x00554a9b.MotionContains](by-memory/0x00554a60-0x00554a9b.MotionContains.md) | UID0001FW nested position `30` | Stack-copies `region.m_bounds` and tests containment. |
| `Region::HasSameBoundsAs(const Region &region) const` | `Motion::HasSameBoundsAs` | [UID:00042T][0x00554aa0-0x00554adb.MotionHasSameBoundsAsRaw](by-memory/0x00554aa0-0x00554adb.MotionHasSameBoundsAsRaw.md) | UID0001FW nested position `40` | Stack-copies `region.m_bounds` and compares all edges through `RectsEquivalent`. |

The receiver is the exact `Region` object: `LObject` vptr at `+0x00`, then `RectBounds m_bounds` at `+0x04`, total `0x14`. Historical mixed MapPane examples using `Motion &last` must be read as superseded receiver spelling; their queue/containment behavior remains valid.

The lower helper `RectContainsRect` takes arguments as `RectContainsRect(innerBounds, outerBounds)`. Therefore both Region containment methods treat this object's stored rectangle as the outer/container rectangle.

## UID0000N3 Whole-File Completion - 2026-08-11

The complete hand-authored method inventory, in physical source order, is:

| Order | Exact range | Source method / disposition |
| --- | --- | --- |
| 1 | `0x00554680-0x005546e1` | `Region::Region` |
| 2 | source destructor represented by `0x00554b00-0x00554b38` compiler wrapper | `Region::~Region`; wrapper itself is compiler-covered |
| 3-14 | `0x005546f0-0x00554a18` | `IsEmpty`, `SetEmpty`, `SetRect`, `CopyRectFrom`, `IntersectWith`, `IntersectWithRect`, `UnionWithRect`, `UnionWith`, `SubtractRect`, `SubtractRectFrom`, `Offset`, `IntersectsRect` |
| 15 | `0x00554a20-0x00554a3c` | nested `Intersects` |
| 16 | `0x00554a40-0x00554a56` | nested `ContainsRect` |
| 17 | `0x00554a60-0x00554a9b` | nested `Contains` |
| 18 | `0x00554aa0-0x00554adb` | nested `HasSameBoundsAs` |
| 19 | `0x00554ae0-0x00554af1` | pointer-returning `GetRect` |
| compiler consequence | `0x00554b00-0x00554b38` | scalar-deleting destructor; no handwritten duplicate |

The range is exactly 1,208 bytes with SHA256 `82FF3091560354702FEB2CC07A8CE78D1CD309D1DFA745F3A2192684827E7872`. Its 18 internal gaps are `0xcc` alignment, not source items. The class has no file-owned global, static, literal, resource, import, or handwritten table. UID0002OP/UID0001YL cover the compiler-generated Region RTTI/vtable. `RectBounds.h` supplies the value type and the complete eleven-helper related inventory, but `Region.cpp` directly consumes exactly seven of those free helpers: `InitRectBounds`, `IntersectRects`, `UnionRects`, `OffsetRect`, `IsRectEmptyOrInvalid`, `RectsEquivalent`, and `RectContainsRect`. The other four declarations remain shared RectBounds-family API coverage and are not direct Region dependencies.

Historical pre-completion generated state: Region.cpp contained all bodies but placed the four children before the constructor; Region.h omitted `Intersects` and declared `GetRect` as `void`; RectBounds.h omitted the free-helper prototypes. The accepted emitter graph fixed source order by placing UID0001FW's `[[CHILDREN]]` immediately before pointer-returning `GetRect`, completed Region.h, and routed UID00015S declarations inside the RectBounds header guard.

Supervisor-generated closure command `000000022730` at `2026-08-12T10:46:24-04:00` completed and was physically reread for this repair. `auto-generated/NexusTK/ui/core/Region.cpp` is SHA256 `466BBD4FCBE3197D9606F6FF8663BAD1C9D411A5AB15FD0AE367A3CF3D4EBB90`, 5,386 bytes / 199 lines, with exactly 19 definitions in physical source order and no empty or placeholder marker. `Region.h` is SHA256 `D9FEBA50DE6E75083DDB107D7FAC9D601F7BB061E463550DFFF07E0806A227EA`, 1,462 bytes / 44 lines, with all 19 declarations, `Intersects` at line 32, and pointer-returning `GetRect` at line 36. `RectBounds.h` is SHA256 `A1A8FC3476DEE5E506E141C27547B22D28CE1BF90EB49BA7335DCE0199A11C16`, 2,271 bytes / 54 lines, with all eleven free-helper declarations at lines 42-52 inside the guard. The dated tracker snapshot from the same command is SHA256 `E1A1FEC167438A8E8C3E064697F0A540A001F12487315BF5552A1654A49A58BB`, 2,044,210 bytes / 9,604 lines, and records Region as `8/8`, `100.0%` at line 284; tracker identity remains lifecycle-sensitive and must be reread dynamically at later gates.

## Evidence Notes

- Historical 2026-07-04 B014 UID0001FW implementation checkpoint: accepted MCP session `nexustk_supervisor_20260704` reconfirmed exact modeled ranges, broad xrefs, Region vtable/RTTI evidence, and at that time reported missing local `Region`/`Motion`/project `RectBounds` UDTs. Current 2026-07-24 IDA now has an exact `Region` UDT; that old absence is superseded, while the source-name corrections and range/xref evidence remain valid.
- IDA MCP is reachable through the manual `/mcp` flow and confirms real function starts at `0x00554680`, `0x005546f0`, `0x00554760`, `0x005547a0`, `0x005547e0`, `0x00554a00`, and `0x00554b00`.
- IDA decompilation of `0x00554680` constructs `LObject`, installs the `Region` vtable, and clears a four-int rectangle at `this + 4`.
- IDA decompilation of `0x00554a00` calls the shared rectangle intersection helper over the stored rect, and `0x00554b00` destroys the base object then optionally frees storage.
- 2026-05-26 IDA `py_eval` recheck confirms all mapped function starts from `0x00554680` through `0x00554b00`, `Region` vtable `0x00622f58`, constructor store `0x005546c1`, and `Region` RTTI/name records.
- IDA caller checks show broad pane/layer/render fanout for the rectangle helpers, including `Layer`, `GrafPort`, `Pane`, scroll, text, and map/UI paths. That fanout supports a reusable UI-core helper file instead of feature ownership.
- `class_Region.cpp` currently includes unrelated methods such as `GetUsagePercent`, `ToLong`, a wide-string constructor, and `SimpleUString::c_str`. These are generated owner pollution outside the local rectangle island. The `0x0041a580` `GetUsagePercent` helper is now documented under [UID:0000WG][0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers](by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md).
- 2026-06-01 IDA MCP recheck of [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md) confirms exact modeled function endpoints, broad UI/render caller fanout, lower-level rectangle primitive callees, and raw helper bodies at `0x00554a20`, `0x00554a40`, and `0x00554aa0`.
- 2026-06-11 IDA MCP live refresh reconfirmed the exact local Region/dirty-rectangle island: `Region::Region` remains `0x00554680-0x005546e1` with 90 xrefs and the vtable store at `0x005546c1`; the helper starts from `0x005546f0` through `0x00554ae0` remain stable; the historically named `Region::IntersectWithRect` row at `0x00554a00-0x00554a18` has 51 xrefs and is now source-facing `Region::IntersectsRect`; and the scalar deleting destructor wrapper remains `0x00554b00-0x00554b38` with its only data ref from `0x00622f58`.
- The same 2026-06-11 pass reconfirmed the `Region` vtable slice `0x00622f54-0x00622f64`: COL pointer `0x0064ebbc`, destructor slot `0x00554b00`, inherited/shared slot `0x004f4b10`, no-op/default slot `0x0041b6c0`, and `RightButtonMenuPane` RTTI at `0x00622f64`.
- 2026-07-24 B003 current live audit identifies the inherited slots as `LObject::GetRuntimeClass` and typed default no-op `LObject::OnChangeMessage`, walks a two-entry Region/LObject RTTI hierarchy, and reads the exact `Region` UDT (`vftable` +0x00, `RectBounds m_bounds` +0x04, total `0x14`). This evidence fixes the declaration in `Region.h` and confirms that the COL/vtable slice is normal compiler output from that declaration.
- The exact `0x00622f54-0x00622f64` table contains bytes `BC EB 64 00 00 4B 55 00 10 4B 4F 00 C0 B6 41 00` in `.rdata` at raw offset `0x221954`, followed immediately by `RightButtonMenuPane` RTTI. It is not a source array and must not widen the Region.cpp implementation range.
- 2026-06-26 B008 implementation of [UID:0002R9][0x00554a20-0x00554adb.RegionRawRectangleHelpers](by-memory/0x00554a20-0x00554adb.RegionRawRectangleHelpers.md) records live MCP session `80de0a67`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, raw/no-function starts at `0x00554a20`, `0x00554a40`, and `0x00554aa0`, modeled `sub_554A60` at `0x00554a60-0x00554a9b`, exact internal padding, `RectContainsRect(innerBounds, outerBounds)` semantics, and Region.cpp ownership for the four split child methods.

## Strict Assignment Gate

This file clears the source-ready parent gate at `94/94`. It is the canonical source parent for [UID:0000BV][Region](by-class/Region.md) because the complete 19-method inventory, exact layout/ranges/padding, nested emitter order, header/source formals, compiler-data child, consumer fanout, and exclusion boundaries are documented with IDA-backed evidence.

## Boundary Rules

- Keep [UID:0001DD][0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster](by-memory/0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster.md) and [UID:0002QZ][0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor](by-memory/0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor.md) in a separate animation/game-render source candidate.
- Keep `HandleDialogPacket_54C200` with [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md).
- Keep `VectorGrowMotion_004E5240` and `DestroyMotionVector_004E5DD0` with [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) because they are `Motion.tbl` asset-vector helpers.
- Keep [UID:0000KL][Layer](by-file/Layer.md), [UID:0000MC][Pane](by-file/Pane.md), [UID:0000JR][GrafPort](by-file/GrafPort.md), and [UID:0000NF][ScrollBar](by-file/ScrollBar.md) as consumers; their broad calls into this island are dependency evidence, not ownership evidence.

## Cross-References

- [UID:0000BV][Region](by-class/Region.md)
- [UID:00008R][Motion](by-class/Motion.md)
- [UID:0000LL][Motion](by-file/Motion.md)
- [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md)
- [UID:0002R9][0x00554a20-0x00554adb.RegionRawRectangleHelpers](by-memory/0x00554a20-0x00554adb.RegionRawRectangleHelpers.md)
- [UID:00042Q][0x00554a20-0x00554a3c.MotionIntersectsRaw](by-memory/0x00554a20-0x00554a3c.MotionIntersectsRaw.md)
- [UID:00042R][0x00554a40-0x00554a56.MotionContainsRectRaw](by-memory/0x00554a40-0x00554a56.MotionContainsRectRaw.md)
- [UID:00042S][0x00554a60-0x00554a9b.MotionContains](by-memory/0x00554a60-0x00554a9b.MotionContains.md)
- [UID:00042T][0x00554aa0-0x00554adb.MotionHasSameBoundsAsRaw](by-memory/0x00554aa0-0x00554adb.MotionHasSameBoundsAsRaw.md)
- [UID:0001YL][RegionVtable](by-type/by-vtable/RegionVtable.md)
- [UID:0000WG][0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers](by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md)
- [UID:0000N2][RectBounds](by-file/RectBounds.md)
- [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md)
- [UID:0000KL][Layer](by-file/Layer.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000JR][GrafPort](by-file/GrafPort.md)
- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)

## Changes

- 2026-07-24 B003 UID0002OP support implementation callback: Preserved `86/85`, FILE ownership, proposed source root, dirty-region Motion caveats, and all existing helper evidence. Added the explicit `Region.h` declaration/`Region.cpp` definition split, current exact Region UDT and Region/LObject hierarchy, inherited virtual identities, and compiler-generated RTTI/vtable route through covered-by UID0002OP/UID0001YL pages. Historicalized the superseded no-local-UDT checkpoint without pruning it.

- 2026-07-04 B014 UID0001FW implementation sync:
  - Preserved file score/path/owner metadata.
  - Recorded that [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md) is source-ready at `90/91` with formal C++ for the modeled non-child Region/Motion rectangle helpers.
  - Added the `Motion::IntersectWithRect` and `Region::IntersectsRect` source-name corrections, source destructor vs scalar-deleting wrapper distinction, no-local-UDT confidence cap, and the rule that UID00042Q/R/S/T child bodies remain direct child emitters.

- 2026-06-26 B008 [UID:0002R9][0x00554a20-0x00554adb.RegionRawRectangleHelpers](by-memory/0x00554a20-0x00554adb.RegionRawRectangleHelpers.md) implementation sync:
  - Preserved scores and metadata.
  - Replaced the tentative `Motion.cpp` companion wording with the accepted Region.cpp dirty-region helper route.
  - Added the four exact child helper entries, receiver layout, MapPane queue compatibility, corrected `RectContainsRect(innerBounds, outerBounds)` argument-order note, and the guard that these Motion-prefixed dirty-rectangle methods do not migrate to the timer-driven animation Motion source file.

- 2026-06-13 C001 Goal 2 barrier repair: Updated the Motion exclusion text after the old broad `0x00539bc0-0x0053d614.MotionAnimation` range was narrowed to [UID:0001DD][0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster](by-memory/0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster.md), with the scalar deleting destructor kept as [UID:0002QZ][0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor](by-memory/0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor.md).

- 2026-05-28:
  - Before: the safe Region/rectangle helper island was cited as `0x00554680-0x00554b37`.
  - After: corrected it to `0x00554680-0x00554b38`.
  - Evidence: IDA MCP disassembly shows `0x00554b37` is the final byte of `Region::ScalarDeletingDestructor`'s `retn 4`, with padding beginning at `0x00554b38`.

- 2026-06-01:
  - Before: the projected source path was blank and the proposed contents used shortened Region/rectangle helper endpoints.
  - After: set projected path to `NexusTK/ui/core/`, corrected the Region/rectangle helper endpoints, and added the raw helper child page reference.
  - Evidence: IDA MCP endpoint/callee/raw-byte recheck of [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md).

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Summary/evidence: the page documents Region/dirty-rect role, contents, IDA evidence, boundary rules, generated-owner pollution, range correction, and cross-references; confidence remains capped by final original filename and historical `Motion` helper naming.

- 2026-06-11 A004 normal task:
  - Before: the file was `86/80`, so it documented the Region source family but did not clear the strict direct-parent confidence gate for the `Region` class.
  - After: raised confidence to `85` and added a strict-gate note while keeping completion at `86`.
  - Evidence: live IDA MCP reconfirmed local function boundaries/caller counts, the predicate now source-facing as `Region::IntersectsRect`, scalar deleting destructor wrapper data ref, the exact Region vtable cells, and the `RightButtonMenuPane` successor boundary; existing boundary rules still keep animation `Motion` and unrelated generated pollution outside this source root.

## 2026-07-23 B004 Accepted UID0002E6 Reconciliation (0000N3)

- Accepted source: B004 UID0002E6 report, Gate 1 SHA F8FE25AA9AD6922244A4C7EC84D390D41DE9782819D15DCD6D192A58C1D7EF26.
- Region.cpp remains the source owner for the complete UID0000BV declaration and ordinary stack lifetime used by UID0002DL. Motion split/history evidence remains intact.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C2E6-090 | 0000BV | `Region` is a complete `LObject`-derived 0x14-byte type with `RectBounds m_bounds`; automatic construction/destruction is source-real and static `Region::Construct/Destroy` is not. | Strong | Constructor/destructor/vtable/layout evidence and exact GrafPort clip callers. | UID0000BV complete formal; UID0000N3 header/source placement; UID0002DL. | reject-stale | implemented |
