** TARGET-REPORT-UID:0001J7 **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0001J7] ForcedInformMessageDialogCore Source-Quality Report

Agent: B008  
Assignment: `B008-report-0001J7-ForcedInformMessageDialogCore-source-quality-20260627`  
Target: `by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md`  
Report path: `tools/leaser/Agents/Agent-B008/research/0001J7-ForcedInformMessageDialogCore-source-quality.md`

## Supervisor Amendment Summary

This amendment supersedes the earlier no-code recommendation. Current-scope Rule 26 investigation now resolves the constructor attachment parameters, helper signatures, callback reachability, and aggregate disposition far enough for implementation.

Implementation-ready decision:

- Convert [UID:0001J7] into a reviewed non-emitting split container for the physical `0x00587bb0-0x005881ed` island.
- Create four exact source-bearing child method pages under [UID:0000JJ] / [UID:00005E]: constructor `0x00587bb0-0x00588073`, non-deleting destructor `0x00588080-0x00588101`, button callback `0x00588110-0x0058815d`, and key callback `0x00588160-0x005881ed`.
- Populate formal first-draft C++ on those child pages. Keep the parent aggregate C++ block blank because the parent becomes a non-emitting split index.
- Reclassify [UID:0001JA] `0x0058abf0-0x0058acb2` as compiler-generated scalar deleting destructor support after the ordinary destructor child owns the source destructor body.

The valid MCP boundary, vtable, singleton, resource, and source-facing mapping evidence below is preserved. The amended implementation plan at the end of this report is the authoritative action list.

## Scope And Constraints

This is a report-first pass. I did not take leases, did not edit target/support by-* documentation, did not edit generated outputs, did not edit validator/tool state, did not touch IDA DB state, and did not spawn subagents.

I checked the required target and support set:

- `by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md`
- `by-file/ForcedInformMessageDialog.md`
- `by-class/ForcedInformMessageDialog.md`
- `by-memory/0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear.md`
- `by-memory/0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks.md`
- `by-memory/0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor.md`
- `by-memory/0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog.md`
- `by-memory/0x0062d714-0x0062d7b0.ForcedInformMessageDialogVtableData.md`

I also checked related support pages for current source-facing names: `by-global/g_pForcedInformMessageDialog.md`, `by-global/g_useEpfAssets.md`, `by-global/g_pMainUiGraph.md`, `by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md`, `by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md`, `by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md`, `by-memory/0x0049db60-0x0049dc05.DialogPaneSetBackgroundResource.md`, `by-memory/0x0049dc10-0x0049dc93.DialogPaneEnsureControlManagerAndAdd.md`, `by-memory/0x0049eac0-0x0049f07e.DialogPaneSlideAnimation.md`, `by-class/DialogPane.md`, `by-file/TextEditPane.md`, `by-file/TextEditControlPane.md`, `by-memory/0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane.md`, and `by-memory/0x00595390-0x005954b3.TextBoxPaneConstructor.md`.

## Current Target State

Current target metadata is:

- `COMPLETION:86`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000JJ`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000JJ`
- formal `RECONSTRUCTION_CPP CODE` block is blank

The owner/emitter route is valid. [UID:0000JJ] `ForcedInformMessageDialog` remains the source file, and [UID:00005E] `ForcedInformMessageDialog` remains the class context. The target is a coherent four-method class-core cluster:

- `0x00587bb0-0x00588073`: constructor/setup path
- `0x00588080-0x00588101`: ordinary/non-deleting destructor
- `0x00588110-0x0058815d`: button response callback
- `0x00588160-0x005881ed`: secondary-view key callback

The generated `auto-generated/NexusTK/login/ForcedInformMessageDialog.cpp` currently contains only empty emitter markers for this file/class/global/core set. Its [UID:0001J7] marker still shows stale `82/84` metadata even though the target page is `86/88`; that is a generated-output refresh issue for the later implementation/validator batch, not a report-pass edit.

The tracker row in `auto-generated/-ag-research-tracker.md` is also stale at `82/84` and `Reports 0`. This report is the missing B-agent source-quality report for the row.

## Live IDA MCP Provenance

Mandatory MCP evidence was available and used. I started from `idb_list` and used the active session:

- session: `b001_000241_20260627`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- active: `true`
- backend: `worker`
- `server_health`: `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready

Successful read-only MCP calls used in this report include:

- `server_health`
- `lookup_funcs`
- `analyze_component`
- `analyze_function`
- `callees`
- `xrefs_to`
- `decompile`
- `entity_query`
- `get_bytes`

One broad `search_text` attempt for the constructor symbol timed out. I did not use that timed-out query as evidence. A follow-up `idb_list` and `server_health` check immediately after the timeout still reported the same active healthy session.

## Live Boundary Evidence

Current `lookup_funcs` reconfirms the exact executable boundaries:

| Address | IDA name | Size | Disposition |
| --- | --- | ---: | --- |
| `0x00587bb0` | `sub_587BB0` | `0x4c3` | constructor/setup |
| `0x00588080` | `sub_588080` | `0x81` | ordinary destructor |
| `0x00588110` | `sub_588110` | `0x4d` | button callback |
| `0x00588160` | `sub_588160` | `0x8d` | secondary-view key callback |
| `0x005881ed` | none | not a function | exclusive end confirmed |
| `0x0058aa90` | `sub_58AA90` | `0xb` | singleton-clear EH/helper support |
| `0x0058aadb` | `sub_58AADB` | `0xb` | secondary destructor adjustor thunk |
| `0x0058aae6` | `sub_58AAE6` | `0xb` | tertiary destructor adjustor thunk |
| `0x0058abf0` | `sub_58ABF0` | `0xc2` | scalar deleting destructor |
| `0x0058acb2` | none | not a function | scalar destructor exclusive end confirmed |

Current helper lookups also match the support pages:

- `0x0049db60` `sub_49DB60`, size `0xa5`
- `0x0049dc10` `sub_49DC10`, size `0x83`
- `0x0049eac0` `sub_49EAC0`, size `0xcd`
- `0x0058fc30` `sub_58FC30`, size `0x263`

## Behavior Evidence

`decompile(0x00587bb0)` confirms the constructor signature currently recovered by Hex-Rays as:

- `int __thiscall sub_587BB0(int this, const unsigned __int16 *a2, int a3, _DWORD *a4)`

Source-facing interpretation:

- `a2` is the message text.
- `a3` and `a4` are dialog creation/attachment context values passed through `DialogPane` create/show helpers; exact public names/types remain unproven because no constructor call site is recovered.

Constructor evidence:

- calls `DialogPane` base setup at `0x0049d8a0`;
- publishes or clears `g_pForcedInformMessageDialog` at `0x00587c17` / `0x00587c1e`;
- installs three `ForcedInformMessageDialog` vtable views at `this+0`, `this+0xa0`, and `this+0xa4`;
- branches on `g_useEpfAssets` (`byte_66DA97 == 1`);
- EPF path builds `DLGSTAFF.EPF` / `DLGSTAFF.PAL`, a `318x456` dialog, text bounds `(25,56)-(300,391)`, button id `14`, button id `22`, centered screen bounds, and shows via DialogPane slide/open path;
- EPD path builds `DLGSTAFF.EPD`, a `267x367` dialog, text bounds `(39,70)-(230,306)`, fixed bounds `(363,100)-(630,467)`, and shows via the same base dialog open path;
- both paths insert the incoming UTF-16 text into the embedded editor via `0x0058fc30` with `wcslen(a2)`;
- both paths clear/select the editor at `(0,0)` through `0x0058f2a0`;
- both paths notify `g_pScreenDimmer` if it is present.

Destructor/callback evidence:

- `decompile(0x00588080)` reinstalls all three vtables, checks `g_useEpfAssets == 1`, `m_bAccepted`, and `g_pMainUiGraph`, calls `EnsureLoginDialogPane`, clears `g_pForcedInformMessageDialog`, then chains the inherited DialogPane cleanup despite IDA's polluted `boost::exception` label.
- `decompile(0x00588110)` maps action `2` to accept (`m_bAccepted = 1`, slide-close, close dialog) and action `3` to decline (`m_bAccepted = 0`, slide-close, close dialog, `g_pApplication->RequestExit()`).
- `decompile(0x00588160)` handles event kind `8`, accepts `A/a`, declines `D/d`, adjusts from secondary view by `0xa0`, and returns handled.
- `decompile(0x0058abf0)` confirms the scalar deleting destructor has the same login-restore and singleton-clear behavior plus conditional operator delete wrapper.

## Reachability Resolution

Direct constructor callers remain absent in the current active IDB, but that absence is now bounded and no longer blocks formal constructor C++.

Negative constructor-callsite evidence from current MCP:

- `xref_query(0x00587bb0, direction=to, xref_type=code)` returns zero refs.
- `xref_query(0x00587bb0, direction=both)` returns only the function's own fallthrough xref `0x00587bb0 -> 0x00587bb1`, not an incoming caller.
- `analyze_function(0x00587bb0)` reports `callers=0`.
- `find_bytes` over the current IDB for VA/RVA byte patterns `B0 7B 58 00`, `B0 7B 18 00`, `B0 7B 58`, and `B0 7B 18` returns zero matches.
- A broad immediate scan attempted earlier timed out / truncated and is not used as complete proof. It is only supplemental; the reliable negative evidence is the xref and byte-pattern result above.

Constructor identity is still strong: vtable stores, singleton publication, `DLGSTAFF.*` resources, destructor pair, resource support pages, class page, and vtable data all agree. The no-caller state should be documented as a reachability caveat, not as a source-quality blocker.

`a3` and `a4` are resolved by callee semantics and DialogPane support docs:

- `sub_49DFD0` decompiles as `DialogPane::OnCreate(const RectBounds *bounds, int zOrder, Pane *parentPane, Layer *layer)`. It calls `sub_544C70(this, bounds, zOrder, parentPane, layer)` and then attaches child controls using the same layer argument.
- `sub_544C70` uses `parentPane + 0xa8` when the parent is non-null and otherwise uses the explicit layer pointer, then calls the lower pane attach helper. This proves the fourth and fifth raw arguments are parent pane and layer context.
- `sub_49E190` decompiles through `sub_544D30` and `sub_4A6FC0` as `DialogPane::OnShow(Pane *afterPane, Pane *beforePane)`. The target calls `OnShow(NULL, parentPane)`.
- Comparable dialog constructors either pass `0, g_rootLayer` or a root/main UI pane to the same helpers. ForcedInform is the variant that forwards caller-provided attachment context.

Source-facing constructor signature to use:

```cpp
ForcedInformMessageDialog::ForcedInformMessageDialog(const wchar_t *messageText,
                                                     Pane *parentPane,
                                                     Layer *layer)
