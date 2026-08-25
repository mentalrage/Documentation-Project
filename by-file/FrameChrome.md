*** UID:0000JL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# FrameChrome

## Current Split Disposition

- Current role: non-emitting historical UI-chrome umbrella. `PROPOSED_RECONSTRUCTION_PATH:"NONE"` intentionally prevents a synthetic `FrameChrome.cpp` or `FrameChrome.h`.
- The complete recovered family is split into active `AboveFrame.cpp/.h` and retained `FramePartPane.cpp/.h`; their exact by-file pages are the source roots after validator registration.
- `CANONICAL_OWNER:FILE` records ownership of this documentation/index page only. It does not authorize source output.
- Exact source-bearing children remain reconstructable and emit through one of the two class-centered roots. Mixed vtable/global/resource indexes, wrappers, thunks, padding, and pooled literals remain non-emitting.
- Completion/confidence `94/95` reflect complete inventory, split, behavior, liveness, layout, formal source, generated-output defects, and manual-coverage staging. Remaining uncertainty is limited to historical basenames/private spellings and the retained FramePart builder/cleanup runtime entry route.

## Current Two-Unit Inventory

### AboveFrame source unit

- Class/layout: [UID:000005][AboveFrame](by-class/AboveFrame.md), exact `0x134` layout.
- Methods/compiler island: [UID:0000YH][0x004610f0-0x0046178a.AboveFrame](by-memory/0x004610f0-0x0046178a.AboveFrame.md).
- Active helpers: [UID:0000U2][BuildAboveFrameBorder_00461310](by-item/BuildAboveFrameBorder_00461310.md) and [UID:0000YI][0x004615b0-0x00461658.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md).
- Compiler products: [UID:0000YJ][0x004616c8-0x004616de.AboveFrameAdjustorThunks](by-memory/0x004616c8-0x004616de.AboveFrameAdjustorThunks.md), [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md), and [UID:0003I2][AboveFrameVtables](by-type/by-vtable/AboveFrameVtables.md).
- File statics: [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md), including the no-source `0x0067a844-0x0067a848` gap and excluded `g_pGeneralPurposePanel` successor.
- Reachability: two startup builder callers, ten constructor calls, and two release plus two recreate callers establish active runtime use.

### FramePartPane source unit

- Class/layout: [UID:00005I][FramePartPane](by-class/FramePartPane.md), exact `0xfc` layout.
- Builder/cleanup: [UID:00022F][0x004b7120-0x004b731f.BuildFramePartPanes](by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md) and [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md).
- Methods/compiler island: [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md), with [UID:00015P][0x004b7590-0x004b75a6.FramePartPaneAdjustorThunks](by-memory/0x004b7590-0x004b75a6.FramePartPaneAdjustorThunks.md).
- Vtables/statics: [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md), [UID:0003I3][FramePartPaneVtables](by-type/by-vtable/FramePartPaneVtables.md), and [UID:0001PF][0x0069b33c-0x0069b350.FramePartPaneSlots](by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md).
- Reachability: exhaustive xref and VA/RVA pointer checks found no current builder/cleanup entry route. The complete coherent source is retained and explicitly classified inactive/unrouted rather than compiler-generated.

### Mixed indexes and resource pool

- [UID:0000PN][FrameChromeSlots](by-global/FrameChromeSlots.md) and [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md) are mixed non-emitting indexes over the exact source-local children.
- [UID:0002SG][0x00610f60-0x00610fe8.FrameChromeResourceStrings](by-memory/0x00610f60-0x00610fe8.FrameChromeResourceStrings.md) is a four-child non-emitting literal index. Literal children remain use-site-only because `FRMPART.PAL`, `TABS.PAL`, and `NPAL5.PAL` have consumers outside these source units.

## Current Source And Generated Routing

- The two new by-file roots own `NexusTK/ui/core/AboveFrame.cpp/.h` and `NexusTK/ui/core/FramePartPane.cpp/.h`.
- Formal C++ remains on exact class/memory/item pages. The by-file roots establish destination and ordering only, preventing duplicate source.
- Above source order: include/declaration route, file statics, class methods, `BuildAboveFrameBorder`, release/recreate.
- FramePart source order: include/declaration route, file-static array, builder, cleanup, class methods.
- `FrameChrome.cpp/.h` must disappear after the waited validator refresh. Five historical empty-emitter markers are routing defects resolved through these exact source/no-code dispositions, not source text.

## Current Evidence And Decisions

- Two distant code islands, separate vtable/static neighborhoods, complete class-local source orders, and active-versus-retained liveness outweigh pooled strings and the historical synthetic basename.
- `AboveFrame::~AboveFrame` unregisters the listener without an observed `RemoveFromLayer`; `FramePartPane::~FramePartPane` unregisters and removes itself from the layer.
- The raw `0x004b7320-0x004b73a3` body is source-authored cleanup; its missing function model/xrefs do not make it compiler glue.
- Compiler adjustors, scalar deleting wrappers, raw vtable/RTTI storage, linker alignment, and pooled literal storage are regenerated from declarations/use sites and emit no handwritten body.
- No PDB, map, or source path proves any basename. The selected class-centered names are the highest-probability human source shape and avoid carrying decompiler labels into final code.

