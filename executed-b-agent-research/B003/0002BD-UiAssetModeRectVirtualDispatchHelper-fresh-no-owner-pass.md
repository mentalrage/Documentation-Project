** TARGET-REPORT-UID:0002BD **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BD UiAssetModeRectVirtualDispatchHelper Current No-Owner Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002BD] `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md` unchanged.
- Final disposition: `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank `RECONSTRUCTION_CPP`, score `87/91`.
- Required action: no owner, emitter, score, split, merge, rename, reclassification, IDA-safe-name, generated-report, or shared `by-memory/-coverage-report.md` change is justified by this pass.
- Confidence: high for the current no-owner/non-emitting routing decision. The helper is source-shaped project code, but current IDA MCP and PE evidence still expose no caller, table entry, vtable slot, direct branch/call target, pointer, class-private field tie, or generated source-use route.

This is a legitimate reconstructable no-owner/non-emitting item. `MapNamePane` remains the best ownership lead if forced, but the evidence is only associative. It is not strong enough to assign a canonical owner or emitter under the current owner/emitter model.

## Supporting Research

## Target

- Target UID: `0002BD`
- Target path: `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md`
- Address range: `0x00503060-0x005030bc`
- Source queue/report row: `auto-generated/-ag-memory-coverage.md` no-owner row and `tools/leaser/Agents/no_owner_b-agent-tracker.md` active 2026-06-14 no-owner sweep row.
- Current supervisor classification: Goal 2 fresh no-owner memory pass assigned to Agent-B003 on 2026-06-14.
- Current generated state: `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, and no generated output file.
- Current scores and metadata: `COMPLETION:87`, `CONFIDENCE:91`, `RECONSTRUCTABLE:TRUE`, blank reconstruction C++.

Prior report reviewed as historical context only:

- `tools/leaser/Agents/Agent-B003/research/executed/0002BD-UiAssetModeRectVirtualDispatchHelper-current-no-owner-research.md`

## Executive Recommendation

Leave the target no-owner/non-emitting.

The code body at `0x00503060-0x005030bc` is a real source-shaped helper: it receives `this` in `ecx`, optionally creates a local `RectBounds(0, 0, 0xa6/0xad, 0x10)` depending on [UID:0000SW] `g_useEpfAssets`, and calls through `this->vtable + 0x20`. The unresolved part is not behavior; it is source-route evidence. No current evidence identifies the receiver class or an output file route.

`MapNamePane` is the best hypothesis if forced because the helper is adjacent to the MapName/MiniMapButton island and uses the `0xad` width also documented as the 173-pixel MapName clamp. That is still insufficient. Unlike sibling [UID:0002BF], this helper does not read the MapName-owned `this + 0x220` / `this[136]` font-table field, has no MapName vtable slot, and has no caller from the MapName constructor/render/update/destructor family.

Do not enter C++. Although `(87 + 91) / 2 = 89` clears the numeric portion of the active code-entry gate, the required confirmed nonblank emitter route is absent.

## Supervisor Active Recheck

The supervisor assignment asked Agent-B003 to recheck this current generated no-owner/non-emitting target using current documentation and live IDA MCP evidence, and to decide whether it should remain `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS`, gain owner/emitter routing, be split/merged/reclassified, or require repair.

No split repair is needed before final reporting. The target is already an exact child of [UID:00022Z] `0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers`, bounded by `0xcc` padding and neighboring exact helper bodies. Every source-bearing child in the immediate cluster was checked as context; no child creation or target-page repair is required in this pass.

## Inference Research Guidance Check

`by-structure.md` controls the result:

- `CANONICAL_OWNER` must be the correct direct semantic owner, not the nearest address neighbor or broad generated `.cpp` root.
- `EMITTER_UIDS` is output routing. A reconstructable page with no proven route may remain non-emitting.
- Do not set owner, emitters, or C++ just because ownership is plausible.
- Reconstruction C++ requires `RECONSTRUCTABLE:TRUE`, confirmed nonblank emitters that surface to valid generated source, and `(COMPLETION + CONFIDENCE) / 2 > 85`, plus strong source placement/name/dependency evidence.

