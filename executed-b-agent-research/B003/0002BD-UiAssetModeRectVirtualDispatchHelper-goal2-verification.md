** TARGET-REPORT-UID:0002BD **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BD UiAssetModeRectVirtualDispatchHelper Goal 2 Verification

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002BD] `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md` as `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank reconstruction C++.
- Final disposition: no owner assignment, no emitter route, no split, no merge, no reclassification, no rename, no IDA repair, and no target score change.
- Required action: no by-memory metadata edit and no `by-memory/-coverage-report.md` row replacement is required. The current shared coverage row already states the correct no-owner/non-emitting outcome and the same owner-negative evidence.
- Confidence: high for the current no-owner/non-emitting recommendation; medium-low for original source identity because the helper is source-authored but still has no proven live source-use route.

## Supporting Research

## Target

- Target UID: `0002BD`
- Target path: `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md`
- Source queue/report row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, section `Active 2026-06-14 Goal 2 No-Owner Memory Verification Pass`.
- Coverage source: `auto-generated/-ag-memory-coverage.md`
- Current generated state: `no-owner`, owner `NONE`, blank emitters, no generated output path.
- Current target metadata: `COMPLETION:87`, `CONFIDENCE:91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`.
- Prior report reviewed as evidence only: `tools/leaser/Agents/Agent-B003/research/executed/0002BD-UiAssetModeRectVirtualDispatchHelper-live-goal2-no-owner-pass.md`.

## Executive Recommendation

The current no-owner/non-emitting state is still correct. Fresh current documentation review and live IDA MCP evidence confirm that `0x00503060-0x005030bc` is an exact source-shaped helper body, but the binary still provides no caller, table pointer, vtable slot, branch target, source-use context, or class-private field evidence that would justify a canonical owner or emitter.

The helper should remain reconstructable because it is executable custom project code: it has a normal MSVC stack-cookie frame, reads `byte_66DA97` / [UID:0000SW] `g_useEpfAssets`, optionally initializes a `RectBounds(0, 0, 0xa6/0xad, 0x10)` through `sub_4B7C50`, and dispatches through the receiver vtable slot `+0x20`. It should remain non-emitting because the current system requires a confirmed emitter route to generated source, and no such route is present.

This is not a pooled literal or shared constant case. There are no proven source-use contexts, so adding one or more emitters would invent source placement instead of reconstructing it.

## Supervisor Active Recheck

- Triggering instruction: fresh Goal 2 no-owner memory verification for [UID:0002BD].
- Split repair needed: no. The target is already a clean exact child under [UID:00022Z] `0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers`.
- Child pages created: none.
- by-* edits made: none.
- Lease needed: none, because the only created file is this report inside Agent-B003's research folder.
- Coverage-report edit needed: none.

## Inference Research Guidance Check

`by-structure.md` requires `CANONICAL_OWNER` to be the narrowest true semantic owner and `EMITTER_UIDS` to be proven generated-output routing, not just a convenient place to put code. It also allows source-authored code to stay `RECONSTRUCTABLE:TRUE` while owner and emitter routing remain unresolved.

`inference_research.md` treats address adjacency, nearby data, and consumer reads as hypothesis evidence, not declaration/source ownership proof. I applied that here: MapName adjacency, the `0x00ad` width match, sibling `0002BF` MapName ownership, `g_useEpfAssets` consumption, and `RectBounds` utility calls were all checked as leads, but none supplies the missing caller/table/vtable/field route for this target.

## Evidence Standards Used

- IDA MCP session: `a001_goal2_class_batch`
- IDB/input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64` / `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- MCP status on 2026-06-14: server health `ok`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready.
- IDA tools used: `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `find_bytes`, `make_signature_for_range`, `insn_query`, `decompile`, `get_int`, `xref_query`, and `entity_query`.
- Local binary check: section-aware PowerShell PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for VA/RVA literals and external direct branch/call targets.
- Documentation evidence: current target page, parent aggregate, sibling raw helpers, MapName/MiniMap candidate pages, RectGeometryHelpers, `g_useEpfAssets`, generated memory coverage, and current shared by-memory coverage row.

## IDA MCP Facts

