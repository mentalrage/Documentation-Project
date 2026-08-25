** TARGET-REPORT-UID:0000K5 **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0000K5] IMEPanes Empty-Emitter Family Source-Quality Report

## Report Metadata

- Agent: Agent-B008
- Assignment: `B008-revise-0000K5-IMEPanes-empty-emitter-family-20260630`
- Mode: same-report revision, report-only. No by-* docs, generated files, coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, or lock files were edited.
- Target: [UID:0000K5] `by-file/IMEPanes.md`
- Generated unit: `auto-generated/NexusTK/input/IMEPanes.cpp`
- Report path: `tools/leaser/Agents/Agent-B008/research/0000K5-IMEPanes-empty-emitter-family-source-quality.md`
- MCP session used for revision: `supervisor_resume_20260629`

## Final Recommendation

[UID:0000K5] `IMEPanes` is a real pane-side IME source family. The previous report correctly identified the strong `g_pIMEPane` evidence and the stale singleton-storage initializer, but it used broad no-code/comment dispositions for several source-authored class and method rows. This revision resolves those score blockers under `score-blocker-audit-standard.md`.

Implementation callback should now make these concrete changes:

1. Add declaration-level class shells with `[[CHILDREN]]` for [UID:00006F] `IMECandidatePane`, [UID:00006G] `IMECompositionPane`, [UID:00006H] `IMEPane`, and [UID:00006I] `IMEStatusPane`. These class pages are not no-code deferrals; they should emit source-facing declarations, fields, method prototypes, and child insertion points.
2. Populate first-draft formal C++ for [UID:00018B] `IMECandidatePane::ShowCandidateList` using the current MCP decompile, B001 producer-side Event evidence, and existing candidate-deque support docs.
3. Populate source-level formal C++ for [UID:00031F] `IMECandidatePane::~IMECandidatePane()` as an ordinary destructor body. The binary cleanup of the candidate deque and base pane is the compiler output for member/base destruction, so the source body is intentionally minimal, not blank.
4. Keep scalar deleting destructor wrappers [UID:00031I], [UID:00031J], [UID:00031K], and [UID:00031L] as target-specific no-source-body rows. The proof is wrapper-specific: current MCP shows vtable restores, adjustor/vtable xrefs, optional delete-flag behavior, and no normal handwritten source caller route. These should get formal proof comments or remain blank only if the support page text is updated to explain the compiler-wrapper disposition.
5. Treat [UID:00031G] `0x004e8110` as a rare no-code raw-helper exception with proof. Current MCP still reports no direct xrefs to `0x004e8110`; the body duplicates the focus-caret anchor refresh already emitted inline by [UID:00018A]. Emitting a callable helper would invent a source route, while a formal covered-inline proof preserves the range.
6. Emit the real global declaration for [UID:0000R7] as `IMEPane *g_pIMEPane = NULL;`, and update [UID:0001PS] to a covered-by storage marker with current zero/null evidence. The older `ff ff ff ff` / `0xffffffff` wording is stale for the active IDB.
7. Reclassify [UID:00031H] as compiler/static-lifetime cleanup support with `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++. Do not raise its score while making it non-reconstructable.
8. Keep [UID:00025J] as source-declared/generated-binary vtable/RTTI/string data with a formal no-raw-table proof. Do not hand-author vtable arrays or duplicate the `Closed`/`IME`/`ENG` literals outside the class/method source that uses them.
9. Convert [UID:000189] from a blank aggregate emitter into an implementation-ready split/order plan: add a formal aggregate marker with `[[CHILDREN]]`, document that exact child pages own method bodies, and create the exact child pages listed in the split plan during callback if the supervisor accepts split work in that callback.

With these repairs, the root [UID:0000K5] can move from `89/86` to `90/88`. It should not move higher in this pass because many contained IME methods still need exact child pages and first-draft method-body review, but those blockers are now concrete implementation items rather than unresolved deferrals.

## Current Target State

- `by-file/IMEPanes.md` current metadata: `COMPLETION:89`, `CONFIDENCE:86`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/input/"`, `CANONICAL_OWNER:FILE`.
- Queue row: [UID:0000K5] `IMEPanes` has `17` total emitters, `1` filled, `16` empty, `5.9%`, generated path `auto-generated/NexusTK/input/IMEPanes.cpp`.
- Generated `IMEPanes.cpp` read-only snapshot: `validator-command-id: 000000002660`, `validator-refreshed-at: 2026-06-30T07:03:51-04:00`, source by-file UID `0000K5`.
- Generated `IMEPanes.cpp` currently emits [UID:00018A] `IMECompositionPane::SetCompositionString` and shows empty markers for [UID:00006F], [UID:00018B], [UID:00031F], [UID:00031I], [UID:00006G], [UID:00031J], [UID:00006H], [UID:00031G], [UID:00031K], [UID:00006I], [UID:00031L], [UID:0000R7], [UID:0001PS], [UID:000189], [UID:00031H], and [UID:00025J].
- Current [UID:00018A] C++ is already populated and remains out of scope for rewrite. It uses the root `IMEPane` fields `focusPaneList`, `focusPaneCount`, `focusCaretAnchorX`, and `focusCaretAnchorY`, so [UID:00006H] must provide a compatible class declaration shell.
- Current [UID:0001PS] still says the storage bytes are `ff ff ff ff` / `0xffffffff`. Current MCP `get_bytes`, `get_int`, and `get_global_value` prove zero/null for `0x0069b458`.

## Evidence Checked

### Project Documents And Generated Inputs

- Read `goal.md`, `ntk-b-agent-workflow/SKILL.md`, `b-agent-research-and-implementation-workflow.md`, `supervisor-rule26-review-and-incorporation-standard.md`, `score-blocker-audit-standard.md`, and `b-agent-report-template.md`.
- Read `by-structure.md` IDA MCP discipline and reconstruction-code gate text, plus `by-file/-guidance.md`, `by-class/-guidance.md`, `by-memory/-guidance.md`, and `by-global/-guidance.md`.
- Re-read `by-file/IMEPanes.md` and generated `auto-generated/NexusTK/input/IMEPanes.cpp`.
- Re-read support docs for [UID:00006F], [UID:00006G], [UID:00006H], [UID:00006I], [UID:00018A], [UID:00018B], [UID:00031F], [UID:00031G], [UID:00031H], [UID:00031I], [UID:00031J], [UID:00031K], [UID:00031L], [UID:0000R7], [UID:0001PS], [UID:000189], [UID:00025J], [UID:00001G], and [UID:0001WO].
- Old report search terms retained from the first pass: `0000K5`, `IMEPanes`, `0x004e7930`, `0x004e7470`, `0x0069b458`, `0x004e85b0`, and `IMEPane`.
- Relevant executed reports retained as leads: B003 [UID:00018A], B001 [UID:00018B], B001 [UID:00018E] InputMan, B008 [UID:00014C] EventMan/Event factory helpers, B008 [UID:0002RV], B008 [UID:0002H8], and B007 [UID:0002H7].
- Checked accepted `[[CHILDREN]]` class-shell precedents such as `ChattingVarietyPane`, `TextEditPane`, `VoteMenuPane`, and `ThreadMan`.

### Current MCP Calls

MCP was available. No fallback-only evidence was used.

