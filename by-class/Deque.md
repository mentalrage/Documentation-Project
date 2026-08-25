*** UID:00003P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Deque

## Summary

`Deque` is a non-emitting documentation grouping for MSVC/Dinkumware `std::deque` template/support bodies over 4-byte element specializations. It is not a recovered NexusTK class declaration.

The full-family audit resolves the common layout as a proxy-like first field, block map, power-of-two map size, front logical offset, and element count. UID000149 is `std::deque<int>::push_back(const int&)`; UID0000XB is internal `_Growmap`; UID0000XA/UID0001FD are cleanup support; UID0001FC is integer element-address support; UID0001IE is `std::deque<OwnedAnsiString>` destruction support.

Concrete source lives in EventDispatcher, FolderTreePane, PrimeNumberGenerator, WorldMap, and SoundManager callers as typed `std::deque` declarations/operations. `RECONSTRUCTABLE:FALSE`, blank emitter, and blank C++ prevent a false custom class or `Deque.cpp` output while preserving this page as binary evidence.

## Likely Original Placement

- Documentation grouping: [UID:0000IR][Deque](by-file/Deque.md), now reviewed with projected path `NONE`.
- Original source placement: toolchain `<deque>` header instantiations in concrete consumer translation units.
- Rejected placement: `NexusTK/util/Deque.cpp`; the historical scaffold is not original-TU evidence.

## Layout

See [UID:0001U2][DequeLayout](by-type/by-struct/DequeLayout.md).

```text
+0x00  void* proxyLikeStorageOrAllocatorSlot
+0x04  uint32_t** blockMap
+0x08  uint32_t blockCount
+0x0c  uint32_t frontIndex
+0x10  uint32_t count
```

## Methods

| Address | Name | Role |
| --- | --- | --- |
| `0x00439e00-0x00439ea3` | historical scaffold `Destroy` | Non-emitting MSVC/Dinkumware `std::deque` 4-byte cleanup / `_Tidy`-style support body. B003 session `19917133` proves the exact `0xa3` range, padding boundaries, thirteen xrefs to the start, no xrefs to the exclusive end, heap-free/invalid-parameter callees, and thunk `0x00439f50`; do not add custom `Deque::Destroy` C++ for this range. |
| `0x0043e0b0-0x0043e241` | historical scaffold `EnsureCapacity` / `_Growmap` | Non-emitting MSVC/Dinkumware `std::deque` 4-byte block-map growth support body. B004 session/database `19917133` proves the exact `0x191` range, padding boundaries, no xrefs to the exclusive end, sixteen direct start xrefs, `deque<T> too long` overflow route, standard allocator/copy/zero/free behavior, and comparator `std::deque` reserve helper evidence; do not add custom `Deque::EnsureCapacity` C++ for this range. |
| `0x004a88e0-0x004a8966` | historical scaffold `PushBack` | Non-emitting `std::deque<int>::push_back(const int&)` support. Eight source expressions in seven functions call the folded body; later appends are inlined in those callers. Source return is `void`; no custom body or emitter. |
| `0x0054c0c0-0x0054c110` | historical scaffold `ElementAddress` / `GetAtAddress` | Non-emitting MSVC/Dinkumware `std::deque` 4-byte element-address helper / `_Subscript`-style support body. B013 session `eb7ce28b` proves the exact body, one raw caller at `0x0054bce1`, no callees, and constructor proxy setup at `0x0054bcf0`; do not add custom `Deque::ElementAddress` C++ for this range. |
| `0x0054c160-0x0054c1f1` | historical scaffold `Clear` | Non-emitting Prime `std::deque<int>` cleanup support; no custom project method. |
| `0x0057b9e0-0x0057baa3` | historical scaffold `DestroyOwnedEntries` | Non-emitting `std::deque<OwnedAnsiString>` destruction support caused by SoundManager source scope/member destruction; the stale custom body is removed. |

## Evidence

