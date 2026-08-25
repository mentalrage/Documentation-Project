** TARGET-REPORT-UID:00036O **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 00036O FolderTreePaneVtableData Empty-Emitter Source-Quality Report

Agent: B006
Assignment id: `B006-revise-report-00036O-FolderTreePaneVtableData-20260629`
Original report date: 2026-06-28
Current revision date: 2026-06-29

Target: [UID:00036O] `by-memory/0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md`

Report-only compliance: this pass did not edit target/support `by-*` docs, generated files, project-level files, manual coverage reports, validator/tool state, or the IDA DB. No leases were acquired. The only write is this B006 research report in the agent research folder.

## Current Revision / Supervisor Active Recheck

This 2026-06-29 revision preserves the existing report and updates it in place for current Rule 26 review. It does not supersede the 2026-06-28 evidence; it adds the current MCP spot-check, Claim And Incorporation Ledger, score-blocker/no-code audit, stale-source actions for proposed support edits, and a current implementation checklist.

Supervisor instruction checked: revise the direct B006 report-only file for [UID:00036O], do not edit target/support `by-*` docs, do not acquire leases, do not run validators as edit validation, do not run `execute_report`, and stop if MCP fails or session `86fb854e` disappears. MCP remained available for this pass.

Split repair status: no split execution is recommended in this report-only revision. [UID:00036O] is already the exact half-open `FolderTreePane` vtable-data child from `0x0061a514-0x0061a5c4`; the parent [UID:00025C] and aggregate [UID:0001XL] remain non-emitting mixed/index pages. The implementation-ready repair is source-quality/C++ marker completion for [UID:00036O] and paired support [UID:00036N], plus support-doc policy synchronization.

## Final Recommendation

[UID:00036O] should remain an exact reconstructable source-declared/generated-binary vtable-data child owned by [UID:00005A] `FolderTreePane`, but it should no longer be a blank emitter. Keep `CANONICAL_OWNER:00005A`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00005A`; add an exact formal comment-only no-code marker. This gives the generated `FolderTreePane.cpp` route a concrete source-quality disposition while still rejecting handwritten RTTI/vtable arrays.

Recommended target metadata:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `87` | `89` |
| `CONFIDENCE` | `92` | `93` |
| `CANONICAL_OWNER` | `00005A` | `00005A` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `00005A` | `00005A` |
| `RECONSTRUCTION_CPP CODE` | blank | comment-only no-code marker below |

Recommended [UID:00036O] formal `RECONSTRUCTION_CPP CODE` content:

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-emitted FolderTreePane primary/secondary/tertiary RTTI/vtable data.
// Source reconstruction is routed through [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
// class declarations and virtual method/destructor declarations; do not emit
// raw vtable arrays for this range.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended target `Item Summary`:

```markdown
Exact FolderTreePane primary/secondary/tertiary RTTI and vtable data at 0x0061a514-0x0061a5c4; source-declared/generated-binary, routed through UID00005A class declarations with a comment-only no-code marker, not raw vtable arrays.
```

The directly paired vtable-layout page [UID:00036N] has the same empty-emitter defect. It is support, not the primary queue target, but implementing [UID:00036O] cleanly should repair [UID:00036N] at the same time so the type/vtable page does not remain a blank nonblank emitter for the same compiler-generated class tables.

Recommended [UID:00036N] support metadata:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `87` | `89` |
| `CONFIDENCE` | `92` | `93` |
| `CANONICAL_OWNER` | `00005A` | `00005A` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `00005A` | `00005A` |
| `RECONSTRUCTION_CPP CODE` | blank | comment-only no-code marker below |

Recommended [UID:00036N] formal `RECONSTRUCTION_CPP CODE` content:

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-emitted FolderTreePane primary/secondary/tertiary RTTI/vtable layout.
// Source reconstruction is routed through [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
// class declarations and virtual method/destructor declarations; no raw vtable
// array is emitted from this type page.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Pre-Implementation Target State

Queue and generated state before the accepted implementation callback:

- `auto-generated/-ag-research-tracker.md` lists [UID:00036O] in `Files With Empty Emitters` as a by-memory zero-report row at `87/92`, average `89.5`, reconstructable `true`, report count `0`.
- `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` was refreshed by validator command `000000005286` at `2026-06-28T19:07:20-04:00`.
- Before this callback, the generated file emitted `// UID:00036O | by-memory\0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md | Completion:87 | Confidence:92 | Empty Emitter Marker`.
- Before this callback, the same generated file showed [UID:00036N] as an `Empty Emitter Marker` for the paired class-vtable type page. Unrelated neighboring empty emitters such as [UID:00034K], [UID:00036K], [UID:0000F9], and other FolderTreePane helper pages are separate queue items unless the supervisor explicitly expands an implementation callback.

Target header before this callback:

- `COMPLETION:87`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:00005A`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00005A`
- formal C++ blank
- `Item Summary` blank

The target body already says not to hand-port these bytes. The source-quality defect is narrower: because the formal C++ block is blank while the emitter route is nonblank, the generator still has to output an empty marker instead of an explicit no-code proof.

## Evidence Checked

Current support docs reviewed:

- [UID:00036O] `by-memory/0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md`
- [UID:00036N] `by-type/by-vtable/FolderTreePaneClassVtables.md`
- [UID:0001XL] `by-type/by-vtable/FolderTreePaneVtables.md`
- [UID:00005A] `by-class/FolderTreePane.md`
- [UID:0000JG] `by-file/FolderTreePane.md`
- [UID:00025C] `by-memory/0x0061a45c-0x0061a5c4.FolderSelectTreeReadOnlyData.md`
- [UID:000155] `by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md`
- [UID:000157] `by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md`
- [UID:000159] `by-memory/0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks.md`
- [UID:00034K] `by-memory/0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor.md`
- sibling vtable-data report context [UID:00036K] `tools/leaser/Agents/Agent-B001/research/00036K-FolderTreeVtableData-empty-emitter-source-quality.md`

Accepted reports used as leads and rechecked against current evidence:

- `executed-b-agent-research/B008/00005A-FolderTreePane-class-source-quality.md`: accepted `FolderTreePane` as a reusable `ScrollablePane`-derived control under `NexusTK/ui/controls/FolderTreePane.cpp`; it records size `0x17c`, vtable views at `+0x00/+0xa0/+0xa4`, `m_tree` at `+0x130`, `m_selection` at `+0x170`, and explicitly rejects hand-authored vtable arrays, adjustor thunks, constructor EH cleanup fragments, and scalar deleting destructor glue.
- `executed-b-agent-research/B001/000157-FolderTreePaneTreeAndSortHelpers.md`: records `0x0061a518`, `0x0061a58c`, and `0x0061a5bc` as the `FolderTreePane` views and treats scalar deleting destructors and adjustor thunks as compiler-generated support rather than standalone handwritten methods.
- `executed-b-agent-research/B009/00022E-FolderTreePaneVectorSupportHelpers-source-quality.md`: reinforces the current project pattern for compiler/template support: exact support pages with strong owner routes should use explicit comment markers or strict no-code proof instead of decompiler-shaped helper bodies or empty emitters.
- `executed-b-agent-research/B014/0000FB-FolderTreePaneTreeIterator-class-source-quality.md`: establishes the same vtable-data policy for the concrete iterator specialization: class declarations may emit source C++, while vtable/data and destructor glue remain source-declared/generated-binary support.
- Pending sibling report `tools/leaser/Agents/Agent-B001/research/00036K-FolderTreeVtableData-empty-emitter-source-quality.md`: recommends exact formal comment-only no-code markers for the `Tree<FolderTreePane::TreeElem>` vtable-data page and paired vtable-layout page. This is a direct precedent for [UID:00036O]/[UID:00036N] while using the `FolderTreePane` class route instead of the tree-wrapper route.

