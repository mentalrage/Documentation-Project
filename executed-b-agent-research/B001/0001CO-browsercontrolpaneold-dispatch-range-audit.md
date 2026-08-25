** TARGET-REPORT-UID:0001CO **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001CO BrowserControlPaneOld Dispatch Range / Source-Quality Audit

## Finalized Report / Current Recommendation

- Current recommendation: accept the coordinated rename to `by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md`, keep direct owner/emitter [UID:000016][BrowserControlPaneOld](../../../../../by-class/BrowserControlPaneOld.md), and keep the Browser file route through [UID:0000HV][Browser](../../../../../by-file/Browser.md).
- Final disposition: `0001CO` is not a generic `MSGHandler` method and is not a Browser-object dispatch helper. It is a BrowserControlPaneOld fallback bridge that tail-forwards through the embedded `MSGHandler` subobject's saved previous-handler pointer.
- Required action: current live docs already have the renamed path and `85/89` score; if applying from a stale checkout, use the exact replacement rows/snippets below.
- Confidence: high for range, ownership, emitted route, and saved-handler semantics; intentionally below final-source confidence for exact helper/source spelling.

## Target

- Target UID: `0001CO`
- Assigned stale target path: `by-memory/0x00528de0-0x00528deb.BrowserControlPaneOldDispatch.md`
- Current live target path: `by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md`
- Assignment: `B001-goal2-browsercontrolpaneold-dispatch-range-audit-0001CO-20260616`
- Current metadata in live target at the time of this report:

```text
*** UID:0001CO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000016 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000016 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

## Executive Recommendation

The filename/range should be `0x00528de0-0x00528dec`, not `0x00528de0-0x00528deb`. The target page's authoritative range, IDA function size, raw bytes, and padding all support the half-open end `0x00528dec`, and the current file has already been normalized to that name.

The score should be `COMPLETION:85` and `CONFIDENCE:89`. The initial `80/88` was too conservative after the range rename, corrected saved-handler semantics, constructor/caller layout, vtable route, and generated/simroot source-shape checks. This item is not an exception to the 85/85 gate; it now has enough behavior, range, ownership, source-route, and blocker investigation to clear it. It should not be raised beyond `85/89` yet because the original C++ spelling of the helper remains open.

## Supervisor Active Recheck

- The supervisor rejection was valid: keeping `0001CO` at `80/88` after correcting range and behavior failed the standing "research more if below 85/85" gate.
- Additional research confirms `85/89` is justified. The missing source-quality questions are now bounded:
  - `MSGHandler` subobject: constructed at outer `BrowserControlPaneOld + 0x108`.
  - saved previous-handler field: subobject slot `+4`, generated as `MSGHandler::m_previousHandler` in active app output.
  - Browser object pointer: outer `BrowserControlPaneOld + 0x110`, which is subobject `this[2]` from the message handler's perspective.
  - helper name: generated `DispatchToBrowser` is rejected as final-source proof because it misidentifies the saved handler as a Browser object.
  - compiler/source shape: not a vtable override slot; best treated as BrowserControlPaneOld source-path helper/glue until exact C++ spelling is resolved.

## Evidence Standards Used

Evidence used here separates direct IDA facts, documentation evidence, generated-output leads, and inference.

- Direct IDA facts: function bounds, raw bytes, decompile, disassembly, xrefs, callers/callees, padding, vtable/data refs from live session `a002_goal65_20260616`.
- Documentation evidence: current target/support docs under `by-memory`, `by-class`, `by-file`, `by-type`, and `by-project-structure`.
- Generated-output leads: `auto-generated/NexusTK/app/MSGHandler.cpp`, `auto-generated/NexusTK/browser/Browser.cpp`, and `source-3/simroot_v2/class_BrowserControlPaneOld.cpp` / `class_MSGHandler.cpp`.
- Negative evidence: no vtable/data ref to `0x00528de0`, no Browser class caller, no dedicated by-type layout page for `MSGHandler` or `BrowserControlPaneOld`, and stale generated/scratch references to the old filename only.

## IDA MCP Facts

### Function and range facts

| Address/range | IDA fact | Meaning |
| --- | --- | --- |
| `0x00528de0` | `sub_528DE0`, size `0x0c` | Authoritative target body. |
| `0x00528dec` | not a function | Half-open exclusive end. |
| `0x00528dd0` | `sub_528DD0`, size `0x0c` | Generic `MSGHandler::DispatchMessage` forwarder, separate from `0001CO`. |
| `0x00528df0` | `sub_528DF0`, size `0x65` | Generic `MSGHandler` scalar deleting destructor successor. |
| `0x0046f310` | `sub_46F310`, body `0x0046f310-0x0046f378` plus switch table through `0x0046f47b` | Sole code caller of `0001CO`. |

Target body bytes:

```asm
0x00528de0  push ebp
0x00528de1  mov  ebp, esp
0x00528de3  mov  ecx, [ecx+4]
0x00528de6  mov  eax, [ecx]
0x00528de8  pop  ebp
0x00528de9  jmp  dword ptr [eax+4]
```

Hex-Rays decompile:

```cpp
int __thiscall sub_528DE0(_DWORD **this)
{
  return (*(int (__thiscall **)(_DWORD *))(*this[1] + 4))(this[1]);
}
```

Padding:

```text
0x00528ddc-0x00528de0 = CC CC CC CC
0x00528de0-0x00528dec = 55 8B EC 8B 49 04 8B 01 5D FF 60 04
0x00528dec-0x00528df0 = CC CC CC CC
```

### Xref and route facts

| Item | Xrefs/callees | Meaning |
| --- | --- | --- |
| `0x00528de0` | one code caller: `0x0046f36d` inside `sub_46F310`; no direct callees | BrowserControlPaneOld caller-only helper, indirect tail dispatch. |
| `0x00528dd0` | data xref from `0x0061fbfc` | Generic `MSGHandler` vtable dispatch slot. |
| `0x0046f310` | vtable/data ref from `0x00613828` | BrowserControlPaneOld handler method route. |
| `0x0061fbf8` | refs from `0x00528d64`, `0x00528da5`, `0x00528e18` | Generic MSGHandler vtable writes. |

The call site in `BrowserControlPaneOld::HandleBrowserMessage` pushes the message pointer, sets `ecx` to the embedded handler subobject, and calls `0x00528de0`:

```asm
0x0046f36a  push esi
0x0046f36b  mov  ecx, edi
0x0046f36d  call sub_528DE0
```

The keyboard forwarding path in the same caller uses `[edi+8]`, not `[edi+4]`, for the Browser object. This is the key split: from the embedded handler subobject perspective, `this[1]` / `+4` is the saved previous handler and `this[2]` / `+8` is the Browser pointer.

### Constructor/destructor layout facts

`BrowserControlPaneOld` constructor `0x0046ff50-0x00470159`:

- Calls `MSGHandler::MSGHandler` at `0x00528d60` with `this + 0x108`.
- Installs BrowserControlPaneOld vtable slices, including the handler-subobject vtable at outer `+0x108`.
- Clears and later stores the Browser object pointer at outer `+0x110`.
- Allocates the Browser object with size `0x234`.

`MSGHandler` constructor/destructor:

- Constructor writes `MSGHandler::vftable` and stores the return from [UID:0002GR][ApplicationExchangeMSGHandler](../../../../../by-memory/0x00465650-0x00465686.ApplicationExchangeMSGHandler.md) in `this[1]`.
- Destructor resets `MSGHandler::vftable` and calls `Application::ExchangeMSGHandler(this[1])`.
- `Application::ExchangeMSGHandler` reads previous handler from `Application + 0x844`, swaps the incoming handler pointer under the app critical section, and returns the previous pointer.

Destructor evidence around BrowserControlPaneOld:

- Raw non-deleting destructor `0x0046f1e0-0x0046f216` calls `0x00528d80` at `0x0046f209` to tear down the embedded MSGHandler subobject.
- Scalar deleting destructor `0x004704f0-0x00470579` calls `0x00528d80` and uses object size `0x114`.

## Function / Child Inventory

| Range / item | UID / path | Role | Direct parent | Score | Status |
| --- | --- | --- | --- | --- | --- |
| `0x00528d60-0x00528e55` | [UID:0001CN](../../../../../by-memory/0x00528d60-0x00528e55.MSGHandler.md) | MSGHandler executable island | [UID:00008S][MSGHandler](../../../../../by-class/MSGHandler.md) | `84/90` | Keep app-owned aggregate with `0001CO` split note. |
| `0x00528dd0-0x00528ddc` | inside `0001CN` | generic `MSGHandler::DispatchMessage` vtable slot | [UID:00008S][MSGHandler](../../../../../by-class/MSGHandler.md) | via aggregate | Not `0001CO`. |
| `0x00528de0-0x00528dec` | [UID:0001CO](../../../../../by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md) | BrowserControlPaneOld fallback bridge | [UID:000016][BrowserControlPaneOld](../../../../../by-class/BrowserControlPaneOld.md) | `85/89` | Rename/score/semantics accepted. |
| `0x0046f310-0x0046f47b` | [UID:00032U](../../../../../by-memory/0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage.md) | sole caller and switch table | [UID:000016][BrowserControlPaneOld](../../../../../by-class/BrowserControlPaneOld.md) | `85/88` | Confirms call route. |
| `0x0046ff50-0x00470159` | [UID:0002P3](../../../../../by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md) | constructor/layout source | [UID:000016][BrowserControlPaneOld](../../../../../by-class/BrowserControlPaneOld.md) | `85/89` | Confirms subobject and Browser pointer offsets. |

## Documentation Evidence And Current Status

- Target page currently exists at the corrected filename and already carries `COMPLETION:85`, `CONFIDENCE:89`, `CANONICAL_OWNER:000016`, and `EMITTER_UIDS:000016`.
- The old stale target filename `by-memory/0x00528de0-0x00528deb.BrowserControlPaneOldDispatch.md` is absent in the live tree.
- `by-memory/-coverage-report.md` already uses the corrected path and `85% : very strong`.
- [UID:000016][BrowserControlPaneOld](../../../../../by-class/BrowserControlPaneOld.md) already cites `0001CO` as `85/89`.
- [UID:0000HV][Browser](../../../../../by-file/Browser.md) already uses the corrected class table range ending at `0x00528dec`.
- [UID:0001CN][MSGHandler](../../../../../by-memory/0x00528d60-0x00528e55.MSGHandler.md) already lists `0001CO` as a BrowserControlPaneOld-owned bridge inside the physical MSGHandler island.
- [UID:00032U][BrowserControlPaneOldHandleBrowserMessage](../../../../../by-memory/0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage.md) already describes the default path as saved-previous-handler fallback.
- `auto-generated/-ag-memory-coverage.md` already routes `0001CO` to `auto-generated/NexusTK/browser/Browser.cpp`, but that generated source file is currently zero bytes because final C++ is blank.
- Stale generated/scratch state remains in `project-level/-unresolved.md` and `auto-generated/tmp3us4zach` with the old `0x00528deb` filename. These are generated reports/scratch artifacts and should not be edited manually.

## Generated / Simroot Review

`auto-generated/NexusTK/app/MSGHandler.cpp` is the strongest generated source-quality lead for the saved-handler field:

```cpp
class MSGHandler
{
public:
    MSGHandler();
    virtual ~MSGHandler();

