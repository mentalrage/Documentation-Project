** TARGET-REPORT-UID:0002BD **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BD UiAssetModeRectVirtualDispatchHelper Live Goal 2 No-Owner Pass

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002BD] `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md` as `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank reconstruction C++.
- Final disposition: no split, no reclassification, no new child pages, no canonical owner, and no emitters.
- Required action: no target metadata or coverage-report edit is required. The item remains a reconstructable but currently non-emitting raw helper because current IDA/PE evidence proves a source-shaped helper body but still proves no caller, table, vtable slot, direct branch, absolute/RVA pointer, or class-field evidence that would justify a source owner or generated-output route.
- Confidence: high for the no-owner/non-emitting recommendation under the current rules; medium-low for original source identity because the helper appears source-authored but remains unreferenced.

## Supporting Research

## Target

- Target UID: `0002BD`
- Target path: `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md`
- Source queue/report row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, section `Active 2026-06-14 Live Goal 2 No-Owner Memory Pass`, row for `0002BD`.
- Current supervisor classification: live Goal 2 no-owner/non-emitting memory pass.
- Current scores and state: `COMPLETION:87`, `CONFIDENCE:91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`.
- Current generated row: `auto-generated/-ag-memory-coverage.md` reports [UID:0002BD] as `no-owner` with owner `NONE` and blank emitters.

## Executive Recommendation

The best direct disposition remains no-owner/non-emitting. The helper is an exact source-shaped MSVC body at `0x00503060-0x005030bc`, but current evidence does not prove a source owner or source-use route. Assigning it to [UID:00007P] `MapNamePane`, [UID:0000L2] `MapNamePane.cpp`, [UID:00008B] `MiniMapButtonPane`, [UID:0000LE] `MiniMap`, [UID:0000N2] `RectBounds`, [UID:0000SW] `g_useEpfAssets`, or the aggregate [UID:00022Z] would be weaker than the by-structure direct-parent rule allows.

The target should remain reconstructable because its bytes are custom executable project code: stack-cookie frame, `g_useEpfAssets` branch, call to the rectangle initializer, and virtual dispatch through the receiver vtable. It should remain non-emitting because no confirmed emitter chain exists. This is not a pooled literal/multi-emitter case; it is code with no proven source context, so duplicating or routing it through consumers would invent source placement.

## Supervisor Active Recheck

- Triggering instruction: live Goal 2 no-owner/non-emitting memory pass for [UID:0002BD].
- Split repair needed: no. The target is already an exact child range with a normal prologue at `0x00503060`, `retn 4` at `0x005030b9`, and `0xcc` alignment at `0x005030bc-0x005030c0`.
- Child pages created: none.
- Parent/container status: [UID:00022Z] remains a non-emitting split inventory for the raw helper cluster, not a source owner or emitter.

## Inference Research Guidance Check

`by-structure.md` requires `CANONICAL_OWNER` to be the narrowest true semantic owner and `EMITTER_UIDS` to be confirmed output routing. It also explicitly allows `RECONSTRUCTABLE:TRUE` to remain no-owner/non-emitting while ownership and output route are unresolved. That rule is the key decision here.

`inference_research.md` warns that adjacency and consumer/read evidence are not enough to prove same-file ownership. I treated the MapName adjacency, the `0x00ad` width match, and sibling ownership as leads, not proof. The fresh IDA/PE checks did not supply the missing direct caller/table/vtable/source-use evidence.

## Evidence Standards Used

- IDA MCP session: `a001_goal2_class_batch`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, checked on 2026-06-14.
- IDA MCP tools used: `idb_list`, `lookup_funcs`, `xrefs_to`, `disasm`, `get_bytes`, `find_bytes`, `get_int`, `make_signature_for_range`, and `decompile`.
- Local PE byte scan: parsed PE sections from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, searched VA/RVA literals and direct rel32/rel8 branch targets.
- Documentation evidence: current target page, aggregate page, MapName/MiniMap candidates, RectBounds helper page, and `g_useEpfAssets` global page.

## IDA MCP Facts

- `lookup_funcs` reports `0x00503060`, `0x005030bc`, `0x005030c0`, `0x00503104`, `0x00503110`, and `0x005031e1` as `Not a function`.
- Neighbor functions remain modeled: `sub_502E30` at `0x00502e30` size `0x22c`; `sub_5031F0` at `0x005031f0` size `0xd3`; `sub_4B7C50` at `0x004b7c50` size `0x1f`.
- `xrefs_to` reports zero xrefs to `0x00503060`, `0x005030bc`, `0x005030c0`, `0x00503104`, and `0x00503110`.
- Raw bytes at `0x0050305c-0x005030c0` show four leading `0xcc` bytes, the helper body, `c2 04 00`, then four trailing `0xcc` bytes.
- `find_bytes` found zero direct little-endian hits for `60 30 50 00`, `bc 30 50 00`, `c0 30 50 00`, `04 31 50 00`, `10 31 50 00`, and `e1 31 50 00`.
- `make_signature_for_range 0x00503060-0x005030bc` returns a unique exact signature for the helper bytes.
- `decompile 0x004b7c50` confirms the callee writes four `_DWORD` fields: `a1[1]=a3`, `*a1=a2`, `a1[3]=a5`, `a1[2]=a4`. This supports the `RectBounds(left, top, right, bottom)` interpretation.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00503060-0x005030bc` | [UID:0002BD] `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md` | asset-mode rectangle virtual-dispatch helper | true | `NONE` | `87/91` | keep no-owner/non-emitting |
| `0x005030c0-0x00503104` | [UID:0002BE] `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` | sibling rectangle write helper | true | `NONE` | `87/91` | sibling lead only |
| `0x00503110-0x005031e1` | [UID:0002BF] `by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md` | sibling glyph renderer | true | [UID:00007P] | `87/91` | assigned to MapNamePane by separate `this+0x220` field evidence |
| `0x00503060-0x005031e1` | [UID:00022Z] aggregate | raw helper split inventory | false | `NONE` | `86/90` | non-emitting container |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00503060` | `xrefs_to`: 0 | No direct caller, table entry, or pointer reference to target entry. |
| `0x00503079` | data ref to `byte_66DA97` / [UID:0000SW] | The helper reads the process-wide EPF/current-layout selector. This is consumer evidence, not ownership. |
| `0x00503098` | call to `sub_4B7C50` / [UID:00015S] | Builds local rectangle bounds. Callee ownership does not make this helper a RectBounds-owned item. |
| `0x005030a8` | `call dword ptr [eax+20h]` | Virtual dispatch through the receiver vtable slot `+0x20`; no concrete vtable table slot to this helper was found. |
| `0x0061e5b4` range | vtable dword dump | Contains known MapName/MiniMapButton slots such as `0x00503840`, `0x00503350`, `0x005034a0`, `0x00503650`, `0x005036a0`, `0x00503821`, `0x00503900`, `0x0050382c`; no `0x00503060`. |

## Disassembly Facts

Fresh IDA disassembly at `0x00503060` has no function container but decodes the helper body:

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
5030a0  mov eax, [esi]
5030a2  lea ecx, [ebp-14h]
5030a5  push ecx
5030a6  mov ecx, esi
5030a8  call dword ptr [eax+20h]
5030b1  call @__security_check_cookie@4
5030b9  retn 4
5030bc  align 10h
```

