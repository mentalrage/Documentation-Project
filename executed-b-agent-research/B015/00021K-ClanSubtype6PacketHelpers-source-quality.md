** TARGET-REPORT-UID:00021K **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00021K ClanSubtype6PacketHelpers Source-Quality / Heuristic Research

## Finalized Report / Current Recommendation

- Current recommendation: rename/reframe [UID:00021K] from generic `ClanSubtype6PacketHelpers` to `ClanEnlistListRefreshAndSelectionPacketHelpers`.
- Final disposition: keep it as one by-memory cluster covering two adjacent source functions plus internal `0xcc` alignment; do not split into child pages.
- Direct owner recommendation: change `CANONICAL_OWNER` from [UID:0000I8][Clan] to [UID:00002K][ClanStatusPane]. Keep generated source route through [UID:00002K] to [UID:0000I8] `NexusTK/social/Clan.cpp`.
- Required action: update target/support docs, apply the exact coverage row below, and populate first-draft C++ unless the supervisor rejects the class-method source-shape recommendation.
- Recommended score: `84/90` -> `88/91`.
- Confidence: strong for range, packet layout, callers, source route, and helper names as descriptive source-facing names; medium-high for exact original source symbols and user-facing action labels.

## Target

- Target UID: `00021K`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00485960-0x00485abe.ClanSubtype6PacketHelpers.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B015\research\00021K-ClanSubtype6PacketHelpers-source-quality.md`
- Current source queue row: `project-level/-auto-completion-stats.md` lists `00021K` at `84/90`, average `87.0`, low-score reconstructable.
- Current generated route: `auto-generated/-ag-memory-coverage.md` routes `00021K` through `0000I8` to `auto-generated/NexusTK/social/Clan.cpp`, with no emitted C++ body.
- Current metadata: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000I8`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000I8`.

## Executive Recommendation

The two helpers should be named:

| Address | Recommended source-facing name | Recommended signature | Meaning |
| --- | --- | --- | --- |
| `0x00485960-0x004859c9` | `ClanStatusPane::SendClanEnlistListRefreshPacket` | `int ClanStatusPane::SendClanEnlistListRefreshPacket()` | Sends subtype `6`, action `0`: `{ 0x4b, 6, 0 }`. Used from status row `7` to request/open the enlist list and after inline action `3` to refresh it. |
| `0x004859d0-0x00485abe` | `ClanStatusPane::SendClanEnlistListSelectionPacket` | `int ClanStatusPane::SendClanEnlistListSelectionPacket(const wchar_t *applicantName)` | Sends subtype `6`, action `1`: `{ 0x4b, 6, 1, nameLen, nameBytes... }` for the selected enlist-list row. |

`applicantName` is an inferred descriptive argument name, not recovered symbol proof. It is stronger than `name` because every caller obtains text from `ClanEnlistListPane`, and subtype `6` action `2` is the separate enlistment submission path from `ClanEnlistInputDialog`.

Do not name action `1` as approve/accept/reject. The binary proves selected-row submission, not the server-side decision label. Do not keep `SendClanSubtype6OpenRequest` or `SendClanSubtype6NamePacket`; those names preserve numeric protocol uncertainty after caller context now resolves the feature surface.

## Supervisor Active Recheck

- The active assignment asks for a B-preferred source-quality and heuristic-inference pass, not direct target edits.
- I did not edit `by-memory/-coverage-report.md` and did not edit target/support by-* docs.
- The target does not require split repair before the report. Both executable functions share the same feature, receiver pattern, packet family, caller family, source route, and first-draft source shape. Internal padding is already documented and does not justify a standalone child page.
- IDA MCP is currently unavailable at `http://127.0.0.1:13337/mcp` (`Unable to connect to the remote server`). I used existing live IDA evidence already recorded in the target/support docs and revalidated the bytes/call edges directly from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` with a section-mapped PE/Capstone script.

## Inference Research Guidance Check

`by-structure.md` requires source-quality questions to be resolved before C++ entry and permits first-draft C++ when `RECONSTRUCTABLE:TRUE`, emitter routing is confirmed, and `(COMPLETION + CONFIDENCE) / 2 > 85`. This target already meets the minimum gate, but the current doc still carries generic helper names and a stale 95-percent no-code rationale.

