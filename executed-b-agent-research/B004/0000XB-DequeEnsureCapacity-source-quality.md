** TARGET-REPORT-UID:0000XB **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0000XB DequeEnsureCapacity Source-Quality Report

## Finalized Report / Current Recommendation

UID0000XB should not receive a hand-written NexusTK `Deque::EnsureCapacity` formal C++ body. Gate 1 passed, and the implementation callback has reclassified the exact target as MSVC/Dinkumware `std::deque` block-map growth support for a 4-byte element deque, equivalent to an outlined `_Growmap`/reserve-map helper generated from ordinary source `std::deque` use.

Implemented disposition:

- Target `by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md`: set `COMPLETION:89`, `CONFIDENCE:92`, kept `CANONICAL_OWNER:00003P` only as a transitional Deque documentation grouping, set `RECONSTRUCTABLE:FALSE`, cleared `EMITTER_UIDS`, and kept the formal C++ block blank.
- Do not emit a custom `NexusTK/util/Deque.cpp` body for this target. The source-facing reconstruction should use typed container operations in consumers, for example the already accepted `std::deque<int>` traversal/pending-container code, and let the compiler/STL provide this helper.
- Updated support docs so UID0000XB joins UID0001FC and UID0000XA as understood non-emitting STL deque support. Sibling Deque exact pages and project-structure docs were not mass-reclassified.

Scoped validators passed for every changed by-* file. Generated output was refreshed only through the validator path; no manual edits were made to generated files, manual coverage reports, validator state, lifecycle/archive files, or report archives.

## Supporting Research

The supervisor restored MCP and provided fresh session `19917133`. I discarded the stale zero-session incident as historical context only and used session `19917133` for the required evidence pass.

Gate 1 later passed for this report, and the supervisor authorized the implementation callback for UID0000XB. The callback applied only the accepted target/support documentation scope: target page, Deque class page, Deque file page, and Deque layout page. `by-meta/client_containers.md` was checked for a blocking UID0000XB contradiction and did not require a change.

Current MCP availability:

- MCP `server_health` id `10`: `status:"ok"`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input binary `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- MCP `tools/list`: current schemas expose the read-only tools used here: `lookup_funcs`, `xrefs_to`, `callees`, `get_bytes`, `analyze_function`, `decompile`, `disasm`, `find_regex`, and `search_text`; this MCP build requires `database` on each tool call.

Local research checked the target page, Deque class/file/layout support pages, sibling Deque pages, generated coverage/output leads, project tracker rows, executed B-agent reports, current Agent notes, and archived markdown. The relevant accepted lead is B013 UID0001FC, which already reclassified the same Deque family element-address helper as non-emitting MSVC/Dinkumware `std::deque` support while keeping UID00003P only as a transitional documentation grouping.

## Target

- UID: `0000XB`
- Target path: `by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md`
- Report path: `tools/leaser/Agents/Agent-B004/research/0000XB-DequeEnsureCapacity-source-quality.md`
- Current title: `0x0043e0b0-0x0043e241 DequeEnsureCapacity`
- Implemented metadata: `COMPLETION:89`, `CONFIDENCE:92`, `CANONICAL_OWNER:00003P`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Current generated state: `auto-generated/NexusTK/util/Deque.cpp` was refreshed by validator command `000000006652` at `2026-07-05T01:56:41-04:00` and no longer contains a UID0000XB empty emitter marker.
- Current tracker state: `auto-generated/-ag-research-tracker.md` lists UID0000XB as `89/92`, average `90.5`, reconstructable `false`, report count `0`.
- Current memory coverage state: `auto-generated/-ag-memory-coverage.md` lists UID0000XB as `not_reconstructable`, owner `00003P`, blank emitter, no generated output.

The target is a real exact function. The recommendation changes source category and emission route, not function existence or behavior.

## Current Target State

The target now documents a non-emitting MSVC/Dinkumware `std::deque` map-growth helper that doubles a power-of-two block map, allocates a replacement map, preserves wrapped entries, zeroes the newly opened gaps, frees the old map, and updates fields at `+0x04` and `+0x08`.

Facts already correct and preserved:

- Exact half-open range is `0x0043e0b0-0x0043e241`.
- The IDA function is `sub_43E0B0`, size `0x191`.
- `0x0043e0a3-0x0043e0b0` is 13 bytes of `0xcc` padding.
- `0x0043e241-0x0043e250` is 15 bytes of `0xcc` padding.
- No direct xrefs target the exclusive end `0x0043e241`.
- The next function starts at `0x0043e250` and is outside UID0000XB.
- The body calls `operator new`, `_memmove_0`, `_memset`, checked free `sub_5C7526`, overflow helper `sub_43F190`, and `__invalid_parameter_noinfo_noreturn`.
- The caller spread is broad and crosses unrelated consumers.

Historicalized or rejected facts:

- "Project DequeEnsureCapacity" and `NexusTK/util/Deque.cpp` should be treated as reconstruction scaffolding, not proof of original product-owned source.
- The blank C++ block is not a source-name blocker to solve by inventing a custom method. It is now documented as intentional no-code proof that the helper is compiler/STL-generated support.

## Heuristic / Inference Reanalysis And Validation

The previous blocker was framed as unresolved source-grade class/template/helper spelling. Current MCP evidence resolves the source category more strongly: the target body is the same Dinkumware deque map-growth shape as accepted ignored STL helper pages, and it reaches the literal `deque<T> too long` through `sub_43F190`.

Validation points:

- MCP `decompile 0x0043e0b0` shows map capacity starts at `this[2]` or `1`, doubles until `newMapSize - oldMapSize >= requested` and `newMapSize >= 8`, and calls `sub_43F190` on overflow.
- The decompile reads `this[3] >> 2` as the current map block index, which matches a 4-byte element deque with four entries per 16-byte block.
- Allocation uses `operator new(4 * newMapSize)` for small maps and the MSVC large-allocation convention for maps `>= 0x1000`: allocate `size + 0x23`, align to 32 bytes, and store the original raw pointer at `aligned[-1]`.
- The body copies the old block map with `_memmove_0`, handles both wrapped and non-wrapped layouts, zero-fills unused slots with `_memset`, validates the old aligned pointer slack against `0x1f`, frees with `sub_5C7526`, then writes the new map pointer at `+0x04` and grows map size at `+0x08`.
- MCP `find_regex` and `search_text` find the literal `deque<T> too long` at `0x0060f0a8`; MCP `xrefs_to 0x0060f0a8` shows the data xref from `sub_43F190`; MCP `xrefs_to 0x0043f190` includes UID0000XB at `0x0043e237`.
- MCP `callees` reports UID0000XB and accepted ignored comparator `0x004e8860` with the same six callees: `operator new`, `_memmove_0`, `_memset`, `sub_5C7526`, `sub_43F190`, and `__invalid_parameter_noinfo_noreturn`.
- Current docs already classify `0x004e8860-0x004e89f2.CandidateStringQueueReserveAdditional` as ignored MSVC/Dinkumware `std::deque<std::wstring>` map-growth support; its decompile is structurally the same reserve-map algorithm.
- Accepted B013 UID0001FC proves that at least one helper in the current Deque grouping is MSVC/Dinkumware `std::deque` support, not NexusTK-authored `util/Deque.cpp` source.
- Accepted B015/B007 FolderTree traversal reports use UID0000XB as low-level deque/segmented-container compiler support while recommending source-facing `std::deque<int>` operations, not raw helper calls.

The strongest alternative explanation is a project-authored wrapper around Dinkumware-like internals. Current evidence does not support hand emission for that alternative: there is no PDB/source name, no feature-specific state, no NexusTK-specific error path, and the literal diagnostic is standard-library text.

## Evidence Standards Used

- IDA MCP session `19917133` is treated as ground truth for function bounds, xrefs, byte ranges, callees, decompile/disassembly facts, and strings.
- Current by-* docs are treated as current documentation state and implementation leads, not final proof of original source ownership when MCP/source-category evidence contradicts the emitted route.
- Generated C++ and generated coverage are treated as symptoms/leads only. The UID0000XB empty marker proves the current coverage problem; it does not prove that custom C++ should be invented.
- Executed B-agent reports are treated as accepted local precedent, then rechecked against current docs and current MCP.
- Source-quality inference prefers plausible C++ source operations over decompiler-shaped direct field manipulation. Standard-library/generated helpers get no-code proof, not hand-port C++.
- The 95+ score range remains blocked unless exact source category, source placement, names, and family effects are fully audited.

## Evidence Checked

- Assignment docs: `tools/leaser/Agents/Agent-B004/goal.md`, `notes.md`.
- Target doc: `by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md`.
- Support docs: `by-class/Deque.md`, `by-file/Deque.md`, `by-type/by-struct/DequeLayout.md`, `by-meta/client_containers.md`.
- Sibling Deque docs: `DequeDestroy`, `DequePushBack`, `DequeElementAddressHelper`, `DequeClear`, and `DequeDestroyOwnedEntries`.
- Comparative STL docs: `by-memory/0x004e8860-0x004e89f2.CandidateStringQueueReserveAdditional.md`, `by-type/by-template/CandidateStringDequeTemplate.md`, `by-memory/0x0060f038-0x0060f4c0.MsvcStlNumericRdata.md`.
- Boundary/support docs: `by-memory/-ignored.md`, `by-memory/0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport.md`, and `by-memory/0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport.md`.
- Consumer evidence docs: FolderTree traversal pages, PrimeNumberGenerator docs, EventDispatcher support pages, and generated `auto-generated/NexusTK/util/Deque.cpp`.
- Generated/tracker reads: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`.
- Implementation verification reads after validator refresh: `auto-generated/NexusTK/util/Deque.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `tools/leaser/Agents/current_leases.md`.
- Narrow meta check: `by-meta/client_containers.md` was searched for UID0000XB/Deque contradictions and did not block this target implementation; no edit was required.
- Report searches: current Agent folders, executed B-agent research, and archived markdown. Archived markdown had no direct UID0000XB/target matches.
- MCP session `19917133` calls:
  - `server_health` id `10`.
  - `lookup_funcs` id `11` for `0x0043e0a3`, `0x0043e0b0`, `0x0043e240`, `0x0043e241`, `0x0043e250`, sibling Deque starts, comparator `0x004e8860`, `0x005980f0`, and `0x0043f190`.
  - `xrefs_to` id `12` for `0x0043e0b0`, `0x0043e241`, `0x0043f190`, and `0x0060f0a8`.
  - `callees` id `13` for `0x0043e0b0`, `0x004a88e0`, `0x004e8860`, and `0x005980f0`.
  - `get_bytes` id `14` for target padding, target body, post-target padding, and `0x0043f190`.
  - `analyze_function` id `20`, `decompile` id `21`, and `disasm` id `22` for `0x0043e0b0`.
  - `decompile` id `23` for comparator `0x004e8860`.
  - `find_regex` id `24` and `search_text` id `25` for `deque<T> too long`.
  - `xrefs_to` id `30`, `decompile` id `31`, and `callees` id `32` for adjacent/comparator helpers.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Recommended action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0000XB-01 | UID0000XB is exactly `0x0043e0b0-0x0043e241`, IDA `sub_43E0B0`, size `0x191`, with `0xcc` padding before and after. | confirmed | MCP `lookup_funcs` id `11`, `get_bytes` id `14`, `disasm` id `22`; current target and `-ignored` agree. | Target `Current MCP Evidence`; target `Covered Range`; layout evidence caveat. | Preserved and refreshed under session `19917133`. | Applied. Verified by validator command `000000006649` for target and `000000006652` for layout, both exit `0`, `ok:1`. |
| C-0000XB-02 | No xrefs target exclusive end `0x0043e241`; `0x0043e250` is a distinct next function. | confirmed | MCP `lookup_funcs` id `11`, `xrefs_to` id `12`, `get_bytes` id `14`; current `MsvcStlJsonCppStringSupport` page. | Target `Current MCP Evidence`; target `Rejected Alternatives`. | Preserved; range merge with `0x0043e250` rejected. | Applied. Verified by validator command `000000006649`, exit `0`, `ok:1`. |
| C-0000XB-03 | The body is a deque block-map growth helper for 4-byte elements. | confirmed | MCP decompile/disasm ids `21`/`22`: minimum 8 map slots, doubling, `this[3] >> 2`, `4 * newMapSize`, wrapped `memmove`, zero `memset`, final `+0x04/+0x08` writes. | Target summary/status, `Current MCP Evidence`, `Reconstruction Notes`; layout storage model and field evidence matrix. | Behavior preserved; source category changed to standard deque map-growth support. | Applied. Verified by target/layout validators `000000006649` and `000000006652`, both exit `0`, `ok:1`. |
| C-0000XB-04 | The overflow path is standard deque STL support, not NexusTK-specific policy. | strong | MCP `find_regex`/`search_text` ids `24`/`25` find `deque<T> too long`; `xrefs_to` id `12` ties `0x0060f0a8` to `sub_43F190` and UID0000XB callsite `0x0043e237`. | Target `Current MCP Evidence` and `Reconstruction Notes`; class/file/layout support caveats. | Added as decisive no-code evidence. | Applied. Verified by validators `000000006649` through `000000006652`, all exit `0`, `ok:1`. |
| C-0000XB-05 | The callee set matches accepted ignored `std::deque` map-growth support at `0x004e8860`. | strong | MCP `callees` id `13`; decompile comparator id `23`; current `CandidateStringQueueReserveAdditional` page. | Target `Current MCP Evidence`, `Cross-References`, `Rejected Alternatives`; class/file/layout support text. | Comparator evidence added; custom emission rejected. | Applied. Verified by validators `000000006649` through `000000006652`, all exit `0`, `ok:1`. |
| C-0000XB-06 | Broad caller fan-in proves utility/compiler support reachability, not direct NexusTK source ownership. | strong | MCP `xrefs_to` id `12` has 16 code xrefs across unrelated contexts; target/current support docs map those contexts. | Target `Current MCP Evidence`, `Reconstruction Notes`, `Rejected Alternatives`; class/file support caveats. | Feature ownership and custom product helper ownership rejected. | Applied. Verified by validators `000000006649` through `000000006651`, all exit `0`, `ok:1`. |
| C-0000XB-07 | UID0000XB should be non-reconstructable with blank emitter and blank formal C++. | strong | MCP source-category evidence, accepted B013 UID0001FC precedent, B015/B007 source-facing `std::deque<int>` precedent, generated empty marker symptom. | Target metadata, target `Reconstruction Notes`, formal C++ block; file generated-output caveat. | Set `RECONSTRUCTABLE:FALSE`, cleared `EMITTER_UIDS`, left C++ blank. | Applied. Target validator `000000006649` reported `completion_update:1`, `confidence_update:1`, `autogen_registry_update:2`; generated `Deque.cpp` no longer contains UID0000XB. |
| C-0000XB-08 | UID00003P can remain as transitional grouping if callback scope is narrow. | medium-high | B013 accepted pattern for UID0001FC; current Deque class/file/layout pages still group sibling helpers. | Target metadata/status; class/file/layout caveats. | Kept `CANONICAL_OWNER:00003P` with explicit caveat. | Applied. Verified by validators `000000006649` through `000000006652`, all exit `0`, `ok:1`. |
| C-0000XB-09 | Deque siblings should not be mass reclassified from this report alone. | medium-high | Siblings have their own semantics and one already emits formal C++; B013 explicitly deferred broader family reclassification. | Class/file/layout support docs; no sibling exact page or project-structure edits. | Narrow callback only; no blanket edits. | Applied by omission with verification: only the four accepted by-* docs were edited; `by-meta/client_containers.md` checked and not edited because it had no blocking contradiction. |

## Positive Evidence Summary

- Current MCP session `19917133` is healthy and confirms the target function exists at `0x0043e0b0` with size `0x191`.
- Boundary evidence is clean: padding before and after, no xrefs to the exclusive end, and the next function starts at `0x0043e250`.
- The body is a full map-growth helper: double until enough extra block slots exist, require minimum 8 slots, allocate a new map, copy wrapped old map ranges, zero new gaps, free the old map, and update map pointer/map size.
- The 4-byte/four-entry deque form is explicit: `this[3] >> 2` selects the block-map offset, while map entries are copied in 4-byte pointer units.
- The helper calls the standard deque overflow path `sub_43F190`, and MCP finds the only string `deque<T> too long` at `0x0060f0a8`.
- Accepted ignored STL helper `0x004e8860` has the same core decompile and the same six callees.
- B013 already proved UID0001FC in this same Deque grouping is standard-library `std::deque` support, not NexusTK-authored `Deque.cpp`.
- Pre-callback generated output had an empty emitter marker for UID0000XB, showing the project had been trying to emit a target that should instead be no-code. Validator refresh has now removed that UID0000XB marker.

## Negative Evidence Summary

- No MCP evidence names `Deque::EnsureCapacity`, `Deque::_Growmap`, or a NexusTK-authored source function.
- No PDB, source file, header, typedef, or member spelling proves a custom `NexusTK/util/Deque.cpp` body.
- The literal `deque<T> too long` is standard-library diagnostic evidence against a bespoke NexusTK helper.
- The caller spread is broad and cross-feature; broad fan-in is reachability evidence, not ownership evidence.
- A hand-written C++ body using `m_blockMap`, `m_blockCount`, and `m_frontIndex` would reproduce STL internals as decompiler-shaped source.
- Emitting this helper through `Deque.cpp` would duplicate standard library implementation rather than reconstruct product source.
- Physical adjacency to runtime/JsonCpp support islands does not make the helper part of a product-owned Deque module.
- The broader Deque family still contains mixed evidence; this report does not prove every sibling should be non-emitting.

## IDA MCP Facts

| Probe | Current result |
| --- | --- |
| `server_health` id `10` | `status:"ok"`, IDB `NexusTK.exe.i64`, imagebase `0x400000`, Hex-Rays ready. |
| `lookup_funcs 0x0043e0b0` id `11` | `sub_43E0B0`, size `0x191`. |
| `lookup_funcs 0x0043e0a3` id `11` | Not a function. |
| `lookup_funcs 0x0043e240` id `11` | Inside `sub_43E0B0`. |
| `lookup_funcs 0x0043e241` id `11` | Not a function. |
| `lookup_funcs 0x0043e250` id `11` | `sub_43E250`, size `0x192`, outside UID0000XB. |
| `get_bytes 0x0043e0a3 size 13` id `14` | Thirteen `0xcc` bytes. |
| `get_bytes 0x0043e241 size 15` id `14` | Fifteen `0xcc` bytes. |
| `xrefs_to 0x0043e0b0` id `12` | 16 code xrefs, no truncation. |
| `xrefs_to 0x0043e241` id `12` | No cross-references. |
| `callees 0x0043e0b0` id `13` | `operator new`, `_memmove_0`, `_memset`, `sub_5C7526`, `sub_43F190`, `__invalid_parameter_noinfo_noreturn`. |
| `analyze_function 0x0043e0b0` id `20` | Prototype `void __thiscall(_DWORD *this, void *)`, size `401`, 24 basic blocks, cyclomatic complexity `10`. |
| `disasm 0x0043e0b0` id `22` | 150 instructions; returns with `retn 4` at `0x43e232`; overflow branch calls `sub_43F190` at `0x43e237`. |
| `find_regex/search_text deque<T> too long` ids `24`/`25` | One string at `0x0060f0a8`, data xref from `sub_43F190`. |

## Function / Child Inventory

| Address | MCP function | Size | Current doc role | Source-quality interpretation |
| --- | --- | ---: | --- | --- |
| `0x00439e00` | `sub_439E00` | `0xa3` | `DequeDestroy` sibling | Needs separate audit; current route remains as documented. |
| `0x0043e0b0` | `sub_43E0B0` | `0x191` | `DequeEnsureCapacity` target | Preferred: non-emitting MSVC/Dinkumware `std::deque` map-growth helper. |
| `0x0043e250` | `sub_43E250` | `0x192` | Next support island, outside target | Separate function; structurally similar STL map-growth support. |
| `0x004a88e0` | `sub_4A88E0` | `0x86` | `DequePushBack` sibling and direct caller | Needs separate audit; source callers should generally express container operations. |
| `0x004e8860` | `sub_4E8860` | `0x192` | CandidateStringQueue reserve comparator | Already non-reconstructable ignored MSVC/Dinkumware `std::deque<std::wstring>` support. |
| `0x0054c0c0` | `sub_54C0C0` | `0x50` | `DequeElementAddressHelper` sibling | Already accepted as non-emitting MSVC/Dinkumware `std::deque` support. |
| `0x0054c160` | `sub_54C160` | `0x91` | `DequeClear` sibling | Needs separate audit; current route remains as documented. |
| `0x0057b9e0` | `sub_57B9E0` | `0xc3` | `DequeDestroyOwnedEntries` sibling | Currently emits first-draft C++; do not disturb from this report alone. |

## Direct Xref / Caller Inventory

MCP `xrefs_to 0x0043e0b0` id `12` reports 16 direct code xrefs:

| Callsite | Containing function | Current documentation context |
| --- | --- | --- |
| `0x0042b4ca` | `sub_42B120` | JsonCpp/runtime support context in current target summary. |
| `0x004335e0` | `sub_4331F0` | JsonCpp/runtime support context in current target summary. |
| `0x00442824` | `sub_442800` | JsonCpp/runtime support context in current target summary. |
| `0x004a7fc9` | `sub_4A7E70` | EventDispatcher helper context. |
| `0x004a812e` | `sub_4A7E70` | EventDispatcher helper context. |
| `0x004a8553` | `sub_4A8420` | EventDispatcher temporary descendant-walk storage. |
| `0x004a8904` | `sub_4A88E0` | Deque push/append helper. |
| `0x004b35ac` | `sub_4B3400` | FolderTree content-dimension traversal using source-facing `std::deque<int>`. |
| `0x004b37ac` | `sub_4B3650` | FolderTree paint traversal using source-facing `std::deque<int>`. |
| `0x004b3a3c` | `sub_4B3850` | FolderTree hit-test traversal support. |
| `0x004b3c89` | `sub_4B3AF0` | FolderTree visible-navigation traversal support. |
| `0x0054be64` | `sub_54BCF0` | PrimeNumberGenerator constructor/context. |
| `0x0054bf69` | `sub_54BCF0` | PrimeNumberGenerator constructor/context. |
| `0x0057aa04` | `sub_57A890` | SoundManager-style documented consumer context. |
| `0x0057ad94` | `sub_57A890` | SoundManager-style documented consumer context. |
| `0x005c4f83` | `sub_5C4BD0` | WorldMapPane/documented container consumer context. |

This spread is positive evidence for shared library/container support and negative evidence against feature-module ownership.

## Documentation Evidence And IDA Status

- `by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md` now has accurate low-level behavior, current MCP evidence, non-emitting source category, blank emitter, and blank formal C++.
- `by-class/Deque.md` and `by-file/Deque.md` now caveat UID0001FC, UID0000XA, and UID0000XB as standard-library `std::deque` support; UID0000XB is no longer routed as reconstructable custom C++.
- `by-type/by-struct/DequeLayout.md` records the correct offsets and now describes UID0000XB as standard deque map-growth support for 4-byte elements, not as project-owned layout source.
- `by-memory/-ignored.md` correctly records both padding ranges around UID0000XB.
- `by-memory/0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport.md` correctly treats the following island as runtime/STL/JsonCpp support and confirms UID0000XB boundary separation.
- `auto-generated/NexusTK/util/Deque.cpp` currently emits `Deque::DestroyOwnedEntries()` plus remaining empty markers for other Deque pages, but the UID0000XB empty marker is gone after validator refresh.

## Range / Split / Padding / Reclassification Analysis

No split or range edit is recommended. The exact function starts at `0x0043e0b0`, ends before `0x0043e241`, returns with `retn 4`, and is isolated by padding. The following `sub_43E250` begins after 15 bytes of padding and has separate xrefs.

The required change is reclassification:

- From: reconstructable project `Deque::EnsureCapacity` method with blank C++ pending source spelling.
- To: non-reconstructable MSVC/Dinkumware `std::deque` map-growth support body with no target-local C++.

This reclassification resolved the empty-emitter problem without creating a decompiler-shaped source body.

## Ranked Ownership Analysis

| Rank | Candidate | Evidence For | Evidence Against | Decision |
| ---: | --- | --- | --- | --- |
| 1 | MSVC/Dinkumware `std::deque` map-growth support for 4-byte elements | `deque<T> too long` literal path; Dinkumware large-allocation pattern; identical callee set and structure to accepted ignored `std::deque` reserve helper; B013 UID0001FC precedent; broad unrelated callers. | Current docs scaffold the helper as `Deque::EnsureCapacity`; broader family not fully reclassified. | Preferred source category; non-emitting/no formal C++. |
| 2 | Transitional [UID:00003P] `Deque` documentation grouping | Existing docs and generated route group this exact helper with DequeLayout and siblings; B013 kept UID00003P for non-emitting UID0001FC continuity. | Grouping name can imply product ownership; generated `util/Deque.cpp` output is not authoritative. | Keep only as transitional canonical owner for narrow callback. |
| 3 | Hand-authored NexusTK `NexusTK/util/Deque.cpp` method | Current target/file/class names and current generated marker imply this route. | No source name proof; standard deque diagnostic; STL allocation/move/free shape; accepted reports recommend source-facing `std::deque` use. | Rejected for formal C++ emission. |
| 4 | Feature owners such as EventDispatcher, FolderTreePane, PrimeNumberGenerator, SoundManager, WorldMapPane | Direct callers exist in those areas. | Body is generic container map growth and has broad unrelated fan-in. | Rejected as canonical owner; they are consumers only. |
| 5 | No-owner unknown helper | Raw IDA name and no source symbol could imply uncertainty. | Behavior, string, comparators, and caller pattern are understood. | Rejected; it is known standard-library support. |

## Source Placement

Do not place UID0000XB in hand-authored `NexusTK/util/Deque.cpp` source. The best source placement is standard-library/compiler support generated from ordinary source declarations and operations using `std::deque<T>` or an equivalent source-level typedef/member.

For current documentation continuity, [UID:00003P] `Deque` can continue to group exact Deque-family pages, but it should say this is a transitional documentation grouping around standard-library deque internals and helper materializations. The final source route should be through consumers' typed container usage, not through a custom `Deque::EnsureCapacity` implementation.

## First-Draft C++ Recommendation

No formal C++ body should be inserted for UID0000XB.

Exact no-code proof:

- The target is compiled MSVC/Dinkumware `std::deque` block-map growth support, not a NexusTK-authored function.
- The `deque<T> too long` literal, `_Growmap`-style doubling/minimum-8 logic, 32-byte aligned allocation convention, wrapped map copy, and checked free match standard-library implementation.
- Accepted local precedent reclassifies the same Deque family element-address helper UID0001FC as non-emitting STL support.
- Accepted consumer reports reconstruct source operations as `std::deque<int>` push/back/pop usage rather than raw helper calls.
- Hand-emitting this helper would encode standard-library internals in project source and would not be source-quality reconstruction.

The target formal C++ should remain blank after metadata reclassification:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

No import directive, namespace-local helper, or `Deque::EnsureCapacity` function should be added for this target.

## Final Recommendation

This implementation applied the source-category correction. UID0000XB is exact and behaviorally understood, but it is now non-emitting standard-library deque support.

Implemented callback shape:

- Updated the target metadata to `89/92`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank C++.
- Kept `CANONICAL_OWNER:00003P` as a transitional grouping unless the supervisor chooses a broader coordinated Deque reclassification.
- Updated target text with current MCP session `19917133` evidence and the no-code proof.
- Updated support docs so `Deque.cpp` is not treated as proof of original source ownership for UID0000XB.
- Refreshed generated outputs only through scoped validator runs; no generated files or coverage files were manually edited.

## Recommended Target Doc Changes

For `by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md`:

- Set `COMPLETION:89`.
- Set `CONFIDENCE:92`.
- Kept `CANONICAL_OWNER:00003P` only as a transitional documentation grouping.
- Set `RECONSTRUCTABLE:FALSE`.
- Cleared `EMITTER_UIDS`.
- Kept `EMITTER_POSITION_OPTIONAL:` blank.
- Kept formal `RECONSTRUCTION_CPP CODE` blank.
- Changed the item summary/status to identify the exact range as MSVC/Dinkumware `std::deque` 4-byte block-map growth support, not NexusTK-authored source.
- Preserved exact boundary, padding, xref, callee, and behavior facts.
- Added MCP session `19917133` evidence: `server_health`, `lookup_funcs`, `get_bytes`, `xrefs_to`, `callees`, `analyze_function`, `decompile`, `disasm`, string search, and comparator checks.
- Added source-category rationale using `deque<T> too long`, accepted UID0001FC precedent, accepted CandidateStringQueue reserve helper precedent, and broad caller spread.
- Added rejected alternatives: hand-authored `util/Deque.cpp`, feature ownership, no-owner unknown, range merge with `0x0043e250`, and formal decompiler-shaped C++.

These recommended target changes have been applied in the callback and verified by scoped validator command `000000006649`.

## Recommended Support Doc Changes

For `by-class/Deque.md`:

- Added UID0000XB to the caveat that at least UID0001FC, UID0000XA, and UID0000XB are MSVC/Dinkumware `std::deque` support helpers rather than proof of a NexusTK-authored Deque class.
- Kept the helper inventory, but changed the UID0000XB row/status to non-emitting STL deque map-growth support; source callers should use typed container operations.
- Did not reclassify every sibling in this callback.

For `by-file/Deque.md`:

- Qualified `NexusTK/util/Deque.cpp` as a reconstruction scaffold/transitional grouping, not proof that UID0000XB belongs in hand-authored product source.
- Marked UID0000XB as no custom emitter/formal C++.
- Preserved `DestroyOwnedEntries` as current first-draft code until separately reviewed.

For `by-type/by-struct/DequeLayout.md`:

- Preserved offsets `+0x00/+0x04/+0x08/+0x0c/+0x10`.
- Added that UID0000XB uses the layout as standard deque `_Growmap`/map-growth support for 4-byte elements.
- Kept layout formal C++ blank; standard library declarations should not be recreated as project-owned layout source.

For `by-meta/client_containers.md` and consumer docs:

- Checked `by-meta/client_containers.md` for a direct UID0000XB contradiction; no blocking contradiction was present, so no edit was made.
- Consumer guidance remains source-facing `std::deque<T>` or accepted typed aliases in consumers; raw calls to UID0000XB should not be documented in consumer C++.

For sibling Deque exact pages:

- No sibling Deque exact pages were edited in this callback.
- `DequeDestroy`, `DequePushBack`, `DequeClear`, and `DequeDestroyOwnedEntries` metadata remain for separate target-specific reports if needed.

For `by-project-structure/proposed-source-tree.md`:

- Not edited; project-structure support was outside the accepted callback scope.

These recommended support changes have been applied for the accepted support-doc scope and verified by scoped validator commands `000000006650`, `000000006651`, and `000000006652`. `by-meta/client_containers.md` was checked and excluded with reason: no direct UID0000XB contradiction blocked this target implementation.

## Score And Metadata Recommendation

Recommended target metadata after implementation callback:

| Field | Current | Recommended | Rationale |
| --- | --- | --- | --- |
| `COMPLETION` | `85` | `89` | Exact range, current MCP evidence, source-category correction, no-code proof, comparator evidence, and support-doc route are complete enough for non-emitting disposition. |
| `CONFIDENCE` | `90` | `92` | Strong MCP/string/comparator evidence; below final-audit range because broader Deque family and source-facing typedef/member names remain unresolved. |
| `CANONICAL_OWNER` | `00003P` | `00003P` with caveat | Matches accepted UID0001FC transitional pattern; not final source ownership. |
| `RECONSTRUCTABLE` | `TRUE` | `FALSE` | Target is standard-library/generated support, not product source to hand-port. |
| `EMITTER_UIDS` | `00003P` | blank | No generated C++ should be emitted for this target. |
| `RECONSTRUCTION_CPP` | blank | blank | Blank is intentional no-code proof, not an unresolved missing implementation. |

Score blockers that remain:

- No exact source-facing typedef/member spelling for every consumer.
- No full Deque-family reclassification audit.
- No source/PDB symbol naming this helper.
- Sibling pages still mix custom/scaffold/STL evidence.
- Therefore no 95+ score is recommended.

## Score-Blocker Audit

Current blocker:

- UID0000XB is `RECONSTRUCTABLE:TRUE`, has `EMITTER_UIDS:00003P`, and has blank formal C++. Generated output therefore records an empty emitter marker in `auto-generated/NexusTK/util/Deque.cpp`.

Resolution:

- The marker was not filled with C++.
- The target was changed to non-reconstructable and the emitter was cleared after documenting the no-code proof.
- Validator refresh removed the UID0000XB empty marker from `auto-generated/NexusTK/util/Deque.cpp`.

What this does not resolve:

- It does not prove final source names for every caller's deque member.
- It does not settle all sibling Deque methods.
- It does not authorize manual generated/coverage edits.

## Open Questions With Attempted Resolution

| Question | Attempted resolution | Status |
| --- | --- | --- |
| Is `Deque::EnsureCapacity` a real original NexusTK method? | Checked current MCP, generated output, target docs, support docs, B013/B015/B007 reports, CandidateString comparator, and `deque<T> too long` path. Evidence favors standard-library support. | Resolved enough for no-code reclassification. |
| Should UID0000XB be merged into the following support island at `0x0043e250`? | MCP boundary and xref checks show padding and a distinct next function. | No merge; keep exact page. |
| Should all Deque siblings be reclassified now? | B013 explicitly deferred broad family reclassification; siblings have distinct behavior and one current first-draft body. | Defer separate family audit. |
| Should consumer source use custom `Deque` or `std::deque`? | Accepted FolderTree reports already use source-facing `std::deque<int>` while treating UID0000XB as low-level support. | Prefer typed `std::deque`/aliases per consumer. |
| Is `CANONICAL_OWNER:NONE` better than `00003P`? | UID0001FC accepted callback retained `00003P` as transitional grouping while clearing emitter. | Recommend same narrow-scope pattern. |

## Validator Results

Scoped validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed by-* file, exactly in the accepted implementation callback scope:

| File | Command | command_id | command_timestamp | Exit | ok | Result |
| --- | --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md` | `python .\tools\validator.py --mode file --file by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md --apply --queue-timeout 240` | `000000006649` | `2026-07-05T01:56:26-04:00` | `0` | `1` | Passed; reported `completion_update:1`, `confidence_update:1`, `autogen_registry_update:2`, `projected_stats_update:1`, `reference_index_add:2`, and `generated_refresh: deferred`. |
| `by-class/Deque.md` | `python .\tools\validator.py --mode file --file by-class/Deque.md --apply --queue-timeout 240` | `000000006650` | `2026-07-05T01:56:27-04:00` | `0` | `1` | Passed; reported `projected_stats_update:1` and `generated_refresh: deferred`. |
| `by-file/Deque.md` | `python .\tools\validator.py --mode file --file by-file/Deque.md --apply --queue-timeout 240` | `000000006651` | `2026-07-05T01:56:29-04:00` | `0` | `1` | Passed; reported `projected_stats_update:1` and `generated_refresh: deferred`. |
| `by-type/by-struct/DequeLayout.md` | `python .\tools\validator.py --mode file --file by-type/by-struct/DequeLayout.md --apply --queue-timeout 240` | `000000006652` | `2026-07-05T01:56:41-04:00` | `0` | `1` | Passed; reported `stats_row_update:1`, `projected_stats_update:1`, and `generated_refresh: deferred`. |

