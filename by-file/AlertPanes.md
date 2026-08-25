*** UID:0000HE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# AlertPanes

## UID0003ZT Alert Global Declaration Contract - 2026-07-23

- The canonical source pair remains `NexusTK/ui/dialogs/AlertPanes.h` and `NexusTK/ui/dialogs/AlertPanes.cpp`.
- AlertPanes.h exports the declaration `extern UrlAlertPane *g_pUrlAlertPane;` with the type declaration visibility required by consumers. The sole storage definition remains [UID:0000SM][g_pUrlAlertPane](by-global/g_pUrlAlertPane.md) in AlertPanes.cpp.
- MapPane.cpp includes AlertPanes.h before [UID:0003ZT][0x00508f60-0x0050902b.MapPaneNotifyMessageCore](by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md) tests the pointer as a guard. MapPane neither defines nor owns the alert singleton and does not construct UrlAlertPane in this path.
- Scores remain `85/88`; VersatileAlertPane, AlertPane/Blue/Url family evidence, ABI/vtable support, source order, and the blank by-file formal remain unchanged.

## Status

- Confidence: strong for shared alert ownership, family layout, vtable stores, and the `UrlAlertPane` placement; medium-strong for exact original filename.
- Proposed module folder: `ui/dialogs/`
- Proposed source file: `ui/dialogs/AlertPanes.cpp`
- Proposed header: `ui/dialogs/AlertPanes.h`
- Current recovered labels: `AlertPane`, `VersatileAlertPane`, `BlueAlertPane`, and `UrlAlertPane`.
- Evidence basis: existing class/type/global/memory documentation plus IDA MCP boundary, decompile, xref, vtable, layout, exact read-only-data, and raw-disassembly checks recorded below.
- Autogen readiness: the valid `NexusTK/ui/dialogs/` source root and `85/88` score satisfy the strict parent-side attachment gate for alert-family class, layout, and memory children that independently pass their own score/evidence gates.
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

| Entity | Current range | Recovered label | Role |
| --- | --- | --- | --- |
| [UID:00000B][AlertPane](by-class/AlertPane.md) | `0x0049feb0-0x004a0686`, vtables [UID:0001WZ][AlertPaneVtables](by-type/by-vtable/AlertPaneVtables.md), shared destructor [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md) | `AlertPane` | Shared dynamic modal alert with optional primary/secondary buttons, static or scrollable text body, modal-list insertion, and slide animation. |
| [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md) | non-emitting index [UID:00012X][0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland](by-memory/0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland.md); source children [UID:0004NB][0x004a0690-0x004a06d7.VersatileAlertPaneConstructor](by-memory/0x004a0690-0x004a06d7.VersatileAlertPaneConstructor.md), [UID:00012Y][0x004a06e0-0x004a0715.VersatileAlertPaneDestructor](by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneDestructor.md), [UID:0004NC][0x004a0720-0x004a0732.VersatileAlertPaneOnPrimaryButton](by-memory/0x004a0720-0x004a0732.VersatileAlertPaneOnPrimaryButton.md), and [UID:0004ND][0x004a0740-0x004a0752.VersatileAlertPaneOnSecondaryButton](by-memory/0x004a0740-0x004a0752.VersatileAlertPaneOnSecondaryButton.md); vtables [UID:0001Z0][VersatileAlertPaneVtables](by-type/by-vtable/VersatileAlertPaneVtables.md); compiler-destructor island `0x004a0cb0-0x004a0d37` | `VersatileAlertPane` | Thin callback-backed alert wrapper that owns `FunctionObjectT<unsigned long> *m_resultCallback` at `+0x270`, invokes it with primary/secondary results `1/0`, and deletes it in the ordinary destructor. Accept/cancel remain behavior aliases. |
| [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md) | `0x005008c0-0x0050114d`, vtables [UID:0001X3][BlueAlertPaneVtables](by-type/by-vtable/BlueAlertPaneVtables.md), exact vtable data [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md), shared destructor [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md), adjustor thunks [UID:00010V][0x0048c315-0x0048c32b.AlertPaneAdjustorThunks](by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md) | `BlueAlertPane` | Blue-framed alert variant with custom `BDFRAME.EPF` background/border drawing and selected-list frame painting. Recovered `g_uiTileRenderer` calls are a resource/render alias artifact, not AlertPanes ownership. |
| [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md) | `0x00599a40-0x00599cb3`, vtables [UID:0001YZ][UrlAlertPaneVtables](by-type/by-vtable/UrlAlertPaneVtables.md), exact vtable data [UID:0002P0][0x0062e580-0x0062e624.UrlAlertPaneVtableData](by-memory/0x0062e580-0x0062e624.UrlAlertPaneVtableData.md) | `UrlAlertPane` | `AlertPane` subclass that owns an ANSI URL buffer, opens it with `ShellExecuteA` from `OnPrimaryButton`, and can request application exit after confirmation. Method-body draft C++ now emits through the class page; compiler EH/thunk/deleting-destructor glue remains no-code. |
| [UID:0000SM][g_pUrlAlertPane](by-global/g_pUrlAlertPane.md) | `0x0069b4dc` | global-data alias | Active URL alert singleton, declared as `UrlAlertPane *g_pUrlAlertPane = NULL;` with final `static`/external linkage still open. |