- IDA MCP decompilation on 2026-05-31 confirms the layout used by `Destroy`, `EnsureCapacity`, `PushBack`, `Clear`, and `DestroyOwnedEntries`: `+0x04` block map, `+0x08` block count, `+0x0c` front index, and `+0x10` count.
- IDA MCP also shows `Destroy` and `DestroyOwnedEntries` freeing `*(void**)this` after block-map cleanup, while `Clear` leaves that slot untouched; the `+0x00` field is therefore an auxiliary owned pointer/storage slot, not the block map.
- Historical generated `class_Deque.cpp` and Wave2/Wave3 metadata were leads only and are superseded by current IDA/caller evidence; they are not source ownership evidence.
- IDA MCP confirms the documented helper boundaries; all six exact pages are compiler/STL support rather than custom emitters.
- Caller fan-in crosses unrelated subsystems and multiple 4-byte element semantics, supporting template instantiation/folding rather than utility-file ownership.
- IDA MCP confirms `0x0054c0c0` as an additional 0x50-byte helper; its raw known caller is `PrimeNumberGenerator::GetPrimeAt` at `0x0054bcc0`.
- B013 2026-07-04 MCP session `eb7ce28b` reclassified the `0x0054c0c0` helper as non-emitting standard deque support for this exact target: `lookup_funcs` reports `sub_54C0C0` size `0x50`, `xrefs_to` reports only the raw code xref at `0x0054bce1`, `callees` is empty, byte/disassembly/decompile checks confirm the four-entry block formula, and the constructor at `0x0054bcf0` allocates an 8-byte proxy into the deque `+0x00` slot and stores the deque pointer back through it. Historical `ElementAddress` / `GetAtAddress` names are descriptive scaffolds only.
- B003 2026-07-05 MCP session/database `19917133` reclassified [UID:0000XA][0x00439e00-0x00439ea3.DequeDestroy](by-memory/0x00439e00-0x00439ea3.DequeDestroy.md) as non-emitting standard deque cleanup support: `lookup_funcs` reports `sub_439E00` size `0xa3`, bytes show seven `0xcc` prebytes and thirteen postbytes before `0x00439eb0`, `xrefs_to`/`xref_query` report thirteen code xrefs to the start and zero xrefs to the exclusive end, `callees` reports only `sub_5C7526` and `__invalid_parameter_noinfo_noreturn`, and `analyze_function` identifies `0x00439f50` as a five-byte jump thunk to this body. The helper drains `+0x10`, resets `+0x0c`, frees blocks through `+0x04/+0x08`, applies the large-allocation guard to the map, and frees the proxy-like `+0x00` slot.
- B004 2026-07-05 MCP session/database `19917133` reclassified [UID:0000XB][0x0043e0b0-0x0043e241.DequeEnsureCapacity](by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md) as non-emitting standard deque map-growth support: `lookup_funcs` reports `sub_43E0B0` size `0x191`, byte checks confirm thirteen prebytes and fifteen postbytes of `0xcc` padding, `xrefs_to` reports sixteen code xrefs to the start and zero xrefs to the exclusive end, `callees` reports `operator new`, `_memmove_0`, `_memset`, `sub_5C7526`, `sub_43F190`, and `__invalid_parameter_noinfo_noreturn`, and string/xref checks tie `sub_43F190` to the literal `deque<T> too long` at `0x0060f0a8`. The helper doubles the map to satisfy requested extra slots and a minimum of eight slots, preserves wrapped map slices, zero-fills gaps, and updates `+0x04/+0x08`.
- 2026-05-26 recheck: active `class_Deque.cpp` still omits `0x0054c0c0`, and IDA still sees the helper only through the raw `0x0054bce1` code reference.
- 2026-06-07 Batch 083 live IDA MCP `py_eval` reconfirmed the exact helper set and broad utility fan-in: `Destroy` `0x00439e00-0x00439ea3` with 11 entry callers, `EnsureCapacity` `0x0043e0b0-0x0043e241` with 13 entry callers, `PushBack` `0x004a88e0-0x004a8966` with 7 entry callers, `ElementAddress` `0x0054c0c0-0x0054c110` with the raw `0x0054bce1` caller, `Clear` `0x0054c160-0x0054c1f1` with 4 entry callers, and `DestroyOwnedEntries` `0x0057b9e0-0x0057baa3` with 2 entry callers. The caller spread still crosses event, folder-tree, map/world-map, prime-table, and sound-manager code, supporting shared utility placement.
- 2026-06-16 A001 live IDA MCP reconfirmed the same six modeled helper starts and sizes, the single internal component edge `DequePushBack -> DequeEnsureCapacity`, and broad external fan-in through event/folder-tree/map/world-map/prime/sound callers. A section-mapped PE scan found the expected direct branch to the raw element helper at `0x0054bce1` and no VA/RVA pointer encodings for `0x0054c0c0`.
- Historical 2026-06-26 B002 work proved UID0001IE's SoundManager caller, separate thunk, ANSI `StringBase` entry type, and exact destruction mechanics. The former `Deque::DestroyOwnedEntries()` source-body conclusion is superseded: those same facts identify a `std::deque<OwnedAnsiString>` destructor instantiation.

