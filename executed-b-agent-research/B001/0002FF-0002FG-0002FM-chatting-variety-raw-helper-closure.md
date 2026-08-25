** TARGET-REPORT-UID:0002FF **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002FF / 0002FG / 0002FM Chatting Variety Raw Helper Closure

## Finalized Report / Current Recommendation

- Assignment: `B001-goal2-chatting-variety-raw-helper-closure-0002FF-0002FG-0002FM-20260617`.
- Current recommendation:
  - [UID:0002FF] `0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md`: keep owner/emitter [UID:00001Y] `ChattingVarietyPane`; raise only to `84/91`; keep below 85 completion and keep formal C++ blank.
  - [UID:0002FG] `0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest.md`: keep owner/emitter [UID:00001Y] `ChattingVarietyPane`; raise only to `84/91`; keep below 85 completion and keep formal C++ blank.
  - [UID:0002FM] `0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect.md`: keep owner/emitter [UID:00001Z] `ChattingVarietySelectPane`; raise to `86/92`; populate first-draft formal C++ for the row-rectangle helper.
- Final disposition: no split, merge, owner change, source-file move, generated-file edit, by-memory coverage edit, or IDA DB edit by B001. Supervisor/A-agent should apply the recommended doc/coverage/C++ changes if accepted.
- Confidence: high for the raw-route negative evidence and compact-vs-selector ownership; high for [UID:0002FM] source shape and C++ readiness; medium for exact original spellings of the helper names.

## Supporting Research

## Target

| UID | Path | Current score | Recommended score | Current owner/emitter | Recommended C++ |
| --- | --- | ---: | ---: | --- | --- |
| [UID:0002FF] | `by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md` | `82/90` | `84/91` | [UID:00001Y] | keep blank |
| [UID:0002FG] | `by-memory/0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest.md` | `82/90` | `84/91` | [UID:00001Y] | keep blank |
| [UID:0002FM] | `by-memory/0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect.md` | `82/92` | `86/92` | [UID:00001Z] | populate first draft |

- Source queue/report row: supervisor-assigned B-agent source-quality/raw-helper closure task.
- Current supervisor classification: report-only B-agent heuristic/source-inference work.
- Source route: [UID:00001Y] and [UID:00001Z] both emit through [UID:0000I5] `Chatting`, projected to `auto-generated/NexusTK/social/Chatting.cpp`.

## Executive Recommendation

[UID:0002FF] and [UID:0002FG] should remain `ChattingVarietyPane` compact-button helpers, not selector row helpers. The new evidence is not another restatement of "IDA has no xrefs": a fresh raw PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` found no direct `E8` calls to `0x00481010` or `0x00481060`, no accepted external direct branch route into either helper, and no VA/RVA literal pointer occurrences for either start. The old Ghidra/export cache does recognize both starts as functions, but that same cache reports zero callers, so it validates the function-shaped boundary without proving a source call route.

The best source inference is "retained file-local/private compact helper whose source use was inlined, elided, or left unreferenced in the linked object," not "popup selector row helper" and not "compiler padding." That is strong enough to close the ownership/name question and justify a small score bump to `84/91`, but it is not enough to clear 85 completion or populate formal C++. The missing route still prevents choosing a safe source declaration shape: non-static member with unused `this`, static/private helper, file-local helper, or uncalled leftover are all possible.

[UID:0002FM] is different. It has a modeled function boundary, a direct call from selector `OnPaint` at `0x00481605`, an actual call-site argument setup (`ECX=this`, row byte sign-extended, output `RectBounds` local pushed), exact row geometry, and an established `RectBoundsLayout` / `InitRectBounds` dependency. It should be raised to `86/92`, and its formal C++ block should be populated with a small helper body.

## Supervisor Active Recheck

- I followed the report-only assignment. I did not edit by-* docs, generated files, source files, the IDA DB, or `by-memory/-coverage-report.md`.
- IDA MCP endpoint `http://127.0.0.1:13337/mcp` was unavailable in this session (`Unable to connect to the remote server`). I therefore used:
  - current by-* docs and executed B-agent reports as recorded IDA evidence,
  - old local Ghidra/export JSON as non-authoritative comparison evidence,
  - fresh raw PE parsing/scanning against the actual `NexusTK.exe`.
