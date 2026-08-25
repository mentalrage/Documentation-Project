** TARGET-REPORT-UID:0002BD **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BD UiAssetModeRectVirtualDispatchHelper Ownership / Split Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002BD] `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md` reconstructable and parent-blank. Do not attach it to `MapNamePane`, `MiniMap`, `MiniMapButtonPane`, `MainMenuPane`, `g_useEpfAssets`, `RectBounds`, `Surface`, or a new source file yet.
- Final disposition: exact source-authored raw helper child, nested only under the non-emitting [UID:00022Z] `UnreferencedUiResourceTextHelpers` split inventory. The strongest source-family inference is retained MapName-side UI/resource helper code, but the direct ownership threshold still fails because there is no caller, table, vtable slot, raw VA/RVA pointer, relative branch target, or source metadata tying this start to a source owner.
- Required action: no by-* documentation edit is justified from this B001 pass. No `by-memory/-coverage-report.md` edit is required. Supervisor may mark B001-0002BD complete as "ownership still blocked after B-track review" and retain the current coverage/autogen rows.
- Confidence: `94/100` for target boundary and behavior; `91/100` for the no-assignment recommendation; `76/100` for MapName-source-family as the best non-actionable hypothesis.

## Supporting Research

## Target

- Target UID: `0002BD`
- Target path: `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md`
- Source queue/report row: `auto-generated/-ag-memory-coverage.md`
- Current supervisor classification: `reviewed-85-but-ownership-unknown-under-review`
- Current scores and parent state: `COMPLETION:87`, `CONFIDENCE:91`, `RECONSTRUCTABLE:TRUE`, blank `AUTOGEN_PARENT_UID`
- Active assignment: Agent-B001, Batch `B001-0002BD`, from active `Supervisor_notes.md`

## Executive Recommendation

Best current direct-owner answer: leave parent blank. The helper is not padding, runtime, or compiler-only code; it is a retained source-authored UI helper. It should stay reconstructable, but no current source parent can be assigned under the direct-parent rule.

Best source-family inference if forced: a retained MapName-side map UI/resource helper family, likely adjacent to `MapNamePane.cpp` or private map-name support folded into `MapPane.cpp`. This inference is useful for future search, but it is still weaker than the assignment threshold because the target itself has zero inbound references and the following address island is mixed between `MapNamePane` and `MiniMapButtonPane`.

No split repair is needed. The existing split is already exact:

- [UID:0002BD] `0x00503060-0x005030bc` target rectangle virtual-dispatch helper.
- [UID:0002BE] `0x005030c0-0x00503104` sibling rectangle write helper.
- [UID:0002BF] `0x00503110-0x005031e1` sibling wide-glyph renderer.
- [UID:00022Z] `0x00503060-0x005031e1` non-emitting split inventory.

The exact condition that must change before assignment: a direct or near-direct reference must surface, such as a caller, function-pointer table, vtable slot, raw absolute/RVA pointer, PE-relative call/jump/branch target, source/debug/linker-map clue, or a higher-confidence object-file/source-unit boundary proving the raw helper cluster belongs to a specific source module rather than merely preceding a mixed MapName/MiniMap island.

## Supervisor Active Recheck

The active supervisor row assigns `0002BD` to B001 after A003 Batch307 raised the page to `87/91` but left the parent blank. The B001 task was ownership/source-family inference and split/repair analysis, not routine restatement.

This pass confirms:

- The assigned item does not require a new split; exact children already exist and are gate-clearing.
- The child itself remains well documented at `87/91`; the gap is direct owner evidence, not boundary or behavior quality.
- No related child needed repair before this report. Sibling pages [UID:0002BE] and [UID:0002BF] already document the mode-selected rectangle writer and the wide-glyph renderer at `87/91`.
- The broad parent [UID:00022Z] is correctly non-reconstructable as a split inventory, not a source owner.

## Inference Research Guidance Check