## Preserved Historical One-File Documentation

The sections below are retained in full as historical evidence and prior assumptions. Their former `FrameChrome.cpp` ownership claims, unresolved split, polluted helper label, omitted raw cleanup, incomplete FramePart declaration, and mixed generated route are superseded by the current two-unit disposition above. Exact ranges, callers, xrefs, resource use, and earlier dated research remain useful evidence.

### Historical Status

- Confidence: very strong for `AboveFrame`, both direct exact slot-child routes, source-local helper placement, vtable/global support, and the accepted FrameChrome module; medium-high for the exact historical basename and retained `FramePartPane` factory liveness.
- Proposed module: `ui/core/FrameChrome.cpp`.
- Current recovered sources: `source-3/simroot_v2/class_AboveFrame.cpp` and `class_FramePartPane.cpp`
- Main address ranges: `0x004610f0-0x0046178a`, `0x004b7120-0x004b7661`
- Global slots: [UID:0000PN][FrameChromeSlots](by-global/FrameChromeSlots.md)
- Vtable/layout anchors: source-local children [UID:0003I2][AboveFrameVtables](by-type/by-vtable/AboveFrameVtables.md) and [UID:0003I3][FramePartPaneVtables](by-type/by-vtable/FramePartPaneVtables.md); mixed non-emitting index [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md), with exact backing data [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md) and [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md)
- Resource string anchor: [UID:0002SG][0x00610f60-0x00610fe8.FrameChromeResourceStrings](by-memory/0x00610f60-0x00610fe8.FrameChromeResourceStrings.md) is now a non-emitting mixed string-pool index. [UID:00044T][0x00610f60-0x00610fa4.FrameChromeFrameResourceStrings](by-memory/0x00610f60-0x00610fa4.FrameChromeFrameResourceStrings.md) is the FrameChrome-local resource-name child; the palette-tail children are shared with non-FrameChrome source routes.

### Historical File Role

This module owns visible frame-border panes built from `FRMPART`, `TABS`, and palette resources. It is UI chrome code: it creates pane objects, positions them around the screen/dialog edge, registers for the shared notification tag `0x676f6f67` (`goog`), and draws frame-part EPF/EPD resources through the EPF resource registry.

Only the `FRMPART.EPF`, `TABS.EPF`, and `FRMPART.EPD` head of the `0x00610f60-0x00610fe8` literal run is FrameChrome-local source data. The palette names in the same physical string pool are shared: `FRMPART.PAL` is also used by MapNamePane and MiniMapButtonPane, `TABS.PAL` by Group panes, and `NPAL5.PAL` by BackPane and UserStatus paint paths. Keep those palette literals on no-owner/multiple-emitter children rather than treating the whole pool as a `FrameChrome.cpp` declaration block.

This is distinct from [UID:0000JM][FrameMgr](by-file/FrameMgr.md), which schedules frame callbacks. It is also distinct from [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md), which owns the underlying resource registry and frame metadata loaders.

### Historical AboveFrame Static Storage

[UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md) is an exact source-bearing child routed directly to this file. It contributes five file-static scalar pointers and two file-static arrays:

- `g_pAboveFrameTop` at `0x0067a834`, written as EPF frame 0 or legacy frame 1;
- `g_pAboveFrameRight` at `0x0067a838`, written as frame 2 in either asset mode;
- `g_pAboveFrameLeft` at `0x0067a83c`, written as EPF frame 1;
- `g_pDynamicAboveFrame` at `0x0067a840`, written by build/recreate and deleted without clearing by release;
- no source object at `0x0067a844-0x0067a848`, which is a loader-zero linker/BSS alignment gap;
- `g_pLegacyAboveFrameTopLeft` at `0x0067a848`;
- `g_pLegacyAboveFrameLeftSide[5]` at `0x0067a84c-0x0067a860`;
- `g_pLegacyAboveFrameRightSide[5]` at `0x0067a860-0x0067a874`.

PE mapping places the 64-byte target in the unbacked `.data` virtual tail, 0x34 bytes beyond the raw-backed end at `0x0067a800`; all 16 dwords are loader-zero. Historical all-`FF` rendering is superseded and must not become a source initializer. Constant-address stores versus two indexed bases prove the five-scalar/two-array source shape. Every target xref is within the `BuildAboveFrameBorder` and dynamic release/recreate helpers, so the definitions are file-static in CPP and require no H `extern` declarations. [UID:0000PN][FrameChromeSlots](by-global/FrameChromeSlots.md) remains a false/nonemitting mixed-family index rather than an aggregate declaration owner.

