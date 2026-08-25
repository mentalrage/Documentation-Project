** TARGET-REPORT-UID:0003LQ **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003LQ **
# 0003LQ TextControlSharedStateAndBorderHelpers Ownership / Split Research

Revision: Agent-B001 final report, live IDA MCP recheck on 2026-06-13.

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003LQ] `by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md` as a reconstructable, source-authored shared helper band with `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and no reconstruction C++.
- Final disposition: no split, no reclassification, no parent/source repair required for this target. The current `no-owner` / `non-emits` generated state is intentional and evidence-backed, not an unfinished cleanup artifact.
- Required action: none for `auto-generated/-ag-memory-coverage.md`, `by-memory/-coverage-report.md`, or the target by-memory page. If the supervisor wants a status label, close B001-0003LQ as "no-owner/non-emitting confirmed after IDA MCP review."
- Confidence: `88/100` for the recommendation, `94/100` for the physical range/boundaries, `90/100` for the shared vtable-use facts, and `70/100` for the underlying source-model explanation. The weak part is original C++ source representation, not the binary evidence.

Recommended metadata state remains:

```text
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Under the current owner/emitter model, `CANONICAL_OWNER:NONE` is correct because IDA proves the same physical functions are used by multiple concrete class vtable families and does not prove whether the original source owner was a real shared base/mixin, one concrete class with inherited slots, or separate identical virtual implementations folded by the linker. `EMITTER_UIDS` are not justified yet because vtable consumption is not output-routing proof. A single emitter would overclaim one class as the source home; multiple emitters would assume duplicate source methods or ICF without proof.

If forced to pick an existing source route today, the least-bad single route would be [UID:0000EM] `TextEditControlPane`, because the band is adjacent to TextEditControlPane local code and uses the same embedded `TextEditPane*` layout. It still does not clear the evidence bar: [UID:0000E3] `StaticTextControlPane` installs its own concrete vtables pointing at the same bodies, and [UID:00004T] `ExchangeMoneyEditControlPane` consumes four of the five bodies through its vtable data.

## Supporting Research

## Target

- Target UID: `0003LQ`
- Target path: `by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md`
- Source row: `auto-generated/-ag-memory-coverage.md`, currently `no-owner` with `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, and no output path.
- Current supervisor classification: assigned B001 ownership review for an existing no-owner row.
- Current scores and parent state: target is `COMPLETION:85`, `CONFIDENCE:89`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:NONE`, blank emitters.
- Existing report path: `tools/leaser/Agents/Agent-B001/research/0003LQ-TextControlSharedStateAndBorderHelpers.md`.

Current generated row to keep unchanged:

```text
| [UID:0003LQ][0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers](by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md` |  |
```

Current by-memory coverage placement to keep unchanged:

```text
- [UID:00011H] TextEditControlPaneCore
  - [UID:0000VN] 0x00498dc8-0x00498dd0 padding
