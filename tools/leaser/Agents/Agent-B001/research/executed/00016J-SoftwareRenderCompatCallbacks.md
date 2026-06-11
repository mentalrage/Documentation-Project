# 00016J SoftwareRenderCompatCallbacks Ownership / Split Research

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](../../../by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md) as a parent-blank, non-emitting by-memory inventory; assign every exact source-bearing callback child to [UID:0000OC][Surface](../../../by-file/Surface.md).
- Final disposition: aggregate repaired from `84/88`, `RECONSTRUCTABLE:TRUE` to `88/90`, `RECONSTRUCTABLE:FALSE`, `AUTOGEN_PARENT_UID:` blank. All twelve exact children now clear the strict child gate and attach to Surface `88/85`.
- Required action: supervisor review only. Split pages and parent-gate decisions are final; no Supervisor_notes edit and no move to executed.
- Confidence: high for split/parent disposition; medium-high for final original public names and typedefs.

## Supporting Research

## Target
- Target UID: `00016J`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md`
- Source queue/report row: B001 supervisor assignment B001-029, status `reviewed-no-85-under-review`.
- Current scores and parent state after repair: aggregate `88/90`, `RECONSTRUCTABLE:FALSE`, parent blank; exact children `0002PF` through `0002YJ` are source-bearing and assigned to `0000OC`.

## Executive Recommendation
- Best direct owner for source-bearing children: [UID:0000OC][Surface](../../../by-file/Surface.md), because the functions are callback-table implementations selected by the surface initializer and invoked through global render slots, not ordinary feature-pane methods.
- Aggregate handling: keep `00016J` parent blank as a non-emitting inventory to avoid duplicate source generation over the same address range.
- Remaining condition before any future change: only final source naming/typedef work remains. No ownership blocker remains for the exact children.

## Supervisor Active Recheck
- Supervisor assigned exactly B001-029 and instructed split-first research, parent-gate verification, Surface-related child recheck, IDA MCP evidence, validators, and a final report.
- The aggregate was already split into twelve exact child pages before this replacement pass; final audit found no missing source-bearing range.
- Repaired below-gate/unassigned tail children `0002TE`, `0002YF`, and `0002YJ`; resolved the prior Surface-vs-SoftwareBlend16 ambiguity for `0002YG`, `0002YH`, and `0002YI`; preserved the first six Surface assignments after metadata recheck.

## Inference Research Guidance Check
- `by-structure.md` required exact child pages to carry source-bearing documentation and required both child and direct parent to clear `85/85` before assignment.
- `inference_research.md` supported choosing the best defensible source owner from initializer xrefs, callback-table ownership, caller/callee patterns, and negative evidence instead of leaving items blank for lack of original source filenames.
- Existing generated `RankingEventListPane` names were treated as uncertain callsite-biased artifacts. Existing SoftwareBlend16 ownership was checked but scoped to stateless helpers, not callback-table targets.

## Evidence Standards Used
- IDA MCP evidence used: `idb_meta`, `lookup_funcs`, `callers`, `callees`, `xrefs_to`, `analyze_funcs`, and decompilation observations.
- Documentation evidence used: `Surface.md`, `SoftwareBlend16.md`, `SurfaceRenderCallbackTable` global/by-memory docs, SurfacePresentation docs, the target aggregate, all twelve child pages, and generated memory coverage.
- Negative evidence used: no direct callers for callback target addresses, no callees for the three RGB555 leaf slots and `0x004bee40`, no ranking-specific direct call ownership, and no proof that SoftwareBlend16 owns callback slots.

## IDA MCP Facts
- Active IDB: `NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- Function/range facts: `sub_4BE0E0` size `0x58e`, `sub_4BE680` size `0x6e7`, `sub_4BED80` size `0x2a`, `sub_4BEDB0` size `0x2e`, `sub_4BEDE0` size `0x55`, and `sub_4BEE40` size `0x185e`; aggregate end `0x004c069e` is not a function.
- Xref facts: tail target refs are initializer/data refs at `0x00558bbc`, `0x00558bc6`, `0x00558bda`, `0x00558be4`, `0x00558bd0`, and `0x00558bee`, paired with raw setup refs near `0x005586f9-0x0055872f`.
- Callee facts: `0x004be0e0` and `0x004be680` call rect/clip/palette helpers and security-cookie glue; `0x004bed80`, `0x004bedb0`, `0x004bede0`, and `0x004bee40` have no callees.
- Decompilation facts: `0x004be0e0` is a clipped packed-bitmask RGB555 write/blend callback; `0x004be680` is a clipped fill/blend callback; the three leaf callbacks expand/pack/transform RGB555 channels; `0x004bee40` clamps a mode to `0..24` and performs in-place RGB555 block transforms over `a2 >> 1` words.
- Data/table/padding facts: local alignment/switch islands remain modeled as generated control-flow data, including the final jump table after `0x004c069e` recorded in `-ignored`.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Before | Final Direct Parent | Final Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004bb8d0-0x004c069e` | `00016J` aggregate | callback-family inventory | `84/88`, true, blank | blank | `88/90`, false | non-emitting inventory |
| `0x004bb8d0-0x004bb9a5` | `0002PF` pixel | slot `69B3E0` | `86/88`, `0000OC` | `0000OC` | `86/88` | rechecked assigned |
| `0x004bb9b0-0x004bc08a` | `0002PG` line | slot `69B3E4` | `86/89`, `0000OC` | `0000OC` | `86/89` | rechecked assigned |
| `0x004bc090-0x004bd3e8` | `0002PH` sprite blit | slot `69B3E8` | `85/88`, `0000OC` | `0000OC` | `85/88` | rechecked assigned |
| `0x004bd420-0x004bdca9` | `0002TB` RLE fill | slot `69B3EC` | `85/88`, `0000OC` | `0000OC` | `85/88` | rechecked assigned |
| `0x004bdcc0-0x004bdf3e` | `0002TC` scaled RLE tint | slot `69B3F0` | `86/89`, `0000OC` | `0000OC` | `86/89` | rechecked assigned |
| `0x004bdf40-0x004be0db` | `0002TD` alpha lookup blit | slot `69B3F4` | `85/89`, `0000OC` | `0000OC` | `85/89` | rechecked assigned |
| `0x004be0e0-0x004be66e` | `0002TE` bitmask blit | slot `69B3F8` | `82/88`, blank | `0000OC` | `85/88` | repaired assigned |
| `0x004be680-0x004bed67` | `0002YF` fill | slot `69B3FC` | `82/88`, blank | `0000OC` | `85/88` | repaired assigned |
| `0x004bed80-0x004bedaa` | `0002YG` RGB555 expand | slot `69B400` | `86/90`, blank | `0000OC` | `86/90` | assignment repaired |
| `0x004bedb0-0x004bedde` | `0002YH` RGB555 pack | slot `69B404` | `86/90`, blank | `0000OC` | `86/90` | assignment repaired |
| `0x004bede0-0x004bee35` | `0002YI` palette transform | slot `69B408` | `86/90`, blank | `0000OC` | `86/90` | assignment repaired |
| `0x004bee40-0x004c069e` | `0002YJ` block transform | slot `69B40C` | `78/86`, blank | `0000OC` | `85/88` | repaired assigned |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004be0e0` | refs `0x0055872f`, `0x00558bbc`; no callers | Surface initializer callback target for `dword_69B3F8`. |
| `0x004be680` | refs `0x00558723`, `0x00558bc6`; no callers | Surface initializer callback target for `dword_69B3FC`. |
| `0x004bed80` | refs `0x00558710`, `0x00558bda`; no callers/callees | Surface callback slot `dword_69B400`, not ordinary SoftwareBlend16 call graph. |
| `0x004bedb0` | refs `0x00558705`, `0x00558be4`; no callers/callees | Surface callback slot `dword_69B404`. |
| `0x004bede0` | refs `0x0055871e`, `0x00558bd0`; no callers/callees | Surface callback slot `dword_69B408` using alpha lookup roots. |
| `0x004bee40` | refs `0x005586f9`, `0x00558bee`; no callers/callees | Surface callback slot `dword_69B40C`, large in-place transform body. |

