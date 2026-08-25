*** UID:00000Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// BlueAlertPane is assigned to this AlertPanes source family, but current evidence does not yet
// support a source-quality class declaration shell. IDA confirms the constructor/draw/action methods,
// three vtable views, shared AlertPane-family destructor thunks, BDFRAME.EPF drawing, and
// m_layoutReference at +0x26c; it still finds no direct constructor caller/allocation route and
// no final base/member/helper spelling.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BlueAlertPane

## Status

- Assigned source file: [UID:0000HE][AlertPanes](by-file/AlertPanes.md). Live construction reachability remains unresolved after the 2026-06-05 IDA xref recheck, but the class-level source ownership is strong enough for no-code parent attachment.
- Address ranges: [UID:0001A5][0x005008c0-0x0050114d.BlueAlertPaneCore](by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md), with shared destructor [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md) and adjustor thunks [UID:00010V][0x0048c315-0x0048c32b.AlertPaneAdjustorThunks](by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md).
- Vtables: [UID:0001X3][BlueAlertPaneVtables](by-type/by-vtable/BlueAlertPaneVtables.md) at `0x0061dcd8`, `0x0061dd40`, and `0x0061dd70`; exact vtable bytes are split as [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md).
- Layout docs: [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md).
- Confidence: medium-high for vtables, method roles, and resource usage; lower for exact constructor source text and live construction path.

## Class Purpose

`BlueAlertPane` is a blue-framed alert/dialog variant. It has dynamic alert construction similar to `AlertPane`, custom selected-list frame painting, and custom `BDFRAME.EPF` background/border drawing.

## Class Shape

