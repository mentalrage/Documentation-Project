** TARGET-REPORT-UID:0000C7 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000C7 SayToUserNameInputPane Source-Quality Research

## Status

FINISHED B-agent report-only pass. No by-* documentation was edited. `by-memory/-coverage-report.md` was not edited.

Assignment id: `B003-goal2-say-to-user-name-input-pane-source-quality-0000C7-20260619`

## Target

- UID: `0000C7`
- Primary doc: `source-3/project-documentation/by-class/SayToUserNameInputPane.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0000C7-SayToUserNameInputPane-source-quality.md`
- Current metadata: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000N9`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N9`
- Current owner route: [UID:0000N9] `SayInputPanes`
- Main memory aggregate: [UID:0001MD] `0x005b3cb0-0x005b4219.SayToUserNameInputPane`
- Embedded child needing coordinated rename: [UID:0001ME] current filename `0x005b3e80-0x005b4071.LineInputPaneHistoryNavigation.md`

## Executive Recommendation

Raise [UID:0000C7] to `COMPLETION:87`, `CONFIDENCE:91`, keep `CANONICAL_OWNER:0000N9`, keep `RECONSTRUCTABLE:TRUE`, and keep `EMITTER_UIDS:0000N9`.

The class is live, source-authored, and belongs with the `SayInputPanes` direct-message/whisper input family. The remaining blockers are documentation-structure items, not behavior blockers: the stale history-navigation filename should be corrected, and final method-body C++ is best hosted by exact method children rather than the class inventory page.

Recommended class-level C++ for `by-class/SayToUserNameInputPane.md`:

```cpp
struct InputEvent;

class SayToUserNameInputPane : public LineInputPane
{
public:
    SayToUserNameInputPane();
    virtual ~SayToUserNameInputPane();

protected:
    virtual void OnRecipientNameConfirmed();
    virtual bool HandleHistoryNavigation(const InputEvent *event);

private:
    short m_recentRecipientHistoryIndex;   // +0x108
    short m_fallbackRecipientHistoryIndex; // +0x10a

    [[CHILDREN]]
};
```

If the supervisor prefers exact method-body C++ immediately, split or add exact by-memory children for the constructor and confirmation handler first. The first-draft method bodies below are ready as source-quality drafts, but the class page itself should normally emit a declaration shell with `[[CHILDREN]]`.

## Core Findings

- `0x005b3cb0-0x005b3e7f` is `SayToUserNameInputPane::SayToUserNameInputPane()`.
- `0x005b3e80-0x005b4072` is `SayToUserNameInputPane::HandleHistoryNavigation(const InputEvent *event)`, not `LineInputPane`. The current file name is stale and one byte short.
- `0x005b4080-0x005b4219` is `SayToUserNameInputPane::OnRecipientNameConfirmed()`.
- The history-navigation function has no direct rel32 caller because it is a virtual callback. The sole dword hit is the secondary vtable slot at `0x0062fccc`.
- The confirmation function also has no direct rel32 caller; its vtable route is primary slot `0x0062fcbc`.
- The constructor has three rel32 callers: `0x005a5490`, `0x005a638b`, and `0x005b1d0b`. The last is `NewSayToUserMessageInputPane::HandleKeyInput` returning from empty Backspace to recipient-name entry.
- `byte_66DA97` should be documented as [UID:0000SW] `g_useEpfAssets`, the broad current EPF/layout selector. Its local direct-message effect is selecting modern `NewSayToUserMessageInputPane` versus legacy `SayToUserMessageInputPane`; do not rename the global as whisper-only.
- The modern recipient-name prompt is literal `L"To "` at `0x00630a18`; the legacy recipient-name prompt is language id `150` from `g_pLanguageMan` / `dword_67A750`.
- Confirmation stores non-empty recipient names through the recent-recipient update helper at `0x005a4b60`, then opens the modern or legacy direct-message pane.

## Boundary And Endpoint Recheck

Direct PE/Capstone evidence from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

- File MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA-256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- Image base: `0x00400000`
- `.text`: `0x00401000-0x0060c600`
- `.rdata`: `0x0060d000-0x0066c200`
- `.data`: `0x0066d000-0x0069ce24`

