*** UID:0000D9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UTIL_STRINGUTIL_H
#define NEXUSTK_UTIL_STRINGUTIL_H

#include "LObject.h"

class SimpleUString
{
public:
    SimpleUString();
    ~SimpleUString();

    void Clear();
    SimpleUString& Assign(const wchar_t *source, unsigned int length);
    wchar_t *MutableData()
    {
        return m_capacity > 7 ? m_heapBuffer : m_inlineBuffer;
    }
    const wchar_t *Data() const
    {
        return m_capacity > 7 ? m_heapBuffer : m_inlineBuffer;
    }
    unsigned int Length() const
    {
        return m_length;
    }

private:
    union
    {
        wchar_t m_inlineBuffer[8];
        wchar_t *m_heapBuffer;
    };
    unsigned int m_length;
    unsigned int m_capacity;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SimpleUString

## UID0000IF Ordered Direct-Header Closure - 2026-08-24

- This class is StringUtil H emitter position `0`. Its formal H opens the sole `NEXUSTK_UTIL_STRINGUTIL_H` guard, includes the complete `LObject.h` dependency, and emits the existing 24-byte SSO-7 declaration unchanged.
- The former class-local H `[[CHILDREN]]` placeholder is removed. Exact SimpleUString method definitions remain owned by their existing by-memory children and StringUtil CPP routing; no method body is nested in the header declaration.
- The guard deliberately remains open for UID0000DA position `10`, UID0000E7 position `20`, and UID0000PW position `30`. UID0000PW alone closes it after the external empty-string declaration.
- Ownership UID0000OB, score `90/92`, API, field order, layout, formal CPP, SSO behavior, and all rejected pointer-backed/StringBase alternatives are unchanged. Generated proof requires one guard pair, zero placeholders, and this class before every later StringUtil declaration.

## Status

- Rebuild handling: reconstructable shared string utility class/facade.
- Autogen status: attached to [UID:0000OB][StringUtil](by-file/StringUtil.md) as the broad source owner. The complete accepted SSO-7 class declaration opens the ordered formal H route for `util/StringUtil.h`; formal class CPP is blank because exact method children carry implementations.
- Confidence: very strong for the 24-byte SSO-7 `SimpleUString` class/facade side, its fields and static-instance behavior, and project-owned shared string infrastructure; medium-high for the broader class boundary because the separate pointer-backed public API relationship remains outside this target's scope.
- Important owner caveat: pointer-backed helpers around `0x00583210+` should continue to be reviewed through [UID:0000OA][StringBase](by-file/StringBase.md) / [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md), even though older recovery labels still use `SimpleUString`.

## Summary

`SimpleUString` is shared UTF-16 string infrastructure. Current recovery shows two related surfaces under the same canonical class:

- an early SSO-7 counted wide-string layout at the exact endpoint helpers `0x00421310-0x00421362` and `0x00421590-0x004216cb`, plus the narrow-range-to-wide append helper at `0x00423060-0x00423204`;
- a pointer-backed formatted-string family around `0x00583210`, `0x00583280`, and `0x005845b0`.

The 2026-07-29 UID00027J pass resolves the 24-byte SSO-7 side deterministically for the shared empty global and formal class declaration. It does not collapse the separate pointer-backed family: source migration must preserve that distinction, and [UID:0000OA][StringBase](by-file/StringBase.md) remains its preferred neighboring owner because live IDA name evidence preserves `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` in vtable/RTTI records.

## Representation Map

| Representation | Evidence anchor | Current owner decision | Remaining risk |
| --- | --- | --- | --- |
| SSO-7 UTF-16 string object | [UID:0001W5][SimpleUStringSso7Layout](by-type/by-struct/SimpleUStringSso7Layout.md), [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md), [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md), [UID:0002U5][0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper](by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md), [UID:0000PW][g_emptySimpleUString](by-global/g_emptySimpleUString.md) | Keep under `SimpleUString` / [UID:0000OB][StringUtil](by-file/StringUtil.md). This is the direct class parent for the exact 24-byte layout, and the complete declaration belongs in `StringUtil.h`. | Original lexical class/template spelling remains inferred, but exact fields, default construction, static cleanup, and public project-facing source disposition are implementation-ready. [UID:0002U5][0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper](by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md) stays blank-C++ because it is an internal range/tag append body with an unused third stack argument. |
| Pointer-backed ref-counted string facade | [UID:0001W4][SimpleUStringPointerBackedLayout](by-type/by-struct/SimpleUStringPointerBackedLayout.md), [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md), [UID:0001J2][0x00583210-0x005832f0.StringBaseFormatConstructors](by-memory/0x00583210-0x005832f0.StringBaseFormatConstructors.md) | Treat older `SimpleUString` recovery labels as aliases/leads; prefer [UID:0000OA][StringBase](by-file/StringBase.md) for source migration until the API split is audited. | Final name may be `mystr::StringBase<wchar_t>` rather than `SimpleUString`. |
| Static/global empty string objects | [UID:0000PW][g_emptySimpleUString](by-global/g_emptySimpleUString.md), [UID:00027J][0x0066daec-0x0066db04.g_emptySimpleUString](by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md), [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md) | UID0000PW is externally linked in `StringUtil.cpp`/`.h`; UID00027J is its exact non-duplicating storage. Other static objects retain their own owner pages. | Compiler startup/cleanup bodies are evidence for ordinary construction/destruction and must not be hand-authored as class methods. |

## Likely Original Placement

- Source: [UID:0000OB][StringUtil](by-file/StringUtil.md)
- Proposed path: `util/StringUtil.cpp`, with pointer-backed helpers possibly in `util/StringBase.cpp`
- Confidence: strong for `SimpleUString` and `g_emptySimpleUString` placement; medium-high for the broader family/file split.

## UID00027J Static Instance And Source-ABI Resolution

- [UID:00027J][0x0066daec-0x0066db04.g_emptySimpleUString](by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md) is a concrete exact instance of this 24-byte UTF-16 SSO-7 class side: the union occupies `+0x00..+0x0f`, `m_length` is at `+0x10`, and `m_capacity` is at `+0x14`. Its loader state is zero inline storage, length zero, capacity seven.
- The `0x00419f20` compiler startup wrapper lowers default construction through the shared empty wide literal and a count-zero `Assign`; `0x0060c100` is the paired compiler cleanup that conditionally frees heap storage and restores the empty inline state. Matching [UID:0000Q2][g_metaAliasTableName](by-global/g_metaAliasTableName.md) / [UID:0001OL][0x0066de18-0x0066de30.g_metaAliasTableName](by-memory/0x0066de18-0x0066de30.g_metaAliasTableName.md) lowering supports the existing default constructor and rejects inventing a target-only `const wchar_t *` overload.
- The ABI is compatible with the MSVC/Dinkumware UTF-16 SSO-7 implementation, but the reconstructed project-facing type remains `SimpleUString`. This separates observed layout/toolchain behavior from inferred original lexical source.
- `MutableData()` is a source-facing inline selector already supported by exact child use: it returns heap storage only when capacity exceeds seven and otherwise returns the inline buffer. Parser-only `AssignAnsi`/`c_str` facades remain rejected; this report does not reintroduce them.
- `Data() const` uses the same exact capacity-gated heap/inline selection without exposing mutable storage, and `Length() const` returns the counted length at `+0x10`. CollectionPane's metadata copy and draw paths establish both read-only accessors; they do not justify implicit assignment, `operator==`, or `c_str()` additions.
- Final class CPP is blank. `StringUtil.h` carries the complete declaration at H position `0` without a child placeholder; exact by-memory method children emit definitions through their existing CPP routes. `StringUtil.cpp` carries the bare shared global definition through UID0000PW.

## UID00027J Saved IDA Boundary

- Catalog entry `0360` created exact IDA-only compatibility types `SimpleUStringSso7Storage` (`0x10`) and `SimpleUStringSso7` (`0x18`) and applied the latter to the consolidated `g_emptySimpleUString` data item. IDA's temporary `stru_66DAEC` normalization during consolidation is historical only.
- Existing IDA ordinal 835 `SimpleUString` remains size four and unchanged. Applying it to the 24-byte static object was explicitly rejected; the separate compatibility UDT prevents that IDA modeling error without replacing the project source type.
- Target/member xrefs remain `33/0/0/0/12/12`; object bytes/fences, wrapper ranges/frames/xrefs, broad clear/assign helpers, and shared empty literal remain unchanged. Wrapper names/comments are navigation evidence for compiler lowering, not new source methods.
- Catalog0360's successful UID00027J save for active database `1da2b2ae` is the historical checkpoint SHA256 `03F10207763C01455EA5F767F330A371FEDD9885FBFD98705F5A486985DBE5DA`; prestate backup SHA256 is `08D31FD1C7B80721D6CD7774B42C5A5157B3A4683670A3E27EA5660290554F5A`. The unrelated UID0001HA checkpoint `0E0AF9383DE743CB91E076959498A0D9DAF906C5CA6E620F99425931A09AB481` and later `3C8F31781C94DF74AADDB65B3D944CD2CA4387C448918BBBFFD60B41C3625B69` checkpoint are also historical. Bounded read-only MCP and byte/xref/type readback found no UID00027J drift after the newest shared save; the current authoritative shared IDB is SHA256 `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B`, 143,190,676 bytes, saved `2026-07-29T14:22:15.9735862-04:00`.

## Batch140 SSO Parent-Gate Decision

This class page now clears the corrected `85/85` parent gate for [UID:0001W5][SimpleUStringSso7Layout](by-type/by-struct/SimpleUStringSso7Layout.md). The direct class evidence is narrow but sufficient:

- The SSO endpoint helpers operate on a 24-byte `this` object, not on the pointer-backed ref-counted `data[-3..-1]` storage.
- [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md) proves the `capacity > 7` heap/free gate and reset to the empty inline state.
- [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md) proves counted UTF-16 assignment, growth, terminator writes, and old-heap release using the same fields.
- [UID:0002U5][0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper](by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md) proves a `this`-object SSO-7 narrow-byte-range append/grow helper with the same `+0x10` length, `+0x14` capacity, inline threshold `8`, heap/free support, sign-extended byte-to-UTF-16 writes, and current MCP session `80de0a67` source-quality evidence. It remains a direct class child but not a formal C++ emitter because its exact `retn 0x0c` helper ABI carries an unused third stack argument.
- 2026-06-08 live IDA reconfirmed `0x00421310` as `sub_421310` size `0x52` and `0x00421590` as `sub_421590` size `0x13b`; their callee sets still match the documented free/allocation/memmove/string-too-long behavior.
- [UID:0000OB][StringUtil](by-file/StringUtil.md) is already `86/88` and remains this class page's broad file parent. [UID:0000OA][StringBase](by-file/StringBase.md) is the direct parent for the separate pointer-backed layout, not for this 24-byte SSO object.

## B005 SimpleUString::Clear Formal Method Evidence

2026-06-24 B005 rechecked [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md) with IDA MCP session `80de0a67` against PE SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`. That exact child now carries formal `SimpleUString::Clear()` C++ and score `88/91`.

The method evidence strengthens the SSO-7 side of this class:

- exact `sub_421310` range `0x00421310-0x00421362`, size `0x52`, with 15 bytes of `0xcc` padding before and 14 bytes of `0xcc` padding after before the separate `0x00421370` pane-base thunk;
- body uses the `+0x14` capacity gate, inline threshold `8`, heap pointer/inline-buffer union at `+0x00`, length reset at `+0x10`, capacity reset to `7` at `+0x14`, and an inline UTF-16 NUL write at `+0x00`;
- heap release preserves the caller-side allocation-size calculation `(capacity + 1) * sizeof(wchar_t)`, applies the `0x1000` large-allocation threshold, validates the aligned header using the `0x1f` delta limit, adds `0x23` to the size on the raw-pointer free path, and calls the shared free wrapper at `0x005c7526`;
- callees are limited to `0x005c7526` and `__invalid_parameter_noinfo_noreturn`; current MCP found 83 code xrefs across 22 functions, zero data xrefs, and no absolute VA/RVA pointer pattern route;
- representative caller windows at `0x004231f3`, `0x004cd840`, `0x004d2128`, and `0x00580e68` do not consume a return value, supporting `void SimpleUString::Clear()`.

This does not make the whole class page final-C++-ready. The method name `Clear`, helper spelling `FreeMemory`, and member names `m_heapBuffer`, `m_inlineBuffer`, `m_length`, and `m_capacity` remain source-facing inferences from behavior and local style. Those caveats cap confidence but no longer block the exact child from emitting through this class/file route. The inline duplicate static cleanup at `0x0060c2a0` remains supporting behavior evidence only; it is not a covered-by route or owner.

## Method Families

| Range | Role |
| --- | --- |
| [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md) | Formal-C++-ready `Clear`: frees heap storage when capacity is at least `8`, preserves the caller-side allocation-size/free convention, validates large-allocation headers, and resets the SSO-7 wide string to empty. |
| [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md) | Formal-C++-ready `SimpleUString& Assign(const wchar_t *source, unsigned int length)`: assigns counted UTF-16 input into inline or heap SSO-7 storage, returns `*this`, grows capacity with the `length | 7` and 1.5x policy, and frees old heap storage through the size-aware convention. |
| [UID:0002U5][0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper](by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md) | Non-emitting internal narrow-byte-range to UTF-16 append/grow helper for the SSO-7 object; direct callers are fitting-room catalog conversion and startup update-check conversion. Current B007 callback keeps the exact child at `87/90` with a formal no-standalone-source comment because the body is an internal range/tag append helper with an unused third stack argument, not a stable standalone public method. |
| [UID:0002LJ][0x00583210-0x00583273.StringBaseAnsiFormatCtor](by-memory/0x00583210-0x00583273.StringBaseAnsiFormatCtor.md) | ANSI varargs initializer wrapper, forwards to the ANSI formatting worker. |
| [UID:0002LK][0x00583280-0x005832e3.StringBaseWideFormatCtor](by-memory/0x00583280-0x005832e3.StringBaseWideFormatCtor.md) | Wide varargs initializer wrapper, forwards to the wide formatting worker. |
| [UID:0002LL][0x00583720-0x00583832.StringBaseAnsiVFormatWorker](by-memory/0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md) | ANSI `va_list` formatting worker for the pointer-backed ref-counted buffer. |
| [UID:0002LM][0x00583840-0x00583968.StringBaseWideVFormatWorker](by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md) | UTF-16 `va_list` formatting worker for the pointer-backed ref-counted buffer. |
| [UID:0002LN][0x005840f0-0x0058415a.WideRangeCompare](by-memory/0x005840f0-0x0058415a.WideRangeCompare.md) | Lexicographic UTF-16 range comparator. |
| [UID:0002LO][0x005845b0-0x005845ec.StringBaseCompareWideLiteral](by-memory/0x005845b0-0x005845ec.StringBaseCompareWideLiteral.md) | Compares a stored wide string against a NUL-terminated wide literal. |

## Evidence

- 2026-06-03 live IDA MCP refresh confirms the SSO endpoint helpers as `sub_421310` at `0x00421310-0x00421362` and `sub_421590` at `0x00421590-0x004216cb`. IDA reports 83 callers for the clear/reset helper and 74 callers for the counted wide assignment helper.
- Live IDA decompilation of `0x00421310` shows the SSO-7 reset shape: capacity at `this+0x14`, length at `this+0x10`, inline threshold `7`, heap free through the runtime free helper when capacity is at least `8`, and a final UTF-16 NUL at the object start.
- Live IDA decompilation of `0x00421590` shows the counted wide-copy/grow shape: length compared against capacity, `length | 7` plus 1.5x growth, allocation for `(capacity + 1) * 2` bytes, counted `memmove`, UTF-16 terminator write, and old-heap release only for previous capacities at least `8`.
- 2026-06-08 A006 Batch140 live IDA refresh reconfirmed the endpoint sizes and callee sets: clear size `0x52` with free/invalid-parameter callees, and counted assign size `0x13b` with allocation, `memmove`, string-too-long, free, and invalid-parameter callees.
- 2026-06-10 B001 IDA MCP audit for [UID:0002U5][0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper](by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md) confirms `sub_423060` size `0x1a4`, SSO-7 length/capacity offsets `+0x10/+0x14`, inline threshold `8`, growth through `0x00423d00`, cleanup through `0x00421310`, and two direct callers at `0x00421bc5` and `0x00581d22`.
- 2026-06-24 B003 MCP session `80de0a67` refreshes [UID:0002U5][0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper](by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md) as an exact `0x1a4` / 420-byte helper with SHA16 `7cd41a67bc199b3f`, four-byte predecessor padding, twelve-byte successor padding, 149 instructions, 25 basic blocks, two code refs, zero data refs, no VA/RVA pointer bytes, sign-extended narrow-byte to UTF-16 append behavior, `+0x10/+0x14` length/capacity fields, reserve helper `0x00423eb0`, allocator `0x00423d00`, free wrapper `0x005c7526`, cleanup helper `0x00421310`, and `retn 0x0c`. This supports [UID:0000D9] ownership while keeping the child blank-C++ because the two callers push different unused third stack values.
- 2026-06-24 B005 MCP session `80de0a67` confirms [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md) as an exact `0x52` method with formal `SimpleUString::Clear()` C++: capacity gate at `+0x14`, heap/inline union at `+0x00`, `(capacity + 1) * sizeof(wchar_t)` caller-side deallocation size, large-allocation raw-header validation, free wrapper `0x005c7526`, length/capacity/inline-NUL reset, 83 code xrefs across 22 functions, no data xrefs, and no absolute pointer route.
- 2026-06-24 B003 MCP session `80de0a67` confirms [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md) as an exact `0x13b` / 315-byte method (Verified with `int_convert.py`) with formal `SimpleUString& SimpleUString::Assign(const wchar_t *source, unsigned int length)` C++: SHA16 `2e2b7de08fe03fe5`, twelve-byte predecessor padding, five-byte successor padding, length/capacity at `+0x10/+0x14`, heap/inline union at `+0x00`, return-this normal exits, `length | 7` plus 1.5x growth, `0x7ffffffe` cap, large-allocation `0x1000`/`+0x23`/`0x1f` handling, `_memmove`/`_memmove_0`, `operator new`, `0x005c7526`, `0x0041b6d0`, `__invalid_parameter_noinfo_noreturn`, 74 code xrefs, no data xrefs, and no absolute VA/RVA pointer route.
- Live IDA function inventory across `0x00583210-0x00584d7e` confirms the pointer-backed family is a multi-function string helper island, not a single method. Current container maps split it into [UID:0001J2][0x00583210-0x005832f0.StringBaseFormatConstructors](by-memory/0x00583210-0x005832f0.StringBaseFormatConstructors.md) for the two varargs constructor wrappers and [UID:0001J3][0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md) for the release/format/mutation continuation. The exact child pages now cover the format wrappers/workers, release/capacity helpers, replace/trim/lock helpers, append/find helpers, range compare, literal compare wrapper, and search/splice/substring helpers.
- Live IDA decompilation of `0x00583210` seeds the ANSI empty sentinel `off_670290` before calling `0x00583720`; `0x00583280` seeds the wide sentinel `Src` before calling `0x00583840`. The sentinel xref check found 16 refs to `0x00670290` and 23 refs to `0x00670278`.
- Live IDA name search found many `StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` vtable/RTTI records, including entries around `0x0061fcd4`, `0x0061ff70`, `0x0062004c`, `0x00620094`, and `0x00622cf4`. This strengthens the pointer-backed family's [UID:0000OA][StringBase](by-file/StringBase.md) placement while leaving `SimpleUString` as the cross-linked facade/coordination page.
- `0x00421590` has broad constructor/copy-style caller fan-in from startup, UI/resource helpers, collection dialogs, and other systems.
- The historical [UID:0000WT][0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland](by-memory/0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland.md) page is now an aggregate only. IDA MCP confirms the middle functions are pane/fitting-room/checkbox/runtime helpers, not `SimpleUString` code.
- `0x00583280` has broad caller fan-in from `Application`, startup, patch, browser, sound, virus-checker, and UI helper paths.
- `0x00583210` is used by SoundManager-style track-name formatting paths to build `%08d.MP3` names.
- `0x005845b0` callers include SelfSaveOKPane and WorldMapPane-style compare paths.
- IDA MCP decompilation confirms the pointer-backed formatting workers use the 12-byte ref-counted header described by [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md), including `refCount`, `length`, and `capacity` fields immediately before the data pointer.
- Existing string-family notes keep the SSO-7 wide-string subcluster separate from nearby SSO-15 byte-string helpers. B010 reanalysis of [UID:0002CZ][0x0041d3b0-0x0041d431.SmallStringStorageAssign](by-memory/0x0041d3b0-0x0041d431.SmallStringStorageAssign.md) confirms that helper is MSVC/Dinkumware `std::string`-style byte SSO-15 support with inline threshold `0x10`, one-byte storage, runtime allocation through `0x0041b6e0`, and FittingRoom/JsonCpp/runtime callers; it should not be merged into this UTF-16 SSO-7 class/facade.

## Open Questions

- Whether the early SSO-7 layout and the pointer-backed `StringBase` layout were separate original template instantiations sharing the `SimpleUString` name, or whether the current documentation is collapsing adjacent string classes. This remains an API/split caveat, not a blocker for assigning the SSO layout to this class page.
- Final ownership of the full `0x00582b70-0x005851d9` string helper neighborhood.
- Names for formatting workers at `0x00583720` and `0x00583840`.
- Whether the release/format/mutation continuation at `0x005832f0-0x00584d7e` belongs under this class name or a neighboring string-base type.
- These remaining questions concern the broader pointer-backed family and original lexical organization. They do not reopen the exact SSO-7 fields, UID00027J static-instance source, default constructor, StringUtil.h declaration channel, or pointer-backed-family exclusion resolved above.

## 2026-07-01 B007 Source-Disposition

The formal class declaration is a first-draft source carrier for the exact SSO-7 layout and child placement. Field names are inferred human-source names, but the storage policy is evidence-backed: the inline buffer covers seven usable UTF-16 code units plus terminator space, the `+0x10/+0x14` slots carry length/capacity, and heap storage is used only after the SSO threshold. Pointer-backed `StringBase` bodies remain separate.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `90` | The page now carries the complete SSO-7 class declaration in formal H, blank class CPP, exact endpoint helpers, no-standalone-source narrow append/grow helper, concrete UID00027J static instance, default-constructor/static-cleanup lowering, saved IDA compatibility-type boundary, pointer-backed child inventory, utility placement, and strict owner/source-channel decisions. Completion remains below final-source because the broader public API and remaining pointer-backed continuation ownership still need a whole-family audit. |
| Confidence `92` | Exact helper behavior, concrete loader/runtime/cleanup state, 24-byte compatibility UDT, saved IDA data readback, and StringUtil owner/header route agree on the SSO-7 side. Confidence stays below final because original symbols and the wider SSO-7 versus pointer-backed lexical relationship are not recoverable from this target alone. |

## Cross-References

- File: [UID:0000OB][StringUtil](by-file/StringUtil.md)
- File: [UID:0000OA][StringBase](by-file/StringBase.md)
- Memory: [UID:0000WT][0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland](by-memory/0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland.md), [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md), [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md), [UID:0002U5][0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper](by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md), [UID:0001J2][0x00583210-0x005832f0.StringBaseFormatConstructors](by-memory/0x00583210-0x005832f0.StringBaseFormatConstructors.md), [UID:0001J3][0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md), [UID:0002LJ][0x00583210-0x00583273.StringBaseAnsiFormatCtor](by-memory/0x00583210-0x00583273.StringBaseAnsiFormatCtor.md), [UID:0002LK][0x00583280-0x005832e3.StringBaseWideFormatCtor](by-memory/0x00583280-0x005832e3.StringBaseWideFormatCtor.md), [UID:0002LL][0x00583720-0x00583832.StringBaseAnsiVFormatWorker](by-memory/0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md), [UID:0002LM][0x00583840-0x00583968.StringBaseWideVFormatWorker](by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md), [UID:0002LN][0x005840f0-0x0058415a.WideRangeCompare](by-memory/0x005840f0-0x0058415a.WideRangeCompare.md), [UID:0002LO][0x005845b0-0x005845ec.StringBaseCompareWideLiteral](by-memory/0x005845b0-0x005845ec.StringBaseCompareWideLiteral.md)
- Excluded SSO-15 byte support: [UID:0002CZ][0x0041d3b0-0x0041d431.SmallStringStorageAssign](by-memory/0x0041d3b0-0x0041d431.SmallStringStorageAssign.md), plus sibling compiler/runtime pages [UID:0003GZ][0x0041b300-0x0041b34a.SmallStringStorageReset](by-memory/0x0041b300-0x0041b34a.SmallStringStorageReset.md), [UID:0000WN][0x0041b6d0-0x0041b9a0.MsvcStringSupportHelpers](by-memory/0x0041b6d0-0x0041b9a0.MsvcStringSupportHelpers.md), and [UID:0002UG][0x00423960-0x00423a57.SmallString24AssignCopyHelper](by-memory/0x00423960-0x00423a57.SmallString24AssignCopyHelper.md)
- Related classes: [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md), [UID:0000E7][StringIter](by-class/StringIter.md)
- Layouts: [UID:0001W5][SimpleUStringSso7Layout](by-type/by-struct/SimpleUStringSso7Layout.md), [UID:0001W4][SimpleUStringPointerBackedLayout](by-type/by-struct/SimpleUStringPointerBackedLayout.md), [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md)

## Changes

- 2026-08-16 Agent-B008 UID0003FA accepted callback: preserved the complete SSO-7 declaration and added only inline `Data() const` and `Length() const` beside `MutableData()`. Exact CollectionPane const-read and counted-copy evidence supports these accessors; parser-only `AssignAnsi`/`c_str`, implicit assignment, and comparison operators remain rejected. Score, owner/emitter, object layout, and the separate pointer-backed `StringBase` caveat remain unchanged.
- 2026-07-29 B004 UID00027J ordinary implementation and saved-IDA reconciliation:
  - Raised `89/90 -> 90/92`; owner/emitter `0000OB` and reconstructable state remain unchanged.
  - Moved the exact complete declaration from formal CPP to formal H and left formal CPP blank; preserved the default constructor, `Clear`, counted-wide `Assign`, `MutableData`, private SSO fields, and `[[CHILDREN]]`.
  - Added concrete UID00027J loader/startup/cleanup proof, matching sibling default-constructor lowering, project-facade versus compatible ABI distinction, rejection of a target-only wide-literal overload and the size-four IDA UDT, catalog0360 compatibility-type/data results, and durable saved-IDB evidence.
- 2026-07-01 B007 [UID:0000OB][StringUtil](by-file/StringUtil.md) implementation callback: raised score to `88/88`, inserted the accepted `SimpleUString` formal class declaration with `[[CHILDREN]]`, updated stale blank-C++ status, and preserved SSO-7 versus pointer-backed `StringBase` ownership caveats.
- 2026-06-24 B003 [UID:0002U5][0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper](by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md) source-quality support sync:
  - Changed to: support wording only; scores remain `85/87`.
  - Summary/evidence: recorded that the exact [UID:0002U5][0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper](by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md) child is now `87/90` under MCP session `80de0a67` with direct [UID:0000D9][SimpleUString](by-class/SimpleUString.md) owner/emitter and broad [UID:0000OB][StringUtil](by-file/StringUtil.md) source route. Evidence confirms exact `0x1a4` / 420-byte range, SHA16 `7cd41a67bc199b3f`, padding, two code refs (`0x00421bc5`, `0x00581d22`), zero data refs, no VA/RVA pointer route, SSO-7 field offsets, sign-extended narrow-to-wide append/grow behavior, reserve/allocator/free/cleanup helpers, and rejected fitting-room/startup-local, `StringBase`, runtime/MSVC, mixed-aggregate, no-owner, formal `AssignAnsi`, stale helper-name, and decompiler-label alternatives. The class-level block remains blank and [UID:0002U5][0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper](by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md) also remains blank-C++ because the exact helper has an unused third stack argument; sibling children [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md) and [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md) are the current formal C++ emitters.
- 2026-06-21 B010 Rule 26 SSO-15 exclusion: Scores unchanged. Added explicit evidence that [UID:0002CZ][0x0041d3b0-0x0041d431.SmallStringStorageAssign](by-memory/0x0041d3b0-0x0041d431.SmallStringStorageAssign.md) and sibling SSO-15 byte-string helpers are compiler/runtime `std::string` support, not `SimpleUString` source. This preserves the distinction between this class's UTF-16 SSO-7 representation and byte-string SSO-15 helper machinery.
- 2026-06-10 B001-005 split-gate update: added [UID:0002U5][0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper](by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md) as a direct `SimpleUString` SSO-7 method child. Evidence: IDA MCP confirms the exact `0x1a4` function, SSO-7 `this` layout, startup plus fitting-room caller spread, and string-support callees; the child now clears `85/88`, this class clears `85/87`, and [UID:0000OB][StringUtil](by-file/StringUtil.md) remains the broad file parent at `87/88`.
- 2026-06-03: Raised completion/confidence from `70/82` to `78/86`.
  - Summary/evidence: live IDA MCP reconfirmed the SSO endpoint helpers at `0x00421310-0x00421362` and `0x00421590-0x004216cb`, including 83/74 caller counts and decompiled SSO-7 clear/assign behavior; it also confirmed the pointer-backed `0x00583210-0x00584d7e` family as a multi-function string helper island with ANSI/wide sentinel use and `StringBase<wchar_t>` vtable/RTTI name evidence. Later Agent-C001 range cleanup split the old broad pointer-backed map into [UID:0001J2][0x00583210-0x005832f0.StringBaseFormatConstructors](by-memory/0x00583210-0x005832f0.StringBaseFormatConstructors.md) and [UID:0001J3][0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md). The page now explains that `SimpleUString` is the coordination/facade page while pointer-backed source placement remains with `StringBase`. The class-level C++ block stays blank because the full public API and representation relationship remain broader than this class page, while exact method children can emit when their own current combined-score/emitter evidence supports it.
- 2026-06-02: Raised the class page to `70/82`, attached it to [UID:0000OB][StringUtil](by-file/StringUtil.md), and added status, representation map, autogen rationale, and score rationale. Final C++ remains blank because the `SimpleUString` versus `StringBase` API split is unresolved.

- 2026-05-30: Existing class summary treated `0x00421310-0x004216cb` as one early `SimpleUString` helper neighborhood. Changed this to endpoint-only `SimpleUString` ownership and linked the exact child pages, while retaining the historical aggregate as a mixed-island map. Evidence: IDA MCP function inventory/decompilation/byte audit for `0x00421310-0x004216cb`.

- 2026-05-31: The pointer-backed family now links exact IDA-confirmed child pages for the formatting constructors/workers and wide compare helpers.
  - Before: the class page listed only raw address rows for the pointer-backed family and left reconstructable metadata blank.
  - After: marked the class reconstructable, linked exact split memory pages, and raised scores modestly to reflect verified boundaries and behavior.
  - Evidence: IDA MCP `lookup_funcs`, `decompile`, `callers`, `callees`, sentinel `xrefs_to`, and byte checks for `0x00583210`, `0x00583280`, `0x00583720`, `0x00583840`, `0x005840f0`, and `0x005845b0`.
- 2026-06-03: refreshed the formatting-worker links to corrected half-open ranges `0x00583720-0x00583832` and `0x00583840-0x00583968`.
- 2026-06-08 A006 Batch140 SSO parent-gate update:
  - Before: `COMPLETION:78`, `CONFIDENCE:86`.
  - After: `COMPLETION:85`, `CONFIDENCE:87`.
  - Summary/evidence: added a focused parent-gate section for [UID:0001W5][SimpleUStringSso7Layout](by-type/by-struct/SimpleUStringSso7Layout.md), live IDA endpoint refresh for the clear and counted-assign helpers, and explicit exclusion of [UID:0000OA][StringBase](by-file/StringBase.md) as the SSO layout's direct owner. Final C++ remains blank because the broader public API and representation split are not final-source quality.
- 2026-06-24 B005 [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md) source-quality support sync:
  - Changed to: support wording only; scores remain `85/87`.
  - Summary/evidence: recorded that the exact [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md) child is now `88/91` with formal `SimpleUString::Clear()` C++ under MCP session `80de0a67`. The child evidence confirms exact range/padding, SSO-7 field names, caller-side allocation-size/free behavior, large-allocation header validation, 83 code xrefs across 22 functions, zero data xrefs, no pointer-route ownership, and representative void-call windows. The class-level block remains blank because only the exact child, not the complete class declaration, cleared first-draft C++ readiness.
- 2026-06-24 B003 [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md) source-quality support sync:
  - Changed to: support wording only; scores remain `85/87`.
  - Summary/evidence: recorded that the exact [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md) child is now `88/90` with formal `SimpleUString& SimpleUString::Assign(const wchar_t *source, unsigned int length)` C++ under MCP session `80de0a67`. The child evidence confirms exact range/padding, SSO-7 field names, return-this assignment shape, old heap release, 74 code xrefs, zero data xrefs, no VA/RVA pointer route, allocator/memmove/free/string-too-long/invalid-parameter callees, and rejected `StringBase`, caller-local, runtime/MSVC, constructor, `void`, and mixed-aggregate ownership alternatives. The class-level block remains blank because only exact method children, not the complete class declaration/API split, have cleared first-draft C++ readiness.

## 2026-07-23 B004 Accepted UID0002E6 Reconciliation (0000D9)

- Accepted source: B004 UID0002E6 report, Gate 1 SHA F8FE25AA9AD6922244A4C7EC84D390D41DE9782819D15DCD6D192A58C1D7EF26.
- The complete SSO-7 declaration now exposes only the observed inline MutableData selector. Parser-only AssignAnsi/c_str facades remain rejected; the separate pointer-backed StringBase family remains distinct.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C2E6-050 | 0002E4 | The implemented parser formal replaces unsupported parser-side `SimpleUString::AssignAnsi`/parser-side `SimpleUString::c_str` with `std::wstring` range construction and valid `std::wstring::c_str()`, copies each nested Json value, and avoids value-initializing natural padding; scoped validation confirms current `90/91`. This does not reject UID0002DL's valid paint-time SimpleUString use. | Strong | Live parser/helper decompilation, current UID0000D9 formal, C++03 string route, scoped validator result, and command16927 readback. | UID0002E4 formal/prose/metadata. | reject-stale | implemented-verified |
| C2E6-057 | 0002E4 | Helper 0x00423060 is compiler/container range-construction lowering for the 24-byte SSO-7 wide temporary; the source expression is `std::wstring(itemName.begin(), itemName.end())`, not an invented project API. | Strong | Helper body, two callers, runtime diagnostics, and missing UID0000D9 methods. | UID0002E4 formal/history; UID000051 includes. | reject-stale | implemented |
| C2E6-078 | 0000D9 | UID0002DL's SSO-7 `SimpleUString itemName` and wide `Assign` are valid; inline `MutableData()` selects heap storage when capacity exceeds seven and otherwise the inline buffer. Parser-only `AssignAnsi`/`c_str` remain rejected. | Strong | UID0002DL call/storage selection, UID0000D9 exact 24-byte layout and Assign endpoint. | UID0000D9 complete formal/prose/metadata; UID0000OB/UID0002DL support. | incorporate | implemented |
| C2E6-080 | 0002DL | UID0002DL retains `SimpleUString` and exact text wrapping while consuming UID000053 grid constants and UID0000D9 `MutableData`; generated postcondition is zero unsupported parser facade, not zero SimpleUString. | Strong | Existing full paint formal and live generated/source evidence. | UID0002DL formal/prose/manual row/checklist. | incorporate | implemented |
| C2E6-081 | 0002E6 | Current manual coverage roots advanced during repair and must be identified by current hashes while preserving all 43 no-loss handoffs, including UID0000D9/UID0000OB, three explicit companion-header routes, and ten direct-dependency destination rows. | Certain | Read-only current manual-root hashes/anchors. | Exact Manual Supervisor-Owned Coverage Or Tracker Text. | incorporate | implemented |
| C2E6-087 | 0000OB | `NexusTK/util/StringUtil.h` is already explicitly documented by UID0000OB and is the exact home for complete UID0000D9; FittingRoomListPane consumes that route without another header declaration. | Strong | UID0000OB Status/Proposed header and UID0000D9 formal. | UID000053/UID0000D9 dependency evidence; no duplicate ordinary header change. | already-present | implemented |
| C2E6-098 | 0002E4 | Generated postcondition must require zero parser-side `SimpleUString::AssignAnsi` and zero parser-side `SimpleUString::c_str` facade while explicitly allowing and requiring the proposed `std::wstring::c_str()` call. | Certain | UID0002E4 proposed standard string object and UID0000D9 API inventory. | Validator Results/checklist/generated readback. | incorporate | implemented |
