** TARGET-REPORT-UID:000118 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000118 ButtonChoiceControlCore Ownership / Split Research

## Finalized Report / Current Recommendation

- Current recommendation: UID `000118` should remain `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS`, but it is now correctly `RECONSTRUCTABLE:FALSE` as a non-emitting mixed coverage/index aggregate.
- Final disposition: split repair completed. Four new exact child pages now carry the previously unresolved raw source-bearing helper islands; existing exact Selection and RadioGroup children remain valid.
- Required action: supervisor should update `by-memory/-coverage-report.md` manually using the exact rows in this report. Do not assign or emit source from UID `000118`.
- Confidence: high for the split/ownership decision; remaining uncertainty is limited to final source-level helper names and eventual final C++ reconstruction, not to owner routing.

## Supporting Research

## Target

- Target UID: `000118`
- Target path: `by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md`
- Source queue/report row: `auto-generated/-ag-memory-coverage.md`
- Tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, row for `000118`
- Current post-repair metadata: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`

## Executive Recommendation

UID `000118` is not a source-emitting item. It is a corrected aggregate/index over a dense ButtonChoice control band. The source-bearing raw islands that previously blocked final disposition are now split into exact child pages:

| UID | Child path | Range | Direct owner | Emitters | Score |
| --- | --- | --- | --- | --- | --- |
| `0003N8` | `by-memory/0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md` | `0x00495010-0x0049503d` | `00001E` ButtonControlPane | `00001E` | `85/86` |
| `0003NA` | `by-memory/0x004955e0-0x00495615.TextButtonExControlPaneRawTeardown.md` | `0x004955e0-0x00495615` | `0000EK` TextButtonExControlPane | `0000EK` | `86/89` |
| `0003NC` | `by-memory/0x00495aa0-0x00495be2.TextButtonExControlPaneLabelBoundsRawHelpers.md` | `0x00495aa0-0x00495be2` | `0000EK` TextButtonExControlPane | `0000EK` | `85/87` |
| `0003NB` | `by-memory/0x00497890-0x00497c59.SliderControlPaneRawTailHelpers.md` | `0x00497890-0x00497c59` | `0000DB` SliderControlPane | `0000DB` | `86/88` |

Existing child pages remain part of the completed split picture:

- `00011D`, `0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh`, owned/emitted by `0000CR` SelectionControlPane.
- `00011E`, `0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers`, owned/emitted by `0000BI` RadioGroupControlPane.

The broad aggregate should not gain a canonical owner or emitters. Exact children route through their direct class owners, and those classes route to the established source-family file `0000HY` `ButtonControlPane.cpp`.

## Supervisor Active Recheck

The supervisor rejected the first report because it only recommended splitting. This pass performed the split/child repair directly:

- Created four exact by-memory child pages.
- Researched and scored each child to at least `85/85`.
- Assigned each child only where the direct class parent already cleared `85/85`.
- Updated the aggregate target to a non-reconstructable, non-emitting index.
- Ran normal validator file-mode `--apply` on each child and the aggregate. No dry-run validator or memory-range validator mode was used.

Every source-bearing raw helper island previously identified in UID `000118` is now either an exact child page or an already existing exact child page.

## Inference Research Guidance Check

`by-structure.md` and `inference_research.md` drove three decisions:

- Direct-owner rule: child pages attach to class owners (`ButtonControlPane`, `TextButtonExControlPane`, `SliderControlPane`, etc.), not to the broad memory aggregate.
- Split-first rule: the aggregate could not be finalized until raw source-bearing bodies were split and researched.
- Container rule: after the child split, UID `000118` is a mixed aggregate/index rather than a source body, so `RECONSTRUCTABLE:FALSE` is the correct final classification.

Existing documentation was treated as evidence, not authority. Older Wave2/FittingRoom labels around `0x00495010`, `0x00495450`, `0x00495aa0`, and `0x00495b60` were rejected as owner pollution where live IDA evidence showed generic control-family behavior.

## Evidence Standards Used

Evidence used:

- MCP `server_health` and `idb_list` for active IDB/session.
- MCP `lookup_funcs` for raw-start function/non-function status and modeled neighbors.
- MCP `search_text` scoped to raw ranges for readable raw disassembly heads.
- MCP `get_bytes` and `make_signature_for_range` for exact byte ranges and unique signatures.
- MCP `xrefs_to` for helper-start no-xref status and internal slider call evidence.
- MCP `decompile` / `analyze_batch` for surrounding constructors, vtable writes, mouse/timer/process helpers, and owner signals.
- Existing by-class/by-file pages for direct parent score gates.
- Existing exact child pages `00011D` and `00011E`.

The evidence is strong enough for ownership and emitter routing because each created child is bounded by exact bytes, class-local fields, adjacent modeled methods, vtable or call-graph context, and a direct parent that clears `85/85`.

## IDA MCP Facts

Session facts:

- Database/session: `b001_0003lq`
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- Image base: `0x400000`
- Auto-analysis and Hex-Rays: ready

Function/range facts:

- `lookup_funcs` reports `0x00495010`, `0x004955e0`, `0x00495aa0`, `0x00495b60`, `0x00497890`, `0x00497aa0`, and `0x00497c30` as `Not a function`.
- Modeled neighbors are present: `0x00495040` size `0xef`, `0x00495620` size `0x12c`, `0x00495bf0` size `0xb5`, and `0x00497c60` size `0x10b`.
- `0x0049803a-0x00498040` remains six `0xcc` bytes before PopupMenu successor `0x00498040`.

Xref facts:

- No xrefs to helper starts `0x00495010`, `0x004955e0`, `0x00495aa0`, `0x00495b60`, `0x00497890`, `0x00497aa0`, or `0x00497c30`.
- `0x00497c60` has three xrefs: modeled `OnMouse` at `0x004976e6`, modeled `OnTimer` at `0x0049786b`, and raw child call at `0x00497bff`.

Vtable facts:

- `0x004955e0` writes TextButtonEx vtables through xrefs to `0x00617d24`, `0x00617d90`, and `0x00617dc0`; the same vtable triplet is written by constructor `0x00495450` and scalar deleting destructor `0x0049b860`.
- Slider vtable triplet `0x00617f14`, `0x00617f7c`, and `0x00617fac` is installed by constructor `0x00496630`, matching the slider raw tail island before `0x00497c60`.

Negative facts:

- The created raw child starts are not IDA functions and have no direct inbound xrefs, so their C++ remains blank.
- PopupMenu begins after the corrected endpoint and does not own any UID `000118` child.
- ProgressBar and ControlPane state-helper pages are adjacent/predecessor pages, not owners for this range.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00495010-0x0049503d` | `0003N8` / `ButtonControlPaneActiveRefreshHelper` | Base button active/selected refresh raw helper | `TRUE` | `00001E` | `85/86` | Created, assigned, emits via class |
| `0x004955e0-0x00495615` | `0003NA` / `TextButtonExControlPaneRawTeardown` | TextButtonEx raw ordinary teardown | `TRUE` | `0000EK` | `86/89` | Created, assigned, emits via class |
| `0x00495aa0-0x00495be2` | `0003NC` / `TextButtonExControlPaneLabelBoundsRawHelpers` | Two raw label-bounds helpers | `TRUE` | `0000EK` | `85/87` | Created, assigned, emits via class |
| `0x004964a0-0x0049662f` | `00011E` / `RadioGroupControlPaneOptionHelpers` | Radio option helper/table island | `TRUE` | `0000BI` | `85/88` | Existing, assigned |
| `0x00497890-0x00497c59` | `0003NB` / `SliderControlPaneRawTailHelpers` | Slider rectangle/drag/repeat/cancel raw helpers | `TRUE` | `0000DB` | `86/88` | Created, assigned, emits via class |
| `0x00495cb0-0x00495cc9` | `00011D` / `SelectionControlPaneSetSelectionAndRefresh` | Exact selection setter | `TRUE` | `0000CR` | `85/90` | Existing, assigned |
| `0x00494eb0-0x0049803a` | `000118` / `ButtonChoiceControlCore` | Mixed ButtonChoice aggregate index | `FALSE` | `NONE` | `86/90` | Updated as non-emitting index |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00495010` | no xrefs | Raw helper is source-bearing but not directly reached as an IDA function start. |
| `0x004955e0` | no xrefs | Raw teardown body is identified by vtable writes and lifecycle pairing, not start xrefs. |
| `0x00495aa0`, `0x00495b60` | no xrefs | Label-bounds helpers are raw local helper bodies; final reachability remains unknown. |
| `0x00497890`, `0x00497aa0`, `0x00497c30` | no xrefs | Slider raw helper starts are not modeled as entrypoints. |
| `0x00497bff -> 0x00497c60` | raw internal call | Proves the `0x00497aa0` body is tied to modeled Slider input processing. |
| `0x004976e6 -> 0x00497c60` | modeled OnMouse caller | Slider mouse path uses the same process helper. |
| `0x0049786b -> 0x00497c60` | modeled OnTimer caller | Slider repeat timer path uses the same process helper. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- `by-file/ButtonControlPane.md` (`0000HY`) is `86/88` and documents the generic button/choice-control source family.
- `by-class/ButtonControlPane.md` (`00001E`) is `85/88` and owns the base button control methods.
- `by-class/TextButtonExControlPane.md` (`0000EK`) is `86/86` and documents the text-provider child at `+0x10c`, constructor, raw teardown, and destructor evidence.
- `by-class/SliderControlPane.md` (`0000DB`) is `86/86` and documents the slider constructor, vtable triplet, mouse/key/timer/process helper behavior.
- Existing child `00011E` already resolves the raw RadioGroup option island.
- Existing child `00011D` already resolves the exact Selection helper.

Existing docs that were stale or incomplete:

- The original target page listed unresolved raw gaps. It is now repaired and points to exact child pages.
- `by-memory/-coverage-report.md` still has the old row saying UID `000118` is reconstructable `84%`; it must be updated by the supervisor.
- Older Wave2 names that implied fitting-room owners were rejected where live IDA and current control-family docs prove generic control ownership.

Generated/coverage report state:

- Validator regenerated `auto-generated/-ag-memory-coverage.md`.
- New generated rows show `0003N8`, `0003NA`, `0003NC`, and `0003NB` as `emits`.
- UID `000118` now appears as `not_reconstructable` in `auto-generated/-ag-memory-coverage.md`.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` for UID `000118`

