** TARGET-REPORT-UID:0003P9 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003P9 **
# [UID:0003P9] SharedEpfSuffixString Current Source Routing Reanalysis

## Finalized Report / Current Recommendation

- Current recommendation: keep target metadata unchanged: `COMPLETION:87`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JA,0000L3,0000PB`, blank `EMITTER_POSITION_OPTIONAL`, and blank `RECONSTRUCTION_CPP CODE`.
- Final disposition: no canonical owner, but three confirmed source-use emitters. This is a live pooled UTF-16 `.EPF` suffix literal used by FieldMapPane, MapPane, and WorldMapPane code. It is not a non-emitting item and not a standalone shared global.
- Required action: no score, metadata, owner, emitter, split, merge, reclassification, or C++ change is justified. Supervisor should apply the exact text/coverage support corrections listed in `## Exact Supervisor Changes Needed` because current support docs and coverage still contain stale pre-emitter wording, and the target duplicate-count wording should be corrected.
- Confidence: high. The current local PE scan of the same MD5 image as the documented IDA sessions revalidates the four target-address operands, the lack of interior/successor target refs, the exact bytes, the absence of embedded debug/source breadcrumbs, and the duplicate-literal limitation.

## Supporting Research

## Target

- Assignment id: `B003-goal2-shared-epf-suffix-current-source-routing-0003P9-20260618`.
- Target UID: `0003P9`.
- Target path: `source-3/project-documentation/by-memory/0x0061a44c-0x0061a458.SharedEpfSuffixString.md`.
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0003P9-SharedEpfSuffixString-current-source-routing.md`.
- Current target state: `87/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JA,0000L3,0000PB`, blank formal C++.
- Containing current support page: [UID:00025B] `0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData`.
- Source queue/report state checked: `auto-generated/-ag-memory-coverage.md` currently lists [UID:0003P9] as `no-owner` with emitters `0000JA`,`0000L3`,`0000PB`, and the multiple-emitter section lists [UID:0000JA] FieldMapPane, [UID:0000L3] MapPane, and [UID:0000PB] WorldMapPane.

## Executive Recommendation

Keep the accepted pooled-literal route:

- `CANONICAL_OWNER:NONE` remains correct because FieldMapPane, MapPane, and WorldMapPane all directly reference the same physical address and no source/debug metadata, shared declaration, suffix table, or global constant object proves a single declaration owner.
- `EMITTER_UIDS:0000JA,0000L3,0000PB` remains correct because each emitter is a valid by-file root with direct source-use evidence:
  - [UID:0000JA] FieldMapPane through `push 0x0061a44c` at `0x004b0c12` inside the FieldMapPane constructor family.
  - [UID:0000L3] MapPane through `push 0x0061a44c` at `0x00510b2f` and `0x00511019` inside [UID:0003TL] `MapPaneHandleMapInfoTileRegionPacket`.
  - [UID:0000PB] WorldMapPane through `push 0x0061a44c` at `0x005c2df4` inside [UID:0003SC] `WorldMapPaneConstructorAndNodeSetup`.
- No additional emitters are justified. A full-image little-endian target-VA scan found exactly four operands for `0x0061a44c`, and all four correspond to the three current emitter roots. No RVA-form, interior, successor, pointer-table, or hidden direct-address route was found.
- No canonical owner/global/shared-constants file is justified. The binary contains many other `.EPF` byte-pattern hits, but those are separate physical literals or fragments, not direct refs to this address.
- Do not populate formal C++. The range represents a physical pooled `.rdata` string, while the source text belongs as use-site `L".EPF"` literals in the surrounding functions when those functions are reconstructed.

## Supervisor Active Recheck

- The user explicitly overrode the stale B003 `goal.md` assignment and assigned [UID:0003P9].
- This was report-only work. I did not edit by-* docs, generated reports/source, IDA DB, or `by-memory/-coverage-report.md`.
- IDA MCP was not reachable in this session: `Test-NetConnection 127.0.0.1:13337` failed. I therefore treated older live IDA report claims as leads only and revalidated the address-sensitive evidence with local PE scans against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- The local PE is the same image documented by the current by-* pages: size `2679296`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, image base `0x00400000`.
- Split repair is not needed. The current child range `0x0061a44c-0x0061a458` is exact: UTF-16LE `.EPF`, wide NUL, and two alignment bytes before the successor `FolderSelectDialog` RTTI locator pointer cell.

## Inference Research Guidance Check

`by-structure.md` allows `CANONICAL_OWNER:NONE` with multiple `EMITTER_UIDS` for compiler/linker-pooled string literals and shared constants when no single declaration owner is proven but multiple source-use contexts are proven. This target matches that rule exactly.

Facts, documentation evidence, and inference are separated here:

- Fact from current PE scan: the little-endian VA `0x0061a44c` appears exactly four times in the file, all as operands immediately after opcode `0x68` (`push imm32`) in `.text`.
- Fact from current PE scan: `0x0061a450`, `0x0061a452`, `0x0061a456`, and `0x0061a458` have zero VA-form hits and zero RVA-form hits.
- Documentation evidence: current by-file/by-class pages for FieldMapPane, MapPane, and WorldMapPane all clear the route gate and place those source roots under `NexusTK/map/`.
- Inference: the original source most likely had separate use-site suffix literals or macros/constants that compiled/link-pooled to one `.rdata` address. The binary does not prove a human-authored shared declaration.
- Rejected inference: a new `ResourceSuffixes.cpp`, `SharedEpfSuffixes`, by-global constant, or by-resource owner would be invented structure. No initializer, table, source path, debug marker, or global address-taken pattern supports it.

## Heuristic / Inference Reanalysis And Validation

### Generated / Fragment Names

- IDA names `aE` at `0x0061a44c` and `aPf_1` at `0x0061a450` are decoder-fragment artifacts, not source names.
- The current target filename `SharedEpfSuffixString` remains the best descriptive documentation name. It describes the physical pooled literal without pretending to know an original variable name.
- There is no source-facing helper or global name to recover for this data item. If final source later needs a local helper name, it should be chosen in the surrounding function pages, not here.

Validation:

- Current bytes at `0x0061a44c` are `2e 00 45 00 50 00 46 00 00 00 00 00`.
- There is no NUL after `.E`; the bytes are one UTF-16 `.EPF` literal. Starting IDA string decoding at `0x0061a450` naturally yields `PF` because `P 00 F 00 00 00` is an interior suffix of the same literal.
- Current local PE scan found zero VA/RVA refs to `0x0061a450`, `0x0061a452`, or `0x0061a456`, so no interior split is justified.

### Source-Use Function Names

- `sub_4B0BB0` is documented by [UID:00014Z], [UID:00004U], and [UID:0000JA] as the FieldMapPane constructor-family function. Source-facing role: `FieldMapPane::FieldMapPane(...)`.
- `sub_510960` is now exact child [UID:0003TL] `MapPaneHandleMapInfoTileRegionPacket`, routed through [UID:00007Q] MapPane and [UID:0000L3] MapPane file. Source-facing role: a MapPane map-info/tile-region packet handler that appends EPF/PAL-style resource suffixes while updating map resource strings.
- `sub_5C2AC0` is now exact child [UID:0003SC] `WorldMapPaneConstructorAndNodeSetup`, routed through [UID:0000G9] WorldMapPane and [UID:0000PB] WorldMapPane file. Source-facing role: WorldMapPane constructor/setup.

Validation:

- The source-use mapping is stronger than older B001 wording because current exact child pages exist for the MapPane and WorldMapPane functions.
- The target page's current broader references to [UID:0001AW] and [UID:0001O4] remain valid, but support can optionally add exact [UID:0003TL] and [UID:0003SC] links later.

### Range / Split / Container Decision

- Keep [UID:0003P9] as a single exact child.
- Do not split `.E` and `PF`; no interior refs exist.
- Do not merge back into [UID:00025B]; the parent is a mixed index that crosses FieldMapPane vtables, this shared literal, and a FolderSelectDialog RTTI locator pointer.
- Do not widen through `0x0061a458`; bytes at `0x0061a458` are `0c 78 64 00`, a pointer to `0x0064780c`, documented as the `FolderSelectDialog` COL pointer by [UID:0003PA].
- Do not absorb the predecessor; [UID:0003P8] separately owns `FieldMapPane` vtable data through [UID:00004U].

### Ownership / Source Placement

Accepted:

- `CANONICAL_OWNER:NONE` with emitters [UID:0000JA], [UID:0000L3], [UID:0000PB].

Rejected:

- FieldMapPane canonical owner: physical adjacency and one constructor xref are real, but MapPane and WorldMapPane direct refs block exclusive ownership.
- MapPane canonical owner: it has two refs, but by-structure explicitly warns not to force ownership to the consumer with the most xrefs when other consumers materially use the pooled item.
- WorldMapPane canonical owner: it has a constructor/resource-loading ref, but FieldMapPane and MapPane refs are equally direct.
- [UID:00025B] parent as owner/emitter: it is a non-emitting mixed `.rdata` index, not an original source owner.
- New shared suffix/global/constants owner: no binary/source-tree evidence supports one. All confirmed uses are immediate string operands, and there are many other `.EPF` physical byte-pattern hits.

### Duplicate Literal Model

The current scan found 176 total UTF-16 `.EPF\0` byte-pattern hits in the PE, including this target. That means there are 175 other physical byte-pattern hits, not 176 other hits. This matters only as negative evidence against byte-pattern ownership:

- The duplicate count does not add emitters to [UID:0003P9]; emitters require refs to `0x0061a44c`, not merely another `.EPF` byte sequence.
- The duplicate count weakens any claim that this address is a program-wide `EPF_SUFFIX` global; if a single shared global existed for all `.EPF` uses, the binary would not contain this many physical copies/fragments.
- Nearby duplicate `.EPF` hits around `0x0061a32a`, `0x0061a352`, `0x0061a3a2`, and `0x0061a5d4` are separate strings in the same broad `.rdata` neighborhood, not refs to this target.

### Final C++ Readiness

The target meets the minimum active code-entry gate in a mechanical sense: it is `RECONSTRUCTABLE:TRUE`, has nonblank emitters, and averages above 85. But final C++ is still unsafe and should remain blank because the page does not represent a standalone source declaration. A formal C++ block here would either:

- invent a global/shared declaration such as `static const wchar_t kEpfSuffix[]`, which is not proven;
- emit the same standalone declaration into three files through the multiple emitters, which would misrepresent the physical pooled literal; or
- include surrounding use-site code that belongs to other memory ranges.

Therefore the strongest source-quality decision is exact do-not-populate proof, not first-draft C++.

## Evidence Standards Used

- Current local PE parsing and byte scans of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Current target/support by-* docs.
- Current generated memory coverage state as read-only evidence.
- Prior executed B001 research used as a lead only, then revalidated against current docs and PE bytes.
- Negative evidence: no IDA MCP in this session, no source/debug markers in PE, no hidden RVA refs, no interior refs, no target pointer-table hits outside the four push operands.

## Current PE Facts

- Path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Size: `2679296`.
- MD5: `4247e04e20b65d6414c7238aa8ff5515`.
- Image base: `0x00400000`.
- Sections:
  - `.text`: VA `0x00401000-0x0060c600`, raw `0x400-0x20ba00`.
  - `.rdata`: VA `0x0060d000-0x0066c200`, raw `0x20ba00-0x26ac00`.
  - `.data`: VA `0x0066d000-0x0069ce24`, raw `0x26ac00-0x278400`.
  - `.rsrc`: VA `0x0069d000-0x006b2e00`, raw `0x278400-0x28e200`.
- Target VA: `0x0061a44c`.
- Target RVA: `0x0021a44c`.
- Target file offset: `0x218e4c`.
- Target bytes at `0x0061a44c`: `2e 00 45 00 50 00 46 00 00 00 00 00`.
- Predecessor/successor context bytes include FieldMapPane vtable slots before `0x0061a44c`, then the target literal, then `0c 78 64 00` at `0x0061a458`, the `FolderSelectDialog` RTTI locator pointer value.

## Direct Xref / Immediate Inventory

Current full-file little-endian VA scan for `0x0061a44c`:

| Operand file offset | Operand VA | Instruction start | Bytes | Source-use route |
| --- | --- | --- | --- | --- |
| `0x000b0013` | `0x004b0c13` | `0x004b0c12` | `68 4c a4 61 00` | FieldMapPane constructor-family use. |
| `0x0010ff30` | `0x00510b30` | `0x00510b2f` | `68 4c a4 61 00` | MapPane map-info/tile-region handler first use. |
| `0x0011041a` | `0x0051101a` | `0x00511019` | `68 4c a4 61 00` | MapPane map-info/tile-region handler second use. |
| `0x001c21f5` | `0x005c2df5` | `0x005c2df4` | `68 4c a4 61 00` | WorldMapPane constructor/setup use. |

Negative current scans:

| Pattern | Count | Meaning |
| --- | ---: | --- |
| VA `0x0061a44c` | 4 | Exactly the four current emitters/use sites above. |
| RVA `0x0021a44c` | 0 | No RVA-form hidden target refs. |
| VA `0x0061a450` | 0 | No direct ref to interior `PF` fragment. |
| VA `0x0061a452` | 0 | No direct interior ref. |
| VA `0x0061a456` | 0 | No direct alignment ref. |
| VA `0x0061a458` | 0 | No direct ref to successor cell address. |
| RVA `0x0021a450`, `0x0021a452`, `0x0021a456`, `0x0021a458` | 0 | No hidden RVA-form interior/successor refs. |
| `RSDS`, `NB10`, `.pdb`, `.cpp` raw markers | 0 | No embedded debug/source-path metadata found by marker scan. |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent / Emitters | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0061a44c-0x0061a458` | [UID:0003P9] SharedEpfSuffixString | pooled UTF-16 `.EPF` suffix literal | `TRUE` | `CANONICAL_OWNER:NONE`; emitters `0000JA,0000L3,0000PB` | `87/92` | keep unchanged; text corrections only |
| `0x0061a3c4-0x0061a45c` | [UID:00025B] FieldMapPaneReadOnlyData | mixed `.rdata` split index | `FALSE` | `NONE`; no emitters | `86/91` | support page has stale wording about [UID:0003P9] emitters |
| `0x0061a3c4-0x0061a44c` | [UID:0003P8] FieldMapPaneVtableData | FieldMapPane vtable island | `TRUE` | owner/emitter [UID:00004U] | `86/91` | predecessor; not a suffix owner |
| `0x0061a458-0x0061a45c` | [UID:0003PA] FolderSelectDialogRttiLocatorPointer | successor COL pointer | `TRUE` | owner/emitter [UID:000059] | `86/91` | successor; not a suffix owner |
| `0x00510960-0x00511347` | [UID:0003TL] MapPaneHandleMapInfoTileRegionPacket | MapPane source-use function | `TRUE` | owner/emitter [UID:00007Q] -> [UID:0000L3] | `86/89` | proves MapPane emitter |
| `0x005c2ac0-0x005c32aa` | [UID:0003SC] WorldMapPaneConstructorAndNodeSetup | WorldMapPane source-use function | `TRUE` | owner [UID:0000G9], emitter [UID:0000PB] | `86/90` | proves WorldMapPane emitter |
| `0x0061ea24-0x0061ea30` | [UID:0003JG] SharedMapPaletteSuffixString | accepted pooled `.PAL` suffix precedent | `TRUE` | `CANONICAL_OWNER:NONE`; emitters `0000L3,0000PB` | `87/93` | comparison model |

