*** UID:0000IL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# CursorManager

## Status

- Confidence: very strong for the final no-source-root disposition. Cursor behavior, dimensions, cursor loading, and all seven UID0001G7 methods are exact ScreenPane source; no separate CursorManager translation unit remains plausible.
- Source module: none. [UID:0000NB][ScreenPane](by-file/ScreenPane.md) owns every source-bearing method and resource-loading route.
- Historical recovered source: `source-3/simroot_v2/class_CursorManager.cpp`, retained only as superseded generated-container provenance.
- Main method range: [UID:0001G7][0x00557380-0x00557467.ScreenCursorHelpers](by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md)

## File Role

`CursorManager` is a historical generated name for small helpers that live on the root screen object. UID0001G7 now resolves those helpers as exact ScreenPane methods that switch the process cursor from a handle table, force cursor visibility, and expose cached screen width and height used by UI panes.

IDA evidence ties this view to [UID:0000NB][ScreenPane](by-file/ScreenPane.md): ScreenPane construction writes canonical storage, destruction clears it, and the historical CursorManager accessors read the same width/height fields initialized by ScreenPane. Exhaustive current reanalysis found no separate allocation, constructor, vtable, storage, or lifetime, so this is a closed historical typed-view index rather than a deferred companion/subobject source hypothesis.

Historical 2026-05-26 evidence did not yet identify cursor-table initialization. That open point is superseded by [UID:00039X][0x00558f70-0x005590da.ScreenPaneCursorResourceLoader](by-memory/0x00558f70-0x005590da.ScreenPaneCursorResourceLoader.md), which populates the same ScreenPane HCURSOR table during startup and further rejects a standalone CursorManager source.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| [UID:00003E][CursorManager](by-class/CursorManager.md) typed view | `0x005573f0-0x00557467` | Generated class view for active cursor and screen-dimension helpers over the root `ScreenPane` layout. |
| screen dirty/update helper | `0x00557380-0x005573a0` | Marks a root-screen dirty/update flag and merges a rectangle/list helper at `+0x11c`. Exact final name pending. |
| screen repaint/timer helper | `0x005573b0-0x005573e2` | Calls presentation work and schedules immediate plus delayed callbacks through the root screen timer-handler subobject at `+0xa4`. Exact final name pending. |
| show cursor helpers | `0x00557430-0x00557448` | Tiny wrappers around `ShowCursor(TRUE/FALSE)`. |
| cursor resource loader | [UID:00039X][0x00558f70-0x005590da.ScreenPaneCursorResourceLoader](by-memory/0x00558f70-0x005590da.ScreenPaneCursorResourceLoader.md) | ScreenPane-owned startup cursor-file loader for the same cursor handle table; rejects a standalone CursorManager source-root decision. |
| [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) | [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md) | Canonical root screen singleton; generated data also aliases it as [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md). |

## Ownership Notes

- Keep `0x0067a7cc` canonical as `g_pScreenPane` until a separate cursor-manager allocation or constructor is found.
- The current Wave3/Wave2 [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md) name is useful as a typed view for cursor helper calls, but it points at the same storage written by `ScreenPane`.
- The former possibility of a tiny `CursorManager.cpp` is rejected: current IDA/type/xref/lifetime evidence plus complete exact ScreenPane children leave no independent source-bearing entity.
- Do not use the current `simroot_v2/class_CursorManager.cpp` file name by itself as migration evidence; it is a generated staging container over the shared `g_pScreenPane` storage.

## Autogen Status

`PROPOSED_RECONSTRUCTION_PATH` is `NONE` and this page must not emit a standalone `CursorManager.cpp` placeholder. The exact reconstruction route is ScreenPane.cpp; this page remains documentation-only with no class declaration, method body, global definition, or source path.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `89` | The page documents the historical generated container, exact replacement child inventory, ScreenPane/global aliasing, callers, cursor loader, source-root rejection, no-path metadata, migration history, and compiler/no-duplicate exclusions. |
| Confidence `92` | IDA ties every helper and field to ScreenPane, g_pCursorManager aliases g_pScreenPane, cursor resources load on ScreenPane, and no independent type/lifetime/storage exists. Only stripped original private nicknames remain unknowable. |

## Final Source-Root Disposition

