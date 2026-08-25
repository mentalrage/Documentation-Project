** TARGET-REPORT-UID:00022E **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 00022E FolderTreePaneVectorSupportHelpers Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: reclassify [UID:00022E] `by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md` from a reconstructable emitting aggregate into a reviewed non-emitting split/index page, then create exact child pages for the seven modeled helper bodies.
- Reason: the current target is not one source-level function, type, declaration, method, or coherent source emitter. It spans seven separate helper functions plus alignment padding, and those helpers fall into different source-quality buckets: `FolderTreePane` directory-entry name-normalization support, `TreeStorage<FolderTreePane::TreeElem>` 36-byte relocation/destruction/free support, one FolderTree-local 12-byte entry copy-range helper, and two shared 12-byte string-leading record destroy/free helpers reused by both FolderTreePane and SpelledPane.
- Target metadata after accepted implementation should become:
  - `COMPLETION:90`
  - `CONFIDENCE:91`
  - `CANONICAL_OWNER:NONE`
  - `RECONSTRUCTABLE:FALSE`
  - `EMITTER_UIDS:` blank
  - formal `RECONSTRUCTION_CPP CODE` blank
- Exact no-code proof for the parent target: emitting C++ from the aggregate would conflate different generated/support functions and two source contexts. Correct reconstruction belongs in exact child pages and in the owning high-level source expressions: `FolderTreePane` tree storage, `FolderTreePane` local `DirectoryEntry` sorting/vector code, and SpelledPane entry-vector code where shared helpers are reused.
- The current generated research tracker row is stale: it still shows this target as `78/86`, while the target header is already `86/88`. The stale tracker row should be fixed by validator/executed-report lifecycle refresh after supervisor acceptance/implementation, not by manual generated-file edits.

## Target

- Target UID: `00022E`.
- Target path: `by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md`.
- Assignment id: `B009-report-00022E-folder-tree-pane-vector-support-helpers-source-quality-20260626`.
- Current header metadata: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000JG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JG`, formal C++ blank.
- Current item summary: "FolderTreePane-owned container/string support helpers for 36-byte tree nodes and 12-byte directory-entry records; exact helper boundaries, padding, xrefs, and shared 12-byte-vector reuse are documented."
- Current target problem: the page is treated as one reconstructable/emitting item even though its own evidence already proves mixed direct ownership/source shape. This is why the page remains low-value for generated coverage: it is covered as evidence, but it is not source-shaped.

## Evidence Checked

- Current target and support docs:
  - [UID:00022E] `by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md`.
  - [UID:000157] `by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md`.
  - [UID:0000JG] `by-file/FolderTreePane.md`.
  - [UID:00005A] `by-class/FolderTreePane.md`.
  - [UID:0001UJ] `by-type/by-struct/FolderTreePane__TreeElem.md`.
  - [UID:0001WP] `by-type/by-template/FolderTreePaneTreeTemplates.md`.
  - [UID:0000DK] `by-class/SpelledPane.md`.
  - [UID:000343] `by-memory/0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md`.
  - [UID:000348] `by-memory/0x004b3fb0-0x004b4232.FolderTreeDirectoryEntryVectorInsertAt.md`.
  - [UID:00039O] `by-memory/0x00572fd0-0x00573232.SpelledPaneEntryVectorInsert.md`.
  - [UID:0001J1] `by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md` as the current aggregate/non-emitting-container pattern for broad helper ranges.
- Executed B-agent reports:
  - B008 `00005A-FolderTreePane-class-source-quality.md`.
  - B008 `00034B-FolderTreeDirectoryEntrySortCore-source-quality.md`.
  - B009 `00034C-FolderTreeDirectoryEntrySortPartition-source-quality.md`.
  - B001 `00034G-SharedSimpleStringEntryVectorDestructor.md`.
- Generated tracker context:
  - `auto-generated/-ag-research-tracker.md` currently lists [UID:00022E] with stale `78/86` queue data.
- IDA MCP:
  - Endpoint `http://127.0.0.1:13337/mcp`.
  - Active session `80de0a67`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`.
  - `server_health` returned `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`.
  - Tools used: `idb_list`, `server_health`, `tools/list`, `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, `disasm`, and `get_bytes`.
- Numeric conversions:
  - `tools/int_convert.py` verified `0x24` / 36, `0x0c` / 12, `0x7c` / 124, `0x25` / 37, `0xbf` / 191, `0x95` / 149, `0x3c` / 60, `0x1000` / 4096, `0x1f` / 31, `0x71c71c7` / 119304647, and `0x15555555` / 357913941.

## Live IDA Function And Padding Inventory

IDA MCP `lookup_funcs` on session `80de0a67` confirms the target contains seven modeled helper bodies:

| Range | IDA name | Size | Current source-quality role |
| --- | --- | ---: | --- |
| `0x004b5c40-0x004b5cbc` | `sub_4B5C40` | `0x7c` / 124 bytes (Verified with int_convert.py) | Copy/normalize one `SimpleUString`-style directory-entry name for comparison. |
| `0x004b5cc0-0x004b5ce5` | `sub_4B5CC0` | `0x25` / 37 bytes (Verified with int_convert.py) | Destroy a range of 36-byte `TreeElem` records by releasing `name` at `+0x14`. |
| `0x004b5cf0-0x004b5d14` | `sub_4B5CF0` | `0x24` / 36 bytes (Verified with int_convert.py) | Destroy a range of 12-byte string-leading records by releasing the leading string. |
| `0x004b5d20-0x004b5ddf` | `sub_4B5D20` | `0xbf` / 191 bytes (Verified with int_convert.py) | Copy-construct a range of 36-byte `TreeElem` records. |
| `0x004b5de0-0x004b5e75` | `sub_4B5DE0` | `0x95` / 149 bytes (Verified with int_convert.py) | Copy-construct a range of FolderTreePane 12-byte `DirectoryEntry` records. |
| `0x004b5e80-0x004b5ebc` | `sub_4B5E80` | `0x3c` / 60 bytes (Verified with int_convert.py) | Free 36-byte `TreeElem` vector storage with MSVC aligned-allocation validation. |
| `0x004b5ec0-0x004b5efc` | `sub_4B5EC0` | `0x3c` / 60 bytes (Verified with int_convert.py) | Free 12-byte string-leading record vector storage with the same aligned-allocation validation. |

End probes at `0x004b5cbc`, `0x004b5ce5`, `0x004b5d14`, `0x004b5ddf`, `0x004b5e75`, `0x004b5ebc`, and `0x004b5efc` all return `Not a function`.

IDA MCP `get_bytes` reconfirms the target-neighborhood padding:

- `0x004b5c3f-0x004b5c40`: `0xcc`.
- `0x004b5cbc-0x004b5cc0`: four `0xcc` bytes.
- `0x004b5ce5-0x004b5cf0`: eleven `0xcc` bytes.
- `0x004b5d14-0x004b5d20`: twelve `0xcc` bytes.
- `0x004b5ddf-0x004b5de0`: one `0xcc` byte.
- `0x004b5e75-0x004b5e80`: eleven `0xcc` bytes.
- `0x004b5ebc-0x004b5ec0`: four `0xcc` bytes.
- `0x004b5efc-0x004b5f00`: four `0xcc` bytes.

The padding is already listed in [UID:0000VN] `by-memory/-ignored.md`; no new padding page is needed.

## Live Caller / Callee Evidence

IDA MCP `xrefs_to` gives complete caller sets for the seven helper starts:

| Start | Xrefs / callers | Meaning |
| --- | --- | --- |
| `0x004b5c40` | 26 code xrefs from `0x004b3350`, `0x004b4240`, `0x004b4520`, and `0x004b4fd0` | Local FolderTreePane directory-entry sort/compare normalization helper. No SpelledPane caller. |
| `0x004b5cc0` | one code xref from `0x004b3d50` | 36-byte tree-storage relocation/destruction helper used by `TreeStorage<FolderTreePane::TreeElem>::InsertAt`. |
| `0x004b5cf0` | one code xref from `0x004b3fb0`, one from `0x00572fd0` | Shared 12-byte string-leading record range-destroy helper used by FolderTreePane and SpelledPane vector insert paths. |
| `0x004b5d20` | two code xrefs from `0x004b3d50` | 36-byte tree-storage range copy-construct helper. |
| `0x004b5de0` | two code xrefs from `0x004b3fb0` | FolderTreePane-local 12-byte `DirectoryEntry` range copy-construct helper. |
| `0x004b5e80` | one code xref from `0x004b3d50` | 36-byte tree-storage free helper. |
| `0x004b5ec0` | one code xref from `0x004b3fb0`, one from `0x00572fd0` | Shared 12-byte string-leading record vector free helper used by FolderTreePane and SpelledPane vector insert paths. |

IDA MCP `callees` confirms the helper dependencies:

- `0x004b5c40` calls `0x00582a90`, `0x005830c0`, `0x00583450`, and `0x00582980`.
- `0x004b5cc0` and `0x004b5cf0` call `0x00582b70`.
- `0x004b5d20` and `0x004b5de0` call `0x00582a90`.
- `0x004b5e80` and `0x004b5ec0` call `0x005c7526` and `__invalid_parameter_noinfo_noreturn`.

