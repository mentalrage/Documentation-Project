** TARGET-REPORT-UID:0001F5 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001F5 PowerDialogPaneConstructor Empty-Emitter Source-Quality Report


Assignment: `B003-revise-report-0001F5-PowerDialogPaneConstructor-empty-emitter-source-quality-20260628`  
Agent: `Agent-B003`  
Mode: report-only research first; no by-* edits, no leases, no generated edits, no coverage edits, no tool/IDA process edits.  
Target: [UID:0001F5] `by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md`  
Required report path: `tools/leaser/Agents/Agent-B003/research/0001F5-PowerDialogPaneConstructor-empty-emitter-source-quality.md`

## Executive Recommendation

[UID:0001F5] should remain owned and emitted by [UID:0000AP] `PowerDialogPane`, routed through [UID:0000MO] `PowerDialogPane.cpp`, and should receive formal first-draft constructor C++ in the target `RECONSTRUCTION_CPP CODE` block. The previous blank-C++ recommendation is superseded by this revision.

The active code-entry gate is satisfied (`RECONSTRUCTABLE:TRUE`, nonblank emitter [UID:0000AP], combined assignment score above 85). The current-scope naming and source-shape blockers are resolvable by B-agent inference: use a raw packet-pointer constructor, descriptive `PowerEntryRecord`, `m_powerDialogThresholdDefaults[4]`, `m_encodedPowerValues[5]`, `m_powerGrid[5][5]`, `PowerListPane` list helpers, and existing UI helper aliases. These names are inferred, but they are more source-realistic than preserving an empty emitter.

Recommended target metadata after implementation:

| Field | Current | Recommended | Reason |
| --- | ---: | ---: | --- |
| `COMPLETION` | `85` | `89` | Current MCP resolves the exact constructor phases, owner, caller routes, singleton, vtables, row record offsets, config offset family, dependent pane relationships, and enough source shape for formal first-draft C++. |
| `CONFIDENCE` | `88` | `90` | Live IDA MCP rechecked function size, callers, no-xref wrapper state, singleton refs, vtables, dependent methods, and the constructor decompilation during revision. Confidence remains capped because some helper/member spellings are inferred rather than original-symbol proven. |
| `CANONICAL_OWNER` | `0000AP` | `0000AP` | Constructor installs PowerDialogPane vtables, publishes `g_pPowerDialog`, and is directly part of the PowerDialogPane source family. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | The behavior is reconstructable and now has first-draft emitted constructor source. |
| `EMITTER_UIDS` | `0000AP` | `0000AP` | Keep the route through [UID:0000AP] and [UID:0000MO]. |
| Formal C++ | blank | populate | Insert the exact formal first-draft constructor C++ block in this report. |

Generated state: `auto-generated/NexusTK/ui/dialogs/PowerDialogPane.cpp` currently contains an Empty Emitter Marker for [UID:0001F5]. If this revised report is accepted and implemented, the next generated refresh should emit the constructor block for [UID:0001F5] and remove that specific empty marker. Do not hand-edit generated output.

## Current IDA MCP Status

IDA MCP was available and used. No fallback-only evidence was used.

| Check | Result |
| --- | --- |
| Endpoint | `http://127.0.0.1:13337/mcp` |
| Server | `ida-pro-mcp`; `initialize` and `tools/list` succeeded. |
| Listener/process state | TCP listener `127.0.0.1:13337`; listener PID `21700`; `idalib-mcp.exe` PID `10020` present during this report. |
| Database session | `b003_powerdialog_0001f5_20260628` opened through MCP with `idb_open`, `prefer_gui`, caches built, Hex-Rays initialized. |
| IDB/input | `E:\Desktop\Clone\NexusTK\NexusTK.exe.i64`; module `NexusTK.exe`; imagebase `0x400000`; input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`. |
| Health | `server_health` reported `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`. |
| Revision recheck | `initialize` succeeded again during revision; `server_health(database=b003_powerdialog_0001f5_20260628)` returned `status:"ok"`, `uptime_sec:558.14`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`. A focused `decompile(addr=0x00549c20)` succeeded with the current MCP schema using `addr`. |

## Current Target And Generated State

Target page state read for this report:

- `COMPLETION:85`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000AP`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000AP`
- Formal `RECONSTRUCTION_CPP CODE` header and block are blank.
- The page already rejects generated `PowerListPane::InitializeFromData` ownership and assigns [UID:0001F5] to `PowerDialogPane`.
- The current blank-C++ rationale names the correct problem family but is now too conservative. It should be replaced by the formal first-draft constructor C++ and source-shape rationale below.

Generated file state read for this report:

- `auto-generated/NexusTK/ui/dialogs/PowerDialogPane.cpp` was refreshed before this report at `2026-06-28T03:49:58-04:00` by validator command `000000005013`.
- It emits [UID:0001F7] singleton helpers only.
- It has Empty Emitter Markers for [UID:0000AP], [UID:0001F5], [UID:0000AQ], [UID:0000S0], [UID:0001PZ], and [UID:0001F6].
- Do not edit this generated file in the implementation callback.

## Function, Boundary, Caller, And Wrapper Evidence

Live MCP `lookup_funcs` and conversion checks:

| Address | Result |
| --- | --- |
| `0x00549c20` | `sub_549C20`, size `0x852` / 2130 bytes by `int_convert.py`. |
| `0x0054a472` | Not a function; this is the exclusive target end. |
| `0x0054a480` | `sub_54A480`, singleton destructor helper, size `0x29`. |
| `0x0054a4b0` | `sub_54A4B0`, singleton getter helper, size `0x6`. |
| `0x00513b50` | IDA name `___std_parallel_algorithms_hw_threads@0_2`, wrapper body, size `0x5b`. |
| `0x00507c90` | `sub_507C90`, MapPane packet dispatcher, caller of the constructor at `0x0050876a`. |

Live MCP `xref_query`:

- Incoming refs to `0x00549c20` are exactly two:
  - `0x0050876a` in `sub_507C90` (`MapPane::HandlePacket` packet route).
  - `0x00513b93` in the wrapper at `0x00513b50`.
- Incoming refs to `0x00513b50` are zero. The wrapper is source-family evidence, not a live dispatch route.
- Incoming refs to `g_pPowerDialog` at `0x0069ba34` are exactly five:
  - `0x0054a44c` constructor publish.
  - `0x0054a49a` singleton destructor clear.
  - `0x0054a4b0` singleton getter read.
  - `0x0054b010` `PowerListPane::OnMouseEvent` owner-dialog read.
  - `0x0054b540` scalar/vector deleting destructor clear.
- PowerDialogPane vtable base `0x00622158` is referenced by `0x00549c7a`, `0x0054a480`, and `0x0054b526`.
- PowerDialogPane vtable base `0x006221b8` is referenced by `0x00549c80`, `0x0054a486`, and `0x0054b52c`.
- PowerDialogPane vtable base `0x006221e8` is referenced by `0x00549c8a`, `0x0054a490`, and `0x0054b536`.

The wrapper at `0x00513b50` decompiles to:

```cpp
char __stdcall wrapper(int packet)
{
    int pane = sub_4F4AA0(740);
    if (pane)
        sub_549C20(pane, packet);
    return 1;
}
```

`0x2e4` was checked with `int_convert.py` as decimal `740`. Because this helper has no incoming xrefs and no recovered source name, support docs should describe it as an unreferenced PowerDialogPane allocation/factory wrapper, not as MapPane-owned code and not as a required formal constructor source call.

## Constructor Behavior Resolved By MCP

`decompile 0x00549c20` resolves the constructor as `int __thiscall sub_549C20(int this, int packet)` at the binary level. The accepted first-draft formal source-facing signature is `PowerDialogPane::PowerDialogPane(const unsigned char *packet)`, inferred from the raw packet-pointer boundary, direct caller/wrapper argument shape, byte-address packet-reader helper use, and current MCP evidence; a separate packet-reader class is not evidenced at this constructor boundary.

Constructor phases:

1. Calls the `DialogPane` base constructor with title `L"Power"`, `-1`, and enabled/visible flag `1`.
2. Installs three PowerDialogPane vtable pointers at `0x00549c7a`, `0x00549c80`, and `0x00549c8a`.
3. Reads `g_pConfig` (`dword_67A7C8`) for four power threshold defaults.
4. Creates seven image button/header controls using `ImageButtonControlPane` and `DialogPane::AddControl`:
   - rect `(47,307,110,331)`, image/control resource id `43`.
   - rect `(120,307,183,331)`, id `38`.
   - rect `(193,307,256,331)`, id `39`.
   - rect `(266,307,329,331)`, id `40`.
   - rect `(339,307,402,331)`, id `41`.
   - rect `(412,307,475,331)`, id `42`.
   - rect `(485,307,548,331)`, id `30`.
5. Creates four embedded private PowerListPane list controls in scroll wrappers:
   - x positions `61`, `171`, `281`, `391`.
   - rects `(x,99,x+109,219)`.
   - each underlying list is constructed with item size `528`, list width `100`, list height `96`, row height `12`, and enabled flags matching decompiler args `0`, `1`, `1`.
   - each private PowerListPane installs vtables at offsets `+0`, `+160`, and `+164` inside the 332-byte list object.
6. Encodes threshold defaults:
   - `this+0x26c` / decimal 620 = `8 * *(int16_t *)(g_pConfig+0x28de94) + 52`.
   - `this+0x270` = `8 * *(int16_t *)(g_pConfig+0x28de96) + 52`.
   - `this+0x274` = `8 * *(int16_t *)(g_pConfig+0x28de98) + 52`.
   - `this+0x278` = `8 * *(int16_t *)(g_pConfig+0x28de9a) + 52`.
   - `this+0x27c` = `52`, the fallback/default row marker.
