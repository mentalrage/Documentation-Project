** TARGET-REPORT-UID:0002EX **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001 Source-Quality Report: 0002EX / 0002F0 Chatting

Assignment: `B001-goal2-chatting-source-quality-0002EX-0002F0-20260615`

Targets:

- [UID:0002EX](../../../../../by-memory/0x0047fc70-0x0047fd3b.ChattingPaneComputeLineCount.md) `0x0047fc70-0x0047fd3b.ChattingPaneComputeLineCount`
- [UID:0002F0](../../../../../by-memory/0x0047ff80-0x00480640.ChatPacketType10Handler.md) `0x0047ff80-0x00480640.ChatPacketType10Handler`

## Recommendation

For [UID:0002EX], treat `this+0x130` as a heap-owned project `List` object containing `ColorStringChattingMessage *` entries. The best source-facing member name is role-based `m_pChatMessageList` or, if local class style avoids pointer prefixes, `m_chatMessageList`. This is stronger than `m_chatLineList` because the container stores message render objects, not precomputed line rows. Accept `ColorStringChattingMessage` as the concrete entry evidence. Reject `ChatEntryList` and `ChatEntry` as final original-source names; they are Wave2 reconstruction helper names over the generic `List` container.

For [UID:0002F0], keep source ownership under the Chatting source cluster, not real `FolderTreePane`. Use the following role names for packet type 10 subtypes:

| subtype | recommended role name | evidence strength | basis |
| --- | --- | --- | --- |
| `0` | `Whisper` / `ChatType10_Whisper` | medium-strong | current layout uses `g_pConfig+0x28de86/+0x28de87`, the third persisted chat-color pair; bracket rewrite with quote marker; no use of first Talk pair in this handler |
| `4` | `Shout` / `ChatType10_Shout` | strong | current layout uses `+0x28de84/+0x28de85`, the second persisted pair; local UI category order places Shout after Talk |
| `5` | `System` / `ChatType10_System` | medium-strong | current layout uses `+0x28de8c/+0x28de8d`, the sixth persisted pair; no social-channel bracket rewrite |
| `11` | `Group` / `ChatType10_Group` | medium-strong | current layout uses `+0x28de88/+0x28de89`, the fourth persisted pair; bracket rewrite with `]` marker |
| `12` | `Clan` / `ChatType10_Clan` | medium-strong | current layout uses `+0x28de8a/+0x28de8b`, the fifth persisted pair; bracket rewrite with `>` marker |
| `17` | `SystemNotice` / `ChatType10_SystemNotice` | medium | current layout shares the sixth System pair with subtype `5`; old layout has a distinct fixed-color case, so keep a separate enum constant instead of merging with `5` |
| `18` | `CustomColor` / `ChatType10_CustomColor` | strong for semantics, medium for exact name | current-layout-only case; reads two extra dwords at `packet+2` and `packet+6`; text starts at `packet+10`; forwards palette ids `253/254` plus the two extra values |

For `g_pConfig + 0x28de82..0x28de8d`, recommend a role-based `RegistryConfig` chat-color block, not exact field names. The most defensible declaration shape is an indexed pair block such as `chatColorPairs[ChatColorCategory_Count][2]`, with categories `Talk, Shout, Whisper, Group, Clan, System`. The even offset is the first color/palette argument passed to `AddChattingMessage`; the odd offset is the second color/style/background argument. Exact original field names like `talkTextColor` or `whisperBackgroundColor` are not proven by the available `RegistryConfig` docs or IDA evidence.

No direct IDA rename was applied. No target docs, support docs, or coverage report files were edited by this B report.

## Evidence Checked

Required assignment docs were read:

- `tools/leaser/Agents/Agent-B001/goal.md`
- `tools/leaser/Agents/Agent-B001/notes.md`
- `tools/leaser/Agents/Agent-B001/inference_research.md`
- `by-structure.md`
- `tools/leaser/Agents/Supervisor_notes.md` rows for `0002EX/0002F0/0002F8/0002FE`
- `tools/leaser/Agents/Agent-A001/notes.md` section `A001-goal2-chatting-compute-packet-memory-20260615-18` and continuation

Wave2 commands run from `E:\NTK\GhidraBridge\source-2\core\wave2`:

- `python wave2.py method 0x0047fc70`
- `python wave2.py decomp 0x0047fc70`
- `python wave2.py xrefs 0x0047fc70`
- `python wave2.py struct ChattingPane`
- `python wave2.py filter --class ChattingPane --all-methods`
- `python wave2.py method 0x0047ff80`
- `python wave2.py decomp 0x0047ff80`
- `python wave2.py xrefs 0x0047ff80`
- `python wave2.py struct FolderTreePane`
- `python wave2.py filter --class FolderTreePane --all-methods`
- `python wave2.py filter --class ColorStringChattingMessage --all-methods`
- `python wave2.py filter --class ChattingColorPane --all-methods`
- `python wave2.py method 0x0047f280`
- `python wave2.py method 0x0047f370`

