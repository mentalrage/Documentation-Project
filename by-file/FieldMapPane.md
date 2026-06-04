*** UID:0000JA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# FieldMapPane

## Status

- Confidence: strong for map placement, method/vtable anchors, request/path helper ownership, and padding boundaries; medium-high for standalone source split and the unresolved raw rectangle helper.
- Proposed module folder: `NexusTK/map/`
- Candidate file: `NexusTK/map/FieldMapPane.cpp`
- Evidence basis: live IDA MCP checks on 2026-06-04, existing exact memory pages, and `by-project-structure/proposed-source-tree.md`.

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

| Entity | Current range | Role |
| --- | --- | --- |
| `FieldMapPane` | `0x004b0bb0-0x004b129b` | Field-entry map pane with mouse/keyboard selection and rendering. |
| `BuildFieldMapPath_4B8220` | `0x004b8220-0x004b8284` | File-local or nearby helper that strips a wide source path extension before the constructor appends `.EPF`. |

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

## Live IDA Evidence

IDA MCP checks on 2026-06-04 confirm:

- IDB identity: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- Real function map: constructor `0x004b0bb0-0x004b0d2b`, mouse handler `0x004b0d30-0x004b0e50`, key handler `0x004b0e50-0x004b0f1b`, render method `0x004b0fb0-0x004b112a`, request helper `0x004b11a0-0x004b1242`, adjustor thunks `0x004b1242-0x004b124d` and `0x004b124d-0x004b1258`, scalar destructor `0x004b1260-0x004b129b`, and path helper `0x004b8220-0x004b8284`.
- `0x004b1130` remains raw code, not an IDA function: it has no containing function, no current xrefs, and begins with a normal helper-shaped prologue (`55 8b ec 0f bf 45 08 ...`). Keep it documented as [UID:000150][0x004b1130-0x004b119a.FieldMapRectHelper](by-memory/0x004b1130-0x004b119a.FieldMapRectHelper.md), but do not promote it to a live source method yet.
- Constructor vtable stores: `0x004b0bf3 -> 0x0061a3c8`, `0x004b0bf9 -> 0x0061a414`, and `0x004b0c03 -> 0x0061a444`.
- Vtable slots: `0x0061a3c8 -> 0x004b1260`, `0x0061a414 -> 0x004b1242`, `0x0061a444 -> 0x004b124d`, `0x0061a40c -> 0x004b0fb0`, `0x0061a418 -> 0x004b0d30`, and `0x0061a41c -> 0x004b0e50`.
- Request helper callers are all FieldMap methods: `0x004b0dfe` in the mouse handler and `0x004b0ea7`/`0x004b0f0e` in the key handler.
- Path helper caller is the constructor at `0x004b0c0d`; `0x004b8220` still ends at `0x004b8284`, followed by `0xcc` padding.
- Boundary padding is confirmed at `0x004b0ba5-0x004b0bb0`, `0x004b129b-0x004b12a0`, and `0x004b8284-0x004b8290`.

## Boundary Cautions

- Some neighboring helper names in older notes point at fitting-room or ranking-event classes, but the FieldMap-owned evidence is the vtable/request/path-helper data listed above. `0x004b95e0-0x004b9767` is documented as shared GrafPort draw-state/clip helpers, and `0x004ba9a0-0x004bad66` as [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md). Those shared helpers should not pull the FieldMap module into fitting-room or ranking-event ownership.
- The `FieldMapPane` virtual handlers are entered through an adjusted pane/control subobject; decompilation subtracts `0xa0` from `this` before accessing the real field-entry table and request flag. Preserve the adjustor-subobject note when reconstructing the class layout.

## Open Questions

- Whether `FieldMapPane` was a standalone source file or declared inside a larger field-map dialog module.
- Render helper globals in this class remain unresolved and should be named as part of a broader UI/render pass.
- `0x004b1130` needs an IDA boundary decision: create the function, leave it as unreferenced code, or prove it is dead/duplicate raw code.

## Cross-References

- [UID:00004U][FieldMapPane](by-class/FieldMapPane.md)
- [UID:00014Z][0x004b0bb0-0x004b129b.FieldMapPane](by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md)
- [UID:000150][0x004b1130-0x004b119a.FieldMapRectHelper](by-memory/0x004b1130-0x004b119a.FieldMapRectHelper.md)
- [UID:000151][0x004b11a0-0x004b1241.FieldMapRequestHelper](by-memory/0x004b11a0-0x004b1241.FieldMapRequestHelper.md)
- [UID:00015U][0x004b8220-0x004b8284.BuildFieldMapPath](by-memory/0x004b8220-0x004b8284.BuildFieldMapPath.md)
- [UID:00025B][0x0061a3c8-0x0061a45c.FieldMapPaneReadOnlyData](by-memory/0x0061a3c8-0x0061a45c.FieldMapPaneReadOnlyData.md)
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
- 2026-06-04 live IDA confidence update:
  - What existed before: `COMPLETION:82`, `CONFIDENCE:76`, and older source-label/helper wording.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:84`.
  - Summary/evidence: live IDA MCP now records the exact modeled function ranges, constructor vtable stores, vtable slots, FieldMap-only request-helper callers, constructor-only path-helper caller, raw `0x004b1130` status, and padding boundaries. Confidence remains below final-source quality because the standalone-vs-larger-dialog source split and the raw rectangle helper are still unresolved.
