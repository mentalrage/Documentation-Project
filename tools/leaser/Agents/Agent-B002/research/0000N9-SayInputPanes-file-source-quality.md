# UID0000N9 SayInputPanes Whole-File Source Quality Research

** TARGET-REPORT-UID:0000N9 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

## Finalized Report / Current Recommendation

- Current recommendation: retain one reconstructable `NexusTK/social/SayInputPanes.cpp` plus `SayInputPanes.h` compilation unit, raise UID0000N9 from `89/90` to `95/95`, add literal `RECONSTRUCTABLE:TRUE`, and repair the formal emit graph rather than splitting the seven related input-pane classes into generated class files.
- Final disposition: the authored unit contains 18 class-method definitions for legacy and modern direct-message panes, group and clan target-message panes, default say input, recipient-name input, and shout input. The current-mode dispatcher, six pane openers, and three recipient-history routines are ten `UserPane` member definitions in `UserPane.cpp/.h`, not SayInputPanes-owned free functions. This corrects the current documentation assumption using the exact `ECX = g_pUserPane` call convention, direct `this` field accesses, and address-family placement.
- Ordinary callback result: claims C0000N9-001 through C0000N9-051 are implemented and physically verified. C0000N9-052 through C0000N9-055 remain unchecked supervisor-owned manual coverage, and C0000N9-056 through C0000N9-098 remain unchecked supervisor-owned Gate 2B work. The handoff still contains exactly four prerequisite incomplete-type declarations, 19 pure renames, and 19 separate source-facing prototype applications; B002 performed no coverage, direct generated, IDA, audit, tracker, registry, lifecycle, or execution action.
- Current generated authority is validator command `000000028242`, refreshed `2026-08-25T16:21:25-04:00`. SayInputPanes CPP is SHA256 `1E9F0CC50AECFADEFD3138EAC0D7A3798F01543C6F9C990857428A50A6EC7E71` (17,726 bytes; 509 LF; 0 CR) and H is SHA256 `13975F5D67D3DDE1A722FEA50557BFA9472FB3081A1747D7D07703D66223363E` (2,598 bytes; 102 LF; 0 CR). UserPane CPP is SHA256 `85623B44DCE1D21E41D57C3C63E9A92D59B89DDBADDF0383A6D7D8271BDC466A` (92,561 bytes; 2,822 LF; 0 CR) and H is SHA256 `3D0891487EF3E302BF430E8178A3CD5A9A2D6610B62B1D89975F94E74FDAA5D6` (13,362 bytes; 406 LF; 0 CR). Physical reread proves the exact 18 SayInputPanes definitions, seven declarations, ten UserPane definitions/declarations, direct social includes, one mode enum, one bounded friendship, and no stale `OnSubmitChat`, `InputEvent`, `HandleHistoryNavigation`, nested qualified definition, or empty marker. Command `000000028163` and its four hashes are retained only as dated pre-callback defect evidence.
- Confidence: very strong for membership, behavior, class/header topology, protocol constants, compiler-only exclusions, `social/` placement, and source-facing call conventions/prototypes; strong for inferred original spellings of the three UserPane recipient-history methods and the default opener.

## Supporting Research

- This is the first UID0000N9 whole-file report found by searches for `UID0000N9`, `SayInputPanes`, `SayModeHelpers`, the two principal ranges, and generated source names. Earlier child reports were treated as evidence inputs and rechecked against the current canonical IDB and physical files; none substitutes for this inventory.
- Current report phase is the completed accepted ordinary implementation callback awaiting fresh Gate 2A. The current artifact path plus validator-owned lifecycle/history metadata remain authoritative for later execution/archive state. No historical Wave2/Wave3 workflow, projected simroot class-file name, or old generated command is current authority.
- The assignment requires one terminal marker. This callback-complete report follows the explicit UID0000N9 goal override and otherwise remains lifecycle-neutral.
- IDA MCP was available read-only through current canonical session `supervisor_uid0003a1_canonical_20260825_1704`. Historical and current oversized exact-name bundles timed out without changing state; bounded one/two-pair retries, all 19 function profiles/decompilations/frames, and exact type queries succeeded. No session/process management or IDA mutation occurred.
- Dated no-callback history: the wholly fresh supervisor Gate 1 review at `2026-08-25T16:29:38Z` failed exact report SHA256 `378ADC143E93F84CCD30659627B1D96E3472AC9A261295FFD48FE122C1B4A585` because the active names-registry present-row contract omitted the mandatory nested `kind:"name"` member. That review granted no Gate 1, callback, Gate 2, validation, execution, or lifecycle credit; this revision repairs only that response-schema defect and its dependent prose/twins.
- Dated no-callback history: the wholly fresh supervisor Gate 1 review at `2026-08-25T17:49:30Z` failed exact report SHA256 `0737FD3160696B40E1AFD98A6D670E0AE612168BE98074D04A8900B10D0C7D57` for omitted source-facing prototype/type closure, an overstrict persistent-rename `summary.dry_run` requirement, and invalid validator command syntax. It granted no Gate 1, callback, Gate 2, validation, execution, or lifecycle credit; this additive revision supplies the exact declaration/type actions, frames, response contracts, counts, and command wording.
- Dated no-callback history: the wholly fresh supervisor Gate 1 review at `2026-08-25T19:06:00Z` failed exact report SHA256 `B4215C0C84349FE00CEE96568F3D18AA333247B84D67DBA8D2AC7DC70D8D628C` because Section 21 embedded supervisor-owned paths, sessions, attestations, persistence, verification, and promotion procedure as a report-owned transaction program. It granted no new Gate 1, callback, Gate 2, validation, execution, or lifecycle credit; this revision removes only that operational package while preserving every accepted entity prestate, action, protection, response contract, and expected readback.

## Target

- Target UID: `UID0000N9`.
- Additional target UIDs: none. All other UIDs below are support destinations, not declared additional coverage targets.
- Target path: `by-file/SayInputPanes.md`, opening SHA256 `FB37E52891F71DD58F825EE60831563DA8B53F4DE2C31A41694469D795F4795B`, 56,325 bytes.
- Source queue/report row: `by-file/-coverage-report.md` line 238, currently `89%` and reconstructable.
- Current supervisor classification: whole-file source-quality and compilation-unit completion pass.
- Current scores and parent state after callback: `COMPLETION:95`, `CONFIDENCE:95`, `RECONSTRUCTABLE:TRUE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/social/"`, `CANONICAL_OWNER:FILE`.
- Inferred compilation-unit boundary: authored pane methods/raw constructors in `[0x005b1570,0x005b43bc)` excluding explicitly listed packet clones and ChatInputPane islands; seven class declarations in `SayInputPanes.h`; literal prompts expressed lexically in those bodies. The `[0x005a4ab0,0x005a5791)` dispatcher/opener/history family is a direct UserPane support boundary, proved by `__thiscall`, call-site ECX setup, private UserPane field access, and address-family placement.

## Current Target State

- Current target metadata is coherent: the FILE owner and `social/` route are retained, literal reconstructability is present, scores are `95/95`, and the former executable Wave3 fence survives only as inert superseded history.
- Current owner/emitter state routes all seven classes and their exact method children to UID0000N9. UID0001MB and the literal/raw evidence pages are non-emitting; UID0001MD and UID0000D5 now emit complete source; UID0000C4 has child-only CPP topology; UID0002RX plus allocated UIDs `000579` and `00057A` emit the ten UserPane member prerequisites through UID0000FQ. Allocated UID `00057B` documents the second no-route raw island without emission.
- Current formal C++ preserves every accepted body while closing the prior topology, declaration, stale-name, prerequisite, and source-order defects.
- Whole-file modeled-function inventory is exact for the two serious candidate neighborhoods: 20 functions in `[0x005a4ab0,0x005a5791)` and 44 functions in `[0x005b1500,0x005b5600)`. Of those, 18 live definitions belong to SayInputPanes, ten direct member definitions belong to UserPane, and the remainder are excluded command/emotion/ChatInputPane/GroupInputPane or adjacent UI functions. Seven raw/source-shaped starts, nine compiler wrappers, 21 class-vtable cells, nine prompt/prefix literal heads, and all known support pages also have explicit dispositions below.
- Current generated SayInputPanes CPP/H at command `000000028242` has the exact namespace-scope 18-definition body and guarded seven-class header. It has no free UserPane functions, malformed Group topology, missing class, undefined default opener, stale source-facing method/type, explicit derived destructor, or empty marker.
- Current generated UserPane CPP/H at the same command has the two direct social includes, exact mode enum, ten declarations and definitions, and one bounded `SayToUserNameInputPane` friendship. Each required member appears exactly once, including the complete zero-current-caller last-recipient opener.
- Direct prerequisites are therefore physically complete. Generated files were refreshed only by scoped validator application and were never edited directly.
- Current report artifact/lifecycle state records callback implementation and evidence without claiming Gate 2A, coverage, Gate 2B, execution, or archive completion. Those states are authoritative only from the current path and validator history.

## Executive Recommendation

- Keep `NexusTK/social/SayInputPanes.cpp/.h` as the direct file owner for the seven pane classes. `Chatting.cpp`, `Group.cpp`, and `CommandInputPanes.cpp` are callers, feature siblings, or neighbors. `UserPane.cpp/.h` is the proven direct owner of the ten dispatcher/opener/history support methods.
- Reroute UID0002RX to UID0000FQ/UserPane and create one exact source-bearing opener support page `[0x005a53c0,0x005a5791)` that emits all six UserPane opener methods, including descriptive no-current-caller `OpenSayToLastRecipientInputPane` at `0x005a54b0`. Create one exact UserPane support page `[0x005a4ab0,0x005a4c8b)` for the three recipient-history methods.
- Convert UID0001MB to a reconstructable-false, non-emitting method-cluster index because all SayInputPane bodies already have exact children. Keep UID0001MD source-bearing, add constructor/submit around `[[CHILDREN]]`, and repair UID0001ME to the real inherited Event signature. Convert four literal-pool pages to reconstructable-false/non-emitting source evidence because their text is lexically present in authored functions and should not emit standalone definitions.
- Add one non-emitting page for raw `[0x005b3bc0,0x005b3ca5)` so the second no-route chat packet island is no longer an undocumented gap. Keep UID0002S8 non-emitting and historicalize its stale liveness uncertainty.
- Command `000000028242` produced the required guarded SayInputPanes header, all seven class declarations, namespace-scope 18-definition CPP, and exact UserPane enum/ten-member closure. The physical readback in Sections 31-32 proves no empty marker, free UserPane definition, or nested qualified definition remains.

## Supervisor Active Recheck

- The current instruction is the accepted UID0000N9 ordinary implementation callback. No split-first master report or competing UID0000N9 report was found.
- Every discoverable source-bearing item now has an exact owning page, formal CPP/H disposition, and ledger/checklist row. Validator allocation assigned UIDs `000579`, `00057A`, and `00057B` to the three fixed new pages; no research deferral remains.
- All raw starts and adjacent candidate functions were checked for modeled-function state, caller/xref routes, packet/string behavior, and sibling source family. No item remains at generic `needs investigation` status.
- The repaired supervisor handoff is equally explicit: four currently missing pane types receive incomplete declarations only, each of the 19 functions retains an independent pure rename, and each receives a separate parser-safe source-facing `set_type` action with literal prestate, complete frame delta/protection, exact public response allowlist, and immediate/final readback.
- The handoff stops at those entity contracts. Runtime identity, storage, process/session handling, cross-entity ordering, persistence verification, promotion/rollback, audit, and lifecycle mechanics remain independently supervisor-owned and are not constructed by this report.

## Inference Research Guidance Check

- Current `by-structure.md` rules favor semantic source ownership and exact children over address adjacency. They support one social pane module for the seven pane classes, UserPane-owned dispatcher/opener/history methods, non-emitting mixed indexes, and compiler-covered wrapper/vtable exclusions.
- Existing assumptions treated as uncertain and rechecked were: separate class CPPs, `SayToPlan` versus `SayToClan`, `InputEvent`, `OnRecipientNameConfirmed`, `HandleHistoryNavigation`, `OnSubmitChat`, source-emitted prompt islands, the liveness of raw packet clones, and broad UID0001KO ownership.
- Direct IDA facts are addresses, bounds, bytes, callers/callees, vtable cells, field offsets, string values, packet constants, and current names/types/comments. Documentation evidence is current metadata/formal source and earlier child research. Source-facing names, original file grouping, and omission of explicit derived destructors are supported inference.
- Wave2/Wave3 artifacts occur only in target migration/history prose. They were rejected as stale and are not used as authority.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis | Resolution |
| --- | --- | --- |
| Whole-file boundary | Reconciled 64 modeled functions across two candidate neighborhoods, raw gaps, callers, vtables, strings, current class/file docs, and generated output. | 18 live SayInputPanes definitions; ten UserPane member prerequisites; all others explicitly excluded. |
| Dispatcher/opener ownership | Call sites load `ECX = g_pUserPane`; dispatcher/default/shout use `this`; all seven sit in the UserPane method family and access private UserPane state. | UserPane member methods in UserPane.cpp/H, not free SayInputPanes functions. |
| Default opener name | `0x005a53c0` has dispatcher/UserPane callers, writes mode 0, allocates a `0x10c` SayInputPane, and installs Say vtables. | Inferred source name `UserPane::OpenDefaultSayInputPane()`; reject undefined `OpenDefaultSayPane`. |
| Recipient-history helper names | Exact list offsets, previous-index behavior, dedupe/cap-ten insertion, selector write, and Name callers identify the three roles. | `UserPane::GetPreviousRecentRecipientHistory`, `UpdateRecentRecipientList`, and `GetPreviousFallbackRecipientHistory`; names are descriptive/high-confidence inference. |
| `0x005a54b0` | Complete `__thiscall` modern-recipient opener shape, zero current callers, outgoing-list access, recent update, and UID000403 construction. | Emit descriptive private `UserPane::OpenSayToLastRecipientInputPane()`; zero current route is documented but does not erase a modeled authored body. |
| Plan versus Clan | Mode 4 copies `L"!"`, constructors use `L"Clan => "`, and all live source paths describe clan chat. | Source class is `SayToClanMessageInputPane`; stable UID0000C5 path/title may retain historical Plan label. |
| Name-pane event method | IDA type is `Event *`; secondary-vtable call uses primary complete offsets `+0x108/+0x10a`; unhandled events call `LineInputPane::HandleKeyOrTextEvent`. | Replace `InputEvent`/`HandleHistoryNavigation` with `HandleKeyOrTextEvent(Event *)`. |
| Name-pane submit method | Primary submit slot `+0x48` reaches `0x005b4080`; it saves a nonempty recipient then constructs modern or legacy direct-message pane. | Replace `OnRecipientNameConfirmed` with `OnSubmitInput`. |
| Say submit method | Primary `+0x48` and base API identify the virtual, while `OnSubmitChat` exists only in current documentation. | Rename formal source and IDA recommendation to `SayInputPane::OnSubmitInput`. |
| Explicit destructors | Nine shared adjustor/scalar-wrapper addresses service seven pane classes; no unique authored derived destructor body is present. | Omit explicit derived destructor declarations/definitions; retain wrappers as compiler-only evidence. |
| Prompt data pages | Nine exact wide-string heads are referenced by constructors/openers, but no independent source storage identity or standalone data definition is required. | Preserve literal values in authored source; set the four existing target-owned prompt pages non-emitting/reconstructable false. |
| Raw packet helpers | `[0x5b1820,0x5b1983)`, `[0x5b1d50,0x5b1eb3)`, `[0x5b2160,0x5b22c3)`, `[0x5b37f0,0x5b38d5)`, and `[0x5b3bc0,0x5b3ca5)` have source-shaped packet bodies but no proven call/pointer/vtable route. | Keep all non-emitting. Create documentation only for the unpaged `0x5b3bc0` island. |
| Header/source topology | Physical generated output proves missing declarations, duplicate/nested definitions, wrong free-function ownership, and absent direct prerequisites. | SayInputPanes H owns only class declarations; UserPane H owns mode/method declarations; definitions remain class/member definitions; Say class positions are 10-70. |
| Score blocker | Prior 89/90 cap cited historical split uncertainty and child blockers. Current evidence closes membership, source placement, method names, headers, and raw exclusions. | Raise to 95/95; retain a five-point cap for inferred original spellings and lack of original source/PDB. |

Rejected alternatives: separate `class_*.cpp` outputs reproduce current malformed topology; `Group.cpp`/`Chatting.cpp` ownership confuses feature callers with class implementation; broad UID0001KO emission would absorb unrelated Icons/status/UI functions; standalone string definitions create synthetic source; treating raw packet clones as live would duplicate inline serialization without a route.

## Evidence Standards Used

- Highest weight: current canonical IDA MCP modeled functions, decompilation, exact bytes, callers/callees, vtable references, item/string reads, exact-name registry checks, and negative xref/function evidence.
- Next: current formal by-file/by-class/by-memory channels and current physical generated CPP/H. Historical child reports and old generated hashes were corroboration only.
- Inference was accepted only when multiple independent facts converge and the source-facing choice preserves observed behavior. Original spelling is not claimed where no PDB/source symbol survives.
- Negative evidence is bounded: zero xrefs or a raw no-function start does not prove dead source alone, but combined with duplicate inline live bodies, no pointer route, no vtable slot, and adjacent padding it supports non-emission.

## Evidence Checked

