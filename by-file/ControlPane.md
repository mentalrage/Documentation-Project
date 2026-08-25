*** UID:0000IG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ControlPane

## 2026-08-18 ObjectImage Derived-Source Relationship

- ObjectImageControlPane.cpp/.h consumes ControlPane as the direct base for ObjectImageControlPane and indirect base for ObjectImageButtonPane.
- The base constructor receives control type 8 and the supplied bounds; inherited activation/flags/enter-key fields are initialized by the derived constructors.
- ObjectImageButtonPane's source-level non-const HitTestPart(int,int) override returns 11. The five-byte shared physical implementation is folded compiler output, not a new ControlPane.cpp helper or duplicate owner.
- This relationship adds no ControlPane method body, field, score, owner, or emitter change.

## 2026-08-14 B003 ChangePassword Dependency Incorporation

- UID000038 now provides one guarded H definition and a CPP include/children route, eliminating the former duplicate class body across channels.
- This file remains a dependency owner for EPFImageControlPane and ButtonControlPane. It does not own ChangePasswordDialogPane controls, resources, or packet logic; existing file metadata is unchanged.

## Status

- Confidence: very strong for base control ownership and child routing; medium-high for final source-facing member/helper names.
- Proposed module: `ui/core/ControlPane.cpp`
- Historical recovered-source lead: `source-3/simroot_v2/class_ControlPane.cpp`; retained only as superseded search provenance, not current source authority.
- Main address ranges: `0x004949e0-0x00494a81`, `0x00494b80-0x00494c4a`, `0x00494bf0-0x00494bf7`, `0x0049b170-0x0049b1aa`; the legacy [UID:000114][0x004949e0-0x00494b50.ControlPaneAndProgressBarPrelude](by-memory/0x004949e0-0x00494b50.ControlPaneAndProgressBarPrelude.md) and [UID:0002PD][0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers](by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md) pages are now aggregate/index pages because unrelated helpers are interleaved in the old spans.
- Type docs: [UID:0003J9][ControlPaneVtables](by-type/by-vtable/ControlPaneVtables.md), split from [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)

## File Role

`ControlPane` is the base pane for clickable or input-bearing UI controls. It constructs a `Pane` in mode `1`, stores shared control metadata such as control type, neutral range/current state, enabled/active state, visual-state defaults, and hit-test suppression, then installs control-specific vtables. The control-enabled byte at `+0x101` is distinct from inherited Pane visibility at `+0xb4`.

Derived controls such as browser controls, checkbox controls, image controls, minimap controls, fitting-room controls, popup controls, and text buttons all call this constructor.

The current source route has a complete declaration-before-definition cause through [UID:000038][ControlPane](by-class/ControlPane.md) at source position `10`. R7 includes complete `Pane`, forward-declares pointer-only `RectBounds`, declares the inline empty virtual destructor, preserves the primary virtual order through `HitTestPart(int,int)`, exposes the exact protected `+0xf8..+0x104` state band used directly by derived controls, and supplies inline `IsEnabled`, `IsSelectable`, `SetSelectable`, and `SetHandlesEnterKey` accessors. The class closes before `[[CHILDREN]]`, so routed child definitions remain at namespace scope.

