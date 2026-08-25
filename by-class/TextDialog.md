*** UID:0000EL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "TextDialog.h"

#include "MemoryMan.h"
#include "PacketBuffer.h"
#include "Socket.h"
#include "TextEditControlPane.h"

#include <windows.h>
#include <wchar.h>

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "PursuitMessageDialogPane.h"

class TextDialog : public PursuitMessageDialogPane
{
public:
    TextDialog(const unsigned char *payload,
               bool showObjectImage,
               bool useLargeLayout);
    virtual void OnControlCommand(int controlIndex, int notifyCode);
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TextDialog

## Status

- Confidence: very strong for method boundaries, exact split, RTTI-proven direct Pursuit inheritance, inherited packet/navigation state, exact `0x278` layout, `OnControlCommand` virtual identity, and direct class ownership of exact children.
- Likely source file: [UID:0000OL][TextDialog](by-file/TextDialog.md)
- Main address range: [UID:0001FJ][0x00552110-0x005534a0.TextDialogCore](by-memory/0x00552110-0x005534a0.TextDialogCore.md)
- Source route: `NexusTK/ui/dialogs/TextDialog.cpp` with declaration in `TextDialog.h`.
- Formal source state: class/header surface and `OnControlCommand` child are source-ready. [UID:0003VR][0x00553180-0x00553338.TextDialogHandleDialogAction](by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md) owns the method body; this class page owns includes, the class declaration, inheritance, and child insertion point.

## Class Purpose

`TextDialog` directly derives from [UID:0000BE][PursuitMessageDialogPane](by-class/PursuitMessageDialogPane.md), not directly from `DialogPane`. Its RTTI class hierarchy descriptor at `0x0064e7d0` has eight entries, and base array `0x0064e7e0` uses exact Pursuit descriptor `0x0064e3a4` immediately after the TextDialog descriptor.

TextDialog has exact object size `0x278`, equal to `PursuitMessageDialogPane`, and adds no source-proven instance fields, alignment fields, or vtable members. The source declaration therefore represents direct public inheritance without manufacturing a base-as-member pseudo-layout or duplicating inherited packet state.

It shows packet-provided text, optional object art, optional input controls, and navigation buttons. The constructor's direct machine call to `DialogPane(L"", 1, 1)` is inlined lowering of the Pursuit base constructor.

TextDialog inherits `m_dialogType`, `m_dialogId`, `m_dialogState`, and `m_dialogPageIndex` at `+0x26c/+0x270/+0x274/+0x276`, plus protected `SendPreviousDialogPacket`, `SendNextDialogPacket`, and `SendCurrentDialogPacket`. It submits typed replies inline through opcode `0x3a` and uses those inherited methods for navigation.

B010 2026-07-01 support sync: [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) calls this class through four source-facing wrapper forms: `TextDialog(payload, true, false)`, `TextDialog(payload, false, false)`, `TextDialog(payload, true, true)`, and `TextDialog(payload, false, true)`. Constructor behavior and those wrapper combinations support the human parameter names `showObjectImage` and `useLargeLayout`; no original symbol preserves their historical spellings.

## Method Map

| Range | Method | Role |
| --- | --- | --- |
| `0x00552110-0x0055317a` | `TextDialog::TextDialog` | Parses dialog packet fields, chooses normal/high-resolution resources, and constructs child controls. |
| `0x00553180-0x00553338` | `TextDialog::OnControlCommand` | Exact primary-vtable `+0x48` override. Control `1` reads text child `6`, converts and sends the inline opcode `0x3a` reply, controls `2/3/4` call inherited navigation methods, and every handled route closes. |
| `0x00553350-0x00553495` | no-route raw submit-packet island | Source-shaped but currently unreferenced opcode `0x3a` reply clone; B007 found no VA/RVA/direct-branch route into the body. If a route is later proven, the best inferred private role is `SendTextReplyPacket(const wchar_t *text)` or `SendSubmitTextPacket(const wchar_t *text)`, but it is not emitted under this class now. |

`0x00553338-0x00553348` is the compiler switch table for `OnControlCommand`; `0x0055317a-0x00553180`, `0x00553348-0x00553350`, and `0x00553495-0x005534a0` are `0xcc` alignment padding. `0x005534a0-0x00553609` is not a TextDialog method; it belongs to [UID:0003GL][0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback](by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md).

The raw island at `0x00553350` remains excluded from class emission because the live virtual action handler sends typed text inline, the action-handler switch table targets only addresses inside `0x00553180-0x00553338`, the TextDialog vtable routes the action handler and constructor family but not the raw body, and the neighboring proxy constructor installs `0x005534a0` rather than `0x00553350`.

## OnControlCommand Contract

The primary TextDialog vtable begins at `0x00622958`; cell `0x006229a0` is slot `+0x48` and stores [UID:0003VR][0x00553180-0x00553338.TextDialogHandleDialogAction](by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md). The inherited `DialogPane` contract identifies this slot as `virtual void OnControlCommand(int controlIndex, int notifyCode)`. This is stronger than the historical descriptive name `HandleDialogAction` and resolves the exact declaration without retaining IDA naming.

The override consumes inherited `m_controlManager` to obtain child `6` as `TextEditControlPane`, and consumes inherited Pursuit fields `m_dialogType`, `m_dialogId`, `m_dialogState`, and `m_dialogPageIndex`. Control `1` emits the inline text packet; controls `2/3/4` use inherited `SendPreviousDialogPacket`, `SendNextDialogPacket`, and `SendCurrentDialogPacket`; handled routes call inherited `CloseDialog`. The default is a no-op.

## Source Dependencies And Header Shape

- `TextDialog.h` includes `PursuitMessageDialogPane.h` and declares only the constructor plus the exact virtual override. No TextDialog-specific destructor is declared because the vtable uses shared compiler-generated destructor machinery and no source-specific body is proven.
- `TextDialog.cpp` includes `MemoryMan.h`, `PacketBuffer.h`, `Socket.h`, `TextEditControlPane.h`, `<windows.h>`, and `<wchar.h>` for the accepted child bodies.
- `[[CHILDREN]]` is the only class-parent insertion point. Exact constructor/action definitions remain on their by-memory child emitters and are not duplicated here.
- The source uses human C++ names rather than `sub_553180`, stack offsets, or compiler runtime labels. Numeric control/child indices remain where resource-symbol spellings are not recoverable.

## Shared Helpers

The opcode `0x3a` previous/next/current methods at `0x0054cc30`, `0x0054ccd0`, and `0x0054cd70` were historically staged under `TextDialog`, but caller and RTTI evidence now assigns them to the shared Pursuit base. [UID:0001FG][0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers](by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md) emits those methods once through Pursuit/MessageDialogs; TextDialog calls them through inheritance and must not duplicate their bodies.

Historical B012 no-owner/no-emitter treatment is preserved as a correct result before the shared receiver declaration was proven. The missing receiver blocker is now resolved by the Pursuit RTTI hierarchy and exact shared tail layout.

## Key Relationships

- Uses [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md) for optional object/NPC art.
- Uses [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md) for the editable input field.
- Uses [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md), [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md), and button controls for the dialog layout.
- Neighboring [UID:00009H][NexonclubProxyDialog](by-class/NexonclubProxyDialog.md) owns the old `0x005534a0-0x00553609` tail through its callback install site.

## Cross-References

- [UID:0000OL][TextDialog](by-file/TextDialog.md)
- [UID:0001FJ][0x00552110-0x005534a0.TextDialogCore](by-memory/0x00552110-0x005534a0.TextDialogCore.md)
- [UID:0003VQ][0x00552110-0x0055317a.TextDialogConstructor](by-memory/0x00552110-0x0055317a.TextDialogConstructor.md)
- [UID:0003VR][0x00553180-0x00553338.TextDialogHandleDialogAction](by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md)
- [UID:0003VS][0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw](by-memory/0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw.md)
- [UID:0003GL][0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback](by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md)
- [UID:0001FG][0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers](by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md)
- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)

