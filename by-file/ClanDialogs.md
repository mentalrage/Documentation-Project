*** UID:0000IA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ClanDialogs

## Status

- Confidence: strong for the modal-dialog function island, vtable anchors, layouts, and packet submitters; medium-high for final source split from [UID:0000I8][Clan](by-file/Clan.md).
- Proposed module: `NexusTK/ui/dialogs/ClanDialogs.cpp` as the current split candidate from [UID:0000I8][Clan](by-file/Clan.md).
- Proposed header: `NexusTK/ui/dialogs/ClanDialogs.h`, or declarations folded into `NexusTK/social/Clan.h` if the final source layout keeps the modal dialogs feature-owned.
- Evidence basis: live IDA MCP checks on 2026-06-04, plus the existing layout/vtable memory docs and `by-project-structure/proposed-source-tree.md`.
- Layout docs: [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md)

## File Role

`ClanDialogs.cpp` is the current split-candidate home for clan modal dialogs and submitters: name/money/member input dialogs, attribute-change dialogs, enlist/change/leave confirmation flows, and their small opcode `0x4b` packet submitters.

The current stronger owner is [UID:0000I8][Clan](by-file/Clan.md), because the same cluster shares clan status pane state, child list panes, resources, packet helpers, and destructor bands. Treat this page as a split candidate, not a committed migration target.

Do not fold the clan bank/item dialogs into this page by default. Those dialogs are larger and currently have a stronger split case in [UID:0000I9][ClanBank](by-file/ClanBank.md).

## Candidate Contents

| Entity | Range / anchors | Role |
| --- | --- | --- |
| `ClanNameInputDialog` | `0x00488b40-0x00488fa0`; vtables `0x006158f8`, `0x0061595c`, `0x0061598c` | Shared `DLGCLAN1.EPF` modal input shell for clan name/money/text flows. |
| `ClanDepMoneyInputDialog` | raw constructor [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md); submitter [UID:0002NS][0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney](by-memory/0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney.md); vtables `0x00615998`, `0x006159fc`, `0x00615a2c` | Deposit-money dialog variant. |
| `ClanWidMoneyInputDialog` | raw constructor [UID:0002NT][0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor](by-memory/0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor.md); submitter [UID:0002NU][0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney](by-memory/0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney.md); vtables `0x00615a38`, `0x00615a9c`, `0x00615acc` | Withdraw-money dialog variant. |
| `ClanExpelNameInputDialog` | raw constructor [UID:0002NV][0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor](by-memory/0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor.md); submitter [UID:0002NW][0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName](by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md); vtables `0x00615ad8`, `0x00615b3c`, `0x00615b6c` | Expel-member-by-name dialog variant. |
| `ClanSummonNameInputDialog` | raw constructor [UID:0002NX][0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor](by-memory/0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor.md); submitter [UID:0002NY][0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName](by-memory/0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName.md); vtables `0x00615b78`, `0x00615bdc`, `0x00615c0c` | Summon-member-by-name dialog variant. |
| `ClanAppearNameInputDialog` | raw constructor [UID:0002NZ][0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor](by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md); submitter [UID:0002O0][0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName](by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md); vtables `0x00615c18`, `0x00615c7c`, `0x00615cac` | Appearance/name action dialog variant. |
| `ClanChangeNameInputDialog` | raw constructor [UID:0002O1][0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor](by-memory/0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor.md); submitter [UID:0002O2][0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName](by-memory/0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName.md); vtables `0x00615cb8`, `0x00615d1c`, `0x00615d4c` | Clan rename dialog variant. |
| `ClanAttrInputDialog` | `0x00489600-0x00489f80`; vtables `0x00615d58`, `0x00615dbc`, `0x00615dec` | Shared `DLGCLAN2.EPF` multi-field attribute input shell. |
| `ClanEnlistInputDialog` | raw constructor [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md), parser/handlers and submitter [UID:0002O3][0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment](by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment.md); vtables `0x00615df8`, `0x00615e5c`, `0x00615e8c` | Enlistment attribute dialog submit path plus related clan packet handling. |
| `ClanChangeInputDialog` | raw constructor [UID:0002O4][0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor](by-memory/0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md); submitter [UID:0002O5][0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange](by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange.md); vtables `0x00615e98`, `0x00615efc`, `0x00615f2c` | Clan attribute-change submit path through helper `0x00486330`. |
| `ClanLeaveConfirmDialog` | raw constructor [UID:0002O6][0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor](by-memory/0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor.md); callbacks [UID:0002O7][0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm](by-memory/0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm.md) and [UID:0002O8][0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel](by-memory/0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel.md); vtables `0x00615f38`, `0x00615fa0`, `0x00615fd0` | Alert-derived leave confirmation dialog. |

