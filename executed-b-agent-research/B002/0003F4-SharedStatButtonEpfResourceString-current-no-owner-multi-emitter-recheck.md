** TARGET-REPORT-UID:0003F4 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003F4 **
# 0003F4 SharedStatButtonEpfResourceString Current No-Owner / Multi-Emitter Recheck

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003F4][0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString](by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md) as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000NL,0000P0`.
- Final disposition: reconstructable pooled UTF-16 resource filename literal with two proven source-use output routes and no defensible single declaration owner.
- Required action: no canonical-owner assignment, emitter change, split, merge, reclassification, IDA-safe name repair, C++ entry, or `by-memory/-coverage-report.md` update is recommended.
- Confidence: high for the current no-owner/multiple-emitter state.

## Supporting Research

## Target

- Target UID: `0003F4`
- Target path: `by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md`
- Source queue/report row: `auto-generated/-ag-memory-coverage.md` current no-owner/multiple-emitter row.
- Current supervisor classification: Goal 2 B-agent no-owner/multiple-emitter recheck.
- Current scores and parent state: `COMPLETION:89`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NL,0000P0`, blank C++.

## Executive Recommendation

Keep the current state. The target is exactly the UTF-16LE `STATBUT.EPF` physical string at `0x00624b90-0x00624ba8`. Live IDA evidence still shows eight source-use xrefs from `SelfLookPane2` code under [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md) and two source-use xrefs from `UserLookPane` code under [UID:0000P0][UserLookPane](by-file/UserLookPane.md). That proves both emitter routes.

Do not set a canonical owner. The direct consumers prove use, not single declaration ownership. Assigning the physical pooled cell to either file would overclaim the other file's use, and no by-resource/global/table/debug artifact proves a shared declaration owner.

Do not add C++. The page remains below the active `90/90+` code-entry gate, and the correct eventual source form is likely use-site literals in the surrounding reconstructed functions, not a standalone global declaration on this page.

## Supervisor Active Recheck

- Trigger: user assigned `[UID:0003F4] by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md` for current no-owner/multiple-emitter Goal 2 research.
- Current generated state rechecked: `auto-generated/-ag-memory-coverage.md` lists owner `NONE`, emitters `0000NL,0000P0`, and generated route rooted at `SelfLookPane.cpp`.
- Split repair required: no. The target is one 24-byte UTF-16 string, has no interior xrefs, and the successor child starts at `0x00624ba8`.
- Direct page repair required: no. The current page already contains the exact label text, owner/emitter metadata, bytes, xrefs, score rationale, and change history consistent with this pass.

## Inference Research Guidance Check

- `by-structure.md` separates canonical ownership from output routing. This target is the case where `CANONICAL_OWNER:NONE` with multiple `EMITTER_UIDS` is appropriate: a pooled source literal used by independent source contexts.
- Consumer xrefs alone do not prove canonical ownership, but they are strong emitter evidence when the source-use functions have established file parents.
- Address adjacency in `.rdata` is weaker than xrefs. The predecessor and successor strings belong to SelfLookPane2, but the target itself crosses into UserLookPane usage.
- Prior reports and existing docs were treated as leads. The final recommendation is based on current target docs, current generated coverage rows, related source-owner docs, and fresh live IDA evidence.

## Evidence Standards Used

- IDA MCP: `server_health`, `lookup_funcs`, `get_bytes`, `get_string`, `xrefs_to`, `xref_query`, `find_bytes`, `decompile`, and focused disassembly snippets.
- Documentation evidence: target page, containing [UID:0002V2] split inventory, predecessor/successor child pages, `SelfLookPane`, `UserLookPane`, proposed source tree, generated memory coverage, and manual coverage row.
- Negative evidence: no interior target xrefs, no interior immediate hits, no unique shared declaration owner, and no reason to merge with nearby strings.

## IDA MCP Facts

