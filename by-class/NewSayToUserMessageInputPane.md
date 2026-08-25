*** UID:000099 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "SayInputPanes.h"

#include "Chatting.h"
#include "../auth/PasswordGuard.h"
#include "../ui/core/BlackHole.h"
#include "../ui/panels/UserPane.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "../ui/dialogs/InputPanes.h"

class NewSayToUserMessageInputPane : public LineInputPane
{
public:
    explicit NewSayToUserMessageInputPane(const wchar_t *recipientName);

protected:
    virtual void OnSubmitInput();
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    wchar_t m_recipientName[128];
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

## UID0000N9 Whole-File Topology Synchronization - 2026-08-25

- This class is the first deterministic SayInputPanes emitter at position `10`. Its formal CPP owns the compilation-unit include preamble and `[[CHILDREN]]`; its formal H owns the one `#pragma once`, direct `InputPanes.h` prerequisite, and complete class declaration.
- The assembled `NexusTK/social/SayInputPanes.cpp` must place all child definitions at namespace scope. `SayInputMode` and every UserPane dispatcher/opener/history declaration remain in `UserPane.h`, not this header.

# NewSayToUserMessageInputPane

## Status

- Confidence: very strong for exact layout, three vtable views, five constructor routes, submit/key liveness, one-buffer opcode `0x19` serialization, Event-based empty-Backspace behavior, and shared-header/namespace-scope source topology.
- Likely source file: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- Address range: exact child [UID:000403][0x005b1990-0x005b1d42.NewSayToUserMessageInputPaneMethods](by-memory/0x005b1990-0x005b1d42.NewSayToUserMessageInputPaneMethods.md), indexed by [UID:0001LY][0x005b1570-0x005b2562.SayTargetMessageInputPanes](by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md)
- C++ reconstruction: the complete declaration is in the formal H channel; the formal CPP includes `SayInputPanes.h` and emits only `[[CHILDREN]]`, so [UID:000403][0x005b1990-0x005b1d42.NewSayToUserMessageInputPaneMethods](by-memory/0x005b1990-0x005b1d42.NewSayToUserMessageInputPaneMethods.md) definitions appear at namespace scope. The derived destructor remains implicit; compiler wrappers and adjustors do not require a handwritten declaration/body.

## Class Purpose

`NewSayToUserMessageInputPane` is the modern direct-message/whisper input pane. It stores a recipient name, prompts with `To <name> : `, sends opcode `0x19`, and lets backspace on an empty field return to `SayToUserNameInputPane`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `NewSayToUserMessageInputPane` | `0x005b1990-0x005b1a51` | Initializes line input, vtables, `m_recipientName[128]` at `+0x108`, and prompt. |
| `OnSubmitInput` | `0x005b1a60-0x005b1c32` | Uses one `wchar_t[256]`, one reused `char[256]`, and one 300-byte packet to serialize opcode `0x19` plus recipient/message lengths and payloads. |
| `HandleKeyOrTextEvent(Event *event)` | `0x005b1c40-0x005b1d42` | Secondary-facet Event override; delegates modifier/non-Backspace/nonempty input and performs complete empty-Backspace deletion/state/refresh/name-pane flow. |
| adjustor thunks | `0x005b7820`, `0x005b782b` | Compiler-generated secondary/tertiary receiver adjustors; no authored methods. |
| scalar deleting destructor | `0x005b7af0-0x005b7b2b` | Shared compiler-generated wrapper; the source destructor remains implicit. |

## Evidence Notes

- Live IDA MCP on 2026-06-04 confirms the current executable as `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` / SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- IDA function boundaries are exact for the constructor `0x005b1990-0x005b1a51`, submit handler `0x005b1a60-0x005b1c32`, key handler `0x005b1c40-0x005b1d42`, adjustor thunks `0x005b7820-0x005b782b` and `0x005b782b-0x005b7836`, and scalar deleting destructor `0x005b7af0-0x005b7b2b`.
- `CodeRefsTo(0x005b1990)` reports constructor callers at `0x00554e0a`, `0x0059edc6`, `0x005a51e9`, `0x005a5544`, and `0x005b4128`; `0x005b4128` is [UID:0000C7][SayToUserNameInputPane](by-class/SayToUserNameInputPane.md)'s modern confirmation branch constructing this pane after a non-empty recipient name.
- The constructor installs three `NewSayToUserMessageInputPane` vtables at `0x0062f788`, `0x0062f7d8`, and `0x0062f808`, copies the recipient into the `+0x108` buffer, and uses prompt string `To %s : ` at `0x00630a30`.
- Object size is `0x208`; the only class-specific field currently proven in the constructor/submit/key cluster is `m_recipientName[128]` at `this+0x108`.
- `OnSubmitInput` is vtable-referenced only at `0x0062f7d0`; it uses `LineInputPane::TextLength` / `LineInputPane::CopyText`, checks the password-disclosure guard at `0x00465890`, sanitizes through [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md), and serializes inline through exactly three `PacketBufferWriteUInt8` calls. Physical storage proves one reusable `CHAR[256]` conversion buffer and one contiguous 300-byte packet, not two arrays or `0x230` bytes. Recipient and message each receive a local converted-string terminator; the packet receives a local-only terminator; counted send length is recipient plus message plus three through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md). The apparent `>=256`/`>=300` branches are compiler checked-index instrumentation, not authored silent returns.
- The legacy [UID:0000C6][SayToUserMessageInputPane](by-class/SayToUserMessageInputPane.md) submit path at `0x005b1640` has the same opcode `0x19`, packet-helper call set, two `WideCharToMultiByte` conversions, and `dword_67A7EC` send path; the class distinction is the separate constructor/vtable/prompt family, not a different packet protocol.
- `HandleKeyOrTextEvent(Event *)` is vtable-referenced only at `0x0062f7e0`. The incoming receiver is the secondary EventHandler facet at complete object `+0xa0`; source must not model it as a separate complete object. The body translates Event key/modifier fields unconditionally and does not test `Event::m_type`. Modifier, non-Backspace, or nonempty-text paths delegate the same Event to `LineInputPane::HandleKeyOrTextEvent`. Empty unmodified Backspace queues deferred deletion, clears active line-input state through canonical `g_pUserPane` storage [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md), conditionally resets say mode and refreshes [UID:0002X5][g_pChattingVarietyPane](by-global/g_pChattingVarietyPane.md) from [UID:0002XE][g_pChattingHandlePane](by-global/g_pChattingHandlePane.md) pending-target state, directly constructs [UID:0000C7][SayToUserNameInputPane](by-class/SayToUserNameInputPane.md), and returns true.
- [UID:000403][0x005b1990-0x005b1d42.NewSayToUserMessageInputPaneMethods](by-memory/0x005b1990-0x005b1d42.NewSayToUserMessageInputPaneMethods.md) now carries the exact constructor/padding/submit/padding/key-handler split and first-draft method C++.
- The sibling no-route helper [UID:000404][0x005b1d50-0x005b1eb3.SayTargetMessagePacketHelperNoRouteB](by-memory/0x005b1d50-0x005b1eb3.SayTargetMessagePacketHelperNoRouteB.md) is not part of this class. It has two stack wchar arguments, `ret 8`, no `this` receiver, no rel32 callers, and no pointer hits.

