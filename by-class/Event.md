*** UID:00004L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "Event.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Event

## Summary

`Event` is the base event record used by the UI event dispatch system. It initializes an `LObject` base, installs the `Event` vtable, stores a default event type of `0xff` at `this + 0x04`, and provides ordinary and scalar deleting destructor behavior for stack and heap event records.

B008 resolves the adjacent Event predicate helpers in [UID:00014C][0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers](by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md) as source-facing type-family classifiers rather than anonymous small helpers: pointer/mouse `0..7`, key/text `8..10`, IME `11..17`, packet `18`, and system/control `20..22`, with type `19` routed specially by EventDispatcher.

## Likely Original Placement

### UID0003ZT Self-Contained Header Contract - 2026-07-23

- This complete `EventType`, payload-union, and `Event` declaration is owned here through [UID:0000J6][Event](by-file/Event.md) and belongs in `NexusTK/ui/core/Event.h`; pointer-only handler interfaces do not own a second reduced declaration.
- `Event.h` includes the exact existing `NexusTK/util/LObject.h` before declaring `class Event : public LObject`, so every consumer sees the complete base and natural `0x110` layout without relying on a precompiled header.
- `kEventWorkNotification = 22` is the source-facing discriminator consumed by [UID:0003ZT][0x00508f60-0x0050902b.MapPaneNotifyMessageCore](by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md). The target reads `Event::m_type` at `+0x04`; it does not consume a raw message block or packet opcode.
- `Event.cpp` retains constructors, destructors, EventMan definitions, classifiers, factories, and retained helper bodies. The header owns declarations only; EventHandler.h and EventDispatcher.h may forward-declare or include Event as needed but must not duplicate this complete record.
- This dependency closure preserves `94/95`, owner/emitter [UID:0000J6][Event](by-file/Event.md), position `10`, all existing payload/producer/consumer evidence, and the exact managed formal.

### UID0000L2 Physical Header Channel Repair - 2026-08-12

- The complete declaration now emits from `RECONSTRUCTION_H`, guarded as `NEXUSTK_UI_CORE_EVENT_H` and including `../../util/LObject.h`. The CPP channel contains only `#include "Event.h"` followed by `[[CHILDREN]]`.
- Every enum value, payload field, fixed array width, union member, method declaration, field order, and child route is preserved verbatim. This changes visibility only: consumers such as `MapNamePane.cpp` can now dereference `event->m_payload.m_packet.m_data` through the generated header.
- The former CPP-resident declaration is preserved in the dated history below as a source-factoring defect, not as a second current declaration.

- Source: [UID:0000J6][Event](by-file/Event.md)
- Proposed path: `NexusTK/ui/core/Event.cpp`
- Confidence: very strong for the UI-core event object/factory module, exact `0x110` layout, unsigned type byte, payload overlays, and lifecycle route; strong for descriptive source-facing field/enum names.
- Read-only data: [UID:0003I7][0x006196a0-0x006196b0.EventVtableData](by-memory/0x006196a0-0x006196b0.EventVtableData.md)

## Methods

| Address | Method | Role |
| --- | --- | --- |
| `0x004a8a90-0x004a8ab0` | constructor | Calls the `LObject` initializer, installs vtable `0x006196a4`, and stores default event type `0xff` at `+0x04`. |
| `0x004a8ab0-0x004a8abf` | destructor | Restores vtable `0x006196a4`, resets type byte `+0x04` to `0xff`, and tail-calls the `LObject` destructor. |
| `0x004ab3f0-0x004ab435` | compiler-generated scalar deleting destructor | Runs the same base teardown and handles scalar-delete flags, including the 0x110-byte guard-size path; source is covered by the ordinary destructor rather than a handwritten ABI wrapper. |

## Classifier Helpers And Payload Direction

The source-facing classifier helpers live in the mixed Event.cpp island, not in the exact base constructor/destructor pages:

| Address | Best source-facing helper | Routed type family |
| --- | --- | --- |
| `0x004a8ac0` | `Event::IsPointerEvent()` / `IsMouseEvent()` | `0..7` cursor/mouse family |
| `0x004a8ad0` | `Event::IsKeyOrTextEvent()` | `8..10` key, key-release, text/composition family |
| `0x004a8ae0` | `Event::IsImeEvent()` | `11..17` IME family |
| `0x004a8af0` | `Event::IsPacketEvent()` | exact packet type `18` |
| `0x004a8b00` | `Event::IsSystemOrControlEvent()` | `20..22` system/control family |

