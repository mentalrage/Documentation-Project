*** UID:00009O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ObjectImageControlPane

## Status

- Confidence: strong for class role and principal method boundaries.
- Likely source file: [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md)
- Current recovered file: `source-3/simroot_v2/class_ObjectImageControlPane.cpp`
- Address range: [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md)

## Class Purpose

`ObjectImageControlPane` is a `ControlPane`-derived image preview widget. It copies a 68-byte object image descriptor, centers the resolved image inside its pane bounds, and paints human, monster, or EPF item/NPC imagery depending on the descriptor type.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ObjectImageControlPane` | `0x00520540-0x005205b4` | Constructs a type `8` control pane, installs three vtable pointers, initializes/copies image descriptor state. |
| `OnPaint` | `0x005205c0-0x00520816` | Initializes render context, invalidates the pane origin, measures the descriptor-specific image, centers it, and dispatches to human, monster, or EPF frame rendering; endpoint includes the final `retn`. |
| Adjustor thunks | `0x00520afd-0x00520b12` | Compiler-generated secondary-vtable thunks that forward to the scalar deleting destructor after this-pointer adjustment. |
| `ScalarDeletingDestructor` | `0x00520ca0`, size `0x3b` | Calls shared pane-base teardown `0x00544580`, then conditionally frees through `0x004f4ac0` according to scalar-delete flags. |

## Evidence Notes

- Wave3 summary gives manual/effective grade `96.3` and auto grade `100.0`.
- IDA MCP confirms the two main function ranges and the non-contiguous thunk/destructor ranges.
- IDA MCP reports direct constructor refs from menu/dialog constructors and from `ObjectImageButtonPane::ObjectImageButtonPane`.
- 2026-05-24 IDA MCP decompiles the deleting destructor as `sub_544580(this)` plus conditional `sub_4F4AC0(this)`. The generated `TextButtonExControlPane` base label is owner-name pollution; IDA only proves the shared pane-base teardown helper.

## Cross-References

- [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md)
- [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md)
- [UID:00009N][ObjectImageButtonPane](by-class/ObjectImageButtonPane.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page already documented class purpose, method boundaries, destructor support, constructor callers, and owner-pollution caveats.
- Changed to: `COMPLETION:78` and `CONFIDENCE:84`.
- Evidence: constructor, `OnPaint`, non-contiguous thunks/destructor, descriptor rendering behavior, caller sources, and generated base-label pollution are documented; remaining gaps are detailed field names and full reconstructed C++.
