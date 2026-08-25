** TARGET-REPORT-UID:0001LY **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001LY SayTargetMessageInputPanes Source-Quality Research

## Status

FINISHED B-agent report-only pass. No by-* documentation was edited. `by-memory/-coverage-report.md` was not edited.

## Target

- UID: `0001LY`
- Primary doc: `source-3/project-documentation/by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0001LY-SayTargetMessageInputPanes-source-quality.md`
- Current metadata: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000N9`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N9`, blank formal C++
- Current source route in prose: [UID:0000N9] `SayInputPanes`

## Executive Recommendation

Reclassify [UID:0001LY] as a reviewed, non-emitting split/index over the target-message input pane family:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

The physical range is real source-authored code, but the aggregate is not one source-level method or class. It spans legacy direct-message class methods, three standalone no-route packet helper clones, the modern direct-message class, the group-message class, and the clan/plan-message class. Emitting formal C++ from this aggregate would either duplicate exact child/class emitters or hide the no-route helper/liveness caveats. Exact class pages and exact future method/helper children should carry source C++.

Keep [UID:0000N9] `NexusTK/social/SayInputPanes.cpp` as the best source file for exact source-bearing children. Keep [UID:0000JS] `Group` as a feature cross-reference for the group-message pane, not as the direct source owner. Treat `SayToPlanMessageInputPane` as a historical documentation/generated name; the best source-facing semantic direction is `SayToClanMessageInputPane`, with medium-high confidence, because every live branch and literal says `Clan => ` / `!`.

## Evidence Checked

Instructions and workflow:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B001/goal.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B001/notes.md`
- `.codex/AGENTS.md`

Target and support docs:

- `by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md`
- `by-file/SayInputPanes.md`
- `by-class/SayToUserMessageInputPane.md`
- `by-class/NewSayToUserMessageInputPane.md`
- `by-class/SayToGroupMessageInputPane.md`
- `by-class/SayToPlanMessageInputPane.md`
- `by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md`
- `by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md`
- `by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md`
- `by-file/Group.md`
- `by-memory/0x006309d0-0x006309dc.SayModeGroupClanPrefixFragments.md`
- `by-memory/0x00630a18-0x00630a44.DirectWhisperPromptFragments.md`
- `by-memory/0x00630a44-0x00630a6c.GroupClanPromptFragments.md`
- `by-file/PacketBuffer.md`
- `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`
- `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
- `by-global/g_packetSender.md`
- `by-global/g_pTextFilter.md`
- `by-global/g_useEpfAssets.md`
- `by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md`
- `auto-generated/NexusTK/social/SayInputPanes.cpp`
- `source-3/simroot_v2/class_SayToUserMessageInputPane.cpp`
- `source-3/simroot_v2/class_NewSayToUserMessageInputPane.cpp`
- `source-3/simroot_v2/class_SayToGroupMessageInputPane.cpp`
- `source-3/simroot_v2/class_SayToPlanMessageInputPane.cpp`

Prior B-report leads checked and revalidated as needed:

- `tools/leaser/Agents/Agent-B013/research/0000C6-SayToUserMessageInputPane-class-source-quality.md`
- `tools/leaser/Agents/Agent-B014/research/000099-NewSayToUserMessageInputPane-source-quality.md`
- `tools/leaser/Agents/Agent-B003/research/0000C7-SayToUserNameInputPane-source-quality.md`

Direct PE / Capstone evidence:

- Read-only PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Size: `2679296`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA-256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- Image base: `0x00400000`
- `.text`: `0x00401000-0x0060c600`
- `.rdata`: `0x0060d000-0x0066c200`
- `.data`: `0x0066d000-0x0069ce24`
- Disassembled and byte-checked `0x005b1570-0x005b2562`, including exact non-CC runs and padding in the three previously open spans.
- Scanned `.text` direct `E8`/`E9` rel32 refs to target-family starts and static-helper starts.
- Scanned `.text`, `.rdata`, and `.data` dword hits for method starts, vtable bases, submit slots, adjustor/scalar-deleting destructor starts, prompt/prefix literals, `g_packetSender`, `g_pTextFilter`, and `g_useEpfAssets`.
- Decoded UTF-16 prompt/prefix literals at `0x006309d0`, `0x006309d8`, `0x00630a18`, `0x00630a20`, `0x00630a30`, `0x00630a44`, and `0x00630a58`.

IDA MCP note:

- No IDA MCP endpoint/tool namespace was exposed in this Codex run. Existing IDA-backed docs were used as prior evidence, and direct PE/Capstone scans were used for independent range, route, pointer, vtable, padding, and literal checks. No IDA database writes were made.

## Exact Boundary And Split Results

The current target page still describes three internal spans as unresolved. Direct PE reanalysis resolves all three.

