*** UID:0000D9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SimpleUString

## Status

- Rebuild handling: reconstructable shared string utility class/facade.
- Autogen status: attached to [UID:0000OB][StringUtil](by-file/StringUtil.md) as the broad `util/StringUtil.cpp` owner; final C++ remains blank because the public API, representation split, and relationship to [UID:0000OA][StringBase](by-file/StringBase.md) are not final-source quality.
- Confidence: strong for project-owned shared string infrastructure and the documented split between the two representations; medium-high for the current `SimpleUString` class boundary.
- Important owner caveat: pointer-backed helpers around `0x00583210+` should continue to be reviewed through [UID:0000OA][StringBase](by-file/StringBase.md) / [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md), even though older recovery labels still use `SimpleUString`.

## Summary

`SimpleUString` is shared UTF-16 string infrastructure. Current recovery shows two related surfaces under the same canonical class:

- an early SSO-7 counted wide-string layout at the exact endpoint helpers `0x00421310-0x00421362` and `0x00421590-0x004216cb`;
- a pointer-backed formatted-string family around `0x00583210`, `0x00583280`, and `0x005845b0`.

The relationship between those two representations still needs a layout pass. Both are currently cross-linked from `SimpleUString` because existing caller evidence and exact child pages use this class as the coordination point, but source migration should preserve the distinction. The pointer-backed family now has a preferred neighboring owner candidate in [UID:0000OA][StringBase](by-file/StringBase.md), because live IDA name evidence preserves `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` in vtable/RTTI records.

## Representation Map

| Representation | Evidence anchor | Current owner decision | Remaining risk |
| --- | --- | --- | --- |
| SSO-7 UTF-16 string object | [UID:0001W5][SimpleUStringSso7Layout](by-type/by-struct/SimpleUStringSso7Layout.md), [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md), [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md) | Keep under `SimpleUString` / [UID:0000OB][StringUtil](by-file/StringUtil.md). | Need final class/API names and proof whether this is the same public type as the pointer-backed family. |
| Pointer-backed ref-counted string facade | [UID:0001W4][SimpleUStringPointerBackedLayout](by-type/by-struct/SimpleUStringPointerBackedLayout.md), [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md), [UID:0001J2][0x00583210-0x005845eb.SimpleUStringPointerBacked](by-memory/0x00583210-0x005845eb.SimpleUStringPointerBacked.md) | Treat older `SimpleUString` recovery labels as aliases/leads; prefer [UID:0000OA][StringBase](by-file/StringBase.md) for source migration until the API split is audited. | Final name may be `mystr::StringBase<wchar_t>` rather than `SimpleUString`. |
| Static/global empty string objects | [UID:0000PW][g_emptySimpleUString](by-global/g_emptySimpleUString.md), [UID:00027J][0x0066daec-0x0066db04.g_emptySimpleUString](by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md), [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md) | Cross-link from `SimpleUString`, but keep owning module with the specific consumer/global page until source placement is stronger. | Static lifetime wrapper code should not be hand-authored from the cleanup thunks. |

## Likely Original Placement

- Source: [UID:0000OB][StringUtil](by-file/StringUtil.md)
- Proposed path: `util/StringUtil.cpp`, with pointer-backed helpers possibly in `util/StringBase.cpp`
- Confidence: medium

## Method Families

| Range | Role |
| --- | --- |
| [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md) | `Clear`: frees heap storage when present and resets the SSO-7 wide string to empty. |
| [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md) | counted wide-source constructor/copy helper with SSO-7 growth logic. |
| [UID:0002LJ][0x00583210-0x00583272.StringBaseAnsiFormatCtor](by-memory/0x00583210-0x00583272.StringBaseAnsiFormatCtor.md) | ANSI varargs initializer wrapper, forwards to the ANSI formatting worker. |
| [UID:0002LK][0x00583280-0x005832e2.StringBaseWideFormatCtor](by-memory/0x00583280-0x005832e2.StringBaseWideFormatCtor.md) | Wide varargs initializer wrapper, forwards to the wide formatting worker. |
| [UID:0002LL][0x00583720-0x00583832.StringBaseAnsiVFormatWorker](by-memory/0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md) | ANSI `va_list` formatting worker for the pointer-backed ref-counted buffer. |
| [UID:0002LM][0x00583840-0x00583968.StringBaseWideVFormatWorker](by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md) | UTF-16 `va_list` formatting worker for the pointer-backed ref-counted buffer. |
| [UID:0002LN][0x005840f0-0x00584159.WideRangeCompare](by-memory/0x005840f0-0x00584159.WideRangeCompare.md) | Lexicographic UTF-16 range comparator. |
| [UID:0002LO][0x005845b0-0x005845eb.StringBaseCompareWideLiteral](by-memory/0x005845b0-0x005845eb.StringBaseCompareWideLiteral.md) | Compares a stored wide string against a NUL-terminated wide literal. |

