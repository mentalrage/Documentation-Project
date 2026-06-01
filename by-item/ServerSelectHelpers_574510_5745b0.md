*** UID:0000VG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ServerSelectHelpers_574510_5745b0

## Status

- Confidence: strong for server-select ownership, medium for final helper names.
- Current Wave3 state: `0x00574510` is mis-owned as `ChattingColorListPane::ApplySelectedColor`; `0x005745b0` is not modeled as a Wave3 method in current data.
- Proposed owner file: [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md)
- Exact memory range: [UID:0001HR][0x00573d20-0x005747df.ServerSelectPane](by-memory/0x00573d20-0x005747df.ServerSelectPane.md)
- Rebuild handling: `source-authored` login/server-selection helpers. Marked reconstructable, but parent attachment and C++ are blank until the server-entry struct, login state fields, and packet helper names are near-final.

## Helper Summary

| Address range | Proposed name | Behavior |
| --- | --- | --- |
| `0x00574510-0x0057454d` | `ApplySelectedServer` / `ApplyServerSelection` | Reads the selected server-list entry, copies its name into the configured/current server-name buffer, then forwards the entry id and entry pointer to `0x005745b0`. |
| `0x005745b0-0x0057465d` | `SendServerSelectPacket` / `ApplyServerEndpoint` | Builds and sends a three-byte server-select packet, stores the selected server id in application/session state, and formats the endpoint string when the client is not already connected through the alternate path. |

## IDA MCP Evidence

Checked on 2026-05-24:

- `lookup_funcs` confirms `0x00574510` as a real function of size `0x3e`, and `0x005745b0` as a real function of size `0xae`.
- `xrefs_to 0x00574510` reports only code xrefs from `ServerSelectPane::OnDialogAction` at `0x00574399` and `0x005743db`, covering the high-resolution and classic layout branches.
- `xrefs_to 0x005745b0` reports the direct call from `0x00574510` at `0x00574546`; the additional raw ref at `0x005745a1` is just before the function body and needs boundary review.
- Decompilation of `0x00574510` copies the selected entry name from `[entry + 4]` into the config/current-server buffer at `dword_67A7C8 + 2692816` with capacity `0x10`, then calls `0x005745b0` with the entry id byte and entry pointer.
- Decompilation of `0x005745b0` emits packet bytes `0x57`, `0`, and the selected id through the packet helper at `0x00574bb0`, writes the selected id to `dword_67A7C8 + 2677208`, and formats an endpoint string from application state plus entry address bytes/port fields when the flag at `dword_67A7C8 + 2677213` is clear.
- 2026-05-31 IDA MCP recheck reports `0x00574510` as `sub_574510` with exclusive end `0x0057454e` and direct callsites at `0x00574399` and `0x005743db`; its callees are selected-entry access, `_wcscpy_s`, and `0x005745b0`.
- 2026-05-31 IDA MCP recheck reports `0x005745b0` as `sub_5745B0` with exclusive end `0x0057465e`; it is called by `0x00574510` and the near-boundary code ref at `0x005745a1`, writes packet bytes with `0x00575380`, sends through `0x00574bb0`, and updates `dword_67A7C8` session/config fields.

## Entry Layout Notes

The same layout is visible in `ServerSelectMenuItemList::DrawListItem`:

```text
+0x000  server id / first byte used by selection packet
+0x004  wchar_t* server name
+0x008  wchar_t* server description
+0x010  endpoint bytes used by 0x005745b0
+0x014  endpoint port or suffix field used by 0x005745b0
```

## Ownership Decision

These helpers belong with `login/ServerSelectPane.cpp` or as file-local login server-selection helpers. Do not migrate `0x00574510` as chat-color code: the call sites, selected entry layout, config buffer target, and packet behavior are all server-selection specific.

## Cross-References

- [UID:0000NO][ServerSelectPane](by-file/ServerSelectPane.md)
- [UID:0000D2][ServerSelectPane](by-class/ServerSelectPane.md)
- [UID:0000D1][ServerSelectMenuItemList](by-class/ServerSelectMenuItemList.md)
- [UID:0000S8][g_pServerSelectPane](by-global/g_pServerSelectPane.md)
- [UID:00001S][ChattingColorListPane](by-class/ChattingColorListPane.md)

## Changes

- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with moderate completion and strong confidence, while parent attachment and C++ remain blank.
- Summary and evidence: IDA MCP verification on 2026-05-31 reconfirmed both helper boundaries, callers, callees, packet bytes, selected-server state writes, and the remaining near-boundary xref caveat. The score remains below 95 because final helper names, entry structure names, and login-state field names are not fully audited.
