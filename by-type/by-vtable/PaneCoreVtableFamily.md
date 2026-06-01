*** UID:0001YC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Pane Core Vtable Family

## Status

- Disposition: vtable family inventory for reconstructable UI-core pane code.
- Covered source owners: [UID:0000MC][Pane](by-file/Pane.md), [UID:0000IG][ControlPane](by-file/ControlPane.md), [UID:0000IT][DialogPane](by-file/DialogPane.md), [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md), and [UID:0000ME][PanelPane](by-file/PanelPane.md)
- Covered classes: [UID:0000A2][Pane](by-class/Pane.md), [UID:000038][ControlPane](by-class/ControlPane.md), [UID:00003T][DialogPane](by-class/DialogPane.md), [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md), and [UID:0000A4][PanelPane](by-class/PanelPane.md)
- Layout docs: [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md), [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md), [UID:0001V9][ModelessDialogPaneLayout](by-type/by-struct/ModelessDialogPaneLayout.md), [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md)
- Confidence: strong for table bases, object offsets, RTTI locator dwords, slot counts, constructor/destructor stores, and destructor adjustor thunks.
- Verification: IDA MCP `list_globals`, `lookup_funcs`, `disasm`, `xrefs_to`, and `py_eval` checks on 2026-05-26 and 2026-06-01.

## Table Bases

| Class | Primary vtable | Secondary vtable | Tertiary vtable | Object offsets |
| --- | --- | --- | --- | --- |
| `Pane` | `0x006219e8` | `0x00621a34` | `0x00621a64` | `+0x00`, `+0xa0`, `+0xa4` |
| `ControlPane` | `0x00617a90` | `0x00617af8` | `0x00617b28` | `+0x00`, `+0xa0`, `+0xa4` |
| `DialogPane` | `0x00618a64` | `0x00618ac4` | `0x00618af4` | `+0x00`, `+0xa0`, `+0xa4` |
| `ModelessDialogPane` | `0x00618c48` | `0x00618ca8` | `0x00618cd8` | `+0x00`, `+0xa0`, `+0xa4` |
| `PanelPane` | `0x00621a70` | `0x00621ac0` | `0x00621af0` | `+0x00`, `+0xa0`, `+0xa4` |

## Destructor Slot Pattern

| Class | Primary destructor slot | Secondary adjustor | Tertiary adjustor | Notes |
| --- | --- | --- | --- | --- |
| `Pane` | `0x00544f50` | `0x00544f2e` | `0x00544f39` | Secondary subtracts `0xa0`; tertiary subtracts `0xa4`; both jump to `0x00544f50`. |
| `ControlPane` | `0x0049b170` | `0x0049af3d` | `0x0049af48` | Both thunks jump to `0x0049b170`; active generated scalar destructor has base-owner pollution. |
| `DialogPane` | `0x0048c350` | `0x0048c27b` | `0x0048c286` | Both thunks jump to `0x0048c350`; IDA's scalar destructor name/type is polluted by nearby Boost/exception metadata. |
| `ModelessDialogPane` | `0x0048c350` | `0x0048c27b` | `0x0048c286` | Reuses `DialogPane` destructor ABI support; no class-specific destructor body identified. |
| `PanelPane` | `0x00545110` | `0x005450ef` | `0x005450fa` | Both thunks jump to `0x00545110`; see [UID:0001YD][PanelPaneVtables](by-type/by-vtable/PanelPaneVtables.md). |

## Extent Notes

- The `Pane`, `ControlPane`, `DialogPane`, `ModelessDialogPane`, and `PanelPane` tertiary tables are short. Each owns only the destructor adjustor slot and inherited `0x00544e90` slot; the following dword is RTTI or neighboring data, not another slot for the current class.
- `Pane` tertiary table at `0x00621a64` ends before `0x00621a6c`, where `PanelPane` RTTI starts.
- `ControlPane` tertiary table at `0x00617b28` ends before `0x00617b30`, where `ProgressBarControlPane` RTTI starts.
- `DialogPane` tertiary table at `0x00618af4` ends before `0x00618afc`, where `AlertPane` RTTI starts.
- `ModelessDialogPane` tertiary table at `0x00618cd8` ends before `0x00618ce0`, where neighboring `DLGFRAME.*` string/data storage starts.
- `PanelPane` tertiary table at `0x00621af0` ends before `0x00621af8`, where [UID:0001XF][EditablePaperPaneVtables](by-type/by-vtable/EditablePaperPaneVtables.md) RTTI starts.

## Constructor/Destructor Store Evidence

- `Pane` constructor `0x00544460`, non-deleting destructor `0x00544580`, and scalar deleting destructor `0x00544f50` all write `0x006219e8`, `0x00621a34`, and `0x00621a64`.
- `ControlPane` constructor `0x004949e0` writes `0x00617a90`, `0x00617af8`, and `0x00617b28`. Its scalar deleting destructor `0x0049b170` calls the `Pane` teardown path rather than reinstalling control vtables.
- `DialogPane` constructor `0x0049d8a0` and cleanup body `0x0049da10` write `0x00618a64`, `0x00618ac4`, and `0x00618af4`.
- `ModelessDialogPane` constructor `0x004a0760` writes `0x00618c48`, `0x00618ca8`, and `0x00618cd8`.
- `PanelPane` constructor `0x00545090`, non-deleting destructor `0x005450d0`, and scalar deleting destructor `0x00545110` write `0x00621a70`, `0x00621ac0`, and `0x00621af0`.