| Call | Result |
| --- | --- |
| `initialize` | `ida-pro-mcp`, protocol `2025-06-18`. |
| `tools/list` | 65 tools available. Relevant current schemas require `database=supervisor_resume_20260629` for inspection calls. |
| `idb_list` | One active worker session `supervisor_resume_20260629`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, pid/worker_pid `24256`. |
| `server_health` | `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, strings cache ready. |
| `lookup_funcs` | `0x004e7930` size `0x23c`; `0x004e7cb0` and `0x004e8110` are not function starts; `0x004e85b0` size `0xb`; scalar deleting destructor starts/sizes: `0x004e8640` `0x7f`, `0x004e86c0` `0x55`, `0x004e8720` `0xd9`, `0x004e8800` `0x55`; status methods `0x004e70f0` `0xcc`, `0x004e71c0` `0xca`, `0x004e72b0` `0x48`, `0x004e7300` `0x7b`. |
| `xrefs_to` | `0x004e7930` has one code xref at `0x004e7d13`; `0x004e7cb0` has no xrefs; `0x004e8110` has no xrefs; `0x004e85b0` has one cleanup-table reference at `0x00600586`; `0x0069b458` has 17 data xrefs across IME/text/startup/shutdown paths. |
| `decompile 0x004e7930` | Confirms `ShowCandidateList` reads Event `+0x08`, iterates candidate deque range `+0x0c/+0x10`, measures each wide string, builds/clamps popup geometry, uses `g_pIMEPane+0xfc` active child fallback, range-assigns to `this+0xf8`, stores Event `+0x0c` into `this+0x10c`, and invalidates. |
| `disasm 0x004e7cb0` | Raw destructor body restores `IMECandidatePane` vtables, calls `0x004e8a00` on `this+0xf8`, frees stored queue map with `0x005c7526`, nulls `this+0xf8`, and tail-jumps to base pane teardown `0x00544580`. |
| `disasm 0x004e8110` | Raw helper reads `focusPaneCount` at `+0x110`, indexes `focusPaneList` at `+0x104`, calls text-entry caret/local/screen-origin helpers, writes `focusCaretAnchorX` at `+0x11c` and `focusCaretAnchorY` at `+0x118`, or clears both when no focus pane exists. |
| `analyze_function 0x004e85b0` | One-block function `unk_69B458 = 0`, no callees, cleanup-table ref only. |
| `analyze_function` scalar destructors | Confirms vtable restores, adjustor/vtable xrefs, member/base cleanup, optional delete flag handling for [UID:00031I], [UID:00031J], [UID:00031K], and [UID:00031L]. |
| `decompile 0x004e70f0` / `0x004e71c0` / `0x004e72b0` | Confirms `IMEStatusPane::SetText` copies into `this+0xf8` with 256 wchar capacity, constructor clears `0x200` bytes at `+0xf8` and sets `Closed`, mode-change uses Event type `11` and chooses `IME` or `ENG`. |
| `get_bytes/get_int/get_global_value` | `0x0069b458` bytes are `00 00 00 00`; `u32le=0`; `0x0069b458`, `dword_69B458`, and `unk_69B458` all read `0x0`. |
| `entity_query/get_string` | `0x0061c360-0x0061c5a0` has 15 named heads: twelve IME pane vtable bases plus `aClosed`, `aIme`, and `aEng`; strings decode as `Closed`, `IME`, and `ENG`. |

## Heuristic / Inference Reanalysis And Validation

The previous rejection was correct: "declarations are not coordinated" is not a final disposition for current in-scope source-authored targets. The revised outcome is:

- Class pages are no longer marker-only. Each class page has enough current field/method evidence to emit a declaration-level shell with `[[CHILDREN]]`. Exact method bodies remain on exact by-memory children.
- [UID:00018B] no longer stays blank for Event/Pane spelling reasons. Current MCP and B001 evidence support a first-draft formal body using inferred source-facing names: `Event::imeCandidateStrings`, `Event::imeCandidateSelectedRow`, `CandidateStringList`, `candidateAnchorX`, `candidateAnchorY`, `visibleCandidates`, and `selectedCandidateRow`.
- [UID:00031F] no longer stays blank for member/base naming reasons. It should emit the source destructor body, with the compiler responsible for candidate-string container and Pane base destruction.
- [UID:00031G] remains no-code only because current MCP proves a target-specific no-route case: no xrefs to `0x004e8110`, no IDA function object, same behavior duplicated inline by [UID:00018A]. A separate helper call would invent a route.
- Scalar deleting destructors are not source-authored methods. They are generated ABI wrappers from class virtual destructors and should not emit handwritten C++.
- [UID:000189] is not a method body. It needs an implementation-ready split/order plan, not a generic future-work list or a blank emitter.

The best-supported source-facing names are inferred but defensible. Lack of original symbol proof is not a blocker because the behavior, offsets, owner route, and dependency direction are current-MCP-backed and align with existing accepted first-draft C++ in [UID:00018A].

## Empty Emitter Inventory And Revised Disposition

| UID | Current marker | Revised disposition |
| --- | --- | --- |
| `00006F` | `by-class/IMECandidatePane.md` | Emit declaration shell with `CandidateStringList`, `visibleCandidates`, `selectedCandidateRow`, `candidateAnchorY` at `+0x110`, `candidateAnchorX` at `+0x114`, method prototypes, and `[[CHILDREN]]`. |
| `00018B` | `by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md` | Emit first-draft formal `void IMECandidatePane::ShowCandidateList(const Event *event)` C++. |
| `00031F` | `by-memory/0x004e7cb0-0x004e7cfc.IMECandidatePaneOrdinaryDestructor.md` | Emit source-level `IMECandidatePane::~IMECandidatePane()` body. |
| `00031I` | `by-memory/0x004e8640-0x004e86bf.IMECandidatePaneScalarDeletingDestructor.md` | Formal no-source-body proof for compiler scalar deleting destructor wrapper. |
| `00006G` | `by-class/IMECompositionPane.md` | Emit declaration shell compatible with [UID:00018A], including `compositionCursorX`, `compositionText[256]`, prototypes, and `[[CHILDREN]]`. |
| `00031J` | `by-memory/0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor.md` | Formal no-source-body proof for compiler scalar deleting destructor wrapper. |
| `00006H` | `by-class/IMEPane.md` | Emit declaration shell with friends, `activeChildPane`, `focusPaneList`, `focusPaneCount`, `focusCaretAnchorY`, `focusCaretAnchorX`, prototypes, and `[[CHILDREN]]`. |
| `00031G` | `by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md` | Rare no-code raw-helper proof: no direct xrefs, no function object, behavior covered inline by [UID:00018A]; do not invent helper call route. |
| `00031K` | `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` | Formal no-source-body proof for compiler scalar deleting destructor wrapper. |
| `00006I` | `by-class/IMEStatusPane.md` | Emit declaration shell with `statusText[256]` at `+0xf8`, `SetText`, mode-change/paint prototypes, and `[[CHILDREN]]`. |
| `00031L` | `by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md` | Formal no-source-body proof for compiler scalar deleting destructor wrapper. |
| `0000R7` | `by-global/g_pIMEPane.md` | Emit `IMEPane *g_pIMEPane = NULL;`. |
| `0001PS` | `by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md` | Covered-by marker and current zero/null evidence; stale `0xffffffff` historicalized/rejected. |
| `000189` | `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md` | Aggregate split/order plan with `[[CHILDREN]]`; create exact child pages for remaining unsplit source-authored methods during callback if accepted. |
| `00031H` | `by-memory/0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper.md` | Reclassify `RECONSTRUCTABLE:FALSE`, blank emitters, blank C++; compiler/static cleanup support covered by global/class lifetime. |
| `00025J` | `by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md` | Formal no-raw-table proof for vtable/RTTI island and pooled status string literals. |

## Exact Formal Blocks For Implementation Callback

Use the following as exact insertion text for the formal `RECONSTRUCTION_CPP CODE` block of each listed target unless the row explicitly says metadata-only.

### [UID:00006F] IMECandidatePane

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class IMEPane;
class Pane;
struct RectBounds;

typedef std::deque<std::wstring> CandidateStringList;

class IMECandidatePane : public Pane
{
public:
    IMECandidatePane();
    virtual ~IMECandidatePane();

    void ShowCandidateList(const Event *event);

protected:
    virtual bool HandleIMEMessage(const Event *event);
    virtual void OnPaint();

private:
    CandidateStringList visibleCandidates;  // +0xf8, display-side visible candidate strings.
    int selectedCandidateRow;               // +0x10c, selected row within the visible page.
    int candidateAnchorY;                   // +0x110, top anchor copied from the root IME pane.
    int candidateAnchorX;                   // +0x114, left anchor copied from the root IME pane.
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00018B] IMECandidateShowCandidateList

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void IMECandidatePane::ShowCandidateList(const Event *event)
{
    const CandidateStringList *candidateStrings = event->imeCandidateStrings;
    const int selectedRow = event->imeCandidateSelectedRow;

    int maxTextWidth = 0;
    int popupHeight = 4;
    const int lineStep = GetLineHeight() + 2;

    for (CandidateStringList::const_iterator it = candidateStrings->begin();
         it != candidateStrings->end();
         ++it) {
        const std::wstring &candidate = *it;
        const int textWidth = MeasureTextWidth(candidate.c_str(), static_cast<int>(candidate.length()));
        if (maxTextWidth < textWidth) {
            maxTextWidth = textWidth;
        }
        popupHeight += lineStep;
    }

    RectBounds popupRect;
    popupRect.left = candidateAnchorX;
    popupRect.top = candidateAnchorY;
    popupRect.right = candidateAnchorX + maxTextWidth + 6;
    popupRect.bottom = candidateAnchorY + popupHeight;

    const int screenWidth = g_pScreenPane->GetScreenWidth();
    const int screenHeight = g_pScreenPane->GetScreenHeight();

    if (popupRect.right >= screenWidth) {
        TranslateRectBounds(&popupRect, screenWidth - popupRect.right, 0);
    }

    if (popupRect.bottom >= screenHeight) {
        if (g_pIMEPane->activeChildPane != NULL) {
            RectBounds activeChildRect;
            g_pIMEPane->activeChildPane->GetBounds(&activeChildRect);
            TranslateRectBounds(&popupRect, 0, activeChildRect.top - popupRect.bottom - 8);
        } else {
            TranslateRectBounds(&popupRect, 0, screenHeight - popupRect.bottom);
        }
    }

    if (popupRect.left < 0) {
        TranslateRectBounds(&popupRect, -popupRect.left, 0);
    }

    SetBounds(&popupRect, 0);

    visibleCandidates.assign(candidateStrings->begin(), candidateStrings->end());
    selectedCandidateRow = selectedRow;
    Invalidate(&bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00031F] IMECandidatePaneOrdinaryDestructor

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
IMECandidatePane::~IMECandidatePane()
{
    // CandidateStringList member storage and Pane base state are destroyed by normal C++ teardown.
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00031I] IMECandidatePaneScalarDeletingDestructor

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-generated scalar deleting destructor for IMECandidatePane.
// Current MCP shows only vtable restoration, candidate-string member/base cleanup,
// adjustor/vtable xrefs, and optional delete-flag handling. Source output is covered
// by IMECandidatePane::~IMECandidatePane() and the IMECandidatePane class declaration.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00006G] IMECompositionPane

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class IMEPane;
class Pane;

class IMECompositionPane : public Pane
{
public:
    IMECompositionPane();
    virtual ~IMECompositionPane();

    void SetCompositionString(const wchar_t *text, int length);
    int GetCompositionWidth() const;

protected:
    virtual bool OnMouseEvent(const Event *event);
    virtual bool OnKeyEvent(const Event *event);
    virtual void OnPaint();

private:
    int compositionCursorX;        // +0xf8, cached cursor pixel offset.
    wchar_t compositionText[256];  // +0xfc, bounded UTF-16 composition text.
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00031J] IMECompositionPaneScalarDeletingDestructor

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-generated scalar deleting destructor for IMECompositionPane.
// Current MCP shows vtable restoration, Pane base teardown, adjustor/vtable xrefs,
// and optional delete-flag handling. Source output is the class virtual destructor,
// not a handwritten scalar-deleting-destructor method.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00006H] IMEPane

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class IMECandidatePane;
class IMECompositionPane;
class IMEStatusPane;
class List;
class Pane;

class IMEPane : public Pane
{
    friend class IMECandidatePane;
    friend class IMECompositionPane;

public:
    IMEPane();
    virtual ~IMEPane();

    void SetFocusPane(Pane *pane);
    bool IsIMESupported() const;
    bool HandleIMEMessage(const Event *event);

private:
    Pane *activeChildPane;       // +0xfc, active composition/candidate child or popup anchor.
    List focusPaneList;          // +0x104, focused text-entry panes.
    int focusPaneCount;          // +0x110.
    int focusCaretAnchorY;       // +0x118.
    int focusCaretAnchorX;       // +0x11c.
};

extern IMEPane *g_pIMEPane;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00031G] IMEPaneFocusCaretAnchorHelper

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Rare no-code raw-helper proof for 0x004e8110.
// Current MCP reports no function object and no direct xrefs to this start. The bytes
// refresh IMEPane::focusCaretAnchorX/Y from the last focused text-entry pane, but the
// same source behavior is already emitted inline by IMECompositionPane::SetCompositionString.
// Emitting IMEPane::UpdateFocusCaretAnchor() here would invent a call route and duplicate
// behavior that the current IDB does not prove reachable as a standalone helper.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00031K] IMEPaneScalarDeletingDestructor

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-generated scalar deleting destructor for IMEPane.
// Current MCP shows child-pane cleanup, focus-list teardown, g_pIMEPane clearing,
// Pane base teardown, adjustor/vtable xrefs, and optional delete-flag handling.
// Source output is covered by IMEPane::~IMEPane(), owned members, and the IMEPane
// class declaration.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00006I] IMEStatusPane

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class Pane;

class IMEStatusPane : public Pane
{
public:
    IMEStatusPane();
    virtual ~IMEStatusPane();

    void SetText(const wchar_t *text, int length);

protected:
    virtual bool OnIMEModeChange(const Event *event);
    virtual void OnPaintFrame();

private:
    wchar_t statusText[256];  // +0xf8, cleared as 0x200 bytes and copied with a 255-char cap.
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00031L] IMEStatusPaneScalarDeletingDestructor

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-generated scalar deleting destructor for IMEStatusPane.
// Current MCP shows status-pane vtable restoration, Pane base teardown, adjustor/vtable
// xrefs, and optional delete-flag handling. Source output is the class virtual destructor,
// not a handwritten scalar-deleting-destructor method.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0000R7] g_pIMEPane

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
IMEPane *g_pIMEPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0001PS] g_pIMEPane exact storage

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Storage for g_pIMEPane is emitted by [UID:0000R7][g_pIMEPane](by-global/g_pIMEPane.md)
// as `IMEPane *g_pIMEPane = NULL;`. Current MCP bytes at 0x0069b458 are zero/null;
// older `ff ff ff ff` / `0xffffffff` wording is stale for the active IDB.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:000189] IMEPaneFamily

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// IMEPaneFamily is the split/order container for the IMEStatusPane,
// IMECompositionPane, IMECandidatePane, and IMEPane method cluster.
// Exact method bodies belong on class or exact by-memory children; this aggregate
// must not emit one broad source body for 0x004e70f0-0x004e8433.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00031H] IMEPaneSingletonClearHelper

Recommended metadata-only reclassification:

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

No-code proof: current MCP `analyze_function 0x004e85b0` decompiles to only `unk_69B458 = 0`, has no callees, and has one cleanup-table reference at `0x00600586`, not a normal source caller. Source-visible state is covered by [UID:0000R7] `g_pIMEPane`, `IMEPane` construction/destruction, and the class declaration.

### [UID:00025J] IMEPaneReadOnlyData

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// IME pane RTTI/vtable data is source-declared/generated-binary output from
// IMEStatusPane, IMECompositionPane, IMECandidatePane, and IMEPane declarations.
// The Closed/IME/ENG labels are source string literals used by IMEStatusPane.
// Do not hand-author this .rdata island as a standalone table.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Implementation-Ready Split / Source-Placement Plan For [UID:000189]

[UID:000189] must not remain a blank aggregate body. The callback should add the aggregate `[[CHILDREN]]` marker above and, if the supervisor accepts split work in this callback, create exact child pages for the remaining unsplit source-authored methods below. These child pages should route through the listed class owners and [UID:0000K5] by the class route. Initial C++ should be added only where the new child page clears the active code gate during that callback; otherwise the child page records exact source-placement evidence and stays below code-entry until a child-specific pass.

| Proposed child range | Proposed name | Direct owner/emitter route | Initial disposition |
| --- | --- | --- | --- |
| `0x004e70f0-0x004e71bc` | `IMEStatusPaneSetText` | [UID:00006I] -> [UID:0000K5] | Source-authored status text helper; current MCP already supports `statusText[256]`, text measure, screen placement, and invalidate. |
| `0x004e71c0-0x004e728a` | `IMEStatusPaneConstructor` | [UID:00006I] -> [UID:0000K5] | Constructor clears `statusText[256]`, sets `Closed`, attaches hidden pane. |
| `0x004e7290-0x004e72af` | `IMEStatusPaneOrdinaryDestructor` | [UID:00006I] -> [UID:0000K5] | Ordinary destructor/source class teardown; not a scalar wrapper. |
| `0x004e72b0-0x004e72f8` | `IMEStatusPaneOnIMEModeChange` | [UID:00006I] -> [UID:0000K5] | Event type `11`, chooses `IME` or `ENG`. |
| `0x004e7300-0x004e737b` | `IMEStatusPaneOnPaintFrame` | [UID:00006I] -> [UID:0000K5] | Paints compact status label. |
| `0x004e7380-0x004e744d` | `IMECompositionPaneConstructor` | [UID:00006G] -> [UID:0000K5] | Constructor clears `compositionText[256]`, attaches root. |
| `0x004e7450-0x004e746f` | `IMECompositionPaneOrdinaryDestructor` | [UID:00006G] -> [UID:0000K5] | Ordinary destructor/source class teardown. |
| `0x004e7640-0x004e7809` | `IMECompositionPaneOnMouseEvent` | [UID:00006G] -> [UID:0000K5] | Drag/visibility/mode event handling. |
| `0x004e7810-0x004e7838` | `IMECompositionPaneOnKeyEvent` | [UID:00006G] -> [UID:0000K5] | Event byte `13`, calls [UID:00018A]. |
| `0x004e7840-0x004e7912` | `IMECompositionPaneOnPaint` | [UID:00006G] -> [UID:0000K5] | Paints composition text/caret using `compositionCursorX`. |
| `0x004e7920-0x004e7927` | `IMECompositionPaneGetCompositionWidth` | [UID:00006G] -> [UID:0000K5] | Tiny accessor for cached width/cursor x. |
| `0x004e7b70-0x004e7cae` | `IMECandidatePaneConstructor` | [UID:00006F] -> [UID:0000K5] | Constructor initializes candidate deque and anchor state. |
| `0x004e7d00-0x004e7d24` | `IMECandidatePaneHandleIMEMessage` | [UID:00006F] -> [UID:0000K5] | Event type `15`, calls [UID:00018B] after `this-0xa0` adjustment. |
| `0x004e7d30-0x004e7f1a` | `IMECandidatePaneOnPaint` | [UID:00006F] -> [UID:0000K5] | Paints candidate popup rows/highlight. |
| `0x004e7f20-0x004e7ff5` | `IMEPaneConstructor` | [UID:00006H] -> [UID:0000K5] | Root singleton constructor publishes `g_pIMEPane`. |
| `0x004e8000-0x004e8098` | `IMEPaneOrdinaryDestructor` | [UID:00006H] -> [UID:0000K5] | Deletes child panes, destroys focus list, clears singleton. |
| `0x004e80a0-0x004e810b` | `IMEPaneSetFocusPane` | [UID:00006H] -> [UID:0000K5] | Maintains focus list for text controls. |
| `0x004e81a0-0x004e81a5` | `IMEPaneIsIMESupported` | [UID:00006H] -> [UID:0000K5] | Returns true. |
| `0x004e81b0-0x004e8433` | `IMEPaneHandleIMEMessage` | [UID:00006H] -> [UID:0000K5] | Creates/deletes composition/candidate/status children and dispatches candidate messages. |

Rejected aggregate alternatives:

- One broad first-draft C++ body for [UID:000189] is invalid because the range contains many distinct methods/classes plus switch/padding boundaries.
- A plain no-code comment without split plan is invalid under the score-blocker standard.
- Moving the aggregate to `InputMan` is rejected because InputMan produces IME events but does not own pane display, singleton state, vtables, or popups.
- Leaving unsplit methods as generic "future work" is rejected; the exact ranges and owner routes above are implementation-ready child-page creation instructions.

## Recommended Target And Support Doc Changes

- `by-file/IMEPanes.md`: add a generated-output/source-emission audit noting current generated file `000000002660`, current MCP session `supervisor_resume_20260629`, the one populated marker [UID:00018A], and the revised dispositions for all sixteen empty markers. Recommended score after callback: `COMPLETION:90`, `CONFIDENCE:88`.
- `by-class/IMECandidatePane.md`: insert the exact class-shell formal block, set `EMITTER_POSITION_OPTIONAL:0`, update observed field order to `candidateAnchorY +0x110` and `candidateAnchorX +0x114`, and raise to `87/90`.
- `by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md`: replace the review-only/no-body language with the exact formal C++ body above, retain the B001 Event producer route, and raise to `89/91`.
- `by-memory/0x004e7cb0-0x004e7cfc.IMECandidatePaneOrdinaryDestructor.md`: insert the exact destructor C++ body, revise notes to source-level destructor/member/base teardown, and raise to `87/91`.
- `by-memory/0x004e8640-0x004e86bf.IMECandidatePaneScalarDeletingDestructor.md`: insert the scalar-wrapper proof comment, keep owner/emitter unless supervisor prefers blank emitter policy, and raise to `86/91`.
- `by-class/IMECompositionPane.md`: insert the exact class-shell formal block with `[[CHILDREN]]`, set `EMITTER_POSITION_OPTIONAL:0`, preserve [UID:00018A] populated method, and raise to `87/90`.
- `by-memory/0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor.md`: insert the scalar-wrapper proof comment and raise to `86/90`.
- `by-class/IMEPane.md`: insert the exact class-shell formal block, set `EMITTER_POSITION_OPTIONAL:0`, preserve root fields compatible with [UID:00018A], and raise to `88/91`.
- `by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md`: insert the rare no-code raw-helper proof comment, preserve no-xref evidence, and raise to `86/90`.
- `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md`: insert the scalar-wrapper proof comment and raise to `86/91`.
- `by-class/IMEStatusPane.md`: insert the exact class-shell formal block with `statusText[256]`, set `EMITTER_POSITION_OPTIONAL:0`, add current MCP SetText/constructor/mode-change proof, and raise to `88/90`.
- `by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md`: insert the scalar-wrapper proof comment and raise to `86/90`.
- `by-global/g_pIMEPane.md`: insert formal `IMEPane *g_pIMEPane = NULL;`, update current zero/null evidence, and raise to `90/90`.
- `by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md`: replace stale current `0xffffffff` wording with current zero/null evidence, preserve older `ff ff ff ff` as superseded historical evidence only, insert covered-by marker, and raise to `88/91`.
- `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`: insert the aggregate `[[CHILDREN]]` marker, add the split table above, and keep score conservative at `87/90`.
- `by-memory/0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper.md`: reclassify to `RECONSTRUCTABLE:FALSE`, blank emitters, blank C++, preserve score `85/92`, and update notes to compiler/static cleanup support.
- `by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md`: insert the formal no-raw-table proof comment and keep or raise only slightly to `88/92`.

No manual generated file, generated report, or manual `-coverage-report.md` edit is recommended. Validator-owned generated files/reports should refresh from by-* changes only.

## Score And Metadata Recommendation

| UID | Before | After | Rationale |
| --- | --- | --- | --- |
| `0000K5` | `89/86`, file root | `90/88`, file root unchanged | Empty-marker blockers become first-draft C++, class shells, target-specific no-code proofs, or split plan. Not higher because many split children remain pending. |
| `00006F` | `85/89`, true, owner/emitter `0000K5` | `87/90`, true, owner/emitter unchanged, position `0` | Class shell with `[[CHILDREN]]`, corrected candidate anchor order, child route preserved. |
| `00018B` | `87/90`, true, owner/emitter `00006F`, blank C++ | `89/91`, formal first-draft C++ | Current MCP decompile plus B001 Event route resolves previous C++ blocker. |
| `00031F` | `85/90`, true, owner/emitter `00006F`, blank C++ | `87/91`, formal destructor C++ | Source-level ordinary destructor can be represented; compiler emits member/base teardown. |
| `00031I` | `85/90`, true, owner/emitter `00006F`, blank C++ | `86/91`, formal no-source-body proof | Compiler scalar deleting destructor wrapper, not handwritten source. |
| `00006G` | `85/88`, true, owner/emitter `0000K5` | `87/90`, true, owner/emitter unchanged, position `0` | Declaration shell now supports [UID:00018A] child and field names. |
| `00031J` | `85/89`, true, owner/emitter `00006G`, blank C++ | `86/90`, formal no-source-body proof | Compiler scalar deleting destructor wrapper. |
| `00006H` | `85/90`, true, owner/emitter `0000K5` | `88/91`, true, owner/emitter unchanged, position `0` | Root class shell resolves focus fields and child/g_pIMEPane access. |
| `00031G` | `85/89`, true, owner/emitter `00006H`, blank C++ | `86/90`, formal rare no-code proof | No xrefs/no function object; source-equivalent behavior already inline in [UID:00018A]. |
| `00031K` | `85/90`, true, owner/emitter `00006H`, blank C++ | `86/91`, formal no-source-body proof | Compiler scalar deleting destructor wrapper. |
| `00006I` | `86/89`, true, owner/emitter `0000K5` | `88/90`, true, owner/emitter unchanged, position `0` | `statusText[256]` is now proven by current MCP SetText/constructor evidence. |
| `00031L` | `85/89`, true, owner/emitter `00006I`, blank C++ | `86/90`, formal no-source-body proof | Compiler scalar deleting destructor wrapper. |
| `0000R7` | `88/86`, true, owner/emitter `0000K5`, blank C++ | `90/90`, formal `IMEPane *g_pIMEPane = NULL;` | Current zero/null storage and lifecycle xrefs prove initializer/source route. |
| `0001PS` | `86/90`, true, owner/emitter `0000R7`, stale `0xffffffff` text | `88/91`, true, owner/emitter unchanged, covered-by marker | Current active IDB bytes/value are zero/null; old bytes historicalized. |
| `000189` | `86/90`, true, owner/emitter `0000K5`, blank C++ | `87/90`, true, owner/emitter unchanged, `[[CHILDREN]]` and split plan | Aggregate no longer hides body blockers; exact split list is implementation-ready. |
| `00031H` | `85/92`, true, owner/emitter `0000K5`, blank C++ | `85/92`, `RECONSTRUCTABLE:FALSE`, owner `0000K5`, blank emitters/C++ | No score raise while converting to compiler/static cleanup support. |
| `00025J` | `87/92`, true, owner/emitter `0000K5`, blank C++ | `88/92`, true, owner/emitter unchanged, formal no-raw-table proof | Source-declared/generated-binary vtable/string data should not emit raw table arrays. |

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | [UID:0000K5] is the correct source root for pane-side IME UI and remains separate from InputMan. | High | `by-file/IMEPanes.md` now records the pane-side IME family, InputMan separation, callback evidence, and score `90/88`. | `by-file/IMEPanes.md` Status/Evidence/Changes | incorporate | applied |
| C02 | Generated `IMEPanes.cpp` had one filled and sixteen empty marker rows before callback; callback replaced the empty-marker state with code, class shells, proof comments, covered-by handling, or metadata reclassification. | High | `by-file/IMEPanes.md` records the before/after generated audit; final generated header is `validator-command-id: 000000002929`, refreshed `2026-06-30T14:34:45-04:00`. | `by-file/IMEPanes.md` generated-output audit and this report callback results | incorporate | applied |
| C03 | [UID:00018A] is already populated and should not be rewritten. | High | Existing [UID:00018A] formal C++ was left untouched; `IMECompositionPane` class shell was made compatible with that method. | `by-file/IMEPanes.md`, `by-class/IMECompositionPane.md` | already-present | already-present |
| C04 | [UID:00006F] should emit a declaration shell with `[[CHILDREN]]`. | High | `by-class/IMECandidatePane.md` now has score `87/90`, `EMITTER_POSITION_OPTIONAL:0`, `CandidateStringList`, method prototypes, fields, and `[[CHILDREN]]`. | `by-class/IMECandidatePane.md` metadata/C++/Status | incorporate | applied |
| C05 | [UID:00018B] should emit first-draft `ShowCandidateList` C++. | High | `by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md` now has the accepted formal body and score `89/91`. | `by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md` C++/Source Quality | incorporate | applied |
| C06 | Candidate anchor field order should be `candidateAnchorY +0x110`, `candidateAnchorX +0x114`. | High | Field order is now documented in `IMECandidatePane.md` and [UID:00018B] touched-state evidence; generated C++ uses `candidateAnchorX` as left and `candidateAnchorY` as top. | `by-class/IMECandidatePane.md`, [UID:00018B] Touched State | incorporate | applied |
| C07 | [UID:00031F] should emit ordinary destructor source C++. | High | `by-memory/0x004e7cb0-0x004e7cfc.IMECandidatePaneOrdinaryDestructor.md` now has the accepted minimal destructor body and score `87/91`. | `by-memory/0x004e7cb0-0x004e7cfc.IMECandidatePaneOrdinaryDestructor.md` C++/Notes | incorporate | applied |
| C08 | Scalar deleting destructors are compiler wrappers, not source methods. | High | [UID:00031I], [UID:00031J], [UID:00031K], and [UID:00031L] now contain formal compiler-wrapper proof comments and score notes. | [UID:00031I]/[UID:00031J]/[UID:00031K]/[UID:00031L] C++/Notes | incorporate | applied |
| C09 | [UID:00006G] should emit a declaration shell with `[[CHILDREN]]` compatible with [UID:00018A]. | High | `by-class/IMECompositionPane.md` now has score `87/90`, `EMITTER_POSITION_OPTIONAL:0`, composition fields/prototypes, and `[[CHILDREN]]`. | `by-class/IMECompositionPane.md` | incorporate | applied |
| C10 | [UID:00006H] should emit a declaration shell with `[[CHILDREN]]`, friends, and root IME fields. | High | `by-class/IMEPane.md` now has score `88/91`, `EMITTER_POSITION_OPTIONAL:0`, friend declarations, root fields, `extern IMEPane *g_pIMEPane`, and `[[CHILDREN]]`. | `by-class/IMEPane.md` | incorporate | applied |
| C11 | [UID:00031G] is a rare no-code raw-helper exception, not a deferred method. | High | `by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md` now has score `86/90` and a formal no-xref/no-function/covered-inline proof comment. | `by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md` C++/No-Code Proof | incorporate | applied |
| C12 | [UID:00006I] should emit a declaration shell with `statusText[256]`. | High | `by-class/IMEStatusPane.md` now has score `88/90`, `EMITTER_POSITION_OPTIONAL:0`, `statusText[256]`, method prototypes, and `[[CHILDREN]]`. | `by-class/IMEStatusPane.md` | incorporate | applied |
| C13 | [UID:0000R7] should emit `IMEPane *g_pIMEPane = NULL;`. | High | `by-global/g_pIMEPane.md` now has score `90/90`, the formal initializer, and current zero/null evidence. | `by-global/g_pIMEPane.md` formal C++/Evidence | incorporate | applied |
| C14 | [UID:0001PS] active IDB storage is zero/null; old `0xffffffff` text is stale. | High | `by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md` now has score `88/91`, covered-by marker, current `00 00 00 00` / `0x0` evidence, and superseded stale wording. | `by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md` Summary/Data/Evidence/C++ | incorporate, historicalize, reject-stale | applied |
| C15 | [UID:000189] needs aggregate `[[CHILDREN]]` and exact child split plan, not a broad body. | High | `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md` now has score `87/90`, aggregate `[[CHILDREN]]`, no-broad-body proof, and validator-assigned child UIDs [UID:0004BW] through [UID:0004CE]. | `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md` C++/Split plan and new child pages | incorporate | applied |
| C16 | [UID:00031H] should be non-reconstructable compiler/static cleanup support. | High | `by-memory/0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper.md` is now `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++, score still `85/92`, with cleanup-support notes. | `by-memory/0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper.md` metadata/status | incorporate | applied |
| C17 | [UID:00025J] is source-declared/generated-binary data, not a raw table to hand-author. | High | `by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md` now has score `88/92`, formal no-raw-table proof, and preserved vtable/string evidence. | `by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md` C++/Notes | incorporate | applied |
| C18 | FittingRoom owner placement for [UID:00018A]/[UID:00018B] remains rejected generated-owner pollution. | High | Existing rejection was preserved and reinforced in `by-file/IMEPanes.md` and [UID:00018B] notes; no FittingRoom/InputMan ownership was introduced. | `by-file/IMEPanes.md`, [UID:00018B] Notes | already-present | already-present |
| C19 | No manual generated files, coverage reports, validator state, IDA DB, supervisor ledgers, executed archives, or lock files were edited during callback. | High | Manual edits were limited to accepted by-* docs and this report. Validator-owned side effects occurred only through scoped validator commands: generated `IMEPanes.cpp`, `tools/validator.ini`, and generated tracker/coverage refreshes. `current_leases.md` was rechecked after B008 release/expiry and contained no active B008 leases. | Report checklist and callback results | incorporate | applied |

