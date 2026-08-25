** TARGET-REPORT-UID:0001FC **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 0001FC DequeElementAddressHelper Source-Quality Report


## Finalized Report / Current Recommendation

UID0001FC should not receive a hand-written NexusTK `Deque::ElementAddress` formal C++ body. The accepted recommendation has now been implemented for the scoped callback: the target was reclassified from a NexusTK-authored `util/Deque.cpp` helper to MSVC/Dinkumware `std::deque` template/support code generated from source declarations such as `std::deque<int>::operator[]` / `_Subscript`.

The implemented disposition is:

- Target `by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md`: changed to `COMPLETION:89`, `CONFIDENCE:92`, kept `CANONICAL_OWNER:00003P` only as a transitional Deque documentation grouping, set `RECONSTRUCTABLE:FALSE`, cleared `EMITTER_UIDS`, and kept formal C++ blank.
- The old empty-emitter wording was replaced with an explicit no-code proof: the body is a standard-library deque element-address helper, not a NexusTK source-authored function. Rebuilding should come from the compiler/STL implementation reached through source uses like [UID:0001FA] `PrimeNumberGenerator::GetPrimeAt` using `m_primes[index]`, not from a bespoke `Deque.cpp` helper.
- Support docs preserve the current helper inventory but now caveat [UID:00003P] `Deque`, [UID:0000IR] `Deque`, and [UID:0001U2] `DequeLayout` as transitional/scaffolded around this `std::deque` evidence.

By-* implementation edits have been applied and scoped validators passed. The artifact is awaiting supervisor Gate 2 verification/execution.

## Supporting Research

This started as the report-only Gate 1 artifact for UID0001FC and now records the completed implementation callback. It uses current local docs, generated outputs as leads, executed B-report leads, and mandatory IDA MCP evidence from active session `eb7ce28b`.

Current MCP availability was confirmed after supervisor release:

- `idb_list`: one active adopted worker session `eb7ce28b` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- `server_health`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- `tools/list`: schema-current tools included `lookup_funcs`, `xrefs_to`, `callees`, `get_bytes`, `decompile`, `disasm`, and `server_health`; this MCP build requires `database` on every tool call.

The older docs already knew the byte behavior but stopped at "source-grade helper/operator name and `+0x00` chain unresolved." The new source-quality result is that the `+0x00` chain is not a project-specific mystery field; it matches the standard `std::deque` proxy slot, and the remaining body is the ordinary four-entry block address calculation used by Dinkumware/MSVC deque internals for 4-byte elements.

## Target