## IDA Evidence

- `AlertPane::AlertPane` is a real function at `0x0049feb0` with size `0x6c5`; `AlertPane::DismissDialog` is a real virtual at `0x004a0580` with size `0x106`.
- 2026-05-26 IDA `py_eval` recheck found 96 xrefs to `AlertPane::AlertPane`, supporting shared `AlertPanes` ownership rather than feature-local placement.
- 2026-05-26 IDA MCP vtable pass confirms `AlertPane` primary/secondary/tertiary vtables at `0x00618b00`, `0x00618b68`, and `0x00618b98`, installed by constructor stores at `0x0049ff1e`, `0x0049ff24`, and `0x0049ff2e`. Older recovered metadata did not model these vtables, so IDA-backed vtable docs are the placement authority.
- 2026-05-26 IDA layout pass confirms the alert-family three-vptr shape at object offsets `+0x00`, `+0xa0`, and `+0xa4`; `AlertPane` and `BlueAlertPane` store the caller layout reference at `+0x26c`, while derived wrappers reuse `+0x270` for callback or URL storage. See [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md).
- 2026-05-26 IDA MCP recheck confirms [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md) is a shared `AlertPane`-family scalar deleting destructor referenced by `ClanLeaveConfirmDialog`, `AlertPane`, `BlueAlertPane`, `CopyWindow`, and `QuitDialog` vtables; [UID:00010V][0x0048c315-0x0048c32b.AlertPaneAdjustorThunks](by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md) are compiler adjustor thunks into that destructor.
- `VersatileAlertPane` construction at `0x004a0690` calls `AlertPane::AlertPane`, stores `m_resultCallback` at object offset `0x270`, and installs three vtables. `0x004a0760` is [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md), not a `VersatileAlertPane` method.
- 2026-05-26 IDA MCP vtable pass confirms `VersatileAlertPane` primary/secondary/tertiary vtables at `0x00618ba4`, `0x00618c0c`, and `0x00618c3c`, installed by constructor stores at `0x004a06b6`, `0x004a06bc`, and `0x004a06c6`. Older recovered metadata did not model these vtables, so IDA-backed vtable docs are the placement authority.
- 2026-05-26 raw-disassembly follow-up, refreshed on 2026-06-13, confirms the ordinary-destructor-shaped [UID:00012Y][0x004a06e0-0x004a0715.VersatileAlertPaneDestructor](by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneDestructor.md) body: current IDA does not wrap it as a function and finds no callers, but raw disassembly and nearby alert docs show the `VersatileAlertPane` vtable stores, callback release, and base teardown. Its accepted source is `delete m_resultCallback;`; the remaining effects are compiler generated.
- `BlueAlertPane` construction at `0x005008c0` initializes a blank `DialogPane`, installs `BlueAlertPane` vtables, measures text, creates static text plus optional buttons, shows the dialog, and stores the layout reference. This disagrees with older constructor summaries that claimed a fixed `DIALOG2.DLG` and an OK-only setup.
- 2026-05-26 IDA MCP vtable pass confirms `BlueAlertPane` primary/secondary/tertiary vtables at `0x0061dcd8`, `0x0061dd40`, and `0x0061dd70`, installed by constructor stores at `0x00500920`, `0x00500926`, and `0x00500930`. Older recovered metadata did not model these vtables, so IDA-backed vtable docs are the placement authority.
- 2026-05-31 IDA MCP `py_eval` confirms [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md) as the exact `BlueAlertPane` vtable-data range inside the main-menu/new-user `.rdata` block, ending before `UserHairSelectControlPane` RTTI at `0x0061dd78`.
- `BlueAlertPane::DrawContent` and `BlueAlertPane::DrawBorderFrame` do not prove an alert-local tile-renderer singleton. IDA shows `g_pEPFLib` / `dword_67A744` resource lookups through `0x004d02f0` and broad render callbacks such as `dword_69B3E8`; see [UID:0000SV][g_uiTileRenderer](by-global/g_uiTileRenderer.md).
- `UrlAlertPane` construction at `0x00599a40` calls `AlertPane::AlertPane` with a likely OK button string, stores [UID:0000SM][g_pUrlAlertPane](by-global/g_pUrlAlertPane.md), copies the URL into owned heap memory, and records the exit-after-open flag.
- 2026-05-26 IDA MCP vtable pass confirms `UrlAlertPane` primary/secondary/tertiary vtables at `0x0062e584`, `0x0062e5ec`, and `0x0062e61c`, installed by constructor stores at `0x00599aac`, `0x00599ab2`, and `0x00599abc`. Older recovered metadata did not model these vtables, so IDA-backed vtable docs are the placement authority.
- 2026-06-07 documentation pass links the executable [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md) to exact vtable-data child [UID:0002P0][0x0062e580-0x0062e624.UrlAlertPaneVtableData](by-memory/0x0062e580-0x0062e624.UrlAlertPaneVtableData.md) and mixed-owner read-only aggregate [UID:00026S][0x0062e578-0x0062e624.UniApiUrlAlertReadOnlyData](by-memory/0x0062e578-0x0062e624.UniApiUrlAlertReadOnlyData.md), proving that only the URL-alert subrange belongs to this file while the preceding `UniAPIInit` dword remains a platform/API concern.
- 2026-06-11 A003 live IDA MCP recheck against `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` reconfirmed the family boundaries used by this file page: `AlertPane` constructor/dismiss `0x0049feb0-0x004a0575` and `0x004a0580-0x004a0686`; `VersatileAlertPane` constructor `0x004a0690-0x004a06d7` with raw cleanup still not an IDA function at `0x004a06e0`; `BlueAlertPane` constructor `0x005008c0-0x00500c24`; `UrlAlertPane` constructor `0x00599a40-0x00599b19`; and shared scalar destructor `0x0048c550-0x0048c58b`. It also reconfirmed primary/secondary/tertiary vtable stores for AlertPane (`0x0049ff1e`, `0x0049ff24`, `0x0049ff2e`), Versatile (`0x004a06b6`, `0x004a06bc`, `0x004a06c6`), Blue (`0x00500920`, `0x00500926`, `0x00500930`), and Url (`0x00599aac`, `0x00599ab2`, `0x00599abc`), plus broad `AlertPane::AlertPane` constructor fan-in and Url constructor callers `0x00503034`, `0x00513f7e`, and `0x0051402f`.
- 2026-06-17 B002 source-quality recheck resolves the base `AlertPane` class declaration under this file: `DismissDialog(int buttonId, int unused)`, no-argument `OnPrimaryButton` / `OnSecondaryButton` slots, `m_layoutReference` at `+0x26c`, and compiler-wrapper policy for the shared scalar destructor and vtable data. The file score stays unchanged because broader `BlueAlertPane` reachability and original filename confidence still cap the source-file page.
- Evidence-time 2026-06-21 B005 source-quality incorporation recorded declaration-ready support form under this file: constructor arguments forward message/layout/primary/secondary text to `AlertPane`, store the non-forwarded `FunctionObjectT<unsigned long>*` result callback at `+0x270`, and override `OnPrimaryButton` / `OnSecondaryButton` to report `1/0`. At that time the exact callback member spelling remained coordinated with `FunctionObjects`; current UID0001WQ support resolves it to `Invoke` without moving the class to `FunctionObjects` or either feature consumer.
- 2026-06-25 B008 implementation callback confirms source placement for the raw cleanup remains this `AlertPanes.cpp`/`AlertPanes.h` family through [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md). Current MCP/PE checks still find no entry route to [UID:00012Y][0x004a06e0-0x004a0715.VersatileAlertPaneDestructor](by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneDestructor.md), but the body writes `VersatileAlertPane` vtables, releases `m_resultCallback`, and jumps to shared alert/DialogPane teardown. Treat it as class lifecycle evidence for one coordinated `VersatileAlertPane` destructor source shape, not a standalone source helper, not `ModelessDialogPane`, not direct `AlertPane`, and not `FunctionObjects` ownership.
- 2026-06-30 B011 empty-emitter implementation keeps this file root at `85/88` and converts the 16 current empty generated markers in `NexusTK/ui/dialogs/AlertPanes.cpp` into formal source-disposition comments. The current generated file observed by the accepted report had 22 child UID markers, 6 already filled emitters, and 16 empty markers; the supervisor queue row's `23/6/17` count is tracker drift and must be refreshed by validator tooling rather than manual edits. The comments preserve existing class source where evidence is ready (`AlertPane`, `VersatileAlertPane`, `UrlAlertPane`) while keeping compiler vtables, scalar deleting wrappers, adjustor thunks, the no-entry Versatile cleanup body, the pooled `L"OK"` literal, and the cross-family layout audit out of handwritten source.
- 2026-07-14 B002 method-island callback places the exact `VersatileAlertPane` class declaration and four source methods in `AlertPanes.h`/`AlertPanes.cpp`: UID0004NB constructor, UID00012Y ordinary destructor, UID0004NC primary handler, and UID0004ND secondary handler. UID00012X is now a non-emitting semantic index. Compiler-adjusted destructor entries, scalar deleting wrapper, three vtable views, and layout bytes remain compiler/ABI evidence reserved to B004's coordinated phase and are not handwritten here.
- 2026-06-21 B011 source-quality incorporation resolves the URL alert class under this file at method-body draft level: constructor signature `UrlAlertPane(bool exitAfterOpen, Pane *layoutReference, const wchar_t *messageText, const char *urlText, unsigned int urlLength)`, `m_url` at `+0x270`, `m_exitAfterOpen` at `+0x274`, `OnPrimaryButton()` as the formal inherited callback name, `ShellExecuteA` plus optional `Application::RequestExit`, `g_pUrlAlertPane` declaration route, and no-code treatment for the constructor-unwind clear helper, adjustor thunks, and scalar deleting destructor wrapper. The file score stays unchanged because broader `BlueAlertPane` reachability and exact original file naming still cap the file page.

