** TARGET-REPORT-UID:0002BE **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BE UiAssetModeRectWriteHelper Fresh No-Owner Pass

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](../../../../../by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) as `CANONICAL_OWNER:NONE`, with blank `EMITTER_UIDS`.
- Final disposition: reconstructable source-authored raw UI rectangle helper, but still no proven declaration owner, source-use route, generated-source emitter, or live reachability route.
- Required action: no metadata change, no score change, no split/merge/reclassification, no IDA-safe rename, no by-memory/-coverage-report.md row replacement, and no C++ entry.
- Confidence: high for the no-change routing decision; the target behavior and unreferenced status are strongly supported, while original source ownership remains unresolved.

## Supporting Research

## Target

- Target UID: `0002BE`
- Target path: `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md`
- Source queue/report row: `auto-generated/-ag-memory-coverage.md` current no-owner/non-emitting row.
- Current supervisor classification: Goal 2 no-owner memory pass target, current generated state `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`.
- Prior report read as evidence only: `Agent-B002/research/executed/0002BE-UiAssetModeRectWriteHelper-current-no-owner-research.md`.
- Live IDA MCP session used: `a001_goal2_class_batch`, IDB `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, imagebase `0x00400000`, auto-analysis ready, Hex-Rays ready.

Current metadata before this pass:

```text
COMPLETION:87
CONFIDENCE:91
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP: blank
```

Recommended metadata after this pass:

```text
COMPLETION:87
CONFIDENCE:91
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP: blank
```

Score before/after:

```text
Before: COMPLETION:87, CONFIDENCE:91
After:  COMPLETION:87, CONFIDENCE:91
```

## Executive Recommendation

Leave the item no-owner/non-emitting. The helper is real source-authored code, but the only current positive semantic lead is a weak MapName-side UI layout association from address locality and the `0x00ad` map-name width. That does not satisfy by-structure ownership rules because current IDA and PE evidence still find no caller, xref, function pointer, vtable slot, table entry, class-private field access, singleton route, or source-use context for `0x005030c0`.

Do not assign the target to [UID:00007P][MapNamePane](../../../../../by-class/MapNamePane.md), [UID:00008B][MiniMapButtonPane](../../../../../by-class/MiniMapButtonPane.md), [UID:0000SW][g_useEpfAssets](../../../../../by-global/g_useEpfAssets.md), [UID:0000N2][RectBounds](../../../../../by-file/RectBounds.md), or the aggregate [UID:00022Z][0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers](../../../../../by-memory/0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md). All are either dependencies, neighbors, consumers, or non-emitting documentation containers, not proven direct owners or emitters for this raw helper.

## Supervisor Active Recheck

The supervisor assigned exactly one current no-owner target: `0002BE` / `0x005030c0-0x00503104.UiAssetModeRectWriteHelper`. The assigned item did not require split repair before final reporting: it is already one exact raw helper child inside the `00022Z` split inventory, with padding on both sides and distinct sibling pages for `0x00503060-0x005030bc` and `0x00503110-0x005031e1`.

No source-bearing child was created or repaired in this pass. The evidence supports preserving the current exact child and reporting no metadata change.

## Inference Research Guidance Check

`by-structure.md` and `inference_research.md` affected the recommendation in three ways:

- Address adjacency and broad mode-global reads are weak evidence. They can start a hypothesis, but they do not prove source ownership.
- A callee relationship to `RectBounds` and a read of `g_useEpfAssets` show dependencies, not ownership.
- A reconstructable page may stay `CANONICAL_OWNER:NONE` and non-emitting when source code is real but no defensible source-output route exists.

Facts, documentation evidence, and inference are separated below. Existing docs and the B002 report were treated as leads; live IDA MCP and raw PE evidence were rechecked independently.

## Evidence Standards Used

Evidence types used:

- IDA MCP `server_health`, `lookup_funcs`, `xrefs_to`, `search_text`, `get_bytes`, `decompile`, and `callees`.
- Raw PE scan for exact byte uniqueness, absolute VA/RVA/push-address references, rel32 and short-branch targets, and nearby vtable dword contents.
- Current project documentation for target metadata, aggregate/child split status, candidate by-class/by-file/by-global parents, and generated coverage state.
- Negative evidence: absence of function object, entry xrefs, raw pointers, calls, branches, vtable slots, table refs, caller routes, and class-private state.

The evidence is strong enough for a no-change recommendation because every plausible owner route currently fails on direct route evidence, while the raw behavior and boundaries remain stable.

## IDA MCP Facts

### Function / Range Facts

Current `lookup_funcs` reports:

| Query | Result |
| --- | --- |
| `0x00503060` | not a function |
| `0x005030bc` | not a function |
| `0x005030c0` | not a function |
| `0x00503104` | not a function |
| `0x00503110` | not a function |
| `0x005031e1` | not a function |
| `0x005031f0` | `sub_5031F0`, size `0xd3` |
| `0x004b7c50` | `sub_4B7C50`, size `0x1f` |
| `0x00502e30` | `sub_502E30`, size `0x22c` |
| `0x005032d0` | `sub_5032D0`, size `0x7d` |
| `0x00503350` | `sub_503350`, size `0x14f` |
| `0x005034a0` | `sub_5034A0`, size `0xd4` |
| `0x00503580` | `sub_503580`, size `0x9e` |
| `0x00503650` | `sub_503650`, size `0x42` |
| `0x005036a0` | `sub_5036A0`, size `0x14d` |
| `0x00503840` | `sub_503840`, size `0xbe` |
| `0x00503900` | `sub_503900`, size `0x5f` |

`get_bytes 0x00503050 size 0x1a0` confirms the cluster layout:

- `0x0050305c-0x00503060`: four `0xcc` bytes before sibling `0002BD`.
- `0x00503060-0x005030bc`: first raw helper sibling.
- `0x005030bc-0x005030c0`: four `0xcc` bytes before this target.
- `0x005030c0-0x00503104`: this target, 68 bytes.
- `0x00503104-0x00503110`: twelve `0xcc` bytes before sibling `0002BF`.
- `0x00503110-0x005031e1`: third raw helper sibling.
- `0x005031e1-0x005031f0`: fifteen `0xcc` bytes before modeled `MapNamePane` constructor.

### Target Behavior Facts

The target bytes decode to:

```asm
005030c0  push    ebp
005030c1  mov     ebp, esp
005030c3  sub     dword ptr [ebp+8], 1
005030c7  jnz     short loc_503100
005030c9  cmp     byte_66DA97, 1
005030d0  push    10h
005030d2  jnz     short loc_5030ec
005030d4  push    0a6h
005030d9  push    0
005030db  push    0
005030dd  push    dword ptr [ebp+0ch]
005030e0  call    sub_4B7C50
005030e5  add     esp, 14h
005030e8  pop     ebp
005030e9  retn    8
005030ec  push    0adh
005030f1  push    0
005030f3  push    0
005030f5  push    dword ptr [ebp+0ch]
005030f8  call    sub_4B7C50
005030fd  add     esp, 14h
00503100  pop     ebp
00503101  retn    8
```

Observed behavior:

- Decrements the first stack argument.
- If the adjusted value is not zero, returns without writing the output rectangle.
- If the adjusted value is zero, compares [UID:0000SW][g_useEpfAssets](../../../../../by-global/g_useEpfAssets.md) / `byte_66DA97` against `1`.
- Writes a caller-provided `RectBounds` through `0x004b7c50` with `(0, 0, 0x00a6, 0x10)` in EPF/current mode or `(0, 0, 0x00ad, 0x10)` otherwise.
- Returns with `retn 8`, so the helper consumes two caller stack arguments.

`decompile 0x004b7c50` confirms the callee writes four explicit rectangle fields:

```c
a1[1] = a3;
*a1 = a2;
a1[3] = a5;
a1[2] = a4;
```

### Xref Facts

Current `xrefs_to` reports:

| Address | Result |
| --- | --- |
| `0x00503060` | zero xrefs |
| `0x005030bc` | zero xrefs |
| `0x005030c0` | zero xrefs |
| `0x00503104` | zero xrefs |
| `0x00503110` | zero xrefs |
| `0x005031e1` | zero xrefs |
| `0x0061e5b4` | MapName vtable head refs from constructor/destructor/scalar destructor |
| `0x0061e600` | MapName secondary vtable head refs from constructor/destructor/scalar destructor |
| `0x0061e630` | MapName tertiary vtable head refs from constructor/destructor/scalar destructor |
| `0x0061e664` | zero direct xrefs to this vtable interior |
| `0x0061e68c` | zero direct xrefs to this vtable interior |

`search_text` scoped to `0x00503000-0x00503200` finds `byte_66DA97` only at:

```text
0x00503079  cmp byte_66DA97, 1
0x005030c9  cmp byte_66DA97, 1
```

These are the two rectangle helper siblings, not proof of a parent class or emitter.

### Nearby Class / Owner Facts

Current decompilation confirms:

- `0x005031f0` constructs `MapNamePane`, writes `g_pMapNamePane`, stores MapName vtables, initializes map-name resource state, and in EPF mode loads `MAPNAME.EPF` and `9X11FONT.BIN` into `this[136]` / offset `0x220`.
- `0x005032d0` frees the same `this[136]` / `0x220` resource and clears `g_pMapNamePane`.
- `0x00503350` renders map-name text and branches on `byte_66DA97`.
- `0x005034a0` handles map-name update opcode `0x15`, converts bytes to UTF-16, clamps/ellipsizes with width `173`, and requests redraw through a vtable path.
- `0x00503580`, `0x00503650`, and `0x005036a0` are MiniMapButtonPane constructor, paint, and mouse/interaction functions.

Those facts support MapName/MiniMapButton ownership for the modeled methods after `0x005031f0`. They do not establish a route to `0x005030c0`.

## PE / Raw Evidence

Read-only PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

```text
ImageBase: 0x00400000
.text:  0x00401000-0x0060c600
.rdata: 0x0060d000-0x0066c200
.data:  0x0066d000-0x0069ce24
.rsrc:  0x0069d000-0x006b2e00
```

Raw scan results:

```text
Exact 0x005030c0-0x00503104 body: 1 hit at 0x005030c0
Entry prefix for this helper: 1 hit at 0x005030c0
Absolute VA refs to 0x00503060/0x005030c0/0x00503110: 0
RVA refs to 0x00503060/0x005030c0/0x00503110: 0
push absolute VA refs to 0x00503060/0x005030c0/0x00503110: 0
rel32 call/jump/near-conditional refs to those starts: 0
short-branch refs to those starts: 0
```

Branch targets into this target are internal only:

```text
0x005030ec: short-branch hits at 0x005030d2 and 0x005030de, both inside target
0x00503100: short-branch hit at 0x005030c7, inside target
```

Nearby vtable window `0x0061e5b4-0x0061e6c4` contains slots for known MapName/MiniMapButton methods:

- MapName examples: `0x0061e5b4 -> 0x00503840`, `0x0061e5f8 -> 0x00503350`, `0x0061e600 -> 0x0050380b`, `0x0061e610 -> 0x005034a0`, `0x0061e630 -> 0x00503816`.
- MiniMapButton examples: `0x0061e63c -> 0x00503900`, `0x0061e680 -> 0x00503650`, `0x0061e688 -> 0x00503821`, `0x0061e68c -> 0x005036a0`, `0x0061e6b8 -> 0x0050382c`.
- No slot points to `0x00503060`, `0x005030c0`, or `0x00503110`.

This PE evidence independently supports the IDA conclusion: no static table, pointer, or branch/call route currently surfaces the target into source output.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0050305c-0x00503060` | [UID:0000VN][-ignored](../../../../../by-memory/-ignored.md) | padding | false | none | 100/strong | no repair |
| `0x00503060-0x005030bc` | [UID:0002BD][UiAssetModeRectVirtualDispatchHelper](../../../../../by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) | sibling raw rect virtual-dispatch helper | true | `NONE` | 87/91 | no-owner/non-emitting |
| `0x005030bc-0x005030c0` | [UID:0000VN][-ignored](../../../../../by-memory/-ignored.md) | padding | false | none | 100/strong | no repair |
| `0x005030c0-0x00503104` | [UID:0002BE][UiAssetModeRectWriteHelper](../../../../../by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) | assigned target; raw output-rect writer | true | `NONE` | 87/91 | keep no-owner/non-emitting |
| `0x00503104-0x00503110` | [UID:0000VN][-ignored](../../../../../by-memory/-ignored.md) | padding | false | none | 100/strong | no repair |
| `0x00503110-0x005031e1` | [UID:0002BF][WideGlyphResourceTextRendererRaw](../../../../../by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md) | sibling raw glyph renderer | true | `00007P` | 87/91 | now assigned to MapNamePane by private field evidence |
| `0x005031e1-0x005031f0` | [UID:0000VN][-ignored](../../../../../by-memory/-ignored.md) | padding | false | none | 100/strong | no repair |
| `0x005031f0-0x0050395f` | [UID:0001AL][MapNameAndMiniMapButtonPanes](../../../../../by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md) | split inventory for modeled MapName/MiniMapButton methods | false | `NONE` | 86/92 | no merge |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005030c0` | zero `xrefs_to`; no PE pointer/branch refs | no caller/source-use route for target |
| `0x005030c9` | scoped listing hit: `cmp byte_66DA97, 1` | dependency on global mode selector |
| `0x005030e0`, `0x005030f8` | calls `0x004b7c50` | dependency on RectBounds initializer |
| `0x005030ec`, `0x00503100` | only internal short-branch targets | no external branch into target body |
| `0x005031f0` | modeled MapName constructor | starts after padding; not a caller of target |
| `0x0061e5b4-0x0061e6c4` | vtable slots for known MapName/MiniMapButton methods, no `0x005030c0` | rejects vtable-emitter route |

The current MCP server listed `callers` in tool discovery but returned `Method 'callers' not found` when invoked. This report therefore relies on `xrefs_to`, decompilation refs, raw PE reference scanning, and vtable bytes for caller/source-use evidence.

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:0002BE][target page](../../../../../by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) already records `87/91`, source-authored behavior, no IDA function object, no direct start xrefs, no raw pointer hits, unique signatures, and no emitter route.
- [UID:00022Z][aggregate](../../../../../by-memory/0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md) is correctly a non-emitting split inventory, not a source owner.
- [UID:0002BD][sibling virtual-dispatch helper](../../../../../by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) shares the mode-selected rectangle constants but also remains no-owner/non-emitting because route evidence is absent.
- [UID:0002BF][sibling glyph renderer](../../../../../by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md) is now assigned to [UID:00007P][MapNamePane](../../../../../by-class/MapNamePane.md), but on different evidence: private `this + 0x220` font-table lifecycle. That evidence does not exist in `0002BE`.
- [UID:00007P][MapNamePane](../../../../../by-class/MapNamePane.md) and [UID:0000L2][MapNamePane](../../../../../by-file/MapNamePane.md) clear the numeric gate but only document modeled MapName methods, vtables, singleton, resource strings, and the `0x005031f0+` island.
- [UID:00008B][MiniMapButtonPane](../../../../../by-class/MiniMapButtonPane.md) and [UID:0000LE][MiniMap](../../../../../by-file/MiniMap.md) clear the numeric gate for MiniMapButton methods, but vtable/resource evidence starts at the modeled button pane methods, not this raw helper.
- [UID:0000SW][g_useEpfAssets](../../../../../by-global/g_useEpfAssets.md) documents the broad mode selector; it is a dependency, not a local owner for every consumer.
- [UID:0000N2][RectBounds](../../../../../by-file/RectBounds.md) and [UID:00015S][RectGeometryHelpers](../../../../../by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md) own the rectangle initializer callee, not this caller/helper.

Existing docs that are stale or incomplete:

- Some older text in [UID:00022Z][aggregate](../../../../../by-memory/0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md) still describes all three children as unassigned, while current `0002BF` metadata is assigned to MapNamePane. This does not change `0002BE` and is not a required repair for this target, but a future aggregate sync may be useful.
- Historical reports mention older `90/90+` or `95/95` code-entry wording. The current active gate is the combined-score plus confirmed-emitter rule.

Generated/coverage report state:

```text
auto-generated/-ag-memory-coverage.md main row: no-owner, `NONE`, blank emitters
auto-generated/-ag-memory-coverage.md no-owner/non-emitting row: present
by-memory/-coverage-report.md row: already states no function object/xrefs/raw pointer hits/PE refs/table evidence and blank owner/emitter route
```

## Ranked Ownership Analysis

### 1. Keep `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`

Evidence for:

- Current IDA has no function object and zero xrefs to the target start.
- Raw PE scan finds no absolute VA, RVA, push-address, rel32 branch/call, near conditional branch, or external short-branch route to the target.
- Nearby vtable scan shows slots for the known MapName/MiniMapButton methods and no slot for `0x005030c0`.
- The helper has no `this` receiver, no class-private field access, no singleton access, no resource literal, no vtable dispatch, and no caller context.
- The aggregate parent is explicitly non-emitting and not a source owner.

Evidence against:

- The body is real, source-shaped, and adjacent to map-name/minimap UI code.
- The `0x00ad` width matches MapName's documented 173-pixel clamp.
- Sibling `0002BF` now has MapName ownership, so the cluster is not meaningless padding.

Decision: accepted. The positive evidence supports preserving the page as reconstructable, but not assigning or emitting it.

### 2. [UID:00007P] MapNamePane / [UID:0000L2] MapNamePane

Evidence for:

- Address locality: the helper sits immediately before the MapNamePane constructor island.
- The target's `0x00ad` width matches the MapName update handler's documented 173-pixel clamp.
- Sibling `0002BF` is now assigned to MapNamePane.

Evidence against:

- No caller, pointer, branch, vtable slot, or table route points to `0x005030c0`.
- Unlike `0002BF`, this target has no `this` pointer and no `this + 0x220` MapName-owned field access.
- MapName vtable slots point to `0x00503350`, `0x005034a0`, `0x0050380b`, `0x00503816`, and `0x00503840`, not to this helper.
- The helper writes a caller-supplied rectangle; without a caller, the caller's object/source context is unknown.

Decision: reject for now. MapName is the strongest forced semantic hypothesis, but not strong enough for `CANONICAL_OWNER:00007P` or `EMITTER_UIDS:00007P`.

### 3. [UID:00008B] MiniMapButtonPane / [UID:0000LE] MiniMap

Evidence for:

- The helper is in the same physical neighborhood as the interleaved MapName/MiniMapButton pane island.
- MiniMapButton has nearby vtable/resource data and is the next class family in the shared island.

Evidence against:

- No MiniMapButton vtable slot points to the target.
- Known MiniMapButton methods start at `0x00503580+`, with direct resource/mouse/singleton evidence absent from `0002BE`.
- The helper does not reference `g_pMiniMapButtonPane`, `MMAPBUT.EPF`, MiniMapButton object state, or MiniMap globals.

Decision: reject.

### 4. [UID:0000SW] g_useEpfAssets / [UID:0000O5] StartupWindow route

Evidence for:

- The target reads `byte_66DA97` / `g_useEpfAssets`.
- The global and its file route are high-confidence and emit-capable.

Evidence against:

- `g_useEpfAssets` has hundreds of readers across many subsystems; a consumer read does not make the global or StartupWindow the owner of every consumer helper.
- The helper is UI layout code, not startup policy.

Decision: reject as canonical owner or emitter.

### 5. [UID:0000N2] RectBounds / `RectBounds.cpp`

Evidence for:

- The target calls the RectBounds initializer `0x004b7c50` twice.
- The target's direct output is a caller-provided `RectBounds`.

Evidence against:

- `0x004b7c50` is a shared utility callee with broad fan-in; caller ownership does not move to the utility source.
- The helper's mode branch and UI extents make it a UI layout helper, not a generic rectangle primitive.

Decision: reject.

### 6. New helper source file or grouping

Evidence for:

- The three raw helpers are adjacent and source-shaped.
- The cluster could represent retained local helper functions from a UI resource/layout source file.

Evidence against:

- No caller/table/source-use context identifies a source file, class, or module name.
- The existing aggregate already covers the cluster as a non-emitting split inventory.
- Creating a standalone emitted helper file would invent a source route and still have no caller to use it.

Decision: reject. No new file/grouping recommendation for this target.

## Negative Evidence Summary

Checked and rejected:

- IDA function object at `0x005030c0`: absent.
- IDA direct xrefs to target start/end/sibling starts: absent.
- Raw PE absolute VA/RVA/push refs to target/sibling starts: absent.
- Raw PE rel32 and external short-branch targets to target/sibling starts: absent.
- Nearby MapName/MiniMapButton vtable slots to target/sibling starts: absent.
- Class-private MapName field evidence: absent for `0002BE`, present only for sibling `0002BF`.
- MiniMapButton singleton/resource evidence: absent for `0002BE`.
- RectBounds ownership: rejected as utility callee dependency.
- `g_useEpfAssets` ownership: rejected as broad mode-selector dependency.
- Merge into neighboring modeled island: rejected by padding boundaries and different route evidence.
- Reclassify as non-reconstructable: rejected because the body is source-authored project helper code.

## Split / Merge / Reclassification Reasoning

- Split: not needed. The target is already an exact 68-byte raw helper child with a single entry, two local returns, and padding on both sides.
- Merge with `0002BD`: not needed. The sibling uses a `this` receiver and vtable slot dispatch; this target writes into a caller-provided output pointer.
- Merge with `0002BF`: not needed. The glyph renderer has different stack-cookie/text-render behavior and now has separate MapName field evidence.
- Merge with `0001AL`: not needed. `0001AL` starts after fifteen bytes of padding and contains modeled MapName/MiniMapButton methods with vtable/singleton evidence.
- Reclassify non-reconstructable: not justified. It is source-shaped UI helper code; the blocker is route evidence, not code authenticity.

## C++ Entry Eligibility

The target satisfies:

```text
RECONSTRUCTABLE:TRUE
(COMPLETION + CONFIDENCE) / 2 = (87 + 91) / 2 = 89 > 85
```

The target fails:

```text
confirmed nonblank EMITTER_UIDS that surface to valid generated source without a dead end
```

C++ entry is therefore not allowed. Do not add or recommend final `RECONSTRUCTION_CPP` for this page unless a future pass proves an emitter route such as a direct class/table/caller source-use path.

## Exact Required Edits

No by-memory, by-file, by-class, by-global, generated, or shared coverage-report edits are required.

No exact `by-memory/-coverage-report.md` replacement row is needed. Retain the current supervisor/shared row:

```markdown
        - [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) 0x005030c0-0x00503104 | raw function | UiAssetModeRectWriteHelper : reconstructable : 87% : strong : A001 Batch310 and B001 second-pass confirm no function object/xrefs/raw pointer hits/section-aware PE-level references/nearby table evidence, exact bytes, unique exact-range and wildcarded-entry signatures, two retn 8 exits at 0x005030e9 and 0x00503101, optional EPF/legacy RectBounds(0,0,0xa6/0xad,0x10) writes through sub_4B7C50 with int_convert-verified extents 166/173/16, output-preserving non-1 state, MapName-width association without direct ownership, and `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS` because no caller/table/source-use emitter route is proven.