- IDA MCP: current canonical session `supervisor_uid0003a1_canonical_20260825_1704`; health `status:ok`, canonical path, imagebase `0x00400000`, Hex-Rays ready, analysis not running; bounded function profiles, direct decompilation, persisted item types, and complete stack frames for all 19 actions; exact comments/bytes/vtable/xref/callee evidence; current type catalog/type inspection for `UserPane`, `Event`, `LineInputPane`, `SayInputPane`, four missing pane types, `size_t`, and `wchar_t`; and exact old/desired name-registry checks.
- Physical canonical receipt: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, 143,211,870 bytes, SHA256 `2C9A806456DCCDAFC3A96BC9E02217407090BE552B5354113366AC67BD58ECBB`, last write UTC `2026-08-25T17:01:37.7388127Z`.
- Documentation: target, all seven class pages, UID0001KO/0002RX/0001LY/000401-000406, UID0001MB/0002S7/000414-000416, UID0001MD/0001ME, UID0002SA/0001MF, prompt pages, UserPane class/packet support, List API, Chatting/Group/CommandInputPanes boundaries, manual coverage, generated tracker metadata, and matching B-report searches.
- Physical generated files: command `000000028242` SayInputPanes/UserPane CPP/H bodies were read, hashed, and compared item-by-item after the final foreground validator. Commands `000000028163` and `000000028114` are superseded historical evidence only.
- Negative checks: all adjacent modeled functions listed below; raw helper function/xref state; `InputEvent` absence; four exact missing pane-type catalog entries; zero desired-name registry collisions; and no prior UID0000N9 matching report before this assignment.
- Failed checks: the earlier 26-subquery bundle and current 20-/8-subquery exact-name bundles timed out read-only. Current one-/two-pair calls then succeeded for all 19 old/desired pairs, proving a query-size limitation rather than missing evidence. Every displayed autogenerated `sub_*` spelling has exact registry total zero; the five descriptive old names alone have exact total one.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C0000N9-001 | UID0000N9 | Retain `NexusTK/social/SayInputPanes.cpp/.h`, add `RECONSTRUCTABLE:TRUE`, and keep owner FILE. | very strong | complete source-family inventory | `by-file/SayInputPanes.md` metadata/Status | B002 callback incorporate | implemented-verified |
| C0000N9-002 | UID0000N9 | Replace sampled contents with the exhaustive included/excluded inventory in this report. | very strong | 20+44 modeled function sweep plus raw/data/type inventory | target Proposed Contents/Boundary Notes | B002 callback incorporate | implemented-verified |
| C0000N9-003 | UID0000N9 | Record current command-28242 SayInputPanes/UserPane CPP/H hashes and exact clean generated acceptance state. | certain | physical generated reread | target Current Generated State | B002 callback incorporate | implemented-verified |
| C0000N9-004 | UID0000N9 | Centralize guard/include and seven class declarations in SayInputPanes H; remove free opener/enum ownership. | very strong | calling convention, direct prerequisites, malformed current H | target Shared Header Contract | B002 callback incorporate | implemented-verified |
| C0000N9-005 | UID0000N9 | Emit includes, 18 class-method definitions, and no standalone literal data at namespace scope in CPP. | very strong | function/source inventory | target Source Topology | B002 callback incorporate | implemented-verified |
| C0000N9-006 | UID0000N9 | Apply emitter positions 10/20/30/40/50/60/70 to 099/C6/C4/C5/C3/C7/D5. | strong | deterministic class/header order | target Source Order | B002 callback incorporate | implemented-verified |
| C0000N9-007 | UID0000N9 | Remove the executable Wave3 fence and preserve its content only as rejected historical migration prose. | certain | target lines 129-142 and active workflow ban | target Migration Notes | B002 callback incorporate | implemented-verified |
| C0000N9-008 | UID0001KO | Keep mixed helper range owner NONE, reconstructable false, blank emitter/formal source; update exact 20-function inventory. | very strong | complete range query | `by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md` | B002 callback incorporate | implemented-verified |
| C0000N9-009 | UID0002RX | Reroute dispatcher owner/emitter to UID0000FQ, emit `UserPane::OpenInputPaneForCurrentSayMode` in UserPane CPP, and keep formal H blank. | very strong | `__thiscall`, ECX caller setup, private field access | exact dispatcher page | B002 callback incorporate | implemented-verified |
| C0000N9-010 | UID000579 | Create exact `[0x005a53c0,0x005a5791)` opener support page; emit six UserPane member openers including last-recipient method; owner/emitter UID0000FQ. | very strong | member calling convention/profiles/callers/allocations | `by-memory/0x005a53c0-0x005a5791.UserPaneSayInputPaneOpeners.md` | B002 callback create/incorporate | implemented-verified |
| C0000N9-011 | UID00057A | Create exact `[0x005a4ab0,0x005a4c8b)` UserPane history-helper page with three definitions; owner/emitter UID0000FQ. | very strong | exact list fields and decompilation | `by-memory/0x005a4ab0-0x005a4c8b.UserPaneWhisperRecipientHistoryHelpers.md` | B002 callback create/incorporate | implemented-verified |
| C0000N9-012 | UID0000FQ | Add enum, ten dispatcher/opener/history declarations, direct social CPP includes, and bounded SayToUserNameInputPane friendship with exact ownership/history notes. | very strong | member calling convention, ranges, private class fields, and Name direct accesses | `by-class/UserPane.md` formal CPP/H/Direct-Message History | B002 callback incorporate | implemented-verified |
| C0000N9-013 | UID0000C6 | Preserve legacy direct-message class declaration/children topology; position 20; no explicit destructor. | very strong | current formal H and vtable wrappers | `by-class/SayToUserMessageInputPane.md` | B002 callback incorporate | implemented-verified |
| C0000N9-014 | UID000401 | Preserve current constructor/submit CPP unchanged and blank H. | very strong | current formal source/current IDA names | exact legacy method page | B002 callback verify-no-change | implemented-verified |
| C0000N9-015 | UID000402 | Preserve raw helper A ownerless, reconstructable false, non-emitting. | very strong | no function/xref/pointer route | exact no-route page | B002 callback verify-no-change | implemented-verified |
| C0000N9-016 | UID000099 | Keep central CPP/H preambles on this earliest Say emitter, keep `[[CHILDREN]]`, preserve complete H declaration, and set position 10. | very strong | generated nested topology and corrected UID2RX route | `by-class/NewSayToUserMessageInputPane.md` | B002 callback incorporate | implemented-verified |
| C0000N9-017 | UID000403 | Preserve current three modern method definitions and blank H. | very strong | accepted formal source/live methods | exact modern method page | B002 callback verify-no-change | implemented-verified |
| C0000N9-018 | UID000404 | Preserve raw helper B ownerless, reconstructable false, non-emitting. | very strong | no function/xref/call route | exact no-route page | B002 callback verify-no-change | implemented-verified |
| C0000N9-019 | UID0000C4 | Move Group declaration to H, set CPP to `[[CHILDREN]]`, omit destructor, position 30, score 93/94. | very strong | current malformed nested emission and wrapper proof | `by-class/SayToGroupMessageInputPane.md` | B002 callback incorporate | implemented-verified |
| C0000N9-020 | UID0001LZ | Preserve Group constructor/submit CPP, blank H, owner/emitter C4; update source/topology notes to shared unit. | very strong | live methods and formal source | exact Group method page | B002 callback incorporate | implemented-verified |
| C0000N9-021 | UID000405 | Preserve raw helper C ownerless, reconstructable false, non-emitting. | very strong | no function/xref/call route | exact no-route page | B002 callback verify-no-change | implemented-verified |
| C0000N9-022 | UID0000C5 | Preserve source-facing Clan declaration/children route, stable Plan filename as history only, position 40. | very strong | mode/literal/method evidence | `by-class/SayToPlanMessageInputPane.md` | B002 callback incorporate | implemented-verified |
| C0000N9-023 | UID000406 | Preserve current Clan constructor/submit CPP and blank H. | very strong | accepted formal source/live methods | exact Clan method page | B002 callback verify-no-change | implemented-verified |
| C0000N9-024 | UID0000C3 | Change H virtual to `OnSubmitInput`, omit explicit destructor, preserve CPP children, position 50. | very strong | base submit slot/API and compiler wrapper | `by-class/SayInputPane.md` | B002 callback incorporate | implemented-verified |
| C0000N9-025 | UID0002S7 | Preserve exact default Say constructor CPP and blank H. | very strong | raw body/vtables/inline equivalents | exact raw constructor page | B002 callback verify-no-change | implemented-verified |
| C0000N9-026 | UID000414 | Preserve initial-text constructor CPP and blank H. | very strong | live method/formal source | exact constructor child | B002 callback verify-no-change | implemented-verified |
| C0000N9-027 | UID000415 | Preserve Event-based history handler CPP and blank H. | very strong | live type/vtable/formal source | exact event child | B002 callback verify-no-change | implemented-verified |
| C0000N9-028 | UID000416 | Rename only formal `OnSubmitChat` to `OnSubmitInput`; preserve body/protocol; blank H. | very strong | primary submit slot/base API | exact submit child | B002 callback incorporate | implemented-verified |
| C0000N9-029 | UID0001MB | Make aggregate reconstructable false with blank emitter/formal source; retain exact-child index and evidence. | very strong | all four method bodies have exact children | Say aggregate page metadata/summary | B002 callback incorporate | implemented-verified |
| C0000N9-030 | UID0000C7 | Replace stale InputEvent/method/destructor H with Event-based constructor/submit/event declaration; position 60. | very strong | live types/vtable slots | `by-class/SayToUserNameInputPane.md` | B002 callback incorporate | implemented-verified |
| C0000N9-031 | UID0001MD | Emit exact Name constructor and submit around `[[CHILDREN]]`; preserve owner/emitter C7 and refresh summary. | very strong | complete class cluster decompilation | Name aggregate formal CPP | B002 callback incorporate | implemented-verified |
| C0000N9-032 | UID0001ME | Replace stale InputEvent/history CPP with exact `HandleKeyOrTextEvent(Event *)`; blank H. | very strong | live decompile/type/offset correction | exact Name event child | B002 callback incorporate | implemented-verified |
| C0000N9-033 | UID0000D5 | Add `[[CHILDREN]]` CPP and complete Shout H declaration without destructor; position 70; score 93/94. | very strong | raw constructor and submit child | `by-class/ShoutInputPane.md` | B002 callback incorporate | implemented-verified |
| C0000N9-034 | UID0002SA | Preserve exact raw Shout constructor CPP and blank H. | very strong | raw bytes/vtables/prompt | exact raw constructor page | B002 callback verify-no-change | implemented-verified |
| C0000N9-035 | UID0001MF | Preserve exact Shout submit CPP and blank H. | very strong | live submit/vtable/protocol | exact submit page | B002 callback verify-no-change | implemented-verified |
| C0000N9-036 | UID0003JM | Set group/clan prefix fragment page reconstructable false, emitter blank, CPP/H blank; preserve literal/xrefs. | very strong | lexical use/no independent storage need | exact string page | B002 callback incorporate | implemented-verified |
| C0000N9-037 | UID0003JQ | Set direct-whisper fragment page reconstructable false, emitter blank, CPP/H blank; preserve literal/xrefs. | very strong | lexical use/no independent storage need | exact string page | B002 callback incorporate | implemented-verified |
| C0000N9-038 | UID0003JR | Set group/clan prompt page reconstructable false, emitter blank, CPP/H blank; preserve literal/xrefs. | very strong | lexical use/no independent storage need | exact string page | B002 callback incorporate | implemented-verified |
| C0000N9-039 | UID0003JS | Set Shout prompt page reconstructable false, emitter blank, CPP/H blank; preserve literal/xrefs. | very strong | lexical use/no independent storage need | exact string page | B002 callback incorporate | implemented-verified |
| C0000N9-040 | UID0002S8 | Preserve raw chat sender owner NONE/reconstructable false/non-emitting and replace stale liveness wording. | very strong | repeated no-route checks and inline live bodies | exact raw sender page | B002 callback incorporate | implemented-verified |
| C0000N9-041 | UID00057B | Create non-emitting page for `[0x005b3bc0,0x005b3ca5)` opcode-0x0e/subtype-0 packet island; owner NONE. | strong | raw body, zero xrefs, padding | `by-memory/0x005b3bc0-0x005b3ca5.ChatPacketRawSenderNoRouteRawB.md` | B002 callback create/incorporate | implemented-verified |
| C0000N9-042 | support set | Preserve nine exact destructor adjustor/scalar wrappers as compiler-only with no formal source. | very strong | shared vtable wrapper topology | target/support compiler inventory | B002 callback incorporate | implemented-verified |
| C0000N9-043 | support set | Preserve seven three-view vtable groups and RTTI as compiler output, not source emitters. | certain | exact table pointers/vptr stores | target/support data inventory | B002 callback incorporate | implemented-verified |
| C0000N9-044 | UID0000I5/UID0000JS/CommandInputPanes | Preserve ChatInputPane, command/emotion panes, and GroupInputPane exclusions. | very strong | modeled ranges and semantic owners | target Rejected Candidates/cross-links | B002 callback incorporate | implemented-verified |
| C0000N9-045 | UID0000N9 | Reconcile all support links, direct prerequisites, literal pools, wrappers, gaps, and rejected candidates in target history. | very strong | exhaustive destination sweep | target Cross-References/Changes | B002 callback incorporate | implemented-verified |
| C0000N9-046 | UID0000N9 | Raise file score 89/90 to 95/95 after formal/source/inventory closure. | strong | blocker audit in Section 26 | target metadata/Score Rationale | B002 callback incorporate | implemented-verified |
| C0000N9-047 | UID0000C4 | Raise Group class 88/91 to 93/94 after H/CPP topology repair. | strong | complete method/header evidence | Group class metadata/Score | B002 callback incorporate | implemented-verified |
| C0000N9-048 | UID0000C7/UID0001MD/UID0001ME | Raise Name class/aggregate/event to 94/95, 93/94, 94/95 after exact source closure. | strong | all live methods/types/routes resolved | three Name pages metadata/Score | B002 callback incorporate | implemented-verified |
| C0000N9-049 | UID0000D5 | Raise Shout class 85/86 to 93/94 after complete H/CPP route. | strong | exact constructor/submit/wrappers | Shout class metadata/Score | B002 callback incorporate | implemented-verified |
| C0000N9-050 | changed ordinary docs | From project root run exact scoped `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240` per changed destination; add `--wait-generated` to the final relevant validation. | certain | current validator syntax/workflow | every changed by-* destination | B002 callback validate | implemented-verified |
| C0000N9-051 | UID0000N9/UID0000P1 | Physically verify refreshed SayInputPanes 18-definition CPP/H and UserPane ten-method CPP/H deltas against exact acceptance inventories and record receipts. | certain | current physical generated acceptance inventory | report Validator Results/Changed Files | B002 callback verify | implemented-verified |
| C0000N9-052 | UID0000N9 | Replace manual by-file coverage row with exact 95% whole-file closure text. | certain | current row line 238 | `by-file/-coverage-report.md` line 238 | supervisor coverage | proposed-unapplied |
| C0000N9-053 | UID0000C4 | Replace manual class coverage row with exact 93% Group topology text. | certain | current row line 463 | `by-class/-coverage-report.md` line 463 | supervisor coverage | proposed-unapplied |
| C0000N9-054 | UID0000C7 | Replace manual class coverage row with exact 94% Name source text. | certain | current row line 466 | `by-class/-coverage-report.md` line 466 | supervisor coverage | proposed-unapplied |
| C0000N9-055 | UID0000D5 | Replace manual class coverage row with exact 93% Shout source text. | certain | current row line 499 | `by-class/-coverage-report.md` line 499 | supervisor coverage | proposed-unapplied |
| C0000N9-056 | UID0000FQ | Rename `sub_5A4AB0` to `UserPane__GetPreviousRecentRecipientHistory` under A01 and exact Section 21 zero/present registry-payload contracts. | strong | exact list/decompile/callers | IDA `0x005a4ab0` | supervisor Gate2B | proposed-unapplied |
| C0000N9-057 | UID0000FQ | Rename `sub_5A4B60` to `UserPane__UpdateRecentRecipientList` under A02 and exact Section 21 zero/present registry-payload contracts. | strong | dedupe/cap/select behavior | IDA `0x005a4b60` | supervisor Gate2B | proposed-unapplied |
| C0000N9-058 | UID0000FQ | Rename `sub_5A4C30` to `UserPane__GetPreviousFallbackRecipientHistory` under A03 and exact Section 21 zero/present registry-payload contracts. | strong | exact list/decompile/callers | IDA `0x005a4c30` | supervisor Gate2B | proposed-unapplied |
| C0000N9-059 | UID0000FQ | Rename `OpenInputPaneForCurrentSayMode` to `UserPane__OpenInputPaneForCurrentSayMode` under A04 and exact Section 21 zero/present registry-payload contracts. | very strong | ECX caller setup/private field use | IDA `0x005a5110` | supervisor Gate2B | proposed-unapplied |
| C0000N9-060 | UID0000FQ | Rename `sub_5A53C0` to `UserPane__OpenDefaultSayInputPane` under A05 and exact Section 21 zero/present registry-payload contracts. | very strong | allocation/mode/callers | IDA `0x005a53c0` | supervisor Gate2B | proposed-unapplied |
| C0000N9-061 | UID0000FQ | Rename `OpenSayToUserNameInputPane` to `UserPane__OpenSayToUserNameInputPane` under A06 and exact Section 21 zero/present registry-payload contracts. | very strong | ECX caller setup/allocation | IDA `0x005a5450` | supervisor Gate2B | proposed-unapplied |
| C0000N9-062 | UID0000FQ | Rename displayed `sub_5A54B0` to `UserPane__OpenSayToLastRecipientInputPane` under A07 and exact Section 21 zero/present registry-payload contracts. | strong | member fields/behavior and zero-current-caller evidence | IDA `0x005a54b0` | supervisor Gate2B | proposed-unapplied |
| C0000N9-063 | UID0000FQ | Rename `OpenSayToGroupMessageInputPane` to `UserPane__OpenSayToGroupMessageInputPane` under A08 and exact Section 21 zero/present registry-payload contracts. | very strong | ECX caller setup/group construction | IDA `0x005a5570` | supervisor Gate2B | proposed-unapplied |
| C0000N9-064 | UID0000FQ | Rename `OpenSayToClanMessageInputPane` to `UserPane__OpenSayToClanMessageInputPane` under A09 and exact Section 21 zero/present registry-payload contracts. | very strong | ECX caller setup/clan construction | IDA `0x005a5640` | supervisor Gate2B | proposed-unapplied |
| C0000N9-065 | UID0000FQ | Rename `OpenShoutInputPane` to `UserPane__OpenShoutInputPane` under A10 and exact Section 21 zero/present registry-payload contracts. | very strong | explicit `__thiscall`, mode write, callers | IDA `0x005a5710` | supervisor Gate2B | proposed-unapplied |
| C0000N9-066 | UID0000C4 | Rename `sub_5B1EC0` to `SayToGroupMessageInputPane__Constructor` under A11 and exact Section 21 zero/present registry-payload contracts. | very strong | ctor/vtable/prompt | IDA `0x005b1ec0` | supervisor Gate2B | proposed-unapplied |
| C0000N9-067 | UID0000C4 | Rename `sub_5B1F80` to `SayToGroupMessageInputPane__OnSubmitInput` under A12 and exact Section 21 zero/present registry-payload contracts. | very strong | submit vtable/protocol | IDA `0x005b1f80` | supervisor Gate2B | proposed-unapplied |
| C0000N9-068 | UID0000C5 | Rename `sub_5B22D0` to `SayToClanMessageInputPane__Constructor` under A13 and exact Section 21 zero/present registry-payload contracts. | very strong | ctor/vtable/prompt | IDA `0x005b22d0` | supervisor Gate2B | proposed-unapplied |
| C0000N9-069 | UID0000C5 | Rename `sub_5B2390` to `SayToClanMessageInputPane__OnSubmitInput` under A14 and exact Section 21 zero/present registry-payload contracts. | very strong | submit vtable/protocol | IDA `0x005b2390` | supervisor Gate2B | proposed-unapplied |
| C0000N9-070 | UID0000C3 | Rename `sub_5B3670` to `SayInputPane__OnSubmitInput` under A15 and exact Section 21 zero/present registry-payload contracts. | very strong | base submit slot/protocol | IDA `0x005b3670` | supervisor Gate2B | proposed-unapplied |
| C0000N9-071 | UID0000C7 | Rename `sub_5B3CB0` to `SayToUserNameInputPane__Constructor` under A16 and exact Section 21 zero/present registry-payload contracts. | very strong | ctor/vtables/callers | IDA `0x005b3cb0` | supervisor Gate2B | proposed-unapplied |
| C0000N9-072 | UID0000C7 | Rename `sub_5B3E80` to `SayToUserNameInputPane__HandleKeyOrTextEvent` under A17 and exact Section 21 zero/present registry-payload contracts. | very strong | Event type/secondary vtable | IDA `0x005b3e80` | supervisor Gate2B | proposed-unapplied |
| C0000N9-073 | UID0000C7 | Rename `sub_5B4080` to `SayToUserNameInputPane__OnSubmitInput` under A18 and exact Section 21 zero/present registry-payload contracts. | very strong | primary submit vtable/behavior | IDA `0x005b4080` | supervisor Gate2B | proposed-unapplied |
| C0000N9-074 | UID0000D5 | Rename `sub_5B4260` to `ShoutInputPane__OnSubmitInput` under A19 and exact Section 21 zero/present registry-payload contracts. | very strong | submit vtable/protocol | IDA `0x005b4260` | supervisor Gate2B | proposed-unapplied |
| C0000N9-075 | UID0000N9/UID0000FQ | Independently establish all supervisor-owned Gate 2B runtime, persistence, process, audit, and lifecycle prerequisites outside this report; any missing or mismatched external prerequisite fails Gate 2B without weakening the 42 entity contracts. | certain | Section 21 role boundary and entity manifests | supervisor Gate2B external controls | supervisor Gate2B | proposed-unapplied |
| C0000N9-076 | UID0000C4 | Declare only incomplete `struct SayToGroupMessageInputPane;` under TD01 and preserve every existing prerequisite type/function state. | certain | current type catalog plus formal Group class | IDA local type library / Section 21 TD01 | supervisor Gate2B | proposed-unapplied |
| C0000N9-077 | UID0000C5 | Declare only incomplete `struct SayToClanMessageInputPane;` under TD02 and preserve every cumulative type/function state. | certain | current type catalog plus formal Clan class | IDA local type library / Section 21 TD02 | supervisor Gate2B | proposed-unapplied |
| C0000N9-078 | UID0000C7 | Declare only incomplete `struct SayToUserNameInputPane;` under TD03 and preserve every cumulative type/function state. | certain | current type catalog plus formal Name class | IDA local type library / Section 21 TD03 | supervisor Gate2B | proposed-unapplied |
| C0000N9-079 | UID0000D5 | Declare only incomplete `struct ShoutInputPane;` under TD04 and preserve every cumulative type/function state. | certain | current type catalog plus formal Shout class | IDA local type library / Section 21 TD04 | supervisor Gate2B | proposed-unapplied |
| C0000N9-080 | UID0000FQ | Apply T01 exact source-facing `void __thiscall UserPane__GetPreviousRecentRecipientHistory(UserPane *, short *, wchar_t *, size_t)` type and exact F01 frame delta after A01. | very strong | ignored incidental return, caller/formal/frame evidence | IDA `0x005a4ab0` / Section 21 T01/F01 | supervisor Gate2B | proposed-unapplied |
| C0000N9-081 | UID0000FQ | Apply T02 exact source-facing `void __thiscall UserPane__UpdateRecentRecipientList(UserPane *, const wchar_t *)` type and exact F02 frame delta after A02. | very strong | ignored incidental return, caller/formal/frame evidence | IDA `0x005a4b60` / Section 21 T02/F02 | supervisor Gate2B | proposed-unapplied |
| C0000N9-082 | UID0000FQ | Apply T03 exact source-facing fallback-history `void __thiscall` type and exact F03 frame delta after A03. | very strong | ignored incidental return, caller/formal/frame evidence | IDA `0x005a4c30` / Section 21 T03/F03 | supervisor Gate2B | proposed-unapplied |
| C0000N9-083 | UID0000FQ | Apply T04 exact `void __thiscall UserPane__OpenInputPaneForCurrentSayMode(UserPane *)` type with F04 protected frame after A04. | very strong | ECX member call, no consumed return, formal member | IDA `0x005a5110` / Section 21 T04/F04 | supervisor Gate2B | proposed-unapplied |
| C0000N9-084 | UID0000FQ | Apply T05 exact `void __thiscall UserPane__OpenDefaultSayInputPane(UserPane *)` type with F05 protected frame after A05. | very strong | ECX member call, mode write, formal member | IDA `0x005a53c0` / Section 21 T05/F05 | supervisor Gate2B | proposed-unapplied |
| C0000N9-085 | UID0000FQ | Apply T06 exact `void __thiscall UserPane__OpenSayToUserNameInputPane(UserPane *)` type, replacing stale cdecl, with F06 protected frame. | very strong | caller loads ECX UserPane, formal member | IDA `0x005a5450` / Section 21 T06/F06 | supervisor Gate2B | proposed-unapplied |
| C0000N9-086 | UID0000FQ | Apply T07 exact `void __thiscall UserPane__OpenSayToLastRecipientInputPane(UserPane *)` type with F07 protected frame after A07. | strong | direct UserPane fields, no consumed return | IDA `0x005a54b0` / Section 21 T07/F07 | supervisor Gate2B | proposed-unapplied |
| C0000N9-087 | UID0000FQ | Apply T08 exact `void __thiscall UserPane__OpenSayToGroupMessageInputPane(UserPane *)` type with F08 protected frame after A08. | very strong | caller ECX and formal member | IDA `0x005a5570` / Section 21 T08/F08 | supervisor Gate2B | proposed-unapplied |
| C0000N9-088 | UID0000FQ | Apply T09 exact `void __thiscall UserPane__OpenSayToClanMessageInputPane(UserPane *)` type with F09 protected frame after A09. | very strong | caller ECX and formal member | IDA `0x005a5640` / Section 21 T09/F09 | supervisor Gate2B | proposed-unapplied |
| C0000N9-089 | UID0000FQ | Apply T10 exact `void __thiscall UserPane__OpenShoutInputPane(UserPane *)` type with F10 protected frame after A10. | very strong | ECX member call, mode write, formal member | IDA `0x005a5710` / Section 21 T10/F10 | supervisor Gate2B | proposed-unapplied |
| C0000N9-090 | UID0000C4 | Apply T11 parser-safe Group constructor type with class-pointer return, `const wchar_t *groupName`, and exact F11 frame delta after A11. | very strong | constructor/vtable/formal argument/frame evidence | IDA `0x005b1ec0` / Section 21 T11/F11 | supervisor Gate2B | proposed-unapplied |
| C0000N9-091 | UID0000C4 | Apply T12 exact void Group submit member type with complete F12 frame protected after A12. | very strong | primary virtual slot/formal method/protocol | IDA `0x005b1f80` / Section 21 T12/F12 | supervisor Gate2B | proposed-unapplied |
| C0000N9-092 | UID0000C5 | Apply T13 parser-safe Clan constructor type with class-pointer return, `const wchar_t *clanName`, and exact F13 frame delta after A13. | very strong | constructor/vtable/formal argument/frame evidence | IDA `0x005b22d0` / Section 21 T13/F13 | supervisor Gate2B | proposed-unapplied |
| C0000N9-093 | UID0000C5 | Apply T14 exact void Clan submit member type with complete F14 frame protected after A14. | very strong | primary virtual slot/formal method/protocol | IDA `0x005b2390` / Section 21 T14/F14 | supervisor Gate2B | proposed-unapplied |
| C0000N9-094 | UID0000C3 | Apply T15 exact void Say submit member type with complete F15 frame protected after A15. | very strong | primary virtual slot/formal method/protocol | IDA `0x005b3670` / Section 21 T15/F15 | supervisor Gate2B | proposed-unapplied |
| C0000N9-095 | UID0000C7 | Apply T16 parser-safe Name constructor class-pointer type with complete F16 frame protected after A16. | very strong | constructor/vtables/formal source | IDA `0x005b3cb0` / Section 21 T16/F16 | supervisor Gate2B | proposed-unapplied |
| C0000N9-096 | UID0000C7 | Apply T17 exact `bool __thiscall ...HandleKeyOrTextEvent(SayToUserNameInputPane *, Event *)` type with F17 event row preserved. | very strong | secondary virtual slot/Event formal source/frame | IDA `0x005b3e80` / Section 21 T17/F17 | supervisor Gate2B | proposed-unapplied |
| C0000N9-097 | UID0000C7 | Apply T18 exact void Name submit member type with complete F18 frame protected after A18. | very strong | primary virtual slot/formal method | IDA `0x005b4080` / Section 21 T18/F18 | supervisor Gate2B | proposed-unapplied |
| C0000N9-098 | UID0000D5 | Apply T19 exact void Shout submit member type with complete F19 frame protected after A19. | very strong | primary virtual slot/formal method/protocol | IDA `0x005b4260` / Section 21 T19/F19 | supervisor Gate2B | proposed-unapplied |

