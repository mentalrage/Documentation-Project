# 00016L SoftwareRenderRgb565Callbacks Ownership / Split Research

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](../../../by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md) as a parent-blank, non-emitting by-memory inventory; keep every exact source-bearing RGB565 callback child assigned to [UID:0000OC][Surface](../../../by-file/Surface.md).
- Final disposition: aggregate repaired from `84/88`, `RECONSTRUCTABLE:TRUE`, parent blank to `88/90`, `RECONSTRUCTABLE:FALSE`, parent blank. All twelve exact children now clear the strict child gate and attach to Surface `88/85`.
- Required action: supervisor review only. The by-* edits are acceptable after recovery verification; no other target was started.
- Confidence: high for split/parent disposition and Surface ownership; medium-high for final public callback names, typedefs, field names, and the largest branch/mode names.

## Supporting Research

## Target
- Target UID: `00016L`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md`
- Source queue/report row: recovery assignment `B001-033`, supervisor status `reviewed-no-85-under-review`.
- Current scores and parent state after recovery: aggregate `88/90`, `RECONSTRUCTABLE:FALSE`, parent blank; exact children `0002PI`, `0002PJ`, `0002PK`, `0002TF`, `0002TG`, `0002TH`, `0002TI`, `0002YK`, `0002YL`, `0002YM`, `0002YN`, and `0002YO` are source-bearing and assigned to `0000OC`.

## Executive Recommendation
- Best direct owner for source-bearing children: [UID:0000OC][Surface](../../../by-file/Surface.md), because IDA shows every target address is installed into the surface render callback table from the surface initializer path, has no ordinary direct code callers, and is dispatched by callback slots rather than by a feature-pane call graph.
- Aggregate handling: keep `00016L` parent blank and non-reconstructable so generated source does not duplicate exact child functions.
- Remaining condition before any future source-code promotion: final callback typedefs, parameter/field names, and large switch/mode names need a normal A-agent source-grade pass. That is not an ownership blocker.

## Supervisor Active Recheck
- Supervisor assigned exactly `B001-033 / 00016L` as a recovery-only task. I did not start any other target.
- The previous B001 worker had already edited the RGB565 by-* pages between 2026-06-10 15:29 and 15:39 local time but left only an in-progress report stub.
- Recovery inspection found no remaining by-* documentation blocker. The needed work was validation, IDA-backed verification, and replacement of the stub report with this final handoff.

## Prior Worker Change Audit

Working-tree inspection before recovery validation showed this exact prior-worker footprint:

- Modified tracked by-* docs: `by-file/Surface.md`; aggregate `by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md`; existing child pages `0002PI`, `0002PJ`, `0002PK`, `0002TF`, `0002TG`, `0002TH`, and `0002TI`.
- Created/untracked by-memory child pages: `0002YK`, `0002YL`, `0002YM`, `0002YN`, and `0002YO`.
- Created/untracked report stub: `tools/leaser/Agents/Agent-B001/research/00016L-SoftwareRenderRgb565Callbacks.md`.
- Diff summary before validator: nine tracked docs changed with 356 insertions and 54 deletions, plus the five new exact child pages.
- Main metadata changes: aggregate `00016L` became `88/90`, `RECONSTRUCTABLE:FALSE`, parent blank; existing children were raised to assignment-floor scores and assigned `AUTOGEN_PARENT_UID:0000OC`; five tail children were created and assigned to Surface; `Surface.md` now lists all RGB565 children as direct Surface callback implementations.
- Recovery worker changes after audit: no manual by-* edits. I ran targeted validator `--apply` scans and replaced only the Agent-B001 report stub.

## Inference Research Guidance Check
- `by-structure.md` requires exact source-bearing child pages to carry the reconstructable code documentation and requires both child and direct parent to clear `85/85` before assignment.
- `inference_research.md` supports selecting the best defensible source owner from initializer xrefs, callback-table ownership, caller/callee distribution, and negative evidence, without requiring impossible original-source proof.
- Existing generated `RankingEventListPane` names were treated as callsite-biased hypotheses. Existing `SoftwareBlend16` documentation was checked and rejected as direct parent scope for installed callback-table targets.

## Evidence Standards Used
- IDA MCP evidence used in recovery: `idb_meta` and `py_eval` against IDA APIs for function starts/ends, basic block counts, instruction counts, direct call xrefs, target xrefs, callback-slot xref counts, and callee sets.
- Documentation evidence used: `Surface.md`, `SoftwareBlend16.md`, `SurfaceRenderCallbackTable` by-global/by-memory pages, `SurfacePresentation`, the RGB565 aggregate, all twelve child pages, generated memory coverage, and executed `00016J` as a structure analog.
- Negative evidence used: no ordinary direct callers for any callback target, no feature-pane-only call graph, no SoftwareBlend16 direct ownership for callback-table targets, and no need for aggregate source emission.

## IDA MCP Facts
- Active IDB: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Module/base: `NexusTK.exe`, base `0x400000`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- Recovery recheck date: 2026-06-10
- All twelve exact child starts are IDA functions with the documented end addresses.
- IDA reports zero direct call xrefs to all twelve callback targets.
- Every child target has exactly two target-address refs: one raw setup-neighborhood ref and one ref from `sub_558840`.
- Callback slot xref counts match the existing documentation: `15`, `26`, `114`, `11`, `21`, `4`, `12`, `206`, `4`, `9`, `8`, and `5` for slots `dword_69B3E0` through `dword_69B40C`.

## Function / Child Inventory

| Range / Item | UID / Path | Slot / Role | Before | Final Direct Parent | Final Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004c0770-0x004c5fde` | `00016L` aggregate | RGB565 callback inventory | `84/88`, true, blank | blank | `88/90`, false | non-emitting inventory |
| `0x004c0770-0x004c0845` | `0002PI` pixel | `dword_69B3E0` | `74/84`, blank | `0000OC` | `85/86` | repaired assigned |
| `0x004c0850-0x004c0f7a` | `0002PJ` line | `dword_69B3E4` | `72/84`, blank | `0000OC` | `85/86` | repaired assigned |
| `0x004c0f80-0x004c3123` | `0002PK` sprite blit | `dword_69B3E8` | `74/84`, blank | `0000OC` | `85/86` | repaired assigned |
| `0x004c3190-0x004c3a40` | `0002TF` RLE fill | `dword_69B3EC` | `74/84`, blank | `0000OC` | `85/86` | repaired assigned |
| `0x004c3a50-0x004c3ce1` | `0002TG` scaled RLE tint | `dword_69B3F0` | `74/84`, blank | `0000OC` | `85/86` | repaired assigned |
| `0x004c3cf0-0x004c3e93` | `0002TH` alpha lookup blit | `dword_69B3F4` | `74/84`, blank | `0000OC` | `85/86` | repaired assigned |
| `0x004c3ea0-0x004c4364` | `0002TI` bitmask blit | `dword_69B3F8` | `74/84`, blank | `0000OC` | `85/86` | repaired assigned |
| `0x004c4380-0x004c46c0` | `0002YK` fill | `dword_69B3FC` | absent/unsplit | `0000OC` | `85/88` | created assigned |
| `0x004c46d0-0x004c46fa` | `0002YL` expand | `dword_69B400` | absent/unsplit | `0000OC` | `86/90` | created assigned |
| `0x004c4700-0x004c472e` | `0002YM` pack | `dword_69B404` | absent/unsplit | `0000OC` | `86/90` | created assigned |
| `0x004c4730-0x004c478a` | `0002YN` palette transform | `dword_69B408` | absent/unsplit | `0000OC` | `86/90` | created assigned |
| `0x004c4790-0x004c5fde` | `0002YO` block transfer | `dword_69B40C` | absent/unsplit | `0000OC` | `85/88` | created assigned |
| `Surface.md` | `0000OC` by-file parent | render dispatch owner | working-tree baseline `88/84`; current page also contains earlier `88/85` gate history | source root | `88/85` | clears parent gate |

