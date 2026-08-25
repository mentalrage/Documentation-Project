// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000K7
// Source by-file doc: by-file/InputPanes.md
// UID:000077 | by-class/LineInputPane.md | Completion:93 | Confidence:94
#include "../core/BlackHole.h"
#include "InputPanes.h"
#include "../controls/TextEditPane.h"




// UID:00001P | by-class/CharInputPane.md | Completion:92 | Confidence:94

// UID:000364 | by-memory/0x004f2920-0x004f29ca.CharInputPaneHandleKeyOrTextEvent.md | Completion:92 | Confidence:94
bool CharInputPane::HandleKeyOrTextEvent(Event *event)
{
    const unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);

    if (event->m_type != kEventKeyDown)
        return true;

    if (key == kPaneKeyEscape)
        return LineInputPane::HandleKeyOrTextEvent(event);

    if (key >= ' ' && key <= '~') {
        event->m_type = kEventTextInput;
        event->m_payload.m_text.m_length = 1;
        event->m_payload.m_text.m_text[0] = key;

        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
        g_pUserPane->ClearActiveLineInputPane();
        LineInputPane::HandleKeyOrTextEvent(event);
        OnAccept();
        return true;
    }

    return key != kPaneKeyUp &&
           key != kPaneKeyDown &&
           key != kPaneKeyLeft &&
           key != kPaneKeyRight;
}


// UID:00035P | by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md | Completion:92 | Confidence:94
LineInputPane::LineInputPane(const wchar_t *promptText)
    : Pane(1),
      m_promptTextPane(NULL),
      m_textEditPane(NULL),
      m_deferredSubmitPending(0),
      m_deferSubmitUntilNextEvent(0)
{
    RectBounds paneBounds;
    RectBounds childBounds;
    short promptWidth = 0;

    if (g_useEpfAssets) {
        if (g_pUserPane->m_activeLineInputPane != NULL) {
            g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(
                g_pUserPane->m_activeLineInputPane);
        }

        if (promptText != NULL) {
            promptWidth = GetTextWidth(promptText, (int)wcslen(promptText)) + 1;
            m_promptTextPane = new TextBoxPane(
                promptWidth, 12, false, 128, 0, promptText);
        }

        const int editWidth = 593 - promptWidth;
        m_textEditPane = new TextEditPane(
            editWidth, 12, editWidth, 12, 128, 0,
            false, false, 0x100, IsLegacyAssetMode(), true, false);
        m_textEditPane->SetMaxLength(80);
        m_textEditPane->SetMaxLines(1);
        InitRectBounds(&paneBounds, 100, 733, 693, 745);
    } else {
        if (promptText != NULL) {
            promptWidth = GetTextWidth(promptText, (int)wcslen(promptText)) + 1;
            m_promptTextPane = new TextBoxPane(
                promptWidth, 12, false, 128, 143, promptText);
        }

        const int editWidth = 408 - promptWidth;
        m_textEditPane = new TextEditPane(
            editWidth, 12, editWidth, 12, 128, 143,
            false, false, 0x100, IsLegacyAssetMode(), true, false);
        m_textEditPane->SetMaxLength(50);
        m_textEditPane->SetMaxLines(1);
        InitRectBounds(&paneBounds, 14, 456, 422, 468);
    }

    AddToLayer(&paneBounds, 0, g_pBackPane, rootPaneLayerContext);

    if (m_promptTextPane != NULL) {
        m_promptTextPane->GetBounds(&childBounds);
        m_promptTextPane->AddToLayer(
            &childBounds, 0, this, rootPaneLayerContext);
    }

    m_textEditPane->GetBounds(&childBounds);
    childBounds.left = promptWidth;
    m_textEditPane->AddToLayer(
        &childBounds, 0, this, rootPaneLayerContext);

    SetPaneOrder(0, g_pBackPane);
    g_pEventDispatcher->ArmTextInputGuardTimer();

    if (g_useEpfAssets) {
        g_pUserPane->m_activeLineInputPane = this;
        g_pChattingVarietyPane->Refresh();
    }
}