The fixed slots are builder-written program-lifetime state with no cleanup/read xrefs. Only the dynamic pointer has a release/recreate lifecycle: release deletes through its scalar-deleting virtual slot without clearing, and recreate immediately overwrites it with `AboveFrame(g_pGeneralPurposePanel->m_activeChildIndex + 5, 0x4f, 0x328)` or null on allocation failure. GeneralPurposePanel is therefore a trigger/index provider, not a slot owner.

### Historical Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `AboveFrame` static pointer definitions | [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md) | Direct CPP-only file-static definitions for five scalars and two five-entry arrays; exact child excludes the no-source alignment gap and separate `g_pGeneralPurposePanel` successor. |
| `AboveFrame` | `0x004610f0-0x0046178a` | Pane for a frame or tab border piece using `FRMPART.EPF`, `TABS.EPF`, or legacy `FRMPART.EPD`. |
| [UID:0000U2][BuildAboveFrameBorder_00461310](by-item/BuildAboveFrameBorder_00461310.md) | `0x00461310-0x004615aa` | File-level factory/helper that creates fixed and legacy-loop `AboveFrame` border pieces and stores them in global frame slots. |
| `AboveFrame` refresh helpers | [UID:0000YI][0x004615b0-0x00461658.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md) | `ReleaseDynamicAboveFrame()` / `RecreateDynamicAboveFrame()`; releases/rebuilds the dynamic `AboveFrame` slot used after side-panel tab switches. |
| `FramePartPane` | `0x004b73b0-0x004b7661` | Smaller frame-part pane used by a five-part border factory. |
| `BuildFramePartPanes` | [UID:00022F][0x004b7120-0x004b731f.BuildFramePartPanes](by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md) | Source-authored file-level factory that creates five `FramePartPane` objects at fixed rectangles and now carries first-draft C++ on the canonical memory page. |
| `FramePartPane` slot cleanup | [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md) | Source-ready file-level `ReleaseFramePartPanes()` helper that releases and clears all five `FramePartPane` global slots; `ClearFramePartPaneSlots` remains a descriptive legacy/provisional alias. |
| `AboveFrame` vtables | [UID:0003I2][AboveFrameVtables](by-type/by-vtable/AboveFrameVtables.md) | Source-local primary/secondary/tertiary `AboveFrame` vtable documentation routed to the class parent. |
| `FramePartPane` vtables | [UID:0003I3][FramePartPaneVtables](by-type/by-vtable/FramePartPaneVtables.md) | Source-local primary/secondary/tertiary `FramePartPane` vtable documentation routed to the class parent. |

### Historical Evidence Notes

