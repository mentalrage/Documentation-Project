** TARGET-REPORT-UID:0000AO **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001 PostInputPane Source-Quality Report

Assignment: `B001-goal2-postinputpane-source-quality-0000AO-0001MK-20260617`  
Agent: `Agent-B001`  
Date: 2026-06-17  
Report-only: yes. No by-* docs, generated reports, generated source, IDA DB, source files, or coverage reports were edited.

## Executive Recommendation

- [UID:0001MK] should be range-corrected and renamed from `by-memory/0x005b5630-0x005b5830.PostInputPane.md` to `by-memory/0x005b5630-0x005b5890.PostInputPane.md`. The documented true range is already `0x005b5630-0x005b5890`, and IDA confirms `0x005b5890` is the first byte of the successor `ThrowInputPane` constructor.
- [UID:0001MK] should remain reconstructable/emitting through [UID:0000AO] `PostInputPane`. It is a coherent PostInputPane method island plus one Post-specific raw packet helper. A future exact-child split is optional, but not required for this pass.
- [UID:0000AO] should remain reconstructable under [UID:0000ID] `CommandInputPanes`; source placement should stay `NexusTK/ui/dialogs/CommandInputPanes.cpp`.
- Populate first-draft C++ on [UID:0001MK] after the rename/range correction. Keep [UID:0000AO] class-level formal C++ blank because the corrected by-memory method island should carry the method/helper bodies.
- Recommended scores:
  - [UID:0000AO] `82/90 -> 87/91`
  - [UID:0001MK] `84/90 -> 88/91`

## Evidence Reviewed

Read/rechecked:

- `tools/leaser/Agents/Supervisor.md`, `Agent-B001/goal.md`, `Agent-B001/notes.md`, `by-structure.md`, and `Agent-B001/inference_research.md`.
- [UID:0000AO] `by-class/PostInputPane.md`
- [UID:0001MK] `by-memory/0x005b5630-0x005b5830.PostInputPane.md`
- [UID:0000ID] `by-file/CommandInputPanes.md`
- [UID:0001XA] `by-type/by-vtable/CommandInputPaneVtableFamily.md`
- [UID:0003HK] `by-type/by-vtable/GroupPostInputPaneVtables.md`
- [UID:0002N6] `by-memory/0x006300d4-0x006301e8.GroupPostInputPaneVtableData.md`
- [UID:0001MJ] `by-memory/0x005b4e90-0x005b561b.GroupInputPane.md`
- [UID:0001ML] `by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md`
- Global/support docs for `g_pCollectionData`, `g_pLanguageMan`, `g_pEventMan`, `g_pGeneralPurposePanel`, `g_activeUserStatusPane`, and `g_packetSender`.
- Shared base docs for `LineInputPane`, `CharInputPane`, and `InputPanes`.
- Current `by-class/-coverage-report.md`, `by-memory/-coverage-report.md`, auto-generated memory/source rows, completion stats, and generated/simroot source pollution around `PostInputPane`.

IDA MCP evidence checked:

- Active IDA session is ready with Hex-Rays and strings available.
- Function lookup:
  - `0x005b5630`: function `sub_5B5630`, size `0xc7`, ends `0x005b56f7`.
  - `0x005b5700`: function `sub_5B5700`, size `0x6c`, ends `0x005b576c`.
  - `0x005b5770`: function `sub_5B5770`, size `0xc0`, ends `0x005b5830`.
  - `0x005b5830`: no IDA function, but decodes as a complete prologue/cookie/packet-send routine through `0x005b5890`.
  - `0x005b5890`: successor `sub_5B5890`, ThrowInputPane constructor start.
- Xrefs:
  - Constructor start `0x005b5630`: no direct call xrefs.
  - Key handler `0x005b5700`: vtable data xref from `0x006301b8`.
  - Confirm handler `0x005b5770`: vtable data xref from `0x006301a8`.
  - Raw helper start `0x005b5830`: no direct xrefs.
  - Post vtables:
    - primary `0x00630160`
    - secondary `0x006301b0`
    - tertiary `0x006301e0`
    - vtable stores at `0x005a6718/1e/28`, `0x005a9aeb/f1/fb`, and `0x005b5677/7d/87`.
