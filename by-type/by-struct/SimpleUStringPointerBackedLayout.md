*** UID:0001W4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Layout-only view: the one-pointer StringBase receiver layout is represented by [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md) and exact StringBase child helper bodies; this page owns no standalone C++ declaration.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SimpleUStringPointerBackedLayout

## Status

- Entity kind: inferred struct/layout
- Direct owner: [UID:0000OA][StringBase](by-file/StringBase.md)
- Alias/context owner: [UID:0000D9][SimpleUString](by-class/SimpleUString.md), because older recovery labels use `SimpleUString` for some wrappers.
- Proposed header: `util/StringUtil.h`
- Confidence: strong for the pointer/header layout, sentinel/header use, and `StringBase` source-owner placement; medium-high for final public API spelling.

## Direct Parent Decision

The canonical owner/emitter route stays [UID:0000OA][StringBase](by-file/StringBase.md). The child layout now clears the corrected gate at `87/89`, and the direct parent is `91/90`. This page describes the one-pointer object view consumed by the ref-counted ANSI/UTF-16 `StringBase` helper family, not the early 24-byte SSO object. It emits only a layout marker because [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md) and exact child helper bodies already carry the useful source representation. `SimpleUString` remains a search alias and facade context, but compiler metadata and the exact helper aggregate place the storage declaration with `StringBase.cpp`.

## Layout Hypothesis

The pointer-backed `SimpleUString` / `StringBase` family stores a pointer to shared or allocated character data. The same 12-byte header prefix is used for ANSI and UTF-16 buffers; the object field points at character data, and the header immediately before it stores refcount, length, and capacity.

Observed access pattern:

| Expression | Meaning |
| --- | --- |
| `this->m_data` | Pointer to ANSI or UTF-16 character data, depending on specialization/helper. |
| `((int *)this->m_data)[-3]` | Reference count; formatting workers detach when this is greater than one. |
| `((int *)this->m_data)[-2]` | Stored character count; `0x005845b0` uses this as the left range length. |
| `((int *)this->m_data)[-1]` | Capacity; formatting workers grow when this is smaller than the estimated/required capacity. |
| shared sentinel at `0x00670278` / `0x00670290` | Empty/default wide and ANSI storage used by varargs initializer wrappers and release paths. |

## Evidence

- [UID:0002LJ][0x00583210-0x00583273.StringBaseAnsiFormatCtor](by-memory/0x00583210-0x00583273.StringBaseAnsiFormatCtor.md) seeds the object with the ANSI empty sentinel `0x00670290` before forwarding ANSI varargs to [UID:0002LL][0x00583720-0x00583832.StringBaseAnsiVFormatWorker](by-memory/0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md).
- [UID:0002LK][0x00583280-0x005832e3.StringBaseWideFormatCtor](by-memory/0x00583280-0x005832e3.StringBaseWideFormatCtor.md) seeds the object with the wide empty sentinel `0x00670278` before forwarding wide varargs to [UID:0002LM][0x00583840-0x00583968.StringBaseWideVFormatWorker](by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md).
- [UID:0002LL][0x00583720-0x00583832.StringBaseAnsiVFormatWorker](by-memory/0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md) and [UID:0002LM][0x00583840-0x00583968.StringBaseWideVFormatWorker](by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md) both test `data[-3]` for sharing, compare/grow against `data[-1]` capacity, and write final length into `data[-2]`.
- [UID:0002LO][0x005845b0-0x005845ec.StringBaseCompareWideLiteral](by-memory/0x005845b0-0x005845ec.StringBaseCompareWideLiteral.md) computes `lhsEnd = lhsBegin + 2 * lhsBegin[-2]`, then compares against a NUL-terminated literal range through [UID:0002LN][0x005840f0-0x0058415a.WideRangeCompare](by-memory/0x005840f0-0x0058415a.WideRangeCompare.md).
- [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md) records the same 12-byte header prefix from allocation/release/copy-on-write helpers.
- 2026-06-08 Batch140 live IDA refresh reconfirmed the exact key helper starts and sizes: `0x00583210` size `0x63`, `0x00583280` size `0x63`, `0x00583720` size `0x112`, `0x00583840` size `0x128`, `0x005840f0` size `0x6a`, and `0x005845b0` size `0x3c`. The callee sets still match the StringBase model: formatting wrappers funnel into the ANSI/wide workers, workers call the allocation/release helpers and CRT secure-format routines, and the literal compare wrapper calls the range comparator.
- The same refresh found preserved `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` names in vtable/RTTI globals around `0x0061fcd4`, `0x0061fcec`, `0x0061ff70`, `0x0062004c`, `0x00620094`, `0x00622cf4`, and related `0x0064c6xx-0x0064caxx` RTTI records.