## Direct Xref / Caller Inventory

| UID | IDA function | Bounds / size | Direct callers | Target refs | Slot refs | Callee summary |
| --- | --- | --- | ---: | --- | ---: | --- |
| `0002PI` | `sub_4C0770` | `0x004c0770-0x004c0845`, `0xd5` | 0 | `0x00558833`, `0x00558e9c` | 15 | clip/palette/`BlendRgb565Pixel` helpers |
| `0002PJ` | `sub_4C0850` | `0x004c0850-0x004c0f7a`, `0x72a` | 0 | `0x00558822`, `0x00558ea6` | 26 | line clip, rect/clip, palette, `BlendRgb565Pixel`, `BlendRgb565Pair` |
| `0002PK` | `sub_4C0F80` | `0x004c0f80-0x004c3123`, `0x21a3` | 0 | `0x0055882e`, `0x00558eb0` | 114 | rect/clip, palette, RGB565 helpers, memmove/security glue |
| `0002TF` | `sub_4C3190` | `0x004c3190-0x004c3a40`, `0x8b0` | 0 | `0x00558816`, `0x00558eba` | 11 | rect/clip and palette helpers |
| `0002TG` | `sub_4C3A50` | `0x004c3a50-0x004c3ce1`, `0x291` | 0 | `0x00558829`, `0x00558ec4` | 21 | clip helper and security glue |
| `0002TH` | `sub_4C3CF0` | `0x004c3cf0-0x004c3e93`, `0x1a3` | 0 | `0x005587ec`, `0x00558ece` | 4 | clip/setup/bulk alpha lookup helpers |
| `0002TI` | `sub_4C3EA0` | `0x004c3ea0-0x004c4364`, `0x4c4` | 0 | `0x0055881d`, `0x00558ed8` | 12 | rect/clip, palette, `BlendRgb565Pixel` |
| `0002YK` | `sub_4C4380` | `0x004c4380-0x004c46c0`, `0x340` | 0 | `0x00558811`, `0x00558ee2` | 206 | rect/clip, palette, `BlendRgb565Pixel`, `BlendRgb565Pair` |
| `0002YL` | `sub_4C46D0` | `0x004c46d0-0x004c46fa`, `0x2a` | 0 | `0x005587fe`, `0x00558ef6` | 4 | no callees |
| `0002YM` | `sub_4C4700` | `0x004c4700-0x004c472e`, `0x2e` | 0 | `0x005587f3`, `0x00558f00` | 9 | no callees |
| `0002YN` | `sub_4C4730` | `0x004c4730-0x004c478a`, `0x5a` | 0 | `0x0055880c`, `0x00558eec` | 8 | no callees |
| `0002YO` | `sub_4C4790` | `0x004c4790-0x004c5fde`, `0x184e` | 0 | `0x005587e7`, `0x00558f0a` | 5 | no callees |