Generated refresh state observed after the callback:

- `auto-generated/NexusTK/util/Deque.cpp`: current header `validator-command-id: 000000006655`, `validator-refreshed-at: 2026-07-05T01:58:25-04:00`, `validator-refresh-source: foreground-generated-refresh`; no UID0000XB empty emitter marker remains.
- `auto-generated/-ag-memory-coverage.md`: current header `validator-command-id: 000000006655`, `validator-refreshed-at: 2026-07-05T01:58:25-04:00`, `validator-refresh-source: foreground-generated-refresh`; UID0000XB row is `not_reconstructable`, owner `00003P`, blank emitter, no generated output.
- `auto-generated/-ag-coverage-report-by-memory.md`: current header `validator-command-id: 000000006655`, `validator-refreshed-at: 2026-07-05T01:58:25-04:00`, `validator-refresh-source: foreground-generated-refresh`; UID0000XB row is `emits_code:false`, `not_reconstructable`, `89%`.
- `auto-generated/-ag-research-tracker.md`: current header `validator-command-id: 000000006656`, `validator-refreshed-at: 2026-07-05T01:59:39-04:00`, `validator-refresh-source: foreground-generated-refresh`; UID0000XB row is `89/92`, average `90.5`, reconstructable `false`, report count `0`.
- Read-only queue check `python .\tools\validator.py --queue-status` returned command `000000006653` at `2026-07-05T01:57:09-04:00` with worker running, zero queued jobs, zero processing jobs, zero queued generated refresh jobs, and zero processing generated refresh jobs.
- No generated files, manual coverage reports, validator state files, lifecycle/archive files, or report moves were manually edited.