| Span | Result | Evidence |
| --- | --- | --- |
| `0x005b1568-0x005b1570` | predecessor padding | Eight `0xcc` bytes before the target start. Existing coverage already records this predecessor padding. |
| `0x005b1570-0x005b1631` | `SayToUserMessageInputPane::SayToUserMessageInputPane(const wchar_t *recipientName)` | Constructor body ends with `ret 4` at `0x005b162e`; the byte at `0x005b1630` is the `ret` immediate, so the true half-open endpoint is `0x005b1631`, not `0x005b1630`. |
| `0x005b1631-0x005b1640` | padding | Fifteen `0xcc` bytes. |
| `0x005b1640-0x005b1812` | `SayToUserMessageInputPane::OnSubmitInput()` / existing `OnSubmit` alias | Live vtable slot `0x0062f744 -> 0x005b1640`; no direct rel32 callers. Builds opcode `0x19` target/message payload from `this+0x108` recipient buffer and current line text. |
| `0x005b1812-0x005b1820` | padding | Fourteen `0xcc` bytes. |
| `0x005b1820-0x005b1983` | standalone no-route target-message packet helper clone | Real body with normal prologue, two stack wchar arguments, opcode `0x19`, target/message string conversion, `QueueAndSendPacket`, normal `ret 8` at `0x005b197b`, and range-failure tail call at `0x005b197e`. No direct rel32 route and no dword pointer hits. |
| `0x005b1983-0x005b1990` | padding | Thirteen `0xcc` bytes. |
| `0x005b1990-0x005b1a51` | `NewSayToUserMessageInputPane::NewSayToUserMessageInputPane(const wchar_t *recipientName)` | Constructor body with `ret 4`; installs modern vtables `0x0062f788`, `0x0062f7d8`, `0x0062f808`, copies `this+0x108`, formats `To %s : `. |
| `0x005b1a51-0x005b1a60` | padding | Fifteen `0xcc` bytes. |
| `0x005b1a60-0x005b1c32` | `NewSayToUserMessageInputPane::OnSubmitInput()` | Vtable slot `0x0062f7d0 -> 0x005b1a60`; same opcode `0x19` recipient/message packet shape as legacy. |
| `0x005b1c32-0x005b1c40` | padding | Fourteen `0xcc` bytes. |
| `0x005b1c40-0x005b1d42` | `NewSayToUserMessageInputPane::OnKeyInput(const InputEvent *event)` / existing `HandleKeyInput` alias | Vtable slot `0x0062f7e0 -> 0x005b1c40`; empty Backspace returns to `SayToUserNameInputPane`, otherwise delegates to `LineInputPane::HandleKeyInput`. |
| `0x005b1d42-0x005b1d50` | padding | Fourteen `0xcc` bytes. |
| `0x005b1d50-0x005b1eb3` | standalone no-route target-message packet helper clone | Same source-shaped helper as `0x005b1820`, with normal `ret 8` at `0x005b1eab` and range-failure tail call at `0x005b1eae`; no direct rel32 route and no dword pointer hits. |
| `0x005b1eb3-0x005b1ec0` | padding | Thirteen `0xcc` bytes. |
| `0x005b1ec0-0x005b1f7e` | `SayToGroupMessageInputPane::SayToGroupMessageInputPane(const wchar_t *groupName)` | Existing exact child [UID:0001LZ]; installs group vtables `0x0062f814`, `0x0062f864`, `0x0062f894`, copies `this+0x108`, formats `Group => `. |
| `0x005b1f7e-0x005b1f80` | padding | Two `0xcc` bytes. |
| `0x005b1f80-0x005b2152` | `SayToGroupMessageInputPane::SendGroupMessage()` / `OnSubmitInput()` role | Existing exact child [UID:0001LZ]; vtable slot `0x0062f85c -> 0x005b1f80`; opcode `0x19`, group-name length/string, message length/string. |
| `0x005b2152-0x005b2160` | padding | Fourteen `0xcc` bytes. |
| `0x005b2160-0x005b22c3` | standalone no-route target-message packet helper clone | Same source-shaped helper as `0x005b1820` and `0x005b1d50`, with normal `ret 8` at `0x005b22bb` and range-failure tail call at `0x005b22be`; no direct rel32 route and no dword pointer hits. |
| `0x005b22c3-0x005b22d0` | padding | Thirteen `0xcc` bytes. |
| `0x005b22d0-0x005b238e` | `SayToPlanMessageInputPane::SayToPlanMessageInputPane(const wchar_t *targetName)`, best semantic alias `SayToClanMessageInputPane::SayToClanMessageInputPane` | Installs vtables `0x0062f8a0`, `0x0062f8f0`, `0x0062f920`, copies `this+0x108`, formats `Clan => `. |
| `0x005b238e-0x005b2390` | padding | Two `0xcc` bytes. |
| `0x005b2390-0x005b2562` | plan/clan submit override, best semantic alias `SayToClanMessageInputPane::OnSubmitInput()` | Vtable slot `0x0062f8e8 -> 0x005b2390`; opcode `0x19`, target length/string, message length/string. |
| `0x005b2562-0x005b2570` | successor padding sample | Fourteen `0xcc` bytes checked; target exclusive end remains `0x005b2562`. |

## Packet Shape And Field Names

All live submit methods and all three standalone helper clones share the same target-message packet shape:

| Packet field | Encoding | Source-facing name direction |
| --- | --- | --- |
| opcode | one byte `0x19` at packet offset `0` | `kSayTargetMessageOpcode` / `kChatTargetMessageOpcode`; exact original constant name not proven. |
| target length | one byte after `WideCharToMultiByte` | `targetNameByteLen`, `recipientNameByteLen`, or class-specific `groupNameByteLen`. |
| target bytes | multibyte target string, no counted terminator | `targetNameBytes`; source wide source is `m_recipientName[128]`, `m_groupName[128]`, or `m_clanName[128]` depending class. |
| message length | one byte after `WideCharToMultiByte` | `messageByteLen`. |
| message bytes | sanitized message text bytes, no counted terminator | `messageBytes`. |

Bounds and helper behavior:

- Each wide-to-multibyte conversion caps at `0x100` / 256 bytes and range-fails on `>= 0x100`.
- The combined payload length is `targetLen + messageLen + 3`.
- The combined payload is range-checked against `0x12c` / 300 bytes.
- The packet builder writes a scratch null terminator after the counted packet bytes before calling `QueueAndSendPacket`; this null is not a protocol field.
- `0x00575380` should be documented as `PacketBufferWriteUInt8` or the accepted local `PacketBufferWriteByte` spelling.
- `0x00574bb0` should be documented as `Socket::QueueAndSendPacket`, reached through [UID:0000Q5] `g_packetSender`.
- `0x00465890` remains `ValidateChatInputOrThrowPasswordError`.
- `0x005957c0` / [UID:0000SG] `g_pTextFilter` should be documented as `SanitizeWideTextForChat` / text-filter sanitizer.
- `0x004f2310` and `0x004f2300` are `LineInputPane::TextLength()` and `LineInputPane::CopyText(...)`.

## Route And Liveness Findings

Direct PE rel32 route scan:

| Target | Direct rel32 result |
| --- | --- |
| `0x005b1570` | One constructor call at `0x0059edf7` in `UserListPane::OpenSayToUserMessageInputPane`. |
| `0x005b1640` | No direct rel32 callers; live through vtable slot `0x0062f744`. |
| `0x005b1820` | No direct rel32 callers and no dword pointer hits. |
| `0x005b1990` | Constructor calls at `0x00554e0a`, `0x0059edc6`, `0x005a51e9`, `0x005a5544`, and `0x005b4128`. |
| `0x005b1a60` | No direct rel32 callers; live through vtable slot `0x0062f7d0`. |
| `0x005b1c40` | No direct rel32 callers; live through vtable slot `0x0062f7e0`. |
| `0x005b1d50` | No direct rel32 callers and no dword pointer hits. |
| `0x005b1ec0` | No direct rel32 callers; group construction also appears inline in dispatcher/open helpers via vtable stores and prompt/prefix literals. |
| `0x005b1f80` | No direct rel32 callers; live through vtable slot `0x0062f85c`. |
| `0x005b2160` | No direct rel32 callers and no dword pointer hits. |
| `0x005b22d0` | No direct rel32 callers; clan/plan construction also appears inline in dispatcher/open helpers via vtable stores and prompt/prefix literals. |
| `0x005b2390` | No direct rel32 callers; live through vtable slot `0x0062f8e8`. |
| `0x005b7820` / `0x005b782b` | No direct calls; dword hits in secondary/tertiary vtables for legacy, modern, group, and clan/plan panes. |
| `0x005b7af0` | Rel32 jumps from adjustor thunks `0x005b7826` and `0x005b7831`; primary-vtable dword hits for all four target-message panes. |

Vtable route evidence:

- Legacy primary vtable base `0x0062f6fc` has scalar deleting destructor `0x005b7af0` and submit slot `0x0062f744 -> 0x005b1640`.
- Legacy secondary/tertiary vtable bases `0x0062f74c` and `0x0062f77c` route to generated adjustor thunks `0x005b7820` and `0x005b782b`.
- Modern primary vtable base `0x0062f788` has scalar deleting destructor `0x005b7af0`, submit slot `0x0062f7d0 -> 0x005b1a60`, and key slot `0x0062f7e0 -> 0x005b1c40`.
- Group primary vtable base `0x0062f814` has scalar deleting destructor `0x005b7af0` and submit slot `0x0062f85c -> 0x005b1f80`.
- Clan/plan primary vtable base `0x0062f8a0` has scalar deleting destructor `0x005b7af0` and submit slot `0x0062f8e8 -> 0x005b2390`.
- The same shared generated adjustor thunks appear in all secondary/tertiary target-message pane vtables.

Prompt/prefix literal evidence:

- `0x00630a20`: `L"-> %s: "`, refs at `0x005b15eb` and inline legacy construction `0x005b41d8`.
- `0x00630a30`: `L"To %s : "`, ref at `0x005b1a0b`.
- `0x00630a44`: `L"Group => "`, refs at `0x005a525e`, `0x005a55fa`, and `0x005b1f39`.
- `0x00630a58`: `L"Clan => "`, refs at `0x005a52f0`, `0x005a56ca`, and `0x005b2349`.
- `0x006309d0`: `L"!!"`, refs at `0x005a522a` and `0x005a55c6`.
- `0x006309d8`: `L"!"`, refs at `0x005a52bc` and `0x005a5696`.

## Source-Facing Class And Helper Shape

Class source declarations are ready at the class-page level; exact method-body C++ should live on exact by-memory children.

Recommended class shells:

```cpp
class SayToUserMessageInputPane : public LineInputPane
{
public:
    explicit SayToUserMessageInputPane(const wchar_t *recipientName);
    virtual ~SayToUserMessageInputPane();

protected:
    virtual void OnSubmitInput();

private:
    wchar_t m_recipientName[128]; // +0x108

    [[CHILDREN]]
};

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
    wchar_t m_recipientName[128]; // +0x108

    [[CHILDREN]]
};

class SayToGroupMessageInputPane : public LineInputPane
{
public:
    explicit SayToGroupMessageInputPane(const wchar_t *groupName);
    virtual ~SayToGroupMessageInputPane();

protected:
    virtual void OnSubmitInput();

private:
    wchar_t m_groupName[128]; // +0x108

    [[CHILDREN]]
};

// Current documentation UID/name is SayToPlanMessageInputPane.
// Source-facing semantic direction is clan, not plan.
class SayToClanMessageInputPane : public LineInputPane
{
public:
    explicit SayToClanMessageInputPane(const wchar_t *clanName);
    virtual ~SayToClanMessageInputPane();

protected:
    virtual void OnSubmitInput();

private:
    wchar_t m_clanName[128]; // +0x108

    [[CHILDREN]]
};
```

