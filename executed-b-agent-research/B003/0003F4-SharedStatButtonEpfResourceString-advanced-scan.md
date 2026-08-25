** TARGET-REPORT-UID:0003F4 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0003F4 SharedStatButtonEpfResourceString Advanced Scan

## Finalized Report / Current Recommendation

- Current recommendation: pass this repaired report through Gate 1 as an existing-report revalidation repair. Do not perform new by-* edits from this pass; the current target page already contains the accepted UID0003F4 evidence and metadata at same-or-greater detail.
- Final disposition: keep [UID:0003F4][0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString](../../../../../by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md) as `COMPLETION:89`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NL,0000P0`, blank `EMITTER_POSITION_OPTIONAL`, and blank direct `RECONSTRUCTION_CPP CODE`.
- Required action: supervisor Gate 1 review of this report artifact. The live active-revalidation blocker was cleared by the supervisor-owned validator command `active-clear-revalidation` command id `000000007201` at `2026-07-05T16:00:53-04:00`; B003 did not edit validator-owned status headers, generated reports, coverage reports, or lifecycle/archive files during this cleanup.
- Confidence: high for the technical recommendation. The preserved live IDA MCP evidence proves exact bytes, ten source-use xrefs, two emitter routes, no interior target refs, and a correct successor boundary. The remaining uncertainty is generated/registry visibility outside this report-text repair, not target-evidence-owned.

## Supporting Research

- Current artifact status: this active report path no longer carries the live `REPORT-VALIDATION-STATUS` or `REPORT-REVALIDATION-REASON` headers. The supervisor cleared the active revalidation marker with `python .\tools\validator.py active-clear-revalidation B003 0003F4-SharedStatButtonEpfResourceString-advanced-scan.md --apply --no-generated-refresh`, command id `000000007201`, at `2026-07-05T16:00:53-04:00`; the validator-owned footer records the event as `active-revalidation-cleared`.
- Historical lifecycle: command `invalidate_execute B003 0003F4-SharedStatButtonEpfResourceString-advanced-scan.md --apply` returned the executed report to this active research path as command `000000007183` at `2026-07-05T15:40:46-04:00`. Earlier event `000000004167` marked the executed report for revalidation on `2026-07-01T19:52:03-04:00` because the registry could not resolve `target_uid_unknown: 0003F4`; that marker has since been cleared for this active artifact by command `000000007201`.
- Historical implementation note: older wording in this report said the advanced-scan repair was "accepted and applied." That is historical target-edit history, not a current request for B003 to edit by-* docs. The current target page already contains the advanced-scan label, source-use evidence, no-owner/two-emitter disposition, no-code proof, and score rationale.
- Existing-report repair scope: the pre-Gate-1 repair pass repaired report text only. This Gate 2 callback verified target/support docs, updated this report ledger/checklist, and ran the scoped target validator `000000007217`; it did not acquire leases, manually edit generated/coverage files, or run lifecycle/archive commands.

## Target

- Target UID: `0003F4`.
- Target path: `by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md`.
- Target range: `0x00624b90-0x00624ba8`.
- Target item: pooled UTF-16LE resource filename literal `STATBUT.EPF`.
- Historical source queue/report row: `auto-generated/by-memory-tool-report.md` Advanced-Error-Scan once reported `0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md: missing document text for SharedStatButtonEpfResourceString`.
- Current supervisor classification for this turn: existing-report revalidation repair, not new target research and not implementation callback.
- Current target state read-only on `2026-07-05`: `89/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NL,0000P0`, blank optional emitter position, blank formal C++ block, `Nested:0`.

## Current Target State

- Existing metadata: the target page currently has `COMPLETION:89`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NL,0000P0`, blank `EMITTER_POSITION_OPTIONAL`, blank `RECONSTRUCTION_CPP CODE`, and `Nested:0`.
- Existing evidence body: the target already documents exact range `0x00624b90-0x00624ba8`, size `0x18` / 24 bytes, UTF-16LE bytes for `STATBUT.EPF`, ten direct target-start xrefs, negative interior-address/xref scans, successor refs at `0x00624ba8`/`0x00624bbc`, and no standalone direct C++ because this is a pooled use-site literal.
- Existing support state: `by-file/SelfLookPane.md` already notes eight direct `push offset aStatbutEpf` refs from `sub_570FC0` and explains SelfLookPane emission without sole ownership. `by-file/UserLookPane.md` already notes two direct refs from `sub_5A0640` and explains UserLookPane emission without sole ownership. The parent `by-memory/0x00624788-0x00624c64.LookGroupCollectionResourceStringData.md` already lists UID0003F4 as the shared `STATBUT.EPF` pooled literal under a non-emitting mixed inventory.
- Generated/tracker state checked read-only: earlier `auto-generated/-ag-research-tracker.md` output listed historical executed UID0003F4 reports with unregistered/revalidation diagnostics due `target_uid_unknown: 0003F4`. After scoped validator command `000000007217`, UID0003F4 rows are present in `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/-ag-research-tracker.md`; manual `by-memory/-coverage-report.md` remains untouched and generated/manual coverage artifacts were not edited by hand.
- Current artifact/lifecycle status: this report remains in active Agent-B003 research for Gate 1 review after supervisor command `000000007201` cleared the active revalidation marker. Historical implementation and validator output below are retained only as history and evidence; they are not current authorization to edit by-* docs or run lifecycle commands.

## Executive Recommendation

