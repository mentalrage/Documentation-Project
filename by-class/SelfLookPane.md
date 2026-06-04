*** UID:0000CU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SelfLookPane

## Status

- Confidence: strong for class purpose and IDA boundaries; medium for several provisional helper names.
- Likely source file: [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md)
- Main address range: [UID:0001H7][0x00565610-0x0056a373.SelfLookPane](by-memory/0x00565610-0x0056a373.SelfLookPane.md)
- Autogen handling: attached to [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md) because the file parent is `82/88` with projected path `NexusTK/ui/panels/` and this class is above the 80% confidence attachment threshold. C++ remains blank because the class declaration, fields, and helper method names are not final-audit quality.

## Class Purpose

`SelfLookPane` is the player's own look/status panel. It owns character-data parsing, equipment slot rendering, stat/legend view switching, world-map refresh bridging, body/equipment/stat visibility toggles, input handling, item-slot hit testing, and the large self-look paint path.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x00565610-0x005657d2` | Initializes `PanelPane`, DAT-backed resources, child `SpelledPane` and `LegendPane`, and self-look state fields. |
| non-deleting destructor | `0x005657e0-0x00565887` | IDA-confirmed cleanup body for child panes/resources. |
| `OnReceiveCharacterData` | `0x00565890-0x00566f24` | Parses character data and updates look/stat/equipment fields. |
| `SendToggleLook` | `0x00566f40-0x00566ffa` | Sends the look/body visibility toggle packet. |
| `SendToggleEquip` | `0x00567000-0x005670ba` | Sends the equipment visibility toggle packet. |
| `SendToggleStats` | `0x005670c0-0x0056717a` | Sends the stat/spelled-view visibility toggle packet. |
| `RefreshWorldMapPane` | `0x005671c0-0x005671de` | Refreshes the embedded/related world-map pane. |
| child refresh helper | `0x005671e0-0x005671f1` | IDA-confirmed helper around the spelled child pane. |
| `ResetAndRefresh` | `0x00567200-0x00567280` | Resets state and refreshes visible child panes. |
| `ActivateView` | `0x00567280-0x005672b0` | Shows/activates the current view. |
| `DeactivateView` | `0x00567380-0x00567472` | Hides/deactivates child view panes. |
| `OnPaint` | `0x00567480-0x00568bb4` | Main self-look/equipment/stat rendering path. |
| `OnKeyPress` | `0x00568bd0-0x00568ca9` | Keyboard navigation/actions. |
| `OnMouseClick` | `0x00568cb0-0x0056934a` | Mouse hit testing and action dispatch. |
| server/event handler | `0x005693d0-0x005697b5` | IDA-confirmed packet/event handler that calls the adjacent packet/update helper island. |
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

## Evidence Map

| Evidence page | Score | Role |
| --- | ---: | --- |
| [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md) | `82/88` | Source-file owner with `NexusTK/ui/panels/` placement, SelfLookPane/SelfLookPane2 grouping notes, child-pane caveats, and static-state ownership. |
| [UID:0001H7][0x00565610-0x0056a373.SelfLookPane](by-memory/0x00565610-0x0056a373.SelfLookPane.md) | `82/88` | Main executable aggregate with exact modeled functions, raw helper bodies, jump-table spans, vtable writes, child-pane construction, and boundaries. |
| [UID:00023V][0x0056a380-0x0056ba99.SelfLookPanePacketUpdateHelpers](by-memory/0x0056a380-0x0056ba99.SelfLookPanePacketUpdateHelpers.md) | `76/84` | Adjacent packet/update helper island split into exact child pages and attached to the same SelfLookPane file parent. |
| [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md) | `80/87` | IDA-verified SelfLookPane/SpelledPane/LegendPane/SelfLookPane2 vtable family and store-xref evidence. |
| [UID:0002CG][g_selfLookLastHoverEquipmentSlotId](by-global/g_selfLookLastHoverEquipmentSlotId.md) | linked | File/static state tied by xrefs only to the SelfLookPane hover-slot branch. |

## Evidence Notes

