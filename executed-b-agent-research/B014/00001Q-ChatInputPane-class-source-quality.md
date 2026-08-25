** TARGET-REPORT-UID:00001Q **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00001Q ChatInputPane Class Source-Quality Reanalysis

Agent: B014  
Assignment: correction resume for [UID:00001Q] `by-class/ChatInputPane.md`  
Target: `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\ChatInputPane.md`  
Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B014\research\00001Q-ChatInputPane-class-source-quality.md`  
Date: 2026-06-19  
Mode: report-only. No by-* documentation file and no `by-memory/-coverage-report.md` edit is recommended or performed by this pass.

## Executive Recommendation

`ChatInputPane` is source-reconstructable as a class owned by [UID:0000I5] `Chatting`, with source emission routed through `auto-generated/NexusTK/social/Chatting.cpp` unless the broader Chatting unit is later split into `social/ChatInputPane.cpp`. The class page can now carry source-quality class declarations and a `[[CHILDREN]]` route. The raw constructor child is ready for first-draft C++ immediately. The `0x005b3940-0x005b3bba` method cluster is behaviorally source-ready, but the higher-quality implementation path is to split it into exact child methods before adding method-body C++:

- `0x005b3940-0x005b3a40` - `ChatInputPane::HandleSpecialInput` or `ChatInputPane::HandleHistoryKey`.
- `0x005b3a40-0x005b3bba` - `ChatInputPane::SendChatMessage` or `ChatInputPane::SubmitChatMessage`.

The adjacent [UID:0002S8] raw packet island remains non-emitting/no-owner. It is a useful protocol comparison but not a `ChatInputPane` method, not a `SayInputPane` child, and not a Socket/PacketBuffer helper until a caller, pointer table, or runtime route appears.

Recommended target metadata after accepted implementation:

- `by-class/ChatInputPane.md` [UID:00001Q]: keep `RECONSTRUCTABLE:TRUE`, keep `CANONICAL_OWNER:0000I5`, keep `EMITTER_UIDS:0000I5`, raise from `85/86` to `87/90`.
- `by-memory/0x005b38e0-0x005b3935.ChatInputPaneRawConstructor.md` [UID:0002S9]: keep owner/emitter `00001Q`, raise from current support-row `74%` to `88/91`, and add constructor first-draft C++.
- `by-memory/0x005b3940-0x005b3bba.ChatInputPane.md` [UID:0001MC]: keep owner/emitter `00001Q`, raise coverage-row score from `78%` to `87/90` only if method children are split or the cluster is explicitly allowed to emit both method bodies. Preferred action is child split before method C++.
- `by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md` [UID:0002S8]: keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++.
- `by-memory/0x00630a14-0x00630a18.ChatInputPaneChevronPromptString.md` [UID:0003JP]: keep owner/emitter `00001Q`; no code body beyond the class constructor reference.
- `by-global/g_pChatInputPane.md` [UID:000308] and storage [UID:000309]: keep Chatting ownership, but document the initializer/source-declaration caveat described below.

## Evidence Checked

Target and support documentation checked:

- `by-class/ChatInputPane.md`
- `by-memory/0x005b3940-0x005b3bba.ChatInputPane.md`
- `by-memory/0x005b38e0-0x005b3935.ChatInputPaneRawConstructor.md`
- `by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md`
- `by-memory/0x00630a14-0x00630a18.ChatInputPaneChevronPromptString.md`
- `by-global/g_pChatInputPane.md`
- `by-memory/0x0069bf68-0x0069bf6c.g_pChatInputPane.md`
- `by-file/Chatting.md`
- `by-project-structure/proposed-source-tree.md`
- `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`
- `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
- `by-global/g_packetSender.md`
- `by-memory/0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md`
- `by-memory/0x004f2300-0x004f2310.LineInputPaneCopyText.md`
- `by-memory/0x004f2310-0x004f2320.LineInputPaneTextLength.md`
- `by-class/LineInputPane.md`
- `by-memory/0x005b34d0-0x005b37ea.SayInputPane.md`
- `by-memory/0x005b4260-0x005b43bc.ShoutInputPane.md`
- `by-class/-coverage-report.md`
- `by-memory/-coverage-report.md` read only for exact current row text.
- `auto-generated/-ag-class-coverage.md` and `auto-generated/-ag-memory-coverage.md` read only to confirm current emitter/no-code state.

Binary/decompiler evidence checked:

- Local PE: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- Sections used for VA/raw mapping:
  - `.text` VA `0x00401000`, virtual size `0x20b4ac`, raw `0x400/0x20b600`
  - `.rdata` VA `0x0060d000`, virtual size `0x5f0be`, raw `0x20ba00/0x5f200`
  - `.data` VA `0x0066d000`, virtual size `0x2fe24`, raw `0x26ac00/0xd800`
  - `.rsrc` VA `0x0069d000`, virtual size `0x15c38`, raw `0x278400/0x15e00`
- Cached decompiler/IDA exports for `0x005b3940`, `0x005b3a40`, `0x005b38e0`, `0x005b77de`, `0x005b77e9`, and `0x005b7980`.
- Capstone disassembly over the exact raw ranges and destructor thunks.
- PE abs32 and rel32 reference scans for starts, prompt literal, singleton storage, and vtable addresses.

