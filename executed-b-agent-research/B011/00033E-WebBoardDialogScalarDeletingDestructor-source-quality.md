** TARGET-REPORT-UID:00033E **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00033E WebBoardDialog Scalar Deleting Destructor Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00033E] `by-memory/0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor.md` assigned to [UID:0000G2] `WebBoardDialog`, with emitter route [UID:0000G2] -> [UID:0000P9] `WebBoardDialog.cpp`.
- Final disposition: this range is the compiler-generated scalar deleting destructor wrapper for `WebBoardDialog`. The source-level reconstruction should remain the class declaration plus `WebBoardDialog::~WebBoardDialog()` from [UID:00020Y]; UID `00033E` should not emit a duplicate handwritten deleting-destructor function body.
- Required action: if the supervisor accepts this report, send B011 an implementation callback to add target-level source-quality detail and a comment-only formal C++ block for UID `00033E`. Do not manually edit `by-memory/-coverage-report.md`; use the exact replacement row below if the accepted implementation changes score/C++ status.
- Confidence: high for owner/source route and compiler-generated wrapper policy; medium-high for exact helper spelling because no fresh live IDA MCP session was available in this report pass.

## Supporting Research

## Target

- Target UID: `00033E`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor.md`
- Source queue/report row: `B011-goal2-web-board-dialog-scalar-deleting-destructor-source-quality-00033E-20260619`
- Current supervisor classification: report-only source-quality and heuristic/inference pass; no by-* edits, no `by-memory/-coverage-report.md` edit.
- Current scores and parent state: target is `COMPLETION:85`, `CONFIDENCE:87`, `CANONICAL_OWNER:0000G2`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000G2`; direct class parent [UID:0000G2] is `88/90`; source file [UID:0000P9] is `88/90`; singleton global [UID:0000SQ] is `86/90`.

## Executive Recommendation

Use this exact source-quality model:

- `0x00470790-0x004707ef` remains an exact source-bearing child of the mixed Browser/OLE aggregate [UID:0000ZF], not part of the aggregate source body.
- The direct semantic owner is [UID:0000G2] `WebBoardDialog` because the wrapper destroys a `WebBoardDialog` object, clears [UID:0000SQ] `g_pWebBoardDialog`, is reached through `WebBoardDialog` vtable data, and mirrors the already emitted ordinary destructor body in [UID:00020Y].
- The final source module remains [UID:0000P9] `WebBoardDialog`, proposed path `NexusTK/ui/dialogs/WebBoardDialog.cpp`. The generic browser module is a base/infrastructure dependency only.
- The range should keep `RECONSTRUCTABLE:TRUE` and `EMITTER_UIDS:0000G2` because the rebuilt source must declare a virtual destructor on `WebBoardDialog` and produce equivalent deleting-destructor ABI output through the compiler.
- Formal C++ for UID `00033E` should be comment-only, not a real wrapper body. The ordinary destructor source is already emitted by [UID:00020Y].
- Recommended score after target-doc implementation: `86/90` if the target page incorporates the wrapper policy, caller/vtable route, rejected owners, and C++ comment-only rationale from this report. Keep `85/87` if the supervisor chooses not to implement target-doc detail.

## Supervisor Active Recheck

- The active user instruction overrides the stale B011 `notes.md` chatting assignment for this turn. This report addresses only UID `00033E`.
- The assignment is report-only. I did not edit by-* docs, `by-memory/-coverage-report.md`, `auto-generated` files, project-level files, or B011 notes.
- The target does not need split repair. It is already an exact half-open function child inside [UID:0000ZF] `0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers`.
- Every source-bearing child relevant to the wrapper route already exists: ordinary destructor body [UID:00020Y], adjustor thunk cluster [UID:000337], vtable/data aggregate [UID:0001OB], and sibling old wrapper [UID:00033F].

## Inference Research Guidance Check

`by-structure.md` drove three decisions:

- The page is eligible for formal C++ only if `RECONSTRUCTABLE:TRUE`, a nonblank emitter route surfaces to a valid by-file source root, and `(COMPLETION + CONFIDENCE) / 2 > 85`. UID `00033E` meets that minimum gate: `(85 + 87) / 2 = 86`, emitter `0000G2` reaches `0000P9`, and [UID:0000P9] has a valid `NexusTK/ui/dialogs/` path.
- The minimum gate does not authorize weak or decompiler-shaped code. Because this is compiler deleting-wrapper glue, the correct final-output source is not a handwritten function; a comment-only marker is the safe C++ entry.
- Source-quality work does not stop at `85/85`. The target still needed explicit wrapper/deleting policy, source-placement, generated-wrapper status, caller/vtable reachability, and C++ readiness decisions.

`inference_research.md` affected the owner/source conclusion:

- Consumer or adjacency evidence alone is not ownership proof. The target sits in a Browser/OLE address island, but the write to `g_pWebBoardDialog`, WebBoardDialog vtable route, sibling active class docs, and ordinary destructor body outweigh address locality.
- Existing docs were treated as leads. I rechecked the current class/file/global/aggregate/thunk/vtable docs against each other and against generated coverage state, then separated documented IDA facts from inference.
- Because no live IDA MCP server was reachable in this session, the report does not claim fresh MCP observations. It relies on current by-* docs that record prior live IDA MCP evidence, the generated reports, and a scoped validator dry run.

## Heuristic / Inference Reanalysis And Validation

### Issue 1: `sub_470790` placeholder name

- Current generated/IDA placeholder: `sub_470790`.
- Best source-facing interpretation: `WebBoardDialog` scalar deleting destructor wrapper.
- Evidence checked: target doc records `sub_470790` at `0x00470790-0x004707ef`; [UID:0000G2] records `0x00470790` as the scalar deleting destructor; [UID:000337] maps the `0x004702d0-0x004702db` and `0x004702db-0x004702e6` adjustor-thunk ranges to `sub_470790`; [UID:0001OB] records WebBoardDialog vtable data at `0x006135dc`.
- Rejected alternatives: naming it `WebBoardDialog::~WebBoardDialog()` as the formal body would collide with [UID:00020Y], which already owns the ordinary source destructor body at `0x0046d330-0x0046d359`. Keeping only `sub_470790` is too low-quality because the current docs prove the class and role.
- Final direction: use "WebBoardDialog scalar deleting destructor" as the documentation subject and describe it as compiler-generated, not source-authored.

### Issue 2: Destructor/deleting-wrapper policy

- Best policy: source-declared/generated-binary. The rebuilt C++ should declare `virtual ~WebBoardDialog();` and emit the ordinary destructor body; the compiler should regenerate the deleting wrapper and optional `operator delete` call.
- Evidence checked: [UID:00020Y] emits `WebBoardDialog::~WebBoardDialog()` and records that `0x0046d330` clears `g_pWebBoardDialog`, restores BrowserPane vtable views, and calls base teardown. UID `00033E` records the same singleton clear/base teardown plus conditional free behavior, which is characteristic scalar deleting destructor glue.
- Rejected alternatives: a source-authored `WebBoardDialog::ScalarDeletingDestructor(unsigned int flags)` method is not plausible late-1999/mid-2000s C++ source; it would encode MSVC ABI implementation detail into hand-written project code. Marking the page non-reconstructable would also be too aggressive because the source class declaration is required to reproduce the ABI wrapper.
- Final direction: keep reconstructable and routed, but use comment-only formal C++ for this exact page.

### Issue 3: Owner and source placement

