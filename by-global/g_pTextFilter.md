*** UID:0000SG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
TextFilter *g_pTextFilter = 0;

template <>
Singleton<TextFilter>::Singleton()
{
    g_pTextFilter = static_cast<TextFilter *>(this);
}

template <>
Singleton<TextFilter>::~Singleton()
{
    g_pTextFilter = 0;
}

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pTextFilter

## Status

- Symbol kind: global singleton pointer.
- Address: `0x0067adc8`.
- Type: `TextFilter *`.
- Static image value: `0x00000000` / `nullptr`.
- Exact storage child: [UID:0002XT][0x0067adc8-0x0067adcc.g_pTextFilter](by-memory/0x0067adc8-0x0067adcc.g_pTextFilter.md).
- Owner/emitter route: [UID:0000OO][TextFilter](by-file/TextFilter.md), projected to `NexusTK/ui/controls/TextFilter.cpp`.
- Score: `92/95`; exact storage, lifecycle, specialization source ownership, and emitter order are resolved.
- Formal C++ policy: this semantic global page owns the sole source definition, then the explicit `Singleton<TextFilter>` constructor specialization, then the explicit destructor specialization, followed by lifecycle `[[CHILDREN]]` in exact order UID00050B position `0` and UID00050C position `1`. Exact storage child [UID:0002XT][0x0067adc8-0x0067adcc.g_pTextFilter](by-memory/0x0067adc8-0x0067adcc.g_pTextFilter.md) carries only a covered-by marker and must not duplicate the definition.
- MCP provenance: the dated 2026-08-02 accepted evidence snapshot used IDA MCP session `ff68e691`; stale `0xffffffff` py_eval-era wording was superseded. Live session and canonical-disk authority are re-established dynamically by the supervisor.

## Purpose

`g_pTextFilter` stores the process-wide [UID:0000EQ][TextFilter](by-class/TextFilter.md) singleton. Startup constructs a four-byte object; the inlined explicit `Singleton<TextFilter>` constructor specialization publishes the complete-object pointer. The matching specialization clears it during ordinary destruction. User-text submission paths read the pointer as context before calling [UID:0000TK][SanitizeWideTextForChat](by-global/SanitizeWideTextForChat.md), but the sanitizer body itself is a free helper and does not consume `ecx`.

Treat the surrounding `0x0067adc4-0x0067adec` storage cluster as physical adjacency only. Neighboring singleton slots belong to system-message/chat/clan UI modules; this declaration belongs with [UID:0000OO][TextFilter](by-file/TextFilter.md).

## MCP Evidence

B003's accepted report used live IDA MCP session `ff68e691`:

- `get_bytes 0x0067adc8-0x0067adcc` returns `00 00 00 00`, SHA16 `df3f619804a92fdb`.
- `get_int 0x0067adc8` returns `0x00000000`.
- The prior `0xffffffff` static-image claim is stale and rejected.
- `xrefs_to 0x0067adc8` reports 19 refs:
  - article caller refs `0x00477617`, `0x00477630`;
  - mail caller refs `0x0047de1d`, `0x0047de31`;
  - shutdown read `0x004f667d`;
  - profile caller ref `0x0053fe22`;
  - constructor writes `0x00595771`, `0x00595784`;
  - destructor clears `0x005957a6`, `0x005958e0`;
  - party/spell/say/shout sanitizer-user refs `0x0059e4a7`, `0x005ae0c8`, `0x005b16a8`, `0x005b1ac8`, `0x005b1fe8`, `0x005b23f8`, `0x005b36f9`, `0x005b3ac9`, and `0x005b42da`.

Related class/vtable facts:

- [UID:00050B][0x00595760-0x00595795.TextFilterConstructor](by-memory/0x00595760-0x00595795.TextFilterConstructor.md) emits the empty authored derived constructor body; the observed pointer store is emitted once through this semantic global's `Singleton<TextFilter>` constructor specialization.
- [UID:00050C][0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody](by-memory/0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md) emits the empty authored derived destructor body; the observed pointer clear is emitted once through this semantic global's `Singleton<TextFilter>` destructor specialization.
- [UID:00050E][0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor](by-memory/0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor.md) is no-code compiler glue that calls the ordinary destructor and conditionally invokes `operator delete`.
- [UID:0002OZ][0x0062e184-0x0062e18c.TextFilterVtableData](by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md) records the one-slot vtable data whose destructor slot reaches the scalar wrapper.

## Users

Read refs before sanitizer use appear in article, mail, profile, party-search, spell-string, say-target, normal say, chat/recipient, and shout paths:

- [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md).
- [UID:000096][NewMailDialog](by-class/NewMailDialog.md).
- [UID:0000AU][ProfileDialog](by-class/ProfileDialog.md).
- [UID:0000A7][PartySearchEditPane](by-class/PartySearchEditPane.md).
- [UID:0000DU][SpellStringInputPane](by-class/SpellStringInputPane.md).
- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md).
- [UID:0000C3][SayInputPane](by-class/SayInputPane.md).
- [UID:0000D5][ShoutInputPane](by-class/ShoutInputPane.md).

These callers prove shared use, not caller ownership. The global remains owned by the `TextFilter` source root.

## First-Draft C++ Routing

