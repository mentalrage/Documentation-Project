*** UID:0000PN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FrameChromeSlots

## Status

- Confidence: very strong for both exact slot clusters, object types, factory/refresh/cleanup writers, direct exact-child source routes, and owner module; broader `FramePartPane` construction reachability remains a separate file-level cap.
- Likely owner file: [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- Vtable/layout anchor: [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md)
- Related memory docs: [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md), [UID:0001PF][0x0069b33c-0x0069b350.FramePartPaneSlots](by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md), [UID:0000YI][0x004615b0-0x00461658.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md), and [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md)
- Rebuild handling: reviewed nonreconstructable/nonemitting semantic index. Preserve the cross-range research here, but emit the independently authored declarations only from exact children [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md) and [UID:0001PF][0x0069b33c-0x0069b350.FramePartPaneSlots](by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md), both routed directly through UID0000JL. Both formal channels therefore remain blank.

## Role

The frame chrome code keeps global pointers to visible frame-border pane objects. There are two related but distinct slot families:

| Slot family | Data range | Object type | Builder / users |
| --- | --- | --- | --- |
| `AboveFrame` slots | `0x0067a834-0x0067a874` | Five file-static [UID:000005][AboveFrame](by-class/AboveFrame.md) pointer scalars, one no-source alignment gap, and two five-entry pointer arrays | Source-bearing exact child UID0001P1; built by [UID:0000U2][BuildAboveFrameBorder_00461310](by-item/BuildAboveFrameBorder_00461310.md); dynamic slot refreshed by [UID:0000YI][0x004615b0-0x00461658.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md); GeneralPurposePanel tab switches are consumers/triggers only. |
| `FramePartPane` slots, provisional `g_framePartPanes[5]` | `0x0069b33c-0x0069b350` | Five [UID:00005I][FramePartPane](by-class/FramePartPane.md) pointers | Built by [UID:0000U5][BuildFramePartPanes_004B7120](by-item/BuildFramePartPanes_004B7120.md); pointer-cleared by `FramePartPane::OnNotification`; released/deleted and cleared by source-ready [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md) as inferred `ReleaseFramePartPanes()`. |

## Slot Layout Summary

The exact slot pages carry the full address-level tables. At the overview level, the source-facing split is:

| Range | Contents | Lifecycle evidence |
| --- | --- | --- |
| `0x0067a834-0x0067a838` | `g_pAboveFrameTop` | Builder writes EPF frame 0 or legacy frame 1. |
| `0x0067a838-0x0067a83c` | `g_pAboveFrameRight` | Builder writes frame 2 in either asset mode. |
| `0x0067a83c-0x0067a840` | `g_pAboveFrameLeft` | Builder writes EPF frame 1. |
| `0x0067a840-0x0067a844` | `g_pDynamicAboveFrame` | Builder/recreate write it; release deletes without clearing; recreate overwrites or stores null. Input is `g_pGeneralPurposePanel->m_activeChildIndex + 5`, not GeneralPurposePanel ownership. |
| `0x0067a844-0x0067a848` | No authored object. | Loader-zero linker/BSS alignment gap: no xref, name, type, comment, or nonzero byte. It is not an unused pointer variable or source initializer. |
| `0x0067a848-0x0067a84c` | `g_pLegacyAboveFrameTopLeft` | Legacy frame 0 at top 12, left 14. |
| `0x0067a84c-0x0067a860` | `g_pLegacyAboveFrameLeftSide[5]` | Indexed legacy frame-3 pointers at left 14 and tops `98 + 63*i`. |
| `0x0067a860-0x0067a874` | `g_pLegacyAboveFrameRightSide[5]` | Indexed legacy frame-4 pointers at left 420 and tops `92 + 63*i`; exact half-open end precedes separate `g_pGeneralPurposePanel`. |
| `0x0069b33c-0x0069b350` | Five `FramePartPane*` slots, source-facing provisional `g_framePartPanes[5]`. | [UID:00022F][0x004b7120-0x004b731f.BuildFramePartPanes](by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md) writes all five slots in builder order; [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md) now emits source-ready `ReleaseFramePartPanes()` that deletes each non-null slot through `FramePartPane` scalar deleting destructor slot `+0x00` and clears it; [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md) notification handling only clears the pointers. Current B007 MCP `get_bytes` reads zero bytes for this range, and corrected PE mapping places it in the unbacked `.data` tail; treat older IDA `FF` byte rendering as superseded for source-initializer purposes. Final individual-vs-array spelling remains provisional, but contiguous storage, uniform builder order, source-ready release cleanup, and notification bulk clear support the array-family name. |

The complete `AboveFrame` target is loader-zero static storage in the unbacked `.data` virtual tail, not `0xffffffff` initialized data. PE mapping places the start 0x34 bytes beyond the raw-backed end at `0x0067a800`; all 16 dwords read zero. Five constant-address heads and two indexed bases prove five scalars plus two arrays, not one 16-element array or opaque structure. Every xref is in FrameChrome, so the exact child definitions are file-static and have no H `extern` declarations.

The `g_framePartPanes[5]` source-facing order is: `[0]` top strip, `[1]` left side, `[2]` right side, `[3]` lower-left piece, and `[4]` lower-right piece. These names are visual-role inferences from the fixed builder rectangles and offsets; the raw addresses on the exact slot page remain the authoritative binary evidence until original private names are recovered.

## Ownership Decision

Keep these globals with frame/chrome source, not with [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md), [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md), or generic pane-manager source. General-purpose panel switches call the refresh helpers, but they do not own the frame objects or the slot storage.

This page is not itself an authored source container. Its two physical families are noncontiguous and already have exact source-bearing children with direct UID0000JL routes. Emitting a declaration here would duplicate those children or invent a wrapper absent from the binary. Retaining UID0000JL as semantic owner preserves the common module relationship without creating aggregate C++.

The object families also share the same frame-chrome evidence bundle: `FRMPART`/`TABS` resources and palettes, the `goog` notification path, and the short three-view vtable pattern recorded by [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md). Exact vtable-data children [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md) and [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md) support keeping both slot families under [UID:0000JL][FrameChrome](by-file/FrameChrome.md), even though the concrete storage ranges are not adjacent.

Do not move these globals to [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) or EPF library ownership just because the constructors load `FRMPART.EPF`, `FRMPART.EPD`, `TABS.EPF`, `FRMPART.PAL`, `TABS.PAL`, and `NPAL5.PAL`. Those resources are constructor inputs; the pointer slots are pane lifetime state.

B007's Rule 26 report was reviewed on 2026-06-21 and is already represented by this global overview: `0x0067a840` remains descriptive `g_pDynamicAboveFrame`, the dynamic recreate input remains `g_pGeneralPurposePanel->m_activeChildIndex + 5`, exact per-slot names remain provisional, and `GeneralPurposePanel` is a caller/state provider rather than the owner of the frame-chrome slot family.

## IDA MCP Evidence

Checked on 2026-05-25 and rechecked on 2026-05-26:

- `xrefs_to 0x0069b33c-0x0069b34c` shows writes from `0x004b7120`, clears from raw cleanup bytes at `0x004b7320-0x004b73a3`, and clears from `FramePartPane::OnNotification` at `0x004b73b0`.
- `xrefs_to 0x0067a834-0x0067a860` shows writes from `BuildAboveFrameBorder` at `0x00461310`. `0x0067a840` also has cleanup/refresh xrefs from `0x004615b0` and the adjacent dynamic-create helper currently mislabeled by IDA as `__std_parallel_algorithms_hw_threads`.
- `callers 0x00461310` reports two calls inside `0x004f7d10`, matching main UI graph setup. `callers 0x004b7120` currently reports no direct callers, so the five-part `FramePartPane` factory remains a retained or indirect construction path until a caller is recovered.
- `callers 0x004615b0` and `callers 0x004615d0` both report the general-panel switch functions `0x004b8650` and `0x004b89a0`; those calls are dependencies on frame-chrome state, not ownership evidence for the globals. The switch helpers supply `m_activeChildIndex` through [UID:0000R0][g_pGeneralPurposePanel](by-global/g_pGeneralPurposePanel.md), while this page owns the refreshed `AboveFrame` pointer storage.
- 2026-05-30 IDA MCP `xrefs_to 0x0067a840` confirms dynamic `AboveFrame` slot writes from `BuildAboveFrameBorder`, delete/read at `0x004615b0`, recreate write at `0x0046162b`, and allocation-failure clear at `0x0046163f`.
- 2026-05-30 IDA MCP `xrefs_to 0x0069b33c` confirms the `FramePartPane` slot start is written by `0x004b7120`, referenced by raw cleanup bytes at `0x004b7320`/`0x004b7330`, and cleared by `FramePartPane::OnNotification` at `0x004b73cb`.
- 2026-06-05 IDA MCP recheck confirmed `AboveFrame` slot xrefs at `0x0067a834`/`0x0067a840` from `0x00461310`, `0x004615b0`, and the dynamic recreate helper, plus `FramePartPane` slot xrefs at `0x0069b33c`/`0x0069b34c` from builder, cleanup bytes, and `FramePartPane::OnNotification`.
- Neighbor-page evidence through 2026-06-06 raises this overview above the child-parent attachment gate: `AboveFrameSlots` and `FramePartPaneSlots` both document exact ranges, object types, slot counts, initial storage, writer/clearer xrefs, and unresolved naming/reachability caveats; [UID:0000JL][FrameChrome](by-file/FrameChrome.md) is already the above-threshold owner.
- `FramePartPane` reachability remains a deliberate cap. The factory at `0x004b7120` constructs and writes real slot state, and cleanup/notification paths consume that state, but current IDA evidence still reports no direct static callers for the factory.
- 2026-06-22 B011 local PE route scan found no direct rel32 `call`/`jmp`, absolute VA pointer, or RVA pointer to `0x004b7120`; the same negative route result holds for raw cleanup start `0x004b7320`. This supports retained/dormant or still-unrouted construction, not ownership by MainUiGraph, FrameMgr, ResourceLayoutTable, or resource-loader code.
- 2026-06-24 B007 implementation keeps the same owner/source split but upgrades [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md) to source-ready `ReleaseFramePartPanes()` under [UID:0000JL][FrameChrome](by-file/FrameChrome.md). Current MCP session `80de0a67` confirms no modeled function at the raw cleanup entry, exact `0x83` / 131-byte body and `0x0d` / 13-byte padding (Verified with int_convert.py), unique literal signature, no entry xref, complete slot read/delete/clear pairs, builder and notification peer paths, and primary `FramePartPane` vtable slot `+0x00 -> 0x004b75b0` scalar deleting destructor proof. The local PE route scan still finds no rel32/VA/RVA route to `0x004b7320`; that remains a liveness confidence cap rather than a no-code proof.
- 2026-06-07 A002 live IDA MCP `py_eval` refreshed the `AboveFrame` half of this overview while working [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md): `0x0067a834`, `0x0067a838`, `0x0067a83c`, `0x0067a840`, `0x0067a848`, `0x0067a84c`, and `0x0067a860` have the expected builder/release/recreate xrefs; `0x0067a844` is unreferenced filler; `0x0067a874` is the separate [UID:00028X][0x0067a874-0x0067a878.g_pGeneralPurposePanel](by-memory/0x0067a874-0x0067a878.g_pGeneralPurposePanel.md), not part of the `AboveFrameSlots` child.
- 2026-06-14 live IDA MCP xref refresh reconfirmed the `AboveFrame` scalar/array starts, the zero-xref `0x0067a844` spacer, `FramePartPane` slot start/end refs at `0x0069b33c` and `0x0069b34c`, and the high-fanout separate `g_pGeneralPurposePanel` slot at `0x0067a874`.
- 2026-06-14 IDA MCP `analyze_component` over the frame-chrome builder/refresh/cleanup set reported `sub_4B7120` size `511`, `sub_461310` size `666`, `sub_4615B0` size `17`, dynamic recreate helper `0x004615d0` size `136`, and `FramePartPane::OnNotification` at `0x004b73b0` size `81`; it still found no internal call edge proving a static caller for `0x004b7120`.
- Corrected local PE section-offset checking places the late slot ranges beyond the initialized `.data` raw payload. IDA signature output renders these unbacked bytes as `FF`; the source reconstruction should model frame-chrome static pointer storage and runtime writes/clears, not hard-code an initializer solely from that placeholder.
- B007's 2026-06-24 current MCP `get_bytes` for the exact `FramePartPane` slot range reads twenty zero bytes, agreeing with the unbacked-tail source model and superseding older exact-slot wording that treated `0xffffffff` as the source initializer.
- 2026-07-26 B004 UID0001P1 read-only audit resolves the AboveFrame half at final source quality. The exact target has 13 xrefs, all within `BuildAboveFrameBorder`, `ReleaseDynamicAboveFrame`, and `RecreateDynamicAboveFrame`; the five scalar heads and two indexed array bases have exact source-facing names, while `0x0067a844` remains a name/type/xref-free alignment gap. The fixed pointers are builder-written program-lifetime state; only `g_pDynamicAboveFrame` has release/recreate behavior.
- The same pass confirmed all target data entities are presently undefined/unnamed in IDA, all proposed names have zero collisions, and `AboveFrame` is not yet an IDA type. Those are supervisor Gate 2B modeling tasks, not reasons for this semantic index to emit source.

## Score Rationale

Completion is `91` because the overview now accurately inventories both independently source-bearing slot families, exact ranges, loader-zero corrections, builders/refresh/cleanup writers, direct exact-child routes, source linkage, and the no-duplicate aggregate disposition. Confidence is `93` because PE, live IDA, exact child pages, class/vtable/resource evidence, and ownership agree. The broader retained `FramePartPane` factory liveness and some private FramePartPane spelling remain documented caps, but they do not justify aggregate emission.

## Cross-References

- [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- [UID:000005][AboveFrame](by-class/AboveFrame.md)
- [UID:00005I][FramePartPane](by-class/FramePartPane.md)
- [UID:0000YH][0x004610f0-0x0046178a.AboveFrame](by-memory/0x004610f0-0x0046178a.AboveFrame.md)
- [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md)
- [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md)
- [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md)
- [UID:0001PF][0x0069b33c-0x0069b350.FramePartPaneSlots](by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md)
- [UID:0000U2][BuildAboveFrameBorder_00461310](by-item/BuildAboveFrameBorder_00461310.md)
- [UID:0000U5][BuildFramePartPanes_004B7120](by-item/BuildFramePartPanes_004B7120.md)
- [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md)
- [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md)
- [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md)

## UID0000JL Accepted Split Incorporation - 2026-08-25

- This page remains the exact non-reconstructable, non-emitting mixed index over two independent source-bearing children: [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md) routes to [UID:000577][AboveFrame](by-file/AboveFrame.md), while [UID:0001PF][0x0069b33c-0x0069b350.FramePartPaneSlots](by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md) routes to [UID:000578][FramePartPane](by-file/FramePartPane.md).
- The disjoint ranges, different types/lifecycles, exact xrefs, Above alignment gap, and FramePart five-element array remain indexed here without inventing one aggregate object or duplicate declaration.
- `CANONICAL_OWNER:NONE`, blank emitter, blank CPP, and blank H are intentional. Historical UID0000JL ownership represented the synthetic one-file hypothesis and is superseded; the detailed historical relation remains useful as an umbrella cross-link.

## Changes

- 2026-08-25 UID0000JL callback: changed canonical owner `0000JL -> NONE`, preserved `91/93` and non-reconstructable/no-code metadata, and replaced one-file certainty with exact UID000577/UID000578 child routes.

- 2026-07-26 B004 UID0001P1 accepted implementation callback:
  - Changed `87/90 -> 91/93`, retained canonical owner UID0000JL, changed reconstructable true to false, cleared the emitter, and kept both formal channels blank.
  - Reclassified this page as a nonemitting semantic index over two exact source children. Incorporated the complete AboveFrame loader-zero correction, five-scalar/two-array topology, accepted names, file-static linkage, alignment-gap proof, exact lifecycle asymmetry, direct FrameChrome route, and GeneralPurposePanel consumer-only rejection without pruning the separate FramePartPane research or liveness caveats.

- 2026-06-24 B007 FramePartPaneSlotCleanup implementation:
  - Score unchanged at `87/90`.
  - Summary/evidence: incorporated [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md) as source-ready `ReleaseFramePartPanes()` for the `g_framePartPanes[5]` family, while keeping no-function/no-route evidence as a confidence cap. Synced the exact slot storage note with current MCP zero bytes and the PE unbacked-tail model, preserved `FrameChrome` ownership, and distinguished release/delete cleanup from notification pointer clears.
- 2026-06-22 B011 BuildFramePartPanes support incorporation:
  - Score unchanged at `87/90`.
  - Summary/evidence: added the accepted `g_framePartPanes[5]` index-role order and the stronger no-rel32/no-VA/no-RVA route caveat for the builder and raw cleanup start. Kept owner/emitter on [UID:0000JL][FrameChrome](by-file/FrameChrome.md), kept IDA `FF` bytes as unbacked-tail/initializer caveat, and kept exact original slot spelling provisional.
- 2026-06-20 B003 AboveFrame source-quality implementation:
  - Added corrected [UID:0000YI][0x004615b0-0x00461658.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md) path, source-facing `g_pDynamicAboveFrame` role for `0x0067a840`, and the accepted `g_pGeneralPurposePanel->m_activeChildIndex + 5` recreate input.
  - Reaffirmed rejected owner alternatives: GeneralPurposePanel calls the refresh helpers but does not own the frame slots; ResourceLayoutTable/EPF resources provide data inputs; MapPane and generic pane managers have no slot lifecycle evidence.
- 2026-06-20 B006 Rule 26 reconciliation:
  - Score unchanged.
  - Summary/evidence: rechecked the `AboveFrame` slot family from the FrameChrome report side and kept `0x0067a840` as descriptive `g_pDynamicAboveFrame`; tuple semantics remain `(frameIndex, top, left)`, `0x0067a874` remains outside the range as `g_pGeneralPurposePanel`, and `GeneralPurposePanel` supplies only `m_activeChildIndex`, not slot ownership.
- 2026-06-21 B007 Rule 26 report review:
  - Score unchanged.
  - Summary/evidence: verified B007's slot-family recommendations against the current overview and exact child page. No ownership, score, or C++ change was needed.
- 2026-06-19 B002 FramePartPane source-quality implementation support:
  - Added source-facing slot-family wording `g_framePartPanes[5]` for the `0x0069b33c-0x0069b350` `FramePartPane` slots while preserving the exact raw storage range, builder order, cleanup, notification clear, and unresolved live-caller caveats.
  - Final individual-vs-array spelling remains provisional until naming is aligned across the file-level builder, slot cleanup helper, class notification handler, and generated `FrameChrome.cpp`.

- 2026-05-30: Raised completion/confidence from `0/0` to `76/84`. Previously this overview had strong content but no score; it now records current IDA MCP xrefs for the dynamic `AboveFrame` slot and `FramePartPane` slot start while retaining the final-name and neighboring-global caveats.
- 2026-06-05: Marked reconstructable and attached to [UID:0000JL][FrameChrome](by-file/FrameChrome.md).
  - Reason: live IDA MCP recheck confirms these source-declared global slot families are written and cleared by frame-chrome builders/cleanup paths, while caller-side panel code only consumes the frame state.
- 2026-06-06: Raised completion/confidence from `76/84` to `84/88`.
  - Reason: integrated the exact [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md) and [UID:0001PF][0x0069b33c-0x0069b350.FramePartPaneSlots](by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md) page evidence, documented the source-facing static/global rebuild treatment, added the lifecycle split for fixed/dynamic `AboveFrame` storage and five `FramePartPane` slots, and tied both object families to the frame-chrome resource/notification/vtable evidence.
  - Remaining cap: final source slot names and the direct/indirect caller for `BuildFramePartPanes_004B7120` are still unresolved, so reconstruction C++ remains blank.
- 2026-06-07 A002 Batch 033 parent-gate refresh:
  - What existed before: `COMPLETION:84`, `CONFIDENCE:88`, and an overview row that could be read as including `dword_67A874` in the `AboveFrame` slot family.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:89`.
  - Summary/evidence: live IDA MCP refreshed the `AboveFrameSlots` child xrefs, documented the unreferenced `0x0067a844` spacer, corrected the half-open `0x0067a874` boundary to the separate `g_pGeneralPurposePanel` slot, and made this page a valid direct parent for [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md) under the corrected 85/85 gate.
- 2026-06-14 A002 Goal 2 by-global score pass:
  - Changed to: `COMPLETION:87`, `CONFIDENCE:90`.
  - Summary/evidence: live IDA MCP reconfirmed slot xrefs, component function sizes, and the unresolved no-static-caller state for `BuildFramePartPanes`; corrected PE section-offset checking clarified that IDA `FF` bytes over the late `.data` ranges are unbacked-tail placeholder evidence rather than a hard source initializer. Owner and emitter remain [UID:0000JL][FrameChrome](by-file/FrameChrome.md).
