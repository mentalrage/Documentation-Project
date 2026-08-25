** TARGET-REPORT-UID:0003LQ **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003LQ **
# 0003LQ TextControlSharedStateAndBorderHelpers Ownership / Split Research

## Finalized Report / Current Recommendation
- Current recommendation: repaired [UID:0003LQ] `by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md` from reconstructable no-owner/non-emitting to `CANONICAL_OWNER:0000EM` and `EMITTER_UIDS:0000EM`.
- Final disposition: assign this exact helper band to [UID:0000EM][TextEditControlPane](by-class/TextEditControlPane.md), route it through the same class, keep `RECONSTRUCTABLE:TRUE`, keep reconstruction C++ blank, and do not split or merge the page.
- Required action: supervisor should update the manual `by-memory/-coverage-report.md` row with the exact replacement row in this report. Validator already refreshed `auto-generated/-ag-memory-coverage.md`.
- Confidence: `92/100` for the TextEdit owner/emitter route; `95/100` for physical boundaries and raw pointer/vtable facts; below final C++ readiness because source-quality method and field names remain open.

## Supporting Research

## Target
- Target UID: `0003LQ`
- Target path: `by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md`
- Source queue/report row: current Goal 2 no-owner memory pass from `auto-generated/-ag-memory-coverage.md`; before repair the row was `no-owner`, owner `NONE`, blank emitters, no output path.
- Current supervisor classification: reconstructable no-owner memory target requiring current-doc and IDA MCP recheck under by-structure rules.
- Current scores and parent state:
  - Before this pass: `85/89`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`.
  - After this pass: `88/92`, `CANONICAL_OWNER:0000EM`, `EMITTER_UIDS:0000EM`.
  - Direct parent [UID:0000EM] is `86/90` and routes to [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md), which is `86/88` with `NexusTK/ui/controls/`.

## Executive Recommendation
- The best direct semantic owner is [UID:0000EM] `TextEditControlPane`, not `NONE`.
- The best emitter route is [UID:0000EM] `TextEditControlPane`, which reaches `auto-generated/NexusTK/ui/controls/TextEditControlPane.cpp` through [UID:0000OM].
- The target should remain one exact by-memory page. Splitting into five functions is not needed because all five are base `TextEditControlPane` virtual helpers; ExchangeMoney's missing `0x00498ed0` ref is explained by a derived override at `0x004b0b40`, not by mixed page ownership.
- The exact condition before final C++ is source-quality naming/signature recovery for the five virtuals, wrapper fields at `+0x101/+0x102/+0x109/+0x10c/+0x110`, and callee naming. The page is routed but intentionally has no reconstruction code.

## Supervisor Active Recheck
- The supervisor assigned one target: `[UID:0003LQ] by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md`.
- The prior report `Agent-B003/research/executed/0003LQ-TextControlSharedStateAndBorderHelpers-post-migration-recheck.md` was read as evidence, not authority.
- The assigned item did not require split repair. It is already the exact split between [UID:00011H] `TextEditControlPaneCore` and [UID:00011I] `StaticTextControlPaneConstructor`.
- Direct in-scope repair was required because current IDA RTTI evidence gives a defensible owner/emitter route. The target page was edited and validated; manual `by-memory/-coverage-report.md` was not edited.

## Inference Research Guidance Check
- `by-structure.md` owner/emitter rules were applied: `CANONICAL_OWNER` is the direct semantic owner, while `EMITTER_UIDS` is output routing. Because the direct owner is a class, this page routes through [UID:0000EM], not directly to the by-file page.
- `inference_research.md` guidance was applied: vtable consumer xrefs alone are not ownership proof, but class hierarchy/RTTI plus vtable-slot inheritance is stronger evidence than adjacency or consumer count.
- The prior assumption that multiple vtable families meant "shared owner unknown" was treated as uncertain. Current IDA MCP confirms that StaticText and ExchangeMoney are derived through `TextEditControlPane`, which changes the ownership conclusion.

## Evidence Standards Used
- IDA MCP functions used: `server_health`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `find_bytes`, `entity_query`, `callees`, `analyze_component`, `decompile`, `get_global_value`, and `search_structs`.
- Documentation used: target page, prior B003 executed report, `by-memory/-coverage-report.md`, `auto-generated/-ag-memory-coverage.md`, `by-class` and `by-file` pages for TextEditControlPane, StaticTextControlPane, ExchangeMoneyEditControlPane, ExchangeDialog, and proposed-source-tree.
- Strength: the owner decision is supported by direct RTTI/base-array facts plus vtable-slot behavior, not only by address adjacency.
- Remaining limits: IDA does not provide original source method names or field names for these five helpers, so final C++ remains blocked.

## IDA MCP Facts
- MCP session: `b001_0003gy`
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Health: `status=ok`, `auto_analysis_ready=True`, `hexrays_ready=True`

### Function/range facts

| Range | IDA function | Size | Current role |
| --- | --- | ---: | --- |
| `0x00498dd0-0x00498e0e` | `sub_498DD0` | `0x3e` | Restores wrapper/editor display state, sets `+0x101`, invalidates owner bounds. |
| `0x00498e10-0x00498e5e` | `sub_498E10` | `0x4e` | Saves child text-pane state byte, maps state `2/3`, clears `+0x101`, invalidates. |
| `0x00498e60-0x00498eca` | `sub_498E60` | `0x6a` | Applies inactive child text-pane state, refreshes child bounds, clears `+0x102`. |
| `0x00498ed0-0x00498f4c` | `sub_498ED0` | `0x7c` | Applies active/selectable child state, selects `0..0x7fff`, sets `+0x102`. |
| `0x00498f50-0x00499021` | `sub_498F50` | `0xd1` | Draws optional older text-control border/highlight gated by `+0x109`. |

Neighbor checks:
- `lookup_funcs(0x00498d70)` reports `sub_498D70`, size `0x18`.
- `lookup_funcs(0x00498dc8)` reports `Not a function`.
- `lookup_funcs(0x00499021)` reports `Not a function`.
- `lookup_funcs(0x00499030)` reports `sub_499030`, size `0x1bc`.
- ExchangeMoney exact local helpers remain separate: `0x004b0b40` size `0x14` and `0x004b0b60` size `0x36`.

### Data/table/padding facts

| Range | Bytes |
| --- | --- |
| `0x00498dc8-0x00498dd0` | eight `0xcc` bytes |
| `0x00498e0e-0x00498e10` | two `0xcc` bytes |
| `0x00498e5e-0x00498e60` | two `0xcc` bytes |
| `0x00498eca-0x00498ed0` | six `0xcc` bytes |
| `0x00498f4c-0x00498f50` | four `0xcc` bytes |
| `0x00499021-0x00499030` | fifteen `0xcc` bytes |

### Xref facts

| Target function | Xrefs | Meaning |
| --- | --- | --- |
| `0x00498dd0` | `0x0061814c`, `0x006181f0`, `0x0061a2b0` | TextEdit, StaticText, ExchangeMoney inherited vtable cells. |
| `0x00498e10` | `0x00618150`, `0x006181f4`, `0x0061a2b4` | TextEdit, StaticText, ExchangeMoney inherited vtable cells. |
| `0x00498e60` | `0x00618158`, `0x006181fc`, `0x0061a2bc` | TextEdit, StaticText, ExchangeMoney inherited vtable cells. |
| `0x00498ed0` | `0x0061815c`, `0x00618200` | TextEdit and StaticText vtable cells only; ExchangeMoney overrides this slot. |
| `0x00498f50` | `0x00618144`, `0x006181e8`, `0x0061a2a8` | TextEdit, StaticText, ExchangeMoney inherited vtable cells. |

Raw pointer scan `find_bytes` confirms the same absolute pointer cells and no extra matches for these five function starts.

### Vtable/global/type facts

IDA `entity_query(kind=names)` names these relevant vtables:
- `0x00618100`, `0x00618168`, `0x00618198`: `TextEditControlPane`
- `0x006181a4`, `0x0061820c`, `0x0061823c`: `StaticTextControlPane`
- `0x0061a264`, `0x0061a2cc`, `0x0061a2fc`: `ExchangeMoneyEditControlPane`

IDA `get_global_value` over MSVC RTTI gives the decisive hierarchy facts:
- `TextEditControlPane` CHD `0x00645d58`: base count `7`, base array `0x00645d68`, first descriptor `0x00645d88` (`TextEditControlPane`).
- `StaticTextControlPane` CHD `0x00645de0`: base count `8`, base array `0x00645df0`, first descriptors `0x00645e14` (`StaticTextControlPane`) then `0x00645d88` (`TextEditControlPane`).
- `ExchangeMoneyEditControlPane` CHD `0x006476c0`: base count `8`, base array `0x006476d0`, first descriptors `0x006476f4` (`ExchangeMoneyEditControlPane`) then `0x00645d88` (`TextEditControlPane`).

This proves the multi-vtable refs are inherited base-class slot use. `search_structs TextControl` returned no IDA struct, so there is no current IDA type evidence for a separate `TextControl` base.

### Negative IDA facts
- No ordinary code callers to the five target starts were found; target refs are data/vtable refs.
- No IDA names or structures identify a standalone `TextControlPane`/`TextControlSharedHelpers` owner.
- The only shared global in `analyze_component` is `___security_cookie`, used by the three larger helpers with stack cookies.
- The five target functions have no internal call edges and no strings.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00498dd0-0x00499021` | [UID:0003LQ] target | Inherited TextEdit virtual helper band | TRUE | [UID:0000EM] | `88/92` | Repaired and assigned |
| `0x00498dd0-0x00498e0e` | included in target | show/restore state helper | TRUE | [UID:0000EM] through target | included | No split required |
| `0x00498e10-0x00498e5e` | included in target | deactivate/save state helper | TRUE | [UID:0000EM] through target | included | No split required |
| `0x00498e60-0x00498eca` | included in target | inactive child-state helper | TRUE | [UID:0000EM] through target | included | No split required |
| `0x00498ed0-0x00498f4c` | included in target | active/selectable child-state helper | TRUE | [UID:0000EM] through target | included | No split required |
| `0x00498f50-0x00499021` | included in target | optional border paint helper | TRUE | [UID:0000EM] through target | included | No split required |
| `0x00498dc8-0x00498dd0` | [UID:0000VN] ignored ledger | pre-target padding | FALSE | ignored | `100/strong` | unchanged |
| `0x00499021-0x00499030` | [UID:0000VN] ignored ledger | post-target padding | FALSE | ignored | `100/strong` | unchanged |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00618100`, `0x00618168`, `0x00618198` | refs from `sub_498920`, `sub_498B90`, `sub_49B6C0` | TextEdit construction/destruction vtable stores. |
| `0x006181a4`, `0x0061820c`, `0x0061823c` | refs from `sub_499030` at `0x004990be/0x004990c4/0x004990ce` | StaticText constructor stores derived vtables that inherit TextEdit slots. |
| `0x0061a264`, `0x0061a2cc`, `0x0061a2fc` | refs from `sub_4AC8A0` and `sub_4B0A60` | ExchangeMoney constructor/destructor stores derived vtables that inherit TextEdit slots. |
| `0x00498dd0`, `0x00498e10` | call `sub_5446B0` | Pane/control state transitions. |
| `0x00498e60` | calls `sub_58EA80`, `sub_4B8E00`, security cookie | Text pane inactive mode and bounds refresh. |
| `0x00498ed0` | calls `sub_58EA80`, `sub_58F2A0`, `sub_4B8E00`, security cookie | Text pane active/selectable mode and select-all range. |
| `0x00498f50` | calls `sub_4B7E30`, `sub_4B9660`, `sub_4BA450`, `sub_4B9600`, `sub_4B98F0`, security cookie | Border/highlight drawing. |

## Documentation Evidence And IDA Status
- Target page before repair documented correct boundaries and vtable refs but kept owner/emitter blank. Current IDA confirms the physical facts and adds ownership evidence through RTTI base arrays.
- Prior B003 report correctly rejected consumer-only multi-emitter routing, but it did not use the current RTTI hierarchy evidence. That report's no-owner conclusion is superseded.
- [UID:0000EM] `TextEditControlPane` and [UID:0000OM] `TextEditControlPane.cpp` already describe this band as part of the wrapper/control adapter family. Their current "shared/unexclusive" wording should be updated later to "inherited TextEdit virtual helper band."
- [UID:0000E3] `StaticTextControlPane` and [UID:0000O8] `StaticTextControlPane.cpp` correctly keep the constructor separate; their shared-helper wording should be updated later to inherited-TextEdit wording.
- [UID:00004T] `ExchangeMoneyEditControlPane` and [UID:0003BK] vtable data already describe most target refs as inherited text-edit/control slots; current RTTI confirms that direction.
- `auto-generated/-ag-memory-coverage.md` was updated by validator and now routes `0003LQ` to `auto-generated/NexusTK/ui/controls/TextEditControlPane.cpp`.
- `by-memory/-coverage-report.md` remains manually stale by instruction and needs the supervisor row replacement below.

## Ranked Ownership Analysis

### 1. [UID:0000EM] TextEditControlPane
- Evidence for:
  - Direct IDA RTTI: StaticText and ExchangeMoney class hierarchy descriptors list `TextEditControlPane` immediately after their derived descriptors.
  - Direct IDA vtable facts: TextEdit, StaticText, and ExchangeMoney share the same slot offsets for four helpers, while StaticText shares all five.
  - ExchangeMoney slot asymmetry is explained by a local derived override at `0x004b0b40`, not by different ownership of the base helper band.
  - Documentation: TextEditControlPane owns the wrapper fields and embedded `TextEditPane*` layout used by all five helpers.
- Evidence against:
  - Source-level virtual method names are not recovered.
  - The page is split out from the adjacent TextEdit core range, so it should remain a separate memory page rather than be merged back into [UID:00011H].
- Decision: accepted. Set `CANONICAL_OWNER:0000EM` and `EMITTER_UIDS:0000EM`.

### 2. Keep `CANONICAL_OWNER:NONE`
- Evidence for:
  - Prior reports only had consumer vtable refs and no direct hierarchy proof.
  - There is still no final source method naming.
- Evidence against:
  - Current RTTI hierarchy evidence is strong enough to identify `TextEditControlPane` as the implementation owner.
  - Leaving `NONE` would now ignore direct base-class evidence and keep a reconstructable source-authored method band unnecessarily blocked.
- Decision: rejected and repaired.

### 3. [UID:0000E3] StaticTextControlPane
- Evidence for:
  - StaticText vtables reference all five helper bodies.
  - StaticText constructor follows after the target.
- Evidence against:
  - StaticText RTTI derives through TextEditControlPane.
  - StaticText constructor starts after confirmed padding at `0x00499030`.
  - Its vtable refs are inherited-slot use, not implementation ownership.
- Decision: rejected.

### 4. [UID:00004T] ExchangeMoneyEditControlPane / [UID:0000J9] ExchangeDialog
- Evidence for:
  - ExchangeMoney vtables reference four of the five helper bodies.
  - ExchangeMoney has exact vtable-data docs and feature-local helper docs.
- Evidence against:
  - ExchangeMoney RTTI derives through TextEditControlPane.
  - It lacks `0x00498ed0` because it overrides that slot with `0x004b0b40`.
  - Its source file owns only the derived money-input overrides, not the inherited TextEdit base implementations.
- Decision: rejected.

### 5. Proposed new file/grouping
- Proposed owner/name/path: none recommended.
- Likely full contents: not applicable.
- Candidate related items that belong: none found beyond the already mapped TextEditControlPane family.
- Candidate related items rejected: a hypothetical `TextControlPane.cpp`/`TextControlSharedHelpers.cpp` because IDA has no matching RTTI/name/struct and current RTTI points to the existing `TextEditControlPane` base.
- Standalone, narrow, or broad source-file inference: no new file. Existing `TextEditControlPane.cpp` is the correct source route.

## Negative Evidence Summary
- Consumer vtable refs alone were not used as proof; the decision depends on RTTI hierarchy plus slot behavior.
- No ordinary caller evidence exists for a free helper function model.
- No IDA type/name/struct evidence supports a separate `TextControl` owner.
- Address adjacency to StaticText is weak and contradicted by the padding boundary and RTTI.
- ExchangeMoney cannot be a whole-page owner/emitter because it overrides the `0x00498ed0` slot.
- `ControlPane` and `TextEditPane` are dependencies, not direct owners: the receiver layout is the text-control wrapper, while embedded `TextEditPane` is accessed through `+0x10c`.

## Final Recommendation
- Exact changes applied:
  - Target page metadata changed to `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000EM`, `EMITTER_UIDS:0000EM`.
  - Target body updated with RTTI class-hierarchy evidence and corrected ownership rationale.
  - Target cross-references updated for ExchangeMoney class/vtable evidence.
  - Validator file apply run; generated autogen memory coverage refreshed.
- Exact parent assignments applied:
  - [UID:0003LQ] -> [UID:0000EM] `TextEditControlPane`
  - Emitter route [UID:0003LQ] -> [UID:0000EM] -> [UID:0000OM] -> `auto-generated/NexusTK/ui/controls/TextEditControlPane.cpp`
- Exact items left no-owner/non-emitting and why:
  - None in this target.
- Exact future work outside this assignment scope:
  - Update surrounding class/file prose in TextEditControlPane, StaticTextControlPane, and ExchangeMoneyEditControlPane docs from "shared unresolved helper band" to "inherited TextEditControlPane virtual helper band."
  - Recover source-quality names/signatures before entering final C++.

### Exact manual `by-memory/-coverage-report.md` replacement row

Replace the current row between the `0x00498dc8-0x00498dd0` padding row and the `0x00499021-0x00499030` padding row with:

```text
    - [UID:0003LQ][0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers](by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md) 0x00498dd0-0x00499021 | inherited method cluster | TextControlSharedStateAndBorderHelpers : reconstructable : 88% : strong : B003 current Goal 2 repaired the former no-owner row; live IDA MCP session `b001_0003gy` reconfirmed the five aligned helper functions, boundary padding, raw pointer refs, vtable refs from TextEditControlPane/StaticTextControlPane/ExchangeMoneyEditControlPane, and MSVC RTTI class-hierarchy arrays showing StaticTextControlPane and ExchangeMoneyEditControlPane derive through [UID:0000EM][TextEditControlPane](by-class/TextEditControlPane.md), so `CANONICAL_OWNER:0000EM` and `EMITTER_UIDS:0000EM`; final C++ remains blank pending source-quality method/field names.
