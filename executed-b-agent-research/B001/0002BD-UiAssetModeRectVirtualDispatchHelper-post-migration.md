** TARGET-REPORT-UID:0002BD **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BD UiAssetModeRectVirtualDispatchHelper Post-Migration Ownership / Source-Routing Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002BD][0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper](../../../../../by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank reconstruction C++.
- Final disposition: source-authored raw UI helper code, but no current canonical owner and no source-use emitter route clears the owner/emitter split gate. This is still no-owner and non-emitting, not ignored/padding/runtime.
- Required action: no by-* metadata, split, reclassification, score, or `by-memory/-coverage-report.md` row change is recommended. Supervisor can mark the B001-0002BD post-migration tracker row complete with "retain no-owner/non-emitting".
- Confidence: `94/100` for boundary and behavior; `92/100` for keeping `CANONICAL_OWNER:NONE` with blank emitters; `78/100` for MapName-side retained UI/resource helper code as the strongest non-actionable source-family hypothesis.

## Supporting Research

## Target

- Target UID: `0002BD`
- Target path: `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md`
- Source queue/report row: `auto-generated/-ag-memory-coverage.md`, current generated state `no-owner`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`.
- Tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, row `0002BD`, assigned to Agent-B001 for post-migration owner/emitter recheck.
- Current scores and metadata: `COMPLETION:87`, `CONFIDENCE:91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank reconstruction C++.
- Current physical aggregate: [UID:00022Z][0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers](../../../../../by-memory/0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md), `RECONSTRUCTABLE:FALSE` split inventory.
- Lease handling: read current lease report; no by-* files were edited, so no target lease was required under `goal.md`.

## Executive Recommendation

The post-migration metadata should stay as-is:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
```

The helper is not compiler-generated support and not ignorable padding. IDA shows a real source-shaped body: stack-cookie setup, `g_useEpfAssets` branch, `RectBounds` initialization through `0x004b7c50`, and virtual dispatch through receiver vtable slot `+0x20`.

The owner/emitter split does not justify adding emitters. `EMITTER_UIDS` means generated-output source routing, not "best nearby guess." For this target there is no direct caller, no function pointer table, no vtable slot, no raw VA/RVA pointer hit, no relative branch/call target, and no class-field access tying the helper to a source-use context. The helper is a unique function body, not a pooled string/constant that should be emitted in multiple consumer files. Therefore `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS` remains the correct reconstructable-but-non-emitting state.

The best non-actionable hypothesis is still MapName-side retained UI/resource helper code, now strengthened by sibling [UID:0002BF][0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw](../../../../../by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md) having a valid [UID:00007P][MapNamePane](../../../../../by-class/MapNamePane.md) route. That sibling uses the `MapNamePane`-owned `this + 0x220` / 544 field (Verified with `int_convert`) loaded by the constructor and freed by the destructor. [UID:0002BD] does not touch that field or any other MapName-private state, so the sibling route does not transfer automatically.

No split repair is required. The exact child pages and padding boundaries are already modeled:

- [UID:0002BD] `0x00503060-0x005030bc`, current target.
- [UID:0002BE] `0x005030c0-0x00503104`, sibling rectangle-write helper, still no-owner/no-emitter.
- [UID:0002BF] `0x00503110-0x005031e1`, sibling glyph renderer, now routed to [UID:00007P] `MapNamePane`.
- [UID:00022Z] `0x00503060-0x005031e1`, non-emitting split inventory.

## Supervisor Active Recheck

The supervisor asked for a post-migration re-evaluation because the generated memory report still lists [UID:0002BD] as reconstructable no-owner with `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`.

This pass rechecked the old B001 conclusion under current owner/emitter semantics:

- `CANONICAL_OWNER` remains unassigned because no direct semantic owner clears the gate.
- `EMITTER_UIDS` remains blank because no source-use context is proven.
- `RECONSTRUCTABLE:TRUE` remains correct because the bytes are project code that must be understood/recreated if the original source path is recovered.
- `RECONSTRUCTABLE:FALSE` is not appropriate for the target itself. That classification is correct only for the physical aggregate [UID:00022Z].
- Multiple emitters are not appropriate. This is a single unique function body, not a pooled literal or shared constant that must appear in multiple reconstructed source contexts.

## Inference Research Guidance Check

`by-structure.md` now separates direct semantic ownership from generated-output routing:

- `CANONICAL_OWNER` must identify the narrowest true owner supported by evidence.
- `EMITTER_UIDS` must identify proven generated-output source-use routes.
- `CANONICAL_OWNER:NONE` with multiple emitters is valid for source-authored pooled data when source-use contexts are proven.

That pooled-data rule does not fit [UID:0002BD]. The target is executable function code with one unique binary instance. Adding `EMITTER_UIDS:00007P` would claim MapName source-use without a caller, table, vtable slot, or class-private state access. Adding multiple emitters would be worse because it would duplicate a unique unreferenced helper body into several source contexts without evidence.

`inference_research.md` warns not to treat lack of perfect source proof as a reason to stop early. I applied that by ranking MapNamePane, MiniMapButtonPane/MiniMap, MainMenuPane, `g_useEpfAssets`/StartupWindow, `RectGeometryHelpers`, a new helper file, and compiler/runtime classification. The recommendation still stays no-owner/no-emitter because every actionable route depends on association evidence rather than a source-use proof.

Existing documentation was treated as evidence, not authority. Fresh IDA MCP checks confirm the target page's main facts and update the post-migration interpretation.

## Evidence Standards Used

- IDA MCP: `server_health`, `lookup_funcs`, `xrefs_to`, `disasm`, `decompile`, `callees`, `get_bytes`, `find_bytes`, `make_signature`, `make_signature_for_range`, `search_text`, and `int_convert`.
- Local PE scan: section-aware `.text` scan for relative `E8/E9`, `0F 8x`, and short conditional-branch targets to the three raw starts.
- Documentation evidence: target/sibling pages, aggregate split pages, MapNamePane file/class/memory/vtable pages, MiniMapButtonPane file/class/vtable pages, MainMenu left-neighbor page, `g_useEpfAssets`, `RectGeometryHelpers`, and proposed source tree.
- Negative evidence: no IDA function object, no xrefs to raw starts, no VA/RVA pointer hits, no relative branch/call targets, no nearby MapName/MiniMapButton vtable slots, no MapName-private state access by the target, and no source metadata.

## IDA MCP Facts

### Session Facts

- MCP session: `b001_0003lq`
- Input path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- IDB path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Image base: `0x400000`
- Hex-Rays ready: true
- Auto-analysis ready: true

### Function / Range Facts

`lookup_funcs` on 2026-06-13 reports:

| Query | Result |
| --- | --- |
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
| `0x00503840` | `sub_503840`, size `0xbe` |
| `0x00503900` | `sub_503900`, size `0x5f` |
| `0x004b7c50` | `sub_4B7C50`, size `0x1f` |

### Target Body Facts

`disasm 0x00503060` shows:

- Prologue at `0x00503060`, stack frame size `0x14` / 20 bytes (not used as a recommendation field, no conversion needed).
- Security cookie read from `___security_cookie`.
- `sub dword ptr [ebp+8], 1` at `0x00503070`.
- `ecx` saved into `esi`, so the helper uses `thiscall` receiver semantics.
- `cmp byte_66DA97, 1` at `0x00503079`.
- If the adjusted argument is zero, it initializes a local rectangle through `sub_4B7C50` with `(0, 0, 0xa6, 0x10)` or `(0, 0, 0xad, 0x10)`.
- `0xa6` is 166, `0xad` is 173, and `0x10` is 16 (all Verified with `int_convert`).
- It always pushes the local rectangle pointer and executes `call dword ptr [eax+20h]` at `0x005030a8`; `0x20` is 32 (Verified with `int_convert`).
- It returns with `retn 4` at `0x005030b9`.
- `0x005030bc-0x005030c0` is `0xcc` alignment before [UID:0002BE].

Hex-Rays decompilation of `0x00503060` fails because IDA still has no function object there. That failure supports the raw-helper status but does not make the bytes non-code.

### Raw Bytes / Padding Facts

`get_bytes` over `0x00503050` confirms the physical layout:

- `0x0050305c-0x00503060`: four `0xcc` bytes after the MainMenu helper.
- `0x00503060-0x005030bc`: target body.
- `0x005030bc-0x005030c0`: four `0xcc` bytes.
- `0x005030c0-0x00503104`: sibling [UID:0002BE].
- `0x00503104-0x00503110`: twelve `0xcc` bytes.
- `0x00503110-0x005031e1`: sibling [UID:0002BF].
- `0x005031e1-0x005031f0`: fifteen `0xcc` bytes before `MapNamePane` constructor.

`get_bytes` over `0x0061e5b4-0x0061e704` confirms the nearby MapName/MiniMapButton vtable and string island contains real slots for `MapNamePane` and `MiniMapButtonPane`, including `0x00503840`, `0x00503350`, `0x005034a0`, `0x0050380b`, `0x00503816`, `0x00503900`, `0x00503650`, `0x00503821`, `0x005036a0`, and `0x0050382c`, followed by `MAPNAME.EPF`, `MMAPBUT.EPF`, `CMAP`, and `GM`. It contains no raw helper start `0x00503060`, `0x005030c0`, or `0x00503110`.

### Xref Facts

`xrefs_to` reports zero xrefs to:

- `0x00503060`
- `0x005030bc`
- `0x005030c0`
- `0x00503104`
- `0x00503110`
- `0x005031e1`

Positive nearby owner anchors are normal and do not target [UID:0002BD]:

- `xrefs_to 0x005031f0`: two code xrefs from `0x004f8051` and `0x004f8695` inside `sub_4F7D10`, both MapName constructor calls.
- `xrefs_to 0x00503350`: data ref at `0x0061e5f8`, MapName render vtable slot.
- `xrefs_to 0x005034a0`: data ref at `0x0061e610`, MapName update-handler vtable slot.
- `xrefs_to 0x00503580`: code xref at `0x004f80c2`, MiniMapButtonPane constructor call.
- `xrefs_to 0x0061e5b4`, `0x0061e600`, `0x0061e630`: MapName constructor/destructor/deleting-destructor vptr stores.
- `xrefs_to 0x0061e63c`, `0x0061e688`, `0x0061e6b8`: MiniMapButtonPane constructor/cleanup/destructor vptr stores.

`search_text byte_66DA97` over `0x00503000-0x00503200` found exactly two local hits:

- `0x00503079` in [UID:0002BD].
- `0x005030c9` in [UID:0002BE].

That proves the target and rectangle-writer sibling share the EPF/current-mode branch. It does not prove a MapName or MiniMap owner.

### Signature And Pointer Facts

`find_bytes` found zero matches for raw helper starts as absolute VAs or RVAs:

| Pattern | Meaning | Matches |
| --- | --- | ---: |
| `60 30 50 00` | VA `0x00503060` | 0 |
| `60 30 10 00` | RVA `0x00103060` | 0 |
| `c0 30 50 00` | VA `0x005030c0` | 0 |
| `c0 30 10 00` | RVA `0x001030c0` | 0 |
| `10 31 50 00` | VA `0x00503110` | 0 |
| `10 31 10 00` | RVA `0x00103110` | 0 |

`make_signature_for_range 0x00503060-0x005030bc` reports a unique signature:

```text
55 8B EC 83 EC 14 A1 ? ? ? ? 33 C5 89 45 ? 83 6D ? ? 56 8B F1 75 ? 80 3D ? ? ? ? ? 8D 45 ? 6A 10 75 ? 68 A6 00 00 00 EB ? 68 AD 00 00 00 6A 00 6A 00 50 E8 ? ? ? ? 83 C4 14 8B 06 8D 4D ? 51 8B CE FF 50 ? 8B 4D ? 33 CD 5E E8 ? ? ? ? 8B E5 5D C2 04 00
```

`make_signature` reports unique entry signatures for `0x00503060`, `0x005030c0`, and `0x00503110`. The target and siblings are unique binary bodies, not repeated pooled inline copies.

### PE Relative Target Facts

A local section-aware `.text` scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` checked relative `E8/E9`, `0F 8x`, and short conditional branch targets. Results:

| Target | RelCallJmp | NearCond | ShortCond |
| --- | ---: | ---: | ---: |
| `0x00503060` | 0 | 0 | 0 |
| `0x005030c0` | 0 | 0 | 0 |
| `0x00503110` | 0 | 0 | 0 |

Combined with IDA `find_bytes` VA/RVA checks, this closes the ordinary direct-call, jump, conditional-branch, and raw-pointer source-use routes for the three raw starts.

### Candidate Owner Decompilation Facts

MapName constructor `0x005031f0`:

- Publishes `g_pMapNamePane` at `0x0069b4b4`.
- Stores MapName vtables at `0x0061e5b4`, `0x0061e600`, and `0x0061e630`.
- Checks `byte_66DA97`.
- Loads `MAPNAME.EPF` through `off_61E6C0`.
- Loads `9X11FONT.BIN` through `off_61682C` and stores the result into `this[136]`, byte offset `0x220` / 544 (Verified with `int_convert`).

MapName destructor `0x005032d0`:

- Restores MapName vtables.
- Frees `this[136]` / `this + 0x220`.
- Clears `g_pMapNamePane`.

MapName render `0x00503350`:

- Reads `byte_66DA97`.
- In the current/EPF path, draws centered map-name text through resource-backed rendering.
- In the legacy path, uses fallback text/color rendering.

MapName update handler `0x005034a0`:

- Handles opcode `0x15`.
- Converts incoming bytes to UTF-16 at the MapName buffer.
- Calls `sub_4BA820(..., 173)`, where 173 is `0xad` (Verified with `int_convert`).
- Invalidates/redraws through a base virtual call.

MiniMapButton paint `0x00503650`:

- Loads `MMAPBUT.EPF` through `off_61E6D8`.
- Draws through shared tile/resource rendering.
- Does not use the `0xa6` / `0xad` rectangle pair and does not reference the target.

These facts strengthen MapName as the best source-family lead but still do not identify [UID:0002BD] as a MapName source item.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Current Owner / Emitters | Score | Status |
| --- | --- | --- | --- | --- | ---: | --- |
| `0x00503060-0x005030bc` | [UID:0002BD][0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper](../../../../../by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) | optional EPF/legacy rectangle setup and virtual dispatch | TRUE | `CANONICAL_OWNER:NONE`; blank `EMITTER_UIDS` | `87/91` | target; retain no-owner/non-emitting |
| `0x005030c0-0x00503104` | [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](../../../../../by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) | sibling optional EPF/legacy rectangle writer | TRUE | `CANONICAL_OWNER:NONE`; blank `EMITTER_UIDS` | `87/91` | sibling; same owner blocker |
| `0x00503110-0x005031e1` | [UID:0002BF][0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw](../../../../../by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md) | sibling 9x11 glyph renderer | TRUE | `CANONICAL_OWNER:00007P`; `EMITTER_UIDS:00007P` | `87/91` | sibling now has MapName field-lifecycle evidence |
| `0x00503060-0x005031e1` | [UID:00022Z][0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers](../../../../../by-memory/0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md) | physical split inventory | FALSE | `CANONICAL_OWNER:NONE`; blank `EMITTER_UIDS` | `86/90` | correct non-emitting aggregate |
| `0x005031f0-0x0050395f` | [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](../../../../../by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md) | mixed MapName/MiniMapButton island | FALSE | `CANONICAL_OWNER:NONE`; blank `EMITTER_UIDS` | `86/92` | non-emitting mixed inventory |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00503060` | `xrefs_to`: 0 | No direct caller, table, vtable slot, or pointer owner for target. |
| `0x005030c0` | `xrefs_to`: 0 | Sibling rectangle writer has the same unresolved state. |
| `0x00503110` | `xrefs_to`: 0 | Sibling glyph renderer has no live caller, but has MapName-private field evidence. |
| `0x004b7c50` | target callee at `0x00503098` | Generic `RectBounds` initializer dependency; not owner. |
| `0x0066da97` | target read at `0x00503079` | Broad process-wide EPF/current-mode flag; not owner. |
| `0x005030a8` | outgoing virtual call `[this->vtable + 0x20]` | Proves the helper dispatches to some receiver object; does not identify the helper's source owner. |
| `0x005031f0` | code refs from `0x004f8051`, `0x004f8695` | Normal MapName constructor callers start after the raw cluster. |
| `0x00503350` | data ref at `0x0061e5f8` | MapName render vtable slot; not target. |
| `0x005034a0` | data ref at `0x0061e610` | MapName update vtable slot; not target. |
| `0x00503580` | code ref at `0x004f80c2` | MiniMapButtonPane constructor caller; not target. |
| `0x0061e5b4`, `0x0061e600`, `0x0061e630` | MapName vptr stores | Confirms MapName class routing but no target slot. |
| `0x0061e63c`, `0x0061e688`, `0x0061e6b8` | MiniMapButton vptr stores | Confirms MiniMapButton routing but no target slot. |

## Documentation Evidence And IDA Status

Existing docs confirmed by this pass:

- Target page [UID:0002BD] correctly documents a real raw helper body, no IDA function object, no start xrefs, no VA/RVA pointer refs, no nearby vtable slot, and no assigned owner.
- Sibling [UID:0002BE] correctly documents the same EPF/legacy rectangle widths and the same no-owner/no-emitter blocker.
- Sibling [UID:0002BF] is now assigned to [UID:00007P] `MapNamePane`; fresh decompilation confirms the supporting `this + 0x220` field lifecycle.
- Aggregate [UID:00022Z] is correctly `RECONSTRUCTABLE:FALSE` as a physical split inventory.
- [UID:0001AL] correctly warns not to absorb the raw helper cluster into MapName/MiniMapButton without caller/vtable evidence.
- [UID:00007P] and [UID:0000L2] `MapNamePane` docs are confirmed for vtable stores, constructor callers, `MAPNAME.EPF`, `9X11FONT.BIN`, `g_pMapNamePane`, resource branch, render, and update-handler facts.
- [UID:00008B] and [UID:0000LE] `MiniMapButtonPane`/`MiniMap` docs are confirmed for `MMAPBUT.EPF`, vtables, constructor caller, and MiniMapButton ownership, but they do not tie to [UID:0002BD].
- [UID:00022Y] `MainMenuAnsiTextDialogPacketHelpers` correctly owns the left neighbor through direct MainMenu packet-handler callers; padding separates that range from [UID:0002BD].
- [UID:0000SW] `g_useEpfAssets` correctly documents the byte as a broad process-wide selector with a single startup writer and many consumers, so a read does not prove local ownership.
- [UID:00015S] `RectGeometryHelpers` correctly identifies `0x004b7c50` as rectangle initialization support, not an owner of every caller.

Existing docs needing no repair:

- No split/parent repair is required for the target range.
- No target metadata repair is recommended.
- No by-memory coverage row repair is required.

## Ranked Ownership Analysis

### 1. Keep `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS` - accepted

Evidence for:

- Target is a unique, source-shaped function body, but has zero xrefs to its start.
- No raw VA/RVA byte references to `0x00503060` exist in IDA `find_bytes`.
- Local `.text` PE scan found no `E8/E9`, `0F 8x`, or short conditional branch target to `0x00503060`.
- Nearby MapName/MiniMapButton vtable bytes do not contain `0x00503060`.
- The outgoing virtual call through `[eax+20h]` identifies a receiver call, not the helper's source owner.
- The target reads broad global `g_useEpfAssets`; read-only consumer evidence is insufficient for ownership.
- The target calls generic rectangle initializer `0x004b7c50`; callee use is insufficient for ownership.
- There is no proven source-use emitter route. `EMITTER_UIDS` should stay blank.

Evidence against:

- The helper strongly resembles retained UI/resource code and sits in an address cluster adjacent to MapNamePane.
- Sibling [UID:0002BF] now has a valid MapName route, making the source-family neighborhood less ambiguous.

Decision:

- Accepted. The positive evidence is enough to keep the item reconstructable and guide future MapName/MapPane research, but not enough to assign canonical owner or emitters.

### 2. [UID:00007P] `MapNamePane` / [UID:0000L2] `MapNamePane.cpp` - best rejected candidate

Evidence for:

- Target sits immediately before the MapName constructor island.
- Target and sibling [UID:0002BE] use `g_useEpfAssets` and the `0xa6` / 166 and `0xad` / 173 rectangle-width pair (Verified with `int_convert`).
- `0xad` / 173 matches the MapName update handler clamp width.
- Sibling [UID:0002BF] now has a valid MapName route through the `this + 0x220` / 544 font field (Verified with `int_convert`).
- MapNamePane file/class parents clear the numeric gate and have strong vtable/resource/lifecycle evidence.

Evidence against:

- `xrefs_to 0x00503060` remains empty.
- MapName vtables do not contain `0x00503060`.
- IDA `find_bytes` finds no VA/RVA pointer to the target.
- PE scan finds no relative call/jump/branch to the target.
- The target does not access `MapNamePane`-specific fields such as `this + 0x220`.
- The target's receiver type is generic in the raw body; it only calls virtual slot `+0x20`.
- Sibling [UID:0002BF] has MapName field-lifecycle evidence; [UID:0002BD] does not.

Decision:

- Rejected as a metadata action. MapNamePane is the best source-family hypothesis if forced, but it does not clear the canonical-owner or emitter gate for [UID:0002BD].

### 3. Multiple emitters through MapNamePane and MiniMapButton/MiniMap - rejected

Evidence for:

- The raw cluster physically borders a mixed MapName/MiniMapButton island.
- The EPF/current-mode global is read by many UI modules.

Evidence against:

- No source-use context is proven for even one emitter, much less multiple emitters.
- This is a function body with a unique binary signature, not a pooled literal or shared constant.
- Multiple `EMITTER_UIDS` would duplicate a single unreferenced helper into multiple generated source files without evidence.
- MiniMapButton-specific evidence (`MMAPBUT.EPF`, vtables, constructor caller, singleton) does not touch the target.

Decision:

- Reject. No emitters are justified.

### 4. [UID:00008B] `MiniMapButtonPane` / [UID:0000LE] `MiniMap` - rejected

Evidence for:

- Address-adjacent to the mixed MapName/MiniMapButton island.
- MiniMapButtonPane is a real owner nearby with vtable data and resource string evidence.

Evidence against:

- Target has no `MMAPBUT.EPF`, MiniMapButton singleton, hover/down state, mouse event, or minimap-specific callee.
- MiniMapButton vtables do not contain `0x00503060`.
- Its resource/paint path at `0x00503650` is independent.
- No xrefs or branch targets connect MiniMapButton code to the target.

Decision:

- Reject.

### 5. [UID:0000L0] `MainMenuPane` - rejected

Evidence for:

- MainMenu helper [UID:00022Y] ends just before the target.
- The broader address area is near login/main menu code.

Evidence against:

- Four `0xcc` bytes separate the MainMenu helper end at `0x0050305c` from target start `0x00503060`.
- MainMenu helper ownership is supported by direct packet-handler calls; the target has no comparable caller.
- Target behavior is UI asset-mode rectangle dispatch, not packet parsing or URL/static text handling.

Decision:

- Reject.

### 6. [UID:0000SW] `g_useEpfAssets` / [UID:0000O5] `StartupWindow` - rejected

Evidence for:

- Target reads `byte_66DA97`.
- `g_useEpfAssets` has a documented source-owner inference through `StartupWindow`.

Evidence against:

- The target is only a consumer of a broad process-wide mode flag.
- The target does not write or initialize the global.
- Consumer reads of extern-like globals do not establish source ownership or emitter routing.

Decision:

- Reject. Keep as dependency evidence only.

### 7. [UID:00015S] `RectGeometryHelpers` / `RectBounds` - rejected

Evidence for:

- Target calls `sub_4B7C50`, documented as a rectangle initializer.

Evidence against:

- The initializer has broad fan-in and is a generic geometry primitive.
- The target is not geometry support; it is UI helper logic using a rectangle.

Decision:

- Reject. Keep as callee dependency only.

### 8. New `MapNameUiResourceTextHelpers.cpp` or `MapPaneResourceTextHelpers.cpp` grouping - rejected for now

Evidence for:

- A narrow helper source file could theoretically contain the three raw helpers, especially [UID:0002BD] and [UID:0002BE].
- The cluster has a real source-shaped helper pattern and sits next to MapName code.

Evidence against:

- No source metadata, object-file boundary, caller, table, vtable, or broader contents prove a standalone helper file.
- Creating a file owner would be a stronger claim than the evidence supports.
- Existing [UID:00022Z] already provides a non-emitting physical inventory for the unresolved cluster.
- If these were source-level private helpers, they more likely belonged inside MapName/MapPane source than in a standalone file, but that still lacks direct proof for [UID:0002BD].

Decision:

- Reject for current metadata. If future map/source-boundary evidence appears, research all three children together before creating a new file/grouping.

### 9. Compiler-generated / runtime / ignored classification - rejected

Evidence for:

- IDA does not model a function object at the target start.
- No xrefs reach the target.

Evidence against:

- Body is not padding and not a known CRT helper: it has project-specific branch logic, a project global read, a project rectangle helper call, and a virtual dispatch.
- The unique source-shaped byte signature supports retained project code.
- The exact aggregate is already split; only [UID:00022Z] is a non-reconstructable container.

Decision:

- Reject. Keep [UID:0002BD] `RECONSTRUCTABLE:TRUE`.

## Negative Evidence Summary

Checked and rejected:

- IDA function object at `0x00503060`: none.
- Direct xrefs to `0x00503060`: zero.
- Raw absolute VA and RVA references to the target and siblings: zero.
- Relative call/jump/branch targets to the target and siblings: zero.
- Nearby MapName/MiniMapButton vtable slots: no target entry.
- Direct MapName ownership by sibling [UID:0002BF]: rejected as transferable evidence because [UID:0002BD] lacks the `this + 0x220` field access that justifies [UID:0002BF].
- MiniMap ownership: rejected because MiniMap-specific resource/vtable/singleton evidence does not touch the target.
- MainMenu ownership: rejected because the left neighbor has direct packet-handler evidence and a padding boundary; target does not.
- `g_useEpfAssets` owner route: rejected because the target is only a reader.
- `RectGeometryHelpers` route: rejected because the target is only a caller.
- New helper file: rejected because no standalone source-unit boundary or contents are proven.
- Multi-emitter route: rejected because no source-use emitter is proven and the target is unique function code, not pooled data.

## Final Recommendation

Exact metadata recommendation:

```text
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Exact parent/emitter assignments recommended:

- `CANONICAL_OWNER:NONE`
- `EMITTER_UIDS:` blank
- No canonical owner.
- No single emitter.
- No multiple emitters.

Exact items left no-owner/non-emitting and why:

- [UID:0002BD] remains no-owner/non-emitting because no direct owner or source-use route clears the gate.
- [UID:0002BE] remains sibling context only; do not use it to route [UID:0002BD].
- [UID:0002BF] remains MapName-owned but does not transfer ownership to [UID:0002BD].
- [UID:00022Z] remains non-emitting inventory, not a source owner.

Coverage/report actions:

- No `by-memory/-coverage-report.md` edit is required.
- Do not directly edit `auto-generated/-ag-memory-coverage.md`; it is generated.
- Do not reclassify the target as ignored or non-reconstructable.

Current generated row to retain:

```text
| [UID:0002BD][0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper](by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md` |  |
```

Current `by-memory/-coverage-report.md` row remains technically correct and does not need replacement:

```text
        - [UID:0002BD][0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper](by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) 0x00503060-0x005030bc | raw function | UiAssetModeRectVirtualDispatchHelper : reconstructable : 87% : strong : A003 Batch307 reconfirms no IDA function object/xrefs/raw pointer hits/PE-level absolute-VA/RVA/relative references/MapName-or-MiniMapButton-adjacent vtable slot, exact bytes through retn 4, stack-cookie body, data refs to g_useEpfAssets and security cookie, optional EPF/legacy RectBounds(0,0,0xa6/0xad,0x10) setup through sub_4B7C50, unconditional vtable slot +0x20 dispatch, MapName-width association without direct ownership, non-initializing state caveat, and blank parent because no caller/vtable/table owner is proven.
```

Optional tracker disposition text for supervisor:

```text
B001-0002BD-post-migration complete. Retain [UID:0002BD] as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, and blank C++: source-authored raw helper but no owner/emitter route clears the current split gate. MapName remains the best source-family lead, especially after sibling [UID:0002BF] was routed to [UID:00007P], but [UID:0002BD] itself has no caller, table/vtable slot, VA/RVA pointer, relative branch target, or MapName-private field evidence.
```

## Follow-Up Actions

Supervisor actions:

- Mark tracker row `0002BD` complete with no metadata or coverage changes.
- Leave target page metadata unchanged.
- Leave generated `auto-generated/-ag-memory-coverage.md` to validator generation.
- Do not add `EMITTER_UIDS:00007P` unless future evidence proves a MapName source-use route.

A-agent actions:

- No immediate by-* repair is required.
- Future MapName/MapPane audits should keep [UID:0002BD] and [UID:0002BE] as unresolved sibling leads, not as assigned MapName children.

B001 future research actions:

- If future evidence discovers an object-file/source-unit boundary, hidden callback table, manual dispatch table, or runtime registration for any raw start in `0x00503060-0x005031e1`, re-evaluate [UID:0002BD], [UID:0002BE], and [UID:0002BF] as a cluster.
- If a new MapName/MapPane helper source file is proposed, explicitly include or reject [UID:0002BD] and [UID:0002BE] with fresh IDA evidence rather than inheriting [UID:0002BF]'s class-field route.

## Confidence

- Boundary and behavior confidence: `94/100`. Repeated IDA MCP evidence, raw bytes, unique signatures, and disassembly confirm the exact body and behavior.
- No-owner/no-emitter confidence: `92/100`. All normal direct-owner and source-use routes were checked and remain absent.
- MapName source-family hypothesis: `78/100`. Address adjacency, width constants, `g_useEpfAssets`, and sibling [UID:0002BF] support MapName-side retained helper code, but the target lacks direct owner evidence.
- Rejection of MiniMap direct route: `88/100`.
- Rejection of MainMenu direct route: `90/100`.
- Rejection of compiler/runtime/ignored classification: `95/100`.
- Remaining uncertainty: whether the helper is stale retained source, reachable through an unrecognized runtime mechanism, or a private helper from a MapName/MapPane object file whose direct reference was eliminated or never represented in this build.

## Validator / Validation Results

Validator was not run. No by-* documentation files or generated reports were edited, and the assignment explicitly banned dry-run validator modes. Normal live research validation performed instead:

> Executable block R001 was removed from this report and preserved verbatim in [0002BD-UiAssetModeRectVirtualDispatchHelper-post-migration-removed.md](0002BD-UiAssetModeRectVirtualDispatchHelper-post-migration-removed.md). The archived block is non-authoritative and must not be executed.

Result summary:

- IDA MCP session healthy, Hex-Rays ready.
- Target and siblings still not IDA function objects.
- Zero xrefs to raw starts.
- Zero VA/RVA pointer hits for raw starts.
- Unique target and sibling signatures.
- Target disassembly confirms behavior and dependencies.
- MapName decompilation confirms sibling [UID:0002BF]'s field route, but no equivalent target route.
- Local `.text` PE scan found zero relative call/jump/conditional branch targets to the three raw starts.

Unresolved validator warnings/errors:

- None, because validator was not run and no validator-managed by-* edits were made.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0002BD-UiAssetModeRectVirtualDispatchHelper-post-migration.md`
- Modified: none outside this B001 research report.
- Renamed: none.
- Moved to executed: none; supervisor owns execution/move.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002BD-UiAssetModeRectVirtualDispatchHelper-post-migration.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002BD"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002BD-UiAssetModeRectVirtualDispatchHelper-post-migration-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0002BD-UiAssetModeRectVirtualDispatchHelper-post-migration.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002BD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
