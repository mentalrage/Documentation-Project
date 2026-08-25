** TARGET-REPORT-UID:0002BE **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BE - UiAssetModeRectWriteHelper Current Goal 2 Pass

## Final Recommendation

Keep [UID:0002BE] `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` as a reconstructable no-owner, non-emitting raw helper:

- `CANONICAL_OWNER:NONE`
- `EMITTER_UIDS:` blank
- `RECONSTRUCTABLE:TRUE`
- Keep current `COMPLETION:87` and `CONFIDENCE:91`
- Keep `C++:` blank under the active 90/90+ code-entry gate

No canonical owner is proven. No source-output emitter route is proven. No split, merge, reclassification, or IDA-safe rename/repair is warranted for this Goal 2 pass.

No edit is needed to `by-memory/-coverage-report.md`. The current shared row already states the defensible conclusion.

## Target and Scope

Assigned target:

- Target page: `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md`
- UID: `0002BE`
- Address range: `0x005030c0-0x00503104`
- Parent aggregate: `by-memory/0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md` / UID `00022Z`
- Current generated state: `auto-generated/-ag-memory-coverage.md` lists this item as `no-owner`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`

Documents reviewed as current documentation leads:

- `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md`
- `by-memory/0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md`
- `by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md`
- `by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md`
- `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`
- `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md`
- `by-class/MapNamePane.md`
- `by-file/MapNamePane.md`
- `by-class/MiniMapButtonPane.md`
- `by-file/MiniMap.md`
- `by-global/g_useEpfAssets.md`
- `auto-generated/-ag-memory-coverage.md`
- `by-memory/-coverage-report.md`
- Prior reports used only as background: B001 second-pass and B002 post-migration/current-pass reports for `0002BE`

## Evidence Standard Applied

This pass used the current B-agent owner/emitter rules from `goal.md` and `by-structure.md`:

- A canonical owner requires direct semantic ownership, not address adjacency or subsystem resemblance.
- `EMITTER_UIDS` require proven source-use output routes. A global read, callee dependency, sibling relation, or adjacent vtable is not enough.
- `CANONICAL_OWNER:NONE` with blank emitters is valid for real project code when owner and output route remain unproven.
- Reconstruction C++ stays blank unless the relevant item reaches at least 90/90 with defensible source-quality evidence.

## IDA MCP Facts

Live IDA MCP was used against session `b001_0003gy`:

- Input binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Module image base: `0x00400000`
- Auto-analysis: ready
- Hex-Rays: ready

Function lookup around the raw helper confirms IDA has no function object for the assigned range:

| Address | IDA result |
|---|---|
| `0x00503060` | not a function |
| `0x005030bc` | not a function |
| `0x005030c0` | not a function |
| `0x00503104` | not a function |
| `0x00503110` | not a function |
| `0x005031f0` | `sub_5031F0`, size `0xd3` |
| `0x005032d0` | `sub_5032D0`, size `0x7d` |
| `0x00503350` | `sub_503350`, size `0x14f` |
| `0x005034a0` | `sub_5034A0`, size `0xd4` |
| `0x00503580` | `sub_503580`, size `0x9e` |
| `0x004b7c50` | `sub_4B7C50`, size `0x1f` |

`xrefs_to` results:

- `0x00503060`: zero xrefs
- `0x005030c0`: zero xrefs
- `0x00503110`: zero xrefs

Positive controls in the same neighborhood did resolve normally:

- `0x005031f0`: code xrefs at `0x004f8051` and `0x004f8695`
- `0x00503350`: data xref at `0x0061e5f8`
- `0x005034a0`: data xref at `0x0061e610`
- `0x00503580`: code xref at `0x004f80c2`
- `0x00503650`: data xref at `0x0061e680`
- `0x005036a0`: data xref at `0x0061e68c`

This distinguishes `0002BE` from the modeled MapName/MiniMapButton methods that do have constructor-call or vtable evidence.

## Raw Disassembly and Behavior

IDA `insn_query` for `0x005030c0-0x00503104` produced one compact stdcall-style helper:

```asm
0x005030c0  push ebp
0x005030c1  mov ebp, esp
0x005030c3  sub dword ptr [ebp+8], 1
0x005030c7  jnz short loc_503100
0x005030c9  cmp byte_66DA97, 1
0x005030d0  push 10h
0x005030d2  jnz short loc_5030EC
0x005030d4  push 0A6h
0x005030d9  push 0
0x005030db  push 0
0x005030dd  push dword ptr [ebp+0Ch]
0x005030e0  call sub_4B7C50
0x005030e5  add esp, 14h
0x005030e8  pop ebp
0x005030e9  retn 8
0x005030ec  push 0ADh
0x005030f1  push 0
0x005030f3  push 0
0x005030f5  push dword ptr [ebp+0Ch]
0x005030f8  call sub_4B7C50
0x005030fd  add esp, 14h
0x00503100  pop ebp
0x00503101  retn 8
```

The helper decrements its first argument. If the adjusted value is nonzero, it returns without writing the output rectangle. If the adjusted value is zero, it calls `sub_4B7C50` to initialize the second argument as a `RectBounds`-style rectangle:

- EPF mode (`byte_66DA97 == 1`): `(0, 0, 0xa6, 0x10)`
- Legacy/non-EPF mode: `(0, 0, 0xad, 0x10)`

IDA `int_convert` confirmed:

- `0xa6` = decimal `166`
- `0xad` = decimal `173`
- `0x10` = decimal `16`
- range size `0x44` = decimal `68`

Raw bytes for the full assigned range are:

```text
55 8b ec 83 6d 08 01 75 37 80 3d 97 da 66 00 01
6a 10 75 18 68 a6 00 00 00 6a 00 6a 00 ff 75 0c
e8 6b 4b fb ff 83 c4 14 5d c2 08 00 68 ad 00 00
00 6a 00 6a 00 ff 75 0c e8 53 4b fb ff 83 c4 14
5d c2 08 00
```

Padding evidence:

- `0x005030bc-0x005030bf`: `cc cc cc cc`
- `0x00503104-0x0050310f`: `cc` padding

The exact helper body is therefore isolated and does not require a child split.

## Signature and Raw PE Evidence

IDA `make_signature_for_range` for `0x005030c0-0x00503104` returned a unique masked signature:

```text
55 8B EC 83 6D ? ? 75 ? 80 3D ? ? ? ? ? 6A 10 75 ? 68 A6 00 00 00 6A 00 6A 00 FF 75 ? E8 ? ? ? ? 83 C4 14 5D C2 08 00 68 AD 00 00 00 6A 00 6A 00 FF 75 ? E8 ? ? ? ? 83 C4 14 5D C2 08 00
```

IDA `find_bytes` found the exact entry pattern only at `0x005030c0`. It found no pointer or push patterns for this target:

- `C0 30 50 00` absolute VA for `0x005030c0`: zero hits
- `C0 30 10 00` RVA for `0x005030c0`: zero hits
- `68 C0 30 50 00` push-immediate target VA: zero hits

A read-only PE scan of `NexusTK.exe` covered `.text`, `.rdata`, `.data`, and `.rsrc` and checked absolute VA, RVA, relative call/jump, near branch, and short branch encodings. It found no reference form to `0x00503060`, `0x005030c0`, or `0x00503110`.

The same scan found positive controls:

| Target | Evidence found |
|---|---|
| `0x005031f0` | relative refs at `0x004f8051`, `0x004f8695` |
| `0x00503350` | absolute slot at `0x0061e5f8` |
| `0x005034a0` | absolute slot at `0x0061e610` |
| `0x00503580` | relative ref at `0x004f80c2` |
| `0x00503650` | absolute slot at `0x0061e680` |
| `0x005036a0` | absolute slot at `0x0061e68c` |
| `0x00503840` | absolute slot at `0x0061e5b4`, relative refs at `0x00503811` and `0x0050381c` |
| `0x00503900` | absolute slot at `0x0061e63c`, relative refs at `0x00503827` and `0x00503832` |

This supports the current conclusion that missing xrefs for `0002BE` are not a tooling-wide failure. Nearby direct references are found when they exist.

## Function and Child Inventory

The parent raw aggregate `00022Z` remains a non-emitting split inventory rather than an owner:

| UID | Range | Name | Current state |
|---|---:|---|---|
| `0002BD` | `0x00503060-0x005030bc` | `UiAssetModeRectVirtualDispatchHelper` | raw no-owner/non-emitting child |
| `0002BE` | `0x005030c0-0x00503104` | `UiAssetModeRectWriteHelper` | assigned target, raw no-owner/non-emitting child |
| `0002BF` | `0x00503110-0x005031e1` | `WideGlyphResourceTextRendererRaw` | separate raw child with stronger MapName field evidence |

Modeled functions start after the raw helper cluster:

- `0x005031f0`: MapNamePane constructor path
- `0x005032d0`: MapNamePane destructor/cleanup path
- `0x00503350`: MapNamePane render slot
- `0x005034a0`: MapNamePane update slot
- `0x00503580` and later: MiniMapButton-related methods

`search_text` in the same area found MapName-specific `220h` field evidence in `0002BF` and modeled MapName methods:

- `0x00503196`: `0002BF` reads `[edi+220h]`
- `0x005032a9`: `sub_5031F0` writes `[esi+220h]`
- `0x005032f5`: `sub_5032D0` reads `[esi+220h]`
- `0x00503326`: `sub_5032D0` writes `[esi+220h]`

No comparable `this` pointer, field offset, vtable slot, constructor reference, or table reference exists inside `0002BE`.

## Owner and Emitter Analysis

### Canonical owner

No canonical owner should be assigned.

The best positive association is MapNamePane because the helper writes a 173-pixel legacy width, and MapNamePane documentation also discusses map-name width handling. The association is not strong enough for direct ownership:

- No xref to `0x005030c0`
- No raw PE pointer or branch reference to `0x005030c0`
- No vtable slot pointing to `0x005030c0`
- No caller table recovered
- No `this+0x220` or other MapName-specific field evidence in the target body
- No proof that the first argument state value belongs to a MapName source route

`0002BF` has MapName field evidence, but that evidence is sibling-specific. It does not transfer across padding to `0002BE`.

### Emitters

`EMITTER_UIDS` should remain blank.

The helper reads `g_useEpfAssets` and calls the `RectBounds` initializer at `0x004b7c50`, but those are dependencies rather than source-output routes. No file/class/global doc proves that a specific source emitter invokes this helper or emits this exact rectangle callback. With no caller, table entry, or source-use route, assigning `MapNamePane.cpp`, `MiniMap.cpp`, `StartupWindow.cpp`, or `RectBounds.cpp` as an emitter would overstate the evidence.

### Reconstructability

`RECONSTRUCTABLE:TRUE` remains appropriate because the bytes form a coherent, source-shaped helper with exact behavior, isolated padding, and a unique signature. It remains non-emitting because the use route is not recovered.

## Alternatives Rejected

| Alternative | Reason rejected |
|---|---|
| Assign `MapNamePane` / `MapNamePane.cpp` as canonical owner | Best hypothesis, but lacks direct xref, vtable, caller, table, or field evidence for this specific helper. Width similarity and address adjacency are insufficient. |
| Assign `MiniMapButtonPane` / `MiniMap.cpp` | Nearby modeled MiniMapButton functions have their own constructor/vtable evidence, but none points to `0x005030c0`. |
| Assign `StartupWindow` / `g_useEpfAssets` owner or emitter | `g_useEpfAssets` is a process-wide EPF mode flag with many readers. Reading it does not make StartupWindow the owner or emitter of each consumer helper. |
| Assign `RectBounds` / `RectGeometryHelpers` owner or emitter | `sub_4B7C50` is a callee dependency that initializes the output rectangle. The callee does not own the caller. |
| Assign `MainMenuLoginAndAccountDialogs` | The preceding modeled range is address-adjacent, but no caller or table evidence links it to this helper. |
| Merge with `0002BD` or `0002BF` | Padding and behavior separate the children. `0002BF` has different text-renderer behavior and MapName field evidence not present here. |
| Split `0002BE` further | The assigned range is one isolated 68-byte helper with two return paths and padding after `0x00503104`. |
| Reclassify as padding/runtime artifact | The body is executable, source-shaped logic with a global read, call, stack cleanup, and deterministic rectangle writes. |
| Enter C++ reconstruction | Current score is `87/91`, below the active 90/90+ gate, and source-use routing is not proven. |
| IDA-safe name repair | IDA has no function object at the raw start. Creating or naming a function may aid local analysis, but this ownership pass has no evidence that such a repair would change owner/emitter conclusions. |

## Exact Required Edits

### Target page

No edit required.

The current target page already supports:

- `CANONICAL_OWNER:NONE`
- blank `EMITTER_UIDS`
- `RECONSTRUCTABLE:TRUE`
- blank `C++`
- no split/merge/reclassification

### Shared memory coverage report

No edit required to `by-memory/-coverage-report.md`; do not directly edit it for this pass.

The existing supervisor-owned row is still correct and can remain exactly:

```markdown
        - [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) 0x005030c0-0x00503104 | raw function | UiAssetModeRectWriteHelper : reconstructable : 87% : strong : A001 Batch310 and B001 second-pass confirm no function object/xrefs/raw pointer hits/section-aware PE-level references/nearby table evidence, exact bytes, unique exact-range and wildcarded-entry signatures, two retn 8 exits at 0x005030e9 and 0x00503101, optional EPF/legacy RectBounds(0,0,0xa6/0xad,0x10) writes through sub_4B7C50 with int_convert-verified extents 166/173/16, output-preserving non-1 state, MapName-width association without direct ownership, and `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS` because no caller/table/source-use emitter route is proven.