- Active IDB: session `b001_0003gy`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, IDB `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Function/range facts: `lookup_funcs` reports `0x00624b90`, `0x00624ba8`, and `0x00624bbc` are not functions. The source-use functions are `sub_570FC0` at `0x00570fc0`, size `0xc45`, and `sub_5A0640` at `0x005a0640`, size `0xf3d`.
- Byte facts: `get_bytes 0x00624b90 size 0x18` returns `53 00 54 00 41 00 54 00 42 00 55 00 54 00 2e 00 45 00 50 00 46 00 00 00`.
- String facts: `get_string 0x00624b90` returns `STATBUT.EPF`; `get_string 0x00624820` returns separate sibling `STATBUTS.EPF`.
- Pattern facts: `find_bytes` finds the UTF-16LE `STATBUT.EPF` pattern only at `0x00624b90`; `STATBUTS.EPF` only at `0x00624820`; `STAT.EPF` pattern only at `0x00630ee4`.
- Xref facts: `xrefs_to 0x00624b90` returns ten direct data xrefs. Eight are in `sub_570FC0`: `0x00571579`, `0x005715cc`, `0x00571659`, `0x005716d6`, `0x0057175e`, `0x0057177b`, `0x00571b62`, and `0x00571bb5`. Two are in `sub_5A0640`: `0x005a0c73` and `0x005a0ce1`.
- Negative xref facts: `xrefs_to` for interior addresses `0x00624b94`, `0x00624b98`, `0x00624b9c`, `0x00624ba0`, and `0x00624ba4` returns zero xrefs.
- Immediate facts: `find_bytes 90 4B 62 00` finds exactly the ten operand/immediate sites corresponding to the target xrefs. Interior immediate patterns `94 4B 62 00`, `98 4B 62 00`, `9C 4B 62 00`, `A0 4B 62 00`, and `A4 4B 62 00` have zero matches.
- Boundary facts: successor start `0x00624ba8` has one xref at `0x005717ab`; `0x00624bbc` has one xref at `0x00571868`. Both are in `sub_570FC0`, supporting the successor child as SelfLookPane2-local stat label strings.
- Decompiler facts: `sub_570FC0` contains eight `sub_4D02F0(..., L"STATBUT.EPF", ...)` uses; `sub_5A0640` contains two `sub_4D02F0(..., L"STATBUT.EPF", ...)` uses, followed by drawing calls through `sub_4B9980`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00624788-0x00624c64` | [UID:0002V2][LookGroupCollectionResourceStringData](by-memory/0x00624788-0x00624c64.LookGroupCollectionResourceStringData.md) | Mixed look/group/collection resource-string and constant split inventory | `FALSE` | `NONE` | `88/92` | Container only |
| `0x00624b74-0x00624b90` | [UID:0003F3][SelfLookPane2LookPalStringFragments](by-memory/0x00624b74-0x00624b90.SelfLookPane2LookPalStringFragments.md) | Predecessor SelfLookPane2 `SE`/`LOOK.PAL` fragments | `TRUE` | `0000NL` | `85/88` | Neighbor, no change |
| `0x00624b90-0x00624ba8` | [UID:0003F4][SharedStatButtonEpfResourceString](by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md) | Pooled UTF-16 `STATBUT.EPF` literal | `TRUE` | `NONE`; emit `0000NL,0000P0` | `89/92` | Keep current state |
| `0x00624ba8-0x00624bd0` | [UID:0003F5][SelfLookPane2StatButtonLabelStrings](by-memory/0x00624ba8-0x00624bd0.SelfLookPane2StatButtonLabelStrings.md) | Successor SelfLookPane2 stat label strings | `TRUE` | `0000NL` | `85/88` | Neighbor, no change |
| `0x00570fc0` | [UID:0001HK][SelfLookPane2](by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md) | SelfLookPane2 setup/render source-use function | `TRUE` | `0000NL` | current docs | Proven emitter route |
| `0x005a0640` | [UID:0001KK][UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md) | UserLookPane setup/render source-use function | `TRUE` | `0000P0` | current docs | Proven emitter route |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00571579` | `push offset aStatbutEpf; "STATBUT.EPF"` in `sub_570FC0` | SelfLookPane2 emitter route |
| `0x005715cc` | `push offset aStatbutEpf; "STATBUT.EPF"` in `sub_570FC0` | SelfLookPane2 emitter route |
| `0x00571659` | `push offset aStatbutEpf; "STATBUT.EPF"` in `sub_570FC0` | SelfLookPane2 emitter route |
| `0x005716d6` | `push offset aStatbutEpf; "STATBUT.EPF"` in `sub_570FC0` | SelfLookPane2 emitter route |
| `0x0057175e` | `push offset aStatbutEpf; "STATBUT.EPF"` in `sub_570FC0` | SelfLookPane2 emitter route |
| `0x0057177b` | `push offset aStatbutEpf; "STATBUT.EPF"` in `sub_570FC0` | SelfLookPane2 emitter route |
| `0x00571b62` | `push offset aStatbutEpf; "STATBUT.EPF"` in `sub_570FC0` | SelfLookPane2 emitter route |
| `0x00571bb5` | `push offset aStatbutEpf; "STATBUT.EPF"` in `sub_570FC0` | SelfLookPane2 emitter route |
| `0x005a0c73` | `push offset aStatbutEpf; "STATBUT.EPF"` in `sub_5A0640` | UserLookPane emitter route |
| `0x005a0ce1` | `push offset aStatbutEpf; "STATBUT.EPF"` in `sub_5A0640` | UserLookPane emitter route |
| `0x00624ba8` | xref from `0x005717ab` only | Successor child starts after target and is SelfLookPane2-local |
| `0x00624bbc` | xref from `0x00571868` only | Successor child continuation is SelfLookPane2-local |

## Documentation Evidence And IDA Status

- Target page: matches current IDA facts and already documents no-owner/multiple-emitter rationale, exact bytes, xrefs, negative interior refs, and score rationale.
- `auto-generated/-ag-memory-coverage.md`: current row shows `no-owner`, owner `NONE`, emitters `0000NL,0000P0`; no generated-state contradiction found.
- `by-memory/-coverage-report.md`: current nested row already summarizes the B003 repair and the same IDA facts; no replacement is needed.
- [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md): `85/89`, projected to `NexusTK/ui/panels/`, owns the SelfLookPane/SelfLookPane2 family. It is a valid emitter.
- [UID:0000P0][UserLookPane](by-file/UserLookPane.md): `88/85`, projected to `NexusTK/ui/panels/`, owns the remote-character UserLookPane family. It is a valid emitter.
- [UID:0002V2][LookGroupCollectionResourceStringData](by-memory/0x00624788-0x00624c64.LookGroupCollectionResourceStringData.md): non-emitting mixed split inventory. It supports boundary context but should not own or emit the child.
- [UID:0003F3] and [UID:0003F5]: predecessor/successor pages show adjacent SelfLookPane2-local children. They support the exact split boundary and do not require merging with the shared target.
- `by-project-structure/proposed-source-tree.md`: lists both `ui/panels/SelfLookPane.cpp` and `ui/panels/UserLookPane.cpp`, and records `LegendPane` as shared look/status child context rather than collapsing the look panes into one file.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000NL,0000P0`