7. Creates five numeric `TextEditControlPane` controls at y positions `221`, `236`, `251`, `266`, and `281` with rects `(36,y,61,y+14)`, text color `143`, and initial text `(encodedValue-52)/8`.
8. Reads packet entry count as `ReadUInt16BE(packet + 2)` and starts row parsing at `packet + 4`.
9. Clears the 25-int grid at `this+0x280` / decimal 640.
10. For each packet row:
    - reads entry id with `ReadUInt32BE`.
    - reads a one-byte list column.
    - reads amount with `ReadUInt32BE`.
    - reads one threshold byte and stores display color as `8 * threshold + 52`.
    - reads one byte label length, copies that many bytes into an ANSI scratch buffer, terminates it, and converts to a 256-wide-char label with `MultiByteToWideChar`.
    - locates list control `listColumn + 6`; packet values `1..4` therefore map to control ids `7..10`.
    - appends a 528-byte row record to that list.
    - finds the matching encoded threshold row among the five row markers and falls back to row `4` if not matched.
    - accumulates amount into `m_powerGrid[row][listColumn-1]`.
11. Computes row totals into the fifth grid column:
    - `+0x290` = `+0x280 + +0x284 + +0x288 + +0x28c`.
    - `+0x2a4` = `+0x294 + +0x298 + +0x29c + +0x2a0`.
    - `+0x2b8` = `+0x2a8 + +0x2ac + +0x2b0 + +0x2b4`.
    - `+0x2cc` = `+0x2bc + +0x2c0 + +0x2c4 + +0x2c8`.
    - `+0x2e0` = `+0x2d0 + +0x2d4 + +0x2d8 + +0x2dc`.
12. Sorts the four list controls `7..10` with compare function `0x0054af30`.
13. Sets hover, focused, and pending controls to control id `6`.
14. Initializes and opens the dialog:
    - rect `(20,20,626,391)`.
    - `Pane::SetMode(1)`.
    - `DialogPane::OnCreate(&rect, 0, 0, dword_69B36C)`.
    - `DialogPane::OnShow(0, dword_67A740)`.
    - `DialogPane::SlideOpenVertical()`.
15. Publishes `g_pPowerDialog = this` at `0x0054a44c` and returns `this`.

## Dependent Method Evidence

These dependent methods are required support context for the constructor but should not be folded into [UID:0001F5].

`0x0054a4c0` `PowerDialogPane::OnDialogAction`:

- Action `0` reads controls `11..14`, decodes `_wtoi(text)`, stores encoded display values back into `this+0x26c..0x278`, and writes four config shorts at decimal `2678420` / `0x28de94`, then `0x28de96`, `0x28de98`, and `0x28de9a`.
- Action `0` sends opcode `0x4c`, subcommand `1`, count `4`, four thresholds, and a zero terminator through `g_packetSender`.
- Actions `1..5` call the apply helper at `0x0054a7f0`.
- Action `6` closes the dialog with slide-close and cleanup.

`0x0054a6f0` `PowerDialogPane::OnPaint`:

- Loads/draws `POWER.EPF`.
- Uses text color `143`.
- Draws the 5x5 grid values from `this+0x280` with x coordinate `62 + 110 * column` and y coordinate `234 + 15 * row`.

`0x0054a7f0` apply helper:

- Scans list controls `7..10` for a selected row.
- Retrieves the selected 528-byte row record.
- Writes selected encoded value into the row record display-color field at offset `0x20c`.
- Sends opcode `0x4c`, subcommand `2`, count `4`, four thresholds, selected entry id, selected slot value `(displayColor-52)/8`, and terminator zero.

`0x0054b000` `PowerListPane::OnMouseEvent`:

- Reads `g_pPowerDialog`.
- Uses the owner dialog to clear sibling selections in controls `7..10` before selecting the current list row.
- Uses drag/capture byte at `this+0x149` / decimal 329.
- Invalidates/repaints its own rect on exit.

## Inferred Source Shape For Formal C++

The following names should be treated as implementation-ready first-draft names. They are inferred from binary behavior, support docs, and local generated-code style, not original-symbol proof. That is acceptable for first-draft formal C++ under the active B-agent standard.

