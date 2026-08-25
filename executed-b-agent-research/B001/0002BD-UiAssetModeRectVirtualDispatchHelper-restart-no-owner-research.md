** TARGET-REPORT-UID:0002BD **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BD UiAssetModeRectVirtualDispatchHelper - restart no-owner research

## Final Recommendation

Keep `UID:0002BD` as `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS`.

No canonical owner, emitter route, split, merge, reclassification, IDA-safe name repair, or C++ reconstruction entry is currently justified. The helper is source-shaped project code and remains `RECONSTRUCTABLE:TRUE`, but it has no proven source output route. Under the active code-entry gate, `(87 + 91) / 2 = 89`, but the required nonblank confirmed emitter route is absent, so `RECONSTRUCTION_CPP` must remain blank.

No by-memory page edit is required. No `by-memory/-coverage-report.md` replacement is required; the current shared-report row remains directionally correct. Do not edit `by-memory/-coverage-report.md` directly for this item.

## Target and Scope

- Target: `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md`
- UID: `0002BD`
- Current state checked:
  - `COMPLETION:87`
  - `CONFIDENCE:91`
  - `CANONICAL_OWNER:NONE`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:` blank
  - `RECONSTRUCTION_CPP:` blank
- Current generated no-owner row in `auto-generated/-ag-memory-coverage.md`:

```text
| [UID:0002BD][0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper](by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md` |  |
```

Prior report reviewed as background only:

- `tools/leaser/Agents/Agent-B003/research/executed/0002BD-UiAssetModeRectVirtualDispatchHelper-current-no-owner-sweep.md`

## Evidence Standard Used

I treated existing documentation and prior B-agent reports as leads, not authority. The accepted owner/emitter state requires direct source-route evidence such as a caller, vtable slot, source file/class-private field access, table reference, relocation-like pointer, or other defensible data-flow link. Address adjacency, shared constants, and broad helper/global dependencies are not enough to assign a canonical owner or emitter.

## Live IDA MCP Evidence

Live IDA MCP session used:

- Database/session: `b001_0002bd`
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Module image base: `0x00400000`
- Auto-analysis and Hex-Rays were ready.

Function lookup facts:

- `0x00503060`, `0x00503070`, `0x00503079`, `0x00503098`, `0x005030a0`, `0x005030a8`, `0x005030bc`, `0x005030c0`, `0x00503104`, `0x00503110`, and `0x005031e1` are not IDA function entries.
- Positive controls resolve normally:
  - `0x005031f0` is `sub_5031F0`, size `0xd3`.
  - `0x00503350` is `sub_503350`, size `0x14f`.
  - `0x005034a0` is `sub_5034A0`, size `0xd4`.
  - `0x00503580` is `sub_503580`, size `0x9e`.
  - `0x00503650` is `sub_503650`, size `0x42`.
  - `0x005036a0` is `sub_5036A0`, size `0x14d`.
  - `0x00503840` is `sub_503840`, size `0xbe`.
  - `0x00503900` is `sub_503900`, size `0x5f`.
  - `0x004b7c50` is `sub_4B7C50`, size `0x1f`.

IDA xrefs:

- No xrefs to the target entry `0x00503060`.
- No xrefs to the target end `0x005030bc`.
- Interior xrefs are only internal control flow:
  - `0x00503070` from `0x0050306d`
  - `0x00503079` from `0x00503077`
  - `0x00503098` from `0x00503097`
  - `0x005030a0` from `0x00503077` and `0x0050309d`
  - `0x005030a8` from `0x005030a6`
- No xrefs to sibling starts `0x005030c0`, `0x00503104`, `0x00503110`, or `0x005031e1`.
- Positive controls prove the same IDA session finds real routes nearby:
  - `0x005031f0` has code xrefs from `0x004f8051` and `0x004f8695`.
  - `0x00503350` has data xref `0x0061e5f8`.
  - `0x005034a0` has data xref `0x0061e610`.
  - `0x00503580` has code xref `0x004f80c2`.
  - `0x00503650` has data xref `0x0061e680`.
  - `0x005036a0` has data xref `0x0061e68c`.
  - `0x00503840` has data xref `0x0061e5b4`.
  - `0x00503900` has data xref `0x0061e63c`.

Raw disassembly at `0x00503060`:

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

Body interpretation:

- This is source-shaped x86 code, not padding or compiler-only data.
- The method expects `this` in `ecx` and one stack argument at `[ebp+8]`.
- It decrements the argument and initializes a local rect only when the adjusted argument is zero.
- The rect bounds are `(0, 0, 0xa6 or 0xad, 0x10)`, with the right edge selected by `byte_66DA97` / `g_useEpfAssets`.
- It then dispatches through `this->vtable[0x20]` with the local rect pointer.
- The non-zero adjusted-argument path still dispatches through the same virtual slot but skips local rect initialization; the upstream caller contract is not identified.

IDA byte and signature evidence:

- The target is bounded by alignment bytes:
  - Four `0xcc` bytes before `0x00503060`.
  - Four `0xcc` bytes from `0x005030bc` to `0x005030c0`.
  - Sibling `0002BE` begins at `0x005030c0`.
- `make_signature` produced unique wildcarded entry/interior signatures for `0x00503060`, `0x00503079`, and `0x005030a0`.
- `make_signature_for_range 0x00503060-0x005030bc` produced a unique range signature.
- `find_bytes` for little-endian VA pointers to the target entry, useful interiors, target end, and nearby sibling starts returned zero matches.
- Positive-control `find_bytes` queries found expected vtable pointers:
  - `0x00503350` at `0x0061e5f8`
  - `0x005034a0` at `0x0061e610`
  - `0x00503650` at `0x0061e680`
  - `0x005036a0` at `0x0061e68c`
  - `0x00503840` at `0x0061e5b4`
  - `0x00503900` at `0x0061e63c`

Vtable evidence checked:

- `entity_query` over `0x0061e5a0-0x0061e710` shows the known `MapNamePane` and `MiniMapButtonPane` vtable/resource area:
  - `0x0061e5b4 ??_7MapNamePane@@6B@`
  - `0x0061e600 ??_7MapNamePane@@6B@_0`
  - `0x0061e630 ??_7MapNamePane@@6B@_1`
  - `0x0061e63c ??_7MiniMapButtonPane@@6B@`
  - `0x0061e688 ??_7MiniMapButtonPane@@6B@_0`
  - `0x0061e6b8 ??_7MiniMapButtonPane@@6B@_1`
- Raw bytes in that vtable/resource range contain nearby known methods, including `0x00503840`, `0x00503350`, `0x005034a0`, `0x00503900`, `0x00503650`, and `0x005036a0`.
- The vtable/resource range does not contain `0x00503060`.

## PE / Raw File Evidence

PE file scanned:

- `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`

Pointer scan results:

- No VA or RVA pointer hits for:
  - `0x00503060`
  - `0x00503070`
  - `0x00503079`
  - `0x00503098`
  - `0x005030a0`
  - `0x005030a8`
  - `0x005030bc`
  - `0x005030c0`
  - `0x00503104`
  - `0x00503110`
  - `0x005031e1`
- Positive controls found expected VA hits:
  - `0x00503350` at raw `0x0021cff8`
  - `0x005034a0` at raw `0x0021d010`
  - `0x00503650` at raw `0x0021d080`
  - `0x005036a0` at raw `0x0021d08c`
  - `0x00503840` at raw `0x0021cfb4`
  - `0x00503900` at raw `0x0021d03c`

Clean branch-target scan over `.text`:

- No `E8`, `E9`, `0F8x`, short conditional, or short unconditional branch targets to `0x00503060`.
- No external branch targets to useful target interiors.
- Only target-interior branch hit was internal: `0x00503077 -> 0x005030a0`.
- Positive controls found nearby thunk branches:
  - `0x00503811 -> 0x00503840`
  - `0x0050381c -> 0x00503840`
  - `0x00503827 -> 0x00503900`
  - `0x00503832 -> 0x00503900`

## Function / Child Inventory

The local range is already split at source-shaped boundaries:

- Left real function: `0x00502e30-0x0050305c`
- Alignment: `0x0050305c-0x00503060`
- Current target: `0x00503060-0x005030bc` (`0002BD`)
- Alignment: `0x005030bc-0x005030c0`
- Sibling helper: `0x005030c0-0x00503104` (`0002BE`)
- Alignment: `0x00503104-0x00503110`
- Sibling renderer: `0x00503110-0x005031e1` (`0002BF`)
- Alignment: `0x005031e1-0x005031f0`
- Following MapName/MiniMap island: starts at `0x005031f0` (`0001AL`)

The current item is a single helper body. It is not a mixed container and does not require child splitting. The surrounding alignment confirms the start/end choice.

## Documentation Evidence Checked

Checked current project documentation for target and likely related owners:

- `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md`
- `by-memory/0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md`
- `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md`
- `by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md`
- `by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md`
- `by-class/MapNamePane.md`
- `by-file/MapNamePane.md`
- `by-class/MiniMapButtonPane.md`
- `by-file/MiniMap.md`
- `by-global/g_useEpfAssets.md`
- `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`
- `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md`
- `auto-generated/-ag-memory-coverage.md`
- `by-memory/-coverage-report.md`
- `tools/leaser/Agents/no_owner_b-agent-tracker.md`

Documentation search for `0002BD`, `UiAssetModeRectVirtualDispatchHelper`, `0x00503060`, and `503060` outside by-memory/research context did not reveal a current file/class/global/type owner route.

## Owner / Emitter Analysis

### Accepted: no canonical owner, no emitter

The helper is reconstructable source-shaped code, but no source route is currently proven. It has no IDA function object, no direct entry xref, no external branch target, no pointer hit, no vtable slot, and no private class-field access tying the `this` object to a known class. That is enough to keep it reconstructable but not enough to assign owner or emitter.

### Rejected: `MapNamePane` / `MapNamePane.md` owner-emitter route

`MapNamePane` remains the strongest lead, but not a proven owner.

Evidence in favor:

- The helper is address-adjacent to the MapName/MiniMap memory island.
- The helper uses `g_useEpfAssets` and chooses width `0xa6` or `0xad`; `0xad` / `173` is also documented in the MapName update/render path.
- Sibling `0002BF` is assigned to `MapNamePane`.

Evidence against:

- No caller from MapName constructor, render, update, or thunks reaches `0x00503060`.
- No MapName vtable slot points at `0x00503060`.
- The helper does not access the MapName-private `this+0x220` font resource that justified assigning sibling `0002BF` to `MapNamePane`.
- Positive-control vtable and xref queries do resolve the known MapName methods, so the lack of route to `0x00503060` is meaningful.
- Width similarity and adjacency are not sufficient under by-structure rules.

### Rejected: `MiniMapButtonPane` / `MiniMap.md` owner-emitter route

The MiniMap/MiniMapButton documents occupy the same local island, but the target has no MiniMap constructor call, vtable slot, private-field access, or table/pointer route. The nearby known MiniMap methods are discoverable through xrefs and vtable pointers; this helper is not.

### Rejected: `MainMenuLoginAndAccountDialogs` / initialization owner route

The broader UI/login initialization region is an address-context lead only. There is no call, jump, pointer, vtable, or class-state evidence from `00019I` into this helper. Assigning a broad aggregate owner would be weaker than the current no-owner state.

### Rejected: `g_useEpfAssets` / `StartupWindow` owner route

The helper reads `byte_66DA97` / `g_useEpfAssets`, but that global is a broad asset-mode selector with many consumers. A read of that global explains one branch condition; it does not make `StartupWindow` or the global itself the semantic owner or source emitter for this helper.

### Rejected: `RectGeometryHelpers` owner route

The call to `sub_4B7C50` initializes a rect. The rect helper is a shared fan-in utility, not a source owner for every caller. It should remain a dependency only.

### Rejected: parent aggregate `00022Z` as canonical owner/emitter

`00022Z` is a non-reconstructable split inventory for unreferenced UI resource/text helpers. It is not a source-level file/class owner and should not be used as a canonical owner or emitter for `0002BD`.

### Rejected: split, merge, or reclassification

The target is a single bounded helper body with a unique signature and clear alignment before and after. It is not a mixed range, not only padding/data, and not compiler/runtime support. It should stay split as its own reconstructable raw helper page. It should not be merged into MapName/MiniMap or into sibling helpers without caller/table evidence proving a common source unit.

## Exact Required Edits

No in-scope by-memory documentation edits are required.

No `by-memory/-coverage-report.md` edit is required. Current generated/shared report state can remain:

- `CANONICAL_OWNER:NONE`
- blank `EMITTER_UIDS`
- `RECONSTRUCTABLE:TRUE`
- no C++ reconstruction entry

If the supervisor chooses to refresh prose provenance later, that is editorial only; this pass does not require a row replacement.

## Validation

Commands/evidence checks performed:

- Read B001 `goal.md` and current by-structure/research guidance.
- Reviewed current target, parent, sibling, candidate owner, generated coverage, shared coverage, tracker, and prior B003 report.
- Used live IDA MCP session `b001_0002bd` for function lookup, xrefs, bytes, signatures, entity query, disassembly, and pointer-byte searches.
- Ran raw PE pointer scan against `NexusTK.exe`; no pointer hits to target entry/interiors/end, with expected positive-control hits nearby.
- Ran clean `.text` branch-target scan against `NexusTK.exe`; no external branch hits to target entry/interiors/end, with expected positive-control branch hits nearby.

No repository validator was run because this assignment changed only this B001 research report and made no by-memory/by-structure documentation edits.

## Changed Files

- `tools/leaser/Agents/Agent-B001/research/0002BD-UiAssetModeRectVirtualDispatchHelper-restart-no-owner-research.md`

## Lease State

No by-* files were edited, so no by-* leases were acquired. No shared coverage file was edited.

## Confidence

- Completion after this pass: keep `87`
- Confidence after this pass: keep `91`

The code shape is well understood, and negative source-route evidence is strong because both IDA and raw PE checks find nearby positive controls but no external route to this helper. The remaining uncertainty is semantic: a future recovered call table or manually reconstructed caller could still tie this helper to a class or file. Current evidence does not meet the threshold to assign that owner/emitter now.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002BD-UiAssetModeRectVirtualDispatchHelper-restart-no-owner-research.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002BD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
