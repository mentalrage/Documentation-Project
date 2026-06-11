*** UID:0000RE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pLoginDialogPane

## Status

- Confidence: strong for singleton address, class owner, and split storage child.
- Address: `0x0069b484`
- Exact memory range: [UID:0002XI][0x0069b484-0x0069b488.g_pLoginDialogPane](by-memory/0x0069b484-0x0069b488.g_pLoginDialogPane.md)
- Account-dialog aggregate: [UID:00029H][0x0069b480-0x0069b490.MainMenuAccountDialogSingletons](by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md)
- Owner class: [UID:00007F][LoginDialogPane](by-class/LoginDialogPane.md)
- Likely owner source: [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)

## Symbol Role

`g_pLoginDialogPane` stores the active pre-login login dialog instance. It is written by the `LoginDialogPane` constructor, cleared by login-dialog teardown support, read by [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) before opening a duplicate login dialog, read by [UID:0000PH][CloseMainMenuDialogSingletons_4F69A0](by-global/CloseMainMenuDialogSingletons_4F69A0.md), and read by [UID:0000PL][EnsureLoginDialogPane_4F8B30](by-global/EnsureLoginDialogPane_4F8B30.md).

## Evidence Notes

- IDA MCP `xrefs_to 0x0069b484` shows reads from `CloseMainMenuDialogSingletons_4F69A0`, `MainMenuPane::ActivateMenuItem`, `EnsureLoginDialogPane_4F8B30`, and other login-helper paths.
- Constructor references at `0x004fa801` and `0x004fa808` write the singleton.
- Teardown support includes a singleton clear helper at `0x005023c0` and destructor clear in the `0x005027d0` range.
- Live IDA MCP decompilation confirms constructor `0x004fa7a0`, singleton clear helper `0x005023c0`, and scalar deleting destructor `0x005027d0` write/clear `dword_69B484`. The aggregate account-dialog singleton page links it with neighboring `NewUserDialogPane`, `NewUserMiscDialogPane`, and `ChangePasswordDialogPane` singletons.
- Batch 042 split page [UID:0002XI][0x0069b484-0x0069b488.g_pLoginDialogPane](by-memory/0x0069b484-0x0069b488.g_pLoginDialogPane.md) now documents the exact one-dword storage item, initialized value `0xffffffff`, all twelve direct refs, and the corrected parent gate.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `85` | The page records canonical symbol name, exact address, exact split memory child, owner class/file, constructor/fallback writes, cleanup/destructor clears, main-menu/ensure consumers, aggregate context, and remaining helper/source-placement caveat. |
| Confidence `86` | Confidence is supported by IDA-backed xrefs, the exact split memory child, LoginDialogPane core evidence, and the file parent [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md) at `88/86`. It stays below final-audit range because the tiny clear helper and final declaration placement still need source-quality migration review. |

## Open Questions

- Final ownership of the small `0x005023c0` singleton clear helper should be reviewed with the login-dialog destructor/thunk family before source migration.

## Cross-References

- [UID:00007F][LoginDialogPane](by-class/LoginDialogPane.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- [UID:0000PL][EnsureLoginDialogPane_4F8B30](by-global/EnsureLoginDialogPane_4F8B30.md)
- [UID:0000PH][CloseMainMenuDialogSingletons_4F69A0](by-global/CloseMainMenuDialogSingletons_4F69A0.md)
- [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md)
- [UID:0002XI][0x0069b484-0x0069b488.g_pLoginDialogPane](by-memory/0x0069b484-0x0069b488.g_pLoginDialogPane.md)
- [UID:00029H][0x0069b480-0x0069b490.MainMenuAccountDialogSingletons](by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md)

## Changes

### 2026-05-30 completion/confidence evidence pass

- What existed before: the page had `0` completion/confidence values and did not link the exact aggregate memory page for the singleton storage.
- What changed: completion/confidence were raised to `82/84`, the aggregate singleton memory page was added, and evidence now records constructor/destructor/clear-helper references.
- Summary and evidence: existing IDA-backed notes and [UID:00029H][0x0069b480-0x0069b490.MainMenuAccountDialogSingletons](by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md) establish `0x0069b484` and the main-menu account-dialog singleton cluster. Completion/confidence remain below the fully resolved global pages because the small clear helper and final account-dialog split still need migration review.
- 2026-06-05: Marked reconstructable under [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md). Evidence: live IDA MCP reports 12 xrefs to `0x0069b484`; decompilation confirms `0x004fa7a0`, `0x005023c0`, and `0x005027d0` write/clear `dword_69B484`.
- 2026-06-07 A002 Batch 042 parent-gate refresh:
  - What existed before: `COMPLETION:82`, `CONFIDENCE:84`, and the exact memory evidence was only linked through the mixed account-dialog aggregate.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:86`, with exact memory child [UID:0002XI][0x0069b484-0x0069b488.g_pLoginDialogPane](by-memory/0x0069b484-0x0069b488.g_pLoginDialogPane.md).
  - Summary/evidence: the split child records exact one-dword storage, initialized value, all twelve lifecycle/consumer refs, and the strict direct-parent gate. This page now clears the `85/85` gate for child [UID:0002XI][0x0069b484-0x0069b488.g_pLoginDialogPane](by-memory/0x0069b484-0x0069b488.g_pLoginDialogPane.md) while remaining capped below final-source quality by helper/declaration-placement caveats.