## Assignment Decision

`CANONICAL_OWNER:0000IR` now links only to a reviewed documentation file with projected path `NONE`. This page is `RECONSTRUCTABLE:FALSE`, has no emitter, and keeps both managed C++ values blank. It does not define `Deque<T>`, fields, methods, `EnsureCapacity`, or `[[CHILDREN]]`.

Each exact helper page remains grouped here for review continuity, but source coverage is caller-owned: native `std::deque<int>` in EventDispatcher/FolderTree/Prime/WorldMap and `std::deque<OwnedAnsiString>` destruction in SoundManager. The compiler/STL supplies push, growth, access, clear, and destruction lowering.

## Score Rationale

- Completion `91`: layout, all six exact helpers, two concrete element semantics, caller expressions, inlining/folding, `_Growmap`, no-code states, and rejected custom file/class/body are coordinated.
- Confidence `95`: current IDA, caller bodies, Dinkumware error/runtime patterns, and independently accepted helper audits converge. Exact header version does not affect the grouping disposition.

## Open Questions

- Exact Dinkumware header/compiler revision remains unknown, but source category and no-emitter handling are resolved.
- Additional inlined standard deque operations may exist; they do not justify a custom class/file and are outside this exact helper inventory.

## Cross-References

- File: [UID:0000IR][Deque](by-file/Deque.md)
- Layout: [UID:0001U2][DequeLayout](by-type/by-struct/DequeLayout.md)
- Memory: [UID:0000XA][0x00439e00-0x00439ea3.DequeDestroy](by-memory/0x00439e00-0x00439ea3.DequeDestroy.md), [UID:0000XB][0x0043e0b0-0x0043e241.DequeEnsureCapacity](by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md), [UID:000149][0x004a88e0-0x004a8966.DequePushBack](by-memory/0x004a88e0-0x004a8966.DequePushBack.md), [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md), [UID:0001FD][0x0054c160-0x0054c1f1.DequeClear](by-memory/0x0054c160-0x0054c1f1.DequeClear.md), [UID:0001IE][0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries](by-memory/0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries.md)
- Related: [UID:000079][List](by-class/List.md), [UID:0000C1][RingBuffer](by-class/RingBuffer.md), [UID:0001QA][client_containers](by-meta/client_containers.md)

## Changes

- 2026-07-12 B003 UID000149 full-family implementation:
  - Changed `88/90` to `91/95`, `RECONSTRUCTABLE:TRUE` to `FALSE`, cleared `EMITTER_UIDS`, and preserved blank formal C++.
  - Reclassified the page as a non-emitting standard-library evidence grouping, corrected UID000149/UID0001FD/UID0001IE rows, retired `NexusTK/util/Deque.cpp` ownership, and preserved exact layout/helper evidence without emitting a class.

- 2026-07-05 B004 UID0000XB implementation sync:
  - Added the source-category caveat that UID0000XB is MSVC/Dinkumware `std::deque` map-growth / `_Growmap`-style support, not a NexusTK-authored `Deque::EnsureCapacity` method.
  - Updated the method row to non-emitting generated support and preserved the broader helper inventory for a future Deque-family audit.
  - Evidence: accepted report `tools/leaser/Agents/Agent-B004/research/0000XB-DequeEnsureCapacity-source-quality.md`, MCP session/database `19917133`, exact `0x0043e0b0-0x0043e241` range/bytes/xref/no-exclusive-end-xref/callee checks, `deque<T> too long` route through `0x0060f0a8`/`sub_43F190`, and comparator standard-deque reserve helper evidence.
