*** UID:0000NY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:55 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Specialized Button Panes

## Status

- Confidence: medium.
- Proposed modules: likely split between `ui/controls/DirectionButtonControlPane.cpp`, `ui/controls/GenderButtonControlPane.cpp`, and `ui/controls/CheckBoxTextControlPane.cpp`. `ObjectImageButtonPane` is now better placed with [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md).
- Current recovered sources: `class_DirectionButtonControlPane.cpp`, `class_GenderButtonControlPane.cpp`, `class_ObjectImageButtonPane.cpp`, and `class_CheckBoxTextControlPane.cpp`.
- Type docs: [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md), [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md)

## File Role

These classes are specialized button-like panes that reuse the generic button/control infrastructure but add domain-specific graphics:

- `DirectionButtonControlPane` draws directional arrows from `DIREC.EPD`.
- `GenderButtonControlPane` draws gender-selection sprites and state overrides; the generated `0x004fb630` owner row belongs to `NewUserMiscDialogPane`, not this control.
- `ObjectImageButtonPane` renders an object or character image centered inside a button pane and derives from the reusable `ObjectImageControlPane`; keep it with the object-image control source family unless later source-file evidence proves otherwise.
- `CheckBoxTextControlPane` paints a checkbox plus shadowed text label.

They should not be merged into feature dialogs purely because generated helper names mention fitting-room or new-user code. IDA MCP confirmed several generated constructor addresses in this group are not function starts in the current IDB, so the class starts need further verification before source moves.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `DirectionButtonControlPane` | `0x005007a0-0x005008b8`, `0x0050248a-0x005026f4` | Direction arrow control over `DIREC.EPD`; virtual methods/destructor are IDA-confirmed, but standalone constructor start is not. |
| `GenderButtonControlPane` | `0x00500640-0x00502754` | Gender-selection button behavior and cleanup; virtual methods/destructor are IDA-confirmed, standalone constructor start is not, and the generated `0x004fb630` row is owner pollution. |
| `ObjectImageButtonPane` | `0x00520820-0x00520a8f`, thunks `0x00520ae7`/`0x00520af2`, destructor `0x00520c60-0x00520c9a`, plus type id at `0x004242f0` | Historical/provisional staging only; current preferred owner is [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md). |
| `CheckBoxTextControlPane` | constructor-shaped bytes `0x0059ded0-0x0059df24`, helper `0x0059df30-0x0059df4e`, paint `0x0059df50-0x0059e0ab`, thunks/destructor `0x0059efeb-0x0059f0a4`, and type helper [UID:0002DZ][0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType](by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType.md) | Checkbox plus label control; constructor bytes are real but not an IDA function, and the type helper returns control type `0x16` rather than checked state. |

## Evidence Notes

- IDA MCP reports `ObjectImageButtonPane::ObjectImageButtonPane` at `0x00520820` has one direct code xref from `0x00551479`.
- `ObjectImageButtonPane` directly calls `ObjectImageControlPane::ObjectImageControlPane` at `0x00520830`; current source-placement preference is to pair it with [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md), with this file retaining only a cross-reference.
- IDA MCP does not currently recognize `0x00500640`, `0x005007a0`, or `0x0059ded0` as function starts, even though Wave3 imports them as constructors.
- The painting methods at `0x005006d0`, `0x00500700`, and `0x0059df50` are IDA-recognized functions, so the class behavior is real even where constructor boundaries are suspect.
- 2026-05-24 IDA MCP confirms `0x004fb630-0x004fbfcf` is `NewUserMiscDialogPane::NewUserMiscDialogPane`, not `GenderButtonControlPane`; the generated `class_GenderButtonControlPane.cpp` row at that range came from child-control vtable writes inside the parent dialog constructor.
- 2026-05-24 IDA MCP recheck confirms no direct callers/xrefs for `0x00500640` or `0x005007a0`, while the real virtual methods and deleting destructors are referenced from `GenderButtonControlPane` and `DirectionButtonControlPane` vtables. `NewUserMiscDialogPane::NewUserMiscDialogPane` inlines both child-control setups.
- 2026-05-24 IDA recheck: `0x0059ded0` has constructor-shaped bytes with no function object or direct code xrefs; [UID:0000A7][PartySearchEditPane](by-class/PartySearchEditPane.md) instead inlines equivalent `CheckBoxTextControlPane` setup at `0x0059e22f-0x0059e265`.
- The generated `CheckBoxTextControlPane::GetControlType` summary is misleading. IDA decompiles `0x004214c0` as `return 22`, and the checked flag is the byte at offset `+0x108`.
- The exact `GetControlType` helper is now documented separately as [UID:0002DZ][0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType](by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType.md) because it lives in the mixed `0x00421310-0x004216cb` island, not inside the main `0x0059ded0` class-memory page.
- 2026-05-26 IDA MCP vtable/layout pass confirmed subclass field use for gender, direction, and checkbox/text controls. The adjustor thunks at `0x0050248a`, `0x00502495`, `0x005024a0`, `0x005024ab`, `0x0059efeb`, and `0x0059eff6` are compiler-generated vtable glue, not handwritten source routines.
- 2026-05-27 IDA MCP recheck still reports `0x00500640` and `0x005007a0` as `NOFUNC` with no xrefs, and a raw dword scan across loaded segments found no pointers to either address. The virtual starts `0x005006d0`, `0x00500700`, `0x005007f0`, and `0x00500820` remain real IDA functions with vtable refs. `0x004fb630` is still `NewUserMiscDialogPane::NewUserMiscDialogPane` with code caller `0x004fa74e`, and no raw pointer hits were found for that address.

## Cross-References

- [UID:00003X][DirectionButtonControlPane](by-class/DirectionButtonControlPane.md)
- [UID:00005P][GenderButtonControlPane](by-class/GenderButtonControlPane.md)
- [UID:00009N][ObjectImageButtonPane](by-class/ObjectImageButtonPane.md)
- [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md)
- [UID:000022][CheckBoxTextControlPane](by-class/CheckBoxTextControlPane.md)
- [UID:0002DZ][0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType](by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType.md)
- [UID:0001A4][0x00500640-0x00502754.SpecializedButtonPanes](by-memory/0x00500640-0x00502754.SpecializedButtonPanes.md)
- [UID:0001BV][0x00520820-0x00520c9a.ObjectImageButtonPane](by-memory/0x00520820-0x00520c9a.ObjectImageButtonPane.md)
- [UID:0001KJ][0x0059ded0-0x0059f0a4.CheckBoxTextControlPane](by-memory/0x0059ded0-0x0059f0a4.CheckBoxTextControlPane.md)
- [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md)
- [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md)

## Changes

- 2026-05-30: Existing file doc mentioned `CheckBoxTextControlPane` type helper `0x004214c0` as a raw address. Changed it to the exact by-memory UID page and clarified that it sits in a mixed adjacent island. Evidence: IDA MCP decompilation/data refs for `0x004214c0` and the split of [UID:0000WT][0x00421310-0x004216cb.SimpleUStringSso7](by-memory/0x00421310-0x004216cb.SimpleUStringSso7.md).
