*** UID:00001O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000K7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CharArgsInputPane

## Status

- Confidence: strong for class role and IDA boundaries.
- Likely source file: [UID:0000K7][InputPanes](by-file/InputPanes.md)
- Main address range: [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- Vtables: [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- Current recovered file: `source-3/simroot_v2/class_CharArgsInputPane.cpp`
- Autogen status: reconstructable class attached to [UID:0000K7][InputPanes](by-file/InputPanes.md); C++ remains blank because base-layout names and exact source declarations are below the `95/95` final-source gate.

## Class Purpose

`CharArgsInputPane` is a character-argument prompt derived from [UID:000077][LineInputPane](by-class/LineInputPane.md). It accepts alphabetic characters, comma, and space as translated input while passing standard control keys through to the base handler.

## Class Evidence

| Evidence | Meaning |
| --- | --- |
| Constructor range `0x004f2a60-0x004f2ad2` | Builds the `LineInputPane` base, installs the `CharArgsInputPane` three-vtable family, and disables active edit input. |
| Key filter range `0x004f2ae0-0x004f2b73` | Alphabetic-argument input handler; accepts letters, comma, space, and control keys before forwarding to the base handler. |
| Vtable bases `0x0061cc88`, `0x0061ccd8`, `0x0061cd08` | IDA-confirmed primary, secondary, and tertiary tables in [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md). |
| Vtable slot secondary `+0x08 -> 0x004f2ae0` | Confirms the alphabetic/comma/space filter is the derived key-input override. |
| Aggregate range [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md) | Places constructor/filter with the reusable input-pane base family rather than feature-specific command or spell prompt modules. |

## Consumer Evidence

| Consumer | Evidence |
| --- | --- |
| [UID:0001M5][0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor](by-memory/0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor.md) | Raw constructor calls the `CharArgsInputPane` base constructor before installing `ChangeItemSlotInputPane` vtables. |
| [UID:0001M7][0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor](by-memory/0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor.md) | Raw constructor calls the `CharArgsInputPane` base constructor before installing `ChangeSpellSlotInputPane` vtables. |
| [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) | Command/slot prompt modules consume this reusable character-argument base while feature-specific packet/state behavior remains outside `InputPanes.cpp`. |

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x004f2a60-0x004f2ad2` | constructor | Builds `LineInputPane`, installs character-argument vtables, and disables active edit input. |
| `0x004f2ae0-0x004f2b73` | `OnKeyInput` | Filters alphabetic/comma/space input and forwards accepted/control events to `LineInputPane::HandleKeyInput`. |

## Cross-References

- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- [UID:000077][LineInputPane](by-class/LineInputPane.md)
- [UID:00009J][NumberArgsInputPane](by-class/NumberArgsInputPane.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0001M5][0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor](by-memory/0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor.md)
- [UID:0001M7][0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor](by-memory/0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor.md)

## Changes

- 2026-06-06: Raised completion and attached to [UID:0000K7][InputPanes](by-file/InputPanes.md).
  - Before: completion was `70` and `AUTOGEN_PARENT_UID` was blank because the page had not cleared the child-side parent gate.
  - After: completion is `82`, confidence remains `86`, and `AUTOGEN_PARENT_UID` is `0000K7`.
  - Evidence: added constructor/filter range evidence, exact vtable bases and secondary key-filter slot from [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md), aggregate ownership through [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md), and derived slot-prompt consumer links. C++ remains blank under the `95/95` final-source gate.

- What existed before: the page documented class role, constructor, key filter, and references, but metadata remained `0/0`.
- What it was changed to: scores were set to `70/86`.
- Summary and evidence: the class is simple and IDA boundaries are strong; completion is capped because detailed field layout, accepted-key edge cases, and final header form are not fully expanded here.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE`. Current IDA MCP `lookup_funcs` reconfirmed the constructor and key-filter starts at `0x004f2a60` and `0x004f2ae0`, and `callers` shows use from command/input prompt creation paths. Parent attachment was deferred at that score and superseded by the 2026-06-06 attachment above after the page met the 80/80 gate.