The StringBase aggregate currently documents `0x00582a90` as `ShareOrCopyWideFromStringBase`, `0x00582b70` as the wide destructor/release body, `0x005830c0` as wide COW detach, `0x00583450` as a string access/metadata helper in the later string family, and `0x00582980` as a wide uppercase-in-place secure CRT wrapper. Therefore `0x004b5c40` is better described as copy-to-comparison-key plus uppercase/COW normalization, not a generic opaque string helper.

## Live Decompilation Summary

### `0x004b5c40`

The function receives source string object in `ecx`, destination string object as one stack argument, returns the destination, and uses C++ EH cleanup for the partially constructed destination. Disassembly shows:

- `mov esi, [ebp+arg_0]` loads destination.
- `push ecx; mov ecx, esi; call 0x00582a90` copy/share-constructs destination from the source.
- `call 0x005830c0` detaches or prepares the wide buffer for mutation.
- `call 0x00583450` obtains string metadata/length.
- `push length + 1; push [esi]; call 0x00582980` uppercases the wide buffer in place.
- EH cleanup at `0x005fec80` jumps to `0x00582b70` on the destination if construction reached the cleanup state.

Best descriptive source-facing role: `FolderTreeDirectoryEntryNormalizeNameForCompare`, or if the implementation wants a more literal name, `CopyUppercaseDirectoryEntryNameForCompare`. This helper is part of the folder-tree directory-entry comparator/sort expression and should not be represented as a public `FolderTreePane` method.

### `0x004b5cc0`

Decompilation walks `i += 36` and calls `0x00582b70(i + 20)`. This is 36-byte `FolderTreePane::TreeElem` range destruction for the embedded `name` field at `+0x14`.

Best descriptive role: `FolderTreeElemRangeDestroy`.

### `0x004b5cf0`

Decompilation walks `i += 3` dwords and calls `0x00582b70(i)`. This is 12-byte string-leading record range destruction. It is shared between `0x004b3fb0` and `0x00572fd0`, so it cannot be assigned solely to FolderTreePane.

Best descriptive role: `SharedStringLeadingRecordRangeDestroy`.

### `0x004b5d20`

Decompilation copy-constructs 36-byte records: five leading dwords, `0x00582a90` string copy at destination `+0x14`, words at `+0x18/+0x1a`, flag bytes at `+0x1c/+0x1d`, and byte `+0x20`. This exactly matches [UID:0001UJ] `FolderTreePane::TreeElem`.

Best descriptive role: `FolderTreeElemRangeCopyConstruct`.

### `0x004b5de0`

Decompilation copy-constructs FolderTreePane 12-byte `DirectoryEntry` records: `name` at `+0x00`, words at `+0x04/+0x06`, and bytes at `+0x08/+0x09`. This helper is only called from [UID:000348] `FolderTreeDirectoryEntryVectorInsertAt`, unlike the shared 12-byte destroy/free helpers.

Best descriptive role: `FolderTreeDirectoryEntryRangeCopyConstruct`.

### `0x004b5e80`

Decompilation frees storage for `36 * count` bytes. If the byte count is at least `0x1000` / 4096 bytes (Verified with int_convert.py), it validates the aligned-allocation back pointer using the `0x1f` / 31-byte (Verified with int_convert.py) maximum alignment gap before freeing.

Best descriptive role: `FolderTreeElemVectorStorageFree`.

### `0x004b5ec0`

Decompilation is the 12-byte equivalent of `0x004b5e80`, freeing `12 * count` bytes with the same large-allocation validation. Xrefs show reuse from FolderTreePane and SpelledPane.

Best descriptive role: `SharedStringLeadingRecordVectorStorageFree`.

## Heuristic / Inference Reanalysis And Validation

### Issue: should the parent aggregate remain reconstructable/emitting?

- Current state: `CANONICAL_OWNER:0000JG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JG`.
- Evidence against keeping that state:
  - The range is seven separate functions, not one source-level item.
  - It contains explicit alignment padding between function bodies.
  - Two functions are shared by both FolderTreePane and SpelledPane vector insert paths.
  - Three functions are 36-byte `TreeElem` storage/template support better owned through `TreeStorage<FolderTreePane::TreeElem>` and `FolderTreePane::TreeElem`.
  - One function is FolderTreePane-local `DirectoryEntry` range copy support.
  - One function is a comparator/string-normalization support helper for the directory-entry sort chain.
  - Formal aggregate C++ would either be empty or a decompiler-shaped list of helper bodies, both of which are worse than original-like mid-2000s C++.
