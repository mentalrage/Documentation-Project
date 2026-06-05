*** UID:0000IS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# DescPane

## Status

- Confidence: high for class identity and reusable-control placement; medium-high for final provider-interface naming.
- Proposed module: `ui/controls/DescPane.cpp`
- Proposed header: `ui/controls/DescPane.h`
- Main class: [UID:00003Q][DescPane](by-class/DescPane.md)
- Main address doc: [UID:00012K][0x0049d6f0-0x0049d89f.DescPane](by-memory/0x0049d6f0-0x0049d89f.DescPane.md)
- Evidence basis: live IDA MCP disassembly/decompilation, vtable rows, singleton xrefs, and current project source-tree placement.

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

- IDA MCP reports no function at the constructor-shaped raw start `0x0049d6f0`. Raw disassembly at `0x0049d6f0-0x0049d73b` calls the `Pane` constructor helper `sub_544460(1)`, installs three `DescPane` vtables, clears `+0xf8`, sets `+0xfc` to `-1`, and stores `g_pDescPane`.
- IDA models `0x0049d740` as a non-deleting destructor, `0x0049d770` as a singleton getter, `0x0049d7c0` as the virtual refresh routine, `0x0049d81e`/`0x0049d829` as adjustor thunks, and `0x0049d840` as the scalar deleting destructor.
- IDA MCP reports no function at the raw helper start `0x0049d780`. Raw disassembly at `0x0049d780-0x0049d7af` updates `+0xf8`/`+0xfc` when either value changes, then calls primary-vtable slot `+0x20` with the pane bounds at `this+0x44`.
- Vtable data at `0x006189dc`, `0x00618a28`, and `0x00618a58` points at the virtual refresh and destructor thunk rows; see [UID:0001XC][DescPaneVtables](by-type/by-vtable/DescPaneVtables.md).
- Live vtable data places the scalar deleting destructor at `0x006189dc`, refresh at `0x00618a20`, adjustor thunk `sub_49D81E` at `0x00618a28`, adjustor thunk `sub_49D829` at `0x00618a58`, and the next `DialogPane` RTTI at `0x00618a60`.
- IDA xrefs to [UID:0001PB][0x0069adf8-0x0069adfc.g_pDescPane](by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md) are limited to the DescPane island: constructor store at `0x0049d731`, non-deleting destructor clear at `0x0049d75a`, singleton getter read at `0x0049d770`, and scalar deleting destructor clear at `0x0049d860`.
- `RefreshDescription` at `0x0049d7c0-0x0049d81e` clears pane text state, invalidates bounds through `dword_69B3FC(this, this+0x44)`, reads provider pointer `+0xf8` and selected index `+0xfc`, and calls provider vtable slot `+0x24` with a local 2048-byte buffer when valid.

## Reconstruction Caveats

- Keep `0x0049d740`, `0x0049d770`, and raw `0x0049d780` with the file even though some partial reconstruction outputs omit them.
- 2026-05-25 follow-up data records [UID:0000QR][g_pDescPane](by-global/g_pDescPane.md) as resolved global-data at the four-byte storage range `0x0069adf8-0x0069adfc`.
- 2026-05-25 follow-up data says the earlier duplicate memory issue for `method:0x0049d6f0` is no longer active.
- IDA still decompiles both 11-byte adjustor thunks. The thunks are recorded in [UID:0000VN][-ignored](by-memory/-ignored.md) as compiler glue, not handwritten source.

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

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:78`.
  - Summary/evidence: class role, layout/vtable/global anchors, raw setter/destructor gaps, reconstruction caveats, singleton resolution, and source-structure decision are documented; confidence remains medium-high because final folder and provider-interface naming remain open.
- 2026-05-31 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - Changed to: `NexusTK/ui/controls/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `DescPane.cpp` under `ui/controls`, and the 2026-05-31 IDA MCP recheck confirms this is a reusable pane/control class rather than a feature-dialog owner.
- 2026-06-04 live IDA refresh:
  - What existed before: the file was scored `82/78` and still mixed live IDA facts with stale source/cache caveats.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:84`.
  - Summary/evidence: live IDA confirms the raw constructor-shaped block, raw source/index setter block, modeled lifecycle/getter/refresh/destructor functions, singleton xrefs to `0x0069adf8`, exact vtable rows through `0x00618a60`, and the reusable-control source placement. Confidence remains below final because the provider interface is behaviorally understood but not source-named, and two class-local blocks are still raw non-function starts with no direct callers.
