*** UID:0000IR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Deque

## Status

- Reviewed disposition: `NONE`; no standalone NexusTK source/header exists for this documentation grouping.
- Source category: MSVC/Dinkumware `std::deque` template/support instantiated from concrete consumer translation units.
- Historical generated/recovered `class_Deque.cpp` is a rejected reconstruction scaffold, not original-TU evidence.
- Documentation grouping: [UID:00003P][Deque](by-class/Deque.md), now false/non-emitting.

## File Role

This page is a reviewed index for non-contiguous 4-byte `std::deque` implementation bodies. It does not own generated C++.

EventDispatcher, FolderTreePane, PrimeNumberGenerator, and WorldMap use source-facing `std::deque<int>` declarations/operations; SoundManager causes `std::deque<OwnedAnsiString>` destruction support. Broad fan-in and multiple element semantics prove template/toolchain factoring, not a generic project utility file.

The coordinated UID000149 audit extends the accepted UID0000XA/UID0000XB/UID0001FC classifications to PushBack, Clear, and DestroyOwnedEntries. `PROPOSED_RECONSTRUCTION_PATH:"NONE"` retires the false `NexusTK/util/Deque.cpp` route. Concrete source owners include `<deque>` and let the compiler/STL regenerate these bodies.

## Likely Contents

- [UID:00003P][Deque](by-class/Deque.md)
- [UID:0001U2][DequeLayout](by-type/by-struct/DequeLayout.md)
- raw-entry cleanup: `0x00439e00-0x00439ea3`, now non-emitting standard deque cleanup / `_Tidy`-style helper as [UID:0000XA][0x00439e00-0x00439ea3.DequeDestroy](by-memory/0x00439e00-0x00439ea3.DequeDestroy.md)
- growth/reblock helper: `0x0043e0b0-0x0043e241`, now non-emitting standard deque map-growth / `_Growmap`-style helper as [UID:0000XB][0x0043e0b0-0x0043e241.DequeEnsureCapacity](by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md)
- push-back helper: `0x004a88e0-0x004a8966`, non-emitting `std::deque<int>::push_back(const int&)` support
- element-address helper: `0x0054c0c0-0x0054c110`, now non-emitting standard deque support / `_Subscript`-style helper as [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md)
- non-owning clear helper: `0x0054c160-0x0054c1f1`, non-emitting Prime `std::deque<int>` cleanup support
- ownership-aware entry cleanup: `0x0057b9e0-0x0057baa3`, non-emitting `std::deque<OwnedAnsiString>` destruction support

## Evidence

- Historical Wave2/Wave3 `class_Deque` metadata is ignored as stale lead material and does not prove a source file.
- IDA MCP confirms all five active/emitted method starts and sizes.
- IDA caller checks show broad fan-in from EventDispatcher internals, FolderTreePane traversal helpers, MapPane paths, WorldMapPane reachability construction, and SoundManager music-directory scanning.
- 2026-05-31 IDA MCP decompilation corrects the shared layout to `+0x00` auxiliary owned pointer/storage slot, `+0x04` block map, `+0x08` block count, `+0x0c` front index, and `+0x10` count. Generated `class_Deque.cpp` is useful as a lead but is not authoritative for the first field offset.
- A 2026-05-25 IDA MCP recheck identifies `0x0054c0c0` as a 0x50-byte element-address helper: it computes the block-map slot and in-block offset for a 4-byte element. Active `class_Deque.cpp` does not currently emit this helper.
- B013 2026-07-04 MCP session `eb7ce28b` resolves why the helper should remain non-emitting: `0x0054c0c0` is an exact MSVC/Dinkumware `std::deque` element-address support body, not a NexusTK-authored helper. `lookup_funcs` reports size `0x50`; `xrefs_to` reports only raw caller `0x0054bce1`; `callees` is empty; byte/disassembly/decompile checks confirm the four-entry formula; and constructor context at `0x0054bcf0` allocates an 8-byte proxy into the embedded deque `+0x00` slot and stores the deque pointer back through it.
- B003 2026-07-05 MCP session/database `19917133` resolves why UID0000XA should also remain non-emitting: `0x00439e00` is an exact MSVC/Dinkumware `std::deque` cleanup / `_Tidy`-style support body, not a NexusTK-authored `Deque::Destroy` helper. `lookup_funcs` reports `sub_439E00` size `0xa3`; byte checks confirm seven `0xcc` prebytes and thirteen postbytes before `0x00439eb0`; xref checks report thirteen code xrefs to the start and none to the exclusive end; callees are only the heap-free wrapper and invalid-parameter noreturn helper; and the body drains count/front state, frees blocks/map with the large-allocation guard, and frees the proxy-like `+0x00` slot.
- B004 2026-07-05 MCP session/database `19917133` resolves why UID0000XB should also remain non-emitting: `0x0043e0b0` is an exact MSVC/Dinkumware `std::deque` map-growth / `_Growmap`-style support body, not a NexusTK-authored `Deque::EnsureCapacity` helper. `lookup_funcs` reports `sub_43E0B0` size `0x191`; byte checks confirm thirteen `0xcc` prebytes and fifteen postbytes before `0x0043e250`; xref checks report sixteen code xrefs to the start and none to the exclusive end; callees are `operator new`, `_memmove_0`, `_memset`, `sub_5C7526`, `sub_43F190`, and `__invalid_parameter_noinfo_noreturn`; and string/xref checks tie `sub_43F190` to `deque<T> too long` at `0x0060f0a8`.
- A 2026-05-26 recheck confirms active `class_Deque.cpp` still omits `0x0054c0c0`; IDA still reports no modeled callers, with the only xref coming from raw `PrimeNumberGenerator::GetPrimeAt` code at `0x0054bce1`.
- A 2026-05-31 IDA MCP recheck confirms the exact boundaries for all six helpers. Cross-feature xrefs are now understood as template-instantiation/folding evidence, not shared project-file ownership.
- Historical 2026-06-07 caller-count evidence remains useful for fan-in, but its former utility source-root conclusion is superseded by the coordinated standard-library classification.
- 2026-06-16 A001 live IDA MCP reconfirmed the current modeled helper set and sizes: `0x00439e00` size `0xa3`, `0x0043e0b0` size `0x191`, `0x004a88e0` size `0x86`, `0x0054c0c0` size `0x50`, `0x0054c160` size `0x91`, and `0x0057b9e0` size `0xc3`. `analyze_component` keeps only one internal edge, `DequePushBack -> DequeEnsureCapacity`, while other reachability comes from broad external callers.
- Current xrefs and PE evidence constrain exact consumers and boundaries. They reject any one feature owner but also reject a fabricated common project file; source ownership remains with each typed caller while toolchain support is non-emitting.
- Historical 2026-06-26 B002 evidence proves UID0001IE's SoundManager call, separate thunk, ANSI `StringBase` entry type, and exact destruction behavior. The former shared utility-body conclusion is superseded by `std::deque<OwnedAnsiString>` destructor classification.