- 2026-07-05 B003 UID0000XA implementation sync:
  - Added the source-category caveat that UID0000XA is MSVC/Dinkumware `std::deque` cleanup / `_Tidy`-style support, not a NexusTK-authored `Deque::Destroy` method.
  - Updated the method row to non-emitting generated support and preserved the broader helper inventory for a future Deque-family audit.
  - Evidence: accepted report `tools/leaser/Agents/Agent-B003/research/0000XA-DequeDestroy-source-quality.md`, MCP session/database `19917133`, exact `0x00439e00-0x00439ea3` range/bytes/xref/no-exclusive-end-xref/callee checks, thunk `0x00439f50`, and same-layout UID0001FC standard-deque support precedent.
- 2026-06-26 B002 implementation sync:
  - Changed score from `87/89` to `88/90`.
  - Updated the [UID:0001IE][0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries](by-memory/0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries.md) method row and source-quality notes to reflect target-local first-draft C++ and the live ANSI `StringBase` entry type.
  - Class-level formal C++ remains blank pending a full Deque declaration/API audit; only the exact child method emits.
- 2026-07-04 B013 UID0001FC implementation sync:
  - Added the source-category caveat that UID0001FC is MSVC/Dinkumware `std::deque` generated support, not a NexusTK-authored `Deque::ElementAddress` method.
  - Updated the method row to non-emitting generated support and preserved the broader helper inventory for a future Deque-family audit.
  - Evidence: accepted report `tools/leaser/Agents/Agent-B013/research/0001FC-DequeElementAddressHelper-source-quality.md`, MCP session `eb7ce28b`, exact `0x0054c0c0-0x0054c110` range/bytes/xref/no-callee checks, and `0x0054bcf0` constructor proxy setup.
- 2026-06-16 A001 Goal 2 file/class completion pass:
  - Before: `COMPLETION:86`, `CONFIDENCE:88`, with stale legacy parent/gate wording.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:89`; updated owner/emitter wording to the current `CANONICAL_OWNER`/`EMITTER_UIDS` fields and replaced the stale `95/95` code gate note with the active source-quality blocker.
  - Evidence: live IDA `lookup_funcs`, `xrefs_to`, `callees`, `analyze_component`, and a section-mapped PE scan reconfirmed all six Deque helper ranges, the raw PrimeNumberGenerator element-address branch, broad non-feature caller spread, and direct utility-file parent [UID:0000IR][Deque](by-file/Deque.md) at `86/88`.
- 2026-05-27: Existing `Destroy` method range used `0x00439e00-0x00439ea2`. Changed it to `0x00439e00-0x00439ea3`. Evidence: read-only IDA MCP reports `sub_439E00` as `0x00439e00-0x00439ea3`, size `0xa3`; the corresponding by-memory page [UID:0000XA][0x00439e00-0x00439ea3.DequeDestroy](by-memory/0x00439e00-0x00439ea3.DequeDestroy.md) records the boundary correction.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `80/82`.
  - Summary/evidence: layout, reusable-utility placement, core methods, omitted element-address helper, caller fan-in, related containers, and endpoint correction are documented; remaining work is exact original class/template naming and possible additional inlined helpers.
- 2026-05-31 layout and reconstructability correction:
  - Before: the class page mirrored a stale four-field layout beginning with `blockMap` at `+0x00`, and `RECONSTRUCTABLE` was blank.
  - After: the layout now records `+0x00` as an auxiliary owned pointer/storage slot, shifts block map/count/front/count to `+0x04/+0x08/+0x0c/+0x10`, raises confidence to `86`, and marks `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: 2026-05-31 IDA MCP decompilation of `0x00439e00`, `0x0043e0b0`, `0x004a88e0`, `0x0054c160`, and `0x0057b9e0` consistently proves the corrected offsets; `Destroy` and `DestroyOwnedEntries` separately free `+0x00`.
- 2026-06-07 A006 Batch 083:
  - Changed score from `80/86` to `86/88` and set `AUTOGEN_PARENT_UID:0000IR`.
  - Summary/evidence: live IDA MCP reconfirmed all six Deque helper ranges, entry-caller counts, raw PrimeNumberGenerator-adjacent helper call, broad non-feature caller spread, and direct utility-file parent gate.
