** TARGET-REPORT-UID:0003JI **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003JI **
# Final Recommendation

Keep [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](../../../../../by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) unchanged:

- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000L3,0000PB`
- `EMITTER_POSITION_OPTIONAL:` blank
- `RECONSTRUCTION_CPP CODE` blank
- Scores unchanged at `COMPLETION:87`, `CONFIDENCE:93`

This target is a source-declared/generated-binary UTF-16 `WM2` string literal whose storage is pooled across two proven source-use contexts. Fresh live IDA MCP evidence on 2026-06-14 shows exactly two direct references to `0x0061ea48`: MapPane packet/world-map helper `sub_511DB0` at `0x00512263`, and WorldMapPane special-region helper `sub_5C5200` at `0x005c5219`. Neither side proves a single source declaration owner. The correct current model is therefore no canonical owner with both file-root emitters, so future method reconstruction can emit use-site `L"WM2"` literals in `MapPane.cpp` and `WorldMapPane.cpp` without inventing a standalone shared constant.

No by-memory, by-file, generated coverage, or `by-memory/-coverage-report.md` edits are recommended. No split, merge, reclassification, new child page, or IDA repair is justified.

## Target And Scope

- Assignment: Agent-B003 live Goal 2 B-agent no-owner memory pass.
- Target UID: `0003JI`
- Target page: `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md`
- Current generated state: `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000L3,0000PB`, `RECONSTRUCTABLE:TRUE`.
- Prior B001 report was read as evidence only; this pass rechecked current documentation and live IDA MCP facts directly.
- Active rule applied: pooled or shared source literals may remain `CANONICAL_OWNER:NONE` while retaining multiple `EMITTER_UIDS` when source-use emitters are proven and no single declaration owner is defensible.

## Current Documentation Context

The target page already describes `0x0061ea48-0x0061ea50` as exact UTF-16 `WM2` string data with no canonical owner and emitters `0000L3,0000PB`.

[UID:0003IX][0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings](../../../../../by-memory/0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings.md) is a non-emitting split index. Its exact children are:

| Range | UID | Current route |
| --- | --- | --- |
| `0x0061ea24-0x0061ea30` | `0003JG` | shared `.PAL`, `CANONICAL_OWNER:NONE`, emitters `0000L3,0000PB` |
| `0x0061ea30-0x0061ea48` | `0003JH` | MapPane-only `wm`, `WM`, `wm2`, owner/emitter `0000L3` |
| `0x0061ea48-0x0061ea50` | `0003JI` | shared `WM2`, no owner, emitters `0000L3,0000PB` |
| `0x0061ea50-0x0061ea70` | `0003JJ` | MapPane-only `wm3`, `WM3`, `wm4`, `WM4`, owner/emitter `0000L3` |

[UID:0000L3][MapPane](../../../../../by-file/MapPane.md) is a valid file-root emitter with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`. It documents `sub_511DB0` as part of MapPane packet/world-map handling and records the surrounding MapPane-only resource-string children.