## Documentation Evidence And Current Status

Current target page:

- Correctly has `87/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000JA,0000L3,0000PB`.
- Correctly states no single declaration owner is proven.
- Correctly states final C++ should stay blank.
- Needs one small factual wording correction: the PE scan found 176 total UTF-16 `.EPF` byte-pattern hits including this target, not 176 other occurrences.

Current [UID:00025B] support page:

- Correctly reclassifies the parent as `RECONSTRUCTABLE:FALSE`, no owner, no emitter.
- Correctly lists the FieldMapPane vtable child, [UID:0003P9], and the FolderSelectDialog RTTI locator child.
- Stale text remains in the child table and reconstruction notes: it still says [UID:0003P9] has no canonical owner/emitter assigned yet and that source placement is not proven. That was superseded by B001's accepted report and the current target metadata.

Current `by-memory/-coverage-report.md`:

- Stale at the `00025B` row. It still lists [UID:00025B] as a reconstructable `80%` FieldMapPane-owned-style row and does not include nested [UID:0003P8], [UID:0003P9], or [UID:0003PA] rows.
- Supervisor should replace that row with the exact replacement block below.

Current `auto-generated/-ag-memory-coverage.md`:

- Current generated state is consistent with target metadata:
  - main row: [UID:0003P9] is `no-owner`, canonical `NONE`, emitters `0000JA`,`0000L3`,`0000PB`;
  - multiple-emitter section lists FieldMapPane, MapPane, and WorldMapPane file roots.