Current generated state checked:

- `auto-generated/NexusTK/social/Chatting.cpp` currently contains empty emitter markers for `00001Q`, `0002S9`, `0001MC`, `0003JP`, and the `g_pChatInputPane` support nodes.
- The generated class/memory coverage rows show these nodes route to `auto-generated/NexusTK/social/Chatting.cpp` but have no emitted code.
- Any generated staging source encountered was treated only as a non-authoritative warning about synthetic names and stale helper guesses. It was not used as naming authority.

## Exact Range And Boundary Recheck

Confirmed local byte ranges:

- `0x005b37ea-0x005b37f0`: six bytes of `0xcc` padding between `SayInputPane` and the no-route raw packet island.
- `0x005b37f0-0x005b38d5`: `0xe5` bytes of source-shaped raw packet sender body. No `0xcc` padding inside this body.
- `0x005b38d5-0x005b38e0`: eleven bytes of `0xcc` padding between the no-route raw island and the raw `ChatInputPane` constructor.
- `0x005b38e0-0x005b3935`: exact `0x55` byte raw constructor body. First bytes are `55 8b ec 51 56 8b f1 68 14 0a 63 00`; final body bytes store vtables and return at `0x005b3934`.
- `0x005b3935-0x005b3940`: eleven bytes of `0xcc` padding between the constructor and the history key handler.
- `0x005b3940-0x005b3a40`: exact history/special-input handler body.
- `0x005b3a40-0x005b3bba`: exact submit/send-chat handler body.
- `0x005b3bba-0x005b3bc0`: six bytes of `0xcc` padding after the submit handler.

Boundary conclusion:

- [UID:0002S8] must not be merged into `ChatInputPane`; it has separate leading/trailing padding and no route to `ChatInputPane`.
- [UID:0002S9] should use exact source range `0x005b38e0-0x005b3935`. The current supervisor support row says `0x005b38e0-0x005b3940`, which includes padding and should be corrected if accepted.
- [UID:0001MC] is a two-method cluster, not a single function. The clean source split is two child pages at `0x005b3940-0x005b3a40` and `0x005b3a40-0x005b3bba`, plus the existing padding rows.

## Heuristic / Inference Reanalysis And Validation

### Class Ownership And Source Placement

Best-supported owner: [UID:0000I5] `Chatting`.

Evidence:

- `ChatInputPane` creates and sends chat protocol packets, uses chat history helpers, and is documented as attached to `Chatting`.
- `by-file/Chatting.md` and `by-project-structure/proposed-source-tree.md` already place `ChatInputPane` under `social/Chatting.cpp`, with a possible future split into `social/ChatInputPane.cpp`.
- `auto-generated/-ag-class-coverage.md` currently routes [UID:00001Q] to `auto-generated/NexusTK/social/Chatting.cpp`.
- The prompt literal [UID:0003JP], singleton [UID:000308]/[UID:000309], raw constructor [UID:0002S9], and method cluster [UID:0001MC] all route to or through `ChatInputPane`, which itself routes to `Chatting`.

Rejected alternatives:

- `InputPanes.cpp`: rejected because the behavior is chat-specific, not generic input control behavior.
- `CommandInputPanes.cpp`: rejected because there is no command-specific parser or command-prefix handling in the target.
- `SayInputPanes.cpp`: rejected because `SayInputPane` is a neighboring and related packet workflow, but `ChatInputPane` has a separate prompt, singleton, vtables, history cursor, and open routes.
- `UserPane.cpp`: rejected as primary owner. UserPane has inline open/allocation branches, but those are callers/factory sites, not the semantic owner of the chat input class.
- `Socket.cpp`/`PacketBuffer.cpp`: rejected as owners. PacketBuffer and socket helpers are callees; the method is a chat submit action.

Final placement recommendation:

- Keep `CANONICAL_OWNER:0000I5` and `EMITTER_UIDS:0000I5` on [UID:00001Q].
- Keep child ownership of [UID:0002S9], [UID:0001MC], and [UID:0003JP] under [UID:00001Q].
- If the source tree is later split, `social/ChatInputPane.cpp` is the only supported split target. The split should still be listed under the Chatting/social subsystem.

### Raw Constructor Relationship

Best-supported source-facing signature:

```cpp
ChatInputPane::ChatInputPane();
```

Best-supported body role:

- Constructs the `MultiLineInputPane` base with prompt `L">"`.
- Publishes `this` to `g_pChatInputPane`.
- Initializes the full-object history cursor at `+0x108` to `-1`.
- Installs primary and adjusted secondary/tertiary vtables.

Evidence:

- Raw constructor bytes at `0x005b38e0-0x005b3935` push `0x00630a14`, call `0x004f2c90`, write `0x0069bf68`, write word `-1` at `this+0x108`, and store vtables at `this`, `this+0xa0`, and `this+0xa4`.
- Prompt literal [UID:0003JP] at `0x00630a14` is UTF-16 `">"` and has refs from the raw constructor, UserPane inline open branch, and open helper.
- Equivalent construction appears in the open helper at `0x005a95e0`: allocation size `0x10c`, same prompt, same singleton publish, same vtable stores, same `+0x108` sentinel.
- Abs32 scan finds no direct pointer to the raw constructor start, supporting the existing "raw constructor with no IDA function/xref" classification.

