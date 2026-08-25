** TARGET-REPORT-UID:00023P **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00023P WordRefCountHelpers Post-Migration Owner / Emitter Recheck

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00023P][0x00554640-0x00554675.WordRefCountHelpers](../../../../../by-memory/0x00554640-0x00554675.WordRefCountHelpers.md) as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank reconstruction C++.
- Final disposition: source-authored/rebuild-relevant tiny 16-bit intrusive refcount helper island, but with no proven source-use context, no direct owner, and no valid emitter route under the current `CANONICAL_OWNER` / `EMITTER_UIDS` model.
- Required action: no target metadata change, no split, no reclassification to `RECONSTRUCTABLE:FALSE`, and no `by-memory/-coverage-report.md` edit required.
- Confidence: high for range/bytes/behavior/no-reference facts; medium-high for rejecting existing owners/emitters; medium for the best-if-forced future `util/WordRefCountHelpers` source-family hypothesis, which remains below assignment threshold.

## Supporting Research

## Target

- Target UID: `00023P`
- Target path: `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md`
- Source queue/report row: `auto-generated/-ag-memory-coverage.md` no-owner/non-emitting memory row.
- Tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md` row `00023P`, assigned to B003 as `B003-00023P-post-migration`.
- Previous historical report: `tools/leaser/Agents/Agent-B001/research/executed/00023P-WordRefCountHelpers-B001-00023P.md`.
- Current scores and parent state: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank reconstruction C++.

## Executive Recommendation

Keep the current no-owner/non-emitting metadata. This target is real executable project logic and should stay `RECONSTRUCTABLE:TRUE`, but no current evidence proves a direct semantic owner or a source-use context that can receive emitted code.

This is not an invalid dead-end state under the current model. `by-structure.md` explicitly allows confirmed NexusTK source items to be `RECONSTRUCTABLE:TRUE` while the owner, emitter route, source-file owner, or final C++ are not ready. The generated report tracks this as `no-owner` and `non-emits`, and the current `auto-generated/-ag-memory-coverage.md` summary still has `Total_DeadEnds: 0`. It would become invalid if the page had emitted C++ with no route to a `by-file` source root, or if an emitter were invented without evidence. It should eventually emit only after a real owner/source-use context is found or after an explicit project-level decision creates a narrow utility owner for no-xref retained helper islands.

The item should not become `RECONSTRUCTABLE:FALSE`. It is not padding, a mixed physical container, a compiler audit map, or a standard CRT helper. It contains a coherent init/addref/release/free helper family with source-level lifetime semantics; only its final `free` dependency is runtime-like.

## Supervisor Active Recheck

The supervisor assigned a post-migration recheck because the executed B001 report predated or used old `AUTOGEN_PARENT_UID` language. This B003 pass reinterprets that result under the current model:

- old `AUTOGEN_PARENT_UID` blank maps to `CANONICAL_OWNER:NONE` for ownership;
- generated output routing is now controlled only by `EMITTER_UIDS`;
- blank emitters are valid for an unresolved reconstructable item only while no emitted code/source-use route is proven;
- `CANONICAL_OWNER:NONE` plus nonblank emitters is valid for pooled/shared data when source-use contexts are proven, but this target has no such source-use evidence.

No split repair is required. The three helper bodies form a single cohesive lifetime-helper island, and splitting initializer/addref/release into separate pages would create three copies of the same unresolved owner/emitter problem without adding evidence.

## Inference Research Guidance Check

`by-structure.md` requires the canonical owner to be the narrowest true semantic owner that evidence supports, not the nearest address neighbor or a convenient output file. It also states that `EMITTER_UIDS` is output routing, not ownership, and that emitters must eventually route to a singular by-file source root.

`inference_research.md` treats direct machine-code facts, xrefs, callers, table references, and metadata as stronger than address adjacency. It also warns that source-file ownership cannot be proven from adjacency alone when no debug/map/source metadata exists.

Applied to `00023P`:

- IDA fact: bytes, boundaries, behavior, uniqueness, and no-reference state are strong.
- Documentation evidence: adjacent and thematic owners have incompatible boundaries, layouts, or ownership maps.
- Inference: a narrow `NexusTK/util/WordRefCountHelpers.cpp` or `IntrusiveWordRefCount` owner is the best source-family guess if forced, but it is not strong enough to create an owner or fill emitters.

## Evidence Standards Used

- Live IDA MCP `server_health`, `lookup_funcs`, `xrefs_to`, `disasm`, `decompile`, `analyze_function`, `get_bytes`, `find_xref_signatures`, `make_signature`, `make_signature_for_range`, `find_bytes`, `entity_query`, and `find_regex`.
- Independent PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for exact bytes, duplicate patterns, VA/RVA pointer bytes, and relative branch/call targets.
- Existing documentation for nearby memory ranges, `StringBase`, `StringUtil`, `RefCountedStringBufferHeader`, `LinkedList`, `PoolAllocator`, `LObject`, `MiniMapVersionManager`, and proposed source-tree placement.
- Negative evidence for callers, data refs, raw pointers, branch targets, vtable/table entries, source/debug strings, local names, and source-use contexts.

## IDA MCP Facts

Current IDA session facts:

- MCP database used: `b001_0003gy`
- Module: `NexusTK.exe`
- IDB path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Input path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Image base: `0x00400000`
- Hex-Rays and string cache: ready
- Binary MD5 from `Get-FileHash`: `4247E04E20B65D6414C7238AA8FF5515`

Function/range facts:

| Address | IDA status |
| --- | --- |
| `0x00554635` | not a function; alignment after prior reconnect cleanup/destructor span |
| `0x00554640` | function `sub_554640`, size `0x0b` |
| `0x0055464b` | not a function; internal padding |
| `0x00554650` | not a function; raw addref helper |
| `0x00554654` | not a function; internal padding |
| `0x00554660` | not a function; raw release/free helper |
| `0x00554675` | not a function; trailing padding begins |
| `0x00554680` | function `sub_554680`, size `0x61`; following Region constructor island |
| `0x005c7526` | function `sub_5C7526`, size `0x0e`; CRT free wrapper |

IDA decompiles `0x00554640` as:

```cpp
_WORD *__thiscall sub_554640(_WORD *this)
{
  *this = 1;
  return this;
}
```

IDA decompiles `0x005c7526` as:

```cpp
void __cdecl sub_5C7526(void *Block)
{
  j_j___free_base(Block);
}
```

Raw disassembly:

```asm
00554640  mov     eax, 1
00554645  mov     [ecx], ax
00554648  mov     eax, ecx
0055464a  retn
0055464b  cc cc cc cc cc
00554650  inc     word ptr [ecx]
00554653  retn
00554654  cc cc cc cc cc cc cc cc cc cc cc cc
00554660  dec     word ptr [ecx]
00554663  cmp     word ptr [ecx], 0
00554667  jg      short 0x00554674
00554669  push    2
0055466b  push    ecx
0055466c  call    sub_5C7526
00554671  add     esp, 8
00554674  retn
```

Xref facts:

- `xrefs_to 0x00554640`: zero.
- `xrefs_to 0x00554650`: zero.
- `xrefs_to 0x00554660`: zero.
- `find_xref_signatures` for all three helper starts: total xrefs `0`.
- `analyze_function 0x00554640`: no callers, no callees, no strings, one basic block.
- `xrefs_to 0x00554680`: many code refs, proving the following Region constructor island is live while this target is not referenced.
- `xrefs_to 0x005c7526`: broad direct-use free-wrapper refs; dependency only, not ownership.
- Fallthrough is not a viable reachability explanation: the preceding reconnect cleanup child ends at `0x00554635` after a final `retn 4` byte and eleven `0xcc` bytes precede this target; the target then ends at `0x00554675` with eleven more `0xcc` bytes before the live `0x00554680` Region constructor.
- Vtable/table adjacency does not route the target: reconnect vtable refs land inside the preceding cleanup/destructor child, and Region vtable/constructor evidence begins at the following `0x00554680` island; no vtable slot, callback table, or raw pointer entry targets any of the three helper starts.

Byte/signature facts:

- `get_bytes 0x00554635 size 85` confirms eleven leading `0xcc` bytes, initializer bytes, five `0xcc` bytes, raw increment bytes, twelve `0xcc` bytes, release bytes, eleven trailing `0xcc` bytes, then the `0x00554680` prologue.
- `make_signature 0x00554640`: `B8 01 00 00 00 66 89 01`, unique.
- `make_signature 0x00554650`: `66 FF 01`, unique.
- `make_signature 0x00554660`: `66 FF 09 66 83 39 00`, unique.
- `make_signature_for_range 0x00554640-0x00554675`: unique.
- `find_bytes` found the full initializer, full increment helper, full release helper, and `push 2; push ecx; call sub_5C7526; add esp, 8; retn` tail exactly once, at this target.
- `find_bytes` found zero raw little-endian VA pointer hits for `0x00554640`, `0x00554650`, and `0x00554660`.
- `find_bytes` found zero raw RVA pointer hits for `0x00154640`, `0x00154650`, and `0x00154660`.

Metadata/name facts:

- `entity_query` for names in `0x00554600-0x00554700`: no names.
- `find_regex` for `refcount|referencecount|ref count`: zero.
- `find_regex` for `intrusive|wordref|word ref`: zero.
- `find_regex` for `.pdb|RSDS|NB10`: zero IDA string-cache hits.
- `find_regex` for candidate owner names finds RTTI/name strings for `LObject`, `StringBase`, `Motion`, `ReconnectDialog`, `CopyWindow`, and `Region` elsewhere, but none reference the helper starts.

## Independent PE Scan Facts

The B003 local PE scan used the same binary as IDA:

- Path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Image base: `0x00400000`
- `.text`: `0x00401000-0x0060c600`, executable
- `.rdata`: `0x0060d000-0x0066c200`
- `.data`: `0x0066d000-0x0069ce24`
- `.rsrc`: `0x0069d000-0x006b2e00`

Exact bytes:

- `0x00554635`: eleven `0xcc` bytes.
- `0x00554640`: `b8 01 00 00 00 66 89 01 8b c1 c3`.
- `0x00554650`: `66 ff 01 c3`.
- `0x00554660`: `66 ff 09 66 83 39 00 7f 0b 6a 02 51 e8 b5 2e 07 00 83 c4 08 c3`.
- `0x00554675`: eleven `0xcc` bytes.

Pattern uniqueness:

| Pattern | Count | Hit |
| --- | ---: | --- |
| initializer | 1 | `0x00554640` |
| increment | 1 | `0x00554650` |
| release | 1 | `0x00554660` |
| exact free tail | 1 | `0x00554669` |

Raw reference scan:

| Target | Absolute VA dword hits | RVA dword hits | Relative branch/call hits |
| --- | ---: | ---: | ---: |
| `0x00554640` | 0 | 0 | 0 |
| `0x00554650` | 0 | 0 | 0 |
| `0x00554660` | 0 | 0 | 0 |

The branch scan covered executable-section `E8/E9 rel32`, `0F 80-8F rel32`, `EB rel8`, and `70-7F rel8` branch forms. The scan also found `617` direct calls to `0x005c7526`; only three call sites had `push 2` within the previous 20 bytes: `0x004564bb`, `0x004574bb`, and this target's `0x0055466c`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Owner | Emitters | Score | Status |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `0x00554640-0x00554675` | `00023P` / `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md` | complete init/addref/release helper island | true | `NONE` | blank | `88/92` | keep as-is |
| `0x00554640-0x0055464b` | contained in `00023P` | initializer: `word [this] = 1`, return `this` | true | unresolved | blank | inherited | no split |
| `0x00554650-0x00554654` | contained in `00023P` | addref: increment first word | true | unresolved | blank | inherited | no split |
| `0x00554660-0x00554675` | contained in `00023P` | release: decrement first word and free when count is not positive | true | unresolved | blank | inherited | no split |
| `0x0055464b-0x00554650` | coverage padding row | internal alignment | false/ignored | ignored ledger | none | `100/strong` | unchanged |
| `0x00554654-0x00554660` | coverage padding row | internal alignment | false/ignored | ignored ledger | none | `100/strong` | unchanged |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00554640` | no IDA xrefs, no PE VA/RVA pointer hits, no branch/call targets | no proven caller, table entry, or source-use context |
| `0x00554650` | no IDA xrefs, no PE VA/RVA pointer hits, no branch/call targets | raw helper is not statically referenced |
| `0x00554660` | no IDA xrefs, no PE VA/RVA pointer hits, no branch/call targets | raw release helper is not statically referenced |
| `0x0055466c -> 0x005c7526` | outgoing free-wrapper call | dependency only; does not prove owner |
| `0x00554680` | many code refs to following Region constructor | proves successor island is reachable, not that it owns target |
| `0x004564bb`, `0x004574bb` | MiniMapVersionManager `push 2` / free-wrapper comparison sites | deallocation idiom control cases, not target owner evidence |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target page `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md` already records the exact helper/padding layout, repeated no-xref evidence, unique patterns, and rejected owner candidates. B003 live checks reconfirmed the material facts.
- Previous B001 executed report recommends leaving the target reconstructable, parent-blank, and unsplit. Under current terminology, that becomes `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`.
- `by-structure.md` says reconstructable NexusTK source may remain ownerless/non-emitting while research continues, and warns not to fill owner/emitter fields merely because ownership is plausible.
- `auto-generated/-ag-memory-coverage.md` currently reports `Total_DeadEnds: 0` and row `00023P` as `no-owner`, owner `NONE`, blank emitters, no code, no destination.
- `by-memory/-coverage-report.md` already carries the B001 evidence row for this target and does not require a replacement.