- Best decision: make the parent target a non-emitting split/index page, following the current StringBase aggregate pattern at [UID:0001J1].
- Rejected alternative: keep [UID:0000JG] as canonical owner for the whole target. That hides the SpelledPane reuse and incorrectly treats shared compiler/template helpers as FolderTreePane-owned source functions.
- Rejected alternative: move the whole target to SpelledPane. Only two 12-byte helpers have SpelledPane xrefs, and the remaining five helper bodies are FolderTreePane-only.
- Rejected alternative: assign the whole target to `StringBase`/`StringUtil`. The string helpers are dependencies. The target's record strides and caller contexts are vector/container support for FolderTreePane and SpelledPane, not StringBase implementation.
- Rejected alternative: assign the whole target to `VectorHelpers`. That would create an artificial source file from compiler/template instantiations and would not match the caller-specific source contexts.

### Issue: exact child split requirements

The current target has enough evidence for implementation-ready child pages. The split should not be deferred as a future research blocker. Recommended child plan:

| New child range | Recommended filename stem | Recommended metadata/disposition |
| --- | --- | --- |
| `0x004b5c40-0x004b5cbc` | `FolderTreeDirectoryEntryNormalizeNameForCompare` | `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000JG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JG`; formal `RECONSTRUCTION_CPP CODE` must contain the exact comment-only marker below, routing source shape through [UID:000343] and [UID:0000JG]. |
| `0x004b5cc0-0x004b5ce5` | `FolderTreeElemRangeDestroy` | `COMPLETION:87`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000FC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FC`; formal `RECONSTRUCTION_CPP CODE` must contain the exact comment-only marker below, routing source shape through [UID:0002MV] and [UID:0000FC]. |
| `0x004b5cf0-0x004b5d14` | `SharedStringLeadingRecordRangeDestroy` | `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, `EMITTER_UIDS:` blank; formal C++ blank with target-specific no-code proof because the helper is shared by [UID:000348] and [UID:00039O] and has no single safe source owner/emitter. |
| `0x004b5d20-0x004b5ddf` | `FolderTreeElemRangeCopyConstruct` | `COMPLETION:87`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000FC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FC`; formal `RECONSTRUCTION_CPP CODE` must contain the exact comment-only marker below, routing source shape through [UID:0002MV], [UID:0000FC], and [UID:0001UJ]. |
| `0x004b5de0-0x004b5e75` | `FolderTreeDirectoryEntryRangeCopyConstruct` | `COMPLETION:87`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000JG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JG`; formal `RECONSTRUCTION_CPP CODE` must contain the exact comment-only marker below, routing source shape through [UID:000348] and [UID:0000JG]. |
| `0x004b5e80-0x004b5ebc` | `FolderTreeElemVectorStorageFree` | `COMPLETION:87`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000FC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FC`; formal `RECONSTRUCTION_CPP CODE` must contain the exact comment-only marker below, routing source shape through [UID:0002MV] and [UID:0000FC]. |
| `0x004b5ec0-0x004b5efc` | `SharedStringLeadingRecordVectorStorageFree` | `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, `EMITTER_UIDS:` blank; formal C++ blank with target-specific no-code proof because the helper is shared by [UID:000348] and [UID:00039O] and has no single safe source owner/emitter. |

If the supervisor chooses to avoid new child pages in the immediate callback, the parent should not be raised above `88/90`; its correct high-quality state depends on either creating the children or explicitly documenting the accepted non-emitting split plan in the parent. The better implementation is to create the children now.

### Issue: child-page formal reconstruction dispositions

The implementation callback should not leave any reconstructable/emitting child with a blank formal block or generic "no standalone C++" prose. Each child page must use one of the following implementation-ready dispositions.

#### `0x004b5c40-0x004b5cbc.FolderTreeDirectoryEntryNormalizeNameForCompare`

- Metadata: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000JG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JG`.
- Formal `RECONSTRUCTION_CPP CODE` content, inserted exactly between the formal begin/end headers:

```cpp
// Compiler-emitted FolderTreePane child-directory name-normalization support.
// Reconstructed by [UID:000343] and the [UID:0000JG] FolderTreePane
// child-directory sort expression; no standalone helper body is emitted here.
```

- Reason: the helper is real source-derived comparison support, but a handwritten `NormalizeNameForCompare` body would preserve a compiler-lowered helper instead of the likely original sort/comparator source shape.

#### `0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy`

- Metadata: `COMPLETION:87`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000FC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FC`.
- Formal `RECONSTRUCTION_CPP CODE` content, inserted exactly between the formal begin/end headers:

```cpp
// Compiler-emitted TreeStorage<FolderTreePane::TreeElem> range-destroy support.
// Reconstructed by [UID:0002MV] through [UID:0000FC]; no standalone helper
// body is emitted here.
```

