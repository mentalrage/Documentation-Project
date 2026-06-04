*** UID:0000NL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# SelfLookPane

## Status

- Confidence: strong for `NexusTK/ui/panels/` placement and `SelfLookPane` ownership; medium-high for whether `SelfLookPane2`, `SpelledPane`, and `LegendPane` were all in this same original translation unit or adjacent panel files.
- Proposed module: `NexusTK/ui/panels/SelfLookPane.cpp`
- Main address docs: [UID:0001H7][0x00565610-0x0056a373.SelfLookPane](by-memory/0x00565610-0x0056a373.SelfLookPane.md) and [UID:0001HK][0x0056fe80-0x005729c3.SelfLookPane2](by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md)
- Shared child-pane docs: [UID:0000NZ][SpelledPane](by-file/SpelledPane.md) and [UID:0000KM][LegendPane](by-file/LegendPane.md)
- Vtable/layout anchor: [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)
- 2026-06-04 live IDA refresh confirms the main `SelfLookPane` and `SelfLookPane2` function maps, raw helper spans, vtable-store paths, child-pane constructor xrefs, hover-slot global xrefs, and alignment boundaries used by this file page.

## File Role

`SelfLookPane.cpp` owns the player's own look/status panel family. It renders equipment and body appearance, parses character-data/server-update packets, sends option-toggle packets, switches among look/status/legend views, handles keyboard and mouse input, and tears down child panes used for spelled/stat and legend text.

`SelfLookPane` is the larger/current class with broad character-data parsing and item-slot rendering. `SelfLookPane2` is a smaller alternate or older/newer sibling with the same core view model: default look view, spelled/stat view, legend view, toggle buttons, and input routing.

IDA confirms `SelfLookPane`, `SelfLookPane2`, `SpelledPane`, and `LegendPane` vtable records. Those vtables are used here only as source-layout and ownership evidence; final C++ remains blank until class declarations and field names clear the 95/95 reconstruction gate.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `SelfLookPane` | `0x00565610-0x0056a373`, helpers `0x0056a380-0x0056ba99`, destructor `0x00573730` | Full self-look panel with character-data parser, equipment rendering, world-map refresh, input, packet/update helpers, and slot helpers. |
| `SelfLookPane2` | `0x0056fe80-0x005729c3`, helpers `0x005729e0-0x00573232`, destructor `0x00573640` | Smaller sibling self-look panel with default/spelled/legend views, button/input helpers, packet/update helpers, and a SpelledPane entry-vector insertion helper. |
| `SpelledPane` | `0x0056bb20-0x0056c3f1` | Shared child text pane used by self-look and system-message/new-system-message construction paths. |
| `LegendPane` | `0x0056c400-0x0056c493` | Shared legend/key text pane used by self-look and user-look paths. |
| destructor/thunk island | `0x005732c0-0x0057399e` | Mixed adjustor/scalar destructor island for self-look, self-look2, spelled-pane, and nearby classes, plus adjacent entry-vector cleanup helpers. |
| [UID:0002CG][g_selfLookLastHoverEquipmentSlotId](by-global/g_selfLookLastHoverEquipmentSlotId.md) | `0x0066fe40` | Source-owned/static hover equipment-slot cache used by `SelfLookPane::OnMouseClick` timer state. |

## Boundaries

- Keep [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md) as the owner of side-panel composition. It constructs self-look and user-look children but should not own their internals.
- Keep [UID:0000P0][UserLookPane](by-file/UserLookPane.md) separate. It is the remote-character look/profile panel; self-look owns the player's own equipment/status/legend panel.
- Keep [UID:0000NZ][SpelledPane](by-file/SpelledPane.md) and [UID:0000KM][LegendPane](by-file/LegendPane.md) cross-referenced as shared child-pane modules. They may be standalone small source files or local classes in a broader look/status source; they should not be blindly duplicated into both self-look and user-look source.
- Do not treat the `SelfLookPane2` toggle-helper names as final source names until their exact field and packet semantics are audited from disassembly.

## Evidence Notes

