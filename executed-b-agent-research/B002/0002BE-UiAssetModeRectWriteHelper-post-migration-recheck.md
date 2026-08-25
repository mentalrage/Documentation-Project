** TARGET-REPORT-UID:0002BE **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BE - UiAssetModeRectWriteHelper Post-Migration Recheck

## Final Recommendation

Keep [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](../../../../../by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) unchanged:

| Field | Recommendation |
| --- | --- |
| `COMPLETION` | `87` |
| `CONFIDENCE` | `91` |
| `CANONICAL_OWNER` | `NONE` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | blank |
| `EMITTER_POSITION_OPTIONAL` | blank |
| `RECONSTRUCTION_CPP` | blank |

The helper is source-authored project code, not compiler/runtime residue, but it still has no proven source owner or emitter route. Fresh live IDA MCP and independent PE scans found no IDA function object, no xrefs, no absolute-VA/RVA pointer, no direct call/jump/conditional branch target, and no MapName/MiniMapButton vtable slot to `0x005030c0`. Under the current owner/emitter split this is a valid reconstructable no-owner/non-emitting state: `RECONSTRUCTABLE:TRUE` records the recoverable helper behavior, while blank `EMITTER_UIDS` prevents source output where no source placement is proven.

No split, merge, parent repair, IDA repair, by-memory metadata edit, or `by-memory/-coverage-report.md` edit is recommended. The active 90/90+ code-entry gate is not met because completion remains `87`, the owner/emitter route is absent, and source placement is not verified.

## Scope And Prior Material Reviewed