- Evidence for: ten direct xrefs split across two validated file roots; decompiler context shows both functions pass `L"STATBUT.EPF"` to the same resource-frame helper; no single declaration owner is proven; current by-structure explicitly supports no-owner/multiple-emitter pooled literals.
- Evidence against: the physical string has more uses from SelfLookPane2 than UserLookPane, but xref count does not establish ownership.
- Decision: accepted. This is the best current model.

### 2. [UID:0000NL] `SelfLookPane` as canonical owner

- Evidence for: eight of ten xrefs are in `sub_570FC0`, which belongs to the SelfLookPane2 source family; neighboring predecessor and successor children are SelfLookPane2-local.
- Evidence against: UserLookPane has two direct xrefs and no evidence shows it imports or references a SelfLookPane-owned declaration. Assigning the pooled cell to SelfLookPane would overclaim the UserLookPane source-use route.
- Decision: reject as canonical owner; keep as emitter.

### 3. [UID:0000P0] `UserLookPane` as canonical owner

- Evidence for: two direct xrefs are in `sub_5A0640`, which belongs to UserLookPane.
- Evidence against: eight direct xrefs are in SelfLookPane2; no evidence shows SelfLookPane2 uses a UserLookPane-owned declaration. UserLookPane is a consumer, not a proven declaration owner.
- Decision: reject as canonical owner; keep as emitter.

### 4. [UID:0002V2] containing split inventory as owner/emitter

- Evidence for: physical containment and split context.
- Evidence against: `0002V2` is explicitly `RECONSTRUCTABLE:FALSE`, non-emitting, and spans multiple owners. It is not a source-level declaration or file root.
- Decision: reject as canonical owner and emitter.

### 5. New by-resource/global shared `STATBUT.EPF` owner

