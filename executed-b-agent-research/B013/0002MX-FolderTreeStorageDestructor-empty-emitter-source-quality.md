** TARGET-REPORT-UID:0002MX **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# [UID:0002MX] FolderTreeStorageDestructor Empty-Emitter Source-Quality Report

Report-only assignment: `B013-report-0002MX-FolderTreeStorageDestructor-empty-emitter-source-quality-20260628`
Revision assignment: `B013-revise-report-0002MX-FolderTreeStorageDestructor-empty-emitter-source-quality-20260629`
Stale-source support revision assignment: `B013-revise-report-0002MX-FolderTreeStorageDestructor-stale-source-support-fix-20260629`

Target: `by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md`

Required disposition: implementation-ready metadata/source-route repair for the current generated empty-emitter state in `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp`.

2026-06-29 revision scope: report revision only. No by-* docs, generated files, manual coverage reports, project-level generated files, validator/tool state, executed reports, or IDA DB were edited. The original report evidence is preserved; this revision adds the current Claim And Incorporation Ledger, current checklist wording, current MCP spot-check proof, stale simroot/source-lead handling, support-doc already-present distinctions, support-doc stale Wave/recovered-source cleanup requirements, and a score-blocker recheck under the current code-entry standard.

## Current Target State

Current target metadata:

- `COMPLETION:85`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000FC`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000FC`
- `EMITTER_POSITION_OPTIONAL:` blank
- Inline `RECONSTRUCTION_CPP CODE:[[[]]]` blank
- Block `RECONSTRUCTION_CPP CODE` blank

Current generated state:

- `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` currently emits [UID:0002MX] as an `Empty Emitter Marker`.
- The same generated file also has nearby empty markers for [UID:0000FC] and [UID:0002MV], so this target is part of the still-incomplete `TreeStorage<FolderTreePane::TreeElem>` source route.
- `auto-generated/-ag-research-tracker.md` lists [UID:0002MX] in `Files With Empty Emitters`, direct executed report count `0`, score `85/90`, average `87.5`.
- `auto-generated/-ag-coverage-report-by-memory.md` still records a stale blank-parent summary even though the target itself now has a canonical owner and emitter route.

Current documentation state:

- The target already identifies the range as the destructor/storage cleanup path for `TreeStorage<FolderTreePane::TreeElem>`.
- The existing item text still preserves an old "no final C++ until 95/95" style blocker. That blocker is stale under current code-entry policy and must be replaced with an exact formal disposition.
- Sibling support helper pages [UID:000447] `FolderTreeElemRangeDestroy` and [UID:00044B] `FolderTreeElemVectorStorageFree` already use nonblank comment-only formal markers because their bytes are compiler-emitted vector/range support rather than standalone handwritten source helpers. The original report's `00044B` / `00044C` sibling UID wording was stale and is corrected by this revision.

## Actual Evidence Checked

### Live MCP Session

Live MCP was available and used. This report is not fallback-only.

