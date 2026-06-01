*** UID:0000FS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# UserStatusPane

## Status

- Confidence: strong for role, method boundaries, and singleton.
- Likely source file: [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- Main address range: [UID:0001NM][0x005b83b0-0x005baafe.UserStatusPane](by-memory/0x005b83b0-0x005baafe.UserStatusPane.md)
- Shared destructor/thunk tail: [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)
- Singleton: [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) at `0x0069ae0c`
- Current recovered source: `source-3/simroot_v2/class_UserStatusPane.cpp`

## Class Purpose

`UserStatusPane` is the newer local player status summary pane. It displays the character name/title text, nation/totem/class icons, selected status icon, level/stat values, bar values, pair values, and tooltip help zones. It is constructed by `InitializeMainUiGraph` in the newer UI layout.

## Method Map

| Address | Method / family | Role |
| --- | --- | --- |
| `0x005b83b0-0x005b8526` | `UserStatusPane::UserStatusPane` | Constructs the pane, stores the singleton, installs vtables, loads `9X11FONT.BIN`, and initializes display fields. |
| `0x005b8530-0x005b85ad` | cleanup body | Frees the font table, clears the singleton, and calls pane-base cleanup. |
| [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md) | text/status accessors and setters | Copies title/secondary strings, returns status-byte fields, sets text fields, and invalidates. Active output only emits part of this family. |
| [UID:0002LP][0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId](by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md) | `SetStatusIconId` | Writes byte offset `+0x27f` and calls the summary refresh sink at subobject offset `+0x44`. |
| `0x005b8700-0x005b89b1` | packet/movement router | Reads the packet payload pointer from `event+0x0c`, handles opcodes including `0x04`, `0x08`, `0x0b`, and `0x26`, and forwards full status payloads to `0x005ba4a0`. |
| `0x005b8a10-0x005b8c6b` | `HandleMouseStatusHitTest` | Shows localized help for status regions. |
| `0x005b8c70-0x005b9d6a` | `OnPaint` | Draws `USERSTAT.EPF`/`USERSTAT.EPD`, text, nation/totem/class icons, bars, and numeric values. |
| `0x005b9db0-0x005b9fb1` | status-rect lookup helper | Maps field ids to dirty/help rectangles and varies geometry by layout mode. |
| `0x005ba020-0x005ba0f1` | `DrawStatusGlyphText` | Draws 9x11 bitmap-font text. |
| `0x005ba4a0-0x005baafe` | status payload application | Parses bitflagged status payloads, updates fields, invalidates dirty rectangles, and creates/invalidates `TotemFrame` when the spirit/totem value changes. |
| `0x005bfc00`, `0x005bfc63`, `0x005bfc6e`, `0x005bff20` | shared tail helpers | Singleton clear helper, destructor adjustor thunks, and scalar deleting destructor. |

## Field Evidence

- `0x005b8620` returns byte offset `+0x27c`, the newer nation id.
- `0x005b8630` returns byte offset `+0x27e`, the newer spirit/totem id.
- `+0x284` is initialized to `52` in the constructor and is read by inventory/item command panes as the maximum valid item-slot selector for the active local user.
- `0x005b8640`, `0x005b8650`, and `0x005b8660` return 32-bit values at offsets `+0x28c`, `+0x294`, and `+0x298`.
- `0x005ba4a0` uses bit flags in the status packet to decide which fields are present and which rectangles to invalidate.
- See [UID:0001WF][UserStatusPaneSummaryFields](by-type/by-struct/UserStatusPaneSummaryFields.md) for the full field slice currently emitted as generated [UID:00001N][CharacterSummaryRecord](by-class/CharacterSummaryRecord.md).

## Evidence Notes

- IDA callers show construction from `InitializeMainUiGraph` at `0x004f837a`.
- IDA xrefs show constructor writes and cleanup/scalar destructor clears [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md).
- The update handler at `0x005ba4a0` references [UID:0000SK][g_pTotemFrame](by-global/g_pTotemFrame.md): it invalidates an existing frame or constructs [UID:0000F4][TotemFrame](by-class/TotemFrame.md).
- Active generated output omits `0x005b8700`, `0x005b9db0`, `0x005ba4a0`, and the shared tail helpers.
- Active generated output also splits `0x005b85b0-0x005b86ca` into `class_CharacterSummaryRecord.cpp`; this is a generated pseudo-class over the `UserStatusPane` object tail.
- 2026-05-31 IDA MCP recheck of the constructor, summary accessor island, status-icon setter, status-payload updater, and final boundary before `UserStatusPane2` supports treating the class as NexusTK-owned reconstructable source. Parent attachment and C++ emission remain intentionally blank until the class and all children are near-final.

## Cross-References

- [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- [UID:0001NM][0x005b83b0-0x005baafe.UserStatusPane](by-memory/0x005b83b0-0x005baafe.UserStatusPane.md)
- [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md)
- [UID:0002LP][0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId](by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md)
- [UID:0001WF][UserStatusPaneSummaryFields](by-type/by-struct/UserStatusPaneSummaryFields.md)
- [UID:0001RS][user-status-resources](by-resource/user-status-resources.md)
- [UID:0000F4][TotemFrame](by-class/TotemFrame.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:88`.
  - Summary/evidence: scored from the constructor/cleanup/accessor/router/paint/rect/glyph/status-payload method map, singleton/global evidence, field offsets, resource links, TotemFrame interaction, and generated-output caveats.
- 2026-05-31 reconstructable flag:
  - What existed before: blank `RECONSTRUCTABLE`.
  - Changed to: `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP confirms the class constructor, methods, singleton storage, field accessors, payload updater, and neighboring `UserStatusPane2` boundary as source-owned NexusTK UI code.
