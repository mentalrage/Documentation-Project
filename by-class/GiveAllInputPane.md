*** UID:00005S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GiveAllInputPane

## Status

- Confidence: strong for behavior and item-action input module placement.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address range: [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- Autogen parent: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md), which is `90/80` and owns the direct item-action prompt family.
- Current recovered file: `source-3/simroot_v2/class_GiveAllInputPane.cpp`
- Final C++ gate: keep blank until the raw helper span after `0x005b4eee`, confirmation callback type, prompt text fields, and base `CharInputPane` method names are split/named.

## Class Purpose

`GiveAllInputPane` is a single-character prompt for giving all items in a selected slot to another player. It mirrors the drop-all prompt shape but builds a give callback and confirmation message.

It is the all-items sibling of [UID:00005U][GiveInputPane](by-class/GiveInputPane.md). The class should stay with the drop/give item-action cluster rather than target-selection or generic command-input code.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GiveAllInputPane` | `0x005b4cc0-0x005b4d87` | Constructs prompt with player name and installs the three-view item-action input vtables. |
| `OnKeyInput` | `0x005b4d90-0x005b4dfc` | Handles the help-panel shortcut and delegates character input. |
| `OnSubmitInput` | `0x005b4e00-0x005b4eee` | Converts slot letter, validates inventory range, and creates a give-all confirmation callback. |

## Evidence Notes

- [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) records IDA-confirmed half-open ranges for `0x005b4cc0-0x005b4d87`, `0x005b4d90-0x005b4dfc`, and `0x005b4e00-0x005b4eee`.
- The same aggregate records pure padding at `0x005b4d87-0x005b4d90` and `0x005b4dfc-0x005b4e00`, which keeps the three modeled method boundaries clean.
- The raw span `0x005b4eee-0x005b4f70` is non-empty and likely contains adjacent give-all packet/confirmation helper logic; it still needs exact child splitting before final C++ reconstruction.
- Generated source shows callback creation through `GiveItemsToSlot` with the all-items flag set; keep that as behavioral evidence, not final source text.
- The class should migrate beside [UID:00005U][GiveInputPane](by-class/GiveInputPane.md) and [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md).

## State And Dependencies

| Dependency | Role | Reconstruction Note |
| --- | --- | --- |
| [UID:00005U][GiveInputPane](by-class/GiveInputPane.md) | Non-all give prompt sibling. | Share prompt framework naming, but keep all-items callback handling distinct. |
| [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md) | Gold give sibling in the same cluster. | The all-items pane does not own gold amount packet send logic. |
| [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md) | Three-view vtable family for direct item-action prompts. | Source should declare the class and let vtables rebuild from virtual methods. |
| inventory slot decoding | Submit handler validates a typed slot letter before creating the confirmation callback. | Final field/local names still need method-level reconstruction. |

## Autogen And Score Notes

This page is now attached to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md). The parent is `90/80`, and this class reaches `80/87` with exact method ranges, sibling relationships, all-items callback behavior, vtable-family evidence, and remaining raw-helper blockers documented.

Final C++ remains blank because the raw helper body after the modeled submit method, callback type declaration, prompt/local field names, and source-facing base class virtual names still need a focused method-level pass.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- [UID:00005U][GiveInputPane](by-class/GiveInputPane.md)
- [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md)
- [UID:000042][DropAllInputPane](by-class/DropAllInputPane.md)

## Changes

- 2026-06-07: Raised `COMPLETION` from `74` to `80`, raised `CONFIDENCE` from `86` to `87`, and attached `AUTOGEN_PARENT_UID:0000KC`.
  - Before: the page documented the three core methods and give-all role, but lacked parent metadata, raw-span caveats, dependency mapping, and score rationale.
  - After: the page records parent-gate reasoning, exact half-open method ranges, clean padding boundaries, all-items confirmation behavior, raw helper blocker after `0x005b4eee`, sibling/drop-side relationships, and final-C++ blockers.
  - Evidence: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) is `90/80`; [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) records the modeled function map, raw helper map, vtable family, and give-side prompt cluster.
- Completion/confidence score update: existed before as `0/0`; changed to `74/86`. Summary: give-all prompt role, constructor/key/submit methods, callback behavior, inventory validation, and sibling placement are documented with strong confidence; remaining work is final source reconstruction and field naming. Evidence: `0x005b44b0-0x005b538a` memory page, IDA-confirmed starts for `0x005b4cc0`, `0x005b4d90`, and `0x005b4e00`, plus ItemActionInputPanes vtable documentation.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the give-all item action prompt unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE`; left `AUTOGEN_PARENT_UID` blank because the class score is `74/86`, below the 80 completion attachment gate.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x005b4cc0`, `0x005b4d90`, and `0x005b4e00`, matching the documented item-action input pane behavior and `ItemActionInputPanes` placement.
