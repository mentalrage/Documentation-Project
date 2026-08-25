// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IJ
// Source by-file doc: by-file/CreateUserDialogPane.md
// UID:00003B | by-class/CreateUserDialogPane.md | Completion:93 | Confidence:94
#pragma once

#include "../ui/core/DialogPane.h"
#include "../util/Singleton.h"
#include "../util/StringBase.h"

class Event;
class KeyEvent;
class CreateUserDialogPane;
extern CreateUserDialogPane *g_pCreateUserDialogPane;

class CreateUserDialogPane : public DialogPane,
                             public Singleton<CreateUserDialogPane>
{
public:
    CreateUserDialogPane();
    virtual ~CreateUserDialogPane() {}

    void SelectBodyShape(short bodyShapeIndex);
    void SelectMale();
    void SelectFemale();
    unsigned char SetHairColorIndex(unsigned char colorIndex);
    unsigned char SetFaceColorIndex(unsigned char colorIndex);

protected:
    void OpenNexonclubRegistrationOrSendCharacterRequest(bool openRegistration);
    void OnNexonclubRegistrationResult(
        const mystr::StringBase<
            wchar_t,
            mystr::mychar_traits<wchar_t> > &text);

    virtual void OnDialogAction(int commandId, int action);
    virtual bool OnKeyEvent(KeyEvent *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual bool OnDialogShow(int reason);

    void SubmitCreateUser();
    void SendCreateCharacterRequest();
    bool HandleCreateUserReply(const unsigned char *packet);

private:
    int m_initialAppearanceRoll;
    int m_bodyShapeIndex;
    bool m_waitingForCharacterReply;
    bool m_isFemale;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >
        m_createUserExtraText;
};
