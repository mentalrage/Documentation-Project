*** UID:0000CU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:55 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SelfLookPane

## Status

- Confidence: strong for class purpose and IDA boundaries; medium for several generated helper names.
- Likely source file: [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md)
- Main address range: [UID:0001H7][0x00565610-0x0056a373.SelfLookPane](by-memory/0x00565610-0x0056a373.SelfLookPane.md)
- Current recovered file: `source-3/simroot_v2/class_SelfLookPane.cpp`

## Class Purpose

`SelfLookPane` is the player's own look/status panel. It owns character-data parsing, equipment slot rendering, stat/legend view switching, world-map refresh bridging, body/equipment/stat visibility toggles, input handling, item-slot hit testing, and the large self-look paint path.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x00565610-0x005657d2` | Initializes `PanelPane`, DAT-backed resources, child `SpelledPane` and `LegendPane`, and self-look state fields. |
| non-deleting destructor | `0x005657e0-0x00565887` | IDA-confirmed cleanup body for child panes/resources; currently unknown to Wave3. |
| `OnReceiveCharacterData` | `0x00565890-0x00566f24` | Parses character data and updates look/stat/equipment fields. |
| `SendToggleLook` | `0x00566f40-0x00566ffa` | Sends the look/body visibility toggle packet. |
| `SendToggleEquip` | `0x00567000-0x005670ba` | Sends the equipment visibility toggle packet. |
| `SendToggleStats` | `0x005670c0-0x0056717a` | Sends the stat/spelled-view visibility toggle packet. |
| `RefreshWorldMapPane` | `0x005671c0-0x005671de` | Refreshes the embedded/related world-map pane. |
| child refresh helper | `0x005671e0-0x005671f1` | IDA-confirmed helper around the spelled child pane; currently unknown to Wave3. |
| `ResetAndRefresh` | `0x00567200-0x00567280` | Resets state and refreshes visible child panes. |
| `ActivateView` | `0x00567280-0x005672b0` | Shows/activates the current view. |
| `DeactivateView` | `0x00567380-0x00567472` | Hides/deactivates child view panes. |
| `OnPaint` | `0x00567480-0x00568bb4` | Main self-look/equipment/stat rendering path. |
| `OnKeyPress` | `0x00568bd0-0x00568ca9` | Keyboard navigation/actions. |
| `OnMouseClick` | `0x00568cb0-0x0056934a` | Mouse hit testing and action dispatch. |
| unmodeled server/event handler | `0x005693d0-0x005697b5` | IDA-confirmed packet/event handler; currently unknown to Wave3. |
| `OnShowHelp` | `0x00569860-0x00569c3a` | Help display for self-look controls/slots. |
| `OnGetRect` | `0x00569c80-0x00569cce` | Returns class-specific rectangle geometry. |
| `OnTransformRect` | `0x00569cd0-0x00569d75` | Transforms local/child rectangles. |
| `DrawNumberString` | `0x00569d80-0x00569ec1` | Draws numeric stat labels. |
| `GetSlotColors` | `0x00569ed0-0x0056a29e` | Computes equipment slot palette/text colors. |
| `HitTestSlot` | `0x0056a300-0x0056a373` | Maps mouse coordinates to equipment slots. |
| packet/update helper island | `0x0056a380-0x0056ba99` | Sends self-look packets, applies server packet updates, dispatches child `SpelledPane` text, and toggles view/cache state. |
| destructor thunk | `0x005732d6` | Mixed destructor/thunk island entry. |
| scalar deleting destructor | `0x00573730-0x00573818` | Full class destructor plus conditional delete. |

## Child Panes

- [UID:0000DK][SpelledPane](by-class/SpelledPane.md) is constructed at `0x005656cc` and stored at `this[63]`.
- [UID:000074][LegendPane](by-class/LegendPane.md) is constructed at `0x0056571c` and stored at `this[65]`.

## Static State

- [UID:0002CG][g_selfLookLastHoverEquipmentSlotId](by-global/g_selfLookLastHoverEquipmentSlotId.md) at `0x0066fe40` caches the last hovered equipment slot id for the `OnMouseClick` / mouse-event timer path. It is initialized to `0xffff`, accepts only slot ids `7..20`, and is compared/updated inside `0x00568cb0-0x0056934a`.

## Evidence Notes

- Wave3 reports `SelfLookPane` grade `98.3` and zero missing refs.
- IDA confirms the constructor xref from `GeneralPurposePanel` at `0x004b844e`.
- IDA confirms the unmodeled destructor helper at `0x005657e0`, child refresh helper at `0x005671e0`, and packet/event handler at `0x005693d0`.
- 2026-05-28 IDA MCP resolved the former UNKNOWN gap after `HitTestSlot`: `0x0056a380-0x0056ba99` is real packet/update helper code tied to this class, while the boundary bytes are padding.
- 2026-05-30 IDA MCP xrefs show the only references to `word_66FE40` are the compare/write pair in the `SelfLookPane` hover-slot timer branch at `0x005692c7` and `0x00569310`.

## Cross-References

- [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md)
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)
- [UID:0001H7][0x00565610-0x0056a373.SelfLookPane](by-memory/0x00565610-0x0056a373.SelfLookPane.md)
- [UID:00023V][0x0056a380-0x0056ba99.SelfLookPanePacketUpdateHelpers](by-memory/0x0056a380-0x0056ba99.SelfLookPanePacketUpdateHelpers.md)
- [UID:0002CG][g_selfLookLastHoverEquipmentSlotId](by-global/g_selfLookLastHoverEquipmentSlotId.md)
- [UID:0000CV][SelfLookPane2](by-class/SelfLookPane2.md)
- [UID:0000DK][SpelledPane](by-class/SpelledPane.md)
- [UID:000074][LegendPane](by-class/LegendPane.md)

## Changes

- 2026-05-28: Added `0x0056a380-0x0056ba99` as a SelfLookPane packet/update helper island.
  - Before: class documentation stopped at `HitTestSlot` before an UNKNOWN memory gap.
  - After: the helper island is recorded as adjacent SelfLookPane support code while the main contiguous memory page remains `0x00565610-0x0056a373`.
  - Evidence: IDA MCP reports calls to island functions from `0x00569588` and `0x0056972f` inside the existing SelfLookPane packet/event handler, plus helper bodies that touch SelfLookPane state offsets and redraw through pane virtuals.
- 2026-05-30: Added the `g_selfLookLastHoverEquipmentSlotId` static/global state owned by the hover-slot timer path.
  - Before: the class page did not identify the `0x0066fe40` state used by `OnMouseClick`.
  - After: the class page records the state as SelfLookPane-owned hover equipment-slot cache and links the global/memory pages.
  - Evidence: IDA MCP xrefs to `word_66FE40` are limited to `0x005692c7` and `0x00569310`, both inside `SelfLookPane::OnMouseClick` / mouse-event handling.