Additional IDA shape facts from the recovery recheck:

- `sub_4C0F80` is the largest sprite/blit child in this family at 308 basic blocks and 2109 instructions.
- `sub_4C4790` is the final large block-transfer child at 214 basic blocks and 1816 instructions.
- Leaf conversion callbacks `sub_4C46D0`, `sub_4C4700`, and `sub_4C4730` each have one basic block and no callees, but their target addresses are installed as callback-table slots, so they are not ordinary SoftwareBlend16 helper callees.

## Documentation Evidence And IDA Status
- `Surface.md` is now `88/85`, has a valid `NexusTK/render/` proposed path, lists all twelve RGB565 exact children, and records the B001-033 evidence update. IDA confirms the no-direct-caller and initializer/table evidence that makes Surface the best existing direct parent.
- `SoftwareBlend16.md` is `86/88` and explicitly scopes itself to stateless RGB555/RGB565 blend/math helpers. IDA confirms several RGB565 callback children call `BlendRgb565Pixel` and `BlendRgb565Pair`, but this callee relationship supports related helper context, not callback target ownership.
- `auto-generated/-ag-memory-coverage.md` rows `855-866` now show all twelve RGB565 children assigned to `0000OC` / `auto-generated/NexusTK/render/Surface.cpp`.
- `auto-generated/-ag-memory-coverage.md` row `2151` shows aggregate `00016L` as `not_reconstructable`.
- Historical generated `RankingEventListPane` names remain documented as recovered names only. IDA contradicts using those names as direct ownership proof.

