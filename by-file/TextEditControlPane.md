*** UID:0000OM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# TextEditControlPane

## Status

- Confidence: strong.
- Proposed module: `ui/controls/TextEditControlPane.cpp`
- Proposed header: `ui/controls/TextEditControlPane.h`
- Main address clusters: `0x004988d0-0x00499021` and `0x0049b6c0-0x0049b731`
- IDA MCP evidence pass: 2026-06-05.

## File Role

`TextEditControlPane` is the dialog/control adapter around [UID:0000ON][TextEditPane](by-file/TextEditPane.md). It derives from [UID:0000IG][ControlPane](by-file/ControlPane.md), returns control type `5`, owns an embedded `TextEditPane`, exposes wrapper text accessors, forwards attach/detach/show/hide/focus events, synchronizes wrapper/editor state, and paints the older-mode border around the editing surface.

This file should remain separate from the editor implementation because it is a `ControlPane` wrapper with broad dialog caller fan-in.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| Small constructor body | `0x004988d0-0x0049891f` | Unmodeled-by-IDA function body that initializes a type-`5` wrapper, input/border bytes, vtables, and initialized flag. |
| Full constructor | `0x00498920-0x00498b8d` | Full editor construction with initial text, colors, bounds, scrollbars, width scale, editability flags, input mode, max length, max lines, and local bounds. |
| Embedded editor cleanup | `0x00498b90-0x00498bcf`, `0x0049b6c0-0x0049b731` | Non-deleting cleanup helper and scalar deleting destructor for the owned embedded editor. |
| Text/accessor helpers | `0x00498bd0-0x00498ce1`, [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder.md) | Forward max-length/max-line, activation, read-text, export, empty-state, and replacement-text operations to the embedded editor. |
| Lifecycle and state virtuals | `0x00498cf0-0x00498f4c` | Attach/detach/show/hide/focus forwarding plus wrapper/editor state synchronization. |
| Border paint | `0x00498f50-0x00499021` | Draw control border when enabled. |

## Ownership Decision

Keep this as `ui/controls/TextEditControlPane.cpp`, not inside [UID:0000ON][TextEditPane](by-file/TextEditPane.md). The full constructor at `0x00498920` is a hot general-purpose UI entry point used by article, mail, login, alert, and other dialog flows. It constructs `ControlPane` with type `5`, allocates a `372`-byte `TextEditPane`, then configures the child editor.

## Evidence Notes

- `callers(0x00498920)` reports `85` ordinary references to the full constructor.
- The full constructor calls `ControlPane::ControlPane(5, bounds)`, subtracts horizontal/vertical scrollbar space from the editable rectangle, applies a width scale, builds style flags, allocates the embedded editor, and stores it at `+0x10c`.
- It sets the embedded editor's max length to `1024`, max lines to `1`, local bounds, visibility/editability state, and optional initial text.
- `callers` reports ordinary fan-in to the wrapper text/accessor helpers, including `69` callers for [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder.md).
- `xrefs_to` confirms attach/detach/show/hide/focus/state/paint helpers are primarily vtable-reached through the TextEditControlPane and neighboring text-control vtable cells.
- [UID:000127][0x0049b6c0-0x0049b731.TextEditControlPaneDestructor](by-memory/0x0049b6c0-0x0049b731.TextEditControlPaneDestructor.md) documents the scalar deleting destructor, adjustor thunks, embedded editor cleanup, base teardown, and conditional object-free path.

## Current Caveats

- A few helper starts inside `0x00498c40-0x00498c9d` are valid aligned forwarding bodies but are not currently promoted to IDA functions and have no direct xrefs.
- Several lifecycle/state helpers are shared or vtable-referenced by neighboring text-control vtables, so this file documents the wrapper role and embedded-editor behavior without claiming final private method names.

## Cross-References

- [UID:0000EM][TextEditControlPane](by-class/TextEditControlPane.md)
- [UID:00011H][0x004988d0-0x00499020.TextEditControlPaneCore](by-memory/0x004988d0-0x00499020.TextEditControlPaneCore.md)
- [UID:000127][0x0049b6c0-0x0049b731.TextEditControlPaneDestructor](by-memory/0x0049b6c0-0x0049b731.TextEditControlPaneDestructor.md)
- [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)

## Changes

- 2026-06-05: Live IDA refresh.
  - What existed before: the page was scored `82/86`, cited a recovered-source path, and summarized only the main constructor/lifecycle/paint/destructor slices.
  - Changed to: completion `86`, confidence `88`, stale recovered-source reference removed, contents expanded with exact accessor/state helper ranges, and live caller/vtable/destructor evidence added.
  - Summary/evidence: live IDA confirms this is the reusable `ControlPane` adapter around `TextEditPane`, not the editor implementation itself. Remaining completion gap is final source naming/layout and the exact private split for the shared text-control helper methods.
