*** UID:0000VG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact ServerSelectMenuItemList ApplySelectedServer and private SendServerSelectPacket helpers with two action callers, member-this ABI, complete frames/types, selected-name/config writes, three-byte opcode-0x57 send, selected-id/endpoint formatting behavior, raw sibling route evidence, and formal source emitted once through UID0000D1. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ServerSelectHelpers_574510_5745b0

## Status

- Confidence: very strong for server-select ownership, exact helper boundaries/hashes, member ABI, frames, callers, packet/state behavior, raw-sibling routes, and the single formal source owner; original private spelling remains inferred rather than symbol-proven.
- Owner/emitter route: [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md)
- Exact memory range: [UID:0001HR][0x00573d20-0x005747df.ServerSelectPane](by-memory/0x00573d20-0x005747df.ServerSelectPane.md)
- Rebuild handling: source-authored login/server-selection methods. This index remains formally blank to avoid duplicate definitions; complete accepted CPP/H is emitted once through [UID:0000D1][ServerSelectMenuItemList](by-class/ServerSelectMenuItemList.md), including the resolved entry declaration and raw-route caveats.

## Helper Summary

| Address range | Proposed name | Behavior |
| --- | --- | --- |
| `0x00574510-0x0057454e` | `ServerSelectMenuItemList::ApplySelectedServer()` | Reads the selected server-list row through current `GetItem`, copies `entry->name` into `g_pConfig + 0x2916d0`, then forwards `entry->serverId` and entry pointer to the member packet helper. SHA256 `16EB3EFBB21760F6CA7894F0F99CF9B7867A5229C457FE803E4C6889D870650C`. |
| `0x00574570-0x005745ac` | raw `ServerSelectMenuItemList::ApplyServerEntry(const ServerSelectEntry *entry)` | Unmodeled function-shaped wrapper; copies the selected entry name through `g_pApplication + 0x858` current-server display state, then forwards the entry id and entry pointer to `SendServerSelectPacket`. SHA256 `BE5DEA2A3BB6610B5C72D6EC42D6256355BC73C5B40290BB6FCD3D0F928E240D`. |
| `0x005745b0-0x0057465e` | private member `ServerSelectMenuItemList::SendServerSelectPacket(unsigned int serverId, const ServerSelectEntry *entry)` | Both callers carry the list instance in ECX. The method builds and sends three bytes headed by opcode `0x57`, stores the selected id, and formats endpoint text when alternate-endpoint state is clear. SHA256 `E888F2CA0129A9D67D1E45111FDC3E84E8F649E22386A8B77BF28268386EDBB5`. |

## IDA MCP Evidence

Checked on 2026-05-24:

- `lookup_funcs` confirms `0x00574510` as a real function of size `0x3e`, and `0x005745b0` as a real function of size `0xae`.
- `xrefs_to 0x00574510` reports only code xrefs from `ServerSelectPane::OnControlCommand` at `0x00574399` and `0x005743db`, covering the high-resolution and classic layout branches.
- `xrefs_to 0x005745b0` reports the direct call from `0x00574510` at `0x00574546`; the additional raw ref at `0x005745a1` is just before the function body and needs boundary review.
- Decompilation of `0x00574510` copies the selected entry name from `[entry + 4]` into the config/current-server buffer at `g_pConfig + 0x2916d0` with capacity `0x10`, then calls `0x005745b0` with the entry id byte and entry pointer.
- Decompilation of `0x005745b0` emits packet bytes `0x57`, `0`, and the selected id through the packet helper path, writes the selected id to `g_pConfig + 0x28d9d8`, and formats an endpoint string from config/application state plus entry address bytes/port fields when the flag at `g_pConfig + 0x28d9dd` is clear.
- 2026-05-31 IDA MCP recheck reports `0x00574510` as `sub_574510` with exclusive end `0x0057454e` and direct callsites at `0x00574399` and `0x005743db`; its callees are selected-entry access, `_wcscpy_s`, and `0x005745b0`.
- 2026-05-31 IDA MCP recheck reports `0x005745b0` as `sub_5745B0` with exclusive end `0x0057465e`; it is called by `0x00574510` and the near-boundary code ref at `0x005745a1`, writes packet bytes with `0x00575380`, sends through `0x00574bb0`, and updates `g_pConfig` session/config fields.

Rechecked with live IDA MCP on 2026-06-03:

- `lookup_funcs` reports exact modeled functions at `0x00574510-0x0057454e` and `0x005745b0-0x0057465e`; `0x00574580`, `0x005745a1`, and `0x0057465e` are not function starts.
- `sub_574340` is the `ServerSelectPane::OnControlCommand(int controlIndex, int notifyCode)` caller. Its primary vtable slot `+0x48`, two-argument `retn 8` contract, and body agree; it calls `0x00574510` from both high-resolution and classic layout branches at `0x00574399` and `0x005743db`.
- `sub_574510` reads the selected list entry, copies `[entry + 4]` into the current/configured server-name buffer at `g_pConfig + 0x2916d0` with capacity `0x10`, and calls `0x005745b0` with the entry id byte and entry pointer.
- `sub_5745B0` writes packet bytes `0x57`, `0`, and selected id through `0x00575380`, queues three bytes through `0x00574bb0`, stores the selected id at `g_pConfig + 0x28d9d8`, and formats the endpoint string from entry bytes `+0x10..+0x13` plus port field `+0x14` when the alternate-path flag at `g_pConfig + 0x28d9dd` is clear.
- The additional call to `0x005745b0` at `0x005745a1` is inside a raw wrapper starting at `0x00574570`, not padding. That wrapper copies the selected entry name through `0x0041b9b0`, then forwards the entry id and entry pointer to `0x005745b0`.
- `ServerSelectMenuItemList::DrawListEntry` at `0x00574670-0x00574748` independently confirms `[entry + 4]` as server name and `[entry + 8]` as description by formatting `"%s : %s"` and copying selected names into application/session display state. The former `DrawListItem` label is retained only as superseded descriptive history.
- Parent evidence: these helpers are contained by the `0x00573d20-0x005747df` ServerSelectPane aggregate, are called by ServerSelectPane action/list code, use server-list entry fields, and write login/server-selection session state. The `ServerSelectPane` parent is therefore strong enough for autogen attachment.

Rechecked with live IDA MCP on 2026-06-16:

- `lookup_funcs` still reports only `0x00574510` (`sub_574510`, size `0x3e`) and `0x005745b0` (`sub_5745B0`, size `0xae`) as modeled starts in this helper strip. Raw starts `0x00574500`, `0x00574550`, `0x00574570`, and `0x00574580` are still not functions.
- `xrefs_to` reports exactly two code xrefs to `0x00574510`, both from the action handler at `0x00574399` and `0x005743db`; it reports exactly two xrefs to `0x005745b0`, the modeled call at `0x00574546` and the raw-wrapper call at `0x005745a1`.
- `xrefs_to` for raw starts `0x00574500`, `0x00574550`, and `0x00574570` returns no direct refs. `find_bytes` also found no direct 32-bit pointer-byte hits for `0x00574500`, `0x00574550`, `0x00574570`, `0x00574510`, or `0x005745b0`, so current evidence does not support a vtable/data-slot reachability claim for the raw wrappers.
- Current decompilation of `0x00574510` names the config singleton as `g_pConfig`: it copies `[entry + 4]` into `g_pConfig + 0x2916d0` / decimal `2692816` (Verified with int_convert.py) with capacity `0x10`, then calls `0x005745b0`.
- Disassembly of `0x005745b0` confirms packet byte `0x57` / decimal `87` (Verified with int_convert.py), zero byte, selected id byte, `0x00574bb0` queue/send of three bytes, selected-id store at `g_pConfig + 0x28d9d8` / decimal `2677208` (Verified with int_convert.py), alternate-path flag check at `g_pConfig + 0x28d9dd` / decimal `2677213` (Verified with int_convert.py), and endpoint formatting through `g_pConfig + 0x291230` / decimal `2691632` (Verified with int_convert.py) using config argument data at `g_pConfig + 0x2912b0` / decimal `2691760` (Verified with int_convert.py) plus entry bytes `+0x10..+0x14`.
- Disassembly of the raw `0x00574570` wrapper shows `push ebp` at `0x00574570`, selected-entry name formatting through `sub_41B9B0`, the call to `0x005745b0` at `0x005745a1`, `retn 4` at `0x005745a9`, and `0xcc` alignment at `0x005745ac-0x005745b0`. The wrapper writes through `g_pApplication + 0x858` / decimal `2136` (Verified with int_convert.py), so the final source field name is still not recovered.
- 2026-06-22 B013 source-quality recheck resolves the preferred source names, confirms no rel32/absolute VA/RVA/pointer route to raw starts `0x00574500`, `0x00574550`, or `0x00574570`, and keeps all helpers with [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md). `0x005745b0` is a file-local server-select packet/state helper, not Socket, PacketBuffer, CashShopRequest, or ProtocolSend source; those are only dependencies.

