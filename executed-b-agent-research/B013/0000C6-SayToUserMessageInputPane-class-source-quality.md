** TARGET-REPORT-UID:0000C6 **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000C6 SayToUserMessageInputPane Class Source-Quality Research

## Status

FINISHED B-agent report-only pass. No by-* documentation was edited. `by-memory/-coverage-report.md` was not edited.

## Target

- UID: `0000C6`
- Primary doc: `source-3/project-documentation/by-class/SayToUserMessageInputPane.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B013/research/0000C6-SayToUserMessageInputPane-class-source-quality.md`
- Current metadata: `COMPLETION:84`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000N9`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N9`
- Current owner route: [UID:0000N9] `SayInputPanes`
- Main containing aggregate: [UID:0001LY] `by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md`

## Executive Recommendation

Raise [UID:0000C6] to `COMPLETION:87`, `CONFIDENCE:90`, keep `CANONICAL_OWNER:0000N9`, keep `RECONSTRUCTABLE:TRUE`, and keep `EMITTER_UIDS:0000N9`.

The legacy class is live, source-authored, and source-routed to `NexusTK/social/SayInputPanes.cpp`. The class page should emit declaration-level C++ only. Constructor and submit method bodies are source-ready as first drafts, but they belong in exact by-memory children or a future exact `0x005b1570-0x005b1812` method-cluster child rather than in the class inventory page.

Recommended class-level C++ for `by-class/SayToUserMessageInputPane.md`:

```cpp
class SayToUserMessageInputPane : public LineInputPane
{
public:
    explicit SayToUserMessageInputPane(const wchar_t *recipientName);
    virtual ~SayToUserMessageInputPane();

protected:
    virtual void OnSubmitInput();

private:
    wchar_t m_recipientName[128]; // +0x108; copied with a 0x80 wchar bound.

    [[CHILDREN]]
};
```

If the supervisor keeps the current method label `OnSubmit`, add a source-role note that the project-local virtual role matches `OnSubmitInput()` used by the modern pane report. The exact original spelling is not proven, but the vtable role and behavior are resolved.

## Core Findings

- `0x005b1570` is `SayToUserMessageInputPane::SayToUserMessageInputPane(const wchar_t *recipientName)`.
- Direct PE disassembly shows the constructor's `ret 4` starts at `0x005b162e` and consumes the immediate byte at `0x005b1630`, so the exact half-open constructor range should be `0x005b1570-0x005b1631`, not `0x005b1570-0x005b1630`.
- `0x005b1631-0x005b1640` is `0xcc` alignment padding before submit.
- `0x005b1640-0x005b1812` is the submit override. It validates non-empty input, copies current line text, calls the password-disclosure guard, sanitizes the wide message through `g_pTextFilter`, serializes opcode `0x19`, recipient length/string, and message length/string, then calls `QueueAndSendPacket(g_packetSender, packet, recipientLen + messageLen + 3)`.
- `0x005b1812-0x005b1820` is fourteen `0xcc` bytes. `0x005b1820-0x005b1983` is a real adjacent two-argument target-message packet helper with the same opcode `0x19` two-string serialization, but direct PE rel32/dword scans found no route to its start. Treat it as a sibling split candidate, not part of `SayToUserMessageInputPane`.
- The legacy direct-message prompt is `L"-> %s: "` at `0x00630a20`. The modern sibling prompt is `L"To %s : "` at `0x00630a30`.
- Object allocation size is `0x208`, matching the modern, group, and plan/clan target-message panes. The class-specific buffer proved here is `wchar_t m_recipientName[128]` at `this+0x108`.
- The destructor support is compiler-generated: adjustor thunks at `0x005b7820` and `0x005b782b` subtract `0xa0` or `0xa4` and jump to the scalar deleting destructor at `0x005b7af0`. The scalar deleting destructor calls the `LineInputPane` cleanup body and conditionally frees `0x208` bytes. There is no evidence for a handwritten legacy-class destructor body.

## Legacy Versus Modern Whisper Pane Split

The legacy and modern direct-message panes are UI-flow variants, not protocol variants.