## Source Topology And Score Rationale

- `NexusTK/social/SayInputPanes.h` receives the clean class declaration before any child definitions are parsed. The single `../ui/dialogs/InputPanes.h` include appears on this earliest derived-class H emitter; UID0000C3 no longer duplicates it.
- `NexusTK/social/SayInputPanes.cpp` receives `#include "SayInputPanes.h"` followed by `[[CHILDREN]]`. UID000403 supplies the three namespace-scope definitions; no class body or nested qualified definition belongs in CPP.
- [UID:0000C7][SayToUserNameInputPane](by-class/SayToUserNameInputPane.md) must also be complete in the shared H before UID000403's direct `new SayToUserNameInputPane()` is parsed. That topology dependency does not claim resolution of UID0000C7's independently stale method source.
- Completion `93`: declaration/method routing, layout, vtables, callers, protocol, key flow, and compiler exclusions are complete. Confidence `94`: behavior and topology are strongly evidenced; stripped lexical names and historical physical-file partition remain the bounded cap.

## Source-Quality Names

| Binary item | Current source-facing decision | Confidence |
| --- | --- | --- |
| `this+0x108` | `m_recipientName[128]`; copied with `_wcscpy_s(..., 0x80, recipientName)` and serialized as the packet recipient. | high |
| `0x00630a30` | `L"To %s : "` modern direct-message prompt literal. | high |
| `0x00630a18` / `0x00630a20` | `L"To "` recipient-name prompt and legacy `L"-> %s: "` direct-message prompt, documented by [UID:0003JQ][0x00630a18-0x00630a44.DirectWhisperPromptFragments](by-memory/0x00630a18-0x00630a44.DirectWhisperPromptFragments.md). | high |
| `byte_66DA97` | [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md); direct-message-local behavior is modern `NewSayToUserMessageInputPane` versus legacy `SayToUserMessageInputPane`, not a whisper-only global. | high |
| `dword_67A7EC` | [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / `Socket *`; reject stale cash-shop sender aliases for this route. | high |
| `dword_67ADC8` | [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md), the chat text sanitizer owner. | medium-high |
| `dword_67A748` | canonical source-facing `g_pUserPane` storage [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md); stable filename/historical alias is `g_pCollectionData`, and key cleanup uses local player chat/line-input state. | medium-high |
| `dword_67ADE0` / `dword_67ADD8` | [UID:0002XE][g_pChattingHandlePane](by-global/g_pChattingHandlePane.md) and [UID:0002X5][g_pChattingVarietyPane](by-global/g_pChattingVarietyPane.md), used during empty-Backspace chat UI refresh. | high |
| `0x005b7820`, `0x005b782b`, `0x005b7af0` | compiler-generated adjustor thunks and scalar deleting destructor support shared by target-message pane vtables; no source-authored method bodies. | high |

## Cross-References

- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- [UID:000403][0x005b1990-0x005b1d42.NewSayToUserMessageInputPaneMethods](by-memory/0x005b1990-0x005b1d42.NewSayToUserMessageInputPaneMethods.md)
- [UID:000404][0x005b1d50-0x005b1eb3.SayTargetMessagePacketHelperNoRouteB](by-memory/0x005b1d50-0x005b1eb3.SayTargetMessagePacketHelperNoRouteB.md)
- [UID:0001LY][0x005b1570-0x005b2562.SayTargetMessageInputPanes](by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md)
- [UID:0000C7][SayToUserNameInputPane](by-class/SayToUserNameInputPane.md)
- [UID:0000C6][SayToUserMessageInputPane](by-class/SayToUserMessageInputPane.md)

## Changes

- 2026-08-17 B001 UID0000MG dependency implementation: score/class/children unchanged; inserted `../auth/PasswordGuard.h` as the single earliest SayInputPanes CPP preamble before BlackHole/SayInputPanes includes and all six family caller definitions.

- 2026-08-14 Agent-B002 UID000403 accepted implementation callback:
  - Raised `87/90` to `93/94`; preserved owner/emitter UID0000N9 and reconstructable true.
  - Moved the exact class declaration to H, changed CPP to the shared-header include plus `[[CHILDREN]]`, and removed stale `struct InputEvent`, `OnKeyInput`, and explicit derived-destructor source declarations.
  - Added exact one-buffer/300-byte protocol shape, Event receiver and cleanup semantics, five callers, three vtable views, compiler-only thunk/destructor policy, complete-type dependency on UID0000C7, and namespace-scope source topology.
  - Historical `InputEvent`, `OnKeyInput`/`HandleKeyInput`, explicit destructor, two conversion buffers, `0x230` packet, silent bounds returns, and standalone class-CPP assumptions are retained only as superseded provenance in older dated entries.

- Before: completion/confidence metadata were `0/0` even though the page already documented class role, method boundaries, caller evidence, globals, and related panes.
- Changed to: `COMPLETION:74` and `CONFIDENCE:76`.
- Evidence: the page covers constructor, submit, key-input, destructor support, whisper globals, and caller flow; confidence remains medium because the exact relationship to the legacy direct-message pane still needs a comparison pass.
- 2026-06-04: Raised completion from `74` to `84` and confidence from `76` to `88` after live IDA MCP comparison against the legacy direct-message pane.
  - Before: the page had only summarized start evidence and left the modern-vs-legacy relationship as medium confidence.
  - After: the page records exact function boundaries, constructor callers, vtable refs, prompt string, submit opcode/callee set, modern key-handler return-to-name path, and the specific equivalence/difference between modern and legacy direct-message submit behavior.
  - Evidence: live disassembly confirms `sub_5B1990`, `sub_5B1A60`, `sub_5B1C40`, `sub_5B7820`, `sub_5B782B`, and `sub_5B7AF0`; `CodeRefsTo(0x005b1990)` has five constructor callers; `0x0062f7d0` and `0x0062f7e0` reference the submit/key vtable slots; modern and legacy submit both push opcode `0x19` and share the packet-helper/WideCharToMultiByte/send path while using separate constructors, prompts, and vtables.
- 2026-06-05: Marked reconstructable and attached to [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) because the class is `84/88` and the parent is `87/84`, satisfying the 80/80 parent gate. Live IDA MCP `lookup_funcs` confirms exact starts at `0x005b1990`, `0x005b1a60`, `0x005b1c40`, `0x005b7820`, `0x005b782b`, and `0x005b7af0`; current `callers` confirms the same five constructor callers already documented.
- 2026-06-20 supervisor Rule 26 incorporation of B001 `0001LY-SayTargetMessageInputPanes-source-quality.md`:
  - Before: `84/88`, no formal class C++, and the sibling helper was not excluded at class level.
  - After: `87/90`, declaration-only class C++ with `m_recipientName[128]` at `+0x108`, exact child [UID:000403][0x005b1990-0x005b1d42.NewSayToUserMessageInputPaneMethods](by-memory/0x005b1990-0x005b1d42.NewSayToUserMessageInputPaneMethods.md) carries first-draft constructor/submit/key C++, and helper [UID:000404][0x005b1d50-0x005b1eb3.SayTargetMessagePacketHelperNoRouteB](by-memory/0x005b1d50-0x005b1eb3.SayTargetMessagePacketHelperNoRouteB.md) is explicitly excluded from class ownership.
  - Evidence: B001 PE/Capstone route and boundary pass confirmed five constructor routes, submit/key vtable slots `0x0062f7d0` and `0x0062f7e0`, prompt literal `To %s : `, opcode `0x19` packet shape, modern-flow role, and negative route/pointer evidence for the sibling helper.
- 2026-06-20 B003 [UID:0000C7][SayToUserNameInputPane](by-class/SayToUserNameInputPane.md) source-quality sync:
  - Clarified that constructor caller `0x005b4128` is the modern recipient-confirmation path from `SayToUserNameInputPane`, while `0x005b1d0b` in this class's key handler is the empty-Backspace return to the recipient-name pane.
- 2026-06-22 B014 `000099-NewSayToUserMessageInputPane-source-quality.md` sync:
  - Kept `87/90`, owner/emitter [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md), and reconstructable declaration-only class C++.
  - Added report-level source-quality names and roles for object size `0x208`, `m_recipientName[128]`, `g_packetSender`, `g_pTextFilter`, `g_pUserPane`, `g_pChattingHandlePane`, `g_pChattingVarietyPane`, `g_useEpfAssets`, password guard, exact packet shape, empty-Backspace cleanup, and generated thunk/destructor policy.
  - Evidence: B014 PE/Capstone route audit reconfirmed five constructor callsites, submit/key vtable routes, the shared opcode `0x19` direct-message protocol, prompt literals, and the lack of source-authored bodies for adjustor/scalar-deleting destructor support.
