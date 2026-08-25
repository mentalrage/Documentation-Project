*** UID:0001X1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Binary Codec Vtables

## 2026-08-15 Compiler-Consequence Resolution

This exact paired-vtable record remains owned as BinaryCodec family evidence but is not independently reconstructable and has no emitter. Encoder record `0x006192c8-0x006192d4` and Decoder record `0x006192d4-0x006192e0` are compiler/linker consequences of complete standalone class declarations, virtual ordinary destructors, concrete NoopVirtual methods, and compiler-generated scalar deleting wrappers. Formal CPP/H remain blank; no handwritten dword table, wrapper, RTTI, or vtable definition belongs in source.

The records end exactly before unrelated `0x006192e0`, whose sole user at `0x004a5e9e` is ParseEntries. Earlier statements routing an empty marker, favoring separate Encoder/Decoder roots, or leaving the one-file split unresolved are superseded by the final BinaryCodec.cpp/.h topology. The exact bytes, slots, xrefs, and boundary remain preserved.

## Dated Superseded Status

- Entity kind: vtable layout
- Confidence: very strong for slot values, owning class association, vtable-store refs, exported slot-target function facts, and the non-vtable boundary at `0x006192e0`.
- Parent attachment: attached to [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md), now `86/88`, because this is shared read-only type data for both codec classes.
- Evidence basis: live IDA MCP dword, xref, function-boundary, and padding checks through 2026-06-04; exported function JSON and local documentation cross-checks were re-reviewed during the 2026-06-21 B006 Rule 26 source-quality pass.
- Metadata caveat: any non-IDA metadata that omits these vtables is incomplete; IDA dwords and xrefs are the authority here.
- Source C++ policy: this by-type page documents compiler-generated vtable evidence and source declaration implications. Do not emit a handwritten vtable object or dword table from this target. The source-facing declarations belong in [UID:00004F][Encoder](by-class/Encoder.md), [UID:00003M][Decoder](by-class/Decoder.md), [UID:0000J1][Encoder](by-file/Encoder.md), and [UID:0000IQ][Decoder](by-file/Decoder.md). The exact vtable bytes regenerate from the class declarations, virtual destructors, concrete no-op virtual slots, and compiler-generated scalar deleting destructors.

## Exact Dword Map

| Address | Value | Interpretation |
| --- | --- | --- |
| `0x006192c8` | `0x00646b2c` | `??_R4Encoder@@6B@` RTTI complete object locator for [UID:00004F][Encoder](by-class/Encoder.md). |
| `0x006192cc` | `0x004a5e30` | `Encoder` first virtual slot: MSVC scalar deleting destructor wrapper [UID:00013V][0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor](by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md). |
| `0x006192d0` | `0x004a5630` | `Encoder` second virtual slot: one-byte concrete no-op virtual [UID:00013L][0x004a5630-0x004a5631.EncoderNoopVirtual](by-memory/0x004a5630-0x004a5631.EncoderNoopVirtual.md). |
| `0x006192d4` | `0x00646b74` | `??_R4Decoder@@6B@` RTTI complete object locator for [UID:00003M][Decoder](by-class/Decoder.md). |
| `0x006192d8` | `0x004a5e00` | `Decoder` first virtual slot: MSVC scalar deleting destructor wrapper [UID:00013U][0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor](by-memory/0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor.md). |
| `0x006192dc` | `0x004a5df0` | `Decoder` second virtual slot: one-byte concrete no-op virtual [UID:00013T][0x004a5df0-0x004a5df1.DecoderNoopVirtual](by-memory/0x004a5df0-0x004a5df1.DecoderNoopVirtual.md). |
| `0x006192e0` | `0x0000001a` | First dword of [UID:0003IC][0x006192e0-0x00619340.ParseEntriesConstantTable](by-memory/0x006192e0-0x00619340.ParseEntriesConstantTable.md), not a codec vtable slot. |

## Encoder Vtable

- Primary vtable: `0x006192cc`
- Owner class: [UID:00004F][Encoder](by-class/Encoder.md)
- Likely source file: [UID:0000J1][Encoder](by-file/Encoder.md)

| Slot | Target | Interpretation |
| --- | --- | --- |
| `+0x00` | [UID:00013V][0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor](by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md) | `Encoder::ScalarDeletingDestructor` |
| `+0x04` | [UID:00013L][0x004a5630-0x004a5631.EncoderNoopVirtual](by-memory/0x004a5630-0x004a5631.EncoderNoopVirtual.md) | no-op virtual / `nullsub_27` |

IDA xrefs to `0x006192cc` land at:

- `0x004a4e70` in `Encoder::Encoder`
- `0x004a4ea0` in `Encoder::~Encoder`
- `0x004a5e3a` in `Encoder::ScalarDeletingDestructor`

