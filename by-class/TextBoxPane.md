*** UID:0000EI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TextBoxPane

## Status

- Confidence: strong for the `TextEditPane`-derived control role, live override/constructor boundaries, vtable installation, constructor caller set, IME focus behavior, and cursor/line invalidation behavior; medium for final field and public API names.
- Likely source file: [UID:0000OJ][TextBoxPane](by-file/TextBoxPane.md)
- Main address ranges: `0x00591300-0x005913f9` and `0x00595390-0x005954b3`
- Parent attachment: [UID:0000OJ][TextBoxPane](by-file/TextBoxPane.md) has a documented `NexusTK/ui/controls/` reconstruction path and covers this text-box control family.

## Class Purpose

`TextBoxPane` is a [UID:0000EO][TextEditPane](by-class/TextEditPane.md) derivative that customizes cursor visibility and line invalidation for a bordered or constrained text box. It can construct with optional initial text, multiline mode, and scrollbar support.

## Method Families

| Range | Function | Role |
| --- | --- | --- |
| `0x00591300-0x0059136a` | `EnsureCursorVisible` | Converts cursor word `+0x144` through the caret-position helper, clamps against visible bounds at `+0x120`, adds line height, and invalidates the computed rectangle through the pane vtable callback. |
| `0x00591370-0x005913f9` | `InvalidateLineRange` | Builds a temporary line-region list, delegates range-to-rect generation to `0x00591520`, invalidates each generated region, and destroys the temporary list. |
| `0x00595390-0x005954b3` | `TextBoxPane::TextBoxPane` | Constructs the `TextEditPane` base, installs three `TextBoxPane` vtables, applies optional initial text, updates style bits at `+0x15c`, assigns IME focus, and refreshes cursor/line visibility. |

## Evidence Notes

- IDA MCP reports exact override/constructor ranges: `0x00591300-0x0059136a` (`sub_591300`), `0x00591370-0x005913f9` (`sub_591370`), and `0x00595390-0x005954b3` (`sub_595390`).
- IDA MCP reports eight direct constructor call sites at `0x00495580`, `0x004f1ced`, `0x004f1ead`, `0x004f2145`, `0x004f21fd`, `0x00508549`, `0x0051385f`, and `0x00514814`, across six caller functions.
- Live IDA names the `TextBoxPane` vtable family at `0x0062e070`, `0x0062e0e8`, and `0x0062e118`, with constructor stores at `0x005953fd`, `0x00595403`, and `0x0059540d`.
- Constructor decompilation calls `sub_58DCE0` for the `TextEditPane` base, writes the three vtables, inserts optional wide text through `sub_58FC30`, sets style bit `0x4`, calls `sub_4E80A0(g_pIMEPane, this, 0)`, clears bit `0x80`, and calls either `0x00591300` or `0x00591370` based on cursor/line words at `+0x144/+0x146`.
- Override xrefs show the cursor helper is reused from text-edit paths (`0x0058eb20`, `0x0058f335`, `0x0058f444`, `0x0058fc13`) and the constructor (`0x00595499`), while the line-range helper is reused from text-edit paths (`0x0058eb13`, `0x0058f420`, `0x0058f42d`, `0x0058fbdc`, `0x0058fc0c`) and the constructor (`0x00595490`).

## Cross-References

- [UID:0000OJ][TextBoxPane](by-file/TextBoxPane.md)
- [UID:0001JO][0x00591300-0x005954b3.TextBoxPane](by-memory/0x00591300-0x005954b3.TextBoxPane.md)
- [UID:0000EO][TextEditPane](by-class/TextEditPane.md)

## Changes

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