## Positive Evidence Summary

- Seven class families share `LineInputPane`, three vtable views each, the same submit slot, adjacent method neighborhoods, common packet helpers, and social-mode callers. This is a stronger compilation-unit signal than filename inheritance from generated class pages.
- Ten UserPane support methods form a coherent member family: call sites pass `g_pUserPane` in ECX, dispatcher/default/shout directly use private state, recipient history methods use private Lists, and the six openers construct six pane types. Name submit's modern/legacy branch supplies the remaining direct-message class route, completing the seven-class family. The dispatcher encodes exact modes default 0, shout 1, whisper 2, group 3, clan 4.
- Exact live method bodies cover all constructors, submits, and event handlers once the two raw constructors and Name aggregate are included. No behavior requires emission from the five no-route packet clones.
- Existing accepted formal source supplied most packet/body details. The dated pre-callback defects were mechanically attributable to wrong emitter channels, missing source children, and stale names; the additive callback preserved that prior research while correcting those defects.
- UserPane owns both recipient history Lists and the selector byte. The three prerequisite functions touch only those fields and are called by Name/dispatcher code, proving dependency rather than SayInputPanes ownership.

## IDA MCP Facts

- Canonical session: `supervisor_uid0003a1_canonical_20260825_1704`; module `NexusTK.exe`; imagebase `0x00400000`; Hex-Rays ready; analysis not running.
- Mixed neighborhood query returned 20 functions, starting with three UserPane history helpers and ending with a seven-method UserPane dispatcher/opener family. Main neighborhood query returned exactly 44 functions.
- Caller disassembly at `0x00481256-0x004812d9` writes `m_currentSayMode`, loads `ECX = g_pUserPane`, and calls `0x005a5110`, `0x005a5710`, and `0x005a5450`; analogous selector branches call Group/Clan with the same ECX convention. Dispatcher/default/shout profiles are explicit `__thiscall` and directly read/write UserPane fields. This supersedes the free-function placement in current docs.
- Name class: constructor `[0x005b3cb0,0x005b3e7f)` with callers `0x005a5450`, `0x005a5bd0`, `0x005b1c40`; Event handler `[0x005b3e80,0x005b4072)` with secondary vtable xref `0x0062fccc`; submit `[0x005b4080,0x005b4219)` with primary submit slot `0x0062fcbc`.
- Complete offsets: `LineInputPane` size `0x108`; Name cursors at complete `+0x108/+0x10a`; EventHandler-adjusted accesses are `this+0x68/+0x6a`; UserPane outgoing/incoming Lists at `+0x13eb08/+0x13eb0c`, selector at `+0x13eb10`.
- Current type authority is exact: `UserPane` is an existing 1,305,476-byte/68-member UDT; `Event` is an existing 272-byte/four-member UDT; `LineInputPane` is an existing 264-byte/five-member UDT; `SayInputPane` is already an incomplete declaration; `size_t` is four bytes and `wchar_t` is two bytes. `SayToGroupMessageInputPane`, `SayToClanMessageInputPane`, `SayToUserNameInputPane`, and `ShoutInputPane` are absent and therefore require only four incomplete declarations before parser-safe source-facing prototypes are applied. `InputEvent` remains absent and is not used.
- Literal readback: `0x006309d0 "!!"`, `0x006309d8 "!"`, `0x00630a18 "To "`, `0x00630a20 "-> %s: "`, `0x00630a30 "To %s : "`, `0x00630a44 "Group => "`, `0x00630a58 "Clan => "`, `0x00630a6c "! "`, `0x00614c54 "> "`.
- The 19 action targets comprise 14 displayed `sub_*` address aliases and five registered descriptive dispatcher/opener names. All are exact typed function items. Fourteen have four empty comment channels; five retain the exact nonempty function-regular comments listed in Section 21 with their other channels empty. Fresh bounded anchored queries returned old/desired totals `0/0` for all 14 autogenerated aliases and `1/0` only for A04/A06/A08/A09/A10; every desired name was absent. No collision exists in the dated canonical session.

## Function / Child Inventory

### Mode/helper neighborhood

| Range / Item | UID / Path | Role | Source disposition |
| --- | --- | --- | --- |
| `[0x5a4ab0,0x5a4b0b)` | proposed UserPane helper page | previous outgoing/recent recipient | UserPane.cpp definition/H declaration |
| `[0x5a4b60,0x5a4c23)` | proposed UserPane helper page | dedupe/cap-ten/append outgoing recipient; selector=1 | UserPane.cpp definition/H declaration |
| `[0x5a4c30,0x5a4c8b)` | proposed UserPane helper page | previous incoming/fallback sender | UserPane.cpp definition/H declaration |
| `0x5a4db0/0x5a4e40/0x5a4e70/0x5a4f40` | UID0001KO exclusions | four 0x22 IconsPane tab/action helpers | exclude: Icons/UI owner |
| `[0x5a4de0,0x5a4e3d)` | UID0004US sibling context | MixItemDialog opener | exclude: MixItemDialog source |
| `[0x5a4ea0,0x5a4f3d)` | UID0001KO exclusion | panel/server action | exclude: non-say UI action |
| `[0x5a4f70,0x5a500f)` | named function | `RequestLocalPlayerStatus` | exclude: UserPane/network state |
| `[0x5a5010,0x5a5091)` | named function | user-list opener | exclude: UserList source |
| `[0x5a50a0,0x5a5103)` | UID0004US | bulletin session helper | exclude: UserPane/Bulletin source |
| `[0x5a5110,0x5a5337)` | UID0002RX | UserPane current-mode dispatcher | reroute to UserPane.cpp/H |
| `[0x5a5340,0x5a53bc)` | UID0001KO exclusion | status opcode `0x43` action | exclude: status/network source |
| `[0x5a53c0,0x5a544b)` | proposed opener page | UserPane default Say opener | UserPane.cpp definition/H declaration |
| `[0x5a5450,0x5a54a4)` | proposed opener page | UserPane recipient-name opener | UserPane.cpp definition/H declaration |
| `[0x5a54b0,0x5a5563)` | proposed opener page | UserPane last-recipient modern opener, zero current callers | UserPane.cpp definition/H declaration |
| `[0x5a5570,0x5a563a)` | proposed opener page | UserPane Group opener | UserPane.cpp definition/H declaration |
| `[0x5a5640,0x5a570a)` | proposed opener page | UserPane Clan opener | UserPane.cpp definition/H declaration |
| `[0x5a5710,0x5a5791)` | proposed opener page | UserPane Shout opener | UserPane.cpp definition/H declaration |

### Pane neighborhood modeled functions

| Functions / range | Role | Disposition |
| --- | --- | --- |
| `0x5b1570/0x5b1640` | legacy recipient-message ctor/submit | include through UID000401/C6, position 20 |
| `0x5b1990/0x5b1a60/0x5b1c40` | modern recipient-message ctor/submit/Event | include through UID000403/099, position 10 preamble owner |
| `0x5b1ec0/0x5b1f80` | Group ctor/submit | include through UID0001LZ/C4, position 30 |
| `0x5b22d0/0x5b2390` | Clan ctor/submit | include through UID000406/C5, position 40 |
| `0x5b2720,0x5b27c0,0x5b2830,0x5b29c0,0x5b2a70,0x5b2f70,0x5b3010,0x5b3080,0x5b3260,0x5b32d0` | command/emotion/spell input family | exclude: CommandInputPanes/emotion source |
| `0x5b34d0/0x5b3570/0x5b3670` plus raw `0x5b3490` | Say constructors/Event/submit | include through C3 exact children, position 50 |
| `0x5b3940/0x5b3a40` | ChatInputPane Event/submit | exclude: Chatting.cpp |
| `0x5b3cb0/0x5b3e80/0x5b4080` | Name ctor/Event/submit | include through 1MD/1ME/C7, position 60 |
| `0x5b4260` plus raw `0x5b4220` | Shout ctor/submit | include through 2SA/1MF/D5, position 70 |
| `0x5b44b0,0x5b4580,0x5b45f0,0x5b47e0,0x5b48b0,0x5b4920,0x5b4bb0,0x5b4cc0,0x5b4d90,0x5b4e00,0x5b4f70,0x5b5040,0x5b50b0,0x5b52f0` | command-input class methods | exclude: CommandInputPanes.cpp |
| `0x5b5400/0x5b5440` | GroupInputPane ctor/confirm | exclude: CommandInputPanes.cpp, not target-message Group class |

### Raw, compiler, data, type, and generated items

| Item | Disposition |
| --- | --- |
| Raw packet clones `0x5b1820`, `0x5b1d50`, `0x5b2160` | existing UID000402/404/405 ownerless and non-emitting |
| Raw packet islands `0x5b37f0` and `0x5b3bc0` | UID0002S8 plus proposed sibling page, ownerless and non-emitting |
| Raw ctors `0x5b3490` and `0x5b4220` | authored constructors emitted by UID0002S7/0002SA |
| Wrappers `0x5b7820`, `0x5b782b`, `0x5b784c`, `0x5b7857`, `0x5b77c8`, `0x5b77d3`, `0x5b7af0`, `0x5b7b80`, `0x5b7940` | compiler adjustors/scalar deleting destructors; no formal source |
| Vtable bases `0x62f6fc/74c/77c`, `0x62f788/7d8/808`, `0x62f814/864/894`, `0x62f8a0/8f0/920`, `0x62fb5c/bac/bdc`, `0x62fc74/cc4/cf4`, `0x62fd00/d50/d80` | compiler data; protect, do not emit |
| Nine literal heads listed in Section 13 | lexical constants in authored functions; no standalone definition |
| `SayInputMode` | exact values 0-4; emit once through UID0000FQ UserPane H |
| `Event` | direct InputPanes prerequisite; no local duplicate |
| Generated SayInputPanes/UserPane CPP/H command `000000028242` | current verified callback receipt; direct edits forbidden; commands 28163/28114 are superseded history |