| Aspect | Legacy `SayToUserMessageInputPane` | Modern `NewSayToUserMessageInputPane` |
| --- | --- | --- |
| Constructor | `0x005b1570` and inline construction at `0x005b419b` | `0x005b1990` direct constructor |
| Prompt | `L"-> %s: "` | `L"To %s : "` |
| Recipient field | `m_recipientName[128]` at `+0x108` | same offset and bound |
| Submit packet | opcode `0x19`, recipient/message length-prefixed bytes | same opcode and packet shape |
| Backspace-to-name flow | not present in this class | modern key handler `0x005b1c40` returns to `SayToUserNameInputPane` on empty Backspace |
| Selection branch | used when `g_useEpfAssets != 1` in local direct-message flows | used when `g_useEpfAssets == 1` |

Use [UID:0000SW] `g_useEpfAssets` as the canonical global name, not a new global such as `g_useModernWhisperFlow`. It is a broad EPF/current-layout selector. Its local effect in this UI family is selecting the modern direct-message pane versus the legacy pane.

Do not merge the two class pages. The shared opcode and packet shape are shared target-message behavior; the separate vtables, prompts, constructor routes, and modern key-return handler prove distinct source classes.

## Constructor And Ownership Evidence

Direct PE/Capstone recheck used `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

- Size: `2679296`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA-256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- Image base: `0x00400000`
- `.text`: `0x00401000-0x0060c600`
- `.rdata`: `0x0060d000-0x0066c200`
- `.data`: `0x0066d000-0x0069ce24`

Constructor facts:

- Calls `LineInputPane::LineInputPane(0)` at `0x005b15b1`.
- Copies the constructor argument into `this+0x108` with `_wcscpy_s(..., 0x80, recipientName)` at `0x005b15e4`.
- Installs primary, secondary, and tertiary legacy vtable views at `0x0062f6fc`, `0x0062f74c`, and `0x0062f77c`.
- Formats prompt `L"-> %s: "` through the `swprintf_s`-style helper at `0x0041b9b0` and calls `LineInputPane::SetPromptText`.
- Returns `this` and uses `ret 4`.

Reachability:

- Direct rel32 scan found one ordinary constructor call: call instruction `0x0059edf7` inside `UserListPane::OpenSayToUserMessageInputPane`.
- `SayToUserNameInputPane::OnRecipientNameConfirmed` does not call this constructor. Its legacy branch inline-constructs the same source shape at `0x005b419b-0x005b41f9`: base constructor call, vtable stores, recipient copy, legacy prompt format, and prompt setter.
- Direct PE scan found `0x0062f6fc`, `0x0062f74c`, and `0x0062f77c` vtable-base immediates twice each: once in this constructor and once in the inline legacy branch.

The inline construction evidence is important for reconstruction: the source may have used a constructor that the compiler inlined inside `OnRecipientNameConfirmed`, but the binary does not contain a call edge there. Documentation should say "inline legacy construction branch" rather than inventing a direct call.

## Submit Packet Shape

Best source-facing signature:

```cpp
void SayToUserMessageInputPane::OnSubmitInput();
```

Behavior:

- Calls `LineInputPane::TextLength()` and returns immediately when the current line is empty.
- Copies up to `0xff` wide characters through `LineInputPane::CopyText`.
- Calls [UID:0002VH] `ValidateChatInputOrThrowPasswordError` at `0x00465890`.
- Calls [UID:0000TK] `SanitizeWideTextForChat` / `0x005957c0` through `g_pTextFilter` / `dword_67ADC8`.
- Converts the stored recipient and filtered message through `WideCharToMultiByte` loaded from IAT slot `0x0060d170`.
- Writes opcode `0x19` through [UID:0003YJ] `PacketBufferWriteUInt8`.
- Writes one-byte recipient length, recipient bytes, one-byte message length, and message bytes. The helper uses byte writes and memcpy-style copies, not a central "write string" helper in this body.
- Rejects each converted field if the conversion result is `>= 0x100`.
- Rejects the full packet if `recipientLen + messageLen + 3 >= 0x12c`.
- Sends with [UID:0001HU] `Socket::QueueAndSendPacket` using [UID:0000Q5] `g_packetSender` / `dword_67A7EC`.

Packet layout:

| Offset | Field | Encoding |
| --- | --- | --- |
| `0` | opcode | `0x19` |
| `1` | recipient length | one byte after `WideCharToMultiByte` |
| `2..` | recipient bytes | multibyte bytes, no terminator counted |
| `2 + recipientLen` | message length | one byte after `WideCharToMultiByte` |
| `3 + recipientLen..` | message bytes | filtered message multibyte bytes |

Source-facing helper names and roles:

| Binary item | Recommended name / role | Confidence |
| --- | --- | --- |
| `0x004f2310` | `LineInputPane::TextLength()` | high |
| `0x004f2300` | `LineInputPane::CopyText(wchar_t *buffer, int maxChars)` | high |
| `0x00465890` | `ValidateChatInputOrThrowPasswordError(wchar_t *text)` | high for role, medium-high for exact return spelling |
| `0x005957c0` | `SanitizeWideTextForChat(TextFilter *, wchar_t *text, int length)` | high for role, medium for exact signature |
| `0x0067adc8` | `g_pTextFilter` | high |
| `0x00575380` | `PacketBufferWriteUInt8` | high |
| `0x00574bb0` | `Socket::QueueAndSendPacket` | high |
| `0x0067a7ec` | `g_packetSender` / `Socket *` | high |
| `0x0060d170` | `WideCharToMultiByte` IAT function pointer | high |

## Adjacent Helper Split

`0x005b1820-0x005b1983` is not padding. It is a standalone `ret 8` helper taking two wide-string arguments, serializing the same opcode `0x19` target/message packet, and sending it through `g_packetSender`.

Best current source-facing role:

```cpp
static void SendTargetMessagePacket(const wchar_t *recipientName,
                                    const wchar_t *messageText);
