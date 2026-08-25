** TARGET-REPORT-UID:0003LQ **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003LQ **
# 0003LQ TextControlSharedStateAndBorderHelpers Post-Migration Recheck

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003LQ] `by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md` as `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank reconstruction C++.
- Final disposition: no owner assignment, no emitter assignment, no reclassification, no split, no merge, and no IDA-side repair recommended from the current evidence.
- Required action: no `by-memory/-coverage-report.md` edit is needed. No by-* documentation edit is needed for this target.
- Score before/after: `85/89 -> 85/89`.
- Confidence: `89/100` for the no-owner/non-emitting recommendation; `95/100` for physical boundaries and pointer-cell facts; below action threshold for every positive owner/emitter route.

This is a valid reconstructable no-owner/non-emitting state under the current owner/emitter model. The item is confirmed NexusTK source-authored virtual-helper code, so `RECONSTRUCTABLE:TRUE` is still correct. However, `EMITTER_UIDS` is source-output routing, not a list of vtable consumers. The current binary proves that TextEditControlPane, StaticTextControlPane, and ExchangeMoneyEditControlPane vtable cells consume these physical function bodies, but it does not prove whether the original source used inherited methods, a hidden shared base/helper implementation, or separate virtual methods later folded or shared by the linker. Emitting this page into one or more current source roots would be an unsupported source-output claim.

The strongest reason not to add multiple emitters is the page-level asymmetry: `0x00498ed0` is referenced by TextEdit and StaticText vtable cells only, while the other four helper starts also have ExchangeMoney vtable cells. A whole-page route through ExchangeMoney would over-emit a function ExchangeMoney does not use.

## Supporting Research

## Target

- Target UID: `0003LQ`
- Target path: `by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md`
- Source queue/report row: `auto-generated/-ag-memory-coverage.md`, current `no-owner` row with `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, and no output path.
- Supervisor assignment: `B003-0003LQ-post-migration-recheck`.
- Prior reports reviewed as evidence, not authority:
  - `tools/leaser/Agents/Agent-B001/research/executed/0003LQ-TextControlSharedStateAndBorderHelpers.md`
  - `tools/leaser/Agents/Agent-B001/research/executed/0003LQ-TextControlSharedStateAndBorderHelpers-second-pass.md`
- Current target metadata:

```text
*** UID:0003LQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

## Executive Recommendation

Keep the current row unchanged. The target is an exact shared physical helper band between [UID:00011H] `TextEditControlPaneCore` and [UID:00011I] `StaticTextControlPaneConstructor`. It is not dead code, compiler padding, or runtime code. It is also not ready for source output, because the direct source owner and emitter route remain unresolved after a current live IDA MCP pass.

If forced to choose the least-bad positive route, `TextEditControlPane` would rank first due to address adjacency, matching wrapper layout, and ExchangeMoney constructor/destructor reuse of TextEdit setup/cleanup. It still does not clear the action bar because StaticText constructs its own wrapper, installs StaticText vtables, and references all five helper functions. A TextEdit-only route would turn a consumer/inheritance hypothesis into a source-owner claim.

Do not use `EMITTER_UIDS:0000EM,0000E3,00004T`, `0000OM,0000O8,0000J9`, or any subset yet. Vtable consumers are source-use evidence, but they are not enough to prove that source output must be duplicated into each consuming class/file. Whole-page ExchangeMoney emission is specifically blocked because `0x00498ed0` has no ExchangeMoney pointer cell.

## Supervisor Active Recheck

The supervisor requested a post-migration no-owner recheck under the current `CANONICAL_OWNER` / `EMITTER_UIDS` split, with special attention to mixed ownership and split rules. The assigned item did not require immediate split repair. The current page is already the prior split repair for an overbroad TextEdit/StaticText overlap: TextEdit-local code ends before `0x00498dd0`, StaticText constructor starts at `0x00499030`, and this page covers only the five real helper functions between them.

The active `90/90+` reconstruction-code gate was applied. The item is below that gate at `85/89`, and the owner/emitter route is unresolved, so reconstruction C++ should remain blank.

## Inference Research Guidance Check

- IDA fact: function starts, sizes, padding, xrefs, vtable names, callees, decompiler observations, and pointer-byte matches came from live IDA MCP against session `b001_0003gy`.
- Documentation evidence: target, generated coverage, by-memory coverage, TextEdit, StaticText, ExchangeMoney, ExchangeDialog, and proposed-source-tree docs were used as leads and checked against IDA where possible.
- Inference: ownership/routing is evaluated from source-layout models. The current evidence supports "shared physical virtual helper bodies" but does not distinguish inherited implementation from a hidden shared base/helper from linker folding.
- Current model rule applied: `CANONICAL_OWNER:NONE` with blank emitters is acceptable while a reconstructable source-authored item is confirmed but output routing remains unproven. It is not a final "dead/non-emitting forever" classification.

## Evidence Standards Used

Evidence used in this pass:

- `by-structure.md` current owner/emitter model and `90/90+` code-entry gate.
- `inference_research.md` guidance that adjacency and consumer xrefs are useful but not proof of source ownership.
- Live IDA MCP tools: `idb_list`, `tools/list`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `find_bytes`, `callees`, `entity_query`, `decompile`, and `analyze_component`.
- Current generated rows in `auto-generated/-ag-memory-coverage.md` and current coverage row in `by-memory/-coverage-report.md`.
- Current by-* docs for TextEditControlPane, StaticTextControlPane, ExchangeMoneyEditControlPane, ExchangeDialog, and proposed source-tree placement.

MCP availability note: `tools/list` and `idb_list` were live. The endpoint required a `database` argument for current worker-backed calls; the active session was `b001_0003gy`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, active and not analyzing. Initial empty `initialize` returned missing MCP client parameters, and an initial no-database tool call returned "database is required"; rerunning with `database=b001_0003gy` succeeded.

## IDA MCP Facts

### Function and Range Facts

Live `lookup_funcs` with `database=b001_0003gy` reports:

| Range | IDA function | Size | Role summary |
| --- | --- | ---: | --- |
| `0x00498dd0-0x00498e0e` | `sub_498DD0` | `0x3e` | Uses byte `+0x101`, calls `sub_5446B0`, sets active/show state, invalidates `this+0x44` through vtable slot `+0x20`. |
| `0x00498e10-0x00498e5e` | `sub_498E10` | `0x4e` | Saves embedded child state from `this[67]+0xb5` into byte `+0x110`, calls `sub_5446B0(2/3)`, clears byte `+0x101`, invalidates. |
| `0x00498e60-0x00498eca` | `sub_498E60` | `0x6a` | Applies inactive embedded text-pane state, refreshes child bounds, clears byte `+0x102`, invalidates if previously active. |
| `0x00498ed0-0x00498f4c` | `sub_498ED0` | `0x7c` | Applies active/selectable state, calls select-range behavior with `0,0x7fff`, refreshes child bounds, sets byte `+0x102`, invalidates if needed. |
| `0x00498f50-0x00499021` | `sub_498F50` | `0xd1` | Draws optional older border/highlight when byte `+0x109` is set. |

Neighbor checks:

- `0x00498dc8` is not a function.
- `0x00498d70` is `sub_498D70`, size `0x18`, before the pre-target padding.
- `0x00499021` is not a function.
- `0x00499030` is `sub_499030`, size `0x1bc`, the StaticText constructor start.
- ExchangeMoney-local helper starts remain separate: `0x004b0b40` is `sub_4B0B40`, size `0x14`; `0x004b0b60` is `sub_4B0B60`, size `0x36`; `0x004ac8a0` and `0x004b0a60` are the ExchangeDialog construction and ExchangeMoney teardown paths.

### Padding and Boundary Facts

Live `get_bytes` confirms the target is bounded by padding and contains aligned padding between the five helper functions:

| Range | Bytes |
| --- | --- |
| `0x00498dc8-0x00498dd0` | eight `0xcc` bytes |
| `0x00498e0e-0x00498e10` | two `0xcc` bytes |
| `0x00498e5e-0x00498e60` | two `0xcc` bytes |
| `0x00498eca-0x00498ed0` | six `0xcc` bytes |
| `0x00498f4c-0x00498f50` | four `0xcc` bytes |
| `0x00499021-0x00499030` | fifteen `0xcc` bytes |

### Direct Xrefs and Raw Pointer Matches

Live `xrefs_to` reports only data refs to the five target function starts:

| Target function | Xrefs | Meaning |
| --- | --- | --- |
| `0x00498dd0` | `0x0061814c`, `0x006181f0`, `0x0061a2b0` | TextEdit, StaticText, ExchangeMoney vtable cells |
| `0x00498e10` | `0x00618150`, `0x006181f4`, `0x0061a2b4` | TextEdit, StaticText, ExchangeMoney vtable cells |
| `0x00498e60` | `0x00618158`, `0x006181fc`, `0x0061a2bc` | TextEdit, StaticText, ExchangeMoney vtable cells |
| `0x00498ed0` | `0x0061815c`, `0x00618200` | TextEdit and StaticText vtable cells only |
| `0x00498f50` | `0x00618144`, `0x006181e8`, `0x0061a2a8` | TextEdit, StaticText, ExchangeMoney vtable cells |

Live `find_bytes` for little-endian absolute pointers confirms the same cells:

| Pattern | Function pointer | Matches |
| --- | --- | --- |
| `D0 8D 49 00` | `0x00498dd0` | `0x0061814c`, `0x006181f0`, `0x0061a2b0` |
| `10 8E 49 00` | `0x00498e10` | `0x00618150`, `0x006181f4`, `0x0061a2b4` |
| `60 8E 49 00` | `0x00498e60` | `0x00618158`, `0x006181fc`, `0x0061a2bc` |
| `D0 8E 49 00` | `0x00498ed0` | `0x0061815c`, `0x00618200` |
| `50 8F 49 00` | `0x00498f50` | `0x00618144`, `0x006181e8`, `0x0061a2a8` |

This confirms there are no hidden extra absolute pointer cells in the checked IDB for the target starts.

### Vtable and Consumer Facts

Live `entity_query(kind=names)` over `0x00618100-0x00618250` reports:

- `0x00618100`: `??_7TextEditControlPane@@6B@`
- `0x00618168`: `??_7TextEditControlPane@@6B@_0`
- `0x00618198`: `??_7TextEditControlPane@@6B@_1`
- `0x006181a4`: `??_7StaticTextControlPane@@6B@`
- `0x0061820c`: `??_7StaticTextControlPane@@6B@_0`
- `0x0061823c`: `??_7StaticTextControlPane@@6B@_1`

Live `entity_query(kind=names)` over `0x0061a260-0x0061a310` reports:

- `0x0061a264`: `??_7ExchangeMoneyEditControlPane@?A0x0ff658a5@@6B@`
- `0x0061a2cc`: `??_7ExchangeMoneyEditControlPane@?A0x0ff658a5@@6B@_0`
- `0x0061a2fc`: `??_7ExchangeMoneyEditControlPane@?A0x0ff658a5@@6B@_1`

Live `xrefs_to` for vtable bases confirms store/restore contexts:

- TextEdit vtable bases `0x00618100`, `0x00618168`, and `0x00618198` are referenced by the TextEdit construction/destruction area, including `sub_498920`, `sub_498B90`, and `sub_49B6C0`.
- StaticText vtable bases `0x006181a4`, `0x0061820c`, and `0x0061823c` are referenced from `sub_499030` at `0x004990be`, `0x004990c4`, and `0x004990ce`.
- ExchangeMoney vtable bases `0x0061a264`, `0x0061a2cc`, and `0x0061a2fc` are referenced from `sub_4AC8A0` at `0x004accd3`, `0x004accd9`, and `0x004acce3`, and from `sub_4B0A60` at `0x004b0a66`, `0x004b0a6c`, and `0x004b0a76`.

### Callee and Behavior Facts

Live `callees` and `analyze_component` show no internal calls between the five target functions and no string literals:

- `0x00498dd0` calls `sub_5446B0`.
- `0x00498e10` calls `sub_5446B0`.
- `0x00498e60` calls `sub_58EA80`, `sub_4B8E00`, and `@__security_check_cookie@4`.
- `0x00498ed0` calls `sub_58EA80`, `sub_58F2A0`, `sub_4B8E00`, and `@__security_check_cookie@4`.
- `0x00498f50` calls drawing helpers `sub_4B7E30`, `sub_4B9660`, `sub_4BA450`, `sub_4B9600`, `sub_4B98F0`, and `@__security_check_cookie@4`.
- `analyze_component` reports the only shared global as `___security_cookie`, accessed by the three larger helpers.

Decompilation confirms the target functions operate on wrapper state bytes and embedded text-pane state:

- `0x00498dd0` reads/writes `this[257]`, reads `this[272]`, and invalidates `this+68`.
- `0x00498e10` reads `this[67]+181`, stores `this+272`, clears `this+257`, and invalidates `this+68`.
- `0x00498e60` and `0x00498ed0` operate through `this[67]`, use bytes at `this+258`, and invalidate `this+68`.
- `0x00498f50` checks `this+265` and draws around the rectangle at `this+68`.

These are text-control wrapper helpers, not generic ControlPane-only helpers and not TextEditPane-owned methods.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct owner | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00498dd0-0x00499021` | [UID:0003LQ] target | Shared physical helper band | TRUE | NONE | `85/89` | Keep no-owner/non-emitting |
| `0x00498dd0-0x00498e0e` | included in target | active/show state helper | TRUE | unresolved | included | No split now |
| `0x00498e10-0x00498e5e` | included in target | deactivate/save state helper | TRUE | unresolved | included | No split now |
| `0x00498e60-0x00498eca` | included in target | inactive child-state helper | TRUE | unresolved | included | No split now |
| `0x00498ed0-0x00498f4c` | included in target | active/selectable child-state helper | TRUE | unresolved | included | No split now |
| `0x00498f50-0x00499021` | included in target | optional border/highlight paint helper | TRUE | unresolved | included | No split now |
| `0x00498dc8-0x00498dd0` | [UID:0000VN] ignored ledger | pre-target padding | FALSE | ignored | `100/strong` | Existing coverage ok |
| `0x00499021-0x00499030` | [UID:0000VN] ignored ledger | post-target padding | FALSE | ignored | Existing coverage ok |