Best source-facing standalone helper role for all three no-route bodies:

```cpp
static void SendTargetMessagePacket(const wchar_t *targetName,
                                    const wchar_t *messageText);
```

This helper name is a high-probability role name, not proven original spelling. It is better than class ownership because the bodies:

- use `ret 8`, not `ret 4`;
- read two stack arguments and no `ecx`/`this` class field;
- have no vtable entries;
- have no rel32 callers or data pointer hits in direct PE scans;
- duplicate the target/message packet builder shape shared by all target-message panes.

Because the helper clones are no-route, their exact child pages should either stay `RECONSTRUCTABLE:FALSE` / no-code until a route is found, or be marked as retained source-style static helpers with a strong liveness caveat. They should not be folded into any of the class pages.

## First-Draft C++ Policy

Do not emit formal C++ on [UID:0001LY]. The exact no-code proof for the aggregate is target-specific:

- The range has multiple primary owners: [UID:0000C6] legacy direct-message, [UID:000099] modern direct-message, [UID:0000C4] group-message, and [UID:0000C5] plan/clan-message.
- The range contains three no-route helper clones that have no class receiver, no vtable route, no direct call route, and no pointer route.
- The range contains padding rows interleaved between independent functions.
- Formal C++ on the aggregate would duplicate class C++ from class pages or future exact by-memory children.
- The current generated output already shows only an empty marker for [UID:0001LY] in `auto-generated/NexusTK/social/SayInputPanes.cpp`, which is the right output class after reclassification.

Emitting paths that are justified after child split:

- [UID:0000C6] `SayToUserMessageInputPane` class page should emit declaration-level C++ from B013; method-body C++ belongs to a future exact by-memory child `0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md` or split constructor/submit children.
- [UID:000099] `NewSayToUserMessageInputPane` class page should emit declaration-level C++ from B014; method-body C++ belongs to a future exact child covering `0x005b1990-0x005b1d42` or split constructor/submit/key children.
- [UID:0001LZ] `SayToGroupMessageInputPane` is exact enough for first-draft constructor/submit C++ after a source-quality method-name pass; the page currently stays blank because exact helper spelling and source split have not been callback-implemented.
- A future `0x005b22d0-0x005b2562.SayToClanMessageInputPaneMethods.md` child should emit the constructor/submit body once the plan/clan naming decision is accepted.

## Heuristic / Inference Reanalysis And Validation

### Aggregate Versus Exact Children

Evidence checked:

- Target page currently has one `RECONSTRUCTABLE:TRUE` aggregate route under `SayInputPanes`.
- Direct PE proves the aggregate contains multiple independent class bodies, three standalone no-route helpers, and padding.
- Existing repository pattern reclassifies broad mixed/multi-owner indexes as `RECONSTRUCTABLE:FALSE` with blank emitters, while exact children carry source ownership.

Candidate interpretations:

1. Keep [UID:0001LY] reconstructable and emitting through `SayInputPanes`.
2. Keep owner `0000N9` but blank formal C++.
3. Reclassify as non-emitting split/index, owner/emitter blank, with source-file route described in prose for exact children.

Rejected alternatives:

- Option 1 is unsafe because one formal C++ block cannot represent four classes plus three no-route helpers.
- Option 2 leaves autogen with a misleading source-emitter route for a physical index.

Best direction:

- Use option 3. Set `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, and blank `EMITTER_UIDS`; state that exact children still route to [UID:0000N9] where source-bearing.

Score/C++ impact:

- Raise confidence because all gap classifications are now resolved, but remove aggregate C++ eligibility.

### Internal Span Classification

Evidence checked:

- PE bytes and Capstone disassembly for every previously open span.
- Direct rel32 scans and dword pointer scans for `0x005b1820`, `0x005b1d50`, and `0x005b2160`.

Candidate interpretations:

1. The gaps are padding.
2. The gaps are compiler thunks/destructors.
3. The gaps are source-style standalone helper bodies with no route.

Rejected alternatives:

- Padding is rejected because each gap contains a complete `push ebp; mov ebp, esp; sub esp, 0x238` packet-builder body.
- Compiler thunk/destructor is rejected because each helper has normal local buffers, `WideCharToMultiByte`, `PacketBufferWriteUInt8`, `QueueAndSendPacket`, and `ret 8`.

Best direction:

- Document `0x005b1820-0x005b1983`, `0x005b1d50-0x005b1eb3`, and `0x005b2160-0x005b22c3` as standalone no-route target-message packet helper clones, each followed and preceded by exact `0xcc` padding.

Score/C++ impact:

- This resolves the target's largest open issue and justifies raising the aggregate index score. The helpers themselves should not emit source C++ until a route is found or a retained-static-helper policy is accepted.

### Compiler-Generated Names And Support

Evidence checked:

- Vtable data at `0x0062f6fc-0x0062f930`.
- Dword hits for `0x005b7820`, `0x005b782b`, and `0x005b7af0`.
- Direct rel32 scan to `0x005b7af0` found jumps from adjustor thunks.

Candidate interpretations:

1. Class-authored destructors.
2. Shared compiler-generated scalar deleting destructor and adjustor thunks.

Rejected alternatives:

- Source-authored destructor bodies are rejected because the secondary/tertiary slots only adjust `this` and jump to the shared scalar deleting destructor, while the scalar deleting destructor performs inherited `LineInputPane` cleanup and conditional delete for all target-message panes.

Best direction:

- Document `0x005b7820` and `0x005b782b` as generated adjustor thunks and `0x005b7af0` as the shared generated scalar deleting destructor. Class pages should declare a virtual destructor only; no by-memory body C++ for the generated wrappers.

Score/C++ impact:

- Compiler/generated support is resolved and does not block class declaration C++; it does block treating these wrappers as source-authored method bodies.

### Owner And Source Placement

Evidence checked:

- `by-file/SayInputPanes.md` family inventory and source path `NexusTK/social/SayInputPanes.cpp`.
- `by-file/Group.md` says `SayToGroupMessageInputPane` is feature-related but likely belongs with the broader say/chat input family.
- Mode dispatcher [UID:0002RX] constructs/opens default say, shout, direct, group, and clan/plan branches.
- Prompt and prefix literals are grouped under [UID:0000N9].

Candidate interpretations:

1. `SayInputPanes.cpp` owns exact target-message input pane classes and helpers.
2. `Group.cpp` owns `SayToGroupMessageInputPane`.
3. `Clan.cpp` owns the `Clan => ` target-message pane.
4. Separate `WhisperInputPanes.cpp` / `GroupChatInput.cpp` / `ClanChatInput.cpp` source files existed.
5. No source owner or generated artifact.

Rejected alternatives:

- `Group.cpp` is weaker because the group class is physically interleaved with direct-message and clan/plan panes, uses the same opcode `0x19` target-message packet shape, and the Group file itself calls it a feature cross-reference.
- `Clan.cpp` is weaker for the same reason: the class is opened by the say-mode dispatcher and shares target-message machinery, not clan bank/status packet code.
- A generated/no-owner interpretation is rejected for live class bodies because vtables, prompts, constructor routes, and submit slots prove source-authored UI code.
- Separate source files are plausible but not better supported than current repository route; no binary boundary proves a file split.

Best direction:

- Exact source-bearing children should remain under [UID:0000N9] `SayInputPanes`.
- The aggregate itself should be parentless/non-emitting.
- `Group` and `Clan` remain feature cross-references.

Score/C++ impact:

- Source file route for exact children is strong enough for source C++ after split. Aggregate C++ stays blank.

### Plan Versus Clan Naming

Evidence checked:

- `0x00630a58` decodes as `Clan => `.
- Refs to `Clan => ` occur in `OpenInputPaneForCurrentSayMode` at `0x005a52f0`, in the standalone open helper `0x005a56ca`, and in the constructor `0x005b2349`.
- `0x006309d8` decodes as `!` and is the clan/plan branch prefix.
- Current class filename/UID is `SayToPlanMessageInputPane`; generated active view still emits that name.

Candidate interpretations:

1. Keep `SayToPlanMessageInputPane` as the source-facing class name.
2. Rename/reframe source-facing class as `SayToClanMessageInputPane`, while preserving current UID/path until a rename callback.
3. Use only neutral `SayTargetMessageInputPane`.

Rejected alternatives:

- Pure `Plan` source-facing naming is weak: no checked literal, prompt, or mode evidence says plan. All branch strings say clan.
- Pure neutral naming hides an important high-confidence semantic distinction between group and clan branches.

Best direction:

- Best source-facing name is `SayToClanMessageInputPane` with medium-high confidence. Keep the current documentation filename and UID until supervisor authorizes a rename/migration; update prose to state that `SayToPlanMessageInputPane` is a historical/generated label for the clan branch.

Score/C++ impact:

- Plan/clan naming no longer blocks a first draft for exact child pages if the accepted C++ uses `SayToClanMessageInputPane` as the source-facing alias and documents the current UID filename.

### Opcode `0x19` Field Names

Evidence checked:

- All four submit methods and all three helper clones write opcode `0x19`, then two one-byte-length multibyte strings.
- Class constructors copy the target/destination string into `this+0x108` with a `0x80` wchar bound.
- Group/clan dispatcher literals use `!!` and `!` as destination strings.

Candidate interpretations:

1. Direct-message-only packet.
2. Generic target-message packet with class-specific target semantics.

Rejected alternatives:

- Direct-message-only naming is rejected because group and clan/plan classes use the same opcode and layout.

Best direction:

- Document as target-message packet: `{ opcode 0x19, targetNameLen, targetNameBytes, messageLen, messageBytes }`.
- Class field names should be `m_recipientName[128]`, `m_groupName[128]`, and `m_clanName[128]`, all at `+0x108`.
- Generic helper argument names should be `targetName` and `messageText`.

Score/C++ impact:

- Packet fields are source-ready and should be incorporated into exact child pages and support docs.

### Raw No-Xref Helper Policy

Evidence checked:

- Direct scans found no `E8`/`E9`/branch routes or dword pointer hits for `0x005b1820`, `0x005b1d50`, or `0x005b2160`.
- Bodies are complete, non-padding, source-shaped packet helpers.
- Similar no-route packet helper pages elsewhere in the project use no-owner/non-emitting or retained-helper caveats unless a route is found.

Candidate interpretations:

1. Compiler-generated artifacts.
2. Dead stripped retained static helpers.
3. Unmodeled indirect callback targets.
4. Source helper clones emitted from separate translation units or inline/static copies.

Rejected alternatives:

- Compiler-generated artifact is rejected by normal packet-builder bodies.
- Indirect callback is currently unsupported because there are no pointer hits or vtable slots.

Best direction:

- Best current explanation: retained/dead or unreferenced static helper clones, likely source-level `SendTargetMessagePacket(const wchar_t *, const wchar_t *)` style helpers. Keep them out of class ownership until a route appears.

Score/C++ impact:

- The helpers support reclassifying the aggregate as a split/index. They should receive exact child pages if coverage wants no hidden raw code, but they should not force aggregate C++.

## Recommended Target Changes

In `by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md`:

1. Change metadata to:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. Keep formal C++ blank and replace the current "source-authored aggregate" wording with "reviewed non-emitting split/index".

3. Add/replace the boundary matrix using the exact ranges in this report, including:

- corrected legacy constructor endpoint `0x005b1570-0x005b1631`;
- padding `0x005b1631-0x005b1640`;
- helper `0x005b1820-0x005b1983`;
- padding `0x005b1983-0x005b1990`;
- helper `0x005b1d50-0x005b1eb3`;
- padding `0x005b1eb3-0x005b1ec0`;
- helper `0x005b2160-0x005b22c3`;
- padding `0x005b22c3-0x005b22d0`;
- plan/clan constructor/submit and `Clan => ` naming evidence.

4. Replace stale open questions:

- The three internal spans are solved as no-route standalone helper clones plus padding.
- The aggregate source C++ decision is solved as no aggregate C++.
- The owner/source decision is solved as parentless aggregate, with exact source children under `SayInputPanes`.
- The plan/clan naming decision should become "best source-facing direction is clan; current `SayToPlan...` filename is a historical/generated label until rename callback."

5. Add a "Packet Shape" section for opcode `0x19` with exact fields, bounds, helper/global names, and class field names.

6. Add a "2026-06-19 B001 Evidence" change entry:

- PE path and hashes.
- `.text`, `.rdata`, `.data` ranges.
- Exact no-route helper discoveries and padding.
- Direct route scan results for constructor starts, vtable-only submit/key methods, and helper starts.
- Prompt/prefix literal decodes and xrefs.
- No IDA MCP endpoint available in this Codex run; existing IDA-backed docs plus PE/Capstone used.

## Recommended Support-Doc Changes

### `by-file/SayInputPanes.md`

- Update the [UID:0001LY] row to say it is a non-emitting split/index over exact target-message pane methods and no-route helper clones.
- Add that exact children/class pages remain source-routed to `NexusTK/social/SayInputPanes.cpp`.
- Update the `SayToPlanMessageInputPane` row to say the best source-facing semantic direction is `SayToClanMessageInputPane`, because mode 4 uses `!` and `Clan => `; keep the current UID/path label until supervisor authorizes a rename.
- Add the three no-route helper clones: `0x005b1820-0x005b1983`, `0x005b1d50-0x005b1eb3`, and `0x005b2160-0x005b22c3`.

### `by-class/SayToUserMessageInputPane.md`

- Incorporate B013's accepted direction if not already applied: `87/90`, declaration-level C++, corrected constructor endpoint `0x005b1570-0x005b1631`, field `m_recipientName[128]` at `+0x108`, direct constructor route `0x0059edf7`, inline legacy construction branch in `SayToUserNameInputPane`, submit vtable slot `0x0062f744`, and opcode `0x19` target-message packet shape.
- Add cross-reference that sibling no-route helper `0x005b1820-0x005b1983` is not part of this class.

### `by-class/NewSayToUserMessageInputPane.md`

- Incorporate B014's accepted direction if not already applied: `87/90`, declaration-level C++, constructor `NewSayToUserMessageInputPane(const wchar_t *recipientName)`, `OnSubmitInput()`, `OnKeyInput(const InputEvent *)`, field `m_recipientName[128]` at `+0x108`, five constructor routes, vtable slots `0x0062f7d0` and `0x0062f7e0`, and `g_useEpfAssets` modern-vs-legacy direct-message role.
- Add cross-reference that sibling no-route helper `0x005b1d50-0x005b1eb3` is not part of this class.

### `by-class/SayToGroupMessageInputPane.md`

- Keep owner/emitter [UID:0000N9].
- Add source-facing declaration direction:

```cpp
class SayToGroupMessageInputPane : public LineInputPane
{
public:
    explicit SayToGroupMessageInputPane(const wchar_t *groupName);
    virtual ~SayToGroupMessageInputPane();

protected:
    virtual void OnSubmitInput();

private:
    wchar_t m_groupName[128];

