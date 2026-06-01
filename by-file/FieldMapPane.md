*** UID:0000JA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# FieldMapPane

## Status

- Confidence: medium-strong for a separate map/UI source file.
- Proposed module folder: `map/`
- Candidate file: `map/FieldMapPane.cpp`
- Current generated source label: `class_FieldMapPane.cpp`
- Evidence basis: existing generated/simroot notes plus targeted IDA MCP checks on 2026-05-23, 2026-05-24, and 2026-06-01. `wave3.py` was not run during the 2026-06-01 pass.

## Hypothesis

`FieldMapPane` is a smaller map-related selection/render pane. It initializes field metadata, handles field-entry mouse and keyboard selection, renders selectable field entries with labels, and sends the selected field-map request packet. Its name and behavior are map-domain specific, but it is smaller and more UI-control-like than `MapPane`.

Likely original placement:

```text
map/FieldMapPane.cpp
```

Alternative placement if later evidence ties it to a larger dialog:

```text
ui/dialogs/FieldMapPane.cpp
```

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `FieldMapPane` | `0x004b0bb0-0x004b129b` | `class_FieldMapPane.cpp` | Field-entry map pane with mouse/keyboard selection and rendering. |
| `BuildFieldMapPath_4B8220` | `0x004b8220-0x004b8284` | `recovered/BuildFieldMapPath_004B8220.cpp` | File-local or nearby helper that strips a wide source path extension before the constructor appends `.EPF`. |

## Method Summary

| Address | Current name | Summary |
| --- | --- | --- |
| `0x004b0bb0` | constructor | Initializes pane state, builds the `.EPF` path, and copies field metadata into the local entry table. |
| `0x004b0d30` | `HandleMouseEvent` | Hit-tests entries and dispatches a field-map request for the clicked entry. |
| `0x004b0e50` | `HandleKeyEvent` | Handles navigation, submit, and cancel actions. |
| `0x004b0fb0` | `RenderFieldEntries` | Renders field entries, selected highlight, and labels. |
| `0x004b1130` | `CalculateFieldItemRect` candidate | Function-shaped code fragment that calculates an entry rectangle from label extent and line height; IDA currently has code bytes but no function object or xrefs. |
| `0x004b11a0` | `SendFieldMapRequest` | Builds and sends the `0x3f` field-map request packet from the selected entry and marks the request in flight. |
| `0x004b1242` / `0x004b124d` | adjustor deleting destructors | `-0xa0` / `-0xa4` adjustor wrappers into the scalar deleting destructor. |
| `0x004b1260` | scalar deleting destructor | Runs destructor/base cleanup and conditionally frees storage. |

## IDA MCP Evidence

Targeted checks confirmed:

- `0x004b0bb0-0x004b0d2b` constructor-like function calls pane/base initialization and wide string helpers.
- `0x004b0fb0-0x004b112a` render function calls common render/text helpers and references the shared render globals used by map UI.
- `0x004b0d30`, `0x004b0e50`, and `0x004b0fb0` are vtable-referenced from data addresses `0x0061a418`, `0x0061a41c`, and `0x0061a40c`.
- `0x004b11a0` is called only from `FieldMapPane` mouse/key handling in current IDA xrefs; it is a field-map request helper, not fitting-room download ownership.
- `0x004b1130-0x004b119a` is code with a normal prologue/epilogue, but IDA currently has no function object or xrefs for `0x004b1130`. Treat it as a candidate orphaned rect helper until the function boundary is reconciled.
- `0x004b8220` is called by the constructor only and performs the path-stem copy used before appending `.EPF`.
- 2026-05-28 IDA boundary check corrects `BuildFieldMapPath_4B8220` to end-exclusive `0x004b8284`.
- 2026-06-01 IDA MCP recheck confirms the same function map: real methods at `0x004b0bb0`, `0x004b0d30`, `0x004b0e50`, `0x004b0fb0`, `0x004b11a0`, `0x004b1242`, `0x004b124d`, `0x004b1260`, and `0x004b8220`; `0x004b1130` remains `Not a function`.
- 2026-06-01 xref recheck confirms vtable data references for `0x004b0d30`, `0x004b0e50`, and `0x004b0fb0`, constructor stores to vtables at `0x0061a3c8`, `0x0061a414`, and `0x0061a444`, three FieldMap-only callers of `0x004b11a0`, and one constructor caller of `0x004b8220`.

## Boundary Cautions

- `simroot_v2` still references generic text/render helpers through active names such as `FittingRoomDownloadControlPane::MeasureFieldLabelExtent`, `FittingRoomDownloadControlPane::GetLineHeight`, `FittingRoomListPane::SetTextColor`, and `RankingEventListPane::DrawFrame`. `0x004b95e0-0x004b9767` is now documented as shared GrafPort draw-state/clip helpers, and `0x004ba9a0-0x004bad66` as [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md). These names are shared-helper artifacts and should not pull the FieldMap module into fitting-room or ranking-event ownership.
- The `FieldMapPane` virtual handlers are entered through an adjusted pane/control subobject; decompilation subtracts `0xa0` from `this` before accessing the real field-entry table and request flag. Preserve the adjustor-subobject note when reconstructing the class layout.

## Open Questions

- Whether `FieldMapPane` was a standalone source file or declared inside a larger field-map dialog module.
- Render helper globals in this class remain unresolved and should be named as part of a broader UI/render pass.
- `0x004b1130` needs an IDA boundary decision: create the function, leave it as unreferenced code, or prove it is dead/duplicate generated data.

## Cross-References

- [UID:00004U][FieldMapPane](by-class/FieldMapPane.md)
- [UID:00014Z][0x004b0bb0-0x004b129b.FieldMapPane](by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md)
- [UID:000150][0x004b1130-0x004b119a.FieldMapRectHelper](by-memory/0x004b1130-0x004b119a.FieldMapRectHelper.md)
- [UID:000151][0x004b11a0-0x004b1241.FieldMapRequestHelper](by-memory/0x004b11a0-0x004b1241.FieldMapRequestHelper.md)
- [UID:00015U][0x004b8220-0x004b8284.BuildFieldMapPath](by-memory/0x004b8220-0x004b8284.BuildFieldMapPath.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)

## Changes

- 2026-06-01 reconstruction path and IDA refresh:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the contents table still used the pre-correction `0x004b129a` aggregate end.
  - Changed to: `NexusTK/map/` and aggregate range `0x004b0bb0-0x004b129b`.
  - Summary/evidence: the proposed source tree already lists `map/FieldMapPane.cpp`; IDA MCP rechecked the FieldMap function map, vtable refs, helper callers, constructor path-helper caller, and the still-unmodeled raw rect helper.
- Before: `BuildFieldMapPath_4B8220` was listed as `0x004b8220-0x004b8283`.
- After: `BuildFieldMapPath_4B8220` is listed as `0x004b8220-0x004b8284`.
- Summary/evidence: 2026-05-28 IDA MCP reports `sub_4B8220` size `0x64`, and disassembly shows the final two-byte jump at `0x004b8282-0x004b8283`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:76`.
  - Summary/evidence: field-map role, proposed source placement, method map, IDA xref/boundary evidence, shared-helper ownership cautions, open rectangle helper question, and path-helper endpoint correction are documented; confidence remains medium-high because standalone map/UI source placement and `0x004b1130` reachability remain open.
