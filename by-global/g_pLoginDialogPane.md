*** UID:0000RE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pLoginDialogPane

## Status

- Confidence: very strong for singleton address/type, zero initialization, class/file owner, exact storage child, source ordering, twelve-reference lifecycle, and MainMenu/ensure consumers. Original declaration spelling is now represented through the exact storage child.
- Address: `0x0069b484`
- Exact memory range: [UID:0002XI][0x0069b484-0x0069b488.g_pLoginDialogPane](by-memory/0x0069b484-0x0069b488.g_pLoginDialogPane.md)
- Account-dialog aggregate: [UID:00029H][0x0069b480-0x0069b490.MainMenuAccountDialogSingletons](by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md)
- Owner class: [UID:00007F][LoginDialogPane](by-class/LoginDialogPane.md)
- Owner source: [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md), position 0 before the class/method children.

## Symbol Role

`g_pLoginDialogPane` stores the active pre-login login dialog instance. It is written by the `LoginDialogPane` constructor, cleared by login-dialog teardown support, read by [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) before opening a duplicate login dialog, read by [UID:0000PH][CloseMainMenuDialogSingletons_4F69A0](by-global/CloseMainMenuDialogSingletons_4F69A0.md), and read by [UID:0000PL][EnsureLoginDialogPane_4F8B30](by-global/EnsureLoginDialogPane_4F8B30.md).

`g_pLoginDialogPane` is read by source helper [UID:00019L][0x004f8b30-0x004f8b8d.EnsureLoginDialogPane](by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md) before login-dialog creation. The helper relies on [UID:0002Q4][0x004fa7a0-0x004fb2d0.LoginDialogPaneCore](by-memory/0x004fa7a0-0x004fb2d0.LoginDialogPaneCore.md) to publish or clear the singleton; it does not assign this global directly. [UID:0000PL][EnsureLoginDialogPane_4F8B30](by-global/EnsureLoginDialogPane_4F8B30.md) is the recovered-symbol alias for that exact helper.

## Evidence Notes

- IDA MCP `xrefs_to 0x0069b484` shows reads from `CloseMainMenuDialogSingletons_4F69A0`, `MainMenuPane::ActivateMenuItem`, `EnsureLoginDialogPane_4F8B30`, and other login-helper paths.
- Constructor references at `0x004fa801` and `0x004fa808` write the singleton.
- Teardown support includes a singleton clear helper at `0x005023c0` and destructor clear in the `0x005027d0` range.
- Live IDA MCP decompilation confirms constructor `0x004fa7a0`, singleton clear helper `0x005023c0`, and scalar deleting destructor `0x005027d0` write/clear `dword_69B484`. The aggregate account-dialog singleton page links it with neighboring `NewUserDialogPane`, `NewUserMiscDialogPane`, and `ChangePasswordDialogPane` singletons.
- Batch 042 split page [UID:0002XI][0x0069b484-0x0069b488.g_pLoginDialogPane](by-memory/0x0069b484-0x0069b488.g_pLoginDialogPane.md) is the exact one-dword storage emitter. Resumed sessions `3fc1dcef` and `9df6e9a0` each returned zero bytes for the checked singleton block, superseding the historical target-slot `0xffffffff` claim while preserving UID00029H's separately session-qualified sibling evidence.
- Live IDA MCP on 2026-06-14 rechecked all twelve direct refs: `0x004f69b0`, `0x004f7a56`, `0x004f7ae5`, `0x004f7c68`, `0x004f8b53`, `0x004f8fcc`, `0x004f91fc`, `0x004fa801`, `0x004fa808`, `0x004faaff`, `0x005023c0`, and `0x00502802`. The constructor at `0x004fa7a0` is a `0x32d`-byte, 813 decimal byte (Verified with int_convert.py), login-dialog constructor reached from `MainMenuPane::ActivateMenuItem` and `EnsureLoginDialogPane_4F8B30`; the tiny clear helper at `0x005023c0` and scalar deleting destructor at `0x005027d0` remain the teardown clear paths.
- Ref classification is exact: MainMenu cleanup/activation and retained openers read or clear the slot; EnsureLoginDialogPane is a duplicate-open guard; constructor UID0004PJ publishes/fallback-clears; cleanup UID0004PN, compact helper `0x005023c0`, and destructor UID0004PU clear it. No alternative writer/type/file owner was found.
- Source route is two-level by design: this by-global page owns declaration ordering and `[[CHILDREN]]`; exact storage UID0002XI emits `class LoginDialogPane; LoginDialogPane *g_pLoginDialogPane = NULL;` through this page into LoginDialogPane.cpp. The global page does not duplicate the definition.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `92` | Exact symbol/type/address, zero initializer, storage child, twelve-reference lifecycle, owner/file/position, two-level emission route, compiler/source split, historical correction, and formal `[[CHILDREN]]` block are resolved. |
| Confidence `94` | Repeated bounded bytes, exact refs, constructor/cleanup/destructor behavior, current class/file docs, and generated route are very strong; stripped original declaration formatting alone remains below final certainty. |
| Parent [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md) | Global `92/94` emits at position 0 through the LoginDialogPane.cpp file root; exact storage UID0002XI supplies the one source definition. |

