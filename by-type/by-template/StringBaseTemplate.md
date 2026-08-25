*** UID:0001WS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UTIL_STRINGBASE_H
#define NEXUSTK_UTIL_STRINGBASE_H

namespace mystr
{
template <class CharT>
struct mychar_traits;

template <class CharT, class Traits = mychar_traits<CharT> >
class StringBase
{
public:
    StringBase();
    StringBase(const CharT *text);
    StringBase(const StringBase& other);
    template <class OtherCharT, class OtherTraits>
    StringBase(const StringBase<OtherCharT, OtherTraits>& other);
    ~StringBase();

    StringBase& operator=(const StringBase& other);
    StringBase& operator=(const CharT *text);

    const CharT *c_str() const;
    CharT *data();
    StringBase ToLower() const;
    void DetachAnsiIfShared();
    unsigned int length() const;
    bool empty() const;
    StringBase& AppendWideLiteral(const wchar_t *source, unsigned int maxCount);
    int CompareWideLiteral(const wchar_t *literal) const;
    int FindLastOf(const wchar_t *chars, unsigned int start, unsigned int charCount) const;
    int FindLastNotOf(const wchar_t *chars, unsigned int start, unsigned int charCount) const;
    StringBase& SubstringWide(StringBase& out, unsigned int start, unsigned int count) const;
    long ToLong() const;
    int FormatWide(const wchar_t *format, ...);
    StringBase& InitializeWideFromRange(const wchar_t *first, const wchar_t *last);
    void append(const CharT *text);
    StringBase& append(unsigned int count, CharT character);
    void insert(int position, const CharT *text);
    void insert(int position, const StringBase& text);
    void DetachWideIfShared();
    wchar_t *SetLengthWideAndDetach(unsigned int length);
    wchar_t *LockWideBuffer();

private:
    CharT *m_data;
};

int WideRangeCompare(const wchar_t *lhsBegin, const wchar_t *lhsEnd,
                     const wchar_t *rhsBegin, const wchar_t *rhsEnd);
}

[[CHILDREN]]

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# StringBase Template

## UID0000MS Profile-Read API Closure - 2026-08-25

The guarded `StringBase` declaration now exposes `SetLengthWideAndDetach(unsigned int)` and `LockWideBuffer()`, matching the already-emitted explicit `wchar_t` specialization bodies at `0x005835c0` and `0x00584040`. ProfileStorage uses the first to obtain writable length-sized UTF-16 storage before `fread`, then uses the second to restore the accepted refcount/lock state.

This is declaration closure only. It does not create duplicate method bodies, change `m_data`, add a second string template, or move the existing exact children away from StringBase ownership. The names are source-facing inferred API names already used by the accepted formal definitions and current callers.

## 2026-08-18 Count-And-Character Append Closure

The public template declaration now includes `StringBase& append(unsigned int count, CharT character);`. Live `0x00584200` behavior appends exactly `count` copies, updates length and NUL state, and returns `this`; DATFile ANSI `ReadLine` invokes it as `(1, current)`. The 32-bit target gives `unsigned int` the observed `size_t` ABI width, so this is a source-facing overload declaration rather than a reverse-engineered helper signature.

## C134 Header Assembly Closure

The canonical public template declaration is protected by `NEXUSTK_UTIL_STRINGBASE_H`. `SpelledPane.cpp` reaches it first for the source-local LineIterator and again through SpelledPane and LanguageMan headers; one guarded definition preserves the sole default template argument and prevents command20473's C4348/C2953 duplicate-template failures. Existing non-default forward declarations remain legal declarations of the same template and do not create a second class body.

## Status

- Entity kind: inferred C++ template/type family.
- Direct owner header/source root: [UID:0000OA][StringBase](by-file/StringBase.md), with [UID:0000OB][StringUtil](by-file/StringUtil.md) as the broader utility-string coordinator.
- Confidence: strong for `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` name evidence, the main out-of-line `StringBase.cpp` implementation family, and header-visible placement of exact template specializations such as [UID:0004FM][0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper](by-memory/0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper.md); medium for exact declaration/API spelling.
- Evidence basis: generated `FunctionObjectT<mystr::StringBase<...>>` metadata/source, `simroot_v2` `LObject` string helpers, and read-only IDA MCP decompile/caller checks on 2026-05-25.
- Rebuild handling: `source-authored` / `source-declared/generated-binary`; the template/layout semantics must be recreated. This template page's own formal C++ stays blank until the full declaration/API split is audited, while exact child helper pages may emit first-draft method/helper C++ when their target-specific route clears the current code-entry gate.

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

Current target-specific method inventory from [UID:0002RS][0x00584160-0x005845af.StringBaseAppendAndFind](by-memory/0x00584160-0x005845af.StringBaseAppendAndFind.md) extends the declaration hypothesis with inferred source-facing helper roles: `AppendAnsiSliceFromString`, `AppendAnsiFill`, `AppendAnsiLiteral`, `AppendWideSliceFromString`, `AppendWideFill`, `AppendWideLiteral` / counted wide append, the generic `c_str`/data-pointer accessor, and `CompareWideSubstringWithLiteral`. These names are not symbol-proven original public names; they are the formal C++ names used for the accepted target because they preserve behavior and avoid stale `AppendWideData`/`FindWide` roles.

Current target-specific method inventory from [UID:0002RM][0x00582500-0x005829f0.StringBaseConversionAndCrtShims](by-memory/0x00582500-0x005829f0.StringBaseConversionAndCrtShims.md) adds inferred conversion and value-helper roles: `InitializeWideFromAnsi`, `InitializeWideFromRaw`, `InitializeAnsiFromWideString`, `InitializeWideFromStringBase`, `InitializeAnsiFromRaw`, `InitializeAnsiFromWide`, `InitializeAnsiFromStringBase`, `InitializeWideFromAnsiString`, `ToLong`, and `ToDoubleDefaultLocale`. `0002RM` also includes file-local CRT compare/collation/case/format wrappers, so its canonical owner stays [UID:0000OA][StringBase](by-file/StringBase.md) rather than this template page, but the template type context supports the method names and formal first-draft C++ route.

