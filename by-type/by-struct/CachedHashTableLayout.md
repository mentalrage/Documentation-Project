*** UID:0001TU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CachedHashTableLayout

## Status

- Entity kind: class layout support struct
- Confidence: strong for IDA-observed offsets, medium for final field names.
- Proposed owner: [UID:0000HZ][CachedHashTable](by-file/CachedHashTable.md)
- Evidence basis: live IDA MCP constructor/destructor/accessor checks and raw helper disassembly.
- Reconstructable: yes, as source-level container layout information. Do not emit final C++ until the original class declaration and field names are proven.

## Layout

```text
CachedHashTableLayout
  +0x00  LObject base
  +0x04  void* entriesBuffer
  +0x08  uint8_t* slotStateBuffer
  +0x0c  int entrySize
  +0x10  int slotCount
  +0x14  int entryCount
  +0x18  uint8_t hashSeed0
  +0x19  uint8_t hashSeed1
  +0x1a  uint8_t hashSeed2
  +0x1b  uint8_t hashSeed3
```

Observed object size is `0x1c` bytes.

## Allocation Rules

- Constructor allocates `entrySize * slotCount` bytes for `entriesBuffer`.
- Constructor allocates `slotCount` bytes for `slotStateBuffer`.
- Constructor zeroes each slot-state byte.
- Destructor frees both buffers through the shared memory manager and clears both pointers.
- Raw helper `0x004c63d0` clears slot-state bytes and resets `entryCount`.
- Raw helper `0x004c6450` copies one fixed-size entry into `entriesBuffer + entrySize * index`, marks the slot occupied when needed, and updates `entryCount`.
- Raw helpers `0x004c63f0`, `0x004c6420`, and `0x004c64d0` return entry addresses derived from the same `entriesBuffer`/`entrySize` pair.
- IDA-modeled accessors [UID:00016Q][0x004c64b0-0x004c64c4.CachedHashTableCountAccessors](by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md) return `slotCount` and `entryCount`.
- 2026-05-31 IDA MCP recheck of `0x004c6160` confirms constructor writes `entrySize` at `+0x0c`, `slotCount` at `+0x10`, zeroes `entryCount` at `+0x14`, allocates `entrySize * slotCount` bytes into `+0x04`, allocates `slotCount` bytes into `+0x08`, clears the slot-state buffer, and writes four `rand()` bytes at `+0x18..+0x1b`.
- 2026-05-31 IDA MCP recheck of `0x004c6260` confirms destructor frees `+0x04` and `+0x08`, clears both pointers, and chains to the `LObject` cleanup path.
- 2026-05-31 raw IDA disassembly confirms helper `0x004c63d0` resets `+0x14` and clears every slot-state byte, helper `0x004c6450` copies `entrySize` bytes into `entriesBuffer + entrySize * index`, sets `slotStateBuffer[index] = 1`, and increments `entryCount` only on first occupation.
- 2026-05-31 raw IDA disassembly confirms accessors `0x004c64b0` and `0x004c64c0` return `+0x10` and `+0x14`, respectively.
- 2026-06-04 live IDA MCP reconfirms constructor/destructor half-open boundaries `0x004c6160-0x004c6259` and `0x004c6260-0x004c62ce`; constructor tail writes the four seed bytes through `+0x1b`, and destructor clears buffer pointers at `+0x04` and `+0x08`.
- 2026-06-04 live IDA raw helper disassembly reconfirms `0x004c63d0` clears `+0x14` and the byte array at `+0x08`, `0x004c63f0` clears a slot and decrements `+0x14`, `0x004c6420` checks the slot-state byte before returning an entry address, `0x004c6450` copies `+0x0c` bytes and marks new slots occupied, and `0x004c64d0` computes `+0x04 + +0x0c * index`.
- 2026-06-04 live IDA confirms the two modeled accessors remain exact `0x4`-byte functions: `0x004c64b0-0x004c64b4` returns `+0x10`, and `0x004c64c0-0x004c64c4` returns `+0x14`.

## Naming Notes

`slotStateBuffer` is a structural placeholder. Current evidence proves a parallel byte array with `0` meaning empty and non-zero meaning occupied. The four hash seed fields are low-byte results of `rand()`; the currently documented raw hash-index helper sums caller-provided key bytes and divides by `slotCount`, but no caller has yet shown whether the seed bytes participate in a higher-level probe/key path.

## Open Questions

- Final source-facing names for `entriesBuffer`, `slotStateBuffer`, and the four seed bytes remain provisional.
- The raw helpers at `0x004c62d0-0x004c64de` are not all IDA-modeled function starts; source reconstruction should split or inline them only after caller and vtable-slot review.

## Cross-References

- [UID:00001F][CachedHashTable](by-class/CachedHashTable.md)
- [UID:0000HZ][CachedHashTable](by-file/CachedHashTable.md)
- [UID:0001X6][CachedHashTableVtable](by-type/by-vtable/CachedHashTableVtable.md)
- [UID:00016O][0x004c6160-0x004c659c.CachedHashTableLifecycle](by-memory/0x004c6160-0x004c659c.CachedHashTableLifecycle.md)
- [UID:00016P][0x004c62d0-0x004c64de.CachedHashTableRawHelpers](by-memory/0x004c62d0-0x004c64de.CachedHashTableRawHelpers.md)
- [UID:00016Q][0x004c64b0-0x004c64c4.CachedHashTableCountAccessors](by-memory/0x004c64b0-0x004c64c4.CachedHashTableCountAccessors.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)

## Changes

- What existed before: the page had a documented 28-byte layout but needed current live evidence and report alignment.
- What changed: evidence basis now foregrounds live IDA MCP constructor/destructor/helper checks, and the page is marked reconstructable as layout documentation.
- Summary/evidence: IDA MCP rechecked `0x004c6160`, `0x004c6260`, raw helper disassembly at `0x004c63d0-0x004c64df`, and the count accessors at `0x004c64b0/0x004c64c0`.
- 2026-06-04: Raised scores from `74/86` to `82/90` and attached the layout to [UID:0000HZ][CachedHashTable](by-file/CachedHashTable.md). The increase is justified by live IDA verification of every documented field offset through constructor, destructor, clear/remove/get/set/accessor helpers, plus exact `0x4`-byte accessor bodies. Completion remains below final-source level because field names are still provisional and the original class declaration is not proven.
