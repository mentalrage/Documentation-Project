** TARGET-REPORT-UID:0003LQ **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003LQ **
# 0003LQ TextControlSharedStateAndBorderHelpers Second-Pass Ownership / Split / Emitter Research

Revision: Agent-B001 second-pass final report, 2026-06-13.

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003LQ] `by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md` exactly as a reconstructable shared physical helper band with `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank reconstruction C++.
- Final disposition: no owner assignment, no emitter assignment, no reclassification, no split, no merge, and no parent/source repair required by the current evidence.
- Exact metadata recommendation:

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Score recommendation: no score change. Before `85/89`; after second-pass review `85/89`. The binary boundaries and behavior are well supported, but source routing is still unresolved, so raising completion/confidence would overstate the owner/emitter state.
- Coverage report action: no `by-memory/-coverage-report.md` edit is needed. The existing coverage row remains correct.
- Confidence: `89/100` for this no-owner/non-emitting recommendation; `95/100` for physical range and vtable-pointer facts; `86/100` for behavior; below action threshold for any positive source owner or emitter route.

Under the current owner/emitter model, this is not a pooled-literal multiple-emitter case. `CANONICAL_OWNER` asks for the semantic source owner. `EMITTER_UIDS` asks where reconstructed output should be generated. The evidence proves vtable consumers across TextEditControlPane, StaticTextControlPane, and ExchangeMoneyEditControlPane; it does not prove that the original source had duplicate definitions that must be emitted in each consuming class/file. A shared base/mixin implementation, inherited concrete method, or linker-folded identical bodies all remain plausible. Multi-emitting this whole page would also over-route `0x00498ed0`, which is not referenced by the ExchangeMoney vtable cells.

## Supporting Research

## Target

- Target UID: `0003LQ`
- Target path: `by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md`
- Current source row: `auto-generated/-ag-memory-coverage.md`, current no-owner row with `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, and no output path.
- Tracker assignment: `B001-0003LQ-second-pass`.
- Prior report reviewed: `tools/leaser/Agents/Agent-B001/research/executed/0003LQ-TextControlSharedStateAndBorderHelpers.md`.
- Current target state: `COMPLETION:85`, `CONFIDENCE:89`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`.

Current generated memory-coverage row, kept unchanged:

```text
| [UID:0003LQ][0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers](by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md` |  |
```

Current `by-memory/-coverage-report.md` row, kept unchanged:

```text
    - [UID:0003LQ][0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers](by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md) 0x00498dd0-0x00499021 | shared method cluster | TextControlSharedStateAndBorderHelpers : reconstructable : 85% : strong : New C001 exact shared helper page for five vtable-only state/border helpers; live IDA confirms function starts/sizes, refs from TextEditControlPane, StaticTextControlPane, and ExchangeMoneyEditControlPane vtable cells, internal 0xcc padding, and parent blank by design until a single source-level shared owner is proven.
```

Placement context remains:

```text
- [UID:00011H] 0x004988d0-0x00498dd0.TextEditControlPaneCore
- [UID:0000VN] 0x00498dc8-0x00498dd0 padding
- [UID:0003LQ] 0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers
- [UID:0000VN] 0x00499021-0x00499030 padding
- [UID:00011I] 0x00499030-0x004991ec.StaticTextControlPaneConstructor
```

## Executive Recommendation

Keep `0003LQ` no-owner and non-emitting. The target is source-authored NexusTK project code and should remain reconstructable, but it is not ready for source output because neither a single direct owner nor a multi-emitter output route clears the by-structure evidence gate.

If forced to name the best existing owner candidate, [UID:0000EM] `TextEditControlPane` / [UID:0000OM] `TextEditControlPane.cpp` is the least-bad route because of address adjacency, layout reuse, and ExchangeMoney's TextEdit constructor/destructor reuse. It still does not clear the action bar because `StaticTextControlPane` constructs its own wrapper and installs concrete vtables that point at the same helper bodies. A forced TextEdit route would convert consumer/inheritance evidence into an unproven source-owner claim.

Do not create a synthetic `TextControlPane`, `TextControlBase`, or `TextControlSharedHelpers` owner from design plausibility alone. The second pass found no RTTI/type descriptor, constructor, vtable family, source/debug breadcrumb, or documentation-backed file scope for such an owner.

## Supervisor Active Recheck

The supervisor requested a fresh second-pass review under the current separated owner/emitter system and specifically asked whether multi-emitter semantics change the prior recommendation. They do not.

The assigned item did not require split repair before final reporting. The existing page is already the split repair for the former TextEdit/StaticText crossing: TextEdit-local code ends before `0x00498dd0`, the StaticText constructor starts at `0x00499030`, and this page covers the five real functions between them. Splitting those five functions into separate pages would not solve ownership. It would create smaller no-owner function pages with the same source-model ambiguity; for the one function not referenced by ExchangeMoney, a split would actually highlight that page-level multi-emitter routing is unsafe.

The current 90/90+ reconstruction-code entry gate does not change this recommendation. The target is still `85/89`, owner/emitter placement is unresolved, function names are not source-stable, and B-agent reports must not write final reconstruction C++ directly.

## Inference Research Guidance Check

`by-structure.md` and B001 inference guidance were applied as follows:

- Facts: IDA MCP and raw PE evidence are used for function boundaries, padding, vtable pointer cells, constructor/destructor vtable writes, callees, and byte-level pointer counts.
- Documentation evidence: existing by-class, by-file, by-memory, proposed-source-tree, generated coverage, and prior B001/C001 reports are treated as leads and checked against IDA evidence.
- Inference: ownership and emitter routing are assessed from competing source models. Vtable consumers are weighed as evidence of use, not direct proof of output location.
- Multi-emitter rule: multiple emitters can be correct for pooled literals/shared constants with proven source-use contexts. This target is different because it is a group of virtual method bodies where the same compiled function may represent inherited implementation, a hidden shared base/helper, or linker-folded duplicate methods.

Existing documentation assumptions treated as uncertain:

- TextEdit adjacency is not enough to prove TextEdit source ownership.
- StaticText adjacency is not enough to prove StaticText source ownership.
- ExchangeMoney vtable use is not enough to prove ExchangeDialog source ownership.
- The absence of a modeled shared base does not justify inventing one without IDA/source evidence.

## Evidence Standards Used

Evidence reviewed in this pass:

- Live IDA MCP facts from the target and related functions: `lookup_funcs`, `get_bytes`, `xrefs_to`, `entity_query`, `analyze_component`, and Hex-Rays decompilation observations.
- Raw PE byte scan of absolute function-pointer values in `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Current target page and prior executed B001 report.
- Related docs:
  - [UID:0000EM] `by-class/TextEditControlPane.md`
  - [UID:0000OM] `by-file/TextEditControlPane.md`
  - [UID:0000E3] `by-class/StaticTextControlPane.md`
  - [UID:0000O8] `by-file/StaticTextControlPane.md`
  - [UID:00004T] `by-class/ExchangeMoneyEditControlPane.md`
  - [UID:0000J9] `by-file/ExchangeDialog.md`
  - [UID:0000IG] `by-file/ControlPane.md`
  - [UID:0000ON] `by-file/TextEditPane.md`
  - `by-project-structure/proposed-source-tree.md`
  - `auto-generated/-ag-memory-coverage.md`
  - `by-memory/-coverage-report.md`

## IDA MCP Facts

### Function and Range Facts

| Range | IDA function | Size | Role | Direct vtable/data refs |
| --- | --- | ---: | --- | --- |
| `0x00498dd0-0x00498e0e` | `sub_498DD0` | `0x3e` | Activates/restores wrapper display state, calls `sub_5446B0`, sets wrapper byte `+0x101`, invalidates through owner vtable slot `+0x20`. | `0x0061814c`, `0x006181f0`, `0x0061a2b0` |
| `0x00498e10-0x00498e5e` | `sub_498E10` | `0x4e` | Saves embedded child state byte `+0xb5` into wrapper state `+0x110`, maps state through `sub_5446B0(2/3)`, clears wrapper byte `+0x101`, invalidates. | `0x00618150`, `0x006181f4`, `0x0061a2b4` |
| `0x00498e60-0x00498eca` | `sub_498E60` | `0x6a` | Applies inactive embedded text-pane state, refreshes child bounds, clears wrapper byte `+0x102`, invalidates if previously active. | `0x00618158`, `0x006181fc`, `0x0061a2bc` |
| `0x00498ed0-0x00498f4c` | `sub_498ED0` | `0x7c` | Applies active/selectable embedded text-pane state, selects range `0-0x7fff`, refreshes child bounds, sets wrapper byte `+0x102`, invalidates if needed. | `0x0061815c`, `0x00618200` |
| `0x00498f50-0x00499021` | `sub_498F50` | `0xd1` | Draws optional older text-control border/highlight when wrapper byte `+0x109` is set. | `0x00618144`, `0x006181e8`, `0x0061a2a8` |

IDA `analyze_component` reports no internal call graph among the five target functions and no string literals. Shared global use is limited to the MSVC security cookie in the larger functions.

### Boundary and Padding Facts

`get_bytes` confirms the exact function band and padding:

| Range | IDA/raw bytes |
| --- | --- |
| `0x00498dc8-0x00498dd0` | eight `0xcc` bytes before the target |
| `0x00498e0e-0x00498e10` | two `0xcc` bytes |
| `0x00498e5e-0x00498e60` | two `0xcc` bytes |
| `0x00498eca-0x00498ed0` | six `0xcc` bytes |
| `0x00498f4c-0x00498f50` | four `0xcc` bytes |
| `0x00499021-0x00499030` | fifteen `0xcc` bytes before StaticText constructor |

Neighbor facts:

- `lookup_funcs(0x00498d70)` reports `sub_498D70`, size `0x18`, before the padding that precedes `0003LQ`.
- `lookup_funcs(0x00499030)` reports `sub_499030`, size `0x1bc`, the StaticText constructor after the target.
- `lookup_funcs(0x004b0b40)`, `0x004b0b60`, and `0x004b0ba0` report separate ExchangeMoney helper starts outside this target.

### Vtable and Constructor/Destructor Facts

IDA names the concrete vtable families:

| Address | IDA name |
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

Constructor/destructor evidence:

- TextEdit vtables are referenced by TextEdit construction/destruction paths including the local constructor-like body around `0x004988f8/0x004988fe/0x00498908`, `sub_498920`, `sub_498B90`, and scalar deleting destructor `sub_49B6C0`.
- StaticText vtables are installed by `sub_499030` at `0x004990be`, `0x004990c4`, and `0x004990ce`.
- ExchangeMoney vtables are installed by `sub_4AC8A0` at `0x004accd3`, `0x004accd9`, and `0x004acce3`, after that constructor path calls the TextEditControlPane constructor `sub_498920` for the embedded money edit control.
- ExchangeMoney vtables are restored by `sub_4B0A60` at `0x004b0a66`, `0x004b0a6c`, and `0x004b0a76`, and then the TextEdit cleanup helper `sub_498B90` is called.

Important source-model implication:

- ExchangeMoney strongly looks like a private TextEdit-derived wrapper because it calls the TextEdit constructor and cleanup helper, then overrides vtables.
- StaticText does not simply call `sub_498920`. Its constructor `sub_499030` directly calls the common ControlPane setup and creates a TextEditPane child, then installs StaticText vtables. That prevents a simple "TextEdit owns these and everyone inherits them" conclusion.

### Raw PE Pointer Facts

Raw scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` confirms IDA's vtable-pointer counts. Image base is `0x00400000`.

| Pointer value | Raw count | Mapped hit VAs |
| --- | ---: | --- |
| `0x00498dd0` | 3 | `0x0061814c`, `0x006181f0`, `0x0061a2b0` |
| `0x00498e10` | 3 | `0x00618150`, `0x006181f4`, `0x0061a2b4` |
| `0x00498e60` | 3 | `0x00618158`, `0x006181fc`, `0x0061a2bc` |
| `0x00498ed0` | 2 | `0x0061815c`, `0x00618200` |
| `0x00498f50` | 3 | `0x00618144`, `0x006181e8`, `0x0061a2a8` |

RVA-literal scans for `0x00098dd0`, `0x00098e10`, `0x00098e60`, `0x00098ed0`, and `0x00098f50` found zero hits. This supports the interpretation that the known direct references are absolute vtable pointer cells, not hidden code operands.

### Negative IDA Facts

- No ordinary call xrefs to the five function starts were found; the refs are vtable/data refs.
- No common `TextControlPane`, `TextControlBase`, `TextControlSharedHelpers`, source-file, PDB, `RSDS`, or `NB10` breadcrumb was found in the checked string/name evidence.
- No modeled constructor/vtable family for a distinct shared text-control base was found near the checked vtable neighborhoods.
- `sub_498ED0` lacks an ExchangeMoney vtable ref, so ExchangeMoney is not a whole-page consumer.
- No evidence shows `ControlPane` owns this target; the target touches text-wrapper fields and embedded TextEditPane state beyond generic ControlPane behavior.
- No evidence shows `TextEditPane` owns this target; the receiver is the wrapper/control object, and vtable refs are wrapper vtables.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00498dd0-0x00499021` | [UID:0003LQ] target | Shared physical helper band | TRUE | NONE | `85/89` | Keep no-owner/non-emitting |
| `0x00498dd0-0x00498e0e` | included in target | activate/show-state helper | TRUE | unresolved | included in `85/89` | No split needed |
| `0x00498e10-0x00498e5e` | included in target | deactivate/save-state helper | TRUE | unresolved | included in `85/89` | No split needed |
| `0x00498e60-0x00498eca` | included in target | inactive child-state helper | TRUE | unresolved | included in `85/89` | No split needed |
| `0x00498ed0-0x00498f4c` | included in target | active/selectable child-state helper | TRUE | unresolved | included in `85/89` | No split needed |
| `0x00498f50-0x00499021` | included in target | optional border/highlight paint helper | TRUE | unresolved | included in `85/89` | No split needed |
| `0x00498dc8-0x00498dd0` | [UID:0000VN] ignored ledger | padding before target | FALSE | ignored | `100/strong` | Existing coverage ok |
| `0x00499021-0x00499030` | [UID:0000VN] ignored ledger | padding after target | FALSE | ignored | `100/strong` | Existing coverage ok |

## Direct Xref / Source-Use Inventory

| Address / Item | Fact | Meaning |
| --- | --- | --- |
| `0x00498dd0` | refs `0x0061814c`, `0x006181f0`, `0x0061a2b0` | TextEdit, StaticText, ExchangeMoney vtable cells |
| `0x00498e10` | refs `0x00618150`, `0x006181f4`, `0x0061a2b4` | TextEdit, StaticText, ExchangeMoney vtable cells |
| `0x00498e60` | refs `0x00618158`, `0x006181fc`, `0x0061a2bc` | TextEdit, StaticText, ExchangeMoney vtable cells |
| `0x00498ed0` | refs `0x0061815c`, `0x00618200` | TextEdit and StaticText vtable cells only |
| `0x00498f50` | refs `0x00618144`, `0x006181e8`, `0x0061a2a8` | TextEdit, StaticText, ExchangeMoney vtable cells |
| `sub_498920` | constructs TextEditControlPane-style wrapper and embedded TextEditPane | Strong TextEdit local-layout lead |
| `sub_499030` | independently constructs StaticText wrapper and embedded TextEditPane | Strong evidence against TextEdit-only ownership |
| `sub_4AC8A0` | constructs ExchangeMoney money edit by calling TextEdit constructor then overwriting vtables | ExchangeMoney is likely derived/private wrapper consumer |
| `sub_4B0A60` | restores ExchangeMoney vtables and calls TextEdit cleanup helper | ExchangeMoney reuse confirmed, but not whole-page ownership |

## Documentation Evidence And IDA Status

- Target page `by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md`: documents exact five-function range, shared vtable refs, boundary padding, touched wrapper offsets, and blank parent by design. Live IDA and raw PE evidence confirm those facts.
- [UID:00011H] `0x004988d0-0x00498dd0.TextEditControlPaneCore`: documents TextEdit-local code ending before `0003LQ`. IDA confirms the boundary and padding before `0x00498dd0`.
- [UID:00011I] `0x00499030-0x004991ec.StaticTextControlPaneConstructor`: documents StaticText constructor after this band. IDA confirms `sub_499030` starts at `0x00499030`.
- [UID:0000EM] / [UID:0000OM] `TextEditControlPane`: current docs already treat this band as shared with StaticText and ExchangeMoney. IDA confirms TextEdit is a real consumer and strong candidate, but not exclusive owner.
- [UID:0000E3] / [UID:0000O8] `StaticTextControlPane`: current docs list this band as related shared helper code while keeping StaticText constructor/type-id children separate. IDA confirms StaticText's concrete vtable refs and constructor split.
- [UID:00004T] `ExchangeMoneyEditControlPane` / [UID:0000J9] `ExchangeDialog`: docs identify ExchangeMoney-specific wrapper helpers separately. IDA confirms those local helpers and confirms ExchangeMoney vtable use of four target functions.
- [UID:0000IG] `ControlPane`: docs establish the generic base control family. IDA does not support routing `0003LQ` to ControlPane because the target uses text-wrapper state and embedded TextEditPane child behavior.
- [UID:0000ON] `TextEditPane`: docs establish rich editor implementation. IDA does not support routing `0003LQ` to TextEditPane because the target receiver is a wrapper object, not the embedded pane.
- `proposed-source-tree.md`: lists separate `TextEditControlPane.cpp`, `StaticTextControlPane.cpp`, `TextEditPane.cpp`, `ControlPane.cpp`, and `ExchangeDialog.cpp` modules. It does not list a confirmed common text-control helper file.

## Ranked Ownership and Routing Analysis

### 1. Keep `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`

Evidence for:

- IDA and raw PE evidence prove the same physical function bodies are vtable-reached from multiple concrete text-control families.
- The source model remains ambiguous: common inherited implementation, unmodeled base/mixin, and linker-folded duplicate virtual methods all fit the binary facts.
- No common source owner name, constructor, vtable, RTTI/type descriptor, source string, PDB, or debug breadcrumb was found.
- A page-level multi-emitter route would be inaccurate because `sub_498ED0` has TextEdit/StaticText refs only and no ExchangeMoney ref.
- Leaving output routing blank prevents generating the same virtual methods into one or more incorrect classes.

Evidence against:

- The functions are real source-authored behavior, not compiler padding or runtime code.
- The final reconstructed project eventually needs a source representation for these virtual behaviors.
- TextEditControlPane remains a plausible forced route if a future policy decides to prefer inherited-concrete implementation over no-owner.

Decision: recommended. This is the only route that preserves known facts without converting ambiguous vtable consumption into a source-output claim.

### 2. Assign [UID:0000EM] `TextEditControlPane` / [UID:0000OM] `TextEditControlPane.cpp`

Evidence for:

- The band immediately follows TextEditControlPane-local code.
- The functions use the same wrapper layout, embedded `TextEditPane*` pointer at `+0x10c`, and state bytes used by the TextEdit wrapper.
- ExchangeMoney construction calls `sub_498920` and ExchangeMoney cleanup calls `sub_498B90`, supporting a TextEdit-derived ExchangeMoney wrapper model.

Evidence against:

- StaticText has concrete vtable cells pointing at all five functions.
- StaticText constructor `sub_499030` directly builds a wrapper/TextEditPane pair and installs StaticText vtables instead of simply calling `sub_498920`.
- No IDA source metadata proves these are TextEdit member functions inherited by StaticText.
- Assigning the whole band to TextEdit would overclaim a shared physical band as a one-class source declaration.

Decision: best forced existing candidate, but rejected as not evidence-backed enough to apply.

### 3. Assign [UID:0000E3] `StaticTextControlPane` / [UID:0000O8] `StaticTextControlPane.cpp`

Evidence for:

- StaticText vtables reference all five functions.
- StaticText constructor is adjacent after the target and uses the same embedded text-pane layout.

Evidence against:

- The band precedes the StaticText constructor and was split out specifically because the previous StaticText page overclaimed it.
- TextEdit and ExchangeMoney vtables also reference this band.
- StaticText exact constructor/type-id pages already carry the StaticText-specific ownership; this shared helper band is not exact StaticText-local code.

Decision: rejected. StaticText is a confirmed consumer, not a proven direct owner.

### 4. Assign [UID:00004T] `ExchangeMoneyEditControlPane` / [UID:0000J9] `ExchangeDialog.cpp`

Evidence for:

- ExchangeMoney vtable data references four of the five functions.
- ExchangeMoney constructor/destructor paths prove it is a concrete source-use context for TextEdit-style wrapper behavior.

Evidence against:

- `sub_498ED0` has no ExchangeMoney vtable cell.
- ExchangeMoney-specific local helpers are separate exact children at `0x004b0b40-0x004b0b54`, `0x004b0b60-0x004b0b96`, and nearby return-true helper coverage.
- ExchangeMoney is a feature-local private wrapper and cannot own the shared TextEdit/StaticText helper band.

Decision: rejected.

### 5. Use multiple `EMITTER_UIDS`

Candidate lists considered:

- `EMITTER_UIDS:0000OM,0000O8`
- `EMITTER_UIDS:0000OM,0000O8,0000J9`
- Class-level variants using `0000EM`, `0000E3`, and `00004T`

Evidence for:

- More than one concrete source-use context is real at the vtable level.
- If the linker folded separate but identical virtual methods, reconstruction might eventually need methods emitted in more than one class/file.

Evidence against:

- Linker folding is only one possible source model. A true shared base or inherited implementation would require one output home, not one per consumer.
- `EMITTER_UIDS` is output routing, not a list of all vtable consumers.
- The whole target page is not consumed uniformly: ExchangeMoney lacks the `0x00498ed0` slot.
- Current documentation has no source-level declaration evidence proving that StaticText and TextEdit each authored separate methods.
- Multiple emitters would create source-output obligations that the binary evidence does not actually prove.

Decision: rejected. Keep `EMITTER_UIDS` blank. The valid future path is to first prove the source model, then set either one source emitter or function-specific split/emitter routes if that future proof requires it.

### 6. Create a new shared helper/base owner

Possible names if future evidence appears:

- `TextControlPane`
- `TextControlBase`
- `TextControlSharedHelpers`
- `TextControlHelpers.cpp`

Evidence for:

- A common text-wrapper source owner would explain why TextEdit and StaticText vtables share these state and border helpers.
- The functions are text-wrapper specific and are not generic ControlPane or TextEditPane internals.

Evidence against:

- No IDA name, RTTI/type descriptor, constructor, vtable, source string, or proposed-source-tree entry supports this owner.
- Creating a new source file would be a design convenience, not an evidence-backed source inference.
- The possible scope would be narrow and currently limited to this exact band; no additional nearby helper set was proven to belong.

Decision: rejected for this assignment. If future evidence proves such an owner, it should be narrow and should exclude TextEditPane implementation, concrete TextEdit/StaticText constructors, and ExchangeMoney-specific wrappers.

### 7. Assign `ControlPane` or `TextEditPane`

ControlPane evidence:

- The functions invalidate/draw control rectangles and use inherited pane drawing infrastructure.

ControlPane rejection:

- They operate on text-wrapper bytes and an embedded text pane pointer, not generic ControlPane-only state.

TextEditPane evidence:

- The helpers call embedded TextEditPane methods.

TextEditPane rejection:

- The receiver layout is the wrapper/control object, and refs are wrapper vtables. TextEditPane is a child dependency, not the direct owner.

Decision: both rejected.

## Negative Evidence Summary

- No single concrete class is proven to own the source semantics for the full physical band.
- No common base/helper source owner is named or modeled by IDA.
- No ordinary caller pattern identifies a private file-static helper owner.
- No source/debug metadata settles original compilation-unit ownership.
- TextEdit adjacency is useful but contradicted by StaticText's concrete constructor/vtable use.
- StaticText adjacency is useful but contradicted by TextEdit and ExchangeMoney vtable use.
- ExchangeMoney is partial and feature-local; it does not reference one of the five functions.
- Multi-emitter routing is not justified because vtable consumers are not source-output proof.

## Final Recommendation

Exact recommended state:

- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `CANONICAL_OWNER:NONE`.
- Keep `EMITTER_UIDS:` blank.
- Keep `EMITTER_POSITION_OPTIONAL:` blank.
- Keep reconstruction C++ blank.
- Keep current `85/89` score.
- Keep existing coverage and generated rows unchanged.
- Do not split the target now.
- Do not edit `by-memory/-coverage-report.md`.

This is a valid reconstructable no-owner/non-emitting state because the functions are real source-authored behavior but current evidence does not identify a correct source-output route. It is not a dead-code/non-reconstructable state and should not be reclassified as compiler-generated.

## Follow-Up Actions

- Supervisor: no coverage-report action is required. Mark B001-0003LQ-second-pass as "confirmed no-owner/non-emitting, no row edit."
- A-agents: do not attach `0003LQ` to TextEditControlPane, StaticTextControlPane, ExchangeMoneyEditControlPane, ControlPane, or TextEditPane from current evidence alone.
- Future owner work: revisit only if new class-hierarchy/source evidence proves a shared text-control base, inherited method implementation, or function-specific linker-folding/source-output model.
- Future split work: split into individual function pages only if that future evidence requires function-specific emitter routing. Current evidence does not justify split churn.

## Confidence

- Recommendation confidence: `89/100`.
- Boundary confidence: `95/100`.
- Vtable/data reference confidence: `95/100` after IDA and raw PE corroboration.
- Behavior confidence: `86/100`.
- Source-owner confidence for positive routes:
  - TextEditControlPane: `58/100`, best forced candidate but below action.
  - New shared helper/base owner: `55/100` as design inference, below action due lack of concrete evidence.
  - StaticTextControlPane: `42/100`.
  - ExchangeMoneyEditControlPane: `25/100` for whole page.
  - ControlPane/TextEditPane: below `25/100`.
- Remaining uncertainty: original source could have used a real shared base/helper, inherited TextEdit implementation, or separate methods later folded to one physical address. Current stripped binary evidence does not distinguish those enough to route output.

## Validator Results

- Validator was not run. No by-* documentation, generated report, project-level report, or validator-managed target page was edited.
- No dry-run validator mode was used.
- No memory-range validator mode was used.
- No lease was required because the only created file is this B001 research report under `tools/leaser/Agents/Agent-B001/research`.

## Command / Evidence Log

- Read `tools/leaser/Agents/Agent-B001/goal.md`.
- Read prior executed report `tools/leaser/Agents/Agent-B001/research/executed/0003LQ-TextControlSharedStateAndBorderHelpers.md`.
- Read current target page `by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md`.
- Reviewed current `by-structure.md` owner/emitter rules and B001 `inference_research.md` guidance.
- Reviewed current generated rows in `auto-generated/-ag-memory-coverage.md` and current row in `by-memory/-coverage-report.md`.
- Reviewed related TextEditControlPane, StaticTextControlPane, ExchangeMoneyEditControlPane, ControlPane, TextEditPane, ExchangeDialog, and proposed-source-tree documentation.
- Used IDA MCP evidence from live NexusTK IDB to confirm function starts/sizes, padding bytes, vtable refs, constructor/destructor vtable stores, callees, and decompilation behavior.
- Ran raw PE absolute pointer scan of `NexusTK.exe`; results matched IDA vtable refs exactly, including two refs only for `0x00498ed0`.

## Changed Files

- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\0003LQ-TextControlSharedStateAndBorderHelpers-second-pass.md`
- Modified: none outside this report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003LQ","source_path":"executed-b-agent-research/B001/0003LQ-TextControlSharedStateAndBorderHelpers-second-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