```

Confidence is medium because no route was found:

- Direct PE rel32 scan found zero code refs to `0x005b1820`.
- Dword scan across `.text`, `.rdata`, and `.data` found zero pointer hits to `0x005b1820`.
- The helper has no `this` receiver and does not read a pane field, so it should not be folded into `SayToUserMessageInputPane`.
- It is physically between the legacy class submit and modern constructor and shares the same target-message packet shape. The best parent, if a child page is created later, is [UID:0000N9] `SayInputPanes`, with no class owner until liveness is proven.

Recommended exact future page:

```text
by-memory/0x005b1820-0x005b1983.SayTargetMessagePacketHelper.md
```

That page should remain non-emitting or low-code until a route is found. It can still document the helper as a high-probability retained static helper or dead stripped source function.

## Source Placement

Keep [UID:0000N9] `SayInputPanes` as owner/emitter.

Owner ranking:

1. `SayInputPanes.cpp`: best supported. It already owns the say/shout/whisper/group/plan target-message input family, direct prompt fragments, current-mode dispatcher, and sibling class docs.
2. Possible future `WhisperInputPanes.cpp`: plausible if source import proves a split, but weaker than the existing route. No binary evidence separates only the whisper classes into a distinct source file.
3. `SayToUserNameInputPane`: rejected as owner. It inline-constructs the legacy message pane in one branch and opens the modern pane in the other, but it is a sibling/predecessor class.
4. `NewSayToUserMessageInputPane`: rejected as owner. It shares protocol behavior but has separate vtables, prompt, constructor routes, and key handling.
5. `UserListPane`: rejected as owner. It has one direct constructor callsite and supplies a selected username, but it is a caller/consumer.
6. `Socket`, `PacketBuffer`, `PasswordGuard`, and `TextFilter`: rejected as owners. They own shared dependencies only.

## First-Draft Method C++ For Future Exact Children

These drafts are source-shaped and intentionally omit vtable stores, EH/cookie scaffolding, inline adjusted-this artifacts, and generated scalar-deleting wrappers.

Constructor draft:

```cpp
SayToUserMessageInputPane::SayToUserMessageInputPane(const wchar_t *recipientName)
    : LineInputPane(0)
{
    wcscpy_s(m_recipientName, 128, recipientName);

    wchar_t prompt[128];
    swprintf_s(prompt, 128, L"-> %s: ", m_recipientName);
    SetPromptText(prompt);
}
```

Submit draft:

```cpp
void SayToUserMessageInputPane::OnSubmitInput()
{
    if (TextLength() <= 0) {
        return;
    }

    wchar_t messageText[256] = {};
    CopyText(messageText, 0xff);

    ValidateChatInputOrThrowPasswordError(messageText);
    g_pTextFilter->SanitizeWideTextForChat(messageText,
        static_cast<int>(wcslen(messageText)));

    char recipientBytes[256] = {};
    const int recipientLen = WideCharToMultiByte(
        CP_ACP, 0, m_recipientName, static_cast<int>(wcslen(m_recipientName)),
        recipientBytes, sizeof(recipientBytes), nullptr, nullptr);
    if (recipientLen >= 0x100) {
        return;
    }

    char messageBytes[256] = {};
    const int messageLen = WideCharToMultiByte(
        CP_ACP, 0, messageText, static_cast<int>(wcslen(messageText)),
        messageBytes, sizeof(messageBytes), nullptr, nullptr);
    if (messageLen >= 0x100) {
        return;
    }

    unsigned char packet[0x230] = {};
    unsigned char *out = packet;
    PacketBufferWriteUInt8(0x19, out++);
    PacketBufferWriteUInt8(static_cast<unsigned char>(recipientLen), out++);
    memcpy(out, recipientBytes, recipientLen);
    out += recipientLen;
    PacketBufferWriteUInt8(static_cast<unsigned char>(messageLen), out++);
    memcpy(out, messageBytes, messageLen);
    out += messageLen;

    const int packetLength = static_cast<int>(out - packet);
    if (packetLength >= 0x12c) {
        return;
    }

    g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength));
}
```

Implementation notes:

- The real binary uses local packet offsets rather than an advancing pointer. The pointer style above is acceptable source C++ for reconstruction.
- If the project models packet writes as destination-first helpers, adjust the call spelling to match the final `PacketBuffer` API. The semantic packet shape is stable.
- The binary failfast path on oversized conversions is compiler/runtime validation behavior. Human source can return, assert, or use the project-local checked packet helper once that helper policy is settled.

## Exact No-Code Proof For Generated Support

Do not emit C++ bodies for the following support functions:

| Range | Proof |
| --- | --- |
| `0x005b7820-0x005b782b` | Adjustor thunk subtracts `0xa0` from `ecx` and jumps to `0x005b7af0`; no independent source logic. |
| `0x005b782b-0x005b7836` | Adjustor thunk subtracts `0xa4` from `ecx` and jumps to `0x005b7af0`; no independent source logic. |
| `0x005b7af0-0x005b7b2b` | Scalar deleting destructor wrapper calls `LineInputPane` cleanup and conditionally frees memory; shared by target-message panes through vtable slots, not a handwritten class destructor. |

The source class should expose a normal virtual destructor declaration. If a future exact destructor page is created, it should remain generated/no-code with this proof.

## Heuristic / Inference Reanalysis And Validation

Resolved or high-probability inferences:

- Field `this+0x108`: resolved as `m_recipientName[128]`. Evidence: constructor and inline branch copy with `_wcscpy_s(..., 0x80, ...)`; submit reads the same buffer as packet recipient.
- Object size: `0x208`. Evidence: user-list and recipient-name branches allocate `0x208`; scalar deleting destructor array-delete path passes `0x208`.
- Submit method name: best source-facing name `OnSubmitInput()`, with `OnSubmit` acceptable as existing doc spelling. Evidence: primary vtable slot `0x0062f744 -> 0x005b1640`, identical role to modern `NewSayToUserMessageInputPane::OnSubmitInput`.
- `byte_66DA97`: resolved as `g_useEpfAssets`; local effect is modern versus legacy direct-message pane selection.
- `dword_67A7EC`: resolved as `g_packetSender` / `Socket *`; reject generated `CashShopRequest *` aliases.
- `dword_67ADC8`: resolved as `g_pTextFilter`; submit uses it only as sanitizer dependency, not owner.
- Legacy/modern split: resolved as separate classes with shared protocol.
- Destructor ownership: generated support only, no custom resource ownership in the legacy class beyond inherited `LineInputPane` cleanup.

Rejected alternatives:

- Not a dead legacy class: direct constructor call from `UserListPane::OpenSayToUserMessageInputPane` remains live, and the recipient-name flow inline-constructs the class in the legacy branch.
- Not a modern-class alias: modern has separate constructor, prompt, key handler, and vtables.
- Not a protocol owner: `Socket` and `PacketBuffer` own shared send/write helpers only.
- Not owned by `PasswordGuard` or `TextFilter`: those are submit dependencies.
- Not safe to fold `0x005b1820` into the class: no `this` receiver, no route, no vtable entry, and no field access.

Open questions after reanalysis:

- Exact original spelling for the submit virtual remains unproven between `OnSubmit`, `OnSubmitInput`, and a project-local callback name. Use `OnSubmitInput()` as the best source-facing role and keep the existing label as an alias if needed.
- Exact final source-file split between `SayInputPanes.cpp` and a possible `WhisperInputPanes.cpp` is not provable from stripped binary. Existing owner/emitter route remains stronger.
- The adjacent `0x005b1820` helper's liveness is unresolved after negative direct scans. Best role is a retained static target-message packet helper, but do not assign it to this class without a route.

## Evidence Checked

Instructions and workflow:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B013/goal.md`
- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`

Target and support docs:

- `by-class/SayToUserMessageInputPane.md`
- `by-file/SayInputPanes.md`
- `by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md`
- `by-class/NewSayToUserMessageInputPane.md`
- `by-class/SayToUserNameInputPane.md`
- `by-memory/0x005b3cb0-0x005b4219.SayToUserNameInputPane.md`
- `by-memory/0x00630a18-0x00630a44.DirectWhisperPromptFragments.md`
- `by-class/LineInputPane.md`
- `by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md`
- `by-memory/0x004f2300-0x004f230f.LineInputPaneCopyText.md`
- `by-memory/0x004f2310-0x004f231b.LineInputPaneTextLength.md`
- `by-memory/0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md`
- `by-global/g_pTextFilter.md`
- `by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md`
- `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`
- `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
- `by-global/g_packetSender.md`
- `by-global/g_useEpfAssets.md`
- `by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md`
- `by-class/SayToGroupMessageInputPane.md`
- `by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md`
- `by-class/SayToPlanMessageInputPane.md`
- `auto-generated/NexusTK/social/SayInputPanes.cpp`

