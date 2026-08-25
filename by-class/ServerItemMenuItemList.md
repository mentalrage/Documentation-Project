*** UID:0000D0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ServerItemMenuItemList definitions are emitted by source child UID0001BP.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct ServerItemMenuEntry
{
    unsigned short itemId;
    unsigned char itemStyle;
    unsigned char reserved;
    unsigned int value;
    wchar_t name[256];
    wchar_t description[256];
};

class ServerItemMenuItemList : public ListPane
{
public:
    ServerItemMenuItemList(unsigned char packetSubtype,
                           unsigned int menuObjectId,
                           unsigned short menuOptionId,
                           ServerItemMenuDialog *owner);
    virtual ~ServerItemMenuItemList();

    void AppendItem(unsigned short itemId,
                    unsigned char itemStyle,
                    unsigned int value,
                    const wchar_t *name,
                    const wchar_t *description);
    void SendSelectedItemName();
    void SendItemName(const wchar_t *name);

    void OnItemSelected(int rowIndex, int notify) override;
    void OnItemActivated() override;
    bool OnMouseEvent(MouseEvent *event) override;
    void DrawListEntry(int rowIndex, void *rowData,
                       RectBounds *rowBounds) override;

private:
    unsigned char m_packetSubtype;
    unsigned char m_reserved0[3];
    unsigned int m_menuObjectId;
    unsigned short m_menuOptionId;
    unsigned short m_reserved1;
    ServerItemMenuDialog *m_owner;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ServerItemMenuItemList

## Status

- Confidence: strong for live vtable identity, item-menu list behavior, exact virtual/destructor boundaries, corrected row layout, `g_pItemHelpPane` linkage, opcode `0x39` string semantics, ordinary/scalar destructor split, and parent source placement; medium-high for exact original private helper/prototype names outside the now-closed destructor route.
- Reconstructability: reconstructable as the server-side private item-menu list under [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md). Source authors supplied the ordinary destructor in UID0001BP; the compiler regenerates UID0001C2 and UID0001BZ scalar/adjustor ABI entry points. Remaining caveats are exact original helper/prototype names and unrelated raw helper starts that still lack modeled IDA functions/xrefs.
- Parent source file: [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md)
- Main address range: [UID:0001BP][0x0051ae90-0x0051b87a.ServerItemMenuItemList](by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md)

## Class Purpose

`ServerItemMenuItemList` is the row-list widget for server-provided item action menus. It stores packet/item context, maintains selected-row description text, forwards activation into the owning menu context, and draws rows with item icon, display name, and right-aligned value.

## Method Notes

| Method or range | Address | Role |
| --- | --- | --- |
| `ServerItemMenuItemList` | `0x0051ae90-0x0051aefc` | Raw constructor-shaped code; builds a `ListPane` with server menu row geometry and installs three `ServerItemMenuItemList` vtables. |
| `~ServerItemMenuItemList` ordinary destructor | `0x0051af00-0x0051af35` | Exact source-visible body; restores three vptrs, closes active `g_pItemHelpPane`, and tail-calls shared `ListPane` cleanup. Its SHA256 is `33D2282C2082BD8A9C26F862709936EC0BFD90FEB0ECBDF2A2EF53F5CD67039A`. |
| append row helper | `0x0051af40-0x0051afbf` | Builds a server item row record from id/style/value/name/detail strings and appends it to the list. |
| selected-name packet helper | `0x0051afd0-0x0051b0f8` | Builds opcode `0x39` payload from the selected row's wide display name/string. |
| `OnItemSelected` | `0x0051b100-0x0051b18d` | Updates owner text slot `7` from the selected row detail text before delegating to `ListPane`. |
| explicit-text packet helper | `0x0051b190-0x0051b2a8` | Builds opcode `0x39` payload from a caller-supplied wide name/string. |
| `OnItemActivated` thunk | `0x0051b2b0-0x0051b2bb` | Loads owner/context from `this + 0x158` and jumps to shared activation logic at `0x0049de70`. |
| `OnMouseEvent` | `0x0051b2c0-0x0051b3e0` | Handles row pointer/event logic and high-resolution help-pane behavior. |
| `DrawListEntry` | `0x0051b3e0-0x0051b87a` | Draws item icon, name, and numeric value in high-resolution and legacy layouts. |
| compiler destructor entries | `0x00520b13`, `0x00520b1e`, `0x00520ce0-0x00520d47` | Secondary `this -= 0xa0`, tertiary `this -= 0xa4`, and exact 103-byte scalar deleting wrapper. These are compiler ABI output covered by the ordinary destructor, not additional source methods. |

## Evidence Notes

- Live IDA MCP reports no function object at raw helper starts `0x0051ae90`, `0x0051af00`, `0x0051af40`, `0x0051afd0`, and `0x0051b190`, but disassembly and call/data refs identify complete out-of-line class code at those addresses.
- Live IDA MCP confirms modeled function boundaries for virtuals and destructor glue: `0x0051b100-0x0051b18d`, `0x0051b2b0-0x0051b2bb` with the shared activation chunk at `0x0049de70-0x0049df14`, `0x0051b2c0-0x0051b3e0`, `0x0051b3e0-0x0051b87a`, adjustor thunks `0x00520b13-0x00520b1e` and `0x00520b1e-0x00520b29`, and scalar deleting destructor `0x00520ce0-0x00520d47`.
- Live byte checks confirm `0xcc` padding at `0x0051ae8d-0x0051ae90`, `0x0051aefc-0x0051af00`, `0x0051b87a-0x0051b880`, and after `0x00520d47`. The byte at `0x0051b879` is the final `retn 0Ch` operand for the row draw virtual, so `0x0051b87a` remains the correct exclusive end.
- Live vtable symbols bind the class: primary `??_7ServerItemMenuItemList@@6B@` at `0x0061ef44`, secondary `??_7ServerItemMenuItemList@@6B@_0` at `0x0061efcc`, and tertiary `??_7ServerItemMenuItemList@@6B@_1` at `0x0061effc`.
- Vtable writes occur in the inline server-dialog setup (`0x0051a6ff`, `0x0051a705`, `0x0051a70f`), raw constructor (`0x0051aedb`, `0x0051aee1`, `0x0051aeeb`), raw destructor (`0x0051af03`, `0x0051af09`, `0x0051af13`), and scalar deleting destructor (`0x00520ce6`, `0x00520cec`, `0x00520cf6`).
- Key primary vtable slots are `0x0061ef44 -> 0x00520ce0`, `0x0061efa4 -> 0x0051b2c0`, `0x0061efbc -> 0x0051b100`, `0x0061efc0 -> 0x0051b2b0`, and `0x0061efc4 -> 0x0051b3e0`; secondary/tertiary slots point to `0x00520b13` and `0x00520b1e`.
- Live call refs in the raw constructor show `ListPane` construction through `0x004f3a50` followed by fixed state storage at `+0x14c`, `+0x150`, `+0x154`, and `+0x158`. The raw row append helper calls `_wcscpy_s` twice and `0x004f3c50` to append the stack row.
- Live call refs in the two packet helpers show the selected-row path through `0x004f3dc0`, allocator `0x00516030`, byte writers around `0x00575380/0x005753f0/0x005753a0`, `WideCharToMultiByte`, send path `0x00574bb0`, and shared network context `0x0067a7ec`.
- IDA decompilation of `0x0051b100` updates owner child/control slot `7` from row text at `row + 0x208` or clears it with `word_60db20`, then delegates selection to `0x004f45b0`.
- IDA-backed documentation of `0x0051b2c0` handles event byte `1`/`4`, hit-tests through `0x004b7e80` and `0x004f4480`, closes active [UID:0000R9][g_pItemHelpPane](by-global/g_pItemHelpPane.md) through the singleton close helper, and allocates/replaces an `ItemHelpPane` in the EPF/current help path.
- IDA decompilation of `0x0051b3e0` branches on `byte_66da97`, draws the selected background, renders item imagery through item-image helpers, clamps/truncates the wide display name with ellipsis text, and prints the right-aligned value using the `"%10u"` format.
- IDA decompilation of `0x00520ce0` resets the three class vtables, closes active [UID:0000R9][g_pItemHelpPane](by-global/g_pItemHelpPane.md), calls `ListPane` cleanup at `0x004f3b60`, and conditionally deletes through `0x004f4ac0`.
- B001 current healthy MCP session `7be8cc9f` fixes complete-object size at `0x15c`, consistent with class state through owner pointer `+0x158`. Scalar wrapper UID0001C2 passes this exact size only on its guarded bit-4 no-free path.
- The exact ordinary destructor has four predecessor and eleven successor `0xcc` alignment bytes. Its first 47 semantic bytes match UID0001C2 after that wrapper's frame setup: all three vptr restores and the null-safe help-pane close are identical before ordinary `ListPane` cleanup versus compiler delete-flag handling.

## Destructor Source And ABI Routing

| View | First entry | Source disposition |
| --- | --- | --- |
| Primary complete-object vtable `0x0061ef44` | `0x00520ce0` | Enters class-owned scalar wrapper UID0001C2. The wrapper's formal output is a covered-by comment to ordinary source UID0001BP. |
| Secondary vtable `0x0061efcc` | `0x00520b13` | Compiler adjustor subtracts `0xa0` and tail-jumps to UID0001C2; no handwritten method. |
| Tertiary vtable `0x0061effc` | `0x00520b1e` | Compiler adjustor subtracts `0xa4` and tail-jumps to UID0001C2; no handwritten method. |

The authored class source retains ordinary `ServerItemMenuItemList::~ServerItemMenuItemList()` semantics through direct null-safe `delete g_pItemHelpPane;` followed by inherited `ListPane` teardown. It must not expose scalar `deleteFlags`, manual vptr stores, `this` adjustments, direct operator-delete dispatch, guarded-size ABI mechanics, or an invented singleton-close helper. UID0001C2 remains reconstructable class evidence for traceability, but its exact formal covered-by marker points to UID0001BP so generated source has one human destructor body rather than duplicate reverse-engineered wrappers.

## Row Layout And Packet Semantics

The server row is `ServerItemMenuEntry`, `sizeof == 0x408`. B002's 2026-06-19/20 aggregate recheck supersedes the older generated/report wording that treated the first byte as `actionId`.

| Offset | Field | Notes |
| --- | --- | --- |
| `+0x000` | `unsigned short itemId` | Raw append writes a word; draw uses it with `itemStyle` for item imagery. |
| `+0x002` | `unsigned char itemStyle` | Raw append writes a byte; draw uses it with `itemId`. |
| `+0x003` | `unsigned char reserved` | Padding/copied stack byte with no proven semantic read. |
| `+0x004` | `unsigned int value` | Drawn right-aligned with `"%10u"`. |
| `+0x008` | `wchar_t name[256]` | Copied by `_wcscpy_s`, drawn as row name, used by the selected-name packet path and help display. |
| `+0x208` | `wchar_t description[256]` | Copied by `_wcscpy_s` and pushed to owner text control id `7` on selection. |

There is no server row `actionId`. The source-facing list helpers are `AppendItem(unsigned short itemId, unsigned char itemStyle, unsigned int value, const wchar_t* name, const wchar_t* description)`, `SendSelectedItemName()`, and `SendItemName(const wchar_t* name)`. Server opcode `0x39` serializes `m_packetSubtype`, `m_menuObjectId`, `m_menuOptionId`, and selected/caller-supplied text converted from wide characters. Dialog command ids `1`, `2`, and `3` are handled by `ServerItemMenuDialog`; raw button constants `0x0e`, `0x10`, and `0x0f` are construction constants, not row action ids.

## 2026-08-22 UID0000KF Accepted Declaration

The formal H channel is the complete private list declaration at ItemMenuDialogs H source position 20. `ServerItemMenuEntry` is exactly `0x408`, with fields at `+0/+2/+3/+4/+8/+0x208`; there is no server-row action byte. The complete list object is `0x15c`: constructor-saved state is `m_packetSubtype +0x14c`, `m_menuObjectId +0x150`, `m_menuOptionId +0x154`, and owner `+0x158`. The `ListPane` base call is exactly `ListPane(0x408,0x10,0x15c,0x18,false,true,1)`.

UID0001BP supplies nine authored bodies in source order: constructor, ordinary destructor, `AppendItem`, selected-name sender, `OnItemSelected(int,int)`, explicit-name sender, `OnItemActivated()`, `OnMouseEvent(MouseEvent *)`, and `DrawListEntry(int,void *,RectBounds *)`. Five raw starts remain valid retained methods despite zero direct start xrefs; four virtuals are anchored by cells `0x0061efbc`, `0x0061efc0`, `0x0061efa4`, and `0x0061efc4`. The declaration deliberately excludes synthetic `NotifyOwner`, `HandleMenuEvent`, and decompiler drawing interfaces.

The ordinary destructor at `[0x0051af00,0x0051af35)` closes active UID0000R9 and allows normal `ListPane` destruction. UID0001BZ adjustors and UID0001C2 deleting-wrapper mechanics are compiler output; UID0001C2 retains only a covered-by comment. Completion/confidence are `94/94`; remaining uncertainty is lexical and compile/byte parity, not layout, behavior, ownership, or source routing.

## Score Rationale

- `COMPLETION:94`: exact row/object layouts, nine-body inventory, raw and modeled liveness, packet/help/draw behavior, ordinary/compiler destructor split, H declaration, source child, and final emitter order are closed.
- `CONFIDENCE:94`: vtable names/writes, inline construction, exact hashes/ranges, call targets, row consumers, and current dependency declarations agree. The cap reflects inferred private lexical names and unproven compile/byte parity.
- `RECONSTRUCTABLE:TRUE`: authored behavior emits through UID0001BP and this declaration; only compiler deleting glue remains no-code.

## Cross-References

- [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0001BP][0x0051ae90-0x0051b87a.ServerItemMenuItemList](by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md)
- [UID:0000CZ][ServerItemMenuDialog](by-class/ServerItemMenuDialog.md)
- [UID:00002Q][ClientItemMenuItemList](by-class/ClientItemMenuItemList.md)
- [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md)
- [UID:00007A][ListPane](by-class/ListPane.md)

## Changes

- 2026-06-04: Raised completion/confidence from `82/76` to `86/86`, marked `RECONSTRUCTABLE:TRUE`, and attached the class to [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md). The increase is justified by fresh live IDA MCP evidence for exact function/raw-code boundaries, padding bytes, vtable names and slots, inline server-dialog setup writes, raw helper call targets, modeled virtual behavior, and destructor/thunk linkage.
- 2026-06-18 B002 source-quality sync: raised to `88/89` after the target report resolved the `0x408` `ServerItemMenuEntry` layout, changed stale observer wording to [UID:0000R9][g_pItemHelpPane](by-global/g_pItemHelpPane.md), and documented first-draft C++ eligibility. Remaining uncertainty is limited to exact original helper/prototype names and raw helper reachability.
- 2026-06-20 B002 Rule 26 aggregate correction: score unchanged. Updated the class-level row layout to the corrected server `ServerItemMenuEntry` shape (`itemId`, `itemStyle`, reserved byte, `value`, `name[256]`, `description[256]`), removed the stale row `actionId`, and recorded server opcode `0x39` string/name semantics plus source-facing helpers `AppendItem`, `SendSelectedItemName`, and `SendItemName`.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `82`, confidence `76`.
- Evidence: the page documented constructor-shaped code, destructor, row append, packet helpers, activation/event/draw behavior, destructor thunks, and vtable xrefs; confidence stayed medium-high because constructor and scattered helper ownership still needed final source placement.
- 2026-07-23 B001 UID0001C2 support synchronization: score/formal class route unchanged at `88/89` through UID0000KF. Added exact source-visible destructor `[0x0051af00,0x0051af35)`, ordinary hash/padding and 47-byte scalar parity, complete-object size `0x15c`, primary/secondary/tertiary deleting-destructor routes, the UID0001C2 covered-by relation, and the requirement that compiler vptr/delete-flag/adjustor/free/guard mechanics never be handwritten as class methods.