- The assigned targets are already exact ranges. No split repair is needed.
- All remaining target open questions are either closed by evidence or evidence-bounded below.

## Inference Research Guidance Check

- `by-structure.md` requires source-quality questions to be resolved before final C++. For [UID:0002FF]/[UID:0002FG], the source route remains evidence-bounded but not code-safe. For [UID:0002FM], the type/source route is now code-safe.
- Current B-agent rules require rechecking existing B003 claims instead of copying them. I rechecked:
  - prior B003 [UID:00001Y] source-quality report,
  - prior B003 [UID:0002FC]/[UID:0002FD]/[UID:0002FF]/[UID:0002FG] method-family report,
  - prior B003 selector-family report,
  - current target/support docs,
  - current coverage rows,
  - raw PE route and pointer evidence.
- Existing B003 conclusions are mostly validated for [UID:0002FF]/[UID:0002FG], but the fresh PE scan lets the docs say the route search was explicitly performed against the binary. For [UID:0002FM], the old "support only/no required score change" posture is now too conservative because the helper has enough evidence for C++.

## Heuristic / Inference Reanalysis And Validation

### [UID:0002FF] Name, Type, And Source Direction

- Best descriptive name: `ChattingVarietyPaneCompactButtonRectHelper` or source-like `GetCompactButtonRect`.
- Best source direction: retained compact `ChattingVarietyPane` helper associated with the opener button, not a popup row helper.
- Evidence checked:
  - current target page raw bytes and disassembly;
  - fresh PE bytes at `0x00481010-0x00481056`;
  - six `0xcc` bytes at `0x0048100a-0x00481010` and ten `0xcc` bytes at `0x00481056-0x00481060`;
  - two direct calls inside the body to `0x004b7c50` at `0x00481030` and `0x0048104a`;
  - raw PE scan for direct calls, branches, VA literals, and RVA literals to `0x00481010`;
  - old export `exports/00481010.json`, which recovers the function body and reports zero callers.
- Fresh raw PE result:
  - direct `E8` calls to exact start `0x00481010`: none;
  - VA literal `10 10 48 00`: count `0`;
  - RVA literal `10 10 08 00`: count `0`;
  - accepted external direct branch route: none.
- Rejected alternatives:
  - `ChattingVarietySelectPane` row helper: rejected because selector rows are `(0, row * 16 + 6, 67, row * 16 + 22)` and are implemented by [UID:0002FM]/[UID:000106].
  - compiler padding/artifact: rejected because the range is a complete helper body with `push ebp`, two rectangle-setter calls, and `ret 8`.
  - final private member declaration now: rejected because no caller proves whether source passed `this`, used a static/free helper, or retained an unused helper.
- Impact: raise to `84/91` to reflect route-search closure and source-owner confidence, but keep completion below 85 and formal C++ blank.

### [UID:0002FG] Name, Type, Stack-Cookie Shape, And Source Direction

- Best descriptive name: `ChattingVarietyPaneCompactButtonHitTest` or source-like `HitTestCompactButton`.
- Best source direction: retained compact `ChattingVarietyPane` helper that tests the same compact button rectangle as [UID:0002FF].
- Evidence checked:
  - current target page raw bytes and disassembly;
  - fresh PE bytes at `0x00481060-0x004810ea`;
  - ten `0xcc` bytes before it and six `0xcc` bytes after it;
  - internal direct calls at `0x004810a2 -> 0x004b7c50`, `0x004810ad -> 0x004b7e80`, and security-cookie checks at `0x004810ca`/`0x004810df`;
  - raw PE scan for direct calls, branches, VA literals, and RVA literals to `0x00481060`;
  - old export `exports/00481060.json`, which recovers the stack-cookie helper and reports zero callers.