- Reason: the source-level intent is the `TreeStorage<FolderTreePane::TreeElem>` insertion/relocation expression; hand-emitting this destructor loop would turn template support into false handwritten source.

#### `0x004b5cf0-0x004b5d14.SharedStringLeadingRecordRangeDestroy`

- Metadata: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, `EMITTER_UIDS:` blank.
- Formal `RECONSTRUCTION_CPP CODE`: blank.
- Target-specific no-code proof: xrefs show this exact 12-byte string-leading record range destroy helper is shared by [UID:000348] `FolderTreeDirectoryEntryVectorInsertAt` and [UID:00039O] `SpelledPaneEntryVectorInsert`. No single FolderTreePane, SpelledPane, or type owner can emit it without claiming another owner's compiler/template support. The source shape belongs in each consumer's typed vector/source expression, not in a standalone shared source helper page.

#### `0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct`

- Metadata: `COMPLETION:87`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000FC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FC`.
- Formal `RECONSTRUCTION_CPP CODE` content, inserted exactly between the formal begin/end headers:

```cpp
// Compiler-emitted TreeStorage<FolderTreePane::TreeElem> range-copy support.
// Reconstructed by [UID:0002MV] through [UID:0000FC] and [UID:0001UJ];
// no standalone helper body is emitted here.
```

- Reason: the copied fields are exactly [UID:0001UJ] `TreeElem` storage state, but the original human source should be the `TreeStorage<FolderTreePane::TreeElem>` insertion/relocation expression rather than an out-of-line copy loop authored by hand.

#### `0x004b5de0-0x004b5e75.FolderTreeDirectoryEntryRangeCopyConstruct`

- Metadata: `COMPLETION:87`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000JG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JG`.
- Formal `RECONSTRUCTION_CPP CODE` content, inserted exactly between the formal begin/end headers:

```cpp
// Compiler-emitted FolderTreePane DirectoryEntry range-copy support.
// Reconstructed by [UID:000348] and the [UID:0000JG] child-directory
// vector source expression; no standalone helper body is emitted here.
```

- Reason: this is FolderTreePane-local scratch `DirectoryEntry` relocation support, but the likely original source is the local child-directory vector expression inside the owning expansion path, not a standalone named helper.

#### `0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree`

