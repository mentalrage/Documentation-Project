*** UID:0002XJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ClanBankPane *g_pClanBankPane;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pClanBankPane

## Status

- Address: `0x0067ade8`
- Storage page: [UID:0002XK][0x0067ade8-0x0067adec.g_pClanBankPane](by-memory/0x0067ade8-0x0067adec.g_pClanBankPane.md)
- Type hypothesis: `ClanBankPane *`
- Owner: [UID:0000I9][ClanBank](by-file/ClanBank.md)
- Current storage state: zero-filled virtual `.data`; [UID:0002XK][0x0067ade8-0x0067adec.g_pClanBankPane](by-memory/0x0067ade8-0x0067adec.g_pClanBankPane.md) is marker-only storage proof, and this page emits the single source definition `ClanBankPane *g_pClanBankPane;`.
- Current IDB/source-name state: no IDB source symbol is named at `0x0067ade8`; raw `unk_67ADE8`/`dword_67ADE8` labels are evidence-only and must not replace the source-facing `g_pClanBankPane`.

## Evidence

The mixed-range audit records 7 xrefs for this slot. [UID:000026][ClanBankPane](by-class/ClanBankPane.md) documents the constructor store, destructor-family clears, and checks before opening/routing clan-bank UI actions. B014 2026-06-22 direct PE review identifies `0x0048c260-0x0048c26b` as the exact compiler cleanup helper that clears this singleton slot; it should not be emitted as a source method.

2026-07-07 B007 current MCP recheck used session `supervisor-nexustk-20260707` and reconfirmed current zero storage at `0x0067ade8` plus exactly seven refs: constructor publish/fallback clear at `0x0048b224`/`0x0048b22b`, vtable-reset/destructor clear at `0x0048b61a`, cleanup-helper clear at `0x0048c260`, scalar-deleting destructor clear at `0x0048c430`, and duplicate-open/action guard reads at `0x00508706` and `0x00513b07`. Successor `0x0067adec` has zero xrefs and no address-literal matches, and the generated `ClanBank.cpp` route keeps this global as the only emitted `ClanBankPane *g_pClanBankPane;` definition with no standalone UID0002XK block.

## Assignment Gate

Assigned to [UID:0000I9][ClanBank](by-file/ClanBank.md), now `90/89`. The relationship is direct because this global stores the ClanBankPane singleton and owns the source definition while the exact by-memory child remains marker-only storage evidence.

## Cross-References

- [UID:0000I9][ClanBank](by-file/ClanBank.md)
- [UID:000026][ClanBankPane](by-class/ClanBankPane.md)
- [UID:00010R][0x0048b1c0-0x0048b7dc.ClanBankPane](by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md)
- [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md)

## Changes

- 2026-07-07 B007 UID0002XK implementation callback: raised `COMPLETION:86` / `CONFIDENCE:89` to `88/91`, kept owner/emitter [UID:0000I9][ClanBank](by-file/ClanBank.md), kept the formal C++ as `ClanBankPane *g_pClanBankPane;`, and refreshed evidence for zero storage, seven refs, zero successor refs, no IDB source name, and marker-only [UID:0002XK][0x0067ade8-0x0067adec.g_pClanBankPane](by-memory/0x0067ade8-0x0067adec.g_pClanBankPane.md) storage.
- 2026-06-30 B009 empty-emitter implementation callback: inserted the accepted source-level declaration `ClanBankPane *g_pClanBankPane;`. The exact storage child [UID:0002XK][0x0067ade8-0x0067adec.g_pClanBankPane](by-memory/0x0067ade8-0x0067adec.g_pClanBankPane.md) remains marker-only because this global page owns the emitted definition.
- 2026-06-07 A008 Batch 037 split: created as the canonical global page for the ClanBankPane singleton.
- 2026-06-22 B014 ClanDestructorBand support sync: added cleanup helper `0x0048c260-0x0048c26b` as lifecycle evidence; score and owner/emitter unchanged.
