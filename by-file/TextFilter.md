*** UID:0000OO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# TextFilter

## Status

- Source root: `TextFilter.cpp`.
- Proposed reconstruction folder: `NexusTK/ui/controls/`.
- Disposition: reconstructable source family for the `TextFilter` startup singleton, the shared user-text sanitizer helper, and the `g_pTextFilter` singleton pointer.
- Score: `92/94`; the complete header/source order, lifecycle specialization model, helper ABI, exact child graph, and compiler-only exclusions are documented.
- Main code aggregate: [UID:0001JU][0x00595760-0x005958fe.TextFilterAndSanitizer](by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md).
- Exact singleton storage: [UID:0002XT][0x0067adc8-0x0067adcc.g_pTextFilter](by-memory/0x0067adc8-0x0067adcc.g_pTextFilter.md).
- Vtable data: [UID:0002OZ][0x0062e184-0x0062e18c.TextFilterVtableData](by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md).
- Evidence provenance: the dated 2026-08-02 accepted snapshot used IDA MCP session `ff68e691`; stale `261fb29b` and older offline/fallback wording were superseded. Live session and canonical-disk authority are re-established dynamically by the supervisor.

## Source Family Contents

| Entity | Page / range | Source-output policy |
| --- | --- | --- |
| `TextFilter::TextFilter()` | [UID:00050B][0x00595760-0x00595795.TextFilterConstructor](by-memory/0x00595760-0x00595795.TextFilterConstructor.md) | Canonically owned by [UID:0000EQ][TextFilter](by-class/TextFilter.md); emits through [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md) position `0` after both explicit Singleton specializations. |
| `TextFilter::~TextFilter()` | [UID:00050C][0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody](by-memory/0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md) | Canonically owned by [UID:0000EQ][TextFilter](by-class/TextFilter.md); emits through [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md) position `1` after both specializations and UID00050B. |
| `SanitizeWideTextForChat` | [UID:00050D][0x005957c0-0x005958ca.SanitizeWideTextForChat](by-memory/0x005957c0-0x005958ca.SanitizeWideTextForChat.md) and [UID:0000TK][SanitizeWideTextForChat](by-global/SanitizeWideTextForChat.md) | The exact by-memory child emits first-draft helper C++; the by-global page indexes/routes the helper and does not duplicate the body. |
| `TextFilter` scalar deleting destructor | [UID:00050E][0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor](by-memory/0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor.md) | Compiler-generated no-code wrapper; generated from the class destructor/vtable. |
| `g_pTextFilter` | [UID:0002XT][0x0067adc8-0x0067adcc.g_pTextFilter](by-memory/0x0067adc8-0x0067adcc.g_pTextFilter.md) and [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md) | The semantic global emits the sole pointer definition and two explicit `Singleton<TextFilter>` specialization bodies; the physical storage page is covered-by and does not duplicate the definition. |
| `TextFilter` vtable/RTTI data | [UID:0001YY][TextFilterVtable](by-type/by-vtable/TextFilterVtable.md) and [UID:0002OZ][0x0062e184-0x0062e18c.TextFilterVtableData](by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md) | Compiler-emitted data; no hand-authored vtable C++. |

## File Role

`TextFilter.cpp` is a tiny user-text filtering source root. The class instance is constructed during application startup, stored in `g_pTextFilter`, and cleared during teardown. The behavior-heavy routine is the neighboring free helper `SanitizeWideTextForChat`, which edits writable UTF-16 buffers in place before article, mail, profile, spell, party-search, say, chat/recipient, and shout submission flows serialize user-authored text.

The file-level source should keep ordinary source constructs rather than decompiler artifacts. Exact translation-unit order is `#include "TextFilter.h"`, sole pointer definition, constructor specialization, destructor specialization, empty constructor, empty destructor, then sanitizer and applicable covered-by output:

- `TextFilter::TextFilter()` and `TextFilter::~TextFilter()` are empty authored derived bodies; the class-specific `Singleton<TextFilter>` constructor/destructor specializations publish and clear `g_pTextFilter`.
- `SanitizeWideTextForChat(wchar_t *text, unsigned int textLength)` is a free `__stdcall` helper, not a member or virtual function.
- `TextFilter *g_pTextFilter = 0;` is the sole source definition, owned by the semantic global page; physical storage is loader-zero-filled.
- Vtable stores, the decompiler's `this == -4` branch, deleting flags, object-size pushes, delete-helper calls, and RTTI/vtable dwords are compiler output and should not be hand-authored source.

## MCP Evidence Incorporated

B003's accepted split report used live IDA MCP session `ff68e691`:

- `lookup_funcs` confirmed child function ranges:
  - constructor `0x00595760-0x00595795`, size `0x35`, SHA16 `0de8157fbaa29517`;
  - non-deleting destructor body `0x005957a0-0x005957b1`, size `0x11`, SHA16 `c020601bb4db048c`;
  - sanitizer `0x005957c0-0x005958ca`, size `0x10a`, SHA16 `d06aa427134dc3d3`;
  - scalar deleting destructor `0x005958d0-0x005958fe`, size `0x2e`, SHA16 `decc5293dda7446a`.
