*** UID:0000EQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "TextFilter.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_CONTROLS_TEXTFILTER_H
#define NEXUSTK_UI_CONTROLS_TEXTFILTER_H

#include "../../util/Singleton.h"

class TextFilter : public Singleton<TextFilter>
{
public:
    TextFilter();
    virtual ~TextFilter();
};

extern TextFilter *g_pTextFilter;

void __stdcall SanitizeWideTextForChat(wchar_t *text, unsigned int textLength);

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TextFilter

## Status

- Disposition: reconstructable NexusTK project class.
- Source root: [UID:0000OO][TextFilter](by-file/TextFilter.md), projected to `NexusTK/ui/controls/TextFilter.cpp`.
- Main code aggregate: [UID:0001JU][0x00595760-0x005958fe.TextFilterAndSanitizer](by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md).
- Vtable/type anchor: [UID:0001YY][TextFilterVtable](by-type/by-vtable/TextFilterVtable.md), exact data child [UID:0002OZ][0x0062e184-0x0062e18c.TextFilterVtableData](by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md).
- Singleton pointer: [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md), exact storage child [UID:0002XT][0x0067adc8-0x0067adcc.g_pTextFilter](by-memory/0x0067adc8-0x0067adcc.g_pTextFilter.md).
- Score: `92/95`; hierarchy, four-byte layout, virtual destructor, singleton lifetime lowering, helper declaration, and source placement are closed to the current source-quality standard.
- Class-level C++ policy: formal CPP owns the `#include "TextFilter.h"` and ordered `[[CHILDREN]]` shell, while formal H owns the complete guarded `TextFilter : public Singleton<TextFilter>` declaration plus the global and `__stdcall` helper declarations. UID00050B/C remain canonically owned by this class, but their exact lifecycle definitions emit through [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md) after both explicit Singleton specializations; this separates semantic ownership from legal translation-unit order without duplicating declarations or definitions.

## Class Purpose

`TextFilter` is a tiny startup singleton class used by client user-text filtering. It is allocated during startup as a 4-byte object, stored in `g_pTextFilter`, and cleared during destruction. The richer text-cleanup routine, [UID:0000TK][SanitizeWideTextForChat](by-global/SanitizeWideTextForChat.md), is a neighboring free helper, not a recovered `TextFilter` method or virtual function.

RTTI, PMD, constructor lowering, and object-size evidence support the accepted source-facing declaration shape:

```cpp
class TextFilter : public Singleton<TextFilter>
{
public:
    TextFilter();
    virtual ~TextFilter();
};
```

Do not overfit the constructor decompiler's `this == -4` artifact. The accepted source shape is now `TextFilter : public Singleton<TextFilter>`: RTTI proves the direct public non-virtual base, while the null-preserving +4 adjustment and four-byte complete object reflect compiler lowering plus empty-base optimization rather than an authored `this == -4` branch.

## Method And Data Inventory

| Role | UID / range | Evidence | Output policy |
| --- | --- | --- | --- |
| Constructor | [UID:00050B][0x00595760-0x00595795.TextFilterConstructor](by-memory/0x00595760-0x00595795.TextFilterConstructor.md) | `0x35` / 53 bytes, SHA16 `0de8157fbaa29517`, startup caller `0x004f615f`, base-specialization writes `0x00595771`/`0x00595784`, vtable stores `0x00595778`/`0x0059578b`. | Canonically class-owned empty `TextFilter::TextFilter()`; emitted through UID0000SG position `0` after both explicit specializations. |
| Non-deleting destructor body | [UID:00050C][0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody](by-memory/0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md) | `0x11` / 17 bytes, SHA16 `c020601bb4db048c`, vtable restore, base-specialization clear at `0x005957a6`, zero direct xrefs. | Canonically class-owned empty `TextFilter::~TextFilter()`; emitted through UID0000SG position `1` after both specializations and UID00050B. |
| Scalar deleting destructor wrapper | [UID:00050E][0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor](by-memory/0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor.md) | `0x2e` / 46 bytes, SHA16 `decc5293dda7446a`, vtable cell `0x0062e188 -> 0x005958d0`, shutdown indirect route, delete helper `0x005c7526`. | Compiler-generated no-code wrapper. |
| Sanitizer helper | [UID:00050D][0x005957c0-0x005958ca.SanitizeWideTextForChat](by-memory/0x005957c0-0x005958ca.SanitizeWideTextForChat.md) and [UID:0000TK][SanitizeWideTextForChat](by-global/SanitizeWideTextForChat.md) | `0x10a` / 266 bytes, SHA16 `d06aa427134dc3d3`, 14 call sites, two stack args, `retn 8`, no `ecx` use. | Free `__stdcall` helper body emits on the exact by-memory child, not on this class page. |
| Singleton storage | [UID:0002XT][0x0067adc8-0x0067adcc.g_pTextFilter](by-memory/0x0067adc8-0x0067adcc.g_pTextFilter.md) | Current bytes `00 00 00 00`, SHA16 `df3f619804a92fdb`, 19 data xrefs. | Sole definition and explicit specialization bodies emit through [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md); storage page is covered-by. |

