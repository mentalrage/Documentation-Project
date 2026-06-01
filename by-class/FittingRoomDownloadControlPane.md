*** UID:000052 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:62 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FittingRoomDownloadControlPane

## Status

- Confidence: medium for the download-progress pane, low for several currently attached helpers.
- Current Wave3 file: `class_FittingRoomDownloadControlPane.cpp`
- Proposed source module: [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- Evidence basis: Wave3 inspection, generated source, and IDA MCP checks on 2026-05-23 with a boundary recheck on 2026-05-25.

## Role

Download progress control used by the fitting-room asset/catalog loading flow. The strongest local method is the progress-pane paint routine at `0x0041ba40`, which draws progress text/bar style state.

The small [UID:0001UI][FittingRoomDownloadProgressState](by-type/by-struct/FittingRoomDownloadProgressState.md) helper island at [UID:0000WG][0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers](by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md) feeds progress percentages into the fitting-room action path before this pane is refreshed. Current generated `class_Region.cpp` ownership for that helper is caller/name pollution.

## Strong Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x0041b9e0-0x0041ba20` | raw constructor-shaped body | Installs fitting-room download vtables and clears progress word; IDA has no function object/xrefs at the start. |
| `0x0041ba20-0x0041ba3f` | raw non-deleting destructor/body helper | Restores fitting-room download vtables and calls shared pane/control teardown; no direct xrefs currently. |
| `0x0041ba40-0x0041bdcd` | `OnPaint` | Strong fitting-room download/progress drawing candidate. |
| [UID:0002EI][0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor](by-memory/0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor.md) | scalar deleting destructor wrapper | Confirmed compiler-generated wrapper that restores vtables, calls shared teardown, and conditionally deletes `this`. |

## Boundary Cautions

- Wave3 lists a constructor at `0x0041b9e0`, but IDA MCP reports `0x0041b9e0` is not a function start and has no direct xrefs. The bytes are now documented as [UID:0000WP][0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor](by-memory/0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor.md): they call `ControlPane` setup with type `8`, install the `FittingRoomDownloadControlPane` vtables at offsets `0x0`, `0xa0`, and `0xa4`, clear the word at `0x108`, and return with `retn 4`.
- The adjacent [UID:0000WQ][0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor](by-memory/0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor.md) body restores the same vtables and calls shared teardown helper `0x00544580`; IDA has a function object for this start but currently no xrefs.
- The confirmed deleting destructor at [UID:0002EI][0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor](by-memory/0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor.md) restores the fitting-room download vtables, calls shared pane/control teardown helper `0x00544580`, and conditionally calls delete helper `0x004f4ac0`.
- Wave3 currently places `FittingRoomDialog::FittingRoomDialog` at `0x0041bdd0` inside this file, which is probably file-group evidence rather than `FittingRoomDownloadControlPane` class ownership.
- Current attached helpers include field-map helpers (`0x004b1130`, `0x004b11a0`), generic draw/text helpers (`0x004b9600`, `0x004b9680`, `0x004ba9a0-0x004bad66`, `0x004bb5e0`, `0x00593b20+`), and IME/text-edit functions (`0x004e7470`, `0x004e7930`). `0x004b11a0` is now documented as a [UID:000151][0x004b11a0-0x004b1241.FieldMapRequestHelper](by-memory/0x004b11a0-0x004b1241.FieldMapRequestHelper.md), `0x004b1130` as a [UID:000150][0x004b1130-0x004b119a.FieldMapRectHelper](by-memory/0x004b1130-0x004b119a.FieldMapRectHelper.md), `0x004b9600` / `0x004b9680` as [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md), `0x004ba9a0-0x004bad66` / `0x004bb5e0` as [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md) and [UID:00016I][0x004bb5e0-0x004bb7df.GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7df.GrafPortDrawGlyph.md), `0x00593c20` / `0x00593db0` under [UID:0000ON][TextEditPane](by-file/TextEditPane.md), and the IME helpers under [UID:0000K5][IMEPanes](by-file/IMEPanes.md); treat these as owner-pollution candidates here.
- Current attached helpers also include `0x00541660` and `0x005416d0`. IDA MCP rechecked them on 2026-05-25 and found every direct caller inside `NewOptionPane::OnPaint`, not fitting-room code. Treat [UID:0001DZ][0x00541660-0x005416d0.NewOptionPaneDrawBoldText](by-memory/0x00541660-0x005416d0.NewOptionPaneDrawBoldText.md) and [UID:0001E0][0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem](by-memory/0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem.md) as option-pane owner-pollution candidates.

## Cross-References

- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0001UI][FittingRoomDownloadProgressState](by-type/by-struct/FittingRoomDownloadProgressState.md)
- [UID:0000WG][0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers](by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md)
- [UID:0000WP][0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor](by-memory/0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor.md)
- [UID:0000WQ][0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor](by-memory/0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor.md)
- [UID:0002EI][0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor](by-memory/0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor.md)
- [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- [UID:0000M7][OptionPane](by-file/OptionPane.md)
- [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md)
- [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md)
- [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md)
- [UID:00016I][0x004bb5e0-0x004bb7df.GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7df.GrafPortDrawGlyph.md)
- [UID:0001DZ][0x00541660-0x005416d0.NewOptionPaneDrawBoldText](by-memory/0x00541660-0x005416d0.NewOptionPaneDrawBoldText.md)
- [UID:0001E0][0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem](by-memory/0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-05-30: Added a direct by-memory reference for the confirmed `0x0041d580-0x0041d5d5` deleting-destructor wrapper and scored the class page from 0/0 to 62/76. Evidence: IDA MCP confirms the wrapper's function size, vtable reference, adjacent adjustor-thunk callers, shared teardown call, and conditional delete-helper call.
- 2026-05-27: Existing boundary note treated `0x0041b9e0` mainly as a projected non-function start. Changed it to document the actual byte-level split: `0x0041b9e0-0x0041ba20` is a raw constructor-shaped body and `0x0041ba20-0x0041ba3f` is a raw destructor/body helper. Evidence: IDA MCP still reports no function/xrefs at `0x0041b9e0`, while manual IDA disassembly shows vtable installation, `this + 0x108` initialization, and adjacent vtable restore plus shared teardown before `OnPaint`.
