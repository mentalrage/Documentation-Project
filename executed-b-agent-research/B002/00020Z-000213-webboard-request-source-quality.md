** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_header_missing **
# 00020Z / 000213 WebBoard Request Helper Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: raise both targets above the source-quality gate after adding the reanalysis evidence below.
- Final disposition: both remain reconstructable WebBoard source-family code with no direct by-memory split required.
- Required action: supervisor should update the two by-memory pages and the two `by-memory/-coverage-report.md` rows using the exact text in this report.
- Confidence: high for behavior, owner/emitter route, duplicate-vs-callback/dead-artifact classification, and coverage-row change; below final-C++ confidence because original helper names and why the retained no-xref bodies survived are still inferred.

## Target

- Target UID: `00020Z`
- Target path: `by-memory/0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers.md`
- Current scores and parent state: `82/88`, `CANONICAL_OWNER:0000G2`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000G2`
- Current coverage row score: `82%`

- Target UID: `000213`
- Target path: `by-memory/0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper.md`
- Current scores and parent state: `82/88`, `CANONICAL_OWNER:0000G3`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000G3`
- Current coverage row score: `82%`

Source queue/report row: supervisor dispatch `B002-goal2-webboard-request-source-quality-00020Z-000213-20260616` in `tools/leaser/Agents/Supervisor_notes.md`.

## Executive Recommendation

Raise both targets to `85/90`:

| UID | Completion | Confidence | Canonical owner | Emitter | Final source route |
| --- | ---: | ---: | --- | --- | --- |
| `00020Z` | `85` | `90` | `0000G2` | `0000G2` | [UID:0000P9] `NexusTK/ui/dialogs/WebBoardDialog.cpp` |
| `000213` | `85` | `90` | `0000G3` | `0000G3` | [UID:0000P9] `NexusTK/ui/dialogs/WebBoardDialog.cpp` |

Do not add final `RECONSTRUCTION_CPP CODE` in this pass. The current combined-score/emitter gate is met after the recommended score raise, but the source-facing method names, input/event types, and no-xref retention cause still need source-quality stabilization before final-output code is safe.

## Supervisor Active Recheck

The supervisor assigned this as report-only B-agent heuristic/source-quality work for raw/no-function/no-xref WebBoard request helpers. This assignment does not require split repair before a final report because the current target pages already cover exact adjacent bodies and the remaining issue is source-quality classification, not an overbroad mixed-owner memory range.

Report-only scope followed: this report recommends edits but does not edit by-* docs, generated reports, source files, IDA database, or `by-memory/-coverage-report.md`.

## Inference Research Guidance Check

`by-structure.md` requires source-quality questions to be investigated before score and final-C++ decisions, not deferred merely because a target already reaches or approaches `85/85`. It also distinguishes `CANONICAL_OWNER` from `EMITTER_UIDS`; the correct direct semantic owner for both targets is class-level, while both routes surface through [UID:0000P9] `WebBoardDialog.cpp`.

`inference_research.md` supports using negative evidence, adjacency, xrefs, constructor patterns, vtable slots, raw bytes, generated-source leads, and rejected alternatives as confidence-rated inference rather than requiring impossible original-source proof. The conclusions below separate direct facts from inferred source-facing names.

## Heuristic / Inference Reanalysis And Validation

### `00020Z` Active WebBoardDialog Helper Cluster

Fact: `0x0046d4b0-0x0046d50e` is a modeled virtual input/key handler. Existing documentation places it in the active `WebBoardDialog` vtable slot `0x00613658`, adjacent to active `WebBoardDialog` slots `0x0046d3b0` at `0x00613654` and `0x0046d480` at `0x00613660`. That confirms WebBoardDialog class ownership and rejects generic `DialogPane` ownership.

Best source-facing input-handler name: `WebBoardDialog::OnKeyboardInput` or `WebBoardDialog::OnInputEvent`. The generated `simroot_v2/ui/dialogs/WebBoardDialog.cpp` lead uses `OnKeyboardInput`; this is defensible as a descriptive name but not original-proof because the inherited event type is still unnamed.

Fact: `0x0046d510-0x0046d57c` is function-shaped raw code with a normal prologue/body/epilogue, not padding. It writes opcode `0x73`, writes the caller-provided byte from `[ebp+8]`, queues length `2`, starts timer `0x572` for `0x4e20` / `20000`, and returns with `retn 4`.

Read-only PE evidence checked for liveness:

- no rel32 call, jump, or near conditional branch targets `0x0046d510`;
- no absolute VA dword or RVA dword pointer to `0x0046d510`;
- helper body is unique from the first 32 bytes onward;
- full helper body SHA1 from `0x0046d510-0x0046d57c`: `9551699bf3fc36edf83a773f1381eff8d04e3e17`;
- internal calls: `0x0046d529 -> 0x00575380`, `0x0046d535 -> 0x00575380`, `0x0046d54d -> 0x00574bb0`, `0x0046d566 -> 0x005975e0`.

