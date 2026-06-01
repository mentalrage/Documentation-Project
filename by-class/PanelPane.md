*** UID:0000A4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PanelPane

## Status

- Confidence: strong for behavior; medium for destructor base-owner label.
- Likely source file: [UID:0000ME][PanelPane](by-file/PanelPane.md)
- Main address doc: [UID:0001EC][0x00545090-0x00545165.PanelPane](by-memory/0x00545090-0x00545165.PanelPane.md)
- Type docs: [UID:0001YD][PanelPaneVtables](by-type/by-vtable/PanelPaneVtables.md)
- Current recovered file: `source-3/simroot_v2/class_PanelPane.cpp`
- IDA MCP rechecked: 2026-05-26.

## Functionality

`PanelPane` is a base panel container class. It derives from `Pane`, installs a three-vtable layout, and provides standard panel destruction behavior used by many larger feature panes.

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| constructor | `0x00545090-0x005450c1` | Calls `Pane::Pane(this, 1)` and installs panel vtables; IDA size `0x32`. |
| destructor | `0x005450d0-0x005450ee` | Resets vtables and tears down the base pane; IDA size `0x1f`; generated owner label is polluted. |
| adjustor thunks | `0x005450ef-0x00545104` | Two 0xb-byte IDA-confirmed thunks forwarding to `0x00545110`. |
| scalar deleting destructor | `0x00545110-0x00545165` | Deleting destructor wrapper; vtable data xref at `0x00621a70`. |

## Derived-Use Evidence

IDA MCP caller checks on `0x00545090` show direct calls from inventory panes, options, self-look, group panes, collection, spell inventory, new system-message pane, and user-look/profile panes. That broad fan-in makes `PanelPane` a reusable UI-core base rather than a source file owned by any one feature module.

The scalar deleting destructor has no direct code callers; xrefs are vtable/thunk driven. `0x005450ef` and `0x005450fa` have vtable data xrefs at `0x00621ac0` and `0x00621af0` respectively.

IDA `list_globals` confirms the three `PanelPane` vtable bases at `0x00621a70`, `0x00621ac0`, and `0x00621af0`, with RTTI objects at `0x0064daf4`, `0x0064db08`, and `0x0064db1c`. The tertiary table is short: only `0x005450fa` and inherited slot `0x00544e90` belong to `PanelPane`; the next dword at `0x00621af8` begins neighboring `EditablePaperPane` RTTI metadata.

## Data Caveats

- Disabled generated output marks `0x005450ef` as missing code even though IDA models it as a real thunk.
- The generated destructor path still uses a `TextButtonExControlPane`-named base teardown; treat that as owner-label pollution.

## Cross References

- [UID:0000ME][PanelPane](by-file/PanelPane.md)
- [UID:0000A2][Pane](by-class/Pane.md)
- [UID:00005Q][GeneralPurposePanel](by-class/GeneralPurposePanel.md)
- [UID:0001EC][0x00545090-0x00545165.PanelPane](by-memory/0x00545090-0x00545165.PanelPane.md)
- [UID:0001YD][PanelPaneVtables](by-type/by-vtable/PanelPaneVtables.md)
- [UID:0001ED][0x005450ef-0x00545104.PanelPaneAdjustorThunks](by-memory/0x005450ef-0x00545104.PanelPaneAdjustorThunks.md)

## Changes

- Before: the `PanelPane` scalar deleting destructor and memory page ended at `0x00545164`.
- Changed to: both end at `0x00545165`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows `0x00545164` is the final operand byte of the destructor's `retn 4`.
- Before: completion/confidence metadata were `0/0` despite method map, derived-use evidence, vtables, RTTI, and generated-data caveats.
- Changed to: `COMPLETION:80` and `CONFIDENCE:78`.
- Evidence: constructor, destructor, adjustor thunks, scalar deleting destructor, broad derived-class fan-in, vtable data xrefs, and owner-label pollution are documented; confidence stays medium-high because destructor base-owner naming remains generated/polluted.
