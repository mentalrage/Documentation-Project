** TARGET-REPORT-UID:0002BD **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BD UiAssetModeRectVirtualDispatchHelper Current No-Owner Sweep

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002BD] `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md` as reconstructable project code with `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank `RECONSTRUCTION_CPP`.
- Final disposition: no owner, no emitter route, no split, no merge, no reclassification, no IDA-safe name repair, and no C++ code entry in this pass.
- Required action: no direct documentation edit is required for the target page, generated memory row, or `by-memory/-coverage-report.md`. If the supervisor wants explicit row text for the shared report, keep the current row text recorded below.
- Confidence: `91` for the negative owner/emitter result and `87/91` target score retention. The helper is source-shaped and reconstructable, but the original source owner and any generated-output route remain unproven.

## Supporting Research

## Target

- Target UID: `0002BD`
- Target path: `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md`
- Source queue/report row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, section `Active 2026-06-14 Remaining No-Owner Memory Sweep`, row for `0002BD`.
- Current supervisor classification: current Goal 2 no-owner memory sweep target.
- Current generated status: `auto-generated/-ag-memory-coverage.md` lists `no-owner`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, no generated file.
- Current target metadata: `COMPLETION:87`, `CONFIDENCE:91`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank `RECONSTRUCTION_CPP`.
- Prior report reviewed first as background only: `tools/leaser/Agents/Agent-B003/research/executed/0002BD-UiAssetModeRectVirtualDispatchHelper-current-goal2-pass.md`.

## Executive Recommendation

The current no-owner/non-emitting state is still correct. The body at `0x00503060-0x005030bc` is a unique, source-shaped UI helper that optionally builds a mode-selected `RectBounds` and dispatches it through `this` vtable slot `+0x20`, but live IDA MCP and a fresh section-aware PE scan still find no direct caller, no table/vtable pointer, no absolute VA/RVA pointer, and no direct external branch/call route to the helper entry.

MapNamePane remains the strongest semantic lead because the helper uses the same `0xad` width as the documented 173-pixel map-name clamp, and the third sibling helper [UID:0002BF] is now owned by `MapNamePane`. That is not enough for ownership here. Unlike [UID:0002BF], this helper does not read the `MapNamePane` private `this+0x220` font field, has no MapName vtable slot, and has no caller from the MapName constructor/render/update methods.

Do not emit C++. The target is `87/91`, below the active `90/90+` reconstruction-code gate, and source placement plus the vtable-slot semantics are unresolved.

## Supervisor Active Recheck

- Triggering instruction: recheck [UID:0002BD] from the current generated no-owner memory sweep, treating prior reports and docs as leads rather than authority.
- Split requirement: no split is required. The target is already an exact child of [UID:00022Z] `0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers`; its body boundaries are still exact.
- Source-bearing children in scope: the assigned child itself remains source-bearing/reconstructable. Sibling pages were checked as context only and do not require repair.
- Shared report handling: `by-memory/-coverage-report.md` was not edited. The exact current row is included below for supervisor reference.

## Inference Research Guidance Check

`by-structure.md` controls the decision:

- `CANONICAL_OWNER` must be the best direct semantic owner, not the nearest address neighbor or broad thematic file.
- `EMITTER_UIDS` is generated-output routing, not ownership. A reconstructable page can remain non-emitting while owner and source route are unresolved.
- Shared pooled literals can be `CANONICAL_OWNER:NONE` with multiple emitters when proven source-use routes exist. This target is executable helper code, not pooled literal/data; blank emitters are correct unless a source-use/output route is proven.
- Reconstruction C++ must remain blank unless the item, owner/emitter route, dependencies, names, boundaries, and source placement meet the active `90/90+` code-entry gate.

`inference_research.md` affected the recommendation by keeping address adjacency, theme, and consumer-style associations below direct xref/table/field evidence. The current docs were treated as leads. The current IDA MCP and PE facts independently support the no-owner/non-emitting conclusion.

## Evidence Standards Used

Evidence types used:

- Current target page and current generated `-ag-memory-coverage` row.
- Parent split inventory [UID:00022Z] and sibling pages [UID:0002BE] and [UID:0002BF].
- Candidate owner docs: `MapNamePane` class/file, `MiniMapButtonPane`, `g_useEpfAssets`, and `RectGeometryHelpers`.
- Live IDA MCP session `b001_0003gy`: `server_health`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `find_bytes`, `make_signature`, and `make_signature_for_range`.
- Fresh raw PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for VA/RVA pointers and direct branch/call targets.
- Numeric conversion checks with `tools/int_convert.py`: `0xa6` is 166, `0xad` is 173, `0x10` is 16, `0x20` is 32, and `0x220` is 544 (all verified with `int_convert.py`).

The evidence is strong for the boundary, body behavior, and absence of obvious owner/emitter routes. It is intentionally not strong enough to name a source owner, because the remaining positive evidence is semantic association rather than a direct path.

## IDA MCP Facts

IDA MCP session facts:

- Session ID: `b001_0003gy`
- Input path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- IDB path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- Image base: `0x00400000`
- Auto-analysis ready: `true`
- Hex-Rays ready: `true`
- Strings cache ready: `true`
- Note: the current MCP backend requires `database=b001_0003gy`; all final evidence calls used that session argument.

Function/range facts from `lookup_funcs`:

| Address | Result |
| --- | --- |
| `0x00503060` | not a function |
| `0x00503070` | not a function |
| `0x00503079` | not a function |
| `0x00503098` | not a function |
| `0x005030a0` | not a function |
| `0x005030a8` | not a function |
| `0x005030bc` | not a function |
| `0x005030c0` | not a function |
| `0x00503104` | not a function |
| `0x00503110` | not a function |
| `0x005031e1` | not a function |
| `0x005031f0` | `sub_5031F0`, size `0xd3` |
| `0x00503350` | `sub_503350`, size `0x14f` |
| `0x005034a0` | `sub_5034A0`, size `0xd4` |
| `0x00503580` | `sub_503580`, size `0x9e` |
| `0x00503650` | `sub_503650`, size `0x42` |
| `0x005036a0` | `sub_5036A0`, size `0x14d` |
| `0x00503840` | `sub_503840`, size `0xbe` |
| `0x00503900` | `sub_503900`, size `0x5f` |

Raw byte facts from `get_bytes`:

- `0x00503050-0x0050313f` shows the prior modeled function tail, four `0xcc` bytes, the target prologue at `0x00503060`, target `retn 4`, four `0xcc` bytes at `0x005030bc-0x005030c0`, sibling [UID:0002BE] at `0x005030c0`, twelve `0xcc` bytes at `0x00503104-0x00503110`, and sibling [UID:0002BF] at `0x00503110`.
- `0x0061e5b4` vtable-region bytes include normal nearby MapName/MiniMap entries such as `0x00503840`, `0x00503350`, `0x005034a0`, `0x00503900`, `0x00503650`, and `0x005036a0`. They do not include `0x00503060`.

Target body facts:

```asm
00503060  push ebp
00503061  mov ebp, esp
00503063  sub esp, 14h
00503066  mov eax, ___security_cookie
0050306b  xor eax, ebp
0050306d  mov [ebp-4], eax
00503070  sub dword ptr [ebp+8], 1
00503074  push esi
00503075  mov esi, ecx
00503077  jnz short loc_5030A0
00503079  cmp byte_66DA97, 1
00503080  lea eax, [ebp-14h]
00503083  push 10h
00503085  jnz short loc_50308E
00503087  push 0A6h
0050308c  jmp short loc_503093
0050308e  push 0ADh
00503093  push 0
00503095  push 0
00503097  push eax
00503098  call sub_4B7C50
0050309d  add esp, 14h
005030a0  mov eax, [esi]
005030a2  lea ecx, [ebp-14h]
005030a5  push ecx
005030a6  mov ecx, esi
005030a8  call dword ptr [eax+20h]
005030ab  mov ecx, [ebp-4]
005030ae  xor ecx, ebp
005030b0  pop esi
005030b1  call @__security_check_cookie@4
005030b6  mov esp, ebp
005030b8  pop ebp
005030b9  retn 4
```

Behavior facts:

- The helper receives `this` in `ecx` and one stack argument.
- It decrements the stack argument, initializes the local rect only when the adjusted value is zero, and then always dispatches through `this` vtable slot `+0x20`.
- If `byte_66DA97` / [UID:0000SW] `g_useEpfAssets` equals `1`, it initializes `RectBounds(0, 0, 0xa6, 0x10)` through `sub_4B7C50`.
- Otherwise it initializes `RectBounds(0, 0, 0xad, 0x10)` through `sub_4B7C50`.
- `0xa6` is 166, `0xad` is 173, and `0x10` is 16, verified with `int_convert.py`.
- `0x20` is 32, verified with `int_convert.py`, and is the vtable slot offset used by this helper.

Signature and pointer facts:

- `make_signature` for `0x00503060` produced unique signature `55 8B EC 83 EC 14 A1 ? ? ? ? 33 C5 89 45 ? 83 6D ? ? 56 8B F1 75 ? 80 3D`.
- `make_signature` for useful interiors `0x00503079` and `0x005030a0` also produced unique signatures.
- `make_signature_for_range` for `0x00503060-0x005030bc` produced a unique wildcarded range signature.
- `find_bytes` found zero little-endian VA hits for `0x00503060`, `0x00503070`, `0x00503079`, `0x00503098`, `0x005030a0`, `0x005030a8`, `0x005030bc`, `0x005030c0`, and `0x00503110`.
- Positive control `find_bytes` hits were present for nearby vtable methods: `0x00503350 -> 0x0061e5f8`, `0x005034a0 -> 0x0061e610`, `0x00503650 -> 0x0061e680`, and `0x005036a0 -> 0x0061e68c`.

Xref facts from `xrefs_to`:

| Address | Xrefs | Meaning |
| --- | --- | --- |
| `0x00503060` | none | no entry route |
| `0x00503070` | internal code xref from `0x0050306d` | no external owner route |
| `0x00503079` | internal code xref from `0x00503077` | no external owner route |
| `0x00503098` | internal code xref from `0x00503097` | no external owner route |
| `0x005030a0` | internal code xrefs from `0x0050309d` and `0x00503077` | internal state branch target |
| `0x005030a8` | internal code xref from `0x005030a6` | virtual dispatch instruction inside body |
| `0x005030bc` | none | no end/padding route |
| `0x005030c0` | none | sibling start unreferenced |
| `0x00503104` | none | sibling end/padding route absent |
| `0x00503110` | none | sibling [UID:0002BF] start still no live caller |
| `0x005031e1` | none | no right-boundary route |
| `0x005031f0` | code xrefs from `0x004f8051` and `0x004f8695` | positive MapName constructor control |
| `0x00503350` | data xref at `0x0061e5f8` | positive MapName vtable control |
| `0x005034a0` | data xref at `0x0061e610` | positive MapName vtable control |
| `0x00503580` | code xref from `0x004f80c2` | positive MiniMapButton constructor control |
| `0x00503650` | data xref at `0x0061e680` | positive MiniMapButton vtable control |
| `0x005036a0` | data xref at `0x0061e68c` | positive MiniMapButton vtable control |
| `0x00503840` | thunk refs plus data xref at `0x0061e5b4` | positive MapName destructor/vtable control |
| `0x00503900` | thunk refs plus data xref at `0x0061e63c` | positive MiniMapButton destructor/vtable control |

Negative IDA facts:

- No function object exists at the target or useful interiors.
- No external `xrefs_to` route reaches the target entry.
- No little-endian VA pointer to the target or useful interiors exists in the loaded IDB search.
- Nearby MapName/MiniMap vtable slots resolve for real methods but do not point to `0x00503060`.
- The target body has no MapName-private field access analogous to sibling [UID:0002BF]'s `this+0x220` read.

## PE / Raw Executable Evidence

Fresh section-aware raw scan target:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
```