Documentation evidence against candidate owners/emitters:

- `ConnectionReconnectDialogCleanupAndDestructorThunks` ends at `0x00554635` and documents `0x00554635-0x00554640` as eleven `0xcc` bytes before `00023P`.
- `ConnectionClosedReconnectDialogs` is now a `RECONSTRUCTABLE:FALSE` mixed physical map whose exact children carry ownership; it stops before `00023P`.
- `RegionAndMotionRect` starts at `0x00554680` after `0x00554675-0x00554680` padding and documents Region/Motion rectangle/vtable behavior, not word refcounting.
- `StringBase` / `RefCountedStringBufferHeader` document the real ref-counted string-buffer family as a 12-byte prefix with 32-bit interlocked counts, sentinels, and pools. That contradicts this target's 16-bit count at object head and direct free of `this`.
- `StringUtil` is a broad utility string coordinator with `StringBase` as preferred owner for the ref-counted string implementation; it has no evidence for this unreferenced word-count island.
- `LinkedList` owns 16-byte sentinel-list node helpers with cross-feature callers; `00023P` has no sentinel/list-node shape.
- `PoolAllocator` owns fixed-block pool mechanics; `00023P` directly calls a free wrapper rather than returning storage to pool state.
- `LObject` owns the one-vptr runtime/base shell and excludes string-helper pollution; `00023P` has no vtable/runtime-class evidence.
- `MiniMapVersionManager` shares two `push 2` / free-wrapper comparison sites, but its docs show those are class teardown paths for minimap list payloads/nodes.

