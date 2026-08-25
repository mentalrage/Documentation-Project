** TARGET-REPORT-UID:00027C **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00027C EventManKeyTranslationTables Ownership / Split Research

## Finalized Report / Current Recommendation
- Current recommendation: READY FOR SUPERVISOR REVIEW.
- Final disposition: keep `00027C` as one coherent reconstructable `EventMan` key-translation-table child; do not split it into separate unshifted/shifted child pages.
- Required action: no further B001 action. The shared docs now assign `00027C` directly to `by-class/EventMan.md` (`00004O`), with the class and containing file repaired above the strict `85/85` gate.
- Confidence: high for EventMan ownership, exact range boundaries, and no-split decision; medium for final source member/table names and the eventual `Event.cpp` versus `EventMan.cpp` file split.

## Supporting Research

## Target
- Target UID: `00027C`
- Target path: `by-memory/0x0066d888-0x0066da88.EventManKeyTranslationTables.md`
- Source queue/report row: supervisor-assigned B001-041 row for `00027C`.
- Current supervisor classification: ownership/parent-gate repair for an already high-scored memory child.
- Before B001-041: `00027C` was `88/92`, reconstructable, parent blank. Prior notes said it could not be assigned because the likely EventMan/Event parents were below the corrected `85/85` gate.
- After B001-041: `00027C` is `89/93`, reconstructable, assigned to `00004O` EventMan. Direct parent `EventMan` is `86/88`; containing file `Event` is `86/86`; support memory aggregate `00014C` is `86/88`.

## Executive Recommendation
- Assign `00027C` to `by-class/EventMan.md` (`00004O`).
- Keep `00027C` as a single source-bearing child. It is two adjacent `0x100` tables, but both are copied by the same `EventMan` constructor into the same keyboard translation state and consumed by the same key down/release paths.
- Do not attach the child directly to `InputMan`, `EventDispatcher`, the broad `.data` container, or neighboring memory pages.
- No exact split children were created because no owner boundary exists inside `0x0066d888-0x0066da88`.

## Supervisor Active Recheck
- The supervisor asked B001 to continue beyond the low-parent-score checkpoint and repair the actual direct parent where evidence supported it.
- B001 performed the parent-gate repair for `EventMan`, `Event`, and the `EventMan` memory support page before assigning the child.
- The assigned item did not require split repair. The split-first review found a coherent table pair with a clean predecessor boundary and a clean successor boundary.

## Inference Research Guidance Check
- `inference_research.md` was applied by treating current docs as hypotheses and ranking ownership from direct xrefs, construction sites, consumers, neighboring data, and negative evidence.
- `by-structure.md` was applied by assigning to the semantic direct parent class (`EventMan`) rather than forcing a file parent when the class is the source owner.
- IDA facts, documentation evidence, and inference are separated below. Existing docs supported the hypothesis, but the assignment was based on live IDA MCP facts plus parent-document repair.

## Evidence Standards Used
- Live IDA MCP evidence: `tools/list`, `xrefs_to`, `py_eval` byte/name checks, `lookup_funcs`, `disasm`, `decompile`, and `callers`.
- Documentation evidence: target page, manual/generated memory coverage, `EventMan` class page, `Event` file page, `EventMan` memory aggregate, neighboring memory pages, candidate `InputMan` and `EventDispatcher` docs, and proposed source-tree context.
- Negative evidence: no non-EventMan xrefs to the table starts, clean successor ownership by FolderSelect, clean predecessor/padding boundary, and no source-owner signal from candidate consumers.

## IDA MCP Facts
- Function/range facts:
  - `lookup_funcs` places `0x004a8b40`, `0x004a8cfd`, and `0x004a8d1d` inside one function `sub_4A8B40`, size `0x3d3`, documented as `EventMan::EventMan`.
  - `lookup_funcs` places `0x004a96a0` in the key down handler and `0x004a98a0` in the key release handler.
  - `callers 0x004a8b40` returns one caller at `0x0046463f` inside `sub_4639D0`, matching application initialization of the EventMan singleton.