## Source-Use / Emitter Inventory

| Candidate emitter context | Evidence for source use | Blocking facts | Decision |
| --- | --- | --- | --- |
| [UID:0000EM] `TextEditControlPane` / [UID:0000OM] `TextEditControlPane.cpp` | All five helper starts have TextEdit vtable cells; target follows TextEdit-local core; wrapper layout matches TextEdit embedded `TextEditPane` design. | StaticText has its own constructor and vtables pointing at all five; no source evidence proves TextEdit authored the shared implementation. | Best forced candidate, rejected. |
| [UID:0000E3] `StaticTextControlPane` / [UID:0000O8] `StaticTextControlPane.cpp` | All five helper starts have StaticText vtable cells; StaticText constructor follows the target and installs StaticText vtables. | TextEdit and ExchangeMoney also use the band; the target was split out specifically to avoid StaticText overclaim. | Rejected. |
| [UID:00004T] `ExchangeMoneyEditControlPane` / [UID:0000J9] `ExchangeDialog.cpp` | Four helper starts have ExchangeMoney vtable cells; ExchangeMoney docs and live xrefs confirm local vtable setup/teardown and separate local overrides. | `0x00498ed0` lacks an ExchangeMoney vtable ref; ExchangeMoney has separate exact local methods at `0x004b0b40` and `0x004b0b60`; feature-local class cannot own the shared TextEdit/StaticText band. | Rejected for whole page. |
| Multiple emitters across TextEdit/StaticText/ExchangeMoney | More than one concrete vtable family consumes physical target bodies. | Vtable use does not prove duplicated source definitions; inherited/base/shared implementation remains plausible; page-level ExchangeMoney route would overclaim `0x00498ed0`. | Rejected. |
| New shared owner, e.g. `TextControlPane` or `TextControlSharedHelpers.cpp` | A shared text-control source owner would explain multiple vtable families. | No IDA name, RTTI/type, constructor, vtable, source string, or proposed-source-tree entry proves such an owner; no broader candidate file contents were found. | Rejected for now. |
| [UID:000038] `ControlPane` / [UID:0000IG] `ControlPane.cpp` | Helpers invalidate/draw control rectangles and use pane drawing infrastructure. | Functions touch text-wrapper bytes and embedded text-pane pointer; not generic ControlPane behavior. | Rejected. |
| [UID:0000EO] `TextEditPane` / [UID:0000ON] `TextEditPane.cpp` | Helpers call embedded text-pane methods. | Receiver is wrapper/control object and refs are wrapper vtables; TextEditPane is a dependency, not the direct owner. | Rejected. |