- The path column shows `auto-generated/NexusTK/map/FieldMapPane.cpp` as the first surfaced path. That does not prove FieldMapPane ownership; it is a generated-report display artifact for one of the emitter routes.

Generated source outputs:

- `auto-generated/NexusTK/map/FieldMapPane.cpp` and `WorldMapPane.cpp` are currently zero bytes, and `MapPane.cpp` does not contain this report's literal because [UID:0003P9] formal C++ is blank. This is expected and not a dead-end. The emitter route is for future use-site insertion when surrounding functions are ready.

## Ranked Ownership Analysis

### 1. No canonical owner with FieldMapPane, MapPane, WorldMapPane emitters

Evidence for:

- Four direct target-address operands exist and map exactly to the three current source-use roots.
- All operands are `push 0x0061a44c` instructions, not incidental byte matches.
- Current source roots [UID:0000JA], [UID:0000L3], and [UID:0000PB] have valid `NexusTK/map/` reconstruction paths.
- Related accepted pooled literals [UID:0003JG], [UID:0003JI], [UID:0003IO], [UID:0003G1], [UID:0003FZ], and [UID:0003F4] use the same owner/emitter split when independent source contexts share a physical literal.

Evidence against:

- Original source could have used a named constant or macro, but the binary does not prove that.
- Formal use-site C++ is not ready on this data page.