- 2026-06-04 IDA MCP confirms the modeled `SelfLookPane` function starts from constructor `0x00565610-0x005657d2` through `HitTestSlot` `0x0056a300-0x0056a373`, including non-IDA raw bodies at `0x005670c0`, `0x00567180`, `0x005671a0`, and `0x005672b0`.
- 2026-06-04 IDA MCP confirms `SelfLookPane2` modeled functions from constructor `0x0056fe80-0x0057002c` through `0x005728a0-0x005729c3`, with raw/helper follow-on code at `0x005729e0`, `0x00572f30`, and `0x00572fd0`.
- 2026-06-01 IDA MCP confirms `SelfLookPane::SelfLookPane` at `0x00565610-0x005657d2` with the constructor xref from `GeneralPurposePanel` at `0x004b844e`.
- 2026-06-04 IDA MCP confirms both self-look constructors create a `SpelledPane` child through `0x0056bb20` and a `LegendPane` child through `0x0056c400`; `SpelledPane` also has an external constructor xref at `0x005886bd`, and `LegendPane` has a `UserLookPane` constructor xref at `0x0059f428`, so those child panes remain adjacent/shared panel modules rather than blindly embedded into this file.
- 2026-06-04 IDA MCP confirms the core `SelfLookPane` vtable data reference `0x00624188` is written by the constructor at `0x00565640`, non-deleting cleanup helper at `0x0056580b`, and scalar deleting destructor at `0x00573762`; `SelfLookPane2` vtable `0x006246f8` is written at `0x0056feb3`, `0x0057005b`, and `0x00573672`.
- IDA confirms `SelfLookPane2` core function starts at `0x0056fe80`, `0x005700e0`, `0x00570c00`, `0x00570c80`, `0x00570ef0`, `0x00570fc0`, `0x00571c10`, `0x00571cc0`, `0x005726a0`, `0x00572780`, and `0x005728a0`.
- IDA has real modeled functions/raw starts that are preserved as migration anchors, including `0x005657e0`, `0x005693d0`, `0x00570030`, `0x00572120`, `0x005729e0`, `0x00572f30`, and `0x00572fd0`.
- 2026-05-28 IDA MCP resolved the former `0x0056a373-0x0056baa0` UNKNOWN gap as padding plus a real `0x0056a380-0x0056ba99` SelfLookPane packet/update helper island.
- 2026-05-30 IDA MCP xrefs show `word_66FE40` belongs with `SelfLookPane` source state: the compare/write pair is only in the `0x00568cb0-0x0056934a` mouse-event slot-hover branch.
- 2026-06-01 IDA MCP shows `SelfLookPane` and `SelfLookPane2` are constructed by panel/UI owner code and consume local-player panel state/resources; this supports `ui/panels/` placement, while the documented `UserLookPane` source candidate remains the separate remote-character look/profile panel.

## Caveats

The file is now well anchored to live IDA boundaries, vtable stores, child-pane xrefs, and helper islands. The remaining uncertainty is source-shape rather than ownership: exact field names, final toggle-helper names, and whether `SpelledPane` / `LegendPane` were standalone small sources or local classes in a broader look/status translation unit remain below the final C++ threshold.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 82 | The page now ties the file owner to both self-look class ranges, adjacent packet/helper islands, shared child panes, vtable family, destructor islands, static hover-slot state, and exact live IDA boundary checks. It remains below high completion because final field names, method-level child splits, and the original child-pane source split are not fully resolved. |
| Confidence | 88 | Live IDA confirms constructor ownership, vtable stores, child-pane constructor xrefs, raw/helper boundaries, padding, and global-state xrefs. Confidence is capped by source-shape uncertainty around shared `SpelledPane`/`LegendPane` placement and unresolved exact helper names. |

## Cross-References

- [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md)
- [UID:0000CV][SelfLookPane2](by-class/SelfLookPane2.md)
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)
- [UID:0000NZ][SpelledPane](by-file/SpelledPane.md)
- [UID:0000KM][LegendPane](by-file/LegendPane.md)
- [UID:0001H7][0x00565610-0x0056a373.SelfLookPane](by-memory/0x00565610-0x0056a373.SelfLookPane.md)
- [UID:00023V][0x0056a380-0x0056ba99.SelfLookPanePacketUpdateHelpers](by-memory/0x0056a380-0x0056ba99.SelfLookPanePacketUpdateHelpers.md)
- [UID:0002CG][g_selfLookLastHoverEquipmentSlotId](by-global/g_selfLookLastHoverEquipmentSlotId.md)
- [UID:0001HK][0x0056fe80-0x005729c3.SelfLookPane2](by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md)
- [UID:00023X][0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers](by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md)
- [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md)

