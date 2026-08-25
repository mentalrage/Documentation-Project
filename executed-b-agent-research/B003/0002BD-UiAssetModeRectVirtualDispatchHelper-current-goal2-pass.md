** TARGET-REPORT-UID:0002BD **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BD UiAssetModeRectVirtualDispatchHelper Current Goal 2 Pass

## Finalized Recommendation

Keep [UID:0002BD] `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md` as a reconstructable but currently unowned and non-emitting raw helper.

- Keep `COMPLETION:87` and `CONFIDENCE:91`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `CANONICAL_OWNER:NONE`.
- Keep `EMITTER_UIDS:` blank and `EMITTER_POSITION_OPTIONAL:` blank.
- Keep `RECONSTRUCTION_CPP` blank. The item is above 90 confidence, but it is still below 90 completion and lacks proven owner/emitter/source placement, so it does not clear the current 90/90+ code-entry gate.
- Do not split, merge, reclassify, rename, or apply an IDA-safe name repair for this target in the current pass.

This is a valid last-resort no-owner/non-emitting result under the current owner/emitter model. The executable body is source-shaped project UI code, but no current evidence proves a direct semantic owner or output route. Assigning it to MapNamePane, MiniMapButtonPane, MainMenu, RectBounds, StartupWindow, or a new source file would rely on adjacency/theme rather than caller, table, field, or source-placement evidence.

## Target And Scope