No `execute_report`, dry-run/probing execute variants, registry lifecycle commands, report moves, or equivalent lifecycle/archive commands were run.

## Lease Results

- Initial target-only lease was acquired after support docs were still leased by B003, then released before the final edit batch.
- Final B004 edit leases were acquired for `by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md`, `by-class/Deque.md`, `by-file/Deque.md`, and `by-type/by-struct/DequeLayout.md` at `2026-07-05T05:51:48Z`, expiring at `2026-07-05T05:56:48Z`.
- Release was attempted after validation, but the leaser reported `Rejected[No active lease]` for each path because the leases had already expired.
- Current `tools/leaser/Agents/current_leases.md` was rechecked during this repair. It has no active B004 leases; only unrelated B002 leases are listed.

## IDA Rename / Type / Comment Recommendations

No IDA writes were made or requested.

If a future supervisor-owned IDA annotation pass is allowed, prefer a comment or non-final local label such as `std_deque_4byte_grow_map_support` over a product-owned `Deque::EnsureCapacity` name. Do not let an IDA label imply hand-authored NexusTK source ownership.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

B004 did not manually edit coverage or generated files. The validator-generated rows now carry this meaning:

```text
UID0000XB 0x0043e0b0-0x0043e241: non-reconstructable MSVC/Dinkumware std::deque 4-byte block-map growth support; current MCP session 19917133 confirms exact 0x191 boundary, padding, 16 direct xrefs, deque<T> too long overflow path, STL allocation/copy/zero/free behavior, and no target-local source C++.
```