Boundary results:

| Span | Result |
| --- | --- |
| `0x005b3ca5-0x005b3cb0` | eleven `0xcc` bytes before constructor |
| `0x005b3cb0-0x005b3e7f` | constructor body, size `0x1cf` |
| `0x005b3e7f-0x005b3e80` | one `0xcc` byte |
| `0x005b3e80-0x005b4072` | history-navigation body, size `0x1f2`; byte `0x005b4071` is the final `00` byte |
| `0x005b4072-0x005b4080` | fourteen `0xcc` bytes |
| `0x005b4080-0x005b4219` | confirmation body, size `0x199` |
| `0x005b4219-0x005b4220` | seven `0xcc` bytes before raw ShoutInputPane constructor |

The true [UID:0001ME] half-open range is `0x005b3e80-0x005b4072`; the current filename `0x005b3e80-0x005b4071.LineInputPaneHistoryNavigation.md` must be renamed to:

```text
source-3/project-documentation/by-memory/0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation.md
```

## Constructor Behavior

The constructor:

- Calls `LineInputPane::LineInputPane(0)` at `0x005b3ced`.
- Installs three `SayToUserNameInputPane` vtable views at `0x0062fc74`, `0x0062fcc4`, and `0x0062fcf4`.
- In the `g_useEpfAssets == 1` branch, calls `LineInputPane::SetPromptText(L"To ")`.
- In the legacy branch, calls `g_pLanguageMan->GetString(150)` and passes that prompt to `LineInputPane::SetPromptText`.
- Initializes `m_recentRecipientHistoryIndex` at `this+0x108` and `m_fallbackRecipientHistoryIndex` at `this+0x10a` to `-1`.
- Reads `g_pUserPane + 0x13eb10` / historical `dword_67A748 + 0x13eb10`. When nonzero, it preloads through `UserPane::GetPreviousRecentRecipientHistory`; when zero, it preloads through `UserPane::GetPreviousFallbackRecipientHistory`.
- If a preloaded recipient exists, selects all text in the inherited text edit (`this+0xfc`), inserts the wide recipient, and selects all again.
- Stores `1` at `this+0x104`. Best source-facing role is inherited `LineInputPane::SetInputReady(true)` / input-ready state. Exact original field spelling is not proven.

## History Navigation Behavior

`0x005b3e80` is called through the secondary `this+0xa0` view. Its local `this+0x68` and `this+0x6a` references map back to the primary class fields at `+0x108` and `+0x10a`.

Behavior:

- Narrows `event[8]` through the `std::ctype<char>` facet at `dword_67A754`, using `event[0x10a]` as the fallback/mode byte.
- Handles only key event type `event[4] == 8` and narrowed key bytes `0x81` or `0x83`; otherwise delegates to `LineInputPane::HandleKeyInput`.
- For event mode `0`, navigates fallback-recipient history at `g_pUserPane + 0x13eb0c`.
  - `0x81` calls `UserPane::GetPreviousFallbackRecipientHistory(&m_fallbackRecipientHistoryIndex, name, 0x100)`.
  - `0x83` advances forward inline by reading the table count at `+0x0c`, wrapping `(cursor + 1 + count) % count`, fetching table vtable slot `+0x10`, and copying the selected name.
- For event mode `4`, navigates recent-recipient history at `g_pUserPane + 0x13eb08`.
  - `0x81` calls `UserPane::GetPreviousRecentRecipientHistory(&m_recentRecipientHistoryIndex, name, 0x100)`.
  - `0x83` advances forward inline with the same table count/wrap/fetch/copy pattern.
- If a non-empty name is produced, it replaces the inherited text edit content and selects the inserted name.
- Returns `true` for handled history navigation and otherwise returns `LineInputPane::HandleKeyInput(event)`.

## Confirmation Behavior

`OnRecipientNameConfirmed`:

- Checks `LineInputPane::TextLength()` and ignores empty/cancelled entries.
- Copies up to `0xff` wide characters from the inherited edit field through `LineInputPane::CopyText`.
- Rejects an empty copied recipient string.
- Calls the recent-recipient update helper at `0x005a4b60`.
- In the modern branch (`g_useEpfAssets == 1`), allocates `0x208` bytes and calls `NewSayToUserMessageInputPane::NewSayToUserMessageInputPane(recipientName)`.
- In the legacy branch, allocates `0x208` bytes, calls `LineInputPane::LineInputPane(0)`, installs `SayToUserMessageInputPane` vtables, copies the recipient into `this+0x108`, formats `L"-> %s: "`, and calls `LineInputPane::SetPromptText`.

The legacy inline construction is source-equivalent to the existing [UID:0000C6] constructor behavior, but the binary inlines it in this confirmation handler. Do not model the legacy branch as a direct call to `SayToUserMessageInputPane::SayToUserMessageInputPane` unless a future source import proves that call boundary.

## Recipient History Helpers And Fields

Recommended source-facing names and roles:

| Binary item | Recommended name / role | Confidence |
| --- | --- | --- |
| `dword_67A748` | `g_pUserPane` in this context; cross-link [UID:0000QK] historical `g_pCollectionData` storage | medium-high |
| `dword_67A748 + 0x13eb04` | `m_chatHistory` | high from `SayInputPane` / Wave2 chat-history helpers |
| `dword_67A748 + 0x13eb08` | `m_recentRecipientHistory` | high |
| `dword_67A748 + 0x13eb0c` | `m_fallbackRecipientHistory` | high |
| `dword_67A748 + 0x13eb10` | `m_hasRecentRecipientHistory` / recent-recipient active flag | medium-high |
| `0x005a4ab0` | `UserPane::GetPreviousRecentRecipientHistory(short *historyIndex, wchar_t *output, size_t outputCount) const` | high; Wave2 restored name and raw code agrees |
| `0x005a4c30` | `UserPane::GetPreviousFallbackRecipientHistory(short *historyIndex, wchar_t *output, size_t outputCount) const` | high; Wave2 restored name and raw code agrees |
| `0x005a4b60` | `UpdateRecentRecipientList` / `UserPane::SaveRecentRecipient` | medium-high; Wave2 registry has `UpdateRecentRecipientList`, but final file ownership remains split-sensitive |
| `this+0x108` | `m_recentRecipientHistoryIndex` | high |
| `this+0x10a` | `m_fallbackRecipientHistoryIndex` | high |
| `this+0xfc` | inherited `LineInputPane::m_textEditPane` | high from LineInputPane docs |
| `this+0x104` | inherited input-ready state / `SetInputReady(true)` | medium |

The current [UID:0000P1] `UserPane` docs intentionally exclude most `0x005a4930-0x005a5791` chat/say helpers from `UserPane.cpp` until source partitioning is proven. Keep the helper names as `UserPane` state APIs for call clarity, but keep [UID:0000C7] and its C++ route in [UID:0000N9] `SayInputPanes`.

## Modern Versus Legacy Direct-Message Flow

Modern branch:

- `g_useEpfAssets == 1`.
- Recipient-name prompt literal is `L"To "`.
- Confirmation allocates and calls `NewSayToUserMessageInputPane`.
- The follow-up modern message pane prompt is `L"To %s : "`.
- Empty Backspace from the modern message pane returns to this name-entry constructor.

Legacy branch:

- `g_useEpfAssets != 1`.
- Recipient-name prompt comes from language id `150`.
- Confirmation allocates and inline-constructs `SayToUserMessageInputPane`.
- The follow-up legacy message pane prompt is `L"-> %s: "`.

Both follow-up message pane classes send the same direct-message opcode `0x19` recipient/message packet family. This target is about choosing and priming the recipient name, not changing the network protocol.

## Source Placement And Owner Ranking

Keep direct owner/emitter [UID:0000N9] `SayInputPanes`.

Ranking:

1. `SayInputPanes` / `NexusTK/social/SayInputPanes.cpp`: best current owner. It already owns default say, shout, legacy direct-message, modern direct-message, group, plan/clan, direct prompt strings, and mode dispatcher pages.
2. Possible future `WhisperInputPanes.cpp`: plausible split, but weaker than existing route because current source tree and docs centralize the `Say*` direct-message family under `SayInputPanes`.
3. `LineInputPane`: rejected as owner. It is the base class and unhandled-key delegate only; vtable slot `0x0062fccc` belongs to `SayToUserNameInputPane`.
4. `NewSayToUserMessageInputPane`: rejected as owner. It calls the constructor on empty Backspace and is constructed after confirmation, but the recipient-name prompt is its sibling/predecessor class.
5. `SayToUserMessageInputPane`: rejected as owner. The legacy branch constructs it inline after confirmation; that is a consumer/sibling relationship, not ownership.
6. `UserPane`: rejected as class/source owner for [UID:0000C7]. `g_pUserPane` provides history tables and helpers, but by-file `UserPane.md` explicitly treats most chat/say helpers as social-source exclusions.
7. No-owner/generated artifact: rejected. Constructor direct callers, two vtable callback slots, vtable stores, prompt string refs, and direct-message flow prove source-authored UI code.

## Source Split / Child-Page Recommendation

For final C++ readiness, split the aggregate [UID:0001MD] into exact method pages or at least add exact method children:

| Proposed page | Range | Role |
| --- | --- | --- |
| `0x005b3cb0-0x005b3e7f.SayToUserNameInputPaneConstructor.md` | `0x005b3cb0-0x005b3e7f` | constructor body |
| `0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation.md` | `0x005b3e80-0x005b4072` | existing [UID:0001ME] rename/range correction |
| `0x005b4080-0x005b4219.SayToUserNameInputPaneOnRecipientNameConfirmed.md` | `0x005b4080-0x005b4219` | confirmation callback |

Padding rows:

- `0x005b3e7f-0x005b3e80`: one `0xcc`
- `0x005b4072-0x005b4080`: fourteen `0xcc`
- Existing `0x005b4219-0x005b4220`: seven `0xcc`

This split is not required to prove ownership, but it gives the project a clean place for method-body C++ without mixing an aggregate and a nested child.

## First-Draft Method C++

These drafts are source-shaped and intentionally omit vtable stores, SEH scaffolding, cookie checks, and inline binary receiver adjustments.

```cpp
SayToUserNameInputPane::SayToUserNameInputPane()
    : LineInputPane(0),
      m_recentRecipientHistoryIndex(-1),
      m_fallbackRecipientHistoryIndex(-1)
{
    if (g_useEpfAssets) {
        SetPromptText(L"To ");
    } else {
        SetPromptText(g_pLanguageMan->GetString(150));
    }

    wchar_t initialRecipient[64] = {};
    if (g_pUserPane->m_hasRecentRecipientHistory) {
        g_pUserPane->GetPreviousRecentRecipientHistory(
            &m_recentRecipientHistoryIndex,
            initialRecipient,
            64);
    } else {
        g_pUserPane->GetPreviousFallbackRecipientHistory(
            &m_fallbackRecipientHistoryIndex,
            initialRecipient,
            64);
    }

    if (initialRecipient[0] != L'\0') {
        TextEditPane *edit = GetInputEditPane();
        edit->SelectRange(0, 32767);
        edit->InsertText(initialRecipient,
                         static_cast<short>(wcslen(initialRecipient)),
                         0,
                         0);
        edit->SelectRange(0, 32767);
    }

    SetInputReady(true);
}

bool SayToUserNameInputPane::HandleHistoryNavigation(const InputEvent *event)
{
    const unsigned char key = NarrowInputKey(event->key, event->mode);
    if (event->message != 8 || (key != 0x81 && key != 0x83)) {
        return LineInputPane::HandleKeyInput(event);
    }

    wchar_t recipient[256] = {};

    if (event->mode == 0) {
        if (key == 0x81) {
            g_pUserPane->GetPreviousFallbackRecipientHistory(
                &m_fallbackRecipientHistoryIndex,
                recipient,
                256);
        } else {
            g_pUserPane->GetNextFallbackRecipientHistory(
                &m_fallbackRecipientHistoryIndex,
                recipient,
                256);
        }
    } else if (event->mode == 4) {
        if (key == 0x81) {
            g_pUserPane->GetPreviousRecentRecipientHistory(
                &m_recentRecipientHistoryIndex,
                recipient,
                256);
        } else {
            g_pUserPane->GetNextRecentRecipientHistory(
                &m_recentRecipientHistoryIndex,
                recipient,
                256);
        }
    } else {
        return LineInputPane::HandleKeyInput(event);
    }

    if (recipient[0] != L'\0') {
        TextEditPane *edit = GetInputEditPane();
        edit->SelectRange(0, 32767);
        edit->InsertText(recipient, static_cast<short>(wcslen(recipient)), 0, 0);
        edit->SelectRange(0, 32767);
    }

    return true;
}

void SayToUserNameInputPane::OnRecipientNameConfirmed()
{
    if (TextLength() <= 0) {
        return;
    }

    wchar_t recipientName[256] = {};
    CopyText(recipientName, 255);
    if (recipientName[0] == L'\0') {
        return;
    }

    g_pUserPane->UpdateRecentRecipientList(recipientName);

    if (g_useEpfAssets) {
        new NewSayToUserMessageInputPane(recipientName);
        return;
    }

    new SayToUserMessageInputPane(recipientName);
}
```

