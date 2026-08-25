*** UID:0001W2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000CO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000CO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScrollVolumePaneLayout

## Status

- Confidence: very strong for the exact `0x110` natural layout, signed value/range fields, distinct hover/active bytes, `Point` y/x order, resolved `+0xfb` writer, three inherited vtable views, and direct owner.
- Direct owner: [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md), with source file [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md)
- Primary memory evidence: [UID:0001H2][0x00564710-0x005654ec.ScrollVolumePane](by-memory/0x00564710-0x005654ec.ScrollVolumePane.md)
- Vtable evidence: [UID:0001YT][ScrollVolumePaneVtables](by-type/by-vtable/ScrollVolumePaneVtables.md)
- Size evidence: `NewOptionPane::NewOptionPane` allocates `272` bytes twice before calling the constructor; field accesses end at `+0x10f`, confirming a naturally aligned `0x110` object.
- Human declaration policy: use natural C++ alignment. Do not add synthetic authored padding fields; compiler alignment supplies `+0xfd` and `+0x105..+0x107`. An IDA-only UDT may use explicit padding solely to preserve exact offsets.

## Accepted Exact Natural Layout

| Offset | Size | Human source field | Exact interpretation |
| --- | --- | --- | --- |
| `+0x000` | `0xf8` | inherited `Pane` | Includes primary Pane state plus inherited EventHandler and TimerHandler views at the documented base offsets. |
| `+0x0f8` | 2 | `unsigned short m_trackStateWord` | Change-detecting raw setter; packed constructor default is zero. |
| `+0x0fa` | 1 | `unsigned char m_scrollStyle` | Change-detecting raw setter; constructor default is one. |
| `+0x0fb` | 1 | `bool m_thumbDragActive` | Written by `HandlePointerOrMouseEvent`; consumed by paint, hit-test, and rectangle geometry. |
| `+0x0fc` | 1 | `unsigned char m_volumeType` | Constructor argument forwarded to `NewOptionPane::OnVolumeChanged`. |
| `+0x0fd` | 1 | implicit alignment | Compiler-supplied alignment before signed short state; no human padding member. |
| `+0x0fe` | 2 | `short m_value` | Signed current value; clamped and compared through signed branches. |
| `+0x100` | 2 | `short m_range` | Signed maximum/range value, clamped to `0..30000`. |
| `+0x102` | 1 | `bool m_enabled` | Constructor/Enable/Disable/CanAdjust state. |
| `+0x103` | 1 | `signed char m_hoverPart` | Hovered part or `-1`; distinct from active interaction state. |
| `+0x104` | 1 | `signed char m_activePart` | Active interaction part or `-1`. |
| `+0x105` | 3 | implicit alignment | Compiler-supplied alignment before `Point`; no human padding array. |
| `+0x108` | 4 | `m_thumbDragOffset.y` | Vertical/local-Y offset, matching shared `Point` member order. |
| `+0x10c` | 4 | `m_thumbDragOffset.x` | Horizontal/local-X thumb offset used by value conversion. |

The class declaration therefore uses signed `short` values and natural alignment, and its size assertion is `0x110`. Historical `PointPair`, unsigned value/range, `m_highlightPart`, and missing `+0xfb` writer descriptions are superseded by this table.

## Historical Layout Notes (Superseded Where Corrected Above)

`ScrollVolumePane` extends `Pane` and exposes three vtable views. The confirmed local state lives near the end of the object:

| Offset | Size | Observed field | Evidence |
| --- | --- | --- | --- |
| `+0x00` | 4 | primary vtable | Constructor writes `ScrollVolumePane` vtable. |
| `+0xa0` | 4 | secondary vtable | Constructor writes second `ScrollVolumePane` vtable. |
| `+0xa4` | 4 | tertiary TimerHandler/update-handler subobject view | Constructor writes third vtable; raw begin/reset interaction helpers pass `ecx = this + 0xa4` to `TimerHandler::ScheduleTimer(0, 200, 0, 0)` at `0x005975e0` and `TimerHandler::RemovePendingTimers()` at `0x00597600`; do not treat this as a standalone widget-local data field. |
| `+0x44` | 16 | bounds rectangle | Setters invalidate through vtable slot using `this + 0x44`; geometry helpers read the same rectangle. |
| `+0xf8` | 2 | `m_trackStateWord` | Constructor initializes the containing dword to `0x00010000`; [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw.md) compares/writes this inferred track-state low word and invalidates the bounds rect when changed. Prior `m_lowStateWord` wording was the storage-shaped draft name. |
| `+0xfa` | 1 | `m_scrollStyle` | Constructor sets it to `1` through the packed dword store; [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw.md) compares/writes this inferred scroll/slider style-state byte and invalidates the bounds rect when changed. Current MCP finds no local consumers outside the setter, so the name is source-facing inference rather than original-symbol proof. |
| `+0xfb` | 1 | `m_thumbDragActive` / thumb-drag override flag | Paint, hit-test, and geometry helpers check this byte before using cursor-derived/stored drag placement. B014 found no writer inside this class island, so treat the write route as external/base/not-yet-modeled until proven. |
| `+0xfc` | 1 | `m_volumeType` | Constructor stores the argument; value-change helper passes it to `NewOptionPane::OnVolumeChanged`. |
| `+0xfe` | 2 | `m_value` | `SetValue` writes this word; `SetRange` clamps it; `NotifyValueChange` reads it as old value before callback dispatch. |
| `+0x100` | 2 | `m_range` | `SetRange` writes this word; paint/geometry/value math divide or clamp by it. |
| `+0x102` | 1 | `m_enabled` | Constructor initializes it to `1`; `Enable`/`Disable` mutate it; `CanAdjust` requires it to be set. |
| `+0x103` | 1 | `char m_hoverPart` | Hovered slider part, with `0xff` / `-1` as no-part sentinel; set by `SetHoverPart`, forced to thumb by begin-interaction, invalidated/cleared by commit/reset, and used by painting. Historical `m_highlightPart` / `SetHighlightPart` wording is superseded. |
| `+0x104` | 1 | `char m_activePart` | Active interaction/tracking part, with `0xff` / `-1` as no-part sentinel; written by begin-interaction, read by commit, and cleared by reset. |
| `+0x108` | 8 | `PointPair m_thumbDragOffset` | Eight-byte mouse-to-thumb offset written by `InitPointPair` during thumb begin-interaction. The first component stores the vertical/top offset (`mouseY - rect.top`); the second/+4 component stores the horizontal/track offset (`mouseX - rect.left`). |
| `+0x10c` | 4 | horizontal/track component of `m_thumbDragOffset` | The `+4` component of the `+0x108` point, not an unrelated independent field; [UID:0001H5][0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange](by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md) subtracts this component from `mouseX` while computing the horizontal volume value. Do not force final `Point::x/y` source spelling until shared point layout names are reconciled. |

## State Values

Known slider part codes:

| Code | Meaning |
| --- | --- |
| `0` | `kScrollVolumePartLeading`, leading/left end segment |
| `1` | `kScrollVolumePartPageBeforeThumb`, horizontal track before the thumb |
| `2` | `kScrollVolumePartThumb`, draggable thumb |
| `3` | `kScrollVolumePartPageAfterThumb`, horizontal track after the thumb |
| `4` | `kScrollVolumePartTrailing`, trailing/right end segment |
| `0xff` / `-1` | `kScrollVolumePartNone`, no highlighted or active part |

## Evidence Notes