The exact `0x108` source layout is `Pane` through `+0xf7`, three protected `short` range words at `+0xf8/+0xfa/+0xfc`, `m_controlType +0xfe`, `m_controlFlags +0xff`, `m_handlesEnterKey +0x100`, enabled/active/visual/hit-testing state at `+0x101..+0x104`, and natural tail alignment through `+0x107`. Direct derived assignments prove protected access; private duplicates, raw offset casts, and public storage are rejected. Narrow inline setters are valid source access, add no layout or slot, and historical generic reserved/invented-setter cautions are superseded. Vtable/RTTI stores, scalar-deleting wrappers, secondary/tertiary adjustor thunks, EH/cookie machinery, and natural padding remain compiler output rather than handwritten `ControlPane.cpp`.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `ControlPane` | [UID:0002PB][0x004949e0-0x00494a81.ControlPaneConstructor](by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md), [UID:0003N2][0x00494b80-0x00494bad.ControlPaneSetVisualState](by-memory/0x00494b80-0x00494bad.ControlPaneSetVisualState.md), [UID:0003N3][0x00494bb0-0x00494bca.ControlPaneEnable](by-memory/0x00494bb0-0x00494bca.ControlPaneEnable.md), [UID:0003N4][0x00494bd0-0x00494bea.ControlPaneDisable](by-memory/0x00494bd0-0x00494bea.ControlPaneDisable.md), [UID:0002PC][0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting](by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md), [UID:0003N5][0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting](by-memory/0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting.md), [UID:0003N6][0x00494c10-0x00494c2a.ControlPaneDeactivate](by-memory/0x00494c10-0x00494c2a.ControlPaneDeactivate.md), [UID:0003N7][0x00494c30-0x00494c4a.ControlPaneActivate](by-memory/0x00494c30-0x00494c4a.ControlPaneActivate.md), plus destructor/thunks | Exact child C++ routes through `NexusTK/ui/core/ControlPane.cpp`: the constructor initializes `m_enabled=true` and `m_ignoreHitTesting=false`; UID0003N3/UID0003N4 emit virtual Enable/Disable at primary slots `+0x4c/+0x50`; inline `IsEnabled` exposes the protected byte safely to unrelated dialog-derived consumers UID00043M/UID00043N without an out-of-line body; the getter/setter emit the hit-test suppression lifecycle. Action-button, navigation, ImageButton, Scrollable, and NewUserDialogPane2 consumers corroborate enablement. Sibling raw helpers retain their no-code dispositions. |
| raw draw-state helper | [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) | Source-shaped active-frame helper now documented at `88/89`. Best source-facing behavior name is `ControlPane::DrawActiveFrame`: it checks `m_enabled` and `m_controlActive`, uses `GrafPort::SetDrawColor` with active-frame color `0x80`, sets inherited `m_drawMode` to `0`, and draws `m_bounds` through `GrafPort::DrawRectFrame`. Current generated `NexusTK/ui/core/ControlPane.cpp` carries no UID0003N9 marker/body/reference because the formal block is blank; this page preserves the route context and behavior prose only, not a C++ body. |
| vtable family | [UID:0003J9][ControlPaneVtables](by-type/by-vtable/ControlPaneVtables.md), [UID:0003J8][0x00617a8c-0x00617b30.ControlPaneVtableData](by-memory/0x00617a8c-0x00617b30.ControlPaneVtableData.md) | Primary control view plus secondary/tertiary handler views at object offsets `+0xa0` and `+0xa4`. |
| adjustor thunk helpers | `0x0049af3d`, `0x0049af48` | Compiler-generated secondary/tertiary destructor thunks; not handwritten control behavior. |
| small fixed virtual | `0x0041d690-0x0041d694` | Returns fixed control constant `10`; semantic name still open. |

## Evidence Notes