- Current IDA-backed class documentation establishes `AboveFrame` as a `Pane`-derived object with `EPFTileContext` at `+0xf8` and frame bounds at `+0x108`; stale Wave3 notes were ignored and are not used as evidence.
- IDA MCP confirms `BuildAboveFrameBorder` at `0x00461310` calls `AboveFrame::AboveFrame` nine times and has two direct callers from the map/game-server startup neighborhood at `0x004f7d10`.
- IDA MCP confirms `BuildFramePartPanes` at `0x004b7120` calls `FramePartPane::FramePartPane` five times and stores five global frame-part pointers.
- IDA MCP confirms [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md) at `0x0067a834-0x0067a874` and [UID:0001PF][0x0069b33c-0x0069b350.FramePartPaneSlots](by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md) at `0x0069b33c-0x0069b350`.
- The `AboveFrame` refresh helper pair at [UID:0000YI][0x004615b0-0x00461658.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md) is called by [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md) tab switches but still owns frame-chrome state.
- IDA currently reports no direct callers for `0x004b7120`; keep the five-part `FramePartPane` factory as retained or indirect frame-chrome construction until a live caller is found.
- 2026-06-22 B011 local PE route scan strengthens that caveat: no direct rel32 `call`/`jmp`, no absolute VA pointer, and no RVA pointer to `0x004b7120` were found, and the same negative route result holds for raw cleanup start `0x004b7320`. This no-route state caps confidence but does not make `BuildFramePartPanes` compiler glue; the body is normal source-shaped `FrameChrome` factory code with five fixed layout blocks, `FramePartPane` allocations, and slot writes.
- 2026-06-24 B007 implementation resolves the stale no-code treatment for raw cleanup start [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md). Current MCP session `80de0a67` reports `0x004b7320`, `0x004b73a2`, and `0x004b73a3` are still not modeled functions, but `get_bytes` confirms the exact `0x83` / 131-byte body and `0x0d` / 13-byte padding (Verified with int_convert.py), and `make_signature_for_range` returns a unique literal signature for the body. The helper reads each `g_framePartPanes` slot, calls primary vtable slot `+0x00` with flag `1`, and clears the slot; primary `FramePartPane` vtable slot `+0x00 -> 0x004b75b0` plus the scalar deleting destructor decompilation prove this is source-level `delete` behavior. A current PE route scan over `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` still finds no rel32 `call`/`jmp`, absolute VA dword, or RVA dword to `0x004b7320`, so the no-route state remains a confidence cap rather than a no-code proof.
- [UID:0001PF][0x0069b33c-0x0069b350.FramePartPaneSlots](by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md) now emits the file-static declaration `static FramePartPane* g_framePartPanes[5];` for the five `FramePartPane` slots, with index roles top strip, left side, right side, lower-left piece, and lower-right piece. Exact original private variable spelling remains provisional, but the array-like model is stronger than five unrelated globals because the storage is contiguous and the build/delete/notification lifecycle is uniform.
- Both classes use the same `goog` notification tag and the same `FRMPART` resource family, supporting a shared chrome/source-file hypothesis.
- 2026-06-26 B014 source-quality refresh on current MCP session `80de0a67` narrows the resource-string ownership claim: the `0x00610f60-0x00610fe8` run is exact, but only `FRMPART.EPF`, `TABS.EPF`, and `FRMPART.EPD` route solely through this file. `FRMPART.PAL` has xrefs from `AboveFrame::OnPaint`, [MapNamePane::OnPaint](by-memory/0x00503350-0x0050349f.MapNamePaneOnPaint.md), and [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md); `TABS.PAL` has `AboveFrame` and Group pane paint xrefs; `NPAL5.PAL` has `AboveFrame`, [UID:0000HO][BackPane](by-file/BackPane.md), and UserStatus paint xrefs. The stale `0x00610fd4` generated split is rejected because that address is inside UTF-16 `NPAL5.PAL`; AES table bytes begin at `0x00610fe8`.
- IDA MCP confirms `AboveFrame` vtables at `0x00610edc`, `0x00610f28`, and `0x00610f58`, and `FramePartPane` vtables at `0x0061a7fc`, `0x0061a848`, and `0x0061a878`. Current generated metadata reports `vtable_count: 0` for both classes, so use [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md) as the layout anchor.
- 2026-05-31 IDA MCP verifies exact vtable-data children [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md) and [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md), including boundaries before `FRMPART.EPF` string data and `GeneralPurposePanel` RTTI.
- 2026-06-12 A004 split refresh promotes [UID:0003I2][AboveFrameVtables](by-type/by-vtable/AboveFrameVtables.md) and [UID:0003I3][FramePartPaneVtables](by-type/by-vtable/FramePartPaneVtables.md) as the source-local by-vtable anchors; [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md) is now only a non-emitting mixed index. Live IDA MCP reconfirmed both exact vtable clusters, lifecycle stores, slot target sizes, unique signatures, and successor boundaries.
- 2026-05-26 recheck using `simroot_v2` and IDA MCP only: `class_FramePartPane.cpp` still omits the raw cleanup body, `lookup_funcs` still reports `0x004b7320` as not-a-function, `callers 0x004b7120` is still empty, and `0x004615b0`/`0x004615d0` are still called from `GeneralPurposePanel` switch helpers at `0x004b8650` and `0x004b89a0`. 2026-05-28 byte review extends the current raw cleanup endpoint to `0x004b7320-0x004b73a3`.
- 2026-05-26 exact xref recheck: `AboveFrame::AboveFrame` has ten direct code refs in this chrome island: nine from `BuildAboveFrameBorder` and one from `0x004615d0`. The `BuildAboveFrameBorder` slot writes cover `0x0067a834`, `0x0067a838`, `0x0067a83c`, `0x0067a840`, `0x0067a848`, `0x0067a84c[]`, and `0x0067a860[]`.
- 2026-05-26 exact boundary recheck corrects `BuildFramePartPanes` to `0x004b7120-0x004b731f` end-exclusive. It writes the five `FramePartPane` slots at `0x0069b33c-0x0069b34c`; direct callers remain unresolved.
- 2026-05-28 IDA boundary check corrects `FramePartPane` to `0x004b73b0-0x004b7661`; byte `0x004b7660` is the final immediate byte of the scalar-deleting destructor's `retn 4`.
- 2026-06-11 A005 live IDA MCP parent-gate refresh reconfirms the FrameChrome source-root evidence: `BuildAboveFrameBorder` still has two callers from `0x004f7d10`, the dynamic `AboveFrame` refresh helpers still have callers from `0x004b8650` and `0x004b89a0`, `BuildFramePartPanes` still has no direct caller but has five constructor refs to `FramePartPane::FramePartPane`, and all `AboveFrame`/`FramePartPane` vtable bases, store xrefs, slot targets, and adjacent data boundaries match the exact child pages.
- 2026-06-12 A003 live IDA MCP refresh for [UID:0000U2][BuildAboveFrameBorder_00461310](by-item/BuildAboveFrameBorder_00461310.md) confirms the helper is routed here as a file-level chrome factory: `sub_461310` is `0x00461310-0x004615aa`, branches on `byte_66DA97`, creates four fixed new-mode `AboveFrame` slots or the legacy fixed plus five-pair looped side pieces, and is called twice from `sub_4F7D10`.
- 2026-06-16 A001 live IDA refresh reconfirms current modeled starts and sizes: `AboveFrame` constructor body at `0x004610f0` size `0x1a9`, file-level `BuildAboveFrameBorder` at `0x00461310` size `0x29a`, dynamic release helper at `0x004615b0` size `0x11`, dynamic creator at `0x004615d0` size `0x88`, retained `BuildFramePartPanes` at `0x004b7120` size `0x1ff`, `FramePartPane::OnNotification` at `0x004b73b0` size `0x51`, adjustor thunk `0x004b7590` size `0xb`, and scalar deleting destructor at `0x004b75b0` size `0xb1`.
- Current reachability evidence keeps the source split conservative: `analyze_function 0x00461310` resolves to the main UI graph startup function `0x004f7d10`; `0x004615d0` is called by the two `GeneralPurposePanel` switch helpers at `0x004b8650` and `0x004b89a0`; `0x004b7120` still has no direct callers; and raw cleanup start `0x004b7320` is still not an IDA function and has no xrefs to the start.
- Slot evidence remains frame-chrome-local. `xrefs_to 0x0067a834` reports builder writes from `0x00461310`; `xrefs_to 0x0069b33c` reports builder writes from `0x004b7120`, raw cleanup refs at `0x004b7320`/`0x004b7330`, and `FramePartPane::OnNotification` at `0x004b73cb`. A section-mapped PE scan found no absolute VA pointer and no direct rel32 call/jump reference to `0x004b7320`, so the cleanup body remains a raw local helper rather than a modeled callable function.
- 2026-06-20 B003 source-quality implementation revalidates `AboveFrame` as a source island inside this file rather than a `GeneralPurposePanel`, `MapPane`, `ResourceLayoutTable`, EPF library, generic scheduler, or standard-library owner. The support facts are: exact `0x004610f0-0x0046178a` aggregate split, constructor order `frameIndex/top/left`, fields `+0xf8/+0x108/+0x120/+0x130`, resources `FRMPART.EPF`, `TABS.EPF`, `FRMPART.EPD`, palettes `FRMPART.PAL`, `TABS.PAL`, `NPAL5.PAL`, `goog` notification message field `+4`, ten constructor refs, and FrameChrome slot ownership. `GeneralPurposePanel` only supplies `m_activeChildIndex` for the dynamic frame piece; it does not own the frame object or its globals.
- 2026-06-20 B006 Rule 26 reconciliation independently agrees that [UID:0000YH][0x004610f0-0x0046178a.AboveFrame](by-memory/0x004610f0-0x0046178a.AboveFrame.md) is a mixed FrameChrome source island, not a single class method or a `GeneralPurposePanel`/Surface/ResourceLayoutTable/STL body. The local PE/exported-record pass supports `BuildAboveFrameBorder`, `ReleaseDynamicAboveFrame`, and `RecreateDynamicAboveFrame` as file-level helpers beside the `AboveFrame` class methods; it keeps the aggregate child-routed and leaves compiler adjustor/scalar destructor material no-code.
- 2026-06-21 B007 Rule 26 report review was reconciled against this file root. Its valid routing facts are already present: `FrameChrome.cpp` owns `AboveFrame` resource/palette constants, global slot lifetime, `BuildAboveFrameBorder`, dynamic release/recreate helpers, and the source route for `AboveFrame` methods; `GeneralPurposePanel`, `ResourceLayoutTable`, ImageLib/EPF resources, Pane, GrafPort/Surface, FrameMgr/FrameHandler, TotemFrame, and STL/generated labels are rejected as owners. No file-level score change is needed because B007 had no live MCP access and did not add stronger evidence than the current IDA-backed route.
- 2026-07-26 B004 read-only UID0001P1 audit confirmed the exact 64-byte slot range, all-zero virtual-tail bytes, five constant-address scalar heads, two indexed five-pointer array bases, the no-xref/name/type/comment gap at `0x0067a844`, and the separate `g_pGeneralPurposePanel` successor. All target xrefs remain confined to this file's three helpers, and each proposed source/IDA name had a zero-result collision lookup.

