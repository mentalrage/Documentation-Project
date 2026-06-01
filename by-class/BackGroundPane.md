*** UID:00000R | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:75 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

## Cross-References

- [UID:0000HO][BackPane](by-file/BackPane.md)
- [UID:0000YY][0x00467510-0x00467b2d.BackPaneAndBackGroundPane](by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md)
- [UID:00000S][BackPane](by-class/BackPane.md)
- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md)

## Changes

- What existed before: the page documented class purpose, method boundaries, and data notes but had unevaluated scores.
- What it was changed to: scores were set to `75/86`, and class-shape notes were added for base shape, singleton state, readiness fields, and source placement.
- Summary and evidence: IDA-confirmed function starts and the by-memory compact pane range support strong confidence; completion remains below full because exact member names and converted C++ bodies are not complete.