## Boundary Notes

- IDA reports no function at the projected constructor starts `0x00488fa0`, `0x00489070`, `0x00489140`, `0x00489270`, `0x004893a0`, `0x004894d0`, `0x00489f80`, `0x00489ff0`, or `0x0048a060`; the bytes are still constructor-shaped raw ranges and should not be discarded.
- The vtable records above are stronger class identity anchors than the projected constructor starts.
- 2026-05-27 IDA MCP family pass found no inbound xrefs or raw dword pointer hits for those projected constructor starts. The bytes are still constructor-shaped and contain base-constructor calls plus derived vtable stores, so they should be modeled as unresolved constructor-boundary bytes rather than thrown away or treated as confirmed callable starts.
- The `0x0048c260-0x0048c341` destructor/thunk band is layout support for these dialogs and `ClanStatusPane`, but compiler-emitted adjustor thunks should not be rewritten as source methods.
- `ClanNameInputDialog` uses inherited control host offset `+0x1fc` to fetch controls `1`, `2`, and `4`. `ClanAttrInputDialog` adds submitted-field storage at `+0x26c`, `+0x46c`, `+0x66c`, and `+0x86c`; see [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md).

## Live IDA Evidence

- IDB identity: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, checked through IDA MCP on 2026-06-04.
- Function boundaries in the modal-dialog island: `0x00488b40-0x00488eab`, `0x00488eb0-0x00488f24`, `0x00488f30-0x00488f67`, `0x00488f70-0x00488fa0`, submitters `0x00488fe0-0x00489062`, `0x004890b0-0x00489132`, `0x00489180-0x0048926e`, `0x004892b0-0x0048939e`, `0x004893e0-0x004894ce`, `0x00489510-0x004895fe`, `ClanAttrInputDialog` core methods `0x00489600-0x00489de1`, `0x00489df0-0x00489eb7`, `0x00489ec0-0x00489f46`, `0x00489f50-0x00489f80`, submitters `0x00489fc0-0x00489fe9` and `0x0048a030-0x0048a059`, and leave-confirm callbacks `0x0048a0a0-0x0048a0ae` and `0x0048a0b0-0x0048a0be`.
- Raw constructor starts `0x00488fa0`, `0x00489070`, `0x00489140`, `0x00489270`, `0x004893a0`, `0x004894d0`, `0x00489f80`, `0x00489ff0`, and `0x0048a060` are not IDA function starts, have no current xrefs to the exact start addresses, and begin with standard constructor-shaped prologues (`55 8b ec 51 56 ff 75 ...`).
- Modal-dialog vtable data is contiguous from `0x006158f8` through `0x00615fd0`: `ClanNameInputDialog`, the six `ClanNameInputDialog` derivatives, `ClanAttrInputDialog`, `ClanEnlistInputDialog`, `ClanChangeInputDialog`, and `ClanLeaveConfirmDialog` each have primary/secondary/tertiary vtable groups.
- IDA vtable store xrefs match the raw/inline construction evidence: `ClanNameInputDialog` stores at `0x00488b9e/0x00488ba4/0x00488bae`; derived name-dialog variants have stores at their inline open sites and raw constructor bodies, including `ClanDepMoneyInputDialog` `0x00485120/0x00487de4/0x00488fb2`, `ClanWidMoneyInputDialog` `0x00485398/0x004884d4/0x00489082`, `ClanExpelNameInputDialog` `0x004851cb/0x004881e4/0x00489152`, `ClanSummonNameInputDialog` `0x0048522c/0x00488294/0x00489282`, `ClanAppearNameInputDialog` `0x00485284/0x0048833c/0x004893b2`, and `ClanChangeNameInputDialog` `0x00485337/0x0048842e/0x004894e2`.
- `ClanAttrInputDialog` vtable stores are `0x00489660/0x00489666/0x00489670`; derived/enclosing stores include `ClanEnlistInputDialog` `0x00487f34/0x00489f92`, `ClanChangeInputDialog` `0x004852ee/0x004883ed/0x0048a002`, and `ClanLeaveConfirmDialog` `0x004850a7/0x00487d22/0x0048a07b`.
- `by-project-structure/proposed-source-tree.md` lists `ClanDialogs.cpp` under `ui/dialogs/`, which is why this page now has the validator path `NexusTK/ui/dialogs/`; [UID:0000I8][Clan](by-file/Clan.md) remains the stronger fallback owner if final source layout keeps clan modal dialogs inside the social feature module.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0000I9][ClanBank](by-file/ClanBank.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md)
- [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md)
- [UID:000024][ClanAttrInputDialog](by-class/ClanAttrInputDialog.md)
- [UID:00002J][ClanNameInputDialog](by-class/ClanNameInputDialog.md)
- [UID:00010J][0x00488b40-0x00488fa0.ClanNameInputDialogCore](by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md)
- [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md)
- [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md)
- [UID:0002NS][0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney](by-memory/0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney.md)
- [UID:0002NT][0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor](by-memory/0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor.md)
- [UID:0002NU][0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney](by-memory/0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney.md)
- [UID:0002NV][0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor](by-memory/0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor.md)
- [UID:0002NW][0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName](by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md)
- [UID:0002NX][0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor](by-memory/0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor.md)
- [UID:0002NY][0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName](by-memory/0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName.md)
- [UID:0002NZ][0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor](by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md)
- [UID:0002O0][0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName](by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md)
- [UID:0002O1][0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor](by-memory/0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor.md)
- [UID:0002O2][0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName](by-memory/0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName.md)
- [UID:00010L][0x00489600-0x00489f80.ClanAttrInputDialogCore](by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md)
- [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md)
- [UID:00010M][0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters](by-memory/0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters.md)
- [UID:0002O3][0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment](by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment.md)
- [UID:0002O4][0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor](by-memory/0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md)
- [UID:0002O5][0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange](by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange.md)
- [UID:0002O6][0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor](by-memory/0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor.md)
- [UID:0002O7][0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm](by-memory/0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm.md)
- [UID:0002O8][0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel](by-memory/0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel.md)