- Bytes/padding:
  - `0x005b56f7-0x005b5700`: `0xcc` padding.
  - `0x005b576c-0x005b5770`: `0xcc` padding.
  - `0x005b5830-0x005b5890`: non-padding raw helper body.
  - `0x005b5890`: successor prologue begins.

## Range And Split Recommendation

The correct half-open range for [UID:0001MK] is `0x005b5630-0x005b5890`.

Inventory:

- `0x005b5630-0x005b56f7`: `PostInputPane::PostInputPane()`
- `0x005b56f7-0x005b5700`: 9 bytes `0xcc` padding
- `0x005b5700-0x005b576c`: key/input virtual handler
- `0x005b576c-0x005b5770`: 4 bytes `0xcc` padding
- `0x005b5770-0x005b5830`: confirm/accept handler
- `0x005b5830-0x005b5890`: raw opcode `0x34` post packet helper
- `0x005b5890`: first byte of successor [UID:0001ML] `ThrowUseEatInputPanes`

I do not recommend converting [UID:0001MK] into a non-emitting split/index in this pass. Exact child pages would be a valid future cleanup, but the current island is still source-facing: it contains only PostInputPane construction/input logic and one adjacent Post-specific send helper. Because this assignment is report-only and no safe split is required to remove mixed ownership, a rename/range correction plus first-draft C++ is the lowest-risk supervisor action.

If exact children are later desired, use:

- `0x005b5630-0x005b56f7.PostInputPaneConstructor`
- `0x005b5700-0x005b576c.PostInputPaneKeyInput`
- `0x005b5770-0x005b5830.PostInputPaneConfirmInput`
- `0x005b5830-0x005b5890.PostInputPaneSendPostSelectionPacketRaw`

The raw helper child could be file-owned by [UID:0000ID] if modeled as a file-local helper, or class-owned by [UID:0000AO] if modeled as a private static helper. For the current combined page, keep direct owner [UID:0000AO] because all behavior is PostInputPane-specific and emits through [UID:0000ID].

## Heuristic / Inference Reanalysis And Validation

### Source Placement

Best placement: `NexusTK/ui/dialogs/CommandInputPanes.cpp`, owned by [UID:0000ID].

Rejected alternatives:

- `InputPanes.cpp`: rejected. `CharInputPane`/`LineInputPane` own the base helpers, but this island installs PostInputPane vtables and contains Post-specific prompt and packet behavior.
- `SpellInputPanes.cpp`: rejected. The `?` shortcut shape matches spell/input classes, but tab index, prompt id, vtables, and packet opcode are PostInputPane-specific.
- `ItemActionInputPanes.cpp` or successor Throw/Use/Eat ownership: rejected. The successor starts at `0x005b5890`; there is no byte overlap.
- A standalone `PostInputPane.cpp`: not supported by project structure. Existing source tree and file doc keep Emotion/Group/Post together in `CommandInputPanes.cpp`.

Impact: [UID:0000AO] and [UID:0001MK] should keep their existing owner/emitter route through [UID:0000ID].

### Constructor Name, Signature, And Prompt Data

Recommended source-facing signature:

```cpp
PostInputPane::PostInputPane()
```

Evidence:

- Decompile at `0x005b5630` calls `CharInputPane` constructor with null initial text/prompt argument.
- It installs the three PostInputPane vtable views.
- It calls helper `0x005a40d0` into a 200-byte local buffer, consistent with a local-player name copy into `wchar_t playerName[100]`.
- It retrieves language string id `11` through `g_pLanguageMan`.
- It formats a 128-wide-character prompt buffer and passes it to `LineInputPaneSetPromptText` at `0x004f20a0`.

Best defensible names:

- `g_pCollectionData->GetLocalPlayerName(playerName)` or `CopyLocalPlayerName(playerName)` for `0x005a40d0`.
- `g_pLanguageMan->GetString(11)` or `GetLocalizedString(11)`.
- `LineInputPane::SetPromptText(prompt)`.

Rejected alternatives:

- Generated `g_pPlayerData` / `g_pLocalPlayer` names from simroot are source-pollution leads. The documented global at `0x0067a748` remains the broader local-player/collection-data singleton, currently [UID:0000QK] `g_pCollectionData`.
- Generated `SpellStringInputPane::SetPromptText` is owner pollution. The exact helper belongs to shared `LineInputPane`.

Impact: constructor is safe for first-draft C++ with descriptive helper names.

### Key Handler Name, Signature, And Event Semantics

Recommended source-facing signature:

```cpp
bool PostInputPane::OnKeyInput(const InputEvent *event)
```

Evidence:

- Vtable-only reachability comes from Post secondary vtable slot `0x006301b8`.
- The body narrows the event key through `std::ctype<char>::do_narrow`.
- It checks narrowed key `'?'`, byte `event + 0x10a == 4`, and event type byte `event + 0x04 == 8`.
- On match, it calls `GeneralPurposePanel::SwitchActiveTab(g_pGeneralPurposePanel, 2, false)` and `SoundManager::PlayEffect(g_pSoundManager, 0x198, 100)`, then returns handled.
- Otherwise it falls back to `CharInputPane::OnKeyInput`.

Best defensible names:

- `event->type` for offset `+0x04`.
- `event->keyCode` for offset `+0x08`.
- `event->narrowFallback` or `event->keyMode` for offset `+0x10a`.
- `kInputEventKey == 8` and `kPrintableKeyMode == 4` are acceptable local constants if the shared event enum is not yet finalized.
- `SwitchActiveTab(2, false)` should remain numeric or use a cautious `kPostHelpTab` alias. The evidence proves tab index `2`, but does not prove a final project enum name.

Rejected alternatives:

- Treating the key handler as a free/static callback is rejected. Its only reachability is the PostInputPane secondary vtable slot, matching the inherited input-handler interface pattern.
- Treating `?` as a text character insertion path is rejected. The body returns before base `CharInputPane::OnKeyInput` and opens a side/help panel instead.

Impact: source-facing method name and behavior are clear enough for first-draft C++.

### Confirm Handler Name, Signature, Packet Semantics, And Slot Limit

Recommended source-facing signature:

```cpp
void PostInputPane::OnConfirmInput()
```

Evidence:

- Vtable-only reachability comes from primary vtable slot `0x006301a8`.
- The handler first requires inherited text length exactly `1`.
- It copies one UTF-16 character through shared `LineInputPane` copy/text helpers.
- It maps:
  - `a-z` to `1-26`
  - `A-Z` to `27-52`
- It requires the resulting signed/byte index to be at least `1`.
- It reads `*(uint8_t *)(g_activeUserStatusPane + 0x284)` and only sends if `postIndex <= limit`.
- It writes opcode `0x34`, writes the one-byte index, explicitly null-terminates the scratch buffer, then queues exactly 2 bytes through `g_packetSender`.

Best defensible names:

- `OnConfirmInput` or `OnAcceptInput`. Existing target docs already use `OnConfirmInput`; keep it for low churn.
- `activeSlotLimit` or `maxSelectableSlot` for `g_activeUserStatusPane + 0x284`.
- `SendPostSelectionPacket(postIndex)` for the packet send.
- `kPostCommandOpcode = 0x34`.

Rejected alternatives:

- `maxPostIndex` is too specific. The same user-status pane field participates in other active slot/item selection contexts, so `activeSlotLimit` or `maxSelectableSlot` is safer.
- A two-field packet interpretation is rejected. The transmitted payload length is exactly 2 bytes: opcode `0x34` plus one mapped index byte. The trailing zero is local scratch terminator behavior, not transmitted data.
- Generated `CashShopRequest::QueueAndSendPacket` ownership is rejected. The callee at `0x00574bb0` belongs to the packet/socket send path represented by [UID:0000Q5] `g_packetSender`.

Impact: confirm handler is safe for first-draft C++.

### Raw Helper At 0x005b5830

Recommended source-facing model:

```cpp
static void SendPostSelectionPacket(unsigned char postIndex)
```

Evidence:

- `0x005b5830` is not an IDA function start, but the bytes form a complete stack-cookie-protected routine ending exactly before `0x005b5890`.
- It writes opcode `0x34` to the first byte, writes the signed byte argument to the second byte, writes a trailing zero at the third byte, and calls `QueueAndSendPacket(g_packetSender, packet, 2)`.
- It has no direct xrefs.
- The confirm handler at `0x005b5770` contains the same send sequence inline.

Best inference:

This is a source-authored Post packet helper that was either inlined into `OnConfirmInput` while retaining an out-of-line copy, or was an unreferenced retained file-local helper. It is not padding and not a compiler runtime helper.

Rejected alternatives:

- Padding/data: rejected by valid prologue, stack cookie, calls to project packet helpers, and clean `retn 4`.
- Compiler artifact: rejected because the body is domain-specific, writes opcode `0x34`, and calls the socket packet queue.
- Dead unrelated routine: rejected by exact adjacency to PostInputPane confirm logic and identical packet semantics.

Impact:

- It should remain inside the corrected [UID:0001MK] range.
- Formal C++ should represent it as a private file-local/static helper. In the draft below, `OnConfirmInput` calls the helper because that is the most plausible source shape; the binary shows the helper body retained separately and the confirm path inlined the same packet sequence.

### Packet Writer And Send Helper Names

Recommended source-facing names:

- `WritePacketByte` or `PacketBufferWriteByte` for `0x00575380`.
- `QueueAndSendPacket` for `0x00574bb0`.

Evidence:

- `0x00575380` stores the byte and zero-terminates the next byte. Existing resolved alias `WriteByteZ_575380` captures the trailing-zero behavior, but source-facing code should prefer packet intent over IDA helper shape.
- `0x00574bb0` allocates/copies `length` bytes, appends a terminator in the allocated buffer, and queues the send through the socket/thread command path.

Impact:

Use a descriptive `WritePacketByte` in first-draft C++; document that the trailing zero is local buffer safety, not protocol length.

### Vtable, Multiple Views, And Reachability

Evidence:

- [UID:0002N6] confirms PostInputPane primary, secondary, and tertiary views at `0x00630160`, `0x006301b0`, and `0x006301e0`.
- Key and confirm handlers are reachable by vtable data refs, not direct calls.
- Vtable installs exist in the constructor and in external open/dispatcher construction paths.

Best inference:

The `+0xa0` and `+0xa4` stores are compiler-generated secondary/tertiary interface views used by the shared command/input pane inheritance family. Source-facing C++ should model normal virtual overrides and should not introduce manual thunk functions for this target.

Rejected alternatives:

- Separate class ownership for the secondary and tertiary views: rejected. The vtable doc groups them under the same PostInputPane class family.
- Marking key/confirm as dead because they have no direct callers: rejected. Vtable data xrefs and class construction stores prove virtual reachability.

Impact:

No owner/emitter change. Keep vtable support docs non-emitting and source-local to [UID:0000ID].

### Generated Source Pollution

Current generated/simroot output contains useful shape but polluted ownership:

- `SpellStringInputPane::SetPromptText` should be `LineInputPane::SetPromptText`.
- `QuitInputPane::GetInputLength` / `ReadInputText` should be shared `LineInputPane` helpers.
- `CashShopRequest::QueueAndSendPacket` should be packet/socket send ownership through `g_packetSender`.
- `g_pPlayerData` / `g_pLocalPlayer` should remain evidence-bounded to the documented [UID:0000QK] local-player/collection-data singleton unless that global is renamed project-wide.

Impact:

The first-draft C++ should not reuse these generated owner names. Updating [UID:0000AO]/[UID:0001MK] will reduce stale source-pollution risk in regenerated output.

## First-Draft C++ Recommendation

[UID:0000AO] class-level `RECONSTRUCTION_CPP` should remain blank. Class pages in this family should summarize ownership/layout and let exact method/memory pages emit code.

[UID:0001MK] should populate formal C++ after the rename to `0x005b5630-0x005b5890.PostInputPane.md`. Recommended draft:

```cpp
namespace {
const unsigned char kPostCommandOpcode = 0x34;
const unsigned char kPostHelpPanelTab = 2;
const int kHelpPanelSoundId = 0x198;
const int kHelpPanelSoundVolume = 100;
const unsigned char kInputEventKey = 8;
const unsigned char kPrintableKeyMode = 4;

static void SendPostSelectionPacket(unsigned char postIndex)
{
    char packet[3];

    WritePacketByte(static_cast<char>(kPostCommandOpcode), packet);
    WritePacketByte(static_cast<char>(postIndex), packet + 1);
    packet[2] = 0;

    QueueAndSendPacket(g_packetSender, packet, 2);
}
}

PostInputPane::PostInputPane()
    : CharInputPane(0)
{
    wchar_t playerName[100];
    wchar_t prompt[128];

    g_pCollectionData->GetLocalPlayerName(playerName);
    swprintf_s(prompt, 128, g_pLanguageMan->GetString(11), playerName);
    SetPromptText(prompt);
}

bool PostInputPane::OnKeyInput(const InputEvent *event)
{
    const char key = NarrowInputKey(event->keyCode, event->narrowFallback);

    if (key == '?' &&
        event->narrowFallback == kPrintableKeyMode &&
        event->type == kInputEventKey) {
        g_pGeneralPurposePanel->SwitchActiveTab(kPostHelpPanelTab, false);
        g_pSoundManager->PlayEffect(kHelpPanelSoundId, kHelpPanelSoundVolume);
        return true;
    }

    return CharInputPane::OnKeyInput(event);
}

void PostInputPane::OnConfirmInput()
{
    if (GetTextLength() != 1)
        return;

    wchar_t text[2] = {0, 0};
    CopyText(text, 1);

    unsigned char postIndex = 0;
    const wchar_t ch = text[0];

    if (ch >= L'a' && ch <= L'z') {
        postIndex = static_cast<unsigned char>(ch - L'a' + 1);
    } else if (ch >= L'A' && ch <= L'Z') {
        postIndex = static_cast<unsigned char>(ch - L'A' + 27);
    } else {
        return;
    }

    if (postIndex < 1)
        return;

    if (postIndex > g_activeUserStatusPane->activeSlotLimit)
        return;

    SendPostSelectionPacket(postIndex);
}
```

Notes for supervisor:

- `GetLocalPlayerName`, `GetString`, `WritePacketByte`, `QueueAndSendPacket`, `activeSlotLimit`, and `NarrowInputKey` are source-facing names. If the project has stricter canonical names, map these to the canonical helpers while preserving behavior.
- The raw helper has no direct xref. The draft models the most likely source shape: source calls a helper, the compiler inlined that helper into `OnConfirmInput`, and a retained out-of-line copy remains at `0x005b5830-0x005b5890`.
- If the supervisor prefers exact binary-shape pseudocode over source-shape code, duplicate the send sequence in `OnConfirmInput` and keep `SendPostSelectionPacket` as an uncalled static helper. I do not recommend leaving formal C++ blank for [UID:0001MK].

## Score And Metadata Recommendations

[UID:0000AO] `by-class/PostInputPane.md`:

- `COMPLETION: 87`
- `CONFIDENCE: 91`
- `RECONSTRUCTABLE: TRUE`
- `CANONICAL_OWNER: 0000ID` unchanged.
- `EMITTER_UIDS: 0000ID` unchanged.
- Keep formal C++ blank; point to corrected [UID:0001MK] for method/helper C++.
- Update status to say the backing method page is `by-memory/0x005b5630-0x005b5890.PostInputPane.md`.

[UID:0001MK] corrected by-memory page:

- Rename file/link to `by-memory/0x005b5630-0x005b5890.PostInputPane.md`.
- Keep `ADDRESS_RANGE: 0x005b5630-0x005b5890`.
- `COMPLETION: 88`
- `CONFIDENCE: 91`
- `RECONSTRUCTABLE: TRUE`
- `CANONICAL_OWNER: 0000AO` unchanged.
- `EMITTER_UIDS: 0000AO` unchanged.
- Populate formal C++ using the draft above or canonicalized equivalent.

Reason score is not higher than 88/91:

- Raw helper liveness remains no-direct-xref and must be source-modeled by inference.
- Final project-wide names for the input-event layout and `g_activeUserStatusPane +0x284` field are still inferred, not globally proven.
- `g_pCollectionData` remains a broad local-player/collection-data singleton name pending any project-wide rename.

## Support Docs To Update

Required:

- [UID:0000AO] `by-class/PostInputPane.md`: update target path/range, resolved names, raw helper policy, and score/metadata.
- [UID:0001MK] by-memory page: rename to `0x005b5630-0x005b5890.PostInputPane.md`, update score/metadata, populate first-draft C++, and remove stale "filename should be renamed" wording after rename.
- `by-class/-coverage-report.md`: replace [UID:0000AO] row with the row below.
- `by-memory/-coverage-report.md`: replace [UID:0001MK] row with the row below.

Recommended no-score-change cross-reference updates:

- [UID:0000ID] `by-file/CommandInputPanes.md`: update the PostInputPane page link to the corrected filename and record the accepted source-facing helper names.
- [UID:0003HK] `by-type/by-vtable/GroupPostInputPaneVtables.md`: update any link text that references the old [UID:0001MK] filename.
- [UID:0002N6] `by-memory/0x006300d4-0x006301e8.GroupPostInputPaneVtableData.md`: update any link text that references the old [UID:0001MK] filename.
- [UID:0001ML] `by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md`: no score change; optional note that predecessor [UID:0001MK] now ends exactly at `0x005b5890`.