- [UID:0003LQ] 0x00498dd0-0x00499021 shared helper band
- [UID:0000VN] 0x00499021-0x00499030 padding
- [UID:00011I] StaticTextControlPaneConstructor
```

## Executive Recommendation

Do not assign this target to `TextEditControlPane`, `StaticTextControlPane`, `ExchangeMoneyEditControlPane`, `TextEditPane`, `ControlPane`, or a newly invented `TextControlPane` / `TextControlSharedHelpers` source file. The best current documentation model is a physical by-memory page that captures a real shared compiled helper band while leaving source ownership and output routing unresolved.

This is not a recommendation to mark the target ignored or non-reconstructable. The functions are NexusTK source-authored behavior and should remain reconstructable. The blocker is source-routing confidence: the physical machine-code band cannot yet be mapped to one defensible declaration owner or to a proven multi-emitter output plan.

## Supervisor Active Recheck

Supervisor instruction for this pass: continue and finish B001 research for UID `0003LQ`, considering TextEditControlPane, StaticTextControlPane, ExchangeMoneyEditControlPane, adjacent child pages, vtable families, shared helper/source-file grouping, and negative evidence.

The assigned item did not require split repair before final reporting. The current target page already represents the exact split made from the former TextEdit/StaticText overlap: TextEdit-local code ends before `0x00498dd0`, StaticText constructor starts at `0x00499030`, and `0003LQ` covers the five functions between those boundaries. Live IDA MCP rechecked the function starts, end-exclusive boundaries, padding gaps, and vtable refs.

Every source-bearing child in this narrow scope either already has a separate page or is represented inside `0003LQ` with exact subranges. Creating five new function pages would not improve ownership; each child would still have the same shared vtable ambiguity.

## Inference Research Guidance Check

Applied `inference_research.md` and `by-structure.md` guidance:

- IDA/MCP facts are treated as ground truth for function starts, byte ranges, xrefs, vtable names, and decompilation behavior.
- Existing docs are used as leads and checked against IDA. They mostly agree with the live IDA pass, but no existing doc is treated as proof of source ownership by itself.
- Consumer vtable refs are meaningful evidence of use, but they do not prove declaration ownership.
- Address adjacency to TextEditControlPane is useful but not decisive because StaticTextControlPane and ExchangeMoneyEditControlPane vtables also point at the same functions.
- `CANONICAL_OWNER:NONE` with blank emitters is allowed here because no single direct owner or emitter route is supported strongly enough. This differs from pooled literals/constants with multiple proven source-use emitters: for this target, multiple source-use contexts are plausible but not proven as required emission sites.

Live IDA string evidence found concrete RTTI/type descriptor strings for `TextEditPane`, `TextEditControlPane`, `StaticTextControlPane`, `StaticTextControlPane2`, `ExchangeMoneyEditControlPane`, `ScrolledTextControlPane`, `TextEditObject`, `TextEditScrap`, `EPFTextEditObject`, and `CheckBoxTextControlPane`. The same search found no `TextControlPane`, no `TextControlBase`, and no `.cpp`, `.h`, `.pdb`, `RSDS`, or `NB10` source/debug breadcrumb in the current string cache.

## Evidence Standards Used

- Live IDA MCP session: `b001_0003lq`, opened from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- IDA health: `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, image base `0x400000`.
- Binary survey: 32-bit PE, `.text` `0x00401000-0x0060d000`, `.rdata` `0x0060d670-0x0066d000`, `.data` `0x0066d000-0x0069d000`.
- IDA tools used: `idb_open`, `server_health`, `survey_binary`, `lookup_funcs`, `analyze_component`, `get_bytes`, `entity_query`, `find_regex`, `xrefs_to`, `xref_query`, and `decompile`.
- Documentation checked: target page, adjacent by-memory children, TextEditControlPane/StaticTextControlPane/ExchangeMoneyEditControlPane class and file pages, ControlPane and TextEditPane file pages, ExchangeMoney vtable-data child, `by-memory/-coverage-report.md`, `auto-generated/-ag-memory-coverage.md`, and relevant `proposed-source-tree.md` sections.

## IDA MCP Facts

### Function and Range Facts

| Range | IDA function | Size | Role | Direct xrefs |
| --- | --- | ---: | --- | --- |
| `0x00498dd0-0x00498e0e` | `sub_498DD0` | `0x3e` | Activates/restores wrapper state, calls `sub_5446B0`, sets byte `+0x101`, invalidates through owner vtable slot `+0x20`. | data refs at `0x0061814c`, `0x006181f0`, `0x0061a2b0` |
| `0x00498e10-0x00498e5e` | `sub_498E10` | `0x4e` | Saves embedded child state byte `+0xb5` into wrapper `+0x110`, maps child state through `sub_5446B0(2/3)`, clears byte `+0x101`, invalidates. | data refs at `0x00618150`, `0x006181f4`, `0x0061a2b4` |
| `0x00498e60-0x00498eca` | `sub_498E60` | `0x6a` | Calls `sub_58EA80(0,0)`, gets child bounds via embedded pointer at `+0x10c`, clears byte `+0x102`, invalidates if previously active. | data refs at `0x00618158`, `0x006181fc`, `0x0061a2bc` |
| `0x00498ed0-0x00498f4c` | `sub_498ED0` | `0x7c` | Calls `sub_58EA80(1,1)`, selects range `0-0x7fff` through `sub_58F2A0`, refreshes child bounds, sets byte `+0x102`, invalidates if needed. | data refs at `0x0061815c`, `0x00618200` |
| `0x00498f50-0x00499021` | `sub_498F50` | `0xd1` | If byte `+0x109` is set, draws the older text-control border/highlight using rectangle and drawing helpers. | data refs at `0x00618144`, `0x006181e8`, `0x0061a2a8` |

