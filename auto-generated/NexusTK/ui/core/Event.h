// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000J6
// Source by-file doc: by-file/Event.md
// UID:00004L | by-class/Event.md | Completion:94 | Confidence:95
#ifndef NEXUSTK_UI_CORE_EVENT_H
#define NEXUSTK_UI_CORE_EVENT_H

#include "../../util/LObject.h"

enum PaneKeyCode
{
    kPaneKeyEscape = 0x1b,
    kPaneKeyLeft = 0x80,
    kPaneKeyUp = 0x81,
    kPaneKeyRight = 0x82,
    kPaneKeyDown = 0x83,
    kPaneKeyDelete = 0x84,
    kPaneKeyPageUp = 0x93,
    kPaneKeyPageDown = 0x94
};

enum EventModifierFlags
{
    kEventModifierAlt = 0x01,
    kEventModifierControl = 0x02,
    kEventModifierShift = 0x04
};

enum EventType
{
    kEventCursorMove = 0,
    kEventLeftButtonDown = 1,
    kEventLeftButtonDoubleClick = 2,
    kEventLeftButtonUp = 3,
    kEventRightButtonDown = 4,
    kEventRightButtonDoubleClick = 5,
    kEventRightButtonUp = 6,
    kEventMouseWheel = 7,
    kEventKeyDown = 8,
    kEventKeyUp = 9,
    kEventTextInput = 10,
    kEventImeOpenStatus = 11,
    kEventImeCompositionStart = 12,
    kEventImeCompositionResult = 13,
    kEventImeCompositionEnd = 14,
    kEventImeCandidateList = 15,
    kEventImeCandidateClose = 16,
    kEventImeReserved = 17,
    kEventPacket = 18,
    kEventApplicationNotification = 19,
    kEventDispatchSuppressed = 20,
    kEventSystemControl = 21,
    kEventWorkNotification = 22,
    kEventNone = 0xff
};

struct EventPointerPayload
{
    int m_y;
    int m_x;
    unsigned char m_modifiers;
    int m_detail;
    unsigned int m_messageTime;
};

struct EventKeyPayload
{
    unsigned char m_key;
    unsigned char m_reserved;
    wchar_t m_text[128];
    unsigned char m_modifiers;
    unsigned int m_messageTime;
};

struct EventTextPayload
{
    unsigned char m_inputCode;
    unsigned char m_length;
    wchar_t m_text[128];
    unsigned char m_modifiers;
    unsigned int m_messageTime;
};

struct EventCompositionPayload
{
    unsigned char m_subtype;
    unsigned char m_length;
    wchar_t m_text[128];
    unsigned char m_modifiers;
    unsigned int m_messageTime;
};

struct EventImeResultPayload
{
    unsigned char m_reserved;
    unsigned char m_length;
    wchar_t m_text[129];
    unsigned int m_messageTime;
};

struct EventImeOpenPayload
{
    int m_isOpen;
    unsigned char m_reserved[0x100];
    unsigned int m_messageTime;
};

struct EventCandidatePayload
{
    void *m_candidateList;
    int m_selectedRow;
    unsigned char m_reserved[0xfc];
    unsigned int m_messageTime;
};

struct EventPacketPayload
{
    unsigned char m_packetKind;
    void *m_data;
    unsigned int m_size;
};

struct EventNotificationPayload
{
    unsigned int m_channel;
    LObject *m_payload;
};

union EventPayload
{
    EventPointerPayload m_pointer;
    EventKeyPayload m_key;
    EventTextPayload m_text;
    EventCompositionPayload m_composition;
    EventImeResultPayload m_imeResult;
    EventImeOpenPayload m_imeOpen;
    EventCandidatePayload m_candidate;
    EventPacketPayload m_packet;
    EventNotificationPayload m_notification;
    unsigned char m_raw[0x108];
};

class Event : public LObject
{
public:
    Event();
    virtual ~Event();

    bool IsPointerEvent() const;
    bool IsKeyOrTextEvent() const;
    bool IsImeEvent() const;
    bool IsPacketEvent() const;
    bool IsSystemOrControlEvent() const;

    unsigned char m_type;
    EventPayload m_payload;
};

#endif

// UID:00004O | by-class/EventMan.md | Completion:90 | Confidence:92
#ifndef NEXUSTK_UI_CORE_EVENTMAN_DECLARATION_H
#define NEXUSTK_UI_CORE_EVENTMAN_DECLARATION_H

#include <windows.h>
#include <deque>
#include <string>

struct Point;

class EventMan
{
public:
    unsigned char TranslateEventKey(unsigned char key,
                                    unsigned char modifiers);
    void GetCursorPosition(Point *position);
    void DispatchCharEvent(wchar_t character, unsigned int messageTime);
    void DispatchImeOpenStatusEvent(BOOL isOpen, unsigned int messageTime);
    void DispatchCompositionTextEvent(const wchar_t *text,
                                      unsigned int messageTime);
    void DispatchCompositionStartEvent(unsigned int messageTime);
    void DispatchCompositionResultEvent(const wchar_t *text,
                                        unsigned int messageTime);
    void DispatchCompositionEndEvent(unsigned int messageTime);
    void DispatchCandidateListEvent(
        int selectedRow,
        std::deque<std::wstring> *visibleCandidates,
        unsigned int messageTime);
    void DispatchCandidateCloseEvent(unsigned int messageTime);
};

extern EventMan *g_pEventMan;

#endif