## Source-Structure Decision

Do not create `util/Deque.cpp` or `util/Deque.h`. Keep this page only as a documentation index with projected path `NONE`. Concrete feature/utility source files own their typed `std::deque` expressions; the toolchain owns all listed lowered helpers.

## Generated Output Caveats

- Historical `class_Deque.cpp` is behavioral lead material only and should disappear from generated routing after this callback.
- The five methods are non-contiguous in the binary, so do not create one broad migration memory range around them.
- UID0001IE has SoundManager-specific caller/type evidence and remains exact binary documentation; it emits no custom destructor body.
- `0x0054c0c0` is physically adjacent to `PrimeNumberGenerator`, but its body is generic Deque layout arithmetic. Keep the raw `PrimeNumberGenerator` accessor at `0x0054bcc0` with `PrimeNumberGenerator`; keep this helper with Deque/container support.
- For UID0001FC specifically, "keep with Deque/container support" now means non-emitting standard deque support under the transitional Deque grouping. Do not add a custom `Deque::ElementAddress`/`GetAtAddress` body, and do not fold it into `PrimeNumberGenerator`; the source-level consumer remains `m_primes[index]`.
- For UID0000XA specifically, "keep with Deque/container support" now means non-emitting standard deque cleanup support under the transitional Deque grouping. Do not add a custom `Deque::Destroy` body to `util/Deque.cpp`; the source-level consumers should use typed containers and let compiler/STL support emit cleanup lowering.
- For UID0000XB specifically, "keep with Deque/container support" now means non-emitting standard deque map-growth support under the transitional Deque grouping. Do not add a custom `Deque::EnsureCapacity` body to `util/Deque.cpp`; the source-level consumers should use typed container operations and let compiler/STL support emit map-growth lowering.

## Cross-References

- [UID:00003P][Deque](by-class/Deque.md)
- [UID:0001U2][DequeLayout](by-type/by-struct/DequeLayout.md)
- [UID:0000XA][0x00439e00-0x00439ea3.DequeDestroy](by-memory/0x00439e00-0x00439ea3.DequeDestroy.md)
- [UID:0000XB][0x0043e0b0-0x0043e241.DequeEnsureCapacity](by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md)
- [UID:000149][0x004a88e0-0x004a8966.DequePushBack](by-memory/0x004a88e0-0x004a8966.DequePushBack.md)
- [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md)
- [UID:0001FD][0x0054c160-0x0054c1f1.DequeClear](by-memory/0x0054c160-0x0054c1f1.DequeClear.md)
- [UID:0001IE][0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries](by-memory/0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries.md)
- [UID:0000MQ][PrimeNumberGenerator](by-file/PrimeNumberGenerator.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)
- [UID:0000KS][List](by-file/List.md)
- [UID:0000N8][RingBuffer](by-file/RingBuffer.md)

## Changes

