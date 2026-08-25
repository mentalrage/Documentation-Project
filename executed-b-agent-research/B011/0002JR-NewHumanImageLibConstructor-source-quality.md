** TARGET-REPORT-UID:0002JR **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B011 Report: [UID:0002JR] NewHumanImageLib Constructor Source Quality

Assignment: `B011-report-0002JR-new-human-image-lib-constructor-20260625`  
Agent: `Agent-B011`  
Mode: report-only research  
Target: [UID:0002JR] `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`  
Report path: `tools/leaser/Agents/Agent-B011/research/0002JR-NewHumanImageLibConstructor-source-quality.md`  
Report date: 2026-06-25

## Report-Only Compliance

- No by-* target/support documents were edited.
- No generated files, project-level files, validator state/cache, IDA database files, `by-memory/-coverage-report.md`, or any other `-coverage-report.md` files were edited.
- No leases were taken; this was report-only research.
- No subagents were spawned.
- IDA MCP was available. Evidence below is from the active MCP session, not a fallback-only pass.
- No IDA DB edits, renames, comments, type changes, or function creation were made.

## Current Recommendation

Update [UID:0002JR] from `COMPLETION:86`, `CONFIDENCE:90` to:

- `COMPLETION:91`
- `CONFIDENCE:92`
- Preserve `CANONICAL_OWNER:000092`
- Preserve `RECONSTRUCTABLE:TRUE`
- Preserve `EMITTER_UIDS:000092`
- Keep `EMITTER_POSITION_OPTIONAL` blank
- Insert the formal first-draft constructor C++ supplied in this corrected report

The constructor is correctly class-owned by [UID:000092] `NewHumanImageLib` and should continue to emit through the class/file route already documented for `NexusTK/render/NewHumanImageLib.cpp`. The page is eligible under the current reconstruction-code gate because it is reconstructable, has an emitter route, and has an average score above 85. The corrected first-draft C++ is source-shaped rather than decompiler-shaped: it uses existing/inferred `NewHumanImageLib` layout names, `DATFile` archive-reader APIs, `NewHuman*Entry` row types, and the already documented loader methods. Old 95/95 or 95+ gate wording should be removed.

Supervisor correction: after the rejection recheck, the named blockers from the first draft are no longer valid no-code blockers. Current MCP decompilation plus existing layout/resource docs resolve enough row/type/helper naming to supply source-shaped first-draft C++ using explicitly inferred names. Helper/type/resource support docs still need synchronization, and several exact helper child pages should be created or updated, but that work no longer blocks [UID:0002JR] formal constructor code.

The corrected implementation callback should refresh the target and support docs with current MCP evidence, replace stale gate/autogen-parent wording, add the constructor first-draft C++ below, create or update the implementation-ready helper child/support docs listed in this report, then run scoped validators so generated tracker and generated source comments refresh normally.

## Current Target State

The target page currently records:

- `COMPLETION:86`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:000092`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000092`
- blank `EMITTER_POSITION_OPTIONAL`
- blank formal C++ block
- `Item Summary: Initializes singleton/vtable/vector/list state and loads Motion.tbl, Layer.tbl, Part.tbl, per-part descriptors, acc2drw.tbl, and HAIRCOL.TBL.`
- `Nested:4`

The current prose is substantially useful: it already documents the boundary, singleton/vtable stores, vector/list initialization, ordered table loads, local cleanup table, and major helper calls. The stale parts are source-quality issues:

- It still uses an `Autogen parent` phrase instead of the current canonical owner/emitter wording.
- It says final C++ is blank because the page has not reached an old 95/95 or 95+ threshold. That threshold is not the active code-entry rule.
- It has no current 2026-06-25 MCP provenance, even though the constructor was rechecked against the live IDA database in this pass.
- It does not yet separate the current combined-score/emitter gate from the stale old 95/95 gate.
- It does not yet capture the corrected 2026-06-25 decompile details for the loader helpers, row loaders, and vector-grow helpers that support the formal first-draft C++ in this report.

Generated and coverage state was checked read-only. The assignment row says `auto-generated/-ag-research-tracker.md` is stale at `74/86`, combined `80.0`, reconstructable `true`, reports `0`. Current generated coverage/source artifacts also still reflect stale `74/86` or `74%` state. These files should be refreshed by the validator/autogen lifecycle after source-doc changes, not hand-edited in a report-only or implementation callback.

## Evidence Checked

Primary source documents:

- [UID:0002JR] `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`
- [UID:000092] `by-class/NewHumanImageLib.md`
- [UID:0000LR] `by-file/NewHumanImageLib.md`
- [UID:0001F3] `by-type/by-struct/NewHumanImageLibLayout.md`
- [UID:0001Y9] `by-type/by-vtable/NewHumanImageLibVtable.md`
- [UID:0000RT] `by-global/g_pNewHumanImageLib.md`
- [UID:00017R] `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`
- `by-resource/new-human-motion-tables.md`
- `by-item/ResolveSpritePartPath_004E19D0.md`
- `by-memory/0x004e19d0-0x004e1f27.ResolveSpritePartPath.md`
- `by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md`
- `by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md`
- `by-item/EPFArchiveMetadataTable.md`

Generated/project inputs were read-only:

- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/render/NewHumanImageLib.cpp`
- `auto-generated/by-memory-tool-report.md`
- `by-project-structure/proposed-source-tree.md`
- `by-memory/-coverage-report.md`

Prior report/context was checked for conflicts and support evidence:

- `executed-b-agent-research/B010/00030Q-PointerVectorGrowInsert-source-quality.md`
- `executed-b-agent-research/B001/0002DR-FittingRoomSelectionVectorHelpers.md`
- `tools/leaser/Agents/Agent-A003/notes.md`
- `tools/leaser/Agents/Agent-B011/goal.md`
- `tools/leaser/Agents/Agent-B011/notes.md`

No dedicated executed B-agent report for [UID:0002JR] was found before this report.

## MCP Availability And Session Facts

The supervisor-required IDA MCP endpoint was live.

- `idb_list` returned active session `80de0a67`.
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Backend: worker
- Session active: `true`
- `server_health` returned `status: ok`
- Module: `NexusTK.exe`
- Input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Imagebase: `0x400000`
- `auto_analysis_ready: true`
- `hexrays_ready: true`
- `strings_cache_ready: true`
- `strings_cache_size: 2067`

One MCP tool limitation was observed in the earlier pass: the tool list included `callers`, but invoking that tool returned `Method 'callers' not found`. The corrected pass used current `xrefs_to`, `lookup_funcs`, `decompile`, `analyze_component`, `server_health`, and `int_convert` calls instead. This is not an MCP availability failure.

## Function Boundary And Range Evidence

Current `lookup_funcs` evidence:

| Address | Result |
| --- | --- |
| `0x004dfd10` | `sub_4DFD10`, size `0x53a` |
| `0x004e0249` | Inside `sub_4DFD10` |
| `0x004e024a` | Not a function |
| `0x004e0250` | `sub_4E0250`, size `0x374`; successor destructor |
| `0x004e0d70` | `sub_4E0D70`, size `0x5f`; inferred `LoadPartFrameDrawRecord` |
| `0x004e0dd0` | `sub_4E0DD0`, size `0x0a`; inferred `GetHeadCount` |
| `0x004e0e20` | `sub_4E0E20`, size `0x21f`; motion-table loader |
| `0x004e1040` | `sub_4E1040`, size `0x170`; inferred reusable `LoadLayerTable` |
| `0x004e11b0` | `sub_4E11B0`, size `0x1f7`; inferred reusable `LoadPartTable` |
| `0x004e13b0` | `sub_4E13B0`, size `0x446`; per-part descriptor loader |
| `0x004e1800` | `sub_4E1800`, size `0x1c5`; `acc2drw.tbl` loader |
| `0x004e19d0` | `sub_4E19D0`, size `0x557`; sprite part path resolver |
| `0x004e4f10` | `sub_4E4F10`, range `0x004e4f10-0x004e50a0`; 3-byte `Acc2DrwEntry` grow/insert helper |
| `0x004e50a0` | `sub_4E50A0`, size `0x19e`; 32-byte layer row vector grow/insert |
| `0x004e5240` | `sub_4E5240`, size `0x1d5`; motion row vector grow/insert |
| `0x004e5420` | `sub_4E5420`, size `0x1d6`; 68-byte part row vector grow/insert |
| `0x00420de0` | `sub_420DE0`, size `0x10a`; shared 4-byte vector grow/insert |

`get_bytes 0x004e024a size 6` returned:

```text
cc cc cc cc cc cc
```

The target range is exact: `0x004dfd10-0x004e024a` is one modeled constructor function, and `0x004e024a-0x004e0250` is alignment before the destructor. There is no split or boundary repair needed for the target range itself.

`analyze_function 0x004dfd10` reported:

- Name: `sub_4DFD10`
- Prototype shape: `_DWORD *__fastcall(_DWORD *)`
- Size: `0x53a`
- Basic blocks: 61
- Cyclomatic complexity: 6
- Direct caller: `sub_4F5FB0`
- Callees include `LObject` construction, DAT/file helpers, `_memset`, `operator new`, `MultiByteToWideChar`, table loaders, vector-grow helpers, string conversion, and compiler/runtime helpers.

## Constructor Behavior Confirmed By Decompile

The live constructor decompile confirms this ordered source behavior:

1. Calls `0x004f4a80` to construct the `LObject` base.
2. Stores `this` into singleton storage `g_pNewHumanImageLib` / `dword_67A760`, with the compiler cleanup/sentinel path clearing the singleton when the adjusted pointer equals `-4`.
3. Stores the `NewHumanImageLib` vtable at object offset `+0x00`.
4. Zeroes the vector triplets at offsets `+0x04`, `+0x10`, `+0x1c`, `+0x28`, `+0x48`, and `+0x54`.
5. Initializes list/sentinel state at `+0x34-+0x47`, allocates an 8-byte sentinel node, clears its two dwords, and points the sentinel back at the list header.
6. Calls `LoadMotionTable` at `0x004e0e20` with the `Motion.tbl` literal.
7. Opens `Layer.tbl`, reads a 23-byte header and 4-byte row count, then appends 32-byte layer rows into the `+0x10` vector. Rows with a child count allocate and read a 4-byte child-index array.
8. Opens `Part.tbl`, reads a 23-byte header and 4-byte row count, clears a 68-byte temporary part row, reads a 20-byte ANSI part name and scalar fields, converts the part name through `MultiByteToWideChar`, calls `ResolveSpritePartPath` at `0x004e19d0`, stores the returned EPF metadata pointer at row offset `+0x40`, then appends the row into the `+0x04` vector.
9. Calls `LoadPartSpriteDescriptors` at `0x004e13b0`.
10. Calls `LoadAcc2DrwTable` at `0x004e1800` with the `acc2drw.tbl` literal.
11. Opens `HAIRCOL.TBL`, reads the loop count from `*(partEntriesBegin + 0x188)`, reads six-byte text rows, converts them through `0x005cea6d`, and appends 4-byte values into the `+0x54` vector. The full-capacity path calls shared vector helper `0x00420de0` at `0x004e020d`.

This exactly matches the target page's high-level summary. The improvement is that current MCP now proves the helper bodies and caller graph enough to replace old gate prose with a precise source-shape explanation.

## Helper And Xref Evidence

Current MCP xref queries confirm these helper routes:

| Target | Current caller evidence |
| --- | --- |
| `0x004dfd10` constructor | One code xref from `0x004f60a1` in `sub_4F5FB0`. |
| `0x004e0d70` `LoadPartFrameDrawRecord` | Two code xrefs from UI/preview functions at `0x0050141a` and `0x005018fa`. |
| `0x004e0dd0` `GetHeadCount` | Nine code xrefs from look/head-selection/UI paths including `0x004fb8b4`, `0x004fd584`, `0x00551758`, and `0x00551c6b`. |
| `0x004e0e20` `LoadMotionTable` | Called only from constructor at `0x004dfe5a`. |
| `0x004e1040` inferred `LoadLayerTable` | No current direct xrefs. It is a reusable source-shaped loader body, not a constructor callee. |
| `0x004e11b0` inferred `LoadPartTable` | No current direct xrefs. It is a reusable source-shaped loader body, not a constructor callee. |
| `0x004e13b0` `LoadPartSpriteDescriptors` | Called only from constructor at `0x004e017c`. |
| `0x004e1800` `LoadAcc2DrwTable` | Called only from constructor at `0x004e0188`. |
| `0x004e19d0` `ResolveSpritePartPath` | Called from constructor at `0x004e00f0` and local helper `sub_4E11B0` at `0x004e12fe`. |
| `0x004e4f10` `VectorGrowAcc2Drw` | Called only from `LoadAcc2DrwTable` at `0x004e195a`. |
| `0x004e50a0` 32-byte row grow/insert | Called from constructor at `0x004dffb2` and `sub_4E1040` at `0x004e1171`. |
| `0x004e5240` motion row grow/insert | Called only from `sub_4E0E20` at `0x004e0ff2`. |
| `0x004e5420` 68-byte row grow/insert | Called from constructor at `0x004e0148` and `sub_4E11B0` at `0x004e1356`. |
| `0x00420de0` shared 4-byte grow/insert | Called from two existing non-NewHuman sites and the constructor hair-color append path at `0x004e020d`. |

Current MCP xref queries for the vtable and singleton:

- Vtable `0x0061b76c` has data refs from constructor store `0x004dfd78` and destructor restore/store `0x004e027e`.
- Singleton `0x0067a760` has constructor writes at `0x004dfd67` and `0x004dfd6e`, destructor clear at `0x004e059e`, helper clear at `0x004e5be0`, shutdown read at `0x004f65f2`, and many render/look/UI consumers.

This is strong positive evidence that [UID:0002JR] is the class constructor for [UID:000092], not a file-level parser or resource-owned helper.

## Loader Helper Evidence

The corrected MCP pass resolves the local helper names and roles enough for constructor C++. The helpers still need exact child/support-page synchronization, but that is no longer a constructor no-code blocker.

`0x004e0e20` `LoadMotionTable`:

- Opens the supplied table path.
- Reads a 23-byte header and a 4-byte row count.
- Uses 66-byte motion rows.
- Reads scalar row fields, a frame/count field, one 2-byte-per-frame array, and one 120-byte-per-frame block.
- Appends rows into the motion vector at `this + 0x1c`.
- Calls `0x004e5240` on full capacity at `0x004e0ff2`.

`0x004e13b0` `LoadPartSpriteDescriptors`:

- Iterates the part vector, using `(end - begin) / 68`.
- Builds a descriptor path from the part name and `.DSC`.
- Opens the descriptor file.
- Reads a 23-byte header and count.
- Allocates 32-byte descriptor rows when count is positive.
- Stores descriptor pointer/count/capacity-like fields into the owning part row.
- Allocates nested per-motion/per-frame mapping data sized from the motion vector row count.
- Reads nested 9-byte descriptor records into selected motion slots.

`0x004e1800` `LoadAcc2DrwTable`:

- Opens the supplied path.
- Clears the accessory-draw vector end back to begin.
- Gets the row count from `*(partEntriesBegin + 0x210)`.
- Reads up to 4096 chars per line.
- Parses an integer value through `0x005cea6d`.
- Decomposes decimal hundreds/tens/ones into three compact flag bytes.
- Appends 3-byte rows into `this + 0x48`.
- On read/open failure, emits the documented `MessageBoxW` error path for `Error on ACC2DRW table!`.

`0x004e50a0`:

- Grows/inserts 32-byte layer rows.
- Uses vector capacity growth, prefix/suffix moves, and aligned/free cleanup.
- Called from the constructor and local helper `0x004e1040`.

`0x004e5420`:

- Grows/inserts 68-byte part rows.
- Computes the insertion index from `(Src - begin) / 68`.
- Uses vector capacity growth, 0x44-byte row copies, prefix/suffix moves, and aligned/free cleanup.
- Called from the constructor and local helper `0x004e11b0`.

These details show how the constructor C++ should be shaped: call the out-of-line helpers where the binary calls them (`LoadMotionTable`, `LoadPartSpriteDescriptors`, `LoadAcc2DrwTable`) and keep the constructor's actual inline `Layer.tbl`, `Part.tbl`, and `HAIRCOL.TBL` loops in the constructor body. Do not invent source calls from the constructor to `LoadLayerTable` or `LoadPartTable`, because the current binary has no calls from [UID:0002JR] to `0x004e1040` or `0x004e11b0`.

## Corrected Helper Child-Page Disposition

Exact page inventory after the supervisor-rejection recheck:

| Range | Current by-memory page state | Decision |
| --- | --- | --- |
| `0x004e0d70-0x004e0dcf` | No exact page found. Existing class/file/cluster docs mention `LoadPartFrameDrawRecord`. | New exact child page should be proposed: `by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md`. UID must be assigned by the validator; use a `[TMP:"by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md"]` reference in implementation until validation replaces it. |
| `0x004e0dd0-0x004e0dda` | No exact page found. Existing class/file/cluster docs mention `GetHeadCount`. | New exact child page should be proposed: `by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md`. UID assigned by validator via TMP reference. |
| `0x004e0e20-0x004e103f` | No exact page found. Class/resource/cluster docs describe `LoadMotionTable`. | New exact child page should be proposed: `by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md`. UID assigned by validator via TMP reference. |
| `0x004e1040-0x004e11af` | No exact page found. Cluster currently calls it `MotionTableLocalHelperA`, which is stale. | New exact child page should be proposed as `by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md`. Current decompile proves it is a reusable `Layer.tbl` loader and not a motion-table helper. UID assigned by validator via TMP reference. |
| `0x004e11b0-0x004e13a7` | No exact page found. Cluster currently calls it `MotionTableLocalHelperB`, which is stale. | New exact child page should be proposed as `by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md`. Current decompile proves it is a reusable `Part.tbl` loader and not a motion-table helper. UID assigned by validator via TMP reference. |
| `0x004e13b0-0x004e17f6` | No exact page found. Class/resource/cluster docs describe `LoadPartSpriteDescriptors`. | New exact child page should be proposed: `by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md`. UID assigned by validator via TMP reference. |
| `0x004e1800-0x004e19c5` | No exact page found. Class/resource/cluster docs describe `LoadAcc2DrwTable`. | New exact child page should be proposed: `by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md`. UID assigned by validator via TMP reference. |
| `0x004e4f10-0x004e50a0` | No exact page found in current filenames/search. It is directly called by `LoadAcc2DrwTable` at `0x004e195a`. | New exact child page should be proposed: `by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md`. UID assigned by validator via TMP reference. |
| `0x004e50a0-0x004e523e` | No exact page found. It is called from the constructor and `LoadLayerTable`. | New exact child page should be proposed: `by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md`. UID assigned by validator via TMP reference. |
| `0x004e5240-0x004e5415` | Existing [UID:00017T] `by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md`. | Update only. Preserve range/UID. Replace stale gate wording and add the 2026-06-25 caller/decompile confirmation. |
| `0x004e5420-0x004e55f6` | No exact page found. It is called from the constructor and `LoadPartTable`. | New exact child page should be proposed: `by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md`. UID assigned by validator via TMP reference. |

Gate-compliant metadata rule for the new helper pages:

The proposed new helper child pages are implementation-ready support pages, but this constructor report recommends them at `84/86`. Under the strict 85/85 owner/emitter gate, none of those new `84/86` pages may receive `CANONICAL_OWNER:000092`, `CANONICAL_OWNER:0000LR`, or nonblank `EMITTER_UIDS` yet. Their class/file routes are documented below as forced candidate routes only. The implementation callback must create them as below-gate, non-emitting support pages with `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank `RECONSTRUCTION_CPP CODE`. A later page-specific pass may raise any helper to at least `85/85` and assign owner/emitter only if it also supplies the helper's own C++ or a current no-code proof.

