** TARGET-REPORT-UID:00012F **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00012F _DATFileMgr Raw Destructor Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: raise [UID:00012F] `by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md` from `82/88` to `86/90`.
- Final disposition: keep `CANONICAL_OWNER:0000IO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000IO`, blank `EMITTER_POSITION_OPTIONAL`, and blank final C++.
- Required action: update the target page and support docs with the rechecked raw function/no-route/destructor-split evidence below; update the supervisor-owned `by-memory/-coverage-report.md` row with the exact replacement row in this report.
- Confidence: high for range, byte behavior, ownership, source placement, and non-deleting destructor interpretation; medium-high for original private class/helper spelling and final member names.

## Target

- Target UID: `00012F`
- Target path: `by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md`
- Assignment: `B002-goal2-datfilemgr-raw-destructor-source-quality-00012F-20260616`
- Current score/state: `82/88`, owner/emitter [UID:0000IO] `DATFileMgr`, reconstructable, blank C++.
- Current report-only output path: `tools/leaser/Agents/Agent-B002/research/00012F-datfilemgr-raw-destructor-source-quality.md`

## Executive Recommendation

The target is a real source-authored `_DATFileMgr` ordinary/non-deleting destructor body that IDA failed to model as a function. It should not be ignored, reclassified as compiler filler, split, or merged into the scalar deleting destructor page. It should remain routed through [UID:0000IO] `DATFileMgr` because the public wrapper, private `_DATFileMgr`, resolver/hash table, archive-container vector, and vtable data all belong in `NexusTK/archive/DATFileMgr.cpp`.

The strongest final source shape is:

- Source-authored declaration/body: `_DATFileMgr::~_DATFileMgr()` or an equivalent private cleanup body used by the compiler-generated deleting destructor.
- Compiler-generated/source-declared binary consequence: `_DATFileMgr::DeletingDestructor` at `0x0049d3d0-0x0049d488` remains the vtable slot target at `0x006189cc`.
- Final generated C++ for [UID:00012F]: keep blank for now. The item now clears the current minimum score/emitter gate after the recommended raise, but final code would duplicate or conflict with the modeled deleting-destructor source shape until the class declaration, destructor split, resolver member type, and field names are finalized.

## Supervisor Active Recheck

The supervisor requested report-only reanalysis beyond the current no-function/no-direct-xref notes. I did not edit `by-*` docs, generated reports, source files, IDA DB, generated source, or `by-memory/-coverage-report.md`.

This target does not require split repair:

- The exact half-open range is still `0x0049c750-0x0049c7f6`.
- `0x0049c750-0x0049c7f0` is the normal destructor body through `retn`.
- `0x0049c7f1-0x0049c7f6` is the cold invalid-parameter call tail reached from the large-allocation guard at `0x0049c7bf`.
- `0x0049c7f6-0x0049c800` is `align 10h` / `0xcc` padding before `_DATFileMgr::LoadDATFileIndex`.

## Inference Research Guidance Check

I treated existing docs and generated `simroot_v2` output as leads, not authority. IDA MCP function/xref/disassembly evidence and raw PE scans were the deciding evidence for boundaries, reachability, and source-authored/destructor classification. Generated source was useful for candidate member names but remains below final-output quality because it uses synthetic layout overlays, modern/scaffolded idioms, and an incomplete destructor/deleting-destructor split.

## Heuristic / Inference Reanalysis And Validation

### Raw/non-function liveness

Best inference: live source-authored ordinary destructor body retained in `.text`, not data, padding, or an accidental duplicate.

Evidence checked:

- IDA MCP `lookup_funcs` reports `sub_49C720` at `0x0049c720` size `0x2b`, no function at `0x0049c750`, no function at `0x0049c7f6`, and `sub_49C800` at `0x0049c800` size `0x2c4`.
- IDA MCP `insn_query` over `0x0049c740-0x0049c800` decodes a full instruction stream at `0x0049c750`: prologue, vtable write, vector loop, heap free, resolver cleanup call, epilogue, `retn`, cold invalid-parameter call, then alignment.
- Raw PE bytes map `0x0049c750` to RVA `0x0009c750`, file offset `0x0009bb50` in `.text`; the target is executable bytes, not `.rdata` or gap data.
- The same scan maps `0x0049c7f6` to file offset `0x0009bbf6`, followed by ten `0xcc` bytes before `0x0049c800`.