- `get_bytes` confirmed internal padding spans `0x00595795-0x005957a0`, `0x005957b1-0x005957c0`, `0x005958ca-0x005958d0`, and tail padding `0x005958fe-0x00595900`.
- `xrefs_to 0x00595760` reported the one startup constructor caller at `0x004f615f`.
- `xrefs_to 0x005957a0` reported zero direct refs, preserving the ordinary destructor body caveat.
- `xrefs_to 0x005957c0` reported 14 code xrefs across 12 user-text submission/dialog functions.
- `xrefs_to 0x005958d0` reported the vtable data xref at `0x0062e188`; shutdown reaches it indirectly through `g_pTextFilter` and the vtable slot.
- `get_bytes/get_int` for `0x0062e184-0x0062e18c` confirmed bytes `18 15 65 00 d0 58 59 00`, SHA16 `50df7549f68dce6b`, `0x0062e184 -> 0x00651518`, `0x0062e188 -> 0x005958d0`, and exact excluded-boundary successor `0x0062e18c -> 0x006515b4`. The former `0x006517b4` literal was a transposed report/document value and is retained only as this dated rejected historical correction, not current MCP evidence.
- `get_bytes/get_int` for `0x0067adc8-0x0067adcc` confirmed `00 00 00 00`, SHA16 `df3f619804a92fdb`, and integer value `0x00000000`.

## Source Placement Decision

Keep `NexusTK/ui/controls/TextFilter.cpp` as the current source root.

Evidence for the current route:

- `by-project-structure/proposed-source-tree.md` places `TextFilter.cpp` under `ui/controls` beside text-edit control sources.
- The `TextFilter` class, singleton pointer, vtable data, and sanitizer helper form one source-family cluster with current owner/emitter routes.
- The sanitizer caller spread is broad but still UI/user-text submission focused.
- [UID:0001JT][0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter](by-memory/0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md) preserves the TextEdit support-object adjacency as a mixed audit aggregate, not as file ownership.

Rejected or residual alternatives:

| Candidate | Decision | Reason |
| --- | --- | --- |
| [UID:0000ON][TextEditPane](by-file/TextEditPane.md) | Rejected | Physical adjacency is not enough; startup singleton/vtable/global evidence and broad caller use make this a separate TextFilter source. |
| Forced `NexusTK/util/TextFilter.cpp` | Rejected as primary | No source path, symbol, import, or non-UI utility consumer proves generic utility placement. Keep only as a residual folder caveat. |
| Article/mail/profile/say/shout/spell/party-search caller files | Rejected | They consume the sanitizer helper but do not own the shared declaration or storage. |
| Packet/socket/network modules | Rejected | The helper runs before serialization and never owns packet/socket state. |
| No-owner/non-emitting | Rejected | The file, class, global, vtable, and helper routes are coherent and clear the accepted gate. |

## C++ Policy

This by-file page is the source root and has no formal CPP/H channel. Exact output is routed in source order through class/global/helper and exact-child pages:

- [UID:0000EQ][TextFilter](by-class/TextFilter.md) position `0` emits `#include "TextFilter.h"` and the class-owned source shell.
- [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md) position `4` emits the sole pointer definition, constructor specialization, destructor specialization, then ordered lifecycle children: [UID:00050B][0x00595760-0x00595795.TextFilterConstructor](by-memory/0x00595760-0x00595795.TextFilterConstructor.md) position `0`, followed by [UID:00050C][0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody](by-memory/0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md) position `1`.
- [UID:0000TK][SanitizeWideTextForChat](by-global/SanitizeWideTextForChat.md) position `8` routes exact helper child [UID:00050D][0x005957c0-0x005958ca.SanitizeWideTextForChat](by-memory/0x005957c0-0x005958ca.SanitizeWideTextForChat.md), followed by applicable covered-by output.

The aggregate [UID:0001JU][0x00595760-0x005958fe.TextFilterAndSanitizer](by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md), physical storage [UID:0002XT][0x0067adc8-0x0067adcc.g_pTextFilter](by-memory/0x0067adc8-0x0067adcc.g_pTextFilter.md), and vtable pages carry covered-by comments. Scalar wrapper [UID:00050E][0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor](by-memory/0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor.md) remains blank-C++/H compiler glue.

Historical stale assumptions superseded by this implementation:

- Old 95+ code gate wording no longer blocks exact child/source C++.
- `g_pTextFilter` is not statically initialized to `0xffffffff`; current bytes are `00 00 00 00`.
- Older helper names `NormalizeChatText`, `ApplyOutboundChatFilter`, and `g_chatTextFilter` are search/history aliases only.
- A `TextFilter *` sanitizer/member signature is rejected by two-stack-argument `retn 8` and no-`ecx` callee evidence.

