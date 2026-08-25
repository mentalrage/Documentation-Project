** TARGET-REPORT-UID:00013D **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00013D Encoder Core Index Source Quality Research

## Finalized Report / Current Recommendation

- Assignment: `B002-goal2-encoder-core-index-source-quality-00013D-20260617`
- Target: [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](../../../../../by-memory/0x004a4e70-0x004a5621.EncoderCore.md)
- Current target metadata: `COMPLETION:82`, `CONFIDENCE:88`, `CANONICAL_OWNER:00004F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004F`
- Current recommendation: reclassify `00013D` as a reviewed non-emitting Encoder split/index, not as a source-emitting aggregate.
- Final disposition: `00013D` should remain as the address-neighborhood/index page for the Encoder writer cluster, but exact child pages should carry source ownership and output routing.
- Required action: supervisor should update the target metadata/body and manual coverage row; do not delete the page and do not emit aggregate C++ from it.
- Confidence: high for non-emitting split/index policy; medium-high for final source-facing names because names are descriptive/recovered from behavior, not original-source proof.

Recommended target metadata after the supervisor updates the page:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00004F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

This is not a no-85 result. The executable path to 85/85+ is to document `00013D` explicitly as a non-emitting split/index, list the exact source-bearing children, record the raw helper islands still needing future exact pages, and remove the aggregate emitter.

## Supporting Research

## Target

- Target UID: `00013D`
- Target path: `by-memory/0x004a4e70-0x004a5621.EncoderCore.md`
- Source queue/report row: `by-memory/-coverage-report.md` row near `0x004a4e70`, current text says reconstructable `82%`.
- Generated route row: `auto-generated/-ag-memory-coverage.md` currently lists `00013D` as `emits` through `00004F` to `auto-generated/NexusTK/util/Encoder.cpp`.
- Current supervisor classification: report-only source-quality and split/index decision for an aggregate/index currently owned and emitted through [UID:00004F][Encoder](../../../../../by-class/Encoder.md).

## Executive Recommendation

`00013D` should become `RECONSTRUCTABLE:FALSE`, with `CANONICAL_OWNER:00004F` and blank `EMITTER_UIDS`.

The page is valuable as an Encoder writer-cluster index, but it is not itself a source-level method, class, data object, or final source range. It overlaps exact source-bearing method pages:

- `00013C` constructor
- `00013E` destructor
- `00013F` `WriteByte`
- `00013G` `WriteShort`
- `00013H` `WriteInt`
- `00013I` `WriteBytes`
- `00013J` `Initialize`
- `00013K` `Finalize`

The current emitting aggregate route duplicates these exact children in the generated-memory coverage model. If C++ is later entered, it must be entered on the exact children or the class page with explicit child insertion, not on this aggregate index.

Do not replace `00013D` entirely with existing exact child pages yet. The existing exact children cover the modeled Encoder methods, but the address interval also contains currently unpaged raw helper-shaped islands between the modeled functions. Keep `00013D` as the non-emitting index until those raw helper islands are either split into exact children or explicitly classified as padding/compiler artifacts.

## Supervisor Active Recheck

This assignment was explicitly report-only. I did not edit target by-* docs, generated reports, source files, IDA state, generated source, or `by-memory/-coverage-report.md`.

The assigned item does not need direct split edits in this pass because exact modeled children already exist. It does need structural reclassification: the aggregate should stop emitting and should document the missing raw-helper child follow-up.

No live IDA MCP mutation was performed. The evidence checked here is the current project documentation's recorded live IDA MCP evidence, generated autogen coverage rows, manual coverage rows, ignored padding ledger, source-tree proposal, and exact neighboring child pages.

## Inference Research Guidance Check

`by-structure.md` distinguishes semantic ownership from output routing and says broad containers should be `RECONSTRUCTABLE:FALSE` when exact children carry the real source ownership. It also says final C++ entry requires more than a numeric score: names, dependencies, boundaries, and source placement must support final output.

`inference_research.md` cautions that source file ownership cannot be proven from adjacency alone. Here the owner decision does not rely on address adjacency alone. The strongest signals are the Encoder vtable stores, the shared cursor layout, exact method field effects, the direct TextEditPane serialization caller set, class/file pages, and the proposed util source tree. These signals support [UID:00004F][Encoder](../../../../../by-class/Encoder.md) as the direct semantic owner and [UID:0000J1][Encoder](../../../../../by-file/Encoder.md) as the concrete file root, while [UID:0000HQ][BinaryCodec](../../../../../by-file/BinaryCodec.md) remains the broader coordinator.

