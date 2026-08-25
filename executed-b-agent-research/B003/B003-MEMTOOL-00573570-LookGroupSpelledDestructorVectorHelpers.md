** TARGET-REPORT-UID:000240 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003-MEMTOOL-00573570 LookGroupSpelledDestructorVectorHelpers

## Finalized Report / Current Recommendation

- Current recommendation: treat the Advanced-Error-Scan warning as a real scanner-visible document-token miss, but not as a substantive missing-documentation, range, owner/emitter, split, score, or IDA repair problem.
- Final disposition: keep [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md) as a non-reconstructable, non-emitting mixed aggregate/index. Exact child pages already carry the reconstructable destructor routing or non-emitting helper classification.
- Required action: optional target-body line adding the exact compact token `LookGroupSpelledDestructorVectorHelpers`, then rerun validator and the advanced memory-range scan. No metadata or coverage row change is recommended.
- Confidence: high.

## Supporting Research

## Target

- Assignment: `B003-MEMTOOL-00573570`
- Target UID: `000240`
- Target path: `by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md`
- Source warning: `auto-generated/by-memory-tool-report.md` Advanced-Error-Scan reports missing document text for `LookGroupSpelledDestructorVectorHelpers`.
- Current metadata: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank reconstruction C++.
- Current coverage state: generated `-ag-memory-coverage.md` lists [UID:000240] as `not_reconstructable`; `by-memory/-coverage-report.md` lists it as `ignored : 88% : very strong`.
- Score before/after this audit: `88/92` before, `88/92` after. No score change recommended.

## Executive Recommendation

The memtool warning is caused by a literal-token mismatch. A direct target-page text check found zero matches for `LookGroupSpelledDestructorVectorHelpers`, while the page documents the same aggregate under the readable H1 `Look/Group/Spelled Destructor And Vector Helpers` and with detailed split/ownership evidence.

Apply only this optional target edit if the supervisor wants the warning cleared. Add under `## Status`, preferably after the confidence/disposition lines:

```markdown
- Document-text token: `LookGroupSpelledDestructorVectorHelpers` is the compact filename token for this non-emitting look/group/spelled destructor and vector-helper aggregate; the page title uses the readable `Look/Group/Spelled Destructor And Vector Helpers` form.
```

Do not change `CANONICAL_OWNER`, `RECONSTRUCTABLE`, `EMITTER_UIDS`, scores, filename, range, or coverage row for this warning.

## Supervisor Active Recheck

- The assignment asks whether this is only a scanner-visible label issue or whether documentation repair, rename, owner/emitter repair, score change, split/container repair, or IDA-side repair is needed.
- Result: scanner-visible label issue only for [UID:000240]. The aggregate is already split, classified, and routed correctly under the current owner/emitter model.
- The broad range should remain parentless and non-emitting because no single semantic owner spans `NewGroupPane`, `SelfLookPane2`, `SelfLookPane`, `SpelledPane`, vector helpers, no-xref helper code, and alignment.
- Exact destructor children route through their direct class owners; exact helper children remain non-reconstructable/non-emitting.

## Inference Research Guidance Check

- `by-structure.md` allows `RECONSTRUCTABLE:FALSE` on reviewed mixed/index pages whose exact children carry the real source ownership. That rule applies here.
- `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS` is valid for this aggregate because it is not a source-level object and should not emit. This is different from a reconstructable no-owner/non-emitting dead end.
- The active C++ code-entry gate is `90/90+`. The aggregate is `RECONSTRUCTABLE:FALSE`, so C++ entry is not applicable. The exact reconstructable destructor children remain below 90 completion or have unresolved final field/helper names, so no C++ recommendation is made here.

## Evidence Standards Used

- Live IDA MCP endpoint: `http://127.0.0.1:13337/mcp`.
- Live IDA database: `b001_0003gy`, module `NexusTK.exe`, input path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis and Hex-Rays ready.
- IDA tools used: `server_health`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `find_bytes`, `callees`, and `disasm`.
- Documentation evidence used: target page, exact child pages [UID:00039D] through [UID:00039K], class/file owner pages, generated memory coverage, memtool report, and `by-memory/-coverage-report.md`.

## IDA MCP Facts

- Function starts confirmed by `lookup_funcs`:
  - `0x00573570`: `sub_573570`, size `0xc4`.
  - `0x00573640`: `sub_573640`, size `0xe8`.
  - `0x00573730`: `sub_573730`, size `0xe8`.
  - `0x00573820`: `sub_573820`, size `0x53`.
  - `0x00573880`: `sub_573880`, size `0x7c`.
  - `0x00573900`: `sub_573900`, size `0x62`.
  - `0x00573970`: `??0big_integer@__crt_strtox@@QAE@XZ_0`, size `0x9`, but the body is only a zero-store helper.
