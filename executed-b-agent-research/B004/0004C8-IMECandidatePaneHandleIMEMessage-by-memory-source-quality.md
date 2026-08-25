** TARGET-REPORT-UID:0004C8 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# Source-quality report: UID 0004C8

Target: `by-memory/0x004e7d00-0x004e7d24.IMECandidatePaneHandleIMEMessage.md`  
Assignment: `B004-report-0004C8-IMECandidatePaneHandleIMEMessage-by-memory-20260701`  
Mode: report-only research; no target/support/generated/coverage/tool-state edits.

## Current state

- Target header currently records `COMPLETION: 82`, `CONFIDENCE: 90`, `CANONICAL_OWNER: 00006F`, `RECONSTRUCTABLE: TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and no accepted formal C++ body.
- Target summary already describes a split child for `IMECandidatePane::HandleIMEMessage` that checks IME candidate-list event type `15` and forwards to `IMECandidatePane::ShowCandidateList` at `0x004e7930` after a primary-object adjustment.
- The existing target intentionally kept the emitter/body blank because the B008 split report created the child range but left child-specific bodies for later source-quality reports.
- The current generated source check found no `UID:0004C8` or `IMECandidatePane::HandleIMEMessage` marker/body in `auto-generated/NexusTK/input/IMEPanes.cpp`, consistent with the blank target emitter/body state.

## Evidence checked

### Required existing-report search

Searched existing agent reports and executed research for the required terms:

- `0004C8`
- `0x004e7d00`
- `0x004e7d24`
- `IMECandidatePaneHandleIMEMessage`
- `IMECandidatePane`
- `ShowCandidateList`
- `Event type 15`
- `IMEPanes`

Relevant prior reports found:

- `executed-b-agent-research/B008/0000K5-IMEPanes-empty-emitter-family-source-quality.md`
  - Created/split UID0004C8 under the IME pane family.
  - Recorded route `[UID:00006F] -> [UID:0000K5]`.
  - Described `0x004e7d00-0x004e7d24` as Event type `15`, calling UID00018B after `this-0xa0`.
  - Left new child emitters blank until child-specific body reports were accepted.
- `executed-b-agent-research/B001/00018B-ime-candidate-show-candidate-list-source-quality.md`
  - Proved UID00018B is `IMECandidatePane::ShowCandidateList`.
  - Recorded UID0004C8 as the sole caller at `0x004e7d13`.
  - Recorded the Event type `15` guard and `this-0xa0` adjustment.
  - Linked Event payload offsets: candidate list/deque pointer at Event `+0x08`, selected row at Event `+0x0c`.
- `executed-b-agent-research/B010/0004CE-IMEPaneHandleIMEMessage-source-quality.md`
  - Proved root `IMEPane::HandleIMEMessage` dispatches candidate-list work to `IMECandidatePane::HandleIMEMessage(event)`.
  - Required `friend class IMEPane` so the root pane can call the protected child method.
- `executed-b-agent-research/B010/0004C9-IMECandidatePaneOnPaint-source-quality.md`
  - Supports the candidate-pane field model used by UID00018B and this target.
- `executed-b-agent-research/B009/0004C7-IMECandidatePaneConstructor-source-quality.md`
  - Supports the IMECandidatePane construction/vtable context. One stale label in that report appears to call this neighbor an ordinary destructor; current MCP and target evidence supersede that typo.

### Target and support docs checked

- `by-memory/0x004e7d00-0x004e7d24.IMECandidatePaneHandleIMEMessage.md`
- `by-class/IMECandidatePane.md`
- `by-file/IMEPanes.md`
- `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`
- `by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md`
- `by-memory/0x004e81b0-0x004e8433.IMEPaneHandleIMEMessage.md`
- `by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md`
- `by-memory/0x004e8af0-0x004e970d.InputMan.md`
- `by-file/Event.md`
- `by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md`

### IDA MCP state

IDA MCP was available and mandatory evidence was collected from the active database:

- `idb_list` active database: `NexusTK.exe.i64`
- Session: `supervisor_resume_20260629`
- Input path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- `server_health`: `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready: true`, `hexrays_ready: true`
- MCP tools used narrowly: `lookup_funcs`, `analyze_function`, `disasm`, `decompile`, `xrefs_to`, `callees`, `get_bytes`, `get_int`, `int_convert`

## Positive evidence

### Exact range and function identity

MCP `lookup_funcs` results:

- `0x004e7d00` resolves to `sub_4E7D00`, size `0x24`.
- `0x004e7d13` and `0x004e7d23` resolve inside the same function.
- `0x004e7d24` is not a function start.
- `0x004e7d30` resolves to the next function, `sub_4E7D30`, size `0x1ea`.
- `0x004e7cfc` is not a function start.

MCP `get_bytes` boundary proof:

- `0x004e7cfc-0x004e7d00`: four `0xcc` padding bytes before the target.
- `0x004e7d24-0x004e7d30`: twelve `0xcc` padding bytes after the target.

Disposition: the target range `0x004e7d00-0x004e7d24` is exact and self-contained.

### Current decompiler body

MCP `analyze_function` / `decompile` body:

```cpp
char __thiscall sub_4E7D00(int *this, int a2)
{
  if ( *(_BYTE *)(a2 + 4) != 15 )
    return 0;
  sub_4E7930(this - 40, a2);
  return 1;
}
```

Key facts:

- Event type byte is read at Event `+0x04`.
- The only accepted event type is decimal `15` (`0x0f`).
- False branch returns `0`.
- True branch calls `sub_4E7930`.
- The `this - 40` typed-int adjustment is a byte adjustment of `-0xa0`.
- True branch returns `1`.

### Current disassembly

MCP `disasm 0x004e7d00` confirms the branch/call shape:

```asm
0x004e7d03  mov     eax, [ebp+arg_0]
0x004e7d06  cmp     byte ptr [eax+4], 0Fh
0x004e7d0a  jnz     loc_4E7D1E
0x004e7d0c  push    eax
0x004e7d0d  add     ecx, 0FFFFFF60h
0x004e7d13  call    sub_4E7930
0x004e7d18  mov     al, 1
0x004e7d1b  retn    4
0x004e7d1e  xor     al, al
0x004e7d20  mov     esp, ebp
0x004e7d22  pop     ebp
0x004e7d23  retn    4
```

Disposition: the source body is a narrow protected virtual-style boolean event filter:

1. If `event->m_type != kEventImeCandidateList`, return `false`.
2. Otherwise call `ShowCandidateList(event)`.
3. Return `true`.

### Call graph and vtable reachability

MCP `callees 0x004e7d00`:

- Sole callee: `0x004e7930` / UID00018B `IMECandidatePane::ShowCandidateList`.

MCP `xrefs_to 0x004e7930`:

- Sole code xref to UID00018B is from `0x004e7d13` inside this target.

MCP `xrefs_to 0x004e7d00`:

- No direct code callers.
- Data xref from `0x0061c4cc`.

MCP `get_int 0x0061c4cc` plus `int_convert`:

- `0x0061c4cc` stores decimal `5143808`.
- `int_convert` confirms decimal `5143808` is `0x004e7d00`, bytes `00 7d 4e 00`.

Support doc `by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md` records the IMECandidatePane secondary vtable base at `0x0061c4c0`; `0x0061c4cc` is therefore an IMECandidatePane secondary vtable slot, not dead code.

Disposition: direct code callers are absent because this is a virtual child handler reached through pane dispatch/vtables; the data xref is strong live-code evidence.

### Event type 15 and payload provenance

Support doc `by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md` records:

- Event type `15` is the IME candidate-list event.
- Factory `0x004a9e50` dispatches the candidate-list event.
- Event `+0x08` stores the candidate deque/list pointer.
- Event `+0x0c` stores the selected candidate row.
- Event `+0x10c` stores the tick.

Current MCP `decompile 0x004a9e50` confirms:

```cpp
void __stdcall sub_4A9E50(int a1, int a2, int a3)
{
  ...
  v7 = a3;
  v5 = a2;
  v6 = a1;
  v8 = 0;
  v4 = 15;
  sub_4A6EF0(g_dispatcher, &v3);
  ...
}
```

Current MCP `disasm 0x004a9e50` confirms the stack Event layout:

- Argument 0 is stored into Event `+0x08`.
- Argument 1 is stored into Event `+0x0c`.
- Argument 2 is stored into Event `+0x10c`.
- Event type is set to `0x0f`.

Support doc `by-memory/0x004e8af0-0x004e970d.InputMan.md` records the producer path:

- The `WM_IME_NOTIFY` candidate branch builds visible candidates.
- It computes selected row as `candidateList->dwSelection - pageStart`.
- It calls `DispatchCandidateListEvent(..., visibleCandidates, GetMessageTime())`.

Support doc `by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md` records the consumer path:

- UID00018B is `IMECandidatePane::ShowCandidateList(const Event *event)`.
- It consumes `event->imeCandidateStrings` and `event->imeCandidateSelectedRow`.
- Its sole caller is this target at `0x004e7d13`.

Disposition: event type `15` has strong producer, dispatcher, and consumer evidence.

## Negative evidence and rejected alternatives

### No-code / non-emitting classification rejected

Evidence against no-code:

- MCP identifies a real function at `0x004e7d00` with exact size `0x24`.
- The function has executable branch/call behavior, not padding, thunk-only glue, or compiler-only destruction.
- `0x0061c4cc` stores a vtable pointer to `0x004e7d00`.
- Root `IMEPane::HandleIMEMessage` source dispatch reaches the child candidate pane handler.
- UID00018B has this target as its sole code caller.

Disposition: mark as source-authored, reconstructable, emitting C++.

### Merge into UID00018B rejected

UID00018B is the candidate-list UI update implementation. This target is the IME-message gate that decides whether to invoke UID00018B. Evidence:

- Target range is a separate `0x24` function with its own vtable data xref.
- UID00018B range begins at `0x004e7930`.
- UID00018B has sole caller `0x004e7d13`, proving a caller/callee relationship rather than one combined source block.

Disposition: keep UID0004C8 as a separate method body.

### InputMan/Event ownership rejected

InputMan and Event support the producer/factory side only:

- InputMan builds the IME candidate list and selected row.
- Event factory `0x004a9e50` packages Event type `15`.
- This target is the pane-side consumer/dispatcher and directly invokes `IMECandidatePane::ShowCandidateList`.

Disposition: do not assign canonical ownership to InputMan or Event.

### File-only or aggregate-only ownership rejected

`by-file/IMEPanes.md` and `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md` are correct support/aggregate documents, but the most precise owner is the class document:

- Class support doc declares `protected: virtual bool HandleIMEMessage(const Event *event);`.
- Root support doc calls the method through `candidatePane->HandleIMEMessage(event)`.
- Vtable data xref is in the IMECandidatePane secondary vtable area.

Disposition: keep canonical owner `00006F`; file route remains `[UID:00006F] -> [UID:0000K5]`.

### Generic Pane or base IMEPane ownership rejected

The method belongs to `IMECandidatePane`, not generic `Pane` or root `IMEPane`:

- It calls `IMECandidatePane::ShowCandidateList`.
- The true branch adjusts the secondary-subobject pointer by `-0xa0` to recover the primary IMECandidatePane object.
- The root `IMEPane::HandleIMEMessage` method is separately documented in UID0004CE and dispatches to this child.

Disposition: source placement remains `IMECandidatePane` inside `IMEPanes.cpp`.

## Heuristic reanalysis

### Why the current blank emitter exists

The blank emitter is a staging artifact from the B008 family split. The target was separated correctly and documented with good behavioral notes, but the body had not yet received child-specific source-quality research. Current MCP and cross-doc proof now close that gap.

### Why this is source-level code

The function is too semantic to classify as compiler-only glue:

- It filters an Event type constant.
- It normalizes a secondary object pointer to the primary `IMECandidatePane`.
- It calls a named class method that consumes a typed Event payload.
- It returns a source-visible boolean.

The likely original source was a small virtual override:

```cpp
bool IMECandidatePane::HandleIMEMessage(const Event *event)
{
    if (event->m_type != kEventImeCandidateList) {
        return false;
    }

    ShowCandidateList(event);
    return true;
}
```

The `this - 40` decompiler expression is an artifact of the current integer pointer type. In bytes, `40 * sizeof(int) == 0xa0`, matching the documented secondary-to-primary adjustment and class layout context. The accepted C++ should not spell that adjustment because source code calls the member method on the primary object after dispatch/vtable adjustment.

## Owner and source disposition

Recommended disposition:

- `CANONICAL_OWNER: 00006F`
- `EMITTER_UIDS: 00006F`
- `EMITTER_POSITION_OPTIONAL:` remain blank unless the supervisor wants an explicit class-order position.
- `RECONSTRUCTABLE: TRUE`
- Source file route: `[UID:00006F] IMECandidatePane -> [UID:0000K5] IMEPanes`

Rationale:

- The class doc already declares `IMECandidatePane::HandleIMEMessage(const Event *event)`.
- The vtable slot is in IMECandidatePane secondary vtable territory.
- The only callee is `IMECandidatePane::ShowCandidateList`.
- The event producer/factory docs support behavior but are not ownership targets.

## Score and metadata recommendation

Recommended target metadata:

- `COMPLETION: 88`
- `CONFIDENCE: 91`
- `CANONICAL_OWNER: 00006F`
- `RECONSTRUCTABLE: TRUE`
- `EMITTER_UIDS: 00006F`
- `EMITTER_POSITION_OPTIONAL:` blank

Rationale for `88/91`:

- Raise above the current `82/90` because the target now has exact MCP range proof, exact vtable data xref proof, exact branch/call proof, Event factory proof, and an implementation-ready formal C++ body.
- Keep completion below the low-90s because the accepted source names for the Event type constant and Event field names remain reconstructed from project conventions rather than recovered source symbols.
- Confidence can rise to `91` because independent evidence agrees across MCP, target docs, class docs, file docs, aggregate docs, Event factory docs, InputMan producer docs, and UID00018B consumer docs.

## Formal C++ disposition

Recommended target header block C++:

```cpp
bool IMECandidatePane::HandleIMEMessage(const Event *event)
{
    if (event->m_type != kEventImeCandidateList) {
        return false;
    }

    ShowCandidateList(event);
    return true;
}
```

Notes:

- Use `event->m_type` for consistency with accepted root `IMEPane::HandleIMEMessage` C++ and Event docs that identify Event `+0x04` as `m_type`.
- Use `kEventImeCandidateList` for Event type `15`; if the project later standardizes a different enum spelling, this body should follow that enum rename.
- Do not include explicit `this-0xa0` in source C++; the adjustment is compiler/ABI output caused by secondary-subobject dispatch.
- Do not inline UID00018B; it is a separate class method and accepted callee.

No-code disposition: rejected.

## Implementation-ready doc changes

These are recommendations only for a future implementation callback. This report-only pass did not apply them.

### Target doc

File: `by-memory/0x004e7d00-0x004e7d24.IMECandidatePaneHandleIMEMessage.md`

Apply:

- Set `COMPLETION: 88`.
- Set `CONFIDENCE: 91`.
- Set `EMITTER_UIDS: 00006F`.
- Leave `EMITTER_POSITION_OPTIONAL:` blank unless directed otherwise.
- Insert the recommended formal C++ body in the target header block.
- Update status/evidence to cite current MCP proof:
  - `sub_4E7D00` exact size `0x24`.
  - Event type check at Event `+0x04` against `0x0f`.
  - False branch returns `false`.
  - True branch calls UID00018B at `0x004e7d13` after `this-0xa0`.
  - True branch returns `true`.
  - Data xref/vtable slot `0x0061c4cc -> 0x004e7d00`.
  - No direct code callers are expected for this virtual child method.
  - Padding before and after the target confirms exact boundaries.
  - Event factory `0x004a9e50` and InputMan producer establish Event type `15` payload semantics.

### Class support doc

File: `by-class/IMECandidatePane.md`

Apply:

- Update the `HandleIMEMessage` method row to include UID0004C8, score `88/91`, and a note that it returns false unless Event type `15`, then forwards to `ShowCandidateList`.
- Add/update evidence note:
  - MCP verified vtable slot `0x0061c4cc` points to `0x004e7d00`.
  - MCP verified `0x004e7d13` calls UID00018B after the `this-0xa0` adjustment.
  - Event factory `0x004a9e50` provides candidate-list payload consumed by `ShowCandidateList`.
- No class-level score change is required by this report.

### File support doc

File: `by-file/IMEPanes.md`

Apply:

- Add UID0004C8 to the IMECandidatePane proposed-contents row, alongside constructor, `ShowCandidateList`, `OnPaint`, and destructor/scalar destructor rows.
- Add evidence/change note that UID0004C8 now has accepted formal C++ as `IMECandidatePane::HandleIMEMessage`.
- No file-level score change is required by this report.

### Aggregate support doc

File: `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`

Apply:

- Update UID0004C8 row/status to reflect accepted formal C++ rather than blank child body.
- Preserve existing route `[UID:00006F] -> [UID:0000K5]`.
- Add concise MCP proof: exact range `0x24`, vtable data xref `0x0061c4cc`, Event type `15`, call to UID00018B at `0x004e7d13`, and post-range padding through `0x004e7d30`.
- No aggregate score change is required by this report.

### Already sufficient support docs

No required edit recommended:

- `by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md` already records the sole caller, Event type `15`, payload offsets, and formal callee body.
- `by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md` already records the Event type `15` factory/payload semantics.
- `by-memory/0x004e8af0-0x004e970d.InputMan.md` already records the producer route.
- `by-file/Event.md` already records the Event type/payload map.
- `by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md` already records the IMECandidatePane vtable family context.

## Recommended scoped validators for implementation callback

Report-only mode did not run validators. If this report is accepted for implementation, run the scoped validator batch after the target/support doc edits:

> Executable block R001 was removed from this report and preserved verbatim in [0004C8-IMECandidatePaneHandleIMEMessage-by-memory-source-quality-removed.md](0004C8-IMECandidatePaneHandleIMEMessage-by-memory-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After validators, verify `auto-generated/NexusTK/input/IMEPanes.cpp` freshness and confirm it contains the UID0004C8 body:

```cpp
bool IMECandidatePane::HandleIMEMessage(const Event *event)
{
    if (event->m_type != kEventImeCandidateList) {
        return false;
    }

    ShowCandidateList(event);
    return true;
}
```

Expected generated disposition after implementation: UID0004C8 should no longer be absent/blank/non-emitting in generated `IMEPanes.cpp`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Evidence | Incorporation target | Callback verification |
|---|---|---|---|---|
| C001 | Current target is staged at `82/90`, owner `00006F`, reconstructable, blank emitter/body. | Target header and body reviewed. | Target metadata update. | Applied: target header now records `88/91`, keeps owner/reconstructable, sets `EMITTER_UIDS:00006F`, and contains formal C++; the prior blank state is preserved in the target Changes entry. |
| C002 | IDA MCP was available and healthy. | `idb_list` active `NexusTK.exe.i64`; `server_health status: ok`, Hex-Rays ready. | Report evidence basis. | Applied/already-present: retained in this report as evidence basis; by-* docs cite the accepted B004 MCP session/proof rather than duplicating listener health details. |
| C003 | Target range is exact `0x004e7d00-0x004e7d24`, size `0x24`. | MCP `lookup_funcs`; `0x004e7d24` not a function; next function at `0x004e7d30`. | Target evidence and aggregate row. | Applied: target Evidence and aggregate Covered Ranges / Split Source Placement rows record exact `0x24` range and next-function boundary. |
| C004 | Boundary padding supports the exact range. | MCP `get_bytes`: four `0xcc` bytes before target, twelve `0xcc` bytes after target. | Target evidence and aggregate row. | Applied: target Evidence records both padding windows; aggregate row/evidence records predecessor and successor padding through `0x004e7d30`. |
| C005 | Target is live through IMECandidatePane vtable data, not direct code callers. | MCP `xrefs_to 0x004e7d00` data xref `0x0061c4cc`; `get_int/int_convert` -> `0x004e7d00`. | Target and class evidence. | Applied: target, class, file, and aggregate evidence record vtable slot `0x0061c4cc -> 0x004e7d00`; target/class note zero direct callers as expected virtual-child reachability. |
| C006 | Target rejects non-candidate-list events. | MCP disasm/decompile compare Event `+0x04` against `0x0f`, false branch returns `0`. | Formal C++ `if` guard. | Applied: formal C++ guard inserted in target; target/class/file/aggregate text records Event `+0x04` / type `15` / false return path. |
| C007 | Target handles Event type `15` by forwarding to UID00018B. | MCP disasm call at `0x004e7d13`; `callees`; UID00018B sole caller evidence. | Formal C++ `ShowCandidateList(event); return true;`. | Applied: formal C++ inserts `ShowCandidateList(event); return true;`; target/support docs record `0x004e7d13` and UID00018B forwarding. |
| C008 | `this-0xa0` is ABI/subobject adjustment, not source spelling. | MCP decompile `this - 40`; disasm `add ecx, 0FFFFFF60h`; class/vtable context. | C++ omits explicit pointer adjustment. | Applied: target/support docs record the `this-0xa0` ABI adjustment and explain why source C++ omits it. |
| C009 | Event type `15` is IME candidate-list event. | Event factory doc; current MCP decompile/disasm of `0x004a9e50`; InputMan producer doc. | Constant name `kEventImeCandidateList`. | Applied: formal C++ uses `kEventImeCandidateList`; target/support docs record Event factory `0x004a9e50` and InputMan producer support. |
| C010 | Event payload offsets match ShowCandidateList. | Event factory `+0x08/+0x0c/+0x10c`; UID00018B consumes candidate strings and selected row. | Target evidence and support notes. | Applied: target and class evidence record Event factory payload offsets; file/aggregate point to Event factory/InputMan producer support. |
| C011 | No-code/non-emitting classification is incorrect after research. | Executable semantic body, vtable slot, root dispatch, sole callee relationship. | Set `EMITTER_UIDS: 00006F`; add C++ body. | Applied: target sets `EMITTER_UIDS:00006F`, inserts formal C++, and rejects no-code/non-emitting classification; support docs record emitting child route. |
| C012 | Canonical owner remains IMECandidatePane. | Class declaration, vtable context, callee `IMECandidatePane::ShowCandidateList`. | `CANONICAL_OWNER: 00006F`. | Applied: target keeps `CANONICAL_OWNER:00006F`; class/file/aggregate support rows preserve `[UID:00006F] -> [UID:0000K5]`. |
| C013 | File route remains IMEPanes. | Existing by-file and aggregate routing. | Support doc sync. | Applied: file Proposed Contents and Changes add UID0004C8 as an emitting IMECandidatePane child routed into IMEPanes; aggregate split/source row preserves `[UID:00006F] -> [UID:0000K5]`. |
| C014 | Recommended score is `88/91`. | Exact MCP proof plus unresolved source-name/enum spelling uncertainty. | Target metadata. | Applied: target header and Score Rationale now record `88/91` with the accepted rationale and remaining naming caveat. |
| C015 | Generated output currently lacks UID0004C8 body because target is blank. | Scoped generated-source search found no UID0004C8/body marker. | Implementation callback freshness check. | Applied/verified: after scoped validators, `auto-generated/NexusTK/input/IMEPanes.cpp` header shows `validator-command-id: 000000004132` and `validator-refreshed-at: 2026-07-01T18:08:08-04:00`; the file contains UID0004C8 and `bool IMECandidatePane::HandleIMEMessage(const Event *event)` with no UID0004C8 empty/non-emitting marker. |

## Implementation Tracking Checklist

Callback status updated by B004 on 2026-07-01.

- [x] Acquire/update leases if callback instructions require them. Proof: leased the four accepted by-* docs as B004 with `tools/leaser/leaser.py`; no lease needed for own report update.
- [x] Edit only accepted target/support docs. Proof: edited target UID0004C8, support UID00006F, support UID0000K5, support UID000189, and this report; no generated, coverage, project-level generated, validator/tool-state, queue, archive, or lock files were manually edited.
- [x] Update target metadata to `88/91`, owner `00006F`, emitter `00006F`. Proof: target header now records `COMPLETION:88`, `CONFIDENCE:91`, keeps `CANONICAL_OWNER:00006F`, keeps `RECONSTRUCTABLE:TRUE`, and sets `EMITTER_UIDS:00006F`.
- [x] Insert formal C++ in target header block. Proof: target formal block now contains exact accepted `bool IMECandidatePane::HandleIMEMessage(const Event *event)` body.
- [x] Update target evidence and rejected-alternative notes. Proof: target Status/Behavior/Evidence/Reconstruction Notes/Score Rationale/Changes record range, padding, Event guard, returns, ABI adjustment, call, vtable xref, Event factory/InputMan support, rejected alternatives, score rationale, and generated expectation.
- [x] Update `by-class/IMECandidatePane.md` support row/evidence. Proof: method row now links UID0004C8 at `88/91` with formal C++ behavior; Evidence Notes and Changes record vtable slot, Event type 15 guard, UID00018B forwarding, Event factory/InputMan support, and rejected alternatives.
- [x] Update `by-file/IMEPanes.md` proposed contents/evidence. Proof: IMECandidatePane Proposed Contents now includes UID0004C8 as exact emitting IME handler; Evidence Notes and Changes record formal handler route through UID00006F into UID0000K5.
- [x] Update `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md` aggregate row/evidence. Proof: Covered Ranges, Evidence Notes, Split Source Placement, and Changes record UID0004C8 formal C++, exact range, vtable xref, Event type 15, UID00018B callee, padding, and route `[UID:00006F] -> [UID:0000K5]`.
- [x] Run scoped validators listed above. Proof: all required validators exited `0` with `ok: 1`: target command `000000004129` at `2026-07-01T18:07:22-04:00`; class command `000000004130` at `2026-07-01T18:07:39-04:00`; file command `000000004131` at `2026-07-01T18:07:52-04:00`; aggregate command `000000004132` at `2026-07-01T18:08:08-04:00`.
- [x] Verify generated `auto-generated/NexusTK/input/IMEPanes.cpp` freshness and UID0004C8 body. Proof: generated header shows `validator-command-id: 000000004132`, `validator-refreshed-at: 2026-07-01T18:08:08-04:00`, matching the final aggregate validator; UID0004C8 body is present and no UID0004C8 empty/non-emitting marker was found.
- [x] Release leases immediately after edit/validator batch if leases were acquired. Proof: `python .\leaser.py B004 unlease` released the four accepted by-* doc leases successfully after validators and generated inspection.
- [x] Return proof, score/metadata, C++ disposition, unresolved issues, and no-unapproved-edit confirmation. Proof: satisfied by the B004 implementation callback final response after this checklist update.

## Unresolved issues

- The exact original source spelling of the Event type constant is not recovered from symbols. `kEventImeCandidateList` is recommended because the project already uses reconstructed Event enum names and type `15` is proven.
- The exact source field name for Event type at `+0x04` is reconstructed as `m_type`, consistent with accepted root IMEPane C++ and Event docs. If the project later standardizes `eventType` or `type`, this body should follow the project-wide rename.
- `EMITTER_POSITION_OPTIONAL` remains intentionally blank. The class/file ordering is clear enough without forcing a position value during this report-only pass.

## Report-only edit confirmation

This report-only pass created only:

- `tools/leaser/Agents/Agent-B004/research/0004C8-IMECandidatePaneHandleIMEMessage-by-memory-source-quality.md`

No target docs, support by-* docs, generated files, coverage reports, validator/tool state, ledgers, queues, archives, lock files, or IDA DB state were edited by this pass.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0004C8-IMECandidatePaneHandleIMEMessage-by-memory-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0004C8-IMECandidatePaneHandleIMEMessage-by-memory-source-quality.md","timestamp":"2026-07-01T18:17:41","uid":"0004C8"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0004C8-IMECandidatePaneHandleIMEMessage-by-memory-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0004C8-IMECandidatePaneHandleIMEMessage-by-memory-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0004C8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