PE facts:

| Section | VA | VSZ | RAW | RSZ |
| --- | --- | --- | --- | --- |
| `.text` | `0x00001000` | `0x0020b4ac` | `0x00000400` | `0x0020b600` |
| `.rdata` | `0x0020d000` | `0x0005f0be` | `0x0020ba00` | `0x0005f200` |
| `.data` | `0x0026d000` | `0x0002fe24` | `0x0026ac00` | `0x0000d800` |
| `.rsrc` | `0x0029d000` | `0x00015c38` | `0x00278400` | `0x00015e00` |

Pointer/reference results:

| Target | VA pointer hits | RVA pointer hits |
| --- | --- | --- |
| `0x00503060` | none | none |
| `0x00503070` | none | none |
| `0x00503079` | none | none |
| `0x00503098` | none | none |
| `0x005030a0` | none | none |
| `0x005030a8` | none | none |
| `0x005030bc` | none | none |
| `0x005030c0` | none | none |
| `0x00503104` | none | none |
| `0x00503110` | none | none |
| `0x005031e1` | none | none |
| `0x00503350` | raw `0x21cff8` | none |
| `0x005034a0` | raw `0x21d010` | none |
| `0x00503650` | raw `0x21d080` | none |
| `0x005036a0` | raw `0x21d08c` | none |
| `0x00503840` | raw `0x21cfb4` | none |
| `0x00503900` | raw `0x21d03c` | none |