## No-Code Proofs And Remaining Open Questions

- [UID:00031G] no-code proof is target-specific and accepted as a rare exception only if the current no-xref/no-function state remains true during callback. Evidence checked: `lookup_funcs`, `xrefs_to`, `disasm`, [UID:00018A] duplicate inline logic, class/root field docs. Rejected alternatives: emit `IMEPane::UpdateFocusCaretAnchor()` as a callable helper, merge the raw range into [UID:00018A], clear ownership, or treat it as InputMan/TextEdit source.
- Scalar deleting destructor no-code proofs are wrapper-specific. They should not be converted to ordinary destructor bodies because each current MCP decompile includes deleting flag behavior and adjustor/vtable xrefs. Source-level cleanup lives in ordinary destructors/class declarations.
- [UID:00031H] is not a no-code source helper; it should be reclassified to `RECONSTRUCTABLE:FALSE`. The score does not rise because the callback is narrowing rebuild handling, not adding more behavior.
- [UID:000189] still has real source-authored bodies inside it, but the blocker is now converted into exact child pages and a source-placement table. The aggregate score remains conservative until those child pages receive child-specific body reviews and accepted formal C++.
- Exact original spellings for inherited Pane/GrafPort/Screen/TextEdit helpers remain inferred. They no longer block first-draft C++ because [UID:00018A] already uses the same accepted style, and current MCP proves behavior and owner direction. They continue to cap final-audit scores.