Live IDA MCP was available after opening a fresh headless IDB session for `NexusTK.exe`. Checked:

- `analyze_function 0x0047fc70`
- `analyze_function 0x0047ff80`
- `xrefs_to 0x0067a7c8`
- `xrefs_to 0x0066da97`
- `xrefs_to 0x0047f280`
- `xrefs_to 0x0047ff80`
- scoped `search_text` for `dword_67A7C8` in `0x0047ff80-0x00480640`
- scoped `search_text` for `28DE` in `0x0047ff80-0x00480640`
- scoped `search_text` for `28DE8` in `0x004824e0-0x00482c40`
- `lookup_funcs` for `0x0047fc70`, `0x0047ff80`, `0x0047f280`, `0x0047f370`, `0x0047f890`, `0x0047fd70`, `0x00483630`, and `0x004836a0`

Local docs searched/read included:

- `by-file/Chatting.md`
- `by-class/ChattingPane.md`
- `by-class/ChattingColorPane.md`
- `by-class/ColorStringChattingMessage.md`
- `by-file/RegistryConfig.md`
- `by-class/RegistryConfig.md`
- `by-type/by-struct/RegistryConfigUserProfileBlock.md`
- `by-memory/0x0047f0b0-0x0047f26b.ChattingPaneConstructor.md`
- `by-memory/0x0047fcb0-0x0047ff69.ChattingPaneOnPaint.md`
- `by-memory/0x0047f280-0x0047f363.FolderTreePaneAddChattingMessage.md`
- `by-memory/0x0047f370-0x0047f468.FolderTreePaneAddIncomingMessage.md`
- `by-memory/0x0047f890-0x0047f8d3.ChattingPaneChatPacketRouter.md`
- `by-memory/0x0047fd70-0x0047ff69.ChatPacketType13Handler.md`
- `by-memory/0x004824e0-0x004828b9.ChattingColorPaneConstructor.md`
- `by-memory/0x00482b20-0x00482c56.ChattingColorPaneOnButtonResponse.md`
- `by-memory/0x00483630-0x00483699.ColorStringChattingMessageMeasureLines.md`
- `by-memory/0x004836a0-0x00483919.ColorStringChattingMessageDrawWithTables.md`
- `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
- `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md`
- `by-item/FolderTreePaneOwnerPollution_47f280_58a8e0.md`
- `by-meta/client_containers.md`
- `by-file/List.md`

## Facts

### [UID:0002EX] `this+0x130`

- Wave2 `method 0x0047fc70` names the function `ChattingPane::GetLineCount()` and models `this->m_chatLineList` as a `ChatEntryList *`. This is useful behavioral evidence, but it is a generated name, not a recovered original symbol.
- Wave2 `struct ChattingPane` only proves a dword field at offset `0x130` (`mbr_0x130`) after the `ScrollablePane` base and adjacent dword fields at `0x124`, `0x128`, `0x12c`, and `0x134`. It does not prove a source member name.
- Live IDA `analyze_function 0x0047fc70` agrees with the docs: the function reads `this[76]`, uses count at `list+0x0c`, fetches entries through list vtable slot `+0x10`, calls each entry's measure virtual through slot `+0x10`, and selects width `783` or `408` from `g_useEpfAssets`.
- The constructor page proves `this+0x130` is assigned a heap allocation of `0x14` bytes initialized by `List::List` at `0x004f3060` with element size `4` and capacity/count limit `1000`: `sub_4F3060(list, 4, 1000)`.
- `ChattingPaneOnPaint` iterates the same list, fetches entries through list vtable slot `+0x10`, measures with the message virtual slot `+0x10`, draws with message virtual slot `+0x14`, and advances display rows by `13 * measuredRows`.
- `FolderTreePaneAddIncomingMessage` uses the same `this+0x130` list, inserts through list vtable slot `+0x18`, trims above `1000`, fetches oldest entry through slot `+0x10`, and removes through slot `+0x1c`.
- `FolderTreePaneAddChattingMessage` constructs a `ColorStringChattingMessage`, then forwards it to the incoming-message helper. Local docs identify the message render object as `ColorStringChattingMessage`.
- `by-meta/client_containers.md` and `by-file/List.md` identify `List` as the shared fixed-width dynamic array container. `List::List` at `0x004f3060` is the broad utility constructor used by many systems.

### [UID:0002F0] packet type 10 handler

- Wave2 `method 0x0047ff80` names the function `FolderTreePane::HandleChatPacketType10(const std::uint8_t *packetData)`, but local owner-pollution docs reject the real `FolderTreePane` class as source owner for `0x0047f280-0x00480640`.
- Live IDA `analyze_function 0x0047ff80` confirms exact function size `0x656`, single router xref at `0x0047f8c4`, subtype byte at `packet+1`, multibyte-to-wide conversion, bracket rewrites for social-channel cases, and final `AddChattingMessage` call at `0x004805b7`.
- IDA switch comments confirm current-layout cases `0`, `4`, `5`, `11`, `12`, `17`, and `18`. Old-layout handling covers the same family except subtype `18` is current-layout-only.
- Subtype `18` reads two dwords through `sub_5754C0(packet+2)` and `sub_5754C0(packet+6)`, starts text at `packet+10`, and forwards palette ids `253` and `254` plus those two extra values to `AddChattingMessage`.
- IDA `search_text` in `0x0047ff80-0x00480640` confirms `g_pConfig` reads at the packet-handler color cases, not `g_pMetaMan`.
- IDA `search_text` for `28DE` in the handler confirms the exact packet-handler color offsets:
  - `+0x28de84/+0x28de85` for subtype `4`
  - `+0x28de86/+0x28de87` for subtype `0`
  - `+0x28de88/+0x28de89` for subtype `11`
  - `+0x28de8a/+0x28de8b` for subtype `12`
  - `+0x28de8c/+0x28de8d` for subtypes `5` and `17`
- `ChattingColorPaneConstructor` reads all twelve bytes `g_pConfig+0x28de82..0x28de8d`, and `ChattingColorPaneOnButtonResponse` writes the same twelve bytes back on commit.
- `ChattingColorPane` docs identify the six UI categories as `Talk`, `Shout`, `Whisper`, `Group`, `Clan`, and `System`.
- `RegistryConfig` docs prove the global config/registry ownership context, but they do not provide exact source field names for this twelve-byte chat-color block.

## Inference

### [UID:0002EX] declaration/name structure

Best declaration model:

```cpp
List *m_pChatMessageList; // element size 4; entries are ColorStringChattingMessage*
```

If the final source model wraps the generic list in a typedef or thin type, the defensible type alias is:

```cpp
using ChatMessageList = List; // or List<ColorStringChattingMessage*> if templates are used in rebuilt source
```

Do not use `ChatEntryList` as a final original-source type unless a later source clue proves that alias. The allocation and utility docs point to the shared `List` implementation, and `sub_4F3060(list, 4, 1000)` is exactly the generic fixed-width list constructor pattern.

Do not treat `m_chatLineList` as final original spelling. It is a reasonable Wave2 role alias for a line-count method, but all producers and consumers show message render entries. `m_pChatMessageList` is the better role name because the object is also used for painting, insertion, scrolling, and trimming, not only line counting.

Accept `ColorStringChattingMessage` as the concrete entry class evidence. The list stores 4-byte pointers, and every observed in-module producer constructs or clones `ColorStringChattingMessage`-compatible objects before insertion. To stay conservative in final C++, phrase this as `ColorStringChattingMessage *` or `ColorStringChattingMessage`-compatible message object if virtual subclassing later appears.

### [UID:0002F0] subtype and color semantics

The persisted chat-color block is best modeled as:

| config offsets | category role | packet type 10 usage |
| --- | --- | --- |
| `+0x28de82/+0x28de83` | Talk color pair | not used by this handler |
| `+0x28de84/+0x28de85` | Shout color pair | subtype `4` |
| `+0x28de86/+0x28de87` | Whisper color pair | subtype `0` |
| `+0x28de88/+0x28de89` | Group color pair | subtype `11` |
| `+0x28de8a/+0x28de8b` | Clan color pair | subtype `12` |
| `+0x28de8c/+0x28de8d` | System color pair | subtypes `5` and `17` |

This mapping is stronger than pure subtype-name guessing because it is anchored by the persisted `ChattingColorPane` category order and by the packet handler's direct color-byte reads. The first Talk pair being unused in type 10 is not a contradiction; it suggests type 10 handles remote/social/system display cases while normal Talk color is consumed elsewhere.

The pair element names should remain generic until `RegistryConfig` load/save field order and registry key text are fully mapped. Recommended placeholders:

- `chatColorPairs[ChatColor_Talk][0]` and `[1]`
- `chatColorPairs[ChatColor_Shout][0]` and `[1]`
- `chatColorPairs[ChatColor_Whisper][0]` and `[1]`
- `chatColorPairs[ChatColor_Group][0]` and `[1]`
- `chatColorPairs[ChatColor_Clan][0]` and `[1]`
- `chatColorPairs[ChatColor_System][0]` and `[1]`

If individual fields are required for generated C++, use role placeholders such as `m_chatWhisperColor0` and `m_chatWhisperColor1`, not claimed original names like `m_whisperTextColor`.

## Ranked Outcomes

### [UID:0002EX]

1. Best outcome: `ChattingPane` owns a heap `List *` member at `+0x130`, named role-wise `m_pChatMessageList`, with `ColorStringChattingMessage *` entries. This fits constructor, paint, line count, add/trim, `List` utility docs, and local message-class docs.
2. Acceptable but narrower: keep Wave2 `m_chatLineList` as a temporary alias in generated code comments only. It describes one consumer but misdescribes the stored objects.
3. Rejected: final source type `ChatEntryList` / entry type `ChatEntry`. These are Wave2 local reconstruction structs; the repository already has `List` and `ColorStringChattingMessage` evidence.
4. Rejected: real `FolderTreePane` list/member ownership. The chat helper cluster is documented owner pollution and the real filesystem `FolderTreePane` class lives elsewhere.

### [UID:0002F0]

1. Best outcome: `Chatting.cpp` or an adjacent Chatting source helper owns the packet type 10 handler, with role-based enum constants for `Whisper`, `Shout`, `System`, `Group`, `Clan`, `SystemNotice`, and `CustomColor`.
2. Acceptable source-structure variant: the handler remains documented as a file/static helper routed from `ChattingPane` rather than a `Chatting` instance method. The single caller is the chat packet router, and the body does not prove a class `this` pointer.
3. Rejected: real `FolderTreePane::HandleChatPacketType10`. Wave2's class label is generated owner pollution; local owner-pollution docs and address-neighborhood evidence place it in Chatting.
4. Rejected: `g_pMetaMan` as color/config root. Live IDA and local docs prove `dword_67A7C8` is `g_pConfig` and that these bytes are persisted by `ChattingColorPane`.
5. Rejected for now: exact `RegistryConfig` field names. The category/order semantics are strong, but exact source spelling is not available in the checked docs or IDA decompilation.

## Concrete Supervisor Actions

Recommended target doc wording updates:

- In [UID:0002EX], replace the remaining source-quality blocker wording with: `B001 2026-06-15 source-quality recommendation: this+0x130 is a heap project List object initialized as List(4, 1000), storing ColorStringChattingMessage* entries. Use role name m_pChatMessageList/m_chatMessageList in reconstructed source. Treat Wave2 m_chatLineList as a historical alias and ChatEntryList/ChatEntry as generated helper names, not proven original declarations.`
- In [UID:0002F0], add the subtype table from this report to the reconstruction notes and state that `RegistryConfig` chat-color bytes are role-based placeholders until registry field names are proven.
- In [UID:0002F0], replace any remaining `g_pMetaMan` or meta-manager wording for these color reads with `g_pConfig`.

Score changes:

- No immediate score change is recommended for either target. Keep [UID:0002EX] at `87/90` and [UID:0002F0] at `87/90` unless the supervisor wants to reward the narrowed source-quality wording with a small completion-only bump. Confidence should not rise from this report because exact original spellings remain unproven.

IDA/Wave2 rename recommendations:

- Do not apply a hard IDA/Wave2 field rename for `ChattingPane::mbr_0x130` as an exact original symbol. If role-based names are allowed in the working database, `m_pChatMessageList` is the recommended field name.
- Correct Wave2/support prose for `0x0047ff80` away from `g_pMetaMan` and toward `g_pConfig` / `ReadChatConfigColorByte`.
- Keep method owner recommendations at the documentation level: `HandleChatPacketType10` belongs to the Chatting source cluster, not real `FolderTreePane`.

Support doc update recommendations:

- `by-class/ChattingColorPane.md` can cross-reference the packet type 10 usage map for `+0x28de84..+0x28de8d`.
- `by-class/RegistryConfig.md` or `by-type/by-struct/RegistryConfigUserProfileBlock.md` can add a role-only chat-color block table for `+0x28de82..+0x28de8d`; do not introduce exact field names yet.
- A future enum/support page such as `ChatPacketType10Subtype` would be useful, but this B report does not require it.

Coverage report:

- No `by-memory/-coverage-report.md` change is recommended. No row text is supplied because the shared coverage rows already reflect the unresolved source-quality caveat, and this report should be incorporated through target doc wording first.

## Residual Risk

- The subtype role names are inferred from color-category order and bracket rewrite conventions, not from a packet enum symbol table. The confidence is good enough for role names and target-doc wording, but not for claiming original enum spellings.
- The `RegistryConfig` block could have been represented in original source as an array keyed by registry `Color%d` indices rather than named fields. That is why exact individual field names should remain placeholders.
- `ColorStringChattingMessage *` is the strongest observed entry type for the chat message list, but the virtual interface leaves room for future subclasses. Final source should avoid making ownership/lifetime claims beyond the observed clone/insert/delete pattern.

## Changed Files

- Created `tools/leaser/Agents/Agent-B001/research/0002EX-0002F0-chatting-source-quality-20260615.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002EX-0002F0-chatting-source-quality-20260615.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002EX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