[UID:00040Q][0x004f0380-0x004f03bb.LanguageManCopyLocalizedString](by-memory/0x004f0380-0x004f03bb.LanguageManCopyLocalizedString.md) is a direct by-value wide-template consumer of `InitializeWideFromRaw` at `0x00582560`. Both callers allocate an uninitialized four-byte result object, the callee allocates/copies without releasing prior storage, and later `c_str`/destructor use confirms one-pointer `StringBase<wchar_t, mychar_traits<wchar_t> >`. The explicit result pointer is hidden-sret lowering rather than a source output parameter; current 24-byte `SimpleUString`, assignment, and std::wstring alternatives are excluded.

Current target-specific method inventory from [UID:0002RN][0x005829f0-0x00582d80.StringBaseShareAssignAndAccess](by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md) adds the accepted direct `StringBaseTemplate` constructor/destructor/assignment/access helper group: `ShareOrCopyAnsiFromStringBase`, `InitializeAnsiFromCountedBytes`, `InitializeEmptyAnsi`, `ShareOrCopyWideFromStringBase`, `InitializeWideFromRange`, `InitializeEmptyWide`, destructor release bodies over `ReleaseAnsiBuffer` / `ReleaseWideBuffer`, `AssignAnsiFromStringBase`, `AssignWideFromStringBase`, `AssignWideLiteral`, and `GetWideAt`. These are source-facing target names, not symbol-proven final public spellings. They intentionally differ from the [UID:0002RM][0x00582500-0x005829f0.StringBaseConversionAndCrtShims](by-memory/0x00582500-0x005829f0.StringBaseConversionAndCrtShims.md) raw-start `InitializeAnsiFromStringBase` / `InitializeWideFromStringBase` names because [UID:0002RN][0x005829f0-0x00582d80.StringBaseShareAssignAndAccess](by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md) owns separate modeled helpers at `0x005829f0` and `0x00582a90`.

Current target-specific method inventory from [UID:0002RO][0x00582d80-0x00583132.StringBaseAllocationGrowAndCow](by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md) adds the accepted direct `StringBaseTemplate` allocation/grow/COW helper group: `AllocateAnsiBuffer`, `AllocateWideBuffer`, `GrowAnsiBuffer`, `GrowWideBuffer`, `DetachAnsiIfShared`, and `DetachWideIfShared`. Formal target C++ emits exactly these six modeled bodies through [UID:0000OA][StringBase](by-file/StringBase.md); pool selection and header recovery are inlined inside the six bodies, and the child does not introduce `AllocateAnsiHeader`, `AllocateWideHeader`, `HeaderFromData`, lambdas, local helper functions, namespace helpers, or other standalone helper bodies.

Current target-specific method inventory from [UID:0002RQ][0x00583970-0x00584052.StringBaseReplaceTrimAndLocks](by-memory/0x00583970-0x00584052.StringBaseReplaceTrimAndLocks.md) adds the accepted wide slice/split/trim/lock group: `SliceWideRange`, `SplitWideBySet`, `TrimLeftWide`, `TrimRightWide`, `LockAnsiBuffer`, and `LockWideBuffer`. These method/helper names are inferred source-facing names for the accepted target formal C++ and deliberately supersede stale `ReplaceWide`, `ReplaceWorker`, or replace-worker terminology; the physical target filename's `Replace` segment remains a callback-local path constraint, not a source API name.

Current target-specific method inventory from the B011 [UID:0000OA][StringBase](by-file/StringBase.md) empty-emitter implementation adds the suffix, format, comparator, wide search, and splice/grow helpers: `EndsWithAnsi`, `EndsWithWide`, `InitializeAnsiFormat`, `InitializeWideFormat`, `AnsiVFormat`, `WideVFormat`, `CompareAnsiRange`, `WideRangeCompare`, `CompareWideLiteral`, `empty`, `RemoveWideRange`, `FindSubstring`, `FindFirstNotOf`, `FindFirstOf`, `FindLastNotOf`, `FindLastOf`, `SpliceWide`, `EnsureAnsiCapacity`, `EnsureWideCapacity`, `FindLastSubstring`, `length`, and `SubstringWide`. Exact public overload spellings remain provisional, but the accepted child pages now emit source-facing formal C++ or dependency helpers through [UID:0000OA][StringBase](by-file/StringBase.md) rather than staying as empty markers.

Current target-specific method inventory from [UID:00022D][0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper](by-memory/0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper.md) adds the accepted wide two-StringBase free `operator+` / concatenation helper. The formal C++ uses source-facing `StringBase<wchar_t, mychar_traits<wchar_t>> operator+(const StringBase&, const StringBase&)`, constructs the result from the left operand, calls `rhs.length()`, appends the full right operand through `AppendWideSliceFromString`, and returns by value. The exact public overload spelling is inferred, but the ABI/body and [UID:000325][0x004671b0-0x004671de.StringBaseAppendWideLiteral](by-memory/0x004671b0-0x004671de.StringBaseAppendWideLiteral.md) precedent make [UID:0000OA][StringBase](by-file/StringBase.md) the direct owner rather than PatchPane2.