- `NewOptionPane::NewOptionPane` (`0x0053ff90`) allocates `272` bytes twice and calls `0x00564710(v10, 1)` at `0x00540097` and `0x00564710(v12, 0)` at `0x005400c6`, confirming the object size and the two option sliders.
- Constructor decompilation writes `+0xfc`, clears the current/range dword at `+0xfe`, initializes the packed state cluster at `+0xf8` to `0x00010000` (`m_trackStateWord = 0`, `m_scrollStyle = 1`, `m_thumbDragActive = 0`), writes `+0x102/+0x103` through a packed word, writes `+0x104 = 0xff`, clears the point at `+0x108`, and installs vtable bases at `+0`, `+0xa0`, and `+0xa4`.
- 2026-06-08 A008 IDA MCP disassembly split three additional raw helper spans: [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw.md) writes word `+0xf8`, [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw.md) writes byte `+0xfa`, and [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md) tests enabled byte `+0x102` plus positive range word `+0x100`.
- 2026-06-26 B007 current MCP session `80de0a67` refreshes the [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md) layout evidence without changing field offsets. Scoped `search_text` over `0x00564710-0x005654ec` found 11 `102h` hits supporting `m_enabled`: constructor packed initialization of `+0x102/+0x103`, `Enable` writes `1`, `Disable` writes `0`, `CanAdjust` tests zero, and paint/hit-test/geometry paths test enabled behavior. The same pass found 11 `100h` hits supporting `m_range`: `SetRange` writes the max/range word, `CanAdjust` tests it against zero, and paint/hit-test/geometry/notify paths use it for slider math. A separate 10-hit `0FEh` census keeps `m_value` distinct from `m_range`: constructor clears it, `SetRange` clamps it, `SetValue` writes it, and paint/hit-test/geometry/notify paths read it as the current slider value. `0x100` = 256 and `0x102` = 258 (Verified with tools/int_convert.py).
- 2026-06-25 B001 current MCP session `80de0a67` resolves `+0xf8` to inferred `m_trackStateWord`: target instructions compare/store the word and invalidate bounds, constructor packed initialization gives the cluster values listed above, scoped field-reference scan over `0x00564710-0x005654ec` finds `0F8h` only in the constructor plus [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw.md), and the sibling `+0xfa` setter has the same compare/store/invalidate shape. The same scan separates `+0xfb` as the drag-active byte consumed by paint, hit-test, and `GetPartRect`, so `+0xf8` is not the thumb-drag flag, live value, range, enabled byte, highlight part, active part, or drag-offset field.
- 2026-06-25 B002 current MCP session `80de0a67` resolves `+0xfa` to inferred `m_scrollStyle`: target bytes and disassembly show only a compare/store/invalidate helper, constructor initialization sets the byte to `1`, `xrefs_to` and VA/RVA/raw-offset pointer-pattern scans find no raw-start route, and scoped `search_text` over `0x00564710-0x005654ec` finds `0FAh` only at the target compare/store. The same census separates `+0xfb` as the drag-override byte used by paint, hit-test, and geometry; `+0xfc`, `+0xfe`, `+0x100`, `+0x102`, `+0x103`, `+0x104`, and `+0x108/+0x10c` have their own established roles. The related `ScrollSpellInventoryPane` raw setter at `0x0055f530` has the same `+0xfa` invalidating scroll style/state shape, supporting `m_scrollStyle` while preserving the exact-original-name caveat.
- `SetRange` uses `this[127]` and `this[128]`, matching words at `+0xfe` and `+0x100`.
- `Enable` and `Disable` read/write byte `+0x102`.
- Paint, `GetPartRect`, hit-test, and value-change helpers use `+0xfb`, `+0xfe`, `+0x100`, `+0x102`, `+0x103`, `+0x104`, and the `+0x108/+0x10c` point/offset fields with the fixed 38-pixel thumb width and `SCRBUTT2.EPF`.
- Raw helper pages now cover `0x00565170`, `0x005651e0`, and `0x00565490`, confirming hover-part, active-part, drag-offset, and reset-state use independently of the historical/superseded Wave3 method-name snapshot.
- Historical 2026-06-18 B003 reanalysis used then-draft `m_highlightPart` for `+0x103`; current accepted vocabulary is `m_hoverPart`. Its `m_activePart` at `+0x104`, two-component `m_thumbDragOffset` at `+0x108/+0x10c`, and `+0xa4` TimerHandler/update-handler subobject-view conclusions remain current.
- 2026-06-23 B005 current MCP session `80de0a67` rechecked [UID:0002LC][0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw](by-memory/0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw.md) and confirmed this layout mapping from the raw begin-interaction body: `0x5651fc` reads `+0x103`, `0x565239` writes thumb value `2` to `+0x103`, `0x56525b` passes `this+0x108` to the Point initializer, `0x56526c` writes the active part byte to `+0x104`, and `0x565288` schedules the timer through `ecx=this+0xa4`. Later accepted terminology corrects `m_highlightPart` to `m_hoverPart`, confirms localY/localX and Point y/x order, and excludes trailing padding at `0x0056529f`.
- 2026-06-19 B001 [UID:0001H5][0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange](by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md) source-quality pass corrected the orientation of this control's part map: `ScrollVolumePane` value computation is horizontal, part `0` and part `4` are collapsed left/right edge regions, part `2` is the thumb, and the second/+4 component at `+0x10c` is the horizontal drag offset consumed by the notify helper. The older top/bottom and fixed-height wording was a stale scrollbar-style interpretation.
- IDA xrefs confirm vtable bases `0x006240b4`, `0x00624100`, and `0x00624130` installed by the constructor.
- 2026-06-11 live IDA MCP recheck confirms `NexusTK.exe` models the constructor as `0x00564710-0x005647b1`, `SetRange` as `0x00564820-0x0056487b`, `SetValue` as `0x00564880-0x005648a7`, `0x00564910-0x00564af1` under the superseded `OnMouseEvent` label (current source identity `HandlePointerOrMouseEvent`), `OnPaint` as `0x00564b50-0x00564e21`, `GetPartRect` as `0x00565010-0x0056516b`, commit helper as `0x005652a0-0x00565360`, and notify helper as `0x00565360-0x00565488`.
- The same 2026-06-11 recheck reports no IDA function starts at the raw helper addresses `0x005647c0`, `0x005647f0`, `0x005648f0`, or `0x00565490`, preserving their raw/projected-helper status rather than promoting them to modeled methods.
- Constructor/store evidence remains one data xref per `ScrollVolumePane` vtable base: `0x006240b4` from `0x00564761`, `0x00624100` from `0x00564767`, and `0x00624130` from `0x00564771`.
- NewOptionPane callers remain stable: constructor calls at `0x00540097` and `0x005400c6`, `SetRange` calls at `0x005403c7` and `0x005403de`, `SetValue` calls at `0x00540416` and `0x00540463`, `Enable` calls at `0x00541aa7` and `0x00541af3`, and `Disable` calls at `0x00541ac4` and `0x00541b0f`.