```

### Generated coverage rows

No direct generated-file edit requested. The current generated state is correct:

```markdown
| [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` |  |
```

Non-emitting queue row remains correct:

```markdown
| [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) | no-owner | `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` |  |  |  |
```

## Validation

No by-memory, by-file, by-class, by-global, or shared coverage documentation file was edited in this pass. Therefore the normal documentation validator was not run.

Validation/evidence commands actually used:

- IDA MCP `server_health`, `lookup_funcs`, `xrefs_to`, `insn_query`, `get_bytes`, `make_signature_for_range`, `search_text`, `find_bytes`, `int_convert`, and `entity_query`
- Read-only PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Current docs and generated reports read from disk

No dry runs were used.

## Changed Files

Changed by this pass:

- `tools/leaser/Agents/Agent-B001/research/0002BE-UiAssetModeRectWriteHelper-current-goal2-pass.md`

No target page or shared coverage file was changed by this pass. At report time, `git status` already showed existing modifications to `by-memory/-coverage-report.md` and `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md`; this pass did not revert or modify those files.

## Lease State

No lease was acquired because this pass only writes the Agent-B001 research report. `tools/leaser/Agents/current_leases.md` had no matching `B001`, `0002BE`, `005030c0`, or `UiAssetModeRectWriteHelper` entry at the final lease check.

## Confidence

Retain target score:

- Completion: `87`
- Confidence: `91`

The no-owner/non-emitting conclusion is well supported by live IDA and PE evidence. The remaining uncertainty is the unrecovered source-use path for the raw helper, not the helper's byte-level behavior. The strongest owner hypothesis remains MapNamePane, but it does not meet by-structure ownership or emitter standards for this specific target.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002BE-UiAssetModeRectWriteHelper-current-goal2-pass.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002BE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