This confirms behavior and also negative owner evidence: the body uses only `this` as a virtual-dispatch receiver and does not access MapName-private fields such as `this+0x220`.

## PE / Byte-Scan Facts

The local PE scan parsed `.text`, `.rdata`, `.data`, and `.rsrc` with image base `0x400000`.

For `0x00503060`, `0x005030bc`, `0x005030c0`, `0x00503104`, `0x00503110`, and `0x005031e1`, both VA and RVA literal counts are zero. A scan for any dword value inside `0x00503060-0x005030bc` outside the target body also found zero hits.

Direct branch/call scanning found no external `E8`, `E9`, `0F 8x`, short conditional branch, or short jump target into `0x00503060-0x005030bc`. One naive short-branch byte-pattern hit to `0x00503104` was inside the sibling helper's instruction bytes at `0x005030f6`, not a decoded instruction and not a reference to this target.

## Documentation Evidence And IDA Status

- Target page [UID:0002BD] already documents the exact range, source-authored behavior, blank owner/emitter state, `g_useEpfAssets` branch, `RectBounds` initializer, virtual slot dispatch, and prior no-xref/no-pointer evidence. Fresh IDA/PE checks confirm the core claims.
- Aggregate [UID:00022Z] correctly models the physical cluster as a non-emitting split inventory. It is not a valid source owner or emitter.
- [UID:00007P] `MapNamePane` and [UID:0000L2] `MapNamePane.cpp` clear the numeric assignment gate, but current IDA facts still do not tie `0002BD` to their vtables, fields, callers, or singleton lifecycle.
- [UID:0002BF] is a useful contrast: it is assigned to MapNamePane because it uniquely reads the MapName-owned `this+0x220` font field. `0002BD` does not share that evidence.
- [UID:0000SW] `g_useEpfAssets` and [UID:00015S] `RectGeometryHelpers` are dependencies/consumed utilities, not direct owners.

