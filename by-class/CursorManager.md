*** UID:00003E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CursorManager

## Status

- Confidence: strong for the documented helper bodies, medium for typed-view identity, low for a separate allocated class.
- Likely source file: [UID:0000NB][ScreenPane](by-file/ScreenPane.md), with [UID:0000IL][CursorManager](by-file/CursorManager.md) retained as a provisional source-layout candidate.
- Main address range: [UID:0001G7][0x00557380-0x00557467.ScreenCursorHelpers](by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md)
- Documentation basis: IDA-confirmed screen cursor helper bodies, root-screen field offsets, [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) aliasing, and the explicit absence of a separate constructor/destructor/allocation lifetime.
- Recovered-output caveat: recovered one-class output is only a typed-view lead; current evidence does not support a separately reconstructable `CursorManager` class.

## Class Purpose

`CursorManager` is the generated class view for root-screen cursor and dimension helpers. It exposes cached screen dimensions and switches the Win32 cursor handle used by the active UI state.

This is probably not a separately allocated manager object. The methods operate on the same root object stored in [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md), and the generated [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md) name is an alias over that storage in current evidence. The dimension fields are initialized by [UID:0000CB][ScreenPane](by-class/ScreenPane.md). Use `CursorManager` as a provisional typed view until the final `ScreenPane` layout and source split are resolved.

