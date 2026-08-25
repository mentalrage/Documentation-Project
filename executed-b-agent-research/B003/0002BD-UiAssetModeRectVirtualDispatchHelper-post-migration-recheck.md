** TARGET-REPORT-UID:0002BD **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BD UiAssetModeRectVirtualDispatchHelper Post-Migration Recheck

## Finalized Report / Current Recommendation

**Recommendation:** keep [UID:0002BD] `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md` as a reconstructable, currently unowned and non-emitting raw helper.

- `COMPLETION:87` / `CONFIDENCE:91` should remain unchanged.
- `RECONSTRUCTABLE:TRUE` should remain unchanged because the body is source-shaped project UI code, not compiler/runtime residue or padding.
- `CANONICAL_OWNER:NONE` should remain unchanged. No semantic declaration owner is proven.
- `EMITTER_UIDS:` should remain blank. No source-use/output route is proven for MapNamePane, MiniMapButtonPane, MainMenu, RectBounds, StartupWindow, or any other current source island.
- `EMITTER_POSITION_OPTIONAL:` should remain blank.
- Do not enter final reconstruction C++. The active gate is 90/90+, and this item still lacks a proven owner/emitter/source placement even though confidence is above 90.
- No split, merge, range repair, owner/emitter repair, or IDA-side repair is recommended for supervisor execution.

This is not an invalid dead reconstructable state under the current owner/emitter model. `RECONSTRUCTABLE:TRUE` records that the executable body is likely source-authored and can be reconstructed once placement is proven. Blank `EMITTER_UIDS` is still valid here because this is not a pooled literal or shared data item with known source-use contexts; it is a unique executable helper with no proven caller, table slot, pointer, branch target, or documented source route. Emitting it now would fabricate output placement.

## Target