`inference_research.md` emphasizes that source-file and source-name recovery are probabilistic without debug symbols. I separate direct byte facts from inference below. The `ClanStatusPane` owner recommendation is not based on address adjacency alone; it is based on explicit call-site receiver setup (`ecx = ClanStatusPane` / `g_pClanStatusPane`) plus caller semantics.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best inference / decision | Rejected alternatives and impact |
| --- | --- | --- | --- |
| Action `0` helper name | Raw PE disassembly of `0x00485960`, direct rel32 callers at `0x004876b6` and `0x00488aec`, [UID:00010H], [UID:00021U], [UID:00002C]. | `SendClanEnlistListRefreshPacket`. It requests/refreshes the enlist-list state. | Reject `OpenRequest` as too narrow because the helper is also called after inline action `3` to refresh. Reject `Subtype6Action0` as not source-quality. |
| Action `1` helper name | Raw PE disassembly of `0x004859d0`, direct rel32 callers at `0x0048898a` and `0x00488b09`, selected-entry calls through `0x004f3dc0`, [UID:00021U]. | `SendClanEnlistListSelectionPacket(const wchar_t *applicantName)`. | Reject `NamePacket` because the list/caller context is known. Reject `ApproveApplicant`/`AcceptEnlistment` because server-side meaning is not directly proven. |
| Class/member versus file-local helper shape | Caller `0x00484e91` sets `ecx = esi` before `0x00487600`; row `7` then reaches `0x00485960` with that receiver. `ClanEnlistListPane` callers set `ecx = [0x0067ade4]` before `0x00485960`/`0x004859d0`. Bodies ignore `ecx`. | First-draft C++ should define private/near-private `ClanStatusPane` packet methods. Direct owner should be [UID:00002K], emitter [UID:00002K], still surfacing to `social/Clan.cpp`. | Keeping [UID:0000I8] as direct owner is acceptable only as a source-root fallback, but it loses the real thiscall receiver evidence. `ClanEnlistListPane` is rejected as owner because it is a caller/consumer and passes `g_pClanStatusPane` as receiver. |
| Split/range status | PE bytes: `0x00485960-0x004859c9` function, `0x004859c9-0x004859d0` seven `0xcc` bytes, `0x004859d0-0x00485abe` function, `0x00485abe-0x00485ac0` two `0xcc` bytes. Existing target and coverage rows already record these boundaries. | Keep one page. It is a coherent two-helper source cluster with internal alignment, matching 00021I/00021J cluster style. | Splitting into action `0`, padding, and action `1` pages would add bookkeeping without changing ownership, source route, or C++ readiness. It is optional future granularity, not required repair. |
| Packet layout action `0` | Disassembly at `0x0048597a`, `0x00485988`, `0x00485996`, send at `0x004859b3`. | Sends exactly `{ 0x4b, 0x06, 0x00 }`, length `3`. `0x4b` is decimal `75` / ASCII `K` (Verified with int_convert.py). | No extra payload field. `packet[3] = 0` is local scratch terminator, not sent. |
| Packet layout action `1` | Disassembly at `0x004859f6`, `0x00485a04`, `0x00485a12`, conversion at `0x00485a46`, length write at `0x00485a66`, copy at `0x00485a7c`, send at `0x00485aa2`. | Sends `{ 0x4b, 0x06, 0x01, nameLen, nameBytes... }`, length `convertedLength + 4`. | Do not model a string terminator in the protocol. Both `convertedName[convertedLength] = 0` and `packet[packetLength] = 0` are outside the sent span. |
| Range checks | Action `1` compares converted length against `0x100` / 256 and final packet length against `0x80` / 128 (Verified with int_convert.py). | Keep both checks in C++. Effective sent-name cap is `convertedLength + 4 < 128`, while the conversion scratch buffer separately caps `< 256`. | Do not collapse to a single `strlen < 128` guard; the binary has two independent range-check sites. |
| Packet API role `0x00575380` | [UID:0003YJ] split page and 1114 xrefs. | Use `PacketBufferWriteUInt8` / byte writer in prose and C++ draft. | Do not use raw `sub_575380`; do not call it a string writer. |
| Send helper `0x00574bb0` | [UID:0001HU] documents Socket-owned queue/send wrapper, request code `8`, private queued copy terminator. | Use `g_packetSender->QueueAndSendPacket(packet, length)` in draft, matching current generated Clan submitters. | Do not call it direct socket write/framing/encryption. Its private appended zero is not a protocol byte from this helper. |
| Global `0x0067a7ec` | [UID:0001P0] and [UID:0000Q5] document Socket-owned `Socket *g_packetSender`, not CashShopRequest. | Use `g_packetSender` as current source-facing global. | Reject generated `g_pCashShopRequest` aliases for this target. |
| `0x00516030` / `0x00516220` | [UID:0001BC] and [UID:0001BH]; raw disassembly shows `0x00516030` before payload copy and `0x00516220` copying converted bytes. | Treat `0x00516030` as `GetMemoryMan`/context touch and `0x00516220` as `memmove` wrapper. Draft C++ should use `memmove`, consistent with already populated name submitters. | Do not invent packet-specific conversion helpers. |
| Relationship to action `2` | [UID:00010E] begins after `0x00485abe-0x00485ac0` padding and sends subtype `6`, action `2`, three strings plus 16-bit value from `ClanEnlistInputDialogSubmitEnlistment`. | Action `0`/`1` are enlist-list management/selection helpers; action `2` is separate enlistment/attribute submit payload. | Do not rename this target `SendClanAttributePacket`; that name belongs to action `2`. |
| Relationship to action `3` | [UID:00021U] inlines subtype `6`, action `3` selected-name packet on key `0x84` / 132 (Verified with int_convert.py), then calls action `0`. [UID:00021L] has raw no-xref action `3` helper. | Keep action `3` outside this page. The action `0` call after action `3` confirms refresh semantics. | Do not merge 00021K with 00021L; 00021L has raw no-route duplicate-helper caveats while 00021K has live modeled functions. |
| Source should inline or call helpers | Both helpers are real branch targets with direct rel32 calls; action `3` is the inline body in 00021U. | First-draft source should define private helper methods and call them from row/list handlers. | Do not inline action `0`/`1` into callers; that would erase observed source-level function boundaries. |
| First-draft C++ readiness | Current target is `RECONSTRUCTABLE:TRUE`, has a nonblank emitter route, average score is already `87`, raw PE confirms bytes/callers, and names/source shape are now resolved enough. | Populate first-draft C++ after applying owner/emitter route and name changes. | No concrete no-code proof remains. Original symbol uncertainty caps score but does not block draft source. |

