** TARGET-REPORT-UID:0003F4 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003F4 **
# 0003F4 SharedStatButtonEpfResourceString Current Goal 2 Pass

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003F4] `by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md` unchanged.
- Final disposition: `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000NL,0000P0`, `RECONSTRUCTABLE:TRUE`, `COMPLETION:89`, `CONFIDENCE:92`, blank C++.
- Required action: no by-memory edit, no coverage-report edit, no generated-report edit, no split, no merge, no reclassification, no IDA-safe name repair.
- Confidence: high. Live IDA MCP and raw PE evidence both confirm the single physical `STATBUT.EPF` string, ten exact source-use refs, no target-interior refs, and two valid emitter roots.

This is a correct current-owner-model case: no defensible single source declaration owner is proven, but the pooled UTF-16 resource filename must emit through both proven source-use routes, [UID:0000NL] `SelfLookPane` and [UID:0000P0] `UserLookPane`.

## Supporting Research

## Target

- Target UID: `0003F4`
- Target path: `by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md`
- Target range: `0x00624b90-0x00624ba8`
- Target size: `0x18` bytes
- Entity kind: pooled UTF-16 resource filename literal
- Source queue/report row: `tools/leaser/Agents/no_owner_b-agent-tracker.md` assigns `0003F4` to Agent-B002 in the active 2026-06-14 no-owner memory sweep.
- Prior report reviewed as background only: `tools/leaser/Agents/Agent-B002/research/executed/0003F4-SharedStatButtonEpfResourceString-current-no-owner-multi-emitter-recheck.md`
- Current scores and parent state: `89/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NL,0000P0`, blank emitter position and C++.

## Executive Recommendation

Keep the current no-owner/multiple-emitter state.

The target is exactly the UTF-16LE `STATBUT.EPF` physical string at `0x00624b90-0x00624ba8`. Current IDA shows eight direct source-use refs from `SelfLookPane2` code in `sub_570FC0` and two direct source-use refs from `UserLookPane` code in `sub_5A0640`. Current source-owner docs make [UID:0000NL] `SelfLookPane` and [UID:0000P0] `UserLookPane` valid source roots, so both emitter routes are justified.

Do not set a canonical owner. The direct xrefs prove source use, not a single source declaration owner. Assigning the physical pooled cell to only `SelfLookPane` would overclaim the `UserLookPane` uses, while assigning it to only `UserLookPane` would overclaim the eight `SelfLookPane2` uses. No by-resource, by-global, table, debug/source-path, relocation, or decompilation evidence proves a shared declaration owner.

Do not enter C++. The item remains below the active `90/90+` code-entry gate and should eventually appear as use-site `L"STATBUT.EPF"` literals in the surrounding reconstructed functions rather than as a standalone global declaration on this page.

## Supervisor Active Recheck

The supervisor assignment requested one fresh B002 Goal 2 recheck for:

```text
UID: 0003F4
Target: 0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString
Current state: no-owner with existing emitters
```

No split repair is required. The target is a single exact 24-byte UTF-16 string, IDA and raw PE show no target-interior references, and the successor child starts cleanly at `0x00624ba8`.

## Inference Research Guidance Check

I applied `by-structure.md` current owner/emitter guidance:

- `CANONICAL_OWNER` records semantic ownership.
- `EMITTER_UIDS` records generated-output routing and can list multiple UIDs.
- Pooled string literals can remain `CANONICAL_OWNER:NONE` when no single declaration owner is proven, while using multiple emitters for proven source-use contexts.
- Do not create a standalone shared owner only to avoid `NONE`.
- Do not force ownership to the consumer with the most xrefs when another independent consumer materially uses the same pooled item.

I also applied `inference_research.md` guidance that merged string literals and constant pools may be linker/compiler artifacts rather than evidence of a hand-authored grouping.

Existing docs and prior reports were treated as leads. The recommendation is based on current target docs, current generated rows, related source-owner docs, live IDA MCP, and raw executable evidence.

## Evidence Standards Used

Evidence checked:

- Current target page.
- Current generated `auto-generated/-ag-memory-coverage.md` no-owner and emitter rows.
- Current manual row in `by-memory/-coverage-report.md`.
- Related by-file docs: `SelfLookPane`, `UserLookPane`, `LegendPane`.
- Related by-memory docs: containing split inventory `LookGroupCollectionResourceStringData`, predecessor `SelfLookPane2LookPalStringFragments`, successor `SelfLookPane2StatButtonLabelStrings`, `SelfLookPane2`, and `UserLookPaneAndProfilePanes`.
- `by-project-structure/proposed-source-tree.md` source placement for `SelfLookPane.cpp`, `UserLookPane.cpp`, and `LegendPane.cpp`.
- Live IDA MCP `server_health`, `lookup_funcs`, `get_bytes`, `xrefs_to`, `insn_query`, `decompile`, and source/debug regex search.
- Raw PE section mapping, byte decoding, literal occurrence scan, absolute/RVA reference scans, and interior-address reference scans.

The evidence is strong enough to keep current owner/emitter routing. It is not strong enough to prove a canonical declaration owner or to enter final C++.

## IDA MCP Facts

IDA MCP session:

- Database/session: `b001_0003gy`
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`
- Image base: `0x00400000`
- `auto_analysis_ready: true`
- `hexrays_ready: true`
- `strings_cache_ready: true`
- `strings_cache_size: 2067`

Function/range facts:

| Query | IDA result | Meaning |
| --- | --- | --- |
| `0x00570fc0` | `sub_570FC0`, size `0xc45` | `SelfLookPane2` source-use function |
| `0x00571579`, `0x005715cc`, `0x00571659`, `0x005716d6`, `0x0057175e`, `0x0057177b`, `0x00571b62`, `0x00571bb5` | inside `sub_570FC0` | eight `SelfLookPane2` target refs |
| `0x005a0640` | `sub_5A0640`, size `0xf3d` | `UserLookPane` source-use function |
| `0x005a0c73`, `0x005a0ce1` | inside `sub_5A0640` | two `UserLookPane` target refs |
| `0x00624b90`, `0x00624ba8`, `0x00624bbc` | not functions | string/data starts |

Byte facts:

```text
0x00624b90:
53 00 54 00 41 00 54 00 42 00 55 00 54 00 2e 00
45 00 50 00 46 00 00 00
```

This decodes as UTF-16LE `STATBUT.EPF`.

Neighbor bytes checked:

- `0x00624b74` decodes as UTF-16LE `SELFLOOK.PAL` with alignment before the target.
- `0x00624ba8` and `0x00624bbc` are separate successor label strings used only from `sub_570FC0`.
- `0x00624820` decodes as separate UTF-16LE `STATBUTS.EPF`.
- `0x00630ee4` decodes as separate UTF-16LE `STAT.EPF`.

Direct target xrefs:

```text
xrefs_to 0x00624b90:
- 0x00571579 in sub_570FC0
- 0x005715cc in sub_570FC0
- 0x00571659 in sub_570FC0
- 0x005716d6 in sub_570FC0
- 0x0057175e in sub_570FC0
- 0x0057177b in sub_570FC0
- 0x00571b62 in sub_570FC0
- 0x00571bb5 in sub_570FC0
- 0x005a0c73 in sub_5A0640
- 0x005a0ce1 in sub_5A0640
- more: false
- xref_count: 10
```

Negative target-interior xrefs:

```text
xrefs_to 0x00624b94: 0
xrefs_to 0x00624b98: 0
xrefs_to 0x00624b9c: 0
xrefs_to 0x00624ba0: 0
xrefs_to 0x00624ba4: 0
```

Boundary and sibling xrefs:

```text
xrefs_to 0x00624b74: 0x00571005 in sub_570FC0
xrefs_to 0x00624ba8: 0x005717ab in sub_570FC0
xrefs_to 0x00624bbc: 0x00571868 in sub_570FC0
xrefs_to 0x00624820: four refs in sub_567480
xrefs_to 0x00630ee4: 0 refs
```

Instruction evidence:

- Every target xref appears as `push offset aStatbutEpf; "STATBUT.EPF"` followed by `call sub_4D02F0`.
- The eight `sub_570FC0` refs are at `0x00571579`, `0x005715cc`, `0x00571659`, `0x005716d6`, `0x0057175e`, `0x0057177b`, `0x00571b62`, and `0x00571bb5`.
- The two `sub_5A0640` refs are at `0x005a0c73` and `0x005a0ce1`.

Decompiler observations:

`sub_570FC0` contains direct calls such as:

```text
sub_4D02F0(v1, L"STATBUT.EPF", 5 * *(_DWORD *)(this + 3464), ...)
sub_4D02F0(v1, L"STATBUT.EPF", 5 * *(_DWORD *)(this + 3468) + 1, ...)
sub_4D02F0(v1, L"STATBUT.EPF", 7, ...)
sub_4D02F0(v1, L"STATBUT.EPF", 2, ...)
sub_4D02F0(v1, L"STATBUT.EPF", 8, ...)
sub_4D02F0(v1, L"STATBUT.EPF", 3, ...)
sub_4D02F0(v1, L"STATBUT.EPF", 9, ...)
sub_4D02F0(v1, L"STATBUT.EPF", 4, ...)
```

`sub_5A0640` contains the two direct target call sites rendered through branch-selected frame indices:

```text
sub_4D02F0(v2, L"STATBUT.EPF", 8, ...)
sub_4D02F0(v2, L"STATBUT.EPF", 3, ...)
sub_4D02F0(v2, L"STATBUT.EPF", 7, ...)
sub_4D02F0(v2, L"STATBUT.EPF", 2, ...)
```

Negative IDA facts:

- No target-interior xrefs.
- No source/debug metadata from `find_regex '(?i)\\.pdb|RSDS|NB10|\\.cpp|\\.cxx|\\.h'`.
- No IDA fact links this string to a by-resource/global/table owner.

## Raw PE Facts

Raw file: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`