Prior reports:

- `tools/leaser/Agents/Agent-B014/research/000099-NewSayToUserMessageInputPane-source-quality.md`
- `tools/leaser/Agents/Agent-B003/research/0000C7-SayToUserNameInputPane-source-quality.md`

Direct PE evidence:

- Disassembled `0x005b1570-0x005b1631`, `0x005b1640-0x005b1812`, `0x005b1820-0x005b1983`, `0x005b7820-0x005b7836`, and `0x005b7af0-0x005b7b2b`.
- Disassembled legacy inline construction branch `0x005b419b-0x005b41f9`.
- Disassembled user-list modern/legacy open branch around `0x0059edc6` and `0x0059edf7`.
- Scanned `.text` rel32 refs to `0x005b1570`, `0x005b1640`, `0x005b1820`, `0x005b1990`, `0x005b7820`, `0x005b782b`, and `0x005b7af0`.
- Scanned `.text`, `.rdata`, and `.data` dword hits to legacy vtable/method/prompt/sender addresses.
- Verified boundary bytes around `0x005b1631`, `0x005b1812`, `0x005b1820`, `0x005b1983`, `0x005b7af0`, and `0x005b7b2b`.

IDA MCP was not exposed as a callable namespace in this Codex run. Existing IDA-backed docs were used as prior evidence, and direct PE/Capstone scans were used for independent route, boundary, vtable, and packet-shape checks. No IDA database writes were made.