## Documentation Evidence And IDA Status

- Target page `by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md` documents the five helper functions, shared vtable refs, padding boundaries, and unresolved owner/emitter state. Current IDA MCP confirms the documented physical facts.
- `by-memory/-coverage-report.md` currently describes the item as a shared method cluster with `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS` after B001 second-pass review. Current IDA MCP confirms the basis for that row.
- `auto-generated/-ag-memory-coverage.md` currently lists the item as `no-owner`, owner `NONE`, blank emitters, and no output path. This is consistent with current metadata.
- [UID:0000EM] `by-class/TextEditControlPane.md` and [UID:0000OM] `by-file/TextEditControlPane.md` list the shared helper band but do not claim it exclusively. IDA confirms TextEdit is a real consumer and strong lead, not an exclusive owner.
- [UID:0000E3] `by-class/StaticTextControlPane.md` and [UID:0000O8] `by-file/StaticTextControlPane.md` list the helper band as shared and keep the constructor as a separate exact page. IDA confirms StaticText vtable cells and constructor boundary.
- [UID:00004T] `by-class/ExchangeMoneyEditControlPane.md`, [UID:0000J9] `by-file/ExchangeDialog.md`, and [UID:0003BK] `by-memory/0x0061a260-0x0061a304.ExchangeMoneyEditControlPaneVtableData.md` document ExchangeMoney's exact local helpers and vtable data. Current IDA confirms the vtable base names and constructor/destructor refs; ExchangeMoney vtable data documents `0x00498f50`, `0x00498dd0`, `0x00498e10`, and `0x00498e60` as inherited text-edit/control slots, with no `0x00498ed0` slot.
- `by-project-structure/proposed-source-tree.md` contains `ui/controls/TextEditControlPane.cpp`, `ui/controls/StaticTextControlPane.cpp`, `ui/dialogs/ExchangeDialog.cpp`, `ui/core/ControlPane.cpp`, and `ui/controls/TextEditPane.cpp`. It does not contain a confirmed shared `TextControlPane.cpp` or `TextControlSharedHelpers.cpp` source root.
- Ancillary doc note: some related TextEdit/StaticText pages still contain old `95/95` code-entry wording. That is stale relative to the active `90/90+` gate, but it does not affect the `0003LQ` owner/emitter recommendation and is outside this no-edit assignment.