## Assignment Gate

Assigned to direct owner [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md). This layout is `92/94`, the class parent is `93/94`, and the file parent [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md) is `92/93`. Reconstruction channels remain blank because the exact human declaration is emitted by the class H channel. Original private spellings and raw direct routes remain provenance limits, not layout or source-code blockers.

## Cross-References

- [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md)
- [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md)
- [UID:0001H2][0x00564710-0x005654ec.ScrollVolumePane](by-memory/0x00564710-0x005654ec.ScrollVolumePane.md)
- [UID:0001YT][ScrollVolumePaneVtables](by-type/by-vtable/ScrollVolumePaneVtables.md)
- [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw.md)
- [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw.md)
- [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md)
- [UID:0000M7][OptionPane](by-file/OptionPane.md)

## Changes

- 2026-06-26 B007 [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md) field-census sync:
  - Score remains `88/89`; layout ownership, field offsets, and blank layout C++ remain unchanged.
  - Evidence: accepted B007 report and current MCP session `80de0a67` reconfirm `+0x102` as `m_enabled`, `+0x100` as `m_range`, and `+0xfe` as separate `m_value` through scoped hit counts and local use roles. The child formal C++ reads `m_enabled && m_range > 0`; rejected alternatives for the predicate fields include visibility/focus/drag/active/highlight names for `+0x102`, value/style/part/drag-offset names for `+0x100`, and any merge of the `m_value` and `m_range` words.
