*** UID:0000FP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# UserLookPane

## Status

- Confidence: strong for class purpose and IDA function boundaries; medium for some field names in generated source.
- Likely source file: [UID:0000P0][UserLookPane](by-file/UserLookPane.md)
- Address range: [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md)
- Current recovered file: `source-3/simroot_v2/class_UserLookPane.cpp`

## Class Purpose

`UserLookPane` is the remote-character look/profile panel. It is constructed by the general-purpose side panel, receives a server-provided look/profile packet, converts multiple text fields to wide strings, parses the character appearance blob, stores portrait payload data, populates text-edit child panes, renders the look overview, and switches among more-info, profile, biography, and legend views.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x0059f260-0x0059f4fd` | Initializes `PanelPane`, installs `UserLookPane` vtables, creates `MoreInfoPane`, `ProfilePane`, and `LegendPane` children, initializes portrait storage and mode fields. |
| non-deleting destructor | `0x0059f500-0x0059f604` | IDA-confirmed cleanup body for child panes, portrait buffer, auxiliary object at `this + 0xd9c`, and base `PanelPane`; currently not modeled by Wave3. |
| `ParseLookPacket` | `0x0059f610-0x005a0626` | Parses server look/profile payload strings, appearance blob, option/config rows, portrait data, rich-text rows, and child text panes. |
| `RenderUserLook` | `0x005a0640-0x005a157d` | Paints the selected remote-character look view, including equipment/body rendering, text labels, portrait state, and mode-specific action buttons. |
| `OnMouseEvent` | `0x005a1580-0x005a1985` | Handles button hit tests and view changes from mouse input. |
| `OnKeyEvent` | `0x005a19a0-0x005a1a6f` | Handles keyboard-driven view changes. |
| `GetActionButtonRect` | `0x005a1a70-0x005a1b4d` | Computes action-button rectangles used by paint and hit-test paths. |
| `HitTestActionButton` | `0x005a1b70-0x005a1caf` | Maps mouse coordinates to action-button ids. |
| `ShowMoreInfoView` | `0x005a1cd0-0x005a1dee` | Selects mode `0`, attaches/lays out `MoreInfoPane`, and hides profile/legend children as needed. |
| `ShowProfileView` | `0x005a1df0-0x005a1f16` | Selects mode `1` and toggles profile display while hiding other child panes. |
| `ShowBioView` | `0x005a1f20-0x005a1fe3` | Selects mode `2`, lays out `ProfilePane` for the biography text, and hides other child panes. |
| `ShowLegendView` | `0x005a1ff0-0x005a2188` | Selects mode `3`, lays out `LegendPane`, and adjusts scroll/height fields for the current resolution mode. |
| adjustor thunks | `0x005a23d5-0x005a23eb` | Excluded adjustor thunks forwarding to the scalar deleting destructor. |
| scalar deleting destructor | `0x005a23f0-0x005a2523` | Deletes owned child panes, releases portrait storage, tears down auxiliary state, destroys base pane, and optionally frees `this`. |

## Child Panes

- [UID:00008Q][MoreInfoPane](by-class/MoreInfoPane.md) is allocated by the constructor and stored at `this[62]`.
- [UID:0000AV][ProfilePane](by-class/ProfilePane.md) is allocated by the constructor and stored at `this[63]`.
- [UID:000074][LegendPane](by-class/LegendPane.md) is allocated through `0x0056c400` and stored at `this[64]`, but is shared with self-look paths and needs a broader owner review.

## Evidence Notes

- Wave3 reports no missing refs for `UserLookPane`.
- IDA confirms the constructor xref from `GeneralPurposePanel` at `0x004b8477`.
- IDA confirms the packet/render/input/view-switch/destructor function starts listed above.
- IDA reports `0x0059f500` as a real function with no normal code xrefs; its body matches the scalar deleting destructor cleanup body without the final conditional delete.

## Cross-References

- [UID:0000P0][UserLookPane](by-file/UserLookPane.md)
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)
- [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md)
- [UID:00008Q][MoreInfoPane](by-class/MoreInfoPane.md)
- [UID:0000AV][ProfilePane](by-class/ProfilePane.md)
- [UID:000074][LegendPane](by-class/LegendPane.md)
- [UID:00005Q][GeneralPurposePanel](by-class/GeneralPurposePanel.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:82`.
  - Summary/evidence: scored from the constructor, packet parse, render, input, action-button, view-switch, destructor, child-pane, xref, and boundary documentation; confidence remains capped by medium confidence on some generated field names and the `LegendPane` ownership caveat.