```

Callback reachability is resolved:

- `xref_query(0x00588110)` returns the vtable data ref `0x0062d760 -> 0x00588110` for `OnButtonResponse`.
- `xref_query(0x00588160)` returns the vtable data ref `0x0062d780 -> 0x00588160` for the secondary-view key callback.
- `xref_query(0x0058abf0)` returns thunk code refs `0x0058aae1` and `0x0058aaec` plus the primary vtable data ref `0x0062d718`.
- `xrefs_to(0x0062d718)`, `0x0062d778`, and `0x0062d7a8` each show constructor/destructor/scalar-destructor stores at the expected `ForcedInformMessageDialog` offsets.

This satisfies current-scope reachability investigation: no direct constructor caller is recovered, but the source parameter plan is supported by the live callee semantics and existing DialogPane patterns.

## Data And Resource Evidence

Current `xrefs_to(0x0069b4a0)` returns exactly six refs:

- `0x004f69ec` in `sub_4F69A0`
- `0x00587c17` in the constructor
- `0x00587c1e` in the constructor fallback
- `0x005880e2` in the ordinary destructor
- `0x0058aa90` in the clear helper
- `0x0058ac59` in the scalar deleting destructor

Current `xrefs_to(0x0069ae08)` returns 40 refs overall, with this target's constructor refs at:

- `0x00587eb2`
- `0x00588043`

Current resource string refs:

- `DLGSTAFF.PAL` at `0x0062d9a0`: constructor ref `0x00587c85`
- `DLGSTAFF.EPF` at `0x0062d9bc`: constructor refs `0x00587c92`, `0x00587e1b`
- `DLGSTAFF.EPD` at `0x0062d9d8`: constructor refs `0x00587f04`, `0x00587fe5`

Current `get_bytes(0x0062d9a0, size 84)` returns the expected UTF-16 sequence for `DLGSTAFF.PAL`, `DLGSTAFF.EPF`, and `DLGSTAFF.EPD` with alignment. `get_bytes(0x0062d714, size 156)` returns the vtable/COL bytes covering the primary, secondary, and tertiary views.

Current active-IDB `get_bytes` returns zero bytes for `0x0069b4a0` and `0x0069ae08`. Some older support pages still describe `0xffffffff` static values for these singleton slots. That initializer wording should be reconciled during implementation if those support pages are touched; it does not change this target's lifecycle/name evidence.

## Source-Facing Name Resolutions

The raw helper/global label blocker is resolved to implementation-ready source-facing names or explicit support-owned role aliases. Use these names in target/support updates:

| Raw IDA label | Source-facing name to use | Evidence |
| --- | --- | --- |
| `sub_49DC10` | `DialogPane::AddControl(...)` / `DialogPaneEnsureControlManagerAndAdd` | [UID:0003KH] documents lazy control-manager allocation and add dispatch; constructor calls it after each control allocation. |
| `sub_49DB60` | `DialogPane::SetBackgroundResource(...)` | [UID:0003KG] documents background/resource state setup; constructor calls it with `DLGSTAFF.EPF` or `DLGSTAFF.EPD`. |
| `sub_49DFD0` | `DialogPane::OnCreate(const RectBounds *bounds, int zOrder, Pane *parentPane, Layer *layer)` | DialogPane class declaration already uses this signature; live decompile shows parent/layer forwarding through `sub_544C70`. |
| `sub_49E190` | `DialogPane::OnShow(Pane *afterPane, Pane *beforePane)` | DialogPane class declaration already uses this signature; live decompile shows secondary-view modal registration and calls with `NULL, parentPane`. |
| `sub_49EAC0` | `DialogPane::SlideOpenVertical()` | [UID:00012U] and `DialogPane` class declaration name the vertical open helper; constructor calls it in both modes. |
| `sub_49EB90` | `DialogPane::SlideCloseVertical()` | [UID:00012U] and class declaration name the vertical close helper; button/key callbacks call it before close. |
| `sub_49DAD0` | `DialogPane::CloseDialog()` / close/delete mark path | `DialogPane` class declaration names `CloseDialog`; callbacks call it after slide-close. |
| `sub_49FC00` | `DialogPane::SetHoverControl(int controlId)` / active-control id setter | NewArticle and NewPredefined support docs use `SetHoverControl` for this inherited forwarder; live decompile writes `m_activeControlId` at `+0x214`. |
| `sub_49DD80` | `DialogPane::SetFocusedControl(int controlId)` | DialogPane class declaration and helper inventory name the focus-control setter; target passes `2`. |
| `sub_49DDD0` | `DialogPane::SetPendingControl(int controlId)` | DialogPane class declaration and helper inventory name the pending-control setter; target passes `3`. |
| `sub_5446B0` | `Pane::SetMode(unsigned char mode)` | [UID:0002V7] now carries formal C++ and proves the `+0xb5` mode-byte setter; target calls `SetMode(1)`, and the text wrapper child receives mode `0` through its own state path. |
| `sub_58FC30` | `TextEditPane::SetText(const wchar_t *text, short length, ..., ...)` | TextEditPane core docs and accepted TextBoxPane source use `SetText(initialText, (short)wcslen(initialText), 0, 0)`. |
| `sub_58F2A0` | `TextEditPane::SetSelectionRange(short start, short end)` | Current decompile clamps endpoints and writes the selection fields; the MusicControlDialog folder-path report already uses `SetSelectionRange(0,0)` for this helper. |
| `sub_498920` | `TextEditControlPane::TextEditControlPane(...)` | TextEditControlPane docs cover the full constructor, embedded `TextEditPane *` at `+0x10c`, max length/line setup, and optional initial text. Target code may use the existing project-facing constructor plus setter calls. |
| `sub_498BE0` / `sub_498BD0` | `TextEditControlPane::SetMaxLines(...)` / `SetMaxLength(...)` | TextEditControlPane/TextEditPane docs and existing first-draft C++ use these limits; target values are `2000` and `30000`. |
| `sub_498C00` | `TextEditControlPane::SetEditActiveState(bool, bool)` role alias | ExchangeMoneyEditControlPane support proves this is a TextEditControlPane embedded-editor state forwarder; target passes `false, false`. If the class declaration lacks the exact method, add a support note rather than leaving a raw label. |
| `sub_4991F0` | `EPFImageControlPane` resource image constructor | Live decompile proves raw order `(resourceName, frameIndex, enabled, bounds, paletteName)` and current class support covers resource/palette/frame fields. Target can use the project-facing `EPFImageControlPane(MakeRect(...), frameIndex, resource, palette)` overload used by other first-draft dialog code. |
| `sub_495BF0` | `ImageButtonControlPane` constructor | Live decompile proves raw order `(buttonImageId, bounds)` and class/file support proves the generic image-button constructor; project-facing code uses `ImageButtonControlPane(MakeRect(...), imageId)`. |
| `byte_66DA97` | `g_useEpfAssets` | [UID:0000SW] names the EPF/current vs EPD/legacy mode selector; current `get_bytes(0x0066da97)` returns `0x01`. |
| `unk_69AE08` | `g_pScreenDimmer` | [UID:00029D] and [UID:0000S5] name the modal screen-dimmer singleton; constructor notifies it when present. |
| `unk_69B4A0` / `dword_69B4A0` | `g_pForcedInformMessageDialog` | [UID:0001PW]/[UID:0000QY] document exact singleton lifecycle refs. |
| `unk_67ABA4` | `g_pMainUiGraph` | [UID:0000RF] documents the main UI graph/root pointer used by the login restore guard. |
| `*((_BYTE *)this + 620)` / `+0x26c` | `m_bAccepted` | Constructor defaults true; accept/decline handlers write it; destructors test it before login restoration. |
| `unk_67AB1C` | `g_pApplication` | [UID:000294] emits `Application *g_pApplication = NULL;`; decline path calls request-exit through it. |
| `sub_464E40` | `Application::RequestExit()` | [UID:0002H3] documents the source-facing Application request-exit method. |

Remaining naming caps do not block implementation:

- The direct constructor caller is absent, but `parentPane` and `layer` are inferred from `OnCreate`/`OnShow` callee semantics and sibling DialogPane constructor patterns.
- `ScreenDimmer::SetDimmed(true)` is a role-level source alias for the virtual singleton call. If the ScreenDimmer class page lacks that exact method spelling, add a support note during implementation.
- Exact original spellings for globals and some UI helper methods remain reconstructed names, but these are already project-accepted source-facing names and should replace raw labels.

## Ownership And Placement Analysis

Source ownership remains [UID:0000JJ] / [UID:00005E], but [UID:0001J7] itself should not remain the emitting method body. The aggregate spans four exact methods, and live byte evidence proves clean `0xcc` padding between them:

- `0x00588073-0x00588080`: 13 bytes of `0xcc` after the constructor.
- `0x00588101-0x00588110`: 15 bytes of `0xcc` after the ordinary destructor.
- `0x0058815d-0x00588160`: 3 bytes of `0xcc` after the button callback.
- `0x005881ed-0x005881f0`: 3 bytes of `0xcc` before the next function prologue.

Recommended [UID:0001J7] parent metadata after implementation:

- `COMPLETION:90`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:FALSE`
- `EMITTER_UIDS:` blank