`inference_research.md` shaped the recommendation by treating address adjacency, shared globals, and broad callee dependencies as leads rather than ownership proof. Current docs and prior reports were useful search guides, but current IDA and PE evidence drove the final decision.

## Evidence Standards Used

Evidence checked:

- Current target page.
- Current parent split inventory [UID:00022Z].
- Sibling pages [UID:0002BE] `UiAssetModeRectWriteHelper` and [UID:0002BF] `WideGlyphResourceTextRendererRaw`.
- Candidate owner docs: [UID:00007P] `MapNamePane`, [UID:0000L2] `MapNamePane`, [UID:00008B] `MiniMapButtonPane`, [UID:0000LE] `MiniMap`, [UID:0000SW] `g_useEpfAssets`, and [UID:00015S] `RectGeometryHelpers`.
- Generated and shared coverage rows.
- Live IDA MCP session `a001_goal2_class_batch`: `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `find_bytes`, `make_signature`, `make_signature_for_range`, `search_text`, `find_regex`, and focused `decompile` checks on neighboring MapName functions.
- Raw PE scans against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for VA/RVA pointers and direct branch/call targets.
- Positive controls in the neighboring MapName/MiniMap island, so negative search results for the target can be weighed against nearby discoverable routes.

The evidence is strong enough to preserve the current no-owner/non-emitting state because both IDA and raw PE can see nearby real method routes, but neither sees a route to this helper.

## IDA MCP Facts

IDA MCP session:

- Session ID: `a001_goal2_class_batch`
- Input path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- IDB path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- Image base: `0x00400000`
- Auto-analysis ready: `true`
- Hex-Rays ready: `true`
- Strings cache ready: `true`
- Strings cache size: `2067`

Function/range facts from `lookup_funcs`:

| Address | IDA result | Meaning |
| --- | --- | --- |
| `0x00502e30` | `sub_502E30`, size `0x22c` | left neighboring modeled function |
| `0x0050305c` | not a function | left alignment before target |
| `0x00503060` | not a function | target entry is raw IDA-missed code |
| `0x00503070` | not a function | target interior |
| `0x00503079` | not a function | `byte_66DA97` compare |
| `0x00503098` | not a function | `sub_4B7C50` call site |
| `0x005030a0` | not a function | internal skip target |
| `0x005030a8` | not a function | virtual dispatch instruction |
| `0x005030bc` | not a function | target end/alignment boundary |
| `0x005030c0` | not a function | sibling [UID:0002BE] raw start |
| `0x00503110` | not a function | sibling [UID:0002BF] raw start |
| `0x005031f0` | `sub_5031F0`, size `0xd3` | MapNamePane constructor positive control |
| `0x00503350` | `sub_503350`, size `0x14f` | MapNamePane render positive control |
| `0x005034a0` | `sub_5034A0`, size `0xd4` | MapNamePane update positive control |
| `0x00503580` | `sub_503580`, size `0x9e` | MiniMapButtonPane constructor positive control |
| `0x00503650` | `sub_503650`, size `0x42` | MiniMapButtonPane paint positive control |
| `0x005036a0` | `sub_5036A0`, size `0x14d` | MiniMapButtonPane mouse positive control |
| `0x00503840` | `sub_503840`, size `0xbe` | MapNamePane deleting destructor positive control |
| `0x00503900` | `sub_503900`, size `0x5f` | MiniMapButtonPane deleting destructor positive control |
| `0x004b7c50` | `sub_4B7C50`, size `0x1f` | shared `RectBounds` initializer dependency |

Target bytes from `get_bytes 0x00503050 size 0x100` confirm:

- The prior modeled function tail ends before `0x0050305c`.
- `0x0050305c-0x00503060` is four `0xcc` bytes.
- Target body begins at `0x00503060` with `55 8b ec 83 ec 14`.
- Target body ends with `c2 04 00` at `0x005030b9`.
- `0x005030bc-0x005030c0` is four `0xcc` bytes.
- Sibling [UID:0002BE] begins at `0x005030c0`.
- Sibling [UID:0002BF] begins at `0x00503110` after twelve `0xcc` bytes.

Target behavior from bytes/disassembly:

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

Behavior interpretation:

- `this` is in `ecx` and is copied to `esi`.
- The stack argument at `[ebp+8]` is decremented.
- A local rectangle is initialized only when the adjusted argument is zero.
- If `byte_66DA97` / [UID:0000SW] `g_useEpfAssets` is `1`, the right edge is `0xa6` / 166.
- Otherwise the right edge is `0xad` / 173.
- Height is `0x10` / 16.
- The helper always dispatches through `[this->vtable + 0x20]` with the local rectangle pointer.
- The non-initializing path still dispatches, leaving the caller contract unresolved.

Xref facts from `xrefs_to`:

| Address | Current xrefs | Meaning |
| --- | --- | --- |
| `0x00503060` | none | no entry route |
| `0x00503070` | internal code xref from `0x0050306d` | no external route |
| `0x00503079` | internal code xref from `0x00503077` | no external route |
| `0x00503098` | internal code xref from `0x00503097` | no external route |
| `0x005030a0` | internal code xrefs from `0x0050309d` and `0x00503077` | internal branch target only |
| `0x005030a8` | internal code xref from `0x005030a6` | virtual dispatch instruction inside body |
| `0x005030bc` | none | no end/padding route |
| `0x005030c0` | none | sibling start unreferenced |
| `0x00503104` | none | sibling end/padding route absent |
| `0x00503110` | none | sibling glyph helper start has no live caller |
| `0x005031e1` | none | no right-boundary route |
| `0x005031f0` | code refs from `0x004f8051`, `0x004f8695` | positive MapName constructor control |
| `0x00503350` | data ref at `0x0061e5f8` | positive MapName vtable control |
| `0x005034a0` | data ref at `0x0061e610` | positive MapName vtable control |
| `0x00503580` | code ref from `0x004f80c2` | positive MiniMapButton constructor control |
| `0x00503650` | data ref at `0x0061e680` | positive MiniMapButton vtable control |
| `0x005036a0` | data ref at `0x0061e68c` | positive MiniMapButton vtable control |
| `0x00503840` | thunk refs plus data ref at `0x0061e5b4` | positive MapName destructor/vtable control |
| `0x00503900` | thunk refs plus data ref at `0x0061e63c` | positive MiniMapButton destructor/vtable control |
| `0x0061e5b4`, `0x0061e600`, `0x0061e630` | constructor/destructor/scalar-destructor stores | MapName vtable heads are real and visible |

Pointer and vtable facts:

- `find_bytes` found zero little-endian VA hits for `0x00503060`, `0x00503070`, `0x00503079`, `0x00503098`, `0x005030a0`, `0x005030a8`, `0x005030bc`, `0x005030c0`, `0x00503104`, `0x00503110`, and `0x005031e1`.
- Positive controls were found for real nearby methods: `0x00503350` at `0x0061e5f8`, `0x005034a0` at `0x0061e610`, `0x00503650` at `0x0061e680`, `0x005036a0` at `0x0061e68c`, `0x00503840` at `0x0061e5b4`, and `0x00503900` at `0x0061e63c`.
- `get_bytes 0x0061e5b4 size 0x150` confirms the MapName/MiniMap vtable/resource range contains those real nearby method pointers but not `0x00503060`.

Signature facts:

- `make_signature 0x00503060`: unique signature `55 8B EC 83 EC 14 A1 ? ? ? ? 33 C5 89 45 ? 83 6D ? ? 56 8B F1 75 ? 80 3D`.
- `make_signature 0x00503079`: unique signature `80 3D ? ? ? ? ? 8D 45 ? 6A 10`.
- `make_signature 0x005030a0`: unique signature `8B 06 8D 4D ? 51 8B CE FF 50 ? ...`.
- `make_signature_for_range 0x00503060-0x005030bc`: unique wildcarded range signature for the whole helper body.

Other IDA facts:

- `search_text` scoped to `0x00503000-0x00503200` finds `byte_66DA97` compares only at `0x00503079` and sibling `0x005030c9`.
- `find_regex '(?i)\.pdb|RSDS|NB10|\.cpp|\.cxx'` returns no source/debug metadata matches in the strings cache.
- Neighboring `MapNamePane` constructor decompilation shows `this[136] = sub_4BB120(&off_61682C, 0x63, ...)` at `0x005032a9`, after a `byte_66DA97` branch and `MAPNAME.EPF` setup. Neighboring destructor decompilation reads and clears `this[136]` at `0x005032f5` / `0x00503326`. This is the private field evidence that supports sibling [UID:0002BF], and it is absent from the target body.

## PE / Raw Executable Evidence

Raw executable:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
```

