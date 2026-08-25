** TARGET-REPORT-UID:0001A2 **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B014 B-report: [UID:0001A2] BackStoryDialogPaneCore source-quality

Target: `source-3/project-documentation/by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md`

Report-only status: do not edit target/support by-* docs or `by-memory/-coverage-report.md` until a supervisor implementation callback.

## Recommendation summary

- Recommend `COMPLETION:88`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, owner/emitter unchanged: `CANONICAL_OWNER:0000HP`, `EMITTER_UIDS:0000HP`.
- First-draft C++ is ready for the target-covered constructor and button handler only:
  - `BackStoryDialogPane::BackStoryDialogPane()`
  - `BackStoryDialogPane::HandleButtonClick(int buttonId, int unused)`
- Destructor/clear/thunk support is proven outside this range and should remain no-code or separate support coverage:
  - `0x00502390-0x0050239b` singleton clear helper
  - `0x0050245e-0x00502474` adjustor thunks
  - `0x00502600-0x00502645` scalar deleting destructor
- Live construction/reachability should no longer remain passively open. Best-supported direction: this is source-authored retained/compatibility BackStory text-dialog code, not the active current main-menu story path. Active story/history menu paths construct `HistoryViewingPane`, while this class remains represented by vtables, singleton lifecycle, cleanup consumer, unique `BACKTALE` text, and complete constructor/destructor support.

## Evidence checked

- Target memory doc:
  - `by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md`
- Support docs:
  - `by-class/BackStoryDialogPane.md`
  - `by-file/BackStoryDialogPane.md`
  - `by-global/g_pBackStoryDialogPane.md`
  - `by-memory/0x0069b498-0x0069b49c.g_pBackStoryDialogPane.md`
  - `by-resource/main-menu-story-resources.md`
  - `by-file/MainMenuPane.md`
  - `by-memory/0x004f66e0-0x004f6b40.MainMenuLoginAndAccountDialogs.md`
  - `by-memory/0x004f79d0-0x004f7c80.MainMenuPaneCore.md`
  - `by-memory/0x004f69b0-0x004f69f0.CloseMainMenuDialogSingletons.md`
  - `by-memory/0x004f90c0-0x004f913f.OpenStoryViewingPane.md`
  - `by-memory/0x004f9140-0x004f91bf.OpenHistoryViewingPane.md`
  - `by-file/HistoryViewingPane.md`
  - `by-class/HistoryViewingPane.md`
  - `by-memory/0x004f91c0-0x004f9568.HistoryViewingPaneCore.md`
  - `by-file/NewHistoryDialogPane.md`
  - `by-class/NewHistoryDialogPane.md`
  - `by-memory/0x00501f40-0x0050235c.NewHistoryDialogPaneCore.md`
  - `tools/leaser/Agents/Agent-B003/research/executed/0001A3-new-history-dialog-pane-core-source-quality.md`
  - `by-global/g_useEpfAssets.md`
  - `by-global/g_pMainUiGraph.md`
  - `by-global/MainUiLayerSlots.md`
  - `by-memory/0x0069b36c-0x0069b370.MainUiLayerSlotsHead.md`
  - Dialog/control helper docs for `DialogPane`, `RectGeometryHelpers`, `PaneSetMode`, `EPFImageControlPane`, `ImageButtonControlPane`, and `ScrolledTextControlPane`
- Coverage rows checked:
  - `by-memory/-coverage-report.md`
  - `project-level/-auto-completion-stats.md`
  - `auto-generated/-ag-memory-coverage.md`
- Auto-generated emitter checked:
  - `auto-generated/NexusTK/login/BackStoryDialogPane.cpp`