## Documentation Evidence And IDA Status
- Supporting docs: `Surface.md` is `88/85` and documents the render callback table, SurfacePresentation initializer, broad callback-slot users, and all twelve exact compat child pages after this pass.
- Supporting docs: `SoftwareBlend16.md` is `86/88` but states broader callback families live nearby and are not owned there as simple math helpers.
- Generated state after validation: `auto-generated/-ag-memory-coverage.md` rows `842-853` show `0002PF` through `0002YJ` assigned to `0000OC`; row `2138` shows `00016J` as `not_reconstructable`.
- Stale docs repaired: `0002TE`, `0002YF`, and `0002YJ` now clear the gate; `0002YG`, `0002YH`, and `0002YI` now have final Surface parent assignments; `00016J` now records non-emitting aggregate disposition.

## Ranked Ownership Analysis

### 1. Surface / `NexusTK/render/Surface.cpp`
- Evidence for: direct parent clears `88/85`; callback targets have only initializer/table refs; callback slots are process-wide render dispatch state; bodies use Surface/GrafPort receiver, clip, pitch, palette, and render-mode state; generated coverage now routes all exact children to `auto-generated/NexusTK/render/Surface.cpp`.
- Evidence against: final original source filename could have been a narrower software-render callback file, but no current by-file parent models that more exactly at `85/85`.
- Decision: accepted as best existing direct parent.