The formal declaration now represents the payload as a four-byte-aligned `EventPayload` union of size `0x108`. With the inherited four-byte LObject/vptr, unsigned `m_type` at `+0x04`, and compiler alignment at `+0x05-+0x07`, this preserves exact `sizeof(Event) == 0x110`.

| Variant | Exact Event offsets | Meaning |
| --- | --- | --- |
| pointer/mouse | y `+0x08`, x `+0x0c`, modifiers `+0x10`, detail/wheel `+0x14`, message time `+0x18` | Cursor, button, and wheel payload. EventMan producer writes, SimpleHelpPane2 consumption through `PointInRect(y,x,...)`, and the accepted project point ABI establish this order; the time field is not at `+0x10c` for this variant. |
| key | key `+0x08`, modifier `+0x10a`, message time `+0x10c` | Key-down/up record over the shared text-capable storage. |
| text/composition | input/subtype `+0x08`, length/text at `+0x09/+0x0a`, UTF-16 storage through `+0x109`, modifier `+0x10a`, message time `+0x10c` | Character and live composition payload. |
| IME result | length `+0x09`, 129-word storage at `+0x0a-+0x10b`, message time `+0x10c` | Allows a 128-unit result plus terminating NUL. |
| IME open | integer open state `+0x08`, message time `+0x10c` | Open/closed status. |
| candidate | list pointer `+0x08`, selected row `+0x0c`, message time `+0x10c` | Candidate-list event. |
| packet | kind byte `+0x08`, transferred data pointer `+0x0c`, size `+0x10` | EventDispatcher frees the data pointer after type-18 dispatch. |
| application notification | channel `+0x08`, `LObject *` payload `+0x0c` | Main_WndProc message `0x406` / type `19` route. |

The accepted enum names preserve known producer semantics and explicitly descriptive gaps. Types `0-16` and `18` follow the factory/classifier map; `kEventApplicationNotification` (`19`) is proven by Main_WndProc plus `EventMan::PostNotification`; `kEventWorkNotification` (`22`) is proven by Main_WndProc custom-message subtype `32` plus work-notification consumers. `kEventImeReserved` (`17`), `kEventDispatchSuppressed` (`20`), and `kEventSystemControl` (`21`) retain no-producer caveats; type `20` is directly suppressed by `EventDispatcher::DispatchEvent`.

## Lifecycle, Size, And Generated Support

- [UID:00014B][0x004a8a90-0x004a8abf.EventBaseConstructorDestructor](by-memory/0x004a8a90-0x004a8abf.EventBaseConstructorDestructor.md) emits the source-visible `m_type` initialization/reset. LObject calls and Event vptr stores are compiler lowering.
- [UID:0003LU][0x004ab3f0-0x004ab435.EventScalarDeletingDestructor](by-memory/0x004ab3f0-0x004ab435.EventScalarDeletingDestructor.md) is compiler-generated MSVC scalar-delete support and emits only a covered-by marker.
- [UID:0003I7][0x006196a0-0x006196b0.EventVtableData](by-memory/0x006196a0-0x006196b0.EventVtableData.md) is compiler-generated RTTI/vtable data and emits only a no-raw-data marker.
- Current RTTI/name inventory contains one Event class/type descriptor/vtable. EventHandler, EventDispatcher, EventMan, and RankingEvent UI names are separate types; no class deriving from Event or alternate Event-record vtable is present.
- The 79 references to Event vtable include compiler-inlined stack Event construction in EventMan/free factories. They do not imply subclasses or a second source owner.

## Source-Shape Decisions

