// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HH
// Source by-file doc: by-file/ArgumentedItemInputDialogs.md
// UID:0001BT | by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md | Completion:92 | Confidence:94
// Exact method definitions for this aggregate are emitted by the
// ArgumentedItemQuantityInputDialogPane and
// ArgumentedItemConfirmInputDialogPane class-owned children below.
// Do not emit a monolithic body for [0x0051fc90,0x00520539).

// UID:00000G | by-class/ArgumentedItemQuantityInputDialogPane.md | Completion:92 | Confidence:94
#include "ArgumentedItemInputDialogs.h"

#include "AlertPanes.h"
#include "ArgumentedMenuDialogs.h"
#include "../MainUiGraph.h"
#include "../controls/ButtonControlPane.h"
#include "../controls/EPFImageControlPane.h"
#include "../controls/StaticTextControlPane.h"
#include "../controls/TextEditControlPane.h"
#include "../../localization/LanguageMan.h"
#include "../../map/BackPane.h"

#include <wchar.h>

namespace
{
enum
{
    kConfirmControlIndex = 1,
    kCancelControlIndex = 2,
    kTextEditControlIndex = 4,
    kConfirmButtonId = 14,
    kCancelButtonId = 22,
    kMaximumPurchaseQuantity = 100,
    kQuantityPromptStringId = 246
};
}

// UID:000554 | by-memory/0x0051fc90-0x0051ff6c.ArgumentedItemQuantityInputDialogPaneConstructor.md | Completion:92 | Confidence:94
ArgumentedItemQuantityInputDialogPane::ArgumentedItemQuantityInputDialogPane(
    const wchar_t *promptText,
    ArgumentedMenuMenuItemList *menuContext,
    unsigned int argumentId)
    : DialogPane(L"ArgumentQuantity", 0x13, 1)
{
    RectBounds bounds;

    InitRectBounds(&bounds, 0, 0, 239, 283);
    AddControl(new EPFImageControlPane(
        L"DLGEXC3.EPF", 0, 1, &bounds, L"PAL01.PAL"));

    InitRectBounds(&bounds, 50, 149, 113, 173);
    AddControl(new ImageButtonControlPane(kConfirmButtonId, &bounds));

    InitRectBounds(&bounds, 129, 149, 192, 173);
    AddControl(new ImageButtonControlPane(kCancelButtonId, &bounds));

    InitRectBounds(&bounds, 30, 60, 197, 72);
    AddControl(new StaticTextControlPane(
        promptText, false, 128, 0, &bounds, false, false));

    InitRectBounds(&bounds, 28, 111, 211, 123);
    AddControl(new TextEditControlPane(
        L"", true, 143, 0, &bounds,
        false, false, false, false, 1.0f, false));

    SetBackgroundResource(L"DLGEXC3.EPF", 0);
    SetFocusedControl(kConfirmControlIndex);
    SetPendingControl(kCancelControlIndex);
    SetHoverControl(kTextEditControlIndex);

    m_menuContext = new ArgumentedMenuMenuItemList(*menuContext);
    m_argumentId = argumentId;

    InitRectBounds(&bounds, 0, 0, 239, 283);
    OnCreate(&bounds, 0, NULL, g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pBackPane);
    SlideOpenVertical();
}

// UID:000555 | by-memory/0x0051ff70-0x005200c4.ArgumentedItemQuantityInputDialogPaneOnControlCommand.md | Completion:93 | Confidence:94
void ArgumentedItemQuantityInputDialogPane::OnControlCommand(
    int controlIndex,
    int notifyCode)
{
    (void)notifyCode;

    if (controlIndex == kConfirmControlIndex) {
        if (m_menuContext != NULL) {
            wchar_t quantityText[128];
            int quantity = 0;
            TextEditControlPane *quantityEdit =
                GetChild<TextEditControlPane>(kTextEditControlIndex);

            quantityEdit->ReadText(quantityText, 128);
            swscanf(quantityText, L"%d", &quantity);

            if (static_cast<unsigned int>(quantity) >
                kMaximumPurchaseQuantity) {
                new AlertPane(
                    L"You can't buy more than 100.", this, L"OK", NULL);
            } else if (quantity == 0) {
                new AlertPane(L"How much?", this, L"OK", NULL);
            } else {
                m_menuContext->SendArgumentedItemQuantityPacket(
                    m_argumentId,
                    static_cast<unsigned char>(quantity));
            }
        }

        SlideCloseVertical();
        CloseDialog();
        return;
    }

    if (controlIndex == kCancelControlIndex) {
        SlideCloseVertical();
        CloseDialog();
    }
}

// UID:000556 | by-type/by-struct/ArgumentedItemQuantityInputDialogPaneLayout.md | Completion:92 | Confidence:94
// ArgumentedItemQuantityInputDialogPane's layout is expressed by its class declaration;
// no standalone source object is emitted for this evidence-only layout page.

