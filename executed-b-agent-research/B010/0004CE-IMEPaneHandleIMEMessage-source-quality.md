** TARGET-REPORT-UID:0004CE **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B010 Research Report: UID0004CE IMEPaneHandleIMEMessage

Status: implementation callback applied; pending supervisor verification.
Target: `by-memory/0x004e81b0-0x004e8433.IMEPaneHandleIMEMessage.md`
Function: `0x004e81b0-0x004e8433`, current IDA name `sub_4E81B0`
Current score after callback: `COMPLETION:89`, `CONFIDENCE:91`

## Scope And MCP Discipline

This report uses the restored IDA MCP session `supervisor_resume_20260629`. The revision rechecked availability with `idb_list` count 1 and `server_health` OK, then rechecked the current tool schemas with `tools/list`. I used narrow, paged, schema-current calls only: targeted `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, paged `disasm`, `get_bytes`, `get_int`, and `int_convert`. The revision-specific MCP additions were targeted decompiles of `IMEPane::IMEPane` (`0x004e7f20`), `IMEPane::~IMEPane` (`0x004e8000`), and UID0004CE (`0x004e81b0`), plus schema-current `get_int`/`int_convert` for the IMEPane secondary vtable. I did not use broad list/search/disassembly/callgraph/type/batch-analysis calls.

Implementation callback note: the accepted by-* documentation edits listed in the ledger below were applied. Generated reports, project ledgers, queues, archives, manual `-coverage-report.md` files, and the IDA database were not manually edited. Validator-owned generated refreshes and validator state updates occurred only through the required scoped validator commands.

## Executive Conclusion

UID0004CE is ready for a first-draft formal C++ body as `IMEPane::HandleIMEMessage(const Event *event)`. The direct owner remains `00006H` (`IMEPane`), and the emitter route should be filled as `EMITTER_UIDS:00006H` because `IMEPane` emits through `by-file/IMEPanes.md` (`0000K5`) via the class page's `[[CHILDREN]]`.

Applied target score after incorporation: `COMPLETION:89`, `CONFIDENCE:91`.

The previous draft incorrectly described the decompiler's `this + 0x5c` and `this + 0x60` accesses as complete-object `IMEPane` offsets. The current re-audit proves UID0004CE is entered through the `IMEPane` secondary vtable at complete-object `+0xa0`. Therefore the target's adjusted-base accesses map as:

- adjusted `this + 0x5c` -> complete-object `IMEPane + 0xfc`, the already documented `activeChildPane`.
- adjusted `this + 0x60` -> complete-object `IMEPane + 0x100`, a separate root-owned candidate pane pointer that is currently missing from `IMEPane.md`.

The function behavior, event cases, child-pane ownership, virtual reachability, adjusted-this model, and range boundary are now pinned by MCP-backed evidence.

## Evidence Checked

### Function Identity And Boundary

- `lookup_funcs` on `0x004e81b0` returned `sub_4E81B0`, size `0x283`, covering `0x004e81b0-0x004e8433`.
- `lookup_funcs` on `0x004e8433` returned no function, while `0x004e8450` begins the next function `sub_4E8450`.
- Paged `disasm` showed the function returns at `0x004e8430` with `retn 4`.
- `get_bytes` at `0x004e8430` showed `c2 04 00 90`, then the switch jump table at `0x004e8434-0x004e8448`, then `0xcc` padding before `0x004e8450`.
- `get_int` and `int_convert` verified jump table destinations:
  - `0x004e8434 -> 0x004e81fc` for event type 12.
  - `0x004e8438 -> 0x004e8413` for event type 13/default false.
  - `0x004e843c -> 0x004e82ae` for event type 14.
  - `0x004e8440 -> 0x004e82c2` for event type 15.
  - `0x004e8444 -> 0x004e8402` for event type 16.

The by-memory page range is correct for the function body. The jump table immediately after the function is compiler data for this function, but the formal source body should not claim the jump table or the padding as source code.

### Reachability

- `xrefs_to 0x004e81b0` returned one data xref from `0x0061c554`.
- `get_int` at the IMEPane read-only region verified `0x0061c554` contains `0x004e81b0` (Verified with `int_convert`: decimal `5145008` -> `0x4e81b0`).
- `by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md` already documents this area as the IMEPane vtable family, including the secondary vtable slot.

There are no direct code callers. This is expected: UID0004CE is a virtual secondary-interface handler reached through the IMEPane vtable, not dead code.

### Adjusted-This Reaudit

Current MCP `decompile 0x004e7f20` for `IMEPane::IMEPane` proves three vptr stores on the complete object:

- primary vptr at complete `+0x0` -> `0x0061c4fc`.
- secondary vptr at complete `+0xa0` -> `0x0061c548`.
- tertiary vptr at complete `+0xa4` -> `0x0061c578`.

The same constructor zeroes complete-object child/root state at `+0xf8`, `+0xfc`, and `+0x100`, then initializes the focus list at `+0x104`. Current MCP `decompile 0x004e8000` for `IMEPane::~IMEPane` deletes the same three pointer fields before destroying the list:

- `this[62]` -> complete `+0xf8`.
- `this[63]` -> complete `+0xfc`.
- `this[64]` -> complete `+0x100`.

Current MCP `get_int` of the secondary vtable at `0x0061c548` verifies the slot sequence includes:

- `0x0061c550 -> 0x004e81a0` (`IMEPane::IsIMESupported`; Verified with `int_convert`).
- `0x0061c554 -> 0x004e81b0` (`IMEPane::HandleIMEMessage`; Verified with `int_convert`).

Therefore UID0004CE's decompiler variable named `this` is the secondary-subobject pointer at complete `IMEPane + 0xa0`, not the complete-object pointer. Current MCP `decompile 0x004e81b0` shows:

- event type 12/14 store/delete `this[23]`, i.e. adjusted `+0x5c`; adding the proven `+0xa0` secondary base gives complete `+0xfc`, matching current `IMEPane.md` `activeChildPane`.
- event type 15/16 store/delete `this[24]`, i.e. adjusted `+0x60`; adding the proven `+0xa0` secondary base gives complete `+0x100`, the missing root-owned candidate pane pointer before `focusPaneList +0x104`.
- candidate construction reads `g_pIMEPane + 0xfc` while seeding candidate anchors, again matching current `IMEPane.md` `activeChildPane`.

The corrected source model is `activeChildPane` plus a separate `candidatePane`, not `compositionPane +0x5c` and `candidatePane +0x60` as class-level fields. Complete `+0xf8` is a third root child pointer deleted by the destructor and likely the status pane slot, but UID0004CE does not create/delete it.

### Callees And Helper Roles

Targeted `callees` for `0x004e81b0` found:

- `0x004f4aa0` allocator.
- `0x00544460` Pane base constructor.
- `_memset`.
- `0x004b7c50` rectangle initializer.
- `0x00544c70` layer attachment helper.
- `0x00544d30` pane ordering helper.
- `0x00544690` child delete/release helper.
- `operator new`.
- `__security_check_cookie`.

Targeted `lookup_funcs` confirmed helper boundaries for the pane constructor, layer/order helpers, delete/release helper, and allocator. These match the already accepted `IMECompositionPane` and `IMECandidatePane` constructor patterns in `IMEPanes.cpp`.

## Behavior Reconstruction

The function reads the event type byte at `event + 4`, subtracts `0x0c`, and dispatches a five-entry switch for event types 12 through 16.

### Event Type 12: Composition Start

The dispatcher allocates `0x30c` bytes (verified as 780 bytes with `int_convert`) and initializes an `IMECompositionPane` object. The decompile shows the compiler inlined the child constructor sequence:

- Pane base construction.
- IMECompositionPane vtable assignment.
- `compositionCursorX = 0`.
- `memset(compositionText, 0, 0x200)`.
- `compositionDragActive = false`.
- zero rectangle initialization.
- add to `g_mainUiLayerSlots.fpsOverlayLayerContext`.
- pane ordering setup.
- store pointer through adjusted `this + 0x5c`, which maps to complete-object `IMEPane + 0xfc activeChildPane`.

Source-facing reconstruction should use `activeChildPane = new IMECompositionPane();`, relying on the existing constructor page `UID0004C1` for constructor details.

### Event Type 13: Composition Result

The jump table routes event type 13 to the default false path at `0x004e8413`. UID0004CE does not consume composition result events directly.

This is important because `InputMan`/event factory documentation names event type 13 as composition result. The result text path belongs to the composition pane flow, not this root dispatcher.

### Event Type 14: Composition End

The dispatcher deletes/releases the pointer stored at adjusted `this + 0x5c`, i.e. complete `IMEPane + 0xfc activeChildPane`, clears that field to null, and returns true.

### Event Type 15: Candidate List

The dispatcher checks adjusted `this + 0x60`, i.e. complete-object `IMEPane + 0x100`. If no candidate pane exists, it allocates `0x118` bytes (verified as 280 bytes with `int_convert`) and initializes an `IMECandidatePane`. The compiler again inlined constructor-shaped setup:

- Pane base construction.
- IMECandidatePane vtable assignment.
- candidate container fields at `+0xf8..+0x108`.
- zero rectangle initialization and add-to-layer via `g_mainUiLayerSlots.fpsOverlayLayerContext`.
- `selectedCandidateRow = -1`.
- candidate anchor seeding from `g_pIMEPane->activeChildPane` if present.
- fallback candidate anchor coordinates `4, 4` if no active child pane exists.
- store pointer at complete-object `IMEPane + 0x100`.

After ensuring the candidate pane exists, the dispatcher calls the candidate pane secondary IME handler through the subobject/vtable path and passes the original event. This corresponds source-wise to dispatching the event to `IMECandidatePane::HandleIMEMessage(event)`, whose child page already shows event type 15 forwarding to `ShowCandidateList`.

### Event Type 16: Candidate Close

The dispatcher deletes/releases the pointer stored at adjusted `this + 0x60`, i.e. complete `IMEPane + 0x100 candidatePane`, clears that field to null, and returns true.

### Default

All other event types return false.

### Status Pane Interaction

No status-pane create, delete, update, or dispatch branch appears in UID0004CE. `IMEStatusPane` remains a sibling class in the same `IMEPanes` source family, but this dispatcher only handles composition and candidate child panes for event types 12, 14, 15, and 16. The assignment's status-pane question should be closed as "not present in this function", not inferred into the target body.

## Ownership And Placement

Recommended metadata:

```text
CANONICAL_OWNER: 00006H
EMITTER_UIDS: 00006H
RECONSTRUCTABLE: TRUE
```

Source placement should be `IMEPane::HandleIMEMessage(const Event *event)` under `by-class/IMEPane.md`, emitted through `by-file/IMEPanes.md`. It should not be routed to `InputMan`, `EventMan`, `IMECandidatePane`, `IMECompositionPane`, `IMEStatusPane`, or a global page.

`InputMan` and the event factory produce the IME event stream. UID0004CE consumes that stream on the pane side.

## Required Support Changes For Incorporation

Before or during implementation callback, update the `IMEPane` class shell to expose the corrected root child-pointer model:

```cpp
Pane *statusPane;                     // +0xf8, root child pointer deleted by IMEPane::~IMEPane; not touched by UID0004CE.
Pane *activeChildPane;                // +0xfc, composition/active popup child used by UID0004CE and candidate anchoring.
IMECandidatePane *candidatePane;      // +0x100, root-owned candidate popup child.
List focusPaneList;                   // +0x104, existing field.
```

`activeChildPane +0xfc`, `focusPaneList +0x104`, and later focus fields are already documented in current `IMEPane.md`. The target-specific required addition is `candidatePane +0x100`; `statusPane +0xf8` is supported by constructor/destructor evidence and explains the adjacent child slot but is not used by UID0004CE. If the supervisor chooses not to add `statusPane` during this callback, the report should at least preserve that `+0xf8` is outside UID0004CE's behavior and must not be confused with composition handling.

The proposed body calls the candidate pane IME handler source-wise. Current `IMEPane.md` already declares `friend class IMECandidatePane;`, which lets the child class read root private fields such as `activeChildPane`, but current `IMECandidatePane.md` still lists `HandleIMEMessage` as protected and does not grant the reverse access. Implementation should make the source route compile-safe. The minimal source-facing option is to add `friend class IMEPane;` to `IMECandidatePane`, or otherwise expose the secondary event-handler interface already proven by the binary vtable call.

## Proposed First-Draft C++

`RECONSTRUCTION_CPP CODE`

```cpp
bool IMEPane::HandleIMEMessage(const Event *event)
{
    switch (event->m_type) {
    case kEventImeCompositionStart:
        activeChildPane = new IMECompositionPane();
        return true;
    case kEventImeCompositionEnd:
        delete activeChildPane;
        activeChildPane = NULL;
        return true;
    case kEventImeCandidateList:
        if (candidatePane == NULL) {
            candidatePane = new IMECandidatePane();
        }
        candidatePane->HandleIMEMessage(event);
        return true;
    case kEventImeCandidateClose:
        delete candidatePane;
        candidatePane = NULL;
        return true;
    }

    return false;
}
```

Notes for supervisor incorporation:

- The child constructor bodies are intentionally not duplicated in this root method. The target binary includes inlined constructor sequences, but source shape should use `new IMECompositionPane()` and `new IMECandidatePane()`.
- The composition start/end cases use `activeChildPane`, not a separate `compositionPane` field. The adjusted handler writes `this + 0x5c`, which maps to complete `IMEPane + 0xfc`.
- If the current Event formal model does not expose `m_type` or named IME constants yet, use the accepted Event field/constant names from the EventMan documentation during implementation. Do not replace the switch with unreviewed new enum declarations in this target page.
- The source-level `delete` statements represent the observed delete/release helper calls followed by nulling the root child pointers.

## Score Blocker Audit

### Resolved Blockers

- Blank emitter route: resolved. Route should be `00006H -> 0000K5`.
- Blank formal C++: resolved to the first-draft body above.
- Ownership ambiguity: resolved. This is an `IMEPane` root dispatcher, not an `InputMan` producer or child-pane method.
- Split/range ambiguity: resolved. Function body ends at `0x004e8433`; jump table/padding after the return should not become source body.
- Caller/reachability concern: resolved. Virtual secondary vtable slot at `0x0061c554` points to `0x004e81b0`.
- Event subtype handling: resolved for types 12-16, including type 13 returning false.
- Candidate child dispatch: resolved. Candidate-list events are forwarded to the candidate pane's secondary IME handler after lazy construction.
- Adjusted-this field model: resolved. UID0004CE's adjusted `this + 0x5c/+0x60` maps to complete `IMEPane +0xfc/+0x100` because the handler is reached through the secondary vtable at complete `+0xa0`.
- `g_pIMEPane` interaction: resolved. It is used only for candidate anchor seeding through complete-object `activeChildPane +0xfc` during candidate pane construction.

### Remaining Minor Risks

- The exact original names for `event->m_type` and the IME event constants should be aligned with the Event documentation during implementation.
- The exact source-facing name for complete `IMEPane +0x100` is inferred as `candidatePane`; the binary proves the field role but not the original spelling.
- `IMECandidatePane::HandleIMEMessage` access needs a class-shell support adjustment or an explicit interface-call source model if the implementation keeps the direct source call shown above.

These risks justify stopping at `89/91` rather than a higher score, but they do not block first-draft formal C++.

## Claim And Incorporation Ledger

| Target | Action | Proposed change | Evidence | Verification state |
|---|---|---|---|---|
| `by-memory/0x004e81b0-0x004e8433.IMEPaneHandleIMEMessage.md` | incorporate | Filled `EMITTER_UIDS:00006H`, raised to `89/91`, corrected root-dispatcher wording, removed status-child branch claims, added adjusted-this evidence, and added the accepted formal C++ body for `IMEPane::HandleIMEMessage`. | MCP `lookup_funcs`, `decompile`, paged `disasm`, `xrefs_to`, `get_bytes`, schema-current `get_int`, `int_convert`, plus constructor/destructor decompiles proving `+0xa0` secondary base and complete `+0xfc/+0x100` mapping. | applied; validator `000000003235` at `2026-07-01T04:23:51-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed` |
| `by-class/IMEPane.md` | incorporate | Preserved `activeChildPane +0xfc`; added `candidatePane +0x100`; documented adjacent `statusPane +0xf8` as constructor/destructor/status-mode evidence and not a UID0004CE branch; added UID0004CE method and evidence notes. | `IMEPane::IMEPane` stores secondary vptr at complete `+0xa0` and zeroes `+0xf8/+0xfc/+0x100`; `IMEPane::~IMEPane` deletes `+0xf8/+0xfc/+0x100`; UID0004CE adjusted `this[23]/this[24]` maps to complete `+0xfc/+0x100`. | applied; validator `000000003236` at `2026-07-01T04:25:09-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed` |
| `by-class/IMECandidatePane.md` | incorporate | Added compile-safe `friend class IMEPane;` access and evidence text for root dispatch to the protected candidate IME handler while preserving B009 UID0004C7 constructor evidence. | UID0004CE calls candidate secondary IME handler after lazy construction; the candidate class shell had protected `HandleIMEMessage`. | applied; validator `000000003237` at `2026-07-01T04:25:23-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed` |
| `by-class/IMECompositionPane.md` | already-present | No edit required for this callback; existing constructor/destructor docs already support source-level `new IMECompositionPane()` and `delete activeChildPane`. | UID0004CE inlines the composition constructor sequence, but source shape delegates that to the existing formal constructor child. | already-present; excluded from accepted edit set |
| `by-file/IMEPanes.md` | incorporate | Updated source-file contents and evidence notes to reflect IMEPane root dispatcher consuming IME event types 12, 14, 15, 16, using `activeChildPane +0xfc` and `candidatePane +0x100`, with no status-pane branch. | Target behavior plus existing `IMEPanes` file ownership. | applied; validator `000000003239` at `2026-07-01T04:25:37-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed` |
| `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md` | incorporate | Updated UID0004CE split row and evidence with `89/91`, route `00006H -> 0000K5`, formal C++ readiness, adjusted-this fields, candidate dispatch, and corrected "no status branch in UID0004CE" wording. | Aggregate already lists UID0004CE as the root dispatcher split child; current MCP proves exact switch cases. | applied; validator `000000003240` at `2026-07-01T04:25:52-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed` |
| `by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md` | already-present | No edit required; existing read-only data page already supports vtable-slot reachability. | MCP verified `0x0061c554 -> 0x004e81b0`; page already documents IMEPane vtables. | already-present |
| `by-global/g_pIMEPane.md` | already-present | No edit required; target's `g_pIMEPane->activeChildPane` use is consistent with existing global and class docs. | MCP decompile at `0x004e8396` reads `unk_69B458 + 252`, i.e. complete `g_pIMEPane +0xfc`; existing docs describe active root IME pane and active child. | already-present |
| Generated coverage/research reports | not-applicable | No manual edits; generated output was refreshed only by scoped validator runs with `--wait-generated`. | User and workflow restrictions; validator outputs report `generated_refresh: completed`. | excluded-with-reason |
| Manual `-coverage-report.md` files, queues, archives, supervisor ledgers, IDA DB | not-applicable | No edits. | User and workflow restrictions. | excluded-with-reason |

## Changed Files

Implementation callback edited these files:

- `tools/leaser/Agents/Agent-B010/research/0004CE-IMEPaneHandleIMEMessage-source-quality.md`
- `by-memory/0x004e81b0-0x004e8433.IMEPaneHandleIMEMessage.md`
- `by-class/IMEPane.md`
- `by-class/IMECandidatePane.md`
- `by-file/IMEPanes.md`
- `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`

## Implementation Tracking Checklist

- [x] Supervisor accepted report and opened an implementation callback.
- [x] Updated UID0004CE metadata with `EMITTER_UIDS:00006H`, `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:00006H`, and `RECONSTRUCTABLE:TRUE`.
- [x] Added UID0004CE formal C++ body to the target by-memory page.
- [x] Corrected UID0004CE item summary/behavior text to remove status-pane create/delete claims from this function.
- [x] Added adjusted-this evidence: secondary vptr at complete `+0xa0`, adjusted `this+0x5c -> complete +0xfc activeChildPane`, and adjusted `this+0x60 -> complete +0x100 candidatePane`.
- [x] Preserved `IMEPane::activeChildPane +0xfc`; added `IMEPane::candidatePane +0x100`; documented `statusPane +0xf8` without attributing status handling to UID0004CE.
- [x] Added compile-safe `friend class IMEPane;` to `IMECandidatePane` handler access.
- [x] Confirmed no `by-class/IMECompositionPane.md` edit was required; current constructor/destructor docs already support the UID0004CE source shape.
- [x] Updated `by-class/IMEPane.md` child coverage and method notes.
- [x] Updated `by-file/IMEPanes.md` source-family notes.
- [x] Updated `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md` split row and score.
- [x] Ran scoped validators from `source-3/project-documentation` after by-* edits:
  - [x] `python .\tools\validator.py --mode file --file by-memory/0x004e81b0-0x004e8433.IMEPaneHandleIMEMessage.md --apply --queue-timeout 240 --wait-generated` -> command `000000003235`, timestamp `2026-07-01T04:23:51-04:00`, exit `0`, `ok: 1`, generated refresh completed.
  - [x] `python .\tools\validator.py --mode file --file by-class/IMEPane.md --apply --queue-timeout 240 --wait-generated` -> command `000000003236`, timestamp `2026-07-01T04:25:09-04:00`, exit `0`, `ok: 1`, generated refresh completed.
  - [x] `python .\tools\validator.py --mode file --file by-class/IMECandidatePane.md --apply --queue-timeout 240 --wait-generated` -> command `000000003237`, timestamp `2026-07-01T04:25:23-04:00`, exit `0`, `ok: 1`, generated refresh completed.
  - [x] `python .\tools\validator.py --mode file --file by-file/IMEPanes.md --apply --queue-timeout 240 --wait-generated` -> command `000000003239`, timestamp `2026-07-01T04:25:37-04:00`, exit `0`, `ok: 1`, generated refresh completed.
  - [x] `python .\tools\validator.py --mode file --file by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md --apply --queue-timeout 240 --wait-generated` -> command `000000003240`, timestamp `2026-07-01T04:25:52-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- [x] Confirmed no generated/manual coverage, queue, archive, supervisor ledger, or IDA DB files were manually edited; validator state and generated outputs changed only via validator commands.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0004CE-IMEPaneHandleIMEMessage-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0004CE-IMEPaneHandleIMEMessage-source-quality.md","timestamp":"2026-07-01T04:29:05","uid":"0004CE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