- Best direct owner: [UID:0000G2] `WebBoardDialog`.
- Best source file: [UID:0000P9] `WebBoardDialog`, generated as `auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp`.
- Evidence checked: [UID:0000G2] class page is `88/90`, declares `virtual ~WebBoardDialog()`, lists UID `00033E`, and records `sub_470790`, vtable ref `0x006135dc`, adjustor callers, singleton clear, base teardown, and delete-flag behavior. [UID:0000P9] file page is `88/90` and explicitly owns active/old web-board dialogs while rejecting generic Browser and generated RankingDialog pollution. The generated `WebBoardDialog.cpp` already contains the class shell and ordinary destructor body from UID `00020Y`, with UID `00033E` currently present as an empty emitter marker.
- Rejected alternatives: [UID:0000HV] `Browser` is infrastructure/base code only; [UID:000019] `BrowserPane` is the base class, not the derived wrapper owner; [UID:0000SQ] `g_pWebBoardDialog` owns the singleton storage, not the destructor method; [UID:0000ZF] is a non-emitting mixed inventory, not a source file.
- Final direction: keep metadata `CANONICAL_OWNER:0000G2` and `EMITTER_UIDS:0000G2`.

### Issue 4: Base/helper names

- Best source names:
  - ordinary source destructor: `WebBoardDialog::~WebBoardDialog()` from [UID:00020Y].
  - base teardown: `BrowserPane` destructor/base cleanup, expressed in source by normal C++ destructor chaining rather than a direct helper call in UID `00033E`.
  - delete helper: source-level `operator delete`, not a stable project helper name.
  - singleton: [UID:0000SQ] `g_pWebBoardDialog`.
- Evidence checked: [UID:00020Y] documents `0x0046d330-0x0046d359` as the ordinary destructor body and emits it; [UID:000019] documents BrowserPane destructor/base behavior; [UID:0000SQ] records scalar-delete clear at `0x00470796`.
- Rejected alternatives: carrying decompiler names such as `sub_470790`, raw delete-helper names, or a decompiler's base-cleanup symbol into final source would make the output less source-like. Exact internal delete-helper symbol spelling is not needed because C++ expresses it through `delete`/compiler deleting destructor generation.
- Final direction: target doc should use the source-facing names above and preserve raw `sub_470790` only as a search/IDA alias.

### Issue 5: Compiler-generated wrapper status

- Best classification: compiler-generated scalar deleting destructor wrapper caused by `WebBoardDialog` having a virtual destructor and multiple BrowserPane/COM-compatible vtable views.
- Evidence checked: [UID:000337] documents two adjustor thunks for `sub_470790`, each subtracting a secondary-base offset and tail-jumping to the target scalar deleting destructor; [UID:0001OB] records WebBoardDialog vtable slices beginning at `0x006135dc`; [UID:00020Y] reports no direct ordinary destructor refs to `0x0046d330`, matching destructor reachability through generated deleting routes.
- Rejected alternatives: treating [UID:000337] adjustors and [UID:00033E] wrapper as handwritten source helpers would force ABI artifacts into reconstructed project code. Treating them as ignorable without a routed comment would leave the current emitted-but-no-code tracker state unresolved.
- Final direction: document wrapper status and add a comment-only `RECONSTRUCTION_CPP CODE` block to UID `00033E`.

### Issue 6: Caller/vtable reachability

- Best reachability model: vtable and adjustor-thunk reachable, not ordinary direct-call source reachable.
- Evidence checked:
  - target doc records vtable data ref `0x006135dc`.
  - [UID:000337] maps the two WebBoardDialog adjustor thunks at `0x004702d0-0x004702db` and `0x004702db-0x004702e6` to `sub_470790`; the target doc records corresponding caller sites `0x004702d6` and `0x004702e1`.
  - [UID:0001OB] records WebBoardDialog vtable slices `0x006135dc`, `0x00613650`, and `0x00613680`, with constructor setup xrefs at `0x0046d0e6`, `0x0046d0ec`, and `0x0046d0f6`.
  - [UID:00020Y] records a local PE scan finding no direct ordinary destructor refs to `0x0046d330`, consistent with compiler wrapper dispatch.