- IDA MCP reports 52 direct constructor call sites across UI controls.
- 2026-06-26 B007 accepted constructor source-quality pass updates the source route without changing this file score: [UID:0002PB][0x004949e0-0x00494a81.ControlPaneConstructor](by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md) is now `89/92` and emits first-draft `ControlPane::ControlPane(unsigned char controlType, const RectBounds *bounds)`. MCP session `80de0a67` confirms exact size `0xa1`, direct callees `0x00544460` and `0x00544bd0`, vtable-store refs `0x00617a90` / `0x00617af8` / `0x00617b28`, 52 constructor xrefs, and the padding/sibling boundary before the ProgressBar helper at `0x00494a90`.
- The constructor source shape is base `Pane(1)`, unsigned `controlType` at `+0xfe`, optional bounds, neutral range/current aliases, flags/reserved bytes, `m_enabled=true` at `+0x101`, `m_controlActive=false`, `m_visualState=10`, and `m_ignoreHitTesting=false`. The historical `m_controlVisible` spelling is superseded; Pane visibility is separately stored at `+0xb4`.
- Base primary cells `0x00617adc/0x00617ae0` are exact virtual slots `+0x4c/+0x50` and emit `ControlPane::Enable()` / `Disable()`. UID0004BP, navigation availability consumers, and Scrollable/ImageButton overrides independently establish that state contract.
- [UID:00043M][0x0052b090-0x0052b1cb.NewUserDialogPane2ShiftShapesLeft](by-memory/0x0052b090-0x0052b1cb.NewUserDialogPane2ShiftShapesLeft.md) reads previous control `6` at `+0x101`; [UID:00043N][0x0052b1d0-0x0052b30d.NewUserDialogPane2ShiftShapesRight](by-memory/0x0052b1d0-0x0052b30d.NewUserDialogPane2ShiftShapesRight.md) reads next control `7` at the same offset. Because those methods belong to a dialog-derived class rather than a `ControlPane` subclass, protected direct access is illegal; the inline `IsEnabled() const` declaration is the narrow source-safe representation and generates no standalone function.
- 2026-07-05 B015 implementation of accepted [UID:0002PC][0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting](by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md) source-quality report updates this file route without changing the file score: current MCP session `supervisor_recovery_20260705` confirmed exact getter bytes `8a 81 04 01 00 00 c3`, range `0x00494bf0-0x00494bf7`, no callees, sole caller at `0x0049fb7f` using the result as a post-rectangle-test skip gate, paired setter write at `0x00494c00`, and constructor initialization of `m_ignoreHitTesting=false`. The formal getter remains an exact child emission through this file route.
- 2026-07-12 B005 accepted UID0003N5 source-quality update adds exact child `void ControlPane::SetIgnoreHitTesting(bool ignoreHitTesting)` through this route without changing the file score. Current MCP session `359c7886` confirms exact target bytes/range/unique signature, nine `0xcc` bytes before the target and immediate Deactivate at `0x00494c10`, no callees or ordinary code callers, 50 base/inherited-vtable data refs, and base primary slot `0x00617ae4` (`+0x54`). The setter directly writes `m_ignoreHitTesting`; retained `AL` is incidental store reuse, while constructor initialization, getter read, and getter consumer `0x0049fb7f` establish the boolean suppression lifecycle. Derived-control vtables, PopupMenu consumer context, ProgressBar/Button/RadioGroup adjacency, and raw decompiler types do not change base ControlPane ownership or source placement.
- Support-only constant note: `kControlPaneMode = 1` and `kControlPaneVisualStateNormal = 10` are future class/file-level candidates only. This file page does not currently own shared declarations for them, so [UID:0002PB][0x004949e0-0x00494a81.ControlPaneConstructor](by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md) uses literal `Pane(1)` and `m_visualState(10)` and does not emit target-local enum/type/constant declarations.
- IDA MCP `list_globals` confirms three `ControlPane` vtable bases at `0x00617a90`, `0x00617af8`, and `0x00617b28`; `disasm` confirms `0x0049af3d` and `0x0049af48` as 11-byte destructor adjustor thunks.
- 2026-06-12 A004 live IDA MCP split the exact vtable source-local docs: [UID:0003J9][ControlPaneVtables](by-type/by-vtable/ControlPaneVtables.md) and [UID:0003J8][0x00617a8c-0x00617b30.ControlPaneVtableData](by-memory/0x00617a8c-0x00617b30.ControlPaneVtableData.md). `trace_data_flow backward` confirmed constructor stores at `0x00494a23`, `0x00494a29`, and `0x00494a33`, and `get_int` confirmed the `0x00617b30` `ProgressBarControlPane` successor boundary.
- Generated control classes call `ControlPane::ControlPane` with a control type and optional bounds.
- Wave3 metadata notes one adjustor thunk is excluded and the `GetFixedValue10` semantic name remains uncertain.
- 2026-06-01 IDA MCP confirms the exact constructor range at `0x004949e0-0x00494a81` and hit-test suppression accessor at `0x00494bf0-0x00494bf7`. The local memory between those functions includes progress-bar helpers and later base control-state virtuals, so do not migrate the entire old `0x004949e0-0x00494bf6` span as one contiguous constructor block.
- 2026-06-13 B002 split repair confirms the modeled state helpers at `0x00494b80`, `0x00494bb0`, `0x00494bd0`, `0x00494c00`, `0x00494c10`, and `0x00494c30` are base `ControlPane` virtual slots, not RadioGroup/ButtonControlPane-owned methods. Vtable dwords read as `0x00617ad8 -> 0x00494b80`, `0x00617adc -> 0x00494bb0`, `0x00617ae0 -> 0x00494bd0`, `0x00617ae4 -> 0x00494c00`, `0x00617ae8 -> 0x00494c10`, and `0x00617aec -> 0x00494c30`.
- 2026-06-16 A001 live IDA MCP reconfirmed the source-root child set: constructor `0x004949e0` size `0xa1`, state virtuals `0x00494b80`/`0x00494bb0`/`0x00494bd0`/`0x00494c00`/`0x00494c10`/`0x00494c30`, hit-test accessor `0x00494bf0`, scalar deleting destructor `0x0049b170`, fixed-return virtual `0x0041d690`, and no IDA function at raw helper `0x00494c50`.
- The same A001 pass reconfirmed 52 constructor xrefs across reusable control families, the base state virtual vtable cells `0x00617ad8-0x00617aec`, `0x00617af0 -> 0x0041d690`, the `0x00617b30` successor boundary, and zero xrefs to raw helper start `0x00494c50`.
- 2026-06-16 section-mapped PE scan found zero absolute-VA, zero RVA, and zero direct `E8`/`E9` hits to `0x00494c50`, preserving the raw-helper reachability blocker while confirming that current owner/emitter routing rests on field use and local ControlPane context rather than hidden direct callers.
- 2026-06-20 supervisor Rule 26 incorporation of B001 `0003N9` report kept `ControlPane.cpp` as the output route for the then-empty/no-code marker and recorded the best current source-facing candidate `ControlPane::DrawActiveFrame`. The report rejects ProgressBar, Button/concrete-control, GrafPort-primitive, and no-owner routes, but keeps formal C++ blank because no caller, vtable slot, pointer encoding, or source declaration has been recovered.
- 2026-06-23 B004 MCP-backed recheck raised child [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) to `88/89` while preserving the no-code route and complete negative evidence. That historical pass used `m_controlVisible`; current evidence supersedes it with `m_enabled`. All no-function/no-xref/no-pointer/no-direct-transfer facts, `m_controlActive`, bounds/draw-mode dependencies, and blank formal disposition remain unchanged.

