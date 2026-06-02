*** UID:0000OQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# TextPad

## Status

- Confidence: strong for class behavior and main ranges; medium-strong for original source placement.
- Proposed module: `ui/dialogs/TextPad.cpp`
- Proposed header: `ui/dialogs/TextPad.h`
- Current recovered source: `source-3/simroot_v2/class_TextPad.cpp`
- Main memory range: [UID:0001JV][0x00595900-0x00596242.TextPad](by-memory/0x00595900-0x00596242.TextPad.md)
- Private helper doc: [UID:0001JW][0x00595be0-0x00595f26.TextPadCommandHelper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md)
- Standalone helper island: [UID:000248][0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers](by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md)

## File Role

`TextPad` is a full-screen `DialogPane`-derived text pad with two [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md) children: a large read-only display/editor surface and a bottom input command bar. Pressing Enter in the input bar dispatches command text through a private helper at `0x00595be0`.

The command helper supports local file and formatting commands. IDA disassembly shows prefix checks for `Open `, `Save `, `SetFont `, and `SetColor `, then performs file I/O or applies formatting to the main `TextEditPane`.

The later `0x00595f30-0x00596242` island duplicates TextPad file-open, file-save, and text-insert behavior as standalone helper-shaped routines. Current IDA reports no inbound xrefs to those starts, so keep them under TextPad with medium reachability confidence.

Keep this separate from [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md). `EditablePaperPane` is packet-opened item paper UI; `TextPad` is a local full-screen text pad/editor and currently has no confirmed constructor caller.

Keep this separate from [UID:0000OL][TextDialog](by-file/TextDialog.md). `TextDialog` belongs to server-driven NPC/message input flows, while `TextPad` has file command behavior and no dialog packet serialization.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `TextPad` | `0x00595900-0x00595bcf` | Full-screen dialog construction, Enter-key command dispatch, close/hide behavior. |
| null virtual | `0x00595bd0-0x00595bd1` | Vtable nullsub/empty virtual. |
| `TextPad_SendText` | [UID:0001JW][0x00595be0-0x00595f26.TextPadCommandHelper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md) | Private command helper for `Open`, `Save`, `SetFont`, and `SetColor`. |
| standalone TextPad helpers | [UID:000248][0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers](by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md) | Retained or callback-target helper island for file open/save and direct text insertion. |

## Function Map

| Range | Function | Notes |
| --- | --- | --- |
| `0x00595900-0x00595ae2` | `TextPad::TextPad` | Builds the full-screen dialog, read-only main editor, bottom input editor, root layout, and cursor manager link. |
| `0x00595af0-0x00595ba9` | `OnKeyInput` | Handles Enter in input mode `1`; reads input control `1`, calls `0x00595be0`, and selects all input text. |
| `0x00595bb0-0x00595bcf` | `OnClose` | Hides the pane and invalidates its client rect. |
| `0x00595bd0-0x00595bd1` | null virtual | Empty vtable target currently in disabled generated output. |
| [UID:0001JW][0x00595be0-0x00595f26.TextPadCommandHelper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md) | `TextPad_SendText` | Parses text commands and reads/writes formatted text content. |
| [UID:000248][0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers](by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md) | standalone helper island | File-open, file-save, and direct insert helpers with no known inbound xrefs. |

## Ownership Notes

- Active `class_TextPad.cpp` calls `TextPad_SendText(this, textBuffer)` but does not emit the helper body. IDA confirms [UID:0001JW][0x00595be0-0x00595f26.TextPadCommandHelper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md) is a real function and the only direct code caller is `TextPad::OnKeyInput`.
- 2026-05-26 IDA MCP recheck confirms `xrefs_to` and `callers` both report the single direct code caller at `0x00595b64` inside `TextPad::OnKeyInput`; keep this helper reconstructable as private `TextPad` code.
- 2026-05-28 IDA MCP recheck splits the former UNKNOWN range after `TextPad_SendText` into padding plus [UID:000248][0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers](by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md). No inbound xrefs were found for the later helper starts.
- The constructor currently has no direct IDA callers. The class may be hidden, development-only, or created through a path that current function/xref recovery does not expose.
- The generated class notes describe this as terminal/chat functionality, but the `Open`/`Save`/formatting command helper makes `TextPad.cpp` a safer source name than placing it under [UID:0000OI][TerminalPane](by-file/TerminalPane.md) or chat modules.

## Cross-References

- [UID:0000EU][TextPad](by-class/TextPad.md)
- [UID:0001JV][0x00595900-0x00596242.TextPad](by-memory/0x00595900-0x00596242.TextPad.md)
- [UID:0001JW][0x00595be0-0x00595f26.TextPadCommandHelper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md)
- [UID:000248][0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers](by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md)
- [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:0000OL][TextDialog](by-file/TextDialog.md)
- [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `76`.
  - Evidence: document captures full-screen text pad role, command helper behavior, standalone helper island, function map, ownership boundaries, IDA xref/reachability caveats, and cross-references; confidence is capped by no known constructor caller and medium original source placement.
- 2026-06-02: assigned reconstruction path and raised confidence for parent attachment.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank and confidence was capped at `76`.
  - After: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` and `CONFIDENCE:80`.
  - Evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `TextPad.cpp` under `ui/dialogs`; existing IDA-backed docs keep `TextPad` separate from `TextDialog`, `EditablePaperPane`, terminal, and chat modules. Confidence remains capped at `80` because no constructor caller is known.
