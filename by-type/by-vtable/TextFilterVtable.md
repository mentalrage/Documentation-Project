*** UID:0001YY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000EQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000EQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-emitted one-slot TextFilter vtable/RTTI layout.
// Source reconstruction is covered by [UID:0000EQ][TextFilter](by-class/TextFilter.md); no raw vtable array or scalar-deleting-destructor source method is emitted here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TextFilter Vtable

## Status

- Entity kind: vtable/type inventory.
- Address span: `0x0062e184-0x0062e18c`, with primary vtable base at `0x0062e188`.
- Exact vtable-data child: [UID:0002OZ][0x0062e184-0x0062e18c.TextFilterVtableData](by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md).
- Owner class: [UID:0000EQ][TextFilter](by-class/TextFilter.md).
- Owner file: [UID:0000OO][TextFilter](by-file/TextFilter.md).
- Score: `91/95`; the exact one-slot ABI, COL relationship, direct public `Singleton<TextFilter>` base, and authored source route are closed.
- C++ policy: formal CPP carries only the covered-by marker above. The vtable/RTTI dwords and scalar deleting destructor are compiler-emitted from the class declaration and virtual destructor; formal H remains blank.
- MCP provenance: the dated 2026-08-02 accepted evidence snapshot used IDA MCP session `ff68e691`; stale older session details and Wave3 links were superseded. Live session and canonical-disk authority are re-established dynamically by the supervisor.

## Layout

| Slot | Cell | Target | Meaning |
| --- | --- | --- | --- |
| `+0x00` | `0x0062e188` | `0x005958d0` / [UID:00050E][0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor](by-memory/0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor.md) | ABI-facing scalar deleting destructor wrapper generated from `TextFilter::~TextFilter()`. |

This vtable has only one confirmed slot. `0x0062e18c+` is the following `TextPad` RTTI/vtable region, not additional `TextFilter` methods.

## Current MCP Evidence

B003's accepted split report used live IDA MCP session `ff68e691`:

- `get_bytes 0x0062e184-0x0062e18c` returns `18 15 65 00 d0 58 59 00`, SHA16 `50df7549f68dce6b`.
- `get_int 0x0062e184 -> 0x00651518`, the `??_R4TextFilter@@6B@` complete-object-locator pointer.
- `get_int 0x0062e188 -> 0x005958d0`, the scalar deleting destructor wrapper.
- `get_int 0x0062e18c -> 0x006515b4`, the following `TextPad` RTTI-adjacent word.
- `xrefs_to 0x0062e188` reports constructor stores at `0x00595778` and `0x0059578b`, non-deleting destructor-body restore at `0x005957a0`, and scalar deleting destructor restore at `0x005958da`.
- `xrefs_to 0x005958d0` reports the vtable data xref from `0x0062e188`.
- `entity_query names *TextFilter*` returns decorated `TextFilter` and `Singleton<TextFilter>` RTTI/vtable names.

## Source Relationship

The vtable proves the class has a virtual destructor route, but the source should not hand-author vtable data:

- [UID:00050C][0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody](by-memory/0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md) emits the single source destructor body.
- [UID:00050E][0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor](by-memory/0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor.md) documents the generated scalar deleting destructor wrapper and remains no-code.
- [UID:0002OZ][0x0062e184-0x0062e18c.TextFilterVtableData](by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md) documents the exact dwords and carries the same covered-by/no-raw-table source disposition.

The class page remains the semantic parent because it owns the vtable concept; the file page remains the source root. `SanitizeWideTextForChat` is not a vtable method.

## Rejected Alternatives And Stale Assumptions

| Alternative / stale assumption | Decision | Reason |
| --- | --- | --- |
| Treat `0x0062e18c+` as additional `TextFilter` slots | Rejected | `0x0062e18c` is the next `TextPad` RTTI-adjacent word. |
| Hand-author vtable dwords in C++ | Rejected | Vtable and RTTI data are compiler-emitted from the class declaration/destructor. |
| Model `SanitizeWideTextForChat` as a virtual slot | Rejected | Vtable has only the destructor slot; sanitizer is a two-stack-argument free helper. |
| Older "generated metadata incomplete" blocker as lead status | Superseded | Current pages have owner/emitter routes; remaining no-code policy is due to compiler-emitted vtable data, not missing generated metadata. |
| Wave3 data issues link as current evidence | Superseded | The then-current by-* docs and dated `ff68e691` MCP snapshot supported this historical disposition; live authority is re-established dynamically. |

## Cross-References

- [UID:0000OO][TextFilter](by-file/TextFilter.md)
- [UID:0000EQ][TextFilter](by-class/TextFilter.md)
- [UID:0001JU][0x00595760-0x005958fe.TextFilterAndSanitizer](by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md)
- [UID:0002OZ][0x0062e184-0x0062e18c.TextFilterVtableData](by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md)
- [UID:00050C][0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody](by-memory/0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md)
- [UID:00050E][0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor](by-memory/0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor.md)
- [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md)

## Changes

- 2026-06-23 B003 accepted split implementation:
  - Score unchanged at `86/90`.
  - Synchronized stale wording with the dated `ff68e691` evidence snapshot, one-slot vtable layout, exact [UID:0002OZ][0x0062e184-0x0062e18c.TextFilterVtableData](by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md) child, destructor-body/scalar-wrapper split, and no hand-authored vtable C++ policy.
- 2026-06-07 historical parent attachment:
  - Completion was set to `86`, owner/emitter routed through [UID:0000EQ][TextFilter](by-class/TextFilter.md), and the exact vtable-data child was linked. That route remains valid.

## UID0002OZ Rule 26 Incorporation - 2026-08-03

- Layout: the vtable base is the single dword at `0x0062e188`; slot `+0x00` points to `0x005958d0`, the compiler-generated scalar deleting destructor [UID:00050E][0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor](by-memory/0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor.md). The preceding dword `0x0062e184` is the Complete Object Locator pointer and is documented by [UID:0002OZ][0x0062e184-0x0062e18c.TextFilterVtableData](by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md).
- Source relationship: decorated RTTI and the one-slot table are generated from `class TextFilter : public Singleton<TextFilter>` with a virtual destructor. The direct public non-virtual base PMD is `{4,-1,0}`; empty-base optimization preserves a four-byte complete object. The authored declaration belongs to [UID:0000EQ][TextFilter](by-class/TextFilter.md), so this page emits only the covered-by CPP marker and keeps formal H blank.
- Lifecycle routing: [UID:00050B][0x00595760-0x00595795.TextFilterConstructor](by-memory/0x00595760-0x00595795.TextFilterConstructor.md) installs the vptr after base publication, [UID:00050C][0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody](by-memory/0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md) is the one authored destructor body, and [UID:00050E][0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor](by-memory/0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor.md) remains no-code compiler glue.
- Historical correction: the former active links to MIDI UIDs `00041I` and `00041K` were duplicate-identity pollution, not cross-family ownership evidence. The canonical MIDI pages are unaffected; only fresh TextFilter children `00050C` and `00050E` are authoritative here.
- Historical correction (2026-08-04): earlier evidence prose transposed the excluded TextPad successor value as `0x006517b4`. Fresh read-only IDA bytes `b4 15 65 00` establish the little-endian value `0x006515b4`; the one-slot TextFilter layout, covered-by source route, formal channels, scores, and boundary ownership are unchanged.
