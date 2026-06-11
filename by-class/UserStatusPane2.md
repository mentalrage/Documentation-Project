*** UID:0000FT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000P2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# UserStatusPane2

## Status

- Confidence: strong for role, method boundaries, and singleton.
- Likely source file: [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- Main address range: [UID:0001NO][0x005bab00-0x005bc60c.UserStatusPane2](by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md)
- Shared destructor/thunk tail: [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)
- Singleton: [UID:0000SN][g_pUserStatusPane2](by-global/g_pUserStatusPane2.md) at `0x0069b4e4`
- Current recovered source: `source-3/simroot_v2/class_UserStatusPane2.cpp`

## Class Purpose

`UserStatusPane2` is the newer compact status-meter pane. It draws `BAR.EPF`/`BAR.PAL` progress bars, comma-separated large numeric values, small fixed-width counters, and uses the same `9X11FONT.BIN` glyph table as the larger status pane.

## Method Map

| Address | Method / family | Role |
| --- | --- | --- |
| `0x005bab00-0x005babf7` | `UserStatusPane2::UserStatusPane2` | Constructs the pane, installs three vtable views, stores the singleton, initializes meter fields, and loads `9X11FONT.BIN`. |
| `0x005bac00-0x005bac7d` | cleanup body | Frees the glyph table, clears the singleton, and calls pane-base cleanup. |
| `0x005bac80-0x005baf0a` | packet/movement router | Handles the same movement opcodes as the larger status pane and forwards compact value payloads to `0x005bc420`. |
| `0x005baf70-0x005baf75` | `AlwaysFalse` | Stub virtual returning false. |
| `0x005baf80-0x005bbe15` | `OnPaint` | Draws four compact bars, large grouped values, comma sprites, and small counters. |
| `0x005bbe60-0x005bbfe1` | compact status-rect lookup helper | Maps compact pane field ids to dirty rectangles. |
| `0x005bc010-0x005bc0e1` | `DrawGlyphText` | Draws glyph text with the loaded 9x11 font table. |
| `0x005bc420-0x005bc60c` | compact status payload application | Parses bitflagged payload values and invalidates compact bar/value rectangles. |
| `0x005bfbf0`, `0x005bfc4d`, `0x005bfc58`, `0x005bfe60` | shared tail helpers | Singleton clear helper, destructor adjustor thunks, and scalar deleting destructor. |

## Evidence Notes

- IDA callers show construction from `InitializeMainUiGraph` at `0x004f83ea`.
- IDA confirms `0x005bc610` starts [UID:000081][MenuVarietyPane](by-class/MenuVarietyPane.md), so `UserStatusPane2` must end at `0x005bc60c` and must not absorb the adjacent menu code.
- Active generated output omits `0x005bac80`, `0x005bbe60`, `0x005bc420`, and the first destructor adjustor thunk `0x005bfc4d`.

## Cross-References

- [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- [UID:0001NO][0x005bab00-0x005bc60c.UserStatusPane2](by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md)
- [UID:0001RS][user-status-resources](by-resource/user-status-resources.md)
- [UID:000081][MenuVarietyPane](by-class/MenuVarietyPane.md)

## Changes

- 2026-06-05 autogen metadata classification:
  - What existed before: reconstruction autogen metadata was unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with parent [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md).
  - Summary/evidence: live IDA MCP against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` confirmed the compact status constructor, cleanup, router, paint, rect/glyph/payload helpers, singleton tail helper, adjustor thunks, and scalar deleting destructor starts from `0x005bab00` through `0x005bfe60`; the class and parent both pass the 80/80 parent gate. No reconstruction C++ was emitted because the page is below 95/95.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:88`.
  - Summary/evidence: scored from the compact-status constructor/cleanup/router/paint/rect/glyph/payload method map, singleton evidence, resource links, boundary with `MenuVarietyPane`, and generated-output omission notes.