| New page | Completion / confidence | Owner / emitter metadata now | Candidate route evidence | Reconstructable | C++ disposition |
| --- | --- | --- | --- | --- | --- |
| `NewHumanImageLibLoadPartFrameDrawRecord` | `84/86` | `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS` | Candidate class route [UID:000092] after exact `LoadFrameDrawRecord`/descriptor typedef support is synchronized. | `TRUE` | Keep formal C++ blank because the page is intentionally below gate and non-emitting. |
| `NewHumanImageLibGetHeadCount` | `84/86` | `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS` | Candidate class route [UID:000092] after the head-part count/member declaration is synchronized. | `TRUE` | Keep formal C++ blank because the page is intentionally below gate and non-emitting. |
| `NewHumanImageLibLoadMotionTable` | `84/86` | `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS` | Candidate class route [UID:000092] after `NewHumanMotionEntry` and frame-array declarations are synchronized. | `TRUE` | Keep formal C++ blank because the page is intentionally below gate and non-emitting. |
| `NewHumanImageLibLoadLayerTable` | `84/86` | `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS` | Candidate class route [UID:000092]; source-facing name is inferred and corrects stale `MotionTableLocalHelperA`. | `TRUE` | Keep formal C++ blank because the page is intentionally below gate and non-emitting. |
| `NewHumanImageLibLoadPartTable` | `84/86` | `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS` | Candidate class route [UID:000092]; source-facing name is inferred and corrects stale `MotionTableLocalHelperB`. | `TRUE` | Keep formal C++ blank because the page is intentionally below gate and non-emitting. |
| `NewHumanImageLibLoadPartSpriteDescriptors` | `84/86` | `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS` | Candidate class route [UID:000092] after descriptor row and nested mapping typedefs are synchronized. | `TRUE` | Keep formal C++ blank because the page is intentionally below gate and non-emitting. |
| `NewHumanImageLibLoadAcc2DrwTable` | `84/86` | `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS` | Candidate class route [UID:000092] after `Acc2DrwEntry` and vector helper declarations are synchronized. | `TRUE` | Keep formal C++ blank because the page is intentionally below gate and non-emitting. |
| `VectorGrowAcc2Drw`, `VectorGrowLayer`, `VectorGrowPart` | `84/86` each | `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS` | Candidate file/helper route [UID:0000LR] and [UID:0000P3] after centralized vector-template declaration support is synchronized. | `TRUE` | Keep formal C++ blank because each page is intentionally below gate and non-emitting. |

The UID handling above is deliberate: report-only work must not invent six-character UIDs. During implementation, create the files with blank UID headers or TMP references according to validator workflow, run scoped validators on each new file, then update target/support references once the validator assigns real UIDs.

### Implementation-Ready New Child Page Specifications

Shared creation rule for all new child pages below: create a new by-memory page at the exact filename/range, leave the UID field blank or use the validator-supported new-page flow, and reference it from edited support pages as `[TMP:"<relative path>"]` until scoped validation assigns a real six-character UID. Do not assign a canonical owner or emitter on these `84/86` support pages during this constructor callback. Do not insert helper bodies into [UID:0002JR]'s constructor C++ block.