    virtual int DispatchMessage();

private:
    MSGHandler* m_previousHandler;
};

MSGHandler::MSGHandler()
    : m_previousHandler(g_pApplication->ExchangeMSGHandler(this))
{
}

int MSGHandler::DispatchMessage()
{
    return m_previousHandler->DispatchMessage();
}
```

This supports `m_previousHandler` as the recommended source-facing name for the saved handler field.

`source-3/simroot_v2/class_MSGHandler.cpp` uses the less final but equivalent name `m_handlerTarget` and confirms the same constructor/destructor/dispatch shape. The app autogen name `m_previousHandler` is better because `Application::ExchangeMSGHandler` returns the previous active target.

`source-3/simroot_v2/class_BrowserControlPaneOld.cpp` confirms current generated leads `m_msgHandler` and `m_pBrowser`:

- Constructor calls `MSGHandler::MSGHandler(&this->m_msgHandler)`.
- Constructor writes `this->m_msgHandler.m_vtable = &BrowserControlPaneOld_msgVtable`.
- Constructor clears and stores `this->m_pBrowser`.
- Scalar deleting destructor calls `MSGHandler::~MSGHandler(&this->m_msgHandler)`.

The same file is also why final C++ must remain blank. It currently emits:

```cpp
// NTK_ScopedInstall(DispatchToBrowser, 0x00528de0)
int BrowserControlPaneOld::DispatchToBrowser()
{
    struct BrowserMsgHandlerState {
        void* m_vtable;
        BrowserObject* m_browserObject;
    };

    BrowserMsgHandlerState* const msgHandler =
        reinterpret_cast<BrowserMsgHandlerState*>(this);

    return msgHandler->m_browserObject->m_vtable->DispatchMessage(
        msgHandler->m_browserObject
    );
}
```

This generated body is semantically wrong at the type/name level. The pointer at subobject `+4` is the saved previous `MSGHandler` target, not the Browser object. The Browser object is at subobject `+8` / outer `+0x110`. Therefore `DispatchToBrowser` is a stale generated helper name, not a final source name.

`auto-generated/NexusTK/browser/Browser.cpp` is currently length `0`, so the Browser emitter route exists but no final C++ has surfaced for this method.

## Ranked Ownership Analysis

### 1. BrowserControlPaneOld [UID:000016]

Evidence for:

- Sole code caller is `BrowserControlPaneOld::HandleBrowserMessage` at `0x0046f36d`.
- Caller has a BrowserControlPaneOld vtable/data route through `0x00613828`.
- Constructor creates the embedded `MSGHandler` subobject at outer `+0x108` and replaces that subobject vtable with a BrowserControlPaneOld handler vtable slice.
- The helper is not referenced by the generic `MSGHandler` vtable.
- Current class and Browser file parents clear 85/85 and route to a valid generated file root.

Evidence against:

- Body is identical to generic `MSGHandler::DispatchMessage`, so behavior alone could mislead ownership.
- Exact source spelling remains uncertain.

Decision: accepted direct owner/emitter.

### 2. MSGHandler [UID:00008S] / MSGHandler file [UID:0000LM]

Evidence for:

- Physical address lies inside the MSGHandler helper island.
- Body is byte-identical to `0x00528dd0`.
- It uses `MSGHandler` saved previous-handler state.

Evidence against:

- Generic MSGHandler vtable slot is `0x0061fbfc -> 0x00528dd0`, not `0x00528de0`.
- `0x00528de0` has only one code xref from the BrowserControlPaneOld message handler.
- Existing `MSGHandler` constructor/destructor/vtable docs already own the generic infrastructure and explicitly split `0001CO` out.

Decision: rejected as direct owner; keep as related infrastructure only.

### 3. Browser class [UID:000013]

Evidence for:

- Current generated simroot misnames the helper `DispatchToBrowser`.
- Browser object pointer is nearby at outer `BrowserControlPaneOld + 0x110`.
- BrowserControlPaneOld owns or references a Browser object for other old-browser paths.

Evidence against:

- IDA/caller layout proves `0x00528de0` uses subobject slot `+4`, while the Browser pointer is subobject slot `+8`.
- The keyboard path in the caller uses `[edi+8]` for Browser-related behavior, separating it from fallback dispatch through `[edi+4]`.
- No Browser vtable or Browser object constructor/destructor path references `0x00528de0`.

Decision: rejected. Browser file remains the emitter only through the BrowserControlPaneOld class owner, not because the helper dispatches to Browser.

## Source-Quality Blocker Resolution

| Blocker from review | Research result | Score impact |
| --- | --- | --- |
| Embedded `MSGHandler` subobject declaration | Constructor/destructor evidence confirms an embedded/secondary subobject at outer `+0x108`. Generated class view names it `m_msgHandler`. Exact C++ spelling as base vs member/adapter is still open. | Resolved enough for `85`, not enough for final C++. |
| Saved previous-handler field | `MSGHandler` constructor stores `Application::ExchangeMSGHandler` return at subobject `+4`; app generated output names it `m_previousHandler`. | Resolved for semantics and naming recommendation. |
| Browser object pointer at outer `+0x110` | Constructor stores Browser pointer at outer `+0x110`; caller uses subobject `+8` for keyboard path. Target uses subobject `+4`, so it is not Browser dispatch. | Resolved and raises confidence. |
| Final helper/member/function name | `DispatchToBrowser` is rejected as final proof. Recommended documentation name stays `BrowserControlPaneOldDispatch`; source candidate should be a neutral fallback helper such as `DispatchUnhandledMessage`/`DispatchToPreviousHandler`, or inlined as `m_msgHandler.DispatchMessage()`, pending final class layout. | Keeps final C++ blank and caps score. |
| Compiler-emitted override glue vs source-authored helper | No vtable/data ref to `0x00528de0`, so it is not the BrowserControlPaneOld virtual override slot itself. It is a directly called helper/glue body from the source path. It may be compiler-materialized from a trivial source helper or base/member call, but not generic compiler vtable glue. | Supports owner route; exact source spelling remains open. |
| Generated output/simroot | App MSGHandler generated output supports `m_previousHandler`; BrowserControlPaneOld simroot supports `m_msgHandler` and `m_pBrowser` but has stale `DispatchToBrowser` typing. Browser emitted file is empty because final C++ remains blank. | Raises completion because leads were investigated; prevents final C++. |

## Why Final C++ Remains Blank

`0001CO` now clears the active code-entry score/emitter gate: `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000016`, and `(85 + 89) / 2 = 87 > 85`. That gate is minimum eligibility, not permission to write weak source.

Final C++ should remain blank because the only generated helper body currently available misnames the saved previous handler as a Browser object and calls the helper `DispatchToBrowser`. Writing that into final output would bake in a contradicted source shape. The behavior is fully understood, but the final original-style C++ spelling is still one of:

- a direct call through the embedded `MSGHandler` member/base dispatch,
- a neutral helper such as `BrowserControlPaneOld::DispatchUnhandledMessage`,
- or an explicit saved-previous-handler forwarder after final header layout is settled.

This uncertainty limits final-source readiness, not range/ownership confidence.

## Exact Recommended Changes

### Target path

Current live tree already matches this recommendation.

```text
Rename:
by-memory/0x00528de0-0x00528deb.BrowserControlPaneOldDispatch.md
to:
by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md
```

### Target metadata

Current live target already matches this metadata. If applying from a stale copy, replace the score/header values with:

```text
*** UID:0001CO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000016 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000016 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Target score rationale

