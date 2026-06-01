*** UID:0000BF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Queue

## Status

- Confidence: strong for layout and method roles, medium for active feature ownership.
- Likely source file: [UID:0000MW][Queue](by-file/Queue.md)
- Address range: [UID:0001FN][0x005539e0-0x00553c07.Queue](by-memory/0x005539e0-0x00553c07.Queue.md)
- Current generated file: `source-3/simroot_v2/class_Queue.cpp`

## Class Purpose

`Queue` is a small `LObject`-derived circular queue for fixed-size slots. The constructor takes slot size and slot count, allocates one contiguous zeroed buffer, and initializes read/write indices.

## Layout

```text
+0x00  vtable
+0x04  slotSize
+0x08  slotCount
+0x0c  buffer
+0x10  readIndex
+0x14  writeIndex
```

The current generated field names call `+0x04` `m_slotCount` and `+0x08` `m_slotSize`, but IDA push/pop arithmetic shows `+0x04` is multiplied by the read/write index as the byte stride, while `+0x08` is used as the wrap limit.

2026-05-26 IDA recheck confirms the constructor stores `a2` to `this[1]`, `a3` to `this[2]`, and allocates `a3 * a2` bytes. The raw write/read helpers still use `+0x04` as the copy byte count and `+0x08` as the wrap limit, so keep the corrected layout names above despite the current generated parameter names.

## Methods

| Address | Method | Role |
| --- | --- | --- |
| `0x005539e0` | [UID:0001FM][0x005539e0-0x00553a5c.QueueConstructor](by-memory/0x005539e0-0x00553a5c.QueueConstructor.md) | Calls `LObject`, installs vtable, allocates `slotSize * slotCount` zeroed bytes. |
| `0x00553a60` | [UID:0001FO][0x00553a60-0x00553ab9.QueueDestructor](by-memory/0x00553a60-0x00553ab9.QueueDestructor.md) | Frees buffer and runs `LObject` teardown. |
| `0x00553ac0` | [UID:0001FP][0x00553ac0-0x00553b05.QueueWriteSlotRaw](by-memory/0x00553ac0-0x00553b05.QueueWriteSlotRaw.md) | Raw start; copies one fixed-size slot into the write position and advances write index. |
| `0x00553b10` | [UID:0001FQ][0x00553b10-0x00553b55.QueueReadSlotRaw](by-memory/0x00553b10-0x00553b55.QueueReadSlotRaw.md) | Raw start; copies one fixed-size slot out of the read position and advances read index. |
| `0x00553b60` | [UID:0001FR][0x00553b60-0x00553b6a.QueueIsEmptyRaw](by-memory/0x00553b60-0x00553b6a.QueueIsEmptyRaw.md) | Raw start; compares read and write indices. |
| `0x00553b70` | [UID:0001FS][0x00553b70-0x00553c07.QueueScalarDeletingDestructor](by-memory/0x00553b70-0x00553c07.QueueScalarDeletingDestructor.md) | Destructor plus conditional delete. |

## Cross-References

- [UID:0000MW][Queue](by-file/Queue.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)
- [UID:0000L7][MemoryMan](by-file/MemoryMan.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `82/78`.
  - Before: The page was unevaluated though it already documented layout, method roles, corrected field naming, and memory cross-references.
  - After: Scored as high completion with medium-high confidence because active feature ownership remains less certain than the container implementation.
  - Evidence: Existing layout notes, 2026-05-26 IDA recheck, and method table cover the queue behavior while preserving generated-name caveats.