- Evidence for: the literal names a resource file and is shared by two look-pane modules.
- Evidence against: no resource/global page, table, pointer object, debug/source path, or relocation pattern proves a shared declaration owner. A new owner would be invented solely to avoid `NONE`.
- Decision: reject.

### 6. Split, merge, rename, or reclassify

- Evidence for: none current.
- Evidence against: exact 24-byte string, no interior xrefs, unique target string pattern, separate `STATBUTS.EPF` and `STAT.EPF` strings, and successor refs begin cleanly at `0x00624ba8`.
- Decision: no split, merge, rename, IDA-safe name repair, or reclassification.

## Negative Evidence Summary

- No xrefs to target interior addresses.
- No immediate byte-pattern hits for target interior addresses.
- No evidence that `STATBUTS.EPF` at `0x00624820` or `STAT.EPF` at `0x00630ee4` belongs in this range.
- No table/global/by-resource page proves a shared canonical declaration owner.
- No single existing file root covers both SelfLookPane2 and UserLookPane as a direct source owner. The shared `LegendPane` caveat in project docs is unrelated; the target xrefs are in SelfLookPane2 and UserLookPane functions, not a LegendPane function.

## Final Recommendation

- Exact changes applied or recommended: none applied; keep current target metadata unchanged.
- Exact parent assignments applied or recommended: keep `CANONICAL_OWNER:NONE`.
- Exact emitter assignments applied or recommended: keep `EMITTER_UIDS:0000NL,0000P0`.
- Exact items left no-owner/non-emitting and why: target is no-owner but not non-emitting; the no-owner state reflects absent canonical declaration ownership, while the emitter list reflects proven source-use routes.
- Exact future work outside this assignment scope: sibling pooled literals in the same island can be reviewed under the same current owner/emitter rule, but no sibling edit is part of this target.

## Supervisor-Owned Shared-Report Text

No `by-memory/-coverage-report.md` edit is recommended. The current row is already acceptable and should remain:

```markdown
            - [UID:0003F4][0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString](by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md) 0x00624b90-0x00624ba8 | pooled UTF-16 resource filename literal | SharedStatButtonEpfResourceString : reconstructable : 89% : very strong : B003 advanced-scan repair reclassified the shared `STATBUT.EPF` literal from non-reconstructable/non-emitting to `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000NL,0000P0`; live IDA confirms exact UTF-16LE bytes, ten direct xrefs to `aStatbutEpf` (eight from SelfLookPane2 `sub_570FC0`, two from UserLookPane `sub_5A0640`), no interior target refs, and separate successor label-string refs at `0x00624ba8`/`0x00624bbc`.
```

No `auto-generated/-ag-memory-coverage.md` manual edit is allowed or needed. Its current generated row is consistent:

```markdown
| [UID:0003F4][0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString](by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md) | no-owner | `NONE` | `0000NL`,`0000P0` |  | no | `auto-generated/NexusTK/ui/panels/SelfLookPane.cpp` | `by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md` |  |
```

## Follow-Up Actions

- Supervisor actions: update any external B-agent tracker if needed; no shared coverage row change is needed.
- A-agent actions: none for this target unless a future source pass proves a shared declaration owner.
- B002 future research actions: review sibling pooled literals only if assigned separately.

## Confidence

- Recommendation confidence: high.
- Score confidence: keep existing `89/92`; the bytes, string identity, xrefs, emitter routes, and negative split evidence are strong, but final C++/source declaration remains below the active gate.
- Remaining uncertainty: original declaration style. The literal may have appeared independently at use sites or in an unmodeled shared resource helper, but the binary does not prove either.

## Validator Results

- Commands run: none.
- Results: not applicable. No by-* documentation files were edited, no split was performed, and no validator-managed metadata changed.
- Dry runs: none.
- Any unresolved validator warnings/errors introduced by this work: none.

## Lease State

- Lease report checked: `tools/leaser/Agents/current_leases.md`.
- Leases taken: none.
- Leases released: none needed.
- Rationale: this pass created only a report under `Agent-B002/research`; no leased-scope by-* documentation was edited.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/0003F4-SharedStatButtonEpfResourceString-current-no-owner-multi-emitter-recheck.md`
- Modified: none outside the created report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003F4","source_path":"executed-b-agent-research/B002/0003F4-SharedStatButtonEpfResourceString-current-no-owner-multi-emitter-recheck.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
