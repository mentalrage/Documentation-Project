*** UID:0000BE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "PursuitMessageDialogPane.h"

#include "Event.h"
#include "ObjectStatusBlob.h"
#include "PacketBuffer.h"
#include "Socket.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "DialogPane.h"

class Event;

class PursuitMessageDialogPane : public DialogPane
{
public:
    PursuitMessageDialogPane();
    virtual bool HandlePacketEvent(Event *event);

protected:
    void SendPreviousDialogPacket();
    void SendNextDialogPacket();
    void SendCurrentDialogPacket();

    unsigned char m_dialogType;
    unsigned int m_dialogId;
    unsigned short m_dialogState;
    unsigned short m_dialogPageIndex;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PursuitMessageDialogPane

## Status

- Confidence: very strong for constructor source, direct inheritance, exact `0x278` layout, shared methods, vtable ownership, implicit destructor source shape, and MessageDialogs routing.
- Likely source: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- Canonical owner/emitter route: file [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), with source position `10`.
- The H channel contains the complete class declaration. The CPP channel contains only the owning header/dependency includes and `[[CHILDREN]]`; exact constructor, navigation, and packet-event bodies remain on their source-bearing children.
- Constructor memory: [UID:0001FE][0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor](by-memory/0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor.md)
- Vtables: [UID:0001YI][PursuitMessageDialogPaneVtables](by-type/by-vtable/PursuitMessageDialogPaneVtables.md)

## Responsibility

`PursuitMessageDialogPane` is the shared [UID:0000IT][DialogPane](by-file/DialogPane.md)-derived base for the NPC message, menu-question, text-input, and proxy dialog branches. Its source constructor initializes `DialogPane(L"", 1, 1)`; the compiler then installs three `PursuitMessageDialogPane` vtable views.

This should be treated as part of [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), not as a strong standalone original source file. Generated `MessageDialogLarger` also embeds a `PursuitMessageDialogPane.DialogPane` base field, which supports message-dialog ownership.

The shared packet virtual receives the canonical [UID:00004L][Event](by-class/Event.md). Packet data is `event->m_payload.m_packet.m_data` at Event `+0x0c`; the former `DialogObjectAction` wrapper is not a source type and is retained only in historical notes.

The class extends the exact `DialogPane` size `0x26c` with a byte/dword/word/word packet tail:

| Source member | Binary offset | Evidence and use |
| --- | --- | --- |
| `m_dialogType` | `+0x26c` | initialized by six direct derived constructor families and serialized by previous/next/current/reply packets |
| `m_dialogId` | `+0x270` | big-endian packet id shared by all navigation and response paths |
| `m_dialogState` | `+0x274` | big-endian state value used by navigation and proxy reply packets |
| `m_dialogPageIndex` | `+0x276` | page value decremented/incremented/preserved by the three navigation methods |

Natural MSVC alignment after the byte member places the dword at `+0x270` and yields exact class size `0x278`; no explicit padding field is required.

RTTI and constructor controls prove six direct derived classes: `MessageDialog`, `MessageDialogLarger`, `MenuQuestionDialog`, `MenuQuestionDialogLarger`, `TextDialog`, and anonymous-namespace `NexonclubProxyDialog`. TextDialog and proxy class hierarchy arrays both use Pursuit descriptor `0x0064e3a4` immediately after their own descriptor.

No destructor is declared explicitly. `DialogPane::~DialogPane()` is virtual, so C++03 implicitly declares a virtual Pursuit destructor. The class adds only POD packet fields and needs no handwritten cleanup. The primary deleting wrapper at `0x00520b70` calls source-owned `DialogPane::~DialogPane()` at `0x0049d9f0` directly, then performs only delete-flag/runtime handling. Early adjustors `0x00520aa5/0x00520ab0` and proxy copies `0x005539c3/0x005539ce` remain compiler output.

## Method And Glue Map

| Range | Method/glue | Ownership note |
| --- | --- | --- |
| [UID:0001FE][0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor](by-memory/0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor.md) | source constructor | Exact 57-byte retained body; emits the empty-body `DialogPane(L"", 1, 1)` initializer while preserving zero-xref/function-object negatives and six inlined-derived controls. |
| [UID:0001FF][0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual](by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md) | `HandlePacketEvent(Event*)` | EventHandler secondary slot `+0x10`; exact relocated duplicate of UID0001BM that parses an Event packet and sends the opcode `0x3a` response. |
| [UID:0001FG][0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers](by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md) | three protected navigation methods | Exact previous/next/current opcode `0x3a` packets over the shared packet-tail members; called by message/menu, TextDialog, and proxy paths. |
| [UID:0001BW][0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks](by-memory/0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks.md) | shared adjustor thunks | Current generated disabled output assigns these to this class, but IDA vtable refs show broad reuse across multiple dialog classes; excluded through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md) | shared scalar deleting wrapper | Calls ordinary `DialogPane::~DialogPane()` and optionally deletes. Seventeen primary vtable references prove broad compiler reuse; it is not a Pursuit source body. |