## Cross-References

- [UID:000038][ControlPane](by-class/ControlPane.md)
- [UID:000114][0x004949e0-0x00494b50.ControlPaneAndProgressBarPrelude](by-memory/0x004949e0-0x00494b50.ControlPaneAndProgressBarPrelude.md)
- [UID:0002PB][0x004949e0-0x00494a81.ControlPaneConstructor](by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md)
- [UID:0002PD][0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers](by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md)
- [UID:0003N2][0x00494b80-0x00494bad.ControlPaneSetVisualState](by-memory/0x00494b80-0x00494bad.ControlPaneSetVisualState.md)
- [UID:0003N3][0x00494bb0-0x00494bca.ControlPaneEnable](by-memory/0x00494bb0-0x00494bca.ControlPaneEnable.md)
- [UID:0003N4][0x00494bd0-0x00494bea.ControlPaneDisable](by-memory/0x00494bd0-0x00494bea.ControlPaneDisable.md)
- [UID:0002PC][0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting](by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md)
- [UID:0003N5][0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting](by-memory/0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting.md)
- [UID:0003N6][0x00494c10-0x00494c2a.ControlPaneDeactivate](by-memory/0x00494c10-0x00494c2a.ControlPaneDeactivate.md)
- [UID:0003N7][0x00494c30-0x00494c4a.ControlPaneActivate](by-memory/0x00494c30-0x00494c4a.ControlPaneActivate.md)
- [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md)
- [UID:0003J9][ControlPaneVtables](by-type/by-vtable/ControlPaneVtables.md)
- [UID:0003J8][0x00617a8c-0x00617b30.ControlPaneVtableData](by-memory/0x00617a8c-0x00617b30.ControlPaneVtableData.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- [UID:000120][0x0049af3d-0x0049af52.ControlPaneAdjustorThunks](by-memory/0x0049af3d-0x0049af52.ControlPaneAdjustorThunks.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md)
- [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md)
- [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md)
- [UID:0000M2][NumericStringControlPane](by-file/NumericStringControlPane.md)
- [UID:0000N1][RectangleControlPane](by-file/RectangleControlPane.md)

## Changes

- 2026-08-16 B001 UID0002NC support callback: preserved `90/92`, `NexusTK/ui/core/`, and class position `10`; synchronized UID000038's exact inline `SetSelectable(bool)` after `IsSelectable()`. It writes canonical `1/0` to protected `m_controlFlags +0xff`, adds no include/storage/padding/virtual slot/out-of-line CPP, and supplies the legal read-only EditablePaperPane caller route. Every unrelated ControlPane child and generated ordering fact remains unchanged.

- 2026-07-22 B002 UID00043N bounded support synchronization:
  - Score, route, complete current ControlPane union, and all prior constructor/state/hit-test/raw-helper evidence are unchanged at `90/92` under `NexusTK/ui/core/`.
  - Recorded inline `IsEnabled() const` as the source-safe declaration for exact inherited `+0x101` reads by UID00043M/UID00043N, preserving the distinction from Pane visibility at `+0xb4` and avoiding an out-of-line definition, raw offset, friendship, or public field.

- 2026-07-16 B003 UID0004EL support implementation:
  - Raised `88/91 -> 90/92`; retained `NexusTK/ui/core/`, FILE ownership, and the complete current control-family union.
  - Added R7 as the complete declaration-before-definition source cause: exact `0x108` protected layout, canonical `RectBounds` constructor signature, inline empty virtual destructor, primary virtual order, class closure before children, and direct-derived-access contract.
  - Recorded the source/compiler split: routed child methods remain source definitions; raw active-frame helper stays blank under its exact route-negative proof; vtables, RTTI, deleting wrappers, adjustor thunks, EH/cookie code, and padding are not handwritten.
  - Historicalized `simroot_v2/class_ControlPane.cpp` as search provenance only and preserved all callers, fixed-virtual caveats, neighboring source families, raw-helper evidence, and score caps.

- 2026-07-13 B005 UID0004BP support implementation:
  - Raised `86/88 -> 88/91`; projected path and FILE ownership remain unchanged.
  - Synchronized constructor `m_enabled`, Enable/Disable names and UID-preserving renamed paths, slots `+0x4c/+0x50`, action/navigation/ImageButton/Scrollable consumers, raw-helper enabled gating, and separate Pane visibility at `+0xb4` while preserving all unrelated class/file blockers and raw liveness negatives.

- 2026-06-16 A001 Goal 2 file/class completion pass:
  - Before: `COMPLETION:85`, `CONFIDENCE:86`; the file page had exact child links but did not record the current raw-helper and vtable recheck.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`, with current live IDA evidence for function starts, state-helper vtable cells, constructor fan-in, successor boundary, and raw-helper no-reachability checks.
  - Evidence: `lookup_funcs`, `xrefs_to`, `analyze_component`, `get_int`, `get_bytes`, and a section-mapped PE scan in session `c001_midiplayer_rdata_20260615` reconfirmed the ControlPane source-root inventory. File-level C++ remains blank because several source-facing member names, the fixed-return virtual name, destructor representation, and the raw active-frame helper reachability/source representation are still not final-source quality; exact child pages may emit their own accepted first-draft C++.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:86`.
  - Summary/evidence: base control role, derived caller fanout, vtable families, adjustor thunks, fixed virtual caveat, and related control modules are documented; confidence is strong because ownership is base-control infrastructure, with only the small fixed virtual name still open.

- 2026-06-01 projected path and exact child split:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, and exact constructor/accessor pages did not exist.
  - Changed to: projected path `NexusTK/ui/core/`, with exact child memory docs for the constructor and hit-test suppression accessor.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `ControlPane.cpp` under `ui/core`, and IDA MCP confirms the exact function boundaries and interleaved non-`ControlPane` helper ranges.
- 2026-06-12 A004 Batch 336 vtable split:
  - Before: completion was `82`, and the file only referenced the broad mixed [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md) aggregate for vtable evidence.
  - Changed to: completion `85`, with exact source-local [UID:0003J9][ControlPaneVtables](by-type/by-vtable/ControlPaneVtables.md) and backing [UID:0003J8][0x00617a8c-0x00617b30.ControlPaneVtableData](by-memory/0x00617a8c-0x00617b30.ControlPaneVtableData.md) linked as proposed contents.
  - Summary/evidence: live IDA MCP confirmed the three `ControlPane` bases, constructor store triad, adjustor/scalar-destructor function sizes, and the `ProgressBarControlPane` boundary. The file now clears `85/86`, supporting the refreshed class-parent chain without emitting final C++.
- 2026-06-13 B002 state-helper split repair:
  - Scores unchanged.
  - Added exact state virtual child pages including UID0003N3/UID0003N4 under their historical visible-flag titles; those UID-preserving pages are now [UID:0003N3][0x00494bb0-0x00494bca.ControlPaneEnable](by-memory/0x00494bb0-0x00494bca.ControlPaneEnable.md) and [UID:0003N4][0x00494bd0-0x00494bea.ControlPaneDisable](by-memory/0x00494bd0-0x00494bea.ControlPaneDisable.md). The remaining state children and historical split conclusions are unchanged.
  - Summary/evidence: live IDA/vtable evidence places the modeled `0x00494b80-0x00494c4a` helper slots in the base `ControlPane` vtable, while [UID:0003N1][0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue](by-memory/0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue.md) remains a separate progress-bar child.
- 2026-06-14 B002 current Goal 2 pass:
  - Scores unchanged.
  - Updated [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) from a no-owner candidate to a class-routed raw helper under [UID:000038][ControlPane](by-class/ControlPane.md).
  - Evidence: current IDA MCP and raw PE checks still show no function object, external xref, vtable slot, pointer encoding, or direct branch/call target, but the helper's exact source-shaped bytes, `+0x101/+0x102` base state checks, `+0x70` draw-state clear, `this+0x44` frame draw, and adjacency to assigned base state helpers are strong enough for ownership. C++ emission remains blank pending final-source helper reachability, source representation, and field/helper names.
- 2026-06-20 supervisor Rule 26 incorporation:
  - Scores unchanged.
  - Incorporated B001 details for [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) into this file route: exact local PE no-pointer/no-branch support, refined `+0x101/+0x102/+0x44/+0x70` field meanings, `GrafPort::SetDrawColor`/`DrawRectFrame` dependency names, best future `DrawActiveFrame` spelling, rejected owner alternatives, and the reason generated `ControlPane.cpp` should omit this target's marker/body/reference while the formal block remains blank.
- 2026-06-23 B004 implementation of accepted [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) MCP-backed report:
  - Scores unchanged for this file page.
  - Synchronized the raw draw-state helper to the child page's `88/89` disposition, current MCP/PE route-negative evidence, source-facing names, no-code proof, and behavior prose for `ControlPane::DrawActiveFrame`. `ControlPane.cpp` remains the correct route, but the target must not emit formal `RECONSTRUCTION_CPP` or carry any C++ body outside that formal block until a route/declaration is proven.
- 2026-06-26 B007 implementation of accepted [UID:0002PB][0x004949e0-0x00494a81.ControlPaneConstructor](by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md) source-quality report:
  - Scores unchanged for this file page.
  - Synchronized the constructor source route to the child page's `89/92` disposition: exact `0xa1` constructor, `Pane(1)` base call, unsigned `controlType`, optional bounds, vtable stores, neutral range/current defaults, packed state, 52 refs, and range-safe formal C++. Its then-current visible-field spelling is superseded by `m_enabled`; the offsets and remaining evidence are unchanged.
- 2026-07-05 B015 implementation of accepted [UID:0002PC][0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting](by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md) source-quality report:
  - Scores unchanged for this file page.
  - Synchronized the source route to the child page's `88/92` disposition: [UID:0002PC][0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting](by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md) now emits source-ready first-draft `bool ControlPane::IgnoresHitTesting() const`, returns `m_ignoreHitTesting`, preserves `ControlPane.cpp` as the route, and should replace the generated empty marker after scoped validator refresh.
- 2026-07-12 B005 implementation of accepted UID0003N5 source-quality report:
  - Scores, projected path, and file ownership unchanged at `86/88`, `NexusTK/ui/core/`, and `CANONICAL_OWNER:FILE`.
  - Updated proposed contents and evidence to include UID0003N5's `90/92` source-ready void-bool setter, complete `m_ignoreHitTesting` lifecycle, current exact MCP/range/padding/vtable/caller-callee facts, incidental-`AL` correction, rejected owner/source-shape alternatives, and validator-owned generated route. Exact child formal blocks emit through this file; the file-level page remains documentation-only.

## 2026-07-23 B004 Accepted UID0002E6 Reconciliation (0000IG)

- Accepted source: B004 UID0002E6 report, Gate 1 SHA F8FE25AA9AD6922244A4C7EC84D390D41DE9782819D15DCD6D192A58C1D7EF26.
- NexusTK/ui/core/ControlPane.h is now the explicit compile-visible companion of complete UID000038 and is consumed by UID000053. Existing ControlPane.cpp ownership and 90/92 evidence remain unchanged.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C2E6-086 | 0000IG | `NexusTK/ui/core/ControlPane.h` is the exact companion-header destination for complete declaration UID000038; UID0000IG currently records only the `.cpp` module and must add the header route for FittingRoomListPane inheritance. | Strong | UID0000IG source root, complete UID000038 formal, and FittingRoomListPane inheritance dependency. | UID0000IG proposed-header/source-placement prose and manual by-file row. | incorporate | implemented |
