*** UID:000074 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LegendPane

## Status

- Confidence: strong for constructor behavior; medium for final source-file ownership.
- Likely source file: [UID:0000KM][LegendPane](by-file/LegendPane.md), pending broader look-pane split review.
- Address range: [UID:0001HB][0x0056c400-0x0056c493.LegendPane](by-memory/0x0056c400-0x0056c493.LegendPane.md)
- Current recovered file: `source-3/simroot_v2/class_LegendPane.cpp`

## Class Purpose

`LegendPane` is a small read-only legend/key child pane used by look-panel views. The constructor chooses resolution-dependent geometry, initializes the common pane/text-edit base, installs `LegendPane` vtables, and stores a fixed scroll or mode value of `63` at offset `0x104`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x0056c400-0x0056c493` | Constructs the legend pane with high/low resolution geometry and installs the `LegendPane` vtable. |

## Evidence Notes

- Wave3 reports `LegendPane` grade `97.5` with one active constructor.
- IDA confirms constructor xrefs at `0x0056571c`, `0x0056ff6e`, and `0x0059f428`.
- The `0x0059f428` xref comes from `UserLookPane::UserLookPane`, which stores the constructed object at `this[64]`.
- The other xrefs are in self-look paths, so this class should not be treated as exclusively owned by `UserLookPane.cpp` without a broader self-look review.

## Cross-References

- [UID:0000KM][LegendPane](by-file/LegendPane.md)
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)
- [UID:0001HB][0x0056c400-0x0056c493.LegendPane](by-memory/0x0056c400-0x0056c493.LegendPane.md)
- [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md)
- [UID:0000FP][UserLookPane](by-class/UserLookPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `72/74`. Summary: the small constructor-only class has clear behavior, vtable family, geometry, and caller evidence, but final source-file ownership remains only medium confidence. Evidence: constructor range, look-pane xrefs, `UserLookPane` storage evidence, and self-look path caveat.
