*** UID:00006R | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:010 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "InventoryPane.h"

#include <wchar.h>

#include "../MainUiGraph.h"
#include "../../config/Config.h"
#include "../InterfaceEfx.h"
#include "../controls/HelpPanes.h"
#include "../core/Event.h"
#include "../core/RectBounds.h"
#include "../panels/UserPane.h"
#include "../../network/PacketBuffer.h"
#include "../../network/Socket.h"
#include "../../render/EPFTileContext.h"
#include "../../render/ImageLib.h"
#include "../../render/ItemObjImageLib.h"

namespace
{
const int kInventorySlotCount = 52;
const int kLegacyPageSize = 15;
const int kCompactPageSize = 9;
const int kListView = 0;
const int kGridView = 1;
const int kButtonNormal = 0;
const int kButtonHover = 1;
const int kButtonPressed = 2;
const int kMouseDown = 1;
const int kMouseDoubleClick = 2;
const int kMouseDrag = 4;
const int kMouseMove = 8;
const int kKeyDown = 8;
const int kPageUp = 0x93;
const int kPageDown = 0x94;
}

InventoryPane::InventoryPane()
    : PanelPane(),
      m_pageIndex(0),
      m_isLastPage(false),
      m_viewMode(kListView),
      m_itemEffect(new InterfaceEfx(
          L"ITEMEFX.EPD", 50, 434, 12,
          g_mainUiLayerSlots.rootPaneLayerContext, false, L"INTEFX.PAD"))
{
}

InventoryPane::~InventoryPane()
{
    if (m_itemEffect != 0)
        m_itemEffect->MarkForDeletion();
}

void InventoryPane::OnActivate(const unsigned char *)
{
    InvalidateRect(&m_visibleBounds);
}

void InventoryPane::PlayItemEffect()
{
    if (m_itemEffect != 0)
        m_itemEffect->Play();
}

void InventoryPane::OnPaint()
{
    EPFTileContext background;
    EPFTileContext buttonFrame;
    g_pEPFLib->CopyEntryTileContext(L"ITEMINV.EPD", 0, &background);
    RenderTileFrame(&background, &background.bounds,
                    &m_visibleBounds, 0, L"NPAL6.PAL", 0);
    int visibleOrdinal = 0;
    int slot = 1;
    int drawn = 0;

    while (slot <= kInventorySlotCount)
    {
        const LocalInventorySlotRecord *item =
            g_pUserPane->GetInventorySlotAddress(static_cast<char>(slot));
        if (item->active && ++visibleOrdinal > m_pageIndex * kLegacyPageSize)
            break;
        ++slot;
    }

    for (; slot <= kInventorySlotCount && drawn < kLegacyPageSize; ++slot)
    {
        const LocalInventorySlotRecord *item =
            g_pUserPane->GetInventorySlotAddress(static_cast<char>(slot));
        if (!item->active)
            continue;

        RectBounds itemRect;
        GetSlotRect(drawn, &itemRect);
        if (m_viewMode == kGridView)
        {
            RectBounds drawBounds = itemRect;
            g_pItemObjImageLib->DrawItemImageIn43x43Slot(
                this, &drawBounds, item->itemId, item->iconStyle, 0, 0.0f);
        }
        else
        {
            RectBounds glyphBounds;
            g_pItemObjImageLib->GetItemGlyphBounds(item->itemId, &glyphBounds);
            RectBounds drawBounds = itemRect;
            g_pItemObjImageLib->DrawItemImage(
                this, &drawBounds, item->itemId, item->iconStyle, 0, 0.0f);
            MoveTo(itemRect.left + 24, itemRect.top);
            SetTextColor(0x25);
            DrawWideText(item->displayName,
                         static_cast<int>(wcslen(item->displayName)));
        }
        const wchar_t hotkey = slot <= 26 ? static_cast<wchar_t>(slot + 96)
                              : slot <= 52 ? static_cast<wchar_t>(slot + 38)
                                           : L' ';
        wchar_t hotkeyText[2] = { hotkey, 0 };
        MoveTo(itemRect.left + 1, itemRect.top + 11);
        SetTextColor(9);
        DrawWideText(hotkeyText, 1);
        ++drawn;
    }

    m_isLastPage = true;
    for (; slot <= kInventorySlotCount; ++slot)
    {
        if (g_pUserPane->GetInventorySlotAddress(static_cast<char>(slot))->active)
        {
            m_isLastPage = false;
            break;
        }
    }

    RectBounds buttonRect;
    if (m_pageIndex == 0)
    {
        GetButtonRect(0, &buttonRect);
        g_pEPFLib->CopyEntryTileContext(L"SPELLBUT.EPD", 12, &buttonFrame);
        RenderTileFrame(&buttonFrame, &buttonFrame.bounds,
                        &buttonRect, 0, L"NPAL6.PAL", 0);
    }
    if (m_isLastPage)
    {
        GetButtonRect(1, &buttonRect);
        g_pEPFLib->CopyEntryTileContext(L"SPELLBUT.EPD", 15, &buttonFrame);
        RenderTileFrame(&buttonFrame, &buttonFrame.bounds,
                        &buttonRect, 0, L"NPAL6.PAL", 0);
    }
    const int viewButton = m_viewMode == kGridView ? 3 : 2;
    GetButtonRect(viewButton, &buttonRect);
    g_pEPFLib->CopyEntryTileContext(
        L"SPELLBUT.EPD", m_viewMode == kGridView ? 14 : 13, &buttonFrame);
    RenderTileFrame(&buttonFrame, &buttonFrame.bounds,
                    &buttonRect, 0, L"NPAL6.PAL", 0);
}