Evidence for:

- It spans multiple direct class owners.
- Exact raw source-bearing children now exist and route to direct class owners.
- A broad aggregate cannot be the narrow semantic owner under the owner/emitter model.

Evidence against:

- The best source-family file is clearly `0000HY` ButtonControlPane, but that is a file-family route, not a direct owner for this mixed aggregate.

Decision:

- Accepted. Keep UID `000118` no-owner/non-emitting and `RECONSTRUCTABLE:FALSE`.

### 2. Exact class owners for child pages

Evidence for:

- `0003N8` uses base button fields and is bounded by ButtonControlPane methods.
- `0003NA` writes TextButtonEx vtables and releases the TextButtonEx provider child.
- `0003NC` uses TextButtonEx provider/bounds behavior and sits in the TextButtonEx band.
- `0003NB` uses Slider fields and the Slider mouse/timer/process helper call graph.

Evidence against:

- Raw starts lack direct xrefs, so final C++ is not emitted.

Decision:

- Accepted. All four created children are assigned and routed through their direct class pages.

### 3. `0000HY` ButtonControlPane file as direct owner for UID `000118`

Evidence for:

- It is the best source-family file for the whole button/choice-control module.

Evidence against:

- Direct-owner rules prefer exact class children. Assigning the aggregate to the file would duplicate child routes and hide mixed ownership.