## Changes

- 2026-06-04: Raised from `72/82` to `82/88` after a live IDA refresh of both self-look sibling ranges and removal of stale non-IDA provenance notes.
  - Before: the file page had accurate ownership direction but still relied on old non-IDA caveats and did not record the current live IDA confirmation for `SelfLookPane2` or the raw helper boundaries.
  - After: the page records the current IDA function maps, raw starts, padding, vtable stores, child-pane constructor xrefs, hover-slot xrefs, score rationale, and remaining source-shape caveats without emitting final C++.
  - Evidence: 2026-06-04 IDA MCP `py_eval` over `0x00565610-0x0056a380` and `0x0056fe80-0x005739a0` confirmed the modeled function runs, raw non-function helper bodies, `0xcc` alignment before/after the class spans, `0x004b844e -> 0x00565610`, child constructor xrefs at `0x005656cc`, `0x0056571c`, `0x0056ff1e`, and `0x0056ff6e`, vtable-store refs to `0x00624188` and `0x006246f8`, and the `0x0066fe40` compare/write pair in `sub_568CB0`.

- 2026-06-01: Set the validator projected path to `NexusTK/ui/panels/` and raised confidence after rechecking IDA constructor/vtable/child-pane evidence against the proposed source tree.
  - Before: the page named `ui/panels/SelfLookPane.cpp` in prose but had a blank `PROPOSED_RECONSTRUCTION_PATH`, preventing child attachment/autogen assignment.
  - After: the page has a valid validator path and stronger source-placement evidence, while preserving the open split question for `SelfLookPane2`, `SpelledPane`, and `LegendPane`.
  - Evidence: IDA MCP confirms constructor xref `0x004b844e -> 0x00565610`, child-pane constructor refs at `0x005656cc`/`0x0056571c`, shared child-pane xrefs outside this class, and vtable data refs to `0x00624188`; `by-project-structure/proposed-source-tree.md` already lists `ui/panels/SelfLookPane.cpp`.

- 2026-05-28: Added `0x0056a380-0x0056ba99` as a SelfLookPane helper island in the proposed file contents.
  - Before: `SelfLookPane.cpp` documentation listed the main range but left the adjacent helper gap unresolved.
  - After: the file owns the helper island as packet/update support code while keeping `GroupListPane`, `SpelledPane`, and `LegendPane` as separate/shared entities.
  - Evidence: 2026-05-28 IDA MCP reports helper code in `0x0056a380-0x0056ba99`, with call refs from the SelfLookPane server/event handler at `0x00569588` and `0x0056972f`.
- 2026-05-28: Added the `SelfLookPane2` trailing helper/destructor coverage.
  - Before: the `SelfLookPane2` trailing helper span after `0x005729c3` was only called out as individual loose starts and remained an `UNKNOWN` coverage gap.
  - After: [UID:00023X][0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers](by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md) covers the raw packet/update helpers and entry-vector insertion body; [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md) covers the related destructor/vector-helper island.
  - Evidence: 2026-05-28 IDA MCP function/byte sweep over `0x005729c3-0x005739a0`.
- 2026-05-30: Added the `0x0066fe40` hover equipment-slot cache to the proposed file contents.
  - Before: the file page did not account for the `SelfLookPane` state global adjacent to `SpelledPane` data.
  - After: [UID:0002CG][g_selfLookLastHoverEquipmentSlotId](by-global/g_selfLookLastHoverEquipmentSlotId.md) is recorded as source-owned/static state for this file.
  - Evidence: IDA MCP xrefs to `word_66FE40` are limited to the `SelfLookPane::OnMouseClick` compare/write pair at `0x005692c7` and `0x00569310`.