### 2. SoftwareBlend16
- Evidence for: several leaf functions perform compact RGB555 math, and the broader callback bodies consume RGB555/RGB565 masks and blend helpers.
- Evidence against: `SoftwareBlend16.md` scopes itself to stateless helpers called by render callbacks and explicitly excludes the larger callback families from direct ownership. The leaf functions in question are callback-table targets with no direct callers.
- Decision: rejected as direct parent for this target. Keep as related helper/mask math owner where its exact children are ordinary helper calls.

### 3. RankingEventListPane / RankingDialog
- Evidence for: generated output historically emitted several callback markers under RankingEventListPane names.
- Evidence against: IDA shows no direct ranking callers for the callback targets; target refs come from surface initializer/table setup; callback slots are used broadly by render/presentation paths.
- Decision: rejected as callsite-biased recovery artifact.

### Proposed new file/grouping
- Proposed owner/name/path: no new by-file owner created in this pass. A future narrower name like `SoftwareRenderCallbacks.cpp` could be justified if the project later models all 555/565 callback families under a dedicated render file.
- Likely full contents if created later: `00016J`, `00016L`, `SurfaceRenderCallbackTable`, alpha lookup roots, mask constants, and selected callback-slot initializer logic.
- Decision: not needed for B001-029 because `Surface` already clears the gate and matches current project documentation patterns.

## Negative Evidence Summary
- No direct code callers were found for tail callback targets; consumer slot refs prove dispatch breadth but not a feature-pane owner.
- No vtable/class evidence ties these functions to RankingEventListPane.
- No call graph ties the three leaf RGB555 callbacks to SoftwareBlend16 as ordinary helpers; their target-address refs are callback-table installs.
- The aggregate itself should not emit source because all source-bearing functions are already represented by exact children.

## Final Recommendation
- Exact changes applied: repaired `00016J`, `0002TE`, `0002YF`, `0002YG`, `0002YH`, `0002YI`, `0002YJ`, and `Surface.md`.
- Exact parent assignments applied: all twelve exact children `0002PF` through `0002YJ` are assigned to `0000OC`.
- Exact items left unassigned: only `00016J`, intentionally parent blank because it is `RECONSTRUCTABLE:FALSE` aggregate inventory.
- Exact future work outside scope: final C++ typedef/public-name cleanup and possible future narrower render-callback source-file modeling.

## Follow-Up Actions
- Supervisor actions: review B001-029; do not require more child creation unless a later source-name audit wants a narrower by-file parent.
- A-agent actions: none required for parent gates; future A-agents can improve public names/signatures on exact child pages.
- B001 future research actions: optional future review of RGB565 family `00016L` for parallel aggregate disposition.

## Confidence
- Recommendation confidence: high. Surface is the best existing direct parent and clears the gate.
- Score confidence: high for assignment scores, moderate-high for `0002YJ` because final 24-mode names remain unresolved but the IDA behavior/ownership evidence is sufficient for `85/88`.
- Remaining uncertainty: original source file name, exact callback typedef names, and final branch names for the largest transform callback.

## Validator Results
- Commands run: normal targeted scans using `python .\tools\validator.py --mode file --file <path> --apply` from `E:\NTK\GhidraBridge\source-3\project-documentation`.
- Files scanned: aggregate `00016J`, all twelve exact children `0002PF`, `0002PG`, `0002PH`, `0002TB`, `0002TC`, `0002TD`, `0002TE`, `0002YF`, `0002YG`, `0002YH`, `0002YI`, `0002YJ`, and `by-file\Surface.md`.
- Results: command batch completed with exit code `0`; each file-mode scan reported `ok: 1`. Aggregate scan reported `completion_update 00016J ... 88`, `confidence_update 00016J ... 90`, and `autogen_registry_update 00016J ... true -> false`. After a final historical-wording cleanup in `0002TE`, `python .\tools\validator.py --mode file --file 'by-memory\0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback.md' --apply` was rerun and reported `ok: 1`.
- Generated coverage check: rows `842-853` in `auto-generated/-ag-memory-coverage.md` show all twelve children assigned to `0000OC`; row `2138` shows the aggregate `00016J` as `not_reconstructable`.
- Unresolved validator warnings/errors: none observed for the targeted scans.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B001/research/00016J-SoftwareRenderCompatCallbacks.md`.
- Modified by-* docs: `by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md`; `by-memory/0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback.md`; `by-memory/0x004be680-0x004bed67.SoftwareRenderCompatFillCallback.md`; `by-memory/0x004bed80-0x004bedaa.SoftwareRenderCompatRgb555ExpandCallback.md`; `by-memory/0x004bedb0-0x004bedde.SoftwareRenderCompatRgb555PackCallback.md`; `by-memory/0x004bede0-0x004bee35.SoftwareRenderCompatRgb555PaletteTransformCallback.md`; `by-memory/0x004bee40-0x004c069e.SoftwareRenderCompatBlockTransferCallback.md`; `by-file/Surface.md`.
- Validator-derived updates: `auto-generated/-ag-memory-coverage.md` and validator registry state were refreshed by the normal validator commands.
- Renamed: none.
- Moved to executed: none.