Current target-specific method inventory from [UID:0004FM][0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper](by-memory/0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper.md) adds the accepted ANSI return-by-value lowercase-copy member `StringBase<char, mychar_traits<char> >::ToLower() const`. The target receives the source object in `ecx`, receives the hidden result object as its one stack argument, returns that object in `eax`, and uses `retn 4`; its body copy-constructs the result, calls `DetachAnsiIfShared`, lowercases `data()` through `_strlwr_s` with `length()+1`, and returns the value. `ToLower` is inferred source-facing spelling, while the hidden-result ABI and StringBase ownership are directly behavior-backed. UID0001NW adds a second live semantic consumer: `VirusChecker::InsertModulePath` and its inlined module callback form a lower-case ANSI copy before unique `ModulePathSet` insertion. Multiple consumer translation units make the highest-probability original source placement a header-visible inline specialization in `StringBase.h` or an included `.inl`, not a SoundManager-owned helper and not a definition owned by `StringBase.cpp`. The formal H declarations plus the parent-H `[[CHILDREN]]` anchor after namespace closure and before `#endif` provide that exact route; the outlined body near SoundManager is consumer-TU/COMDAT evidence. The former explicit `(result, source)` `PrepareLowercaseSoundPathString` helper and SoundPathVector ownership are historical decompiler-shaped interpretations.

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
- B006 session `398b87c1` reconfirmed [UID:0001CQ][0x0052a460-0x0052a49e.FunctionObjectTStringDestructor](by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md) as type-name evidence only: the target writes generic callback vtable slot `0x0061fcd4`, has only that vtable data xref, and contains FunctionObjects/`LObject` scalar deleting destructor cleanup, not string-buffer behavior. Keep the `mystr::StringBase<wchar_t,mystr::mychar_traits<wchar_t>>` spelling as compiler metadata evidence for this template page, but keep destructor ownership with [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md).
- B007 session `b009_0001Q4_20260628` reconfirmed [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md) as const-reference `StringBase` callback type-name evidence only: the target has two exact FunctionObjects scalar deleting destructor bodies, vtable/data refs at `0x0061ff58`, `0x0061ff70`, `0x0062004c`, `0x00620094`, and `0x00622cf4`, no direct callers, no endpoint refs, and create-user/Nexonclub consumer vtables. Keep the `StringBase` const-reference spelling as compiler metadata evidence for this template page, but keep destructor ownership with [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) and the target as blank-emitter non-emitting metadata.
- IDA decompilation of `0x00582d80` and `0x00582e30` shows separate ANSI and wide allocation paths with the same `refCount/length/capacity` header and empty sentinels.
- IDA decompilation of `0x00583210` and `0x00583280` shows varargs format constructors for ANSI and wide strings; the wide wrapper seeds `0x00670278`, then calls the wide formatting worker.
- IDA decompilation of `0x005845b0` reads the stored wide length from `m_data[-2]` and compares against a NUL-terminated wide literal through the range comparator at `0x005840f0`.
- [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md) and [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md) record the shared layout and global storage used by the template family.
- 2026-05-31 IDA MCP recheck confirms exact function bounds for the core string helpers: `0x00582d80-0x00582e2c` ANSI allocation, `0x00582e30-0x00582ee2` wide allocation, `0x00583210-0x00583273` ANSI formatting wrapper, `0x00583280-0x005832e3` wide formatting wrapper, `0x005840f0-0x0058415a` range comparator, and `0x005845b0-0x005845ec` wide literal compare helper.
- 2026-05-31 IDA MCP callers show `0x00582d80` and `0x00582e30` are widely reused by local string construction/mutation routines, while `0x00583280` is used from application setup, UI/dialog code, item/mix helpers, and other client code paths; this supports a shared project-local string template rather than a feature-local helper.
- 2026-05-31 IDA decompilation rechecks show the ANSI helper allocates `a2 + 13` bytes for heap-backed buffers and writes the NUL byte at data offset `a2`, while the wide helper allocates `2 * a2 + 14` bytes and writes the NUL word at data offset `a2`. Both set `refCount=1`, `length=a2`, and `capacity` or requested size in the three dwords immediately before the returned data pointer.
- 2026-06-08 A006 Batch135 live IDA MCP parent-gate refresh returned more than twenty `*StringBase*`/`*mystr*` global-name matches, including vtables and RTTI records for `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` and const-reference/value callback-template instantiations. Representative addresses include `0x0061fcd4`, `0x0061fcec`, `0x0061ff70`, `0x0062004c`, `0x00620094`, `0x00622cf4`, `0x0064c610`, and `0x0064c9c8`.
- The same refresh reconfirmed `0x004f4a80` as a 9-byte true `LObject` shell constructor and reconfirmed the `StringBase` helper boundaries and xref counts recorded in [UID:0000OA][StringBase](by-file/StringBase.md), supporting direct attachment to that file rather than the polluted generated `LObject` owner.
- 2026-06-25 B003 implementation callback for [UID:0002RT][0x005832f0-0x00583714.StringBaseReleaseAndCapacity](by-memory/0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md) confirms that the release/capacity child is another direct `StringBaseTemplate` helper group, matching the route already used by [UID:0002RO][0x00582d80-0x00583132.StringBaseAllocationGrowAndCow](by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md), [UID:0002LL][0x00583720-0x00583832.StringBaseAnsiVFormatWorker](by-memory/0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md), and [UID:0002LM][0x00583840-0x00583968.StringBaseWideVFormatWorker](by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md). The dated callback MCP session `80de0a67` reconfirmed the eight exact helpers, their `0xcc` padding boundaries, release/copy/share/detach behavior, dependency helpers, function-entry xrefs, sentinel/pool xrefs, and preserved `mystr::StringBase` compiler metadata. The child now emits first-draft C++ through this template page to [UID:0000OA][StringBase](by-file/StringBase.md); this template page itself still keeps formal C++ blank because the full public declaration and header/API split remain unresolved.
- 2026-06-25 B005 implementation callback for [UID:0002RS][0x00584160-0x005845af.StringBaseAppendAndFind](by-memory/0x00584160-0x005845af.StringBaseAppendAndFind.md) confirms the append/fill/accessor/compare child as another StringBase method/helper family that emits through [UID:0000OA][StringBase](by-file/StringBase.md). The dated callback MCP session `80de0a67` supports the ANSI/wide slice/fill/literal append helpers, `c_str`/data-pointer accessor, counted wide literal append used by [UID:000325][0x004671b0-0x004671de.StringBaseAppendWideLiteral](by-memory/0x004671b0-0x004671de.StringBaseAppendWideLiteral.md), and bounded wide literal compare consumer of [UID:0002LN][0x005840f0-0x0058415a.WideRangeCompare](by-memory/0x005840f0-0x0058415a.WideRangeCompare.md). Exact facade spelling remains a confidence cap, not a blocker for the target-specific formal C++ block.
- 2026-06-25 B011 implementation callback for [UID:0002RM][0x00582500-0x005829f0.StringBaseConversionAndCrtShims](by-memory/0x00582500-0x005829f0.StringBaseConversionAndCrtShims.md) confirms the conversion constructors and raw retain/copy helpers as another `StringBase` method family with formal first-draft C++ emitted through [UID:0000OA][StringBase](by-file/StringBase.md). The dated callback MCP session `80de0a67` also resolves the adjacent value-conversion wrappers: the wide and ANSI base-10 helpers are UCRT `__crt_strtox` integer parser wrappers, and `0x005e1b76` / `0x005e1b0b` is a default-locale string-to-double wrapper. The child also contains file-local CRT compare/case/collation/format shims, so this template page is type context rather than the canonical owner for the whole range.
- 2026-06-25 B006 implementation callback for [UID:0002RN][0x005829f0-0x00582d80.StringBaseShareAssignAndAccess](by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md) confirms the share/assign/access child as a direct `StringBaseTemplate` helper group with target-specific first-draft C++ emitted through [UID:0000OA][StringBase](by-file/StringBase.md). The dated callback MCP session `80de0a67` proves the twelve exact modeled starts, all internal `0xcc` padding, ANSI and wide empty-sentinel xrefs, helper dependencies at `0x00582d80`, `0x00582e30`, `0x005832f0`, `0x005833a0`, `0x00584b10`, and `0x00584ba0`, caller/callee counts, empty-source assignment no-release behavior, private-copy visible-length clamp/no-length-update behavior, and destructor wrappers as compiler EH/security-cookie scaffolding around release calls.
- 2026-06-26 B005 implementation callback for [UID:0002RO][0x00582d80-0x00583132.StringBaseAllocationGrowAndCow](by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md) confirms the allocation/grow/COW child as a direct `StringBaseTemplate` helper group with target-specific first-draft C++ emitted through [UID:0000OA][StringBase](by-file/StringBase.md). The dated callback MCP session `80de0a67` proves the six modeled starts, internal `0xcc` padding before `0x00583140`, ANSI/wide sentinel and pool references, `refCount`/`length`/`capacity` header writes, grow retain/release/copy behavior, and detach-if-shared release behavior. The formal C++ is intentionally six-body-only and range-faithful: all pool/header logic is inlined inside the target bodies and the child emits no helper bodies outside the modeled range.
- 2026-06-25 B010 implementation callback for [UID:0002RQ][0x00583970-0x00584052.StringBaseReplaceTrimAndLocks](by-memory/0x00583970-0x00584052.StringBaseReplaceTrimAndLocks.md) confirms the wide slice/split/trim/lock child as another direct `StringBaseTemplate` helper group with target-specific first-draft C++ emitted through [UID:0000OA][StringBase](by-file/StringBase.md). The dated callback MCP session `80de0a67` proves six exact function bodies, all internal `0xcc` padding, split/tokenization behavior at `0x005839c0`, trim whitespace callers, ANSI/wide lock sentinel checks, and corrected search-helper roles. This template page still keeps its own full-declaration C++ blank because final public facade spelling and header/API split remain unresolved.
- 2026-06-26 B010 implementation callback for [UID:00022D][0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper](by-memory/0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper.md) confirms a wide two-StringBase free `operator+` / concatenation helper as another target-specific StringBase helper emitted through [UID:0000OA][StringBase](by-file/StringBase.md). The dated callback MCP session `80de0a67` proves the exact `0x004b32d0-0x004b3344` range, `0xcc` boundary padding, unique signature, one PatchPane2 consumer at `0x0054928d`, no data/immediate/VA/RVA pointer route, and callee sequence `0x00582a90` / `0x00584cf0` / `0x00584320`. The helper's exact public overload spelling remains inferred, but that is a template/API confidence cap, not a target-C++ blocker.
- 2026-07-13 B004 UID0001IA callback adds [UID:0004FM][0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper](by-memory/0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper.md) as consumer-TU evidence for an ANSI `ToLower() const` specialization. The dated call-site/target analysis proved source in `ecx`, a hidden stack result, `eax` return, `retn 4`, copy construction, detach-if-shared, and lowercase mutation. This page's score and aggregate formal block remain unchanged; the exact child owns the formal specialization through this template route.
- 2026-06-30 B011 empty-emitter implementation for [UID:0000OA][StringBase](by-file/StringBase.md) confirms that this template/type page remains useful as a marker and method-inventory owner, but not as a full standalone template declaration emitter. The dated callback MCP session `supervisor_resume_20260629` confirms exact sizes and behavior for the accepted suffix, format, comparator, search, and splice/grow children: [UID:0002RP][0x00583140-0x00583206.StringBaseSuffixChecks](by-memory/0x00583140-0x00583206.StringBaseSuffixChecks.md), [UID:0002LJ][0x00583210-0x00583273.StringBaseAnsiFormatCtor](by-memory/0x00583210-0x00583273.StringBaseAnsiFormatCtor.md), [UID:0002LK][0x00583280-0x005832e3.StringBaseWideFormatCtor](by-memory/0x00583280-0x005832e3.StringBaseWideFormatCtor.md), [UID:0002LL][0x00583720-0x00583832.StringBaseAnsiVFormatWorker](by-memory/0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md), [UID:0002LM][0x00583840-0x00583968.StringBaseWideVFormatWorker](by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md), [UID:0003NT][0x00584060-0x005840ea.StringBaseByteRangeCompare](by-memory/0x00584060-0x005840ea.StringBaseByteRangeCompare.md), [UID:0002LN][0x005840f0-0x0058415a.WideRangeCompare](by-memory/0x005840f0-0x0058415a.WideRangeCompare.md), [UID:0002LO][0x005845b0-0x005845ec.StringBaseCompareWideLiteral](by-memory/0x005845b0-0x005845ec.StringBaseCompareWideLiteral.md), [UID:0003NL][0x005845f0-0x0058490f.StringBaseWideSearchHelpers](by-memory/0x005845f0-0x0058490f.StringBaseWideSearchHelpers.md), and [UID:0003NM][0x00584990-0x00584d7e.StringBaseSpliceGrowAndSubstring](by-memory/0x00584990-0x00584d7e.StringBaseSpliceGrowAndSubstring.md). A full template class shell is still deferred because it would guess public/private ordering, facade typedefs, and overload membership across `StringBase`, `SimpleUString`, and utility helpers.

