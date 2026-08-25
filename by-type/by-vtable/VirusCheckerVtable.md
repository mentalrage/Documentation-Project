*** UID:0003JF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000FW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000FW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-emitted one-slot VirusChecker vtable/RTTI layout.
// Source reconstruction is covered by [UID:0000FW][VirusChecker](by-class/VirusChecker.md); no raw vtable array or scalar-deleting-destructor source method is emitted here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# VirusChecker Vtable

## Summary

- Entity kind: source-local vtable layout.
- Owner class: [UID:0000FW][VirusChecker](by-class/VirusChecker.md)
- Source file context: [UID:0000P5][VirusChecker](by-file/VirusChecker.md)
- Backing data: [UID:0002OT][0x006310dc-0x006310e4.VirusCheckerVtableData](by-memory/0x006310dc-0x006310e4.VirusCheckerVtableData.md)
- Object vptr: `0x006310e0`
- Rebuild handling: `source-declared/generated-binary`

This page owns the source-level `VirusChecker` vtable layout that was previously documented only inside the mixed [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md) inventory. The table is intentionally compact: the next dword after the one function slot begins the `V3PRO32E.DLL` string data, not another virtual slot.

B004's 2026-06-20 source-quality pass correctly kept this as compiler-emitted backing data for a normal source declaration containing `virtual ~VirusChecker()`. B005's current RTTI pass closes the missing inheritance detail: the declaration is `VirusChecker : public Singleton<VirusChecker>`. The class page emits that human source; this vtable page carries only the formal covered-by marker and must not emit vtable bytes or a named scalar-deleting-destructor method.

## Layout

| Slot | Target | Interpretation |
| --- | --- | --- |
| `+0x00` | `0x005c0ec0` | scalar deleting destructor |

The vftable address is `0x006310e0`; its compiler-owned Complete Object Locator pointer is at `vftable[-1]`, address `0x006310dc`. The sole slot and the COL pointer make the full physical record exactly eight bytes.

### RTTI Hierarchy

| Item | Address / value | Meaning |
| --- | --- | --- |
| Complete Object Locator | `0x00653f08` | `{0,0,0,0x0067a4c0,0x00653f1c}` for complete `VirusChecker` object |
| Type descriptor | `0x0067a4c0` | `.?AVVirusChecker@@` |
| Class hierarchy | `0x00653f1c` | two descriptors: self and `Singleton<VirusChecker>` |
| Singleton base descriptor | `0x00653f54` | PMD `{4,-1,0}`, attributes `0x40`; visible, non-virtual direct base |
| Singleton type descriptor | `0x0067a4dc` | `.?AV?$Singleton@VVirusChecker@@@@` |

The PMD and constructor adjustment prove direct public `Singleton<VirusChecker>` inheritance with empty-base optimization at object offset `+0x04`. They do not describe a source-level Singleton pointer/member.

## Evidence

- `0x006310dc` is the RTTI-adjacent complete-object-locator word for `VirusChecker`.
- `0x006310e0` is named `??_7VirusChecker@@6B@` and is stored by the constructor, destructor, and scalar deleting destructor at `0x005c04a7`, `0x005c050c`, and `0x005c0eed`.
- `0x006310e4` is named `LibFileName` and begins the `V3PRO32E.DLL` string data, so the vtable has only one function slot.
- A004 Batch 341 live IDA MCP rechecked `entity_query`, `trace_data_flow`, `lookup_funcs`, and `make_signature_for_range`; the unique raw table signature is `08 3F 65 00 C0 0E 5C 00`.
- B004 dated MCP session `86fb854e` rechecked the same compact record with `get_bytes 0x006310dc size 8` -> `08 3f 65 00 c0 0e 5c 00`, `entity_query` for `??_7VirusChecker@@6B@` at `0x006310e0`, and xrefs from the constructor/destructor/scalar deleting destructor vptr stores.
- B005 dated MCP session `7be8cc9f` supersedes earlier sessions for the dated UID0002OT/UID0003JF proof snapshot. It decoded the COL, CHD, both BCD entries, type strings, direct-base PMD/flags, constructor `this+4/-4` adjustment, scalar-wrapper 12-byte free, and exact predecessor/successor boundaries.
- Pointer scans found the vtable address only in the three expected vptr stores, the COL pointer only at `0x006310dc`, and the scalar-wrapper pointer only at `0x006310e0`. No second slot or source-authored raw table route exists.

This vtable page does not own module-path normalization. The class methods represented by the table ultimately consume UID0001NW, whose lower-case copy uses the shared header-visible inline `StringBase<char>::ToLower() const` specialization from `StringBase.h` or an included `.inl`; no specialization is emitted by this vtable record or placed in `VirusChecker.cpp`/`StringBase.cpp` because of it.

All named MCP sessions in this page are dated evidence snapshots, not permanent current authority. Future IDA-dependent decisions require a fresh supervisor `idb_list`, health/canonical-disk identity, and target-prestate readback.

## Assignment Decision

`CANONICAL_OWNER` and `EMITTER_UIDS` point to [UID:0000FW][VirusChecker](by-class/VirusChecker.md). The vtable page is `91/95` after the current hierarchy/source-shape pass. The direct class and file parents remain the source route; the by-type page does not become a raw source-table owner.

## Cross-References

- [UID:0000FW][VirusChecker](by-class/VirusChecker.md)
- [UID:0000P5][VirusChecker](by-file/VirusChecker.md)
- [UID:0002OT][0x006310dc-0x006310e4.VirusCheckerVtableData](by-memory/0x006310dc-0x006310e4.VirusCheckerVtableData.md)
- [UID:0001NU][0x005c0460-0x005c0fe1.VirusChecker](by-memory/0x005c0460-0x005c0fe1.VirusChecker.md)
- [UID:0001WG][VirusCheckerProcessTreeLayout](by-type/by-struct/VirusCheckerProcessTreeLayout.md)
- [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md)

## Changes

- 2026-08-06 B003 UID0001NW placement callback: recorded the shared header-visible ToLower dependency without changing vtable ownership/layout, and historicalized named MCP session authority while retaining all dated RTTI/vptr evidence.
- 2026-06-12 A004 Batch 341: Created exact source-local vtable page from the mixed security singleton vtable inventory. Evidence: live IDA MCP reconfirmed the decorated vtable base, constructor/destructor/scalar-destructor vptr stores, slot target function bound, `LibFileName` successor boundary, and unique raw table signature.
- 2026-06-20 B004 Rule 26 support sync: recorded that first-draft source is the class declaration with `virtual ~VirusChecker()`, while the one-slot vtable and scalar deleting destructor wrapper remain compiler-generated artifacts.
- 2026-07-23 B005 UID0002OT accepted support implementation:
  - Raised completion/confidence from `88/93` to `91/95`; preserved owner/emitter [UID:0000FW][VirusChecker](by-class/VirusChecker.md) and reconstructable state.
  - Added the formal no-raw-table marker and dated MCP proof for the exact COL/CHD/BCD chain, direct visible non-virtual `Singleton<VirusChecker>` base at PMD `+0x04`, EBO overlap, one scalar-deleting slot, three vptr stores, and exact successor boundary.
