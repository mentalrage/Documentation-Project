*** UID:00009L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000K7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NumberInputPane

## Status

- Confidence: strong for class role and IDA boundaries.
- Likely source file: [UID:0000K7][InputPanes](by-file/InputPanes.md)
- Main address range: [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- Vtables: [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- Current recovered file: `source-3/simroot_v2/class_NumberInputPane.cpp`
- Autogen status: reconstructable class attached to [UID:0000K7][InputPanes](by-file/InputPanes.md); C++ remains blank because the base-layout names and exact source declaration are below the `95/95` gate.

## Class Purpose

`NumberInputPane` is a numeric-only [UID:000077][LineInputPane](by-class/LineInputPane.md) variant. It disables free text input and filters key-down events so digits are converted to translated character events while control keys pass through to the base handler.

## Class Evidence

| Evidence | Meaning |
| --- | --- |
| Constructor range `0x004f27a0-0x004f2812` | Builds the `LineInputPane` base and installs the `NumberInputPane` three-vtable family. |
| Key filter range `0x004f2820-0x004f289a` | Numeric-only input handler; accepts digits and control keys before forwarding to the base handler. |
| Vtable bases `0x0061cae4`, `0x0061cb34`, `0x0061cb64` | IDA-confirmed primary, secondary, and tertiary tables in [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md). |
| Vtable slot secondary `+0x08 -> 0x004f2820` | Confirms the numeric filter is the derived key-input override. |
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

## Cross-References

- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- [UID:000077][LineInputPane](by-class/LineInputPane.md)
- [UID:00009J][NumberArgsInputPane](by-class/NumberArgsInputPane.md)
- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md)
- [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md)

## Changes

- 2026-06-06: Raised completion using the same evidence model as the sibling input argument panes.
  - Before: completion was `74`; parent [UID:0000K7][InputPanes](by-file/InputPanes.md) was already attached, but the report row still carried the older `66` score.
  - After: completion is `82`, confidence remains `86`, and the existing parent attachment is retained.
  - Evidence: the page has constructor/filter ranges, exact vtable bases, secondary override-slot proof, aggregate-range ownership, and drop/give gold consumers documented. C++ remains blank under the `95/95` final-source gate.

- 2026-06-02:
  - Before: page documented the class purpose and method map but left reconstructable/parent metadata blank.
  - Changed to: `COMPLETION:74`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000K7`.
  - Evidence: IDA-backed input-pane aggregate boundaries, the input-pane vtable family, secondary key-filter override, and derived gold-input constructor uses support reusable `InputPanes.cpp` ownership. C++ remains blank under the 95+ gate.

- Before: completion/confidence metadata were `0/0` even though the page already captured role, source file, vtable family, and two IDA-backed methods.
- Changed to: `COMPLETION:66` and `CONFIDENCE:82`.
- Evidence: constructor and key-filter behavior are well identified and source-family placement is strong; completion stays moderate because raw body details, callers, field/control layout, and reconstructed C++ are not yet exhaustive.