`analyze_component` reports no internal calls among the five functions, no strings, and only the MSVC `___security_cookie` as shared global access in the three larger functions.

### Data, Table, and Padding Facts

Live `get_bytes` confirms the exact split:

| Range | Bytes |
| --- | --- |
| `0x00498dc8-0x00498dd0` | eight `0xcc` bytes before the target |
| `0x00498e0e-0x00498e10` | two `0xcc` bytes |
| `0x00498e5e-0x00498e60` | two `0xcc` bytes |
| `0x00498eca-0x00498ed0` | six `0xcc` bytes |
| `0x00498f4c-0x00498f50` | four `0xcc` bytes |
| `0x00499021-0x00499030` | fifteen `0xcc` bytes before `sub_499030` |

Neighbor checks:

- `lookup_funcs(0x00498d70)` reports `sub_498D70`, size `0x18`, before the padding that precedes `0003LQ`.
- `lookup_funcs(0x00499030)` reports `sub_499030`, size `0x1bc`, the exact StaticTextControlPane constructor after the padding.
- `lookup_funcs(0x004b0b40)`, `0x004b0b60`, and `0x004b0ba0` report separate ExchangeMoney helper starts outside this target.

### Vtable and Global/Type Facts

`entity_query(kind=names)` identifies the concrete vtable families:

| Base | IDA name |
| --- | --- |
| `0x00618100` | `??_7TextEditControlPane@@6B@` |
| `0x00618168` | `??_7TextEditControlPane@@6B@_0` |
| `0x00618198` | `??_7TextEditControlPane@@6B@_1` |
| `0x006181a4` | `??_7StaticTextControlPane@@6B@` |
| `0x0061820c` | `??_7StaticTextControlPane@@6B@_0` |
| `0x0061823c` | `??_7StaticTextControlPane@@6B@_1` |
| `0x0061a264` | `??_7ExchangeMoneyEditControlPane@?A0x0ff658a5@@6B@` |
| `0x0061a2cc` | `??_7ExchangeMoneyEditControlPane@?A0x0ff658a5@@6B@_0` |
| `0x0061a2fc` | `??_7ExchangeMoneyEditControlPane@?A0x0ff658a5@@6B@_1` |

`xrefs_to` on the vtable bases confirms they are concrete tables installed or restored by concrete class code:

- TextEdit tables are referenced by the small constructor-like body near `0x004988f8/0x004988fe/0x00498908`, full constructor `sub_498920`, non-deleting destructor helper `sub_498B90`, and scalar deleting destructor `sub_49B6C0`.
- StaticText tables are installed by `sub_499030` at `0x004990be`, `0x004990c4`, and `0x004990ce`.
- ExchangeMoney tables are installed by `sub_4AC8A0` at `0x004accd3`, `0x004accd9`, and `0x004acce3`, and restored by `sub_4B0A60` at `0x004b0a66`, `0x004b0a6c`, and `0x004b0a76`.

The slot coverage is not identical:

- `sub_498DD0`, `sub_498E10`, `sub_498E60`, and `sub_498F50` have TextEdit, StaticText, and ExchangeMoney vtable refs.
- `sub_498ED0` has TextEdit and StaticText refs only, with no ExchangeMoney vtable ref in the live `xrefs_to` result.

### Negative IDA Facts

