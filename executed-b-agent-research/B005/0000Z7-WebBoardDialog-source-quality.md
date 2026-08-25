** TARGET-REPORT-UID:0000Z7 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000Z7 WebBoardDialog Constructor Source-Quality Research

Agent: B005  
Date: 2026-06-19  
Target: [UID:0000Z7] `by-memory/0x0046d050-0x0046d324.WebBoardDialog.md`  
Required scope: report-only B-preferred source-quality / heuristic-inference pass

## Final Recommendation

Raise [UID:0000Z7] from `84/88` to `88/91`, keep `RECONSTRUCTABLE:TRUE`, and change the direct owner/emitter from the file bucket [UID:0000P9] to the class owner [UID:0000G2] `WebBoardDialog`. The source file route remains [UID:0000P9] `ui/dialogs/WebBoardDialog.cpp`.

Populate first-draft C++ for `WebBoardDialog::WebBoardDialog`. The constructor is source-authored, modeled by both IDA and Ghidra as the half-open range `0x0046d050-0x0046d324`, has four ordinary constructor call sites, installs BrowserPane then WebBoardDialog vtables, stores `g_pWebBoardDialog`, creates the close button and embedded `BrowserControlPane`, and selects one of three startup paths: immediate response handling, direct URL loading, or initial opcode `0x73` board request plus timer `0x572`.

No split or range change is recommended. No direct edit to `by-memory/-coverage-report.md` was made.

## Evidence Rechecked

Primary documents and project rules re-read:

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B005/goal.md`
- `tools/leaser/Agents/Agent-B005/notes.md`
- `by-structure.md`
- `inference_research.md`
- Target [UID:0000Z7] `0x0046d050-0x0046d324.WebBoardDialog.md`
- [UID:0000G2] `by-class/WebBoardDialog.md`
- [UID:0000P9] `by-file/WebBoardDialog.md`
- [UID:0000Z8], [UID:0000Z9], [UID:00020Y], [UID:00020Z], [UID:0003V1]-[UID:0003V4], [UID:00033E]
- [UID:0000HT] `BoardDialogs`, [UID:0000HV] `Browser`, [UID:000015] `BrowserControlPane`, [UID:0000Z6] `BrowserControlPaneCore`
- [UID:0000SQ]/[UID:0002WJ] `g_pWebBoardDialog`, [UID:0001OB] `BrowserVtablesAndStrings`, [UID:0001RT] WebBoard resources
- `project-level/-auto-completion-stats.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp`
- Current `by-memory/-coverage-report.md` row context
- Executed B002 reports for WebBoardDialog virtual companions and request helpers, plus B001/B004 sibling-context notes where applicable

IDA MCP was checked through the available MCP resource list, but no live IDA resources were exposed in this session. I therefore used current exported IDA/Ghidra JSON, prior accepted live-IDA report evidence, local docs, generated source/coverage, and a direct PE byte audit against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

## Boundary / Bytes / Padding

The target range remains exactly `0x0046d050-0x0046d324`.

PE byte audit:

- File: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Constructor bytes: `0x0046d050-0x0046d324`, length `0x2d4`, raw offset `0x6c450`, SHA1 `ce6793e9f83e8de9144284e6ab04223837d7b600`
- First bytes: `55 8B EC 6A FF 68 A2 AD 5F 00 64 A1 00 00 00 00 50 83 EC 44 A1 24 2F 67 00 33 C5 89 45 F0 53 56 57 50 8D 45 F4 64 A3 00 00 00 00 8B F1 89 75 B8 8B 45 10 8B 7D 0C 6A 01 6A FF 89 45 B4 8B 45 14`
- Last bytes: `8B C6 8B 4D F4 64 89 0D 00 00 00 00 59 5F 5E 5B 8B 4D F0 33 CD E8 11 A4 15 00 8B E5 5D C2 10 00`
- The final `C2 10 00` matches a `thiscall` constructor returning with four stack arguments.

Boundary context:

- Predecessor `0x0046cfe0-0x0046d050` is not part of the constructor. It contains BrowserControlPane child-window switch/table bytes and ends with `00 CC CC CC`.
- Successor `0x0046d324-0x0046d330` is exactly twelve `0xcc` bytes of alignment padding.
- Next function starts at `0x0046d330`, matching [UID:00020Y] WebBoardDialog virtual companion/destructor range.

No half-open range split is justified. The constructor starts at the prologue at `0x0046d050` and ends at the `retn 0x10` at `0x0046d321`; the covered half-open range through `0x0046d324` is exact.

## Function Model, Callers, And Reachability

Current exported IDA/Ghidra function data confirms:

- IDA start/end/size: `0x0046d050-0x0046d324`, size `724`
- Ghidra start/end/size: `0x0046d050-0x0046d324`, size `724`
- Four code xrefs/callers:
  - `0x00508da0` from `sub_507C90`
  - `0x005145db` from `sub_514580`
  - `0x00554d76` from `sub_554C40`
  - `0x005bd0cf` from `sub_5BD000`

The constructor is not vtable-only or orphaned. It is reached by ordinary allocation plus constructor calls.

Caller breakdown:

- `0x00508da0`: packet/UI path for opcode `0x62`. In the active EPF/current-layout path, it allocates `0x37c` bytes and calls `WebBoardDialog::WebBoardDialog(0, NULL, packetPayload, NULL)`.
- `0x005145db`: active-vs-old board dialog dispatch. When the current-layout flag is set and the active browser-dialog singleton is not present, it allocates `0x37c` and calls `WebBoardDialog::WebBoardDialog(0, NULL, responsePayload, NULL)`. The old fallback calls the old WebBoardDialog constructor instead.
- `0x00554d76`: right-button/user board path. It checks `g_pWebBoardDialog`, allocates `0x37c`, calls `WebBoardDialog::WebBoardDialog(4, selectedName, NULL, NULL)`, then clears/marks the selected map object.
- `0x005bd0cf`: menu variety/user path. One branch calls `WebBoardDialog::WebBoardDialog(4, localPlayerName, NULL, NULL)`; another calls `WebBoardDialog::WebBoardDialog(0, NULL, NULL, NULL)`.

No currently observed caller passes mode `6`, but constructor-local geometry for mode `6` is real and source-shaped. It should remain in first-draft C++ as a supported/dormant layout mode, not be deleted or split.

## Constructor Behavior And Source-Facing Shape

The source-facing identity should be:

```cpp
WebBoardDialog::WebBoardDialog(int boardMode,
                               const wchar_t *boardOwnerName,
                               const void *initialResponsePacket,
                               OLECHAR *initialUrl)