## Operational Model

- The object-level layout is one pointer-sized field: `m_data` points directly at character data. All size/ownership metadata is stored in the 12-byte [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md) immediately before that pointer.
- [UID:00040Q][0x004f0380-0x004f03bb.LanguageManCopyLocalizedString](by-memory/0x004f0380-0x004f03bb.LanguageManCopyLocalizedString.md) is a consumer of this pointer-backed wide-string family through `0x00582560(out, selectedStringOrFallback)`. The helper proves an output-object ABI for localized text but not the final public facade name; `StringBase<wchar_t>` is strongest, with `SimpleUString`, `WideString`, or a typedef/facade still plausible.
- The ANSI and UTF-16 format constructor wrappers initialize `m_data` to the corresponding empty sentinel before forwarding to the varargs worker. This means an empty default/wrapper object is still represented by a valid shared data pointer, not by `nullptr`.
- The ANSI worker uses `strlen(format) + 64` as the initial capacity estimate, while the wide worker uses `wcslen(format) + 64`. Both obtain CRT stdio options, call the matching `__stdio_common_vsnprintf_s`/`__stdio_common_vsnwprintf_s` helper, and retry with a larger buffer on truncation or failure.
- Both format workers detach when `refCount > 1`, preserve old content through `memmove`, release the previous storage through the ANSI or wide release helper, and write the final character count back to `data[-2]`.
- `StringBaseCompareWideLiteral` proves the wide consumer convention: `data[-2]` is a character count, and wide range endpoints advance by `2 * length` bytes before delegating to the range comparator.

## Boundary And Owner Caveats

- Prefer [UID:0000OA][StringBase](by-file/StringBase.md) / [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md) as the source-structure owner for this layout. Older `SimpleUString` labels remain useful search aliases, but compiler metadata preserves `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` in callback-template vtable names.
- Keep this page separate from [UID:0001W5][SimpleUStringSso7Layout](by-type/by-struct/SimpleUStringSso7Layout.md). The SSO-7 object embeds inline UTF-16 storage and stores length/capacity at object offsets `+0x10/+0x14`; this layout stores only a data pointer and relies on `data[-3..-1]`.
- Do not emit a standalone declaration shell from this layout page. The exact helper families under `0x005832f0-0x00584d7e` are now split into source-bearing or reviewed-container children, but a separate `SimpleUStringPointerBackedLayout` struct/class declaration would duplicate [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md) and invent unresolved public facade/API shape.

## Open Questions

- Final public API spelling: `StringBase<wchar_t>`, a `SimpleUString` facade over it, or another original template/type alias.
- Exact names and signatures for the remaining helper functions in [UID:0001J2][0x00583210-0x005832f0.StringBaseFormatConstructors](by-memory/0x00583210-0x005832f0.StringBaseFormatConstructors.md) and [UID:0001J3][0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md).

## Score Rationale

- Completion is `87` because the page now records the one-pointer object model, direct `StringBase` parent decision, sentinel initialization, ANSI/wide formatting-worker behavior, detach/grow/update semantics, wide literal compare convention, owner/template metadata, SSO-7 boundary, and no-standalone-code marker route. It remains below final-source quality because the public facade/API declaration remains unresolved.
- Confidence is `89` because the header offsets, sentinel addresses, formatting worker behavior, wide compare convention, helper boundary refresh, accepted wide search/splice child splits, and preserved `mystr::StringBase<wchar_t,...>` metadata all agree. Confidence remains below final confidence because public facade naming is still unresolved.

## Cross-References