Inference closure:

- The constructor is source-authored but not represented as a normal IDA function because construction is also inlined/duplicated by allocation/open paths. This is not evidence for "compiler-only" code; the body is source-shaped and has a normal prologue/epilogue.
- The field at full object `+0x108` should be named `m_historyCursor`, `m_chatHistoryIndex`, or `m_historySelection`. `m_historyCursor` is the best concise source-facing name because the history helpers update it as a cursor while navigating previous/next messages.
- Type should be `short`/`int16_t`; the constructor uses `mov word ptr` to store `-1`, and the handler passes the address of the same field to history helpers.

### Adjusted-This Layout And Destructor Thunks

Resolved layout issue:

- The apparent mismatch between constructor field `this+0x108` and history-handler field `this+0x68` is explained by adjusted secondary-subobject dispatch.

Evidence:

- Constructor installs vtable `0x0062fc38` at full object `this+0xa0`.
- The history handler `0x005b3940` is referenced from vtable slot `0x0062fc40`, inside the secondary vtable region.
- When called through that secondary vtable, the method's incoming `this` is the adjusted subobject pointer at full object `+0xa0`.
- The handler uses adjusted `this+0x68`, which resolves to full object `+0x108`.
- The handler also uses adjusted `this+0x5c`, which resolves to full object `+0xfc`, matching the inherited line/edit child pointer region documented for `LineInputPane`.
- Destructor adjustor thunk `0x005b77de` jumps to scalar destructor `0x005b7980` after subtracting `0xa0`.
- Destructor adjustor thunk `0x005b77e9` jumps to scalar destructor `0x005b7980` after subtracting `0xa4`.

Final field recommendations:

- Full object `+0x108`: `short m_historyCursor`.
- Full object `+0xfc`, accessed as adjusted `this+0x5c`: inherited edit child pointer. Use the established base/source name if later confirmed; otherwise `m_editPane` or `m_textEdit` is the best descriptive field name.
- Do not document `+0x68` as a separate full-object field in `ChatInputPane`; it is an adjusted-this view of `+0x108`.

### Prompt Literal

Best-supported source-facing name:

```cpp
static const wchar_t kChatInputPrompt[] = L">";
```

Evidence:

- [UID:0003JP] bytes at `0x00630a14-0x00630a18` are UTF-16 `">"`.
- Abs32 refs hit the UserPane inline open branch, the open helper, and the raw constructor.
- The literal differs from `SayInputPane`'s `"> "` prompt and should not be merged with Say/Shout prompt constants.

Recommendation:

- Keep prompt literal child under `ChatInputPane`.
- In first-draft C++, an inline `L">"` in the constructor is acceptable. If style favors named constants, use `kChatInputPrompt`.

### History Key Handler

Best-supported source-facing signature:

```cpp
char ChatInputPane::HandleSpecialInput(PaneKeyEvent *event);
```

Alternate acceptable source name:

```cpp
char ChatInputPane::HandleHistoryKey(PaneKeyEvent *event);
```

Evidence:

- Vtable ref `0x0062fc40 -> 0x005b3940` identifies this as a virtual secondary input handler.
- Handler calls base helper `0x004f2cd0` when the event is not the two handled history keys.
- It narrows key data through the `std::ctype<char>::do_narrow` pattern and checks:
  - `event+0x10a == 0`
  - `event+0x04 == 8`
  - narrowed key equals `0x81` or `0x83`
- For `0x81`, it calls `0x005a4930`.
- For `0x83`, it calls `0x005a4990`.
- It passes the user/chat history owner global and the adjusted `this+0x68` address, which resolves to full object `m_historyCursor`.
- When a returned buffer starts nonzero, it selects all current text, inserts the history string using `0x0058fc30`, and selects all again.
- It returns `1` only when a history navigation key was handled.

Best-supported helper names:

- `0x004f2cd0`: `MultiLineInputPane::HandleSpecialInput` or `LineInputPane::HandleSpecialInput`, depending on final base class naming.
- `0x005a4930`: `GetPreviousChatHistory` / `UserPane::GetPreviousChatHistory`.
- `0x005a4990`: `GetNextChatHistory` / `UserPane::GetNextChatHistory`.
- `0x0058f2a0`: edit child `SelectRange`.
- `0x0058fc30`: edit child `ReplaceSelection` or `InsertText`.

Best-supported event field names:

- `event+0x04`: event type or virtual-key message kind. The value `8` is required before history handling.
- `event+0x08`: key/character code input to the ctype narrowing path.
- `event+0x10a`: modifier/repeat/IME state byte that must be zero for history handling.

No-safe-inference boundary:

- The exact source type name for `PaneKeyEvent` is not proven by this target alone. `PaneKeyEvent`, `InputKeyEvent`, or the local project event type should be synchronized with the input subsystem. This is not a blocker for method behavior, but the class declaration should use the established project event struct name if one exists.

### Submit / Send Chat Method

Best-supported source-facing signature:

```cpp
short ChatInputPane::SendChatMessage();
```

Alternate acceptable source names:

- `SubmitChatMessage`
- `OnSubmit`
- `SendInputText`

`SendChatMessage` is preferred because the method builds opcode `0x0e`, subtype `0`, sends through `g_packetSender`, and then saves chat history.

