*** UID:0000AP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class PowerDialogPane;
extern PowerDialogPane *g_pPowerDialog;

class PowerDialogPane : public DialogPane
{
public:
    explicit PowerDialogPane(const unsigned char *packet);
    virtual ~PowerDialogPane();

    static PowerDialogPane *GetSingleton();

    virtual void OnControlCommand(int actionId, int actionParam);
    virtual bool HandlePacketEvent(Event *event);
    virtual void OnPaint();

private:
    void ApplyPowerSlot(int slot);
    void RefreshPowerEntriesFromPacket(const unsigned char *packet);

    int m_encodedPowerValues[5];
    int m_powerGrid[5][5];
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PowerDialogPane

## Status

- Current state: `92/94`, reconstructable true, owner/emitter UID0000MO, with compile-visible `g_pPowerDialog` declaration, complete `PowerDialogPane` declaration, exact `0x2e4` layout, complete virtual/member inventory, and exact children inserted after the class closing brace through `[[CHILDREN]]`.
- Confidence is very strong for dialog ownership, singleton declaration/definition route, vtable/string ownership, parent source routing, constructor/destructor/singleton emission, complete derived tail, `OnControlCommand`/`HandlePacketEvent`/`OnPaint` virtual integration, and private apply/refresh helpers. Exact original physical header and private access spelling remain inferred confidence caps only.
- Likely source file: [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md)
- Address range: [UID:0001F6][0x00549c20-0x0054b5d5.PowerDialogPane](by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md)
- Historical generated-output caveat: older recovered output split dialog/list material and lacked a compile-visible global declaration. The current accepted class union fixes constructor/list ownership and now declares the singleton before all method children; IDA-backed ownership notes remain authoritative.

## Class Purpose

`PowerDialogPane` is the packet-opened power or ability configuration dialog. It constructs the `Power` dialog, owns the `POWER.EPF` background render path, displays a 5x5 power value grid, edits four configured threshold values, and sends opcode `0x4c` responses for apply-all and selected-slot actions.

The dialog contains four embedded [UID:0000AQ][PowerListPane](by-class/PowerListPane.md) controls. Those list controls render and select the power entries, but the large setup routine at `0x00549c20` is the dialog constructor/initializer rather than a list-pane method: it calls the [UID:00003T][DialogPane](by-class/DialogPane.md) constructor, installs `PowerDialogPane` vtables, creates header buttons and list controls, populates row totals from packet data, attaches the dialog to the root pane, and stores the singleton pointer.

## Singleton Declaration And One-Definition Route

- The formal block declares `class PowerDialogPane;` followed by `extern PowerDialogPane *g_pPowerDialog;` before the complete class. This makes constructor, destructor/getter, and private PowerListPane consumers compile-visible without moving or duplicating any method body.
- Semantic [UID:0000S0][g_pPowerDialog](by-global/g_pPowerDialog.md) owns the sole `PowerDialogPane *g_pPowerDialog = NULL;` definition through [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md) at position `160`. Physical [UID:0001PZ][0x0069ba34-0x0069ba38.g_pPowerDialog](by-memory/0x0069ba34-0x0069ba38.g_pPowerDialog.md) is loader-zero backing only and remains blank/non-emitting.
- The class declaration remains behavior-neutral and complete: direct base `DialogPane`, constructor/destructor/static getter, three accepted virtuals, two private helpers, five encoded values, and the 5x5 grid are unchanged. The closing brace remains before `[[CHILDREN]]`; no child definition is nested into the class.
- No Singleton-template base, class static member, raw address declaration, second global, vptr field, explicit ABI table, scalar-delete flag, or base-teardown call is source-supported.

## Method Notes

| Method or role | Address | Notes |
| --- | --- | --- |
| [UID:0001F5][0x00549c20-0x0054a472.PowerDialogPaneConstructor](by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md) | `0x00549c20-0x0054a472` | Currently named `PowerListPane::InitializeFromData` in generated output, but builds the full dialog from server packet case `0x46`, writes `PowerDialogPane` vtables, and now supplies formal first-draft constructor C++ as `PowerDialogPane::PowerDialogPane(const unsigned char *packet)`. |
| [UID:0001F7][0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers](by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md) | `0x0054a480-0x0054a4b6` | Formal exact-child C++ now lives here: `PowerDialogPane::~PowerDialogPane()` clears [UID:0000S0][g_pPowerDialog](by-global/g_pPowerDialog.md), and inferred static `PowerDialogPane::GetSingleton()` returns it. Current IDA has no direct callers/xrefs or absolute helper-start pointer hits, which caps confidence but no longer blocks the child body. |
| [UID:0004AX][0x0054a4c0-0x0054a69d.PowerDialogPaneOnControlCommand](by-memory/0x0054a4c0-0x0054a69d.PowerDialogPaneOnControlCommand.md) | `0x0054a4c0-0x0054a69d` | `92/94` class-owned emitting child for `void PowerDialogPane::OnControlCommand(int actionId, int actionParam)`, the exact inherited DialogPane primary slot `+0x48`: preserves the `retn 8` two-argument callback shape, ignores the second parameter, action `0` reads `TextEditControlPane` controls `11-14`, converts with `_wtol`, updates `m_encodedPowerValues[0..3]` and `g_pConfig->m_powerDialogThresholdDefaults[0..3]`, sends opcode `0x4c`, subcommand `1`, count `4`, and four decoded thresholds through `PacketBufferWriteUInt8`/`g_packetSender->QueueAndSendPacket`; actions `1-5` delegate to [UID:0004B0][0x0054a7f0-0x0054a954.PowerDialogPaneApplyPowerSlot](by-memory/0x0054a7f0-0x0054a954.PowerDialogPaneApplyPowerSlot.md); action `6` calls `SlideCloseVertical()` and `CloseDialog()`. |
| [UID:0004AY][0x0054a6c0-0x0054a6e6.PowerDialogPaneHandlePacketEvent](by-memory/0x0054a6c0-0x0054a6e6.PowerDialogPaneHandlePacketEvent.md) | `0x0054a6c0-0x0054a6e6` | `92/94` class-owned emitting `bool HandlePacketEvent(Event *event)` override at EventHandler secondary slot `+0x10`; reads Event packet data at `+0x0c`, rejects non-`0x46` packets, calls [UID:0004B3][0x0054ab90-0x0054aebb.PowerDialogPaneRefreshPowerEntriesFromPacket](by-memory/0x0054ab90-0x0054aebb.PowerDialogPaneRefreshPowerEntriesFromPacket.md) with the unchanged packet pointer, ignores its register residue, and returns handled true. The machine `this-0xa0` normalization is compiler-only. |
| [UID:0004AZ][0x0054a6f0-0x0054a7e9.PowerDialogPaneOnPaint](by-memory/0x0054a6f0-0x0054a7e9.PowerDialogPaneOnPaint.md) | `0x0054a6f0-0x0054a7e9` | `90/91` class-owned emitting child for `void PowerDialogPane::OnPaint()`: draws `POWER.EPF` through `g_pEPFLib` / resource-layout lookup and the Surface slot-2 `RenderTileFrame` route, sets text color `143` and inferred inherited `m_textDrawMode`, then renders all 25 `m_powerGrid[5][5]` values with `MoveTo` and `DrawWideText` at x `62 + column*110` and y `234 + row*15`. |
| [UID:0004B0][0x0054a7f0-0x0054a954.PowerDialogPaneApplyPowerSlot](by-memory/0x0054a7f0-0x0054a954.PowerDialogPaneApplyPowerSlot.md) | `0x0054a7f0-0x0054a954` | `90/91` class-owned emitting child for `void PowerDialogPane::ApplyPowerSlot(int slot)`: scans embedded list controls `7..10`, checks the selected index at `PowerListPane+0x134`, fetches the selected `PowerEntryRecord` through the ListPane row accessor, writes `m_encodedPowerValues[slot - 1]` to `displayColor` at `+0x20c`, and sends opcode `0x4c`, subcommand `2`, count `4`, four decoded thresholds, UInt32BE selected `entryId`, and the decoded selected threshold/color byte through `PacketBufferWriteUInt8`/`PacketBufferWriteUInt32BE`/`g_packetSender->QueueAndSendPacket`. |
| raw/no-route spans | [UID:0004B1][0x0054a960-0x0054aa96.PowerDialogPaneUnreferencedApplyAllThresholdsRaw](by-memory/0x0054a960-0x0054aa96.PowerDialogPaneUnreferencedApplyAllThresholdsRaw.md), [UID:0004B2][0x0054aaa0-0x0054ab87.PowerDialogPaneUnreferencedSelectedPowerSlotRaw](by-memory/0x0054aaa0-0x0054ab87.PowerDialogPaneUnreferencedSelectedPowerSlotRaw.md) | Reviewed non-reconstructable raw spans, not IDA functions and zero-xref; they duplicate the live apply-all and selected-slot packet-send behavior and do not emit source. |
| [UID:0004B3][0x0054ab90-0x0054aebb.PowerDialogPaneRefreshPowerEntriesFromPacket](by-memory/0x0054ab90-0x0054aebb.PowerDialogPaneRefreshPowerEntriesFromPacket.md) | `0x0054ab90-0x0054aebb` | `88/91` class-owned emitting child for `void PowerDialogPane::RefreshPowerEntriesFromPacket(const unsigned char *packet)`: MCP session `eb7ce28b` confirms exact size `0x32b`, sole caller `0x0054a6db` from the opcode `0x46` packet handler, packet pointer passed from handler context, list clears for controls `7..10`, row parse into `PowerEntryRecord`, label conversion, `m_encodedPowerValues` threshold matching, `m_powerGrid[5][5]` accumulation/totals, `ComparePowerEntries` sorting, and final inherited `InvalidateRect(&m_bounds)`. |
| [UID:0004B5][0x0054af30-0x0054afd5.PowerDialogPaneComparePowerEntries](by-memory/0x0054af30-0x0054afd5.PowerDialogPaneComparePowerEntries.md) | `0x0054af30-0x0054afd5` | `89/91` emitting real file-local compare callback through [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md), not a class method and not only constructor-local pseudo-helper text. Referenced by constructor and refresh body; sorts `PowerEntryRecord` rows by `g_pConfig->m_powerDialogThresholdDefaults[4]` bucket, then descending amount. |
| Dialog destructor and thunks | `0x0054b4f0-0x0054b57f` | Two compiler [UID:0001F8][0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks](by-memory/0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks.md) plus no-code compiler wrapper [UID:0004B9][0x0054b520-0x0054b57f.PowerDialogPaneScalarDeletingDestructor](by-memory/0x0054b520-0x0054b57f.PowerDialogPaneScalarDeletingDestructor.md). The source destructor body remains [UID:0001F7][0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers](by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md). |

## Layout Notes

- Imported Wave2 notes identify a 644-byte dialog struct.
- `m_encodedPowerValues[5]` occupies `+0x26c..+0x27c`; the first four entries are user/config thresholds encoded as `value * 8 + 52`, and the fifth entry is the fallback/default row marker `52`.
- `m_powerGrid[5][5]` occupies `+0x280..+0x2e0` and is drawn as a 5x5 value table in `OnPaint`; columns `0..3` correspond to the four embedded lists and column `4` stores row totals.
- The singleton semantic definition is [UID:0000S0][g_pPowerDialog](by-global/g_pPowerDialog.md), with physical backing at `0x0069ba34` documented by UID0001PZ. Historical generated `g_activePowerListPane` is the same storage misnamed from the older constructor owner and remains rejected.
- Threshold defaults come from `g_pConfig` / `dword_67A7C8` shorts at offsets `0x28de94`, `0x28de96`, `0x28de98`, and `0x28de9a`; generated `g_powerThresholdConfig` is not a separate power-owned global. The accepted first-draft member spelling for those four shorts is `m_powerDialogThresholdDefaults[4]`.
- `OnControlCommand` action `0` persists only the first four threshold rows back to `g_pConfig+0x28de94..+0x28de9a`; the fifth encoded row remains the local fallback marker `52`.

## Constructor Row Record

[UID:0001F5][0x00549c20-0x0054a472.PowerDialogPaneConstructor](by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md) now owns the formal first-draft source shape for the packet constructor. Its inferred source-local row type is `PowerEntryRecord`, a 528-byte record with `entryId` at `+0x000`, one-byte `listColumn` at `+0x004` followed by three padding bytes, `amount` at `+0x008`, `wchar_t label[256]` at `+0x00c..+0x20b`, and `displayColor` at `+0x20c`. Constructor packet values `listColumn == 1..4` map to dialog controls `7..10` via `listColumn + 6`.

The constructor formal block uses inferred source-local helpers/constants `GetScrollablePane`, `AddEntry`, `Sort`, and `ComparePowerEntries` to express documented wrapper/list append/sort behavior. Current B002 UID0001F6 split work refines that older wording: `GetScrollablePane`, `AddEntry`, and `Sort` remain accepted constructor source-shape helper names, while `ComparePowerEntries` is also a real file-local binary callback at [UID:0004B5][0x0054af30-0x0054afd5.PowerDialogPaneComparePowerEntries](by-memory/0x0054af30-0x0054afd5.PowerDialogPaneComparePowerEntries.md).

B012 UID0004B5 implementation resolves the old compare-helper blank-emitter state: `ComparePowerEntries` now emits formal file-local C++ through [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md). It is kept outside this class C++ because the function has no `this` receiver; the constructor child provides a source-visible prototype before calling `Sort(ComparePowerEntries)`.

## Evidence Notes

- IDA MCP confirms `0x00549c20` is a real `0x852`-byte function and is called from `MapPane::HandlePacket` at `0x0050876a`, where packet case `0x46` allocates `740` bytes and calls this initializer with the packet payload.
- 2026-05-26 IDA MCP recheck also reports a second caller at `0x00513b93` currently mislabeled `___std_parallel_algorithms_hw_threads@0_2`; keep that caller under review, but it does not change the constructor ownership.
- B003 session `b003_powerdialog_0001f5_20260628` resolves the second caller as an unreferenced wrapper at `0x00513b50` that allocates `0x2e4` / 740 bytes (Verified with int_convert.py), calls the constructor, returns `1`, and has zero inbound xrefs. It is source-family evidence only, not a live factory route or MapPane-owned body.
- B003 implementation sanity session `b003_powerdialog_impl_0001f5_20260628` opened the current IDA MCP database with `server_health` ok and reconfirmed `lookup_funcs 0x00549c20` as `sub_549C20`, size `0x852`.
- IDA MCP callees for `0x00549c20` include the `DialogPane` constructor, `ListPane` constructor at `0x004f3a50`, list append helper at `0x004f3c50`, list sort helper at `0x004f3540`, and `MultiByteToWideChar`.
- Constructor evidence records the function calling the `DialogPane` constructor and writing three `PowerDialogPane` vtables before creating controls.
- IDA MCP xrefs to `0x0069ba34` show the constructor writes the dialog pointer at `0x0054a44c`, the cleanup/destructor clears it at `0x0054a49a` and `0x0054b540`, and `PowerListPane::OnMouseEvent` reads it at `0x0054b010` only to coordinate sibling list controls.
- IDA MCP confirms `0x0054a480` and `0x0054a4b0` as real singleton destructor/getter functions. B007 session `80de0a67` resolves their source-facing roles as `PowerDialogPane::~PowerDialogPane()` and `PowerDialogPane::GetSingleton()`: `0x0054a480` restores three `PowerDialogPane` vtable views, clears `g_pPowerDialog`, and tails into base `DialogPane` cleanup; `0x0054a4b0` returns the singleton pointer. Direct `callers`, `xrefs_to`, and absolute helper-start pointer scans remain empty, so no-route is a confidence cap rather than a blank-C++ reason.
- Historical B010 UID0004AX work resolved the old blank-emitter blocker under the descriptive name `OnDialogAction`: MCP confirmed exact range `0x0054a4c0-0x0054a69d`, vtable data xref `0x006221a0`, `retn 8` inherited two-argument shape, action `0` control ids `11..14`, `_wtol` conversion, encoded threshold/config writes, packet `0x4c/1` length `7`, five `ApplyPowerSlot(1..5)` calls, and action `6` close route. Current primary-vtable comparison supersedes only that spelling with exact inherited `OnControlCommand(int,int)` at slot `+0x48`; every behavior/helper conclusion remains accepted. Raw `sub_` labels, `dword_67A7EC`, `g_powerThresholdConfig`, `CashShopRequest *`, `Thread *`, and `void *` sender aliases remain rejected.
- B010 UID0004AZ implementation resolves the old `OnPaint` blank-emitter blocker: MCP confirms exact range `0x0054a6f0-0x0054a7e9`, size `0xf9`, vtable xref `0x0062219c`, `POWER.EPF` xref `0x0054a71c`, `L"%d"` format xref `0x0054a785`, `g_pEPFLib` / `ResourceLayoutTable::LookupLayoutEntry`, Surface slot `0x0069b3e8` frame blit route, text color `143`, inherited draw-state byte `this+0x88`, grid base `this+0x280`, coordinate loops, `MoveTo`, and counted `DrawWideText`. Source-facing helper decisions are `EPFTileContext::Init`, `RenderTileFrame`, `SetTextColor`, inferred `m_textDrawMode`, `MoveTo`, and `DrawWideText`; the prior pending renderer/resource/text helper no-code rationale is superseded.
- B012 UID0004B0 implementation resolves the old `ApplyPowerSlot` blank-emitter blocker: MCP confirms exact range `0x0054a7f0-0x0054a954`, no function at `0x0054a954`, five UID0004AX caller xrefs for actions `1..5`, row access through `0x004f3dc0`, packet writers `0x00575380`/`0x005753f0`, sender `0x00574bb0`, selected-index state at `PowerListPane+0x134`, `PowerEntryRecord::entryId` at `+0x000`, and `displayColor` at `+0x20c`. Source-facing helper decisions are `GetSelectedIndex`, `GetItem`, `PacketBufferWriteUInt8`, `PacketBufferWriteUInt32BE`, `DecodePowerThreshold`, `g_packetSender`, and `QueueAndSendPacket`; rejected alternatives are standalone setter API, no-owner/non-emitting, generic list/scrollbar direct ownership, packet-helper ownership, and stronger semantic row-field naming without consumer evidence.
- IDA MCP confirms `0x0054b4f0`, `0x0054b4fb`, `0x0054b506`, and `0x0054b511` as four `0xb` adjustor thunks. These are now recorded in [UID:0000VN][-ignored](by-memory/-ignored.md).
- `OnControlCommand` and `ApplyPowerSlot` both send opcode `0x4c` through the packet writer/send helpers at `0x00575380` and `0x00574bb0`.
- IDA MCP reports `0x0054aec0` is not a function, so the disabled generated method there should not be used as class evidence.
- 2026-06-11 A002 Batch222 read-only-data pass confirms the class-owned `.rdata` pieces: [0x00622154-0x006221f0.PowerDialogPaneVtableData](by-memory/0x00622154-0x006221f0.PowerDialogPaneVtableData.md) covers the exact three-view `PowerDialogPane` RTTI/vtable island, and [0x006222b4-0x006222d4.PowerDialogResourceStrings](by-memory/0x006222b4-0x006222d4.PowerDialogResourceStrings.md) covers the `Power` title and `POWER.EPF` paint resource strings.

## Source Layout Decision

Move the full dialog constructor at `0x00549c20` into `PowerDialogPane`. Keep the embedded list class in the same likely original source module as a private/helper UI class. This matches the late-1999 through mid-2000s pattern already seen in other feature dialogs: a `DialogPane` subclass and its private row/list control class usually live in one `.cpp`/`.h` pair unless the control has broad reuse.

## Parent Attachment Decision

Attach this class to [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md). The file page is scored `89/85`, stages under `NexusTK/ui/dialogs/`, and explicitly groups the dialog, feature-private [UID:0000AQ][PowerListPane](by-class/PowerListPane.md), singleton helpers, corrected generated-owner split, and exact `.rdata` children in one source module.

The class formal block now contains the complete declaration and post-class `[[CHILDREN]]` insertion point. Exact by-memory children continue to own method definitions; the class block supplies the source-legal type, inheritance, virtual/member declarations, and exact derived fields without duplicating child bodies.

[UID:0001F6][0x00549c20-0x0054b5d5.PowerDialogPane](by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md) remains the reviewed non-emitting container for the wider source island. It does not emit broad source. Exact children [UID:0004AX][0x0054a4c0-0x0054a69d.PowerDialogPaneOnControlCommand](by-memory/0x0054a4c0-0x0054a69d.PowerDialogPaneOnControlCommand.md), [UID:0004AY][0x0054a6c0-0x0054a6e6.PowerDialogPaneHandlePacketEvent](by-memory/0x0054a6c0-0x0054a6e6.PowerDialogPaneHandlePacketEvent.md), [UID:0004AZ][0x0054a6f0-0x0054a7e9.PowerDialogPaneOnPaint](by-memory/0x0054a6f0-0x0054a7e9.PowerDialogPaneOnPaint.md), [UID:0004B0][0x0054a7f0-0x0054a954.PowerDialogPaneApplyPowerSlot](by-memory/0x0054a7f0-0x0054a954.PowerDialogPaneApplyPowerSlot.md), and [UID:0004B3][0x0054ab90-0x0054aebb.PowerDialogPaneRefreshPowerEntriesFromPacket](by-memory/0x0054ab90-0x0054aebb.PowerDialogPaneRefreshPowerEntriesFromPacket.md) emit their source definitions through this complete class; raw/compiler-wrapper children keep their no-code dispositions.

## UID0004AY Accepted Callback Synchronization - 2026-07-15

- Exact object size is `0x2e4`. The accepted DialogPane base ends at `+0x26c`; `m_encodedPowerValues[5]` occupies `+0x26c..+0x27f`, and `m_powerGrid[5][5]` occupies `+0x280..+0x2e3`, filling the allocation without an unknown tail.
- PowerDialogPane has primary, EventHandler-secondary, and tertiary vtable views. The constructor installs the secondary table at complete object `+0xa0`; `HandlePacketEvent` occupies its exact packet-family slot `+0x10`. The target's machine `this-0xa0` is compiler normalization and is excluded from source.
- `OnControlCommand(int,int)` occupies inherited DialogPane primary slot `+0x48`. Historical `OnDialogAction` would create a wrong additional virtual in this complete declaration and is rejected as current source spelling.
- `HandlePacketEvent(Event *)` reads `event->m_payload.m_packet.m_data`, accepts only opcode `0x46`, calls the private void refresh method, ignores machine return residue, and returns bool handled state. It has vtable-only liveness, exactly one callee, and no invented kind/size/null checks.
- Source order remains constructor; destructor/singleton; `OnControlCommand`; `HandlePacketEvent`; `OnPaint`; private apply/raw/refresh helpers; private list companion/file-local compare; compiler adjustor/scalar support. The class declaration emits once through UID0000MO and exact children provide definitions.
- Vptr writes, RTTI/vtable arrays, secondary receiver adjustment, adjustor thunks, scalar deleting wrapper, switch table, and alignment bytes are compiler output and must not be handwritten in the class or child source.
- Event, EventHandler, and DialogPane declarations already provide the exact wrapper and base contracts. EventHandler, Event, PacketBuffer, Socket, MapPane, PowerListPane, and UID0001F6 remain rejected as direct target owners.

## Cross-References

- [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md)
- [UID:0000AQ][PowerListPane](by-class/PowerListPane.md)
- [UID:0001F5][0x00549c20-0x0054a472.PowerDialogPaneConstructor](by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md)
- [UID:0001F7][0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers](by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md)
- [UID:0001F8][0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks](by-memory/0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks.md)
- [UID:0001F6][0x00549c20-0x0054b5d5.PowerDialogPane](by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md)
- [UID:0004AX][0x0054a4c0-0x0054a69d.PowerDialogPaneOnControlCommand](by-memory/0x0054a4c0-0x0054a69d.PowerDialogPaneOnControlCommand.md)
- [UID:0004AY][0x0054a6c0-0x0054a6e6.PowerDialogPaneHandlePacketEvent](by-memory/0x0054a6c0-0x0054a6e6.PowerDialogPaneHandlePacketEvent.md)
- [UID:0004AZ][0x0054a6f0-0x0054a7e9.PowerDialogPaneOnPaint](by-memory/0x0054a6f0-0x0054a7e9.PowerDialogPaneOnPaint.md)
- [UID:0004B0][0x0054a7f0-0x0054a954.PowerDialogPaneApplyPowerSlot](by-memory/0x0054a7f0-0x0054a954.PowerDialogPaneApplyPowerSlot.md)
- [UID:0004B1][0x0054a960-0x0054aa96.PowerDialogPaneUnreferencedApplyAllThresholdsRaw](by-memory/0x0054a960-0x0054aa96.PowerDialogPaneUnreferencedApplyAllThresholdsRaw.md)
- [UID:0004B2][0x0054aaa0-0x0054ab87.PowerDialogPaneUnreferencedSelectedPowerSlotRaw](by-memory/0x0054aaa0-0x0054ab87.PowerDialogPaneUnreferencedSelectedPowerSlotRaw.md)
- [UID:0004B3][0x0054ab90-0x0054aebb.PowerDialogPaneRefreshPowerEntriesFromPacket](by-memory/0x0054ab90-0x0054aebb.PowerDialogPaneRefreshPowerEntriesFromPacket.md)
- [UID:0004B5][0x0054af30-0x0054afd5.PowerDialogPaneComparePowerEntries](by-memory/0x0054af30-0x0054afd5.PowerDialogPaneComparePowerEntries.md)
- [UID:0004B9][0x0054b520-0x0054b57f.PowerDialogPaneScalarDeletingDestructor](by-memory/0x0054b520-0x0054b57f.PowerDialogPaneScalarDeletingDestructor.md)
- [UID:0000S0][g_pPowerDialog](by-global/g_pPowerDialog.md)
- [UID:00003T][DialogPane](by-class/DialogPane.md)
- [UID:00007A][ListPane](by-class/ListPane.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-07-21 B002 UID0001PZ accepted callback:
  - Preserved `92/94`, UID0000MO owner/emitter, the exact base/layout/access/method/field union, and all current children.
  - Installed the exact complete managed declaration with `class PowerDialogPane;` and `extern PowerDialogPane *g_pPowerDialog;` before the class, preserved the class closing brace before `[[CHILDREN]]`, and retained every method body on its exact child page.
  - Added the UID0000S0 position-160 sole-definition route, UID0001PZ physical/no-code disposition, source order and compiler exclusions, and explicit rejection of a Singleton-template base, class static member, duplicate global, raw ABI data, or explicit compiler teardown.
- 2026-07-15 B001 UID0004AY accepted callback: raised the class to `92/94`, inserted the complete accepted `0x2e4` declaration with `[[CHILDREN]]`, synchronized `OnControlCommand` and `HandlePacketEvent`, recorded the three-view virtual/receiver/source route, and historicalized only superseded names/no-code conclusions while preserving all prior child research.
- 2026-07-04 B011 accepted [UID:0004B3][0x0054ab90-0x0054aebb.PowerDialogPaneRefreshPowerEntriesFromPacket](by-memory/0x0054ab90-0x0054aebb.PowerDialogPaneRefreshPowerEntriesFromPacket.md) implementation:
  - Updated the method row and parent attachment text from blank-emitter wording to `88/91` class-owned emitting `PowerDialogPane::RefreshPowerEntriesFromPacket(const unsigned char *packet)` first-draft C++ through this class.
  - Summary/evidence: B011 MCP session `eb7ce28b` confirms exact range `0x0054ab90-0x0054aebb`, size `0x32b`, no function at `0x0054aebb`/`0x0054aec0`, sole opcode `0x46` handler caller at `0x0054a6db`, packet pointer and `this - 0xa0` receiver adjustment, controls `7..10` list clear/refill, packet row offsets, `PowerEntryRecord` writes, `m_encodedPowerValues` threshold matching, `m_powerGrid[5][5]` accumulation/totals, `ComparePowerEntries` sorting, final `Pane::InvalidateRect`, and rejection of PacketBuffer/ListPane/PowerListPane/Pane/no-owner/broad-aggregate ownership.
- 2026-07-04 B012 accepted [UID:0004B5][0x0054af30-0x0054afd5.PowerDialogPaneComparePowerEntries](by-memory/0x0054af30-0x0054afd5.PowerDialogPaneComparePowerEntries.md) implementation:
  - Updated the helper row from behavior-only/blank state to `89/91` emitting file-local `static int __cdecl ComparePowerEntries(const void *leftEntry, const void *rightEntry)` C++ through [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md).
  - Summary/evidence: B012 MCP session `eb7ce28b` confirms exact `0xa5` / decimal `165` body, no function at `0x0054afd5`, padding, constructor and refresh sort refs, no callees, `PowerEntryRecord::displayColor +0x20c`, `PowerEntryRecord::amount +0x008`, `g_pConfig->m_powerDialogThresholdDefaults[4]`, exact bucket order, descending amount tie-break, and rejection of class/list ownership.
- 2026-07-02 B012 accepted [UID:0004B0][0x0054a7f0-0x0054a954.PowerDialogPaneApplyPowerSlot](by-memory/0x0054a7f0-0x0054a954.PowerDialogPaneApplyPowerSlot.md) implementation:
  - Updated the method row from blank-emitter wording to `90/91` class-owned emitting `PowerDialogPane::ApplyPowerSlot(int slot)` first-draft C++ through this class.
  - Summary/evidence: B012 MCP evidence confirmed exact range, no function at end boundary, five UID0004AX caller xrefs, selected-index/list-row route, `PowerEntryRecord` `entryId`/`displayColor` fields, `m_encodedPowerValues[slot - 1]`, opcode `0x4c/2` packet layout, UInt32BE selected entry id, decoded selected threshold/color byte, send length `12`, and source-facing helper decisions for list access, packet write, threshold decode, and sender route. The old pending row/packet declaration no-code rationale is superseded.
- 2026-07-02 B010 accepted [UID:0004AZ][0x0054a6f0-0x0054a7e9.PowerDialogPaneOnPaint](by-memory/0x0054a6f0-0x0054a7e9.PowerDialogPaneOnPaint.md) implementation:
  - Updated the method row from blank-emitter wording to `90/91` class-owned emitting `PowerDialogPane::OnPaint()` first-draft C++ through this class.
  - Summary/evidence: B010 MCP evidence confirmed exact range `0x0054a6f0-0x0054a7e9`, size `0xf9`, vtable xref `0x0062219c`, `POWER.EPF` xref `0x0054a71c`, `L"%d"` xref `0x0054a785`, `g_pEPFLib` / resource-layout lookup, Surface slot-2 `RenderTileFrame` route, text color `143`, inferred `m_textDrawMode`, grid base `this+0x280`, coordinate loops, `MoveTo`, and `DrawWideText`. The old pending renderer/resource/text helper no-code rationale is superseded.
- 2026-07-02 B010 accepted [UID:0004AX][0x0054a4c0-0x0054a69d.PowerDialogPaneOnControlCommand](by-memory/0x0054a4c0-0x0054a69d.PowerDialogPaneOnControlCommand.md) implementation:
  - Historical at that implementation point, the method row became `90/91` class-owned emitting `PowerDialogPane::OnDialogAction(int actionId, int actionParam)` first-draft C++. Current UID0004AX is `92/94` and emits the same accepted body as inherited `PowerDialogPane::OnControlCommand(int actionId, int actionParam)`; the earlier spelling is superseded, not current.
  - Summary/evidence: B010 MCP evidence confirmed exact range, vtable xref `0x006221a0`, `retn 8` callback signature, action `0` threshold read/update/send behavior, actions `1..5` to [UID:0004B0][0x0054a7f0-0x0054a954.PowerDialogPaneApplyPowerSlot](by-memory/0x0054a7f0-0x0054a954.PowerDialogPaneApplyPowerSlot.md), action `6` close route, and source-facing helper decisions for text read, packet write/send, config/global, and DialogPane close helpers. The old pending-helper no-code rationale is superseded.
- 2026-06-29 B002 accepted UID0001F6 split/container repair support sync:
  - Added exact child rows for [UID:0004AX][0x0054a4c0-0x0054a69d.PowerDialogPaneOnControlCommand](by-memory/0x0054a4c0-0x0054a69d.PowerDialogPaneOnControlCommand.md) action dispatch, [UID:0004AY][0x0054a6c0-0x0054a6e6.PowerDialogPaneHandlePacketEvent](by-memory/0x0054a6c0-0x0054a6e6.PowerDialogPaneHandlePacketEvent.md) opcode `0x46` packet handler, [UID:0004AZ][0x0054a6f0-0x0054a7e9.PowerDialogPaneOnPaint](by-memory/0x0054a6f0-0x0054a7e9.PowerDialogPaneOnPaint.md) paint, [UID:0004B0][0x0054a7f0-0x0054a954.PowerDialogPaneApplyPowerSlot](by-memory/0x0054a7f0-0x0054a954.PowerDialogPaneApplyPowerSlot.md) apply slot, [UID:0004B1][0x0054a960-0x0054aa96.PowerDialogPaneUnreferencedApplyAllThresholdsRaw](by-memory/0x0054a960-0x0054aa96.PowerDialogPaneUnreferencedApplyAllThresholdsRaw.md)/[UID:0004B2][0x0054aaa0-0x0054ab87.PowerDialogPaneUnreferencedSelectedPowerSlotRaw](by-memory/0x0054aaa0-0x0054ab87.PowerDialogPaneUnreferencedSelectedPowerSlotRaw.md) raw no-route spans, [UID:0004B3][0x0054ab90-0x0054aebb.PowerDialogPaneRefreshPowerEntriesFromPacket](by-memory/0x0054ab90-0x0054aebb.PowerDialogPaneRefreshPowerEntriesFromPacket.md) packet refresh body, [UID:0004B5][0x0054af30-0x0054afd5.PowerDialogPaneComparePowerEntries](by-memory/0x0054af30-0x0054afd5.PowerDialogPaneComparePowerEntries.md) real file-local `ComparePowerEntries`, and [UID:0004B9][0x0054b520-0x0054b57f.PowerDialogPaneScalarDeletingDestructor](by-memory/0x0054b520-0x0054b57f.PowerDialogPaneScalarDeletingDestructor.md) scalar deleting destructor wrapper.
  - Summary/evidence: MCP session `279422f0` reconfirmed the split starts; [UID:0001F6][0x00549c20-0x0054b5d5.PowerDialogPane](by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md) is now a non-emitting container, exact children own remaining coverage, and the older constructor-only `ComparePowerEntries` wording is historicalized.
- 2026-06-28 B003 accepted [UID:0001F5][0x00549c20-0x0054a472.PowerDialogPaneConstructor](by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md) empty-emitter implementation:
  - Updated the constructor row from blank-C++ blocker wording to formal first-draft constructor C++ owned by [UID:0001F5][0x00549c20-0x0054a472.PowerDialogPaneConstructor](by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md).
  - Historical summary/evidence: B003 MCP session `b003_powerdialog_0001f5_20260628` resolved the `0x852` constructor boundary, packet case `0x46` caller, unreferenced `0x00513b50` wrapper, vtable stores, singleton refs, threshold config offsets, `m_encodedPowerValues[5]`, `m_powerGrid[5][5]`, `PowerEntryRecord` layout, and dependent action/paint/apply/list-mouse behavior. Its then-descriptive `OnDialogAction` label is now `OnControlCommand`; its statement that the class C++ stayed blank is superseded by the current complete declaration.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and left `AUTOGEN_PARENT_UID` blank.
  - Before: reconstruction autogen classification was blank despite detailed power-dialog construction, action, paint, singleton, packet, and destructor documentation.
  - After: classified as reconstructable source but intentionally unassigned.
  - Evidence: live IDA MCP `lookup_funcs` confirms modeled starts at `0x00549c20`, `0x0054a480`, `0x0054a4b0`, `0x0054a4c0`, `0x0054a6f0`, `0x0054a7f0`, `0x0054b4f0`, `0x0054b4fb`, `0x0054b506`, `0x0054b511`, and `0x0054b520`; existing [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md) evidence places the module under `NexusTK/ui/dialogs/`. Parent attachment is deferred because the class has `CONFIDENCE:78`, below the 80/80 attach gate.

- Before: completion/confidence metadata were `0/0` despite detailed dialog purpose, constructor re-ownership, method map, layout notes, singleton evidence, packet behavior, and source-layout decision.
- Changed to: `COMPLETION:86` and `CONFIDENCE:78`.
- Historical evidence at that score revision: IDA-backed constructor range, then-descriptive `OnDialogAction` (now `OnControlCommand`), `OnPaint`, `ApplyPowerSlot`, singleton helpers, destructor/thunks, layout offsets, packet opcode `0x4c`, vtable/source-placement decisions, and Wave3 data caveats were documented; the old score cap and generated-ownership uncertainty are superseded by current `92/94` class state.

- 2026-06-06 A006 provenance cleanup:
  - Before: status/evidence lines cited recovered one-class source paths directly.
  - Changed to: generated-output caveat wording that points back to the documented IDA-backed ownership evidence.
  - Evidence: [UID:0001F5][0x00549c20-0x0054a472.PowerDialogPaneConstructor](by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md), [UID:0001F6][0x00549c20-0x0054b5d5.PowerDialogPane](by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md), and the singleton/list pages already record the relevant boundary, vtable, caller, and global-xref proof.
- 2026-06-07 A008 parent-chain refresh:
  - What existed before: `CONFIDENCE:78` and no autogen parent, despite the file and aggregate docs meeting the parent gate.
  - Changed to: `CONFIDENCE:82` and `AUTOGEN_PARENT_UID:0000MO`.
  - Summary/evidence: existing IDA-backed file, memory, singleton, and constructor docs now support the class-level source-root chain through [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md). The class page already documents the corrected `0x00549c20` dialog-constructor ownership, opcode `0x46` construction route, opcode `0x4c` action paths, `POWER.EPF` paint path, embedded private list controls, [UID:0000S0][g_pPowerDialog](by-global/g_pPowerDialog.md), ignored adjustor thunks, generated `0x0054aec0` exclusion, and broad-config threshold reads. C++ remains blank because final row/config names, private-list split, and the second constructor caller still need a final-source pass.
- 2026-06-11 A002 Batch222 confidence refresh:
  - Before: `86/82`, below the strict confidence gate for direct vtable/string children.
  - Changed to: `86/86`.
  - Summary/evidence: live IDA MCP reconfirmed the exact `PowerDialogPane` RTTI/vtable child, the `Power`/`POWER.EPF` resource-string child, vtable-store xrefs, constructor/paint consumers, and corrected `.rdata` boundaries. Confidence remains below final-audit range because exact private row/config field names and the second constructor caller are still unresolved.
- 2026-06-26 B007 implementation of accepted [UID:0001F7][0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers](by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md) report:
  - Updated the singleton helper row from retained cleanup/getter wording to formal exact-child C++: `PowerDialogPane::~PowerDialogPane()` and static `PowerDialogPane::GetSingleton()`.
  - Summary/evidence: B007 MCP session `80de0a67` confirmed exact helper sizes and padding, `g_pPowerDialog` lifecycle refs, three `PowerDialogPane` vtable stores, no direct helper xrefs, no absolute helper-start pointer hits, stale `boost::exception` correction to `DialogPane` cleanup, and scalar deleting destructor corroboration. The broad class C++ remains blank; exact child [UID:0001F7][0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers](by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md) now owns the destructor/getter bodies.
