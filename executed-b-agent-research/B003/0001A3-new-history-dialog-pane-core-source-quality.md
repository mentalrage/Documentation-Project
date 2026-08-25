** TARGET-REPORT-UID:0001A3 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003-goal2-new-history-dialog-pane-core-source-quality-0001A3-20260617

Agent: B003  
Target: [UID:0001A3] `by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md`  
Assignment: `B003-goal2-new-history-dialog-pane-core-source-quality-0001A3-20260617`  
Mode: report-only; no by-* docs, generated source, IDA DB, source files, or coverage reports were edited.

## Recommendation Summary

Raise [UID:0001A3] from `82/88` to `87/91`, keep `RECONSTRUCTABLE:TRUE`, keep `CANONICAL_OWNER:0000LQ`, keep `EMITTER_UIDS:0000LQ`, and populate formal first-draft C++ in `NexusTK/login/NewHistoryDialogPane.cpp`.

The direct constructor caller remains unproven, but it is now a resolved negative reachability finding rather than a sub-85 source-quality blocker. I checked the current IDA function model, direct xrefs, vtable pointer references, singleton/resource xrefs, and a raw PE little-endian pointer scan. The constructor start has no direct or raw pointer-table reference, while the key/mouse/destructor functions do appear as vtable pointers. That rules out an obvious missing launcher table inside the current executable and supports documenting the constructor as retained/source-authored dialog code with an unknown historic launch path.

Correct stale support wording that says the tail shows over `g_pMainMenuPane`. The live operands are `dword_69B36C` and `dword_67ABA4`. Current support docs identify those as a `MainUiLayerSlots` layer/context slot and `g_pMainUiGraph`, respectively. This still keeps the class in the login/main-menu source family, but the exact create/show operands should not be renamed to a literal `g_pMainMenuPane`.

## Evidence Checked