```

Name certainty:

- `boardMode` is high-confidence descriptive. Values `0`, `4`, and `6` drive close-button/browser/dialog rectangles. The request branch sends it as the second byte after opcode `0x73`.
- `boardOwnerName` is high-confidence descriptive, not original-symbol-proof. It is copied with `wcscpy_s` into the fixed `0x80` wchar buffer at `this+0x27c`. Callers pass selected/local player name storage for mode `4`.
- `initialResponsePacket` is high-confidence descriptive. If non-null, the constructor immediately calls [UID:0000Z9] `0x0046d580` response handler and does not send a new request.
- `initialUrl` is high-confidence descriptive. It is passed to the `BrowserControlPane` constructor and, if no response packet exists, to the navigation helper at `0x0046bd30`.

Field/name recommendations:

- `this+0x26c`: `m_browserControlPane`, type `BrowserControlPane *`. This is validated by constructor store, [UID:00020Y] reposition/shutdown evidence, and BrowserControlPane docs.
- `this+0x278`: `m_closeButton`, type best described as `ImageButtonControlPane *` or close/command button pane. It is allocated with size `276`, constructed by `0x00495bf0` with id `30` and a mode-dependent close-button rectangle, then added as a child.
- `this+0x27c`: `m_boardOwnerName` or `m_webBoardOwnerName`, fixed `wchar_t[0x80]`. `m_boardOwnerName` is preferred because caller evidence passes selected/local player names for the personal-board mode.
- `this+0xa4`: embedded BrowserPane/Pane timer or secondary vtable subobject used by the timer start call. No new field name is needed in this constructor report; it is already represented by the inherited BrowserPane layout.
- `g_pWebBoardDialog` at `0x0067ab9c`: `WebBoardDialog *`, initialized to `-1` in storage, set by constructor, cleared by ordinary destructor/cleanup/scalar destructor.

Startup paths:

- If `initialResponsePacket != NULL`: call `WebBoardDialog::HandleBoardResponse(initialResponsePacket)` ([UID:0000Z9]).
- Else if `initialUrl != NULL`: call `BrowserControlPane::Navigate(initialUrl, NULL)` via `0x0046bd30`.
- Else: build a two-byte request with opcode `0x73`, append `boardMode`, send it through the packet/output queue at `dword_67A7EC`, and start timer `0x572` for `20000` ms on the BrowserPane timer subobject.

The constructor’s base/vtable sequence is also source-consistent:

- It calls the BrowserPane/DialogPane base constructor with an empty wide string, `-1`, and enabled/current flag `1`.
- It temporarily installs BrowserPane vtables at `this+0`, `this+0xa0`, and `this+0xa4`.
- It stores `g_pWebBoardDialog`.
- It installs WebBoardDialog vtables at the same primary/secondary subobjects.

The temporary BrowserPane vtable stores are compiler output for base construction and should not be hand-authored as explicit source statements.

## Owner / Source Placement Ranking

Accepted direct owner:

1. [UID:0000G2] `WebBoardDialog` class. The target is a class constructor, uses the WebBoardDialog vtable, writes the WebBoardDialog singleton, owns WebBoardDialog fields, and all accepted companion methods now route through this class owner. This is the narrowest correct owner.

Accepted source file route:

2. [UID:0000P9] `ui/dialogs/WebBoardDialog.cpp`. The file owns the active/old WebBoardDialog family, response parsing, request helpers, render helpers, resources, and browser-dialog integration. The constructor should emit through this file by way of the class owner.

Rejected or lower-ranked alternatives:

- `Browser` / `BrowserControlPane`: rejected as primary owner. The constructor embeds and controls a BrowserControlPane, but the board opcode, singleton, mode layout, response handler, and WebBoard-specific resources are WebBoardDialog behavior.
- `BoardDialogs`: rejected as direct owner. It is a broader source bucket for board/article dialog routing, not the class owner for this constructor.
- `DialogPane` / generic Pane support: rejected. Base constructor/child registration/visibility helpers are dependencies, while this body is a concrete WebBoardDialog constructor.
- Old `WebBoardDialogOld`: rejected. The caller dispatches choose the old constructor only in fallback paths; this target is the active BrowserControlPane-backed constructor.
- Packet/network subsystem: rejected. The constructor sends one initial request, but packet formatting is a startup branch, not ownership.
- No-owner/non-emitting fallback: rejected. The target is modeled, called, reconstructable, source-shaped, and now has a defensible source signature and C++ draft.

The current target metadata should therefore move from file-owned `CANONICAL_OWNER:0000P9` / `EMITTER_UIDS:0000P9` to class-owned `CANONICAL_OWNER:0000G2` / `EMITTER_UIDS:0000G2`. The generated output path remains `auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp`.

## First-Draft C++ Recommendation

The formal `RECONSTRUCTION_CPP CODE` block should be populated. The exact original symbol names for several common Pane helpers are not proven, but this is no longer a blocker: the constructor’s control flow, fields, parameter roles, caller arguments, singleton store, child setup, startup branches, and source owner are sufficiently constrained. The snippet below uses descriptive source-facing names and avoids compiler-only vtable writes.

```cpp
WebBoardDialog::WebBoardDialog(int boardMode,
                               const wchar_t *boardOwnerName,
                               const void *initialResponsePacket,
                               OLECHAR *initialUrl)
    : BrowserPane(L"", -1, true),
      m_browserControlPane(NULL),
      m_closeButton(NULL)
{
    g_pWebBoardDialog = this;

    if (boardOwnerName != NULL)
        wcscpy_s(m_boardOwnerName, 0x80, boardOwnerName);

    Rect closeRect;
    if (boardMode == 0 || boardMode == 4)
        closeRect.Set(318, 468, 381, 492);
    else if (boardMode == 6)
        closeRect.Set(368, 568, 431, 592);

    m_closeButton = new ImageButtonControlPane(30, closeRect);
    AddChild(m_closeButton);

    Rect browserRect;
    if (boardMode == 0)
        browserRect.Set(11, 42, 689, 460);
    else if (boardMode == 4)
        browserRect.Set(11, 42, 407, 526);
    else if (boardMode == 6)
        browserRect.Set(11, 42, 789, 560);

    m_browserControlPane = new BrowserControlPane(browserRect, initialUrl, this);
    AddChild(m_browserControlPane);

    Rect dialogRect;
    if (boardMode == 0)
        dialogRect.Set(162, 134, 862, 634);
    else if (boardMode == 4)
        dialogRect.Set(303, 101, 721, 667);
    else if (boardMode == 6)
        dialogRect.Set(112, 84, 912, 684);

    SetPaneRect(dialogRect, 0, 0, g_layoutContext_69B374);
    SetScrollOffset(0, 0);
    FinishDialogSetup();
    SetVisible(false);
    SetEnabled(false);

    if (initialResponsePacket != NULL)
    {
        HandleBoardResponse(initialResponsePacket);
    }
    else if (initialUrl != NULL)
    {
        m_browserControlPane->Navigate(initialUrl, NULL);
    }
    else
    {
        SendInitialBoardRequest(static_cast<unsigned char>(boardMode));
    }
}
```

Notes for supervisor incorporation:

- `FinishDialogSetup()` is a descriptive placeholder for `0x0049eac0`. If the support docs already standardize that helper as a different Pane/DialogPane method, use the existing standardized name.
- `SetPaneRect`, `SetScrollOffset`, `SetVisible`, `SetEnabled`, `AddChild`, `Rect::Set`, `ImageButtonControlPane`, and `BrowserControlPane::Navigate` are descriptive source-facing names. If canonical names already exist in Pane/DialogPane support docs, the formal block should use those canonical names.
- `g_layoutContext_69B374` should be replaced by the canonical name from [UID:0001PG] if the supervisor has one.

## Heuristic / Inference Reanalysis And Validation

### Constructor Versus Generated Destructor Label

Evidence checked:

- Exported IDA decompile for `0x0046d050`
- Exported Ghidra function model
- OOAnalyzer output references
- Callers allocating `0x37c` bytes then passing the returned allocation as `this`
- Vtable store sequence and return value

Rejected alternative: OOAnalyzer-style destructor labeling. It is contradicted by the base-constructor call, the BrowserPane then WebBoardDialog vtable installation, the singleton set, object allocation call sites, child creation, and `return this` behavior. The best defensible inference is a source-authored constructor. This supports raising completion and populating C++.

### Exact Range And Split Policy

Evidence checked:

- IDA/Ghidra start/end both `0x0046d050-0x0046d324`
- Direct PE bytes and SHA1
- Predecessor table/alignment and successor `0xcc` padding
- Next function at `0x0046d330`

Rejected alternatives: splitting off request setup, vtable setup, or layout setup into separate by-memory docs. The startup request branch is inline in the constructor; the separate raw helper [UID:00020Z] is a retained/source-shaped duplicate with no direct xref. No split/rename/range edit is needed.

### Source Signature

Evidence checked:

- Caller arguments at `0x00508da0`, `0x005145db`, `0x00554d76`, `0x005bd0cf`
- Constructor branches on `a2`, `a4`, `a5`
- `wcscpy_s((wchar_t *)(this+0x27c), 0x80, Source)`
- Packet branch writes `115` (`0x73`) then `boardMode`
- BrowserControlPane constructor and direct navigation branch both consume `initialUrl`

Rejected alternatives:

- Treating `a2` as a boolean: rejected because values `0`, `4`, and `6` are handled and it is sent as a byte to the server.
- Treating `Source` as URL/title generically: partially rejected. It is a wide string copied into a fixed owner/name field, and callers pass selected/local player names. `boardOwnerName` is the strongest descriptive name.
- Treating `a4` as constructor flags: rejected because it is passed directly to the response handler.
- Treating `a5` as generic COM object: rejected because it is `OLECHAR *`, passed to BrowserControlPane construction and navigation.

Final inference: `WebBoardDialog(int boardMode, const wchar_t *boardOwnerName, const void *initialResponsePacket, OLECHAR *initialUrl)`.

Impact: no source-signature blocker remains. The exact original spelling is unproven, but descriptive names are stable enough for first-draft C++ and `88/91`.

### Field Names And Type Model

Evidence checked:

- Constructor stores at `this+0x26c`, `this+0x278`, and `this+0x27c`
- [UID:00020Y] accepted companion report and C++ using `m_browserControlPane`
- BrowserControlPane docs for `+0x11c` hosted HWND and navigation state
- Singleton storage docs [UID:0000SQ]/[UID:0002WJ]

Rejected alternatives:

- `this+0x26c` as generic child pane: rejected because WebBoard virtual companions and BrowserControlPane helper calls consume it as BrowserControlPane.
- `this+0x278` as browser object: rejected because the allocation size/id and constructor `0x00495bf0` match a button/control pane, not BrowserControlPane.
- `this+0x27c` as arbitrary scratch: rejected because it is a fixed `0x80` wchar object field written from player/name call sites.

Final inference: `m_browserControlPane`, `m_closeButton`, and `m_boardOwnerName` are the best source-facing names. These names should be marked descriptive unless later original symbols are found.

Impact: field naming no longer blocks code entry.

### Helper Names And Dependencies

Evidence checked:

- Callee list and decompiled call sites
- BrowserControlPane constructor/navigation docs
- Pane/DialogPane sibling docs and accepted destructor/input reports
- Raw request-helper report [UID:00020Z]

Best defensible names:

- `0x0049d8a0`: BrowserPane/DialogPane base constructor
- `0x004b78d0`: rectangle setter/constructor
- `0x004f4aa0`: allocation helper / `operator new`
- `0x00495bf0`: close/image button control constructor
- `0x0049dc10`: child registration / `AddChild`
- `0x0046b520`: `BrowserControlPane` constructor
- `0x0049dfd0`: pane rectangle/bounds placement helper
- `0x0049e190`: scroll/origin reset helper
- `0x0049eac0`: dialog/pane final setup helper
- `0x0049dd80` / `0x0049ddd0`: visibility/enabled-style state setters
- `0x0046d580`: `WebBoardDialog::HandleBoardResponse`
- `0x0046bd30`: BrowserControlPane navigation helper
- `0x00575380`, `0x00574bb0`: packet byte writer / packet queue send path
- `0x005975e0`: timer-start helper

Rejected alternative: leaving helpers as raw `sub_` labels in formal C++. The exact original Pane helper spellings are not fully proven, but their roles are constrained enough to use project-standard descriptive names. This affects confidence, not C++ readiness.

### Mode Values And Layout

Evidence checked:

- Constructor branch rectangles for `boardMode == 0`, `4`, and `6`
- Current call sites passing `0` and `4`
- Request packet branch sending `boardMode`

Rejected alternatives:

- Deleting mode `6` as dead code: rejected because it is source-authored logic inside the constructor and has complete rectangle sets.
- Treating mode `4` as old-dialog flag: rejected because old-dialog selection is handled by caller dispatch, while mode `4` still constructs the active BrowserControlPane dialog.

Final inference: `boardMode` is a layout/request mode. Current live call sites prove modes `0` and `4`; mode `6` should be retained as dormant/supported source behavior.

Impact: layout inference supports C++ entry and should be documented in class/file pages.

### Startup Request And [UID:00020Z]

Evidence checked:

- Constructor inline request branch at `0x0046d2b7`, `0x0046d2c1`, `0x0046d2d8`, `0x0046d2ef`
- Accepted B002 report for [UID:00020Z]
- Direct constructor response-handler branch
- Direct URL navigation branch

Rejected alternative: treating the no-xref raw helper in [UID:00020Z] as the source function that must be called by the constructor. Current bytes inline the request path. The raw helper remains useful source-quality context but does not block constructor C++.

Final inference: formal constructor C++ may call `SendInitialBoardRequest(boardMode)` as a source-level factoring of the inline byte-send/timer sequence, with [UID:00020Z] documented as the retained duplicate/raw helper.

Impact: no request-helper blocker remains for [UID:0000Z7].

### Owner And Source Placement

Evidence checked:

- Target owner/emitter currently [UID:0000P9]
- [UID:00020Y], [UID:00020Z], [UID:0003V2]-[UID:0003V4], [UID:00033E] class-owned route
- [UID:0000G2] class doc and [UID:0000P9] file doc
- Browser/BoardDialogs support docs

Rejected alternatives:

- File bucket as direct owner: rejected as less precise for a class constructor, though still the correct source file route.
- Browser/BrowserControlPane owner: dependency only.
- BoardDialogs owner: broad grouping only.
- Generic Pane/DialogPane owner: base/helper only.

Final inference: `CANONICAL_OWNER:0000G2`, `EMITTER_UIDS:0000G2`, generated through [UID:0000P9].

Impact: direct owner/emitter metadata should be corrected. This is a source-quality improvement and aligns the constructor with its accepted sibling methods.

### Vtable / RTTI / Generated-Data Policy

Evidence checked:

- Constructor vtable stores
- [UID:0001OB] `BrowserVtablesAndStrings`
- [UID:00020Y] virtual companion data

Rejected alternative: hand-authoring concrete vtable stores or concrete vtable arrays in the constructor source. These are compiler-generated outputs from class declarations and virtual methods. The source declaration belongs in class/file docs; the concrete `.rdata` vtables remain non-hand-authored compiler data.

Impact: vtable evidence supports source class ownership but should not appear as explicit C++ statements.

### Generated Output Pollution

Evidence checked:

- `auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp`
- `auto-generated/-ag-memory-coverage.md`
- [UID:0000P9] generated-output notes

Current generated source already contains C++ for accepted siblings [UID:00020Y] and [UID:000212], but [UID:0000Z7] remains an empty emitter marker. This report should result in constructor C++ being populated in the same generated file. The file doc’s older note that the generated source only had active constructor/globals or no substantive output should be updated to the current state.

Impact: generated-output state supports, rather than blocks, constructor emission.

### Remaining Uncertainties

Unresolved original-symbol details:

- Exact original names for Pane helpers such as `0x0049dfd0`, `0x0049e190`, `0x0049eac0`, `0x0049dd80`, and `0x0049ddd0`
- Exact original spelling of `m_closeButton`, `m_boardOwnerName`, `boardMode`, and `SendInitialBoardRequest`
- Exact semantic label for dormant mode `6`

Evidence checked was sufficient to reject raw/generated names and infer descriptive source-facing names, but not enough to claim original symbol spellings. These residual uncertainties cap confidence below final-symbol quality, but they do not justify keeping the target at `84`, file-owned, or C++ blank.

Recommended impact:

- Completion: `88`, because the function can now emit first-draft source and has resolved owner/field/signature/source-shape blockers.
- Confidence: `91`, because byte/range/caller/callee/field evidence is strong, but exact original helper/field spellings remain inferred and live IDA MCP was unavailable during this pass.
- C++ readiness: ready for first-draft, not final-exact source.

## Support-Doc Update Plan

Recommended target [UID:0000Z7] updates:

- Header metadata:
  - `COMPLETION:88`
  - `CONFIDENCE:91`
  - `CANONICAL_OWNER:0000G2`
  - `EMITTER_UIDS:0000G2`
- Replace the medium source-placement wording with strong class ownership through [UID:0000G2] and source-file route [UID:0000P9].
- Add the PE byte audit: `0x2d4` bytes, SHA1 `ce6793e9f83e8de9144284e6ab04223837d7b600`, pre-boundary table/alignment, post-boundary twelve `0xcc` bytes.
- Add the caller breakdown for `0x00508da0`, `0x005145db`, `0x00554d76`, and `0x005bd0cf`.
- Add parameter and field recommendations:
  - `int boardMode`
  - `const wchar_t *boardOwnerName`
  - `const void *initialResponsePacket`
  - `OLECHAR *initialUrl`
  - `m_browserControlPane` at `+0x26c`
  - `m_closeButton` at `+0x278`
  - `m_boardOwnerName` at `+0x27c`
- Populate the formal constructor C++ block using the draft above, adjusted only for existing canonical helper names.

Recommended [UID:0000G2] class-doc updates:

- Update the constructor method row/signature to `WebBoardDialog::WebBoardDialog(int boardMode, const wchar_t *boardOwnerName, const void *initialResponsePacket, OLECHAR *initialUrl)`.
- Add class field notes for `m_closeButton` at `+0x278` and `m_boardOwnerName` at `+0x27c`; keep `m_browserControlPane` at `+0x26c`.
- Add a note that modes `0` and `4` are proven by callers; mode `6` is constructor-supported but currently has no observed caller in exported xrefs.

Recommended [UID:0000P9] file-doc updates:

- Keep `ui/dialogs/WebBoardDialog.cpp` as the source file route.
- Update generated-output status to say [UID:0000Z7] should now emit first-draft constructor C++ in `auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp`, alongside existing [UID:00020Y] and [UID:000212] output.
- Remove stale wording that treats the constructor’s source shape as unresolved after this pass.

Recommended [UID:00020Z] support update:

- Add that [UID:0000Z7] constructor now has an accepted `SendInitialBoardRequest(static_cast<unsigned char>(boardMode))` source-level call/factoring for the inline opcode `0x73` request branch, while [UID:00020Z] remains a retained no-xref/source-shaped helper context.

Recommended [UID:0000Z9] support update:

- Add that [UID:0000Z7] calls the response handler when `initialResponsePacket` is non-null; this is one of the two proven code-ref routes into `0x0046d580`.

Recommended [UID:0003V3] and [UID:0003V4] support cleanup:

- Replace stale unresolved resource-name blockers with the accepted B002 names:
  - content/background: `WBOARDBK.EPF` / `WBOARDBK.PAL`
  - frame/chrome: `WEBBOARD.EPF` / `WEBBOARD.PAL`

Optional metadata consistency follow-up, not required for this target:

- Review [UID:0000Z8], [UID:0000Z9], and [UID:0003V1], which still carry file-owner metadata in places while sibling bodies and docs increasingly use [UID:0000G2] for class-owned WebBoardDialog methods. Do not change them without their own scope if the supervisor wants per-target evidence.

## Exact Coverage Row Replacement

Placement context: replace the existing [UID:0000Z7] row in `by-memory/-coverage-report.md` between the ignored `0x0046cfe0-0x0046d050` row and the ignored `0x0046d324-0x0046d330` padding row.

Exact replacement row:

```markdown
    - [UID:0000Z7][0x0046d050-0x0046d324.WebBoardDialog](by-memory/0x0046d050-0x0046d324.WebBoardDialog.md) 0x0046d050-0x0046d324 | class constructor | WebBoardDialog : reconstructable : 88% : very strong : B005 2026-06-19 source-quality reanalysis confirms exact `0x2d4` constructor bytes, SHA1 `ce6793e9f83e8de9144284e6ab04223837d7b600`, pre-boundary switch-table/`0xcc` alignment at `0x0046cfe0-0x0046d050`, post-boundary `0x0046d324-0x0046d330` `0xcc` padding, four constructor callers `0x00508da0`/`0x005145db`/`0x00554d76`/`0x005bd0cf`, direct class owner [UID:0000G2] routed through [UID:0000P9], `g_pWebBoardDialog` singleton store, BrowserPane/WebBoardDialog vtable setup, `m_browserControlPane` at `+0x26c`, close button at `+0x278`, owner-name buffer at `+0x27c`, mode-dependent rectangles for modes `0`/`4`/`6`, immediate-response/direct-URL/request startup branches, opcode `0x73` two-byte request and timer `0x572`/`20000`, rejected Browser/BoardDialogs/Ranking/DialogPane ownership alternatives, and accepted first-draft constructor C++ with descriptive source-facing names.
```

## Validation / Tool Evidence

Commands and checks performed:

- `Get-Content` / `rg` reads across target, class, file, sibling by-memory docs, globals, resource docs, generated source, generated coverage, and project stats.
- `list_mcp_resources` returned no exposed IDA MCP resources in this session.
- Exported function JSON read from `resources/exported_data/functions/0x0046d050.json` and combined function exports for caller/callee validation.
- PE byte audit against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` using `FileShare.ReadWrite`, confirming raw offsets, byte prefixes/suffixes, padding, and SHA1.
- Report-only change was written; no by-memory coverage or by-* support docs were edited, so repository validation scripts were not run.

## Changed Files

- Added this report:
  - `tools/leaser/Agents/Agent-B005/research/0000Z7-WebBoardDialog-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0000Z7-WebBoardDialog-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"0000Z7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
