** TARGET-REPORT-UID:0003IO **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003IO **
# 0003IO SharedGmWideString Ownership / Split Research

## Finalized Report / Current Recommendation
- Current recommendation: keep `CANONICAL_OWNER:NONE` and retain `EMITTER_UIDS:0000L3,0000KU,0000M4`.
- Final disposition: reconstructable pooled UTF-16LE `GM` literal with three proven source-use emitter roots.
- Required action: no target edit, no split, no merge, no reclassification, no score change, and no coverage-report replacement required.
- Confidence: high; current `88/93` remains justified.

## Supporting Research

## Target
- Target UID: `0003IO`.
- Target path: `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md`.
- Source queue/report row: current `auto-generated/-ag-memory-coverage.md` lists this row as `no-owner`, with `CANONICAL_OWNER` `NONE` and emitters `0000L3`,`0000KU`,`0000M4`.
- Current supervisor classification: current Goal 2 no-owner memory recheck; prior B002/B003 reports were read as background, not authority.
- Current scores and parent state: `COMPLETION:88`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L3,0000KU,0000M4`, blank C++.

## Executive Recommendation
- The best disposition remains `CANONICAL_OWNER:NONE` because no single semantic declaration owner is proven for the physical pooled `L"GM"` literal.
- Keep all three emitters:
  - `0000L3` for the direct MapPane helper use at `0x00505505`.
  - `0000KU` for the direct LivingObjectPane suffix-check use at `0x00514ec5`.
  - `0000M4` for the 18 direct ObjectList helper uses from `0x0053321a` through `0x00533f19`.
- Do not assign canonical ownership to ObjectList based on xref majority, do not assign it to LivingObjectPane based on semantic suffix-check intuition, and do not assign it to MapPane based on caller dominance or physical neighborhood.
- Do not create a standalone shared constant/global. The final source should spell local `L"GM"` uses in the consuming reconstructed functions unless later source/debug evidence proves a named shared declaration.

## Supervisor Active Recheck
- Triggering instruction: recheck `[UID:0003IO] by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md`, currently no-owner with emitters `0000L3`,`0000KU`,`0000M4`, against current docs and live IDA MCP evidence.
- Split repair requirement: not required. The target is already the exact 8-byte literal child: UTF-16LE `GM`, terminator, and alignment.
- Every source-bearing child in the surrounding range is already represented: `0003IL` for `MAPNAME.EPF`, `0003IM` for `MMAPBUT.EPF`, `0003IN` for `CMAP`, and this shared `GM` child.

## Inference Research Guidance Check
- `by-structure.md` separates canonical ownership from emitter routing. That matters here because all three source-use routes are proven, but no single declaration owner is.
- `by-structure.md` allows `CANONICAL_OWNER:NONE` with multiple `EMITTER_UIDS` for pooled/shared literals; this target fits that case and is no-owner but not non-emitting.
- `inference_research.md` cautions against `.rdata` adjacency ownership. I treated the nearby `MAPNAME.EPF`, `MMAPBUT.EPF`, `CMAP`, and GameServerConfig vtable data as boundary evidence only, not ownership proof.
- Existing documentation assumptions treated as uncertain: the prior executed reports, current target prose, and generated row were all rechecked against live IDA MCP and raw PE evidence.

## Evidence Standards Used
- Evidence types used: IDA MCP `server_health`, `get_bytes`, `xref_query`, `lookup_funcs`, `entity_query`, `find_bytes`, `get_string`, `decompile`, `analyze_component`, `make_signature_for_range`, current by-* docs, generated coverage rows, and a raw PE byte/reference scan.
- The evidence is strong enough because live IDA and raw PE independently agree on one exact literal, exactly 20 direct absolute-VA code operands, no interior/tail/end references, and a separate successor vtable route.
- Stronger confidence is blocked only by absence of original source/debug proof distinguishing repeated pooled use-site literals from a hypothetical named shared declaration.

## IDA MCP Facts
- Function/range facts:
  - Active IDA MCP session: `b001_0003gy`, `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, imagebase `0x00400000`, auto-analysis ready, Hex-Rays ready.
  - `lookup_funcs` maps `0x00505505` to `sub_505430` size `0x19a`.
  - `lookup_funcs` maps `0x00514ec5` to `sub_514EA0` size `0x3d`.
  - `lookup_funcs` maps ObjectList refs to six modeled helpers: `sub_533170`, `sub_5333B0`, `sub_533600`, `sub_533850`, `sub_533A90`, and `sub_533D00`.
  - `lookup_funcs` reports `0x0061e6f8`, `0x0061e700`, and `0x0061e704` are not functions.