bool InventoryPane::OnKeyEvent(Event *event)
{
    if (event->m_type != kEventKeyDown)
        return false;

    const int key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);
    if (key == kPageUp)
    {
        if (m_pageIndex > 0)
        {
            --m_pageIndex;
            InvalidateRect(&m_visibleBounds);
        }
        return true;
    }
    if (key == kPageDown)
    {
        if (!m_isLastPage)
        {
            ++m_pageIndex;
            InvalidateRect(&m_visibleBounds);
        }
        return true;
    }
    return false;
}

bool InventoryPane::OnMouseEvent(Event *event)
{
    if (g_pUserPane->IsInputLocked())
        return false;

    const int mouseX = event->m_payload.m_pointer.m_x;
    const int mouseY = event->m_payload.m_pointer.m_y;

    if (event->m_type == kMouseDrag)
    {
        const int hit = HitTestSlot(mouseX, mouseY);
        if (hit < 0 || hit >= kLegacyPageSize)
            return false;
        const int slot = VisibleOrdinalToInventorySlot(
            hit + kLegacyPageSize * m_pageIndex + 1);
        if (slot == -1)
            return false;

        unsigned char packet[10];
        PacketBufferWriteUInt8(0x66, packet);
        PacketBufferWriteUInt16BE(
            static_cast<unsigned short>(mouseX) & 0x3fff, packet + 1);
        PacketBufferWriteUInt8(0, packet + 3);
        PacketBufferWriteUInt8(1, packet + 4);
        PacketBufferWriteUInt8(1, packet + 5);
        PacketBufferWriteUInt8(static_cast<unsigned char>(slot), packet + 6);
        PacketBufferWriteUInt8(1, packet + 7);
        PacketBufferWriteUInt8(0, packet + 8);
        PacketBufferWriteUInt8(0, packet + 9);
        g_packetSender->QueueAndSendPacket(packet, 10);
        return true;
    }

    if (event->m_type == kMouseDown)
    {
        const int button = HitTestButton(mouseX, mouseY);
        bool changed = false;
        switch (button)
        {
        case 0:
            if (m_pageIndex > 0)
            {
                --m_pageIndex;
                changed = true;
            }
            break;
        case 1:
            if (!m_isLastPage)
            {
                ++m_pageIndex;
                changed = true;
            }
            break;
        case 2:
            m_viewMode = kListView;
            changed = true;
            break;
        case 3:
            m_viewMode = kGridView;
            changed = true;
            break;
        }
        if (changed)
        {
            InvalidateRect(&m_visibleBounds);
            return true;
        }
        if (g_pConfig->m_doubleClickEnabled)
            return false;
    }
    else if (event->m_type == kMouseDoubleClick)
    {
        if (!g_pConfig->m_doubleClickEnabled)
            return false;
    }
    else
    {
        return false;
    }

    const int hit = HitTestSlot(mouseX, mouseY);
    if (hit < 0 || hit >= kLegacyPageSize)
        return false;
    const int slot = VisibleOrdinalToInventorySlot(
        hit + kLegacyPageSize * m_pageIndex + 1);
    if (slot == -1)
        return false;
    g_pUserPane->UseInventorySlot(slot);
    return true;
}

