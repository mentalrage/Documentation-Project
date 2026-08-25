** TARGET-REPORT-UID:00032U **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00032U BrowserControlPaneOldHandleBrowserMessage Empty-Emitter Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00032U] owned by [UID:000016][BrowserControlPaneOld](../../../by-class/BrowserControlPaneOld.md), keep the emitter route through [UID:000016] to [UID:0000HV][Browser](../../../by-file/Browser.md) / `auto-generated/NexusTK/browser/Browser.cpp`, and populate the formal C++ block for the source-authored `MSGHandler::DispatchMessage(MSG*)` override.
- Final disposition: the current empty-emitter marker is caused by blank `RECONSTRUCTION_CPP CODE`, not by bad ownership, bad range, or a missing generated route. The target satisfies the active code-entry gate: `RECONSTRUCTABLE:TRUE`, nonblank `EMITTER_UIDS:000016`, valid route to `Browser.cpp`, and `(85 + 88) / 2 = 86.5 > 85`.
- Required action if accepted: update the target doc with fresh MCP evidence, resolve the public method spelling to `BrowserControlPaneOld::DispatchMessage(MSG *message)`, insert the exact formal C++ below, and synchronize `BrowserControlPaneOld`, `Browser`, `BrowserMessageId`, `g_browserControlKeyCallback`/`WideApiDispatchTable`, and `BrowserControlPaneOldDispatch` support wording without editing generated or manual coverage files.
- Confidence: high for range, ownership, emitted route, switch/table bounds, message semantics, and source-bearing status; medium-high for helper names `InvalidateRect`, `DispatchToPreviousHandler`, and `g_pfnSendMessageW`, which are inferred source-facing names over documented slots.

## Implementation Callback Completion Update

- Implementation status: accepted report applied on 2026-06-29 by Agent-B002.
- Target/support docs changed: UID00032U target, [UID:000016] `BrowserControlPaneOld`, [UID:0000HV] `Browser`, and [UID:0001CO] `BrowserControlPaneOldDispatch`.
- Support docs not edited because same-or-greater detail was already present: [UID:0001SL] `BrowserMessageId` already recommends standard Win32 names for `15/256/257/260/261`; [UID:0001Q1] and [UID:0000TQ] already document `0x0069bec4` as the PlatformApi/WideApi `SendMessageW` dispatch slot with BrowserControlPaneOld as consumer only.
- UID00032U now has `COMPLETION:88`, `CONFIDENCE:91`, unchanged owner/emitter route, and the accepted `LRESULT BrowserControlPaneOld::DispatchMessage(MSG *message)` formal C++ block.
- Leases were taken only for the four changed by-* docs, released immediately after the edit/validator batch, and `tools/leaser/Agents/current_leases.md` had no `Agent-B002` or edited-file entries after release.

## Target

