** TARGET-REPORT-UID:0002BE **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BE UiAssetModeRectWriteHelper Second-Pass Ownership / Emitter Research

Revision: Agent-B001 second-pass final report, 2026-06-13.

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002BE] `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` as reconstructable source-authored code with `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank reconstruction C++.
- Final disposition: continued no-owner/non-emitting state is justified. No split, merge, reclassification, IDA function-definition repair, by-class/by-file parent repair, or new source grouping is required before closing this second pass.
- Exact metadata recommendation:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Score before/after: before `87/91`; after independent B001 second-pass review `87/91`. Completion should not rise because no caller, table, source owner, emitter, source-facing output name, or final source placement is known. Confidence remains high for the negative routing evidence and exact behavior.
- Coverage-report action: no required `by-memory/-coverage-report.md` replacement. The current row is still accurate and should stay in address order under [UID:00022Z] unless the supervisor wants a purely editorial "B001 second-pass confirmed" refresh.
- Confidence: `90/100` for the no-owner/non-emitting recommendation, `94/100` for exact range/behavior/unreferenced status, and below action threshold for any positive owner or emitter route.

This is a valid reconstructable no-owner/non-emitting state under the current owner/emitter system. The helper is real source-shaped NexusTK code, but `EMITTER_UIDS` requires a defensible source-use/output context. Current live IDA MCP and fresh raw executable evidence still find no caller, no function object, no vtable slot, no raw pointer, no RVA literal, no branch/call target, no class-local field access, and no table/callback owner for `0x005030c0`.

## Supporting Research

## Target

- Target UID: `0002BE`
- Target path: `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md`
- Coverage source: `auto-generated/-ag-memory-coverage.md`
- Tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, row `0002BE`, reopened as `B001-0002BE-second-pass`.
- Prior report reviewed as evidence, not as authority: `tools/leaser/Agents/Agent-B002/research/executed/0002BE-UiAssetModeRectWriteHelper-post-migration.md`.
- Current target state: `COMPLETION:87`, `CONFIDENCE:91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`.

Current generated memory-coverage row, kept unchanged:

```text
| [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` |  |
```

Current `by-memory/-coverage-report.md` row, kept unchanged:

```text
        - [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) 0x005030c0-0x00503104 | raw function | UiAssetModeRectWriteHelper : reconstructable : 87% : strong : A001 Batch310 confirms no function object/xrefs/raw pointer hits/section-aware PE-level references/nearby table evidence, exact bytes, unique exact-range and wildcarded-entry signatures, two retn 8 exits at 0x005030e9 and 0x00503101, optional EPF/legacy RectBounds(0,0,0xa6/0xad,0x10) writes through sub_4B7C50 with int_convert-verified extents 166/173/16, output-preserving non-1 state, MapName-width association without direct ownership, and blank parent because no caller/table/source owner is proven.
```

## Executive Recommendation

Keep the target as `CANONICAL_OWNER:NONE` and leave `EMITTER_UIDS` blank. The helper's physical behavior is clear: when the first argument is exactly `1`, it writes a `RectBounds(0, 0, 0xa6/0xad, 0x10)` into the caller-provided second argument, choosing the right edge by [UID:0000SW] `g_useEpfAssets`; otherwise it returns without writing the output rectangle. The missing piece is not behavior. The missing piece is a source-use route.

The best positive source-family hypothesis remains MapName-side UI/resource layout support. The `0xad` right edge matches the documented 173-pixel MapName clamp, the helper sits immediately before the MapName/MiniMapButton island, and sibling [UID:0002BF] now routes to [UID:00007P] `MapNamePane`. Those facts are not enough for this target. `0002BF` has direct object-field evidence: it is a `thiscall` renderer reading `this + 0x220`, while `MapNamePane` constructor/destructor manage the same field. `0002BE` has no `this`, no class-field access, no caller, no table, and no vtable slot.

Do not route this through `MapNamePane`, `MiniMapButtonPane`, `MiniMap`, `MainMenuPane`, `StartupWindow`, `RectBounds`, or a new helper file. Any such route would be a source-placement guess, not an emitter route proven by IDA/raw evidence.

## Supervisor Active Recheck

The supervisor requested an independent second-pass owner/emitter review after the B002 post-migration report. This pass re-read the B001 goal, current owner/emitter rules, the target page, the B002 report, the aggregate and sibling pages, candidate owner pages, generated coverage, manual coverage, and proposed source-tree evidence. Live IDA MCP and raw executable scans were rerun rather than relying only on previous reports.

No split repair is needed. The exact parent aggregate [UID:00022Z] is already a non-emitting split inventory, and the current child split isolates `0002BD`, `0002BE`, and `0002BF` correctly. Splitting `0002BE` further is not meaningful: the whole `0x44`-byte body is one contiguous helper with one prologue, two internal return sites, and no separable sub-owner.

No IDA repair is required for ownership. Defining a formal IDA function at `0x005030c0` could improve decompilation convenience later, but it would not create caller, table, vtable, or source-use evidence. This report therefore does not recommend IDA-side mutation.

## Inference Research Guidance Check

Applied `by-structure.md` and B001 inference guidance:

- `CANONICAL_OWNER` must be the narrowest true semantic owner. No true direct owner is proven.
- `EMITTER_UIDS` is output routing, not "plausible source family." No source-use output context is proven.
- `RECONSTRUCTABLE:TRUE` is still correct because the helper is source-shaped custom project code, not padding, CRT, or compiler-generated support.
- Multiple emitters are valid for pooled literals or shared constants with proven consumers. This target is different: it is an unreferenced raw helper body with no known caller or consumer.
- Existing docs are treated as leads. The B002 report agrees with this final recommendation, but the recommendation here rests on fresh live IDA MCP and raw PE evidence.

The active 90/90+ reconstruction-code bar does not change the result. The target is `87/91`, has no emitter route, and lacks final source placement/naming; B reports also do not write final C++ directly.

## Evidence Standards Used

Evidence used in this pass:

- Live IDA MCP session `b001_0003gy` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, input MD5 `4247e04e20b65d6414c7238aa8ff5515`, image base `0x00400000`.
- IDA MCP tools: `server_health`, `survey_binary`, `lookup_funcs`, `xrefs_to`, `insn_query`, `get_bytes`, `search_text`, `entity_query`, `make_signature_for_range`, `find_bytes`, and `int_convert`.
- Independent read-only PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for absolute VAs, RVAs, relative branches/calls, conditional branches, short branches, exact body uniqueness, and nearby vtable slot values.
- Documentation evidence from target/aggregate/sibling pages, `MapNamePane`, `MiniMapButtonPane`, `MiniMap`, `g_useEpfAssets`, `RectGeometryHelpers`, generated coverage, manual memory coverage, and proposed source-tree.

## IDA MCP Facts

### Function and Range Facts

`lookup_funcs` on 2026-06-13:

| Address | IDA result |
| --- | --- |
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
| `0x004b7c50` | `sub_4B7C50`, size `0x1f` |

`make_signature_for_range 0x005030c0-0x00503104` returned a unique wildcarded IDA signature:

```text
55 8B EC 83 6D ? ? 75 ? 80 3D ? ? ? ? ? 6A 10 75 ? 68 A6 00 00 00 6A 00 6A 00 FF 75 ? E8 ? ? ? ? 83 C4 14 5D C2 08 00 68 AD 00 00 00 6A 00 6A 00 FF 75 ? E8 ? ? ? ? 83 C4 14 5D C2 08 00
```

### Target Instruction Facts

`insn_query 0x005030c0-0x00503104` decodes exactly 23 instructions:

```asm
5030c0  push    ebp
5030c1  mov     ebp, esp
5030c3  sub     dword ptr [ebp+8], 1
5030c7  jnz     short loc_503100
5030c9  cmp     byte_66DA97, 1
5030d0  push    10h
5030d2  jnz     short loc_5030EC
5030d4  push    0A6h
5030d9  push    0
5030db  push    0
5030dd  push    dword ptr [ebp+0Ch]
5030e0  call    sub_4B7C50
5030e5  add     esp, 14h
5030e8  pop     ebp
5030e9  retn    8
5030ec  push    0ADh
5030f1  push    0
5030f3  push    0
5030f5  push    dword ptr [ebp+0Ch]
5030f8  call    sub_4B7C50
5030fd  add     esp, 14h
503100  pop     ebp
503101  retn    8
```

`int_convert` verified:

| Hex | Decimal | Meaning |
| --- | ---: | --- |
| `0xA6` | `166` | EPF/current mode rectangle right edge |
| `0xAD` | `173` | legacy rectangle right edge and MapName-width association |
| `0x10` | `16` | rectangle bottom edge |
| `0x44` | `68` | exact helper byte count |

### Xref and Table Facts

`xrefs_to` on 2026-06-13:

| Address | Result |
| --- | --- |
| `0x00503060` | zero xrefs |
| `0x005030c0` | zero xrefs |
| `0x00503110` | zero xrefs |
| `0x005031f0` | two code xrefs from `0x004f8051` and `0x004f8695` in `sub_4F7D10` |
| `0x00503350` | one data xref from `0x0061e5f8` |
| `0x005034a0` | one data xref from `0x0061e610` |
| `0x00503580` | one code xref from `0x004f80c2` |

Nearby vtable heads are real, but none point to the raw target:

| Address | IDA name / status |
| --- | --- |
| `0x0061e5b4` | `??_7MapNamePane@@6B@`; xrefs from MapName constructor/destructor/deleting destructor |
| `0x0061e600` | `??_7MapNamePane@@6B@_0`; xrefs from MapName constructor/destructor/deleting destructor |
| `0x0061e630` | `??_7MapNamePane@@6B@_1`; xrefs from MapName constructor/destructor/deleting destructor |
| `0x0061e63c` | `??_7MiniMapButtonPane@@6B@` |
| `0x0061e688` | `??_7MiniMapButtonPane@@6B@_0` |
| `0x0061e6b8` | `??_7MiniMapButtonPane@@6B@_1` |

Raw vtable/table dword values from the executable contain modeled MapName/MiniMapButton slots such as `0x00503840`, `0x00503350`, `0x005034a0`, `0x0050380b`, `0x00503816`, `0x00503900`, `0x00503650`, `0x00503821`, `0x005036a0`, and `0x0050382c`. None of the checked table heads contain `0x00503060`, `0x005030c0`, or `0x00503110`.

### Raw PE Facts

Fresh read-only executable scan on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

| Target | Absolute VA hits | RVA hits | `E8/E9` rel32 targets | `0F 8x` near conditional targets | short branch targets |
| --- | ---: | ---: | ---: | ---: | ---: |
| `0x00503060` | 0 | 0 | 0 | 0 | 0 |
| `0x005030c0` | 0 | 0 | 0 | 0 | 0 |
| `0x00503110` | 0 | 0 | 0 | 0 | 0 |

The exact `0x44`-byte target body appears once in the executable: file offset `0x1024c0`, VA `0x005030c0`.

### Sibling Contrast Facts

Sibling [UID:0002BF] has evidence that `0002BE` lacks. Live `insn_query` on `0x00503188-0x0050319d` shows:

```asm
50318e  mov     ecx, edi
503196  add     eax, [edi+220h]
50319c  mov     [ebp-38h], eax
```

Scoped `search_text` over the MapName constructor/destructor area shows:

- `0x005032a9`: `mov [esi+220h], eax` in `sub_5031F0`.
- `0x005032f5`: `mov eax, [esi+220h]` in `sub_5032D0`.
- `0x00503326`: `mov [esi+220h], eax` in `sub_5032D0`.

That is why `0002BF` can be defensibly routed to `MapNamePane`: it directly reads the MapName-managed field. `0002BE` does not read any receiver field and has no comparable class anchor.

### Negative IDA Facts

- No IDA function object exists at `0x005030c0`.
- No direct xrefs target `0x005030c0`.
- No vtable slot or table entry to `0x005030c0` was found in the nearby MapName/MiniMapButton read-only data.
- No raw pointer, RVA, rel32 branch/call, near conditional branch, or short branch target reaches `0x005030c0`.
- No `this` register usage, class field access, resource string operand, singleton, or object-local pointer appears in the target body.
- The target's dependencies, `byte_66DA97` and `sub_4B7C50`, are broad shared dependencies rather than owner evidence.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00503060-0x005031e1` | [UID:00022Z] `UnreferencedUiResourceTextHelpers` | Non-emitting split inventory | FALSE | NONE | `86/90` | Container only |
| `0x00503060-0x005030bc` | [UID:0002BD] `UiAssetModeRectVirtualDispatchHelper` | Raw asset-mode rectangle helper with vtable dispatch | TRUE | NONE | `87/91` | Sibling no-owner/non-emitting |
| `0x005030c0-0x00503104` | [UID:0002BE] target | Raw asset-mode rectangle write helper | TRUE | NONE | `87/91` | Keep no-owner/non-emitting |
| `0x00503110-0x005031e1` | [UID:0002BF] `WideGlyphResourceTextRendererRaw` | Raw wide glyph renderer | TRUE | `00007P` | `87/91` | Sibling routed to MapNamePane by field evidence |
| `0x005031f0-0x0050395f` | [UID:0001AL] `MapNameAndMiniMapButtonPanes` | Mixed MapName/MiniMapButton split inventory | FALSE | NONE | `86/92` | Adjacent modeled island |

## Source-Use / Emitter Inventory

| Candidate source-use context | Evidence present | Evidence missing | Emitter decision |
| --- | --- | --- | --- |
| Unknown direct caller | none | no caller, branch target, pointer, table, or vtable slot | no emitter |
| [UID:00007P] `MapNamePane` | proximity, `0xad`/173 width association, sibling `0002BF` route | no call/table/vtable/ref/field evidence for `0002BE` | no emitter |
| [UID:0000L2] `MapNamePane.cpp` | plausible source-family file | no direct source-use proof | no emitter |
| [UID:00008B] `MiniMapButtonPane` / [UID:0000LE] `MiniMap` | adjacent island contains MiniMapButton vtables/resources | no target slot, field, singleton, resource literal, or caller | no emitter |
| [UID:0000SW] `g_useEpfAssets` / [UID:0000O5] `StartupWindow` | target reads the global | global read dependency only; StartupWindow does not own helper | no emitter |
| [UID:00015S] `RectGeometryHelpers` / [UID:0000N2] `RectBounds` | target calls rectangle initializer | broad helper dependency only; caller-specific constants are not RectBounds source | no emitter |
| New `MapNameUiResourceTextHelpers` file/group | design-plausible if a hidden callback table appears | no table/caller/source breadcrumb today | no new emitter |

## Documentation Evidence And IDA Status

- Target page: IDA confirms current range, behavior, no-function status, no xrefs, `byte_66DA97` compare, `sub_4B7C50` calls, unique signature, and padding. The page remains a good behavior record.
- [UID:00022Z] aggregate: IDA confirms it is a non-emitting split inventory. The aggregate cannot be an emitter because it is `RECONSTRUCTABLE:FALSE` and not a source root.
- [UID:0002BD] sibling: similar no-owner/non-emitting rectangle helper. It supports treating rectangle helpers conservatively.
- [UID:0002BF] sibling: now routed to MapNamePane, but IDA confirms the decisive `this+0x220` field evidence exists in `0002BF`, not `0002BE`.
- [UID:00007P] / [UID:0000L2] `MapNamePane`: IDA confirms constructor callers, vtables, render/update slots, `g_pMapNamePane`, `MAPNAME.EPF`, and `this+0x220` font field. None of those point to `0002BE`.
- [UID:00008B] / [UID:0000LE] `MiniMapButtonPane` / `MiniMap`: IDA confirms MiniMapButton constructor, vtables, `MMAPBUT.EPF`, and singleton evidence. None of those point to `0002BE`.
- [UID:0000SW] `g_useEpfAssets`: IDA confirms broad global use and StartupWindow ownership. A read of that global is not ownership of every consumer helper.
- [UID:00015S] `RectGeometryHelpers`: IDA confirms `sub_4B7C50` is a broad rectangle initializer. It is a dependency, not the target's owner.
- `proposed-source-tree.md`: lists `MapNamePane.cpp`, `MiniMap.cpp`, `StartupWindow.cpp`, `RectBounds.cpp`, and broader resource modules. It does not provide a verified source root for this raw helper.

## Ranked Ownership Analysis

### 1. Keep `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`

Evidence for:

- Live IDA reports no function object and zero xrefs to `0x005030c0`.
- Fresh PE scan finds zero absolute VA, RVA, rel32, near-conditional, or short-branch references to `0x005030c0`.
- Nearby MapName and MiniMapButton vtable/table data contains real modeled class slots but no raw helper start.
- The target body has no receiver field, singleton, resource string, class-local global, or direct source breadcrumb.
- The only positive owner evidence is proximity/constant association, which is weaker than the negative caller/table evidence.

Evidence against:

- The body is real source-shaped code and eventually may need reconstruction if a source-use route is found.
- MapName-side helper ancestry remains plausible.

Decision: accepted. This is the only route that preserves the facts without inventing source output.

### 2. Route to [UID:00007P] `MapNamePane` / [UID:0000L2] `MapNamePane.cpp`

Evidence for:

- The target sits immediately before the MapName/MiniMapButton modeled island.
- The legacy width `0xad` is decimal `173`, matching the documented MapName clamp.
- Sibling `0002BF` is now MapName-owned.
- MapName constructor and render methods also use `g_useEpfAssets`.

Evidence against:

- No caller, table, branch, pointer, or vtable slot connects `MapNamePane` to `0x005030c0`.
- The target has no `this+0x220` field evidence, unlike `0002BF`.
- The target has no `MAPNAME.EPF`, `9X11FONT.BIN`, `g_pMapNamePane`, or MapName vtable interaction.
- Assigning by proximity would ignore the documented warning in [UID:0001AL] not to absorb the raw cluster without caller/vtable evidence.

Decision: strongest forced source-family hypothesis, rejected as canonical owner and emitter.

### 3. Route to a new MapName-side raw helper grouping

Possible names:

- `MapNameUiResourceTextHelpers`
- `MapNameRetainedResourceHelpers`
- `UiAssetModeRectHelpers`

Evidence for:

- The first two raw helpers share the `g_useEpfAssets` rectangle extent behavior.
- A hidden legacy callback/table source could plausibly have kept these helpers beside MapName resource code.

Evidence against:

- No source file name, caller table, callback list, vtable, pointer, or resource string supports the grouping.
- `0002BF` now has a direct class route; grouping it back with the rectangle helpers would weaken a proven owner.
- A new source file would be a documentation convenience rather than an evidence-backed source root.

Decision: reject for now. If a future table/caller is found, revisit a narrow helper group covering `0002BD` and `0002BE` first; do not move `0002BF` unless future evidence supersedes its MapName field route.

### 4. Route to [UID:00008B] `MiniMapButtonPane` / [UID:0000LE] `MiniMap`

Evidence for:

- The modeled adjacent island includes MiniMapButtonPane.
- MiniMapButtonPane has nearby vtables and `MMAPBUT.EPF` resource data.

Evidence against:

- No MiniMapButton vtable slot or constructor path points to `0x005030c0`.
- The target's `0xad` width association is more MapName-like than MiniMap-like.
- There is no MiniMap singleton/resource/string/field evidence in the target body.

Decision: rejected.

### 5. Route to MainMenu/Login source family

Evidence for:

- The previous modeled function before the raw cluster belongs near the MainMenu/login account-dialog neighborhood.

Evidence against:

- `0x0050305c-0x00503060` is explicit `0xcc` padding before the raw helper cluster.
- No caller/table/vtable evidence connects MainMenu code to `0x005030c0`.
- The target behavior is asset-mode rectangle layout, not login/account packet/dialog logic.

Decision: rejected.

### 6. Route through [UID:0000SW] `g_useEpfAssets` / [UID:0000O5] `StartupWindow`

Evidence for:

- The target reads `byte_66DA97`.

Evidence against:

- `g_useEpfAssets` has broad cross-subsystem readers. Reading it does not make the reader a `StartupWindow` source item.
- `StartupWindow` owns the global by setter/lifecycle inference, not every branch controlled by the global.

Decision: rejected.

### 7. Route through [UID:00015S] `RectGeometryHelpers` / [UID:0000N2] `RectBounds`

Evidence for:

- The target calls `sub_4B7C50`, the `RectBounds` initializer.

Evidence against:

- `sub_4B7C50` has broad fan-in. It initializes caller-provided rectangles and does not own caller-specific asset-mode constants.
- The target is a caller-specific helper, not a geometry primitive.

Decision: dependency only; rejected as owner and emitter.

## Negative Evidence Summary

- No function object at `0x005030c0`.
- No xrefs to `0x005030c0`.
- No raw absolute pointer or RVA literal for `0x005030c0`.
- No `E8/E9`, `0F 8x`, or short-branch target to `0x005030c0`.
- No nearby MapName or MiniMapButton vtable slot to `0x005030c0`.
- No `this`, class field, singleton, resource literal, string, or table/callback entry in the target body.
- No source-tree entry names a confirmed raw helper source for this item.
- Sibling `0002BF` has MapName field evidence; `0002BE` does not.

## Final Recommendation

Exact recommended state:

- Keep `COMPLETION:87`.
- Keep `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:NONE`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:` blank.
- Keep `EMITTER_POSITION_OPTIONAL:` blank.
- Keep reconstruction C++ blank.
- Keep `auto-generated/-ag-memory-coverage.md` generated state unchanged.
- Keep `by-memory/-coverage-report.md` row unchanged.
- Do not split the target.
- Do not define or mutate IDA functions as part of this ownership task.

Optional nonblocking documentation cleanup if a future A-agent edits the target page: update stale "95/95 source-emission gate" phrasing to the current 90/90+ code-entry gate. Suggested replacement sentence for the target `## Reconstruction Gate` paragraph:

```text
No C++ is emitted for this page. The raw behavior is documented, but the item remains below the active 90/90+ reconstruction-code bar because it is `87/91`, lacks a proven owner/emitter route, has no caller/table/source-use context, and still lacks source-facing output type/name evidence.
```

This wording cleanup is not required to execute the ownership/emitter recommendation and was not applied by B001.

## Follow-Up Actions

- Supervisor: mark tracker row `0002BE` completed/no-change for `B001-0002BE-second-pass`.
- Supervisor: no coverage-report edit required. If a row refresh is desired for audit trail only, use the current row content above as the baseline and append that B001 second-pass reconfirmed the same no-owner/non-emitting outcome with live IDA session `b001_0003gy` plus raw PE scan.
- A-agents: do not attach `0002BE` to MapNamePane, MiniMapButtonPane, MiniMap, MainMenu, StartupWindow, RectBounds, or a new helper file without new caller/table/source evidence.
- Future research: if a non-standard callback table or generated EH/table reference is later found, revisit `0002BD` and `0002BE` together as possible narrow rectangle-helper siblings.

## Confidence

- Recommendation confidence: `90/100`.
- Range/behavior confidence: `94/100`.
- No-reference confidence: `93/100`, based on live IDA `xrefs_to`, `find_bytes`, and independent executable scan.
- Best positive source-family confidence: `70/100` for MapName-side UI/resource layout support as a hypothesis only.
- Direct `MapNamePane` owner/emitter confidence: `40/100`, below action threshold.
- New helper grouping confidence: `35/100`, below action threshold.
- Remaining uncertainty: the helper may be stale retained code, or reachable through a mechanism not represented by direct IDA xrefs, absolute/RVA literals, conventional branch/call encodings, or nearby vtable slots. That uncertainty is exactly why it remains reconstructable but non-emitting.

## Validator Results

- Validator was not run. No by-* documentation, generated report, coverage report, project-level report, or validator-managed target page was edited.
- No dry-run validator mode was used.
- No memory-range validator mode was used.
- No lease was required because the only created file is this report inside `tools/leaser/Agents/Agent-B001/research`.

## Command / Evidence Log

- Read `tools/leaser/Agents/Agent-B001/goal.md`.
- Read target page, prior B002 report, aggregate and sibling pages, candidate owner docs, current generated row, tracker row, and current coverage row.
- Queried MCP endpoint `http://127.0.0.1:13337/mcp` with `initialize`, `tools/list`, and `idb_list`; reused active session `b001_0003gy`.
- Ran `server_health`, `survey_binary`, `lookup_funcs`, `xrefs_to`, `insn_query`, `get_bytes`, `search_text`, `entity_query`, `make_signature_for_range`, `find_bytes`, and `int_convert` through IDA MCP.
- Ran a read-only raw executable scan of `NexusTK.exe` for absolute VAs, RVAs, branch/call encodings, exact body uniqueness, and vtable slots. Two initial PowerShell implementations were discarded after timeout/signed-byte problems; the successful evidence scan was the final Python read-only scan recorded above.
- Ran `rg` for `0002BE`, `0x005030c0`, and `UiAssetModeRectWriteHelper` across project documentation to check for current references and stale leads.

## Changed Files

- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\0002BE-UiAssetModeRectWriteHelper-second-pass.md`
- Modified: none outside this report.
- Renamed: none.
- Moved to executed: none.

## Blockers

No external blocker. The only blocker to positive owner/emitter routing is evidentiary: no caller, table, vtable, pointer, branch, source breadcrumb, or class-field evidence currently ties `0x005030c0` to a source-use output context.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002BE-UiAssetModeRectWriteHelper-second-pass.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002BE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
