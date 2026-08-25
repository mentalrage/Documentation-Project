** TARGET-REPORT-UID:0003N9 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003N9 **
# 0003N9 ControlPaneDrawActiveFrameHelper Post-Migration Recheck

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](../../../../../by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) as `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, `RECONSTRUCTABLE:TRUE`, and below gate at `COMPLETION:82`, `CONFIDENCE:84`.
- Final disposition: no split, merge, reclassification, rename, parent repair, IDA repair, canonical-owner assignment, or emitter route is justified by the current evidence.
- Required action: no target metadata/text edit and no `by-memory/-coverage-report.md` edit are required.
- Confidence: high that the bytes are an exact source-shaped ControlPane-like draw helper; high that no current owner/emitter route clears the strict gate; medium that the original source intent was a private `ControlPane` helper, because that remains an inference from field/layout context rather than a proven entrypoint.

## Target

| Field | Current state / recommendation |
| --- | --- |
| Target UID | `0003N9` |
| Target path | `by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md` |
| Current generated status | reconstructable `no-owner` |
| `COMPLETION` / `CONFIDENCE` | keep `82/84` |
| `CANONICAL_OWNER` | keep `NONE` |
| `RECONSTRUCTABLE` | keep `TRUE` |
| `EMITTER_UIDS` | keep blank |
| `EMITTER_POSITION_OPTIONAL` | keep blank |

This is a post-migration owner/emitter recheck. I reviewed the prior executed reports from B003 and B002 as background, then rechecked current target docs, generated coverage, owner docs, by-structure rules, IDA MCP, and raw PE evidence.

## Executive Recommendation

Keep `0003N9` visible as reconstructable NexusTK source-shaped code, but do not route it through `ControlPane` yet.

`ControlPane` remains the best forced semantic candidate: the body tests the generic `ControlPane` state bytes at `this+0x101` and `this+0x102`, clears `this+0x70`, and draws the inherited rectangle at `this+0x44`. That is not enough for ownership/emission because the current binary evidence still provides no reachable entry mechanism: no IDA function object, no external xref, no ControlPane/ProgressBar vtable slot, no raw absolute VA/RVA pointer, and no direct branch/call into the helper start or plausible interior entry.

Because the page remains below `85/85`, it cannot receive a canonical owner under the child/direct-parent gate. Because this is executable code rather than pooled/shared source data, blank `EMITTER_UIDS` is also still correct. Adding `EMITTER_UIDS:000038` would assert that reconstructed `ControlPane` output must emit this helper, which is not proven.

The active `90/90+` C++ code-entry gate is not reached. This page is `82/84` and has no emitter route, so final reconstruction C++ should remain blank.

## Supervisor Active Recheck

- Assignment: B002 one-target post-migration no-owner memory recheck for [UID:0003N9].
- Split status: no new split is required. The exact `0x00494c50-0x00494c80` child already exists and is half-open between ignored padding and the `ProgressBarControlPane` constructor.
- Source-bearing child status: the only in-scope source-shaped child remains below gate; the report does not defer hidden split work.
- Current generated rows: `auto-generated/-ag-memory-coverage.md` lists `0003N9` as `no-owner`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`.

## Evidence Standards Used

Evidence used:

- IDA MCP `server_health`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `callees`, `entity_query`, and `make_signature_for_range`.
- Local read-only raw PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for VA/RVA pointer encodings, vtable dwords, and direct branch/call targets.
- Current docs for `ControlPane`, `ProgressBarControlPane`, `ControlFamilyStateVirtualHelpers`, exact sibling state helpers, vtable-data/type pages, ignored padding, generated memory coverage, and manual coverage report.
- Prior executed reports as background, not as authority.

`by-structure.md` is decisive here: `CANONICAL_OWNER` requires the narrowest true semantic owner that clears the evidence gate; `EMITTER_UIDS` is source-output routing, not a workaround for uncertain ownership; reconstructable no-owner/no-emitter items are acceptable while owner/emitter/source placement remains unproven.