## Open Questions

- None blocking this global. The small `0x005023c0` clear helper remains compiler/lifecycle support evidence and does not require a second global definition or change the exact destructor source.

## Cross-References

- [UID:00007F][LoginDialogPane](by-class/LoginDialogPane.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- [UID:0000PL][EnsureLoginDialogPane_4F8B30](by-global/EnsureLoginDialogPane_4F8B30.md)
- [UID:0000PH][CloseMainMenuDialogSingletons_4F69A0](by-global/CloseMainMenuDialogSingletons_4F69A0.md)
- [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md)
- [UID:0002XI][0x0069b484-0x0069b488.g_pLoginDialogPane](by-memory/0x0069b484-0x0069b488.g_pLoginDialogPane.md)
- [UID:00029H][0x0069b480-0x0069b490.MainMenuAccountDialogSingletons](by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md)

## Changes

- 2026-07-14 B005 UID0002Q4 callback: raised `86/89` to `92/94`, preserved canonical owner/emitter UID0000KX, set emitter position 0, and applied the exact `[[CHILDREN]]` formal block. Sessions `3fc1dcef` and `9df6e9a0` read zero across `0x0069b480-0x0069b490`; exact storage UID0002XI therefore emits the null-initialized external pointer. Preserved all twelve refs, constructor publish/fallback, cleanup/helper/destructor clears, MainMenu/ensure consumers, aggregate context, historical `0xffffffff` correction, source/compiler split, and rejected duplicate-definition/alternate-owner routes.

### 2026-05-30 completion/confidence evidence pass

- What existed before: the page had `0` completion/confidence values and did not link the exact aggregate memory page for the singleton storage.
- What changed: completion/confidence were raised to `82/84`, the aggregate singleton memory page was added, and evidence now records constructor/destructor/clear-helper references.
- Summary and evidence: existing IDA-backed notes and [UID:00029H][0x0069b480-0x0069b490.MainMenuAccountDialogSingletons](by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md) establish `0x0069b484` and the main-menu account-dialog singleton cluster. Completion/confidence remain below the fully resolved global pages because the small clear helper and final account-dialog split still need migration review.
- 2026-06-05: Marked reconstructable under [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md). Evidence: live IDA MCP reports 12 xrefs to `0x0069b484`; decompilation confirms `0x004fa7a0`, `0x005023c0`, and `0x005027d0` write/clear `dword_69B484`.
- 2026-06-07 A002 Batch 042 parent-gate refresh:
  - What existed before: `COMPLETION:82`, `CONFIDENCE:84`, and the exact memory evidence was only linked through the mixed account-dialog aggregate.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:86`, with exact memory child [UID:0002XI][0x0069b484-0x0069b488.g_pLoginDialogPane](by-memory/0x0069b484-0x0069b488.g_pLoginDialogPane.md).
  - Summary/evidence: the split child records exact one-dword storage, initialized value, all twelve lifecycle/consumer refs, and the strict direct-parent gate. This page now clears the `85/85` gate for child [UID:0002XI][0x0069b484-0x0069b488.g_pLoginDialogPane](by-memory/0x0069b484-0x0069b488.g_pLoginDialogPane.md) while remaining capped below final-source quality by helper/declaration-placement caveats.
- 2026-06-14 A003 score refresh:
  - Before: `85/86`; the target page lagged behind the exact storage child and did not cite a current twelve-ref recheck.
  - Changed to: `86/89`, retaining [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md) as canonical owner/emitter and keeping reconstruction C++ blank.
  - Summary/evidence: live IDA MCP rechecked all twelve direct refs to `0x0069b484`, constructor `0x004fa7a0`, clear helper `0x005023c0`, and scalar deleting destructor `0x005027d0`. Final declaration placement and clear-helper migration remain the blockers below final code entry.
- 2026-06-20 B001 EnsureLoginDialogPane source-quality sync:
  - Score unchanged at `86/89`.
  - Summary/evidence: [UID:00019L][0x004f8b30-0x004f8b8d.EnsureLoginDialogPane](by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md) now emits first-draft `EnsureLoginDialogPane()` and records this global as a duplicate-open guard only. The helper does not store to `g_pLoginDialogPane`; constructor and cleanup/destructor paths remain the singleton write/clear authorities.