Evidence:

- Vtable ref `0x0062fc30 -> 0x005b3a40`.
- The method calls `0x004f2310` first. Existing docs identify this as `LineInputPaneTextLength`.
- If text length is `<= 0`, it returns immediately.
- It reads `dword_67A748` and checks byte `+0x134102`; if nonzero, it skips packet send/history save and returns the existing length.
- It calls `0x004f2300` with max count `0xff` to copy up to 255 wide chars from the input.
- If copied text starts empty, it returns without send.
- It calls password guard `0x00465890`.
- It calls sanitizer/filter helper `0x005957c0` with global context `dword_67ADC8` and `wcslen(text)`.
- It calls packet scratch/init helper `0x00516030`.
- It writes opcode `0x0e`.
- It writes subtype/action `0`.
- It converts the wide text to MBCS via `WideCharToMultiByte` IAT call.
- It writes a one-byte payload length at packet offset `+2`.
- It copies payload bytes to packet offset `+3`.
- It sends packet through `0x00574bb0(g_packetSender, packet, payloadLength + 3)`.
- It saves submitted text to chat history through `0x005a49e0(dword_67A748, wideText)`.

Best-supported helper/global names:

- `0x004f2310`: `LineInputPane::GetTextLength`.
- `0x004f2300`: `LineInputPane::CopyText`.
- `dword_67A748`: local user/user pane/chat history owner. Existing source names should decide between `g_pUserPane`, `g_pLocalPlayer`, or a broader client-state singleton. In this target, it is the owner for history helpers and the `+0x134102` send-gate byte.
- `dword_67A748 + 0x134102`: `m_chatSubmitBlocked`, `m_inputSendBlocked`, or `m_isChatMutedOrLocked`. Best neutral name: `m_inputSendBlocked`, because the method does not prove why sending is blocked.
- `0x00465890`: `ValidateChatInputOrThrowPasswordError` remains supported by the existing doc and caller route.
- `0x005957c0`: best descriptive source name `NormalizeChatText` or `ApplyOutboundChatFilter`. It is not safe to assign a specific class owner from this target alone.
- `dword_67ADC8`: text filter/normalization context. Use an existing global name if available; otherwise document as `g_chatTextFilter` only as an inference.
- `0x00516030`: packet builder/scratch initialization helper. Best placeholder `BeginPacketBuild` or `InitPacketBuffer`.
- `0x00575380`: `PacketBufferWriteUInt8`.
- `0x005753a0`: currently documented in PacketBuffer scalar helper page as the scalar big-endian write helper used for the zero subtype/action field.
- `0x00516220`: packet byte-copy helper. Best placeholder `PacketBufferCopyBytes`.
- `dword_67A7EC`: [UID:0000Q5] `g_packetSender`, best type `Socket *`.
- `0x00574bb0`: [UID:0001HU] `QueueAndSendPacket`.
- `0x005a49e0`: `SaveChatHistory` / `UserPane::SaveChatHistory`.

Protocol naming recommendation:

- Packet family: `Chat`.
- Opcode: `0x0e`.
- Subtype/action for ChatInputPane: `0`.
- Source-facing enum names if protocol constants are introduced:
  - `kPacketChat = 0x0e`
  - `kChatSubtypeNormal = 0`
  - or `ChatPacketType::Normal = 0`
- Do not name subtype `Say` here. `SayInputPane` also uses opcode `0x0e` subtype `0`, but `ChatInputPane` is a separate UI route and its prompt/history/singleton differ. If the protocol-level meaning is "normal/default chat", use `Normal` or `Default`, not a UI class name.

### Singleton / Global Handling

Best-supported source-facing declaration:

```cpp
extern ChatInputPane *g_pChatInputPane;
```

Evidence:

- Storage [UID:000309] at `0x0069bf68`.
- Abs32 refs hit open checks, alternate allocation/publish paths, the raw constructor write, and destructor clear:
  - `0x005a5d10`, `0x005a5d54`, `0x005a5d5c`
  - `0x005a9606`, `0x005a9647`, `0x005a964f`
  - `0x005b390a`
  - `0x005b7988`
- Raw constructor writes this pointer to `0x0069bf68`.
- Scalar destructor `0x005b7980` writes zero to `0x0069bf68`.
- UserPane/open helpers check the singleton before opening/allocating.

Initializer caveat:

- Existing docs say static image value is `0xffffffff`.
- The local raw PE section mapping did not physically map `0x0069bf68` as initialized bytes in the expected raw area; this looks like virtual/BSS tail behavior from the PE mapping rather than a normal source initializer proof.
- The open path checks for null before allocation/open. A permanent source initializer of `reinterpret_cast<ChatInputPane *>(-1)` would be incompatible with that route unless another startup initializer resets it.

Recommendation:

- The class page should only use `extern ChatInputPane *g_pChatInputPane;`.
- The global page should resolve whether the source declaration was zero-initialized, uninitialized BSS, or deliberately sentinel-initialized during startup. Until that is resolved, do not emit an initializer from the class page.

### UserPane Open Branch

Best-supported role:

- `0x005a5d37` is an inline open/allocation branch that constructs or opens `ChatInputPane` from a UserPane key/action flow.
- `0x005a95e0` is an equivalent open helper that constructs the pane if the singleton is absent.