## Ranked Ownership Analysis

### 1. Keep `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`

- Evidence for: zero direct xrefs to entry and boundaries; zero VA/RVA literal hits; no external PE branch target into the helper; no vtable slot to the start; no class-private field access; aggregate is a non-source split inventory; target is already exact and coherent.
- Evidence against: the code is source-authored and adjacent to MapName/MiniMapButton code; the `0x00ad` width matches a MapName width; sibling `0002BF` now has MapName ownership.
- Decision: accepted. The positive leads do not meet direct owner/emitter proof.

### 2. [UID:00007P] `MapNamePane` / [UID:0000L2] `MapNamePane.cpp`

- Evidence for: immediate adjacency to the MapName/MiniMapButton island; `0x00ad` equals 173, matching documented MapName clamp width; `0002BF` sibling is MapName-owned through `this+0x220`.
- Evidence against: no caller, no direct branch, no table pointer, no MapName vtable slot, no `g_pMapNamePane` lifecycle link, and no MapName-private field access. `0002BF` has field evidence that this target lacks.
- Decision: rejected for current assignment. Best forced owner lead, but still too weak.

### 3. Narrow new `UiAssetModeRectHelpers` source grouping

- Evidence for: `0002BD` and `0002BE` are adjacent, both use `g_useEpfAssets`, both choose `0x00a6`/`0x00ad` width and height `0x10`, and both call `sub_4B7C50`.
- Evidence against: a grouping created only from adjacency and similar body shape would not have a file root, caller, table, declaration site, or generated-output route. It would not explain why the virtual-dispatch helper should emit anywhere.
- Decision: do not create now. Keep as a future hypothesis if a caller/table/source route is recovered.

### 4. [UID:00008B] `MiniMapButtonPane` / [UID:0000LE] `MiniMap`

- Evidence for: same nearby physical island and shared MapName/MiniMapButton read-only-data neighborhood.
- Evidence against: no minimap-button vtable slot, no minimap singleton/global evidence, no minimap resource literal, and no field or caller tie. The width constants are MapName-like, not MiniMapButton-specific.
- Decision: rejected.

### 5. [UID:0000N2] `RectBounds` / [UID:00015S] `RectGeometryHelpers`

- Evidence for: helper calls `sub_4B7C50`, the rectangle initializer.
- Evidence against: `RectBounds` is a utility dependency with broad fan-in. Calling an initializer does not make the caller part of the geometry source owner.
- Decision: rejected.

### 6. [UID:0000SW] `g_useEpfAssets` / [UID:0000O5] `StartupWindow`

- Evidence for: target reads `byte_66DA97`.
- Evidence against: the byte is a process-wide mode selector with hundreds of consumers; read xrefs do not prove ownership. StartupWindow is the global's best source owner, not the owner of every consumer.
- Decision: rejected.

### 7. [UID:00019I] MainMenu/Login aggregate

- Evidence for: the preceding modeled function range ends at `0x0050305c`.
- Evidence against: four `0xcc` bytes separate the preceding range from the target; no xrefs tie this helper to main-menu packet handling; the aggregate is mixed and non-reconstructable.
- Decision: rejected.

## Proposed New File / Grouping

- Proposed owner/name/path: none now.
- If future evidence forces a new owner, the narrow candidate would be `UiAssetModeRectHelpers` containing [UID:0002BD] and [UID:0002BE] only.
- Candidate related items that belong if proven: `0002BD`, `0002BE`, and any future recovered caller/table that references them.
- Candidate related items rejected now: `0002BF`, because it has separate MapNamePane `this+0x220` font-field evidence and different glyph-rendering behavior.
- Source-file inference: currently too weak to create. Standalone or broad source-file ownership would be speculative.

## Negative Evidence Summary