- Read target [UID:0001A3], class [UID:000091], file [UID:0000LQ], singleton [UID:0000RS]/[UID:0001PV], destructor/unwind support [UID:0001A8]/[UID:0001AC]/[UID:0001AH], resources [UID:0001RF], scrolled text support [UID:00019X]/[UID:0000CJ], `MainMenuPane`, `MainUiLayerSlots`, `g_pMainUiGraph`, `DialogPane`, `DialogControlPaneHelpers`, `EPFImageControlPaneCore`, and `PaneSetMode`.
- Searched prior agent material with `rg "0001A3|00500410|NewHistoryDialogPaneCore|NewHistoryDialogPane" source-3/project-documentation/tools/leaser/Agents -g "*.md"`. No prior B report for this target was found. Existing A/C notes were treated as leads only.
- Generated route check: `auto-generated/NexusTK/login/NewHistoryDialogPane.cpp` exists but has length `0`, so generated output currently omits this source body.
- IDA evidence already recorded in the current session: `lookup_funcs` reports `NewHistoryDialogPane_Constructor` at `0x00500410` size `0x1a4`, key handler at `0x005005c0` size `0x45`, mouse handler at `0x00500610` size `0x22`, singleton clear at `0x005023e0` size `0xb`, destructor thunks at `0x005024f8`/`0x00502503`, and scalar deleting destructor at `0x00502920` size `0x45`.
- `analyze_function 0x00500410` confirms the constructor body: base `DialogPane` construction, `g_pNewHistoryDialog` publish/fallback clear, three vtable stores, full-screen `HISTORYN.EPF`/`HISTORYN.PAL` image control, `MADEBY` scrolled-text control at `(614,156)-(950,556)`, background-resource setup, pane mode set to `1`, create with `dword_69B36C`, and show with `dword_67ABA4`.
- `analyze_function 0x005005c0` confirms event type `8`, key narrowing from event bytes `+0x08` and `+0x10a`, close on Enter/Escape/Space, and `this - 0xa0` adjustment before calling the shared dialog close helper.
- `analyze_function 0x00500610` confirms event codes `3` or `6`, then the same `this - 0xa0` close call.
- `xrefs_to 0x00500410` reports no direct constructor-start xrefs. `xrefs_to 0x0069b49c` reports exactly five singleton refs: made-by scroller close read `0x004ff6eb`, constructor writes `0x00500465`/`0x0050046c`, singleton clear helper `0x005023e0`, and destructor clear `0x00502926`.
- Raw PE pointer scan over `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

```text
0x00500410 Count 0
0x005005c0 Count 1 RawOffset 0x21c55c
0x00500610 Count 1 RawOffset 0x21c558
0x005023e0 Count 0
0x00502920 Count 1 RawOffset 0x21c4f4
```

This proves the constructor is not present as a raw absolute-VA table pointer in the current PE, while the vtable methods/destructor are.

## Heuristic / Inference Reanalysis And Validation

### Constructor reachability and raw launcher evidence

Best inference: `0x00500410` is a source-authored `NewHistoryDialogPane::NewHistoryDialogPane()` constructor retained in the login/main-menu dialog family. Its live entry path is not statically represented by a direct call or raw absolute-VA pointer in the current executable.

Evidence checked: IDA `xrefs_to 0x00500410`, `analyze_function` caller list, raw PE pointer scan, resource xrefs, vtable stores, singleton lifecycle xrefs, and adjacent login/main-menu docs. The constructor has no direct xrefs, but its owned vtable family is installed by the body, its singleton is read by the made-by scroller, its resources are unique to the new history/credits dialog, and its destructor/support family is coherent.

Rejected alternatives:

- Direct `MainMenuPane::ActivateMenuItem` caller: rejected. Existing `MainMenuPane` evidence directly constructs `HistoryViewingPane` for story/history branches, not this constructor.
- Hidden raw function-pointer table in the PE: rejected for the current executable by the raw pointer scan.
- Dead/unowned blob: rejected. The constructor installs class vtables, publishes a documented singleton, is paired with destructor/adjustor support, and has unique resource/control composition.
- Separate in-scope raw launcher split: rejected. No referenced raw launcher bytes or table entry were found. Creating a child page for a hypothetical launcher would be unsupported.

Score impact: this evidence removes the sub-85 completion blocker. The unknown historic entry path caps completion below the low 90s, but it does not prevent an `85/85+` reconstruction recommendation.

### Source-facing signatures and event semantics

Best inference:

- Constructor signature: `NewHistoryDialogPane::NewHistoryDialogPane()`.
- Key callback: source-level `bool NewHistoryDialogPane::OnKeyInput(const Event& event)` or project-equivalent input-event pointer signature. The compiled callback is reached through the secondary view at `this + 0xa0`.
- Mouse callback: source-level `bool NewHistoryDialogPane::OnMouseInput(const Event& event)` or project-equivalent mouse-event pointer signature, also through the secondary view.

Evidence checked: decompilation of `0x005005c0` and `0x00500610`, vtable cells `0x0061db5c` and `0x0061db58`, destructor thunks that subtract `0xa0`/`0xa4`, and related event docs. Event type `8` is consistently documented as key input. Event types `3` and `6` match the EventMan left-button-up and right-button-up release paths, not generic mouse down/up. The target and class docs should replace "mouse down/up" with "left/right mouse-button release close events" or the more conservative "event codes `3` or `6`".

Rejected alternatives:

- Key handler as a character-input body: rejected because it gates on event type `8` and only dismisses; it does not mutate text fields.
- Mouse handler as mouse-down/mouse-up pair: rejected by EventMan support docs that show `3` as left-button release and `6` as right-button release.
- Explicit source-level `this - 0xa0`: rejected for C++. That adjustment is ABI glue from the secondary event-handler subobject back to the complete `DialogPane` object.

Score impact: the signatures and event semantics are strong enough for formal first-draft C++. Remaining uncertainty is only original enum spelling.

### DialogPane, control, and resource helper names

Best defensible helper directions:

- `0x0049d8a0`: `DialogPane` constructor with empty title, config id `-1`, and mode/capture flag `1`.
- `0x004b7c50`: `InitRectBounds` / rectangle initializer.
- `0x004991f0`: `EPFImageControlPane` constructor.
- `0x004ff400`: `ScrolledTextControlPaneForMadeBy` constructor.
- `0x0049db60`: `DialogPane::SetBackgroundResource`.
- `0x0049dc10`: `DialogPane::AddControl` / `EnsureControlManagerAndAdd`.
- `0x0049dad0`: shared `DialogPane::Close` / dismiss helper.
- `0x0049dfd0`: `DialogPane::Create` / create-layout handler.
- `0x0049e190`: `DialogPane::Show` / modal-register show handler.
- `0x005446b0`: `Pane::SetMode`; for this target it sets mode byte `1`.

Evidence checked: `DialogPane` aggregate and exact child docs, `EPFImageControlPaneCore`, `PaneSetMode`, and constructor decompilation. The `DialogPane` helper docs already split `SetBackgroundResource` and `EnsureControlManagerAndAdd` as exact children, so these names are not merely target-local guesses.

Rejected alternatives:

- Owning EPF/image parsing in `NewHistoryDialogPane.cpp`: rejected. `EPFImageControlPane` and image/layout registries are shared UI/resource modules.
- Owning scrolled text behavior in `NewHistoryDialogPane.cpp`: rejected. The constructor composes `ScrolledTextControlPaneForMadeBy`, while scrolling/timer close behavior remains with the scrolled text control module.
- Using generated owner-polluted names for helpers: rejected. Source text should use shared UI helper names or project-local wrappers, not `sub_*` labels.

Score impact: helper identities are strong enough to raise completion above the gate. Exact original spellings still cap completion/confidence below final audit quality.

### Source placement and owner/emitter treatment

Best inference: keep [UID:0001A3] owned/emitted by [UID:0000LQ] `NewHistoryDialogPane`, generated route `NexusTK/login/NewHistoryDialogPane.cpp`. This is a class method cluster, not a `MainMenuPane` helper and not a generic UI-control module.

Evidence checked: proposed source tree, `MainMenuPane`, `NewHistoryDialogPane`, `main-menu-history-resources`, `g_pNewHistoryDialog`, and constructor resources. The resources and adjacency keep this in the login/main-menu family. The singleton lifecycle and class vtables make `NewHistoryDialogPane.cpp` the direct source home.

Rejected alternatives:

- Move to `MainMenuPane.cpp`: rejected. `MainMenuPane` supplies family/launcher context but does not own the class implementation.
- Move to `DialogPane.cpp`: rejected. `DialogPane` helpers are dependencies only.
- Move to `ScrolledTextControlPane.cpp`: rejected. Only the embedded made-by control behavior belongs there.
- Treat `dword_69B36C`/`dword_67ABA4` as `g_pMainMenuPane`: rejected. Current support docs identify them as a `MainUiLayerSlots` slot and `g_pMainUiGraph`.

Score impact: owner/emitter/source route are stable. The stale `g_pMainMenuPane` wording should be updated, but it does not change the direct owner.

### Range, padding, and split policy

Best inference: no split is required for [UID:0001A3]. The target is an exact class-method cluster containing constructor, key callback, mouse callback, and two internal `0xcc` alignment spans. It should continue to include:

- `0x00500410-0x005005b4` constructor.
- `0x005005b4-0x005005c0` padding.
- `0x005005c0-0x00500605` key callback.
- `0x00500605-0x00500610` padding.
- `0x00500610-0x00500632` mouse callback.

Evidence checked: IDA `lookup_funcs`, `get_bytes`, existing ignored padding rows, successor/predecessor docs, destructor support pages. Non-contiguous singleton clear, destructor thunks, and scalar deleting destructor already have separate pages.

Rejected alternatives:

- Exact child split for constructor/key/mouse: unnecessary for this assignment because the aggregate is not mixed-owner or overbroad; all source-bearing bodies are the same class/file and the padding is already ignored.
- Expand range into destructor support: rejected. Destructor support is non-contiguous and already documented.
- Create a launcher child: rejected due no direct/raw launcher evidence.

Score impact: range treatment is closed and supports formal C++ emission for the class methods in the cluster.

### Existing docs validated or rejected

Validated:

- Function boundaries and padding spans in [UID:0001A3].
- `HISTORYN.EPF`, `HISTORYN.PAL`, and `MADEBY` resource composition.
- `ScrolledTextControlPaneForMadeBy` ownership outside this file.
- Singleton lifecycle through [UID:0001PV]/[UID:0000RS].
- Login/main-menu source family placement.

Rejected or revised:

- "Shows over `g_pMainMenuPane`" should be revised to "creates/shows using `dword_69B36C` main UI layer/context and `g_pMainUiGraph`; this remains login/main-menu family evidence."
- "Mouse down/up" should be revised to "event codes `3` or `6`, best read as left/right mouse-button release close events."
- "Direct constructor reachability is unresolved" should be retained only as a source-history caveat, not as a blocker to `85/85+` or formal first-draft C++ for this target.
- [UID:0001PV] by-memory coverage row still says initialized to `0xffffffff`; the memory doc and C001 refresh record current zeroed storage bytes, so the row should be replaced.

## Exact Target Doc Recommendations

For [UID:0001A3] `by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md`:

Metadata:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace the `Confidence` status bullet with:

```markdown
- Confidence: very strong for function boundaries, vtable ownership, singleton/resource operands, event behavior, source placement, and first-draft C++ shape; capped below final audit quality because the historic constructor entry path has no direct or raw PE pointer evidence in the current executable.
```

Replace the `Behavior Summary` section text with:

```markdown
The constructor creates a full-screen [UID:00003T][DialogPane](by-class/DialogPane.md), writes [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md), installs three `NewHistoryDialogPane` vtable pointers, adds a `HISTORYN.EPF` background image with `HISTORYN.PAL`, adds a [UID:0000CJ][ScrolledTextControlPaneForMadeBy](by-class/ScrolledTextControlPaneForMadeBy.md) for the `MADEBY` text resource at `(614, 156)-(950, 556)`, loads the dialog resource, sets pane mode `1`, creates the full-screen dialog with the `dword_69B36C` main UI layer/context slot, and shows it with [UID:0000RF][g_pMainUiGraph](by-global/g_pMainUiGraph.md). This is pre-login/main-menu source-family evidence, but the operands should not be renamed to a literal `g_pMainMenuPane`.