- Metadata: `COMPLETION:87`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000FC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FC`.
- Formal `RECONSTRUCTION_CPP CODE` content, inserted exactly between the formal begin/end headers:

```cpp
// Compiler-emitted TreeStorage<FolderTreePane::TreeElem> vector-storage free support.
// Reconstructed by [UID:0002MV] through [UID:0000FC]; no standalone helper
// body is emitted here.
```

- Reason: the large-allocation validation/free behavior is compiler/runtime vector storage support generated from the tree-storage source expression; hand-emitting it as a source helper would be decompiler-shaped.

#### `0x004b5ec0-0x004b5efc.SharedStringLeadingRecordVectorStorageFree`

- Metadata: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, `EMITTER_UIDS:` blank.
- Formal `RECONSTRUCTION_CPP CODE`: blank.
- Target-specific no-code proof: xrefs show this exact 12-byte storage-free helper is shared by [UID:000348] `FolderTreeDirectoryEntryVectorInsertAt` and [UID:00039O] `SpelledPaneEntryVectorInsert`. The body is compiler/runtime vector storage cleanup for multiple typed consumer contexts; assigning one owner/emitter or adding a marker under one route would misrepresent shared generated support as a single source artifact.

### Issue: FolderTreePane 36-byte versus 12-byte record confusion

- 36-byte family:
  - `0x004b5cc0`, `0x004b5d20`, and `0x004b5e80` operate on `0x24` / 36-byte records (Verified with int_convert.py).
  - They match [UID:0001UJ] `FolderTreePane::TreeElem`: five link/state dwords, string at `+0x14`, words at `+0x18/+0x1a`, bytes at `+0x1c/+0x1d`, and skip byte at `+0x20`.
  - They are called by [UID:0002MV] `TreeStorage<FolderTreePane::TreeElem>::InsertAt`, not by the directory-entry sort.
- 12-byte FolderTreePane family:
  - `0x004b5de0` operates on the FolderTreePane local `DirectoryEntry` scratch record: `name`, `rowIndex`, `depth`, `childrenLoaded`, and `expanded`.
  - It is called only by [UID:000348] `FolderTreeDirectoryEntryVectorInsertAt`.
- Shared 12-byte family:
  - `0x004b5cf0` and `0x004b5ec0` are shared by [UID:000348] and [UID:00039O].
  - SpelledPane's insert helper has a different copy helper at `0x00573880` for its full 12-byte record, but it reuses the same destroy and storage-free helpers because those helpers only need the leading string and element width.
- Best documentation rule: preserve the distinct `TreeElem`, FolderTreePane local `DirectoryEntry`, and generic string-leading 12-byte record concepts. Do not collapse them into one type.

### Issue: first-draft C++ / no-code status

- Parent target [UID:00022E]: exact no-code proof. Formal C++ should remain blank after reclassification to `RECONSTRUCTABLE:FALSE`.
- Reconstructable/emitting child helpers: formal C++ must not be blank. The correct implementation is the exact comment-only marker specified in the child-page formal reconstruction disposition section above. Full helper bodies would look like compiler-output source, not likely original source.
- Non-emitting shared 12-byte child helpers: `RECONSTRUCTABLE:FALSE`, no owner/emitter, blank formal C++, and target-specific no-code proof because the helpers are shared across FolderTreePane and SpelledPane contexts.
- 12-byte FolderTreePane local copy helper: use the exact marker routing it through [UID:000348] and [UID:0000JG]; source should express local `DirectoryEntry` vector construction/copy through the owning expansion/sort expression.
- The high-level source to reconstruct remains the `FolderTreePane::ExpandNode` / generated alias `FindFirstVisibleChild` path, plus its local `DirectoryEntry` sorting/vector expression, and the SpelledPane entry-vector owner paths.

## Positive Evidence Summary

- Live IDA confirms exact start/end boundaries for all seven helper functions and padding bytes between them.
- Live xrefs prove the 36-byte helpers are local to FolderTreePane tree storage.
- Live xrefs prove `0x004b5c40` is only used by FolderTreePane directory-entry sort/compare helpers.
- Live xrefs prove `0x004b5cf0` and `0x004b5ec0` are shared by FolderTreePane and SpelledPane.
- Live decompilation proves the exact record widths, copied fields, destructor offsets, and MSVC aligned-allocation validation paths.
- Current class/file/type docs already define the correct `TreeElem`, `DirectoryEntry`, `TreeStorage`, sort-chain, and SpelledPane vector contexts.
- Executed B reports already reject standalone source files for compiler-generated sort/vector support and establish the "emit high-level source expression, not helper internals" rule for this neighborhood.

## Negative Evidence Summary

- No evidence supports treating the whole range as one `FolderTreePane.cpp` source function or one class method.
- No evidence supports `FontImageLib` ownership despite the physical successor range at `0x004b5f00`.
- No evidence supports a standalone `VectorHelpers.cpp` or `StringUtil.cpp` owner for this exact target.
- No evidence supports assigning shared 12-byte destroy/free helpers solely to SpelledPane or solely to FolderTreePane.
- No recovered symbols/PDB/source names prove exact original helper spellings. The report uses source-facing descriptive names based on behavior and caller context.
- The current research-tracker row is stale and should not be treated as the current target score.

## Open-Question Closure

- "Why is the target still not-covered/low-scored?" Closed: the current generated queue row is stale, and the page is still source-shaped incorrectly as an emitting aggregate. It needs report execution plus split/index repair.
- "Does the target need more research before improvement?" Closed: no. Current live MCP evidence is enough for exact child split recommendations and parent reclassification.
- "Can the current parent emit first-draft C++?" Closed: no. The parent is not a source unit and should be non-emitting.
- "Should the two shared 12-byte helpers be owned by FolderTreePane because they are physically adjacent?" Closed: no. Xrefs show SpelledPane reuse; source-level reconstruction belongs in both consumer contexts, not in a single direct owner.
- "Should all seven helpers be treated as compiler-generated and ignored?" Closed: no. The shared helpers should be non-emitting; the FolderTree-specific helpers are source-declared/generated-binary support that should be documented as exact child pages and routed through the correct FolderTreePane/type owners.

## Target / Support Implementation Checklist

Implementation callback completed by B009 on 2026-06-26. Each item below was applied or explicitly excluded with proof.

Target parent [UID:00022E] `by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md`:

- [x] Changed metadata to `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++. Proof: validator command `python .\tools\validator.py --mode file --file by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md --apply --queue-timeout 240`, `command_id:000000002578`, timestamp `2026-06-26T13:40:11-04:00`, exit `0`, `ok:1`.
- [x] Changed status/disposition to reviewed non-emitting split/index page over seven helper functions and padding.
- [x] Preserved function/padding/xref evidence and added live MCP session `80de0a67` split evidence.
- [x] Added parent no-code proof explaining why aggregate C++ would conflate compiler/template helpers, FolderTreePane-local helpers, TreeStorage/TreeElem support, and shared FolderTreePane/SpelledPane 12-byte support.
- [x] Added stale-tracker note; no generated tracker file was manually edited.
- [x] Replaced FolderTreePane-owned aggregate/emitter wording with split disposition for `TreeElem`, FolderTreePane `DirectoryEntry`, and shared string-leading record support.