Notes for implementation:

- `GetNextFallbackRecipientHistory` and `GetNextRecentRecipientHistory` are source-facing convenience names for the inline forward-navigation branches inside `0x005b3e80`. If no separate UserPane methods are accepted, keep those forward branches inline in the history-navigation method.
- If the project avoids `new` in recovered drafts, expand the allocation helper as `operator new(0x208)` followed by constructor call. The human source form should still read as object construction.
- Use `g_useEpfAssets` in docs. A local wrapper such as `UseModernWhisperFlow()` is acceptable only if the support docs introduce it as source-level sugar over the global, not as a separate recovered global.

## Heuristic / Inference Reanalysis And Validation

Resolved issues:

- Stale `LineInputPaneHistoryNavigation`: resolved as `SayToUserNameInputPane` secondary-vtable callback. `LineInputPane` is only the fallback delegate.
- Stale endpoint `0x005b4071`: resolved to true half-open end `0x005b4072`.
- Modern-vs-legacy flow: resolved as local use of broad `g_useEpfAssets`; modern creates `NewSayToUserMessageInputPane`, legacy inline-constructs `SayToUserMessageInputPane`.
- Recipient history fields: resolved to `m_recentRecipientHistoryIndex` (`+0x108`) and `m_fallbackRecipientHistoryIndex` (`+0x10a`), adjusted as `+0x68/+0x6a` in the secondary callback.
- History tables: resolved as `g_pUserPane + 0x13eb08` recent recipient, `+0x13eb0c` fallback recipient, and `+0x13eb10` recent-history active/dirty flag.
- Prompt globals: resolved as `g_useEpfAssets`, `g_pLanguageMan`, `L"To "`, `L"-> %s: "`, and `L"To %s : "` direct-whisper string data.
- Route/liveness: constructor has direct callers; confirmation/history are live by vtable slots.

Rejected or lower-ranked alternatives:

- `LineInputPane` method ownership: rejected by vtable slot and class-field offsets.
- `UserPane` source ownership for this class: rejected as dependency-only; current `UserPane.cpp` docs exclude social/say helpers.
- Generated/no-code treatment: rejected for the class and method bodies. Only vtable stores, SEH, cookie checks, and potential scalar deleting/destructor wrappers are compiler output.
- No split needed: rejected for final C++ hygiene. The current aggregate can keep evidence, but exact children are cleaner for method bodies.

Open questions after reanalysis:

- Exact original spelling for the secondary virtual may be `HandleHistoryNavigation`, `OnKeyInput`, or a project-specific key callback. Existing Wave2 rename registry and current docs support `HandleHistoryNavigation`; keep that unless surrounding virtual naming changes.
- Exact original field name for `this+0x104` is not proven. Use role wording `input-ready state` / `SetInputReady(true)`.
- Exact final source partition between `SayInputPanes.cpp` and a possible `WhisperInputPanes.cpp` remains unproven. Existing owner/emitter route is stronger than the split alternative.
- `0x005a4b60` has Wave2 `UpdateRecentRecipientList` naming but uncertain source-file placement. Use the name for role clarity; do not move [UID:0000C7] out of `SayInputPanes`.