All named MCP sessions in this page are dated evidence snapshots, not permanent current authority. Any future IDA-dependent decision requires a fresh supervisor `idb_list`, health/canonical-disk identity, and target-prestate readback before it can be treated as current.

## Direct Helper Groups

| Child | Role | Route note |
| --- | --- | --- |
| [UID:0002RP][0x00583140-0x00583206.StringBaseSuffixChecks](by-memory/0x00583140-0x00583206.StringBaseSuffixChecks.md) | ANSI and UTF-16 suffix predicates. | Target-specific formal C++ emits `EndsWithAnsi` and `EndsWithWide` through [UID:0000OA][StringBase](by-file/StringBase.md), with [UID:0003NT][0x00584060-0x005840ea.StringBaseByteRangeCompare](by-memory/0x00584060-0x005840ea.StringBaseByteRangeCompare.md) as the ANSI dependency and [UID:0002RS][0x00584160-0x005845af.StringBaseAppendAndFind](by-memory/0x00584160-0x005845af.StringBaseAppendAndFind.md) as the wide bounded-compare dependency. |
| [UID:0002RO][0x00582d80-0x00583132.StringBaseAllocationGrowAndCow](by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md) | ANSI/wide allocation, append-growth, and detach-if-shared primitives. | Direct template/type helper group; target-specific formal C++ emits exactly the six modeled bodies through [UID:0000OA][StringBase](by-file/StringBase.md). Pool/header logic is inlined inside those bodies, and no 0002RO-owned helper bodies are emitted. |
| [UID:0002LJ][0x00583210-0x00583273.StringBaseAnsiFormatCtor](by-memory/0x00583210-0x00583273.StringBaseAnsiFormatCtor.md) | ANSI varargs format constructor/initializer. | Target-specific formal C++ emits `InitializeAnsiFormat`, seeding the ANSI empty sentinel before forwarding to `AnsiVFormat`. |
| [UID:0002LK][0x00583280-0x005832e3.StringBaseWideFormatCtor](by-memory/0x00583280-0x005832e3.StringBaseWideFormatCtor.md) | UTF-16 varargs format constructor/initializer. | Direct template/type helper group; target-specific formal C++ emits `InitializeWideFormat`, seeding the wide empty sentinel before forwarding to `WideVFormat`. |
| [UID:0002RT][0x005832f0-0x00583714.StringBaseReleaseAndCapacity](by-memory/0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md) | ANSI/wide release, header access, wide copy/share, set-length detach, make-exclusive, and wide format forwarding helpers. | Direct template/type helper group; current first-draft C++ is target-specific and emitted by the child, not by this template page. |
| [UID:0002LL][0x00583720-0x00583832.StringBaseAnsiVFormatWorker](by-memory/0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md) | ANSI `va_list` formatting worker. | Direct template/type helper group emitted through [UID:0000OA][StringBase](by-file/StringBase.md). |
| [UID:0002LM][0x00583840-0x00583968.StringBaseWideVFormatWorker](by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md) | UTF-16 `va_list` formatting worker. | Direct template/type helper group emitted through [UID:0000OA][StringBase](by-file/StringBase.md). |
| [UID:0003NT][0x00584060-0x005840ea.StringBaseByteRangeCompare](by-memory/0x00584060-0x005840ea.StringBaseByteRangeCompare.md) | ANSI byte-range comparator dependency for suffix checks. | Target-specific formal C++ emits through [UID:0000OA][StringBase](by-file/StringBase.md); this helper is included because [UID:0002RP][0x00583140-0x00583206.StringBaseSuffixChecks](by-memory/0x00583140-0x00583206.StringBaseSuffixChecks.md) calls it directly. |
| [UID:0002LN][0x005840f0-0x0058415a.WideRangeCompare](by-memory/0x005840f0-0x0058415a.WideRangeCompare.md) | UTF-16 half-open range comparator. | Target-specific formal C++ emits through [UID:0000OA][StringBase](by-file/StringBase.md), using source-facing range-loop semantics rather than compiler-specific compare optimizations. |
| [UID:0002RQ][0x00583970-0x00584052.StringBaseReplaceTrimAndLocks](by-memory/0x00583970-0x00584052.StringBaseReplaceTrimAndLocks.md) | UTF-16 range slicing, delimiter split/tokenization, trim-left/right, and ANSI/UTF-16 writable-buffer lock helpers. | Direct template/type helper group; target-specific formal C++ emits through [UID:0000OA][StringBase](by-file/StringBase.md). Names are inferred source-facing method/helper roles, and the physical filename's `Replace` segment is stale. |
| [UID:0002RS][0x00584160-0x005845af.StringBaseAppendAndFind](by-memory/0x00584160-0x005845af.StringBaseAppendAndFind.md) | ANSI/wide slice, fill, and literal append helpers; `c_str`/data-pointer accessor; bounded wide literal compare. | Target-specific formal C++ now emits through [UID:0000OA][StringBase](by-file/StringBase.md). Names are inferred source-facing method/helper roles, not symbol-proven public API spellings. |
| [UID:0002LO][0x005845b0-0x005845ec.StringBaseCompareWideLiteral](by-memory/0x005845b0-0x005845ec.StringBaseCompareWideLiteral.md) | UTF-16 literal compare wrapper. | Target-specific formal C++ emits `CompareWideLiteral` through [UID:0000OA][StringBase](by-file/StringBase.md) and delegates to [UID:0002LN][0x005840f0-0x0058415a.WideRangeCompare](by-memory/0x005840f0-0x0058415a.WideRangeCompare.md). |
| [UID:0003NL][0x005845f0-0x0058490f.StringBaseWideSearchHelpers](by-memory/0x005845f0-0x0058490f.StringBaseWideSearchHelpers.md) | UTF-16 empty/remove/search, first/last-of, and not-of helper group. | Target-specific formal C++ emits through [UID:0000OA][StringBase](by-file/StringBase.md), split before the separately owned vector helper. |
| [UID:0003NM][0x00584990-0x00584d7e.StringBaseSpliceGrowAndSubstring](by-memory/0x00584990-0x00584d7e.StringBaseSpliceGrowAndSubstring.md) | UTF-16 splice, ANSI/wide ensure-capacity, reverse substring search, length, and substring helpers. | Target-specific formal C++ emits through [UID:0000OA][StringBase](by-file/StringBase.md), split after the separately owned vector helper and four-byte padding island. |
| [UID:0002RM][0x00582500-0x005829f0.StringBaseConversionAndCrtShims](by-memory/0x00582500-0x005829f0.StringBaseConversionAndCrtShims.md) | ANSI/UTF-16 conversion initialization helpers, raw retain/copy helpers, value conversions, and adjacent file-local CRT shims. | Mixed method/file-local helper child; target-specific formal C++ emits through [UID:0000OA][StringBase](by-file/StringBase.md). Method names are inferred source-facing roles, while compare/case/collation/format shims stay file-local. |
| [UID:0002RN][0x005829f0-0x00582d80.StringBaseShareAssignAndAccess](by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md) | ANSI/wide share-or-copy initialization, counted data initialization, empty sentinel initialization, destructor release bodies, assignment-style copy/share helpers, raw wide literal assignment, and wide index access. | Direct template/type helper group; target-specific formal C++ emits through [UID:0000OA][StringBase](by-file/StringBase.md). Names are inferred source-facing method/helper roles and preserve binary quirks such as empty-source no-release and private-copy no-length-update behavior. |
| [UID:00022D][0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper](by-memory/0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper.md) | Wide two-StringBase free `operator+` / concatenation helper. | Target-specific formal C++ emits through [UID:0000OA][StringBase](by-file/StringBase.md). PatchPane2 is the only known consumer; the helper body is generic StringBase return-by-value concatenation, not PatchPane2-owned source. |

