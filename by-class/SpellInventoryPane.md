*** UID:0000DN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:010 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "SpellInventoryPane.h"

#include <cwchar>

#include "../MainUiGraph.h"
#include "../InterfaceEfx.h"
#include "../core/Event.h"
#include "../core/RectBounds.h"
#include "../dialogs/SpellInputPanes.h"
#include "../dialogs/TargetSelectionInputPanes.h"
#include "../panels/UserPane.h"
#include "../../config/Config.h"
#include "../../map/LivingObjectPane.h"
#include "../../map/MapPane.h"
#include "../../network/PacketBuffer.h"
#include "../../network/Socket.h"
#include "../../render/EPFTileContext.h"
#include "../../render/ImageLib.h"

wchar_t SlotIndexToHotkeyLetter(int slot);

namespace
{
const int kSpellSlotCount = 52;
const int kSpellPageSize = 13;
const int kSpellClickableRows = 10;
}

SpellInventoryPane::SpellInventoryPane()
    : m_pageIndex(0),
      m_isLastPage(false),
      m_spellInputActive(false),
      m_spellEffect(new InterfaceEfx(
          L"MAGEFX.EPD", 50, 434, 12,
          g_mainUiLayerSlots.rootPaneLayerContext, false, L"INTEFX.PAD"))
{
}

SpellInventoryPane::~SpellInventoryPane()
{
    m_spellEffect->MarkForDeletion();
}

void SpellInventoryPane::OnActivate(const unsigned char *)
{
    m_pageIndex = 0;
    m_isLastPage = false;
    InvalidateRect(&m_visibleBounds);
}

void SpellInventoryPane::PlaySpellEffect()
{
    m_spellEffect->Play();
}

void SpellInventoryPane::OnPaint()
{
    EPFTileContext frame;
    g_pEPFLib->CopyEntryTileContext(L"SPELLINV.EPD", 0, &frame);
    RenderTileFrame(&frame, &frame.bounds,
                    &m_visibleBounds, 0, L"NPAL6.PAL", 0);

    int visibleOrdinal = 0;
    int slot = 1;
    while (slot <= kSpellSlotCount)
    {
        SpellCommandSlotRecord *record =
            g_pUserPane->GetSpellCommandSlotRecord((unsigned char)slot);
        if (record->active && ++visibleOrdinal > m_pageIndex * kSpellPageSize)
            break;
        ++slot;
    }

    Point textPoint;
    InitPointPair(&textPoint, 63, 35);
    SetDrawColor(0x80);
    SetDrawMode(1);
    int drawn = 0;
    for (; slot <= kSpellSlotCount && drawn < kSpellPageSize; ++slot)
    {
        SpellCommandSlotRecord *record =
            g_pUserPane->GetSpellCommandSlotRecord((unsigned char)slot);
        if (!record->active)
            continue;
        wchar_t text[128];
        swprintf_s(text, 128, L"%c: %s",
                   SlotIndexToHotkeyLetter(slot), record->displayName);
        MoveTo(textPoint.x, textPoint.y);
        DrawWideText(text, (int)wcslen(text));
        textPoint.y += 13;
        textPoint.x = 35;
        ++drawn;
    }

    m_isLastPage = true;
    for (; slot <= kSpellSlotCount; ++slot)
    {
        if (g_pUserPane->GetSpellCommandSlotRecord((unsigned char)slot)->active)
        {
            m_isLastPage = false;
            break;
        }
    }

    SetDrawColor(0x8f);
    SetDrawMode(2);
    RectBounds bounds;
    if (m_pageIndex == 0)
    {
        InitRectBounds(&bounds, 14, 221, 36, 239);
        g_pEPFLib->CopyEntryTileContext(L"SPELLBUT.EPD", 6, &frame);
        RenderTileFrame(&frame, &frame.bounds, &bounds, 0, L"NPAL6.PAL", 0);
    }
    if (m_isLastPage)
    {
        InitRectBounds(&bounds, 157, 221, 179, 239);
        g_pEPFLib->CopyEntryTileContext(L"SPELLBUT.EPD", 7, &frame);
        RenderTileFrame(&frame, &frame.bounds, &bounds, 0, L"NPAL6.PAL", 0);
    }
}

bool SpellInventoryPane::OnKeyEvent(Event *event)
{
    const int key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key, event->m_payload.m_key.m_modifiers);
    if (event->m_type != kEventKeyDown ||
        event->m_payload.m_key.m_modifiers != 0)
        return false;
    if (key == kPaneKeyPageUp)
    {
        if (m_pageIndex > 0)
        {
            --m_pageIndex;
            InvalidateRect(&m_visibleBounds);
        }
        return true;
    }
    if (key == kPaneKeyPageDown)
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