The original advanced-scan finding was partly a real wording issue and partly a stale modeling issue. The current target page has already resolved both, so this repaired report recommends no new by-* edits.

The wording issue was simple: the document described `STATBUT.EPF` but did not contain the exact filename label token `SharedStatButtonEpfResourceString` outside ignored change/update text. The current target page now contains that exact label in the Range section.

The stale modeling issue was more important: current `by-structure.md` distinguishes canonical ownership from output routing. The literal is source-declared/generated-binary data because both relevant source-use routes need `L"STATBUT.EPF"` when reconstructed. It should not be non-reconstructable merely because the linker pooled the physical `.rdata` bytes. The correct current model is:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000NL,0000P0
```

No final C++ should be entered directly on this page. The stronger current reason is source shape: this physical by-memory page represents a pooled use-site literal, and standalone C++ here would invent a shared declaration. The final source expression should appear as `L"STATBUT.EPF"` inside the reconstructed SelfLookPane/UserLookPane methods.

## Supervisor Active Recheck

- Trigger for this repair: current Agent-B003 `goal.md` assigned an existing-report revalidation repair for `tools/leaser/Agents/Agent-B003/research/0003F4-SharedStatButtonEpfResourceString-advanced-scan.md`.
- Report repair required: yes. The returned report had useful research but read as an implementation log and lacked current required Gate 1 sections, a current-state section, a claim ledger, and an implementation tracking checklist.
- Split repair required: no. The exact target is a 24-byte UTF-16LE string and has no interior xrefs. The next child begins at `0x00624ba8` and has separate SelfLookPane2-only refs.
- Direct page repair required now: no. The target page already has the exact label text, current owner/emitter/reconstructable metadata, detailed IDA evidence, and no-code proof.
- Coverage-report/generated direct edit: not performed and not recommended for B003. Any lifecycle, registry, generated, or manual coverage clearing must be supervisor/validator-owned.

## Inference Research Guidance Check

`by-structure.md` controls the decision:

- `CANONICAL_OWNER` is semantic ownership, not nearest consumer.
- `EMITTER_UIDS` is output routing and can contain multiple emitters.
- Pooled string literals can remain `CANONICAL_OWNER:NONE` when no single declaration owner is proven, while still emitting through every proven source-use file.
- NexusTK-owned source-declared/generated-binary string literals should be `RECONSTRUCTABLE:TRUE` when source reconstruction must reproduce them.
- Reconstruction C++ is not recommended directly on UID0003F4 even though the current combined score/emitter gate is met, because the source shape is use-site literals inside the surrounding source functions rather than a standalone by-memory declaration.

`inference_research.md` also matters here: consumer xrefs alone do not prove canonical ownership, but clustered source-use xrefs are strong emitter evidence. Address adjacency inside `.rdata` remains weaker than direct xrefs.

## Heuristic / Inference Reanalysis And Validation

- Pooled-literal modeling: `STATBUT.EPF` is source-level data, but the physical cell is shared by two independent source routes. The accepted heuristic is no canonical owner with multiple emitters, not non-reconstructable/no-emitter and not single-consumer ownership.
- Owner/emitter split: eight direct refs from SelfLookPane2 and two from UserLookPane prove both source-use routes. The larger SelfLookPane2 ref count is not enough to make SelfLookPane the semantic owner because UserLookPane materially uses the same physical literal.
- Range/split validation: exact bytes decode to one UTF-16LE string plus terminator over `0x18` bytes. Interior addresses have no xrefs or immediate hits, and successor refs begin at `0x00624ba8`/`0x00624bbc`, so no split, tail child, range widen, predecessor merge, or successor merge is justified.
- Source placement validation: final emitted source should surface `L"STATBUT.EPF"` at use sites in SelfLookPane and UserLookPane reconstruction, not as a standalone global declaration from UID0003F4.
- Generated-output validation: a current read-only search found historical tracker revalidation entries for UID0003F4 but no active UID0003F4 row in the checked generated coverage/tool reports. That is registry/generated state, not evidence against the target page facts; B003 must not fix it by hand.
- Rejected alternatives validated: sole `SelfLookPane`, sole `UserLookPane`, `LookGroupCollectionResourceStringData` parent ownership, `LegendPane`, a synthetic shared by-resource/global owner, broad look/status source owner, and range/merge/reclass alternatives all remain unsupported by direct evidence.

## Evidence Standards Used

- IDA MCP bytes and string decoding for exact data content.
- IDA MCP xrefs and scoped listing search for all direct code references.
- Hex-Rays decompiler context for both source-use functions.
- Current by-file documentation for the two emitter roots.
- Current containing split-inventory page for boundaries and sibling roles.
- Negative evidence: no interior target refs, no target-interior immediate hits, no by-resource/global page for a shared `STATBUT.EPF` declaration, and no single owner covering both consumers.
- Current repair standard: no new target facts were needed beyond the preserved live IDA MCP evidence and current target/support docs. This callback used read-only filesystem checks plus the scoped target validator; no lifecycle/archive commands were run.

## Evidence Checked

- Current report artifact: `tools/leaser/Agents/Agent-B003/research/0003F4-SharedStatButtonEpfResourceString-advanced-scan.md`, with no live `REPORT-VALIDATION-STATUS` header and with the validator-owned `VALIDATOR-REPORT-HISTORY` footer preserved.
- Current target doc: `by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md`, which already contains the accepted `89/92`, no-owner, two-emitter, blank-C++ state and detailed evidence body.
- Current support docs: `by-file/SelfLookPane.md`, `by-file/UserLookPane.md`, and `by-memory/0x00624788-0x00624c64.LookGroupCollectionResourceStringData.md`.
- Current generated/tracker checks: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/by-memory-tool-report.md`, manual `by-memory/-coverage-report.md`, and `project-level/-unresolved.md` via read-only `rg`; after callback validator command `000000007217`, generated memory coverage/tracker rows for UID0003F4 are present. Current observed headers show `-ag-memory-coverage.md` and `-ag-coverage-report-by-memory.md` at command `000000007217` / `2026-07-05T16:10:22-04:00`, while `-ag-research-tracker.md` has advanced to command `000000007219` / `2026-07-05T16:12:36-04:00`.
- Historical reports checked as supporting context: executed UID0003F4 reports under `executed-b-agent-research/B001`, `B002`, and `B003` matching the target UID/name.
- Existing IDA MCP evidence preserved: sessions `b001_0003gy`, `a001_goal2_class_batch`, and `b001_0002bd` from incorporated reports/target body. No new MCP call was required because this was a report-text repair and current target docs already preserve the binary facts at report-level detail.
- Negative checks performed: no lifecycle/archive command, no execute-report variant, no manual generated/coverage/tracker edits, and no leases. The only by-* write was validator-owned target normalization during the scoped target file validator.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0003F4-01 | Target metadata should remain `89/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NL,0000P0`, blank optional emitter position, blank formal C++, `Nested:0`. | High | Current target header rechecked after validator command `000000007217`; prior live IDA evidence confirms no single owner and two use routes. | Target metadata; `Current Target State`; `Score And Metadata Recommendation` | already-present | already-present |
| C-0003F4-02 | UID0003F4 is exact range `0x00624b90-0x00624ba8`, size `0x18` / 24 bytes, UTF-16LE `STATBUT.EPF` plus terminator. | High | Target Range/IDA Evidence already carries exact range, size, bytes, and string decode. | Target `Range` / `IDA Evidence`; report `IDA MCP Facts` | already-present | already-present |
| C-0003F4-03 | Ten direct target-start refs exist: eight from SelfLookPane2 `sub_570FC0` and two from UserLookPane `sub_5A0640`. | High | Target xref table and support docs already carry the xref split; SelfLookPane/UserLookPane rows verified. | Target `IDA Evidence`; support `SelfLookPane`/`UserLookPane`; report `Direct Xref / Caller Inventory` | already-present | already-present |
| C-0003F4-04 | Interior addresses have no xrefs/immediate hits, and successor refs at `0x00624ba8`/`0x00624bbc` prove the current boundary. | High | Target negative xref/boundary section already carries no-interior-ref and successor evidence. | Target `IDA Evidence`; report `Heuristic / Inference Reanalysis And Validation` | already-present | already-present |
| C-0003F4-05 | The correct ownership model is no canonical owner with two source-use emitters, not non-emitting and not sole consumer ownership. | High | Target Summary/Ownership sections and generated `-ag-memory-coverage` rows show `NONE` with emitters `0000NL,0000P0`. | Target `Summary` / `Ownership And Reconstruction`; report `Ranked Ownership Analysis` | already-present | already-present |
| C-0003F4-06 | Direct C++ should remain blank because the source shape is use-site `L"STATBUT.EPF"` in surrounding SelfLookPane/UserLookPane methods, not a standalone global declaration. | High | Target formal C++ block is blank; target Ownership section carries the no-standalone-C++ proof. | Target formal C++ block and `Ownership And Reconstruction`; report `First-Draft C++ Recommendation` | already-present | already-present |
| C-0003F4-07 | Reject sole `SelfLookPane`, sole `UserLookPane`, containing `0002V2`, `LegendPane`, synthetic shared owner, and range/merge/reclassification alternatives. | High | Target Rule 26/ownership sections and parent/support docs already preserve rejected alternatives and rationale. | Target `Rule 26 Claim Details`; report `Negative Evidence Summary` / `Ranked Ownership Analysis` | reject-invalid | already-present |
| C-0003F4-08 | Support docs already contain same-or-greater emitter context for SelfLookPane, UserLookPane, and parent split inventory. | High | `SelfLookPane.md` records eight `sub_570FC0` refs; `UserLookPane.md` records two `sub_5A0640` refs; parent inventory lists UID0003F4 as shared/no-owner with SelfLookPane/UserLookPane emission. | `Recommended Support Doc Changes` | already-present | already-present |
| C-0003F4-09 | Historical advanced-scan missing-label issue is resolved in the current target body; stale "I added" implementation wording should be treated as historical, not current action. | High | Target Range already contains `Filename label: SharedStatButtonEpfResourceString`; report body now historicalizes old wording. | `Supporting Research`; `Current Target State`; `Final Recommendation` | historicalize | already-present |
| C-0003F4-10 | Generated/tracker/lifecycle state for UID0003F4 is validator-owned and must not be repaired by B003 in this report-text pass. | High | Supervisor-owned command `000000007201` cleared the active marker; scoped validator `000000007217` refreshed generated rows; B003 made no lifecycle/manual generated edits. | `Validator Results`; `Changed Files`; `Implementation Tracking Checklist` | not-applicable | excluded-with-reason |
| C-0003F4-11 | Manual `by-memory/-coverage-report.md` and generated reports should not be hand-edited from this repair; any clearing/regeneration is supervisor/validator-owned. | High | No manual generated/coverage edits were made; generated rows refreshed only through scoped validator command `000000007217`; manual coverage remained untouched. | `Recommended Target Doc Changes`; `Recommended Support Doc Changes`; `Follow-Up Actions` | not-applicable | excluded-with-reason |
| C-0003F4-12 | This repaired report must keep validator-owned history, avoid execute/lifecycle commands, and report Gate 2 verification only. | High | `VALIDATOR-REPORT-HISTORY` footer preserved; no execute/lifecycle/report-move command run; ledger/checklist updated for callback verification. | `Validator Results`; `Changed Files`; `Implementation Tracking Checklist` | incorporate | applied |

