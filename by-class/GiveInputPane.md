*** UID:00005U | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GiveInputPane

## Status

- Confidence: strong for behavior and item-action input module placement.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address range: [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- Autogen parent: blank under the strict `85/85` child/direct-parent gate. The direct parent is still [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md), now `90/85`, but this class remains `80/87` until the raw helper span and final source naming are resolved.
- Current recovered file: `source-3/simroot_v2/class_GiveInputPane.cpp`
- Final C++ gate: keep blank until the raw helper span after `0x005b5223`, prompt text fields, and base `CharInputPane` method names are split/named.

## Class Purpose

`GiveInputPane` is the standard item-give prompt. It accepts a single inventory slot letter, routes gold selection into `GiveGoldInputPane`, and opens a confirmation callback for normal item slots.

It is the non-all variant paired with [UID:00005S][GiveAllInputPane](by-class/GiveAllInputPane.md). Both live in the same drop/give item-action cluster and use the same prompt/input framework as the drop-side siblings.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GiveInputPane` | `0x005b4f70-0x005b5037` | Constructs the prompt with player name and installs the three-view item-action input vtables. |
| `OnKeyInput` | `0x005b5040-0x005b50ac` | Handles the help-panel shortcut and delegates normal character input. |
| `OnConfirmInput` | `0x005b50b0-0x005b5223` | Converts slot input, branches gold selection into `GiveGoldInputPane`, or opens normal-item give confirmation. |

## Evidence Notes

- [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) records IDA-confirmed half-open ranges for `0x005b4f70-0x005b5037`, `0x005b5040-0x005b50ac`, and `0x005b50b0-0x005b5223`.
- The same aggregate records pure padding at `0x005b5037-0x005b5040` and `0x005b50ac-0x005b50b0`, which keeps the three modeled method boundaries clean.
- The gold branch reaches the raw [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md), a `NumberInputPane`-derived prompt with prompt id `43`.
- The raw span `0x005b5223-0x005b52f0` is non-empty and still needs exact child splitting before final C++ reconstruction.
- This class is the give counterpart to [UID:000044][DropInputPane](by-class/DropInputPane.md).

## State And Dependencies

| Dependency | Role | Reconstruction Note |
| --- | --- | --- |
| [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md) | Numeric gold-give prompt reached from the gold slot branch. | Keep the inline construction behavior tied to the raw constructor page until source naming is final. |
| [UID:00005S][GiveAllInputPane](by-class/GiveAllInputPane.md) | Sibling prompt for all-items give behavior. | Share naming and prompt framework, but keep all-items callback handling separate. |
| [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md) | Three-view vtable family for direct item-action prompts. | Source should declare the class and let vtables rebuild from virtual methods. |
| [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) | Give-gold path ultimately queues opcode `0x2a`. | Packet send details live with `GiveGoldInputPane`; this class owns the routing branch. |

## Autogen And Score Notes

This page is not currently attached for autogen. The direct parent is [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md), which clears the parent side at `90/85`, but this class remains `80/87` and therefore fails the child side of the strict `85/85` assignment gate.

Final C++ remains blank because the raw helper body after the modeled submit method, prompt/local field names, and source-facing base class virtual names still need a focused method-level pass.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- [UID:00005S][GiveAllInputPane](by-class/GiveAllInputPane.md)
- [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md)
- [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md)
- [UID:000044][DropInputPane](by-class/DropInputPane.md)

## Changes

- 2026-06-10 A002 strict-gate repair:
  - Before: `AUTOGEN_PARENT_UID:0000KC` still attached this class to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) even though the class score is only `80/87`.
  - After: cleared `AUTOGEN_PARENT_UID` and left the score unchanged at `80/87`.
  - Reason: the direct parent now clears the parent side at `90/85`, but the child side must also be at least `85/85`; this class still needs the raw helper span after `0x005b5223`, prompt/local field names, and final source-facing base method names resolved before assignment.
  - Evidence: existing class, by-file, and [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) documentation already records the modeled ranges and blockers; no new live IDA evidence was used.
- 2026-06-07: Raised `COMPLETION` from `74` to `80`, raised `CONFIDENCE` from `86` to `87`, and attached `AUTOGEN_PARENT_UID:0000KC`.
  - Before: the page documented the three core methods and give/gold role, but lacked parent metadata, raw-span caveats, dependency mapping, and score rationale.
  - After: the page records parent-gate reasoning, exact half-open method ranges, clean padding boundaries, gold raw-constructor dependency, raw helper blocker after `0x005b5223`, sibling/drop-side relationships, and final-C++ blockers.
  - Evidence: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) is `90/80`; [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) records the modeled function map, raw helper map, vtable family, and give-gold prompt dependency.
- Completion/confidence score update: existed before as `0/0`; changed to `74/86`. Summary: standard give prompt role, constructor/key/confirm methods, gold branch, sibling relationship, and item-action module placement are documented with strong confidence; remaining work is detailed layout naming and final source reconstruction. Evidence: `0x005b44b0-0x005b538a` memory page, IDA-confirmed starts for `0x005b4f70`, `0x005b5040`, and `0x005b50b0`, plus GiveAll/GiveGold cross-references.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the standard give item action prompt unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE`; left `AUTOGEN_PARENT_UID` blank because the class score is `74/86`, below the 80 completion attachment gate.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x005b4f70`, `0x005b5040`, and `0x005b50b0`, matching the documented give/gold-branch behavior and sibling `ItemActionInputPanes` placement.