bool SpellInventoryPane::OnMouseEvent(Event *event)
{
    if (g_pUserPane->IsInputLocked())
        return false;

    const int y = event->m_payload.m_pointer.m_y;
    const int x = event->m_payload.m_pointer.m_x;
    bool handled = false;
    if (event->m_type == kEventLeftButtonDown)
    {
        const int button = HitTestPageButton(y, x);
        if (button == 0 && m_pageIndex > 0)
        {
            --m_pageIndex;
            handled = true;
        }
        else if (button == 1 && !m_isLastPage)
        {
            ++m_pageIndex;
            handled = true;
        }
        if (handled)
            InvalidateRect(&m_visibleBounds);
        if (!g_pConfig->m_doubleClickEnabled && !m_spellInputActive && !handled)
        {
            const int row = HitTestSpellRow(y, x);
            if (row >= 0)
            {
                const int slot = VisibleOrdinalToSpellSlot(
                    (short)(m_pageIndex * kSpellPageSize + row + 1));
                if (slot != -1)
                {
                    ActivateSpellSlot((unsigned char)slot);
                    return true;
                }
            }
        }
        return handled;
    }
    if (event->m_type == kEventLeftButtonDoubleClick &&
        g_pConfig->m_doubleClickEnabled && !m_spellInputActive)
    {
        const int row = HitTestSpellRow(y, x);
        if (row >= 0)
        {
            const int slot = VisibleOrdinalToSpellSlot(
                (short)(m_pageIndex * kSpellPageSize + row + 1));
            if (slot != -1)
            {
                ActivateSpellSlot((unsigned char)slot);
                return true;
            }
        }
    }
    return false;
}

bool SpellInventoryPane::OnServerMessage(Event *event)
{
    const unsigned char *packet = static_cast<const unsigned char *>(
        event->m_payload.m_packet.m_data);
    if ((unsigned char)(packet[0] - 23) <= 1)
        OnActivate(0);
    return false;
}

void SpellInventoryPane::ActivateSpellSlot(unsigned char spellSlot)
{
    if ((unsigned char)(spellSlot - 1) > 51)
        return;
    SpellCommandSlotRecord *record =
        g_pUserPane->GetSpellCommandSlotRecord(spellSlot);
    if (!record->active)
        return;

    switch (record->inputKind)
    {
    case 1:
        new SpellStringInputPane((char)spellSlot);
        m_spellInputActive = true;
        break;
    case 2:
        if (g_activeMapPane->m_selectedObjectActive &&
            g_activeMapPane->m_selectedObjectPane != 0)
        {
            LivingObjectPane *target = g_activeMapPane->m_selectedObjectPane;
            MapPoint position;
            target->GetMapPosition(&position);
            SendTargetedActionPacket(spellSlot,
                (unsigned int)target->GetObjectId(),
                (unsigned short)position.column,
                (unsigned short)position.row);
        }
        else
        {
            new SpellWhoInputPane((char)spellSlot);
            m_spellInputActive = true;
        }
        break;
    case 3:
        new SpellFourArgsInputPane((char)spellSlot);
        m_spellInputActive = true;
        break;
    case 4:
        new SpellThreeArgsInputPane((char)spellSlot);
        m_spellInputActive = true;
        break;
    case 5:
        SendDirectSpellPacket(spellSlot);
        m_spellInputActive = false;
        break;
    case 6:
        new SpellTwoArgsInputPane((char)spellSlot);
        m_spellInputActive = true;
        break;
    case 7:
        new SpellOneArgInputPane((char)spellSlot);
        m_spellInputActive = true;
        break;
    case 8:
        new SpellSlotInputPane((char)spellSlot);
        m_spellInputActive = true;
        break;
    }
}

void SpellInventoryPane::SendDirectSpellPacket(unsigned char spellSlot)
{
    unsigned char packet[3];
    PacketBufferWriteUInt8(0x0f, packet);
    PacketBufferWriteUInt8(spellSlot, packet + 1);
    packet[2] = 0;
    g_packetSender->QueueAndSendPacket(packet, 2);
}

void __stdcall SpellInventoryPane::BuildPageButtonRect(
    short button, RectBounds *bounds)
{
    if (button == 0)
        InitRectBounds(bounds, 14, 221, 36, 239);
    else if (button == 1)
        InitRectBounds(bounds, 157, 221, 179, 239);
    else
        InitRectBounds(bounds, -1, -1, -1, -1);
}

