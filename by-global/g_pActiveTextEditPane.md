*** UID:0000Q7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pActiveTextEditPane / dword_69BE00

## Status

- Confidence: strong for active-text-edit role; exact original name unknown.
- Address: `0x0069be00`
- IDA name: `dword_69BE00`
- Generated aliases observed: `g_pCopyWindowTextEditPane`
- Likely owner: [UID:0000ON][TextEditPane](by-file/TextEditPane.md)

## Purpose

This global tracks the currently active [UID:0000EO][TextEditPane](by-class/TextEditPane.md) for editor commands and dialog callbacks. It is set during `TextEditPane` construction when the style flags allow the pane to become active, cleared during `TextEditPane` destruction if it still points to that pane, and consumed by [UID:000039][CopyWindow](by-class/CopyWindow.md).

## Evidence Notes

- IDA xrefs show writes in `TextEditPane::TextEditPane` at `0x0058dd5c`/`0x0058dd6b` and `TextEditPane::~TextEditPane` at `0x0058e181`/`0x0058e18d`.
- `CopyWindow::OnAccept` at `0x00554520` reads this pointer, calls `TextEditPane::SelectAll` at `0x00590520`, then clears the pointer.
- `CopyWindow::OnCancel` at `0x00554540` clears the pointer without calling into the editor.
- The connection-closed/reconnect init helper at `0x00553e60` checks this pointer before optionally allocating a `CopyWindow`.
- 2026-05-26 IDA MCP `xrefs_to 0x0069be00` reports the same eight data xrefs: one read in `0x00553e60`, two callback xrefs in `0x00554520`, one clear in `0x00554540`, two constructor writes in `0x0058dce0`, and two destructor xrefs in `0x0058e140`.
- 2026-05-26 `simroot_v2` recheck: `class_TextEditPane.cpp` owns `TextEditPane* g_pActiveTextEditPane`, but `class_CopyWindow.cpp` still emits the stale alias `g_pCopyWindowTextEditPane`.

## Naming Notes

The generated alias `g_pCopyWindowTextEditPane` describes one consumer but is too narrow. Use `g_pActiveTextEditPane` in documentation until a stronger original symbol is recovered.

## Cross-References

- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000EO][TextEditPane](by-class/TextEditPane.md)
- [UID:0000IH][CopyWindow](by-file/CopyWindow.md)
- [UID:0001FV][0x005544c0-0x0055454b.CopyWindow](by-memory/0x005544c0-0x0055454b.CopyWindow.md)
- [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/84`. Summary/evidence: the page documents address, active `TextEditPane` role, constructor/destructor writes, `CopyWindow` and reconnect consumers, IDA xref recheck, generated alias correction, and class/memory refs.
