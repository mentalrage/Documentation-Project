*** UID:00009U | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# OldUserStatusPane

## Status

- Confidence: strong for role, method boundaries, and singleton.
- Likely source file: [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- Main address range: [UID:0001NR][0x005bda40-0x005bfbc1.OldUserStatusPane](by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md)
- Shared destructor/thunk tail: [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)
- Singleton: [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md) at `0x0069b4ec`
- Current recovered source: `source-3/simroot_v2/class_OldUserStatusPane.cpp`

## Class Purpose

`OldUserStatusPane` is the legacy local player status pane used by the older UI layout. It paints the `USERSTAT.EPD` panel, draws nation/totem/class icons and bars, provides legacy hover help zones, and applies the old status-packet payload format.

## Method Map

| Address | Method / family | Role |
| --- | --- | --- |
| `0x005bda40-0x005bdb63` | `OldUserStatusPane::OldUserStatusPane` | Constructs the pane, stores the singleton, installs vtables, loads `9X11FONT.BIN`, and initializes legacy display fields. |
| `0x005bdb70-0x005bdbed` | cleanup body | Frees the glyph table, clears the singleton, and calls pane-base cleanup. |
| `0x005bdc30-0x005bdc88` | accessors and `SetStatusIconId` | Returns nation/status value fields and writes the top-row status icon id at offset `+0x13f`. |
| `0x005bdcb0-0x005bdf3c` | packet/movement router | Reads packet payloads, handles movement/status opcodes, and forwards full status payloads to `0x005bf7c0`. |
| `0x005bdfa0-0x005be51e` | `OnMouseMove` | Handles legacy status hover zones and creates help panes with localized ids. |
| `0x005be520-0x005bf10d` | `OnPaint` | Draws `USERSTAT.EPD`, `NATION.EPD`, `TOTEM.EPD`, `CLASS.EPD`, bars, numbers, and status text. |
| `0x005bf150-0x005bf374` | legacy status-rect lookup helper | Maps legacy field ids to dirty/help rectangles. |
| `0x005bf3b0-0x005bf481` | `DrawNumberGlyphString` | Draws numbers with the loaded 9x11 font table. |
| `0x005bf7c0-0x005bfbc1` | legacy status payload application | Parses bitflagged status payloads, updates legacy fields, invalidates rectangles, and creates/invalidates `TotemFrame` when the spirit/totem value changes. |
| `0x005bfbe0`, `0x005bfc37`, `0x005bfc42`, `0x005bfda0` | shared tail helpers | Singleton clear helper, destructor adjustor thunks, and scalar deleting destructor. |

## Field Evidence

- `0x005bdc30` returns byte offset `+0x13c`, the legacy nation id.
- `0x005bdc60` returns byte offset `+0x13e`, the legacy spirit/totem id. [UID:0000F4][TotemFrame](by-class/TotemFrame.md) calls this getter to select a `TOTFRAME.EPD` frame.
- `0x005bdc70` writes byte offset `+0x13f`, the status icon selector used by the paint path.

## Evidence Notes

- IDA callers show construction from `InitializeMainUiGraph` at `0x004f8951`.
- `TotemFrame::OnPaint` reads [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md) and calls `OldUserStatusPane::GetSpiritId` at `0x005bdc60`.
- `LivingObjectPane::HandleServerEntryPacket` calls `OldUserStatusPane::SetStatusIconId` at `0x005aaed8`.
- Active generated output omits `0x005bdcb0`, `0x005bf150`, `0x005bf7c0`, and the shared tail helpers. Its constructor text also contains literal `` `n`n`` data.

## Cross-References

- [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- [UID:0001NR][0x005bda40-0x005bfbc1.OldUserStatusPane](by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md)
- [UID:0001RS][user-status-resources](by-resource/user-status-resources.md)
- [UID:0000F4][TotemFrame](by-class/TotemFrame.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page already documented purpose, singleton storage, method families, field offsets, resources, callers, and generated-output omissions.
- Changed to: `COMPLETION:82` and `CONFIDENCE:80`.
- Evidence: the page covers constructor/cleanup, packet routing, hover help, painting, status payload application, glyph drawing, field evidence, and cross-class caller relationships; confidence remains medium-high because active generated output omits several IDA-confirmed bodies and contains malformed constructor text.
