*** UID:0001U2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00003P | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DequeLayout

## Status

- Entity kind: non-emitting MSVC/Dinkumware `std::deque` implementation-layout evidence, not a project class/struct declaration.
- Confidence: very strong for all five offsets, four-entry blocks for 4-byte specializations, proxy/map/size/offset/count roles, and toolchain source category.
- Direct owner: [UID:00003P][Deque](by-class/Deque.md)
- Source owner: [UID:0000IR][Deque](by-file/Deque.md)
- Assignment: retained under [UID:00003P][Deque](by-class/Deque.md) only as a non-emitting documentation grouping; [UID:0000IR][Deque](by-file/Deque.md) is reviewed with projected path `NONE`.
- Evidence basis: 2026-05-31 IDA MCP decompilation of `Destroy`, `EnsureCapacity`, `PushBack`, `Clear`, and `DestroyOwnedEntries`; `lookup_funcs` boundary checks for the Deque helper cluster; B013 2026-07-04 MCP session `eb7ce28b` constructor proxy evidence at `0x0054bcf0`; B003 2026-07-05 MCP session/database `19917133` cleanup evidence for UID0000XA; and B004 2026-07-05 MCP session/database `19917133` map-growth evidence for UID0000XB.

## Layout

```text
DequeLayout
  +0x00  void* proxyLikeStorageOrAllocatorSlot
  +0x04  uint32_t** blockMap
  +0x08  uint32_t blockCount
  +0x0c  uint32_t frontIndex
  +0x10  uint32_t count
```

Observed object size is at least `0x14` bytes.

`+0x00` is not the block map. IDA shows `Destroy` at `0x00439e00` and `DestroyOwnedEntries` at `0x0057b9e0` freeing `*(void**)this` after block-map cleanup, while `Clear` at `0x0054c160` leaves it untouched. B013's UID0001FC pass adds constructor evidence from `0x0054bcf0`: the embedded deque at `this+0x08` is zeroed, an 8-byte allocation is stored into `+0x00`, both allocation words are cleared, and the deque subobject pointer is written back through that allocation. B003's UID0000XA pass shows the raw-entry cleanup freeing this same slot after the standard deque block-map teardown. Treat `+0x00` as proxy-like standard deque support storage for the `std::deque` path, not as a final NexusTK-authored field name.

## Declaration Hypothesis

Model this only as the observed old Dinkumware `std::deque` implementation state shared by 4-byte specializations. Source-authored code declares typed `std::deque<int>` or `std::deque<OwnedAnsiString>` containers through `<deque>`; there was no project `util/Deque.h` declaration to emit.

```text
struct DequeLayout {
    void* proxyLikeStorageOrAllocatorSlot;  // +0x00, provisional documentation name
    uint32_t** blockMap;                    // +0x04
    uint32_t blockCount;                    // +0x08
    uint32_t frontIndex;                    // +0x0c
    uint32_t count;                         // +0x10
};
```

This declaration sketch is historical documentation notation only. The coordinated UID000149 full-family audit resolves every exact helper as standard-library/template support. `RECONSTRUCTABLE:FALSE`, blank emitter, and blank managed C++ prevent a duplicate project layout declaration.

## Storage Model

- Each allocated block stores four 4-byte entries.
- `blockCount` is grown as a power of two.
- Logical slot mask is `blockCount * 4 - 1`.
- Physical block index is `(logicalIndex >> 2) & (blockCount - 1)`.
- Entry index within a block is `logicalIndex & 3`.
- The non-emitted helper at `0x0054c0c0` implements this exact address calculation for a 4-byte element. B013 reclassified that exact page as MSVC/Dinkumware `std::deque` generated support with no custom formal C++.

UID0000XB `EnsureCapacity` copies old logical order into a new block map and resets `frontIndex` to zero, but B004 reclassified that exact range as non-emitting MSVC/Dinkumware `std::deque` map-growth / `_Growmap`-style support. Do not recreate the layout or this growth helper as project-owned source C++; source callers should use typed container operations.