Decision:

- Rejected for UID `000118`; retained as source-family context through the class owners.

### 4. Rejected adjacent/source candidates

- `ControlPane` (`0000IG`): base-control file, not direct owner of derived button/choice behavior.
- `ProgressBarControlPane` (`0000MT`): predecessor/exclusion, passive progress control.
- `PopupMenuControls` (`0000MN`): successor begins at `0x00498040`.
- `TextButtonControlPane` file (`0000OK`): owns plain text-button subset only, not TextButtonEx/Slider/Radio aggregate.

## Negative Evidence Summary

- No direct xrefs to raw helper starts means no final C++ should be emitted from the child pages yet.
- Consumer/caller context does not prove feature ownership. Feature-polluted Wave2 labels were rejected in favor of vtables, fields, and local control-family behavior.
- Address adjacency alone does not prove ownership: ProgressBar and PopupMenu are adjacent but excluded by boundary and behavior.
- Shared offset `+0x10c` is not a universal field. Each child uses it in class-local context: TextButtonEx provider child, Selection selected value, Radio selected index, etc.

## Final Recommendation

Exact changes applied:

- Created `by-memory/0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md`.
- Created `by-memory/0x004955e0-0x00495615.TextButtonExControlPaneRawTeardown.md`.
- Created `by-memory/0x00495aa0-0x00495be2.TextButtonExControlPaneLabelBoundsRawHelpers.md`.
- Created `by-memory/0x00497890-0x00497c59.SliderControlPaneRawTailHelpers.md`.
- Updated `by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md` to `86/90`, `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitters, and child links.

Exact parent assignments applied:

- `0003N8 -> 00001E`, emits to `00001E`.
- `0003NA -> 0000EK`, emits to `0000EK`.
- `0003NC -> 0000EK`, emits to `0000EK`.
- `0003NB -> 0000DB`, emits to `0000DB`.

Items left no-owner/non-emitting:

- UID `000118` only, because it is a mixed aggregate/container after child split.

Future work outside this assignment:

- Final C++ reconstruction for the children remains blocked by source-quality class layouts, field names, and helper names. That is not an ownership blocker.

## Coverage Row Guidance

Do not edit `by-memory/-coverage-report.md` directly. The supervisor should replace the existing UID `000118` row at the current ButtonChoice location, immediately after the `0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers` row, with this row:

```text
    - [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md) 0x00494eb0-0x0049803a | aggregate index | ButtonChoiceControlCore : not_reconstructable : 86% : very strong : B003-000118 split repair completed; broad Button/TextButtonEx/ImageButton/Selection/RadioGroup/Slider range is now a parent-blank non-emitting coverage index, not a source body. Exact source-bearing raw children [UID:0003N8][0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper](by-memory/0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md), [UID:0003NA][0x004955e0-0x00495615.TextButtonExControlPaneRawTeardown](by-memory/0x004955e0-0x00495615.TextButtonExControlPaneRawTeardown.md), [UID:0003NC][0x00495aa0-0x00495be2.TextButtonExControlPaneLabelBoundsRawHelpers](by-memory/0x00495aa0-0x00495be2.TextButtonExControlPaneLabelBoundsRawHelpers.md), existing [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md), and [UID:0003NB][0x00497890-0x00497c59.SliderControlPaneRawTailHelpers](by-memory/0x00497890-0x00497c59.SliderControlPaneRawTailHelpers.md) carry reconstructable owner/emitter routing; endpoint padding and PopupMenu successor remain confirmed.