- Local executable byte/pointer scan:
  - `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
  - MD5 `4247e04e20b65d6414c7238aa8ff5515`
  - SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
  - Image base `0x00400000`
- MCP note:
  - Live MCP resource/template enumeration returned no resources in this session. This report therefore uses current docs plus direct PE byte, rel32, absolute VA, RVA, string, and vtable checks. IDA/MCP validation requests are listed below for supervisor follow-up.

## Heuristic / inference reanalysis

### 1. Construction and reachability

The prior "no direct constructor xref" caveat is real, but it should not block first-draft source for this target. The better resolution is:

`BackStoryDialogPane` is retained/compatibility dialog code with complete source shape and runtime support, but it is not the active current main-menu story route.

Positive source-authored evidence:

- Constructor at `0x00500090` installs BackStory vtables and writes `g_pBackStoryDialogPane`.
- Handler at `0x005003f0` is present in BackStory vtable data at `0x0061daa0`.
- Scalar deleting destructor at `0x00502600` clears `g_pBackStoryDialogPane`, calls `DialogPane` cleanup, and optionally deletes.
- Adjustor thunks at `0x0050245e` and `0x00502469` target the destructor from secondary-base offsets.
- Main-menu cleanup checks `g_pBackStoryDialogPane` and closes it if live.
- Constructor builds coherent EPF and legacy layouts using `STORY.EPF`, `STORY.EPD`, palettes, and unique `BACKTALE` text.

Negative reachability evidence checked:

- No direct rel32 call/jump target to constructor `0x00500090`.
- No absolute VA pointer hit for constructor `0x00500090`.
- No RVA pointer hit for constructor `0x00500090`.
- Vtable head `0x0061da58` is only referenced by the constructor vtable store.
- Active `MainMenuPane::ActivateMenuItem` story/history branches directly construct `HistoryViewingPane`, not `BackStoryDialogPane`.
- Retained story/history wrapper helpers `OpenStoryViewingPane_4F90C0` and `OpenHistoryViewingPane_4F9140` also construct `HistoryViewingPane`, not `BackStoryDialogPane`.
- `CloseMainMenuDialogSingletons` is a cleanup consumer only and cannot create this pane.

Rejected alternatives:

- Active current story menu dialog: rejected by direct `HistoryViewingPane` construction in the active menu branch.
- Hidden factory or constructor pointer table: not supported by rel32, VA, or RVA pointer scans.
- Inline construction elsewhere: not supported because the BackStory vtable head is not stored outside this constructor.
- Dead unowned blob: rejected by singleton, vtables, destructor, cleanup consumer, resources, and coherent constructor shape.

### 2. Constructor source shape

Recommended source signature:

```cpp
BackStoryDialogPane::BackStoryDialogPane();
```

Observed behavior:

- Calls `DialogPane(L"", -1, true)`.
- Publishes singleton `g_pBackStoryDialogPane = this`.
- Installs BackStory vtables at primary and secondary base offsets.
- Branches on `g_useEpfAssets`.
- Builds background image pane, image button pane, and scrolled text pane.
- Selects logical control/action id `1`.
- Sets the background resource and pane mode.
- Creates through `dword_69B36C`.
- Shows through `g_pMainUiGraph`.
- Calls `SlideOpen`.

The `this == nullptr` style fallback clear path should be treated as constructor EH/unwind or decompiler artifact support, not source-level control flow.

### 3. EPF and legacy layout branches

EPF branch:

- Background rect: `(0,0)-(384,341)`
- Background resource: `STORY.EPF`
- Palette: `PAL01.PAL`
- Image button visual index: `14`
- Image button rect: `(169,305)-(232,329)`
- Text resource: `BACKTALE`
- Text rect: `(25,56)-(361,278)`
- Text step/line argument: `50`
- Dialog rect: `(246,150)-(630,491)`

Legacy branch:

- Background rect: `(0,0)-(267,337)`
- Background resource: `STORY.EPD`
- Palette: `NPAL8.PAL`
- Image button visual index: `14`
- Image button rect: `(98,287)-(170,303)`
- Text resource: `BACKTALE`
- Text rect: `(36,71)-(228,265)`
- Text step/line argument: `50`
- Dialog rect: `(363,150)-(630,487)`

Important source-quality correction: image index `14` is the button's visual image index, not the logical callback/action id. The logical close action id is `1`.

### 4. Button handler source shape

Recommended source signature:

```cpp
void BackStoryDialogPane::HandleButtonClick(int buttonId, int unused);
```

Observed machine behavior:

- Stack cleanup is `ret 8`, so two arguments follow `this`.
- The first argument is decremented and compared, equivalent to `buttonId == 1`.
- The second argument is unused.
- When `buttonId == 1`, the handler calls `SlideClose` then the shared close/dismiss helper.
- For all other ids, it returns without action.

Recommended source behavior:

```cpp
void BackStoryDialogPane::HandleButtonClick(int buttonId, int /*unused*/)
{
    if (buttonId == 1) {
        SlideClose();
        Close();
    }
}
```

### 5. Owner/emitter/source-file route

Keep the current route:

- Source file owner: [UID:0000HP] `BackStoryDialogPane`
- Class owner: [UID:00000T] `BackStoryDialogPane`
- Target emitter: [UID:0000HP] `auto-generated/NexusTK/login/BackStoryDialogPane.cpp`

The route is correct even though the active current story viewer is `HistoryViewingPane`. This target's resources, singleton, and vtables are internally consistent and belong in `BackStoryDialogPane.cpp`.

### 6. Globals and helper names

Use current source-quality names where resolved:

- `g_useEpfAssets` for `byte_66DA97`
- `g_pBackStoryDialogPane` for `0x0069b498`
- `g_pMainUiGraph` for `dword_67ABA4`
- `dword_69B36C` as the main UI layer/context slot until a better canonical global name is approved

Avoid stale or misleading names:

- Do not call `dword_69B36C` `g_pMainMenuPane`.
- Do not imply `g_pBackStoryDialogPane` is definitely created by current active main-menu story navigation.
- Do not treat raw helper names like `sub_49fc00` or compiler thunk names as source names.

Helper/source-name status:

- `0x004b7c50`: `InitRectBounds`
- `0x0049dc10`: `DialogPane` add-control/control-manager helper
- `0x0049ddd0`: `SetPendingControl(1)` behavior, stores control id at dialog pending-control field
- `0x0049db60`: `SetBackgroundResource`
- `0x005446b0`: `Pane::SetMode`
- `0x0049dfd0`: create/layout helper
- `0x0049e190`: show/register helper
- `0x0049eac0`: `SlideOpen`
- `0x0049eb90`: `SlideClose`
- `0x0049dad0`: shared close/dismiss helper
- `0x0049fc00`: inherited `DialogPane` control-id update helper. Behavior is source-ready with argument `1`, but final canonical name remains open. Suggested draft call name: `SetHoverControl(1)` or equivalent project-approved `DialogPane` control-selection name.

### 7. Destructor, clear, and thunk relationship

Do not put destructor or clear code into target [UID:0001A2]. They are outside the covered range.

No-code proof for compiler/support ranges:

- `0x00502390-0x0050239b`: singleton clear helper, body is only `g_pBackStoryDialogPane = nullptr; return;`, referenced from constructor EH/unwind metadata/code path.
- `0x0050245e-0x00502474`: adjustor thunks subtract `0xa0` or `0xa4` from `this` and jump to `0x00502600`; compiler-generated ABI support.
- `0x00502600-0x00502645`: scalar deleting destructor clears `g_pBackStoryDialogPane`, calls `DialogPane` cleanup, then conditionally calls delete based on flags. Source destructor body is at most the singleton clear; wrapper/delete dispatch is compiler-generated.

## First-draft C++ readiness

Recommended draft code for target [UID:0001A2] only:

```cpp
BackStoryDialogPane::BackStoryDialogPane()
    : DialogPane(L"", -1, true)
{
    g_pBackStoryDialogPane = this;

    RectBounds rect;
    if (g_useEpfAssets) {
        InitRectBounds(&rect, 0, 0, 384, 341);
        AddControl(new EPFImageControlPane(L"STORY.EPF", 0, true, rect, L"PAL01.PAL"));

        InitRectBounds(&rect, 169, 305, 232, 329);
        AddControl(new ImageButtonControlPane(14, rect));

        InitRectBounds(&rect, 25, 56, 361, 278);
        AddControl(new ScrolledTextControlPane(L"BACKTALE", rect, 50));

        SetHoverControl(1);
        SetPendingControl(1);
        SetBackgroundResource(L"STORY.EPF", 0);
        SetMode(1);

        InitRectBounds(&rect, 246, 150, 630, 491);
    } else {
        InitRectBounds(&rect, 0, 0, 267, 337);
        AddControl(new EPFImageControlPane(L"STORY.EPD", 0, true, rect, L"NPAL8.PAL"));

        InitRectBounds(&rect, 98, 287, 170, 303);
        AddControl(new ImageButtonControlPane(14, rect));

        InitRectBounds(&rect, 36, 71, 228, 265);
        AddControl(new ScrolledTextControlPane(L"BACKTALE", rect, 50));

        SetHoverControl(1);
        SetPendingControl(1);
        SetBackgroundResource(L"STORY.EPD", 0);
        SetMode(1);

        InitRectBounds(&rect, 363, 150, 630, 487);
    }

    Create(rect, 0, 0, dword_69B36C);
    Show(false, g_pMainUiGraph);
    SlideOpen();
}

