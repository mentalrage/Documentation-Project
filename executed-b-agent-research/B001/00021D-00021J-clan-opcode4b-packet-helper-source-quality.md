** TARGET-REPORT-UID:00021D **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001 00021D-00021J Clan Opcode 0x4b Packet Helper Source Quality Report

Assignment: `B001-goal2-clan-opcode4b-packet-helper-source-quality-00021D-00021E-00021F-00021H-00021I-00021J-20260616`

Report-only output. No by-memory pages, generated reports, source files, IDA database state, or shared coverage files were edited by this pass.

## Evidence Checked

- Workflow and assignment files: `Supervisor.md`, `Supervisor_notes.md`, `SupervisorAssignments.md`, `Agent-B001/goal.md`, `Agent-B001/notes.md`, `by-structure.md`, and `Agent-B001/inference_research.md`.
- Target pages: [UID:00021D] through [UID:00021J].
- Context pages: `Clan`, `ClanBank`, `ClanStatusPane`, `ClanStatusPaneFrameAndInput`, `ClanStatusPaneRows`, `ClanStatusRowActionPacket`, `ClanStatusPacketDispatcher`, `ClanAttributePacketParser`, `ClanStatusPacketDialogHandlers`, `ClanJoinListPane`, `ClanEnlistListPane`, `ClanDepMoneyInputDialog`, `ClanDepItemDialog`, `SendClanJoinListSelectionPacket`, `SendClanLeaveResponse`, `ClanSubtype6PacketHelpers`, `ClanNameActionPacketHelpers`, `ClanWithdrawAndNoticePacketHelpers`, `SendClanAttributePacket`, `PacketBufferHelpers`, `QueueAndSendPacket`, `g_packetSender`, `by-memory/-ignored.md`, and `by-memory/-coverage-report.md`.
- Live IDA/MCP session: `b001_00021D_00021J_clan_20260616`, opened against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` / `NexusTK.exe.i64`.
- IDA/MCP checks:
  - `lookup_funcs` for all target starts, internal action starts, and modeled adjacent helpers.
  - `xref_query` to all raw target starts and to modeled siblings.
  - `insn_query` linear disassembly for every raw body.
  - `decompile` for `0x00487600`, `0x00485590`, `0x00485700`, `0x00487d70`, `0x00487e20`, `0x00488fe0`, `0x0048a6b0`, `0x0048a790`, `0x004877d0`, and `0x004879e0`.
- Local PE check against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:
  - exact little-endian VA and RVA pointer scans for starts `0x00485440`, `0x004854b0`, `0x00485520`, `0x00485690`, `0x00485780`, `0x004857f0`, `0x00485870`, and `0x004858e0`;
  - section-mapped `.text` direct `E8`/`E9`/`0F 8x` rel32 target scans to exact starts and to the full raw ranges.

## Summary Decisions

| UID | Current label | Recommended label | Source-facing helper signatures | Classification | Owner/source | Score |
| --- | --- | --- | --- | --- | --- | --- |
| `00021D` | `SendClanOpcode4BSubtype0Request` | `SendClanStatusRefreshRequestPacket` | `static void SendClanStatusRefreshRequestPacket();` | source-authored retained/no-route packet helper, not compiler artifact | keep [UID:0000I8] `Clan`, `social/Clan.cpp` | `85/89` |
| `00021E` | `SendClanOpcode4BSubtype1Request` | `SendClanEnlistRequestRefreshPacket` | `static void SendClanEnlistRequestRefreshPacket();` | retained duplicate of row-action subtype 1 action 0 request | keep [UID:0000I8] `Clan`, `social/Clan.cpp` | `85/90` |
| `00021F` | `SendClanJoinListRefreshPacket` | keep `SendClanJoinListRefreshPacket` | `static void SendClanJoinListRefreshPacket();` | retained duplicate of row-action subtype 2 action 0 request; paired with live action 1 selection sender | keep [UID:0000I8] `Clan`, `social/Clan.cpp` | `85/90` |
| `00021H` | `SendClanLeaveRequestPacket` | keep `SendClanLeaveRequestPacket` | `static void SendClanLeaveRequestPacket();` | retained duplicate of row-action subtype 3 action 0 request; paired with live action 1 leave response | keep [UID:0000I8] `Clan`, `social/Clan.cpp` | `85/90` |
| `00021I` | `ClanDepositMoneyPacketHelpers` | `ClanDepositMoneyRequestAndSubmitPacketHelpers` | `static void SendClanDepositMoneyDialogRequestPacket();` and `static void SendClanDepositMoneySubmitPacket(uint32_t amount);` | retained duplicate/helper pair; action 0 mirrors row action, action 1 mirrors live dialog submitter | keep [UID:0000I8] `Clan`, `social/Clan.cpp` | `85/89` |
| `00021J` | `ClanDepositItemPacketHelpers` | `ClanDepositItemRequestAndSubmitPacketHelpers` | `static void SendClanDepositItemDialogRequestPacket();` and `static void SendClanDepositItemSubmitPacket(uint8_t selectedSlotIndex, uint16_t amount);` | retained duplicate/helper pair; action 0 mirrors row action, action 1 mirrors live `ClanDepItemDialog` sender | keep [UID:0000I8] `Clan`, `social/Clan.cpp` for this raw strip; do not move to `ClanBank.cpp` | `85/89` |

All final C++ blocks should remain blank. These helpers now clear a defensible `85/85+` documentation bar because behavior, layout, source family, negative reachability, and semantic naming have been rechecked, but none clears the final-source/code-emission bar due the unresolved original declarations and no-route raw starts.

## Raw Liveness Reanalysis

IDA/MCP `lookup_funcs` reports no function object for:

- `0x00485440`, `0x004854b0`, `0x00485520`, `0x00485690`,
- `0x00485780`, `0x004857f0`,
- `0x00485870`, `0x004858e0`.

IDA/MCP `xref_query direction=to xref_type=any` reports zero code/data xrefs to each raw entry above. This was compared against adjacent modeled helpers:

- `0x00485590` has two code refs from `ClanJoinListPane` paths at `0x004888ea` and `0x00488951`.
- `0x00485700` has two code refs from leave confirm/cancel callbacks at `0x0048a0a8` and `0x0048a0b8`.
- `0x00485960` has two code refs, one from row action `0x00487600` and one from `ClanEnlistListPane` input handling.
- `0x00487600` has the expected `ClanStatusPane::OnMouseEvent` code ref at `0x00484e91`.
- `0x00488fe0` and `0x0048a790` are vtable-backed data refs only, not raw helper callers.

The local PE check found zero exact VA and zero exact RVA pointer hits to all eight raw starts. It also found zero direct rel32 branch targets to exact starts and zero direct rel32 branch targets to any address inside the full target ranges. A broad byte-sequence scan for any dword value inside the ranges produces unrelated byte-pattern hits in code/data and should not be used as pointer evidence; the meaningful entry-point pointer/branch scans are zero.

Conclusion: these addresses are not hidden live direct-call helpers in the current binary. Their packet bodies are source-shaped, contiguous with the Clan opcode `0x4b` helper strip, and not compiler-generated switch tables or alignment, so the best classification is retained/dead source-authored packet helper evidence or duplicate adapter evidence, not active reachable functions.

## Packet Body Validation

IDA/MCP `insn_query` linear disassembly validates exact packet fields:

- `00021D` `0x00485440-0x004854a5`: writes byte `0x4b`, byte `0`, word `0` through `sub_5753A0`, sends length `4`.
- `00021E` `0x004854b0-0x00485518`: writes byte `0x4b`, byte `1`, byte `0`, sends length `3`.
- `00021F` `0x00485520-0x00485588`: writes byte `0x4b`, byte `2`, byte `0`, sends length `3`.
- `00021H` `0x00485690-0x004856f8`: writes byte `0x4b`, byte `3`, byte `0`, sends length `3`.
- `00021I`:
  - `0x00485780-0x004857e8`: writes `{0x4b, 4, 0}`, sends length `3`.
  - `0x004857f0-0x00485864`: writes `{0x4b, 4, 1}`, appends a big-endian 32-bit amount via `sub_5753F0`, sends length `7`, `retn 4`.
- `00021J`:
  - `0x00485870-0x004858d8`: writes `{0x4b, 5, 0}`, sends length `3`.
  - `0x004858e0-0x00485952`: writes `{0x4b, 5, 1}`, appends one selected-slot byte and a big-endian 16-bit amount via `sub_5753A0`, sends length `6`, `retn 8`.

All bodies use the shared byte/word/dword packet writers documented in `PacketBufferHelpers` and the shared send funnel documented in `QueueAndSendPacket` / `g_packetSender`.

## Semantic Naming Rationale

`ClanStatusRowActionPacket` at `0x00487600` is the strongest semantic anchor for subtype/action `0` helpers. Its current decompilation maps clicked row numbers to opcode `0x4b` action requests:

- row `2` sends subtype `1`, action `0`;
- row `3` sends subtype `2`, action `0`;
- row `4` sends subtype `3`, action `0`;
- row `5` sends subtype `4`, action `0`;
- row `6` sends subtype `5`, action `0`;
- row `7` calls subtype `6` action `0` helper `0x00485960`;
- rows `8-13` send subtypes `7-12`, action `0`.

Inbound opcode `0x43` dispatcher and handler evidence gives the names:

- subtype `0`: `ClanStatusPane` attribute/status parser at `0x004842b0`; outbound 00021D is best named as a status refresh/request helper. I recommend `SendClanStatusRefreshRequestPacket` rather than `SendClanAttributeRequestPacket` because `SendClanAttributePacket` already names the separate subtype `6` action `2` update helper and would create source-facing ambiguity.
- subtype `1`: `0x004877d0` decodes a clan name and request text and switches the status pane to the enlist/request view. I recommend `SendClanEnlistRequestRefreshPacket`. Rejected alternatives: `SendClanOpcode4BSubtype1Request` is too generic; `SendClanEnlistDialogOpenPacket` overstates the evidence because the handler updates status-pane text rather than opening a modal.
- subtype `2`: `0x004879e0` decodes the join-list packet, and the adjacent live action `1` sender `0x00485590` submits selected join-list text. Current `SendClanJoinListRefreshPacket` is source-facing enough and should remain.
- subtype `3`: dispatcher case `3` opens the leave confirm dialog, and live action `1` helper `0x00485700` sends accept/cancel. Current `SendClanLeaveRequestPacket` is source-facing enough and should remain.
- subtype `4`: dispatcher/opener `0x00487d70` handles deposit-money packet action `0` by constructing `ClanDepMoneyInputDialog`; live `ClanDepMoneyInputDialog_SubmitDepositMoney` sends action `1` amount. Recommended helper names are `SendClanDepositMoneyDialogRequestPacket` and `SendClanDepositMoneySubmitPacket(uint32_t amount)`.
- subtype `5`: dispatcher/opener `0x00487e20` constructs `ClanDepItemDialog`; live `0x0048a6b0` reads `MyItemListPane_GetSelectedSlotIndex`, parses the amount, and virtual-dispatches to `0x0048a790`, which sends subtype `5` action `1`. Recommended helper names are `SendClanDepositItemDialogRequestPacket` and `SendClanDepositItemSubmitPacket(uint8_t selectedSlotIndex, uint16_t amount)`.

## Source Placement And Ownership

Keep all six targets under [UID:0000I8] `Clan`, source route `NexusTK/social/Clan.cpp`.

Reasons:

- The raw helpers form one contiguous opcode `0x4b` helper strip after the `ClanStatusPacketDispatcher` switch table and before the row/view/list/dialog Clan code.
- The strip continues through subtype `6` helpers, `SendClanAttributePacket`, subtype `7-10` name-action helpers, and subtype `11-13` withdraw/notice helpers already assigned to `Clan`.
- `ClanStatusPane` and row actions prove the subtype/action semantics, but these raw starts are not class-method starts and have no direct row-action calls.
- `00021J` should not be moved to `ClanBank.cpp` even though the active `ClanDepItemDialog::SendDepositItemPacket` belongs to [UID:0000I9] `ClanBank`. The target `00021J` is not the active vtable-backed dialog sender at `0x0048a790`; it is a no-route raw helper pair in the Clan helper strip, and its action `0` member belongs to the status-pane request family.

Recommended support-doc phrasing:

- `by-file/Clan.md`: replace generic subtype entries for 00021D/00021E and update the 00021I/00021J cluster names to request-and-submit wording. Add a note that subtype `4`/`5` action `1` raw helpers mirror live dialog submitters but remain no-route retained helpers.
- `by-file/ClanBank.md` and `by-class/ClanDepItemDialog.md`: add a cross-note only, not an ownership change, saying the raw `00021J` helper mirrors the live sender but remains Clan-owned/no-route in the helper strip.
- `by-class/ClanDepMoneyInputDialog.md`: add a cross-note that `00021I` action `1` mirrors the live vtable submitter, but the raw helper is not the class method.
- `by-memory/-ignored.md`: no boundary changes are needed; existing padding rows remain correct.

## Final C++ Decision

Leave all final C++ blocks blank.

These helpers are reconstructable in behavior, but source-emission should still wait because:

- none of the target raw starts has a live direct caller, vtable entry, data pointer, VA/RVA pointer hit, or rel32 branch target;
- helper names are best inferred from packet/dialog context rather than recovered symbols;
- `00021I` and `00021J` include duplicate action `1` helpers that mirror active vtable-backed dialog methods, so emitting both in final C++ without a source route risks duplicate source behavior;
- the packet writer/sender wrappers and protocol enum names are still not final-source quality.

## Recommended Target Metadata

- `00021D`: `COMPLETION:85`, `CONFIDENCE:89`, owner/emitter unchanged `0000I8`, reconstructable true, blank C++.
- `00021E`: `COMPLETION:85`, `CONFIDENCE:90`, owner/emitter unchanged `0000I8`, reconstructable true, blank C++.
- `00021F`: `COMPLETION:85`, `CONFIDENCE:90`, owner/emitter unchanged `0000I8`, reconstructable true, blank C++.
- `00021H`: `COMPLETION:85`, `CONFIDENCE:90`, owner/emitter unchanged `0000I8`, reconstructable true, blank C++.
- `00021I`: `COMPLETION:85`, `CONFIDENCE:89`, owner/emitter unchanged `0000I8`, reconstructable true, blank C++.
- `00021J`: `COMPLETION:85`, `CONFIDENCE:89`, owner/emitter unchanged `0000I8`, reconstructable true, blank C++.

## Exact Coverage Row Replacements

Use these as supervisor-owned replacement rows for `by-memory/-coverage-report.md` if the recommended page renames are accepted:

```markdown
    - [UID:00021D][0x00485440-0x004854a5.SendClanStatusRefreshRequestPacket](by-memory/0x00485440-0x004854a5.SendClanStatusRefreshRequestPacket.md) 0x00485440-0x004854a5 | packet helper | SendClanStatusRefreshRequestPacket : reconstructable : 85% : strong : B001 source-quality recheck replaces the generic subtype label with a status-refresh request helper name; live IDA confirms raw no-function/no-xref state, exact `{0x4b,0,word 0}` four-byte packet body, PacketBuffer/QueueAndSendPacket/g_packetSender dependencies, adjacent dispatcher/subtype-0 parser context, and Clan.cpp helper-strip ownership, while PE exact-start VA/RVA and rel32 branch scans found no hidden route; final C++ stays blank because direct reachability and original symbol remain unresolved.
    - [UID:00021E][0x004854b0-0x00485518.SendClanEnlistRequestRefreshPacket](by-memory/0x004854b0-0x00485518.SendClanEnlistRequestRefreshPacket.md) 0x004854b0-0x00485518 | packet helper | SendClanEnlistRequestRefreshPacket : reconstructable : 85% : strong : B001 source-quality recheck replaces the generic subtype label with an enlist-request refresh helper name; live IDA confirms raw no-function/no-xref state, exact `{0x4b,1,0}` three-byte packet body, row-action duplicate evidence for status row 2, inbound subtype-1 enlist-request handler context, PacketBuffer/send dependencies, Clan.cpp helper-strip ownership, and zero exact-start PE pointer/rel32 route hits; final C++ stays blank because this address is retained/no-route.
    - [UID:00021F][0x00485520-0x00485588.SendClanJoinListRefreshPacket](by-memory/0x00485520-0x00485588.SendClanJoinListRefreshPacket.md) 0x00485520-0x00485588 | packet helper | SendClanJoinListRefreshPacket : reconstructable : 85% : strong : B001 source-quality recheck keeps the join-list refresh name; live IDA confirms raw no-function/no-xref state, exact `{0x4b,2,0}` three-byte packet body, row-action duplicate evidence for status row 3, inbound join-list parser context, adjacent live subtype-2 action-1 selection sender callers, PacketBuffer/send dependencies, Clan.cpp helper-strip ownership, and zero exact-start PE pointer/rel32 route hits; final C++ stays blank because this address is retained/no-route.
    - [UID:00021H][0x00485690-0x004856f9.SendClanLeaveRequestPacket](by-memory/0x00485690-0x004856f9.SendClanLeaveRequestPacket.md) 0x00485690-0x004856f9 | packet helper | SendClanLeaveRequestPacket : reconstructable : 85% : strong : B001 source-quality recheck keeps the leave-request helper name; live IDA confirms raw no-function/no-xref state, exact `{0x4b,3,0}` three-byte packet body, row-action duplicate evidence for status row 4, inbound leave-confirm dialog context, adjacent live subtype-3 action-1 confirm/cancel helper callers, PacketBuffer/send dependencies, Clan.cpp helper-strip ownership, and zero exact-start PE pointer/rel32 route hits; final C++ stays blank because this address is retained/no-route.
    - [UID:00021I][0x00485780-0x00485867.ClanDepositMoneyRequestAndSubmitPacketHelpers](by-memory/0x00485780-0x00485867.ClanDepositMoneyRequestAndSubmitPacketHelpers.md) 0x00485780-0x00485867 | packet helper cluster | ClanDepositMoneyRequestAndSubmitPacketHelpers : reconstructable : 85% : strong : B001 source-quality recheck names the subtype-4 action-0 dialog request and action-1 amount submit helpers; live IDA confirms raw no-function/no-xref state for both starts, exact `{0x4b,4,0}` length-3 and `{0x4b,4,1,uint32 amount}` length-7 packet bodies, row-action duplicate evidence for status row 5, inbound deposit-money dialog opener context, mirrored live `ClanDepMoneyInputDialog` submitter evidence, PacketBuffer/send dependencies, Clan.cpp helper-strip ownership, and zero exact-start PE pointer/rel32 route hits; final C++ stays blank because duplicate-helper reachability remains unresolved.
    - [UID:00021J][0x00485870-0x00485955.ClanDepositItemRequestAndSubmitPacketHelpers](by-memory/0x00485870-0x00485955.ClanDepositItemRequestAndSubmitPacketHelpers.md) 0x00485870-0x00485955 | packet helper cluster | ClanDepositItemRequestAndSubmitPacketHelpers : reconstructable : 85% : strong : B001 source-quality recheck names the subtype-5 action-0 dialog request and action-1 selected-slot/amount submit helpers; live IDA confirms raw no-function/no-xref state for both starts, exact `{0x4b,5,0}` length-3 and `{0x4b,5,1,uint8 selectedSlotIndex,uint16 amount}` length-6 packet bodies, row-action duplicate evidence for status row 6, inbound deposit-item dialog opener context, mirrored live ClanBank `ClanDepItemDialog` sender evidence, PacketBuffer/send dependencies, Clan.cpp helper-strip ownership, and zero exact-start PE pointer/rel32 route hits; final C++ stays blank because the active dialog method remains separate and duplicate-helper reachability is unresolved.