Branch/call target results:

| Target | PE branch/call target hits |
| --- | --- |
| `0x00503060` | none |
| `0x00503070` | none |
| `0x00503079` | none |
| `0x00503098` | none |
| `0x005030a0` | internal `75 rel8` from `0x00503077` |
| `0x005030a8` | none |
| `0x005030bc` | none |
| `0x005030c0` | none |
| `0x00503104` | sibling-internal `75 rel8` from `0x005030f6` |
| `0x00503110` | none |
| `0x005031e1` | none |
| `0x00503350` | none |
| `0x005034a0` | none |
| `0x00503650` | none |
| `0x005036a0` | none |
| `0x00503840` | thunk jumps from `0x00503811` and `0x0050381c` |
| `0x00503900` | thunk jumps from `0x00503827` and `0x00503832` |

This raw scan supports the IDA negative result: it found no absolute pointer, RVA literal, direct call/jump, near conditional, short conditional, short jump, or loop-style direct branch to the target entry. Positive controls prove the scan sees ordinary vtable pointers and thunk branches nearby.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00502e30-0x0050305c` | existing modeled `sub_502E30` | left neighboring modeled function | out of scope | unrelated left neighbor | not reviewed here | ends before `0xcc` pad |
| `0x0050305c-0x00503060` | [UID:0000VN] `by-memory/-ignored.md` | alignment padding | false | ignored ledger | `100/strong` in coverage | four `0xcc` bytes |
| `0x00503060-0x005030bc` | [UID:0002BD] target | asset-mode rect virtual-dispatch helper | true | `NONE` | `87/91` | keep no-owner/non-emitting |
| `0x005030bc-0x005030c0` | [UID:0000VN] `by-memory/-ignored.md` | alignment padding | false | ignored ledger | `100/strong` in coverage | four `0xcc` bytes |
| `0x005030c0-0x00503104` | [UID:0002BE] `UiAssetModeRectWriteHelper` | sibling rect write helper | true | `NONE` | `87/91` | no-owner/non-emitting context |
| `0x00503104-0x00503110` | [UID:0000VN] `by-memory/-ignored.md` | alignment padding | false | ignored ledger | `100/strong` in coverage | twelve `0xcc` bytes |
| `0x00503110-0x005031e1` | [UID:0002BF] `WideGlyphResourceTextRendererRaw` | sibling 9x11 glyph renderer | true | `00007P` | `87/91` | MapName-owned through `this+0x220` evidence |
| `0x005031e1-0x005031f0` | [UID:0000VN] `by-memory/-ignored.md` | alignment padding | false | ignored ledger | `100/strong` in coverage | fifteen `0xcc` bytes |
| `0x005031f0-0x0050395f` | [UID:0001AL] `MapNameAndMiniMapButtonPanes` | following interleaved MapName/MiniMap island | container/mixed | per-child | reviewed elsewhere | warns not to absorb raw cluster without route evidence |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00503060` | no `xrefs_to`, no PE pointer, no PE branch target | no proven caller, table entry, or emitter route |
| `0x00503098` | calls `sub_4B7C50` | uses shared RectBounds initializer, but callee fan-in is broad and does not prove owner |
| `0x005030a8` | calls `[this->vtable + 0x20]` | proves virtual dispatch pattern but not receiver type |
| `byte_66DA97` / [UID:0000SW] | read by target compare | broad asset-mode selector, not declaration owner for this helper |
| `0x005031f0` | called from `0x004f8051`, `0x004f8695` | positive MapName constructor control absent from target |
| `0x00503350`, `0x005034a0` | vtable entries at `0x0061e5f8`, `0x0061e610` | positive MapName vtable controls absent from target |
| `0x00503580` | called from `0x004f80c2` | positive MiniMapButton constructor control absent from target |
| `0x00503650`, `0x005036a0` | vtable entries at `0x0061e680`, `0x0061e68c` | positive MiniMapButton vtable controls absent from target |
| [UID:0002BF] | reads `this+0x220` | sibling has direct MapName field evidence; target does not |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target page [UID:0002BD] records exact range, body behavior, `g_useEpfAssets` branch, `RectBounds` setup, virtual slot `+0x20`, no function object, no start xrefs, no pointer hits, no vtable slot, and blank owner/emitter state.
- Parent [UID:00022Z] records this cluster as a non-emitting split inventory. It says candidate MapName, MiniMapButton, MiniMap, and MainMenu parents fail the direct-parent test for the first two helpers.
- Sibling [UID:0002BE] is a structurally similar no-owner/non-emitting rect writer. It reinforces that the `0xa6`/`0xad` rectangle association alone has not been treated as direct owner proof.
- Sibling [UID:0002BF] is assigned to [UID:00007P] `MapNamePane`, but specifically because it reads `this+0x220`, a field the MapName constructor loads with `9X11FONT.BIN` and the destructor frees. The target lacks this evidence.
- [UID:00007P] `MapNamePane` and [UID:0000L2] `MapNamePane` file docs prove the MapName owner candidate itself is real and gate-valid, with constructor callers and vtable slots, but not connected to `0x00503060`.
- [UID:00008B] `MiniMapButtonPane` proves the adjacent minimap button class and vtables are real, but it has no target route.
- [UID:0000SW] `g_useEpfAssets` proves the byte is a broad process-wide UI asset selector owned upward by `StartupWindow`; it is a dependency, not target ownership.
- [UID:00015S] `RectGeometryHelpers` proves `sub_4B7C50` initializes four rect edges; it is a callee dependency with broad fan-in, not target ownership.

