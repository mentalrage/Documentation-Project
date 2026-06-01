*** UID:0000IA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ClanDialogs

## Status

- Confidence: medium for final source split; strong for the class family and vtable anchors.
- Proposed module: `ui/dialogs/ClanDialogs.cpp` only if final source layout separates clan modal dialogs from `social/Clan.cpp`.
- Proposed header: `ui/dialogs/ClanDialogs.h` or declarations folded into `social/Clan.h`.
- Current recovered sources: clan name/attribute/enlist/change/leave dialog class files under `simroot_v2`.
- Evidence basis: generated `simroot_v2` class files as hints, plus IDA MCP vtable/RTTI/store checks on 2026-05-26. Current generated metadata omits these vtables, so use [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md) for layout evidence.
- Layout docs: [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md)

## File Role

`ClanDialogs.cpp` is a possible home for clan modal dialogs and submitters: name/money/member input dialogs, attribute-change dialogs, enlist/change/leave confirmation flows, and their small opcode `0x4b` packet submitters.

The current stronger owner is [UID:0000I8][Clan](by-file/Clan.md), because the same cluster shares clan status pane state, child list panes, resources, packet helpers, and destructor bands. Treat this page as a split candidate, not a committed migration target.

Do not fold the clan bank/item dialogs into this page by default. Those dialogs are larger and currently have a stronger split case in [UID:0000I9][ClanBank](by-file/ClanBank.md).

## Candidate Contents

| Entity | Range / anchors | Role |
| --- | --- | --- |
| `ClanNameInputDialog` | `0x00488b40-0x00488fa0`; vtables `0x006158f8`, `0x0061595c`, `0x0061598c` | Shared `DLGCLAN1.EPF` modal input shell for clan name/money/text flows. |
| `ClanDepMoneyInputDialog` | raw constructor [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md); submitter `0x00488fe0`; vtables `0x00615998`, `0x006159fc`, `0x00615a2c` | Deposit-money dialog variant. |
| `ClanWidMoneyInputDialog` | submitter `0x004890b0`; vtables `0x00615a38`, `0x00615a9c`, `0x00615acc` | Withdraw-money dialog variant. |
| `ClanExpelNameInputDialog` | submitter `0x00489180`; vtables `0x00615ad8`, `0x00615b3c`, `0x00615b6c` | Expel-member-by-name dialog variant. |
| `ClanSummonNameInputDialog` | submitter `0x004892b0`; vtables `0x00615b78`, `0x00615bdc`, `0x00615c0c` | Summon-member-by-name dialog variant. |
| `ClanAppearNameInputDialog` | submitter `0x004893e0`; vtables `0x00615c18`, `0x00615c7c`, `0x00615cac` | Appearance/name action dialog variant. |
| `ClanChangeNameInputDialog` | submitter `0x00489510`; vtables `0x00615cb8`, `0x00615d1c`, `0x00615d4c` | Clan rename dialog variant. |
| `ClanAttrInputDialog` | `0x00489600-0x00489f80`; vtables `0x00615d58`, `0x00615dbc`, `0x00615dec` | Shared `DLGCLAN2.EPF` multi-field attribute input shell. |
| `ClanEnlistInputDialog` | raw constructor [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md), parser/handlers and submitter `0x00489fc0`; vtables `0x00615df8`, `0x00615e5c`, `0x00615e8c` | Enlistment attribute dialog submit path plus related clan packet handling. |
| `ClanChangeInputDialog` | submitter `0x0048a030`; vtables `0x00615e98`, `0x00615efc`, `0x00615f2c` | Clan attribute-change submit path through helper `0x00486330`. |
| `ClanLeaveConfirmDialog` | callbacks `0x0048a0a0`, `0x0048a0b0`; vtables `0x00615f38`, `0x00615fa0`, `0x00615fd0` | Alert-derived leave confirmation dialog. |

## Boundary Notes

- IDA reports no function at the generated constructor starts `0x00488fa0`, `0x00489070`, `0x00489140`, `0x00489270`, `0x004893a0`, `0x004894d0`, `0x00489f80`, `0x00489ff0`, or `0x0048a060`; some starts are still raw constructor-shaped byte ranges and should not be discarded.
- The vtable records above are stronger class identity anchors than the projected constructor starts.
- 2026-05-27 IDA MCP family pass found no inbound xrefs or raw dword pointer hits for those projected constructor starts. The bytes are still constructor-shaped and contain base-constructor calls plus derived vtable stores, so they should be modeled as unresolved constructor-boundary bytes rather than thrown away or treated as confirmed callable starts.
- The `0x0048c260-0x0048c341` destructor/thunk band is layout support for these dialogs and `ClanStatusPane`, but compiler-generated adjustor thunks should not be rewritten as source methods.
- `ClanNameInputDialog` uses inherited control host offset `+0x1fc` to fetch controls `1`, `2`, and `4`. `ClanAttrInputDialog` adds submitted-field storage at `+0x26c`, `+0x46c`, `+0x66c`, and `+0x86c`; see [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md).

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
- [UID:00010L][0x00489600-0x00489f80.ClanAttrInputDialogCore](by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md)
- [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md)
- [UID:00010M][0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters](by-memory/0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters.md)

## Changes

- 2026-05-27: Corrected the `ClanNameInputDialog` core range from `0x00488b40-0x00488f9f` to `0x00488b40-0x00488fa0` and added [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md) for the `ClanDepMoneyInputDialog` raw constructor-shaped bytes. Evidence: IDA MCP disassembly shows the final byte at `0x00488f9f` belongs to `sub_488F70`'s `retn 4`, and raw-head audit shows `0x00488fa0-0x00488fd5` installs `ClanDepMoneyInputDialog` vtables without an IDA function object.
- 2026-05-27: Corrected `ClanAttrInputDialog` core end from `0x00489f7f` to `0x00489f80` and added [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md). Evidence: IDA MCP reports `sub_489F50` at `0x00489f50-0x00489f80`, then constructor-shaped bytes that install `ClanEnlistInputDialog` vtables before alignment padding at `0x00489fb5-0x00489fc0`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:76`.
  - Summary/evidence: candidate dialog family contents, vtable/layout anchors, raw constructor caveats, and Clan/ClanBank ownership relationships are documented; confidence remains medium-high because this page is explicitly a split candidate rather than a committed final source module.