## Assignment Gate

This template page now attaches to [UID:0000OA][StringBase](by-file/StringBase.md). The child is `88/91`, the direct parent is `91/90`, and the by-structure relationship is direct because this page records the source-level template/type declaration context for the ref-counted string-buffer family. Formal CPP retains `[[CHILDREN]]` for ordinary out-of-line method bodies owned by `StringBase.cpp`; formal H supplies both the guarded public declaration and a second `[[CHILDREN]]` anchor after namespace closure and before `#endif` for header-visible inline template definitions such as UID0004FM. Exact original overload spelling remains an evidence cap, but the complete currently used declaration and deterministic header-child insertion route are no longer deferred.

Do not attach this page to [UID:0000OB][StringUtil](by-file/StringUtil.md) unless later original-source evidence collapses the source split. `StringUtil` is the broader utility-string coordination page; current compiler metadata names and exact helper aggregates point at the dedicated `StringBase` source root.

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
- [UID:0001J1][0x00582500-0x00583206.StringBaseConstructionAndCow](by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md)
- [UID:0001J2][0x00583210-0x005832f0.StringBaseFormatConstructors](by-memory/0x00583210-0x005832f0.StringBaseFormatConstructors.md)
- [UID:0001J3][0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md)
- [UID:0002RM][0x00582500-0x005829f0.StringBaseConversionAndCrtShims](by-memory/0x00582500-0x005829f0.StringBaseConversionAndCrtShims.md)
- [UID:0002RN][0x005829f0-0x00582d80.StringBaseShareAssignAndAccess](by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md)
- [UID:0002RO][0x00582d80-0x00583132.StringBaseAllocationGrowAndCow](by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md)
- [UID:0002RP][0x00583140-0x00583206.StringBaseSuffixChecks](by-memory/0x00583140-0x00583206.StringBaseSuffixChecks.md)
- [UID:0002LJ][0x00583210-0x00583273.StringBaseAnsiFormatCtor](by-memory/0x00583210-0x00583273.StringBaseAnsiFormatCtor.md)
- [UID:0002LK][0x00583280-0x005832e3.StringBaseWideFormatCtor](by-memory/0x00583280-0x005832e3.StringBaseWideFormatCtor.md)
- [UID:0002RT][0x005832f0-0x00583714.StringBaseReleaseAndCapacity](by-memory/0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md)
- [UID:0002LL][0x00583720-0x00583832.StringBaseAnsiVFormatWorker](by-memory/0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md)
- [UID:0002LM][0x00583840-0x00583968.StringBaseWideVFormatWorker](by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md)
- [UID:0002RQ][0x00583970-0x00584052.StringBaseReplaceTrimAndLocks](by-memory/0x00583970-0x00584052.StringBaseReplaceTrimAndLocks.md)
- [UID:0002RS][0x00584160-0x005845af.StringBaseAppendAndFind](by-memory/0x00584160-0x005845af.StringBaseAppendAndFind.md)
- [UID:0003NT][0x00584060-0x005840ea.StringBaseByteRangeCompare](by-memory/0x00584060-0x005840ea.StringBaseByteRangeCompare.md)
- [UID:0002LN][0x005840f0-0x0058415a.WideRangeCompare](by-memory/0x005840f0-0x0058415a.WideRangeCompare.md)
- [UID:0002LO][0x005845b0-0x005845ec.StringBaseCompareWideLiteral](by-memory/0x005845b0-0x005845ec.StringBaseCompareWideLiteral.md)
- [UID:0003NL][0x005845f0-0x0058490f.StringBaseWideSearchHelpers](by-memory/0x005845f0-0x0058490f.StringBaseWideSearchHelpers.md)
- [UID:0003NM][0x00584990-0x00584d7e.StringBaseSpliceGrowAndSubstring](by-memory/0x00584990-0x00584d7e.StringBaseSpliceGrowAndSubstring.md)
- [UID:00022D][0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper](by-memory/0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper.md)
- [UID:0004FM][0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper](by-memory/0x0057bc60-0x0057bcdc.SoundPathStringPrepareHelper.md)
- [UID:0001CQ][0x0052a460-0x0052a49e.FunctionObjectTStringDestructor](by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md)
- [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md)

