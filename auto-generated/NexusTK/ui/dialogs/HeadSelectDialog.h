// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JT
// Source by-file doc: by-file/HeadSelectDialog.md
// UID:000062 | by-class/HeadSelectDialog.md | Completion:92 | Confidence:93
#include "../core/DialogPane.h"
#include "../../map/ObjectStatusBlob.h"

class ImageButtonControlPane;
class ObjectImageButtonPane;
class ObjectImageControlPane;

class HeadSelectDialog : public DialogPane
{
public:
    HeadSelectDialog(const unsigned char *packet);
    virtual ~HeadSelectDialog();

    virtual void OnAction(int actionId, int unused);

private:
    void RefreshHeadPreview();
    void UpdatePageButtonStates();
    void NextHeadPage();
    void PreviousHeadPage();
    void PopulateHeadButtons(int page, bool removeExistingButtons);

    unsigned char m_dialogSubtype;
    unsigned int m_headPrice;
    unsigned short m_npcId;
    unsigned short m_objectId;
    ObjectStatusBlob m_previewObject;
    int m_headCount;
    int m_selectedHead;
    int m_currentPage;
    int m_baseHeadDrawOffset;
    ObjectImageControlPane *m_previewPane;
    ObjectImageButtonPane *m_headButtons[10];
    ImageButtonControlPane *m_confirmButton;
    ImageButtonControlPane *m_nextPageButton;
    ImageButtonControlPane *m_prevPageButton;
};
