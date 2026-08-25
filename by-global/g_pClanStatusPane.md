*** UID:0002XG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ClanStatusPane *g_pClanStatusPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pClanStatusPane

## Status

- Address: `0x0067ade4`
- Storage page: [UID:0002XH][0x0067ade4-0x0067ade8.g_pClanStatusPane](by-memory/0x0067ade4-0x0067ade8.g_pClanStatusPane.md)
- Type hypothesis: `ClanStatusPane *`
- Owner: [UID:0000I8][Clan](by-file/Clan.md)
- Source placement: canonical by-global declaration emitted through [UID:0000I8][Clan](by-file/Clan.md) into `NexusTK/social/Clan.cpp`; the exact by-memory storage child is marker-only evidence.

## Evidence

The mixed-range audit records 15 xrefs for this slot. [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md) documents the constructor store, cleanup/destructor clears, and clan status helper reads for row actions, list dialogs, and packet routing. B014 2026-06-22 direct PE review identifies `0x0048c270-0x0048c27b` as the exact compiler cleanup helper that clears this singleton slot; it should not be emitted as a source method.

2026-07-07 B011 current MCP recheck used session `supervisor-nexustk-20260707` against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; server health was `ok`, auto-analysis and Hex-Rays were ready, and the strings cache was ready. `get_bytes 0x0067ade4 size 4` returned `00 00 00 00`, and `get_global_value 0x0067ade4` returned `0x0`. The same pass reconfirmed 15 live xrefs: constructor publish/fallback clear at `0x00484079` and `0x00484080`, constructor-cleanup clear at `0x0048429d`, ten status/list/dialog helper reads, cleanup-helper clear at `0x0048c270`, and destructor clear at `0x0048c600`.

This global page now emits the single source declaration `ClanStatusPane *g_pClanStatusPane = NULL;`. The exact storage child [UID:0002XH][0x0067ade4-0x0067ade8.g_pClanStatusPane](by-memory/0x0067ade4-0x0067ade8.g_pClanStatusPane.md) is marker-only source-declared/generated-binary storage evidence. Raw IDA labels such as `unk_67ADE4` or `dword_67ADE4` are evidence-only and must not be used in final source.

## Assignment Gate

Assigned to [UID:0000I8][Clan](by-file/Clan.md), now `90/85`. The relationship is direct because this global stores the ClanStatusPane singleton.

## Score Rationale

- Completion is `88` because this canonical global page now owns the emitted singleton declaration, links the exact storage child, and records current zero storage, 15 xrefs, constructor/destructor/helper evidence, cleanup-helper no-source disposition, and source-route rationale.
- Confidence is `92` because live MCP and current support docs agree on null storage, xref roles, and `NexusTK/social/Clan.cpp` ownership. It remains below final-audit range because no recovered source/header proves whether the original used explicit null initialization versus an omitted initializer.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md)
- [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md)
- [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md)

## Changes

- 2026-07-07 B011 implementation callback: raised `86/89` to `88/92`, moved the singleton declaration from [UID:0002XH][0x0067ade4-0x0067ade8.g_pClanStatusPane](by-memory/0x0067ade4-0x0067ade8.g_pClanStatusPane.md) to this canonical by-global page, recorded current MCP zero-byte/global-value and 15-xref evidence, and documented that UID0002XH is marker-only storage proof.
- 2026-06-30 B007 implementation callback: populated the route-only formal block with `[[CHILDREN]]`, preserved this page as the canonical global route, and recorded current zero-filled MCP evidence while assigning the single source definition to [UID:0002XH][0x0067ade4-0x0067ade8.g_pClanStatusPane](by-memory/0x0067ade4-0x0067ade8.g_pClanStatusPane.md).
- 2026-06-07 A008 Batch 037 split: created as the canonical global page for the ClanStatusPane singleton.
- 2026-06-22 B014 ClanDestructorBand support sync: added cleanup helper `0x0048c270-0x0048c27b` as lifecycle evidence; score and owner/emitter unchanged.