Reachability inference: the active constructor contains the same startup request logic inline, with calls at `0x0046d2b7 -> 0x00575380`, `0x0046d2c1 -> 0x00575380`, `0x0046d2d8 -> 0x00574bb0`, and `0x0046d2ef -> 0x005975e0`. Therefore the current reachable startup path is accounted for without an inbound call to the raw helper.

Best source-facing request-helper name/declaration:

```cpp
void __thiscall WebBoardDialog::SendInitialBoardRequest(unsigned char boardMode);
```

Classification: retained source-shaped out-of-line helper body with no surviving inbound edge in the current binary. It is not a vtable callback, not a packet-forwarder target, not padding, and not a generic packet helper.

Rejected alternatives:

- Callback target: rejected because the adjacent packet callback is `0x0046d480`, vtable-backed at `0x00613660`, and tail-jumps to `0x0046d580`.
- Shared active/old helper: rejected because the old helper has a different signature and hard-coded zero second byte.
- Dead artifact/padding: rejected because the body is complete, unique, stack-cookie protected, and source-shaped.
- Generic network helper: rejected because only the callees are generic; opcode `0x73` and timer `0x572` are web-board protocol behavior.

### `000213` Old WebBoardDialog Request Helper

Fact: `0x0046ea30-0x0046ea99` is function-shaped raw code with no IDA function object. It writes opcode `0x73`, writes zero as the second byte, queues length `2`, starts timer `0x572` for `0x4e20` / `20000`, and returns with plain `retn`.

Read-only PE evidence checked for liveness:

- no rel32 call, jump, or near conditional branch targets `0x0046ea30`;
- no absolute VA dword or RVA dword pointer to `0x0046ea30`;
- helper body is unique from the first 32 bytes onward;
- full helper body SHA1 from `0x0046ea30-0x0046ea99`: `6dae313d5347a1666a444f45ef1690cb459464ab`;
- internal calls: `0x0046ea49 -> 0x00575380`, `0x0046ea54 -> 0x00575380`, `0x0046ea6c -> 0x00574bb0`, `0x0046ea85 -> 0x005975e0`.

Reachability inference: the old constructor contains the same no-payload startup request logic inline, with calls at `0x0046e861 -> 0x00575380`, `0x0046e86b -> 0x00575380`, `0x0046e882 -> 0x00574bb0`, and `0x0046e899 -> 0x005975e0`. Therefore the current reachable old startup path is accounted for without an inbound call to the raw helper.

Best source-facing request-helper name/declaration:

```cpp
void __thiscall WebBoardDialogOld::SendInitialBoardRequest();
```

Classification: retained source-shaped out-of-line old-dialog helper body with no surviving inbound edge. It belongs to `WebBoardDialogOld`, not RankingDialog, because the surrounding constructor, singleton, fixed `WEBBOARD.EPD` resources, packet forwarder, response handler, and vtable/RTTI context are old web-board-specific.

Rejected alternatives:

- Callback target: rejected because old packet callback is `0x0046ea00`, vtable-backed at `0x00613710`, and tail-jumps to `0x0046eaa0`.
- Shared active/old helper: rejected because active helper takes a stack byte and returns with `retn 4`; old helper has no stack argument and always sends zero.
- RankingDialog ownership: rejected as generated-output pollution; IDA/context evidence points to `WebBoardDialogOld`.
- Dead artifact/padding: rejected because the body is complete, unique, stack-cookie protected, and source-shaped.

### Protocol / Helper Names

Best descriptive packet names:

- `0x73`: initial web-board request opcode.
- `0x62`: web-board response event opcode, handled by adjacent packet forwarders.
- `0x572`: web-board request timeout timer id.
- `0x4e20` / `20000`: timeout duration.
- `0x00575380`: `PacketBufferWriteByte` / byte-plus-zero writer.
- `0x00574bb0`: `QueueAndSendPacket` / Socket queue-send wrapper.
- `0x005975e0`: timer-start wrapper.

These names are descriptive/inferred from behavior and sibling documentation, not original-proof.

### Split / Range Decision

No new split is recommended. `00020Z` is a small class helper cluster containing the modeled input handler plus adjacent raw request helper; `000213` is an exact raw helper body. Existing documented padding boundaries are sufficient:

- `0x0046d50e-0x0046d510` and `0x0046d57c-0x0046d580` are active helper padding.
- `0x0046ea23-0x0046ea30` and `0x0046ea99-0x0046eaa0` are old helper padding.

