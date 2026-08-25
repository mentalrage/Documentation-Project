** TARGET-REPORT-UID:0003JP **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003JP **
# 0003JP SharedChevronPromptString Ownership / Split Research

## Finalized Report / Current Recommendation
- Current recommendation: Assign [UID:0003JP][0x00630a14-0x00630a18.SharedChevronPromptString](by-memory/0x00630a14-0x00630a18.SharedChevronPromptString.md) to [UID:00001Q][ChatInputPane](by-class/ChatInputPane.md) by setting `AUTOGEN_PARENT_UID:00001Q`.
- Final disposition: Keep the exact four-byte string child reconstructable, unsplit, and C++ blank; it is a class-owned `ChatInputPane` prompt literal, not a parentless cross-owner pooled literal.
- Required action: Supervisor/A-agent should update the target page and affected split-container/coverage text listed in `Final Recommendation`. Do not create a new shared prompt owner/source file.
- Confidence: High for direct `ChatInputPane` ownership, because live IDA MCP shows all three literal xrefs are ChatInputPane construction/open paths.

## Supporting Research

## Target
- Target UID: `0003JP`.
- Target path: `by-memory/0x00630a14-0x00630a18.SharedChevronPromptString.md`.
- Source queue/report row: `auto-generated/-ag-memory-coverage.md`, row currently `unassigned`.
- Current supervisor classification: `reviewed-85-but-ownership-unknown-under-review`, assignment `B003-0003JP`.
- Current scores and parent state: `COMPLETION:86`, `CONFIDENCE:92`, `RECONSTRUCTABLE:TRUE`, blank `AUTOGEN_PARENT_UID`.

## Executive Recommendation
- Best direct owner: [UID:00001Q][ChatInputPane](by-class/ChatInputPane.md).
- Downstream source file: [UID:0000I5][Chatting](by-file/Chatting.md), or a future `social/ChatInputPane.cpp` split if that file is later created. The direct parent should still be the class, not a by-file fallback.
- Split/container disposition: no split is needed. The target is already the exact half-open `0x00630a14-0x00630a18` UTF-16 string literal, between the quit yes/no child and the direct-whisper prompt child.
- Assignment condition: the child and parent both clear the strict gate. `0003JP` is `86/92`; `ChatInputPane` is `85/86`; `Chatting` is `85/88`.

## Supervisor Active Recheck
- Supervisor assigned `0003JP` to Agent-B003 on 2026-06-13 to research whether the shared `>` literal has a defensible owner, should create a new shared prompt owner, or should remain parentless.
- The assigned item did not require split repair. It is already a precise four-byte string child.
- Every source-bearing child in the immediate split scope has an evidence-backed owner or prior routing. This report only changes the conclusion for the chevron child.

## Inference Research Guidance Check
- `by-structure.md` requires the narrowest direct semantic parent. For a class-owned literal, that parent is the class page when it clears the assignment gate.
- `inference_research.md` warns that physical adjacency and consumer xrefs alone do not prove source ownership. I treated the old `UserPane`/`ChatInputPane` wording as a lead and rechecked the actual xref-site semantics in IDA.
- Existing documentation assumption revised: the `UserPane` xref is real, but it is not a separate UserPane prompt use. It is an inline `ChatInputPane` allocation/open branch inside `UserPane::OnKeyEvent`.

