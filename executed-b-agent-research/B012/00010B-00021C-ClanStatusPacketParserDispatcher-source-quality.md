** TARGET-REPORT-UID:00010B **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00010B / 00021C ClanStatus Packet Parser / Dispatcher Source-Quality Research

Agent: Agent-B012  
Assignment: ClanStatus packet parser/dispatcher [UID:00010B] and [UID:00021C]  
Targets:
- `by-memory/0x004842b0-0x00484a50.ClanAttributePacketParser.md`
- `by-memory/0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md`

## Finalized Report

Recommended disposition:
- Keep both targets owned by `UID:00002K ClanStatusPane` and emitted through the Clan source module, `UID:0000I8`, into `auto-generated/NexusTK/social/Clan.cpp`.
- Do not split either target into `ClanDialogs.cpp`, `ClanEnlistInputDialog`, or a raw protocol helper island. The only correct semantic owner is the status pane class; the source file owner remains the broader Clan implementation file.
- Raise both rows from `84/90` to `87/90`. The confidence should stay at `90` because live IDA MCP was unavailable for this pass, but existing target docs already record live IDA facts and the local exported function records close the packet-field and dispatcher-case questions.
- Mark both as first-draft C++ ready only with the limitations stated below. `UID:00010B` is ready for a source-quality first draft after adding the packet-field and slot-name support text. `UID:00021C` is control-flow ready, but its formal block should remain blank until the project chooses the exact source shape for inline dialog construction versus local retained helpers.

No existing `by-*` or coverage file was edited by this pass.

## Supporting Research

| UID | Range | Current name | Current score | Recommended score | Owner / emitter |
| --- | --- | --- | --- | --- | --- |
| `00010B` | `0x004842b0-0x00484a50` | `ClanAttributePacketParser` | `84/90` | `87/90` | `00002K ClanStatusPane` |
| `00021C` | `0x00484f70-0x0048540b` | `ClanStatusPacketDispatcher` | `84/90` | `87/90` | `00002K ClanStatusPane` |

Evidence used:
- Target memory pages for `UID:00010B` and `UID:00021C`.
- `by-class/ClanStatusPane.md`.
- `by-file/Clan.md` and `by-file/ClanDialogs.md`.
- `by-project-structure/proposed-source-tree.md`.
- Related ClanStatusPane pages: `UID:00010C`, `UID:00010G`, `UID:00010H`, `UID:00021D`, `UID:00021O`, `UID:00021S`, and `UID:0002MQ`.
- Generated route evidence in `auto-generated/-ag-memory-coverage.md` and empty emitter markers in `auto-generated/NexusTK/social/Clan.cpp`.
- Read-only exported function records for `0x004842b0` and `0x00484f70`.

IDA MCP note: direct JSON-RPC connection to `127.0.0.1:13337/mcp` failed for this pass. The conclusions below therefore treat current live IDA as unavailable and rely on the target pages' recorded live-IDA facts plus local read-only exported function records. Where evidence is inference instead of direct live IDA, it is labeled as such.

## Supervisor Active Recheck

This is a B-preferred source-quality and inference pass. The assignment did not require direct target repair, and `Agent-B012/goal.md` permits manual edits only inside the Agent-B012 folder unless a split repair is required. The required output is therefore this report.

The active code-entry gate is:
- `RECONSTRUCTABLE:TRUE`.
- Nonblank emitter route to source.
- `(COMPLETION + CONFIDENCE) / 2 > 85`.

Both rows satisfy the numerical and route gate after this pass:
- `UID:00010B`: `RECONSTRUCTABLE:TRUE`, route exists, recommended `(87 + 90) / 2 = 88.5`.
- `UID:00021C`: `RECONSTRUCTABLE:TRUE`, route exists, recommended `(87 + 90) / 2 = 88.5`.

The distinction is source-shape readiness. `UID:00010B` can be populated as a first-draft body once the packet helper names are represented as inline/local source constructs. `UID:00021C` should not be populated as formal C++ until the inline dialog construction pattern is chosen, because a helperized sketch would not match the observed call graph.

## Heuristic / Inference Reanalysis And Validation

### Generated Name And Owner Pollution