void BackStoryDialogPane::HandleButtonClick(int buttonId, int /*unused*/)
{
    if (buttonId == 1) {
        SlideClose();
        Close();
    }
}
```

Implementation callback caveats:

- Replace `SetHoverControl` with the project-approved final name for helper `0x0049fc00` if that name is settled before emission.
- Keep `dword_69B36C` as-is unless the Main UI layer slot docs approve a better global name.
- Do not emit destructor, adjustor thunk, or singleton-clear support in this target C++ block.

## Recommended exact target doc changes

Header metadata:

```text
COMPLETION:88
CONFIDENCE:90
RECONSTRUCTABLE:TRUE
CANONICAL_OWNER:0000HP
EMITTER_UIDS:0000HP
```

Replace the stale reachability/open-question language with:

```text
B014 2026-06-19 source-quality reanalysis resolves construction reachability as retained/compatibility BackStory text-dialog code rather than active current main-menu story navigation. The active story/history menu branches and retained story/history wrappers construct HistoryViewingPane. A local PE scan found no direct rel32 call/jump, VA pointer, or RVA pointer to constructor 0x00500090, and the BackStory vtable head is only stored by this constructor. The range remains source-authored and C++ ready because the constructor publishes g_pBackStoryDialogPane, installs BackStory vtables, builds coherent STORY.EPF/STORY.EPD plus BACKTALE layouts, routes create/show through dword_69B36C and g_pMainUiGraph, and the vtable-only button handler closes on logical action id 1.
```

Replace handler semantics text with:

```text
BackStoryDialogPane::HandleButtonClick(int buttonId, int unused) is a two-argument virtual callback. It ignores the second argument and closes the dialog only when buttonId == 1 by calling SlideClose followed by the shared close/dismiss helper. The constructor's image-button value 14 is a visual image/resource index; it is not the logical action id.
```

Add or update source-quality naming notes:

```text
Use g_useEpfAssets, g_pBackStoryDialogPane, g_pMainUiGraph, and dword_69B36C. Do not use stale g_pMainMenuPane wording for dword_69B36C. Helper 0x0049fc00 remains a DialogPane inherited control-id update helper pending final project name; draft C++ may use SetHoverControl(1) or the approved equivalent.
```

Add first-draft C++ block from the section above to the target's C++ field on implementation callback.

## Recommended support doc changes

`by-class/BackStoryDialogPane.md`:

- Raise to approximately `COMPLETION:88`, `CONFIDENCE:89`.
- State that the class is retained/compatibility BackStory text-dialog code, not the active current story/history viewer.
- Keep source ownership under `BackStoryDialogPane.cpp`.
- Clarify that the close action id is `1`, while image index `14` is only visual.
- Replace `g_pMainMenuPane` wording with `dword_69B36C` main UI layer/context slot and `g_pMainUiGraph`.
- Mark live construction as resolved negative for current active menu routing, with retained/compatibility source shape proven.

`by-file/BackStoryDialogPane.md`:

- Raise to approximately `COMPLETION:88`, `CONFIDENCE:89`.
- Replace stale "possible indirect active construction" language with the retained/compatibility conclusion.
- Keep emitting file path `NexusTK/login/BackStoryDialogPane.cpp`.
- Add that active current story/history menu actions route to `HistoryViewingPane`, while this file owns the older one-page `BACKTALE` dialog and its singleton/destructor support.
- Replace stale `g_pMainMenuPane` mention with `dword_69B36C` plus `g_pMainUiGraph`.

`by-global/g_pBackStoryDialogPane.md` and exact storage `by-memory/0x0069b498-0x0069b49c.g_pBackStoryDialogPane.md`:

- Keep type `BackStoryDialogPane*`.
- Update lifecycle wording to say constructor publishes and destructor/clear helper clear the singleton, while current main-menu cleanup only consumes the singleton if live.
- Avoid implying that current active menu story navigation constructs it.

`by-resource/main-menu-story-resources.md`:

- Clarify that `BACKTALE` is unique to retained `BackStoryDialogPane`.
- Keep contrast that active current story viewing uses `HistoryViewingPane` paths with `STORY.*`.

Potential future support split:

- Add or update exact support docs for `0x0050245e-0x00502474` and `0x00502600-0x00502645` only if the supervisor wants destructor/thunk coverage separated from the mixed specialized pane aggregate.

## Exact pending coverage row text

Do not edit `by-memory/-coverage-report.md` directly. Recommended replacement row:

```text
    - [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md) 0x00500090-0x0050040d | class method cluster | BackStoryDialogPaneCore : reconstructable : 88% : very strong : B014 2026-06-19 source-quality reanalysis resolves the stale reachability caveat as retained/compatibility BackStory text-dialog code rather than the active main-menu story path: local PE scan found no rel32, VA, or RVA route to constructor `0x00500090`, no constructor pointer table entry, and only vtable/destructor/support pointers for `0x005003f0`, `0x0050245e`, `0x00502469`, and `0x00502600`; active `MainMenuPane` story/history branches and retained story/history wrappers construct [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md). The range remains source-authored and emitting through [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md): constructor publishes `g_pBackStoryDialogPane`, installs three BackStory vtables, builds EPF/legacy `STORY.*` plus `BACKTALE` layouts with image-button visual index `14` and logical close action id `1`, creates through `dword_69B36C`, shows with `g_pMainUiGraph`, and the vtable-only `HandleButtonClick(int buttonId, int unused)` slides/closes on action id `1`; first-draft constructor/handler C++ is ready while clear/thunk/scalar-destructor support stays outside this target.