Rejected alternatives:

- Padding/filler: rejected because the range decodes to coherent destructor code with internal branches and two direct calls.
- Runtime/compiler helper unrelated to `_DATFileMgr`: rejected because it restores `_DATFileMgr` vtable `0x006189cc` and uses the same object fields as the modeled `_DATFileMgr` deleting destructor.
- Dead artifact to ignore: rejected because it is source-shaped and class-specific; no-route only means there is no surviving static inbound edge.

### Source-authored versus compiler-retained treatment

Best inference: source-authored ordinary destructor semantics, compiler-retained as a standalone non-deleting destructor body with no direct surviving call route. It should be represented in source as `_DATFileMgr::~_DATFileMgr()` or factored cleanup called by that destructor, while the vtable remains pointed at the compiler-generated scalar deleting destructor.

Evidence checked:

- The modeled `_DATFileMgr::DeletingDestructor` decompilation at `0x0049d3d0` performs the same vtable restore, archive-vector element deletion, vector-storage free, vector clear, and resolver cleanup, then conditionally frees `this` when the delete flag is set.
- The raw body performs the same cleanup but lacks the deleting-destructor flag parameter, conditional object free, `this` return value setup, and `retn 4`; it ends with plain `retn`.
- Vtable data at `0x006189cc` points to `0x0049d3d0`, not `0x0049c750`, which is the expected MSVC shape for a virtual destructor slot using a scalar deleting destructor wrapper.

Rejected alternatives:

- Treat `0x0049c750` as the vtable destructor target: rejected by exact vtable dword `0x006189cc -> 0x0049d3d0`.
- Treat `0x0049d3d0` as the only source-authored destructor: rejected because the ordinary destructor body exists and matches the non-deleting source destructor shape.
- Hand-port both as independent source methods in final C++ now: rejected because a normal C++ class should express the destructor once and let the compiler emit the deleting destructor wrapper.

### Caller/reachability and raw PE call surface

Best inference: no direct static inbound route to the ordinary destructor start currently survives in the binary, but this does not reduce source-authored classification.

Evidence checked:

- IDA MCP `xrefs_to 0x0049c750` returns zero cross-references.
- Raw PE scan of `NexusTK.exe` found zero little-endian VA pointer hits for `0x0049c750`, zero RVA pointer hits for `0x0009c750`, and zero direct `E8`/`E9` rel32 call/jump hits to `0x0049c750` across executable sections.
- The same scan found one VA pointer hit for `0x0049d3d0` at `0x006189cc`, proving the live virtual route is through the scalar deleting destructor.
- IDA MCP `xrefs_to 0x0049d190` returns exactly the raw body call at `0x0049c7e8` and the deleting-destructor call at `0x0049d462`.

Rejected alternatives:

- Hidden vtable route to the ordinary destructor: rejected by vtable data.
- Direct static call missed by IDA: rejected by raw PE VA/RVA/rel32 scan.
- Callback/table route: no pointer hits to the raw start were found in the PE image; no table candidate is currently defensible.

### Field/type/helper naming

Best defensible source-facing names:

- `_DATFileMgr` remains the current best private implementation class name. The leading underscore is not original-proof, but the RTTI/vtable labels in IDA use `_DATFileMgr`, so changing it now would lower traceability.
- `DATFileResolver` should remain a descriptive documentation/source-facing name for the embedded name-index/hash-table subobject, not a separate `DATFileResolver.cpp`.
- Resolver field names should be documented as inferred: `m_maxLoadFactor`, `m_entryListSentinel`, `m_entryCount`, `m_bucketsBegin`, `m_bucketsEnd`, `m_bucketsCapacity`, `m_bucketMask`, `m_bucketCount`.
- Archive-vector field names should be documented as inferred: `m_archiveContainersBegin`, `m_archiveContainersEnd`, `m_archiveContainersCapacity` at `_DATFileMgr` offsets `+0x24`, `+0x28`, `+0x2c`.
- Node type should be described as `DATEntryNode` or `DATFileEntryNode`: fields `next`, `prev`, `keyText`, `archiveContainer`, `entryIndex`. `DATEntryNode` is the lower-churn recommendation because generated and docs already use it.

Rejected alternatives:

- `DATIndexVector` as the resolver owner/type: rejected because `DATIndexVector` helpers are shared with minimap/fitting-room/monster-image code and should remain standalone.
- Standalone `DATFileResolver.cpp`: rejected because every confirmed resolver use is embedded in `_DATFileMgr` lifecycle/load/find/insert context.
- Generic `loadedFiles` field names from generated source: weaker than archive-container names; these are not arbitrary files, they are mapped DAT archive containers.

### Source placement

Best inference: keep all target ownership and output routing under [UID:0000IO] `DATFileMgr`, projected to `NexusTK/archive/DATFileMgr.cpp`.

Evidence checked:

- `DATFileMgr` constructor at `0x0049bd30` allocates a `0x30` byte `_DATFileMgr`, installs vtable `0x006189cc`, initializes resolver/list/bucket state, and stores the internal pointer at wrapper offset `+0x04`.
- `_DATFileMgr::LoadDATFileIndex` constructs `DATFileContainer`, uppercases DAT entry names, and populates the name index.
- `DATFileResolver::Destroy` is called only by the raw ordinary destructor and the modeled deleting destructor.
- `by-file/DATFileMgr.md`, `by-class/_DATFileMgr.md`, `by-class/DATFileResolver.md`, and vtable docs already clear the ownership gate and consistently place this family in `DATFileMgr.cpp`.

Rejected alternatives:

- Move target to `DATArchive`: rejected because `DATArchive` is a subsystem grouping, not the direct file owner for this class destructor.
- Move target to `DATFileResolver`: rejected because the raw body owns both archive-vector teardown and resolver cleanup; the direct semantic owner is `_DATFileMgr`/`DATFileMgr.cpp`.
- Leave non-emitting: rejected because current owner/emitter route already surfaces to `auto-generated/NexusTK/archive/DATFileMgr.cpp`.

### Split/merge/reclassification

Best inference: no split and no merge.

- No split: the cold invalid-parameter tail belongs to the same destructor's vector free guard. Splitting it would orphan an internal branch target.
- No merge with `_DATFileMgr::DeletingDestructor`: the ordinary and deleting destructor are distinct emitted code bodies with different call/return conventions and routing evidence.
- No reclassification to ignored/compiler-only: the source-level destructor semantics must be recreated even if the exact raw body has no direct inbound edge.

### Final C++ treatment

Best inference: keep final C++ blank now.

The item will clear the current minimum code-entry gate if raised to `86/90`, but final C++ should wait because:

- A source-quality implementation should write one `_DATFileMgr::~_DATFileMgr()` body and let the compiler emit the scalar deleting destructor/vtable route.
- The target page alone should not emit duplicated cleanup code that competes with [UID:000004] `_DATFileMgr` class declarations or [UID:0002MB] vtable-data expectations.
- The final source field names remain inferred, especially resolver subobject spelling and archive-vector member names.
- The generated `simroot_v2` code is not final-quality source; it contains synthetic layout overlays and modern/scaffolded helper names.

## Evidence Standards Used

- IDA MCP read-only evidence: `lookup_funcs`, `insn_query`, `xrefs_to`, `xref_query`, `decompile`, `callees`, and `analyze_component`.
- Raw PE evidence: PE section parse, VA/RVA/file-offset mapping, little-endian pointer scan, direct rel32 `E8`/`E9` scan, and exact byte dump.
- Documentation evidence: existing target, DATFileMgr class/file pages, resolver cleanup page, aggregate DAT manager page, vtable-data pages, generated coverage and completion stats.
- Generated source evidence: `source-3/simroot_v2/class__DATFileMgr.cpp`, `class_DATFileResolver.cpp`, and `class_DATFileMgr.cpp` used as leads only.