Project rules checked:

- `by-structure.md` classifies vtables as source-declared/generated-binary when source declarations cause the compiler to regenerate them.
- For singular pages, `CANONICAL_OWNER` records semantic documentation ownership while `EMITTER_UIDS` controls generated output routing. A known owner can still be non-emitting, but a retained nonblank emitter should not remain a blank formal block once the no-code disposition is known.
- For `by-memory` pages, formal C++ content is limited to the page's own range. [UID:00036O] cannot contain the full `FolderTreePane` class declaration or the scalar deleting destructor body; it can only carry a marker for this exact vtable-data range.

2026-06-29 current-session spot-check and acceptance evidence:

- MCP endpoint `http://127.0.0.1:13337/mcp` initialized successfully with protocol `2025-06-18`.
- `tools/list` rechecked current schemas. The active server requires `database=<session_id>` for database-backed calls.
- `idb_list` returned active adopted worker session `86fb854e`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_active:true`, `is_analyzing:false`, PID/worker PID `10220`.
- `server_health` with `database=86fb854e` returned `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready `true`, Hex-Rays ready `true`, strings cache ready `true`, strings cache size `2067`.
- `lookup_funcs` with `database=86fb854e` returned `0x00401000` -> `sub_401000` size `0x4c`, matching the supervisor MCP recovery note, and reconfirmed `0x004b5a70` -> `sub_4B5A70` size `0x84`, `0x004b59d5` -> `sub_4B59D5` size `0x0b`, `0x004b59e0` -> `sub_4B59E0` size `0x0b`, and `0x004b1b90` -> `sub_4B1B90` size `0x155`.
- `entity_query names 0x0061a4e0-0x0061a5d0` with `database=86fb854e` returned the neighboring vtable names, including `0x0061a518 ??_7FolderTreePane@@6B@`, `0x0061a58c ??_7FolderTreePane@@6B@_0`, and `0x0061a5bc ??_7FolderTreePane@@6B@_1`, with the successor name `0x0061a5d0 aOnEpf`.
- `xrefs_to` with `database=86fb854e` reconfirmed three xrefs each to `0x0061a518`, `0x0061a58c`, and `0x0061a5bc`: constructor stores at `0x004b1bd5`, `0x004b1bdb`, `0x004b1be5`; cleanup stores at `0x004b1cf4`, `0x004b1d00`, `0x004b1d0a`; and destructor stores at `0x004b5a77`, `0x004b5a83`, `0x004b5a8d`.
- `xrefs_to 0x0061a5c4` with `database=86fb854e` returned constructor/root-name references at `0x004b1c51`, `0x004b1c89`, and `0x004b2618`, preserving the successor-string boundary proof.
- `get_int` with `database=86fb854e` reconfirmed the in-range dwords: `0x0061a514=0x00647894`, `0x0061a518=0x004b5a70`, `0x0061a588=0x006478f4`, `0x0061a58c=0x004b59d5`, `0x0061a5b8=0x00647908`, `0x0061a5bc=0x004b59e0`, and `0x0061a5c0=0x00544e90`.
- `get_bytes 0x0061a5c4 size 24` with `database=86fb854e` returned UTF-16 bytes `54 00 52 00 45 00 45 00 49 00 43 00 4f 00 4e 00 2e 00 45 00 50 00 46 00`, i.e. `TREEICON.EPF`, confirming this successor is not a vtable row.
- `disasm 0x004b59d5` and `disasm 0x004b59e0` with `database=86fb854e` reconfirmed the two adjustor thunks as `sub ecx, 0A0h; jmp sub_4B5A70` and `sub ecx, 0A4h; jmp sub_4B5A70`.

The bullets above are the current active MCP evidence for supervisor acceptance. The older 2026-06-28 MCP pass below is preserved as historical lead/corroborating evidence only.

## Historical 2026-06-28 IDA MCP Evidence Preserved As Lead Evidence

The original 2026-06-28 report used MCP successfully, and those observations remain useful because they agree with the 2026-06-29 `86fb854e` spot-check. This subsection is not the current active MCP session for acceptance; current acceptance evidence is the 2026-06-29 session `86fb854e` recorded immediately above.

