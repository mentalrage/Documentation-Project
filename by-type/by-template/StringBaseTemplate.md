*** UID:0001WS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StringBase Template

## Status

- Entity kind: inferred C++ template/type family.
- Likely owner header: [UID:0000OA][StringBase](by-file/StringBase.md), [UID:0000OB][StringUtil](by-file/StringUtil.md), or a shared `util/StringUtil.h`.
- Confidence: strong for `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` name evidence; medium for exact declaration and source-file split.
- Evidence basis: generated `FunctionObjectT<mystr::StringBase<...>>` metadata/source, `simroot_v2` `LObject` string helpers, and read-only IDA MCP decompile/caller checks on 2026-05-25.
- Rebuild handling: `source-authored` / `source-declared/generated-binary`; the template/layout semantics must be recreated, but final C++ should wait until all string helper pages and owner files are audited to the final-source gate.

## Declaration Hypothesis

The executable likely contains a small pre-standard or project-local string template in a `mystr` namespace:

```cpp
namespace mystr {

template <class CharT>
struct mychar_traits;

template <class CharT, class Traits = mychar_traits<CharT> >
class StringBase {
public:
    StringBase();
    StringBase(const CharT* text);
    ~StringBase();

    const CharT* c_str() const;
    int Compare(const CharT* rhs) const;

private:
    CharT* m_data;
};

}
```

The exact public API is still provisional. The important recovered layout fact is that field `0x00` is a character-data pointer, not an `LObject` vtable pointer.

## Layout Model

`StringBase` points at character data. Metadata lives immediately before that data:

| Data-relative offset | Meaning |
| --- | --- |
| `-0x0c` | `refCount`, changed with `InterlockedIncrement`/`InterlockedDecrement`. |
| `-0x08` | current character length, excluding the NUL terminator. |
| `-0x04` | capacity / pool bucket size. |
| `0x00` | `char[]` or `wchar_t[]` data. |

Empty ANSI and UTF-16 strings use shared sentinel data pointers. Non-empty strings use 64/128/256/512 fixed-capacity pools where possible and heap allocation for larger buffers.

## Evidence

- Generated class names preserve `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` in two callback-template instantiations: [UID:00005M][FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____](by-class/FunctionObjectT_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t_____.md) and [UID:00005N][FunctionObjectT_near_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t____const___](by-class/FunctionObjectT_near_class_mystr__StringBase_wchar_t__struct_mystr__mychar_traits_wchar_t____const___.md).
- IDA decompilation of `0x0052a460` writes the vtable named `FunctionObjectT<mystr::StringBase<wchar_t,mystr::mychar_traits<wchar_t>>>::vftable`, confirming the type spelling outside the noisy `LObject` generated owner.
- IDA decompilation of `0x00582d80` and `0x00582e30` shows separate ANSI and wide allocation paths with the same `refCount/length/capacity` header and empty sentinels.
- IDA decompilation of `0x00583210` and `0x00583280` shows varargs format constructors for ANSI and wide strings; the wide wrapper seeds `0x00670278`, then calls the wide formatting worker.
- IDA decompilation of `0x005845b0` reads the stored wide length from `m_data[-2]` and compares against a NUL-terminated wide literal through the range comparator at `0x005840f0`.
- [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md) and [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md) record the shared layout and global storage used by the template family.
- 2026-05-31 IDA MCP recheck confirms exact function bounds for the core string helpers: `0x00582d80-0x00582e2c` ANSI allocation, `0x00582e30-0x00582ee2` wide allocation, `0x00583210-0x00583273` ANSI formatting wrapper, `0x00583280-0x005832e3` wide formatting wrapper, `0x005840f0-0x0058415a` range comparator, and `0x005845b0-0x005845ec` wide literal compare helper.
- 2026-05-31 IDA MCP callers show `0x00582d80` and `0x00582e30` are widely reused by local string construction/mutation routines, while `0x00583280` is used from application setup, UI/dialog code, item/mix helpers, and other client code paths; this supports a shared project-local string template rather than a feature-local helper.
- 2026-05-31 IDA decompilation rechecks show the ANSI helper allocates `a2 + 13` bytes for heap-backed buffers and writes the NUL byte at data offset `a2`, while the wide helper allocates `2 * a2 + 14` bytes and writes the NUL word at data offset `a2`. Both set `refCount=1`, `length=a2`, and `capacity` or requested size in the three dwords immediately before the returned data pointer.

## Relationship To Other String Types

- [UID:0000D9][SimpleUString](by-class/SimpleUString.md) may be a typedef, wrapper, or separate utility class over `StringBase<wchar_t>`. The disabled `0x00583210`, `0x00583280`, and `0x005845b0` methods use `SimpleUString` names, while compiler metadata preserves the `mystr::StringBase` template name.
- [UID:0001W5][SimpleUStringSso7Layout](by-type/by-struct/SimpleUStringSso7Layout.md) describes an earlier 24-byte SSO-7 UTF-16 layout at `0x00421310-0x004216cb`. Keep it as a separate representation until a focused pass proves whether it is the same public type, a short-string helper, or another string class.
- [UID:0000KV][LObject](by-file/LObject.md) is not the string type. The generated `LObject` owner is a recovery artifact over two unrelated layout families.

## Cross-References

- [UID:0000OA][StringBase](by-file/StringBase.md)
- [UID:0000OB][StringUtil](by-file/StringUtil.md)
- [UID:0000KV][LObject](by-file/LObject.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md)
- [UID:0001W4][SimpleUStringPointerBackedLayout](by-type/by-struct/SimpleUStringPointerBackedLayout.md)
- [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md)
- [UID:0001J1][0x00582500-0x00583206.LObjectStringConstructionAndCow](by-memory/0x00582500-0x00583206.LObjectStringConstructionAndCow.md)
- [UID:0001J2][0x00583210-0x005845eb.SimpleUStringPointerBacked](by-memory/0x00583210-0x005845eb.SimpleUStringPointerBacked.md)
- [UID:0001J3][0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation.md)
- [UID:0001CQ][0x0052a460-0x0052a49d.FunctionObjectTStringDestructor](by-memory/0x0052a460-0x0052a49d.FunctionObjectTStringDestructor.md)

## Changes

- 2026-05-31 scoring/rebuild update:
  - What existed before: the page documented the pointer-backed `mystr::StringBase` model but had `COMPLETION:0`, `CONFIDENCE:0`, and blank reconstructable metadata.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP `lookup_funcs`, `callers`, and decompilation reconfirm the ANSI/wide allocation helpers, shared `refCount/length/capacity` header, sentinel behavior, formatting wrappers, and wide comparison helper. Scores remain below `95+` because the final original header/API split, all string helper methods, and relationship to `SimpleUString`/SSO-7 representation still need a full audit before final C++ is emitted.
