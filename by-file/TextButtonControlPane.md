*** UID:0000OK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# TextButtonControlPane

## Status

- Confidence: strong for text-button class role, medium for shared text-render helper ownership.
- Proposed module: `ui/controls/TextButtonControlPane.cpp`
- Current recovered source: `source-3/simroot_v2/class_TextButtonControlPane.cpp`
- Main address ranges: [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md), [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md), and [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md)

## File Role

`TextButtonControlPane` is a text-labeled button control derived from the control pane family. It constructs a text buffer, paints 3D button borders and centered text, exposes text retrieval/set-resource behavior, and owns the broad `DrawTextInRect` helper currently used by many text-rendering call sites.

`DrawTextInRect` may eventually move to a more generic text/render helper file if further evidence shows it is not text-button-specific. For now, Wave3 owns it here and IDA MCP reports 130 direct callers, so document it explicitly. Its callees and neighboring helpers now point toward [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md) as the likely shared owner family.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `TextButtonControlPane` | [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md), destructor at [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md) | Text button construction, text buffer ownership, paint, and teardown. |
| `DrawTextInRect` | `0x004bad70-0x004baf92` | Shared multi-line wrapped text drawing helper with alignment support. |

## Evidence Notes

- Wave3 metadata says `TextButtonControlPane` has a `ButtonControlPane` base and a text pointer at offset `0x10c`.
- 2026-05-25 IDA MCP confirms function starts at `0x00495040`, `0x00495130`, `0x004951b0`, `0x00495220`, and scalar deleting destructor `0x0049b7a0`.
- Current `simroot_v2` emits `SetTextResource` at `0x004964e0`, but current IDA MCP reports `0x004964e0` is not a promoted function and raw disassembly maps the full `0x004964e0-0x0049662f` structure to [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md). Treat that row as stale/misowned, not as a confirmed text-button setter.
- 2026-05-25 current-state recheck: `class_TextButtonControlPane.cpp` still emits the stale `SetTextResource` row. `class_RadioGroupControlPane.cpp` now emits the promoted `RadioGroupControlPane::OnPaint` at `0x00496300`, and IDA still leaves the later `0x004964e0` helper/table island unpromoted with no inbound xrefs to its helper starts.
- IDA MCP reports `DrawTextInRect` has 130 direct callers across UI and message rendering code.
- `DrawTextInRect` currently calls `GetFontLineAdvance(...g_pDirectX...)`, but IDA evidence from the DirectX batch indicates this is likely the same `g_pFontImageLib` global-alias issue tracked in [Wave3 noticed problems](../wave3_noticed_problems.md).

## Cross-References

- [UID:0000EJ][TextButtonControlPane](by-class/TextButtonControlPane.md)
- [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md)
- [UID:0000UJ][DrawTextInRect_004BAD70](by-item/DrawTextInRect_004BAD70.md)
- [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md)
- [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)
- [UID:0000JH][FontImageLib](by-file/FontImageLib.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `78`.
  - Evidence: document captures text-button role, proposed contents, Wave3/IDA evidence, stale `SetTextResource` ownership caveat, shared `DrawTextInRect` helper issue, font/global alias caveat, and cross-references; confidence is capped by shared text-render helper ownership.