- No ordinary code callers were found for the five function starts; direct refs are vtable/data refs only.
- No source/debug strings were found for a common `TextControlPane`, `TextControlBase`, source file, PDB, or linker/debug metadata.
- No constructor or vtable family for a distinct shared text-control base was found in the checked vtable/name neighborhoods.
- No IDA evidence shows `ExchangeMoneyEditControlPane` owns the whole band; it uses only four of the five helpers and has its own exact wrapper methods at `0x004b0b40` and `0x004b0b60`.
- No IDA evidence shows `ControlPane` owns these helpers; the functions operate on text-wrapper state at offsets `+0x101`, `+0x102`, `+0x109`, `+0x10c`, and `+0x110`, not generic ControlPane-only state.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00498dd0-0x00499021` | [UID:0003LQ] target | Shared physical helper band | TRUE | NONE | `85/89` | Keep no-owner/non-emitting |
| `0x00498dd0-0x00498e0e` | child inside target | activate/show-state helper | TRUE | unresolved | inherited inside target score | No separate split needed |
| `0x00498e10-0x00498e5e` | child inside target | deactivate/save-state helper | TRUE | unresolved | inherited inside target score | No separate split needed |
| `0x00498e60-0x00498eca` | child inside target | inactive child-state helper | TRUE | unresolved | inherited inside target score | No separate split needed |
| `0x00498ed0-0x00498f4c` | child inside target | active/selectable child-state helper | TRUE | unresolved | inherited inside target score | No separate split needed |
| `0x00498f50-0x00499021` | child inside target | optional frame/border paint helper | TRUE | unresolved | inherited inside target score | No separate split needed |
| `0x00498dc8-0x00498dd0` | [UID:0000VN] ignored ledger | padding before target | FALSE | ignored | `100/strong` | Existing coverage ok |
| `0x00499021-0x00499030` | [UID:0000VN] ignored ledger | padding after target | FALSE | ignored | `100/strong` | Existing coverage ok |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00498dd0` | data xrefs `0x0061814c`, `0x006181f0`, `0x0061a2b0` | TextEdit, StaticText, and ExchangeMoney vtable slots |
| `0x00498e10` | data xrefs `0x00618150`, `0x006181f4`, `0x0061a2b4` | TextEdit, StaticText, and ExchangeMoney vtable slots |
| `0x00498e60` | data xrefs `0x00618158`, `0x006181fc`, `0x0061a2bc` | TextEdit, StaticText, and ExchangeMoney vtable slots |
| `0x00498ed0` | data xrefs `0x0061815c`, `0x00618200` | TextEdit and StaticText vtable slots only |
| `0x00498f50` | data xrefs `0x00618144`, `0x006181e8`, `0x0061a2a8` | TextEdit, StaticText, and ExchangeMoney vtable slots |
| `0x00618100/168/198` | refs from TextEdit constructor/destructor paths | Concrete TextEdit vtable installation/restoration |
| `0x006181a4/20c/23c` | refs from StaticText constructor | Concrete StaticText vtable installation |
| `0x0061a264/2cc/2fc` | refs from ExchangeDialog construction and ExchangeMoney destructor | Concrete ExchangeMoney vtable installation/restoration |

## Documentation Evidence And IDA Status

- Target by-memory page: confirms exact five-function range, shared vtable refs, boundary padding, wrapper offsets, and parent blank by design. Live IDA confirms these facts.
- [UID:00011H] `TextEditControlPaneCore`: documents TextEdit-local code ending at `0x00498dd0` and says the old page overran into shared helpers. Live IDA confirms the `0xcc` boundary and TextEdit vtable refs.
- [UID:00011I] `StaticTextControlPaneConstructor`: documents the actual constructor at `0x00499030-0x004991ec` and the prior mixed page split. Live IDA confirms `sub_499030` size `0x1bc` and the padding before it.
- [UID:0000EM] / [UID:0000OM] `TextEditControlPane`: list this band as shared state/border helpers and explicitly avoid exclusive TextEdit ownership after the C001 split. Live IDA supports the shared claim.
- [UID:0000E3] / [UID:0000O8] `StaticTextControlPane`: list this band as related shared helper code, but the constructor/type-id children are separately assigned to StaticText. Live IDA supports the constructor split.
- [UID:00004T] `ExchangeMoneyEditControlPane` and [UID:0003BK] `ExchangeMoneyEditControlPaneVtableData`: classify the target's ExchangeMoney slots as inherited text-edit/control slots. Live IDA supports that ExchangeMoney owns separate wrapper methods at `0x004b0b40` and `0x004b0b60`, not this band.
- [UID:0000IG] `ControlPane`: documents generic base control code and vtables. IDA does not support routing `0003LQ` there because the target relies on embedded text-pane and wrapper bytes absent from generic ControlPane ownership.
- `proposed-source-tree.md`: places `TextEditControlPane.cpp`, `StaticTextControlPane.cpp`, `TextEditPane.cpp`, `ControlPane.cpp`, and `ExchangeDialog.cpp` as separate source modules. This supports rejecting a casual merge into one existing file, but it is source-tree hypothesis, not direct proof.