## Ownership Notes

- `AlertPane` has broad constructor fan-in from login, patch, board/mail, item/menu, terminal, reconnect, and in-game command flows. That fan-in supports a reusable dialog source instead of feature ownership.
- `VersatileAlertPane` direct constructor xrefs were observed from `0x005301de` and `0x0058b5c5`, consistent with callback-backed generic prompts.
- 2026-07-14 B002 callback resolves `VersatileAlertPane::m_resultCallback` as an owned `FunctionObjectT<unsigned long> *` at `+0x270`. Vtable-only primary/secondary entry points invoke `Invoke(1)`/`Invoke(0)` after a null check, and the ordinary destructor deletes that object exactly once. Raw vptr reset/base teardown, adjustor thunks, and scalar deleting behavior remain compiler consequences rather than duplicate handwritten helper bodies.
- `BlueAlertPane` currently has no direct constructor or custom-virtual code xrefs in IDA. Its vtables and virtual drawing methods are still real, but live reachability and exact feature owner remain open. The recovered `g_uiTileRenderer` alias is now explicitly ignored in [UID:0000PF][-ignored](by-global/-ignored.md).
- 2026-06-30 B011 re-audit keeps `BlueAlertPane` structurally real but no-code: IDA confirms constructor `0x005008c0-0x00500c24`, action/draw methods, vtable stores at `0x00500920`, `0x00500926`, and `0x00500930`, shared alert-family destructor thunks, `BDFRAME.EPF` frame drawing, and `m_layoutReference` at `+0x26c`; it still finds no direct constructor/allocation route and does not prove final base-class spelling, inherited DialogPane/list field names, render helper names, or a safe declaration shell with `[[CHILDREN]]`.
- `UrlAlertPane` constructor xrefs from `0x00503034` and `0x00513f7e`/`0x0051402f` show it as a small shared URL prompt rather than browser implementation code. The `0x00503034` call site is inside [UID:00022Y][0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers](by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md); the other two are in-game/MapPane opcode `0x66` analogs.
- The MainMenu and MapPane packet helpers remain with their owning UI/network files: they parse opcode `0x66`, build URL/text payloads, and construct `UrlAlertPane`; this file owns the reusable alert class, singleton declaration, method bodies, and compiler-emitted vtable declarations.
- `Browser` ownership is rejected because `UrlAlertPane` only calls `ShellExecuteA` on an owned ANSI URL and has no browser-dialog or COM/OLE state. `Application` ownership is rejected because `RequestExit` is only an optional callee after URL launch.
- Direct `FunctionObjects`, `ModelessDialogPane`, feature module, raw `.rdata` aggregate, Blue class-shell, standalone raw-cleanup helper, raw vtable array, scalar deleting wrapper body, and feature-owned `OK` global/table alternatives remain rejected after the B011 pass. Those pages now carry no-code markers explaining the exact source route or compiler/generated-data reason.
- The `0x004a0760-0x004a0c8e` neighborhood between `VersatileAlertPane` callbacks and destructor is [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md) / modeless-dialog event code. Do not pull it into this file solely because it sits between alert-related functions in memory.
- [UID:0000IH][CopyWindow](by-file/CopyWindow.md) derives from `AlertPane`, but remains feature-specific rather than part of reusable `AlertPanes.cpp`. Current evidence places the complete private file-local [UID:000039][CopyWindow](by-class/CopyWindow.md) class in `network/ReconnectDialog.cpp`, before [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md): that reconnect helper is the sole live construction context, the active [UID:0000ON][TextEditPane](by-file/TextEditPane.md) pointer is a dependency rather than an owner, and no external complete-type consumer requires a standalone header or translation unit.
- The former dedicated `CopyWindow.cpp` theory and proposed-tree separation are preserved only as superseded history. They were plausible from the retained out-of-line constructor/callback island and feature-specific state, but the live same-unit inline construction, accepted owner/emitter chain, source order, and generated ReconnectDialog closure now outweigh address clustering and reject both standalone CopyWindow and AlertPanes ownership.

