*** UID:0000Q7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ON | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000EO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
TextEditPane *g_pActiveTextEditPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
extern TextEditPane *g_pActiveTextEditPane;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pActiveTextEditPane

## Status

- Confidence: strong for active-text-edit role, exact applied pointer type/name, zero initialization, and eight-ref lifecycle; original source spelling remains inferred.
- Address: `0x0069be00`
- Current IDA item: `TextEditPane *g_pActiveTextEditPane`, four bytes, eight refs, zero bytes, blank address comments
- Historical aliases: `dword_69BE00` (raw IDA) and `g_pCopyWindowTextEditPane` (consumer-biased generated name)
- Likely owner: [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- Exact storage: [UID:000302][0x0069be00-0x0069be04.g_pActiveTextEditPane](by-memory/0x0069be00-0x0069be04.g_pActiveTextEditPane.md)
- Formal C++: first-draft source declaration emitted through the TextEditPane module state; exact storage child remains the binary storage split.

## Purpose

This global tracks the currently active [UID:0000EO][TextEditPane](by-class/TextEditPane.md) for editor commands and dialog callbacks. It is set during `TextEditPane` construction when the style flags allow the pane to become active, cleared during `TextEditPane` destruction if it still points to that pane, and consumed by [UID:000039][CopyWindow](by-class/CopyWindow.md).

## Evidence Notes

- IDA xrefs show writes in `TextEditPane::TextEditPane` at `0x0058dd5c`/`0x0058dd6b` and `TextEditPane::~TextEditPane` at `0x0058e181`/`0x0058e18d`.
- `CopyWindow::OnPrimaryButton` at `0x00554520` reads this pointer, calls `TextEditPane::CopyAllToClipboard` at `0x00590520`, then clears the pointer without a null guard.
- `CopyWindow::OnSecondaryButton` at `0x00554540` clears the pointer without calling into the editor.
- The connection-closed/reconnect init helper at `0x00553e60` checks this pointer before optionally allocating a `CopyWindow`.
- 2026-05-26 IDA MCP `xrefs_to 0x0069be00` reports the same eight data xrefs: one read in `0x00553e60`, two callback xrefs in `0x00554520`, one clear in `0x00554540`, two constructor writes in `0x0058dce0`, and two destructor xrefs in `0x0058e140`.
- The `g_pCopyWindowTextEditPane` alias describes one consumer but is too narrow for the shared active-editor pointer.
- [UID:000302][0x0069be00-0x0069be04.g_pActiveTextEditPane](by-memory/0x0069be00-0x0069be04.g_pActiveTextEditPane.md) now isolates the exact four-byte `.data` storage from the adjacent mixed terminal/text-edit cluster. This parent page clears the corrected `85/85` direct-parent gate for that storage child.
- A004 Batch 056 attempted a live IDA MCP refresh, but repeated `py_eval`, `xrefs_to`, and `idb_meta` calls timed out. The confidence raise uses the already written IDA-backed eight-xref set and exact storage split, not new live facts.
- 2026-06-30 B004 corrected TextEditPane implementation callback used current MCP evidence from database `supervisor_resume_20260629`: `xrefs_to 0x0069be00` still reports eight references, with external/CopyWindow uses at `0x00553e84`, `0x00554520`, `0x0055452b`, and `0x00554540`, TextEditPane constructor reads/writes at `0x0058dd5c` and `0x0058dd6b`, and destructor tests/clears at `0x0058e181` and `0x0058e18d`. Current storage sampling reports `get_int u32le 0x0069be00 == 0` and zero initializer bytes, superseding the older no-code declaration direction.
- 2026-07-30 supervisor catalog0376 applied and verified `TextEditPane *g_pActiveTextEditPane` over exact `[0x0069be00,0x0069be04)`, preserving all eight refs, zero bytes, and blank address comments, then saved IDB SHA256 `4A9360D1E70338D03A5B7C2D6455BE5A5DAED90EDA071FB2DAC4E815A2526C94`.

## Naming Notes

The `g_pCopyWindowTextEditPane` alias describes one consumer but is too narrow. Use `g_pActiveTextEditPane` in documentation until a stronger original symbol is recovered.

First-draft source declaration direction, once emitted through the TextEditPane implementation module, is:

```cpp
TextEditPane *g_pActiveTextEditPane = NULL;
```

Keep this as TextEditPane module state; CopyWindow remains a consumer and should not provide the canonical global name.

## UID0000IH Declaration And Consumer Closure - 2026-08-18

- Formal CPP remains exactly `TextEditPane *g_pActiveTextEditPane = NULL;` in the TextEditPane source family. Formal H now declares exactly `extern TextEditPane *g_pActiveTextEditPane;` for the ReconnectDialog translation-unit consumer.
- The exact zero-initialized four-byte storage remains [UID:000302][0x0069be00-0x0069be04.g_pActiveTextEditPane](by-memory/0x0069be00-0x0069be04.g_pActiveTextEditPane.md), with eight references at `0x00553e84`, `0x00554520`, `0x0055452b`, `0x00554540`, `0x0058dd5c`, `0x0058dd6b`, `0x0058e181`, and `0x0058e18d`.
- TextEditPane construction/destruction owns publication and clearing. The helper reads the pointer before optional `CopyWindow` construction; primary CopyWindow behavior calls `CopyAllToClipboard()` and clears it; secondary behavior only clears it.
- Historical `dword_69BE00`, `g_pCopyWindowTextEditPane`, `SelectAll`, `OnAccept`, and `OnCancel` spellings remain evidence aliases only. They do not change canonical global ownership or the current virtual/API names.
- Score `92/93` reflects exact type/storage/initializer/xrefs/owner, one-definition route, formal CPP definition, required formal H declaration, and all consumer behavior. Original source spelling remains the bounded confidence cap.

## Cross-References

- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000EO][TextEditPane](by-class/TextEditPane.md)
- [UID:0000IH][CopyWindow](by-file/CopyWindow.md)
- [UID:0001FV][0x005544c0-0x0055454b.CopyWindow](by-memory/0x005544c0-0x0055454b.CopyWindow.md)
- [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md)
- [UID:000302][0x0069be00-0x0069be04.g_pActiveTextEditPane](by-memory/0x0069be00-0x0069be04.g_pActiveTextEditPane.md)