- Fresh raw PE result:
  - direct `E8` calls to exact start `0x00481060`: none;
  - VA literal `60 10 48 00`: count `0`;
  - RVA literal `60 10 08 00`: count `0`;
  - accepted external direct branch route: none.
- Stack-cookie inference:
  - The helper has local `RectBounds` storage and a security-cookie check, matching a source-shaped helper with stack locals rather than padding or a thunk.
  - The cookie proves a normal compiled helper shape, but it does not prove inbound source liveness.
- Rejected alternatives:
  - selector six-row hit-test: rejected because this helper loops over exactly one candidate and returns `0` or `0xff`; [UID:000106] loops rows `0..5`.
  - compiler-generated stack-cookie support: rejected because the cookie is only prologue/epilogue hardening around handwritten point/rectangle logic.
  - final C++ helper now: rejected because no caller or original symbol proves argument order/source declaration beyond `x,y`-like stack args.
- Impact: raise to `84/91`, keep completion below 85, keep formal C++ blank.

### [UID:0002FM] Name, Type, Caller, And Source Direction

- Best descriptive name: `ChattingVarietySelectPane::GetItemRect(int row, RectBounds *outRect)` or `GetSelectorRowRect`.
- Best source direction: selector-owned non-virtual private/helper method under `ChattingVarietySelectPane`.
- Evidence checked:
  - current [UID:0002FM] target page;
  - fresh PE bytes at `0x00481a80-0x00481acd`;
  - three `0xcc` bytes after and fourteen `0xcc` bytes before;
  - old export `exports/00481a80.json`, which reports one caller and one callee;
  - fresh raw PE direct-call scan;
  - bytes around call site `0x00481605` in selector `OnPaint`;
  - [UID:0001VP] `RectBoundsLayout`;
  - [UID:00015S] `RectGeometryHelpers`.
- Fresh raw PE result:
  - direct `E8` calls to exact start `0x00481a80`: `0x00481605`;
  - VA/RVA literal pointers to `0x00481a80`: count `0`, which is expected because this is directly called code, not table-routed data.
- Caller shape:
  - bytes around `0x00481605`: `8d 4d ec 0f be c0 51 50 8b cb e8 76 04 00 00`;
  - this is `lea ecx,[ebp-0x14]` for local out rect, sign-extend hot row, push out, push row, move selector `this` to `ecx`, then call `0x00481a80`;
  - the helper itself does not read `ecx`, but the call-site convention supports a member/helper source shape rather than an unrelated global.
- Rejected alternatives:
  - compact button helper: rejected because geometry is `left 0`, `right 67`, `top row*16+6`, `bottom row*16+22`, matching selector rows and [UID:000106], not compact `(0,0,62,24)`.
  - code-unsafe due unknown `Rect` type: rejected because [UID:0001VP] and [UID:00015S] document the four-int `RectBounds` layout and initializer.
  - keep at `82` because B003 did not focus it: rejected; current evidence is stronger than the current sparse page/coverage row.
- Impact: raise to `86/92` and populate first-draft C++.

### Compact-Versus-Selector Ownership Boundary

- [UID:0002FC] compact mouse handler inlines the compact `(0,0,62,24)` hit-test and selector popup creation. That supports [UID:0002FF]/[UID:0002FG] as compact opener helpers by geometry, but it does not call them.
- [UID:0002FL] selector paint calls [UID:0002FM] at `0x00481605` for the hot-row highlight rectangle.
- [UID:0002FJ] selector mouse handler calls [UID:000106] at `0x0048124d` and `0x00481430` for six-row hit-testing.
- This split is now stable:
  - compact opener: [UID:00001Y], [UID:0002FF], [UID:0002FG];
  - popup selector rows: [UID:00001Z], [UID:0002FM], [UID:000106].

### Raw Helper Liveness, Callsite Elision, And Inline/Local/Static Origin