`by-structure.md` requires `AUTOGEN_PARENT_UID` to point to the narrowest true direct semantic owner, not merely a nearby file root or output-routing convenience. It also allows reconstructable project code to remain unassigned when ownership is plausible but not evidence-backed.

`Agent-B001/inference_research.md` pushes against using "no perfect source proof" as a stop sign. I applied that by ranking MapName, MiniMap, MainMenu, shared UI helper, global/callee owners, and a possible new helper file. The conclusion is still no assignment because the positive evidence is source-family association, while every actionable direct-parent path would overclaim.

Existing documentation was treated as a hypothesis. Fresh IDA MCP checks confirmed much of it: the raw starts are non-functions with zero xrefs, MapName/MiniMap vtables contain adjacent real methods but not this helper, MapName update clamps width `0xad` / 173 (verified with `int_convert.py`), and the glyph-render sibling uses the same `this + 0x220` / 544-byte field (verified with `int_convert.py`) initialized by the MapName constructor. The B001 conclusion updates the emphasis: MapName is the best source-family lead, but not a safe parent assignment.

## Evidence Standards Used

- IDA MCP facts: `lookup_funcs`, `xrefs_to`, `disasm`, `decompile`, `get_bytes`, `find_bytes`, `find`, `search_text`, `make_signature`, `make_signature_for_range`, `entity_query`, `server_health`, and `idb_list`.
- Documentation evidence: target/sibling/aggregate by-memory pages, MapNamePane and MiniMap file/class pages, `g_useEpfAssets`, `RectGeometryHelpers`, `SurfaceRenderCallbackTable`, MainMenu packet-helper page, and proposed source tree.
- Negative evidence: no function object, no start xrefs, no VA/RVA byte-pattern references, no nearby vtable slot, no PE-level reference per prior section-aware scans, no caller, no table owner, no stable source metadata.
- Positive inference evidence: local helper clustering, shared `g_useEpfAssets` branch, MapName update width, MapName `this + 0x220` font storage association through sibling [UID:0002BF], and address adjacency immediately before MapName constructor.

## IDA MCP Facts

MCP session facts:

- Active database: `b001_nexustk`.
- Input path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- IDB path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Image base: `0x400000`.
- Hex-Rays ready: true.

Function/range facts:

- `lookup_funcs` reports `0x00503060`, `0x005030bc`, `0x005030c0`, `0x00503104`, `0x00503110`, and `0x005031e1` as not functions.
- Left modeled neighbor: `0x00502e30` -> `sub_502E30`, size `0x22c`, ending at `0x0050305c`.
- Right modeled neighbor: `0x005031f0` -> `sub_5031F0`, size `0xd3`, the `MapNamePane` constructor.
- Shared rectangle initializer: `0x004b7c50` -> `sub_4B7C50`, size `0x1f`.
- `get_bytes 0x00503050 size 0x180` confirms `0xcc` padding at `0x0050305c-0x00503060`, the target body, `0x005030bc-0x005030c0` padding, sibling [UID:0002BE], `0x00503104-0x00503110` padding, and sibling [UID:0002BF].

Target disassembly facts:

- The target has a normal MSVC-shaped prologue and security-cookie setup at `0x00503060`.
- It decrements `[ebp+8]`, saves `ecx` into `esi`, and only initializes a local rectangle when the adjusted argument is zero.
- At `0x00503079` it compares [UID:0000SW] `g_useEpfAssets` / `byte_66DA97` against `1`.
- In EPF/current mode it pushes `0xa6` / 166 (verified with `int_convert.py`); otherwise it pushes `0xad` / 173 (verified with `int_convert.py`). It also pushes `0x10` / 16 (verified with `int_convert.py`) as the bottom edge.
- It calls `sub_4B7C50` at `0x00503098` to initialize a `RectBounds`-style local.
- It always performs `call dword ptr [eax+20h]` at `0x005030a8`, passing the local rectangle pointer and using the receiver vtable slot `+0x20` / 32 (verified with `int_convert.py`).
- It returns with `retn 4` at `0x005030b9`.

Signature and reference facts:

- `make_signature_for_range 0x00503060-0x005030bc` returns a unique range signature:

```text
55 8B EC 83 EC 14 A1 ? ? ? ? 33 C5 89 45 ? 83 6D ? ? 56 8B F1 75 ? 80 3D ? ? ? ? ? 8D 45 ? 6A 10 75 ? 68 A6 00 00 00 EB ? 68 AD 00 00 00 6A 00 6A 00 50 E8 ? ? ? ? 83 C4 14 8B 06 8D 4D ? 51 8B CE FF 50 ? 8B 4D ? 33 CD 5E E8 ? ? ? ? 8B E5 5D C2 04 00
```

- `make_signature 0x00503060` returns a unique wildcarded entry signature:

```text
55 8B EC 83 EC 14 A1 ? ? ? ? 33 C5 89 45 ? 83 6D ? ? 56 8B F1 75 ? 80 3D
```

- `find_bytes` found zero raw byte matches for target and sibling starts as absolute VAs or RVAs: `60 30 50 00`, `60 30 10 00`, `C0 30 50 00`, `C0 30 10 00`, `10 31 50 00`, and `10 31 10 00` all returned `n=0`.
- `find_bytes` found the target entry-pattern once at `0x00503060` and the `byte_66DA97`/`0xa6`/`0xad` branch pattern once at `0x00503079`.
- `xrefs_to` reports zero xrefs to raw starts `0x00503060`, `0x005030c0`, and `0x00503110`.
- `search_text byte_66DA97` in `0x00503000-0x00503200` returns only two local hits: `0x00503079` in the target and `0x005030c9` in sibling [UID:0002BE].
- `find immediate 166` returns 16 total matches and `find immediate 173` returns 23 total matches. The constants are not globally unique; only the local branch pattern is unique.

Vtable/source-family facts:

- `xrefs_to 0x005031f0` reports two constructor code refs from `0x004f8051` and `0x004f8695` inside `sub_4F7D10`.
- `xrefs_to 0x00503350` reports a data ref at `0x0061e5f8`, the MapName render slot.
- `xrefs_to 0x005034a0` reports a data ref at `0x0061e610`, the MapName update-handler slot.
- `xrefs_to` MapName vtable heads `0x0061e5b4`, `0x0061e600`, and `0x0061e630` reports constructor/destructor/scalar-deleting-destructor stores at `0x00503258`, `0x005032fb`, `0x00503872` and corresponding secondary/tertiary stores.
- `xrefs_to` MiniMapButton vtable heads `0x0061e63c`, `0x0061e688`, and `0x0061e6b8` reports constructor/cleanup/destructor stores at `0x005035dc`, `0x00503620`, `0x00503906` and corresponding secondary/tertiary stores.
- `get_bytes 0x0061e5b4 size 0x120` shows MapName and MiniMapButton vtable slots for real nearby functions including `0x00503840`, `0x00503350`, `0x005034a0`, `0x0050380b`, `0x00503816`, `0x00503900`, `0x00503650`, `0x00503821`, `0x005036a0`, and `0x0050382c`. It does not contain `0x00503060`, `0x005030c0`, or `0x00503110`.
- `entity_query` for MapName/MiniMap names returns decorated vtable/RTTI names for `MapNamePane` and `MiniMapButtonPane`; it returns no names for `UiAsset`, `ResourceText`, or the raw helper starts.

MapName positive-association facts:

- Decompiling `0x005031f0` shows the `MapNamePane` constructor installs three `MapNamePane` vtables, clears the display buffer at `this + 0xf8`, checks `byte_66DA97`, calls the resource setup at `0x004d02f0`, and stores a loaded resource pointer at `this[136]`, which is byte offset `0x220` / 544 (verified with `int_convert.py`).
- Disassembling sibling [UID:0002BF] at `0x00503110` shows it reads `[edi+220h]` as the glyph base before calling [UID:0000TN] `SurfaceRenderCallbackTable` slot `dword_69B3E8`.
- Decompiling `0x005034a0` shows the MapName update handler calls `sub_4BA820(..., 173)` after converting incoming map-name bytes to UTF-16. That `173` matches the target's legacy `0xad` right edge.
- Decompiling `0x00503350` shows MapName rendering branches on `byte_66DA97`, using resource-backed rendering in current mode and fallback text/color rendering otherwise.
- Decompiling `0x00503650` shows MiniMapButton painting loads `MMAPBUT` resource data, but it has no `0xa6`/`0xad` rectangle-width or `this + 0x220` glyph-field evidence.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00503060-0x005030bc` | [UID:0002BD] `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md` | optional asset-mode `RectBounds` setup and virtual dispatch | TRUE | blank | `87/91` | current target; no split or parent edit recommended |
| `0x005030c0-0x00503104` | [UID:0002BE] `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` | sibling optional asset-mode `RectBounds` write helper | TRUE | blank | `87/91` | exact sibling; no repair needed |
| `0x00503110-0x005031e1` | [UID:0002BF] `by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md` | sibling wide-glyph resource text renderer | TRUE | blank | `87/91` | strongest MapName association through `this + 0x220`; still unassigned |
| `0x00503060-0x005031e1` | [UID:00022Z] `by-memory/0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md` | split inventory for the three raw helpers | FALSE | blank | `86/90` | correct non-emitting container |
| `0x005031f0-0x0050395f` | [UID:0001AL] `by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md` | mixed MapNamePane/MiniMapButtonPane island | FALSE | blank | `86/92` | following mixed island; not a parent for target |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00503060` | `xrefs_to`: `0` | No direct caller/table/pointer owner for target. |
| `0x005030c0` | `xrefs_to`: `0` | Sibling writer also unreferenced. |
| `0x00503110` | `xrefs_to`: `0` | Sibling glyph renderer also unreferenced despite MapName field association. |
| `0x005031f0` | code refs `0x004f8051`, `0x004f8695` | Normal construction evidence begins at MapName constructor, after the raw cluster. |
| `0x00503350` | data ref `0x0061e5f8` | MapName render vtable slot; does not point to target. |
| `0x005034a0` | data ref `0x0061e610` | MapName update-handler vtable slot; does not point to target. |
| `0x0061e5b4`, `0x0061e600`, `0x0061e630` | MapName vtable store refs from constructor/destructor/deleting destructor | Confirms MapName tables and owner methods, but not raw helper membership. |
| `0x0061e63c`, `0x0061e688`, `0x0061e6b8` | MiniMapButton vtable store refs from constructor/cleanup/destructor | Confirms MiniMapButton tables and owner methods, but not raw helper membership. |
| `0x004b7c50` | target callee | Shared rectangle initializer with broad fan-in; callee does not prove owner. |
| `0x0066da97` | target data ref at `0x00503079` | Broad EPF/current-layout selector; consumer evidence only. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:0002BD] target page already records no IDA function object, no xrefs, PE no-reference scans, no nearby vtable slot, exact behavior, and blank parent. Fresh MCP confirms these facts and adds unique target signatures.
- [UID:0002BE] and [UID:0002BF] sibling pages already document the same unreferenced raw-start problem. Fresh MCP confirms the local cluster shape.
- [UID:00022Z] aggregate correctly classifies itself as a non-emitting split inventory. Fresh evidence supports keeping that disposition.
- [UID:00007P] and [UID:0000L2] MapNamePane docs are confirmed by fresh decompilation for vtable stores, `byte_66DA97` use, `this + 0x220` resource storage, and `173` width clamp.
- [UID:00008B] and [UID:0000LE] MiniMap/MiniMapButton docs are confirmed for vtables, constructor, paint, and `MMAPBUT` resource use; they do not acquire new evidence for the target.
- [UID:00022Y] MainMenu helper docs show the left neighbor is strongly MainMenu-owned and ends at `0x0050305c`, with four `0xcc` bytes before the target.
- [UID:0000SW] `g_useEpfAssets` confirms `byte_66DA97` is a broad process-wide selector with 366 xrefs and StartupWindow setter ownership, so target reads do not prove local ownership.
- [UID:00015S] `RectGeometryHelpers` confirms `0x004b7c50` is a broad rectangle initializer; target calls are dependency evidence, not source-owner evidence.
- [UID:0000TN] `SurfaceRenderCallbackTable` confirms sibling [UID:0002BF]'s `dword_69B3E8` callback is broad render infrastructure, not a MapName-owner proof by itself.

