** TARGET-REPORT-UID:0002P4 **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# UID0002P4 LoadImageFrameTable Source-Quality Report


## Finalized Report / Current Recommendation

- Current recommendation: implemented by B010 callback; UID0002P4 now emits source-shaped first-draft `LoadImageFrameTable(const wchar_t *resourcePath, int mergeMode)` body in `ImageFrameTable.cpp`.
- Final disposition: canonical owner/emitter UID0000K1 and reconstructable state were preserved; target metadata is now `89/92`.
- Required action: supervisor Gate 2/execution verification. B010 did not run `execute_report` or lifecycle/archive commands.
- Confidence: high for behavior, ownership, range, and target signature; medium-high for exact final source spelling because DATFile declarations and original enum/container names remain inferred first-draft names.

## Target

- UID: `0002P4`
- Target doc: `by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md`
- Function: `sub_4D0F50`, `0x004d0f50-0x004d15c5`, size `0x675`
- Current metadata after callback: `COMPLETION:89`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000K1`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000K1`, blank emitter position
- Current generated path: `auto-generated/NexusTK/render/ImageFrameTable.cpp`
- Current generated state after callback: `auto-generated/NexusTK/render/ImageFrameTable.cpp` contains the first-draft UID0002P4 body and shows `Completion:89 | Confidence:92` after validator refresh through command `000000005904`.
- Assignment source: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`, row `85/89`, combined `87.0`, reconstructable `true`, reports `0`, agents blank.
- Current supervisor classification: post-Gate-1 implementation callback completed by B010; returned for supervisor Gate 2/execution verification.
- Current parent state: source family owner UID0000K1 emits `auto-generated/NexusTK/render/ImageFrameTable.cpp`; UID0002P4 is no longer comment-only in generated output.

## Executive Recommendation

UID0002P4 should no longer remain comment-only. The current MCP pass and current support docs support a source-shaped first-draft C++ body for `LoadImageFrameTable(const wchar_t *resourcePath, int mergeMode)` under owner/emitter UID0000K1.

Recommended target metadata: `COMPLETION:89`, `CONFIDENCE:92`, preserving `CANONICAL_OWNER:0000K1`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000K1`.

The previous hard no-code rationale is stale as a hard blocker. It correctly identified the difficult areas in DATFile method spelling and merge-mode object-array cleanup, but current sibling implementations for `LoadTileEpfMetadata` and `BuildEffectArchiveTable` already accept the same source-facing DATFile array, shard-header, `swprintf`, `HasDATEntry`, `Open`/`Read`/`Seek`/`GetDataPointer`/`Close`, sentinel, and cleanup pattern as first-draft C++. UID0002P4 has a larger prefix switch and a direct-mode path, but those are now implementation details rather than source-safety blockers.

Remaining uncertainty should cap confidence, not block a formal body: exact original enum names, exact helper container spelling if the original source wrapped the arrays, and final DATFile member declarations are still not final source imports. The first-draft should avoid raw `sub_`, `off_`, `dword_`, and `unknown_libname` labels and should use established source-facing names.

## Supporting Research