- Data/table/padding facts:
  - `get_bytes 0x0061e6f8 size 0x8` returns `47 00 4d 00 00 00 00 00`, i.e. UTF-16LE `GM` plus terminator/alignment.
  - `get_bytes 0x0061e6c0 size 0x50` decodes the surrounding range as UTF-16 `MAPNAME.EPF`, UTF-16 `MMAPBUT.EPF`, ANSI `CMAP`, UTF-16 `GM`, then vtable/RTTI data beginning at `0x0061e700`/`0x0061e704`.
  - `make_signature_for_range 0x0061e6f8-0x0061e700` returned unique signature `47 00 4D 00 00 00 00 00`.
  - `get_string 0x0061e6f8` returns `GM`. `entity_query strings` does not list this short literal, so direct bytes and xrefs are the authoritative evidence.
- Xref facts:
  - `xref_query to 0x0061e6f8` returns exactly 20 refs:
    `0x00505505`, `0x00514ec5`, `0x0053321a`, `0x005332b5`, `0x0053334c`, `0x00533445`, `0x00533515`, `0x005335b7`, `0x005336a5`, `0x00533738`, `0x005337d7`, `0x005338dc`, `0x0053397a`, `0x00533a1b`, `0x00533b3a`, `0x00533bfa`, `0x00533ca5`, `0x00533d9a`, `0x00533e6a`, `0x00533f19`.
  - `xref_query` reports zero refs to `0x0061e6fa`, `0x0061e6fc`, `0x0061e6fe`, and `0x0061e700`.
  - `xref_query to 0x0061e704` returns five separate successor vtable refs at `0x00503a1c`, `0x00503a5c`, `0x00504481`, `0x00514d59`, and `0x00514d8f`.
  - `find_bytes "68 F8 E6 61 00"` returns the same 20 `push 0x0061e6f8` code sites.
- Decompilation facts:
  - `sub_505430` contains `_wcsicmp(..., L"GM")` in the MapPane movement/collision/nation-mask helper body.
  - `sub_514EA0` returns `_wcsicmp(..., L"GM") == 0` in the LivingObjectPane suffix-check body.
  - The six ObjectList helpers each contain repeated `_wcsicmp(..., L"GM")` checks.
  - `analyze_component` across the eight consumer functions reports no internal call edges between them and lists `aGm` as the one shared global accessed by all eight functions.
- Negative IDA facts:
  - No xrefs to interior or tail addresses.
  - No xrefs to the target end address.
  - No common GM/name helper is evident in the component call graph.
  - No vtable, RTTI, initializer, global pointer, or source metadata proves a declaration owner for this literal.

## Raw PE Facts
- Raw PE scan target: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Imagebase: `0x00400000`.
- Target file offset: `0x0021D0F8`; target section: `.rdata`.
- Exact byte pattern `47 00 4D 00 00 00 00 00` occurs once at VA `0x0061E6F8`.
- Absolute VA dword `0x0061e6f8` occurs 20 times in `.text`, each preceded by opcode byte `0x68`, matching `push imm32`.
- RVA dword `0x0021e6f8` occurs zero times.
- Absolute interior/tail/end dwords `0x0061e6fa`, `0x0061e6fc`, `0x0061e6fe`, and `0x0061e700` occur zero times.
- Absolute successor dword `0x0061e704` occurs five times, matching the separate vtable child evidence.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0061e6f8-0x0061e700` | `0003IO` / target | Shared UTF-16LE `GM` literal | Yes | `NONE`; emitters `0000L3,0000KU,0000M4` | `88/93` | Keep current |
| `0x0061e6c0-0x0061e700` | `0003C1` / `MapNameMiniMapResourceStrings` | Mixed string-data index | No | `NONE` | `90/94` | Container only; not owner |
| `0x0061e6f0-0x0061e6f8` | `0003IN` / `MapPaneCmapSignatureString` | ANSI `CMAP` predecessor | Yes | `0000L3` | `86/92` | Separate MapPane child |
| `0x0061e700-0x0061e704` | `0003C2` / `GameServerConfigProtectedArrayRttiBoundary` | RTTI boundary dword | No | `NONE` | `85/92` | Separate successor boundary |
| `0x0061e704-0x0061e708` | `0003II` / `GameServerNationEntryProtectedArrayVtableData` | Successor vtable slot | Yes | `0000B4` | `86/93` | Separate GameServerConfig/ProtectedArray child |
| `0x00505430-0x005055ca` | part of `0001AP` | MapPane movement/collision/nation-mask helper | Yes | `00007Q` -> `0000L3` | aggregate `85/88` | Source-use emitter `0000L3` |
| `0x00514ea0-0x00514edd` | `000233` / `LivingObjectPaneGmNameSuffixCheck` | LivingObjectPane suffix helper | Yes | `0000KU` | documented exact child | Source-use emitter `0000KU` |
| `0x00532f70-0x0053728e` | `00023F` / `ObjectListExtendedTypeLookupHelpers` | ObjectList helper family | Yes | `0000M4` | `80/86` | Source-use emitter `0000M4` |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00505505` | `push offset aGm` in `sub_505430` | Direct MapPane use; supports emitter `0000L3` |
| `0x00514ec5` | `push offset aGm` in `sub_514EA0` | Direct LivingObjectPane suffix-check use; supports emitter `0000KU` |
| `0x0053321a`, `0x005332b5`, `0x0053334c` | refs in `sub_533170` | ObjectList helper uses |
| `0x00533445`, `0x00533515`, `0x005335b7` | refs in `sub_5333B0` | ObjectList helper uses |
| `0x005336a5`, `0x00533738`, `0x005337d7` | refs in `sub_533600` | ObjectList helper uses |
| `0x005338dc`, `0x0053397a`, `0x00533a1b` | refs in `sub_533850` | ObjectList helper uses |
| `0x00533b3a`, `0x00533bfa`, `0x00533ca5` | refs in `sub_533A90` | ObjectList helper uses |
| `0x00533d9a`, `0x00533e6a`, `0x00533f19` | refs in `sub_533D00` | ObjectList helper uses |
| `0x0061e700` | no refs | Clean target end boundary |
| `0x0061e704` | five successor refs | Confirms following vtable/table child should stay separate |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion:
  - Target page already records the exact literal, 20 executable refs, `CANONICAL_OWNER:NONE`, and emitters `0000L3,0000KU,0000M4`; live IDA and raw PE evidence confirm this state.
  - `by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md` documents the parent as a non-emitting mixed index over exact children with different owners/routes.
  - `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md` documents `sub_505430` as MapPane-owned movement/collision/nation-mask code.
  - `by-memory/0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md` documents the LivingObjectPane suffix helper.
  - `by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md` documents the six ObjectList helper functions as ObjectList source.
  - `by-project-structure/proposed-source-tree.md` keeps `map/MapPane.cpp`, `map/LivingObjectPane.cpp`, and `map/ObjectList.cpp` as distinct source modules.
