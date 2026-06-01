*** UID:0001QS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client String Handling

## Scope

This page tracks client-level string utility findings. Source ownership lives in [UID:0000OB][StringUtil](by-file/StringUtil.md); exact address evidence lives in `by-memory`.

## Current Model

- [UID:0000D9][SimpleUString](by-class/SimpleUString.md) is the canonical recovered string utility, but current evidence shows two representation surfaces that need reconciliation: an SSO-7 UTF-16 layout and a pointer-backed formatted-string layout.
- [UID:0000OA][StringBase](by-file/StringBase.md) is now the preferred source-structure candidate for the large generated ANSI/UTF-16 ref-counted string-buffer family at `0x00582500-0x00584d7d`.
- [UID:00007D][LObject](by-class/LObject.md) currently owns that family in generated output. Treat this as string-base evidence, not proof that the same C++ type was also the true virtual base object.
- [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md) records the `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` compiler metadata preserved through callback-template vtables.
- [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md) tracks the empty ANSI/wide sentinels at `0x00670278` and `0x00670290` plus the eight fixed-capacity string pools at `0x0069bacc-0x0069bbe4`.
- [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md) is the fixed-block allocator used by those pool globals.
- [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md) is a begin/end/capacity vector of 4-byte pointer-backed string-handle slots.
- [UID:0000E7][StringIter](by-class/StringIter.md) iterates UTF-16 character data and is used by text parsing/render helpers.
- [UID:0000PW][g_emptySimpleUString](by-global/g_emptySimpleUString.md) tracks the 24-byte empty `SimpleUString` fallback at `0x0066daec`, currently returned by metadata lookup helpers and read by other UI/help paths.
- The generated `FunctionObjectT<mystr::StringBase<...>>` files are [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) template/deleting-destructor support, not string utility source modules. See [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md).

## Important Caveats

- `SimpleUString` active output omits real disabled methods at `0x00583210`, `0x00583280`, and `0x005845b0`.
- `SimpleUStringVector::GrowAndInsert` has an IDA-confirmed last executable byte at `0x0049ce48`, but generated metadata appears to end earlier.
- `StringIter` active output includes a projected constructor at `0x00584dc0` that IDA does not define as a function.
- Older reports warn against merging unrelated SSO-15 byte-string helpers into `SimpleUString`.
- `class_LObject.cpp` is polluted with FolderTreePane callbacks and historical `m_vtable`/`vftptr_0x0` naming over a string data pointer.
- The preferred source split is now `util/LObject.cpp` for the virtual base shell and `util/StringBase.cpp` for the ref-counted string-buffer implementation, while keeping the SSO-7 `SimpleUString` representation under review.

## Cross-References

- [UID:0000OB][StringUtil](by-file/StringUtil.md)
- [UID:0000OA][StringBase](by-file/StringBase.md)
- [UID:0000KV][LObject](by-file/LObject.md)
- [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md)
- [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md)
- [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md)
- [UID:0000PW][g_emptySimpleUString](by-global/g_emptySimpleUString.md)
- [UID:0001J1][0x00582500-0x00583206.LObjectStringConstructionAndCow](by-memory/0x00582500-0x00583206.LObjectStringConstructionAndCow.md)
- [UID:0001J3][0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation.md)
- [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md)
- [UID:0000WT][0x00421310-0x004216cb.SimpleUStringSso7](by-memory/0x00421310-0x004216cb.SimpleUStringSso7.md)
- [UID:0001J2][0x00583210-0x005845eb.SimpleUStringPointerBacked](by-memory/0x00583210-0x005845eb.SimpleUStringPointerBacked.md)
- [UID:000112][0x00493f10-0x00493f79.SimpleUStringVectorDestructor](by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md)
- [UID:00012G][0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert](by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md)
- [UID:0001J4][0x00584910-0x0058498b.SimpleUStringVectorPushBack](by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md)
- [UID:0001J5][0x00584d80-0x00584e9e.StringIter](by-memory/0x00584d80-0x00584e9e.StringIter.md)
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