Current live target already has this rationale. If stale, replace the score rationale table with:

```markdown
| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | The page now records the corrected half-open filename/range, sole BrowserControlPaneOld caller, no-direct-callee indirect tail dispatch, neighboring padding, generic MSGHandler split, parent attachment, constructor-derived subobject mapping, saved previous-handler fallback semantics, and why the Browser object pointer is not the dispatch target. It stays below final-C++ completion because the original helper declaration, embedded MSGHandler member spelling, and old-browser source split are still unresolved. |
| Confidence | 89 | Live IDA MCP directly proves the boundary, callsite, decompiled body, padding, generic MSGHandler vtable target at `0x00528dd0`, BrowserControlPaneOld handler vtable/caller route, and constructor layout separating the saved handler from the Browser object pointer. Confidence stays below final-source level because the source-facing declaration and inherited/embedded MSGHandler shape remain open. |
```

### `by-memory/-coverage-report.md`

Current live row already matches this recommendation. Agents remain banned from editing this file; supervisor should use this exact row if reconciling stale coverage:

```markdown
    - [UID:0001CO][0x00528de0-0x00528dec.BrowserControlPaneOldDispatch](by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md) 0x00528de0-0x00528dec | method | BrowserControlPaneOldDispatch : reconstructable : 85% : very strong : Live IDA reconfirms authoritative dispatch bridge bounds, single legacy-browser caller, indirect virtual dispatch through the saved `MSGHandler` target at subobject slot `+4`, no direct callees, `0xcc` padding before/after, generic MSGHandler vtable target at `0x00528dd0`, BrowserControlPaneOld handler vtable/caller route, constructor layout separating the saved handler from the Browser object pointer at outer `+0x110`, BrowserControlPaneOld owner/emitter route, and blank final C++ pending final subobject/source spelling.
```