- Target UID: `00032U`
- Target path: `by-memory/0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## Files With Empty Emitters`
- Generated file: `auto-generated/NexusTK/browser/Browser.cpp`
- Current metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:000016`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000016`, blank formal C++.
- Current generated state: `Browser.cpp` refreshed by validator command `000000001048` at `2026-06-29T18:28:10-04:00`; UID00032U appears only as an `Empty Emitter Marker`.
- MCP session used: `B003_0002FZ_20260629`, health `ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, Hex-Rays ready, strings cache ready.

## Current Target State

The page already records the correct exact range, class owner, and switch-table ownership. It is still an empty emitter because the formal C++ header and multiline block are both blank. `Browser.cpp` confirms the route reaches the generated file: [UID:000016] appears as a class-level empty marker and [UID:00032U] appears as a child empty marker.

The current page title uses the descriptive documentation name `HandleBrowserMessage`. Fresh support evidence from [UID:00008S][MSGHandler](../../../by-class/MSGHandler.md) resolves the source-facing signature more narrowly: this vtable slot is the `MSGHandler` secondary-base virtual `DispatchMessage(MSG *message)`. The target should keep the by-memory filename unless the supervisor wants a later rename, but the formal C++ should use `LRESULT BrowserControlPaneOld::DispatchMessage(MSG *message)`.

## Evidence Checked

- Required instructions: `goal.md`, `ntk-b-agent-workflow` skill, `b-agent-research-and-implementation-workflow.md`, `score-blocker-audit-standard.md`, `b-agent-report-template.md`, and relevant `by-structure.md` code-entry/owner/emitter sections.
- Target/support docs: [UID:00032U], [UID:000016] `BrowserControlPaneOld`, [UID:0000HV] `Browser`, [UID:0001CO] `BrowserControlPaneOldDispatch`, [UID:00008S] `MSGHandler`, [UID:0001CN] `MSGHandler`, [UID:0001SL] `BrowserMessageId`, [UID:0001Q1] `0x0069bec4-0x0069bec8.g_browserControlKeyCallback`, [UID:0000PT] stale alias page, [UID:0000TQ] `WideApiDispatchTable`.
- Generated/tracker docs: `auto-generated/NexusTK/browser/Browser.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`.
- Old reports searched with `rg` terms `00032U`, `0x0046f310`, `0x0046f47b`, `BrowserControlPaneOldHandleBrowserMessage`, `HandleBrowserMessage`, `BrowserControlPaneOld`, `BrowserOleLegacyAndHelpers`, and `Browser.cpp` across `executed-b-agent-research` and active agent folders.
- Relevant old reports opened as leads: [UID:0001CO] B001 dispatch range audit and [UID:00032S] B011 destructor/source-quality report. No executed dedicated B report for UID00032U was found; matches were support references only.
- IDA MCP calls: `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `xrefs_to`, `get_bytes`, `func_profile`.
- Negative checks: no direct code callers to `0x0046f310`; no function at `0x0046f378` or `0x0046f47b`; no function at vtable slot address `0x00613828`; no extra function inside the switch-table tail; `0x0046f47b` is the `0xcc` padding byte after the table.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID00032U is an eligible source-bearing empty emitter because only its formal C++ block is blank. | High | Target metadata, `Browser.cpp` marker, by-structure gate. | UID00032U metadata/reconstruction notes | incorporated | applied: UID00032U formal C++ populated; validator `000000001084` ok; generated Browser.cpp lines 384-410 show body and no UID00032U empty marker. |
| C02 | The source-facing method should be `LRESULT BrowserControlPaneOld::DispatchMessage(MSG *message)`, not a separate non-overriding `HandleBrowserMessage` method. | High | `MSGHandler` class emits `virtual LRESULT DispatchMessage(MSG *message)`; vtable slot `0x00613828 -> 0x0046f310`; MCP prototype uses `MSG *` layout. | UID00032U first-draft C++ and BrowserControlPaneOld methods | incorporated | applied: exact signature inserted in UID00032U; BrowserControlPaneOld method row updated; generated Browser.cpp line 385 has `BrowserControlPaneOld::DispatchMessage`. |
| C03 | Function body is `0x0046f310-0x0046f378`; target table tail is `0x0046f378-0x0046f47b`; `0x0046f47b` is padding. | High | MCP `lookup_funcs`, `analyze_function`, `get_bytes`, xrefs to jump targets. | UID00032U scope/table evidence | incorporated | applied: UID00032U IDA evidence now records body, table tail, no separate function, and padding boundary; target validator `000000001084` ok. |
| C04 | `WM_PAINT` case calls primary pane virtual slot `+0x20` with `0`, best current source-facing name `InvalidateRect(0)`, then falls through to previous-handler dispatch. | Medium-high | MCP disasm `mov eax,[edi-108h]`, `lea ecx,[edi-108h]`, `push 0`, `call [eax+20h]`; historical Pane doc names `0x00544800` as `Pane::InvalidateRect`. | UID00032U behavior/C++ notes | incorporated | applied with caveat: UID00032U C++ uses `InvalidateRect(0)` and score rationale records the name as inferred; generated Browser.cpp line 389 shows the call. |
| C05 | `WM_KEYDOWN`, `WM_KEYUP`, `WM_SYSKEYDOWN`, and `WM_SYSKEYUP` forward only `VK_TAB` and `VK_ESCAPE` through the PlatformApi `SendMessageW` slot using `m_browser->m_hWnd`. | High | MCP decompile/disasm; xrefs to `0x0069bec4`; Browser class field `m_hWnd` at Browser object `+0x14`; BrowserMessageId and dispatch-slot docs. | UID00032U behavior/C++ notes; support docs | incorporated | applied/already-present: UID00032U C++ and evidence updated; BrowserMessageId already has standard Win32 row; UID0001Q1/WideApi already document SendMessageW consumer role, so no extra edits were needed there. |
| C06 | Other messages and non-Tab/Escape keyboard messages forward through BrowserControlPaneOld's previous-handler bridge at `0x00528de0`. | High | MCP disasm `push esi; mov ecx, edi; call sub_528DE0`; B001 dispatch report; UID0001CO page. | UID00032U behavior; UID0001CO support | incorporated | applied: UID00032U calls `DispatchToPreviousHandler(message)`; UID0001CO support wording synchronized; validators `000000001081` and `000000001084` ok. |
| C07 | `0x0069bec4` is not browser-owned storage; UID00032U is a consumer of PlatformApi `SendMessageW` dispatch. | High | `xrefs_to 0x0069bec4` has 17 refs including browser and socket consumers; PlatformApi/WideApi docs. | UID00032U and support notes | incorporated | applied/already-present: UID00032U now says Browser is consumer only; UID0001Q1 and WideApiDispatchTable already had same-or-greater PlatformApi ownership detail. |
| C08 | The formal C++ should call a helper named `DispatchToPreviousHandler(message)` and the support bridge UID0001CO should be updated to that inferred helper name if accepted. | Medium-high | UID0001CO body is a direct duplicate previous-handler forwarder; B001 rejected `DispatchToBrowser`; `m_previousHandler` now resolved. | UID00032U C++; UID0001CO support/C++ if supervisor accepts | incorporated | applied/excluded: helper call inserted in UID00032U and UID0001CO support synchronized; UID0001CO formal C++ excluded because the goal explicitly said support wording only and no UID0001CO formal C++. |
| C09 | Scores can move to `88/91` after adding current MCP proof and formal C++; not higher because `InvalidateRect`, helper name, and PlatformApi typedef spelling remain inferred. | Medium-high | Current evidence closes empty-emitter blocker; remaining source names are not original-symbol proven. | UID00032U metadata/score rationale | incorporated | applied: UID00032U metadata is `88/91`; validator `000000001084` recorded `completion_update` and `confidence_update`. |