- UID: `0002BD`
- Path: `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md`
- Range: `0x00503060-0x005030bc`
- Current generated state: reconstructable no-owner, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`
- Current target metadata: `COMPLETION:87`, `CONFIDENCE:91`, `RECONSTRUCTABLE:TRUE`
- Current coverage row score: `87% : strong`
- Prior reports reviewed as evidence, not accepted as conclusions:
  - `tools/leaser/Agents/Agent-B001/research/executed/0002BD-UiAssetModeRectVirtualDispatchHelper-post-migration.md`
  - `tools/leaser/Agents/Agent-B002/research/executed/0002BD-UiAssetModeRectVirtualDispatchHelper-second-pass.md`

## Evidence Standards Used

I applied the current `by-structure.md` owner/emitter split:

- `CANONICAL_OWNER` is semantic declaration/source ownership.
- `EMITTER_UIDS` controls reconstruction output routing and may be different from canonical ownership.
- Reconstructable no-owner/non-emitting state is allowed while owner/emitter evidence is unresolved.
- Multiple emitters require proven source-use contexts; they should not be inferred from adjacency or theme.
- The active reconstruction C++ entry gate is 90/90+ plus proven owner/emitter route, dependencies, names, boundaries, and source placement.

## IDA MCP Evidence

Live IDA MCP was available at the documented endpoint. The active session was `b001_0003gy`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, module `NexusTK.exe`, image base `0x00400000`, auto-analysis ready, Hex-Rays ready, strings ready.

### Function Boundary Facts

`lookup_funcs` shows no IDA function object for the target or adjacent raw helper children:

- `0x00503060`, `0x00503070`, `0x00503079`, `0x00503098`, `0x005030a0`, `0x005030a8`, and `0x005030bc`: not functions.
- `0x005030c0` and `0x00503110`: not functions.
- Positive surrounding controls:
  - `0x00502e10` -> `sub_502E10`
  - `0x00502e30` -> `sub_502E30`
  - `0x005031f0` -> `sub_5031F0` (MapNamePane constructor)
  - `0x005032d0` -> `sub_5032D0` (MapNamePane destructor)
  - `0x00503350` -> `sub_503350` (MapNamePane render/update-associated routine)
  - `0x005034a0` -> `sub_5034A0` (MapNamePane packet/update-associated routine)
  - `0x00503580` -> `sub_503580` (MiniMapButtonPane constructor)
  - `0x00503650` -> `sub_503650`
  - `0x005036a0` -> `sub_5036A0`
  - `0x004b7c50` -> `sub_4B7C50` (`InitRectBounds`)

### Target Body

IDA disassembly of `0x00503060-0x005030bc`:

```asm
00503060  push    ebp
00503061  mov     ebp, esp
00503063  sub     esp, 14h
00503066  mov     eax, ___security_cookie
00503070  sub     dword ptr [ebp+8], 1
00503074  push    esi
00503075  mov     esi, ecx
00503077  jnz     short loc_5030A0
00503079  cmp     byte_66DA97, 1
00503080  lea     eax, [ebp-14h]
00503083  push    10h
00503085  jnz     short loc_50308E
00503087  push    0A6h
0050308c  jmp     short loc_503093
0050308e  push    0ADh
00503093  push    0
00503095  push    0
00503097  push    eax
00503098  call    sub_4B7C50
0050309d  add     esp, 14h
005030a0  mov     eax, [esi]
005030a2  lea     ecx, [ebp-14h]
005030a5  push    ecx
005030a6  mov     ecx, esi
005030a8  call    dword ptr [eax+20h]
005030b1  call    @__security_check_cookie@4
005030b9  retn    4
005030bc  align   10h
```

The body is source-shaped UI helper logic:

- It tests `g_useEpfAssets` / `byte_66DA97`.
- It builds a local `RectBounds(0, 0, 0xa6 or 0xad, 0x10)` through `sub_4B7C50`.
- It dispatches through the receiver vtable slot `+0x20`.
- It has normal stack-cookie instrumentation, but no evidence of compiler/runtime-only residue.

### Xrefs and Interior Reachability

`xrefs_to` results:

- `0x00503060`: no xrefs.
- `0x00503070`: internal xref only from `0x0050306d`.
- `0x00503079`: internal xref only from `0x00503077`.
- `0x00503098`: internal xref only from `0x00503097`.
- `0x005030a0`: internal xrefs only from `0x0050309d` and `0x00503077`.
- `0x005030a8`: internal xref only from `0x005030a6`.
- `0x005030bc`: no xrefs.
- Adjacent child starts `0x005030c0` and `0x00503110`: no xrefs.

Positive controls prove the IDA xref path is working:

- `0x005031f0` has code xrefs from `0x004f8051` and `0x004f8695`.
- `0x00503350` has a data ref at `0x0061e5f8`.
- `0x005034a0` has a data ref at `0x0061e610`.
- `0x00503580` has a code ref at `0x004f80c2`.
- `0x00503650` has a data ref at `0x0061e680`.
- `0x005036a0` has a data ref at `0x0061e68c`.

### Raw Pointer and Signature Checks

IDA `find_bytes` checks found no VA/RVA-style raw pointers to the target or useful interiors:

- No hits for `60 30 50 00`, `60 30 10 00`, `70 30 50 00`, `79 30 50 00`, `98 30 50 00`, `A0 30 50 00`, `A8 30 50 00`, `BC 30 50 00`, `C0 30 50 00`, `C0 30 10 00`, `10 31 50 00`, `10 31 10 00`.
- Positive controls found known vtable entries:
  - `50 33 50 00` -> `0x0061e5f8`
  - `A0 34 50 00` -> `0x0061e610`
  - `50 36 50 00` -> `0x0061e680`
  - `A0 36 50 00` -> `0x0061e68c`

IDA signature generation for `0x00503060-0x005030bc` produced a unique wildcarded signature. That supports keeping the helper as a distinct reconstructable body, but it does not provide an owner or emitter.

## PE / Raw Executable Evidence

I performed a local PE relative branch/call scan against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

- Image base: `0x00400000`
- `.text`: `0x00401000-0x0060c4ac`

Results:

| Target | Direct rel32 call/jmp | Near conditional branch | Short conditional branch |
| --- | --- | --- | --- |
| `0x00503060` | none | none | none |
| `0x00503070` | none | none | none |
| `0x00503079` | none | none | none |
| `0x00503098` | none | none | none |
| `0x005030a0` | none | none | `0x00503077` only |
| `0x005030a8` | none | none | none |
| `0x005030bc` | none | none | none |
| `0x005030c0` | none | none | none |
| `0x00503110` | none | none | none |
| `0x005031f0` | `0x004f8051`, `0x004f8695` | none | none |

The MapNamePane constructor calls are a positive control. The target has no external PE-level direct branch or call evidence, including no intentional branch into the interior dispatch block at `0x005030a0`.

## Documentation Evidence

### Target Page

The target page already records the same basic shape:

- raw helper, no IDA function object;
- no direct callers or external xrefs;
- source-shaped body using `g_useEpfAssets`, `RectBounds`, and virtual dispatch;
- no proven parent/emitter route;
- C++ intentionally blank.

The page is consistent with the current owner/emitter model and the 90/90+ gate.

### Aggregate Container

`by-memory/0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md` is a non-reconstructable inventory container over the raw helper cluster:

- `0002BD` `0x00503060-0x005030bc`
- `0002BE` `0x005030c0-0x00503104`
- `0002BF` `0x00503110-0x005031e1`

That aggregate should stay non-emitting. It should not absorb this child into MapName/MiniMapButton without caller/table evidence.

### Sibling Pages

`0002BE` `UiAssetModeRectWriteHelper` is another unowned, non-emitting helper that reads `g_useEpfAssets` and uses the same EPF/legacy rectangle constants. It does not prove ownership for `0002BD`.

`0002BF` `WideGlyphResourceTextRendererRaw` now has `CANONICAL_OWNER:00007P` and `EMITTER_UIDS:00007P` because it reads the MapNamePane `this+0x220` font slot loaded by the MapNamePane constructor and freed by its destructor. That is valid sibling-specific evidence, but it does not transfer to `0002BD`, which does not read `this+0x220` or any other MapName-private field.

### MapNamePane / MiniMapButtonPane Documentation

Current MapNamePane documentation identifies:

- constructor at `0x005031f0`;
- destructor at `0x005032d0`;
- render/update-related routines at `0x00503350` and `0x005034a0`;
- vtables at `0x0061e5b4`, `0x0061e600`, `0x0061e630`;
- resource and font behavior involving `MAPNAME.EPF` and `9X11FONT.BIN`;
- packet/update behavior using width `0xad` in `sub_4BA820`.

Current MiniMapButtonPane documentation identifies:

- constructor at `0x00503580`;
- paint/mouse/update methods at `0x00503650`, `0x005036a0`, `0x00503840`, `0x00503900`;
- vtables at `0x0061e63c`, `0x0061e688`, `0x0061e6b8`;
- resource `MMAPBUT.EPF`;
- singleton `g_pMiniMapButtonPane`.

Live IDA name/table checks confirmed those vtable regions, and no table entry points to `0x00503060`.

## Candidate Owner / Emitter Analysis

### 1. MapNamePane (`00007P`) - Rejected

MapNamePane is the strongest hypothesis by proximity and theme:

- `0002BD` sits immediately before MapName/MiniMapButton code.
- It uses `g_useEpfAssets`, like MapNamePane and nearby UI code.
- The `0xad` width equals the `173` value used in the MapNamePane update text path.
- Sibling `0002BF` has proven MapNamePane ownership.

That is still insufficient for ownership or emitter routing:

- no xref/caller to `0x00503060`;
- no raw pointer to `0x00503060`;
- no vtable slot containing `0x00503060`;
- no external branch into the helper or its interior;
- no MapName-private field access such as `this+0x220`;
- no current by-file/by-class doc placing this helper in `MapNamePane.cpp`;
- sibling `0002BF` has field evidence that `0002BD` lacks.

Do not assign `CANONICAL_OWNER:00007P` or `EMITTER_UIDS:00007P` from adjacency alone.

### 2. MiniMapButtonPane / MiniMap - Rejected

MiniMapButtonPane is also nearby, but current evidence does not connect it to the helper:

- no MiniMapButton vtable slot points to `0x00503060`;
- no MiniMapButton constructor/paint/mouse path calls it;
- no MiniMapButton singleton or field access appears in the target body;
- the target does not load `MMAPBUT.EPF`;
- the PE branch/call scan found no route.

No MiniMap or MiniMapButton emitter is justified.

### 3. MainMenu / Login UI - Rejected

The left neighbor `0x00502e10-0x0050305c` is documented as MainMenu-owned. That does not extend across the `0xcc` alignment boundary into `0x00503060`:

- the target begins after padding/alignment;
- the body has no packet-dialog behavior matching the left neighbor;
- there are no MainMenu callers, xrefs, or pointer references to the helper.

No MainMenu owner or emitter is justified.

### 4. RectBounds / Geometry Helpers - Rejected

The target calls `sub_4B7C50` / `InitRectBounds`, but that is a broad geometry helper with many callers. A dependency on `RectBounds` construction does not make this body owned by RectBounds or a geometry source island.

### 5. `g_useEpfAssets` / StartupWindow - Rejected

The target reads `g_useEpfAssets`, but that flag is a broad process-wide rendering/resource-mode switch with many consumers. Its current ownership does not make every consumer owned by StartupWindow or any global owner.

### 6. New Raw UI Helper Island - Not Actionable

A future narrow helper source file for the `0002BD/0002BE` raw pair is plausible, but current evidence does not prove a source island, source path, or emitter route. The existing aggregate `00022Z` already records the cluster as a non-emitting inventory container. Creating a new owner/emitter from the cluster alone would not improve correctness.

## Source-Authored vs Residue Decision

This helper should not be reclassified as non-reconstructable/compiler residue:

- it has a coherent UI helper body;
- it branches on a project global resource-mode flag;
- it initializes a project `RectBounds` object;
- it performs a virtual UI call through receiver vtable slot `+0x20`;
- its exact code signature is unique.

The lack of xrefs makes it retained/unrouted, not padding or runtime residue.

## Split / Merge / IDA Repair Decision

- No split is needed. The target range is already a single coherent helper body ending at the `0x005030bc` alignment.
- No merge is recommended. The neighboring raw helpers have different behavior and their own child pages.
- No IDA function repair is required for this ownership decision. Defining a function at `0x00503060` might aid future decompilation, but it would not create caller, pointer, table-slot, or source-placement evidence.
- No documentation repair is required for owner/emitter metadata.

## Exact Recommended Metadata / Coverage Changes

No metadata change is recommended.

Target header should remain:

```text
UID:0002BD
COMPLETION:87
CONFIDENCE:91
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
```

`RECONSTRUCTION_CPP` should remain blank.

Generated no-owner row should remain:

```text
| [UID:0002BD][0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper](by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md` |  |
```

Coverage row should remain unchanged:

```text
    - [UID:0002BD][0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper](by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) 0x00503060-0x005030bc | raw function | UiAssetModeRectVirtualDispatchHelper : reconstructable : 87% : strong : B002 second-pass reconfirms source-shaped raw helper body but no owner/emitter route: live IDA session b001_0003gy reports no function object at 0x00503060, no external xrefs to the entry/end/sibling starts, only internal branch refs inside the helper, unique exact and wildcarded signatures, data refs only to security cookie and g_useEpfAssets, optional RectBounds(0,0,0xa6/0xad,0x10) setup through sub_4B7C50, unconditional vtable slot +0x20 dispatch, no VA/RVA pointer hits to the target or useful interiors, no PE-level E8/E9/0F8x/short-branch target to the entry, and no MapName/MiniMapButton vtable slot. MapName width and sibling-glyph associations remain insufficient for canonical ownership or emitter routing.
```

Score before/after:

```text
Before: 87/91
After:  87/91
```

## Validation / Rerun Recommendation

No `by-*` files or coverage rows were edited, so `memory_ranges` / coverage validation does not need to be rerun for this report alone. If a supervisor later edits target prose or regenerates coverage text, run the normal non-dry validation path afterward.

## Remaining Risks / Blockers

The main unresolved blocker is reachability/source placement:

- no direct xrefs;
- no raw pointer hits;
- no vtable/table entry;
- no external branch/call target;
- no MapName/MiniMap/MainMenu private state access;
- no documented source-use context.

The most likely future route, if one appears, would be a UI source island adjacent to MapName/MiniMapButton or a recovered table/caller that dispatches this helper. Current evidence does not clear that gate.

## Confidence

High confidence for keeping the current no-owner/non-emitting state. The negative reachability evidence was refreshed with live IDA MCP checks and a raw PE branch/call scan, while positive controls confirmed that xrefs, vtable pointer searches, and branch scanning were able to find known MapName/MiniMapButton references.

## Changed Files

- Created this report only:
  - `tools/leaser/Agents/Agent-B003/research/0002BD-UiAssetModeRectVirtualDispatchHelper-post-migration-recheck.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002BD-UiAssetModeRectVirtualDispatchHelper-post-migration-recheck.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0002BD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