```

If the supervisor chooses not to rename the 00021I/00021J files, keep the old link filenames but still update the row labels/descriptions and target-page body with the two source-facing helper signatures above.

## Validation Order For Supervisor

1. Rename or retitle 00021D and 00021E away from generic subtype names.
2. Add source-facing signature/name tables to all six target pages.
3. Add the IDA/MCP and PE liveness evidence to the target pages.
4. Update `Clan.md` helper-strip table and cross-notes for `ClanDepMoneyInputDialog` / `ClanDepItemDialog`.
5. Apply the exact coverage rows above after any accepted page renames.
6. Leave final C++ blank.

## Heuristic / Inference Reanalysis And Validation

Unresolved: original source symbols for all six targets.

Evidence checked: current IDA symbols, target pages, by-file/by-class support docs, `lookup_funcs`, `xref_query`, linear `insn_query`, decompilation of adjacent live helpers, and PE pointer/branch scans. No original symbol or source declaration appears. Therefore the report uses semantic source-facing names derived from packet family, row actions, and inbound handlers. Scores stay at `85` completion rather than higher final-source scores.

Unresolved: direct runtime reachability for the raw target starts.

Evidence checked: IDA function lookup has no function objects; IDA xrefs to raw starts are zero; exact-start VA/RVA pointer hits are zero; exact-start and full-range rel32 branch hits are zero. Adjacent modeled helpers do have expected refs, which shows the negative results are not a broken-query artifact. These helpers should be documented as retained/no-route or duplicate adapter evidence, not live caller-hidden functions.

Unresolved: `00021D` subtype `0` exact user-facing name.

Evidence checked: inbound dispatcher case `0`, `ClanAttributePacketParser`, `ClanStatusPane` parser state, row/resource docs, nearby helper strip, and absence of row-action mapping for subtype `0`. The best current name is `SendClanStatusRefreshRequestPacket` because it likely requests the opcode `0x43` subtype `0` clan status/attribute payload. The report rejects `SendClanAttributeRequestPacket` only to avoid collision with existing `SendClanAttributePacket` subtype `6` action `2`; if later source text proves "attribute request" was original, rename can be revisited.

Unresolved: whether `00021E` should use "request", "refresh", "view", or "open" wording.

Evidence checked: row-action subtype `1` action `0`, inbound `HandleEnlistRequestPacket`, and `ClanEnlistInputDialog` notes. The handler decodes clan name/request text and changes the status-pane view; no modal open is proven. `SendClanEnlistRequestRefreshPacket` is the safest current name because it describes the client request without claiming a dialog-open side effect.

Unresolved: source placement split for deposit item helper evidence.

Evidence checked: `ClanBank.md`, `ClanDepItemDialog` class/memory pages, live decompilation of `0x0048a6b0` and `0x0048a790`, row-action `0x00487600`, raw helper-strip adjacency, and PE/IDA no-route evidence for `0x00485870`/`0x004858e0`. The active dialog class and modeled sender remain ClanBank-owned. The raw 00021J helper pair remains Clan-owned because it is physically and semantically part of the Clan opcode helper strip and has no route tying it to the `ClanDepItemDialog` class method.

Unresolved: whether duplicate raw helpers should be emitted as source functions.

Evidence checked: live action paths for row-action packets, live `ClanDepMoneyInputDialog_SubmitDepositMoney`, live `ClanDepItemDialog::SendDepositItemPacket`, and no-route evidence for raw helpers. Emitting final C++ would risk duplicate behavior without a caller or declaration. The correct current state is reconstructable documentation with blank C++.

Unresolved: exact protocol field name for 00021J action `1` first payload byte.

Evidence checked: raw helper body, live `0x0048a790` sender, and `0x0048a6b0` button handler. The button handler calls `MyItemListPane_GetSelectedSlotIndex` and passes that byte to the virtual sender, so `selectedSlotIndex` is better than the older generic "mode byte." Confidence remains below final because the original member/control names and protocol enum names are not recovered.

Unresolved: final packet enum names and packet-buffer wrapper names.

Evidence checked: `PacketBufferHelpers`, `QueueAndSendPacket`, `g_packetSender`, and many Clan packet pages. The byte/word/dword writer roles are clear, but final source wrapper names are still provisional project-wide. Use behavior names in prose and keep C++ blank.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00021D-00021J-clan-opcode4b-packet-helper-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"00021D"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