## 2026-07-29 UID0002MZ Header Dependency Reconciliation

- Formal H now supplies the complete one-pointer `mystr::StringBase<CharT, Traits>` declaration required by `FolderTreePane::TreeElem::name`. Exact `0x0c` FolderTree payload arithmetic proves this concrete wide-string specialization occupies four bytes; the declaration preserves the documented refcounted backing-buffer method children rather than replacing them.
- The accepted consumer type is `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >`. It is explicitly separate from the 24-byte SSO `SimpleUString` family and from IDA's protected four-byte artifact that carries the `SimpleUString` name.
- Broader overload order, facade aliases, and exact original header spelling remain documented uncertainty and keep the score at `88/91`; they no longer justify a prose-only declaration deferral that makes the FolderTree header structurally incomplete.
- Supervisor Gate 2B catalog entry `0365` now provides the matching IDA analysis alias `StringBaseWide`, exact size `0x04`, with only `wchar_t *m_data` at `+0x00`. The pre-existing pointer-backed IDA artifact `SimpleUString` remains unchanged and distinct. This analysis alias confirms the consumer width but does not replace the human-source template spelling in formal H.
- Saved IDB `412DA7E8...519CD` is the dated catalog0365 transaction checkpoint rather than a durable current-global authority claim; later bounded report readbacks preserved the same target-local alias and width facts. The source declaration needs no IDA parser annotation; the explicit `__declspec(align(4))` requirement applied only to the dependent payload/node analysis UDT tails.