## Ranked Ownership Analysis

### 1. Surface / `NexusTK/render/Surface.cpp`
- Evidence for: Surface clears `88/85`; all exact target addresses are callback-table installs; IDA reports no ordinary direct callers; target refs are raw setup-neighborhood refs plus `sub_558840`; slot refs show broad render dispatch; bodies use GrafPort/Surface clipping, pitch/origin, palette, lookup, and render-mode state; generated coverage now routes every exact child to `auto-generated/NexusTK/render/Surface.cpp`.
- Evidence against: original source may have used a narrower software-render callback file or a shared blitter translation unit. Current docs do not model such a narrower source root at `85/85`.
- Decision: accepted as best current direct parent for the exact children.

### 2. SoftwareBlend16
- Evidence for: several RGB565 callbacks call `BlendRgb565Pixel`, `BlendRgb565Pair`, span/block helpers, or related RGB565 math helpers; the three small leaf callbacks are color conversion/math-like functions.
- Evidence against: `SoftwareBlend16.md` explicitly limits its direct-parent gate to stateless helpers and says the larger callback families are Surface/render-dispatch implementations. IDA confirms the three small leaf callbacks have no ordinary callers and are installed into callback slots `dword_69B400`, `dword_69B404`, and `dword_69B408`.
- Decision: rejected as direct parent for `00016L` children; keep as related helper/math context.

### 3. RankingEventListPane / RankingDialog
- Evidence for: generated output historically emitted several RGB565 functions with `RankingEventListPane` names.
- Evidence against: IDA finds zero direct callers from ranking code to the target starts; target references are callback-table setup references; callback slots are process-wide render dispatch state. Generated names are therefore callsite-biased recovery artifacts.
- Decision: rejected.

### 4. The aggregate `00016L` as source parent
- Evidence for: it is a useful by-memory inventory and records exact split coverage, boundary islands, and callback slot mapping.
- Evidence against: it spans twelve source-bearing functions plus local jump/alignment islands and would duplicate source if emitted. Exact children are the reconstructable units.
- Decision: keep parent blank, `RECONSTRUCTABLE:FALSE`, non-emitting inventory.

### Proposed new file/grouping
- Proposed owner/name/path: no new by-file owner is required for this recovery. A future narrower `SoftwareRenderCallbacks.cpp` or `SoftwareRender565.cpp` may be plausible if the project later models all RGB555/RGB565 callback families under a dedicated render source root.
- Likely full contents if created later: `00016J`, `00016L`, `SurfaceRenderCallbackTable`, alpha lookup root pointers, mask constants, surface initializer callback selection, and related 16-bit callback typedefs.
- Decision: not needed now because Surface already clears the gate and matches current documentation patterns.

## Negative Evidence Summary
- No direct code callers were found for any exact RGB565 callback target.
- No vtable, class method, or feature-pane caller evidence ties these functions to `RankingEventListPane` or `RankingDialog`.
- No ordinary call graph ties the three small conversion callbacks to `SoftwareBlend16`; they are table targets, not called helper functions.
- The aggregate is not a source-emitting object; reconstructable code belongs on exact child pages.
- No recovered source metadata proves the final original public callback names or typedef names, so those remain future cleanup work.

## Final Recommendation
- Exact changes accepted: prior B001 by-* edits are acceptable as-is after recovery verification.
- Exact parent assignments accepted: `0002PI`, `0002PJ`, `0002PK`, `0002TF`, `0002TG`, `0002TH`, `0002TI`, `0002YK`, `0002YL`, `0002YM`, `0002YN`, and `0002YO` assigned to `0000OC`.
- Exact items left unassigned: only `00016L`, intentionally parent blank because it is `RECONSTRUCTABLE:FALSE` aggregate inventory.
- Exact future work outside scope: source-grade callback typedef/signature cleanup, field/mode naming, and deep branch-table reconstruction for `0002PK` and `0002YO`.
- Supervisor handoff: READY FOR SUPERVISOR REVIEW.