[UID:0000PB][WorldMapPane](../../../../../by-file/WorldMapPane.md) is a valid file-root emitter with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`. It documents WorldMapPane as a separate `map/WorldMapPane.cpp` source module, not a MapPane subrange.

## Live IDA MCP Evidence

IDA MCP session used for this pass:

- Session: `a001_goal2_class_batch`
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- Auto-analysis ready: `true`
- Hex-Rays ready: `true`

Byte and string checks:

- `get_bytes(0x0061ea24, 0x4c)` returned the contiguous UTF-16 sequence `.PAL`, `wm`, `WM`, `wm2`, `WM2`, `wm3`, `WM3`, `wm4`, `WM4`.
- `get_string` decoded `0x0061ea48` as `WM2`.
- Target bytes are `57 00 4d 00 32 00 00 00`, exactly `WM2\0` as UTF-16LE.
- `find_bytes("57 00 4D 00 32 00 00 00")` returned one match: `0x61ea48`.
- `find_bytes("77 00 6D 00 32 00 00 00")` returned one match for the lowercase sibling `wm2`: `0x61ea40`.

Direct xrefs:

| Address | Xrefs found |
| --- | --- |
| `0x0061ea48` | `0x00512263` in `sub_511DB0`; `0x005c5219` in `sub_5C5200` |
| `0x0061ea4a` | none |
| `0x0061ea4c` | none |
| `0x0061ea4e` | none |

Surrounding xrefs confirm the existing split:

- `.PAL` at `0x0061ea24` has refs from MapPane helper `sub_510960` and WorldMapPane constructor-family function `sub_5C2AC0`.
- `wm`, `WM`, and `wm2` at `0x0061ea30`, `0x0061ea38`, and `0x0061ea40` each have one ref, all inside `sub_511DB0`.
- `WM2` at `0x0061ea48` has two refs, one in `sub_511DB0` and one in `sub_5C5200`.
- `wm3`, `WM3`, `wm4`, and `WM4` at `0x0061ea50`, `0x0061ea58`, `0x0061ea60`, and `0x0061ea68` each have one ref, all inside `sub_511DB0`.
- The successor `0x0061ea70` decodes as `%s\Mscfg.dll` and has separate refs outside this child.

Function and instruction checks:

- `lookup_funcs(0x00511db0)` reports `sub_511DB0`, size `0xa8a`.
- `lookup_funcs(0x005c5200)` reports `sub_5C5200`, size `0x1d0`.
- `xref_query(0x00511db0, direction=to)` reports one code caller: `0x00508307` in MapPane packet dispatcher `sub_507C90`.
- `decompile(0x00507c90)` shows packet case `0x2E` returning `sub_511DB0(v3)` at `0x0050830c`.
- `insn_query(0x00512180-0x00512380)` shows `0x00512263: mov ecx, offset aWm2_0; "WM2"` inside `sub_511DB0`.
- `decompile(0x00511db0)` shows the local converted `WideCharStr` compared against `L"wm"`, `L"WM"`, `L"wm2"`, `L"WM2"`, `L"wm3"`, `L"WM3"`, `L"wm4"`, and `L"WM4"`.
- `insn_query(0x005c5200-0x005c5235)` shows `0x005c5219: push offset aWm2_0; "WM2"` inside `sub_5C5200`.
- `decompile(0x005c5200)` shows the WorldMapPane helper calling `sub_5845B0(L"WM2")` in both layout branches.
- `xref_query(0x005c5200, direction=to)` reports code callers at `0x005c4955` and `0x005c4acf`, both inside `sub_5C48B0`.
- `xref_query(0x005c48b0, direction=to)` reports caller `0x005c3e2b` inside `sub_5C3950`, keeping this use within the WorldMapPane implementation range.
- `analyze_component(0x00510960,0x00511db0,0x005c2ac0,0x005c5200)` lists `0x61ea48 aWm2_0` as a shared global accessed by `sub_511DB0` and `sub_5C5200`.

## Candidate Owner And Emitter Analysis

`CANONICAL_OWNER:NONE` is still the most conservative correct owner.

`MapPane` is a required emitter but not a canonical declaration owner. Its source-use ref is real, and the surrounding lower `wm`/`WM`/`wm2` plus later `wm3`/`WM3`/`wm4`/`WM4` strings are MapPane-only. But the target `WM2` has a separate material WorldMapPane ref at `0x005c5219`, so setting `CANONICAL_OWNER:0000L3` would overclaim the declaration.

`WorldMapPane` is a required emitter but not a canonical declaration owner. `sub_5C5200` uses `L"WM2"` for WorldMapPane special-region logic, and its callers remain inside the WorldMapPane executable aggregate. But MapPane packet/world-map creation code independently compares against the same literal, so setting `CANONICAL_OWNER:0000PB` would also overclaim.

The split-index parent `0003IX` is not a source owner. It is a documentation container over mixed shared and MapPane-only string literals, and it is intentionally non-reconstructable/non-emitting.

A new shared constants owner is not justified. IDA shows direct immediate references to a pooled literal, not a named global object, source-level constants table, separate file, or declaration-only owner. Creating a shared constants page would add a source shape the binary does not prove.

`sub_5845B0` and its owning utility surface should not be added as emitters. It is a callee receiving the literal pointer from WorldMapPane logic; it is not the source-use site that should emit `L"WM2"`.

The exact emitter list should remain:

| Emitter UID | File root | Proof |
| --- | --- | --- |
| `0000L3` | `NexusTK/map/MapPane.cpp` | `sub_507C90` packet case `0x2E` calls `sub_511DB0`; `sub_511DB0` compares `WideCharStr` against `L"WM2"` using the direct ref at `0x00512263`. |
| `0000PB` | `NexusTK/map/WorldMapPane.cpp` | `sub_5C5200` calls `sub_5845B0(L"WM2")` using the direct ref at `0x005c5219`; callers stay in the WorldMapPane draw/helper chain. |

No additional emitter is supported, and removing either current emitter would drop a proven source-use route.

## Reconstructable No-Owner Defense

`RECONSTRUCTABLE:TRUE` is correct even with `CANONICAL_OWNER:NONE`.

The source-level requirement is not to hand-port a standalone data object at `0x0061ea48`. The requirement is to preserve the behavior of two original source-use sites that both reference the text `WM2`. A normal C++ rebuild can express this as `L"WM2"` in the relevant MapPane and WorldMapPane methods, and the compiler/linker can pool or duplicate the final read-only bytes.

Under the current documentation model, `CANONICAL_OWNER` answers "who owns the semantic declaration?" and `EMITTER_UIDS` answers "which source roots need this item to surface during reconstruction?" For this target, no semantic declaration owner is proven, but both source-use emitters are proven. That makes `CANONICAL_OWNER:NONE` with nonblank `EMITTER_UIDS:0000L3,0000PB` the correct output-emission model, not an unresolved dead end.

The blank `RECONSTRUCTION_CPP CODE` block is also correct. Adding a standalone `static const wchar_t[]` or shared constant would invent a declaration owner and would be worse than emitting use-site literals when the owning methods are rewritten.

## Rejected Alternatives

- Assign to `MapPane`: rejected because WorldMapPane independently references the exact same `WM2` storage.
- Assign to `WorldMapPane`: rejected because MapPane independently references the exact same `WM2` storage.
- Assign to parent `MapWorldPaletteResourceStrings`: rejected because that page is a mixed split index, not an original source declaration owner.
- Create a new shared constants child/page: rejected because there is no IDA evidence for a named shared object or constants module.
- Split the target: rejected because the target is one complete UTF-16 `WM2\0` literal and interior addresses `0x0061ea4a`, `0x0061ea4c`, and `0x0061ea4e` have no direct xrefs.
- Merge with predecessor or successor: rejected because predecessor and successor are MapPane-only sibling groups, while this exact literal is shared.
- Reclassify non-reconstructable: rejected because both source-use sites need the `WM2` literal behavior in the rebuilt source.
- Add `sub_5845B0` or utility file as an emitter: rejected because it is a callee utility, not the source-use owner for the literal.
- Add final C++ now: rejected because a standalone declaration would overfit the binary storage instead of the source-use evidence.

## Exact Recommended Changes

No shared documentation changes are recommended.

Target metadata should remain exactly:

```text
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3,0000PB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No replacement row is needed for `by-memory/-coverage-report.md`. The current row's substantive state is still correct: exact UTF-16 `WM2`, no canonical owner, emitters `0000L3,0000PB`, no split/merge/reclassification.