## Evidence Checked

Instructions and workflow:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B003/goal.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/inference_research.md`
- `source-3/project-documentation/by-project-structure/proposed-source-tree.md`

Target and support docs:

- `by-class/SayToUserNameInputPane.md`
- `by-memory/0x005b3cb0-0x005b4219.SayToUserNameInputPane.md`
- `by-memory/0x005b3e80-0x005b4071.LineInputPaneHistoryNavigation.md`
- `by-file/SayInputPanes.md`
- `by-class/SayToUserMessageInputPane.md`
- `by-class/NewSayToUserMessageInputPane.md`
- `by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md`
- `by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md`
- `by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md`
- `by-memory/0x00630a18-0x00630a44.DirectWhisperPromptFragments.md`
- `by-class/LineInputPane.md`
- `by-memory/0x004f2300-0x004f230f.LineInputPaneCopyText.md`
- `by-global/g_useEpfAssets.md`
- `by-global/g_pCollectionData.md`
- `by-class/UserPane.md`
- `by-file/UserPane.md`
- `by-file/Chatting.md`
- `by-class/SayInputPane.md`
- `by-memory/-coverage-report.md`
- `by-class/-coverage-report.md`
- `auto-generated/-ag-class-coverage.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/social/SayInputPanes.cpp`
- Agent-B014 report `000099-NewSayToUserMessageInputPane-source-quality.md`

Historical/source leads checked:

- `source-2/core/wave2/recovered/UserPane_005A4AB0_GetPreviousRecentRecipientHistory.cpp`
- `source-2/core/wave2/recovered/UserPane_005A4C30_GetPreviousFallbackRecipientHistory.cpp`
- `source-2/core/wave2/recovered/UserPane_005a49e0_SaveChatHistory.cpp`
- Wave2 rename registry and cached source records for `HandleHistoryNavigation`, `OnRecipientNameConfirmed`, and `UpdateRecentRecipientList`.
- Wave3 derived baseline for `SayToUserNameInputPane` first-draft source, used only as a source-name lead and rechecked against raw PE.

Direct PE evidence:

- Disassembled `0x005b3cb0-0x005b4219`, `0x005a4ab0-0x005a4c8b`.
- Scanned rel32 calls to constructor, history, confirmation, and helper targets.
- Scanned `.text`, `.rdata`, and `.data` dword hits for method starts, vtables, and prompt literals.
- Verified boundary bytes and padding around `0x005b3ca5`, `0x005b3e7f`, `0x005b4071`, `0x005b4072`, `0x005b4219`, and `0x005b4220`.

IDA MCP was not exposed as a callable namespace in this Codex run. Existing IDA-backed docs were used as prior evidence, and direct PE/Capstone scans were used for independent verification. No IDA database writes were made.

## Recommended Exact Target Changes

In `by-class/SayToUserNameInputPane.md`:

1. Change metadata:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. Add declaration-level C++ with `[[CHILDREN]]` from the executive recommendation.

3. Update the method table:

- `SayToUserNameInputPane()` at `0x005b3cb0-0x005b3e7f`.
- `HandleHistoryNavigation(const InputEvent *event)` with [UID:0001ME] true range `0x005b3e80-0x005b4072` and stale filename pending rename.
- `OnRecipientNameConfirmed()` at `0x005b4080-0x005b4219`.

4. Add source-quality notes:

- Constructor direct callers `0x005a5490`, `0x005a638b`, and `0x005b1d0b`.
- Vtable slots `0x0062fcbc -> 0x005b4080` and `0x0062fccc -> 0x005b3e80`.
- Field layout `m_recentRecipientHistoryIndex` `+0x108`, `m_fallbackRecipientHistoryIndex` `+0x10a`, inherited input-ready state at `+0x104`.
- `g_useEpfAssets` local modern-vs-legacy direct-message effect.
- `g_pUserPane` / historical `g_pCollectionData` recipient-history dependency.

## Recommended Support-Doc Changes

- `by-memory/0x005b3cb0-0x005b4219.SayToUserNameInputPane.md`: update score to `88/91`, replace old 95/95 wording with active gate wording, add helper names from this report, add first-draft readiness notes, and recommend exact child split.
- Rename [UID:0001ME] file to `0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation.md`; update title, references, `tools/validator.ini`, and generated coverage rows. Recommended score `88/91`.
- `by-file/SayInputPanes.md`: update the `SayToUserNameInputPane` row to describe the constructor/history/confirmation trio, current `g_useEpfAssets` local flow, `UserPane` recipient-history dependency, and declaration-ready class C++. Replace `g_useModernWhisperFlow` wording with `g_useEpfAssets` unless explicitly described as local source sugar.
- `by-class/LineInputPane.md`: after the rename, replace stale [UID:0001ME] link and keep the note that the method delegates to `LineInputPane::HandleKeyInput`.
- `by-class/NewSayToUserMessageInputPane.md`: ensure the empty-Backspace route mentions constructor callsite `0x005b1d0b` returning to `SayToUserNameInputPane`.
- `by-class/SayToUserMessageInputPane.md`: preserve the legacy inline construction branch from `0x005b4080` and note it uses the same opcode `0x19` follow-up message family.
- `by-memory/0x00630a18-0x00630a44.DirectWhisperPromptFragments.md`: no score change required; cross-reference that `L"To "` at `0x00630a18` is the modern recipient-name prompt, `L"-> %s: "` is legacy follow-up prompt, and `L"To %s : "` is modern follow-up prompt.
- `by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md`: add a cross-reference noting that `0x005a4b60` is called from recipient confirmation as recent-recipient update; keep the broad aggregate non-emitting.
- `by-file/UserPane.md` / `by-class/UserPane.md`: optional note that recipient-history helper names are useful call dependencies but do not move [UID:0000C7] out of `SayInputPanes`.
- `auto-generated/NexusTK/social/SayInputPanes.cpp`: after accepted implementation and autogen, the empty emitter marker should point to the renamed [UID:0001ME] path.

## Coverage Text

Do not edit `by-memory/-coverage-report.md` in the B-agent pass. Recommended exact replacement rows:

```markdown
    - [UID:0001MD][0x005b3cb0-0x005b4219.SayToUserNameInputPane](by-memory/0x005b3cb0-0x005b4219.SayToUserNameInputPane.md) 0x005b3cb0-0x005b4219 | class-method aggregate | SayToUserNameInputPane : reconstructable : 88% : very strong : B003 source-quality reanalysis resolves the recipient-name direct-message flow: constructor `0x005b3cb0-0x005b3e7f`, stale history child true range `0x005b3e80-0x005b4072`, confirmation callback `0x005b4080-0x005b4219`, constructor callsites `0x005a5490`/`0x005a638b`/`0x005b1d0b`, vtable callback routes `0x0062fcbc` and `0x0062fccc`, `g_useEpfAssets` modern-vs-legacy direct-message branch, `g_pUserPane` recipient-history tables at `+0x13eb08/+0x13eb0c` with active flag `+0x13eb10`, recent/fallback history cursor fields at `this+0x108/+0x10a`, and first-draft method C++ readiness after exact child split.
    - [UID:0001ME][0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation](by-memory/0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation.md) 0x005b3e80-0x005b4072 | class method | SayToUserNameInputPaneHistoryNavigation : reconstructable : 88% : very strong : B003 source-quality reanalysis confirms stale filename/range correction from `LineInputPaneHistoryNavigation` to `SayToUserNameInputPaneHistoryNavigation`: secondary-vtable slot `0x0062fccc`, no direct rel32 callers, true endpoint `0x005b4072`, adjusted `this+0x68/+0x6a` map to primary `+0x108/+0x10a` recipient-history cursors, event modes `0` and `4` navigate fallback/recent recipient history, and unhandled input delegates to `LineInputPane::HandleKeyInput`.