- [UID:0001G7][0x00557380-0x00557467.ScreenCursorHelpers](by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md) is a non-emitting semantic index, not a CursorManager source island.
- [UID:0004RR][0x00557380-0x005573a0.ScreenPaneMarkDirtyRegion](by-memory/0x00557380-0x005573a0.ScreenPaneMarkDirtyRegion.md), [UID:0004RS][0x005573b0-0x005573e2.ScreenPaneStartPresentation](by-memory/0x005573b0-0x005573e2.ScreenPaneStartPresentation.md), [UID:0004RT][0x005573f0-0x0055742b.ScreenPaneSetActiveCursor](by-memory/0x005573f0-0x0055742b.ScreenPaneSetActiveCursor.md), [UID:0004RU][0x00557430-0x00557438.ScreenPaneShowCursor](by-memory/0x00557430-0x00557438.ScreenPaneShowCursor.md), [UID:0004RV][0x00557440-0x00557448.ScreenPaneHideCursor](by-memory/0x00557440-0x00557448.ScreenPaneHideCursor.md), [UID:0004S0][0x00557450-0x00557457.ScreenPaneGetScreenWidth](by-memory/0x00557450-0x00557457.ScreenPaneGetScreenWidth.md), and [UID:0004S2][0x00557460-0x00557467.ScreenPaneGetScreenHeight](by-memory/0x00557460-0x00557467.ScreenPaneGetScreenHeight.md) emit only through ScreenPane.cpp positions 110-170.
- Exact fields are the 12-entry HCURSOR table at ScreenPane `+0x550`, signed-short active index at `+0x580`, and signed-short dimensions at `+0x112/+0x114`. The visibility methods consume no boolean argument.
- `PROPOSED_RECONSTRUCTION_PATH:"NONE"` and `CANONICAL_OWNER:NONE` remain exact. No reconstruction metadata is valid on this by-file page.
- Historical `class_CursorManager.cpp`, CursorManager method spellings, and possible private/adjacent source remain explicitly superseded provenance rather than current source claims.

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
- 2026-06-14 C001 IDA MCP recheck on session `b001_0003gy` confirms the helper island as real small functions: `0x00557380` size `0x21`, `0x005573b0` size `0x33`, `0x005573f0` size `0x3c`, `0x00557430` and `0x00557440` size `0x9`, `0x00557450` and `0x00557460` size `0x8`, and successor `0x00557470` size `0x22d`.
- The same component pass confirms the behavior split: `0x00557380` calls the rectangle/list helper `0x004b7d70`, `0x005573b0` calls presentation/timer helpers `0x00557140` and `0x005975e0`, `0x005573f0` calls `SetCursor` and `ShowCursor`, and the width/height accessors remain leaf functions.
- `xrefs_to 0x005573f0` reports 16 code callers, `xrefs_to 0x0067a7cc` still reports broad root-screen singleton usage with more than the first 100 data refs, and the possible cursor-resource loader lead `0x00559080` remains not a function with zero xrefs. This supports the `NONE` source-root decision rather than a standalone `CursorManager.cpp`.
- 2026-06-16 A001 active-IDB refresh on `b001_mappane_0001AW_20260616` reconfirmed the helper island counts: one caller each for `0x00557380` and `0x005573b0`, 16 callers for active cursor selection at `0x005573f0`, eight/five callers for the show/hide wrappers, and 12 paired callers each for width/height.
- The cursor-resource loader is no longer only an unresolved `0x00559080` lead. IDA models `0x00558f70` as a `0x105`-byte function with one startup caller at `0x004f61c9`; [UID:00039X][0x00558f70-0x005590da.ScreenPaneCursorResourceLoader](by-memory/0x00558f70-0x005590da.ScreenPaneCursorResourceLoader.md) records the adjacent raw `0x00559080-0x005590da` helper and assigns the combined loader to [UID:0000NB][ScreenPane](by-file/ScreenPane.md). `xrefs_to 0x00559080` still returns zero, so it remains an interior/raw loader body, not a separate CursorManager constructor or source-root proof.

## Cross-References

- [UID:00003E][CursorManager](by-class/CursorManager.md)
- [UID:0001G7][0x00557380-0x00557467.ScreenCursorHelpers](by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md)
- [UID:00039X][0x00558f70-0x005590da.ScreenPaneCursorResourceLoader](by-memory/0x00558f70-0x005590da.ScreenPaneCursorResourceLoader.md)
- [UID:0000NB][ScreenPane](by-file/ScreenPane.md)
- [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md)
- [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:0000K5][IMEPanes](by-file/IMEPanes.md)

## UID0003CJ Cursor Literal Closure

