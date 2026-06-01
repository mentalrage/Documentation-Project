*** UID:0000OB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:64 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# StringUtil

## Status

- Proposed module: `util/StringUtil.cpp`
- Proposed header: `util/StringUtil.h`
- Preferred companion module: [UID:0000OA][StringBase](by-file/StringBase.md) for the ref-counted `mystr::StringBase` family.
- Confidence: medium for exact source-file split, strong for utility ownership.
- Current recovered sources: `class_SimpleUString.cpp`, `class_SimpleUStringVector.cpp`, `class_StringIter.cpp`, and the string-heavy subset of `class_LObject.cpp`

## File Role

`StringUtil.cpp` is the current working owner for shared client string infrastructure: the `SimpleUString` UTF-16 string helper, the vector container that stores contiguous 4-byte pointer-backed string-handle slots, the small `StringIter` character iterator used by text parsing/render helpers, and coordination with the ref-counted ANSI/UTF-16 [UID:0000OA][StringBase](by-file/StringBase.md) family currently emitted under [UID:0000KV][LObject](by-file/LObject.md).

This is utility code. It is referenced from application startup, DAT/resource loading, UI text, sound track-name formatting, patch/profile/config helpers, browser paths, and map/world UI. It should not be owned by any single caller module.

## Likely Contents

- [UID:0000D9][SimpleUString](by-class/SimpleUString.md)
- [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md)
- [UID:0000E7][StringIter](by-class/StringIter.md)
- [UID:0000OA][StringBase](by-file/StringBase.md) ref-counted string-buffer helpers, currently emitted as [UID:00007D][LObject](by-class/LObject.md) methods
- [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md), if final owner review keeps the fixed-block string pools as a separate utility file
- SSO-7 wide-string layout endpoint helpers [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md) and [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md)
- [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md)
- [UID:000236][0x005151b0-0x005151ef.DefaultCodepageConversionWrappers](by-memory/0x005151b0-0x005151ef.DefaultCodepageConversionWrappers.md)
- pointer-backed varargs format helpers around `0x00583210`, `0x00583280`, `0x00583720`, and `0x00583840`
- range comparison helpers around `0x005840f0` and `0x005845b0`

The generated `FunctionObjectT<mystr::StringBase<...>>` classes are template/deleting-destructor support for [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), not primary `StringUtil.cpp` ownership proof. Keep them under [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md) unless caller evidence ties a construction site to this file.

## Evidence

- `SimpleUString` metadata states the import source as `SimpleUString.cpp` and documents UTF-16 SSO-7 endpoint helpers at `0x00421310` and `0x00421590`.
- IDA confirms the historical `0x00421310-0x004216cb` page is a mixed helper island. Only [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md) and [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md) belong to the early wide-string layout; the middle contains pane, fitting-room, checkbox, generated thunk, and runtime/vector helpers.
- `class_LObject.meta_wave3` warns that its generated owner merges a true virtual base object with a reference-counted string class; IDA confirms the string prefix at `0x00582500-0x00583206`.
- IDA confirms pointer-backed `SimpleUString` wrappers at `0x00583210`, `0x00583280`, and `0x005845b0`, with broad caller fan-in.
- IDA confirms `0x0052a460` writes a vtable named `FunctionObjectT<mystr::StringBase<wchar_t,mystr::mychar_traits<wchar_t>>>::vftable`, preserving the `StringBase` template name outside the generated `LObject` owner.
- `SimpleUStringVector` destructor at `0x00493f10`, grow/insert at `0x0049cc40`, and push-back at `0x00584910` prove a begin/end/capacity vector of 4-byte pointer-backed string-handle slots.
- `StringIter` methods at `0x00584d80`, `0x00584df0`, `0x00584e40`, and `0x00584e60` form a small `LObject`-derived iterator over wide-character data.
- IDA confirms empty string sentinels at `0x00670278` and `0x00670290`, plus eight `PoolAllocator` globals at `0x0069bacc-0x0069bbe4`, are used by the `0x00582d80`, `0x00582e30`, `0x005832f0`, and `0x005833a0` string allocation/release helpers.

## Generated Output Caveats