Reason: the parent becomes a reviewed non-emitting split container. This avoids duplicate C++ emission while exact child pages carry the reconstructable method bodies through [UID:0000JJ].

Rejected ownership alternatives:

- `DialogPane`: provides base helpers and animation only; it does not own `DLGSTAFF.*`, button ids `14/22`, or the `ForcedInformMessageDialog` singleton.
- `TextEditControlPane` / `TextEditPane`: provide the embedded editor and text mutation helper only.
- `ScreenDimmer`, `Application`, or `MainUiGraph`: lifecycle consumers/dependencies only.
- `SystemMessagePanes`: physical neighborhood/provenance only. The resource/vtable/singleton/class evidence routes this target to `ForcedInformMessageDialog`, not the surrounding system-message panes.
- no-owner source rejection: too weak for the four methods themselves. Only the physical aggregate parent becomes `CANONICAL_OWNER:NONE`; each child remains owned/emitted through `ForcedInformMessageDialog`.

## Formal C++ Disposition

Do not put behavior-bearing C++ on the parent aggregate. Create exact child pages and populate the following formal `RECONSTRUCTION_CPP CODE` blocks there.

### Child 1: Constructor

Recommended page:

- `by-memory/0x00587bb0-0x00588073.ForcedInformMessageDialogConstructor.md`
- `COMPLETION:89`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:00005E`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000JJ`