```

Insert these new child rows immediately after the replacement UID `000118` aggregate row:

```text
        - [UID:0003N8][0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper](by-memory/0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md) 0x00495010-0x0049503d | raw helper | ButtonControlPaneActiveRefreshHelper : reconstructable : 85% : strong : B003 split child; no IDA function object or helper-start xrefs, unique MCP signature, checks `this+0x101`/`this+0x108`, calls `sub_4B9660(1)`, clears `this+0x70`, refreshes bounds at `this+0x44`, and routes to [UID:00001E][ButtonControlPane](by-class/ButtonControlPane.md).
        - [UID:0003NA][0x004955e0-0x00495615.TextButtonExControlPaneRawTeardown](by-memory/0x004955e0-0x00495615.TextButtonExControlPaneRawTeardown.md) 0x004955e0-0x00495615 | raw teardown | TextButtonExControlPaneRawTeardown : reconstructable : 86% : strong : B003 split child; no IDA function object or helper-start xrefs, unique MCP signature, writes TextButtonEx vtables `0x00617d24/0x00617d90/0x00617dc0`, releases provider child at `+0x10c`, jumps to `sub_544580`, and routes to [UID:0000EK][TextButtonExControlPane](by-class/TextButtonExControlPane.md).
        - [UID:0003NC][0x00495aa0-0x00495be2.TextButtonExControlPaneLabelBoundsRawHelpers](by-memory/0x00495aa0-0x00495be2.TextButtonExControlPaneLabelBoundsRawHelpers.md) 0x00495aa0-0x00495be2 | raw helper island | TextButtonExControlPaneLabelBoundsRawHelpers : reconstructable : 85% : strong : B003 split child; two raw non-function label-bounds helpers at `0x00495aa0-0x00495b50` and `0x00495b60-0x00495be2`, no helper-start xrefs, unique MCP signatures, provider/supplied text measurement through `sub_58E380`/`sub_4BAA70`, bounds fetch `sub_4B8E00`, clamp `sub_4B7CC0`, and routes to [UID:0000EK][TextButtonExControlPane](by-class/TextButtonExControlPane.md).
        - [UID:0003NB][0x00497890-0x00497c59.SliderControlPaneRawTailHelpers](by-memory/0x00497890-0x00497c59.SliderControlPaneRawTailHelpers.md) 0x00497890-0x00497c59 | raw helper island | SliderControlPaneRawTailHelpers : reconstructable : 86% : strong : B003 split child; three raw non-function SliderControlPane helpers for part-rectangle, drag/repeat, and cancel/reset behavior, no helper-start xrefs, unique MCP signatures, internal call `0x00497bff -> 0x00497c60`, timer calls `sub_5975E0`/`sub_597600`, active part byte `+0x2f0`, drag rectangle `+0x2f4`, and routes to [UID:0000DB][SliderControlPane](by-class/SliderControlPane.md).
