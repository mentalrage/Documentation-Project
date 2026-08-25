*** UID:0003I1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000E6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000E6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// StdioFile vtable is compiler-generated from the StdioFile class declaration and virtual method definitions.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# StdioFile Vtable

## Status

- Current role: source-local by-vtable page for the concrete CRT-backed `StdioFile` stream implementation.
- Direct owner: [UID:0000E6][StdioFile](by-class/StdioFile.md).
- Source context: [UID:0000O9][StdioFile](by-file/StdioFile.md), with broader utility context [UID:0000JD][FileIO](by-file/FileIO.md).
- Backing data: [UID:00026L][0x0062d5a8-0x0062d5f8.StdioFileStringIterReadOnlyData](by-memory/0x0062d5a8-0x0062d5f8.StdioFileStringIterReadOnlyData.md) contains this vtable plus adjacent non-StdioFile string-utility data.
- Split source: [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md) mixed aggregate.

## Layout

The exact `StdioFile` vtable record is `0x0062d5a8-0x0062d5d8`: `0x30` bytes / decimal 48 bytes, with an RTTI locator dword at `0x0062d5a8` followed by `0x2c` bytes / decimal 44 bytes of slots at `0x0062d5ac-0x0062d5d8` (Verified with int_convert.py). The current by-memory backing page starts at the slot table, so this by-type page records the source-local vtable record while linking to that mixed memory index.

| Slot | Address | Value | Role |
| --- | --- | --- | --- |
| locator | `0x0062d5a8` | `0x006509d4` | `StdioFile` RTTI complete-object-locator pointer. |
| `+0x00` | `0x0062d5ac` | `0x005824a0` | scalar deleting destructor. |
| `+0x04` | `0x0062d5b0` | `0x004f4b10` | inherited `LObject`-style runtime slot. |
| `+0x08` | `0x0062d5b4` | `0x0041b6c0` | inherited no-op virtual / `nullsub_18`. |
| `+0x0c` | `0x0062d5b8` | `0x005820d0` | `Open` via `_wstat`/`_wfopen`. |
| `+0x10` | `0x0062d5bc` | `0x005821d0` | `Close`. |
| `+0x14` | `0x0062d5c0` | `0x00582200` | `GetPosition`; `Tell` is historical vocabulary. |
| `+0x18` | `0x0062d5c4` | `0x00582210` | seek. |
| `+0x1c` | `0x0062d5c8` | `0x004f5ad0` | cached size query. |
| `+0x20` | `0x0062d5cc` | `0x00582230` | `size_t Read(void *buffer, int count)`; source count is signed. |
| `+0x24` | `0x0062d5d0` | `0x005822d0` | string/line read. |
| `+0x28` | `0x0062d5d4` | `0x00582250` | raw line read into caller buffer. |

## 2026-06-12 A004 IDA Recheck