- Skill and assignment: Agent-B010 followed the project-level `ntk-b-agent-workflow` instructions and the current `goal.md` assignment for UID0002P4.
- MCP session: evidence was refreshed after supervisor MCP restart using session `3a33af0b`. `server_health` returned `ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays available, and strings cache ready.
- Target docs read: `by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md`.
- Support docs read: `by-file/ImageFrameTable.md`, `by-item/LoadImageFrameTable_004D0F50.md`, `by-file/DATFile.md`, `by-class/DATFile.md`, `by-memory/0x0049c130-0x0049d2cc.DATFile.md`, `by-item/EPFArchiveMetadataTable.md`, `by-memory/0x004d1b80-0x004d1f22.LoadTileEpfMetadata.md`, `by-item/BuildEffectArchiveTable_004DE420.md`, and current generated `auto-generated/NexusTK/render/ImageFrameTable.cpp`.
- Historical report read: `executed-b-agent-research/B006/0000K1-ImageFrameTable-empty-emitter-family-source-quality.md`. Its no-code proof is useful historical context, but current sibling formal bodies supersede its object-array/EH cleanup blocker as a hard blocker for UID0002P4.
- Generated context before callback: `ImageFrameTable.cpp` was validator-refreshed at `2026-07-03T22:48:22-04:00` by command id `000000005831`; it contained the shared UID0000UN declarations and formal bodies for UID0002P5, UID0002P6, UID00031T, and UID00031U, while UID0002P4 remained comment-only. After callback, `ImageFrameTable.cpp` refreshed through command `000000005904` and contains the UID0002P4 first-draft body at `89/92`.
- Callback write-scope note: by-* docs were edited only after supervisor Gate 1 passed and an implementation callback was issued. Generated/project-level outputs were updated only by scoped validators. No generated file, coverage report, validator state, lifecycle state, archive, or supervisor ledger was manually edited. No `execute_report`, lifecycle, or archive command was run by B010.

## Current Target State

The target doc now contains strong behavioral documentation and first-draft formal C++: direct and merge modes, 18 EPF prefix families, the misspelled `NECLACE` literal, DATFile lifecycle, payload rebasing, sentinel setup, cleanup, two-stack-argument target signature, and an owner decision for `ImageFrameTable`.

The prior target state was over-conservative. It said a formal body was not source-safe until DATFile method declarations and merge-mode object-array/EH cleanup shape were stabilized. That historical B006 conclusion has now been superseded in the target and support docs because sibling source docs use accepted first-draft source shapes for the same DATFile method family and merge-mode object-array lifecycle.

The target is now a formal first-draft implementation, not a raw decompiler transcription. The C++ block below was inserted into the target's formal `RECONSTRUCTION_CPP CODE` block with source-facing names and retained confidence caps for exact type-import details.

## Supervisor Active Recheck

- Triggering instruction: supervisor reported MCP had been restarted and verified, then ordered B010 to resume UID0002P4, redo/update the MCP-backed evidence pass with session `3a33af0b`, and return a Gate 1 report without fallback-only finalization.
- Split repair requirement: none. MCP and padding checks confirmed the assigned target range ends at `0x004d15c5`, with padding before neighboring helpers at `0x004d15d0` and `0x004d1600`.
- Source-bearing children: none created or recommended. UID0002P4 should remain the source-bearing by-memory target under UID0000K1; `by-item/LoadImageFrameTable_004D0F50.md` remains support/index only.
- Forbidden actions observed: no generated manual edits, coverage edits, validator-state edits, lifecycle/archive commands, supervisor-ledger edits, or `execute_report` were run. By-* edits and scoped validators occurred only during the approved implementation callback.

## Inference Research Guidance Check

- IDA fact was separated from documentation evidence and inference. MCP facts establish range, callers, callees, literals, direct/merge behavior, DATFile lifecycle, payload rebasing, cleanup, and caller argument shape.
- Documentation evidence was used for source-facing names and accepted project style: `DATFile`, `ArchiveMetadataTable`, `PackedArchiveRecord`, `InitRectBounds`, `HasDATEntry`, sibling `LoadTileEpfMetadata`, and sibling `BuildEffectArchiveTable`.
- Inference was limited to source-shaped first-draft names such as `resourcePath`, `mergeMode`, `archiveName`, `ImageArchiveShardHeader`, `archives`, and `headers`; these replace raw decompiler temporaries and helper labels.
- Existing documentation assumptions revalidated: the old UID0002P4 no-code conclusion remains useful historical context but is stale as a hard blocker because sibling formal bodies now cover the same DATFile array and cleanup pattern.
- Wave2/Wave3 artifacts were not used as evidence. Current by-* docs, generated output, historical B006 context, and MCP-backed binary evidence controlled the recommendation.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Reanalysis result | Disposition |
|---|---|---|---|
| Raw generated helper labels | MCP callees include `sub_49C130`, `sub_49C180`, `sub_49C310`, `sub_49C260`, `sub_49C240`, `sub_49C160`, and allocator/free helpers. | Raw helper labels are binary evidence only; support docs and sibling bodies provide source-facing DATFile method names. | Replace with `DATFile::Open`, `Read`, `Seek`, `GetDataPointer`, and `Close`; do not emit raw labels. |
| Function signature | MCP caller disassembly shows two stack pushes before calls while `ecx` is loaded with `dword_67A744` in several callers. | The target does not read `ecx`; the source-facing signature should not include `g_pEPFLib`. | Use `LoadImageFrameTable(const wchar_t *resourcePath, int mergeMode)`. |
| Direct mode | MCP decompile/disassembly show `mergeMode == 0` path opening one DAT archive and reading table/records. | Existing no-code text correctly documented behavior but did not need to keep the body blank. | Emit direct-mode branch in formal C++. |
| Merge mode | MCP shows 18-mode switch, `%s%d.EPF`, 100-shard cap, shard headers, DATFile array, merged records, and reverse cleanup. | The switch and loop are source-shapeable; no split or child target is needed. | Emit merge-mode branch in formal C++. |
| Prefix names | MCP string bytes and decompile identify 18 prefixes including `NECLACE`. | Names are direct binary literals; typo must be preserved. | Emit exact literals; reject spelling correction. |
| DATFile array/EH cleanup | Historical B006 treated compiler-lowered object-array cleanup as a blocker. Current sibling formal bodies use source arrays. | The blocker is resolved for first draft, but exact original container/helper spelling remains a confidence cap. | Emit `new []` / `delete []` first-draft source shape. |
| Ownership/source placement | Current generated path and support file place the family in `NexusTK/render/ImageFrameTable.cpp`. | Consumer xrefs do not make this a consumer-owned method. | Keep UID0000K1 owner/emitter. |
| Source-quality names | Decompiler names such as `ArgList`, `v42`, `v57`, `v56`, and `unknown_libname_19` are not source quality. | Descriptive names can be inferred from roles without pretending exact original local names are known. | Use descriptive first-draft local names and keep confidence cap. |

Unresolved issues after this reanalysis are not hard blockers: exact final DATFile declarations, exact enum/constant type names, and whether the original source used a small helper container around arrays remain unknown, but current evidence is strong enough for first-draft source.

## Evidence Standards Used

- IDA MCP evidence was treated as strongest for binary facts: function boundaries, bytes/padding, decompile/disassembly behavior, xrefs, callees, string references, caller argument shape, and cleanup order.
- Existing by-* documentation was used for project source-facing names, ownership, emitted file placement, related declarations, and accepted sibling source style.
- Generated output was used only to establish current emission state and sibling body precedent; generated code did not override MCP when a call signature appeared stale.
- Historical B-agent reports were used as prior hypothesis and blocker context, not as current proof when contradicted or superseded by newer docs/MCP evidence.
- Negative evidence was required for ownership and signature: consumer xrefs, `ecx` loads, DATFile dependencies, and support/index docs were checked and rejected as ownership or extra-parameter proof.
- Confidence is capped because MCP does not prove original local variable names, exact enum declarations, or final DATFile class declaration spelling.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed: `server_health`, `lookup_funcs`, `analyze_function`, `callees`, `xrefs_to`, `decompile`, `disasm`, caller disassembly around representative callsites, and `get_bytes` for padding and key wide strings.
- MCP session evidence: session `3a33af0b`, server health `ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, imagebase `0x400000`, Hex-Rays available, target `sub_4D0F50` size `0x675`.
- Docs checked: target `by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md`, `by-file/ImageFrameTable.md`, `by-item/LoadImageFrameTable_004D0F50.md`, DATFile class/file/memory docs, `by-item/EPFArchiveMetadataTable.md`, sibling tile/effect loader docs, generated `ImageFrameTable.cpp`, research tracker row, and historical B006 report.
- Negative checks performed: checked whether `0x004d15c5` begins another function, whether callers pass `g_pEPFLib` as a stack argument, whether DATFile or consumer classes should own the function, and whether the historical no-code blocker still stands after sibling formal bodies.
- Failed or skipped checks: initial old-schema MCP calls were not used as evidence; schema-current MCP calls were rerun successfully. During the later approved callback, scoped validators were run for every edited by-* file and are recorded under `Validator Results`.

## MCP Evidence

MCP session `3a33af0b` produced the following target-specific evidence:

- `lookup_funcs`: `0x004d0f50` is `sub_4D0F50`, size `0x675`; `0x004d15c5` is not a function and is followed by `0xcc` padding. Neighbor functions start at `0x004d15d0` and `0x004d1600`.
- `analyze_function`: prototype `_DWORD *__stdcall(wchar_t *ArgList, int)`, size `1653`, 89 basic blocks, cyclomatic complexity `40`, 25 xrefs, 18 callees.
- `callees`: `sub_516030`, `sub_49C130`, `sub_41B9B0`, `sub_49C700`, `unknown_libname_19`, `??2@YAPAXI@Z`, `sub_516050`, `sub_4F4AA0`, `sub_49C550`, `sub_4B7C50`, `sub_5C7526`, `j_j_j___free_base`, `sub_49C180`, `sub_49C310`, `sub_49C260`, `sub_49C240`, `sub_49C160`, and `@__security_check_cookie@4`.
- `xrefs_to`: 25 code xrefs, including 18 calls from the image-frame preload routine at `0x004d2720` and seven direct consumer calls at `0x004dc707`, `0x004dd109`, `0x004ff859`, `0x0055a694`, `0x0055a849`, `0x0055ab76`, and `0x0055b704`.
- `get_bytes`: `0x004d15c5` and `0x004d15fc` are `0xcc` padding, confirming the documented target range. String bytes confirm `HEAD` at `0x0061b778`, `NECLACE` at `0x0061b828`, and `%s%d.EPF` at `0x0061b850`.
- Caller disassembly: callers load `ecx` with `dword_67A744` before the call in several places, but pass only two stack arguments. Example `0x004dc707` pushes `0` and `offset aRidingsEpf`; `0x004ff859` pushes `0` and `[ebp+ArgList]`; overlay constructors at `0x0055a694`, `0x0055a849`, and `0x0055ab76` do the same pattern. UID0002P4 itself does not read `ecx`, so the source-facing target signature should be two-argument, not `LoadImageFrameTable(g_pEPFLib, name, mode)`.

## Disassembly And Decompiler Findings

The function has two source-relevant modes:

- Direct mode: `mergeMode == 0`. It constructs one stack `DATFile`, opens `resourcePath`, reads the 8-byte archive table header into a 12-byte `ArchiveMetadataTable`, reads a 4-byte record-table offset, obtains the archive data pointer, seeks to the record table, allocates `frameCount + 1` records at 24 bytes each, reads and rebases per-frame payload offsets, writes a sentinel record, closes the archive, destroys the stack DATFile, and returns the table.
- Merge mode: `mergeMode` in `1..18`. It chooses a wide prefix, formats `%s%d.EPF`, probes up to 100 shards with `HasDATEntry`, allocates shard headers and DATFile instances, opens every shard, reads 8-byte shard headers, accumulates total frame count and maximum dimensions, allocates the merged record table plus sentinel, reads per-shard record offsets and per-frame records, rebases payload offsets by each shard base pointer, writes the sentinel from the final shard base plus final record-table offset, closes DATFiles in reverse order, frees arrays, and returns the table.

The merge-mode prefix table is:

| Mode | Prefix |
|---:|---|
| 1 | `HEAD` |
| 2 | `HEADSP` |
| 3 | `BODY` |
| 4 | `SWORD` |
| 5 | `SPEAR` |
| 6 | `BOW` |
| 7 | `FAN` |
| 8 | `SHIELD` |
| 9 | `ARROW` |
| 10 | `FACE` |
| 11 | `HAIR` |
| 12 | `ACE1` |
| 13 | `ACE2` |
| 14 | `HELMET` |
| 15 | `MANTLE` |
| 16 | `NECLACE` |
| 17 | `SHOES` |
| 18 | `COAT` |

Invalid nonzero modes return `0` after DATFile stack cleanup. The typo `NECLACE` is binary-backed and should be preserved.

## Positive Evidence Summary

- Direct binary facts support the chosen recommendation: UID0002P4 has one coherent function range, one direct-mode path, one merge-mode switch, bounded EPF shard probing, record allocation/rebasing, sentinel construction, and cleanup.
- Corroborating documentation supports source shape: UID0000UN emits the table/record declarations, DATFile docs name the archive helper class, and sibling loaders already emit accepted first-draft C++ for DAT-backed EPF table construction.
- Strongest inference chain: MCP proves the exact behavior and caller signature; current docs provide source-facing names; sibling formal bodies prove the prior DATFile array cleanup blocker is no longer fatal. Together those justify a formal first-draft body with confidence caps rather than a no-code proof.

## IDA MCP Facts

- Function/range facts: `sub_4D0F50`, range `0x004d0f50-0x004d15c5`, size `0x675`, followed by `0xcc` padding.
- Data/table/padding facts: wide strings include `HEAD`, `NECLACE`, and `%s%d.EPF`; merge mode has 18 prefixes and a 100-shard cap.
- Xref facts: 25 code xrefs; 18 preload calls from `0x004d2720`; seven representative direct consumer calls at `0x004dc707`, `0x004dd109`, `0x004ff859`, `0x0055a694`, `0x0055a849`, `0x0055ab76`, and `0x0055b704`.
- Vtable/global/type facts: decompile shows DATFile-style stack object and array instances with open/read/seek/close/data-pointer roles; caller `ecx = dword_67A744` loads are not consumed as target arguments.
- Negative IDA facts: `0x004d15c5` is not a function; the target does not read `ecx`; no evidence supports a DATFile-owned or consumer-owned method.

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion: `by-file/ImageFrameTable.md` assigns the source family to `NexusTK/render/`; UID0000UN declares archive table structures; tile/effect sibling loaders show accepted first-draft DAT-backed loader style.
- Existing docs that are stale, incomplete, or contradicted: UID0002P4's comment-only no-code wording and historical B006 hard blocker wording should be historicalized because current sibling bodies resolve the DATFile array/EH cleanup concern for first draft.
- Generated/coverage report state: before callback, generated `ImageFrameTable.cpp` included UID0002P4 as comment-only. After callback and generated refresh through command `000000005904`, it includes the first-draft UID0002P4 formal body and shows `Completion:89 | Confidence:92`.

## Dependency Resolution

