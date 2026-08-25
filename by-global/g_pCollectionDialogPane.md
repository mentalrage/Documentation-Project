*** UID:0000QL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted declaration for this global storage is covered by [UID:0002B8][0x0069adf0-0x0069adf4.g_pCollectionDialogPane](by-memory/0x0069adf0-0x0069adf4.g_pCollectionDialogPane.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pCollectionDialogPane

## Status

- Address: `0x0069adf0`; current B006 MCP evidence found no explicit IDA user global/name row for the slot, while older disassembly rendered auto operand labels such as `dword_69ADF0`/`unk_69ADF0`.
- Symbol kind: process-wide singleton pointer
- Likely owner file: [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- Exact storage carrier: [UID:0002B8][0x0069adf0-0x0069adf4.g_pCollectionDialogPane](by-memory/0x0069adf0-0x0069adf4.g_pCollectionDialogPane.md)
- Confidence: strong.

## Purpose

`g_pCollectionDialogPane` guards the active collection detail dialog. The `CollectionDialogPane` constructor stores `this`, the destructor clears it, and `CollectionPane`'s omitted open helper checks it before constructing a new dialog.

## Evidence

- IDA xrefs include `CollectionDialogPane::CollectionDialogPane` at `0x0048c686`/`0x0048c68d`, destructor cleanup at `0x0048e278`, and the collection open helper at `0x0056fd15`.
- IDA-confirmed helper `0x0048e140` only writes `0` to `dword_69ADF0`; this should be modeled as a singleton-clear helper or folded into dialog teardown.
- IDA MCP `xrefs_to 0x0069adf0` on 2026-05-25 also reports broader UI close/check references at `0x00508cc2` and `0x00514500`, plus a raw/in-function reference at `0x0048cf9f`.
- Other xrefs from `0x00508cc2` and `0x00514500` likely check/close the dialog from broader UI/session paths.
- 2026-06-14 A003 live IDA MCP `xrefs_to 0x0069adf0` reconfirmed exactly eight refs: constructor publish/fallback clear at `0x0048c686`/`0x0048c68d`, raw/in-function reference at `0x0048cf9f`, clear helper at `0x0048e140`, scalar deleting destructor clear at `0x0048e278`, broader UI close/check refs at `0x00508cc2` and `0x00514500`, and CollectionPane open-helper duplicate guard at `0x0056fd15`.
- 2026-06-14 `lookup_funcs` confirms the constructor cluster `sub_48C640` is `0x935` / `2357` bytes, clear helper `sub_48E140` is `0xb` / `11` bytes, scalar deleting destructor `sub_48E250` is `0x5f` / `95` bytes, and open helper `sub_56FC80` is `0xe1` / `225` bytes (Verified with int_convert.py).
- 2026-06-14 decompilation confirms `sub_48E140` is only `unk_69ADF0 = 0`, `sub_48E250` restores `CollectionDialogPane` vtable views before clearing the singleton and optionally deleting `this`, and `sub_56FC80` checks `unk_69ADF0` before allocating `0x270` / `624` bytes for a new collection dialog.
- 2026-07-04 B006 MCP session `ddf5b602` reconfirmed current storage/source-output facts for the exact by-memory carrier [UID:0002B8][0x0069adf0-0x0069adf4.g_pCollectionDialogPane](by-memory/0x0069adf0-0x0069adf4.g_pCollectionDialogPane.md): `0x0069adf0` is not a function; `get_bytes 0x0069adf0 size 0x20` and `get_global_value 0x0069adf0` show zero-filled storage/value; `entity_query` finds no explicit IDA user global/name row in `0x0069adf0-0x0069ae10`; `xref_query` reports the same exact eight refs at `0x0048c686`, `0x0048c68d`, `0x0048cf9f`, `0x0048e140`, `0x0048e278`, `0x00508cc2`, `0x00514500`, and `0x0056fd15`; `find_bytes F0 AD 69 00` reports only the eight xref-operand matches and no extra pointer-table route.

## Autogen And Score Rationale

- Owner/emitter route remains [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md), which surfaces to `auto-generated/NexusTK/ui/dialogs/CollectionDialogPane.cpp` without a dead end.
- Source output for the storage definition is carried by exact by-memory page [UID:0002B8][0x0069adf0-0x0069adf4.g_pCollectionDialogPane](by-memory/0x0069adf0-0x0069adf4.g_pCollectionDialogPane.md). This by-global page is an alias/support page and emits only a marker comment so the reconstructed source does not duplicate `CollectionDialogPane *g_pCollectionDialogPane;`.
- Completion is raised to `86` because the page now records exact singleton address, all eight refs, constructor/destructor/clear-helper/open-helper boundaries, duplicate-open behavior, broader UI close/check references, and route support.
- Confidence is raised to `90` because current IDA xrefs and decompilation match the singleton lifecycle and source owner. It remains below final audit because the raw `0x0048cf9f` reference and exact broader close/check source names are still not source-quality.

## Cross-References

- [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- [UID:00002V][CollectionDialogPane](by-class/CollectionDialogPane.md)
- [UID:00002X][CollectionPane](by-class/CollectionPane.md)
- [UID:00010X][0x0048c640-0x0048e305.CollectionDialogControls](by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md)
- [UID:00010Z][0x0048e140-0x0048e14b.ClearCollectionDialogPaneSingleton](by-memory/0x0048e140-0x0048e14b.ClearCollectionDialogPaneSingleton.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `84/86`. Summary/evidence: the page documents address, owner, singleton purpose, constructor/destructor/clear-helper evidence, broader close/check refs, and class/memory refs.
- 2026-06-05: Marked reconstructable under [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md). Evidence: live IDA MCP reports eight xrefs to `0x0069adf0`; decompilation confirms `0x0048e140` clears `dword_69ADF0`, `0x0048e250` clears it in the deleting destructor path, and `0x0056fc80` checks it before constructing a collection detail dialog.
- 2026-06-14 A003 goal2 score pass: raised `84/86` to `86/90`.
  - Evidence: live IDA MCP reconfirmed the eight-ref singleton map, clear-helper/deleting-destructor/open-helper decompilation, constructor/open-helper sizes, duplicate guard, and non-dead-ended CollectionDialogPane owner/emitter route.
  - Historical code-entry decision: no reconstruction C++ was added at that time because final declaration/source split and broader close/check names were below source-quality evidence.
- 2026-07-04 B006 implementation callback:
  - Summary/evidence: the exact storage definition now belongs to [UID:0002B8][0x0069adf0-0x0069adf4.g_pCollectionDialogPane](by-memory/0x0069adf0-0x0069adf4.g_pCollectionDialogPane.md), which emits `CollectionDialogPane *g_pCollectionDialogPane;` through [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md). This by-global page now emits only a covered-by marker to avoid duplicate source output while retaining the global alias/lifecycle evidence.
