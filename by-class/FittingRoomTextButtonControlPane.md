*** UID:000055 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FittingRoomTextButtonControlPane

## Status

- Confidence: strong for live method/vtable behavior, medium-high for final source placement because one ranking dialog path also instantiates the same class.
- Proposed source module: [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- Local memory core: [UID:0002SC][0x00424020-0x004242e4.FittingRoomTextButtonControlPane](by-memory/0x00424020-0x004242e4.FittingRoomTextButtonControlPane.md)
- Base class: [UID:0000EJ][TextButtonControlPane](by-class/TextButtonControlPane.md) constructor/destructor calls at `0x00495040` and `0x00495130`.
- Evidence basis: live IDA MCP/disassembly on 2026-06-04 for binary `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.

## Autogen Status

- Reconstructable: true. This is a source-owned fitting-room action/category button class.
- Autogen parent: [UID:0000JE][FittingRoom](by-file/FittingRoom.md). The file parent is high-confidence and has a valid proposed reconstruction path under `NexusTK/cashshop/`.
- Reconstruction status: no final C++ emitted yet. The exact final declaration, source-file placement, paint-frame constants, and field names are not final-source quality.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 84 | Live IDA now documents the constructor, non-deleting destructor body, vtable-only paint method, selected-state setter, two secondary adjustor thunks, scalar deleting destructor, base TextButtonControlPane calls, direct fitting-room and ranking constructor callers, vtable slots, and boundary exclusions. |
| Confidence | 86 | Binary behavior and class RTTI/vtable identity are strong. Confidence stays below final because the same constructor is also used by `RankingDialog`, so final source placement and naming still need source-shape review. |

## Role

Fitting-room action button control. Local methods initialize a resource-backed text button, draw the frame, and toggle enabled state.

## Confirmed Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x00424020-0x0042405f` | constructor | Calls `TextButtonControlPane` construction at `0x00495040`, installs three class vtable pointers, and clears selected-state byte `this + 0x110`. |
| `0x00424060-0x0042407f` | non-deleting destructor body | Restores the class vtables and tail-calls `TextButtonControlPane` teardown at `0x00495130`; no direct xrefs found in current IDA. |
| `0x00424080-0x0042425d` | paint frame method | Vtable-only paint method; draws two inset border rectangles, sets colors, and draws centered label text through `0x004bad70`. |
| `0x00424260-0x00424270` | selected-state setter | Stores the selected/enabled visual flag at `this + 0x110`; called by category rebuild and selected-button paths. |
| `0x00424270-0x0042427b` | adjustor thunk | Secondary-vtable `this - 0xa0` thunk to the deleting destructor wrapper; compiler-generated. |
| `0x0042427b-0x00424286` | adjustor thunk | Tertiary-vtable `this - 0xa4` thunk to the deleting destructor wrapper; compiler-generated. |
| `0x00424290-0x004242e5` | scalar deleting destructor wrapper | Restores class vtables, calls `0x00495130`, conditionally frees with `0x004f4ac0`, and has a sized-delete path for `0x114` bytes. |

## Evidence Notes

- Live IDA on 2026-06-04 confirms the local function starts and half-open ranges: `sub_424020` `0x00424020-0x0042405f`, `sub_424060` `0x00424060-0x0042407f`, `sub_424080` `0x00424080-0x0042425d`, `sub_424260` `0x00424260-0x00424270`, `sub_424270` `0x00424270-0x0042427b`, `sub_42427B` `0x0042427b-0x00424286`, and `sub_424290` `0x00424290-0x004242e5`.
- The constructor writes primary vtable `0x0060dfd4`, secondary vtable `0x0060e040` at `this + 0xa0`, tertiary vtable `0x0060e070` at `this + 0xa4`, and selected byte `this + 0x110 = 0`.
- Vtable data xrefs place `0x00424290` at `0x0060dfd4`, paint `0x00424080` at `0x0060e018`, adjustor thunk `0x00424270` at `0x0060e040`, and adjustor thunk `0x0042427b` at `0x0060e070`.
- [UID:0002CV][0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons](by-memory/0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons.md) constructs category buttons for `UsableItems`, `Weapons`, `Mounts`, `Face`, `Head`, `Mantle`, `Necklaces`, `Coats`, `Shoes`, and `SpecialtySets`; it calls the selected-state setter once for the default category.
- [UID:0002CP][0x0041bdd0-0x0041c250.FittingRoomDialogConstructor](by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md) constructs fixed fitting-room buttons for `Basic` and `Current`.
- [UID:0002CX][0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton](by-memory/0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton.md) calls `0x00424260` at `0x0041d30a` and `0x0041d320` to clear the old selected button and set the new selected button.
- [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md) also constructs this class at `0x00458828` with `RewardInfo` and at `0x0045886d` with `GetReward`.
- [UID:00024M][0x0060d798-0x0060e174.CashShopFittingRoomReadOnlyData](by-memory/0x0060d798-0x0060e174.CashShopFittingRoomReadOnlyData.md) places the class RTTI/vtable names in the fitting-room UI vtable block.

## Boundary Cautions

- The `RankingDialog` constructor reuse means this class may be a small shared text-button subclass or a fitting-room class reused by ranking code. Keep the FittingRoom parent for current autogen grouping, but do not treat source-file placement as final.
- Vtable entry `0x0060e034 -> 0x004242f0` is a separate shared type-code virtual that returns `11` and is cross-referenced by several other vtables; keep it outside this class page.
- Padding around the local core is now byte-checked: `0x0042425d-0x00424260` and `0x00424286-0x00424290` are `0xcc` alignment, and `0x004242e5-0x004242f0` / `0x004242f5-0x00424300` bracket the separate `0x004242f0` type-code helper before [UID:000056][FittingRoomUserImageControlPane](by-class/FittingRoomUserImageControlPane.md).
- Do not write final C++ until the class name, header ownership, inherited virtual slots, and paint constants are resolved at source quality.

## Cross-References

- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0002SC][0x00424020-0x004242e4.FittingRoomTextButtonControlPane](by-memory/0x00424020-0x004242e4.FittingRoomTextButtonControlPane.md)
- [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md)
- [UID:0002CV][0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons](by-memory/0x0041cdc0-0x0041d14b.FittingRoomDialogRebuildCategoryButtons.md)
- [UID:0002CX][0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton](by-memory/0x0041d2c0-0x0041d335.FittingRoomDialogSelectButton.md)
- [UID:00024M][0x0060d798-0x0060e174.CashShopFittingRoomReadOnlyData](by-memory/0x0060d798-0x0060e174.CashShopFittingRoomReadOnlyData.md)
- [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- [UID:0000EJ][TextButtonControlPane](by-class/TextButtonControlPane.md)
- [UID:00001E][ButtonControlPane](by-class/ButtonControlPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `58/64`. Summary: local fitting-room button methods and ownership cautions are documented, but class contents are intentionally incomplete because generic event/motion helpers are not strong ownership evidence. Evidence: confirmed local cluster `0x00424020-0x004242e4` and documented boundary cautions against trusting current Wave3 ownership alone.

- 2026-06-02 exact local-core and autogen update:
  - What existed before: score was `58/64`, reconstructable and parent metadata were blank, and the class did not have an exact memory page.
  - Changed to: score is `72/80`, reconstructable is `TRUE`, parent is [UID:0000JE][FittingRoom](by-file/FittingRoom.md), and the class now links the exact local-core page.
  - Summary/evidence: existing IDA MCP evidence in the category-button rebuild and selected-button helper pages ties the constructor and selected-state helper to fitting-room behavior, while the read-only data page confirms the class vtable block. Fresh IDA MCP calls timed out, so final C++ remains blank.

- 2026-06-04 live IDA refresh:
  - What existed before: score was `72/80` and the page still relied on earlier linked evidence because the previous direct IDA refresh had timed out; it also omitted the non-deleting destructor body and second adjustor thunk.
  - Changed to: score is `84/86`, the method inventory now includes `0x00424060-0x0042407f` and `0x0042427b-0x00424286`, the stale timeout basis is replaced with current IDA binary identity/function/xref/vtable evidence, and the RankingDialog constructor reuse is recorded as a source-placement caveat.
  - Summary/evidence: live IDA confirms the exact local starts/ranges, TextButtonControlPane constructor/destructor calls, vtable pointers at `0x0060dfd4`, `0x0060e018`, `0x0060e040`, and `0x0060e070`, FittingRoom constructor/category/select call sites, RankingDialog `RewardInfo`/`GetReward` call sites, and boundary separation from the shared `0x004242f0` type-code virtual. Final C++ remains blank because final naming/source placement and paint constants are not at the 95/95 bar.