- UID: `0001FC`
- Target path: `by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md`
- Current title: `0x0054c0c0-0x0054c110 DequeElementAddressHelper`
- Current metadata at assignment: `COMPLETION:85`, `CONFIDENCE:89`, `CANONICAL_OWNER:00003P`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003P`, blank formal C++.
- Generated state: the assignment/pre-callback generated lead `auto-generated/NexusTK/util/Deque.cpp` contained a UID0001FC empty emitter marker. Current post-callback generated output refreshed with `validator-command-id: 000000006004`, `validator-refreshed-at: 2026-07-04T03:19:33-04:00`, no longer contains UID0001FC because the target is now non-reconstructable with blank `EMITTER_UIDS`.
- Immediate support pages used: `by-class/Deque.md`, `by-file/Deque.md`, `by-type/by-struct/DequeLayout.md`, and `by-memory/0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt.md`.

The target is a real modeled function at `0x0054c0c0` with size `0x50`; the report does not dispute the boundary or behavior. The issue is source category and emission route.

## Current Target State

The target now says this is an exact MSVC/Dinkumware `std::deque` 4-byte element-address helper / `_Subscript`-style support body and no longer emits custom source. [UID:00003P] `Deque` remains only as a transitional documentation grouping.

Current written facts preserved in the target:

- Exact half-open range is `0x0054c0c0-0x0054c110`.
- Preceding bytes `0x0054c0bc-0x0054c0c0` are four `0xcc` bytes.
- IDA models `sub_54C0C0` as size `0x50`, ending with `retn 4`.
- Next modeled function starts at `0x0054c110`, size `0x4a`, and is outside UID0001FC.
- The helper has no modeled callees.
- `xrefs_to 0x0054c0c0` has one raw code xref at `0x0054bce1`, inside the raw `PrimeNumberGenerator::GetPrimeAt` body.
- The body computes `blockMap[((frontIndex + index) >> 2) & (blockCount - 1)] + 4 * ((frontIndex + index) & 3)`.

Facts historicalized or narrowed during callback:

- "NexusTK/util/Deque.cpp" and `Deque::ElementAddress` are now treated as reconstruction scaffolding names for this exact target, not final original-source ownership.
- The `+0x00` field is now caveated as proxy-like standard deque support storage in [UID:0001U2], based on constructor evidence showing an 8-byte allocation whose first word points back to the deque container.
- Formal C++ remains blank because the source is standard-library/generated template implementation rather than a NexusTK-authored function to hand-port.

## Heuristic / Inference Reanalysis And Validation

The old blocker was framed as "exact helper/operator name and `+0x00` pointer-chain semantics unresolved." The MCP-backed reanalysis resolves both far enough to change the disposition.

Validation points:

- The field layout documented as `+0x00/+0x04/+0x08/+0x0c/+0x10` matches MSVC/Dinkumware `std::deque` internals: proxy pointer, block map, map size, logical offset, and size.
- The block model is a standard-library deque block model for 4-byte elements: each block holds four entries because the block byte size is `0x10`; the element address is selected with `(logicalIndex >> 2) & (blockCount - 1)` and `logicalIndex & 3`.
- The `PrimeNumberGenerator` constructor at `0x0054bcf0` initializes the embedded deque subobject at `this+0x08`, zeroes five 4-byte fields, allocates an 8-byte proxy, stores it in field `+0x00`, clears proxy words, and writes the deque-subobject pointer back through the proxy. This is not a NexusTK-specific custom container signature; it is the expected checked-iterator/proxy setup shape for MSVC STL containers.
- The UID0001FA accepted source already expresses the call site as `m_primes[index]`. That source expression is more plausible than a project-local `m_primes.ElementAddress(index)` helper call, and it naturally accounts for an emitted `std::deque<int>` internal address helper.
- The helper has a single raw caller and no named source route of its own. That is consistent with a template/support instantiation retained because `std::deque<int>::operator[]` is used, not with a standalone game utility function.
- Writing a new `Deque::ElementAddress` body would either omit the observed proxy path or reproduce it in decompiler-shaped C++. Neither is source-quality: direct field C++ does not explain the emitted proxy reads, while explicit multi-level `reinterpret_cast` proxy chasing would be artificial source scaffolding.

Inference confidence is high because independent evidence lines converge: layout offsets, constructor proxy initialization, four-entry block arithmetic, call-site source expression, and broad Deque helper family behavior all match `std::deque` support better than a NexusTK-authored utility file.

## Evidence Standards Used

- IDA MCP is treated as ground truth for addresses, function boundaries, xrefs, bytes, decompile/disassembly facts, and callee state.
- Current by-* docs are treated as current project documentation and implementation leads, not proof of final original-source ownership when MCP contradicts the source category.
- Generated C++ and generated coverage are treated as lead material only. The pre-callback `auto-generated/NexusTK/util/Deque.cpp` UID0001FC empty emitter marker proved the original coverage gap; the current post-callback generated output no longer contains UID0001FC after validator command `000000006004`, which matches the accepted non-reconstructable/blank-emitter disposition.
- Executed B reports are treated as accepted leads for adjacent targets, then rechecked against current MCP and current docs.
- Source-shape inference uses late-1990s/2000s MSVC C++ expectations and avoids names such as `sub_54C0C0` in recommended documentation.
- C++ is recommended only when the source body is NexusTK-authored or otherwise appropriate for formal target insertion. For standard-library/template-generated internals, the correct report output is a target-specific no-code proof.

## Evidence Checked

- Read current target: `by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md`.
- Read support docs: `by-class/Deque.md`, `by-file/Deque.md`, `by-type/by-struct/DequeLayout.md`, `by-memory/0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt.md`, and sibling first-draft source page `by-memory/0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries.md`.
- Read generated lead: pre-callback `auto-generated/NexusTK/util/Deque.cpp`, which had UID0001FC as an empty emitter marker; post-callback generated output refreshed at `2026-07-04T03:19:33-04:00` with command id `000000006004` and no longer contains UID0001FC.
- Checked generated/research state: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `project-level/-auto-completion-stats.md` rows for UID0001FC.
- Checked unresolved aliases: `project-level/-unresolved.md` entries for `sub_54C0C0`, `sub_54C110`, and `this+0x0c`.
- Searched old/current reports and notes with terms: `0001FC`, `0x0054c0c0`, `0x0054c110`, `DequeElementAddressHelper`, `ElementAddress`, `GetAtAddress`, and `sub_54C0C0`.
- Opened matching executed reports: `executed-b-agent-research/B005/0001FA-PrimeNumberGeneratorGetPrimeAt-source-quality.md` and `executed-b-agent-research/B002/0001IE-DequeDestroyOwnedEntries-source-quality.md`.
- MCP session `eb7ce28b` exact-address probes:
  - `lookup_funcs` for `0x0054c0bc`, `0x0054c0c0`, `0x0054c10f`, `0x0054c110`, `0x0054c160`, `0x0054bce1`, and `0x0054bcc0`.
  - `xrefs_to` for `0x0054c0c0`, `0x0054c110`, and `0x0054bcc0` with `limit=20`.
  - `callees` for `0x0054c0c0` with `limit=20`.
  - `get_bytes` for `0x0054c0bc` size `4`, `0x0054c0c0` size `80`, `0x0054c110` size `8`, and `0x0054bce0` size `12`.
  - `decompile` and bounded `disasm` for `0x0054c0c0`.
  - bounded `disasm` for raw caller window starting at `0x0054bcc0`.
  - bounded constructor context probes at `0x0054bcf0`, including `lookup_funcs`, `disasm` first 70 instructions, and `decompile`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0001FC-01 | UID0001FC is exactly `0x0054c0c0-0x0054c110`, an 80-byte modeled function ending `retn 4`, with four `0xcc` bytes before and separate function `0x0054c110` after. | confirmed | MCP `lookup_funcs`, `get_bytes`, `disasm`; current target page already had these facts and now refreshes them under session `eb7ce28b`. | Target `Range And Boundaries` / `Current MCP Evidence` | incorporate | applied |
| C-0001FC-02 | The helper has one raw code xref at `0x0054bce1`, no modeled direct function caller for that raw site, and no callees. | confirmed | MCP `xrefs_to 0x0054c0c0` reports raw code xref at `0x54bce1`; `callees 0x0054c0c0` empty; UID0001FA raw body documents the call. | Target `Current MCP Evidence`; UID0001FA left unchanged because current text already preserves consumer source route | incorporate | applied |
| C-0001FC-03 | The body computes the address of a four-byte deque element using front offset, block map, power-of-two block count mask, and four-entry block index. | confirmed | MCP decompile/disasm and target body bytes: `shr ecx,2`, `and ecx, blockCount-1`, `and esi,3`, `mov eax,[blockMap+ecx*4]`, `lea eax,[eax+esi*4]`. | Target `Behavior` and `Raw Code Evidence` | incorporate | applied |
| C-0001FC-04 | The `+0x00` field is best explained as a standard deque proxy/checking allocation, not an unresolved project-specific auxiliary field. | strong | Constructor MCP at `0x0054bcf0`: embedded deque at `this+0x08`, zeroed fields, `operator new(8)`, store to deque `+0x00`, clear proxy words, write deque pointer back through proxy. This matches MSVC STL deque proxy shape. | Target `Constructor Proxy Context`; support `DequeLayout` field description | incorporate | applied |
| C-0001FC-05 | The likely source category is MSVC/Dinkumware `std::deque` template/support code, not a NexusTK-authored `util/Deque.cpp` helper. | strong | Layout matches `std::deque` internals, block size matches 4-byte element deque, UID0001FA source uses `m_primes[index]`, broad helper family resembles STL container methods, and no independent NexusTK helper route/symbol exists. | Target `Source Category And Ownership Decision`; support `Deque` class/file docs | incorporate | applied |
| C-0001FC-06 | Do not insert a target-local formal C++ body for `Deque::ElementAddress`; doing so would invent a game-owned helper or encode decompiler-shaped proxy chasing. | strong | Direct field C++ would omit observed proxy resolution; explicit proxy-chain C++ would be artificial; source call site should rely on standard `std::deque` operator implementation. | Target formal C++ block and `Reconstruction Notes` | incorporate | applied |
| C-0001FC-07 | Target metadata should move to `89/92`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++, while keeping `CANONICAL_OWNER:00003P` only as a transitional documentation grouping unless broader Deque docs are reworked. | medium-high | Source-category resolution improves confidence; broader Deque parent still needs a separate coordinated reclassification because current docs and generated output route multiple sibling helper pages through `Deque`. | Target metadata; support `Deque` parent caveat | incorporate | applied |
| C-0001FC-08 | Support docs should preserve `PrimeNumberGenerator::GetPrimeAt` as NexusTK source using `m_primes[index]`; that source expression is the real source-level reachability for this generated helper. | strong | Executed B005 report and current UID0001FA formal C++ already use `return m_primes[index];`; MCP raw call at `0x0054bce1` is the compiled route. | UID0001FA, `by-class/Deque.md`, `by-file/Deque.md` | already-present | already-present |

## Positive Evidence Summary

- MCP session `eb7ce28b` confirms the exact target function at `0x0054c0c0`, size `0x50`, no callees, raw xref only at `0x0054bce1`, and exact bytes matching current docs.
- The helper arithmetic exactly matches deque block address calculation for four-byte elements and four entries per block.
- Constructor context at `0x0054bcf0` initializes an embedded container at `this+0x08`, allocates an 8-byte proxy into field `+0x00`, and writes the container pointer back through that proxy.
- The field sequence `proxy`, `map`, `map size`, `offset`, `size` and the block arithmetic are a strong match for MSVC/Dinkumware `std::deque`.
- The known source-level consumer already reconstructs as `m_primes[index]`, which is the natural source expression for a `std::deque<int>` element access.
- Pre-callback generated output had an empty emitter marker for UID0001FC, proving the original coverage gap was real; current generated output no longer has that marker after the target became non-reconstructable with blank emitter.

## Negative Evidence Summary

- No MCP evidence names `Deque::ElementAddress`, `GetAtAddress`, or a project-local utility helper.
- The only xref is from a raw retained accessor body; there is no broad NexusTK call fanout to a named helper entry.
- A direct hand-written `Deque::ElementAddress` implementation using `m_blockMap`/`m_blockCount`/`m_frontIndex` would not account for the observed `+0x00` proxy resolution path.
- A hand-written implementation that explicitly follows the observed multi-level proxy path would be decompiler-shaped and not plausible original NexusTK source.
- Physical adjacency to `PrimeNumberGenerator` is not ownership evidence; the body is generic container/STL support.
- Current `util/Deque.cpp` generated output is a documentation route, not evidence of an original NexusTK `Deque.cpp`.

## Ranked Ownership Analysis

| Rank | Candidate | Evidence For | Evidence Against | Decision |
| ---: | --- | --- | --- | --- |
| 1 | MSVC/Dinkumware `std::deque<int>` support / template instantiation | Exact layout/proxy/block behavior; source caller is `m_primes[index]`; constructor proxy allocation; no named NexusTK helper route. | Current docs model this as `Deque` utility class; broader support pages need reclassification before all generated output changes cleanly. | Preferred source category. Target should be non-emitting/no formal C++. |
| 2 | Transitional [UID:00003P] `Deque` documentation grouping | Current target, class, file, and layout pages all route here; useful grouping for sibling deque internals. | Name is project-scaffolded and obscures STL/proxy evidence; generated `util/Deque.cpp` hand-emission is likely wrong for this target. | Keep only as transitional canonical grouping if supervisor wants minimal callback scope. |
| 3 | [UID:0000MQ]/[UID:0000AT] `PrimeNumberGenerator` | Only known raw call originates in the prime accessor; embedded deque stores primes. | Body is generic deque block math; no prime-specific state except caller; accepted UID0001FA report already rejected folding helper into PrimeNumberGenerator. | Rejected as owner; source use remains consumer evidence. |
| 4 | Hand-authored NexusTK `util/Deque.cpp` helper | Existing generated route and older docs name this. | Proxy layout and STL call-site expression point to standard-library implementation; no original file/name proof; first-draft helper would be invented. | Rejected for formal C++ emission. |
| 5 | No-owner unknown raw helper | Single raw xref and generated name could suggest uncertainty. | Behavior, source category, layout, and caller expression are now understood. | Rejected; not unknown, just non-Nexus source/generated support. |

## Source Placement

Do not place UID0001FC in a hand-authored `NexusTK/util/Deque.cpp` body. The best source placement is standard-library/template support generated from source declarations that use `std::deque`, with the direct source-facing caller in UID0001FA represented as `m_primes[index]`.

For documentation continuity, [UID:00003P] `Deque` can remain a temporary grouping page for current Deque-family exact pages, but its status should be revised to say it likely documents MSVC `std::deque` internals/template instantiations rather than an original NexusTK utility module. That parent reclassification is broader than this exact target and should be done carefully because sibling pages UID0000XA, UID0000XB, UID000149, UID0001FD, UID0001IE, and UID0001U2 currently route through the same scaffold.

## First-Draft C++ Recommendation

No formal C++ body should be inserted for UID0001FC.

Target-specific no-code proof:

- The target is compiled support code for `std::deque` element access, not a NexusTK-authored helper function.
- The source-level operation is already represented at the consumer as `m_primes[index]`; the compiler/STL provides the helper body.
- A direct field implementation would be behavior-incomplete with respect to the observed proxy path.
- An explicit proxy-chain implementation would be reverse-engineering scaffolding, not plausible original source.
- The formal `RECONSTRUCTION_CPP CODE` block should therefore remain blank when `RECONSTRUCTABLE` is set to `FALSE` and `EMITTER_UIDS` is cleared.

Do not paste sentinel/header lines into the C++ block. Do not add namespace-local helpers or a new `Deque::ElementAddress` abstraction.

## Final Recommendation

Apply the report as a source-category correction, not as a custom C++ insertion. UID0001FC should be documented as an exact, understood standard-library deque element-address helper with no NexusTK source-emitter body.

The accepted callback updated only target/support docs directly; generated files were refreshed by validator, not edited manually:

- Target becomes `89/92`, non-reconstructable, blank emitter, blank formal C++, with MCP evidence and no-code proof.
- Deque class/file/layout support pages receive a source-category caveat that the current Deque grouping appears to be MSVC `std::deque` internals/template support, not final proof of an original `NexusTK/util/Deque.cpp`.
- UID0001FA remains PrimeNumberGenerator-owned with source expression `m_primes[index]` and should not be changed except if a stale note still implies the callee is game-owned source.

## Recommended Target Doc Changes

For `by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md`:

- Set `COMPLETION:89`.
- Set `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:00003P` only as a transitional documentation grouping unless the callback also performs broader Deque parent reclassification.
- Set `RECONSTRUCTABLE:FALSE`.
- Clear `EMITTER_UIDS`.
- Keep `EMITTER_POSITION_OPTIONAL` blank.
- Keep formal `RECONSTRUCTION_CPP CODE` multiline block blank.
- Update summary/status to say the range is an exact MSVC/Dinkumware `std::deque` 4-byte element address helper / `_Subscript`-style instantiation, not NexusTK-authored source.
- Preserve exact range, padding, function size, raw xref, no-callee, body bytes, and formula evidence.
- Add current MCP session `eb7ce28b` evidence, including active IDB health, `lookup_funcs`, `xrefs_to`, `callees`, `get_bytes`, `decompile`, `disasm`, and constructor proxy context.
- Historicalize old `Deque::ElementAddress` / `GetAtAddress` names as descriptive scaffold names only.
- Add rejected alternatives: PrimeNumberGenerator ownership, hand-authored `util/Deque.cpp`, direct field C++ body, decompiler-shaped proxy-chain body, and unknown/no-owner.

## Recommended Support Doc Changes

For `by-class/Deque.md`:

- Add a source-category caveat that the documented `Deque` layout and helper family match MSVC/Dinkumware `std::deque` internals, including proxy at `+0x00`, map at `+0x04`, map size at `+0x08`, offset at `+0x0c`, and size/count at `+0x10`.
- Change UID0001FC method row/status from "currently not emitted in active class_Deque.cpp" to "non-emitting STL/template-generated address helper; no hand-authored target C++."
- Do not erase existing useful helper inventory; mark the original class/file spelling as inferred scaffold pending broader STL reclassification.

For `by-file/Deque.md`:

- Replace or qualify `util/Deque.cpp` as likely reconstruction scaffold for standard-library deque internals rather than direct evidence of an original NexusTK source module.
- Mark UID0001FC as no custom emitter/formal C++; the generated helper should arise from standard `std::deque` use.
- Preserve the warning that feature modules and PrimeNumberGenerator do not own the helper.

For `by-type/by-struct/DequeLayout.md`:

- Update `+0x00` from broad `auxiliaryStorageOrAllocatorSlot` wording to proxy-like STL deque support storage, with constructor evidence from `0x0054bcf0`.
- Keep exact field offsets and storage model.
- Mark layout declaration C++ as still blank because standard library declarations should come from STL headers, not project-authored layout source.

For `by-memory/0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt.md`:

- No required change if current text already says `m_primes[index]` and keeps UID0001FC Deque-owned/generic. If touched for consistency, narrow "Deque-owned generic support" to "standard deque/generated helper support" without changing UID0001FA owner/emitter/C++.

## Score And Metadata Recommendation

Recommended target metadata after callback:

```text
COMPLETION:89
CONFIDENCE:92
CANONICAL_OWNER:00003P
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE:[[[]]]
```

Rationale:

- Completion rises from `85` to `89` because the previous source-quality blocker is now resolved into a source-category decision: standard-library deque support with exact byte/range/xref/formula evidence and constructor proxy confirmation.
- Confidence rises from `89` to `92` because MCP confirms the behavior and the STL interpretation explains the previously unresolved `+0x00` chain. It remains below `95` because broader sibling Deque pages still need a coordinated reclassification audit.
- `RECONSTRUCTABLE:FALSE` and blank `EMITTER_UIDS` are recommended because UID0001FC should not hand-emit NexusTK source. It is generated by the compiler/STL from source declarations.
- `CANONICAL_OWNER:00003P` is retained only to avoid a one-target orphan during callback. A later broader callback may replace the `Deque` scaffold with a more explicit STL/template support owner or ignored/runtime handling if by-structure and supervisor agree.

## Open Questions With Attempted Resolution

- Exact original symbol name: likely an internal `std::deque<int>` `_Subscript` / `operator[]` helper rather than `Deque::ElementAddress`. No recovered symbol proves the spelling, but source ownership does not require naming this as NexusTK code.
- Whether all current `Deque` helper pages should become STL/runtime-generated rather than reconstructable utility code: strong evidence points yes, but this assignment is UID0001FC. The report recommends support caveats and a follow-up broader Deque-family audit rather than silently changing sibling dispositions during report-only work.
- Whether `CANONICAL_OWNER:00003P` should eventually be cleared or replaced: unresolved at broader system level. For this exact callback, keeping it as a transitional grouping while clearing emitter/reconstructability is the least disruptive accurate fix.
- Whether UID0001IE's existing formal `Deque::DestroyOwnedEntries` should be revisited: yes as follow-up, because the same field layout and source category likely affect it. This report does not invalidate that executed report by itself; it flags the broader source-category conflict for supervisor-directed audit.

## Validator Results

Implementation callback validators were run from `source-3/project-documentation` for each changed by-* file:

| File | Command | command_id | command_timestamp | Exit | ok | Notes |
| --- | --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md` | `python .\tools\validator.py --mode file --file by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md --apply --queue-timeout 240` | `000000006001` | `2026-07-04T03:19:18-04:00` | 0 | 1 | Updated completion/confidence, registry reconstructable `true -> false`, emitter `00003P -> blank`, UID links, and projected stats; generated refresh initially deferred. |
| `by-class/Deque.md` | `python .\tools\validator.py --mode file --file by-class/Deque.md --apply --queue-timeout 240` | `000000006002` | `2026-07-04T03:19:20-04:00` | 0 | 1 | Projected stats updated; generated refresh deferred. |
| `by-file/Deque.md` | `python .\tools\validator.py --mode file --file by-file/Deque.md --apply --queue-timeout 240` | `000000006003` | `2026-07-04T03:19:22-04:00` | 0 | 1 | Projected stats updated; generated refresh deferred. |
| `by-type/by-struct/DequeLayout.md` | `python .\tools\validator.py --mode file --file by-type/by-struct/DequeLayout.md --apply --queue-timeout 240` | `000000006004` | `2026-07-04T03:19:33-04:00` | 0 | 1 | Projected stats updated; generated refresh deferred. |