Created exact child by-memory pages:

- [x] Created [UID:000446] `by-memory/0x004b5c40-0x004b5cbc.FolderTreeDirectoryEntryNormalizeNameForCompare.md` with `88/91`, owner/emitter [UID:0000JG], caller/callee/decompile evidence, and the exact accepted formal marker. Initial validator `command_id:000000002570`, timestamp `2026-06-26T13:33:02-04:00`, exit `0`, inserted UID `000446`.
- [x] Created [UID:000447] `by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md` with `87/91`, owner/emitter [UID:0000FC], 36-byte stride/name-release evidence, and the exact accepted formal marker. Initial validator `command_id:000000002571`, timestamp `2026-06-26T13:33:04-04:00`, exit `0`, inserted UID `000447`.
- [x] Created [UID:000448] `by-memory/0x004b5cf0-0x004b5d14.SharedStringLeadingRecordRangeDestroy.md` with `88/92`, no owner/emitter, blank C++, and no-code proof shared by [UID:000348] and [UID:00039O]. Initial validator `command_id:000000002572`, timestamp `2026-06-26T13:33:06-04:00`, exit `0`, inserted UID `000448`; final revalidation after [UID:00039O] registry repair `command_id:000000002588`, timestamp `2026-06-26T13:40:37-04:00`, exit `0`, `ok:1`.
- [x] Created [UID:000449] `by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md` with `87/91`, owner/emitter [UID:0000FC], [UID:0001UJ] field-copy evidence, and the exact accepted formal marker. Initial validator `command_id:000000002573`, timestamp `2026-06-26T13:33:08-04:00`, exit `0`, inserted UID `000449`.
- [x] Created [UID:00044A] `by-memory/0x004b5de0-0x004b5e75.FolderTreeDirectoryEntryRangeCopyConstruct.md` with `87/91`, owner/emitter [UID:0000JG], FolderTreePane-only xrefs, `DirectoryEntry` field evidence, and the exact accepted formal marker. Initial validator `command_id:000000002574`, timestamp `2026-06-26T13:33:09-04:00`, exit `0`, inserted UID `00044A`.
- [x] Created [UID:00044B] `by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md` with `87/91`, owner/emitter [UID:0000FC], 36-byte allocation-size/free validation evidence, and the exact accepted formal marker. Initial validator `command_id:000000002575`, timestamp `2026-06-26T13:33:11-04:00`, exit `0`, inserted UID `00044B`.
- [x] Created [UID:00044C] `by-memory/0x004b5ec0-0x004b5efc.SharedStringLeadingRecordVectorStorageFree.md` with `88/92`, no owner/emitter, blank C++, and no-code proof shared by [UID:000348] and [UID:00039O]. Initial validator `command_id:000000002576`, timestamp `2026-06-26T13:33:21-04:00`, exit `0`, inserted UID `00044C`; final revalidation after [UID:00039O] registry repair `command_id:000000002589`, timestamp `2026-06-26T13:40:48-04:00`, exit `0`, `ok:1`.

Support docs:

- [x] Updated [UID:000157] `FolderTreePaneTreeAndSortHelpers` to treat [UID:00022E] as a non-emitting split/index successor and link all seven child pages. Final validator `command_id:000000002591`, timestamp `2026-06-26T13:41:28-04:00`, exit `0`, `ok:1`.
- [x] Updated [UID:0000JG] `by-file/FolderTreePane.md` and [UID:00005A] `by-class/FolderTreePane.md` so exact child pages carry vector/string support details. Final validators: by-file `command_id:000000002592`, timestamp `2026-06-26T13:41:39-04:00`, exit `0`, `ok:1`; by-class `command_id:000000002595`, timestamp `2026-06-26T13:42:30-04:00`, exit `0`, `ok:1`.
- [x] Updated [UID:0001WP] `FolderTreePaneTreeTemplates.md`, [UID:0000FC] `TreeStorage_struct_FolderTreePane__TreeElem_`, and [UID:0001UJ] `FolderTreePane__TreeElem.md` to cross-link the 36-byte child helpers. Validators: template `command_id:000000002582`, timestamp `2026-06-26T13:40:27-04:00`, exit `0`; TreeStorage `command_id:000000002583`, timestamp `2026-06-26T13:40:29-04:00`, exit `0`; TreeElem `command_id:000000002584`, timestamp `2026-06-26T13:40:31-04:00`, exit `0`, `ok:1`.
- [x] Updated [UID:000343] `FolderTreeDirectoryEntryNameLess` to link [UID:000446] as the exact `0x004b5c40` normalization child. Validator `command_id:000000002585`, timestamp `2026-06-26T13:40:32-04:00`, exit `0`, `ok:1`.
- [x] Updated [UID:000348] `FolderTreeDirectoryEntryVectorInsertAt` to link [UID:00044A], [UID:000448], [UID:00044C], and [UID:00039O]. Final validator `command_id:000000002598`, timestamp `2026-06-26T13:43:20-04:00`, exit `0`, `ok:1`.
- [x] Updated [UID:00039O] `SpelledPaneEntryVectorInsert` to link [UID:000448] and [UID:00044C] while preserving `0x00573880` as the separate SpelledPane copy helper. Validator `command_id:000000002587`, timestamp `2026-06-26T13:40:35-04:00`, exit `0`, `ok:1`; it also repaired [UID:00039O] registry mapping.
- [x] [UID:0000VN] `by-memory/-ignored.md` was not edited because the existing ignored ledger already covers `0x004b5c3f-0x004b5c40`, all internal `0xcc` gaps, and `0x004b5efc-0x004b5f00`.