- Non-function boundaries confirmed by `lookup_funcs`: no function at `0x00573564`, `0x00573634`, `0x00573728`, `0x00573818`, `0x00573873`, `0x005738fc`, `0x00573962`, `0x00573979`, `0x00573980`, `0x0057399e`, or `0x005739a0`.
- Padding bytes confirmed by `get_bytes`: `0x00573564-0x00573570`, `0x00573634-0x00573640`, `0x00573728-0x00573730`, `0x00573818-0x00573820`, `0x00573873-0x00573880`, `0x005738fc-0x00573900`, `0x00573962-0x00573970`, `0x00573979-0x00573980`, and `0x0057399e-0x005739a0` are `0xcc` alignment.
- Raw helper bytes at `0x00573980`: `56 8b f1 8b 06 85 c0 74 13 50 e8 a1 26 fa ff 8b c8 e8 da 27 fa ff c7 06 00 00 00 00 5e c3`, matching the documented pointer-slot clear/free helper.
- `xrefs_to 0x00573570`: code refs at `0x005732a5` and `0x005732b0`, plus vtable data at `0x00624554`.
- `xrefs_to 0x00573640`: code refs at `0x005732bb` and `0x005732c6`, plus vtable data at `0x006246f8`.
- `xrefs_to 0x00573730`: code refs at `0x005732d1` and `0x005732dc`, plus vtable data at `0x00624188`.
- `xrefs_to 0x00573820`: code refs at `0x005732e7`, `0x005732f2`, and `0x005732fd`, plus vtable data at `0x006242c8`.
- `xrefs_to 0x00573880`: only `0x00573151` and `0x00573162` inside `sub_572FD0`.
- `xrefs_to 0x00573900`: only `0x0056be70` inside `sub_56BE20`.
- `xrefs_to 0x00573970`, `0x00573980`, and `0x005739a0`: zero xrefs.
- `find_bytes` found little-endian function-pointer hits for destructor starts at `0x00624554`, `0x006246f8`, `0x00624188`, and `0x006242c8`; it found no pointer hits for `0x00573880`, `0x00573900`, `0x00573970`, or `0x00573980`.
- `callees`: first three scalar deleting destructors call shared cleanup/free helpers `0x00516030`, `0x00516170`, `0x005450d0`, `0x004f4ac0`, and guard check dispatch; `0x00573820` calls `0x004b5760`, `0x004b6cb0`, `0x0058e140`, `0x004f4ac0`, and guard check dispatch; `0x00573880` calls `0x00582a90`; `0x00573900` calls `0x00582c60` and `0x00582b70`; `0x00573970` has no callees.
- `disasm 0x00573970`: `mov dword ptr [ecx], 0; mov eax, ecx; retn`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent / Emitter | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00573570-0x00573634` | [UID:00039D](by-memory/0x00573570-0x00573634.NewGroupPaneScalarDeletingDestructor.md) | `NewGroupPane` scalar deleting destructor | true | `000090` / `000090` | `86/91` | Exact source-bearing child routed to `NewGroupPane`. |
| `0x00573634-0x00573640` | [UID:0000VN][-ignored](by-memory/-ignored.md) | padding | false | none | `100`, strong | `0xcc` alignment. |
| `0x00573640-0x00573728` | [UID:00039E](by-memory/0x00573640-0x00573728.SelfLookPane2ScalarDeletingDestructor.md) | `SelfLookPane2` scalar deleting destructor | true | `0000CV` / `0000CV` | `88/92` | Exact source-bearing child routed to `SelfLookPane2`. |
| `0x00573728-0x00573730` | [UID:0000VN][-ignored](by-memory/-ignored.md) | padding | false | none | `100`, strong | `0xcc` alignment. |
| `0x00573730-0x00573818` | [UID:00039F](by-memory/0x00573730-0x00573818.SelfLookPaneScalarDeletingDestructor.md) | `SelfLookPane` scalar deleting destructor | true | `0000CU` / `0000CU` | `88/92` | Exact source-bearing child routed to `SelfLookPane`. |
| `0x00573818-0x00573820` | [UID:0000VN][-ignored](by-memory/-ignored.md) | padding | false | none | `100`, strong | `0xcc` alignment. |
| `0x00573820-0x00573873` | [UID:00039G](by-memory/0x00573820-0x00573873.SpelledPaneScalarDeletingDestructor.md) | `SpelledPane` scalar deleting destructor | true | `0000DK` / `0000DK` | `87/92` | Exact source-bearing child routed to `SpelledPane`. |
| `0x00573873-0x00573880` | [UID:0000VN][-ignored](by-memory/-ignored.md) | padding | false | none | `100`, strong | `0xcc` alignment. |
| `0x00573880-0x005738fc` | [UID:00039H](by-memory/0x00573880-0x005738fc.SpelledPaneEntryVectorCopyHelper.md) | `SpelledPane` entry vector copy helper | false | none | `84/91` | Non-emitting compiler/template helper. |
| `0x005738fc-0x00573900` | [UID:0000VN][-ignored](by-memory/-ignored.md) | padding | false | none | `100`, strong | `0xcc` alignment. |
| `0x00573900-0x00573962` | [UID:00039I](by-memory/0x00573900-0x00573962.SpelledPaneEntryVectorEraseHelper.md) | `SpelledPane` entry vector erase helper | false | none | `84/91` | Non-emitting compiler/template helper. |
| `0x00573962-0x00573970` | [UID:0000VN][-ignored](by-memory/-ignored.md) | padding | false | none | `100`, strong | `0xcc` alignment. |
| `0x00573970-0x00573979` | [UID:00039J](by-memory/0x00573970-0x00573979.ZeroInitializePointerHelper.md) | no-xref zero-initialize helper | false | none | `82/88` | Non-emitting no-owner helper. |
| `0x00573979-0x00573980` | [UID:0000VN][-ignored](by-memory/-ignored.md) | padding | false | none | `100`, strong | `0xcc` alignment. |
| `0x00573980-0x0057399e` | [UID:00039K](by-memory/0x00573980-0x0057399e.PointerSlotClearFreeHelper.md) | no-xref pointer-slot clear/free helper | false | none | `82/88` | Non-emitting raw helper. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00573570` | thunks `0x005732a5`, `0x005732b0`; vtable slot `0x00624554` | `NewGroupPane` destructor child. |
| `0x00573640` | thunks `0x005732bb`, `0x005732c6`; vtable slot `0x006246f8` | `SelfLookPane2` destructor child. |
| `0x00573730` | thunks `0x005732d1`, `0x005732dc`; vtable slot `0x00624188` | `SelfLookPane` destructor child. |
| `0x00573820` | thunks `0x005732e7`, `0x005732f2`, `0x005732fd`; vtable slot `0x006242c8` | `SpelledPane` destructor child. |
| `0x00573880` | callers `0x00573151`, `0x00573162` inside `sub_572FD0` | `SpelledPane` entry-vector copy/construct helper, not a standalone owner. |
| `0x00573900` | caller `0x0056be70` inside `sub_56BE20` | `SpelledPane` entry-vector erase/remove helper, not a standalone owner. |
| `0x00573970` | no xrefs | Tiny zero-initialize support, current IDA name is runtime-style pollution. |
| `0x00573980` | no xrefs and no IDA function object | Raw pointer-slot clear/free helper. |