## Ranked Ownership And Emitter Analysis

### 1. Keep `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS` - recommended

Evidence for:

- No direct xrefs, raw pointer references, branch/call targets, vtable/table entries, source strings, PDB strings, or local names prove ownership.
- Current owner/emitter rules allow `RECONSTRUCTABLE:TRUE` with unresolved owner/emitter while research continues.
- Blank emitters avoid inventing a source-use context.
- Generated report has `Total_DeadEnds: 0`; this is tracked as no-owner/non-emitting backlog, not invalid routed output.

Evidence against:

- The helper family is source-authored and should eventually be represented somewhere if a true source route is found.
- The three helper bodies are coherent enough that a future narrow utility owner is plausible.

Decision: keep current metadata. This is the most accurate current-model representation.

### 2. New narrow `util/WordRefCountHelpers.cpp` / `IntrusiveWordRefCount` - best if forced, not actionable now

Evidence for:

- The range is a complete init/addref/release helper family.
- The behavior is generic lifetime management rather than UI, map, or string-buffer specific.
- Proposed source tree already has `NexusTK/util/` for generic utility/container/lifetime support.
- No existing owner is stronger.

Evidence against:

- No source-facing name, type metadata, caller, pointer table, object-file boundary, or source-path breadcrumb exists.
- The proposed source file would contain only this no-xref island today.
- Creating a file solely to avoid `NONE` would conflict with the current guidance not to invent standalone helper files without evidence.

