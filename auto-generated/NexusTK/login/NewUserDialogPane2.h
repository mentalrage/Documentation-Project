// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LW
// Source by-file doc: by-file/NewUserDialogPane2.md
// UID:00009E | by-class/NewUserDialogPane2.md | Completion:93 | Confidence:95
#pragma once

#include "../ui/core/DialogPane.h"
#include "../util/Singleton.h"
#include "../util/StringBase.h"

class Event;
class NewUserDialogPane2;
extern NewUserDialogPane2 *g_pNewUserDialogPane2;

class NewUserDialogPane2 : public DialogPane,
                           public Singleton<NewUserDialogPane2>
{
public:
    NewUserDialogPane2();
    virtual ~NewUserDialogPane2() {}

protected:
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);

    void ShiftShapesLeft();
    void ShiftShapesRight();
    void SelectNation(int nation);
    void SelectTotem(short totem);
    void SelectShapeSlot(int slot);
    void SelectMaleMode();
    void SelectFemaleMode();
    void OpenNexonclubRegistrationOrSendCharacterRequest(bool openRegistration);
    void OnNexonclubRegistrationResult(
        const mystr::StringBase<
            wchar_t,
            mystr::mychar_traits<wchar_t> > &accountName);

    void SubmitCreateUser();
    void SendCreateCharacterRequest();
    bool HandleCreateUserReply(const unsigned char *packet);

private:
    int m_selectedNation;
    int m_selectedTotem;
    int m_selectedShapeSlot;
    bool m_waitingForCharacterReply;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >
        m_nexonclubAccountName;
};