// UID:00018Y | by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md | Completion:88 | Confidence:91
void LineInputPane::SetPromptText(const wchar_t *promptText)
{
    int promptLength = 0;
    while (promptText[promptLength] != L'\0')
        ++promptLength;

    const short promptWidth = GetTextWidth(promptText, promptLength);
    const int promptAdvance = promptWidth + 1;

    if (m_promptTextPane == NULL) {
        ShowChildren();

        const bool useEpfAssets = g_useEpfAssets != 0;
        m_promptTextPane = new TextBoxPane(
            promptAdvance,
            12,
            0,
            0x80,
            useEpfAssets ? 0 : 143,
            promptText);

        RectBounds editBounds;
        m_textEditPane->GetBounds(&editBounds);
        editBounds.left = promptAdvance;
        m_textEditPane->SetBounds(&editBounds, 0);

        RectBounds attachBounds;
        if (useEpfAssets)
            InitRectBounds(&attachBounds, 100, 733, 693, 745);
        else
            InitRectBounds(&attachBounds, 14, 456, 422, 468);

        AttachChild(&attachBounds, 0, g_pBackPane, rootPaneLayerContext, m_promptTextPane);
        return;
    }

    RectBounds promptBounds;
    m_promptTextPane->GetBounds(&promptBounds);
    promptBounds.right = promptBounds.left + promptAdvance;
    m_promptTextPane->SetBounds(&promptBounds, 0);

    RectBounds editBounds;
    m_textEditPane->GetBounds(&editBounds);
    editBounds.left = promptBounds.right;
    m_textEditPane->SetBounds(&editBounds, 0);

    m_promptTextPane->ClearText();
    m_promptTextPane->SetText(promptText, 0);
}

// UID:00035R | by-memory/0x004f2300-0x004f230f.LineInputPaneCopyText.md | Completion:88 | Confidence:90
void LineInputPane::CopyText(wchar_t *buffer, short maxChars) const
{
    m_textEditPane->CopyText(buffer, maxChars);
}

// UID:00035S | by-memory/0x004f2310-0x004f231b.LineInputPaneTextLength.md | Completion:88 | Confidence:90
short LineInputPane::TextLength() const
{
    return m_textEditPane->TextLength();
}











// UID:000035 | by-class/ConfirmInputPane.md | Completion:88 | Confidence:91
class FunctionObject0;

class ConfirmInputPane : public CharInputPane
{
public:
    ConfirmInputPane(const wchar_t *promptText, FunctionObject0 *acceptAction);
    virtual ~ConfirmInputPane();

private:
    FunctionObject0 *m_acceptAction; // +0x108; owned zero-argument accept callback.
};




// UID:0001N4 | by-memory/0x005b75d0-0x005b760e.ConfirmInputPaneConstructor.md | Completion:88 | Confidence:91
ConfirmInputPane::ConfirmInputPane(const wchar_t *promptText, FunctionObject0 *acceptAction)
    : CharInputPane(promptText),
      m_acceptAction(acceptAction)
{
}

// UID:00008T | by-class/MultiLineInputPane.md | Completion:88 | Confidence:90
struct InputKeyEvent;

class MultiLineInputPane : public LineInputPane
{
public:
    MultiLineInputPane(const wchar_t *promptText);
    virtual bool HandleKeyInput(InputKeyEvent *event);
};



// UID:00009J | by-class/NumberArgsInputPane.md | Completion:88 | Confidence:90
struct InputKeyEvent;

class NumberArgsInputPane : public LineInputPane
{
public:
    NumberArgsInputPane(const wchar_t *promptText);
    virtual bool OnKeyInput(InputKeyEvent *event);
};



// UID:00009L | by-class/NumberInputPane.md | Completion:88 | Confidence:90
struct InputKeyEvent;

class NumberInputPane : public LineInputPane
{
public:
    NumberInputPane(const wchar_t *promptText);
    virtual bool OnKeyInput(InputKeyEvent *event);
};



// UID:0001XS | by-type/by-vtable/InputPaneBaseVtableFamily.md | Completion:89 | Confidence:94
// The InputPane base-family vtables are compiler/linker output generated from
// the class declarations in this file. See [UID:000389][0x0061ca54-0x0061ce28.InputPaneBaseVtableData](by-memory/0x0061ca54-0x0061ce28.InputPaneBaseVtableData.md) for the concrete
// 0x0061ca54-0x0061ce28 data range; do not hand-author fixed vtable dwords here.

