*** UID:00009P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ObjectInfoObjectPane

## Status

- Confidence: strong for role and anchors.
- Likely source file: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- Current recovered file: `source-3/simroot_v2/class_ObjectInfoObjectPane.cpp`
- Current Wave3 grade: `96.7`
- Current Wave3 coverage: 8 modeled methods, zero missing target refs.

## Class Purpose

`ObjectInfoObjectPane` displays the floating name/object tooltip above an attached map object. It measures primary/alternate label text, uses sprite anchor information to place the label, and draws decorated or outlined label text according to config flags.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x005395b0-0x00539646` | Initializes attached/object label state, labels, flags, and vtables. |
| `UpdatePosition` | `0x00539700-0x0053975b` | Computes tooltip bounds and offsets them to the object screen position. |
| `ComputeTooltipRect` | `0x00539760-0x005398de` | Computes label bounds from image anchors, tile size, and selected label text. |
| `DrawTooltip` | `0x005398e0-0x00539b20` | Draws primary or alternate label text, including decorated name mode. |
| `UpdatePositionFromDirection` | `0x00539b20-0x00539bb2` | Repositions tooltip by directional screen offset. |
| scalar deleting destructor | `0x0053d620-0x0053d65b` | Tears down attached-object base and frees memory when requested. |

## Evidence Notes

- IDA shows repeated constructor xrefs from `MapPane::ProcessMapPacket` at `0x0050fb00`.
- The class should stay with attached object overlays rather than generic text controls; it depends on map object anchors and object-data sprite state.

## Cross-References

- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md)
- [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite purpose, method-map, caller, and source-placement notes.
- Changed to: `COMPLETION:74` and `CONFIDENCE:82`.
- Evidence: constructor, update, rect computation, draw, direction-offset, destructor, and `MapPane` construction evidence are documented; completion remains below high because field layout, detailed draw-state data flow, and reconstructed C++ are not exhaustive.