Supervisor-owned coverage / generated files:

- [x] No manual `-coverage-report.md`, generated report, project-level report, validator/tool-state hand edit, or IDA DB edit was made by B009.
- [x] Pending supervisor coverage row remains supervisor-owned:

```text
    - [UID:00022E][0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers](by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md) 0x004b5c40-0x004b5efc | split helper inventory | FolderTreePaneVectorSupportHelpers : ignored : 90% : very-strong : B009 source-quality reanalysis reclassifies this seven-function helper cluster as a non-emitting split/index page rather than a single FolderTreePane emitter. Live IDA MCP session `80de0a67` confirms exact helper bodies at `0x004b5c40`, `0x004b5cc0`, `0x004b5cf0`, `0x004b5d20`, `0x004b5de0`, `0x004b5e80`, and `0x004b5ec0`, all internal and neighboring `0xcc` padding, 26 FolderTreePane-only calls to the name-normalization helper, 36-byte `TreeElem` range helpers used by `TreeStorage<FolderTreePane::TreeElem>`, FolderTreePane-only `DirectoryEntry` range-copy support, and shared 12-byte string-leading range-destroy/free helpers reused by FolderTreePane and SpelledPane. Exact child pages carry the source-bearing or non-emitting dispositions; this parent has blank owner/emitter/C++ because aggregate C++ would conflate generated/template helpers and multiple source contexts.
```

Validator/registry repair side effects:

- [x] All scoped by-* validators exited `0`. Validator-managed side effects included UID insertion for new children, UID-link insertion/update, validator registry updates, projected stats refresh lines, and deferred generated refresh markers.
- [x] Repaired stale [UID:00034C] registry path by validating `by-memory/0x004b4fd0-0x004b5271.FolderTreeDirectoryEntryAdjustHeap.md`: `command_id:000000002590`, timestamp `2026-06-26T13:41:23-04:00`, exit `0`, `ok:1`, `path_update` from the old `SortPartition` filename.
- [x] Repaired missing [UID:00036O] and [UID:00036N] registry mappings encountered during clean validation of FolderTreePane support references. Validators: [UID:00036O] data page `command_id:000000002594` then final `000000002597`; [UID:00036N] type/vtable page `command_id:000000002596`; all exited `0`.
- [x] Report execution/move to `research/executed/` was not run by B009; that remains supervisor-owned after supervisor verification.

## Implementation Status

- Changed by-* docs: parent [UID:00022E], seven new child pages [UID:000446]-[UID:00044C], and support docs [UID:000157], [UID:0000JG], [UID:00005A], [UID:0001WP], [UID:0000FC], [UID:0001UJ], [UID:000343], [UID:000348], [UID:00039O]. Additional validator registry repair scans touched [UID:00034C], [UID:00036O], and [UID:00036N].
- Generated/project-level/manual coverage files edited by B009: none.
- IDA DB changes: none.
- MCP status: available during the implementation; no new MCP failure was encountered.
- Leases used: B009 leased the target/support docs before editing. The original lease batch was already expired/cleared by release time; later registry-repair leases on [UID:00034C], [UID:00036O], and [UID:00036N] were released successfully. `current_leases.md` shows no active leases after implementation.
- Unchecked blockers: none for the accepted implementation callback. Coverage-report update and report execution are supervisor-owned.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/00022E-FolderTreePaneVectorSupportHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/00022E-FolderTreePaneVectorSupportHelpers-source-quality.md","timestamp":"2026-06-26T13:56:56","uid":"00022E"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