## IDA MCP Facts

- Active IDA session: `b002_00011G_scrollable_control_20260616`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x00400000`.
- `lookup_funcs`:
  - `0x0049c720`: `sub_49C720`, size `0x2b`.
  - `0x0049c750`: `Not a function`.
  - `0x0049c7f6`: `Not a function`.
  - `0x0049c800`: `sub_49C800`, size `0x2c4`.
  - `0x0049d190`: `sub_49D190`, size `0xdc`.
  - `0x0049d3d0`: `sub_49D3D0`, size `0xb8`.
- `insn_query 0x0049c740-0x0049c800`:
  - `0x0049c74b`: `align 10h`.
  - `0x0049c750`: `push ebp`.
  - `0x0049c755`: `mov dword ptr [ecx], offset ??_7_DATFileMgr@@6B@`.
  - `0x0049c780-0x0049c792`: archive-container pointer loop, virtual slot call with pushed flag `1`.
  - `0x0049c797-0x0049c7de`: vector allocation free and begin/end/capacity clear.
  - `0x0049c7e5`: `add ecx, 4`.
  - `0x0049c7e8`: `call sub_49D190`.
  - `0x0049c7f0`: `retn`.
  - `0x0049c7f1`: `call __invalid_parameter_noinfo_noreturn`.
  - `0x0049c7f6`: `align 10h`.
- `xrefs_to`:
  - `0x0049c750`: none.
  - `0x0049c7f1`: one internal branch from `0x0049c7bf`.
  - `0x0049d190`: code xrefs at `0x0049c7e8` and `0x0049d462`.
  - `0x0049d3d0`: one data xref from `0x006189cc`.
  - `0x006189cc`: vtable stores at `0x0049bda1`, `0x0049c755`, and `0x0049d3dd`.
- `_DATFileMgr::DeletingDestructor` at `0x0049d3d0` decompiles as the same cleanup sequence plus delete-flag handling and optional object free.
- `DATFileMgr` constructor at `0x0049bd30` decompiles as public-wrapper initialization, `_DATFileMgr` allocation, `_DATFileMgr` vtable install, resolver/list/hash initialization, `DATIndexVectorResizeAndFill(8)`, archive-vector clear, and inner pointer store.

## Raw PE Facts

Raw PE parse of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

- Image base: `0x00400000`.
- `.text`: VA `0x00401000-0x0060c600`, raw `0x00000400-0x0020ba00`.
- `.rdata`: VA `0x0060d000-0x0066c200`, raw `0x0020ba00-0x0026ac00`.
- VA/RVA/file-offset mapping:
  - `0x0049c750`: RVA `0x0009c750`, file offset `0x0009bb50`, `.text`.
  - `0x0049c7f6`: RVA `0x0009c7f6`, file offset `0x0009bbf6`, `.text`.
  - `0x0049d190`: RVA `0x0009d190`, file offset `0x0009c590`, `.text`.
  - `0x0049d3d0`: RVA `0x0009d3d0`, file offset `0x0009c7d0`, `.text`.
  - `0x006189cc`: RVA `0x002189cc`, file offset `0x002173cc`, `.rdata`.
- Pointer/call-surface scan:
  - `0x0049c750` VA hits: `0`.
  - `0x0009c750` RVA hits: `0`.
  - rel32 call/jump hits to `0x0049c750`: `0`.
  - `0x0049d3d0` VA hits: `1`, at file offset `0x002173cc` / VA `0x006189cc`.
  - rel32 call/jump hits to `0x0049d190`: `2`, at `0x0049c7e8` and `0x0049d462`.
  - `0x006189cc` VA immediate hits: three, corresponding to text VAs `0x0049bda3`, `0x0049c757`, and `0x0049d3df` inside the three vtable-store instructions.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Recommended Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0049c750-0x0049c7f6` | [UID:00012F] target | `_DATFileMgr` ordinary/non-deleting destructor body plus cold invalid-parameter tail | TRUE | [UID:0000IO] `DATFileMgr` | `86/90` | Raise, keep blank C++ |