Generated memory coverage has moved from `emits`/`00003P`/no-code to non-reconstructable with blank emitter after the approved callback and validator refresh.

## Follow-Up Actions

- Supervisor Gate 1 review passed and the implementation callback was applied.
- Supervisor Gate 2 review remains: verify the report ledger/checklist against the changed docs and validator results.
- Supervisor-only lifecycle remains: do not execute/archive this report until Gate 2 passes.
- Generated output has refreshed through the approved validator path, and `auto-generated/NexusTK/util/Deque.cpp` no longer contains the UID0000XB empty emitter marker.
- Consider a separate Deque-family audit for UID0000XA, UID000149, UID0001FD, UID0001IE, UID0001U2, and project-structure grouping language.

## Confidence

High for exact range, byte boundary, xrefs, callee set, and target behavior. High for non-emitting standard-library support classification because the evidence combines the `deque<T> too long` diagnostic, Dinkumware allocation convention, accepted comparator pages, accepted UID0001FC precedent, and consumer reports that source-face the container as `std::deque`.

Medium-high for retaining UID00003P as transitional owner because that is a documentation continuity decision, not final source ownership.

## Changed Files

- Updated `tools/leaser/Agents/Agent-B004/research/0000XB-DequeEnsureCapacity-source-quality.md`.
- Updated `by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md`.
- Updated `by-class/Deque.md`.
- Updated `by-file/Deque.md`.
- Updated `by-type/by-struct/DequeLayout.md`.