Decision: accepted. Keep metadata unchanged.

### 2. FieldMapPane as canonical owner

Evidence for:

- Physical adjacency: the literal follows FieldMapPane vtable bytes.
- One direct use at `0x004b0c12` is inside FieldMapPane construction.

Evidence against:

- MapPane and WorldMapPane have direct code refs to the same target address.
- The containing parent is now a mixed `.rdata` index, not a FieldMapPane-owned data range.
- Adjacent successor `0x0061a458` belongs to FolderSelectDialog, proving adjacency crosses ownership boundaries here.

Decision: rejected as canonical owner; keep as emitter only.

### 3. MapPane as canonical owner

Evidence for:

- MapPane has two direct refs, more than either FieldMapPane or WorldMapPane.
- The same `sub_510960` MapPane handler also uses related map suffix/resource literals.

Evidence against:

- FieldMapPane and WorldMapPane direct refs are material.
- The by-structure rule explicitly rejects assigning pooled constants to the largest consumer when other consumers materially use the same item.
- No MapPane-only declaration/table/source marker is present.

Decision: rejected as canonical owner; keep as emitter only.

### 4. WorldMapPane as canonical owner

Evidence for:

- The WorldMapPane ref is in a constructor/resource setup function.
- WorldMapPane has many owned resource strings elsewhere.

