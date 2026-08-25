// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IX
// Source by-file doc: by-file/EditablePaperPane.md
// UID:000048 | by-class/EditablePaperPane.md | Completion:94 | Confidence:94
#pragma once

#include "DialogPane.h"

enum PaperOpenMode
{
    kPaperOpenEditable = 0,
    kPaperOpenReadOnly = 1
};

class EditablePaperPane : public DialogPane
{
public:
    EditablePaperPane(const unsigned char *packet, PaperOpenMode mode);

    virtual void OnControlCommand(int controlIndex, int notifyCode);

protected:
    virtual void DrawBackground();
    virtual void DrawBorder();
    virtual void InitializePaperContent(wchar_t *text);

private:
    void ParseEditablePacket(const unsigned char *packet);
    void ParseReadOnlyPacket(const unsigned char *packet);
    void SavePaperContent();

    unsigned char m_paperId;
    unsigned char m_packetStatusByte;
    signed char m_widthTiles;
    signed char m_heightTiles;
    short m_textLength;
    int m_reservedPaperState;
    PaperOpenMode m_paperMode;
    unsigned char m_centerText;
};

typedef char EditablePaperPaneSizeMustBe640[
    sizeof(EditablePaperPane) == 0x280 ? 1 : -1];
