*** UID:0000CO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;

enum ScrollVolumePart {
    kScrollVolumePartLeading = 0,
    kScrollVolumePartPageBeforeThumb = 1,
    kScrollVolumePartThumb = 2,
    kScrollVolumePartPageAfterThumb = 3,
    kScrollVolumePartTrailing = 4,
    kScrollVolumePartNone = -1
};

class ScrollVolumePane : public Pane
{
public:
    explicit ScrollVolumePane(unsigned char volumeType);
    void SetTrackStateWord(unsigned short state);
    void SetScrollStyle(unsigned char style);
    void SetRange(short range);
    void SetValue(short value);
    void Enable();
    void Disable();

protected:
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual void OnPaint();

private:
    enum { kThumbSpan = 38 };
    bool CanAdjust() const;
    ScrollVolumePart HitTestPart(int localY, int localX);
    void GetPartRect(ScrollVolumePart part, RectBounds *rect);
    void SetHoverPart(ScrollVolumePart part);
    void BeginInteraction(ScrollVolumePart part, int localY, int localX);
    void CommitInteraction();
    void NotifyValueChange(int localY, int localX);
    void ResetInteractionState();

    unsigned short m_trackStateWord;
    unsigned char m_scrollStyle;
    bool m_thumbDragActive;
    unsigned char m_volumeType;
    short m_value;
    short m_range;
    bool m_enabled;
    signed char m_hoverPart;
    signed char m_activePart;
    Point m_thumbDragOffset;
};