- [UID:0000OB][StringUtil](by-file/StringUtil.md)
- [UID:0000OA][StringBase](by-file/StringBase.md)
- [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md)
- [UID:0000D9][SimpleUString](by-class/SimpleUString.md)
- [UID:0001J2][0x00583210-0x005832f0.StringBaseFormatConstructors](by-memory/0x00583210-0x005832f0.StringBaseFormatConstructors.md)
- [UID:0001J3][0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md)
- [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md)
- [UID:0002LJ][0x00583210-0x00583273.StringBaseAnsiFormatCtor](by-memory/0x00583210-0x00583273.StringBaseAnsiFormatCtor.md)
- [UID:0002LK][0x00583280-0x005832e3.StringBaseWideFormatCtor](by-memory/0x00583280-0x005832e3.StringBaseWideFormatCtor.md)
- [UID:0002LL][0x00583720-0x00583832.StringBaseAnsiVFormatWorker](by-memory/0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md)
- [UID:0002LM][0x00583840-0x00583968.StringBaseWideVFormatWorker](by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md)
- [UID:0002LN][0x005840f0-0x0058415a.WideRangeCompare](by-memory/0x005840f0-0x0058415a.WideRangeCompare.md)
- [UID:0002LO][0x005845b0-0x005845ec.StringBaseCompareWideLiteral](by-memory/0x005845b0-0x005845ec.StringBaseCompareWideLiteral.md)
- [UID:00040Q][0x004f0380-0x004f03bb.LanguageManCopyLocalizedString](by-memory/0x004f0380-0x004f03bb.LanguageManCopyLocalizedString.md)

## Changes

- 2026-06-30 B011 [UID:0000OA][StringBase](by-file/StringBase.md) empty-emitter implementation:
  - Before: `COMPLETION:86`, `CONFIDENCE:88`, formal C++ blank and stale caveat that the neighboring release/mutation continuation was not fully split in this page.
  - After: `COMPLETION:87`, `CONFIDENCE:89`, formal layout-only marker comment populated.
  - Summary/evidence: incorporated accepted B011 report `0000OA-StringBase-empty-emitter-family-source-quality.md`. The one-pointer receiver layout remains source-relevant evidence, but a standalone declaration would duplicate [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md) and guess public facade/API shape. Exact method/helper behavior is represented by source-bearing StringBase children, including the accepted format, suffix, comparator, wide search, and splice/grow/substring pages.
- Before: the page was ungraded and described only a narrow wide-string pointer hypothesis with `m_data[-2]` and sentinel references.
- Changed to: marked the layout reconstructable, documented the 12-byte ref-counted header fields, and tied each field to IDA-confirmed exact child functions.
- Evidence: IDA MCP `lookup_funcs`, `decompile`, `callers`, `callees`, `xrefs_to`, and byte checks on 2026-05-31 for the constructor/format/compare helpers listed above. Scores remain below `95+` because final original type naming, source-file ownership, and the remaining un-split helper family are still open.
- 2026-06-03: refreshed the formatting-worker links to the corrected half-open IDA ranges `0x00583720-0x00583832` and `0x00583840-0x00583968`.
- 2026-06-07 A006 documentation pass:
  - Before: the page was `74/82` and listed the core pointer/header evidence without a consolidated operational model.
  - After: raised to `80/84`.
  - Summary/evidence: added sentinel initialization behavior, ANSI/wide format-worker capacity/retry/detach semantics, `data[-2]` wide literal compare convention, `StringBase` owner preference, explicit SSO-7 boundary, and a score rationale tied to the remaining release/mutation-family and final API-name caveats.
- 2026-06-08 A006 Batch140 parent-gate update:
  - Before: `COMPLETION:80`, `CONFIDENCE:84`, `AUTOGEN_PARENT_UID` blank.
  - After: `COMPLETION:86`, `CONFIDENCE:88`, `AUTOGEN_PARENT_UID:0000OA`.
  - Summary/evidence: live IDA reconfirmed the key wrapper/worker/compare helper sizes and callee relationships, and `StringBase` vtable/RTTI names remain preserved in compiler metadata. The direct source parent is [UID:0000OA][StringBase](by-file/StringBase.md), while [UID:0000D9][SimpleUString](by-class/SimpleUString.md) remains alias/facade context.
- 2026-06-21 B007 LanguageMan copy-helper support update:
  - Score unchanged.
  - Summary/evidence: added [UID:00040Q][0x004f0380-0x004f03bb.LanguageManCopyLocalizedString](by-memory/0x004f0380-0x004f03bb.LanguageManCopyLocalizedString.md) as a concrete output-object consumer of the pointer-backed wide-string family through assignment helper `0x00582560`. This supports `StringBase<wchar_t>` as the current best family while preserving the public facade-name caveat.