## Implementation Callback Results

- Callback mode: supervisor accepted this report for UID0000K5 implementation.
- Manual edit scope: accepted by-* docs plus this report only.
- Validator-owned side effects: scoped validators refreshed generated `auto-generated/NexusTK/input/IMEPanes.cpp`, generated tracker/coverage artifacts, and `tools/validator.ini` UID/path mappings for new split children. No generated files, generated reports, coverage reports, validator state, lock files, IDA DB, supervisor ledgers, or executed archives were edited by hand.
- Leases: B008 leased the changed by-* batch for the edit/validator batch. The broad batch had expired by cleanup; the final root lease was released successfully. `tools/leaser/Agents/current_leases.md` was rechecked after cleanup and contained no active B008 leases; unrelated B007 leases may appear later in the shared lease report.
- Generated freshness: final root validator command `000000002929` (`2026-06-30T14:34:45-04:00`) returned exit `0`, `ok:1`, warnings `0`, `generated_refresh: completed`. Generated `auto-generated/NexusTK/input/IMEPanes.cpp` now has header `validator-command-id: 000000002929`, `validator-refreshed-at: 2026-06-30T14:34:45-04:00`, `validator-refresh-source: foreground-generated-refresh`.
- Generated refresh note: an intermediate root refresh `000000002926` completed successfully, but a deferred older generated refresh later moved the header back. The final narrow root `--wait-generated` command `000000002929` was run after that deferred work and is the current header state.
- Generated content state: prior empty-marker rows are replaced by class shells, first-draft method/destructor C++, compiler-wrapper proof comments, raw-helper/source-data proofs, `IMEPane *g_pIMEPane = NULL;`, aggregate marker text, or [UID:00031H] non-reconstructable reclassification. [UID:0001PS] is now covered by [UID:0000R7] and does not emit a duplicate global. [UID:00031H] no longer emits because it is non-reconstructable.
- Split UID workflow: validator assigned new child UIDs [UID:0004BW] through [UID:0004CE]. These pages intentionally keep `EMITTER_UIDS` blank until child-specific body reports are accepted; the callback scope was the accepted split/source-placement plan, not first-draft C++ for every new child body.