typedef char ScrollVolumePaneSizeMustBe272[
    sizeof(ScrollVolumePane) == 0x110 ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScrollVolumePane

## Status

- Confidence: very strong for the complete nineteen-method class model, exact `0x110` natural layout, three inherited vtable views, horizontal event/timer/paint behavior, option-owner callback, and source/header split.
- Source file: [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md), emitted at position `10`.
- Physical index: [UID:0001H2][0x00564710-0x005654ec.ScrollVolumePane](by-memory/0x00564710-0x005654ec.ScrollVolumePane.md), now a non-emitting address index rather than a method owner.
- Formal routing: the H channel owns the complete human declaration; the CPP channel contains only `[[CHILDREN]]`; nineteen exact by-memory pages own method definitions directly under this class.
- Vtables: [UID:0001YT][ScrollVolumePaneVtables](by-type/by-vtable/ScrollVolumePaneVtables.md). Layout: [UID:0001W2][ScrollVolumePaneLayout](by-type/by-struct/ScrollVolumePaneLayout.md).
- Corrected source model: EventHandler slots are `HandlePointerOrMouseEvent` and `HandleKeyOrTextEvent`; TimerHandler owns `OnTimer`; `m_value`/`m_range` are signed shorts; `m_hoverPart` and `m_activePart` are distinct signed bytes; `Point` stores `y` then `x`; `m_thumbDragActive` at `+0xfb` is written by the pointer/mouse path.
- Raw-start route gaps remain explicit negative evidence for six function-shaped children, but no longer block human source names, exact bodies, or direct class ownership.

## Accepted Nineteen-Method Inventory

| Position | Method | Exact page/range |
| --- | --- | --- |
| 10 | constructor | [UID:0004XQ][0x00564710-0x005647b1.ScrollVolumePaneConstructor](by-memory/0x00564710-0x005647b1.ScrollVolumePaneConstructor.md) |
| 20 | `SetTrackStateWord` | [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw.md) |
| 30 | `SetScrollStyle` | [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw.md) |
| 40 | `SetRange` | [UID:0004XR][0x00564820-0x0056487b.ScrollVolumePaneSetRange](by-memory/0x00564820-0x0056487b.ScrollVolumePaneSetRange.md) |
| 50 | `SetValue` | [UID:0004XS][0x00564880-0x005648a7.ScrollVolumePaneSetValue](by-memory/0x00564880-0x005648a7.ScrollVolumePaneSetValue.md) |
| 60 | `Enable` | [UID:0004XT][0x005648b0-0x005648ca.ScrollVolumePaneEnable](by-memory/0x005648b0-0x005648ca.ScrollVolumePaneEnable.md) |
| 70 | `Disable` | [UID:0004XU][0x005648d0-0x005648ea.ScrollVolumePaneDisable](by-memory/0x005648d0-0x005648ea.ScrollVolumePaneDisable.md) |
| 80 | `CanAdjust` | [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md) |
| 90 | `HandlePointerOrMouseEvent` | [UID:0004XV][0x00564910-0x00564af1.ScrollVolumePaneHandlePointerOrMouseEvent](by-memory/0x00564910-0x00564af1.ScrollVolumePaneHandlePointerOrMouseEvent.md) |
| 100 | `HandleKeyOrTextEvent` | [UID:0004XW][0x00564b00-0x00564b05.ScrollVolumePaneHandleKeyOrTextEvent](by-memory/0x00564b00-0x00564b05.ScrollVolumePaneHandleKeyOrTextEvent.md) |
| 110 | `OnTimer` | [UID:0004XX][0x00564b10-0x00564b43.ScrollVolumePaneOnTimer](by-memory/0x00564b10-0x00564b43.ScrollVolumePaneOnTimer.md) |
| 120 | `OnPaint` | [UID:0004XY][0x00564b50-0x00564e21.ScrollVolumePaneOnPaint](by-memory/0x00564b50-0x00564e21.ScrollVolumePaneOnPaint.md) |
| 130 | `HitTestPart` | [UID:0001H3][0x00564e30-0x00565006.ScrollVolumePaneHitTestPart](by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md) |
| 140 | `GetPartRect` | [UID:0004XZ][0x00565010-0x0056516b.ScrollVolumePaneGetPartRect](by-memory/0x00565010-0x0056516b.ScrollVolumePaneGetPartRect.md) |
| 150 | `SetHoverPart` | [UID:0002LB][0x00565170-0x005651e0.ScrollVolumePaneSetHoverPartRaw](by-memory/0x00565170-0x005651e0.ScrollVolumePaneSetHoverPartRaw.md) |
| 160 | `BeginInteraction` | [UID:0002LC][0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw](by-memory/0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw.md) |
| 170 | `CommitInteraction` | [UID:0001H4][0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction](by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md) |
| 180 | `NotifyValueChange` | [UID:0001H5][0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange](by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md) |
| 190 | `ResetInteractionState` | [UID:0002LD][0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw](by-memory/0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw.md) |

## Class Purpose

`ScrollVolumePane` is a horizontal volume slider pane used by the option UI. It tracks a signed current value and maximum range, enabled state, hovered part, active interaction state, and horizontal thumb drag offset. Pointer input can page before/after the thumb, drag the thumb along the horizontal track, commit changes, and refresh only affected part rectangles.

The class renders the slider track and two-part thumb through `SCRBUTT2.EPF` / `BUTTON.PAL`; it does not own sound playback or option packet policy.

## Historical Method Notes (Superseded Where Corrected Above)

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x00564710-0x005647b1` | Constructs the `Pane` base, stores volume type, initializes packed slider state, installs three vtable pointers, and clears the mouse reference point. |
| `SetTrackStateWord(unsigned short state)` | [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw.md) | Function-shaped raw helper that stores inferred `m_trackStateWord` at `+0xf8`, the low word of the `+0xf8..+0xfb` ScrollVolumePane state cluster, and invalidates the bounds rect when changed; no direct raw-start route is recovered, but the field role is no longer an unresolved low-word placeholder. |
| `SetScrollStyle(unsigned char style)` | [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw.md) | Function-shaped raw helper that stores inferred `m_scrollStyle` byte `+0xfa`, defaulted to `1` by the constructor, and invalidates the bounds rect when changed; exact original spelling and live raw-start route remain unrecovered. |
| `SetRange` | `0x00564820-0x0056487b` | Clamps max range to `0..30000`, reduces current value if necessary, and invalidates bounds. |
| `SetValue` | `0x00564880-0x005648a7` | Stores the current value and invalidates bounds when changed. |
| `Enable` | `0x005648b0-0x005648ca` | Sets enabled byte and invalidates the control. |
| `Disable` | `0x005648d0-0x005648ea` | Clears enabled byte and invalidates the control. |
| `CanAdjust() const` | [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md) | Function-shaped raw predicate returning `m_enabled && m_range > 0` from `+0x102/+0x100`; B007 current MCP session `80de0a67` confirms exact bytes, six-byte pre/post padding, raw non-function/no-xref/no-route status, field census, accepted inferred name, and retained formal child C++. |
| `HandlePointerOrMouseEvent(Event *event)` | [UID:0004XV][0x00564910-0x00564af1.ScrollVolumePaneHandlePointerOrMouseEvent](by-memory/0x00564910-0x00564af1.ScrollVolumePaneHandlePointerOrMouseEvent.md) | EventHandler pointer/mouse override handling press, drag, release, capture, hover, page interaction, commit, and timer setup. Historical `OnMouseEvent` was a superseded descriptive label. |
| `HandleKeyOrTextEvent(Event *event)` | [UID:0004XW][0x00564b00-0x00564b05.ScrollVolumePaneHandleKeyOrTextEvent](by-memory/0x00564b00-0x00564b05.ScrollVolumePaneHandleKeyOrTextEvent.md) | EventHandler key/text override returning false. Historical `IsScrollable` was a superseded slot interpretation. |
| `OnTimer(int timerId, int arg0, int arg1)` | [UID:0004XX][0x00564b10-0x00564b43.ScrollVolumePaneOnTimer](by-memory/0x00564b10-0x00564b43.ScrollVolumePaneOnTimer.md) | TimerHandler override that repeats the active slider action and schedules a 30 ms follow-up. Historical `OnLoseFocus` was a superseded slot interpretation. |
| `OnPaint` | `0x00564b50-0x00564e21` | Draws track background and the two-part EPF thumb at the computed value/drag position. |
| `HitTestPart(int mouseX, int mouseY)` | [UID:0001H3][0x00564e30-0x00565006.ScrollVolumePaneHitTestPart](by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md) | IDA/PE-confirmed helper that maps a point to horizontal slider parts `0..4` or `-1` by building the five candidate rectangles inline; stale generated `TextEditPane::TrackScrollButtonF` ownership and the older `GetPartRect` call-through draft are rejected. |
| `GetPartRect(ScrollVolumePart part, RectBounds *rect)` | `0x00565010-0x0056516b` | Sibling geometry helper that computes rectangles for leading end, page-before-thumb track, thumb, page-after-thumb track, and trailing end for callers that need one part rectangle. |
| historical `SetHighlightPart`, corrected to `SetHoverPart(ScrollVolumePart part)` | [UID:0002LB][0x00565170-0x005651e0.ScrollVolumePaneSetHoverPartRaw](by-memory/0x00565170-0x005651e0.ScrollVolumePaneSetHoverPartRaw.md) | Function-shaped raw code invalidates old/new hover parts and stores `m_hoverPart`; IDA does not model the raw start as a function. |
| `BeginInteraction(ScrollVolumePart part, int localY, int localX)` | [UID:0002LC][0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw](by-memory/0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw.md) | Function-shaped raw helper with no modeled raw-start route; formal C++ preserves the signed-byte active-part store and excludes the `0xCC` byte at `0x0056529f`. |
| `CommitInteraction()` | [UID:0001H4][0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction](by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md) | IDA-confirmed helper called from `HandlePointerOrMouseEvent`, `OnTimer`, and raw begin-interaction paths; commits the active part and clears transient state. |
| `NotifyValueChange(int mouseY, int mouseX)` | [UID:0001H5][0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange](by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md) | IDA-confirmed helper that computes the horizontal value and calls `NewOptionPane::OnVolumeChanged` when changed. |
| `ResetInteractionState()` | [UID:0002LD][0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw](by-memory/0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw.md) | Function-shaped raw code that removes pending timer/update work and clears timer/hover state; IDA currently does not model it as a function. |

## Excluded Tail

IDA/cache identify the immediately following `0x005654ec` and `0x005654f7` adjustor thunks and `0x00565510` deleting destructor as `ScrollablePane` destructor glue. Do not use those rows as evidence that `ScrollVolumePane.cpp` owns a destructor implementation unless later IDA/vtable work proves otherwise.

2026-05-26 IDA MCP recheck confirms both adjustor thunks still have data refs from vtable slots (`0x00623e58` and `0x00623e88`) and jump to `0x00565510`; `0x00565510` still has no ordinary callers and decompiles as the `ScrollablePane` scalar deleting destructor.

## Layout Notes

See [UID:0001W2][ScrollVolumePaneLayout](by-type/by-struct/ScrollVolumePaneLayout.md). The most important local fields are:

- `+0xf8`: `m_trackStateWord`, the accepted inferred track-state low word set by raw `SetTrackStateWord` and invalidating the pane bounds when changed. Prior `m_lowStateWord` wording is the superseded storage-shaped draft name.
- `+0xfa`: `m_scrollStyle`, an inferred scroll/slider style-state byte set by the raw `SetScrollStyle` helper and initialized to `1`; current MCP finds no local consumers outside that setter, so the name is source-facing inference rather than original-symbol proof.
- `+0xfb`: `m_thumbDragActive` / thumb-drag override flag; paint, hit-test, and part-rectangle helpers read it to force cursor-derived thumb placement, but no writer was found inside this class island.
- `+0xfc`: volume type, set by constructor argument.
- `+0xfe`: current slider value.
- `+0x100`: max slider value/range.
- `+0x102`: enabled byte.
- `+0x103`: `m_hoverPart`, hovered slider part with `0xff` / `-1` no-part sentinel (historically called `m_highlightPart`).
- `+0x104`: `m_activePart`, active interaction/tracking part with `0xff` / `-1` no-part sentinel.
- `+0x108`: `m_thumbDragOffset`, two-component mouse-to-thumb offset written when thumb drag begins.
- `+0x10c`: second/+4 component of `m_thumbDragOffset`; this is the horizontal/track component consumed by `NotifyValueChange`, so the current `Point::x/y` spelling should stay provisional until shared point-layout names are reconciled.

## Part Model

The source-facing part enum is:

| Value | Source-facing name | Meaning |
| --- | --- | --- |
| `0` | `kScrollVolumePartLeading` | leading/left end segment |
| `1` | `kScrollVolumePartPageBeforeThumb` | horizontal track before the thumb |
| `2` | `kScrollVolumePartThumb` | draggable thumb |
| `3` | `kScrollVolumePartPageAfterThumb` | horizontal track after the thumb |
| `4` | `kScrollVolumePartTrailing` | trailing/right end segment |
| `-1` / `0xff` | `kScrollVolumePartNone` | no highlighted or active part |

`kScrollVolumeThumbSpan` is `38` pixels. This fixed metric is used by hit-test, part-rectangle, paint, drag, and value-conversion paths. Prefer leading/trailing/page-before/page-after names over left/right button names because the binary shows slider end segments and page regions, not necessarily standalone clickable arrow buttons.

## Evidence Notes

- IDA `lookup_funcs` confirms all primary methods except raw/projected `0x00565170`, `0x005651e0`, and `0x00565490`.
- 2026-05-31 IDA raw-disassembly pass split those three raw/projected helper spans into exact `by-memory` pages and confirmed their field effects on hover part, active part, drag offset, timer/update view, and reset state.
- IDA `callers` confirms constructor use from `NewOptionPane::NewOptionPane`, range/value setters from `NewOptionPane::ApplyVolumeSettings`, and enable/disable from `NewOptionPane::UpdateSliderVisibility`.
- Historical 2026-05-25 generated-output checks found the helpers at `0x00564e30`, `0x005652a0`, and `0x00565360` absent and described their callers with mouse/focus labels. Current ordinary documentation contains the exact helper pages and identifies the interaction chain through `HandlePointerOrMouseEvent` and `OnTimer`.
- 2026-05-26 IDA MCP recheck reconfirms the same helper chain: hit-test callers at `0x005649f1` and `0x0056530f`, commit callers at `0x00564a83` and `0x00564b28`, and notify callers at `0x005652fb` and `0x00565324`.
- Historical/superseded Wave3 metadata reported `vtable_count: 0`. Current ordinary documentation instead uses the IDA-confirmed vtable bases `0x006240b4`, `0x00624100`, and `0x00624130`, with paint, `HandlePointerOrMouseEvent`, `HandleKeyOrTextEvent`, and `OnTimer` slot identities.
- A historical pre-callback generated snapshot emitted helper rows at `0x00564e30`, `0x005652a0`, and `0x00565360` with stale `TextEditPane::*` signatures. Current ordinary pages attach all three to `ScrollVolumePane`; renewed supervisor generated-output verification remains pending.
- 2026-06-03 restarted IDA MCP recheck reconfirmed raw helper starts `0x00565170`, `0x005651e0`, and `0x00565490` as non-modeled function-table gaps with no xrefs or raw pointer hits. It also reconfirmed the modeled neighbor helpers at `0x00565010`, `0x005652a0`, and `0x00565360`, the `0x005654ec`/`0x005654f7` neighboring `ScrollablePane` thunks, and the raw helper calls into `GetPartRect`, commit, timer start/stop, and invalidation slots.
- 2026-06-08 A008 IDA MCP recheck confirmed the modeled method starts/sizes, constructor stores to `+0xfc/+0xfe/+0x100/+0x102/+0x103/+0x104/+0x108`, vtable installs at `0x00564761`/`0x00564767`/`0x00564771`, constructor/setter callers from `NewOptionPane`, internal helper callers, and the neighboring `ScrollablePane` thunk boundary.
- The same pass split three previously undocumented raw helpers at `0x005647c0`, `0x005647f0`, and `0x005648f0`; all three remain raw/no-direct-route ScrollVolumePane methods, but their source-facing names are no longer generically unresolved. [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw.md) is accepted inferred `SetTrackStateWord` / `m_trackStateWord`, [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw.md) is accepted inferred `SetScrollStyle` / `m_scrollStyle`, and [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md) is accepted inferred `CanAdjust() const`.
- Historical 2026-06-18 B003 reanalysis accepted source-facing first drafts for [UID:0002LB][0x00565170-0x005651e0.ScrollVolumePaneSetHoverPartRaw](by-memory/0x00565170-0x005651e0.ScrollVolumePaneSetHoverPartRaw.md), [UID:0002LC][0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw](by-memory/0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw.md), and [UID:0002LD][0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw](by-memory/0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw.md). That pass used the superseded `m_highlightPart` draft; current accepted vocabulary is `m_hoverPart`, `m_activePart`, and `m_thumbDragOffset`. Its zero VA/RVA/direct-branch routes and rejected `TextEditPane::DrawScrollbarPartF` ownership remain valid historical evidence.
- 2026-06-23 B005 current MCP session `80de0a67` rechecked [UID:0002LC][0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw](by-memory/0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw.md): `lookup_funcs` still reports no function at `0x005651e0`, bounded disassembly shows a complete 71-instruction raw begin-interaction helper, `xref_query` finds zero raw-start refs, and `find_bytes` finds no VA/RVA/raw-offset pointer route. The child now emits the same `BeginInteraction(ScrollVolumePart part, int mouseY, int mouseX)` signature declared above; source code uses enum names for part comparisons and casts to `signed char` only for `m_activePart` byte storage.
- 2026-06-19 B014 class source-quality pass resolves the class declaration and source placement: `ScrollVolumePane` is a horizontal volume slider owned by [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md), configured by [UID:000097][NewOptionPane](by-class/NewOptionPane.md), and routed back through `NewOptionPane::OnVolumeChanged(m_volumeType, m_value)` from the value-change helper. Stale generated `TextEditPane::*` labels on hit-test/commit/notify helpers are rejected as generated-output owner pollution. The nearby `0x005654ec` destructor-like bytes remain excluded `ScrollablePane` adjustor/destructor support, not a source-authored `ScrollVolumePane` destructor.
- 2026-06-25 B001 MCP session `80de0a67` resolves [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw.md) from storage-shaped `SetLowStateWord` / `m_lowStateWord` to inferred `SetTrackStateWord` / `m_trackStateWord`. Target instructions compare/store word `+0xf8` and invalidate bounds; constructor packed initialization `0x00010000` sets `+0xf8 = 0`, `+0xfa = 1`, `+0xfb = 0`; the scoped field scan finds `0F8h` only in constructor plus that setter and finds `0FBh` in paint/hit-test/GetPartRect drag-active consumers. Value, range, enabled, hover-part, active-part, and drag-offset roles remain on their separate fields.
- 2026-06-26 B007 MCP session `80de0a67` resolves the stale final-name-open wording for [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md). `lookup_funcs` keeps the raw start/end as non-functions between modeled `Disable` (`0x1a` / 26 bytes, Verified with tools/int_convert.py) and `0x00564910` under the superseded `OnMouseEvent` label; the current source identity is `HandlePointerOrMouseEvent` (`0x1e1` / 481 bytes, Verified with tools/int_convert.py). `get_bytes` confirms six-byte `0xcc` padding before and after the exact predicate bytes; xref and local PE route scans find no raw-start/end route, while positive controls find the `HandlePointerOrMouseEvent` vtable slot at `0x00624104` and direct routes to sibling modeled helpers. Scoped field census finds 11 `102h` hits for `m_enabled`, 11 `100h` hits for `m_range`, and 10 `0FEh` hits separating `m_value`, so `CanAdjust() const` remains the accepted inferred private predicate name. Exact original spelling and live raw-start route remain confidence caps only.

## Source-Quality Decisions

- Class-level C++ is declaration-only and intentionally places `[[CHILDREN]]` after the closed declaration so exact child method definitions emit outside the class body. Exact method bodies belong to exact by-memory children; the aggregate [UID:0001H2][0x00564710-0x005654ec.ScrollVolumePane](by-memory/0x00564710-0x005654ec.ScrollVolumePane.md) stays blank because it is only the child index/container.
- [UID:0001H3][0x00564e30-0x00565006.ScrollVolumePaneHitTestPart](by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md), [UID:0001H4][0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction](by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md), and [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md) are first-draft-ready after this name pass. The hit-test body constructs its rectangles inline; [UID:0001H3][0x00564e30-0x00565006.ScrollVolumePaneHitTestPart](by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md) should not be simplified to a `GetPartRect` loop because B014 verified `0x00565010` is a sibling helper, not a callee from `0x00564e30`.
- B007 keeps [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md) as first-draft-ready, with the formal child C++ retained only on that exact target page and expressing the `m_enabled && m_range > 0` predicate. Rejected class-level alternatives include `IsEnabled`, `HasRange`, superseded `IsScrollable` (the current slot is `HandleKeyOrTextEvent`), `CanScroll`, `CanDrag`, active/drag/hover names, file-global helper placement, OptionPane/NewOptionPane ownership, generic ScrollBar/ScrollableControlPane ownership, stale TextEditPane ownership, vtable/data treatment, padding, no-owner/non-emitting treatment, and merge/split changes around `Disable` or current `HandlePointerOrMouseEvent` (historically `OnMouseEvent`).
- [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw.md) now emits inferred `SetTrackStateWord` / `m_trackStateWord` first-draft C++; prior `SetLowStateWord` wording is preserved only as superseded storage-shaped draft language. [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw.md) now emits inferred `SetScrollStyle` / `m_scrollStyle` first-draft C++; its cap is the unrecovered original spelling and live dispatch route, not a generic byte-name blocker.
- `0x004a9090` is best documented as `EventMan::GetCursorPosition(Point *)`; `0x005447c0` is a pane screen-origin/screen-offset helper; `0x004b7c50` initializes rectangles; `0x004b7e80` tests point-in-rectangle; `0x005975e0` schedules timer/update work; and `0x00597600` removes pending timer/update work.
- No passive class-page blockers remain. The intentional caps are exact historical spelling/live route for the inferred `+0xf8` and `+0xfa` setters, the inferred-but-unproven external effect for `+0xfa`, the no-local-writer status of `+0xfb`, and final `Point` component spelling for the `+0x108/+0x10c` pair.
- [UID:0002LC][0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw](by-memory/0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw.md) is not a covered-by/comment-only emitter despite the inline duplicate in current `HandlePointerOrMouseEvent` (historically `OnMouseEvent`): it owns a distinct executable byte range with a separate prologue, security-cookie frame, `retn 0Ch`, and child code block. The no-route evidence is a confidence cap and IDA-function-creation blocker, not a class declaration blocker.

## Cross-References

- [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md)
- [UID:0001H2][0x00564710-0x005654ec.ScrollVolumePane](by-memory/0x00564710-0x005654ec.ScrollVolumePane.md)
- [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw.md)
- [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw.md)
- [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md)
- [UID:0001H3][0x00564e30-0x00565006.ScrollVolumePaneHitTestPart](by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md)
- [UID:0002LB][0x00565170-0x005651e0.ScrollVolumePaneSetHoverPartRaw](by-memory/0x00565170-0x005651e0.ScrollVolumePaneSetHoverPartRaw.md)
- [UID:0002LC][0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw](by-memory/0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw.md)
- [UID:0001H4][0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction](by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md)
- [UID:0001H5][0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange](by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md)
- [UID:0002LD][0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw](by-memory/0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw.md)
- [UID:0001W2][ScrollVolumePaneLayout](by-type/by-struct/ScrollVolumePaneLayout.md)
- [UID:0001YT][ScrollVolumePaneVtables](by-type/by-vtable/ScrollVolumePaneVtables.md)
- [UID:0000M7][OptionPane](by-file/OptionPane.md)
- [UID:000097][NewOptionPane](by-class/NewOptionPane.md)
- [UID:0000A2][Pane](by-class/Pane.md)

## Changes

- 2026-06-26 B007 [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md) source-quality implementation:
  - Score remains `89/89`; declaration-level C++ already had `bool CanAdjust() const;` and keeps broad class C++ as a declaration with `[[CHILDREN]]`.
  - Evidence: accepted B007 report and current MCP session `80de0a67` prove the child body remains a raw `m_enabled && m_range > 0` predicate, raise the child to `89/91`, preserve formal child C++, and replace stale unresolved-final-name wording. The class now records the current raw/no-route cap, field census for `+0x102`/`+0x100`/`+0xfe`, positive route controls, accepted inferred `CanAdjust() const` naming, and rejected owner/name/split alternatives.
- 2026-05-30: Changed completion/confidence from `0/0` to `86/80`.
  - Before: The page was unevaluated despite extensive method, layout, vtable, caller, omitted-helper, and excluded-tail documentation.
  - After: Scored as high completion with strong-but-not-perfect confidence because behavior/source ownership are strong while several raw projected helper starts remain unmodeled by IDA.
  - Evidence: Existing method notes, excluded-tail section, layout notes, IDA caller/evidence notes, and exact by-memory/type cross-references support the score.
- 2026-05-30: Corrected the current recovered source path and active-output caveat.
  - Before: The page referenced the old flat `source-3/simroot_v2/class_ScrollVolumePane.cpp` path and described helper rows as omitted from active output.
  - Historical after-state: the page pointed to `source-3/simroot_v2/ui/controls/class_ScrollVolumePane.cpp` and recorded helpers emitted with stale `TextEditPane` signatures. Current ordinary ownership is `ScrollVolumePane`; renewed supervisor generated verification remains pending.
  - Historical/superseded evidence: the then-current `simroot_v2` file list, `class_ScrollVolumePane.cpp.source_map.json`, and `class_ScrollVolumePane.meta_wave3` snapshot reported emitted path `ui\controls\class_ScrollVolumePane.cpp` and active methods `0x00564e30`, `0x005652a0`, and `0x00565360`.
- 2026-05-31: Marked the class reconstructable and replaced inline raw helper rows with exact UID-linked memory pages.
  - Before: The page listed `0x00565170`, `0x005651e0`, and `0x00565490` as inline projected raw spans only.
  - After: Those spans are first-class `by-memory` pages and the class page links to them without adding parent attachments or final C++.
  - Evidence: IDA MCP raw disassembly confirms the three helper-shaped ranges and their state effects; later child pages carry code-entry decisions under the active reconstructable/nonblank-emitter/combined-score gate.
- 2026-06-03 parent attachment update:
  - Before: `AUTOGEN_PARENT_UID` was blank and confidence stayed at `80` despite the file parent already having a valid `NexusTK/ui/controls/` path.
  - Changed to: confidence `82`, `AUTOGEN_PARENT_UID:0000NK`, and position `10`; reconstruction C++ remained blank at that checkpoint, with later child-level code-entry decisions handled on exact method/helper pages.
  - Evidence: the restarted IDA MCP recheck reconfirmed the raw helper gaps, modeled helper chain, and neighboring `ScrollablePane` thunk boundary, while [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md) is already a validated controls source root.
- 2026-06-08 A008 Batch 137 strict-gate and child-split update:
  - Before: score was `86/82`, and the method inventory skipped three raw helper bodies near the constructor/setter cluster.
  - Changed to: score `87/85`; parent remains [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md) at position `10`.
  - Evidence: live IDA MCP rechecked modeled boundaries, constructor field/vtable stores, constructor/setter/helper callers, vtable xrefs, neighboring destructor-thunk ownership, and the newly split raw helpers [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw.md), [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw.md), and [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md). The parent file is now also `88/85`, satisfying the strict parent gate.
- 2026-06-25 B002 [UID:00031N][0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw](by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw.md) source-quality sync:
  - Score remains `89/89`; class declaration C++ now uses `void SetScrollStyle(unsigned char style);` and `unsigned char m_scrollStyle; // +0xfa`.
  - Evidence: accepted B002 report and current MCP session `80de0a67` prove the child body is a raw invalidating setter for byte `+0xfa`, the constructor initializes that byte to `1`, scoped field-use census finds `0FAh` only in the setter, and the related `ScrollSpellInventoryPane` family has the same `+0xfa` raw scroll style/state setter shape. The declaration keeps the inferred-name caveat because no direct caller, consumer, or original symbol was recovered.
- 2026-06-18 B003 raw-interaction source-quality sync:
  - Target child pages [UID:0002LB][0x00565170-0x005651e0.ScrollVolumePaneSetHoverPartRaw](by-memory/0x00565170-0x005651e0.ScrollVolumePaneSetHoverPartRaw.md), [UID:0002LC][0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw](by-memory/0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw.md), and [UID:0002LD][0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw](by-memory/0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw.md) now carry accepted first-draft C++ and PE no-route caveats; the class page remains a declaration/source-owner summary rather than a duplicate body emitter.
  - Historical evidence: B003 rechecked raw-start VA/RVA/direct-branch routes, rejected stale `TextEditPane::DrawScrollbarPartF` ownership for `0x005651e0`, and used then-draft `m_highlightPart`; current accepted field names are `m_hoverPart`, `m_activePart`, and `m_thumbDragOffset`.
- 2026-06-19 B014 class source-quality incorporation:
  - Changed completion/confidence from `87/85` to `89/89` and populated declaration-level first-draft C++ with `ScrollVolumePart`, `kScrollVolumeThumbSpan`, private helper declarations, local field names, and `[[CHILDREN]]`.
  - Evidence: B014 PE/source-quality report confirmed the horizontal slider model, exact child boundaries and padding, direct `NewOptionPane` constructor/setter/callback route, vtable/resource evidence, raw helper no-route evidence, and rejected stale `TextEditPane::*` generated-owner pollution.
- 2026-06-22 Rule 26 [UID:0001H3][0x00564e30-0x00565006.ScrollVolumePaneHitTestPart](by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md) sync:
  - Kept score `89/89` and updated the class declaration/narrative to match the individual hit-test report: `HitTestPart` and `GetPartRect` are sibling helpers, and `HitTestPart` builds candidate rectangles inline rather than delegating to `GetPartRect`.
  - Evidence: `Agent-B014/research/0001H3-ScrollVolumePaneHitTestPart-source-quality.md` directly rechecked `0x00564e30` callers/callees and rejected the stale generated `TextEditPane::TrackScrollButtonF` and call-through interpretations.
- 2026-06-23 B005 [UID:0002LC][0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw](by-memory/0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw.md) implementation sync:
  - Score remains `89/89`; class declaration already had the correct method signature.
  - Historical evidence: the child target then matched `BeginInteraction(ScrollVolumePart part, int mouseY, int mouseX)` and documented `m_activePart` narrowing, then-draft `m_highlightPart`, `m_thumbDragOffset`, no-route evidence, stale TextEditPane rejection, and no covered-by marker. Current accepted vocabulary corrects that draft field to `m_hoverPart` and the formal coordinates to `localY/localX`.
- 2026-06-25 B001 [UID:00031M][0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw.md) source-quality implementation:
  - Score remains `89/89`; class declaration C++ now uses `void SetTrackStateWord(unsigned short state);` and `unsigned short m_trackStateWord; // +0xf8`.
  - Evidence: accepted B001 report and current MCP session `80de0a67` prove the child body is a raw invalidating setter for the `+0xf8` track-state word, constructor initializes the `+0xf8..+0xfb` cluster with packed value `0x00010000`, `+0xf8` appears only in constructor plus that setter, and `+0xfb` is the drag-active byte consumed by paint/hit-test/GetPartRect. `m_lowStateWord` is now only the prior storage-shaped draft wording.
