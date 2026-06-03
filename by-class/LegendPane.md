*** UID:000074 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LegendPane

## Status

- Confidence: strong for constructor bounds, behavior, callers, vtables, and shared `ui/panels/` placement; medium-high for final standalone-versus-merged source ownership.
- Likely source file: [UID:0000KM][LegendPane](by-file/LegendPane.md), with a documented broader look-pane split caveat.
- Address range: [UID:0001HB][0x0056c400-0x0056c493.LegendPane](by-memory/0x0056c400-0x0056c493.LegendPane.md)
- Current recovered file: `source-3/simroot_v2/class_LegendPane.cpp`
- Vtable/layout anchor: [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)

## Class Purpose

`LegendPane` is a small read-only legend/key child pane used by look-panel views. The constructor chooses resolution-dependent geometry, initializes the common pane/text-edit base, installs `LegendPane` vtables, and stores a fixed scroll or mode value of `63` at offset `0x104`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x0056c400-0x0056c493` | Constructs the legend pane with high/low resolution geometry and installs the `LegendPane` vtable. |

## Evidence Notes

- [UID:0001HB][0x0056c400-0x0056c493.LegendPane](by-memory/0x0056c400-0x0056c493.LegendPane.md) records IDA-confirmed exact bounds, raw bytes, surrounding `0xcc` padding, the `byte_66DA97` resolution branch, `sub_4B60B0` and `sub_58DCE0` callees, and the `this+0x104 = 63` state write.
- IDA caller/xref checks in the memory page confirm exactly three direct constructor callers: `SelfLookPane::SelfLookPane` at `0x0056571c`, `SelfLookPane2::SelfLookPane2` at `0x0056ff6e`, and `UserLookPane::UserLookPane` at `0x0059f428`.
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md) records `LegendPane` vtable bases at `0x00624388`, `0x00624400`, and `0x00624430`; current generated metadata reporting no vtables is a Wave3 data issue, not source-layout evidence.
- [UID:0000KM][LegendPane](by-file/LegendPane.md) has a valid `NexusTK/ui/panels/` reconstruction path and documents why `LegendPane` is a shared look/status child instead of being exclusively owned by either self-look or user-look source.

## Autogen Status

- Reconstructable: true for the class and constructor semantics.
- Parent: [UID:0000KM][LegendPane](by-file/LegendPane.md), the current shared `ui/panels/LegendPane.cpp` source bucket.
- Code: intentionally blank. The constructor is well bounded, but final C++ remains below the 95+ gate until helper/base names and the standalone-versus-merged source decision are final-audit quality.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 82 | Exact constructor bounds, caller/callee set, touched state, vtable bases, padding boundaries, source bucket, and ownership caveat are documented through linked pages. Completion is not higher because the class page is still a summary and final source placement remains open. |
| Confidence | 86 | The constructor, vtables, and shared child-pane role are backed by written IDA evidence. Confidence stays below final-source quality because the original standalone/local class split is unresolved and generated source still uses provisional helper/base names. |

## Cross-References

- [UID:0000KM][LegendPane](by-file/LegendPane.md)
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)
- [UID:0001HB][0x0056c400-0x0056c493.LegendPane](by-memory/0x0056c400-0x0056c493.LegendPane.md)
- [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md)
- [UID:0000FP][UserLookPane](by-class/UserLookPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `72/74`. Summary: the small constructor-only class has clear behavior, vtable family, geometry, and caller evidence, but final source-file ownership remains only medium confidence. Evidence: constructor range, look-pane xrefs, `UserLookPane` storage evidence, and self-look path caveat.
- 2026-06-03 source-owner and score update:
  - What existed before: the page was scored `72/74`, had no reconstructable/autogen parent metadata, and summarized vtable/caller evidence indirectly.
  - Changed to: scores `82/86`; `RECONSTRUCTABLE:TRUE`; parent [UID:0000KM][LegendPane](by-file/LegendPane.md) at position `5`; C++ block remains empty.
  - Summary/evidence: exact memory documentation, source-root placement, and look-pane vtable-family documentation now support stronger class metadata. Final source C++ remains gated by unresolved helper/base names and the standalone-versus-merged look-pane source split.