## IDA MCP Facts

Live IDA MCP was queried against `NexusTK.exe.i64` through session `b001_0003gy`; health reported auto-analysis and Hex-Rays ready.

Function/range facts:

| Address | IDA result |
| --- | --- |
| `0x00494c30` | `sub_494C30`, size `0x1a` |
| `0x00494c4a` | not a function |
| `0x00494c50` | not a function |
| `0x00494c51` | not a function |
| `0x00494c53` | not a function |
| `0x00494c7e` | not a function |
| `0x00494c80` | `sub_494C80`, size `0x12a` |
| `0x00494db0` | not a function |

IDA `entity_query` over `0x00494a80-0x00494ec0` lists modeled starts at `0x00494b50`, `0x00494b80`, `0x00494bb0`, `0x00494bd0`, `0x00494bf0`, `0x00494c00`, `0x00494c10`, `0x00494c30`, `0x00494c80`, `0x00494de0`, and `0x00494eb0`. It still does not list `0x00494c50`.

Raw helper bytes/signature:

```text
56 8B F1 80 BE 01 01 00 00 00 74 22 80 BE 02 01 00 00 00 74 19 68 80 00 00 00 E8 F1 49 02 00 8D 46 44 C6 46 70 00 50 8B CE E8 D2 57 02 00 5E C3
```

The byte window confirms: previous helper return, six `0xcc` bytes at `0x00494c4a-0x00494c50`, the exact `0x30`-byte helper, then the constructor prologue at `0x00494c80`.

Xref/callee facts:

| Item | Result |
| --- | --- |
| `xrefs_to 0x00494c50` | zero xrefs |
| `xrefs_to 0x00494c51` / `0x00494c53` | only local sequential flow |
| `xrefs_to 0x00494c7e` | only internal short branches from `0x00494c5a`, `0x00494c63`, and local flow from `0x00494c79` |
| `xrefs_to 0x00494c80` | one code xref at `0x005472d7` |
| `callees 0x00494c50` | no function found |
| raw outgoing calls | `0x00494c6a -> 0x004b9660`; `0x00494c79 -> 0x004ba450` |

The shared GrafPort callees prove draw behavior but not source ownership; `0x004b9660` and `0x004ba450` are broad shared UI drawing helpers.

Vtable/name facts:

- IDA name query over `0x00617a80-0x00617bd4` lists `ControlPane` vtable bases at `0x00617a90`, `0x00617af8`, `0x00617b28`, followed by `ProgressBarControlPane` bases at `0x00617b34`, `0x00617b9c`, `0x00617bcc`.
- The ControlPane/ProgressBar vtable data contains neighboring helper slots such as `0x00494b80`, `0x00494bb0`, `0x00494bd0`, `0x00494c00`, `0x00494c10`, `0x00494c30`, and ProgressBar draw slot `0x00494de0`.
- No vtable dword in `0x00617a8c-0x00617bd4` equals `0x00494c50`, `0x00494c51`, or `0x00494c53`.

## Raw PE Evidence

Read-only raw PE scan:

| Check | Result |
| --- | --- |
| Image base | `0x00400000` |
| Target file offset | `0x94050` |
| VA pointer pattern for `0x00494c50`, `0x00494c51`, `0x00494c53`, `0x00494c7e` | count `0` each |
| RVA pointer pattern for the same addresses | count `0` each |
| ControlPane/ProgressBar vtable dwords equal to target start/interiors | none |
| Direct `E8/E9`, `0F 8x`, short branch targets to `0x00494c50`, `0x00494c51`, `0x00494c53` | none |