### `by-class/BrowserControlPaneOld.md`

Current live class page already has the correct score reference. If stale, replace the `0001CO` evidence bullet with:

```markdown
- [UID:0001CO][0x00528de0-0x00528dec.BrowserControlPaneOldDispatch](by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md) is scored `85/89` and records the old-pane unhandled-message fallback bridge outside generic `MSGHandler` ownership. Its authoritative half-open range is `0x00528de0-0x00528dec`; live IDA shows it forwards through the saved previous handler at the embedded `MSGHandler` subobject slot `+4`, not through the Browser object pointer at outer `+0x110`.
```

If stale, add/keep this change note:

```markdown
- 2026-06-16 B001 dispatch range/semantics sync:
  - Changed to: [UID:0001CO][0x00528de0-0x00528dec.BrowserControlPaneOldDispatch](by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md) score reference updated to `85/89` after the filename/range normalization and saved-previous-handler fallback evidence.
  - Summary/evidence: B001 live IDA MCP evidence separates the generic MSGHandler vtable dispatch at `0x00528dd0` from the BrowserControlPaneOld-only caller path at `0x0046f36d`, and the constructor layout distinguishes the saved handler at subobject slot `+4` from the Browser object pointer at outer `+0x110`.
```

### `by-file/Browser.md`