Evidence:

- Both paths reference prompt literal `0x00630a14`.
- Both paths publish `g_pChatInputPane`.
- Both paths install the same vtables as the raw constructor.
- Both paths initialize the history cursor sentinel.
- Both paths allocate or operate on an object of size `0x10c`.

Conclusion:

- UserPane is a caller/factory context, not the semantic owner of `ChatInputPane`.
- The open branch should be documented in UserPane support docs and in `ChatInputPane` caller evidence, but source placement should remain Chatting/social.

### Adjacent No-Route Packet Island

Best-supported classification:

- Keep [UID:0002S8] `ignored/non-emitting`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`.

Evidence:

- Exact body at `0x005b37f0-0x005b38d5` is separated from `SayInputPane` and `ChatInputPaneRawConstructor` by `0xcc` padding.
- No IDA function start at the raw address.
- No inbound xrefs, no VA/RVA pointer hits, and no rel32 call/jump hits to the body or interior were documented by prior B001 and reconfirmed by the local scan for the start.
- The body builds a default chat packet using opcode `0x0e`, subtype `0`, one wide-string argument, MBCS conversion, length-prefixing, `g_packetSender`, and `QueueAndSendPacket`.
- The packet shape resembles `ChatInputPane` and `SayInputPane`, but similarity is not a route.

Rejected source-owner alternatives:

- `ChatInputPane`: rejected because no caller or vtable/pointer route links the raw island to the class.
- `SayInputPane`: rejected because there is padding and no call route after the SayInputPane submit method.
- `ShoutInputPane`: rejected because subtype differs and no route exists.
- `Socket`/`PacketBuffer`: rejected because the body is a UI/protocol wrapper over packet helpers, not a generic helper.

Recommendation:

- Do not emit first-draft C++ for [UID:0002S8].
- Keep it as support evidence for opcode `0x0e` subtype `0` default chat packet layout.

### Destructor Thunks

Best-supported names:

- `ChatInputPane::~ChatInputPane()`
- scalar deleting destructor wrapper/thunk entries as compiler-generated adjustors.

Evidence:

- Vtable slot `0x0062fbe8 -> 0x005b7980` primary scalar destructor.
- Secondary thunk `0x005b77de` adjusts by `-0xa0` and jumps to `0x005b7980`.
- Tertiary thunk `0x005b77e9` adjusts by `-0xa4` and jumps to `0x005b7980`.
- Scalar destructor clears `g_pChatInputPane` and calls base destructor `0x004f2010`; conditional delete follows the usual scalar deleting destructor flag path.

Implementation recommendation:

- Class declaration should include `virtual ~ChatInputPane();`.
- Do not hand-author C++ for adjustor thunks. They are compiler-generated from inheritance/vtable layout.
- If the destructor body is emitted by a child or class-level implementation, the source body should clear the singleton and rely on C++ inheritance to generate thunks.

## Rejected Alternatives And No-Safe-Inference Proofs

Rejected: [UID:0002S8] is `ChatInputPane::SendChatMessage` or an overload.

- Checked exact range, padding, IDA function presence, xrefs, pointer hits, and rel32 route.
- No route exists from a vtable, call site, switch table, import, or constructor/open path.
- The body has source-like packet construction, but address adjacency and packet similarity are insufficient.

Rejected: `this+0x68` is a distinct full-object field.

- Constructor initializes full object `+0x108`.
- Secondary vtable dispatch adjusts `this` by `+0xa0`.
- Handler adjusted `this+0x68` equals full object `+0x108`.
- Destructor thunks independently prove `+0xa0` and `+0xa4` adjusted subobjects.

Rejected: the prompt literal belongs to `UserPane`.

- UserPane refs are caller/open refs.
- Constructor and open helper both consume the same prompt as part of `ChatInputPane` construction.
- The literal is class-specific and differs from nearby Say/Shout prompts.

Rejected: the submit method belongs to PacketBuffer or Socket.

- PacketBuffer/Socket helpers are callees only.
- The method reads UI text, checks UI/client state, validates and filters chat text, writes chat protocol fields, sends via Socket, and saves chat history.

No-safe-inference remaining items:

- Exact event struct type name cannot be proven from this target alone. Use the established input-event type from the input subsystem when implementing.
- Exact source owner/name for `dword_67A748` is broader than this class. It behaves as the user/chat state owner for history and send gating here.
- Exact semantic meaning of `dword_67A748 + 0x134102` cannot be proven beyond "nonzero blocks submit-send after positive text length." Use `m_inputSendBlocked` or an existing project name; do not over-name it as mute/dead/locked without corroborating callers.
- Exact source name for `0x005957c0` cannot be proven beyond outbound chat text normalization/filtering in this target. `NormalizeChatText` is the best local descriptive name; synchronize with the helper page if one exists.
- Exact global initializer for `g_pChatInputPane` must be resolved in the global/storage docs. Class C++ should not encode a sentinel initializer.

These remaining items are bounded and do not block class/constructor C++. They do affect the final exact typedefs/helper names in method bodies, which is another reason to split [UID:0001MC] before body emission.

## First-Draft C++ Recommendation

### Class-Level C++ Is Eligible

[UID:00001Q] is eligible for a nonblank class declaration and child route. The declaration should not invent full private layout beyond fields proven here and inherited-base placeholders already accepted by surrounding input-pane docs.

Recommended class skeleton:

```cpp
class ChatInputPane : public MultiLineInputPane
{
public:
    ChatInputPane();
    virtual ~ChatInputPane();