// UID:00000F | by-class/ArgumentedItemConfirmInputDialogPane.md | Completion:92 | Confidence:94
// UID:000557 | by-memory/0x005200d0-0x005203be.ArgumentedItemConfirmInputDialogPaneConstructor.md | Completion:92 | Confidence:94
ArgumentedItemConfirmInputDialogPane::ArgumentedItemConfirmInputDialogPane(
    const wchar_t *promptText,
    ArgumentedMenuMenuItemList *menuContext,
    unsigned int maxQuantity,
    unsigned int expectedPrice,
    unsigned int argumentId)
    : DialogPane(L"ArgumentQuantity", 0x13, 1)
{
    RectBounds bounds;

    m_maxQuantity = maxQuantity;
    m_expectedPrice = expectedPrice;
    m_argumentId = argumentId;

    InitRectBounds(&bounds, 0, 0, 239, 283);
    AddControl(new EPFImageControlPane(
        L"DLGEXC3.EPF", 0, 1, &bounds, L"PAL01.PAL"));

    InitRectBounds(&bounds, 50, 149, 113, 173);
    AddControl(new ImageButtonControlPane(kConfirmButtonId, &bounds));

    InitRectBounds(&bounds, 129, 149, 192, 173);
    AddControl(new ImageButtonControlPane(kCancelButtonId, &bounds));

    InitRectBounds(&bounds, 30, 45, 210, 81);
    AddControl(new StaticTextControlPane(
        promptText, false, 128, 0, &bounds, false, false));

    InitRectBounds(&bounds, 28, 111, 211, 123);
    AddControl(new TextEditControlPane(
        L"", true, 143, 0, &bounds,
        false, false, false, false, 1.0f, false));

    SetBackgroundResource(L"DLGEXC3.EPF", 0);
    SetFocusedControl(kConfirmControlIndex);
    SetPendingControl(kCancelControlIndex);
    SetHoverControl(kTextEditControlIndex);

    m_menuContext = new ArgumentedMenuMenuItemList(*menuContext);

    InitRectBounds(&bounds, 0, 0, 239, 283);
    OnCreate(&bounds, 0, NULL, g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pBackPane);
    SlideOpenVertical();
}

// UID:000558 | by-memory/0x005203c0-0x00520539.ArgumentedItemConfirmInputDialogPaneOnControlCommand.md | Completion:93 | Confidence:94
void ArgumentedItemConfirmInputDialogPane::OnControlCommand(
    int controlIndex,
    int notifyCode)
{
    (void)notifyCode;

    if (controlIndex == kConfirmControlIndex) {
        if (m_menuContext == NULL)
            return;

        wchar_t priceText[128];
        int enteredPrice = 0;
        TextEditControlPane *priceEdit =
            GetChild<TextEditControlPane>(kTextEditControlIndex);

        priceEdit->ReadText(priceText, 128);
        swscanf(priceText, L"%d", &enteredPrice);

        if (static_cast<unsigned int>(enteredPrice) != m_expectedPrice) {
            new AlertPane(L"Price is different.", this, L"OK", NULL);
            return;
        }

        if (m_maxQuantity <= 1) {
            m_menuContext->SendArgumentedItemQuantityPacket(m_argumentId, 1);
        } else {
            new ArgumentedItemQuantityInputDialogPane(
                g_pLanguageMan->GetLocalizedString(kQuantityPromptStringId),
                m_menuContext,
                m_argumentId);
        }

        SlideCloseVertical();
        CloseDialog();
        return;
    }

    if (controlIndex == kCancelControlIndex) {
        SlideCloseVertical();
        CloseDialog();
    }
}

// UID:000559 | by-type/by-struct/ArgumentedItemConfirmInputDialogPaneLayout.md | Completion:92 | Confidence:94
// ArgumentedItemConfirmInputDialogPane's layout is expressed by its class declaration;
// no standalone source object is emitted for this evidence-only layout page.

// UID:00055A | by-memory/0x0061f584-0x0061f6bc.ArgumentedItemInputDialogVtableData.md | Completion:92 | Confidence:95
// ArgumentedItemQuantityInputDialogPane and
// ArgumentedItemConfirmInputDialogPane vtables, RTTI, deleting-destructor
// wrappers, and adjustor thunks are generated by the class declarations and
// compiler. Do not emit raw ABI arrays for [0x0061f584,0x0061f6bc).

// UID:00055B | by-memory/0x0061f99c-0x0061fa3c.ArgumentedItemInputDialogStrings.md | Completion:92 | Confidence:95
// [0x0061f99c,0x0061fa3c) is covered by the source literals in the exact
// constructor and OnControlCommand definitions. Do not emit duplicate arrays.

// UID:00055C | by-type/by-vtable/ArgumentedItemInputDialogVtables.md | Completion:92 | Confidence:95
// Argumented-item input-dialog vtables and RTTI are compiler-generated from the
// class declarations; do not emit handwritten ABI arrays or wrapper bodies.