[UID:0001FF][0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual](by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md), [UID:0001FG][0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers](by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md), and [UID:0001FE][0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor](by-memory/0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor.md) carry the complete source definitions.

## Unresolved

- The exact product meaning of `Pursuit` remains unavailable; RTTI proves the spelling but not a safe semantic expansion.
- The exact original header filename remains inferred. The stable source route is the MessageDialogs declaration surface and translation unit.
- The zero inbound xrefs and missing function object for the retained constructor remain valid negative evidence, now resolved by six independent inlined-derived constructor controls rather than treated as a no-code blocker.
- Exact vtable-data page [UID:0002OM][0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData](by-memory/0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData.md) remains generated-binary evidence and is unchanged.

The former shared-response method name and action wrapper are no longer unresolved: canonical EventHandler slot ordering, Event layout, and the exact Merchant duplicate resolve them to `HandlePacketEvent(Event*)`. The remaining items above concern product meaning, historical header packaging, raw-constructor IDA modeling, and generated table data; none blocks the class declaration or child source.

## EventHandler And Source-Channel Contract

- The complete object has primary, EventHandler, and timer-handler views at `+0x00`, `+0xa0`, and `+0xa4`. Secondary cell `0x00622498` is EventHandler slot `+0x10` and points to UID0001FF.
- The packet body uses no class state or raw ECX, but source remains an ordinary virtual member. Raw IDA typing must use an EventHandler facet receiver rather than a complete Pursuit pointer; no manual this-adjustment belongs in source.
- H includes `DialogPane.h`, forward-declares Event, and owns the complete class declaration and exact `0x278` field tail.
- CPP includes `PursuitMessageDialogPane.h`, Event, ObjectStatusBlob, PacketBuffer, and Socket before expanding child definitions. No class declaration, wrapper example, vtable data, or ABI destructor body remains in CPP.
- UID0001FF preserves the exact 256-byte local, reserved byte `+7`, signed-short cursor, ObjectStatusBlob parse, and ten-byte response send. No invented guards or protocol semantics are added.

## Historical Assumptions Superseded

- The prior `DialogObjectAction { payload; }` and `HandleDialogObjectResponse` declaration were high-level placeholders for the observed `+0x0c` load. Canonical Event/EventHandler evidence and exact relocated-duplicate analysis supersede them.
- Existing class size, member offsets, constructor controls, RTTI hierarchy, implicit destructor closure, navigation methods, raw-constructor negatives, and MessageDialogs source route remain unchanged and valid.
- The old declaration-in-CPP arrangement is superseded by the required H declaration and separate CPP include/children shell; this is a channel correction, not loss of source information.

## Cross-References

- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:0001FE][0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor](by-memory/0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor.md)
- [UID:0001YI][PursuitMessageDialogPaneVtables](by-type/by-vtable/PursuitMessageDialogPaneVtables.md)
- [UID:0001FF][0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual](by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md)
- [UID:0001BW][0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks](by-memory/0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks.md)
- [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:000086][MessageDialogLarger](by-class/MessageDialogLarger.md)

