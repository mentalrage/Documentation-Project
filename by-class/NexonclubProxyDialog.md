*** UID:00009H | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include <string.h>
#include <windows.h>

#include "FunctionObjects.h"
#include "MessageDialogs.h"
#include "NexonclubRegistrationDialog.h"
#include "ObjectStatusBlob.h"
#include "PacketBuffer.h"
#include "Socket.h"
#include "StringBase.h"

namespace
{
class NexonclubProxyDialog : public PursuitMessageDialogPane
{
public:
    explicit NexonclubProxyDialog(unsigned char *packet);

private:
    void OnReplyText(const StringBaseW& text);
};

[[CHILDREN]]
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NexonclubProxyDialog

## Status

- Confidence: very strong for direct Pursuit inheritance, exact no-field layout, constructor/callback declarations, vtable identity, callback wiring, declaration order, and dialog-file placement.
- Likely source file: [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md)
- Main address range: [UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md)
- Read-only data evidence: [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md)
- Concrete callback wrapper: [UID:0003GK][PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback](by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md)
- Current recovered file: `source-3/simroot_v2/class_NexonclubProxyDialog.cpp`

## Class Purpose

`NexonclubProxyDialog` directly derives from [UID:0000BE][PursuitMessageDialogPane](by-class/PursuitMessageDialogPane.md), parses a server-provided proxy dialog packet, and immediately opens `NexonclubRegistrationDialog` with the parsed text and callback data. It is a bridge between the NPC/message dialog packet format and the account-registration UI.

RTTI base array `0x0064e86c` uses exact Pursuit descriptor `0x0064e3a4` immediately after the proxy descriptor, proving direct nonvirtual inheritance. The class is an anonymous-namespace/local implementation class and emits at source position `0`, before its constructor and callback children.

Allocation size is exactly `0x278`, equal to the complete Pursuit base size. The proxy adds no data members; all four packet fields below are inherited protected state.

## Field Layout

| Offset | Source-facing field | Type direction | Evidence |
| --- | --- | --- | --- |
| `+0x26c` | `m_dialogType` | `unsigned char` | [UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md) stores `packet[0]`; [UID:0003GL][0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback](by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md) writes it after opcode `0x3a`. |
| `+0x270` | `m_dialogId` | inherited `unsigned int` / big-endian packet id | Constructor reads `PacketBufferReadUInt32BE(packet + 1)`; reply callback writes it as the dialog/session id. |
| `+0x274` | `m_dialogState` | inherited `unsigned short` | Constructor reads a big-endian word after the embedded object/status blob; reply callback writes it unchanged. |
| `+0x276` | `m_dialogPageIndex` | inherited `unsigned short` | Constructor reads a big-endian word; reply callback writes `m_dialogPageIndex + 1` for the one-based reply page/index. |

The proxy declares no duplicate fields. Exact names/types live on the Pursuit base declaration and are consumed here through inheritance.

## Method Map

| Range | Method | Role |
| --- | --- | --- |
| `0x005534a0-0x00553609` | `NexonclubProxyDialog::OnReplyText` | Bound member callback installed in [UID:0003GK][PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback](by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md); serializes opcode `0x3a` replies from the stored proxy fields, falls back to current-dialog reply on empty text, and closes the dialog. |
| `0x00553610-0x005538fd` | `NexonclubProxyDialog::NexonclubProxyDialog` | Parses proxy-packet header/status/text/caption fields, creates a callback wrapper for `OnReplyText`, and constructs `NexonclubRegistrationDialog` with the decoded main text. |
| `0x005539c3-0x005539ce` | thunk | Secondary adjustor thunk; IDA models it as `this -= 0xa0` followed by shared destructor glue. |
| `0x005539ce-0x005539d8` | thunk | Disabled generated thunk; exact base owner remains polluted. |

## Vtable And Data Evidence

| Range | Evidence | Interpretation |
| --- | --- | --- |
| `0x00622c54-0x00622cf0` | [UID:0003DE][0x00622c54-0x00622cf0.NexonclubProxyDialogVtableData](by-memory/0x00622c54-0x00622cf0.NexonclubProxyDialogVtableData.md) records anonymous-namespace `NexonclubProxyDialog` RTTI/vtables. | Confirms class identity separate from adjacent `TextDialog`, callback-table, and `HeadSelectDialog` ranges. |
| `0x00622cf4` | [UID:0003GK][PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback](by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md) records the concrete `PlainMemberFunctionObjectT<NexonclubProxyDialog,const StringBase&>` vtable. | Supports the constructor's callback allocation and reply-target binding. |
| `0x0054c9f0-0x0054ca49` | [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) records the dispatcher wrapper that allocates `0x278` bytes and calls `0x00553610`. | Confirms construction path from the NPC/message dialog dispatcher. |

B010 2026-07-01 support sync: [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) calls this class through wrapper `0x0054c9f0` as `new NexonclubProxyDialog(payload)`. The MessageDialogs dispatcher owns that call site only; this class keeps packet parse, callback, and registration ownership.

## Callback Evidence

Live IDA MCP on 2026-06-12 recovered the constructor's callback allocation block at `0x00553870-0x005538d3`: it allocates `0x18` bytes, initializes the callback base, writes vtable `0x00622cf4`, stores member-function pointer `0x005534a0`, stores zero this-adjustment, stores the current proxy object, and passes the callback with the decoded wide text into [UID:00009I][NexonclubRegistrationDialog](by-class/NexonclubRegistrationDialog.md).

The direct owner of the callback vtable data is [UID:0003GK][PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback](by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md), while this class is the consumer and bound target object. The reusable template declaration remains with [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md).

B008 2026-06-26 reanalysis names the callback source method `OnReplyText`. The constructor source shape is `new PlainMemberFunctionObjectT<NexonclubProxyDialog, const StringBaseW&>(this, &NexonclubProxyDialog::OnReplyText)`, followed by construction of [UID:00009I][NexonclubRegistrationDialog](by-class/NexonclubRegistrationDialog.md) with the main message text and callback. `OnRegistrationResult` is rejected as too registration-dialog-centric, `SendProxyReplyText` hides the empty/cancel fallback path, and stale `TextDialog` naming is contradicted by the constructor install site.

## Constructor Packet Parse Summary

[UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md) source-initializes only `PursuitMessageDialogPane()`. The machine-level direct DialogPane call and vtable stores are inlined/compiler lowering. The body constructs a local `ObjectStatusBlob`, assigns inherited type/id in exact observed order, forces tagged-status mode byte `2` when the packet kind byte equals `2`, parses status, assigns inherited state/page only on successful parsing, consumes layout bytes, converts prompt/button text, creates the callback wrapper, and opens `NexonclubRegistrationDialog`.

## Key Relationships

- Constructs [UID:00009I][NexonclubRegistrationDialog](by-class/NexonclubRegistrationDialog.md).
- Creates [UID:0003GK][PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback](by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md) as the result callback passed to the registration dialog.
- Owns [UID:0003GL][0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback](by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md), the concrete proxy member stored into the callback wrapper at `0x00553895`.
- Uses [UID:0000EL][TextDialog](by-class/TextDialog.md) only as the neighboring dialog family; A001 Batch 284 split the concrete `0x005534a0` proxy member body out of stale TextDialog ownership.
- Sits immediately after `TextDialog`, but has independent vtable installation and class identity.
- Belongs under [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md), whose projected source folder is now `NexusTK/ui/dialogs/`.

## Reconstruction Notes

- Rebuild handling: complete source-position-zero anonymous class declaration plus exact constructor/callback child definitions; compiler regenerates vtables and destructor wrappers.
- Marked reconstructable because the constructor and vtables are NexusTK-owned dialog code/data that must be represented in rebuilt source.
- Class-level source declares the direct Pursuit base, public packet constructor, private `OnReplyText`, required includes, and `[[CHILDREN]]`; method bodies remain on the exact by-memory pages.
- [UID:0003DE][0x00622c54-0x00622cf0.NexonclubProxyDialogVtableData](by-memory/0x00622c54-0x00622cf0.NexonclubProxyDialogVtableData.md), [UID:0003DF][0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData](by-memory/0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData.md), and [UID:00023N][0x005539c3-0x005539d9.SharedDialogDefaultDestructorThunksLate](by-memory/0x005539c3-0x005539d9.SharedDialogDefaultDestructorThunksLate.md) remain no-code/generated-data or compiler-glue support. Source reconstruction should express the class declaration, `OnReplyText`, and constructor; the compiler should regenerate vtables and adjustor thunks.
- No destructor is declared explicitly. Pursuit's implicitly declared destructor is virtual through source-owned `DialogPane::~DialogPane()`, so the proxy also receives an implicit virtual destructor. The class adds no fields or custom cleanup, and shared primary/adjustor deleting wrappers remain compiler output.

## Cross-References

- [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md)
- [UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md)
- [UID:0003GL][0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback](by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md)
- [UID:0003DE][0x00622c54-0x00622cf0.NexonclubProxyDialogVtableData](by-memory/0x00622c54-0x00622cf0.NexonclubProxyDialogVtableData.md)
- [UID:0003GK][PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback](by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md)
- [UID:00009I][NexonclubRegistrationDialog](by-class/NexonclubRegistrationDialog.md)
- [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md)
- [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md)

## Changes

- 2026-07-16 Agent-B004 UID0001FE implementation callback:
  - Raised `88/90 -> 91/94` and set source position `0`.
  - Installed the complete anonymous-namespace class declaration before child definitions.
  - Corrected the direct base to PursuitMessageDialogPane, removed duplicate-field/destructor assumptions, and recorded inherited packet/navigation state plus implicit virtual destructor closure.
  - Preserved all B008 packet, callback, vtable, registration, source-placement, and compiler-glue evidence.
- 2026-07-01 Agent-B010 implementation callback: added support note for [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) wrapper `0x0054c9f0 -> new NexonclubProxyDialog(payload)` and preserved proxy-owned callback/registration behavior.
- Before: the constructor range ended at `0x005538fc`.
- Changed to: the constructor range ends at `0x005538fd`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows the old endpoint omitted the final byte of the range-check failure call operand.
- Before: completion/confidence metadata were `0/0` despite constructor, packet-bridge role, thunk caveat, and class relationship notes.
- Changed to: `COMPLETION:68` and `CONFIDENCE:76`.
- Evidence: the page documents the constructor range, parsed proxy-packet role, callback relationship, and registration-dialog construction; confidence stays medium because only the constructor is meaningfully described and final source split/base-owner pollution remain open.
- Before: class metadata was `68/76`, reconstructable was blank, and no parent was assigned.
- Changed to: `COMPLETION:80`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and parent [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md).
- Evidence: the class now records the dispatcher wrapper, anonymous proxy vtables, callback vtable, projected dialog source folder, and reconstruction blockers. C++ remains blank because final callback/base/destructor names are not near-final.
- 2026-06-12 Agent-A003 Batch 285 parent-gate refresh:
  - Before: `COMPLETION:80`, `CONFIDENCE:84`; callback ownership was broad and blocked exact callback-vtable routing.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`, keeping parent [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md).
  - Evidence: live IDA MCP confirms the proxy constructor's exact callback-object allocation, concrete [UID:0003GK][PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback](by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md) vtable store, member-function pointer `0x005534a0`, bound proxy object, registration-dialog handoff, and independent proxy vtables. The page still stays below final C++ quality because packet field names and destructor/base cleanup remain provisional.
- 2026-06-12 Agent-A001 Batch 284 follow-up: Added exact method child [UID:0003GL][0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback](by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md) and exact class vtable child [UID:0003DE][0x00622c54-0x00622cf0.NexonclubProxyDialogVtableData](by-memory/0x00622c54-0x00622cf0.NexonclubProxyDialogVtableData.md). Scores remain `86/88`; the added evidence reinforces the already-cleared parent gate and repairs the stale TextDialog ownership reference.
- 2026-06-26 Agent-B008 Rule 26 implementation:
  - Before: `COMPLETION:86`, `CONFIDENCE:88`, with constructor/callback evidence present but field names and method names not fully carried into the class page.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:90`, adding the `+0x26c/+0x270/+0x274/+0x276` field table, `OnReplyText` method role, constructor parse summary, callback source expression, and explicit no-code policy for vtable/destructor glue.
  - Evidence: B008 live MCP session `80de0a67` and accepted report tie the constructor field writes to callback packet serialization, reject TextDialog/registration/message-dispatcher ownership, and place method-body C++ in the exact by-memory pages rather than this class page.
