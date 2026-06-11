*** UID:00000R | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BackGroundPane

## Status

- Confidence: strong for core class shape and method roles.
- Likely source file: [UID:0000HO][BackPane](by-file/BackPane.md)
- Core address range: [UID:0000YY][0x00467510-0x00467b2d.BackPaneAndBackGroundPane](by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md)
- Current recovered file: `source-3/simroot_v2/class_BackGroundPane.cpp`

## Class Purpose

`BackGroundPane` is a small tile-frame background pane. It has the same `Pane` plus secondary vtable shape as `BackPane`, owns an embedded `EPFTileContext`, tracks two readiness bytes, and either renders its tile frame or invalidates/clears its region when the backing data is not ready.

## Class Shape

- Base family: `Pane`-derived background/tile-frame pane with secondary vtable shape matching [UID:00000S][BackPane](by-class/BackPane.md).
- Singleton: writes and clears `g_pBackGroundPane`.
- Core state: embedded `EPFTileContext` plus readiness flags at `+0x160` and `+0x161`.
- Source placement: [UID:0000HO][BackPane](by-file/BackPane.md), sharing the compact [UID:0000YY][0x00467510-0x00467b2d.BackPaneAndBackGroundPane](by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md) range with `BackPane`.
- Vtable data: primary and secondary `BackGroundPane` vtable slices at `0x00612f3c`, `0x00612f88`, and `0x00612fb8`, each installed or restored by the constructor/destructor family.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x00467510-0x004675ab` | Constructs `Pane`, stores `g_pBackGroundPane`, installs vtables, initializes tile context, clears readiness flags. |
| non-deleting destructor | `0x004675b0-0x004675d9` | Resets vtables, clears singleton, tears down `Pane`. |
| packet/state callback | `0x004675e0-0x00467660` | Updates readiness flag at `+0x161` from a float threshold and reacts to selected packet/event codes. |
| `OnPaint` | `0x00467690-0x004676e5` | If both readiness flags are set, renders the tile frame; otherwise clears/invalidate fallback state. |
| flag accessors | `0x00467740-0x00467790` | Tiny getters/setters for bytes at offsets `0x160` and `0x161`. |
| singleton clear thunk | `0x004677a0-0x004677ab` | Clears `g_pBackGroundPane`. |
| deleting destructor | `0x004677d0-0x0046782f` | Resets vtables, clears singleton, destroys base, optionally deletes. |
| adjustor thunks | `0x004677ab-0x004677c1` | Compiler-generated this-adjustor thunks to the deleting destructor. |

## Data Notes

- `g_pBackGroundPane` is written in the constructor and cleared by destructor/clear-helper paths.
- Readiness flags live at offsets `0x160` and `0x161`.
- The embedded `EPFTileContext` starts around offset `0x138` in generated output.

## Evidence Notes

- IDA MCP confirms each listed method start as a function.
- IDA decompilation shows the `0x004675e0` callback writes `*(g_pBackGroundPane + 0x161)` based on a float value greater than approximately `0.8`, then dispatches only for event bytes `4`, `8`, `0xb`, `0x15`, and `0x26`.
- `by-memory/-report.md` marks the `0x004677b6` adjustor thunk as reviewed compiler support under `BackGroundPane`.
- [UID:0000YY][0x00467510-0x00467b2d.BackPaneAndBackGroundPane](by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md) records the current promoted BackGroundPane starts and sizes: constructor `0x00467510` size `0x9b`, non-deleting destructor `0x004675b0` size `0x29`, packet/state callback `0x004675e0` size `0x80`, paint `0x00467690` size `0x55`, flag accessor island beginning `0x00467740`, singleton clear `0x004677a0`, and scalar deleting destructor `0x004677d0` size `0x5f`.
- [UID:0002VV][0x0067ab7c-0x0067ab80.g_pBackGroundPane](by-memory/0x0067ab7c-0x0067ab80.g_pBackGroundPane.md) records the exact singleton slot: static bytes `ff ff ff ff`, six xrefs, constructor writes at `0x00467556`/`0x0046755d`, teardown clears at `0x004675ca`, `0x004677a0`, and `0x004677f0`, and the callback read at `0x00467601`.
- [UID:00024U][0x00612f3c-0x006131b4.BackGroundBalloonBlackHoleReadOnlyData](by-memory/0x00612f3c-0x006131b4.BackGroundBalloonBlackHoleReadOnlyData.md) records the three BackGroundPane vtable anchors with constructor/destructor install refs and representative first-slot targets `sub_4677D0`, `sub_4677AB`, and `sub_4677B6`.

## Assignment Gate

Assigned to [UID:0000HO][BackPane](by-file/BackPane.md). This class page is now `86/88`, the direct file parent is `86/88`, and the relationship is direct because the BackPane file page owns the contiguous BackGroundPane/BackPane root-background pane island, exact `g_pBackGroundPane` singleton storage, and BackGroundPane vtable/resource data. Final C++ remains blank because class declarations, member names, and full method bodies are below the `95/95` reconstruction-code gate.

## Cross-References

- [UID:0000HO][BackPane](by-file/BackPane.md)
- [UID:0000YY][0x00467510-0x00467b2d.BackPaneAndBackGroundPane](by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md)
- [UID:00000S][BackPane](by-class/BackPane.md)
- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md)

## Changes

- What existed before: the page documented class purpose, method boundaries, and data notes but had unevaluated scores.
- What it was changed to: scores were set to `75/86`, and class-shape notes were added for base shape, singleton state, readiness fields, and source placement.
- Summary and evidence: IDA-confirmed function starts and the by-memory compact pane range support strong confidence; completion remains below full because exact member names and converted C++ bodies are not complete.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE`. Current IDA MCP `lookup_funcs` reconfirmed the constructor/destructor/callback/paint/accessor/deleting-destructor starts at `0x00467510`, `0x004675b0`, `0x004675e0`, `0x00467690`, `0x00467740`, and `0x004677d0`. `AUTOGEN_PARENT_UID` remains blank because this class and [UID:0000HO][BackPane](by-file/BackPane.md) do not both clear the 80+ completion attachment gate.
- 2026-06-07 A005 Batch 079:
  - Before: score `75/86`, parent blank; the page documented the method table but did not carry the latest singleton, vtable, and direct-parent evidence already present in associated pages.
  - Changed to: score `86/88` and `AUTOGEN_PARENT_UID:0000HO`.
  - Summary/evidence: added current BackGroundPane function-size evidence from [UID:0000YY][0x00467510-0x00467b2d.BackPaneAndBackGroundPane](by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md), exact singleton slot/xref evidence from [UID:0002VV][0x0067ab7c-0x0067ab80.g_pBackGroundPane](by-memory/0x0067ab7c-0x0067ab80.g_pBackGroundPane.md), and BackGroundPane vtable anchor evidence from [UID:00024U][0x00612f3c-0x006131b4.BackGroundBalloonBlackHoleReadOnlyData](by-memory/0x00612f3c-0x006131b4.BackGroundBalloonBlackHoleReadOnlyData.md). Direct parent [UID:0000HO][BackPane](by-file/BackPane.md) is `86/88`, so the corrected child-and-parent gate is satisfied.