| `0x0049d190-0x0049d26c` | [UID:00012H] resolver destroy | Embedded resolver/hash-table cleanup | TRUE | [UID:00003J] `DATFileResolver` | no score change required | Support evidence |
| `0x0049d3d0-0x0049d488` | modeled function | `_DATFileMgr` scalar deleting destructor / vtable slot target | TRUE | [UID:000004]/[UID:0000IO] | no direct page change required | Companion evidence |
| `0x006189c8-0x006189d0` | [UID:0002MB] vtable data | `_DATFileMgr` RTTI + one scalar-deleting-destructor vtable slot | TRUE | [UID:000004] `_DATFileMgr` | no score change required | Confirms vtable route |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0049c750` | no direct `xrefs_to`; no PE VA/RVA/rel32 route | Raw ordinary destructor has no surviving direct route |
| `0x0049c755` | store to `0x006189cc` | Installs/restores `_DATFileMgr` vtable |
| `0x0049c78a` | indirect call through `[archiveContainer->vtable + 0]`, flag `1` | Deletes each loaded `DATFileContainer` |
| `0x0049c7c5` | direct call `sub_5C7526` | Frees archive-vector storage |
| `0x0049c7e8` | direct call `sub_49D190` | Destroys embedded resolver/hash-table at `this + 4` |
| `0x0049c7bf -> 0x0049c7f1` | internal branch to invalid-parameter tail | Cold tail is part of vector allocation guard |
| `0x006189cc -> 0x0049d3d0` | vtable data slot | Live virtual route is deleting destructor |

## Documentation Evidence And IDA Status

Existing docs validated:

- [UID:00012F] correctly describes a raw destructor-shaped body, exact padding, resolver cleanup, and no direct xrefs.
- [UID:000004] `_DATFileMgr` correctly treats offsets `+0x24/+0x28/+0x2c` as the archive-container pointer vector and `+0x04-+0x23` as resolver/hash-table state.
- [UID:0000IO] `DATFileMgr` correctly places the public wrapper, private `_DATFileMgr`, `DATFileContainer`, resolver subobject, vtables, singleton, and local helpers under `archive/DATFileMgr.cpp`.
- [UID:00012H] correctly identifies resolver cleanup callers at `0x0049c7e8` and `0x0049d462`.
- [UID:0002MB] correctly records `0x006189cc -> 0x0049d3d0` and the UTF-16 `"../"` boundary at `0x006189d0`.

Docs needing refresh:

- [UID:00012F] should explicitly add the 2026-06-16 raw PE VA/RVA/rel32 no-route evidence and the source-authored ordinary-destructor-versus-retained-no-route conclusion.
- [UID:00012F] should update final-C++ rationale: blank not because it fails the emitter/score gate, but because final source should consolidate the ordinary destructor/deleting destructor split through a class declaration and finalized field names.
- Support docs should prefer `archive-container vector` names over generic `loadedFiles` wording for offsets `+0x24/+0x2c`.

## Ranked Ownership Analysis

### 1. [UID:0000IO] DATFileMgr / `NexusTK/archive/DATFileMgr.cpp`

- Evidence for: owns public wrapper, private `_DATFileMgr`, resolver/hash-table subobject, mapped archive containers, singleton, vtable data, load/find/index methods, and destructor lifecycle. Current target already emits through this route to `auto-generated/NexusTK/archive/DATFileMgr.cpp`.
- Evidence against: original private helper spelling remains inferred, but the binary RTTI/vtable labels support `_DATFileMgr` strongly enough.
- Decision: keep owner/emitter `0000IO`.

### 2. [UID:000004] _DATFileMgr class

- Evidence for: direct semantic class owner of the destructor body; target writes `_DATFileMgr` vtable and uses `_DATFileMgr` fields.
- Evidence against: current page already routes method bodies through the file owner; changing target canonical owner from file to class may be semantically narrower but is not necessary for the current generated route and would require broader consistency review across `_DATFileMgr` method pages.
- Decision: keep current `0000IO` metadata for this report-only pass, but support text should state `_DATFileMgr` is the semantic class whose destructor is represented.

### 3. [UID:00003J] DATFileResolver

- Evidence for: raw destructor calls resolver cleanup at `this + 4`.
- Evidence against: target also tears down archive containers and vector storage; resolver cleanup is only a subobject callee. It is not the direct owner of the destructor body.
- Decision: reject as direct owner.

### 4. No-owner / non-emitting / ignored

- Evidence for: no direct xrefs to `0x0049c750`; no PE pointer or rel32 route to the start.
- Evidence against: code is class-specific, source-shaped, vtable-restoring, and semantically required by C++ destructor source. Current emitter route is valid.
- Decision: reject.

## Exact Target Metadata Recommendations

Recommended header values for `by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md`:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep `RECONSTRUCTION_CPP CODE` blank.

## Exact Support-Doc Text To Add / Replace

### Target page [UID:00012F]

Replace the current `Confidence:` bullet in `## Status` with:

```text
- Confidence: strong for exact byte range, raw ordinary destructor behavior, resolver cleanup call, archive-container vector teardown, and `DATFileMgr.cpp` ownership; medium-high for original private-class/helper spelling and final field names.
```

Replace the current final-C++ bullet in `## Status` with:

```text
- Final C++ is intentionally blank. After this recheck the item clears the minimum score/emitter route, but the source-quality representation should be emitted only after `_DATFileMgr::~_DATFileMgr()`, the compiler-generated scalar deleting destructor route, `DATFileResolver` embedded-member shape, and archive/resolver field names are finalized together.
```

Append to `## IDA Evidence`:

```text
- 2026-06-16 B002 IDA MCP recheck on session `b002_00011G_scrollable_control_20260616` reconfirmed `0x0049c750` and `0x0049c7f6` are not IDA functions, while `insn_query 0x0049c740-0x0049c800` decodes a coherent destructor body from `0x0049c750` through `0x0049c7f0`, a cold invalid-parameter call at `0x0049c7f1`, and alignment at `0x0049c7f6`.
- 2026-06-16 raw PE scan mapped `0x0049c750` to RVA `0x0009c750` / file offset `0x0009bb50` in `.text` and found zero VA pointer hits, zero RVA pointer hits, and zero direct `E8`/`E9` rel32 call/jump routes to the raw start. The same scan found the `_DATFileMgr` vtable slot pointer `0x006189cc -> 0x0049d3d0`, confirming the virtual route is the scalar deleting destructor, not this ordinary destructor body.
- The raw body should be treated as `_DATFileMgr`'s source-authored ordinary/non-deleting destructor semantics retained without a surviving direct inbound route. It is not padding, data, a callback table target, or an ignored compiler-only artifact.
```

Replace `## Source Reconstruction Notes` with:

```text
## Source Reconstruction Notes

Do not ignore this range. The absence of an IDA function object and the lack of direct VA/RVA/rel32 inbound route mean the ordinary destructor body has no surviving static caller, not that the bytes are non-source filler.

In final source, this should be represented as `_DATFileMgr::~_DATFileMgr()` or an equivalent private cleanup body that deletes each `DATFileContainer*` in the archive-container vector, frees the vector storage, clears `m_archiveContainersBegin`, `m_archiveContainersEnd`, and `m_archiveContainersCapacity`, and destroys the embedded resolver/hash-table member at `this + 4`. The compiler-generated scalar deleting destructor should remain the vtable slot route represented by `0x0049d3d0-0x0049d488`.

Best current field-name direction is descriptive, not original-proof: `_DATFileMgr::m_archiveContainersBegin`, `m_archiveContainersEnd`, `m_archiveContainersCapacity`, and embedded `DATFileResolver` fields `m_maxLoadFactor`, `m_entryListSentinel`, `m_entryCount`, `m_bucketsBegin`, `m_bucketsEnd`, `m_bucketsCapacity`, `m_bucketMask`, and `m_bucketCount`.
```