The no-op virtual target has only the vtable data reference at `0x006192d0` in the current IDA database.

## Decoder Vtable

- Primary vtable: `0x006192d8`
- Owner class: [UID:00003M][Decoder](by-class/Decoder.md)
- Likely source file: [UID:0000IQ][Decoder](by-file/Decoder.md)

| Slot | Target | Interpretation |
| --- | --- | --- |
| `+0x00` | [UID:00013U][0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor](by-memory/0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor.md) | `Decoder::ScalarDeletingDestructor` |
| `+0x04` | [UID:00013T][0x004a5df0-0x004a5df1.DecoderNoopVirtual](by-memory/0x004a5df0-0x004a5df1.DecoderNoopVirtual.md) | no-op virtual / `nullsub_28` |

IDA xrefs to `0x006192d8` land at:

- `0x004a5640` in `Decoder::Decoder`
- `0x004a5670` in `Decoder::~Decoder`
- `0x004a5e0a` in `Decoder::ScalarDeletingDestructor`

The no-op virtual target has only the vtable data reference at `0x006192dc` in the current IDA database.

[UID:00013S][0x004a5dd0-0x004a5ded.DecoderFinalize](by-memory/0x004a5dd0-0x004a5ded.DecoderFinalize.md) is not part of this vtable. B009's 2026-06-28 current MCP pass found zero incoming xrefs to `0x004a5dd0`, while the Decoder vtable still contains only `0x004a5e00` as the scalar deleting destructor slot and `0x004a5df0` as the no-op virtual slot. `Decoder::Finalize()` is a separate non-virtual lifecycle method emitted through [UID:00003M][Decoder](by-class/Decoder.md), not handwritten vtable support.

## Live IDA Evidence

2026-06-04 IDA MCP checks confirmed:

- `0x004a5630-0x004a5631` and `0x004a5df0-0x004a5df1` are one-byte `retn` functions.
- `0x004a5e00-0x004a5e24` and `0x004a5e30-0x004a5e54` are scalar deleting destructor wrappers that restore the class vtable and conditionally call the delete helper.
- `0x006192c8 -> ??_R4Encoder@@6B@`
- `0x006192cc -> 0x004a5e30`
- `0x006192d0 -> 0x004a5630`
- `0x006192d4 -> ??_R4Decoder@@6B@`
- `0x006192d8 -> 0x004a5e00`
- `0x006192dc -> 0x004a5df0`
- `0x006192e0 -> 0x0000001a`, with the only data ref from `0x004a5e9e` inside the adjacent [UID:0000IN][DATFile](by-file/DATFile.md) parser helper. This proves `0x006192e0` is not another codec vtable slot.
- `0x004a5e54-0x004a5e60` is `0xcc` padding before the adjacent DAT helper at `0x004a5e60`.

## Heuristic And Inference Reanalysis