## Historical Assumption Superseded By UID0002MZ

- The former formal CPP comment deferred the entire template declaration to a future project-wide API pass. The accepted callback historicalizes that deferral: exact child behavior remains valid, while the minimum complete one-pointer H surface is now source-ready for current consumers.

## Changes

- 2026-08-24 B005 UID0000KK support sync: added UID00040Q as a behavior-backed by-value `StringBase<wchar_t,...>` consumer of `InitializeWideFromRaw`, preserving the exact hidden-result ABI and four-byte `m_data` layout while rejecting assignment and 24-byte SimpleUString source shapes.

- 2026-08-06 B003 UID0001NW placement callback: added the formal-H `[[CHILDREN]]` anchor after namespace closure and before `#endif`; routed UID0004FM's exact ANSI `ToLower() const` body as a header-visible inline specialization; distinguished the SoundManager-adjacent outlined body as consumer-TU/COMDAT evidence rather than source ownership; and historicalized dated MCP session identities without removing their evidence.
- 2026-07-13 B004 UID0001IA support sync: added the ANSI return-by-value `ToLower() const` inventory, hidden-result ABI, exact copy/detach/lower behavior, UID0004FM child route, inferred-name limit, and rejected explicit-output/SoundPathVector history. Score and aggregate marker block remain unchanged.
- 2026-06-30 B011 [UID:0000OA][StringBase](by-file/StringBase.md) empty-emitter implementation:
  - Before: `COMPLETION:86`, `CONFIDENCE:90`, formal C++ blank with a broad pending-template caveat and incomplete current child inventory.
  - After: `COMPLETION:88`, `CONFIDENCE:91`, marker comment populated with a `[[CHILDREN]]` insertion point and child inventory expanded for accepted suffix, format, comparator, wide search, and splice/grow helper bodies.
  - Summary/evidence: incorporated accepted B011 report `0000OA-StringBase-empty-emitter-family-source-quality.md`. This page remains the template/type declaration context for exact StringBase method children, but it intentionally does not emit a full standalone class shell because public/private ordering, facade typedefs, overload membership, and the `StringBase`/`SimpleUString` header split remain unresolved. Exact source behavior is emitted by the child pages listed in the Direct Helper Groups table through this marker/children route.
- 2026-06-28 B007 [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md) support sync:
  - Score unchanged.
  - Summary/evidence: added evidence from dated MCP session `b009_0001Q4_20260628` clarification that [UID:0001CS][0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors](by-memory/0x0052f780-0x0052f7fe.FunctionObjectTConstStringDestructors.md) is strong const-reference `StringBase` callback type-name evidence but not StringBase or StringUtil ownership of the destructor bodies. The functions are generic FunctionObjects callback-template scalar deleting destructor glue with vtable-only routes and blank-emitter non-emitting metadata.
- 2026-06-27 B006 [UID:0001CQ][0x0052a460-0x0052a49e.FunctionObjectTStringDestructor](by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md) support sync:
  - Score unchanged.
  - Summary/evidence: added evidence from dated MCP session `398b87c1` clarification that [UID:0001CQ][0x0052a460-0x0052a49e.FunctionObjectTStringDestructor](by-memory/0x0052a460-0x0052a49e.FunctionObjectTStringDestructor.md) is strong `mystr::StringBase<wchar_t,mystr::mychar_traits<wchar_t>>` type-name evidence but not StringBase ownership of the destructor body. The function is generic FunctionObjects callback-template scalar deleting destructor glue with a vtable-only route through `0x0061fcd4`.
- 2026-06-26 B005 [UID:0002RO][0x00582d80-0x00583132.StringBaseAllocationGrowAndCow](by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md) implementation sync:
  - Score unchanged; this template page still keeps its own full-declaration C++ blank pending final public API/facade audit.
  - Summary/evidence: added the accepted [UID:0002RO][0x00582d80-0x00583132.StringBaseAllocationGrowAndCow](by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md) allocation/grow/COW method family to the declaration/method inventory and direct helper table: `AllocateAnsiBuffer`, `AllocateWideBuffer`, `GrowAnsiBuffer`, `GrowWideBuffer`, `DetachAnsiIfShared`, and `DetachWideIfShared`. The dated callback MCP session `80de0a67` supports the exact six starts, padding, sentinel/pool/header behavior, release-helper dependencies, and the six-body-only formal C++ route through [UID:0000OA][StringBase](by-file/StringBase.md) with no 0002RO-owned helper bodies.
- 2026-06-25 B010 [UID:0002RQ][0x00583970-0x00584052.StringBaseReplaceTrimAndLocks](by-memory/0x00583970-0x00584052.StringBaseReplaceTrimAndLocks.md) implementation sync:
  - Score unchanged.
  - Summary/evidence: added the accepted [UID:0002RQ][0x00583970-0x00584052.StringBaseReplaceTrimAndLocks](by-memory/0x00583970-0x00584052.StringBaseReplaceTrimAndLocks.md) method family to the declaration/method inventory: `SliceWideRange`, `SplitWideBySet`, `TrimLeftWide`, `TrimRightWide`, `LockAnsiBuffer`, and `LockWideBuffer`. The dated callback MCP session `80de0a67` supports the exact function inventory, split/tokenization correction, trim whitespace callers, lock sentinel behavior, and target-specific formal C++ through [UID:0000OA][StringBase](by-file/StringBase.md), while this template page keeps its own full-declaration C++ blank pending final API/facade audit.
