** TARGET-REPORT-UID:0002RC **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0002RC SelfLookPaneEquipmentRecordParser Source-Quality Report

Agent: B006  
Assignment: B006-report-0002RC-self-look-pane-equipment-record-parser-20260625  
Mode: report-only research first  
Target: [UID:0002RC] `by-memory/0x0056a640-0x0056b5c0.SelfLookPaneEquipmentRecordParser.md`

## Current Recommendation

Keep [UID:0002RC] as a reconstructable `SelfLookPane` class method, owned and emitted through [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md), and replace the blank formal C++ block with first-draft method code for `SelfLookPane::ApplyEquipmentSlotRecord`.

Recommended metadata after implementation:

| Field | Current | Recommended |
| --- | ---: | ---: |
| `COMPLETION` | `86` | `90` |
| `CONFIDENCE` | `90` | `92` |
| `CANONICAL_OWNER` | `0000CU` | `0000CU` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `0000CU` | `0000CU` |

The old note saying the page is blocked by a `90/90+` code-entry rule is stale. Current `by-structure.md` allows formal C++ when the target is reconstructable, has a confirmed emitter route, and `(COMPLETION + CONFIDENCE) / 2 > 85`; [UID:0002RC] currently averages `88` and routes through [UID:0000CU] to [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md). The remaining field and case names can be resolved to source-facing inferred names from the live MCP switch, the clear-slot sibling, the mouse-click selector sends, the help-label string bytes, and the accepted SelfLookPane naming style.

## Target State Checked

Current target header:

| Header field | Value |
| --- | --- |
| UID | `0002RC` |
| Range | `0x0056a640-0x0056b5c0` |
| Completion / Confidence | `86/90` |
| Owner / emitter | `0000CU` / `0000CU` |
| Reconstructable | `TRUE` |
| Formal C++ | blank |
| Stale note | says C++ remains blank until slot fields and switch-case names are source-quality and cites old `90/90+` gate |

Docs and generated inputs checked as leads, not authority:

- Target page [UID:0002RC].
- Parent/helper map [UID:00023V][0x0056a380-0x0056ba99.SelfLookPanePacketUpdateHelpers](by-memory/0x0056a380-0x0056ba99.SelfLookPanePacketUpdateHelpers.md).
- Caller/event handler [UID:0003QQ][0x005693d0-0x00569860.SelfLookPanePacketEventHandler](by-memory/0x005693d0-0x00569860.SelfLookPanePacketEventHandler.md).
- Clear sibling [UID:0002RD][0x0056b5c0-0x0056b7c0.SelfLookPaneClearSlotSwitchRaw](by-memory/0x0056b5c0-0x0056b7c0.SelfLookPaneClearSlotSwitchRaw.md).
- Mouse/help/slot support pages [UID:0003QP], [UID:0003QV], [UID:0003QW], and [UID:0003EY].
- [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md) and [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md).
- Accepted adjacent source-quality reports: B007 [UID:0002RE] and B006 [UID:0002RF].
- Read-only generated state: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/NexusTK/ui/panels/SelfLookPane.cpp`.

Generated state is stale for this target. The source page is `86/90`, but `auto-generated/-ag-research-tracker.md` and `auto-generated/NexusTK/ui/panels/SelfLookPane.cpp` still show [UID:0002RC] as old `76/84` empty-emitter state. Do not hand-edit generated files; a validator run after accepted by-* implementation should refresh them.

## Live MCP Provenance

IDA MCP was available and mandatory evidence was gathered from active session `80de0a67`.

| JSON-RPC / tool | Result used |
| --- | --- |
| `initialize` | MCP replied `200`, server `ida-pro-mcp`, protocol `2025-06-18`. |
| `tools/list` | Current schema rechecked; IDB-backed tools require `database`. |
| `idb_list` | Active worker session `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, PID `26892`, not analyzing. |
| `server_health` | `status:"ok"`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, Hex-Rays and strings cache ready. |
| `lookup_funcs` | `0x0056a640 -> sub_56A640`, size `0xf22`; `0x0056b562` and `0x0056b5c0` are not functions; caller `0x005693d0`, summary child `0x0056b7c0`, and spelled child `0x0056b950` are modeled siblings. |
| `xrefs_to` / `xref_query` | Exactly one code xref to `0x0056a640` from `0x00569588` inside `sub_5693D0`; switch data refs to `0x0056b5a0` and `0x0056a6b1` are local from `0x0056a6aa`; no xrefs to `0x0056b562` or `0x0056b5c0`. |
| `callees` | Target callees are `sub_516030`, `memmove` wrapper `0x00516220`, `PacketBufferReadUInt16BE` at `0x00575480`, `PacketBufferReadUInt32BE` at `0x005754c0`, `MultiByteToWideChar`, `std::_Narrow_char_traits<char,int>::to_char_type`, and security-cookie support. |
| `decompile 0x0056a640` | Confirms packet selector at `packet+1`, item id at `packet+2`, record state byte at `packet+4`, two length-prefixed multibyte strings, per-slot id/state/name/description/dword/byte writes, redraw through vtable slot `+0x20`, and return `0`. |
| `decompile 0x005693d0` | Confirms event-handler opcode `0x37` returns `sub_56A640(this - 40, event->packet)`, while opcode `0x38` runs the matching clear switch. |
| `decompile 0x00569860` plus `get_bytes 0x006248e0` | Confirms help labels for hit-test slots 7..20 and decodes the UTF-16 label run directly because IDA string typing is partial. |
| `decompile 0x00568cb0` | Confirms mouse-click hit-test cases map slots 7..20 to take-off/equipment selectors `22,4,23,1,2,3,8,14,7,20,16,21,6,13`. |
| `get_bytes` | Confirms the target tail: body ending/ret bytes at `0x0056b542`, `0x0056b562-0x0056b5c0` jump-table/byte-map/alignment data, and `0x0056a63e-0x0056a640` as `04 00` lead-in before the modeled function. |
| `int_convert` | Verified `0xf22 = 3874`, opcode `0x37 = 55`, opcode `0x38 = 56`, and tail size `0x5e = 94` where decimal values are recorded. |

## Positive Evidence

The target is a single complete method with owned compiler switch data. `lookup_funcs` reports one modeled function at `0x0056a640`, size `0xf22`, ending at `0x0056b562`; `lookup_funcs` reports no function at `0x0056b562` or `0x0056b5c0`. The `0x0056b562-0x0056b5c0` tail contains jump target dwords, byte map entries, and `0xcc` alignment, with only local refs from the switch at `0x0056a6aa`. Reconstruct the source switch, not the compiler tables.

The caller route is exact and class-local. The `SelfLookPane` packet/event handler dispatches opcode `0x37` to this method and opcode `0x38` to the sibling clear switch. This pairing makes the source-facing role "apply equipment slot record" rather than a generic character parser.

The parser and the clear switch touch the same slot-id block. The parser writes item id words at `this+0x15a..0x174`; [UID:0002RD] clears those exact words for the same selectors. The parser also writes parallel per-slot record-state bytes, name buffers, description/detail buffers, dwords, and trailing bytes.

Slot names are recoverable by triangulation:

| Route | Evidence |
| --- | --- |
| Help labels | `0x00569860` maps hit-test slots 7..20 to decoded UTF-16 labels: `Faceaccessory(1)`, `Head(h)`, `Headaccessory(2)`, `Righthand(w)`, `Body(a)`, `Lefthand(s)`, `Rightaccessory(r)`, `Mantle(m)`, `Leftaccessory(l)`, `Subaccessory([)`, `Coat(c)`, stored `Subaccessory(r)`, `Necklace(n)`, and `Foot(f)`. |
| Mouse click selectors | `0x00568cb0` sends selectors from hit-test slots 7..20 as `22,4,23,1,2,3,8,14,7,20,16,21,6,13`. |
| Take-off key table | [UID:0001OF][g_equipmentSlotKeys](by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md) uses the same selector domain and valid selector set. |
| Clear switch | [UID:0002RD] clears only selectors `1,2,3,4,6,7,8,13,14,16,20,21,22,23`, matching the parser's non-default cases. |