- `by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md`
  - Range: `0x004e0d70-0x004e0dcf`; nested value: `0`.
  - Metadata: `COMPLETION:84`, `CONFIDENCE:86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank `RECONSTRUCTION_CPP CODE`.
  - Item summary: exact below-gate child support page for inferred `NewHumanImageLib::LoadPartFrameDrawRecord`.
  - No-owner disposition: candidate owner [UID:000092] is documented evidence only; owner/emitter assignment is blocked by the `84/86` score and missing helper-page-specific C++.
  - Behavior summary: indexes the part entry, descriptor table, and motion-specific draw mapping, then forwards the selected record to the established frame-draw record loader.
  - Evidence: function lookup at `0x004e0d70`, existing class/file/cluster mentions, helper pass confirmed it is the named frame-draw bridge.
  - Rejected alternatives: reject preserving raw address/sub-name; reject folding this helper into [UID:0002JR], because it is outside the constructor range.
  - Score rationale: `84` completion for exact range, role, and call purpose but missing formal helper C++; `86` confidence from current MCP lookup/decompile support.
  - Cross-references: [UID:0002JR], [UID:000092], [UID:0000LR], [UID:00017R], `by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md`.
  - Validator: `python .\tools\validator.py --mode file --file by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md --apply --queue-timeout 240`.
- `by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md`
  - Range: `0x004e0dd0-0x004e0dda`; nested value: `0`.
  - Metadata: `COMPLETION:84`, `CONFIDENCE:86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank `RECONSTRUCTION_CPP CODE`.
  - Item summary: exact below-gate child support page for inferred `NewHumanImageLib::GetHeadCount`.
  - No-owner disposition: candidate owner [UID:000092] is documented evidence only until the accessor and head-count/member name are promoted in a page-specific pass.
  - Behavior summary: returns the count field at `this[1] + 0x188`, matching the head/hair descriptor-count evidence used by the constructor's `HAIRCOL.TBL` loop.
  - Evidence: function lookup at `0x004e0dd0`, class/file/cluster mentions, current xrefs from UI/look code, direct small accessor shape.
  - Rejected alternatives: reject raw address name; reject emitting a one-line helper in this constructor pass because the page is below gate and non-emitting.
  - Score rationale: `84` completion for exact range and accessor semantics but missing formal helper declaration; `86` confidence from direct MCP decompile/accessor evidence.
  - Cross-references: [UID:0002JR], [UID:000092], [UID:0000LR], [UID:00017R], `by-type/by-struct/NewHumanImageLibLayout.md`.
  - Validator: `python .\tools\validator.py --mode file --file by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md --apply --queue-timeout 240`.
- `by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md`
  - Range: `0x004e0e20-0x004e103f`; nested value: `0`.
  - Metadata: `COMPLETION:84`, `CONFIDENCE:86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank `RECONSTRUCTION_CPP CODE`.
  - Item summary: exact below-gate child support page for inferred `NewHumanImageLib::LoadMotionTable`.
  - No-owner disposition: candidate owner [UID:000092] is documented evidence only until motion row/frame-array declarations and helper C++ are promoted.
  - Behavior summary: opens/reads `Motion.tbl`, skips the 23-byte header, reads count and 0x42-byte motion rows, allocates per-frame arrays, and appends entries through [UID:00017T] `VectorGrowMotion`.
  - Evidence: constructor call at `0x004dfe57`, string/data xref to `Motion.tbl`, current decompile, and current caller graph showing the constructor as the only caller.
  - Rejected alternatives: reject naming as generic DAT helper; reject inlining into [UID:0002JR], because the binary calls this out-of-line helper.
  - Score rationale: `84` completion for exact load semantics but missing formal helper C++; `86` confidence from current MCP decompile/xref support.
  - Cross-references: [UID:0002JR], [UID:000092], [UID:0000LR], [UID:00017R], [UID:00017T], `by-resource/new-human-motion-tables.md`, `by-type/by-struct/NewHumanImageLibLayout.md`.
  - Validator: `python .\tools\validator.py --mode file --file by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md --apply --queue-timeout 240`.
- `by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md`
  - Range: `0x004e1040-0x004e11af`; nested value: `0`.
  - Metadata: `COMPLETION:84`, `CONFIDENCE:86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank `RECONSTRUCTION_CPP CODE`.
  - Item summary: exact below-gate child support page for inferred `NewHumanImageLib::LoadLayerTable`.
  - No-owner disposition: candidate owner [UID:000092] is documented evidence only; the constructor does not call this helper and the page remains non-emitting at `84/86`.
  - Behavior summary: reusable `Layer.tbl` loader with 23-byte header, count read, 32-byte layer rows, optional child-index allocation, and `VectorGrowLayer` insertion.
  - Evidence: current decompile proves layer-table behavior; current xrefs show zero direct calls; local cluster stale name `MotionTableLocalHelperA` is wrong.
  - Rejected alternatives: reject `MotionTableLocalHelperA`; reject claiming [UID:0002JR] calls it, because current xrefs show no constructor call to `0x004e1040`.
  - Score rationale: `84` completion for exact behavior/range and corrected name but no helper C++; `86` confidence from direct decompile and negative xref check.
  - Cross-references: [UID:0002JR], [UID:000092], [UID:0000LR], [UID:00017R], `by-resource/new-human-motion-tables.md`, `by-type/by-struct/NewHumanImageLibLayout.md`.
  - Validator: `python .\tools\validator.py --mode file --file by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md --apply --queue-timeout 240`.
- `by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md`
  - Range: `0x004e11b0-0x004e13a7`; nested value: `0`.
  - Metadata: `COMPLETION:84`, `CONFIDENCE:86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank `RECONSTRUCTION_CPP CODE`.
  - Item summary: exact below-gate child support page for inferred `NewHumanImageLib::LoadPartTable`.
  - No-owner disposition: candidate owner [UID:000092] is documented evidence only; the constructor does not call this helper and the page remains non-emitting at `84/86`.
  - Behavior summary: reusable `Part.tbl` loader with 23-byte header, 20-byte ANSI part name conversion, `ResolveSpritePartPath`, 68-byte part rows, and `VectorGrowPart` insertion.
  - Evidence: current decompile proves part-table behavior; current xrefs show zero direct calls; local cluster stale name `MotionTableLocalHelperB` is wrong.
  - Rejected alternatives: reject `MotionTableLocalHelperB`; reject claiming [UID:0002JR] calls it, because current xrefs show no constructor call to `0x004e11b0`.
  - Score rationale: `84` completion for exact behavior/range and corrected name but no helper C++; `86` confidence from direct decompile and negative xref check.
  - Cross-references: [UID:0002JR], [UID:000092], [UID:0000LR], [UID:00017R], `by-item/ResolveSpritePartPath_004E19D0.md`, `by-memory/0x004e19d0-0x004e1f27.ResolveSpritePartPath.md`, `by-resource/new-human-motion-tables.md`.
  - Validator: `python .\tools\validator.py --mode file --file by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md --apply --queue-timeout 240`.
- `by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md`
  - Range: `0x004e13b0-0x004e17f6`; nested value: `0`.
  - Metadata: `COMPLETION:84`, `CONFIDENCE:86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank `RECONSTRUCTION_CPP CODE`.
  - Item summary: exact below-gate child support page for inferred `NewHumanImageLib::LoadPartSpriteDescriptors`.
  - No-owner disposition: candidate owner [UID:000092] is documented evidence only until descriptor row and nested per-motion mapping declarations are promoted.
  - Behavior summary: builds per-part `.DSC` paths, reads descriptor counts and 32-byte descriptor rows, allocates nested motion/draw mapping arrays, and initializes per-part descriptor state.
  - Evidence: constructor call at `0x004e0176`, `.DSC` data xref at `0x0061c33c`, current decompile, and class/resource/cluster helper mentions.
  - Rejected alternatives: reject treating `.DSC` parsing as constructor-inline code; the binary calls this helper out-of-line.
  - Score rationale: `84` completion for exact range/table role but missing helper formal C++; `86` confidence from current MCP decompile/string/xref evidence.
  - Cross-references: [UID:0002JR], [UID:000092], [UID:0000LR], [UID:00017R], `by-resource/new-human-motion-tables.md`, `by-type/by-struct/NewHumanImageLibLayout.md`.
  - Validator: `python .\tools\validator.py --mode file --file by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md --apply --queue-timeout 240`.