| Storage | Evidence | Recommended support wording |
| --- | --- | --- |
| `PowerDialogPane +0x26c..+0x27c` | constructor initializes five encoded row values; OnDialogAction updates first four; apply helper reads them. | `m_encodedPowerValues[5]`, where first four are user thresholds and fifth is fallback/default `52`. |
| `PowerDialogPane +0x280..+0x2e0` | constructor clears/populates 25 ints; OnPaint draws them. | `m_powerGrid[5][5]`, four list columns plus row total. |
| `g_pConfig +0x28de94/+0x28de96/+0x28de98/+0x28de9a` | constructor reads shorts; OnDialogAction writes shorts. | `m_powerDialogThresholdDefaults[4]`; support docs should record the raw offset family alongside this inferred member-array name. |
| 528-byte list row record `+0x000` | `ReadUInt32BE`, apply packet sends it. | `entryId`. |
| 528-byte list row record `+0x004` | packet one-byte list column stored in a padded slot; constructor uses `listColumn+6`. | `listColumn` with three explicit padding bytes in the first-draft struct. |
| 528-byte list row record `+0x008` | `ReadUInt32BE`, grid accumulation amount. | `amount`. |
| 528-byte list row record `+0x00c..+0x20b` | `MultiByteToWideChar` output buffer, 256 WCHARs. | `label[256]`. |
| 528-byte list row record `+0x20c` | constructor writes encoded threshold color; apply helper overwrites it. | `displayColor`. |
| `PowerListPane +0x149` | OnMouseEvent drag/capture state. | `m_isDraggingSelection` or drag/capture byte, if [UID:0000AQ] needs field wording. |

Constructor source-facing decisions:

- Constructor signature: `PowerDialogPane::PowerDialogPane(const unsigned char *packet)`. The direct caller and wrapper pass a raw packet pointer; the packet reader helpers operate on byte addresses. A separate packet-reader class is not evidenced at this boundary.
- Config member: `g_pConfig->m_powerDialogThresholdDefaults[index]`. The support doc must also retain raw offsets `+0x28de94/+0x28de96/+0x28de98/+0x28de9a`.
- UI helper aliases: `MakeRect`, `AddControl`, `GetControl`, `SetHoverControl`, `SetFocusedControl`, `SetPendingControl`, `SetMode`, `OnCreate`, `OnShow`, and `SlideOpenVertical` match existing generated/UI-core style. The final text edit visibility call should be `SetControlVisible(true)`, matching the virtual `+0x50` call to the base `ControlPane` set-visible helper.
- Scroll wrapper helper: the formal block uses `ScrollableControlPane::GetScrollablePane()` to express the documented embedded child pointer at `+0x108`. This is an inferred accessor name over the support-documented wrapper/child relationship.
- List helper names: `PowerListPane::AddEntry` and `PowerListPane::Sort` are inferred source-facing wrappers over the documented list append/sort helpers at `0x004f3c50` and `0x004f3540`.

## Exact Formal RECONSTRUCTION_CPP CODE

Insert this exact first-draft C++ between the existing [UID:0001F5] `RECONSTRUCTION_CPP CODE:BEGIN` and `END` lines. Leave the inline `RECONSTRUCTION_CPP CODE:[[[]]]` value unchanged.