The branch scan sanity checks found expected neighboring transfers: internal branches to `0x00494c7e`, calls/jumps to `0x00494c30`, calls to `0x00494b80`, and the known constructor call to `0x00494c80` from `0x005472d7`. That makes the lack of a branch into `0x00494c50` meaningful.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00494c4a-0x00494c50` | [UID:0000VN][-ignored](../../../../../by-memory/-ignored.md) | alignment padding | FALSE | none | `100/strong` | Already ignored; no change |
| `0x00494c50-0x00494c80` | [UID:0003N9][ControlPaneDrawActiveFrameHelper](../../../../../by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) | raw ControlPane-like active-frame helper | TRUE | none | `82/84` | Keep no-owner/no-emitter |
| `0x00494c80-0x00494daa` | [UID:000119][ProgressBarControlPaneConstructor](../../../../../by-memory/0x00494c80-0x00494daa.ProgressBarControlPaneConstructor.md) | ProgressBar constructor | TRUE | [UID:0000AW][ProgressBarControlPane](../../../../../by-class/ProgressBarControlPane.md) | `86/90` | Clean successor boundary |

## Documentation Evidence And Current Status

Existing docs supporting the recommendation:

- The target page records `82/84`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, no function object, zero xrefs, exact raw helper bytes, and candidate `ControlPane` semantics.
- [UID:0002PD][ControlFamilyStateVirtualHelpers](../../../../../by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md) is a non-reconstructable mixed audit/container and lists `0003N9` as the only unresolved raw child in the split band.
- [UID:000038][ControlPane](../../../../../by-class/ControlPane.md) and [UID:0000IG][ControlPane](../../../../../by-file/ControlPane.md) list this target only as a below-gate candidate raw draw-state helper.
- [UID:0003N6][ControlPaneDeactivate](../../../../../by-memory/0x00494c10-0x00494c2a.ControlPaneDeactivate.md) and [UID:0003N7][ControlPaneActivate](../../../../../by-memory/0x00494c30-0x00494c4a.ControlPaneActivate.md) show `this+0x102` is a base `ControlPane` active/focus-like state byte, but they are routed because they have modeled function/vtable evidence that this target lacks.
- [UID:0003J8][ControlPaneVtableData](../../../../../by-memory/0x00617a8c-0x00617b30.ControlPaneVtableData.md) and [UID:0003J9][ControlPaneVtables](../../../../../by-type/by-vtable/ControlPaneVtables.md) route real ControlPane vtable slots; they do not contain `0x00494c50`.
- [UID:000119][ProgressBarControlPaneConstructor](../../../../../by-memory/0x00494c80-0x00494daa.ProgressBarControlPaneConstructor.md) confirms a clean successor boundary at `0x00494c80`.

No current by-* page proves a function object, caller, vtable/table slot, raw pointer, recovered indirect target, or source/debug breadcrumb for `0x00494c50`.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`

Evidence for:

- The child remains below `85/85`.
- No IDA function object exists at `0x00494c50`.
- No external code/data xrefs target the helper start.
- No raw VA/RVA pointer or direct transfer targets the start or plausible interior entries.
- No ControlPane or ProgressBar vtable slot contains the address.
- This is executable code, not pooled source data where `CANONICAL_OWNER:NONE` with multiple emitters could be justified by independent source-use contexts.

Evidence against:

- The helper body is strongly ControlPane-like and likely came from the base control source neighborhood.

Decision: accepted. This is the only evidence-safe post-migration state.

### 2. [UID:000038] `ControlPane` / [UID:0000IG] `ControlPane`

Evidence for:

- Best semantic candidate.
- Uses generic state bytes `+0x101` and `+0x102`.
- Uses the inherited rectangle at `+0x44` and clears `+0x70`.
- Physically adjacent to assigned ControlPane state virtuals.

Evidence against:

- No function object, no xref, no vtable slot, no raw pointer, and no caller/entry mechanism.
- Adding only `EMITTER_UIDS:000038` would still assert source output placement without proof.

Decision: best forced candidate, but rejected for current assignment.

### 3. [UID:0000AW] `ProgressBarControlPane`

Evidence for:

- Physical successor begins at `0x00494c80`.

Evidence against:

- The target ends before the constructor and does not touch ProgressBar fields `+0xf8`, `+0xfa`, or `+0xfc`.
- ProgressBar vtable data does not contain `0x00494c50`.

Decision: rejected.

### 4. ButtonControlPane / ButtonChoice family

Evidence for:

- Same broad UI-control address neighborhood.

Evidence against:

- Current barrier repairs place ButtonChoice/ButtonControl source-bearing ranges later.
- The helper uses base ControlPane state bytes, not button/choice-specific fields.

Decision: rejected.

### 5. New source file/grouping

No new source file or grouping is justified. If future evidence proves reachability, the likely home is a private `ControlPane` helper in `NexusTK/ui/core/ControlPane.cpp`, not a standalone file.

## Exact Recommendations

Target metadata: no change.

```text
COMPLETION:82
CONFIDENCE:84
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
```

Target text: no edit required.

Coverage report: no edit required. The current row already expresses the correct recommendation:

```markdown
        - [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) 0x00494c50-0x00494c80 | raw-helper | ControlPaneDrawActiveFrameHelper : reconstructable/no-owner : 82% : medium-strong : B002 second pass keeps this exact raw helper below gate: source-shaped ControlPane-like drawing body checks `this+0x101` and `this+0x102`, selects color `0x80`, clears `this+0x70`, and calls the GrafPort frame drawer for `this+0x44`, but live IDA and raw PE scans still find no IDA function object, zero external xrefs to `0x00494c50`, no ControlPane/ProgressBar vtable slot, no absolute VA/RVA pointer to the start or plausible interior entries, no direct/conditional branch into the start, and no caller/entry mechanism. Keep `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, and `RECONSTRUCTABLE:TRUE`.
```

If the supervisor wants a row wording refresh to mention this post-migration recheck, the only safe replacement is the same metadata/disposition with updated lead text:

```markdown
        - [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) 0x00494c50-0x00494c80 | raw-helper | ControlPaneDrawActiveFrameHelper : reconstructable/no-owner : 82% : medium-strong : B002 post-migration recheck keeps this exact raw helper below gate: source-shaped ControlPane-like drawing body checks `this+0x101` and `this+0x102`, selects color `0x80`, clears `this+0x70`, and calls the GrafPort frame drawer for `this+0x44`, but current IDA and raw PE scans still find no IDA function object, zero external xrefs to `0x00494c50`, no ControlPane/ProgressBar vtable slot, no absolute VA/RVA pointer to the start or plausible interior entries, no direct/conditional branch into the start, and no caller/entry mechanism. Keep `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, and `RECONSTRUCTABLE:TRUE`.
```

Missing evidence needed to route:

- IDA function object or confirmed function metadata at `0x00494c50`.
- External code/data xref, raw VA/RVA pointer, direct branch/call, table slot, vtable slot, or recovered indirect-call target.
- Source/debug/build evidence proving this helper belongs in `ControlPane.cpp` output despite absent reachability.

## Validation Results

Commands/evidence used:

- IDA MCP: `server_health`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `callees`, `entity_query`, `make_signature_for_range`.
- Local read-only PowerShell raw PE scan of `NexusTK.exe` for pointer, vtable, and branch evidence.

Not run:

- No validator command was run because no by-* documentation was edited.
- No dry-run validator mode was used.
- No memory-range validator mode was used.

## Changed Files

Created:

```text
tools/leaser/Agents/Agent-B002/research/0003N9-ControlPaneDrawActiveFrameHelper-post-migration-recheck.md
```

Modified: none outside this B002 research report.

## Blockers

No external blocker prevented the report. The target itself remains blocked below the owner/emitter gate until a real entry mechanism or source/debug proof is found.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003N9","source_path":"executed-b-agent-research/B002/0003N9-ControlPaneDrawActiveFrameHelper-post-migration-recheck.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