    short SendChatMessage();
    char HandleSpecialInput(PaneKeyEvent *event);

private:
    // Full-object offset +0x108. Accessed as adjusted-this +0x68 through the secondary input vtable.
    short m_historyCursor;
};

extern ChatInputPane *g_pChatInputPane;
```

If the local class style uses `protected` virtual overrides instead of public methods, move `SendChatMessage` and `HandleSpecialInput` to the matching access section. Do not include adjustor thunks in source.

### Raw Constructor C++ Is Eligible

Recommended [UID:0002S9] first draft:

```cpp
ChatInputPane::ChatInputPane()
    : MultiLineInputPane(L">")
{
    g_pChatInputPane = this;
    m_historyCursor = -1;
}
```

Notes:

- Vtable stores are compiler output and should not be hand-emitted.
- If `m_historyCursor` is not representable as a direct member because of multiple inheritance layout in the reconstructed headers, keep a documented padding/layout member and still initialize the source field semantically.

### Method Bodies Are Source-Ready But Should Be Split

Preferred implementation callback action:

1. Split [UID:0001MC] into the two exact children listed above.
2. Give each child its own C++ body and evidence.
3. Leave [UID:0001MC] as an aggregate/container or remove it from emitting if the framework supports replacement by children.

If a split is not accepted, [UID:0001MC] can emit both method bodies in one cluster, but that is lower quality because the page covers two source functions.

Source-quality draft for the history handler, with unresolved project type names isolated:

```cpp
char ChatInputPane::HandleSpecialInput(PaneKeyEvent *event)
{
    const signed char key = NarrowPaneKey(event);
    if (event->state != 0 || event->type != 8 ||
        (key != static_cast<signed char>(0x81) && key != static_cast<signed char>(0x83))) {
        return MultiLineInputPane::HandleSpecialInput(event);
    }

    wchar_t text[256];
    if (key == static_cast<signed char>(0x81)) {
        GetPreviousChatHistory(g_pUserPane, &m_historyCursor, text, 256);
    } else {
        GetNextChatHistory(g_pUserPane, &m_historyCursor, text, 256);
    }

    if (text[0] != L'\0') {
        m_editPane->SelectRange(0, 0x7fff);
        m_editPane->ReplaceSelection(text, wcslen(text), 0, 0);
        m_editPane->SelectRange(0, 0x7fff);
    }

    return 1;
}
```

Source-quality draft for submit/send, with helper names that should be synchronized with support docs:

```cpp
short ChatInputPane::SendChatMessage()
{
    short length = GetTextLength();
    if (length <= 0) {
        return length;
    }

    if (g_pUserPane->m_inputSendBlocked) {
        return length;
    }

    wchar_t text[256];
    length = CopyText(text, 255);
    if (text[0] == L'\0') {
        return length;
    }

    ValidateChatInputOrThrowPasswordError(text);
    NormalizeChatText(g_chatTextFilter, text, wcslen(text));

    unsigned char packet[0x12c];
    InitPacketBuffer(packet);
    PacketBufferWriteUInt8(packet, 0x0e);
    PacketBufferWriteChatSubtypeZero(packet);

    char narrow[256];
    const int payloadLength = WideCharToMultiByte(CP_ACP, 0, text, -1, narrow, 255, NULL, NULL);
    PacketBufferWriteUInt8(packet + 2, static_cast<unsigned char>(payloadLength));
    PacketBufferCopyBytes(packet + 3, narrow, payloadLength);

    QueueAndSendPacket(g_packetSender, packet, payloadLength + 3);
    return SaveChatHistory(g_pUserPane, text);
}
```

The draft intentionally uses placeholder project names for `PaneKeyEvent`, `NarrowPaneKey`, `g_pUserPane`, `g_chatTextFilter`, `PacketBufferWriteChatSubtypeZero`, and `m_editPane`; those must be replaced by established project names during implementation. Behavior, packet fields, and call order are supported.

## Target And Support Implementation Checklist

Primary target:

- `by-class/ChatInputPane.md`
  - Replace stale "C++ blank until" blocker text with this resolved evidence.
  - Keep owner/emitter as `0000I5`.
  - Raise to proposed `COMPLETION:87`, `CONFIDENCE:90`.
  - Add class-level C++ declaration and `[[CHILDREN]]` route if accepted.
  - Document adjusted-this layout: full `+0x108` history cursor is seen as secondary `+0x68`.
  - Document destructor thunk/adjustor evidence and that thunks are compiler-generated.
  - Document UserPane open branch as caller/factory, not source owner.

Memory children:

- `by-memory/0x005b38e0-0x005b3935.ChatInputPaneRawConstructor.md`
  - Correct support-row range from `0x005b38e0-0x005b3940` to exact `0x005b38e0-0x005b3935`.
  - Add first-draft constructor C++.
  - Add prompt/singleton/history-cursor/vtable evidence.
  - Raise to proposed `88/91`.
- `by-memory/0x005b3940-0x005b3bba.ChatInputPane.md`
  - Preferred: split into exact method children:
    - `0x005b3940-0x005b3a40.ChatInputPaneHandleSpecialInput.md`
    - `0x005b3a40-0x005b3bba.ChatInputPaneSendChatMessage.md`
  - If split is not performed, document that the page emits two method bodies as a cluster.
  - Add adjusted-this, event-field, history-helper, player-gate, packet protocol, and helper-name evidence.
  - Raise to proposed `87/90` after split or accepted cluster emission.
- `by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md`
  - No code.
  - Keep no-owner/non-emitting.
  - Optionally add cross-reference that B014 00001Q rechecked it and retained B001's no-route conclusion.
- `by-memory/0x00630a14-0x00630a18.ChatInputPaneChevronPromptString.md`
  - Optionally add the three prompt refs and note that `L">"` differs from `SayInputPane`'s prompt.

Globals/support:

- `by-global/g_pChatInputPane.md`
  - Keep Chatting ownership.
  - Document source use as `extern ChatInputPane *g_pChatInputPane`.
  - Resolve initializer ambiguity in the global page, not in class C++.
- `by-memory/0x0069bf68-0x0069bf6c.g_pChatInputPane.md`
  - Keep storage refs and destructor clear evidence.
  - Add PE/BSS initializer caveat if accepted.
- `by-global/g_packetSender.md`
  - No required metadata change; support submit-method naming as `Socket *g_packetSender`.
- `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
  - No required metadata change; cite from submit method.