## Documentation Evidence And IDA Status

- Target page already documents the aggregate as non-emitting, split, and parent-blank because it spans four class owners plus helper code.
- Target page body lacks the exact compact token `LookGroupSpelledDestructorVectorHelpers`; this is the direct cause of the memtool warning.
- [UID:00039D] through [UID:00039G] child pages are reconstructable destructor bodies with direct class owners and emitters: `000090`, `0000CV`, `0000CU`, and `0000DK`.
- [UID:00039H] and [UID:00039I] are non-emitting vector helper children tied to `SpelledPane` entry storage. IDA caller evidence confirms their context, but by-structure handling as compiler/template helpers is still correct.
- [UID:00039J] and [UID:00039K] are no-xref non-emitting helpers; live IDA gives no owner/emitter route and no evidence they should be hand-ported.
- [UID:000090][NewGroupPane](by-class/NewGroupPane.md), [UID:0000CV][SelfLookPane2](by-class/SelfLookPane2.md), [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md), and [UID:0000DK][SpelledPane](by-class/SpelledPane.md) all document the class-level context used by the exact destructor children.
- [UID:0000JS][Group](by-file/Group.md), [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md), and [UID:0000NZ][SpelledPane](by-file/SpelledPane.md) provide file-level output routes for the class children.

## Ranked Issue Analysis

### 1. Scanner-visible label issue

- Evidence for: target filename and memtool warning use `LookGroupSpelledDestructorVectorHelpers`; target body has zero exact matches; H1 uses `Look/Group/Spelled Destructor And Vector Helpers`.
- Evidence against: none.
- Decision: add one document-text token line to the target page.

### 2. Split/container issue

- Evidence for repair: the physical range is mixed and includes multiple owners.
- Evidence against repair: exact child pages already exist for every source-bearing or helper subrange, and padding rows are already represented. Live IDA confirms the same boundaries.
- Decision: no split/container repair required. The current `RECONSTRUCTABLE:FALSE` aggregate/index is correct.

### 3. Owner/emitter issue

- Evidence for current state: broad target spans `NewGroupPane`, `SelfLookPane2`, `SelfLookPane`, `SpelledPane`, vector helpers, no-xref helpers, and padding. Exact reconstructable destructor children already own and emit through their class routes.
- Evidence against current state: none from live IDA or generated coverage.
- Decision: keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and blank `EMITTER_UIDS` for [UID:000240].