## Positive Evidence Summary

- Exact data identity: live IDA evidence and current target docs agree on one UTF-16LE `STATBUT.EPF` string at `0x00624b90-0x00624ba8`, with bytes `53 00 54 00 41 00 54 00 42 00 55 00 54 00 2e 00 45 00 50 00 46 00 00 00`.
- Direct source-use evidence: ten xrefs push `aStatbutEpf`; eight occur in SelfLookPane2 `sub_570FC0`, and two occur in UserLookPane `sub_5A0640`.
- Corroborating decompiler evidence: both source routes pass `L"STATBUT.EPF"` into the resource-frame helper `sub_4D02F0`.
- Boundary evidence: no interior target xrefs/immediate hits exist, and adjacent successor label-string refs start at `0x00624ba8`/`0x00624bbc`.
- Documentation support: current target, SelfLookPane, UserLookPane, and the containing split-inventory page already agree on no canonical owner and two emitter routes.

## IDA MCP Facts

Session facts:

```text
session: b001_0003gy
input: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
idb: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64
imagebase: 0x00400000
auto_analysis_ready: true
hexrays_ready: true
```

Byte facts:

```text
0x00624b90-0x00624ba8:
53 00 54 00 41 00 54 00 42 00 55 00 54 00 2e 00 45 00 50 00 46 00 00 00

IDA get_string(0x00624b90): STATBUT.EPF
Size: 0x18 / 24 bytes, verified with int_convert.py
```