- Data/table/padding facts:
  - `0x0066d888` is in `.data`, IDA name `unk_66D888`, first bytes `00 1b 31 32 33 34 35 36 37 38 39 30 2d 3d 08 09`.
  - `0x0066d988` is in `.data`, IDA name `unk_66D988`, first bytes `00 1b 21 40 23 24 25 5e 26 2a 28 29 5f 2b 08 09`.
  - `0x0066da80` is zero padding through the end of the target range.
  - `0x0066da88` is IDA name `asc_66DA88`, item size `0x8`, bytes `58 00 3a 00 5c 00 00 00`, the next item after `00027C`.
- Xref facts:
  - `xrefs_to 0x0066d888` returns one xref at `0x004a8cfd` inside `sub_4A8B40`.
  - `xrefs_to 0x0066d988` returns one xref at `0x004a8d1d` inside `sub_4A8B40`.
  - `xrefs_to 0x0066da88` returns FolderSelect xrefs at `0x004b183f`, `0x004b185b`, `0x004b1a8b`, and `0x004b1aaa`, confirming the successor belongs to a different owner.
- Decompiler facts:
  - `decompile 0x004a8b40` shows the constructor copying `&unk_66D888` into `this + 0x420` and `&unk_66D988` into `this + 0x520`, each with size `0x100`.
  - `decompile 0x004a96a0` and `0x004a98a0` show EventMan key down/release methods using EventMan keyboard state and fallback translation arrays when `ToAscii` does not return one byte.
- Negative IDA facts:
  - No direct xrefs from `InputMan`, `EventDispatcher`, or FolderSelect code to the two table starts were found.
  - The only xrefs to the successor item are FolderSelect xrefs, so `00027C` must stop at `0x0066da88`.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0066d888-0x0066d988` | part of `00027C` | unshifted key translation table copied by EventMan constructor | true | `00004O` EventMan | included in `89/93` | retained inside one coherent child |
| `0x0066d988-0x0066da88` | part of `00027C` | shifted/keypad key translation table copied by EventMan constructor | true | `00004O` EventMan | included in `89/93` | retained inside one coherent child |
| `0x0066d888-0x0066da88` | `00027C` target page | EventMan key translation table pair | true | `00004O` EventMan | `89/93` | assigned |
| `0x004a8b40-0x004ab476` | `00014C` | EventMan method aggregate/support page | true | `0000J6` Event | `86/88` | repaired as supporting evidence |
| by-class `EventMan` | `00004O` | direct semantic owner class | true | `0000J6` Event | `86/88` | repaired and used as direct parent |
| by-file `Event` | `0000J6` | containing source-family page | true | file root | `86/86` | repaired above file-parent gate |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0066d888` | data xref at `0x004a8cfd` in `EventMan::EventMan` | source table copied into EventMan object state |
| `0x0066d988` | data xref at `0x004a8d1d` in `EventMan::EventMan` | second source table copied into EventMan object state |
| `0x004a8b40` | caller `0x0046463f` in application initialization | EventMan object is initialized as application event producer |
| `0x004a96a0` | decompiled key down method | consumes constructor-built translation/key state |
| `0x004a98a0` | decompiled key release method | consumes constructor-built translation/key state |
| `0x0066da88` | FolderSelect xrefs only | clean successor boundary outside EventMan ownership |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion:
  - The target page already described two keyboard translation tables and a prior 2026-06-07 IDA refresh.
  - `by-class/EventMan.md` already modeled EventMan as the input event producer and now explicitly documents the key-table child.
  - `by-file/Event.md` models the event object/factory source family under `NexusTK/ui/core/Event.cpp`.
- Existing docs that were stale or incomplete:
  - The target page still had the historical "left unassigned" decision from the earlier parent-gate failure. B001 preserved it as historical context and superseded it with the 2026-06-11 assignment.
  - `EventMan`, `Event`, and `00014C` were below or barely at the strict gate and did not yet document the current table xrefs and key-method consumer evidence.
  - Manual coverage rows for memory/class/file needed to reflect the repaired parent gate and assignment.