Existing documentation assumptions revalidated:

- Validated: `00013D` is an index over the main Encoder writer cluster.
- Validated: exact child pages are canonical for method bodies.
- Validated: direct behavioral callers are from TextEditPane serialization, not packet/network code.
- Corrected recommendation: the aggregate should not be reconstructable/emitting now that exact children carry source ownership.
- Still open: final historical field names, header layout, no-op virtual declaration name, and raw helper exact-child treatment.

## Heuristic / Inference Reanalysis And Validation

### 1. Aggregate disposition

Best inference: `00013D` is a non-emitting split/index over an Encoder method cluster. It should not remain reconstructable/emitting.

Evidence checked:

- Target page calls itself a "grouping index" and says exact per-body by-memory pages are canonical.
- `by-structure.md` says a reviewed container that only indexes exact source-bearing children should be `RECONSTRUCTABLE:FALSE`.
- `auto-generated/-ag-memory-coverage.md` currently emits both `00013D` and all exact method children through `00004F`, creating duplicate aggregate/child output routing.
- [UID:00013M][DecoderAndCodecVtableGlue](../../../../../by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md) is already modeled the right way: non-emitting split/index, `RECONSTRUCTABLE:FALSE`, blank emitters.

Rejected alternatives:

- Keep `00013D` reconstructable/emitting: rejected because it is not a source-level function or class and it overlaps exact children.
- Delete/replace `00013D` with exact children only: rejected because the interval still records raw helper-shaped islands and useful cluster-level evidence.
- Move owner to `0000HQ` BinaryCodec: rejected for this target because the range is Encoder-only behavior. BinaryCodec is the family coordinator, not the direct owner.

Score/source/final-C++ impact:

- After reclassification and body refresh, `86/90` is defensible for an index.
- No final C++ should ever be entered on this aggregate page.
- Exact child pages remain the future source-C++ candidates once their source-quality blockers are resolved.

### 2. Exact Encoder method boundaries

The modeled Encoder methods in scope are stable:

| Range | UID | Best source-facing role | Boundary evidence |
| --- | --- | --- | --- |
| `0x004a4e70-0x004a4e94` | `00013C` | `Encoder::Encoder()` | IDA recorded size `0x24`; vtable store, field clears, flags word `0x0101`. |
| `0x004a4ea0-0x004a4ea7` | `00013E` | `Encoder::~Encoder()` | IDA recorded size `0x7`; vtable restore only. |
| `0x004a4ec0-0x004a4ef1` | `00013F` | `Encoder::WriteByte(uint8_t value)` | IDA recorded size `0x31`; writes one byte if valid/capacity permits. |
| `0x004a4f00-0x004a4f59` | `00013G` | `Encoder::WriteShort(uint16_t value)` | IDA recorded size `0x59`; two-byte writer with byte-order branch. |
| `0x004a4ff0-0x004a506b` | `00013H` | `Encoder::WriteInt(uint32_t value)` | IDA recorded size `0x7b`; four-byte writer with byte-order branch. |
| `0x004a5480-0x004a54c6` | `00013I` | `Encoder::WriteBytes(const void *data, uint32_t size)` | IDA recorded size `0x46`; copy-helper callees and cursor advance. |
| `0x004a55c0-0x004a55de` | `00013J` | `Encoder::Initialize(uint8_t *buffer, uint32_t capacity)` | IDA recorded size `0x1e`; attaches caller buffer and resets cursor/valid. |
| `0x004a55e0-0x004a5621` | `00013K` | `bool Encoder::Finalize(uint32_t *outBytesWritten)` | IDA recorded size `0x41`; returns prior valid state, writes trailing NUL, detaches buffer. |

The exact child pages document alignment between these methods and identify raw helper-shaped islands in the uncovered interior:

- `0x004a4eb0-0x004a4ebd`: likely byte-order setter role because it stores caller byte to `+0x10`; no exact page yet.
- `0x004a4f60-0x004a4fe3`: likely three-byte scalar writer using the same cursor/capacity/byte-order fields; no exact page yet.
- `0x004a5070-0x004a50e3`, `0x004a50f0-0x004a5189`, `0x004a5190-0x004a5293`, `0x004a52a0-0x004a53ca`, `0x004a53d0-0x004a5472`: raw string/helper islands documented by the `WriteInt` child as outside `WriteInt` and before `WriteBytes`; no exact pages yet.
- `0x004a54d0-0x004a558b` and `0x004a5590-0x004a55b4`: raw helper bodies documented by the `WriteBytes` and `Initialize` children as outside those exact methods; no exact pages yet.

Best inference: the existing exact child pages are correct for modeled method bodies, but they do not fully replace `00013D` for all executable-looking bytes in the interval. Future B work should split/research those raw helper islands before claiming complete final source for `Encoder`.

### 3. Padding `0x004a5621-0x004a5630`

Best inference: confirmed ignored alignment padding, not Encoder source and not part of the no-op virtual.

Evidence checked:

- Target page records `0x004a5621-0x004a5630` as `0xcc` padding before `0x004a5630`.
- [UID:00013K][EncoderFinalize](../../../../../by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md) records the exact end-exclusive function end at `0x004a5621`.
- `by-memory/-ignored.md` lists `0x004a5621-0x004a5630` as alignment padding between `EncoderCore` and codec vtable glue.
- Manual coverage row `0000VN` already marks the span ignored `100%`.

Rejected alternatives:

- Include the padding in `EncoderFinalize`: rejected by function end and `0xcc` bytes.
- Include the padding in `EncoderNoopVirtual`: rejected because the no-op starts at `0x004a5630`.
- Treat as unknown/uncovered: rejected because the ignored ledger and exact pages already document it.

### 4. Companion vtable glue and destructor pages

Best inference:

- [UID:00013L][EncoderNoopVirtual](../../../../../by-memory/0x004a5630-0x004a5631.EncoderNoopVirtual.md) should remain an exact reconstructable vtable-support child owned/routed through `Encoder`, but final C++ remains blank until the virtual declaration name is known.
- [UID:00013V][EncoderScalarDeletingDestructor](../../../../../by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md) should remain an exact reconstructable compiler/vtable support child owned/routed through `Encoder`, but final handwritten source should not model it as an ordinary method.
- [UID:00013M][DecoderAndCodecVtableGlue](../../../../../by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md) should remain a non-emitting BinaryCodec split/index.

Evidence checked:

- `00013L` records one-byte `retn`, no callers/callees, and sole vtable data xref at `0x006192d0`.
- `00013V` records `0x24` bytes, vtable restore, scalar-delete flag test, conditional delete helper, and vtable data route.
- `00013M` records modeled Decoder lifecycle/glue, raw Decoder no-function/no-xref caveats, vtable dwords, and padding envelopes, and is already `RECONSTRUCTABLE:FALSE`.
- [UID:0001X1][BinaryCodecVtables](../../../../../by-type/by-vtable/BinaryCodecVtables.md) records Encoder vtable `0x006192cc` with slots `0x004a5e30` and `0x004a5630`.

Rejected alternatives:

- Fold `00013L` or `00013V` into `00013D`: rejected because they are outside the `00013D` range.
- Make `00013M` emitting: rejected because it is an overlapping codec island index with exact children.
- Assign `00013L` or `00013V` directly to BinaryCodec: rejected because both are Encoder vtable members and [UID:00004F][Encoder](../../../../../by-class/Encoder.md) now clears the direct parent gate.

### 5. Cursor layout and field naming

Best defensible layout from [UID:0001TS][BinaryCodecCursorLayout](../../../../../by-type/by-struct/BinaryCodecCursorLayout.md):

| Offset | Descriptive field role | Encoder-specific recommended name direction | Confidence |
| --- | --- | --- | --- |
| `+0x00` | vtable pointer | `vtable` / compiler ABI field | Confirmed role, source field not explicit. |
| `+0x04` | buffer pointer | `m_outputBuffer` or `m_buffer` | Confirmed role, name descriptive. |
| `+0x08` | buffer size/limit | `m_capacity` or `m_bufferCapacity` | Confirmed role, name descriptive. |
| `+0x0c` | cursor/write position | `m_writePos` or `m_cursor` | Confirmed role, name descriptive. |
| `+0x10` | byte-order flag | `m_useBigEndian` | Confirmed semantics, name descriptive. |
| `+0x11` | valid/writable flag | `m_isWritable` or `m_isValid` | Confirmed semantics, name descriptive. |