    [[CHILDREN]]
};
```

- Document method-name direction: `SendGroupMessage` is an existing role label; `OnSubmitInput()` is the vtable/source callback role.
- Keep [UID:0000JS] `Group` as a feature cross-reference, not direct source owner.

### `by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md`

- Keep metadata `86/89` or raise only after a dedicated implementation pass; current evidence is already strong.
- Add B001's aggregate context: the preceding no-route helper is `0x005b1d50-0x005b1eb3` followed by `0x005b1eb3-0x005b1ec0` padding, and the following no-route helper is `0x005b2160-0x005b22c3` after `0x005b2152-0x005b2160` padding.
- Add that `this+0x108` is source-facing `m_groupName[128]`.
- Add method-name caveat: `SendGroupMessage` existing doc label, source callback role `OnSubmitInput()`.

### `by-class/SayToPlanMessageInputPane.md`

- Keep current UID/path unless supervisor explicitly authorizes rename.
- Update prose to say: best source-facing semantic direction is `SayToClanMessageInputPane`; `SayToPlanMessageInputPane` is a historical generated/documentation label.
- Replace "final naming remains open" with a ranked conclusion: `SayToClanMessageInputPane` highest probability; neutral `SayTargetMessageInputPane` lower; `SayToPlanMessageInputPane` retained only for filename/UID continuity.
- Add declaration-level C++ readiness under that caveat:

```cpp
class SayToClanMessageInputPane : public LineInputPane
{
public:
    explicit SayToClanMessageInputPane(const wchar_t *clanName);
    virtual ~SayToClanMessageInputPane();

protected:
    virtual void OnSubmitInput();

private:
    wchar_t m_clanName[128];