Validated facts:
- `0x004842b0` has one ordinary caller from the dispatcher at `0x00484fc8`.
- That caller passes the adjusted receiver `this - 0xa0`, proving the parser belongs to the containing `ClanStatusPane`, not to a dialog object.
- The Ghidra/exported `ClanEnlistInputDialog` receiver label is stale generated ownership. The current target page and ClanStatusPane class page already correct this to `ClanStatusPane`.
- `0x00484f70` is referenced by secondary-vtable/data evidence at `0x006155cc` and reads the packet pointer from an event/message payload at offset `+0x0c`.

Rejected alternatives:
- `ClanEnlistInputDialog::sub_4842B0`: rejected by dispatcher receiver adjustment and the parser's writes into ClanStatusPane status fields.
- `ClanDialogs.cpp`: rejected because these functions drive status-pane state, child panes, and status row text; dialog constructors are callees, not owners.
- Raw packet helper ownership: rejected because the functions update pane fields and invoke pane refresh/invalidation side effects.

Recommended generated-name closure:
- Use `ClanStatusPane::ParseClanStatusAttributesPacket` or `ClanStatusPane::ParseClanStatusAttributePacket` for `UID:00010B`.
- Keep `ClanStatusPane::OnClanStatusPacket` or `ClanStatusPane::DispatchClanStatusPacket` for `UID:00021C`. `OnClanPacket` is acceptable only if the project wants a broader event-handler name.
- Do not leave bare `sub_4842B0` or `sub_484F70` as unresolved names except in quoted IDA evidence.

### Opcode And Subtype Naming

Validated facts:
- Inbound dispatcher accepts only `packet[0] == 0x43`.
- It switches on `packet[1]`, with cases `0..12`.
- Outbound ClanStatus row actions use opcode `0x4b` and subtypes `1..12`; outbound subtype `0` requests the status refresh payload.

Recommended naming:
- `0x43`: inbound ClanStatus packet family.
- `0x43 / subtype 0`: ClanStatus attribute/status text payload.
- `0x4b`: outbound ClanStatus action/request family.
- `0x4b / subtype 0`: ClanStatus refresh request.

Rejected alternatives:
- Naming subtype `0` as `ClanAttributeRequest`: rejected because the request is outbound opcode `0x4b / subtype 0`, while the parser consumes inbound opcode `0x43 / subtype 0`.
- Naming the inbound parser as a generic attribute parser without the status-pane prefix: rejected because the packet directly fills row labels and view state.

### Packet Field Names And Types

Validated `UID:00010B` packet layout:
- `packet[0]`: already checked by dispatcher, opcode `0x43`.
- `packet[1]`: subtype `0`, read/discarded by parser because dispatcher already selected the subtype.
- `packet[2]`: `uint8_t statusDataVersion`.
- `packet[3]`: `uint8_t headerTextByteLength`.
- `packet[4..]`: multibyte header/status title text, converted through `MultiByteToWideChar` into a 40-wide-character local and stored at `this + 0xfe`.
- Next two bytes: `uint16_t rawAttributeDataLength`, read big-endian through the `0x00575480` scalar helper.
- Next `rawAttributeDataLength` bytes: raw attribute blob copied to `this + 0x150` through the memmove wrapper at `0x00516220`; the length is later stored at `this + 0x14e`.
- Next one byte after the raw blob: read/discarded reserved/status group byte. No checked evidence gives this byte a semantic name; keep it as reserved/unknown in support text.
- Then five mandatory `uint8_t length + bytes` text fields for status rows 2 through 6.
- If `statusDataVersion >= 2`, seven more `uint8_t length + bytes` fields are present for management rows 7 through 13.

Important helper correction:
- `0x00575470` is not a high-level PacketBuffer byte reader for these packet fields in the support docs; current PacketBuffer docs identify it as a runtime/narrow-character helper in this evidence path. Treat one-byte fields as raw byte loads.
- `0x00575480` is the confirmed big-endian `uint16_t` helper used for raw attribute length.
- Do not claim the parser calls a length-prefixed string helper. The decompile shows manual byte count, bounded copy, `MultiByteToWideChar`, and `_wcscpy_s`.

Rejected alternatives:
- `uint16_t` lengths for all strings: rejected by direct one-byte length reads.
- Null-terminated packet strings: rejected by explicit length reads and bounded copies.
- Treating the post-raw-blob byte as a confirmed flag set: rejected because no consumer or semantic branch was observed.