// UID:00001O | by-class\CharArgsInputPane.md | Completion:92 | Confidence:94 | Empty Emitter Marker

// UID:000367 | by-memory\0x004f2a60-0x004f2ad3.CharArgsInputPaneConstructor.md | Completion:86 | Confidence:88 | Empty Emitter Marker

// UID:000368 | by-memory\0x004f2ae0-0x004f2b74.CharArgsInputPaneKeyFilter.md | Completion:86 | Confidence:88 | Empty Emitter Marker

// UID:000363 | by-memory\0x004f28a0-0x004f2913.CharInputPaneConstructor.md | Completion:86 | Confidence:88 | Empty Emitter Marker

// UID:00036F | by-memory\0x004f2f70-0x004f2fab.CharInputPaneScalarDeletingDestructor.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:00035Q | by-memory\0x004f2010-0x004f2092.LineInputPaneCleanupBody.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:00035T | by-memory\0x004f2320-0x004f242f.LineInputPaneUpdateChildLayout.md | Completion:86 | Confidence:88 | Empty Emitter Marker

// UID:00035U | by-memory\0x004f2430-0x004f24b5.LineInputPaneAttachChildren.md | Completion:86 | Confidence:88 | Empty Emitter Marker

// UID:00035V | by-memory\0x004f24c0-0x004f24e5.LineInputPaneShowChildren.md | Completion:86 | Confidence:88 | Empty Emitter Marker

// UID:00035W | by-memory\0x004f24f0-0x004f257a.LineInputPaneHitTestForwarder.md | Completion:86 | Confidence:88 | Empty Emitter Marker

// UID:00035X | by-memory\0x004f2580-0x004f2598.LineInputPaneActiveChildForwarder.md | Completion:86 | Confidence:88 | Empty Emitter Marker

// UID:00035Y | by-memory\0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md | Completion:88 | Confidence:90 | Empty Emitter Marker

// UID:00035Z | by-memory\0x004f2760-0x004f2783.LineInputPaneTextEditForwarder.md | Completion:86 | Confidence:88 | Empty Emitter Marker

// UID:000360 | by-memory\0x004f2790-0x004f2791.LineInputPaneNoOpVirtual.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:00036D | by-memory\0x004f2dd0-0x004f2e59.LineInputPaneCompleteDestructor.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:00036E | by-memory\0x004f2ea0-0x004f2f63.LineInputPaneScalarDeletingDestructor.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:000365 | by-memory\0x004f29d0-0x004f2a05.ConfirmInputPaneCompleteDestructor.md | Completion:86 | Confidence:88 | Empty Emitter Marker

// UID:000366 | by-memory\0x004f2a10-0x004f2a58.ConfirmInputPaneInvokeAcceptedAction.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:00036G | by-memory\0x004f2fb0-0x004f3017.ConfirmInputPaneScalarDeletingDestructor.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:00036B | by-memory\0x004f2c90-0x004f2cc5.MultiLineInputPaneConstructor.md | Completion:86 | Confidence:88 | Empty Emitter Marker

// UID:00036C | by-memory\0x004f2cd0-0x004f2dcb.MultiLineInputPaneKeyHandler.md | Completion:86 | Confidence:88 | Empty Emitter Marker

// UID:000369 | by-memory\0x004f2b80-0x004f2bf3.NumberArgsInputPaneConstructor.md | Completion:86 | Confidence:88 | Empty Emitter Marker

// UID:00036A | by-memory\0x004f2c00-0x004f2c85.NumberArgsInputPaneKeyFilter.md | Completion:86 | Confidence:88 | Empty Emitter Marker

// UID:000361 | by-memory\0x004f27a0-0x004f2813.NumberInputPaneConstructor.md | Completion:86 | Confidence:88 | Empty Emitter Marker

// UID:000362 | by-memory\0x004f2820-0x004f289b.NumberInputPaneKeyFilter.md | Completion:86 | Confidence:88 | Empty Emitter Marker