| Item | Finding |
| --- | --- |
| Target page | Current metadata is already `87/91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank C++. |
| Prior B001 original report | Useful historical evidence, but pre-migration ownership fields are superseded. |
| Prior B002 post-migration report | Correctly kept no-owner/non-emitting; this recheck independently reran live evidence. |
| Prior B001 second-pass report | Correctly distinguished `0002BE` from `0002BF`; this recheck verified the distinction against current docs and IDA. |
| Parent [UID:00022Z] | Remains a non-emitting split inventory over the three raw helpers at `0x00503060`, `0x005030c0`, and `0x00503110`. |
| Adjacent [UID:0002BF] | Now routes to `MapNamePane` because it uniquely uses the `this+0x220` font field owned by the MapNamePane constructor/destructor. That evidence does not exist for `0002BE`. |

## Behavior Summary

`0x005030c0-0x00503104` is a raw IDA-missed helper with a normal prologue and two `retn 8` exits. It decrements its first stack argument. If the adjusted state is not zero, it returns without writing the output rectangle. If the state is zero, it reads `byte_66DA97` / `g_useEpfAssets` and writes one of two `RectBounds` values through caller-supplied argument 2:

| Branch | Output bounds |
| --- | --- |
| `g_useEpfAssets == 1` | `(0, 0, 0xa6, 0x10)` = `(0, 0, 166, 16)` |
| else | `(0, 0, 0xad, 0x10)` = `(0, 0, 173, 16)` |

The write is performed by `sub_4B7C50`, documented by [UID:00015S][RectGeometryHelpers](../../../../../by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md) as the four-field `RectBounds` initializer. The `0xa6/0xad` pair is useful map-name sizing evidence, but it is not a resource id, pointer, vtable slot, caller, or source-owner proof.

## Live IDA MCP Evidence

Session: `b001_0003gy`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, imagebase `0x00400000`, auto-analysis ready, Hex-Rays ready.

| Query | Result |
| --- | --- |
| `lookup_funcs` at `0x005030c0`, `0x00503104` | `Not a function` for the target start/end. |
| `lookup_funcs` at sibling raw starts | `0x00503060`, `0x005030bc`, `0x00503110`, `0x005031e1` are also not functions. |
| Neighbor functions | `sub_502E30` at `0x00502e30` size `0x22c`; `sub_5031F0` at `0x005031f0` size `0xd3`; `sub_5032D0`, `sub_503350`, `sub_5034A0`, and `sub_503580` all remain modeled normally. |
| `xrefs_to 0x005030c0` | `0` xrefs. |
| `xrefs_to 0x00503060`, `0x00503110` | `0` xrefs to both sibling raw starts. |
| Positive controls | `0x005031f0` has two constructor calls; `0x00503350` and `0x005034a0` have vtable data refs; `0x00503580` has one constructor call. |
| Vtable heads | `0x0061e5b4`, `0x0061e600`, `0x0061e630`, `0x0061e63c`, `0x0061e688`, and `0x0061e6b8` have normal constructor/destructor store xrefs, but none point to `0x005030c0`. |
| Scoped `byte_66DA97` search | Hits only at `0x00503079` in `0002BD` and `0x005030c9` in `0002BE` within `0x00503000-0x00503200`. |
| Scoped `+220h` search | Hits at `0x00503196`, `0x005032a9`, `0x005032f5`, and `0x00503326`; this is the `0002BF`/MapNamePane font-field evidence, not `0002BE` evidence. |
| Signatures | Exact-range and wildcarded-entry signatures for `0x005030c0-0x00503104` are unique. |
| Numeric check | `0xa6 = 166`, `0xad = 173`, `0x10 = 16`, and range length `0x44 = 68`. |

Current raw byte window confirms the target body and boundaries: `0x005030bc-0x005030c0` is padding, the target starts with `55 8b ec 83 6d 08 01`, calls `sub_4B7C50` in both asset-mode branches, returns with `c2 08 00`, and `0x00503104-0x00503110` is padding before `0002BF`.

## Independent PE/Raw Evidence

I scanned `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` directly, parsed `.text`, `.rdata`, `.data`, and `.rsrc`, and searched all bytes for target absolute VAs, RVAs, executable relative `E8/E9` calls/jumps, `0F 8x` near conditional branches, and short conditional/unconditional branches. I also dumped the nearby MapName/MiniMapButton vtable region `0x0061e5b4-0x0061e6c0`.

| Target | Absolute VA refs | RVA refs | Direct branch/call refs | Nearby vtable slot |
| --- | ---: | ---: | ---: | --- |
| `0x00503060` | 0 | 0 | 0 | none |
| `0x005030c0` | 0 | 0 | 0 | none |
| `0x00503110` | 0 | 0 | 0 | none |
| `0x005031f0` | 0 | 0 | 2 calls | not a vtable slot |
| `0x00503350` | 1 at `0x0061e5f8` | 0 | 0 | MapName render slot |
| `0x005034a0` | 1 at `0x0061e610` | 0 | 0 | MapName update slot |
| `0x00503580` | 0 | 0 | 1 call | not a vtable slot |

Positive controls prove the scan can see real local references: it found calls from `0x004f8051` and `0x004f8695` to `0x005031f0`, a call from `0x004f80c2` to `0x00503580`, and vtable slots for `0x00503350` and `0x005034a0`. It did not find any comparable pointer, call, branch, or vtable evidence for `0x005030c0`.

## Ownership And Emitter Decision

| Candidate | Decision | Evidence |
| --- | --- | --- |
| `CANONICAL_OWNER:NONE` | Keep | No direct semantic owner is proven. The helper is source-like executable code, but the original class/file/function owner is not recoverable from current references. |
| `EMITTER_UIDS:` blank | Keep | No source-use context or output file is proven. For executable helper code, emitters require a credible source placement, not just behavioral similarity. |
| `MapNamePane` / `MapNamePane.cpp` | Reject for `0002BE` | The `0xad` width matches MapName sizing and the helper sits before MapName code, but there is no caller, vtable slot, pointer, `this+field`, or MapName-private data access. The `0002BF` `this+0x220` route cannot be copied here. |
| `MiniMapButtonPane` / `MiniMap.cpp` | Reject | No MiniMapButton caller, vtable entry, singleton access, resource string, or class-field evidence references this helper. |
| `MainMenuLoginAndAccountDialogs` | Reject | Address adjacency to earlier UI/dialog code is weaker than the padding boundary and lack of references. |
| `RectBounds` / `RectGeometryHelpers` | Reject as owner | `sub_4B7C50` is a dependency called by the helper. It does not own this UI-specific width-selection wrapper. |
| `StartupWindow` / `g_useEpfAssets` | Reject as emitter | `byte_66DA97` is a broad process-wide mode selector with 366 IDA xrefs. Reading it does not make this helper a StartupWindow source item. |
| New helper source file | Reject for now | There is no table, caller cluster, symbol, or source breadcrumb proving a standalone source unit. |

Blank `EMITTER_UIDS` is not an invalid dead state here. Multiple emitters are appropriate for pooled literals or shared constants when multiple source-use sites are proven. This target is a function-shaped executable helper. Without a proven caller, table, class field, vtable slot, or source file route, emitting the helper through any owner would make source placement less accurate.

## Split / Reclassification / Repair Decision

| Question | Decision |
| --- | --- |
| Split target further? | No. The exact body is a single 68-byte helper with internal branches but no separable child source items. |
| Merge into parent `00022Z`? | No. The parent is correctly a non-emitting split inventory; the exact child keeps behavior and metadata. |
| Attach to adjacent `MapNameAndMiniMapButtonPanes`? | No. That aggregate explicitly interleaves MapNamePane and MiniMapButtonPane and warns not to absorb this prior raw-helper cluster without caller/vtable evidence. |
| Reclassify as compiler/runtime residue? | No. The body is a coherent project UI helper that writes `RectBounds` through a project callee and uses a project global. It is not padding or compiler support. |
| IDA repair needed? | No required repair for documentation routing. Defining an IDA function at `0x005030c0` might improve local disassembly/decompilation, but it would not create ownership, reachability, or emitter evidence. |
| Parent/source repair needed? | No. Current parent and adjacent docs already express the correct caveat. |

## Exact Metadata And Coverage Recommendations

No metadata edit is required. The target header should remain:

```text
*** UID:0002BE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No `by-memory/-coverage-report.md` replacement is required. The current row is already accurate and should remain:

```text
- [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) 0x005030c0-0x00503104 | raw function | UiAssetModeRectWriteHelper : reconstructable : 87% : strong : A001 Batch310 and B001 second-pass confirm no function object/xrefs/raw pointer hits/section-aware PE-level references/nearby table evidence, exact bytes, unique exact-range and wildcarded-entry signatures, two retn 8 exits at 0x005030e9 and 0x00503101, optional EPF/legacy RectBounds(0,0,0xa6/0xad,0x10) writes through sub_4B7C50 with int_convert-verified extents 166/173/16, output-preserving non-1 state, MapName-width association without direct ownership, and `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS` because no caller/table/source-use emitter route is proven.
```

The generated memory-coverage row is also already correct:

```text
| [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` |  |
```

## Validation / Commands Performed

No by-* files were edited, so no validator run was required. I did not use dry-run validator or memory-range modes.

Evidence commands/results recorded:

| Command family | Result |
| --- | --- |
| `Get-Content` / `rg` on target, parent, prior B001/B002 reports, MapName/MiniMap/Button/RectBounds/global docs | Current docs support the no-owner/non-emitting state and isolate `0002BF`'s MapName evidence from `0002BE`. |
| IDA MCP `idb_list` / `server_health` | Active session `b001_0003gy`; NexusTK executable ready. |
| IDA MCP `lookup_funcs` | Target and sibling raw starts are not functions; adjacent modeled functions are intact. |
| IDA MCP `xrefs_to` | `0` xrefs to `0x005030c0`; positive control refs exist for adjacent MapName/MiniMap functions and vtable heads. |
| IDA MCP `entity_query` | Local function inventory excludes the raw helper cluster and includes the adjacent MapName/MiniMapButton functions. |
| IDA MCP `get_bytes` | Confirms exact raw bytes, padding, two branch returns, and sibling boundaries. |
| IDA MCP `search_text` | Confirms `byte_66DA97` use in `0002BE`; confirms `+220h` field evidence belongs to `0002BF`/MapNamePane, not `0002BE`. |
| IDA MCP `make_signature_for_range` | Exact and wildcarded signatures for `0x005030c0-0x00503104` are unique. |
| IDA MCP `int_convert` | Confirms `0xa6=166`, `0xad=173`, `0x10=16`, `0x44=68`. |
| Inline PE scanner over `NexusTK.exe` | Found no VA/RVA/direct-branch/vtable evidence for `0x005030c0`; positive controls found adjacent calls and vtable entries. |

## Changed Files

Only this report was created:

```text
tools/leaser/Agents/Agent-B002/research/0002BE-UiAssetModeRectWriteHelper-post-migration-recheck.md
```

## Open Risks / Blockers

The remaining blocker is external evidence, not an unsearched obvious lead. To route this helper, the project would need at least one of:

- a recovered caller, table entry, callback list, or function pointer to `0x005030c0`;
- a class-private field or `this`-relative access tying the helper to a direct class owner;
- source-output evidence placing this exact helper in a file;
- a verified IDA-side repair that reveals cross-references hidden by current analysis.

Absent that evidence, keeping `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS` is the most accurate owner/emitter result.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002BE-UiAssetModeRectWriteHelper-post-migration-recheck.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002BE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
