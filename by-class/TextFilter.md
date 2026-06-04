*** UID:0000EQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TextFilter

## Status

- Confidence: strong for singleton lifecycle, live function boundaries, vtable/global anchors, startup construction, and sanitizer separation; medium for final public names.
- Likely source file: [UID:0000OO][TextFilter](by-file/TextFilter.md)
- Main address ranges: `0x00595760-0x005958fe`
- Vtable/layout anchor: [UID:0001YY][TextFilterVtable](by-type/by-vtable/TextFilterVtable.md)
- Parent attachment: [UID:0000OO][TextFilter](by-file/TextFilter.md) has a documented `NexusTK/ui/controls/` reconstruction path and covers the singleton/sanitizer cluster.

## Class Purpose

`TextFilter` is a tiny singleton class used by client text filtering. It stores itself in `g_pTextFilter` during startup and clears the singleton pointer during destruction.

The more behavior-rich text sanitization lives in the neighboring free helper `SanitizeWideTextForChat`, not in a recovered virtual method on this class.

## Method Families

| Address | Function | Role |
| --- | --- | --- |
| `0x00595760-0x00595795` | `TextFilter::TextFilter` | Store `g_pTextFilter` and install the one-slot `TextFilter` vtable. |
| `0x005957a0-0x005957b1` | non-deleting destructor-like body | Restore the `TextFilter` vtable and clear `g_pTextFilter`; live IDA reports no direct callers/xrefs. |
| `0x005958d0-0x005958fe` | scalar deleting destructor | Restore the `TextFilter` vtable, clear `g_pTextFilter`, and optionally delete the object. |
| `0x005957c0-0x005958ca` | [UID:0000TK][SanitizeWideTextForChat](by-global/SanitizeWideTextForChat.md) | Neighboring free helper that sanitizes UTF-16 user text; not a `TextFilter` virtual method. |

## Evidence Notes

- 2026-06-04 live IDA MCP reports exact function extents: constructor `0x00595760-0x00595795`, non-deleting body `0x005957a0-0x005957b1`, sanitizer `0x005957c0-0x005958ca`, and scalar deleting destructor `0x005958d0-0x005958fe`.
- IDA MCP reports one direct constructor caller at `0x004f615f` inside `sub_4F5FB0` / startup.
- IDA MCP confirms one vtable slot at `0x0062e188`, pointing to the scalar deleting destructor `0x005958d0`; vtable stores/xrefs occur at `0x00595778`, `0x0059578b`, `0x005957a0`, and `0x005958da`. Adjacent `0x0062e18c+` data belongs to `TextPad`, not `TextFilter`.
- IDA ties `g_pTextFilter` to `0x0067adc8`, with constructor writes at `0x00595771` and `0x00595784`, destructor clears at `0x005957a6` and `0x005958e0`, and 19 total data xrefs.
- Live sanitizer evidence shows 14 direct call sites across 12 caller functions, including article/mail/profile/party-search/spell/say/shout submit paths.
- The adjacent [UID:0000TK][SanitizeWideTextForChat](by-global/SanitizeWideTextForChat.md) global is used by many user-text submission paths and should not be modeled as a `TextFilter` virtual method.

## Cross-References

- [UID:0000OO][TextFilter](by-file/TextFilter.md)
- [UID:0001JU][0x00595760-0x005958fe.TextFilterAndSanitizer](by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md)
- [UID:0001YY][TextFilterVtable](by-type/by-vtable/TextFilterVtable.md)
- [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md)
- [UID:0000TK][SanitizeWideTextForChat](by-global/SanitizeWideTextForChat.md)
- [UID:0001JT][0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter](by-memory/0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `78`, confidence `76`.
- Evidence: the page documents singleton behavior, constructor/destructor/scalar-destructor ranges, vtable/global anchors, startup caller, and separation from the richer sanitizer helper; confidence remains capped by source-file placement.
- 2026-06-04: Raised completion/confidence from `78/76` to `84/86`, set `RECONSTRUCTABLE:TRUE`, and attached the class to [UID:0000OO][TextFilter](by-file/TextFilter.md).
  - Evidence: live IDA MCP corrected and confirmed constructor/destructor/sanitizer extents, the sole startup constructor call site, the one-slot vtable at `0x0062e188`, vtable writes in constructor/destructor paths, singleton pointer lifecycle at `0x0067adc8`, 19 singleton data xrefs, and 14 sanitizer call sites across 12 submit-path functions.
  - Remaining limits: scores stay below final-source level because exact public class declarations, final folder choice, and final sanitizer helper signature spelling remain open.
