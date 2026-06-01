*** UID:0001TX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CheckBoxControlPaneLayout

## Status

- Entity kind: class layout support struct
- Current Wave3 struct id: `CheckBoxControlPane`
- Likely owner: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md), or split candidate [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md)
- Confidence: strong for offsets used by constructor, paint, mouse, and checked-state accessors; medium for inherited subobject names and final original source-file split.
- Evidence basis: read-only IDA MCP lookup/decompile/caller checks on 2026-05-31, plus earlier vtable checks from 2026-05-25. Generated `simroot_v2` names are retained only as search/context leads. `wave3.py` was not executed for this pass.

## Layout

```text
CheckBoxControlPane  // observed size 0x150
  +0x000  ControlPane base / primary vtable
  +0x0a0  secondary vtable pointer       // constructor writes 0x00618540
  +0x0a4  tertiary vtable pointer        // constructor writes 0x00618570
  +0x108  wchar_t tileName[16]           // e.g. "ONOFFBUT.EPF"
  +0x128  wchar_t paletteName[16]        // e.g. "BUTTON.PAL"
  +0x148  int16_t checkedFrame
  +0x14a  int16_t uncheckedFrame
  +0x14c  uint8_t checked
  +0x14d  padding/alignment to 0x150
```

The current generated field names preserve only coarse Ghidra fields at `+0x108` and `+0x128`, but the constructor copies two 16-wide-character strings there with `wcscpy_s(..., 0x10, ...)`.

## IDA Evidence

IDA MCP `lookup_funcs` confirms the checkbox method cluster as six adjacent functions: constructor `0x00499d40-0x00499db9`, setter `0x00499dc0-0x00499dcf`, getter `0x00499dd0-0x00499dd6`, mouse handler `0x00499de0-0x00499e2c`, paint handler `0x00499e30-0x00499ebf`, and state/type helper `0x00499ec0-0x00499f0d`.

IDA decompilation confirms the constructor calls the generic control constructor with type `7`, installs the three `CheckBoxControlPane` vtables at offsets `+0x000`, `+0x0a0`, and `+0x0a4`, clears byte `this+0x14c`, copies two bounded wide strings into `this+0x108` and `this+0x128` with count `0x10`, and stores two 16-bit frame ids at `this+0x148` and `this+0x14a`.

The setter and getter at `0x00499dc0` and `0x00499dd0` access only byte `this+0x14c`. The mouse handler toggles that byte on event byte `3` inside the hit rectangle and then notifies through virtual slot `+0x20`. The paint handler reads byte `+0x14c` to choose between the signed 16-bit frame fields at `+0x148/+0x14a`, passes `this+0x108` to the EPF frame lookup, and passes `this+0x128` as the palette/draw string.

IDA caller checks confirm direct constructor callers at `0x00450f60`, `0x0045100d`, and `0x0047d3b4`; the setter callers are the two minimap initialization sites, and the getter caller is the mail send path at `0x0047dfd0`.

## Field Semantics

`tileName` is passed to the EPF layout lookup in [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md). `paletteName` is passed as the final draw argument. Confirmed callers construct minimap and mail checkboxes with `L"ONOFFBUT.EPF"` and `L"BUTTON.PAL"`, so the second string should not be documented as a user-visible label.

`checkedFrame` and `uncheckedFrame` are selected by [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md) based on the `checked` byte. [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md) writes `+0x14c`; [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md) reads the same byte.

## Source-Layout Notes

`CheckBoxControlPane` behaves like a generic choice control. It is used by [UID:0000LE][MiniMap](by-file/MiniMap.md) for NPC/portal toggles and by [UID:000096][NewMailDialog](by-class/NewMailDialog.md) for the "Keep a copy" option. The breadth is small but cross-feature, so current source-layout evidence still favors keeping it with the broader [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) generic button/choice-control module unless a later original-source split is proven.

## Cross-References

- [UID:000021][CheckBoxControlPane](by-class/CheckBoxControlPane.md)
- [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md)
- [UID:0001X8][CheckBoxControlPaneVtables](by-type/by-vtable/CheckBoxControlPaneVtables.md)
- [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md)
- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)

## Open Questions

- Confirm whether the original source kept `CheckBoxControlPane` in the broader `ButtonControlPane` module or split it into its own source file.
- Name the inherited subobject views at `+0x0a0/+0x0a4` after the surrounding `ControlPane`/button-control hierarchy is fully audited.

## Changes

- Reclassified the page from unevaluated to reconstructable layout documentation with conservative scores. Evidence: IDA MCP lookup/decompile/caller checks on 2026-05-31 directly verify the field offsets used by the constructor, accessor, mouse, and paint methods; final source-file split and inherited subobject names remain below near-final confidence.
