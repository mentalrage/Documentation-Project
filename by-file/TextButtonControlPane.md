*** UID:0000OK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# TextButtonControlPane

## Status

- Confidence: strong for text-button class placement and destructor/vtable ownership, medium-high for the historical shared text-render helper boundary.
- Proposed module: `ui/controls/TextButtonControlPane.cpp`
- Current recovered source: `source-3/simroot_v2/class_TextButtonControlPane.cpp`
- Main address ranges: [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md), [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md), and [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md)

## File Role

`TextButtonControlPane` is a text-labeled button control derived from the control pane family. It constructs a text buffer, paints 3D button borders and centered text, and exposes text retrieval behavior. The old generated `SetTextResource` row is not accepted as text-button ownership because the raw body belongs to the radio-group option helper island.

`DrawTextInRect` remains linked here as a historical generated-output lead and because `TextButtonControlPane::OnPaint` is one of its callers. Its own memory page now treats the preferred owner as [UID:0000JR][GrafPort](by-file/GrafPort.md) / shared UI text drawing, with [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md) as the adjacent helper family. Do not use this file page as final proof that `DrawTextInRect` belongs in `TextButtonControlPane.cpp`.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `TextButtonControlPane` | [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md), destructor at [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md) | Text button construction, text buffer ownership, paint, and teardown. |
| `TextButtonControlPane` destructor support | [UID:0002YD][0x0049b05b-0x0049b071.TextButtonControlPaneAdjustorThunks](by-memory/0x0049b05b-0x0049b071.TextButtonControlPaneAdjustorThunks.md), [UID:0002YE][0x0049b7a0-0x0049b854.TextButtonControlPaneScalarDeletingDestructor](by-memory/0x0049b7a0-0x0049b854.TextButtonControlPaneScalarDeletingDestructor.md) | Compiler-generated adjustor thunks and scalar deleting wrapper tied to the `TextButtonControlPane` vtable cells; source should declare the destructor relationship rather than hand-author these thunks. |
| `DrawTextInRect` | [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md) | Shared multi-line wrapped text drawing helper with alignment support; historical/generated association only, likely GrafPort/shared text infrastructure. |

## Evidence Notes

- Wave3 metadata says `TextButtonControlPane` has a `ButtonControlPane` base and a text pointer at offset `0x10c`.
- 2026-05-25 IDA MCP confirms function starts at `0x00495040`, `0x00495130`, `0x004951b0`, `0x00495220`, and scalar deleting destructor `0x0049b7a0`.
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md) maps the `TextButtonControlPane` adjustor thunks at `0x0049b05b-0x0049b071`, the scalar deleting destructor at `0x0049b7a0-0x0049b853`, and the primary destructor vtable cell at `0x00617c7c`. That evidence supports this source/class placement even while the destructor wrappers remain compiler-generated aggregate rows.
- Current `simroot_v2` emits `SetTextResource` at `0x004964e0`, but current IDA MCP reports `0x004964e0` is not a promoted function and raw disassembly maps the full `0x004964e0-0x0049662f` structure to [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md). Treat that row as stale/misowned, not as a confirmed text-button setter.
- 2026-05-25 current-state recheck: `class_TextButtonControlPane.cpp` still emits the stale `SetTextResource` row. `class_RadioGroupControlPane.cpp` now emits the promoted `RadioGroupControlPane::OnPaint` at `0x00496300`, and IDA still leaves the later `0x004964e0` helper/table island unpromoted with no inbound xrefs to its helper starts.
- [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md) records 130 direct callers across UI and message rendering code and prefers GrafPort/shared-text ownership, so keep it cross-referenced rather than class-owned here.
- `DrawTextInRect` currently calls `GetFontLineAdvance(...g_pDirectX...)`, but IDA evidence from the DirectX batch indicates this is likely the same `g_pFontImageLib` global-alias issue tracked in [Wave3 noticed problems](../wave3_noticed_problems.md).
- [UID:0002YD][0x0049b05b-0x0049b071.TextButtonControlPaneAdjustorThunks](by-memory/0x0049b05b-0x0049b071.TextButtonControlPaneAdjustorThunks.md) and [UID:0002YE][0x0049b7a0-0x0049b854.TextButtonControlPaneScalarDeletingDestructor](by-memory/0x0049b7a0-0x0049b854.TextButtonControlPaneScalarDeletingDestructor.md) now give this file an exact destructor/vtable support chain: adjustor branches at `0x0049b061` and `0x0049b06c`, primary vtable/data cell `0x00617c7c`, and a confirmed `0x0049b7a0-0x0049b854` scalar deleting wrapper.
- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) is the broader generic button/choice-control family, but the proposed source tree and this page both keep `TextButtonControlPane.cpp` as a narrower reusable controls module. Use this file as the direct parent for [UID:0000EJ][TextButtonControlPane](by-class/TextButtonControlPane.md); keep broad aggregate and base-button ownership under [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md).

## Cross-References

- [UID:0000EJ][TextButtonControlPane](by-class/TextButtonControlPane.md)
- [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md)
- [UID:0000UJ][DrawTextInRect_004BAD70](by-item/DrawTextInRect_004BAD70.md)
- [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md)
- [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)
- [UID:0000JH][FontImageLib](by-file/FontImageLib.md)

## Changes

- 2026-06-07 A010 Batch096 parent-gate update:
  - What existed before: `COMPLETION:84`, `CONFIDENCE:82`, below the corrected 85/85 parent gate for [UID:0000EJ][TextButtonControlPane](by-class/TextButtonControlPane.md).
  - Changed to: `COMPLETION:85`, `CONFIDENCE:85`.
  - Summary/evidence: exact destructor support pages now document the TextButton adjustor thunk pair and scalar deleting destructor/vtable cell, while the file page narrows ownership to constructor/destructor/get-text/paint and treats `DrawTextInRect` as a shared GrafPort/text-render helper rather than text-button-owned code. Confidence stays at the gate because final field names and the broader button/source split still need a final source-layout pass.

- 2026-06-07 A003 ownership-boundary refinement:
  - What existed before: confidence was `78`, and the file-role text still said this page owned the broad `DrawTextInRect` helper while also carrying the stale generated `SetTextResource` caveat.
  - Changed to: confidence `82`, with `DrawTextInRect` documented as a historical/generated association and likely GrafPort/shared-text helper; `TextButtonControlPane` class placement is supported by constructor/paint/accessor boundaries plus destructor/vtable evidence from the destructor aggregate.
  - Summary/evidence: existing memory pages record the class functions at `0x00495040`, `0x00495130`, `0x004951b0`, and `0x00495220`, TextButton adjustor/scalar destructor/vtable ownership at `0x0049b05b`, `0x0049b7a0`, and `0x00617c7c`, the stale `0x004964e0` radio-group island, and the shared 130-caller `DrawTextInRect` helper. Completion stays `84` because final helper ownership and source split remain open.

- 2026-06-05 projected-path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file row remained a generated-root coverage error.
  - Changed to: `NexusTK/ui/controls/`.
  - Summary/evidence: live IDA MCP lookup confirms the documented text-button method anchor at `0x00495040`; proposed-source-tree treats `TextButtonControlPane.cpp` as a reusable UI-control module while keeping broad text drawing helper ownership open.

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `78`.
  - Evidence: document captures text-button role, proposed contents, Wave3/IDA evidence, stale `SetTextResource` ownership caveat, shared `DrawTextInRect` helper issue, font/global alias caveat, and cross-references; confidence is capped by shared text-render helper ownership.