## MCP Evidence Incorporated

B003's accepted report used IDA MCP session `ff68e691`; stale `261fb29b` is superseded.

Class/type facts:

- `entity_query names *TextFilter*` returns decorated vtable/RTTI names for `TextFilter` and `Singleton<TextFilter>`.
- `??_7TextFilter@@6B@` is at `0x0062e188`.
- `??_R4TextFilter@@6B@` is at `0x00651518`.
- `entity_query names *Sanit*` returns no recovered sanitizer symbol.
- `type_query *TextFilter*`, `*Sanit*`, and `*Singleton*TextFilter*` return no UDT/source type, so declaration/header shape remains inferred.

Lifecycle facts:

- Startup `sub_4F5FB0` allocates 4 bytes, passes the result in `ecx`, and calls `0x00595760`.
- `xrefs_to 0x00595760` reports the one startup constructor call at `0x004f615f`.
- `xrefs_to 0x005957a0` reports zero direct code refs; this is an ordinary destructor-body/lowering caveat, not a source-owner rejection.
- Shutdown reads `g_pTextFilter`, tests it, pushes deleting flag `1`, and calls through vtable slot `0x0062e188`, reaching `0x005958d0`.
- `callees 0x005958d0` reports delete helper `0x005c7526`.

Vtable/global facts:

- `get_int 0x0062e184 -> 0x00651518`; this corrects stale `0x00651718` support text.
- `get_int 0x0062e188 -> 0x005958d0`.
- `get_int 0x0062e18c -> 0x006515b4`, the `TextPad` successor boundary.
- `xrefs_to 0x0062e188` includes constructor stores at `0x00595778`/`0x0059578b`, non-deleting destructor restore at `0x005957a0`, and scalar deleting destructor restore at `0x005958da`.
- `xrefs_to 0x0067adc8` reports 19 refs across constructor writes, destructor clears, shutdown read, and sanitizer-user reads.
- `get_int 0x0067adc8 -> 0x00000000`, so stale `0xffffffff` initializer wording is rejected.

## Destructor Source Representation

The source destructor should be represented exactly once:

- [UID:00050C][0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody](by-memory/0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md) owns the single empty authored `TextFilter::~TextFilter()` body semantically and emits it through UID0000SG position `1`. The observed clear of `g_pTextFilter` is inlined `Singleton<TextFilter>::~Singleton()` specialization behavior, not a derived-body statement; routing through UID0000SG places that specialization before the destructor definition.
- [UID:00050E][0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor](by-memory/0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor.md) remains `RECONSTRUCTABLE:FALSE`, ownerless, and no-code because it is the scalar deleting destructor wrapper that tests a deleting flag, pushes object size `4`, calls delete helper `0x005c7526`, and returns with `retn 4`.

This prevents duplicate generated destructor definitions and keeps compiler ABI glue out of handwritten source.

## Sanitizer Relationship

`SanitizeWideTextForChat` is adjacent to the class lifecycle cluster but is not a `TextFilter` member or virtual method:

- The callee takes exactly two stack arguments and returns with `retn 8`.
- It does not read `ecx`.
- The `TextFilter` vtable has only one confirmed slot, the scalar deleting destructor at `+0x00`.
- Several callers read `g_pTextFilter` before the helper call, but that is singleton/use-context evidence, not callee ABI proof.

The helper belongs with this source family through [UID:0000OO][TextFilter](by-file/TextFilter.md) but emits as a free helper through [UID:0000TK][SanitizeWideTextForChat](by-global/SanitizeWideTextForChat.md) and exact child [UID:00050D][0x005957c0-0x005958ca.SanitizeWideTextForChat](by-memory/0x005957c0-0x005958ca.SanitizeWideTextForChat.md).

## Rejected Alternatives And Superseded Assumptions

| Alternative / stale assumption | Decision | Reason |
| --- | --- | --- |
| Old 95+ gate blocks all C++ | Superseded | Current project gate permits exact emitting children above combined 85 with source-quality proof. |
| `g_pTextFilter` static value `0xffffffff` | Rejected | The dated `ff68e691` bytes/int evidence snapshot showed `00 00 00 00` / `0x00000000`; live authority is re-established dynamically. |
| `NormalizeChatText`, `ApplyOutboundChatFilter`, `g_chatTextFilter` | Historical aliases only | Current source-facing helper/global names are `SanitizeWideTextForChat` and `g_pTextFilter`. |
| `SanitizeWideTextForChat` as `TextFilter` member or virtual | Rejected | No `ecx` use, two stack args, `retn 8`, and no vtable slot. |
| [UID:0000ON][TextEditPane](by-file/TextEditPane.md) class/file ownership | Rejected | Address adjacency is outweighed by startup singleton/vtable/global evidence and broad caller spread. |
| Caller-feature ownership | Rejected | Callers consume the shared helper; they do not own the class. |
| Packet/socket ownership | Rejected | Sanitizer is a pre-serialization buffer filter and does not own packet state. |
| No-owner/non-emitting class | Rejected | Class/file/global/vtable routes are coherent and accepted. Only the scalar wrapper child is no-owner/non-reconstructable. |