Existing docs that remain uncertain but not contradicted:

- `MapNamePane.md` says the final source split may be standalone `MapNamePane.cpp` or private in `MapPane.cpp`. Fresh IDA does not resolve this.
- `MiniMap.md` says `MiniMapButtonPane` may live in compact `MiniMap.cpp` or a focused minimap source. Fresh IDA does not resolve this.
- The raw cluster may be retained old source from the same object/source neighborhood as MapNamePane. Fresh IDA makes this plausible, but not actionable.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` lists [UID:0002BD] as `unassigned`, with no parent and no emitted code. That remains correct.
- `by-memory/-coverage-report.md` currently records the target as reconstructable with strong evidence and blank parent. That row remains correct.

## Ranked Ownership Analysis

### 1. Parent-blank retained source-authored raw helper under [UID:00022Z]

Evidence for:

- IDA MCP confirms a real function-shaped source body with MSVC prologue/epilogue, security-cookie setup/check, project data/callee references, and a virtual dispatch.
- The exact target range and signatures are unique.
- The raw start has zero xrefs and no VA/RVA byte-pattern hits; sibling starts are the same.
- The existing [UID:00022Z] aggregate is purpose-built as a non-emitting split inventory for the exact raw helper cluster and already clears `86/90`.
- No direct source parent clears both the evidence and correctness tests.

Evidence against:

- This is not an original source owner. It is a documentation container.
- It does not solve final source-file placement; it only prevents a false parent assignment.

Decision: accepted current disposition. Keep parent blank and retain [UID:00022Z] only as documentation nesting.

### 2. [UID:0000L2] `MapNamePane` / [UID:00007P] `MapNamePane`

Evidence for:

- The raw helper cluster is immediately before the `MapNamePane` constructor at `0x005031f0`, separated by only `0xcc` padding.
- Target and sibling [UID:0002BE] use the same `g_useEpfAssets` current/legacy branch pattern as MapName constructor/render code.
- Target and sibling [UID:0002BE] use the `0xa6` / 166 and `0xad` / 173 rectangle-width pair; MapName update uses `173` as the display clamp.
- Sibling [UID:0002BF] reads `this + 0x220`; fresh decompilation confirms MapName constructor stores a resource pointer at byte offset `0x220` / 544.
- `MapNamePane` file/class pages both clear the numeric gate (`86/86` and `86/88`).
- No other candidate has stronger semantic alignment.

Evidence against:

- `xrefs_to 0x00503060` is empty. No caller from `MapNamePane` reaches the target.
- MapName vtables have slots for known MapName methods, including `0x00503350` and `0x005034a0`; none point to `0x00503060`, `0x005030c0`, or `0x00503110`.
- `find_bytes` found no raw VA/RVA pointer to the target; prior section-aware PE scans found no absolute/RVA/relative call/jump/branch target.
- The target's outgoing virtual call through receiver slot `+0x20` does not identify the receiver type. If anything, it proves the helper delegates to some pane/interface method, not that the helper itself is a MapName method.
- The following address island is not pure MapName; it interleaves MapNamePane and MiniMapButtonPane methods, and the file split between `MapNamePane.cpp`, `MiniMap.cpp`, and possible `MapPane.cpp` private code remains open.
- `g_useEpfAssets` and `0xa6`/`0xad` are association evidence, not declaration ownership. Immediate constants `166` and `173` occur elsewhere in the binary.

Decision: strongest source-family hypothesis, but rejected as an actionable direct parent for [UID:0002BD]. Do not set `AUTOGEN_PARENT_UID:0000L2` or `00007P`.

### 3. New `MapNameResourceTextHelpers.cpp` / `MapNameUiResourceTextHelpers` grouping

Evidence for:

- A plausible original source grouping could contain the three raw helpers:
  - `0x00503060-0x005030bc` virtual-dispatch rectangle helper.
  - `0x005030c0-0x00503104` rectangle write helper.
  - `0x00503110-0x005031e1` 9x11 wide-glyph renderer.
- The likely contents would be old/current resource layout helpers for map-name UI text, perhaps retained after the current MapNamePane render path changed.
- A new grouping would explain why the functions remain source-shaped but unreferenced: they may be unused file-local helpers preserved by linker behavior.

Evidence against:

- No debug/source metadata, direct caller, string owner, table, vtable, or object-file boundary proves a separate helper source file.
- A new source file with only orphaned functions would be speculative and would duplicate the existing non-emitting [UID:00022Z] container.
- If the helpers were original file-local statics, they more likely lived near MapName/MapPane source than in a standalone file. The proposed source tree has `MapNamePane.cpp`, `MapPane.cpp`, and `MiniMap.cpp`, not a resource-text helper file.
- Creating a by-file parent would give autogen a source-owner claim stronger than the evidence.

Decision: reject creating a new source file now. If future evidence appears, the likely grouping should be narrow and MapName/MapPane-adjacent, not a broad UI/render utility.

### 4. [UID:0000LE] `MiniMap` / [UID:00008B] `MiniMapButtonPane`

Evidence for:

- The target is adjacent to the shared `MapNamePane`/`MiniMapButtonPane` island.
- `MiniMapButtonPane` has nearby vtables and resource string `MMAPBUT.EPF`.
- `MiniMap` and `MiniMapButtonPane` both clear the numeric gate (`85/86`).

Evidence against:

- Target behavior has no `MMAPBUT`, minimap button state, mouse, singleton, or minimap-specific resource use.
- The `0xa6`/`0xad` width pair and sibling `this + 0x220` glyph field align better with MapName than MiniMapButton.
- MiniMapButton vtables do not contain any raw helper starts.
- `xrefs_to` raw starts remains zero.

Decision: reject as direct parent. MiniMap is a neighboring mixed-island candidate, not the best target owner.

### 5. [UID:0000L0] `MainMenuPane`

Evidence for:

- The left neighbor `0x00502e30-0x0050305c` belongs to MainMenu ANSI text/dialog packet helpers.
- The target follows that range in address order.

Evidence against:

- Four `0xcc` bytes separate the MainMenu helper end from the target start.
- MainMenu ownership is supported by direct caller evidence in the server-message handler; the raw target has no comparable caller.
- Target behavior is rectangle/resource-mode dispatch, not MainMenu packet parsing or URL alert construction.
- Fresh and prior scans find no MainMenu references to the raw start.

Decision: reject. Address adjacency across a padding boundary is weaker than behavior and xref evidence.

### 6. [UID:0000O5] `StartupWindow` / [UID:0000SW] `g_useEpfAssets`

Evidence for:

- The target reads `byte_66DA97`.
- `g_useEpfAssets` is now assigned to `StartupWindow` as the sole observed writer/source-owner inference.

Evidence against:

- `g_useEpfAssets` has hundreds of reads across UI/render/map code; a read is consumer evidence only.
- The target does not write the global and is not in StartupWindow code.
- The target's role is local layout/resource dispatch, not startup/update policy.

Decision: reject. Keep `g_useEpfAssets` as a dependency reference only.

### 7. [UID:0000N2] `RectBounds` / [UID:00015S] `RectGeometryHelpers`

Evidence for:

- Target calls `sub_4B7C50`, documented as `InitRectBounds`.
- Target behavior constructs a `RectBounds`-style local.

Evidence against:

- `InitRectBounds` has very broad fan-in and is a generic geometry primitive.
- The target is a UI helper using rectangles, not part of the geometry helper island.
- No code or data ref points from RectBounds to the target.

Decision: reject. `RectBounds` is a callee dependency, not owner.

### 8. [UID:0000OC] `Surface` / [UID:0000TN] `SurfaceRenderCallbackTable`

Evidence for:

- Sibling [UID:0002BF] dispatches through `dword_69B3E8`, a surface render callback.
- The target cluster is UI/resource-rendering adjacent.

Evidence against:

- The target itself does not call the surface render table.
- `dword_69B3E8` is broad render infrastructure with many callers, not local ownership.
- Surface ownership would ignore the MapName width/font associations.

Decision: reject for the target. Mention only as a sibling dependency.

### 9. Compiler/runtime/padding/ignored

Evidence for:

- IDA did not create a function object for the target start.
- The helper is unreferenced.

Evidence against:

- The body is source-shaped project code, not padding: normal prologue, security-cookie use, branch logic, global read, project helper call, virtual dispatch, and `retn 4`.
- The byte range is not all `0xcc` and is not a known CRT/security-cookie helper itself.
- The exact child is already documented as reconstructable and unique.

Decision: reject ignored/runtime classification. Keep `RECONSTRUCTABLE:TRUE`.

## Negative Evidence Summary

Checked and rejected:

- IDA function object: none at target or sibling starts.
- Direct xrefs to raw starts: zero.
- Raw byte references to VA/RVA forms of raw starts: zero for target and siblings.
- Nearby MapName/MiniMapButton vtable membership: no raw helper start appears in the vtable bytes.
- Direct caller from MapName/MiniMap/MainMenu: none.
- Assignment through outgoing vtable call: rejected because `[eax+20h]` is a callee dispatch, not a reference to the helper or a receiver-type proof.
- Ownership through `g_useEpfAssets`: rejected because the global is broad and target is only a consumer.
- Ownership through `RectBounds`: rejected because `InitRectBounds` is a generic callee with broad fan-in.
- Ownership through `SurfaceRenderCallbackTable`: rejected for target; only the sibling glyph renderer calls a render callback.
- New source file: rejected because no source metadata or broader contents justify it beyond the existing [UID:00022Z] non-emitting container.

The strongest remaining positive evidence is MapName-family association. It is enough to guide future research, but not enough to set a direct parent.

## Final Recommendation

Exact changes applied or recommended:

- Applied: created this research report only.
- Recommended: no by-* documentation changes.
- Recommended: no split/rename/reclassify changes.
- Recommended: keep [UID:0002BD] `RECONSTRUCTABLE:TRUE`, score `87/91`, blank `AUTOGEN_PARENT_UID`, blank `RECONSTRUCTION_CPP CODE`.
- Recommended: keep [UID:00022Z] as `RECONSTRUCTABLE:FALSE` non-emitting split inventory.

Exact parent assignments recommended:

- None.

Exact items left unassigned and why:

- [UID:0002BD] remains unassigned because no direct source parent is proven.
- [UID:0002BE] and [UID:0002BF] remain useful sibling leads but do not make [UID:0002BD] assignable.
- [UID:00022Z] remains unassigned because it is a by-memory inventory, not a source owner.

Exact future work outside this assignment:

- If another agent later finds an object-file/source-unit boundary, linker map, PDB, callback registration table, or hidden indirect reference for any raw start in `0x00503060-0x005031e1`, rerun the assignment decision for all three children together.
- If a MapName/MapPane helper grouping is created later, it should explicitly include or reject [UID:0002BD], [UID:0002BE], and [UID:0002BF] as a set. Do not assign only one based on this report.

## Coverage / Autogen Rows For Supervisor

No `by-memory/-coverage-report.md` edit is required. Retain the current row exactly:

```text
        - [UID:0002BD][0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper](by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) 0x00503060-0x005030bc | raw function | UiAssetModeRectVirtualDispatchHelper : reconstructable : 87% : strong : A003 Batch307 reconfirms no IDA function object/xrefs/raw pointer hits/PE-level absolute-VA/RVA/relative references/MapName-or-MiniMapButton-adjacent vtable slot, exact bytes through retn 4, stack-cookie body, data refs to g_useEpfAssets and security cookie, optional EPF/legacy RectBounds(0,0,0xa6/0xad,0x10) setup through sub_4B7C50, unconditional vtable slot +0x20 dispatch, MapName-width association without direct ownership, non-initializing state caveat, and blank parent because no caller/vtable/table owner is proven.