- Endpoint: `http://127.0.0.1:13337/mcp`
- Historical `idb_list` session: `supervisor_20260628_resume`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Historical `server_health` time: `2026-06-28T19:11:06-04:00`
- Historical `server_health` result: `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready `true`, Hex-Rays ready `true`, strings cache ready `true`, strings cache size `2067`.
- Historical listener/process state from that availability probe: `127.0.0.1:13337` listening with PID `21700`; visible MCP/worker processes included `idalib-mcp.exe` PID `10020`, Python wrapper PIDs `11320`/`21700`, and worker PIDs `5124`/`26792`.

Historical 2026-06-28 name and global evidence:

- `entity_query names 0x0061a4e0-0x0061a5d0` reports:
  - `0x0061a500` `??_7?$Tree@UTreeElem@FolderTreePane@@@@6B@`
  - `0x0061a510` `??_7?$TreeItor@UTreeElem@FolderTreePane@@@@6B@`
  - `0x0061a518` `??_7FolderTreePane@@6B@`
  - `0x0061a58c` `??_7FolderTreePane@@6B@_0`
  - `0x0061a5bc` `??_7FolderTreePane@@6B@_1`
  - `0x0061a5d0` `aOnEpf`
- `list_globals *FolderTreePane*` also reports the `FolderTreePane` RTTI locators at `0x00647894`, `0x006478f4`, and `0x00647908`, plus related type descriptors and concrete tree/iterator vtables.

Historical 2026-06-28 byte/dword evidence for [UID:00036O]:

| Address | Historical evidence | Meaning |
| --- | --- | --- |
| `0x0061a514` | bytes `94 78 64 00`; `get_int` value matches `0x00647894` | primary `FolderTreePane` RTTI locator |
| `0x0061a518` | bytes `70 5a 4b 00`; IDA name `??_7FolderTreePane@@6B@` | primary vtable base, first slot `0x004b5a70` |
| `0x0061a588` | bytes `f4 78 64 00` | secondary RTTI locator |
| `0x0061a58c` | bytes `d5 59 4b 00`; IDA name `??_7FolderTreePane@@6B@_0` | secondary `+0xa0` vtable base, first slot `0x004b59d5` |
| `0x0061a5b8` | bytes `08 79 64 00` | tertiary RTTI locator |
| `0x0061a5bc` | bytes `e0 59 4b 00`; IDA name `??_7FolderTreePane@@6B@_1` | tertiary `+0xa4` vtable base, first slot `0x004b59e0` |
| `0x0061a5c0` | bytes `90 4e 54 00` | tertiary inherited event/update slot `0x00544e90` |
| `0x0061a5c4` | bytes decode as UTF-16 `TREEICON.EPF` | mandatory successor boundary, not a virtual row |

Historical 2026-06-28 xref evidence:

- `xrefs_to 0x0061a518` reports constructor store `0x004b1bd5`, cleanup store `0x004b1cf4`, and destructor store `0x004b5a77`.
- `xrefs_to 0x0061a58c` reports constructor store `0x004b1bdb`, cleanup store `0x004b1d00`, and destructor store `0x004b5a83`.
- `xrefs_to 0x0061a5bc` reports constructor store `0x004b1be5`, cleanup store `0x004b1d0a`, and destructor store `0x004b5a8d`.
- `xrefs_to 0x0061a514`, `0x0061a588`, and `0x0061a5b8` reports no direct xrefs, which is expected for RTTI locator dwords before vtable bases rather than source-referenced literals.
- `xrefs_to 0x0061a5c0` reports no direct xrefs; it is a vtable slot used through virtual dispatch rather than by address-taken source.
- `xrefs_to 0x0061a5c4` reports constructor/root-name data refs at `0x004b1c51`, `0x004b1c89`, and `0x004b2618`, proving the successor bytes are the folder icon string path, not table slots.
- `xrefs_to 0x004b5a70` reports code refs from adjustor thunks `0x004b59db` and `0x004b59e6`, plus the primary vtable data ref at `0x0061a518`.
- `xrefs_to 0x004b59d5` reports only the secondary vtable slot data ref at `0x0061a58c`.
- `xrefs_to 0x004b59e0` reports only the tertiary vtable slot data ref at `0x0061a5bc`.

Historical 2026-06-28 function/disassembly evidence:

- `lookup_funcs` returns `0x004b5a70` `sub_4B5A70` size `0x84`, `0x004b59d5` `sub_4B59D5` size `0x0b`, and `0x004b59e0` `sub_4B59E0` size `0x0b`.
- Disassembly of `0x004b59d5` is exactly `sub ecx, 0A0h; jmp sub_4B5A70`.
- Disassembly of `0x004b59e0` is exactly `sub ecx, 0A4h; jmp sub_4B5A70`.
- Disassembly/decompilation of `0x004b5a70` restores the three `FolderTreePane` vtable views, resets the selected iterator vtable at `this+0x170`, resets the tree vtable at `this+0x130`, calls `0x004b56e0` for tree storage destruction, calls `0x004f4a90` for tree/base teardown, calls `0x0055e780` for pane/base cleanup, then handles scalar-delete flags and the `0x17c`-sized delete helper path.
- `callees 0x004b5a70` reports internal callees `0x004b56e0`, `0x004f4a90`, `0x0055e780`, `0x004f4ac0`, and guard helper `0x0041b6a0`; the two adjustor thunks have no independent callees.
- `lookup_funcs 0x004b1b90` returns the constructor `sub_4B1B90`, size `0x155`. Its decompilation/disassembly stores the three `FolderTreePane` vtable bases at `0x004b1bd5`, `0x004b1bdb`, and `0x004b1be5`, constructs `m_tree` at `+0x130`, initializes `m_folderIconContext` around `+0x148`, writes `TreeItor<FolderTreePane::TreeElem>` at `+0x170`, references `TREEICON.EPF` at `0x004b1c51` and `0x004b1c89`, and later populates/root-expands the tree. This ties the vtable data to class construction and confirms the adjacent string belongs to the constructor icon setup.
- `xrefs_to 0x004b1b90` reports a constructor call from `0x004b178b` in `FolderSelectDialog`; this remains consumer evidence only and does not override the accepted `FolderTreePane.cpp` control-source split.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | [UID:00036O] remains the exact half-open `0x0061a514-0x0061a5c4` `FolderTreePane` primary/secondary/tertiary RTTI/vtable data range; `0x0061a5c4` starts `TREEICON.EPF` and is outside the target. | Very high | Existing target docs plus 2026-06-29 MCP `entity_query`, `get_int`, `get_bytes`, and `xrefs_to 0x0061a5c4`. | [UID:00036O] Range/Contents/IDA Evidence; [UID:00036N] Vtable Inventory; [UID:00025C] child inventory; [UID:0001XL] aggregate notes. | incorporate | applied |
| C02 | Keep [UID:00036O] `CANONICAL_OWNER:00005A`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00005A`; the direct semantic owner is the `FolderTreePane` class, and generated output routes through the class/file chain. | Very high | Vtable names, constructor/destructor stores, accepted B008/B001/B014 reports, by-structure owner/emitter rules. | [UID:00036O] metadata and Reconstruction Notes; [UID:00005A] vtable/destructor boundary; [UID:0000JG] generated-output policy. | incorporate | applied |
| C03 | Raise [UID:00036O] score from `87/92` to `89/93` because the current report resolves the empty-emitter/no-code-marker defect, rechecks MCP evidence, and preserves rejected alternatives. | High | Existing score state, current MCP spot-check, implementation-ready exact marker and support plan. | [UID:00036O] metadata/Changes; support sync where score rationale is referenced. | incorporate | applied |
| C04 | Insert the exact formal comment-only `RECONSTRUCTION_CPP CODE` marker for [UID:00036O]; do not emit raw vtable arrays, address tables, destructor bodies, or class declarations in this by-memory page. | Very high | By-structure C++ gate/range limit, current vtable evidence, source-declared/generated-binary policy. | [UID:00036O] formal `RECONSTRUCTION_CPP CODE` block. | incorporate | applied |
| C05 | [UID:00036N] is the paired type/vtable support page for the same class tables and should receive matching `89/93` metadata and a paired formal comment-only no-code marker. | High | [UID:00036N] current blank formal block, same owner/emitter state, same MCP evidence and target data range. | [UID:00036N] metadata, Status/Vtable Inventory, formal `RECONSTRUCTION_CPP CODE`, Changes. | incorporate | applied |
| C06 | [UID:0001XL] remains a mixed non-emitting aggregate; only add policy text that [UID:00036N]/[UID:00036O] now carry comment-only markers and preserve rejection of aggregate C++, raw vtable arrays, and string-derived false virtual rows. | High | [UID:0001XL] existing `RECONSTRUCTABLE:FALSE`, exact child split, 2026-06-29 boundary evidence. | [UID:0001XL] child/aggregate policy notes. | incorporate | applied |
| C07 | [UID:00005A] should preserve class-level declaration-only C++ and record that [UID:00036N]/[UID:00036O] are compiler-emitted class vtable layout/data markers routed through this class shell. | High | Accepted B008 class route, current class/vtable evidence, by-structure range limits. | [UID:00005A] vtables/destructor/source-boundary notes. | incorporate | applied |
| C08 | [UID:0000JG] should record generated-output/no-code policy for [UID:00036N]/[UID:00036O] while preserving existing rejection of raw vtable arrays, adjustor thunk bodies, constructor EH fragments, and scalar deleting destructor glue. | High | Existing file policy and accepted B008/B014/B001 source-shape reports. | [UID:0000JG] generated-output/no-code policy section. | incorporate | applied |
| C09 | [UID:00025C] remains a mixed `.rdata` index with `RECONSTRUCTABLE:FALSE`, blank owner, and blank emitter; sync only the [UID:00036O] observed-content/owner-split note to say the exact child carries a formal no-code marker. | High | Existing [UID:00025C] state and child split; current target boundary proof. | [UID:00025C] child table/reconstruction notes. | incorporate | applied |
| C10 | Support-doc stale-source wording must not be reactivated: [UID:00005A] and [UID:0000JG] already historicalize Wave3/simroot/recovered-source material as lead/provenance only; preserve that wording and do not use it as authority. | High | 2026-06-29 `rg` scan for `Wave2|Wave3|simroot|recovered-source|AUTOGEN_PARENT`; current docs already mark old generated source as historical lead material. | [UID:00005A] and [UID:0000JG] historical generated-source notes; implementation checklist support stale-source actions. | already-present | already-present |
| C11 | [UID:0001XL] has a historical `Wave3 data issues` cross-reference; no stale active source-route claim was found there, so preserve it as historical/support context and do not edit it into authority. | Medium-high | 2026-06-29 support stale-source scan. | [UID:0001XL] cross-reference/history context. | already-present | already-present |
| C12 | Do not edit [UID:00034K], [UID:000159], [UID:00036K], [UID:00036M], or sibling tree/iterator pages in this callback unless supervisor expands scope; they are context, not required to resolve [UID:00036O]. | High | Current report scope and source-quality blocker audit; [UID:00034K] remains separate queue/source-quality item. | Implementation checklist and support-doc change plan. | not-applicable | excluded-with-reason |