- Rejected alternatives: no evidence supports a normal source caller manually invoking this wrapper. No evidence supports moving the wrapper to the mixed thunk page, because the wrapper body itself performs WebBoardDialog teardown semantics.
- Final direction: target doc should state vtable/adjustor reachability explicitly and should not invent direct source callers.

### Issue 7: Split/range decision

- Best split decision: no further split; keep exact half-open `0x00470790-0x004707ef`.
- Evidence checked: [UID:0000ZF] final split map lists UID `00033E` exactly between [UID:00033D] `0x00470740-0x00470782.BrowserNotificationScalarDeletingDestructor` and [UID:00033F] `0x004707f0-0x0047084f.WebBoardDialogOldScalarDeletingDestructor`; [UID:00033F] is the old-variant sibling with separate owner [UID:0000G3].
- Rejected alternatives: merging active and old wrappers would mix [UID:0000G2] and [UID:0000G3]; merging the wrapper into [UID:000337] would mix actual deleting destructor bodies with adjustor thunks; merging into [UID:0000ZF] would undo the accepted mixed-container split.
- Final direction: no rename/split/merge needed.

### Issue 8: Open questions and blockers

- Live IDA MCP was unavailable for this B011 pass. A direct endpoint check to `http://127.0.0.1:13337/mcp` failed with `Unable to connect to the remote server`. This caps the report's fresh-evidence confidence and prevents a new byte/decompile capture.
- Exact MSVC internal helper symbol names for the delete helper/base cleanup are not needed for source readiness and should not block implementation. Source should use destructor declaration/destructor body and let the compiler generate wrapper/delete behavior.
- No owner, emitter, split, or C++ policy blocker remains. The only remaining uncertainty is historical compiler-symbol spelling, which should be documented as nonessential ABI detail.

## Evidence Standards Used

- Direct documented IDA facts from current by-* pages: function range, prior live IDA MCP size/range observations, decompilation summaries, vtable refs, adjustor thunk mapping, singleton writes, and generated output route.
- Documentation evidence: [UID:0000G2] `WebBoardDialog`, [UID:0000P9] `WebBoardDialog`, [UID:0000SQ] `g_pWebBoardDialog`, [UID:00020Y] ordinary destructor cluster, [UID:000337] adjustor thunk cluster, [UID:0001OB] vtable/data aggregate, [UID:0000ZF] parent split map, and sibling [UID:00033F].
- Generated/autogen evidence: `auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp` currently emits the class declaration and [UID:00020Y] ordinary destructor, while UID `00033E` is an empty emitter marker. `auto-generated/-ag-memory-coverage.md` records UID `00033E` as routed to that file with `Code` equal to `no`.
- Negative evidence: no single Browser/OLE aggregate owner; no source-shaped direct caller; no need to create a new file/source grouping; no safe reason to duplicate the compiler deleting wrapper as handwritten C++.
- Fresh live IDA MCP was attempted but unavailable, so this report does not present new live disassembly/decompilation beyond current docs.

## IDA MCP Facts

These are documented prior IDA MCP facts from current by-* docs, not fresh observations from this B011 session:

- Function/range facts: [UID:0000G2] records live IDA MCP confirmation that `sub_470790` at `0x00470790` has size `0x5f`; target [UID:00033E] uses half-open range `0x00470790-0x004707ef`.
- Data/table facts: [UID:0001OB] records WebBoardDialog vtable data beginning at `0x006135dc` and constructor setup xrefs at `0x0046d0e6`, `0x0046d0ec`, and `0x0046d0f6`.
- Xref facts: [UID:000337] records adjustor thunks that target `sub_470790`; target [UID:00033E] records caller sites `0x004702d6` and `0x004702e1` plus vtable data ref `0x006135dc`.
- Global/type facts: [UID:0000SQ] records `g_pWebBoardDialog` storage at `0x0067ab9c`, with scalar-delete clear at `0x00470796`.
- Behavior facts: target [UID:00033E] records decompilation clearing `dword_67AB9C` / `g_pWebBoardDialog`, restoring BrowserPane vtables, calling base cleanup, and conditionally freeing `this`.
- Negative IDA facts: [UID:00020Y] records no direct ordinary destructor refs to `0x0046d330`, matching source destructor reachability through generated deleting-destructor routes.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0046d330-0x0046d359` within `0x0046d330-0x0046d475` | [UID:00020Y] `by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md` | ordinary `WebBoardDialog::~WebBoardDialog()` body plus close/reposition companions | TRUE | [UID:0000G2] | `87/91` | emits real C++ destructor body |
| `0x00470278-0x004702fc` | [UID:000337] `by-memory/0x00470278-0x004702fc.BrowserDialogDestructorAdjustorThunks.md` | mixed destructor adjustor thunks including two WebBoardDialog adjustors to `sub_470790` | FALSE | NONE | `86/90` | non-emitting ABI thunk cluster |
| `0x00470790-0x004707ef` | [UID:00033E] target | WebBoardDialog scalar deleting destructor wrapper | TRUE | [UID:0000G2] | `85/87` current, `86/90` recommended after implementation | routed, currently no formal code |
| `0x004707f0-0x0047084f` | [UID:00033F] `by-memory/0x004707f0-0x0047084f.WebBoardDialogOldScalarDeletingDestructor.md` | old variant scalar deleting destructor wrapper | TRUE | [UID:0000G3] | `85/88` | sibling, separate owner |
| `0x006135dc-0x00613730` within `0x006131b4-0x006139df` | [UID:0001OB] `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md` | WebBoardDialog/WebBoardDialogOld vtable slices inside mixed data index | FALSE as aggregate | NONE | `86/90` | non-emitting mixed vtable/string index |
| `0x0046f010-0x004710b8` | [UID:0000ZF] `by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md` | mixed Browser/OLE split inventory container | FALSE | NONE | `91/92` | non-emitting parent index |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x006135dc` | WebBoardDialog vtable data ref to `sub_470790` | Primary vtable reachability for the active deleting destructor wrapper. |
| `0x004702d0-0x004702db` | adjustor thunk to `sub_470790` | Secondary-base adjustor route for WebBoardDialog destructor dispatch. |
| `0x004702db-0x004702e6` | second adjustor thunk to `sub_470790` | Additional secondary-base adjustor route; documented caller sites include `0x004702d6` and `0x004702e1`. |
| `0x0046d330-0x0046d359` | ordinary destructor body | Source destructor body emitted by UID `00020Y`; target wrapper should not duplicate this C++ body. |
| `0x00470796` | write to `0x0067ab9c` / `g_pWebBoardDialog` | Scalar deleting destructor clears active singleton parity with ordinary destruction. |
| `0x004707f0` | adjacent sibling old wrapper | Confirms active/old split boundary; old wrapper belongs to [UID:0000G3], not this target. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - [UID:00033E] target already has exact range, owner, singleton clear, vtable ref, adjustor callers, base cleanup, and delete-flag behavior.
  - [UID:0000G2] `WebBoardDialog` is `88/90`, contains a declaration-level class shell with `virtual ~WebBoardDialog();`, lists UID `00033E`, and records prior live IDA evidence for `sub_470790`.
  - [UID:00020Y] emits the ordinary `WebBoardDialog::~WebBoardDialog()` source body, proving the final C++ destination for source destructor semantics.
  - [UID:0000P9] `WebBoardDialog` is `88/90`, owns active and old web-board variants under `NexusTK/ui/dialogs/`, and rejects generic Browser/RankingDialog placement.
  - [UID:000337] separates compiler adjustor thunks from source method bodies.
  - [UID:0000ZF] keeps the broad Browser/OLE range as a non-emitting mixed inventory and lists UID `00033E` as an exact source-bearing child.
