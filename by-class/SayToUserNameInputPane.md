*** UID:0000C7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:60 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SayToUserNameInputPane : public LineInputPane
{
public:
    SayToUserNameInputPane();

protected:
    virtual void OnSubmitInput();
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    short m_recentRecipientHistoryIndex;
    short m_fallbackRecipientHistoryIndex;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

## UID0000N9 Whole-File Topology Synchronization - 2026-08-25

- Score is `94/95` after exact constructor, primary `OnSubmitInput`, secondary `HandleKeyOrTextEvent(Event *)`, two signed history cursors, UserPane dependencies, and modern/legacy follow-up closure. Deterministic emitter position is `60`.
- Formal CPP remains `[[CHILDREN]]`; formal H removes stale `InputEvent`, `HandleHistoryNavigation`, `OnRecipientNameConfirmed`, and explicit-destructor assumptions. UID0001MD owns constructor/submit and UID0001ME owns the Event handler.

# SayToUserNameInputPane

## Status

- Confidence: very strong for behavior, IDA boundaries, source owner, vtable routes, recipient-history fields, and modern/legacy direct-message flow.
- Likely source file: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- Address range: [UID:0001MD][0x005b3cb0-0x005b4219.SayToUserNameInputPane](by-memory/0x005b3cb0-0x005b4219.SayToUserNameInputPane.md)
- Autogen parent: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- C++ reconstruction: the complete class declaration lives in formal H and formal CPP contains only `[[CHILDREN]]`. UID0001MD now emits the exact constructor and `OnSubmitInput` around the UID0001ME `HandleKeyOrTextEvent(Event *)` child, so all three definitions are namespace-scope and the type is complete before UID000403's direct construction.

## Class Purpose

`SayToUserNameInputPane` prompts for a direct-message recipient name. It preloads either the outgoing/recent recipient history or incoming/fallback sender history from `g_pUserPane`, sets the recipient prompt according to the broad `g_useEpfAssets` modern/legacy UI selector, and opens either `NewSayToUserMessageInputPane` or the legacy `SayToUserMessageInputPane` after confirmation. This class belongs with the direct-message/whisper input family in [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md); [UID:000077][LineInputPane](by-class/LineInputPane.md) is the base/fallback delegate, and [UID:0000FQ][UserPane](by-class/UserPane.md) supplies history storage rather than owning this pane.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SayToUserNameInputPane()` | `0x005b3cb0-0x005b3e7f` | Initializes the base `LineInputPane`, installs three `SayToUserNameInputPane` vtable views, chooses `L"To "` or language id `150`, initializes both recipient-history cursors to `-1`, preloads a recipient from `g_pUserPane`, selects any inserted text, and marks the inherited input-ready state. |
| `HandleKeyOrTextEvent(Event *event)` | [UID:0001ME][0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation](by-memory/0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation.md) | Secondary-vtable Event override; translates key/modifier payload, cycles fallback or recent recipient history for modifiers `0` and `4`, replaces/selects text, and delegates unhandled events to the base Event method. |
| `OnRecipientNameConfirmed()` | `0x005b4080-0x005b4219` | Copies a non-empty recipient name, updates recent-recipient history through `0x005a4b60`, and opens the modern pane or inline-constructs the legacy pane. |

- The inherited and overridden contract is `bool HandleKeyOrTextEvent(Event *event)`. Historical `HandleHistoryNavigation(const InputEvent *)` was a descriptive evidence-time spelling; the same secondary-vtable history algorithm now uses the exact Event surface and current inline forward traversal.
- Historical `LineInputPane::HandleKeyInput` and broader `OnKeyInput` spellings remain only as provenance for inherited routing. They do not transfer ownership of the complete UID000364 `CharInputPane::HandleKeyOrTextEvent(Event *)` body to this class.

## Source-Quality Layout

| Binary item | Source-facing interpretation | Confidence |
| --- | --- | --- |
| `byte_66DA97` | [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md); local effect is selecting modern `NewSayToUserMessageInputPane` versus legacy `SayToUserMessageInputPane`. Do not rename it as whisper-only. | high |
| `dword_67A748` | `g_pUserPane` in this context, with historical/stable alias [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md). | medium-high |
| `dword_67A748 + 0x13eb08` | outgoing/recent direct-message recipient history list. | high |
| `dword_67A748 + 0x13eb0c` | incoming/fallback whisper-sender history list. | high |
| `dword_67A748 + 0x13eb10` | selector/active flag choosing the recent-recipient path when set and fallback-sender path when clear. | medium-high |
| `this + 0x108` | `m_recentRecipientHistoryIndex`. | high |
| `this + 0x10a` | `m_fallbackRecipientHistoryIndex`. | high |
| `this + 0x104` | inherited input-ready state, best modeled as `SetInputReady(true)` until the exact original field name is proven. | medium |
| `0x005a4ab0` | `UserPane::GetPreviousRecentRecipientHistory(short *, wchar_t *, size_t) const`. | high |
| `0x005a4c30` | `UserPane::GetPreviousFallbackRecipientHistory(short *, wchar_t *, size_t) const`. | high |
| `0x005a4b60` | recent-recipient update helper, source-facing `UpdateRecentRecipientList` / `UserPane::SaveRecentRecipient` role. | medium-high |

## Behavior Details

Constructor `0x005b3cb0` calls `LineInputPane::LineInputPane(0)`, installs the primary/secondary/tertiary vtable views at `0x0062fc74`, `0x0062fcc4`, and `0x0062fcf4`, then chooses the prompt. The modern branch uses literal `L"To "` at `0x00630a18`; the legacy branch asks [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md) / `dword_67A750` for language id `150`. After setting both short history cursor fields to `-1`, the constructor reads `g_pUserPane + 0x13eb10`: a set selector preloads through `GetPreviousRecentRecipientHistory`, and a clear selector preloads through `GetPreviousFallbackRecipientHistory`. Any non-empty preloaded name replaces the inherited text edit contents and is selected.

History navigation `0x005b3e80` has no direct rel32 caller because it is reached through secondary vtable slot `0x0062fccc`. The secondary-view offsets `this+0x68` and `this+0x6a` map back to primary offsets `+0x108` and `+0x10a`. The handler narrows the incoming key through the `std::ctype<char>` facet at `dword_67A754`, handles only key-event type `8` with narrowed bytes `0x81` or `0x83`, and uses event mode `0` for fallback sender history or mode `4` for recent recipient history. The `0x81` direction calls the previous-entry helpers; the `0x83` direction advances inline by reading the list count, wrapping `(cursor + 1 + count) % count`, fetching the selected wide string through the list vtable slot `+0x10`, and copying it into a local buffer.

Confirmation `0x005b4080` is reached through primary vtable slot `0x0062fcbc`. It requires positive `TextLength()`, copies up to `0xff` wide characters, ignores an empty recipient, then calls `0x005a4b60` to update recent-recipient history. The modern branch allocates `0x208` bytes and calls [UID:000099][NewSayToUserMessageInputPane](by-class/NewSayToUserMessageInputPane.md). The legacy branch allocates the same size, constructs the `LineInputPane` base inline, installs [UID:0000C6][SayToUserMessageInputPane](by-class/SayToUserMessageInputPane.md) vtables, copies the recipient into `+0x108`, formats `L"-> %s: "`, and sets that prompt. The inline legacy branch is source-equivalent to constructing `SayToUserMessageInputPane`, but the binary does not call its standalone constructor at `0x005b1570`.

## Owner And Rejected Alternatives

- Keep owner/emitter [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md). The family already owns default say, shout, legacy direct-message, modern direct-message, group, clan/plan target-message input, prompt fragments, and mode dispatch.
- A future `WhisperInputPanes.cpp` split is plausible, but weaker than the current route because the documented source tree and adjacent class pages centralize the `Say*` direct-message family under `SayInputPanes`.
- Reject [UID:000077][LineInputPane](by-class/LineInputPane.md) as direct owner of `0x005b3e80`: it is only the base fallback delegate, while the vtable slot is `SayToUserNameInputPane`.
- Reject [UID:000099][NewSayToUserMessageInputPane](by-class/NewSayToUserMessageInputPane.md) and [UID:0000C6][SayToUserMessageInputPane](by-class/SayToUserMessageInputPane.md) as owners: they are successor/consumer panes after the recipient is chosen.
- Reject [UID:0000FQ][UserPane](by-class/UserPane.md) as owner: it stores history lists and helper APIs, but current file docs intentionally exclude social/say helpers from `UserPane.cpp`.
- Reject generated/no-code treatment for the class and method bodies. The compiler artifacts are vtable stores, security-cookie/SEH scaffolding, and destructor/adjustor wrappers, not the recipient-name flow itself.
- Header placement is a compilation dependency. The current declaration and all three definitions are now closed without an explicit destructor; historical InputEvent/history-callback and unsplit-source uncertainty is superseded by UID0001MD/UID0001ME formal source.

## Evidence Notes

- Boundary recheck confirms eleven `0xcc` bytes before the constructor, constructor body `0x005b3cb0-0x005b3e7f`, one `0xcc` byte at `0x005b3e7f-0x005b3e80`, history body `0x005b3e80-0x005b4072`, fourteen `0xcc` bytes at `0x005b4072-0x005b4080`, confirmation body `0x005b4080-0x005b4219`, and seven `0xcc` bytes before the following `ShoutInputPane` raw constructor.
- Constructor callers include `0x005a5490`, `0x005a638b`, and `0x005b1d0b`; the last is `NewSayToUserMessageInputPane::HandleKeyInput` returning from empty Backspace to recipient-name entry.
- `OnRecipientNameConfirmed` is vtable-referenced at `0x0062fcbc`.
- 2026-06-05 IDA MCP confirms the history-navigation handler at `0x005b3e80` has size `0x1f2`, ends at `0x005b4072`, has no direct code callers, and is referenced by `SayToUserNameInputPane` secondary vtable slot `0x0062fccc`.
- The history handler delegates unhandled keys to `LineInputPane::HandleKeyInput`, so `LineInputPane` is a dependency rather than the direct owner.
- Prompt strings are `L"To "` at `0x00630a18` for modern recipient-name entry, `L"-> %s: "` at `0x00630a20` for the legacy follow-up pane, and `L"To %s : "` at `0x00630a30` for the modern follow-up pane. Both follow-up panes use opcode `0x19`; this class selects and primes the recipient rather than changing the network protocol.

## Cross-References

- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- [UID:0001MD][0x005b3cb0-0x005b4219.SayToUserNameInputPane](by-memory/0x005b3cb0-0x005b4219.SayToUserNameInputPane.md)
- [UID:0001ME][0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation](by-memory/0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation.md)
- [UID:0000C6][SayToUserMessageInputPane](by-class/SayToUserMessageInputPane.md)
- [UID:000099][NewSayToUserMessageInputPane](by-class/NewSayToUserMessageInputPane.md)

## Changes

- 2026-08-14 Agent-B002 UID000403 support implementation callback:
  - Preserved `87/91`, owner/emitter UID0000N9, reconstructable true, complete declaration text, layout, behavior, callers, vtables, histories, and all independent source-quality caveats.
  - Moved the existing complete class declaration from formal CPP to formal H and left formal CPP as `[[CHILDREN]]`, making `SayToUserNameInputPane` complete for UID000403's direct construction at namespace scope.
  - This is topology-only support. It does not claim resolution or additional coverage for this class's independently stale method-body naming/source, explicit destructor spelling, constructor split, or confirmation split.

- 2026-06-20 B003 Rule 26 source-quality incorporation:
  - Before: `84/90`, no declaration-level C++, method table still linked the stale [UID:0001ME][0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation](by-memory/0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation.md) filename/range, and the class page summarized behavior without the report-level source-placement, field/global, route, and rejected-owner evidence.
  - After: `87/91`, declaration-level class C++ with `m_recentRecipientHistoryIndex` at `+0x108`, `m_fallbackRecipientHistoryIndex` at `+0x10a`, and `[[CHILDREN]]`; method table uses exact constructor/history/confirmation roles; the source-quality layout records `g_useEpfAssets`, `g_pUserPane`, recipient-history lists/selector byte, helper names, vtable routes, prompt literals, inline legacy construction, and rejected owners.
  - Evidence: B003 report `0000C7-SayToUserNameInputPane-source-quality.md` rechecked raw PE boundaries, constructor callers `0x005a5490`/`0x005a638b`/`0x005b1d0b`, vtable slots `0x0062fcbc`/`0x0062fccc`, prompt literals, `g_pUserPane` history tables at `+0x13eb08/+0x13eb0c/+0x13eb10`, and modern/legacy direct-message flow.

- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and assigned parent `0000N9`.
  - Before: The direct-message recipient prompt remained unclassified in autogen coverage even though the class and parent file both met the 80/80 attach gate.
  - After: The class contributes to `SayInputPanes.cpp` as a reconstructable child without emitting final C++ yet.
  - Evidence: Live IDA MCP lookup confirms constructor `0x005b3cb0` and confirmation handler `0x005b4080`; parent [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) groups the legacy and modern direct-message input flow.

- 2026-06-05: Raised completion/confidence from `80/86` to `84/90` and corrected the history-navigation ownership.
  - Before: the class method map only listed the constructor and confirmation handler, while the `0x005b3e80` history-navigation handler was still documented as a `LineInputPane` non-contiguous helper.
  - After: the method map includes [UID:0001ME][0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation](by-memory/0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation.md) as `SayToUserNameInputPane` code, with its true endpoint `0x005b4072` recorded.
  - Evidence: live IDA MCP reports the sole function xref to `0x005b3e80` at `0x0062fccc`, the `SayToUserNameInputPane` secondary vtable slot; byte audit confirms `0x005b4071` is inside the function body and `0x005b4072-0x005b4080` is padding.

- 2026-05-30: Changed completion/confidence from `0/0` to `80/86`.
  - Before: The page was unevaluated despite documenting recipient prompt behavior, recent history preload, modern/legacy flow dispatch, and vtable/caller evidence.
  - After: Scored as high completion and strong confidence for the recipient-name input pane.
  - Evidence: Existing method notes, IDA MCP boundary evidence, constructor caller notes, vtable-reference note, and direct-message pane cross-references support the score.