### Historical Open Issues

- `class_AboveFrame.meta_wave3` has a bad summary and a disabled unrelated method at `0x00520046`; IDA shows this address-like value comes from `FRMPART.EPF` UTF-16 string bytes after the short tertiary vtable, while the real code address is inside `ArgumentedItemQuantityInputDialogPane::OnDialogAction`. See [wave3 data issues](../wave3_data_issues.md).
- `AboveFrame` and `FramePartPane` may represent old/new frame chrome implementations rather than two active implementations. Keep both documented together until callers and globals are reconciled.
- IDA labels the `0x004615d0-0x00461658` dynamic `AboveFrame` creator as `__std_parallel_algorithms_hw_threads`; decompilation shows frame-chrome behavior, so treat that label as generated-name pollution, not standard-library ownership.
- Active `class_FramePartPane.cpp` omits the raw [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md) body even though it reads and clears the same five global slots.

### Historical C++ Placement

This file root owns the FrameChrome source module and should aggregate exact child output without duplicating child method bodies. [UID:000005][AboveFrame](by-class/AboveFrame.md) emits `#include "FrameChrome.h"` through CPP and the complete class declaration through H. [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md) emits the seven file-static definitions before their users. Source-authored helper bodies belong on exact children such as [UID:0000U2][BuildAboveFrameBorder_00461310](by-item/BuildAboveFrameBorder_00461310.md) and [UID:0000YI][0x004615b0-0x00461658.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md). Compiler adjustor thunks, scalar deleting destructor wrappers, vtable data, the `0x0067a844` linker gap, and helper alignment bytes remain generated/no-code.