```

Recommended exact replacement row for `by-class/-coverage-report.md`:

```markdown
- [UID:0000C7][SayToUserNameInputPane](by-class/SayToUserNameInputPane.md) : reconstructable : 87% : very strong : B003 source-quality reanalysis resolves the direct-message recipient-name class shape under `SayInputPanes`: constructor `SayToUserNameInputPane()`, virtual `HandleHistoryNavigation(const InputEvent *)`, virtual `OnRecipientNameConfirmed()`, constructor callers `0x005a5490`/`0x005a638b`/`0x005b1d0b`, vtable callback slots `0x0062fcbc`/`0x0062fccc`, `m_recentRecipientHistoryIndex` at `+0x108`, `m_fallbackRecipientHistoryIndex` at `+0x10a`, inherited input-ready state at `+0x104`, `g_useEpfAssets` modern-vs-legacy direct-message flow, `g_pUserPane` recipient-history dependency, stale [UID:0001ME] rename/range fix to `0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation`, and declaration-level class C++ readiness with method bodies reserved for exact by-memory children.
```

After [UID:0001ME] rename, autogen memory coverage should replace the stale path:

```markdown
| [UID:0001ME][0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation](by-memory/0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation.md) | emits | `0000C7` | `0000C7` |  | no | `auto-generated/NexusTK/social/SayInputPanes.cpp` | `by-memory/0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation.md` |  |
```

## Validator Needs

Recommended validation commands after accepted implementation:

> Executable block R001 was removed from this report and preserved verbatim in [0000C7-SayToUserNameInputPane-source-quality-removed.md](0000C7-SayToUserNameInputPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Add scoped validators for optional `UserPane`, `SayModeHelpers`, and prompt-fragment pages if they are edited.

## IDA Rename / Type / Comment Recommendations

Do not apply during this report pass.

| Item | Recommendation | Confidence |
| --- | --- | --- |
| `0x005b3cb0` | rename/type as `SayToUserNameInputPane::SayToUserNameInputPane()` | high |
| `0x005b3e80` | rename/type as `SayToUserNameInputPane::HandleHistoryNavigation(const InputEvent *event)` | high for owner/role, medium-high for exact spelling |
| `0x005b4080` | rename/type as `SayToUserNameInputPane::OnRecipientNameConfirmed()` | high |
| `0x0062fc74`, `0x0062fcc4`, `0x0062fcf4` | label as `SayToUserNameInputPane` primary/secondary/tertiary vtable views | high |
| `0x0062fcbc` | comment as primary vtable slot for `OnRecipientNameConfirmed` | high |
| `0x0062fccc` | comment as secondary vtable slot for `HandleHistoryNavigation` | high |
| `this + 0x108` | `m_recentRecipientHistoryIndex` | high |
| `this + 0x10a` | `m_fallbackRecipientHistoryIndex` | high |
| `this + 0x104` | inherited input-ready state / `SetInputReady(true)` | medium |
| `0x005a4ab0` | `UserPane::GetPreviousRecentRecipientHistory(short *, wchar_t *, size_t) const` | high |
| `0x005a4c30` | `UserPane::GetPreviousFallbackRecipientHistory(short *, wchar_t *, size_t) const` | high |
| `0x005a4b60` | `UpdateRecentRecipientList(const wchar_t *)` / `UserPane::SaveRecentRecipient` role | medium-high |
| `dword_67A748` in this target | `g_pUserPane` local-player state pointer; cross-link historical `g_pCollectionData` | medium-high |
| `dword_67A750` | `g_pLanguageMan` | high |
| `dword_67A754` | `std::ctype<char>` facet / `g_pCharCTypeFacet` | medium |
| `byte_66DA97` | use support name `g_useEpfAssets`; comment local effect as modern direct-message branch | high |
| `0x00630a18` | `L"To "` recipient-name prompt | high |
| `0x00630a20` | `L"-> %s: "` legacy direct-message prompt | high |

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0000C7-SayToUserNameInputPane-source-quality.md`
- Modified: none
- Target/support by-* docs: not edited
- `by-memory/-coverage-report.md`: not edited

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0000C7-SayToUserNameInputPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:26","uid":"0000C7"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000C7-SayToUserNameInputPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0000C7-SayToUserNameInputPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000C7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
