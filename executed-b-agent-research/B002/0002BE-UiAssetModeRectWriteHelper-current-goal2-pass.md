** TARGET-REPORT-UID:0002BE **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BE UiAssetModeRectWriteHelper Ownership / Split Research

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](../../../../../by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank reconstruction C++.
- Final disposition: reconstructable source-authored raw helper with no proven owner or emitter route.
- Required action: no target edit, no split, no merge, no reclassification, no IDA repair, and no `by-memory/-coverage-report.md` replacement required. The exact unchanged coverage row is included below for supervisor reference.
- Confidence: high for the no-owner/non-emitting decision; the blocker is missing source-use evidence, not missing obvious local research.

## Supporting Research

## Target
- Target UID: `0002BE`
- Target path: `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md`
- Source queue/report row: current `auto-generated/-ag-memory-coverage.md` still lists the target as reconstructable `no-owner`, canonical owner `NONE`, and blank emitters.
- Current supervisor classification: prior supervisor notes mark the earlier 2026-06-13 B001/B002 passes complete-or-reclassified, but the current user assignment requested a fresh Goal 2 no-owner memory recheck.
- Current scores and parent state: `87/91`, parent aggregate [UID:00022Z][0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers](../../../../../by-memory/0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md) is a `RECONSTRUCTABLE:FALSE` split inventory, not a source owner.

## Executive Recommendation
- Leave the target no-owner and non-emitting. The helper is real project UI code, but no direct caller, pointer, table, vtable slot, class field, singleton path, resource literal, or source-file route proves where it should be emitted.
- Do not attach it to `MapNamePane`, `MiniMapButtonPane`, `MiniMap`, `MainMenuPane`, `StartupWindow`, `RectGeometryHelpers`, or a new helper source file on the current evidence.
- Do not enter C++ code. The active 90/90+ code-entry gate is not met because the item is `87/91` and has no owner/emitter route.
- The condition needed to change this result is a recovered caller/table/callback/vtable/reference path to `0x005030c0`, or equivalent source/debug evidence that proves a source-use context.

## Supervisor Active Recheck
- Supervisor/user instruction: recheck `[UID:0002BE] by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` from current docs and live IDA MCP, using the prior B002 report only as background.
- Split repair: not required. The target is already an exact `0x44` / 68-byte helper body with padding before and after; no separable source-bearing child exists inside it.
- Source-bearing children in scope: only `0002BE`. It is already documented as reconstructable and remains blocked only on owner/emitter evidence.

## Inference Research Guidance Check
- `by-structure.md` separates `CANONICAL_OWNER` from `EMITTER_UIDS`; plausible ownership is not enough to fill either field.
- The same rules allow `RECONSTRUCTABLE:TRUE` with no owner and no emitters when NexusTK source code is real but the source placement is not proven.
- `inference_research.md` warns that address adjacency and shared globals are weak evidence unless xrefs, constructors, vtables, shared local/static state, or source metadata reinforce them. That directly affects the MapName and `g_useEpfAssets` leads here.
- Existing documentation was treated as evidence to verify, not authority. Live IDA and raw PE scans confirmed the current docs' negative ownership evidence.

## Evidence Standards Used
- Evidence used: IDA MCP `idb_list`, `server_health`, `lookup_funcs`, `entity_query`, `xref_query`, `get_bytes`, `search_text`, `make_signature_for_range`, local raw PE reference scanning, local `int_convert.py`, current by-memory/by-class/by-file/by-global docs, generated memory coverage, and supervisor notes.
- Evidence strength: strong for range, behavior, unreferenced status, and lack of vtable/table/call refs. Not strong enough for owner assignment because all positive owner candidates are semantic or adjacency based.

## IDA MCP Facts
- Session: `b001_0003gy`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, IDB `NexusTK.exe.i64`, imagebase `0x00400000`, auto-analysis ready, Hex-Rays ready.
- Function/range facts: `lookup_funcs` reports `0x005030c0`, `0x00503104`, and sibling raw starts `0x00503060` and `0x00503110` as not functions. Neighbor functions remain `sub_502E30` at `0x00502e30` size `0x22c`, `sub_5031F0` at `0x005031f0` size `0xd3`, `sub_5032D0`, `sub_503350`, `sub_5034A0`, `sub_503580`, `sub_503650`, `sub_5036A0`, `sub_503840`, and `sub_503900`.
- Data/table/padding facts: `get_bytes` confirms four `0xcc` bytes before `0002BD`, four `0xcc` bytes between `0002BD` and `0002BE`, twelve `0xcc` bytes after `0002BE`, and the next raw helper at `0x00503110`.
- Target byte facts: target bytes begin `55 8b ec 83 6d 08 01 75 37 80 3d 97 da 66 00 01`, call `sub_4B7C50` at `0x005030e0` and `0x005030f8`, return with `retn 8` at `0x005030e9` and `0x00503101`, and end at `0x00503104`.
- Signature facts: exact `0x005030c0-0x00503104` signature is unique; wildcarded-operand range signature is also unique.
- Xref facts: `xref_query` reports zero xrefs to `0x00503060`, `0x005030c0`, and `0x00503110`.
- Positive controls: IDA sees two calls to `0x005031f0` from `0x004f8051` and `0x004f8695`, a call to `0x00503580` from `0x004f80c2`, vtable data refs to `0x00503350` at `0x0061e5f8`, `0x005034a0` at `0x0061e610`, `0x00503650` at `0x0061e680`, and `0x005036a0` at `0x0061e68c`.
- Vtable/global/type facts: MapName vtable heads `0x0061e5b4`, `0x0061e600`, and `0x0061e630` have normal constructor/destructor/scalar-destructor store refs; MiniMapButton vtable heads `0x0061e63c`, `0x0061e688`, and `0x0061e6b8` have normal constructor/cleanup/destructor store refs. None contains or references `0x005030c0`.
- Search facts: `byte_66DA97` appears in this cluster at `0x00503079` and `0x005030c9`, plus MapName-side uses at `0x00503279` and `0x0050335e`. `220h` hits occur at `0x00503196` and MapName lifecycle/destructor sites, not in `0002BE`. `sub_4B7C50` hits inside `0002BE` are `0x005030e0` and `0x005030f8`.
- Numeric facts: local `int_convert.py` confirms `0xa6 = 166`, `0xad = 173`, `0x10 = 16`, and `0x44 = 68`.
- Negative IDA facts: no function object, no IDA xrefs, no vtable/table refs, no `this + 0x220`, no singleton access, no class-private field access, and no source-use context for `0x005030c0`.

## Raw PE Facts
- Raw PE scan parsed `.text`, `.rdata`, `.data`, and `.rsrc` from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- The scan found no absolute VA refs, RVA refs, `E8/E9` refs, `0F 8x` near conditional refs, or short branch refs to `0x00503060`, `0x005030c0`, or `0x00503110`.
- Positive controls were found: calls to `0x005031f0` from `0x004f8051` and `0x004f8695`, call to `0x00503580` from `0x004f80c2`, vtable slots to `0x00503350`, `0x005034a0`, `0x00503650`, `0x005036a0`, `0x00503840`, and `0x00503900`.
- Nearby vtable dump `0x0061e5b4-0x0061e6c0` contains normal MapName/MiniMapButton entries and no slot equal to `0x005030c0`.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00503060-0x005031e1` | [UID:00022Z][UnreferencedUiResourceTextHelpers](../../../../../by-memory/0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md) | Raw helper split inventory | `FALSE` | `NONE` | `86/90` | Valid non-emitting container |
| `0x00503060-0x005030bc` | [UID:0002BD][UiAssetModeRectVirtualDispatchHelper](../../../../../by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md) | Sibling rectangle virtual-dispatch helper | `TRUE` | `NONE` | `87/91` | No-owner/non-emitting |
| `0x005030c0-0x00503104` | [UID:0002BE][UiAssetModeRectWriteHelper](../../../../../by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) | Target rectangle output writer | `TRUE` | `NONE` | `87/91` | Keep no-owner/non-emitting |
| `0x00503110-0x005031e1` | [UID:0002BF][WideGlyphResourceTextRendererRaw](../../../../../by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md) | Sibling 9x11 glyph renderer | `TRUE` | `MapNamePane` in current coverage wording | `87/91` | Has MapName `this+0x220` evidence not shared by `0002BE` |
| `0x005031f0-0x0050395f` | [UID:0001AL][MapNameAndMiniMapButtonPanes](../../../../../by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md) | Interleaved MapName/MiniMapButton pane island | `FALSE` | `NONE` | `86/92` | Exact children carry source ownership |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005030c0` | `0` IDA xrefs; `0` raw PE absolute/RVA/branch refs | No direct owner/emitter evidence for target |
| `0x00503060` | `0` IDA xrefs; `0` raw PE refs | Sibling rectangle helper has same unresolved reachability problem |
| `0x00503110` | `0` IDA xrefs; `0` raw PE refs | Sibling glyph helper has better semantic field evidence, but still no live caller |
| `0x005031f0` | Calls from `0x004f8051`, `0x004f8695` | Positive control for MapNamePane constructor reachability |
| `0x00503350` | Vtable slot `0x0061e5f8` | Positive control for MapNamePane render slot |
| `0x005034a0` | Vtable slot `0x0061e610` | Positive control for MapNamePane update slot |
| `0x00503580` | Call from `0x004f80c2` | Positive control for MiniMapButtonPane constructor reachability |
| `0x00503650`, `0x005036a0` | Vtable slots `0x0061e680`, `0x0061e68c` | Positive controls for MiniMapButtonPane methods |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion: target page, parent aggregate `00022Z`, sibling `0002BD`, adjacent `0001AL`, MapNamePane class/file docs, MiniMap docs, vtable data pages, `g_useEpfAssets`, and `RectGeometryHelpers`.
- Existing docs confirmed by IDA: no function object at the target, no direct xrefs, no raw pointer/branch refs, exact bytes and padding, unique signatures, `sub_4B7C50` rectangle writes, and nearby MapName/MiniMapButton positive controls.
- Existing docs treated as association, not proof: MapName width `0xad` / 173, address adjacency to the MapName/MiniMap island, and shared `g_useEpfAssets` usage.
- Generated/coverage report state: generated memory coverage still lists `0002BE` as no-owner with blank emitters, and manual coverage already has the correct no-owner row.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS`
- Evidence for: no caller, no IDA xref, no PE absolute/RVA/branch ref, no nearby vtable slot, no class field, no singleton access, no pointer table, and no source metadata route.
- Evidence against: the helper is coherent project UI code and its width constants strongly resemble MapName layout values.
- Decision: keep. This is the most accurate current state because behavior is reconstructable but source placement is not.

### 2. `MapNamePane` / `MapNamePane.cpp`
- Evidence for: `0xad` equals 173, matching MapNamePane's documented map-name width clamp; the helper is address-adjacent to MapNamePane; `g_useEpfAssets` is also used by MapNamePane constructor/render code.
- Evidence against: no call or table to `0x005030c0`; no MapName vtable slot points to it; no `this` register or `this+0x220` field access appears in `0002BE`; MapName's real methods and vtable slots are already visible as positive controls.
- Decision: reject for assignment. MapName is the best forced semantic guess, but it is below the direct-owner threshold.

### 3. `MiniMapButtonPane` / `MiniMap`
- Evidence for: address adjacency to the interleaved MapName/MiniMapButton island and shared UI/resource layout domain.
- Evidence against: MiniMapButton constructor and vtable slots are visible, but none reference `0x005030c0`; no `MMAPBUT.EPF`, singleton, or class-local field evidence appears in the target.
- Decision: reject.

### 4. `StartupWindow` / `g_useEpfAssets`
- Evidence for: target reads `byte_66DA97`, whose by-global page now routes upward to `StartupWindow` as the only observed writer.
- Evidence against: `g_useEpfAssets` has 366 xrefs across 248 functions and is a process-wide mode selector. A read by this helper is dependency evidence, not ownership or an emitter route.
- Decision: reject.

### 5. `RectGeometryHelpers` / `RectBounds`
- Evidence for: target calls `sub_4B7C50` twice to write `RectBounds(0,0,0xa6/0xad,0x10)`.
- Evidence against: `sub_4B7C50` is a generic rectangle initializer dependency. It does not own the UI asset-mode branch or source placement of this wrapper.
- Decision: reject.

### 6. `MainMenuLoginAndAccountDialogs` or new UI helper file
- Evidence for: the raw helper cluster sits after main-menu/login/account dialog code and before MapName/MiniMapButton code; a retained UI helper source file is possible in principle.
- Evidence against: no caller cluster, table, source path, static-local data, resource string, or object-file boundary proves a standalone file or a MainMenu source owner. Creating a new file would be speculative.
- Decision: reject for now.

### Proposed New File/Grouping, If Applicable
- Proposed owner/name/path: none recommended.
- Likely full contents: not applicable. The only plausible group would be the three raw helpers in `00022Z`, but the parent is already modeled as a non-emitting by-memory split inventory and has no source-use proof.
- Candidate related items rejected: `0002BD` and `0002BF` remain related by adjacency and helper style, but `0002BF` has MapName field evidence that cannot be transferred to `0002BE`.
- Standalone, narrow, or broad source-file inference: no new file should be created without caller/table/source evidence.

## Negative Evidence Summary
- Checked and rejected direct owner signals: function object, IDA xrefs, raw absolute VA refs, RVA refs, `E8/E9` calls/jumps, `0F 8x` near conditional branches, short branches, nearby vtable slots, class-field usage, singleton usage, resource-literal usage, and direct source-file breadcrumbs.
- Consumer/global evidence is insufficient: `g_useEpfAssets` is a broad read dependency, and `sub_4B7C50` is a generic callee.
- Adjacency evidence is insufficient: the target is near MapName/MiniMap code, but the adjacent real methods have clear calls/vtable slots while `0002BE` does not.
- Sibling evidence is not transferable: `0002BF` has `this+0x220` MapName font storage evidence; `0002BE` has no equivalent class-private access.

## Final Recommendation
- Exact changes applied or recommended: no by-* changes applied or recommended.
- Exact parent assignments applied or recommended: none. Keep `CANONICAL_OWNER:NONE`.
- Exact items left no-owner/non-emitting and why: `0002BE` remains reconstructable no-owner/non-emitting because no source-use route is proven.
- Exact future work outside this assignment: only revisit if a caller, pointer table, callback registration, vtable repair, debug/source metadata, or runtime trace reveals a reference to `0x005030c0`.

Current target metadata should remain:

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

No `by-memory/-coverage-report.md` replacement is required. If the supervisor wants an explicit unchanged row/block, keep this exact row:

```text
        - [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) 0x005030c0-0x00503104 | raw function | UiAssetModeRectWriteHelper : reconstructable : 87% : strong : A001 Batch310 and B001 second-pass confirm no function object/xrefs/raw pointer hits/section-aware PE-level references/nearby table evidence, exact bytes, unique exact-range and wildcarded-entry signatures, two retn 8 exits at 0x005030e9 and 0x00503101, optional EPF/legacy RectBounds(0,0,0xa6/0xad,0x10) writes through sub_4B7C50 with int_convert-verified extents 166/173/16, output-preserving non-1 state, MapName-width association without direct ownership, and `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS` because no caller/table/source-use emitter route is proven.
```

Current generated memory-coverage row should also remain unchanged:

```text
| [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` |  |
```

## Follow-Up Actions
- Supervisor actions: no coverage-report application required unless the supervisor wants to refresh wording; keep the current row above if unchanged text is desired.
- A-agent actions: do not emit C++ or assign an owner without new caller/table/source evidence.
- B002 future research actions: none for this target unless new evidence appears; a separate runtime/callback investigation could be useful project-wide but is outside this single-target pass.

## Confidence
- Recommendation confidence: high.
- Score confidence: keep `87/91`; do not raise because owner, emitter, source-facing names, and live reachability remain unresolved.
- Remaining uncertainty: whether the helper is stale retained code, indirectly reachable through a currently invisible callback mechanism, or source-associated with MapName in a way the stripped binary no longer exposes.

## Validator Results
- Commands run: no validator command was run.
- Results: not applicable.
- Any unresolved validator warnings/errors: none from this pass.
- Reason: no by-* documentation was edited, no split was performed, and no validator-owned generated state needed refresh. No dry-run validator was used.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B002/research/0002BE-UiAssetModeRectWriteHelper-current-goal2-pass.md`
- Modified: none outside this report.
- Renamed: none.
- Moved to executed: none.
- Leases: none acquired; no leased-scope by-* files were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002BE-UiAssetModeRectWriteHelper-current-goal2-pass.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002BE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
