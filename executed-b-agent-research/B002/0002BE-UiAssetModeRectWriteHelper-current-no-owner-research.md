** TARGET-REPORT-UID:0002BE **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002BE] UiAssetModeRectWriteHelper Current No-Owner Research

## Final Recommendation

Keep [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](../../../../../by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank reconstruction C++.

No canonical owner, emitter route, split, merge, reclassification, or IDA-safe rename is justified by the current evidence. The target is a reconstructable raw helper, but it still has no caller, xref, function-object, pointer, branch/call, table, vtable-slot, class-field, singleton, resource-literal, or source-use route that can surface generated source.

One direct target-page repair was required and applied: the `Reconstruction Gate` section used stale `90/90+` wording. It now reflects the current gate: `(COMPLETION + CONFIDENCE) / 2 = 89` clears the score side, but code entry still fails because `EMITTER_UIDS` is blank and no valid generated-source route is proven.

Scores remain `COMPLETION:87`, `CONFIDENCE:91`. No shared coverage row replacement is needed; retain the current coverage row.

## Target And Current State

- UID: `0002BE`
- Target path: `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md`
- Address range: `0x005030c0-0x00503104`
- Current generated state: reconstructable no-owner/non-emitting
- Current metadata after this pass:

```text
COMPLETION:87
CONFIDENCE:91
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP: blank
```

Active generated row checked in `auto-generated/-ag-memory-coverage.md`:

```markdown
| [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` |  |
```

Prior reports were reviewed as historical context only:

- `Agent-B002/research/executed/0002BE-UiAssetModeRectWriteHelper-current-no-owner-recheck.md`
- `Agent-B001/research/executed/0002BE-UiAssetModeRectWriteHelper-second-pass.md`

The current pass independently rechecked the target page, generated rows, tracker state, related file/class/global docs, and live IDA/PE evidence.

## Evidence Standard Applied

The current owner/emitter model allows `CANONICAL_OWNER:NONE` when no single declaration/source owner is defensible. For code entry, the active gate requires:

- `RECONSTRUCTABLE:TRUE`
- confirmed nonblank `EMITTER_UIDS` that surface to valid generated source without a dead end
- `(COMPLETION + CONFIDENCE) / 2 > 85`

This item meets `RECONSTRUCTABLE:TRUE` and score average `89`, but fails the nonblank-emitter/source-route side. Therefore C++ remains blank even though the raw behavior is well documented.

## IDA Facts

Live IDA MCP evidence from the current pass:

- `lookup_funcs` reports no function object at `0x005030c0`.
- Neighboring modeled functions remain:
  - `sub_502E30` at `0x00502e30`, size `0x22c`
  - `sub_5031F0` at `0x005031f0`, size `0xd3`
  - `sub_5032D0` at `0x005032d0`, size `0x7d`
  - `sub_503350` at `0x00503350`, size `0x14f`
  - `sub_5034A0` at `0x005034a0`, size `0xd4`
  - `sub_503580` at `0x00503580`, size `0x9e`
  - `sub_503650` at `0x00503650`, size `0x42`
  - `sub_5036A0` at `0x005036a0`, size `0x14d`
  - rectangle initializer `sub_4B7C50` at `0x004b7c50`, size `0x1f`
- `xrefs_to` found zero references to `0x005030c0`, `0x00503104`, `0x00503060`, `0x005030bc`, and `0x00503110`.
- Internal-only references exist inside the helper:
  - `0x005030d2 -> 0x005030ec`
  - `0x005030c7 -> 0x00503100`
  - `0x005030fd -> 0x00503100`
- Positive nearby references point to later MapName/MiniMapButton modeled methods and vtable heads, not to this target.

Decoded target instructions:

```asm
005030c0  push    ebp
005030c1  mov     ebp, esp
005030c3  sub     dword ptr [ebp+8], 1
005030c7  jnz     short loc_503100
005030c9  cmp     byte_66DA97, 1
005030d0  push    10h
005030d2  jnz     short loc_5030EC
005030d4  push    0A6h
005030d9  push    0
005030db  push    0
005030dd  push    dword ptr [ebp+0Ch]
005030e0  call    sub_4B7C50
005030e5  add     esp, 14h
005030e8  pop     ebp
005030e9  retn    8
005030ec  push    0ADh
005030f1  push    0
005030f3  push    0
005030f5  push    dword ptr [ebp+0Ch]
005030f8  call    sub_4B7C50
005030fd  add     esp, 14h
00503100  pop     ebp
00503101  retn    8
```

Behavior: decrement first argument; if adjusted value is zero, write a caller-supplied `RectBounds` through `sub_4B7C50`. The rectangle is `(0,0,0xa6,0x10)` when `g_useEpfAssets == 1`, otherwise `(0,0,0xad,0x10)`. Non-1 adjusted state returns without writing. Constants are 166, 173, and 16; `retn 8` pops two caller arguments.

## Raw PE Evidence

Raw executable scan evidence against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

- Image base: `0x400000`
- Target VA `0x005030c0` maps to raw offset `0x1024c0` in `.text`.
- Exact body bytes for `0x005030c0-0x00503104` occur once, at VA `0x005030c0`.
- Wildcarded entry signature is unique:

```text
55 8B EC 83 6D ? ? 75 ? 80 3D ? ? ? ? ? 6A 10 75 ? 68 A6 00 00 00 6A 00 6A 00 FF 75 ? E8 ? ? ? ? 83 C4 14 5D C2 08 00 68 AD 00 00 00 6A 00 6A 00 FF 75 ? E8 ? ? ? ? 83 C4 14 5D C2 08 00
```

Pointer/reference checks:

- Absolute VA little-endian references to `0x00503060`, `0x005030c0`, and `0x00503110`: none
- RVA little-endian references to `0x00103060`, `0x001030c0`, and `0x00103110`: none
- `push <VA>` references to those starts: none
- Direct external branch/call targets to those starts: none
- Apparent raw branch hits into the middle of the range were instruction-boundary false positives or internal helper branches, not valid external ownership routes.

Nearby vtable dword scans around `0x0061e5b4-0x0061e6c4` contain MapName/MiniMapButton slots for modeled methods such as `0x503840`, `0x503350`, `0x5034a0`, `0x503900`, `0x503650`, and `0x5036a0`. They do not contain `0x503060`, `0x5030c0`, or `0x503110`.

## Related Documentation Checked

- [UID:00022Z][0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers](../../../../../by-memory/0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md): aggregate inventory only, `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`; not a source owner or emitter.
- [UID:0002BF][0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw](../../../../../by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md): sibling with stronger MapName evidence because it reads `this+0x220`; this target has no comparable `this` or field access.
- [UID:0000L2][MapNamePane](../../../../../by-file/MapNamePane.md) and [UID:00007P][MapNamePane](../../../../../by-class/MapNamePane.md): strongest semantic family because of the adjacent pane island and the `0xad` width association, but no caller/table/vtable/source-use route to this raw helper.
- [UID:0000SW][g_useEpfAssets](../../../../../by-global/g_useEpfAssets.md): process-wide EPF/legacy mode selector read by this helper; not a source owner for every consumer.
- [UID:0000O5][StartupWindow](../../../../../by-file/StartupWindow.md): owns startup policy for the global mode selector, not this local consumer helper.
- [UID:0000LE][MiniMap](../../../../../by-file/MiniMap.md), [UID:00008B][MiniMapButtonPane](../../../../../by-class/MiniMapButtonPane.md), and [UID:0000L0][MainMenuPane](../../../../../by-file/MainMenuPane.md): no direct route to `0x005030c0`.
- [UID:0000N2][RectBounds](../../../../../by-file/RectBounds.md) / `sub_4B7C50`: callee utility used by the helper, not owner/emitter of the helper.

## Owner And Emitter Alternatives Rejected

1. Keep `CANONICAL_OWNER:NONE` and blank emitters: accepted. It matches the current absence of source-use routes and prevents an unowned raw helper from being emitted through a guessed file.
2. Assign MapNamePane: rejected. The semantic association is real, but current xref, pointer, vtable, table, field, and caller evidence do not prove this helper belongs to `MapNamePane`.
3. Assign MiniMap or MiniMapButtonPane: rejected. Neighboring functions and vtables support later MiniMapButton methods, but no slot or reference points at this raw helper.
4. Assign StartupWindow or `g_useEpfAssets`: rejected. The helper reads the global, but the global is a broad mode selector; consumer reads do not establish a source owner.
5. Assign RectBounds: rejected. `sub_4B7C50` is only the rectangle initializer callee.
6. Create a new helper source file/emitter: rejected. There is no caller/table/source context to name a source file or prove an output route.
7. Reclassify non-reconstructable: rejected. The exact raw behavior, boundaries, and constants are sufficiently documented, and the page correctly represents source-authored raw helper code. The problem is emission route, not reconstructability.
8. Split or merge: rejected. The range is a unique 68-byte helper with two local returns and clean alignment. The containing aggregate already tracks the larger raw cluster; this child should remain a separate reconstructable memory item.
9. IDA-safe rename/repair: rejected. IDA has no function object at the start, and no new safe name evidence was found.

## Exact Edits Applied

Edited `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` under lease:

- Replaced stale `90/90+` reconstruction-gate wording with current nonblank-emitter/source-route gate wording.
- Added a `2026-06-14 B002 current no-owner sweep gate wording repair` change-log entry.
- No metadata values changed.
- No C++ was entered.

Before/after scores:

```text
Before: COMPLETION:87, CONFIDENCE:91
After:  COMPLETION:87, CONFIDENCE:91
```

## Shared Report Text

Do not edit `by-memory/-coverage-report.md` for this item. Retain the current row:

```markdown
        - [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) 0x005030c0-0x00503104 | raw function | UiAssetModeRectWriteHelper : reconstructable : 87% : strong : A001 Batch310 and B001 second-pass confirm no function object/xrefs/raw pointer hits/section-aware PE-level references/nearby table evidence, exact bytes, unique exact-range and wildcarded-entry signatures, two retn 8 exits at 0x005030e9 and 0x00503101, optional EPF/legacy RectBounds(0,0,0xa6/0xad,0x10) writes through sub_4B7C50 with int_convert-verified extents 166/173/16, output-preserving non-1 state, MapName-width association without direct ownership, and `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS` because no caller/table/source-use emitter route is proven.
```

Do not replace the generated memory coverage row. Retain:

```markdown
| [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` |  |
```

Recommended tracker close-out text for supervisor-owned tracker application:

```markdown
| `0002BE` | 0x005030c0-0x00503104.UiAssetModeRectWriteHelper | `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` | Agent-B002 | 2026-06-14 | complete-no-change-target-gate-wording-repair | `Agent-B002/research/0002BE-UiAssetModeRectWriteHelper-current-no-owner-research.md` | `Agent-B002/research/executed/0002BE-UiAssetModeRectWriteHelper-current-no-owner-recheck.md` |
```

## Validation

Command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0002BE-UiAssetModeRectWriteHelper-current-no-owner-research-removed.md](0002BE-UiAssetModeRectWriteHelper-current-no-owner-research-removed.md). The archived block is non-authoritative and must not be executed.

Relevant result:

```text
mode: file
apply: True
scanned markdown files: 1
ok: 1
projected_stats_update: 1
autogen_registry_rebuild: 1
autogen_report_noop ------ auto-generated/-ag-memory-coverage.md unchanged
```

The validator updated `project-level/-auto-completion-stats.md` and rebuilt `tools/validator.ini`. The memory coverage report row for this item remains semantically unchanged.

## Leases

- Initial lease attempt from the wrong working directory was rejected as `File not found`.
- Lease acquired from `source-3/project-documentation`:

> Executable block R002 was removed from this report and preserved verbatim in [0002BE-UiAssetModeRectWriteHelper-current-no-owner-research-removed.md](0002BE-UiAssetModeRectWriteHelper-current-no-owner-research-removed.md). The archived block is non-authoritative and must not be executed.

Result: `Success`.

- Lease released after validation:

> Executable block R003 was removed from this report and preserved verbatim in [0002BE-UiAssetModeRectWriteHelper-current-no-owner-research-removed.md](0002BE-UiAssetModeRectWriteHelper-current-no-owner-research-removed.md). The archived block is non-authoritative and must not be executed.

Result: `Success`.

## Changed Files

Files changed by this pass:

- `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md`
- `tools/leaser/Agents/Agent-B002/research/0002BE-UiAssetModeRectWriteHelper-current-no-owner-research.md`
- `project-level/-auto-completion-stats.md` through validator `--apply`
- `tools/validator.ini` through validator `--apply`

Observed shared generated/report files are dirty in the worktree, including `auto-generated/-ag-memory-coverage.md` and `by-memory/-coverage-report.md`; this pass did not directly edit `by-memory/-coverage-report.md`, and validator output reported `auto-generated/-ag-memory-coverage.md unchanged`.

## Confidence

Recommendation confidence: high for no owner/emitter change and no C++ entry. The helper behavior and boundaries are well supported by IDA and PE evidence, but no defensible source owner or generated-source route is present. The correct state is reconstructable documentation with `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, and no emitted code until new caller/table/source evidence appears.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002BE-UiAssetModeRectWriteHelper-current-no-owner-research.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002BE"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002BE-UiAssetModeRectWriteHelper-current-no-owner-research-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0002BE-UiAssetModeRectWriteHelper-current-no-owner-research.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002BE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
