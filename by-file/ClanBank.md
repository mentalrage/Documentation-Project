*** UID:0000I9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/social/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ClanBank

## Status

- Confidence: strong for local bank/item dialog classes, packet senders, and `g_pClanBankPane` lifecycle ownership; medium for exact original file split between bank pane, item deposit/withdraw dialogs, and shared text helpers.
- Proposed module folder: `social/`
- Proposed source file: `social/ClanBank.cpp`
- Possible split file: `social/ClanItemDialogs.cpp`
- Evidence basis: Wave3 class/file inspection, generated `simroot_v2` sources, and IDA MCP `lookup_funcs` checks on 2026-05-23.

## Hypothesis

The clan bank and item deposit/withdraw dialogs are probably a companion Clan feature translation unit, not independent one-class files. The cluster is physically compact from raw constructor-shaped bytes at `0x0048a0c0` through `0x0048c251`, shares opcode `0x4b`/`0x36` clan-bank packet shapes, uses the same `DL`/`DL_15`/`cl` dialog resources, and is tied together by `ClanItemDialog`, `ClanItemListPane`, `ClanBankPane`, and `ClanBankItemListPane`.

Keep this as a likely `ClanBank.cpp` split from [UID:0000I8][Clan](by-file/Clan.md) unless later xref evidence shows the original source kept every clan dialog in one larger `Clan.cpp`.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `ClanItemDialog` | raw constructor [UID:00021X][0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor](by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md), vtable reset [UID:0002OC][0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail](by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md), confirm validation [UID:0002OB][0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation](by-memory/0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation.md), destructor `0x0048c470` | `class_ClanItemDialog.cpp` | Shared item-selection dialog base; validates selected item plus quantity/text before enabling confirmation. |
| `ClanDepItemDialog` | `0x0048a1c0-0x0048a805`, animation `0x0049ec80` | `class_ClanDepItemDialog.cpp` | Deposit-item dialog; parses packet text, builds item/amount UI, sends opcode `0x4b` subtype `5`. |
| `ClanWidItemDialog` | `0x0048a810-0x0048ae65` | `class_ClanWidItemDialog.cpp` | Withdraw-item dialog; parses title/detail/list payload, builds item/quantity UI, sends opcode `0x4b` subtype `12`. |
| `ClanItemListPane` | `0x0048ae70-0x0048b1b1`, destructor `0x0048c510`, text helpers `0x004ba820-0x004ba991` | `class_ClanItemListPane.cpp` | Scrollable item list for clan item dialogs, including icon rendering and width-limited item names. |
| `ClanBankPane` | `0x0048b1c0-0x0048b7dc`, raw packet helpers [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md), destructor `0x0048c410`, animation `0x0049ed60` | `class_ClanBankPane.cpp` | Main clan bank dialog, mode switch between item/gold bank, close/submit packet handling, singleton `g_pClanBankPane`. |
| `ClanBankItemListPane` | `0x0048b8c0-0x0048c251`, destructor `0x0048c3d0` | `class_ClanBankItemListPane.cpp` | Parses full/update/remove bank inventory packets, sorts display names, draws bank item rows with counts. |

## Boundary And Data Notes

- IDA reports no function at Wave3's projected `ClanItemDialog::ClanItemDialog` start `0x0048a0c0`, but 2026-05-27 IDA byte audit bounded the raw constructor-shaped body as [UID:00021X][0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor](by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md). Use real IDA starts `0x0048a100` and `0x0048a120` for confirmed function anchors, and keep the constructor as a raw byte-range record until reachability is understood.
- IDA confirms real helper starts at `0x0048a690`, `0x0048acf0`, and `0x0048b600`, but Wave3 does not currently give those small vtable-reset/destructor helper functions clean memory owners.
- `ClanBankItemListPane::AppendEntryString` at `0x00430041` starts one byte after IDA's real [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md) and behaves like support code. Do not migrate it into `ClanBank.cpp` from current owner data alone.
- `ClanBankItemListPane::virt_meth_0x4c0043` is excluded in Wave3 and resolves inside IDA function `sub_4BEE40`, a large SIMD bit-manipulation helper with no clan-bank behavior. Treat it as owner pollution, not as a clan method.
- `ClanItemListPane` currently owns `SetEntryText` and `CountCharsFittingWidth` at `0x004ba820-0x004ba991`. They are useful text-fitting helpers for clan item rows, but their final owner may be a generic UI/text module after caller review.
- `ClanDepItemDialog` constructs [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md) at `0x0048a50d` to choose a player-owned item for deposit. Do not move `MyItemListPane` into `ClanBank.cpp`; current caller fanout also includes `AddItemDialog` and `MixItemDialog`.
- The `MyItemListPane` dependency consumes [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md) for item icon drawing. That is a render-library dependency, not clan-owned image state.

## Migration Notes

Recommended migration order:

```powershell
python source-3\wave3.py create file ClanBank.cpp --kind source --simpath social/ClanBank.cpp --dry-run
python source-3\wave3.py attach class ClanBankPane --to-file ClanBank.cpp --dry-run
python source-3\wave3.py attach class ClanBankItemListPane --to-file ClanBank.cpp --dry-run
python source-3\wave3.py attach class ClanItemDialog --to-file ClanBank.cpp --dry-run
python source-3\wave3.py attach class ClanItemListPane --to-file ClanBank.cpp --dry-run
python source-3\wave3.py attach class ClanDepItemDialog --to-file ClanBank.cpp --dry-run
python source-3\wave3.py attach class ClanWidItemDialog --to-file ClanBank.cpp --dry-run
```

