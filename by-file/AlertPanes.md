*** UID:0000HE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# AlertPanes

## Status

- Confidence: strong for shared alert ownership; medium for exact original filename.
- Proposed module folder: `ui/dialogs/`
- Proposed source file: `ui/dialogs/AlertPanes.cpp`
- Proposed header: `ui/dialogs/AlertPanes.h`
- Current generated sources: `class_AlertPane.cpp`, `class_VersatileAlertPane.cpp`, `class_BlueAlertPane.cpp`, and `class_UrlAlertPane.cpp`.
- Evidence basis: `simroot_v2` generated sources and IDA MCP boundary/decompile/xref checks on 2026-05-24. Wave3 was not executed for this pass.
- Layout docs: [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md).

## Hypothesis

`AlertPanes.cpp` should own the reusable modal alert classes rather than each alert being a one-class source file. These panes share `DialogPane` construction, text measurement, dynamic button creation, modal-list insertion, slide animation, callback dispatch, and small deleting-destructor thunk patterns.

Likely original grouping:

```text
ui/dialogs/AlertPanes.cpp
ui/dialogs/AlertPanes.h
```

Feature-specific alert subclasses should stay with their owning feature modules when their behavior is tightly coupled to packets or singleton state. Examples include `ExchangeAlertPane` in [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md), reconnect alerts in [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md), board/mail reply alert wrappers in [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), and [UID:0000IH][CopyWindow](by-file/CopyWindow.md) beside [UID:0000ON][TextEditPane](by-file/TextEditPane.md).

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| [UID:00000B][AlertPane](by-class/AlertPane.md) | `0x0049feb0-0x004a0686`, vtables [UID:0001WZ][AlertPaneVtables](by-type/by-vtable/AlertPaneVtables.md), shared destructor [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md) | `class_AlertPane.cpp` | Shared dynamic modal alert with optional primary/secondary buttons, static or scrollable text body, modal-list insertion, and slide animation. |
| [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md) | `0x004a0690-0x004a0752`, raw cleanup [UID:00012Y][0x004a06e0-0x004a0714.VersatileAlertPaneRawCleanup](by-memory/0x004a06e0-0x004a0714.VersatileAlertPaneRawCleanup.md), vtables [UID:0001Z0][VersatileAlertPaneVtables](by-type/by-vtable/VersatileAlertPaneVtables.md), destructor island `0x004a0cb0-0x004a0d37` | `class_VersatileAlertPane.cpp` | Thin callback-backed alert wrapper that reports accept/cancel through a stored callback object. |
| [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md) | `0x005008c0-0x0050114d`, vtables [UID:0001X3][BlueAlertPaneVtables](by-type/by-vtable/BlueAlertPaneVtables.md), exact vtable data [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md), shared destructor [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md), adjustor thunks [UID:00010V][0x0048c315-0x0048c32b.AlertPaneAdjustorThunks](by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md) | `class_BlueAlertPane.cpp` | Blue-framed alert variant with custom `BDFRAME.EPF` background/border drawing and selected-list frame painting. Generated `g_uiTileRenderer` calls are a resource/render alias artifact, not AlertPanes ownership. |
| [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md) | `0x00599a40-0x00599cb3`, vtables [UID:0001YZ][UrlAlertPaneVtables](by-type/by-vtable/UrlAlertPaneVtables.md) | `class_UrlAlertPane.cpp` | `AlertPane` subclass that stores an URL string, opens it with `ShellExecuteA`, and can request application exit after confirmation. |
| [UID:0000SM][g_pUrlAlertPane](by-global/g_pUrlAlertPane.md) | `0x0069b4dc` | generated global-data alias | Active URL alert singleton. |

## IDA Evidence