## Evidence Standards Used

- Direct byte evidence: section-mapped PE parser plus Capstone disassembly of `0x00485960-0x00485abe`, `0x004859c9-0x004859d0`, `0x00485abe-0x00485ac0`, and caller snippets.
- Direct rel32 scans: exactly two calls to `0x00485960` (`0x004876b6`, `0x00488aec`) and exactly two calls to `0x004859d0` (`0x0048898a`, `0x00488b09`); zero VA/RVA dword pointer hits to either start.
- Documentation evidence: target page, `Clan.md`, `ClanStatusPane`, `ClanEnlistListPane`, [UID:00010H], [UID:00021U], [UID:00010E], [UID:00021L], PacketBuffer, QueueAndSendPacket, g_packetSender, MemoryMan helper pages, B001/B002 executed reports.
- Generated-state evidence: `-ag-memory-coverage.md` confirms current route to `social/Clan.cpp`; `Clan.cpp` shows existing first-draft style for equivalent name submitters.
- Tool limitation: live IDA MCP endpoint was unavailable during this pass. The report relies on existing live IDA notes already in the docs plus direct raw PE revalidation.

## IDA / PE Facts

### Function and Padding Facts

| Range | Fact |
| --- | --- |
| `0x00485960-0x004859c9` | Modeled action `0` function, size `0x69` / 105 (Verified with int_convert.py), stack allocation `0x84`, writes three packet bytes and sends length `3`. |
| `0x004859c9-0x004859d0` | Seven `0xcc` bytes; compiler/linker alignment between helpers. |
| `0x004859d0-0x00485abe` | Modeled action `1` function, size `0xee` / 238 (Verified with int_convert.py), stack allocation `0x184`, one stack argument, `ret 4`. |
| `0x00485abe-0x00485ac0` | Two `0xcc` bytes before [UID:00010E] action `2` helper. |

