*** UID:0000OO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# TextFilter

## Status

- Confidence: strong for the class/helper behavior and for keeping it separate from `TextEditPane`; medium for final `ui/controls` vs `util` folder placement.
- Proposed module: `ui/controls/TextFilter.cpp` or `util/TextFilter.cpp`
- Current recovered source: `source-3/simroot_v2/class_TextFilter.cpp`
- Main address cluster: `0x00595760-0x005958fe`
- Exact memory page: [UID:0001JU][0x00595760-0x005958fe.TextFilterAndSanitizer](by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md)
- Vtable/layout anchor: [UID:0001YY][TextFilterVtable](by-type/by-vtable/TextFilterVtable.md)

## File Role

`TextFilter` is a tiny startup singleton around client text filtering. The class itself only installs and clears `g_pTextFilter`, but the neighboring global `SanitizeWideTextForChat` at `0x005957c0` is a broader text-sanitization helper used by chat, mail, article, whisper, spell-string, and party-search submission paths.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `TextFilter` | `0x00595760-0x00595794`, `0x005957a0-0x005957b0`, `0x005958d0-0x005958fe` | Singleton object constructed during application startup; stores and clears `g_pTextFilter`. |
| [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md) | `0x0067adc8` | Process-wide text filter singleton pointer. |
| [UID:0000TK][SanitizeWideTextForChat](by-global/SanitizeWideTextForChat.md) | `0x005957c0-0x005958c9` | In-place UTF-16 sanitizer used before sending user-authored text. |

## Ownership Decision

Keep this separate from [UID:0000ON][TextEditPane](by-file/TextEditPane.md) until stronger evidence proves a shared original file. The addresses are adjacent, but `SanitizeWideTextForChat` is used by many submit paths that are not editor rendering or selection code.

The exact final folder is open. `ui/controls/TextFilter.cpp` matches the current text-control neighborhood; `util/TextFilter.cpp` may fit better if later evidence shows this was intended as generic string sanitization.

## Evidence Notes

- IDA MCP confirms the one-slot `TextFilter` vtable at `0x0062e188`; current `class_TextFilter.meta_wave3` still reports `vtable_count: 0`.
- `TextFilter::TextFilter` writes `g_pTextFilter = this` at `0x0067adc8` and installs `TextFilter_vtable`.
- IDA MCP confirms a non-deleting destructor-like body at `0x005957a0-0x005957b0`; current active `class_TextFilter.cpp` does not emit it.
- The scalar deleting destructor clears `g_pTextFilter`.
- IDA MCP reports one direct constructor caller at `0x004f615f` inside `Application::Startup`.
- IDA MCP reports 14 direct `SanitizeWideTextForChat` callers in article, mail, profile, spell string, target message, normal say, shout, and party-search submit paths.

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
