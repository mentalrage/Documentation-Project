*** UID:000052 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FittingRoomDownloadControlPane

## Status

- Confidence: strong for the local download-progress pane identity, medium for final field names and raw constructor/destructor reachability.
- Proposed source module: [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- Autogen status: reconstructable class under the fitting-room source module; C++ is intentionally blank until the pane field names, `OnPaint` child split, and helper ownership exclusions are final-source quality.
- Evidence basis: live IDA MCP function lookup, xrefs, callees, decompilation, and raw-range disassembly checks on 2026-06-03.

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

## Local Core Evidence

| Evidence | Meaning | Confidence impact |
| --- | --- | --- |
| Raw constructor body writes `FittingRoomDownloadControlPane` vtables at offsets `0x0`, `0xa0`, and `0xa4` | Confirms this is a distinct pane/control subclass, not just a file-level helper cluster. | Raises class identity confidence. |
| Raw constructor clears word `this + 0x108` | Identifies a local state field used by the download/progress pane. | Supports reconstruction, but field name remains unresolved. |
| `0x0041ba40-0x0041bdcd` draw routine follows the raw constructor/destructor island | Places the strongest behavior immediately after the pane lifecycle bodies. | Supports source-module ownership. |
| Deleting destructor `0x0041d580-0x0041d5d5` restores the same vtables and conditionally deletes `this` | Confirms compiler-generated lifecycle wrapper for the same class. | Raises confidence enough to attach to `FittingRoom`. |
| Progress state helper [UID:0000WG][0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers](by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md) feeds fitting-room action flow before pane refresh | Links the visible progress control to the fitting-room asset/catalog loading path. | Supports role description. |

## IDA Evidence Snapshot

Live IDA MCP checks on 2026-06-03 confirm the local class core:

| Address | IDA result | Evidence |
| --- | --- | --- |
| `0x0041b9e0` | no IDA function record | Raw disassembly is a constructor-shaped body: pushes constructor argument and type/id `8`, calls `sub_4949E0`, writes the three `FittingRoomDownloadControlPane` vtables, clears `word ptr [this + 0x108]`, and returns with `retn 4`. `xrefs_to` has no direct references. |
| `0x0041ba20` | `sub_41BA20`, size `0x1f` | Non-deleting destructor-shaped body; decompilation writes the same three vtables and tail-jumps/calls shared teardown `sub_544580`. `xrefs_to` has no direct references. |
| `0x0041ba40` | `sub_41BA40`, size `0x38e` | Paint routine with a vtable data xref from `0x0060da08`; decompilation draws centered text, frame pieces, and a percentage-width progress fill using `MulDiv(..., byte[this + 0x108], 100)`. |
| `0x0041d580` | `sub_41D580`, size `0x55` | Scalar deleting destructor wrapper; vtable/data xref at `0x0060d9c4`, code xrefs from adjustor thunks `0x0041d471` and `0x0041d47c`, restores vtables, calls `sub_544580`, and conditionally calls `sub_4F4AC0`. |

## Boundary Cautions

- IDA MCP reports `0x0041b9e0` is not a function start and has no direct xrefs. The bytes are documented as [UID:0000WP][0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor](by-memory/0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor.md): they call `ControlPane` setup with type `8`, install the `FittingRoomDownloadControlPane` vtables at offsets `0x0`, `0xa0`, and `0xa4`, clear the word at `0x108`, and return with `retn 4`.
- The adjacent [UID:0000WQ][0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor](by-memory/0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor.md) body restores the same vtables and calls shared teardown helper `0x00544580`; IDA has a function object for this start but currently no xrefs.
- The confirmed deleting destructor at [UID:0002EI][0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor](by-memory/0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor.md) restores the fitting-room download vtables, calls shared pane/control teardown helper `0x00544580`, and conditionally calls delete helper `0x004f4ac0`.
- Stale generated owner assignments place unrelated fitting-room dialog and generic rendering helpers under this class; current IDA evidence should drive ownership instead of those labels.
- Current attached helpers include field-map helpers (`0x004b1130`, `0x004b11a0`), generic draw/text helpers (`0x004b9600`, `0x004b9680`, `0x004ba9a0-0x004bad66`, `0x004bb5e0`, `0x00593b20+`), and IME/text-edit functions (`0x004e7470`, `0x004e7930`). `0x004b11a0` is now documented as a [UID:000151][0x004b11a0-0x004b1241.FieldMapRequestHelper](by-memory/0x004b11a0-0x004b1241.FieldMapRequestHelper.md), `0x004b1130` as a [UID:000150][0x004b1130-0x004b119a.FieldMapRectHelper](by-memory/0x004b1130-0x004b119a.FieldMapRectHelper.md), `0x004b9600` / `0x004b9680` as [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md), `0x004ba9a0-0x004bad66` / `0x004bb5e0` as [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md) and [UID:00016I][0x004bb5e0-0x004bb7df.GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7df.GrafPortDrawGlyph.md), `0x00593c20` / `0x00593db0` under [UID:0000ON][TextEditPane](by-file/TextEditPane.md), and the IME helpers under [UID:0000K5][IMEPanes](by-file/IMEPanes.md); treat these as owner-pollution candidates here.
- Current attached helpers also include `0x00541660` and `0x005416d0`. IDA MCP rechecked them on 2026-05-25 and found every direct caller inside `NewOptionPane::OnPaint`, not fitting-room code. Treat [UID:0001DZ][0x00541660-0x005416d0.NewOptionPaneDrawBoldText](by-memory/0x00541660-0x005416d0.NewOptionPaneDrawBoldText.md) and [UID:0001E0][0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem](by-memory/0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem.md) as option-pane owner-pollution candidates.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `78` | The class has current live IDA evidence for the raw constructor bytes, non-deleting destructor, vtable-referenced paint method, scalar deleting destructor, local progress field, progress-state linkage, and parent source ownership. Completion remains capped because the exact `OnPaint` by-memory split is still inside the broad UI core page and several attached helper labels remain owner-pollution candidates. |
| Confidence `88` | Vtable writes, vtable restoration, vtable data xrefs, shared teardown, destructor thunk xrefs, and fitting-room parent evidence are direct and consistent. Confidence is not higher because the raw constructor still has no IDA function record/xrefs and final member names are not proven. |

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

## Changes

- 2026-06-03: Raised completion/confidence to `78/88` after live IDA MCP reconfirmed the raw constructor bytes at `0x0041b9e0`, `sub_41BA20` size `0x1f`, `sub_41BA40` size `0x38e` with vtable data xref `0x0060da08`, and `sub_41D580` size `0x55` with adjustor-thunk and vtable xrefs. The update also removes generated-source evidence from the status/boundary sections. C++ stays blank because the `OnPaint` child split and final member/helper names are not source-quality yet.
- 2026-06-02: Raised the class page to 70/82, marked it reconstructable, and attached it to [UID:0000JE][FittingRoom](by-file/FittingRoom.md). Added local core evidence and score rationale while leaving C++ blank because field names, `OnPaint` child boundaries, and helper ownership are not final-source quality.
- 2026-05-30: Added a direct by-memory reference for the confirmed `0x0041d580-0x0041d5d5` deleting-destructor wrapper and scored the class page from 0/0 to 62/76. Evidence: IDA MCP confirms the wrapper's function size, vtable reference, adjacent adjustor-thunk callers, shared teardown call, and conditional delete-helper call.
- 2026-05-27: Existing boundary note treated `0x0041b9e0` mainly as a projected non-function start. Changed it to document the actual byte-level split: `0x0041b9e0-0x0041ba20` is a raw constructor-shaped body and `0x0041ba20-0x0041ba3f` is a raw destructor/body helper. Evidence: IDA MCP still reports no function/xrefs at `0x0041b9e0`, while manual IDA disassembly shows vtable installation, `this + 0x108` initialization, and adjacent vtable restore plus shared teardown before `OnPaint`.