PE facts:

- Image base: `0x00400000`
- Target VA: `0x00503060`
- Target raw offset: `0x102460`
- `.text`: VA `0x00401000`, VSZ `0x20b4ac`, raw `0x400`, RSZ `0x20b600`
- `.rdata`: VA `0x0060d000`, VSZ `0x5f0be`, raw `0x20ba00`, RSZ `0x5f200`
- `.data`: VA `0x0066d000`, VSZ `0x2fe24`, raw `0x26ac00`, RSZ `0xd800`
- `.rsrc`: VA `0x0069d000`, VSZ `0x15c38`, raw `0x278400`, RSZ `0x15e00`

Raw target bytes:

```text
55 8b ec 83 ec 14 a1 24 2f 67 00 33 c5 89 45 fc
83 6d 08 01 56 8b f1 75 27 80 3d 97 da 66 00 01
8d 45 ec 6a 10 75 07 68 a6 00 00 00 eb 05 68 ad
00 00 00 6a 00 6a 00 50 e8 b3 4b fb ff 83 c4 14
8b 06 8d 4d ec 51 8b ce ff 50 20 8b 4d fc 33 cd
5e e8 79 46 0c 00 8b e5 5d c2 04 00
```

Raw pointer scan results:

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
| `0x00503350` | `0x0061e5f8` / raw `0x21cff8` | none |
| `0x005034a0` | `0x0061e610` / raw `0x21d010` | none |
| `0x00503650` | `0x0061e680` / raw `0x21d080` | none |
| `0x005036a0` | `0x0061e68c` / raw `0x21d08c` | none |
| `0x00503840` | `0x0061e5b4` / raw `0x21cfb4` | none |
| `0x00503900` | `0x0061e63c` / raw `0x21d03c` | none |