Count reconciliation: 18 live SayInputPanes definitions, ten UserPane member prerequisites, 36 modeled exclusions in the two queried neighborhoods, seven raw starts, nine wrappers, 21 vtable cells, nine literal heads, one enum, one direct Event type, 29 existing relevant support pages, and three validator-allocated new by-memory pages. Every item is represented by C0000N9-002 and a specific support/source/no-code claim where a documentation action was needed.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x5a4ab0` | callers `0x5b3cb0`, `0x5b3e80`; copies from outgoing List | UserPane recent-history prerequisite |
| `0x5a4b60` | callers `0x5a5110`, `0x5a54b0`, `0x5b4080`; List compare/remove/append | UserPane recent recipient update prerequisite |
| `0x5a4c30` | callers `0x5b3cb0`, `0x5b3e80`; copies from incoming List | UserPane fallback-history prerequisite |
| `0x5a5110` | callers load `g_pUserPane` in ECX; routes five modes through private state | UserPane dispatcher |
| `0x5a53c0` | UserPane `this`, callers dispatcher/UserPane event; allocates SayInputPane | UserPane default opener |
| `0x5a5450` | selector loads UserPane in ECX; allocates Name pane | UserPane whisper-name opener |
| `0x5a54b0` | `__thiscall`, zero current caller; uses outgoing history/update/modern ctor | retained private UserPane method |
| `0x5a5570/0x5a5640` | selector loads UserPane in ECX; group/clan literals and constructors | UserPane Group/Clan openers |
| `0x5a5710` | explicit UserPane `this`; three callers and mode 1 | UserPane Shout opener |
| target-message ctor starts | constructors have allocation/inlining routes; submit handlers have vtable data refs | authored class methods despite zero direct submit callers |
| `0x5b34d0/0x5b3570/0x5b3670` | constructor route/inline equivalents; Event and submit vtable slots `0x62fbb4/0x62fba4` | Say class method set |
| `0x5b3cb0` | three direct callers; uses both UserPane previous helpers | Name constructor |
| `0x5b3e80` | vtable `0x62fccc`; no direct rel32 caller | Name Event virtual |
| `0x5b4080` | vtable `0x62fcbc`; creates modern/legacy pane | Name submit virtual |
| `0x5b4260` | vtable `0x62fd48`; no direct caller | Shout submit virtual |
| raw packet clones/islands | no function object or no incoming xref/pointer/vtable route; live submits serialize inline | non-emitting evidence, not hidden helper calls |
| prompt/prefix literals | xrefs only from matching openers/constructors/submit formatting | lexical source evidence |

## Documentation Evidence And IDA Status

- Supporting docs already establish strong behavior for legacy/modern direct message, Group, Clan, Say, and Shout children. Their accepted packet bodies are retained.
- Dated pre-callback stale docs included target generated claims, C4 CPP topology, C7/1ME method/type names, D5 blank class formal channels, 1MD blank source, UID2S8 liveness text, four string emitter assignments, and obsolete by-memory summaries. The callback historicalized or corrected each ordinary destination; command 28242 refreshed generated authority.
- Current IDA has already named the dispatcher, four routed non-default openers, five legacy/modern methods, and two Say methods. Fourteen action targets display `sub_*`; each has a collision-free, behavior-specific rename proposal, while the five already descriptive opener/dispatcher spellings receive class-qualified member names.
- Current persisted prototypes still expose incorrect raw returns, receivers, one cdecl presentation, and generic argument types. The repaired handoff preserves each rename as its own action and separately converges all 19 functions to the exact formal-source signature proved by caller ECX, vtable slots, caller return-use, formal class methods, and complete current frames.
- Current generated output is independent physical proof of the ordinary implementation. Manual coverage remains supervisor-owned and unchanged, so C0000N9-052 through C0000N9-055 remain unchecked.

## Ranked Ownership Analysis

### 1. `NexusTK/social/SayInputPanes.cpp/.h`

- Evidence for: seven related LineInputPane classes, common mode dispatcher/openers, shared packet/prompt family, existing owner routes, direct Chatting callers, contiguous principal methods, and current generated module.
- Evidence against: some helpers lie inside UserPane address space and group/clan features have separate higher-level files.
- Decision: best direct owner for the 18 live pane definitions and seven class declarations. Ten UserPane member prerequisites stay in UserPane.cpp/.h.

### 2. Split Whisper/Group/Clan class files

- Evidence for: semantic subfamilies and historical class-file prose.
- Evidence against: no original file symbols, current shared header/caller contract, repeated emitter failures, and tight shared method/vtable neighborhood.
- Decision: reject. It increases synthetic files and breaks established shared module topology.

### 3. `UserPane.cpp`, `Chatting.cpp`, `Group.cpp`, or `CommandInputPanes.cpp`

- Evidence for: helper storage on UserPane, selectors in Chatting, group feature semantics, and adjacent command functions.
- Evidence against: those are dependency/caller/neighbor relationships; the pane classes and vtables remain distinct.
- Decision: reject as primary owner for the seven Say pane classes. UserPane separately owns the ten dispatcher/opener/history support methods.

### Proposed new file/grouping, if applicable

- No new reconstruction compilation unit is proposed.
- Two allocated exact source-support pages, UID `000579` `UserPaneSayInputPaneOpeners` and UID `00057A` `UserPaneWhisperRecipientHistoryHelpers`, emit into UserPane through UID0000FQ. Allocated UID `00057B` is documentation-only and non-emitting for the raw island.

## Source Placement

- Place shared class declarations in `NexusTK/social/SayInputPanes.h`, with `#pragma once`, `../ui/dialogs/InputPanes.h`, and the seven classes in source order. Do not expose free opener declarations there.
- Place CPP includes and all 18 live class-method definitions in `NexusTK/social/SayInputPanes.cpp`. Include `SayInputPanes.h`, `Chatting.h`, `../auth/PasswordGuard.h`, `../ui/core/BlackHole.h`, and `../ui/panels/UserPane.h` directly.
- The enum and ten dispatcher/opener/history declarations/definitions are now placed in `NexusTK/ui/panels/UserPane.h/.cpp` through UID0000FQ, rerouted UID0002RX, and allocated UIDs `000579`/`00057A`. UserPane CPP directly includes `../../social/SayInputPanes.h` and `../../social/Chatting.h`.
- Keep raw packet clones, wrappers, vtables, and prompt storage non-emitting. Their semantics remain evidence for authored source.
- Remaining placement uncertainty does not block source: exact historical filenames within the social folder are not symbol-proven, but the current one-unit route is materially better supported than any split.

## Range / Split / Padding / Reclassification Analysis

- Exact included modeled ranges are listed in Section 14. Known internal padding remains excluded, including `0x5b356c-0x5b3570`, `0x5b37ea-0x5b37f0`, `0x5b4072-0x5b4080`, `0x5b4219-0x5b4220`, and `0x5b4255-0x5b4260`.
- UID0001KO and UID0001LY remain non-emitting indexes. UID0001MB becomes a non-emitting exact-child index. UID0001MD remains source-bearing because constructor and submit lack exact child pages; it emits both around the existing event child.
- Raw `0x5b3bc0-0x5b3ca5` receives a dedicated non-emitting page instead of being silently absorbed into Name/Say/Chat classes.
- String pages are reclassified from reconstructable emitters to evidence-only, because literal spelling belongs directly in function source.
- No code/data boundary mutation is recommended in IDA. Raw bodies and compiler regions are protected.

## Negative Evidence Summary

- Address adjacency does not make IconsPane/status/bulletin/user-list/command/emotion/GroupInputPane functions part of this unit; their roles and caller families are distinct.
- No xref, pointer, vtable, or live call proves any of the five raw packet clones is invoked. Each corresponding live submit serializes its packet inline.
- No `InputEvent` type exists, and no virtual evidence supports the stale `HandleHistoryNavigation` or `OnRecipientNameConfirmed` source names.
- No unique authored derived destructor body exists for these classes; shared adjustors/scalar deleting wrappers are compiler output.
- No independent global identity requires separate source definitions for the prompt fragments. Emitting blank string pages only creates markers.
- Generated file existence alone does not prove completeness or validity. The dated command-28163 files failed physical inspection; current command-28242 CPP/H passes the exact acceptance inventory.

## IDA Rename / Type / Comment Recommendations

This is a read-only structured entity handoff. B002 performed no mutation, persistence, process handling, or session handling. The dated canonical receipt and current read-only evidence source are evidence only. Each TD, A, T, F, registry, and physical-protection row below is an independent entity contract; a corresponding rename must satisfy its A row before its T row, and required incomplete declarations must exist before a signature that names them. The report does not prescribe cross-entity mutation sequencing.

The supervisor independently owns runtime attestation, IDB backup/copy/path selection, MCP/IDA process and session handling, mutation ordering, save/persistence/reopen verification, promotion/rollback, and audit/catalog recording outside this report. Missing or mismatched external prerequisites fail Gate 2B. No path, session, persistence, or lifecycle choice receives authority from this report.

### Exact name and response contract

For pair `i`, `RQ-Pi` is one literal `entity_query` call containing two ordered `kind:"names"` subqueries with exact anchored old/desired regexes derived without case or spelling changes from the A-row, `count:2`, `offset:0`, `sort_by:"addr"`, `descending:false`, and fields `addr,name`. Its result must contain exactly two ordered old/desired envelopes. Each envelope has the mandatory members `kind:"names"`, `data`, and `total`; the only permitted optional members are `error` absent or JSON null and `next_offset` absent or JSON null. A zero registration is exactly `data:[]` with `total:0`. A present registration is exactly `data:[{"kind":"name","addr":"<target>","name":"<expected exact spelling>"}]` with `total:1`: the sole nested row has exactly the three members `kind`, `addr`, and `name`, its `kind` is exactly `"name"`, its address parses numerically to the literal target despite optional leading zeroes, and its name is the exact anchored old or desired spelling for that subquery. Reject every other envelope member, nested-row member, row, continuation, duplicate, non-null optional, kind/address/name mismatch, or total/data mismatch. `lookup_funcs("sub_<address>")` is physical address-alias evidence only and never substitutes for these registry queries.

The current-schema precedent supplied for this repair returned the literal nested row `{"kind":"name","addr":"0x559360","name":"ScreenPane__FindLayerIndex"}`. It proves the mandatory three-member row shape only and is not target-state evidence for any UID0000N9 action address or spelling.

For target literal `T` and a supervisor-supplied database identifier `DB`, physical set `PR-i` is exactly: `lookup_funcs {database:DB,queries:[T]}`; `inspect_items {database:DB,addrs:[T]}`; `get_comments {database:DB,addrs:[T]}`; `get_bytes {database:DB,regions:[{addr:T,size:16}]}`; `func_profile {database:DB,queries:[{addr:T,count:1,offset:0,sort_by:"addr",descending:false,include_prototype:true,include_lists:true,max_items:50}]}`; `stack_frame {database:DB,addrs:[T]}`; `xref_query {database:DB,queries:[{addr:T,direction:"to",xref_type:"any",count:200,offset:0,sort_by:"addr",descending:false,dedup:true,include_fn:true}]}`; `disasm {database:DB,addr:T,max_instructions:1000,offset:0,include_total:true}`; and direct `decompile {database:DB,addr:T,include_addresses:false}`. Require one exact untruncated result from every call, `cursor.done:true` where emitted, no error, and exact agreement with the A/T/F row plus protection manifest. Missing optional response members are not invented. `DB` is only a request-field placeholder, not a report-selected path or session.

Each A-row first runs `RQ-Pi` and `PR-i`. Its dry request is exactly `rename {database:DB,batch:{func:[{addr:T,name:DESIRED}],dry_run:true,pure:true,allow_overwrite:false,stop_on_error:true}}`; after it, rerun `RQ-Pi` and `PR-i` and require unchanged physical/read/catalog state, including the exact old/desired zero-or-present envelope and exact three-member nested-row payloads defined above. The dry response is exactly one `func` row with numeric-target `addr`, exact old/name, and `dry_run:true`; fields `dir`, `func_addr`, and `new` are rejected. Summary requires `total:1`, `ok:1`, `failed:0`, `dry_run:true`, no `stopped_at`; optional `stop_on_error` is absent or true, optional `stopped` and `allow_overwrite` are absent or false. `error`/`dir_error` are absent or exact empty string only.

The persistent request is exactly the same object with `dry_run:false`. Its one response row requires numeric-target `addr` and exact old/name; optional row `dry_run` is absent or false, and `error`/`dir_error` are absent or exact empty string. Reject `dir`, `func_addr`, `new`, extra rows, null/non-string/nonempty errors, or any other field/state mismatch. Summary requires `total:1`, `ok:1`, `failed:0`, no `stopped_at`; optional `dry_run` is physically absent or exactly boolean false, optional `stop_on_error` is absent or true, and optional `stopped` and `allow_overwrite` are absent or false. Present true/null/non-boolean `dry_run` or any contradictory summary value hard-stops. Immediate and final entity readback reruns that row's `PR-i` and `RQ-Pi`; only the current entity's display/name registration may differ from prestate, and its zero/present registry state must use the exact envelope and nested-row form above. At this rename-only readback, `lookup_funcs`, `inspect_items.name`, and registry state must show the desired name; direct decompile must preserve the exact pre-T prototype/body but may still display either the old cached identifier or the desired identifier. That cache-only allowance grants no registry/name credit and ends at T: the immediate and final post-T decompile must use the exact desired named signature. Exact address spelling may contain leading zeroes but must parse numerically to the literal target.

Fresh registry baseline is literal: A04/A06/A08/A09/A10 are old/desired `1/0`; all 14 displayed autogenerated `sub_*` targets A01-A03/A05/A07/A11-A19 are `0/0` because address aliases are not registered-name rows. Each A row's expected immediate and final entity readback is exact `0/1`. Every `1/0`, `0/0`, or `0/1` total is shorthand for the full payload contract, never a totals-only check: total zero requires exact `data:[]`; total one requires one exact nested `{"kind":"name","addr":"<target>","name":"<expected>"}` row and no other member, row, or continuation.

### Exact prerequisite type declarations and public response contracts

The current type set `TM` has ten exact rows. Existing and protected: `UserPane` is `exists:true`, UDT size `1305476`, `member_count:68`; `Event` is UDT size `272`, four members; `LineInputPane` is UDT size `264`, five members; `SayInputPane` is an existing incomplete non-UDT with unknown size and zero members; `size_t` is four bytes; `wchar_t` is two bytes. Missing prestates are exact `exists:false` / `Type not found` for `SayToGroupMessageInputPane`, `SayToClanMessageInputPane`, `SayToUserNameInputPane`, and `ShoutInputPane`.

| ID / claim | Exact one-entity request | Exact expected readback and protection |
| --- | --- | --- |
| TD01 / C0000N9-076 | `declare_type({database:DB,decls:"struct SayToGroupMessageInputPane;"})` | Group becomes exactly one incomplete declaration; the other nine TM rows are protected and no layout is invented. |
| TD02 / C0000N9-077 | `declare_type({database:DB,decls:"struct SayToClanMessageInputPane;"})` | Clan becomes exactly one incomplete declaration; the other nine TM rows are protected and no layout is invented. |
| TD03 / C0000N9-078 | `declare_type({database:DB,decls:"struct SayToUserNameInputPane;"})` | Name becomes exactly one incomplete declaration; the other nine TM rows are protected and no layout is invented. |
| TD04 / C0000N9-079 | `declare_type({database:DB,decls:"struct ShoutInputPane;"})` | Shout becomes exactly one incomplete declaration; the other nine TM rows are protected and no layout is invented. |

Each `declare_type` structured result must contain only an exact one-row `result` array. The row must echo only exact requested string `decl`; sole optional string `error` is absent or exactly `""`. Reject null/non-string/nonempty error, changed declaration, another member, or missing/extra/reordered row. Immediate and final `type_inspect` for the declared entity must be exact: requested bare type `name`, `exists:true`, `declaration` equal to that bare name, unsigned unknown-size sentinel `18446744073709551615`, `is_func:false`, `is_ptr:false`, `is_enum:false`, `is_udt:false`, `members:null`, and `member_count:0`; missing/extra/changed state fails. The other nine TM entries and all function/name/frame state are protected; only that entity's absent-to-incomplete type transition is permitted.

Each T row is exactly `set_type({database:DB,edits:[{addr:T,kind:"function",signature:SIG}]})` with the literal named declarator below. Its structured result must contain only a `result` array with exactly one row. Optional `edit`, `kind`, and `ok` may each be absent; if emitted they must be the exact request-preserving edit, `"function"`, and boolean true. Sole optional string `error` is absent or exactly `""`. Reject null/non-string/nonempty error, changed/extra edit member, wrong kind/ok, any other row member, or missing/extra/reordered row. Immediate and final entity readback must show the exact normalized name-free posttype and a direct decompile beginning with the exact named signature; rerun that target's `PR-i`, `RQ-Pi`, full frame, and all ten TM rows. Only the listed prototype/receiver/argument-frame delta is permitted; name, bounds, bytes, comments, xrefs, callees, locals, saved-register row, return-address row, unrelated arguments, all TM declarations, and registry state remain exact.