Function/range facts:

| Address | IDA function | Role |
| --- | --- | --- |
| `0x00570fc0` | `sub_570FC0`, size `0xc45` | SelfLookPane2 stat-button rendering/setup route. |
| `0x005a0640` | `sub_5A0640`, size `0xf3d` | UserLookPane stat-button rendering/setup route. |
| `0x00624b90` | not a function | Target UTF-16LE string. |

Pattern facts:

```text
UTF-16LE STATBUT.EPF pattern:
0x00624b90 only

UTF-16LE STATBUTS.EPF pattern:
0x00624820 only, separate SelfLookPane look-icon/nation string

UTF-16LE STAT.EPF pattern:
0x00630ee4 only, separate string outside this target

Absolute immediate 0x00624b90:
0x0057157a, 0x005715cd, 0x0057165a, 0x005716d7, 0x0057175f,
0x0057177c, 0x00571b63, 0x00571bb6, 0x005a0c74, 0x005a0ce2
```

Negative IDA facts:

- `0x00624b94`, `0x00624b98`, `0x00624b9c`, `0x00624ba0`, and `0x00624ba4` have zero xrefs.
- Immediate scans for those interior addresses have zero hits.
- `0x00624ba8` and `0x00624bbc` have SelfLookPane2-only refs and belong to successor child [UID:0003F5].

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00624788-0x00624c64` | [UID:0002V2][LookGroupCollectionResourceStringData](../../../../../by-memory/0x00624788-0x00624c64.LookGroupCollectionResourceStringData.md) | Mixed look/group/collection resource-string and constant split inventory. | `FALSE` | `NONE` | `88/92` | Non-emitting container. |
| `0x00624b74-0x00624b90` | [UID:0003F3][SelfLookPane2LookPalStringFragments](../../../../../by-memory/0x00624b74-0x00624b90.SelfLookPane2LookPalStringFragments.md) | Predecessor SelfLookPane2 local fragments. | `TRUE` | `0000NL` | current docs | Boundary support. |
| `0x00624b90-0x00624ba8` | [UID:0003F4][SharedStatButtonEpfResourceString](../../../../../by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md) | Target pooled UTF-16 `STATBUT.EPF`. | `TRUE` | `NONE`; emitters `0000NL,0000P0` | `89/92` | Repaired in this pass. |
| `0x00624ba8-0x00624bd0` | [UID:0003F5][SelfLookPane2StatButtonLabelStrings](../../../../../by-memory/0x00624ba8-0x00624bd0.SelfLookPane2StatButtonLabelStrings.md) | Successor SelfLookPane2 stat-label strings. | `TRUE` | `0000NL` | current docs | Boundary support. |
| `0x00570fc0` | [UID:0001HK][SelfLookPane2 aggregate](../../../../../by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md) | SelfLookPane2 route. | `TRUE` | `0000NL` | current docs | Proven emitter route. |
| `0x005a0640` | [UID:0001KK][UserLookPane aggregate](../../../../../by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md) | UserLookPane route. | `TRUE` | `0000P0` | current docs | Proven emitter route. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00571579` | `push offset aStatbutEpf` in `sub_570FC0` | SelfLookPane2 uses `STATBUT.EPF`. |
| `0x005715cc` | `push offset aStatbutEpf` in `sub_570FC0` | SelfLookPane2 uses `STATBUT.EPF`. |
| `0x00571659` | `push offset aStatbutEpf` in `sub_570FC0` | SelfLookPane2 uses `STATBUT.EPF`. |
| `0x005716d6` | `push offset aStatbutEpf` in `sub_570FC0` | SelfLookPane2 uses `STATBUT.EPF`. |
| `0x0057175e` | `push offset aStatbutEpf` in `sub_570FC0` | SelfLookPane2 uses `STATBUT.EPF`. |
| `0x0057177b` | `push offset aStatbutEpf` in `sub_570FC0` | SelfLookPane2 uses `STATBUT.EPF`. |
| `0x00571b62` | `push offset aStatbutEpf` in `sub_570FC0` | SelfLookPane2 uses `STATBUT.EPF`. |
| `0x00571bb5` | `push offset aStatbutEpf` in `sub_570FC0` | SelfLookPane2 uses `STATBUT.EPF`. |
| `0x005a0c73` | `push offset aStatbutEpf` in `sub_5A0640` | UserLookPane uses `STATBUT.EPF`. |
| `0x005a0ce1` | `push offset aStatbutEpf` in `sub_5A0640` | UserLookPane uses `STATBUT.EPF`. |

