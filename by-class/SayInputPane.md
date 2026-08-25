*** UID:0000C3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:50 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SayInputPane : public LineInputPane
{
public:
    SayInputPane();
    explicit SayInputPane(const wchar_t *initialText);

protected:
    virtual void OnSubmitInput();
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    short m_chatHistoryCursor;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

## UID0000N9 Whole-File Topology Synchronization - 2026-08-25

- Deterministic emitter position is `50`. Formal CPP remains `[[CHILDREN]]`; the formal H virtual is source-facing `OnSubmitInput`, matching primary slot `+0x48`, and the compiler-only shared destruction wrappers do not justify an explicit derived destructor.
- UID0002S7, UID000414, UID000415, and UID000416 provide the default constructor, initial-text constructor, Event handler, and submit definition. The adjacent UID0002S8 packet island remains ownerless and non-emitting.

# SayInputPane

## Status

- Confidence: very strong for the class route, constructor overload behavior, three-vtable identity, inherited edit-child contract, signed-short history cursor, Event-based key/text override, UserPane-owned history helpers, and child-only method emission. Remaining uncertainty is limited to stripped lexical spellings and the exact historical use of `explicit`; it no longer includes the UID000415 event or helper contract.
- Likely source file: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- Address range: [UID:0001MB][0x005b34d0-0x005b37ea.SayInputPane](by-memory/0x005b34d0-0x005b37ea.SayInputPane.md)
- Historical generated/recovered file: `source-3/simroot_v2/class_SayInputPane.cpp`; current source placement is shared `NexusTK/social/SayInputPanes.cpp/.h`.
- C++ reconstruction: the declaration now lives in the H channel with the `InputPanes.h` dependency; the CPP channel contains only `[[CHILDREN]]`, so exact constructor/key/submit definitions emit at namespace scope. Source-bearing children are [UID:0002S7][0x005b3490-0x005b34d0.SayInputPaneRawConstructor](by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md), [UID:000414][0x005b34d0-0x005b356c.SayInputPaneConstructorWithInitialText](by-memory/0x005b34d0-0x005b356c.SayInputPaneConstructorWithInitialText.md), [UID:000415][0x005b3570-0x005b3670.SayInputPaneHandleKeyInput](by-memory/0x005b3570-0x005b3670.SayInputPaneHandleKeyInput.md), and [UID:000416][0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat](by-memory/0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat.md). The [UID:0001MB][0x005b34d0-0x005b37ea.SayInputPane](by-memory/0x005b34d0-0x005b37ea.SayInputPane.md) aggregate remains blank no-code evidence.

## Class Purpose

`SayInputPane` is the default local chat/say input pane. It owns chat history navigation for up/down keys and sends opcode `0x0e`, subtype `0`, after normalizing text and saving it to user chat history.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SayInputPane` | [UID:0002S7][0x005b3490-0x005b34d0.SayInputPaneRawConstructor](by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md) | Raw default constructor child now carrying first-draft `SayInputPane::SayInputPane()` C++; IDA still reports this is not a function and no direct start route is proven. |
| `SayInputPane(const wchar_t*)` | [UID:000414][0x005b34d0-0x005b356c.SayInputPaneConstructorWithInitialText](by-memory/0x005b34d0-0x005b356c.SayInputPaneConstructorWithInitialText.md) | Constructs `LineInputPane(L"> ")`, initializes signed-short `m_chatHistoryCursor=-1`, installs three SayInputPane vtable views, and inserts the supplied string through public typed `TextEditPane::InsertTextRange`; exact source-ready CPP lives on the child. |
| `HandleKeyOrTextEvent(Event *event)` | [UID:000415][0x005b3570-0x005b3670.SayInputPaneHandleKeyInput](by-memory/0x005b3570-0x005b3670.SayInputPaneHandleKeyInput.md) | Handles unmodified Up/Down key-down events through the shared `Event` payload, retrieves previous/next lines from `g_pUserPane`, replaces the inherited edit text when a nonempty line is returned, and delegates every other event to `LineInputPane::HandleKeyOrTextEvent(event)`. |
| `OnSubmitInput` | [UID:000416][0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat](by-memory/0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat.md) | Primary submit override; builds opcode `0x0e`, subtype `0`, applies password/sanitizer helpers, sends through `g_packetSender`, and saves history. Historical `OnSubmitChat` is evidence-time naming only. |
| scalar deleting destructor | `0x005b7b80-0x005b7bba` | Destroys base line input and conditionally frees memory. |

## Evidence Notes

- 2026-06-02 IDA MCP confirms `0x005b34d0-0x005b356c`, `0x005b3570-0x005b3670`, `0x005b3670-0x005b37ea`, and `0x005b7b80-0x005b7bbb`.
- 2026-06-02 IDA MCP reports no function at `0x005b3490`, but raw disassembly proves [UID:0002S7][0x005b3490-0x005b34d0.SayInputPaneRawConstructor](by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md) as the default constructor body.
- 2026-06-02 IDA vtable/data-ref evidence places key input at `0x0062fbb4 -> 0x005b3570`, submit at `0x0062fba4 -> 0x005b3670`, and destructor slot refs to `0x005b7b80`.
- The constructors write primary `0x0062fb5c`, secondary `0x0062fbac`, and tertiary `0x0062fbdc` vtable views and initialize the history cursor sentinel at `this+0x108`.
- The submit function mirrors [UID:00001Q][ChatInputPane](by-class/ChatInputPane.md) behavior but uses default say subtype `0`.
- 2026-06-12 live IDA MCP refresh reconfirms the same method bounds: raw default constructor bytes `0x005b3490-0x005b34d0`, constructor overload `0x005b34d0-0x005b356c`, key handler `0x005b3570-0x005b3670`, submit handler `0x005b3670-0x005b37ea`, and scalar deleting destructor `0x005b7b80-0x005b7bbb`.
- 2026-06-12 `xref_query` reconfirms no direct callers to the raw/default constructor or overload, vtable dispatch refs for key and submit, destructor table refs, and constructor/vtable installation refs from this raw body, the overload, and construction sites `0x005a53c0`, `0x005a5bd0`, and `0x005aa3b0`.
- 2026-06-12 decompilation reconfirms the constructor overload's `"> "` prompt, history sentinel, three vtable writes, and initial-text insertion; the key handler's previous/next history behavior; and the submit handler's opcode `0x0e`, subtype `0`, multibyte conversion, packet send, and history-save path.
- Current source names are `SayInputPane::SayInputPane(const wchar_t *initialText)`, `SayInputPane::HandleKeyOrTextEvent(Event *)`, `SayInputPane::OnSubmitInput`, `m_chatHistoryCursor`, `GetPreviousChatHistoryLine`, `GetNextChatHistoryLine`, `SaveChatHistoryLine`, `PacketBufferWriteUInt8`, `QueueAndSendPacket`, and `g_packetSender`. The 2026-06-22 `HandleKeyInput`/`OnSubmitChat` spellings are superseded history. `Chatting`, ChatInputPane, shared packet helpers, UserPane, and UID0002S8 remain rejected owners.
- 2026-06-23 B003 MCP-backed redo was the prior evidence source for the split implementation. Then-current IDA MCP session `b880584f` reported `server_health.status=ok` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `lookup_funcs` confirmed child ranges `0x005b34d0-0x005b356c`, `0x005b3570-0x005b3670`, and `0x005b3670-0x005b37ea`, `func_profile` reported `caller_count=0` for all three child starts, `xrefs_to` confirmed vtable cells `0x0062fbb4 -> 0x005b3570` and `0x0062fba4 -> 0x005b3670`, and `get_bytes` confirmed SHA16 values `0fc41bb510338c08`, `77317c3876917ced`, and `d7c586e0ec44b7f9` plus padding `0x005b356c-0x005b3570` and `0x005b37ea-0x005b37f0`.
- 2026-06-23 B005 accepted MCP revalidation supersedes `b880584f` as active evidence for the [UID:0001MB][0x005b34d0-0x005b37ea.SayInputPane](by-memory/0x005b34d0-0x005b37ea.SayInputPane.md) aggregate and its support pages. Current session `ff68e691` reported healthy `NexusTK.exe.i64` state and PE SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`; `lookup_funcs` reconfirmed raw no-function sibling `0x005b3490`, constructor overload `0x005b34d0-0x005b356c`, key/history handler `0x005b3570-0x005b3670`, submit handler `0x005b3670-0x005b37ea`, and adjacent no-function raw island start `0x005b37f0`; `xrefs_to`/vtable bytes reconfirmed `0x0062fbb4 -> 0x005b3570` and `0x0062fba4 -> 0x005b3670`; bounded raw instruction review reconfirmed the default constructor's `L"> "` prompt, base construction, `m_chatHistoryCursor` store at primary `+0x108`, and three vtable stores; and targeted pointer checks found no VA/RVA route to the raw constructor or adjacent raw island.
- 2026-06-25 B006 accepted source-quality implementation promotes [UID:0002S7][0x005b3490-0x005b34d0.SayInputPaneRawConstructor](by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md) to first-draft default-constructor C++ while preserving the no-function/no-direct-start-route facts as confidence caps. Current MCP session `80de0a67` confirms the raw body calls `LineInputPane(L"> ")`, initializes `this+0x108` / `m_chatHistoryCursor` to `-1`, stores the three SayInputPane vtable views, returns at `0x005b34ce`, and has one-byte alignment at `0x005b34cf`; zero xrefs/code/data/immediate/pointer hits remain for the raw start, but sibling overload and inline construction-site evidence prove source ownership.
- 2026-07-29 B008 UID000414 pre-Gate-2B recheck on database `1da2b2ae` confirmed the exact overload at `[0x005b34d0,0x005b356c)`, 57 instructions/seven blocks, zero direct callers/start xrefs, absent absolute/image-relative pointer encodings, then-blank target comments, then-absent `SayInputPane` IDA type, and unchanged `cc cc cc cc` successor padding. That raw/absent state is historical pre-action evidence. Supervisor Gate 2B saved current `SayInputPane__ConstructorWithInitialText` with prototype `SayInputPane *__thiscall(SayInputPane *this, const wchar_t *initialText)` and the exact constructor function comment, plus an incomplete/no-layout `SayInputPane` type. Current typed helper `TextEditPane__InsertTextRange` remains unchanged with 38 callers and exact `const wchar_t *`, signed-short length, optional format-payload, and `TextEditObject *` parameters.
- Gate-2B action checkpoint `87D34CCD103CC97F107DBABF1CA089FCE223F1650D5376A0DCB48C0E46F500F2`, 143,192,020 bytes, saved `2026-07-30T07:11:07.1602926-04:00`, is dated history. Current saved-IDB readback after an unrelated B002 transaction is SHA256 `83C20CE9E13A19CA3C5501998110D490FA3D2D2EA5FE774AE1F880403C294A9E`, 143,193,954 bytes, saved `2026-07-30T07:36:29.3601106-04:00`. The target's address comments and function-repeatable comment remain blank; its exact function-regular comment remains applied. Hex-Rays uses typed `const wchar_t *initialText`, while the physical frame remains `text: wchar_t *` plus non-source EH `arg_4` because the bounded argument-member rename/type operation was rejected without creating a duplicate argument.
- The same saved-IDB checkpoint preserves UID000415's exact `[0x005b3570,0x005b3670)` body and vtable-only route at `0x0062fbb4`. Its current raw IDA identity remains a supervisor Gate-2B handoff rather than source truth: `sub_5B3570` with adjusted `void *` receiver and raw `int` event argument. The accepted source declaration is nevertheless `bool HandleKeyOrTextEvent(Event *event)`: the body reads `Event::m_type` and the key/modifier payload, calls the same `EventMan` translation service used by the base handler, and forwards the identical Event pointer to [UID:00035Y][0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput](by-memory/0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md). This removes the historical `PaneKeyEvent` invention without pretending the pending IDA rename/type/comment action is already applied.
- Chat-history ownership is resolved to `UserPane`, not this class or the `SayInputPanes` source unit. `GetPreviousChatHistoryLine`, `GetNextChatHistoryLine`, and `SaveChatHistoryLine` operate on `g_pUserPane->m_chatHistory` at `UserPane + 0x13eb04`; `SayInputPane` owns only the signed-short `m_chatHistoryCursor` at complete-object `+0x108` and calls those members.
- The zero-direct-start question is resolved by three source-equivalent inline sites: `0x005a53c0` reproduces default construction, the UserPane case near `0x005a62fa` constructs and inserts `L"/"`, and `0x005aa3b0` reproduces the initial-text sequence. These sites support retained out-of-line constructor code plus compiler inlining; they are evidence, not additional class/source owners.
- `m_textEditPane` is the accepted inherited `+0xfc` field name from LineInputPane construction/layout/cleanup evidence. `m_chatHistoryCursor` is the accepted signed-short `+0x108` field name because constructors store `-1` and the key child passes the same field by address to history helpers. Older raw/helper spelling uncertainty is historical rather than an unresolved first-draft blocker.

## Reconstruction Notes

This class is reconstructable at `93/94` and attached to [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md). The class H channel owns declarations; the class CPP channel owns only child insertion. Exact method children own definitions, preventing invalid nested out-of-class definitions and duplicate aggregate code. UID000415 supplies the exact Event-based override body, while UID000416 supplies submit/save behavior; neither body is duplicated here.

Do not place method-body C++ on the aggregate [UID:0001MB][0x005b34d0-0x005b37ea.SayInputPane](by-memory/0x005b34d0-0x005b37ea.SayInputPane.md) page. B014, B003, B005, and B006 confirm that range is a cluster of source methods plus padding, not one source function. The exact children now exist for the default constructor `0x005b3490-0x005b34d0`, constructor overload `0x005b34d0-0x005b356c`, key/history handler `0x005b3570-0x005b3670`, and submit handler `0x005b3670-0x005b37ea`; those children carry first-draft C++ with descriptive helper/member names. Keep [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md) excluded from SayInputPane ownership/emission until a real caller or pointer route is proven.

B003's 2026-06-23 implementation callback completed the modeled-method split: [UID:000414][0x005b34d0-0x005b356c.SayInputPaneConstructorWithInitialText](by-memory/0x005b34d0-0x005b356c.SayInputPaneConstructorWithInitialText.md), [UID:000415][0x005b3570-0x005b3670.SayInputPaneHandleKeyInput](by-memory/0x005b3570-0x005b3670.SayInputPaneHandleKeyInput.md), and [UID:000416][0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat](by-memory/0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat.md) carry method-level evidence and first-draft C++. B006 adds the raw default-constructor child [UID:0002S7][0x005b3490-0x005b34d0.SayInputPaneRawConstructor](by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md) to that source-ready child set. The class page emits only the declaration shell and child insertion point; [UID:0001MB][0x005b34d0-0x005b37ea.SayInputPane](by-memory/0x005b34d0-0x005b37ea.SayInputPane.md) remains blank aggregate evidence, not a second method-body emitter.

The declaration retains `explicit SayInputPane(const wchar_t *initialText)` as the strongest plausible human source shape for a one-argument pointer constructor. The binary cannot prove `explicit`, so that spelling remains a bounded lexical confidence cap rather than a reason to emit decompiler-style source. Offset evidence for the secondary key-handler view (`primary+0xa0`, inherited edit child at complete `+0xfc`, cursor at complete `+0x108`) remains documented here even though those reverse-engineering comments are intentionally omitted from the clean formal H declaration.

## Cross-References

- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- [UID:0001MB][0x005b34d0-0x005b37ea.SayInputPane](by-memory/0x005b34d0-0x005b37ea.SayInputPane.md)
- [UID:0002S7][0x005b3490-0x005b34d0.SayInputPaneRawConstructor](by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md)
- [UID:000414][0x005b34d0-0x005b356c.SayInputPaneConstructorWithInitialText](by-memory/0x005b34d0-0x005b356c.SayInputPaneConstructorWithInitialText.md)
- [UID:000415][0x005b3570-0x005b3670.SayInputPaneHandleKeyInput](by-memory/0x005b3570-0x005b3670.SayInputPaneHandleKeyInput.md)
- [UID:000416][0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat](by-memory/0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat.md)
- [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md)
- [UID:00001Q][ChatInputPane](by-class/ChatInputPane.md)
- [UID:0000D5][ShoutInputPane](by-class/ShoutInputPane.md)

## Changes

### 2026-07-30 - B007 UID000415 accepted ordinary implementation callback

- Raised the class from `88/90` to `93/94` after resolving the event model, history-helper ownership, and source-facing method declaration rather than retaining raw or invented signatures.
- Replaced historical `PaneKeyEvent` / `HandleKeyInput` declarations with `virtual bool HandleKeyOrTextEvent(Event *event)`, matching the shared base virtual and the target's exact Event payload reads and fallback call.
- Recorded `g_pUserPane` as the receiver for previous/next/save history members and `UserPane + 0x13eb04` as the sole source-facing `m_chatHistory` field. Older `SayInputPanes`/`Chatting` helper-ownership uncertainty remains preserved above as dated history.
- Kept the class CPP as `[[CHILDREN]]`, installed no method body on this page, and retained all constructor, vtable, layout, raw-default-constructor, no-route-island, and source-placement evidence.

- 2026-05-30: Changed completion/confidence from `0/0` to `78/78`.
  - Before: The page was unevaluated despite documenting local chat behavior, history navigation, submit packet shape, and the default-constructor caveat.
  - After: Scored as moderate-high completion and confidence because submit/history behavior is confirmed while the projected default constructor remains unresolved.
  - Evidence: Existing method notes, IDA MCP evidence notes, opcode/subtype behavior, and chat/shout cross-references support the score.
- 2026-06-02 raw-constructor and parent update:
  - Before: the class was not reconstructable/attached and still treated the default constructor as an unresolved projected start.
  - After: raised to `82/84`, marked reconstructable, attached to [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md), and linked the exact raw constructor child [UID:0002S7][0x005b3490-0x005b34d0.SayInputPaneRawConstructor](by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md).
  - Evidence: current IDA function-boundary, raw constructor, vtable/data-ref, and callee checks for the constructor/key/submit/destructor family.
- 2026-06-12 Goal 2 parent-gate refresh:
  - Before: the direct class parent was `82/84`, which blocked assigning the refreshed raw-constructor child under the strict Goal 2 `85/85` parent rule.
  - After: raised to `85/86`; parent remains [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md), which already clears the file-parent gate.
  - Evidence: live IDA MCP reconfirmed exact method bounds, vtable slots, constructor/vtable installation xrefs, key-history behavior, submit packet construction, destructor behavior, and the unresolved raw-start/no-direct-caller caveat.
- 2026-06-22 B014 Rule 26 source-quality incorporation:
  - Before: the class page did not carry the report-level child-split/no-aggregate-C++ decision or the explicit owner rejections for adjacent chat/no-route packet code.
  - After: scores and owner route remain `85/86`, `CANONICAL_OWNER:0000N9`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N9`; the class now records exact method-child split requirements, current best helper/field/protocol names, and the [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md) no-route exclusion.
  - Evidence: B014 reanalysis of `0001MB` and its sibling/support pages, including vtable dispatch slots `0x0062fbb4` and `0x0062fba4`, raw/default constructor evidence, `L"> "` prompt, `m_chatHistoryCursor`, opcode `0x0e` subtype `0`, and negative route evidence for the adjacent raw packet island.
- 2026-06-23 B003 implementation callback:
  - Metadata remains `85/86`, `CANONICAL_OWNER:0000N9`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000N9`.
  - Added declaration-only class C++ with `[[CHILDREN]]` and wired exact child method pages [UID:000414][0x005b34d0-0x005b356c.SayInputPaneConstructorWithInitialText](by-memory/0x005b34d0-0x005b356c.SayInputPaneConstructorWithInitialText.md), [UID:000415][0x005b3570-0x005b3670.SayInputPaneHandleKeyInput](by-memory/0x005b3570-0x005b3670.SayInputPaneHandleKeyInput.md), and [UID:000416][0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat](by-memory/0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat.md) into the method inventory.
  - Evidence: accepted B003 MCP-backed redo report, session `b880584f`, confirmed exact constructor/key/submit ranges, internal padding, vtable-only/no-direct-code-xref dispatch, prompt/history cursor, password/sanitizer path, opcode `0x0e` subtype `0`, PacketBuffer/`g_packetSender` dependencies, and [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSenderNoRouteRaw.md) no-route rejection.
- 2026-06-23 B005 accepted MCP revalidation implementation:
  - Metadata remains `85/86`, `CANONICAL_OWNER:0000N9`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000N9`.
  - Added current session `ff68e691` evidence for the aggregate/child split, raw constructor sibling, PE SHA-256, `m_chatHistoryCursor` offset proof, vtable cells, no-route raw-island exclusion, child C++ placement, and parent aggregate no-code rule.
  - Evidence: accepted B005 report for [UID:0001MB][0x005b34d0-0x005b37ea.SayInputPane](by-memory/0x005b34d0-0x005b37ea.SayInputPane.md), current MCP `lookup_funcs`, `get_bytes`, `decompile`, bounded `insn_query`, `xrefs_to`, `xref_query`, vtable byte reads, and targeted `find_bytes` pointer checks.
- 2026-06-25 B006 accepted source-quality implementation for [UID:0002S7][0x005b3490-0x005b34d0.SayInputPaneRawConstructor](by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md):
  - Metadata remains `85/86`, `CANONICAL_OWNER:0000N9`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000N9`.
  - Updated the method/source-quality notes so `SayInputPane::SayInputPane()` is a first-draft child C++ body on [UID:0002S7][0x005b3490-0x005b34d0.SayInputPaneRawConstructor](by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md), with no IDA function object or direct start route preserved as confidence caps.
  - Evidence: accepted B006 report, current MCP session `80de0a67`, raw instruction proof, sibling overload proof, inline construction-site equivalence, no-route negative checks, and padding exclusion at `0x005b34cf`.
- 2026-07-29 B008 UID000414 source-quality callback:
  - Raised `85/86 -> 88/90` while preserving `CANONICAL_OWNER:0000N9`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N9`, and blank position.
  - Moved the clean class declaration to H, placed only `[[CHILDREN]]` in CPP, and preserved the reverse-engineering offset rationale in prose.
  - Incorporated the exact typed InsertTextRange contract, accepted `m_textEditPane`/`m_chatHistoryCursor` names, three inline-equivalent route sites, zero-xref/pointer negative evidence, protected prompt/vtable/padding state, and explicit-versus-lexical score cap from the accepted UID000414 report.
- 2026-07-30 supervisor Gate 2B reconciliation:
  - Replaced the class page's current-tense absent-type/blank-comment prestate with the exact applied `SayInputPane__ConstructorWithInitialText` name, prototype, function-regular comment, and incomplete/no-layout `SayInputPane` type.
  - Preserved the exact zero-start-xref result, target bytes/range, prompt/vtable/padding dependencies, physical `text: wchar_t *` frame limitation, non-source EH `arg_4`, and unchanged `TextEditPane__InsertTextRange` contract.