- 2026-07-12 B003 UID000149 full-family implementation:
  - Changed `87/89` to `91/95` and `PROPOSED_RECONSTRUCTION_PATH` from `NexusTK/util/` to `NONE`.
  - Retired the historical `Deque.cpp`/`Deque.h` scaffold, synchronized all six exact helpers as compiler/STL support, and routed source semantics to native typed containers in concrete consumer files.

- 2026-07-05 B004 UID0000XB implementation sync:
  - Qualified `util/Deque.cpp` further as a reconstruction scaffold pending broader Deque audit and marked UID0000XB as no custom emitter/formal C++.
  - Evidence: B004 report `tools/leaser/Agents/Agent-B004/research/0000XB-DequeEnsureCapacity-source-quality.md` and MCP session/database `19917133` confirmed exact range, boundary bytes, sixteen start xrefs, no exclusive-end xrefs, standard allocation/copy/zero/free callees, `deque<T> too long` string route, body behavior, and comparator standard-deque reserve helper evidence.
- 2026-07-05 B003 UID0000XA implementation sync:
  - Qualified `util/Deque.cpp` further as a reconstruction scaffold pending broader Deque audit and marked UID0000XA as no custom emitter/formal C++.
  - Evidence: B003 report `tools/leaser/Agents/Agent-B003/research/0000XA-DequeDestroy-source-quality.md` and MCP session/database `19917133` confirmed exact range, boundary bytes, thirteen start xrefs, no exclusive-end xrefs, heap-free/invalid-parameter callees, thunk `0x00439f50`, body behavior, and same-layout UID0001FC standard-deque support precedent.
- 2026-06-26 B002 implementation sync:
  - Changed score from `86/88` to `87/89`.
  - Marked `0x0057b9e0-0x0057baa3` as the first Deque helper child with formal first-draft C++ ready through [UID:0001IE][0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries](by-memory/0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries.md).
  - Preserved `NexusTK/util/` placement and clarified that the SoundManager caller is use-site evidence, not direct source ownership.
- 2026-07-04 B013 UID0001FC implementation sync:
  - Qualified `util/Deque.cpp` as a reconstruction scaffold pending broader Deque audit and marked UID0001FC as no custom emitter.
  - Evidence: B013 report `tools/leaser/Agents/Agent-B013/research/0001FC-DequeElementAddressHelper-source-quality.md` and MCP session `eb7ce28b` confirmed exact range, single raw caller, no callees, body formula, and `0x0054bcf0` constructor proxy setup. Historical `ElementAddress` / `GetAtAddress` names are descriptive scaffolds only for UID0001FC.
- 2026-06-16 A001 Goal 2 file/class completion pass:
  - Before: `COMPLETION:85`, `CONFIDENCE:86`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`, with current live IDA and PE evidence for all six helper starts, caller spread, raw PrimeNumberGenerator element-address call, and utility source-root placement.
  - Evidence: `lookup_funcs`, `xrefs_to`, `callees`, `analyze_component`, and a section-mapped PE scan in session `c001_midiplayer_rdata_20260615` reconfirmed the non-contiguous Deque helper set and the absence of a feature-specific owner. Final C++ remains blank because the original class/template spelling, helper names, and first-field role are still not final-source quality.
- 2026-05-27: Existing `Deque::Destroy` range used `0x00439e00-0x00439ea2`. Changed it to `0x00439e00-0x00439ea3`. Evidence: read-only IDA MCP reports `sub_439E00` as `0x00439e00-0x00439ea3`, size `0xa3`; the corresponding by-memory page [UID:0000XA][0x00439e00-0x00439ea3.DequeDestroy](by-memory/0x00439e00-0x00439ea3.DequeDestroy.md) records the boundary correction.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:78`.
  - Summary/evidence: shared utility-container role, likely contents, caller fanout, source-structure decision, generated-output caveats, non-contiguous method refs, and boundary correction are documented; confidence is medium-high because utility ownership is strong but exact original filename/folder remains uncertain.
- 2026-05-31 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - Changed to: `NexusTK/util/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` already places `Deque.cpp` under `util/`, and the 2026-05-31 IDA MCP recheck confirms the documented Deque helpers remain shared non-feature-specific container support.
- 2026-05-31 layout evidence correction:
  - What existed before: the evidence section said active generated `class_Deque.cpp` showed the shared layout as `m_blockMap`, `m_blockCount`, `m_frontIndex`, and `m_count`, which could imply `blockMap` starts at `+0x00`.
  - Changed to: the evidence section now records the IDA-confirmed layout with `+0x00` auxiliary pointer/storage, `+0x04` block map, `+0x08` block count, `+0x0c` front index, and `+0x10` count, and treats generated source as a lead only.
  - Summary/evidence: IDA MCP decompilation of Deque cleanup, growth, push, and ownership-aware cleanup helpers consistently proves the corrected offsets.
- 2026-06-07 A006 Batch 083:
  - Changed score from `84/82` to `85/86`.
  - Summary/evidence: live IDA MCP reconfirmed all six helper ranges, broad utility caller fan-in, the raw `PrimeNumberGenerator` element-address call, and shared container placement. Remaining uncertainty is exact original source/class spelling, not direct file ownership.
