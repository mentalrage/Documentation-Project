*** UID:0000IS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# DescPane

## Status

- Confidence: strong for class identity; medium for final source folder.
- Proposed module: `ui/controls/DescPane.cpp`
- Proposed header: `ui/controls/DescPane.h`
- Current recovered source: `source-3/simroot_v2/class_DescPane.cpp`
- Main class: [UID:00003Q][DescPane](by-class/DescPane.md)
- Main address doc: [UID:00012K][0x0049d6f0-0x0049d89f.DescPane](by-memory/0x0049d6f0-0x0049d89f.DescPane.md)
- Evidence basis: `simroot_v2`, read-only Wave2 `DescPane.json`, Wave3 cache metadata, and IDA MCP checks through 2026-05-26.

## File Role

`DescPane.cpp` owns a reusable `Pane`-derived description display control. The pane stores an external description source pointer and selected entry index, invalidates its display region, and asks the source object for description text when the selection is valid.

Keep this separate from feature dialogs. Current caller evidence is sparse, but the class is generic UI infrastructure: it has a singleton accessor, a source/index setter, and a virtual refresh path that delegates description content to an external source interface.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:00003Q][DescPane](by-class/DescPane.md) | `0x0049d6f0-0x0049d89f` | Constructor, destructor paths, singleton getter, source/index update helper, and virtual refresh. |
| [UID:0001U3][DescPaneLayout](by-type/by-struct/DescPaneLayout.md) | size `0x100`, fields `+0xf8` and `+0xfc` | `Pane` base plus description source pointer and selected index. |
| [UID:0001XC][DescPaneVtables](by-type/by-vtable/DescPaneVtables.md), [UID:0002NA][0x006189dc-0x00618a60.DescPaneVtableData](by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md) | `0x006189dc`, `0x00618a28`, `0x00618a58` | Three vtable views installed by constructor and destructor paths. |
| [UID:0000QR][g_pDescPane](by-global/g_pDescPane.md) | [UID:0001PB][0x0069adf8-0x0069adfc.g_pDescPane](by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md) | Active global singleton for the description pane. |

## Evidence Notes

- Wave3 imports the class from original `DescPane.cpp` and reports a 256-byte struct extending [UID:0000MC][Pane](by-file/Pane.md).
- IDA disassembly confirms the constructor-shaped raw start at `0x0049d6f0`: it calls the `Pane` constructor, installs three `DescPane` vtables, clears `+0xf8`, sets `+0xfc` to `-1`, and stores `g_pDescPane`.
- IDA models `0x0049d740` as a non-deleting destructor, `0x0049d770` as a singleton getter, `0x0049d7c0` as the virtual refresh routine, `0x0049d81e`/`0x0049d829` as adjustor thunks, and `0x0049d840` as the scalar deleting destructor.
- IDA disassembly also shows a raw helper at `0x0049d780` that updates `+0xf8`/`+0xfc` when either value changes, then calls a primary-vtable slot with the pane bounds at `this+0x44`. Treat that as the source/index update helper until function recovery names it.
- Vtable data at `0x006189dc`, `0x00618a28`, and `0x00618a58` points at the virtual refresh and destructor thunk rows; see [UID:0001XC][DescPaneVtables](by-type/by-vtable/DescPaneVtables.md).
- 2026-05-26 IDA vtable pass confirms the primary table ends before RTTI at `0x00618a24`, the secondary table ends before RTTI at `0x00618a54`, and the tertiary table ends before `DialogPane` RTTI at `0x00618a60`. Current `class_DescPane.meta_wave3` still reports `vtable_count: 0`.
- 2026-05-26 recheck using current `simroot_v2` and IDA MCP only: active `class_DescPane.cpp` still emits only constructor `0x0049d6f0`, `RefreshDescription` `0x0049d7c0`, scalar deleting destructor `0x0049d840`, and `g_pDescPane`. IDA still models `0x0049d740`, `0x0049d770`, `0x0049d7c0`, `0x0049d81e`, `0x0049d829`, and `0x0049d840`; constructor `0x0049d6f0` and setter `0x0049d780` remain raw not-a-function starts.

## Generated Output Caveats

- Active `class_DescPane.cpp` currently emits only constructor `0x0049d6f0`, `RefreshDescription` `0x0049d7c0`, scalar deleting destructor `0x0049d840`, and `g_pDescPane`.
- The disabled companion emits only destructor adjustor thunks `0x0049d81e` and `0x0049d829`.
- Active output omits IDA-confirmed or disassembly-confirmed rows at `0x0049d740`, `0x0049d770`, and raw `0x0049d780`.
- 2026-05-25 follow-up data records [UID:0000QR][g_pDescPane](by-global/g_pDescPane.md) as resolved global-data at the four-byte storage range `0x0069adf8-0x0069adfc`.
- 2026-05-25 follow-up data says the earlier duplicate memory issue for `method:0x0049d6f0` is no longer active.
- 2026-05-26 disabled output still emits only the first adjustor thunk and marks `0x0049d829` missing code, while IDA still decompiles both 0xb adjustor thunks. The thunks are recorded in [UID:0000VN][-ignored](by-memory/-ignored.md) as compiler-generated glue, not handwritten source.

## Source-Structure Decision

Use a separate `ui/controls/DescPane.cpp` module. It is higher-level than `Pane.cpp`, but it is not owned by a particular feature dialog. The likely original header exposed the pane class plus a small provider interface whose virtual slot at offset `+0x24` returns description text for a selected index.

## Cross-References

- [UID:00003Q][DescPane](by-class/DescPane.md)
- [UID:00012K][0x0049d6f0-0x0049d89f.DescPane](by-memory/0x0049d6f0-0x0049d89f.DescPane.md)
- [UID:0001U3][DescPaneLayout](by-type/by-struct/DescPaneLayout.md)
- [UID:0001XC][DescPaneVtables](by-type/by-vtable/DescPaneVtables.md)
- [UID:0002NA][0x006189dc-0x00618a60.DescPaneVtableData](by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md)
- [UID:0000QR][g_pDescPane](by-global/g_pDescPane.md)
- [UID:0001PB][0x0069adf8-0x0069adfc.g_pDescPane](by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0001QV][client_ui_core](by-meta/client_ui_core.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:78`.
  - Summary/evidence: class role, layout/vtable/global anchors, raw setter/destructor gaps, generated-output caveats, singleton resolution, and source-structure decision are documented; confidence remains medium-high because final folder and provider-interface naming remain open.
- 2026-05-31 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - Changed to: `NexusTK/ui/controls/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `DescPane.cpp` under `ui/controls`, and the 2026-05-31 IDA MCP recheck confirms this is a reusable pane/control class rather than a feature-dialog owner.