- 2026-06-11 A002 Batch 175 live evidence refresh:
  - What existed before: the layout page was already assigned at `85/86`, with raw helper split evidence from Batch 137.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:88`, plus a new dated live-IDB recheck.
  - Summary/evidence: IDA MCP `py_eval` reconfirmed modeled method boundaries, raw helper non-function status, constructor vtable-store data xrefs, and the stable NewOptionPane constructor/setter/enable/disable caller set. Completion remains below final-source quality because inherited base layout and final field/helper names still need final C++ audit.
- 2026-06-18 B003 source-quality field sync:
  - Changed to: retained score `87/88` and replaced provisional tail-field wording for `+0xa4`, `+0x103`, `+0x104`, `+0x108`, and `+0x10c`.
  - Historical evidence: B003 rechecked the three raw interaction helper bodies and local PE routes and then accepted draft `m_highlightPart`; current accepted vocabulary supersedes it with `m_hoverPart`, while `m_activePart` and `m_thumbDragOffset` remain current. The coordinate order is now resolved as Point `y@+0`, `x@+4`.
- 2026-06-19 B001 orientation/value-math sync:
  - Changed to: retained score `87/88` and corrected `m_thumbDragOffset` component wording plus the known part-code table from vertical top/bottom wording to horizontal left/right wording.
  - Evidence: B001's accepted [UID:0001H5][0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange](by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md) report disassembled the value helper and confirmed `mouseX - [this+0x10c] + 1`, out-of-line `GetPartRect(2)`, inlined constant `GetPartRect(0/4)` left/right edge math, and fixed 38-pixel thumb width semantics.
- 2026-06-19 B014 class source-quality incorporation:
  - Historical changed state: `88/89` accepted then-draft `m_lowStateWord` and `m_highlightPart` along with `m_scrollStyle`, `m_thumbDragActive`, `m_volumeType`, `m_value`, `m_range`, `m_enabled`, `m_activePart`, and `m_thumbDragOffset`, and added the `ScrollVolumePart` enum. Current corrections are `m_trackStateWord` and `m_hoverPart`; the remaining listed names stay accepted, and `m_scrollStyle` supersedes the earlier generic `m_stateByte` wording.
  - Evidence: B014 report tied the field names to raw setter/predicate helpers, horizontal hit-test/get-rect/value math, `NewOptionPane` callback route, and the explicit caveat that `+0xfb` has no local writer while `+0x10c` is the horizontal/track component of the drag-offset pair.
- 2026-06-23 B005 [UID:0002LC][0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw](by-memory/0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw.md) source-quality sync (the endpoint was later corrected to exclude one `0xCC` byte):
  - Score remains `88/89`; layout ownership and emitted state remain unchanged.
  - Evidence: current MCP session `80de0a67` ties the child formal C++ directly to layout offsets `+0x103`, `+0x104`, `+0x108/+0x10c`, and `+0xa4`; the update confirms `m_activePart` is byte storage for the source-facing `ScrollVolumePart`, not an independent integer field, and keeps the `+0x10c` horizontal component caveat.
- 2026-05-31: Changed completion/confidence from `0/0` to `78/84` and marked the layout reconstructable.
  - Before: The page used metadata size evidence and treated the packed `+0xf8` dword as a single field.
  - After: The page records IDA allocation evidence for the `0x110` object size, splits the packed `+0xf8..+0xfb` state, and ties the tail fields to constructor, setter, paint, hit-test, raw helper, and callback decompilation evidence.
  - Evidence: IDA MCP checks of `NewOptionPane::NewOptionPane`, `ScrollVolumePane` constructor/setters/paint/hit-test/commit/value-change helpers, raw helper disassembly at `0x00565170`, `0x005651e0`, `0x00565490`, and vtable xrefs.
- 2026-06-08 A008 Batch 137 strict-gate and raw-field update:
  - Before: score was `78/84`, and the layout page did not link the raw helpers that write `+0xf8`, `+0xfa`, or test enabled/range state.
  - Changed to: score `85/86` and `AUTOGEN_PARENT_UID:0000CO`.
  - Evidence: live IDA MCP rechecked constructor allocation/field stores, vtable install xrefs, caller edges from `NewOptionPane`, internal helper callers, and the newly split raw helpers [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw.md), [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw.md), and [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md). [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md) and [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md) now also meet the strict `85/85` parent gate.
- 2026-06-25 B002 [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw.md) source-quality sync:
  - Score remains `88/89`; layout ownership and emitted state remain unchanged.
  - Evidence: accepted B002 implementation updates `+0xfa` from generic `m_stateByte` to inferred `m_scrollStyle`, synchronized with [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw.md) and [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md). Current MCP session `80de0a67` confirms no local consumers outside the setter, constructor default `1`, no raw-start xrefs/pointer route, and distinct `+0xfb` drag-override use; exact original spelling/effect remain caveats.
- 2026-06-25 B001 [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw.md) source-quality sync:
  - Score remains `88/89`; layout ownership and emitted state remain unchanged.
  - Evidence: accepted B001 implementation updates `+0xf8` from storage-shaped `m_lowStateWord` wording to inferred `m_trackStateWord`, synchronized with [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw.md) and [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md). Current MCP session `80de0a67` confirms target compare/store/invalidate instructions, constructor packed initialization `0x00010000`, sibling `+0xfa` setter shape, and distinct `+0xfb` drag-active consumers in paint, hit-test, and `GetPartRect`.