## Positive Evidence Summary

- MCP `lookup_funcs` reports `sub_46F310` at `0x46f310`, size `0x68`; `0x0046f378` and `0x0046f47b` are not functions.
- MCP `analyze_function 0x0046f310` decompiles a switch over `message->message`, with handled cases `15`, `256`, `257`, `260`, and `261`.
- MCP xrefs show the only incoming xref to `0x0046f310` is data at `0x00613828`, the BrowserControlPaneOld `MSGHandler` secondary-base vtable dispatch slot.
- MCP xrefs show `0x00528de0` has one code caller at `0x0046f36d` inside this target.
- The target has no strings, two meaningful callees (`unk_69BEC4` and `sub_528DE0`), 38 instructions, 7 basic blocks, and cyclomatic complexity 5.
- `get_bytes` confirms the body bytes end at `0x0046f378`; the tail bytes are jump-table dwords plus a selector byte table, with a `0xcc` padding byte after the target at `0x0046f47b`.
- `MSGHandler` support now emits the exact virtual declaration `virtual LRESULT DispatchMessage(MSG *message);`, removing the method-spelling blocker for UID00032U.

## IDA MCP Facts

### Function/range facts

| Item | MCP result | Meaning |
| --- | --- | --- |
| `0x0046f310` | `sub_46F310`, size `0x68` | Function body `0x0046f310-0x0046f378`. |
| `0x0046f378` | not a function | Start of compiler switch table. |
| `0x0046f47b` | not a function | First byte after selector table; `0xcc` padding. |
| `0x00528de0` | `sub_528DE0`, size `0x0c` | Previous-handler fallback bridge called by default path. |
| `0x00613828` | not a function | Data/vtable slot pointing to `0x0046f310`. |