The cursor strings are now physically and semantically closed by [UID:0003CJ][0x0062317c-0x00623480.ScreenPaneResourceStringData](by-memory/0x0062317c-0x00623480.ScreenPaneResourceStringData.md) and [UID:00039X][0x00558f70-0x005590da.ScreenPaneCursorResourceLoader](by-memory/0x00558f70-0x005590da.ScreenPaneCursorResourceLoader.md). Ten NUL-terminated UTF-16 paths occupy `0x00623304-0x0062345c`; the subrange SHA256 is `B73849261F0C50B5AE7C0E7982B465FEA48ABE7AA7B6D39BD5D7DA01406445E8`. Each path has exactly one xref from the ScreenPane loader: normal `.ani/.cur` at `0x00558f7b/0x00558f92`, select at `0x00558fb1/0x00558fc2`, view at `0x00558fe1/0x00558ff2`, put at `0x00559011/0x00559022`, and attack at `0x00559041/0x00559052`.

This evidence strengthens the existing `NONE` source-module decision. The strings are inline arguments in ScreenPane cursor-loading code, not resource identifiers, CursorManager globals, or a separate data table. No separate allocation, constructor, vtable, storage, lifetime, aggregate-base xref, or source file exists. Preserve this page at `89/92`, `PROPOSED_RECONSTRUCTION_PATH:"NONE"`, owner none, and non-emitting historical/index status.

## Changes

- 2026-07-24 B001 UID0003CJ cursor synchronization: preserved `89/92` and the rejected standalone source module; added exact literal range/hash, all ten loader xrefs and fallback order, inline source shape, and no-global/no-resource/no-table negative evidence.

- 2026-07-15 B002 accepted UID0001G7 callback:
  - Raised `87/87` to `89/92`, preserving path/owner NONE and non-emitting by-file semantics.
  - Added all seven real ScreenPane child UIDs and exact final field/source route.
  - Closed the former possible CursorManager.cpp/private-helper split as rejected and historicalized the generated staging container.

- 2026-06-14 C001 confidence refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:82`.
  - After: `COMPLETION:86`, `CONFIDENCE:85`.
  - Summary/evidence: live IDA MCP session `b001_0003gy` reconfirmed the exact helper island sizes, the `SetCursor`/`ShowCursor` and screen timer helper edges, leaf width/height accessors, broad `0x0067a7cc` root-screen singleton usage, and no modeled function or xrefs at `0x00559080`. The page remains `PROPOSED_RECONSTRUCTION_PATH:"NONE"` because this is still best documented as a ScreenPane companion/typed view, not a proven original source root.
- 2026-06-16 A001 Goal 2 file-confidence refresh:
  - Changed to: completion `87`, confidence `87`.
  - Summary/evidence: active IDB checks reconfirmed helper caller counts and showed the cursor-resource path is represented by modeled [UID:00039X][0x00558f70-0x005590da.ScreenPaneCursorResourceLoader](by-memory/0x00558f70-0x005590da.ScreenPaneCursorResourceLoader.md) with a startup caller, while raw `0x00559080` still has zero xrefs. This strengthens the reviewed `NONE` source-root decision: cursor behavior belongs with ScreenPane support unless future original-source evidence proves a separate helper type.
- 2026-06-05:
  - Before: the projected path was intentionally blank, which kept this reviewed ScreenPane companion/facet in generated file-coverage errors.
  - After: set `PROPOSED_RECONSTRUCTION_PATH` to `NONE`; the page remains a non-standalone helper view over [UID:0000NB][ScreenPane](by-file/ScreenPane.md) / [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md).
  - Summary/evidence: live IDA MCP `lookup_funcs` confirms the helper functions at `0x00557380` (`0x21` bytes) and `0x005573f0` (`0x3c` bytes); this preserves the existing ScreenPane ownership decision without emitting a fake source root.
- 2026-06-02:
  - Before: scored `84/72` with the same evidence, leaving the page in Low_Confidence.
  - After: scored `86/82` and added explicit no-autogen rationale.
  - Summary/evidence: the documented ScreenPane field-offset and singleton alias evidence is strong enough for the current non-promotion decision, while cursor-resource initialization remains the open follow-up.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:72`.
  - Summary/evidence: cursor/screen helper behavior, shared `g_pScreenPane` storage, typed-view aliasing, offsets, callers, and ownership warnings are documented; confidence is lower than the documentation completeness because a standalone original `CursorManager.cpp` remains weakly supported.
