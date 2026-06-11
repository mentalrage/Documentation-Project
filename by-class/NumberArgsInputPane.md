*** UID:00009J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000K7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NumberArgsInputPane

## Status

- Confidence: strong for class role and IDA boundaries.
- Likely source file: [UID:0000K7][InputPanes](by-file/InputPanes.md)
- Main address range: [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- Vtables: [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- Current recovered file: `source-3/simroot_v2/class_NumberArgsInputPane.cpp`
- Autogen status: reconstructable class attached to [UID:0000K7][InputPanes](by-file/InputPanes.md); C++ remains blank because the base-layout names and exact source declaration are below the `95/95` gate.

## Class Purpose

`NumberArgsInputPane` is a numeric-argument prompt derived from [UID:000077][LineInputPane](by-class/LineInputPane.md). It accepts digits, comma, and space, which matches command inputs that accept one or more numeric arguments.

## Class Evidence

| Evidence | Meaning |
| --- | --- |
| Constructor range `0x004f2b80-0x004f2bf2` | Builds the `LineInputPane` base and installs the `NumberArgsInputPane` three-vtable family. |
| Key filter range `0x004f2c00-0x004f2c84` | Numeric-argument input handler; accepts digits, comma, space, and control keys before forwarding to the base handler. |
| Vtable bases `0x0061cd14`, `0x0061cd64`, `0x0061cd94` | IDA-confirmed primary, secondary, and tertiary tables in [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md). |
| Vtable slot secondary `+0x08 -> 0x004f2c00` | Confirms the digit/comma/space filter is the derived key-input override. |
| Aggregate range [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md) | Places constructor/filter with the reusable input-pane base family, not spell-specific argument packet handlers. |

## Consumer Evidence

| Consumer | Evidence |
| --- | --- |
| [UID:0000DR][SpellOneArgInputPane](by-class/SpellOneArgInputPane.md) | Derived spell prompt for one numeric argument. |
| [UID:0000DW][SpellTwoArgsInputPane](by-class/SpellTwoArgsInputPane.md) | Derived spell prompt for two numeric arguments. |
| [UID:0000DV][SpellThreeArgsInputPane](by-class/SpellThreeArgsInputPane.md) | Derived spell prompt for three numeric arguments. |
| [UID:0000DL][SpellFourArgsInputPane](by-class/SpellFourArgsInputPane.md) | Derived spell prompt for four numeric arguments. |
| [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md) | Spell-specific subclasses consume this reusable base while packet serialization remains in spell input modules. |

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x004f2b80-0x004f2bf2` | constructor | Builds `LineInputPane`, installs numeric-argument vtables, and configures the edit child. |
| `0x004f2c00-0x004f2c84` | `OnKeyInput` | Filters digit/comma/space input and forwards accepted/control events to `LineInputPane::HandleKeyInput`. |

## Cross-References

- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- [UID:000077][LineInputPane](by-class/LineInputPane.md)
- [UID:00009L][NumberInputPane](by-class/NumberInputPane.md)
- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0000DR][SpellOneArgInputPane](by-class/SpellOneArgInputPane.md)
- [UID:0000DW][SpellTwoArgsInputPane](by-class/SpellTwoArgsInputPane.md)
- [UID:0000DV][SpellThreeArgsInputPane](by-class/SpellThreeArgsInputPane.md)
- [UID:0000DL][SpellFourArgsInputPane](by-class/SpellFourArgsInputPane.md)

## Changes

- 2026-06-06: Raised completion using the same evidence model as the sibling input argument panes.
  - Before: completion was `74`; parent [UID:0000K7][InputPanes](by-file/InputPanes.md) was already attached, but the report row still carried the older `66` score.
  - After: completion is `82`, confidence remains `86`, and the existing parent attachment is retained.
  - Evidence: the page now has constructor/filter ranges, exact vtable bases, secondary override-slot proof, aggregate-range ownership, and spell numeric-argument consumers documented. C++ remains blank under the `95/95` final-source gate.

- 2026-06-02:
  - Before: page documented the class purpose and method map but left reconstructable/parent metadata blank.
  - Changed to: `COMPLETION:74`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000K7`.
  - Evidence: IDA-backed input-pane aggregate boundaries, the input-pane vtable family, secondary key-filter override, and spell numeric-argument subclass consumers support reusable `InputPanes.cpp` ownership. C++ remains blank under the 95+ gate.

- Before: completion/confidence metadata were `0/0` even though the page already had purpose, range, vtable, method, and cross-reference notes.
- Changed to: `COMPLETION:66` and `CONFIDENCE:82`.
- Evidence: the small class has IDA-backed constructor/key-filter boundaries and clear source-family placement; completion remains moderate because the page lacks raw code detail, caller inventory, and field/control layout beyond the main behavior.
