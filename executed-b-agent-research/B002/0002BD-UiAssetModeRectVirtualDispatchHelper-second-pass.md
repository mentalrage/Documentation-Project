** TARGET-REPORT-UID:0002BD **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BD UiAssetModeRectVirtualDispatchHelper Second-Pass Ownership / Emitter Report

## Final Recommendation

Keep [UID:0002BD][0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper](../../../../../by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) as:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
```

No split, merge, IDA metadata repair, canonical-owner assignment, emitter assignment, score change, source-routing change, or `by-memory/-coverage-report.md` edit is required.

Second-pass score recommendation: keep `COMPLETION:87`, `CONFIDENCE:91`. The helper is source-authored project code and remains reconstructable, but no direct semantic owner or source-emitter route clears the current owner/emitter gate. It also does not clear the active reconstruction-code entry bar: completion is below `90`, and the owner/emitter route, caller contract, source placement, and dependencies are not sufficiently verified.

## Required Supervisor Actions

Required by-memory metadata/header changes: none.

Required `auto-generated/-ag-memory-coverage.md` routing state: retain the current no-owner row.

```text
| [UID:0002BD][0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper](by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md` |  |
```

Required `by-memory/-coverage-report.md` row change: none. The current row is still accurate. If the supervisor wants to refresh the audit note with this B002 second-pass evidence, this is the exact replacement row:

```text
        - [UID:0002BD][0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper](by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) 0x00503060-0x005030bc | raw function | UiAssetModeRectVirtualDispatchHelper : reconstructable : 87% : strong : B002 second-pass reconfirms source-shaped raw helper body but no owner/emitter route: live IDA session b001_0003gy reports no function object at 0x00503060, no external xrefs to the entry/end/sibling starts, only internal branch refs inside the helper, unique exact and wildcarded signatures, data refs only to security cookie and g_useEpfAssets, optional RectBounds(0,0,0xa6/0xad,0x10) setup through sub_4B7C50, unconditional vtable slot +0x20 dispatch, no VA/RVA pointer hits to the target or useful interiors, no PE-level E8/E9/0F8x/short-branch target to the entry, and no MapName/MiniMapButton vtable slot. MapName width and sibling-glyph associations remain insufficient for canonical ownership or emitter routing.
```

## Assignment Context

- Assignment: `B002-0002BD-second-pass`
- Target: [UID:0002BD] `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md`
- Coverage source: `auto-generated/-ag-memory-coverage.md`
- Prior evidence report reviewed: `tools/leaser/Agents/Agent-B001/research/executed/0002BD-UiAssetModeRectVirtualDispatchHelper-post-migration.md`
- Current generated state: reconstructable `no-owner`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`
- Current target score: `87/91`
- Current parent aggregate: [UID:00022Z][0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers](../../../../../by-memory/0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md), `RECONSTRUCTABLE:FALSE`, non-emitting split inventory

The prior B001 post-migration report was treated as prior evidence, not as a conclusion to accept. This pass rechecked live IDA and executable bytes on 2026-06-13.

## Evidence Summary

The target is a unique, source-shaped raw helper:

- Entry bytes begin at `0x00503060` with an MSVC-style prologue and stack-cookie setup.
- The helper saves `ecx` into `esi`, so it uses `thiscall` receiver semantics.
- It decrements the stack argument; only the adjusted-zero path initializes a local rectangle.
- It reads [UID:0000SW][g_useEpfAssets](../../../../../by-global/g_useEpfAssets.md) / IDA `byte_66DA97`.
- It calls [UID:00015S][RectGeometryHelpers](../../../../../by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md) `sub_4B7C50`, documented as `InitRectBounds`, with `(0, 0, 0xa6, 0x10)` or `(0, 0, 0xad, 0x10)`.
- It always dispatches through `[this->vtable + 0x20]` with the local rectangle pointer.
- It returns with `retn 4` at `0x005030b9`.

The target remains unrouteable:

- No IDA function object exists at `0x00503060`.
- No external xref reaches `0x00503060`.
- No raw VA/RVA pointer exists for the target entry, useful interiors, or sibling raw starts.
- No section-aware PE direct call/jump/conditional branch reaches the target entry.
- Nearby MapName/MiniMapButton vtables contain real adjacent methods but not the target.
- The target does not access the `MapNamePane +0x220` private resource field that justified routing sibling [UID:0002BF].

## IDA MCP Evidence

### Session

Live MCP session:

| Field | Value |
| --- | --- |
| Session | `b001_0003gy` |
| Input path | `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` |
| IDB path | `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64` |
| Image base | `0x400000` |
| Auto-analysis | ready |
| Hex-Rays | ready |

### Function Boundary Checks

`lookup_funcs` confirms:

| Query | Result |
| --- | --- |
| `0x00502e10` | `sub_502E10`, size `0x11` |
| `0x00502e30` | `sub_502E30`, size `0x22c` |
| `0x0050305c` | not a function |
| `0x00503060` | not a function |
| `0x005030bc` | not a function |
| `0x005030c0` | not a function |
| `0x00503104` | not a function |
| `0x00503110` | not a function |
| `0x005031e1` | not a function |
| `0x005031f0` | `sub_5031F0`, size `0xd3` |
| `0x005032d0` | `sub_5032D0`, size `0x7d` |
| `0x00503350` | `sub_503350`, size `0x14f` |
| `0x005034a0` | `sub_5034A0`, size `0xd4` |
| `0x00503580` | `sub_503580`, size `0x9e` |
| `0x00503650` | `sub_503650`, size `0x42` |
| `0x005036a0` | `sub_5036A0`, size `0x14d` |
| `0x004b7c50` | `sub_4B7C50`, size `0x1f` |

`entity_query` over `0x00502e00-0x00503980` reports 18 modeled functions: `0x00502e10`, `0x00502e30`, `0x005031f0`, `0x005032d0`, `0x00503350`, `0x005034a0`, `0x00503580`, `0x00503620`, `0x00503650`, `0x005036a0`, `0x005037f0`, `0x00503800`, `0x0050380b`, `0x00503816`, `0x00503821`, `0x0050382c`, `0x00503840`, and `0x00503900`. It does not report a function at any raw helper start in `0x00503060-0x005031e1`.

### Xrefs

`xrefs_to` results:

| Address | Xrefs | Decision impact |
| --- | ---: | --- |
| `0x00503060` | 0 | No direct caller, table, vtable, or pointer owner for target entry. |
| `0x00503070` | 1 internal ref from `0x0050306d` | Internal flow only. |
| `0x00503079` | 1 internal ref from `0x00503077` | Internal flow only. |
| `0x00503098` | 1 internal ref from `0x00503097` | Internal call-site flow only. |
| `0x005030a0` | 2 internal refs from `0x0050309d` and `0x00503077` | Internal flow only. |
| `0x005030a8` | 1 internal ref from `0x005030a6` | Internal virtual-call instruction only. |
| `0x005030bc` | 0 | No alternate end/padding reference. |
| `0x005030c0` | 0 | Sibling rectangle writer remains unreferenced. |
| `0x00503110` | 0 | Sibling glyph renderer remains unreferenced at the entry. |
| `0x0061e5b4` | 3 | MapName vtable stores from MapName constructor/destructor/deleting destructor. |
| `0x0061e600` | 3 | MapName secondary vtable stores. |
| `0x0061e630` | 3 | MapName tertiary vtable stores. |
| `0x0061e664` | 0 | No extra table-head owner for the raw target. |
| `0x0061e68c` | 0 | Address is a MiniMapButton method slot value, not a target owner. |

Interior xrefs do not prove an external entry mechanism; they are all local branch/call flow inside the raw helper.

### Target Disassembly

`disasm 0x00503060` succeeds even though IDA has no function object. Key instructions:

```asm
503060  push    ebp
503061  mov     ebp, esp
503063  sub     esp, 14h
503066  mov     eax, ___security_cookie
503070  sub     dword ptr [ebp+8], 1
503075  mov     esi, ecx
503077  jnz     short loc_5030A0
503079  cmp     byte_66DA97, 1
503083  push    10h
503087  push    0A6h
50308e  push    0ADh
503098  call    sub_4B7C50
5030a0  mov     eax, [esi]
5030a5  push    ecx
5030a6  mov     ecx, esi
5030a8  call    dword ptr [eax+20h]
5030b1  call    @__security_check_cookie@4
5030b9  retn    4
5030bc  align   10h
```

`search_text byte_66DA97` over `0x00503000-0x00503200` found exactly two hits:

| Address | Context |
| --- | --- |
| `0x00503079` | target [UID:0002BD] |
| `0x005030c9` | sibling [UID:0002BE] |

This proves the target and sibling rectangle writer share the EPF/current-mode branch. It does not prove a common source owner.

### Signatures And Bytes

`make_signature_for_range 0x00503060-0x005030bc`:

| Mode | Unique | Signature |
| --- | --- | --- |
| exact bytes | true | `55 8B EC 83 EC 14 A1 24 2F 67 00 33 C5 89 45 FC 83 6D 08 01 56 8B F1 75 27 80 3D 97 DA 66 00 01 8D 45 EC 6A 10 75 07 68 A6 00 00 00 EB 05 68 AD 00 00 00 6A 00 6A 00 50 E8 B3 4B FB FF 83 C4 14 8B 06 8D 4D EC 51 8B CE FF 50 20 8B 4D FC 33 CD 5E E8 79 46 0C 00 8B E5 5D C2 04 00` |
| wildcarded operands | true | `55 8B EC 83 EC 14 A1 ? ? ? ? 33 C5 89 45 ? 83 6D ? ? 56 8B F1 75 ? 80 3D ? ? ? ? ? 8D 45 ? 6A 10 75 ? 68 A6 00 00 00 EB ? 68 AD 00 00 00 6A 00 6A 00 50 E8 ? ? ? ? 83 C4 14 8B 06 8D 4D ? 51 8B CE FF 50 ? 8B 4D ? 33 CD 5E E8 ? ? ? ? 8B E5 5D C2 04 00` |

`get_bytes 0x00503050 size 224` confirms the target body, the `0x005030bc-0x005030c0` `0xcc` padding, sibling [UID:0002BE], the `0x00503104-0x00503110` `0xcc` padding, and the start of sibling [UID:0002BF].

`get_bytes 0x0061e5b4 size 304` confirms nearby MapName/MiniMapButton vtable regions contain real adjacent method entries, including `0x00503350`, `0x005034a0`, `0x00503650`, and `0x005036a0`, then resource strings. They do not contain `0x00503060`.

`find_bytes` pointer-pattern sanity checks:

| Pattern | Meaning | Matches |
| --- | --- | --- |
| `60 30 50 00` | target VA `0x00503060` | 0 |
| `60 30 10 00` | target RVA `0x00103060` | 0 |
| `70 30 50 00` | target interior VA `0x00503070` | 0 |
| `79 30 50 00` | target interior VA `0x00503079` | 0 |
| `98 30 50 00` | target interior VA `0x00503098` | 0 |
| `a0 30 50 00` | target interior VA `0x005030a0` | 0 |
| `a8 30 50 00` | target virtual-call VA `0x005030a8` | 0 |
| `bc 30 50 00` | target end/padding VA `0x005030bc` | 0 |
| `c0 30 50 00` | sibling [UID:0002BE] VA `0x005030c0` | 0 |
| `10 31 50 00` | sibling [UID:0002BF] VA `0x00503110` | 0 |
| `50 33 50 00` | MapName render VA `0x00503350` | 1 at `0x0061e5f8` |
| `a0 34 50 00` | MapName update VA `0x005034a0` | 1 at `0x0061e610` |
| `50 36 50 00` | MiniMapButton paint VA `0x00503650` | 1 at `0x0061e680` |
| `a0 36 50 00` | MiniMapButton mouse VA `0x005036a0` | 1 at `0x0061e68c` |

The positive MapName/MiniMapButton hits show the scan can see real vtable pointers; the target absence is meaningful.

## PE / Raw Executable Evidence

I ran a section-aware read-only scan against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

PE facts:

| Field | Value |
| --- | --- |
| Machine | `0x14c` |
| Image base | `0x400000` |
| `.text` | `0x00401000-0x0060c600`, executable |
| `.rdata` | `0x0060d000-0x0066c200` |
| `.data` | `0x0066d000-0x0069ce24` |
| `.rsrc` | `0x0069d000-0x006b2e00` |

Literal VA/RVA pattern scan:

| Target | VA hits | RVA hits |
| --- | ---: | ---: |
| `0x00503060` target entry | 0 | 0 |
| `0x00503070` target interior | 0 | 0 |
| `0x00503079` target `byte_66DA97` compare | 0 | 0 |
| `0x00503098` target rect call site | 0 | 0 |
| `0x005030a0` dispatch block | 0 | 0 |
| `0x005030a8` virtual call instruction | 0 | 0 |
| `0x005030bc` target end/padding | 0 | 0 |
| `0x005030c0` sibling [UID:0002BE] entry | 0 | 0 |
| `0x00503110` sibling [UID:0002BF] entry | 0 | 0 |
| `0x005031f0` MapName constructor | 0 | 0 |
| `0x00503350` MapName render | 1 at `0x0061e5f8` | 0 |
| `0x005034a0` MapName update | 1 at `0x0061e610` | 0 |
| `0x00503650` MiniMapButton paint | 1 at `0x0061e680` | 0 |
| `0x005036a0` MiniMapButton mouse | 1 at `0x0061e68c` | 0 |

Direct branch/call encoded target scan:

| Target | Direct branch/call hits |
| --- | ---: |
| `0x00503060` target entry | 0 |
| `0x00503070` target interior | 0 |
| `0x00503079` target interior | 0 |
| `0x00503098` target interior | 0 |
| `0x005030a0` dispatch block | 1 internal short jump from `0x00503077` |
| `0x005030a8` virtual call instruction | 0 |
| `0x005030bc` target end/padding | 0 |
| `0x005030c0` sibling [UID:0002BE] entry | 0 |
| `0x00503110` sibling [UID:0002BF] entry | 0 |
| `0x005031f0` MapName constructor | 2 direct calls from `0x004f8051` and `0x004f8695` |
| `0x00503350` MapName render | 0 |
| `0x005034a0` MapName update | 0 |
| `0x00503650` MiniMapButton paint | 0 |
| `0x005036a0` MiniMapButton mouse | 0 |

The only branch to a target interior is the target's own `jnz` to `0x005030a0`. No external encoded call/jump/conditional branch reaches the entry.

## Documentation Evidence

| Document | Evidence used |
| --- | --- |
| [UID:0002BD][target page](../../../../../by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) | Current metadata, exact behavior, prior no-owner evidence, non-initializing state caveat. |
| [UID:00022Z][parent aggregate](../../../../../by-memory/0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md) | Correctly models the physical span as a non-emitting split inventory with exact child pages. |
| [UID:0002BE][sibling rectangle writer](../../../../../by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) | Same EPF/legacy rectangle constants and same owner blocker. |
| [UID:0002BF][sibling glyph renderer](../../../../../by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md) | Has MapName routing only because of `MapNamePane +0x220` 9x11-font lifecycle evidence, which [UID:0002BD] lacks. |
| [UID:0001AL][MapNameAndMiniMapButtonPanes](../../../../../by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md) | Documents exact following MapName/MiniMapButton island and warns not to absorb the raw helper cluster without caller/vtable evidence. |
| [UID:00007P][MapNamePane class](../../../../../by-class/MapNamePane.md) | Confirms constructor callers, vtables, render/update slots, `MAPNAME.EPF`, `g_useEpfAssets`, and `+0x220` resource cleanup. |
| [UID:0000L2][MapNamePane file](../../../../../by-file/MapNamePane.md) | Valid map-source file root, but no source-use reference to [UID:0002BD]. |
| [UID:00008B][MiniMapButtonPane class](../../../../../by-class/MiniMapButtonPane.md) | Confirms MiniMapButton vtable/method ownership and resource evidence, but no relation to [UID:0002BD]. |
| [UID:0000LE][MiniMap file](../../../../../by-file/MiniMap.md) | Valid MiniMap source root for MiniMapButton; no source-use reference to [UID:0002BD]. |
| [UID:00022Y][MainMenu ANSI helper](../../../../../by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md) | Left neighbor is strongly MainMenu-owned and ends at `0x0050305c`; four `0xcc` bytes separate it from the target. |
| [UID:00015S][RectGeometryHelpers](../../../../../by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md) | `0x004b7c50` is a broad `RectBounds` initializer dependency, not an owner. |
| [UID:0000SW][g_useEpfAssets](../../../../../by-global/g_useEpfAssets.md) | Global process-wide EPF/current-mode flag; target is only a reader. |

## Candidate Owner / Emitter Analysis

| Candidate | Rank | Evidence for | Evidence against | Decision |
| --- | ---: | --- | --- | --- |
| [UID:00007P] `MapNamePane` / [UID:0000L2] `MapNamePane` file | 1 | Address adjacency; `0xad` equals the documented 173-pixel map-name clamp; target reads `g_useEpfAssets`; sibling [UID:0002BF] has valid MapName ownership. | No caller, table pointer, vtable slot, raw VA/RVA hit, relative branch/call, or MapName-private field access; target lacks the `+0x220` evidence that justified [UID:0002BF]. | Reject canonical owner and emitter. Best non-actionable hypothesis only. |
| [UID:00008B] `MiniMapButtonPane` / [UID:0000LE] `MiniMap` | 2 | Nearby interleaved island; MiniMapButton mouse handler also uses vtable `+0x20` redraw-like calls. | MiniMapButton has its own constructor, paint, mouse, vtable, singleton, and `MMAPBUT.EPF` evidence; no reference or field evidence ties target to it. | Reject. |
| [UID:0000L0] `MainMenuPane` | 3 | Left neighbor [UID:00022Y] is MainMenu-owned. | `0x0050305c-0x00503060` is `0xcc` padding; left neighbor has real MainMenu caller and packet behavior, target has none. | Reject. |
| [UID:0000N2] `RectBounds` / geometry helpers | 4 | Target calls `sub_4B7C50` to initialize a rectangle. | `sub_4B7C50` has broad fan-in and is only a callee dependency; caller code does not become geometry-owned. | Reject. |
| [UID:0000SW] `g_useEpfAssets` or StartupWindow owner | 5 | Target reads `byte_66DA97`. | Global is process-wide configuration; read-only consumer evidence does not imply ownership or emission under StartupWindow. | Reject. |
| New shared UI helper source | 6 | Target and [UID:0002BE] form a matched rectangle helper pair. | No caller/table/source-use context proves original source file or output route. | Do not create. |
| Multiple emitters | 7 | Owner/emitter split allows multiple emitters for pooled/shared source data. | Target is unique executable code, not pooled data or a literal group; no source-use contexts are proven. Multiple emitters would duplicate an unreferenced function into guessed files. | Reject. |
| Compiler/runtime/ignored | 8 | Function has stack-cookie code. | Body uses game UI globals, RectBounds helper, and virtual dispatch; it is project code, not padding/runtime. | Reject reclassification. |

## Split / Repair Decision

No split repair is needed.

| Range | UID | State | Decision |
| --- | --- | --- | --- |
| `0x00503060-0x005030bc` | [UID:0002BD] | `RECONSTRUCTABLE:TRUE`, no owner/emitter | Current target, exact child. |
| `0x005030bc-0x005030c0` | ignored padding | `0xcc` | Correct padding. |
| `0x005030c0-0x00503104` | [UID:0002BE] | `RECONSTRUCTABLE:TRUE`, no owner/emitter | Exact sibling; same owner blocker. |
| `0x00503104-0x00503110` | ignored padding | `0xcc` | Correct padding. |
| `0x00503110-0x005031e1` | [UID:0002BF] | `RECONSTRUCTABLE:TRUE`, routed to MapNamePane | Exact sibling; MapName route does not transfer. |
| `0x00503060-0x005031e1` | [UID:00022Z] | `RECONSTRUCTABLE:FALSE`, no owner/emitter | Correct non-emitting split inventory. |

IDA function creation is not a prerequisite for the ownership decision. Creating a function object could help a future C++ rewrite if a real source route is later found, but it would not create caller/table/vtable evidence and should not be treated as an ownership repair.

## Why Blank `EMITTER_UIDS` Is Correct

Blank `EMITTER_UIDS` is valid here because `RECONSTRUCTABLE:TRUE` means the bytes are source-authored project code that may eventually need reconstruction, while emitter routing controls where generated source is output. For [UID:0002BD], no output route is proven.

This is not the pooled-data case where `CANONICAL_OWNER:NONE` plus one or more emitters would be correct. The target is a unique executable function body. No caller, table, vtable slot, literal consumer, or class-private state access identifies a source-use file. Adding `EMITTER_UIDS:0000L2` or `EMITTER_UIDS:0000LE` would be a source placement guess, not a documented route.

## Negative Evidence

- No IDA function object at `0x00503060`.
- No external xrefs to `0x00503060`.
- No xrefs to the target end/padding at `0x005030bc`.
- No xrefs to sibling entries `0x005030c0` and `0x00503110`.
- No raw little-endian VA/RVA pattern for the target entry or useful interiors.
- No PE direct `E8/E9`, `0F 8x`, or short-branch target to the target entry.
- No MapName or MiniMapButton vtable slot points to `0x00503060`.
- No constructor/destructor/singleton lifecycle path references the target.
- No MapName `this + 0x220` or other class-private state access appears in the target.
- No evidence that the target is a source-level inline duplicate or pooled literal/data item.
- No evidence that MainMenu's left-neighbor ownership crosses the `0xcc` boundary.

## Open Risks

- The helper may be reachable through an indirect mechanism not represented by IDA xrefs, raw pointers, vtables, or encoded direct branches.
- The virtual slot `+0x20` receiver type is still unresolved.
- The non-initializing state path still passes an uninitialized local rectangle pointer unless the real caller contract avoids that state or the virtual receiver tolerates it.
- `0xa6` and `0xad` are strongly rectangle extents, but their source-level names remain unresolved.
- A future linker map, PDB, object-file boundary, callback registry, or hidden table could justify re-routing all three raw children together.

## Commands / Validation

No by-* documentation files were edited by this B002 second-pass work, so no leaser write lease or validator run was required. No prohibited validator mode was used.

Evidence commands/results recorded:

- Read `goal.md`, `by-structure.md`, and `inference_research.md`.
- Read target, parent aggregate, sibling pages, candidate owner docs, prior B001 report, generated coverage rows, and current `by-memory/-coverage-report.md` row.
- IDA MCP `idb_list`: active session `b001_0003gy`.
- IDA MCP `server_health`: IDB ready, Hex-Rays ready, image base `0x400000`.
- IDA MCP `lookup_funcs`: raw helper starts are not functions; surrounding modeled functions match current docs.
- IDA MCP `entity_query`: no modeled function at `0x00503060-0x005031e1`; adjacent MapName/MiniMapButton functions listed.
- IDA MCP `xrefs_to`: zero external xrefs to target entry, sibling entries, and target end; MapName vtable-head refs are normal constructor/destructor stores.
- IDA MCP `disasm 0x00503060`: confirms raw helper behavior through `retn 4`.
- IDA MCP `decompile` for MapName and MiniMapButton methods: confirms candidate owner facts and lack of target references.
- IDA MCP `get_bytes`: confirms raw bytes, padding, and vtable-region negative evidence.
- IDA MCP `find_bytes`: zero target/sibling/interior pointer-pattern hits; positive sanity hits for known MapName/MiniMapButton slots.
- IDA MCP `make_signature_for_range`: exact and wildcarded target signatures are unique.
- IDA MCP `search_text byte_66DA97`: only local hits at `0x00503079` and `0x005030c9` in this cluster.
- Local PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`: zero VA/RVA and external branch/call hits for target and sibling raw entries; positive sanity hits for known MapName/MiniMapButton vtable pointers and MapName constructor direct calls.

One initial PowerShell PE scan timed out after partial pointer checks; it was rerun with a faster read-only parser and completed successfully. No filesystem writes occurred during evidence gathering except creation of this final report.

## Changed Files

- Created `tools/leaser/Agents/Agent-B002/research/0002BD-UiAssetModeRectVirtualDispatchHelper-second-pass.md`

No by-memory, by-class, by-file, auto-generated, tracker, or coverage-report file was modified by this B002 second-pass work.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002BD-UiAssetModeRectVirtualDispatchHelper-second-pass.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002BD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