## Cross-References

- [UID:0000EQ][TextFilter](by-class/TextFilter.md)
- [UID:0001JU][0x00595760-0x005958fe.TextFilterAndSanitizer](by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md)
- [UID:00050B][0x00595760-0x00595795.TextFilterConstructor](by-memory/0x00595760-0x00595795.TextFilterConstructor.md)
- [UID:00050C][0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody](by-memory/0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md)
- [UID:00050D][0x005957c0-0x005958ca.SanitizeWideTextForChat](by-memory/0x005957c0-0x005958ca.SanitizeWideTextForChat.md)
- [UID:00050E][0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor](by-memory/0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor.md)
- [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md)
- [UID:0000TK][SanitizeWideTextForChat](by-global/SanitizeWideTextForChat.md)
- [UID:0001YY][TextFilterVtable](by-type/by-vtable/TextFilterVtable.md)
- [UID:0002OZ][0x0062e184-0x0062e18c.TextFilterVtableData](by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md)
- [UID:0002XT][0x0067adc8-0x0067adcc.g_pTextFilter](by-memory/0x0067adc8-0x0067adcc.g_pTextFilter.md)
- [UID:0001JT][0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter](by-memory/0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)

## Changes

- 2026-08-05 B001 source-order callback:
  - Preserved UID0000EQ as canonical lifecycle owner while routing UID00050B/C through UID0000SG positions `0` and `1`. Recorded exact specialization-before-use translation-unit order: include, pointer definition, constructor specialization, destructor specialization, constructor, destructor, sanitizer/covered-by output.
- 2026-06-23 B003 accepted split implementation:
  - Raised `86/88 -> 88/90`.
  - Recorded exact child split, real child UIDs, source-output policy, the then-current `ff68e691` evidence snapshot, zero/null singleton storage, `ui/controls` route retained over forced `util`, and aggregate/scalar/vtable no-code policy; the session identity is dated history rather than permanent authority.
- 2026-06-16 A002 historical state:
  - Raised `85/86 -> 86/88` after live IDA reconfirmed lifecycle/helper extents, singleton/vtable refs, startup constructor caller, sanitizer call sites, and TextEditPane exclusion. Folder/signature blockers then kept C++ blank under older wording; those blockers are superseded for exact child/source emission by the B003 split package.

## Header And Source Emission Plan - 2026-08-03

- `NexusTK/ui/controls/TextFilter.h` is emitted from [UID:0000EQ][TextFilter](by-class/TextFilter.md). It owns the include guard, `../../util/Singleton.h`, `class TextFilter : public Singleton<TextFilter>`, public constructor, virtual destructor, `extern TextFilter *g_pTextFilter`, and `void __stdcall SanitizeWideTextForChat(wchar_t *text, unsigned int textLength);`.
- `NexusTK/ui/controls/TextFilter.cpp` begins with `#include "TextFilter.h"`. Emitter order is class shell position `0`, semantic global position `4`, and semantic sanitizer position `8`.
- [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md) emits `TextFilter *g_pTextFilter = 0;`, the explicit `Singleton<TextFilter>` constructor specialization, the explicit destructor specialization, then lifecycle children [UID:00050B][0x00595760-0x00595795.TextFilterConstructor](by-memory/0x00595760-0x00595795.TextFilterConstructor.md) position `0` and [UID:00050C][0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody](by-memory/0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md) position `1`. Canonical owner UID0000EQ remains unchanged; UID0000SG controls only translation-unit emission.
- [UID:0000TK][SanitizeWideTextForChat](by-global/SanitizeWideTextForChat.md) emits exact helper child [UID:00050D][0x005957c0-0x005958ca.SanitizeWideTextForChat](by-memory/0x005957c0-0x005958ca.SanitizeWideTextForChat.md). [UID:00050E][0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor](by-memory/0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor.md), RTTI, vtable cells, vptr stores, deleting flags, object-size pushes, and null-adjust branches are compiler output and never handwritten source.

## Rejected Alternatives And Historical Correction - 2026-08-03

- Superseded source draft: placing `g_pTextFilter = this` and `g_pTextFilter = nullptr` directly in the derived lifecycle bodies duplicated the proven inlined Singleton specializations. The historical observation of those writes remains valid binary evidence; only the authored source attribution changed.
- Rejected duplicate definition: the physical storage page must not also emit `TextFilter *g_pTextFilter`. Exactly one definition and one pair of explicit specializations belong to the semantic global emitter.
- Rejected source placement: physical adjacency does not move this family into `TextEditPane.cpp`; broad callers do not move it into article/mail/chat/packet modules; raw RTTI/vtable/scalar glue is not authored code.
- Historical identity correction: the earlier TextFilter links to canonical MIDI UIDs `00041H`-`00041K` were copied-UID pollution. Fresh TextFilter identities are constructor `00050B`, destructor `00050C`, sanitizer `00050D`, and scalar wrapper `00050E`; canonical MIDI documentation remains unchanged.