## Changes

- 2026-05-27: Corrected the `ClanNameInputDialog` core range from `0x00488b40-0x00488f9f` to `0x00488b40-0x00488fa0` and added [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md) for the `ClanDepMoneyInputDialog` raw constructor-shaped bytes. Evidence: IDA MCP disassembly shows the final byte at `0x00488f9f` belongs to `sub_488F70`'s `retn 4`, and raw-head audit shows `0x00488fa0-0x00488fd5` installs `ClanDepMoneyInputDialog` vtables without an IDA function object.
- 2026-05-27: Corrected `ClanAttrInputDialog` core end from `0x00489f7f` to `0x00489f80` and added [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md). Evidence: IDA MCP reports `sub_489F50` at `0x00489f50-0x00489f80`, then constructor-shaped bytes that install `ClanEnlistInputDialog` vtables before alignment padding at `0x00489fb5-0x00489fc0`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:76`.
  - Summary/evidence: candidate dialog family contents, vtable/layout anchors, raw constructor caveats, and Clan/ClanBank ownership relationships are documented; confidence remains medium-high because this page is explicitly a split candidate rather than a committed final source module.
- 2026-06-04 live IDA path and confidence update:
  - What existed before: `COMPLETION:82`, `CONFIDENCE:76`, and a blank `PROPOSED_RECONSTRUCTION_PATH`, with older external-source hints and only partial exact child links.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:82`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`.
  - Summary/evidence: live IDA MCP now records exact modal-dialog function boundaries, the raw constructor starts with no IDA function/xref at the start, contiguous vtable groups from `0x006158f8-0x00615fd0`, concrete vtable store xrefs for each dialog family, and the `ui/dialogs/ClanDialogs.cpp` placement in `by-project-structure/proposed-source-tree.md`. Confidence remains capped because [UID:0000I8][Clan](by-file/Clan.md) is still a strong fallback owner for final source layout.
