*** UID:0000KM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# LegendPane

## Status

- Confidence: strong for constructor behavior; medium for final original source-file ownership.
- Proposed module: `ui/panels/LegendPane.cpp`, or a local class in a broader look/status pane source after self-look/user-look split review.
- Current recovered source: `class_LegendPane.cpp`
- Main address doc: [UID:0001HB][0x0056c400-0x0056c493.LegendPane](by-memory/0x0056c400-0x0056c493.LegendPane.md)
- Vtable/layout anchor: [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)

## File Role

`LegendPane` is a small reusable legend/key child pane used by look/status panels. It initializes a `TextEditPane`-style read-only pane with resolution-dependent geometry, installs the `LegendPane` vtable, and stores a fixed mode/scroll value used by the legend display.

IDA confirms `LegendPane` vtable bases at `0x00624388`, `0x00624400`, and `0x00624430`. Current generated metadata reports `vtable_count: 0`, so the family page is the stronger layout anchor.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `LegendPane` constructor | `0x0056c400-0x0056c493` | Constructs the shared legend child pane and initializes its fixed display state. |

## Evidence Notes

- Wave3 reports `LegendPane` grade `97.5`.
- IDA confirms constructor xrefs from `SelfLookPane::SelfLookPane` at `0x0056571c`, `SelfLookPane2::SelfLookPane2` at `0x0056ff6e`, and `UserLookPane::UserLookPane` at `0x0059f428`.
- Because both self-look and user-look construct it, final source ownership should be decided during the broader look-pane split rather than by one caller.

## Cross-References

- [UID:000074][LegendPane](by-class/LegendPane.md)
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)
- [UID:0001HB][0x0056c400-0x0056c493.LegendPane](by-memory/0x0056c400-0x0056c493.LegendPane.md)
- [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md)
- [UID:0000P0][UserLookPane](by-file/UserLookPane.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:76` and `CONFIDENCE:78`.
  - Summary/evidence: constructor role, look/status panel callers, vtable/layout anchor, and source-ownership caveat are documented; completion remains moderate because the page is concise and final ownership depends on the broader self-look/user-look split.
