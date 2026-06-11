*** UID:00001P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000K7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CharInputPane

## Status

- Confidence: strong for class role and IDA boundaries.
- Likely source file: [UID:0000K7][InputPanes](by-file/InputPanes.md)
- Main address range: [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- Compiler adjustors: [UID:00018Z][0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks.md)
- Vtables: [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- Current recovered file: `source-3/simroot_v2/class_CharInputPane.cpp`
- Autogen status: reconstructable class attached to [UID:0000K7][InputPanes](by-file/InputPanes.md); C++ remains blank because base-layout names and exact source declarations are below the `95/95` final-source gate.

## Class Purpose

`CharInputPane` is a single-character prompt built on [UID:000077][LineInputPane](by-class/LineInputPane.md). It disables free text editing, accepts printable characters, converts them into translated character events, dismisses the prompt, clears pending player input state, forwards the accepted key to the base handler, and notifies the owner pane.

## Class Evidence

| Evidence | Meaning |
| --- | --- |
| Constructor range `0x004f28a0-0x004f2912` | Builds the `LineInputPane` base, installs the `CharInputPane` three-vtable family, and disables active edit input. |
| Character handler range `0x004f2920-0x004f29c9` | Printable-character acceptor and owner-notification path; Escape/control handling falls through the base input path. |
| Destructor adjustors `0x004f2e6f-0x004f2e84` | Compiler-generated secondary/tertiary thunks in [UID:00018Z][0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks.md). |
| Scalar deleting destructor `0x004f2f70-0x004f2faa` | Real `CharInputPane` deleting destructor body in the reusable input-pane cluster. |
| Vtable bases `0x0061cb70`, `0x0061cbc0`, `0x0061cbf0` | IDA-confirmed primary, secondary, and tertiary tables in [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md). |
| Vtable slot secondary `+0x08 -> 0x004f2920` | Confirms the printable-character acceptor is the derived key-input override. |

## Consumer Evidence

| Consumer | Evidence |
| --- | --- |
| [UID:000035][ConfirmInputPane](by-class/ConfirmInputPane.md) | Inherits the `CharInputPane` key acceptor through its secondary vtable while adding yes/no confirmation behavior. |
| [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) | Command prompt modules consume this reusable single-character base for feature-specific prompt classes. |
| [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) | Item action prompts consume the reusable base while packet/state behavior remains in item-action modules. |

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x004f28a0-0x004f2912` | constructor | Builds `LineInputPane`, installs `CharInputPane` vtables, and disables active edit input. |
| `0x004f2920-0x004f29c9` | `OnCharInput` | Accepts printable characters, handles Escape through base key input, rejects some extended keys, and notifies owner on accepted input. |
| `0x004f2e6f-0x004f2e84` | secondary/tertiary destructor adjustors | Compiler thunks that subtract `0xa0` or `0xa4` and tail-jump to the scalar deleting destructor. |
| `0x004f2f70-0x004f2faa` | scalar deleting destructor | Tears down `LineInputPane` and conditionally deletes storage. |

## Cross-References

- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:00018Z][0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks.md)
- [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- [UID:000077][LineInputPane](by-class/LineInputPane.md)
- [UID:000035][ConfirmInputPane](by-class/ConfirmInputPane.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)

## Changes

- 2026-06-06: Raised completion and attached to [UID:0000K7][InputPanes](by-file/InputPanes.md).
  - Before: completion was `72` and `AUTOGEN_PARENT_UID` was blank because the page had not cleared the child-side parent gate.
  - After: completion is `82`, confidence remains `86`, and `AUTOGEN_PARENT_UID` is `0000K7`.
  - Evidence: added constructor/handler/destructor evidence, vtable bases and override-slot proof from [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md), adjustor-thunk ownership, and consumer links to confirmation/command/item prompt modules. C++ remains blank under the `95/95` final-source gate.

- What existed before: the page documented constructor, char input, destructor adjustors, scalar destructor, and references, but metadata remained `0/0`.
- What it was changed to: scores were set to `72/86`.
- Summary and evidence: IDA boundaries and class role are strong; completion is limited by missing detailed field/layout notes and exact owner notification naming.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE`. Current IDA MCP `lookup_funcs` reconfirmed the constructor, char-input handler, and scalar deleting destructor starts at `0x004f28a0`, `0x004f2920`, and `0x004f2f70`, and `callers` shows broad prompt construction use from command, item, and dialog paths. Parent attachment was deferred at that score and superseded by the 2026-06-06 attachment above after the page met the 80/80 gate.
