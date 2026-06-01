*** UID:00004U | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FieldMapPane

## Status

- Confidence: medium-strong for class behavior and map/UI placement.
- Likely source file: [UID:0000JA][FieldMapPane](by-file/FieldMapPane.md)
- Address range: [UID:00014Z][0x004b0bb0-0x004b129b.FieldMapPane](by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md)
- Current recovered file: `source-3/simroot_v2/class_FieldMapPane.cpp`
- Evidence basis: generated `simroot_v2` source plus IDA MCP lookup/xref/decompile checks. `wave3.py` was not run during the 2026-05-24 update.

## Class Purpose

`FieldMapPane` renders a selectable field map/list UI. It builds an EPF resource path, copies field metadata into a local entry table, handles mouse/keyboard selection, draws highlighted entries with labels, and sends the selected field-map request packet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `FieldMapPane` | `0x004b0bb0-0x004b0d2a` | Initializes pane state and field metadata. |
| `HandleMouseEvent` | `0x004b0d30-0x004b0e4f` | Hit-tests entries and sends a request for the clicked entry. |
| `HandleKeyEvent` | `0x004b0e50-0x004b0f1a` | Handles navigation, submit, and cancel. |
| `RenderFieldEntries` | `0x004b0fb0-0x004b1129` | Draws entries, selected highlight, and text labels. |
| `CalculateFieldItemRect` candidate | `0x004b1130-0x004b119a` | Computes a hit/render rectangle from the entry center, measured label extent, and line height. IDA currently has code bytes but no function object or xrefs. |
| `SendFieldMapRequest` | `0x004b11a0-0x004b1241` | Builds opcode `0x3f` packet fields from the selected entry and sets the request-in-flight flag. |
| `AdjustorDeletingDestructorA0/A4` | `0x004b1242-0x004b1257` | Adjusted destructor wrappers for the pane/control subobjects. |
| `ScalarDeletingDestructor` | `0x004b1260-0x004b129a` | Runs destructor/base cleanup and optionally frees storage. |

## Layout Notes

- Constructor evidence places the wide map path at approximately `this + 0xf8` and the field-entry table at approximately `this + 0x1f8`.
- The event-handler decompilation receives an adjusted `this` pointer and subtracts `0xa0` to reach the owning field-map object. This explains why generated code sometimes casts the owner to unrelated UI classes.
- Each field entry is a 0x94-byte record containing center coordinates, a wide label, two 16-bit sort/id values, and two packet coordinate/id values.

## Evidence Notes

- IDA MCP confirms `0x004b0bb0-0x004b0d2b` and `0x004b0fb0-0x004b112a` as real functions.
- IDA MCP confirms `0x004b11a0` as a real function called only by `0x004b0d30` and `0x004b0e50` in current xrefs.
- IDA byte inspection shows `0x004b1130-0x004b119a` is function-shaped code, but `lookup_funcs` reports `0x004b1130` is not a function and `xrefs_to` reports no current references.
- Wave3/simroot notes mention unresolved shared renderer globals; those should not be force-named from this class alone.

## Cross-References

- [UID:0000JA][FieldMapPane](by-file/FieldMapPane.md)
- [UID:00014Z][0x004b0bb0-0x004b129b.FieldMapPane](by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md)
- [UID:000150][0x004b1130-0x004b119a.FieldMapRectHelper](by-memory/0x004b1130-0x004b119a.FieldMapRectHelper.md)
- [UID:000151][0x004b11a0-0x004b1241.FieldMapRequestHelper](by-memory/0x004b11a0-0x004b1241.FieldMapRequestHelper.md)
- [UID:00015U][0x004b8220-0x004b8284.BuildFieldMapPath](by-memory/0x004b8220-0x004b8284.BuildFieldMapPath.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `72/78`. Summary: class-level purpose, method table, layout notes, and IDA caveats are documented, but full field naming and final C++ reconstruction are not complete. Evidence: documented address cluster `0x004b0bb0-0x004b129b`, helper cross-references, and explicit IDA notes for the unresolved `0x004b1130` helper boundary.