bool InventoryPane::OnServerMessage(Event *message)
{
    const unsigned char *packet = static_cast<const unsigned char *>(
        message->m_payload.m_packet.m_data);
    const unsigned char opcode = packet[0];
    if (opcode < 0x0f)
        return false;
    if (opcode <= 0x10)
    {
        NotifyPaneMessageHandled(false);
        return false;
    }
    if (opcode != 0x59 || (packet[1] >> 6) != 0)
        return false;

    const int side = PacketBufferReadUInt16BE(packet + 1) & 0x3fff;
    const unsigned short textLength = PacketBufferReadUInt16BE(packet + 3);
    if (textLength >= 1 && textLength <= 1023)
    {
        wchar_t text[1024];
        const int count = MultiByteToWideChar(
            CP_ACP, 0, reinterpret_cast<const char *>(packet + 5),
            textLength, text, 1023);
        text[count] = 0;

        RectBounds bounds;
        GetBounds(&bounds);
        if (g_pSimpleHelpPane != 0)
            g_pSimpleHelpPane->Close(true);
        new SimpleHelpPane(
            text, this, (bounds.left + bounds.right) / 2, side, 10000);
    }
    return true;
}

void InventoryPane::GetButtonRect(int button, RectBounds *rect)
{
    static const RectBounds kRects[4] = {
        {59, 259, 81, 277}, {112, 259, 134, 277},
        {81, 259, 103, 277}, {104, 259, 112, 277}
    };
    if (button >= 0 && button < 4)
        *rect = kRects[button];
    else
        InitRectBounds(rect, -1, -1, -1, -1);
}

[[CHILDREN]]

int InventoryPane::HitTestSlot(int x, int y) const
{
    RectBounds rect;
    for (int slot = 0; slot != kLegacyPageSize; ++slot)
    {
        GetSlotRect(slot, &rect);
        if (PointInRect(y, x, &rect))
            return slot;
    }
    return -1;
}