| Issue | Best direction | Evidence | Rejected alternatives / remaining uncertainty |
| --- | --- | --- | --- |
| Aggregate owner | Keep [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md) as the family/coordinator owner for this by-type aggregate. | The target intentionally spans both sibling classes, shares [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md), and currently routes an empty marker through `auto-generated/NexusTK/util/BinaryCodec.cpp`. | Do not move the aggregate to only `Encoder` or only `Decoder`; either single-class owner would be wrong for half of the target. Do not move to `DATFile`, `PacketBuffer`, or `TextEdit`; those are adjacent/consumer routes, not ownership. |
| Exact vtable data owners | Keep [UID:0003IA][0x006192c8-0x006192d4.EncoderVtableData](by-memory/0x006192c8-0x006192d4.EncoderVtableData.md) under [UID:00004F][Encoder](by-class/Encoder.md) and [UID:0003IB][0x006192d4-0x006192e0.DecoderVtableData](by-memory/0x006192d4-0x006192e0.DecoderVtableData.md) under [UID:00003M][Decoder](by-class/Decoder.md). | RTTI names, constructor/destructor vtable-store xrefs, and generated memory coverage route the exact children to `Encoder.cpp` / `Decoder.cpp`. | Do not force the exact `.rdata` children through `BinaryCodec.cpp`; the class owners are more direct. |
| Source family / file split | Continue documenting probable `NexusTK/util/Encoder.cpp` and `NexusTK/util/Decoder.cpp`, with [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md) as the coordinator for shared layout/vtable-family facts. | The file docs own the method clusters and child routes, while this by-type page explains why the two classes form one compact codec family. | A single original `BinaryCodec.cpp` / header remains plausible, but current generated source model and class-specific children are stronger than a forced merge. |
| No-op virtual names | Use descriptive `EncoderNoopVirtual` and `DecoderNoopVirtual` in docs; in declaration snippets use `NoopVirtual` only as a descriptive placeholder. | Both targets are concrete one-byte `ret` functions reached only by vtable data refs. Separate destructor slots prove they are not destructors. | Reject raw `nullsub_27` / `nullsub_28` as source-quality names. Reject pure-virtual or abstract placeholder: the binary contains concrete return bodies. Exact original virtual method names remain unproved and cap final naming confidence. |
| Scalar deleting destructor policy | Treat `0x004a5e30` and `0x004a5e00` as compiler-generated MSVC scalar deleting destructors. Do not emit them as source methods. | Exported bodies restore the class vtable, test hidden flag bit 0, conditionally call delete helper `0x005c7526`, return `this`, and OOAnalyzer marks both as deleting destructors. | Reject handwritten `ScalarDeletingDestructor` source implementations. Source should express `virtual ~Encoder()` / `virtual ~Decoder()` and let MSVC generate wrappers. |
| Decoder finalize relationship | Keep [UID:00013S][0x004a5dd0-0x004a5ded.DecoderFinalize](by-memory/0x004a5dd0-0x004a5ded.DecoderFinalize.md) outside the vtable and route its source body through [UID:00003M][Decoder](by-class/Decoder.md). | B009 current MCP reports no xrefs to `0x004a5dd0`; vtable bytes remain `0x006192d8 -> 0x004a5e00` and `0x006192dc -> 0x004a5df0`; the finalize body is ordinary non-virtual lifecycle code that clears cursor state and returns prior validity. | Reject treating finalize as a hidden virtual slot, no-op support body, scalar deleting destructor wrapper, or handwritten vtable helper. |
| Formal target C++ | Keep [UID:0001X1] formal C++ blank. Carry declaration guidance only in prose/support docs. | The by-type aggregate spans compiler-generated `.rdata` for two classes and routes an empty marker today. Emitting a vtable literal in `BinaryCodec.cpp` would duplicate class-owned generated data and would not match original C++ source. | Do not mark the aggregate non-reconstructable: the source declaration implications are reconstructable. Do not populate a C++ table literal. |
| Relationship to cursor layout | Cross-link [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md) as shared instance-layout evidence. | The layout documents `+0x00` vptr, `+0x04` buffer, `+0x08` capacity/limit, `+0x0c` cursor, `+0x10` byte-order flag, and `+0x11` valid flag; constructors write flags word `0x0101`. | Do not let this vtable target settle final field names alone. Field/accessor naming remains owned by the layout/class docs. |
| `0x006192e0` boundary | Treat `0x006192e0` as DAT parser constant table start, not part of codec vtables. | The value is `0x1a`, xref is from `0x004a5e9e`, [UID:0003IC][0x006192e0-0x00619340.ParseEntriesConstantTable](by-memory/0x006192e0-0x00619340.ParseEntriesConstantTable.md) owns the exact child, and `0x004a5e54-0x004a5e60` is padding before the adjacent parser helper. | Reject "third Decoder slot" and "shared codec table sentinel". |
| Split needs | No new split is required for this by-type target. Preserve existing exact children. | Exact `.rdata` children already split `EncoderVtableData`, `DecoderVtableData`, and `ParseEntriesConstantTable`; glue code children already exist. | Do not create new by-memory pages for this report. |

## Dated Superseded Declaration Guidance

This is declaration guidance for support docs, not formal C++ output for [UID:0001X1]. The exact vtable bytes are compiler-generated from declarations like these:

```cpp
class Encoder {
public:
    Encoder();
    virtual ~Encoder();

    // Descriptive placeholder. The binary body at 0x004a5630 is a concrete
    // no-op vtable slot; the original source name is not currently proven.
    virtual void NoopVirtual();

    void Initialize(unsigned char *buffer, unsigned int capacity);
    bool Finalize(unsigned int *bytesWritten);
    void WriteByte(unsigned char value);
    void WriteShort(unsigned short value);
    void WriteInt(unsigned int value);
    void WriteBytes(const void *data, unsigned int byteCount);

private:
    unsigned char *m_outputBuffer; // +0x04
    unsigned int m_capacity;       // +0x08
    unsigned int m_writePos;       // +0x0c
    bool m_useBigEndian;           // +0x10
    bool m_isWritable;             // +0x11
};

class Decoder {
public:
    Decoder();
    virtual ~Decoder();

    // Descriptive placeholder. The binary body at 0x004a5df0 is a concrete
    // no-op vtable slot; the original source name is not currently proven.
    virtual void NoopVirtual();

    void Initialize(const unsigned char *buffer, unsigned int size);
    bool Finalize();

private:
    const unsigned char *m_inputBuffer; // +0x04
    unsigned int m_inputSize;           // +0x08
    unsigned int m_readPos;             // +0x0c
    bool m_useBigEndian;                // +0x10
    bool m_isValid;                     // +0x11
};
```