Append to target `## Changes`:

```text
- 2026-06-16 B002 source-quality reanalysis:
  - Before: score `82/88`; page documented raw no-function/no-direct-xref state, vtable restore, archive-vector teardown, resolver cleanup, and exact padding, but did not include raw PE route checks or a final source-authored-versus-retained-artifact decision.
  - Recommended after: score `86/90`; metadata owner/emitter stay [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md), reconstructable stays true, and final C++ stays blank.
  - Summary/evidence: IDA MCP reconfirmed no function at `0x0049c750`, exact body/tail/alignment through `0x0049c7f6`, xrefs only to resolver cleanup at `0x0049c7e8` and vtable store `0x0049c755`, and `_DATFileMgr::DeletingDestructor` semantic match at `0x0049d3d0`. Raw PE VA/RVA/rel32 scans found no inbound route to the ordinary destructor start, while vtable data `0x006189cc` points to `0x0049d3d0`; therefore this is a source-authored ordinary destructor body retained without a direct surviving route, not an ignored artifact.
```

### [UID:000004] `by-class/_DATFileMgr.md`

Append to `## Evidence Notes`:

```text
- 2026-06-16 B002 source-quality recheck of [UID:00012F] reconfirmed the raw ordinary destructor at `0x0049c750-0x0049c7f6` as source-authored `_DATFileMgr` cleanup semantics with no surviving direct VA/RVA/rel32 route to the start. The body restores vtable `0x006189cc`, deletes archive-container pointers from offsets `+0x24/+0x28`, frees and clears archive-vector storage at `+0x24/+0x28/+0x2c`, and calls resolver cleanup at `0x0049c7e8` on `this + 4`. Best current descriptive field names are `m_archiveContainersBegin`, `m_archiveContainersEnd`, and `m_archiveContainersCapacity`; final source names remain inferred.
```

No score change required for this support page in the current pass.

### [UID:0000IO] `by-file/DATFileMgr.md`

Replace the existing raw-destructor file-level rationale bullet with:

```text
- [UID:00012F][0x0049c750-0x0049c7f6._DATFileMgrRawDestructor](by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md) should be reconstructed as `_DATFileMgr`'s ordinary/non-deleting destructor or equivalent cleanup body even though current IDA does not model it as a function and raw PE scans find no direct VA/RVA/rel32 route to the start. It mirrors `_DATFileMgr::DeletingDestructor` without the delete-flag object-free tail; the vtable slot at `0x006189cc` correctly points to the scalar deleting destructor at `0x0049d3d0`.
```

No score change required for this support page.

### [UID:00012B] `by-memory/0x0049bd30-0x0049d6ed.DATManagers.md`

Append to `## Evidence`:

```text
- 2026-06-16 B002 rechecked [UID:00012F] with IDA MCP and raw PE scans: `0x0049c750` is still not an IDA function but decodes as a complete ordinary `_DATFileMgr` destructor through `0x0049c7f6`; PE VA/RVA/rel32 scans found no inbound route to the ordinary destructor start; vtable data `0x006189cc` points to the modeled scalar deleting destructor at `0x0049d3d0`; and both destructor bodies call resolver cleanup at `0x0049d190`. This supports keeping the raw body as a source-authored child under the DAT manager cluster, not as padding or ignored artifact.
```

No score change required for this aggregate page.

### [UID:00012H] `by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md`

Append to `## Source Reconstruction Notes`:

```text
The 2026-06-16 B002 source-quality recheck of [UID:00012F] strengthens the embedded-member interpretation: both the raw ordinary destructor and scalar deleting destructor call this cleanup on `_DATFileMgr + 4`, while no evidence points to a standalone `DATFileResolver.cpp` ownership route. Keep `DATFileResolver` as a descriptive embedded resolver/hash-table type until final class layout work proves a different original spelling.
```