Likely full contents if future policy/evidence accepts it:

- A narrow helper/type declaration with three operations: initialize count to `1`, increment count, decrement count and delete/free when nonpositive.
- No current neighboring by-memory item should be automatically added. Adjacent reconnect and Region spans have their own stronger owners; string/container/allocator pages describe incompatible mechanisms.

Decision: document as best-if-forced source-family hypothesis only. Do not create owner or emitter route in this pass.

### 3. `EMITTER_UIDS:0000OA` / `StringBase` - rejected

Evidence for:

- Abstract refcount theme.
- `StringBase` is the preferred owner for a large ref-counted string-buffer implementation under `NexusTK/util/`.

Blocking facts:

- `StringBase` uses a 12-byte header before the returned character data pointer.
- Refcounts are 32-bit and changed by `InterlockedIncrement` / `InterlockedDecrement`.
- String release uses sentinels and pool-capacity selection.
- `00023P` uses a 16-bit word at `this`, no sentinel, no pool switch, and frees `this` directly.
- No `StringBase` method, vtable, RTTI, type, or source-use path references `0x00554640`, `0x00554650`, or `0x00554660`.

Decision: reject both ownership and emitter route.

### 4. `EMITTER_UIDS:0000OB` / `StringUtil` - rejected

Evidence for:

- Broad utility-string source root with many helper-style children.
- Generic utility placement is plausible in the abstract.

Blocking facts:

- `StringUtil` evidence is for `SimpleUString`, `SimpleUStringVector`, fixed wide-format wrappers, wide-string map nodes, and coordination with `StringBase`.
- No string layout, caller spread, or source-use context connects this target to `StringUtil`.
- A broad utility coordinator is not a valid emitter for unrelated no-xref lifetime helpers.

Decision: reject.

### 5. ReconnectDialog / ConnectionClosedDialog / CopyWindow route - rejected

Evidence for:

- Physical predecessor range is near the target.

Blocking facts:

- The reconnect cleanup/destructor child ends at `0x00554635`; `0x00554635-0x00554640` is padding.
- No reconnect/copy-window function, vtable, singleton, or read-only-data reference targets the helper starts.
- The preceding page is dialog singleton/vtable/destructor behavior, not word refcount object lifetime.

Decision: reject owner and emitter route.

### 6. Region / Motion route - rejected

Evidence for:

- The following island starts at `0x00554680` and is heavily referenced.
- Region/Motion are utility-like UI geometry helpers.

Blocking facts:

- `0x00554675-0x00554680` is padding before the Region constructor.
- `xrefs_to 0x00554680` has many code refs, while all target starts have zero refs.
- Region/Motion docs describe `LObject` vptr plus rectangle fields, not first-word refcount layout.
- No Region/Motion vtable, constructor, destructor, or field path touches this target.

Decision: reject.

### 7. LinkedList / PoolAllocator / LObject / MiniMapVersionManager / CRT - rejected

Evidence for:

- These are utility or lifetime-adjacent systems, and MiniMapVersionManager shares the `push 2` / free-wrapper idiom.

Blocking facts:

- `LinkedList` is a 16-byte sentinel-list node family with cross-feature callers.
- `PoolAllocator` is fixed-block pool state with locks, chunks, and free lists.
- `LObject` is a one-vptr runtime class shell.
- MiniMapVersionManager comparison sites free known minimap list payloads/nodes and do not reference this island.
- `sub_5C7526` is a free-wrapper callee, not the owner of this source-authored init/addref/release family.

Decision: reject all as direct owners and emitters.

## Negative Evidence Summary

Checked and rejected:

- direct IDA xrefs to all three helper starts;
- xref signatures to all three helper starts;
- raw absolute VA dwords and RVA dwords for all three starts;
- direct `E8/E9`, near conditional, and short branch targets to all three starts;
- duplicate full-byte patterns;
- local names in `0x00554600-0x00554700`;
- `refcount`, `referencecount`, `intrusive`, `wordref`, PDB, RSDS, and NB10 string evidence;
- adjacency to predecessor reconnect/copy-window functions;
- adjacency to successor Region/Motion functions;
- StringBase/StringUtil thematic refcount route;
- LinkedList/PoolAllocator/LObject utility routes;
- MiniMapVersionManager `push 2` free-wrapper idiom route;
- CRT/free-wrapper ownership.

The remaining blocker is exact and actionable: no current binary or documentation evidence proves a source declaration owner or any source-use context for emitted code.

## Exact Recommended Metadata And Coverage State

Target metadata should remain exactly:

```text
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No `by-memory/-coverage-report.md` replacement row is required. The current manual row already states the accepted B001 evidence and the same no-owner conclusion.

The current generated primary row is correct and should remain semantically unchanged after normal autogen:

```markdown
| [UID:00023P][0x00554640-0x00554675.WordRefCountHelpers](by-memory/0x00554640-0x00554675.WordRefCountHelpers.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md` |  |
```

The current generated non-emitting/no-owner secondary row is also correct:

```markdown
| [UID:00023P][0x00554640-0x00554675.WordRefCountHelpers](by-memory/0x00554640-0x00554675.WordRefCountHelpers.md) | no-owner | `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md` |  |  |  |
```

If the supervisor wants the manual coverage row to mention this B003 post-migration recheck, use the existing row text as the placement anchor and append a short note rather than changing metadata. This is optional, not required for correctness.

## Final Recommendation

Exact changes recommended:

- No target metadata change.
- No emitters.
- No canonical owner.
- No split.
- No reclassification to `RECONSTRUCTABLE:FALSE`.
- No final reconstruction C++.
- No coverage-report change required.

Exact item left no-owner/non-emitting:

- `00023P` remains no-owner/non-emitting because all known source-use routes are blocked by zero xrefs, zero raw pointer/branch references, no metadata, and incompatible candidate-owner layouts.

Condition that would change the recommendation:

- a direct code/data/table/vtable/reference edge to one of the helper starts;
- a source/PDB/linker-map/object-file breadcrumb proving the compilation unit;
- a recovered type/class with first-word 16-bit intrusive refcount semantics and calls or table references to these helpers;
- a supervisor-approved policy to create a narrow no-xref utility owner, after documenting and scoring that new owner itself.

## Follow-Up Actions

Supervisor actions:

- Mark the B003 post-migration recheck accepted with no metadata or coverage-row change, or optionally append a B003 note to the existing manual coverage text.
- Do not add `EMITTER_UIDS` for `StringBase`, `StringUtil`, `ReconnectDialog`, `Region`, or any other existing file under current evidence.

A-agent actions:

- Do not route this target during routine no-owner cleanup unless new caller/source-use evidence appears.
- Keep final C++ blank until owner, emitter, naming, and behavior are final-audit quality.

B003 future research actions:

- Revisit only if another assignment uncovers a matching first-word 16-bit intrusive refcount type, hidden dispatch table, or source/debug breadcrumb.

## Confidence

- Recommendation confidence: `90/100` for keeping current metadata under the owner/emitter model.
- Range/behavior confidence: `96/100`.
- No-reference confidence: `95/100` after live IDA and independent PE scans.
- Rejection of existing owners/emitters: `89/100`.
- Best-if-forced `util/WordRefCountHelpers` source-family hypothesis: `72/100`, below assignment threshold.
- Remaining uncertainty: original source filename, original API/type name, whether the helpers are dead retained methods, and whether a runtime-only indirect mechanism ever reached them.

## Validator Results

- Commands run: none.
- Reason: this assignment created only an Agent-B003 research report and made no target/by-memory edits. The user also instructed not to use dry-run modes, and no validator apply operation was needed for an Agent research Markdown file.
- Unresolved validator warnings/errors: none from this pass.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/00023P-WordRefCountHelpers-post-migration.md`
- Modified: none.
- Renamed: none.
- Moved to executed: none.
- Direct `by-memory/-coverage-report.md` edits: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/00023P-WordRefCountHelpers-post-migration.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"00023P"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