## Evidence Standards Used
- IDA MCP session: `a001_goal2_0002UM`, database `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, checked 2026-06-13.
- IDA evidence types: server health, bytes, string read, range signature, xrefs, data-flow trace, function lookup, instruction query, decompilation, callee list, vtable/data xrefs, vtable value reads.
- Documentation evidence types: target page, physical split containers [UID:0003J3], [UID:0002YV], [UID:00026X], adjacent prompt child pages, `UserPane`, `Chatting`, `SayInputPanes`, `ChatInputPane`, `g_pChatInputPane`, and `proposed-source-tree.md`.
- Strength: high. The same prompt, global publish, three `ChatInputPane` vtable stores, and history sentinel appear at every relevant construction site.

## IDA MCP Facts
- Function/range facts:
  - `lookup_funcs` reports `0x005a5d37` inside `sub_5A5BD0` (`0x1852` bytes), `0x005a962a` inside `sub_5A95E0` (`0xa7` bytes), and `0x005b38e7` as not inside an IDA-recognized function.
  - `lookup_funcs` reports `0x005b3940` as `sub_5B3940` (`0x100` bytes), matching the `ChatInputPane` key/history handler.
- Data/table/padding facts:
  - `get_bytes 0x00630a14 size 4` returns `3e 00 00 00`.
  - `get_string 0x00630a14` returns `>`.
  - `make_signature_for_range 0x00630a14-0x00630a18` returns `3E 00 00 00`, unique `false`; this is expected for a four-byte pattern and is not ownership evidence.
- Xref facts:
  - `xrefs_to 0x00630a14` reports exactly three xrefs: `0x005a5d37`, `0x005a962a`, and `0x005b38e7`.
  - `trace_data_flow backward 0x00630a14` reports `asc_630A14` as UTF-16LE `">",0` and the same three `push offset asc_630A14` sites.
- Vtable/global/type facts:
  - `xrefs_to 0x0069bf68` ties `g_pChatInputPane` storage to `sub_5A5BD0`, `sub_5A95E0`, raw constructor write `0x005b3908`, and destructor clear `0x005b7986`.
  - `xrefs_to 0x0062fbe8`, `0x0062fc38`, and `0x0062fc68` ties all three `ChatInputPane` vtable bases to stores in `sub_5A5BD0`, `sub_5A95E0`, and the raw constructor.
  - `get_global_value` confirms key slots: `0x0062fc30 -> 0x005b3a40`, `0x0062fc40 -> 0x005b3940`, `0x0062fbe8 -> 0x005b7980`.
- Negative IDA facts:
  - `xrefs_to 0x00630a14` finds no direct references from the `SayInputPanes` direct-message/group/clan constructors except the ChatInputPane-related construction sites listed above.
  - `xrefs_to 0x005a95e0` reports no direct code callers, so it looks like an alternate/open helper body or retained construction helper, not an independently called shared prompt function.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00630a14-0x00630a18` | [UID:0003JP][0x00630a14-0x00630a18.SharedChevronPromptString](by-memory/0x00630a14-0x00630a18.SharedChevronPromptString.md) | UTF-16 `>` prompt literal for ChatInputPane construction | Yes | Recommend [UID:00001Q][ChatInputPane](by-class/ChatInputPane.md) | `86/92` | Assign |
