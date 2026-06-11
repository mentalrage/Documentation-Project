*** UID:0001W7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SpecializedButtonPane Layouts

## Status

- Confidence: strong for observed offsets, medium for final original type names.
- Likely owner headers: `ui/controls/DirectionButtonControlPane.h`, `ui/controls/GenderButtonControlPane.h`, and `ui/controls/CheckBoxTextControlPane.h`, or a shared specialized-button header.
- Primary file doc: [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)
- Vtable doc: [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md)

## Shared Base Shape

These controls use the same multiple-vtable `ControlPane`/`ButtonControlPane` shape seen across pane controls:

| Offset | Field | Evidence |
| --- | --- | --- |
| `0x00` | primary vtable pointer | Constructors/inline setup and scalar deleting destructors install concrete class vtables. |
| `0xa0` | secondary vtable pointer | Inline setup and destructors write the class secondary vtable. |
| `0xa4` | tertiary vtable pointer | Inline setup and destructors write the class tertiary vtable. |
| `0x44` | bounds/draw rect subobject | Paint methods copy an OWORD from `this + 0x44` before drawing frames. |
| `0x101` | enabled/pressed byte | Paint paths test byte `+0x101` before drawing disabled overlay. |
| `0x103` | visual state byte | State methods compare this byte against the incoming state before updating subclass frame state. |

The exact inherited names should stay with [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) and `ControlPane`; this page only records subclass-specific fields.

## DirectionButtonControlPane

Observed object allocation in `NewUserMiscDialogPane` is `0x114` bytes.

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `0x10c` | direction index | Inline setup writes `0` for left and `1` for right. `OnPaint` uses this as `2 * directionIndex` in the `DIREC.EPD` frame index. |
| `0x110` | visual-state frame offset | Inline setup clears it. `SetEnabled` writes `1` when incoming state is `0x0b`; `OnPaint` adds it to the frame index. |

## GenderButtonControlPane

Observed object allocation in `NewUserMiscDialogPane` is `0x118` bytes.

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `0x10c` | gender index | Inline setup writes `0` for one gender option and `1` for the other. `OnPaint` uses `3 * genderIndex` in the `GENDERBT.EPF` frame index. |
| `0x110` | visual-state frame offset | Inline setup writes `2` for the first option and `0` for the second. `SetEnabled` writes `1` when incoming state is `0x0b`; `OnPaint` adds it to the frame index. |
| `0x114` | selected/default flag | Inline setup writes `1` for the initially selected option and `0` for the other. Current IDA paint/state methods do not consume this byte directly. |

## CheckBoxTextControlPane

Observed object allocation in `PartySearchEditPane` is `0x30c` bytes.

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `0x108` | checked byte | Constructor-shaped bytes store the initial checked flag. `PartySearchEditPane::OnAction` reads and toggles this byte directly. `OnPaint` selects the on/off tile using this byte. |
| `0x10a` | `wchar_t label[0x100]` | Constructor-shaped bytes copy the label with a 256-wide-character count. `OnPaint` scans and draws the string from this offset twice for shadow/foreground text. |

The current generated summary for `0x004214c0` is misleading: IDA decompiles it as a constant control-type helper returning `0x16`, not as a checked-state getter.

## Evidence

- 2026-05-26 IDA MCP decompilation of `0x004fb630` shows `NewUserMiscDialogPane::NewUserMiscDialogPane` allocating `0x118`-byte gender controls and `0x114`-byte direction controls, then writing the concrete vtables and subclass fields listed above.
- 2026-05-26 IDA MCP decompilation of `0x005006d0`, `0x00500700`, `0x005007f0`, and `0x00500820` confirms the state and paint field usage for gender/direction buttons.
- 2026-05-26 IDA MCP decompilation of `0x0059df50` confirms `CheckBoxTextControlPane` reads checked byte `+0x108` and label buffer `+0x10a` during paint.
- 2026-05-31 IDA MCP recheck confirmed the same function boundaries and field accesses: `0x005006d0` writes `+0x110` when state `0x0b` arrives, `0x00500700` reads `+0x10c/+0x110` for the `GENDERBT.EPF` frame index, `0x005007f0` writes `+0x110` from state `0x0b`, `0x00500820` reads `+0x10c/+0x110` for the `DIREC.EPD` frame index, `0x0059df50` reads the checkbox byte and label buffer, and `0x004214c0` returns constant control type `0x16`.
- 2026-06-06 IDA MCP recheck reconfirmed the gender/direction layout evidence from the class pages: `0x00500640` and `0x005007a0` remain raw `NOFUNC` constructor-shaped starts with no entry xrefs/callers, but vtable store refs from those raw bodies and from inline `NewUserMiscDialogPane` setup still target `0x0061db90` and `0x0061dc34`. The modeled state/paint methods remain `0x005006d0`/`0x00500700` for gender and `0x005007f0`/`0x00500820` for direction, with the state methods delegating through `0x00494b80` and paint methods using the resource/render helper family.

## Cross-References

- [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)
- [UID:00005P][GenderButtonControlPane](by-class/GenderButtonControlPane.md)
- [UID:00003X][DirectionButtonControlPane](by-class/DirectionButtonControlPane.md)
- [UID:000022][CheckBoxTextControlPane](by-class/CheckBoxTextControlPane.md)
- [UID:0001A4][0x00500640-0x00502754.SpecializedButtonPanes](by-memory/0x00500640-0x00502754.SpecializedButtonPanes.md)
- [UID:0001KJ][0x0059ded0-0x0059f0a4.CheckBoxTextControlPane](by-memory/0x0059ded0-0x0059f0a4.CheckBoxTextControlPane.md)

## Changes

- 2026-05-31: Metadata had `COMPLETION:0`, `CONFIDENCE:0`, and no reconstructable flag despite existing IDA-backed layout notes. Changed to `COMPLETION:72`, `CONFIDENCE:82`, and `RECONSTRUCTABLE:TRUE` after rechecking the key layout offsets and helper behavior in IDA MCP. The score remains below the final-source threshold because constructor-shaped ranges for some controls are still not clean IDA function starts and final original field/type names remain partly inferred.
- 2026-06-06: Raised score to `78/84` after refreshing the gender/direction evidence while updating the related class pages. Live IDA MCP still leaves both constructor starts raw/no-xref, but it reconfirms the modeled state/paint/destructor functions, vtable refs, inline setup stores, and resource/render/base-handler callees that support the documented subclass offsets. Final source field names, inherited base layout names, and whether the raw constructor bodies should become standalone source members remain open.