The source-facing field layout can be represented as sparse arrays indexed by the visible `SelfLookEquipmentSlot` id:

| Field role | Base expression from MCP offsets | Evidence |
| --- | --- | --- |
| item id word | `m_equipmentSlotItemIds[slot]` | `this+0x14c + 2*slot`; parser writes it, clear switch zeros it, mouse tooltip checks it before showing equipment detail. |
| record state byte | `m_equipmentSlotRecordStates[slot]` | `this+0x176 + slot`; parser writes `packet[4]`. |
| item name wide buffer | `m_equipmentSlotNames[slot]` | `this+0x18c + 0x80*slot`; first length-prefixed string converted through `MultiByteToWideChar`. |
| description/detail wide buffer | `m_equipmentSlotDescriptions[slot]` | `this+0xc0c + 0x80*slot`; second length-prefixed string converted through `MultiByteToWideChar`; mouse tooltip passes this high buffer as the first text argument. |
| extra dword | `m_equipmentSlotValues[slot]` | `this+0x168c + 4*slot`; parser reads from the post-string cursor through `PacketBufferReadUInt32BE`. |
| extra byte | `m_equipmentSlotValueFlags[slot]` | `this+0x16e0 + slot`; parser reads the byte immediately after the extra dword; mouse tooltip passes it to the equipment-detail popup. |

## Selector / Slot / Offset Table

Recommended selector and slot names are source-facing inferred names, not recovered original symbols.

| Packet selector | Best source-facing selector name | Visible slot id | Help label / key evidence | Item id | State | Name | Description | Dword | Byte |
| ---: | --- | ---: | --- | --- | --- | --- | --- | --- | --- |
| `1` | `RightHand` | `10` | `Righthand(w)` | `+0x160` | `+0x180` | `+0x68c` | `+0x110c` | `+0x16b4` | `+0x16ea` |
| `2` | `Body` | `11` | `Body(a)` | `+0x162` | `+0x181` | `+0x70c` | `+0x118c` | `+0x16b8` | `+0x16eb` |
| `3` | `LeftHand` | `12` | `Lefthand(s)` | `+0x164` | `+0x182` | `+0x78c` | `+0x120c` | `+0x16bc` | `+0x16ec` |
| `4` | `Head` | `8` | `Head(h)` | `+0x15c` | `+0x17e` | `+0x58c` | `+0x100c` | `+0x16ac` | `+0x16e8` |
| `6` | `Necklace` | `19` | `Necklace(n)` | `+0x172` | `+0x189` | `+0xb0c` | `+0x158c` | `+0x16d8` | `+0x16f3` |
| `7` | `LeftAccessory` | `15` | `Leftaccessory(l)` | `+0x16a` | `+0x185` | `+0x90c` | `+0x138c` | `+0x16c8` | `+0x16ef` |
| `8` | `RightAccessory` | `13` | `Rightaccessory(r)` | `+0x166` | `+0x183` | `+0x80c` | `+0x128c` | `+0x16c0` | `+0x16ed` |
| `13` | `Foot` | `20` | `Foot(f)` | `+0x174` | `+0x18a` | `+0xb8c` | `+0x160c` | `+0x16dc` | `+0x16f4` |
| `14` | `Mantle` | `14` | `Mantle(m)` | `+0x168` | `+0x184` | `+0x88c` | `+0x130c` | `+0x16c4` | `+0x16ee` |
| `16` | `Coat` | `17` | `Coat(c)` | `+0x16e` | `+0x187` | `+0xa0c` | `+0x148c` | `+0x16d0` | `+0x16f1` |
| `20` | `LeftSubAccessory` | `16` | `Subaccessory([)` | `+0x16c` | `+0x186` | `+0x98c` | `+0x140c` | `+0x16cc` | `+0x16f0` |
| `21` | `RightSubAccessory` | `18` | second subaccessory slot; stored help text currently decodes as `Subaccessory(r)`, while selector-key domain uses `]` | `+0x170` | `+0x188` | `+0xa8c` | `+0x150c` | `+0x16d4` | `+0x16f2` |
| `22` | `FaceAccessory1` | `7` | `Faceaccessory(1)` | `+0x15a` | `+0x17d` | `+0x50c` | `+0xf8c` | `+0x16a8` | `+0x16e7` |
| `23` | `HeadAccessory2` | `9` | `Headaccessory(2)` | `+0x15e` | `+0x17f` | `+0x60c` | `+0x108c` | `+0x16b0` | `+0x16e9` |