## Changes

- 2026-08-01 Agent-B009 UID0003VR implementation callback:
  - Raised `88/92 -> 90/93` while preserving owner/emitter [UID:0000OL][TextDialog](by-file/TextDialog.md).
  - Added formal class CPP/H with direct Pursuit inheritance, exact `0x278` no-added-field layout, constructor declaration, and `OnControlCommand` override.
  - Resolved the historical `HandleDialogAction` label to the primary-vtable `+0x48` virtual identity and documented its inherited child, packet, navigation, and close dependencies.
  - Kept the adjacent no-route raw island and compiler-generated destructor records non-emitting.

- 2026-07-16 Agent-B004 UID0001FE support callback:
  - Raised `87/88 -> 88/92`.
  - Corrected direct base from DialogPane to PursuitMessageDialogPane using exact RTTI.
  - Added inherited packet fields/navigation methods and historicalized the former shared-helper no-owner blocker.
  - Preserved blank class formal and every TextDialog-specific constructor/action blocker.
- 2026-07-01 Agent-B010 implementation callback: added support note for the four [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) TextDialog wrapper call forms and kept constructor flag semantics under TextDialog ownership.
- 2026-06-16 Supervisor execution of B001 reports `0001FJ-textdialog-core-source-split-audit.md` and `0001FJ-textdialog-core-source-quality.md`: raised from `86/86` to `87/88`, replaced stale `SendRegionSelectionPacket` ownership with the exact TextDialog constructor/action map, recorded the no-route raw submit-packet island, and recorded switch-table/padding/proxy-callback exclusions.
- 2026-06-21 Rule 26 incorporation of B007 report `0003VS-TextDialogUnreferencedSubmitPacketRaw-source-quality.md`: score unchanged; expanded the raw-island row with future-route name candidates and the raw PE no-route proof while keeping class-level C++ blank.
- 2026-07-04 B012 UID0001FG support sync: updated the shared helper note so the previous/next/current packet helpers remain reconstructable shared infrastructure but are not private TextDialog methods and are not currently source-emitting. This preserves TextDialog historical/generated staging context while matching UID0001FG's blank-emitter/no-code proof.