### Caller Facts

| Address | Call target | Meaning |
| --- | --- | --- |
| `0x004876b6` | `0x00485960` | [UID:00010H] row `7` delegate. Caller path sets `ecx` to the `ClanStatusPane` receiver before `0x00487600`. |
| `0x00488aec` | `0x00485960` | [UID:00021U] action `3` path sends inline `{0x4b,6,3,name...}` then refreshes the list through action `0`. |
| `0x0048898a` | `0x004859d0` | `ClanEnlistListPane` selected-row action: selected index `+0x134`, `0x004f3dc0` selected text, `ecx = g_pClanStatusPane`. |
| `0x00488b09` | `0x004859d0` | `ClanEnlistListPane` Enter key path after selected row lookup. |

### Negative Facts

- No exact VA or RVA dword pointer hits to `0x00485960` or `0x004859d0` were found in the PE.
- No additional rel32 direct calls to either helper were found outside the four known call sites.
- No switch table belongs to this target. The nearby row-action switch table remains part of [UID:00010H] at `0x004877a0-0x004877d0`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00485960-0x004859c9` | part of `00021K` | `ClanStatusPane::SendClanEnlistListRefreshPacket` | TRUE | recommend `00002K` | included in `88/91` | source-ready |
| `0x004859c9-0x004859d0` | part of `00021K` | internal alignment | FALSE as source bytes | contained only | n/a | no child split needed |
| `0x004859d0-0x00485abe` | part of `00021K` | `ClanStatusPane::SendClanEnlistListSelectionPacket` | TRUE | recommend `00002K` | included in `88/91` | source-ready |

## Ranked Ownership Analysis

### 1. [UID:00002K] ClanStatusPane

- Evidence for: every live caller uses or preserves a `ClanStatusPane` receiver in `ecx`; `0x00484e91` calls [UID:00010H] with `ecx = esi` and row `7` delegates to action `0`; `ClanEnlistListPane` callers load `g_pClanStatusPane` from `0x0067ade4` and set `ecx` before both action helpers; [UID:00002K] is `85/86` and routes through [UID:0000I8] to `social/Clan.cpp`.
- Evidence against: helper bodies do not read `this`; current target and Clan file docs classify them as file-level helpers; sibling packet helper pages have historically used file-level owner conventions.
- Decision: accept as the best direct semantic owner for source-quality C++. The unused receiver explains why old docs treated the helpers as file-local, but source call shape is member-style.

### 2. [UID:0000I8] Clan

- Evidence for: all code still belongs in `NexusTK/social/Clan.cpp`; the helpers sit in the contiguous opcode `0x4b` Clan packet-helper island; current owner/emitter route works as a generated source root.
- Evidence against: it is a source root, not the narrowest source owner once receiver setup is considered.
- Decision: keep as the file/source route, not the direct owner. If the supervisor declines a parent change, the first-draft code should still be class-qualified in `Clan.cpp`.

### 3. [UID:00002C] ClanEnlistListPane

- Evidence for: action `1` is only used from `ClanEnlistListPane` selected-row/Enter handlers, and action `0` is called from the same key handler after action `3`.
- Evidence against: call sites explicitly set `ecx` to `g_pClanStatusPane`, not the list pane, before calling 00021K helpers.
- Decision: reject as direct owner; keep it as caller/consumer documentation.

### 4. PacketBuffer / Socket / protocol-only ownership

- Evidence for: helpers use PacketBuffer byte writer, `g_packetSender`, and queue/send.
- Evidence against: packet fields and callers are Clan feature-specific; shared network helpers are dependencies only.
- Decision: reject.

## First-Draft C++ Recommendation

Populate the target's `RECONSTRUCTION_CPP CODE` after applying the owner/name update. This draft intentionally follows the style already accepted in `auto-generated/NexusTK/social/Clan.cpp` for name submitters: explicit `PacketBufferWriteUInt8`, `WideCharToMultiByte(CP_ACP, ...)`, `memmove`, range-check failure calls, and `g_packetSender->QueueAndSendPacket`.

```cpp
int ClanStatusPane::SendClanEnlistListRefreshPacket()
{
    unsigned char packet[128];

    PacketBufferWriteUInt8(packet + 0, 0x4b);
    PacketBufferWriteUInt8(packet + 1, 0x06);
    PacketBufferWriteUInt8(packet + 2, 0x00);
    packet[3] = 0;

    return g_packetSender->QueueAndSendPacket(packet, 3);
}