```cpp
namespace {

constexpr int kPowerDialogControlFocusId = 6;
constexpr int kPowerFirstListControlId = 7;
constexpr int kPowerListCount = 4;
constexpr int kPowerThresholdCount = 4;
constexpr int kPowerRowCount = 5;
constexpr int kPowerGridColumnCount = 5;
constexpr int kPowerFallbackRow = 4;
constexpr int kPowerEncodedBase = 52;
constexpr int kPowerEncodedScale = 8;
constexpr int kPowerEntryRecordSize = 528;
constexpr int kPowerListWidth = 100;
constexpr int kPowerListHeight = 96;
constexpr int kPowerListRowHeight = 12;
constexpr int kPowerTextColor = 143;

struct PowerButtonLayout {
    int left;
    int top;
    int right;
    int bottom;
    int imageId;
};

const PowerButtonLayout kPowerButtonLayout[] = {
    {47, 307, 110, 331, 43},
    {120, 307, 183, 331, 38},
    {193, 307, 256, 331, 39},
    {266, 307, 329, 331, 40},
    {339, 307, 402, 331, 41},
    {412, 307, 475, 331, 42},
    {485, 307, 548, 331, 30},
};

struct PowerEntryRecord {
    unsigned int entryId;
    unsigned char listColumn;
    unsigned char reserved0[3];
    unsigned int amount;
    wchar_t label[256];
    int displayColor;
};

int EncodePowerThreshold(int value)
{
    return value * kPowerEncodedScale + kPowerEncodedBase;
}

int DecodePowerThreshold(int encodedValue)
{
    return (encodedValue - kPowerEncodedBase) / kPowerEncodedScale;
}

PowerListPane *GetPowerListPane(PowerDialogPane *dialog, int controlId)
{
    ScrollableControlPane *scrollPane =
        static_cast<ScrollableControlPane *>(dialog->GetControl(controlId));
    return static_cast<PowerListPane *>(scrollPane->GetScrollablePane());
}

void AddPowerButton(PowerDialogPane *dialog, const PowerButtonLayout &layout)
{
    RectBounds bounds = MakeRect(layout.left,
                                 layout.top,
                                 layout.right,
                                 layout.bottom);
    dialog->AddControl(new ImageButtonControlPane(layout.imageId, bounds));
}

} // namespace

PowerDialogPane::PowerDialogPane(const unsigned char *packet)
    : DialogPane(L"Power", -1, 1)
{
    for (int i = 0; i < sizeof(kPowerButtonLayout) / sizeof(kPowerButtonLayout[0]); ++i) {
        AddPowerButton(this, kPowerButtonLayout[i]);
    }

    for (int left = 61; left < 501; left += 110) {
        PowerListPane *listPane =
            new PowerListPane(kPowerEntryRecordSize,
                              kPowerListWidth,
                              kPowerListHeight,
                              kPowerListRowHeight,
                              false,
                              true,
                              true);
        RectBounds listBounds = MakeRect(left, 99, left + 109, 219);
        AddControl(new ScrollableControlPane(listBounds, listPane, 0, 0, 0));
    }

    for (int i = 0; i < kPowerThresholdCount; ++i) {
        m_encodedPowerValues[i] =
            EncodePowerThreshold(g_pConfig->m_powerDialogThresholdDefaults[i]);
    }
    m_encodedPowerValues[kPowerFallbackRow] = kPowerEncodedBase;

    TextEditControlPane *lastThresholdEdit = NULL;
    for (int row = 0; row < kPowerRowCount; ++row) {
        wchar_t thresholdText[10];
        swprintf(thresholdText,
                 L"%d",
                 DecodePowerThreshold(m_encodedPowerValues[row]));

        const int top = 221 + row * 15;
        RectBounds editBounds = MakeRect(36, top, 61, top + 14);
        lastThresholdEdit =
            new TextEditControlPane(thresholdText,
                                    true,
                                    kPowerTextColor,
                                    0,
                                    &editBounds,
                                    false,
                                    false,
                                    false,
                                    false,
                                    1.0f,
                                    0);
        AddControl(lastThresholdEdit);
    }

    if (lastThresholdEdit != NULL)
        lastThresholdEdit->SetControlVisible(true);

    memset(m_powerGrid, 0, sizeof(m_powerGrid));

    unsigned int packetOffset = 4;
    const unsigned int entryCount = ReadUInt16BE(packet + 2);
    for (unsigned int i = 0; i < entryCount; ++i) {
        PowerEntryRecord record;
        memset(&record, 0, sizeof(record));

        record.entryId = ReadUInt32BE(packet + packetOffset);
        packetOffset += 4;

        record.listColumn = packet[packetOffset++];

        record.amount = ReadUInt32BE(packet + packetOffset);
        packetOffset += 4;

        const unsigned char thresholdValue = packet[packetOffset++];
        record.displayColor = EncodePowerThreshold(thresholdValue);

        const unsigned char labelLength = packet[packetOffset++];
        char labelText[256];
        memcpy(labelText, packet + packetOffset, labelLength);
        labelText[labelLength] = 0;
        packetOffset += labelLength;

        const int converted =
            MultiByteToWideChar(0,
                                0,
                                labelText,
                                labelLength,
                                record.label,
                                256);
        record.label[converted] = 0;

        PowerListPane *listPane =
            GetPowerListPane(this, record.listColumn + kPowerDialogControlFocusId);
        listPane->AddEntry(&record);

        int rowIndex = kPowerFallbackRow;
        for (int row = 0; row < kPowerRowCount; ++row) {
            if (thresholdValue == DecodePowerThreshold(m_encodedPowerValues[row])) {
                rowIndex = row;
                break;
            }
        }

        m_powerGrid[rowIndex][record.listColumn - 1] += record.amount;
    }

    for (int row = 0; row < kPowerRowCount; ++row) {
        m_powerGrid[row][4] = m_powerGrid[row][0]
                            + m_powerGrid[row][1]
                            + m_powerGrid[row][2]
                            + m_powerGrid[row][3];
    }

    for (int i = 0; i < kPowerListCount; ++i) {
        PowerListPane *listPane =
            GetPowerListPane(this, kPowerFirstListControlId + i);
        listPane->Sort(ComparePowerEntries);
    }

    SetHoverControl(kPowerDialogControlFocusId);
    SetFocusedControl(kPowerDialogControlFocusId);
    SetPendingControl(kPowerDialogControlFocusId);

    RectBounds dialogBounds = MakeRect(20, 20, 626, 391);
    SetMode(1);
    OnCreate(&dialogBounds, 0, 0, g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pBackPane);
    SlideOpenVertical();

    g_pPowerDialog = this;
}
```

Notes for implementation:

- The block intentionally uses inferred source-facing helper names, not raw addresses. Support docs should record the binary facts behind those names.
- `GetScrollablePane()`, `PowerListPane::AddEntry`, `PowerListPane::Sort`, and `ComparePowerEntries` are best-supported first-draft names for the documented wrapper/list append/sort behavior and are part of the exact insertion text for this report.
- The code preserves the packet contract: entry count at `packet+2`, row payload at `packet+4`, packet list columns `1..4` mapping to dialog controls `7..10`, grid fallback row `4`, row totals in column `4`, and singleton publication after `SlideOpenVertical`.

## Required Support-Doc Changes

Implementation should lease and edit only the files it changes immediately. No report-only edit is authorized here.

1. [UID:0001F5] `by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md`
   - Raise to `COMPLETION:89`, `CONFIDENCE:90`.
   - Keep owner/emitter [UID:0000AP].
   - Insert the exact formal first-draft constructor C++ block above into the target's formal `RECONSTRUCTION_CPP CODE` block.
   - Replace the stale "blank C++ rationale" with the current source-shape decisions and note that the previous blank/no-code disposition was supervisor-rejected.
   - Add current MCP session evidence: session `b003_powerdialog_0001f5_20260628`, function size `0x852` / 2130, caller refs `0x0050876a` and `0x00513b93`, wrapper zero-inxref status, singleton refs, vtable refs, and generated marker state.
   - Add constructor phase map with the 15 phases listed in this report.
   - Add field/record map for `+0x26c`, `+0x280`, config offsets, and the 528-byte list row.
   - Record the inferred helper/name decisions used by the formal block: `PowerDialogPane::PowerDialogPane(const unsigned char *packet)`, `PowerEntryRecord`, `m_powerDialogThresholdDefaults`, `GetScrollablePane`, `AddEntry`, `Sort`, and `ComparePowerEntries`.

2. [UID:0000AP] `by-class/PowerDialogPane.md`
   - Update the constructor method row for [UID:0001F5] from "current blank due unresolved details" to "formal first-draft constructor C++ now supplied by [UID:0001F5]".
   - Add or refine layout entries for `m_encodedPowerValues[5]` at `+0x26c..+0x27c` and `m_powerGrid[5][5]` at `+0x280..+0x2e0`.
   - Record that OnDialogAction persists only the first four encoded threshold values to `g_pConfig+0x28de94..+0x28de9a`; the fifth row is fallback `52`.
   - Record the inferred source signature `PowerDialogPane(const unsigned char *packet)` and the `PowerEntryRecord` layout as constructor-owned support.
   - Keep [UID:0001F7] singleton helpers as separate emitted child C++.

3. [UID:0000MO] `by-file/PowerDialogPane.md`
   - Update file-level proposed contents to say [UID:0001F5] is the real PowerDialogPane constructor and now carries formal first-draft constructor C++.
   - Note that generated `PowerDialogPane.cpp` should no longer retain the [UID:0001F5] empty marker after implementation and generated refresh.
   - Keep source route `NexusTK/ui/dialogs/PowerDialogPane.cpp`.

4. [UID:0001F6] `by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md`
   - Update the aggregate constructor row with the current [UID:0001F5] evidence and formal-code disposition.
   - Preserve aggregate blank C++; the exact child [UID:0001F5] owns constructor emitted C++ and [UID:0001F7] owns singleton emitted C++.
   - Add the wrapper at `0x00513b50` as unreferenced source-family evidence, not as an aggregate-owned live entry.

5. [UID:0000AQ] `by-class/PowerListPane.md`
   - Keep the correction that `0x00549c20` is not PowerListPane-owned.
   - Update the row-record section with the 528-byte layout: `entryId +0x0`, padded `listColumn +0x4`, `amount +0x8`, `label[256] +0x0c`, `displayColor +0x20c`.
   - Mention that constructor-created packet values `1..4` map to dialog controls `7..10` through `listColumn + 6`.
   - Link `OnMouseEvent` sibling-selection clearing through `g_pPowerDialog` to this constructor-created control-id layout.