## Entry Layout Notes

The same layout is visible in the accepted `ServerSelectMenuItemList::DrawListEntry` method:

```text
+0x000  unsigned char serverId / packet byte 2
+0x001  compiler-natural alignment through +0x003
+0x004  wchar_t *name
+0x008  wchar_t *description
+0x00c  wchar_t *agreementText
+0x010  unsigned char address[4]
+0x014  unsigned short port
+0x016  compiler-natural tail alignment through +0x017
```

The containing 0x308-byte `ServerSelectDirectory` lives at `g_pConfig + 0x28db10`, contains 32 stride-`0x18` `ServerSelectEntry` records, stores `entryCount` at directory `+0x300`, and stores `version` at `+0x304`. Registry and packet construction independently prove `agreementText`, address width, unsigned port, and version even though these selection helpers read only the fields needed to display/select an entry.

## Packet Helper Semantics

`SendServerSelectPacket(unsigned int selectedServerId, const ServerSelectEntry *entry)` performs the following source-visible work:

- Writes packet bytes `0x57`, `0`, and `selectedServerId` through [UID:0003YJ][0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers](by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md).
- Queues exactly three bytes through [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) using [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).
- Stores `selectedServerId` at `g_pConfig + 0x28d9d8`.
- If `g_pConfig + 0x28d9dd` is zero, formats `g_pConfig + 0x291230` with the full literal `L"%d.%d.%d.%d.%d.%d"` at `0x00624ee8`, using `g_pConfig + 0x2912b0`, `entry->address[0..3]`, and unsigned-short `entry->port`.

## Formal Source Disposition

- Complete formal source now lives in UID0000D1 rather than as a prose-only draft here. `ApplySelectedServer` uses the observed selected-index guard, current `GetItem`, capacity-16 copy, and member call. `SendServerSelectPacket` is a private nonstatic member with a 16-byte local packet, three-byte send, opcode `0x57`, exact selected-id write, and conditional 64-wide-character endpoint formatting.
- This by-item index intentionally keeps both formal channels blank. It would otherwise duplicate definitions already emitted through UID0000D1 into the same UID0000NO file.
- Historical `ListPane::GetSelectedEntry`, static helper, three-byte local array, unsigned direct port formatting, and blank-until-later source language are superseded. Exact current source uses `GetItem`, member ECX, a 16-byte frame-backed local, and `(short)entry->port` for `%d`.

## Exact Function Frames And Routes

- `ApplySelectedServer` `[0x574510,0x57454e)` has direct callers at `0x574399` and `0x5743db`, both in `ServerSelectPane::OnControlCommand`. Its report-time frame contains only the return-address row. The ignored return and body support source type `void __thiscall(ServerSelectMenuItemList *this)`.
- `SendServerSelectPacket` `[0x5745b0,0x57465e)` has callers at `0x574546` and raw `0x5745a1`. Its exact frame partitions are `Src` byte at `+0xc`, destination byte at `+0xd`, 14-byte tail at `+0xe`, `var_4` at `+0x1c`, saved registers at `+0x20`, return address at `+0x24`, `serverId` at `+0x28`, and `entry` at `+0x2c`. The first three local bytes are sent, while the remaining local capacity is preserved.
- Raw siblings `[0x574500,0x57450e)`, `[0x574550,0x574561)`, and `[0x574570,0x5745ac)` have no modeled function, inbound start xref, rel32 route, or encoded absolute VA/RVA pointer route. The final raw sibling contains the live call at `0x5745a1`; these are complete source-shaped bodies, not padding.
- Exact direct owner remains UID0000D1. Socket, packet-buffer, sender, Config, and Application pages are dependencies, not alternate owners.

## Ownership Decision

These helpers belong with `login/ServerSelectPane.cpp` or as file-local login server-selection helpers. Do not treat `0x00574510` as chat-color code: the call sites, selected entry layout, config buffer target, and packet behavior are all server-selection specific.

## Blocker Investigation

