*** UID:0000EQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TextFilter

## Status

- Confidence: strong for class behavior; medium for source-file placement.
- Likely source file: [UID:0000OO][TextFilter](by-file/TextFilter.md)
- Main address ranges: `0x00595760-0x00595794` and `0x005958d0-0x005958fd`
- Vtable/layout anchor: [UID:0001YY][TextFilterVtable](by-type/by-vtable/TextFilterVtable.md)
- Current recovered file: `source-3/simroot_v2/class_TextFilter.cpp`

## Class Purpose

`TextFilter` is a tiny singleton class used by client text filtering. It stores itself in `g_pTextFilter` during startup and clears the singleton pointer during destruction.

The more behavior-rich text sanitization lives in the neighboring free helper `SanitizeWideTextForChat`, not in a recovered virtual method on this class.

## Method Families

| Address | Function | Role |
| --- | --- | --- |
| `0x00595760-0x00595794` | `TextFilter::TextFilter` | Store `g_pTextFilter` and install the vtable. |
| `0x005957a0-0x005957b0` | non-deleting destructor-like body | Restore `TextFilter` vtable and clear `g_pTextFilter`; IDA models this start but current active source omits it. |
| `0x005958d0-0x005958fd` | scalar deleting destructor | Clear `g_pTextFilter` and optionally delete the object. |

## Evidence Notes

- IDA MCP reports one direct constructor caller at `0x004f615f` inside `Application::Startup`.
- IDA MCP confirms one vtable slot at `0x0062e188`, pointing to the scalar deleting destructor `0x005958d0`. Adjacent `0x0062e18c+` data belongs to `TextPad`, not `TextFilter`.
- `class_TextFilter.cpp` declares `TextFilter_vtable` and `TextFilter* g_pTextFilter`; IDA ties `g_pTextFilter` to `0x0067adc8`.
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