- Generated/coverage report state:
  - Generated memory coverage now lists `00027C` as `assigned` to `00004O` with output path `auto-generated/NexusTK/ui/core/Event.cpp`.
  - Manual memory/class/file coverage rows agree with the updated scores and parent state.

## Ranked Ownership Analysis

### 1. EventMan class (`00004O`) - accepted
- Evidence for: both table starts have exactly one direct xref, both from `EventMan::EventMan`; constructor copies both with `0x100` sizes into EventMan object fields; key down/release methods consume EventMan keyboard translation state; EventMan is constructed by application initialization.
- Evidence against: final source field names are still inferred, and the project may eventually split `EventMan.cpp` from `Event.cpp`.
- Decision: accepted as the direct semantic parent. The class now clears `86/88`, so the child assignment is valid.

### 2. Event file (`0000J6`) - accepted as containing source family, not direct child parent
- Evidence for: current project structure places Event, EventMan, and event factories under `NexusTK/ui/core/Event.cpp`; EventMan is part of the event producer layer between InputMan and EventDispatcher; the file page now lists `00027C`.
- Evidence against: the exact original source split between `Event.cpp` and a possible `EventMan.cpp` remains medium confidence.
- Decision: retained as the parent of `EventMan` and `00014C`; not used as the direct parent of the data child because by-structure favors the owning class when the class ownership is clear.

### 3. EventMan memory aggregate (`00014C`) - support page, not direct semantic parent
- Evidence for: contains the constructor and key handlers that copy and consume `00027C`.
- Evidence against: it is an address-range aggregate, not the semantic class/source owner for static data.
- Decision: repaired to `86/88` as supporting evidence under `Event`, while `00004O` remains the direct parent.

### 4. InputMan (`0000K6` / `00006J`) - rejected
- Evidence for: InputMan handles Win32 keyboard/window/IMM message input before events are produced.
- Evidence against: live table-start xrefs do not point to InputMan; EventMan owns the copied arrays and key event construction; InputMan is a caller/producer neighbor, not the static table owner.
- Decision: rejected as direct parent.

### 5. EventDispatcher (`0000J7` / `00004M`) - rejected
- Evidence for: dispatched events eventually flow through the event dispatcher.
- Evidence against: no table-start xrefs; dispatcher routes already-built events and does not initialize or consume the translation tables directly.
- Decision: rejected as direct parent.

### 6. DataSection / neighboring pages - rejected
- Evidence for: the target lives in `.data` and has adjacent initialized globals.
- Evidence against: `.data` is only a storage container; predecessor and successor have distinct ownership; successor `0x0066da88` has FolderSelect xrefs.
- Decision: rejected as semantic ownership.

## Negative Evidence Summary
- No split was created because the only internal boundary is between two same-size, same-constructor, same-class translation tables.
- No xrefs from the candidate non-EventMan parents to either table start were found.
- `0x0066da88` is not EventMan data; it is a separate FolderSelect wide-character buffer with independent xrefs.
- Neighboring `.data` adjacency did not drive the decision; xrefs and constructor behavior did.

## Final Recommendation
- Applied: set `00027C` to `COMPLETION:89`, `CONFIDENCE:93`, `RECONSTRUCTABLE:TRUE`, `AUTOGEN_PARENT_UID:00004O`.
- Applied: repaired `by-class/EventMan.md` to `86/88` and documented the key-table direct parent evidence.
- Applied: repaired `by-file/Event.md` to `86/86` and documented the EventMan key-table child under `NexusTK/ui/core/Event.cpp`.
- Applied: repaired `by-memory/0x004a8b40-0x004ab476.EventMan.md` to `86/88` as the supporting constructor/key-handler aggregate.
- Applied: updated manual memory/class/file coverage reports for the new assignment and parent-gate repair.
- Items left unassigned: none in this target.
- Exact future work outside this assignment: final naming of EventMan object fields and table names, plus the possible future `Event.cpp` versus `EventMan.cpp` source split if later evidence supports it.