| ID | Address/range; exact current prestate | Proposed one mutation | Required immediate/final poststate |
| --- | --- | --- | --- |
| A01 / C0000N9-056 | `[0x5a4ab0,0x5a4b0b)`, `sub_5A4AB0`, `wchar_t *__thiscall(_DWORD *this, __int16 *, wchar_t *Destination, rsize_t SizeInWords)`, bytes `55 8b ec 56 8b b1 08 eb 13 00 8b 4e 0c 85 c9 7f`, callers `0x5b3cb0,0x5b3e80`, four comments empty, registered old/desired totals 0/0 | pure rename to `UserPane__GetPreviousRecentRecipientHistory` | exact new name; all type/bounds/bytes/comments/callers/callees preserved; old/desired 0/1 |
| A02 / C0000N9-057 | `[0x5a4b60,0x5a4c23)`, `sub_5A4B60`, `int __thiscall(int this, const unsigned __int16 *)`, bytes `55 8b ec 51 53 56 57 8b f9 83 ca ff 33 f6 8b 8f`, callers `0x5a5110,0x5a54b0,0x5b4080`, comments empty, registered totals 0/0 | pure rename to `UserPane__UpdateRecentRecipientList` | only exact name/catalog delta; all other facets preserved; totals 0/1 |
| A03 / C0000N9-058 | `[0x5a4c30,0x5a4c8b)`, `sub_5A4C30`, same four-argument history type, bytes `55 8b ec 56 8b b1 0c eb 13 00 8b 4e 0c 85 c9 7f`, callers `0x5b3cb0,0x5b3e80`, comments empty, registered totals 0/0 | pure rename to `UserPane__GetPreviousFallbackRecipientHistory` | only exact name/catalog delta; totals 0/1 |
| A04 / C0000N9-059 | `[0x5a5110,0x5a5337)`, `OpenInputPaneForCurrentSayMode`, `NewSayToUserMessageInputPane *__thiscall(_DWORD *this)`, bytes `55 8b ec 6a ff 68 b0 a5 60 00 64 a1 00 00 00 00`, four callers, function-regular comment `Dispatches UserPane::m_currentSayMode to default, shout, whisper, group, or clan input-pane creation.`, other comments empty, totals 1/0 | pure rename to `UserPane__OpenInputPaneForCurrentSayMode` | only name/catalog delta; type/body/comment/callers/callees preserved; totals 0/1 |
| A05 / C0000N9-060 | `[0x5a53c0,0x5a544b)`, `sub_5A53C0`, `int __thiscall(_DWORD *this)`, bytes `55 8b ec 6a ff 68 e3 a5 60 00 64 a1 00 00 00 00`, callers `0x5a5110,0x5a5bd0`, comments empty, registered totals 0/0 | pure rename to `UserPane__OpenDefaultSayInputPane` | only name/catalog delta; allocation/vtable/caller/callee seals preserved; totals 0/1 |
| A06 / C0000N9-061 | `[0x5a5450,0x5a54a4)`, `OpenSayToUserNameInputPane`, `void *__cdecl()`, bytes `55 8b ec 6a ff 68 09 a6 60 00 64 a1 00 00 00 00`, caller `0x4811c0` with ECX UserPane, function-regular comment `Opens the recipient-name input pane used by the Whisper selector row.`, other comments empty, totals 1/0 | pure rename to `UserPane__OpenSayToUserNameInputPane` | only name/catalog delta; type/body/comment/caller/callees preserved; totals 0/1 |
| A07 / C0000N9-062 | `[0x5a54b0,0x5a5563)`, displayed `sub_5A54B0`, `NewSayToUserMessageInputPane *__thiscall(_DWORD *this)`, bytes `55 8b ec 6a ff 68 32 a6 60 00 64 a1 00 00 00 00`, zero callers, comments empty, registered old/desired totals 0/0 | pure rename to `UserPane__OpenSayToLastRecipientInputPane` | only name/catalog delta; desired becomes sole 1 at target while old remains 0; type/body/comments/zero-caller/callees preserved |
| A08 / C0000N9-063 | `[0x5a5570,0x5a563a)`, `OpenSayToGroupMessageInputPane`, `LineInputPane *()`, bytes `55 8b ec 6a ff 68 73 a6 60 00 64 a1 00 00 00 00`, caller `0x4811c0` with ECX UserPane, function-regular comment `Opens the group-message input pane with the "!!" command prefix and "Group => " prompt.`, other comments empty, totals 1/0 | pure rename to `UserPane__OpenSayToGroupMessageInputPane` | only name/catalog delta; all physical/comment/caller/callee facets preserved; totals 0/1 |
| A09 / C0000N9-064 | `[0x5a5640,0x5a570a)`, `OpenSayToClanMessageInputPane`, `LineInputPane *()`, bytes `55 8b ec 6a ff 68 b4 a6 60 00 64 a1 00 00 00 00`, caller `0x4811c0` with ECX UserPane, function-regular comment `Opens the clan-message input pane with the "!" command prefix and "Clan => " prompt.`, other comments empty, totals 1/0 | pure rename to `UserPane__OpenSayToClanMessageInputPane` | only name/catalog delta; all physical/comment/caller/callee facets preserved; totals 0/1 |
| A10 / C0000N9-065 | `[0x5a5710,0x5a5791)`, `OpenShoutInputPane`, `LineInputPane *__thiscall(_DWORD *this)`, bytes `55 8b ec 6a ff 68 e7 a6 60 00 64 a1 00 00 00 00`, three callers, function-regular comment `Sets shout mode and opens a ShoutInputPane initialized with the "! " prompt.`, other comments empty, totals 1/0 | pure rename to `UserPane__OpenShoutInputPane` | only name/catalog delta; all physical/comment/caller/callee facets preserved; totals 0/1 |
| A11 / C0000N9-066 | `[0x5b1ec0,0x5b1f7e)`, `sub_5B1EC0`, `int __thiscall(int this, wchar_t *Source)`, bytes `55 8b ec 6a ff 68 ee b2 60 00 64 a1 00 00 00 00`, zero code callers, vtables/literal/callees sealed, comments empty, registered totals 0/0 | pure rename to `SayToGroupMessageInputPane__Constructor` | only name/catalog delta; totals 0/1 |
| A12 / C0000N9-067 | `[0x5b1f80,0x5b2152)`, `sub_5B1F80`, `void __thiscall(WCHAR *this)`, bytes `55 8b ec 81 ec 34 04 00 00 a1 24 2f 67 00 33 c5`, vtable-only route, comments empty, registered totals 0/0 | pure rename to `SayToGroupMessageInputPane__OnSubmitInput` | only name/catalog delta; exact protocol/callee/vtable state preserved; totals 0/1 |
| A13 / C0000N9-068 | `[0x5b22d0,0x5b238e)`, `sub_5B22D0`, `int __thiscall(int this, wchar_t *Source)`, bytes `55 8b ec 6a ff 68 21 b3 60 00 64 a1 00 00 00 00`, zero code callers, comments empty, registered totals 0/0 | pure rename to `SayToClanMessageInputPane__Constructor` | only name/catalog delta; totals 0/1 |
| A14 / C0000N9-069 | `[0x5b2390,0x5b2562)`, `sub_5B2390`, `void __thiscall(WCHAR *this)`, same 0x434-frame prefix as A12, vtable-only route, comments empty, registered totals 0/0 | pure rename to `SayToClanMessageInputPane__OnSubmitInput` | only name/catalog delta; totals 0/1 |
| A15 / C0000N9-070 | `[0x5b3670,0x5b37ea)`, `sub_5B3670`, `void __thiscall(_DWORD **this)`, bytes `55 8b ec 81 ec 30 04 00 00 a1 24 2f 67 00 33 c5`, vtable-only route, comments empty, registered totals 0/0 | pure rename to `SayInputPane__OnSubmitInput` | only name/catalog delta; exact history-save/protocol/callee/vtable state preserved; totals 0/1 |
| A16 / C0000N9-071 | `[0x5b3cb0,0x5b3e7f)`, `sub_5B3CB0`, `int __thiscall(int this)`, bytes `55 8b ec 6a ff 68 db b3 60 00 64 a1 00 00 00 00`, three callers, comments empty, registered totals 0/0 | pure rename to `SayToUserNameInputPane__Constructor` | only name/catalog delta; exact vtables/helpers/literals/callers preserved; totals 0/1 |
| A17 / C0000N9-072 | `[0x5b3e80,0x5b4072)`, `sub_5B3E80`, `bool __thiscall(int this, Event *event)`, bytes `55 8b ec 81 ec 04 02 00 00 a1 24 2f 67 00 33 c5`, vtable-only route, comments empty, registered totals 0/0 | pure rename to `SayToUserNameInputPane__HandleKeyOrTextEvent` | only name/catalog delta; Event type, complete-offset behavior, xrefs/callees preserved; totals 0/1 |
| A18 / C0000N9-073 | `[0x5b4080,0x5b4219)`, `sub_5B4080`, `__int16 __thiscall(_DWORD **this)`, bytes `55 8b ec 6a ff 68 2a b4 60 00 64 a1 00 00 00 00`, vtable-only route, comments empty, registered totals 0/0 | pure rename to `SayToUserNameInputPane__OnSubmitInput` | only name/catalog delta; constructor branches/helper route preserved; totals 0/1 |
| A19 / C0000N9-074 | `[0x5b4260,0x5b43bc)`, `sub_5B4260`, `void __thiscall(_DWORD **this)`, same 0x430-frame prefix as A15, vtable-only route, comments empty, registered totals 0/0 | pure rename to `ShoutInputPane__OnSubmitInput` | only name/catalog delta; exact gate/protocol/callees preserved; totals 0/1 |

### Exact source-facing type actions

Every T row requires its corresponding A rename and any pane-type declaration named by that signature. The named declarator is mandatory in the request because current `set_type` rejects an anonymous function type. The normalized posttype omits only the function-name token; direct decompile must show the complete named request signature.

| ID / claim | Exact sole `set_type` signature | Exact normalized persisted posttype |
| --- | --- | --- |
| T01 / C0000N9-080 | `void __thiscall UserPane__GetPreviousRecentRecipientHistory(UserPane *this, short *historyIndex, wchar_t *recipient, size_t recipientCount)` | `void __thiscall(UserPane *this, short *historyIndex, wchar_t *recipient, size_t recipientCount)` |
| T02 / C0000N9-081 | `void __thiscall UserPane__UpdateRecentRecipientList(UserPane *this, const wchar_t *recipient)` | `void __thiscall(UserPane *this, const wchar_t *recipient)` |
| T03 / C0000N9-082 | `void __thiscall UserPane__GetPreviousFallbackRecipientHistory(UserPane *this, short *historyIndex, wchar_t *recipient, size_t recipientCount)` | `void __thiscall(UserPane *this, short *historyIndex, wchar_t *recipient, size_t recipientCount)` |
| T04 / C0000N9-083 | `void __thiscall UserPane__OpenInputPaneForCurrentSayMode(UserPane *this)` | `void __thiscall(UserPane *this)` |
| T05 / C0000N9-084 | `void __thiscall UserPane__OpenDefaultSayInputPane(UserPane *this)` | `void __thiscall(UserPane *this)` |
| T06 / C0000N9-085 | `void __thiscall UserPane__OpenSayToUserNameInputPane(UserPane *this)` | `void __thiscall(UserPane *this)` |
| T07 / C0000N9-086 | `void __thiscall UserPane__OpenSayToLastRecipientInputPane(UserPane *this)` | `void __thiscall(UserPane *this)` |
| T08 / C0000N9-087 | `void __thiscall UserPane__OpenSayToGroupMessageInputPane(UserPane *this)` | `void __thiscall(UserPane *this)` |
| T09 / C0000N9-088 | `void __thiscall UserPane__OpenSayToClanMessageInputPane(UserPane *this)` | `void __thiscall(UserPane *this)` |
| T10 / C0000N9-089 | `void __thiscall UserPane__OpenShoutInputPane(UserPane *this)` | `void __thiscall(UserPane *this)` |
| T11 / C0000N9-090 | `SayToGroupMessageInputPane *__thiscall SayToGroupMessageInputPane__Constructor(SayToGroupMessageInputPane *this, const wchar_t *groupName)` | `SayToGroupMessageInputPane *__thiscall(SayToGroupMessageInputPane *this, const wchar_t *groupName)` |
| T12 / C0000N9-091 | `void __thiscall SayToGroupMessageInputPane__OnSubmitInput(SayToGroupMessageInputPane *this)` | `void __thiscall(SayToGroupMessageInputPane *this)` |
| T13 / C0000N9-092 | `SayToClanMessageInputPane *__thiscall SayToClanMessageInputPane__Constructor(SayToClanMessageInputPane *this, const wchar_t *clanName)` | `SayToClanMessageInputPane *__thiscall(SayToClanMessageInputPane *this, const wchar_t *clanName)` |
| T14 / C0000N9-093 | `void __thiscall SayToClanMessageInputPane__OnSubmitInput(SayToClanMessageInputPane *this)` | `void __thiscall(SayToClanMessageInputPane *this)` |
| T15 / C0000N9-094 | `void __thiscall SayInputPane__OnSubmitInput(SayInputPane *this)` | `void __thiscall(SayInputPane *this)` |
| T16 / C0000N9-095 | `SayToUserNameInputPane *__thiscall SayToUserNameInputPane__Constructor(SayToUserNameInputPane *this)` | `SayToUserNameInputPane *__thiscall(SayToUserNameInputPane *this)` |
| T17 / C0000N9-096 | `bool __thiscall SayToUserNameInputPane__HandleKeyOrTextEvent(SayToUserNameInputPane *this, Event *event)` | `bool __thiscall(SayToUserNameInputPane *this, Event *event)` |
| T18 / C0000N9-097 | `void __thiscall SayToUserNameInputPane__OnSubmitInput(SayToUserNameInputPane *this)` | `void __thiscall(SayToUserNameInputPane *this)` |
| T19 / C0000N9-098 | `void __thiscall ShoutInputPane__OnSubmitInput(ShoutInputPane *this)` | `void __thiscall(ShoutInputPane *this)` |

The three history-helper `void` returns are source-facing corrections, not guesses: every caller ignores EAX and the two control paths leave incompatible incidental values. T04-T10 similarly discard allocation/helper residues that no caller consumes and restore the proved `UserPane` receiver; T06 specifically repairs the stale cdecl presentation proved false by caller-loaded ECX. T11/T13/T16 use the established IDA constructor convention of class-pointer return. T12/T14/T15/T18/T19 follow the primary submit vtable's void contract; T17 retains the directly modeled bool/Event contract while repairing only the receiver.

### Complete stack-frame protection manifest

Each F row is the complete current frame from fresh `stack_frame`, not a sample. Every local, saved-register, return-address, and unaffected argument row is protected. Only the explicit argument rename/type deltas below are permitted; receiver and return changes do not add stack rows. Existing analysis-artifact `arg_4` rows on no-argument members remain protected rather than being silently removed.

| Frame | Exact current rows | Sole permitted post-T delta |
| --- | --- | --- |
| F01 | `__saved_registers@0x4/4:_DWORD; __return_address@0x8/4:_UNKNOWN *; arg_0@0xc/4:int; Destination@0x10/4:wchar_t *; SizeInWords@0x14/4:rsize_t` | `arg_0 -> historyIndex:short *`; `Destination -> recipient:wchar_t *`; `SizeInWords -> recipientCount:size_t`; first two rows exact. |
| F02 | `var_4@0xc/4:_DWORD; __saved_registers@0x10/4:_DWORD; __return_address@0x14/4:_UNKNOWN *; arg_0@0x18/4:_DWORD` | only `arg_0 -> recipient:const wchar_t *`; first three rows exact. |
| F03 | `__saved_registers@0x4/4:_DWORD; __return_address@0x8/4:_UNKNOWN *; arg_0@0xc/4:int; Destination@0x10/4:wchar_t *; SizeInWords@0x14/4:rsize_t` | same three argument deltas as F01; first two rows exact. |
| F04 | `Block@0x8/4:void *; var_210@0xc/2:wchar_t; Buffer@0x10c/2:wchar_t; Destination@0x18c/2:wchar_t; var_10@0x20c/4:_DWORD; var_C@0x210/4:_DWORD; var_4@0x218/4:_DWORD; __saved_registers@0x21c/4:_DWORD; __return_address@0x220/4:_UNKNOWN *; arg_4@0x228/4:_DWORD` | all ten rows exact; no stack delta. |
| F05 | `Block@0x8/4:void *; var_C@0xc/4:_DWORD; var_4@0x14/4:_DWORD; __saved_registers@0x18/4:_DWORD; __return_address@0x1c/4:_UNKNOWN *; arg_4@0x24/4:_DWORD` | all six rows exact; no stack delta. |
| F06 | `Block@0x4/4:void *; var_C@0x8/4:_DWORD; var_4@0x10/4:_DWORD; __saved_registers@0x14/4:_DWORD; __return_address@0x18/4:_UNKNOWN *; arg_4@0x20/4:_DWORD` | all six rows exact while calling convention becomes thiscall; no stack delta. |
| F07 | `Block@0x8/4:void *; Destination@0xc/2:wchar_t; var_10@0x8c/4:_DWORD; var_C@0x90/4:_DWORD; var_4@0x98/4:_DWORD; __saved_registers@0x9c/4:_DWORD; __return_address@0xa0/4:_UNKNOWN *; arg_4@0xa8/4:_DWORD` | all eight rows exact; no stack delta. |
| F08 | `Block@0x8/4:void *; Buffer@0xc/2:wchar_t; var_10@0x10c/4:_DWORD; var_C@0x110/4:_DWORD; var_4@0x118/4:_DWORD; __saved_registers@0x11c/4:_DWORD; __return_address@0x120/4:_UNKNOWN *; arg_4@0x128/4:_DWORD` | all eight rows exact; no stack delta. |
| F09 | same exact eight rows/offsets/types as F08 | no stack delta. |
| F10 | `Block@0x8/4:void *; var_C@0xc/4:_DWORD; var_4@0x14/4:_DWORD; __saved_registers@0x18/4:_DWORD; __return_address@0x1c/4:_UNKNOWN *; arg_4@0x24/4:_DWORD` | all six rows exact; no stack delta. |
| F11 | `var_118@0xc/4:LineInputPane *; var_114@0x10/4:_DWORD; Buffer@0x14/2:wchar_t; var_10@0x114/4:_DWORD; var_C@0x118/4:_DWORD; var_4@0x120/4:_DWORD; __saved_registers@0x124/4:_DWORD; __return_address@0x128/4:_UNKNOWN *; Source@0x12c/4:wchar_t *; arg_4@0x130/4:_DWORD` | only `Source -> groupName:const wchar_t *`; other nine rows exact. |
| F12 | `var_434@0x4/4:MemoryMan *; WideCharStr@0x8/2:WCHAR; Src@0x208/1:_BYTE; destination@0x209/1:unsigned __int8; var_22E@0x20a/1:_BYTE; var_22D@0x20b/1:_BYTE; MultiByteStr@0x334/0x100:CHAR[256]; var_4@0x434/4:_DWORD; __saved_registers@0x438/4:_DWORD; __return_address@0x43c/4:_UNKNOWN *` | all ten rows exact; no stack delta. |
| F13 | same exact ten rows/offsets/types as F11 | only `Source -> clanName:const wchar_t *`; other nine rows exact. |
| F14 | same exact ten rows/offsets/types as F12 | no stack delta. |
| F15 | `MultiByteStr@0x4/0x100:CHAR[256]; WideCharStr@0x104/2:WCHAR; Src@0x304/1:_BYTE; destination@0x305/1:unsigned __int8; var_12E@0x306/1:unsigned __int8; var_12D@0x307/0x129:_BYTE[297]; var_4@0x430/4:_DWORD; __saved_registers@0x434/4:_DWORD; __return_address@0x438/4:_UNKNOWN *` | all nine rows exact; no stack delta. |
| F16 | `var_98@0xc/4:LineInputPane *; var_94@0x10/4:_DWORD; Destination@0x14/2:wchar_t; var_10@0x94/4:_DWORD; var_C@0x98/4:_DWORD; var_4@0xa0/4:_DWORD; __saved_registers@0xa4/4:_DWORD; __return_address@0xa8/4:_UNKNOWN *; arg_4@0xb0/4:_DWORD` | all nine rows exact; no stack delta. |
| F17 | `Destination@0xc/2:wchar_t; var_4@0x20c/4:_DWORD; __saved_registers@0x210/4:_DWORD; __return_address@0x214/4:_UNKNOWN *; event@0x218/4:Event *` | all five rows exact, including `event`; no stack delta. |
| F18 | `Block@0xc/4:void *; Source@0x10/2:wchar_t; recipientName@0x210/2:wchar_t; Buffer@0x410/2:wchar_t; var_10@0x510/4:_DWORD; var_C@0x514/4:_DWORD; var_4@0x51c/4:_DWORD; __saved_registers@0x520/4:_DWORD; __return_address@0x524/4:_UNKNOWN *; arg_4@0x52c/4:_DWORD` | all ten rows exact; no stack delta. |
| F19 | `WideCharStr@0x4/2:WCHAR; MultiByteStr@0x204/0x100:CHAR[256]; Src@0x304/1:_BYTE; destination@0x305/1:unsigned __int8; var_12E@0x306/1:unsigned __int8; var_12D@0x307/0x129:_BYTE[297]; var_4@0x430/4:_DWORD; __saved_registers@0x434/4:_DWORD; __return_address@0x438/4:_UNKNOWN *` | all nine rows exact; no stack delta. |

### Exact physical protection manifest

The following incoming-xref and callee lists are literal dated prestates. Every immediate and final entity readback must reproduce the exact row for its action target; order is normalized ascending for comparison, and zero means an exact empty list. Function bounds, prototype, first 16 bytes, and all four comments are additionally protected by the corresponding A-row above.

| Action | Exact incoming code/data xrefs | Exact direct callee starts |
| --- | --- | --- |
| A01 | code `0x5b3d5a,0x5b3de6,0x5b3fa9` | `0x5cd657` |
| A02 | code `0x5a51b9,0x5a5518,0x5b40f8,0x5b4172` | zero |
| A03 | code `0x5b3d62,0x5b3dee,0x5b3ef1` | `0x5cd657` |
| A04 | code `0x48126b,0x481ef6,0x4cf704,0x4cf937,0x5a6351` | `0x41b9b0,0x4f1c00,0x4f20a0,0x4f4aa0,0x5a4b60,0x5a53c0,0x5a5710,0x5b1990,0x5c772f,0x5cd657` |
| A05 | code `0x5a5318,0x5a62c0` | `0x4f1c00,0x4f4aa0` |
| A06 | code `0x4812d9` | `0x4f4aa0,0x5b3cb0` |
| A07 | zero | `0x4f4aa0,0x5a4b60,0x5b1990,0x5c772f,0x5cd657` |
| A08 | code `0x481310` | `0x41b9b0,0x4f1c00,0x4f20a0,0x4f4aa0,0x5c772f,0x5cd657` |
| A09 | code `0x481347` | `0x41b9b0,0x4f1c00,0x4f20a0,0x4f4aa0,0x5c772f,0x5cd657` |
| A10 | code `0x4812a2,0x5a5170,0x5a63a7` | `0x4f1c00,0x4f4aa0` |
| A11 | zero | `0x41b9b0,0x4f1c00,0x4f20a0,0x5c772f,0x5cd657` |
| A12 | data `0x62f85c` | `0x465890,0x4f2300,0x4f2310,0x516030,0x516220,0x574bb0,0x575380,0x5957c0,0x5c7655,0x5c772f` |
| A13 | zero | `0x41b9b0,0x4f1c00,0x4f20a0,0x5c772f,0x5cd657` |
| A14 | data `0x62f8e8` | `0x465890,0x4f2300,0x4f2310,0x516030,0x516220,0x574bb0,0x575380,0x5957c0,0x5c7655,0x5c772f` |
| A15 | data `0x62fba4` | `0x465890,0x4f2300,0x4f2310,0x516030,0x516220,0x574bb0,0x575380,0x5957c0,0x5a49e0,0x60d170` |
| A16 | code `0x5a5490,0x5a638b,0x5b1d0b` | `0x4f0350,0x4f1c00,0x4f20a0,0x58f2a0,0x58fc30,0x5a4ab0,0x5a4c30,0x5c772f` |
| A17 | data `0x62fccc` | `0x4a8b10,0x4f25a0,0x58f2a0,0x58fc30,0x5a4ab0,0x5a4c30,0x5c772f,0x5cd657` |
| A18 | data `0x62fcbc` | `0x41b9b0,0x4f1c00,0x4f20a0,0x4f2300,0x4f2310,0x4f4aa0,0x5a4b60,0x5b1990,0x5c772f,0x5cd657` |
| A19 | data `0x62fd48` | `0x465890,0x4f2300,0x4f2310,0x516030,0x516220,0x574bb0,0x575380,0x5957c0,0x5c772f,0x60d170` |