Generated/autogen artifacts to refresh only through supervisor validators:

- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/ui/dialogs/CommandInputPanes.cpp`
- `project-level/-auto-completion-stats.md`
- Any generated source index that currently links to `0x005b5630-0x005b5830.PostInputPane.md`

## Supervisor-Owned Coverage Rows

### by-class/-coverage-report.md

Placement: replace the existing [UID:0000AO] `PostInputPane` row.

Replacement row:

```md
- [UID:0000AO][PostInputPane](by-class/PostInputPane.md) : reconstructable : 87% : very strong : B001 2026-06-17 source-quality reanalysis keeps direct owner/emitter [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md), resolves the true method island as [UID:0001MK] `0x005b5630-0x005b5890`, confirms constructor/key/confirm/raw-helper ranges, three vtable views at `0x00630160/0x006301b0/0x006301e0`, vtable-only key/confirm reachability, prompt id `11`, local-player name helper, `?` tab-2 help shortcut/effect, `a-z`/`A-Z` post-index mapping, `g_activeUserStatusPane +0x284` active-slot-limit semantics, opcode `0x34` send through `g_packetSender`, and class-level C++ held blank because the corrected by-memory method island should carry the first-draft method/helper C++.
```

### by-memory/-coverage-report.md

Placement: replace the existing [UID:0001MK] row immediately after [UID:0001MJ] and before [UID:0001ML].

Replacement row after the file rename:

```md
- [UID:0001MK][0x005b5630-0x005b5890.PostInputPane](by-memory/0x005b5630-0x005b5890.PostInputPane.md) 0x005b5630-0x005b5890 | class-method cluster/raw helper | PostInputPane : reconstructable : 88% : very strong : B001 2026-06-17 source-quality reanalysis range-corrects the page from `0x005b5630-0x005b5830` to the true half-open `0x005b5630-0x005b5890`, keeps owner/emitter [UID:0000AO][PostInputPane](by-class/PostInputPane.md), confirms modeled constructor/key/confirm ranges, `0xcc` padding spans at `0x005b56f7-0x005b5700` and `0x005b576c-0x005b5770`, raw no-direct-xref helper `0x005b5830-0x005b5890` as Post-owned opcode `0x34` packet helper, vtable-only key/confirm reachability, three vtable installs, prompt id `11`, local-player name helper, `?` tab-2 help shortcut/effect, `a-z`/`A-Z` index mapping, `g_activeUserStatusPane +0x284` active-slot-limit check, two-byte send via `g_packetSender`, boundary before [UID:0001ML] `ThrowUseEatInputPanes`, and first-draft C++ recommendation for the corrected method island.
```

No other coverage row replacement is required for this assignment.

## Validation Commands For Supervisor

Run after applying the rename, metadata updates, support-link updates, and formal C++:

> Executable block R001 was removed from this report and preserved verbatim in [0000AO-0001MK-postinputpane-source-quality-removed.md](0000AO-0001MK-postinputpane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Also recheck generated output under `auto-generated/NexusTK/ui/dialogs/CommandInputPanes.cpp` after C++ population to ensure it no longer emits polluted `SpellStringInputPane`, `QuitInputPane`, or `CashShopRequest` ownership for this target.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B001/research/0000AO-0001MK-postinputpane-source-quality.md`

No leases were needed because this report is inside the assigned Agent-B001 research folder. No by-* documentation, generated reports, generated source, IDA DB, source files, or coverage reports were edited.

## Remaining Follow-Up

- Supervisor should apply the file rename and coverage row replacements.
- If the project later performs exact method splitting for command input panes, split [UID:0001MK] into the four exact children listed above and make the parent a non-emitting index. This is optional for the current source-quality goal.
- Project-wide event field names and `g_activeUserStatusPane +0x284` field name should eventually be finalized in shared type/global docs. Current best names for this target are `event->type`, `event->keyCode`, `event->narrowFallback`, and `activeSlotLimit`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0000AO-0001MK-postinputpane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"0000AO"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000AO-0001MK-postinputpane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0000AO-0001MK-postinputpane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000AO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
