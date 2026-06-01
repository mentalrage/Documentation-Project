*** UID:0000OM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# TextEditControlPane

## Status

- Confidence: strong.
- Proposed module: `ui/controls/TextEditControlPane.cpp`
- Proposed header: `ui/controls/TextEditControlPane.h`
- Current recovered source: `source-3/simroot_v2/class_TextEditControlPane.cpp`
- Main address clusters: `0x004988d0-0x00499020` and `0x0049b6c0-0x0049b731`

## File Role

`TextEditControlPane` is the dialog/control adapter around [UID:0000ON][TextEditPane](by-file/TextEditPane.md). It derives from [UID:0000IG][ControlPane](by-file/ControlPane.md), returns control type `5`, owns an embedded `TextEditPane`, forwards attach/detach/show/hide/focus events, and paints the older-mode border around the editing surface.

This file should remain separate from the editor implementation because it is a `ControlPane` wrapper with broad dialog caller fan-in.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `TextEditControlPane` small constructor | `0x004988d0-0x0049891f` | Minimal wrapper initialization with read-only and multiline flags. |
| `TextEditControlPane` full constructor | `0x00498920-0x00498b8c` | Full editor construction with initial text, colors, bounds, scrollbars, width scale, and input mode. |
| Lifecycle/forwarding virtuals | `0x00498b90-0x00498dc7`, [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder.md) | Destroy embedded editor and forward layer/show/hide/focus and bounded text-copy operations. |
| Border paint | `0x00498f50-0x00499020` | Draw control border when enabled. |
| Scalar deleting destructor | `0x0049b6c0-0x0049b731` | Vtable deleting-destructor entry; IDA shows the same wrapper body is also referenced by a StaticTextControlPane vtable cell. |

## Ownership Decision

Keep this as `ui/controls/TextEditControlPane.cpp`, not inside [UID:0000ON][TextEditPane](by-file/TextEditPane.md). The full constructor at `0x00498920` is a hot general-purpose UI entry point used by article, mail, login, alert, and other dialog flows. It constructs `ControlPane` with type `5`, allocates a 372-byte `TextEditPane`, then configures the child editor.

## Evidence Notes

- IDA MCP reports 85 direct references to `TextEditControlPane::TextEditControlPane` at `0x00498920`.
- The full constructor calls `ControlPane::ControlPane(5, bounds)`.
- The constructor subtracts horizontal/vertical scrollbar space from the editable rectangle, applies a width scale, builds style flags, and calls `TextEditPane::TextEditPane`.
- It sets the embedded editor's max length, max lines, local bounds, visibility, editable state, and optional initial text.
- `OnAttachToParent`, `OnDetachFromParent`, `ForwardShow`, `ForwardHide`, and `ForwardFocusEvent` delegate to the embedded pane.
- [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder.md) forwards text-copy requests to the owned [UID:0000ON][TextEditPane](by-file/TextEditPane.md), confirming this wrapper/file boundary.

## Current Caveats

- The generated destructor region may contain base/destructor naming pollution from nearby control classes. Constructor and virtual forwarding evidence are stronger than generated base-name text.

## Cross-References

- [UID:0000EM][TextEditControlPane](by-class/TextEditControlPane.md)
- [UID:00011H][0x004988d0-0x00499020.TextEditControlPaneCore](by-memory/0x004988d0-0x00499020.TextEditControlPaneCore.md)
- [UID:000127][0x0049b6c0-0x0049b731.TextEditControlPaneDestructor](by-memory/0x0049b6c0-0x0049b731.TextEditControlPaneDestructor.md)
- [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `82` and confidence to `86`.
  - Evidence: document captures wrapper role, proposed contents, ownership decision, IDA caller fan-in, constructor behavior, forwarding virtuals, caveats, and cross-references; confidence is high because scope and class behavior are narrow and strongly supported.