### ClanStatusPane Fields And String Slots

Validated field names:
- `this + 0xf8`: `m_currentClanStatusView`.
- `this + 0xf9`: `m_statusDataVersion`.
- `this + 0xfa`: `m_selectedStatusRow`.
- `this + 0x14e`: `m_rawAttributeDataLength`.
- `this + 0x150`: raw attribute data blob.
- `this + 0x2510`: `m_infoListPane`.
- `this + 0x2514`: `m_joinListPane`.
- `this + 0x2518`: `m_enlistListPane`.

Validated text slots:
- `this + 0x00fe`: `m_statusHeaderText`, row 0.
- `this + 0x2150`: `m_statusActionText[0]`, row 2, outbound subtype 1.
- `this + 0x21a0`: `m_statusActionText[1]`, row 3, outbound subtype 2.
- `this + 0x21f0`: `m_statusActionText[2]`, row 4, outbound subtype 3.
- `this + 0x2240`: `m_statusActionText[3]`, row 5, outbound subtype 4.
- `this + 0x2290`: `m_statusActionText[4]`, row 6, outbound subtype 5.
- `this + 0x22e0`: `m_managementActionText[0]`, row 7, outbound subtype 6.
- `this + 0x2330`: `m_managementActionText[1]`, row 8, outbound subtype 7.
- `this + 0x2380`: `m_managementActionText[2]`, row 9, outbound subtype 8.
- `this + 0x23d0`: `m_managementActionText[3]`, row 10, outbound subtype 9.
- `this + 0x2420`: `m_managementActionText[4]`, row 11, outbound subtype 10.
- `this + 0x2470`: `m_managementActionText[5]`, row 12, outbound subtype 11.
- `this + 0x24c0`: `m_managementActionText[6]`, row 13, outbound subtype 12.

Version-2 parse-order caution:
- The packet reads the seven version-2 strings in the order row 7, row 8, row 12, row 13, row 11, row 9, row 10 before copying them into their final field offsets.
- Do not reorder the packet cursor reads by destination address in a final C++ body.

### Refresh Side Effects And Child Pane Updates

Validated parser side effects:
- Calls `ClanStatusPaneRefreshChildPanes` at `0x00487370` before committing the newly parsed version, row selection, raw length, view mode, and text slots.
- Sets `m_statusDataVersion = packet[2]`.
- Sets `m_selectedStatusRow = 0xffff`.
- Sets `m_rawAttributeDataLength` from the big-endian raw length.
- Sets `m_currentClanStatusView = 0` after refresh, selecting the status view.
- Copies parsed text into the row slots listed above.
- Calls the primary vtable slot at `+0x20` with the pane receiver and child/visual receiver offset `+0x44`, matching invalidation/redraw behavior.

Validated `UID:00021O` child refresh behavior:
- Refreshes child pointers in the order join-list pane `+0x2514`, info-list pane `+0x2510`, enlist-list pane `+0x2518`.
- For each child, it invokes vtable slots `+0x38` and `+0x40`.
- The final child call is tail-jumped.

Rejected alternatives:
- Treating the parser tail as only text-copy logic: rejected by child refresh and redraw calls.
- Treating child updates as membership-list parsing: rejected for `UID:00010B`; detailed list population is handled by dispatcher helper cases under `UID:00021S`.

### Dispatcher Cases

Validated `UID:00021C` dispatch:

| Subtype | Action byte | Behavior | Return |
| --- | --- | --- | --- |
| `0` | N/A | Calls `UID:00010B` with adjusted `ClanStatusPane` receiver. | `true` |
| `1` | helper-owned | Calls `0x004877d0`, updates info child and view mode. | helper result |
| `2` | helper-owned | Calls `0x004879e0`, updates join-list child and view mode. | helper result |
| `3` | `0` | Decodes a name and opens `ClanLeaveConfirmDialog`. | `true` |
| `3` | nonzero | Accepts without opening a dialog. | `true` |
| `4` | `0` | Opens `ClanDepMoneyInputDialog`. | `true` |
| `4` | `1` | Accept/no-op. | `true` |
| `4` | other | Rejects. | `false` |
| `5` | `0` | Opens `ClanDepItemDialog`. | `true` |
| `5` | other | Rejects. | `false` |
| `6` | helper-owned | Calls `0x00487ea0`; action 0 fills enlist child/view 4, action 1 opens enlist dialog, action 2 no-op. | helper result |
| `7` | `0` | Opens `ClanExpelNameInputDialog`. | `true` |
| `7` | `1` | Accept/no-op. | `true` |
| `7` | other | Rejects. | `false` |
| `8` | `0` | Opens `ClanSummonNameInputDialog`. | `true` |
| `8` | `1` | Accept/no-op. | `true` |
| `8` | other | Rejects. | `false` |
| `9` | `0` | Opens `ClanAppearNameInputDialog`. | `true` |
| `9` | other | Rejects. | `false` |
| `10` | `0` | Opens `ClanChangeNameInputDialog`. | `true` |
| `10` | `1` | Opens `ClanChangeInputDialog`. | `true` |
| `10` | `2` | Accept/no-op. | `true` |
| `10` | other | Rejects. | `false` |
| `11` | `0` | Opens `ClanWidMoneyInputDialog`. | `true` |
| `11` | `1` | Accept/no-op. | `true` |
| `11` | other | Rejects. | `false` |
| `12` | `0` | Opens `ClanWidItemDialog`. | `true` |
| `12` | `1` | Accept/no-op. | `true` |
| `12` | other | Rejects. | `false` |
| default | N/A | Unhandled subtype. | `false` |

Validated guard:
- If `packet[0] != 0x43`, the dispatcher returns `false`.

Rejected alternatives:
- Treating subtype 3 nonzero action as reject: rejected by local exported decompile, which returns true after setup/no-open.
- Treating all cases as calls to `UID:00021S`: rejected because the dispatcher directly calls only the helper bodies at `0x004877d0`, `0x004879e0`, and `0x00487ea0`; the other dialog openings are inline in the dispatcher body.

### Owner / Emitter Routing

Validated route:
- Canonical owner: `UID:00002K ClanStatusPane`.
- Source module: `UID:0000I8 Clan`.
- Generated path: `auto-generated/NexusTK/social/Clan.cpp`.
- Generated file currently contains empty emitter markers for both `UID:00010B` and `UID:00021C`.

Rejected routes:
- `NexusTK/ui/dialogs/ClanDialogs.cpp`: dialog constructors are called from the dispatcher, but the dispatcher itself belongs with status-pane packet handling.
- `ClanEnlistInputDialog`: stale generated receiver only.
- A new protocol-only source file: rejected because side effects are UI-pane state and child-pane refreshes, not standalone packet decoding.

## Ranked Ownership Analysis

1. `ClanStatusPane` (`UID:00002K`) - accepted. It owns the fields, child panes, view mode, row labels, redraw, and packet event handler.
2. `Clan` file/module (`UID:0000I8`) - accepted as source placement. Existing project structure says `social/Clan.cpp` contains ClanStatusPane and its packet helpers.
3. `ClanDialogs.cpp` (`UID:0000IA`) - rejected for these two targets. It remains relevant only for called dialog classes.
4. `ClanEnlistInputDialog` - rejected as a generated receiver artifact.
5. `UID:00021S` helper island - rejected as owner of the dispatcher. It supplies helper bodies for some cases, but not for the dispatcher itself.

## Final Recommendation

Update target support text with:
- Packet layout table for `UID:00010B`.
- Final text-slot table and version-2 parse-order warning.
- Dispatcher action matrix for `UID:00021C`.
- Explicit rejection of `ClanEnlistInputDialog` and `ClanDialogs.cpp` ownership for these two rows.
- C++ readiness note distinguishing `UID:00010B` parser readiness from `UID:00021C` formal-block delay.

Recommended metadata:

| UID | COMPLETION | CONFIDENCE | RECONSTRUCTABLE | CANONICAL_OWNER | EMITTER_UIDS |
| --- | --- | --- | --- | --- | --- |
| `00010B` | `87` | `90` | `TRUE` | `00002K` | `00002K` |
| `00021C` | `87` | `90` | `TRUE` | `00002K` | `00002K` |

No filename changes are recommended.

## First-Draft C++ Recommendation

### UID:00010B

Populate formal C++ after target support text records the field names and the local packet-text helper convention. The body is source-quality ready as a first draft, but helper names such as `ReadClanPacketText8ToWide40` must be treated as inline/local source helpers or expanded in place; they are not observed out-of-line binary calls.

