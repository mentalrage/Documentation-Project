*** UID:0000OJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# TextBoxPane

## Status

- Confidence: strong for `TextBoxPane` as a small `TextEditPane`-derived UI control source, with live constructor/override boundaries, vtable stores, IME focus behavior, and parent path; medium for final public names and possible later fold into `TextEditPane`.
- Proposed module: `ui/controls/TextBoxPane.cpp`, with possible later merge into [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- Reviewed source-family inputs: `TextBoxPane` class page plus exact memory children for cursor/line invalidation overrides and the constructor.
- Main address clusters: `0x00591300-0x005913f9` and `0x00595390-0x005954b3`

## File Role

`TextBoxPane` is a small [UID:0000ON][TextEditPane](by-file/TextEditPane.md) derivative for bordered or constrained text-box display/editing. It customizes cursor visibility and invalidation behavior, then constructs the base text editor with optional initial text, multiline mode, read-only behavior, and scrollbar support.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `TextBoxPane` | `0x00595390-0x005954b3` | Constructor that builds the text-edit base and applies initial text/style/caret visibility. |
| `EnsureCursorVisible` | `0x00591300-0x0059136a` | Computes a visible line rectangle and applies clip bounds. |
| `InvalidateLineRange` | `0x00591370-0x005913f9` | Builds temporary line-region list and invalidates/sets clip bounds for each affected line. |

## Ownership Decision

Keep this as a small neighboring `ui/controls/TextBoxPane.cpp` for now. It is a true `TextEditPane` derivative, but its constructor has eight direct callers and a distinct text-box role. If later ownership migration prefers fewer text-edit source files, this can fold into `TextEditPane.cpp`.

## Evidence Notes

- IDA MCP reports exact function ranges `0x00591300-0x0059136a`, `0x00591370-0x005913f9`, and `0x00595390-0x005954b3`.
- IDA MCP reports eight direct references to `TextBoxPane::TextBoxPane` at `0x00595390`, across six caller functions.
- IDA MCP names `TextBoxPane` vtables at `0x0062e070`, `0x0062e0e8`, and `0x0062e118`; constructor stores reference them at `0x005953fd`, `0x00595403`, and `0x0059540d`.
- The constructor calls `TextEditPane::TextEditPane`, installs `TextBoxPane` vtables, applies optional initial text, sets style flag `4`, calls `g_pIMEPane->SetFocusPane`, and then ensures/invalidate line visibility.
- The method ranges at `0x00591300` and `0x00591370` override or specialize core text-edit caret/line invalidation behavior.

## Cross-References

- [UID:0000EI][TextBoxPane](by-class/TextBoxPane.md)
- [UID:0001JO][0x00591300-0x005954b3.TextBoxPane](by-memory/0x00591300-0x005954b3.TextBoxPane.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000K5][IMEPanes](by-file/IMEPanes.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `78` and confidence to `80`.
  - Evidence: document covers text-box role, proposed contents, ownership decision, constructor evidence, override/helper ranges, and cross-references; completion remains lower because behavior and fields are summarized rather than deeply reconstructed.
- 2026-06-01: `PROPOSED_RECONSTRUCTION_PATH` changed from blank to `NexusTK/ui/controls/`.
  - Evidence: the page already proposed `ui/controls/TextBoxPane.cpp`, and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `TextBoxPane.cpp` with neighboring UI controls.
- 2026-06-03: constructor range corrected from `0x00595390-0x005954b2` to `0x00595390-0x005954b3`.
  - Evidence: live IDA MCP reports [UID:0002RV][0x00595390-0x005954b3.TextBoxPaneConstructor](by-memory/0x00595390-0x005954b3.TextBoxPaneConstructor.md) as size `0x123`, with `retn 18h` occupying the final three bytes.
- 2026-06-04: Raised completion/confidence from `78/80` to `82/84` and corrected the override cluster to `0x00591300-0x005913f9`.
  - Evidence: live IDA MCP confirms exact override and constructor ranges, eight constructor call sites, three `TextBoxPane` vtable stores, `TextEditPane` base construction, optional text insertion, IME focus assignment, and cursor/line invalidation behavior.
  - Remaining limits: score stays below final-source level because exact field names and the final decision on a standalone source file versus a `TextEditPane` fold-in remain open.
