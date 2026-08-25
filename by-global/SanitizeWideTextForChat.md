*** UID:0000TK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SanitizeWideTextForChat

## Status

- Symbol kind: recovered source-facing free helper.
- Exact body child: [UID:00050D][0x005957c0-0x005958ca.SanitizeWideTextForChat](by-memory/0x005957c0-0x005958ca.SanitizeWideTextForChat.md).
- Address range: `0x005957c0-0x005958ca`.
- Source-facing signature: `void __stdcall SanitizeWideTextForChat(wchar_t *text, unsigned int textLength)`.
- Owner/emitter route: [UID:0000OO][TextFilter](by-file/TextFilter.md), currently `NexusTK/ui/controls/TextFilter.cpp`.
- Score: `93/94`; the earlier `91/90` assignment state is retained below as history.
- Formal C++ policy: this semantic helper page emits exactly `[[CHILDREN]]` at source position `8`; the exact by-memory child [UID:00050D][0x005957c0-0x005958ca.SanitizeWideTextForChat](by-memory/0x005957c0-0x005958ca.SanitizeWideTextForChat.md) emits the single first-draft body. [UID:0000EQ][TextFilter](by-class/TextFilter.md) owns the header declaration.
- MCP provenance: the dated 2026-08-02 accepted evidence snapshot used IDA MCP session `ff68e691`; stale session `261fb29b` and older fallback/offline wording were superseded. Live session and canonical-disk authority are re-established dynamically by the supervisor.

## Purpose

`SanitizeWideTextForChat` edits a writable UTF-16 buffer in place before user-authored text is serialized into packets. It scans up to `textLength` code units, stops early at NUL, preserves printable ASCII, CR/LF, and a fixed lowercase Latin-1 accent allowlist, and replaces every other nonzero code unit with `?`.

The allowed accented code units are:

```text
0x00e9, 0x00e8, 0x00e0, 0x00f9, 0x00f4, 0x00ee,
0x00eb, 0x00ef, 0x00fb, 0x00fa, 0x00e2, 0x00e7
```

## MCP Evidence

B003's accepted report used live IDA MCP session `ff68e691`:

- `lookup_funcs 0x005957c0` reports `sub_5957C0`, size `0x10a`, ending at exclusive `0x005958ca`.
- `lookup_funcs 0x005958ca` reports no function, confirming the half-open end and following padding.
- `get_bytes 0x005957c0-0x005958ca` returns SHA16 `d06aa427134dc3d3`.
- `get_bytes 0x005958ca-0x005958d0` returns six `0xcc` padding bytes, SHA16 `33cc4a00a0f04735`.
- `callees 0x005957c0` reports no callees.
- Decompilation and disassembly agree on a two-stack-argument helper. The function does not read `ecx`, and the return is `retn 8`.
- `entity_query names *Sanit*` returns no recovered source symbol. `SanitizeWideTextForChat` is therefore inferred/descriptive, but it is behaviorally accurate and consistent with accepted caller reports.

## Caller Families

`xrefs_to 0x005957c0` reports 14 code call sites across 12 functions:

| Call site(s) | Current owner context | Use |
| --- | --- | --- |
| `0x0047762b`, `0x00477641` | [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md) / article submit flow | Sanitizes article subject/body before posting. |
| `0x0047de2c`, `0x0047de3f` | [UID:000096][NewMailDialog](by-class/NewMailDialog.md) / mail submit flow | Sanitizes mail subject/body before sending. |
| `0x0053fe34` | [UID:0000AU][ProfileDialog](by-class/ProfileDialog.md) | Sanitizes profile text before saving/copying. |
| `0x0059e4ae` | [UID:0000A7][PartySearchEditPane](by-class/PartySearchEditPane.md) | Sanitizes party-search text before opcode `0x84`. |
| `0x005ae0cf` | [UID:0000DU][SpellStringInputPane](by-class/SpellStringInputPane.md) | Sanitizes spell string argument before opcode `0x0f`. |
| `0x005b16af`, `0x005b1acf`, `0x005b1fef`, `0x005b23ff` | [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) target/group/plan input family | Sanitizes target-message payloads. |
| `0x005b3700` | [UID:0000C3][SayInputPane](by-class/SayInputPane.md) | Sanitizes normal say text before opcode `0x0e`, subtype `0`. |
| `0x005b3ad0` | chat/recipient input path | Sanitizes chat recipient text before submit. |
| `0x005b42e1` | [UID:0000D5][ShoutInputPane](by-class/ShoutInputPane.md) | Sanitizes shout text before opcode `0x0e`, subtype `1`. |

These call sites prove live shared use, not caller-feature ownership. The helper remains part of the `TextFilter` source family.

## Signature Decision

Accepted source-facing signature:

```cpp
void __stdcall SanitizeWideTextForChat(wchar_t *text, unsigned int textLength);
```

Rationale:

- Windows/NexusTK callers pass wide-character buffers, so `wchar_t *` is the best source-facing type. Older `unsigned short *` wording is behaviorally equivalent for UTF-16 but less source-like.
- `unsigned int` matches the 32-bit loop bound and stack argument.
- `retn 8` proves exactly two stack arguments.
- The callee does not read `ecx`, rejecting `TextFilter::` member and virtual interpretations.
- No vtable slot points to the helper.

Rejected signatures/names:

| Candidate | Decision | Reason |
| --- | --- | --- |
| `TextFilter::SanitizeWideTextForChat(...)` | Rejected | No `ecx` use and no vtable slot. |
| `void SanitizeWideTextForChat(TextFilter *, wchar_t *, unsigned int)` | Rejected | `retn 8` proves only two stack arguments. |
| `g_pTextFilter->SanitizeWideTextForChat(...)` | Rejected | Caller reads of `g_pTextFilter` are context/use evidence, not callee ABI evidence. |
| `NormalizeChatText`, `ApplyOutboundChatFilter`, `g_chatTextFilter` | Historical/search aliases only | Superseded by current helper/global naming. |
| Packet/socket helper | Rejected | The helper edits text before packet serialization and does not own packet/socket state. |

