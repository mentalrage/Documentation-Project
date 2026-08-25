** TARGET-REPORT-UID:000099 **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000099 NewSayToUserMessageInputPane Source-Quality Research

## Status

FINISHED B-agent report-only pass. No by-* documentation was edited. `by-memory/-coverage-report.md` was not edited.

## Target

- UID: `000099`
- Primary doc: `source-3/project-documentation/by-class/NewSayToUserMessageInputPane.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B014/research/000099-NewSayToUserMessageInputPane-source-quality.md`
- Current metadata: `COMPLETION:84`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000N9`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N9`
- Current owner route: [UID:0000N9] `SayInputPanes`

## Executive Recommendation

Raise [UID:000099] to `COMPLETION:87`, `CONFIDENCE:90`, keep `CANONICAL_OWNER:0000N9`, keep `RECONSTRUCTABLE:TRUE`, and keep `EMITTER_UIDS:0000N9`.

The class is live, source-shaped, and belongs with the `SayInputPanes` / whisper input family. The class page should emit declaration-level C++ only; exact constructor, submit, and key-handler method bodies are ready for first-draft C++ in exact by-memory children or an exact method aggregate, not directly in the class page.

Recommended class declaration:

```cpp
struct InputEvent;

class NewSayToUserMessageInputPane : public LineInputPane
{
public:
    explicit NewSayToUserMessageInputPane(const wchar_t *recipientName);
    virtual ~NewSayToUserMessageInputPane();

protected:
    virtual void OnSubmitInput();
    virtual bool OnKeyInput(const InputEvent *event);

private:
    wchar_t m_recipientName[128]; // +0x108; copied with a 0x80 wchar bound.

    [[CHILDREN]]
};
```

If the existing page keeps the historical method label, use `HandleKeyInput(const InputEvent *event)` for the virtual row while documenting that the source-facing role is the key-input override.

## Core Findings

- `0x005b1990-0x005b1a50` is the modern direct-message constructor: `NewSayToUserMessageInputPane::NewSayToUserMessageInputPane(const wchar_t *recipientName)`.
- Object size is `0x208`. The only class-specific data field proved in this body is `wchar_t m_recipientName[128]` at `this + 0x108`.
- The constructor copies the recipient name with a 0x80 wchar bound, formats prompt literal `L"To %s : "` at `0x00630a30`, calls `LineInputPane::SetPromptText`, and installs the primary/secondary/tertiary vtables.
- The submit override sends the same opcode `0x19` direct-message packet shape as the legacy `SayToUserMessageInputPane`: `{0x19, recipientLen, recipientBytes, messageLen, messageBytes}`.
- Submit uses `LineInputPane::TextLength`, `LineInputPane::CopyText`, the password-disclosure guard at `0x00465890`, the wide chat text sanitizer through `g_pTextFilter` / `dword_67ADC8`, `WideCharToMultiByte`, packet byte writers, and `Socket::QueueAndSendPacket(g_packetSender, ...)`.
- The key override handles empty Backspace by closing the message pane and returning to `SayToUserNameInputPane`; otherwise it delegates to `LineInputPane::HandleKeyInput`.
- Empty Backspace cleanup clears the active line-input state on `g_pUserPane` / `dword_67A748`, may clear current chat mode at `+0x3eb4`, and refreshes `g_pChattingVarietyPane` when `g_pChattingHandlePane + 0x111` is set.
- Adjustor thunks `0x005b7820` and `0x005b782b`, plus scalar deleting destructor `0x005b7af0-0x005b7b2b`, are compiler-generated support. They should remain no-code support, not source-authored method bodies.

## Reachability And Liveness

The class is not dead, compatibility-only, or vtable-only. Direct PE rel32 scans found five constructor callsites:

| Callsite | Best owner/context | Meaning |
| --- | --- | --- |
| `0x00554e0a` | right-click/context-menu pane neighborhood | opens a direct-message input for a selected user name stored near `+0x60` |
| `0x0059edc6` | `UserListPane::OpenSayToUserMessageInputPane` | modern branch selected by `byte_66DA97` allocates `0x208` and calls this constructor |
| `0x005a51e9` | `OpenInputPaneForCurrentSayMode` | current say-mode dispatcher opens direct-message pane for the recent recipient |
| `0x005a5544` | `OpenWhisperToLastRecipient` | last-recipient helper opens this modern direct-message pane |
| `0x005b4128` | `SayToUserNameInputPane::OnRecipientNameConfirmed` | confirmed recipient returns into this message pane |