Best source-facing field names for future Encoder C++ are `m_outputBuffer`, `m_capacity`, `m_writePos`, `m_useBigEndian`, and `m_isWritable`. These are not proven original names. For shared layout documentation, keep neutral names `buffer`, `limit/capacity`, `cursor`, `byteOrder`, and `valid`.

Rejected alternatives:

- Treat `+0x10/+0x11` as one opaque flags word in final source: rejected for behavior documentation because methods address the two bytes independently. Acceptable only as a low-level implementation note.
- Claim exact historical names: rejected because no debug/source metadata proves them.
- Use TextEditPane field names for Encoder fields: rejected because TextEditPane is only the consumer.

Score/final-C++ impact: unresolved exact field names cap final C++, but not 85-level documentation or owner/source placement.

### 6. Byte-order and valid-flag semantics

Best inference:

- Constructor writes flags word `0x0101`, so new instances default to byte-order flag `1` and valid/writable flag `1`.
- Nonzero `+0x10` means scalar writes are big-endian: `WriteShort` writes high byte then low byte; `WriteInt` writes most-significant byte through least-significant byte.
- Zero `+0x10` means scalar writes use native little-endian direct stores.
- `+0x11` gates all writer methods. If it is zero, writers return without mutation.
- Capacity checks reserve one extra byte for the final NUL written by `Finalize`.
- On insufficient capacity, writers clear `+0x11` and do not write.
- `Initialize` attaches caller storage, zeroes cursor, and sets valid/writable to `1`.
- `Finalize` returns the prior valid/writable byte as `bool`, optionally reports the cursor, writes a trailing NUL at `buffer[cursor]`, clears buffer/capacity/cursor, restores valid/writable to `1`, and detaches without freeing the caller buffer.

Rejected alternatives:

- Interpret byte-order flag as "little endian when nonzero": rejected by documented high-byte-first branches.
- Interpret valid flag as "has buffer attached": rejected because `Finalize` restores it to `1` after clearing the buffer.
- Treat the output buffer as owned by Encoder: rejected because destructor does not free it and `Finalize` only detaches it.

### 7. Direct TextEditPane serializer caller route

Best inference: [UID:0000UM][EncodeTextEditState_0058E490](../../../../../by-item/EncodeTextEditState_0058E490.md) / [UID:0001JN][TextEditPaneSerialization](../../../../../by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md) is the only confirmed direct behavioral consumer of the modeled Encoder writer family.

Recorded call sites:

| Encoder method | Recorded caller sites inside `0x0058e490` |
| --- | --- |
| Constructor `0x004a4e70` | `0x0058e4e4` |
| Initialize `0x004a55c0` | `0x0058e54b` |
| WriteBytes `0x004a5480` | `0x0058e56e`, `0x0058e5ba`, `0x0058e5e3`, `0x0058e612` |
| WriteByte `0x004a4ec0` | `0x0058e57b` |
| WriteInt `0x004a4ff0` | `0x0058e58b` |
| WriteShort `0x004a4f00` | `0x0058e59a`, `0x0058e5c9`, `0x0058e5f8` |
| Finalize `0x004a55e0` | `0x0058e624` |
| Destructor `0x004a4ea0` | `0x0058e66c` |

