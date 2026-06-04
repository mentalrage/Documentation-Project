*** UID:00004U | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FieldMapPane

## Status

- Confidence: strong for class behavior, vtable-backed method ownership, request/path helper linkage, and map/UI placement; medium for the raw rectangle-helper boundary.
- Likely source file: [UID:0000JA][FieldMapPane](by-file/FieldMapPane.md)
- Address range: [UID:00014Z][0x004b0bb0-0x004b129b.FieldMapPane](by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md)
- Read-only data: [UID:00025B][0x0061a3c8-0x0061a45c.FieldMapPaneReadOnlyData](by-memory/0x0061a3c8-0x0061a45c.FieldMapPaneReadOnlyData.md)
- Evidence basis: live IDA MCP `py_eval` on 2026-06-04 against `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` (imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`).

## Class Purpose

`FieldMapPane` renders a selectable field map/list UI. It builds an EPF resource path, copies field metadata into a local entry table, handles mouse/keyboard selection, draws highlighted entries with labels, and sends the selected field-map request packet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `FieldMapPane` | `0x004b0bb0-0x004b0d2b` | Initializes pane state, stores the three `FieldMapPane` vtables, builds the `.EPF` path, and copies field metadata. |
| `HandleMouseEvent` | `0x004b0d30-0x004b0e50` | Vtable slot `0x0061a418`; hit-tests entries and sends a request for the clicked entry. |
| `HandleKeyEvent` | `0x004b0e50-0x004b0f1b` | Vtable slot `0x0061a41c`; handles navigation, submit, and cancel. |
| `RenderFieldEntries` | `0x004b0fb0-0x004b112a` | Vtable slot `0x0061a40c`; draws entries, selected highlight, and text labels. |
| `CalculateFieldItemRect` candidate | `0x004b1130-0x004b119d` | Computes a hit/render rectangle from the entry center, measured label extent, and line height. IDA currently has code bytes but no function object or xrefs; `retn 8` starts at `0x004b119a`, with alignment at `0x004b119d`. |
| `SendFieldMapRequest` | `0x004b11a0-0x004b1242` | Builds opcode `0x3f` packet fields from the selected entry and sets the request-in-flight flag. |
| `AdjustorDeletingDestructorA0` | `0x004b1242-0x004b124d` | Secondary vtable slot `0x0061a414`; adjusts by `-0xa0` and jumps to `0x004b1260`. |
| `AdjustorDeletingDestructorA4` | `0x004b124d-0x004b1258` | Tertiary vtable slot `0x0061a444`; adjusts by `-0xa4` and jumps to `0x004b1260`. |
| `ScalarDeletingDestructor` | `0x004b1260-0x004b129b` | Primary vtable slot `0x0061a3c8`; runs destructor/base cleanup and optionally frees storage. |

## Layout Notes

- Constructor evidence places the wide map path at approximately `this + 0xf8` and the field-entry table at approximately `this + 0x1f8`.
- The event-handler decompilation receives an adjusted `this` pointer and subtracts `0xa0` to reach the owning field-map object. This explains why generated code sometimes casts the owner to unrelated UI classes.
- Each field entry is a 0x94-byte record containing center coordinates, a wide label, two 16-bit sort/id values, and two packet coordinate/id values.

## Live IDA Evidence

- 2026-06-04 IDA confirms modeled functions at `0x004b0bb0-0x004b0d2b`, `0x004b0d30-0x004b0e50`, `0x004b0e50-0x004b0f1b`, `0x004b0fb0-0x004b112a`, `0x004b11a0-0x004b1242`, `0x004b1242-0x004b124d`, `0x004b124d-0x004b1258`, `0x004b1260-0x004b129b`, and `0x004b8220-0x004b8284`.
- The constructor stores primary, secondary, and tertiary `FieldMapPane` vtables at `0x0061a3c8`, `0x0061a414`, and `0x0061a444`, then calls `0x004b8220` at `0x004b0c0d` before appending `.EPF` from `0x0061a44c`.
- Vtable data slots bind `RenderFieldEntries` at `0x0061a40c`, `HandleMouseEvent` at `0x0061a418`, `HandleKeyEvent` at `0x0061a41c`, adjustor destructors at `0x0061a414`/`0x0061a444`, and the scalar deleting destructor at `0x0061a3c8`.
- `SendFieldMapRequest` has exactly three code refs from `0x004b0dfe`, `0x004b0ea7`, and `0x004b0f0e`; decompilation confirms opcode `0x3f`, entry values from the `0x94`-byte record, a seven-byte send through `0x00574bb0`, and request-in-flight byte `this+0x95fe`.
- `BuildFieldMapPath` has one code ref from the constructor and decompiles as a wide path-stem copy helper that scans backward for `'.'`, copies the stem with `memmove`, writes a wide NUL, and returns zero.
- Raw byte disassembly confirms the rectangle helper shape at `0x004b1130-0x004b119d`, including `index * 0x94`, row base `this+0x1f8`, text helpers `0x004baa70`/`0x004baaa0`, four rectangle writes, and `retn 8`; IDA still reports no function object and no xrefs for `0x004b1130`.

## Cross-References

- [UID:0000JA][FieldMapPane](by-file/FieldMapPane.md)
- [UID:00014Z][0x004b0bb0-0x004b129b.FieldMapPane](by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md)
- [UID:000150][0x004b1130-0x004b119a.FieldMapRectHelper](by-memory/0x004b1130-0x004b119a.FieldMapRectHelper.md)
- [UID:000151][0x004b11a0-0x004b1241.FieldMapRequestHelper](by-memory/0x004b11a0-0x004b1241.FieldMapRequestHelper.md)
- [UID:00015U][0x004b8220-0x004b8284.BuildFieldMapPath](by-memory/0x004b8220-0x004b8284.BuildFieldMapPath.md)
- [UID:00025B][0x0061a3c8-0x0061a45c.FieldMapPaneReadOnlyData](by-memory/0x0061a3c8-0x0061a45c.FieldMapPaneReadOnlyData.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `72/78`. Summary: class-level purpose, method table, layout notes, and IDA caveats are documented, but full field naming and final C++ reconstruction are not complete. Evidence: documented address cluster `0x004b0bb0-0x004b129b`, helper cross-references, and explicit IDA notes for the unresolved `0x004b1130` helper boundary.
- 2026-06-04: Raised from `72/78` to `82/86`.
  - What existed before: the page had a broad method table and layout notes, but it used stale generated-source evidence wording, mixed last-byte and end-exclusive ranges, and did not tie the class to the current vtable/read-only data scan.
  - Changed to: recorded the current IDA binary identity, exact modeled function endpoints, constructor vtable stores, vtable method slots, request/path helper caller evidence, `.EPF` suffix xref, and raw rectangle-helper disassembly.
  - Reason for score increase: live IDA now strongly proves the class method ownership, vtable layout, field-entry request flow, path helper use, and render/input method endpoints; score remains below final reconstruction because the raw `0x004b1130` helper still has no IDA function object or callers and source-quality field/helper names are unfinished.
