*** UID:0000ES | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace {

class TextMenuPayloadReader {
public:
    explicit TextMenuPayloadReader(const unsigned char *payload)
        : m_cursor(payload)
    {
    }

    unsigned char ReadUInt8()
    {
        return *m_cursor++;
    }

    unsigned short ReadUInt16()
    {
        const unsigned short value = PacketBufferReadUInt16BE(m_cursor);
        m_cursor += 2;
        return value;
    }

    unsigned int ReadUInt32()
    {
        const unsigned int value = PacketBufferReadUInt32BE(m_cursor);
        m_cursor += 4;
        return value;
    }

    bool ReadObjectStatus(ObjectStatusBlob *status)
    {
        status->m_displayStatusByte = 0x50;
        const int length = status->ParseTaggedStatus(m_cursor);
        if (length < 0)
            return false;
        m_cursor += length + 4;
        return true;
    }

    void ReadAnsi16(wchar_t *out, unsigned int outCount)
    {
        const unsigned short length = ReadUInt16();
        char text[32768];
        memcpy(text, m_cursor, length);
        m_cursor += length;
        text[length] = '\0';
        const int count = MultiByteToWideChar(
            CP_ACP, 0, text, length, out, outCount - 1);
        out[count] = L'\0';
    }

    void ReadAnsi8(wchar_t *out, unsigned int outCount)
    {
        const unsigned char length = ReadUInt8();
        char text[256];
        memcpy(text, m_cursor, length);
        m_cursor += length;
        text[length] = '\0';
        const int count = MultiByteToWideChar(
            CP_ACP, 0, text, length, out, outCount - 1);
        out[count] = L'\0';
    }

    void ReadWideString8(
        mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > *out)
    {
        wchar_t text[256];
        ReadAnsi8(text, 256);
        *out = text;
    }

private:
    const unsigned char *m_cursor;
};

} // namespace

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "MerchantDialogPane.h"
#include "../../core/LObject.h"
#include "../../util/StringBase.h"

class DialogPane;
class TextMenuItemList;

class MerchantDialogCreator : public LObject
{
};

void CreateMerchantMenuDialog(const unsigned char *packet);
DialogPane *CreateTextMenuDialog(const unsigned char *payload);
DialogPane *CreateTextMenuDialogWithExtraString(const unsigned char *payload);
DialogPane *CreateTextInputMenuDialog(const unsigned char *payload);
DialogPane *CreateTextInputMenuDialogWithExtraString(const unsigned char *payload);
DialogPane *CreateServerItemMenuDialog(const unsigned char *payload);
DialogPane *CreateClientItemMenuDialog(const unsigned char *payload);
DialogPane *CreateServerSpellMenuDialog(const unsigned char *payload);
DialogPane *CreateClientSpellMenuDialog(const unsigned char *payload);
DialogPane *CreateArgumentedMenuDialog(const unsigned char *payload);

class TextMenuDialog : public MerchantDialogPane
{
public:
    TextMenuDialog(bool hasExtraString,
                   const RectBounds& bounds,
                   const unsigned char *payload,
                   unsigned char merchantDialogType);

    virtual void OnPaint();
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual void UpdateActionButton();

private:
    friend class TextMenuItemList;

    void SendMenuReply(unsigned short optionIndex);

    unsigned char m_replyType;             // +0x274
    unsigned char m_reserved275[3];        // +0x275
    unsigned char m_itemCount;             // +0x278
    bool m_hasExtraString;                 // +0x279
    mystr::StringBase<
        wchar_t, mystr::mychar_traits<wchar_t> > m_extraString; // +0x27c
    unsigned short m_itemIds[6];           // +0x280
};

