*** UID:0000SG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pTextFilter

## Status

- Symbol kind: global data / singleton pointer.
- Address: `0x0067adc8`.
- Type hypothesis: `TextFilter*`.
- Likely owner: [UID:0000OO][TextFilter](by-file/TextFilter.md).
- Exact memory context: [UID:0001JU][0x00595760-0x005958fe.TextFilterAndSanitizer](by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md).
- Confidence: strong for address and lifecycle, medium for final source folder.

## Purpose

`g_pTextFilter` stores the process-wide [UID:0000EQ][TextFilter](by-class/TextFilter.md) singleton. The object itself is tiny; most user-text cleanup is performed by the neighboring [UID:0000TK][SanitizeWideTextForChat](by-global/SanitizeWideTextForChat.md) helper.

## Evidence

- IDA MCP `xrefs_to 0x0067adc8` on 2026-05-26 shows constructor writes at `0x00595771` and `0x00595784`, clear writes at `0x005957a6` and `0x005958e0`, and reads from text-submission callers before they call `0x005957c0`.
- IDA MCP `py_eval` rechecked `0x0067adc8` on 2026-05-31 and confirmed IDA name `dword_67ADC8`, initial dword `0xffffffff`, and 19 data xrefs. The same recheck confirmed the constructor writes, destructor/clear writes, and broad submit-path reads listed below.
- `TextFilter::TextFilter` at `0x00595760-0x00595794` stores `this` into `0x0067adc8` and installs the [UID:0001YY][TextFilterVtable](by-type/by-vtable/TextFilterVtable.md).
- The non-deleting destructor-like body at `0x005957a0-0x005957b0` and scalar deleting destructor at `0x005958d0-0x005958fd` both clear the singleton.
- Current `simroot_v2/class_TextFilter.cpp` emits `TextFilter* g_pTextFilter`, but the generated global-data record remains below completion threshold and should be checked against this address before migration.

## Users

IDA data xrefs include article/mail/profile/party-search/spell/chat submit paths that read `g_pTextFilter` before sanitizing text:

- `0x00477590` / [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md)
- `0x0047dcb0` / [UID:000096][NewMailDialog](by-class/NewMailDialog.md)
- `0x0053fdc0` / [UID:0000AU][ProfileDialog](by-class/ProfileDialog.md)
- `0x0059e3d0` / [UID:0000A7][PartySearchEditPane](by-class/PartySearchEditPane.md)
- `0x005ae060` / [UID:0000DU][SpellStringInputPane](by-class/SpellStringInputPane.md)
- `0x005b1640`, `0x005b1a60`, `0x005b1f80`, and `0x005b2390` / target message input panes under [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- `0x005b3670` / [UID:0000C3][SayInputPane](by-class/SayInputPane.md)
- `0x005b4260` / [UID:0000D5][ShoutInputPane](by-class/ShoutInputPane.md)

## Cross-References

- [UID:0000OO][TextFilter](by-file/TextFilter.md)
- [UID:0000EQ][TextFilter](by-class/TextFilter.md)
- [UID:0000TK][SanitizeWideTextForChat](by-global/SanitizeWideTextForChat.md)
- [UID:0001YY][TextFilterVtable](by-type/by-vtable/TextFilterVtable.md)
- [UID:0001JU][0x00595760-0x005958fe.TextFilterAndSanitizer](by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md)
- [UID:0001JT][0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter](by-memory/0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md)

## Changes

- 2026-05-31: Updated reconstruction metadata and scores from live IDA evidence.
  - Before: completion/confidence were `0/0`, reconstructable state was blank, and no parent file UID was assigned.
  - After: `COMPLETION:76`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000OO` for [UID:0000OO][TextFilter](by-file/TextFilter.md). `RECONSTRUCTION_CPP CODE` remains blank because the page is below the 95+ final-source threshold.
  - Evidence: IDA MCP rechecked `0x0067adc8` as a 4-byte singleton pointer with 19 data xrefs, constructor writes in `0x00595760-0x00595794`, clear writes in `0x005957a0-0x005957b0` and `0x005958d0-0x005958fe`, and broad user-text submission reads.