- `AlertPane::AlertPane` is a real function at `0x0049feb0` with size `0x6c5`; `AlertPane::DismissDialog` is a real virtual at `0x004a0580` with size `0x106`.
- 2026-05-26 IDA `py_eval` recheck found 96 xrefs to `AlertPane::AlertPane`, supporting shared `AlertPanes` ownership rather than feature-local placement.
- 2026-05-26 IDA MCP vtable pass confirms `AlertPane` primary/secondary/tertiary vtables at `0x00618b00`, `0x00618b68`, and `0x00618b98`, installed by constructor stores at `0x0049ff1e`, `0x0049ff24`, and `0x0049ff2e`. Current Wave3 metadata still reports `vtable_count: 0`.
- 2026-05-26 IDA layout pass confirms the alert-family three-vptr shape at object offsets `+0x00`, `+0xa0`, and `+0xa4`; `AlertPane` and `BlueAlertPane` store the caller layout reference at `+0x26c`, while derived wrappers reuse `+0x270` for callback or URL storage. See [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md).
- 2026-05-26 IDA MCP recheck confirms [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md) is a shared `AlertPane`-family scalar deleting destructor referenced by `ClanLeaveConfirmDialog`, `AlertPane`, `BlueAlertPane`, `CopyWindow`, and `QuitDialog` vtables; [UID:00010V][0x0048c315-0x0048c32b.AlertPaneAdjustorThunks](by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md) are compiler adjustor thunks into that destructor.
- `VersatileAlertPane` construction at `0x004a0690` calls `AlertPane::AlertPane`, stores the callback/control pointer at object offset `0x270`, and installs three vtables. `0x004a0760` is [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md), not a `VersatileAlertPane` method.
- 2026-05-26 IDA MCP vtable pass confirms `VersatileAlertPane` primary/secondary/tertiary vtables at `0x00618ba4`, `0x00618c0c`, and `0x00618c3c`, installed by constructor stores at `0x004a06b6`, `0x004a06bc`, and `0x004a06c6`. Current Wave3 metadata still reports `class_VersatileAlertPane.meta_wave3` `vtable_count: 0`.
- 2026-05-26 raw-disassembly follow-up confirms the cleanup-shaped [UID:00012Y][0x004a06e0-0x004a0714.VersatileAlertPaneRawCleanup](by-memory/0x004a06e0-0x004a0714.VersatileAlertPaneRawCleanup.md) body: current IDA does not wrap it as a function and finds no callers, but raw disassembly and prewave show the `VersatileAlertPane` vtable stores and callback release.
- `BlueAlertPane` construction at `0x005008c0` initializes a blank `DialogPane`, installs `BlueAlertPane` vtables, measures text, creates static text plus optional buttons, shows the dialog, and stores the layout reference. This disagrees with the current generated constructor summary, which claims a fixed `DIALOG2.DLG` and an OK-only setup.
- 2026-05-26 IDA MCP vtable pass confirms `BlueAlertPane` primary/secondary/tertiary vtables at `0x0061dcd8`, `0x0061dd40`, and `0x0061dd70`, installed by constructor stores at `0x00500920`, `0x00500926`, and `0x00500930`. Current Wave3 metadata still reports `class_BlueAlertPane.meta_wave3` `vtable_count: 0`.
- 2026-05-31 IDA MCP `py_eval` confirms [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md) as the exact `BlueAlertPane` vtable-data range inside the main-menu/new-user `.rdata` block, ending before `UserHairSelectControlPane` RTTI at `0x0061dd78`.
- `BlueAlertPane::DrawContent` and `BlueAlertPane::DrawBorderFrame` do not prove an alert-local tile-renderer singleton. IDA shows `g_pEPFLib` / `dword_67A744` resource lookups through `0x004d02f0` and broad render callbacks such as `dword_69B3E8`; see [UID:0000SV][g_uiTileRenderer](by-global/g_uiTileRenderer.md).
- `UrlAlertPane` construction at `0x00599a40` calls `AlertPane::AlertPane` with a likely OK button string, stores [UID:0000SM][g_pUrlAlertPane](by-global/g_pUrlAlertPane.md), copies the URL into owned heap memory, and records the exit-after-open flag.
- 2026-05-26 IDA MCP vtable pass confirms `UrlAlertPane` primary/secondary/tertiary vtables at `0x0062e584`, `0x0062e5ec`, and `0x0062e61c`, installed by constructor stores at `0x00599aac`, `0x00599ab2`, and `0x00599abc`. Current Wave3 metadata still reports `class_UrlAlertPane.meta_wave3` `vtable_count: 0`.

## Ownership Notes