Submit and key-handler methods have no ordinary rel32 callers because they are virtual callbacks. Their vtable-slot dword hits are the live route:

- `0x005b1a60` submit override: vtable hit at `0x0062f7d0`.
- `0x005b1c40` key override: vtable hit at `0x0062f7e0`.
- `0x005b7af0` scalar deleting destructor: shared vtable hits at `0x0062f6fc`, `0x0062f788`, `0x0062f814`, and `0x0062f8a0`.
- Adjustor thunk `0x005b7820`: hits at `0x0062f74c`, `0x0062f7d8`, `0x0062f864`, and `0x0062f8f0`.
- Adjustor thunk `0x005b782b`: hits at `0x0062f77c`, `0x0062f808`, `0x0062f894`, and `0x0062f920`.

The modern constructor vtable-base immediates `0x0062f788`, `0x0062f7d8`, and `0x0062f808` occur exactly once each in `.text`, all inside the constructor body.

## Source Placement

Keep owner and emitter as [UID:0000N9] `SayInputPanes`.

Reasons:

- The constructor is called by the say-mode dispatcher, last-recipient helper, user-name confirmation flow, and user-list/context-menu openings.
- The legacy `SayToUserMessageInputPane`, modern `NewSayToUserMessageInputPane`, `SayToUserNameInputPane`, group target-message pane, and plan/clan target-message pane share constructor, packet, prompt, key-return, adjustor, and scalar-delete patterns.
- `by-file/SayInputPanes.md` already owns this family and gives a stable generated source route.
- `UserListPane`, right-click/context-menu pane, `Chatting`, and `UserPane` are callers or global dependencies, not the semantic source owner for this class.

Best source file direction remains `NexusTK/social/SayInputPanes.cpp`. A future split such as `WhisperInputPanes.cpp` is plausible but not currently better supported than the existing aggregate route.

## Modern Versus Legacy Direct Message Relationship

`NewSayToUserMessageInputPane` is the modern direct-message pane selected by the global layout/asset selector `byte_66DA97` / `g_useEpfAssets` in direct-message flows. The older `SayToUserMessageInputPane` remains live in the legacy branch. Both classes send opcode `0x19` with recipient and message length-prefixed after wide-to-multibyte conversion.

Do not rename `byte_66DA97` as a whisper-only global. The project-wide support docs identify it as `g_useEpfAssets` / current-layout selector; in this UI family it gates the modern direct-message pane versus the legacy direct-message pane.

## Field, Helper, Global, And Type Names

Recommended source-facing names and roles:

| Binary item | Recommended documentation name | Confidence / note |
| --- | --- | --- |
| `this + 0x108` | `m_recipientName[128]` | high; copied with `_wcscpy_s(..., 0x80, recipientName)` and used as packet recipient |
| `0x00630a30` | `L"To %s : "` direct-message prompt literal | high |
| `0x00630a18` | `L"To "` name prompt fragment | high, used by `SayToUserNameInputPane` |
| `0x00630a20` | legacy prompt `L"-> %s: "` | high |
| `0x004f20a0` | `LineInputPane::SetPromptText` | high |
| `0x004f2310` | `LineInputPane::TextLength` | high |
| `0x004f2300` | `LineInputPane::CopyText` | high |
| `0x004f25a0` | `LineInputPane::HandleKeyInput` / key-input override base call | high |
| `0x00575380` | `PacketBufferWriteUInt8` | high from packet helper page |
| `0x00574bb0` | `Socket::QueueAndSendPacket` | high |
| `dword_67A7EC` | `g_packetSender` / `Socket *` | high; reject stale cash-shop sender alias |
| `dword_67ADC8` | `g_pTextFilter` / chat text sanitizer owner | medium-high |
| `dword_67A748` | `g_pUserPane` / local user-pane state pointer | medium-high; support docs also carry historical `g_pCollectionData` naming |
| `dword_67ADE0` | `g_pChattingHandlePane` | high |
| `dword_67ADD8` | `g_pChattingVarietyPane` | high |
| `dword_67A748 + 0x3eb4` | current chat mode / variety mode field | medium-high |
| `dword_67A748 + 0x210` | active line-input pane/state field | medium; role clear, original field name not proven |