The serializer writes a first raw text-storage payload, delimiter byte `0`, marker `0x6b6f6e67` (`"kong"` under the Encoder's default big-endian scalar write), then size-prefixed secondary payloads.

Rejected alternatives:

- Packet/network owner: rejected because no packet sender or network caller owns these methods; TextEditPane is the direct consumer, and Encoder remains a generic utility dependency.
- TextEditPane owns Encoder methods: rejected because TextEditPane consumes a stack Encoder object; state mutation and vtable ownership stay in Encoder.
- BinaryCodec owns direct emission for these methods: rejected because BinaryCodec is a coordinator. Direct owner is the Encoder class, and concrete file root is `Encoder.cpp`.

### 8. Owner and emitter route

Best ownership chain:

- Direct semantic owner for exact Encoder methods and the `00013D` index: [UID:00004F][Encoder](../../../../../by-class/Encoder.md).
- Concrete source file root: [UID:0000J1][Encoder](../../../../../by-file/Encoder.md), projected to `NexusTK/util/Encoder.cpp`.
- Source-family coordinator: [UID:0000HQ][BinaryCodec](../../../../../by-file/BinaryCodec.md).

For `00013D` specifically:

- `CANONICAL_OWNER:00004F` remains appropriate.
- `RECONSTRUCTABLE:FALSE` is appropriate because the page is an index.
- `EMITTER_UIDS` must be blank because non-reconstructable index pages must not emit.

For exact source-bearing method children:

- Keep `CANONICAL_OWNER:00004F`.
- Keep `EMITTER_UIDS:00004F` only while final source route remains through `Encoder` class to `Encoder.cpp`.

Rejected alternatives:

- `CANONICAL_OWNER:0000J1` for the aggregate: rejected because the narrow direct owner is the class, not the file.
- `CANONICAL_OWNER:0000HQ` for the aggregate: rejected because the range is not a shared Encoder/Decoder island.
- `CANONICAL_OWNER:NONE`: rejected because Encoder class ownership is proven well enough by vtable stores, method layout, and class/file pages.

### 9. Final source-facing method/signature names

Best descriptive source-facing names and signatures for future exact-child review:

```cpp
Encoder::Encoder();
Encoder::~Encoder();
void Encoder::WriteByte(uint8_t value);
void Encoder::WriteShort(uint16_t value);
void Encoder::WriteInt(uint32_t value);
void Encoder::WriteBytes(const void *data, uint32_t byteCount);
void Encoder::Initialize(uint8_t *buffer, uint32_t capacity);
bool Encoder::Finalize(uint32_t *outBytesWritten);
```

These names are strongly descriptive and consistent with current by-* method pages. They should still be marked inferred/descriptive until original headers, debug symbols, or stronger source-name evidence appears.

Additional likely raw helper names that need separate research:

- `0x004a4eb0`: likely `SetByteOrder` / `SetBigEndian` because it stores the caller byte at `+0x10`.
- `0x004a4f60`: likely `WriteTriByte` / `Write24` because it writes a three-byte scalar with byte-order logic.
- Later raw helper islands: likely string/blob writers, but exact names and signatures are not safe without their own child pages and caller/callee analysis.

Rejected alternatives:

- Treat all helper names as final original names: rejected.
- Use address-based names in final source: rejected for future final C++ because they are decompiler scaffolding.
- Use `BinaryCodec::Write*`: rejected because the methods mutate an `Encoder` object and vtable.

### 10. Duplicate aggregate/child coverage and final C++ eligibility

Current generated coverage problem:

- `auto-generated/-ag-memory-coverage.md` lists `00013D` as `emits` to the same class/file route as its exact children.
- The generated `Encoder.cpp` file in this workspace snapshot is empty, but the coverage model is still wrong because any future aggregate C++ would overlap the exact child method pages.

Best correction:

- Change `00013D` to `RECONSTRUCTABLE:FALSE`, blank emitters.
- Keep exact children source-bearing.
- Add future exact child pages for raw helper islands before claiming complete source reconstruction of the cluster.

Final C++:

- `00013D`: not eligible because it should be non-reconstructable/non-emitting.
- Exact modeled method children: numerically close to or above minimum code-entry eligibility, but still not final-C++ ready because exact historical field names, header layout, raw helper siblings, no-op virtual declaration, and source dependency surface remain open.
- `00013L`: no final C++ until the virtual declaration name is known.
- `00013V`: should be produced by class destructor/vtable shape, not hand-written as an ordinary method.

## Evidence Standards Used

Evidence types checked:

- Current target page and exact child pages under `by-memory`.
- Class/file/type docs for `Encoder`, `BinaryCodec`, cursor layout, and vtables.
- Direct TextEditPane serializer item and memory pages.
- Generated autogen coverage reports for current ownership/emitter state.
- Manual `by-memory/-coverage-report.md` rows for stale score/reconstructability text.
- `by-memory/-ignored.md` row for `0x004a5621-0x004a5630`.
- `by-project-structure/proposed-source-tree.md` for `NexusTK/util/Encoder.cpp`, `Decoder.cpp`, and `BinaryCodec.cpp` placement.
- `by-structure.md` and `inference_research.md` policy on split/index pages, emitter routing, scores, and inference limits.

What prevents stronger confidence:

- No direct original header/source metadata proves exact member names.
- Raw helper-shaped islands inside `00013D` are not exact child pages yet.
- Direct live IDA MCP was not invoked in this report-only pass; the report relies on the current docs' recorded live IDA evidence.

## IDA MCP Facts From Current Docs

Function/range facts:

- IDA recorded modeled Encoder starts and sizes for constructor, destructor, `WriteByte`, `WriteShort`, `WriteInt`, `WriteBytes`, `Initialize`, and `Finalize`.
- IDA recorded `0x004a55e0` size `0x41`, ending at `0x004a5621`.
- IDA recorded `0x004a5630` as `nullsub_27`, size `0x1`.
- IDA recorded `0x004a5e30` as scalar deleting destructor, size `0x24`.

Data/table/padding facts:

- `0x004a5621-0x004a5630` is fifteen `0xcc` bytes.
- Encoder vtable data has scalar deleting destructor slot `0x004a5e30` and no-op virtual slot `0x004a5630`.
- Cursor fields span through `+0x11`.

Xref facts:

- Writer-family behavioral callers are inside `0x0058e490-0x0058e691`.
- Encoder vtable base `0x006192cc` is referenced by constructor, destructor, and scalar deleting destructor.
- No ordinary caller exists for the no-op virtual in current docs; it is vtable-data only.

Negative facts:

- No documented evidence supports packet/network ownership.
- No documented evidence proves a folded `BinaryCodec.cpp` direct owner over separate `Encoder.cpp`.
- Existing exact children do not yet cover every helper-shaped island inside `00013D`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004a4e70-0x004a5621` | `00013D` / target | Encoder writer cluster index | Recommend `FALSE` | `00004F` | Recommend `86/90` | Non-emitting split/index |
| `0x004a4e70-0x004a4e94` | `00013C` | Constructor | `TRUE` | `00004F` | `84/90` | Exact child |
| `0x004a4ea0-0x004a4ea7` | `00013E` | Destructor | `TRUE` | `00004F` | `84/90` | Exact child |
| `0x004a4ec0-0x004a4ef1` | `00013F` | `WriteByte` | `TRUE` | `00004F` | `84/90` | Exact child |
| `0x004a4f00-0x004a4f59` | `00013G` | `WriteShort` | `TRUE` | `00004F` | `84/90` | Exact child |
| `0x004a4ff0-0x004a506b` | `00013H` | `WriteInt` | `TRUE` | `00004F` | `84/90` | Exact child |
| `0x004a5480-0x004a54c6` | `00013I` | `WriteBytes` | `TRUE` | `00004F` | `84/90` | Exact child |
| `0x004a55c0-0x004a55de` | `00013J` | `Initialize` | `TRUE` | `00004F` | `84/90` | Exact child |
| `0x004a55e0-0x004a5621` | `00013K` | `Finalize` | `TRUE` | `00004F` | `84/90` | Exact child |
| `0x004a5621-0x004a5630` | `0000VN` ignored ledger | Padding | `FALSE` | n/a | `100` coverage | Confirmed `0xcc` |
| `0x004a5630-0x004a5631` | `00013L` | Encoder no-op virtual | `TRUE` | `00004F` | `85/91` | Companion exact child |
| `0x004a5630-0x004a5e54` | `00013M` | Codec glue index | `FALSE` | `0000HQ` | `85/89` | Non-emitting split/index |
| `0x004a5e30-0x004a5e54` | `00013V` | Encoder scalar deleting destructor | `TRUE` | `00004F` | `85/91` | Companion exact child |

## Ranked Ownership Analysis

### 1. `Encoder` class `00004F`

Evidence for:

- All modeled methods mutate Encoder fields and install/restore the Encoder vtable.
- `Encoder` class page documents the complete method family and companion vtable support.
- Direct source route reaches [UID:0000J1][Encoder](../../../../../by-file/Encoder.md), a validated `NexusTK/util/Encoder.cpp` root.
- Direct TextEditPane serializer calls construct and use a stack Encoder, proving consumer use rather than ownership transfer.

Evidence against:

- The aggregate contains raw helper-shaped islands that still need exact child treatment.
- Final historical field/method names are not proven.

Decision: accepted as direct semantic owner for the index and exact Encoder children. The target index should still have blank emitters because it is not source-bearing.

### 2. `BinaryCodec` file/coordinator `0000HQ`

Evidence for:

- Encoder and Decoder share cursor layout and adjacent compact vtables.
- `BinaryCodec` coordinates both `Encoder.cpp` and `Decoder.cpp` in source-tree docs.
- `00013M` is correctly attached to BinaryCodec as the shared codec glue index.

Evidence against:

- `00013D` itself contains only Encoder behavior, not Decoder or shared glue.
- Direct source-root file docs distinguish `Encoder.cpp` from `BinaryCodec.cpp`.
- Attaching to BinaryCodec would bypass the narrower direct class owner.

Decision: rejected as direct owner/emitter for `00013D`; retained as source-family context.

### 3. `TextEditPane`

Evidence for:

- It is the only confirmed behavioral caller of the modeled Encoder writer family.

Evidence against:

- TextEditPane only consumes Encoder. It does not own the Encoder vtable, cursor fields, or method implementation.
- The serializer page itself says the helper belongs to TextEditPane and should not move Encoder code into TextEditPane.

Decision: rejected as owner; retained as direct caller evidence.

### 4. Network/PacketBuffer/Socket

Evidence for:

- Generic "encoder" naming can suggest packet serialization.

Evidence against:

- No direct packet/network caller is documented for these methods.
- Current direct consumer is a UI text-edit serializer.
- PacketBuffer/Socket docs own packet helpers, not this caller-owned in-memory writer.

Decision: rejected.

## Negative Evidence Summary

- No source evidence proves `00013D` should emit one aggregate source snippet.
- No current evidence proves `BinaryCodec.cpp` rather than `Encoder.cpp` is the concrete source file for the Encoder class.
- No current evidence proves exact original field names.
- No current evidence proves the no-op virtual declaration name.
- No current exact pages exist for all raw helper-shaped islands inside the aggregate interval.
- No reason was found to route the aggregate through TextEditPane, PacketBuffer, Socket, DATFile, or Decoder.

## Final Recommendation

Exact recommended changes:

- Change `00013D` metadata to `86/90`, `CANONICAL_OWNER:00004F`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`.
- Rewrite the target status to say: "reviewed non-emitting Encoder writer-cluster split/index; exact child pages carry source ownership; raw helper islands require future exact child research."
- Preserve cross-references to `00004F`, `0000J1`, `0000HQ`, `0000UM`, `0001TS`, `0001X1`, `00013M`, `00013L`, and `00013V`.
- Do not enter reconstruction C++ on `00013D`.
- Do not remove existing exact children.
- Recommend later split/research for raw helper islands inside the target range before final source C++ is attempted for the full Encoder class.

Exact items left non-emitting and why:

- `00013D`: non-emitting because it is a reviewed aggregate/index that overlaps exact source-bearing children.
- `00013M`: already non-emitting because it is a shared codec glue index with exact children.

Exact items still source-bearing:

- `00013C`, `00013E`, `00013F`, `00013G`, `00013H`, `00013I`, `00013J`, `00013K`, `00013L`, and `00013V` remain exact Encoder children/support pages routed through `00004F` unless future final-source modeling changes the compiler-glue treatment.

## Support Docs To Update

Supervisor/A-agent updates recommended:

- `by-memory/0x004a4e70-0x004a5621.EncoderCore.md`: update metadata/body as above.
- `by-file/Encoder.md`: update the `00013D` proposed-contents note to say the row is non-emitting after reclassification; keep `Encoder.cpp` as concrete source root.
- `by-class/Encoder.md`: clarify that `00013D` is evidence/index, while exact method and vtable-support pages carry source-bearing state.
- `by-memory/-coverage-report.md`: apply replacement rows below.
- `auto-generated/-ag-memory-coverage.md`: do not edit manually; regenerate through validator after the metadata update.

No required change:

- `by-file/BinaryCodec.md`: already treats BinaryCodec as the coordinator.
- `by-type/by-struct/BinaryCodecCursorLayout.md`: already records final field-name and `sizeof` caveats.
- `by-memory/-ignored.md`: padding row `0x004a5621-0x004a5630` is already correct.

## Supervisor-Owned `by-memory/-coverage-report.md` Replacement Rows

Replace the current `00013D` row near `0x004a4e70` with:

```markdown
    - [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md) 0x004a4e70-0x004a5621 | split/index | EncoderCore exact-child index : not_reconstructable : 86% : strong : B002 source-quality review recommends reclassifying this broad Encoder writer cluster as a non-emitting split/index. Exact source-bearing method children [UID:00013C][0x004a4e70-0x004a4e94.EncoderConstructor](by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md)-[UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md) carry owner/emitter routing through [UID:00004F][Encoder](by-class/Encoder.md) and [UID:0000J1][Encoder](by-file/Encoder.md); internal raw helper islands still need exact child research before final Encoder C++.
```

Replace the stale `00013M` row near `0x004a5630` with:

```markdown
    - [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md) 0x004a5630-0x004a5e54 | split/index | DecoderAndCodecVtableGlue exact-child index : not_reconstructable : 85% : strong : Reviewed non-emitting BinaryCodec codec-glue index over exact Encoder/Decoder vtable and lifecycle children; live documented IDA evidence confirms modeled glue boundaries, raw Decoder non-function/no-xref starts, compact Encoder/Decoder vtables, `0x006192e0` DAT boundary, and padding envelopes. Exact child pages carry source ownership.
```

Replace the stale `00013L` row with:

```markdown
    - [UID:00013L][0x004a5630-0x004a5631.EncoderNoopVirtual](by-memory/0x004a5630-0x004a5631.EncoderNoopVirtual.md) 0x004a5630-0x004a5631 | vtable support | EncoderNoopVirtual : reconstructable : 85% : strong : One-byte `Encoder` no-op virtual slot; documented live IDA evidence confirms the single `retn`, no ordinary callers/callees, sole vtable data xref at `0x006192d0`, and owner/emitter route through [UID:00004F][Encoder](by-class/Encoder.md) to [UID:0000J1][Encoder](by-file/Encoder.md). Final C++ remains blank because the original virtual declaration name is unrecovered.
```

Replace the stale `00013V` row with:

```markdown
    - [UID:00013V][0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor](by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md) 0x004a5e30-0x004a5e54 | scalar deleting destructor | EncoderScalarDeletingDestructor : reconstructable : 85% : strong : `Encoder` scalar deleting destructor wrapper; documented live IDA evidence confirms exact `0x24` range, `off_6192CC` vtable restore, scalar-delete flag test, conditional delete-helper call, and vtable route at `0x006192cc`. Owner/emitter route remains [UID:00004F][Encoder](by-class/Encoder.md); final source should come from class destructor/vtable shape rather than handwritten standalone C++.
```

The padding row for `0x004a5621-0x004a5630` does not need replacement.

## Follow-Up Actions

Supervisor actions:

- Apply the metadata/body change to `00013D`.
- Apply the manual coverage row replacements above.
- Run validator file mode for the changed target and any support docs edited.
- Run autogen refresh so `auto-generated/-ag-memory-coverage.md` stops listing `00013D` as an emitter.

A-agent actions:

- Refresh `by-class/Encoder.md` and `by-file/Encoder.md` wording after the target reclassification.
- Keep `00013L` and `00013V` as exact companion pages, but do not promote final C++ until virtual/destructor source modeling is settled.

Future B002 split/research actions:

- Create or recommend exact child pages for the raw helper islands inside `0x004a4e70-0x004a5621`, especially likely `SetByteOrder`, likely `WriteTriByte`, and the string/blob writer family.
- Recheck whether any raw helper has direct callers or only retained/dead source-shaped status.

## Confidence

- Recommendation confidence: high.
- Score confidence: `86/90` after page body refresh; current `82/88` is reasonable until the page explicitly documents the non-emitting policy and raw-helper inventory.
- Remaining uncertainty: final original method names, field names, header split, `sizeof` padding, raw helper exact children, and no-op virtual declaration.

## Validator Results / Validation Commands

No validator run was required for by-* docs because this task was report-only and no by-* files were edited.

Recommended supervisor validation after applying edits:

> Executable block R001 was removed from this report and preserved verbatim in [00013D-encoder-core-index-source-quality-removed.md](00013D-encoder-core-index-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Recommended read-only checks before final source promotion:

> Executable block R002 was removed from this report and preserved verbatim in [00013D-encoder-core-index-source-quality-removed.md](00013D-encoder-core-index-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/00013D-encoder-core-index-source-quality.md`
- Modified: none outside this report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00013D-encoder-core-index-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:23","uid":"00013D"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00013D-encoder-core-index-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00013D-encoder-core-index-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00013D"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
