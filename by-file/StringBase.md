*** UID:0000OA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# StringBase

## Status

- Proposed module: `util/StringBase.cpp`
- Proposed header: `util/StringBase.h` or `util/StringUtil.h`
- Confidence: medium for final source-file name, strong for separating this implementation from the true `LObject` runtime shell.
- Current generated sources: the string-buffer subset of `source-3/simroot_v2/class_LObject.cpp` plus disabled `SimpleUString` wrappers in `source-3/simroot_v2/class_SimpleUString.cpp.disabled`.
- Primary template/type doc: [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md)
- Evidence basis: `simroot_v2` metadata/source and read-only IDA MCP lookup, decompile, and caller checks on 2026-05-25. `wave3.py` was not executed for this pass.

## File Role

This is the preferred source-structure home for the ref-counted ANSI/UTF-16 string implementation currently emitted under [UID:0000KV][LObject](by-file/LObject.md). The generated owner is polluted: the real `LObject` class is a tiny virtual base/runtime object, while the string methods use field `0x00` as a character-data pointer with a 12-byte header immediately before it.

The original project may have put this in `StringUtil.cpp`, but the recovered template type name `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` is strong enough to track a dedicated `StringBase` module candidate.

## Likely Contents

| Entity | Address/range | Role |
| --- | --- | --- |
| `mystr::StringBase<char, mystr::mychar_traits<char>>` helpers | `0x00582500-0x00583206`, selected `0x005832f0+` methods | ANSI construction, assignment, copy-on-write, allocation, release, append, formatting, and mutation helpers. |
| `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` helpers | `0x00582500-0x00584d7d`, especially `0x00583280`, `0x00583840`, `0x005840f0`, `0x005845b0` | UTF-16 construction, formatting, comparison, search, splice, trim, and substring helpers. |
| [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md) | data pointer `-0x0c` through `-0x04` | Shared header with `refCount`, `length`, and `capacity`. |
| [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md) | `0x00670278`, `0x00670290`, `0x0069bacc-0x0069bbe4` | Empty-string sentinels and 64/128/256/512 fixed-capacity pools for wide and ANSI buffers. |
| pointer-backed formatting wrappers/workers | [UID:0002LJ][0x00583210-0x00583272.StringBaseAnsiFormatCtor](by-memory/0x00583210-0x00583272.StringBaseAnsiFormatCtor.md), [UID:0002LK][0x00583280-0x005832e2.StringBaseWideFormatCtor](by-memory/0x00583280-0x005832e2.StringBaseWideFormatCtor.md), [UID:0002LL][0x00583720-0x00583831.StringBaseAnsiVFormatWorker](by-memory/0x00583720-0x00583831.StringBaseAnsiVFormatWorker.md), [UID:0002LM][0x00583840-0x00583967.StringBaseWideVFormatWorker](by-memory/0x00583840-0x00583967.StringBaseWideVFormatWorker.md) | ANSI/UTF-16 format constructors and `va_list` workers; likely `StringBase<char/wchar_t>` helpers or a thin string facade over them. |
| pointer-backed compare helpers | [UID:0002LN][0x005840f0-0x00584159.WideRangeCompare](by-memory/0x005840f0-0x00584159.WideRangeCompare.md), [UID:0002LO][0x005845b0-0x005845eb.StringBaseCompareWideLiteral](by-memory/0x005845b0-0x005845eb.StringBaseCompareWideLiteral.md) | UTF-16 range comparator and literal compare wrapper. |
| [UID:000236][0x005151b0-0x005151ef.DefaultCodepageConversionWrappers](by-memory/0x005151b0-0x005151ef.DefaultCodepageConversionWrappers.md) | `0x005151b0`, `0x005151d0` | Thin default-codepage conversion wrappers consumed by the string constructors/converters. |

## Evidence

- `class_LObject.meta_wave3` explicitly warns that Ghidra/Wave3 merged a true virtual base class with a reference-counted string class; this file records the source-structure consequence of that warning.
- IDA decompilation of `0x004f4a80` is a 9-byte constructor that writes only `LObject::vftable`, while IDA decompilation of `0x00582d80` and `0x00582e30` writes a data pointer, allocates an inline header, stores `refCount`, `length`, and `capacity`, and returns `header + 0x0c`.
- IDA decompilation of `0x00583210` seeds the object with the ANSI empty sentinel `0x00670290` and forwards to the ANSI formatting worker at `0x00583720`.
- IDA decompilation of `0x00583280` seeds the object with the wide empty sentinel `0x00670278` and forwards to the wide formatting worker at `0x00583840`.
- Exact split pages now document the two constructor wrappers, the ANSI/UTF-16 formatting workers, the UTF-16 range comparator, and the literal comparison wrapper. These were verified with IDA MCP `lookup_funcs`, `decompile`, `callers`, `callees`, sentinel xrefs, and byte-level padding checks on 2026-05-31.
- IDA decompilation of `0x005833a0` releases wide storage through `InterlockedDecrement`, returns 64/128/256/512 buckets to the matching pool globals, and otherwise heap-frees the 12-byte-prefixed allocation.
- IDA decompilation of `0x005845b0` compares `this->m_data` to a wide literal by reading the stored length from `m_data[-2]` and forwarding to the range comparator at `0x005840f0`.
- IDA decompilation of `0x0052a460` resets a callback object's vtable to `FunctionObjectT<mystr::StringBase<wchar_t,mystr::mychar_traits<wchar_t>>>::vftable`, preserving the `mystr::StringBase` type spelling in compiler metadata.
- Caller checks show `0x00583280` has broad fan-in from application initialization, browser/path helpers, UI, audio, and security integration. This breadth supports utility-string ownership, not any one feature module.