## First-Draft C++ Readiness

Class-level C++ is ready as a declaration with `[[CHILDREN]]`. Full method bodies should be emitted by exact by-memory children because the class page is a class-level inventory page, not a byte-range method page.

Exact method-body readiness:

- Constructor: ready. It is one clean source constructor body with vptr stores omitted from source.
- Submit override: ready after exact-child creation. Packet shape, conversion bounds, sanitizer, sender global, and opcode are all resolved well enough for first-draft source.
- Key override: ready after exact-child creation. The adjusted `ecx - 0xa0` binary calling shape is a vtable/interface artifact; source should model this as the class key-input override.
- Adjustor thunks and scalar deleting destructor: no-code/generated-binary proof only.

Recommended future exact-child constructor draft:

```cpp
NewSayToUserMessageInputPane::NewSayToUserMessageInputPane(const wchar_t *recipientName)
    : LineInputPane(0)
{
    wcscpy_s(m_recipientName, 128, recipientName);

    wchar_t prompt[128];
    swprintf_s(prompt, 128, L"To %s : ", m_recipientName);
    SetPromptText(prompt);
}
```

Submit and key-handler exact children should use human source style, not decompiler-shaped locals. The submit body should write opcode `0x19`, then length-prefixed multibyte recipient and message payloads, and range-check total payload below `0x12c`. The key body should handle empty Backspace as return-to-name flow and otherwise call the base key handler.

## Rejected Alternatives

- Not a dead or compatibility-only class: five constructor callsites reach it.
- Not a new packet protocol: it shares opcode `0x19` and recipient/message packet shape with the legacy direct-message pane.
- Not owned by `UserListPane`, right-click menu, `Chatting`, or `UserPane`: those pages are callers or globals.
- Not a cash-shop sender route: `dword_67A7EC` is `g_packetSender` / `Socket *`.
- Not a whisper-only flag global: `byte_66DA97` is the broader current-layout/EPF selector whose local effect is modern versus legacy direct-message UI.
- Not class-level full method-body C++: by-structure guidance keeps method bodies on exact by-memory pages.
- Not source-authored thunks/destructor bodies: adjustors and scalar deleting destructor are compiler support.

## Evidence Checked

Instructions and required workflow:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B014/goal.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/inference_research.md`
- `source-3/project-documentation/by-project-structure/proposed-source-tree.md`

Target and support docs:

- `by-class/NewSayToUserMessageInputPane.md`
- `by-file/SayInputPanes.md`
- `by-class/SayToUserMessageInputPane.md`
- `by-class/SayToUserNameInputPane.md`
- `by-memory/0x005b3cb0-0x005b4219.SayToUserNameInputPane.md`
- `by-memory/0x00630a18-0x00630a44.DirectWhisperPromptFragments.md`
- `by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md`
- `by-class/LineInputPane.md`
- `by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md`
- `by-memory/0x004f2300-0x004f230f.LineInputPaneCopyText.md`
- `by-memory/0x004f2310-0x004f231b.LineInputPaneTextLength.md`
- `by-memory/0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md`
- `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`
- `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
- `by-global/g_packetSender.md`
- `by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md`
- `by-global/g_pChattingHandlePane.md`
- `by-global/g_pChattingVarietyPane.md`
- `by-global/g_useEpfAssets.md`
- `by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md`
- `by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md`
- `by-class/UserListPane.md`
- `by-global/g_pCollectionData.md`
- `by-class/ChattingVarietyPane.md`

Direct PE evidence:

- Read-only PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Size: `2679296`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA-256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- Image base: `0x00400000`
- `.text`: `0x00401000-0x0060c600`
- `.rdata`: `0x0060d000-0x0066c200`
- `.data`: `0x0066d000-0x0069ce24`