## Ranked Ownership Analysis

### 1. Keep `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`

Evidence for:

- IDA proves all five functions are vtable-reached shared physical functions, not ordinary callees owned by one local caller.
- Three concrete vtable families use the band: TextEditControlPane, StaticTextControlPane, and ExchangeMoneyEditControlPane.
- The exact source model is ambiguous: inherited common implementation, unmodeled base/mixin, or linker-folded identical virtual implementations are all possible.
- No source/debug names or class metadata identify a common shared owner.
- Blank emitters avoid prematurely generating code into the wrong class/file.

Evidence against:

- The functions are real source-authored logic and eventually need a source representation.
- TextEditControlPane is the strongest address/local-layout lead if the project later decides to force a single source route.

Decision: recommended. This is the only current disposition that preserves the binary facts without overclaiming source ownership or output routing.

### 2. Attach to [UID:0000EM] `TextEditControlPane` / [UID:0000OM] `TextEditControlPane.cpp`

Evidence for:

- The band immediately follows TextEditControlPane local constructor/destructor/accessor/lifecycle code.
- The helpers use the same embedded `TextEditPane*` offset `+0x10c` and wrapper state bytes documented by TextEditControlPane.
- TextEditControlPane's existing file page says the adapter paints the wrapper border and synchronizes wrapper/editor state.

Evidence against:

- StaticTextControlPane installs its own concrete vtables that point at the same bodies.
- ExchangeMoneyEditControlPane vtable data points at four of the five bodies and documents them as inherited text-edit/control slots.
- StaticTextControlPane constructor calls ControlPane/TextEditPane setup directly and installs StaticText vtables; the current IDB does not prove these bodies were TextEdit member functions inherited by StaticText.
- Assigning the physical by-memory page to TextEdit would turn shared vtable evidence into a one-class ownership claim.

Decision: rejected for now. Best forced existing-owner candidate, but still below the source-ownership bar.

### 3. Attach to [UID:0000E3] `StaticTextControlPane` / [UID:0000O8] `StaticTextControlPane.cpp`

Evidence for:

- StaticTextControlPane vtables point at all five functions.
- The StaticText constructor at `0x00499030` uses the same embedded text-pane layout and is immediately adjacent after a padding gap.
- Static text and text effects are a coherent UI-control family in `proposed-source-tree.md`.

Evidence against:

- The band precedes the StaticText constructor and was split out precisely because the previous StaticText page overclaimed it.
- TextEditControlPane and ExchangeMoneyEditControlPane vtables also point at these bodies.
- StaticText owns its constructor and type-id helper separately; those exact children already clear the parent gate.

Decision: rejected as direct owner. StaticText is a confirmed consumer and adjacent family member, not exclusive source owner.

### 4. Create a new shared text-control owner or source file

Possible names if future evidence appears: `TextControlPane`, `TextControlBase`, `TextControlSharedHelpers`, or a private `TextControlHelpers.cpp`.

Evidence for:

- The helper behavior is clearly text-control wrapper behavior, not generic ControlPane behavior.
- A common base or helper source would explain why TextEdit and StaticText vtables share the same state/border functions.
- It would avoid attaching the page to one concrete consumer.

Evidence against:

- Live string/name checks found no `TextControlPane` or `TextControlBase` RTTI/type descriptor.
- No distinct vtable, constructor, source string, or table family for such an owner was found.
- Creating a new source file would be a documentation convenience, not an IDA-backed source inference.
- A shared source file still would not answer whether ExchangeMoney's use is inherited, folded, or intentionally routed.