### Core disassembly facts

```asm
0046f31a  mov ecx, [esi+4]        ; MSG.message
0046f327  movzx eax, byte_46F384[eax]
0046f32e  jmp dword ptr jpt_46F32E[eax*4]
0046f335  mov eax, [esi+8]        ; MSG.wParam
0046f338  cmp eax, 9              ; VK_TAB
0046f33d  cmp eax, 1Bh            ; VK_ESCAPE
0046f342  push dword ptr [esi+0Ch]; MSG.lParam
0046f345  push eax
0046f346  mov eax, [edi+8]        ; BrowserControlPaneOld::m_browser from MSGHandler-base view
0046f349  push ecx                ; MSG.message
0046f34a  push dword ptr [eax+14h]; Browser::m_hWnd
0046f34d  call dword ptr unk_69BEC4
0046f359  mov eax, [edi-108h]     ; primary BrowserControlPaneOld view
0046f35f  lea ecx, [edi-108h]
0046f365  push 0
0046f367  call dword ptr [eax+20h]
0046f36a  push esi
0046f36b  mov ecx, edi            ; MSGHandler secondary-base view
0046f36d  call sub_528DE0
```

### Switch/table facts

- Jump table dwords at `0x0046f378`: `0x0046f359`, `0x0046f335`, `0x0046f36a`.
- Selector bytes start at `0x0046f384`, cover `247` values for messages `15..261`, and end at `0x0046f47b` exclusive.
- MCP comments identify `0x0046f335` as cases `256,257,260,261`, `0x0046f359` as case `15`, and `0x0046f36a` as default plus cases `16-255,258,259`.
- The target page correctly owns the switch data. No separate source owner should be created for the table.

### Xref facts