Raw branch/call target scan results:

| Target | PE branch/call target hits |
| --- | --- |
| `0x00503060` | none |
| `0x00503070` | none |
| `0x00503079` | none |
| `0x00503098` | none |
| `0x005030a0` | internal short branch from `0x00503077` |
| `0x005030a8` | none |
| `0x005030bc` | none |
| `0x005030c0` | none |
| `0x00503104` | sibling-internal short branch from `0x005030f6` |
| `0x00503110` | none |
| `0x005031e1` | none |
| `0x005031f0` | calls from `0x004f8051` and `0x004f8695` |
| `0x00503580` | call from `0x004f80c2` |
| `0x00503840` | thunk jumps from `0x00503811` and `0x0050381c` |
| `0x00503900` | thunk jumps from `0x00503827` and `0x00503832` |

The PE branch scan finds the expected internal branch and nearby positive controls, but no external branch/call to the target entry.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00502e30-0x0050305c` | left neighboring modeled helper | preceding MainMenu-area code | true | outside scope | current docs | ends before `0xcc` padding |
| `0x0050305c-0x00503060` | [UID:0000VN] `by-memory/-ignored.md` | alignment | false | ignored ledger | current coverage | four `0xcc` bytes |
| `0x00503060-0x005030bc` | [UID:0002BD] target | asset-mode rect virtual-dispatch helper | true | `NONE` | `87/91` | keep no-owner/non-emitting |
| `0x005030bc-0x005030c0` | [UID:0000VN] `by-memory/-ignored.md` | alignment | false | ignored ledger | current coverage | four `0xcc` bytes |
| `0x005030c0-0x00503104` | [UID:0002BE] `UiAssetModeRectWriteHelper` | sibling asset-mode rect writer | true | `NONE` | `87/91` | no-owner/non-emitting context |
| `0x00503104-0x00503110` | [UID:0000VN] `by-memory/-ignored.md` | alignment | false | ignored ledger | current coverage | twelve `0xcc` bytes |
| `0x00503110-0x005031e1` | [UID:0002BF] `WideGlyphResourceTextRendererRaw` | sibling glyph renderer | true | [UID:00007P] MapNamePane | `87/91` | assigned by MapName `this[136]`/font-field evidence |
| `0x005031e1-0x005031f0` | [UID:0000VN] `by-memory/-ignored.md` | alignment | false | ignored ledger | current coverage | fifteen `0xcc` bytes |
| `0x005031f0-0x0050395f` | [UID:0001AL] `MapNameAndMiniMapButtonPanes` | following mixed MapName/MiniMap island | false container | per-child | `86/92` | non-emitting split inventory |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00503060` | no IDA xrefs; no PE pointer; no PE branch/call target | no proven caller, table, or emitter route |
| `0x00503079` | `cmp byte_66DA97, 1` | reads broad asset-mode selector |
| `0x00503098` | call to `sub_4B7C50` | uses `RectBounds` initializer dependency |
| `0x005030a8` | call through `[eax+0x20]` after `eax = [this]` | virtual dispatch but receiver type unknown |
| `0x005031f0` | code refs from `0x004f8051`, `0x004f8695` | MapName constructor positive control absent from target |
| `0x00503350`, `0x005034a0` | vtable entries at `0x0061e5f8`, `0x0061e610` | MapName vtable controls absent from target |
| `0x00503580` | code ref from `0x004f80c2` | MiniMapButton constructor positive control absent from target |
| `0x00503650`, `0x005036a0` | vtable entries at `0x0061e680`, `0x0061e68c` | MiniMapButton vtable controls absent from target |
| [UID:0002BF] | reads MapName font field `this[136]` / offset `0x220` | sibling has direct MapName field evidence; target does not |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target page [UID:0002BD] documents exact range, raw helper behavior, no function object, no direct start xrefs, no pointer hits, no vtable slot, and blank owner/emitter state. Current IDA and PE checks confirm this.
- Parent [UID:00022Z] documents the raw helper cluster as a `RECONSTRUCTABLE:FALSE` split inventory, not a source owner. Current child boundaries and padding agree.
- Sibling [UID:0002BE] has similar rectangle constants and is also no-owner/non-emitting, supporting that `0xa6/0xad` width association alone is not owner proof.
- Sibling [UID:0002BF] is MapName-owned because it uniquely reads the MapName-owned `this[136]` / `this + 0x220` font resource field; this contrast is important negative evidence for `0002BD`.
- [UID:00007P] and [UID:0000L2] prove `MapNamePane` is real, gate-valid, and has constructor/vtable/source-root evidence, but current IDA/PE does not connect this helper to it.
- [UID:00008B] and [UID:0000LE] prove `MiniMapButtonPane`/`MiniMap` are real and gate-valid, but current IDA/PE does not connect this helper to them.
- [UID:0000SW] proves `byte_66DA97` is a broad process-wide UI asset selector, not a local owner of every consumer.
- [UID:00015S] proves `sub_4B7C50` initializes rectangle bounds and has broad helper fan-in, not ownership over callers.