Only the four incomplete declarations, 19 pure renames, and 19 exact function type applications are authorized. No comment mutation is authorized; each row's four literal comment channels are protected, including five nonempty function-regular comments above. Existing prerequisite UDTs, named class methods outside the action set, raw starts, wrappers, vtables, globals, literal data, and every nonlisted type are no-action dependencies. No other Gate 2B mutation, rename, type, comment, code/data definition, layout/member invention, or boundary change is authorized.

The fixed handoff cardinality is 42 independent entity mutations: four one-declaration TD rows, 19 pure A renames, and 19 one-function T type applications. Each A row also carries one read-only dry-run response contract. This cardinality is an evidence/allocation fact, not a transaction sequence. Every entity must independently satisfy its literal prestate, response schema, permitted delta, complete F-row and physical protections, and immediate/final expected readback; a mismatch fails that entity and Gate 2B.

No report-owned operational transaction package remains. Runtime identity, storage paths, backup/copy choices, process/session controls, cross-entity ordering, persistence and independent persistence verification, promotion/rollback, and audit/catalog/lifecycle actions are exclusively supervisor-owned outside this report.

## First-Draft C++ Recommendation

All source below is exact formal-channel text implemented during the accepted callback, not illustrative report-only code. Existing accepted bodies not repeated here remain preserved at the current destination hashes in Section 32.

### UID000099 central SayInputPanes formal channels

UID000099 is the first SayInputPanes emitter. Its formal H replacement owns the unit guard/include and then its existing class declaration; the remaining six class declarations follow through child H composition at positions 20 through 70. Its formal CPP replacement owns the compilation-unit include block and then `[[CHILDREN]]`:

```cpp
#pragma once

#include "../ui/dialogs/InputPanes.h"

class NewSayToUserMessageInputPane : public LineInputPane
{
public:
    explicit NewSayToUserMessageInputPane(const wchar_t *recipientName);

protected:
    virtual void OnSubmitInput();
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    wchar_t m_recipientName[128];
};
```

```cpp
#include "SayInputPanes.h"

#include "Chatting.h"
#include "../auth/PasswordGuard.h"
#include "../ui/core/BlackHole.h"
#include "../ui/panels/UserPane.h"

[[CHILDREN]]
```

No `SayInputMode`, UserPane dispatcher, opener, or history declaration belongs in SayInputPanes H, and no such definition belongs in SayInputPanes CPP.

### UID0002RX formal channels

UID0002RX is rerouted to UID0000FQ. Its formal H is blank because the declaration is inserted into the existing `UserPane` class. Its formal CPP replacement is:

```cpp
void UserPane::OpenInputPaneForCurrentSayMode()
{
    if (!g_useEpfAssets || g_pChattingHandlePane->m_chatTargetPending)
    {
        OpenDefaultSayInputPane();
        return;
    }

    switch (m_currentSayMode)
    {
    case kSayInputModeDefault:
        OpenDefaultSayInputPane();
        break;
    case kSayInputModeShout:
        OpenShoutInputPane();
        break;
    case kSayInputModeWhisper:
    {
        wchar_t recipientName[64] = L"";
        if (m_outgoingWhisperRecipientHistory->GetCount() > 0)
        {
            const int last = m_outgoingWhisperRecipientHistory->GetCount() - 1;
            wcscpy_s(recipientName, _countof(recipientName),
                static_cast<const wchar_t *>(
                    m_outgoingWhisperRecipientHistory->GetElementAt(last)));
        }
        UpdateRecentRecipientList(recipientName);
        new NewSayToUserMessageInputPane(recipientName);
        break;
    }
    case kSayInputModeGroup:
        new SayToGroupMessageInputPane(L"!!");
        break;
    case kSayInputModeClan:
        new SayToClanMessageInputPane(L"!");
        break;
    }
}
```

### Proposed UserPane opener page formal CPP; H blank

The exact new support page is `by-memory/0x005a53c0-0x005a5791.UserPaneSayInputPaneOpeners.md`, owner/emitter UID0000FQ. It emits all six modeled members, including the source-bearing zero-current-caller body at `0x005a54b0`:

```cpp
void UserPane::OpenDefaultSayInputPane()
{
    m_currentSayMode = kSayInputModeDefault;
    new SayInputPane();
}

void UserPane::OpenSayToUserNameInputPane()
{
    new SayToUserNameInputPane();
}

void UserPane::OpenSayToLastRecipientInputPane()
{
    wchar_t recipientName[64] = L"";
    if (m_outgoingWhisperRecipientHistory->GetCount() > 0)
    {
        const int last = m_outgoingWhisperRecipientHistory->GetCount() - 1;
        wcscpy_s(recipientName, _countof(recipientName),
            static_cast<const wchar_t *>(
                m_outgoingWhisperRecipientHistory->GetElementAt(last)));
    }
    UpdateRecentRecipientList(recipientName);
    new NewSayToUserMessageInputPane(recipientName);
}

void UserPane::OpenSayToGroupMessageInputPane()
{
    new SayToGroupMessageInputPane(L"!!");
}

void UserPane::OpenSayToClanMessageInputPane()
{
    new SayToClanMessageInputPane(L"!");
}

void UserPane::OpenShoutInputPane()
{
    m_currentSayMode = kSayInputModeShout;
    new ShoutInputPane();
}
```

### Proposed UserPane helper page formal CPP; H blank

```cpp
void UserPane::GetPreviousRecentRecipientHistory(
    short *historyIndex, wchar_t *recipient, size_t recipientCount)
{
    const int count = m_outgoingWhisperRecipientHistory->GetCount();
    if (count <= 0)
    {
        recipient[0] = L'\0';
        return;
    }

    const int index = *historyIndex == -1
        ? count - 1
        : (count + *historyIndex - 1) % count;
    *historyIndex = static_cast<short>(index);
    wcscpy_s(recipient, recipientCount,
        static_cast<const wchar_t *>(
            m_outgoingWhisperRecipientHistory->GetElementAt(index)));
}

void UserPane::UpdateRecentRecipientList(const wchar_t *recipient)
{
    int foundIndex = -1;
    const int count = m_outgoingWhisperRecipientHistory->GetCount();
    for (int i = 0; i < count; ++i)
    {
        if (wcscmp(static_cast<const wchar_t *>(
                m_outgoingWhisperRecipientHistory->GetElementAt(i)), recipient) == 0)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex >= 0)
        m_outgoingWhisperRecipientHistory->RemoveAt(foundIndex, 1);
    else if (count >= 10)
        m_outgoingWhisperRecipientHistory->RemoveAt(0, 1);

    m_outgoingWhisperRecipientHistory->Append(
        1, const_cast<wchar_t *>(recipient));
    m_whisperHistorySource = 1;
}

void UserPane::GetPreviousFallbackRecipientHistory(
    short *historyIndex, wchar_t *recipient, size_t recipientCount)
{
    const int count = m_incomingWhisperSenderHistory->GetCount();
    if (count <= 0)
    {
        recipient[0] = L'\0';
        return;
    }

    const int index = *historyIndex == -1
        ? count - 1
        : (count + *historyIndex - 1) % count;
    *historyIndex = static_cast<short>(index);
    wcscpy_s(recipient, recipientCount,
        static_cast<const wchar_t *>(
            m_incomingWhisperSenderHistory->GetElementAt(index)));
}
```

The formal helper returns are deliberately `void`. Current IDA profiles show `wchar_t *` for `0x5a4ab0/0x5a4c30` and `int` for `0x5a4b60`, but every caller ignores EAX. On each empty-history path the copy helper leaves `Destination` in EAX, while on each nonempty path it leaves `_wcscpy_s`'s `errno_t`; those incompatible incidental values do not form a coherent authored pointer return. The updater similarly leaves the underlying `List::Append` result before setting the selector byte. Source-facing `void` preserves all consumed behavior, and T01-T03 deterministically converge the persisted IDA prototypes to those exact source signatures while preserving complete frames and bodies.

UID0000FQ formal CPP inserts `#include "../../social/SayInputPanes.h"` and `#include "../../social/Chatting.h"` after its existing local includes and before `[[CHILDREN]]`; its existing `PoolAllocator` include and unrelated text remain unchanged. UID0000FQ formal H adds `class SayToUserNameInputPane;` with the existing forward declarations, inserts the enum immediately before `class UserPane`, adds the ten declarations in the public method surface, and adds `friend class SayToUserNameInputPane;` in the private friend block. That one friendship is required by the exact Name constructor/event bodies' direct reads of the private selector and two recipient-history Lists; it exposes no field and changes no object bytes:

Forward-declaration/enum insertion before `class UserPane`:

```cpp
class SayToUserNameInputPane;

enum SayInputMode
{
    kSayInputModeDefault = 0,
    kSayInputModeShout = 1,
    kSayInputModeWhisper = 2,
    kSayInputModeGroup = 3,
    kSayInputModeClan = 4,
};
```

Public method insertion inside `class UserPane`:

```cpp
    void GetPreviousRecentRecipientHistory(
        short *historyIndex, wchar_t *recipient, size_t recipientCount);
    void UpdateRecentRecipientList(const wchar_t *recipient);
    void GetPreviousFallbackRecipientHistory(
        short *historyIndex, wchar_t *recipient, size_t recipientCount);
    void OpenInputPaneForCurrentSayMode();
    void OpenDefaultSayInputPane();
    void OpenSayToUserNameInputPane();
    void OpenSayToLastRecipientInputPane();
    void OpenSayToGroupMessageInputPane();
    void OpenSayToClanMessageInputPane();
    void OpenShoutInputPane();
```

Private friend insertion inside `class UserPane`:

```cpp
friend class SayToUserNameInputPane;
```

### Class topology replacements

UID000099 owns the central guard/includes above and is position 10. UID0000C6 retains its current H and `[[CHILDREN]]` CPP at position 20. UID0000C4 CPP becomes `[[CHILDREN]]`; its exact H at position 30 is:

```cpp
class SayToGroupMessageInputPane : public LineInputPane
{
public:
    explicit SayToGroupMessageInputPane(const wchar_t *groupName);

protected:
    virtual void OnSubmitInput();

private:
    wchar_t m_groupName[128];
};
```

UID0000C3 CPP remains `[[CHILDREN]]`; exact H replacement:

UID0000C5 retains its source-facing Clan declaration and `[[CHILDREN]]` CPP at position 40. UID0000C3 is position 50.

```cpp
class SayInputPane : public LineInputPane
{
public:
    SayInputPane();
    explicit SayInputPane(const wchar_t *initialText);

protected:
    virtual void OnSubmitInput();
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    short m_chatHistoryCursor;
};
```

UID000416 changes only its definition spelling to `void SayInputPane::OnSubmitInput()`; the existing body remains exact. UID0001MB CPP/H stay blank after non-emitting reclassification.

UID0000C7 is position 60; its CPP remains `[[CHILDREN]]`; exact H replacement:

```cpp
class SayToUserNameInputPane : public LineInputPane
{
public:
    SayToUserNameInputPane();

protected:
    virtual void OnSubmitInput();
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    short m_recentRecipientHistoryIndex;
    short m_fallbackRecipientHistoryIndex;
};
```

UID0001MD formal CPP replacement; H blank:

```cpp
SayToUserNameInputPane::SayToUserNameInputPane()
    : LineInputPane(g_useEpfAssets
          ? L"To "
          : g_pLanguageMan->GetLocalizedString(150)),
      m_recentRecipientHistoryIndex(-1),
      m_fallbackRecipientHistoryIndex(-1)
{
    wchar_t recipient[64] = L"";
    if (g_pUserPane->m_whisperHistorySource)
        g_pUserPane->GetPreviousRecentRecipientHistory(
            &m_recentRecipientHistoryIndex, recipient, _countof(recipient));
    else
        g_pUserPane->GetPreviousFallbackRecipientHistory(
            &m_fallbackRecipientHistoryIndex, recipient, _countof(recipient));

    if (recipient[0] != L'\0')
    {
        m_textEditPane->SetSelectionRange(0, 0x7fff);
        m_textEditPane->InsertTextRange(
            recipient, static_cast<short>(wcslen(recipient)), NULL, NULL);
        m_textEditPane->SetSelectionRange(0, 0x7fff);
    }
    m_deferSubmitUntilNextEvent = true;
}

[[CHILDREN]]

void SayToUserNameInputPane::OnSubmitInput()
{
    if (TextLength() <= 0)
        return;

    wchar_t recipient[256];
    CopyText(recipient, _countof(recipient) - 1);
    if (recipient[0] == L'\0')
        return;

    g_pUserPane->UpdateRecentRecipientList(recipient);
    if (g_useEpfAssets)
        new NewSayToUserMessageInputPane(recipient);
    else
        new SayToUserMessageInputPane(recipient);
}
```

UID0001ME formal CPP replacement; H blank:

```cpp
bool SayToUserNameInputPane::HandleKeyOrTextEvent(Event *event)
{
    const unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);
    const unsigned char modifiers = event->m_payload.m_key.m_modifiers;
    if (event->m_type != kEventKeyDown ||
        (key != kPaneKeyUp && key != kPaneKeyDown) ||
        (modifiers != 0 && modifiers != 4))
        return LineInputPane::HandleKeyOrTextEvent(event);

    List *history = modifiers == 4
        ? g_pUserPane->m_outgoingWhisperRecipientHistory
        : g_pUserPane->m_incomingWhisperSenderHistory;
    short *historyIndex = modifiers == 4
        ? &m_recentRecipientHistoryIndex
        : &m_fallbackRecipientHistoryIndex;
    wchar_t recipient[256] = L"";

    if (key == kPaneKeyUp)
    {
        if (modifiers == 4)
            g_pUserPane->GetPreviousRecentRecipientHistory(
                historyIndex, recipient, _countof(recipient));
        else
            g_pUserPane->GetPreviousFallbackRecipientHistory(
                historyIndex, recipient, _countof(recipient));
    }
    else if (history->GetCount() > 0)
    {
        const int index = (history->GetCount() + *historyIndex + 1) % history->GetCount();
        *historyIndex = static_cast<short>(index);
        wcscpy_s(recipient, _countof(recipient),
            static_cast<const wchar_t *>(history->GetElementAt(index)));
    }

    if (recipient[0] != L'\0')
    {
        m_textEditPane->SetSelectionRange(0, 0x7fff);
        m_textEditPane->InsertTextRange(
            recipient, static_cast<short>(wcslen(recipient)), NULL, NULL);
        m_textEditPane->SetSelectionRange(0, 0x7fff);
    }
    return true;
}
```

UID0000D5 is position 70. Its CPP becomes `[[CHILDREN]]`; exact H:

```cpp
class ShoutInputPane : public LineInputPane
{
public:
    ShoutInputPane();

protected:
    virtual void OnSubmitInput();
};
```

UID0002SA and UID0001MF retain current CPP and blank H. UID0003JM/JQ/JR/JS and all no-route/raw/compiler items keep both formal channels blank under their evidence-backed no-code dispositions. No third-party import applies.

## Final Recommendation

- Retain the now-implemented 51 ordinary documentation/formal-source claims without compressing this report. All accepted packet bodies and dated histories remain, while contradicted old source names/splits/generated receipts are explicitly superseded.
- Retain validator allocations UID `000579` for the opener support page, UID `00057A` for the history-helper page, and UID `00057B` for the no-route raw page; their exact ledger/checklist rows are checked only after physical validation.
- Apply manual coverage and IDA only as supervisor-owned actions. B002 must not check those rows.
- The accepted callback closed every generated defect and produced the exact command-28242 physical receipts in Sections 31-32; those receipts, not by-* edits alone, support C0000N9-051.
- The source-quality questions raised by the failed artifact are now resolved in report text: Section 21 has exact current type prestates, four minimal incomplete declarations, 19 separate parser-safe source-facing types, complete frame protections, current response allowlists, and valid validator syntax. Original spelling uncertainty remains represented as confidence/score rather than an implementation blocker; fresh Gate 1 still controls acceptance.
- Section 21 is intentionally entity-only. It supplies no working/TX path, transaction session, runtime-attestation schedule, persistence sequence, or promotion/rollback procedure; C0000N9-075 assigns those external prerequisites to the supervisor without weakening C0000N9-056 through C0000N9-074 and C0000N9-076 through C0000N9-098.

## Recommended Target Doc Changes

- Target: `by-file/SayInputPanes.md`.
- Implemented: literal `RECONSTRUCTABLE:TRUE`, `95/95`, retained path/owner, and exhaustive Sections 14-19 inventory with exact owner/emitter/source order, direct prerequisites, no-route exclusions, and current command-28242 receipt.
- Implemented: corrected default opener and Name/Say names throughout; commands 28163 and 28114 remain only as superseded history.
- Implemented: removed the executable Wave3 fence while retaining a dated inert explanation, exact formal CPP/H topology, acceptance counts, current hashes, and validator receipts. Unrelated history remains intact.

## Recommended Support Doc Changes

- Implemented every destination C0000N9-008 through C0000N9-045 at report-level detail without shortening accepted method bodies.
- Allocated UID `000579` contains the exact six-function opener inventory/definitions, including source-bearing zero-current-caller `0x5a54b0`; allocated UID `00057A` contains the exact three history-helper definitions; both route through UID0000FQ and generated UserPane CPP/H now has the required includes, enum, declarations, definitions, and history notes.
- Allocated UID `00057B` records exact `[0x5b3bc0,0x5b3ca5)` bytes/packet/no-route evidence with owner NONE, reconstructable false, and blank emitter/CPP/H.
- Current by-memory summaries for 1LZ, 1MD, 1ME, 2SA, 1MF, 2S8, literal pages, and new pages contain exact callback state. Changed pages include callback chronology, and historical contradictions remain explicitly superseded.

## Score And Metadata Recommendation