The key handler closes the dialog on key event type `8` when the narrowed key is Enter (`0x0d`), Escape (`0x1b`), or Space (`0x20`). The mouse handler closes the dialog on event codes `3` or `6`, best read from EventMan support docs as left/right mouse-button release close events. Both handlers are secondary-view callbacks and adjust `this - 0xa0` back to the complete dialog before calling the shared `DialogPane` close helper.
```

Add these bullets after the existing `xrefs_to 0x00500410` evidence bullet:

```markdown
- A B003 2026-06-17 raw PE pointer scan over `NexusTK.exe` found no little-endian absolute-VA pointer to constructor start `0x00500410`, while the key handler `0x005005c0`, mouse handler `0x00500610`, and scalar deleting destructor `0x00502920` each appear once as vtable pointers. This closes the obvious hidden-function-pointer-table alternative for the current executable.
- The missing constructor caller is now a source-history caveat rather than an ownership or first-draft-C++ blocker: resource xrefs, singleton lifecycle xrefs, vtable stores, destructor support, and the made-by scroller close read prove the class is a real retained NexusTK dialog.
```

Replace the `Score Rationale` section with:

```markdown
Completion is raised from `82` to `87` because the page now records the full source-facing constructor/key/mouse shape, the raw PE no-pointer result for the constructor reachability caveat, corrected event semantics, corrected create/show operands, shared `DialogPane`/`Pane`/control helper directions, aggregate-vs-child emission policy, and formal first-draft C++ readiness. Confidence is raised from `88` to `91` because IDA function boundaries, vtable data, singleton/resource xrefs, support docs, and raw PE pointer evidence agree. The score remains below final audit quality because the original historic launcher is still not represented by a direct/static reference and exact enum/helper spellings may differ from the final style guide.
```

Add this change-log entry:

```markdown
- 2026-06-17 B003 source-quality reanalysis:
  - Before: `82/88`, with direct constructor reachability, helper names, event semantics, `g_pMainMenuPane` wording, and first-draft C++ policy still open.
  - Changed to: recommended `87/91`, retaining owner/emitter [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md), `RECONSTRUCTABLE:TRUE`, and formal C++ emission.
  - Summary/evidence: live IDA and support-doc review reconfirmed the constructor/key/mouse boundaries, singleton/resource/vtable evidence, `DialogPane` helper roles, secondary-subobject `this - 0xa0` adjustment, and padding treatment; a raw PE pointer scan found no constructor pointer but did find the vtable method/destructor pointers; `dword_69B36C`/`dword_67ABA4` were resolved as main UI layer/context plus `g_pMainUiGraph`, not a literal `g_pMainMenuPane`; event codes `3`/`6` were narrowed to mouse-button release close events.