- `AlertPane` has broad constructor fan-in from login, patch, board/mail, item/menu, terminal, reconnect, and in-game command flows. That fan-in supports a reusable dialog source instead of feature ownership.
- `VersatileAlertPane` direct constructor xrefs were observed from `0x005301de` and `0x0058b5c5`, consistent with callback-backed generic prompts.
- `BlueAlertPane` currently has no direct constructor or custom-virtual code xrefs in IDA. Its vtables and virtual drawing methods are still real, but live reachability and exact feature owner remain open. The generated `g_uiTileRenderer` alias is now explicitly ignored in [UID:0000PF][-ignored](by-global/-ignored.md).
- `UrlAlertPane` constructor xrefs from `0x00503034` and `0x00513f7e`/`0x0051402f` show it as a small shared URL prompt rather than browser implementation code. The `0x00503034` call site is inside [UID:00022Y][0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers](by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md).
- The `0x004a0760-0x004a0c8e` neighborhood between `VersatileAlertPane` callbacks and destructor is [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md) / modeless-dialog event code. Do not pull it into this file solely because it sits between alert-related functions in memory.
- [UID:0000IH][CopyWindow](by-file/CopyWindow.md) derives from `AlertPane`, but current evidence favors a dedicated `CopyWindow.cpp`: Wave2 source-file metadata names it that way, and its state is the active [UID:0000ON][TextEditPane](by-file/TextEditPane.md) pointer rather than reusable alert infrastructure.

## Migration Notes

Defer direct Wave3 ownership edits while the Wave3 agent is working on the tool. When that work resumes, this file is a candidate for:

- creating or renaming a source container to `ui/dialogs/AlertPanes.cpp`;
- attaching `AlertPane`, `VersatileAlertPane`, `BlueAlertPane`, and `UrlAlertPane`;
- keeping feature-specific alert subclasses with feature files unless later xrefs prove they were generic;
- rechecking BlueAlert constructor source text against IDA before materializing it.

## Cross-References

- [UID:00000B][AlertPane](by-class/AlertPane.md)
- [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md)
- [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md)
- [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md)
- [UID:0000IH][CopyWindow](by-file/CopyWindow.md)
- [UID:00012W][0x0049feb0-0x004a0686.AlertPaneCore](by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md)
- [UID:0001WZ][AlertPaneVtables](by-type/by-vtable/AlertPaneVtables.md)
- [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md)
- [UID:0001Z0][VersatileAlertPaneVtables](by-type/by-vtable/VersatileAlertPaneVtables.md)
- [UID:0001X3][BlueAlertPaneVtables](by-type/by-vtable/BlueAlertPaneVtables.md)
- [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md)
- [UID:0001YZ][UrlAlertPaneVtables](by-type/by-vtable/UrlAlertPaneVtables.md)
- [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md)
- [UID:00010V][0x0048c315-0x0048c32b.AlertPaneAdjustorThunks](by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md)
- [UID:00012X][0x004a0690-0x004a0752.VersatileAlertPaneCallbacks](by-memory/0x004a0690-0x004a0752.VersatileAlertPaneCallbacks.md)
- [UID:00012Y][0x004a06e0-0x004a0714.VersatileAlertPaneRawCleanup](by-memory/0x004a06e0-0x004a0714.VersatileAlertPaneRawCleanup.md)
- [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md)
- [UID:00012Z][0x004a0760-0x004a0c8e.ModelessDialogPane](by-memory/0x004a0760-0x004a0c8e.ModelessDialogPane.md)
- [UID:000130][0x004a0cb0-0x004a0d37.VersatileAlertPaneDestructor](by-memory/0x004a0cb0-0x004a0d37.VersatileAlertPaneDestructor.md)
- [UID:0001A5][0x005008c0-0x0050114d.BlueAlertPaneCore](by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md)
- [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md)
- [UID:00022Y][0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers](by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md)
- [UID:0001R5][alert-dialog-resources](by-resource/alert-dialog-resources.md)
- [UID:0000SV][g_uiTileRenderer](by-global/g_uiTileRenderer.md)
- [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md)
- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)

## Changes

- What existed before: the page had strong grouping, vtable, layout, and migration evidence but remained scored as unevaluated.
- What it was changed to: scores were set to `78/85`, and the exact `BlueAlertPane` vtable-data child range [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md) was added.
- Summary and evidence: shared alert ownership is strongly supported by IDA fan-in, vtables, exact child vtable-data ranges, and shared destructor evidence; exact original filename and `BlueAlertPane` live reachability remain the main confidence limits.
- 2026-05-31: Assigned validator reconstruction path.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - After: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`.
  - Evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `AlertPanes.cpp` under `ui/dialogs`; the page's IDA evidence groups `AlertPane`, `VersatileAlertPane`, `BlueAlertPane`, and `UrlAlertPane` as shared dialog infrastructure.