## Changed Files

Existing by-* docs modified:

- `by-file/IMEPanes.md`
- `by-class/IMECandidatePane.md`
- `by-class/IMECompositionPane.md`
- `by-class/IMEPane.md`
- `by-class/IMEStatusPane.md`
- `by-global/g_pIMEPane.md`
- `by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md`
- `by-memory/0x004e7cb0-0x004e7cfc.IMECandidatePaneOrdinaryDestructor.md`
- `by-memory/0x004e8640-0x004e86bf.IMECandidatePaneScalarDeletingDestructor.md`
- `by-memory/0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor.md`
- `by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md`
- `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md`
- `by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md`
- `by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md`
- `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`
- `by-memory/0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper.md`
- `by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md`

New split child by-* docs created by supported validator UID workflow:

- [UID:0004BW] `by-memory/0x004e70f0-0x004e71bc.IMEStatusPaneSetText.md`
- [UID:0004BX] `by-memory/0x004e71c0-0x004e728a.IMEStatusPaneConstructor.md`
- [UID:0004BY] `by-memory/0x004e7290-0x004e72af.IMEStatusPaneOrdinaryDestructor.md`
- [UID:0004BZ] `by-memory/0x004e72b0-0x004e72f8.IMEStatusPaneOnIMEModeChange.md`
- [UID:0004C0] `by-memory/0x004e7300-0x004e737b.IMEStatusPaneOnPaintFrame.md`
- [UID:0004C1] `by-memory/0x004e7380-0x004e744d.IMECompositionPaneConstructor.md`
- [UID:0004C2] `by-memory/0x004e7450-0x004e746f.IMECompositionPaneOrdinaryDestructor.md`
- [UID:0004C3] `by-memory/0x004e7640-0x004e7809.IMECompositionPaneOnMouseEvent.md`
- [UID:0004C4] `by-memory/0x004e7810-0x004e7838.IMECompositionPaneOnKeyEvent.md`
- [UID:0004C5] `by-memory/0x004e7840-0x004e7912.IMECompositionPaneOnPaint.md`
- [UID:0004C6] `by-memory/0x004e7920-0x004e7927.IMECompositionPaneGetCompositionWidth.md`
- [UID:0004C7] `by-memory/0x004e7b70-0x004e7cae.IMECandidatePaneConstructor.md`
- [UID:0004C8] `by-memory/0x004e7d00-0x004e7d24.IMECandidatePaneHandleIMEMessage.md`
- [UID:0004C9] `by-memory/0x004e7d30-0x004e7f1a.IMECandidatePaneOnPaint.md`
- [UID:0004CA] `by-memory/0x004e7f20-0x004e7ff5.IMEPaneConstructor.md`
- [UID:0004CB] `by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md`
- [UID:0004CC] `by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md`
- [UID:0004CD] `by-memory/0x004e81a0-0x004e81a5.IMEPaneIsIMESupported.md`
- [UID:0004CE] `by-memory/0x004e81b0-0x004e8433.IMEPaneHandleIMEMessage.md`