## Follow-Up Actions
- Supervisor actions: review and, if accepted, archive/move this report.
- A-agent actions: none required for `00027C`; future source reconstruction can refine table/member names.
- B001 future research actions: none for this target.

## Confidence
- Recommendation confidence: high. The table-start xrefs, constructor copies, consumer methods, and boundaries all point to EventMan.
- Score confidence: `00027C` at `89/93` is justified by exact size, xrefs, boundaries, and consumers; parent pages at `86/88` and `86/86` are justified for ownership but still below final-source levels because naming/source-split details remain open.
- Remaining uncertainty: exact original member names and whether original developers used one `Event.cpp` or a separate `EventMan.cpp`.

## Validator Results
- `python source-3\project-documentation\tools\validator.py --mode file --file by-memory\0x0066d888-0x0066da88.EventManKeyTranslationTables.md --apply --queue-timeout 180`
  - Result: exit 0; updated `00027C` score/parent registry to `89/93`, parent `00004O`; generated coverage refreshed.
- `python source-3\project-documentation\tools\validator.py --mode file --file by-class\EventMan.md --apply --queue-timeout 180`
  - Result: exit 0; updated `00004O` to `86/88`; inserted/validated `00027C` references. Rerun after wording cleanup also exited 0.
- `python source-3\project-documentation\tools\validator.py --mode file --file by-file\Event.md --apply --queue-timeout 180`
  - Result: exit 0; updated `0000J6` to `86/86`; inserted/validated `00027C` references and refreshed stats state.
- `python source-3\project-documentation\tools\validator.py --mode file --file by-memory\0x004a8b40-0x004ab476.EventMan.md --apply --queue-timeout 180`
  - Result: exit 0; updated `00014C` to `86/88` and validated the static-data reference.
- `python source-3\project-documentation\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 180`
  - Result: exit 0; validated manual memory coverage row and UID links.
- `python source-3\project-documentation\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --queue-timeout 180`
  - Result: exit 0; validated manual class coverage row and UID links.
- `python source-3\project-documentation\tools\validator.py --mode file --file by-file\-coverage-report.md --apply --queue-timeout 180`
  - Result: exit 0; validated manual file coverage row and UID links.
- Final target rerun after the last wording cleanup:
  - Command: `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x0066d888-0x0066da88.EventManKeyTranslationTables.md --apply --queue-timeout 180`
  - Result: exit 0; `ok: 1`, `autogen_registry_rebuild: 1`, generated coverage reports unchanged, and `project-level/-auto-completion-stats.md` projected path section refreshed by validator.
- Unresolved validator warnings/errors: none for the touched target, parent, support, or coverage files.

## Changed Files
- Created: none.
- Modified:
  - `by-memory/0x0066d888-0x0066da88.EventManKeyTranslationTables.md`
  - `by-class/EventMan.md`
  - `by-file/Event.md`
  - `by-memory/0x004a8b40-0x004ab476.EventMan.md`
  - `by-memory/-coverage-report.md`
  - `by-class/-coverage-report.md`
  - `by-file/-coverage-report.md`
  - validator-driven refresh side effects: `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-class-coverage.md`, `auto-generated/-ag-file-coverage.md`, `auto-generated/-ag-type-coverage.md`, and `project-level/-auto-completion-stats.md`.
- Renamed: none.
- Moved to executed: none.

## Lease Handling
- B001 read `Agent-B001/current_leases.md` before shared edits. Expired B001 rows were treated as stale.
- B001 leased the target and directly related shared docs/coverage rows during the applied edits, then released B001 leases after the final shared validator pass.
- Final lease check after release showed no active B001 leases. Remaining active rows, if any, belonged to other agents and were not touched.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00027C-EventManKeyTranslationTables.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"00027C"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