- The most likely source history for [UID:0002FF]/[UID:0002FG] is a pair of small private/local compact-button helpers written like the later menu-variety helper pairs. The compiler/linker retained their bodies even though the live compact mouse handler contains equivalent inline logic.
- This could happen if:
  - the original `.cpp` kept helper functions but the hot call site was inlined or manually duplicated;
  - function-level linking did not discard unreferenced local functions;
  - old code retained a helper pair after the final mouse handler stopped calling it.
- What cannot be safely chosen:
  - non-static member vs static member vs file-local free helper;
  - original helper names;
  - whether a final reconstructed source file should declare them at all while no current caller uses them.
- This is why the raw helpers remain below 85 completion even after the route search is closed.

## Evidence Standards Used

- Direct file evidence:
  - [UID:0002FF], [UID:0002FG], [UID:0002FM] target docs.
  - [UID:00001Y] `ChattingVarietyPane`.
  - [UID:00001Z] `ChattingVarietySelectPane`.
  - [UID:0000I5] `Chatting`.
  - [UID:000104] `ChattingUI`.
  - [UID:0002FC], [UID:0002FD], [UID:0002FH], [UID:000106].
  - [UID:000162] GrafPort draw-state helpers.
  - [UID:00015S] Rect geometry helpers and [UID:0001VP] RectBounds layout.
- B-agent evidence:
  - B003 `00001Y-chatting-variety-pane-source-quality.md`.
  - B003 `0002FC-0002FD-0002FF-0002FG-chatting-variety-method-family-source-quality.md`.
  - B003 `0002FH-0002FJ-0002FK-0002FL-0002FN-0002FO-000106-chatting-variety-select-pane-source-quality.md`.
  - B002 older Chatting UI raw-helper report for adjacent [UID:0002FP]/[UID:0002FQ] ownership contrast.
- Fresh binary evidence:
  - Parsed PE sections from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`: image base `0x00400000`, `.text` at `0x00401000`, `.rdata` at `0x0060d000`, `.data` at `0x0066d000`, `.rsrc` at `0x0069d000`.
  - Scanned `.text` for external direct `E8` calls to target starts and target ranges.
  - Scanned whole file for little-endian VA/RVA literals for all target starts.
  - Verified target bytes and surrounding `0xcc` padding.
- Limitation:
  - Live IDA MCP was unavailable. Current by-* docs and executed reports supply recorded live IDA evidence; fresh route closure comes from raw PE scanning.

## IDA MCP / Local Binary Facts

### Recorded IDA Facts From Current Docs

- [UID:0002FF] and [UID:0002FG] are not modeled as functions by the current IDA docs; callers/xrefs to their starts are empty.
- [UID:0002FM] is modeled at `0x00481a80-0x00481acd` with one caller in selector `OnPaint`.
- [UID:000106] is modeled at `0x00481ad0-0x00481b5b` with two selector `OnMouseEvent` callers.
- [UID:0002FH] raw constructor is not modeled and has no direct xrefs/pointer route, but selector destructor and vtable methods are modeled.

### Fresh PE Scan Facts

- Bytes/padding:
  - `0x0048100a-0x00481010`: six `0xcc`.
  - `0x00481010-0x00481056`: function-shaped helper bytes, ending in `ret 8`.
  - `0x00481056-0x00481060`: ten `0xcc`.
  - `0x00481060-0x004810ea`: stack-cookie helper bytes, ending in two `ret 8` paths.
  - `0x004810ea-0x004810f0`: six `0xcc`.
  - `0x00481a72-0x00481a80`: fourteen `0xcc`.
  - `0x00481a80-0x00481acd`: modeled row-rect helper bytes, ending in `ret 8`.
  - `0x00481acd-0x00481ad0`: three `0xcc`.
- Direct `E8` calls to exact starts:
  - `0x00481010`: none.
  - `0x00481060`: none.
  - `0x004810f0`: none.
  - `0x00481a80`: `0x00481605`.
  - `0x00481ad0`: `0x0048124d`, `0x00481430`.
- Whole-file VA/RVA literal counts:
  - `0x00481010` / `0x00081010`: `0`.
  - `0x00481060` / `0x00081060`: `0`.
  - `0x004810f0` / `0x000810f0`: `0`.
  - `0x00481a80` / `0x00081a80`: `0`.
  - `0x00481ad0` / `0x00081ad0`: `0`.
- Internal helper calls:
  - [UID:0002FF]: `0x00481030 -> 0x004b7c50`, `0x0048104a -> 0x004b7c50`.
  - [UID:0002FG]: `0x004810a2 -> 0x004b7c50`, `0x004810ad -> 0x004b7e80`, cookie checks at `0x004810ca` and `0x004810df`.
  - [UID:0002FM]: `0x00481aa3 -> 0x004b7c50`, `0x00481ac0 -> 0x004b7c50`.
  - [UID:000106]: `0x00481b11 -> 0x004b7c50`, `0x00481b1e -> 0x004b7e80`, cookie checks at `0x00481b3b` and `0x00481b50`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00481010-0x00481056` | [UID:0002FF] | compact button rectangle helper | TRUE | [UID:00001Y] | `84/91` | below 85; C++ blank |