6. [UID for `g_pConfig`] `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
   - Refine the existing `+0x28de94..+0x28de9a` row from a generic "Power-dialog threshold defaults" cluster to four 16-bit threshold defaults used by PowerDialogPane, with first-draft member spelling `m_powerDialogThresholdDefaults[4]`.
   - Add read proof from [UID:0001F5] constructor and write proof from `0x0054a4c0` action `0`.
   - Do not create a separate `g_powerThresholdConfig` global; this is a `g_pConfig` field cluster.

7. [UID for MapPane packet dispatcher] `by-memory/0x00507c90-0x00508f60.MapPanePacketDispatcher.md`
   - Add a concise support row for packet case/opcode `0x46`: it reaches `0x00549c20` at `0x0050876a` and constructs/publishes `PowerDialogPane`.
   - Keep ownership with PowerDialogPane, not MapPane. This dispatcher page is caller evidence only.

8. Optional no-edit proofs to mention in [UID:0001F5] instead of editing separate files:
   - `by-global/g_pPowerDialog.md` and `by-memory/0x0069ba34-0x0069ba38.g_pPowerDialog.md` already contain the exact five refs and do not need mandatory edits.
   - `by-memory/0x00622154-0x006221f0.PowerDialogPaneVtableData.md` already records constructor/helper/destructor vtable stores and does not need mandatory edits.
   - `by-memory/0x006222b4-0x006222d4.PowerDialogResourceStrings.md` already records `L"Power"` and `POWER.EPF` resource string ownership and does not need mandatory edits.

## Rejected Alternatives And Stale Assumptions

| Alternative | Rejection |
| --- | --- |
| Preserve [UID:0001F5] as `EMITTER_UIDS:0000AP` with blank formal C++ | Rejected by supervisor and by the empty-emitter assignment. The revised report supplies formal first-draft constructor C++ instead. |
| Use a nonblank comment-only no-code marker | Rejected because the constructor is source-authored, behaviorally solved, and has a valid owner/emitter route. A comment marker would hide reconstructable source rather than reconstruct it. |
| Remove or blank `EMITTER_UIDS` | Rejected because [UID:0000AP] remains the correct owner/emitter and the target is code-ready after current-scope inference. |
| Keep blank solely because of the obsolete 95/95 gate | Rejected. The active gate is [UID reconstructable] + nonblank emitter + combined score above 85; the blocker is source-quality readiness, not score policy. |
| Assign the constructor to PowerListPane | Rejected by vtable stores, singleton publish, DialogPane base constructor, and dependent method ownership. |
| Assign the constructor to MapPane | Rejected. MapPane has one caller site for packet case `0x46`; the body installs PowerDialogPane vtables and belongs to `PowerDialogPane.cpp`. |
| Treat `0x00513b50` as the live source factory route | Rejected for formal code on [UID:0001F5]. It calls the constructor after allocating 740 bytes, but has zero incoming xrefs and an IDA compiler-polluted name. The constructor block does not need the wrapper. |
| Create a separate `g_powerThresholdConfig` global | Rejected. The thresholds are four shorts under `g_pConfig`, with reads in the constructor and writes in OnDialogAction. |
| Fold [UID:0001F7] singleton helpers back into the constructor page | Rejected. [UID:0001F7] already has formal destructor/getter C++ and a clean child range. |

## Validator And Refresh Expectations

No validators were run during this report-only pass because no by-* files were edited.

Implementation callback requirements:

- Lease each by-* file immediately before editing and release leases immediately after the edit/validator batch.
- Run scoped validators from `source-3/project-documentation` on every changed by-* file. The [UID:0001F5] target validator should use `--wait-generated` if implementation needs to prove generated `PowerDialogPane.cpp` no longer contains the [UID:0001F5] empty marker before returning.
- Do not edit generated files, coverage reports, manual coverage files, tool files, IDA files, or MCP process state.
- Generated refresh expectation: after [UID:0001F5] formal C++ is inserted and validators regenerate `auto-generated/NexusTK/ui/dialogs/PowerDialogPane.cpp`, [UID:0001F5] should emit constructor code and should not remain an Empty Emitter Marker. Other unrelated empty markers in that file can remain.

## Implementation Checklist

- [x] Lease [UID:0001F5] target immediately before editing. Proof: B003 leased `by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md` plus the six callback-listed support by-* files at `2026-06-28T18:05:16Z` for the immediate edit/validator batch.
- [x] Update [UID:0001F5] metadata to `89/90`, preserve owner/emitter [UID:0000AP], and insert the exact formal first-draft constructor C++ block from this report. Proof: target header now reads `COMPLETION:89`, `CONFIDENCE:90`, owner/emitter [UID:0000AP], and the formal block comparison against this report returned `BLOCK_MATCH lines=199`.
- [x] Update [UID:0001F5] with MCP session, function/caller/wrapper/singleton/vtable evidence and the 15-phase constructor map. Proof: target records report session `b003_powerdialog_0001f5_20260628`, implementation sanity session `b003_powerdialog_impl_0001f5_20260628`, size `0x852`, callers `0x0050876a`/`0x00513b93`, wrapper `0x00513b50`, singleton/vtable refs, and expanded constructor phase table.
- [x] Update [UID:0001F5] with inferred source-shape decisions for `PowerDialogPane::PowerDialogPane(const unsigned char *packet)`, `PowerEntryRecord`, `m_powerDialogThresholdDefaults`, `GetScrollablePane`, `AddEntry`, `Sort`, and `ComparePowerEntries`. Proof: target `B003 Source-Shape Resolution` table documents these names as accepted first-draft inferred source shape and notes they are not separate recovered binary starts.
- [x] Lease and update [UID:0000AP] `by-class/PowerDialogPane.md` with constructor formal-code disposition, layout fields, config persistence, row-record layout, and current emitted-helper state. Proof: class page now points [UID:0001F5] to formal first-draft constructor C++, documents `m_encodedPowerValues[5]`, `m_powerGrid[5][5]`, `m_powerDialogThresholdDefaults[4]`, `PowerEntryRecord`, and keeps [UID:0001F7] as the separate destructor/getter emitter.
- [x] Lease and update [UID:0000MO] `by-file/PowerDialogPane.md` with source route, expected generated constructor emission, and removal of the [UID:0001F5] empty-marker expectation. Proof: file page keeps `NexusTK/ui/dialogs/`, says [UID:0001F5] emits constructor C++ into `PowerDialogPane.cpp`, and says generated output should no longer retain the [UID:0001F5] empty marker.
- [x] Lease and update [UID:0001F6] aggregate with [UID:0001F5] current evidence and formal-code disposition while preserving aggregate blank C++. Proof: aggregate page marks [UID:0001F5] as exact child constructor emitter, records wrapper evidence, and explicitly keeps aggregate C++ blank to avoid duplicating exact-child output.
- [x] Lease and update [UID:0000AQ] `by-class/PowerListPane.md` with row-record layout and control-id mapping. Proof: PowerListPane page now lists the 528-byte row offsets/padding and documents `listColumn + 6` mapping to controls `7..10` and sibling selection through `g_pPowerDialog`.
- [x] Lease and update `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md` with `m_powerDialogThresholdDefaults[4]`, raw offsets `+0x28de94..+0x28de9a`, and read/write proof. Proof: config page field-cluster row now records the four 16-bit defaults, constructor read proof, `OnDialogAction` action-0 write proof, and rejection of a separate `g_powerThresholdConfig` global.
- [x] Lease and update `by-memory/0x00507c90-0x00508f60.MapPanePacketDispatcher.md` with packet case `0x46` caller evidence and PowerDialogPane ownership caveat. Proof: dispatcher page now has a consumer row for [UID:0001F5], caller site `0x0050876a`, and explicit ownership caveat keeping the constructor with PowerDialogPane.
- [x] Record no-edit proof for already-current `g_pPowerDialog`, vtable-data, and resource-string docs, unless implementation finds stale text in those files while editing. Proof: target notes `by-global/g_pPowerDialog.md` and `by-memory/0x0069ba34-0x0069ba38.g_pPowerDialog.md` already record the exact five singleton refs; `by-memory/0x00622154-0x006221f0.PowerDialogPaneVtableData.md` already records the three vtable ref sets; `by-memory/0x006222b4-0x006222d4.PowerDialogResourceStrings.md` already records `Power` and `POWER.EPF`; no stale text was found, so no edits were made to those files.
- [x] Run scoped validators from `source-3/project-documentation` for every changed by-* file and record command ids, timestamps, and ok counts; use `--wait-generated` on the [UID:0001F5] target validator if generated proof is needed before return. Proof: validators all exited `0` with `ok:1`: target `000000005052` at `2026-06-28T14:09:39-04:00` with `--wait-generated`; class `000000005053` at `14:10:18`; file `000000005054` at `14:10:20`; aggregate `000000005055` at `14:10:21`; PowerListPane `000000005056` at `14:10:28`; g_pConfig `000000005057` at `14:10:35`; MapPane dispatcher `000000005058` at `14:10:37`.
- [x] Release all leases immediately after the edit/validator batch. Proof: B003 refreshed the six support leases after target validation, released them after validation/generation checks, and `current_leases.md` showed no active B003 leases; the target lease had already expired before cleanup and `unlease` returned `Rejected[No active lease]` for that path.
- [x] Report generated-refresh state explicitly: no generated edit by hand; after refresh [UID:0001F5] should emit constructor code and no longer be an empty marker. Proof: generated `auto-generated/NexusTK/ui/dialogs/PowerDialogPane.cpp` header is `validator-command-id: 000000005056`, `validator-refreshed-at: 2026-06-28T14:10:28-04:00`; it contains [UID:0001F5] constructor code and `PowerDialogPane::PowerDialogPane(const unsigned char *packet)`, and `rg` found no [UID:0001F5] Empty Emitter Marker. Other broad/class/global empty markers remain unrelated.
- [x] Leave this report unarchived; supervisor or implementation callback owner decides archival after acceptance. Proof: report remains in `tools/leaser/Agents/Agent-B003/research/`; no `execute_report` or archive/move command was run.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0001F5-PowerDialogPaneConstructor-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0001F5-PowerDialogPaneConstructor-empty-emitter-source-quality.md","timestamp":"2026-06-28T14:18:45","uid":"0001F5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