FramePartPane method implementation emits through the class owner [UID:00005I][FramePartPane](by-class/FramePartPane.md) into this `FrameChrome.cpp` file route. [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md) is the method-body emitter for the constructor, ordinary destructor, notification handler, and paint handler; this file page should not duplicate those bodies. The scalar deleting destructor and secondary/tertiary adjustor thunks remain compiler-generated artifacts represented by class/vtable/destructor documentation.

Keep [UID:00022F][0x004b7120-0x004b731f.BuildFramePartPanes](by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md) and [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md) as file-level helpers with their own reachability/source-shape caveats. `BuildFramePartPanes` now emits first-draft C++ on its canonical memory page because it clears the active reconstructability gate; it has five direct constructor calls and writes the five `FramePartPane` slots but still lacks a recovered live caller. `FramePartPaneSlotCleanup` now emits first-draft `ReleaseFramePartPanes()` C++ on its canonical memory page because the body is source-level frame-chrome lifecycle cleanup: it deletes each non-null `g_framePartPanes[0..4]` object through the `FramePartPane` scalar deleting destructor, then clears the slot. It still remains not modeled as an IDA function and has no direct entry xref or rel32/VA/RVA route, so those facts cap confidence rather than blocking C++. Neither helper should be collapsed into the `FramePartPane` class method emitter solely because it touches `FramePartPane*` objects.

Rejected owner/source alternatives for [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md): `FramePartPane` is only the object type; [UID:0000JM][FrameMgr](by-file/FrameMgr.md) has no scheduling/callback role here; `Pane` or a generic pane manager is too broad; `ResourceLayoutTable`, EPF/ImageLib, and asset ownership are dependencies of neighboring construction/paint paths, not owners of slot lifetime; [UID:00022F][0x004b7120-0x004b731f.BuildFramePartPanes](by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md) is adjacent but ends before the `0xcc` boundary; and [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md) notification clearing is a peer pointer-clear path, not the all-slot release helper.

### Historical Assignment Gate

This file page clears the strict parent side at `89/90` for the exact slot children, [UID:000005][AboveFrame](by-class/AboveFrame.md), [UID:00005I][FramePartPane](by-class/FramePartPane.md), and file-level chrome helpers such as [UID:0000U2][BuildAboveFrameBorder_00461310](by-item/BuildAboveFrameBorder_00461310.md). Class-owned vtable data should still attach to those class pages first through [UID:0003I2][AboveFrameVtables](by-type/by-vtable/AboveFrameVtables.md) and [UID:0003I3][FramePartPaneVtables](by-type/by-vtable/FramePartPaneVtables.md); UID0000PN and [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md) remain mixed nonemitting inventories rather than direct source parents.

### Historical Cross-References

