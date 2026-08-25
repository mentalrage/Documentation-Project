*** UID:0000ER | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
TextInputMenuDialog::TextInputMenuDialog(
    bool hasExtraString,
    const RectBounds& dialogBounds,
    const unsigned char *payload,
    unsigned char merchantDialogType)
    : MerchantDialogPane(merchantDialogType),
      m_replyType(0),
      m_selectedOptionId(0),
      m_hasExtraString(hasExtraString),
      m_extraString()
{
    TextMenuPayloadReader reader(payload);
    ObjectStatusBlob objectStatus;
    wchar_t prompt[32768];

    m_replyType = reader.ReadUInt8();
    m_menuObjectId = reader.ReadUInt32();
    if (!reader.ReadObjectStatus(&objectStatus))
        return;
    reader.ReadAnsi16(prompt, 32768);
    if (m_hasExtraString)
        reader.ReadWideString8(&m_extraString);
    m_selectedOptionId = reader.ReadUInt16();

    RectBounds bounds;
    if (g_useEpfAssets) {
        InitRectBounds(&bounds, 0, 0, 336, 205);
        AddImageControl(bounds, L"DLGMERC2.EPF", 0, L"PA");
        AddButtonControl(RectBounds(60, 169, 123, 193), 14);
        AddButtonControl(RectBounds(137, 169, 200, 193), 16);
        AddButtonControl(RectBounds(214, 169, 277, 193), 15);
        AddObjectImageControl(RectBounds(22, 8, 96, 116), objectStatus);
        AddStaticTextControl(RectBounds(105, 28, 301, 112),
                             prompt, true, 128, 143);
        AddTextEditControl(RectBounds(44, 128, 291, 140),
                           L"", 1, 128, 143, 1.0f);
        SetBackgroundResource(L"DLGMERC2.EPF", 0);
        bounds = RectBounds(0, 0, 336, 205);
    } else {
        InitRectBounds(&bounds, 0, 0, 314, 197);
        AddImageControl(bounds, L"DLGMERC2.EPD", 0, L"NP");
        AddButtonControl(RectBounds(44, 147, 116, 163), 14);
        AddButtonControl(RectBounds(121, 147, 193, 163), 16);
        AddButtonControl(RectBounds(198, 147, 270, 163), 15);
        AddObjectImageControl(RectBounds(35, 37, 72, 92), objectStatus);
        AddStaticTextControl(RectBounds(82, 35, 262, 83),
                             prompt, true, 128, 143);
        AddTextEditControl(RectBounds(56, 113, 257, 125),
                           L"", 1, 128, 143, 1.0f);
        SetBackgroundResource(L"DLGMERC2.EPD", 0);
        bounds = RectBounds(0, 0, 314, 197);
    }

    SetHoverControl(6);
    SetFocusedControl(1);
    SetPendingControl(3);
    StoreClampRect(&dialogBounds);
    SetMode(1);
    OnCreate(&bounds, 0, 0, g_dialogLayer);
    OnShow(0, g_pBackPane);
}

void TextInputMenuDialog::OnControlCommand(int controlIndex, int notifyCode)
{
    (void)notifyCode;

    switch (controlIndex) {
    case 1:
    {
        wchar_t inputText[256];
        GetChild<TextEditControlPane>(6)->ReadText(inputText, 255);
        SendInputReply(inputText);
        CloseDialog();
        break;
    }
    case 2:
        SendMenuRequestPacket();
        break;
    case 3:
        CloseDialog();
        break;
    }
}

void TextInputMenuDialog::UpdateActionButton()
{
    ControlPane *okButton = GetChild<ControlPane>(1);
    TextEditControlPane *input = GetChild<TextEditControlPane>(6);
    if (input->IsEmpty())
        okButton->Deactivate();
    else
        okButton->Activate();
}

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class TextInputMenuDialog : public MerchantDialogPane
{
public:
    TextInputMenuDialog(bool hasExtraString,
                        const RectBounds& bounds,
                        const unsigned char *payload,
                        unsigned char merchantDialogType);

protected:
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual void UpdateActionButton();

private:
    void SendInputReply(const wchar_t *inputText);

    unsigned int m_reserved274;            // +0x274, retained unknown storage
    unsigned char m_replyType;             // +0x278
    unsigned short m_selectedOptionId;      // +0x27a
    bool m_hasExtraString;                 // +0x27c
    mystr::StringBase<
        wchar_t, mystr::mychar_traits<wchar_t> > m_extraString; // +0x280
};