## Migration Notes

When validator/project-structure tooling is available, this file remains a candidate for:

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
- [UID:0002P0][0x0062e580-0x0062e624.UrlAlertPaneVtableData](by-memory/0x0062e580-0x0062e624.UrlAlertPaneVtableData.md)
- [UID:00026S][0x0062e578-0x0062e624.UniApiUrlAlertReadOnlyData](by-memory/0x0062e578-0x0062e624.UniApiUrlAlertReadOnlyData.md)
- [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md)
- [UID:00010V][0x0048c315-0x0048c32b.AlertPaneAdjustorThunks](by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md)
- [UID:00012X][0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland](by-memory/0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland.md)
- [UID:00012Y][0x004a06e0-0x004a0715.VersatileAlertPaneDestructor](by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneDestructor.md)
- [UID:0004NB][0x004a0690-0x004a06d7.VersatileAlertPaneConstructor](by-memory/0x004a0690-0x004a06d7.VersatileAlertPaneConstructor.md)
- [UID:0004NC][0x004a0720-0x004a0732.VersatileAlertPaneOnPrimaryButton](by-memory/0x004a0720-0x004a0732.VersatileAlertPaneOnPrimaryButton.md)
- [UID:0004ND][0x004a0740-0x004a0752.VersatileAlertPaneOnSecondaryButton](by-memory/0x004a0740-0x004a0752.VersatileAlertPaneOnSecondaryButton.md)
- [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md)
- [UID:00012Z][0x004a0760-0x004a0c8e.ModelessDialogPane](by-memory/0x004a0760-0x004a0c8e.ModelessDialogPane.md)
- [UID:000130][0x004a0cb0-0x004a0d37.VersatileAlertPaneDeletingDestructorAbiIsland](by-memory/0x004a0cb0-0x004a0d37.VersatileAlertPaneDeletingDestructorAbiIsland.md)
- [UID:0001A5][0x005008c0-0x0050114d.BlueAlertPaneCore](by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md)
- [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md)
- [UID:00022Y][0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers](by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md)
- [UID:0001R5][alert-dialog-resources](by-resource/alert-dialog-resources.md)
- [UID:0000SV][g_uiTileRenderer](by-global/g_uiTileRenderer.md)
- [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md)
- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)