PE mapping:

- Image base: `0x00400000`
- Target VA: `0x00624b90`
- Target section: `.rdata`
- Target file offset: `0x223590`

Raw target bytes:

```text
53 00 54 00 41 00 54 00 42 00 55 00 54 00 2e 00 45 00 50 00 46 00 00 00
```

Decoded string:

```text
UTF-16LE "STATBUT.EPF"
```

Literal occurrence scan:

| Pattern | Count | VA hits |
| --- | ---: | --- |
| UTF-16LE `STATBUT.EPF\0` | 1 | `0x00624b90` |
| UTF-16LE `STATBUTS.EPF\0` | 1 | `0x00624820` |
| UTF-16LE `STAT.EPF\0` | 1 | `0x00630ee4` |

Reference-form scan:

```text
absolute target VA 0x00624b90 hits:
- 0x0057157a
- 0x005715cd
- 0x0057165a
- 0x005716d7
- 0x0057175f
- 0x0057177c
- 0x00571b63
- 0x00571bb6
- 0x005a0c74
- 0x005a0ce2

RVA-form 0x00224b90 hits:
- none

absolute interior hits:
- 0x00624b94: none
- 0x00624b98: none
- 0x00624b9c: none
- 0x00624ba0: none
- 0x00624ba4: none
```