- `lookup_funcs` reports `0x00503060`, `0x005030bc`, `0x005030c0`, `0x00503104`, `0x00503110`, and `0x005031e1` as `Not a function`.
- Neighbor functions remain modeled: `sub_502E30` at `0x00502e30` size `0x22c`; `sub_5031F0` at `0x005031f0` size `0xd3`; `sub_4B7C50` at `0x004b7c50` size `0x1f`.
- `xrefs_to` reports zero xrefs to `0x00503060`, `0x005030bc`, `0x005030c0`, `0x00503104`, and `0x00503110`.
- The only xrefs to interior target addresses are internal flow edges from the raw body itself: `0x00503077 -> 0x00503079` and `0x00503097 -> 0x00503098`.
- `get_bytes` for `0x0050305c` shows four leading `0xcc` bytes, the helper bytes beginning `55 8b ec 83 ec 14`, `retn 4` bytes `c2 04 00`, then four trailing `0xcc` bytes before sibling `0x005030c0`.
- `find_bytes` returns zero matches for VA and RVA little-endian encodings of `0x00503060`, `0x005030bc`, `0x005030c0`, `0x00503104`, `0x00503110`, and `0x005031e1`.
- `make_signature_for_range 0x00503060-0x005030bc` returns a unique wildcarded IDA-format signature for the helper body.
- `decompile 0x004b7c50` confirms the callee writes four `_DWORD` fields: `a1[1] = a3`, `*a1 = a2`, `a1[3] = a5`, `a1[2] = a4`, supporting the documented `RectBounds(left, top, right, bottom)` interpretation.
- `xref_query` for MapName vtable heads `0x0061e5b4`, `0x0061e600`, and `0x0061e630` returns only normal constructor/destructor/scalar-deleting-destructor stores from `sub_5031F0`, `sub_5032D0`, and `sub_503840`; it does not expose a route to `0x00503060`.

## Disassembly Facts

Fresh `insn_query` over `0x00503060-0x005030bc` decodes 34 instructions and no owning function container:

```asm
503060  push ebp
503061  mov ebp, esp
503063  sub esp, 14h
503066  mov eax, ___security_cookie
503070  sub dword ptr [ebp+8], 1
503074  push esi
503075  mov esi, ecx
503077  jnz short loc_5030A0
503079  cmp byte_66DA97, 1
503080  lea eax, [ebp-14h]
503083  push 10h
503085  jnz short loc_50308E
503087  push 0A6h
50308c  jmp short loc_503093
50308e  push 0ADh
503093  push 0
503095  push 0
503097  push eax
503098  call sub_4B7C50
50309d  add esp, 14h
5030a0  mov eax, [esi]
5030a2  lea ecx, [ebp-14h]
5030a5  push ecx
5030a6  mov ecx, esi
5030a8  call dword ptr [eax+20h]
5030ab  mov ecx, [ebp-4]
5030ae  xor ecx, ebp
5030b0  pop esi
5030b1  call @__security_check_cookie@4
5030b6  mov esp, ebp
5030b8  pop ebp
5030b9  retn 4
```

The disassembly confirms the positive behavior and the owner blocker: this helper does not read a MapNamePane-private field such as `this+0x220`; it only keeps `this` in `esi` and performs an indirect virtual call through `[this->vtable + 0x20]`.

## Vtable / Read-Only Data Facts

The current IDA `get_int` dump for `0x0061e5b4-0x0061e704` includes real nearby MapName/MiniMapButton slots:

| Vtable address | Value |
| --- | --- |
| `0x0061e5b4` | `0x00503840` |
| `0x0061e5f8` | `0x00503350` |
| `0x0061e600` | `0x0050380b` |
| `0x0061e610` | `0x005034a0` |
| `0x0061e630` | `0x00503816` |
| `0x0061e63c` | `0x00503900` |
| `0x0061e680` | `0x00503650` |
| `0x0061e688` | `0x00503821` |
| `0x0061e68c` | `0x005036a0` |
| `0x0061e6b8` | `0x0050382c` |

The same dump does not contain `0x00503060`. This rejects the obvious "hidden MapName/MiniMapButton vtable slot" route.

## Local PE / Byte-Scan Facts

The local PE scan parsed `NexusTK.exe` with image base `0x00400000` and sections:

| Section | VA range |
| --- | --- |
| `.text` | `0x00401000-0x0060c600` |
| `.rdata` | `0x0060d000-0x0066c200` |
| `.data` | `0x0066d000-0x0069ce24` |
| `.rsrc` | `0x0069d000-0x006b2e00` |

Literal scan results were zero VA hits and zero RVA hits for `0x00503060`, `0x005030bc`, `0x005030c0`, `0x00503104`, `0x00503110`, and `0x005031e1`.