## Score Rationale

- Completion `85`: the page covers the shared alert source root, core class family, exact `BlueAlertPane` and `UrlAlertPane` vtable-data children, shared destructor and adjustor-thunk evidence, layout offsets, constructor fan-in, feature-specific alert exclusions, the exact four-method `VersatileAlertPane` source route, the family layout parent gate, and current declaration/method-body readiness for `AlertPane`, `VersatileAlertPane`, and `UrlAlertPane`. It remains below the final-source range because `BlueAlertPane` live reachability, exact original filename, and final whole-file source shape still need more audit.
- Confidence `88`: strong for `AlertPane`, `VersatileAlertPane`, `UrlAlertPane`, source folder, class-family grouping, vtable/layout evidence, and family-level parent readiness; still below final-source confidence because the broader file hypothesis includes the less-settled `BlueAlertPane` placement and shared-module filename question.

## 2026-07-29 Supervisor Gate 2B Reconciliation (Catalog 0353)

- The shared AlertPane constructor at `0x0049feb0` now has the verified analysis identity `AlertPane__AlertPane` and prototype `AlertPane *__thiscall(AlertPane *this, const wchar_t *messageText, Pane *layoutReference, const wchar_t *primaryButtonText, const wchar_t *secondaryButtonText)`. `layoutReference` is the stored pane reference; ownership is not proven.
- Existing frame argument slots were normalized in place to `messageText +0xb0/4`, `layoutReference +0xb4/4`, `primaryButtonText +0xb8/4`, and `secondaryButtonText +0xbc/4`. All nonargument storage, offsets, and widths remain unchanged. Only the accepted repeatable function comment is populated; address channels and the regular function-comment channel remain blank.
- The former raw constructor identity is historical prestate/search provenance only. No source ownership, file placement, byte range, caller, or AlertPane data-layout decision changed.
- Persistence checkpoint: prestate IDB SHA256 `FD8282A51836D47961EA386D7C2D25F80D0BF88B96ACFF106FFA802277F78B16`; byte-identical backup `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B010-UID0003MQ-20260729-082218.i64`; saved IDB SHA256 `6D20767D448CC568508E462790D05678838216C6CFEE77E3CFF5C4B5905244AB`, `143190049` bytes, `2026-07-29T08:26:09.5759690-04:00`. Catalog entry `0353` is `APPLIED_VERIFIED_RECONCILIATION_PENDING`; B010 did not mutate IDA.