- Base family: [UID:00000B][AlertPane](by-class/AlertPane.md)-family dialog with three vtable views and shared alert deleting-destructor support.
- Layout state: stores caller layout reference at `+0x26c` and follows [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md).
- Render role: draws blue framed alert/list content from `BDFRAME.EPF` using EPF frame lookup/render callbacks.
- Source placement: attached to [UID:0000HE][AlertPanes](by-file/AlertPanes.md), with live construction path still unresolved.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ScalarDeletingDestructor` | [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md) | Shared `AlertPane`-family deleting destructor, reused by multiple alert/dialog derived vtables. |
| `AdjustorThunk` | [UID:00010V][0x0048c315-0x0048c32b.AlertPaneAdjustorThunks](by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md) | Secondary/tertiary vtable thunks into the shared deleting destructor. |
| `BlueAlertPane` | `0x005008c0-0x00500c24` | IDA shows dynamic text measurement, static text creation, optional button creation, dialog show, slide animation, and layout-reference storage. |
| `HandleActionButton` | `0x00500c30-0x00500c70` | Handles action ids `1` and `2`, dispatches primary/secondary callback slots, and closes the dialog. |
| `DrawSelectedItemFrame` | `0x00500c70-0x00500d6e` | Repaints the pane, fetches the selected list item bounds, and draws a multi-line highlight frame with active/inactive colors. |
| `DrawContent` | `0x00500d70-0x00500e19` | Draws alternate content or fills the body with `BDFRAME.EPF` frame `8` through `g_pEPFLib` frame lookup plus shared render callbacks. |
| `DrawBorderFrame` | `0x00500e20-0x0050114d` | Tiles `BDFRAME.EPF` frames `0` through `7` as corners and edges; apparent `g_uiTileRenderer` calls are a stale alias over `g_pEPFLib` and `dword_69B3E8`. |

## Evidence Notes

- IDA confirms the `0x005008c0` constructor body does not match older prose that claimed `DIALOG2.DLG`, parent dimensions, and a single OK button.
- 2026-05-26 IDA MCP vtable pass confirms `BlueAlertPane` primary/secondary/tertiary vtables at `0x0061dcd8`, `0x0061dd40`, and `0x0061dd70`, installed by constructor stores at `0x00500920`, `0x00500926`, and `0x00500930`.
- 2026-05-31 IDA MCP vtable-data recheck confirms [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md) as the exact vtable-data child range. `0x0061dd78` is `UserHairSelectControlPane` RTTI and `0x0061dd7c` is the next class vtable start, so the `BlueAlertPane` table does not extend past `0x0061dd78`.
- 2026-05-26 IDA layout pass confirms the same three-view vptr offsets as `AlertPane` and confirms the constructor stores the caller layout reference at `+0x26c`; see [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md).
- 2026-05-26 current-state IDA MCP recheck shows no direct callers or code xrefs for `0x005008c0`, `0x00500c30`, `0x00500c70`, `0x00500d70`, or `0x00500e20`; the four virtual handlers are referenced through the primary vtable only, and the three vtable bases are only stored by the constructor. Treat live construction paths as unresolved.
- 2026-06-05 live IDA MCP confirms method ranges: constructor `sub_5008C0` is `0x005008c0-0x00500c24`, action handler `sub_500C30` is `0x00500c30-0x00500c70`, selected-frame draw `sub_500C70` is `0x00500c70-0x00500d6e`, content draw `sub_500D70` is `0x00500d70-0x00500e19`, and border draw `sub_500E20` is `0x00500e20-0x0050114d`.
- 2026-06-05 live IDA xrefs again show no direct xrefs to `0x005008c0`; the virtual handlers are referenced only by vtable data at `0x0061dd1c`, `0x0061dd20`, `0x0061dd28`, and `0x0061dd2c`.
- 2026-06-12 Agent-C001 live IDA MCP recheck reconfirmed the constructor function object at `0x005008c0-0x00500c24`, no direct constructor xrefs, the `0x00501150` successor boundary, and the enclosing mixed aggregate as non-emitting; this preserves `AlertPanes` ownership while clearing the strict parent gate for the exact executable child.
- 2026-06-05 live vtable-base xrefs confirm the three BlueAlertPane vptr stores in the constructor: `0x00500920` writes the primary vtable to `[ebx]`, `0x00500926` writes the secondary vtable to `[ebx+0xa0]`, and `0x00500930` writes the tertiary vtable to `[ebx+0xa4]`. The same pass confirms the layout-reference store at `0x00500bfe` as `mov [ebx+26Ch], eax`.
- 2026-06-05 live vtable-slot check ties the primary table to shared scalar destructor `0x0048c550`, virtual handlers `0x00500c70`, `0x00500c30`, `0x00500d70`, and `0x00500e20`, and the secondary/tertiary tables to adjustor thunks `0x0048c315` and `0x0048c320`.
- 2026-06-05 live action-handler disassembly shows `0x00500c3a-0x00500c40` limits handled action ids to `1` and `2`; id `1` calls the virtual callback at `[vtable+0x5c]`, id `2` calls `[vtable+0x60]`, and both successful paths close through `sub_49DAD0`.
- 2026-06-05 live resource pass confirms `DrawContent` resolves `BDFRAME.EPF` frame `8` through `dword_67A744` and `sub_4D02F0`, then renders through `sub_4BA6B0`.
- 2026-06-05 live border pass confirms `DrawBorderFrame` resolves `BDFRAME.EPF` frame ids `1`, `6`, `3`, `4`, `0`, `2`, `5`, and `7`, with repeated render calls through `dword_69B3E8`.
- `DrawContent` and `DrawBorderFrame` are concrete resource evidence for [UID:0001R5][alert-dialog-resources](by-resource/alert-dialog-resources.md).
- IDA MCP decompile/disassembly of `0x00500d70` and `0x00500e20` shows `dword_67A744` / [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) frame resolution and render callbacks, not a real `g_uiTileRenderer` singleton.
- 2026-05-26 IDA MCP xrefs show the `0x0048c550` deleting destructor and `0x0048c315`/`0x0048c320` thunks are shared by `AlertPane`, `BlueAlertPane`, `CopyWindow`, `QuitDialog`, and `ClanLeaveConfirmDialog` vtables. Do not treat that island as BlueAlert-only code.

## Data Caveats

- Older destructor notes still name `TransferReplyAlert` teardown. Treat that as base-owner pollution.
- The constructor should be rewritten from IDA before source migration.
- The `g_uiTileRenderer` global-data record is now listed in [UID:0000PF][-ignored](by-global/-ignored.md) as a stale alias. Do not make it a source singleton without a later render/global pass proving backing storage.

## Reconstruction Notes

- Attached to [UID:0000HE][AlertPanes](by-file/AlertPanes.md) as an assigned/no-code class. The parent file has a valid `NexusTK/ui/dialogs/` reconstruction path and already groups the shared `AlertPane`, `VersatileAlertPane`, `BlueAlertPane`, and `UrlAlertPane` family from IDA-backed evidence.
- Parent position is `30`, following the intended source-family order `AlertPane`, `VersatileAlertPane`, `BlueAlertPane`, then `UrlAlertPane` recorded on [UID:0000HE][AlertPanes](by-file/AlertPanes.md).
- Do not emit class C++ yet. The older constructor body notes are contradicted by IDA evidence, and the final source declaration still needs a constructor rewrite, exact field names, and a live-reachability explanation.
- 2026-06-05 live IDA MCP retry succeeded. It refreshed method ranges, vtable/xref ownership, action-handler behavior, and frame-resource evidence, while still finding no direct constructor xrefs.

## 2026-06-30 B011 Class-Shell Audit

- Constructor/destructor route: IDA models `0x005008c0-0x00500c24` as the constructor and still reports zero direct xrefs or allocation/caller routes to `0x005008c0`. The class uses the shared alert-family scalar deleting destructor [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md) plus secondary/tertiary adjustor thunks [UID:00010V][0x0048c315-0x0048c32b.AlertPaneAdjustorThunks](by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md); no Blue-specific destructor body is currently identified.
- Vtable slots: constructor stores primary/secondary/tertiary views at `0x00500920`, `0x00500926`, and `0x00500930`. Primary custom slots point to `0x00500c70` selected-item frame drawing, `0x00500c30` action handling, `0x00500d70` content drawing, and `0x00500e20` border drawing. Primary `+0x5c` and `+0x60` remain base no-op callback slots, and the secondary/tertiary first slots are shared adjustor thunks.
- Method inventory: current executable children are constructor `0x005008c0-0x00500c24`, action handler `0x00500c30-0x00500c70`, selected-item frame draw `0x00500c70-0x00500d6e`, content draw `0x00500d70-0x00500e19`, and border draw `0x00500e20-0x0050114d`, with successor boundary `0x00501150`.
- Fields/offsets: observed class-family offsets are three vptrs at `+0x00`, `+0xa0`, and `+0xa4`, and the layout reference at `+0x26c`. Offsets such as `+0x1fc`, `+0x200`, `+0x204`, and `+0x260` are inherited/provisional DialogPane/list/render state and are not safe BlueAlertPane member declarations in this pass.
- Base class: the constructor calls `DialogPane` construction directly with the blank resource string rather than `AlertPane::AlertPane`, while vtables and destructor reuse match the alert family. The exact original source base spelling is therefore not safe to force as either `AlertPane` or direct `DialogPane`.
- Direct child ownership: keep [UID:0001A5][0x005008c0-0x0050114d.BlueAlertPaneCore](by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md), [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md), and [UID:0001X3][BlueAlertPaneVtables](by-type/by-vtable/BlueAlertPaneVtables.md) under this class, and keep this class under [UID:0000HE][AlertPanes](by-file/AlertPanes.md). Do not move draw methods to EPF/render globals; those are dependencies.
- Declaration-shell decision: a class shell with `[[CHILDREN]]` would overclaim the base class, constructor signature, inherited/member field names, and helper names while the constructor still has no live allocation route. The safe output remains the formal no-code class-disposition marker above.

## Score Rationale

Completion is raised to `85` because live IDA now confirms the method ranges, vtable-store addresses, vtable-slot ownership, layout-reference store, action-button dispatch behavior, unresolved constructor reachability, `BDFRAME.EPF` frame use, exact executable child, vtable-data child, and corrected mixed-aggregate parent context. Confidence is `87` because the class shape and virtual/render behavior are strongly backed by live disassembly and current C001 boundary checks, but it remains below final-source confidence because the constructor has not been rewritten and the allocation/reachability path is still missing.

## Cross-References

- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- [UID:0001A5][0x005008c0-0x0050114d.BlueAlertPaneCore](by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md)
- [UID:0001X3][BlueAlertPaneVtables](by-type/by-vtable/BlueAlertPaneVtables.md)
- [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md)
- [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md)
- [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md)
- [UID:00010V][0x0048c315-0x0048c32b.AlertPaneAdjustorThunks](by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md)
- [UID:0001R5][alert-dialog-resources](by-resource/alert-dialog-resources.md)
- [UID:0000SV][g_uiTileRenderer](by-global/g_uiTileRenderer.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:00000B][AlertPane](by-class/AlertPane.md)

## Changes

- What existed before: the page contained IDA-based corrections for old constructor/render aliases and live-reachability caveats; it referenced the vtables only through the type page.
- What it was changed to: the class is marked reconstructable, scores were raised conservatively to `68/80`, and the exact vtable-data child range [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md) was added.
- Summary and evidence: vtables, layout stores, render methods, and vtable-data boundaries are now well supported by IDA MCP evidence. Confidence remains below final-source level because older constructor prose is wrong and no direct live construction xrefs were found.
- 2026-06-03 parent assignment:
  - What existed before: the class was reconstructable but unassigned even though its likely source file was already documented as [UID:0000HE][AlertPanes](by-file/AlertPanes.md).
  - Changed to: `COMPLETION:72`, `CONFIDENCE:82`, and `AUTOGEN_PARENT_UID:0000HE`, with C++ still blank.
  - Summary/evidence: the AlertPanes page has a valid projected path and IDA-backed shared alert-family grouping. The attachment is limited to source ownership; constructor text and live construction reachability remain open.
- 2026-06-05 live IDA refresh:
  - What existed before: the class was `72/82`, assigned to AlertPanes, and still carried stale constructor/render caveats plus a failed-MCP note.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:86`, stale evidence wording removed, and current live IDA facts added for method ranges, xrefs, vtable slots, action dispatch, and resource-frame rendering.
  - Summary/evidence: IDA MCP confirms no direct xrefs to constructor `0x005008c0`, virtual handler xrefs only through the BlueAlertPane vtable data, constructor vptr stores at `0x00500920/0x00500926/0x00500930`, layout reference store at `0x00500bfe`, action ids `1` and `2`, `DrawContent` frame `8`, and `DrawBorderFrame` frames `0` through `7`. The score is capped because constructor source recovery and live construction reachability are still unresolved.