- Owner/emitter: unchanged as [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md). The action-handler xrefs, internal component edge through `0x00574510 -> 0x005745b0`, `ServerSelectMenuItemList` row layout, and `g_pConfig` server-selection state writes all support the login/server-select file owner.
- Raw wrapper boundary: `0x00574570-0x005745a9` is now documented from live disassembly and padding, but it is still not safe to split into a stronger standalone page or IDA function metadata change because the current IDB has no function object, no direct refs to the wrapper start, and no direct pointer-byte hits.
- Field/global names: refreshed evidence uses documented `g_pConfig` and `g_pApplication` names. The canonical `ServerSelectEntry`/`ServerSelectDirectory` declaration is resolved; private field spellings remain high-probability human inference because original symbols were stripped, not a reason to retain offset labels or blank source.
- Final source: resolved through UID0000D1. Raw-wrapper liveness remains explicit negative evidence and a confidence cap, but does not block the complete class-owned definitions. This helper index remains blank only to prevent duplicate output.
- Member/static classification: resolved as nonstatic. Both callers preserve or establish the list object in ECX; a file-local/static declaration would misstate the observed ABI.

## Cross-References

- [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md)
- [UID:0000D2][ServerSelectPane](by-class/ServerSelectPane.md)
- [UID:0000D1][ServerSelectMenuItemList](by-class/ServerSelectMenuItemList.md)
- [UID:0000S8][g_pServerSelectPane](by-global/g_pServerSelectPane.md)

## Changes

- 2026-08-15 B010 UID0003D9 accepted implementation callback:
  - Raised `86/91` to `91/94`, preserved UID0000NO owner/emitter, reconstructable state, and intentionally blank duplicate formal channels.
  - Corrected exclusive ends, hashes, `GetItem` use, member-helper ABI, complete frame partitions, exact callers, raw-sibling route evidence, 16-byte local/three-byte send distinction, and source emission through UID0000D1.
  - Historical static-helper, `GetSelectedEntry`, prose-draft, and unresolved-blank-source assumptions are retained only as corrections and are not current recommendations.

- 2026-08-10 B010 UID0002PA accepted implementation callback:
  - Score, owner/emitter, helper boundaries, xrefs, raw-wrapper policy, and blank formal CPP/H remain unchanged.
  - Completed the canonical entry/directory dependency with `agreementText`, unsigned-short `port`, `entryCount`, and `version`; endpoint source guidance now uses `entry->port` with the exact six-component format.
  - Historical unresolved-dword, port/suffix, explicit reserved-byte, missing-version, and generic selected-entry assumptions remain below as dated history and no longer block the dependency model.

- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with moderate completion and strong confidence, while parent attachment and C++ remain blank.
- Summary and evidence: IDA MCP verification on 2026-05-31 reconfirmed both helper boundaries, callers, callees, packet bytes, selected-server state writes, and the remaining near-boundary xref caveat. The score remains below 95 because final helper names, entry structure names, and login-state field names are not fully audited.
- Historical 2026-06-03 update: live IDA MCP rechecked the two modeled helper ranges, the two callsites now identified as `OnControlCommand` at `0x00574399/0x005743db`, selected-entry name copy, `0x57` packet emission, selected-id/session writes, endpoint formatting fields, the then-descriptive `DrawListItem` entry layout now accepted as `DrawListEntry`, and the raw `0x00574570-0x005745ac` wrapper containing the `0x005745a1` call. Completion increased from 70 to 84 and confidence from 85 to 90 because the owner, packet behavior, entry layout, and raw-wrapper caveat were documented from then-current IDA evidence and the item was safely attached to `ServerSelectPane`. The historical score remained below 95 because final source helper names and login-state field names were not yet proven.
- Historical caller-name correction: `OnDialogAction(int)` was an earlier descriptive label. The inherited primary slot, argument count, `retn 8`, and complete class declaration support `OnControlCommand(int controlIndex, int notifyCode)`; the old name is retained only as rejected history.
- 2026-06-16 A002 Goal 2 refresh: raised from `84/90` to `86/91`.
  - Evidence: live IDA MCP session `b001_selflookpane_0001H7_20260616` reconfirmed the modeled helper starts, raw non-function starts, action-handler/helper xrefs, raw-wrapper body and alignment, no direct refs or pointer-byte hits for raw starts, `g_pConfig`-named state accesses, verified config/session offsets, `0x57` select-server packet bytes, endpoint formatting arguments, and the remaining source-quality blockers.
  - IDA DB changes: none. Defining or renaming the raw wrapper was skipped because current reachability evidence does not prove a stable source-facing symbol or function object.
- 2026-06-22 B013 Rule 26 support sync:
  - Score unchanged at `86/91`.
  - Incorporated preferred helper names, full `ServerSelectEntry`/`ServerSelectDirectory` layout, packet opcode `0x57` write/send/store/format semantics, `g_pApplication + 0x858` display-state behavior, exact `0x00624ee8` format literal, and the rejected owner alternatives for Socket/PacketBuffer/chat/list-generic routing.
