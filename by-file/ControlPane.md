*** UID:0000IG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ControlPane

## Status

- Confidence: strong for base control ownership.
- Proposed module: `ui/core/ControlPane.cpp`
- Current recovered source: `source-3/simroot_v2/class_ControlPane.cpp`
- Main address ranges: `0x004949e0-0x00494a81`, `0x00494bf0-0x00494bf7`, `0x0049b170-0x0049b1aa`; the legacy [UID:000114][0x004949e0-0x00494bf7.ControlPane](by-memory/0x004949e0-0x00494bf7.ControlPane.md) page is now an aggregate/index because unrelated helpers are interleaved in the old span.
- Type docs: [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)

## File Role

`ControlPane` is the base pane for clickable or input-bearing UI controls. It constructs a `Pane` in mode `1`, stores shared control metadata such as control type, sprite/skin state, repeat delay, and hit-test suppression, then installs control-specific vtables.

Derived controls such as browser controls, checkbox controls, image controls, minimap controls, fitting-room controls, popup controls, and text buttons all call this constructor.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `ControlPane` | [UID:0002PB][0x004949e0-0x00494a81.ControlPaneConstructor](by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md), [UID:0002PC][0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting](by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md), plus destructor/thunks | Base control constructor and generic hit-test behavior. |
| vtable family | `0x00617a90`, `0x00617af8`, `0x00617b28` | Primary control view plus secondary/tertiary handler views at object offsets `+0xa0` and `+0xa4`. |
| adjustor thunk helpers | `0x0049af3d`, `0x0049af48` | Compiler-generated secondary/tertiary destructor thunks; not handwritten control behavior. |
| small fixed virtual | `0x0041d690-0x0041d694` | Returns fixed control constant `10`; semantic name still open. |

## Evidence Notes

- IDA MCP reports 52 direct constructor call sites across UI controls.
- IDA MCP `list_globals` confirms three `ControlPane` vtable bases at `0x00617a90`, `0x00617af8`, and `0x00617b28`; `disasm` confirms `0x0049af3d` and `0x0049af48` as 11-byte destructor adjustor thunks.
- Generated control classes call `ControlPane::ControlPane` with a control type and optional bounds.
- Wave3 metadata notes one adjustor thunk is excluded and the `GetFixedValue10` semantic name remains uncertain.
- 2026-06-01 IDA MCP confirms the exact constructor range at `0x004949e0-0x00494a81` and hit-test suppression accessor at `0x00494bf0-0x00494bf7`. The local memory between those functions includes progress-bar helpers and button/radio-control helpers, so do not migrate the entire old `0x004949e0-0x00494bf6` span as one `ControlPane.cpp` block.

## Cross-References

- [UID:000038][ControlPane](by-class/ControlPane.md)
- [UID:000114][0x004949e0-0x00494bf7.ControlPane](by-memory/0x004949e0-0x00494bf7.ControlPane.md)
- [UID:0002PB][0x004949e0-0x00494a81.ControlPaneConstructor](by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md)
- [UID:0002PC][0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting](by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- [UID:000120][0x0049af3d-0x0049af52.ControlPaneAdjustorThunks](by-memory/0x0049af3d-0x0049af52.ControlPaneAdjustorThunks.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md)
- [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md)
- [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md)
- [UID:0000M2][NumericStringControlPane](by-file/NumericStringControlPane.md)
- [UID:0000N1][RectangleControlPane](by-file/RectangleControlPane.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:86`.
  - Summary/evidence: base control role, derived caller fanout, vtable families, adjustor thunks, fixed virtual caveat, and related control modules are documented; confidence is strong because ownership is base-control infrastructure, with only the small fixed virtual name still open.

- 2026-06-01 projected path and exact child split:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, and exact constructor/accessor pages did not exist.
  - Changed to: projected path `NexusTK/ui/core/`, with exact child memory docs for the constructor and hit-test suppression accessor.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `ControlPane.cpp` under `ui/core`, and IDA MCP confirms the exact function boundaries and interleaved non-`ControlPane` helper ranges.