Existing docs that are stale, incomplete, or contradicted:

- No current target or related by-* doc is contradicted by this pass.
- Some historical change logs still mention old `AUTOGEN_PARENT_UID` or older code-entry gates. Current target metadata already uses `CANONICAL_OWNER` / `EMITTER_UIDS`; no in-scope repair is needed.

Generated/coverage report state:

Current generated owner/emitter row in `auto-generated/-ag-memory-coverage.md`:

```markdown
| [UID:0002BD][0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper](by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md` |  |
```

Current generated no-owner queue row:

```markdown
| [UID:0002BD][0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper](by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) | no-owner | `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md` |  |  |  |
```

Current shared coverage row in `by-memory/-coverage-report.md` remains semantically correct. It cites an older MCP session ID but records the same substantive facts reconfirmed here. No supervisor-owned row replacement is required.

## Ranked Ownership Analysis

### 1. Keep `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS`

Evidence for:

- No IDA function object at the helper entry.
- No external IDA xrefs to the entry, useful interiors, end, or sibling starts.
- No raw VA/RVA pointer hits to the entry or useful interiors.
- No PE direct call/jump/branch target to the entry.
- No MapName/MiniMapButton vtable slot to the helper.
- No class-private field access identifying the receiver object.
- The parent aggregate is a non-emitting split inventory, not a source owner.

Evidence against:

- The body is source-shaped and reconstructable.
- It is address-adjacent to MapName/MiniMap code.
- It uses the same `g_useEpfAssets` mode byte and `0xad` width seen in MapName behavior.

Decision:

- Accepted. The positive clues are not sufficient for owner/emitter assignment.

### 2. [UID:00007P] `MapNamePane` / [UID:0000L2] `MapNamePane.cpp`

Evidence for:

- Strongest semantic lead.
- The helper is adjacent to the MapName/MiniMap island.
- The `0xad` right edge is 173, matching the documented MapName clamp.
- [UID:0002BF], the third raw helper in the same physical cluster, has MapName ownership.
- `MapNamePane` and `MapNamePane.cpp` clear the numeric gate at `86/88` and `86/86`.

Evidence against:

- No MapName caller reaches `0x00503060`.
- No MapName vtable slot points to `0x00503060`.
- No VA/RVA pointer or branch target connects MapName code to the helper.
- The target does not read MapName's `this[136]` / `this + 0x220` field, unlike sibling [UID:0002BF].
- The receiver type at the virtual dispatch is unknown.
- Positive controls prove MapName methods and vtables are discoverable in this same IDA/PE pass.

Decision:

- Rejected for now. Best lead if future evidence appears, but not assignable today.

### 3. [UID:00008B] `MiniMapButtonPane` / [UID:0000LE] `MiniMap`

Evidence for:

- The helper is near a mixed MapName/MiniMapButton island.
- MiniMapButtonPane and MiniMap are valid, gate-clearing source candidates.
- MiniMapButtonPane uses EPF assets and UI rectangles elsewhere.

Evidence against:

- No MiniMapButton constructor, paint, mouse, cleanup, or vtable route points to `0x00503060`.
- No singleton, resource literal, or class-private field evidence ties this helper to MiniMapButtonPane.
- Positive controls found real MiniMapButton methods and vtable entries, while the helper remains absent.

Decision:

- Rejected.

### 4. [UID:00019I] MainMenu/Login/Account neighborhood or [UID:0000L1] MainUiGraph

Evidence for:

- The raw cluster sits after a MainMenu-related modeled helper and before the MapName/MiniMap island.
- Main UI initialization constructs MapName and MiniMapButton controls nearby.

Evidence against:

- `0xcc` padding separates the left modeled function from the raw helper.
- No call, branch, pointer, table, or class-state evidence routes from MainMenu/MainUiGraph to `0x00503060`.
- Assigning to a broad UI aggregate would bypass direct-owner rules.

Decision:

- Rejected.

### 5. [UID:0000SW] `g_useEpfAssets` / [UID:0000O5] `StartupWindow`

Evidence for:

- The helper reads `byte_66DA97`, and the global is currently source-owned upward by `StartupWindow`.

Evidence against:

- `g_useEpfAssets` is a broad process-wide selector with hundreds of reads.
- A read of a global dependency does not make that global or its setter file the owner of every consumer.
- No StartupWindow caller/table/field evidence reaches this helper.

Decision:

- Rejected as owner or emitter. Keep as dependency evidence only.

### 6. [UID:00015S] `RectGeometryHelpers` / [UID:0000N2] `RectBounds`

Evidence for:

- The helper calls `sub_4B7C50`, the `RectBounds` initializer.

Evidence against:

- `sub_4B7C50` is a broad shared geometry helper.
- The target is UI control-specific code that consumes rectangle primitives and dispatches to a receiver vtable.
- Callee fan-in does not prove source ownership of callers.

Decision:

- Rejected as owner or emitter. Keep as dependency evidence only.

### Proposed new file/grouping, if applicable

Proposed owner if future evidence appears:

- A narrow helper group such as `UiAssetModeRectHelpers` could cover [UID:0002BD] and [UID:0002BE] only if a future caller/table proves these were shared helper functions outside MapName/MiniMapButton classes.

Likely full contents if proven:

- [UID:0002BD] `UiAssetModeRectVirtualDispatchHelper`
- [UID:0002BE] `UiAssetModeRectWriteHelper`
- Any future discovered callback/caller table that references them

Candidate related items rejected now:

- [UID:0002BF] should not be pulled into a new grouping because it has stronger MapName field evidence.
- [UID:00022Z] should remain a non-emitting split inventory, not become a source file.

Decision:

- Rejected for now. Creating a new source owner would manufacture structure solely to hide missing route evidence.

### Split, merge, reclassify, or rename

Evidence for:

- None.

Evidence against:

- The helper is a single source-shaped body with clear prologue, stack-cookie setup/check, local rect setup, virtual dispatch, `retn 4`, and `0xcc` padding before/after.
- The parent aggregate already splits the local raw helper cluster into exact children.
- It is not padding, not data, not a mixed range, and not compiler/runtime library code.
- The current documentation name describes observed behavior without overstating ownership.

Decision:

- Reject split, merge, reclassification, and rename.

## Negative Evidence Summary

Checked and rejected:

- Direct IDA function object: absent.
- External IDA xrefs to the helper entry: absent.
- PE VA/RVA pointers to entry, useful interiors, target end, and sibling starts: absent.
- PE branch/call targets to entry: absent.
- MapName vtable membership: absent.
- MiniMapButton vtable membership: absent.
- MapName-private `this + 0x220` field access: absent.
- Ownership through `g_useEpfAssets`: rejected as broad global dependency.
- Ownership through `RectBounds`: rejected as broad callee dependency.
- Ownership through address adjacency: rejected because nearby positive controls are visible but do not include this helper.

Evidence that would change the recommendation:

- A caller, callback table, vtable slot, relocation/pointer, runtime trace, or class-private field pattern that identifies the receiver type or source file for the `this->vtable + 0x20` dispatch.

## Final Recommendation

Exact changes applied:

- Created this Agent-B003 research report only.
- No by-* documentation file was edited.
- No generated file was edited.
- No shared coverage report was edited.

Exact target metadata to retain:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Exact generated row to retain:

```markdown
| [UID:0002BD][0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper](by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md` |  |
```

Exact `by-memory/-coverage-report.md` action:

- No replacement required. Retain the current row; this report provides fresher supporting evidence but does not change the coverage status.

Exact item left no-owner/non-emitting:

- [UID:0002BD] remains no-owner/non-emitting because source-authored behavior is documented but no direct semantic owner or generated-output route is proven.

## Follow-Up Actions

- Supervisor actions: none required for target metadata, generated reports, or shared coverage rows.
- A-agent actions: none required from this pass.
- B003 future research actions: revisit only if new caller/table/vtable/field evidence appears for `0x00503060` or the receiver type behind the `+0x20` virtual dispatch.

## Confidence

- Recommendation confidence: high.
- Score confidence: keep `87/91`.
- Before/after scores: unchanged, `87/91 -> 87/91`.
- Before/after routing: unchanged, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank `RECONSTRUCTION_CPP`.
- Remaining uncertainty: whether the helper is dead retained code or reachable through an unrecognized indirect registration/callback mechanism not exposed by current static references.

## Validator Results

- Commands run: none.
- Results: validator not applicable because this pass changed only an Agent-B003 research report and made no validator-managed by-* documentation edits.
- Any unresolved validator warnings/errors: none introduced.
- Dry runs: none used.

## Lease State

- Checked `tools/leaser/Agents/current_leases.md` before report creation: no active leases.
- No lease was required to create this Agent-B003 research-root report under `goal.md`.
- No by-* documentation files were edited, so no by-* leases were acquired or released.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/0002BD-UiAssetModeRectVirtualDispatchHelper-current-no-owner-research.md`
- Modified: none outside this report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002BD-UiAssetModeRectVirtualDispatchHelper-fresh-no-owner-pass.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0002BD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