## Changes

- 2026-07-30 B010 UID0002AP post-Gate2B reconciliation:
  - Replaced `dword_69BE00` as current IDA state with applied `TextEditPane *g_pActiveTextEditPane`; retained both raw and consumer-biased aliases as historical evidence.
  - Preserved the formal definition, TextEditPane ownership, zero initializer, eight-ref lifecycle, and current `90/90` metadata.

- 2026-06-30 B004 corrected TextEditPane implementation callback:
  - Before: `88/86`, formal C++ blank, with only first-draft declaration direction in prose.
  - Changed to: `90/90`; inserted the first-draft module global declaration `TextEditPane *g_pActiveTextEditPane = NULL;`.
  - Evidence: current MCP evidence from `supervisor_resume_20260629` reconfirmed the eight xrefs at `0x00553e84`, `0x00554520`, `0x0055452b`, `0x00554540`, `0x0058dd5c`, `0x0058dd6b`, `0x0058e181`, and `0x0058e18d`, and sampled the exact storage at `0x0069be00` as a zero-initialized pointer. The historical `g_pCopyWindowTextEditPane` alias remains too narrow because TextEditPane owns constructor/destructor state while CopyWindow only consumes it.

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/84`. Summary/evidence: the page documents address, active `TextEditPane` role, constructor/destructor writes, `CopyWindow` and reconnect consumers, IDA xref recheck, alias correction, and class/memory refs.
- 2026-06-05: Marked reconstructable under [UID:0000ON][TextEditPane](by-file/TextEditPane.md). Evidence: live IDA MCP reports the same eight xrefs to `0x0069be00`; decompilation confirms `0x0058dce0` writes the active pointer, `0x0058e140` clears it when destroying the active editor, and `0x00554520` consumes and clears it from the copy-window accept handler.
- 2026-06-07 A004 Batch 056 parent-gate refresh:
  - Before: `88/84`, below the corrected confidence gate for exact storage assignment.
  - Changed to: `88/86`, linking exact child [UID:000302][0x0069be00-0x0069be04.g_pActiveTextEditPane](by-memory/0x0069be00-0x0069be04.g_pActiveTextEditPane.md).
  - Summary/evidence: the existing IDA-backed eight-xref set now has an exact memory child and still supports TextEditPane ownership over the narrower CopyWindow alias. Live MCP refresh timed out, so the page stays below final-source confidence and no C++ declaration was emitted.

- 2026-06-20 B005 Rule 26 source-quality incorporation:
  - Score unchanged at `88/86`; formal C++ remains blank.
  - Added first-draft declaration direction `TextEditPane *g_pActiveTextEditPane = 0;` and reconfirmed that `g_pCopyWindowTextEditPane` is only a historical/generated consumer alias.
  - Evidence: B005 report matched constructor/destructor ownership and CopyWindow consumption against the exact storage child [UID:000302][0x0069be00-0x0069be04.g_pActiveTextEditPane](by-memory/0x0069be00-0x0069be04.g_pActiveTextEditPane.md).

## UID0000OJ Whole-File Incorporation - 2026-08-16

C0000OJ-427 preserves the exact `TextEditPane *g_pActiveTextEditPane = NULL` definition; the owner page retains that formal source while the consolidated UID0000EO channel emits it once before all address-ordered bodies.