typedef char TextMenuDialogSizeMustBe652[
    (sizeof(TextMenuDialog) == 0x28c) ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TextMenuDialog

## Status

- Confidence: accepted `94/94` for behavior, exact layout, method identities, source placement, and the generated `TextMenuDialogs.cpp/.h` route.
- Likely source file: [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- Main address range: [UID:0001BN][0x00517ec0-0x0051a417.TextMenuDialogs](by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md)
- Destructor/thunk range: [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md)
- Current generated files: `auto-generated/NexusTK/ui/dialogs/TextMenuDialogs.cpp` and `TextMenuDialogs.h`; the old `source-3/simroot_v2/class_TextMenuDialog.cpp` path is historical evidence only.

## Class Purpose

`TextMenuDialog` is a packet-driven NPC/merchant text menu. It parses a server packet for menu object id, subtype, portrait/object image data, text, optional extra string, and menu entries. It then builds either a small direct-button layout or a scrollable list layout and sends opcode `0x39` responses for selections.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| [UID:0004H8][0x00517ec0-0x00517f26.MerchantDialogPaneSendMenuRequestPacket](by-memory/0x00517ec0-0x00517f26.MerchantDialogPaneSendMenuRequestPacket.md) | inherited `MerchantDialogPane::SendMenuRequestPacket` | External support method inherited by this class; sends cancel/request packet opcode `0x43`, subtype `1`, with inherited `m_menuObjectId`, then closes the dialog. It is not a TextMenuDialogs-authored method. |
| [UID:0004H9][0x00517f30-0x00518e17.TextMenuDialogConstructor](by-memory/0x00517f30-0x00518e17.TextMenuDialogConstructor.md) | `TextMenuDialog` | Source-emitting constructor child; parses packet data, builds `DLGMERC1` EPD/EPF layouts, and creates `TextMenuItemList` when needed. |
| [UID:0004HA][0x00518e20-0x00519102.TextMenuDialogOnPaint](by-memory/0x00518e20-0x00519102.TextMenuDialogOnPaint.md) | `OnPaint` | Source-emitting paint child; draws the older tile-backed path. |
| [UID:0004HC][0x00519210-0x005194b1.TextMenuDialogOnDialogAction](by-memory/0x00519210-0x005194b1.TextMenuDialogOnDialogAction.md) | `OnControlCommand` | Source-emitting inherited-slot override; handles OK/cancel/close/menu selections and writes opcode `0x39` response payloads. The linked filename preserves the superseded `OnDialogAction` label only as history. |
| [UID:0004HD][0x005194c0-0x00519511.TextMenuDialogUpdateScrollButtons](by-memory/0x005194c0-0x00519511.TextMenuDialogUpdateScrollButtons.md) | `UpdateActionButton` | Source-emitting inherited-slot override; updates the action button after selection changes. The linked filename preserves the superseded `UpdateScrollButtons` label only as history. |
| [UID:0004HB][0x00519110-0x0051920c.TextMenuDialogRawSelectionReplySerializer](by-memory/0x00519110-0x0051920c.TextMenuDialogRawSelectionReplySerializer.md) | `SendMenuReply(unsigned short optionIndex)` | Retained source-emitting private overload; serializes opcode `0x39` for direct option selection, while the live small-menu call is compiler-inlined into UID0004HC. Target score/emitter are 93/94 and UID0000ES. |
| [UID:00037E][0x00520b3f-0x00520b54.TextMenuDialogDestructorThunks](by-memory/0x00520b3f-0x00520b54.TextMenuDialogDestructorThunks.md) | vtable adjustor thunks | Compiler-generated secondary/tertiary destructor adjustors: `this -= 0xa0` / `this -= 0xa4`, then tail-jump to `0x00520da0`. |
| [UID:00037F][0x00520da0-0x00520de8.TextMenuDialogScalarDeletingDestructor](by-memory/0x00520da0-0x00520de8.TextMenuDialogScalarDeletingDestructor.md) | scalar deleting destructor | Compiler-generated deleting-destructor wrapper; releases the provisional `+0x27c` text/string/LObject-backed member, runs inherited `DialogPane` cleanup, then handles delete flags. |

## Evidence Notes

- Wave3 summary: network-driven NPC text menu dialog that parses server packets and handles menu selections.
- Wave3 notes identify key fields: the inherited menu object id at `0x270`, reply subtype at `0x274`, item count at `0x278`, extra-string flag at `0x279`, `LObject` at `0x27c`, and menu item ids at `0x280`.
- IDA MCP confirms the main methods, vtable-referenced thunks, and destructor starts listed above.
- Direct callers of the constructor sit in the nearby dialog-packet dispatch area around `0x005174df`, `0x0051752d`, `0x00517809`, and `0x00517899`.
- B010 [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) resolves the source-facing factory constructor shape as `TextMenuDialog(bool hasExtraString, const RectBounds& bounds, const unsigned char *payload, unsigned char merchantDialogType)`. Subtypes `0` / `kTextMenu` and `1` / `kTextMenuWithExtraString` use `InitDlgMerc1Bounds` through `RectBounds`/`InitRectBounds`; the factory stays in [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md).
- B009 UID0001BN originally grouped UID0004H8 with this class's method island. That grouping is historical: current ownership places `MerchantDialogPane::SendMenuRequestPacket` under UID000083/UID0000L9, external to UID0000OP. The remaining exact TextMenuDialog children are UID0004H9, UID0004HA, UID0004HC (`OnControlCommand`), and UID0004HD (`UpdateActionButton`). Session `60724697` correctly found zero direct xrefs to UID0004HB; its then-current blank-C++ conclusion is superseded by the exact live inlined counterpart in UID0004HC.
- B006 UID0004HB source-quality reanalysis pairs target packet logic `0x0051915d-0x005191f2` with UID0004HC `0x00519293-0x00519330`. The private one-index overload owns the retained out-of-line definition; the existing three-argument overload remains separate support for the scrollable-list branch and is not UID0004HB's signature.
- B012 `TextMenuItemList` source-quality reanalysis ties the scrollable menu path back to this owner: the list constructor callers at `0x0051814d` and `0x005186d4` copy this dialog's `+0x274` reply type and inherited `m_menuObjectId +0x270` into the distinct list-local `TextMenuItemList +0x14c/+0x150` fields, store the owner pointer at list `+0x154`, and use `TextMenuItemListEntry` rows shaped as `unsigned short itemId` plus `wchar_t label[256]`.
- B005 UID0004HE and B006 UID0004HF reanalysis establish the scrollable source chain `TextMenuDialog::OnControlCommand -> TextMenuItemList::SendSelectedTextMenuReply -> TextMenuItemList::SendTextMenuReply(unsigned short itemId)`. The private explicit-id helper reads this dialog's `m_hasExtraString` at `+0x279` and `m_extraString` at `+0x27c`; no getter call survives. The existing narrow `friend class TextMenuItemList;` declaration is therefore the least-invented C++03 access relation and remains sufficient. UID0004HC calls the selected-row wrapper and then closes, while `[0x0051938f,0x00519492)` contains the complete transitive compiler-inline expansion of both list calls.
- 2026-06-11 Batch166 split review added exact non-reconstructable destructor-glue children [UID:00037E][0x00520b3f-0x00520b54.TextMenuDialogDestructorThunks](by-memory/0x00520b3f-0x00520b54.TextMenuDialogDestructorThunks.md) and [UID:00037F][0x00520da0-0x00520de8.TextMenuDialogScalarDeletingDestructor](by-memory/0x00520da0-0x00520de8.TextMenuDialogScalarDeletingDestructor.md), replacing the previous reliance on the mixed [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md) aggregate for exact thunk/destructor boundaries.
- B008 source-routing recheck confirms the ordinary source destructor belongs to this class/file owner, while the exact secondary/tertiary thunks and scalar deleting wrapper stay non-emitting compiler output. Current source identifies the owned member at `+0x27c` as `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >`; its ordinary destruction precedes normal base cleanup. Do not model raw thunk functions, scalar-wrapper flag tests, direct source `operator delete`, or guarded-size helper calls in class C++.

## Cross-References

- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)
- [UID:0004H8][0x00517ec0-0x00517f26.MerchantDialogPaneSendMenuRequestPacket](by-memory/0x00517ec0-0x00517f26.MerchantDialogPaneSendMenuRequestPacket.md)
- [UID:0004H9][0x00517f30-0x00518e17.TextMenuDialogConstructor](by-memory/0x00517f30-0x00518e17.TextMenuDialogConstructor.md)
- [UID:0004HA][0x00518e20-0x00519102.TextMenuDialogOnPaint](by-memory/0x00518e20-0x00519102.TextMenuDialogOnPaint.md)
- [UID:0004HB][0x00519110-0x0051920c.TextMenuDialogRawSelectionReplySerializer](by-memory/0x00519110-0x0051920c.TextMenuDialogRawSelectionReplySerializer.md)
- [UID:0004HC][0x00519210-0x005194b1.TextMenuDialogOnDialogAction](by-memory/0x00519210-0x005194b1.TextMenuDialogOnDialogAction.md)
- [UID:0004HD][0x005194c0-0x00519511.TextMenuDialogUpdateScrollButtons](by-memory/0x005194c0-0x00519511.TextMenuDialogUpdateScrollButtons.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0000ET][TextMenuItemList](by-class/TextMenuItemList.md)
- [UID:0000ER][TextInputMenuDialog](by-class/TextInputMenuDialog.md)
- [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md)

## Changes

- 2026-08-22 B002 UID0000OP implementation callback: selected inherited `MerchantDialogPane::m_menuObjectId +0x270` as the sole current source name across all seven caller families. This class inherits that field and `SendMenuRequestPacket()` without redeclaration; its 0x28c layout and all packet behavior are unchanged.
- 2026-08-21 B002 Gate 2A repair:
  - Replaced active stale method identities with accepted `OnControlCommand` and `UpdateActionButton`, and made UID0004H8 explicitly inherited from `MerchantDialogPane` rather than owned by TextMenuDialog.
  - Reconciled the current generated route and exact StringBase state, retained the old method/ownership wording only as dated history, and removed the stale copied `proposed` claim-mapping table without removing its technical evidence.
- 2026-08-15 B006 accepted UID0004HF support callback:
  - Preserved formal H, `friend class TextMenuItemList;`, and metadata `86/86` unchanged.
  - Replaced the stale independently unresolved UID0004HF prose with the resolved private explicit-id helper and transitive nested-inline relationship; no broader class claim changed.
- 2026-08-14 B005 accepted UID0004HE support callback:
  - Added `friend class TextMenuItemList;` to the formal H private section because the retained list method directly reads `m_hasExtraString` and `m_extraString` and no accessor route survives.
  - Documented the UID0004HC call/inline relationship; its then-current independently unresolved UID0004HF conclusion is retained as superseded history. Score remains `86/86`.
- 2026-08-13 B006 accepted UID0004HB source-quality callback:
  - Moved class and payload-reader declarations from the formal CPP channel into the formal H channel.
  - Added private `SendMenuReply(unsigned short optionIndex)` beside the independent three-argument overload.
  - Reclassified UID0004HB from blank no-route child to retained source-emitting helper at 93/94 with emitter UID0000ES, preserving B009's zero-xref finding as dated history.
- 2026-07-04 B009 accepted UID0001BN split/container callback:
  - Added formal class/support declaration C++ for the source-emitting exact child pages, keeping source method bodies on the child by-memory pages.
  - Updated the method map and cross-references to the real child UIDs [UID:0004H8][0x00517ec0-0x00517f26.MerchantDialogPaneSendMenuRequestPacket](by-memory/0x00517ec0-0x00517f26.MerchantDialogPaneSendMenuRequestPacket.md), [UID:0004H9][0x00517f30-0x00518e17.TextMenuDialogConstructor](by-memory/0x00517f30-0x00518e17.TextMenuDialogConstructor.md), [UID:0004HA][0x00518e20-0x00519102.TextMenuDialogOnPaint](by-memory/0x00518e20-0x00519102.TextMenuDialogOnPaint.md), [UID:0004HB][0x00519110-0x0051920c.TextMenuDialogRawSelectionReplySerializer](by-memory/0x00519110-0x0051920c.TextMenuDialogRawSelectionReplySerializer.md), [UID:0004HC][0x00519210-0x005194b1.TextMenuDialogOnDialogAction](by-memory/0x00519210-0x005194b1.TextMenuDialogOnDialogAction.md), and [UID:0004HD][0x005194c0-0x00519511.TextMenuDialogUpdateScrollButtons](by-memory/0x005194c0-0x00519511.TextMenuDialogUpdateScrollButtons.md).
  - Preserved the no-route policy for raw opcode `0x39` helper [UID:0004HB][0x00519110-0x0051920c.TextMenuDialogRawSelectionReplySerializer](by-memory/0x00519110-0x0051920c.TextMenuDialogRawSelectionReplySerializer.md); MCP session `60724697` found zero direct xrefs to the raw start.
- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md).
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the documented request helper, constructor, paint, action, scroll-button updater, adjustor thunks, and scalar deleting destructor at `0x00517ec0`, `0x00517f30`, `0x00518e20`, `0x00519210`, `0x005194c0`, `0x00520b3f`, `0x00520b4a`, and `0x00520da0`; this page and parent [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md) both meet the parent gate. Class-level formal C++ remains blank here to avoid duplicating exact child bodies and because final class/source-quality details remain open.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `84`.
- Evidence: the page documents packet-driven menu behavior, constructor/paint/action/update/destructor-thunk ranges, key fields, caller evidence, vtable family, and related text-input/list/dialog classes; confidence remains slightly capped by generated source name/control-character caveats.
- 2026-06-11 A002 Batch166 destructor-glue split:
  - Before: `86/84`; the main behavior was documented, but the destructor-thunk evidence stayed inside a mixed island.
  - Changed to: `86/86`, with exact non-reconstructable children [UID:00037E][0x00520b3f-0x00520b54.TextMenuDialogDestructorThunks](by-memory/0x00520b3f-0x00520b54.TextMenuDialogDestructorThunks.md) and [UID:00037F][0x00520da0-0x00520de8.TextMenuDialogScalarDeletingDestructor](by-memory/0x00520da0-0x00520de8.TextMenuDialogScalarDeletingDestructor.md).
  - Evidence: the split records the `0x00520b3f-0x00520b54` adjustor pair, `0x00520da0-0x00520de8` scalar deleting destructor, vtable refs, and exact neighboring boundaries.