The historical UID0001IE custom method conclusion is superseded. Its live SoundManager entry type proves a second 4-byte specialization, `std::deque<mystr::StringBase<char, mystr::mychar_traits<char> > >`, whose compiler-generated destructor uses this same layout. UID0001IE and this layout page are now false/blank toolchain evidence.

## Field Evidence Matrix

| Field | Confirming helpers | Evidence |
| --- | --- | --- |
| `+0x00` proxy-like standard deque support storage | [UID:0000XA][0x00439e00-0x00439ea3.DequeDestroy](by-memory/0x00439e00-0x00439ea3.DequeDestroy.md), [UID:0001IE][0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries](by-memory/0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries.md), [UID:0001FD][0x0054c160-0x0054c1f1.DequeClear](by-memory/0x0054c160-0x0054c1f1.DequeClear.md), [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md) | `Destroy` and `DestroyOwnedEntries` free and clear `*(void**)this` after block-map teardown; `Clear` frees block storage but leaves this slot untouched. B013 MCP session `eb7ce28b` shows `0x0054bcf0` allocating 8 bytes into this slot and writing the deque subobject pointer back through it, matching `std::deque` proxy/checking storage. B003 MCP session/database `19917133` rechecks UID0000XA and shows the raw-entry cleanup frees this slot after draining `+0x10`, resetting `+0x0c`, and tearing down `+0x04/+0x08`. |
| `+0x04` block map | [UID:0000XA][0x00439e00-0x00439ea3.DequeDestroy](by-memory/0x00439e00-0x00439ea3.DequeDestroy.md), [UID:0000XB][0x0043e0b0-0x0043e241.DequeEnsureCapacity](by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md), [UID:000149][0x004a88e0-0x004a8966.DequePushBack](by-memory/0x004a88e0-0x004a8966.DequePushBack.md), [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md), [UID:0001FD][0x0054c160-0x0054c1f1.DequeClear](by-memory/0x0054c160-0x0054c1f1.DequeClear.md), [UID:0001IE][0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries](by-memory/0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries.md) | Cleanup helpers walk block pointers through this field, UID0000XB standard-deque map growth replaces it, `PushBack` allocates missing block slots, and `ElementAddress` returns a slot address through it. |
| `+0x08` block count | [UID:0000XA][0x00439e00-0x00439ea3.DequeDestroy](by-memory/0x00439e00-0x00439ea3.DequeDestroy.md), [UID:0000XB][0x0043e0b0-0x0043e241.DequeEnsureCapacity](by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md), [UID:000149][0x004a88e0-0x004a8966.DequePushBack](by-memory/0x004a88e0-0x004a8966.DequePushBack.md), [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md), [UID:0001FD][0x0054c160-0x0054c1f1.DequeClear](by-memory/0x0054c160-0x0054c1f1.DequeClear.md), [UID:0001IE][0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries](by-memory/0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries.md) | Cleanup loops use it as the block-map count; UID0000XB standard-deque map growth doubles it as a power of two with a minimum of eight slots; slot arithmetic masks with `blockCount - 1`. |
| `+0x0c` front index | [UID:0000XA][0x00439e00-0x00439ea3.DequeDestroy](by-memory/0x00439e00-0x00439ea3.DequeDestroy.md), [UID:0000XB][0x0043e0b0-0x0043e241.DequeEnsureCapacity](by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md), [UID:000149][0x004a88e0-0x004a8966.DequePushBack](by-memory/0x004a88e0-0x004a8966.DequePushBack.md), [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md), [UID:0001FD][0x0054c160-0x0054c1f1.DequeClear](by-memory/0x0054c160-0x0054c1f1.DequeClear.md), [UID:0001IE][0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries](by-memory/0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries.md) | Emptying paths reset it when count drains to zero; UID0000XB standard-deque map growth copies from logical order and resets it; push and element-address helpers add it to the requested logical index. |
| `+0x10` count | [UID:0000XA][0x00439e00-0x00439ea3.DequeDestroy](by-memory/0x00439e00-0x00439ea3.DequeDestroy.md), [UID:000149][0x004a88e0-0x004a8966.DequePushBack](by-memory/0x004a88e0-0x004a8966.DequePushBack.md), [UID:0001FD][0x0054c160-0x0054c1f1.DequeClear](by-memory/0x0054c160-0x0054c1f1.DequeClear.md), [UID:0001IE][0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries](by-memory/0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries.md) | Destroy/clear variants drain it, `PushBack` increments it after writing a 4-byte entry, and owned-entry cleanup walks from the current count down to zero. |