| Address | Xref result | Meaning |
| --- | --- | --- |
| `0x0046f310` | one data xref from `0x00613828` | BrowserControlPaneOld `MSGHandler` secondary-base virtual slot. |
| `0x00528de0` | one code xref from `0x0046f36d` | Default/fallback route is UID0001CO. |
| `0x0069bec4` | 17 xrefs, including `0x0046f34d` and `0x0046f0e6` browser consumers plus platform/socket refs | PlatformApi `SendMessageW` dispatch slot, not Browser-owned storage. |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0046f310-0x0046f378` | [UID:00032U](../../../by-memory/0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage.md) | Source-authored `DispatchMessage(MSG*)` override body | TRUE | [UID:000016] | current `85/88`, recommend `88/91` | formal C++ ready |
| `0x0046f378-0x0046f47b` | same page | compiler switch table for UID00032U | TRUE as target-owned data | [UID:000016] | same | keep in target range, no separate source item |
| `0x00528de0-0x00528dec` | [UID:0001CO](../../../by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md) | previous-handler fallback bridge | TRUE | [UID:000016] | `85/89` | support helper, still empty marker |
| `0x0069bec4-0x0069bec8` | [UID:0001Q1](../../../by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) | PlatformApi `SendMessageW` dispatch slot | TRUE | [UID:0000ML] | `88/90` | consumer evidence only for UID00032U |

## Ranked Ownership Analysis

### 1. BrowserControlPaneOld [UID:000016]

Evidence for:

- The only xref to `0x0046f310` is the BrowserControlPaneOld `MSGHandler` secondary-base vtable slot at `0x00613828`.
- `BrowserControlPaneOld` docs and B011 destructor support prove secondary-base `MSGHandler` starts at outer `+0x108`; this method is entered with `ecx` equal to that base view and reaches full-object state by `this-0x108` where needed.
- The function accesses the old pane's Browser pointer from subobject `+8` / outer `+0x110`.
- The fallback call is to the BrowserControlPaneOld-only bridge [UID:0001CO].

Evidence against:

- The by-memory documentation title `HandleBrowserMessage` is descriptive rather than the best source-facing override name.
- The helper names for pane invalidation and previous-handler dispatch are inferred, not PDB-proven.

Decision: accepted direct owner and emitter. The naming uncertainty does not block formal C++ after `MSGHandler::DispatchMessage(MSG*)` was resolved.

### 2. Generic MSGHandler [UID:00008S]

Evidence for:

- The target is a `MSGHandler` virtual override and receives a `MSG *`.
- Default forwarding uses `MSGHandler::m_previousHandler` semantics.

Evidence against:

- The vtable slot is BrowserControlPaneOld's secondary-base vtable, not generic `MSGHandler` vtable `0x0061fbf8`.
- The body uses BrowserControlPaneOld state: primary pane view at `this-0x108`, Browser pointer at `this+8`, and the BrowserControlPaneOld fallback bridge.

Decision: reject as direct owner. MSGHandler owns the interface and previous-handler field semantics; BrowserControlPaneOld owns this override body.

### 3. Browser class / Browser object [UID:000013]

Evidence for:

- Keyboard forwarding reaches `m_browser->m_hWnd`.
- The route eventually emits through Browser.cpp.

Evidence against:

- The Browser object is a field/consumer target at `BrowserControlPaneOld + 0x110`; no Browser vtable or Browser COM method owns the target body.
- The default fallback does not dispatch through Browser. B001 already rejected stale `DispatchToBrowser` naming for UID0001CO.

Decision: reject as direct owner. Browser is the source file route, not the semantic owner.

### 4. PlatformApi / WideApiDispatchTable

Evidence for:

- The keyboard branch calls `0x0069bec4`, which PlatformApi docs resolve as `SendMessageW`.

Evidence against:

- PlatformApi owns the function-pointer storage only. It does not own this browser message-handler method.

Decision: support dependency only.

## Heuristic / Inference Reanalysis And Validation

- Empty-emitter cause: resolved. The formal C++ block is blank despite a valid owner/emitter/score route.
- Method spelling: resolved to `DispatchMessage(MSG *message)` because `MSGHandler` now emits that virtual declaration and the vtable slot is the old pane's `MSGHandler` secondary-base override.
- Message constants: use standard Win32 names `WM_PAINT`, `WM_KEYDOWN`, `WM_KEYUP`, `WM_SYSKEYDOWN`, `WM_SYSKEYUP`, `VK_TAB`, and `VK_ESCAPE`. `BrowserMessageId` explicitly recommends standard names for values `15/256/257/260/261` unless future evidence proves browser-local aliases.
- `SendMessageW` slot name: use inferred PlatformApi style `g_pfnSendMessageW`; support docs prove the role but not final typedef/global spelling. This is acceptable first-draft source naming and better than stale `g_browserControlKeyCallback`.
- Pane invalidation name: use `InvalidateRect(0)`. Historical Pane docs name `0x00544800` as `Pane::InvalidateRect`; current coverage rows describe vtable slot `+0x20` as invalidation/refresh. Keep the exact original name caveat in support notes.
- Previous-handler helper: use `DispatchToPreviousHandler(message)` for source readability and to avoid the rejected `DispatchToBrowser` name. If accepted, update UID0001CO support docs to make this the preferred inferred helper spelling; its formal C++ can be populated in a later/paired callback if the supervisor chooses to include UID0001CO.
- Range/table: no split needed. The switch table belongs to the source lowering of this method and should stay in UID00032U.

## Negative Evidence Summary

- No direct code callers target `0x0046f310`; reachability is vtable-only through `0x00613828`, which is expected for an override.
- No function starts at `0x0046f378` or `0x0046f47b`; those addresses are table/padding, not missed source functions.
- No evidence supports moving the target to generic MSGHandler. Generic `MSGHandler::DispatchMessage` is the separate vtable slot at `0x00528dd0`; this override body uses BrowserControlPaneOld state.
- No evidence supports Browser-object ownership. The Browser pointer is only used for its window handle in the keyboard branch.
- No evidence supports browser ownership of `0x0069bec4`; PlatformApi/WideApi evidence and broad socket refs reject that stale alias.
- No stale Wave2/Wave3 material was used as authority. Old generated names were used only as rejected leads.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. The target is reconstructable, routed, source-bearing, and above the active score gate.

Recommended formal `RECONSTRUCTION_CPP CODE` insertion text for [UID:00032U]:

```cpp
LRESULT BrowserControlPaneOld::DispatchMessage(MSG *message)
{
    switch (message->message)
    {
    case WM_PAINT:
        InvalidateRect(0);
        break;

    case WM_KEYDOWN:
    case WM_KEYUP:
    case WM_SYSKEYDOWN:
    case WM_SYSKEYUP:
        if (message->wParam == VK_TAB || message->wParam == VK_ESCAPE)
        {
            return g_pfnSendMessageW(m_browser->m_hWnd,
                                     message->message,
                                     message->wParam,
                                     message->lParam);
        }
        break;

    default:
        break;
    }

    return DispatchToPreviousHandler(message);
}
```

Reason it preserves behavior:

- The switch cases match IDA: `WM_PAINT` routes to primary pane slot `+0x20` with zero, keyboard messages filter `VK_TAB`/`VK_ESCAPE`, and everything else falls through to UID0001CO.
- The `SendMessageW` argument order matches the stack pushes at `0x0046f342-0x0046f34a`.
- `m_browser->m_hWnd` corresponds to Browser object offset `+0x14`, loaded through BrowserControlPaneOld `m_browser` at subobject `+8` / outer `+0x110`.
- `DispatchToPreviousHandler(message)` corresponds to the direct call to UID0001CO with the same `MSG *` argument still on the stack.

Names used:

- `DispatchMessage(MSG*)` is resolved by [UID:00008S] `MSGHandler`.
- `m_browser` is resolved by `BrowserControlPaneOld` layout support.
- `g_pfnSendMessageW` is inferred from PlatformApi naming style and the proven `SendMessageW` dispatch slot.
- `InvalidateRect` and `DispatchToPreviousHandler` are inferred source-facing helper names; document them as inferred, not original-proof.

## Recommended Target Doc Changes

Target path: `by-memory/0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage.md`

- Recommended metadata:
  - `COMPLETION:88`
  - `CONFIDENCE:91`
  - `CANONICAL_OWNER:000016`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:000016`
  - blank `EMITTER_POSITION_OPTIONAL`