Recommended first-draft shape:

```cpp
void ClanStatusPane::ParseClanStatusAttributePacket(const unsigned char* packet)
{
    const unsigned char* cursor = packet + 1;
    (void)*cursor++; // subtype already selected by the dispatcher

    const unsigned char statusDataVersion = *cursor++;

    wchar_t headerText[40] = {};
    wchar_t statusText0[40] = {};
    wchar_t statusText1[40] = {};
    wchar_t statusText2[40] = {};
    wchar_t statusText3[40] = {};
    wchar_t statusText4[40] = {};
    wchar_t managementText0[40] = {};
    wchar_t managementText1[40] = {};
    wchar_t managementText2[40] = {};
    wchar_t managementText3[40] = {};
    wchar_t managementText4[40] = {};
    wchar_t managementText5[40] = {};
    wchar_t managementText6[40] = {};

    cursor = ReadClanPacketText8ToWide40(cursor, headerText);

    const unsigned short rawAttributeDataLength = PacketBufferReadUInt16BE(cursor);
    cursor += sizeof(unsigned short);

    memmove(m_rawAttributeData, cursor, rawAttributeDataLength);
    cursor += rawAttributeDataLength;

    (void)*cursor++; // reserved/status text group byte; semantics not proven

    cursor = ReadClanPacketText8ToWide40(cursor, statusText0);
    cursor = ReadClanPacketText8ToWide40(cursor, statusText1);
    cursor = ReadClanPacketText8ToWide40(cursor, statusText2);
    cursor = ReadClanPacketText8ToWide40(cursor, statusText3);
    cursor = ReadClanPacketText8ToWide40(cursor, statusText4);

    if (statusDataVersion >= 2) {
        cursor = ReadClanPacketText8ToWide40(cursor, managementText0);
        cursor = ReadClanPacketText8ToWide40(cursor, managementText1);
        cursor = ReadClanPacketText8ToWide40(cursor, managementText5);
        cursor = ReadClanPacketText8ToWide40(cursor, managementText6);
        cursor = ReadClanPacketText8ToWide40(cursor, managementText4);
        cursor = ReadClanPacketText8ToWide40(cursor, managementText2);
        cursor = ReadClanPacketText8ToWide40(cursor, managementText3);
    }

    RefreshChildPanes();

    m_statusDataVersion = statusDataVersion;
    m_selectedStatusRow = 0xffff;
    m_rawAttributeDataLength = rawAttributeDataLength;
    m_currentClanStatusView = ClanStatusView_Status;

    wcscpy_s(m_statusHeaderText, _countof(m_statusHeaderText), headerText);
    wcscpy_s(m_statusActionText[0], _countof(m_statusActionText[0]), statusText0);
    wcscpy_s(m_statusActionText[1], _countof(m_statusActionText[1]), statusText1);
    wcscpy_s(m_statusActionText[2], _countof(m_statusActionText[2]), statusText2);
    wcscpy_s(m_statusActionText[3], _countof(m_statusActionText[3]), statusText3);
    wcscpy_s(m_statusActionText[4], _countof(m_statusActionText[4]), statusText4);

    if (statusDataVersion >= 2) {
        wcscpy_s(m_managementActionText[0], _countof(m_managementActionText[0]), managementText0);
        wcscpy_s(m_managementActionText[1], _countof(m_managementActionText[1]), managementText1);
        wcscpy_s(m_managementActionText[2], _countof(m_managementActionText[2]), managementText2);
        wcscpy_s(m_managementActionText[3], _countof(m_managementActionText[3]), managementText3);
        wcscpy_s(m_managementActionText[4], _countof(m_managementActionText[4]), managementText4);
        wcscpy_s(m_managementActionText[5], _countof(m_managementActionText[5]), managementText5);
        wcscpy_s(m_managementActionText[6], _countof(m_managementActionText[6]), managementText6);
    }

    Invalidate();
}
```

Implementation caveat:
- `ReadClanPacketText8ToWide40` must model the observed bounded copy, `MultiByteToWideChar`, range check at 40 wide characters, and `_wcscpy_s` behavior. It should not be emitted as a new external binary helper unless a matching source helper is intentionally introduced.

### UID:00021C

