*** UID:00009O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000M3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ObjectImageControlPane

## Status

- Confidence: strong for class role and principal method boundaries.
- Likely source file: [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md)
- Address range: [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md)
- Parent attachment: enabled because this class page, its memory-range page, and the owning file page all meet the 80%+ completion/confidence gate.

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

- [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md) documents the constructor field writes, the `OnPaint` descriptor branches, vtable refs, byte-boundary checks, and the associated non-contiguous thunks/destructor.
- [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md) documents the broader source family and explains why the object-image button sibling belongs adjacent to this reusable preview control rather than in a generic button bucket.
- Constructor call sites from menu/dialog constructors and from `ObjectImageButtonPane::ObjectImageButtonPane` support a reusable control class instead of a single feature-dialog owner.
- The deleting destructor evidence resolves only the shared pane-base teardown helper plus conditional delete helper; generated `TextButtonExControlPane`/`Pane` labels remain owner-name pollution, not inheritance proof.

## Attachment and Reconstruction State

- Attached to [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md) after the class page was refreshed from nearby by-file/by-memory evidence and raised above the child attachment gate.
- Keep final C++ withheld: the class role, methods, and descriptor rendering behavior are strong, but final field names and a source-quality class declaration are not yet proven at the 95/95 level.
- Keep `ObjectImageButtonPane` as a sibling class with its own page; this page should summarize the base preview behavior and point to the button subclass rather than absorbing its command handling.

## Cross-References

- [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md)
- [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md)
- [UID:00009N][ObjectImageButtonPane](by-class/ObjectImageButtonPane.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-06-06: Raised completion from `78` to `82`, attached the class to [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md), removed stale generated-source/Wave-derived framing from the evidence notes, and added an attachment/reconstruction-state section. Confidence stays `84` because the existing by-memory evidence proves behavior and ownership, while final field names and source-quality declarations remain open.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed constructor, paint, adjustor, and deleting-destructor functions at `0x00520540`, `0x005205c0`, `0x00520afd`, `0x00520b08`, and `0x00520ca0`. Left `AUTOGEN_PARENT_UID` blank because this class is still below the 80 completion attachment gate even though likely parent [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md) passes the parent score gate.
- Before: completion/confidence metadata were `0/0` even though the page already documented class purpose, method boundaries, destructor support, constructor callers, and owner-pollution caveats.
- Changed to: `COMPLETION:78` and `CONFIDENCE:84`.
- Evidence: constructor, `OnPaint`, non-contiguous thunks/destructor, descriptor rendering behavior, caller sources, and generated base-label pollution are documented; remaining gaps are detailed field names and full reconstructed C++.