```

`auto-generated/-ag-memory-coverage.md` already reflects the applied validator state:

```text
| [UID:0003N8][0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper](by-memory/0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md) | emits | `00001E` | `00001E` |  | no | `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp` | `by-memory/0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md` |  |
| [UID:0003NA][0x004955e0-0x00495615.TextButtonExControlPaneRawTeardown](by-memory/0x004955e0-0x00495615.TextButtonExControlPaneRawTeardown.md) | emits | `0000EK` | `0000EK` |  | no | `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp` | `by-memory/0x004955e0-0x00495615.TextButtonExControlPaneRawTeardown.md` |  |
| [UID:0003NC][0x00495aa0-0x00495be2.TextButtonExControlPaneLabelBoundsRawHelpers](by-memory/0x00495aa0-0x00495be2.TextButtonExControlPaneLabelBoundsRawHelpers.md) | emits | `0000EK` | `0000EK` |  | no | `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp` | `by-memory/0x00495aa0-0x00495be2.TextButtonExControlPaneLabelBoundsRawHelpers.md` |  |
| [UID:0003NB][0x00497890-0x00497c59.SliderControlPaneRawTailHelpers](by-memory/0x00497890-0x00497c59.SliderControlPaneRawTailHelpers.md) | emits | `0000DB` | `0000DB` |  | no | `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp` | `by-memory/0x00497890-0x00497c59.SliderControlPaneRawTailHelpers.md` |  |
| [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md) | not_reconstructable | `NONE` |  |  | no |  | `by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md` |  |
```

## Follow-Up Actions

Supervisor actions:

- Apply the manual `by-memory/-coverage-report.md` replacement/insert rows above.
- No additional parent/source repair is needed for UID `000118`.

A-agent actions:

- Future final-C++ work should target exact class/child pages, not UID `000118`.
- Keep helper names provisional until class layouts and private field names are source-quality.

B003 future research actions:

- None for UID `000118`; the split blocker has been resolved.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for split/owner metadata; below final reconstruction because raw helper starts lack direct xrefs and final source names remain inferred.
- Remaining uncertainty: final helper names, final class field names, and whether original source used one `ButtonControlPane.cpp` or later narrower split files. These do not block the current owner/emitter disposition.

## Validator Results

Initial validator issue:

- Command: `python .\tools\validator.py --mode file --file <new child> --apply --queue-timeout 120`
- Result: the first normal file scan inserted new metadata but hit `PermissionError: [WinError 5] Access is denied` while replacing `auto-generated/-ag-memory-coverage.md`.
- Recovery: reran `--uid-only --apply` for the affected files, repaired the duplicate new-file UID header created by the interrupted run, then reran normal file-mode `--apply` after metadata edits. No dry runs were used.

Successful final validation commands:

> Executable block R001 was removed from this report and preserved verbatim in [000118-ButtonChoiceControlCore-ownership-research-removed.md](000118-ButtonChoiceControlCore-ownership-research-removed.md). The archived block is non-authoritative and must not be executed.

Successful final validation results:

- `0003N8`: `ok: 1`; completion `85`, confidence `86`, owner `NONE -> 00001E`, reconstructable `blank -> true`, emitter `00001E`.
- `0003NA`: `ok: 1`; completion `86`, confidence `89`, owner `NONE -> 0000EK`, reconstructable `blank -> true`, emitter `0000EK`.
- `0003NC`: `ok: 1`; completion `85`, confidence `87`, owner `NONE -> 0000EK`, reconstructable `blank -> true`, emitter `0000EK`.
- `0003NB`: `ok: 1`; completion `86`, confidence `88`, owner `NONE -> 0000DB`, reconstructable `blank -> true`, emitter `0000DB`.
- `000118`: `ok: 1`; completion `86`, confidence `90`, reconstructable `true -> false`, four new reverse references added.
- Validator regenerated `auto-generated/-ag-memory-coverage.md` and updated `project-level/-auto-completion-stats.md` projected path section as normal validator side effects.

## Changed Files

Created:

- `by-memory/0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md`
- `by-memory/0x004955e0-0x00495615.TextButtonExControlPaneRawTeardown.md`
- `by-memory/0x00495aa0-0x00495be2.TextButtonExControlPaneLabelBoundsRawHelpers.md`
- `by-memory/0x00497890-0x00497c59.SliderControlPaneRawTailHelpers.md`

Modified:

- `by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md`
- `tools/leaser/Agents/Agent-B003/research/000118-ButtonChoiceControlCore-ownership-research.md`

Validator side effects:

- `auto-generated/-ag-memory-coverage.md`
- `project-level/-auto-completion-stats.md`
- validator registry/autogen backup state under `tools/` as produced by normal validator `--apply`

Not modified:

- `by-memory/-coverage-report.md` was not edited directly. Exact replacement/insert rows are provided above for supervisor application.

## Blockers

No blocker remains for UID `000118` ownership/emitter disposition. Final C++ reconstruction remains future work on exact child/class pages.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/000118-ButtonChoiceControlCore-ownership-research.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:26","uid":"000118"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000118-ButtonChoiceControlCore-ownership-research-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/000118-ButtonChoiceControlCore-ownership-research.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000118"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
