** TARGET-REPORT-UID:0002MW **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0002MW FolderTreeElemCopyConstruct Empty-Emitter Source-Quality Research

## Final Recommendation

- Target: [UID:0002MW] `by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md`.
- Assignment: `B010-repair-report-0002MW-FolderTreeElemCopyConstruct-20260629`.
- Report mode: repaired report-only pass. No target/support by-* docs, generated files, coverage reports, validator/tool state, IDA DB, leases, or execute-report state were edited.
- Recommended disposition: keep the target reconstructable, keep direct owner/emitter [UID:0001UJ] `FolderTreePane::TreeElem`, raise to `COMPLETION:88` / `CONFIDENCE:92`, and replace the blank formal C++ block with the exact marker-only formal block below.
- Source-quality decision: [UID:0002MW] is real compiler-emitted copy-constructor support for the 36-byte `FolderTreePane::TreeElem` record. It should be traceable in generated `FolderTreePane.cpp`, but it should not receive a handwritten standalone helper body.

Exact formal `RECONSTRUCTION_CPP CODE` block content to insert into the target page:

```cpp
// Compiler-emitted FolderTreePane::TreeElem copy-constructor support.
// Reconstructed by [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md)
// through the FolderTreePane::TreeElem field declaration and TreeStorage
// insertion/copy users; no standalone helper body is emitted here.
```

This is the formal block content for [UID:0002MW], not an illustrative snippet. It resolves the empty-emitter condition by documenting that the rebuilt source represents this physical helper through the nested `TreeElem` declaration and its storage/template users.

## Current Target State

- Current target metadata before implementation remains `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:0001UJ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001UJ`, and blank `RECONSTRUCTION_CPP CODE`.
- Current item summary still says the parent remains blank and final C++ remains blank because of older gate/source-quality wording. That is stale: current metadata already has owner/emitter [UID:0001UJ], and the current code-entry gate permits marker-only formal output because the target is reconstructable, emitted, and has average score above 85.
- `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` currently still renders [UID:0002MW] as:

```cpp
// UID:0002MW | by-memory\0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md | Completion:85 | Confidence:90 | Empty Emitter Marker
```

- `auto-generated/-ag-research-tracker.md` currently shows [UID:0002MW] with report count `0`; supervisor execution after implementation should refresh that state. B010 must not edit generated tracker state manually.
- Current support route:
  - [UID:0001UJ] `FolderTreePane::TreeElem` is `86/89`, owned/emitted through [UID:00005A] `FolderTreePane`, and already records the 36-byte field layout plus copied/non-copied padding distinction.
  - [UID:0000FC] `TreeStorage<FolderTreePane::TreeElem>` is `85/86`, owned/emitted through [UID:0000JG] `FolderTreePane.cpp`, and already records storage insertion/destruction support.
  - [UID:0001WP] `FolderTreePaneTreeTemplates` is `87/90`, owned/emitted through [UID:0000JG], and records the concrete `Tree`, `TreeStorage`, and `TreeItor` template support route.
  - [UID:0002MV] `FolderTreeStorageInsertAt` has already been repaired to marker-only formal output through [UID:0000FC].
  - [UID:000157] is a non-emitting aggregate inventory. It already lists [UID:0002MW] as a child but does not yet record the marker-only disposition or the predecessor padding gap `0x004b55d3-0x004b55e0`.
  - [UID:0000JG] and [UID:00005A] already contain current file/class route detail for many sibling FolderTreePane empty-emitter repairs; they still need a [UID:0002MW]-specific sync that the copy helper is no longer blank/unresolved.
  - `by-memory/-ignored.md` currently lists `0x004b564d-0x004b5650` as FolderTreePane helper alignment padding, but it does not list the predecessor gap `0x004b55d3-0x004b55e0`.

## Evidence Checked

### Current MCP Session

MCP was mandatory for this repair and was available after supervisor restoration.