External direct branch/call scanning of `.text` found no `E8`, `E9`, `0F 8x`, `70-7F`, or `EB` target from outside the target range into `0x00503060-0x005030bc`. The only branch targets into the target body are the helper's own internal short branches at `0x00503077`, `0x00503085`, and `0x0050308c`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00503060-0x005030bc` | [UID:0002BD] `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md` | asset-mode rectangle virtual-dispatch helper | true | `NONE` | `87/91` | keep no-owner/non-emitting |
| `0x005030c0-0x00503104` | [UID:0002BE] `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` | sibling rectangle write helper | true | `NONE` | `87/91` | sibling lead only |
| `0x00503110-0x005031e1` | [UID:0002BF] `by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md` | sibling glyph renderer | true | [UID:00007P] `MapNamePane` | `87/91` | assigned by separate `this+0x220` field evidence |
| `0x00503060-0x005031e1` | [UID:00022Z] aggregate | raw helper split inventory | false | `NONE` | `86/90` | non-emitting container |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00503060` | `xrefs_to`: 0 | No direct caller, table entry, pointer reference, or vtable slot to the entry. |
| `0x00503079` | `cmp byte_66DA97, 1` | Consumes the process-wide EPF/current-layout selector; this is dependency evidence, not ownership. |
| `0x00503098` | `call sub_4B7C50` | Calls shared rectangle initializer; utility use does not make the caller owned by RectBounds. |
| `0x005030a8` | `call dword ptr [eax+20h]` | Virtual dispatch through receiver vtable slot `+0x20`; no concrete vtable table entry to the helper was found. |
| `0x0061e5b4-0x0061e704` | vtable dword dump | Contains adjacent MapName/MiniMapButton methods, not `0x00503060`. |

## Documentation Evidence And IDA Status

- Target page [UID:0002BD] already records the exact range, source-authored behavior, no-owner/no-emitter state, repeated no-xref checks, `g_useEpfAssets` branch, `RectBounds` initializer, and virtual dispatch. Fresh IDA and PE checks confirm the core claims.
- Parent aggregate [UID:00022Z] is correctly `RECONSTRUCTABLE:FALSE` as a non-emitting physical split inventory. It is not a semantic source owner or emitter for the child.
- Sibling [UID:0002BE] remains a no-owner rectangle writer; it strengthens the hypothesis that `0002BD` belongs to a small UI asset-mode rectangle helper family, but it does not add an output route.
- Sibling [UID:0002BF] is now assigned to [UID:00007P] `MapNamePane`, but that assignment depends on the glyph renderer reading `this+0x220`, the same font-table field initialized and freed by MapNamePane. `0002BD` lacks that field evidence.
- [UID:00007P] `MapNamePane` and [UID:0000L2] `MapNamePane.cpp` clear the numeric gate, but the fresh checks still show no caller, vtable slot, table pointer, singleton lifecycle link, or private field access tying this target to MapName.
- [UID:0000SW] `g_useEpfAssets` is an input dependency. Its broad 366-xref role makes it unsuitable as a helper owner.
- [UID:00015S] `RectGeometryHelpers` / `sub_4B7C50` is a utility dependency with broad fan-in. It does not own every caller that initializes a rectangle.

## Ranked Ownership Analysis

### 1. Keep `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`

- Evidence for: exact source-shaped helper body; zero entry/boundary xrefs; zero VA/RVA literal hits; no external direct branch/call into the target; no vtable slot to `0x00503060`; no class-private field access; parent aggregate is a non-source container; target has no proven source-use context.
- Evidence against: helper is address-adjacent to MapName/MiniMapButton code, `0x00ad` matches the documented MapName 173-pixel clamp, and sibling `0002BF` now has MapNamePane ownership.
- Decision: accepted. The positive leads are association evidence, not direct owner or emitter evidence.

### 2. [UID:00007P] `MapNamePane` / [UID:0000L2] `MapNamePane.cpp`

- Evidence for: immediate adjacency to the MapName/MiniMapButton island; `0x00ad` equals the documented 173-pixel map-name clamp; sibling `0002BF` is assigned to MapNamePane.
- Evidence against: no caller, no direct branch, no raw pointer, no MapName vtable slot, no `g_pMapNamePane` lifecycle tie, and no `this+0x220` or other MapName-private field access in this helper.
- Decision: rejected for assignment. This is the best forced owner lead, but it remains too weak under current rules.

### 3. New `UiAssetModeRectHelpers` source grouping

- Evidence for: [UID:0002BD] and [UID:0002BE] are adjacent, both use `g_useEpfAssets`, both select `0x00a6`/`0x00ad` and height `0x10`, and both call `sub_4B7C50`.
- Evidence against: no caller, source file root, table, declaration site, or emitter chain proves such a source unit existed or shows where it should emit.
- Decision: do not create now. Keep as a future hypothesis if a caller/table/source route is recovered.

### 4. [UID:00008B] `MiniMapButtonPane` / [UID:0000LE] `MiniMap`

- Evidence for: same nearby physical island and shared MapName/MiniMapButton read-only-data neighborhood.
- Evidence against: no MiniMapButton vtable slot, no minimap singleton/global evidence, no minimap resource literal, no class field, and width constants are more MapName-like than MiniMapButton-specific.
- Decision: rejected.

### 5. [UID:0000N2] `RectBounds` / [UID:00015S] `RectGeometryHelpers`

- Evidence for: target calls the rectangle initializer at `0x004b7c50`.
- Evidence against: utility calls do not prove source ownership; `RectBounds` helpers are shared primitives with broad fan-in.
- Decision: rejected.

### 6. [UID:0000SW] `g_useEpfAssets` / [UID:0000O5] `StartupWindow`

- Evidence for: target reads `byte_66DA97`, and the global page currently routes the global declaration to StartupWindow as the best setter-side owner.
- Evidence against: the byte is a process-wide mode selector; read consumers do not become StartupWindow-owned code.
- Decision: rejected.

### 7. [UID:00019I] MainMenu/Login aggregate

- Evidence for: the preceding modeled helper range ends nearby at `0x0050305c`.
- Evidence against: four `0xcc` bytes separate the previous range from this target; no xrefs tie this helper to MainMenu/Login packet handling; the broad aggregate is a mixed non-emitting container.
- Decision: rejected.

## Negative Evidence Summary

- No IDA function object at target or sibling raw starts.
- No IDA xrefs to target entry or relevant boundaries.
- No VA/RVA literal references to the target or sibling boundaries.
- No external direct PE branch/call target into `0x00503060-0x005030bc`.
- No MapName/MiniMapButton vtable slot to `0x00503060`.
- No MapName-private `this+0x220` or equivalent field access.
- No proven source-use context and no valid emitter chain.
- No mixed-range or boundary problem requiring split repair.

## Why Reconstructable But Non-Emitting Is Correct

`RECONSTRUCTABLE:TRUE` is correct because the bytes are custom project executable logic, not padding, CRT code, import glue, vtable data, or compiler metadata. They implement source-level UI behavior that would matter if the original source route is recovered.

Blank `EMITTER_UIDS` is also correct because the generated-output system requires a confirmed route to a source-emitting owner. This helper has no direct source-use context. Routing it through MapNamePane, MiniMapButtonPane, RectBounds, StartupWindow, or a new helper file would turn weak association into output source. The accurate current model is therefore source-authored code preserved as reconstructable research, withheld from generated source until a real owner or source route is proven.

## Final Recommendation

- Exact changes applied: created this report only.
- Exact by-memory metadata changes recommended: none.
- Exact parent assignments recommended: keep `CANONICAL_OWNER:NONE`.
- Exact emitters recommended: keep `EMITTER_UIDS:` blank.
- Exact coverage-report update needed: none. Do not edit `by-memory/-coverage-report.md` for this pass.
- Exact future trigger for reopening: a recovered indirect-call table, callback registration, vtable slot, runtime trace, old source/PDB/map breadcrumb, or additional table scan that references `0x00503060`.

## Follow-Up Actions

- Supervisor actions: mark this verification as complete-no-change if accepted.
- A-agent actions: do not assign this item to MapNamePane, MiniMapButtonPane, RectBounds, `g_useEpfAssets`, StartupWindow, or [UID:00022Z] without new direct route evidence.
- B003 future research actions: none for this target unless new reference evidence appears.

## Confidence

- Recommendation confidence: high.
- Score confidence: keep current `87/91`; no score change is justified because the current target page already records the same evidence level and remaining uncertainty.
- Remaining uncertainty: original source name, live reachability, concrete vtable slot semantics, and whether the helper is dead retained code or reachable through a mechanism not represented by the checked xrefs/pointers/branches/vtables.

## Validator Results

- Commands run: none.
- Results: not applicable; no by-* documentation or coverage report files were edited.
- Unresolved validator warnings/errors: none introduced.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/0002BD-UiAssetModeRectVirtualDispatchHelper-goal2-verification.md`
- Modified: none outside this research report.
- Renamed: none.
- Moved to executed: none.
- Leases used: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002BD-UiAssetModeRectVirtualDispatchHelper-goal2-verification.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0002BD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
