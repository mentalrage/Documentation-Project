*** UID:0000V7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PhoneBookListHelpers 0x0058cfa0 / 0x0058dcb0

## Status

- Confidence: strong for phone-book ownership of `0x0058cfa0`; medium for final name of `0x0058dcb0`.
- Rebuild handling: `source-authored` phone-book helper code that should be recreated through the owning phone-book source module; final parent attachment and C++ are intentionally blank until the owner/source shape reaches the 95% gate.
- Related file/module: [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- Related memory ranges: [UID:0001JE][0x0058c350-0x0058d74c.PhoneBookDialogs](by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md), [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md), [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md), and [UID:0001JG][0x0058d750-0x0058dc5b.DialDialog](by-memory/0x0058d750-0x0058dc5b.DialDialog.md)

## Helpers

| Address | Proposed name | Current issue | Evidence |
| --- | --- | --- | --- |
| `0x0058cfa0-0x0058cfdb` | `PhoneBookListPane::GetSelectedEntryData` | Current `simroot_v2/class_PhoneBookListPane.cpp` emits this helper, but `PhoneBookDialog::OnCommand` still calls it through a polluted `ChattingColorListPane` cast. | IDA xrefs show only one direct caller: `PhoneBookDialog::OnCommand` at `0x0058cd8c`. The body copies `entry + 1` and `entry + 65` wide strings into caller buffers and returns the entry flag byte. |
| `0x0058dcb0-0x0058dcd3` | `WriteWideFormattedLine` / `PhoneBookFwprintf` | Wave3 does not model this helper. | IDA xrefs include `PhoneBookDialog::SavePhoneBook` at `0x0058ce94` and `0x0058cea6`, plus raw refs in the phone-list rendering neighborhood. The helper builds a varargs list and forwards to a CRT-like formatted wide write routine. |

## IDA MCP Evidence

Rechecked on 2026-05-31:

- `0x0058cfa0` is an IDA function `sub_58CFA0` with exclusive end `0x0058cfdc`; this matches the documented inclusive range `0x0058cfa0-0x0058cfdb`.
- `0x0058cfa0` has one direct code reference at `0x0058cd8c`. Its callees are `0x004f3dc0`, `_wcscpy_s`, and `_wcscpy_s`; decompilation copies two wide-string fields from the selected entry and returns the entry flag byte.
- `0x0058dcb0` is an IDA function `sub_58DCB0` with exclusive end `0x0058dcd3`; this aligns with the related memory page's `0x0058dcb0-0x0058dcd3` endpoint if that page is using exclusive-end notation. Confirm the exact inclusive/exclusive convention before any 95% score.
- `0x0058dcb0` has code references at `0x0058ce94`, `0x0058cea6`, `0x0058d0db`, and `0x0058d0ed`. It calls `0x0041b9a0` and `0x005d2208`, consistent with a local varargs formatted-write adapter.

## Layout Evidence

Phone-book list entries have a compact flag plus two wide-string fields:

```text
+0x000  flag/status byte exposed through the helper return value
+0x002  contact name, wchar_t[64]
+0x082  phone number, wchar_t[64]
```

`PhoneBookListPane::RenderEntry` reads the same `+0x02` and `+0x82` fields, truncates them with ellipses at approximately 60 and 120 pixels, and draws both columns.

## Ownership Decision

`0x0058cfa0` should not migrate as chat code. It is a phone-book list-model helper or file-local helper in `PhoneBookDialog.cpp`.

`0x0058dcb0` should remain a small helper under review. It may be a file-local wrapper around `fwprintf`/`vfwprintf` or a project CRT adapter, but its known local use is phone-book persistence.

## Cross-References

- [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- [UID:0000AD][PhoneBookDialog](by-class/PhoneBookDialog.md)
- [UID:0000AE][PhoneBookListPane](by-class/PhoneBookListPane.md)
- [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md)
- [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md)
- [wave3_data_issues](../wave3_data_issues.md)

## Changes

- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with moderate completion and strong confidence, while parent attachment and C++ remain blank.
- Summary and evidence: IDA MCP verification on 2026-05-31 confirmed the helper boundaries, direct callsites, callees, and decompiled behavior. The score remains below 95 because final source naming, the `0x0058dcb0` endpoint convention, and owner placement still need a full audit.
