*** UID:0000OJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# TextBoxPane

## Current UID0000OJ Source-Family Disposition - 2026-08-16

- `TextBoxPane` is a reviewed non-emitting alias, not a standalone source unit. Its reconstruction path and canonical owner are `NONE`; no `TextBoxPane.cpp` or `TextBoxPane.h` is emitted.
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md) is the sole source family. [UID:0000EO][TextEditPane](by-class/TextEditPane.md) owns the complete merged C++03 CPP/H declarations and source order, including the fieldless [UID:0000EI][TextBoxPane](by-class/TextBoxPane.md) declaration and [UID:0002RV][0x00595390-0x005954b3.TextBoxPaneConstructor](by-memory/0x00595390-0x005954b3.TextBoxPaneConstructor.md) body.
- The local machine-code inventory remains complete: `0x00591300` is `TextEditPane::InvalidateCaret`, `0x00591370` is `TextEditPane::InvalidateSelectionRange`, and `0x00595390` is the TextBoxPane constructor. Only the constructor belongs to the derived class.
- The constructor uses `(viewportWidth, viewportHeight, blackBackground, textColor, textBackColor, initialText)`, inserts initial text through `InsertTextRange(initialText, (short)wcslen(initialText), 0, 0)`, and completes with `SetEditActiveState(false, false)`. The two derived Event handlers are inline false overrides; the destructor is implicit; the derived class adds no fields and remains exactly `0x174` bytes.
- Exact caller contracts, three vtable identities, RTTI, five `0xcc` padding spans, physical range boundaries, rejected standalone alternative, and dated generated-output evidence are preserved below. The effective selected-unit score is `94/94` because every source-authored item is formally routed through UID0000ON/UID0000EO.

## UID0000OJ Incorporation Ledger - 2026-08-16

| Claims | Incorporated disposition |
| --- | --- |
| C0000OJ-001/-002/-032/-050/-055/-056/-057 | Non-standalone alias, `NONE` path/owner, history preservation, absence of standalone output, valid pointer-only forward declarations, and historical generated/archive evidence. |
| C0000OJ-004/-026 | Complete three-member local inventory and five exact padding/EH-separation spans retained. |
| C0000OJ-068/-069 | Exact manual-coverage payload remains present in the accepted report but supervisor-owned for coverage-file incorporation. |

## Historical Pre-UID0000OJ Status