Do not populate formal C++ yet. The dispatcher control flow is resolved, but a compilable formal block would need either:
- fully inlined dialog construction matching the observed body, including allocation sizes and constructors, or
- local retained source helpers for dialog-opening branches, with support text explaining that the helpers are source reconstruction conveniences and not observed out-of-line calls for cases 3-5 and 7-12.

The following control-flow sketch is ready as review material, not as a formal block:

```cpp
bool ClanStatusPane::OnClanStatusPacket(const ClanPacketEvent* event)
{
    const unsigned char* packet = event->packet;
    if (packet[0] != 0x43) {
        return false;
    }

    switch (packet[1]) {
    case 0:
        ParseClanStatusAttributePacket(packet);
        return true;
    case 1:
        return HandleClanStatusInfoPacket(packet);
    case 2:
        return HandleClanJoinListPacket(packet);
    case 3:
        return OpenLeaveConfirmDialogFromClanPacket(packet);
    case 4:
        return DispatchClanDepositMoneyPacket(packet);
    case 5:
        return DispatchClanDepositItemPacket(packet);
    case 6:
        return HandleClanEnlistPacket(packet);
    case 7:
        return DispatchClanExpelNamePacket(packet);
    case 8:
        return DispatchClanSummonNamePacket(packet);
    case 9:
        return DispatchClanAppearNamePacket(packet);
    case 10:
        return DispatchClanChangePacket(packet);
    case 11:
        return DispatchClanWithdrawMoneyPacket(packet);
    case 12:
        return DispatchClanWithdrawItemPacket(packet);
    default:
        return false;
    }
}
```

Rejected formal-block shortcut:
- Emitting the sketch above as final C++ without support text would be misleading because only cases `1`, `2`, and `6` are direct helper calls in the observed dispatcher. The other helper names are source-quality names for inline dialog construction branches.

## Support / Coverage Replacement Text

Do not edit `by-memory/-coverage-report.md` directly from this B pass. If a maintainer applies this report, replace the two rows with the following exact rows, preserving coverage-file ordering:

```text
| UID:00010B | 0x004842b0 | 0x00484a50 | 0x7a1 | packet parser | ClanStatusPane::ParseClanStatusAttributePacket | reconstructable | 87% | strong | ClanStatusPane-owned inbound opcode 0x43 subtype 0 parser. Reanalysis resolves packet field names and types, raw attribute length/blob handling, row text slots, version-2 management text order, child-pane refresh side effects, owner/emitter routing to social/Clan.cpp, and first-draft parser C++ readiness. |
| UID:00021C | 0x00484f70 | 0x0048540b | 0x49b | packet dispatcher | ClanStatusPane::OnClanStatusPacket | reconstructable | 87% | strong | ClanStatusPane secondary-vtable inbound opcode 0x43 dispatcher. Reanalysis resolves subtype cases 0-12, action-byte returns, dialog-opening branches, direct helper calls for cases 1/2/6, owner/emitter routing to social/Clan.cpp, and explains why formal dispatcher C++ should wait for inline dialog-construction source-shape selection. |
```

## Exact Replacement Metadata Notes

Recommended target-page support additions:
- Add `COMPLETION:87` and keep `CONFIDENCE:90`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `CANONICAL_OWNER: UID:00002K`.
- Keep `EMITTER_UIDS: UID:00002K`.
- For `UID:00010B`, rename the display/function title from `ClanAttributePacketParser` to `ClanStatusPane::ParseClanStatusAttributePacket` if project naming policy allows class-qualified names in the target header.
- For `UID:00021C`, keep `ClanStatusPacketDispatcher` as a stable filename title or promote the source name `ClanStatusPane::OnClanStatusPacket` in support text.

## Remaining Risk

No protocol questions remain open for this pass. Remaining risk is source-shape only:
- The formal source name of the secondary-vtable event handler is not recovered.
- The exact event payload type name for the `+0x0c` packet pointer is not recovered.
- Dialog-opening branches in `UID:00021C` are resolved behaviorally but not ready for formal C++ unless emitted inline or deliberately wrapped by source-local reconstruction helpers.

These risks do not affect ownership, packet field names/types, dispatcher case coverage, child-pane side effects, or coverage replacement rows.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/00010B-00021C-ClanStatusPacketParserDispatcher-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"00010B"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