The 2026-05-26 IDA check found no constructor, destructor, allocation site, or singleton lifetime for a distinct cursor manager. It did confirm that `ScreenPane::ScreenPane` initializes the screen singleton and dimensions but does not initialize the cursor handle table. The cursor-resource load path is now documented as screen/surface lifecycle work in [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md), which weakens the case for a separate `CursorManager` source file rather than strengthening it.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SetActiveCursor` | `0x005573f0-0x0055742b` | Updates active cursor index, loads a handle from the object-local cursor table, calls `SetCursor`, and makes the cursor visible. |
| `GetScreenWidth` | `0x00557450-0x00557457` | Returns cached screen width from the root screen object. |
| `GetScreenHeight` | `0x00557460-0x00557467` | Returns cached screen height from the root screen object. |

## Nearby Helpers

- `0x00557380-0x005573a0`: root screen dirty/update helper; sets byte offset `+0x118` and merges state through the helper region at `+0x11c`.
- `0x005573b0-0x005573e2`: presentation/timer request helper; calls the local presentation helper and schedules immediate/delayed timer callbacks through the `+0xa4` subobject.
- `0x00557430-0x00557448`: tiny `ShowCursor(TRUE/FALSE)` wrappers.

## Data Notes

- Cursor handle table: IDA places the table at word offset `680`, byte offset `+0x550`.
- Active cursor index: IDA places it at word offset `704`, byte offset `+0x580`.
- Screen width/height: IDA confirms getters read word offsets `137` and `138`, byte offsets `+0x112` and `+0x114`, matching `ScreenPane::ScreenPane` initialization.
- `ScreenPane::ScreenPane` initializes the singleton, root layer list at dword offset `67` / byte offset `+0x10c`, dimensions, and frame/fade fields, but not the cursor handle table at `+0x550`.
- [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md) records the raw cursor file loader at `0x00559080-0x005590da`: it loads cursor files through `LoadCursorFromFileW`, stores handles into the same root-screen table at `this+0x550`, and falls back to `LoadCursorW(IDC_ARROW)`. That path is treated as screen/surface lifecycle support, not as evidence for a separately allocated `CursorManager`.
- 2026-05-26 recheck: IDA MCP still reports no separate cursor-manager constructor/lifetime. Recovered one-class output still emits these methods through a cursor-manager typed view, but all observed lifetime evidence belongs to `ScreenPane` / [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md).

## Ownership Decision Matrix

| Evidence | Decision |
| --- | --- |
| Helpers use root-object offsets `+0x112`, `+0x114`, `+0x550`, and `+0x580` | Treat `CursorManager` as a typed view over [UID:0000CB][ScreenPane](by-class/ScreenPane.md) storage. |
| [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md) aliases [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) | Do not emit a second singleton/global declaration. |
| Cursor handles are loaded by the screen/surface lifecycle range at `0x00559080-0x005590da` | Keep cursor-resource initialization with ScreenPane/SurfacePresentation documentation unless a distinct constructor is later found. |
| No constructor, destructor, allocation site, or independent lifetime has been documented | Keep `RECONSTRUCTABLE:FALSE` for this class page and leave C++ blank. |
| Generated `class_CursorManager.cpp` still names the view | Preserve the page as a useful alias/cross-reference, not as source-file proof. |

## Autogen Status

This page remains unattached and does not emit class C++. Current evidence supports a useful generated typed view over root `ScreenPane` storage, not a separately allocated original class with its own source file or singleton lifetime.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `78` | The page now also links the cursor-handle initialization path to the ScreenPane/SurfacePresentation helper range, records an ownership decision matrix, and explains why that loader does not prove a standalone class. Completion remains capped because the exact original helper type/header split is still unknown. |
| Confidence `84` | Confidence is strong for the current non-promotion decision: helpers operate on root ScreenPane fields, `g_pCursorManager` aliases `g_pScreenPane`, cursor handles are loaded through screen/surface lifecycle code, and no separate cursor-manager lifetime has been found. Confidence is not higher because an original private helper type or adjacent source split is still possible. |

## Cross-References

- [UID:0000IL][CursorManager](by-file/CursorManager.md)
- [UID:0001G7][0x00557380-0x00557467.ScreenCursorHelpers](by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md)
- [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md)
- [UID:0000CB][ScreenPane](by-class/ScreenPane.md)
- [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md)
- [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md)

## Changes

- 2026-06-05:
  - Before: reconstructability metadata was blank even though the page says it should not emit class C++.
  - After: set `RECONSTRUCTABLE:FALSE`; `CursorManager` remains a generated typed view over [UID:0000CB][ScreenPane](by-class/ScreenPane.md) / [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md), not an emitted standalone class.
  - Why/evidence: live IDA MCP confirms the helper functions at `0x00557380` (`0x21` bytes) and `0x005573f0` (`0x3c` bytes); no separate constructor/lifetime evidence is documented, so class autogen should not produce a declaration here.
- 2026-06-06 provenance/report cleanup:
  - Before: the status section still presented a direct recovered-output path as current evidence, and the coverage report still treated this page as reconstructable.
  - After: replaced the status line with IDA-backed documentation-basis/recovered-output caveats and queued the coverage row as not-reconstructable.
  - Why/evidence: helper behavior and offsets are documented, but the page's own reconstructability metadata is `FALSE` because all observed lifetime evidence belongs to `ScreenPane` storage.
- 2026-06-02:
  - Before: scored `70/68`, making the typed-view page look weak even though the negative lifetime evidence is well documented.
  - After: scored `74/82` and added explicit no-autogen rationale.
  - Why: existing ScreenPane/global/helper evidence strongly supports treating `CursorManager` as a generated typed view over `g_pScreenPane` rather than a standalone class.
- 2026-06-06 A009 continuation:
  - Before: scored `74/82`; the page still described cursor-resource loading as an unresolved open path without tying it to the documented screen/surface loader.
  - After: scored `78/84`, added [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md) as the cursor-handle loader evidence, and added an ownership decision matrix.
  - Why: the cursor handle table at `this+0x550` is populated by the screen/surface lifecycle range rather than by a proven `CursorManager` constructor, reinforcing `RECONSTRUCTABLE:FALSE` for this generated class view while improving the documentation of the remaining source-layout caveat.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `70/68`.
  - Summary/evidence: helper bodies, cursor/dimension offsets, root screen relationship, and absence of separate lifetime evidence are documented; confidence stays lower because the `CursorManager` class identity is probably a generated typed view over `ScreenPane` storage.