int InventoryPane::VisibleOrdinalToInventorySlot(int ordinal)
{
    for (int slot = 1; slot <= kInventorySlotCount; ++slot)
    {
        if (!g_pUserPane->GetInventorySlotAddress(static_cast<char>(slot))->active)
            continue;
        if (--ordinal == 0)
            return slot;
    }
    return -1;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_INVENTORY_INVENTORYPANE_H
#define NEXUSTK_UI_INVENTORY_INVENTORYPANE_H

#include "../core/PanelPane.h"
#include "../core/Event.h"
#include "../core/RectBounds.h"

class InterfaceEfx;

class InventoryPane : public PanelPane
{
public:
    InventoryPane();
    virtual ~InventoryPane();

    virtual void OnActivate(const unsigned char *packetData);
    virtual void OnPaint();
    virtual bool OnKeyEvent(Event *event);
    virtual bool OnMouseEvent(Event *event);
    virtual bool OnServerMessage(Event *message);

private:
    void PlayItemEffect();
    static void GetButtonRect(int button, RectBounds *rect);
    void GetSlotRect(short slot, RectBounds *bounds) const;
    static int HitTestButton(int x, int y);
    int HitTestSlot(int x, int y) const;
    static int VisibleOrdinalToInventorySlot(int ordinal);

    unsigned char m_pageIndex;
    bool m_isLastPage;
    unsigned char m_reservedFA[2];
    int m_viewMode;
    InterfaceEfx *m_itemEffect;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# InventoryPane

## Status

- Completion/confidence: `93/94`; source-ready at whole-class scope with the retained no-route caveat on two raw helpers and complete inherited `GrafPort::m_visibleBounds` declaration closure.
- Likely source file: [UID:0000KA][InventoryPane](by-file/InventoryPane.md)
- Address range: [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md)
- Owner/emitter: [UID:0000KA][InventoryPane](by-file/InventoryPane.md), source position `010`.
- C++ emission: the formal CPP channel now owns the file preamble and A01-A09/A12-A13 definitions; `[[CHILDREN]]` inserts exact raw children [UID:00051B][0x004eb140-0x004eb1b4.InventoryPaneSlotRectBuilderRaw](by-memory/0x004eb140-0x004eb1b4.InventoryPaneSlotRectBuilderRaw.md) and [UID:00051H][0x004eb1c0-0x004eb291.InventoryPaneButtonHitTestRaw](by-memory/0x004eb1c0-0x004eb291.InventoryPaneButtonHitTestRaw.md) at positions `100/110`. The formal H channel owns the sole complete legacy declaration.

## Class Purpose

`InventoryPane` is the legacy player item inventory pane. It renders item slots in list or grid mode, pages through visible inventory entries, handles mouse item activation and drag-transfer packets, and displays server-provided item tooltip text through a help pane.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `InventoryPane` | `[0x004ea130,0x004ea202)` | A01/`010`; constructs `PanelPane`, creates the item `InterfaceEfx`, and initializes page/view state. |
| `~InventoryPane` | `[0x004ea210,0x004ea271)` | A02/`020`; marks the effect object for deletion and tears down the base pane. |
| `OnActivate` | `[0x004ea280,0x004ea28c)` | A03/`030`; ignores the packet and invalidates inherited `GrafPort::m_visibleBounds` at `+0x44`. |
| `PlayItemEffect` | `[0x004ea290,0x004ea29b)` | A04/`040`; plays the retained item effect helper. |
| `OnPaint` | `[0x004ea2a0,0x004ea945)` | A05/`050`; renders 15-entry list or 3x5 grid content and navigation/view controls. |
| `OnKeyEvent` | `[0x004ea950,0x004ea9cc)` | A06/`060`; consumes gated Page Up/Page Down changes. |
| `OnMouseEvent` | `[0x004ea9d0,0x004eac88)` | A07/`070`; handles buttons, item use/double-click policy, and opcode `0x66` drag send. |
| `OnServerMessage` | `[0x004eac90,0x004eae02)` | A08/`080`; handles bounded opcode `0x59` help text and 10-second popup lifetime. |
| `GetButtonRect` | `[0x004eb050,0x004eb126)` | A09/`090`; returns four exact navigation/view rectangles. |
| `GetSlotRect` | `[0x004eb140,0x004eb1b4)` | A10/`100`; UID00051B retained 116-byte raw child uses logical `short`, an unsigned 15-slot guard, exact 15-row/3x5 geometry, and one final `InitRectBounds` call. |
| `HitTestButton` | `[0x004eb1c0,0x004eb291)` | A11/`110`; UID00051H raw child tests the four fixed rectangles and returns `-1` on miss. |
| `HitTestSlot` | `[0x004eb2b0,0x004eb382)` | A12/`120`; applies slot geometry and `PointInRect` across 15 visible cells. |
| `VisibleOrdinalToInventorySlot` | `[0x004eb390,0x004eb414)` | A13/`130`; scans active one-based UserPane records and returns `0xff` when unmapped. |

The scalar deleting destructor `[0x004efaa0,0x004efb42)`, two destructor adjustors, switch tables, RTTI/vtables, and alignment spans are compiler-covered and do not add authored definitions. The zero-route release packet bodies `[0x004eae10,0x004eae70)` and `[0x004eae70,0x004eaf14)` duplicate behavior already emitted inline by `OnMouseEvent` and likewise do not emit.

## Field And Layout Notes

The class-specific tail starts at the `PanelPane` secondary view. IDA decompilation uses the secondary-view pointer for key/mouse methods, so `this[88]` in those methods is the class field at object offset `+0xf8` (248, verified with `int_convert.py`).

| Offset | Observed role | Evidence |
| --- | --- | --- |
| `+0x44` | inherited `GrafPort::m_visibleBounds` | `GrafPort.h` declares the protected `RectBounds` member; `Pane -> GrafPort` and `PanelPane -> Pane` provide the declaration route used by activation, paint, key, and mouse source. It is not an `InventoryPane` tail field and is not redeclared in the formal H block. |
| `+0xa0` | primary inventory vtable view | Constructor writes `InventoryPane::vftable`; destructor restores it. |
| `+0xa4` | secondary inventory vtable view | Constructor writes the second `InventoryPane::vftable`; destructor restores it. |
| `+0xf8` | current page index | Constructor clears the word at `+0xf8` (248, verified with `int_convert.py`); Page Up/Page Down and mouse button handlers decrement/increment it. |
| `+0xf9` | last-page/no-next-page flag | Paint sets this byte after scanning for remaining populated inventory records; Page Down and the next-page button test it before advancing. |
| `+0xfc` | view mode | Constructor clears this dword; mouse buttons `2` and `3` switch list/grid mode, and paint/hit-test branch on it. |
| `+0x100` | `InterfaceEfx` helper pointer | Constructor allocates `348` bytes (`0x15c`, verified with `int_convert.py`) and stores the `InterfaceEfx` object; scalar delete cleans it with `sub_544690`. |

## Interaction Details

- Paint renders up to `0xf` visible entries (`15`, verified with `int_convert.py`) per page. List mode draws icon, count, and text rows from `(58,30)` downward; grid mode uses a 3-column layout starting around `(72,40)`.
- `GetButtonRect` returns four fixed rectangles: previous page, next page, list mode, and grid mode.
- `HitTestSlot` mirrors the paint geometry: list mode maps 15 row rectangles from `x=30..160`, while grid mode maps 3-column cells from `x=40..75` plus row spacing.
- `MapVisibleSlotToInventorySlot` scans local inventory records through [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md) and returns the physical 1-based slot for the requested populated visible ordinal, or `0xff` when no populated slot maps. It reads `LocalInventorySlotRecord::active` rather than owning the storage table.
- Mouse input builds and sends a drag packet with opcode `0x66` (`102`, verified with `int_convert.py`) after a valid slot hit on event type `4`; the packet includes the masked mouse X coordinate, source/destination flags, physical slot, and fixed zero bytes.
- When the config double-click flag is set, event type `2` activates a slot immediately through `sub_5A3E30`; otherwise the same activation path is reached after no navigation button consumed the click.
- Server-message handling consumes packet opcode `0x59` (`89`, verified with `int_convert.py`) for tooltip text. It decodes a slot id and byte-counted string, converts it to wide text, positions the help pane at the pane midpoint, and uses a `10000` ms (`0x2710`, verified with `int_convert.py`) display duration.

## Evidence Notes

- 2026-06-11 IDA MCP `lookup_funcs` confirms the constructor/destructor/helpers at `0x004ea130`, `0x004ea210`, `0x004ea280`, `0x004ea290`, `0x004ea2a0`, `0x004ea950`, `0x004ea9d0`, `0x004eac90`, `0x004eb050`, `0x004eb2b0`, `0x004eb390`, and `0x004efaa0`.
- 2026-06-11 IDA MCP `xrefs_to` confirms `InventoryPane` primary/secondary vtable stores at `0x004ea172/0x004ea17c`, destructor restores at `0x004ea241/0x004ea24b`, and scalar-deleting-destructor restores at `0x004efad8/0x004efae2`.
- IDA MCP decompilation confirms the constructor allocates `InterfaceEfx`, stores the page/view/effect fields, the paint method's list/grid split, Page Up/Page Down handling, mouse navigation/view-mode/drag/activation paths, server tooltip message parsing, and fixed button/slot helper geometry.
- Dated 2026-08-15 B006 family evidence reconfirmed UID00051B's exact 116-byte low-word slot ABI and one-final-`InitRectBounds` call shape. UID0003EL has the same retained member template, and modeled NewInventoryPane rectangle code independently uses `__int16`; together they support the corrected class declaration without changing UID00051B's exact owner, range, score, or zero-route caveat.
- This class is item inventory UI and should not be merged into item image library code.

## Source Closure And Exclusions

The class is assigned only to [UID:0000KA][InventoryPane](by-file/InventoryPane.md). Its exact `010-130` route is complete and nonduplicative: eleven definitions live in this class block and the two raw definitions live in UID00051B/UID00051H beneath the single `[[CHILDREN]]` anchor. The class closes in H before any child definitions emit. UID00051B owns the sole `GetSlotRect(short, RectBounds *) const` definition at position `100`, while this formal H owns its sole declaration. All visible-bounds uses resolve through protected `GrafPort::m_visibleBounds` inherited by `Pane`, `PanelPane`, and `InventoryPane`; the formal H correctly declares no duplicate `+0x44` member.

NewInventoryPane, ScrollInventoryPane, all three BackPane help bodies, shared literal storage, vtable/RTTI data, switch tables, adjustors, scalar deleting destruction, and release-duplicate packet bodies remain under their documented source/compiler/resource owners. No alternate legacy emitter, standalone raw-helper source file, or descriptive rendering/packet wrapper is permitted.

Completion is `93` because all 13 authored definitions, layout fields, dependencies, behavior, compiler exclusions, source order, formal CPP/H, and exact raw children are closed. Confidence is `94`; stripped private lexical spellings and the raw-start reachability caveat remain documented but do not block source reconstruction.

## Cross-References

- [UID:0000KA][InventoryPane](by-file/InventoryPane.md)
- [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md)
- [UID:000093][NewInventoryPane](by-class/NewInventoryPane.md)
- [UID:00006S][InventoryPane2](by-class/InventoryPane2.md)
- [UID:00051B][0x004eb140-0x004eb1b4.InventoryPaneSlotRectBuilderRaw](by-memory/0x004eb140-0x004eb1b4.InventoryPaneSlotRectBuilderRaw.md)
- [UID:00051H][0x004eb1c0-0x004eb291.InventoryPaneButtonHitTestRaw](by-memory/0x004eb1c0-0x004eb291.InventoryPaneButtonHitTestRaw.md)

## Changes

- 2026-08-15 B006 UID0003EL accepted callback:
  - Corrected the directly affected UID00051B declaration to logical `short`, synchronized its method map and family ABI/one-final-InitRectBounds evidence, and preserved the child-owned CPP route. Class score `93/94`, owner/emitter, complete layout, authored inventory, and compiler exclusions remain unchanged.
- 2026-08-15 B001 accepted UID0000KA whole-file callback:
  - Raised `85/88 -> 93/94`, installed the complete formal CPP/H route, corrected the authored inventory to exactly A01-A13, added permanent raw children UID00051B/UID00051H at positions `100/110`, and historicalized scalar-delete/release-duplicate/compiler products as non-emitting.
  - Preserved exact page/view/effect fields, list/grid geometry, packet/help behavior, UserPane ownership, and the raw-start no-xref caveat.
- 2026-08-15 B001 UID0000KA inherited-bounds source-identity repair:
  - Replaced the undeclared provisional pane-local bounds spelling in formal CPP with inherited protected `GrafPort::m_visibleBounds`, documented its `+0x44` declaration/inheritance chain, kept the InventoryPane H layout free of a duplicate field, and made the retained `wcslen` declaration direct through `<wchar.h>`.

- 2026-06-21 Rule 26 support sync from B006 [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md):
  - Reframed visible-slot scanning through `LocalInventorySlotRecord::active` and kept storage accessor ownership with `LivingObjectPane`.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed inventory-pane methods at `0x004ea130`, `0x004ea210`, `0x004ea2a0`, `0x004ea950`, `0x004ea9d0`, `0x004eac90`, `0x004eb050`, `0x004eb2b0`, and `0x004efaa0`. Left `AUTOGEN_PARENT_UID` blank because this class is still below the 80 completion attachment gate.
- Completion/confidence score update: existed before as `0/0`; changed to `76/86`. Summary: legacy inventory-pane role, constructor/destructor, paint/key/mouse/server-message behavior, button/slot hit-tests, drag opcode, config flag, and module placement are documented with strong confidence; remaining work is deeper layout naming and final C++ reconstruction. Evidence: `InventoryPanes`, `NewInventoryPane`, `InventoryPane2`, and IDA-confirmed method boundaries.
- 2026-06-11 A008 Batch 155 strict-gate refresh:
  - Before: the page was `76/86`, reconstructable but unassigned, with only summary method notes and no field/interaction table.
  - Changed to: `85/88`, `AUTOGEN_PARENT_UID:0000KA`, field/layout notes for `+0xf8/+0xf9/+0xfc/+0x100`, detailed paint/input/server-message behavior, and explicit assignment-gate rationale.
  - Evidence: live IDA MCP `lookup_funcs`, `decompile`, `callers`, and `xrefs_to` confirmed the method boundaries, vtable stores/restores, list/grid geometry, navigation/view-mode fields, drag opcode `0x66`, tooltip opcode `0x59`, and `InterfaceEfx` allocation/cleanup. Numeric conversions were checked with `int_convert.py`.