No score change required for this support page.

### Vtable docs

No text change is required for [UID:0001XB] `DATManagerVtables` or [UID:0002MB] `_DATFileMgrVtableData`. Their current one-slot vtable conclusion is validated: `0x006189cc` points to `0x0049d3d0`, and `0x006189d0` is the UTF-16 `"../"` string boundary, not an ordinary destructor slot.

## Exact Supervisor-Owned `by-memory/-coverage-report.md` Replacement Row

Replace the current [UID:00012F] row with:

```text
    - [UID:00012F][0x0049c750-0x0049c7f6._DATFileMgrRawDestructor](by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md) : reconstructable : 86% : strong : Raw `_DATFileMgr` ordinary/non-deleting destructor; 2026-06-16 IDA/PE recheck confirms no IDA function at the start, exact `0x0049c750-0x0049c7f6` body plus cold invalid-parameter tail, no direct xrefs/VA/RVA/rel32 route to the start, `_DATFileMgr` vtable restore, archive-vector teardown fields `+0x24/+0x28/+0x2c`, resolver cleanup call at `0x0049c7e8`, and semantic match to `_DATFileMgr::DeletingDestructor` without the conditional object free.
```

Placement: keep the row between [UID:00012E] and [UID:00012G] in low-to-high address order.

## Generated Coverage / Stats Impact

Expected after applying target/support/report edits and running validation/rescore:

- `project-level/-auto-completion-stats.md`: [UID:00012F] should disappear from `Low_Completion` / `Low_Both` because recommended score is `86/90`.
- `auto-generated/-ag-memory-coverage.md`: ownership/emitter route should remain `emits`, owner `0000IO`, emitter `0000IO`, path `auto-generated/NexusTK/archive/DATFileMgr.cpp`.
- `by-memory/-coverage-report.md`: only the [UID:00012F] row needs the replacement above.

## Validation Commands

Recommended validation after applying the report:

> Executable block R001 was removed from this report and preserved verbatim in [00012F-datfilemgr-raw-destructor-source-quality-removed.md](00012F-datfilemgr-raw-destructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Optional post-checks:

> Executable block R002 was removed from this report and preserved verbatim in [00012F-datfilemgr-raw-destructor-source-quality-removed.md](00012F-datfilemgr-raw-destructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Negative Evidence Summary

- No IDA function object exists at `0x0049c750`; do not rely on decompiler output for this raw body.
- No direct IDA xrefs to `0x0049c750`.
- No raw PE VA pointer, RVA pointer, or direct rel32 call/jump to `0x0049c750`.
- No vtable slot points to `0x0049c750`; `_DATFileMgr` vtable slot points to `0x0049d3d0`.
- No evidence supports `DATFileResolver` as a standalone source file.
- No evidence supports folding `DATIndexVector` into `DATFileMgr.cpp`.

These negatives constrain reachability and final C++ timing, but they do not justify ignoring or de-routing the target.

## Final Recommendation

Apply the target raise to `86/90`, update source-quality text as above, and leave metadata route/final C++ unchanged. The target can legitimately rise above `85/85` because the new evidence resolves the source-authored-versus-artifact question, validates the exact range and cold tail, validates the no-route state with raw PE scans, and ties the body to the modeled deleting destructor and vtable route.

Do not add final C++ yet. The correct final output should be coordinated with the `_DATFileMgr` class declaration and scalar deleting destructor so the ordinary destructor source body is emitted once and the compiler produces the deleting-destructor wrapper/vtable slot.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/00012F-datfilemgr-raw-destructor-source-quality.md`
- Modified: none.
- by-* docs edited: none.
- Coverage reports edited: none.
- IDA DB edited: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00012F-datfilemgr-raw-destructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:23","uid":"00012F"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00012F-datfilemgr-raw-destructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00012F-datfilemgr-raw-destructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00012F"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