Existing docs that are stale, incomplete, or contradicted:

- No current doc contradiction was found for this target.
- Some historical text still mentions the old `AUTOGEN_PARENT_UID` terminology in older change logs. Under the current model this maps to `CANONICAL_OWNER` and/or `EMITTER_UIDS`, and the current metadata already uses the corrected fields.
- Parent [UID:00022Z] still contains old wording about a prior 95+ gate in a historical sentence, but its current header and status correctly use `RECONSTRUCTABLE:FALSE` as a split inventory. This does not require an in-scope edit for the assigned 0002BD no-owner sweep.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` row for [UID:0002BD] is still `no-owner`, `CANONICAL_OWNER:NONE`, blank emitters.
- `by-memory/-coverage-report.md` already contains a detailed current B003 row for [UID:0002BD]. No replacement is required.

## Ranked Ownership Analysis

### 1. Keep `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS` - accepted

- Evidence for: no function object, no entry xrefs, no PE VA/RVA pointer hits, no direct PE call/jump/branch to the entry, no MapName/MiniMap vtable slot, no class-private field access, no source-use output route, and no proven receiver type for vtable slot `+0x20`.
- Evidence against: the helper is source-shaped, adjacent to the MapName/MiniMap island, uses `g_useEpfAssets`, and uses the `0xad` width matching the MapName 173-pixel clamp. Those are useful leads.
- Decision: accepted as the only defensible current state. This is a last-resort no-owner/non-emitting result after testing stronger owner candidates.

### 2. [UID:00007P] `MapNamePane` / [UID:0000L2] `MapNamePane.cpp` - rejected for assignment

- Evidence for: address adjacency to the MapName/MiniMap island; `0xad` is 173, matching MapName's documented 173-pixel clamp (verified with `int_convert.py`); sibling [UID:0002BF] is MapName-owned; the vtable dispatch could plausibly be a pane redraw/layout callback.
- Evidence against: no caller from MapName methods, no MapName vtable slot to `0x00503060`, no VA/RVA pointer to the helper, no PE branch/call route, and no `this+0x220` or other MapName-private field use. Positive MapName controls are visible in IDA and PE, so the absence is meaningful.
- Decision: best semantic lead, but not enough for `CANONICAL_OWNER` or `EMITTER_UIDS`.

### 3. [UID:00008B] `MiniMapButtonPane` / [UID:0000LE] `MiniMap` - rejected

- Evidence for: the raw cluster sits immediately before the interleaved MapName/MiniMapButton island; MiniMapButton has nearby vtable-controlled methods and uses EPF assets.
- Evidence against: no MiniMapButton constructor caller, vtable entry, singleton field, resource string, paint path, mouse path, or private state access points to the helper. The positive MiniMapButton vtable entries `0x00503650` and `0x005036a0` are found, but `0x00503060` is absent.
- Decision: weaker than MapName and not assignable.

### 4. [UID:00019I] MainMenu/Login/Account dialog neighborhood or [UID:0000L1] MainUiGraph - rejected

- Evidence for: left-side address neighborhood and UI bootstrap context near `InitializeMainUiGraph`.
- Evidence against: `0xcc` padding separates the prior modeled function from the raw cluster; the target has no caller from main UI initialization, no direct branch from the left neighbor, and no table/pointer route. MainUiGraph reads `g_useEpfAssets`, but that broad read does not own every consumer helper.
- Decision: address-neighbor/bootstrap association only; not assignable.

### 5. [UID:00015S] `RectGeometryHelpers` / [UID:0000N2] `RectBounds` - rejected

- Evidence for: the helper calls `sub_4B7C50`, and the local data is a `RectBounds`.
- Evidence against: `sub_4B7C50` is a broad shared initializer with very high fan-in; this target is a UI helper that consumes rectangle primitives, not a geometry helper declaration. The virtual dispatch and `g_useEpfAssets` branch are outside RectBounds responsibilities.
- Decision: dependency only, not owner or emitter.

### 6. [UID:0000SW] `g_useEpfAssets` / [UID:0000O5] `StartupWindow` - rejected

- Evidence for: the target reads `byte_66DA97`, whose best source-owner inference is `StartupWindow`.
- Evidence against: the byte is a process-wide extern-style selector with hundreds of reads. Reading it does not make every consumer a StartupWindow source child. The target has no StartupWindow caller, field, table, or lifecycle connection.
- Decision: dependency only, not owner or emitter.

### 7. New source file/grouping - rejected for now

- Proposed owner/name/path if future evidence appears: a narrow map/UI private helper group such as `UiAssetModeRectHelpers` or a private helper pair under `MapNamePane`/`MapPane` could eventually contain [UID:0002BD] and [UID:0002BE].
- Likely full contents if proven: the two asset-mode rectangle helpers [UID:0002BD] and [UID:0002BE], plus only any future discovered table/caller that references them.
- Candidate related items rejected now: [UID:0002BF] already has stronger MapName ownership through `this+0x220`, so it should not be pulled into a new file merely by address adjacency.
- Standalone, narrow, or broad source-file inference: narrow at most, but not currently justified. Creating a new source file would manufacture an owner to hide missing caller/source-route evidence.
- Decision: do not create a new owner or grouping in this pass.

### 8. Split, merge, reclassify, or IDA-safe rename - rejected

- Evidence for split/merge/reclassification: none. The child range is exact, executable, source-shaped, and already split from its parent aggregate and padding.
- Evidence against: the target has a coherent single body with a clear prologue, stack cookie, local rect setup, virtual call, cookie check, `retn 4`, and following `0xcc` padding. It is not padding, not a mixed aggregate, and not compiler/runtime-only code.
- Decision: keep the current file and name. No IDA-safe name repair is warranted because IDA has no function at the start and the documentation name already describes behavior without overstating ownership.

## Negative Evidence Summary

Checked and rejected:

- Direct IDA function object at target or interiors: absent.
- Direct `xrefs_to` target entry, end, sibling starts, and right boundary: absent.
- VA-style little-endian pointer hits to target/interiors: absent in IDA `find_bytes` and raw PE scan.
- RVA-style pointer hits to target/interiors: absent in raw PE scan.
- Direct PE `E8/E9`, `0F 8x`, short conditional, short jump, or loop-style branch to target entry: absent.
- Nearby MapName and MiniMapButton vtables: real control slots are present but none target `0x00503060`.
- MapName-private field access: absent. Sibling [UID:0002BF]'s `this+0x220` evidence does not transfer to this helper.
- Callee ownership through `sub_4B7C50`: rejected because it is broad shared geometry infrastructure.
- Global ownership through `g_useEpfAssets`: rejected because it is a broad process-wide selector.
- Address adjacency to MapName/MiniMap/MainMenu: useful for search priority, insufficient for ownership or emitters.

## Final Recommendation

Exact changes applied:

- Created this research report only.
- No target by-memory file was edited.
- No generated file was edited.
- No `by-memory/-coverage-report.md` edit was made.

Exact parent/emitter assignments recommended:

- Keep [UID:0002BD] `CANONICAL_OWNER:NONE`.
- Keep [UID:0002BD] `EMITTER_UIDS:` blank.
- Keep [UID:0002BD] `EMITTER_POSITION_OPTIONAL:` blank.
- Keep [UID:0002BD] `RECONSTRUCTABLE:TRUE`.
- Keep [UID:0002BD] `RECONSTRUCTION_CPP` blank.
- Keep scores `COMPLETION:87` and `CONFIDENCE:91`.

Exact items left no-owner/non-emitting and why:

- [UID:0002BD] remains no-owner/non-emitting because no direct semantic owner, source-use route, caller, table, vtable slot, or class-field evidence is proven.

Exact current generated row to keep:

```text
| [UID:0002BD][0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper](by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md` |  |
```

Exact `by-memory/-coverage-report.md` row to keep if the supervisor wants an explicit shared-report reference:

```text
        - [UID:0002BD][0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper](by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) 0x00503060-0x005030bc | raw function | UiAssetModeRectVirtualDispatchHelper : reconstructable : 87% : strong : B003 current Goal 2 pass reconfirms source-shaped raw helper body but no owner/emitter route: live IDA session b001_0003gy reports no function object at 0x00503060 or useful interiors, zero entry/end/sibling-start xrefs, only internal branch refs inside the helper, unique wildcarded entry and range signatures, byte_66DA97/RectBounds(0,0,0xa6/0xad,0x10) setup through sub_4B7C50, unconditional vtable slot +0x20 dispatch, no VA/RVA pointer hits to the target or useful interiors, no PE-level E8/E9/0F8x/short-branch target to the entry, no MapName/MiniMapButton vtable slot, and no MapName-private this+0x220 field access. MapName width and sibling 0002BF association remain the best owner lead but are insufficient for canonical ownership or emitter routing.
```

Exact future work outside this assignment:

- If a future runtime trace, table scan, or decompiler recovery identifies a receiver type or callback table for the virtual slot `+0x20`, re-open MapName/MiniMap/MainMenu ownership before creating any new file.
- If a caller proves the helper is deliberately used in more than one source context, consider emitter routes then. No current evidence supports that.

## Follow-Up Actions

- Supervisor actions: none required for target metadata or shared reports. Current rows may remain unchanged.
- A-agent actions: none from this pass.
- B003 future research actions: only revisit if new caller/table/vtable/field evidence appears for `0x00503060`.

## Confidence

- Recommendation confidence: `91`.
- Score confidence: keep target at `87/91`.
- Remaining uncertainty: whether the helper is dead retained code or reachable through an unrecognized indirect registration mechanism. Current static evidence does not expose such a route.

## Validator Results

- Commands run: no validator command was run.
- Reason: this assignment explicitly prohibited direct by-* edits, and the only changed file is this B003 research report under the agent folder. There were no validator-managed target-documentation edits to validate.
- Any unresolved validator warnings/errors: none introduced by this report.

## Lease State

- `current_leases.md` showed no active leases before report creation.
- `leaser.py` rejected a pre-create lease for this new report path with `Rejected[File not found]`.
- A minimal stub was created so the file path existed, then `leaser.py` registered the B003 lease successfully.
- Final state after report write: B003 lease released for this report path; no by-* files were leased or edited.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0002BD-UiAssetModeRectVirtualDispatchHelper-current-no-owner-sweep.md`
- Modified: none outside this report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002BD-UiAssetModeRectVirtualDispatchHelper-current-no-owner-sweep.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0002BD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
