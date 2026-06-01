*** UID:0000RH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pMemoryMan

## Status

- Confidence: strong for storage address, singleton lifecycle, accessor, and allocator bootstrap role; medium-high for final source spelling/placement.
- Address: `0x0069b4fc` (`dword_69B4FC` / `DAT_0069b4fc`)
- Current generated id: `g_pMemoryMan`
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

- Current `source-3/simroot_v2/class_MemoryMan.cpp` emits `MemoryMan* g_pMemoryMan`, constructor assignment `g_pMemoryMan = this`, reset/destructor clears, `GetMemoryMan`, the static initializer/atexit reset path, and allocation/free/realloc/copy helpers in the same generated source family.
- Current `source-3/simroot_v2/class_MemoryMan.cpp.source_map.json` maps `global-data:g_pMemoryMan` to six declaration/reference lines and records the storage evidence as manual, from documented by-global address evidence.
- Live IDA MCP decompilation for `0x00516000` writes `dword_69B4FC = this`.
- Live IDA MCP decompilation for `0x00516030` returns `dword_69B4FC`.
- Live IDA MCP decompilation for `0x00516260` clears `dword_69B4FC`.
- Live IDA MCP disassembly for `0x00419f70` and `0x0060c260` confirms the static object initialization and atexit reset path.
- `operator_new` at `0x004f4aa0` and `operator_delete` at `0x004f4ac0` call `GetMemoryMan` before forwarding to allocation/free helpers, so this singleton is part of the global allocation bootstrap path.
- 2026-05-26 IDA MCP `xrefs_to 0x0069b4fc` still ties this storage to the constructor, reset/accessor, and destructor paths, not to a feature module.

## Current Data Caveats

Older generated snapshots duplicated marker-only `g_pMemoryMan` comment rows and omitted the constructor/accessor functions that prove the singleton lifecycle. The current `simroot_v2` active source has improved and now includes those lifecycle lines, but the output is still generated evidence with rewrite-quality issues such as modern C++ spelling, raw-address throw helpers, and active-file source boundaries that should be verified against [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md).

Live IDA MCP was unavailable during this 2026-05-30 review pass, so the existing 2026-05-26 IDA notes were not refreshed.

## Cross-References

- [UID:0000L7][MemoryMan](by-file/MemoryMan.md)
- [UID:00007U][MemoryMan](by-class/MemoryMan.md)
- [UID:0000T8][MemoryAllocationHelpers](by-global/MemoryAllocationHelpers.md)
- [UID:0001V4][MemoryManLayout](by-type/by-struct/MemoryManLayout.md)
- [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md)
- [UID:0002B0][0x0069b4fc-0x0069b500.g_pMemoryMan](by-memory/0x0069b4fc-0x0069b500.g_pMemoryMan.md)

## Changes

- 2026-05-30 completion/confidence review:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, and stale caveat text saying active `class_MemoryMan.cpp` only duplicated marker-only `g_pMemoryMan` rows and omitted constructor/accessor lifecycle functions.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:86`, exact storage-page link, current source-map/source evidence, and corrected generated-output caveats.
  - Summary/evidence: exact storage page [UID:0002B0][0x0069b4fc-0x0069b500.g_pMemoryMan](by-memory/0x0069b4fc-0x0069b500.g_pMemoryMan.md), `MemoryMan` file/class docs, [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md), and current `simroot_v2/class_MemoryMan.cpp(.source_map.json)` support the singleton lifecycle and allocator-bootstrap role. Confidence is capped because live IDA was unavailable for this pass and final original source placement/spelling remains reconstructed.