- Existing docs that are incomplete for this specific target:
  - [UID:00033E] does not yet explicitly state the comment-only C++ policy, generated-wrapper classification, or why the ordinary destructor page is the real source body.
  - Current generated `WebBoardDialog.cpp` has UID `00033E` as an empty emitter marker, so the autogen tracker still reports the target as routed but uncoded.
- Generated/coverage report state:
  - `auto-generated/-ag-memory-coverage.md` row: UID `00033E` has status `emits`, owner `0000G2`, emitter `0000G2`, destination `auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp`, and `Code` value `no`.
  - `by-memory/-coverage-report.md` current row is exact and source-owned but should be updated only by the supervisor if score/C++ policy changes are accepted.

## Ranked Ownership Analysis

### 1. [UID:0000G2] WebBoardDialog class

- Evidence for: target clears `g_pWebBoardDialog`, uses WebBoardDialog vtable data, is mapped by WebBoardDialog adjustor thunks, and mirrors the ordinary destructor body already attached to the class. The class parent is `88/90` and source-routed through [UID:0000P9].
- Evidence against: exact compiler-generated wrapper code is not source-authored, but that affects formal C++ policy, not direct semantic ownership.
- Decision: accepted as direct canonical owner and emitter.

### 2. [UID:0000P9] WebBoardDialog source file

- Evidence for: active and old web-board dialog family source route; proposed path `NexusTK/ui/dialogs/`; generated output already includes UID `00033E` under this file through class [UID:0000G2].
- Evidence against: by-structure direct ownership for a class method page should prefer the direct class, not the file, when the class page clears the gate.
- Decision: accepted as final source module, not direct `CANONICAL_OWNER`.

### 3. [UID:000019] BrowserPane / [UID:0000HV] Browser

- Evidence for: wrapper restores BrowserPane vtable views and calls base cleanup; the object is browser-backed and physically located in the Browser/OLE island.
- Evidence against: base-class teardown is not derived-method ownership. BrowserPane has its own scalar deleting destructor [UID:00033C]; Browser source owns generic browser infrastructure, while this wrapper clears `g_pWebBoardDialog` and sits in WebBoardDialog vtable dispatch.
- Decision: rejected as owner; retained as dependency/base context.

### 4. [UID:0000SQ] g_pWebBoardDialog

- Evidence for: target writes the singleton global at `0x0067ab9c`.
- Evidence against: the global page owns storage/lifetime state, not the method body. Constructor, ordinary destructor, cleanup helper, and scalar wrapper all touch the global from class/source contexts.
- Decision: rejected as direct owner; cross-reference/support page only.

### 5. [UID:0000ZF] BrowserOleLegacyAndHelpers aggregate or owner NONE

- Evidence for: target is physically inside the aggregate and was created by the B001-024 split.
- Evidence against: [UID:0000ZF] is explicitly non-emitting and mixed-owner. UID `00033E` has a gate-cleared direct class owner and emitter route, so leaving it parentless would lose useful source structure.
- Decision: rejected.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new owner or file is needed.
- Likely full contents: use existing [UID:0000P9] `WebBoardDialog.cpp`, already covering `WebBoardDialog`, `WebBoardDialogOld`, singleton globals, response/URL helpers, render/layout helpers, and destructor companions.
- Candidate related items that belong: UID `00033E` remains a child routed through [UID:0000G2]; UID `00033F` remains separate under [UID:0000G3]; UID `000337` remains non-emitting.
- Candidate related items rejected: no move to Browser, BrowserPane, or a standalone "DestructorWrappers.cpp".
- Standalone, narrow, or broad source-file inference: existing broad `WebBoardDialog.cpp` route is correct.

## Negative Evidence Summary

