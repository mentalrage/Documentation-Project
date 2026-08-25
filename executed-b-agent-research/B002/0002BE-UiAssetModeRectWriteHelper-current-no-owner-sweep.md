** TARGET-REPORT-UID:0002BE **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002BE] UiAssetModeRectWriteHelper Current No-Owner Sweep

## Finalized Recommendation

Keep [UID:0002BE] `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` as:

- `COMPLETION:87`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:TRUE`
- blank `EMITTER_UIDS`
- blank reconstruction C++

No canonical owner, emitter UID, split, merge, reclassification, IDA-safe rename, by-memory repair, or shared coverage-report edit is justified by the current evidence. The helper is reconstructable raw project code, but the current IDA and PE evidence still proves no caller, vtable/table slot, pointer literal, class-local field route, or source-use output route. The active 90/90+ code-entry gate is not met because the item remains `87/91` and lacks a defensible source owner/emitter route.

## Target And Scope

- Assigned target: `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md`
- UID: `0002BE`
- Current tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, active 2026-06-14 remaining no-owner sweep, assigned to Agent-B002.
- Current generated state in `auto-generated/-ag-memory-coverage.md`: no-owner, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`.
- Prior report reviewed first as background only: `tools/leaser/Agents/Agent-B001/research/executed/0002BE-UiAssetModeRectWriteHelper-current-goal2-pass.md`.
- This pass rechecked the target page, generated/shared rows, parent aggregate, sibling raw helpers, MapName/MiniMap docs, RectBounds/global dependency docs, proposed source placement, by-structure owner/emitter rules, and live IDA MCP evidence.

## Evidence Standards Applied

The current by-structure model requires `CANONICAL_OWNER` to identify the narrowest proven semantic source owner. `EMITTER_UIDS` is only for proven source output routes. Plausible semantic association, address adjacency, shared constants, or a callee dependency is not enough to assign ownership or emission. Reconstructable raw code may remain `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS` when source placement is not defensible.

For this item, code entry would require at least 90/90+ with source-quality context. The target is `87/91`, so the raw behavior can be documented but C++ emission stays blank.

## Current Header State

Current target header:

```text
*** UID:0002BE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Current generated no-owner row:

```text
| [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` |  |
```

Current generated non-emitting queue row:

```text
| [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) | no-owner | `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` |  |  |  |
```

## Live IDA MCP Facts

IDA MCP session used: `b001_0003gy`, binary `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x00400000`.

Function-object check:

```text
0x00503060 -> Not a function
0x005030c0 -> Not a function
0x00503110 -> Not a function
0x005031f0 -> sub_5031F0, size 0xd3
0x00503350 -> sub_503350, size 0x14f
0x005034a0 -> sub_5034A0, size 0xd4
0x004b7c50 -> sub_4B7C50, size 0x1f
```

Target instruction listing:

```text
0x5030c0 push ebp
0x5030c1 mov ebp, esp
0x5030c3 sub dword ptr [ebp+8], 1
0x5030c7 jnz short loc_503100
0x5030c9 cmp byte_66DA97, 1
0x5030d0 push 10h
0x5030d2 jnz short loc_5030EC
0x5030d4 push 0A6h
0x5030d9 push 0
0x5030db push 0
0x5030dd push dword ptr [ebp+0Ch]
0x5030e0 call sub_4B7C50
0x5030e5 add esp, 14h
0x5030e8 pop ebp
0x5030e9 retn 8
0x5030ec push 0ADh
0x5030f1 push 0
0x5030f3 push 0
0x5030f5 push dword ptr [ebp+0Ch]
0x5030f8 call sub_4B7C50
0x5030fd add esp, 14h
0x503100 pop ebp
0x503101 retn 8
```

Boundary evidence:

```text
0x5030b1 call @__security_check_cookie@4
0x5030b6 mov esp, ebp
0x5030b8 pop ebp
0x5030b9 retn 4
0x5030bc-0x5030bf cc cc cc cc
0x5030c0 push ebp
0x503104-0x50310f cc cc cc cc cc cc cc cc cc cc cc cc
```

Target bytes at `0x005030c0`, size `0x44`:

```text
55 8b ec 83 6d 08 01 75 37 80 3d 97 da 66 00 01
6a 10 75 18 68 a6 00 00 00 6a 00 6a 00 ff 75 0c
e8 6b 4b fb ff 83 c4 14 5d c2 08 00 68 ad 00 00
00 6a 00 6a 00 ff 75 0c e8 53 4b fb ff 83 c4 14
5d c2 08 00
```

Unique wildcarded range signature:

```text
55 8B EC 83 6D ? ? 75 ? 80 3D ? ? ? ? ? 6A 10 75 ? 68 A6 00 00 00 6A 00 6A 00 FF 75 ? E8 ? ? ? ? 83 C4 14 5D C2 08 00 68 AD 00 00 00 6A 00 6A 00 FF 75 ? E8 ? ? ? ? 83 C4 14 5D C2 08 00
```

IDA MCP reported `unique:true` for that signature.

Xref check:

```text
0x005030c0 -> 0 xrefs
0x005030ec -> 1 internal code xref from 0x5030d2
0x00503100 -> internal code flow/xrefs from 0x5030fd and 0x5030c7
0x005030fa -> 0 xrefs
0x00503104 -> 0 xrefs
0x00503060 sibling raw helper -> 0 xrefs
0x00503110 sibling raw helper -> 0 xrefs
```

Positive controls from the same IDA session still show normal source-route evidence when it exists:

```text
0x005031f0 -> code xrefs from 0x004f8051 and 0x004f8695
0x00503350 -> data xref from 0x0061e5f8
0x005034a0 -> data xref from 0x0061e610
0x00503580 -> code xref from 0x004f80c2
0x00503650 -> data xref from 0x0061e680
0x005036a0 -> data xref from 0x0061e68c
```

## PE And Raw Scan Evidence

Read-only scan of `NexusTK.exe`:

```text
ImageBase: 0x00400000
Target raw offset: 0x1024c0
Exact entry pattern hits: 1, at raw 0x1024c0
Target absolute VA literal hits for c0 30 50 00: 0
Target RVA literal hits for c0 30 10 00: 0
Target push-VA immediate hits for 68 c0 30 50 00: 0
```

The byte-level branch scan produced one apparent external short-branch hit from `0x005030b2` to `0x005030fa`. This is rejected as a non-instruction false positive: live IDA disassembly shows `0x005030b2` is inside the five-byte instruction at `0x005030b1`:

```text
0x005030b1: e8 79 46 0c 00  -> call @__security_check_cookie@4
```

IDA also reports no xrefs to `0x005030fa`. After instruction-boundary verification, there is no external direct branch/call route into the helper range.

Nearby MapName/MiniMap vtable range scan `0x0061e5b4-0x0061e6c0`:

```text
0x0061e5f8 -> 0x00503350 MapNamePane render
0x0061e610 -> 0x005034a0 MapNamePane update
0x0061e680 -> 0x00503650 MiniMapButton render
0x0061e68c -> 0x005036a0 MiniMapButton update
```

No slot in that vtable/table window points at `0x005030c0`, `0x00503060`, or `0x00503110`.

## Behavior Summary

The helper takes two stack arguments and returns with `retn 8`. It decrements the first argument in place. If the adjusted value is nonzero, it returns without writing the output rectangle. If the adjusted value is zero, it reads `byte_66DA97` / `g_useEpfAssets` and initializes the output `RectBounds` via `sub_4B7C50`:

```text
EPF mode:    RectBounds(out, 0, 0, 0xa6, 0x10)  -> 166 x 16
legacy mode: RectBounds(out, 0, 0, 0xad, 0x10)  -> 173 x 16
```

This is enough to keep the item reconstructable as raw project code, but not enough to assign a source owner or emitter.

## Function And Child Inventory

Parent aggregate:

- [UID:00022Z] `by-memory/0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md`
- Current role: non-emitting split inventory for three raw IDA-missed helpers.
- It is not a source owner and does not provide a source output route.

Children in the aggregate:

- [UID:0002BD] `0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md`: raw helper, no-owner/non-emitting, no direct refs.
- [UID:0002BE] `0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md`: current target, raw helper, no-owner/non-emitting.
- [UID:0002BF] `0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md`: now has MapNamePane ownership/emission based on its own target-specific `MapNamePane` field/resource evidence.

The `0002BF` MapNamePane ownership does not transfer to `0002BE`. This target has no `this` receiver, no class-field access, no caller, and no vtable/table slot.

## Candidate Ownership Analysis

MapNamePane / `MapNamePane.cpp` is the strongest rejected candidate. The legacy width `0xad` equals 173, which resembles MapName-related UI width evidence, and the target is address-adjacent to MapName/MiniMap code. That is still not source-quality ownership evidence. Current IDA and PE checks find no call to `0x005030c0`, no vtable slot, no table pointer, no `this+field` access, no MapNamePane constructor/destructor route, and no reference from the accepted MapNamePane methods. The assignment would be based on semantic plausibility only.

MiniMapButtonPane / `MiniMap.cpp` is rejected. The known MiniMapButton constructors and vtable slots are visible in IDA and PE controls, but none points to the helper. The helper does not reference MiniMapButton fields or methods.

StartupWindow / `g_useEpfAssets` is rejected. The helper reads the global EPF mode byte, but the writer/owner of a shared global is not the owner or emitter of every reader.

RectBounds / geometry helpers is rejected. `sub_4B7C50` is the callee used to initialize the output rectangle. A callee dependency is not a source route for this raw helper.

MainMenu/login aggregate is rejected. It is an address-near container context only and provides no direct source-owner evidence for this helper.

A new source helper file is rejected for this pass. The function may have originated as a small static helper, but no current evidence proves a source filename or output file. Creating a canonical owner from absence of evidence would violate the current owner/emitter model.

## Alternatives Rejected

- Gain canonical owner: rejected because no direct owner evidence exists.
- Add `EMITTER_UIDS`: rejected because no source output route is proven.
- Split: rejected because the current range is a single compact helper with clear padding before and after.
- Merge into parent aggregate: rejected because `00022Z` is an inventory aggregate, not a source unit.
- Merge into MapName/MiniMap memory docs: rejected because adjacent accepted MapName/MiniMap functions have explicit calls/vtable refs while this helper does not.
- Reclassify as data or harmless padding: rejected because the bytes are valid executable helper logic with two `retn 8` exits.
- IDA-safe name repair: not needed for the documentation decision. IDA still has no function object at `0x005030c0`; creating one may be useful for future analysis, but it would not establish ownership/emission.

## Exact Supervisor-Owned Shared-Report Text

Required edit to `by-memory/-coverage-report.md`: none.

Retain the current row exactly:

```text
        - [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) 0x005030c0-0x00503104 | raw function | UiAssetModeRectWriteHelper : reconstructable : 87% : strong : A001 Batch310 and B001 second-pass confirm no function object/xrefs/raw pointer hits/section-aware PE-level references/nearby table evidence, exact bytes, unique exact-range and wildcarded-entry signatures, two retn 8 exits at 0x005030e9 and 0x00503101, optional EPF/legacy RectBounds(0,0,0xa6/0xad,0x10) writes through sub_4B7C50 with int_convert-verified extents 166/173/16, output-preserving non-1 state, MapName-width association without direct ownership, and `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS` because no caller/table/source-use emitter route is proven.
```

Required edit to `auto-generated/-ag-memory-coverage.md`: none. This is generated output and currently matches the recommendation.

Retain the generated owner/emitter row:

```text
| [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` |  |
```

Retain the generated non-emitting queue row:

```text
| [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) | no-owner | `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` |  |  |  |
```

## Validation And Edits

Changed files:

- `tools/leaser/Agents/Agent-B002/research/0002BE-UiAssetModeRectWriteHelper-current-no-owner-sweep.md`

No by-memory, by-file, by-class, by-global, generated coverage, or shared coverage files were edited. Normal documentation validator `--apply` was not run because no in-scope by-* documentation file changed.

Lease state:

- The leaser rejected a pre-lease for the new report file because it did not exist yet.
- The leaser also rejected leasing the research directory because it only leases files.
- A placeholder report was created, then `Agent-B002` successfully acquired the lease for the report file before substantive edits.
- That first lease expired before the release command was issued during the long evidence/report pass.
- The existing report file was re-leased for this final lease-state update and will be released immediately after this update. Final chat status should show no active `Agent-B002` lease.

## Confidence

Recommendation confidence: high for no-owner/non-emitting status.

The raw behavior is well documented and the target remains reconstructable at `87/91`. The remaining uncertainty is original source placement, not behavior. Current evidence supports no canonical owner and no emitter UID because every plausible owner route fails the required caller/table/vtable/field/source-use evidence test.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002BE-UiAssetModeRectWriteHelper-current-no-owner-sweep.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002BE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