```

## Support Doc Recommendations

For [UID:000091] `by-class/NewHistoryDialogPane.md`, body-only update is enough. Keep metadata unless supervisor wants parent score alignment. Replace the constructor/method/resource rows that say `g_pMainMenuPane` and "mouse down/up" with:

```markdown
| Constructor | `0x00500410-0x005005b4` | Builds a full-screen dialog, background image, `MADEBY` scrolled text control, creates it with the `dword_69B36C` main UI layer/context slot, and shows it with `g_pMainUiGraph`; no direct/raw PE constructor pointer is present in the current executable. |
| `OnKeyInput` | `0x005005c0-0x00500605` | Closes on key event type `8` for Enter, Escape, or Space after key narrowing. |
| `OnMouseInput` | `0x00500610-0x00500632` | Closes on event codes `3` or `6`, best read as left/right mouse-button release events. |
```

Replace the class-page source-quality caveat with:

```markdown
Direct constructor reachability remains a source-history caveat after B003's 2026-06-17 direct-xref and raw PE pointer scan, but it no longer blocks [UID:0001A3] first-draft C++: the constructor has unique resource operands, class vtable stores, singleton lifecycle writes, destructor support, and a made-by scroller close consumer. Helper names should use the shared `DialogPane`/`Pane`/control docs rather than generated `sub_*` labels.
```

For [UID:0000LQ] `by-file/NewHistoryDialogPane.md`, replace source placement wording that mentions `g_pMainMenuPane` with:

```markdown
The constructor tail uses the `dword_69B36C` main UI layer/context slot and [UID:0000RF][g_pMainUiGraph](by-global/g_pMainUiGraph.md) when creating/showing the full-screen dialog. This is pre-login/main-menu family evidence, but current docs should not describe those operands as a literal `g_pMainMenuPane`.
```

For [UID:0000RS] `by-global/g_pNewHistoryDialog.md`, replace the `Open Questions` section with:

```markdown
## Open Questions