void __stdcall SpellInventoryPane::BuildSpellRowRect(
    short row, RectBounds *bounds)
{
    if ((unsigned short)row < kSpellPageSize)
        InitRectBounds(bounds, 22, 51 + 13 * row, 170, 64 + 13 * row);
    else
        InitRectBounds(bounds, -1, -1, -1, -1);
}

short __stdcall SpellInventoryPane::HitTestPageButton(int y, int x)
{
    for (short button = 0; button < 2; ++button)
    {
        RectBounds bounds;
        BuildPageButtonRect(button, &bounds);
        if (PointInRect(y, x, &bounds))
            return button;
    }
    return -1;
}

short __stdcall SpellInventoryPane::HitTestSpellRow(int y, int x)
{
    for (short row = 0; row < kSpellPageSize; ++row)
    {
        RectBounds bounds;
        BuildSpellRowRect(row, &bounds);
        if (PointInRect(y, x, &bounds))
            return row;
    }
    return -1;
}

int __stdcall SpellInventoryPane::VisibleOrdinalToSpellSlot(short visibleOrdinal)
{
    for (int slot = 1; slot <= kSpellSlotCount; ++slot)
    {
        if (!g_pUserPane->GetSpellCommandSlotRecord((unsigned char)slot)->active)
            continue;
        if (--visibleOrdinal == 0)
            return slot;
    }
    return -1;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_INVENTORY_SPELLINVENTORYPANE_H
#define NEXUSTK_UI_INVENTORY_SPELLINVENTORYPANE_H

#include "../core/PanelPane.h"
#include "../core/Event.h"
#include "../core/RectBounds.h"

class InterfaceEfx;

class SpellInventoryPane : public PanelPane
{
public:
    SpellInventoryPane();
    virtual ~SpellInventoryPane();

    virtual void OnActivate(const unsigned char *activationData);
    virtual void OnPaint();
    virtual bool OnKeyEvent(Event *event);
    virtual bool OnMouseEvent(Event *event);
    virtual bool OnServerMessage(Event *event);

private:
    void PlaySpellEffect();
    void ActivateSpellSlot(unsigned char spellSlot);
    void SendDirectSpellPacket(unsigned char spellSlot);
    static void __stdcall BuildPageButtonRect(short button, RectBounds *bounds);
    static void __stdcall BuildSpellRowRect(short row, RectBounds *bounds);
    static short __stdcall HitTestPageButton(int y, int x);
    static short __stdcall HitTestSpellRow(int y, int x);
    static int __stdcall VisibleOrdinalToSpellSlot(short visibleOrdinal);

    unsigned char m_pageIndex;
    bool m_isLastPage;
    bool m_spellInputActive;
    unsigned char m_reservedFB;
    InterfaceEfx *m_spellEffect;
};

typedef char SpellInventoryPane_size_must_be_0x100[
    sizeof(SpellInventoryPane) == 0x100 ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SpellInventoryPane

## UID0000O1 Accepted Class Reconstruction - 2026-08-22

This exact `0x100` legacy class is source-ready and emits first at position `010` through [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md). Its formal CPP owns the translation-unit includes/constants and all fifteen legacy definitions; its formal H opens the include guard and declares the complete class. [UID:0002RI][0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers](by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md) is now a non-emitting exact index.

The accepted source identities are constructor, ordinary destructor, `OnActivate`, `PlaySpellEffect`, `OnPaint`, `OnKeyEvent`, `OnMouseEvent`, `OnServerMessage`, `ActivateSpellSlot`, `SendDirectSpellPacket`, `BuildPageButtonRect`, `BuildSpellRowRect`, `HitTestPageButton`, `HitTestSpellRow`, and `VisibleOrdinalToSpellSlot`. `0x0057c410` is the primary-vtable `OnActivate`; `0x0057c440` operates on `InterfaceEfx *`; and opcodes 23/24 in `OnServerMessage` call `OnActivate`.

The exact tail layout after `PanelPane` is `m_pageIndex +0xf8`, `m_isLastPage +0xf9`, `m_spellInputActive +0xfa`, reserved byte `+0xfb`, and `InterfaceEfx *m_spellEffect +0xfc`, for total size `0x100`. UID0001II at `0x0057c430` remains an overlapping external `SpellInputPaneState` child and is not a class method. Dependencies and resource names in the formal source are references only; this class owns no standalone global/static storage or raw rdata array.

## Status

- Confidence: strong for behavior and inventory-module placement.
- Likely source file: [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md)
- Address range: legacy source-bearing core [UID:0002RI][0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers](by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md), with compiler scalar-wrapper refs in [UID:0002RL][0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors](by-memory/0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors.md). The broad [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md) parent is a non-emitting split/index.
- Current generated CPP/H: `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.cpp` and `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.h`.
- Historical path correction: `source-3/simroot_v2/class_SpellInventoryPane.cpp` was an earlier recovered-path assertion; that file does not exist and is not current generated authority.
- Current blocker: the legacy constructor at `0x0057c2d0` still has no direct xref or absolute pointer-pattern hit, so source placement is supported by vtables, neighboring spell-inventory family evidence, and method behavior rather than a live construction call.

## Class Purpose

`SpellInventoryPane` is the legacy player spell inventory pane. It displays up to 13 learned spells per page, handles page navigation and spell slot clicks, creates spell UI effects, and closes itself on relevant message commands.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SpellInventoryPane` | `0x0057c2d0-0x0057c39e` | Initializes `PanelPane`, vtables, page index, and spell effect interface. |
| `~SpellInventoryPane` | `0x0057c3a0-0x0057c400` | Resets vtables and marks spell effects for cleanup. |
| `OnActivate` | `0x0057c410-0x0057c424` | Primary-vtable activation resets page state and invalidates the pane. |
| external `SpellInputPaneState::SetInputModeFlag` | `0x0057c430-0x0057c43f` | Physically overlapping external helper owned by UID0000DM; not a `SpellInventoryPane` method. |
| `PlaySpellEffect` | `0x0057c440-0x0057c44a` | Invokes `InterfaceEfx::Play` through the constructor-created `m_spellEffect` pointer at `+0xfc`. |
| `OnPaint` | `0x0057c450-0x0057c70f` | Draws up to 13 spell entries with key bindings and page buttons. |
| `OnKeyEvent` | `0x0057c710-0x0057c78b` | Handles unmodified Page Up/Page Down events. |
| `OnMouseEvent` | `0x0057c790-0x0057c978` | Handles page navigation and single/double-click spell activation. |
| `OnServerMessage` | `0x0057c980-0x0057c9a7` | Calls `OnActivate` for packet opcodes 23/24 and returns false. |
| `ActivateSpellSlot` | `0x0057c9b0-0x0057cc41` | Validates one-based spell slots, dispatches eight input routes, sends targeted actions, or sends direct opcode `0x0f`. |
| `BuildPageButtonRect` | `0x0057ccd0-0x0057cd50` | Builds previous/next page-button rectangles for the mouse handler. |
| `HitTestSpellRow` | `0x0057ce70-0x0057cf02` | Tests the 13 visible spell-row rectangles and returns row index or `-1`. |
| `VisibleOrdinalToSpellSlot` | `0x0057cf10-0x0057cf6a` | Maps the visible row/page ordinal to the actual one-based spell slot by iterating learned slots `1..52`. |
| `ScalarDeletingDestructor` | `0x0057f6a0-0x0057f741` | MSVC scalar deleting destructor wrapper reached by vtables/adjustor thunks; do not emit as an ordinary handwritten source body. Ordinary cleanup is represented by the non-scalar destructor `0x0057c3a0-0x0057c400`. |

## Field Notes

| Offset | Best-supported role |
| --- | --- |
| `+0xf8` | `m_pageIndex`; `OnActivate` clears it, navigation changes it, and paint uses it to select the current 13-spell page. |
| `+0xf9` | `m_isLastPage`; paint sets it while scanning learned spells and key/mouse navigation blocks forward movement when it is true. |
| `+0xfa` | `m_spellInputActive`; prompt allocation paths set it and direct-send paths clear it. |
| `+0xfc` | `InterfaceEfx *m_spellEffect`; the constructor creates it and `PlaySpellEffect` forwards through it at `0x0057c440`. |

The earlier `m_currentPage`/`ResetPage`, alternative `m_noNextPage`, `m_pendingSpellInput`, and unresolved `+0xfc` concrete-type descriptions are superseded historical interpretations. The accepted formal CPP/H names and types above are current.

## Evidence Notes

- IDA MCP confirms the constructor, draw, mouse, and scalar deleting destructor boundaries.
- Wave3 notes place spell records in player data with stride `0x148` and up to 52 spell slots.
- This is spell inventory UI, not spell rendering or effect-object code.
- 2026-06-16 A002 live IDA refresh reconfirmed every legacy method start in [UID:0002RI][0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers](by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md): constructor `0x0057c2d0`, destructor `0x0057c3a0`, `OnActivate` `0x0057c410`, external state setter `0x0057c430`, `PlaySpellEffect` `0x0057c440`, draw `0x0057c450`, key `0x0057c710`, mouse/message `0x0057c790`/`0x0057c980`, dispatcher `0x0057c9b0`, and row/button helpers `0x0057ccd0`/`0x0057ce70`/`0x0057cf10`.
- `analyze_function(0x0057c2d0)` shows the constructor calls [UID:0000ME][PanelPane](by-file/PanelPane.md) construction support, installs the three legacy spell-inventory vtables, clears page/cast state fields at `+0xf8`/`+0xfa`, allocates a spell effect/interface object, and stores it at `this+0xfc`.
- `xrefs_to(0x0057c2d0)` remains empty and `find_bytes` found no absolute pointer hit for the legacy constructor start. This is a real reachability blocker for final source construction, but it no longer blocks the class score because the vtable stores, method family, scalar destructor refs, and spell dispatcher behavior all point to the same legacy class.
- B007 2026-06-19 source-quality reanalysis corrects the legacy dispatcher data view: `ActivateSpellSlot` reads canonical `g_pUserPane` / historical `dword_67A748` spell records at one-based `+0x13a6ec + 0x148 * slot`, with record-local `+0` as the learned/active byte and `+4` as the input type / cast route. Older `+0x13a82c` prose is stale for this body unless a later byte audit proves a distinct access.
- B011 2026-06-21 parent split/index recheck keeps generated `SpellManager` / `g_pSpellMan` interpretations rejected. Use local-player/UserPane typed spell-state language for `dword_67A748` / [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md), and keep exact spell-type enum names descriptive until a broader spell-type/packet pass resolves original names.
- `ActivateSpellSlot` dispatches cases through the eight-entry table at `0x0057cc44`: string input, targeted action or `SpellWhoInputPane`, four/three/two/one argument input panes, direct two-byte opcode `0x0f` packet sending, and slot input. Prompt panes remain dependencies owned by [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md) or [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md), not direct owners of this class method.
- The legacy child also contains retained no-route helper bodies at `0x0057cc70-0x0057ccd0`, `0x0057cd60-0x0057cdb3`, and `0x0057cdc0-0x0057ce68`. They document source-relevant direct packet sending and geometry behavior; the accepted UID0000DN formal CPP now owns their source-shaped helper definitions while UID0002RI remains a blank non-emitting physical index.

## Cross-References

- [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md)
- [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md)
- [UID:00009A][NewSpellInventoryPane](by-class/NewSpellInventoryPane.md)
- [UID:0000DO][SpellInventoryPane2](by-class/SpellInventoryPane2.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `86`.
- Evidence: the page documents pane behavior, source placement, main range, constructor/destructor/reset/draw/key/mouse/message/destructor methods, player spell-slot model, and sibling relationships; remaining completion gap is deeper field naming and source-ready C++.
- 2026-06-05: Marked reconstructable and attached to [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md).
- Evidence: live IDA MCP `lookup_funcs` confirms the documented spell inventory constructor, destructor, reset, draw, keyboard, mouse, message, and scalar deleting destructor anchors from `0x0057c2d0` through `0x0057f6a0`; both class (`84/86`) and parent file (`82/82`) meet the 80/80 gate.
- 2026-06-16 A002 file-root completion pass: Raised `84/86 -> 85/88` after a live IDA refresh reconfirmed the exact legacy method inventory, constructor behavior, vtable stores, dispatcher data flow, scalar-destructor route, and the unresolved but real zero-xref/zero-pointer legacy constructor blocker. C++ remains blank because final spell-field names, input-helper names, and constructor reachability are not yet source-quality.
- 2026-06-21 Rule 26 B007 legacy dispatcher sync:
  - Score unchanged at `85/88`.
  - Summary/evidence: incorporated the corrected `CastSpell` route table, class-field roles for `+0xf8/+0xf9/+0xfa/+0xfc`, stale `+0x13a82c` rejection in favor of `g_pUserPane + 0x13a6ec + 0x148 * slot`, no-route helper bodies at `0x0057cc70`, `0x0057cd60`, and `0x0057cdc0`, and the direct class-owner decision for [UID:0002RI][0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers](by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md).
- 2026-06-21 Rule 26 B011 parent split/index sync:
  - Score unchanged at `85/88`.
  - Summary/evidence: changed class wording to route ordinary source through [UID:0002RI][0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers](by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md) and treat `0x0057f6a0` as scalar deleting destructor compiler wrapper evidence rather than handwritten source. The broad [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md) parent is now a non-emitting split/index and should not be used as this class's C++ emission unit.