## Ranked Ownership Analysis

### 1. Keep `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`

Evidence for:

- Direct IDA evidence proves a shared physical helper band and exact boundary padding.
- Direct IDA evidence proves vtable/data refs from multiple concrete text-control classes.
- Direct IDA evidence does not prove ordinary callers or a single private source-file helper owner.
- Current docs already model the adjacent TextEdit and StaticText pages as exact neighbors rather than owners of this whole band.
- The owner/emitter split requires source-output proof for emitters, not just consumer enumeration.
- ExchangeMoney cannot be a whole-page emitter because it lacks `0x00498ed0`.

Evidence against:

- The functions are real source-authored behavior, so final reconstruction eventually needs some source representation.
- TextEdit remains a plausible inherited-implementation route if future evidence establishes the class hierarchy/source declaration model.

Decision: recommended.

### 2. Assign TextEditControlPane

Evidence for:

- The target immediately follows TextEdit-local code.
- The helper layout uses TextEdit wrapper offsets and embedded `TextEditPane` state.
- ExchangeMoney construction and cleanup reuse TextEdit construction/cleanup paths.

Evidence against:

- StaticText independently constructs a wrapper and installs StaticText vtables that reference all five functions.
- No IDA/source evidence proves these are TextEdit member functions inherited by StaticText.
- Assigning TextEdit would undo the prior overbroad split in source-output form.