## Cleanup Variants

- `Destroy` and `Clear` free blocks and the block map without interpreting payloads. `Destroy` also frees and clears `+0x00`; B003 reclassified that exact `Destroy` body as non-emitting MSVC/Dinkumware standard deque cleanup support rather than custom NexusTK C++.
- Historical `DestroyOwnedEntries` releases ref-counted string entries before freeing storage. Current caller evidence ties the generated destructor specialization to [UID:0000NV][SoundManager](by-file/SoundManager.md) directory-scan storage.
- `DestroyOwnedEntries` also frees and clears `+0x00` after block-map cleanup.

## IDA Evidence

- `0x00439e00` (`Destroy`) reads and decrements count at `+0x10`, resets front index at `+0x0c` when the last entry is removed, iterates block count at `+0x08`, frees blocks through the block map at `+0x04`, then frees and clears `+0x00`. Current B003 MCP session/database `19917133` also confirms its exact `0xa3` range, boundary padding, no xrefs to `0x00439ea3`, heap-free/invalid-parameter callees, and non-emitting standard-deque cleanup source category.
- `0x0043e0b0` (`EnsureCapacity` historical scaffold) reads block count at `+0x08`, front index at `+0x0c`, old block map at `+0x04`, installs the new block map at `+0x04`, and increases block count at `+0x08`. Current B004 MCP session/database `19917133` confirms its exact `0x191` range, boundary padding, no xrefs to `0x0043e241`, sixteen direct start xrefs, standard deque map-growth behavior, `operator new`/`memmove`/`memset`/free/overflow/invalid-parameter callees, `deque<T> too long` string route, and non-emitting standard-deque source category.
- `0x004a88e0` (`PushBack`) reads count at `+0x10`, front index at `+0x0c`, block count at `+0x08`, and block map at `+0x04`; it allocates 16-byte blocks, writes one 4-byte entry, and increments `+0x10`.
- `0x0054c160` (`Clear`) uses the same `+0x04/+0x08/+0x0c/+0x10` block-map fields and leaves `+0x00` alone.
- `0x0057b9e0` (`DestroyOwnedEntries`) walks entries using `+0x04/+0x08/+0x0c/+0x10`, calls the owned-entry release helper on each entry, then frees blocks, block map, and `+0x00`.

## 2026-06-11 Live IDA Recheck

IDA MCP `lookup_funcs`, `decompile`, and `callers` rechecked the six helper anchors:

| Helper | Current IDA range | Current ordinary caller count | Layout contribution |
| --- | --- | ---: | --- |
| [UID:0000XA][0x00439e00-0x00439ea3.DequeDestroy](by-memory/0x00439e00-0x00439ea3.DequeDestroy.md) | `0x00439e00-0x00439ea3` | 9 | Drains `+0x10`, resets `+0x0c`, walks/frees `+0x04/+0x08`, then frees `+0x00`. |
| [UID:0000XB][0x0043e0b0-0x0043e241.DequeEnsureCapacity](by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md) | `0x0043e0b0-0x0043e241` | 16 | Replaces `+0x04`, grows `+0x08`, preserves wrapped logical order from `+0x0c`, and zero-fills new map gaps. |
| [UID:000149][0x004a88e0-0x004a8966.DequePushBack](by-memory/0x004a88e0-0x004a8966.DequePushBack.md) | `0x004a88e0-0x004a8966` | 8 | Uses `+0x10/+0x0c/+0x08/+0x04` to append one 4-byte entry and calls `EnsureCapacity` when the next block is needed. |
| [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md) | `0x0054c0c0-0x0054c110` | 0 modeled callers; raw caller at `0x0054bce1` remains documented on the helper page | Computes `blockMap[((frontIndex + index) >> 2) & (blockCount - 1)] + 4 * ((frontIndex + index) & 3)`. |
| [UID:0001FD][0x0054c160-0x0054c1f1.DequeClear](by-memory/0x0054c160-0x0054c1f1.DequeClear.md) | `0x0054c160-0x0054c1f1` | 4 | Non-owning clear over `+0x04/+0x08/+0x0c/+0x10`; leaves `+0x00` untouched. |
| [UID:0001IE][0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries](by-memory/0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries.md) | `0x0057b9e0-0x0057baa3` | 1 normal caller plus an adjacent thunk documented on the helper page | Owned-entry cleanup over logical entries, then block-map teardown and `+0x00` free. |