- [UID:000005][AboveFrame](by-class/AboveFrame.md)
- [UID:00005I][FramePartPane](by-class/FramePartPane.md)
- [UID:0000YH][0x004610f0-0x0046178a.AboveFrame](by-memory/0x004610f0-0x0046178a.AboveFrame.md)
- [UID:0003I2][AboveFrameVtables](by-type/by-vtable/AboveFrameVtables.md)
- [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md)
- [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md)
- [UID:0003I3][FramePartPaneVtables](by-type/by-vtable/FramePartPaneVtables.md)
- [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md)
- [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md)
- [UID:0000YJ][0x004616c8-0x004616de.AboveFrameAdjustorThunks](by-memory/0x004616c8-0x004616de.AboveFrameAdjustorThunks.md)
- [UID:00015P][0x004b7590-0x004b75a6.FramePartPaneAdjustorThunks](by-memory/0x004b7590-0x004b75a6.FramePartPaneAdjustorThunks.md)
- [UID:0000PN][FrameChromeSlots](by-global/FrameChromeSlots.md)
- [UID:0002SG][0x00610f60-0x00610fe8.FrameChromeResourceStrings](by-memory/0x00610f60-0x00610fe8.FrameChromeResourceStrings.md)
- [UID:00044T][0x00610f60-0x00610fa4.FrameChromeFrameResourceStrings](by-memory/0x00610f60-0x00610fa4.FrameChromeFrameResourceStrings.md)
- [UID:00044U][0x00610fa4-0x00610fbc.SharedFramePartPaletteResourceString](by-memory/0x00610fa4-0x00610fbc.SharedFramePartPaletteResourceString.md)
- [UID:00044V][0x00610fbc-0x00610fd0.SharedTabsPaletteResourceString](by-memory/0x00610fbc-0x00610fd0.SharedTabsPaletteResourceString.md)
- [UID:00044W][0x00610fd0-0x00610fe8.SharedNpal5PaletteResourceString](by-memory/0x00610fd0-0x00610fe8.SharedNpal5PaletteResourceString.md)
- [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md)
- [UID:0001PF][0x0069b33c-0x0069b350.FramePartPaneSlots](by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md)
- [UID:00022F][0x004b7120-0x004b731f.BuildFramePartPanes](by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md)
- [UID:0000YI][0x004615b0-0x00461658.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md)
- [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md)
- [UID:0000U2][BuildAboveFrameBorder_00461310](by-item/BuildAboveFrameBorder_00461310.md)
- [UID:0000U5][BuildFramePartPanes_004B7120](by-item/BuildFramePartPanes_004B7120.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

### Historical Changes

- 2026-07-26 B004 UID0001P1 accepted implementation callback:
  - Changed `88/88 -> 89/90` and incorporated the exact source-bearing AboveFrame storage child directly into the FrameChrome file route.
  - Added all seven accepted file-static names/ranges, loader-zero PE correction, scalar/array proof, no-source alignment gap, fixed/dynamic lifetime asymmetry, CPP-only linkage, class-header include ordering, UID0000PN nonemitting-index reclassification, GeneralPurposePanel consumer-only rationale, current IDA prestate/collision evidence, and rejected aggregate/exported/opaque representations while retaining the broader FramePartPane liveness cap.

- 2026-06-26 B014 FrameChrome resource-string ownership sync:
  - Score unchanged at `88/88`.
  - Summary/evidence: current MCP session `80de0a67` preserves FrameChrome routing for `FRMPART.EPF`, `TABS.EPF`, and `FRMPART.EPD`, but reclassifies [UID:0002SG][0x00610f60-0x00610fe8.FrameChromeResourceStrings](by-memory/0x00610f60-0x00610fe8.FrameChromeResourceStrings.md) as a non-emitting mixed string-pool index. `FRMPART.PAL`, `TABS.PAL`, and `NPAL5.PAL` are shared source-use literals with MapName/MiniMap, Group, BackPane, and UserStatus consumers, so this file no longer claims the entire pool as FrameChrome-local constants.
- 2026-06-24 B007 FramePartPaneSlotCleanup implementation:
  - Score unchanged at `88/88`.
  - Summary/evidence: incorporated accepted [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md) source-quality result into the file root. The cleanup is now source-ready `ReleaseFramePartPanes()` under [UID:0000JL][FrameChrome](by-file/FrameChrome.md), while `ClearFramePartPaneSlots` remains a descriptive legacy/provisional alias. Current MCP session `80de0a67`, exact body/padding/signature evidence, no-function/no-entry-route negative evidence, scalar-deleting-destructor proof, and PE no-rel32/no-VA/no-RVA route scan are preserved as file-level routing facts.
- 2026-06-22 B011 BuildFramePartPanes source-quality incorporation:
  - Score unchanged at `88/88`.
  - Summary/evidence: reconciled the B011 report into the file root. [UID:00022F][0x004b7120-0x004b731f.BuildFramePartPanes](by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md) is now documented as source-authored `FrameChrome` factory code with first-draft C++ readiness; local PE scanning found no rel32/VA/RVA route to the factory or raw cleanup start, which remains a confidence cap rather than a no-code reason. Added the preferred `g_framePartPanes[5]` slot-family direction and preserved rejection of `FramePartPane`, `MainUiGraph`, `FrameMgr`, `ResourceLayoutTable`, and EPF/resource ownership for the helper body.
- 2026-06-20 B003 AboveFrame source-quality implementation:
  - Before: `87/86`; FrameChrome was already the likely source root but still kept the exact module split, refresh helper path, and generated-name handling open.
  - Changed to: `88/88`.
  - Summary/evidence: incorporated the accepted AboveFrame report details into the file root: accepted `ui/core/FrameChrome.cpp` route, helper range repair to `0x00461658`, dynamic `m_activeChildIndex + 5` recreate input, generated-code separation, and rejected alternatives (`GeneralPurposePanel`, `MapPane`, `ResourceLayoutTable`/EPF resources, generic pane manager, and standard-library ownership for the mislabeled helper).
- 2026-06-20 B006 AboveFrame Rule 26 reconciliation:
  - Score unchanged.
  - Summary/evidence: rechecked the AboveFrame island against local PE/exported function records and current docs; preserved the B003 route while adding stronger report-level support for the mixed source island, file-level helper placement, generated-code boundaries, and rejection of Surface/FittingRoom, BulletinSession/Pane, ResourceLayoutTable, GeneralPurposePanel, and STL ownership pollution.
- 2026-06-21 B007 AboveFrame Rule 26 report review:
  - Score unchanged.
  - Summary/evidence: verified that B007's source-placement report is fully represented by the existing FrameChrome file root: exact AboveFrame method/helper split, file-level helper placement, dynamic slot ownership, resource/palette constant ownership, `goog` notification route, and generated no-code boundaries. The report's conservative aggregate `86/90` score is not applied to this file page.
- 2026-06-19 B002 FramePartPane source-quality implementation support:
  - Added routing note that [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md) emits source-authored `FramePartPane` methods through class owner [UID:00005I][FramePartPane](by-class/FramePartPane.md) into this `FrameChrome.cpp` route.
  - Preserved [UID:00022F][0x004b7120-0x004b731f.BuildFramePartPanes](by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md) and [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md) as file-level helpers with no-live-caller / raw-no-function caveats rather than class methods.

- 2026-06-16 A001 low-confidence file refresh:
  - Scores raised from `86/85` to `87/86`.
  - Evidence: live IDA MCP reconfirmed current function sizes, AboveFrame startup and GeneralPurposePanel refresh reachability, retained no-caller state for `BuildFramePartPanes`, slot xrefs for both global families, and raw cleanup no-function/no-start-xref status; PE scan found no absolute pointer or direct rel32 call/jump to `0x004b7320`.
  - Remaining blockers: exact final filename, whether `AboveFrame`/`FramePartPane` were split files or one chrome file, and retained `FramePartPane` factory liveness remain unresolved enough to cap confidence below the class/global support pages.
- 2026-06-12 FrameChrome vtable split refresh:
  - What existed before: [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md) was the only by-vtable anchor and was still marked reconstructable despite mixed class ownership.
  - Changed to: source-local children [UID:0003I2][AboveFrameVtables](by-type/by-vtable/AboveFrameVtables.md) and [UID:0003I3][FramePartPaneVtables](by-type/by-vtable/FramePartPaneVtables.md) are the reconstructable vtable anchors routed through `AboveFrame` and `FramePartPane`; [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md) is retained as a non-emitting mixed index. This page remains `86/85`.
  - Summary/evidence: A004 live IDA MCP reconfirmed the exact `0x00610ed8-0x00610f60` and `0x0061a7f8-0x0061a880` clusters, decorated vtable bases, lifecycle stores, slot targets, unique signatures, and adjacent `FRMPART.EPF`/`0x0061a880` successor boundaries.

- 2026-06-12 BuildAboveFrameBorder item refresh:
  - What existed before: [UID:0000U2][BuildAboveFrameBorder_00461310](by-item/BuildAboveFrameBorder_00461310.md) was listed as a provisional helper but remained unassigned at `80/86`.
  - Changed to: the proposed contents and assignment gate explicitly support routing [UID:0000U2][BuildAboveFrameBorder_00461310](by-item/BuildAboveFrameBorder_00461310.md) to this file parent; this page remains `86/85`.
  - Summary/evidence: A003 IDA MCP recheck of `sub_461310` confirmed the exact boundary, two startup callers, branch-specific `AboveFrame` slot stores, and the five-iteration legacy loop, while the helper remains file-level chrome construction rather than an `AboveFrame` class method.

- 2026-06-01 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, and the status kept the final filename/folder open.
  - Changed to: `NexusTK/ui/core/`.
  - Summary/evidence: the existing proposed source tree groups frame chrome under UI core, and IDA MCP recheck of the `FramePartPane` helper cluster confirms UI chrome behavior: fixed frame-part pane construction, global frame-part slot lifecycle, `FRMPART` resource use, and no evidence of ownership by MapPane, ResourceLayoutTable, or generic scheduler code.

- Before: `AboveFrame` was listed as `0x004610f0-0x00461789`.
- After: `AboveFrame` is listed as `0x004610f0-0x0046178a`.
- Summary/evidence: IDA MCP reports the scalar deleting destructor through `0x0046178a`; the following bytes `0x0046178a-0x00461790` are alignment padding before the AES helper island.
- Before: `FramePartPane` was listed as `0x004b73b0-0x004b7660`.
- After: `FramePartPane` is listed as `0x004b73b0-0x004b7661`.
- Summary/evidence: 2026-05-28 IDA MCP and raw-byte review show the scalar-deleting destructor's final instruction is `c2 04 00`, with byte `0x004b7660` as the final immediate byte; padding starts at `0x004b7661`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:80`.
  - Summary/evidence: visible frame chrome role, AboveFrame/FramePartPane grouping, factory/slot helpers, vtable/global anchors, old/new implementation caveats, generated metadata problems, and range corrections are documented; confidence remains at 80 because exact original filename and active use of the FramePartPane factory remain unresolved.
- 2026-06-11 parent-gate confidence refresh:
  - What existed before: the file page was the likely source root at `86/80`, which left class-owned vtable-data assignments blocked by the strict parent chain.
  - Changed to: confidence is `85`, with explicit assignment-gate text clarifying that this page is the source root while exact vtable data attaches to the owning classes.
  - Summary/evidence: live IDA MCP reconfirmed the AboveFrame and FramePartPane factories, callers, function boundaries, vtable stores, exact vtable data boundaries, shared `goog`/`FRMPART` behavior, and the unresolved but documented no-direct-caller caveat for `BuildFramePartPanes`.