Decision: rejected, but best forced candidate.

### 3. Assign StaticTextControlPane

Evidence for:

- StaticText vtable cells reference all five helpers.
- StaticText constructor is adjacent after the helper band.

Evidence against:

- TextEdit and ExchangeMoney vtables also reference the helper band.
- StaticText constructor starts after post-target padding at `0x00499030`; the target is not constructor-local.
- Prior split repair separated this band from StaticText for a reason confirmed by current IDA.

Decision: rejected.

### 4. Assign ExchangeMoneyEditControlPane or ExchangeDialog

Evidence for:

- ExchangeMoney vtables consume four of the helper starts.
- ExchangeMoney class/file docs are strong for local numeric edit control behavior.

Evidence against:

- `0x00498ed0` has no ExchangeMoney vtable/data ref.
- ExchangeMoney's local source-owned helpers are separately documented at `0x004b0b40` and `0x004b0b60`.
- Current ExchangeMoney vtable data describes the target refs as inherited text-edit/control slots.

Decision: rejected.

### 5. Create a new shared text-control owner

Evidence for:

- A hidden shared base or helper module would be a plausible source-design explanation for TextEdit and StaticText sharing these virtual bodies.

Evidence against:

- No current IDA names, RTTI/type descriptors, constructors, vtables, source strings, PDB breadcrumbs, or project docs identify this owner.
- No broader candidate contents were found beyond this exact band.
- Creating a new source root just to avoid `NONE` would be design invention, not evidence-backed routing.

Decision: rejected for now. Reconsider only if future hierarchy/source evidence appears.

## Split / Merge / Reclassification Decision

No split is recommended now. The target is already a correct physical split from adjacent TextEdit and StaticText pages. Splitting into five separate child pages would not resolve ownership; it would create five smaller reconstructable no-owner pages. It would only become useful if future source evidence proves function-specific emitter routes, especially because ExchangeMoney consumes four helpers but not `0x00498ed0`.

If future evidence does require function-level emitter routing, use these exact child ranges:

| Proposed child range | Proposed name | Current routing blocker |
| --- | --- | --- |
| `0x00498dd0-0x00498e0e` | `TextControlActivateStateSyncHelper` | Source owner not proven; consumed by TextEdit, StaticText, ExchangeMoney. |
| `0x00498e10-0x00498e5e` | `TextControlDeactivateStateSyncHelper` | Source owner not proven; consumed by TextEdit, StaticText, ExchangeMoney. |
| `0x00498e60-0x00498eca` | `TextControlInactiveChildStateHelper` | Source owner not proven; consumed by TextEdit, StaticText, ExchangeMoney. |
| `0x00498ed0-0x00498f4c` | `TextControlActiveSelectableChildStateHelper` | Source owner not proven; consumed by TextEdit and StaticText only. |
| `0x00498f50-0x00499021` | `TextControlBorderFramePaintHelper` | Source owner not proven; consumed by TextEdit, StaticText, ExchangeMoney. |

Internal padding spans should remain ignored if split later: `0x00498e0e-0x00498e10`, `0x00498e5e-0x00498e60`, `0x00498eca-0x00498ed0`, and `0x00498f4c-0x00498f50`.

No reclassification to `RECONSTRUCTABLE:FALSE` is recommended. The functions are executable project code with concrete vtable use and decompiled behavior. They are not padding, compiler/runtime helpers, or dead evidence. They are simply not source-routable yet.

## Negative Evidence Summary

