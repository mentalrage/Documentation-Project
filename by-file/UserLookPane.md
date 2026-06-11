*** UID:0000P0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# UserLookPane

## Status

- Confidence: strong for `UserLookPane`, `MoreInfoPane`, and `ProfilePane` grouping and direct local-child ownership; medium-high for the final owner of shared `LegendPane`.
- Proposed module: `ui/panels/UserLookPane.cpp`
- Current recovered sources: `class_UserLookPane.cpp`, `class_MoreInfoPane.cpp`, `class_ProfilePane.cpp`, and shared `class_LegendPane.cpp`
- Main address doc: [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md)
- Related shared pane doc: [UID:0000KM][LegendPane](by-file/LegendPane.md)
- Vtable/layout anchor: [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)

## File Role

`UserLookPane.cpp` owns the remote-character look/profile panel created by `GeneralPurposePanel`. It parses the server look/profile payload, stores strings, appearance fields, option fields, and portrait payload data, renders the selected look/profile page, and switches among the more-info, profile/bio, and legend child views.

Portrait payloads use two decode paths: a non-`JPF` legacy bitmap path and a `JPF` path that calls the shared [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md) at `0x004d07b0` to decode embedded JPEG into the panel's portrait tile context.

`MoreInfoPane` and `ProfilePane` are tiny child pane classes allocated directly by the `UserLookPane` constructor. They only override two virtual gate methods to return false, so they should migrate with the user-look source unless later original-file evidence proves they were reusable elsewhere.

IDA confirms `UserLookPane`, `MoreInfoPane`, and `ProfilePane` vtables at `0x0062eccc-0x0062eeb4`. Current generated metadata reports `vtable_count: 0` for all three, so use the IDA-backed family page for layout evidence.

The Batch 093 parent-gate review raises confidence to `85` without changing the `LegendPane` caveat. The direct local-child relationship for `MoreInfoPane` and `ProfilePane` is independently supported by the executable aggregate, [UID:00026V][0x0062eccc-0x0062ef0c.UserLookReadOnlyData](by-memory/0x0062eccc-0x0062ef0c.UserLookReadOnlyData.md), [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md), and the singleton-slot docs. `LegendPane` may still migrate to a shared look-pane source, but that uncertainty does not weaken this file as the direct parent for `UserLookPane`'s two tiny read-only child panes.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `UserLookPane` | `0x0059f260-0x005a2523` | Constructs the look/profile panel, parses look packets, renders the remote-character view, handles mouse/key navigation, and tears down owned child panes and portrait storage. |
| `MoreInfoPane` | vtable stubs `0x005a2340`, `0x005a2350` | First read-only child text pane, created at `this + 0xf8`; rejects unsupported virtual action paths. |
| `ProfilePane` | vtable stubs `0x005a23c0`, `0x005a23d0` | Second read-only child text pane, created at `this + 0xfc`; rejects unsupported virtual action paths. |
| `UserLookPane` non-deleting destructor | `0x0059f500-0x0059f604` | IDA-confirmed destructor body used for cleanup/EH semantics, but currently unknown to Wave3. |
| `LegendPane` | constructor `0x0056c400-0x0056c493` | Shared look legend child used by `UserLookPane` and self-look paths; keep linked to [UID:0000KM][LegendPane](by-file/LegendPane.md), but final ownership may be a shared look-pane source. |

## Boundaries

- Keep [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md) as the owner of page composition and tab switching. It constructs `UserLookPane`, but it should not own the look/profile parser or rendering code.
- Keep [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md) separate. `ProfileDialog` is profile storage/edit UI; `ProfilePane` here is a read-only child pane used by the remote look panel.
- Do not merge `MoreInfoPane` or `ProfilePane` into generic text editor/control files. They are created by `UserLookPane::UserLookPane` after `sub_58DCE0` child pane construction and have only user-look vtable stubs.
- Treat `LegendPane` as shared look UI. IDA xrefs show calls from self-look and user-look paths (`0x0056571c`, `0x0056ff6e`, and `0x0059f428`), so final migration should review whether it belongs in `SelfLookPane.cpp`, `LegendPane.cpp`, or a broader look-pane source.

## Evidence Notes