- 2026-06-07 A004 parent-order sync:
  - What existed before: the class was attached to [UID:0000HE][AlertPanes](by-file/AlertPanes.md), but its optional child position was blank and the manual by-class coverage row still showed the older `72%` score.
  - Changed to: set `AUTOGEN_PARENT_POSITION_OPTIONAL:30` and documented the intended order within the shared alert-family source root. The coverage row is pending because [UID:000001][-coverage-report](by-class/-coverage-report.md) is currently leased by another agent.
  - Summary/evidence: [UID:0000HE][AlertPanes](by-file/AlertPanes.md) lists the reusable alert family in order as `AlertPane`, `VersatileAlertPane`, `BlueAlertPane`, and `UrlAlertPane`; this page already carries the IDA-backed `82/86` method, vtable, layout, and resource evidence.
- 2026-06-12 Agent-C001 Batch C001-011 strict-gate repair:
  - Changed to: `COMPLETION:85`, `CONFIDENCE:87`, parent unchanged [UID:0000HE][AlertPanes](by-file/AlertPanes.md) at position `30`.
  - Summary/evidence: C001 live IDA MCP reconfirmed the exact `0x005008c0-0x00500c24` constructor boundary, no direct constructor xrefs, and the `0x00501150` successor boundary while repairing the enclosing [UID:0001A4][0x00500640-0x00502755.SpecializedButtonPanes](by-memory/0x00500640-0x00502755.SpecializedButtonPanes.md) aggregate as non-emitting. Together with the existing vtable/layout/resource evidence, the class and exact child now clear the strict `85/85` gate; final C++ remains deferred.
- 2026-06-30 B011 empty-emitter implementation:
  - Score and metadata unchanged at `85/87`, owner/emitter [UID:0000HE][AlertPanes](by-file/AlertPanes.md).
  - Added the formal class-disposition no-code marker and the per-class shell audit. The audit proves constructor/destructor route, vtable slots, method inventory, fields/offsets, base-class uncertainty, child ownership, and why a declaration shell with `[[CHILDREN]]` is still unsafe.
