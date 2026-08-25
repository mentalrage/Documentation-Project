// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LP
// Source by-file doc: by-file/NewCreateUserDialogPane.md
// UID:00008Z | by-class/NewCreateUserDialogPane.md | Completion:90 | Confidence:92
#pragma once

#include "../ui/core/DialogPane.h"
#include "../util/Singleton.h"
#include "../util/StringBase.h"

class Event;
class NewCreateUserDialogPane;
extern NewCreateUserDialogPane *g_pNewCreateUserDialogPane;

class NewCreateUserDialogPane : public DialogPane,
                                public Singleton<NewCreateUserDialogPane>
{
public:
    NewCreateUserDialogPane();
    virtual ~NewCreateUserDialogPane() {}

protected:
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);

    void SelectGender(short genderOrNation);
    void SelectTotem(short totem);
    void SelectMale();
    void SelectFemale();
    void OpenNexonclubRegistrationOrSendCharacterRequest(bool openRegistration);
    void OnNexonclubRegistrationResult(
        const mystr::StringBase<
            wchar_t,
            mystr::mychar_traits<wchar_t> > &accountName);

    void SubmitCreateUser();
    void SendCreateCharacterRequest();
    bool HandleCreateUserReply(const unsigned char *packet);

private:
    int m_selectedGenderOrNation;
    int m_selectedTotem;
    int m_compatibilitySelectionState;
    bool m_waitingForCharacterReply;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >
        m_nexonclubAccountName;
};