typedef char TextInputMenuDialogSizeMustBe644[
    (sizeof(TextInputMenuDialog) == 0x284) ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TextInputMenuDialog

## Status

- Confidence: strong for behavior, ownership, field/control naming, destructor no-code policy, and first-draft class declaration; remaining caveats are bounded to exact original method spelling and retained raw-helper reachability.
- Likely source file: [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- Main address range: [UID:0001BN][0x00517ec0-0x0051a417.TextMenuDialogs](by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md)
- Destructor/thunk range: [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md)
- Current generated files: `auto-generated/NexusTK/ui/dialogs/TextMenuDialogs.cpp` and `TextMenuDialogs.h`; the old `source-3/simroot_v2/class_TextInputMenuDialog.cpp` path is historical evidence only.
- Current gate result: clears the active `85/85` source route with [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md) as owner/emitter. The old "no C++ below 95/95" wording is historical only; this page now carries first-draft class-level C++ while exact method bodies remain on child by-memory pages.

## Class Purpose

`TextInputMenuDialog` is the text-entry variant of the server-driven merchant/NPC menu dialog. It displays a merchant/object image, message text, and editable text field, validates the edit control state, and sends opcode `0x39` with the selected option and typed text.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x005198e0-0x0051a275` | `TextInputMenuDialog` | Constructor and packet parser; builds `DLGMERC2` style controls, optional extra string state, and the edit control. |
| `0x0051a280-0x0051a3d4` | `OnControlCommand` | Accepted inherited-slot override. Submits text input on OK, sends cancel via inherited `MerchantDialogPane::SendMenuRequestPacket`, or closes without a reply. |
| `0x0051a3e0-0x0051a416` | `UpdateActionButton` | Accepted inherited-slot override. Enables or disables the OK/action button based on the edit control contents. The older `UpdateSubmitButtonState`/`ValidateInput` names are historical aliases. |
| Source destructor | `~TextInputMenuDialog` | Source-level ordinary destructor responsibility; compiler emits primary scalar deleting destructor `0x00520d50` plus secondary/tertiary adjustor thunks `0x00520b29` and `0x00520b34`. |
| [UID:000239][0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper](by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md) | `SendInputReply` | Raw helper that serializes opcode `0x39`, stored dialog fields, optional extra text through the ANSI writer, and caller-supplied wide input text through the wide-to-ANSI writer. |
| [UID:00037C][0x00520b29-0x00520b3e.TextInputMenuDialogDestructorThunks](by-memory/0x00520b29-0x00520b3e.TextInputMenuDialogDestructorThunks.md) | vtable adjustor thunks | Compiler-generated this-adjustors forwarding to the destructor. |
| [UID:00037D][0x00520d50-0x00520d98.TextInputMenuDialogScalarDeletingDestructor](by-memory/0x00520d50-0x00520d98.TextInputMenuDialogScalarDeletingDestructor.md) | scalar deleting destructor | Compiler-generated deleting-destructor wrapper for the text-input dialog teardown path. |

## Evidence Notes

- Wave3 identifies this as a `MerchantDialogPane -> DialogPane` class with three vtable pointers and an EPF/EPD dual asset path.
- IDA MCP confirms the constructor, two virtual methods, two thunks, and destructor starts.
- B010 source-quality reanalysis keeps this class in [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md): constructor/action/update bodies are in UID0001BN, vtables are in the text-menu vtable family, the cancel path calls inherited `MerchantDialogPane::SendMenuRequestPacket`, and UID000239 is directly class-owned by `TextInputMenuDialog`.
- The OK path fetches child control id `6`, reads edit text through [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadText](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadText.md), serializes opcode `0x39`, appends the optional stored extra string when enabled, writes typed input through the wide-to-ANSI packet writer path, sends through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md), and closes the dialog.
- UID000239 contains the retained raw `SendInputReply(const wchar_t *inputTextWide)` serializer for the same opcode `0x39` reply shape. Current evidence distinguishes its two string paths: optional `m_extraString` still appends through `0x005757d0` / `PacketBufferAppendAnsiString8`, while the caller argument is pushed at `0x0051a4e9` and appended through `0x00575850` / `PacketBufferAppendWideStringAsAnsi8`. This matches the observed inline submit path's wide-to-ANSI writer use, but does not prove a direct call from `OnControlCommand`.
- 2026-06-11 Batch166 split review added exact non-reconstructable destructor-glue children [UID:00037C][0x00520b29-0x00520b3e.TextInputMenuDialogDestructorThunks](by-memory/0x00520b29-0x00520b3e.TextInputMenuDialogDestructorThunks.md) and [UID:00037D][0x00520d50-0x00520d98.TextInputMenuDialogScalarDeletingDestructor](by-memory/0x00520d50-0x00520d98.TextInputMenuDialogScalarDeletingDestructor.md), replacing the previous reliance on the mixed [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md) aggregate for exact thunk/destructor boundaries.

## Constructor, Fields, And Packet Parse

Best current source-facing constructor shape:

```cpp
TextInputMenuDialog::TextInputMenuDialog(
    bool hasExtraString,
    const RectBounds& bounds,
    const unsigned char *packet,
    unsigned char merchantDialogType);
```

The second constructor argument is the project `RectBounds` source type, not a Win32 `RECT *outRect`; [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) initializes it with `InitDlgMerc2Bounds` / `InitRectBounds` before calling this constructor. The fourth constructor argument is stored into inherited merchant/dialog state at `+0x26c`; it is not the same field as the packet byte stored at `+0x278`. Keep the final source spelling on the base if [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md) owns that layout.

| Offset | Current source-facing name | Type and role |
| --- | --- | --- |
| inherited `+0x26c` | `m_merchantDialogType` / inherited `m_dialogKind` | Constructor argument owned by the merchant-dialog base layout. |
| inherited `+0x270` | `m_menuObjectId` | 32-bit server menu-object id owned by `MerchantDialogPane` and serialized in replies. |
| `+0x278` | `m_replyType` | Packet byte serialized after opcode `0x39`. |
| `+0x27a` | `m_selectedOptionId` | 16-bit option/choice id serialized in replies. |
| `+0x27c` | `m_hasExtraString` | Guard for appending the stored extra string. |
| `+0x280` | `m_extraString` | `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >`; initialized by the constructor and destroyed by the ordinary class destructor path. |

Constructor packet parse order:

1. Read one byte into `m_replyType`.
2. Read one big-endian dword into inherited `m_menuObjectId`.
3. Parse the merchant/object image descriptor for the object-image control.
4. Read a 16-bit text length and convert packet multibyte prompt text to wide text for the static prompt control.
5. If constructor `hasExtraString` is true, set `m_hasExtraString`, read a one-byte length-prefixed ANSI string through the PacketBuffer reader family, and store it in `m_extraString`; otherwise clear the flag.
6. Read one 16-bit option id into `m_selectedOptionId`.

Generated `source-3/simroot_v2/class_TextInputMenuDialog.cpp` remains negative evidence, not source truth. It uses plausible but unproven names such as `m_merchantType`, `m_merchantId`, and `m_optionIndex`, invents helpers such as `PacketReadByte`, `CopyBytes`, and `GetControlText`, emits compiler scalar-deleting destructor code, and uses a `MultiByteToWideChar(949)` spelling that is not proven by the current constructor documentation. Keep text conversion described as packet multibyte-to-wide prompt conversion until a fresh IDA pass proves a specific source constant.

## Control Ids And Button Behavior

| Control id | Source-facing name | Role |
| --- | --- | --- |
| `0` | `kBackgroundControlId` | `DLGMERC2` background image. |
| `1` | `kSubmitButtonId` / `kOkButtonId` | Submit typed text. |
| `2` | `kCancelButtonId` | Send the shared cancel/request packet through inherited `MerchantDialogPane::SendMenuRequestPacket`. |
| `3` | `kCloseButtonId` | Close without sending input. |
| `4` | `kObjectImageControlId` | Merchant/object image control. |
| `5` | `kPromptTextControlId` | Static prompt text. |
| `6` | `kInputEditControlId` | Text edit control. |

There is no evidence for a persistent `m_inputEditControl` member. The constructor creates and adds a `TextEditControlPane`; later methods fetch child control id `6` from the inherited `DialogPane` child-control host. Document the edit widget as a child control id and local variable, not as a `TextInputMenuDialog` field.

`OnControlCommand(int controlIndex, int notifyCode)` handles three source-visible command ids; the behavior below keys on `notifyCode`:

- `notifyCode == 1`: fetch edit control `6`, copy up to `0xff` / 255 wide characters, serialize opcode `0x39`, append optional `m_extraString`, append typed input through the wide-to-ANSI PacketBuffer writer, send through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md), then close.
- `notifyCode == 2`: call inherited `MerchantDialogPane::SendMenuRequestPacket`, sending shared cancel/request opcode `0x43`, then close.
- `notifyCode == 3`: close without a text reply.

`UpdateActionButton()` fetches control ids `1` and `6`; if the edit text is empty it deactivates submit through UID0003N6, otherwise it activates submit through UID0003N7. The empty-text predicate comes from UID00011H. `UpdateSubmitButtonState` and `ValidateInput` are retained only as superseded pre-vtable-slot aliases.

## Rejected Ownership And Source Routes

- `TextEditControlPane` ownership is rejected; text-edit helpers are callees and the dialog stores no persistent edit-control pointer.
- `PacketBuffer`, socket, or packet-sender ownership for [UID:000239][0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper](by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md) is rejected; packet helpers are callees while the opcode and payload fields are dialog-specific.
- `MerchantDialogPane` ownership is rejected for the opcode `0x39` reply helper; the base contributes inherited layout/action-string behavior, not this text-input parser and reply shape.
- `TextMenuItemList` pollution is rejected; it is a sibling list class used by `TextMenuDialog`, not the text-input owner.
- `ArgumentedMenuDialogs`, `ItemMenuDialogs`, and `SpellMenuDialogs` are rejected as owners for this class/helper; they share the broader merchant/menu dispatcher and opcode family but have separate class/file buckets.

## Destructor Source Policy

Generated names such as `ScalarDeletingDestructor`, `sub_520B29`, and `sub_520B34` are compiler/IDA artifacts. The source model should expose `TextInputMenuDialog::~TextInputMenuDialog()` and the inherited `EventHandler`/`TimerHandler` subobject layout only. The primary vtable slot `0x0061ee0c` points at the scalar deleting destructor `0x00520d50`; secondary and tertiary vtable slots `0x0061ee6c` and `0x0061ee9c` point at 0x0b-byte adjustor thunks that subtract `0xa0` and `0xa4` before tail-jumping to `0x00520d50`.

The scalar wrapper destroys the member at byte offset `0x280`, then continues through the inherited dialog-base cleanup path and optional scalar delete for the `0x284`-byte object. This supports a source declaration shape like a virtual ordinary destructor on `TextInputMenuDialog` plus a private/string-like member at `+0x280`, but it does not justify emitting wrapper/thunk C++ on the exact compiler-glue child pages. If the local type system is not ready for explicit inherited interface declarations, keep `EventHandler` and `TimerHandler` as high-confidence comments rather than forcing incomplete source headers.

The class-level C++ declaration above models only the source-authored class shape. Do not paste generated `ScalarDeletingDestructor(int flags)` or adjusted-this thunk bodies into this class page or the exact compiler-glue child pages.

## Cross-References

- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0000ES][TextMenuDialog](by-class/TextMenuDialog.md)
- [UID:0000ET][TextMenuItemList](by-class/TextMenuItemList.md)
- [UID:000239][0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper](by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md)
- [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadText](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadText.md)
- [UID:00011H][0x004988d0-0x00498dd0.TextEditControlPaneCore](by-memory/0x004988d0-0x00498dd0.TextEditControlPaneCore.md)
- [UID:0003N6][0x00494c10-0x00494c2a.ControlPaneDeactivate](by-memory/0x00494c10-0x00494c2a.ControlPaneDeactivate.md)
- [UID:0003N7][0x00494c30-0x00494c4a.ControlPaneActivate](by-memory/0x00494c30-0x00494c4a.ControlPaneActivate.md)
- [UID:0003YM][0x00575650-0x00575703.PacketBufferCursorAppendBigEndianHelpers](by-memory/0x00575650-0x00575703.PacketBufferCursorAppendBigEndianHelpers.md)
- [UID:0003YO][0x005757d0-0x00575a07.PacketBufferStringWriteHelpers](by-memory/0x005757d0-0x00575a07.PacketBufferStringWriteHelpers.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)

## Changes

- 2026-08-22 B002 UID0000OP implementation callback:
  - Rebased the inherited `MerchantDialogPane +0x270` field to sole current source name `m_menuObjectId` in constructor source, field/layout prose, packet behavior, and accepted reconciliation.
  - Preserved the complete 0x284 layout, reserved +0x274 dword, reply/option/flag/StringBase fields, virtual identities, and inherited no-argument request method; the derived H declaration does not redeclare the base field or method.
- 2026-08-21 B002 Gate 2A repair:
  - Replaced active stale virtual labels with accepted `OnControlCommand` and `UpdateActionButton`, and corrected cancel/request ownership to inherited `MerchantDialogPane::SendMenuRequestPacket` using inherited `m_dialogId`.
  - Reconciled the current generated route and exact one-pointer StringBase type, retained old names only in dated history, and removed the stale copied `proposed` claim-mapping table without removing technical evidence.
- 2026-06-25 B010 accepted [UID:000239][0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper](by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md) implementation sync:
  - Score unchanged at `88/88`.
  - Corrected the class declaration and method prose from `SendInputReply(const char *inputTextAnsi)` to `SendInputReply(const wchar_t *inputTextWide)`.
  - Preserved the optional stored `m_extraString` ANSI append through `0x005757d0` / `PacketBufferAppendAnsiString8`, corrected the raw helper's caller argument to `0x0051a4ea -> 0x00575850` / `PacketBufferAppendWideStringAsAnsi8`, and retained the no-direct-caller caveat for `OnButtonPress`.
- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md).
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed function starts for the constructor, button handler, validation method, adjustor thunks, and scalar deleting destructor at `0x005198e0`, `0x0051a280`, `0x0051a3e0`, `0x00520b29`, `0x00520b34`, and `0x00520d50`; the reply helper at `0x0051a420` remains a raw non-function helper inside the documented span. This page and parent [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md) both meet the 80/80 parent gate. The old no-C++ rationale was superseded by the active 85/85 first-draft policy during the B010 source-quality pass.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `82`.
- Evidence: the page documents text-input menu role, constructor/action/validate/reply-helper/destructor-thunk ranges, packet serialization, vtable family, and generated method-name caveats.
- 2026-06-11 A002 Batch166 destructor-glue split:
  - Before: `86/82`; the main behavior was documented, but the destructor-thunk evidence stayed inside a mixed island.
  - Changed to: `86/85`, with exact non-reconstructable children [UID:00037C][0x00520b29-0x00520b3e.TextInputMenuDialogDestructorThunks](by-memory/0x00520b29-0x00520b3e.TextInputMenuDialogDestructorThunks.md) and [UID:00037D][0x00520d50-0x00520d98.TextInputMenuDialogScalarDeletingDestructor](by-memory/0x00520d50-0x00520d98.TextInputMenuDialogScalarDeletingDestructor.md).
  - Evidence: the split records the `0x00520b29-0x00520b3e` adjustor pair, `0x00520d50-0x00520d98` scalar deleting destructor, vtable refs, and exact neighboring boundaries.
- 2026-06-21 Rule 26 incorporation:
  - Score unchanged at `86/85`.
  - Added source-facing destructor policy from B007: ordinary `~TextInputMenuDialog()` is the only source method to model; `ScalarDeletingDestructor`, `sub_520B29`, and `sub_520B34` are compiler/IDA artifacts; the destructor glue is proven by vtable slots `0x0061ee0c`/`0x0061ee6c`/`0x0061ee9c`, constructor vptr stores, subobject offsets `0xa0`/`0xa4`, member cleanup at `+0x280`, and object size `0x284`.
- 2026-06-21 B010 Rule 26 source-quality incorporation:
  - Raised `86/85` to `88/88`.
  - Added the active 85/85 gate analysis and first-draft class declaration; resolved source-facing field names for `+0x270`, `+0x278`, `+0x27a`, `+0x27c`, and `+0x280`; documented inherited `+0x26c` as merchant/dialog-base state; added control ids `0` through `6`; clarified `ValidateInput` as `UpdateSubmitButtonState`; separated the observed inline submit-button wide-to-ANSI path from the then-documented retained raw [UID:000239][0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper](by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md) `SendInputReply(const char *)` claim; recorded rejected owner routes; and retained the destructor-thunk/scalar-wrapper no-code policy. The 2026-06-25 [UID:000239][0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper](by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md) pass supersedes only that stale `const char *` caller-argument claim.

## B002 UID0000OP Accepted Whole-File Reconciliation

Exact 0x284 layout with inherited `m_menuObjectId +0x270` and request method, reserved +0x274, reply +0x278, option +0x27a, flag +0x27c, wide StringBase +0x280, position 30, CP_ACP, complete H/CPP.

### Exact Accepted Inventory Disposition

| ID | Exact identity / range | O/E/P | Historical pre-callback -> accepted current score and metadata | CPP/H/compiler and generated disposition | Destination / claim |
| --- | --- | --- | --- | --- | --- |
| I026 | `TextInputMenuDialog` constructor `[0x005198e0,0x0051a276)`, SHA256 `5B359AF02028C9613F544FB5ACA93BDD8820D7BD51F535AF82BFF00414180E28` | O `0000OP`; E `0000OP`; P `0000ER` | UID0000ER `88/88 -> 94/94`; true; position blank -> `30` | UID0000ER CPP/H; D25850 definition and class H absent, callback emits both | UID0000ER / C040 |
| I027 | `TextInputMenuDialog::OnControlCommand [0x0051a280,0x0051a3d5)`, SHA256 `B8BB3FCC44E551653FFE8AC012505494F38E33B79F8C9561C20F57475156892E` | O `0000OP`; E `0000OP`; P `0000ER` | UID0000ER `88/88 -> 94/94`; true; position blank -> `30` | UID0000ER CPP/H; D25850 definition absent, callback emits exact handler | UID0000ER / C041 |
| I028 | `TextInputMenuDialog::UpdateActionButton [0x0051a3e0,0x0051a417)`, SHA256 `BF50AA0FDAFBD41C49B1C55F45807F906FD1FC605DB8318DC5B66AF90516B168` | O `0000OP`; E `0000OP`; P `0000ER` | UID0000ER `88/88 -> 94/94`; true; position blank -> `30` | UID0000ER CPP/H; D25850 definition absent, callback emits exact handler | UID0000ER / C042 |
| I029 | raw retained `TextInputMenuDialog::SendInputReply [0x0051a420,0x0051a51c)`, SHA256 `0178A271A9088C87DA9EFBFF60F81AD248E5C2C16F1C3A4B804B85C3768D75DC` | O `0000ER`; E `0000ER`; P `0000ER` | UID000239 `90/89 -> 93/94`; true; position follows class `30` | child CPP; no H; D25850 body present outside complete class route; callback preserves and routes it; IDA AP only | UID000239 / C043 |
| I055 | public `TextInputMenuDialog`, size `0x284` | O `0000OP`; E `0000OP`; P `0000ER` | UID0000ER `88/88 -> 94/94`; true; position `30` | H plus CPP; D25850 class and definitions absent, callback emits complete pair | UID0000ER / C010 |

### Exact Caller / Xref Disposition

| ID | Exact inbound code set/count | Exact inbound data set/count | Exact outgoing call disposition |
| --- | --- | --- | --- |
| I026 | `{51757b,5175c9,517929,5179b9}` / 4 | `{}` / 0 | targets `{5c7740,49d8a0,582a80,516030,575470,5754c0,4d1f30,575480,516220,60d120,575a90,582bb0,582b30,4b7c50,4f4aa0,4991f0,49dc10,495bf0,520540,499030,498920,49fc00,49dd80,49ddd0,544bd0,49db60,5446b0,49dfd0,49e190,5c772f,5c7655}` |
| I027 | `{}` / 0 | `{61ee54}` / 1 | targets `{517ec0,5c772f,498c10,516030,575650,5756d0,575670,584540,5757d0,575850,574bb0,49dad0}` |
| I028 | `{}` / 0 | `{61ee58}` / 1 | target `{498c60}` |
| I029 | `{}` / 0 | `{}` / 0 | calls `51a43a->516030,51a459->575650,51a474->575650,51a48d->5756d0,51a4a8->575670,51a4cd->584540,51a4d3->5757d0,51a4ea->575850,51a505->574bb0,51a511->5c772f` |
| I055 | not an address entity | not an address entity | source class; code call closure is I026-I029 |

The formal source channel above is authoritative. Older generated names and body-only sketches are dated provenance; compiler vtables, RTTI, adjustor thunks, and deleting wrappers are regenerated from ordinary source and are not handwritten. This is first-party NexusTK source, so no third-party import directive applies.