- `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`
  - Synchronize byte/subtype writer names with `ChatInputPane` and `SayInputPane`.
- `by-memory/0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError.md`
  - No required metadata change; cite as password guard for submit.
- `by-class/LineInputPane.md`, `LineInputPaneTextLength`, and `LineInputPaneCopyText`
  - Ensure inherited `GetTextLength`, `CopyText`, edit child pointer, and base input handler names align.
- `by-file/Chatting.md`
  - Keep `ChatInputPane` under Chatting/social.
  - If a source split is accepted, record `social/ChatInputPane.cpp` as a Chatting-owned split.
- `by-project-structure/proposed-source-tree.md`
  - Keep existing Chatting placement; optionally clarify that ChatInputPane split is only a future organization split, not a semantic owner change.

Coverage/support reports:

- `by-class/-coverage-report.md`
  - Replace the current `00001Q` row with the proposed row below if accepted.
- `by-memory/-coverage-report.md`
  - Do not edit during this report pass.
  - If accepted, correct [UID:0002S9] range/score text and [UID:0001MC] score/detail text using the proposed rows below.
- `auto-generated/-ag-class-coverage.md` and `auto-generated/-ag-memory-coverage.md`
  - Regenerate only through the validator/generator in implementation mode if callback authorizes edits.

## Exact Supervisor-Owned Coverage Row Text

Current exact `by-class/-coverage-report.md` row:

```text
- [UID:00001Q][ChatInputPane](by-class/ChatInputPane.md) : reconstructable : 85% : strong : Chat input pane attached to `Chatting`; exact raw constructor range, singleton/global handling, vtable identity, history navigation, submit packet behavior, destructor/singleton cleanup, and padding split evidence are documented.
```

Proposed replacement `by-class/-coverage-report.md` row:

```text
- [UID:00001Q][ChatInputPane](by-class/ChatInputPane.md) : reconstructable : 87% : very strong : B014 2026-06-19 source-quality reanalysis resolves the stale raw-constructor, prompt, singleton, UserPane inline open branch, secondary-vtable history handler, submit-packet, player-state gate, packet-helper, no-route raw island, destructor-thunk, and Chatting source-placement questions; keep [UID:0002S8] as non-emitting no-route evidence, route the class through [UID:0000I5][Chatting](by-file/Chatting.md), add a class-level declaration/`[[CHILDREN]]` draft when accepted, and split or first-draft the method children before formal method C++ as described in the B014 report.
```

Current exact relevant `by-memory/-coverage-report.md` rows:

```text
    - [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md) 0x005b37f0-0x005b38d5 | no-route raw code island | ChatPacketRawSenderNoRouteRaw : ignored/non-emitting : 85% : strong : Source-shaped default chat packet body retained without a proven source route; B001 2026-06-16 live IDA/raw PE audit confirms exact `0xe5`-byte body, no IDA function, no inbound xrefs, no VA/RVA pointer hits, no rel32 call/jump hits to the body or any interior address, opcode `0x0e` subtype `0`, one-argument UTF-16-to-MBCS length-prefixed payload builder, `g_packetSender`/`QueueAndSendPacket` dependency, and comparison against SayInputPane/ChatInputPane/ShoutInputPane submit handlers; keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters/final C++ unless a caller/pointer/runtime route appears.
    - [UID:0002S9][0x005b38e0-0x005b3935.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3935.ChatInputPaneRawConstructor.md) 0x005b38e0-0x005b3940 | raw constructor | ChatInputPaneRawConstructor : reconstructable : 74% : strong : Raw `ChatInputPane` constructor-shaped bytes with `">"` prompt, base construction, active singleton publish, history sentinel initialization, and primary/secondary/tertiary vtable stores.
    - [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md) 0x005b3940-0x005b3bba | class-method cluster | ChatInputPane : reconstructable : 78% : strong : Chat input history key handler, submit handler, vtable refs, singleton cleanup, packet opcode `0x0e` subtype `0`, player-state gate, and alignment padding documented; C++ blank under the 95+ gate.
```