    [[CHILDREN]]
};
```

### Prompt/string support pages

- `by-memory/0x006309d0-0x006309dc.SayModeGroupClanPrefixFragments.md`: update any stale "plan/clan unresolved" language to say `!` is the clan branch prefix with high confidence, while current `SayToPlan...` name is a documentation continuity label.
- `by-memory/0x00630a44-0x00630a6c.GroupClanPromptFragments.md`: same update for `Clan => `.
- `by-memory/0x00630a18-0x00630a44.DirectWhisperPromptFragments.md`: add cross-reference to corrected legacy constructor endpoint if implementation touches the legacy class docs.

### Suggested new exact child pages

Create these only in a supervisor implementation callback that allows new by-memory files:

| Proposed page | Range | Initial classification |
| --- | --- | --- |
| `by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md` | legacy constructor, padding, submit | reconstructable class-method cluster under [UID:0000C6]; first-draft method C++ ready. |
| `by-memory/0x005b1820-0x005b1983.SayTargetMessagePacketHelperNoRouteA.md` | first no-route helper clone | no-owner or [UID:0000N9] retained-static-helper candidate; no formal C++ until route policy accepted. |
| `by-memory/0x005b1990-0x005b1d42.NewSayToUserMessageInputPaneMethods.md` | modern constructor, padding, submit, padding, key handler | reconstructable class-method cluster under [UID:000099]; first-draft method C++ ready. |
| `by-memory/0x005b1d50-0x005b1eb3.SayTargetMessagePacketHelperNoRouteB.md` | second no-route helper clone | same policy as `0x005b1820`. |
| `by-memory/0x005b2160-0x005b22c3.SayTargetMessagePacketHelperNoRouteC.md` | third no-route helper clone | same policy as `0x005b1820`. |
| `by-memory/0x005b22d0-0x005b2562.SayToClanMessageInputPaneMethods.md` | clan/plan constructor, padding, submit | reconstructable class-method cluster under current [UID:0000C5], with source-facing `SayToClan...` alias. |

## Score And Metadata Recommendation

| Page | Recommendation | Reason |
| --- | --- | --- |
| [UID:0001LY] target aggregate | `88/91`, `RECONSTRUCTABLE:FALSE`, owner/emitter blank | All open span classifications are solved, packet/helper names are resolved to best source-quality direction, and aggregate C++ is proven inappropriate. |
| [UID:0000N9] `SayInputPanes` | no required score change, but update content | Parent/source route remains good for exact children. |
| [UID:0000C6] legacy class | apply B013 if accepted: `87/90`, declaration C++ | Legacy class C++ is ready at class shell level; method bodies need exact child. |
| [UID:000099] modern class | apply B014 if accepted: `87/90`, declaration C++ | Modern class C++ is ready at class shell level; method bodies need exact child. |
| [UID:0000C4] group class | consider `87/90` after method-name/source-shell update | Group class has enough evidence for declaration shell, but no dedicated accepted B report in this pass. |
| [UID:0000C5] plan/clan class | keep current score or raise only with naming implementation | Behavior is strong; source-facing rename should be supervisor-controlled. |

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` during implementation. If this report is accepted and [UID:0001LY] is updated, replace the existing row:

```markdown
    - [UID:0001LY][0x005b1570-0x005b2562.SayTargetMessageInputPanes](by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md) 0x005b1570-0x005b2562 | split/index | SayTargetMessageInputPanes : ignored/non-emitting : 88% : very-strong : B001 2026-06-19 source-quality reanalysis reclassifies the aggregate as a non-emitting split/index for the opcode `0x19` target-message input family; PE/Capstone confirms exact legacy, modern, group, and clan/plan constructor/submit/key ranges, corrects legacy constructor end to `0x005b1631`, resolves the former internal gaps as three no-route standalone `SendTargetMessagePacket(const wchar_t *, const wchar_t *)` helper clones at `0x005b1820-0x005b1983`, `0x005b1d50-0x005b1eb3`, and `0x005b2160-0x005b22c3`, records exact `0xcc` padding around every child body, resolves `+0x108` target-name buffers and opcode fields, rejects aggregate C++/emitter ownership, and keeps exact source-bearing children under `SayInputPanes.cpp` with `SayToClanMessageInputPane` as the best source-facing direction for the current `SayToPlan...` branch.
```

If the supervisor also syncs the existing [UID:0001LZ] group child row, replace its row with:

```markdown
    - [UID:0001LZ][0x005b1ec0-0x005b2152.SayToGroupMessageInputPane](by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md) 0x005b1ec0-0x005b2152 | class-method-cluster | SayToGroupMessageInputPane : reconstructable : 86% : very-strong : Group-message line input constructor and submit method under `SayInputPanes.cpp`; IDA-backed docs and B001 2026-06-19 aggregate reanalysis confirm constructor `0x005b1ec0-0x005b1f7e`, two-byte padding `0x005b1f7e-0x005b1f80`, submit `0x005b1f80-0x005b2152`, vtable slot `0x0062f85c`, `m_groupName[128]` at `+0x108`, `Group => ` prompt, opcode `0x19` group/message packet layout, `g_packetSender`/PacketBuffer/TextFilter/PasswordGuard dependencies, and neighboring no-route helper clones outside this class page.
```

No exact row can be provided yet for proposed new child pages because the validator will assign UIDs during new-file creation. Once assigned, place the new child rows under the [UID:0001LY] aggregate row in address order and keep the aggregate row as `ignored/non-emitting`.

## Validator Needs

No validators were run because this is report-only and no by-* docs were edited.

Recommended validation commands after accepted implementation:

> Executable block R001 was removed from this report and preserved verbatim in [0001LY-SayTargetMessageInputPanes-source-quality-removed.md](0001LY-SayTargetMessageInputPanes-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected results:

- Scoped validators should report `ok: 1`.
- `auto-generated/NexusTK/social/SayInputPanes.cpp` should remove the [UID:0001LY] empty emitter marker after `RECONSTRUCTABLE:FALSE`/blank emitter metadata, while preserving exact class/child markers that remain reconstructable.
- Project-level/autogen coverage may refresh as validator-owned side effects; do not manually edit generated reports.

## IDA Rename / Type / Comment Recommendations

Do not apply during this report pass.

| Item | Recommendation | Confidence |
| --- | --- | --- |
| `0x005b1570` | Rename/type as `SayToUserMessageInputPane::SayToUserMessageInputPane(const wchar_t *recipientName)`; correct end to `0x005b1631`. | high |
| `0x005b1640` | Rename/type as `SayToUserMessageInputPane::OnSubmitInput()`; keep `OnSubmit` as accepted alias if needed. | high for role, medium-high for exact original spelling |
| `0x005b1820` | Comment as no-route `static SendTargetMessagePacket(const wchar_t *targetName, const wchar_t *messageText)` helper clone; not class-owned. | medium |
| `0x005b1990` | Rename/type as `NewSayToUserMessageInputPane::NewSayToUserMessageInputPane(const wchar_t *recipientName)`. | high |
| `0x005b1a60` | Rename/type as `NewSayToUserMessageInputPane::OnSubmitInput()`. | high |
| `0x005b1c40` | Rename/type as `NewSayToUserMessageInputPane::OnKeyInput(const InputEvent *event)` or local `HandleKeyInput` alias. | high for role, medium-high for exact spelling |
| `0x005b1d50` | Comment as second no-route `SendTargetMessagePacket` helper clone; not modern class-owned. | medium |
| `0x005b1ec0` | Rename/type as `SayToGroupMessageInputPane::SayToGroupMessageInputPane(const wchar_t *groupName)`. | high |
| `0x005b1f80` | Rename/type as `SayToGroupMessageInputPane::OnSubmitInput()` / `SendGroupMessage`. | high for role, medium-high for exact spelling |
| `0x005b2160` | Comment as third no-route `SendTargetMessagePacket` helper clone; not group class-owned. | medium |
| `0x005b22d0` | Rename/type as current-doc `SayToPlanMessageInputPane::SayToPlanMessageInputPane(const wchar_t *targetName)` with source-facing comment `best semantic alias: SayToClanMessageInputPane`. | high for body, medium-high for final class name |
| `0x005b2390` | Rename/type as current-doc `SayToPlanMessageInputPane::OnSubmitInput()` with source-facing clan alias. | high for role, medium-high for final class name |
| `0x005b7820` | Generated adjustor thunk, receiver adjustment `-0xa0`, jumps to `0x005b7af0`; no source body. | high |
| `0x005b782b` | Generated adjustor thunk, receiver adjustment `-0xa4`, jumps to `0x005b7af0`; no source body. | high |
| `0x005b7af0` | Shared scalar deleting destructor for target-message panes; generated/no-code support. | high |
| `this+0x108` in legacy/modern | `m_recipientName[128]`. | high |
| `this+0x108` in group | `m_groupName[128]`. | high |
| `this+0x108` in plan/clan | `m_clanName[128]` / `m_targetName[128]`, prefer `m_clanName` after naming decision. | medium-high |
| `0x00630a20` | `L"-> %s: "` legacy direct-message prompt. | high |
| `0x00630a30` | `L"To %s : "` modern direct-message prompt. | high |
| `0x00630a44` | `L"Group => "` group-message prompt. | high |
| `0x00630a58` | `L"Clan => "` clan-message prompt. | high |
| `0x006309d0` | `L"!!"` group target prefix. | high |
| `0x006309d8` | `L"!"` clan target prefix. | high |
| `0x0067a7ec` | `g_packetSender` / `Socket *`; reject generated `CashShopRequest *` aliases. | high |
| `0x0067adc8` | `g_pTextFilter`. | high |
| `0x0066da97` | `g_useEpfAssets`; local direct-message effect is modern versus legacy branch. | high |

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0001LY-SayTargetMessageInputPanes-source-quality.md`
- Modified: none
- Target/support by-* docs: not edited
- `by-memory/-coverage-report.md`: not edited

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001LY-SayTargetMessageInputPanes-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"0001LY"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001LY-SayTargetMessageInputPanes-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001LY-SayTargetMessageInputPanes-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001LY"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