## Exclusions

- Keep [UID:0000KV][LObject](by-file/LObject.md) limited to the runtime/base shell around `0x004f4a80-0x004f4c0d`.
- Keep FolderTreePane traversal callbacks around `0x004b3400-0x004b3d41` with [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), not with this file.
- Keep `FunctionObjectT<mystr::StringBase<...>>` destructor support with [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md). The string type parameter is evidence for the string type name, not ownership of callback template code.
- Keep the early SSO-7 layout at `0x00421310-0x004216cb` under [UID:0000OB][StringUtil](by-file/StringUtil.md) / [UID:0000D9][SimpleUString](by-class/SimpleUString.md) until a later pass proves whether it is a separate string class or another `StringBase` representation.

## Migration Notes

For Wave3/source reconstruction, do not bulk-migrate `class_LObject.cpp`. A safer target split is:

```text
util/LObject.cpp
  LObject virtual base/runtime shell only

util/StringBase.cpp
  0x00582500-0x00584d7d ref-counted ANSI/UTF-16 string-buffer family

util/PoolAllocator.cpp
  fixed-block allocator mechanics used by StringBase pool globals

ui/controls/FolderTreePane.cpp
  tree traversal/search callbacks currently misattributed to LObject
```

The final header can still collapse into `StringUtil.h` if later original-source evidence favors a flatter utility-string file, but source migration should treat `StringBase` as the preferred owner for the `0x00582500+` family.

## Cross-References

- [UID:0000OB][StringUtil](by-file/StringUtil.md)
- [UID:0000KV][LObject](by-file/LObject.md)
- [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md)
- [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md)
- [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md)
- [UID:0001W4][SimpleUStringPointerBackedLayout](by-type/by-struct/SimpleUStringPointerBackedLayout.md)
- [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md)
- [UID:0001J1][0x00582500-0x00583206.LObjectStringConstructionAndCow](by-memory/0x00582500-0x00583206.LObjectStringConstructionAndCow.md)
- [UID:0001J2][0x00583210-0x005845eb.SimpleUStringPointerBacked](by-memory/0x00583210-0x005845eb.SimpleUStringPointerBacked.md)
- [UID:0002LJ][0x00583210-0x00583272.StringBaseAnsiFormatCtor](by-memory/0x00583210-0x00583272.StringBaseAnsiFormatCtor.md)
- [UID:0002LK][0x00583280-0x005832e2.StringBaseWideFormatCtor](by-memory/0x00583280-0x005832e2.StringBaseWideFormatCtor.md)
- [UID:0002LL][0x00583720-0x00583831.StringBaseAnsiVFormatWorker](by-memory/0x00583720-0x00583831.StringBaseAnsiVFormatWorker.md)
- [UID:0002LM][0x00583840-0x00583967.StringBaseWideVFormatWorker](by-memory/0x00583840-0x00583967.StringBaseWideVFormatWorker.md)
- [UID:0002LN][0x005840f0-0x00584159.WideRangeCompare](by-memory/0x005840f0-0x00584159.WideRangeCompare.md)
- [UID:0002LO][0x005845b0-0x005845eb.StringBaseCompareWideLiteral](by-memory/0x005845b0-0x005845eb.StringBaseCompareWideLiteral.md)
- [UID:0001J3][0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation.md)
- [UID:000236][0x005151b0-0x005151ef.DefaultCodepageConversionWrappers](by-memory/0x005151b0-0x005151ef.DefaultCodepageConversionWrappers.md)
- [UID:0001CQ][0x0052a460-0x0052a49d.FunctionObjectTStringDestructor](by-memory/0x0052a460-0x0052a49d.FunctionObjectTStringDestructor.md)
- [UID:0001QS][client_string_handling](by-meta/client_string_handling.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `86` and confidence to `78`.
  - Evidence: document captures the polluted `LObject` split, likely string-template contents, ref-counted buffer layout, sentinel/pool globals, IDA decompilation evidence, exclusions, migration split, and cross-references; confidence is capped by final source-file name and unresolved relationship to the earlier SSO/string utility representation.

- 2026-05-31: Added exact pointer-backed formatting/compare child pages and projected the file to `NexusTK/util/`.
  - Before: pointer-backed wrappers were listed only as raw addresses and the validator-managed projected reconstruction path was blank.
  - After: linked exact child memory pages, raised scores modestly to `88/80`, and set `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"` so the validator stages an empty `StringBase.cpp`.
  - Evidence: IDA MCP verification of `0x00583210`, `0x00583280`, `0x00583720`, `0x00583840`, `0x005840f0`, and `0x005845b0`; final C++ remains intentionally blank because the family is below the `95+` reconstruction-code gate.