int ClanStatusPane::SendClanEnlistListSelectionPacket(const wchar_t *applicantName)
{
    char convertedName[256];
    unsigned char packet[128];

    PacketBufferWriteUInt8(packet + 0, 0x4b);
    PacketBufferWriteUInt8(packet + 1, 0x06);
    PacketBufferWriteUInt8(packet + 2, 0x01);

    unsigned int convertedLength = WideCharToMultiByte(
        CP_ACP, 0, applicantName, wcslen(applicantName), convertedName, sizeof(convertedName), NULL, NULL);
    if (convertedLength >= sizeof(convertedName)) {
        __report_rangecheckfailure();
    }

    convertedName[convertedLength] = 0;
    PacketBufferWriteUInt8(packet + 3, convertedLength);
    memmove(packet + 4, convertedName, convertedLength);

    unsigned int packetLength = convertedLength + 4;
    if (packetLength >= sizeof(packet)) {
        __report_rangecheckfailure();
    }

    packet[packetLength] = 0;
    return g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength));
}
```

Notes for the target page:

- `packet[3] = 0` in action `0` and `packet[packetLength] = 0` in action `1` are not sent because the queued lengths are `3` and `packetLength`.
- `convertedName[convertedLength] = 0` is a local scratch terminator after the converted byte string; it is not copied into the packet payload.
- `ClanStatusPane` method placement is the best source-shape inference from call sites. If the project later standardizes these helpers as file-local wrappers, the body can be mechanically changed to `static int SendClanEnlistListRefreshPacket(ClanStatusPane *)` and `static int SendClanEnlistListSelectionPacket(ClanStatusPane *, const wchar_t *)`, but that would not match the observed thiscall-like call convention as cleanly.

## Recommended Target Updates

Recommended metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00002K | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00002K | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended title/path:

```text
0x00485960-0x00485abe.ClanEnlistListRefreshAndSelectionPacketHelpers.md
```

Recommended covered-ranges table:

```text
| `0x00485960-0x004859c9` | `ClanStatusPane::SendClanEnlistListRefreshPacket` | Sends opcode `0x4b`, subtype `6`, action `0`; used by status row `7` and as the refresh after inline action `3`. |
| `0x004859c9-0x004859d0` | alignment | Seven `0xcc` bytes between helper methods; no child split required. |
| `0x004859d0-0x00485abe` | `ClanStatusPane::SendClanEnlistListSelectionPacket` | Sends opcode `0x4b`, subtype `6`, action `1`, and a length-prefixed selected enlist-list/applicant name. |
```

## Support-Doc Recommendations

- [UID:0000I8] `Clan.md`: rename the proposed contents row from `ClanSubtype6PacketHelpers` to `ClanEnlistListRefreshAndSelectionPacketHelpers`; state that it emits `ClanStatusPane` private packet methods in `social/Clan.cpp`; keep the relationship to action `2` `SendClanAttributePacket` and action `3` raw/inline helpers.
- [UID:00002K] `ClanStatusPane.md`: add methods `SendClanEnlistListRefreshPacket` and `SendClanEnlistListSelectionPacket` near the row-action/list-pane helper entries; document that bodies do not read fields but are called with `ClanStatusPane` receiver.
- [UID:00002C] `ClanEnlistListPane.md`: replace raw helper references with `g_pClanStatusPane->SendClanEnlistListSelectionPacket(applicantName)` for selected-row and Enter paths, and `g_pClanStatusPane->SendClanEnlistListRefreshPacket()` after the inline action `3` path.
- [UID:00021U] `ClanListPaneInputHandlers`: update behavior text to use the new helper names; keep key `0x84` / 132 (Verified with int_convert.py) as a semantic caveat rather than naming it approve/reject.
- [UID:00010H] `ClanStatusRowActionPacket`: row `7` should be described as delegating to `ClanStatusPane::SendClanEnlistListRefreshPacket`.
- [UID:00010E] `SendClanAttributePacket`: keep the action `2` relationship but clarify it is `ClanEnlistInputDialog` enlistment/attribute submission, not action `0`/`1` list management.
- [UID:00021L] `ClanNameActionPacketHelpers`: add a cross-note that subtype `6` action `3` is still raw/no-route in that page while [UID:00021U] contains the live inline action `3` body followed by this target's action `0` refresh.
- Packet helper docs [UID:0003YJ], [UID:0001HU], [UID:0001P0], [UID:0001BC], and [UID:0001BH]: no changes required; this report consumes their current role names.

## Exact Coverage Row Replacement

Replace the current [UID:00021K] row between the `0x00485955-0x00485960` padding row and the `0x00485abe-0x00485ac0` padding row with:

```markdown
    - [UID:00021K][0x00485960-0x00485abe.ClanEnlistListRefreshAndSelectionPacketHelpers](by-memory/0x00485960-0x00485abe.ClanEnlistListRefreshAndSelectionPacketHelpers.md) 0x00485960-0x00485abe | packet helper cluster | ClanEnlistListRefreshAndSelectionPacketHelpers : reconstructable : 88% : strong : B015 source-quality recheck resolves subtype `6` action `0` as `ClanStatusPane::SendClanEnlistListRefreshPacket` and action `1` as `ClanStatusPane::SendClanEnlistListSelectionPacket(const wchar_t *applicantName)`; raw PE/Capstone confirms two modeled helper bodies, `0x004859c9-0x004859d0` internal `0xcc` padding, exact `{0x4b,6,0}` and `{0x4b,6,1,len,name...}` packet layouts, two direct calls to each helper, selected enlist-list caller semantics, PacketBufferWriteUInt8/QueueAndSendPacket/g_packetSender/GetMemoryMan/memmove dependencies, converted-name and packet-length guards, non-sent local terminator bytes, adjacency to subtype `6` action `2`, and no need for child split pages.