- Wave3 reports `UserLookPane` grade `97.2`, summary "Displays a character look/profile panel with mode-specific rendering for overview, equipment, portrait, and legend pages", and no missing refs.
- IDA confirms `UserLookPane::UserLookPane` at `0x0059f260-0x0059f4fd`, with a direct constructor xref from `GeneralPurposePanel` at `0x004b8477`.
- IDA decompilation of the constructor shows allocation of two `372`-byte child panes, vtable installation for `MoreInfoPane` and `ProfilePane`, and construction of a third `LegendPane` child through `0x0056c400`.
- IDA confirms the view-switch methods `0x005a1cd0`, `0x005a1df0`, `0x005a1f20`, and `0x005a1ff0`; each hides/shows child panes, sets mode field `this[881]`, lays out the active child, and invalidates the panel.
- Wave3 does not model IDA function `0x0059f500`, even though IDA decompiles it as the same non-deleting cleanup body used inside the scalar deleting destructor at `0x005a23f0`.
- IDA caller checks on 2026-05-25 show `DecodeJpfImageToTileContext` at `0x004d07b0` has a direct caller at `0x0059fff4` inside `UserLookPane::ParseLookPacket`.

## Caveats

The current class-first recovered-source model splits `MoreInfoPane`, `ProfilePane`, and `LegendPane` into separate one-class files. That should not be treated as evidence that the original late-1999/mid-2000s source used four standalone `.cpp` files. For source reconstruction, `MoreInfoPane` and `ProfilePane` are stronger as local classes in `ui/panels/UserLookPane.cpp`; `LegendPane` remains a shared look-pane ownership question.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 88 | The file page already documents the main user-look constructor/parser/render/view-switch/destructor scope, local `MoreInfoPane`/`ProfilePane` child panes, JPF decode use, GeneralPurposePanel construction boundary, ProfileDialog boundary, and shared `LegendPane` caveat. Completion remains below final-source quality because exact source file split and final declarations are still pending. |
| Confidence | 85 | Confidence is now strong enough for direct child routing because executable, read-only-data, vtable-family, class, and singleton-slot docs agree that `MoreInfoPane` and `ProfilePane` are UserLookPane-local children. The score remains capped at 85 because `LegendPane` is shared with self-look paths and may belong in a separate or broader look-pane source. |
| Parent-gate use | Supports [UID:00008Q][MoreInfoPane](by-class/MoreInfoPane.md) | This file can serve as the direct parent for the local child panes under the strict 85/85 gate; the `LegendPane` uncertainty is a separate shared-child caveat rather than a blocker for MoreInfoPane/ProfilePane ownership. |

## Cross-References

- [UID:0000FP][UserLookPane](by-class/UserLookPane.md)
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)
- [UID:00008Q][MoreInfoPane](by-class/MoreInfoPane.md)
- [UID:0000AV][ProfilePane](by-class/ProfilePane.md)
- [UID:000074][LegendPane](by-class/LegendPane.md)
- [UID:0000KM][LegendPane](by-file/LegendPane.md)
- [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md)
- [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md)
- [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md)
- [UID:00026V][0x0062eccc-0x0062ef0c.UserLookReadOnlyData](by-memory/0x0062eccc-0x0062ef0c.UserLookReadOnlyData.md)
- [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md)
- [UID:0001HB][0x0056c400-0x0056c493.LegendPane](by-memory/0x0056c400-0x0056c493.LegendPane.md)

## Changes

- 2026-06-07 Batch 093 parent-gate refresh:
  - Before: `COMPLETION:88`, `CONFIDENCE:80`; strong grouping was documented, but the page did not separate the local child-pane gate from the shared `LegendPane` caveat.
  - After: `COMPLETION:88`, `CONFIDENCE:85`.
  - Why: the executable aggregate, read-only-data page, vtable-family page, and singleton-slot docs agree that `MoreInfoPane` and `ProfilePane` are local children constructed and used by `UserLookPane`. `LegendPane` remains a shared look-pane caveat, so confidence is capped at 85 rather than raised further.
- 2026-06-02: Set `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/"` to match the documented `ui/panels/UserLookPane.cpp` placement. The page already records strong UserLookPane/MoreInfoPane/ProfilePane grouping, with the final LegendPane ownership still called out as the remaining caveat.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/80`. Summary/evidence: the page gives detailed source grouping for `UserLookPane`, `MoreInfoPane`, `ProfilePane`, and shared `LegendPane`, with IDA/JPF evidence and memory/global refs; final ownership of shared legend behavior is still a caveat.
