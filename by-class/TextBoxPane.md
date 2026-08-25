*** UID:0000EI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ON | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000ON | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class TextBoxPane : public TextEditPane
{
public:
    TextBoxPane(int viewportWidth,
                int viewportHeight,
                bool blackBackground,
                int textColor,
                int textBackColor,
                const wchar_t *initialText);

protected:
    virtual bool OnKeyEvent(Event *)
    {
        return false;
    }

    virtual bool OnMouseEvent(Event *)
    {
        return false;
    }
};

typedef char TextBoxPaneSizeMustBe174[
    (sizeof(TextBoxPane) == 0x174) ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TextBoxPane

## Status

- Current UID0000OJ disposition: `TextBoxPane` is a fieldless class inside the UID0000ON TextEditPane source family, not a standalone file owner. This authoritative formal H emits directly to UID0000ON at explicit file-root position 10, after UID0000EO's complete `TextEditPane` declaration; UID0002RV emits the constructor directly into UID0000ON source order. The two differential virtual slots are exact inline false overrides and the destructor is implicit.
- Confidence: very strong for the fieldless `TextEditPane`-derived role, inline false overrides, exact constructor boundary and caller set, vtable installation, current constructor source, and shared TextEditPane invalidation-helper calls. Unrecoverable original lexical spelling is the remaining confidence cap.
- Source family: [UID:0000ON][TextEditPane](by-file/TextEditPane.md); [UID:0000OJ][TextBoxPane](by-file/TextBoxPane.md) is the retained non-emitting alias/evidence page.
- Main address ranges: `0x00591300-0x005913f9` and `0x00595390-0x005954b3`
- Parent attachment: UID0000ON owns the merged source unit; UID0000OJ preserves complete target-specific history and evidence without emitting a second file.
- Formal C++ status: formal CPP remains blank by design; the complete fieldless declaration, inline overrides, implicit-destructor disposition, and exact size assertion are in formal H. UID0002RU is reclassified as two `TextEditPane` invalidation helpers, while UID0002RV remains the sole TextBoxPane body.

## UID0000OJ Whole-File Incorporation - 2026-08-16

| Claim | Incorporated disposition |
| --- | --- |
| C0000OJ-008 | `OnMouseEvent(Event *)` is an exact inline false override. |
| C0000OJ-009 | `OnKeyEvent(Event *)` is an exact inline false override. |
| C0000OJ-010 | Destructor is implicit; no handwritten destructor body is introduced. |
| C0000OJ-011 / C0000OJ-030 / C0000OJ-461 | Complete fieldless `0x174` C++03 declaration and size assertion are formal H. |
| C0000OJ-033 | Canonical owner and H emitter are UID0000ON; explicit H position 10 places the sole definition after UID0000EO/TextEditPane. |
| C0000OJ-064 | Existing named types remain protection-only; no UDT, frame, or type mutation is delegated to this ordinary-document callback. |
| C0000OJ-068 | Exact manual-coverage payload remains supervisor-owned and unchanged. |

## Class Purpose

`TextBoxPane` is a fieldless [UID:0000EO][TextEditPane](by-class/TextEditPane.md) derivative. Its only differential virtual behavior is the exact inline-false `OnKeyEvent` and `OnMouseEvent` pair; caret and selection invalidation remain shared `TextEditPane` helpers rather than `TextBoxPane` overrides.
The constructor accepts viewport dimensions, the current source-facing `blackBackground` flag, text and text-background colors, and optional initial text.

## Method Families

| Range | Function | Role |
| --- | --- | --- |
| `0x00591300-0x0059136a` | `TextEditPane::InvalidateCaret` | Shared base-class helper that computes and invalidates the caret rectangle; [UID:0002RU][0x00591300-0x005913f9.TextEditPaneCaretAndSelectionInvalidationHelpers](by-memory/0x00591300-0x005913f9.TextEditPaneCaretAndSelectionInvalidationHelpers.md) emits it through UID0000ON. `TextBoxPane` is a caller only. |
| `0x00591370-0x005913f9` | `TextEditPane::InvalidateSelectionRange` | Shared base-class helper that builds and invalidates rectangles for a text range; UID0002RU emits it through UID0000ON. `TextBoxPane` is a caller only. |
| `0x00595390-0x005954b3` | `TextBoxPane::TextBoxPane` | Constructs the `TextEditPane` base with `kTextEditBlackBackground` when requested, installs the three `TextBoxPane` vtables, optionally calls `InsertTextRange`, and closes with `SetEditActiveState(false, false)`. [UID:0002RV][0x00595390-0x005954b3.TextBoxPaneConstructor](by-memory/0x00595390-0x005954b3.TextBoxPaneConstructor.md) emits the sole TextBoxPane body through UID0000ON. |

## Evidence Notes

- IDA MCP reports exact shared-helper/constructor ranges: `0x00591300-0x0059136a` (`sub_591300`), `0x00591370-0x005913f9` (`sub_591370`), and `0x00595390-0x005954b3` (`sub_595390`).
- IDA MCP reports eight direct constructor call sites at `0x00495580`, `0x004f1ced`, `0x004f1ead`, `0x004f2145`, `0x004f21fd`, `0x00508549`, `0x0051385f`, and `0x00514814`, across six caller functions.
- Live IDA names the `TextBoxPane` vtable family at `0x0062e070`, `0x0062e0e8`, and `0x0062e118`, with constructor stores at `0x005953fd`, `0x00595403`, and `0x0059540d`.
- Constructor decompilation calls `sub_58DCE0` for the `TextEditPane` base, writes the three vtables, inserts optional wide text through `sub_58FC30`, sets style bit `0x4`, calls `sub_4E80A0(g_pIMEPane, this, 0)`, clears bit `0x80`, and calls either `0x00591300` or `0x00591370` based on cursor/line words at `+0x144/+0x146`.
- Helper xrefs show caret invalidation is reused from text-edit paths (`0x0058eb20`, `0x0058f335`, `0x0058f444`, `0x0058fc13`) and the constructor (`0x00595499`), while selection-range invalidation is reused from text-edit paths (`0x0058eb13`, `0x0058f420`, `0x0058f42d`, `0x0058fbdc`, `0x0058fc0c`) and the constructor (`0x00595490`).
- 2026-06-12 A004 live IDA MCP `entity_query` and `trace_data_flow` reconfirm the exact `TextBoxPane` vtable-data child [UID:0003GC][0x0062e06c-0x0062e120.TextBoxPaneVtableData](by-memory/0x0062e06c-0x0062e120.TextBoxPaneVtableData.md): named heads at `0x0062e070`, `0x0062e0e8`, and `0x0062e118`, constructor stores at `0x005953fd`, `0x00595403`, and `0x0059540d`, and successor `EPFTextEditObject` vtable at `0x0062e124`.
- Offsets `+0xa0` / `160`, `+0xa4` / `164`, and constructor size `0x123` / `291` were verified with live IDA MCP `int_convert`.
- 2026-06-25 B004 MCP session `80de0a67` reconfirmed healthy `NexusTK.exe` IDB state, exact function sizes for [UID:0002RU][0x00591300-0x005913f9.TextEditPaneCaretAndSelectionInvalidationHelpers](by-memory/0x00591300-0x005913f9.TextEditPaneCaretAndSelectionInvalidationHelpers.md) and [UID:0002RV][0x00595390-0x005954b3.TextBoxPaneConstructor](by-memory/0x00595390-0x005954b3.TextBoxPaneConstructor.md), full helper and constructor xref lists, child decompilation behavior, constructor call-site argument windows, and padding on both sides of the exact children.

### Historical / Superseded Naming and Routing Evidence

- Historical B004 source-facing names `TextEditCaretPosition`, `m_textAreaBounds`, `BuildLineInvalidationRects`, `enableTextBoxStyle`, and `SetFocusRegistration` were provisional. Complete TextEditPane reconstruction superseded them with the current shared-helper ownership and source-clean formal names.
- Historical 2026-06-28 B008 evidence routed UID0002RV through standalone UID0000OJ and preserved `maxWidth`, `maxHeight`, `enableTextBoxStyle`, `backgroundColor`, `scrollColor`, `SetText`, and `SetFocusRegistration`. That route and those provisional names lost to the complete UID0000ON merged-unit ordering, caller evidence, and accepted constructor formal; the warning against an invented `isMultiline` semantic remains valid.

## Source Reconstruction State

- [UID:0002RU][0x00591300-0x005913f9.TextEditPaneCaretAndSelectionInvalidationHelpers](by-memory/0x00591300-0x005913f9.TextEditPaneCaretAndSelectionInvalidationHelpers.md) emits accepted formal C++ for `TextEditPane::InvalidateCaret` and `TextEditPane::InvalidateSelectionRange` through [UID:0000ON][TextEditPane](by-file/TextEditPane.md); these are not TextBoxPane members.
- [UID:0002RV][0x00595390-0x005954b3.TextBoxPaneConstructor](by-memory/0x00595390-0x005954b3.TextBoxPaneConstructor.md) emits the accepted `TextBoxPane::TextBoxPane` body through UID0000ON in the merged source order.
- [UID:0001JO][0x00591300-0x005954b3.TextEditPaneAndTextBoxPaneNoncontiguousAuditMap](by-memory/0x00591300-0x005954b3.TextEditPaneAndTextBoxPaneNoncontiguousAuditMap.md) remains a non-emitting audit map; do not promote the broad range or paste child code into it.
- Current routing requires both shared invalidation helpers to remain `TextEditPane` members and the constructor to remain the sole TextBoxPane body; neighboring support-object islands and vtable/compiler-adjustment bytes remain non-source.
- The class is `94/94`: fieldless layout, exact size, inline false overrides, implicit destructor, merged-unit placement, and constructor source are closed. Only unrecoverable private lexical spelling prevents a perfect score.

## Cross-References

- [UID:0000OJ][TextBoxPane](by-file/TextBoxPane.md)
- [UID:0001JO][0x00591300-0x005954b3.TextEditPaneAndTextBoxPaneNoncontiguousAuditMap](by-memory/0x00591300-0x005954b3.TextEditPaneAndTextBoxPaneNoncontiguousAuditMap.md)
- [UID:0000EO][TextEditPane](by-class/TextEditPane.md)
- [UID:0003GC][0x0062e06c-0x0062e120.TextBoxPaneVtableData](by-memory/0x0062e06c-0x0062e120.TextBoxPaneVtableData.md)

## Changes

- 2026-08-22 Agent-B009 UID0000OJ Gate 2A repair: routed the authoritative TextBoxPane formal H directly to UID0000ON at position 10 after UID0000EO, eliminating the copied and child-routed duplicate while preserving the same merged file owner and class body.

- 2026-08-22 Agent-B009 UID0000OJ eleven-claim callback: corrected active helper ownership/names to `TextEditPane::InvalidateCaret` and `TextEditPane::InvalidateSelectionRange`, aligned the constructor description with its accepted formal, restored the current `94/94` closure, and moved superseded B004/B008 names and standalone routing under explicit history.

### Historical / Superseded Change Log

- 2026-06-28 B008 implementation callback (historical provisional state):
  - Score unchanged at `85/88`.
  - Preserved [UID:0002RV][0x00595390-0x005954b3.TextBoxPaneConstructor](by-memory/0x00595390-0x005954b3.TextBoxPaneConstructor.md) as first-draft formal C++ through [UID:0000OJ][TextBoxPane](by-file/TextBoxPane.md), added the accepted B008 constructor source-facing names/rejected alternatives, and clarified that `enableTextBoxStyle` is the accepted style-flag name rather than a proven `isMultiline` semantic.

- 2026-06-25 B004 implementation callback:
  - Score unchanged at `85/88`.
  - Updated class status, method inventory, evidence notes, and source reconstruction state to reflect that [UID:0002RU][0x00591300-0x005913f9.TextEditPaneCaretAndSelectionInvalidationHelpers](by-memory/0x00591300-0x005913f9.TextEditPaneCaretAndSelectionInvalidationHelpers.md) and [UID:0002RV][0x00595390-0x005954b3.TextBoxPaneConstructor](by-memory/0x00595390-0x005954b3.TextBoxPaneConstructor.md) now carry first-draft formal C++ through [UID:0000OJ][TextBoxPane](by-file/TextBoxPane.md), while this class page remains support/declaration context.
  - Evidence: B004 MCP session `80de0a67` reconfirmed exact override/constructor sizes, xrefs, decompilation behavior, call-site argument windows, padding, TextBoxPane-specific vtables, and rejected TextEditPane/support-object ownership alternatives.
  - Remaining caps: final field/helper/public spellings and class declaration layout remain unresolved, so no class score increase or class-level formal C++ was added.

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `78`, confidence `76`.
- Evidence: the page documents the `TextEditPane` derivative role, constructor and cursor/line invalidation helpers, direct constructor callers, and IME focus behavior; completion remains limited because broader text-box virtual/destructor coverage and exact style fields are not yet detailed.
- 2026-06-03:
  - Corrected constructor range from `0x00595390-0x005954b2` to `0x00595390-0x005954b3`.
  - Evidence: live IDA MCP reports [UID:0002RV][0x00595390-0x005954b3.TextBoxPaneConstructor](by-memory/0x00595390-0x005954b3.TextBoxPaneConstructor.md) as size `0x123`, with an exclusive end at `0x005954b3`.
- 2026-06-04:
  - Corrected the cursor/line override aggregate from `0x00591300-0x005913f8` to `0x00591300-0x005913f9`, raised completion/confidence from `78/76` to `84/86`, set `RECONSTRUCTABLE:TRUE`, and attached the class to [UID:0000OJ][TextBoxPane](by-file/TextBoxPane.md).
  - Evidence: live IDA MCP reports `sub_591300` as `0x00591300-0x0059136a`, `sub_591370` as `0x00591370-0x005913f9`, and `sub_595390` as `0x00595390-0x005954b3`; it also confirms eight constructor call sites, three `TextBoxPane` vtable stores, `TextEditPane` base construction, optional wide-text insertion, IME focus assignment, and cursor/line refresh calls.
  - Remaining limits: scores stay below final-source level because exact field names, helper names, and public constructor parameter names are still inferred.
- 2026-06-12 A004 Batch 277:
  - Before: `COMPLETION:84`, `CONFIDENCE:86`.
  - After: `COMPLETION:85`, `CONFIDENCE:88`; parent remains [UID:0000OJ][TextBoxPane](by-file/TextBoxPane.md).
  - Evidence: live IDA MCP reconfirmed the exact `TextBoxPane` vtable child, all three constructor vptr stores, constructor size/boundary, `EPFTextEditObject` successor boundary, and converted adjusted-base offsets. The exact vtable child [UID:0003GC][0x0062e06c-0x0062e120.TextBoxPaneVtableData](by-memory/0x0062e06c-0x0062e120.TextBoxPaneVtableData.md) is now assigned here because both child and direct class parent clear the strict `85/85` gate.

- 2026-06-13 support-object crossing repair:
  - Score unchanged at `85/88`; updated the broad [UID:0001JO][0x00591300-0x005954b3.TextEditPaneAndTextBoxPaneNoncontiguousAuditMap](by-memory/0x00591300-0x005954b3.TextEditPaneAndTextBoxPaneNoncontiguousAuditMap.md) cross-reference after it was renamed/reclassified as a parentless audit map.
  - Evidence: live IDA MCP confirmed the exact constructor and override children remain the `TextBoxPane` source-bearing code while neighboring support-object ranges route through `TextEditPane`.
