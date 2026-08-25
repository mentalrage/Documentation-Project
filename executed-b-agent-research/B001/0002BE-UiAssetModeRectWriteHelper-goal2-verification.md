** TARGET-REPORT-UID:0002BE **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Final Recommendation

Keep [UID:0002BE] `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` unchanged:

- `CANONICAL_OWNER:NONE`
- blank `EMITTER_UIDS`
- `RECONSTRUCTABLE:TRUE`
- blank `RECONSTRUCTION_CPP CODE`
- no split, merge, reclassification, child creation, IDA repair, or by-memory coverage replacement.

This is a source-authored, reconstructable raw helper, but the current evidence still does not prove a canonical declaration owner or any generated-output source-use route. Under the current `CANONICAL_OWNER` / `EMITTER_UIDS` model, a reconstructable item can legitimately remain non-emitting when its behavior and exact bytes are known but no caller, table, vtable slot, source-use context, or valid emitter chain is proven. Emitting this helper through `MapNamePane`, `MiniMapButtonPane`, `MiniMap`, `MainMenu`, `RectBounds`, `StartupWindow`, or a new helper file would be an ownership guess.

No exact `by-memory/-coverage-report.md` replacement row is recommended. The current row remains accurate enough for this verification pass.

---

# Research

## Assignment

- Agent: Agent-B001
- Date: 2026-06-14
- Target: [UID:0002BE] `0x005030c0-0x00503104.UiAssetModeRectWriteHelper`
- Target path: `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md`
- Coverage source: `auto-generated/-ag-memory-coverage.md`
- Required final report: `Agent-B001/research/0002BE-UiAssetModeRectWriteHelper-goal2-verification.md`

This was treated as a fresh verification pass. Prior B-agent reports were used only as evidence leads; current documentation and live IDA MCP evidence were rechecked.

## Current Documentation State

The target page currently records:

- `COMPLETION:87`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:TRUE`
- blank `EMITTER_UIDS`
- blank reconstruction C++.

Current generated coverage row from `auto-generated/-ag-memory-coverage.md`:

```text
| [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` |  |
```

Current shared by-memory coverage row:

```text
- [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) 0x005030c0-0x00503104 | raw function | UiAssetModeRectWriteHelper : reconstructable : 87% : strong : A001 Batch310 and B001 second-pass confirm no function object/xrefs/raw pointer hits/section-aware PE-level references/nearby table evidence, exact bytes, unique exact-range and wildcarded-entry signatures, two retn 8 exits at 0x005030e9 and 0x00503101, optional EPF/legacy RectBounds(0,0,0xa6/0xad,0x10) writes through sub_4B7C50 with int_convert-verified extents 166/173/16, output-preserving non-1 state, MapName-width association without direct ownership, and `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS` because no caller/table/source-use emitter route is proven.
```

## Current IDA MCP Evidence

IDA MCP endpoint: `http://127.0.0.1:13337/mcp`

Current IDB session:

- Session id: `a001_goal2_class_batch`
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Image base from PE scan: `0x400000`
- Executable section: `.text`, RVA `0x1000`, virtual size `0x20b52c` approximately, raw pointer `0x400`

Fresh `lookup_funcs` results:

| Address | Result |
| --- | --- |
| `0x00503060` | not a function |
| `0x005030bc` | not a function |
| `0x005030c0` | not a function |
| `0x005030e9` | not a function |
| `0x00503101` | not a function |
| `0x00503104` | not a function |
| `0x00503110` | not a function |
| `0x005031f0` | `sub_5031F0`, size `0xd3` |
| `0x00502e30` | `sub_502E30`, size `0x22c` |
| `0x004b7c50` | `sub_4B7C50`, size `0x1f` |
| `0x0066da97` | not a function |

Fresh `xrefs_to` results:

| Address | Result |
| --- | --- |
| `0x00503060` | zero xrefs |
| `0x005030c0` | zero xrefs |
| `0x00503110` | zero xrefs |
| `0x00503104` | zero xrefs |
| `0x005031f0` | two constructor-call xrefs from `0x004f8051` and `0x004f8695` |
| `0x004b7c50` | broad helper fan-in; not ownership evidence for this target |
| `0x0066da97` | broad mode-selector fan-in; not ownership evidence for this target |

Fresh function inventory for `0x00503000-0x00503220` found only `sub_5031F0` at `0x005031f0`. IDA still has no modeled function object for the target or its sibling raw starts.

Fresh bytes around the target show four `0xcc` bytes before `0x005030c0`, the full helper body, twelve `0xcc` bytes at `0x00503104-0x00503110`, and then the next raw glyph-renderer body. The target range is therefore still exactly bracketed as `0x005030c0-0x00503104`.

Fresh disassembly at `0x005030c0`:

```asm
5030c0  push ebp
5030c1  mov ebp, esp
5030c3  sub dword ptr [ebp+8], 1
5030c7  jnz short loc_503100
5030c9  cmp byte_66DA97, 1
5030d0  push 10h
5030d2  jnz short loc_5030EC
5030d4  push 0A6h
5030d9  push 0
5030db  push 0
5030dd  push dword ptr [ebp+0Ch]
5030e0  call sub_4B7C50
5030e9  retn 8
5030ec  push 0ADh
5030f1  push 0
5030f3  push 0
5030f5  push dword ptr [ebp+0Ch]
5030f8  call sub_4B7C50
503101  retn 8
503104  align 10h
```

Fresh scoped text search over `0x00503000-0x00503200` found only two `byte_66DA97` compares in the raw helper cluster: `0x00503079` in sibling [UID:0002BD] and `0x005030c9` in this target.

Fresh byte/signature checks:

- Exact `0x005030c0-0x00503104` range signature is unique.
- Wildcarded entry signature `55 8B EC 83 6D ? ? 75 ? 80 3D` is unique.
- IDA `find_bytes` found no raw little-endian VA pattern `C0 30 50 00`.
- IDA `find_bytes` found no raw little-endian RVA pattern `C0 30 10 00`.
- IDA `find_bytes` found no `push 0x005030c0` pattern `68 C0 30 50 00`.
- IDA `find_bytes` found no raw pointer bytes for sibling starts `0x00503060` or `0x00503110`.

Fresh section-aware PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` checked targets `0x00503060`, `0x005030c0`, and `0x00503110` across file bytes and `.text` control transfers. For each target, the scan found:

- absolute VA hits: `0`
- RVA hits: `0`
- `E8/E9` rel32 call/jump hits: `0`
- `0F 8x` near conditional branch hits: `0`
- short branch hits: `0`

## Behavior Verification

The helper takes a mode/state argument and an output `RectBounds` pointer. It decrements the first argument. If the adjusted value is nonzero, it returns without writing the output rectangle. If the adjusted value is zero, it calls `sub_4B7C50` to initialize the output rectangle.

The rectangle values are:

- EPF/current mode: `(0, 0, 0x00a6, 0x10)`
- legacy/non-EPF mode: `(0, 0, 0x00ad, 0x10)`

Required conversions rechecked with `int_convert.py`:

- `0x44` is 68 decimal bytes.
- `0x00a6` is 166 decimal.
- `0x00ad` is 173 decimal.
- `0x10` is 16 decimal.
- `0x08` is 8 decimal for the `retn 8` argument pop.

[UID:00015S] documents `sub_4B7C50` as the four-field `RectBounds` initializer. [UID:0000SW] documents `byte_66DA97` / `g_useEpfAssets` as the broad EPF/current-layout selector. Those dependencies explain the helper behavior, but they do not prove source ownership.

## Candidate Owner And Emitter Analysis

### `MapNamePane` / `MapNamePane.cpp`

Candidate UIDs:

- [UID:00007P] `MapNamePane`
- [UID:0000L2] `MapNamePane`

This is the strongest semantic hypothesis. The target is address-adjacent to the MapName/MiniMapButton island, and the `0x00ad` width is the same 173-pixel width used by the documented `MapNamePane` map-name clamp. `0x00ad` was rechecked as 173 decimal with `int_convert.py`.

Rejected as canonical owner or emitter for this target because the fresh evidence still has no caller, table, vtable slot, pointer, source-use context, `this` access, MapName field access, singleton access, or MapName-specific resource literal. The distinction from sibling [UID:0002BF] matters: [UID:0002BF] now has MapNamePane ownership because it reads `this + 0x220`, the same font-field lifecycle initialized and freed by `MapNamePane`. This target has no `this` pointer or field evidence; it only writes a caller-supplied rectangle.

### `MiniMapButtonPane` / `MiniMap`

Candidate UIDs:

- [UID:00008B] `MiniMapButtonPane`
- [UID:0000LE] `MiniMap`

Rejected. The target is near the interleaved MapName/MiniMapButton island, but current docs and fresh IDA evidence do not tie it to MiniMapButtonPane construction, paint, mouse handling, singleton state, vtables, or `MMAPBUT.EPF` resource usage. The current MiniMap/MiniMapButton docs clear the numeric gate for their own methods, but not for this raw helper.

### Main menu, login, and account dialogs

Candidate UID:

- [UID:00019I] `MainMenuLoginAndAccountDialogs`

Rejected. This broad preceding neighborhood is a mixed-owner aggregate and not a direct source owner. The current target is separated from the preceding modeled function by padding and has no caller or table reference from the main menu/login/account code. Address adjacency alone is weak under the current ownership rules.

### `RectBounds` / rectangle geometry helpers

Candidate UIDs:

- [UID:00015S] `RectGeometryHelpers`
- [UID:0000N2] `RectBounds`

Rejected as owner/emitter. `sub_4B7C50` is a shared utility callee with broad fan-in. Calling a generic rectangle initializer proves only the output record shape, not that this helper belongs to `RectBounds.cpp`. The target's source semantics are a UI asset-mode layout helper, not a generic rectangle primitive.

### `g_useEpfAssets` / `StartupWindow`

Candidate UIDs:

- [UID:0000SW] `g_useEpfAssets`
- [UID:0000O5] `StartupWindow`

Rejected. `byte_66DA97` explains the EPF/current versus legacy branch. It is a broad process-wide mode selector with hundreds of consumers. A read of that global does not make the helper a `StartupWindow` declaration or emitter.

### Parent aggregate `UnreferencedUiResourceTextHelpers`

Candidate UID:

- [UID:00022Z] `0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers`

Rejected as emitter. The aggregate is already a reviewed non-emitting split inventory with `RECONSTRUCTABLE:FALSE`; it is not a source-level object or file root. Routing this child through the aggregate would dead-end generated output and would not solve the direct source-owner question.

### New file-level helper or multiple emitters

Rejected. A new helper file would need at least a source-use cluster, table route, or coherent declaration-side evidence. This target has none. Multiple emitters are valid for pooled literals and shared constants when multiple source-use contexts are proven, but this is code, not a pooled string/data item, and no source-use context is proven.

## Split, Merge, Reclassification, And IDA Repair

No split is needed. The body is exactly `0x44` bytes, 68 decimal verified with `int_convert.py`, and is bracketed by `0xcc` padding before and after.

No merge is justified. The parent aggregate already records the raw-helper cluster, while this child carries the exact behavior and reconstruction state.

No reclassification to `RECONSTRUCTABLE:FALSE` is justified. The byte pattern is normal source-authored MSVC-shaped code in `.text`, with a clear `RectBounds` write behavior and real dependencies on project helpers/globals. The issue is ownership and emission routing, not whether the bytes represent reconstructable project logic.

No IDA repair is recommended for this pass. Defining a function at `0x005030c0` in IDA could make local disassembly easier, but it would not create a caller, table, or owner. The B-agent assignment is report-only unless a documentation repair is justified, and no by-* edit is needed.

## Exact Recommended Changes

Target page:

```text
No change.
```

Coverage reports:

```text
No replacement row recommended for by-memory/-coverage-report.md.
No direct edit made to by-memory/-coverage-report.md.
```

Tracker suggestion for supervisor only:

```text
Mark UID 0002BE as complete-no-change with this report path.
```

## Validation And Execution Notes

- No leases were used because only this Agent-B001 research report was created.
- No by-* documentation files were edited.
- `by-memory/-coverage-report.md` was not edited.
- No dry runs were used.
- No validator run was needed because no validator-managed by-* page was changed.
- IDA MCP evidence was collected from the current live `a001_goal2_class_batch` session.
- The failed first PE scan attempt was retried with corrected signed-byte handling; the successful scan results above are the evidence used.

## Confidence

Confidence in the no-owner/non-emitting recommendation: high.

The boundary, behavior, no-function state, zero direct xrefs, unique signatures, missing raw pointer bytes, and missing PE-level branch/pointer references are all freshly rechecked. The main residual uncertainty is why this source-shaped helper remains present with no visible route. That uncertainty is exactly why it should stay reconstructable but non-emitting until a real caller/table/source-use route is found.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002BE-UiAssetModeRectWriteHelper-goal2-verification.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002BE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