- 2026-06-21 B008 Rule 26 source-routing sync:
  - Score unchanged at `86/86`.
  - Added ordinary-destructor source responsibility: [UID:00037E][0x00520b3f-0x00520b54.TextMenuDialogDestructorThunks](by-memory/0x00520b3f-0x00520b54.TextMenuDialogDestructorThunks.md) and [UID:00037F][0x00520da0-0x00520de8.TextMenuDialogScalarDeletingDestructor](by-memory/0x00520da0-0x00520de8.TextMenuDialogScalarDeletingDestructor.md) are non-emitting compiler output, while source C++ should model `TextMenuDialog::~TextMenuDialog()` releasing the provisional `+0x27c` member and relying on normal base cleanup.
- 2026-06-21 B012 Rule 26 source-quality support:
  - Score unchanged at `86/86`.
  - Added scrollable-list cross-reference for [UID:0000ET][TextMenuItemList](by-class/TextMenuItemList.md): mirrored `+0x270/+0x274` owner fields, `TextMenuItemListEntry` row id/label layout, selected-row opcode `0x39` serialization, and no-route policy for adjacent list raw helpers.
- 2026-06-28 B010 [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) support sync: score unchanged. Added the source-facing constructor shape using `const RectBounds& bounds` and recorded subtype `0/1` creation through the `TextMenuDialogs.cpp` factory.