Warnings/side effects: no target-specific validator failures. The first validator reported `stats_rescore_recommended` because UID0001FC dropped from generated reconstructable lists; no manual stats/coverage edit was made. Generated `auto-generated/NexusTK/util/Deque.cpp` later refreshed with `validator-command-id: 000000006004`, `validator-refreshed-at: 2026-07-04T03:19:33-04:00`, and `validator-refresh-source: deferred-generated-refresh`.

No `execute_report`, dry-run execute, archive, lifecycle, generated manual edit, coverage edit, or validator-state manual edit was run.

## Changed Files

Manual edits during implementation callback:

- `by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md`
- `by-class/Deque.md`
- `by-file/Deque.md`
- `by-type/by-struct/DequeLayout.md`
- `tools/leaser/Agents/Agent-B013/research/0001FC-DequeElementAddressHelper-source-quality.md`

Not manually edited:

- `by-memory/0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt.md` was inspected and left unchanged because it already preserves `m_primes[index]` and does not fold UID0001FC into PrimeNumberGenerator.
- No `-coverage-report.md` files.
- No generated files under `auto-generated/`.
- No report lifecycle/archive files.
- No supervisor ledgers.

Validator/generated side effects observed:

- Scoped validators updated validator-owned/projected stats and generated output as reported in `Validator Results`.
- `auto-generated/NexusTK/util/Deque.cpp` refreshed through the validator background path with command id `000000006004`; no manual generated edit was made.