## Evidence Standards Used

Direct facts used:

- IDA-documented function bounds, vtable slots, neighbor functions, constructor/response callers, and byte behavior from existing target and neighbor pages.
- Read-only raw PE scans for rel32 target references, absolute/RVA pointers, body uniqueness, and internal call targets.
- Generated-source comparison from `source-3/simroot_v2/ui/dialogs/WebBoardDialog.cpp` as a lead, not proof.
- Current `by-memory/-coverage-report.md` rows showing the shared report still has both targets at `82%`.

Inference used:

- Source-facing helper names are inferred/descriptive from generated source and behavior.
- Retained duplicate helper classification is inferred from no inbound edge plus complete unique helper bodies plus inline duplicate constructor branches.

## IDA / PE Facts

Function/range facts:

- `0x0046d4b0-0x0046d50e`: modeled active input/key handler.
- `0x0046d510-0x0046d57c`: raw active initial-request helper body.
- `0x0046ea30-0x0046ea99`: raw old initial-request helper body.
- `0x0046d480` and `0x0046ea00`: modeled packet forwarders for response opcode `0x62`.
- `0x0046d580` and `0x0046eaa0`: active and old response handlers.

Negative reference facts:

- No direct rel32 call/jump/jcc target, absolute VA dword, or RVA dword pointer was found for `0x0046d510`.
- No direct rel32 call/jump/jcc target, absolute VA dword, or RVA dword pointer was found for `0x0046ea30`.

Constructor duplicate facts:

- Active constructor inline branch: `0x0046d2b7`, `0x0046d2c1`, `0x0046d2d8`, `0x0046d2ef`.
- Old constructor inline branch: `0x0046e861`, `0x0046e86b`, `0x0046e882`, `0x0046e899`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Recommended Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0046d4b0-0x0046d57c` | `00020Z` / `by-memory/0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers.md` | active input handler plus retained request helper | `TRUE` | `0000G2` | `85/90` | update evidence/score/coverage row |
| `0x0046ea30-0x0046ea99` | `000213` / `by-memory/0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper.md` | retained old request helper | `TRUE` | `0000G3` | `85/90` | update evidence/score/coverage row |

## Documentation Evidence And IDA Status

Supporting existing docs:

- [UID:0000G2] `by-class/WebBoardDialog.md` documents `0x0046d4b0` as the active key/input override and `0x0046d510-0x0046d57c` as the active initial board request helper.
- [UID:0000G3] `by-class/WebBoardDialogOld.md` documents `0x0046ea30-0x0046ea98` as the old initial request helper.
- [UID:0000P9] `by-file/WebBoardDialog.md` inventories both active and old web-board variants under `NexusTK/ui/dialogs/WebBoardDialog.cpp`.
- [UID:0000Z8] and [UID:0000ZC] packet-forwarder pages document the actual callback paths, which do not target the raw request helpers.
- [UID:0000Z7] and [UID:0000ZB] constructor pages document the active and old inline startup packet/timer branches.
- Packet helper docs identify `0x00575380` as a byte writer and `0x00574bb0` as the queue-send wrapper.

Stale or incomplete docs:

- The target pages still cap at `82/88` because they treat raw/no-xref helper reachability as a remaining material blocker. This report resolves that blocker to a retained duplicate-helper classification with concrete negative PE evidence and constructor duplicate evidence.
- `by-memory/-coverage-report.md` still has both rows at `82%`; exact replacements are below.

## Ranked Ownership Analysis

### 1. `WebBoardDialog` / `WebBoardDialogOld` class owners

Evidence for:

- vtable and neighbor placement for `00020Z`;
- old constructor/resource/singleton/packet-response context for `000213`;
- source file [UID:0000P9] already inventories both active and old web-board variants;
- opcode/timer behavior is feature-specific to web-board requests.

Evidence against:

- raw request helper entries have no surviving inbound references.

Decision: accepted. No-xref state affects final-C++ and exact reachability wording, not class ownership.

### 2. File-level `WebBoardDialog.cpp`

Evidence for:

- final emitted source route is [UID:0000P9] `NexusTK/ui/dialogs/WebBoardDialog.cpp`;
- both active and old class pages route through that file.

Evidence against:

- direct semantic owner is narrower than the file for both targets.

Decision: accepted as source route/emitter chain, not as `CANONICAL_OWNER`.

### 3. Rejected alternatives

- `DialogPane`: rejected; the active input handler falls back to shared input logic but is vtable-owned by WebBoardDialog.
- `Browser`: rejected; browser infrastructure is a dependency, but opcode/timer/request behavior is board-specific.
- `RankingDialog`: rejected; old generated placement is stale owner pollution.
- `PacketBuffer`/`Socket`: rejected; only generic callees live there.
- `CANONICAL_OWNER:NONE`: rejected; class ownership is supported despite no direct helper xrefs.

## Negative Evidence Summary

Checked and rejected:

- direct code references to raw helper starts;
- absolute and RVA pointer constants to raw helper starts;
- vtable/callback routing to raw helper starts;
- packet-forwarder target alternatives;
- shared helper hypothesis between active and old variants;
- padding/dead-artifact treatment.

The lack of inbound references is real and should remain documented. It does not require lowering or preserving `82/88` because the duplicate inline constructor branches explain current reachable behavior and the raw bodies remain unique source-shaped code inside the web-board class neighborhoods.

## Final Recommendation

Recommended page metadata:

```text
00020Z:
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000G2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000G2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