## Recommended Exact Target Changes

In `by-class/SayToUserMessageInputPane.md`:

1. Change metadata:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. Add declaration-level C++ from the executive recommendation.

3. Update the method table:

- Constructor: `SayToUserMessageInputPane(const wchar_t *recipientName)`, exact half-open range `0x005b1570-0x005b1631`.
- Submit override: `OnSubmitInput()` / existing alias `OnSubmit`, exact range `0x005b1640-0x005b1812`.
- Adjustor thunks: `0x005b7820-0x005b782b` and `0x005b782b-0x005b7836`, generated/no-code.
- Scalar deleting destructor: `0x005b7af0-0x005b7b2b`, generated/no-code, shared target-message-pane support.

4. Add source-quality notes:

- Constructor direct route `0x0059edf7`.
- Inline legacy construction branch in `SayToUserNameInputPane::OnRecipientNameConfirmed` at `0x005b419b-0x005b41f9`.
- Vtable submit slot `0x0062f744 -> 0x005b1640`.
- Vtable support slots `0x0062f6fc -> 0x005b7af0`, `0x0062f74c -> 0x005b7820`, and `0x0062f77c -> 0x005b782b`.
- Field layout: object size `0x208`, recipient buffer `m_recipientName[128]` at `+0x108`, inherited prompt/edit fields from `LineInputPane`.
- Packet shape: opcode `0x19`, one-byte recipient length, recipient bytes, one-byte message length, message bytes, total bound `< 0x12c`.
- Helper/global names: `g_useEpfAssets`, `g_pTextFilter`, `SanitizeWideTextForChat`, `ValidateChatInputOrThrowPasswordError`, `PacketBufferWriteUInt8`, `g_packetSender`, and `Socket::QueueAndSendPacket`.

