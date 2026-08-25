*** UID:00009L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct InputKeyEvent;

class NumberInputPane : public LineInputPane
{
public:
    NumberInputPane(const wchar_t *promptText);
    virtual bool OnKeyInput(InputKeyEvent *event);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NumberInputPane

## B003 2026-07-20 Inherited Event Signature Synchronization

- The inherited/shared source signature is `bool HandleKeyOrTextEvent(Event *event)` through LineInputPane. NumberInputPane's independent numeric filter remains exactly its documented vtable override and algorithm; it is not owned by UID000364 and is not rewritten as CharInputPane behavior.
- Historical `InputEvent`/`OnKeyInput`/raw key-handler links are source-vocabulary provenance only. Scores, route, formal declaration/body, numeric acceptance rules, constructors, vtables, children, and unrelated history remain unchanged.

## Status

- Confidence: strong for class role and IDA boundaries.
- Likely source file: [UID:0000K7][InputPanes](by-file/InputPanes.md)
- Main address range: [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- Vtables: [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- Compiler adjustors: secondary/tertiary destructor slots reuse the LineInputPane-family entries in [UID:00018Z][0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md); they are ABI glue, not custom `NumberInputPane` destructor bodies.
- Current recovered file: `source-3/simroot_v2/class_NumberInputPane.cpp`
- Autogen status: reconstructable class attached to [UID:0000K7][InputPanes](by-file/InputPanes.md); formal declaration shell now emits through the active code gate. The older `95/95` blank-C++ blocker is historical only; constructor and key-filter bodies remain on exact by-memory child pages.

## Class Purpose

`NumberInputPane` is a numeric-only [UID:000077][LineInputPane](by-class/LineInputPane.md) variant. It disables free text input and filters key-down events so digits are converted to translated character events while control keys pass through to the base handler.

## Class Evidence

| Evidence | Meaning |
| --- | --- |
| Constructor range `0x004f27a0-0x004f2812` | Builds the `LineInputPane` base and installs the `NumberInputPane` three-vtable family. |
| Key filter range `0x004f2820-0x004f289a` | Numeric-only input handler; accepts digits and control keys before forwarding to the base handler. |
| Vtable bases `0x0061cae4`, `0x0061cb34`, `0x0061cb64` | IDA-confirmed primary, secondary, and tertiary tables in [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md). |
| Vtable slot secondary `+0x08 -> 0x004f2820` | Confirms the numeric filter is the derived key-input override. |
| Secondary/tertiary destructor slots `0x004f2e59` and `0x004f2e64` | Reuse the LineInputPane-family scalar deleting destructor adjustors from [UID:00018Z][0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md); no independent source destructor body is present in that range. |
| Aggregate range [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md) | Places constructor/filter with the reusable input-pane base family, not feature-specific item or command input files. |

## Consumer Evidence

| Consumer | Evidence |
| --- | --- |
| [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md) | Raw constructor calls the `NumberInputPane` constructor at `0x004f27a0` after resolving prompt id `7`. |
| [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md) | Raw constructor calls the `NumberInputPane` constructor at `0x004f27a0` after resolving prompt id `43`. |
| [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) | Feature-specific item/gold prompts derive from this base but should not own the reusable numeric input class. |

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x004f27a0-0x004f2812` | constructor | Builds `LineInputPane`, installs numeric input vtables, and disables active edit input. |
| `0x004f2820-0x004f289a` | `HandleKeyInput` | Allows digits and control keys; forwards accepted events to `LineInputPane::HandleKeyInput`. |

## B001-042 Exact Split Evidence

The constructor and key-filter bodies now have exact child pages: [UID:000361][0x004f27a0-0x004f2813.NumberInputPaneConstructor](by-memory/0x004f27a0-0x004f2813.NumberInputPaneConstructor.md) and [UID:000362][0x004f2820-0x004f289b.NumberInputPaneKeyFilter](by-memory/0x004f2820-0x004f289b.NumberInputPaneKeyFilter.md). Live IDA checks confirm the constructor calls the `LineInputPane` base constructor, installs the `NumberInputPane` primary/secondary/tertiary vtables, disables free text editing on the edit child, and the key filter accepts digit/control keys before delegating to [UID:00035Y][0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput](by-memory/0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md). The class now clears the `85/85` direct-parent gate for both children.

## Cross-References

- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- [UID:00018Z][0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md)
- [UID:000077][LineInputPane](by-class/LineInputPane.md)
- [UID:00009J][NumberArgsInputPane](by-class/NumberArgsInputPane.md)
- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md)
- [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md)

## Changes

- 2026-07-01 Agent-B011 [UID:0000K7][InputPanes](by-file/InputPanes.md) empty-emitter implementation: raised from `86/88` to `88/90` and inserted the accepted formal `NumberInputPane : public LineInputPane` declaration shell with `OnKeyInput` and `[[CHILDREN]]`. Preserved constructor/key-filter evidence; old `95/95` no-code text is historicalized and superseded by active-gate readiness.
- 2026-06-11 Agent-B001 B001-042: raised from `82/86` to `86/88` after creating exact child pages [UID:000361][0x004f27a0-0x004f2813.NumberInputPaneConstructor](by-memory/0x004f27a0-0x004f2813.NumberInputPaneConstructor.md) and [UID:000362][0x004f2820-0x004f289b.NumberInputPaneKeyFilter](by-memory/0x004f2820-0x004f289b.NumberInputPaneKeyFilter.md) and rechecking constructor/filter ownership against IDA vtable stores, key-filter behavior, and reusable `InputPanes` file placement.
- 2026-06-06: Raised completion using the same evidence model as the sibling input argument panes.
  - Before: completion was `74`; parent [UID:0000K7][InputPanes](by-file/InputPanes.md) was already attached, but the report row still carried the older `66` score.
  - After: completion is `82`, confidence remains `86`, and the existing parent attachment is retained.
  - Evidence: the page has constructor/filter ranges, exact vtable bases, secondary override-slot proof, aggregate-range ownership, and drop/give gold consumers documented. Historical note: C++ was left blank under the then-used `95/95` final-source gate; this is superseded by the 2026-07-01 formal declaration shell.

- 2026-06-02:
  - Before: page documented the class purpose and method map but left reconstructable/parent metadata blank.
  - Changed to: `COMPLETION:74`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000K7`.
  - Evidence: IDA-backed input-pane aggregate boundaries, the input-pane vtable family, secondary key-filter override, and derived gold-input constructor uses support reusable `InputPanes.cpp` ownership. Historical note: C++ was left blank under the then-used 95+ gate; this is superseded by the 2026-07-01 formal declaration shell.

- Before: completion/confidence metadata were `0/0` even though the page already captured role, source file, vtable family, and two IDA-backed methods.
- Changed to: `COMPLETION:66` and `CONFIDENCE:82`.
- Evidence: constructor and key-filter behavior are well identified and source-family placement is strong; completion stays moderate because raw body details, callers, field/control layout, and reconstructed C++ are not yet exhaustive.
