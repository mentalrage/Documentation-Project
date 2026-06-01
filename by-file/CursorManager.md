*** UID:0000IL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# CursorManager

## Status

- Confidence: strong for cursor/screen helper behavior, medium for the typed `CursorManager` view, low for a separate original source file.
- Proposed module: [UID:0000NB][ScreenPane](by-file/ScreenPane.md) private/helper section; keep `ui/core/CursorManager.cpp` only as an adjacent source candidate if later evidence proves an original split.
- Current recovered source: `source-3/simroot_v2/class_CursorManager.cpp`
- Main method range: [UID:0001G7][0x00557380-0x00557467.ScreenCursorHelpers](by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md)

## File Role

`CursorManager` is the current generated name for small helpers that live on the root screen object. The confirmed methods switch the process cursor from a handle table, force cursor visibility, and expose cached screen width and height used by UI panes that clamp popups to the visible display.

IDA evidence ties this object to [UID:0000NB][ScreenPane](by-file/ScreenPane.md): `ScreenPane::ScreenPane` writes `0x0067a7cc = this`, `~ScreenPane` clears the same global, and the generated `CursorManager` accessors read the same width/height fields initialized by the `ScreenPane` constructor. Until a separate allocated cursor manager is proven, treat this as a ScreenPane companion or subobject view over the root screen layout.

The 2026-05-26 IDA pass makes a standalone source file weaker: `ScreenPane::ScreenPane` initializes the root singleton, vtables, layer list, dimensions, and frame/fade fields, but does not initialize the cursor handle table at `+0x550`. The handle table is likely populated by a later setup path or lazy cursor-resource loader that still needs to be found.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| [UID:00003E][CursorManager](by-class/CursorManager.md) typed view | `0x005573f0-0x00557467` | Generated class view for active cursor and screen-dimension helpers over the root `ScreenPane` layout. |
| screen dirty/update helper | `0x00557380-0x005573a0` | Marks a root-screen dirty/update flag and merges a rectangle/list helper at `+0x11c`. Exact final name pending. |
| screen repaint/timer helper | `0x005573b0-0x005573e2` | Calls presentation work and schedules immediate plus delayed callbacks through the root screen timer-handler subobject at `+0xa4`. Exact final name pending. |
| show cursor helpers | `0x00557430-0x00557448` | Tiny wrappers around `ShowCursor(TRUE/FALSE)`. |
| [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) | [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md) | Canonical root screen singleton; generated data also aliases it as [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md). |

## Ownership Notes

- Keep `0x0067a7cc` canonical as `g_pScreenPane` until a separate cursor-manager allocation or constructor is found.
- The current Wave3/Wave2 [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md) name is useful as a typed view for cursor helper calls, but it points at the same storage written by `ScreenPane`.
- Original source may have had a tiny `CursorManager.cpp` helper included beside `ScreenPane.cpp`, but the current IDA evidence now leans toward private `ScreenPane.cpp` helper methods unless a separate allocation, constructor, or header-level type use is found.
- Do not use the current `simroot_v2/class_CursorManager.cpp` file name by itself as migration evidence; it is a generated staging container over the shared `g_pScreenPane` storage.

## Evidence Notes

- IDA MCP confirms `0x005573f0` uses an active cursor index at word offset `704` / byte offset `+0x580`, an `HCURSOR` table at word offset `680` / byte offset `+0x550`, then calls `SetCursor` and `ShowCursor(TRUE)`.
- IDA MCP confirms `0x00557380` sets byte offset `+0x118` and passes the helper region at `+0x11c` to `0x004b7d70`.
- IDA MCP confirms `0x005573b0` calls `0x00557140` and then schedules callbacks through `0x005975e0(this + 0xa4, 0, 1, 0, 0)` and `0x005975e0(this + 0xa4, 1, 500, 0, 0)`.
- IDA MCP confirms `0x00557450` returns word offset `137` / byte offset `+0x112` and `0x00557460` returns word offset `138` / byte offset `+0x114`.
- IDA MCP confirms `ScreenPane::ScreenPane` stores constructor arguments into those same width/height offsets and writes `dword_67A7CC = this`.
- IDA MCP decompilation of `ScreenPane::ScreenPane` does not show cursor table initialization at `+0x550`; cursor handle loading remains open.
- Direct callers of the dimension accessors include static text, help panes, IME panes, patch/update panes, and transfer-server dialogs.
- 2026-05-26 recheck: active `simroot_v2/class_CursorManager.cpp` still emits only the generated `SetActiveCursor`, `GetScreenWidth`, and `GetScreenHeight` view with repeated synthetic `CursorManagerLayout` definitions; browser generated output still calls through `g_pCursorManager`, which remains an alias over `g_pScreenPane` storage.
- 2026-05-26 IDA MCP reports `0x0067a7cc` as a 4-byte `.data` item named `dword_67A7CC` with 145 data xrefs.

## Cross-References

- [UID:00003E][CursorManager](by-class/CursorManager.md)
- [UID:0001G7][0x00557380-0x00557467.ScreenCursorHelpers](by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md)
- [UID:0000NB][ScreenPane](by-file/ScreenPane.md)
- [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md)
- [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:0000K5][IMEPanes](by-file/IMEPanes.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:72`.
  - Summary/evidence: cursor/screen helper behavior, shared `g_pScreenPane` storage, typed-view aliasing, offsets, callers, and ownership warnings are documented; confidence is lower than the documentation completeness because a standalone original `CursorManager.cpp` remains weakly supported.