Report updated:

- `tools/leaser/Agents/Agent-B008/research/0000K5-IMEPanes-empty-emitter-family-source-quality.md`

## Validator Results

All commands were run from `E:\NTK\GhidraBridge\source-3\project-documentation` with `--apply --queue-timeout 240`; the final root command also used `--wait-generated`.

| File | command_id | command_timestamp | Exit | ok | Warnings | Generated refresh |
| --- | --- | --- | --- | --- | --- | --- |
| `by-class/IMECandidatePane.md` | `000000002884` | `2026-06-30T14:21:57-04:00` | 0 | 1 | 0 | deferred |
| `by-class/IMECompositionPane.md` | `000000002885` | `2026-06-30T14:22:05-04:00` | 0 | 1 | 0 | deferred |
| `by-class/IMEPane.md` | `000000002886` | `2026-06-30T14:22:15-04:00` | 0 | 1 | 0 | deferred |
| `by-class/IMEStatusPane.md` | `000000002887` | `2026-06-30T14:22:22-04:00` | 0 | 1 | 0 | deferred |
| `by-global/g_pIMEPane.md` | `000000002888` | `2026-06-30T14:22:32-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md` | `000000002890` | `2026-06-30T14:22:41-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e7cb0-0x004e7cfc.IMECandidatePaneOrdinaryDestructor.md` | `000000002891` | `2026-06-30T14:22:43-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e8640-0x004e86bf.IMECandidatePaneScalarDeletingDestructor.md` | `000000002892` | `2026-06-30T14:22:54-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor.md` | `000000002893` | `2026-06-30T14:23:01-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md` | `000000002895` | `2026-06-30T14:23:08-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md` | `000000002896` | `2026-06-30T14:23:15-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md` | `000000002897` | `2026-06-30T14:23:25-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md` | `000000002898` | `2026-06-30T14:23:34-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md` | `000000002899` | `2026-06-30T14:23:42-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper.md` | `000000002900` | `2026-06-30T14:23:49-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md` | `000000002901` | `2026-06-30T14:23:56-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e70f0-0x004e71bc.IMEStatusPaneSetText.md` | `000000002902` | `2026-06-30T14:24:03-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e71c0-0x004e728a.IMEStatusPaneConstructor.md` | `000000002903` | `2026-06-30T14:24:10-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e7290-0x004e72af.IMEStatusPaneOrdinaryDestructor.md` | `000000002904` | `2026-06-30T14:24:17-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e72b0-0x004e72f8.IMEStatusPaneOnIMEModeChange.md` | `000000002905` | `2026-06-30T14:24:27-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e7300-0x004e737b.IMEStatusPaneOnPaintFrame.md` | `000000002906` | `2026-06-30T14:24:33-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e7380-0x004e744d.IMECompositionPaneConstructor.md` | `000000002907` | `2026-06-30T14:24:43-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e7450-0x004e746f.IMECompositionPaneOrdinaryDestructor.md` | `000000002908` | `2026-06-30T14:24:50-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e7640-0x004e7809.IMECompositionPaneOnMouseEvent.md` | `000000002910` | `2026-06-30T14:24:59-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e7810-0x004e7838.IMECompositionPaneOnKeyEvent.md` | `000000002911` | `2026-06-30T14:25:10-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e7840-0x004e7912.IMECompositionPaneOnPaint.md` | `000000002914` | `2026-06-30T14:25:20-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e7920-0x004e7927.IMECompositionPaneGetCompositionWidth.md` | `000000002915` | `2026-06-30T14:25:34-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e7b70-0x004e7cae.IMECandidatePaneConstructor.md` | `000000002916` | `2026-06-30T14:25:43-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e7d00-0x004e7d24.IMECandidatePaneHandleIMEMessage.md` | `000000002917` | `2026-06-30T14:25:53-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e7d30-0x004e7f1a.IMECandidatePaneOnPaint.md` | `000000002918` | `2026-06-30T14:26:03-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e7f20-0x004e7ff5.IMEPaneConstructor.md` | `000000002919` | `2026-06-30T14:26:12-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md` | `000000002920` | `2026-06-30T14:26:21-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md` | `000000002921` | `2026-06-30T14:26:31-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e81a0-0x004e81a5.IMEPaneIsIMESupported.md` | `000000002922` | `2026-06-30T14:26:41-04:00` | 0 | 1 | 0 | deferred |
| `by-memory/0x004e81b0-0x004e8433.IMEPaneHandleIMEMessage.md` | `000000002923` | `2026-06-30T14:26:51-04:00` | 0 | 1 | 0 | deferred |
| `by-file/IMEPanes.md` | `000000002929` | `2026-06-30T14:34:45-04:00` | 0 | 1 | 0 | completed; generated header matches |