- Populate formal C++ with the block above.
- Add current MCP evidence: session `B003_0002FZ_20260629`, function size `0x68`, xref `0x00613828`, switch cases, `0x0069bec4` xrefs, and table bytes through `0x0046f47a`.
- Replace any implication that final message enum names block C++ with the current resolution: standard Win32 names are the preferred source shape for this method.
- Add a source-quality note that the by-memory filename/title remains descriptive, but the source-facing method is `DispatchMessage(MSG*)`.
- Preserve negative evidence rejecting Browser-object ownership of the fallback and Browser ownership of the `SendMessageW` slot.

## Recommended Support Doc Changes

### [UID:000016] `by-class/BrowserControlPaneOld.md`

- In the Methods row for UID00032U, state that the source-facing method is `DispatchMessage(MSG *message)` / old-browser message handler.
- Add that UID00032U is first-draft C++ ready and should emit through the exact child page.
- Replace the class-wide caveat "Final public method spelling for the message override (`HandleBrowserMessage` versus `DispatchMessage`)" with the resolved direction: use `DispatchMessage(MSG*)` for the override; keep `HandleBrowserMessage` only as a descriptive by-memory title if not renaming now.
- Add inferred helper caveat: `InvalidateRect(0)` and `DispatchToPreviousHandler(MSG*)` names are source-facing inferences pending a broader pane/helper naming audit.