### 4. Rename issue

- Evidence for rename: H1 and filename differ in readable punctuation.
- Evidence against rename: filename token is stable, generated coverage and child links use it, and the H1 is more readable. The warning only requires the compact token to appear in body text.
- Decision: no rename.

### 5. Score issue

- Evidence: live IDA reconfirms the existing child bounds, refs, callers, padding, and non-emitting aggregate classification. The page is already strong at `88/92`, but not final-audit exhaustive because child field/helper names remain provisional.
- Decision: no score change.

### 6. IDA-side repair issue

- Evidence: IDA function modeling is expected: destructors/vector helpers/zero helper are functions; `0x00573980` remains raw code with no xrefs; `0x005739a0` is also not modeled but starts the following documented raw `SimpleListPane` constructor. The docs already reflect these conditions.
- Decision: no IDA-side repair needed for this warning.

## Negative Evidence Summary

- No single owner owns the full `0x00573570-0x0057399e` aggregate.
- No xrefs or pointer-table hits justify making `0x00573880`, `0x00573900`, `0x00573970`, or `0x00573980` emitted standalone source under this aggregate.
- No raw-byte evidence shows a missing child range between the documented children; internal gaps are all `0xcc` alignment.
- No current evidence contradicts the exact child routing applied by prior batches.

## Exact Recommended Metadata / Coverage Changes

No metadata changes recommended. Keep:

```text
COMPLETION:88
CONFIDENCE:92
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
```

No `by-memory/-coverage-report.md` row change recommended. Keep the current row:

```markdown
    - [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md) 0x00573570-0x0057399e | aggregate | LookGroupSpelledDestructorVectorHelpers : ignored : 88% : very strong : Non-emitting mixed look/group/spelled destructor and vector-helper aggregate; live IDA confirms child bounds, thunk/vtable refs, padding, vector-helper callers, raw helper bytes, and no single direct parent across NewGroupPane/SelfLookPane2/SelfLookPane/SpelledPane/helper ownership. Batch 247 updated exact SelfLookPane2, SelfLookPane, and SpelledPane destructor children to direct class routing while this aggregate remains parent-blank.
```

Optional target-body edit to clear the memtool warning:

```markdown
- Document-text token: `LookGroupSpelledDestructorVectorHelpers` is the compact filename token for this non-emitting look/group/spelled destructor and vector-helper aggregate; the page title uses the readable `Look/Group/Spelled Destructor And Vector Helpers` form.
```

Ancillary documentation cleanup, not required to clear this target's memtool warning: exact destructor child pages [UID:00039D], [UID:00039E], [UID:00039F], and [UID:00039G] still say `Final C++ remains blank below the 95+ reconstruction gate.` Replace each instance with:

```markdown
- Final C++ remains blank under the active `90/90+` reconstruction-code gate because completion is still below 90 and final field/helper names are not source-quality.
```

Also consider updating the stale `95/95 reconstruction gate` wording in [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md) during the next normal documentation cleanup pass. This is not a blocker for [UID:000240] because the aggregate is non-reconstructable and has no C++ block.

## Validation / Memory Ranges

- Validator was not run because this pass did not edit by-* documentation.
- If the optional target-body line is applied, rerun:

> Executable block R001 was removed from this report and preserved verbatim in [B003-MEMTOOL-00573570-LookGroupSpelledDestructorVectorHelpers-removed.md](B003-MEMTOOL-00573570-LookGroupSpelledDestructorVectorHelpers-removed.md). The archived block is non-authoritative and must not be executed.

- Expected outcome after optional edit: the `LookGroupSpelledDestructorVectorHelpers` missing-document-text warning should clear. Generated `-ag-memory-coverage.md` should still show [UID:000240] as `not_reconstructable`, exact destructor children as emitted through their class/file routes, and helper children as non-reconstructable.

## Confidence

- Recommendation confidence: high.
- Score confidence: keep `88/92`.
- Remaining uncertainty: final source-quality field names and helper names for exact child pages, and whether some vector support should eventually be expressed through higher-level container operations in `SpelledPane`. These uncertainties are already handled by exact child pages and do not affect the target aggregate classification or memtool warning fix.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/B003-MEMTOOL-00573570-LookGroupSpelledDestructorVectorHelpers.md`
- Modified: none outside the Agent-B003 research folder.
- Coverage edited: no.
- by-* docs edited: no.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/B003-MEMTOOL-00573570-LookGroupSpelledDestructorVectorHelpers.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:29","uid":"000240"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at B003-MEMTOOL-00573570-LookGroupSpelledDestructorVectorHelpers-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/B003-MEMTOOL-00573570-LookGroupSpelledDestructorVectorHelpers.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000240"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