- Address locality in the Browser/OLE island does not prove Browser ownership because [UID:0000ZF] also contains WebBoardDialog, WebBoardDialogOld, AutoInit, and compiler/ABI islands.
- The adjustor thunks in [UID:000337] prove ABI dispatch, not source-authored helper functions.
- The singleton clear does not make [UID:0000SQ] the method owner; it is lifecycle state touched by class constructor/destructor paths.
- The old sibling [UID:00033F] starts immediately after the target but owns [UID:0000G3] `WebBoardDialogOld`; adjacency is not a merge signal.
- No live IDA MCP in this session means no score above low 90s should be recommended from this report alone.

## First-Draft C++ Recommendation

UID `00033E` is eligible for a nonblank formal C++ block by route and score, but the correct content is a comment-only marker. Do not add a real function body such as a hand-authored scalar deleting destructor.

Recommended formal `RECONSTRUCTION_CPP CODE` content for UID `00033E`:

```cpp
// Compiler-generated scalar deleting destructor for WebBoardDialog.
// Source reconstruction is the virtual destructor declaration plus WebBoardDialog::~WebBoardDialog()
// emitted by UID 00020Y; do not hand-author this wrapper.
```

Rationale:

- The ordinary source destructor body already emits from [UID:00020Y].
- The class declaration in [UID:0000G2] already declares `virtual ~WebBoardDialog();`.
- A real wrapper body would encode MSVC ABI glue into project source and could duplicate destructor behavior.
- A comment-only block satisfies the routed-emitter/no-code tracker without pretending the wrapper was handwritten source.

## Supervisor-Owned Coverage Row Text

Current exact `by-memory/-coverage-report.md` row:

```text
      - [UID:00033E][0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor](by-memory/0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor.md) 0x00470790-0x004707ef | class destructor | WebBoardDialogScalarDeletingDestructor : reconstructable : 85% : strong : WebBoardDialog scalar deleting destructor assigned to [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md); in-range dialog ownership is explicit and does not route to Browser.
```

Recommended supervisor-owned replacement row if the implementation callback applies the report, raises the target to `86/90`, and adds the comment-only formal C++ block:

```text
      - [UID:00033E][0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor](by-memory/0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor.md) 0x00470790-0x004707ef | class destructor | WebBoardDialogScalarDeletingDestructor : reconstructable : 86% : strong : WebBoardDialog compiler-generated scalar deleting destructor wrapper assigned to [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md); source body is [UID:00020Y][0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions](by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md), and the wrapper should emit only a comment marker through the class route rather than a duplicate handwritten deleting-destructor body.
```

No B-agent should edit this shared coverage report directly while the temporary ban is active.

## Target / Support Implementation Checklist

Target doc: `by-memory/0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor.md`