000213:
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000G3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000G3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended body additions:

- Add source-quality reanalysis text to both pages documenting PE negative evidence, constructor inline duplicate branches, retained-helper classification, best source-facing helper declaration, and rejected callback/shared/dead alternatives.
- Update score rationale on both pages to state that current reachability is accounted for by constructor inline duplicate branches, while final C++ remains blocked by exact source names/types and no surviving caller.
- Keep `RECONSTRUCTION_CPP CODE` blank.

## Exact `by-memory/-coverage-report.md` Replacement Rows

Supervisor should replace the current `82%` rows with these exact rows. Agents must not directly edit the coverage report.

Replacement for [UID:00020Z]:

```markdown
    - [UID:00020Z][0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers](by-memory/0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers.md) 0x0046d4b0-0x0046d57c | class method/helper cluster | WebBoardDialogInputAndRequestHelpers : reconstructable : 85% : strong : B002 source-quality reanalysis confirms exact WebBoardDialog input/request helper cluster, modeled input handler at vtable slot 0x00613658, raw retained request helper bytes 0x0046d510-0x0046d57c, opcode 0x73 two-byte send through PacketBufferWriteByte/QueueAndSendPacket, timer 0x572/0x4e20 via StartTimer(this+0xa4), no rel32 call/jump/jcc or VA/RVA pointer route to 0x0046d510 in raw PE scans, active constructor inline duplicate request branch accounts for current reachability, callback/shared/dead-artifact alternatives rejected, WebBoardDialog owner/emitter retained, and final C++ remains blank pending original helper/event names.
```

Replacement for [UID:000213]:

```markdown
    - [UID:000213][0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper](by-memory/0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper.md) 0x0046ea30-0x0046ea99 | raw class helper | WebBoardDialogOldInitialRequestHelper : reconstructable : 85% : strong : B002 source-quality reanalysis confirms exact raw old-dialog request helper bytes, opcode 0x73/zero-payload packet construction through PacketBufferWriteByte, two-byte send through QueueAndSendPacket, timer 0x572/0x4e20 via StartTimer(this+0xa4), no rel32 call/jump/jcc or VA/RVA pointer route to 0x0046ea30 in raw PE scans, old constructor inline duplicate no-payload request branch accounts for current reachability, callback/shared/RankingDialog/dead-artifact alternatives rejected, WebBoardDialogOld owner/emitter retained, and final C++ remains blank pending original helper declaration/name proof.
```

## Follow-Up Actions

Supervisor actions:

- Apply the two target page metadata/body recommendations if accepted.
- Replace the two `by-memory/-coverage-report.md` rows exactly as above.
- Run scoped validation on both target pages and `by-memory/-coverage-report.md`.
- Run the usual `memory_ranges.py report` and rescore refresh if that is part of supervisor execution flow.

A-agent actions:

- If final C++ is later attempted, first stabilize the input/event structures, member field names around timer/browser-control subobjects, and source-facing helper declarations.

B002 future research actions:

- None required for this specific assignment unless supervisor wants a final-C++ code-entry pass after the surrounding `WebBoardDialog` class/source quality improves.

## Confidence

- Recommendation confidence: strong.
- Score confidence: strong for `85/90`; not high enough for final-audit scores because original helper names and retention cause are still inferred.
- Remaining uncertainty: exact original method names, exact event/packet structure names, and whether the retained helper bodies were private methods, static helpers, or inlined/duplicated helper remnants in the original source.

## Validator Results

Commands run: none. This assignment is report-only and does not edit by-* docs or coverage reports.

Validation plan for supervisor:

> Executable block R001 was removed from this report and preserved verbatim in [00020Z-000213-webboard-request-source-quality-removed.md](00020Z-000213-webboard-request-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/00020Z-000213-webboard-request-source-quality.md`
- Modified: none outside this report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_header_missing","source_path":"executed-b-agent-research/B002/00020Z-000213-webboard-request-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