Evidence against:

- FieldMapPane and MapPane direct refs are material.
- WorldMapPane-owned resource strings at [UID:00035I] are a separate constructor-only range and do not absorb this earlier pooled target.

Decision: rejected as canonical owner; keep as emitter only.

### 5. New shared constants/global/resource-suffix file

Evidence for:

- `.EPF` is a common resource suffix and this one physical target has multiple source-use contexts.

Evidence against:

- Full-file scan found 176 total UTF-16 `.EPF` hits, so there is no single program-wide physical suffix object.
- All target refs are immediate string operands. No code loads a shared suffix table or global variable.
- No `RSDS`, `NB10`, `.pdb`, or `.cpp` marker was found.
- Proposed source-tree and current docs do not identify a shared suffix constants module.

Decision: rejected.

### 6. Additional emitters such as MapNamePane, MiniMapButtonPane, FolderSelectDialog, ProfileStorage, SelfLookPane, UserLookPane, or resource system

Evidence for:

- Many other functions/resources use `.EPF` text somewhere in the client.

Evidence against:

- They do not reference `0x0061a44c`.
- Existing docs model their own physical literals separately, for example [UID:0003IL] `MAPNAME.EPF`, [UID:0003IM] `MMAPBUT.EPF`, [UID:0003F4] `STATBUT.EPF`, and [UID:00035I] WorldMapPane constructor resource strings.

Decision: rejected. Additional emitters require direct refs to this target address, not textual similarity.

## Negative Evidence Summary

- No target interior refs: rejects `.E`/`PF` split.
- No successor-address refs: rejects absorbing `0x0061a458`.
- No RVA-form refs: rejects hidden table route through RVAs.
- No source/debug markers: rejects confirmed original source-file or declaration owner.
- Many duplicate `.EPF` physical hits: rejects program-wide shared suffix global inference.
- Current support parent crosses vtable, string, and RTTI ownership: rejects FieldMapPane adjacency ownership.
- Generated output has no C++ for this target: does not reject emitters; it only confirms the formal C++ block is blank.

## Comparison With Accepted Pooled-Literal Model

