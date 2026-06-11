*** UID:000035 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000K7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ConfirmInputPane

## Status

- Confidence: strong for class role and IDA boundaries.
- Likely source file: [UID:0000K7][InputPanes](by-file/InputPanes.md)
- Main address range: [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- Constructor range: [UID:0001N4][0x005b75d0-0x005b760e.ConfirmInputPaneConstructor](by-memory/0x005b75d0-0x005b760e.ConfirmInputPaneConstructor.md)
- Compiler adjustors: [UID:00018Z][0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks.md)
- Vtables: [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- Reconstructable class attached to [UID:0000K7][InputPanes](by-file/InputPanes.md). Final C++ stays blank because member/action-object names are not final-source quality.

## Class Purpose

`ConfirmInputPane` is a yes/no confirmation prompt built on [UID:00001P][CharInputPane](by-class/CharInputPane.md). When the text source contains one character and that character is `y` or `Y`, it invokes the stored confirmation action object. Destruction also tears down a stored parent dialog/reference.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x004f2a10-0x004f2a57` | `OnEnterKey` | Reads the single-character response and invokes the confirmation action on `y`/`Y`. |
| `0x004f2e85-0x004f2e9a` | secondary/tertiary destructor adjustors | Compiler thunks that subtract `0xa0` or `0xa4` and tail-jump to the scalar deleting destructor. |
| `0x004f2fb0-0x004f3017` | scalar deleting destructor | Releases the stored confirmation action/context, tears down `LineInputPane`, and conditionally deletes. |
| `0x005b75d0-0x005b760e` | constructor | Builds `CharInputPane`, stores confirmation action/context at `this + 0x108`, and installs vtables. |

## 2026-06-05 IDA MCP Evidence

- `lookup_funcs` confirms modeled starts at `0x004f2a10`, `0x004f2fb0`, and `0x005b75d0`; the late constructor is size `0x3e` and ends at `0x005b760e`.
- `decompile 0x004f2a10` reads the current text length from `this + 0xfc`, copies one wide character when length is one, and invokes the stored action object at `this + 0x108` only for `y` (`0x79`) or `Y` (`0x59`).
- `decompile 0x004f2fb0` restores the three `ConfirmInputPane` vtable views, calls the stored action/context object's first virtual slot with argument `1` when present, calls `LineInputPane` cleanup at `0x004f2dd0`, and conditionally frees storage through `0x004f4ac0`.
- `decompile 0x005b75d0` calls `CharInputPane` constructor `0x004f28a0`, stores the action/context pointer at `this + 0x108`, and installs vtables `0x0061cbfc`, `0x0061cc4c`, and `0x0061cc7c`.
- `xrefs_to 0x004f2a10` reports the primary vtable slot at `0x0061cc44`; `xrefs_to 0x004f2fb0` reports the secondary/tertiary adjustor thunks and the primary vtable slot.
- `callers 0x005b75d0` reports four item-action prompt construction paths: [UID:000042][DropAllInputPane](by-class/DropAllInputPane.md), [UID:000044][DropInputPane](by-class/DropInputPane.md), [UID:00005S][GiveAllInputPane](by-class/GiveAllInputPane.md), and [UID:00005U][GiveInputPane](by-class/GiveInputPane.md).

## Cross-References

- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:00018Z][0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks.md)
- [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- [UID:00001P][CharInputPane](by-class/CharInputPane.md)
- [UID:000077][LineInputPane](by-class/LineInputPane.md)
- [UID:000042][DropAllInputPane](by-class/DropAllInputPane.md)
- [UID:000044][DropInputPane](by-class/DropInputPane.md)
- [UID:00005S][GiveAllInputPane](by-class/GiveAllInputPane.md)
- [UID:00005U][GiveInputPane](by-class/GiveInputPane.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `74/86`.
  - Summary/evidence: class role, constructor, enter-key behavior, destructor/adjustor thunks, vtable family, and base-class relationships are documented from IDA-backed ranges; remaining work is detailed member naming and final C++ body reconstruction.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After at that point: `RECONSTRUCTABLE:TRUE`; parent attachment was deferred because the class completion score was below the 80% attachment gate.
  - Evidence: live IDA MCP confirms modeled starts at `0x004f2a10`, `0x004f2fb0`, and `0x005b75d0`, with the late constructor called from several prompt construction paths; existing project docs place the class in [UID:0000K7][InputPanes](by-file/InputPanes.md).
- 2026-06-05: Raised from `74/86` to `82/88` and attached to [UID:0000K7][InputPanes](by-file/InputPanes.md).
  - Before: the page still had stale output provenance, a one-byte-short destructor row, no parent attachment, and only summary evidence for the late constructor callers.
  - After: removed stale provenance, corrected the destructor and constructor half-open ranges, attached the class to the input-pane source file, and documented current IDA evidence for key handler, destructor, constructor, vtables, and callers.
  - Evidence: current IDA MCP `lookup_funcs`, `decompile`, `disasm`, `callers`, and `xrefs_to` confirm the method family and ownership.