Exact formal C++ insertion text:

```cpp
namespace {
constexpr int kForcedInformDialogConfigId = 15;
constexpr int kForcedInformAcceptButtonImage = 14;
constexpr int kForcedInformDeclineButtonImage = 22;
constexpr int kForcedInformHoverControl = 2;
constexpr int kForcedInformFocusedControl = 2;
constexpr int kForcedInformPendingControl = 3;
constexpr short kForcedInformMaxLines = 2000;
constexpr short kForcedInformMaxLength = 30000;

void ConfigureForcedInformTextPane(TextEditControlPane *pane, const wchar_t *messageText)
{
    pane->SetMaxLines(kForcedInformMaxLines);
    pane->SetMaxLength(kForcedInformMaxLength);
    pane->SetEditActiveState(false, false);

    TextEditPane *editor = pane->GetTextEditPane();
    editor->SetText(messageText, static_cast<short>(std::wcslen(messageText)), NULL, 0);
    editor->SetSelectionRange(0, 0);
    pane->SetControlVisible(false);
}
} // namespace

ForcedInformMessageDialog::ForcedInformMessageDialog(const wchar_t *messageText,
                                                     Pane *parentPane,
                                                     Layer *layer)
    : DialogPane(L"", kForcedInformDialogConfigId, 1),
      m_bAccepted(true)
{
    g_pForcedInformMessageDialog = this;

    if (g_useEpfAssets == 1) {
        AddControl(new EPFImageControlPane(MakeRect(0, 0, 318, 456),
                                           0,
                                           L"DLGSTAFF.EPF",
                                           L"DLGSTAFF.PAL"));

        TextEditControlPane *messagePane =
            new TextEditControlPane(MakeRect(25, 56, 300, 391), L"");
        AddControl(messagePane);
        ConfigureForcedInformTextPane(messagePane, messageText);

        AddControl(new ImageButtonControlPane(MakeRect(86, 419, 149, 443),
                                              kForcedInformAcceptButtonImage));
        AddControl(new ImageButtonControlPane(MakeRect(163, 419, 226, 443),
                                              kForcedInformDeclineButtonImage));

        SetBackgroundResource(L"DLGSTAFF.EPF", NULL);
        SetMode(1);

        const int left = (g_screenWidth - 318) / 2;
        const int top = (g_screenHeight - 456) / 2;
        RectBounds dialogBounds = MakeRect(left, top, left + 318, top + 456);
        OnCreate(&dialogBounds, 0, parentPane, layer);
        OnShow(NULL, parentPane);
        SetHoverControl(kForcedInformHoverControl);
        SetFocusedControl(kForcedInformFocusedControl);
        SetPendingControl(kForcedInformPendingControl);
        SlideOpenVertical();
    } else {
        AddControl(new EPFImageControlPane(MakeRect(0, 0, 267, 367),
                                           0,
                                           L"DLGSTAFF.EPD",
                                           L"NP"));

        TextEditControlPane *messagePane =
            new TextEditControlPane(MakeRect(39, 70, 230, 306), L"");
        AddControl(messagePane);
        ConfigureForcedInformTextPane(messagePane, messageText);

        SetBackgroundResource(L"DLGSTAFF.EPD", NULL);
        SetMode(1);
        RectBounds dialogBounds = MakeRect(363, 100, 630, 467);
        OnCreate(&dialogBounds, 0, parentPane, layer);
        OnShow(NULL, parentPane);
        SlideOpenVertical();
    }

    if (g_pScreenDimmer != NULL) {
        g_pScreenDimmer->SetDimmed(true);
    }
}
```

Implementation notes for this block:

- `MakeRect(...)` follows existing first-draft dialog source style. If the local helper returns by value, assign to a `RectBounds` local before calling `OnCreate`; do not put raw `sub_4B7C50` calls in source-facing C++.
- The `L"NP"` legacy palette string is live MCP evidence at `0x0061484c` (`aNp`).
- `SetEditActiveState(false, false)`, `SetControlVisible(false)`, and `ScreenDimmer::SetDimmed(true)` are role-level source names. If those exact declarations are missing, add support-page declarations/notes during implementation rather than reverting to raw helper labels.

### Child 2: Non-Deleting Destructor

Recommended page:

- `by-memory/0x00588080-0x00588101.ForcedInformMessageDialogNonDeletingDestructor.md`
- `COMPLETION:89`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:00005E`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000JJ`

Exact formal C++ insertion text:

```cpp
ForcedInformMessageDialog::~ForcedInformMessageDialog()
{
    if (g_useEpfAssets == 1 &&
        m_bAccepted &&
        g_pMainUiGraph != NULL) {
        EnsureLoginDialogPane();
    }

    g_pForcedInformMessageDialog = NULL;
}
```

The source destructor child owns the source-authored teardown behavior. Vtable restores and base `DialogPane` cleanup are compiler/base-destruction output, not explicit C++.

### Child 3: Button Callback

Recommended page:

- `by-memory/0x00588110-0x0058815d.ForcedInformMessageDialogOnButtonResponse.md`
- `COMPLETION:90`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:00005E`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000JJ`

Exact formal C++ insertion text:

```cpp
void ForcedInformMessageDialog::OnButtonResponse(int actionId)
{
    if (actionId == 2) {
        m_bAccepted = true;
        SlideCloseVertical();
        CloseDialog();
        return;
    }

    if (actionId == 3) {
        m_bAccepted = false;
        SlideCloseVertical();
        CloseDialog();
        g_pApplication->RequestExit();
    }
}
```

`2` and `3` are the callback action ids. The constructor's `14` and `22` are image/button resource ids passed to `ImageButtonControlPane`.

### Child 4: Secondary Key Callback

Recommended page:

- `by-memory/0x00588160-0x005881ed.ForcedInformMessageDialogOnKeyInput.md`
- `COMPLETION:89`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:00005E`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000JJ`

Exact formal C++ insertion text:

```cpp
bool ForcedInformMessageDialog::OnKeyInput(const InputEvent *event)
{
    if (event->type == 8) {
        const char key = NarrowInputKey(event->keyCode, event->narrowFallback);

        if (key == 'A' || key == 'a') {
            m_bAccepted = true;
            SlideCloseVertical();
            CloseDialog();
        } else if (key == 'D' || key == 'd') {
            m_bAccepted = false;
            SlideCloseVertical();
            CloseDialog();
            g_pApplication->RequestExit();
        }
    }

    return true;
}
```

This uses the accepted project event model already present on first-draft key handlers: `NarrowInputKey(event->keyCode, event->narrowFallback)`, `event->type == 8`, and no raw `event+8` / `event+0x10a` offsets. The binary receives a secondary-subobject `this` pointer and adjusts by `0xa0`; source-facing C++ should stay on the `ForcedInformMessageDialog` method and let the compiler/vtable lowering represent the secondary view.

### Scalar Deleting Destructor Support

[UID:0001JA] `0x0058abf0-0x0058acb2` should become non-emitting compiler-generated scalar deleting destructor support after the non-deleting destructor child is added:

- `COMPLETION:88`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:FALSE`
- `EMITTER_UIDS:` blank
- formal C++ block blank

It should link to the new non-deleting destructor child as the source-body owner and keep evidence for vtable ref `0x0062d718`, adjustor thunk callers `0x0058aae1/0x0058aaec`, optional operator delete, login restore, and singleton clear.

## Score Recommendation

Recommended metadata after implementation:

| Page | Completion | Confidence | Owner | Reconstructable | Emitters |
| --- | ---: | ---: | --- | --- | --- |
| [UID:0001J7] parent aggregate | `90` | `92` | `NONE` | `FALSE` | blank |
| new constructor child `0x00587bb0-0x00588073` | `89` | `91` | `00005E` | `TRUE` | `0000JJ` |
| new non-deleting destructor child `0x00588080-0x00588101` | `89` | `91` | `00005E` | `TRUE` | `0000JJ` |
| new button callback child `0x00588110-0x0058815d` | `90` | `92` | `00005E` | `TRUE` | `0000JJ` |
| new key callback child `0x00588160-0x005881ed` | `89` | `91` | `00005E` | `TRUE` | `0000JJ` |
| [UID:0001JA] scalar deleting destructor | `88` | `91` | `NONE` | `FALSE` | blank |

Rationale:

- Completion improves because the split removes the aggregate-body duplication problem, current MCP proves exact boundaries/padding, helper/global names are resolved to source-facing forms, and formal C++ is available on exact source-bearing children.
- Confidence improves because callback reachability is vtable-proven, constructor attachment parameters are resolved through DialogPane callee semantics, and the remaining no-caller caveat is bounded.
- Scores stay below final-audit range because exact original helper spellings such as `SetEditActiveState`, `SetControlVisible`, `SetDimmed`, and some final constructor overload spellings remain role-level project source names rather than symbol-proven names.

## Support Page Consistency Plan

Apply these changes only during an accepted implementation callback:

1. `by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md`
   - Convert to `90/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`.
   - Keep the formal C++ block blank as a non-emitting split container, not as an accidental blank.
   - Replace the old blocker wording with current MCP session `b001_000241_20260627` evidence.
   - Add the exact child table and split/padding evidence.
   - Change "helper/global labels still real" to the resolved source-facing mapping table.
   - State callback reachability is resolved through vtable data refs; direct constructor reachability remains unresolved.

2. Create `by-memory/0x00587bb0-0x00588073.ForcedInformMessageDialogConstructor.md`
   - Populate metadata and formal constructor C++ exactly as listed in this report.
   - Document constructor no-caller negative evidence and `parentPane`/`layer` callee-based parameter resolution.
   - Include `DLGSTAFF.EPF`, `DLGSTAFF.PAL`, `DLGSTAFF.EPD`, legacy `L"NP"`, text pane, button image ids `14/22`, focus ids `2/3`, dimmer call, and `m_bAccepted`.

3. Create `by-memory/0x00588080-0x00588101.ForcedInformMessageDialogNonDeletingDestructor.md`
   - Populate metadata and formal destructor C++ exactly as listed in this report.
   - Document that compiler vtable restores and base cleanup are not explicit source.

4. Create `by-memory/0x00588110-0x0058815d.ForcedInformMessageDialogOnButtonResponse.md`
   - Populate metadata and formal button callback C++ exactly as listed in this report.
   - Distinguish action ids `2/3` from constructor image ids `14/22`.

5. Create `by-memory/0x00588160-0x005881ed.ForcedInformMessageDialogOnKeyInput.md`
   - Populate metadata and formal key callback C++ exactly as listed in this report.
   - Use accepted `InputEvent` field names and `NarrowInputKey`; document secondary-subobject `this` lowering without writing raw pointer-adjust source.

6. `by-file/ForcedInformMessageDialog.md`
   - Sync the method inventory to parent aggregate plus exact source-bearing children.
   - Add the source-facing helper/global mapping table.
   - State generated output should come from exact children, not the parent aggregate or scalar deleting wrapper.
   - Keep proposed source route `NexusTK/login/ForcedInformMessageDialog.cpp/.h`.

7. `by-class/ForcedInformMessageDialog.md`
   - Add/update declarations for constructor, destructor, `OnButtonResponse`, and `OnKeyInput`.
   - Add/confirm `m_bAccepted` at `+0x26c`.
   - Replace raw globals with `g_useEpfAssets`, `g_pScreenDimmer`, `g_pForcedInformMessageDialog`, `g_pMainUiGraph`, `g_pApplication`, `g_screenWidth`, and `g_screenHeight`.
   - Note the secondary-view key handler is source-facing `ForcedInformMessageDialog::OnKeyInput` despite binary `this-0xa0` adjustment.

8. `by-memory/0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor.md`
   - Reclassify to non-emitting compiler-generated scalar deleting destructor support.
   - Link to the new non-deleting destructor child as source-body owner.
   - Keep evidence for vtable ref, adjustor thunks, optional operator delete, login restore, and singleton clear.

9. `by-memory/0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear.md`
   - No metadata change required.
   - If touched, improve the item summary to say it is the compiler/EH singleton-clear helper for `g_pForcedInformMessageDialog`, exact `0xb` size, no ordinary callers, no source emission.

10. `by-memory/0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks.md`
   - No metadata change required.
   - If touched, improve the item summary to explicitly mention `this-0xa0`, `this-0xa4`, scalar destructor target `0x0058abf0`, vtable refs `0x0062d778`/`0x0062d7a8`, and no source emission.

11. `by-memory/0x0069b4a0-0x0069b4a4.g_pForcedInformMessageDialog.md`
   - No ownership change.
   - Reconcile static initializer wording if touched: current active MCP `get_bytes` sees `00 00 00 00`, while older docs say `ff ff ff ff`. The source-facing singleton name and lifecycle refs remain valid either way.
   - Add links to the new constructor and non-deleting destructor children if edited.

12. `by-memory/0x0062d714-0x0062d7b0.ForcedInformMessageDialogVtableData.md`
   - No metadata change required.
   - Add the current vtable/callback reachability summary if touched: button callback via `0x0062d760`, key callback via `0x0062d780`, scalar destructor via `0x0062d718`, and constructor/destructor/scalar stores to all three vtable views.

13. Support declarations if the implementation batch edits them:
   - `by-class/DialogPane.md`: add or note `SetHoverControl(int controlId)` as the accepted source-facing alias for `0x0049fc00` if not already declared.
   - `by-class/TextEditControlPane.md`: add role aliases for `SetEditActiveState(bool,bool)`, `SetControlVisible(bool)`, and `GetTextEditPane()` if needed by the constructor child C++.
   - `by-class/ScreenDimmer.md`: add role alias `SetDimmed(bool)` for the virtual singleton call if no final method spelling exists.
   - `by-class/InputEvent` support does not exist as a single page; follow the accepted key-handler pattern using `InputEvent::type`, `keyCode`, `narrowFallback`, and `NarrowInputKey`.

14. Optional related support sync if already in the implementation batch:
   - `by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md`: reconcile static initializer wording in the same way as `g_pForcedInformMessageDialog` if edited.
   - `by-global/g_pForcedInformMessageDialog.md`: mirror the split-container/child-source ownership rationale and remove stale old-gate wording if present.

## Expected Validators After Implementation

Run only in the accepted implementation callback, after acquiring short-lived leases for edited by-* docs:

> Executable block R001 was removed from this report and preserved verbatim in [0001J7-ForcedInformMessageDialogCore-source-quality-removed.md](0001J7-ForcedInformMessageDialogCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If optional support declarations are edited, run the same scoped validator command for each edited file, especially `by-class\DialogPane.md`, `by-class\TextEditControlPane.md`, `by-class\ScreenDimmer.md`, and `by-memory\0x0069ae08-0x0069ae0c.g_pScreenDimmer.md`. Do not manually edit coverage reports or generated reports; let the validator/generation pipeline refresh generated outputs.

## Implementation Tracking Checklist

- [x] Acquire only the required short-lived leases for the edited target/support by-* docs.
  - Proof: B008 acquired a fresh lease over all 15 changed by-* docs after the four new child files existed, before validator-applied normalization; the child docs could not be leased until creation.
- [x] Update [UID:0001J7] parent aggregate to `90/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++ block.
  - Proof: validator command `000000004685` at `2026-06-27T22:49:30-04:00` confirmed completion `90`, confidence `92`, owner `NONE`, and registry flip `true -> false`.
- [x] Add child page `0x00587bb0-0x00588073.ForcedInformMessageDialogConstructor.md` with the exact constructor C++ from this report.
  - Proof: assigned [UID:00048Y]; child validator batch exited `0` and inserted the formal constructor C++ under owner [UID:00005E] / emitter [UID:0000JJ].