- 2026-06-26 B010 [UID:00022D][0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper](by-memory/0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper.md) implementation sync:
  - Score unchanged.
  - Summary/evidence: added the accepted [UID:00022D][0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper](by-memory/0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper.md) wide `operator+` / two-StringBase concatenation helper to the declaration/method inventory and direct helper table. The dated callback MCP session `80de0a67` supports exact range, single PatchPane2 consumer, negative pointer-route evidence, and source-facing `StringBase result(lhs); result.AppendWideSliceFromString(rhs, 0, rhs.length()); return result;` behavior. This page still keeps its own full-declaration C++ blank pending final API/facade audit.
- 2026-06-25 B006 [UID:0002RN][0x005829f0-0x00582d80.StringBaseShareAssignAndAccess](by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md) implementation sync:
  - Score unchanged.
  - Summary/evidence: added [UID:0002RN][0x005829f0-0x00582d80.StringBaseShareAssignAndAccess](by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md) as a direct `StringBaseTemplate` helper group with target-specific first-draft C++ emitted through [UID:0000OA][StringBase](by-file/StringBase.md). The dated callback MCP session `80de0a67` supports the exact twelve-function inventory, all-`0xcc` padding, source-facing helper names, sentinel/header/capacity-helper evidence, caller/callee counts, corrected assignment quirks, and compiler-only destructor scaffolding. This template page still keeps its own formal C++ blank because the complete declaration and public/private API split remain unresolved.
- 2026-06-25 B011 [UID:0002RM][0x00582500-0x005829f0.StringBaseConversionAndCrtShims](by-memory/0x00582500-0x005829f0.StringBaseConversionAndCrtShims.md) implementation sync:
  - Score unchanged.
  - Summary/evidence: added the accepted [UID:0002RM][0x00582500-0x005829f0.StringBaseConversionAndCrtShims](by-memory/0x00582500-0x005829f0.StringBaseConversionAndCrtShims.md) conversion/value helper family to the declaration/method inventory while preserving this template page's blank full-declaration C++ block. The child's formal C++ uses inferred source-facing `StringBase` method names and routes through [UID:0000OA][StringBase](by-file/StringBase.md); its adjacent CRT shims explain why the child is file-owned rather than template-owned as a whole.
- 2026-06-25 B005 [UID:0002RS][0x00584160-0x005845af.StringBaseAppendAndFind](by-memory/0x00584160-0x005845af.StringBaseAppendAndFind.md) implementation sync:
  - Score unchanged.
  - Summary/evidence: added the accepted [UID:0002RS][0x00584160-0x005845af.StringBaseAppendAndFind](by-memory/0x00584160-0x005845af.StringBaseAppendAndFind.md) method family to the declaration/method inventory: ANSI/wide slice append, fill append, literal append, `c_str`/data-pointer accessor, counted wide literal append, and bounded wide literal compare. The old `95+` and `AUTOGEN_PARENT_UID` language remains only as historical state below; current target-specific C++ entry is allowed by the combined-score/emitter gate and current owner/emitter metadata.
- 2026-06-25 B003 [UID:0002RT][0x005832f0-0x00583714.StringBaseReleaseAndCapacity](by-memory/0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md) implementation sync:
  - Score unchanged.
  - Summary/evidence: added [UID:0002RT][0x005832f0-0x00583714.StringBaseReleaseAndCapacity](by-memory/0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md) as a direct `StringBaseTemplate` helper group. The dated callback MCP session `80de0a67` supports the route through exact function inventory, padding, sentinel/pool/header behavior, dependency helper checks, function-entry xrefs, and `mystr::StringBase` compiler metadata. The target child now carries first-draft C++; this template page keeps its formal C++ blank because the complete template declaration and public/private API split remain unresolved.
- 2026-06-20 B004 Rule 26 support update:
  - Changed support wording only; score unchanged.
  - Summary/evidence: updated the stale [UID:0001J1][0x00582500-0x00583206.StringBaseConstructionAndCow](by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md) reference to [0x00582500-0x00583206.StringBaseConstructionAndCow](by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md). The parent aggregate is now non-emitting; this template page remains the direct type owner for the allocation/grow/COW child nuance rather than for the whole aggregate.
- 2026-05-31 scoring/rebuild update:
  - What existed before: the page documented the pointer-backed `mystr::StringBase` model but had `COMPLETION:0`, `CONFIDENCE:0`, and blank reconstructable metadata.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP `lookup_funcs`, `callers`, and decompilation reconfirm the ANSI/wide allocation helpers, shared `refCount/length/capacity` header, sentinel behavior, formatting wrappers, and wide comparison helper. The page-level declaration remains below a final full-template audit because the original header/API split, all string helper methods, and relationship to `SimpleUString`/SSO-7 representation still need a full audit before this template page itself emits final class declarations. That page-level caveat does not block target-specific formal C++ on exact child pages such as [UID:0002RS][0x00584160-0x005845af.StringBaseAppendAndFind](by-memory/0x00584160-0x005845af.StringBaseAppendAndFind.md).
- 2026-06-08 A006 Batch135 parent-gate repair:
  - Before: `COMPLETION:82`, `CONFIDENCE:88`, no owner/emitter attachment.
  - After: `COMPLETION:86`, `CONFIDENCE:90`, current `CANONICAL_OWNER:0000OA` and `EMITTER_UIDS:0000OA`.
  - Summary/evidence: live IDA reconfirmed the preserved `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` vtable/RTTI names, key string-helper boundaries, and the separation from the true `LObject` shell. [UID:0000OA][StringBase](by-file/StringBase.md) was raised to `88/86`, clearing the corrected child-and-parent `85/85` gate.