- The Event declaration belongs here with `[[CHILDREN]]` and emitter position `10`; exact child methods follow through Event.cpp.
- Shared internal pane-key values `0x93/0x94` and control-modifier bit `0x02` belong beside the canonical Event declaration because multiple EventHandler consumers use the same translated-key/modifier contract. UID000478 proves the branch-local distinction: PageUp/PageDown require modifiers exactly zero and `kEventKeyDown`, while Ctrl+C tests only the control bit and has no Event-type gate.
- `PaneKeyCode` and `EventModifierFlags` preserve exact widths/values in source-facing form without changing `Event` layout, ownership, emitter position, or score. Their lexical spellings are evidence-backed descriptive inference, not recovered symbols.
- A separate EventLayout page/file is rejected because it would duplicate this canonical class declaration.
- A flat raw `unsigned char[0x10c]` payload is rejected as behavior-preserving but poor source shape; named overlays preserve exact offsets and known semantics.
- A common `m_tickCount` at `+0x10c` is rejected because pointer/mouse factories store message time at `+0x18`.
- The prior formal/prose order `m_x` at `+0x08`, `m_y` at `+0x0c` is retained as an explicitly superseded historical assumption. Current direct producer/consumer evidence and `PointInRect(int y,int x,const RectBounds *)` support `m_y` first and `m_x` second; this correction changes field interpretation, not `EventPayload` size or any other variant offset.
- Exact original identifier/header spellings remain unrecovered. The accepted `kEvent...` and `m_...` names are descriptive source-facing names, not symbol claims, and cap confidence below `95` without blocking source.

## UID000478 Key And Modifier Consumer Evidence

- UID000478 `UserListDialogPane::HandleKeyOrTextEvent(Event *)` loads key byte `+0x08` and modifier byte `+0x10a`, calls `EventMan::TranslateEventKey` before every test, compares the translated result against `0x93/0x94`, and tests modifier bit `0x02`.
- Signed disassembly comparisons `-109/-108` are the same unsigned internal bytes `0x93/0x94`; Win32 `VK_PRIOR/VK_NEXT` values `0x21/0x22`, raw negative enum constants, and the stale ctype label are rejected source shapes.
- Event type value 8 remains the existing `kEventKeyDown`. A recognized page key with nonzero modifiers or wrong type immediately base-forwards; Ctrl+C intentionally permits additional modifier bits and any Event type.
- The new enums are declaration-only support. No new Event data member, raw payload array, target-specific key wrapper, EventMan replacement declaration, or second source owner is introduced.

## UID00030F Delete Key And Natural Alignment Evidence - 2026-07-20

- UID00030F independently proves translated `kPaneKeyDelete = 0x84` between the contiguous arrow family `0x80-0x83` and PageUp/PageDown `0x93/0x94`. Delete is rejected when Alt is present, otherwise it applies the exact selection/forward-delete policy and handled result.
- Target text/key branches consume `kEventTextInput = 10`, `kEventKeyDown = 8`, key byte `+0x08`, text input code/length/text at `+0x08/+0x09/+0x0a`, modifiers `+0x10a`, and long-variant message time `+0x10c`. This corroborates the named overlays without raw source offsets.
- Explicit `m_padding` members are removed only where ordinary 32-bit C++ alignment supplies the bytes: pointer modifiers before detail, key/text/composition modifiers before time, packet kind before pointer, and Event type before the payload union.
- Real variant storage remains source-visible: pointer time is at object `+0x18`; key/text/composition/IME time is at `+0x10c`; IME/candidate reserve arrays retain their required extents; EventPayload remains `0x108`; complete Event remains `0x110`.
- Natural alignment does not authorize packed structs, raw byte accessors, alternate field order, or removal of true variant reserve storage. The class-closing brace remains before `[[CHILDREN]]` so emitted Event methods compile at namespace scope.
- Score/metadata stay `94/95`, owner/emitter UID0000J6, reconstructable true, position 10. Exact enum/private lexical spellings remain inferred but no behavior, type, layout, or source blocker remains for UID00030F.

## Evidence

2026-06-04 live IDA pass:

- Binary identity: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, image base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- Function bounds are `0x004a8a90-0x004a8ab0`, `0x004a8ab0-0x004a8abf`, and `0x004ab3f0-0x004ab435`.
- Direct constructor call sites are `0x00466530` and `0x0046668b` in function `0x00465f20`, `0x00513e62` in function `0x00513da0`, `0x00588c74` in function `0x00588c40`, and `0x0058eb81` in function `0x0058eb50`.
- The constructor calls `0x004f4a80`, writes vtable `0x006196a4`, and initializes the event type byte to `0xff`.
- The ordinary destructor writes vtable `0x006196a4`, resets the event type byte to `0xff`, and tail-calls `0x004f4a90`.
- The scalar deleting destructor writes vtable `0x006196a4`, resets the event type byte, calls `0x004f4a90`, conditionally frees through `0x004f4ac0`, and uses a 0x110-byte sized-delete path when flag bit `4` is set.
- Read-only data shows `0x006196a0` is the `Event` RTTI-adjacent word, `0x006196a4` is the `Event` vtable, and `0x006196b0` begins the following `EventMan` RTTI/vtable data.
- 2026-06-12 A003 Batch322 read-only-data split confirmed [UID:0003I7][0x006196a0-0x006196b0.EventVtableData](by-memory/0x006196a0-0x006196b0.EventVtableData.md) as the exact `Event` COL/vtable child: PE dwords map `0x006196a0 -> 0x0064707c`, `0x006196a4 -> 0x004ab3f0`, `0x006196a8 -> 0x004f4b10`, and `0x006196ac -> 0x0041b6c0`; MCP reports 79 refs to `0x006196a4` across base constructor/destructor and Event/EventMan factory paths.
- The bytes before `0x004a8a90`, after `0x004a8abf`, and after `0x004ab435` are `0xcc` padding. The gap after `0x004a8abf` contains separate event predicate/factory helper bodies before `EventMan`, so it is now split away from the base Event pages.
- 2026-06-19 B008 source-quality pass confirms the post-destructor gap starts with Event type-family classifier helpers at `0x004a8ac0-0x004a8b0b`, then continues into EventMan/free factory support under [UID:00014C][0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers](by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md); this strengthens classifier and payload naming without making the whole gap direct base-Event ownership.

## Bounded Source-Quality Questions

- Exact original payload field spellings and enum constant names are not proven from symbols. The formal declaration now uses the accepted descriptive names and exact offsets above; this is a confidence cap, not an unresolved behavior or C++ blocker.
- The former broad EventObjects memory page has been split into exact [UID:00014B][0x004a8a90-0x004a8abf.EventBaseConstructorDestructor](by-memory/0x004a8a90-0x004a8abf.EventBaseConstructorDestructor.md) and [UID:0003LU][0x004ab3f0-0x004ab435.EventScalarDeletingDestructor](by-memory/0x004ab3f0-0x004ab435.EventScalarDeletingDestructor.md) pages. The intervening Event.cpp helper island is not Event class ownership.

## Cross-References

- File: [UID:0000J6][Event](by-file/Event.md)
- Dispatcher/module context: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- Related class: [UID:00004M][EventDispatcher](by-class/EventDispatcher.md)
- Event producer: [UID:00004O][EventMan](by-class/EventMan.md)
- Memory: [UID:00014B][0x004a8a90-0x004a8abf.EventBaseConstructorDestructor](by-memory/0x004a8a90-0x004a8abf.EventBaseConstructorDestructor.md), [UID:0003LU][0x004ab3f0-0x004ab435.EventScalarDeletingDestructor](by-memory/0x004ab3f0-0x004ab435.EventScalarDeletingDestructor.md)
- Read-only vtable data: [UID:0003I7][0x006196a0-0x006196b0.EventVtableData](by-memory/0x006196a0-0x006196b0.EventVtableData.md)
- Read-only data: [UID:000258][0x00619340-0x006196bc.ErrorEventReadOnlyData](by-memory/0x00619340-0x006196bc.ErrorEventReadOnlyData.md)

## Changes

### 2026-07-20 UID0001MP/UID000364 callback

- Installed complete R4 while preserving the exact `sizeof(Event)==0x110` layout, lifecycle/vtable boundaries, all EventType values, pointer y/x order, packet/application payloads, message time, and unrelated producer/dispatcher evidence.
- Added producer-proven `kEventModifierAlt = 0x01`, retained Control `0x02`, and added Shift `0x04`. EventMan's VK_MENU/VK_CONTROL/VK_SHIFT writes prove all three shared flags; UID0001MP still compares the complete modifier byte to Shift alone rather than masking bits.
- Added Escape `0x1b`, Left `0x80`, Up `0x81`, Right `0x82`, Down `0x83`, PageUp `0x93`, and PageDown `0x94`. UID000364's comparison chain and UserPane direction mapping corroborate the four arrow names.
- Corrected `EventTextPayload` from the stale `unsigned short m_inputCode` shape to byte input code, byte length, then `wchar_t[128]`. UID000364 independently stores length at Event `+0x09` and one UTF-16 unit at `+0x0a` while preserving input code at `+0x08`.
- UID0001MP consumes type `+0x04`, key `+0x08`, and modifier `+0x10a`; UID000364 additionally writes text and consumes Escape/arrows. These are direct layout consumers, not reasons to add raw offsets to source.
- Scores become `94/95` after the exact producer/constants and overlay audit. Owner/emitter UID0000J6, position 10, reconstructable state, scalar-wrapper separation, no handwritten vtable/RTTI policy, and every unrelated Event family fact remain unchanged.