| Dependency | Current disposition | Evidence |
|---|---|---|
| DATFile stack object | Resolved for first draft | Target constructs/destructs one stack `DATFile`; support docs name the DATFile class and method family. |
| DATFile array in merge mode | Resolved for first draft | Sibling loaders already use `DATFile *archives = new DATFile[shardCount]` first-draft source shape for the same pattern. |
| DATFile method declarations | Resolved for first draft with confidence cap | Support docs identify open/read/seek/close/data-pointer roles; sibling formal bodies already use source-facing names. Exact final declarations remain a source-import cap. |
| `HasDATEntry` | Resolved | Same helper appears in sibling source-shaped loaders; target probes `%s%d.EPF` names until missing or count reaches 100. |
| Wide formatting helper | Resolved | Target uses `%s%d.EPF` into a 20-wchar buffer, matching sibling `swprintf(archiveName, 20, L"...")` source shape. |
| Archive table declarations | Resolved | UID0000UN emits `ArchiveMetadataTable` and `PackedArchiveRecord` declarations used by generated `ImageFrameTable.cpp`. |
| Record rectangle helper | Resolved | Existing docs use `InitRectBounds`; target writes top/left/bottom/right into each record and sentinel. |
| Merge-mode cleanup/EH | Resolved for first draft | Binary has compiler-lowered construction/destruction and partial cleanup. Sibling loader callback accepted source-shaped arrays rather than raw EH lowering. |
| Caller signature | Resolved | MCP callers pass two stack args. `ecx = dword_67A744` is not consumed by UID0002P4 and should not appear as a target argument. |

## Ranked Ownership Analysis

### 1. UID0000K1 ImageFrameTable

- Evidence for: current target metadata, generated `NexusTK/render/ImageFrameTable.cpp`, `by-file/ImageFrameTable.md`, UID0000UN shared declarations, and sibling formal bodies in the same source family.
- Evidence against: none that affects ownership; DATFile dependency calls and consumer xrefs are expected for a loader.
- Decision: best and final owner/emitter candidate.

### 2. DATFile

- Evidence for: UID0002P4 constructs DATFile objects and uses DATFile read/seek/close/data-pointer behavior.
- Evidence against: the function assembles ImageFrameTable archive metadata, chooses image EPF prefixes, and returns archive metadata tables; DATFile owns archive primitives only.
- Decision: rejected as dependency/support owner only.

### 3. Consumer classes and ImageLib/global EPF library

- Evidence for: many consumers call the loader and several callers load `ecx = dword_67A744` before the call.
- Evidence against: callers pass only two stack args; UID0002P4 does not consume `ecx`; consumers store returned tables rather than owning the loader.
- Decision: rejected as owner and rejected as proof of a three-argument target signature.

## Source Placement

UID0002P4 belongs in `NexusTK/render/ImageFrameTable.cpp` under canonical owner/emitter UID0000K1. Positive evidence is the generated file placement, support `by-file/ImageFrameTable.md`, shared UID0000UN archive declarations, and sibling formal bodies in the same generated file.

Rejected placements:

- DATFile: dependency owner only. The target orchestrates DATFile reads but is an ImageFrameTable loader.
- ImageLib or `g_pEPFLib`: caller residue only. MCP caller disassembly shows `ecx = dword_67A744` loads before two-argument calls, but the target does not consume `ecx`.
- Human, Riding, Static, UI, Effects, and overlay classes: consumers only. They call the loader or store returned tables.
- `by-item/LoadImageFrameTable_004D0F50.md`: support/index page only, not the emitting owner.
- Broad aggregate owner: unnecessary because UID0000K1 already owns the source family and generated file.

Remaining placement uncertainty: none that changes source file or owner. Only exact local names and final declaration spelling remain first-draft confidence caps.

## Negative Evidence Summary

- Checked and rejected `LoadImageFrameTable(g_pEPFLib, resourcePath, mergeMode)` for UID0002P4. Caller `ecx` loads are not stack arguments and the target does not read `ecx`.
- Checked and rejected DATFile ownership. DATFile methods are dependencies, not the table loader's source owner.
- Checked and rejected Riding, Effects, overlays, UI panes, Human, Static, and other consumers as owners. Their xrefs show use/storage of returned tables only.
- Checked and rejected continuing the broad unresolved DATFile/EH blocker as current truth. It is historical after accepted sibling formal bodies.
- Checked and rejected raw `sub_49C130`, `sub_49C180`, `unknown_libname_19`, `off_61B828`, and similar labels for formal source.
- Checked and rejected correcting `NECLACE` to `NECKLACE`; the misspelling is direct binary string evidence.

## Recommended Target Doc Changes

For `by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md`:

- Set `COMPLETION:89` and `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:0000K1`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000K1`, and blank emitter position unless the supervisor has a project-level reason to set one.
- Replace the blank/comment-only formal body with the exact formal `RECONSTRUCTION_CPP CODE` block from this report, including the required header, begin, and end markers.
- Update item summary and evidence paragraphs to state that the old no-code blockers are now resolved for first draft by current support docs and accepted sibling source bodies.
- Preserve precise MCP facts: range `0x004d0f50-0x004d15c5`, size `0x675`, 25 xrefs, 18 callees, direct mode, merge mode, 18 prefixes, `NECLACE`, `%s%d.EPF`, 100-shard probe cap, DATFile lifecycle, payload rebasing, reverse close cleanup, and sentinel behavior.
- Preserve negative evidence rejecting DATFile/ImageLib/consumer/broad aggregate ownership and rejecting raw `sub_`, `off_`, `dword_`, and `unknown_libname` labels in source.
- Add a note that callers may load `ecx = g_pEPFLib` before the call, but MCP evidence supports a two-stack-argument source signature for the target.

## Recommended Support Doc Changes

For `by-file/ImageFrameTable.md`:

- Update UID0002P4 from comment-only/no-code to first-draft-ready after B010 MCP refresh.
- Historicalize the B006 no-code conclusion as superseded for this target by current sibling formal bodies and support docs.
- Keep owner UID0000K1 and path `NexusTK/render/`.

For `by-item/LoadImageFrameTable_004D0F50.md`:

- Keep it non-emitting/index support, but update the source-quality note so the exact implementation route points to UID0002P4's first-draft target body rather than a no-code proof.
- Note the two-argument target signature and that `g_pEPFLib`/`ecx` loads in callers are not target parameters.

For `by-item/EPFArchiveMetadataTable.md`:

- If stale, add a narrow note that UID0002P4 uses the existing `ArchiveMetadataTable` and `PackedArchiveRecord` declarations. No metadata change is recommended solely from this pass.

For consumer support docs that still spell calls as `LoadImageFrameTable(g_pEPFLib, name, mode)`:

- Update only where directly stale. The binary caller pattern supports `LoadImageFrameTable(name, mode)` as the target-facing signature, while `g_pEPFLib` remains relevant to other helpers such as layout lookup. Do not broaden this into consumer reimplementation.

## Score And Metadata Recommendation

| Field | Current | Recommended | Reason |
|---|---:|---:|---|
| `COMPLETION` | `85` | `89` | Behavior and source shape are now sufficient for a formal first-draft body; exact final source import details remain open. |
| `CONFIDENCE` | `89` | `92` | MCP evidence confirms range, mode behavior, callers, callees, literals, and sibling-precedent source shapes. |
| `CANONICAL_OWNER` | `0000K1` | `0000K1` | ImageFrameTable remains the correct source owner. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | No evidence supports downgrading reconstructability. |
| `EMITTER_UIDS` | `0000K1` | `0000K1` | Target should emit in `ImageFrameTable.cpp`. |

## First-Draft C++ Recommendation

Eligible for draft C++: yes. MCP evidence resolves behavior and current support docs/sibling bodies provide enough source-facing names for a first-draft formal block. The block below is the exact recommended formal `RECONSTRUCTION_CPP CODE` insertion text, including the target header/begin/end wrapper. It is not an illustrative side snippet.

Reason it preserves behavior: it keeps the direct-mode archive path, merge-mode prefix switch, 100-shard probe cap, DATFile open/read/seek/data-pointer/close lifecycle, record payload rebasing, sentinel construction, reverse close order, and exact `NECLACE` literal.

Reason it matches plausible source shape: it uses existing project-facing helper names and sibling loader conventions instead of decompiler temporaries or compiler-lowered EH cleanup.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ArchiveMetadataTable *LoadImageFrameTable(const wchar_t *resourcePath, int mergeMode)
{
    struct ImageArchiveShardHeader
    {
        unsigned short frameCount;
        unsigned short maxWidth;
        unsigned short maxHeight;
        unsigned short reserved;
    };

    if (mergeMode == 0)
    {
        DATFile archive;
        ArchiveMetadataTable *table = new ArchiveMetadataTable;

        archive.Open(resourcePath);
        archive.Read(table, 8);

        int recordTableOffset = 0;
        archive.Read(&recordTableOffset, sizeof(recordTableOffset));

        unsigned char *payloadBase = archive.GetDataPointer();
        archive.Seek(recordTableOffset, 1);

        table->records = new PackedArchiveRecord[table->frameCount + 1];
        PackedArchiveRecord *record = table->records;

        for (unsigned int index = 0; index < table->frameCount; ++index, ++record)
        {
            short top = 0;
            short left = 0;
            short bottom = 0;
            short right = 0;
            unsigned int payloadStart = 0;
            unsigned int payloadEnd = 0;

            archive.Read(&top, sizeof(top));
            archive.Read(&left, sizeof(left));
            archive.Read(&bottom, sizeof(bottom));
            archive.Read(&right, sizeof(right));
            archive.Read(&payloadStart, sizeof(payloadStart));
            archive.Read(&payloadEnd, sizeof(payloadEnd));

            InitRectBounds(&record->bounds, top, left, bottom, right);
            record->payloadStart = payloadBase + payloadStart;
            record->payloadEnd = payloadBase + payloadEnd;
        }

        InitRectBounds(&record->bounds, 0, 0, 0, 0);
        record->payloadStart = payloadBase + recordTableOffset;
        record->payloadEnd = payloadBase + recordTableOffset;

        archive.Close();
        return table;
    }

    const wchar_t *prefix = 0;
    switch (mergeMode)
    {
    case 1:
        prefix = L"HEAD";
        break;
    case 2:
        prefix = L"HEADSP";
        break;
    case 3:
        prefix = L"BODY";
        break;
    case 4:
        prefix = L"SWORD";
        break;
    case 5:
        prefix = L"SPEAR";
        break;
    case 6:
        prefix = L"BOW";
        break;
    case 7:
        prefix = L"FAN";
        break;
    case 8:
        prefix = L"SHIELD";
        break;
    case 9:
        prefix = L"ARROW";
        break;
    case 10:
        prefix = L"FACE";
        break;
    case 11:
        prefix = L"HAIR";
        break;
    case 12:
        prefix = L"ACE1";
        break;
    case 13:
        prefix = L"ACE2";
        break;
    case 14:
        prefix = L"HELMET";
        break;
    case 15:
        prefix = L"MANTLE";
        break;
    case 16:
        prefix = L"NECLACE";
        break;
    case 17:
        prefix = L"SHOES";
        break;
    case 18:
        prefix = L"COAT";
        break;
    default:
        return 0;
    }

    int shardCount = 0;
    wchar_t archiveName[20];
    while (shardCount < 100)
    {
        swprintf(archiveName, 20, L"%s%d.EPF", prefix, shardCount);
        if (!HasDATEntry(archiveName))
            break;
        ++shardCount;
    }

    ImageArchiveShardHeader *headers = shardCount != 0 ? new ImageArchiveShardHeader[shardCount] : 0;
    DATFile *archives = shardCount != 0 ? new DATFile[shardCount] : 0;
    ArchiveMetadataTable *table = new ArchiveMetadataTable;
    table->frameCount = 0;
    table->maxWidth = 0;
    table->maxHeight = 0;
    table->reserved = 0;
    table->records = 0;

    for (int shardIndex = 0; shardIndex < shardCount; ++shardIndex)
    {
        swprintf(archiveName, 20, L"%s%d.EPF", prefix, shardIndex);
        archives[shardIndex].Open(archiveName);
        archives[shardIndex].Read(&headers[shardIndex], 8);

        table->frameCount += headers[shardIndex].frameCount;
        if (table->maxWidth < headers[shardIndex].maxWidth)
            table->maxWidth = headers[shardIndex].maxWidth;
        if (table->maxHeight < headers[shardIndex].maxHeight)
            table->maxHeight = headers[shardIndex].maxHeight;
    }

    table->records = new PackedArchiveRecord[table->frameCount + 1];
    PackedArchiveRecord *record = table->records;
    unsigned char *lastPayloadBase = 0;
    int lastRecordTableOffset = 0;

    for (int shardIndex = 0; shardIndex < shardCount; ++shardIndex)
    {
        int recordTableOffset = 0;
        archives[shardIndex].Read(&recordTableOffset, sizeof(recordTableOffset));

        unsigned char *payloadBase = archives[shardIndex].GetDataPointer();
        archives[shardIndex].Seek(recordTableOffset, 1);

        for (unsigned int frameIndex = 0; frameIndex < headers[shardIndex].frameCount; ++frameIndex, ++record)
        {
            short top = 0;
            short left = 0;
            short bottom = 0;
            short right = 0;
            unsigned int payloadStart = 0;
            unsigned int payloadEnd = 0;

            archives[shardIndex].Read(&top, sizeof(top));
            archives[shardIndex].Read(&left, sizeof(left));
            archives[shardIndex].Read(&bottom, sizeof(bottom));
            archives[shardIndex].Read(&right, sizeof(right));
            archives[shardIndex].Read(&payloadStart, sizeof(payloadStart));
            archives[shardIndex].Read(&payloadEnd, sizeof(payloadEnd));

            InitRectBounds(&record->bounds, top, left, bottom, right);
            record->payloadStart = payloadBase + payloadStart;
            record->payloadEnd = payloadBase + payloadEnd;
        }

        lastPayloadBase = payloadBase;
        lastRecordTableOffset = recordTableOffset;
    }

    InitRectBounds(&record->bounds, 0, 0, 0, 0);
    record->payloadStart = lastPayloadBase + lastRecordTableOffset;
    record->payloadEnd = lastPayloadBase + lastRecordTableOffset;

    for (int shardIndex = shardCount - 1; shardIndex >= 0; --shardIndex)
        archives[shardIndex].Close();

    delete [] archives;
    delete [] headers;
    return table;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## No-Code Proof

No no-code proof remains necessary for UID0002P4. The target is first-draft safe if the implementation callback uses the source-shaped body above and keeps the remaining uncertainties as confidence caps. A no-code outcome would now require a new contradiction, such as evidence that the accepted sibling DATFile source shape is invalid project-wide or that the target signature has a hidden source parameter consumed outside the MCP-visible function body. Current MCP evidence shows neither.

## Final Recommendation

- Exact changes applied: UID0002P4 target metadata is `89/92`, UID0000K1 owner/emitter/reconstructable state is preserved, and the comment-only formal block was replaced with the first-draft C++ block in this report.
- Exact parent assignment recommended: keep UID0002P4 under UID0000K1 `ImageFrameTable`; do not assign it to DATFile, ImageLib, consumers, by-item support, or a broad aggregate owner.
- Exact items left no-owner/non-emitting: none in the assigned target range. `by-item/LoadImageFrameTable_004D0F50.md` remains non-emitting support/index documentation.
- Exact future work outside this assignment: final DATFile declaration import and exact enum/container naming can be refined later, but they should not block UID0002P4 first-draft emission.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Best supported resolution | Remaining impact |
|---|---|---|---|
| Does UID0002P4 require a third `g_pEPFLib` argument? | MCP caller disassembly and target decompile/disassembly. | No. Callers load `ecx` but pass only two stack args; target does not consume `ecx`. | Support docs with stale three-argument spelling should be normalized if in callback scope. |
| Are DATFile method names/source declarations final enough? | DATFile support docs and sibling loader formal bodies. | Good enough for first draft using `Open`, `Read`, `Seek`, `GetDataPointer`, `Close`. | Confidence cap only until final DATFile import. |
| Is merge-mode object-array/EH cleanup a hard blocker? | Historical B006 report and current tile/effect sibling loader bodies. | No. Current accepted sibling bodies use source-shaped arrays for the same pattern. | Confidence cap for exact original helper/container spelling. |
| Should the loader remain no-code? | Target doc, generated output, MCP behavior, sibling precedent. | No. The function is eligible for formal first-draft C++. | No hard blocker remains. |
| Should `NECLACE` be corrected? | MCP string bytes and decompile. | No. Preserve exact binary literal. | None. |

## Follow-Up Actions

- Supervisor actions: perform Gate 2 verification against this report, changed by-* docs, scoped validator output, and generated freshness; if accepted, run supervisor-owned report execution lifecycle.
- A-agent actions: none requested by this callback.
- B010 future callback actions: none pending for accepted UID0002P4 scope. B010 stops at `READY_FOR_SUPERVISOR_EXECUTE`.

## Confidence

- Recommendation confidence: high. Binary behavior, source placement, and target ownership are directly supported.
- Score confidence: medium-high. `89/92` reflects a formal first-draft-ready target while preserving caps for exact final DATFile declarations and source naming.
- Remaining uncertainty: exact original enum names, exact original array/container helper spelling, and final DATFile declaration import.

## Validator Results

Scoped validators run during the approved implementation callback:

| Command | Command ID | Timestamp | Exit | ok | Notes |
|---|---|---|---:|---:|---|
| `python .\tools\validator.py --mode file --file by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md --apply --queue-timeout 240` | `000000005901` | `2026-07-03T23:46:32-04:00` | `0` | `1` | Applied `COMPLETION:89`, `CONFIDENCE:92`; autogen registry updated; generated refresh deferred. |
| `python .\tools\validator.py --mode file --file by-file/ImageFrameTable.md --apply --queue-timeout 240` | `000000005904` | `2026-07-03T23:46:38-04:00` | `0` | `1` | Support page validated; generated refresh deferred. |
| `python .\tools\validator.py --mode file --file by-item/LoadImageFrameTable_004D0F50.md --apply --queue-timeout 240` | `000000005907` | `2026-07-03T23:46:55-04:00` | `0` | `1` | Non-emitting support page validated; stats row updated. |
| `python .\tools\validator.py --mode file --file by-file/Effects.md --apply --queue-timeout 240` | `000000005909` | `2026-07-03T23:47:03-04:00` | `0` | `1` | Validated with pre-existing `missing_ref_uid` warnings for `0003HA`, `0003HB`, `0003HC`, and `0003HD`. |
| `python .\tools\validator.py --mode file --file by-class/OverlayMovingImageEffecter.md --apply --queue-timeout 240` | `000000005910` | `2026-07-03T23:47:16-04:00` | `0` | `1` | Consumer signature wording validated. |
| `python .\tools\validator.py --mode file --file by-class/OverlayImageOnPointEffecter.md --apply --queue-timeout 240` | `000000005911` | `2026-07-03T23:47:25-04:00` | `0` | `1` | Consumer signature wording validated. |
| `python .\tools\validator.py --mode file --file by-class/OverlayFrameImageEffecter.md --apply --queue-timeout 240` | `000000005912` | `2026-07-03T23:47:32-04:00` | `0` | `1` | Consumer signature wording validated. |
| `python .\tools\validator.py --mode file --file by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md --apply --queue-timeout 240` | `000000005913` | `2026-07-03T23:47:42-04:00` | `0` | `1` | Validated with pre-existing `missing_ref_uid` warnings including `0003O9`, `0003OA`, `0003OB`, `0003HA`, `0003HB`, `0003HC`, and `0003HD`; 16 additional rows were suppressed by validator output. |
| `python .\tools\validator.py --mode file --file by-file/ImageFrameTable.md --apply --queue-timeout 240` | `000000005918` | `2026-07-03T23:52:13-04:00` | `0` | `1` | Rerun after final stale-wording cleanup; generated refresh deferred. |
| `python .\tools\validator.py --mode file --file by-item/LoadImageFrameTable_004D0F50.md --apply --queue-timeout 240` | `000000005919` | `2026-07-03T23:52:18-04:00` | `0` | `1` | Rerun after final stale-wording cleanup; stats row updated; generated refresh deferred. |

Generated freshness checks:

- `python .\tools\validator.py --queue-status` command `000000005914` at `2026-07-03T23:47:55-04:00` showed generated refresh jobs queued/processing.
- `python .\tools\validator.py --queue-status` command `000000005915` at `2026-07-03T23:48:14-04:00` showed `auto-generated/NexusTK/render/ImageFrameTable.cpp` refreshed through command `000000005901`, with UID0002P4 at `89/92`.
- `python .\tools\validator.py --queue-status` command `000000005916` at `2026-07-03T23:48:43-04:00` showed `auto-generated/NexusTK/render/ImageFrameTable.cpp` refreshed through command `000000005904`, header `validator-refreshed-at: 2026-07-03T23:46:38-04:00`, UID0002P4 at `Completion:89 | Confidence:92`, and the first-draft body present. The old `Source body for LoadImageFrameTable remains intentionally blank` marker was absent.
- `python .\tools\validator.py --queue-status` command `000000005920` at `2026-07-03T23:52:48-04:00` showed generated queue empty and `auto-generated/NexusTK/render/ImageFrameTable.cpp` refreshed through command `000000005918`, header `validator-refreshed-at: 2026-07-03T23:52:13-04:00`, UID0002P4 at `Completion:89 | Confidence:92`, and no old comment-only marker.

## Changed Files

| File | Change |
|---|---|
| `by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md` | Applied `89/92`, inserted exact formal first-draft C++ block, added B010 MCP/session evidence, superseded historical no-code blocker, preserved negative evidence. |
| `by-file/ImageFrameTable.md` | Updated UID0002P4 from comment-only/no-code to first-draft-ready and historicalized B006 no-code disposition; normalized one stale consumer call spelling. |
| `by-item/LoadImageFrameTable_004D0F50.md` | Kept non-emitting/index support, pointed source-quality route to UID0002P4 first-draft body, and documented two-argument target signature. |
| `by-file/Effects.md` | Narrowly normalized stale `LoadImageFrameTable(g_pEPFLib, ..., 0)` consumer wording to the two-argument loader signature. |
| `by-class/OverlayMovingImageEffecter.md` | Narrowly normalized stale loader signature in C++/parameter evidence; left `g_pEPFLib` layout/destroy roles intact. |
| `by-class/OverlayImageOnPointEffecter.md` | Narrowly normalized stale loader signature in C++/evidence; left `g_pEPFLib` layout/destroy roles intact. |
| `by-class/OverlayFrameImageEffecter.md` | Narrowly normalized stale loader signature in field/call/C++ evidence; left `g_pEPFLib` layout/destroy roles intact. |
| `by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md` | Narrowly normalized stale loader signature in runtime-cluster consumer summaries. |
| `tools/leaser/Agents/Agent-B010/research/0002P4-LoadImageFrameTable-source-quality.md` | Updated implementation ledger, checklist, validator results, and callback state. |
| Validator-generated side effects | Scoped validators updated generated/projected state, including `auto-generated/NexusTK/render/ImageFrameTable.cpp` and `project-level/-auto-completion-stats.md`; these were validator-owned updates, not manual edits. |

Leases: B010 successfully leased the eight by-* docs before the first edit batch. The first release command after validation reported `Rejected[No active lease]` for each path because the five-minute leases had already expired; follow-up lease report grep found no active B010 leases. B010 then re-leased `by-file/ImageFrameTable.md` and `by-item/LoadImageFrameTable_004D0F50.md` for the final stale-wording cleanup, reran validators `000000005918` and `000000005919`, released both leases successfully, and confirmed no active B010 lease remained.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---:|---|---|---|---|
| C01 | UID0002P4 target range is `0x004d0f50-0x004d15c5`, size `0x675`, followed by padding. | High | MCP `lookup_funcs`, `analyze_function`, `get_bytes`. | Target doc metadata/evidence. | incorporate | applied: target B010 section and summary; validator `000000005901` ok. |
| C02 | Current target body is comment-only and should be replaced with the exact formal `RECONSTRUCTION_CPP CODE` wrapper/block from this report. | High | Target doc formal block and generated `ImageFrameTable.cpp`. | Target `RECONSTRUCTION_CPP CODE` header/begin/end block. | incorporate | applied: target formal block populated; generated `ImageFrameTable.cpp` contains first-draft body after refresh `000000005904`. |
| C03 | Recommended metadata is `COMPLETION:89`, `CONFIDENCE:92`, owner/emitter unchanged. | Medium-high | Current docs plus MCP completeness and sibling precedent. | Target metadata. | incorporate | applied: target metadata `89/92`, owner/emitter/reconstructable preserved; validator `000000005901` ok. |
| C04 | Source-facing signature is two arguments: resource path and merge mode. | High | MCP caller disassembly shows two stack args; target does not consume `ecx`. | Target signature and support notes. | incorporate | applied: target C++ signature and support notes updated; stale consumer call spelling normalized in accepted scope. |
| C05 | Direct mode reads one DAT archive, rebases payload offsets, emits sentinel, and closes archive. | High | MCP decompile and disassembly. | Target item summary, evidence, C++ body. | incorporate | applied: target C++ direct path and B010 evidence section. |
| C06 | Merge mode maps modes 1..18 to EPF prefixes and probes `%s%d.EPF` up to 100 shards. | High | MCP decompile, disassembly, and string bytes. | Target behavior table and C++ body. | incorporate | applied: target C++ switch/probe loop and B010 evidence section. |
| C07 | Prefix `NECLACE` must remain misspelled. | High | MCP `get_bytes` at `0x0061b828`. | Target C++ body and evidence. | incorporate | applied: target C++ uses `L"NECLACE"`; evidence retained. |
| C08 | DATFile method spelling and object-array cleanup are not hard blockers for first draft. | Medium-high | Current sibling formal bodies for tile/effect loaders use the same accepted source shape. | Target blocker/dependency table and support docs. | incorporate | applied: target supersedes B006 hard blocker; ImageFrameTable support historicalized. |
| C09 | Owner remains UID0000K1 ImageFrameTable, not DATFile/ImageLib/consumers. | High | Current by-file ownership, generated path, target behavior, consumer-only xrefs. | Target ownership section and support docs. | incorporate | applied: owner/emitter preserved and negative evidence retained in target/support docs. |
| C10 | `by-file/ImageFrameTable.md` should historicalize the old B006 no-code conclusion for UID0002P4. | Medium-high | Historical B006 report plus current support/generated state. | Support `by-file/ImageFrameTable.md`. | incorporate | applied: `by-file/ImageFrameTable.md`; validators `000000005904` and final rerun `000000005918` ok. |
| C11 | `by-item/LoadImageFrameTable_004D0F50.md` should remain non-emitting but point to first-draft UID0002P4. | Medium-high | Item doc support role and target ownership. | Support by-item page. | incorporate | applied: by-item remains non-emitting and points to first-draft UID0002P4; validators `000000005907` and final rerun `000000005919` ok. |
| C12 | Consumer docs with `g_pEPFLib` as target argument should be normalized only where stale. | Medium | MCP caller disassembly shows `ecx` load but only two stack args. | Directly stale consumer support docs only. | incorporate-if-stale | applied: normalized directly stale references in `Effects.md`, three overlay effecter class pages, `ImageFrameTable.md`, and `ScreenEffecterRuntimeCluster.md`; validators `000000005904`, `000000005909`, `000000005910`, `000000005911`, `000000005912`, and `000000005913` ok. |
| C13 | No lifecycle, execute, generated, coverage, validator-state, or forbidden manual edit occurred during callback. | High | Local work scope and command history. | Report validator/changed-files sections. | already-present | applied: no `execute_report`/lifecycle/archive/manual generated or coverage edits; generated/projected state changed only through scoped validators. |

## Implementation Tracking Checklist

- [x] Target metadata updated to `COMPLETION:89`, `CONFIDENCE:92` in `by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md`; validator `000000005901` ok.
- [x] Target owner/emitter/reconstructable fields preserved as `0000K1`, `TRUE`, `0000K1`; blank emitter position preserved.
- [x] Target formal C++ block replaced with the exact formal `RECONSTRUCTION_CPP CODE` header/begin/end block from this report; generated `ImageFrameTable.cpp` contains first-draft body after refresh `000000005904`.
- [x] Target evidence updated with MCP session `3a33af0b`: range, size, xrefs, callees, direct mode, merge mode, prefix table, `NECLACE`, caller signature, cleanup, and generated first-draft state.
- [x] Broad stale no-code blocker wording replaced with resolved dependency table and confidence caps; historical B006 proof retained only as historical context.
- [x] Negative evidence preserved for DATFile/ImageLib/consumer/broad ownership and raw helper labels.
- [x] `by-file/ImageFrameTable.md` updated because stale; validators `000000005904` and final rerun `000000005918` ok.
- [x] `by-item/LoadImageFrameTable_004D0F50.md` updated because stale; validators `000000005907` and final rerun `000000005919` ok.
- [x] `by-item/EPFArchiveMetadataTable.md` narrow note excluded with reason: page already contained `ArchiveMetadataTable` and `PackedArchiveRecord` formal declarations at same-or-greater detail, so no edit was needed.
- [x] Direct consumer support docs with stale three-argument call spelling updated only where directly stale and in accepted scope: `Effects.md`, `OverlayMovingImageEffecter.md`, `OverlayImageOnPointEffecter.md`, `OverlayFrameImageEffecter.md`, `ScreenEffecterRuntimeCluster.md`, plus one `ImageFrameTable.md` consumer note.
- [x] Scoped validators run during authorized implementation callback for every edited by-* file; all exited `0` with `ok:1`.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual coverage or tracker text is recommended. The research tracker and generated coverage files are validator-owned and were not edited. If the implementation callback updates by-* docs and validators refresh generated output, the validator-owned tracker/coverage state should be treated as authoritative.

## Final Status

UID0002P4 implementation callback is complete and ready for supervisor Gate 2 / execution verification. Accepted target/support changes were applied or explicitly resolved, scoped validators ran for every edited by-* file, generated `ImageFrameTable.cpp` contains the first-draft body, and no `execute_report`, lifecycle/archive command, generated manual edit, coverage edit, validator-state edit, or supervisor-ledger edit was performed by B010.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000005925","destination_path":"executed-b-agent-research/B010/0002P4-LoadImageFrameTable-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0002P4-LoadImageFrameTable-source-quality.md","timestamp":"2026-07-03T23:59:22-04:00","uid":"0002P4"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