Decompiler context:

```text
sub_570FC0: sub_4D02F0(v1, L"STATBUT.EPF", ..., (int)v51);
sub_5A0640: sub_4D02F0(v2, L"STATBUT.EPF", ..., (int)v124);
```

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:0002V2] documents this `.rdata` island as a non-emitting split inventory and states that the `STATBUT.EPF` child crosses SelfLookPane2 and UserLookPane.
- [UID:0000NL][SelfLookPane](../../../../../by-file/SelfLookPane.md) is a valid file emitter at `85/89`, projected to `NexusTK/ui/panels/`, and owns the SelfLookPane2 source family.
- [UID:0000P0][UserLookPane](../../../../../by-file/UserLookPane.md) is a valid file emitter at `88/85`, projected to `NexusTK/ui/panels/`, and owns the UserLookPane source family.
- `by-project-structure/proposed-source-tree.md` lists both `SelfLookPane.cpp` and `UserLookPane.cpp` under `ui/panels/`.

Existing docs that were stale or incomplete:

- Historical stale state: the target page once had real text but not the exact advanced-scan label token `SharedStatButtonEpfResourceString`; the current target page now contains that token.
- Historical stale state: the target page once used the older `parent-blank, non-emitting` pooled-literal model; the current target page now uses `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000NL,0000P0`.
- Current manual/generated coverage caveat: scoped validator command `000000007217` restored UID0003F4 rows in generated memory coverage/tracker outputs, but manual `by-memory/-coverage-report.md` remains untouched and must not be hand-fixed by B003.

Generated/coverage state:

- Historical validator output from the old implementation reported an `auto-generated/-ag-memory-coverage.md` update for UID0003F4. Callback validator command `000000007217` refreshed generated memory coverage/tracker headers at `2026-07-05T16:10:22-04:00` and current rows now list UID0003F4 as no-owner `NONE` with emitters `0000NL,0000P0`; `-ag-coverage-report-by-memory.md` also has the UID0003F4 row updated at `2026-07-05 16:10:23`.
- Current recommendation: do not manually edit generated or coverage files. Generated/tracker refreshes in this callback were validator-owned side effects of the scoped file validator.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000NL,0000P0`

- Evidence for: ten direct xrefs split across two separately documented file roots; Hex-Rays shows both source-use functions passing `L"STATBUT.EPF"` to `sub_4D02F0`; no single declaration owner is proven.
- Evidence against: none strong. This leaves no canonical declaration owner, but that is the correct model for source-use pooled literals under current rules.
- Decision: accepted.

### 2. [UID:0000NL][SelfLookPane](../../../../../by-file/SelfLookPane.md) as canonical owner

- Evidence for: eight of ten target xrefs are in SelfLookPane2 `sub_570FC0`; SelfLookPane is a valid file root and clears `85/85`.
- Evidence against: two target xrefs are in UserLookPane `sub_5A0640`; no evidence says UserLookPane references a SelfLookPane-owned declaration.
- Decision: rejected as canonical owner; accepted as emitter.

### 3. [UID:0000P0][UserLookPane](../../../../../by-file/UserLookPane.md) as canonical owner

- Evidence for: two target xrefs are in UserLookPane `sub_5A0640`; UserLookPane is a valid file root and clears `85/85`.
- Evidence against: eight target xrefs are in SelfLookPane2; no evidence says SelfLookPane2 references a UserLookPane-owned declaration.
- Decision: rejected as canonical owner; accepted as emitter.

### 4. [UID:0002V2][LookGroupCollectionResourceStringData](../../../../../by-memory/0x00624788-0x00624c64.LookGroupCollectionResourceStringData.md)

- Evidence for: physical containing range and split-inventory context.
- Evidence against: it is explicitly a non-emitting mixed inventory over multiple source owners, not a source-level object that should emit this literal.
- Decision: rejected as canonical owner/emitter; kept as containing documentation context.

### 5. New by-resource/global shared `STATBUT.EPF` owner

- Evidence for: the literal names an EPF resource file and is used from two source files.
- Evidence against: no current by-resource/global page for a shared stat-button resource declaration; no IDA table, global pointer, debug path, or relocation pattern proves a common source declaration. Creating a new shared owner would be invented structure solely to avoid `NONE`.
- Decision: rejected.

### 6. Split, merge, rename, or reclassify range

- Evidence for: none. The advanced scan wording could look like a stale label, but the filename range and label are semantically correct.
- Evidence against: target is exactly one UTF-16LE `STATBUT.EPF` string; no interior xrefs; successor child refs begin at `0x00624ba8`; predecessor and successor pages already model adjacent children.
- Decision: rejected. Keep filename and range.

## Source Placement

- Recommended source placement: no standalone source declaration from UID0003F4. The literal should surface as use-site `L"STATBUT.EPF"` expressions in the reconstructed SelfLookPane and UserLookPane source routes.
- Emitter routing: keep `EMITTER_UIDS:0000NL,0000P0` because current evidence proves SelfLookPane/SelfLookPane2 and UserLookPane both use the same pooled literal.
- Why this fits source-tree context: both `SelfLookPane.cpp` and `UserLookPane.cpp` are documented under `NexusTK/ui/panels/`; the target is a shared resource filename literal consumed by methods in those source roots.
- Rejected placements: no `SelfLookPane`-only owner, no `UserLookPane`-only owner, no `0002V2` parent emission, no `LegendPane`, and no invented shared constants/resource owner.
- Remaining placement uncertainty: no historical source declaration is proven. That uncertainty supports `CANONICAL_OWNER:NONE`; it does not block source-use emission from the two proven routes.

## Negative Evidence Summary

- The exact target string has no interior xrefs and no interior immediate hits.
- The only target-start xrefs are the ten expected source-use sites.
- `STATBUTS.EPF` and `STAT.EPF` are separate strings and do not require a merge with this target.
- Consumer xrefs do not prove canonical ownership, so neither SelfLookPane nor UserLookPane can own the physical pooled cell alone.
- No by-resource, by-global, or debug/source metadata proves a shared declaration owner.
- A direct local OS read of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` was not relied on because Windows returned access denied in this session; IDA MCP `get_bytes`, `get_string`, `find_bytes`, and xref tools supplied the required byte and reference evidence from the loaded IDB.

