*** UID:0000RH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pMemoryMan

## Status

- Confidence: strong for storage address, singleton lifecycle, accessor, and allocator bootstrap role; medium-high for final source spelling/placement.
- Address: `0x0069b4fc` (`dword_69B4FC` / `DAT_0069b4fc`)
- Working id: `g_pMemoryMan`
- Likely owner: [UID:0000L7][MemoryMan](by-file/MemoryMan.md)
- Memory storage page: [UID:0002B0][0x0069b4fc-0x0069b500.g_pMemoryMan](by-memory/0x0069b4fc-0x0069b500.g_pMemoryMan.md)

## Role

`g_pMemoryMan` stores the process-wide `MemoryMan` singleton pointer. Most allocation call sites do not use the object directly; they touch it through `GetMemoryMan` and then call allocation/free helper functions.

Likely declaration during reconstruction:

```cpp
static MemoryMan* g_pMemoryMan;
```

## Lifecycle

- [UID:0000WA][0x00419f70-0x00419f86.MemoryManStaticInitializer](by-memory/0x00419f70-0x00419f86.MemoryManStaticInitializer.md) constructs the static `MemoryMan` object at `dword_69B3A8` and registers the atexit reset thunk.
- [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md) installs the `MemoryMan` vtable and stores `this` into `g_pMemoryMan`.
- [UID:0001O7][0x0060c260-0x0060c26a.MemoryManAtexitResetThunk](by-memory/0x0060c260-0x0060c26a.MemoryManAtexitResetThunk.md) loads the static object and jumps to [UID:0001BB][0x00516010-0x00516021.MemoryManGlobalResetTail](by-memory/0x00516010-0x00516021.MemoryManGlobalResetTail.md), which clears `g_pMemoryMan` without freeing storage.
- [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) returns `g_pMemoryMan`.
- [UID:0001BJ][0x00516260-0x0051628e.MemoryManScalarDeletingDestructor](by-memory/0x00516260-0x0051628e.MemoryManScalarDeletingDestructor.md) clears `g_pMemoryMan` in the scalar deleting destructor and optionally frees the object.

## Evidence

- Live IDA MCP decompilation for `0x00516000` writes `dword_69B4FC = this`.
- Live IDA MCP decompilation for `0x00516030` returns `dword_69B4FC`.
- Live IDA MCP decompilation for `0x00516260` clears `dword_69B4FC`.
- Live IDA MCP disassembly for `0x00419f70` and `0x0060c260` confirms the static object initialization and atexit reset path.
- `operator_new` at `0x004f4aa0` and `operator_delete` at `0x004f4ac0` call `GetMemoryMan` before forwarding to allocation/free helpers, so this singleton is part of the global allocation bootstrap path.
- 2026-05-26 IDA MCP `xrefs_to 0x0069b4fc` still ties this storage to the constructor, reset/accessor, and destructor paths, not to a feature module.

## Source Migration Caveats

Keep rewrite work grounded in [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md) because this utility island mixes the singleton, static initializer/reset path, operator wrappers, allocation/free/realloc helpers, and copy wrappers.

## Cross-References

- [UID:0000L7][MemoryMan](by-file/MemoryMan.md)
- [UID:00007U][MemoryMan](by-class/MemoryMan.md)
- [UID:0000T8][MemoryAllocationHelpers](by-global/MemoryAllocationHelpers.md)
- [UID:0001V4][MemoryManLayout](by-type/by-struct/MemoryManLayout.md)
- [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md)
- [UID:0002B0][0x0069b4fc-0x0069b500.g_pMemoryMan](by-memory/0x0069b4fc-0x0069b500.g_pMemoryMan.md)

## Changes

- 2026-05-30 completion/confidence review:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, and stale caveat text around omitted constructor/accessor lifecycle functions.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:86`, exact storage-page link, and corrected source migration caveats.
  - Summary/evidence: exact storage page [UID:0002B0][0x0069b4fc-0x0069b500.g_pMemoryMan](by-memory/0x0069b4fc-0x0069b500.g_pMemoryMan.md), `MemoryMan` file/class docs, and [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md) support the singleton lifecycle and allocator-bootstrap role. Confidence is capped because final original source placement/spelling remains reconstructed.
- 2026-06-05: Marked reconstructable under [UID:0000L7][MemoryMan](by-file/MemoryMan.md). Evidence: live IDA MCP reports four xrefs to `0x0069b4fc`; decompilation confirms constructor `0x00516000`, atexit reset tail `0x0060c260`, accessor `0x00516030`, and scalar deleting destructor `0x00516260` write/clear/read `dword_69B4FC`.
