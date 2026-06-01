*** UID:0000SY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GetControlLayout_452260

## Status

- Symbol kind: free helper / recovered global function.
- Address range: [UID:0000XL][0x00452260-0x0045239a.GetControlLayout_452260](by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md).
- Current generated/recovered file: `source-3/simroot_v2/recovered/GetControlLayout_00452260.cpp`.
- Likely owner file: [UID:0000LE][MiniMap](by-file/MiniMap.md).
- Related class: [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md).
- Confidence: strong for behavior, medium for final source-level name.

## Role

`GetControlLayout_452260` maps `MiniMapDialog` control ids to fixed rectangles used while constructing the minimap UI. The helper is currently emitted as a recovered one-function global, but caller evidence makes it minimap-specific layout support rather than a generic dialog-control utility.

The current recovered signature is:

```cpp
int __stdcall GetControlLayout_452260(short controlId, int* rectOut);
```

Use `RectBounds*` for source-facing documentation unless final type recovery proves the output buffer is a different four-int rectangle type.

## Evidence Notes

- Current `simroot_v2/recovered/GetControlLayout_00452260.meta_wave3` imports this from Wave2 with summary "Maps MiniMapDialog control ids to the hard-coded rectangles used when constructing the minimap UI."
- IDA MCP on 2026-05-26 confirms function start `0x00452260`, size `0x13a`, and seven callers, all inside `MiniMapDialog::MiniMapDialog`.
- IDA MCP decompilation shows the switch over ids `0`, `1`, `2`, `4`, `6`, `7`, `8`, `9`, and `10`, with every known case filling `rectOut` through [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md).
- Current generated `MiniMapDialog` output also contains non-IDA projected labels at `0x004517a0` and `0x00452ce0`, but this helper is a real function and should remain a stable migration anchor.

## Source-Structure Decision

Fold this helper into `map/MiniMapDialog.cpp` or a combined `map/MiniMap.cpp`. Do not leave it as a standalone original `GetControlLayout_00452260.cpp` file during final source reconstruction unless migration tooling needs a temporary recovered-global container.

## Cross-References

- [UID:0000XL][0x00452260-0x0045239a.GetControlLayout_452260](by-memory/0x00452260-0x0045239a.GetControlLayout_452260.md)
- [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md)
- [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `84/88`.
  - Before: page documented minimap layout helper behavior, signature, caller evidence, switch cases, and source placement but remained unevaluated.
  - After: score reflects nearly complete behavior and owner documentation for this small helper, with only final source-level name/type polish left open.
  - Evidence: IDA notes confirm the function start/size, seven callers inside `MiniMapDialog` construction, control-id switch, and use of shared rectangle geometry helpers.
