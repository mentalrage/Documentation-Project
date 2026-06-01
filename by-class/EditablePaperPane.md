*** UID:000048 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EditablePaperPane

## Status

- Confidence: strong for behavior and core method ownership.
- Likely source: [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md)
- Current recovered source: `source-3/simroot_v2/class_EditablePaperPane.cpp`
- Memory: [UID:0001EE][0x00545170-0x00545e3b.EditablePaperPane](by-memory/0x00545170-0x00545e3b.EditablePaperPane.md)
- Type docs: [UID:0001XF][EditablePaperPaneVtables](by-type/by-vtable/EditablePaperPaneVtables.md)
- Exact vtable data: [UID:0002NC][0x00621afc-0x00621b98.EditablePaperPaneVtableData](by-memory/0x00621afc-0x00621b98.EditablePaperPaneVtableData.md)

## Responsibility

`EditablePaperPane` is a `DialogPane`-derived paper/document UI. It displays server-sent paper content in either editable or read-only mode, renders a tiled paper frame from `LINE001.EPD`, hosts a text edit control, and sends edited paper content back to the server.

## Layout Evidence

Generated metadata and method bodies support a 640-byte class with a `DialogPane` base and paper-specific fields near the end:

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `+0x26c` | `m_paperId` | Parsed from editable packet byte `+1` and written into save packet byte `+1`. |
| `+0x26d` | status/unused byte | Parsed/cleared by both packet parsers; exact semantic remains open. |
| `+0x26e` | `m_widthTiles` | Used to compute `(width + 2) * 16` pixel width. |
| `+0x26f` | `m_heightTiles` | Used to compute `(height + 3) * 16` pixel height. |
| `+0x270` | `m_textLength` | Stores the `MultiByteToWideChar` result length. |
| `+0x278` | `m_paperMode` | Constructor mode; `0` editable, `1` read-only. |
| `+0x27c` | `m_bCentered` | Read-only packet flag that centers single-line text. |

## Method Families

| Range | Method | Summary |
| --- | --- | --- |
| `0x00545170-0x00545217` | constructor | Initializes base dialog and dispatches to the mode-specific parser. |
| `0x00545220-0x0054524b` | `OnDialogAction` | Saves and closes when action `0` fires. |
| `0x00545250-0x0054565b` | `InitializePaperContent` | Builds controls, applies edit/read-only limits, hides editor scrollbars, and opens the pane. |
| `0x00545660-0x00545877` | packet parsing | Reads editable/read-only packet headers, dimensions, centered flag, and text payload. |
| `0x00545880-0x005459a7` | save serialization | Encodes edited text as opcode `0x23`. |
| `0x005459b0-0x00545dc1` | drawing | Draws the `LINE001.EPD` border and background fill. |
| [UID:0001EF][0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks](by-memory/0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md), `0x00545e00-0x00545e3b` | destructor support | Adjustor thunks excluded through [UID:0000VN][-ignored](by-memory/-ignored.md), plus reconstructable scalar deleting destructor. |

## Vtable Evidence

IDA `list_globals` confirms `EditablePaperPane` vtable bases at `0x00621afc`, `0x00621b60`, and `0x00621b90`. The primary table includes paper-specific slots for `OnDialogAction` (`0x00545220`), `DrawBackground` (`0x00545d50`), `DrawBorder` (`0x005459b0`), and `InitializePaperContent` (`0x00545250`).

The tertiary table is short: it owns only the destructor adjustor `0x00545de8` and inherited slot `0x00544e90`. The dword at `0x00621b98` begins adjacent `LINE001.EPD` string/data, which helps explain the stale disabled `0x0045004e` generated row.

## Packet Behavior

- Editable open packets include paper id, status byte, width tiles, height tiles, 16-bit text length, and multibyte text.
- Read-only open packets omit the paper id, include status byte, width tiles, height tiles, centered flag, 16-bit text length, and multibyte text.
- During display setup, tabs are converted to carriage returns for the text editor.
- During save, carriage returns are converted back to tabs, the text is converted to multibyte, and the client sends opcode `0x23` with paper id plus 16-bit text length.

## Unresolved

- The exact meaning of `+0x26d` remains unresolved. Current behavior suggests a status byte or stale parser flag.
- The small wrappers at `0x005128a0` and `0x00512900` allocate and construct paper panes but have no direct IDA callers. Their final owner may be `map/MapPane.cpp` rather than `ui/dialogs/EditablePaperPane.cpp`.
- Generated disabled method `0x0045004e` is owner pollution from [UID:0000XJ][0x00450030-0x0045007b.LodePngLowerBoundHelper](by-memory/0x00450030-0x0045007b.LodePngLowerBoundHelper.md) and should not be migrated with this class.
- 2026-05-26 IDA recheck confirms `0x00545ddd` and `0x00545de8` forward to `0x00545e00` after `this - 0xa0` and `this - 0xa4`; both are tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).

## Cross-References

- [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md)
- [UID:0001EE][0x00545170-0x00545e3b.EditablePaperPane](by-memory/0x00545170-0x00545e3b.EditablePaperPane.md)
- [UID:0002NC][0x00621afc-0x00621b98.EditablePaperPaneVtableData](by-memory/0x00621afc-0x00621b98.EditablePaperPaneVtableData.md)
- [UID:0001XF][EditablePaperPaneVtables](by-type/by-vtable/EditablePaperPaneVtables.md)
- [UID:0001EF][0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks](by-memory/0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md)
- [UID:0000XJ][0x00450030-0x0045007b.LodePngLowerBoundHelper](by-memory/0x00450030-0x0045007b.LodePngLowerBoundHelper.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `84/86`.
  - Summary/evidence: paper-dialog responsibility, detailed tail layout, constructor/action/setup/parse/save/draw/destructor families, vtable evidence, packet behavior, and stale generated method pollution are documented; remaining uncertainty is the exact semantic for byte `+0x26d` and wrapper ownership.