- JSON-RPC `initialize` id `101` succeeded against `http://127.0.0.1:13337/mcp`; server `ida-pro-mcp`, protocol `2025-06-18`.
- `idb_list` id `102` returned active session `992d23de`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `12076`, `is_analyzing:false`, `is_active:true`.
- `server_health` id `103` on session `992d23de` returned `status: ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and `strings_cache_size:2067`.
- A stale pre-restore session `86fb854e` failed before this repair was completed. That failed session is recorded only as incident history; this repaired report relies on restored session `992d23de` calls.

### Current MCP Function, Boundary, Caller, Callee, And Byte Evidence

- `lookup_funcs` id `104`:
  - `0x004b5510` -> `sub_4B5510`, size `0xc3`; this predecessor ends at `0x004b55d3`.
  - `0x004b55d3` and `0x004b55df` -> not functions.
  - `0x004b55e0` -> `sub_4B55E0`, size `0x6d`.
  - `0x004b564d` -> not a function.
  - `0x004b5650` is still modeled inside `sub_4B1B90`, matching the documented constructor/EH cleanup treatment for [UID:000158].
  - Support lookups: `0x004b3d50` -> `sub_4B3D50`, size `0x254`; `0x004b5d20` -> `sub_4B5D20`, size `0xbf`; `0x004b5cc0` -> `sub_4B5CC0`, size `0x25`; `0x004b5b00` -> `sub_4B5B00`, size `0xae`; `0x00582a90` -> `sub_582A90`, size `0x5b`.
- `xrefs_to` id `105` and `find code_ref` id `124` agree that [UID:0002MW] has exactly five code references:
  - `0x004b2271` and `0x004b23ca` from `sub_4B1D50` / lazy expansion.
  - `0x004b3e72` and `0x004b3ea7` from `sub_4B3D50` / `TreeStorage<FolderTreePane::TreeElem>::InsertAt`.
  - `0x004b5b81` from `sub_4B5B00` / `Tree<FolderTreePane::TreeElem>::ResetToSingleRoot`.
- `xrefs_to` id `105` also confirms the support route:
  - `0x004b3d50` has three callers: `0x004b227f`, `0x004b23d8`, and `0x004b5b8f`.
  - `0x004b5d20` has two callers, both from `0x004b3d50`.
  - `0x004b5cc0` has one caller from `0x004b3d50`.
  - `0x004b5b00` has three callers: `0x004b1c18`, `0x004b1c95`, and `0x004b262a`.
- `callees` id `123` confirms [UID:0002MW] has exactly one direct callee: `0x00582a90` / `sub_582A90`, the `SimpleUString` copy/share constructor family used for the `name` field.
- `decompile` id `118` for `0x004b55e0` shows a `__thiscall` helper that returns `this` after copying:
  - dwords at `+0x00`, `+0x04`, `+0x08`, `+0x0c`, and `+0x10`;
  - `SimpleUString` copy at destination `this+0x14` from source `a2+0x14` through `sub_582A90`;
  - words at `+0x18` and `+0x1a`;
  - bytes at `+0x1c`, `+0x1d`, and `+0x20`.
- `disasm` id `119` confirms the same field order in 42 instructions. The helper uses `ecx` as destination `this`, stack argument `arg_0` as the source pointer, calls `sub_582A90` at `0x004b5615`, moves byte `+0x20` at `0x004b563b-0x004b5641`, returns destination `this`, and ends with `retn 4` at `0x004b564a`.
- `get_bytes` id `120` proves padding around the target:
  - `0x004b55d3-0x004b55e0`: thirteen `0xcc` bytes.
  - `0x004b564d-0x004b5650`: three `0xcc` bytes.
- `decompile` id `121` for `0x004b5d20` confirms range-copy support repeats the same copied field set in 36-byte strides: five leading dwords, `sub_582A90` for `+0x14`, words `+0x18/+0x1a`, bytes `+0x1c/+0x1d`, and byte `+0x20`.
- `decompile` id `122` for `0x004b3d50` confirms `InsertAt` calls `sub_4B55E0`, calls `sub_4B5D20`, destroys old names through `sub_582B70`, and releases old storage through `sub_5C7526` / invalid-parameter support. The body uses 36-byte element math and capacity limit `0x71c71c7`.
- `decompile` id `113` for `0x004b5b00` confirms reset destroys old names, default-constructs a local root name through `sub_582B20`, loads four `-1` dwords from `xmmword_619660`, stores a fifth `-1`, clears the loaded/expanded bytes, then either calls `sub_4B3D50` on full capacity or `sub_4B55E0` followed by `m_end += 36` on available capacity.
- `search_structs` id `114` for `TreeElem` returned no IDA structure.
- `type_query` id `115` for UDT filters `*TreeElem*`, `*FolderTreePane*`, and `*TreeStorage*` returned zero results. Source-facing names remain documentation inference, not recovered PDB/UDT symbols.
- `int_convert` id `116` verified key numeric conversions: `0x6d` = 109, `0x24` = 36, `0x14` = 20, `0x18` = 24, `0x1a` = 26, `0x1c` = 28, `0x1d` = 29, `0x20` = 32, `0x004b564d` = 4937293, and `0x004b55d3` = 4937171.

### Current Documentation And Generated Leads Checked

- Target page [UID:0002MW] `by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md`.
- [UID:0001UJ] `by-type/by-struct/FolderTreePane__TreeElem.md`.
- [UID:0000FC] `by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md`.
- [UID:0001WP] `by-type/by-template/FolderTreePaneTreeTemplates.md`.
- [UID:0002MV] `by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md`.
- [UID:000157] `by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md`.
- [UID:0000JG] `by-file/FolderTreePane.md`.
- [UID:00005A] `by-class/FolderTreePane.md`.
- [UID:0000VN] `by-memory/-ignored.md`.
- Read-only generated leads: `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` and `auto-generated/-ag-research-tracker.md`.
- Adjacent support precedent checked from current docs and executed reports: [UID:000447] `FolderTreeElemRangeDestroy`, [UID:000449] `FolderTreeElemRangeCopyConstruct`, and [UID:00044B] `FolderTreeElemVectorStorageFree`.

### Existing / Archived Reports Searched

Search terms used before finalizing: `0002MW`, `0x004b55e0`, `FolderTreeElemCopyConstruct`, `FolderTreePane__TreeElem`, and `TreeElemCopy`.

Relevant matches opened or used as leads:

- B001 `executed-b-agent-research/B001/000157-FolderTreePaneTreeAndSortHelpers.md`: useful split inventory lead; it marked [UID:0002MW] "already valid" but predates this empty-emitter repair.
- B009 `executed-b-agent-research/B009/00022E-FolderTreePaneVectorSupportHelpers-source-quality.md`: establishes nearby marker-only pattern for compiler-emitted 36-byte `TreeElem` range support.
- B008 `executed-b-agent-research/B008/00005A-FolderTreePane-class-source-quality.md`: establishes `FolderTreePane.cpp`, local `Tree` / `TreeStorage` / `TreeItor` template support, and accepted `TreeElem` field names.
- B014 `executed-b-agent-research/B014/0000FB-FolderTreePaneTreeIterator-class-source-quality.md`: confirms `TreeItor<FolderTreePane::TreeElem>` spelling and traversal use of `parentIndex`, `firstChildIndex`, `nextSiblingIndex`, and the `+0x20` visible-skip byte.
- B009 `executed-b-agent-research/B009/0002MY-FolderTreeResetToSingleRoot-empty-emitter-source-quality.md`: confirms reset uses ordinary copy construction through `0x004b55e0` in the available-capacity path and `InsertAt` in the full-capacity path.
- Current transitional triage notes identify this loose report as active repair; they are administrative context only.

Historical generated/recovered source checked as stale leads only:

- `source-2/core/wave2/recovered/TreeStorage_struct_FolderTreePane__TreeElem__004B3D50_InsertAt.cpp`.
- `source-2/core/wave2/recovered/Tree_struct_FolderTreePane__TreeElem__004B5B00_ResetToSingleRoot.cpp`.

These old recovered files use generated overlays such as `TreeStorageFolderTreeElemRecord` and `field_XX`; one old overlay modeled `field_1C` as a 16-bit field plus a later byte. Current by-* docs plus restored MCP evidence are stronger: the live helper copies bytes at `+0x1c`, `+0x1d`, and `+0x20`, and does not copy `+0x1e/+0x1f` or `+0x21-+0x23`.

## Positive Evidence

- Exact half-open target range is confirmed: `0x004b55e0-0x004b564d`, size `0x6d` / 109 bytes.
- The predecessor function ends at `0x004b55d3`, and current bytes prove `0x004b55d3-0x004b55e0` is alignment padding. The successor gap `0x004b564d-0x004b5650` is also alignment padding and is already listed in `by-memory/-ignored.md`.
- The helper has five live callers, all in the `FolderTreePane` tree/template route:
  - two lazy-expansion copy sites in `sub_4B1D50`;
  - two storage insertion/relocation copy sites in `sub_4B3D50`;
  - one reset fast-path copy site in `sub_4B5B00`.
- The helper has one direct callee, `sub_582A90`, matching `SimpleUString` copy/share construction for the `name` field.
- The copied field set matches the current 36-byte `FolderTreePane::TreeElem` layout:

| Offset | Copied by [UID:0002MW] | Current source-facing role |
| --- | --- | --- |
| `+0x00` | dword | `parentIndex` |
| `+0x04` | dword | `firstChildIndex` |
| `+0x08` | dword | `lastChildIndex` |
| `+0x0c` | dword | inferred `previousSiblingIndex` |
| `+0x10` | dword | `nextSiblingIndex` |
| `+0x14` | `SimpleUString` copy call | `name` |
| `+0x18` | word | `rowIndex` |
| `+0x1a` | word | `depth` |
| `+0x1c` | byte | `childrenLoaded` |
| `+0x1d` | byte | `expanded` |
| `+0x1e-+0x1f` | not copied | padding/reserved layout bytes |
| `+0x20` | byte | `isHidden` / visible-traversal skip byte |
| `+0x21-+0x23` | not copied | tail padding/reserved layout bytes |

- The range-copy helper [UID:000449] copies the same field set in `0x24` / 36-byte strides, proving [UID:0002MW] is not an isolated accidental helper.
- `InsertAt` uses [UID:0002MW] for single-record copy construction and [UID:000449] for prefix/suffix relocation. Reset-to-root uses [UID:0002MW] for the available-capacity append and [UID:0002MV] for the full-capacity slow path.
- Current support docs already establish the direct owner route: [UID:0001UJ] owns the `FolderTreePane::TreeElem` declaration/layout, [UID:0000FC] owns storage helper context, [UID:0001WP] owns the local template context, and [UID:0000JG]/[UID:00005A] own the file/class route.

## Negative Evidence

- No original IDA UDT, PDB structure, or recovered type declaration for `FolderTreePane::TreeElem`, `FolderTreePane`, or `TreeStorage` was found in the restored session. Field/type names remain source-quality inference backed by behavior and current docs, not original symbol recovery.
- [UID:0002MW] does not copy bytes `+0x1e/+0x1f` or `+0x21-+0x23`. Treating those bytes as ordinary copied source members is contradicted by current decompilation/disassembly. They should remain padding/reserved layout notation unless a later source-level declaration pass proves otherwise.
- Consumer/caller evidence does not make `TreeStorage<FolderTreePane::TreeElem>` the canonical owner. Storage calls the copy constructor, but the copied object identity is the nested `TreeElem` record.
- The broad aggregate [UID:000157] is not the direct owner: it is a non-emitting inventory over mixed exact children, compiler cleanup, padding, and source-bearing child pages.
- The outer file [UID:0000JG] and class [UID:00005A] are valid source route context, but [UID:0001UJ] is the narrower direct semantic owner.
- Leaving the formal block blank is no longer a valid final disposition because the target is reconstructable, emitted through a valid route, above the current code-entry average score gate, and currently appears as an `Empty Emitter Marker`.
- A full decompiler-shaped helper body using raw offsets or `sub_582A90` would preserve compiler lowering as if it were handwritten source and would introduce raw IDA names into final output.
- A full high-level copy constructor body remains weaker than the marker-only route for this exact target because the likely original source was the nested record declaration and template/storage copy expressions; the physical helper is compiler-emitted support.

## Heuristic / Inference Reanalysis And Validation

### Ownership Ranking

1. [UID:0001UJ] `FolderTreePane::TreeElem` - accepted direct owner. The helper copy-constructs one nested `TreeElem` record and copies exactly the current field layout. Both child and direct owner clear the gate.
2. [UID:0000FC] `TreeStorage<FolderTreePane::TreeElem>` - rejected as direct owner, accepted as support/caller route. It uses the helper during insertion and relocation but does not own the copied-record identity.
3. [UID:0001WP] `FolderTreePaneTreeTemplates` - rejected as direct owner, accepted as template context. It describes the concrete `Tree`, `TreeStorage`, and `TreeItor` family.
4. [UID:00005A] / [UID:0000JG] `FolderTreePane` class/file - rejected as direct owner for this exact child, accepted as final source route context.
5. [UID:000157] aggregate - rejected as owner/emitter. It is a non-emitting inventory.
6. `CANONICAL_OWNER:NONE` or `RECONSTRUCTABLE:FALSE` - rejected. Current xrefs, field-copy behavior, `SimpleUString` lifetime, and support docs prove project-local source-derived behavior.

### Source-Quality Decision

The best original-like source representation is not a standalone function body. The body is an MSVC-lowered copy-constructor helper for a record with a non-trivial `SimpleUString` member. In source, this is better represented by:

- the `FolderTreePane::TreeElem` declaration/layout;
- storage insertion and reset expressions that copy-construct `TreeElem` objects;
- marker-only traceability on this exact by-memory page.

The marker-only formal block matches the accepted nearby pattern for compiler-emitted `TreeStorage<FolderTreePane::TreeElem>` support pages, especially [UID:0002MV] `InsertAt`, [UID:000447] range destroy, [UID:000449] range copy, and [UID:00044B] storage free. It resolves the empty-emitter row without pretending the binary helper was a handwritten source function.

### Split / Range / Padding

No target split is required. [UID:0002MW] is one exact modeled function, `0x004b55e0-0x004b564d`. The current same-pass padding repair is implementation-ready:

- Add `0x004b55d3-0x004b55e0` to the FolderTreePane helper padding ledger.
- Keep `0x004b564d-0x004b5650` as already present in `by-memory/-ignored.md`.
- Add a corresponding row/note to [UID:000157] so the aggregate inventory records the predecessor gap between [UID:00034E] and [UID:0002MW].

## Score And Metadata Disposition

Recommended target metadata:

| Field | Recommended value | Rationale |
| --- | --- | --- |
| `COMPLETION` | `88` | Exact range, predecessor/successor padding, five callers, sole callee, copied field offsets, range-copy/insert/reset support route, owner/emitter rationale, rejected alternatives, and marker-only formal disposition are now current and implementation-ready. Score remains below final audit because exact original field spellings/header factoring are inferred. |
| `CONFIDENCE` | `92` | Restored MCP session `992d23de` confirms boundary, xrefs, callee, decompile/disassembly, support helper relationships, no UDTs, and padding. Confidence remains below final audit because no original UDT/PDB names survive. |
| `CANONICAL_OWNER` | `0001UJ` | Direct semantic owner is the nested `FolderTreePane::TreeElem` record being copy-constructed. |
| `RECONSTRUCTABLE` | `TRUE` | Project-local source-derived copy support required by FolderTreePane tree storage and reset paths. |
| `EMITTER_UIDS` | `0001UJ` | Output should route through the nested record/type support path into FolderTreePane generated output. |
| `EMITTER_POSITION_OPTIONAL` | blank | No special ordering needed. |
| `RECONSTRUCTION_CPP CODE` | marker-only formal comment block above | Nonblank formal block removes empty-emitter status while preserving source-quality no-standalone-body disposition. |

## First-Draft C++ / Formal Marker Disposition

[UID:0002MW] qualifies for formal `RECONSTRUCTION_CPP CODE` because it is reconstructable, has nonblank `EMITTER_UIDS`, reaches the generated source route, and `(88 + 92) / 2 = 90`, above the current code-entry threshold.

The correct output is a formal marker-only comment block, not a function body:

```cpp
// Compiler-emitted FolderTreePane::TreeElem copy-constructor support.
// Reconstructed by [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md)
// through the FolderTreePane::TreeElem field declaration and TreeStorage
// insertion/copy users; no standalone helper body is emitted here.
```

Rejected C++ alternatives:

- Blank formal block plus prose-only no-code proof: rejected because it preserves the generated empty-emitter problem.
- Raw helper body calling `sub_582A90`: rejected as decompiler/IDA-shaped and not original-like source.
- Full high-level `FolderTreePane::TreeElem::TreeElem(const TreeElem &)` body: rejected for this exact by-memory page because it would imply an out-of-line handwritten helper before the final `TreeElem` declaration/header factoring is proven. The source-level cause is covered by the record declaration and copy-use expressions.
- Emitting [UID:0002MW] through `TreeStorage` or the aggregate page: rejected by ownership analysis.

## Recommended Target And Support Doc Changes

### Target [UID:0002MW]

`by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md`

- Set metadata to `COMPLETION:88`, `CONFIDENCE:92`, keep `CANONICAL_OWNER:0001UJ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001UJ`, and blank `EMITTER_POSITION_OPTIONAL`.
- Insert the exact formal marker-only `RECONSTRUCTION_CPP CODE` block from this report.
- Replace stale "parent remains blank" / "final C++ remains blank" language with marker-only source-routed copy-constructor support.
- Add current restored MCP evidence from ids `101-124`, especially session `992d23de`, function boundary, xrefs, callee, copied offsets, padding, support decompiles, and negative UDT results.
- Preserve the copied field table and the key clarification that `+0x1e/+0x1f` and `+0x21-+0x23` are not copied by the helper.
- Preserve rejected alternatives and the no-standalone-body proof.

### Support Docs To Edit If Accepted

- [UID:0001UJ] `by-type/by-struct/FolderTreePane__TreeElem.md`: add a B010 [UID:0002MW] sync noting the marker-only copy-constructor support result; preserve copied-field list and clarify again that reserved bytes are layout notation, not proven copied source members.
- [UID:0000FC] `by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md`: add [UID:0002MW] as the single-record copy-construction support used by `InsertAt`, distinct from [UID:000449] range copy.
- [UID:0001WP] `by-type/by-template/FolderTreePaneTreeTemplates.md`: update the exact-memory row and evidence notes for [UID:0002MW] from generic IDA-confirmed helper to marker-only source-routed copy-constructor support through [UID:0001UJ].
- [UID:0002MV] `by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md`: update references to `0x004b55e0` so the page points to [UID:0002MW]'s accepted marker-only copy-constructor disposition and does not imply the helper remains blank/unresolved.
- [UID:000157] `by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md`: update the child row for [UID:0002MW] to marker-only source-routed copy-constructor support; add `0x004b55d3-0x004b55e0` as confirmed `0xcc` padding between [UID:00034E] and [UID:0002MW].
- [UID:0000JG] `by-file/FolderTreePane.md`: add file-level support that [UID:0002MW] is no longer an unresolved empty emitter and is marker-only copy-constructor support through [UID:0001UJ].
- [UID:00005A] `by-class/FolderTreePane.md`: add class-level support that `FolderTreePane::TreeElem` copy construction is now covered by the [UID:0002MW] marker, not by a standalone method body.
- [UID:0000VN] `by-memory/-ignored.md`: add `0x004b55d3-0x004b55e0` to the existing FolderTreePane tree/vector helper padding ledger; keep `0x004b564d-0x004b5650` as already present.

### Explicit No-Edit Support Decisions

- [UID:000447] `FolderTreeElemRangeDestroy`: no edit required for this report; it is already a consistent adjacent marker-only/range-support precedent.
- [UID:000449] `FolderTreeElemRangeCopyConstruct`: no edit required unless the supervisor wants a reciprocal note; it already documents the same copied-field set and marker-only range-copy support.
- [UID:00044B] `FolderTreeElemVectorStorageFree`: no edit required for this report; it is storage-free support, not single-record copy construction.
- Generated files, generated reports, manual `-coverage-report.md` files, validator state, tool state, IDA DB, and executed-report archives: no manual edit. Refresh only through validator after implementation.

## Expected Generated Result After Implementation

After the implementation callback applies the target/support updates and runs scoped validators with generated refresh, `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` should no longer contain the [UID:0002MW] `Empty Emitter Marker` row. It should contain the accepted marker-only formal comment with updated score `88/92`.

The generated research tracker should show report coverage only after the supervisor verifies implementation and runs the validator `execute_report` lifecycle command. B010 should not run `execute_report` in this report-repair pass.

## Open Question Closure

- Exact original `TreeElem` field spellings remain unrecovered, but this is not a blocker for the marker-only disposition. Current docs already use the best source-facing field names, and the marker avoids writing a body that depends on exact final spelling.
- Exact shared tree-template header factoring remains unresolved, but it is not a blocker for [UID:0002MW]. The current accepted route keeps concrete FolderTreePane tree/template support under `FolderTreePane.cpp`, while preserving future shared-header consolidation as a separate project question.
- Padding/reserved bytes are resolved for this target: the helper does not copy `+0x1e/+0x1f` or `+0x21-+0x23`, so they must not be treated as ordinary copied source members in this implementation.
- No same-pass blocker remains. The target has a current MCP-backed owner/emitter/source-quality disposition, exact formal marker text, support-doc edit plan, padding-ledger repair item, and validator/generation expectations.

## Claim And Incorporation Ledger

| Claim | Action | Intended destination / exclusion reason | Verification state |
| --- | --- | --- | --- |
| [UID:0002MW] exact range is `0x004b55e0-0x004b564d`, function `sub_4B55E0`, size `0x6d` / 109 bytes. | incorporate | Applied to target `Covered Range` / `IDA Evidence` and [UID:000157] child row; validator `000000000363` and `000000000368` passed with `ok: 1`. | applied |
| Restored MCP session `992d23de` with health ok is the current evidence source; stale failed session `86fb854e` is not used as proof. | incorporate | Applied to target `IDA Evidence` and support sync notes; target explicitly treats `86fb854e` as incident history only. Validator `000000000363` passed with `ok: 1`. | applied |
| Predecessor `0x004b5510` ends at `0x004b55d3`; `0x004b55d3-0x004b55e0` is thirteen `0xcc` bytes. | incorporate | Applied to target boundary evidence, [UID:000157] child table, and `by-memory/-ignored.md` padding ledger; validators `000000000363`, `000000000368`, and `000000000374` passed with `ok: 1`. | applied |
| Successor `0x004b564d-0x004b5650` is three `0xcc` bytes and already appears in `by-memory/-ignored.md`. | already-present | Target now mentions successor padding; ignored ledger already had the range and now includes B010 proof while preserving the existing row. Validators `000000000363` and `000000000374` passed with `ok: 1`. | already-present |
| [UID:0002MW] has five code refs: `0x004b2271`, `0x004b23ca`, `0x004b3e72`, `0x004b3ea7`, and `0x004b5b81`. | incorporate | Applied to target `IDA Evidence` and support notes in [UID:0000FC], [UID:0001WP], [UID:0002MV], [UID:0000JG], and [UID:00005A]; validators `000000000363` through `000000000372` for those docs passed. | applied |
| [UID:0002MW] has one direct callee, `0x00582a90` / `sub_582A90`, for the embedded `name` field copy. | incorporate | Applied to target `IDA Evidence`, [UID:0001UJ] support note, and file/class route notes; validators `000000000363`, `000000000364`, `000000000370`, and `000000000372` passed. | applied |
| Copied fields are dwords `+0x00..+0x10`, `SimpleUString` at `+0x14`, words `+0x18/+0x1a`, and bytes `+0x1c/+0x1d/+0x20`. | incorporate | Applied to target reconstruction/IDA notes and support docs [UID:0001UJ], [UID:0000FC], [UID:0001WP], [UID:0002MV], [UID:000157], [UID:0000JG], and [UID:00005A]; all scoped validators passed. | applied |
| Bytes `+0x1e/+0x1f` and `+0x21-+0x23` are not copied by this helper. | incorporate | Applied to target rejected/negative evidence plus [UID:0001UJ], [UID:0000FC], [UID:0001WP], [UID:0002MV], [UID:000157], [UID:0000JG], and [UID:00005A] support notes. | applied |
| Direct owner remains [UID:0001UJ] `FolderTreePane::TreeElem`. | incorporate | Applied to target metadata/ownership rationale and support route notes; validator `000000000363` preserved `CANONICAL_OWNER:0001UJ`, `EMITTER_UIDS:0001UJ`, and generated UID0002MW marker in `FolderTreePane.cpp`. | applied |
| `TreeStorage` is a caller/support route, not the direct owner of the single-record copy constructor. | incorporate | Applied to target rejected alternatives and [UID:0000FC] / [UID:0002MV] support notes; validators `000000000365` and `000000000367` passed. | applied |
| [UID:000157] aggregate and [UID:0000JG]/[UID:00005A] file/class are context, not the narrow direct owner. | incorporate | Applied to target rejected alternatives and support notes in [UID:000157], [UID:0000JG], and [UID:00005A]; validators `000000000368`, `000000000370`, and `000000000372` passed. | applied |
| Recommended score/metadata is `88/92`, owner/emitter [UID:0001UJ], reconstructable true, blank emitter position. | incorporate | Applied to target header and score rationale; validator `000000000363` reported `completion_update 88`, `confidence_update 92`, `canonical_owner_update 0001UJ`, and exit `0`. | applied |
| Formal C++ must be marker-only with the exact block in this report. | incorporate | Applied verbatim to the target formal `RECONSTRUCTION_CPP CODE` block; generated `FolderTreePane.cpp` current header `validator-command-id: 000000000384` / `validator-refreshed-at: 2026-06-29T02:58:57-04:00` contains the marker at UID0002MW and no UID0002MW empty marker. | applied |
| Full raw/decompiler helper body and full high-level copy-constructor body are rejected for this target. | incorporate | Applied to target `Reconstruction Notes` and support source-quality notes on struct, storage, template, file, and class docs; validators `000000000363`-`000000000372` passed. | applied |
| Old Wave2/source-2 recovered overlays are stale generated leads, not authority. | historicalize | Applied where current target text needed it: target rejected alternatives now historicalize old Wave2/source-2 overlays as stale generated leads; no conflicting support wording was found in this callback. | applied |
| [UID:000447], [UID:000449], and [UID:00044B] need no direct edits for this report unless supervisor expands scope. | not-applicable | Checked only with `rg`; existing pages already use consistent marker-only/range/storage support wording. No edits made. | excluded-with-reason |
| Generated C++ and research tracker must refresh through validator/supervisor execution, not manual edits. | not-applicable | No generated/manual coverage/tool/IDA/executed files were manually edited. Validators refreshed generated output; `execute_report` was not run. | excluded-with-reason |

## Implementation Tracking Checklist

Implementation callback status: all accepted items below are checked as applied, already present, or excluded with proof.

### Target [UID:0002MW]

- [x] Updated `by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md` metadata to `COMPLETION:88`, `CONFIDENCE:92`, kept `CANONICAL_OWNER:0001UJ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001UJ`, and blank `EMITTER_POSITION_OPTIONAL`. Proof: validator `000000000363`, timestamp `2026-06-29T02:55:07-04:00`, exit `0`, `ok: 1`.
- [x] Inserted the exact formal marker-only `RECONSTRUCTION_CPP CODE` block into the target multiline block. Proof: generated `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` current header `validator-command-id: 000000000384` / `validator-refreshed-at: 2026-06-29T02:58:57-04:00` contains the marker under `UID:0002MW`.
- [x] Updated the target item summary, status, reconstruction notes, IDA evidence, score rationale, and changes sections so the target is marker-only source-routed compiler-emitted `FolderTreePane::TreeElem` copy-constructor support. Proof: validator `000000000363`, exit `0`, `ok: 1`.
- [x] Preserved current MCP evidence from restored session `992d23de`: initialize/idb/session/health proof, lookup id `104`, xref id `105`, `find code_ref` id `124`, callee id `123`, decompile/disasm ids `118`/`119`, byte id `120`, support decompile ids `121`/`122`/`113`, type-negative ids `114`/`115`, and int conversion id `116`. Proof: target `IDA Evidence` updated and validator `000000000363` passed.
- [x] Preserved copied-field and negative padding/reserved evidence for `+0x1e/+0x1f` and `+0x21-+0x23`. Proof: target plus support docs validated by `000000000363`-`000000000372`.
- [x] Added rejected alternatives: blank formal block, raw helper body, full high-level out-of-line copy constructor body, `TreeStorage` direct owner, aggregate/file/class direct owner, non-reconstructable/no-emitter disposition, and treating padding as copied source fields. Proof: target validator `000000000363` passed.
- [x] Historicalized stale Wave2/source-2 recovered overlay claims encountered in target scope as generated-lead material only. Proof: target reconstruction notes updated; no active support contradiction found by stale-text scan.

### Support Docs To Update

- [x] Updated [UID:0001UJ] `by-type/by-struct/FolderTreePane__TreeElem.md` with the [UID:0002MW] marker-only result, copied-field list, and padding/reserved clarification. Proof: validator `000000000364`, timestamp `2026-06-29T02:55:35-04:00`, exit `0`, `ok: 1`.
- [x] Updated [UID:0000FC] `by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md` with [UID:0002MW] as single-record copy-construction support used by `InsertAt`, distinct from [UID:000449] range-copy support. Proof: validator `000000000365`, timestamp `2026-06-29T02:55:45-04:00`, exit `0`, `ok: 1`.
- [x] Updated [UID:0001WP] `by-type/by-template/FolderTreePaneTreeTemplates.md` exact-memory row and evidence notes so [UID:0002MW] is marker-only source-routed support through [UID:0001UJ]. Proof: validator `000000000366`, timestamp `2026-06-29T02:55:56-04:00`, exit `0`, `ok: 1`.
- [x] Updated [UID:0002MV] `by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md` so its `0x004b55e0` references point to [UID:0002MW]'s accepted marker-only disposition. Proof: validator `000000000367`, timestamp `2026-06-29T02:56:06-04:00`, exit `0`, `ok: 1`.
- [x] Updated [UID:000157] `by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md` to record [UID:0002MW]'s marker-only disposition and the missing predecessor padding gap `0x004b55d3-0x004b55e0`. Proof: validator `000000000368`, timestamp `2026-06-29T02:56:15-04:00`, exit `0`, `ok: 1`.
- [x] Updated [UID:0000JG] `by-file/FolderTreePane.md` so [UID:0002MW] is marker-only `TreeElem` copy-constructor support through [UID:0001UJ], not unresolved blank-C++ support. Proof: validator `000000000370`, timestamp `2026-06-29T02:56:25-04:00`, exit `0`, `ok: 1`.
- [x] Updated [UID:00005A] `by-class/FolderTreePane.md` with the class-level support note that `FolderTreePane::TreeElem` copy construction is covered by the [UID:0002MW] marker rather than by a standalone source body. Proof: validator `000000000372`, timestamp `2026-06-29T02:56:36-04:00`, exit `0`, `ok: 1`.
- [x] Updated [UID:0000VN] `by-memory/-ignored.md` to include `0x004b55d3-0x004b55e0` as `0xcc` alignment padding around the FolderTreePane helper cluster. Confirmed `0x004b564d-0x004b5650` remains covered. Proof: validator `000000000374`, timestamp `2026-06-29T02:56:45-04:00`, exit `0`, `ok: 1`.

### Explicit No-Edit / Already-Present Checks

- [x] Confirmed no edit is required for [UID:000447] `FolderTreeElemRangeDestroy`; existing marker-only/range-destroy support remains consistent. Proof: targeted `rg` checked the page before validation; no contradiction found.
- [x] Confirmed no edit is required for [UID:000449] `FolderTreeElemRangeCopyConstruct`; existing field-copy and marker-only range-copy support already matches [UID:0002MW]. Proof: targeted `rg` found copied-field/marker-only wording already present.
- [x] Confirmed no edit is required for [UID:00044B] `FolderTreeElemVectorStorageFree`; it remains storage-free support, not single-record copy construction. Proof: targeted `rg` found storage-free marker-only wording and no conflict.
- [x] Did not manually edit `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp`, `auto-generated/-ag-research-tracker.md`, project-level generated reports, manual `-coverage-report.md` files, validator/tool state, IDA DB, or executed research archives. Validators updated generated output as expected.
- [x] Did not run `execute_report`; supervisor owns execution after implementation verification.

### Validators And Generated Freshness Expected After Implementation

- [x] Ran `python .\tools\validator.py --mode file --file by-memory\0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md --apply --queue-timeout 240 --wait-generated`. Proof: command id `000000000363`, timestamp `2026-06-29T02:55:07-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- [x] Ran scoped validators with `--wait-generated` for each edited support doc:
  - `by-type\by-struct\FolderTreePane__TreeElem.md`: command `000000000364`, timestamp `2026-06-29T02:55:35-04:00`, exit `0`, `ok: 1`.
  - `by-class\TreeStorage_struct_FolderTreePane__TreeElem_.md`: command `000000000365`, timestamp `2026-06-29T02:55:45-04:00`, exit `0`, `ok: 1`.
  - `by-type\by-template\FolderTreePaneTreeTemplates.md`: command `000000000366`, timestamp `2026-06-29T02:55:56-04:00`, exit `0`, `ok: 1`.
  - `by-memory\0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md`: command `000000000367`, timestamp `2026-06-29T02:56:06-04:00`, exit `0`, `ok: 1`.
  - `by-memory\0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md`: command `000000000368`, timestamp `2026-06-29T02:56:15-04:00`, exit `0`, `ok: 1`.
  - `by-file\FolderTreePane.md`: command `000000000370`, timestamp `2026-06-29T02:56:25-04:00`, exit `0`, `ok: 1`.
  - `by-class\FolderTreePane.md`: command `000000000372`, timestamp `2026-06-29T02:56:36-04:00`, exit `0`, `ok: 1`.
  - `by-memory\-ignored.md`: command `000000000374`, timestamp `2026-06-29T02:56:45-04:00`, exit `0`, `ok: 1`.
- [x] Read-only checked `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` after generated refresh. It has current `validator-command-id: 000000000384`, `validator-refreshed-at: 2026-06-29T02:58:57-04:00`, UID0002MW at `Completion:88 | Confidence:92`, and the accepted marker text. `rg "UID:0002MW.*Empty Emitter Marker"` returned no match.
- [x] Generated refresh was not deferred; every validator reported `generated_refresh: completed` with matching generated refresh command/timestamp.
- [x] Updated this report checklist and Claim And Incorporation Ledger verification states after each accepted claim was incorporated, already present, or explicitly excluded with a concrete reason.
- [x] Implementation leases were taken for the nine by-* files immediately before edits/validators; release is recorded in the implementation response after `leaser.py B010 unlease`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0002MW-FolderTreeElemCopyConstruct-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0002MW-FolderTreeElemCopyConstruct-empty-emitter-source-quality.md","timestamp":"2026-06-29T03:05:09","uid":"0002MW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