| `0x005b38e0-0x005b3935` | [UID:0002S9][0x005b38e0-0x005b3935.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3935.ChatInputPaneRawConstructor.md) | Raw ChatInputPane constructor, one prompt xref | Yes | [UID:00001Q] | `86/89` | Existing supporting evidence |
| `0x005a95e0-0x005a9687` | no exact page found | Alternate ChatInputPane open/construction helper | Yes, likely | Existing docs route family through ChatInputPane/Chatting | IDA function `sub_5A95E0` | Supporting evidence |
| `0x005a5bd0-0x005a7422` | [UID:0001KL][0x005a2530-0x005b8395.UserPane](by-memory/0x005a2530-0x005b8395.UserPane.md) | UserPane key handler containing inline ChatInputPane open branch | Yes | UserPane for handler, not for this literal | aggregate | Consumer context only |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005a5d37` | `push offset asc_630A14` inside `sub_5A5BD0` | Inline ChatInputPane construction branch in `UserPane::OnKeyEvent`; surrounding instructions check `g_pChatInputPane`, allocate `0x10c`, call `sub_4F2C90`, publish the singleton, install ChatInputPane vtables, and set the `0x108` sentinel. |
| `0x005a962a` | `push offset asc_630A14` inside `sub_5A95E0` | Small equivalent ChatInputPane open helper. Decompilation shows `sub_4F2C90(L">")`, `unk_69BF68` publish/clear, three ChatInputPane vtable stores, and `*(v0+264) = -1`. |
| `0x005b38e7` | `push offset asc_630A14`, no IDA function | Raw ChatInputPane constructor-shaped body; same prompt/base-constructor/global/vtable/sentinel sequence. |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion:
  - [UID:0002S9] records the raw constructor using `">"`, publishing `g_pChatInputPane`, and storing three `ChatInputPane` vtables.
  - [UID:00001Q] identifies `ChatInputPane` as the direct parent for the raw constructor and routes the class through [UID:0000I5][Chatting](by-file/Chatting.md).
  - [UID:000308] and [UID:000309] document `g_pChatInputPane` as Chatting/ChatInputPane-owned storage with the same open/create and destructor lifecycle.
  - `by-project-structure/proposed-source-tree.md` keeps `Chatting.cpp` and `SayInputPanes.cpp` separate and says `ChatInputPane` remains documented under `social/Chatting.cpp` while final source split remains open.
- Existing docs that are stale, incomplete, or contradicted:
  - [UID:0003JP], [UID:0003J3], [UID:0002YV], and [UID:00026X] currently say the chevron remains parentless because it is shared by `UserPane` and `ChatInputPane`. IDA confirms the `UserPane` site is semantically ChatInputPane construction, so that rationale is stale.
  - The physical container name `UserPaneSocialPromptFragments` remains useful as an address index, but it should not drive the direct parent of this exact child.
- Generated/coverage report state:
  - `auto-generated/-ag-memory-coverage.md` currently lists [UID:0003JP] as `unassigned`.
  - `by-memory/-coverage-report.md` currently describes it as parentless because of UserPane and ChatInputPane consumers. That row should be updated after the parent assignment.

## Ranked Ownership Analysis

### 1. [UID:00001Q] ChatInputPane
- Evidence for:
  - Every `0x00630a14` xref is in a ChatInputPane construction/open sequence.
  - The `UserPane` xref is not independent UserPane UI text; it is an inline branch that checks `g_pChatInputPane`, allocates `0x10c`, calls the input base with `">"`, publishes the singleton, installs `ChatInputPane` vtables, and initializes the `0x108` history cursor.
  - The raw constructor uses the same literal and same vtable/global/sentinel sequence.
  - `ChatInputPane` has `85/86`, clears the direct-parent gate, and already attaches to [UID:0000I5][Chatting](by-file/Chatting.md).
- Evidence against:
  - The literal physically sits in a broader `.rdata` run historically named for UserPane/social prompts.
  - The final original file might eventually split as `social/ChatInputPane.cpp` instead of staying in `Chatting.cpp`.
- Decision: Accept. Physical `.rdata` adjacency and future file split uncertainty do not outweigh the exact construction semantics. Assign `AUTOGEN_PARENT_UID:00001Q`.

### 2. [UID:0000I5] Chatting / possible future `social/ChatInputPane.cpp`
- Evidence for:
  - Chatting owns the current `ChatInputPane` class, `g_pChatInputPane`, chat packet sender, history navigation, and chat input source placement.
  - `Chatting.md` explicitly lists `ChatInputPane` or a possible split `social/ChatInputPane.cpp`.
- Evidence against:
  - By-structure requires the narrowest direct semantic parent. The prompt literal belongs to `ChatInputPane`, not directly to a file-level helper.
  - Creating a new by-file solely for this four-byte literal would overreact; the class parent remains valid if a file split happens later.
- Decision: Use as downstream source context only. Do not set `AUTOGEN_PARENT_UID` directly to `0000I5` and do not create a new file for this assignment.

### 3. [UID:0000P1] UserPane
- Evidence for:
  - One xref is inside `sub_5A5BD0`, documented as `UserPane::OnKeyEvent`.
  - The literal is physically inside the broader `UserPaneInputStrings` `.rdata` neighborhood.
- Evidence against:
  - The `0x005a5d37` branch constructs `ChatInputPane`; the following stores are to `g_pChatInputPane` and `ChatInputPane` vtables, not UserPane state.
  - `UserPane.md` already warns to keep chat history and say-input helpers in `SayInputPanes` or `Chatting` unless later evidence proves intentional colocation.
  - Assigning the literal to UserPane would hide the true class-level prompt owner.
- Decision: Reject.

### 4. [UID:0003J3] physical container and parents [UID:0002YV] / [UID:00026X]
- Evidence for:
  - The target is a child of [UID:0003J3], nested under broader `.rdata` containers.
  - Address adjacency is real: it sits between quit yes/no strings and direct-whisper prompt fragments.
- Evidence against:
  - These pages are non-emitting split indexes, not source-level owners.
  - Their own documentation delegates exact children to direct source owners.
  - The correct exact child parent is narrower and clears the gate.
- Decision: Keep containers non-emitting and parentless. Update their child tables/rationales to show [UID:0003JP] is now assigned to [UID:00001Q].

### 5. [UID:0000N9] SayInputPanes or a shared social prompt helper
- Evidence for:
  - Neighboring prompt fragments at `0x00630a18+` and several adjacent say/group/clan prompt strings route to `SayInputPanes`.
  - The current proposed tree acknowledges final split questions between `Chatting`, `SayInputPanes`, and possible `ChatInputPane.cpp`.
- Evidence against:
  - `xrefs_to 0x00630a14` finds no direct-message/group/clan constructor refs; the next child at `0x00630a18` is where direct-whisper prompt ownership begins.
  - No IDA evidence shows a common prompt-string helper or prompt constants table that owns this literal across multiple social input classes.
  - `SayInputPanes.md` explicitly keeps `ChatInputPane` documented under `Chatting`.
- Decision: Reject.

### 6. Parentless pooled-literal retention
- Evidence for:
  - The current docs left it parentless because three xrefs crossed apparent UserPane and ChatInputPane paths.
  - String pooling can make direct source ownership weak when materially unrelated modules share a literal.
- Evidence against:
  - Current IDA evidence collapses the apparent cross-owner split: all refs serve one semantic object, `ChatInputPane`.
  - The parent candidate clears the gate, and assignment would not overclaim ownership of neighboring strings.
- Decision: Reject. Parentless retention is no longer the best defensible inference.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: none recommended.
- Likely full contents if a future split is created outside this assignment: `social/ChatInputPane.cpp` would contain [UID:00001Q][ChatInputPane](by-class/ChatInputPane.md), [UID:0002S8][ChatPacketRawSender](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSender.md), [UID:0002S9][ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3935.ChatInputPaneRawConstructor.md), [UID:0001MC][ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md), [UID:000308][g_pChatInputPane](by-global/g_pChatInputPane.md), [UID:000309][0x0069bf68-0x0069bf6c.g_pChatInputPane](by-memory/0x0069bf68-0x0069bf6c.g_pChatInputPane.md), and [UID:0003JP].
- Candidate related items rejected for this assignment: neighboring [UID:0003JQ], [UID:0003JR], and [UID:0003JS] are social/say/shout prompts with different proven owners.
- Standalone, narrow, or broad source-file inference: no new standalone file should be created now. Existing class ownership is the stable narrow parent.

## Negative Evidence Summary
- The `UserPane` xref is a consumer-location fact, not ownership proof; instruction-level IDA evidence shows ChatInputPane construction.
- Physical adjacency in `0x006309d0-0x00630a78` is weak because the range already contains QuitDialogs, SayInputPanes, UserPane, ChatInputPane, and ShoutInputPane children.
- The four-byte pattern is not unique as a byte signature, so uniqueness/non-uniqueness of `3E 00 00 00` is not a useful source-file signal.
- No current IDA xrefs support a new shared prompt constants owner.
- No split repair is needed because the predecessor and successor child boundaries are exact.

## Final Recommendation
- Exact changes recommended:
  - In `by-memory/0x00630a14-0x00630a18.SharedChevronPromptString.md`, set `AUTOGEN_PARENT_UID:00001Q`.
  - In that same page, replace the current parentless routing paragraph with: the old `UserPane` reference is an inline ChatInputPane construction branch, so the direct semantic owner is [UID:00001Q][ChatInputPane](by-class/ChatInputPane.md); [UID:0000I5][Chatting](by-file/Chatting.md) remains the downstream file owner.
  - Keep `RECONSTRUCTABLE:TRUE`, keep the C++ block blank, and keep scores `86/92` unless a later editor adds the full B003 evidence and chooses a conservative small score refresh.
  - Add [UID:00001Q][ChatInputPane](by-class/ChatInputPane.md) to the target cross-references.
  - In `by-class/ChatInputPane.md`, add [UID:0003JP] as the class-owned prompt literal used by the raw constructor and both open/construction paths.
  - In [UID:0003J3], [UID:0002YV], and [UID:00026X], update child tables/assignment-gate/score-rationale wording that says the chevron remains parentless; it should say the exact chevron child is now routed to [UID:00001Q] while the containers remain non-emitting and parentless.
  - In `by-memory/-coverage-report.md`, update the [UID:0003JP] row to reflect assignment to [UID:00001Q], not parentless shared ownership.
- Exact parent assignment recommended:
  - [UID:0003JP] -> [UID:00001Q][ChatInputPane](by-class/ChatInputPane.md).
- Exact items left unassigned and why:
  - [UID:0003J3], [UID:0002YV], and [UID:00026X] should remain parentless non-emitting containers because each still spans mixed source owners.
- Exact future work outside this assignment:
  - A later source-layout pass may decide whether `ChatInputPane` stays in `Chatting.cpp` or moves to a new `social/ChatInputPane.cpp`; that should not block this class-level parent assignment.

## Follow-Up Actions
- Supervisor actions:
  - Apply the metadata/text changes above or assign an A-agent to apply them.
  - Run validator on changed by-* files. Expected generated-state result: `auto-generated/-ag-memory-coverage.md` should move [UID:0003JP] from `unassigned` to assigned under parent `00001Q`, ultimately routing through [UID:0000I5][Chatting](by-file/Chatting.md).
  - Update `Supervisor_notes.md` after execution; B003 should not edit it directly.
- A-agent actions:
  - Update target and container wording carefully without changing adjacent child ownership.
  - Do not create a shared prompt helper or new source file for this target.
- B003 future research actions:
  - None for `0003JP` after supervisor execution, unless later source-file splitting creates a new `ChatInputPane.cpp` owner and requires a file-level audit.

## Confidence
- Recommendation confidence: High.
- Score confidence: Existing `86/92` remains conservative and valid after assignment.
- Remaining uncertainty: final original source-file split between `social/Chatting.cpp` and possible `social/ChatInputPane.cpp`; this does not affect the direct class parent.

## Validator Results
- Commands run: none. This assignment instructed B003 not to directly edit by-* docs or coverage reports; only this research report was created.
- Results: not applicable.
- Any unresolved validator warnings/errors: not applicable.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B003/research/0003JP-SharedChevronPromptString.md`.
- Modified: none outside the B003 research folder.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003JP","source_path":"executed-b-agent-research/B003/0003JP-SharedChevronPromptString.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