```

No `auto-generated/-ag-memory-coverage.md` edit is required; it is generated and should remain as produced by validator. Current generated row is:

```text
| [UID:0002BD][0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper](by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) | unassigned |  |  | no |  | `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md` |  |
```

If the supervisor wants to record the B001 result in `Supervisor_notes.md`, the exact disposition should be:

```text
complete-or-reclassified; B001-0002BD complete. B001 recommends no by-* docs or coverage row edits: keep [UID:0002BD] reconstructable, parent blank, and nested only under non-emitting [UID:00022Z]. Best source-family hypothesis is MapName-side retained UI/resource helper code, but direct assignment remains blocked by zero xrefs/callers/raw VA-RVA refs/vtable slots/table owner/source metadata.
```

## Follow-Up Actions

Supervisor actions:

- Mark B001-0002BD complete after review.
- Do not edit `by-memory/-coverage-report.md` for this report unless policy requires appending B001 provenance; no technical row change is needed.
- Do not set `AUTOGEN_PARENT_UID` on [UID:0002BD].

A-agent actions:

- No immediate A-agent repair is required.
- Future MapName/MapPane audits should include the entire [UID:00022Z] raw helper cluster as a source-family lead.
- Future MiniMap audits should not absorb this target based only on address adjacency.

B001 future research actions:

- If a future backlog item targets [UID:0002BE], [UID:0002BF], or [UID:00022Z] again, start from this report and look for new indirect-reference evidence rather than repeating the direct-xref checks.
- If project tooling gains object-file boundary or linker-map evidence, revisit whether a MapName/MapPane private helper parent can be justified.

## Confidence

- Boundary and behavior confidence: `94/100`. Multiple IDA and PE checks plus fresh unique signatures confirm exact range, body, and unreferenced status.
- No-assignment confidence: `91/100`. Every plausible direct parent lacks the necessary direct-owner evidence, and assigning to one would conflict with by-structure rules.
- MapName source-family hypothesis: `76/100`. The local width, `byte_66DA97`, `this + 0x220` sibling association, and address adjacency make MapName the best lead, but not a direct owner.
- Rejection of MiniMap direct ownership: `86/100`.
- Rejection of MainMenu direct ownership: `89/100`.
- Rejection of runtime/padding classification: `95/100`.
- Remaining uncertainty: whether the three raw helpers are unused retained source from a MapName/MapPane object file, reachable through an unrecognized runtime mechanism, or remnants of an older UI resource helper path whose registration/reference was removed before this build.

## Validator Results

Commands run:

> Executable block R001 was removed from this report and preserved verbatim in [0002BD-UiAssetModeRectVirtualDispatchHelper-B001-0002BD-removed.md](0002BD-UiAssetModeRectVirtualDispatchHelper-B001-0002BD-removed.md). The archived block is non-authoritative and must not be executed.

Result summary:

- `apply: False`
- `scanned markdown files: 1`
- `ok: 1`
- Target result: `ok 0002BD by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md UID header exists`
- Generated reports: `auto-generated/-ag-*-coverage.md unchanged`
- Noted validator noise: one existing `autogen_parent_has_no_code 00000D by-class/Application.md emitting children only`; unrelated to this target.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0002BD-UiAssetModeRectVirtualDispatchHelper-B001-0002BD.md`
- Modified: none outside this B001 research report.
- Renamed: none.
- Moved to executed: none; supervisor owns execution/move.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002BD-UiAssetModeRectVirtualDispatchHelper-B001-0002BD.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002BD"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002BD-UiAssetModeRectVirtualDispatchHelper-B001-0002BD-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0002BD-UiAssetModeRectVirtualDispatchHelper-B001-0002BD.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002BD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