Checked but not edited:

- `by-meta/client_containers.md`: excluded with reason; search found no direct UID0000XB contradiction blocking the target implementation.

Validator-owned generated refresh was observed but not manually edited:

- `auto-generated/NexusTK/util/Deque.cpp`.
- `auto-generated/-ag-memory-coverage.md`.
- `auto-generated/-ag-coverage-report-by-memory.md`.
- `auto-generated/-ag-research-tracker.md`.

## Implementation Tracking Checklist

- [x] Read Agent-B004 `goal.md`, original Gate 1 research scope, and accepted implementation callback scope.
- [x] Used project-level `ntk-b-agent-workflow` instructions.
- [x] Read target, support, sibling, generated, current report, executed-report, and archive evidence.
- [x] Used current MCP session `19917133`; discarded stale zero-session incident evidence as historical only.
- [x] Confirmed MCP health and current tool schema.
- [x] Confirmed target range, padding, next function, xrefs, callees, bytes, decompile, disassembly, and string evidence.
- [x] Reanalyzed heuristic/source-quality classification.
- [x] Audited score/generator blocker.
- [x] Provided exact no-code proof instead of a formal first-draft C++ body.
- [x] Recommended target and support doc changes.
- [x] Added positive and negative evidence.
- [x] Added implementation callback checklist.
- [x] Supervisor Gate 1 review passed; callback authorized for UID0000XB.
- [x] C-0000XB-01 applied: exact range, `sub_43E0B0`, size `0x191`, and padding evidence incorporated into target/layout docs and verified by validators `000000006649`/`000000006652`.
- [x] C-0000XB-02 applied: no xrefs to `0x0043e241`, separate next function `0x0043e250`, and range-merge rejection incorporated into the target doc and verified by validator `000000006649`.
- [x] C-0000XB-03 applied: 4-byte standard deque map-growth behavior incorporated into target/layout docs and verified by validators `000000006649`/`000000006652`.
- [x] C-0000XB-04 applied: `deque<T> too long` overflow route incorporated into target/support docs and verified by validators `000000006649` through `000000006652`.
- [x] C-0000XB-05 applied: comparator helper/callee-set evidence incorporated into target/support docs and verified by validators `000000006649` through `000000006652`.
- [x] C-0000XB-06 applied: broad caller fan-in and rejection of feature ownership/custom helper ownership incorporated into target/class/file docs and verified by validators `000000006649` through `000000006651`.
- [x] C-0000XB-07 applied: target metadata set to `COMPLETION:89`, `CONFIDENCE:92`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++; validator `000000006649` reported metadata and autogen-registry updates.
- [x] C-0000XB-08 applied: `CANONICAL_OWNER:00003P` retained only as a transitional grouping with caveats in target/support docs and verified by validators `000000006649` through `000000006652`.
- [x] C-0000XB-09 applied/excluded-with-reason: no sibling Deque exact pages or project-structure docs were mass-reclassified; `by-meta/client_containers.md` was checked and not edited because no direct contradiction was found.
- [x] Target doc implementation callback complete: metadata, no-code proof, MCP evidence, historicalized source-body assumptions, rejected alternatives, and blank formal C++ are present.
- [x] Support doc implementation callback complete: `by-class/Deque.md`, `by-file/Deque.md`, and `by-type/by-struct/DequeLayout.md` include UID0000XB caveats and no custom emitter/formal C++ disposition.
- [x] Scoped validators run from `source-3/project-documentation`: commands `000000006649`, `000000006650`, `000000006651`, and `000000006652`, all exit `0`, `ok:1`.
- [x] Generated output refreshed through validator-owned paths; current generated headers are `000000006655`/`000000006656`, and `auto-generated/NexusTK/util/Deque.cpp` no longer contains a UID0000XB empty marker.
- [x] Lease cleanup verified: no active B004 leases remain in `tools/leaser/Agents/current_leases.md`.
- [x] No `execute_report`, dry-run execute variant, registry lifecycle command, report move, generated/coverage manual edit, validator-state edit, or lifecycle/archive edit was run.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000006666","destination_path":"executed-b-agent-research/B004/0000XB-DequeEnsureCapacity-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0000XB-DequeEnsureCapacity-source-quality.md","timestamp":"2026-07-05T02:09:28-04:00","uid":"0000XB"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