## Evidence

- 2026-06-03 live IDA MCP refresh confirms the SSO endpoint helpers as `sub_421310` at `0x00421310-0x00421362` and `sub_421590` at `0x00421590-0x004216cb`. IDA reports 83 callers for the clear/reset helper and 74 callers for the counted wide assignment helper.
- Live IDA decompilation of `0x00421310` shows the SSO-7 reset shape: capacity at `this+0x14`, length at `this+0x10`, inline threshold `7`, heap free through the runtime free helper when capacity is at least `8`, and a final UTF-16 NUL at the object start.
- Live IDA decompilation of `0x00421590` shows the counted wide-copy/grow shape: length compared against capacity, `length | 7` plus 1.5x growth, allocation for `(capacity + 1) * 2` bytes, counted `memmove`, UTF-16 terminator write, and old-heap release only for previous capacities at least `8`.
- Live IDA function inventory across `0x00583210-0x005845eb` confirms the pointer-backed aggregate is a 29-function string helper island, not a single method. The exact child pages now cover the format wrappers/workers, release/capacity helpers, replace/trim/lock helpers, append/find helpers, range compare, and literal compare wrapper.
- Live IDA decompilation of `0x00583210` seeds the ANSI empty sentinel `off_670290` before calling `0x00583720`; `0x00583280` seeds the wide sentinel `Src` before calling `0x00583840`. The sentinel xref check found 16 refs to `0x00670290` and 23 refs to `0x00670278`.
- Live IDA name search found many `StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` vtable/RTTI records, including entries around `0x0061fcd4`, `0x0061ff70`, `0x0062004c`, `0x00620094`, and `0x00622cf4`. This strengthens the pointer-backed family's [UID:0000OA][StringBase](by-file/StringBase.md) placement while leaving `SimpleUString` as the cross-linked facade/coordination page.
- `0x00421590` has broad constructor/copy-style caller fan-in from startup, UI/resource helpers, collection dialogs, and other systems.
- The historical [UID:0000WT][0x00421310-0x004216cb.SimpleUStringSso7](by-memory/0x00421310-0x004216cb.SimpleUStringSso7.md) page is now an aggregate only. IDA MCP confirms the middle functions are pane/fitting-room/checkbox/runtime helpers, not `SimpleUString` code.
- `0x00583280` has broad caller fan-in from `Application`, startup, patch, browser, sound, virus-checker, and UI helper paths.
- `0x00583210` is used by SoundManager-style track-name formatting paths to build `%08d.MP3` names.
- `0x005845b0` callers include SelfSaveOKPane and WorldMapPane-style compare paths.
- IDA MCP decompilation confirms the pointer-backed formatting workers use the 12-byte ref-counted header described by [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md), including `refCount`, `length`, and `capacity` fields immediately before the data pointer.
- Existing string-family notes keep the SSO-7 wide-string subcluster separate from nearby SSO-15 byte-string helpers.

## Open Questions

- Whether the early SSO-7 layout and the pointer-backed `StringBase` layout were separate original template instantiations sharing the `SimpleUString` name, or whether the current documentation is collapsing adjacent string classes.
- Final ownership of the full `0x00582b70-0x005851d9` string helper neighborhood.
- Names for formatting workers at `0x00583720` and `0x00583840`.
- Whether the release/format/mutation continuation at `0x005832f0-0x00584d7e` belongs under this class name or a neighboring string-base type.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `78` | The page now records the two known representations, exact SSO endpoint helpers, refreshed live IDA caller counts/decompilation, exact pointer-backed child inventory, sentinel evidence, layout/type docs, owner caveats, and utility placement. Completion remains capped because the class boundary, final public API, remaining string continuation ownership, and original header split still need a focused string-family audit. |
| Confidence `86` | Confidence is strong that this is project-owned shared string infrastructure and that `StringUtil` is the broad coordination owner for the `SimpleUString` facade/SSO side. It is still medium-high for the final `SimpleUString` class name because live IDA name evidence preserves `mystr::StringBase<wchar_t,...>` for the pointer-backed family and the SSO-7 versus pointer-backed relationship is unresolved. |