## Source-Quality Analysis

## Heuristic / Inference Reanalysis And Validation

The earlier recommendation still validates under the current evidence. The important source-quality question is not whether bytes exist at `0x0061a514-0x0061a5c4`; the direct MCP facts prove the bytes and names. The question is which source item should cause those bytes in the rebuilt program and what, if anything, should appear in generated C++ for this exact page.

Validated inferences:

- Source-facing role: the target is `FolderTreePane` compiler-emitted RTTI/vtable data, not handwritten static source data. This is direct IDA fact for the named vtable bases plus inference from MSVC RTTI/vtable layout and constructor/destructor vptr stores.
- Direct owner: [UID:00005A] `FolderTreePane` remains the best direct semantic owner because the data is class layout output. [UID:0000JG] is the file-level route through the class, not the narrow owner for the data child.
- Source placement: the generated C++ route should remain `FolderTreePane.cpp` through [UID:00005A]/[UID:0000JG], but the source text for this exact page should be a no-code comment marker explaining that the class declarations regenerate the table.
- Boundary: `0x0061a5c4` is not a vtable slot. Current MCP byte and xref checks prove it begins the UTF-16 `TREEICON.EPF` string used by constructor/root-name setup.
- Placeholder/source naming: the IDA names are decorated compiler names (`??_7FolderTreePane@@6B@`, suffix `_0`, `_1`); they are valid binary labels but not source declarations to paste into rebuilt C++. The report therefore uses source-facing descriptions `FolderTreePane primary/secondary/tertiary RTTI/vtable data` and `secondary/tertiary adjustor thunk`.
- Raw helper liveness: `0x004b59d5` and `0x004b59e0` are live adjustor thunks into `0x004b5a70`, but they are compiler-generated support and do not create an independent source body for [UID:00036O].

Rejected alternatives:

- Raw vtable/address arrays are rejected because they would encode compiler output and fixed executable addresses as source.
- A standalone `Vtables.cpp` or by-global owner is rejected because the class declaration is the source-level cause and there is no source-authored table object.
- `FolderSelectDialog` ownership is rejected because constructor use is consumer evidence only; the table belongs to `FolderTreePane` class layout.
- `RECONSTRUCTABLE:FALSE` is rejected because the rebuilt executable needs equivalent class table output, just not hand-authored table bytes.
- Clearing `EMITTER_UIDS` is rejected for this exact child because the owner/emitter route is strong and the formal no-code marker can make the generated route nonblank and self-explanatory.
- Emitting the full class declaration, scalar deleting destructor body, or adjustor thunk bodies in [UID:00036O] is rejected because those source declarations/bodies belong to [UID:00005A], [UID:00034K], [UID:000159], or other linked pages, not this data range.

Unresolved issues and score/C++ impact:

- Exact original spellings for all inherited virtual methods remain outside this page and on linked class/vtable pages; this prevents final-audit scoring but does not block the no-code marker for [UID:00036O]/[UID:00036N].
- [UID:00034K] scalar deleting destructor source-quality remains a separate queue/support issue and should not be solved in this report-only revision. It is not a blocker for this marker because [UID:00036O] only records table data and the source-level destructor declaration route.

## Ranked Ownership Analysis

### 1. [UID:00005A] `FolderTreePane` class

- Evidence for: direct decorated vtable names for `FolderTreePane`, constructor and destructor stores to all three vtable bases, accepted class layout with primary/secondary/tertiary views, and by-structure rule that class vtables belong to the class when the class declaration is the source-level cause.
- Evidence against: the generated file route ultimately goes through [UID:0000JG], and the data is physically `.rdata`; neither fact defeats class ownership because [UID:00005A] is the narrow semantic owner and [UID:0000JG] is the source-file route.
- Decision: accepted. Keep `CANONICAL_OWNER:00005A` and `EMITTER_UIDS:00005A`.

### 2. [UID:0000JG] `FolderTreePane.cpp` file page

- Evidence for: the generated C++ route surfaces through this file page, and accepted FolderTreePane source-shape reports place the control implementation under `ui/controls/FolderTreePane.cpp`.
- Evidence against: by-structure requires the narrowest true semantic owner; the vtable data belongs to the class layout rather than a free file-scope object.
- Decision: rejected as canonical owner for [UID:00036O]/[UID:00036N], retained as the file-level route through [UID:00005A].

### 3. [UID:0001XL] `FolderTreePaneVtables` aggregate or [UID:00025C] `.rdata` parent

- Evidence for: both aggregate/index pages contain or reference the physical range.
- Evidence against: both are mixed-owner containers/indexes with exact children already split; they should not emit source or own the class-specific child.
- Decision: rejected as owner/emitter. Preserve as non-emitting support context only.

### 4. [UID:00034K] scalar deleting destructor or [UID:000159] adjustor thunks

- Evidence for: the primary/secondary/tertiary first slots point to these destructor/thunk code paths.
- Evidence against: slot targets are consumers of the vtable layout, not owners of the table data. The source-level cause is the class declaration and virtual destructor declaration.
- Decision: rejected as owner/emitter for this data page; keep as linked evidence only.

### 5. New standalone vtable/global source owner

- Evidence for: the table is concrete global `.rdata`.
- Evidence against: no source-authored global table is indicated; a standalone owner would invent source structure and invite raw address arrays.
- Decision: rejected.

## Source Placement

Recommended source placement: source-declared/generated-binary support routed through [UID:00005A] `FolderTreePane`, which surfaces through [UID:0000JG] `FolderTreePane.cpp`. The only formal content for [UID:00036O]/[UID:00036N] should be the exact comment-only markers in this report. The class page remains responsible for the source declarations and virtual destructor declaration that make the compiler regenerate equivalent RTTI/vtable data.

Rejected placements: `FolderSelectDialog` consumer ownership, a standalone vtable/global file, raw `DWORD[]` table source, aggregate [UID:0001XL] emission, and parent [UID:00025C] emission.

### Boundary And Direct Owner

The target range is exactly `0x0061a514-0x0061a5c4`.

- `0x0061a514` is the primary RTTI locator dword before the named primary `FolderTreePane` vtable at `0x0061a518`.
- The target includes primary, secondary, and tertiary `FolderTreePane` vtable views, matching object views at `+0x00`, `+0xa0`, and `+0xa4`.
- `0x0061a5c0` is the final in-range tertiary slot. The next address, `0x0061a5c4`, decodes to UTF-16 `TREEICON.EPF` and has constructor/root-setup xrefs. It must remain outside this target.
- The direct semantic owner is [UID:00005A] `FolderTreePane`, not [UID:0000JG] directly, because the data belongs to the class layout. [UID:0000JG] is still the source-file route through [UID:00005A].
- [UID:0001XL] and [UID:00025C] are intentionally non-emitting aggregates because they span multiple direct owners. [UID:00036O] is different: it is an exact class-owned child.

