*** UID:00003E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CursorManager

## Status

- Confidence: very strong for the final non-standalone decision and historical typed-view role; UID0001G7 closes the former private helper/header split in favor of exact ScreenPane methods.
- Source disposition: no CursorManager source file or class emission. [UID:0000NB][ScreenPane](by-file/ScreenPane.md) is the accepted source root; [UID:0000IL][CursorManager](by-file/CursorManager.md) remains a non-emitting history/index page.
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
- 2026-06-14 A001 IDA MCP refresh on database `b001_0003gy` reconfirmed helper starts/sizes at `0x00557380` size `0x21`, `0x005573b0` size `0x33`, `0x005573f0` size `0x3c`, `0x00557430`/`0x00557440` size `0x9`, `0x00557450`/`0x00557460` size `0x8`, and `0x00557470` size `0x22d`; `0x00559080` remains raw/non-function loader code inside the broader screen/surface range.
- 2026-06-14 xrefs show broad caller fan-in to the cursor helpers while `0x0067a7cc` still aliases root screen storage; `SetActiveCursor` calls only `SetCursor` and `ShowCursor`, `ShowCursor(TRUE/FALSE)` wrappers call `ShowCursor`, and the width/height getters remain leaf reads. No constructor, destructor, allocator, or independent singleton lifetime appeared in the refreshed evidence.

## Ownership Decision Matrix

| Evidence | Decision |
| --- | --- |
| Helpers use root-object offsets `+0x112`, `+0x114`, `+0x550`, and `+0x580` | Historical generated typed view only; exact UID0004RT/UID0004S0/UID0004S2 methods belong to [UID:0000CB][ScreenPane](by-class/ScreenPane.md). |
| [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md) aliases [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) | Do not emit a second singleton/global declaration. |
| Cursor handles are loaded by the screen/surface lifecycle range at `0x00559080-0x005590da` | Keep cursor-resource initialization with ScreenPane/SurfacePresentation documentation unless a distinct constructor is later found. |
| No constructor, destructor, allocation site, or independent lifetime has been documented | Keep `RECONSTRUCTABLE:FALSE` for this class page and leave C++ blank. |
| Historical generated `class_CursorManager.cpp` names the view | Preserve the page as superseded recovered-output provenance, not current source-file proof. |

## Autogen Status

This page remains unattached and does not emit class C++. UID0001G7 final reanalysis proves the named view is generated/historical: all seven exact methods are ScreenPane children, g_pCursorManager aliases g_pScreenPane, and no separately allocated original class, source file, vtable, or singleton lifetime exists.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `88` | The page records the full historical helper inventory, root offsets, alias and loader relationships, exact replacement ScreenPane children, ownership decision, no-autogen state, caller/callee evidence, and rejected standalone source route. |
| Confidence `92` | Direct receiver, constructor, global alias, field, cursor-loader, and exhaustive negative lifetime evidence prove the non-emitting historical typed-view decision. Stripped symbols cannot prove whether developers ever used a private nickname, which caps confidence below the exact method pages. |

## Final Historical Typed-View Disposition

[UID:0001G7][0x00557380-0x00557467.ScreenCursorHelpers](by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md) is now a non-emitting semantic index. Its exact methods are:

- [UID:0004RR][0x00557380-0x005573a0.ScreenPaneMarkDirtyRegion](by-memory/0x00557380-0x005573a0.ScreenPaneMarkDirtyRegion.md) and [UID:0004RS][0x005573b0-0x005573e2.ScreenPaneStartPresentation](by-memory/0x005573b0-0x005573e2.ScreenPaneStartPresentation.md), which were always root-screen operations rather than cursor-manager behavior.
- [UID:0004RT][0x005573f0-0x0055742b.ScreenPaneSetActiveCursor](by-memory/0x005573f0-0x0055742b.ScreenPaneSetActiveCursor.md), which owns the signed-byte index, signed-short cache, 12-entry HCURSOR table, SetCursor, and forced ShowCursor call.
- [UID:0004RU][0x00557430-0x00557438.ScreenPaneShowCursor](by-memory/0x00557430-0x00557438.ScreenPaneShowCursor.md) and [UID:0004RV][0x00557440-0x00557448.ScreenPaneHideCursor](by-memory/0x00557440-0x00557448.ScreenPaneHideCursor.md), which prove separate no-argument visibility methods rather than one boolean member.
- [UID:0004S0][0x00557450-0x00557457.ScreenPaneGetScreenWidth](by-memory/0x00557450-0x00557457.ScreenPaneGetScreenWidth.md) and [UID:0004S2][0x00557460-0x00557467.ScreenPaneGetScreenHeight](by-memory/0x00557460-0x00557467.ScreenPaneGetScreenHeight.md), which return signed-short ScreenPane constructor fields.

The former CursorManager method spellings and `class_CursorManager.cpp` route are explicitly superseded history. This page retains `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal C++, and no class declaration. It must not produce a duplicate singleton, type, method declaration, or method body.

No evidence supports a private header-only facade strongly enough to preserve it as current source: type queries return no CursorManager type, target methods have no CursorManager vtable/data refs, and no constructor/destructor/allocation/storage/lifetime exists. These negatives are now a closed source disposition, not a deferred question.

## Cross-References

- [UID:0000IL][CursorManager](by-file/CursorManager.md)
- [UID:0001G7][0x00557380-0x00557467.ScreenCursorHelpers](by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md)
- [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md)
- [UID:0000CB][ScreenPane](by-class/ScreenPane.md)
- [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md)
- [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md)

## UID0003CJ Cursor-Pool Evidence

[UID:0003CJ][0x0062317c-0x00623480.ScreenPaneResourceStringData](by-memory/0x0062317c-0x00623480.ScreenPaneResourceStringData.md) contains ten cursor path literals at `0x00623304-0x0062345c`, but no CursorManager object/table declaration. Every path has one direct xref from [UID:00039X][0x00558f70-0x005590da.ScreenPaneCursorResourceLoader](by-memory/0x00558f70-0x005590da.ScreenPaneCursorResourceLoader.md), and the loader uses `.ani` first with `.cur` fallback for normal, select, view, put, and attack cursor slots.

The exact literal bytes reinforce the existing class rejection: they are compiler-pooled inline arguments in a ScreenPane-owned method, not class-static members or resource descriptors. Combined with the existing absence of a separate allocation, constructor, vtable, storage, and lifetime, this closes the remaining string-grouping caveat in favor of ScreenPane. Preserve `88/92`, owner none, reconstructable false, blank emitter/formal, and all historical typed-view evidence.

## Changes

- 2026-07-24 B001 UID0003CJ class synchronization: preserved `88/92` and false/non-emitting historical view; added exact cursor-pool range, sole loader xrefs/fallback order, and rejection of class-static strings/resource descriptors/separate source ownership.

- 2026-07-15 B002 accepted UID0001G7 callback:
  - Raised `85/86` to `88/92` while retaining NONE/FALSE/blank non-emitting metadata.
  - Added the seven real ScreenPane child links and exact replacement behavior/type ownership.
  - Historicalized the generated CursorManager class/source route and closed the former private helper/header split as rejected by direct and negative evidence.

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
- 2026-06-14 A001 Goal 2 refresh:
  - Before: `78/84`, with enough evidence for a negative standalone-class decision but no current helper/xref refresh.
  - After: `85/86`, preserving `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, and `RECONSTRUCTABLE:FALSE`.
  - Summary/evidence: live IDA MCP reconfirmed helper starts, raw loader status, Win32 cursor callees, root-screen alias xrefs, and the continued absence of separate constructor/destructor/allocation evidence.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `70/68`.
  - Summary/evidence: helper bodies, cursor/dimension offsets, root screen relationship, and absence of separate lifetime evidence are documented; confidence stays lower because the `CursorManager` class identity is probably a generated typed view over `ScreenPane` storage.