- Confidence: strong for `TextBoxPane` as a small `TextEditPane`-derived UI control source, with live constructor/override boundaries, vtable stores, IME focus behavior, parent path, and first-draft child C++ readiness; medium for final public names and possible later fold into `TextEditPane`.
- Proposed module: `ui/controls/TextBoxPane.cpp`, with possible later merge into [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- Reviewed source-family inputs: `TextBoxPane` class page plus exact memory children for cursor/line invalidation overrides and the constructor.
- Main address clusters: `0x00591300-0x005913f9` and `0x00595390-0x005954b3`
- Formal C++ status: exact source-bearing child pages [UID:0002RU][0x00591300-0x005913f9.TextEditPaneCaretAndSelectionInvalidationHelpers](by-memory/0x00591300-0x005913f9.TextEditPaneCaretAndSelectionInvalidationHelpers.md) and [UID:0002RV][0x00595390-0x005954b3.TextBoxPaneConstructor](by-memory/0x00595390-0x005954b3.TextBoxPaneConstructor.md) now emit first-draft C++ through this file root; this by-file page remains source-placement/support context and does not have a formal C++ block.

## Historical Pre-UID0000OJ File Role

`TextBoxPane` is a small [UID:0000ON][TextEditPane](by-file/TextEditPane.md) derivative for bordered or constrained text-box display/editing. It customizes cursor visibility and invalidation behavior, then constructs the base text editor with optional initial text, the accepted source-facing `enableTextBoxStyle` flag, and color/scroll configuration.
The binary proves a style-flag selection, not a direct `isMultiline` API name.

## Historical Pre-UID0000OJ Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `TextBoxPane` | `0x00595390-0x005954b3` | Constructor that builds the text-edit base and applies initial text/style/caret visibility; emitted as first-draft C++ by [UID:0002RV][0x00595390-0x005954b3.TextBoxPaneConstructor](by-memory/0x00595390-0x005954b3.TextBoxPaneConstructor.md). |
| `EnsureCursorVisible` | `0x00591300-0x0059136a` | Computes a visible line rectangle and applies clip bounds; emitted as first-draft C++ by [UID:0002RU][0x00591300-0x005913f9.TextEditPaneCaretAndSelectionInvalidationHelpers](by-memory/0x00591300-0x005913f9.TextEditPaneCaretAndSelectionInvalidationHelpers.md). |
| `InvalidateLineRange` | `0x00591370-0x005913f9` | Builds a temporary line-region list and invalidates each affected line rectangle; emitted as first-draft C++ by [UID:0002RU][0x00591300-0x005913f9.TextEditPaneCaretAndSelectionInvalidationHelpers](by-memory/0x00591300-0x005913f9.TextEditPaneCaretAndSelectionInvalidationHelpers.md). |
| [UID:0003GC][0x0062e06c-0x0062e120.TextBoxPaneVtableData](by-memory/0x0062e06c-0x0062e120.TextBoxPaneVtableData.md) | `0x0062e06c-0x0062e120` | Source-declared/generated-binary vtable data for the primary and adjusted-base `TextBoxPane` tables. |

## Historical Pre-UID0000OJ Ownership Decision

Keep this as a small neighboring `ui/controls/TextBoxPane.cpp` for now. It is a true `TextEditPane` derivative, but its constructor has eight direct callers and a distinct text-box role. If later ownership migration prefers fewer text-edit source files, this can fold into `TextEditPane.cpp`.

The accepted first-draft method bodies do not change that source-placement decision. `TextEditPane` remains the base/helper provider, while the constructor vtables, constructor fanout, and override behavior are TextBoxPane-specific. The broad historical [UID:0001JO][0x00591300-0x005954b3.TextEditPaneAndTextBoxPaneNoncontiguousAuditMap](by-memory/0x00591300-0x005954b3.TextEditPaneAndTextBoxPaneNoncontiguousAuditMap.md) map remains parentless and non-emitting.

## Historical Pre-UID0000OJ Evidence Notes

- IDA MCP reports exact function ranges `0x00591300-0x0059136a`, `0x00591370-0x005913f9`, and `0x00595390-0x005954b3`.
- IDA MCP reports eight direct references to `TextBoxPane::TextBoxPane` at `0x00595390`, across six caller functions.
- IDA MCP names `TextBoxPane` vtables at `0x0062e070`, `0x0062e0e8`, and `0x0062e118`; constructor stores reference them at `0x005953fd`, `0x00595403`, and `0x0059540d`.
- The constructor calls `TextEditPane::TextEditPane`, installs `TextBoxPane` vtables, applies optional initial text, sets style flag `4`, calls `g_pIMEPane->SetFocusPane`, and then ensures/invalidate line visibility.
- The method ranges at `0x00591300` and `0x00591370` override or specialize core text-edit caret/line invalidation behavior.
- 2026-06-12 A004 live IDA MCP confirms the exact vtable-data child [UID:0003GC][0x0062e06c-0x0062e120.TextBoxPaneVtableData](by-memory/0x0062e06c-0x0062e120.TextBoxPaneVtableData.md), including three named table heads, constructor stores at `0x005953fd`, `0x00595403`, and `0x0059540d`, and the `EPFTextEditObject` successor boundary at `0x0062e124`.
- 2026-06-25 B004 MCP session `80de0a67` reconfirmed healthy `NexusTK.exe` IDB state, exact function sizes for [UID:0002RU][0x00591300-0x005913f9.TextEditPaneCaretAndSelectionInvalidationHelpers](by-memory/0x00591300-0x005913f9.TextEditPaneCaretAndSelectionInvalidationHelpers.md) and [UID:0002RV][0x00595390-0x005954b3.TextBoxPaneConstructor](by-memory/0x00595390-0x005954b3.TextBoxPaneConstructor.md), five/six/eight xref sets for the override and constructor starts, decompilation behavior for caret invalidation, line-range invalidation, and constructor setup, focused constructor call-site argument windows, and padding before/after each exact child island.
- 2026-06-28 B008 accepted source-quality refresh keeps [UID:0002RV][0x00595390-0x005954b3.TextBoxPaneConstructor](by-memory/0x00595390-0x005954b3.TextBoxPaneConstructor.md) as first-draft formal C++ through this file root, preserves constructor names `maxWidth`, `maxHeight`, `enableTextBoxStyle`, `backgroundColor`, `scrollColor`, `initialText`, `IsLegacyAssetMode`, `SetText`, `SetFocusRegistration`, `m_selectionStart`, `m_selectionEnd`, and `m_editorFlags`, and explicitly rejects raw helper labels, `isMultiline`, direct `TextEditPane` ownership, adjacent support-object merge, and invented enum names for the unproven style/flag bits.

## 2026-06-14 IDA MCP Refresh

- `lookup_funcs` reconfirms `0x00591300` size `0x6a`, `0x00591370` size `0x89`, and constructor `0x00595390` size `0x123` / 291 bytes (Verified with `int_convert.py`); `0x005954b3` remains a non-function boundary.
- `xrefs_to 0x00595390` still reports eight constructor callsites from six caller functions (`0x00495450`, `0x004f1c00`, `0x004f20a0`, `0x00507c90`, `0x00513800`, and `0x005147d0`), supporting a reusable text-box source root rather than a one-off nested helper.
- `xrefs_to 0x00591300` reports five refs and `xrefs_to 0x00591370` reports six refs, including calls from the constructor at `0x00595499` and `0x00595490` plus TextEditPane-family internal callsites. This keeps the override relationship explicit while preserving the `TextEditPane` dependency.
- `xrefs_to` for the three vtable heads reports constructor stores at `0x005953fd`, `0x00595403`, and `0x0059540d`; the RTTI locator pointer at `0x0062e06c` has no direct code refs, matching source-declared/generated-binary vtable data.
- `callees` shows the constructor calls the base text-edit/control setup, optional text/style/IME helpers, and then both local override helpers; the override helpers call line/clip/region helpers only. This supports the current `ui/controls/TextBoxPane.cpp` placement while exact member names remain open.

## Historical Pre-UID0000OJ Source Reconstruction State

- [UID:0002RU][0x00591300-0x005913f9.TextEditPaneCaretAndSelectionInvalidationHelpers](by-memory/0x00591300-0x005913f9.TextEditPaneCaretAndSelectionInvalidationHelpers.md) now emits first-draft formal C++ for `TextBoxPane::EnsureCursorVisible` and `TextBoxPane::InvalidateLineRange` through this file root.
- [UID:0002RV][0x00595390-0x005954b3.TextBoxPaneConstructor](by-memory/0x00595390-0x005954b3.TextBoxPaneConstructor.md) now emits first-draft formal C++ for `TextBoxPane::TextBoxPane` through this file root.
- [UID:0001JO][0x00591300-0x005954b3.TextEditPaneAndTextBoxPaneNoncontiguousAuditMap](by-memory/0x00591300-0x005954b3.TextEditPaneAndTextBoxPaneNoncontiguousAuditMap.md) remains a non-emitting noncontiguous audit map and must not be recreated at the old `TextBoxPane.md` path.
- Rejected alternatives from the accepted B004 report remain active: no TextEditPane routing for the TextBoxPane children, no TextBoxPane ownership for neighboring support-object ranges, no broad-map source emission, and no vtable/compiler-adjustment bytes as source C++.
- File score remains below final-audit levels because exact public names, field/helper spellings, style-bit enum names, and the standalone-versus-TextEditPane fold decision remain open.

## Historical Pre-UID0000OJ Cross-References

- [UID:0000EI][TextBoxPane](by-class/TextBoxPane.md)
- [UID:0001JO][0x00591300-0x005954b3.TextEditPaneAndTextBoxPaneNoncontiguousAuditMap](by-memory/0x00591300-0x005954b3.TextEditPaneAndTextBoxPaneNoncontiguousAuditMap.md)
- [UID:0003GC][0x0062e06c-0x0062e120.TextBoxPaneVtableData](by-memory/0x0062e06c-0x0062e120.TextBoxPaneVtableData.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000K5][IMEPanes](by-file/IMEPanes.md)

## Changes

- 2026-06-28 B008 implementation callback:
  - Score unchanged at `86/88`.
  - Preserved [UID:0002RV][0x00595390-0x005954b3.TextBoxPaneConstructor](by-memory/0x00595390-0x005954b3.TextBoxPaneConstructor.md) as first-draft formal C++ through this `NexusTK/ui/controls/` file root, added the accepted B008 constructor source-facing names/rejected alternatives, and clarified that `enableTextBoxStyle` is the accepted style-flag name rather than a proven `isMultiline` semantic.

- 2026-06-25 B004 implementation callback:
  - Score unchanged at `86/88`.
  - Updated file status, proposed contents, ownership decision, evidence notes, and source reconstruction state to reflect that [UID:0002RU][0x00591300-0x005913f9.TextEditPaneCaretAndSelectionInvalidationHelpers](by-memory/0x00591300-0x005913f9.TextEditPaneCaretAndSelectionInvalidationHelpers.md) and [UID:0002RV][0x00595390-0x005954b3.TextBoxPaneConstructor](by-memory/0x00595390-0x005954b3.TextBoxPaneConstructor.md) now emit accepted first-draft formal C++ through this `NexusTK/ui/controls/` file root.
  - Evidence: B004 MCP session `80de0a67` reconfirmed exact override/constructor sizes, xrefs, decompilation behavior, call-site argument windows, padding, TextBoxPane-specific vtables, and rejected TextEditPane/support-object ownership alternatives.
  - Remaining caps: final public/member/helper spellings and the possible later fold into `TextEditPane.cpp` remain unresolved, so no file score increase was applied.

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
- 2026-06-12 A004 Batch 277:
  - Before: `COMPLETION:82`, `CONFIDENCE:84`.
  - After: `COMPLETION:85`, `CONFIDENCE:85`.
  - Evidence: live IDA MCP reconfirmed the exact `TextBoxPane` vtable-data child, constructor store sites, constructor extent, and successor boundary. This closes the direct class/file gate for [UID:0000EI][TextBoxPane](by-class/TextBoxPane.md) and its vtable child while keeping final source grouping below the current final C++ source-quality bar.

- 2026-06-13 support-object crossing repair:
  - Score unchanged at `85/85`; updated the broad [UID:0001JO][0x00591300-0x005954b3.TextEditPaneAndTextBoxPaneNoncontiguousAuditMap](by-memory/0x00591300-0x005954b3.TextEditPaneAndTextBoxPaneNoncontiguousAuditMap.md) cross-reference after it was renamed/reclassified as a parentless audit map.
  - Evidence: live IDA MCP confirmed the exact constructor and override children remain the only `TextBoxPane` source-bearing code in the historical range; neighboring support-object children now route through [UID:0000ON][TextEditPane](by-file/TextEditPane.md).
- 2026-06-14 C001 Goal2 score refresh:
  - Before: score `85/85`.
  - Changed to: score `86/88`.
  - Summary/evidence: live IDA MCP reconfirmed exact constructor/override sizes, eight constructor callsites, constructor calls to both override helpers, vtable-store refs, and the `0x005954b3` boundary. No owner/emitter routing changed; exact member names and the standalone-versus-TextEditPane fold decision remain the blockers to a higher score.