5. Add a sibling split caveat:

- `0x005b1820-0x005b1983` is a no-route standalone target-message packet helper candidate. It should be split later under `SayInputPanes`, not absorbed into this class page.

## Recommended Support-Doc Changes

- `by-file/SayInputPanes.md`: update the `SayToUserMessageInputPane` row to say declaration-level class C++ is ready, exact method bodies should live in future child pages, and the legacy pane is selected by local `g_useEpfAssets != 1` direct-message flow.
- `by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md`: correct the legacy constructor endpoint to `0x005b1631`, add `0x005b1631-0x005b1640` padding, add `0x005b1812-0x005b1820` padding, and classify `0x005b1820-0x005b1983` as a no-route standalone target-message packet helper candidate followed by `0x005b1983-0x005b1990` padding.
- `by-class/NewSayToUserMessageInputPane.md`: keep the modern/legacy comparison in sync: same opcode `0x19` packet, separate prompts/vtables/key-flow.
- `by-class/SayToUserNameInputPane.md` and `by-memory/0x005b3cb0-0x005b4219.SayToUserNameInputPane.md`: ensure `byte_66DA97` is described as `g_useEpfAssets`; preserve the inline legacy construction wording rather than claiming a direct call to `0x005b1570`.
- `by-memory/0x00630a18-0x00630a44.DirectWhisperPromptFragments.md`: add the endpoint correction if it quotes the legacy constructor as size `0xc1`; keep the literal roles unchanged.
- Optional future child: create `by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md` or exact constructor/submit children before method-body C++ is emitted.
- Optional future sibling: create `by-memory/0x005b1820-0x005b1983.SayTargetMessagePacketHelper.md` as a no-route packet helper candidate.

## Coverage Text

Do not edit `by-memory/-coverage-report.md` during the B-agent pass.

No direct `by-memory/-coverage-report.md` replacement row is required if the supervisor only updates the class page. If the supervisor also updates [UID:0001LY] to include the endpoint/sibling-gap corrections, replace its existing row with:

```markdown
    - [UID:0001LY][0x005b1570-0x005b2562.SayTargetMessageInputPanes](by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md) 0x005b1570-0x005b2562 | target-message input pane aggregate | SayTargetMessageInputPanes : reconstructable : 86% : strong : B013 legacy direct-message source-quality reanalysis corrects `SayToUserMessageInputPane` constructor range to `0x005b1570-0x005b1631`, confirms submit `0x005b1640-0x005b1812`, `0x005b1631-0x005b1640` and `0x005b1812-0x005b1820` padding, class field `m_recipientName[128]` at `+0x108`, opcode `0x19` recipient/message packet layout, `g_packetSender`/TextFilter/PasswordGuard helper names, and identifies `0x005b1820-0x005b1983` as a no-route standalone target-message packet helper candidate that should be split separately from the legacy class.
```