Before non-dry-run ownership changes, exclude or re-own the outlier `0x00430041` and `0x004c0043` records and decide whether text fitting at `0x004ba820-0x004ba991` stays with clan item lists or moves to a shared text helper file.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:00002F][ClanItemDialog](by-class/ClanItemDialog.md)
- [UID:000029][ClanDepItemDialog](by-class/ClanDepItemDialog.md)
- [UID:00002N][ClanWidItemDialog](by-class/ClanWidItemDialog.md)
- [UID:00002G][ClanItemListPane](by-class/ClanItemListPane.md)
- [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md)
- [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md)
- [UID:000026][ClanBankPane](by-class/ClanBankPane.md)
- [UID:000025][ClanBankItemListPane](by-class/ClanBankItemListPane.md)
- [UID:00021X][0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor](by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md)
- [UID:00010N][0x0048a100-0x0048a1be.ClanItemDialogCore](by-memory/0x0048a100-0x0048a1be.ClanItemDialogCore.md)
- [UID:0002OC][0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail](by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md)
- [UID:0002OB][0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation](by-memory/0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation.md)
- [UID:00010O][0x0048a1c0-0x0048a805.ClanDepItemDialog](by-memory/0x0048a1c0-0x0048a805.ClanDepItemDialog.md)
- [UID:00010P][0x0048a810-0x0048ae65.ClanWidItemDialog](by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md)
- [UID:00010Q][0x0048ae70-0x0048b1b1.ClanItemListPane](by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md)
- [UID:00010R][0x0048b1c0-0x0048b7dc.ClanBankPane](by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md)
- [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md)
- [UID:00010S][0x0048b8c0-0x0048c251.ClanBankItemListPane](by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md)
- [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md)
- [UID:00012V][0x0049ec80-0x0049ee41.ClanDialogSlideAnimation](by-memory/0x0049ec80-0x0049ee41.ClanDialogSlideAnimation.md)
- [UID:00016B][0x004ba820-0x004ba991.TextFitAndSuffixHelpers](by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md)
- [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md)

## Changes

- 2026-05-27: Changed the `ClanItemDialog` constructor note from an unresolved projected start to bounded raw constructor [UID:00021X][0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor](by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md), and moved the bank/item cluster's lower evidence boundary from `0x0048a100` to `0x0048a0c0`. Evidence: IDA MCP reports no function at `0x0048a0c0`, but byte audit shows constructor-shaped code that calls `0x0049d8a0`, installs `ClanItemDialog` vtables, and ends before padding at `0x0048a0fb-0x0048a100`.
- 2026-05-27: Corrected `ClanItemListPane` range from `0x0048ae70-0x0048b1b0` to `0x0048ae70-0x0048b1b1`. Evidence: IDA MCP reports `sub_48B0A0` at `0x0048b0a0-0x0048b1b1`, with `0x0048b1b1-0x0048b1c0` padding before `ClanBankPane`.
- 2026-05-27: Corrected `ClanBankPane` range from `0x0048b1c0-0x0048b7db` to `0x0048b1c0-0x0048b7dc` and added raw packet helpers [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md). Evidence: IDA MCP reports `sub_48B630` ending at `0x0048b7dc`, followed by two helper-shaped opcode `0x36` packet bodies and padding before `ClanBankItemListPane`.
- 2026-05-27: Corrected `ClanBankItemListPane` from `0x0048b8c0-0x0048c250` to `0x0048b8c0-0x0048c251`. Evidence: IDA MCP reports `sub_48C040` through `0x0048c251`, then alignment padding before the destructor band.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:80`.
  - Summary/evidence: clan bank pane, item dialogs, item lists, packet helpers, outlier records, dependencies, migration order, and boundary corrections are documented; confidence is held at 80 because the final split between `ClanBank.cpp`, item-dialog code, and shared text helpers is still provisional.
- 2026-05-31: Updated `ClanItemDialog` contents after the core-method split.
  - What existed before: the proposed contents table listed real helpers only as raw addresses `0x0048a100` and `0x0048a120`.
  - Changed to: linked exact child pages [UID:0002OC][0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail](by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md) and [UID:0002OB][0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation](by-memory/0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation.md).
  - Summary/evidence: IDA MCP verified both ranges and showed the confirm path calls reusable [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder.md), so the bank source owns the dialog behavior but not the text-control helper.
- 2026-06-02: Filled the validator projected path from the page's own source-layout evidence.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the status and hypothesis sections already place the likely source as `social/ClanBank.cpp`.
  - After: projected path is `NexusTK/social/`, matching sibling [UID:0000I8][Clan](by-file/Clan.md) and the documented `social/ClanBank.cpp` split.
  - Evidence: the proposed contents and migration notes keep `ClanBankPane`, `ClanBankItemListPane`, clan item dialogs, and raw bank packet helpers together under the clan-bank social module.
- 2026-06-07 A008 Batch 037 parent-gate refresh:
  - Raised confidence from `80` to `85`.
  - Evidence: the `0x0067ade8` slot has been isolated from [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md) as `g_pClanBankPane`; constructor writes, destructor-family clears, and clan-bank UI action reads all stay inside the documented `ClanBankPane`/`ClanBank.cpp` owner family, clearing the direct-parent gate for the exact singleton global.