| `0x00481060-0x004810ea` | [UID:0002FG] | compact button one-candidate hit-test helper | TRUE | [UID:00001Y] | `84/91` | below 85; C++ blank |
| `0x00481a80-0x00481acd` | [UID:0002FM] | selector row rectangle helper | TRUE | [UID:00001Z] | `86/92` | C++ ready |
| `0x00481ad0-0x00481b5b` | [UID:000106] | selector six-row hit-test helper | TRUE | [UID:00001Z] | `86/91` current | comparison only |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00481010` | no direct PE call, no VA/RVA literal | no proven inbound route for [UID:0002FF] |
| `0x00481060` | no direct PE call, no VA/RVA literal | no proven inbound route for [UID:0002FG] |
| `0x00481605` | direct `E8` to `0x00481a80` | selector `OnPaint` calls [UID:0002FM] |
| `0x0048124d`, `0x00481430` | direct `E8` calls to `0x00481ad0` | selector `OnMouseEvent` calls [UID:000106] |
| `0x00481030`, `0x0048104a`, `0x00481aa3`, `0x00481ac0` | direct calls to `0x004b7c50` | all row/rect helpers materialize `RectBounds` through the shared initializer |

## Documentation Evidence And IDA Status

- Current docs validated:
  - [UID:00001Y] now has declaration-only C++ and explicitly owns the compact helper pair.
  - [UID:00001Z] owns selector fields `m_pressCaptured` and `m_hotRow`, and treats [UID:0002FF]/[UID:0002FG] as related compact opener helpers only.
  - [UID:0000I5] places both compact and selector classes under `social/Chatting.cpp`.
  - [UID:00015S] and [UID:0001VP] make `RectBounds *` a defensible source type for [UID:0002FM].
- Current docs needing update:
  - [UID:0002FF]/[UID:0002FG] should replace "caller or symbol not recovered" with a stronger conclusion: fresh raw PE scan found no direct call/literal route, so the best inference is retained no-route compact helper.
  - [UID:0002FM] should no longer stay at `82` or have only approximate C++ in prose. It should record the exact direct caller/call-site setup and receive formal C++.

## Ranked Ownership Analysis

### 1. [UID:00001Y] ChattingVarietyPane For [UID:0002FF]/[UID:0002FG]

- Evidence for: compact `(0,0,62,24)` geometry; physical adjacency after the compact pane forwarder; relationship to [UID:0002FC] click/open logic; [UID:00001Y] class/source docs; [UID:0000I5] chat source placement.
- Evidence against: no direct caller or pointer route.
- Decision: accepted as semantic owner. The negative route evidence caps C++/source-declaration readiness, not owner.

### 2. [UID:00001Z] ChattingVarietySelectPane For [UID:0002FM]

- Evidence for: direct caller from selector `OnPaint`; selector row geometry; row/hot-state context; class docs; matching [UID:000106] hit-test.
- Evidence against: helper does not read `this` even though caller loads `ECX=this`.
- Decision: accepted. A member/private helper with an unused receiver is plausible and matches the call-site convention.

### 3. [UID:00001Z] ChattingVarietySelectPane For [UID:0002FF]/[UID:0002FG]

- Evidence for: physical proximity before selector constructor.
- Evidence against: geometry is compact button, not selector rows; no selector method calls these helpers; [UID:0002FM]/[UID:000106] are the selector row helpers.
- Decision: rejected.

### 4. Generic RectBounds / GrafPort Ownership

- Evidence for: helpers call `InitRectBounds` / `PointInRect`.
- Evidence against: those are shared dependencies; the helper constants and callers belong to chat compact/selector UI.
- Decision: rejected as direct owner.

## Negative Evidence Summary

- [UID:0002FF] and [UID:0002FG]:
  - no direct `E8` calls to starts in the PE;
  - no VA/RVA literal pointers to starts;
  - no current IDA modeled function/caller/xref according to docs;
  - old export cache recognizes the bodies but still reports zero callers;
  - no selector/compact vtable entry points to either helper.
- Rejected "dead padding" because both bodies are executable, helper-shaped, aligned, and call project geometry helpers.
- Rejected "safe source C++ now" because no inbound route proves source declaration form.

## First-Draft C++ Recommendation

### [UID:0002FF] Do Not Populate Formal C++

Do not populate [UID:0002FF] formal C++. The body is clear, but the source declaration and liveness are not. A plausible review-only sketch would be:

```cpp
// Review-only shape; do not populate as formal C++ yet.
void GetCompactButtonRect(int state, RectBounds *outRect)
{
    if (state == 0)
        InitRectBounds(outRect, 0, 0, 62, 24);
    else
        InitRectBounds(outRect, -1, -1, -1, -1);
}
```

This is not formal-code safe because no caller proves whether it was a `ChattingVarietyPane` member helper, static member, file-local free helper, or retained uncalled object-file body.

### [UID:0002FG] Do Not Populate Formal C++

Do not populate [UID:0002FG] formal C++. The review-only shape is:

```cpp
// Review-only shape; do not populate as formal C++ yet.
signed char HitTestCompactButton(int x, int y)
{
    RectBounds rect;
    GetCompactButtonRect(0, &rect);
    return PointInRect(y, x, &rect) ? 0 : -1;
}
```

This is not formal-code safe because the route to [UID:0002FF] is not proven, the source declaration form is not proven, and the helper is not called by the compact mouse handler in the PE.

### [UID:0002FM] Populate Formal C++

Populate [UID:0002FM] formal C++ with this first draft:

```cpp
void ChattingVarietySelectPane::GetItemRect(int row, RectBounds *outRect)
{
    if (row == -1)
    {
        InitRectBounds(outRect, -1, -1, -1, -1);
        return;
    }

    InitRectBounds(outRect, 0, row * 16 + 6, 67, row * 16 + 22);
}
```

Rationale:

- The exact range covers only this helper.
- The direct call at `0x00481605` passes the selector receiver in `ECX`, a signed row, and an output rectangle pointer.
- `RectBoundsLayout` is documented as four ints, and `InitRectBounds` is documented at `0x004b7c50`.
- The body has no unresolved branch/callee behavior.
- `GetItemRect` is source-facing/descriptive; `GetSelectorRowRect` is also acceptable, but using the current page/class terminology minimizes churn.

## Exact Metadata Recommendations

- [UID:0002FF]:
  - `COMPLETION:84`
  - `CONFIDENCE:91`
  - keep `CANONICAL_OWNER:00001Y`
  - keep `RECONSTRUCTABLE:TRUE`
  - keep `EMITTER_UIDS:00001Y`
  - keep `RECONSTRUCTION_CPP` blank.
- [UID:0002FG]:
  - `COMPLETION:84`
  - `CONFIDENCE:91`
  - keep `CANONICAL_OWNER:00001Y`
  - keep `RECONSTRUCTABLE:TRUE`
  - keep `EMITTER_UIDS:00001Y`
  - keep `RECONSTRUCTION_CPP` blank.
- [UID:0002FM]:
  - `COMPLETION:86`
  - `CONFIDENCE:92`
  - keep `CANONICAL_OWNER:00001Z`
  - keep `RECONSTRUCTABLE:TRUE`
  - keep `EMITTER_UIDS:00001Z`
  - populate `RECONSTRUCTION_CPP` with the first draft above.

## Exact Target-Doc Update Recommendations

### [UID:0002FF]

Add or replace source-route wording with:

```markdown
2026-06-17 B001 raw-helper closure: fresh PE scanning of `NexusTK.exe` found no direct `E8` calls, no accepted external branch route, and no VA/RVA literal pointer to `0x00481010`. The old Ghidra/export cache recognizes this as `FUN_00481010` with zero callers, matching the current IDA no-xref state. The best inference is a retained source-shaped compact-button rectangle helper whose live use was inlined, elided, or left unreferenced, not selector row geometry. Completion rises only to `84` and formal C++ remains blank because no caller/pointer/original-symbol evidence proves the source declaration form.
```

### [UID:0002FG]

Add or replace source-route wording with:

```markdown
2026-06-17 B001 raw-helper closure: fresh PE scanning of `NexusTK.exe` found no direct `E8` calls, no accepted external branch route, and no VA/RVA literal pointer to `0x00481060`. The old Ghidra/export cache recognizes this as a stack-cookie `FUN_00481060` helper with zero callers, matching the current IDA no-xref state. The best inference is a retained source-shaped compact-button hit-test helper paired with [UID:0002FF], not the selector six-row hit-test. Completion rises only to `84` and formal C++ remains blank because no caller/pointer/original-symbol evidence proves the source declaration form.
```

### [UID:0002FM]

Add source-quality evidence:

```markdown
2026-06-17 B001 comparison/source-quality closure: fresh PE scanning confirms a direct call at `0x00481605` from selector `OnPaint` to `0x00481a80`; the call site passes the selector receiver in `ECX`, a sign-extended hot row, and an output `RectBounds` local. The helper writes either an invalid rectangle or `(0, row * 16 + 6, 67, row * 16 + 22)` through `InitRectBounds` (`0x004b7c50`). [UID:0001VP] documents the four-int `RectBoundsLayout`, so this helper is source/C++ ready as `ChattingVarietySelectPane::GetItemRect(int row, RectBounds *outRect)`.
```

Populate [UID:0002FM] formal C++ with:

```cpp
void ChattingVarietySelectPane::GetItemRect(int row, RectBounds *outRect)
{
    if (row == -1)
    {
        InitRectBounds(outRect, -1, -1, -1, -1);
        return;
    }

    InitRectBounds(outRect, 0, row * 16 + 6, 67, row * 16 + 22);
}
```

## Exact Supervisor-Owned Coverage Row Replacement Text

Placement context: replace the existing [UID:0002FF], [UID:0002FG], and [UID:0002FM] rows in `by-memory/-coverage-report.md` inside the Chatting UI block around the `0x00481010-0x00481acd` selector/compact helper rows. Do not alter padding rows.

```markdown
        - [UID:0002FF][0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper](by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md) 0x00481010-0x00481056 | compact button rectangle helper | ChattingVarietyPaneCompactButtonRectHelper : reconstructable : 84% : very strong : B001 raw-helper closure keeps this as a retained source-shaped compact chat-variety button rectangle helper owned by ChattingVarietyPane, not popup selector row geometry; fresh PE scanning found no direct `E8` call, accepted branch route, VA literal, or RVA literal to `0x00481010`, while the old export cache recognizes the body but reports zero callers. Exact bytes, padding, two `InitRectBounds`/`0x004b7c50` calls, compact `(0,0,62,24)` output, invalid `(-1,-1,-1,-1)` output, and selector-row alternative rejection are documented; completion stays below 85 and formal C++ remains blank because no caller/pointer/original-symbol evidence proves member/static/file-local source declaration shape.
        - [UID:0002FG][0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest](by-memory/0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest.md) 0x00481060-0x004810ea | compact button hit-test helper | ChattingVarietyPaneCompactButtonHitTest : reconstructable : 84% : very strong : B001 raw-helper closure keeps this as a retained source-shaped compact chat-variety button hit-test helper owned by ChattingVarietyPane, not popup selector row geometry; fresh PE scanning found no direct `E8` call, accepted branch route, VA literal, or RVA literal to `0x00481060`, while the old export cache recognizes the stack-cookie helper but reports zero callers. Exact bytes, padding, one-candidate compact `(0,0,62,24)` loop, `0x004b7c50`/`0x004b7e80` calls, row `0` hit return, `0xff` miss return, and selector six-row alternative rejection are documented; completion stays below 85 and formal C++ remains blank because no caller/pointer/original-symbol evidence proves member/static/file-local source declaration shape.
        - [UID:0002FM][0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect](by-memory/0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect.md) 0x00481a80-0x00481acd | file-local/helper method | ChattingVarietySelectPaneGetItemRect : reconstructable : 86% : very strong : B001 comparison/source-quality closure confirms this modeled selector row rectangle helper has a direct `OnPaint` caller at `0x00481605`, call-site setup with `ECX=this`, signed row and output `RectBounds` arguments, exact invalid-row and `(0,row*16+6,67,row*16+22)` geometry, established `RectBoundsLayout`/`InitRectBounds` dependency, and selector ownership through [UID:00001Z]; formal first-draft C++ is safe as `ChattingVarietySelectPane::GetItemRect(int row, RectBounds *outRect)`.