- [x] Add child page `0x00588080-0x00588101.ForcedInformMessageDialogNonDeletingDestructor.md` with the exact destructor C++ from this report.
  - Proof: assigned [UID:00048Z]; child validator batch exited `0` and the scalar deleting destructor support page now links this child as source-body owner.
- [x] Add child page `0x00588110-0x0058815d.ForcedInformMessageDialogOnButtonResponse.md` with the exact button callback C++ from this report.
  - Proof: assigned [UID:000490]; child validator batch exited `0` and generated output includes this exact child as `ForcedInformMessageDialog::OnButtonResponse`.
- [x] Add child page `0x00588160-0x005881ed.ForcedInformMessageDialogOnKeyInput.md` with the exact key callback C++ from this report.
  - Proof: assigned [UID:000491]; child validator batch exited `0` and generated output includes this exact child as `ForcedInformMessageDialog::OnKeyInput`.
- [x] Reclassify [UID:0001JA] scalar deleting destructor as non-emitting generated destructor support and link it to the non-deleting destructor child.
  - Proof: validator command `000000004691` at `2026-06-27T22:50:12-04:00` confirmed `88/91`, owner `NONE`, registry flip `true -> false`, and TMP replacement to [UID:00048Z].
- [x] Replace raw helper/global blocker wording in [UID:0001J7] and support docs with the source-facing mapping from this report.
  - Proof: [UID:0001J7], by-file/by-class pages, singleton, vtable, thunk, scalar-wrapper, and support declaration pages now use the accepted helper/global map and child UIDs; `rg -n TMP` across the changed docs returned no matches.
- [x] Document current MCP session `b001_000241_20260627` boundary, xref, byte, decompile, constructor-negative, parameter-semantics, and split-padding evidence.
  - Proof: [UID:0001J7] preserves the MCP session name, exact split table, `0xcc` padding, vtable callback refs, constructor no-caller evidence, and DialogPane callee-based `parentPane`/`layer` semantics.
- [x] Update `by-file/ForcedInformMessageDialog.md` to route generated source through exact children and not through [UID:0001J7] or [UID:0001JA].
  - Proof: validator command `000000004687` at `2026-06-27T22:49:50-04:00` confirmed `88/88`, `CANONICAL_OWNER:FILE`, and TMP replacement to [UID:00048Y], [UID:00048Z], [UID:000490], and [UID:000491].
- [x] Update `by-class/ForcedInformMessageDialog.md` method/global/field naming notes and add child cross-links.
  - Proof: validator command `000000004689` at `2026-06-27T22:50:01-04:00` confirmed `89/89`, owner [UID:0000JJ], child TMP replacement, and generated class declaration with constructor, destructor, `OnButtonResponse`, `OnKeyInput`, and `m_bAccepted`.
- [x] Add support declarations/notes for `SetHoverControl`, `SetEditActiveState`, `SetControlVisible`, `ScreenDimmer::SetDimmed`, and accepted `InputEvent` key field usage only if the edited formal C++ requires them.
  - Proof: `by-class/DialogPane.md` adds default-category `AddControl(ControlPane *)` and `SetHoverControl(int)`; `by-class/TextEditControlPane.md` adds source-facing aliases for edit-active, visibility, and editor access; `by-class/ScreenDimmer.md` adds `SetDimmed(bool)`; exact child/class docs carry the accepted `InputEvent` key-field usage because no standalone InputEvent support page exists.
- [x] Reconcile or explicitly preserve singleton static-byte wording on `g_pForcedInformMessageDialog` / `g_pScreenDimmer` support if those files are touched.
  - Proof: touched [UID:0001PW] records the current MCP `00 00 00 00` bytes versus older `ff ff ff ff` wording and links [UID:00048Y]/[UID:00048Z]; `g_pScreenDimmer` storage was not edited in this batch.
- [x] Run the scoped validators listed in this report with generated output current.
  - Proof: all scoped validator commands used `--apply --queue-timeout 240 --wait-generated` and exited `0`: child batch `000000004680` through `000000004683`; existing/support docs `000000004685`, `000000004687`, `000000004689`, `000000004691`, `000000004693`, `000000004694`, `000000004695`, `000000004696`, `000000004697`, `000000004698`, and `000000004700`.
- [x] Confirm generated output reflects the parent split container, exact method children, and non-emitting scalar deleting destructor.
  - Proof: `auto-generated/NexusTK/login/ForcedInformMessageDialog.cpp` is refreshed by validator command `000000004700` at `2026-06-27T22:51:34-04:00`; it contains only class [UID:00005E] plus exact child sections [UID:00048Y], [UID:00048Z], [UID:000490], and [UID:000491], with no [UID:0001J7] parent or [UID:0001JA] scalar-wrapper emission.
- [x] Release all leases immediately after the edit/validator batch.
  - Proof: `python tools\leaser\leaser.py B008 unlease ...` returned `Success` for all 15 leased docs, and the shared lease table query for B008/ForcedInform/DialogPane/TextEditControlPane/ScreenDimmer returned no rows after release.

FINISHED_REPORT

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0001J7-ForcedInformMessageDialogCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0001J7-ForcedInformMessageDialogCore-source-quality.md","timestamp":"2026-06-27T22:56:04","uid":"0001J7"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001J7-ForcedInformMessageDialogCore-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/0001J7-ForcedInformMessageDialogCore-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001J7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