The raw operand addresses are one byte after the IDA instruction starts because they point at the immediate bytes of the `push offset` instructions.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00624788-0x00624c64` | `0002V2` `LookGroupCollectionResourceStringData` | mixed resource/string/constant split inventory | false | `NONE` | `88/92` in current docs | container only, not emitter |
| `0x00624b74-0x00624b90` | `0003F3` `SelfLookPane2LookPalStringFragments` | predecessor `SELFLOOK.PAL` fragments | true | `0000NL` | current docs `85/88` | SelfLookPane2-local neighbor |
| `0x00624b90-0x00624ba8` | `0003F4` target | pooled UTF-16 `STATBUT.EPF` | true | `NONE`; emit `0000NL,0000P0` | `89/92` | keep current state |
| `0x00624ba8-0x00624bd0` | `0003F5` `SelfLookPane2StatButtonLabelStrings` | successor stat-button label strings | true | `0000NL` | current docs `85/88` | SelfLookPane2-local neighbor |
| `0x0056fe80-0x005729c3` | `0001HK` `SelfLookPane2` | SelfLookPane2 method range | true | `0000NL`; emit `0000NL` | `82/86` | contains eight target use sites |
| `0x0059f260-0x005a2523` | `0001KK` `UserLookPaneAndProfilePanes` | UserLookPane method range | true | `0000P0`; emit `0000P0` | `84/86` | contains two target use sites |
| `by-file/SelfLookPane.md` | `0000NL` | source root `NexusTK/ui/panels/SelfLookPane.cpp` | file root | `FILE` | `85/89` | proven emitter |
| `by-file/UserLookPane.md` | `0000P0` | source root `NexusTK/ui/panels/UserLookPane.cpp` | file root | `FILE` | `88/85` | proven emitter |
| `by-file/LegendPane.md` | `0000KM` | shared child pane source candidate | file root | `FILE` | current docs | rejected for this literal |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00571579` | `sub_570FC0` pushes `aStatbutEpf`, then calls `sub_4D02F0` | SelfLookPane2 emitter route |
| `0x005715cc` | same | SelfLookPane2 emitter route |
| `0x00571659` | same | SelfLookPane2 emitter route |
| `0x005716d6` | same | SelfLookPane2 emitter route |
| `0x0057175e` | same | SelfLookPane2 emitter route |
| `0x0057177b` | same | SelfLookPane2 emitter route |
| `0x00571b62` | same | SelfLookPane2 emitter route |
| `0x00571bb5` | same | SelfLookPane2 emitter route |
| `0x005a0c73` | `sub_5A0640` pushes `aStatbutEpf`, then calls `sub_4D02F0` | UserLookPane emitter route |
| `0x005a0ce1` | same | UserLookPane emitter route |
| `0x00624b94` through `0x00624ba4` | no xrefs | no split at target interior |
| `0x00624ba8`, `0x00624bbc` | refs from `sub_570FC0` only | successor child is SelfLookPane2-local |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target page already records `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000NL,0000P0`, exact bytes, ten target refs, negative interior refs, and score rationale.
- `auto-generated/-ag-memory-coverage.md` currently lists the target as no-owner with owner `NONE` and emitters `0000NL,0000P0`.
- `by-memory/-coverage-report.md` currently has the correct no-owner/multi-emitter row for `0003F4`.
- `by-file/SelfLookPane.md` is `85/89`, has valid reconstruction path `NexusTK/ui/panels/`, and documents `SelfLookPane2` as part of the self-look source family.
- `by-file/UserLookPane.md` is `88/85`, has valid reconstruction path `NexusTK/ui/panels/`, and documents the remote-character look/profile panel family.
- `by-memory/0x00624788-0x00624c64.LookGroupCollectionResourceStringData.md` documents the physical island as a non-emitting mixed split inventory and explicitly identifies `STATBUT.EPF` as shared across SelfLookPane2 and UserLookPane.
- `by-memory/0x00624b74-0x00624b90.SelfLookPane2LookPalStringFragments.md` and `by-memory/0x00624ba8-0x00624bd0.SelfLookPane2StatButtonLabelStrings.md` support the current exact boundaries.
- `by-project-structure/proposed-source-tree.md` keeps `SelfLookPane.cpp`, `UserLookPane.cpp`, and shared `LegendPane.cpp` as separate source candidates.

Existing docs that are stale, incomplete, or contradicted:

- No current by-* target docs were contradicted by this pass.
- The prior B002 report remains compatible as background, but this report uses fresh current evidence.

Generated/coverage report state:

Current generated no-owner row:

```markdown
| [UID:0003F4][0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString](by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md) | no-owner | `NONE` | `0000NL`,`0000P0` |  | no | `auto-generated/NexusTK/ui/panels/SelfLookPane.cpp` | `by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md` |  |
```

Current generated emitter row:

```markdown
| [UID:0003F4][0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString](by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md) | `by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md` | [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md), [UID:0000P0][UserLookPane](by-file/UserLookPane.md) |  | `auto-generated/NexusTK/ui/panels/SelfLookPane.cpp` |  |
```

Current no-owner queue row:

```markdown
| [UID:0003F4][0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString](by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md) | no-owner | `by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md` | `0000NL`,`0000P0` | `auto-generated/NexusTK/ui/panels/SelfLookPane.cpp` |  |
```

These generated rows are correct. The `SelfLookPane.cpp` generated path is not a canonical ownership claim; the emitter row correctly preserves both output routes.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000NL,0000P0`

Evidence for:

- Live IDA shows the same physical string referenced from both `sub_570FC0` and `sub_5A0640`.
- Raw PE scan shows exactly ten absolute target operands matching the ten IDA xrefs.
- The string pattern occurs once in `.rdata`, making this a shared physical cell rather than two separate source-local copies.
- `SelfLookPane` and `UserLookPane` both clear the source-root emitter gate and both have valid `NexusTK/ui/panels/` reconstruction paths.
- No source declaration owner, global, resource-page owner, or table owner is proven.
- `by-structure.md` explicitly supports no-owner/multiple-emitter routing for pooled string literals.

Evidence against:

- None material. The absence of a canonical owner is the accurate representation of current evidence.

Decision:

- Accepted. Keep current state.

### 2. [UID:0000NL] `SelfLookPane` as canonical owner

Evidence for:

- Eight of ten target xrefs are inside `sub_570FC0`, which is documented under the SelfLookPane2 source family.
- The predecessor and successor children around the target are SelfLookPane2-local.
- `SelfLookPane` is a valid source root at `85/89`.

Evidence against:

- Two direct target xrefs are inside `UserLookPane` function `sub_5A0640`.
- No evidence shows `UserLookPane` importing or relying on a `SelfLookPane`-owned declaration.
- By-structure says not to force ownership to the consumer with the most xrefs when another consumer materially uses the same pooled item.

Decision:

- Reject as canonical owner. Keep as emitter.

### 3. [UID:0000P0] `UserLookPane` as canonical owner

Evidence for:

- Two direct target xrefs are inside `sub_5A0640`, documented under `UserLookPane`.
- `UserLookPane` is a valid source root at `88/85`.

Evidence against:

- Eight direct target xrefs are inside `SelfLookPane2`.
- No evidence shows `SelfLookPane2` importing or relying on a `UserLookPane`-owned declaration.
- Assigning canonical ownership to UserLookPane would overclaim the SelfLookPane2 source-use route.

Decision:

- Reject as canonical owner. Keep as emitter.

### 4. [UID:0002V2] `LookGroupCollectionResourceStringData` as owner/emitter

Evidence for:

- It physically contains the target and documents the mixed island.

Evidence against:

- It is `RECONSTRUCTABLE:FALSE`, mixed-owner, and non-emitting.
- It is an inventory/container, not a source declaration owner or generated source root.

Decision:

- Reject as canonical owner and emitter.

### 5. [UID:0000KM] `LegendPane` or a broader look/status shared source

Evidence for:

- Project docs note `LegendPane` is shared by self-look and user-look paths.

Evidence against:

- The direct target xrefs are in `SelfLookPane2` and `UserLookPane` methods, not `LegendPane`.
- No target use goes through `LegendPane::LegendPane` or its vtable/source data.
- The string is a stat-button resource filename used by look-pane render/setup, not legend pane construction.

Decision:

- Reject.

### 6. New by-resource/global shared `STATBUT.EPF` owner

Evidence for:

- The literal names a resource file and is shared by two source roots.

Evidence against:

- No by-resource page, global object, constant table, relocation pattern, debug/source path, or decompilation evidence proves a real shared source declaration.
- Creating a new owner solely to avoid `NONE` would violate by-structure guidance.

Decision:

- Reject.

## Split / Merge / Reclassification Analysis

- Split rejected: `0x00624b90-0x00624ba8` is the exact UTF-16LE `STATBUT.EPF` string and terminator. IDA and raw PE show no interior refs.
- Merge rejected: merging with the predecessor or successor would combine SelfLookPane2-local strings with a shared pooled literal. Merging into `0002V2` would undo the mixed-island split.
- Reclassification rejected: the target is a source-authored/generated-binary string literal, not a function, vtable, pointer table, or broad container.
- IDA-safe name repair rejected: `SharedStatButtonEpfResourceString` accurately describes the shared stat-button EPF resource string.
- Range repair rejected: live bytes, raw PE bytes, and xrefs confirm the current half-open range.

## Negative Evidence Summary

Checked and rejected:

- Target interior starts `0x00624b94`, `0x00624b98`, `0x00624b9c`, `0x00624ba0`, and `0x00624ba4`: no IDA xrefs and no raw absolute operand hits.
- `STATBUTS.EPF` at `0x00624820`: separate string with four xrefs in `sub_567480`, not this target.
- `STAT.EPF` at `0x00630ee4`: separate string with no current IDA xrefs.
- `SelfLookPane` sole ownership: overclaims `UserLookPane`.
- `UserLookPane` sole ownership: overclaims `SelfLookPane2`.
- `LegendPane` and broader shared look/status owner: no direct target refs.
- New shared resource/global owner: no evidence beyond pooled use.
- Target RVA-form refs: none in raw PE.
- Source/debug metadata: none found by IDA regex search.

## Exact Required Edits

No direct documentation edits are required.

No `by-memory/-coverage-report.md` replacement is required. Retain the current row exactly:

```markdown
            - [UID:0003F4][0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString](by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md) 0x00624b90-0x00624ba8 | pooled UTF-16 resource filename literal | SharedStatButtonEpfResourceString : reconstructable : 89% : very strong : B003 advanced-scan repair reclassified the shared `STATBUT.EPF` literal from non-reconstructable/non-emitting to `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000NL,0000P0`; live IDA confirms exact UTF-16LE bytes, ten direct xrefs to `aStatbutEpf` (eight from SelfLookPane2 `sub_570FC0`, two from UserLookPane `sub_5A0640`), no interior target refs, and separate successor label-string refs at `0x00624ba8`/`0x00624bbc`.