IDA MCP was not exposed as a callable tool namespace in this run. Existing IDA-backed docs were used as evidence and direct PE/Capstone scans were used for rel32, dword-hit, vtable, boundary, and literal rechecks. No IDA database writes were made.

## Boundary And Split/Merge Notes

- Constructor range `0x005b1990-0x005b1a50` is clean; following bytes to `0x005b1a60` are `0xcc` padding.
- Submit range `0x005b1a60-0x005b1c32` is clean; following bytes to `0x005b1c40` are `0xcc` padding.
- Key-handler range `0x005b1c40-0x005b1d42` is clean for this method. The larger gap before the next group-pane constructor contains padding followed by sibling bytes, so do not extend the key handler beyond `0x005b1d42`.
- Scalar deleting destructor `0x005b7af0-0x005b7b2b` is separate compiler-generated support and is shared by several target-message pane vtables.
- No class-page merge with `SayToUserMessageInputPane` is recommended. They are related legacy/modern siblings with the same protocol, not the same class.

## Recommended Exact Target Changes

In `by-class/NewSayToUserMessageInputPane.md`:

1. Change metadata:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. Add declaration-level C++ with `[[CHILDREN]]` using the declaration shown in the executive recommendation.

3. Update the method inventory:

- Constructor signature: `NewSayToUserMessageInputPane(const wchar_t *recipientName)`.
- Submit override: `void OnSubmitInput()`; note packet opcode `0x19` and exact recipient/message payload shape.
- Key override: `bool OnKeyInput(const InputEvent *event)` or keep row label `HandleKeyInput` with source-role note; document empty Backspace return-to-name behavior.
- Adjustor thunks: generated/no-code, receiver adjustments `-0xa0` and `-0xa4`.
- Scalar deleting destructor: generated/no-code shared target-message pane deletion helper; not evidence of a handwritten destructor body.

4. Add a source-quality section with:

- Constructor live routes and PE rel32 callsites listed above.
- Vtable slot evidence for submit/key/thunks/destructor.
- Field layout: object size `0x208`, recipient buffer `+0x108`, no accepted `m_field_0x428` artifact from adjusted-receiver layout caches.
- Modern-vs-legacy branch: `byte_66DA97` / `g_useEpfAssets` selects the modern class in this UI flow, while the legacy pane still sends the same opcode.
- Global/helper names: `g_packetSender`, `g_pTextFilter`, `g_pChattingHandlePane`, `g_pChattingVarietyPane`, `g_pUserPane` / historical `g_pCollectionData`, packet byte writer, queue/send helper, and `LineInputPane` base helpers.

5. Replace any stale generated-name wording that leaves `sub_5B1990`, `sub_5B1A60`, `sub_5B1C40`, raw vtable `0x0062f788`, or unnamed captured fields unresolved without the above best-supported names.

## Recommended Support-Doc Changes

- `by-file/SayInputPanes.md`: update the `NewSayToUserMessageInputPane` row to say the modern direct-message class is declaration-ready and exact method bodies are ready in child pages; do not treat the generated class name or old score gate as a blocker.
- `by-class/SayToUserMessageInputPane.md`: add a concise modern/legacy comparison: both direct-message panes use opcode `0x19` and the same recipient/message payload shape; modern pane uses prompt `To %s : `, legacy pane uses `-> %s: `.
- `by-class/SayToUserNameInputPane.md` and `by-memory/0x005b3cb0-0x005b4219.SayToUserNameInputPane.md`: clarify that `byte_66DA97` is the broader `g_useEpfAssets` / layout selector, with direct-message-local behavior of choosing the modern message pane.
- `by-memory/0x00630a18-0x00630a44.DirectWhisperPromptFragments.md`: replace stale old-gate language if present. String data stays no-code/generated-binary support; C++ belongs to the consuming constructor/method pages.
- `by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md`, if touched later: replace stale 90/90+ code-entry wording with the active combined-score/emitter gate and exact-child method-body policy.

No support-doc score changes are required solely from this report. `SayInputPanes.md` already has strong file-level scoring; the primary score movement belongs on `000099`.