The recheck keeps the first field provisional but raises completion because every other field has multiple independent helper confirmations and the direct class/source ownership chain is now written into this page.

## 2026-06-16 Live Recheck

A001 live IDA MCP session `c001_midiplayer_rdata_20260615` reconfirmed the same six helper starts and sizes, with `DequePushBack` still the only helper in the component that directly calls `DequeEnsureCapacity`. A section-mapped PE scan reconfirmed that the raw element-address helper at `0x0054c0c0` has no absolute-VA or RVA pointer encodings and the expected direct branch from `0x0054bce1` inside the PrimeNumberGenerator accessor.

This keeps the binary layout evidence grouped under [UID:00003P][Deque](by-class/Deque.md) without asserting project source ownership or emission.

## 2026-07-04 UID0001FC Source-Category Caveat

B013's accepted report for [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md) rechecked the element-address helper in MCP session `eb7ce28b`. The exact target remains `0x0054c0c0-0x0054c110`, size `0x50`, with four `0xcc` prebytes, next function `0x0054c110`, one raw xref at `0x0054bce1`, no callees, and the documented four-entry block formula.

The new source-quality point is the constructor proxy setup at `0x0054bcf0`: the embedded deque at `this+0x08` stores an 8-byte allocation at `+0x00`, clears it, and stores the deque pointer back through it. That evidence makes `+0x00` proxy-like standard deque support storage and supports treating UID0001FC as MSVC/Dinkumware `std::deque` generated support. This layout page keeps the broader grouping intact pending a full Deque-family audit; it does not authorize adding hand-authored `Deque::ElementAddress` C++ for UID0001FC.

## 2026-07-05 UID0000XA Source-Category Caveat

B003's accepted report for [UID:0000XA][0x00439e00-0x00439ea3.DequeDestroy](by-memory/0x00439e00-0x00439ea3.DequeDestroy.md) rechecked the raw-entry cleanup helper in MCP session/database `19917133`. The exact target remains `0x00439e00-0x00439ea3`, size `0xa3`, with seven `0xcc` prebytes, thirteen `0xcc` postbytes before `0x00439eb0`, thirteen code xrefs to the start, no xrefs to the exclusive end, callees only to `sub_5C7526` and `__invalid_parameter_noinfo_noreturn`, and a five-byte jump thunk at `0x00439f50`.

The source-quality point is that the body is pure standard deque storage cleanup: it drains count at `+0x10`, resets offset/front at `+0x0c`, frees block storage through `+0x04/+0x08`, applies the large-allocation guard before freeing the map, and frees the proxy-like `+0x00` storage. Combined with UID0001FC's constructor/proxy evidence, this supports treating UID0000XA as MSVC/Dinkumware `std::deque` cleanup / `_Tidy`-style support. The completed full-family audit retains this page only as a non-emitting documentation grouping and does not authorize hand-authored `Deque::Destroy` C++ for UID0000XA.

## 2026-07-05 UID0000XB Source-Category Caveat