Current live table already has the corrected range. If stale, use:

```markdown
| `BrowserControlPaneOld` | `class_BrowserControlPaneOld.cpp` | `0x0046f220-0x00528dec` | Legacy control pane wrapping a COM-style `Browser` object, spawning `BrowserThread`, and forwarding unhandled private messages through its embedded MSGHandler subobject. |
```

### `by-memory/0x00528d60-0x00528e55.MSGHandler.md`

Current live page already has the correct split line. If stale, use:

```markdown
- `0x00528de0-0x00528dec` [UID:0001CO][0x00528de0-0x00528dec.BrowserControlPaneOldDispatch](by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md), a separate BrowserControlPaneOld-owned fallback bridge physically inside this island; it reuses MSGHandler saved-target state but is not the generic MSGHandler vtable dispatch slot
```

### `by-memory/0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage.md`

Current live page already has the corrected default-path wording. If stale, use:

```markdown
- The default path calls the BrowserControlPaneOld fallback bridge at `0x00528de0`; live IDA shows the bridge forwards the still-pushed message argument through the saved previous `MSGHandler` target at subobject slot `+4`.
```

### `by-project-structure/proposed-source-tree.md`

Current live page already has the correct Browser/MSGHandler ownership split. If stale, use:

```markdown
- `MSGHandler` owns application message-handler swapping and generic dispatch forwarding at `0x00528d60-0x00528e55`; the nested `0x00528de0-0x00528dec` BrowserControlPaneOld fallback bridge is routed through the Browser module because its only code caller is the old browser message handler.
```

### Generated reports and scratch files

Do not manually edit generated files. Current observations:

- `auto-generated/-ag-memory-coverage.md` already has the corrected row and Browser emitter route.
- `auto-generated/NexusTK/browser/Browser.cpp` is length `0` because final C++ is still blank.
- `project-level/-unresolved.md` still has stale old-path references to `0x00528deb`.
- `auto-generated/tmp3us4zach` still has a stale old-path row; treat as generated/scratch state, not documentation authority.

Refresh these through validator/unresolved tooling, not hand edits.

## Validation Commands For Supervisor

After applying or confirming the current state, run:

> Executable block R001 was removed from this report and preserved verbatim in [0001CO-browsercontrolpaneold-dispatch-range-audit-removed.md](0001CO-browsercontrolpaneold-dispatch-range-audit-removed.md). The archived block is non-authoritative and must not be executed.

Then check:

> Executable block R002 was removed from this report and preserved verbatim in [0001CO-browsercontrolpaneold-dispatch-range-audit-removed.md](0001CO-browsercontrolpaneold-dispatch-range-audit-removed.md). The archived block is non-authoritative and must not be executed.

Expected result:

- No non-generated by-* reference to the old `0x00528deb` filename remains.
- `0001CO` row uses `0x00528de0-0x00528dec`, `85%`, and BrowserControlPaneOld owner/emitter route.
- Generated unresolved/scratch references should disappear after the full unresolved scan or remain only in intentionally retained backup/scratch files.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0001CO-browsercontrolpaneold-dispatch-range-audit.md`
- Modified by B001 in this report pass: none outside the B001 research folder.
- by-* docs, generated reports, IDA DB, and `by-memory/-coverage-report.md`: not edited by B001 in this report pass.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001CO-browsercontrolpaneold-dispatch-range-audit.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001CO"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001CO-browsercontrolpaneold-dispatch-range-audit-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001CO-browsercontrolpaneold-dispatch-range-audit.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001CO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