## First-Draft C++ Recommendation

- Eligible for draft C++: no direct standalone C++ should be inserted on UID0003F4.
- Recommended code: keep the formal `RECONSTRUCTION_CPP CODE` block literally blank.
- Reason it preserves exact original behavior: the target is a pooled read-only string literal. The behavioral source is each consuming call site passing `L"STATBUT.EPF"` to the resource-frame helper, not a separately emitted declaration from this physical memory page.
- Reason it matches plausible original source shape: late-1990s/early-2000s C++ code would naturally contain string literals at the resource-loading/use sites, while the compiler/linker may pool the identical literal in `.rdata`.
- Inferred source-facing names/types: source expression `L"STATBUT.EPF"`; emitter routes `SelfLookPane`/`SelfLookPane2` and `UserLookPane`.
- Exact no-code proof: no current table, global, by-resource declaration, debug source path, or relocation grouping proves a shared source declaration for this physical cell. Adding standalone C++ would invent source structure and risk duplicate or misplaced emission.

## Final Recommendation

- Exact current recommendation: no manual by-* drift repair is required. Keep the current target page as `89/92`, no canonical owner, reconstructable, two emitters, blank optional position, and blank formal C++; the scoped validator only normalized the target header spacing.
- Exact parent/emitter assignments: keep `CANONICAL_OWNER:NONE`; keep `EMITTER_UIDS:0000NL,0000P0`; do not assign the target to SelfLookPane, UserLookPane, `0002V2`, `LegendPane`, or a synthetic shared resource owner.
- Exact items left no-owner/non-emitting: no canonical owner is proven for the physical pooled literal. This does not make it non-emitting; it emits through the two proven source-use routes.
- Historical applied changes to preserve: the prior advanced-scan implementation changed the target from `85/88`, `RECONSTRUCTABLE:FALSE`, blank emitters to `89/92`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NL,0000P0`, and added the exact label/evidence body. Those changes are already present.
- Exact future work outside this assignment: generated/coverage regeneration or final report execution only if supervisor Gate 1/Gate 2 handling authorizes it. The active revalidation marker for this report has already been cleared by supervisor-owned command `000000007201`.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md`.
- Recommendation: no target edit is required in this report-text repair. The current target already contains the exact range, bytes, xrefs, no-owner/two-emitter rationale, no-code proof, rejected alternatives, score rationale, and support-link context at same-or-greater detail.
- Metadata/score/owner/emitter/reconstructable/C++ changes: none. Keep `COMPLETION:89`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NL,0000P0`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++.
- Historical/stale assumptions to preserve as corrected: the old non-reconstructable/non-emitting pooled-literal model is superseded; the old `90/90+` direct-C++ gate wording is superseded by the stronger source-shape no-code proof; the advanced-scan missing-label issue is already fixed in the target body.
- Validator result: callback verification ran the scoped file validator from `source-3/project-documentation`: `python .\tools\validator.py --mode file --file by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md --apply --queue-timeout 240`; command id `000000007217`, timestamp `2026-07-05T16:10:22-04:00`, exit code `0`, `ok: 1`.

## Recommended Support Doc Changes

- Support path: `by-file/SelfLookPane.md`. Recommendation: no edit; it already states the SelfLookPane2 stat-button route is a required UID0003F4 use-site emitter and records eight direct refs from `sub_570FC0`.
- Support path: `by-file/UserLookPane.md`. Recommendation: no edit; it already states the UserLookPane render body is a required UID0003F4 use-site emitter and records two direct refs from `sub_5A0640`.
- Support path: `by-memory/0x00624788-0x00624c64.LookGroupCollectionResourceStringData.md`. Recommendation: no edit; it already lists `0x00624b90-0x00624ba8` as shared `STATBUT.EPF` pooled literal in the split inventory and points to UID0003F4 as the current child page.
- Coverage/generated support docs: not applicable for B003. Do not hand-edit manual coverage reports, generated reports, validator registry/state, or lifecycle/archive files in this repair.

## Score And Metadata Recommendation

- Current score/metadata: `COMPLETION:89`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NL,0000P0`, blank optional emitter position, blank C++.
- Recommended score/metadata: unchanged.
- Score rationale: `89` completion is justified by exact bytes, range, xrefs, decompiler context, boundary evidence, owner/emitter rationale, support links, and no-code proof; it remains below `90` because final surrounding function reconstruction is not complete and no standalone code belongs on this page. `92` confidence is justified because IDA bytes, xrefs, raw-pattern scans preserved in current docs, decompiler output, and support docs agree.
- Reason not higher: no historical source declaration owner is proven, generated/registry visibility for UID0003F4 remains outside this report-text repair, and surrounding SelfLookPane/UserLookPane method source is not final.
- Reason not lower: binary evidence is exact, complete for the target range, and independently corroborated by current target/support docs.
- Metadata fields to leave unchanged: all target metadata fields listed above.