- No ordinary call refs to the target starts were found; current refs are vtable/data refs.
- No direct IDA evidence identifies a single source owner.
- No current IDA evidence identifies a `TextControlPane`, `TextControlBase`, or shared text-control helper file.
- No proposed-source-tree entry exists for a shared text-control helper source root.
- No `ControlPane` route is supported because the helpers operate on text-wrapper fields and embedded text-pane state.
- No `TextEditPane` route is supported because the receiver object is the wrapper/control pane, not the embedded pane.
- No ExchangeMoney whole-page route is supported because the `0x00498ed0` helper lacks an ExchangeMoney vtable cell.
- No split/merge repair is required before this conclusion because exact boundaries are already proven.

## Exact Recommended Metadata / Coverage Changes

No metadata changes are recommended. Keep the target header exactly as:

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No `by-memory/-coverage-report.md` replacement is required. Current row should remain:

```text
    - [UID:0003LQ][0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers](by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md) 0x00498dd0-0x00499021 | shared method cluster | TextControlSharedStateAndBorderHelpers : reconstructable : 85% : strong : C001 exact shared helper page for five vtable-only state/border helpers; B001 second-pass review kept `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS` because live IDA/raw PE evidence confirms function starts/sizes, refs from TextEditControlPane, StaticTextControlPane, and ExchangeMoneyEditControlPane vtable cells, and internal 0xcc padding, but does not prove a single source-level shared owner or a safe whole-page multi-emitter route.
```

No `auto-generated/-ag-memory-coverage.md` replacement is required. Current generated row is:

```text
| [UID:0003LQ][0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers](by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md` |  |
```

## Final Recommendation

- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `CANONICAL_OWNER:NONE`.
- Keep blank `EMITTER_UIDS`.
- Keep blank `EMITTER_POSITION_OPTIONAL`.
- Keep reconstruction C++ blank.
- Keep score `85/89`.
- Do not split, merge, rename, or reclassify this target now.
- Do not edit `by-memory/-coverage-report.md`.
- Do not route this page to TextEditControlPane, StaticTextControlPane, ExchangeMoneyEditControlPane, ControlPane, or TextEditPane without new source-model evidence.

The item should be revisited only if future evidence proves one of these source models:

- A real shared text-control base/helper owner with a documented source route.
- A TextEdit-owned inherited implementation model strong enough to emit once through TextEdit.
- Function-specific folded/duplicated method definitions strong enough to justify splitting and assigning per-function emitters.

## Follow-Up Actions

- Supervisor: no row change required; record this as B003 confirmation of the current no-owner/non-emitting state.
- A-agents: do not emit or attach `0003LQ` from current vtable-consumer evidence alone.
- Future B-agent work: if a shared text-control base/source file emerges, revisit this page and the adjacent TextEdit/StaticText/ExchangeMoney vtable docs together.
- Ancillary cleanup outside this assignment: related TextEdit/StaticText pages contain old `95/95` C++ gate wording and can be updated later to the current `90/90+` phrasing.

## Confidence

- Recommendation confidence: `89/100`.
- Boundary confidence: `95/100`.
- Vtable/data pointer confidence: `95/100`.
- Behavior confidence: `86/100`.
- Positive route confidence:
  - TextEditControlPane route: `58/100`, best forced route but below action.
  - New shared text-control owner: `55/100`, plausible design but unproven.
  - StaticTextControlPane route: `42/100`.
  - ExchangeMoney route: `25/100` for whole page.
  - ControlPane/TextEditPane routes: below `25/100`.

## Validator Results

- Validator was not run. No by-* documentation, coverage report, generated report, or validator-managed target page was edited.
- No dry-run mode was used.
- No lease was required because only this B003 research report was created inside the assigned Agent-B003 folder.
- Validation/memory_ranges rerun: not required for this report-only recommendation because no memory ranges or metadata were changed.

## Changed Files

- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B003\research\0003LQ-TextControlSharedStateAndBorderHelpers-post-migration-recheck.md`
- Modified: none outside this report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003LQ","source_path":"executed-b-agent-research/B003/0003LQ-TextControlSharedStateAndBorderHelpers-post-migration-recheck.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