```

If the supervisor applies target metadata but chooses not to populate [UID:0002FM] formal C++ immediately, do not use the `86%` row above; keep [UID:0002FM] at `82/92` until the C++ block is entered or an explicit no-code reason is added. My recommendation is to populate it.

## Follow-Up Actions

- Supervisor actions:
  - Apply metadata/doc updates for [UID:0002FF], [UID:0002FG], and [UID:0002FM].
  - Populate [UID:0002FM] formal C++.
  - Apply the three coverage rows above in `by-memory/-coverage-report.md`.
  - Run scoped validator passes for the three target pages and the coverage report.
- A-agent actions:
  - Consider a later pass on [UID:000106] after [UID:0002FM] C++ is applied; [UID:000106] may then be closer to first-draft C++ readiness.
- B001 future research actions:
  - None required for this cluster unless a live IDA MCP session or new symbol/source evidence appears for `0x00481010` or `0x00481060`.

## Confidence

- Recommendation confidence:
  - [UID:0002FF]: high for owner/behavior/no-route, medium for original source declaration.
  - [UID:0002FG]: high for owner/behavior/no-route, medium for original source declaration.
  - [UID:0002FM]: high for owner/behavior/caller/source shape.
- Score confidence:
  - [UID:0002FF]/[UID:0002FG] `84/91`: strong but intentionally below the 85 completion gate.
  - [UID:0002FM] `86/92`: strong; not higher because exact original helper spelling is inferred/descriptive.
- Remaining uncertainty:
  - no safe original symbol for any helper;
  - no proof whether [UID:0002FF]/[UID:0002FG] were source member helpers, static helpers, file-local helpers, or retained uncalled bodies.

## Validator Results

- Commands run:
  - No validator commands were run because this assignment is report-only and no by-* docs were edited.
  - IDA MCP status probe was attempted and failed to connect.
  - Raw PE scan was run read-only through an inline Python parser against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Results:
  - Report-only evidence collection completed.
- Any unresolved validator warnings/errors:
  - Not applicable.

## Changed Files

- Created:
  - `tools/leaser/Agents/Agent-B001/research/0002FF-0002FG-0002FM-chatting-variety-raw-helper-closure.md`
- Modified:
  - none outside B001 research.
- Renamed:
  - none.
- Moved to executed:
  - none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002FF-0002FG-0002FM-chatting-variety-raw-helper-closure.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002FF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