- Active `class_SimpleUString.cpp` omits real disabled methods `SimpleUString_from_char` at `0x00583210`, `SimpleUString_from_wchar` at `0x00583280`, and `CompareWide` at `0x005845b0`.
- `SimpleUStringVector::GrowAndInsert` metadata ends at `0x0049ce23`, while IDA reports start `0x0049cc40` size `0x209`, making `0x0049ce48` the last executable byte.
- Active `class_StringIter.cpp` emits a constructor at `0x00584dc0`, but IDA reports `0x00584dc0` is not a function. Treat it as a projected/manual boundary until raw disassembly confirms a real constructor slice.
- Active `class_LObject.cpp` contains real string code but also includes FolderTreePane traversal callbacks and historical `m_vtable`/`vftptr_0x0` naming pollution where the field is actually a string data pointer.
- Historical string metadata includes stale owner projections for unrelated byte-string/small-string helpers. Do not merge the SSO-15 byte-string family into `SimpleUString` without a separate layout pass.

## Source-Structure Decision

Use `util/StringUtil.cpp` as the broad utility-string coordination module, but prefer [UID:0000OA][StringBase](by-file/StringBase.md) / `util/StringBase.cpp` as the first migration target for the `0x00582500-0x00584d7d` ref-counted ANSI/UTF-16 buffer implementation. A later split into `SimpleUString.cpp`, `SimpleUStringVector.cpp`, and `StringIter.cpp` is plausible if original-source evidence appears, but the proposed tree currently benefits from one shared utility-string family plus the explicit `StringBase` owner candidate.

Keep [UID:0000KV][LObject](by-file/LObject.md) as the runtime/base object only. Do not move FolderTreePane callbacks into this module.

## Cross-References

- [UID:0000D9][SimpleUString](by-class/SimpleUString.md)
- [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md)
- [UID:0000E7][StringIter](by-class/StringIter.md)
- [UID:00007D][LObject](by-class/LObject.md)
- [UID:0000OA][StringBase](by-file/StringBase.md)
- [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md)
- [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md)
- [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md)
- [UID:0001J1][0x00582500-0x00583206.LObjectStringConstructionAndCow](by-memory/0x00582500-0x00583206.LObjectStringConstructionAndCow.md)
- [UID:0001J3][0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation.md)
- [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md)
- [UID:0000WT][0x00421310-0x004216cb.SimpleUStringSso7](by-memory/0x00421310-0x004216cb.SimpleUStringSso7.md)
- [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md)
- [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md)
- [UID:0001J2][0x00583210-0x005845eb.SimpleUStringPointerBacked](by-memory/0x00583210-0x005845eb.SimpleUStringPointerBacked.md)
- [UID:000236][0x005151b0-0x005151ef.DefaultCodepageConversionWrappers](by-memory/0x005151b0-0x005151ef.DefaultCodepageConversionWrappers.md)
- [UID:000112][0x00493f10-0x00493f79.SimpleUStringVectorDestructor](by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md)
- [UID:00012G][0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert](by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md)
- [UID:0001J4][0x00584910-0x0058498b.SimpleUStringVectorPushBack](by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md)
- [UID:0001J5][0x00584d80-0x00584e9e.StringIter](by-memory/0x00584d80-0x00584e9e.StringIter.md)
- [UID:0001QS][client_string_handling](by-meta/client_string_handling.md)
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)

## Changes

- 2026-05-30: Existing evidence described `0x00421310-0x004216cb` as a compact early wide-string helper neighborhood. Changed this to endpoint-only `SimpleUString`/`StringUtil` ownership and kept the full range as a mixed aggregate map. Evidence: IDA MCP function inventory/decompilation/byte audit for `0x00421310-0x004216cb`; `simroot_v2/class_SimpleUString.cpp` emits only the `0x00421310` and `0x00421590` helpers from that island.

- 2026-05-31: Updated the `SimpleUStringVector` model and projected path.
  - Before: the page described the vector as contiguous `SimpleUString` elements and left `PROPOSED_RECONSTRUCTION_PATH` blank.
  - After: documented the 4-byte pointer-backed string-handle slot model, corrected linked vector helper ranges, raised scores to `64/80`, and set `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`.
  - Evidence: IDA MCP decompilation of `0x00493f10`, `0x0049cc40`, and `0x00584910`; `proposed-source-tree.md` already lists `util/StringUtil.cpp`.