- Lease target before editing.
- Add an explicit rebuild-handling/source-quality paragraph: `source-declared/generated-binary` compiler scalar deleting destructor wrapper for `WebBoardDialog`.
- Preserve metadata `CANONICAL_OWNER:0000G2`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000G2`.
- If all report details are incorporated, change score from `85/87` to `86/90`. Do not exceed `90` confidence without a fresh live IDA byte/decompile pass.
- Add the comment-only formal C++ block from this report. Do not add a real deleting-destructor function body.
- Add or update evidence for vtable ref `0x006135dc`, adjustor thunk callers `0x004702d6` and `0x004702e1`, singleton clear `g_pWebBoardDialog`, ordinary destructor source body [UID:00020Y], and sibling old wrapper [UID:00033F].
- Add rejected alternatives: Browser, BrowserPane, g_pWebBoardDialog global, parent aggregate, WebBoardDialogOld, and handwritten source helper.
- Add explicit C++ readiness note: source destructor is already in UID `00020Y`; this exact wrapper is comment-only to avoid duplicate ABI glue.

Support doc: `by-class/WebBoardDialog.md`

- If editing, add one sentence to the scalar deleting destructor row/method notes that UID `00033E` is a compiler-generated deleting wrapper and should remain comment-only while UID `00020Y` emits `WebBoardDialog::~WebBoardDialog()`.
- No score change required.

Support doc: `by-file/WebBoardDialog.md`

- If editing, update generated-output/status wording to say UID `00033E` is intentionally comment-only after implementation, not an unresolved missing method body.
- No score change required.

Support docs to read/verify but probably not edit:

- `by-global/g_pWebBoardDialog.md`: confirms scalar-delete clear at `0x00470796`.
- `by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md`: owns/emits ordinary destructor body.
- `by-memory/0x00470278-0x004702fc.BrowserDialogDestructorAdjustorThunks.md`: owns non-emitting adjustor-thunk cluster.
- `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md`: documents vtable slices.
- `by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md`: parent split inventory.

Validation expected after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [00033E-WebBoardDialogScalarDeletingDestructor-source-quality-removed.md](00033E-WebBoardDialogScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If support docs are edited, also run:

> Executable block R002 was removed from this report and preserved verbatim in [00033E-WebBoardDialogScalarDeletingDestructor-source-quality-removed.md](00033E-WebBoardDialogScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Supervisor-owned manual/refresh actions after accepted implementation:

- Apply the `by-memory/-coverage-report.md` replacement row above if the target score changes to `86/90`.
- Confirm validator-generated `auto-generated/-ag-memory-coverage.md` changes from `Code` `no` to the expected coded/comment-only state after target validation. Do not manually edit `auto-generated/-ag-memory-coverage.md`.

## Final Recommendation

- Exact changes recommended: update UID `00033E` target detail, score `85/87 -> 86/90` if implemented, and insert the comment-only formal C++ block.
- Exact parent assignments recommended: keep `CANONICAL_OWNER:0000G2`, `EMITTER_UIDS:0000G2`; no split/rename/owner move.
- Exact items left no-owner/non-emitting and why: none in this target. [UID:000337] remains non-reconstructable and parent-blank because it is a mixed adjustor-thunk cluster; that is already correct and not part of this implementation.
- Exact future work outside this assignment scope: fresh live IDA MCP could capture current disassembly/decompilation bytes for `sub_470790` before any future score above `90`, but it is not needed for the owner/C++ policy decision.

## Follow-Up Actions

- Supervisor actions: review this report; if accepted, send B011 the implementation checklist; after B011 implementation, apply the supervisor-owned coverage row replacement if score changes.
- A-agent actions: none.
- B011 future research actions: none for UID `00033E` after implementation unless a fresh live IDA pass is requested for final-audit scoring.

## Confidence

- Recommendation confidence: `90/100` for direct owner/source route and comment-only C++ policy.
- Score confidence: `86/90` recommended after implementation; current `85/87` remains defensible until the target doc carries these details.
- Remaining uncertainty: exact internal MSVC helper names and fresh byte/decompile capture were not available in this session. This does not affect owner, split, or C++ readiness because the source-facing behavior is expressed through the ordinary destructor and virtual destructor declaration.

## Validator Results

Live IDA MCP availability check:

> Executable block R003 was removed from this report and preserved verbatim in [00033E-WebBoardDialogScalarDeletingDestructor-source-quality-removed.md](00033E-WebBoardDialogScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result: failed with `Unable to connect to the remote server`.

Scoped validator dry run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R004 was removed from this report and preserved verbatim in [00033E-WebBoardDialogScalarDeletingDestructor-source-quality-removed.md](00033E-WebBoardDialogScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code: `0`
- `scanned markdown files: 1`
- `ok: 1`
- `ok 00033E by-memory/0x00470790-0x004707ef.WebBoardDialogScalarDeletingDestructor.md UID header exists`
- Dry run only; no files changed by validator.
- Autogen dry-run output reported `auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp` unchanged and generated reports unchanged.

## Changed Files

- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B011\research\00033E-WebBoardDialogScalarDeletingDestructor-source-quality.md`
- Modified: none outside this B011 research report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/00033E-WebBoardDialogScalarDeletingDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"00033E"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00033E-WebBoardDialogScalarDeletingDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/00033E-WebBoardDialogScalarDeletingDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00033E"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
