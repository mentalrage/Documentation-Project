*** UID:0000KM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# LegendPane

## Status

- Confidence: strong for constructor behavior and `ui/panels/` placement; medium-high for whether it was originally standalone or local to a broader look/status translation unit.
- Proposed module: `ui/panels/LegendPane.cpp`, with an open split question over standalone file versus a broader look/status pane source.
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

- 2026-06-01 IDA MCP confirms `LegendPane::LegendPane` is exactly `0x0056c400-0x0056c493`; the previous bytes `0x0056c3f1-0x0056c400` and following bytes `0x0056c493-0x0056c4a0` are `0xcc` alignment.
- IDA confirms constructor xrefs from `SelfLookPane::SelfLookPane` at `0x0056571c`, `SelfLookPane2::SelfLookPane2` at `0x0056ff6e`, and `UserLookPane::UserLookPane` at `0x0059f428`.
- IDA confirms constructor-only callees `sub_4B60B0` and `sub_58DCE0`; the body uses `byte_66DA97` for resolution-dependent geometry, installs vtables `0x00624388`, `0x00624400`, and `0x00624430`, and initializes the fixed legend mode/scroll field to `63`.
- Because both self-look and user-look construct it, this page is a shared `ui/panels/` source root candidate rather than an attachment to either one caller. Final migration can still merge the class into a broader look/status source if stronger original-source evidence appears.

## Cross-References

- [UID:000074][LegendPane](by-class/LegendPane.md)
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)
- [UID:0001HB][0x0056c400-0x0056c493.LegendPane](by-memory/0x0056c400-0x0056c493.LegendPane.md)
- [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md)
- [UID:0000P0][UserLookPane](by-file/UserLookPane.md)

## Changes

- 2026-06-01: Assigned projected path `NexusTK/ui/panels/` and raised metadata from `76/78` to `80/82`.
  - Evidence: `by-project-structure/proposed-source-tree.md` already lists `ui/panels/LegendPane.cpp`; IDA MCP confirms the exact constructor range, three look-panel constructor callers, vtable stores, resolution global refs, and surrounding padding.
  - Scope: source folder/root assignment only. The final standalone-versus-merged translation-unit question remains documented, and no reconstructed C++ is emitted.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:76` and `CONFIDENCE:78`.
  - Summary/evidence: constructor role, look/status panel callers, vtable/layout anchor, and source-ownership caveat are documented; completion remains moderate because the page is concise and final ownership depends on the broader self-look/user-look split.