## Follow-Up Actions
- Supervisor actions: review B001-033 and accept the recovered by-* edits if the large validator-generated coverage churn is acceptable.
- A-agent actions: future render/source cleanup can improve callback typedef names, mode names, and final reconstructed C++ on exact child pages.
- B001 future research actions: none for this recovery target.

## Confidence
- Recommendation confidence: high. Surface is the best existing direct parent and clears the gate.
- Score confidence: high for assignment-floor scores and aggregate non-emitting disposition; medium-high for final source names because typedefs and field names are still unresolved.
- Remaining uncertainty: exact original source file split, callback typedef names, parameter names, and large-body branch/mode names.

## Validator Results
- Lease status before validator: shared lease report showed no active leases. B001 then leased the aggregate, all twelve child pages, `Surface.md`, `by-memory/-coverage-report.md`, and `auto-generated/-ag-memory-coverage.md`. After validator refreshed projected stats, B001 also leased `project-level/-auto-completion-stats.md` before any further shared-doc operation.
- Commands run: from `C:\FastStorage\NTK_Sources\source-3\project-documentation`, sequential targeted scans using `python .\tools\validator.py --mode file --file <path> --apply`.
- Files scanned: aggregate `00016L`; all twelve exact children `0002PI`, `0002PJ`, `0002PK`, `0002TF`, `0002TG`, `0002TH`, `0002TI`, `0002YK`, `0002YL`, `0002YM`, `0002YN`, `0002YO`; and `by-file\Surface.md`.
- Results: validator batch completed with exit code `0`; each file-mode scan reported `ok: 1`.
- Validator-derived updates observed: `auto-generated/-ag-memory-coverage.md`, `by-memory/-coverage-report.md`, and `project-level/-auto-completion-stats.md` were refreshed by normal validator `--apply` behavior.
- Generated coverage check: rows `855-866` in `auto-generated/-ag-memory-coverage.md` show all twelve children assigned to `0000OC`; row `2151` shows `00016L` as `not_reconstructable`.
- Unresolved validator warnings/errors: none observed for the targeted scans.

## Changed Files
- Created by prior worker and accepted: `by-memory/0x004c4380-0x004c46c0.SoftwareRenderRgb565FillCallback.md`; `by-memory/0x004c46d0-0x004c46fa.SoftwareRenderRgb565ExpandCallback.md`; `by-memory/0x004c4700-0x004c472e.SoftwareRenderRgb565PackCallback.md`; `by-memory/0x004c4730-0x004c478a.SoftwareRenderRgb565PaletteTransformCallback.md`; `by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md`.
- Modified by prior worker and accepted: `by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md`; `by-memory/0x004c0770-0x004c0845.SoftwareRenderRgb565PixelCallback.md`; `by-memory/0x004c0850-0x004c0f7a.SoftwareRenderRgb565LineCallback.md`; `by-memory/0x004c0f80-0x004c3123.SoftwareRenderRgb565SpriteBlitCallback.md`; `by-memory/0x004c3190-0x004c3a40.SoftwareRenderRgb565RleFillCallback.md`; `by-memory/0x004c3a50-0x004c3ce1.SoftwareRenderRgb565ScaledRleTintCallback.md`; `by-memory/0x004c3cf0-0x004c3e93.SoftwareRenderRgb565AlphaLookupBlitCallback.md`; `by-memory/0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback.md`; `by-file/Surface.md`.
- Validator-derived updates: `auto-generated/-ag-memory-coverage.md`; `by-memory/-coverage-report.md`; `project-level/-auto-completion-stats.md`; validator registry state.
- Modified by recovery worker: `tools/leaser/Agents/Agent-B001/research/00016L-SoftwareRenderRgb565Callbacks.md`.
- Renamed: none.
- Moved to executed: none.