- `by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md`
  - Range: `0x004e1800-0x004e19c5`; nested value: `0`.
  - Metadata: `COMPLETION:84`, `CONFIDENCE:86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank `RECONSTRUCTION_CPP CODE`.
  - Item summary: exact below-gate child support page for inferred `NewHumanImageLib::LoadAcc2DrwTable`.
  - No-owner disposition: candidate owner [UID:000092] is documented evidence only until `Acc2DrwEntry` and vector helper declarations are promoted.
  - Behavior summary: reads `acc2drw.tbl`, uses count from `partEntriesBegin + 0x210`, parses decimal lines through `ParseUnsignedLongBase10`, decomposes three decimal digits into flag bytes, appends through `VectorGrowAcc2Drw`, and reports `Error on ACC2DRW table!` on failure.
  - Evidence: constructor call at `0x004e0189`, data xref to `acc2drw.tbl`, current decompile, `VectorGrowAcc2Drw` call at `0x004e195a`.
  - Rejected alternatives: reject inlining into [UID:0002JR]; reject raw parse-helper names in support docs when source-facing `ParseUnsignedLongBase10` is defensible.
  - Score rationale: `84` completion for exact behavior/range but missing helper formal C++; `86` confidence from current MCP decompile/xref support.
  - Cross-references: [UID:0002JR], [UID:000092], [UID:0000LR], [UID:00017R], `by-resource/new-human-motion-tables.md`, `by-type/by-struct/NewHumanImageLibLayout.md`.
  - Validator: `python .\tools\validator.py --mode file --file by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md --apply --queue-timeout 240`.
- `by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md`
  - Range: `0x004e4f10-0x004e50a0`; nested value: `-4`.
  - Metadata: `COMPLETION:84`, `CONFIDENCE:86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank `RECONSTRUCTION_CPP CODE`.
  - Item summary: exact below-gate child support page for inferred `VectorGrowAcc2Drw`.
  - No-owner disposition: candidate route [UID:0000LR]/[UID:0000P3] is documented evidence only until vector-template support is centralized above gate.
  - Behavior summary: grows/inserts a 3-byte accessory-to-draw entry vector, including capacity growth, insertion shift, and cleanup/move behavior.
  - Evidence: direct caller `LoadAcc2DrwTable` at `0x004e195a`, decompile shape, and parallel vector-grow family evidence from [UID:00017T].
  - Rejected alternatives: reject class ownership now; reject raw vector helper name; reject helper C++ in this constructor report.
  - Score rationale: `84` completion for exact vector behavior but no formal vector-template helper C++; `86` confidence from current MCP decompile/caller evidence.
  - Cross-references: [UID:0002JR], [UID:0000LR], [UID:0000P3], [UID:00017R], `by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md`.
  - Validator: `python .\tools\validator.py --mode file --file by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md --apply --queue-timeout 240`.
- `by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md`
  - Range: `0x004e50a0-0x004e523e`; nested value: `-4`.
  - Metadata: `COMPLETION:84`, `CONFIDENCE:86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank `RECONSTRUCTION_CPP CODE`.
  - Item summary: exact below-gate child support page for inferred `VectorGrowLayer`.
  - No-owner disposition: candidate route [UID:0000LR]/[UID:0000P3] is documented evidence only until vector-template support is centralized above gate.
  - Behavior summary: grows/inserts 32-byte layer entries and handles capacity growth, element copy, insertion shifts, and cleanup.
  - Evidence: constructor call at the inline `Layer.tbl` loop, caller from `LoadLayerTable`, current decompile, and vector-grow family evidence.
  - Rejected alternatives: reject assigning [UID:0000LR] owner/emitter at `84/86`; reject helper body insertion into constructor C++.
  - Score rationale: `84` completion for exact vector behavior but no formal vector-template helper C++; `86` confidence from current MCP decompile/caller evidence.
  - Cross-references: [UID:0002JR], [UID:0000LR], [UID:0000P3], [UID:00017R], `by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md`.
  - Validator: `python .\tools\validator.py --mode file --file by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md --apply --queue-timeout 240`.
- `by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md`
  - Range: `0x004e5420-0x004e55f6`; nested value: `-4`.
  - Metadata: `COMPLETION:84`, `CONFIDENCE:86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank `RECONSTRUCTION_CPP CODE`.
  - Item summary: exact below-gate child support page for inferred `VectorGrowPart`.
  - No-owner disposition: candidate route [UID:0000LR]/[UID:0000P3] is documented evidence only until vector-template support is centralized above gate.
  - Behavior summary: grows/inserts 68-byte part entries and handles capacity growth, element copy, insertion shifts, and cleanup.
  - Evidence: constructor call at the inline `Part.tbl` loop, caller from `LoadPartTable`, current decompile, and vector-grow family evidence.
  - Rejected alternatives: reject assigning [UID:0000LR] owner/emitter at `84/86`; reject helper body insertion into constructor C++.
  - Score rationale: `84` completion for exact vector behavior but no formal vector-template helper C++; `86` confidence from current MCP decompile/caller evidence.
  - Cross-references: [UID:0002JR], [UID:0000LR], [UID:0000P3], [UID:00017R], `by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md`.
  - Validator: `python .\tools\validator.py --mode file --file by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md --apply --queue-timeout 240`.

## Resource And String Evidence

Current data xrefs:

| Address | Literal/source role | Xref evidence |
| --- | --- | --- |
| `0x0061c2e4` | `Motion.tbl` | Constructor xref at `0x004dfe4f`. |
| `0x0061c2fc` | `Layer.tbl` | Constructor xref at `0x004dfe91`. |
| `0x0061c310` | `Part.tbl` | Constructor xref at `0x004dffec`. |
| `0x0061c324` | `acc2drw.tbl` | Constructor xref at `0x004e0181`. |
| `0x0061c010` | `HAIRCOL.TBL` | Old-human xref at `0x004d4910` and constructor xref at `0x004e0198`. |
| `0x0061c33c` | `.DSC` | Descriptor-loader xref at `0x004e1435`. |
| `0x0061c348` | `%s.EPF` | Sprite-path resolver xref at `0x004e1d5e`. |
| `0x0061b850` | `%s%d.EPF` | Old-human resolver refs and new-human resolver refs at `0x004e1a1f`, `0x004e1a4b`, and `0x004e1b27`. |

Current raw byte reads decode the UTF-16 table cluster at `0x0061c2e4` as:

```text
Motion.tbl, Layer.tbl, Part.tbl, acc2drw.tbl, .DSC, %s.EPF
```

`get_string` is unreliable for adjacent UTF-16 literals here because current IDA string typing returns only first characters for some adjacent entries. The docs should prefer raw-byte decode evidence for this string cluster.

## Cleanup And Unwind Evidence

Current xrefs to cleanup helpers confirm that the constructor's SEH cleanup table covers the initialized class members:

| Cleanup target | Evidence |
| --- | --- |
| `0x004e5be0` singleton clear helper | Referenced from constructor cleanup table at `0x00600230`. |
| `0x004e5dd0` motion-vector cleanup | Destructor call at `0x004e0547` and constructor cleanup table at `0x0060025a`. |
| `0x004e5d00` accessory-vector cleanup | Destructor call at `0x004e052f` and constructor cleanup table at `0x00600284`. |
| `0x00423810` integer-vector cleanup | Constructor cleanup table at `0x00600292`; also matches the hair-color vector element shape. |
| `0x004557f0` auxiliary-vector cleanup | Destructor call at `0x004e053f` and constructor cleanup table at `0x00600268`. |
| `0x004e5ce0` list/sentinel cleanup | Constructor cleanup table at `0x00600276`. |

`get_bytes 0x00600230 size 128` shows the cleanup table starts with a jump to `0x004e5be0`, then repeated `mov ecx,[ebp-0x1b4]; add ecx,<offset>; jmp <cleanup helper>` tails for offsets `+0x04`, `+0x10`, `+0x1c`, `+0x28`, `+0x34`, `+0x48`, and `+0x54`, plus DAT temporary cleanup through the local file-reader destructor helper.

This is compiler EH cleanup scaffolding, not source-level code to be emitted in the constructor page. It should be summarized as member-lifetime evidence.

## Ownership And Source Route

Recommended ownership ranking:

1. [UID:000092] `NewHumanImageLib` remains the canonical owner. The receiver object, singleton, vtable, constructor/destructor pair, vector/list layout, and table-load responsibilities are all class state.
2. [UID:0000LR] `NewHumanImageLib` remains the best source-file route. The constructor is part of the new-human rendering image library and matches the existing generated path `NexusTK/render/NewHumanImageLib.cpp`.
3. [UID:00017R] `NewHumanImageLibLocalMethodCluster` is useful as an aggregate/index parent, but should not replace the class as canonical owner.
4. The DAT table/resource pages are dependencies and support context, not owners.
5. Vector-grow helpers and EPF resolver helpers are dependencies or child support pages, not owners of this constructor.
6. No-owner/non-emitting placement is rejected because the constructor has a direct class owner and emitter route.