## Implementation Tracking Checklist

Initial report-only revision:

- [x] Supervisor validation required before implementation. Proof: this is a report-only revision and no by-* docs were edited.
- [x] Current target state and generated marker inventory recorded. Proof: target metadata, generated `IMEPanes.cpp` header, one filled marker, and sixteen empty markers are listed above.
- [x] MCP evidence recorded and current. Proof: `supervisor_resume_20260629` health/session/schema plus lookup, xref, decompile, disasm, analyze, entity, string, bytes, int, and global-value results are recorded.
- [x] Score-blocker rework completed. Proof: every prior declaration/base-list/typedef/helper-name blocker is now first-draft C++, a class-shell/support declaration, an implementation-ready split plan, or a rare no-code proof.
- [x] Claim And Incorporation Ledger supplied for report-only supervisor acceptance. Proof: callback ledger rows C01-C19 above now supersede the report-only states with `applied` or `already-present` proof.
- [x] Update `by-file/IMEPanes.md` with revised generated-output audit, current MCP evidence, marker dispositions, score `90/88`, and callback change note. Proof: target validator `000000002929`, generated header matches `000000002929`.
- [x] Insert declaration-level class shells with `[[CHILDREN]]` into [UID:00006F], [UID:00006G], [UID:00006H], and [UID:00006I]; set class `EMITTER_POSITION_OPTIONAL:0`; update scores/field evidence as listed. Proof: class validators `000000002884` through `000000002887`, all exit `0`, `ok:1`.
- [x] Insert first-draft formal C++ for [UID:00018B] and raise to `89/91`. Proof: validator `000000002890`, generated `IMEPanes.cpp` emits `IMECandidatePane::ShowCandidateList`.
- [x] Insert ordinary destructor formal C++ for [UID:00031F] and raise to `87/91`. Proof: validator `000000002891`, generated output includes the destructor body.
- [x] Insert scalar deleting destructor no-source-body proof comments for [UID:00031I], [UID:00031J], [UID:00031K], and [UID:00031L]; update score notes. Proof: validators `000000002892`, `000000002893`, `000000002896`, and `000000002897`, all exit `0`, `ok:1`.
- [x] Insert rare no-code raw-helper proof for [UID:00031G] and raise to `86/90`. Proof: validator `000000002895`, generated output includes the rare no-code raw-helper proof comment.
- [x] Insert [UID:0000R7] formal global declaration `IMEPane *g_pIMEPane = NULL;` and current zero/null MCP evidence; update score to `90/90`. Proof: validator `000000002888`, generated output emits the global declaration.
- [x] Update [UID:0001PS] with covered-by marker, current zero/null evidence, historicalized stale `0xffffffff` wording, and score `88/91`. Proof: validator `000000002898`; generated output no longer emits duplicate [UID:0001PS] storage.
- [x] Update [UID:000189] with aggregate `[[CHILDREN]]`, no-broad-body proof, and exact split/source-placement plan. Create and validate listed child pages under supported UID workflow. Proof: aggregate validator `000000002899`; child validators `000000002902` through `000000002923`; assigned UIDs [UID:0004BW] through [UID:0004CE].
- [x] Reclassify [UID:00031H] to `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++, and compiler/static-lifetime cleanup notes without raising score. Proof: validator `000000002900`; [UID:00031H] no longer appears in generated `IMEPanes.cpp`.
- [x] Insert [UID:00025J] formal source-declared/generated-binary no-raw-table proof and preserve vtable/string evidence. Proof: validator `000000002901`, generated output includes the no-raw-table proof.
- [x] Preserve rejected alternatives: FittingRoom owner pollution, InputMan direct ownership for pane-side helpers, standalone raw helper route for `0x004e8110`, hand-authored scalar deleting destructors, broad aggregate body, and hand-authored read-only vtable table. Proof: preserved in target/support notes and ledger rows C08, C11, C15, C17, and C18.
- [x] Run scoped validators for every changed by-* file from `source-3/project-documentation`, using `--wait-generated` where generated `IMEPanes.cpp` freshness matters. Proof: Validator Results table above.
- [x] Confirm generated `auto-generated/NexusTK/input/IMEPanes.cpp` header is equal/newer than final relevant validator metadata and that prior empty markers are replaced by code, class shells, proof comments, covered-by markers, or metadata reclassification. Proof: generated header equals root validator `000000002929`; `rg` found no `TODO: empty`, `empty marker`, `EMPTY`, [UID:00031H], or duplicate [UID:0001PS] rows in the generated file.
- [x] No manual generated files, generated reports, manual `-coverage-report.md`, validator/tool state, IDA DB, supervisor ledgers, executed archives, or lock files are edited during callback. Proof: only scoped validator commands produced generated/validator-owned side effects; no manual edits were made to excluded files.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: current assignment `B008-implement-0000K5-IMEPanes-empty-emitter-family-20260630`.
- [x] All accepted target/support doc details incorporated at report-level detail or explicitly excluded with reason. Proof: ledger rows C01-C19 are `applied` or `already-present`; no unresolved ledger rows remain.
- [x] Claim And Incorporation Ledger updated from report-only states to final callback states with proof. Proof: all ledger rows above now have callback states and evidence.
- [x] Validators run and results recorded with command ids/timestamps/exit codes/ok counts/warnings. Proof: Validator Results table above.
- [x] Leases used only for immediate edit/validator batches and released immediately or allowed to expire during the validator batch. Proof: final active root lease released; `tools/leaser/Agents/current_leases.md` was rechecked and has no active B008 leases.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0000K5-IMEPanes-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0000K5-IMEPanes-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T14:37:53","uid":"0000K5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