```

### Current generated autogen row after validator apply

```text
| [UID:0003LQ][0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers](by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md) | emits | `0000EM` | `0000EM` |  | no | `auto-generated/NexusTK/ui/controls/TextEditControlPane.cpp` | `by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md` |  |
```

## Follow-Up Actions
- Supervisor actions:
  - Apply the manual `by-memory/-coverage-report.md` row replacement above.
  - Treat `0003LQ` as resolved from the no-owner memory pass; it should no longer be selected as reconstructable no-owner.
- A-agent actions:
  - Refresh surrounding TextEdit/StaticText/Exchange docs to describe inherited TextEdit base slots instead of unresolved shared ownership.
  - Do not add reconstruction C++ until method/field names and signatures clear the active source-code gate.
- B003 future research actions:
  - No additional split research is needed for this target unless later source/naming work discovers a more precise virtual-method naming scheme.

## Confidence
- Recommendation confidence: `92/100`.
- Boundary confidence: `95/100`.
- Vtable/raw pointer confidence: `95/100`.
- RTTI inheritance confidence: `94/100`.
- Score confidence: `90/100`; completion is capped at `88` due source naming and C++ gaps.
- Remaining uncertainty:
  - Exact original virtual method names.
  - Exact source field names for wrapper bytes and embedded text-pane pointer.
  - Whether final source groups these helper implementations textually with nearby TextEdit methods or in a local region inside the same source file. This does not block the current class/file route.

## Validator Results
- Commands run:
  - `python leaser.py B003 lease "E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md"`
  - `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file "E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md" --apply`
  - `python leaser.py B003 unlease "E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md"`
- Results:
  - Lease: success.
  - Validator: `ok: 1`, `completion_update 0003LQ ... 88`, `confidence_update 0003LQ ... 92`, `canonical_owner_update 0003LQ ... NONE -> 0000EM`, `autogen_registry_update 0003LQ ... -> 0000EM`, `autogen_report_update ... auto-generated/-ag-memory-coverage.md`.
  - Validator reported `autogen_emitter_has_no_code: 1`, which is expected because the page is routed but intentionally has no reconstruction C++.
  - Unlease: success.
- Any unresolved validator warnings/errors:
  - No blocking validator errors.
  - No dry-run mode was used.

## Changed Files
- Created:
  - `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B003\research\0003LQ-TextControlSharedStateAndBorderHelpers-current-goal2-pass.md`
- Modified:
  - `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md`
  - `E:\NTK\GhidraBridge\source-3\project-documentation\auto-generated\-ag-memory-coverage.md` (validator-owned generated update)
  - `E:\NTK\GhidraBridge\source-3\project-documentation\project-level\-auto-completion-stats.md` (validator reported projected stats update)
- Validator-created backup side effect:
  - `tools/validator_autogen_backup/20260613-213641`
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003LQ","source_path":"executed-b-agent-research/B003/0003LQ-TextControlSharedStateAndBorderHelpers-current-goal2-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