## Changes

- 2026-07-14 B002 VersatileAlertPane method-island callback:
  - Score and projected source path remain `85/88` and `NexusTK/ui/dialogs/` because broader file-family caps are unchanged.
  - Added real method-child UIDs and exact `AlertPanes.h`/`AlertPanes.cpp` placement for constructor, ordinary destructor, primary handler, and secondary handler; recorded owned `FunctionObjectT<unsigned long>` field/call/delete behavior and the non-emitting UID00012X index.
  - Preserved B004 ownership of compiler destructor ABI, vtable, and layout support and added no reconstruction metadata to this by-file root.

- What existed before: the page had strong grouping, vtable, layout, and migration evidence but remained scored as unevaluated.
- What it was changed to: scores were set to `78/85`, and the exact `BlueAlertPane` vtable-data child range [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md) was added.
- Summary and evidence: shared alert ownership is strongly supported by IDA fan-in, vtables, exact child vtable-data ranges, and shared destructor evidence; exact original filename and `BlueAlertPane` live reachability remain the main confidence limits.
- 2026-05-31: Assigned validator reconstruction path.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - After: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`.
  - Evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `AlertPanes.cpp` under `ui/dialogs`; the page's IDA evidence groups `AlertPane`, `VersatileAlertPane`, `BlueAlertPane`, and `UrlAlertPane` as shared dialog infrastructure.
- 2026-06-06: Replaced stale recovered-source/tool provenance wording without changing score or path.
  - Before: status, vtable caveats, ownership notes, and migration notes still leaned on older recovered-source labels and tool-specific metadata wording.
  - After: kept `78/85` and `NexusTK/ui/dialogs/`, but made IDA-backed class/type/global/memory docs the explicit evidence basis and removed obsolete source/tool edit guidance.
  - Evidence: the existing IDA fan-in, vtable, layout, raw-disassembly, exact child vtable-data, and shared destructor documentation still supports the same shared `AlertPanes.cpp` hypothesis.
- 2026-06-07: Raised the file page from `78/85` to `82/86` and recorded parent-gate readiness.
  - Before: the page had enough shared alert evidence to justify the source root, but its score kept `UrlAlertPane` children unattached even though their exact executable and vtable-data pages were stronger.
  - After: the page now records the `UrlAlertPane` executable, exact vtable-data child, mixed-owner read-only aggregate boundary, and MainMenu packet-adapter separation, making `AlertPanes.cpp` a valid parent for independently strong URL-alert child pages.
  - Evidence: [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md), [UID:0002P0][0x0062e580-0x0062e624.UrlAlertPaneVtableData](by-memory/0x0062e580-0x0062e624.UrlAlertPaneVtableData.md), [UID:00026S][0x0062e578-0x0062e624.UniApiUrlAlertReadOnlyData](by-memory/0x0062e578-0x0062e624.UniApiUrlAlertReadOnlyData.md), and [UID:00022Y][0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers](by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md) separate reusable alert implementation from packet parsing and platform/API read-only data.
- 2026-06-11 A003 supervisor-row pass:
  - Before: `82/86`, enough for the older parent gate but below the current strict 85/85 gate for the shared layout page.
  - After: `85/88`, projected path unchanged.
  - Evidence: live IDA reconfirmed alert-family function bounds, vtable-store refs, raw Versatile cleanup non-function status, shared destructor, broad `AlertPane` constructor fan-in, Url constructor callers, and the [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md) family layout now attached to this shared file root.
- 2026-06-17 B002 VersatileAlertPane callback refresh:
  - Score unchanged at `85/88`.
  - Clarified `m_resultCallback`, the shared unsigned-long `FunctionObject` callback direction, accept/cancel result values, vtable-only reachability, and the one-destructor final-C++ policy for [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md).
- 2026-06-17 B002 AlertPane source-quality execution:
  - Score unchanged at `85/88`.
  - Clarified base `AlertPane` constructor/dismiss signatures, no-argument primary/secondary callback slots, `m_layoutReference`, shared scalar-destructor/thunk compiler policy, and declaration-only class C++ readiness on [UID:00000B][AlertPane](by-class/AlertPane.md).
- 2026-06-21 B005 VersatileAlertPane vtable-data Rule 26 incorporation:
  - Score unchanged at `85/88`.
  - Added that `VersatileAlertPane` should use `OnPrimaryButton` / `OnSecondaryButton` in class source to match the base `AlertPane` declaration, while [UID:0002P1][0x00618ba0-0x00618c44.VersatileAlertPaneVtableData](by-memory/0x00618ba0-0x00618c44.VersatileAlertPaneVtableData.md) remains compiler-generated vtable/RTTI data regenerated from the class declaration and executable method bodies.
- 2026-06-21 B011 UrlAlertPane source-quality incorporation:
  - Score unchanged at `85/88`.
  - Added current method-body draft readiness for [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md), declaration route for [UID:0000SM][g_pUrlAlertPane](by-global/g_pUrlAlertPane.md), inherited `OnPrimaryButton` callback naming, `m_url`/`m_exitAfterOpen` field directions, packet caller separation, and no-code compiler-glue policy for [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md).
- 2026-06-25 B008 implementation callback:
  - Score and projected source path unchanged.
  - Added that [UID:00012Y][0x004a06e0-0x004a0715.VersatileAlertPaneDestructor](by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneDestructor.md) remains `VersatileAlertPane` lifecycle evidence under this `AlertPanes` source family, with no standalone helper/source-method route and no `ModelessDialogPane`/direct `AlertPane`/`FunctionObjects` ownership.
- 2026-06-30 B011 empty-emitter-family implementation:
  - Score and projected source path unchanged at `85/88` and `NexusTK/ui/dialogs/`.
  - Added formal no-code/source-disposition comments for the 16 current empty generated markers reported for `auto-generated/NexusTK/ui/dialogs/AlertPanes.cpp`: shared `AlertPane` destructor glue, `AlertPane` core/vtables, `VersatileAlertPane` callback/destructor/vtable support, `BlueAlertPane` class/core/vtable support, `UrlAlertPane` vtable support, the pooled `L"OK"` literal, and the cross-family layout audit.
  - Preserved the cap on the file score because this pass does not recover `BlueAlertPane` live construction/allocation, prove exact original filename/header split, or supply a final whole-file source body plan.