Recommended `by-memory/-coverage-report.md` handling:

- Keep the [UID:0002S8] row unchanged.
- Replace [UID:0002S9] row, if accepted:

```text
    - [UID:0002S9][0x005b38e0-0x005b3935.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3935.ChatInputPaneRawConstructor.md) 0x005b38e0-0x005b3935 | raw constructor | ChatInputPaneRawConstructor : reconstructable : 88% : very strong : B014 2026-06-19 PE/disassembly/source-quality reanalysis confirms the exact `0x55`-byte constructor body, separate `0x005b3935-0x005b3940` padding, `L">"` prompt literal at `0x00630a14`, `MultiLineInputPane` base construction, `g_pChatInputPane` publish, full-object `+0x108` int16 history-cursor sentinel, primary/secondary/tertiary vtable stores, equivalent UserPane/open-helper construction branches, and first-draft constructor C++ eligibility.
```

- Replace or split [UID:0001MC] row, if accepted without immediate split:

```text
    - [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md) 0x005b3940-0x005b3bba | class-method cluster | ChatInputPane : reconstructable : 87% : very strong : B014 2026-06-19 source-quality reanalysis confirms the secondary-vtable history/special-input handler at `0x005b3940-0x005b3a40` and primary submit/send-chat handler at `0x005b3a40-0x005b3bba`, resolves adjusted-this `+0x68` to full-object `+0x108` history cursor and adjusted-this `+0x5c` to inherited edit child `+0xfc`, identifies event fields, history keys `0x81`/`0x83`, player-state send gate, opcode `0x0e` subtype `0` packet body, PacketBuffer/Socket/history-save helper roles, destructor/singleton cleanup evidence, and recommends splitting into exact method children before formal method-body C++ or otherwise emitting a first-draft cluster.
```

Current exact generated coverage rows:

```text
| [UID:00001Q][ChatInputPane](by-class/ChatInputPane.md) | emits | `0000I5` | `0000I5` |  | no | `auto-generated/NexusTK/social/Chatting.cpp` | `by-class/ChatInputPane.md` |  |
| [UID:0002S9][0x005b38e0-0x005b3935.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3935.ChatInputPaneRawConstructor.md) | emits | `00001Q` | `00001Q` |  | no | `auto-generated/NexusTK/social/Chatting.cpp` | `by-memory/0x005b38e0-0x005b3935.ChatInputPaneRawConstructor.md` |  |
| [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md) | emits | `00001Q` | `00001Q` |  | no | `auto-generated/NexusTK/social/Chatting.cpp` | `by-memory/0x005b3940-0x005b3bba.ChatInputPane.md` |  |
| [UID:0003JP][0x00630a14-0x00630a18.ChatInputPaneChevronPromptString](by-memory/0x00630a14-0x00630a18.ChatInputPaneChevronPromptString.md) | emits | `00001Q` | `00001Q` |  | no | `auto-generated/NexusTK/social/Chatting.cpp` | `by-memory/0x00630a14-0x00630a18.ChatInputPaneChevronPromptString.md` |  |
| [UID:000309][0x0069bf68-0x0069bf6c.g_pChatInputPane](by-memory/0x0069bf68-0x0069bf6c.g_pChatInputPane.md) | emits | `000308` | `000308` |  | no | `auto-generated/NexusTK/social/Chatting.cpp` | `by-memory/0x0069bf68-0x0069bf6c.g_pChatInputPane.md` |  |
| [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md) | not_reconstructable | `NONE` |  |  | no |  | `by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md` |  |
```

No generated coverage row edits are part of this report-only pass.

## Scoped Validator Baseline

Command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00001Q-ChatInputPane-class-source-quality-removed.md](00001Q-ChatInputPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code: `0`
- Mode: dry run, `apply: False`
- Scanned markdown files: `1`
- OK count: `1`
- Target header check: `ok 00001Q by-class/ChatInputPane.md UID header exists`
- Registry rebuild: `4693 metadata nodes, 4083 edges`
- Emitter finding: `autogen_emitter_has_no_code 00001Q by-class/ChatInputPane.md emitting children only`
- Generated C++ dry-run result: `autogen_cpp_noop 0000I5 auto-generated/NexusTK/social/Chatting.cpp unchanged`
- Generated report dry-run result: `-ag-class`, `-ag-file`, `-ag-function`, `-ag-global`, `-ag-item`, `-ag-memory`, and `-ag-type` reports unchanged.

This baseline only validates the existing target before implementation. It does not apply the report recommendations.

## Report-Only Compliance

- This report recommends changes but does not edit any by-* documentation file.
- This report recommends coverage row text but does not edit `by-memory/-coverage-report.md`.
- `Agent-B014/notes.md` is the only non-report file intended to be updated for assignment handoff.
- The implementation callback should decide whether to split [UID:0001MC] before adding method-body C++.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/00001Q-ChatInputPane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"00001Q"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00001Q-ChatInputPane-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/00001Q-ChatInputPane-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00001Q"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