- The current executable still has no direct constructor-start xref and B003's 2026-06-17 raw PE pointer scan found no absolute-VA pointer to `0x00500410`; this is a source-history caveat for the launcher path, not an ownership blocker for the singleton or [UID:0001A3] first-draft C++.
- Final declaration spelling remains `g_pNewHistoryDialog` in documentation until a safe data-symbol rename path is available.
```

For [UID:0001PV] `by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md`, no metadata change is required, but the by-memory coverage row should be replaced because it still says the storage is initialized to `0xffffffff` while the memory page and C001 refresh say current bytes are zeroed.

## First-Draft C++ Recommendation

Populate formal C++ for [UID:0001A3]. This target is reconstructable/emitting, the recommended score is `87/91`, and `(87 + 91) / 2 = 89`, which clears the active code gate. The remaining no-direct-constructor-xref finding should be documented as source-history uncertainty, not as a reason to leave the formal C++ block blank.

Recommended first draft:

```cpp
namespace {
constexpr unsigned char kEventLeftButtonUp = 3;
constexpr unsigned char kEventRightButtonUp = 6;
constexpr unsigned char kEventKeyInput = 8;
}

NewHistoryDialogPane::NewHistoryDialogPane()
    : DialogPane(L"", -1, true)
{
    g_pNewHistoryDialog = this;

    RectBounds rect;
    InitRectBounds(&rect, 0, 0, 1024, 768);
    AddControl(new EPFImageControlPane(L"HISTORYN.EPF", 0, true, rect, L"HISTORYN.PAL"));

    InitRectBounds(&rect, 614, 156, 950, 556);
    AddControl(new ScrolledTextControlPaneForMadeBy(L"MADEBY", rect, 30));

    SetBackgroundResource(L"HISTORYN.EPF", 0);
    SetMode(1);

    InitRectBounds(&rect, 0, 0, 1024, 768);
    Create(rect, 0, 0, dword_69B36C);
    Show(false, g_pMainUiGraph);
}

bool NewHistoryDialogPane::OnKeyInput(const Event& event)
{
    if (event.type == kEventKeyInput) {
        const char key = NarrowKeyCode(event.keyCode, event.defaultChar);
        if (key == '\r' || key == '\x1b' || key == ' ') {
            Close();
        }
    }

    return true;
}