- Endpoint: `http://127.0.0.1:13337/mcp`
- JSON-RPC initialize succeeded with protocol `2025-06-18`.
- Server: `ida-pro-mcp` version `1.0.0`.
- `tools/list` exposed `65` tools, including `server_health`, `lookup_funcs`, `decompile`, `disasm`, `xrefs_to`, `callees`, `get_bytes`, `entity_query`, `type_query`, `search_structs`, `analyze_component`, `idb_open`, and `idb_list`.
- `idb_list` showed active session `supervisor_20260628_resume`.
- Session input path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Worker PID/state: backend worker, owned/adopted, active, PID `5124`.
- `server_health(database='supervisor_20260628_resume')` returned `status: ok`.
- Health details: module `NexusTK.exe`, imagebase `0x400000`, auto analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`.

### Existing Research And Support Leads

I checked the required executed reports and support docs as leads, then revalidated the target with live MCP:

- `executed-b-agent-research/B001/000157-FolderTreePaneTreeAndSortHelpers.md`
- `executed-b-agent-research/B009/00022E-FolderTreePaneVectorSupportHelpers-source-quality.md`
- [UID:0000FC] `by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md`
- [UID:0001UJ] `by-type/by-struct/FolderTreePane__TreeElem.md`
- [UID:0001WP] `by-type/by-template/FolderTreePaneTreeTemplates.md`
- [UID:0002MV] `by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md`
- [UID:000447] `by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md`
- [UID:00044B] `by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md`
- [UID:000448] `by-memory/0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup.md`
- [UID:000449] `by-memory/0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor.md`
- [UID:00044A] `by-memory/0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor.md`
- `by-file/FolderTreePane.md`
- `by-class/FolderTreePane.md`

2026-06-29 revision search terms: `0002MX`, `0x004b56e0`, `FolderTreeStorageDestructor`, and `TreeStorageDestructor` across `executed-b-agent-research` and `tools/leaser/Agents` Markdown. Relevant matches:

- `executed-b-agent-research/B001/000157-FolderTreePaneTreeAndSortHelpers.md`: exact child inventory row for `0x004b56e0-0x004b575f`, existing child assigned to [UID:0000FC].
- `executed-b-agent-research/B001/00034K-FolderTreePaneScalarDeletingDestructor-empty-emitter-source-quality.md`: outer pane destructor caller evidence for `0x004b5aab -> 0x004b56e0`.
- `executed-b-agent-research/B006/0002MV-FolderTreeStorageInsertAt-empty-emitter-source-quality.md`: sibling storage `InsertAt` report treats this B013 report as a pending lead only and preserves UID0002MX ownership pending acceptance.
- `executed-b-agent-research/B009/0002MY-FolderTreeResetToSingleRoot-empty-emitter-source-quality.md`: reset-to-root support report preserves current direct ownership for [UID:0002MV] and [UID:0002MX] and says not to insert destructor C++ as part of that separate target.
- Active report matches in `tools/leaser/Agents/Agent-B006` and `Agent-B010` were treated as sibling pending leads only, not accepted proof for UID0002MX. Supervisor assignment/tracker matches were used only to confirm revision scope, not binary evidence.

`by-structure.md` was rechecked for current source/source-generated labels, `CANONICAL_OWNER` / `EMITTER_UIDS` separation, current code-entry gate, by-memory range limits, and marker guidance for covered-by output. It confirms the report's recommendation: [UID:0002MX] is eligible for formal marker output because it is `RECONSTRUCTABLE:TRUE`, has a confirmed emitter route through [UID:0000FC] to [UID:0000JG], and its current average score is greater than `85`.

The documented lead path `E:\NTK\GhidraBridge\source-3\simroot_v2` is not present in this worktree (`Test-Path` false on 2026-06-29), so no source snapshot was available there. The existing report itself did not depend on actionable Wave2/Wave3/recovered-source evidence. A current support-doc scan did find active stale source-lead wording in planned implementation pages, especially `by-file/FolderTreePane.md` lines that say `Current recovered source: source-3/simroot_v2/class_FolderTreePane.cpp` and `Evidence basis: Wave3 generated source`. The future callback must historicalize or reject those lines as generated-source leads only. The UID0002MX disposition below is based on current by-* docs, executed reports, generated output symptoms, current by-structure rules, and live IDA MCP evidence, not on Wave3, simroot, or recovered-source authority.

### Current 2026-06-29 MCP Spot-Check

IDA MCP was available during the revision. Only read-only calls were made; no IDA process management or IDB writes were performed.

| Evidence | Current result |
| --- | --- |
| Listener/process state | `127.0.0.1:13337` listening under Python PID `8860`; IDA MCP-related processes included `idalib-mcp` PID `20228` and worker Python PID `9064`. |
| `initialize` | Succeeded, server `ida-pro-mcp` `1.0.0`, protocol `2025-06-18`. |
| `tools/list` | `65` tools exposed; active schema uses `queries` for `lookup_funcs`, `regions` for `get_bytes`, `addrs` for `xrefs_to`/`callees`, and singular `addr` for `disasm`/`decompile`. |
| `idb_list` | One active session: `07c55da0`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `9064`, `is_active:true`, `is_analyzing:false`. |
| `server_health(database='07c55da0')` | `status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`. |

Target-critical spot-check calls:

| Tool call | Result |
| --- | --- |
| `lookup_funcs` for `0x004b56e0`, `0x004b575f`, `0x004b5760`, `0x004b59f0`, `0x004b5a70` | `0x004b56e0 -> sub_4B56E0 size 0x7f`; `0x004b575f` is not a function; successor `0x004b5760 -> sub_4B5760 size 0x7d`; tree scalar destructor `0x004b59f0 -> sub_4B59F0 size 0x48`; outer pane scalar destructor `0x004b5a70 -> sub_4B5A70 size 0x84`. |
| `get_bytes` at `0x004b575f` size `17` and `0x004b56d0` size `16` | End boundary bytes start `0xcc 0x56 0x57 ...`, proving the target ends before the successor prologue. Preceding bytes are `0xc3` followed by `0xcc` padding before the target. |
| `xrefs_to 0x004b56e0` | Same five code xrefs as the original report: `0x004b1d28`, `0x004b565c`, `0x004b59ff`, `0x004b5aab`, and `0x005fe936`. These still reduce to constructor/EH cleanup, `Tree<FolderTreePane::TreeElem>` destruction, and outer `FolderTreePane` destruction categories. |
| `callees 0x004b56e0` | Same three callees: `sub_582B70`, `sub_5C7526`, and `__invalid_parameter_noinfo_noreturn`. |
| `disasm 0x004b56e0` | Confirms `lea ecx,[esi+14h]` / `call sub_582B70`, `add esi,24h`, large-allocation threshold `0x1000`, gap check `0x1f`, original-pointer load from `[esi-4]`, call to `sub_5C7526`, and zero stores to `[edi]`, `[edi+4]`, `[edi+8]`. |
| `decompile 0x004b56e0` | Confirms `v2 = *this`, loop to `this[1]`, `sub_582B70(v2 + 5)`, `v2 += 9`, large-allocation validation, `sub_5C7526(v2)`, and clearing `this[0..2]`. |
| `search_structs` filters `TreeStorage`, `TreeElem`, `FolderTreePane` | All returned `[]`; the current IDB still does not provide recovered UDTs for those source-facing names. A broad `type_query` was noisy and not used as positive type evidence. |

The current spot-check confirms rather than changes the original recommendation: exact range/boundary, caller/callee set, 36-byte stride, `+0x14` string cleanup, runtime free lowering, and missing recovered UDT evidence still support marker-only formal output under [UID:0000FC].

### Numeric Checks

I verified the important constants with `tools/int_convert.py`:

- `0x7f` = `127`
- `0x24` = `36`
- `0x1000` = `4096`
- `0x1f` = `31`
- `0x130` = `304`
- `0x170` = `368`
- `0x14` = `20`
- `0x4` = `4`
- `0x8` = `8`

## MCP Function And Boundary Evidence

### Function Lookup

`lookup_funcs` results:

| Address | Result | Meaning |
| --- | --- | --- |
| `0x004b56e0` | `sub_4B56E0`, size `0x7f` | Exact target function, 127 bytes. |
| `0x004b575f` | Not a function | End byte is one `int3` padding byte before the successor. |
| `0x004b5760` | `sub_4B5760`, size `0x7d` | Separate successor helper; not part of [UID:0002MX]. |
| `0x004b1b90` | `sub_4B1B90`, size `0x155` plus chunks | `FolderTreePane` constructor/setup with cleanup chunks. |
| `0x004b3d50` | `sub_4B3D50`, size `0x254` | `TreeStorage<FolderTreePane::TreeElem>::InsertAt` route. |
| `0x004b59f0` | `sub_4B59F0`, size `0x48` | `Tree<FolderTreePane::TreeElem>` scalar deleting destructor. |
| `0x004b5a70` | `sub_4B5A70`, size `0x84` | `FolderTreePane` scalar deleting destructor. |
| `0x004b5cc0` | `sub_4B5CC0`, size `0x25` | Range-destroy support helper. |
| `0x004b5e80` | `sub_4B5E80`, size `0x3c` | Vector storage free support helper. |

Boundary proof:

- `get_bytes(0x004b575f, 17)` begins with `0xcc 0x56 0x57 ...`, proving the target ends before `0x004b5760`.
- `get_bytes(0x004b56d0, 16)` shows a preceding `ret` followed by `int3` padding before the target region.
- There is no evidence that [UID:0002MX] should be merged with the previous or next helper.

### Target Decompilation

Live `decompile(0x004b56e0)` shows this normalized behavior:

1. Read `begin = this[0]`.
2. If `begin` is null, return without touching the storage.
3. Read `end = this[1]`.
4. If `begin != end`, walk records from `begin` to `end` in `0x24` byte strides.
5. For each 36-byte `FolderTreePane::TreeElem`, call `sub_582B70` on `element + 0x14`.
6. After element cleanup, compute capacity byte count from `this[2] - begin`.
7. If the storage byte count is at least `0x1000`, recover the original allocation pointer from the word immediately before the user pointer and validate that the pointer gap is not greater than `0x1f`.
8. Call `sub_5C7526` on the final block pointer.
9. Zero `this[0]`, `this[1]`, and `this[2]`.

This confirms the target is a destructor/storage cleanup body for a vector-like three-pointer storage object. The element cleanup call at `+0x14` is the strong local evidence for the `FolderTreePane::TreeElem::name` field placement.

### Target Disassembly

Live `disasm(0x004b56e0)` confirms the decompiler shape:

- `mov esi, [edi]`, then null-test of the begin pointer.
- `mov ebx, [edi+4]`, loop end pointer.
- `lea ecx, [esi+14h]`, `call sub_582B70`.
- `add esi, 24h`, proving a 36-byte record stride.
- Capacity computation from `[edi+8] - begin`, using the expected multiply/divide sequence for 36-byte elements.
- Large-allocation branch at `0x1000` bytes.
- Guard gap limit `0x1f`.
- Original allocation pointer read from `[esi-4]` on the large-allocation branch.
- `call sub_5C7526`, then zero stores to `[edi]`, `[edi+4]`, and `[edi+8]`.

### Callees And Runtime Roles

`callees(0x004b56e0)` reports:

- `sub_582B70`: destructs/releases the string object at `TreeElem + 0x14`.
- `sub_5C7526`: wraps runtime free.
- `__invalid_parameter_noinfo_noreturn`: large-allocation pointer validation failure path.

Additional live checks:

- `decompile(0x00582b70)` shows `sub_582B70` as a string-like destructor/release wrapper that calls `sub_5833A0(this)`.
- `decompile(0x005c7526)` shows `sub_5C7526(void *Block) { j_j___free_base(Block); }`.
- `lookup_funcs(0x005c74f6)` identifies `??2@YAPAXI@Z`, the local operator-new allocation routine used by sibling storage code.

The free and invalid-parameter sequence is compiler/runtime lowering, not a good source-facing body to hand-author in isolation.

### Xrefs To The Target

`xrefs_to(0x004b56e0)` reports five code references:

| Caller address | MCP function context | Source meaning |
| --- | --- | --- |
| `0x004b1d28` | No containing function | Constructor cleanup/failure block in the `FolderTreePane` setup region. |
| `0x004b565c` | `sub_4B1B90` chunk | EH cleanup chunk that resets the tree vtable then destroys storage. |
| `0x004b59ff` | `sub_4B59F0` | `Tree<FolderTreePane::TreeElem>` scalar deleting destructor. |
| `0x004b5aab` | `sub_4B5A70` | `FolderTreePane` scalar deleting destructor. |
| `0x005fe936` | `sub_4B1B90` chunk | Constructor EH cleanup tail thunk. |

The five raw xrefs collapse to three source-level caller categories:

1. Constructor failure/exception cleanup for `FolderTreePane`.
2. `Tree<FolderTreePane::TreeElem>` destruction.
3. Containing `FolderTreePane` destruction.

This supports keeping the target under `TreeStorage<FolderTreePane::TreeElem>` and the `FolderTreePane.cpp` source route. It does not support reclassifying the range as a random shared runtime helper.

### Caller Body Evidence

`decompile(0x004b1b90)` confirms the constructor/setup route:

- `FolderTreePane` vtables are stored at the object base and secondary subobjects.
- The tree subobject begins at `this + 0x130`.
- The storage three-pointer span is immediately after the `Tree<FolderTreePane::TreeElem>` vtable, at offsets corresponding to the target destructor's `begin`, `end`, and `capacity/end` pointers.
- The iterator subobject begins at `this + 0x170` and points back to the tree at `this + 0x130`.
- Constructor cleanup chunks call [UID:0002MX] after restoring the `Tree<FolderTreePane::TreeElem>` vtable.

`insn_query(0x004b1d20..0x004b1d40)` confirms the non-function cleanup block:

- `0x004b1d20`: store `Tree<FolderTreePane::TreeElem>` vftable at `[edi+0x130]`.
- `0x004b1d28`: call [UID:0002MX].
- `0x004b1d33`: call base/control cleanup after storage destruction.

`decompile(0x004b59f0)` confirms the tree scalar deleting destructor:

- Store `Tree<FolderTreePane::TreeElem>` vftable.
- Call [UID:0002MX] on `Block + 1`, meaning the storage subobject after the vtable.
- Call the base cleanup.
- Optionally free the object for scalar-deleting destructor flags.

`decompile(0x004b5a70)` confirms the containing pane scalar deleting destructor:

- Restore `FolderTreePane`, `TreeItor`, and `Tree<FolderTreePane::TreeElem>` vtables.
- Call [UID:0002MX] on the tree storage at the pane's `+0x130` tree subobject.
- Continue through base/control cleanup and optional delete.

### Vtable Evidence

Live `xrefs_to` on the known tree/template vtables supports the same object layout:

- `xrefs_to(0x0061a500)`: five references from constructor/setup, cleanup, tree scalar destructor, and outer pane destructor to the `Tree<FolderTreePane::TreeElem>` vtable.
- `xrefs_to(0x0061a510)`: multiple references across iterator construction, traversal, cleanup, and destructor sites for `TreeItor<FolderTreePane::TreeElem>`.
- `xrefs_to(0x0061a518)`: references from constructor/setup, cleanup, and outer pane destructor for the `FolderTreePane` vtable route.

### Negative Type Evidence

Live type/structure queries found no recovered local IDA UDTs for the source-facing names:

- `type_query('*TreeStorage*')`: no result.
- `type_query('*TreeElem*')`: no result.
- `type_query('*FolderTreePane*')`: no result.
- `search_structs(filter='TreeStorage')`: no result.
- `search_structs(filter='TreeElem')`: no result.
- `search_structs(filter='FolderTreePane')`: no result.

This matters for the formal C++ decision. The source model is well-supported by by-* documentation and machine code, but the local IDB does not provide stable recovered C++ type declarations or member names for a compilable destructor body.

## Positive Evidence Summary

- [UID:0002MX] is a real bounded function at `0x004b56e0`, size `0x7f`.
- The function is not a tail chunk of another helper and is not merged with the successor at `0x004b5760`.
- The body operates on a three-pointer storage object: begin, end, capacity/end.
- The loop walks 36-byte elements, matching `FolderTreePane::TreeElem`.
- The per-element destructor call targets offset `+0x14`, matching `TreeElem::name`.
- The body frees the storage allocation and zeros all three storage pointers.
- All current callers are constructor cleanup, tree destruction, or containing pane destruction paths.
- Existing executed reports place the `Tree`, `TreeStorage`, and `TreeItor` concrete templates in the `FolderTreePane.cpp` route.
- Sibling storage helper pages already establish a comment-only formal marker pattern for compiler-lowered vector support where standalone handwritten source would be misleading.

## Negative Evidence Summary

- No local IDA UDT gives stable formal member names for the storage pointers.
- No original source snapshot was available at the documented `simroot_v2` lead path.
- The target's binary body includes MSVC/runtime large-allocation validation and free lowering; that should not be presented as handwritten application source.
- The surrounding `TreeStorage<FolderTreePane::TreeElem>` class declaration is still not formally emitted in [UID:0000FC].
- [UID:0002MV] `InsertAt` is also still a blank formal body, so emitting only this destructor body would put one low-level storage method ahead of the unresolved storage class/source model.
- Clearing `EMITTER_UIDS` would lose the known source route and would not explain the source-level storage destructor semantics.
- Reclassifying [UID:0002MX] as `RECONSTRUCTABLE:FALSE` would understate the source relationship: this is not random data or padding, it is a concrete template storage destructor lowered into code.

## Heuristic / Inference Reanalysis And Validation

The older target text treated the function as source-owned but left C++ blank because final code was below a high confidence gate. Current workflow requires an implementation-ready disposition instead of preserving a blank emitter route.

The correct repair is not to emit a full decompiler-shaped destructor body. The target body is source-related, but the observed bytes are heavily compiler-lowered:

- The string destructor call and vector stride express source-level destruction of `TreeElem::name`.
- The large-allocation validation and original-pointer recovery express MSVC allocator/runtime mechanics.
- The three-pointer zeroing is consistent with vector/storage destruction, but the exact source declaration and destructor spelling depend on the unresolved `TreeStorage` class declaration.

Therefore, the best current source-quality repair is a nonblank formal marker on [UID:0002MX] that explicitly preserves the source route through `TreeStorage<FolderTreePane::TreeElem>` while preventing generated output from presenting the binary helper body as handwritten C++.

This is the same conservative pattern already used by the adjacent storage support helper pages, but the marker must be specific to the destructor/storage cleanup role so the target no longer remains an empty-emitter placeholder.

## Ownership And Source Placement Analysis

Recommended owner route:

- Keep `CANONICAL_OWNER:0000FC`.
- Keep `EMITTER_UIDS:0000FC`.
- Keep `EMITTER_POSITION_OPTIONAL:` blank.
- Keep `RECONSTRUCTABLE:TRUE`.

Rationale:

- [UID:0000FC] is the direct `TreeStorage<FolderTreePane::TreeElem>` support page and is the most specific source owner.
- [UID:0000JG] / `FolderTreePane.cpp` remains the file-level source route for the concrete template instantiations.
- [UID:0001WP] is the template-support context, not the direct emitter owner for this concrete destructor.
- [UID:0001UJ] explains the element layout but does not own the storage destructor.
- [UID:000449] and [UID:00044A] are caller/destructor wrappers, not source owners for the storage cleanup body.

Source placement should remain under the `FolderTreePane.cpp` concrete template support area, alongside the `Tree`, `TreeStorage`, and `TreeItor` support docs. No new by-memory split or owner page is needed.

## Storage Member And Element Layout Resolution

The following names are source-facing recommendations for support-doc use:

| Binary evidence | Source-facing role | Recommended wording |
| --- | --- | --- |
| `this[0]` / `[edi]` | First element pointer | storage begin pointer. |
| `this[1]` / `[edi+4]` | One-past-last element pointer | storage end pointer. |
| `this[2]` / `[edi+8]` | One-past-capacity pointer | storage capacity/end pointer. |
| element stride `0x24` | `sizeof(FolderTreePane::TreeElem)` | 36-byte tree element. |
| element offset `+0x14` | string member | `TreeElem::name` / `SimpleUString` name field. |
| call `sub_582B70` | per-element cleanup | `name` destructor/release. |
| call `sub_5C7526` | storage allocation release | runtime free wrapper. |
| large block threshold `0x1000` and gap check `0x1f` | allocator validation | compiler/runtime lowering, not application logic. |

The support docs should avoid pretending that exact member identifiers are recovered. Use roles such as `begin`, `end`, and `capacity/end` or the existing `TreeStorage` storage-pointer terminology unless and until the class declaration is finalized.

## Rejected Alternatives

### Reject Full Formal Destructor Body For This Callback

A literal source body such as a loop over `m_begin` to `m_end`, manual `name.~SimpleUString()`, `_invalid_parameter_noinfo_noreturn()`, and `free()` would match the decompiled control flow but would be poor source reconstruction:

- It would encode MSVC allocator validation as handwritten application source.
- It would invent or prematurely freeze `TreeStorage` member names while [UID:0000FC] has no formal class declaration.
- It would duplicate sibling compiler-support responsibilities already kept as marker-only.
- It would make one method of the still-unresolved storage template appear more source-final than its class and insertion/copy helpers.

### Reject Clearing `EMITTER_UIDS`

Clearing `EMITTER_UIDS` would remove the target from the source-emission route but would discard the established `TreeStorage<FolderTreePane::TreeElem>` ownership. The function is not padding, data, or an unrelated runtime helper. It is source-relevant storage destruction lowered by the compiler.

### Reject `RECONSTRUCTABLE:FALSE`

The range is reconstructable as source semantics. The issue is not absence of source meaning; the issue is that the correct current source representation is a marker/covered-by disposition until the storage class declaration is emitted.

### Reject Moving Ownership To `FolderTreePane` Or `Tree`

The containing `FolderTreePane` and `Tree<FolderTreePane::TreeElem>` destructors call this storage cleanup, but they do not own the storage loop/free semantics. Direct ownership belongs to `TreeStorage<FolderTreePane::TreeElem>`.

### Reject A New Split

The range is a single, bounded function with padding before and after it. The successor at `0x004b5760` is separate and has its own xrefs. No split/merge repair is supported by current MCP evidence.

## First-Draft C++ / Exact No-Code Disposition

Recommendation: insert this exact nonblank formal `RECONSTRUCTION_CPP CODE` block into [UID:0002MX]:

```cpp
// Emitted source for TreeStorage<FolderTreePane::TreeElem> destruction is
// covered by the TreeStorage template/storage declaration tracked through
// [UID:0000FC]; this binary destructor body is compiler-lowered element cleanup
// and vector-storage release and emits no standalone handwritten body here.
```

This marker is intentionally source-routed, not non-emitting metadata. It resolves the empty-emitter state while preserving the correct evidence boundary:

- It names the owning source concept.
- It records that this binary body is element cleanup plus storage release.
- It prevents generated C++ from containing a misleading decompiler-shaped destructor body.
- It leaves the full `TreeStorage` class declaration and any future exact destructor spelling to the class/template route.

Do not put example/body-only C++ in a side note. If accepted, the formal `RECONSTRUCTION_CPP CODE` block should contain only the marker above.

## Metadata Recommendation

Recommended target metadata:

- `COMPLETION:88`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000FC`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000FC`
- `EMITTER_POSITION_OPTIONAL:` blank
- Inline `RECONSTRUCTION_CPP CODE:[[[]]]` blank
- Block `RECONSTRUCTION_CPP CODE`: exact marker from the previous section

Score rationale:

- Completion should move above `85` because the current live-MCP pass resolves the empty-emitter disposition, boundary, xrefs, caller roles, allocation/free roles, and stale "blank until 95/95" blocker.
- Confidence should move from `90` to `91` because the binary evidence and source route are strong and current.
- Do not raise higher yet because the exact original `TreeStorage` class declaration, storage member identifiers, header/file factoring, and `InsertAt` formal C++ are still unresolved.

### Current Score-Blocker Recheck

Current score/source-quality blockers and their disposition under `score-blocker-audit-standard.md`:

| Blocker / question | Current outcome |
| --- | --- |
| Empty emitter despite valid owner/emitter route | Converted into an implementation-ready target repair: keep [UID:0000FC] owner/emitter and insert the exact formal marker above. |
| Old "no C++ until 95/95" wording | Reject stale. Current by-structure code-entry policy uses `(COMPLETION + CONFIDENCE) / 2 > 85` plus a valid emitter route. [UID:0002MX] already averages `87.5`, and the accepted `88/91` remains safely eligible for formal marker output. |
| Full handwritten destructor body | Rejected with target-specific no-code proof. The decompiled body exposes compiler/runtime lowering, large-allocation validation, free wrapper calls, and inferred storage-member names; a source-looking handwritten destructor would overclaim source certainty and duplicate unresolved `TreeStorage` declaration work. |
| Owner/emitter route | Resolved unchanged. Current docs show [UID:0000FC] at `85/86` under [UID:0000JG] `FolderTreePane.cpp` at `89/85`; current MCP confirms the target is storage cleanup called from constructor/tree/pane destruction paths. |
| Exact storage member names and shared header factoring | Evidence-backed unresolved and score-limiting, not a deferred blocker. Current docs already use source-facing roles (`begin`, `end`, `capacity/end`) and current MCP `search_structs` still finds no recovered UDTs. This limits score above `88/91` and supports marker-only output, but does not block the accepted empty-emitter repair. |
| Related [UID:0002MV] `InsertAt` formal C++ | Not a blocker for UID0002MX implementation. It is already marker-only at `88/91` through the same storage route; this report should add a sibling note, not reopen `InsertAt` C++. |

No rare no-improvement exception is being claimed. The report has an implementation-ready improvement: target score movement, exact formal marker, support-doc incorporation, and generated-output refresh expectations.

## Implementation Scope Recommendation

Apply report-level detail to by-* docs only after supervisor validation. Do not edit generated reports, generated C++ files, project-level reports, manual coverage reports, tool state, or IDA DB.

### Required Target Edit

`by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md`

- Update metadata to `88/91`.
- Keep owner/emitter route exactly as recommended.
- Insert the exact formal marker into the `RECONSTRUCTION_CPP CODE` block.
- Replace stale old-gate/blank-C++ wording with the live-MCP no-code proof.
- Add the current xref table, caller-category reduction, boundary proof, storage-pointer roles, string/member evidence, allocation/free evidence, and rejected alternatives.
- State that the generated `Empty Emitter Marker` should disappear for [UID:0002MX] after regeneration, with the formal marker emitted instead.

### Material Support Docs To Update

Current support-doc recheck notes:

- `by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md` already contains the basic destructor behavior and five xrefs at same-or-greater detail, but it does not yet record [UID:0002MX] as marker-only/no-empty-emitter. Update required.
- `by-type/by-template/FolderTreePaneTreeTemplates.md` already lists [UID:0002MX] as 36-byte cleanup/storage free, but it does not yet record marker-only covered-by disposition. Update required.
- `by-type/by-struct/FolderTreePane__TreeElem.md` already records that the storage destructor destroys only the embedded string handle at `+0x14` before freeing storage. A new edit is optional; during implementation mark this claim already-present unless the supervisor wants a current B013-session note.
- `by-file/FolderTreePane.md`, `by-class/FolderTreePane.md`, the broad tree/sort helper inventory, and `InsertAt` still need narrow source-route/sibling sync notes so UID0002MX no longer reads as an unresolved empty emitter in support context.

### Support-Doc Stale Source / Wave Handling

Current scan scope for this narrow revision was the target plus planned material support docs. No by-* docs were edited. The UID0002MX recommendation relies on current live IDA MCP evidence, current by-* docs, current generated empty-emitter symptoms, and current by-structure rules. It does not rely on Wave3, `simroot_v2`, or recovered-source snapshots.

| Support doc | Current stale/source-lead wording found | Required callback disposition |
| --- | --- | --- |
| `by-file/FolderTreePane.md` | Active header lines still say `Current recovered source: source-3/simroot_v2/class_FolderTreePane.cpp`, `Evidence basis: Wave3 generated source`, and `Current active Wave3 ownership`. | Required edit. Historicalize or reframe those lines as historical generated-source leads only, not current evidence for UID0002MX, `FolderTreeStorage`, `FolderTreePane.cpp`, or the source-route recommendation. Preserve useful provenance only after making the current authority explicit: current by-* docs plus live MCP/current generated symptoms. |
| `by-class/FolderTreePane.md` | Active header lines still say `Current recovered file: source-3/simroot_v2/class_FolderTreePane.cpp` and `Current size: 0x17c (380) bytes in Wave3/Ghidra struct data`. | Required if the page is edited for UID0002MX. Historicalize as old generated-source/Ghidra lead material and avoid using it as current proof for storage-destructor ownership or source placement. Keep the valid class/template support facts and caller-source-owner note. |
| `by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md` | Active lines still say `Current Wave3 owners`, `Wave3 disables one as missing code and emits the other`, and `Wave3 records Tree_struct... at 0x004b5650`. | Required if the page is edited for UID0002MX. Reframe Wave3 as historical generated-owner/source-shape leads. Keep IDA-confirmed boundary/caller facts where current and valid, but do not present Wave3 as authority for UID0002MX or the broad child inventory. |
| `by-type/by-struct/FolderTreePane__TreeElem.md` | It contains `simroot_v2` generated-source check notes and says generated overlays disagree on several names. | No required edit for UID0002MX because the page already treats generated-source overlays as inconsistent lead material and already records the `+0x14` destruction fact. If the supervisor callback requests a current-session sync, reframe these notes explicitly as historical/generated leads and record already-present proof for the `+0x14` fact. |
| `by-type/by-template/FolderTreePaneTreeTemplates.md` | Generated filenames are mentioned as aliases only and explicitly rejected as standalone source-file evidence. | No stale-source edit required; record no-edit proof if checked during callback. |
| `by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md`, `by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md`, `by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md` | No active Wave2/Wave3/simroot/recovered-source authority wording found in the current scan. | No support-doc stale-source cleanup required beyond the accepted UID0002MX old-gate/source-route repair and sibling sync notes. |

`by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md`

- Record that [UID:0002MX] is now dispositioned as a nonblank source-routed marker under the `TreeStorage` route, not an empty emitter and not a handwritten destructor body.
- Add live-MCP details: three-pointer storage layout, 36-byte element stride, `name` cleanup at `+0x14`, runtime free wrapper, and large-allocation validation as compiler/runtime lowering.
- Preserve that exact storage member names remain source-facing/inferred, not IDA-recovered.

`by-type/by-template/FolderTreePaneTreeTemplates.md`

- Update the concrete method inventory for [UID:0002MX] to say it is a compiler-lowered `TreeStorage<FolderTreePane::TreeElem>` destructor/storage cleanup marker covered by the storage declaration route.
- Preserve concrete-template placement in `FolderTreePane.cpp`.

`by-type/by-struct/FolderTreePane__TreeElem.md`

- Already-present unless implementation finds contradictory stale text: current page records that [UID:0002MX] destroys only the embedded string handle at `+0x14` before freeing storage. Add only a narrow B013 current-session note if the supervisor callback asks for current-session support synchronization.
- Its `simroot_v2` generated-source notes already describe overlay disagreement. Do not edit this page only for stale-source cleanup unless the callback explicitly asks; if touched, make the lead-only/generated-source status explicit and record already-present proof for the `+0x14` fact.
- Do not use [UID:0002MX] to invent unrelated field names.

`by-file/FolderTreePane.md`

- Add a short source-quality note that [UID:0002MX] no longer should be treated as an empty emitter; it is a marker-only storage destructor route under `TreeStorage<FolderTreePane::TreeElem>`.
- Historicalize/reframe the active `Current recovered source`, `Evidence basis: Wave3 generated source`, and `Current active Wave3 ownership` wording as historical generated-source leads only. The page must not present Wave3, `simroot_v2`, or recovered source as current evidence for UID0002MX, `FolderTreeStorage`, or the [UID:0000FC] source-route recommendation.
- Keep the file-level source placement in `FolderTreePane.cpp`.

`by-class/FolderTreePane.md`

- Add a cross-note under the tree/template support discussion that the pane and tree scalar deleting destructors call [UID:0002MX], but source ownership remains with `TreeStorage<FolderTreePane::TreeElem>`.
- If editing the page for that cross-note, historicalize/reframe `Current recovered file: source-3/simroot_v2/class_FolderTreePane.cpp` and `Current size: 0x17c (380) bytes in Wave3/Ghidra struct data` as old generated-source/Ghidra lead material, not current proof for UID0002MX ownership or source placement.

`by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md`

- Update the child inventory/status for [UID:0002MX] from unresolved blank helper to source-routed marker-only destructor/storage cleanup.
- Historicalize/reframe active `Current Wave3 owners` and Wave3 comparison wording as generated-owner lead material only. Preserve IDA-confirmed current boundary/caller facts where valid, but do not cite Wave3 as the authority for UID0002MX or the child inventory.
- Preserve [UID:000157] as a non-emitting container/split index.

`by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md`

- Add a sibling note that [UID:0002MX] has been resolved as marker-only and that exact storage class/member formalization remains shared with [UID:0000FC] and this insertion method.
- Do not insert `InsertAt` C++ as part of this target callback.

### Check-Only / Edit Only If Contradictory

The following pages already align with the recommended disposition unless they contain stale contradictory text during implementation:

- `by-memory/0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup.md`
- `by-memory/0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor.md`
- `by-memory/0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor.md`
- `by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md`
- `by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md`
- `by-class/Tree_struct_FolderTreePane__TreeElem_.md`
- `by-type/by-struct/FolderTreePane__TreeElem.md` for the narrow `+0x14` / 36-byte cleanup fact, unless current-session support synchronization is requested.

For these pages, record no-edit proof in the implementation checklist if they do not contradict the accepted disposition.

## Validator Expectations For Implementation Callback

After supervisor acceptance and by-* edits, run scoped validators for every changed by-* file. Include `--wait-generated` on the target and any file whose generated output matters.

Expected target generated-output check:

- `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` should no longer contain an `Empty Emitter Marker` for `UID0002MX`.
- It may still contain other unrelated empty markers, including any unresolved marker for [UID:0000FC], unless those are separately accepted for implementation.
- The generated target content should include the exact formal marker text for [UID:0002MX], not a decompiler-shaped destructor body.

Do not run `execute_report`; supervisor owns report execution after verification.

## Claim And Incorporation Ledger

Callback verification state values are `applied`, `already-present`, `excluded-with-reason`, or `blocked`. No row remains pending.

| Claim / accepted fact to preserve | Action | Destination | Verification state | Implementation note / proof source |
| --- | --- | --- | --- | --- |
| [UID:0002MX] moves to `COMPLETION:88`, `CONFIDENCE:91`, while keeping `CANONICAL_OWNER:0000FC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FC`, and blank `EMITTER_POSITION_OPTIONAL`. | incorporate | Target metadata in `by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md`. | applied | Target header now has `88/91`, owner/emitter unchanged, reconstructable true, and blank emitter position. Validator command `000000000273` at `2026-06-29T01:46:02-04:00` exited `0`, `ok: 1`. |
| Inline `RECONSTRUCTION_CPP CODE:[[[]]]` remains blank and the multiline formal block contains only the marker-only no-code proof. | incorporate | Target formal C++ block and generated `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp`. | applied | Target code block contains the accepted marker text; validator canonicalized `[UID:0000FC]` to the project UID-link form. Generated `FolderTreePane.cpp` lines 133-137 emit UID0002MX as the marker, and `UID0002MX.*Empty Emitter Marker` is not found. |
| Current MCP active session `07c55da0` reconfirms the same IDB and healthy analysis state. | incorporate | Target IDA Evidence and support notes. | applied | Target IDA Evidence records session `07c55da0`, `server_health` OK for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, imagebase `0x400000`, Hex-Rays ready, and strings cache ready. |
| Exact target range remains `0x004b56e0-0x004b575f`, `sub_4B56E0`, size `0x7f`; `0x004b575f` is not a function and successor `0x004b5760` is separate. | incorporate | Target IDA Evidence and broad inventory support row. | applied | Target evidence and support docs record the range, size, non-function end address, and separate successor; broad helper inventory now carries the same UID0002MX child row. |
| The body walks 36-byte records and destroys the embedded string/name field at offset `+0x14`. | incorporate | Target behavior, `TreeStorage` class support, template support, file/class support. | applied | Target summary/evidence, `by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md`, `by-type/by-template/FolderTreePaneTreeTemplates.md`, `by-file/FolderTreePane.md`, and the broad helper page now record 36-byte records and `+0x14` name destruction. |
| The storage object is a three-pointer span; the destructor frees storage and zeros begin/end/capacity. | incorporate | Target behavior/storage role and `TreeStorage` support doc. | applied | Target IDA Evidence and `TreeStorage` class row record vector storage validation/free and zeroing of begin/end/capacity. |
| Large-allocation validation and `sub_5C7526` are compiler/runtime lowering, not source-facing handwritten application logic. | incorporate | Target no-code proof and support docs. | applied | Target no-code proof rejects full-body C++; storage/template/file support notes classify the free-validation path as compiler-lowered storage support. |
| Current xrefs reduce to constructor/EH cleanup, `Tree<FolderTreePane::TreeElem>` destruction, and outer `FolderTreePane` destruction categories. | incorporate | Target xref/caller section, `by-class/FolderTreePane.md`, broad helper inventory. | applied | Target evidence and class/file/broad support docs record xrefs `0x004b1d28`, `0x004b565c`, `0x004b59ff`, `0x004b5aab`, and `0x005fe936` as ownership consumers rather than ownership moves. |
| Current callees are `sub_582B70`, `sub_5C7526`, and `__invalid_parameter_noinfo_noreturn`. | incorporate | Target callee evidence and storage support docs. | applied | Target evidence and `TreeStorage` class note record the same callee set and its element-cleanup/storage-release meaning. |
| Current IDB still lacks recovered source UDTs for `TreeStorage`, `TreeElem`, and `FolderTreePane`. | incorporate | Target negative evidence and score rationale. | applied | Target IDA Evidence records `search_structs` returning no recovered source UDTs; score rationale keeps full-body source below final-source quality. |
| Owner/source route remains [UID:0000FC] through [UID:0000JG]; do not move to [UID:0000JG] directly, [UID:0001WP], [UID:0001UJ], `FolderTreePane`, or `Tree`. | incorporate | Target ownership/source-placement, storage class, template, file, and class support docs. | applied | Target owner/emitter remain [UID:0000FC]; support pages now say constructor/tree/pane destructor callsites are consumers and the source route is the concrete `TreeStorage<FolderTreePane::TreeElem>` declaration route. |
| Reject full formal destructor body, clearing `EMITTER_UIDS`, `RECONSTRUCTABLE:FALSE`, moving owner, and a new split. | incorporate | Target rejected alternatives and support notes. | applied | Target rejected alternatives now cover full body, blank block, non-emitting, alternate owners, raw helper classification, and split/merge; support pages use marker-only wording. |
| The old "no final C++ until 95/95" blocker is stale under current by-structure rules. | reject-stale | Target reconstruction notes and changes. | applied | Target changed from blank empty-emitter output to `88/91` marker-only output and records the old `95/95` gate as stale. |
| Old sibling helper UID wording is stale: RangeDestroy is [UID:000447] and VectorStorageFree is [UID:00044B]. | reject-stale | Report evidence and implementation support wording. | already-present | Edited support docs already use [UID:000447] for RangeDestroy and [UID:00044B] for VectorStorageFree; the stale `[UID:00044B] RangeDestroy` / `[UID:00044C] VectorStorageFree` mapping was not present in edited destination text. |
| `source-3\simroot_v2` and Wave/recovered-source material are historical source leads, not current authority. | reject-stale | Report and edited support pages with active stale wording. | applied | `by-file/FolderTreePane.md`, `by-class/FolderTreePane.md`, and `by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md` now frame simroot/Wave/recovered-source wording as historical generated leads only. |
| `by-file/FolderTreePane.md` active recovered-source, Wave3 evidence basis, and active Wave3 ownership wording must be historicalized. | historicalize | `by-file/FolderTreePane.md`. | applied | File page now starts with `Historical generated-source lead`, uses current by-* plus MCP evidence as authority, and records a 2026-06-29 B013 change entry for UID0002MX. Validator command `000000000276` at `2026-06-29T01:46:16-04:00` exited `0`, `ok: 1`. |
| `by-class/FolderTreePane.md` active recovered-file and Wave3/Ghidra-size wording must be historicalized. | historicalize | `by-class/FolderTreePane.md`. | applied | Class page now frames the recovered file and generated-size text as historical leads, adds the UID0002MX caller/source-owner cross-note, and records a B013 change entry. Validator command `000000000277` at `2026-06-29T01:46:22-04:00` exited `0`, `ok: 1`. |
| `by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md` active Wave3 owner/comparison lines must be historicalized. | historicalize | Broad tree/sort helper inventory. | applied | Broad page now uses `Historical Wave3 owner leads`, reframes Wave3 comparison text as generated-lead material, and updates the UID0002MX child row to marker-only source-routed support. Validator command `000000000278` at `2026-06-29T01:46:28-04:00` exited `0`, `ok: 1`. |
| `by-type/by-struct/FolderTreePane__TreeElem.md` already records the `+0x14` / 36-byte cleanup fact and treats generated-source overlays as inconsistent leads. | check-only | `by-type/by-struct/FolderTreePane__TreeElem.md`. | already-present | No edit was made; the required storage-destructor `+0x14` and generated-source caution were already present at same-or-greater detail. |
| `by-type/by-template/FolderTreePaneTreeTemplates.md` already says generated class filenames are aliases only, and it needs the accepted UID0002MX inventory row. | incorporate | Template support page. | applied | Template page now records UID0002MX as marker-only source-routed destructor/storage cleanup through [UID:0000FC] and [UID:0000JG]; existing alias/source-route cautions remain. Validator command `000000000275` at `2026-06-29T01:46:14-04:00` exited `0`, `ok: 1`. |
| Check-only pages [UID:000158], [UID:00034I], [UID:00034J], [UID:000447], [UID:00044B], and [UID:0000F9] should remain untouched unless contradictory stale text exists. | check-only | Listed check-only support pages. | already-present | `rg` spot-checks found no contradiction: cleanup/scalar destructor pages call or consume UID0002MX without claiming ownership, range/free helpers are marker-only through [UID:0000FC], and `Tree_struct` remains compatible with the storage route. No edits made. |
| Generated coverage/research tracker state and generated C++ must be refreshed by validators, not manual edits. | validator-owned | Generated state and `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp`. | applied | Scoped validators were run with `--apply`; target validator `000000000273` used `--wait-generated` and reported `generated_refresh: completed`. Final generated `FolderTreePane.cpp` header shows command `000000000279`, refreshed `2026-06-29T01:46:33-04:00`, with UID0002MX marker lines 133-137 and no UID0002MX empty marker. |

## Implementation Tracking Checklist

- [x] Leased only the accepted by-* target/support files immediately before editing: target, `TreeStorage` class, template support, `by-file/FolderTreePane.md`, `by-class/FolderTreePane.md`, broad tree/sort inventory, and `FolderTreeStorageInsertAt`. Lease command reported `Success` for all seven paths at `2026-06-29T05:41:03Z`.
- [x] Updated [UID:0002MX] target metadata in `by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md` to `COMPLETION:88`, `CONFIDENCE:91`, preserving `CANONICAL_OWNER:0000FC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FC`, and blank `EMITTER_POSITION_OPTIONAL`.
- [x] Inserted the accepted formal multiline marker into [UID:0002MX], leaving inline `RECONSTRUCTION_CPP CODE:[[[]]]` blank. Validator link normalization converted raw `[UID:0000FC]` in the marker comment to the canonical UID markdown link.
- [x] Replaced stale old-gate/blank-C++ wording in [UID:0002MX] with current no-code proof: marker-only source-routed storage destructor, not full handwritten/decompiler-shaped C++ and not non-emitting.
- [x] Added current 2026-06-29 MCP spot-check evidence to [UID:0002MX]: active session `07c55da0`, server health OK, exact range/boundary, xrefs, callee set, disasm/decompile role proof, `search_structs` negative UDT checks, and score-blocker outcome.
- [x] Preserved target rejected alternatives in [UID:0002MX]: full destructor body, clearing `EMITTER_UIDS`, `RECONSTRUCTABLE:FALSE`, moving ownership to `FolderTreePane`/`Tree`/template/element docs, raw runtime-helper classification, and split/merge.
- [x] Updated `by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md` with the UID0002MX marker-only destructor/storage cleanup disposition and current storage evidence; storage member names/header factoring remain inferred. Validator `000000000274`, timestamp `2026-06-29T01:46:12-04:00`, exit `0`, `ok: 1`.
- [x] Updated `by-type/by-template/FolderTreePaneTreeTemplates.md` so the [UID:0002MX] concrete method inventory says marker-only `TreeStorage<FolderTreePane::TreeElem>` destructor/storage cleanup covered by the storage declaration route. Validator `000000000275`, timestamp `2026-06-29T01:46:14-04:00`, exit `0`, `ok: 1`.
- [x] Treated `by-type/by-struct/FolderTreePane__TreeElem.md` as already-present for the `+0x14` name destruction / 36-byte cleanup fact; no edit made. Existing page already treats generated-source overlays as inconsistent lead material.
- [x] Updated `by-file/FolderTreePane.md` with source-quality support that [UID:0002MX] is no longer an empty emitter and is marker-only under the [UID:0000FC] storage route in `FolderTreePane.cpp`; historicalized the active recovered-source, Wave3 evidence-basis, and active Wave3 ownership wording. Validator `000000000276`, timestamp `2026-06-29T01:46:16-04:00`, exit `0`, `ok: 1`.
- [x] Updated `by-class/FolderTreePane.md` with the caller/source-owner cross-note: constructor/tree/pane destructor paths call [UID:0002MX], but source ownership remains [UID:0000FC]; historicalized active recovered-file and Wave3/Ghidra-size wording. Validator `000000000277`, timestamp `2026-06-29T01:46:22-04:00`, exit `0`, `ok: 1`.
- [x] Updated `by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md` child inventory/status for [UID:0002MX] to source-routed marker-only destructor/storage cleanup; historicalized active Wave3 owner/comparison lines as generated-source leads only; [UID:000157] remains non-emitting. Validator `000000000278`, timestamp `2026-06-29T01:46:28-04:00`, exit `0`, `ok: 1`.
- [x] Updated `by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md` with a sibling note that [UID:0002MX] is marker-only through the same [UID:0000FC] storage route; did not reopen or insert `InsertAt` C++. Validator `000000000279`, timestamp `2026-06-29T01:46:33-04:00`, exit `0`, `ok: 1`.
- [x] Checked no-edit pages and found them consistent: `by-memory/0x004b5650-0x004b5668.FolderTreePaneTreeDestructorCleanup.md`, `by-memory/0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor.md`, `by-memory/0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor.md`, `by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md`, `by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md`, and `by-class/Tree_struct_FolderTreePane__TreeElem_.md`.
- [x] Historicalized/rejected stale support wording: old `95/95` code-entry blocker, absent `simroot_v2` authority, `by-file/FolderTreePane.md` active recovered-source/Wave3 lines, `by-class/FolderTreePane.md` recovered-file/Wave3-size lines, and broad tree/sort active Wave3-owner/comparison lines. Edited support text already used current [UID:000447] RangeDestroy and [UID:00044B] VectorStorageFree mapping.
- [x] Ran scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed by-* file. Commands used `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240`, with `--wait-generated` on target. Results: `000000000273` target at `2026-06-29T01:46:02-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`; `000000000274` through `000000000279` for support docs, all exit `0`, `ok: 1`.
- [x] Verified generated freshness read-only. `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` header shows validator command `000000000279`, refreshed `2026-06-29T01:46:33-04:00`; lines 133-137 emit the UID0002MX formal marker and `UID0002MX.*Empty Emitter Marker` is not found.
- [x] Confirmed generated reports/state were only validator-updated. No manual edits were made to generated reports, generated C++, manual `-coverage-report.md`, project-level generated files, validator/tool state, lock files, executed reports, or IDA DB.
- [x] Released/verified leases after the edit/validator batch. The explicit `unlease` call reported `Rejected[No active lease]` for all seven paths because the short leases had already expired during the validator batch; `tools/leaser/Agents/current_leases.md` is empty and shows no active B013 leases.
- [x] Did not run `execute_report`; supervisor owns report execution after verification.

## Final Report Disposition

Implementation callback complete for supervisor verification. The target retains its source owner/emitter route and now emits a marker-only formal disposition rather than a full handwritten destructor body. The marker resolves the empty-emitter state while preserving the accurate source model: [UID:0002MX] is the compiler-lowered destruction and storage-release body for `TreeStorage<FolderTreePane::TreeElem>`, with exact class/member formalization still owned by the surrounding `TreeStorage`/template support route.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/0002MX-FolderTreeStorageDestructor-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/0002MX-FolderTreeStorageDestructor-empty-emitter-source-quality.md","timestamp":"2026-06-29T01:54:33","uid":"0002MX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