## B002 UID0000OP Accepted Whole-File Reconciliation

Exact 0x28c layout with inherited `m_menuObjectId +0x270`, reply +0x274, wide StringBase +0x27c, six ids, one reply overload, local reader, position 10, and slots OnControlCommand/UpdateActionButton.

### Exact Accepted Inventory Disposition

| ID | Exact identity / range | O/E/P | Historical pre-callback -> accepted current score and metadata | CPP/H/compiler and generated disposition | Destination / claim |
| --- | --- | --- | --- | --- | --- |
| I015 | `TextMenuDialog` constructor `[0x00517f30,0x00518e17)`, SHA256 `AD46EB670E3749E68C35F92FD211D04FE39B2410604C2C2E19D3BBC0B9033E7F` | O `0000ES`; E `0000OP`; P `0000ES` | UID0004H9 `88/90 -> 94/94`; true; position follows class `10` | child CPP; H in UID0000ES; D25850 body present but composition/layout stale, callback repairs | UID0004H9 / C029 |
| I016 | `TextMenuDialog::OnPaint [0x00518e20,0x00519102)`, SHA256 `ABAE29159C70F5FDDD00B3486578765822A82767596F8047FAFE07EF8295D053` | O `0000ES`; E `0000OP`; P `0000ES` | UID0004HA `89/91 -> 94/94`; true; position follows class `10` | child CPP; declaration in UID0000ES H; D25850 body present, callback preserves resources and repairs topology | UID0004HA / C030 |
| I017 | retained `TextMenuDialog::SendMenuReply(unsigned short) [0x00519110,0x0051920c)`, SHA256 `1E9E70C505E2A76AB0DB1D26C6B30126009A9F96116B54B72831042FC7BB73A9` | O `0000ES`; E `0000ES`; P `0000ES` | UID0004HB `93/94 -> 94/94`; true; position follows class `10` | child CPP and one H declaration; D25850 body present with stale topology/call spelling, callback repairs | UID0004HB / C031 |
| I018 | `TextMenuDialog::OnControlCommand [0x00519210,0x005194b1)`, SHA256 `5A392B4E39A6AB238D3B14D9761719AA7D100BF6549FDFE197F3D40B8796F860` | O `0000ES`; E `0000OP`; P `0000ES` | UID0004HC `91/93 -> 94/94`; true; position follows class `10` | child CPP; declaration in UID0000ES H; D25850 old source name, callback renames/preserves body | UID0004HC / C032 |
| I019 | `TextMenuDialog::UpdateActionButton [0x005194c0,0x00519511)`, SHA256 `202D588F86F5B635DE0AAE3BD2A65622C491201870FEE0E2F2A3D32976412394` | O `0000ES`; E `0000OP`; P `0000ES` | UID0004HD `91/92 -> 94/94`; true; position follows class `10` | child CPP; declaration in UID0000ES H; D25850 old source name, callback renames/preserves body | UID0004HD / C033 |
| I050 | namespace-local `TextMenuPayloadReader` | O `0000OP`; E `0000OP`; P `0000ES` | UID0000ES `86/86 -> 94/94`; true; position `10` | CPP only; D25850 public/memberless reader defect, callback emits local implementation | UID0000ES / C009,C014 |
| I051 | empty LObject-derived `MerchantDialogCreator` | O `0000OP`; E `0000OP`; P `0000ES` | UID0000ES `86/86 -> 94/94`; true; position `10` | H declaration; compiler record covered by I048; D25850 declaration absent, callback emits | UID0000ES / C008,C046 |
| I052 | public `TextMenuDialog`, size `0x28c` | O `0000OP`; E `0000OP`; P `0000ES` | UID0000ES `86/86 -> 94/94`; true; position `10` | H plus child CPP; D25850 H incomplete/CPP declarations stale, callback replaces | UID0000ES / C009 |