Recommended exact replacement row for `by-class/-coverage-report.md`:

```markdown
- [UID:0000C6][SayToUserMessageInputPane](by-class/SayToUserMessageInputPane.md) : reconstructable : 87% : very strong : B013 source-quality reanalysis resolves the legacy direct-message class shape under `SayInputPanes`: constructor `SayToUserMessageInputPane(const wchar_t *recipientName)` with corrected half-open range `0x005b1570-0x005b1631`, virtual `OnSubmitInput()` at `0x005b1640-0x005b1812`, direct constructor route `0x0059edf7`, inline legacy construction branch in `SayToUserNameInputPane`, object size `0x208`, `m_recipientName[128]` at `+0x108`, prompt `-> %s: `, opcode `0x19` recipient/message packet identical to the modern pane, `g_useEpfAssets` legacy-vs-modern branch, `g_pTextFilter`/PasswordGuard/PacketBuffer/g_packetSender helper names, compiler-generated thunk/destructor no-code policy, and declaration-level class C++ readiness with method bodies reserved for exact by-memory children.
```

## Validator Needs

No validators were run because this is report-only and no by-* docs were edited.

Recommended validation commands after accepted implementation:

> Executable block R001 was removed from this report and preserved verbatim in [0000C6-SayToUserMessageInputPane-class-source-quality-removed.md](0000C6-SayToUserMessageInputPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result for each scoped validator: `ok: 1`, class score update for `0000C6`, and autogen refresh without parent-gate regressions. Add validators for any newly created exact child pages if the supervisor chooses to split `0x005b1570-0x005b1812` or `0x005b1820-0x005b1983`.

## IDA Rename / Type / Comment Recommendations

Do not apply during this report pass.

| Item | Recommendation | Confidence |
| --- | --- | --- |
| `0x005b1570` | rename/type as `SayToUserMessageInputPane::SayToUserMessageInputPane(const wchar_t *recipientName)`; set end to `0x005b1631` if the database currently truncates at `0x005b1630` | high |
| `0x005b1640` | rename/type as `SayToUserMessageInputPane::OnSubmitInput()` or accepted project spelling `OnSubmit()` | high for role, medium-high for exact spelling |
| `0x005b1820` | comment as no-route `SendTargetMessagePacket(const wchar_t *recipientName, const wchar_t *messageText)` candidate, not class-owned | medium |
| `0x005b7820` | generated adjustor thunk, receiver adjustment `-0xa0`, jumps to scalar deleting destructor | high |
| `0x005b782b` | generated adjustor thunk, receiver adjustment `-0xa4`, jumps to scalar deleting destructor | high |
| `0x005b7af0` | shared scalar deleting destructor for target-message panes, generated/no-code | high |
| `0x0062f6fc`, `0x0062f74c`, `0x0062f77c` | label as legacy `SayToUserMessageInputPane` primary/secondary/tertiary vtable views | high |
| `0x0062f744` | comment as submit vtable slot to `0x005b1640` | high |
| `this + 0x108` | `m_recipientName[128]` | high |
| `0x00630a20` | `L"-> %s: "` legacy direct-message prompt literal | high |
| `0x00630a30` | `L"To %s : "` modern direct-message prompt literal | high |
| `0x0067adc8` | `g_pTextFilter` / `TextFilter *` | high |
| `0x0067a7ec` | `g_packetSender` / `Socket *` | high |
| `0x0066da97` | `g_useEpfAssets`; comment local use as modern-vs-legacy direct-message selector | high |

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B013/research/0000C6-SayToUserMessageInputPane-class-source-quality.md`
- Modified: none
- Target/support by-* docs: not edited
- `by-memory/-coverage-report.md`: not edited

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/0000C6-SayToUserMessageInputPane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"0000C6"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000C6-SayToUserMessageInputPane-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/0000C6-SayToUserMessageInputPane-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000C6"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
