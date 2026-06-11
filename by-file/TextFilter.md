*** UID:0000OO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# TextFilter

## Status

- Confidence: strong for the class/helper behavior, live singleton/vtable/global evidence, parent path, and separation from `TextEditPane`; medium for whether the sanitizer was originally placed in a utility-oriented source.
- Proposed module: `ui/controls/TextFilter.cpp`, with possible later utility-folder migration if stronger original-source evidence appears.
- Reviewed source-family inputs: `TextFilter` class page, `g_pTextFilter`, `SanitizeWideTextForChat`, vtable data, and the exact memory aggregate.
- Main address cluster: `0x00595760-0x005958fe`
- Exact memory page: [UID:0001JU][0x00595760-0x005958fe.TextFilterAndSanitizer](by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md)
- Vtable/layout anchor: [UID:0001YY][TextFilterVtable](by-type/by-vtable/TextFilterVtable.md)
- Exact singleton storage: `0x0067adc8` inside the former mixed UI/chat/clan singleton run.

## File Role

`TextFilter` is a tiny startup singleton around client text filtering. The class itself only installs and clears `g_pTextFilter`, but the neighboring global `SanitizeWideTextForChat` at `0x005957c0` is a broader text-sanitization helper used by chat, mail, article, whisper, spell-string, and party-search submission paths.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `TextFilter` | `0x00595760-0x00595795`, `0x005957a0-0x005957b1`, `0x005958d0-0x005958fe` | Singleton object constructed during application startup; stores and clears `g_pTextFilter`. |
| [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md) | `0x0067adc8` | Process-wide text filter singleton pointer. |
| [UID:0000TK][SanitizeWideTextForChat](by-global/SanitizeWideTextForChat.md) | `0x005957c0-0x005958ca` | In-place UTF-16 sanitizer used before sending user-authored text. |

## Ownership Decision

Keep this separate from [UID:0000ON][TextEditPane](by-file/TextEditPane.md) until stronger evidence proves a shared original file. The addresses are adjacent, but `SanitizeWideTextForChat` is used by many submit paths that are not editor rendering or selection code.

The exact final folder is open. `ui/controls/TextFilter.cpp` matches the current text-control neighborhood; `util/TextFilter.cpp` may fit better if later evidence shows this was intended as generic string sanitization.

## Evidence Notes

- 2026-06-04 live IDA MCP confirms exact function extents for the constructor (`0x00595760-0x00595795`), non-deleting body (`0x005957a0-0x005957b1`), sanitizer (`0x005957c0-0x005958ca`), and scalar deleting destructor (`0x005958d0-0x005958fe`).
- IDA MCP confirms the one-slot `TextFilter` vtable at `0x0062e188`; the slot points to `0x005958d0`, and adjacent `0x0062e18c+` data belongs to `TextPad`.
- `TextFilter::TextFilter` writes `g_pTextFilter = this` at `0x0067adc8` and installs the vtable; both destructor paths clear the singleton pointer.
- IDA MCP reports one direct constructor caller at `0x004f615f` inside startup function `sub_4F5FB0`.
- IDA MCP reports 14 direct `SanitizeWideTextForChat` callers across 12 functions in article, mail, profile, spell string, target message, normal say, recipient say, shout, and party-search submit paths.

## Cross-References

- [UID:0000EQ][TextFilter](by-class/TextFilter.md)
- [UID:0001JU][0x00595760-0x005958fe.TextFilterAndSanitizer](by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md)
- [UID:0001YY][TextFilterVtable](by-type/by-vtable/TextFilterVtable.md)
- [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md)
- [UID:0000TK][SanitizeWideTextForChat](by-global/SanitizeWideTextForChat.md)
- [UID:0001JT][0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter](by-memory/0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `82` and confidence to `80`.
  - Evidence: document covers singleton/filter role, sanitizer helper, global/vtable anchors, ownership decision, IDA caller evidence, TextEditPane boundary, and cross-references; confidence remains capped by final `ui/controls` vs `util` placement.
- 2026-05-31: Assigned validator reconstruction path.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - After: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/"`.
  - Evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `TextFilter.cpp` under `ui/controls`; IDA MCP confirms the singleton/filter cluster, while final folder confidence remains capped by the broad sanitizer caller set.
- 2026-06-04: Raised completion/confidence from `82/80` to `84/86`.
  - Evidence: live IDA MCP rechecked constructor/destructor/sanitizer extents, the one startup constructor caller, the one-slot vtable and its constructor/destructor xrefs, the `g_pTextFilter` lifecycle at `0x0067adc8`, 19 singleton data xrefs, 14 sanitizer call sites across 12 submit-path functions, and padding boundaries before `TextPad`.
  - Remaining limits: score stays below final-source level because the final original-source folder and sanitizer helper signature spelling are not fully proven.
- 2026-06-07 A008 Batch 037 parent-gate refresh:
  - Raised `COMPLETION` from `84` to `85`.
  - Evidence: the singleton storage has been split out of [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md) as a direct four-byte TextFilter slot with 19 xrefs, so the file-level parent now clears the stricter `85/85` gate for [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md).