- UID0000N9: ordinary metadata is now `95/95`, reconstructable true, `social/`, FILE. Every live function, declaration, include, source position, dependency, raw exclusion, and generated acceptance condition is implemented and physically verified. The absent original source/PDB and inferred helper spellings cap both values at 95. Manual coverage and the 42-entity Gate 2B handoff remain independent unchecked supervisor work and do not make the ordinary score wording provisional.
- UID0000C4: `88/91 -> 93/94`; exact methods already exist, and class H/CPP topology/destructor disposition becomes complete.
- UID0000C7: `87/91 -> 94/95`; all three methods, Event signature, fields, modern/legacy branch, and formal source become complete.
- UID0001MD: `88/91 -> 93/94`; aggregate now carries constructor/submit and child route.
- UID0001ME: `88/91 -> 94/95`; stale type/name/helper surface is fully corrected.
- UID0000D5: `85/86 -> 93/94`; class declaration plus both exact child bodies eliminate blank emission.
- UID0001LZ/0002SA/0001MF retain `90/92`, `88/91`, `90/91`; formal bodies are already sound, with parent/topology summaries refreshed.
- Prompt pages become reconstructable false with blank emitters; scores may remain because evidence quality is unchanged. UID0001MB becomes reconstructable false/non-emitting with current `89/93` retained as index quality.
- Score-improvement attempts: original file symbols unavailable; all caller/vtable/adjacency/formal/generated/type/frame routes exhausted. The remaining uncertainty is spelling/history only and does not block the exact source or type handoff.

## Open Questions With Attempted Resolution

- Was the original unit split into Whisper/Group/Clan files? Checked caller families, address layout, existing routes, shared H, generated failures, and matching reports. Best resolution is one SayInputPanes unit; no original symbol proves a split.
- Is `0x5a54b0` a source-authored last-recipient opener despite zero current callers? Checked exact body, complete `__thiscall` profile, private UserPane fields, outgoing calls, adjacency, and sibling opener family. Yes: emit descriptive `UserPane::OpenSayToLastRecipientInputPane()` and retain zero-current-caller status as liveness evidence rather than treating the complete modeled body as absent source.
- Are raw packet bodies helpers? Checked functions/xrefs/pointers/vtables and live submit bodies. No; preserve as no-route compiler/source artifacts without emission.
- What are the Name virtual method names? Base class and exact vtable slots resolve `OnSubmitInput` and `HandleKeyOrTextEvent(Event *)`.
- Which history class owns the three helpers? Exact fields and all callers resolve UserPane ownership.
- Should strings emit? No independent storage source identity is needed; lexical literals preserve exact values.
- What is the exact current names-registry present-row schema? The bounded current-schema evidence resolves an outer `kind:"names"` envelope and one nested row with exactly `kind:"name"`, numeric-target `addr`, and exact `name`; zero state is exactly `data:[]`/`total:0`. No extra member, row, continuation, or totals-only substitute is accepted.
- Which types must be declared before source-facing prototypes can be applied? Fresh `type_query`/`type_inspect` resolves existing complete `UserPane`, `Event`, and `LineInputPane`, existing incomplete `SayInputPane`, built-in `size_t`/`wchar_t`, and exactly four missing pane classes. TD01-TD04 therefore declare only those four incomplete structs; no layout is invented.
- Are all 19 source-facing function types deterministic? Yes. Fresh persisted types, direct decompilation, complete 148-row frames, caller ECX/return use, vtable slots, and the formal method declarations resolve every return, convention, receiver, argument order/type/name, and exact protected frame delta in T01-T19/F01-F19.
- Who owns transaction and persistence mechanics? The supervisor, outside this report. The report resolves only the entity prestates, actions, permitted deltas, protections, response schemas, dependencies, and expected readbacks; external prerequisite failure closes Gate 2B without inviting a report-authored fallback.
- No unresolved question affects owner, emitter, range, current ordinary score, formal source, IDA feasibility, or validator syntax. Fresh supervisor Gate 2A remains required and is not preclaimed.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Inspected manual rows: `by-file/-coverage-report.md:238`; `by-class/-coverage-report.md:463,466,499`. By-memory rows are not manually edited; update their source Item Summary/Nested metadata and let generated coverage refresh.

- Replace by-file line 238 with:

`- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) : reconstructable : 95% : very-strong : Complete shared social input-pane compilation unit with seven class declarations and 18 live class-method definitions; exact UserPane-owned dispatcher/opener/history prerequisites; deterministic source order; compiler/raw/string exclusions; and coherent SayInputPanes.cpp/.h acceptance inventory.`

- Replace by-class line 463 with:

`- [UID:0000C4][SayToGroupMessageInputPane](by-class/SayToGroupMessageInputPane.md) : reconstructable : 93% : very-strong : Group target-message pane with complete SayInputPanes.h declaration, child-only CPP topology, exact constructor/submit bodies, group-name field, Group prompt, opcode 0x19 packet behavior, vtable route, and compiler-only destructor disposition.`

- Replace by-class line 466 with:

`- [UID:0000C7][SayToUserNameInputPane](by-class/SayToUserNameInputPane.md) : reconstructable : 94% : very-strong : Recipient-name pane with complete constructor, OnSubmitInput, and Event-based HandleKeyOrTextEvent source; exact recent/fallback history cursors and UserPane helpers; modern/legacy follow-up branches; shared SayInputPanes.h declaration; and compiler-only destructor disposition.`

- Replace by-class line 499 with:

`- [UID:0000D5][ShoutInputPane](by-class/ShoutInputPane.md) : reconstructable : 93% : very-strong : Shout input pane with complete SayInputPanes.h declaration, raw constructor and submit child definitions, exact ! prompt, opcode 0x0e subtype 1 send gate/path, vtable route, shared-module placement, and compiler-only destructor disposition.`

- No manual tracker row was written for allocated by-memory pages; their UIDs `000579`, `00057A`, and `00057B` and generated rows derive from source page metadata. B002 did not apply this section because manual coverage is supervisor-owned by project rule.

## Follow-Up Actions

- Supervisor: perform fresh exact-artifact Gate 1 reconciliation and claim-by-claim Gate 2A for checked C0000N9-001 through C0000N9-051 against the current ordinary docs and command-28242 generated receipts.
- Supervisor after Gate 2A: apply C0000N9-052 through C0000N9-055, then independently evaluate C0000N9-056 through C0000N9-098 against the exact Section 21 entity rows. The supervisor owns every external runtime, persistence, process, audit, and lifecycle prerequisite; any missing or mismatched prerequisite fails Gate 2B.
- No A-agent action or additional B002 research is required by current evidence.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: strong; the 95 cap explicitly accounts for inferred spellings and absent original source/PDB.
- Names-registry schema confidence: certain for this handoff; the dated current-schema evidence contains outer `kind:"names"` and the mandatory sole nested `kind:"name"`/`addr`/`name` row, and Section 21 now rejects every payload that omits that discriminator or adds a member, row, continuation, or contradictory total.
- Type-handoff confidence: very strong; all 19 functions have fresh persisted prototypes, direct decompilation, exact complete frames, formal signatures, and independent named `set_type` actions. The four declarations are incomplete by design and add no invented layout.
- Remaining uncertainty: historical original file split and exact helper spellings only. Neither changes observed behavior, formal completeness, or the deterministic handoff.
- Self-audit: B002 changed only the 24 ordinary by-* destinations listed in Section 32 plus this report; generated output changed only through scoped validator application. No coverage, tracker, audit, lifecycle, goal, direct-generated, or IDA mutation was performed. No executable script fence, conflict marker, registry directive, or generic investigation deferral is present.
- Terminal mechanical contract: 33 literal ordered H2 sections; 98 unique ordered ledger rows and 98 exact checklist twins; 51 checked B002 ordinary rows and 47 unchecked supervisor rows (four coverage plus 43 Gate 2B); 42 entity actions (four declarations, 19 pure renames, 19 separate types) plus 19 per-rename dry-response contracts; every registry zero/present payload and every declaration/type response obeys its exact allowlist; one terminal marker; 14 paired C++ fences and zero executable-language fences; zero named working/TX paths, symbolic transaction sessions, report-owned attestations, or report-owned persistence/promotion program; zero prohibited coordination directives or conflict markers; terminal LF; report lease released before return and zero B002 leases at return.

## Validator Results

- Scoped callback validators ran from `source-3/project-documentation` with exact form `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`; every changed ordinary page returned `ok:1`. Command groups were `000000028194-000000028200` (seven class emitters), `000000028204-000000028206` (three new-page UID allocations), `000000028209`, `000000028211-000000028214` (new/UserPane routes), `000000028218-000000028229` (target/support), and `000000028231-000000028241` (active-prose reconciliation). The target validator also reported the goal-required by-file `RECONSTRUCTABLE:TRUE` line as `autogen_metadata_unexpected`; this did not make its result non-ok and the literal line is required by accepted C0000N9-001.
- Final foreground command `000000028242` at `2026-08-25T16:21:25-04:00` was exact `python .\tools\validator.py --mode file --file "by-class/UserPane.md" --apply --queue-timeout 240 --wait-generated` and returned `ok:1` after generated completion.
- Physical final readback passed: SayInputPanes H has one pragma/include set and exactly seven class declarations, with no UserPane enum/opener surface; CPP has exactly 18 class-method definitions, no free dispatcher/opener, nested qualified definition, empty marker, or stale method/type name. UserPane H has one mode enum, ten declarations, and one bounded `SayToUserNameInputPane` friendship; UserPane CPP has two direct social includes and exactly ten corresponding member definitions, including all six openers and the zero-current-caller last-recipient body.
- Generated identities are current command-28242 receipts in Sections 1 and 32. Commands 28163 and 28114 are historical only. C0000N9-050/051 were checked only after the validator and physical-readback conditions passed.

## Changed Files

- Callback changed exactly these ordinary docs; values are current post-validation SHA256 receipts:

| Path | Bytes | SHA256 |
| --- | ---: | --- |
| `by-class/NewSayToUserMessageInputPane.md` | 16,582 | `F6FABAF90214F5BD4B69C4473A501364D2688AB59948132B4A56EA514E968E73` |
| `by-class/SayToUserMessageInputPane.md` | 13,350 | `ED50B320F5A580D2080ACFE758253AEDA953DA5566F67ADA27A71442BA9731FB` |
| `by-class/SayToGroupMessageInputPane.md` | 12,995 | `51B25441BD047C84C6CA67BD889BE8C182CFF3ED08D724C62595635792269000` |
| `by-class/SayToPlanMessageInputPane.md` | 15,594 | `BE735AC0CEF3B61D4A190951CC5BBA30CE61C744F39BC6CC867BE4DF722D7A96` |
| `by-class/SayInputPane.md` | 24,811 | `4CE0F68D3EDC2D8AF6E7DA628F6B3EE961A287863E3E416B51D5446394B0CF3F` |
| `by-class/SayToUserNameInputPane.md` | 15,841 | `A3095B941D62FD84729A0BCCFD2421995A06352D8B8E5868383C097FD13D1B70` |
| `by-class/ShoutInputPane.md` | 9,533 | `66E9B71FF77265660CE1CB25E33DE1CD60981263029FFF93AC338A335244928A` |
| `by-memory/0x005a53c0-0x005a5791.UserPaneSayInputPaneOpeners.md` | 6,204 | `F79A4D553FDB45465718BF0CDCA2865C11EDA852888665DE93DA7CE8A7B18CDB` |
| `by-memory/0x005a4ab0-0x005a4c8b.UserPaneWhisperRecipientHistoryHelpers.md` | 7,119 | `E4E9729FA47A1980A7D38491B4BCA91D0807F032AA9BF8D786C26E5D76A9DE08` |
| `by-memory/0x005b3bc0-0x005b3ca5.ChatPacketRawSenderNoRouteRawB.md` | 4,261 | `29FC1C6E1D1C32FBA97A5DCEBD70371F2AA08E503027F157164A6DF1D0C5C8EE` |
| `by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md` | 13,894 | `429A3AA3B1FF3F108395287D7DF04DFC44C2C771A89A6C03F2122400025CEB26` |
| `by-class/UserPane.md` | 121,626 | `96D7A3B1E1DF4F04FB068A4017CE1BE14B3D984EF80D523094369A52F6F9FE94` |
| `by-file/SayInputPanes.md` | 63,484 | `630D3C29355F1D163447226DCB82FED54F996D29736D42B37A578D30CC77B2E6` |
| `by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md` | 26,147 | `963718A82EF2FD31FDA0B4D0F8C58256D87F1579E1D1D8B8B8B1CABCD5AD74AC` |
| `by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md` | 20,628 | `D953B8EE58700344EA8C313BE45BE27BD95E7A2B30AD22D84C0960E0CF121DE4` |
| `by-memory/0x005b34d0-0x005b37ea.SayInputPane.md` | 39,590 | `0C57132EF63D7E86C5452EC984C92006099729D4AA15DEF697E13E666D28D281` |
| `by-memory/0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat.md` | 19,589 | `2D31E3371B543A5D03C6BD8842FBF69F37BA2AE98B4DFF1BDC96842175A7E7F1` |
| `by-memory/0x005b3cb0-0x005b4219.SayToUserNameInputPane.md` | 17,759 | `9A600AE302859E3AAA3FA0C49F970AAA0217715334325E9AAC00903027533151` |
| `by-memory/0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation.md` | 13,995 | `682A2C1988C60AE4CA47EEF328077C74A0F91DA20AAC8E1F68939226E9FC7815` |
| `by-memory/0x006309d0-0x006309dc.SayModeGroupClanPrefixFragments.md` | 5,134 | `1A6F7DFDA6F41CC08FD163E8350CB3A40079E498781C3CE75B04688EB1B8CE23` |
| `by-memory/0x00630a18-0x00630a44.DirectWhisperPromptFragments.md` | 5,798 | `2920F34DFBB5B8B2FEAB423C52B637778875E33CE36DAFC4A0BAFBC8CECE77A5` |
| `by-memory/0x00630a44-0x00630a6c.GroupClanPromptFragments.md` | 5,051 | `A01837144042067A1BAF0E78EB7EDC8260B0F06CB99F079CA3F98FDF16A4B794` |
| `by-memory/0x00630a6c-0x00630a78.ShoutPromptString.md` | 5,709 | `C6B4DE4F4993B6B721A66984548478F7316BF48E8C1FD932739269D53A473B8B` |
| `by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md` | 23,163 | `4F0753DDF546B6B35074109E3E20C9A56DE6C5D9E6EAA1E5D56951C3D2ACBB7B` |

- Current generated receipts, refreshed only by command `000000028242`: `auto-generated/NexusTK/social/SayInputPanes.cpp` SHA256 `1E9F0CC50AECFADEFD3138EAC0D7A3798F01543C6F9C990857428A50A6EC7E71`, 17,726 bytes, last-write UTC `2026-08-25T20:21:59.3102671Z`; `.h` SHA256 `13975F5D67D3DDE1A722FEA50557BFA9472FB3081A1747D7D07703D66223363E`, 2,598 bytes, `2026-08-25T20:21:59.3512714Z`; `auto-generated/NexusTK/ui/panels/UserPane.cpp` SHA256 `85623B44DCE1D21E41D57C3C63E9A92D59B89DDBADDF0383A6D7D8271BDC466A`, 92,561 bytes, `2026-08-25T20:22:03.3350767Z`; `.h` SHA256 `3D0891487EF3E302BF430E8178A3CD5A9A2D6610B62B1D89975F94E74FDAA5D6`, 13,362 bytes, `2026-08-25T20:22:03.3720799Z`.
- Renamed ordinary files: none. Generated files were not edited directly. No coverage, tracker, audit, registry, goal, lifecycle, or IDA file changed by B002.
- Report lifecycle boundary: execution/archive truth is supervisor-owned and authoritative only from the current report path plus validator-owned status/history metadata. This body records accepted callback implementation and validation evidence but does not preclaim Gate 2A, coverage, Gate 2B, execution, or archive state.

## Implementation Tracking Checklist

Allocation is exact: 98 unique ordered claims, 51 checked and 47 unchecked. C0000N9-001 through C0000N9-051 are B002-implemented and verified ordinary callback work; C0000N9-052 through C0000N9-055 remain supervisor-owned manual coverage; C0000N9-056 through C0000N9-098 remain supervisor-owned Gate 2B. Every checklist row is an exact full-row twin of the ledger after removing only the checkbox column.

