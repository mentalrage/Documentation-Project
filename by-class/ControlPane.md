*** UID:000038 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ControlPane

## Status

- Confidence: strong for base-control role.
- Likely source file: [UID:0000IG][ControlPane](by-file/ControlPane.md)
- Main address range: [UID:000114][0x004949e0-0x00494bf7.ControlPane](by-memory/0x004949e0-0x00494bf7.ControlPane.md)
- Type docs: [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- Current recovered file: `source-3/simroot_v2/class_ControlPane.cpp`

## Class Purpose

`ControlPane` is a `Pane`-derived base for UI controls. It sets control type, shared vtables, optional bounds, sprite/skin fields, repeat delay, and hit-test behavior.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GetFixedValue10` | `0x0041d690-0x0041d694` | Small virtual returning `10`; semantic name remains open. |
| `ControlPane::ControlPane` | [UID:0002PB][0x004949e0-0x00494a81.ControlPaneConstructor](by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md) | Constructs base `Pane` and initializes control metadata. |
| `IgnoresHitTesting` | [UID:0002PC][0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting](by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md) | Returns hit-test suppression byte. |
| adjustor thunks | `0x0049af3d-0x0049af52` | Two IDA-confirmed 0xb-byte destructor adjustor thunks; compiler-generated. |
| `ScalarDeletingDestructor` | `0x0049b170-0x0049b1aa` | Destructor/delete thunk; generated body currently references a derived-base artifact. |

## Evidence Notes

- IDA MCP reports 52 direct constructor callers.
- Constructor callers include browser, minimap, checkbox, EPF image, fitting-room, popup, and text-button controls.
- IDA `list_globals` confirms `ControlPane` vtable bases at `0x00617a90`, `0x00617af8`, and `0x00617b28`; the tertiary table is short and ends before neighboring `ProgressBarControlPane` RTTI.
- 2026-06-01 IDA MCP recheck splits the old local `0x004949e0-0x00494bf6` memory page into exact canonical children for the constructor and hit-test suppression accessor. The address space between them includes padding, progress-bar range helpers, and small button/radio-control helpers, so it is not one continuous `ControlPane` source body.

## Cross-References

- [UID:0000IG][ControlPane](by-file/ControlPane.md)
- [UID:000114][0x004949e0-0x00494bf7.ControlPane](by-memory/0x004949e0-0x00494bf7.ControlPane.md)
- [UID:0002PB][0x004949e0-0x00494a81.ControlPaneConstructor](by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md)
- [UID:0002PC][0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting](by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- [UID:000120][0x0049af3d-0x0049af52.ControlPaneAdjustorThunks](by-memory/0x0049af3d-0x0049af52.ControlPaneAdjustorThunks.md)
- [UID:0000A2][Pane](by-class/Pane.md)
- [UID:0000EJ][TextButtonControlPane](by-class/TextButtonControlPane.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `76/82`.
  - Summary/evidence: base-control role, constructor, hit-test helper, destructor thunks, vtable addresses, broad caller set, and inheritance/file cross-references are documented; remaining work is exact semantic naming for tiny virtuals and final source-facing destructor representation.

- 2026-06-01:
  - Before: constructor and hit-test helper were referenced only through the broad local memory page.
  - After: exact canonical child pages were added for both functions and linked from the method table.
  - Summary/evidence: IDA MCP confirms function boundaries at `0x004949e0-0x00494a81` and `0x00494bf0-0x00494bf7`, and the neighborhood inventory shows non-`ControlPane` helper code between them.