- Existing docs that are stale, incomplete, or contradicted:
  - No current contradiction requiring repair was found.
  - Older executed reports contain legacy `AUTOGEN_PARENT_UID` wording; this pass uses the current `CANONICAL_OWNER` / `EMITTER_UIDS` model.
  - `entity_query strings` does not list this short UTF-16 literal, but `get_string`, `get_bytes`, xrefs, and raw PE search confirm it.
- Generated/coverage report state:
  - Current generated row is already correct as no-owner with emitters `0000L3`,`0000KU`,`0000M4`.
  - Current `by-memory/-coverage-report.md` row is already semantically correct and should be retained if supervisor refreshes it.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000L3,0000KU,0000M4`
- Evidence for: direct source-use xrefs in three distinct source roots, no common helper, no declaration object, no source/debug proof of a single owner, and current by-structure support for no-owner pooled literals with multiple emitters.
- Evidence against: the item is reconstructable and must emit through source-use contexts. This is handled by the three emitters and is not a reason to force a canonical owner.
- Decision: accepted. This is the best current representation.

### 2. `0000M4` ObjectList as canonical owner
- Evidence for: ObjectList accounts for 18 of 20 direct refs and the six helper bodies perform repeated `L"GM"` comparisons.
- Evidence against: MapPane and LivingObjectPane each have independent direct refs in their own helper bodies. Xref majority is not declaration ownership.
- Decision: reject canonical ownership; keep `0000M4` as an emitter.

### 3. `0000KU` LivingObjectPane as canonical owner
- Evidence for: the cleanest semantic name is the LivingObjectPane GM suffix check, and all consumers appear to inspect living/object name tails.
- Evidence against: MapPane and ObjectList do not call the LivingObjectPane suffix helper for their direct comparisons. Shared field semantics do not prove the literal declaration belongs to LivingObjectPane.
- Decision: reject canonical ownership; keep `0000KU` as an emitter.

### 4. `0000L3` MapPane as canonical owner
- Evidence for: MapPane has one direct use, owns nearby map-world code, and calls ObjectList/LivingObjectPane paths.
- Evidence against: caller dominance and broad subsystem ownership do not transfer the literal out of the LivingObjectPane or ObjectList helper bodies.
- Decision: reject canonical ownership; keep `0000L3` as an emitter.

### 5. `0003C1` physical string container as owner
- Evidence for: target is physically inside the `MapNameMiniMapResourceStrings` range.
- Evidence against: the container is intentionally non-emitting and mixed. Its children route to MapNamePane, MiniMapButtonPane, MapPane, and this shared no-owner literal.
- Decision: rejected.

### 6. New shared helper/header/global owner
- Evidence for: a source header or helper could theoretically have defined a GM suffix constant.
- Evidence against: no common function, global declaration, source path, xref table, initializer, or debug evidence proves it. Creating a shared file solely to avoid `NONE` would over-model a pooled literal.
- Decision: rejected.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: none.
- Likely full contents: not applicable.
- Candidate related items that belong: not applicable.
- Candidate related items rejected: this target should not seed an `ActorNameRules.cpp`, `ObjectNameRules.cpp`, or shared constants file based only on one pooled literal.
- Standalone, narrow, or broad source-file inference: not applicable; this is a pooled literal/source-use routing case.

## Negative Evidence Summary
- Checked and rejected interior/tail references: IDA and raw PE found zero refs to `0x0061e6fa`, `0x0061e6fc`, and `0x0061e6fe`.
- Checked and rejected target-end merge: IDA and raw PE found zero refs to `0x0061e700`; successor `0x0061e704` has five independent vtable refs.
- Checked and rejected RVA-form references: raw PE found zero `0x0021e6f8` hits.
- Checked and rejected ObjectList-only ownership: MapPane and LivingObjectPane direct refs are real.
- Checked and rejected LivingObjectPane-only ownership: MapPane and ObjectList direct refs are real.
- Checked and rejected MapPane-only ownership: LivingObjectPane and ObjectList direct refs are real.
- Checked and rejected physical container ownership: `0003C1` is a mixed non-emitting index.
- Checked and rejected new shared declaration/global ownership: no source/debug/global/init/common-helper evidence proves it.

## Final Recommendation
- Exact changes applied or recommended: created this current research report only. No by-* documentation changes are recommended.
- Exact parent assignments applied or recommended: retain `CANONICAL_OWNER:NONE`; retain `EMITTER_UIDS:0000L3,0000KU,0000M4`; retain `RECONSTRUCTABLE:TRUE`; retain `COMPLETION:88` and `CONFIDENCE:93`.
- Exact items left no-owner/non-emitting and why: `0003IO` is left no-owner but not non-emitting. It is reconstructable and routes through three emitters because source-use sites are proven in MapPane, LivingObjectPane, and ObjectList, while declaration ownership is unproven.
- Exact future work, if any, outside this assignment scope: none required for this target. Future source reconstruction should place local `L"GM"` comparisons in the consuming functions once those functions meet code-entry quality.

Retain the current target header:

```text
*** UID:0003IO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3,0000KU,0000M4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No generated row replacement is required. If the supervisor needs an exact no-op retained row, keep:

```markdown
| [UID:0003IO][0x0061e6f8-0x0061e700.SharedGmWideString](by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md) | no-owner | `NONE` | `0000L3`,`0000KU`,`0000M4` |  | no | `auto-generated/NexusTK/map/LivingObjectPane.cpp` | `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md` |  |
```

No `by-memory/-coverage-report.md` replacement is required. If the supervisor needs an exact no-op retained row, keep:

```markdown
            - [UID:0003IO][0x0061e6f8-0x0061e700.SharedGmWideString](by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md) 0x0061e6f8-0x0061e700 | string-data | SharedGmWideString : reconstructable : 88% : very strong : UTF-16LE `GM` pooled source literal with `CANONICAL_OWNER:NONE` and `EMITTER_UIDS:0000L3,0000KU,0000M4`; ownership reviews confirm 20 direct code xrefs across MapPane, LivingObjectPane, and ObjectList consumers, with no single semantic declaration owner.
```

## Follow-Up Actions
- Supervisor actions: none required beyond retaining the current row/state. The no-op rows above are included for exact supervisor application if needed.
- A-agent actions: none required.
- B002 future research actions: none for this target.

## Confidence
- Recommendation confidence: high. Live IDA MCP and raw PE evidence agree with the current no-owner/three-emitter state.
- Score confidence: current `88/93` remains appropriate. Completion stays below 90 because final source declaration placement is unresolved; confidence remains high because bytes, xrefs, and negative evidence are clean.
- Remaining uncertainty: only original-source declaration style remains unknown: repeated pooled `L"GM"` literals versus a named shared constant.

## Validator Results
- Commands run: none.
- Results: no validator run was needed because no by-* target documentation, generated report, or coverage report was edited. No dry runs were used.
- Any unresolved validator warnings/errors: none introduced by this pass.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B002/research/0003IO-SharedGmWideString-current-goal2-pass.md`.
- Modified: none.
- Renamed: none.
- Moved to executed: none.
- Leases: none acquired; no leased-scope file was edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003IO","source_path":"executed-b-agent-research/B002/0003IO-SharedGmWideString-current-goal2-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