```

## Validation commands needed

Non-mutating local checks:

> Executable block R001 was removed from this report and preserved verbatim in [0001A2-BackStoryDialogPaneCore-source-quality-removed.md](0001A2-BackStoryDialogPaneCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

IDA/MCP validation requested before implementation callback:

- Confirm no code xrefs to constructor `0x00500090`.
- Confirm data xrefs:
  - `0x005003f0` from vtable slot near `0x0061daa0`
  - `0x0050245e` and `0x00502469` from secondary destructor thunk slots
  - `0x00502600` from primary scalar deleting destructor slot
- Confirm singleton refs to `0x0069b498` at constructor, clear helper, scalar destructor, and main-menu cleanup.
- Confirm active `MainMenuPane::ActivateMenuItem` story/history cases call `HistoryViewingPane` constructors, not `BackStoryDialogPane`.
- Confirm `0x0049fc00` final source-quality helper name or approve temporary `SetHoverControl(1)` draft naming.

Post-callback validators after target C++ emission:

> Executable block R002 was removed from this report and preserved verbatim in [0001A2-BackStoryDialogPaneCore-source-quality-removed.md](0001A2-BackStoryDialogPaneCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If validator paths differ in this checkout, run the project-equivalent memory-doc, emitter-route, and coverage-row validators for UID `0001A2`.

## Remaining open questions

- Original launcher, if any, is absent from current direct code/data evidence. The best-supported direction is retained/compatibility code, not an unresolved active path.
- Final source name for helper `0x0049fc00` still needs project-wide confirmation.
- Final non-raw name for `dword_69B36C` remains pending in Main UI layer slot docs.

None of these blocks first-draft C++ for the constructor and handler in target [UID:0001A2].

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/0001A2-BackStoryDialogPaneCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"0001A2"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001A2-BackStoryDialogPaneCore-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/0001A2-BackStoryDialogPaneCore-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001A2"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