## Coverage Text

Do not edit `by-memory/-coverage-report.md`; this is a class target and no by-memory coverage row should be edited by B014.

Recommended exact replacement row for `by-class/-coverage-report.md` if the supervisor updates class coverage:

```markdown
- [UID:000099][NewSayToUserMessageInputPane](by-class/NewSayToUserMessageInputPane.md) : reconstructable : 87% : very strong : B014 source-quality reanalysis resolves the modern direct-message class shape: constructor `NewSayToUserMessageInputPane(const wchar_t *recipientName)`, `wchar_t m_recipientName[128]` at `+0x108`, object size `0x208`, prompt `To %s : `, five live constructor routes, opcode `0x19` recipient/message packet identical to the legacy pane, empty-Backspace return to `SayToUserNameInputPane`, chat UI cleanup through `g_pChattingHandlePane`/`g_pChattingVarietyPane`, `g_packetSender` and packet helper names, compiler-generated thunk/destructor policy, and declaration-only class C++ readiness with method bodies reserved for exact by-memory children.
```

## Validator Needs

No validators were run because this is report-only and no by-* docs were edited.

Recommended commands after accepted implementation:

> Executable block R001 was removed from this report and preserved verbatim in [000099-NewSayToUserMessageInputPane-source-quality-removed.md](000099-NewSayToUserMessageInputPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Add scoped file validators for any optional support pages the supervisor chooses to edit.

## IDA Rename / Type / Comment Recommendations

Do not apply during this report pass.

| Item | Recommendation | Confidence |
| --- | --- | --- |
| `0x005b1990` | rename/type as `NewSayToUserMessageInputPane::NewSayToUserMessageInputPane(const wchar_t *recipientName)` | high |
| `0x005b1a60` | rename/type as `NewSayToUserMessageInputPane::OnSubmitInput()` | high |
| `0x005b1c40` | rename/type as `NewSayToUserMessageInputPane::OnKeyInput(const InputEvent *event)` or project-local `HandleKeyInput` spelling | medium-high |
| `0x005b7820` | generated adjustor thunk, receiver adjustment `-0xa0`, no source body | high |
| `0x005b782b` | generated adjustor thunk, receiver adjustment `-0xa4`, no source body | high |
| `0x005b7af0` | scalar deleting destructor shared by target-message panes, generated/no-code support | high |
| `0x0062f788`, `0x0062f7d8`, `0x0062f808` | label as modern `NewSayToUserMessageInputPane` vtable views | high |
| `this + 0x108` | `m_recipientName[128]` | high |
| `dword_67A7EC` | `g_packetSender` / `Socket *` | high |
| `dword_67ADC8` | `g_pTextFilter` / wide chat sanitizer owner | medium-high |
| `dword_67ADE0` | `g_pChattingHandlePane` | high |
| `dword_67ADD8` | `g_pChattingVarietyPane` | high |
| `byte_66DA97` | use support name `g_useEpfAssets`; comment local behavior as modern direct-message branch selector | high |

## Open Questions

- The exact original C++ spelling for the key override may have been `OnKeyInput`, `HandleKeyInput`, or a project-specific input callback name. Existing target text uses `HandleKeyInput`; surrounding B reports often prefer `OnKeyInput`. The behavior and vtable role are resolved.
- The original field name for the active line-input slot at `g_pUserPane + 0x210` is not proven. Document the role instead of inventing a source field name.
- The original file partition between `SayInputPanes.cpp` and a possible `WhisperInputPanes.cpp` is not provable from stripped binaries. Current ownership docs and generated route support staying with `SayInputPanes.cpp`.
- Full method-body C++ should wait for exact by-memory children or an exact method aggregate. This is a documentation-structure constraint, not a behavior blocker.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B014/research/000099-NewSayToUserMessageInputPane-source-quality.md`
- Modified: none
- Target/support by-* docs: not edited
- `by-memory/-coverage-report.md`: not edited

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/000099-NewSayToUserMessageInputPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"000099"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000099-NewSayToUserMessageInputPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/000099-NewSayToUserMessageInputPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000099"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