## Changes

- 2026-07-26 B002 accepted UID0001BM support correction:
  - Retained `92/94`, UID0000LA owner/emitter route, position `10`, reconstructable state, exact `0x278` layout, navigation methods, RTTI, and implicit destructor evidence.
  - Removed the invented `DialogObjectAction` source type, declared `virtual bool HandlePacketEvent(Event *event)` in H, and moved the complete declaration out of CPP.
  - Installed the separate own/dependency include plus `[[CHILDREN]]` CPP shell and added exact EventHandler slot/facet/source-channel behavior while preserving superseded assumptions historically.
- 2026-07-16 Agent-B004 implementation callback:
  - Raised `86/88 -> 92/94`.
  - Installed the complete source-clean declaration with constructor, response virtual, three protected navigation methods, and exact byte/dword/word/word tail members.
  - Removed the undefined explicit destructor declaration and documented implicit virtual destruction through source-owned `DialogPane::~DialogPane()`.
  - Added six direct derived classes, exact `0x278` layout, RTTI proof, shared-wrapper/adjustor compiler boundary, and complete child source routing.
- 2026-07-01 Agent-B010 implementation callback: raised `85/86 -> 86/88`, set emitter position `10`, and added the accepted declaration shell with `DialogObjectAction`, `HandleDialogObjectResponse(const DialogObjectAction *action)`, and `[[CHILDREN]]`. The page now records the payload pointer at action object `+0x0c` and cross-links [UID:0001FF][0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual](by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md) as the source-bearing shared virtual while preserving the no-route/raw-constructor caveat.
- 2026-05-30: Changed completion/confidence from `0/0` to `76/74`.
  - Before: The page was unevaluated despite documenting raw constructor bytes, shared message-dialog virtual behavior, vtables, and destructor-glue caveats.
  - After: Scored as moderate-high completion with medium-high confidence because the exact "Pursuit" semantic and raw-constructor function promotion remain unresolved.
  - Evidence: Existing method/glue map, unresolved notes, IDA recheck notes, and message-dialog cross-references explain both the known behavior and uncertainty.
- 2026-06-03 autogen attachment pass:
  - Before: the class remained unparented at `76/74` even though the parent [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) was at `88/80` and the constructor/vtable child pages carried strong IDA-backed evidence.
  - Changed to: completion/confidence `80/82`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000LA`.
  - Evidence: [UID:0001FE][0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor](by-memory/0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor.md) documents the exact raw constructor and vtable stores at `82/86`; [UID:0002OM][0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData](by-memory/0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData.md) documents the exact three-view vtable data at `84/89`; [UID:0001YI][PursuitMessageDialogPaneVtables](by-type/by-vtable/PursuitMessageDialogPaneVtables.md) ties those views to this message-dialog base/companion. Scores stay below `95` because the raw constructor is still not an IDA function object and the shared response virtual's final source-level name is not settled.
- 2026-06-10 A002 strict-gate repair:
  - Before: `AUTOGEN_PARENT_UID:0000LA` attached this class to [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), and status text still referenced generated recovered output.
  - After: `AUTOGEN_PARENT_UID:` is blank and status records the strict `85/85` gate; score remains `80/82`.
  - Summary/evidence: the direct parent is now `89/85`, but this child remains below the child side of the current gate. The source-owner link remains as evidence, backed by the raw constructor, three-view vtable data, shared response virtual, and destructor-glue caveats already documented in linked by-memory/by-type pages.
- 2026-06-11 A002 Batch222 parent-gate refresh:
  - Before: `80/82` and blank `AUTOGEN_PARENT_UID`.
  - After: `85/86` and `AUTOGEN_PARENT_UID:0000LA`.
  - Summary/evidence: live IDA MCP reconfirmed the exact vtable child, raw constructor store xrefs, shared response virtual slot, successor boundary, and the existing message-dialog source-family evidence. Superseded by the 2026-07-01 B010 callback, which emits the declaration shell while keeping constructor/body details below final-source confidence.