| UID | Literal / range | Current model | Relevance |
| --- | --- | --- | --- |
| [UID:0003JG] | `.PAL` at `0x0061ea24-0x0061ea30` | `CANONICAL_OWNER:NONE`, emitters `0000L3,0000PB`, blank C++ | Closest suffix precedent; same MapPane/WorldMapPane pooling behavior. |
| [UID:0003JI] | `WM2` at `0x0061ea48-0x0061ea50` | `CANONICAL_OWNER:NONE`, emitters `0000L3,0000PB`, blank C++ | Confirms shared MapPane/WorldMapPane literals use emitters, not forced ownership. |
| [UID:0003IO] | `GM` at `0x0061e6f8-0x0061e700` | `CANONICAL_OWNER:NONE`, emitters `0000L3,0000KU,0000M4`, blank C++ | Confirms multiple source families can share one physical literal and still emit through all proven roots. |
| [UID:0003G1] | `version` at `0x0060d94c-0x0060d958` | `CANONICAL_OWNER:NONE`, emitters `0000JC,0000JE,0000O5`, blank C++ | Confirms shared key literals reject a synthetic shared constants owner. |
| [UID:0003FZ] | minimap download literal group | `CANONICAL_OWNER:NONE`, emitters `0000JC,0000LE`, blank C++ | Confirms pooled grouped literals can be no-owner but not non-emitting. |
| [UID:0003F4] | `STATBUT.EPF` at `0x00624b90-0x00624ba8` | `CANONICAL_OWNER:NONE`, emitters `0000NL,0000P0`, blank C++ | Confirms `.EPF` resource filenames specifically can use no-owner/multiple-emitter routing. |

[UID:0003P9] should stay aligned with these accepted models.

## First-Draft C++ Recommendation Or Exact Do-Not-Populate Proof

Do not populate `RECONSTRUCTION_CPP CODE` for [UID:0003P9].

Exact proof:

- The target range is only the physical bytes for a pooled `.rdata` literal: `L".EPF"` plus terminator/alignment.
- The current source-use emitters are three independent file roots. A standalone declaration emitted from this page would be copied/routed outside the actual surrounding function source and would falsely imply a shared source object.
- A declaration such as `static const wchar_t kEpfSuffix[] = L".EPF";` is not proven by the binary. The binary shows immediate string operands, not loads from a named global constant.
- Surrounding use-site code belongs to FieldMapPane constructor, MapPane map-info/tile-region handler, and WorldMapPane constructor/setup pages, not this data page.
- The correct final source shape is to spell `L".EPF"` at each proven use site when those surrounding functions are reconstructed. This page should remain a routing/evidence page for the pooled physical literal.

Therefore the code-entry gate is intentionally not used here even though the target has emitters and a combined score above 85.

## Final Recommendation

- No target score change.
- No target metadata change.
- No owner/emitter change.
- No split/merge/reclassification.
- No new canonical owner, global, resource, or shared constants page.
- No additional emitters.
- No formal C++.
- Apply exact target/support/coverage text corrections below.

## Exact Supervisor Changes Needed

Do not edit generated files manually. Do not edit IDA DB. For the supervisor/A-agent applying this report, the following by-* and coverage text changes are needed.

### 1. Target Page Rebuild-Handling Text

In `by-memory/0x0061a44c-0x0061a458.SharedEpfSuffixString.md`, replace:

```text
- Rebuild handling: source-authored string literal, compiler/linker-pooled in `.rdata`
```

with:

```text
- Rebuild handling: source-declared/generated-binary pooled source-use string literal in `.rdata`; recreate as use-site `L".EPF"` text, not as a standalone global.
```

Reason: this aligns the page with current by-structure terminology and sibling pooled-literal pages.

### 2. Target Page Duplicate-Count Evidence Text

In `by-memory/0x0061a44c-0x0061a458.SharedEpfSuffixString.md`, replace the current PE-scan bullet:

```text
- Local PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` found exactly four VA immediates to `0x0061a44c`, no target/interior RVA immediates, no interior VA immediates for `0x0061a450`, `0x0061a452`, or `0x0061a456`, no `RSDS`/`NB10`/`.pdb`/`.cpp` source-debug markers, and 176 duplicate UTF-16 `.EPF` byte occurrences elsewhere in the binary.
```

with:

```text
- Local PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` found exactly four VA immediates to `0x0061a44c`, no target/interior/successor RVA immediates, no interior VA immediates for `0x0061a450`, `0x0061a452`, or `0x0061a456`, no direct VA immediate for successor cell `0x0061a458`, no `RSDS`/`NB10`/`.pdb`/`.cpp` source-debug markers, and 176 total UTF-16 `.EPF` byte-pattern hits in the image including this target (175 other physical hits).
```

