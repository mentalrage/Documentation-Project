*** UID:0000QL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pCollectionDialogPane

## Status

- Address: `0x0069adf0` (`dword_69ADF0` in IDA)
- Symbol kind: process-wide singleton pointer
- Likely owner file: [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- Confidence: strong.

## Purpose

`g_pCollectionDialogPane` guards the active collection detail dialog. The `CollectionDialogPane` constructor stores `this`, the destructor clears it, and `CollectionPane`'s omitted open helper checks it before constructing a new dialog.

## Evidence

- IDA xrefs include `CollectionDialogPane::CollectionDialogPane` at `0x0048c686`/`0x0048c68d`, destructor cleanup at `0x0048e278`, and the collection open helper at `0x0056fd15`.
- IDA-confirmed helper `0x0048e140` only writes `0` to `dword_69ADF0`; this should be modeled as a singleton-clear helper or folded into dialog teardown.
- IDA MCP `xrefs_to 0x0069adf0` on 2026-05-25 also reports broader UI close/check references at `0x00508cc2` and `0x00514500`, plus a raw/in-function reference at `0x0048cf9f`.
- Other xrefs from `0x00508cc2` and `0x00514500` likely check/close the dialog from broader UI/session paths.

## Cross-References

- [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- [UID:00002V][CollectionDialogPane](by-class/CollectionDialogPane.md)
- [UID:00002X][CollectionPane](by-class/CollectionPane.md)
- [UID:00010X][0x0048c640-0x0048e305.CollectionDialogControls](by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md)
- [UID:00010Z][0x0048e140-0x0048e14b.ClearCollectionDialogPaneSingleton](by-memory/0x0048e140-0x0048e14b.ClearCollectionDialogPaneSingleton.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `84/86`. Summary/evidence: the page documents address, owner, singleton purpose, constructor/destructor/clear-helper evidence, broader close/check refs, and class/memory refs.
- 2026-06-05: Marked reconstructable under [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md). Evidence: live IDA MCP reports eight xrefs to `0x0069adf0`; decompilation confirms `0x0048e140` clears `dword_69ADF0`, `0x0048e250` clears it in the deleting destructor path, and `0x0056fc80` checks it before constructing a collection detail dialog.
