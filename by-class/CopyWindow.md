*** UID:000039 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CopyWindow

## Status

- Confidence: medium-high.
- Likely source file: [UID:0000IH][CopyWindow](by-file/CopyWindow.md)
- Current recovered file: `source-3/simroot_v2/class_CopyWindow.cpp`
- Current Wave3 grade: `97.5`
- Current Wave3 coverage: 3 modeled methods, zero disabled companion methods.

## Class Purpose

`CopyWindow` is a small [UID:00000B][AlertPane](by-class/AlertPane.md) subclass that coordinates a text-edit copy/select operation with the active [UID:0000EO][TextEditPane](by-class/TextEditPane.md). It presents a modal alert and, on accept, calls the active text editor's select-all helper before clearing the active-editor global.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x005544c0-0x00554513` | Calls `AlertPane::AlertPane`, using localized string id `0xf1`, button table `off_622f44`, and installs three `CopyWindow` vtables. IDA currently does not model this start as a function. |
| `OnAccept` | `0x00554520-0x00554536` | Calls `TextEditPane::SelectAll` at `0x00590520` through [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md), then clears the global. |
| `OnCancel` | `0x00554540-0x0055454b` | Clears [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md). |

## Evidence Notes

- `CopyWindow` vtable data at `0x00622e7c` references `0x00554520` and `0x00554540` as callbacks.
- The constructor has no IDA caller xrefs, but the helper at `0x00553e60` allocates a 624-byte object, calls the same alert base constructor, and installs `CopyWindow` vtables inline.
- 2026-05-25 IDA caller checks show `0x00553e60` is a `ConnectionClosedDialog`/reconnect-flow init helper that conditionally constructs `CopyWindow`, not a CopyWindow-owned open method.
- 2026-05-26 IDA MCP recheck kept `0x005544c0` as not-a-function, kept `0x00554520`/`0x00554540` as vtable-only callback xrefs, and kept `0x00553e60` as a real `0xd6`-byte helper with reconnect-flow callers.
- 2026-06-01 IDA MCP byte review confirms the constructor-shaped raw body at `0x005544c0-0x00554513`, `OnAccept` at `0x00554520-0x00554536`, and `OnCancel` at `0x00554540-0x0055454b`; the previous callback end omitted the final `retn` byte.
- The generated global name `g_pCopyWindowTextEditPane` is too narrow; IDA xrefs show `dword_69BE00` is an active text-edit pointer set by `TextEditPane` construction and cleared by `TextEditPane` destruction.
- Current `simroot_v2` has the canonical `g_pActiveTextEditPane` in `class_TextEditPane.cpp`, but `class_CopyWindow.cpp` still uses the stale alias.

## Cross-References

- [UID:0000IH][CopyWindow](by-file/CopyWindow.md)
- [UID:0001FV][0x005544c0-0x0055454b.CopyWindow](by-memory/0x005544c0-0x0055454b.CopyWindow.md)
- [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md)
- [UID:00000B][AlertPane](by-class/AlertPane.md)
- [UID:0000EO][TextEditPane](by-class/TextEditPane.md)
- [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `68/76`.
  - Summary/evidence: accept/cancel callbacks, vtable references, active text-edit global behavior, and reconnect-flow inline construction evidence are documented; remaining uncertainty is the constructor boundary and stale generated alias cleanup.
- 2026-06-01:
  - Before: method ranges used pre-byte-review endpoints and scores were capped at `68/76`.
  - After: corrected constructor/callback ranges and raised scores to `78/84`.
  - Summary/evidence: IDA MCP confirms exact raw bytes, vtable references, active-editor global access, and callback bodies. Completion remains below file-level because final source method names and constructor modeling remain open.