Reason: the current B003 scan found 176 total hits, not 176 other hits.

### 3. Target Page Change Note

Append to the `## Changes` section of `by-memory/0x0061a44c-0x0061a458.SharedEpfSuffixString.md`:

```text
- 2026-06-18 B003 current-source-routing reanalysis: current local PE scan of MD5 `4247e04e20b65d6414c7238aa8ff5515` revalidated exactly four `push 0x0061a44c` operands at `0x004b0c12`, `0x00510b2f`, `0x00511019`, and `0x005c2df4`; found no target/interior/successor RVA refs, no interior/successor VA refs, no source/debug markers, and 176 total UTF-16 `.EPF` byte-pattern hits including this target. Metadata remains `87/92`, `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000JA,0000L3,0000PB`, with final C++ intentionally blank because the literal should surface as use-site `L".EPF"` text in the three proven source roots.
```

### 4. FieldMapPaneReadOnlyData Support Page Stale Wording

In `by-memory/0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData.md`, replace:

```text
- Rebuild handling: route vtable/RTTI/string children through their direct owners or leave shared literals unowned until the source owner is proven.
```

with:

```text
- Rebuild handling: route vtable/RTTI/string children through their direct owners; shared pooled literals may remain `CANONICAL_OWNER:NONE` while using proven source-use emitters when direct refs span multiple source roots.
```

In the exact-children table, replace the [UID:0003P9] row:

```text
| `0x0061a44c-0x0061a458` | [UID:0003P9][0x0061a44c-0x0061a458.SharedEpfSuffixString](by-memory/0x0061a44c-0x0061a458.SharedEpfSuffixString.md) | Shared UTF-16 `.EPF` suffix literal; reconstructable but no canonical owner/emitter is assigned yet. |
```

with:

```text
| `0x0061a44c-0x0061a458` | [UID:0003P9][0x0061a44c-0x0061a458.SharedEpfSuffixString](by-memory/0x0061a44c-0x0061a458.SharedEpfSuffixString.md) | Shared UTF-16 `.EPF` suffix literal; `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000JA,0000L3,0000PB` because direct refs prove FieldMapPane, MapPane, and WorldMapPane use-site routes with no single declaration owner. |
```

In `## Reconstruction Notes`, replace:

```text
- Preserve `.EPF` as a source literal, but keep [UID:0003P9][0x0061a44c-0x0061a458.SharedEpfSuffixString](by-memory/0x0061a44c-0x0061a458.SharedEpfSuffixString.md) ownerless until the shared literal source placement is proven from call-site/source-neighborhood evidence.
```

with:

```text
- Preserve `.EPF` as a no-canonical-owner source-use literal routed through [UID:0000JA][FieldMapPane](by-file/FieldMapPane.md), [UID:0000L3][MapPane](by-file/MapPane.md), and [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md); do not reassign it to FieldMapPane adjacency or a synthetic shared constants/global file.
```

Append to the `## Changes` section:

```text
- 2026-06-18 B003 current-source-routing reanalysis: refreshed stale [UID:0003P9] wording after current target metadata and local PE evidence confirmed the accepted no-owner/multiple-emitter route `0000JA,0000L3,0000PB`; the parent remains `RECONSTRUCTABLE:FALSE`, no owner, and no emitter as a mixed `.rdata` index.
```

### 5. Supervisor-Owned `by-memory/-coverage-report.md` Replacement

Replace the stale single [UID:00025B] row currently between [UID:00025A] and [UID:00025C] with this exact block:

```text
    - [UID:00025B][0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData](by-memory/0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData.md) 0x0061a3c4-0x0061a45c | mixed-rdata index | FieldMapPaneReadOnlyData : ignored : 86% : very strong : C001 live IDA refresh reclassified this historical FieldMapPane-owned aggregate as a non-emitting mixed map: exact child [UID:0003P8][0x0061a3c4-0x0061a44c.FieldMapPaneVtableData](by-memory/0x0061a3c4-0x0061a44c.FieldMapPaneVtableData.md) carries FieldMapPane vtable ownership, [UID:0003P9][0x0061a44c-0x0061a458.SharedEpfSuffixString](by-memory/0x0061a44c-0x0061a458.SharedEpfSuffixString.md) carries the shared `.EPF` suffix literal without a canonical owner but with proven emitters `0000JA,0000L3,0000PB`, and [UID:0003PA][0x0061a458-0x0061a45c.FolderSelectDialogRttiLocatorPointer](by-memory/0x0061a458-0x0061a45c.FolderSelectDialogRttiLocatorPointer.md) carries the FolderSelectDialog primary COL pointer before successor vtable [UID:00025C][0x0061a45c-0x0061a5c4.FolderSelectTreeReadOnlyData](by-memory/0x0061a45c-0x0061a5c4.FolderSelectTreeReadOnlyData.md).
        - [UID:0003P8][0x0061a3c4-0x0061a44c.FieldMapPaneVtableData](by-memory/0x0061a3c4-0x0061a44c.FieldMapPaneVtableData.md) 0x0061a3c4-0x0061a44c | vtable-data | FieldMapPaneVtableData : reconstructable : 86% : very strong : Exact FieldMapPane COL/primary/secondary/tertiary vtable child; live IDA names, raw bytes, constructor-store xrefs, and slot values prove the range and owner/emitter route through [UID:00004U][FieldMapPane](by-class/FieldMapPane.md).
        - [UID:0003P9][0x0061a44c-0x0061a458.SharedEpfSuffixString](by-memory/0x0061a44c-0x0061a458.SharedEpfSuffixString.md) 0x0061a44c-0x0061a458 | string-data | SharedEpfSuffixString : reconstructable : 87% : very strong : Exact pooled UTF-16 `.EPF` suffix literal; B003 current-source-routing recheck confirms `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000JA,0000L3,0000PB` because direct source-use refs are `0x004b0c12` in FieldMapPane constructor `sub_4B0BB0`, `0x00510b2f`/`0x00511019` in MapPane map-info/tile-region packet helper `sub_510960`, and `0x005c2df4` in WorldMapPane constructor-family `sub_5C2AC0`; local PE scan found no interior refs, no target/interior/successor RVA refs, no source/debug markers, and 176 total UTF-16 `.EPF` byte-pattern hits including this target, so final C++ remains blank and the literal should surface as use-site `L".EPF"` text through the three map file roots rather than as a standalone global.
        - [UID:0003PA][0x0061a458-0x0061a45c.FolderSelectDialogRttiLocatorPointer](by-memory/0x0061a458-0x0061a45c.FolderSelectDialogRttiLocatorPointer.md) 0x0061a458-0x0061a45c | rtti-locator-pointer | FolderSelectDialogRttiLocatorPointer : reconstructable : 86% : very strong : Exact FolderSelectDialog `vftable[-1]` complete-object-locator pointer cell; live bytes show `0x0061a458 -> 0x0064780c`, successor vtable [UID:0003BF][0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData](by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md) starts at `0x0061a45c`, and the cell routes through [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md) rather than FieldMapPane.
```

### 6. Suggested Validation After Supervisor Applies Changes

> Executable block R001 was removed from this report and preserved verbatim in [0003P9-SharedEpfSuffixString-current-source-routing-removed.md](0003P9-SharedEpfSuffixString-current-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

## Follow-Up Actions

- Supervisor: apply the exact target/support/coverage text above if still current.
- A-agent: no ownership, score, emitter, or C++ work is needed for [UID:0003P9] unless future source/debug evidence proves an actual shared declaration.
- B003 future work: none for this target after the text/coverage synchronization. Broader `.EPF` duplicate research should be a separate campaign and must not use this page as a catch-all owner.

## Confidence

- Recommendation confidence: high.
- Score confidence: keep `87/92`; current evidence supports the existing strong score but does not justify `95+` because original source declarations and final use-site C++ remain inferred.
- Remaining uncertainty: original source could have used local constants/macros or repeated literal tokens. The binary does not distinguish those source spellings. This uncertainty affects formal C++ and canonical ownership, not the current emitter route.

## Validator Results

- Commands run: none. This was report-only work and no by-* file was edited.
- Results: not applicable.
- Known validation implication: current `by-memory/-coverage-report.md` row for [UID:00025B] is stale and should be refreshed with the replacement block above.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0003P9-SharedEpfSuffixString-current-source-routing.md`.
- Modified: none outside this report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003P9","source_path":"executed-b-agent-research/B003/0003P9-SharedEpfSuffixString-current-source-routing.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