- UID: `0002BD`
- Target path: `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md`
- Address range: `0x00503060-0x005030bc`
- Current generated state: `no-owner`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`
- Current target metadata: `87/91`, `RECONSTRUCTABLE:TRUE`
- Current by-memory coverage row: `87% : strong`
- Assigned pass source: current Goal 2 no-owner/non-emitting memory recheck.
- Prior B002/B003 reports were read as leads only. This recommendation is based on the current target page, current generated coverage, related docs, live IDA MCP checks, and a fresh PE/raw executable scan.

## Evidence Standards Used

I applied the current `by-structure.md` rules:

- `CANONICAL_OWNER` is the direct semantic/source owner, not merely the nearest file, class, or address-neighbor.
- `EMITTER_UIDS` is generated-output routing and can differ from ownership.
- Shared literals/data can remain `CANONICAL_OWNER:NONE` while gaining multiple emitters when proven source-use contexts exist.
- This target is a unique executable helper, not a pooled literal/data item. Blank emitters are correct unless a source-use/output route is proven.
- A reconstructable item can remain no-owner/non-emitting while research continues. Do not invent ownership or emit C++ from plausible but unproven placement.
- Reconstruction C++ requires the active 90/90+ source-output gate: item behavior, owner/emitter route, dependencies, names, boundaries, and source placement must be effectively complete.

## Current Documentation Evidence

The target page already records the same state the live checks reconfirmed:

- raw UI asset-mode rectangle helper;
- parent documentation aggregate [UID:00022Z] `0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers`;
- no IDA function object;
- no direct caller/start xrefs;
- source-shaped body using `g_useEpfAssets`, `RectBounds`, and virtual dispatch;
- likely but unproven broad association with nearby MainMenu/MapName/MiniMap UI code;
- blank `CANONICAL_OWNER` equivalent now represented as `CANONICAL_OWNER:NONE`;
- blank `EMITTER_UIDS`;
- blank reconstruction C++ because owner/source placement remains unresolved.

The current generated memory coverage row at `auto-generated/-ag-memory-coverage.md` lists:

```text
| [UID:0002BD][0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper](by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md` |  |
```

That generated row is still correct.

## Live IDA MCP Facts

IDA MCP session used for this pass:

- Session: `b001_0003gy`
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`
- Image base: `0x00400000`
- Auto-analysis: ready
- Hex-Rays: ready
- Strings cache: ready

### Function Boundary Inventory

`lookup_funcs` reported no IDA function object for this target or the adjacent raw helper starts:

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

Positive surrounding controls are normal functions:

| Address | Function |
| --- | --- |
| `0x00502e10` | `sub_502E10`, size `0x11` |
| `0x00502e30` | `sub_502E30`, size `0x22c` |
| `0x005031f0` | `sub_5031F0`, size `0xd3` |
| `0x005032d0` | `sub_5032D0`, size `0x7d` |
| `0x00503350` | `sub_503350`, size `0x14f` |
| `0x005034a0` | `sub_5034A0`, size `0xd4` |
| `0x00503580` | `sub_503580`, size `0x9e` |
| `0x00503650` | `sub_503650`, size `0x42` |
| `0x005036a0` | `sub_5036A0`, size `0x14d` |
| `0x004b7c50` | `sub_4B7C50`, size `0x1f` |

`entity_query` for `0x00502e00-0x00503980` listed the same modeled functions and left the raw helper cluster `0x00503060-0x005031e1` unmodeled.

### Target Body

Current disassembly of `0x00503060`:

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
005030bc  align 10h
```

Behavior facts:

- Receives `this` in `ecx` and one stack argument.
- Decrements the stack argument and initializes the local rectangle only when the adjusted value is zero.
- Tests `byte_66DA97` / `g_useEpfAssets`.
- Builds `RectBounds(0, 0, 0xa6, 0x10)` for current/EPF assets and `RectBounds(0, 0, 0xad, 0x10)` for the alternate branch through `sub_4B7C50`.
- Always dispatches through receiver vtable slot `+0x20` with the local rectangle pointer.
- Contains normal stack-cookie instrumentation but is not compiler/runtime-only residue.

The non-initializing state path remains a caller-contract caveat: if the decremented state is nonzero, the helper still dispatches with the local rectangle address. No current caller proves whether real source only passed the initializing state or whether the receiver tolerated/ignored the argument in other states.

### Xrefs And Reachability

`xrefs_to` results for target entry, useful interiors, and sibling starts:

| Address | Xrefs |
| --- | --- |
| `0x00503060` | none |
| `0x00503070` | internal only from `0x0050306d` |
| `0x00503079` | internal only from `0x00503077` |
| `0x00503098` | internal only from `0x00503097` |
| `0x005030a0` | internal only from `0x0050309d` and `0x00503077` |
| `0x005030a8` | internal only from `0x005030a6` |
| `0x005030bc` | none |
| `0x005030c0` | none |
| `0x00503110` | none |

Positive controls show IDA is reporting normal route evidence nearby:

| Address | Xrefs |
| --- | --- |
| `0x005031f0` | code xrefs from `0x004f8051` and `0x004f8695` |
| `0x00503350` | data xref at `0x0061e5f8` |
| `0x005034a0` | data xref at `0x0061e610` |
| `0x00503580` | code xref from `0x004f80c2` |
| `0x00503650` | data xref at `0x0061e680` |
| `0x005036a0` | data xref at `0x0061e68c` |
| `0x0061e5b4` | constructor/destructor/data refs from `0x00503258`, `0x005032fb`, `0x00503872` |
| `0x0061e600` | constructor/destructor/data refs from `0x0050325e`, `0x00503301`, `0x00503878` |
| `0x0061e630` | constructor/destructor/data refs from `0x00503268`, `0x0050330b`, `0x00503882` |

No live IDA xref connects `0x00503060` to MapNamePane, MiniMapButtonPane, MainMenu, or any other modeled owner.

### Byte And Signature Evidence

IDA `get_bytes` for `0x00503050-0x0050312f` confirms:

- the prior modeled function tail ends before `0x00503060`;
- four `0xcc` bytes precede the target start at `0x00503060`;
- the target ends in `c2 04 00` at `0x005030b9`, followed by four `0xcc` alignment bytes through `0x005030bf`;
- the sibling helper starts at `0x005030c0`;
- the next sibling raw renderer starts at `0x00503110`.

IDA `find_bytes` found no absolute little-endian VA-style hits for:

- `60 30 50 00` (`0x00503060`)
- `70 30 50 00`
- `79 30 50 00`
- `98 30 50 00`
- `A0 30 50 00`
- `A8 30 50 00`
- `BC 30 50 00`
- `C0 30 50 00`
- `10 31 50 00`

It also found no RVA-style hit for `60 30 10 00`.

Positive control vtable entries were found in the same scan:

- `50 33 50 00` -> `0x0061e5f8`
- `A0 34 50 00` -> `0x0061e610`
- `50 36 50 00` -> `0x0061e680`
- `A0 36 50 00` -> `0x0061e68c`

IDA `make_signature` produced a unique wildcarded entry signature for `0x00503060`:

```text
55 8B EC 83 EC 14 A1 ? ? ? ? 33 C5 89 45 ? 83 6D ? ? 56 8B F1 75 ? 80 3D
```

IDA `make_signature_for_range` for `0x00503060-0x005030bc` produced unique exact and wildcarded range signatures in this IDB. This supports distinct source-authored body identity, but it does not prove source owner or emitter route.

## PE / Raw Executable Evidence

I performed a fresh local PE scan against:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
```

PE facts:

- Image base: `0x00400000`
- Executable section: `.text`, RVA `0x00001000`, virtual size `2143404`, raw size `2143744`

The scan searched the complete file for VA and RVA little-endian pointers to the target entry, useful interiors, sibling starts, and positive controls. It then scanned executable bytes for direct `E8/E9` rel32 calls/jumps, `0F 80-8F` near conditional branches, short conditional branches, short jumps, and loop-style short branches to the same addresses.

Raw pointer results:

- No VA/RVA hits for target addresses `0x00503060`, `0x00503070`, `0x00503079`, `0x00503098`, `0x005030a0`, `0x005030a8`, `0x005030bc`, `0x005030c0`, or `0x00503110`.
- Positive VA hits exist for nearby vtable-controlled functions:
  - `0x00503350` at raw offset `0x21cff8`
  - `0x005034a0` at raw offset `0x21d010`
  - `0x00503650` at raw offset `0x21d080`
  - `0x005036a0` at raw offset `0x21d08c`

Branch/call results:

| Target | PE branch/call hits |
| --- | --- |
| `0x00503060` | none |
| `0x00503070` | none |
| `0x00503079` | none |
| `0x00503098` | none |
| `0x005030a0` | internal short branch only from `0x00503077` |
| `0x005030a8` | none |
| `0x005030bc` | none |
| `0x005030c0` | none |
| `0x00503110` | none |
| `0x005031f0` | positive control `E8` calls from `0x004f8051` and `0x004f8695` |
| `0x00503580` | positive control `E8` call from `0x004f80c2` |

This closes the most important hidden-route checks available in this pass. The absence of IDA xrefs is not just an IDA function-boundary artifact; the executable also lacks raw VA/RVA pointer evidence and direct branch/call evidence into the target entry.

## Function And Child Inventory

Relevant local memory layout:

| UID / Address | Current disposition | Relevance |
| --- | --- | --- |
| `0x00502e30-0x0050305c` | modeled IDA function, documented near MainMenu/Login UI | left neighbor ends before target; no evidence it owns target |
| `0002BD` `0x00503060-0x005030bc` | reconstructable raw helper, no owner/emitter | current target |
| `0x005030bc-0x005030c0` | alignment bytes | separates target from sibling |
| `0002BE` `0x005030c0-0x00503104` | reconstructable raw rect write helper, no owner/emitter | similar sibling but no ownership proof |
| `0x00503104-0x00503110` | alignment bytes | separates siblings |
| `0002BF` `0x00503110-0x005031e1` | reconstructable raw wide glyph renderer, owner/emitter `00007P` | sibling with MapName-specific `this+0x220` evidence that target lacks |
| `00022Z` `0x00503060-0x005031e1` | non-reconstructable aggregate container | correct inventory parent, not a source owner/emitter |
| `0001AL` `0x005031f0-0x0050395f` | MapName/MiniMapButton pane aggregate | adjacent modeled UI range, but docs warn not to absorb raw helpers without direct evidence |

No new split is needed. `0002BD` is already an exact coherent helper body. No merge is needed because the neighboring children have distinct behavior and separate alignment.

## Ranked Ownership / Emitter Analysis

### 1. Keep `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS` - Accepted

This is the best defensible result.

Positive evidence for reconstructability:

- normal source-shaped helper body;
- project global `g_useEpfAssets` / `byte_66DA97`;
- project `RectBounds` initializer at `sub_4B7C50`;
- receiver virtual dispatch through vtable slot `+0x20`;
- unique current IDB signatures;
- coherent boundaries and alignment.

Negative evidence blocking ownership/emission:

- no IDA function object;
- no entry xrefs;
- no external xrefs to useful interiors or sibling starts;
- no VA/RVA pointer hits;
- no PE direct branch/call route to the entry;
- no nearby MapName/MiniMapButton vtable slot containing the helper;
- no MapName-private field access such as `this+0x220`;
- no source-file documentation proving this helper belongs to a modeled owner.

The target is source-authored but unrouted.

### 2. MapNamePane / `00007P` - Best Forced Candidate, Rejected

MapNamePane is the strongest hypothesis if forced:

- address proximity: target is immediately before MapName/MiniMapButton pane functions;
- theme: UI asset-mode rectangle constants;
- `0xad` matches nearby 173-pixel MapName sizing;
- sibling `0002BF` now has MapNamePane ownership.

The assignment still fails:

- no call, pointer, vtable slot, or branch route from MapNamePane to `0x00503060`;
- no MapName-private field access in the target;
- sibling `0002BF` has `this+0x220` font-resource lifecycle evidence that `0002BD` does not share;
- current MapNamePane docs specifically treat the raw preceding helper cluster as address-adjacent but unabsorbed until direct evidence appears.

Do not set `CANONICAL_OWNER:00007P` or `EMITTER_UIDS:00007P`.

### 3. MiniMapButtonPane / MiniMap UI - Rejected

MiniMapButtonPane is nearby and asset-themed, but current IDA and PE evidence do not connect it to this helper:

- no MiniMapButton vtable entry points to `0x00503060`;
- no constructor/paint/mouse/update function calls it;
- no singleton or class-private MiniMapButton field appears in the target;
- no `MMAPBUT.EPF` or MiniMap-specific state appears in the body.

No MiniMap/MiniMapButton emitter is justified.

### 4. MainMenu / Login UI - Rejected

The left neighbor belongs to the broader MainMenu/Login area, but it ends at `0x0050305c` before `0xcc` alignment. The target begins as a separate raw helper at `0x00503060`.

Blocking facts:

- no MainMenu caller or pointer route;
- no packet/login/account-dialog behavior in the target;
- no source evidence extending the MainMenu range across the alignment into this helper.

No MainMenu owner/emitter is justified.

### 5. RectBounds / Geometry Helpers - Rejected

`sub_4B7C50` constructs the local rectangle, but a callee dependency is not semantic ownership. `RectBounds` owns the geometry initializer, not every UI helper that calls it.

No `RectBounds` owner/emitter is justified.

### 6. `g_useEpfAssets` / StartupWindow - Rejected

The target reads `g_useEpfAssets`, but that global is a process-wide UI/resource-mode selector with many consumers. Ownership of the flag does not transfer to each consumer body.

No StartupWindow/global owner or emitter is justified.

### 7. New Source File Or Helper Group - Not Recommended

A future narrow source grouping for `0002BD` and `0002BE` could become plausible if a caller/table/source route is recovered. Current evidence is not strong enough to create one:

- the existing `00022Z` aggregate already documents the raw helper cluster as an inventory container;
- no file-level source path, name family, caller set, table, or vtable route is known;
- creating a standalone by-file owner would fabricate output placement.

If future evidence forces a new owner, the best candidate scope would be a narrow UI asset-mode rectangle helper group covering `0002BD` and `0002BE`, while excluding `0002BF` because `0002BF` has separate MapNamePane field-lifecycle evidence. That is a future hypothesis, not a current edit.

### 8. Reclassify As Non-Reconstructable / Padding - Rejected

The target is not padding, compiler-only residue, or an ignored support thunk:

- it has a coherent prologue/body/return;
- it tests a project global;
- it initializes project UI geometry;
- it performs a project virtual UI call;
- it has a unique signature.

Keep `RECONSTRUCTABLE:TRUE`.

## Exact Required Edits

No in-scope documentation repair is required.

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

Generated memory coverage should remain:

```text
| [UID:0002BD][0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper](by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md` |  |
```

No direct edit to `by-memory/-coverage-report.md` is recommended. The current row is acceptable. If the supervisor wants an explicit applied/shared-report row for this pass, use exactly:

```text
        - [UID:0002BD][0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper](by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) 0x00503060-0x005030bc | raw function | UiAssetModeRectVirtualDispatchHelper : reconstructable : 87% : strong : B003 current Goal 2 pass reconfirms source-shaped raw helper body but no owner/emitter route: live IDA session b001_0003gy reports no function object at 0x00503060 or useful interiors, zero entry/end/sibling-start xrefs, only internal branch refs inside the helper, unique wildcarded entry and range signatures, byte_66DA97/RectBounds(0,0,0xa6/0xad,0x10) setup through sub_4B7C50, unconditional vtable slot +0x20 dispatch, no VA/RVA pointer hits to the target or useful interiors, no PE-level E8/E9/0F8x/short-branch target to the entry, no MapName/MiniMapButton vtable slot, and no MapName-private this+0x220 field access. MapName width and sibling 0002BF association remain the best owner lead but are insufficient for canonical ownership or emitter routing.
```

## Validation

No by-memory, by-file, by-class, generated coverage, or shared coverage files were edited in this pass. The only created file is this research report in the Agent-B003 research folder, so the normal validator `--apply` path was not needed and was not run.

No dry runs were used.

## Lease State

No lease was required because no `by-*`, generated, or shared project documentation file was edited. `current_leases.md` reported no active leases before report creation.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/0002BD-UiAssetModeRectVirtualDispatchHelper-current-goal2-pass.md`

## Confidence

Recommendation confidence: high.

The behavior, boundary, and lack of direct reachability are well supported by live IDA MCP plus a fresh PE scan with nearby positive controls. Confidence remains capped because the original source placement and runtime reachability mechanism are unknown. The specific evidence that would change this recommendation is a recovered caller, callback table, vtable slot, link/source map, field-lifecycle tie, or source path proving that this helper belongs to a concrete owner/emitter.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002BD-UiAssetModeRectVirtualDispatchHelper-current-goal2-pass.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0002BD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
