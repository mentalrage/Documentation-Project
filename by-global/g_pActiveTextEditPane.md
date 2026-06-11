*** UID:0000Q7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000ON | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pActiveTextEditPane / dword_69BE00

## Status

- Confidence: strong for active-text-edit role; exact original name unknown.
- Address: `0x0069be00`
- IDA name: `dword_69BE00`
- Observed alias: `g_pCopyWindowTextEditPane`
- Likely owner: [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- Exact storage: [UID:000302][0x0069be00-0x0069be04.g_pActiveTextEditPane](by-memory/0x0069be00-0x0069be04.g_pActiveTextEditPane.md)

## Purpose

This global tracks the currently active [UID:0000EO][TextEditPane](by-class/TextEditPane.md) for editor commands and dialog callbacks. It is set during `TextEditPane` construction when the style flags allow the pane to become active, cleared during `TextEditPane` destruction if it still points to that pane, and consumed by [UID:000039][CopyWindow](by-class/CopyWindow.md).

## Evidence Notes

- IDA xrefs show writes in `TextEditPane::TextEditPane` at `0x0058dd5c`/`0x0058dd6b` and `TextEditPane::~TextEditPane` at `0x0058e181`/`0x0058e18d`.
- `CopyWindow::OnAccept` at `0x00554520` reads this pointer, calls `TextEditPane::SelectAll` at `0x00590520`, then clears the pointer.
- `CopyWindow::OnCancel` at `0x00554540` clears the pointer without calling into the editor.
- The connection-closed/reconnect init helper at `0x00553e60` checks this pointer before optionally allocating a `CopyWindow`.
- 2026-05-26 IDA MCP `xrefs_to 0x0069be00` reports the same eight data xrefs: one read in `0x00553e60`, two callback xrefs in `0x00554520`, one clear in `0x00554540`, two constructor writes in `0x0058dce0`, and two destructor xrefs in `0x0058e140`.
- The `g_pCopyWindowTextEditPane` alias describes one consumer but is too narrow for the shared active-editor pointer.
- [UID:000302][0x0069be00-0x0069be04.g_pActiveTextEditPane](by-memory/0x0069be00-0x0069be04.g_pActiveTextEditPane.md) now isolates the exact four-byte `.data` storage from the adjacent mixed terminal/text-edit cluster. This parent page clears the corrected `85/85` direct-parent gate for that storage child.
- A004 Batch 056 attempted a live IDA MCP refresh, but repeated `py_eval`, `xrefs_to`, and `idb_meta` calls timed out. The confidence raise uses the already written IDA-backed eight-xref set and exact storage split, not new live facts.

## Naming Notes

The `g_pCopyWindowTextEditPane` alias describes one consumer but is too narrow. Use `g_pActiveTextEditPane` in documentation until a stronger original symbol is recovered.

## Cross-References

- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000EO][TextEditPane](by-class/TextEditPane.md)
- [UID:0000IH][CopyWindow](by-file/CopyWindow.md)
- [UID:0001FV][0x005544c0-0x0055454b.CopyWindow](by-memory/0x005544c0-0x0055454b.CopyWindow.md)
- [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md)
- [UID:000302][0x0069be00-0x0069be04.g_pActiveTextEditPane](by-memory/0x0069be00-0x0069be04.g_pActiveTextEditPane.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/84`. Summary/evidence: the page documents address, active `TextEditPane` role, constructor/destructor writes, `CopyWindow` and reconnect consumers, IDA xref recheck, alias correction, and class/memory refs.
- 2026-06-05: Marked reconstructable under [UID:0000ON][TextEditPane](by-file/TextEditPane.md). Evidence: live IDA MCP reports the same eight xrefs to `0x0069be00`; decompilation confirms `0x0058dce0` writes the active pointer, `0x0058e140` clears it when destroying the active editor, and `0x00554520` consumes and clears it from the copy-window accept handler.
- 2026-06-07 A004 Batch 056 parent-gate refresh:
  - Before: `88/84`, below the corrected confidence gate for exact storage assignment.
  - Changed to: `88/86`, linking exact child [UID:000302][0x0069be00-0x0069be04.g_pActiveTextEditPane](by-memory/0x0069be00-0x0069be04.g_pActiveTextEditPane.md).
  - Summary/evidence: the existing IDA-backed eight-xref set now has an exact memory child and still supports TextEditPane ownership over the narrower CopyWindow alias. Live MCP refresh timed out, so the page stays below final-source confidence and no C++ declaration was emitted.