### Exact Caller / Xref Disposition

| ID | Exact inbound code set/count | Exact inbound data set/count | Exact outgoing call disposition |
| --- | --- | --- | --- |
| I015 | `{5174df,51752d,517809,517899}` / 4 | `{}` / 0 | targets `{5c7740,49d8a0,582a80,516030,575470,5754c0,4d1f30,575480,516220,60d120,575a90,582bb0,582b30,4f4aa0,519520,4b7c50,4991f0,49dc10,495bf0,520540,499030,5cd657,4f3c50,4985a0,49fc00,49dd80,49ddd0,544bd0,4b7e10,519590,49db60,5446b0,49dfd0,49e190,5c772f,495450,5c7655}` |
| I016 | `{}` / 0 | `{61ecf0}` / 1 | targets `{457a60,4b9660,4d02f0,543d70,4b7c50,4b7e10,5c772f}`; data dependencies `69b3e8,69b3fc` are not calls |
| I017 | `{}` / 0 | `{}` / 0 | targets `{516030,575650,5756d0,575670,584540,5757d0,574bb0,5c772f,5c7655}` |
| I018 | `{}` / 0 | `{61ecf4}` / 1 | targets `{516030,575650,5756d0,575670,584540,5757d0,574bb0,5c772f,517ec0,4f3dc0,575380,5753f0,5753a0,49dad0,5c7655}` |
| I019 | `{}` / 0 | `{61ecf8}` / 1 | target `{4f3e20}` |
| I050 | not an address entity | not an address entity | namespace-local parser type; no independent instruction body or calls |
| I051 | not an address entity | not an address entity | source class; its compiler record is I048; no independent instruction body |
| I052 | not an address entity | not an address entity | source class; code call closure is I015-I019 |

The formal source channel above is authoritative. Older generated names and body-only sketches are dated provenance; compiler vtables, RTTI, adjustor thunks, and deleting wrappers are regenerated from ordinary source and are not handwritten. This is first-party NexusTK source, so no third-party import directive applies.