Decision: reject for this task. Do not create a synthetic owner from design plausibility alone.

### 5. Use multiple `EMITTER_UIDS`

Evidence for:

- Multiple concrete vtables use the same physical functions.
- If the linker folded separate but identical source-level virtual methods, the final reconstructed source might need corresponding methods emitted in more than one class.

Evidence against:

- ICF/folding is only a possibility, not proven.
- If the functions are inherited from a true shared base, multi-emitting them into consumers would be wrong.
- ExchangeMoney does not even use `sub_498ED0`, so a simple `TextEdit + StaticText + ExchangeMoney` multi-emitter list would be inaccurate for the full physical target.
- `EMITTER_UIDS` is output routing, not "all consumers." Current evidence proves consumer vtable slots, not required generated source locations.

Decision: no emitter UIDs are justified. Keep blank until a source-model decision proves one or more output routes.

### 6. Attach to [UID:00004T] `ExchangeMoneyEditControlPane` / [UID:0000J9] `ExchangeDialog.cpp`

Evidence for:

- ExchangeMoney vtable data points at four target functions.
- ExchangeMoney uses text-edit wrapper behavior for a numeric money field.

Evidence against:

- `sub_498ED0` has no ExchangeMoney vtable ref.
- ExchangeMoney owns its exact wrapper/helper methods at `0x004b0b40-0x004b0b54` and `0x004b0b60-0x004b0b96`; those pages are already assigned to ExchangeMoney.
- The ExchangeMoney vtable-data page labels the target slots as inherited text-edit/control slots.

Decision: rejected.

### 7. Attach to [UID:000038] `ControlPane` / [UID:0000IG] `ControlPane.cpp`

Evidence for:

- The helper bodies invalidate control bounds through inherited vtable behavior and draw a control-style frame.
- Several callees are generic UI/rectangle/drawing helpers.

Evidence against:

- The helper state depends on text-wrapper offsets and an embedded text pane pointer at `+0x10c`.
- The target starts long after the documented ControlPane constructor/state helper region and is reached through text control vtables, not ControlPane vtable data.
- ControlPane is a base infrastructure owner and too broad for these text-specific wrappers.

Decision: rejected.

### 8. Attach to [UID:0000EO] / [UID:0000ON] `TextEditPane`

Evidence for:

- The helpers call TextEditPane methods and operate on an embedded TextEditPane child.

Evidence against:

- The receiver layout is the wrapper/control object, not the TextEditPane object.
- The vtable refs are control-wrapper vtables, not TextEditPane vtables.
- TextEditPane owns the rich editor implementation, while this band owns wrapper state and border behavior.

Decision: rejected.

## Proposed New File / Grouping If Future Evidence Changes

No new file/grouping is recommended now.

If later evidence proves a real common text-control base or original helper file, its likely scope should be narrow:

- Include `0x00498dd0-0x00499021` and only other functions proven to share the same text-wrapper state layout and vtable-use pattern.
- Consider related control-family state helpers only after proving they require the same text wrapper fields, not merely because they invalidate panes.
- Do not absorb `TextEditPane.cpp`, `TextEditControlPane.cpp`, `StaticTextControlPane.cpp`, or `ExchangeDialog.cpp`. Existing docs and IDA evidence support those as separate concrete modules.
- Do not include ExchangeMoney-specific wrappers `0x004b0b40` or `0x004b0b60`; those are exact ExchangeMoney children.

This would be a narrow grouping. Current evidence is not strong enough to create it.

## Negative Evidence Summary

- No single concrete class owns all source semantics by IDA evidence.
- No common base/source file name was recovered.
- No ordinary caller pattern identifies a private file-static helper owner.
- No source/debug metadata was found to settle original compilation-unit ownership.
- TextEdit adjacency alone is not enough because StaticText and ExchangeMoney vtable refs are direct and concrete.
- StaticText adjacency alone is not enough because the band precedes the constructor and also appears in TextEdit/ExchangeMoney vtables.
- ExchangeMoney is contradicted by partial slot use and by separate exact ExchangeMoney wrapper children.
- Multi-emitting is not justified because the evidence does not prove duplicate source definitions versus inherited/folded implementations.