Live IDA MCP session `b001_nexustk` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` reconfirmed this page's direct class ownership and split boundary:

- `entity_query` over `0x0062d5a8-0x0062d5f8` reports `??_7StdioFile@@6B@` at `0x0062d5ac` and `??_7StringIter@@6B@` at `0x0062d5ec`.
- `lookup_funcs` reports concrete slot target sizes: destructor `0x005824a0` size `0x56`, open `0x005820d0` size `0xf9`, close `0x005821d0` size `0x27`, tell `0x00582200` size `0x0c`, seek `0x00582210` size `0x1d`, size `0x004f5ad0` size `0x04`, read `0x00582230` size `0x1a`, string-line read `0x005822d0` size `0xa9`, and raw-line read `0x00582250` size `0x71`.
- `trace_data_flow backward 0x0062d5ac` reports the vftable dword and constructor/destructor/deleting-destructor vptr refs at `0x0058207f`, `0x005820a6`, and `0x005824a9`.
- `trace_data_flow backward 0x0062d5d8` reports the successor `UTF-16LE` whitespace literal at `0x0062d5d8` and pointer `0x0067027c`, proving the vtable ends before the string-utility literal/sentinel/StringIter data.
- `make_signature_for_range 0x0062d5a8-0x0062d5d8` produced a unique 48-byte signature:
  `D4 09 65 00 A0 24 58 00 10 4B 4F 00 C0 B6 41 00 D0 20 58 00 D0 21 58 00 00 22 58 00 10 22 58 00 D0 5A 4F 00 30 22 58 00 D0 22 58 00 50 22 58 00`.

2026-06-29 B006 UID0001IQ implementation refresh keeps the same vtable ownership and records the constructor-specific source implication. Current MCP session `3fa0535f` reconfirmed `xrefs_to 0x0062d5ac` as exactly three vptr references with `more:false`: constructor install at `0x0058207f`, non-deleting destructor restore at `0x005820a6`, and scalar-deleting destructor restore at `0x005824a9`. The constructor's formal C++ must not manually assign the vtable; `StdioFile::StdioFile()` plus the class declaration/virtual method set cause the compiler-generated vptr store.

## Assignment Decision

`AUTOGEN_PARENT_UID` is [UID:0000E6][StdioFile](by-class/StdioFile.md). This child score remains unchanged, the direct class parent is now `91/92`, and the existing StdioFile source root remains the emitter.

This page should not attach directly to [UID:0000O9][StdioFile](by-file/StdioFile.md) or [UID:0000JD][FileIO](by-file/FileIO.md). The direct owner is the `StdioFile` class; the source-file pages are context for where the class declaration and methods should be emitted.

## Reconstruction Notes

The rebuilt project should emit this vtable from the concrete `StdioFile` class declaration and virtual method implementations. Do not hand-port the dwords as a static source table. The adjacent `0x0062d5d8` whitespace literal, `0xffffffff` sentinel, and `StringIter` vtable are separate string-utility ownership questions and are not part of this by-type child.

UID0001IQ now emits the direct constructor body through [UID:0000E6][StdioFile](by-class/StdioFile.md), but the vtable data remains source-declared/generated-binary. Do not add manual vtable assignment to the constructor C++ and do not move this vtable page to `FileIO`, `PathUtil`, caller modules, or the mixed [UID:00026L][0x0062d5a8-0x0062d5f8.StdioFileStringIterReadOnlyData](by-memory/0x0062d5a8-0x0062d5f8.StdioFileStringIterReadOnlyData.md) memory page.

2026-07-01 B010 UID0000O9 implementation adds a formal compiler-generated-vtable marker only. The source class declaration and virtual method definitions on the StdioFile child pages are expected to regenerate the vtable; this page remains evidence for slot order, vptr install/restore refs, and the mixed-data boundary.

## UID0002UV Source-Quality Callback

- Scores, owner/emitter, exact table bounds, backing-data boundary, xrefs, and the existing compiler-generated-vtable marker remain unchanged.
- Slot `+0x14` is source-facing `GetPosition`; `Tell` is retained only as historical terminology.
- Slot `+0x20` returns `size_t` and takes signed `int count`. DATFile's same-slot negative-count branch proves the common parameter type; StdioFile's `fread` use does not change the virtual declaration.
- StdioFile remains a 12-byte concrete class over a four-byte data-member-free File base, with fields at `+0x04/+0x08`.
- No vtable dwords, vptr stores/restores, RTTI, or ABI mechanics are added to human source.

## Cross-References

- [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md)
- [UID:0000E6][StdioFile](by-class/StdioFile.md)
- [UID:0000O9][StdioFile](by-file/StdioFile.md)
- [UID:0000JD][FileIO](by-file/FileIO.md)
- [UID:00026L][0x0062d5a8-0x0062d5f8.StdioFileStringIterReadOnlyData](by-memory/0x0062d5a8-0x0062d5f8.StdioFileStringIterReadOnlyData.md)
- [UID:0001IR][0x00582070-0x005824f6.StdioFile](by-memory/0x00582070-0x005824f6.StdioFile.md)
- [UID:0003H2][StdioFileLayout](by-type/by-struct/StdioFileLayout.md)

## Changes

- 2026-07-01 B010 UID0000O9 empty-emitter family implementation:
  - Before: `87/92`, formal C++ blank.
  - After: `88/93`; inserted formal no-manual-vtable marker.
  - Summary/evidence: preserves direct class ownership, slot/xref proof, and the rejection of manual dword/static-table source or FileIO/PathUtil ownership. The vtable is emitted by the compiler from the class declaration and virtual method bodies.
- 2026-06-29 B006 UID0001IQ constructor implementation:
  - Score unchanged.
  - Summary/evidence: recorded that UID0001IQ source-ready constructor C++ relies on compiler-generated StdioFile vptr install rather than manual assignment. Current MCP session `3fa0535f` reconfirmed the three `0x0062d5ac` vptr refs at `0x0058207f`, `0x005820a6`, and `0x005824a9`, preserving direct class ownership and rejecting manual vtable/static-table source.
- 2026-06-12 A004 Batch 319:
  - Created this exact source-local child from the former mixed [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md) aggregate.
  - Summary/evidence: live IDA MCP reconfirmed the decorated vtable name, concrete slot targets and sizes, vptr install/restore refs, successor whitespace/StringIter boundary, unique range signature, and direct class parent gate.