## First-Draft C++ Routing

The exact child [UID:00050D][0x005957c0-0x005958ca.SanitizeWideTextForChat](by-memory/0x005957c0-0x005958ca.SanitizeWideTextForChat.md) emits this accepted first-draft body:

```cpp
void __stdcall SanitizeWideTextForChat(wchar_t *text, unsigned int textLength)
{
    for (unsigned int i = 0; i < textLength; ++i) {
        wchar_t ch = text[i];
        if (ch == 0)
            break;

        if (ch == L'\n' || ch == L'\r' || (ch >= L' ' && ch <= 0x7f))
            continue;

        switch (ch) {
        case 0x00e9:
        case 0x00e8:
        case 0x00e0:
        case 0x00f9:
        case 0x00f4:
        case 0x00ee:
        case 0x00eb:
        case 0x00ef:
        case 0x00fb:
        case 0x00fa:
        case 0x00e2:
        case 0x00e7:
            continue;
        default:
            text[i] = L'?';
            break;
        }
    }
}
```

This by-global page remains the helper owner/index. Its formal `[[CHILDREN]]` marker routes the one exact body without duplicating it, while the class H channel owns the declaration.

## Ownership And Source Placement

Keep [UID:0000OO][TextFilter](by-file/TextFilter.md) as owner/emitter route:

- The helper is adjacent to the `TextFilter` singleton lifecycle and participates in the same user-text filtering source cluster.
- The caller fanout proves shared UI/user-text submit behavior, not ownership by any one caller feature.
- A forced `util` move remains a residual caveat only; no recovered source path, symbol, or non-UI utility consumer proves that route.

## Cross-References

- [UID:0000OO][TextFilter](by-file/TextFilter.md)
- [UID:0000EQ][TextFilter](by-class/TextFilter.md)
- [UID:00050D][0x005957c0-0x005958ca.SanitizeWideTextForChat](by-memory/0x005957c0-0x005958ca.SanitizeWideTextForChat.md)
- [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md)
- [UID:0001JU][0x00595760-0x005958fe.TextFilterAndSanitizer](by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md)
- [UID:0001JT][0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter](by-memory/0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md)
- [UID:0001QH][client_network](by-meta/client_network.md)

## Changes

- 2026-08-03 B001 UID0002OZ callback:
  - Raised `91/90 -> 93/94`, restored the proven `__stdcall` ABI, assigned source position `8`, and routed the exact fresh child through formal `[[CHILDREN]]` without duplicating the body or declaration.
  - Replaced the copied MIDI child identity with fresh TextFilter child [UID:00050D][0x005957c0-0x005958ca.SanitizeWideTextForChat](by-memory/0x005957c0-0x005958ca.SanitizeWideTextForChat.md).

- 2026-06-23 B003 accepted split implementation:
  - Raised `90/86 -> 91/90`.
  - Linked the then-current child path, changed source-facing signature to `wchar_t *`, recorded two-stack-argument `retn 8` and no-`ecx` evidence, preserved the 14 call sites and allowlist, rejected member/virtual/`TextFilter *` signatures, and kept the helper body on the exact child only. Its copied UID was corrected to `00050D` in the 2026-08-03 callback.
- 2026-06-04 historical state:
  - Corrected endpoint to `0x005957c0-0x005958ca` and attached helper to [UID:0000OO][TextFilter](by-file/TextFilter.md). That evidence remains valid and is refined by the accepted child split.

## Current Helper Evidence And Source Route - 2026-08-03

- The modeled function occupies exactly `[0x005957c0,0x005958ca)`, has no callees, consumes two four-byte stack arguments, does not use `ecx`, and returns with `retn 8`. Those facts require a free `__stdcall` helper rather than a member, virtual method, or hidden-`TextFilter *` parameter.
- All fourteen exact call sites remain live: `0x0047762b`, `0x00477641`, `0x0047de2c`, `0x0047de3f`, `0x0053fe34`, `0x0059e4ae`, `0x005ae0cf`, `0x005b16af`, `0x005b1acf`, `0x005b1fef`, `0x005b23ff`, `0x005b3700`, `0x005b3ad0`, and `0x005b42e1`. Their article, mail, profile, party-search, spell, say/chat, and shout fanout proves shared text-filter use rather than ownership by one caller feature.
- The exact behavior is bounded in-place UTF-16 scanning with early NUL termination. CR, LF, printable ASCII through `0x7f`, and the twelve lowercase Latin-1 code units `00e9`, `00e8`, `00e0`, `00f9`, `00f4`, `00ee`, `00eb`, `00ef`, `00fb`, `00fa`, `00e2`, and `00e7` are preserved; every other nonzero code unit becomes `L'?'`.
- [UID:0000TK] emits only `[[CHILDREN]]`; fresh child [UID:00050D][0x005957c0-0x005958ca.SanitizeWideTextForChat](by-memory/0x005957c0-0x005958ca.SanitizeWideTextForChat.md) owns the exact CPP body, [UID:0000EQ][TextFilter](by-class/TextFilter.md) owns the H declaration, and [UID:0000OO][TextFilter](by-file/TextFilter.md) owns the source root. This avoids duplicate bodies and duplicate declarations.
- Historical correction: UID `00041J` and the `MidiPlayerLifecycleMethods` path belong to genuine MIDI lifecycle code at `0x00525dc0`; they are not the TextFilter sanitizer. The TextFilter sanitizer path now has fresh UID `00050D`.
