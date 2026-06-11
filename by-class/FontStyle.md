*** UID:00005C | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FontStyle

## Status

- Confidence: strong for behavior and layout; medium for final source/header placement.
- Likely source file: [UID:0000JI][FontStyle](by-file/FontStyle.md)
- Exact memory docs: [UID:0000XM][0x004536e0-0x00453732.FontStyleClearRules](by-memory/0x004536e0-0x00453732.FontStyleClearRules.md), [UID:00011T][0x00499f10-0x00499fda.FontStyleCore](by-memory/0x00499f10-0x00499fda.FontStyleCore.md), and [UID:00011W][0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth](by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md)

## Class Purpose

`FontStyle` is a compact text-rendering style descriptor. It stores enabled/opacity/scalar style fields and an optional vector of 16-byte style rules. Static text and help panes use the object to carry foreground/background or mode-style settings from caller code into the text-rendering controls.

## Layout Summary

The recovered object is 0x20 bytes:

- `+0x00`: enabled byte, with padding through `+0x03`.
- `+0x04` and `+0x08`: two float fields defaulted to `0.2f`; `HelpPane` uses them as outer and inner opacity values.
- `+0x0c` and `+0x10`: two scalar style values defaulted to `1` and `0x80`.
- `+0x14`, `+0x18`, `+0x1c`: begin/end/capacity pointers for 16-byte style rule records.

See [UID:0001UN][FontStyleLayout](by-type/by-struct/FontStyleLayout.md) for the field-level caveats.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClearRules` | [UID:0000XM][0x004536e0-0x00453732.FontStyleClearRules](by-memory/0x004536e0-0x00453732.FontStyleClearRules.md) | Frees rule-vector storage through the shared heap free helper and clears the vector triplet. |
| `FontStyle` | `0x00499f10-0x00499f51` | Initializes defaults: enabled, both float fields `0.2f`, scalar values `1` and `0x80`, and empty rule storage. |
| bounded rule lookup | `0x00499f60-0x00499f85` | Copies a selected 16-byte rule record to a caller buffer when the requested index is in range; currently used by the HelpPane text renderer. |
| `Configure` | `0x00499f90-0x00499fda` | Builds and appends a 16-byte rule record; calls the vector growth slow path at `0x0049ac60` when full. |
| vector growth support | `0x0049ac60-0x0049ad74` | One-caller compiler/template-style growth helper for the rule vector; not a source-facing method. |

## Caller Evidence

- [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md) constructs a local `FontStyle`, configures it, and passes it to `StaticTextControlPane2` labels for NPC/Portal and coordinate text.
- [UID:000096][NewMailDialog](by-class/NewMailDialog.md) constructs/configures a local style for the EPF compose dialog's "Keep a copy" label.
- [UID:000063][HelpPane](by-class/HelpPane.md) embeds a compatible style record and copies caller-provided style data into it.
- [UID:000064][HelpPane__SimpleHelpTextPartPane](by-class/HelpPane__SimpleHelpTextPartPane.md) calls the bounded rule lookup at `0x00499f60` from two line-drawing sites.
- Cleanup callers are currently minimap-local/unwind paths. The function itself is generic rule-vector teardown and should stay with `FontStyle`.

## Caveats

- The name `FontStyle` is imported/generated, but the behavior strongly supports a text-style record rather than a full font object.
- Earlier emitted drafts repeat the layout/rule declarations inside every emitted method. Treat that as normalization noise.
- The generated `m_flags`, `m_bold`, `m_italic`, `m_color`, and `m_size` names seen in `MiniMapDialog` are provisional caller-side field labels. Prefer the neutral layout names until the rendering consumers are fully typed.
- The third `Configure` argument is semantically byte-sized in IDA. Do not assume the high bytes of the third rule slot are meaningful until consumers prove it.
- `0x0049ac60` should remain ignored as compiler/vector support; final source should express this as a normal rule append.

## Cross-References

- [UID:0000JI][FontStyle](by-file/FontStyle.md)
- [UID:0001UN][FontStyleLayout](by-type/by-struct/FontStyleLayout.md)
- [UID:00011W][0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth](by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md)
- [UID:0000E4][StaticTextControlPane2](by-class/StaticTextControlPane2.md)
- [UID:000063][HelpPane](by-class/HelpPane.md)
- [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md)
- [UID:000096][NewMailDialog](by-class/NewMailDialog.md)

## Changes

- 2026-06-05: A004 raised the class to `84/88`, attached it to [UID:0000JI][FontStyle](by-file/FontStyle.md), removed stale recovered-file provenance, added the live `0x00499f60` bounded rule lookup, and documented the HelpPane text-renderer callers. Final C++ remains blank because field names and original source placement are still below the final reconstruction gate.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed the class-owned function starts `0x004536e0`, `0x00499f10`, `0x00499f90`, and helper `0x0049ac60`; parent attachment was deferred at that time until this page crossed the completion gate.
- 2026-05-30: Scored the class page from 0/0 to 72/84 and linked the `ClearRules` method row to its detailed by-memory page. Evidence: IDA MCP recheck of `0x004536e0` confirms bounds, caller/callee set, and rule-vector teardown offsets; existing docs already cover constructor/configure/layout/caller fanout.