```

Retain the generated memory coverage row:

```markdown
| [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` |  |
```

## Follow-Up Actions

Supervisor actions:

- Mark this fresh pass as complete-no-change for `0002BE`.
- No shared coverage-report row replacement is requested.

A-agent actions:

- None required for this target.
- Optional future cleanup: synchronize [UID:00022Z][UnreferencedUiResourceTextHelpers](../../../../../by-memory/0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md) wording with the current `0002BF` MapNamePane assignment when that aggregate is next edited for another reason.

B001 future research actions:

- Reopen `0002BE` only if new evidence appears: a caller, callback table, vtable slot, raw pointer, branch target, or source-use context for `0x005030c0`.

## Confidence

- Recommendation confidence: `89/100`.
- Score confidence: keep existing `87/91`; no score change is justified because current evidence reconfirms the documented facts but does not add a new owner or missing behavior.
- Remaining uncertainty: the helper may have belonged to MapName-side UI layout source in the original project, but current binary evidence does not expose a safe declaration/source-use route.

## Validator Results

- Commands run: none.
- Result: not applicable.
- Reason: no by-* documentation, generated reports, or shared coverage files were changed by this pass. The only created file is this Agent-B001 research report.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0002BE-UiAssetModeRectWriteHelper-fresh-no-owner-pass.md`
- Modified: none by this pass outside Agent-B001 research.
- Renamed: none.
- Moved to executed: none.

## Lease State

No lease was acquired. Per `goal.md`, no lease is required for Agent-B001 research files. No by-* documentation or shared report file was edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002BE-UiAssetModeRectWriteHelper-fresh-no-owner-pass.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002BE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