## 2026-06-01 IDA Recheck

IDA MCP `py_eval` rechecked the exact table clusters and neighboring boundaries:

| Class | Locator/data range | Slot counts | Base-store evidence | Boundary |
| --- | --- | --- | --- | --- |
| `Pane` | `0x006219e4-0x00621a6c` | `18`, `11`, `2` | `0x005444bb/0x005444c1/0x005444cb`, `0x005445b4/0x005445ba/0x005445c0`, `0x00544f8b/0x00544f91/0x00544f97` | next dword `0x00621a6c -> ??_R4PanelPane@@6B@` |
| `ControlPane` | `0x00617a8c-0x00617b30` | `25`, `11`, `2` | `0x00494a23/0x00494a29/0x00494a33` | next dword `0x00617b30 -> ??_R4ProgressBarControlPane@@6B@` |
| `DialogPane` | `0x00618a60-0x00618afc` | `23`, `11`, `2` | `0x0049d8e0/0x0049d8e6/0x0049d8f0`, `0x0049da17/0x0049da1d/0x0049da27` | next dword `0x00618afc -> ??_R4AlertPane@@6B@` |
| `ModelessDialogPane` | `0x00618c44-0x00618ce0` | `23`, `11`, `2` | `0x004a07bd/0x004a07c4/0x004a07ca` | next dword `0x00618ce0 -> off_618CE0` / `DLGFRAME` data |
| `PanelPane` | `0x00621a6c-0x00621af8` | `19`, `11`, `2` | `0x005450a1/0x005450a9/0x005450b3`, `0x005450d0/0x005450d6/0x005450e0`, `0x00545116/0x0054511c/0x00545126` | next dword `0x00621af8 -> ??_R4EditablePaperPane@@6B@` |

The recheck confirms that the listed primary/secondary/tertiary views are source-declared class interface data and that the secondary/tertiary destructor entries are compiler adjustor thunks, not standalone handwritten methods.

## Wave3 Data Issues

Current disabled generated output marks several real 11-byte destructor adjustor thunks as missing code:

- `class_Pane.cpp.disabled` marks `0x00544f39` missing and emits a misleading adjusted-this expression for `0x00544f2e`.
- `class_ControlPane.cpp.disabled` marks `0x0049af3d` missing and emits a misleading adjusted-this expression for `0x0049af48`.
- `class_DialogPane.cpp.disabled` marks `0x0048c27b` missing and emits a misleading adjusted-this expression for `0x0048c286`.
- `class_PanelPane.cpp.disabled` marks `0x005450ef` missing and emits only the second adjustor thunk.
- `class_ModelessDialogPane.meta_wave3` reports `vtable_count: 0` even though IDA confirms three vtables and constructor stores.

These are data issues, not handwritten source gaps. They should be classified as compiler-generated vtable support or materialized as thunks only if the reconstruction tool needs explicit ABI glue.

## Cross References

- [UID:0001EB][0x00544f2e-0x00544f43.PaneAdjustorThunks](by-memory/0x00544f2e-0x00544f43.PaneAdjustorThunks.md)
- [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md)
- [UID:000120][0x0049af3d-0x0049af52.ControlPaneAdjustorThunks](by-memory/0x0049af3d-0x0049af52.ControlPaneAdjustorThunks.md)
- [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md)
- [UID:00010U][0x0048c27b-0x0048c290.DialogPaneAdjustorThunks](by-memory/0x0048c27b-0x0048c290.DialogPaneAdjustorThunks.md)
- [UID:0001Y6][ModelessDialogPaneVtables](by-type/by-vtable/ModelessDialogPaneVtables.md)
- [UID:0001ED][0x005450ef-0x00545104.PanelPaneAdjustorThunks](by-memory/0x005450ef-0x00545104.PanelPaneAdjustorThunks.md)
- [UID:0001YD][PanelPaneVtables](by-type/by-vtable/PanelPaneVtables.md)
- [UID:000252][0x00617a38-0x0061885c.ControlPaneReadOnlyData](by-memory/0x00617a38-0x0061885c.ControlPaneReadOnlyData.md)
- [UID:000254][0x006189dc-0x00618e50.DialogCoreReadOnlyData](by-memory/0x006189dc-0x00618e50.DialogCoreReadOnlyData.md)
- [UID:000263][0x006219e8-0x00621db8.PaneParcelReadOnlyData](by-memory/0x006219e8-0x00621db8.PaneParcelReadOnlyData.md)

## Changes

### 2026-06-01 - Validator Score And IDA Recheck

- What existed before: the page contained strong vtable-family evidence but still had validator scores `0/0` and blank reconstructable metadata.
- What changed: the page is marked `RECONSTRUCTABLE:TRUE`, scored `88/90`, and records a fresh IDA recheck of the table locator ranges, slot counts, store xrefs, and neighboring boundaries.
- Why: IDA MCP `py_eval` confirms each listed table cluster and shows that the remaining caveats are about generated-tool classification and source-layout refinement, not about whether these vtables exist or where their class boundaries are.