```

If the supervisor does not rename the target file, use the same row text with the existing link target `by-memory/0x00485960-0x00485abe.ClanSubtype6PacketHelpers.md` and row display name `ClanSubtype6PacketHelpers`, but that is the weaker source-quality result.

## Final Recommendation

- Rename/reframe the target around enlist-list refresh/selection semantics.
- Change direct owner/emitter from `0000I8` to `00002K` because call sites use a `ClanStatusPane` receiver.
- Keep the by-memory cluster as one page; do not split action `0`, internal padding, and action `1`.
- Populate the first-draft C++ block with the two `ClanStatusPane` methods above.
- Raise score to `88/91`.
- Do not edit `by-memory/-coverage-report.md` directly; apply the exact replacement row above through supervisor-owned workflow.

## Validator Results

- No validator run was required for this report-only assignment.
- Commands/evidence run in this pass:
  - Direct MCP endpoint request: failed to connect.

> The removed literal PowerShell command is preserved only in [00021K-ClanSubtype6PacketHelpers-source-quality-removed.md](00021K-ClanSubtype6PacketHelpers-source-quality-removed.md). The archive is non-authoritative and must not be executed.
  - Raw PE/Capstone section-mapped disassembly and rel32/pointer scan against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - `int_convert.py` for `0x4b`, `0x84`, `0x100`, `0x80`, `0x184`, `0xee`, `0x69`, `0x0d`, and `0x03`.
  - Read-only documentation/generated-state checks listed in the sections above.

## Changed Files

- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B015\research\00021K-ClanSubtype6PacketHelpers-source-quality.md`
- Modified: none outside Agent-B015 research.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/00021K-ClanSubtype6PacketHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:37","uid":"00021K"} -->
<!-- {"agent":"B015","command_id":"000000023047","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00021K-ClanSubtype6PacketHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B015/00021K-ClanSubtype6PacketHelpers-source-quality.md","timestamp":"2026-08-13T02:36:38-04:00","uid":"00021K"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