## Implementation Tracking Checklist

Callback implementation checklist:

- [x] Target metadata: updated `by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md` to `COMPLETION:89`, `CONFIDENCE:92`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++, with `CANONICAL_OWNER:00003P` retained as transitional grouping.
- [x] Target evidence: incorporated MCP session `eb7ce28b` facts for active session health, function size/range, padding, next function, raw xref at `0x0054bce1`, no callees, exact bytes, decompile/disasm formula, and constructor proxy setup at `0x0054bcf0`.
- [x] Target source-quality decision: replaced "blank final C++ pending helper/operator name and `+0x00` semantics" with "blank final C++ because this is standard-library deque generated support, not NexusTK-authored source."
- [x] Target names: historicalized `Deque::ElementAddress` / `GetAtAddress` as inferred/descriptive scaffolds; no formal source name was added.
- [x] Target rejected alternatives: documented rejection of PrimeNumberGenerator ownership, NexusTK `util/Deque.cpp` hand-emitter, direct field C++ body, decompiler-shaped proxy-chain C++ body, and unknown/no-owner classification.
- [x] Support `by-class/Deque.md`: added the STL/deque proxy source-category caveat and updated UID0001FC row/status to non-emitting generated support while preserving the broader helper inventory.
- [x] Support `by-file/Deque.md`: qualified `util/Deque.cpp` as reconstruction scaffold pending broader Deque audit and marked UID0001FC no custom emitter.
- [x] Support `by-type/by-struct/DequeLayout.md`: updated `+0x00` caveat to proxy-like standard deque storage with constructor evidence; preserved offsets and storage formula.
- [x] Support UID0001FA: inspected and left unchanged as already-present. It already uses `m_primes[index]` in formal C++ and does not fold UID0001FC into PrimeNumberGenerator.
- [x] Ran scoped validators after callback for every changed by-* doc, using the required `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240` pattern. All four exited 0 with `ok:1`.
- [x] Reported generated refresh effects after validators. `auto-generated/NexusTK/util/Deque.cpp` refreshed through validator with command id `000000006004`; no manual generated, coverage, project-level, or validator-state edit was made.
- [x] Updated this report's Claim And Incorporation Ledger row-by-row to `applied` or `already-present`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000006022","destination_path":"executed-b-agent-research/B013/0001FC-DequeElementAddressHelper-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/0001FC-DequeElementAddressHelper-source-quality.md","timestamp":"2026-07-04T03:25:20-04:00","uid":"0001FC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