## Open Questions With Attempted Resolution

- Question: should the target have a single canonical owner? Resolution: no. Direct refs cross SelfLookPane2 and UserLookPane, and no declaration/table/global owner is proven.
- Question: should UID0003F4 emit standalone C++? Resolution: no. Use-site literals in the surrounding source functions are the defensible source shape; direct standalone C++ would invent a shared declaration.
- Question: should generated/coverage files be repaired by this pass? Resolution: no. Current assignment forbids those edits and current tracker issues are validator/lifecycle-owned.
- Question: did the historical validator-owned revalidation marker contradict the technical target recommendation? Resolution: no. It was a lifecycle/registry blocker, not target-evidence disagreement, and supervisor-owned command `000000007201` has cleared it for this active artifact.
- Remaining unresolved issue: registry/generated visibility for UID0003F4 in current generated reports remains outside B003's report-text repair scope. Future evidence/action required is supervisor-authorized validator lifecycle/regeneration, not manual report editing.

## Follow-Up Actions

- Supervisor: perform Gate 1 review of this repaired report artifact. If accepted, use validator/supervisor lifecycle procedures for any later execution or generated/coverage refresh; B003 must not perform those actions.
- Supervisor/validator: if generated or manual coverage state for UID0003F4 must be refreshed, use authorized validator/lifecycle tooling after Gate 1/Gate 2 as appropriate. Do not treat this report as authorization for B003 to hand-edit generated or coverage files.
- Future research outside this assignment: sibling pooled resource literals [UID:0003EV] and [UID:0003EX] can be reviewed under the same current owner/emitter rule if separately assigned.

## Confidence

- Recommendation confidence: high.
- Score confidence: `89/92` is justified by exact bytes, complete direct xref inventory, decompiler context for both emitter routes, negative interior-reference evidence, and same-or-greater current target/support documentation.
- Remaining uncertainty: no proof of a historical shared source declaration exists. That uncertainty is exactly why the item remains `CANONICAL_OWNER:NONE` rather than being assigned to SelfLookPane, UserLookPane, or a new shared resource owner. Remaining generated/registry diagnostics stay supervisor/validator-owned.

## Validator Results

- Callback validator command run from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0003F4-SharedStatButtonEpfResourceString-advanced-scan-removed.md](0003F4-SharedStatButtonEpfResourceString-advanced-scan-removed.md). The archived block is non-authoritative and must not be executed.

- Command id: `000000007217`.
- Command timestamp: `2026-07-05T16:10:22-04:00`.
- Exit code: `0`.
- Result: `ok: 1`.
- Validator output updates: `insert_header_blank: 1`, `path_update: 1`, `completion_update: 1`, `confidence_update: 1`, `canonical_owner_update: 1`, `autogen_registry_update: 5`, `reference_index_add: 4`, `projected_stats_update: 1`, `stats_incremental_noop: 1`.
- Validator warnings: `missing_ref_uid: 3` for UID `0003F5` twice and UID `0003F3` once; these are registry/reference diagnostics outside this callback's manual-edit scope.
- Generated refresh: output reported `generated_refresh: deferred`, `generated_refresh_command_id: 000000007217`, `generated_refresh_timestamp: 2026-07-05T16:10:22-04:00`. Read-only generated headers now show `auto-generated/-ag-memory-coverage.md` and `auto-generated/-ag-coverage-report-by-memory.md` at validator command id `000000007217` / refreshed-at `2026-07-05T16:10:22-04:00`; `auto-generated/-ag-research-tracker.md` is newer at validator command id `000000007219` / refreshed-at `2026-07-05T16:12:36-04:00`. UID0003F4 rows are present in all three generated outputs checked.
- Lease status: no leases acquired. No by-* drift was found that required manual editing; the scoped validator did the only target normalization.
- Historical validator output from the prior implementation is retained as historical evidence only:
  - Historical lease command leased the target for B003; the later unlease returned `Rejected[No active lease]` because the 300-second lease had already expired.
  - Historical scoped validator command was `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md --apply`.
  - Historical result summary reported `ok: 1`, `completion_update 0003F4 ... 89`, `confidence_update 0003F4 ... 92`, `autogen_registry_update 0003F4 ... false -> true`, `autogen_registry_update 0003F4 ... -> 0000NL,0000P0`, and generated update to `auto-generated/-ag-memory-coverage.md`.
