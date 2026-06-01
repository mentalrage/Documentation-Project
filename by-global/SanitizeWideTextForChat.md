*** UID:0000TK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SanitizeWideTextForChat

## Status

- Symbol kind: recovered free helper.
- Address range: `0x005957c0-0x005958c9`.
- Proposed signature: `void SanitizeWideTextForChat(unsigned short* text, unsigned int textLength)`.
- Likely owner: [UID:0000OO][TextFilter](by-file/TextFilter.md), or a broader text utility source if final foldering moves sanitizer code out of `ui/controls`.
- Current recovered source: `source-3/simroot_v2/recovered/SanitizeWideTextForChat_005957C0.cpp`.
- Confidence: strong for behavior, callers, and address range.

## Purpose

`SanitizeWideTextForChat` edits a UTF-16 buffer in place before user-authored text is serialized into packets. It scans up to `textLength` code units, stops early at NUL, preserves printable ASCII, CR/LF, and a fixed Latin-1 lowercase-accent allowlist, and replaces every other nonzero code unit with `?`.

The allowed accented code units are:

```text
0x00e9, 0x00e8, 0x00e0, 0x00f9, 0x00f4, 0x00ee,
0x00eb, 0x00ef, 0x00fb, 0x00fa, 0x00e2, 0x00e7
```

## Evidence

- IDA MCP `lookup_funcs` on 2026-05-26 confirms `0x005957c0` as a real function with size `0x10a`, ending at `0x005958ca`.
- IDA decompilation on 2026-05-26 matches the active recovered source in `simroot_v2/recovered/SanitizeWideTextForChat_005957C0.cpp`.
- IDA callers on 2026-05-26 show 14 direct call sites spanning article, mail, profile, party search, spell-string input, target-message input, normal say, recipient say, and shout flows.
- The helper is adjacent to [UID:0000EQ][TextFilter](by-class/TextFilter.md) and reads are paired with [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md) in several callers, but the body is a free helper rather than a `TextFilter` virtual method.

## Caller Families

| Caller range | Current owner | Use |
| --- | --- | --- |
| `0x00477590-0x00477790` | [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md) | Sanitizes article subject/body before posting. |
| `0x0047dcb0-0x0047e033` | [UID:000096][NewMailDialog](by-class/NewMailDialog.md) | Sanitizes mail subject/body before sending. |
| `0x0053fdc0-0x0053fe86` | [UID:0000AU][ProfileDialog](by-class/ProfileDialog.md) | Sanitizes profile text before copying/saving. |
| `0x0059e3d0-0x0059e707` | [UID:0000A7][PartySearchEditPane](by-class/PartySearchEditPane.md) | Sanitizes party-search text before opcode `0x84`. |
| `0x005ae060-0x005ae1a4` | [UID:0000DU][SpellStringInputPane](by-class/SpellStringInputPane.md) | Sanitizes spell string argument before opcode `0x0f`. |
| `0x005b1640-0x005b2562` | [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) | Sanitizes private/group/plan target-message payloads. |
| `0x005b3670-0x005b37ea` | [UID:0000C3][SayInputPane](by-class/SayInputPane.md) | Sanitizes normal say text before opcode `0x0e`, subtype `0`. |
| `0x005b4260-0x005b43bc` | [UID:0000D5][ShoutInputPane](by-class/ShoutInputPane.md) | Sanitizes shout text before opcode `0x0e`, subtype `1`. |

## Cross-References

- [UID:0000OO][TextFilter](by-file/TextFilter.md)
- [UID:0000EQ][TextFilter](by-class/TextFilter.md)
- [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md)
- [UID:0001JU][0x00595760-0x005958fe.TextFilterAndSanitizer](by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md)
- [UID:0001JT][0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter](by-memory/0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md)
- [UID:0001QH][client_network](by-meta/client_network.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `90/86`. Summary/evidence: the page documents the exact function range, proposed signature, sanitizer behavior, allowlist, IDA decompilation/caller evidence, caller families, and likely owner, with only final source placement open.