The private field names above are source-quality directions for class/layout docs. `m_capacity` versus `m_inputSize` reflects Encoder output-capacity semantics and Decoder input-limit semantics. If [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md) standardizes neutral aliases, keep the aliases synchronized. The scalar deleting destructors should not appear as declarations; they are generated from the virtual destructors.

## Dated Superseded Source-Layout Implication

Both classes have compact two-slot vtables and share the same [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md) field pattern. The vtable adjacency supports a paired utility source family, either separate `NexusTK/util/Encoder.cpp` / `NexusTK/util/Decoder.cpp` files or one compact binary-codec source/header family. It does not support assigning the codec methods to packet, DAT, or text-edit feature modules.

## Cross-References

- [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md)
- [UID:0000J1][Encoder](by-file/Encoder.md)
- [UID:0000IQ][Decoder](by-file/Decoder.md)
- [UID:00004F][Encoder](by-class/Encoder.md)
- [UID:00003M][Decoder](by-class/Decoder.md)
- [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md)
- [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md)
- [UID:00013V][0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor](by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md)
- [UID:00013U][0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor](by-memory/0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor.md)

## Changes

- 2026-06-28 B009 [UID:00013S][0x004a5dd0-0x004a5ded.DecoderFinalize](by-memory/0x004a5dd0-0x004a5ded.DecoderFinalize.md) implementation sync:
  - Before/after score unchanged: `88/92`.
  - Metadata unchanged: [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md) remains owner/emitter, `RECONSTRUCTABLE:TRUE`, and formal C++ remains blank.
  - Summary/evidence: added the negative vtable relationship for [UID:00013S][0x004a5dd0-0x004a5ded.DecoderFinalize](by-memory/0x004a5dd0-0x004a5ded.DecoderFinalize.md). Current MCP session `supervisor_20260628_resume` confirms `0x004a5dd0` has zero incoming xrefs and is not referenced by the Decoder vtable; Decoder vtable bytes remain RTTI/COL at `0x006192d4`, scalar deleting destructor slot `0x006192d8 -> 0x004a5e00`, and no-op virtual slot `0x006192dc -> 0x004a5df0`. The exact finalize child is separate non-virtual lifecycle source emitted through [UID:00003M][Decoder](by-class/Decoder.md), while this by-type page continues to document declaration/vtable implications only.
- 2026-06-21 B006 Rule 26 source-quality incorporation:
  - Before: scored `84/90`; the page carried the core live IDA vtable facts but not the report-level export confirmation, explicit source C++ policy, exact dword map, heuristic owner/source-placement decisions, or declaration guidance.
  - After: scored `88/92`; owner/emitter remain [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md), `RECONSTRUCTABLE` remains `TRUE`, and formal C++ remains blank.
  - Summary/evidence: incorporated the B006 report's exact `Encoder` and `Decoder` two-slot vtable facts, RTTI dwords, constructor/destructor/scalar-destructor vtable-store xrefs, exported one-byte no-op virtual bodies, exported 36-byte MSVC scalar deleting destructor wrappers, class-owned exact child policy for [UID:0003IA][0x006192c8-0x006192d4.EncoderVtableData](by-memory/0x006192c8-0x006192d4.EncoderVtableData.md) and [UID:0003IB][0x006192d4-0x006192e0.DecoderVtableData](by-memory/0x006192d4-0x006192e0.DecoderVtableData.md), `0x006192e0` DAT parser table boundary proof through [UID:0003IC][0x006192e0-0x00619340.ParseEntriesConstantTable](by-memory/0x006192e0-0x00619340.ParseEntriesConstantTable.md), no new split requirement, and rejection of `DATFile`, `TextEdit`, packet, single-class owner, handwritten vtable-object, raw `nullsub_*`, pure-virtual, and handwritten scalar-deleting-destructor alternatives.
- 2026-06-04: Attached `AUTOGEN_PARENT_UID:0000HQ`; scores remain `84/90`.
  - Before: the page had strong vtable content but no parent attachment and stale non-IDA metadata caveat wording.
  - After: live IDA MCP reconfirms slot dwords, vtable-store refs, no-op bodies, deleting-destructor boundaries, padding, and the `0x006192e0` non-vtable boundary, and the page is attached to the strengthened BinaryCodec coordinator.
  - Score rationale: no score increase was made because the new pass reconfirms rather than materially expands the vtable evidence.