bool NewHistoryDialogPane::OnMouseInput(const Event& event)
{
    if (event.type == kEventLeftButtonUp || event.type == kEventRightButtonUp) {
        Close();
    }

    return true;
}
```

Notes for supervisor application:

- If the project standard uses pointer rather than reference event arguments, adjust only the signature/access syntax. The underlying offsets are `event + 4` type byte, key byte at `+8`, and default/narrow byte at `+0x10a`.
- `dword_69B36C` is the documented `MainUiLayerSlots` slot. Do not replace it with `g_pMainMenuPane`; rename it later only through the shared layer-slot naming audit.
- `Close()` is the source-level `DialogPane` close/dismiss call. The compiled `this - 0xa0` adjustment belongs to the secondary input subobject ABI and should not appear in handwritten C++.

## Coverage Row Recommendations

Replace the existing [UID:0001A3] row in `by-memory/-coverage-report.md` under the `0x004ff400-0x00502cbd` login/main-menu dialog region, immediately after the `0x0050040d-0x00500410` padding row:

```markdown
    - [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md) 0x00500410-0x00500632 | class method cluster | NewHistoryDialogPaneCore : reconstructable : 87% : very strong : B003 2026-06-17 source-quality reanalysis confirms constructor/key/mouse function boundaries, internal padding spans, vtable-only input callbacks, singleton/resource composition, `HISTORYN.EPF`/`HISTORYN.PAL`/`MADEBY` operands, `DialogPane`/`Pane`/control helper roles, secondary-subobject close adjustment, event type `8` key close and event codes `3`/`6` mouse-release close behavior, corrected `dword_69B36C` plus `g_pMainUiGraph` create/show operands, raw PE no-pointer result for constructor reachability, valid [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md) owner/emitter route, and formal first-draft C++ readiness.
```

Replace the existing [UID:0001PV] row in `by-memory/-coverage-report.md` in the `.data` singleton region around `0x0069b49c`:

```markdown
    - [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md) 0x0069b49c-0x0069b4a0 | global pointer | g_pNewHistoryDialog : reconstructable : 86% : strong : Exact four-byte NewHistoryDialog singleton slot with current zeroed storage bytes, five live IDA xrefs, constructor publish/fallback clear, clear-helper/destructor clears, made-by scrolled-text close read, no direct constructor-start xrefs, saved IDA lifecycle function names, and parent `g_pNewHistoryDialog` / [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md) route.
```

No new by-memory child rows are recommended. No split was performed or needed.

## Validation Commands For Supervisor

Suggested non-mutating validation:

> Executable block R001 was removed from this report and preserved verbatim in [0001A3-new-history-dialog-pane-core-source-quality-removed.md](0001A3-new-history-dialog-pane-core-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

IDA MCP validation equivalents:

```text
lookup_funcs: 0x00500410, 0x005005c0, 0x00500610, 0x005023e0, 0x005024f8, 0x00502503, 0x00502920
analyze_function include_asm=true: 0x00500410, 0x005005c0, 0x00500610
xrefs_to: 0x00500410, 0x0069b49c, 0x0061daf4, 0x0061db54, 0x0061db84, 0x0061e4cc, 0x0061e4e8, 0x0061e504
get_bytes: 0x005005b4 size 0x0c, 0x00500605 size 0x0b, 0x0061dae8 size 0xc0, 0x0061e4b8 size 0x80
```

Raw PE pointer scan used for the reachability check:

> Executable block R002 was removed from this report and preserved verbatim in [0001A3-new-history-dialog-pane-core-source-quality-removed.md](0001A3-new-history-dialog-pane-core-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result:

```text
0x00500410 Count 0
0x005005c0 Count 1 RawOffset 0x21c55c
0x00500610 Count 1 RawOffset 0x21c558
0x005023e0 Count 0
0x00502920 Count 1 RawOffset 0x21c4f4
```

## Blockers And Next Follow-Up

No blocker prevents supervisor execution of this report. The only remaining target caveat is source-history: the current executable does not expose a direct/static constructor launch path for `0x00500410`. Further resolution likely requires dynamic tracing, original source, or a broader menu/resource script audit outside this report-only source-quality pass.

Next useful follow-up: audit and standardize the `MainUiLayerSlots` per-slot names, then replace raw operands such as `dword_69B36C` in first-draft C++ across dialog constructors.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0001A3-new-history-dialog-pane-core-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0001A3"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001A3-new-history-dialog-pane-core-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0001A3-new-history-dialog-pane-core-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001A3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