| Checkbox | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C0000N9-001 | UID0000N9 | Retain `NexusTK/social/SayInputPanes.cpp/.h`, add `RECONSTRUCTABLE:TRUE`, and keep owner FILE. | very strong | complete source-family inventory | `by-file/SayInputPanes.md` metadata/Status | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-002 | UID0000N9 | Replace sampled contents with the exhaustive included/excluded inventory in this report. | very strong | 20+44 modeled function sweep plus raw/data/type inventory | target Proposed Contents/Boundary Notes | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-003 | UID0000N9 | Record current command-28242 SayInputPanes/UserPane CPP/H hashes and exact clean generated acceptance state. | certain | physical generated reread | target Current Generated State | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-004 | UID0000N9 | Centralize guard/include and seven class declarations in SayInputPanes H; remove free opener/enum ownership. | very strong | calling convention, direct prerequisites, malformed current H | target Shared Header Contract | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-005 | UID0000N9 | Emit includes, 18 class-method definitions, and no standalone literal data at namespace scope in CPP. | very strong | function/source inventory | target Source Topology | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-006 | UID0000N9 | Apply emitter positions 10/20/30/40/50/60/70 to 099/C6/C4/C5/C3/C7/D5. | strong | deterministic class/header order | target Source Order | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-007 | UID0000N9 | Remove the executable Wave3 fence and preserve its content only as rejected historical migration prose. | certain | target lines 129-142 and active workflow ban | target Migration Notes | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-008 | UID0001KO | Keep mixed helper range owner NONE, reconstructable false, blank emitter/formal source; update exact 20-function inventory. | very strong | complete range query | `by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md` | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-009 | UID0002RX | Reroute dispatcher owner/emitter to UID0000FQ, emit `UserPane::OpenInputPaneForCurrentSayMode` in UserPane CPP, and keep formal H blank. | very strong | `__thiscall`, ECX caller setup, private field access | exact dispatcher page | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-010 | UID000579 | Create exact `[0x005a53c0,0x005a5791)` opener support page; emit six UserPane member openers including last-recipient method; owner/emitter UID0000FQ. | very strong | member calling convention/profiles/callers/allocations | `by-memory/0x005a53c0-0x005a5791.UserPaneSayInputPaneOpeners.md` | B002 callback create/incorporate | implemented-verified |
| [x] | C0000N9-011 | UID00057A | Create exact `[0x005a4ab0,0x005a4c8b)` UserPane history-helper page with three definitions; owner/emitter UID0000FQ. | very strong | exact list fields and decompilation | `by-memory/0x005a4ab0-0x005a4c8b.UserPaneWhisperRecipientHistoryHelpers.md` | B002 callback create/incorporate | implemented-verified |
| [x] | C0000N9-012 | UID0000FQ | Add enum, ten dispatcher/opener/history declarations, direct social CPP includes, and bounded SayToUserNameInputPane friendship with exact ownership/history notes. | very strong | member calling convention, ranges, private class fields, and Name direct accesses | `by-class/UserPane.md` formal CPP/H/Direct-Message History | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-013 | UID0000C6 | Preserve legacy direct-message class declaration/children topology; position 20; no explicit destructor. | very strong | current formal H and vtable wrappers | `by-class/SayToUserMessageInputPane.md` | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-014 | UID000401 | Preserve current constructor/submit CPP unchanged and blank H. | very strong | current formal source/current IDA names | exact legacy method page | B002 callback verify-no-change | implemented-verified |
| [x] | C0000N9-015 | UID000402 | Preserve raw helper A ownerless, reconstructable false, non-emitting. | very strong | no function/xref/pointer route | exact no-route page | B002 callback verify-no-change | implemented-verified |
| [x] | C0000N9-016 | UID000099 | Keep central CPP/H preambles on this earliest Say emitter, keep `[[CHILDREN]]`, preserve complete H declaration, and set position 10. | very strong | generated nested topology and corrected UID2RX route | `by-class/NewSayToUserMessageInputPane.md` | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-017 | UID000403 | Preserve current three modern method definitions and blank H. | very strong | accepted formal source/live methods | exact modern method page | B002 callback verify-no-change | implemented-verified |
| [x] | C0000N9-018 | UID000404 | Preserve raw helper B ownerless, reconstructable false, non-emitting. | very strong | no function/xref/call route | exact no-route page | B002 callback verify-no-change | implemented-verified |
| [x] | C0000N9-019 | UID0000C4 | Move Group declaration to H, set CPP to `[[CHILDREN]]`, omit destructor, position 30, score 93/94. | very strong | current malformed nested emission and wrapper proof | `by-class/SayToGroupMessageInputPane.md` | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-020 | UID0001LZ | Preserve Group constructor/submit CPP, blank H, owner/emitter C4; update source/topology notes to shared unit. | very strong | live methods and formal source | exact Group method page | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-021 | UID000405 | Preserve raw helper C ownerless, reconstructable false, non-emitting. | very strong | no function/xref/call route | exact no-route page | B002 callback verify-no-change | implemented-verified |
| [x] | C0000N9-022 | UID0000C5 | Preserve source-facing Clan declaration/children route, stable Plan filename as history only, position 40. | very strong | mode/literal/method evidence | `by-class/SayToPlanMessageInputPane.md` | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-023 | UID000406 | Preserve current Clan constructor/submit CPP and blank H. | very strong | accepted formal source/live methods | exact Clan method page | B002 callback verify-no-change | implemented-verified |
| [x] | C0000N9-024 | UID0000C3 | Change H virtual to `OnSubmitInput`, omit explicit destructor, preserve CPP children, position 50. | very strong | base submit slot/API and compiler wrapper | `by-class/SayInputPane.md` | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-025 | UID0002S7 | Preserve exact default Say constructor CPP and blank H. | very strong | raw body/vtables/inline equivalents | exact raw constructor page | B002 callback verify-no-change | implemented-verified |
| [x] | C0000N9-026 | UID000414 | Preserve initial-text constructor CPP and blank H. | very strong | live method/formal source | exact constructor child | B002 callback verify-no-change | implemented-verified |
| [x] | C0000N9-027 | UID000415 | Preserve Event-based history handler CPP and blank H. | very strong | live type/vtable/formal source | exact event child | B002 callback verify-no-change | implemented-verified |
| [x] | C0000N9-028 | UID000416 | Rename only formal `OnSubmitChat` to `OnSubmitInput`; preserve body/protocol; blank H. | very strong | primary submit slot/base API | exact submit child | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-029 | UID0001MB | Make aggregate reconstructable false with blank emitter/formal source; retain exact-child index and evidence. | very strong | all four method bodies have exact children | Say aggregate page metadata/summary | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-030 | UID0000C7 | Replace stale InputEvent/method/destructor H with Event-based constructor/submit/event declaration; position 60. | very strong | live types/vtable slots | `by-class/SayToUserNameInputPane.md` | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-031 | UID0001MD | Emit exact Name constructor and submit around `[[CHILDREN]]`; preserve owner/emitter C7 and refresh summary. | very strong | complete class cluster decompilation | Name aggregate formal CPP | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-032 | UID0001ME | Replace stale InputEvent/history CPP with exact `HandleKeyOrTextEvent(Event *)`; blank H. | very strong | live decompile/type/offset correction | exact Name event child | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-033 | UID0000D5 | Add `[[CHILDREN]]` CPP and complete Shout H declaration without destructor; position 70; score 93/94. | very strong | raw constructor and submit child | `by-class/ShoutInputPane.md` | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-034 | UID0002SA | Preserve exact raw Shout constructor CPP and blank H. | very strong | raw bytes/vtables/prompt | exact raw constructor page | B002 callback verify-no-change | implemented-verified |
| [x] | C0000N9-035 | UID0001MF | Preserve exact Shout submit CPP and blank H. | very strong | live submit/vtable/protocol | exact submit page | B002 callback verify-no-change | implemented-verified |
| [x] | C0000N9-036 | UID0003JM | Set group/clan prefix fragment page reconstructable false, emitter blank, CPP/H blank; preserve literal/xrefs. | very strong | lexical use/no independent storage need | exact string page | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-037 | UID0003JQ | Set direct-whisper fragment page reconstructable false, emitter blank, CPP/H blank; preserve literal/xrefs. | very strong | lexical use/no independent storage need | exact string page | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-038 | UID0003JR | Set group/clan prompt page reconstructable false, emitter blank, CPP/H blank; preserve literal/xrefs. | very strong | lexical use/no independent storage need | exact string page | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-039 | UID0003JS | Set Shout prompt page reconstructable false, emitter blank, CPP/H blank; preserve literal/xrefs. | very strong | lexical use/no independent storage need | exact string page | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-040 | UID0002S8 | Preserve raw chat sender owner NONE/reconstructable false/non-emitting and replace stale liveness wording. | very strong | repeated no-route checks and inline live bodies | exact raw sender page | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-041 | UID00057B | Create non-emitting page for `[0x005b3bc0,0x005b3ca5)` opcode-0x0e/subtype-0 packet island; owner NONE. | strong | raw body, zero xrefs, padding | `by-memory/0x005b3bc0-0x005b3ca5.ChatPacketRawSenderNoRouteRawB.md` | B002 callback create/incorporate | implemented-verified |
| [x] | C0000N9-042 | support set | Preserve nine exact destructor adjustor/scalar wrappers as compiler-only with no formal source. | very strong | shared vtable wrapper topology | target/support compiler inventory | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-043 | support set | Preserve seven three-view vtable groups and RTTI as compiler output, not source emitters. | certain | exact table pointers/vptr stores | target/support data inventory | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-044 | UID0000I5/UID0000JS/CommandInputPanes | Preserve ChatInputPane, command/emotion panes, and GroupInputPane exclusions. | very strong | modeled ranges and semantic owners | target Rejected Candidates/cross-links | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-045 | UID0000N9 | Reconcile all support links, direct prerequisites, literal pools, wrappers, gaps, and rejected candidates in target history. | very strong | exhaustive destination sweep | target Cross-References/Changes | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-046 | UID0000N9 | Raise file score 89/90 to 95/95 after formal/source/inventory closure. | strong | blocker audit in Section 26 | target metadata/Score Rationale | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-047 | UID0000C4 | Raise Group class 88/91 to 93/94 after H/CPP topology repair. | strong | complete method/header evidence | Group class metadata/Score | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-048 | UID0000C7/UID0001MD/UID0001ME | Raise Name class/aggregate/event to 94/95, 93/94, 94/95 after exact source closure. | strong | all live methods/types/routes resolved | three Name pages metadata/Score | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-049 | UID0000D5 | Raise Shout class 85/86 to 93/94 after complete H/CPP route. | strong | exact constructor/submit/wrappers | Shout class metadata/Score | B002 callback incorporate | implemented-verified |
| [x] | C0000N9-050 | changed ordinary docs | From project root run exact scoped `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240` per changed destination; add `--wait-generated` to the final relevant validation. | certain | current validator syntax/workflow | every changed by-* destination | B002 callback validate | implemented-verified |
| [x] | C0000N9-051 | UID0000N9/UID0000P1 | Physically verify refreshed SayInputPanes 18-definition CPP/H and UserPane ten-method CPP/H deltas against exact acceptance inventories and record receipts. | certain | current physical generated acceptance inventory | report Validator Results/Changed Files | B002 callback verify | implemented-verified |
| [ ] | C0000N9-052 | UID0000N9 | Replace manual by-file coverage row with exact 95% whole-file closure text. | certain | current row line 238 | `by-file/-coverage-report.md` line 238 | supervisor coverage | proposed-unapplied |
| [ ] | C0000N9-053 | UID0000C4 | Replace manual class coverage row with exact 93% Group topology text. | certain | current row line 463 | `by-class/-coverage-report.md` line 463 | supervisor coverage | proposed-unapplied |
| [ ] | C0000N9-054 | UID0000C7 | Replace manual class coverage row with exact 94% Name source text. | certain | current row line 466 | `by-class/-coverage-report.md` line 466 | supervisor coverage | proposed-unapplied |
| [ ] | C0000N9-055 | UID0000D5 | Replace manual class coverage row with exact 93% Shout source text. | certain | current row line 499 | `by-class/-coverage-report.md` line 499 | supervisor coverage | proposed-unapplied |
| [ ] | C0000N9-056 | UID0000FQ | Rename `sub_5A4AB0` to `UserPane__GetPreviousRecentRecipientHistory` under A01 and exact Section 21 zero/present registry-payload contracts. | strong | exact list/decompile/callers | IDA `0x005a4ab0` | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-057 | UID0000FQ | Rename `sub_5A4B60` to `UserPane__UpdateRecentRecipientList` under A02 and exact Section 21 zero/present registry-payload contracts. | strong | dedupe/cap/select behavior | IDA `0x005a4b60` | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-058 | UID0000FQ | Rename `sub_5A4C30` to `UserPane__GetPreviousFallbackRecipientHistory` under A03 and exact Section 21 zero/present registry-payload contracts. | strong | exact list/decompile/callers | IDA `0x005a4c30` | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-059 | UID0000FQ | Rename `OpenInputPaneForCurrentSayMode` to `UserPane__OpenInputPaneForCurrentSayMode` under A04 and exact Section 21 zero/present registry-payload contracts. | very strong | ECX caller setup/private field use | IDA `0x005a5110` | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-060 | UID0000FQ | Rename `sub_5A53C0` to `UserPane__OpenDefaultSayInputPane` under A05 and exact Section 21 zero/present registry-payload contracts. | very strong | allocation/mode/callers | IDA `0x005a53c0` | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-061 | UID0000FQ | Rename `OpenSayToUserNameInputPane` to `UserPane__OpenSayToUserNameInputPane` under A06 and exact Section 21 zero/present registry-payload contracts. | very strong | ECX caller setup/allocation | IDA `0x005a5450` | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-062 | UID0000FQ | Rename displayed `sub_5A54B0` to `UserPane__OpenSayToLastRecipientInputPane` under A07 and exact Section 21 zero/present registry-payload contracts. | strong | member fields/behavior and zero-current-caller evidence | IDA `0x005a54b0` | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-063 | UID0000FQ | Rename `OpenSayToGroupMessageInputPane` to `UserPane__OpenSayToGroupMessageInputPane` under A08 and exact Section 21 zero/present registry-payload contracts. | very strong | ECX caller setup/group construction | IDA `0x005a5570` | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-064 | UID0000FQ | Rename `OpenSayToClanMessageInputPane` to `UserPane__OpenSayToClanMessageInputPane` under A09 and exact Section 21 zero/present registry-payload contracts. | very strong | ECX caller setup/clan construction | IDA `0x005a5640` | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-065 | UID0000FQ | Rename `OpenShoutInputPane` to `UserPane__OpenShoutInputPane` under A10 and exact Section 21 zero/present registry-payload contracts. | very strong | explicit `__thiscall`, mode write, callers | IDA `0x005a5710` | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-066 | UID0000C4 | Rename `sub_5B1EC0` to `SayToGroupMessageInputPane__Constructor` under A11 and exact Section 21 zero/present registry-payload contracts. | very strong | ctor/vtable/prompt | IDA `0x005b1ec0` | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-067 | UID0000C4 | Rename `sub_5B1F80` to `SayToGroupMessageInputPane__OnSubmitInput` under A12 and exact Section 21 zero/present registry-payload contracts. | very strong | submit vtable/protocol | IDA `0x005b1f80` | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-068 | UID0000C5 | Rename `sub_5B22D0` to `SayToClanMessageInputPane__Constructor` under A13 and exact Section 21 zero/present registry-payload contracts. | very strong | ctor/vtable/prompt | IDA `0x005b22d0` | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-069 | UID0000C5 | Rename `sub_5B2390` to `SayToClanMessageInputPane__OnSubmitInput` under A14 and exact Section 21 zero/present registry-payload contracts. | very strong | submit vtable/protocol | IDA `0x005b2390` | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-070 | UID0000C3 | Rename `sub_5B3670` to `SayInputPane__OnSubmitInput` under A15 and exact Section 21 zero/present registry-payload contracts. | very strong | base submit slot/protocol | IDA `0x005b3670` | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-071 | UID0000C7 | Rename `sub_5B3CB0` to `SayToUserNameInputPane__Constructor` under A16 and exact Section 21 zero/present registry-payload contracts. | very strong | ctor/vtables/callers | IDA `0x005b3cb0` | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-072 | UID0000C7 | Rename `sub_5B3E80` to `SayToUserNameInputPane__HandleKeyOrTextEvent` under A17 and exact Section 21 zero/present registry-payload contracts. | very strong | Event type/secondary vtable | IDA `0x005b3e80` | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-073 | UID0000C7 | Rename `sub_5B4080` to `SayToUserNameInputPane__OnSubmitInput` under A18 and exact Section 21 zero/present registry-payload contracts. | very strong | primary submit vtable/behavior | IDA `0x005b4080` | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-074 | UID0000D5 | Rename `sub_5B4260` to `ShoutInputPane__OnSubmitInput` under A19 and exact Section 21 zero/present registry-payload contracts. | very strong | submit vtable/protocol | IDA `0x005b4260` | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-075 | UID0000N9/UID0000FQ | Independently establish all supervisor-owned Gate 2B runtime, persistence, process, audit, and lifecycle prerequisites outside this report; any missing or mismatched external prerequisite fails Gate 2B without weakening the 42 entity contracts. | certain | Section 21 role boundary and entity manifests | supervisor Gate2B external controls | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-076 | UID0000C4 | Declare only incomplete `struct SayToGroupMessageInputPane;` under TD01 and preserve every existing prerequisite type/function state. | certain | current type catalog plus formal Group class | IDA local type library / Section 21 TD01 | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-077 | UID0000C5 | Declare only incomplete `struct SayToClanMessageInputPane;` under TD02 and preserve every cumulative type/function state. | certain | current type catalog plus formal Clan class | IDA local type library / Section 21 TD02 | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-078 | UID0000C7 | Declare only incomplete `struct SayToUserNameInputPane;` under TD03 and preserve every cumulative type/function state. | certain | current type catalog plus formal Name class | IDA local type library / Section 21 TD03 | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-079 | UID0000D5 | Declare only incomplete `struct ShoutInputPane;` under TD04 and preserve every cumulative type/function state. | certain | current type catalog plus formal Shout class | IDA local type library / Section 21 TD04 | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-080 | UID0000FQ | Apply T01 exact source-facing `void __thiscall UserPane__GetPreviousRecentRecipientHistory(UserPane *, short *, wchar_t *, size_t)` type and exact F01 frame delta after A01. | very strong | ignored incidental return, caller/formal/frame evidence | IDA `0x005a4ab0` / Section 21 T01/F01 | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-081 | UID0000FQ | Apply T02 exact source-facing `void __thiscall UserPane__UpdateRecentRecipientList(UserPane *, const wchar_t *)` type and exact F02 frame delta after A02. | very strong | ignored incidental return, caller/formal/frame evidence | IDA `0x005a4b60` / Section 21 T02/F02 | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-082 | UID0000FQ | Apply T03 exact source-facing fallback-history `void __thiscall` type and exact F03 frame delta after A03. | very strong | ignored incidental return, caller/formal/frame evidence | IDA `0x005a4c30` / Section 21 T03/F03 | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-083 | UID0000FQ | Apply T04 exact `void __thiscall UserPane__OpenInputPaneForCurrentSayMode(UserPane *)` type with F04 protected frame after A04. | very strong | ECX member call, no consumed return, formal member | IDA `0x005a5110` / Section 21 T04/F04 | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-084 | UID0000FQ | Apply T05 exact `void __thiscall UserPane__OpenDefaultSayInputPane(UserPane *)` type with F05 protected frame after A05. | very strong | ECX member call, mode write, formal member | IDA `0x005a53c0` / Section 21 T05/F05 | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-085 | UID0000FQ | Apply T06 exact `void __thiscall UserPane__OpenSayToUserNameInputPane(UserPane *)` type, replacing stale cdecl, with F06 protected frame. | very strong | caller loads ECX UserPane, formal member | IDA `0x005a5450` / Section 21 T06/F06 | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-086 | UID0000FQ | Apply T07 exact `void __thiscall UserPane__OpenSayToLastRecipientInputPane(UserPane *)` type with F07 protected frame after A07. | strong | direct UserPane fields, no consumed return | IDA `0x005a54b0` / Section 21 T07/F07 | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-087 | UID0000FQ | Apply T08 exact `void __thiscall UserPane__OpenSayToGroupMessageInputPane(UserPane *)` type with F08 protected frame after A08. | very strong | caller ECX and formal member | IDA `0x005a5570` / Section 21 T08/F08 | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-088 | UID0000FQ | Apply T09 exact `void __thiscall UserPane__OpenSayToClanMessageInputPane(UserPane *)` type with F09 protected frame after A09. | very strong | caller ECX and formal member | IDA `0x005a5640` / Section 21 T09/F09 | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-089 | UID0000FQ | Apply T10 exact `void __thiscall UserPane__OpenShoutInputPane(UserPane *)` type with F10 protected frame after A10. | very strong | ECX member call, mode write, formal member | IDA `0x005a5710` / Section 21 T10/F10 | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-090 | UID0000C4 | Apply T11 parser-safe Group constructor type with class-pointer return, `const wchar_t *groupName`, and exact F11 frame delta after A11. | very strong | constructor/vtable/formal argument/frame evidence | IDA `0x005b1ec0` / Section 21 T11/F11 | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-091 | UID0000C4 | Apply T12 exact void Group submit member type with complete F12 frame protected after A12. | very strong | primary virtual slot/formal method/protocol | IDA `0x005b1f80` / Section 21 T12/F12 | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-092 | UID0000C5 | Apply T13 parser-safe Clan constructor type with class-pointer return, `const wchar_t *clanName`, and exact F13 frame delta after A13. | very strong | constructor/vtable/formal argument/frame evidence | IDA `0x005b22d0` / Section 21 T13/F13 | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-093 | UID0000C5 | Apply T14 exact void Clan submit member type with complete F14 frame protected after A14. | very strong | primary virtual slot/formal method/protocol | IDA `0x005b2390` / Section 21 T14/F14 | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-094 | UID0000C3 | Apply T15 exact void Say submit member type with complete F15 frame protected after A15. | very strong | primary virtual slot/formal method/protocol | IDA `0x005b3670` / Section 21 T15/F15 | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-095 | UID0000C7 | Apply T16 parser-safe Name constructor class-pointer type with complete F16 frame protected after A16. | very strong | constructor/vtables/formal source | IDA `0x005b3cb0` / Section 21 T16/F16 | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-096 | UID0000C7 | Apply T17 exact `bool __thiscall ...HandleKeyOrTextEvent(SayToUserNameInputPane *, Event *)` type with F17 event row preserved. | very strong | secondary virtual slot/Event formal source/frame | IDA `0x005b3e80` / Section 21 T17/F17 | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-097 | UID0000C7 | Apply T18 exact void Name submit member type with complete F18 frame protected after A18. | very strong | primary virtual slot/formal method | IDA `0x005b4080` / Section 21 T18/F18 | supervisor Gate2B | proposed-unapplied |
| [ ] | C0000N9-098 | UID0000D5 | Apply T19 exact void Shout submit member type with complete F19 frame protected after A19. | very strong | primary virtual slot/formal method/protocol | IDA `0x005b4260` / Section 21 T19/F19 | supervisor Gate2B | proposed-unapplied |

READY_FOR_SUPERVISOR_EXECUTE
