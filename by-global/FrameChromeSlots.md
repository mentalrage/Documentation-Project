*** UID:0000PN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FrameChromeSlots

## Status

- Confidence: strong for the two observed slot clusters, object types, factory/refresh/cleanup writers, and owner module; medium for final source-level slot names and `FramePartPane` construction reachability.
- Likely owner file: [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- Vtable/layout anchor: [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md)
- Related memory docs: [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md), [UID:0001PF][0x0069b33c-0x0069b350.FramePartPaneSlots](by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md), [UID:0000YI][0x004615b0-0x00461657.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461657.AboveFrameRefreshHelpers.md), and [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md)
- Rebuild handling: model these as source-declared frame-chrome static/global pointer slots. Preserve the concrete addresses only as binary-layout evidence; source names remain provisional.

## Role

The frame chrome code keeps global pointers to visible frame-border pane objects. There are two related but distinct slot families:

| Slot family | Data range | Object type | Builder / users |
| --- | --- | --- | --- |
| `AboveFrame` slots | `0x0067a834-0x0067a874` | [UID:000005][AboveFrame](by-class/AboveFrame.md) pointers and two five-entry pointer arrays | Built by [UID:0000U2][BuildAboveFrameBorder_00461310](by-item/BuildAboveFrameBorder_00461310.md); refreshed by [UID:0000YI][0x004615b0-0x00461657.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461657.AboveFrameRefreshHelpers.md); called from [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md) tab switches. |
| `FramePartPane` slots | `0x0069b33c-0x0069b350` | Five [UID:00005I][FramePartPane](by-class/FramePartPane.md) pointers | Built by [UID:0000U5][BuildFramePartPanes_004B7120](by-item/BuildFramePartPanes_004B7120.md); cleared by `FramePartPane::OnNotification` and by [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md). |

## Slot Layout Summary

The exact slot pages carry the full address-level tables. At the overview level, the source-facing split is:

| Range | Contents | Lifecycle evidence |
| --- | --- | --- |
| `0x0067a834-0x0067a840` | Three direct `AboveFrame*` slots initialized by the border builder. | [UID:0000U2][BuildAboveFrameBorder_00461310](by-item/BuildAboveFrameBorder_00461310.md) constructs the fixed border pieces. |
| `0x0067a840` | Dynamic `AboveFrame*` slot. | Written by the border builder, deleted by the release helper, rebuilt by the adjacent recreate helper, and cleared on allocation failure. |
| `0x0067a844` | Initialized spacer inside the `AboveFrame` slot range. | Live IDA reports `0xffffffff` and no direct xrefs; keep it with the `AboveFrame` storage island rather than treating it as an independent global. |
| `0x0067a848-0x0067a874` | Two five-entry `AboveFrame*` slot arrays. | The exact slot page records the array split and confirms the half-open end before the separate `g_pGeneralPurposePanel` slot at `0x0067a874`. |
| `0x0069b33c-0x0069b350` | Five `FramePartPane*` slots initialized to `0xffffffff` in `.data`. | [UID:00022F][0x004b7120-0x004b731f.BuildFramePartPanes](by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md) writes all five slots; [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md) and [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md) clear them. |

## Ownership Decision

Keep these globals with frame/chrome source, not with [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md), [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md), or generic pane-manager source. General-purpose panel switches call the refresh helpers, but they do not own the frame objects or the slot storage.

The object families also share the same frame-chrome evidence bundle: `FRMPART`/`TABS` resources and palettes, the `goog` notification path, and the short three-view vtable pattern recorded by [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md). Exact vtable-data children [UID:0002NG][0x00610ed8-0x00610f60.AboveFrameVtableData](by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md) and [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md) support keeping both slot families under [UID:0000JL][FrameChrome](by-file/FrameChrome.md), even though the concrete storage ranges are not adjacent.

Do not move these globals to [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) or EPF library ownership just because the constructors load `FRMPART.EPF`, `FRMPART.EPD`, `TABS.EPF`, `FRMPART.PAL`, `TABS.PAL`, and `NPAL5.PAL`. Those resources are constructor inputs; the pointer slots are pane lifetime state.

## IDA MCP Evidence

Checked on 2026-05-25 and rechecked on 2026-05-26:

- `xrefs_to 0x0069b33c-0x0069b34c` shows writes from `0x004b7120`, clears from raw cleanup bytes at `0x004b7320-0x004b73a3`, and clears from `FramePartPane::OnNotification` at `0x004b73b0`.
- `xrefs_to 0x0067a834-0x0067a860` shows writes from `BuildAboveFrameBorder` at `0x00461310`. `0x0067a840` also has cleanup/refresh xrefs from `0x004615b0` and the adjacent dynamic-create helper currently mislabeled by IDA as `__std_parallel_algorithms_hw_threads`.
- `callers 0x00461310` reports two calls inside `0x004f7d10`, matching main UI graph setup. `callers 0x004b7120` currently reports no direct callers, so the five-part `FramePartPane` factory remains a retained or indirect construction path until a caller is recovered.
- `callers 0x004615b0` and `callers 0x004615d0` both report the general-panel switch functions `0x004b8650` and `0x004b89a0`; those calls are dependencies on frame-chrome state, not ownership evidence for the globals.
- 2026-05-30 IDA MCP `xrefs_to 0x0067a840` confirms dynamic `AboveFrame` slot writes from `BuildAboveFrameBorder`, delete/read at `0x004615b0`, recreate write at `0x0046162b`, and allocation-failure clear at `0x0046163f`.
- 2026-05-30 IDA MCP `xrefs_to 0x0069b33c` confirms the `FramePartPane` slot start is written by `0x004b7120`, referenced by raw cleanup bytes at `0x004b7320`/`0x004b7330`, and cleared by `FramePartPane::OnNotification` at `0x004b73cb`.
- 2026-06-05 IDA MCP recheck confirmed `AboveFrame` slot xrefs at `0x0067a834`/`0x0067a840` from `0x00461310`, `0x004615b0`, and the dynamic recreate helper, plus `FramePartPane` slot xrefs at `0x0069b33c`/`0x0069b34c` from builder, cleanup bytes, and `FramePartPane::OnNotification`.
- Neighbor-page evidence through 2026-06-06 raises this overview above the child-parent attachment gate: `AboveFrameSlots` and `FramePartPaneSlots` both document exact ranges, object types, slot counts, initial storage, writer/clearer xrefs, and unresolved naming/reachability caveats; [UID:0000JL][FrameChrome](by-file/FrameChrome.md) is already the above-threshold owner.
- `FramePartPane` reachability remains a deliberate cap. The factory at `0x004b7120` constructs and writes real slot state, and cleanup/notification paths consume that state, but current IDA evidence still reports no direct static callers for the factory.
- 2026-06-07 A002 live IDA MCP `py_eval` refreshed the `AboveFrame` half of this overview while working [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md): `0x0067a834`, `0x0067a838`, `0x0067a83c`, `0x0067a840`, `0x0067a848`, `0x0067a84c`, and `0x0067a860` have the expected builder/release/recreate xrefs; `0x0067a844` is unreferenced filler; `0x0067a874` is the separate [UID:00028X][0x0067a874-0x0067a878.g_pGeneralPurposePanel](by-memory/0x0067a874-0x0067a878.g_pGeneralPurposePanel.md), not part of the `AboveFrameSlots` child.

## Score Rationale

Completion is raised to 86 because the overview now includes the internal `AboveFrame` spacer, the exact half-open boundary before `g_pGeneralPurposePanel`, the two distinct slot-family ranges, lifecycle writers/clearers, and child-page support for both storage families. Confidence is raised to 89 because live IDA agrees with the exact child pages on object type and ownership; it remains below final confidence because final source-level slot names and `FramePartPane` factory reachability are still unresolved.

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

## Changes

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