- 2026-06-04 IDA MCP confirms the constructor xref from `GeneralPurposePanel` at `0x004b844e`.
- 2026-06-04 IDA MCP confirms the destructor helper at `0x005657e0`, child refresh helper at `0x005671e0`, raw helper bodies at `0x005670c0`, `0x00567180`, `0x005671a0`, and `0x005672b0`, and packet/event handler at `0x005693d0`.
- 2026-06-04 IDA MCP confirms the primary function run through `0x0056a300-0x0056a373`, exact padding at `0x00565608-0x00565610` and `0x0056a373-0x0056a380`, child constructor xrefs at `0x005656cc` and `0x0056571c`, vtable-store refs to `0x00624188`, and the two `0x0066fe40` hover-slot refs in `sub_568CB0`.
- 2026-05-28 IDA MCP resolved the former UNKNOWN gap after `HitTestSlot`: `0x0056a380-0x0056ba99` is real packet/update helper code tied to this class, while the boundary bytes are padding.
- 2026-05-30 IDA MCP xrefs show the only references to `word_66FE40` are the compare/write pair in the `SelfLookPane` hover-slot timer branch at `0x005692c7` and `0x00569310`.
- 2026-06-01 IDA MCP work in the main executable aggregate records switch/jump table spans, constructor/destructor vtable writes, and child `SpelledPane` / `LegendPane` construction refs for the class.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 80 | The class page covers responsibility, method inventory, child panes, static state, file owner, main executable ranges, packet helper island, vtable evidence, and a current live IDA boundary refresh. It remains below high completion because final class fields, helper names, and exact method child pages are not all finished. |
| Confidence | 86 | Live IDA-backed memory, vtable, constructor, raw-helper, helper-island, padding, and global-state pages strongly support class ownership and file placement. Confidence is capped by unresolved exact helper names and source-shape questions around shared child panes. |
| Reconstructable | true | The class is source-authored UI panel code and should be rebuilt, but final C++ is intentionally blank until the declaration and attached methods reach the 95+ gate. |

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

- 2026-06-04: Raised from `76/84` to `80/86` after refreshing the class against live IDA and removing stale non-IDA provenance notes.
  - Before: the class inventory had the right structure but still labeled several bodies by what an older non-IDA analysis missed and the manual report row remained stale.
  - After: the class records the live IDA modeled function run, raw helper bodies, padding, constructor/child/vtable/global xrefs, updated file and memory evidence scores, and keeps final C++ blank under the 95/95 gate.
  - Evidence: IDA MCP `py_eval` on 2026-06-04 confirmed the function starts in `0x00565610-0x0056a373`, raw bodies at `0x005670c0`, `0x00567180`, `0x005671a0`, and `0x005672b0`, padding at `0x00565608-0x00565610` and `0x0056a373-0x0056a380`, child constructor xrefs at `0x005656cc`/`0x0056571c`, vtable refs at `0x00565640`, `0x0056580b`, and `0x00573762`, and hover-slot refs at `0x005692c7`/`0x00569310`.

- 2026-05-28: Added `0x0056a380-0x0056ba99` as a SelfLookPane packet/update helper island.
  - Before: class documentation stopped at `HitTestSlot` before an UNKNOWN memory gap.
  - After: the helper island is recorded as adjacent SelfLookPane support code while the main contiguous memory page remains `0x00565610-0x0056a373`.
  - Evidence: IDA MCP reports calls to island functions from `0x00569588` and `0x0056972f` inside the existing SelfLookPane packet/event handler, plus helper bodies that touch SelfLookPane state offsets and redraw through pane virtuals.
- 2026-05-30: Added the `g_selfLookLastHoverEquipmentSlotId` static/global state owned by the hover-slot timer path.
  - Before: the class page did not identify the `0x0066fe40` state used by `OnMouseClick`.
  - After: the class page records the state as SelfLookPane-owned hover equipment-slot cache and links the global/memory pages.
  - Evidence: IDA MCP xrefs to `word_66FE40` are limited to `0x005692c7` and `0x00569310`, both inside `SelfLookPane::OnMouseClick` / mouse-event handling.
- 2026-06-02: Raised from `55/70` to `76/84`, marked reconstructable, and attached to [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md) after consolidating the already-validated file, main memory aggregate, packet/update island, vtable-family, and hover-slot global evidence. C++ remains blank under the 95+ reconstruction gate.