## Cross-References

- [UID:0000OO][TextFilter](by-file/TextFilter.md)
- [UID:0001JU][0x00595760-0x005958fe.TextFilterAndSanitizer](by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md)
- [UID:00050B][0x00595760-0x00595795.TextFilterConstructor](by-memory/0x00595760-0x00595795.TextFilterConstructor.md)
- [UID:00050C][0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody](by-memory/0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md)
- [UID:00050D][0x005957c0-0x005958ca.SanitizeWideTextForChat](by-memory/0x005957c0-0x005958ca.SanitizeWideTextForChat.md)
- [UID:00050E][0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor](by-memory/0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor.md)
- [UID:0001YY][TextFilterVtable](by-type/by-vtable/TextFilterVtable.md)
- [UID:0002OZ][0x0062e184-0x0062e18c.TextFilterVtableData](by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md)
- [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md)
- [UID:0002XT][0x0067adc8-0x0067adcc.g_pTextFilter](by-memory/0x0067adc8-0x0067adcc.g_pTextFilter.md)
- [UID:0000TK][SanitizeWideTextForChat](by-global/SanitizeWideTextForChat.md)
- [UID:0001JT][0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter](by-memory/0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md)

## Changes

- 2026-08-05 B001 source-order callback:
  - Preserved UID0000EQ as canonical owner of lifecycle children UID00050B/C while documenting their translation-unit emission through UID0000SG positions `0` and `1` after both explicit Singleton specializations. Class formals, scores, inheritance, declarations, evidence, and source ownership are unchanged.
- 2026-06-23 B003 accepted split implementation:
  - Raised `86/88 -> 88/90`.
  - Added real child UIDs [UID:00050B][0x00595760-0x00595795.TextFilterConstructor](by-memory/0x00595760-0x00595795.TextFilterConstructor.md), [UID:00050C][0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody](by-memory/0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md), [UID:00050D][0x005957c0-0x005958ca.SanitizeWideTextForChat](by-memory/0x005957c0-0x005958ca.SanitizeWideTextForChat.md), and [UID:00050E][0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor](by-memory/0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor.md).
  - Recorded the dated `ff68e691` RTTI/vtable/global evidence snapshot, startup constructor route, shutdown indirect scalar route, non-deleting destructor zero-xref caveat, single destructor-source representation, sanitizer free-helper status, scalar-wrapper no-code policy, and zero/null singleton storage correction.
- 2026-06-16 A001 historical state:
  - Raised `84/86 -> 86/88` after a live IDA recheck. Final C++ stayed blank then because public declaration/source-placement evidence was treated as blocking at page level; the exact child split now carries safe first-draft source bodies.

## Singleton Lifetime Source Shape - 2026-08-03

- RTTI establishes a direct public non-virtual `Singleton<TextFilter>` base with PMD `{4,-1,0}`. The class remains a four-byte complete object because the empty base is optimized while compiler-generated adjustment code still models the base subobject at +4.
- The writes at `0x00595771`/`0x00595784` and clear at `0x005957a6` are inlined explicit-specialization behavior for `Singleton<TextFilter>::Singleton()` and `Singleton<TextFilter>::~Singleton()`. They are not authored assignments in the derived constructor/destructor.
- Consequently [UID:00050B][0x00595760-0x00595795.TextFilterConstructor](by-memory/0x00595760-0x00595795.TextFilterConstructor.md) and [UID:00050C][0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody](by-memory/0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md) remain canonically owned here as the empty authored lifecycle bodies. Their definitions emit through [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md) positions `0` and `1`, after UID0000SG's sole pointer definition and both explicit Singleton specialization bodies. This is specialization-before-use ordering, not a transfer of semantic class ownership.
- The helper declaration is free-function ABI, `void __stdcall SanitizeWideTextForChat(wchar_t *text, unsigned int textLength);`; no `TextFilter` member or virtual slot is inferred.
- Historical assumption retained as rejected: earlier drafts put `g_pTextFilter = this` and `g_pTextFilter = nullptr` directly in the derived bodies. That source shape duplicated the proven base-specialization lowering and is superseded. The old MIDI UID links `00041H`-`00041K` were duplicate identity pollution; fresh TextFilter children `00050B`-`00050E` are authoritative without modifying the canonical MIDI pages.
- Historical correction (2026-08-04): earlier binary-evidence prose transposed the excluded TextPad successor value as `0x006517b4`. Fresh read-only IDA bytes `b4 15 65 00` establish the little-endian value `0x006515b4`; class formals, inheritance, source graph, owner/emitter routes, scores, and the exclusive TextFilter boundary are unchanged.