### [UID:0000HV] `by-file/Browser.md`

- Add a source-quality sync note that [UID:00032U] now emits the old pane `DispatchMessage(MSG*)` override under `Browser.cpp`.
- Preserve the broader Browser.cpp vs `BrowserLegacy.cpp` split as a file-level caveat, but mark it nonblocking for this exact child.

### [UID:0001CO] `0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md`

- Keep owner/emitter as [UID:000016].
- Update the final helper-spelling caveat: UID00032U's first-draft code should call it `DispatchToPreviousHandler(message)`, not `DispatchToBrowser`.
- If the supervisor accepts paired helper emission, populate UID0001CO with a matching formal helper body in a separate accepted step. If not accepted now, at minimum preserve it as the required helper dependency for UID00032U.

Suggested helper C++ for a paired future callback, if the supervisor decides UID0001CO is in the accepted implementation scope:

```cpp
LRESULT BrowserControlPaneOld::DispatchToPreviousHandler(MSG *message)
{
    return MSGHandler::DispatchMessage(message);
}
```

This helper body is not the UID00032U formal block; it belongs only to UID0001CO if accepted.

### [UID:0001SL] `BrowserMessageId`

- Add that UID00032U C++ uses standard Win32 names for `15/256/257/260/261`, so enum names should not block this child.
- Keep private thread messages `1280/1281` outside this target's C++.

### [UID:0001Q1] / [UID:0000TQ] dispatch-slot support

- Add or confirm that UID00032U consumes `SendMessageW` at `0x0069bec4` for Tab/Escape forwarding.
- Keep storage owner as PlatformApi/WideApiDispatchTable and reject stale browser-local `g_browserControlKeyCallback` ownership.

## Score And Metadata Recommendation

- Current score/metadata: `85/88`, owner [UID:000016], reconstructable true, emitter [UID:000016], formal C++ blank.
- Recommended score/metadata: `88/91`, owner/emitter unchanged, formal C++ populated.
- Reason not higher: helper names `InvalidateRect`, `DispatchToPreviousHandler`, and `g_pfnSendMessageW` remain inferred source-facing names rather than original-symbol proof; broader Browser file split remains plausible but nonblocking.
- Reason not lower: current MCP proves the exact body, switch table, vtable route, fallback helper, SendMessageW consumer role, and standard Win32 message names; the only empty-emitter blocker has an implementation-ready formal C++ block.

## Open Questions With Attempted Resolution

- Original by-memory filename/method title:
  - Checked `MSGHandler` support and vtable route.
  - Resolution: keep file title unless renaming is desired, but formal C++ must use `DispatchMessage(MSG*)`.
- Pane slot `+0x20` exact source name:
  - Checked vtable bytes, lookup of `0x00544800`, historical docs naming it `Pane::InvalidateRect`, and broad coverage references to invalidation/refresh.
  - Resolution: use `InvalidateRect(0)` as best source-facing first draft; record as inferred.
- Previous-handler helper exact source spelling:
  - Checked B001 dispatch audit, UID0001CO page, and MSGHandler field resolution.
  - Resolution: reject `DispatchToBrowser`; use inferred `DispatchToPreviousHandler`.
- PlatformApi function pointer exact typedef/name:
  - Checked PlatformApi/WideApi docs and generated PlatformApi output.
  - Resolution: use inferred `g_pfnSendMessageW`; storage ownership is settled even if typedef spelling is not.