### Why Raw Vtable C++ Is Wrong

The target bytes are MSVC-style RTTI/vtable artifacts generated from class declarations, virtual methods, inheritance layout, and destructor declarations. A raw C++ array such as a `DWORD` table, synthetic `vftable` object, or address initializer naming `sub_4B5A70`, `sub_4B59D5`, and `sub_4B59E0` would be reverse-engineering scaffolding, not plausible original source. It would also embed fixed binary addresses into source and duplicate compiler output.

The source-level reconstruction already belongs in [UID:00005A]:

- `class FolderTreePane : public ScrollablePane`
- `virtual ~FolderTreePane();`
- virtual method declarations for paint/scroll/input/content paths
- field layout causing `m_tree` at `+0x130`, icon context near `+0x148`, and `m_selection` at `+0x170`

Those declarations cause the compiler to regenerate equivalent vtable data. [UID:00036O] should only prove the binary table and route it to the class declaration owner.

### Why `RECONSTRUCTABLE:FALSE` Is Wrong

[UID:00036O] is not a broad parent/index and not purely irrelevant bytes. The rebuilt executable needs an equivalent `FolderTreePane` vtable/RTTI layout, but it should be generated by the compiler from source declarations. This is the project meaning of source-declared/generated-binary reconstructable data. Therefore `RECONSTRUCTABLE:TRUE` should remain.

The false/non-emitting classification is already correctly applied to:

- [UID:0001XL], the mixed vtable cluster spanning `Tree`, `TreeItor`, and `FolderTreePane` direct owners.
- [UID:00025C], the mixed `.rdata` inventory spanning `FolderSelectDialog`, drive-root string data, tree/iterator vtables, and `FolderTreePane` vtables.

### Why Clearing `EMITTER_UIDS` Is Not The Best Repair

Clearing `EMITTER_UIDS` would remove the empty marker, and by-structure permits owned pages to be non-emitting when generated output is not useful. For this target, however, the owner and route are strong enough to keep. [UID:00005A] already emits the class shell through [UID:0000JG] into `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp`, and the exact vtable page is useful trace evidence in that generated file.

The stronger repair is to keep `EMITTER_UIDS:00005A` and make the formal block nonblank with a comment-only marker. That resolves the empty-emitter state while preserving the important source-quality claim: no raw vtable arrays.

### Covered-By Marker Versus No-Code Marker

A plain "covered by UID00005A" marker would be directionally correct but too thin. This target is not method body code duplicated in another exact range; it is compiler-generated class data caused by class declarations. The marker should explicitly say "compiler-emitted RTTI/vtable data" and "do not emit raw vtable arrays." That makes the generated output self-explanatory and prevents future agents from treating the nonblank marker as permission to paste address arrays.

### Support Page [UID:00036N]

[UID:00036N] is the paired type/vtable layout page for the same class tables and currently has the same nonblank emitter plus blank formal C++ block. Leaving [UID:00036N] unchanged after repairing [UID:00036O] would preserve the same empty-emitter source-quality defect one level up. It should receive the paired no-code marker and the same score movement.

### Related Empty Emitters Not Resolved By This Report

The generated `FolderTreePane.cpp` currently contains other `Empty Emitter Marker` entries, including [UID:00034K] scalar deleting destructor support and sibling tree/template support pages. This report does not recommend editing them unless the supervisor expands the callback. For [UID:00036O], the necessary exact source disposition is independent: vtable bytes are generated from [UID:00005A] class declarations, not from a raw body in [UID:00036O] and not from the scalar deleting destructor page itself.

## Positive Evidence Summary

- Current MCP confirms the exact target bytes, names, and half-open boundary.
- Current MCP confirms the constructor writes all three class vtable bases and uses `TREEICON.EPF` immediately after the target range.
- Current MCP confirms the destructor restores all three class vtable bases and resets embedded tree/iterator vtables before base/member teardown.
- Current MCP confirms the secondary and tertiary slot targets are adjustor thunks into the scalar deleting destructor, not handwritten methods.
- Current docs and accepted B008/B001/B014 reports converge on [UID:00005A] as the class owner and [UID:0000JG] as the source-file output route.
- Sibling [UID:00036K] report provides an accepted-current pattern for exact vtable-data children: keep the reconstructable owner/emitter route, insert a formal comment-only no-code marker, and reject raw vtable arrays.

## Negative Evidence Summary

- No evidence supports treating `0x0061a5c4` or following `TREEICON.EPF` bytes as more virtual rows; current xrefs route them through constructor/root icon setup.
- No evidence supports moving this class-vtable data to `FolderSelectDialog`; the single constructor caller is consumer evidence, while class vtables, local tree/template support, paint/input methods, and accepted source-file placement support `FolderTreePane`.
- No evidence supports a standalone `Vtables.cpp`, raw `DWORD[]`, or IDA-address table as plausible original mid-2000s source.
- No evidence supports marking the exact child as `RECONSTRUCTABLE:FALSE`; the table must exist in the rebuilt executable, but compiler output should create it.
- No evidence supports putting the full `FolderTreePane` class declaration, destructor body, or scalar deleting wrapper body inside [UID:00036O]; those would be outside the by-memory range and violate the source-declared/generated-binary model.

## Score And Metadata Rationale

Recommended [UID:00036O] score: `89/93`.

Reasons to raise completion from `87` to `89`:

- The report resolves the blank formal C++/empty-emitter state with an exact implementation-ready marker.
- Current MCP reverified target bytes, names, xrefs, constructor/destructor/thunk relationships, and the successor string boundary.
- The report explicitly rejects raw vtable arrays, `RECONSTRUCTABLE:FALSE`, and blank/non-emitting route changes for this exact child.
- The required target/support changes and validation plan are implementation-ready.

Reasons to raise confidence from `92` to `93`:

- Current live IDA evidence agrees with the existing 2026-06-11 target docs and accepted executed reports.
- The class owner and emitter route are stronger than a mere adjacency inference: they are supported by IDA names, constructor/destructor vptr stores, class layout docs, and accepted `FolderTreePane.cpp` source placement.

Reasons not higher:

- Exact original virtual method names for inherited slots are still represented by descriptive roles on linked class/vtable pages.
- The scalar deleting destructor support page [UID:00034K] remains a separate empty-emitter/source-quality item and should receive its own callback or queue pass.
- Final shared tree-template/header factoring and a few `FolderTreePane` private helper spellings remain below final-audit certainty on linked owner pages.

Recommended [UID:00036N] score: `89/93` for the same reason if the paired support repair is accepted.

## Score-Blocker / No-Code Audit

Current score/source-quality blockers named by this report and their audited disposition:

| Blocker | Current-pass audit result | Disposition |
| --- | --- | --- |
| Blank formal C++ while [UID:00036O] has nonblank `EMITTER_UIDS:00005A` | Resolved by exact implementation-ready comment-only `RECONSTRUCTION_CPP CODE` marker for [UID:00036O]. | Implementation-ready repair |
| Paired [UID:00036N] type/vtable page has the same empty-emitter defect | Resolved by exact paired marker recommendation and support checklist item. | Implementation-ready repair |
| Risk of raw vtable arrays or address tables | Current by-structure rules, MCP vtable facts, and source-declared/generated-binary policy reject raw arrays; marker text explicitly says not to emit them. | Resolved/rejected alternative preserved |
| Risk of incorrect non-emitting downgrade or `RECONSTRUCTABLE:FALSE` | Rechecked against by-structure source-declared/generated-binary policy: equivalent vtable data is required in the rebuilt binary and should be compiler-generated from class declarations. | Resolved/rejected alternative preserved |
| Successor `TREEICON.EPF` false virtual rows | 2026-06-29 MCP `xrefs_to` and `get_bytes` prove the successor string boundary. | Resolved |
| Stale Wave2/Wave3/simroot/recovered-source support wording | Support scan found [UID:00005A]/[UID:0000JG] already historicalize old generated source as lead/provenance only; [UID:0001XL] has only a historical `Wave3 data issues` cross-reference. No stale wording should be promoted to authority. | Already-present/historicalize-preserve |
| Other `FolderTreePane.cpp` empty emitters such as [UID:00034K] | They are separate queue/source-quality items. The current report proves [UID:00036O]/[UID:00036N] are independently repairable and lists sibling pages as no-edit unless supervisor expands scope. | Not applicable to this callback |

No named in-scope blocker remains as "future work." Remaining uncertainty is either outside this assignment scope or does not block the target-specific no-code marker.

## First-Draft C++ Recommendation / Exact No-Code Proof

Eligible for draft C++: [UID:00036O] and [UID:00036N] pass the current combined-score/emitter gate after the recommended score movement and have confirmed emitter route [UID:00005A] -> [UID:0000JG] -> `FolderTreePane.cpp`. The correct formal content is still comment-only no-code marker text, not executable source C++.

Exact no-code proof:

- The target range is `.rdata` RTTI/vtable data, not a source-authored function body or source-authored global table.
- MSVC regenerates this data from class declarations, inheritance layout, virtual method declarations, and destructor declarations.
- Raw C++ arrays would duplicate compiler/linker output, rely on fixed executable addresses, and look like reverse-engineering scaffolding rather than plausible original source.
- The formal marker is appropriate because it gives the generated file a nonblank, auditable source disposition while preserving exact behavior through [UID:00005A] class reconstruction.

Exact formal [UID:00036O] `RECONSTRUCTION_CPP CODE` insertion text remains:

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-emitted FolderTreePane primary/secondary/tertiary RTTI/vtable data.
// Source reconstruction is routed through [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
// class declarations and virtual method/destructor declarations; do not emit
// raw vtable arrays for this range.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact formal [UID:00036N] `RECONSTRUCTION_CPP CODE` insertion text remains:

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-emitted FolderTreePane primary/secondary/tertiary RTTI/vtable layout.
// Source reconstruction is routed through [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)
// class declarations and virtual method/destructor declarations; no raw vtable
// array is emitted from this type page.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Third-party import directive: not applicable. This is compiler-emitted class data, not vetted staged third-party source.

## Recommended Support Doc Changes

If the supervisor accepts this report, update these support pages at report-level detail:

- [UID:00036O] `by-memory/0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md`
  - Update metadata to `COMPLETION:89`, `CONFIDENCE:93`; keep owner/reconstructable/emitter unchanged.
  - Insert the exact no-code marker shown above.
  - Populate `Item Summary` with the recommended concise summary.
  - Add current MCP evidence for bytes/names/xrefs, constructor/destructor/thunk relationships, and `TREEICON.EPF` boundary.
  - Add the no-raw-array rationale, rejected alternatives, and note that [UID:00034K] remains a separate source-quality item.

- [UID:00036N] `by-type/by-vtable/FolderTreePaneClassVtables.md`
  - Update metadata to `COMPLETION:89`, `CONFIDENCE:93`; keep owner/reconstructable/emitter unchanged.
  - Insert the paired no-code marker shown above.
  - Add a short empty-emitter disposition section stating that this page is compiler-emitted vtable layout evidence routed through [UID:00005A], not an emitted raw table.
  - Refresh its evidence/prose with the current MCP slot/xref/boundary details.

- [UID:0001XL] `by-type/by-vtable/FolderTreePaneVtables.md`
  - Preserve `RECONSTRUCTABLE:FALSE` and blank emitter for the mixed aggregate.
  - Add that [UID:00036N]/[UID:00036O] now use comment-only no-code markers for the `FolderTreePane` class vtable route.
  - Preserve the rejected alternatives: no aggregate C++, no hand-authored vtable arrays, and no string-derived false virtual rows after `TREEICON.EPF`.

- [UID:00005A] `by-class/FolderTreePane.md`
  - Add/sync the vtables/destructors/C++ boundary wording so [UID:00036N]/[UID:00036O] are explicit compiler-emitted class vtable data/layout markers routed through this class shell.
  - Preserve the class-level formal C++ as declaration-level only; do not add vtable arrays or raw destructor/thunk bodies to the class page.

- [UID:0000JG] `by-file/FolderTreePane.md`
  - Add a generated-output/no-code policy note that the class vtable data child [UID:00036O] and vtable layout page [UID:00036N] are traced in generated output with comment-only no-code markers through [UID:00005A].
  - Preserve the current B008/B014 policy rejecting vtable arrays, adjustor thunk bodies, constructor EH cleanup fragments, and scalar deleting destructor glue.

- [UID:00025C] `by-memory/0x0061a45c-0x0061a5c4.FolderSelectTreeReadOnlyData.md`
  - Keep the mixed parent `RECONSTRUCTABLE:FALSE`, owner blank, and emitter blank.
  - Update the [UID:00036O] observed-content/owner-split/reconstruction notes to state the exact `FolderTreePane` vtable child now carries a formal no-code marker, not raw source arrays.

No support edit is recommended for [UID:00034K], [UID:000159], [UID:00036K], [UID:00036M], or sibling tree/iterator pages in this callback unless the supervisor explicitly expands the implementation. They are relevant context, but [UID:00036O] is fully repairable through the target plus [UID:00036N] and high-level support docs above.

## Recommended Target Doc Changes

Target path: [UID:00036O] `by-memory/0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md`