Selectors `5`, `9`, `10`, `11`, `12`, `15`, `17`, `18`, and `19` are default/no-update cases in the parser and no-clear/default cases in [UID:0002RD]. They still invalidate the pane when opcode `0x37` reaches this parser, matching the decompiled default branch.

## Negative And Counter-Evidence

No evidence supports a split. The function body, jump table, byte map, and alignment tail are one compiler switch unit. `0x0056b562` has no xrefs, no function object, and is reached only by fall-through after `ret 4`; `0x0056b5c0` is the next raw sibling and has no incoming xrefs from this target.

No evidence supports a different owner. PacketBuffer owns scalar readers and the memmove wrapper is a CRT support dependency, but the method's semantic writes are all `SelfLookPane` fields and the only caller is the `SelfLookPane` packet handler. ItemActionInputPanes owns the outbound take-off helper, not this inbound record parser.

Exact original names are not recovered. The report therefore recommends descriptive source-facing names, with the inference written into target/support docs. This is not a blocker under the B-agent standard because the names are grounded in direct labels, selector sends, clear-switch behavior, and field access.

The second subaccessory label has a local caveat. Direct bytes at `0x006249e4` decode as `Subaccessory(r)`, while [UID:0001OF] selector keys distinguish selector `20` as `[` and selector `21` as `]`. The source-facing slot name `RightSubAccessory` remains the best fit for the second subaccessory position because hit-test slot `18` maps to selector `21` and is paired with the first subaccessory at hit-test slot `16` / selector `20`.

The target start contains a call to `sub_516030`, which decompiles as a six-byte global read returning `unk_69B4FC` and has no consumed return value. Treat it as compiler/library scaffolding for this source draft rather than an application-level parser step; do not expose the IDA helper name in first-draft C++.

## First-Draft C++ Recommendation

[UID:0002RC] is formal C++ ready. The behavior, packet layout, selector cases, slot names, field layout, switch-data ownership, caller route, and redraw are current-MCP confirmed. Remaining original-spelling uncertainty is handled by inferred source-facing names.

Exact formal `RECONSTRUCTION_CPP CODE` block content to insert:

*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool SelfLookPane::ApplyEquipmentSlotRecord(const unsigned char *packet)
{
    enum {
        SelfLookEquipmentSelector_RightHand = 1,
        SelfLookEquipmentSelector_Body = 2,
        SelfLookEquipmentSelector_LeftHand = 3,
        SelfLookEquipmentSelector_Head = 4,
        SelfLookEquipmentSelector_Necklace = 6,
        SelfLookEquipmentSelector_LeftAccessory = 7,
        SelfLookEquipmentSelector_RightAccessory = 8,
        SelfLookEquipmentSelector_Foot = 13,
        SelfLookEquipmentSelector_Mantle = 14,
        SelfLookEquipmentSelector_Coat = 16,
        SelfLookEquipmentSelector_LeftSubAccessory = 20,
        SelfLookEquipmentSelector_RightSubAccessory = 21,
        SelfLookEquipmentSelector_FaceAccessory1 = 22,
        SelfLookEquipmentSelector_HeadAccessory2 = 23
    };

    enum {
        SelfLookEquipmentSlot_FaceAccessory1 = 7,
        SelfLookEquipmentSlot_Head = 8,
        SelfLookEquipmentSlot_HeadAccessory2 = 9,
        SelfLookEquipmentSlot_RightHand = 10,
        SelfLookEquipmentSlot_Body = 11,
        SelfLookEquipmentSlot_LeftHand = 12,
        SelfLookEquipmentSlot_RightAccessory = 13,
        SelfLookEquipmentSlot_Mantle = 14,
        SelfLookEquipmentSlot_LeftAccessory = 15,
        SelfLookEquipmentSlot_LeftSubAccessory = 16,
        SelfLookEquipmentSlot_Coat = 17,
        SelfLookEquipmentSlot_RightSubAccessory = 18,
        SelfLookEquipmentSlot_Necklace = 19,
        SelfLookEquipmentSlot_Foot = 20
    };

    const unsigned char selector = packet[1];
    const unsigned short itemId = PacketBufferReadUInt16BE(packet + 2);
    const unsigned char recordState = packet[4];
    char text[256];

#define APPLY_SELF_LOOK_EQUIPMENT_SLOT(SLOT_ID)                                      \
    do {                                                                             \
        m_equipmentSlotItemIds[SLOT_ID] = itemId;                                    \
        m_equipmentSlotRecordStates[SLOT_ID] = recordState;                          \
        const unsigned char *cursor = packet + 5;                                    \
        unsigned int textLength = *cursor++;                                         \
        memmove(text, cursor, textLength);                                           \
        text[textLength] = '\0';                                                     \
        int converted = MultiByteToWideChar(0, 0, text, textLength,                  \
                                            m_equipmentSlotNames[SLOT_ID], 256);     \
        m_equipmentSlotNames[SLOT_ID][converted] = L'\0';                            \
        cursor += textLength;                                                        \
                                                                                     \
        textLength = *cursor++;                                                      \
        memmove(text, cursor, textLength);                                           \
        text[textLength] = '\0';                                                     \
        converted = MultiByteToWideChar(0, 0, text, textLength,                      \
                                        m_equipmentSlotDescriptions[SLOT_ID], 256);  \
        m_equipmentSlotDescriptions[SLOT_ID][converted] = L'\0';                     \
        cursor += textLength;                                                        \
                                                                                     \
        m_equipmentSlotValues[SLOT_ID] = PacketBufferReadUInt32BE(cursor);           \
        m_equipmentSlotValueFlags[SLOT_ID] = cursor[4];                              \
    } while (0)

    switch (selector) {
    case SelfLookEquipmentSelector_RightHand:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_RightHand);
        break;
    case SelfLookEquipmentSelector_Body:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_Body);
        break;
    case SelfLookEquipmentSelector_LeftHand:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_LeftHand);
        break;
    case SelfLookEquipmentSelector_Head:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_Head);
        break;
    case SelfLookEquipmentSelector_Necklace:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_Necklace);
        break;
    case SelfLookEquipmentSelector_LeftAccessory:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_LeftAccessory);
        break;
    case SelfLookEquipmentSelector_RightAccessory:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_RightAccessory);
        break;
    case SelfLookEquipmentSelector_Foot:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_Foot);
        break;
    case SelfLookEquipmentSelector_Mantle:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_Mantle);
        break;
    case SelfLookEquipmentSelector_Coat:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_Coat);
        break;
    case SelfLookEquipmentSelector_LeftSubAccessory:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_LeftSubAccessory);
        break;
    case SelfLookEquipmentSelector_RightSubAccessory:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_RightSubAccessory);
        break;
    case SelfLookEquipmentSelector_FaceAccessory1:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_FaceAccessory1);
        break;
    case SelfLookEquipmentSelector_HeadAccessory2:
        APPLY_SELF_LOOK_EQUIPMENT_SLOT(SelfLookEquipmentSlot_HeadAccessory2);
        break;
    default:
        break;
    }

#undef APPLY_SELF_LOOK_EQUIPMENT_SLOT

    InvalidateRect(&m_bounds);
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Source-shape notes:

- The macro is intentional first-draft source shape. It preserves the source switch and repeated per-case expansion implied by the compiled jump table while avoiding IDA-style temporary names.
- `PacketBufferReadUInt16BE`, `PacketBufferReadUInt32BE`, `memmove`, `MultiByteToWideChar`, and `InvalidateRect(&m_bounds)` follow already accepted project naming/style.
- The local enum names should be documented as inferred. If implementation policy prefers shared class/file enum declarations later, the target body can still keep the same source-facing names.

## Recommended Target Doc Changes

| Path | Required edit |
| --- | --- |
| `by-memory/0x0056a640-0x0056b5c0.SelfLookPaneEquipmentRecordParser.md` | Set `COMPLETION:90`, `CONFIDENCE:92`; keep owner/emitter/reconstructable unchanged. |
| same | Replace stale `90/90+` code-entry wording with the current combined-score/emitter gate and state this target is first-draft formal C++ ready. |
| same | Add the live MCP provenance, opcode `0x37` caller route, and opcode `0x38` clear-switch sibling relation. |
| same | Document the packet layout: selector at `packet+1`, big-endian item id at `packet+2`, state byte at `packet+4`, first length-prefixed string, second length-prefixed string, trailing big-endian dword, and trailing byte. |
| same | Add the selector/slot/offset table above and the inferred field names: `m_equipmentSlotItemIds`, `m_equipmentSlotRecordStates`, `m_equipmentSlotNames`, `m_equipmentSlotDescriptions`, `m_equipmentSlotValues`, and `m_equipmentSlotValueFlags`. |
| same | Add switch-data handling: `0x0056b562-0x0056b5c0` is parser-owned compiler switch data/alignment; no child split or emission should be created for that tail. |
| same | Insert the formal C++ block above. |

## Recommended Support Doc Changes

| Path | Required edit |
| --- | --- |
| `by-memory/0x0056a380-0x0056ba99.SelfLookPanePacketUpdateHelpers.md` | Update the [UID:0002RC] covered-range and split-child rows to name the method `SelfLookPane::ApplyEquipmentSlotRecord`, state that selector/slot fields are now source-quality inferred names, and note formal first-draft C++ is ready on the child page. No metadata change required. |
| `by-memory/0x005693d0-0x00569860.SelfLookPanePacketEventHandler.md` | Add that opcode `0x37` dispatches to `SelfLookPane::ApplyEquipmentSlotRecord` at `0x0056a640`, and opcode `0x38` is the matching slot-clear switch for the same selector/id fields. No metadata change required. |
| `by-memory/0x0056b5c0-0x0056b7c0.SelfLookPaneClearSlotSwitchRaw.md` | Add the slot-name table from this report so the clear cases no longer remain anonymous offsets. Keep formal C++ blank unless a separate raw-start liveness/C++ pass is accepted; raw-start no-xref remains its own blocker. |
| `by-memory/0x00568cb0-0x005693d0.SelfLookPaneOnMouseClick.md` | Extend the existing take-off selector table with visible slot names and hit-test slot ids, preserving that [UID:0001M2] remains an ItemActionInputPanes dependency. |
| `by-memory/0x006248e0-0x00624a50.SelfLookPaneEquipmentSlotLabelStrings.md` | Add the decoded UTF-16 label list and the direct-byte caveat for the second subaccessory label. No generated/coverage edits. |
| `by-class/SelfLookPane.md` | Add [UID:0002RC] to accepted child method C++ as `SelfLookPane::ApplyEquipmentSlotRecord`; add inferred equipment slot enum/field layout support, while preserving the broader class-level blank C++ rationale. |
| `by-file/SelfLookPane.md` | Add that [UID:0002RC] now emits first-draft method C++ through `NexusTK/ui/panels/SelfLookPane.cpp`; note generated output is stale until validator refresh. |
| `by-memory/0x00569ed0-0x0056a300.SelfLookPaneGetSlotColors.md` and `by-memory/0x0056a300-0x0056a373.SelfLookPaneHitTestSlot.md` | Optional support sync if implementation wants full cross-linking: add that their slot ids 7..20 now map to the named equipment selector domain documented by [UID:0002RC]. No metadata change required. |