No split is recommended for the exact target range. The support repair is to document or refine child/support pages for helper functions outside the target range.

## First-Draft C++ Recommendation

[UID:0002JR] should receive formal first-draft C++ now. The old blank-C++ recommendation is superseded.

Scope separation: the block below is only the formal constructor code for [UID:0002JR]. It calls out-of-line helpers where the binary does, but it does not contain helper child-page bodies. The proposed new helper child pages above remain blank-C++, below-gate support pages until a later page-specific pass promotes them.

Exact paste-ready formal `RECONSTRUCTION_CPP CODE` header/block content for [UID:0002JR]:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
NewHumanImageLib::NewHumanImageLib()
    : LObject(),
      m_partEntries(),
      m_layerEntries(),
      m_motionEntries(),
      m_auxiliaryEntries(),
      m_loadedPartList(),
      m_acc2drwEntries(),
      m_hairColorEntries()
{
    g_pNewHumanImageLib = this;

    LoadMotionTable(L"Motion.tbl");

    {
        DATFile layerFile;
        unsigned char header[23];
        int layerCount = 0;

        layerFile.Open(L"Layer.tbl");
        layerFile.Read(header, sizeof(header));
        layerFile.Read(&layerCount, sizeof(layerCount));

        for (int index = 0; index < layerCount; ++index)
        {
            NewHumanLayerEntry layer = {};

            layerFile.Read(&layer.layerId, sizeof(layer.layerId));
            layerFile.Read(layer.name, sizeof(layer.name));
            layerFile.Read(&layer.childCount, sizeof(layer.childCount));

            if (layer.childCount > 0)
            {
                layer.childIndexes = new int[layer.childCount];
                layerFile.Read(layer.childIndexes,
                               sizeof(layer.childIndexes[0]) * layer.childCount);
            }

            m_layerEntries.push_back(layer);
        }

        layerFile.Close();
    }

    {
        DATFile partFile;
        unsigned char header[23];
        int partCount = 0;

        partFile.Open(L"Part.tbl");
        partFile.Read(header, sizeof(header));
        partFile.Read(&partCount, sizeof(partCount));

        for (int index = 0; index < partCount; ++index)
        {
            NewHumanPartEntry part = {};
            char partName[256];

            partFile.Read(&part.partId, sizeof(part.partId));
            partFile.Read(partName, 20);
            partFile.Read(&part.drawIndexBase, sizeof(part.drawIndexBase));
            partFile.Read(&part.descriptorBase, sizeof(part.descriptorBase));

            const int partNameLength = strlen(partName);
            MultiByteToWideChar(CP_ACP, 0, partName, partNameLength, part.name, 255);
            part.name[partNameLength] = L'\0';

            part.spriteArchive = ResolveSpritePartPath(part.name);
            m_partEntries.push_back(part);
        }

        partFile.Close();
    }

    LoadPartSpriteDescriptors();
    LoadAcc2DrwTable(L"acc2drw.tbl");

    {
        DATFile hairColorFile;
        char colorText[6];
        const int hairColorCount = m_partEntries[kNewHumanHairPartIndex].descriptorCount;

        hairColorFile.Open(L"HAIRCOL.TBL");

        for (int index = 0; index < hairColorCount; ++index)
        {
            memset(colorText, 0, sizeof(colorText));
            hairColorFile.ReadLine(colorText, sizeof(colorText));
            m_hairColorEntries.push_back(ParseUnsignedLongBase10(colorText));
        }

        hairColorFile.Close();
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Why this is safe as first-draft formal C++:

- It stays inside the exact target range: one complete constructor body at `0x004dfd10-0x004e024a`; helper bodies are called but not pasted into the constructor block.
- It preserves the observed source shape: `LoadMotionTable`, `LoadPartSpriteDescriptors`, and `LoadAcc2DrwTable` remain out-of-line method calls, while `Layer.tbl`, `Part.tbl`, and `HAIRCOL.TBL` stay inline in the constructor as the binary shows.
- It uses the existing local layout convention from [UID:0001VF]: `m_partEntries`, `m_layerEntries`, `m_motionEntries`, `m_acc2drwEntries`, and `m_hairColorEntries`.
- It uses the source-facing `DATFile` API already documented elsewhere in the project for `sub_49C130`, `sub_49C180`, `sub_49C310`, `sub_49C370`, `sub_49C240`, and `sub_49C160`.
- It uses inferred row names that are behavior-grounded and should be marked as inferred in support docs: `NewHumanLayerEntry`, `NewHumanPartEntry`, `childIndexes`, `spriteArchive`, `descriptorCount`, `kNewHumanHairPartIndex`, and `ParseUnsignedLongBase10`.
- It preserves binary-visible constants and row shapes: 23-byte table headers, 20-byte ANSI part names, `MultiByteToWideChar(CP_ACP, ...)`, the observed `255` destination-character argument, 32-byte layer rows, 68-byte part rows, 6-byte hair-color text rows, and hair-color count from the hair part entry descriptor count.
- It avoids IDA labels, raw `_DWORD *`, EH state variables, manual vtable stores, and explicit vector-grow helper calls. The vector/list initialization and cleanup are expressed as ordinary C++ member construction/destruction, which is the plausible source that generated the observed zeroing, sentinel allocation, and EH cleanup table.

Names used in this block are source-facing inferred names unless already present in current docs. Lack of original symbol proof is no longer treated as a blocker. The implementation should document the inferred status in the target page and layout/resource pages, not keep the C++ blank.

## Score Rationale

Raise completion to `91` because the target now has current MCP-backed coverage for:

- exact constructor boundary and successor padding
- singleton and vtable refs
- complete constructor load order
- current helper caller graph
- live decompile facts for the three loader helpers and two local vector grow helpers
- live decompile facts for `LoadLayerTable`, `LoadPartTable`, `LoadPartFrameDrawRecord`, `GetHeadCount`, and `VectorGrowAcc2Drw`
- raw string/data evidence for all constructor table literals
- cleanup/unwind table member-lifetime evidence
- formal first-draft constructor C++ under the current code-entry rule
- concrete implementation-ready helper child-page and support-doc checklist

Raise confidence to `92` because the current IDA session directly confirms function lookup, decompile behavior, xrefs, data refs, raw bytes, helper routes, and the distinction between constructor-inline loops and out-of-line loader calls. Keep confidence below final-audit range because several names in the formal block are inferred source-facing names rather than original-symbol-proven names, and exact row/type declarations still need to be synchronized into support docs during implementation.

Do not raise above `92` in the implementation callback unless the callback also creates or updates the helper/type/resource support docs and proves the row/type declarations at final-audit quality.

## Rejected Alternatives

- Reject changing canonical owner away from [UID:000092]. Dependencies on DAT readers, resource tables, EPF metadata, and vector-grow helpers do not override the receiver object and singleton/vtable evidence.
- Reject making [UID:00017R] the canonical owner. It is an aggregate/local-method cluster, while this exact range is the class constructor.
- Reject moving ownership to the file page only. The file route is correct for emission, but the constructor is a class member and should remain class-owned.
- Reject no-owner or non-emitting treatment. The target is reconstructable, has an emitter route, and has strong class evidence.
- Reject splitting the constructor range. Current lookup and byte evidence prove one function ending at `0x004e024a`, followed only by CC padding before the destructor.
- Reject inserting decompiler-style C++ with `sub_*`, raw `_DWORD *`, EH state variables, or stack buffers as formal source.
- Reject keeping formal C++ blank on the basis of unresolved helper/type/resource docs. Those blockers were researched in the corrected pass, and best-supported inferred names are sufficient for a first draft.
- Reject inventing source helper calls from the constructor to `LoadLayerTable` or `LoadPartTable`. Current xrefs show no calls to `0x004e1040` or `0x004e11b0`; the constructor contains its own inline layer and part loops.
- Reject preserving `MotionTableLocalHelperA/B` as source-facing names. Current decompilation proves those functions are reusable `Layer.tbl` and `Part.tbl` loaders.
- Reject manual edits to generated tracker, generated source comments, or coverage reports. Those must refresh through the normal validator/autogen workflow.

## Implementation Tracking Checklist

Implementation callback status on 2026-06-25: completed. The accepted by-* target/support edits were applied, the new below-gate helper pages were created and validator-registered, scoped validators exited `0`, generated refresh was checked, and all B011 leases were released.

Proof summary:

- [x] Target [UID:0002JR] now has `COMPLETION:91`, `CONFIDENCE:92`, class owner/emitter metadata, and a nonblank formal constructor `RECONSTRUCTION_CPP CODE` block.
- [x] Support docs were synchronized at report detail: class, file, layout, resource, local cluster, resolver item/page, `VectorGrowMotion`, and `DestroyMotionVector`.
- [x] New helper pages were created as below-gate/no-owner/non-emitting support pages with stable UIDs [UID:000417] through [UID:00041G].
- [x] Validator-generated `auto-generated/NexusTK/render/NewHumanImageLib.cpp` refreshed with [UID:0002JR] constructor code; final header shows validator command `000000001391` at `2026-06-25T06:21:56-04:00`.
- [x] Generated memory coverage refreshed: `auto-generated/-ag-coverage-report-by-memory.md` and `auto-generated/-ag-memory-coverage.md` final headers both show command `000000001391` at `2026-06-25T06:21:56-04:00`. Coverage marks [UID:0002JR] `coded` and helper UIDs [UID:000417] through [UID:00041G] `no-owner`/non-emitting.
- [x] Leases were released with `python source-3\project-documentation\tools\leaser\leaser.py B011 unlease`; all 20 scoped paths returned `Success`, and `current_leases.md` shows no active B011 rows.
- [x] Validator diagnostics: all scoped validators reported `ok: 1`, `generated_refresh: deferred`, and exit `0`. Early child/support validators repeated a stale `missing_ref_target` for UID `00017R`; the cluster validator command `000000001387` repaired the UID `00017R` path through validator-managed `path_update` / `reference_source_path_update`. Existing unrelated diagnostics for [UID:0002V8] and broader ignored/coverage references were validator warnings, not blockers for this accepted scope.

- [x] `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`: update metadata to `COMPLETION:91`, `CONFIDENCE:92`; preserve `CANONICAL_OWNER:000092`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000092`, and blank `EMITTER_POSITION_OPTIONAL`.
- [x] Target page: insert the exact formal `RECONSTRUCTION_CPP CODE` block from this corrected report. Do not leave the constructor block blank.
- [x] Target page: replace `Autogen parent` wording with current canonical-owner/emitter wording.
- [x] Target page: remove old 95/95 and 95+ blank-C++ gate wording. Replace it with the current combined-score/emitter gate statement and the corrected first-draft C++ readiness rationale.
- [x] Target page: preserve the current target-state note that generated tracker/source comments are stale at `74/86` or `74%`, but state that generated files refresh through validator/autogen only.
- [x] Target page: add current MCP session provenance for session `80de0a67`, health status, IDB path, module, imagebase, Hex-Rays readiness, strings cache readiness, and no-IDB-edit statement.
- [x] Target page: add current function lookup facts for `0x004dfd10`, `0x004e024a`, `0x004e0250`, `0x004e0d70`, `0x004e0dd0`, `0x004e0e20`, `0x004e1040`, `0x004e11b0`, `0x004e13b0`, `0x004e1800`, `0x004e4f10`, `0x004e50a0`, `0x004e5240`, and `0x004e5420`.
- [x] Target page: add current xref facts for constructor caller, vtable `0x0061b76c`, singleton `0x0067a760`, helper caller routes, zero xrefs to `0x004e1040`/`0x004e11b0`, and data xrefs for table literals.
- [x] Target page: add raw string/data evidence for `Motion.tbl`, `Layer.tbl`, `Part.tbl`, `acc2drw.tbl`, `HAIRCOL.TBL`, `.DSC`, `%s.EPF`, and `%s%d.EPF`; note the `get_string` caveat for adjacent UTF-16 literals.
- [x] Target page: add current loader-helper summaries for `LoadMotionTable`, `LoadLayerTable`, `LoadPartTable`, `LoadPartSpriteDescriptors`, `LoadAcc2DrwTable`, `VectorGrowAcc2Drw`, `VectorGrowLayer`, `VectorGrowMotion`, and `VectorGrowPart`.
- [x] Target page: document source-facing inferred names used in the C++ block: `DATFile`, `NewHumanLayerEntry`, `NewHumanPartEntry`, `m_partEntries`, `m_layerEntries`, `m_motionEntries`, `m_auxiliaryEntries`, `m_loadedPartList`, `m_acc2drwEntries`, `m_hairColorEntries`, `kNewHumanHairPartIndex`, `ResolveSpritePartPath`, and `ParseUnsignedLongBase10`.
- [x] Target page: add cleanup/unwind evidence from the `0x00600230` cleanup table and keep it as compiler lifetime evidence, not source code.
- [x] Target page: preserve rejected alternatives: no owner change, no range split, no blank-C++ disposition, no decompiler-style C++, no invented constructor call to `LoadLayerTable`/`LoadPartTable`, and no manual generated/coverage edits.
- [x] `by-class/NewHumanImageLib.md`: synchronize constructor status to `91/92` target recommendation, record that [UID:0002JR] now has first-draft constructor C++, and update the method-family table to replace `MotionTableLocalHelperA/B` wording with inferred `LoadLayerTable` and `LoadPartTable` if those helpers are mentioned.
- [x] `by-class/NewHumanImageLib.md`: add/update rows for `LoadPartFrameDrawRecord`, `GetHeadCount`, `LoadMotionTable`, `LoadLayerTable`, `LoadPartTable`, `LoadPartSpriteDescriptors`, `LoadAcc2DrwTable`, `VectorGrowAcc2Drw`, `VectorGrowLayer`, `VectorGrowMotion`, and `VectorGrowPart`, with the exact ranges and caller/xref status from this report.
- [x] `by-file/NewHumanImageLib.md`: synchronize generated source route and state that `auto-generated/NexusTK/render/NewHumanImageLib.cpp` should refresh from the inserted constructor C++ after scoped validation; do not hand-edit generated C++.
- [x] `by-type/by-struct/NewHumanImageLibLayout.md`: update the score only if implementation adds the inferred row/member names at report detail; otherwise keep score. Add the constructor-code field names and row declarations as inferred, including `NewHumanLayerEntry` 32-byte row, `NewHumanPartEntry` 68-byte row, `Acc2DrwEntry` 3-byte row, motion row 66-byte note, and `kNewHumanHairPartIndex` descriptor-count source. Include `partEntriesBegin + 0x210` as the `LoadAcc2DrwTable` row count source and `partEntriesBegin + 0x188` / hair part descriptor count as the `HAIRCOL.TBL` count source.
- [x] `by-resource/new-human-motion-tables.md`: incorporate current table-loader details for motion rows, layer rows, part rows, descriptor rows, accessory-draw rows, and hair-color rows; close the old "row/type/resource names block constructor C++" caveat by saying these names are now inferred enough for first-draft constructor code.
- [x] `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`: update the helper inventory with exact page specs and corrected names: `LoadLayerTable` for `0x004e1040-0x004e11af`, `LoadPartTable` for `0x004e11b0-0x004e13a7`, and the new child-page/TMP UID plan from this report.
- [x] Create `by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md` exactly per the new-child spec above. Use validator-assigned UID/TMP handling; set `COMPLETION:84`, `CONFIDENCE:86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, `Nested:0`, and blank C++.
- [x] Create `by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md` exactly per the new-child spec above. Use validator-assigned UID/TMP handling; set `84/86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank emitters, `Nested:0`, and blank C++; include current xrefs from UI/look code and the `this[1] + 0x188` count accessor behavior.
- [x] Create `by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md` exactly per the new-child spec above. Set `84/86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank emitters, `Nested:0`, and blank C++; include 23-byte header, row count, 66-byte row, per-frame 2-byte and 120-byte arrays, `VectorGrowMotion` call, and sole constructor caller.
- [x] Create `by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md` exactly per the new-child spec above. Set `84/86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank emitters, `Nested:0`, and blank C++; include zero direct xrefs, reusable `Layer.tbl` loader role, 23-byte header, 32-byte row, child-index array, and `VectorGrowLayer` call.
- [x] Create `by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md` exactly per the new-child spec above. Set `84/86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank emitters, `Nested:0`, and blank C++; include zero direct xrefs, reusable `Part.tbl` loader role, 20-byte ANSI name conversion, `ResolveSpritePartPath`, 68-byte row, and `VectorGrowPart` call.
- [x] Create `by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md` exactly per the new-child spec above. Set `84/86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank emitters, `Nested:0`, and blank C++; include per-part `.DSC` path construction, descriptor row count, 32-byte descriptor rows, nested per-motion mapping allocation, and `.DSC` string xref.
- [x] Create `by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md` exactly per the new-child spec above. Set `84/86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank emitters, `Nested:0`, and blank C++; include count from `partEntriesBegin + 0x210`, line reads, `ParseUnsignedLongBase10`, decimal digit decomposition into three flag bytes, `VectorGrowAcc2Drw` call, and fatal `Error on ACC2DRW table!` path.
- [x] Create `by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md` exactly per the new-child spec above. Set `84/86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank emitters, `Nested:-4`, and blank C++; include 3-byte element vector grow/insert behavior and sole caller `LoadAcc2DrwTable`.
- [x] Create `by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md` exactly per the new-child spec above. Set `84/86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank emitters, `Nested:-4`, and blank C++; include 32-byte element vector grow/insert behavior and callers from constructor and `LoadLayerTable`.
- [x] Update existing [UID:00017T] `by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md`: replace stale gate wording, keep range/owner, and add current 2026-06-25 MCP caller/decompile confirmation.
- [x] Create `by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md` exactly per the new-child spec above. Set `84/86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank emitters, `Nested:-4`, and blank C++; include 68-byte element vector grow/insert behavior and callers from constructor and `LoadPartTable`.
- [x] `by-item/ResolveSpritePartPath_004E19D0.md`: replace stale old-gate wording and `AUTOGEN_PARENT_UID` wording with current owner/emitter/gate terminology; document that constructor C++ now calls `ResolveSpritePartPath(part.name)`.
- [x] `by-memory/0x004e19d0-0x004e1f27.ResolveSpritePartPath.md`: make the same stale-gate/parent wording repair and keep resolver ownership as support/dependency for the constructor.
- [x] `by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md` and `by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md`: ensure old "90/90" or "95" code-gate references are replaced with current combined-score/emitter terminology.
- [x] Run scoped validators from `source-3/project-documentation` after implementation. Use these exact file-scoped commands for every target/support/new child page this report recommends editing or creating:

> Executable block R001 was removed from this report and preserved verbatim in [0002JR-NewHumanImageLibConstructor-source-quality-removed.md](0002JR-NewHumanImageLibConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.
- [x] If new child pages are created with TMP references, validate the new target pages first to assign UIDs, then validate the files that reference them so TMP references are replaced by real UID annotations.
- [x] After target validation, check generated refresh status for `auto-generated/NexusTK/render/NewHumanImageLib.cpp` and generated by-memory coverage. Do not hand-edit generated files.
- [x] Let `auto-generated/-ag-research-tracker.md` refresh only through supervisor `execute_report` after validation. Do not hand-edit validator-owned tracker rows.
- [x] Supervisor should check whether manual coverage report rows need refresh after validation. Do not edit `by-memory/-coverage-report.md` or any `-coverage-report.md` during report-only or normal callback work unless explicitly overridden.

## Validators

Implementation callback validators were run from `source-3/project-documentation` with `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240`.

| File | Command ID | Timestamp | Exit | OK | Generated refresh |
| --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md` | `000000001372` | `2026-06-25T06:19:46-04:00` | 0 | 1 | deferred |
| `by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md` | `000000001373` | `2026-06-25T06:19:47-04:00` | 0 | 1 | deferred |
| `by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md` | `000000001374` | `2026-06-25T06:19:49-04:00` | 0 | 1 | deferred |
| `by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md` | `000000001375` | `2026-06-25T06:19:59-04:00` | 0 | 1 | deferred |
| `by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md` | `000000001376` | `2026-06-25T06:20:08-04:00` | 0 | 1 | deferred |
| `by-memory/0x004e13b0-0x004e17f6.NewHumanImageLibLoadPartSpriteDescriptors.md` | `000000001377` | `2026-06-25T06:20:18-04:00` | 0 | 1 | deferred |
| `by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md` | `000000001378` | `2026-06-25T06:20:27-04:00` | 0 | 1 | deferred |
| `by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md` | `000000001379` | `2026-06-25T06:20:37-04:00` | 0 | 1 | deferred |
| `by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md` | `000000001380` | `2026-06-25T06:20:46-04:00` | 0 | 1 | deferred |
| `by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md` | `000000001381` | `2026-06-25T06:20:56-04:00` | 0 | 1 | deferred |
| `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md` | `000000001382` | `2026-06-25T06:21:06-04:00` | 0 | 1 | deferred |
| `by-class/NewHumanImageLib.md` | `000000001383` | `2026-06-25T06:21:16-04:00` | 0 | 1 | deferred |
| `by-file/NewHumanImageLib.md` | `000000001384` | `2026-06-25T06:21:26-04:00` | 0 | 1 | deferred |
| `by-type/by-struct/NewHumanImageLibLayout.md` | `000000001385` | `2026-06-25T06:21:36-04:00` | 0 | 1 | deferred |
| `by-resource/new-human-motion-tables.md` | `000000001386` | `2026-06-25T06:21:38-04:00` | 0 | 1 | deferred |
| `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md` | `000000001387` | `2026-06-25T06:21:44-04:00` | 0 | 1 | deferred |
| `by-item/ResolveSpritePartPath_004E19D0.md` | `000000001388` | `2026-06-25T06:21:52-04:00` | 0 | 1 | deferred |
| `by-memory/0x004e19d0-0x004e1f27.ResolveSpritePartPath.md` | `000000001389` | `2026-06-25T06:21:53-04:00` | 0 | 1 | deferred |
| `by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md` | `000000001390` | `2026-06-25T06:21:55-04:00` | 0 | 1 | deferred |
| `by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md` | `000000001391` | `2026-06-25T06:21:56-04:00` | 0 | 1 | deferred |

Generated-refresh proof:

- `auto-generated/NexusTK/render/NewHumanImageLib.cpp` exists, header `validator-command-id: 000000001391`, `validator-refreshed-at: 2026-06-25T06:21:56-04:00`, and contains the [UID:0002JR] constructor C++.
- `auto-generated/-ag-coverage-report-by-memory.md` exists, header `validator-command-id: 000000001391`, `validator-refreshed-at: 2026-06-25T06:21:56-04:00`, and lists [UID:0002JR] with `emits_code:true` plus helper UIDs [UID:000417] through [UID:00041G] with `emits_code:false`.
- `auto-generated/-ag-memory-coverage.md` exists, header `validator-command-id: 000000001391`, `validator-refreshed-at: 2026-06-25T06:21:56-04:00`, and marks [UID:0002JR] `coded` while helper UIDs [UID:000417] through [UID:00041G] remain `no-owner`.

Lease proof:

- Scoped B011 lease command succeeded for all 20 target/support/new-child files before validation.
- Release command `python source-3\project-documentation\tools\leaser\leaser.py B011 unlease` returned `Success` for all 20 scoped paths.
- `tools/leaser/Agents/current_leases.md` was checked after release and has no B011 rows.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/0002JR-NewHumanImageLibConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/0002JR-NewHumanImageLibConstructor-source-quality.md","timestamp":"2026-06-25T06:52:55","uid":"0002JR"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002JR-NewHumanImageLibConstructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/0002JR-NewHumanImageLibConstructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002JR"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