B004's accepted report for [UID:0000XB][0x0043e0b0-0x0043e241.DequeEnsureCapacity](by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md) rechecked the map-growth helper in MCP session/database `19917133`. The exact target remains `0x0043e0b0-0x0043e241`, size `0x191`, with thirteen `0xcc` prebytes, fifteen `0xcc` postbytes before the distinct `0x0043e250` function, sixteen code xrefs to the start, no xrefs to the exclusive end, and callees to `operator new`, `_memmove_0`, `_memset`, `sub_5C7526`, `sub_43F190`, and `__invalid_parameter_noinfo_noreturn`.

The source-quality point is that the body is pure standard deque map growth: it doubles the map until the requested additional slots fit and the map has at least eight slots, uses `+0x0c >> 2` as the 4-byte-entry block-map offset, allocates the new map with the MSVC large-allocation guard, preserves wrapped map slices with `_memmove_0`, zero-fills gaps with `_memset`, frees the old map, and updates `+0x04/+0x08`. The overflow route reaches `deque<T> too long` at `0x0060f0a8` through `sub_43F190`, and the body/callee set matches ignored standard-deque reserve helpers such as `0x004e8860`. The completed full-family audit retains this page only as a non-emitting documentation grouping and does not authorize hand-authored `Deque::EnsureCapacity` C++ for UID0000XB.

## Assignment Gate Rationale

`DequeLayout` remains attached to [UID:00003P][Deque](by-class/Deque.md) only as implementation-layout documentation. Neither page is a source declaration or emitter, and [UID:0000IR][Deque](by-file/Deque.md) has projected path `NONE`.

The strict gate clears:

| Item | Completion | Confidence | Gate result |
| --- | ---: | ---: | --- |
| `DequeLayout` evidence page | 91 | 95 | reviewed non-emitting toolchain layout |
| [UID:00003P][Deque](by-class/Deque.md) grouping | 91 | 95 | reviewed non-emitting documentation grouping |
| [UID:0000IR][Deque](by-file/Deque.md) file record | 91 | 95 | reviewed `NONE`; no source root |

Final reconstruction C++ remains blank by disposition, not because of an unresolved project declaration. Standard `<deque>` declarations in concrete source owners regenerate the implementation layout.

## Open Questions

- Exact Dinkumware-internal proxy field spelling and compiler/header revision remain unknown; neither is required in NexusTK source.
- Additional 4-byte `std::deque` specializations may share these lowered helpers, but they do not change this no-emitter layout disposition.

## Cross-References

- [UID:00003P][Deque](by-class/Deque.md)
- [UID:0000IR][Deque](by-file/Deque.md)
- [UID:0000XA][0x00439e00-0x00439ea3.DequeDestroy](by-memory/0x00439e00-0x00439ea3.DequeDestroy.md)
- [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md)
- [UID:0000XB][0x0043e0b0-0x0043e241.DequeEnsureCapacity](by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md)
- [UID:000149][0x004a88e0-0x004a8966.DequePushBack](by-memory/0x004a88e0-0x004a8966.DequePushBack.md)
- [UID:0001FD][0x0054c160-0x0054c1f1.DequeClear](by-memory/0x0054c160-0x0054c1f1.DequeClear.md)
- [UID:0001IE][0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries](by-memory/0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)

## Changes

- 2026-07-12 B003 UID000149 full-family implementation:
  - Changed `87/90` to `91/95`, set `RECONSTRUCTABLE:FALSE`, cleared `EMITTER_UIDS`, and preserved exactly blank managed C++.
  - Reclassified the page from a prospective project struct declaration to binary/toolchain layout evidence for 4-byte `std::deque` specializations, including native integer callers and ANSI `StringBase` destruction.

- 2026-07-05 B004 UID0000XB implementation sync:
  - Added UID0000XB as supporting evidence for the map/size/offset standard-deque interpretation.
  - Documented that `EnsureCapacity` / `_Growmap` uses `+0x04/+0x08/+0x0c` as standard deque map-growth state and is non-emitting standard-library support rather than a project field method.
  - Evidence: accepted B004 report `tools/leaser/Agents/Agent-B004/research/0000XB-DequeEnsureCapacity-source-quality.md` and MCP session/database `19917133`, including exact range/bytes/xref/no-exclusive-end-xref/callee/string/comparator checks and body behavior.
