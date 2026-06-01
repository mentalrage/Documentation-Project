*** UID:0000A5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ParcelIconPane

## Status

- Confidence: strong for outer parcel alert/icon owner, medium for complete constructor coverage in Wave3.
- Likely source file: [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- Current recovered file: `source-3/simroot_v2/class_ParcelIconPane.cpp`
- Memory range: [UID:0001EH][0x00545e40-0x005470ac.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ac.ParcelNotificationPanes.md)
- Vtable/type evidence: [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md)
- Layout evidence: [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md)

## Class Purpose

`ParcelIconPane` is the outer parcel notification pane/icon that creates and owns a child [UID:0000A6][ParcelPane](by-class/ParcelPane.md). It stores its singleton separately from `g_pParcelPane`, manages the associated child pane, and dismisses it during teardown.

## Layout Notes

The class derives from [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md). IDA-normalized fields begin at `+0xf8` for total/left/right parcel counters, and the owned child [UID:0000A6][ParcelPane](by-class/ParcelPane.md) pointer is at `+0xfc`. The packet callback at `0x005461c0` runs through the secondary view at owner `+0xa0`, so its `this + 0x58..0x5c` accesses normalize to owner `+0xf8..+0xfc`.

## Method Notes

| Range | Method | Notes |
| --- | --- | --- |
| `0x00545e40-0x0054606a` | `ParcelIconPane::ParcelIconPane` candidate | Constructs the icon pane, writes the icon singleton, allocates an embedded `ParcelPane`, initializes the child pane, and schedules its timer. Active `class_ParcelIconPane.cpp` does not emit this body. |
| `0x00546070-0x005460e8` | non-deleting destructor | Resets vtables, dismisses the associated child pane, clears the icon singleton, and destroys the pane base. |
| `0x005461c0-0x0054628d` | parcel packet/update callback | Secondary-vtable callback at `0x00621c10`. Decodes parcel packet bitmasks, updates icon-side total/left/right counters, and forwards new counts to the child `ParcelPane`. Not emitted in active `class_ParcelIconPane.cpp`. |
| `0x00546e70-0x00546e7a` | clear icon singleton helper | Clears the icon-pane singleton. |
| `0x00546ea1-0x00546eb7` | destructor adjustor thunks | Secondary/tertiary vtable thunks forwarding to `0x00546f40`. Compiler-generated; see [UID:0001EM][0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks](by-memory/0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks.md). |
| `0x00546f40-0x00546ff9` | scalar deleting destructor | Dismisses associated child pane, clears icon singleton, destroys base, and optionally deletes memory. |

## Evidence Notes

- IDA MCP decompilation of `0x00545e40` writes `ParcelIconPane` vtables, then allocates and initializes a `ParcelPane` child.
- IDA MCP `xrefs_to 0x005461c0` reports the vtable data reference at `0x00621c10`, which is slot `+0x10` of the ParcelIconPane secondary vtable.
- IDA MCP vtable dump confirms the tertiary table at `0x00621c30` has only two slots. The next dword at `0x00621c38` is `ParcelPane` RTTI, not a `ParcelIconPane` virtual.
- `0x00546f40` appears in many generated metadata files as a referenced owner, so final migration should use the canonical `ParcelIconPane` owner rather than copied reference contexts.
- The destructor path calls pane-manager dismissal for the associated child and clears the icon singleton, distinct from `g_pParcelPane`.

## Cross-References

- [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- [UID:0000A6][ParcelPane](by-class/ParcelPane.md)
- [UID:0001EH][0x00545e40-0x005470ac.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ac.ParcelNotificationPanes.md)
- [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md)
- [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md)
- [UID:0001EG][0x00545e40-0x0054606a.ParcelIconPaneConstructor](by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md)
- [UID:0001EI][0x00546070-0x005460e8.ParcelIconPaneDestructor](by-memory/0x00546070-0x005460e8.ParcelIconPaneDestructor.md)
- [UID:0001EJ][0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback](by-memory/0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback.md)
- [UID:0001EO][0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor](by-memory/0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor.md)
- [UID:0000RX][g_pParcelIconPane](by-global/g_pParcelIconPane.md)

## Changes

- 2026-05-31: Marked reconstructable and attached to [UID:0000MF][ParcelPane](by-file/ParcelPane.md).
  - Before: class evidence was documented but validator autogen metadata was blank.
  - After: `RECONSTRUCTABLE:TRUE` with the file parent set; final C++ remains blank until constructor/callback names and helper APIs are near-final.
  - Evidence: IDA MCP confirms the constructor, destructor, packet/update callback, singleton-clear helper, adjustor thunks, and scalar deleting destructor as part of the parcel notification source family.

## Changes

- Before: completion/confidence metadata were `0/0` while the page already documented purpose, layout normalization, constructor/destructor/callback ranges, vtable evidence, singleton separation, and child `ParcelPane` ownership.
- Changed to: `COMPLETION:82` and `CONFIDENCE:78`.
- Evidence: IDA-backed constructor behavior, packet callback vtable slot, scalar deleting destructor, layout offsets, singleton global, and generated constructor omissions are documented; confidence remains medium-high because active Wave3 output still omits complete constructor/callback coverage.
