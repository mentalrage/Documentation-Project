*** UID:0000RE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pLoginDialogPane

## Status

- Confidence: strong for singleton address and class owner.
- Address: `0x0069b484`
- Exact memory range: [UID:00029H][0x0069b480-0x0069b490.MainMenuAccountDialogSingletons](by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md)
- Owner class: [UID:00007F][LoginDialogPane](by-class/LoginDialogPane.md)
- Likely owner source: [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)

## Symbol Role

`g_pLoginDialogPane` stores the active pre-login login dialog instance. It is written by the `LoginDialogPane` constructor, cleared by login-dialog teardown support, read by [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) before opening a duplicate login dialog, read by [UID:0000PH][CloseMainMenuDialogSingletons_4F69A0](by-global/CloseMainMenuDialogSingletons_4F69A0.md), and read by [UID:0000PL][EnsureLoginDialogPane_4F8B30](by-global/EnsureLoginDialogPane_4F8B30.md).

## Evidence Notes

- IDA MCP `xrefs_to 0x0069b484` shows reads from `CloseMainMenuDialogSingletons_4F69A0`, `MainMenuPane::ActivateMenuItem`, `EnsureLoginDialogPane_4F8B30`, and other login-helper paths.
- Constructor references at `0x004fa801` and `0x004fa808` write the singleton.
- Teardown support includes a singleton clear helper at `0x005023c0` and destructor clear in the `0x005027d0` range.
- Current `simroot_v2/class_LoginDialogPane.cpp` sets `g_pLoginDialogPane = this` in `LoginDialogPane::LoginDialogPane` and clears it in `LoginDialogPane::ScalarDeletingDestructor`.
- Current `class_LoginDialogPane.cpp.source_map.json` maps those constructor/destructor references to method code ranges, but its `global-data:g_pLoginDialogPane` entry is unresolved and has no memory ranges. Treat the exact `0x0069b484-0x0069b488` storage as IDA-backed memory documentation evidence, not a current Wave3 source-map binding.
- Current `class_LoginDialogPane.meta_wave3` lists `g_pLoginDialogPane` in the active `global_data` partition, but without a type or resolved memory range. The aggregate account-dialog singleton page links it with neighboring `NewUserDialogPane`, `NewUserMiscDialogPane`, and `ChangePasswordDialogPane` singletons.

## Open Questions

- Final ownership of the small `0x005023c0` singleton clear helper should be reviewed with the login-dialog destructor/thunk family before source migration.

## Cross-References

- [UID:00007F][LoginDialogPane](by-class/LoginDialogPane.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- [UID:0000PL][EnsureLoginDialogPane_4F8B30](by-global/EnsureLoginDialogPane_4F8B30.md)
- [UID:0000PH][CloseMainMenuDialogSingletons_4F69A0](by-global/CloseMainMenuDialogSingletons_4F69A0.md)
- [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md)
- [UID:00029H][0x0069b480-0x0069b490.MainMenuAccountDialogSingletons](by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md)

## Changes

### 2026-05-30 completion/confidence evidence pass

- What existed before: the page had `0` completion/confidence values and did not link the exact aggregate memory page for the singleton storage.
- What changed: completion/confidence were raised to `82/84`, the aggregate singleton memory page was added, and evidence now records current generated constructor/destructor references plus the unresolved Wave3 global-data memory-range caveat.
- Summary and evidence: existing IDA-backed notes and [UID:00029H][0x0069b480-0x0069b490.MainMenuAccountDialogSingletons](by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md) establish `0x0069b484` and the main-menu account-dialog singleton cluster. Current simroot/source-map evidence confirms constructor/destructor lifecycle references, but the active `global-data:g_pLoginDialogPane` metadata is unresolved and lacks type/range data, so completion/confidence remain below the fully resolved global pages.