- Metadata: update `COMPLETION:87` -> `89`, `CONFIDENCE:92` -> `93`; keep `CANONICAL_OWNER:00005A`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005A`, and blank `EMITTER_POSITION_OPTIONAL`.
- Formal C++: insert the exact [UID:00036O] comment-only marker from this report and no other source text.
- Item Summary: use the recommended summary from this report.
- Evidence/prose: add the current MCP session `86fb854e` facts for vtable names, in-range dwords, constructor/destructor xrefs, adjustor thunk disassembly, and `TREEICON.EPF` successor boundary.
- Rationale to preserve: source-declared/generated-binary handling, no raw vtable arrays, no `RECONSTRUCTABLE:FALSE`, no clearing `EMITTER_UIDS`, no class declaration/destructor body in this by-memory page, and [UID:00034K] as a separate source-quality item.

## Support Stale-Source Actions

The 2026-06-29 support scan checked proposed support docs for `Wave2`, `Wave3`, `simroot`, `recovered-source`, and legacy `AUTOGEN_PARENT` wording.

| Support doc | Stale-source scan result | Required implementation action |
| --- | --- | --- |
| [UID:00036N] `by-type/by-vtable/FolderTreePaneClassVtables.md` | No Wave2/Wave3/simroot/recovered-source wording found in the current file. | No stale-source edit needed; add only the marker/evidence/policy details listed above. |
| [UID:0001XL] `by-type/by-vtable/FolderTreePaneVtables.md` | Contains a historical cross-reference to `wave3_data_issues.md`, but no active Wave3/simroot source-route claim. | Preserve as historical/support context; do not promote it to ownership or C++ authority. |
| [UID:00005A] `by-class/FolderTreePane.md` | Already states `source-3/simroot_v2/class_FolderTreePane.cpp` and Wave3/Ghidra size data are historical generated-source leads/provenance only, not current authority. | Preserve/historicalize-present wording; add [UID:00036N]/[UID:00036O] class-vtable marker sync without relying on Wave3/simroot as proof. |
| [UID:0000JG] `by-file/FolderTreePane.md` | Already states simroot/Wave3/recovered-source material is historical generated lead material and current source-route authority is current by-* docs plus MCP-backed evidence. | Preserve/historicalize-present wording; add generated-output/no-code policy for [UID:00036N]/[UID:00036O] using current report/MCP evidence, not old generated source. |
| [UID:00025C] `by-memory/0x0061a45c-0x0061a5c4.FolderSelectTreeReadOnlyData.md` | Contains legacy `AUTOGEN_PARENT_UID` wording in old change notes from 2026-06-11; it is historical change-log text, not active metadata. | Leave historical change note intact unless supervisor wants a broader cleanup; do not use it as current owner/emitter authority. |

## Validation Plan For Implementation Callback

After accepted implementation edits, run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00036O-FolderTreePaneVtableData-empty-emitter-source-quality-removed.md](00036O-FolderTreePaneVtableData-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Then verify generated freshness and marker state:

> Executable block R002 was removed from this report and preserved verbatim in [00036O-FolderTreePaneVtableData-empty-emitter-source-quality-removed.md](00036O-FolderTreePaneVtableData-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected generated result for this assignment:

- [UID:00036O] no longer appears as `Empty Emitter Marker`.
- [UID:00036N] no longer appears as `Empty Emitter Marker` if the paired support repair is accepted.
- The exact comment-only no-code marker text appears under the generated [UID:00036O] and [UID:00036N] annotations.
- Unrelated empty markers in `FolderTreePane.cpp`, including [UID:00034K], [UID:00036K], and other sibling pages unless separately repaired, may remain.

Do not run `execute_report`; the supervisor owns that lifecycle command.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual `-coverage-report.md` or supervisor-owned tracker edit text is required from this report. The intended coverage/generated state change should come from updating the source by-* docs during an accepted implementation callback, running scoped validators with `--wait-generated`, and then supervisor-owned `execute_report` after verification. Do not manually edit validator-owned `auto-generated/-ag-*` reports.

## Implementation Callback Proof - 2026-06-29

Changed target/support docs:

- [UID:00036O] `by-memory/0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md`: metadata updated to `89/93`; owner/reconstructable/emitter unchanged; exact formal no-code marker inserted; `Item Summary` populated; MCP session `86fb854e` evidence, rejected alternatives, and `## Changes` proof added.
- [UID:00036N] `by-type/by-vtable/FolderTreePaneClassVtables.md`: metadata updated to `89/93`; owner/reconstructable/emitter unchanged; paired formal no-code marker inserted; current MCP evidence, vtable-layout no-raw-array rationale, empty-emitter disposition, and `## Changes` proof added.
- [UID:0001XL] `by-type/by-vtable/FolderTreePaneVtables.md`: aggregate metadata unchanged; added UID00036N/UID00036O comment-only marker policy through UID00005A and preserved no aggregate C++, no raw vtable arrays, and no string-derived virtual rows.
- [UID:00005A] `by-class/FolderTreePane.md`: class metadata and formal declaration-level C++ unchanged; added class-level vtable/destructor/C++ boundary wording for UID00036N/UID00036O and preserved historical simroot/Wave3 wording as lead material only.
- [UID:0000JG] `by-file/FolderTreePane.md`: file metadata unchanged; added generated-output/no-code policy for UID00036N/UID00036O and preserved existing historicalized Wave3/simroot/recovered-source wording.
- [UID:00025C] `by-memory/0x0061a45c-0x0061a5c4.FolderSelectTreeReadOnlyData.md`: mixed parent metadata unchanged; synced UID00036O observed-content/reconstruction notes as exact no-code `FolderTreePane` vtable evidence; legacy `AUTOGEN_PARENT_UID` change-log wording left historical.

Excluded by accepted scope:

- [UID:00034K], [UID:000159], [UID:00036K], [UID:00036M], and sibling tree/iterator pages were not edited. They remain context or separate queue/source-quality items.

Leases:

- Took one B006 lease batch on the six edited by-* docs before editing.
- Cleanup `unlease` reported `Rejected[No active lease]` for all six paths, meaning the short leases had already expired by cleanup. The shared lease report after cleanup showed no active B006 lease rows; only old expired Supervisor rows from 2026-06-18 remained.

Validators run from `E:\NTK\GhidraBridge\source-3\project-documentation` after edits:

| File | Command | command_id | command_timestamp | exit | ok | generated refresh |
| --- | --- | --- | --- | --- | --- | --- |
| `by-memory\0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md` | `python .\tools\validator.py --mode file --file by-memory\0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md --apply --queue-timeout 240 --wait-generated` | `000000000353` | `2026-06-29T02:17:57-04:00` | `0` | `1` | completed, command `000000000353` |
| `by-type\by-vtable\FolderTreePaneClassVtables.md` | `python .\tools\validator.py --mode file --file by-type\by-vtable\FolderTreePaneClassVtables.md --apply --queue-timeout 240 --wait-generated` | `000000000354` | `2026-06-29T02:18:06-04:00` | `0` | `1` | completed, command `000000000354` |
| `by-type\by-vtable\FolderTreePaneVtables.md` | `python .\tools\validator.py --mode file --file by-type\by-vtable\FolderTreePaneVtables.md --apply --queue-timeout 240 --wait-generated` | `000000000355` | `2026-06-29T02:18:20-04:00` | `0` | `1` | completed, command `000000000355` |
| `by-class\FolderTreePane.md` | `python .\tools\validator.py --mode file --file by-class\FolderTreePane.md --apply --queue-timeout 240 --wait-generated` | `000000000356` | `2026-06-29T02:18:33-04:00` | `0` | `1` | completed, command `000000000356` |
| `by-file\FolderTreePane.md` | `python .\tools\validator.py --mode file --file by-file\FolderTreePane.md --apply --queue-timeout 240 --wait-generated` | `000000000357` | `2026-06-29T02:18:49-04:00` | `0` | `1` | completed, command `000000000357` |
| `by-memory\0x0061a45c-0x0061a5c4.FolderSelectTreeReadOnlyData.md` | `python .\tools\validator.py --mode file --file by-memory\0x0061a45c-0x0061a5c4.FolderSelectTreeReadOnlyData.md --apply --queue-timeout 240 --wait-generated` | `000000000358` | `2026-06-29T02:19:04-04:00` | `0` | `1` | completed, command `000000000358` |

Validator side effects:

- Validator refreshed generated/project state through documented commands; this includes generated metadata/report/projected stats side effects reported by validator. These files were not manually edited by B006.
- Known unrelated stale registry/missing-file diagnostics remain in validator output; no target-specific validator failure occurred.

Generated output check:

- `rg -n "validator-command-id|validator-refreshed-at|UID:00036O|UID:00036N|Empty Emitter Marker" auto-generated\NexusTK\ui\controls\FolderTreePane.cpp`
- Generated header: `validator-command-id: 000000000358`, `validator-refreshed-at: 2026-06-29T02:19:04-04:00`, equal to the final scoped validator command metadata.
- UID00036O appears at generated line 33 as `Completion:89 | Confidence:93` with the exact comment-only marker text and no `Empty Emitter Marker`.
- UID00036N appears at generated line 41 as `Completion:89 | Confidence:93` with the exact paired comment-only marker text and no `Empty Emitter Marker`.
- Unrelated `FolderTreePane.cpp` empty markers remain for other pages, as expected by the accepted report.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation; B006 did not edit target/support `by-*` docs in the report-only revision. Proof: supervisor accepted the report and current `goal.md` moved B006 to implementation callback.
- [x] Claim And Incorporation Ledger reviewed and each accepted claim mapped to a destination doc/section or explicit no-edit/not-applicable action. Proof: ledger verification states updated; C01-C09 applied, C10-C11 already present, C12 excluded with reason.
- [x] Lease only immediate files during a future implementation callback, then release immediately after edit/validation. Proof: one B006 lease batch taken for the six by-* docs; cleanup found no active B006 leases because they had already expired.
- [x] Update [UID:00036O] `by-memory/0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md`: metadata to `89/93`, owner/reconstructable/emitter unchanged, exact formal no-code marker inserted, `Item Summary` populated, current MCP evidence added, no-code/rejected-alternative rationale added, and `## Changes` entry added.
- [x] Update [UID:00036N] `by-type/by-vtable/FolderTreePaneClassVtables.md`: metadata to `89/93`, owner/reconstructable/emitter unchanged, exact paired formal no-code marker inserted, vtable-layout no-raw-array rationale added, current MCP evidence synchronized, and `## Changes` entry added.
- [x] Update [UID:0001XL] `by-type/by-vtable/FolderTreePaneVtables.md`: preserve non-emitting aggregate classification; add [UID:00036N]/[UID:00036O] no-code marker policy; preserve rejected aggregate/raw-array/string-derived-virtual alternatives; preserve its historical Wave3-data cross-reference as context only.
- [x] Update [UID:00005A] `by-class/FolderTreePane.md`: sync class-level vtable/destructor/C++ boundary text so [UID:00036N]/[UID:00036O] are explicit compiler-emitted vtable layout/data markers routed through this class shell; preserve existing simroot/Wave3 historical-lead wording and do not add raw vtable or thunk/destructor bodies.
- [x] Update [UID:0000JG] `by-file/FolderTreePane.md`: add generated-output/no-code policy note for [UID:00036N]/[UID:00036O]; preserve the current no-raw-vtable/no-thunk/no-EH-cleanup policy and existing historicalized Wave3/simroot/recovered-source wording.
- [x] Update [UID:00025C] `by-memory/0x0061a45c-0x0061a5c4.FolderSelectTreeReadOnlyData.md`: keep parent false/non-emitting; sync [UID:00036O] row/notes as exact no-code `FolderTreePane` vtable evidence; leave legacy `AUTOGEN_PARENT_UID` mention as historical change-log text unless supervisor expands cleanup.
- [x] Do not edit [UID:00034K], [UID:000159], [UID:00036K], [UID:00036M], or sibling tree/iterator pages unless the supervisor expands the callback. Proof: not edited; listed as excluded by scope.
- [x] Apply no manual `-coverage-report.md`, generated report, project-level generated file, validator/tool state, IDA DB, or executed-report edits. Proof: only six by-* docs and this report were manually modified; validator refreshed generated/project state.
- [x] Run the six scoped validators listed above with `--wait-generated` after accepted implementation edits; record working directory, command ids, timestamps, exit codes, generated-refresh state, warnings, and `ok` counts. Proof: command IDs `000000000353` through `000000000358`, all exit `0`, `ok:1`.
- [x] Verify `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` freshness against validator command metadata and confirm [UID:00036O] and [UID:00036N] no longer have `Empty Emitter Marker` output after the paired support repair. Proof: generated header equals command `000000000358`; UID00036O and UID00036N marker text appears without `Empty Emitter Marker`.
- [x] Confirm score-blocker audit remains closed: no raw vtable arrays, no non-emitting downgrade, no stale-source authority, no false virtual rows after `TREEICON.EPF`, and sibling empty emitters treated as out-of-scope unless separately assigned. Proof: target/support docs preserve these rejected alternatives and exclusions.
- [x] Do not run `execute_report`; leave report execution to the supervisor after verification. Proof: `execute_report` was not run.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: current `goal.md` assignment `B006-implementation-callback-00036O-FolderTreePaneVtableData-20260629`.
- [x] All accepted target/support doc details incorporated at report-level detail or marked already-present/excluded with a concrete reason. Proof: six edited docs listed in `Implementation Callback Proof - 2026-06-29`; excluded sibling pages listed there with reason.
- [x] Claim And Incorporation Ledger verification states updated from `proposed` to `applied`, `already-present`, `excluded-with-reason`, or `blocked`. Proof: C01-C09 `applied`, C10-C11 `already-present`, C12 `excluded-with-reason`; no ledger row remains `proposed`.
- [x] Metadata/score/owner/emitter/C++ changes applied or explicitly not applied with reason. Proof: UID00036O and UID00036N updated to `89/93`, owner/reconstructable/emitter unchanged, exact formal marker blocks inserted; aggregate/class/file/parent metadata intentionally unchanged.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: [UID:00005A]/[UID:0000JG] historical simroot/Wave3 wording preserved as lead material only; [UID:0001XL] historical Wave3-data cross-reference preserved as context; UID00025C legacy `AUTOGEN_PARENT_UID` wording left as historical change-log text; no raw arrays/non-emitting downgrade/false `TREEICON.EPF` virtual rows introduced.
- [x] Validators run and command metadata recorded. Proof: six scoped `--wait-generated` validators recorded above, command IDs `000000000353` through `000000000358`, all exit `0`, `ok:1`.
- [x] Generated refresh completed by validator or explicitly reported as deferred/older than validator command metadata. Proof: each scoped validator reported `generated_refresh: completed`; generated `FolderTreePane.cpp` header is `validator-command-id: 000000000358`, `validator-refreshed-at: 2026-06-29T02:19:04-04:00`.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: none remain unapplied; sibling pages [UID:00034K], [UID:000159], [UID:00036K], [UID:00036M], and sibling tree/iterator pages were excluded by accepted scope unless supervisor expands work.

## Changed Files In This Report-Only Pass / Implementation Callback

Created:

- None during the 2026-06-29 revision; the report already existed.

Modified:

- `tools/leaser/Agents/Agent-B006/research/00036O-FolderTreePaneVtableData-empty-emitter-source-quality.md`
- `by-memory/0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md`
- `by-type/by-vtable/FolderTreePaneClassVtables.md`
- `by-type/by-vtable/FolderTreePaneVtables.md`
- `by-class/FolderTreePane.md`
- `by-file/FolderTreePane.md`
- `by-memory/0x0061a45c-0x0061a5c4.FolderSelectTreeReadOnlyData.md`

No manual edits were made to generated files, project-level files, manual coverage reports, validator/tool state, executed-report archives, or IDA DB files. Validator commands refreshed generated/project state as documented above.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/00036O-FolderTreePaneVtableData-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/00036O-FolderTreePaneVtableData-empty-emitter-source-quality.md","timestamp":"2026-06-29T02:24:46","uid":"00036O"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00036O-FolderTreePaneVtableData-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/00036O-FolderTreePaneVtableData-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00036O"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