- Current lifecycle state: no live `REPORT-VALIDATION-STATUS` or `REPORT-REVALIDATION-REASON` header is present. Supervisor-owned validator command `000000007201` / `2026-07-05T16:00:53-04:00` cleared the active revalidation marker with `--no-generated-refresh`, and the footer records the `active-revalidation-cleared` event.

## Changed Files

- Current callback modified this report: `tools/leaser/Agents/Agent-B003/research/0003F4-SharedStatButtonEpfResourceString-advanced-scan.md`.
- Scoped validator normalized the target: `by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md` (`insert_header_blank` after metadata header only; accepted evidence/metadata remained unchanged).
- Validator-owned/generated side effects reported or observed: `tools/validator.ini` registry/reference updates, `project-level/-auto-completion-stats.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/-ag-research-tracker.md`.
- Not manually modified: target/support by-* docs, generated files, manual `-coverage-report.md` files, validator state, lifecycle/archive files, supervisor ledgers, or report execution/archive locations.
- Report execution/lifecycle commands in this callback: not run.

## Implementation Tracking Checklist

- [x] C-0003F4-01: Target metadata verified already present after validator `000000007217`: `89/92`, no owner, reconstructable, two emitters, blank optional position, blank C++, `Nested:0`.
- [x] C-0003F4-02: Exact range/size/bytes/string identity verified already present in target Range/IDA Evidence.
- [x] C-0003F4-03: Ten direct source-use refs verified already present in the target; SelfLookPane and UserLookPane support docs preserve the eight/two emitter split.
- [x] C-0003F4-04: Negative interior-address evidence and successor-boundary evidence verified already present in target IDA Evidence.
- [x] C-0003F4-05: No-canonical-owner/two-emitter model verified already present in target Summary/Ownership and generated rows after validator `000000007217`.
- [x] C-0003F4-06: Formal C++ block verified blank; target no-code proof states source shape is use-site literal, not standalone declaration.
- [x] C-0003F4-07: Rejected owners/range/merge/reclassification alternatives verified already present in target Rule 26/ownership text and parent/support docs.
- [x] C-0003F4-08: Support docs verified already present at same-or-greater detail: `SelfLookPane.md`, `UserLookPane.md`, and `0x00624788-0x00624c64.LookGroupCollectionResourceStringData.md`.
- [x] C-0003F4-09: Advanced-scan missing-label issue verified resolved; target Range contains `Filename label: SharedStatButtonEpfResourceString`.
- [x] C-0003F4-10: Lifecycle/generated/tracker scope verified excluded from manual edits; active report marker was cleared by supervisor command `000000007201`; scoped validator `000000007217` refreshed generated/tracker rows as validator-owned output.
- [x] C-0003F4-11: Manual coverage/generated edits excluded with reason; generated rows refreshed only by scoped validator, and manual `by-memory/-coverage-report.md` was not edited.
- [x] C-0003F4-12: Report ledger/checklist updated for callback verification; validator-owned history footer preserved; no execute/lifecycle/report-move command run.
- [x] Scoped target validator run: command id `000000007217`, timestamp `2026-07-05T16:10:22-04:00`, exit code `0`, `ok: 1`.
- [x] Generated refresh state recorded: validator reported `generated_refresh: deferred`; generated memory coverage headers show command id `000000007217` / refreshed-at `2026-07-05T16:10:22-04:00`, and `-ag-research-tracker.md` is newer at command id `000000007219` / refreshed-at `2026-07-05T16:12:36-04:00`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003F4","source_path":"executed-b-agent-research/B003/0003F4-SharedStatButtonEpfResourceString-advanced-scan.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- {"agent":"B003","command_id":"000000007183","destination_path":"tools/leaser/Agents/Agent-B003/research/0003F4-SharedStatButtonEpfResourceString-advanced-scan.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B003/0003F4-SharedStatButtonEpfResourceString-advanced-scan.md","timestamp":"2026-07-05T15:40:46-04:00"} -->
<!-- {"agent":"B003","command_id":"000000007201","details":"active returned report revalidation marker cleared after de-execution repair","event":"active-revalidation-cleared","source_path":"tools/leaser/Agents/Agent-B003/research/0003F4-SharedStatButtonEpfResourceString-advanced-scan.md","timestamp":"2026-07-05T16:00:51-04:00","uid":"0003F4"} -->
<!-- {"agent":"B003","command_id":"000000007228","destination_path":"executed-b-agent-research/B003/0003F4-SharedStatButtonEpfResourceString-advanced-scan.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0003F4-SharedStatButtonEpfResourceString-advanced-scan.md","timestamp":"2026-07-05T16:24:12-04:00","uid":"0003F4"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0003F4-SharedStatButtonEpfResourceString-advanced-scan-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0003F4-SharedStatButtonEpfResourceString-advanced-scan.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0003F4"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