## Validator Results

- Implementation validators run:
  - `000000001077` at `2026-06-29T19:17:21-04:00`: `python .\tools\validator.py --mode file --file by-class\BrowserControlPaneOld.md --apply --queue-timeout 240`; exit `0`, `ok: 1`, generated refresh deferred, warnings: `stats_incremental_noop` because project-level generated stats file is not present in generated stats lists.
  - `000000001079` at `2026-06-29T19:17:33-04:00`: `python .\tools\validator.py --mode file --file by-file\Browser.md --apply --queue-timeout 240`; exit `0`, `ok: 1`, generated refresh deferred, warnings: pre-existing `missing_ref_uid` entries for `000407`, `000408`, `000409`, `00040A`, `00040B`, `00040C`, and `0003OH`; plus `stats_incremental_noop`.
  - `000000001081` at `2026-06-29T19:17:42-04:00`: `python .\tools\validator.py --mode file --file by-memory\0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md --apply --queue-timeout 240`; exit `0`, `ok: 1`, generated refresh deferred, warnings: `stats_incremental_noop`.
  - `000000001084` at `2026-06-29T19:17:52-04:00`: `python .\tools\validator.py --mode file --file by-memory\0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage.md --apply --queue-timeout 240 --wait-generated`; exit `0`, `ok: 1`, `completion_update 00032U 88`, `confidence_update 00032U 91`, `autogen_registry_update` blank -> block, `generated_refresh: completed`, `generated_refresh_command_id: 000000001084`, `generated_refresh_timestamp: 2026-06-29T19:17:52-04:00`; broad autogen informational warnings were emitted for existing no-code emitters and missing preferred children markers.
- Generated freshness confirmed:
  - `auto-generated/NexusTK/browser/Browser.cpp` header shows `validator-command-id: 000000001081`, `validator-refreshed-at: 2026-06-29T19:17:42-04:00`, and file write time `2026-06-29 19:18:00`.
  - Direct generated inspection after target validator `000000001084` shows UID00032U at Browser.cpp line 384, `LRESULT BrowserControlPaneOld::DispatchMessage(MSG *message)` at line 385, and `DispatchToPreviousHandler(message)` at line 410.
  - UID00032U no longer appears as an `Empty Emitter Marker`; remaining empty markers in Browser.cpp belong to other UIDs such as UID00032Z, UID000331, UID000015, UID000016, UID00032T, UID0001CO, and others outside this accepted scope.

## Changed Files

- Modified by-* docs:
  - `by-memory/0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage.md`
  - `by-class/BrowserControlPaneOld.md`
  - `by-file/Browser.md`
  - `by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md`
- Modified Agent-B002 report:
  - `tools/leaser/Agents/Agent-B002/research/00032U-BrowserControlPaneOldHandleBrowserMessage-empty-emitter-source-quality.md`
- Validator-owned generated/tool files refreshed by scoped validator runs were not manually edited.
- Leases: Agent-B002 leased the four changed by-* docs for the edit/validator batch and released all four immediately after validation. Post-release check found no `Agent-B002` or edited-file entries in `tools/leaser/Agents/current_leases.md`.
- Report execution: not performed; report was not moved or archived.

## Implementation Tracking Checklist

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded with command IDs/timestamps/results.
- [x] Generated Browser.cpp freshness confirmed against validator command metadata and direct UID00032U body/no-empty-marker inspection.
- [x] Leases released and release proof recorded.
- [x] Remaining unapplied accepted items listed with exact blocker: none. UID0001CO formal helper C++ was not an accepted item in this callback and remains intentionally excluded.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00032U-BrowserControlPaneOldHandleBrowserMessage-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/00032U-BrowserControlPaneOldHandleBrowserMessage-empty-emitter-source-quality.md","timestamp":"2026-06-29T19:22:39","uid":"00032U"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