```

No target header replacement is required. Retain:

```text
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NL,0000P0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

## Follow-Up Actions

- Supervisor actions: none needed for this target; no shared-report text application is required.
- A-agent actions: none for this target.
- B002 future research actions: none unless a future pass finds source-symbol or resource-table evidence for a shared declaration owner.

## Confidence

- Recommendation confidence: high.
- Score confidence: keep `89/92`.
- Remaining uncertainty: exact original declaration style. The binary proves shared physical pooling and source-use routes, but not whether original code repeated the literal at each use or referenced an unmodeled shared helper. Current by-structure rules favor `NONE` plus emitters until that declaration owner is proven.

## Validator Results

- Commands run: none.
- Results: not applicable because no by-memory, by-file, by-class, coverage, generated, or project-level documentation files were edited.
- Dry runs: none used.
- Unresolved validator issues introduced by this work: none.

## Lease State

- Created the new B002 root report placeholder first.
- Leased `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\0003F4-SharedStatButtonEpfResourceString-current-goal2-pass.md` as `B002` before writing this final report body.
- No by-* documentation lease was needed or acquired.
- Report-file lease released after writing and verification; final current-lease check found no `B002`, `0003F4`, `SharedStatButtonEpfResourceString`, or `00624b90` entries.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/0003F4-SharedStatButtonEpfResourceString-current-goal2-pass.md`
- Modified: none outside the B002 research report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003F4","source_path":"executed-b-agent-research/B002/0003F4-SharedStatButtonEpfResourceString-current-goal2-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