- 2026-07-20 B005 UID000478 serialized implementation callback, Phase 1:
  - Preserved `92/93`, owner/emitter UID0000J6, position `10`, complete EventType/payload/class declaration, `[[CHILDREN]]`, exact `0x110` layout, lifecycle, and all unrelated producer/consumer evidence.
  - Applied the accepted Destination 3 delta only: `PaneKeyCode` values `0x93/0x94` and `EventModifierFlags::kEventModifierControl = 0x02`, plus exact UID000478 gate semantics and rejected Win32/raw/stale-label alternatives.
- 2026-07-14 B002 UID00048I implementation callback:
  - Preserved `92/93`, owner/emitter [UID:0000J6][Event](by-file/Event.md), position `10`, full enum/union/class declaration, lifecycle, size, and all unrelated variant details.
  - Corrected `EventPointerPayload` to `m_y` at `+0x08` then `m_x` at `+0x0c`, matching EventMan producer writes, SimpleHelpPane2 pointer/mouse consumption, accepted `PointInRect(y,x,...)`, and the project point ABI; historical x-first order is explicitly superseded.

- 2026-07-12 B002 accepted UID00014B declaration synchronization:
  - Changed `87/90 -> 92/93`, preserved owner/emitter [UID:0000J6][Event](by-file/Event.md), set emitter position `10`, and inserted the accepted Event enum, exact-size payload overlays, Event declaration, and `[[CHILDREN]]`.
  - Incorporated exact `0x110` size, unsigned type byte, corrected variant-specific time offsets, full known/descriptive type map, type19/type22 producers, types17/20/21 no-producer caveats, lifecycle/scalar/vtable separation, no-subclass evidence, source placement, and rejected raw-layout/new-layout-page alternatives.

- 2026-06-04:
  - Before: scored `72/80`, unattached for autogen, cited stale provenance, and summarized only three method addresses.
  - After: scored `84/88`, marked `RECONSTRUCTABLE:TRUE`, attached to [UID:0000J6][Event](by-file/Event.md), and kept final C++ blank because event-record field names and constants are not 95/95.
  - Summary/evidence: live IDA MCP confirmed binary identity, exact constructor/destructor/scalar-destructor bounds, direct constructor callers, vtable writes and slots at `0x006196a0-0x006196b0`, default type-byte behavior, 0x110-byte sized-delete path, neighboring `EventMan` data boundary, and the non-owned helper bodies in the post-destructor gap.
- 2026-06-12 A003 Batch322:
  - Before: scored `84/88`, just below the corrected parent gate for the exact base `Event` vtable-data child.
  - After: scored `85/89`; retained [UID:0000J6][Event](by-file/Event.md) as source-file parent.
  - Summary/evidence: exact [UID:0003I7][0x006196a0-0x006196b0.EventVtableData](by-memory/0x006196a0-0x006196b0.EventVtableData.md) split now records the COL pointer, slot dwords, 79 vtable refs across base Event and EventMan factory paths, and the adjacent EventHandler/EventMan read-only-data boundaries.
- 2026-06-12 Agent-C001 Goal 2 barrier repair:
  - Before: cross-references still pointed at the historical broad EventObjects memory span.
  - Changed to: references now point to the exact Event constructor/destructor page and the exact Event scalar deleting destructor page.
  - Summary/evidence: live IDA MCP proves the ctor/dtor pair, scalar deleting destructor, and mixed Event.cpp helper island are separate ranges; this class remains the direct parent only for the exact Event-owned child pages.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `72/80`.
  - Summary/evidence: event base role, constructor/destructor/scalar-destructor addresses, IDA-confirmed boundaries, and dispatcher/module context are documented; remaining work is subclass inventory and event-type constant naming.
- 2026-06-21 Rule 26 incorporation of B008 EventMan/factory helper report:
  - Before: `COMPLETION:85`, `CONFIDENCE:89`; the class page still left event payload/constant names as a broad open question and did not document the adjacent classifier helper map.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:90`.
  - Summary/evidence: B008 resolves the adjacent Event classifier helpers in [UID:00014C][0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers](by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md) as pointer/mouse, key/text, IME, packet, and system/control predicates; records the accepted type family map; and documents union-style payload field directions. Exact original member spellings remain inferred, so formal C++ stays blank until exact declarations are coordinated.
