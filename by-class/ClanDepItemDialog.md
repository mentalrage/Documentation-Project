*** UID:000029 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanDepItemDialog : public ClanItemDialog
{
public:
    explicit ClanDepItemDialog(const unsigned char *packet);
    virtual ~ClanDepItemDialog();

protected:
    virtual void OnButtonClick(int controlId, int action, int value);
    virtual void SendDepositItemPacket(unsigned char slotIndex, unsigned short amount);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ClanDepItemDialog

## Status

- Confidence: strong for constructor, vtable, button-handler, and packet-sender evidence; medium for exact field names and shared slide-helper ownership.
- Likely source file: [UID:0000I9][ClanBank](by-file/ClanBank.md)
- 2026-06-15 live IDA status: current `NexusTK.exe` session reconfirms constructor `sub_48A1C0` size `0x4ca`, vtable-reset helper `sub_48A690` size `0x1f`, button handler `sub_48A6B0` size `0xd1`, packet sender `sub_48A790` size `0x75`, slide helpers at `0x0049ec80`/`0x0049ed60`, unique signature for `0x0048a1c0-0x0048a805`, constructor callers, and vtable-only action/send anchors.

## Class Purpose

`ClanDepItemDialog` is the clan-bank item deposit dialog. It parses packet-supplied depositor and item-description text, creates the `DL` dialog with an item list and amount edit control, sends a deposit-item packet, and closes through the shared dialog animation path. Its item picker is the reusable [UID:00008W][MyItemListPane](by-class/MyItemListPane.md), not a clan-private list pane.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClanDepItemDialog` | `0x0048a1c0-0x0048a68a` | Builds the dialog, decodes packet text, creates item/object list and amount edit controls, and attaches to the desktop/main window. |
| vtable-reset helper | `0x0048a690-0x0048a6af` | Standalone reset helper; resets class vtables before base cleanup. |
| `OnButtonClick` | `0x0048a6b0-0x0048a781` | On OK, reads selected item and amount, sends the deposit packet through virtual slot `0x5c`, then OK/Cancel closes. |
| `SendDepositItemPacket` | `0x0048a790-0x0048a805` | Sends opcode `0x4b`, subtype `5`, action `1`, selected-slot byte, and big-endian amount through the packet sender. |
| shared slide-in helper | `0x0049ec80-0x0049ed58` | Horizontal slide animation dependency used by this dialog and sibling clan dialogs. |
| shared slide-close helper | `0x0049ed60-0x0049ee42` | Close animation dependency used by this dialog and other clan-bank dialog paths. |

## Evidence Notes

- Live IDA `py_eval` on 2026-06-04 used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- IDA confirms modeled ranges `0x0048a1c0-0x0048a68a`, `0x0048a690-0x0048a6af`, `0x0048a6b0-0x0048a781`, `0x0048a790-0x0048a805`, `0x0049ec80-0x0049ed58`, and `0x0049ed60-0x0049ee42`; padding between adjacent bodies is `0xcc`.
- Constructor callers are `0x0048516e` inside `0x00484f70` and `0x00487e83` inside `0x00487e20`, matching the clan status/packet dialog-open path.
- Constructor vtable stores are `0x0048a21a -> 0x0061607c`, `0x0048a220 -> 0x006160e0`, and `0x0048a22a -> 0x00616110`. The primary vtable places `OnButtonClick` in slot 18 (`0x006160c4 -> 0x0048a6b0`) and `SendDepositItemPacket` in slot 23 (`0x006160d8 -> 0x0048a790`).
- The dialog allocates the reusable [UID:00008W][MyItemListPane](by-class/MyItemListPane.md) at constructor call site `0x0048a50d`. Live caller fanout for `0x004aeb30` is `ClanDepItemDialog`, `AddItemDialog`, and `MixItemDialog`, so the picker remains shared item UI support.
- `OnButtonClick` branches on button ids `1` and `2`; the OK path reads the selected item from the list, parses the amount text, dispatches through virtual slot `0x5c`, and then calls the shared close helper at `0x0049ed60`.
- `SendDepositItemPacket` writes byte sequence pieces for opcode `0x4b`, subtype `5`, action `1`, the selected-slot byte, and amount, then reads the packet-sender global at `0x0067a7ec` and calls `0x00574bb0` with length `6`.
- The slide helpers are intentionally kept as shared dependencies: `0x0049ec80` also has sibling clan-dialog callers, and `0x0049ed60` is called from clan money/item dialogs plus `ClanBankPane`.
- 2026-06-15 live IDA recheck:
  - `lookup_funcs` reports method sizes `0x4ca`, `0x1f`, `0xd1`, and `0x75`, plus slide-helper sizes `0xd8` and `0xe2`.
  - `make_signature_for_range 0x0048a1c0-0x0048a805` returns `unique:true`.
  - `xrefs_to` reports constructor callers at `0x0048516e` and `0x00487e83`, button/send vtable anchors at `0x006160c4` and `0x006160d8`, four slide-in helper refs including this constructor, and six slide-close refs including this dialog and ClanBankPane.
  - `analyze_component` reports constructor dependencies on packet decoding, dialog/control construction, `MyItemListPane`, and slide-in helper; button handler dependencies on amount/text reading and shared close; packet sender callees limited to packet-buffer/send helpers.
- 2026-06-16 B001 Clan opcode helper recheck: [UID:00021J][0x00485870-0x00485955.ClanDepositItemRequestAndSubmitPacketHelpers](by-memory/0x00485870-0x00485955.ClanDepositItemRequestAndSubmitPacketHelpers.md) contains retained/no-route subtype `5` action `0` dialog-request and action `1` selected-slot/amount submit helpers. The action `1` raw body mirrors this class's live sender and uses the selected slot from `MyItemListPane_GetSelectedSlotIndex`, but it is not the class method because IDA/PE show no route to the raw start and the active sender remains the vtable-backed ClanBank-owned method at `0x0048a790`.
- 2026-06-16 B001 [UID:00010Q][0x0048ae70-0x0048b1b1.ClanItemListPane](by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md) relationship recheck: this class is source-family context for the clan item dialogs but does not construct [UID:00002G][ClanItemListPane](by-class/ClanItemListPane.md); it uses the shared [UID:00008W][MyItemListPane](by-class/MyItemListPane.md) deposit inventory picker instead. Keep [UID:00010Q][0x0048ae70-0x0048b1b1.ClanItemListPane](by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md) tied to the withdraw-side [UID:00002N][ClanWidItemDialog](by-class/ClanWidItemDialog.md) path.

## Score Rationale

Completion is now above the low-score queue because the class page records current method sizes, constructor callers, vtable-only action/send anchors, unique range signature, packet byte semantics, MyItemListPane dependency, shared slide-helper fan-in, and source-owner routing. Confidence is strong for ClanBank ownership and deposit packet behavior; it remains below final-source quality because inherited fields, exact control/member names, virtual slot names, and shared slide-helper placement are still provisional.

## Cross-References

- [UID:0000I9][ClanBank](by-file/ClanBank.md)
- [UID:00010O][0x0048a1c0-0x0048a805.ClanDepItemDialog](by-memory/0x0048a1c0-0x0048a805.ClanDepItemDialog.md)
- [UID:00012V][0x0049ec80-0x0049ee42.ClanDialogSlideAnimation](by-memory/0x0049ec80-0x0049ee42.ClanDialogSlideAnimation.md)
- [UID:00002F][ClanItemDialog](by-class/ClanItemDialog.md)
- [UID:00008W][MyItemListPane](by-class/MyItemListPane.md)

## Changes

- 2026-06-30 B009 empty-emitter implementation callback: inserted the accepted declaration-level `ClanDepItemDialog` shell with constructor/action/sender prototypes and `[[CHILDREN]]`; set `EMITTER_POSITION_OPTIONAL:0` and raised score to `87/90`. The source-facing control names and `MyItemListPane` dependency remain inferred from current MCP and documented caller/callee evidence.
- Earlier baseline: the page documented item-deposit dialog behavior, packet sender, MyItemListPane ownership, and slide animation caveat, but metadata remained unevaluated.
- Earlier scoring pass: scores were set to `72/80` because constructor, vtable reset, button action, deposit packet helper, and item-list dependency were covered; shared slide animation ownership and detailed dialog field layout remained open.
- 2026-06-04: Raised from `72/80` to `82/86`, marked reconstructable, and attached to [UID:0000I9][ClanBank](by-file/ClanBank.md).
  - Before: page had strong behavior notes but lacked live boundary/caller/vtable evidence, had no reconstructable/parent metadata, and still included a recovered-file provenance line.
  - After: live IDA evidence records the executable identity, exact function ranges and padding, constructor callers, three vtable stores, virtual slots for button handling and packet send, `MyItemListPane` reuse, packet byte layout, and shared slide-helper caller caveat.
  - Reasoning: this is enough for reconstructable class-level documentation and parent attachment because [UID:0000I9][ClanBank](by-file/ClanBank.md) is already `86/80` with a valid `NexusTK/social/` path. Completion stays below final-source quality because final field names, signatures, and shared animation helper ownership remain provisional.
- 2026-06-05: Replaced the remaining generated packet-sender global label with address-based live IDA wording; score remains `82/86`.
- 2026-06-15 A002 Goal 2 by-class refresh: raised to `86/89` after live IDA reconfirmed exact method sizes, slide-helper sizes, unique class-range signature, two constructor callers, button/send vtable anchors, shared slide helper fan-in, `MyItemListPane` dependency, and packet-send callee shape. Owner/emitter route remains [UID:0000I9][ClanBank](by-file/ClanBank.md); final C++ remains blank pending source-quality inherited field/control names and shared helper placement.
- 2026-06-16 B001 Clan opcode helper source-quality cross-note:
  - Added retained-helper mirror note for [UID:00021J][0x00485870-0x00485955.ClanDepositItemRequestAndSubmitPacketHelpers](by-memory/0x00485870-0x00485955.ClanDepositItemRequestAndSubmitPacketHelpers.md). The raw helper pair remains Clan-owned and no-route; this class still owns the active vtable-backed deposit-item sender.
- 2026-07-03 B003 UID00021J implementation callback: replaced stale `deposit mode` wording with selected-slot wording. Current MCP session `3a33af0b` reconfirms vtable-only anchors `0x006160c4 -> 0x0048a6b0` and `0x006160d8 -> 0x0048a790`; the button handler obtains the selected slot from the item-list path before virtual dispatch, and the sender writes opcode `0x4b`, subtype `5`, action `1`, selected-slot byte, UInt16 amount, and send length `6`. The raw UID00021J helper pair remains Clan-owned retained/no-route mirror evidence, not a class method.
- 2026-06-16 B001 [UID:00010Q][0x0048ae70-0x0048b1b1.ClanItemListPane](by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md) relationship note: added the negative ownership/constructor relation for `ClanItemListPane`; no score or route change.
