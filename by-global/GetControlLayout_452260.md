*** UID:0000SY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for the recovered GetControlLayout_452260 alias is covered by [UID:0000XL][0x00452260-0x0045239a.GetControlLayout_452260](by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md)
// by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md, which emits the
// source-facing file-local helper GetMiniMapControlLayout.
// Do not emit a duplicate global-alias body here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# GetControlLayout_452260

## Status

- Symbol kind: free helper / recovered global function.
- Address range: [UID:0000XL][0x00452260-0x0045239a.GetControlLayout_452260](by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md).
- Likely owner file: [UID:0000LE][MiniMap](by-file/MiniMap.md).
- Related class: [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md).
- Confidence: very strong for behavior, bounds, caller set, rectangle helper dependency, and minimap ownership; medium-high for final source-level name and exact MiniMapDialog file split.

## Role

`GetControlLayout_452260` maps `MiniMapDialog` control ids to fixed rectangles used while constructing the minimap UI. The helper is currently emitted as a recovered one-function global, but caller evidence makes it minimap-specific layout support rather than a generic dialog-control utility.

The current recovered signature is `int __stdcall GetControlLayout_452260(short controlId, int* rectOut)`.

Use `RectBounds*` for source-facing documentation unless final type recovery proves the output buffer is a different four-int rectangle type.

## Evidence Notes

- IDA MCP on 2026-05-26 confirms function start `0x00452260`, size `0x13a`, and seven callers, all inside `MiniMapDialog::MiniMapDialog`.
- IDA MCP decompilation shows the switch over ids `0`, `1`, `2`, `4`, `6`, `7`, `8`, `9`, and `10`, with every known case filling `rectOut` through [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md).
- IDA MCP recheck on 2026-06-05 confirmed `sub_452260`, size `0x13a`, seven callers inside `sub_450CA0`, and rectangle initializer callee `0x004b7c50`.
- Live IDA MCP on 2026-06-14 rechecked `sub_452260` at `0x00452260`, size `0x13a`, 314 decimal bytes (Verified with int_convert.py), seven constructor call sites inside `MiniMapDialog::MiniMapDialog` (`sub_450CA0`), one behavioral callee `sub_4B7C50`, 12 basic blocks, and cyclomatic complexity 3. The exact memory page [UID:0000XL][0x00452260-0x0045239a.GetControlLayout_452260](by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md) already records the full control-id rectangle table and post-body switch-table handling.

## Source-Structure Decision

Fold this helper into `map/MiniMapDialog.cpp` or a combined `map/MiniMap.cpp`. Do not leave it as a standalone original `GetControlLayout_00452260.cpp` file during final source reconstruction unless migration tooling needs a temporary recovered-global container.

## Alias C++ Disposition

This by-global page is an address-suffixed recovered alias. The source body belongs only on [UID:0000XL][0x00452260-0x0045239a.GetControlLayout_452260](by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md), which now emits the source-facing file-local `GetMiniMapControlLayout` helper. Duplicating the switch body here would produce two definitions for the same source helper in `MiniMap.cpp`, so this page intentionally emits only the covered-by marker.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 87 | The page records exact range, size, signature shape, control-id role, caller/callee set, linked full rectangle-table memory page, MiniMapDialog constructor ownership, parent/emitter route, and the accepted no-duplicate-body alias marker. |
| Confidence | 91 | Live IDA MCP on 2026-06-14 matches the exact memory page for boundary, seven constructor callers, rectangle-helper callee, and minimap-specific behavior. Confidence remains below final-source quality because the original file split is still provisional, not because the alias/body relationship is unresolved. |
| Parent | [UID:0000LE][MiniMap](by-file/MiniMap.md) | Child `86/90` and direct parent `85/86` clear the strict `85/85` gate, and the nonblank emitter route targets `auto-generated/NexusTK/map/MiniMap.cpp`. |

## Cross-References

- [UID:0000XL][0x00452260-0x0045239a.GetControlLayout_452260](by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md)
- [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md)
- [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md)

## Changes

- 2026-06-30 B010 empty-emitter implementation callback:
  - Raised `86/90` to `87/91` and inserted the accepted formal alias marker.
  - Clarified that [UID:0000XL][0x00452260-0x0045239a.GetControlLayout_452260](by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md) owns the source body and this by-global page must not duplicate it.
- 2026-05-30: Grading changed from `0/0` to `84/88`.
  - Before: page documented minimap layout helper behavior, signature, caller evidence, switch cases, and source placement but remained unevaluated.
  - After: score reflects nearly complete behavior and owner documentation for this small helper, with only final source-level name/type polish left open.
  - Evidence: IDA notes confirm the function start/size, seven callers inside `MiniMapDialog` construction, control-id switch, and use of shared rectangle geometry helpers.
- 2026-06-05: Marked reconstructable and attached to [UID:0000LE][MiniMap](by-file/MiniMap.md).
  - Reason: live IDA MCP recheck confirms source-authored minimap layout helper behavior and all observed callers are inside minimap-dialog construction.
- 2026-06-14 A003 score refresh:
  - Before: `84/88`; the exact memory page already carried stronger `86/90` support after parent-gate repair.
  - Changed to: `86/90`, retaining [UID:0000LE][MiniMap](by-file/MiniMap.md) as canonical owner/emitter and keeping reconstruction C++ blank.
  - Summary/evidence: live IDA MCP rechecked `sub_452260`, `0x13a` / 314-byte size (Verified with int_convert.py), seven `MiniMapDialog` constructor xrefs, single rectangle-initializer callee, basic-block summary, and the linked full switch/rectangle evidence. Final helper spelling and exact minimap file split remain below final code-entry quality.