This semantic global page emits the sole zero-initialized pointer definition, explicit class-specific Singleton constructor/destructor specializations, and `[[CHILDREN]]` in source position `4`. The effective emitter-child order is empty derived constructor [UID:00050B][0x00595760-0x00595795.TextFilterConstructor](by-memory/0x00595760-0x00595795.TextFilterConstructor.md) at position `0`, followed by empty derived destructor [UID:00050C][0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody](by-memory/0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md) at position `1`. Because `[[CHILDREN]]` follows both specialization bodies in formal CPP, neither lifecycle definition precedes the specializations it relies on.

The physical storage child [UID:0002XT][0x0067adc8-0x0067adcc.g_pTextFilter](by-memory/0x0067adc8-0x0067adcc.g_pTextFilter.md) emits no second object. [UID:0000EQ][TextFilter](by-class/TextFilter.md) owns `extern TextFilter *g_pTextFilter;` in formal H, so formal H remains blank here.

## Rejected Alternatives And Superseded Assumptions

| Alternative / stale assumption | Decision | Reason |
| --- | --- | --- |
| Static image value `0xffffffff` | Rejected | The dated `ff68e691` bytes/int evidence snapshot showed zero-filled storage; live authority is re-established dynamically. |
| `g_chatTextFilter` | Historical alias only | Existing project docs and source route use `g_pTextFilter`; constructor/destructor xrefs tie this exact pointer to `TextFilter`. |
| Caller-feature ownership | Rejected | Callers read the singleton before sanitizer use, but they do not own the declaration. |
| UI/chat/clan singleton cluster as one source struct | Rejected | Adjacent storage slots are physical adjacency, not a source-level aggregate. |
| Duplicate C++ on by-global and by-memory storage pages | Rejected | This semantic global page emits the sole definition/specializations; the exact storage child is covered-by evidence only. |

## Cross-References

- [UID:0000OO][TextFilter](by-file/TextFilter.md)
- [UID:0000EQ][TextFilter](by-class/TextFilter.md)
- [UID:0000TK][SanitizeWideTextForChat](by-global/SanitizeWideTextForChat.md)
- [UID:0001YY][TextFilterVtable](by-type/by-vtable/TextFilterVtable.md)
- [UID:0001JU][0x00595760-0x005958fe.TextFilterAndSanitizer](by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md)
- [UID:00050B][0x00595760-0x00595795.TextFilterConstructor](by-memory/0x00595760-0x00595795.TextFilterConstructor.md)
- [UID:00050C][0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody](by-memory/0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md)
- [UID:00050E][0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor](by-memory/0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor.md)
- [UID:0002XT][0x0067adc8-0x0067adcc.g_pTextFilter](by-memory/0x0067adc8-0x0067adcc.g_pTextFilter.md)
- [UID:0002OZ][0x0062e184-0x0062e18c.TextFilterVtableData](by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md)
- [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md)

## Changes

- 2026-08-05 B001 source-order callback:
  - Preserved the sole pointer definition and both explicit Singleton specialization bodies, then bound lifecycle children in exact order UID00050B position `0` followed by UID00050C position `1`. This corrects specialization-before-use ordering without changing scores, source ownership, formal H, or any binary evidence.
- 2026-06-23 B003 accepted split implementation:
  - Raised `86/88 -> 88/90`.
  - Corrected stale `0xffffffff` initializer to current zero/null evidence, preserved the 19 xrefs, linked exact storage child [UID:0002XT][0x0067adc8-0x0067adcc.g_pTextFilter](by-memory/0x0067adc8-0x0067adcc.g_pTextFilter.md), and routed the source definition to the storage child only.
- 2026-06-07 A008 historical state:
  - Split exact storage context [UID:0002XT][0x0067adc8-0x0067adcc.g_pTextFilter](by-memory/0x0067adc8-0x0067adcc.g_pTextFilter.md) from the mixed UI/chat/clan singleton run. That storage split remains valid and is now refreshed with current zero-byte evidence.

## Singleton Specialization Source Ownership - 2026-08-03

- Exact storage `[0x0067adc8,0x0067adcc)` is loader-zero-filled and has 19 xrefs. Its semantic C++ definition belongs here because this by-global page owns the symbol; the physical by-memory page documents storage only.
- RTTI for `TextFilter : public Singleton<TextFilter>` records direct public non-virtual base PMD `{4,-1,0}`. Constructor writes `0x00595771`/`0x00595784` and ordinary-destructor clear `0x005957a6` are the inlined class-specific Singleton specialization bodies represented in formal CPP above.
- The null-preserving `static_cast<TextFilter *>(this)` reflects the +4 base-to-derived adjustment without copying decompiler control flow into source. The four-byte object size remains consistent with empty-base optimization.
- [UID:00050B][0x00595760-0x00595795.TextFilterConstructor](by-memory/0x00595760-0x00595795.TextFilterConstructor.md) and [UID:00050C][0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody](by-memory/0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md) remain canonically class-owned empty authored bodies, but emit here as ordered children `0` then `1` after both explicit specializations. [UID:00050E][0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor](by-memory/0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor.md) is compiler-only and no-code.
- Historical attribution correction: older docs treated the lifecycle writes/clear as derived-body statements and let the physical storage child emit the definition. Those observations remain binary facts, but the accepted source topology moves them to the semantic global specialization emitter and leaves the storage child covered-by.
- Historical identity correction: former TextFilter links to MIDI UIDs `00041H`/`00041I`/`00041K` were copied identities. Fresh children `00050B`/`00050C`/`00050E` are authoritative; genuine MIDI pages are unchanged.