- Checked and rejected direct caller evidence: IDA `xrefs_to` returns zero for the target entry and boundary starts.
- Checked and rejected direct pointer evidence: IDA `find_bytes` and PE scans find no VA/RVA literal for target starts or boundaries.
- Checked and rejected direct branch evidence: no external direct branch/call target into `0x00503060-0x005030bc`.
- Checked and rejected nearby vtable evidence: MapName/MiniMapButton vtable dwords contain known adjacent methods and thunks, not `0x00503060`.
- Checked and rejected class-field evidence: fresh disassembly shows no MapName-private field access; only virtual dispatch through `[this->vtable + 0x20]`.
- Checked and rejected dependency ownership: `g_useEpfAssets` and `RectBounds` are dependencies, not declaration/source owners for this helper.

## Why Reconstructable But Non-Emitting Is Correct

`RECONSTRUCTABLE:TRUE` is correct because the bytes are not padding, CRT, import glue, or compiler-only metadata. They decode as custom project logic with UI asset-mode behavior and a virtual dispatch.

Blank `EMITTER_UIDS` is also correct. The current system requires a confirmed emitter route that surfaces to generated source output. This helper has no proven source-use context. Emitting it through MapNamePane, MiniMapButtonPane, RectBounds, or StartupWindow would turn weak association into generated source placement. This differs from pooled string-literal cases: there is no evidence that this code body must appear in multiple source contexts, and no evidence that any single context owns or uses it. The accurate state is therefore "source-authored code preserved for reconstruction research, but withheld from generated source until an owner or source route is proven."

## Final Recommendation

- Exact changes applied or recommended: no by-memory metadata change; no split; no child page creation; no target rename; no score change.
- Exact parent assignments recommended: keep `CANONICAL_OWNER:NONE`.
- Exact emitters recommended: keep `EMITTER_UIDS:` blank.
- Exact items left no-owner/non-emitting and why: [UID:0002BD] remains no-owner/non-emitting because the fresh IDA/PE pass still found no direct semantic owner or generated-output route.
- Coverage-report row text: no required change. If the supervisor wants to refresh provenance wording only, the replacement child row can be:

```text
        - [UID:0002BD][0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper](by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) 0x00503060-0x005030bc | raw function | UiAssetModeRectVirtualDispatchHelper : reconstructable : 87% : strong : B003 live Goal 2 no-owner pass reconfirms source-shaped raw helper body but no owner/emitter route: live IDA session a001_goal2_class_batch reports no function object at 0x00503060, zero xrefs to the entry/end/sibling boundaries, exact body bytes with 0xcc padding, unique exact range signature, byte_66DA97/RectBounds(0,0,0xa6/0xad,0x10) setup through sub_4B7C50, unconditional vtable slot +0x20 dispatch, no VA/RVA pointer hits to target starts or boundaries, no external PE-level direct branch target into 0x00503060-0x005030bc, no MapName/MiniMapButton vtable slot, and no MapName-private this+0x220 field access. MapName width and sibling 0002BF association remain the best owner leads but are insufficient for canonical ownership or emitter routing.
```

## Follow-Up Actions

- Supervisor actions: none required for metadata. Optional coverage row provenance refresh text is provided above.
- A-agent actions: do not assign this item to MapNamePane, MiniMapButtonPane, RectBounds, `g_useEpfAssets`, or [UID:00022Z] unless new direct caller/table/vtable/field evidence appears.
- Future research triggers: re-open if an indirect-call table, callback registration, old source map, PDB/source breadcrumb, runtime trace, or additional table scan identifies a call/source route to `0x00503060`.

## Confidence

- Recommendation confidence: high.
- Score confidence: keep current `87/91`; no score change justified by this report because the current page already records the same core evidence level.
- Remaining uncertainty: original source name, live reachability, concrete vtable slot semantics, and whether the code is dead retained source or reachable through an unmodeled mechanism.

## Validator Results

- Commands run: none.
- Results: not applicable. No by-* documentation files or coverage reports were edited.
- Unresolved validator warnings/errors: none introduced by this report-only pass.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/0002BD-UiAssetModeRectVirtualDispatchHelper-live-goal2-no-owner-pass.md`
- Modified: none outside this research report.
- Renamed: none.
- Moved to executed: none.
- Leases used: none. The only edited file is inside Agent-B003's own research folder, which does not require a lease.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002BD-UiAssetModeRectVirtualDispatchHelper-live-goal2-no-owner-pass.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0002BD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