## Final Recommendation

Keep the target exactly as it is:

- `RECONSTRUCTABLE:TRUE`
- `CANONICAL_OWNER:NONE`
- `EMITTER_UIDS:` blank
- `EMITTER_POSITION_OPTIONAL:` blank
- `RECONSTRUCTION_CPP CODE` blank
- by-memory coverage placement unchanged
- auto-generated no-owner row unchanged

No by-memory split is required. The five functions are already inventoried inside the page, and splitting them would produce five smaller parentless rows without improving source ownership.

No by-file, by-class, by-type, by-global, or by-memory parent/source repair is required by this B001 task. The adjacent TextEdit and StaticText split repair already exists and remains correct.

## Follow-Up Actions

- Supervisor: no row edit required. Optionally mark B001-0003LQ as no-owner/non-emitting confirmed.
- A-agents: do not attach `0003LQ` to TextEditControlPane, StaticTextControlPane, ExchangeMoneyEditControlPane, ControlPane, or TextEditPane without new evidence.
- A-agents: if future class-hierarchy work proves a shared base or true inherited implementation, revisit `CANONICAL_OWNER` and `EMITTER_UIDS` together. Do not treat consumer vtable refs alone as emitter proof.
- B001 future research: related shared virtual helper families such as [UID:0002PD] `ControlFamilyStateVirtualHelpers` may need similar owner/emitter review, but that is outside this assigned target.

## Confidence

- Recommendation confidence: `88/100`.
- Boundary confidence: `94/100`, based on function sizes and padding bytes.
- Vtable-use confidence: `90/100`, based on `xrefs_to` and named table bases.
- Behavior confidence: `86/100`, based on decompilation and callees.
- Source-owner confidence for any single positive owner: below action threshold. TextEditControlPane is the best forced candidate at about `55/100`; StaticTextControlPane about `42/100`; new shared base/helper about `60/100` as a design possibility but lower as an actionable documentation owner because it lacks name/vtable/source evidence.
- Remaining uncertainty: original source may have had a real shared base/helper, inherited concrete methods, or separate folded methods. Current stripped binary evidence does not distinguish those enough to route output.

## Validator Results

- Validator was not run. No by-* documentation, generated report, project-level report, or validator-managed page was edited.
- No dry-run validator mode or memory-range mode was used.
- This report-only edit is inside `tools/leaser/Agents/Agent-B001/research`, which B001 instructions say does not require a lease.

## Command / Evidence Log

- Read required B001 goal, `by-structure.md`, `inference_research.md`, and relevant proposed-source-tree sections.
- Read target and related docs listed in this report.
- `tools/list`: confirmed MCP tool availability.
- `idb_list`: old session record existed but was unreachable.
- `idb_open` with preferred session `b001_0003lq`: opened `NexusTK.exe`, initialized caches and Hex-Rays, health ok.
- `server_health`: analysis ready, Hex-Rays ready, string cache ready.
- `survey_binary(detail_level='minimal')`: confirmed binary/segment metadata.
- `lookup_funcs`: confirmed target five functions, neighbor `sub_498D70`, StaticText constructor `sub_499030`, and ExchangeMoney helper starts.
- `analyze_component`: confirmed no internal call graph, no strings, callees, and security-cookie-only shared global.
- `get_bytes`: confirmed all target boundary and internal padding bytes.
- `entity_query(kind='names')`: confirmed TextEdit, StaticText, and ExchangeMoney concrete vtable names.
- `find_regex`: found concrete text-control RTTI strings but no shared owner/source/debug strings.
- `xrefs_to` / `xref_query`: confirmed data refs from concrete vtable cells and vtable-base install/restore refs.
- `decompile`: inspected all five target functions plus StaticText constructor to verify behavior and touched state.

## Changed Files

- Modified: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\0003LQ-TextControlSharedStateAndBorderHelpers.md`
- Created: none
- Renamed: none
- Moved to executed: none

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003LQ","source_path":"executed-b-agent-research/B001/0003LQ-TextControlSharedStateAndBorderHelpers.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