- 2026-07-05 B003 UID0000XA implementation sync:
  - Added UID0000XA as supporting evidence for the proxy/map/offset/size standard-deque interpretation.
  - Documented that `Destroy` frees `+0x00` proxy-like storage after block-map teardown and is non-emitting standard-library cleanup rather than a project field method.
  - Evidence: accepted B003 report `tools/leaser/Agents/Agent-B003/research/0000XA-DequeDestroy-source-quality.md` and MCP session/database `19917133`, including exact range/bytes/xref/no-exclusive-end-xref/callee/thunk checks and body behavior.
- 2026-06-26 B002 implementation sync:
  - Changed score from `86/89` to `87/90`.
  - Added the current source-ready [UID:0001IE][0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries](by-memory/0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries.md) support note, including the field spellings used by the formal method code, the ANSI `StringBase` live entry type, and the remaining `+0x00` field caveat.
  - Layout-page formal C++ remains blank pending the full Deque declaration/API audit.
- 2026-07-04 B013 UID0001FC implementation sync:
  - Updated the `+0x00` caveat from broad auxiliary storage to proxy-like standard deque support storage for the UID0001FC path.
  - Preserved offsets, storage formula, and broader grouping pending a full Deque-family audit.
  - Evidence: accepted B013 report `tools/leaser/Agents/Agent-B013/research/0001FC-DequeElementAddressHelper-source-quality.md` and MCP session `eb7ce28b`, including exact helper range/bytes/xref/no-callee checks and `0x0054bcf0` constructor proxy setup.
- 2026-06-16 A001 Goal 2 support refresh:
  - Before: `85/88` with stale `95/95` code-entry wording and parent scores from the older Deque file/class pass.
  - Changed to: `86/89`, refreshed class/file parent scores, and documented the current live IDA/PE helper-set recheck.
  - Evidence: `lookup_funcs`, `xrefs_to`, `callees`, `analyze_component`, and a section-mapped PE scan reconfirmed the six helper ranges, raw element-address branch from `0x0054bce1`, no VA/RVA pointer hits to `0x0054c0c0`, and shared utility-container layout ownership. C++ remains blank because the final type name/header style and `+0x00` field role are unresolved.
- 2026-06-11 A001 strict-gate assignment:
  - What existed before: the page was `78/86`, reconstructable, and unassigned even though the Deque class/file chain had already been refreshed.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88`, and `AUTOGEN_PARENT_UID:00003P`.
  - Summary/evidence: live IDA MCP rechecked the six Deque helper anchors and current caller counts; the page now records a declaration hypothesis, field evidence matrix, helper matrix, and explicit strict-gate rationale. The direct class parent [UID:00003P][Deque](by-class/Deque.md) is `86/88`, and the upstream file [UID:0000IR][Deque](by-file/Deque.md) is `85/86`, so the layout can attach to the class while final C++ stays blank under the final-source gate.

- 2026-05-31 layout correction:
  - What existed before: the page listed `+0x00` as `blockMap`, `+0x04` as `blockCount`, `+0x08` as `frontIndex`, and `+0x0c` as `count`, with object size at least `0x10`.
  - Changed to: `+0x00` auxiliary owned pointer/storage slot, `+0x04` block map, `+0x08` block count, `+0x0c` front index, `+0x10` count, with object size at least `0x14`.
  - Summary/evidence: IDA MCP decompilation of `Destroy`, `EnsureCapacity`, `PushBack`, `Clear`, and `DestroyOwnedEntries` consistently uses `+0x04/+0x08/+0x0c/+0x10` for the deque block-map state; `Destroy` and `DestroyOwnedEntries` separately free `*(void**)this`, proving `+0x00` is not the block map.
- 2026-05-31 scoring and reconstructability:
  - What existed before: completion/confidence metadata was unevaluated at `0/0`, and `RECONSTRUCTABLE` was blank.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: the core layout and cleanup/growth semantics are now IDA-verified, but the exact `+0x00` semantic name, original type declaration style, and any constructor/initializer sites remain incomplete.