## Cross-References

- File: [UID:0000OB][StringUtil](by-file/StringUtil.md)
- File: [UID:0000OA][StringBase](by-file/StringBase.md)
- Memory: [UID:0000WT][0x00421310-0x004216cb.SimpleUStringSso7](by-memory/0x00421310-0x004216cb.SimpleUStringSso7.md), [UID:0002DV][0x00421310-0x00421362.SimpleUStringClear](by-memory/0x00421310-0x00421362.SimpleUStringClear.md), [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md), [UID:0001J2][0x00583210-0x005845eb.SimpleUStringPointerBacked](by-memory/0x00583210-0x005845eb.SimpleUStringPointerBacked.md), [UID:0001J3][0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation.md), [UID:0002LJ][0x00583210-0x00583272.StringBaseAnsiFormatCtor](by-memory/0x00583210-0x00583272.StringBaseAnsiFormatCtor.md), [UID:0002LK][0x00583280-0x005832e2.StringBaseWideFormatCtor](by-memory/0x00583280-0x005832e2.StringBaseWideFormatCtor.md), [UID:0002LL][0x00583720-0x00583832.StringBaseAnsiVFormatWorker](by-memory/0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md), [UID:0002LM][0x00583840-0x00583968.StringBaseWideVFormatWorker](by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md), [UID:0002LN][0x005840f0-0x00584159.WideRangeCompare](by-memory/0x005840f0-0x00584159.WideRangeCompare.md), [UID:0002LO][0x005845b0-0x005845eb.StringBaseCompareWideLiteral](by-memory/0x005845b0-0x005845eb.StringBaseCompareWideLiteral.md)
- Related classes: [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md), [UID:0000E7][StringIter](by-class/StringIter.md)
- Layouts: [UID:0001W5][SimpleUStringSso7Layout](by-type/by-struct/SimpleUStringSso7Layout.md), [UID:0001W4][SimpleUStringPointerBackedLayout](by-type/by-struct/SimpleUStringPointerBackedLayout.md), [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md)

## Changes

- 2026-06-03: Raised completion/confidence from `70/82` to `78/86`.
  - Summary/evidence: live IDA MCP reconfirmed the SSO endpoint helpers at `0x00421310-0x00421362` and `0x00421590-0x004216cb`, including 83/74 caller counts and decompiled SSO-7 clear/assign behavior; it also confirmed the pointer-backed `0x00583210-0x005845eb` aggregate as a multi-function string helper island with ANSI/wide sentinel use and `StringBase<wchar_t>` vtable/RTTI name evidence. The page now explains that `SimpleUString` is the coordination/facade page while pointer-backed source placement remains with `StringBase`. Final C++ stays blank because the public API and representation relationship remain below the 95/95 gate.
- 2026-06-02: Raised the class page to `70/82`, attached it to [UID:0000OB][StringUtil](by-file/StringUtil.md), and added status, representation map, autogen rationale, and score rationale. Final C++ remains blank because the `SimpleUString` versus `StringBase` API split is unresolved.

- 2026-05-30: Existing class summary treated `0x00421310-0x004216cb` as one early `SimpleUString` helper neighborhood. Changed this to endpoint-only `SimpleUString` ownership and linked the exact child pages, while retaining the historical aggregate as a mixed-island map. Evidence: IDA MCP function inventory/decompilation/byte audit for `0x00421310-0x004216cb`.

- 2026-05-31: The pointer-backed family now links exact IDA-confirmed child pages for the formatting constructors/workers and wide compare helpers.
  - Before: the class page listed only raw address rows for the pointer-backed family and left reconstructable metadata blank.
  - After: marked the class reconstructable, linked exact split memory pages, and raised scores modestly to reflect verified boundaries and behavior.
  - Evidence: IDA MCP `lookup_funcs`, `decompile`, `callers`, `callees`, sentinel `xrefs_to`, and byte checks for `0x00583210`, `0x00583280`, `0x00583720`, `0x00583840`, `0x005840f0`, and `0x005845b0`.
- 2026-06-03: refreshed the formatting-worker links to corrected half-open ranges `0x00583720-0x00583832` and `0x00583840-0x00583968`.
