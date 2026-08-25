** TARGET-REPORT-UID:00023P **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Final Recommendation

Keep [UID:00023P] `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md` exactly as a reconstructable no-owner, non-emitting memory item:

- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:` blank
- `EMITTER_POSITION_OPTIONAL:` blank
- `RECONSTRUCTION_CPP CODE:` blank
- Keep current target score `COMPLETION:88`, `CONFIDENCE:92`.

No canonical owner, emitter route, split, merge, reclassification, child page, IDA repair, or by-memory coverage-row change is justified by the current evidence. This is a real reconstructable custom helper island, but no caller, pointer/table entry, source-use context, declaration owner, or adjacent source owner link is proven. Under the current `by-structure.md` rules, `RECONSTRUCTABLE:TRUE` with `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS` remains correct when the binary proves custom code exists but the owner/emitter route does not clear the assignment gate.

Best-if-forced hypothesis: a narrow utility source grouping such as `util/WordRefCountHelpers` or `IntrusiveWordRefCount`. That grouping should not be created or used as an emitter yet because the current pass still found no caller, xref, source name, table, type, object-file, or related-item evidence tying the island to an actual source file.

---

## Target

- Target UID: `00023P`
- Target page: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00554640-0x00554675.WordRefCountHelpers.md`
- Coverage source checked: `E:\NTK\GhidraBridge\source-3\project-documentation\auto-generated\-ag-memory-coverage.md`
- Shared coverage row checked but not edited: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md`
- Prior report used only as evidence: `Agent-B002/research/executed/00023P-WordRefCountHelpers-live-goal2-no-owner-pass.md`

## Current Documentation Evidence

The current target page already models a compact three-helper island:

- `0x00554640-0x0055464b`: modeled `sub_554640`, initializes `word [this]` to `1`, returns `this`.
- `0x0055464b-0x00554650`: five `0xcc` alignment bytes.
- `0x00554650-0x00554654`: raw `inc word ptr [ecx]; retn`.
- `0x00554654-0x00554660`: twelve `0xcc` alignment bytes.
- `0x00554660-0x00554675`: raw release helper, decrements `word [ecx]`, and frees `ecx` through `sub_5C7526` when the signed count is no longer positive.
- `0x00554675-0x00554680`: trailing `0xcc` alignment before the next modeled function.

The adjacent documentation does not supply an owner:

- Previous aggregate [UID:0001FT] `0x00553c10-0x00554635.ConnectionClosedReconnectDialogs` ends at `0x00554635`, before eleven `0xcc` bytes leading into this island.
- Following aggregate [UID:0001FW] `0x00554680-0x00554b38.RegionAndMotionRect` starts at `0x00554680`, after trailing `0xcc` padding, and carries Region/Motion rectangle evidence rather than word-refcount evidence.
- The current shared coverage row for `00023P` already states no owner/emitter route is proven, so no replacement row is needed.

## Current IDA MCP Evidence

Fresh live IDA MCP evidence was collected against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64` / input `NexusTK.exe`; `server_health` reported `auto_analysis_ready:true`, `hexrays_ready:true`, image base `0x400000`.

Function boundaries:

- `lookup_funcs 0x00554640`: `sub_554640`, size `0x0b`.
- `lookup_funcs 0x00554650`: not a function.
- `lookup_funcs 0x00554660`: not a function.
- `lookup_funcs 0x00554675`: not a function.
- `lookup_funcs 0x00554680`: next modeled function `sub_554680`, size `0x61`.
- `lookup_funcs 0x005c7526`: `sub_5C7526`, size `0x0e`.

Bytes:

- `0x00554635-0x00554640`: eleven `0xcc` bytes.
- `0x00554640-0x00554675`: `b8 01 00 00 00 66 89 01 8b c1 c3 cc cc cc cc cc 66 ff 01 c3 cc cc cc cc cc cc cc cc cc cc cc cc 66 ff 09 66 83 39 00 7f 0b 6a 02 51 e8 b5 2e 07 00 83 c4 08 c3`.
- `0x00554675-0x00554680`: eleven `0xcc` bytes.

Decompilation/disassembly:

- `analyze_function 0x00554640` reports prototype `_WORD *__thiscall(_WORD *this)` and decompiles to `*this = 1; return this;`.
- `disasm 0x00554660` decodes `dec word ptr [ecx]`, `cmp word ptr [ecx], 0`, `jg 0x00554674`, `push 2`, `push ecx`, `call sub_5C7526`, `add esp, 8`, `retn`.
- `decompile 0x005c7526` reports `void __cdecl sub_5C7526(void *Block) { j_j___free_base(Block); }`.

Reference evidence:

- `xrefs_to` reports zero xrefs to `0x00554640`, `0x00554650`, and `0x00554660`.
- `analyze_function 0x00554640` reports no callers and no callees.
- `find_xref_signatures` reports zero total xrefs for `0x00554640`, `0x00554650`, and `0x00554660`.
- `make_signature` produced unique helper-start signatures: `B8 01 00 00 00 66 89 01` for `0x00554640`, `66 FF 01` for `0x00554650`, and `66 FF 09 66 83 39 00` for `0x00554660`.

The only semantic outgoing edge inside the island is the release helper call to the free wrapper at `0x0055466c -> 0x005c7526`. That proves lifetime/free behavior, not source ownership.

## Independent PE Evidence

A fresh read-only PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` confirmed:

- Image base: `0x00400000`.
- `.text`: RVA `0x1000`, raw pointer `0x400`, executable.
- Target raw offsets: `0x00554640 -> 0x153a40`, `0x00554650 -> 0x153a50`, `0x00554660 -> 0x153a60`.

Exact pattern uniqueness:

- Initializer `b8 01 00 00 00 66 89 01 8b c1 c3`: one hit at `0x00554640`.
- Increment helper `66 ff 01 c3`: one hit at `0x00554650`.
- Release helper `66 ff 09 66 83 39 00 7f 0b 6a 02 51 e8 b5 2e 07 00 83 c4 08 c3`: one hit at `0x00554660`.
- Release tail `6a 02 51 e8 b5 2e 07 00 83 c4 08 c3`: one hit at `0x00554669`.

Pointer and branch scans:

- No absolute-VA dword hits for `0x00554640`, `0x00554650`, or `0x00554660`.
- No RVA dword hits for `0x00154640`, `0x00154650`, or `0x00154660`.
- No `E8/E9`, `0F 8x`, short conditional, short jump, or loop-style relative branch targets to the three helper starts in `.text`.

Free-wrapper negative control:

- Calls to `sub_5C7526` with a preceding `push 2` were found at call sites `0x004564bb`, `0x004574bb`, and `0x0055466c`.
- The two non-target sites are the already documented MiniMapVersionManager cleanup/destructor-style cases; they show that the `push 2` free-wrapper form is an allocator/deleting-destructor idiom, not an owner signal for this target.

## Ownership And Emitter Analysis

### 1. Keep `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`

Evidence for:

- The island is custom source code and reconstructable: three tiny, coherent word-refcount/lifetime helpers with exact code bytes and padding.
- No owner xref, caller, pointer-table reference, vtable relation, string/type/name metadata, or source-use context exists for any helper start.
- The current system distinguishes semantic ownership from output routing. A reconstructable item can stay no-owner/non-emitting while the owner and emitter route remain unknown.
- This is not a pooled literal/shared-constant case: there are no proven consumer source-use contexts, so adding multiple emitters would be weaker than leaving it non-emitting.

Evidence against:

- The behavior strongly suggests an original reusable helper or tiny intrusive-refcount type, so there is likely some original source grouping. The binary does not currently identify it.

Conclusion: accepted. This is the only current route that does not invent ownership or output placement.

### 2. New narrow `util/WordRefCountHelpers` or `IntrusiveWordRefCount`

Evidence for:

- The three routines form a self-contained source-like mini-family: construct/init count to `1`, add-reference, release/free.
- The source grouping would be more plausible than assigning the island to neighboring UI/network/region code.

Evidence against:

- No caller or table points to the helpers.
- No nearby named source module, string, PDB-style artifact, class layout, or related item establishes this as a real project source root.
- Creating a standalone emitter only to avoid `NONE` is explicitly disallowed by the current ownership rules.

Conclusion: best-if-forced inference only. Do not create or assign yet.

### 3. ReconnectDialog / CopyWindow adjacency

Evidence for:

- These are the closest previous documented code ranges.

Evidence against:

- The previous aggregate ends at `0x00554635`; this island starts after `0x00554635-0x00554640` padding.
- The current exact child pages under the reconnect/copy area carry their own ownership and do not extend into this island.
- No xref links the helpers back to reconnect or copy-window code.

Conclusion: rejected.

### 4. Region / Motion adjacency

Evidence for:

- The next modeled function starts nearby at `0x00554680`.

Evidence against:

- There is clean `0x00554675-0x00554680` padding before the next function.
- The following aggregate has its own Region/Motion rectangle evidence and ordinary refs to `0x00554680`; this helper island has no incoming refs.
- Word intrusive refcount helpers do not match Region/Motion rectangle helper behavior.

Conclusion: rejected.

### 5. StringBase / StringUtil

Evidence for:

- The target is reference-count-like and touches word-sized counters, which superficially resembles string/shared-buffer lifetime management.

Evidence against:

- Current StringBase documentation describes a separate string implementation pattern with header-based string state, not a two-byte counter at object head followed by `free(this)`.
- No StringBase/StringUtil function, table, or caller references this island.

Conclusion: rejected.

### 6. LinkedList / PoolAllocator / LObject / MiniMapVersionManager / CRT

Evidence for:

- Pool/free and reference/lifetime concepts are nearby generic candidates.
- MiniMapVersionManager provides the other observed `push 2` free-wrapper negative-control sites.

Evidence against:

- LinkedList and PoolAllocator have their own documented allocator/list-node implementations and do not reference this island.
- LObject is a base/runtime shell pattern, not a raw two-byte intrusive refcount helper.
- MiniMapVersionManager only shares a free-wrapper idiom; it has no reference to the helper starts.
- CRT/free wrapper ownership would be wrong because the target helpers are custom code that call a CRT-adjacent wrapper, not CRT code themselves.

Conclusion: rejected.

## Split, Reclassification, And IDA Repair Review

No split is recommended. The range is already exact and coherent: initializer, increment helper, release helper, and only their internal/surrounding padding. Splitting the raw increment and release stubs into separate child pages would not reveal an owner or route; it would create three no-owner fragments where one source-family page is clearer.

No reclassification is recommended. The item should remain `RECONSTRUCTABLE:TRUE` because it is custom game code that would need to be recreated once a source route is known. It should not become `RECONSTRUCTABLE:FALSE` because the page is not merely padding, runtime, or an audit-only container.

No IDA repair is required for this report. IDA models only the initializer as a function, while the increment and release helpers decode cleanly as raw function-shaped bytes. Creating IDA function objects for those two stubs would not change the absence of xrefs, pointers, callers, owner evidence, or emitter evidence.

## Exact Recommended Changes

No documentation or coverage edits are recommended.

- Target page: no change.
- `by-memory/-coverage-report.md`: no change; do not replace the row.
- `auto-generated/-ag-memory-coverage.md`: read-only generated input; no direct edit.
- New child pages: none.
- New by-file/by-global/by-type owner: none.
- Reconstruction C++: none, because the item has no confirmed nonblank emitter route.

## Validation And Execution Notes

- Used current `goal.md`, `Supervisor.md`, `by-structure.md`, tracker context, target page, generated coverage, shared coverage row, adjacent memory docs, and candidate owner docs as current documentation evidence.
- Used live IDA MCP evidence for function lookup, bytes, xrefs, disassembly, decompilation, unique signatures, and xref-signature checks.
- Used an independent read-only PE scan for byte-pattern uniqueness, pointer scans, and relative-branch scans.
- No dry runs were used.
- No validator run was needed because no by-* documentation or generated/project state was modified.
- No lease was needed because the only file created is inside the Agent-B002 research folder.

## Confidence

Recommendation confidence: high, `93`.

The evidence is strong for "real reconstructable helper island" and strong for "no proven owner/emitter route." The remaining uncertainty is original source intent: a narrow utility source grouping probably existed, but current binary evidence still does not identify it well enough to assign ownership or route generated output.

## Changed Files

- Created `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\00023P-WordRefCountHelpers-goal2-verification.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00023P-WordRefCountHelpers-goal2-verification.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00023P"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