Do not edit generated reports, generated C++, project-level files, validator state/cache, IDA DB, or any `-coverage-report.md`. No manual supervisor-owned coverage/tracker text is needed; source metadata plus validators should refresh generated state.

## Score And Metadata Rationale

`90/92` is justified because this pass resolves the named score blockers: selector names, slot names, packet layout, repeated field layout, switch-data handling, opcode route, and first-draft C++ readiness. The target should not go higher yet because exact original field names, exact original enum spelling, and full class declaration layout remain inferred rather than original-symbol proof, and broader `SelfLookPane` class C++ still has unresolved fields outside this target.

Owner and emitter remain unchanged. The direct semantic owner is the `SelfLookPane` class; output routing through [UID:0000CU] already surfaces to [UID:0000NL] and `NexusTK/ui/panels/SelfLookPane.cpp`.

No split, rename, or new child is recommended. The compiler switch tail stays in this page as owned data and should be regenerated from the source switch.

## Validator Expectations For Implementation Callback

Run validators only after accepted by-* edits, from `E:\NTK\GhidraBridge\source-3\project-documentation`, and only for changed files. Likely commands:

> Executable block R001 was removed from this report and preserved verbatim in [0002RC-SelfLookPaneEquipmentRecordParser-source-quality-removed.md](0002RC-SelfLookPaneEquipmentRecordParser-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the implementation callback chooses not to touch optional hit-test/slot-color support docs, do not validate them.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B006/research/0002RC-SelfLookPaneEquipmentRecordParser-source-quality.md`

Modified by this report-only pass:

- None outside the report.

Leases:

- None. Report-only research does not require leases.

Validators:

- Not run during report-only pass. Validators are implementation-callback work after accepted by-* edits.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: the supervisor accepted this report for implementation in the updated Agent-B006 callback goal before by-* edits began.
- [x] Target doc `by-memory/0x0056a640-0x0056b5c0.SelfLookPaneEquipmentRecordParser.md`: applied `COMPLETION:90`, `CONFIDENCE:92`, preserved `CANONICAL_OWNER:0000CU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CU`, and blank `EMITTER_POSITION_OPTIONAL`; added the current combined-score/emitter gate, opcode `0x37` caller evidence, opcode `0x38` clear sibling relation, packet layout, selector/slot/field tables, switch-tail handling, negative evidence, and formal `SelfLookPane::ApplyEquipmentSlotRecord` C++.
- [x] Parent/helper map `by-memory/0x0056a380-0x0056ba99.SelfLookPanePacketUpdateHelpers.md`: updated the [UID:0002RC] row and notes to `ApplyEquipmentSlotRecord`, resolved slot-field naming, and accepted child first-draft C++ readiness; support metadata left unchanged.
- [x] Event handler `by-memory/0x005693d0-0x00569860.SelfLookPanePacketEventHandler.md`: added opcode `0x37` parser dispatch to [UID:0002RC] and opcode `0x38` matching clear-switch evidence; support metadata left unchanged.
- [x] Clear sibling `by-memory/0x0056b5c0-0x0056b7c0.SelfLookPaneClearSlotSwitchRaw.md`: added selector/slot names and `m_equipmentSlotItemIds[slot]` relationship; preserved blank C++ because raw-start no-xref/liveness remains unresolved for that separate target.
- [x] Mouse support `by-memory/0x00568cb0-0x005693d0.SelfLookPaneOnMouseClick.md`: added hit-test slot id to take-off selector names and preserved [UID:0001M2] dependency ownership.
- [x] Label support `by-memory/0x006248e0-0x00624a50.SelfLookPaneEquipmentSlotLabelStrings.md`: added decoded UTF-16 labels and the second-subaccessory caveat that direct bytes decode as `Subaccessory(r)` while selector-key evidence uses `]`.
- [x] Class/file support `by-class/SelfLookPane.md` and `by-file/SelfLookPane.md`: added accepted first-draft child method `SelfLookPane::ApplyEquipmentSlotRecord`, inferred equipment selector/slot/field layout, generated-state caveat, and preserved broader class/file blank-C++ caveats.
- [x] Optional support sync for `by-memory/0x00569ed0-0x0056a300.SelfLookPaneGetSlotColors.md` and `by-memory/0x0056a300-0x0056a373.SelfLookPaneHitTestSlot.md` explicitly not applied. Proof: the implementation callback made these cross-links optional; the target, class, mouse, label, and clear-switch pages now carry the slot id mapping at report-level detail, so editing the two optional pages would add duplicate links without improving the accepted evidence chain.
- [x] Preserved negative evidence: target, class, file, and support docs state no function at `0x0056b562` or `0x0056b5c0`, local-only switch-data refs, no split/rename/new child, no generated-file authority, no PacketBuffer/ItemAction ownership transfer, and inferred rather than original-proof names.
- [x] Did not manually edit generated reports, generated C++, project-level files, validator state/cache, IDA DB, or any `-coverage-report.md`. Proof: manual edits were limited to the eight leased by-* docs and this Agent-B006 research checklist; generated/project-level output changed only through scoped validator refresh.
- [x] Validators run after accepted implementation edits for every changed by-* file with `python .\tools\validator.py --mode file --file <file> --apply --queue-timeout 240 --wait-generated`. Proof: final/latest scoped runs were [UID:0002RC] target `000000001708` at `2026-06-25T15:08:20-04:00`, helper map `000000001685` at `2026-06-25T15:04:30-04:00`, event handler `000000001686` at `2026-06-25T15:04:42-04:00`, clear sibling `000000001701` at `2026-06-25T15:07:36-04:00`, mouse support `000000001703` at `2026-06-25T15:07:48-04:00`, label support `000000001706` at `2026-06-25T15:08:08-04:00`, class page `000000001690` at `2026-06-25T15:05:28-04:00`, and file page `000000001691` at `2026-06-25T15:05:39-04:00`; each exited `0`, reported `ok: 1`, and `generated_refresh: completed`.
- [x] Generated report refresh was validator-owned only. Proof: validator side effects included `project-level/-auto-completion-stats.md` updates and memory auto-coverage/generated refresh where reported by validator; no manual supervisor-owned coverage/tracker text was edited.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: updated Agent-B006 goal named this as an implementation callback for the accepted 0002RC report.
- [x] Immediate edit-file leases taken only for files being edited and released immediately after edit/validator batch. Proof: B006 leased the eight by-* docs before editing/validation; `python .\leaser.py B006 unlease` later returned `B006: No active leases`, and `tools/leaser/Agents/current_leases.md` showed no active leases.
- [x] All accepted target/support doc details incorporated at report-level detail or explicitly marked not applicable with proof. Proof: all mandatory target/support files listed in the report were updated; the two optional slot helper pages were excluded with the concrete duplication reason above.
- [x] Metadata/score/C++ changes applied to [UID:0002RC]; support metadata left unchanged. Proof: [UID:0002RC] is now `90/92` with first-draft C++; support pages retained existing metadata.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target Changes and Negative Evidence sections now explicitly mark the old `90/90+` blocker and provisional-name rationale as superseded while preserving switch-tail/no-split/no-ownership-transfer evidence.
- [x] Validators run and results recorded. Proof: validator command IDs, timestamps, exit codes, `ok: 1`, and generated-refresh state are recorded above.
- [x] Generated output refreshed or generated-header freshness reported. Proof: all scoped validator outputs reported `generated_refresh: completed`; the target rerun `000000001708` completed after support UID registration.
- [x] Remaining unapplied accepted items listed with exact blocker, if any. Proof: no mandatory accepted item remains unapplied; only optional helper cross-linking was intentionally excluded as non-useful duplication.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0002RC-SelfLookPaneEquipmentRecordParser-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0002RC-SelfLookPaneEquipmentRecordParser-source-quality.md","timestamp":"2026-06-25T16:17:50","uid":"0002RC"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002RC-SelfLookPaneEquipmentRecordParser-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/0002RC-SelfLookPaneEquipmentRecordParser-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002RC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