If the tracker needs a close-out status, use:

```text
| `0003JI` | 0x0061ea48-0x0061ea50.SharedWorldMap2UpperString | `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` | Agent-B003 | 2026-06-14 | complete-no-change | `Agent-B003/research/0003JI-SharedWorldMap2UpperString-live-goal2-no-owner-pass.md` |
```

Do not edit `by-memory/-coverage-report.md` for this pass.

## Validation Needs

- Leases: none acquired, because this pass only creates an Agent-B003 research report and does not edit any shared by-* page.
- Validator: not run, because no by-* documentation, validator-managed metadata, or generated coverage file was changed.
- Dry runs: none used.
- IDA MCP checks used read-only inspection tools only.
- Future validation during method reconstruction should verify that MapPane and WorldMapPane method rewrites each retain the `L"WM2"` source-use where the decompiled logic currently uses it.

## Confidence

Recommendation confidence: high.

The byte range, decoded text, exact xrefs, adjacent split boundaries, MapPane emitter, and WorldMapPane emitter were all rechecked in the live IDA session. The remaining uncertainty is only source-shape uncertainty typical of pooled literals: the binary does not prove whether the original compiler pooled two independent use-site literals or a shared named constant. That uncertainty argues against choosing a canonical owner and supports the current no-owner/multiple-emitter route.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003JI","source_path":"executed-b-agent-research/B003/0003JI-SharedWorldMap2UpperString-live-goal2-no-owner-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
