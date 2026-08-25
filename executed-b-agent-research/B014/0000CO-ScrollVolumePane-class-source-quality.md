** TARGET-REPORT-UID:0000CO **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B014 B-source-quality report: [UID:0000CO] ScrollVolumePane

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B014/research/0000CO-ScrollVolumePane-class-source-quality.md`  
Target path: `source-3/project-documentation/by-class/ScrollVolumePane.md`  
Assignment: report-only source-quality / heuristic pass for `ScrollVolumePane` class and helper pages.  
Status: FINISHED for supervisor review. No by-* documentation and no coverage report files were edited.

## Summary recommendation

Raise `by-class/ScrollVolumePane.md` from `COMPLETION:87`, `CONFIDENCE:85` to `COMPLETION:89`, `CONFIDENCE:89`, keeping `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000NK`, and `EMITTER_UIDS:0000NK`.

The class is ready for declaration-level first-draft C++ with `[[CHILDREN]]`, not for an aggregate body. The declaration should name the class as a `Pane`-derived horizontal volume slider, introduce a source-facing `ScrollVolumePart` enum for part ids `0..4` and `-1`, define `kScrollVolumeThumbSpan = 38`, and declare the known public/virtual/private helpers. Method bodies should remain on exact child by-memory pages. The aggregate `0x00564710-0x005654ec.ScrollVolumePane.md` should remain a no-code container.

The current class and file docs still carry stale language that treats the control as a vertical slider and still overstates stale generated `TextEditPane::*` signatures as unresolved pollution. Fresh child/body evidence supports a horizontal volume slider owned by `ScrollVolumePane`, routed through `NewOptionPane`, with stale `TextEditPane` owner strings rejected as generated-output contamination.

Remaining caps: the raw setters at `0x005647c0`, `0x005647f0`, and `0x005648f0` are source-shaped and first-draft-ready but still need accepted source-facing names; `+0xfb` is best inferred as a thumb-drag override/active flag but no writer was found inside this class island; `+0x108/+0x10c` are a pair of drag-offset components but the local source-level `Point` member order should be documented carefully because the horizontal/track component is the `+0x10c` member.

## Evidence checked

Instruction files:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B014/goal.md`

Primary and support docs:

- `source-3/project-documentation/by-class/ScrollVolumePane.md`
- `source-3/project-documentation/by-file/ScrollVolumePane.md`
- `source-3/project-documentation/by-memory/0x00564710-0x005654ec.ScrollVolumePane.md`
- `source-3/project-documentation/by-type/by-struct/ScrollVolumePaneLayout.md`
- `source-3/project-documentation/by-type/by-vtable/ScrollVolumePaneVtables.md`
- `source-3/project-documentation/by-memory/0x006240b4-0x0062415c.ScrollVolumePaneVtableData.md`
- `source-3/project-documentation/by-memory/0x00624168-0x00624174.ScrollVolumePaneResourceString.md`
- Child helper pages for `0x00564710`, `0x005647c0`, `0x005647f0`, `0x00564820`, `0x00564880`, `0x005648b0`, `0x005648d0`, `0x005648f0`, `0x00564910`, `0x00564b00`, `0x00564b10`, `0x00564b50`, `0x00564e30`, `0x00565010`, `0x00565170`, `0x005651e0`, `0x005652a0`, `0x00565360`, and `0x00565490`
- `source-3/project-documentation/by-class/NewOptionPane.md`
- `source-3/project-documentation/by-file/OptionPane.md`
- Coverage rows in `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, and `by-memory/-coverage-report.md`
- Generated output `source-3/project-documentation/auto-generated/NexusTK/ui/controls/ScrollVolumePane.cpp`

Fresh PE scan:

- Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- Image base: `0x00400000`
- Relevant sections: `.text 0x00401000-0x0060c600`, `.rdata 0x0060d000-0x0066c200`, `.data 0x0066d000-0x0069ce24`, `.rsrc 0x0069d000-0x006b2e00`

## Boundary and split findings

The class implementation island is correctly split at 16-byte-aligned bodies with `0xcc` padding between most functions. The aggregate range `0x00564710-0x005654ec` is a container and should not emit aggregate C++.

Exact child boundaries confirmed:

| UID | Range | Recommended source role |
| --- | --- | --- |
| `0001H2` | `0x00564710-0x005654ec` | Aggregate/container only, no C++ |
| constructor child | `0x00564710-0x005647b1` | `ScrollVolumePane::ScrollVolumePane(unsigned char volumeType)` |
| `00031M` | `0x005647c0-0x005647e7` | private low-state word setter, best name `SetLowStateWord` / `SetTrackStateWord` |
| `00031N` | `0x005647f0-0x00564814` | private state-byte setter, best name `SetStateByte` |
| SetRange child | `0x00564820-0x0056487b` | `SetRange(int range)` |
| SetValue child | `0x00564880-0x005648a7` | `SetValue(int value)` |
| Enable child | `0x005648b0-0x005648ca` | `Enable()` |
| Disable child | `0x005648d0-0x005648ea` | `Disable()` |
| `00031O` | `0x005648f0-0x0056490a` | private `CanAdjust() const` predicate |
| OnMouseEvent child | `0x00564910-0x00564af1` | primary mouse handler |
| IsScrollable child | `0x00564b00-0x00564b05` | returns false |
| OnLoseFocus child | `0x00564b10-0x00564b43` | commits/cancels active interaction |
| OnPaint child | `0x00564b50-0x00564e21` | draws horizontal slider parts |
| `0001H3` | `0x00564e30-0x00565006` | `HitTestPart(int x, int y)` |
| GetPartRect child | `0x00565010-0x0056516b` | `GetPartRect(ScrollVolumePart part, RectBounds *rect)` |
| `0002LB` | `0x00565170-0x005651e0` | `SetHighlightPart(ScrollVolumePart part)` |
| `0002LC` | `0x005651e0-0x005652a0` | `BeginInteraction(ScrollVolumePart part, int mouseY, int mouseX)` |
| `0001H4` | `0x005652a0-0x00565360` | `CommitInteraction()` |
| `0001H5` | `0x00565360-0x00565488` | `NotifyValueChange(int mouseY, int mouseX)` |
| `0002LD` | `0x00565490-0x005654ec` | `ResetInteractionState()` |

Padding facts:

- `0x005647b1-0x005647c0`: `0x0f` bytes `0xcc`
- `0x005647e7-0x005647f0`: `0x09` bytes `0xcc`
- `0x00564814-0x00564820`: `0x0c` bytes `0xcc`
- `0x0056487b-0x00564880`: `0x05` bytes `0xcc`
- `0x005648a7-0x005648b0`: `0x09` bytes `0xcc`
- `0x005648ca-0x005648d0`: `0x06` bytes `0xcc`
- `0x005648ea-0x005648f0`: `0x06` bytes `0xcc`
- `0x0056490a-0x00564910`: `0x06` bytes `0xcc`
- `0x00564af1-0x00564b00`: `0x0f` bytes `0xcc`
- `0x00564b05-0x00564b10`: `0x0b` bytes `0xcc`
- `0x00564b43-0x00564b50`: `0x0d` bytes `0xcc`
- `0x00564e21-0x00564e30`: `0x0f` bytes `0xcc`
- `0x00565006-0x00565010`: `0x0a` bytes `0xcc`
- `0x0056516b-0x00565170`: `0x05` bytes `0xcc`
- `0x00565488-0x00565490`: `0x08` bytes `0xcc`

The successor bytes at `0x005654ec-0x005654f7` are outside `ScrollVolumePane`: `81 e9 a0 00 00 00 e9 19 00 00 00`. This is a `ScrollablePane` destructor adjustor thunk and should stay excluded from this class aggregate and class declaration body.

## Caller and route evidence

Direct rel32 call evidence from the PE scan:

- `ScrollVolumePane` constructor `0x00564710` is called from `0x00540097` and `0x005400c6`, both in the `NewOptionPane` construction/setup island.
- `SetRange` `0x00564820` is called from `0x005403c7` and `0x005403de`.
- `SetValue` `0x00564880` is called from `0x00540416` and `0x00540463`.
- `Enable` `0x005648b0` is called from `0x00541aa7` and `0x00541af3`.
- `Disable` `0x005648d0` is called from `0x00541ac4` and `0x00541b0f`.
- `HitTestPart` `0x00564e30` is called from `0x005649f1` and `0x0056530f`.
- `GetPartRect` `0x00565010` is called from `0x00564987`, `0x00564a22`, `0x00564a3a`, `0x00564a59`, `0x00564d98`, `0x0056519c`, `0x005651b8`, `0x00565211`, `0x00565229`, `0x00565248`, `0x0056533a`, `0x00565385`, and `0x005654c6`.
- `CommitInteraction` `0x005652a0` is called from `0x00564a83`, `0x00564b28`, and `0x00565272`.
- `NotifyValueChange` `0x00565360` is called from `0x005652fb` and `0x00565324`.
- `NewOptionPane::OnVolumeChanged`-style callback `0x00540490` is called from `0x00565470`.
- Timer helpers: `0x005975e0` is referenced from `0x00564a99` and `0x00565288`; `0x00597600` is referenced from `0x005654a9`.
- Cursor/source-coordinate helpers: `0x004a9090` is referenced from `0x00564ba6`, `0x00564c9c`, `0x00564e5a`, `0x00565023`, `0x005652bd`, `0x00565394`, and `0x005653cc`; `0x005447c0` is referenced from `0x00564bb1`, `0x00564ca7`, `0x00564e65`, `0x0056502e`, `0x005652c8`, `0x0056539f`, and `0x005653d7`.

Absolute VA evidence:

- Vtable slots point to `0x00564910`, `0x00564b00`, `0x00564b10`, and `0x00564b50`.
- Vtable bases `0x006240b4`, `0x00624100`, and `0x00624130` are stored only by the constructor at `0x00564763`, `0x0056476d`, and `0x00564777`.
- Resource string `0x00624168` is referenced at `0x00564ded`.
- Successor thunk `0x005654ec` is referenced in a vtable slot outside the `ScrollVolumePane` child body set, consistent with inherited/adjustor destructor support rather than a source-authored `ScrollVolumePane` destructor body.

Raw helper route evidence:

- No direct rel32 call, absolute VA dword, or RVA dword route was found for raw helper starts `0x005647c0`, `0x005647f0`, `0x005648f0`, `0x00565170`, `0x005651e0`, or `0x00565490`. This supports retaining exact child docs for these source-shaped helpers while documenting the route as internal/vtable-adjacent or compiler-layout-retained rather than externally called API.

## Ownership and source placement

Keep class owner/emitter as `0000NK` (`by-file/ScrollVolumePane.md`). The owner/source route is:

- Source file: `NexusTK/ui/controls/ScrollVolumePane.cpp` or equivalent under the current file doc.
- Class owner: `ScrollVolumePane`.
- Runtime owner/caller: `NewOptionPane` creates and configures the two volume sliders, then receives value-change callbacks.
- Generated-output owner pollution: stale `TextEditPane::*` signatures on hit-test/commit/notify helper pages are not source ownership evidence.

Rejected ownership alternatives:

- Not `TextEditPane`: the stale generated signatures on `0x00564e30`, `0x005652a0`, and earlier emitted support are parent-map pollution. The direct helper calls are inside the `ScrollVolumePane` island and the callback path reaches `NewOptionPane`; `TextEditPane` does not own the class state, vtable bases, resource string, or slider geometry.
- Not `ScrollablePane`: the excluded `0x005654ec` tail belongs to `ScrollablePane` destructor glue, but the `0x00564710-0x005654ec` bodies own a distinct class layout, constructor vtable stores, resource, painting, mouse handling, and callback logic.
- Not `OptionPane`/`NewOptionPane`: `NewOptionPane` constructs/configures the controls and receives callbacks, but the geometry, hit-test, paint, interaction, and notify source bodies are in `ScrollVolumePane`.
- Not a generic scrollbar class: the resource string, callback to `NewOptionPane`, field `m_volumeType`, and volume-specific callback semantics make this a volume slider class, not a reusable scrollbar/widget with unrelated owner.

## Source-quality name recommendations

Class and file:

- Class: `ScrollVolumePane`
- Source file doc: keep `by-file/ScrollVolumePane.md`; update role from vertical slider to horizontal volume slider.
- Constructor: `ScrollVolumePane::ScrollVolumePane(unsigned char volumeType)`
- Callback receiver in `NewOptionPane`: `NewOptionPane::OnVolumeChanged(int volumeType, int value)` or `NewOptionPane::OnVolumeSliderChanged(...)`. Existing emitted child uses `NewOptionPane::OnVolumeChanged`; keep that unless the `NewOptionPane` page standardizes a different name.

Part ids:

Use source-facing enum names rather than magic values:

```cpp
enum ScrollVolumePart {
    kScrollVolumePartLeading = 0,
    kScrollVolumePartPageBeforeThumb = 1,
    kScrollVolumePartThumb = 2,
    kScrollVolumePartPageAfterThumb = 3,
    kScrollVolumePartTrailing = 4,
    kScrollVolumePartNone = -1
};
```

Confidence notes:

- `Leading` and `Trailing` are safer than `LeftButton`/`RightButton` because the resource pieces behave as slider end segments, not necessarily clickable arrow buttons.
- `PageBeforeThumb` / `PageAfterThumb` match the hit-test geometry and `NotifyValueChange` page/page-to-value behavior.
- `Thumb` for part `2` is high confidence.
- `None = -1` is high confidence from sentinel return/storage behavior.

Constants:

- `kScrollVolumeThumbSpan = 38` for the fixed thumb-size metric used by hit-test/get-rect/value conversion.
- The class should avoid a source-level vertical constant name. The control is horizontal; the old vertical wording should be removed.

Fields:

| Offset | Recommended name | Confidence | Evidence |
| --- | --- | --- | --- |
| `+0x44` | inherited/client bounds rectangle | high | passed to invalidation/rect helpers throughout island |
| `+0xa4` | timer/update-handler view | high | vtable/interface view used with timer schedule/cancel helpers |
| `+0xf8` | `m_lowStateWord` or `m_trackStateWord` | medium | raw word setter and initialization; behavior not fully named |
| `+0xfa` | `m_stateByte` | medium | raw byte setter and initialization; final semantic name unknown |
| `+0xfb` | `m_thumbDragActive` / `m_thumbDragOverrideActive` | medium-high | read by paint, hit-test, and get-rect to force cursor-derived thumb placement; no local writer found |
| `+0xfc` | `m_volumeType` | high | forwarded to `NewOptionPane` callback at `0x00565470` |
| `+0xfe` | `m_value` | high | value field used by `SetValue`, `NotifyValueChange`, callback, and paint math |
| `+0x100` | `m_range` | high | range divisor/clamp; `CanAdjust` predicate; `SetRange` |
| `+0x102` | `m_enabled` | high | enable/disable and `CanAdjust` predicate |
| `+0x103` | `m_highlightPart` | high | hover/highlight rect invalidation |
| `+0x104` | `m_activePart` | high | mouse-down/drag active part and commit state |
| `+0x108/+0x10c` | `m_thumbDragOffset` | medium-high | pair of drag offset components; `+0x10c` is the horizontal/track component used by notify/value math |

Coordinate naming caveat:

- Current generated `NotifyValueChange` uses `m_thumbDragOffset.x` for the field at `+0x10c`. The layout doc also describes `+0x108` and `+0x10c` as a pair with the horizontal/left component at `+0x10c`. To avoid overclaiming the original `Point` member order, class/support docs should state that `+0x10c` is the horizontal/track component and should not force a final `Point::x`/`Point::y` source field name unless the shared `Point` layout doc is reconciled.

Helper names:

| Address | Recommended name | Confidence |
| --- | --- | --- |
| `0x005647c0` | `SetLowStateWord(unsigned short state)`; alternate `SetTrackStateWord` | medium |
| `0x005647f0` | `SetStateByte(unsigned char state)` | medium |
| `0x005648f0` | `CanAdjust() const` | high |
| `0x00564e30` | `HitTestPart(int mouseX, int mouseY)` | high |
| `0x00565010` | `GetPartRect(ScrollVolumePart part, RectBounds *rect) const` | high |
| `0x00565170` | `SetHighlightPart(ScrollVolumePart part)` | high |
| `0x005651e0` | `BeginInteraction(ScrollVolumePart part, int mouseY, int mouseX)` | high |
| `0x005652a0` | `CommitInteraction()` | high |
| `0x00565360` | `NotifyValueChange(int mouseY, int mouseX)` | high |
| `0x00565490` | `ResetInteractionState()` | high |

External helper names:

- `0x004a9090`: `EventMan::GetCursorPosition(Point *)` or equivalent. High confidence by repeated cursor-position use across paint, hit-test, commit, and notify.
- `0x005447c0`: `Pane::GetScreenOffset(Point *)` / `Pane::GetScreenOrigin(Point *)`. High confidence by screen-to-local conversion call pattern and sentinel `(-1000, -1000)` handling. Prefer `GetScreenOffset` if source tree uses "offset"; prefer `GetScreenOrigin` if paired docs use "origin".
- `0x004b7c50`: rectangle initializer/set-bounds helper. Recommended source-facing name `SetRect` or `InitRectBounds`.
- `0x004b7e80`: point-in-rectangle helper. Recommended source-facing name `PointInRect`.
- `0x005975e0`: schedule/update timer helper for pane/timer handler.
- `0x00597600`: remove pending timer/update helper.

## Behavior corrections to incorporate

Horizontal slider:

- The class is a horizontal volume slider. Replace class/file wording that says "vertical volume slider."
- The hit-test and get-rect helpers partition horizontal regions into leading end, before-thumb/page-left, thumb, after-thumb/page-right, and trailing end.
- `NotifyValueChange` maps horizontal mouse/local position to a value using range and track geometry, clamps it, updates `m_value`, invalidates affected rectangles, and routes the changed value and volume type to `NewOptionPane`.

Interaction flow:

- `OnMouseEvent` should be described as using `CanAdjust`, `HitTestPart`, `SetHighlightPart`, `BeginInteraction`, `CommitInteraction`, and `ResetInteractionState`.
- `BeginInteraction` stores active part state, schedules timer/update behavior, handles thumb drag offset state, and may immediately notify for page/end regions.
- `CommitInteraction` rechecks the current cursor-local part. If the active part was the thumb, it notifies directly from the current cursor. If the active part was a non-thumb page/end region, it notifies only when the current hit-test part still matches the active part. It clears highlight/active state afterward through the child helpers.
- `OnLoseFocus` commits/cancels active interaction and clears transient state.
- `ResetInteractionState` removes pending timers and invalidates the current highlighted/active rectangles before setting transient part fields back to `None`.

Notify route:

- Keep the child-level `NotifyValueChange(int mouseY, int mouseX)` C++ route. It is valid and should stay under `0x00565360-0x00565488`.
- It calls the parent callback path, currently best named `NewOptionPane::OnVolumeChanged(m_volumeType, m_value)`.
- This route supports `m_volumeType` as the source-facing field name for `+0xfc`.

Generated output caveat:

- Generated file `auto-generated/NexusTK/ui/controls/ScrollVolumePane.cpp` currently emits bodies for `NotifyValueChange`, `SetHighlightPart`, `BeginInteraction`, and `ResetInteractionState`, and empty markers for the class, aggregate, hit-test, commit, and raw helpers.
- The old `TextEditPane::*` signature pollution should be replaced with a resolved caveat: it is stale generated owner pollution, not a live uncertainty over source ownership.

## C++ recommendation for the class page

Emit declaration-level C++ in `by-class/ScrollVolumePane.md`; keep method bodies on child by-memory pages. The class C++ should be a plausible mid-2000s source declaration, not decompiler-shaped output. Recommended block:

```cpp
struct Point;
struct RectBounds;
struct PaneMouseEvent;

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
    static const int kScrollVolumeThumbSpan = 38;

    explicit ScrollVolumePane(unsigned char volumeType);

    void SetRange(int range);
    void SetValue(int value);
    void Enable();
    void Disable();

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent *event);
    virtual bool IsScrollable() const;
    virtual void OnLoseFocus();
    virtual void OnPaint();

private:
    void SetLowStateWord(unsigned short state);
    void SetStateByte(unsigned char state);
    bool CanAdjust() const;
    ScrollVolumePart HitTestPart(int mouseX, int mouseY) const;
    void GetPartRect(ScrollVolumePart part, RectBounds *rect) const;
    void SetHighlightPart(ScrollVolumePart part);
    void BeginInteraction(ScrollVolumePart part, int mouseY, int mouseX);
    void CommitInteraction();
    void NotifyValueChange(int mouseY, int mouseX);
    void ResetInteractionState();

    // Local fields begin after the inherited Pane/handler views.
    unsigned short m_lowStateWord;          // +0xf8
    unsigned char m_stateByte;              // +0xfa
    bool m_thumbDragActive;                 // +0xfb
    unsigned char m_volumeType;             // +0xfc
    unsigned short m_value;                 // +0xfe
    unsigned short m_range;                 // +0x100
    bool m_enabled;                         // +0x102
    signed char m_highlightPart;            // +0x103
    signed char m_activePart;               // +0x104
    Point m_thumbDragOffset;                // +0x108/+0x10c

    [[CHILDREN]]
};
```

Notes for implementer:

- If validator/autogen conventions reject `[[CHILDREN]]` inside a declaration with fields, keep the same declaration and place `[[CHILDREN]]` at the class page's established marker position rather than changing the source facts.
- Do not add an explicit source-authored destructor body to the class. The only nearby destructor-like bytes are generated/inherited adjustor support outside this class range.
- If the project standard avoids comments in C++ blocks, move the offset comments into prose while keeping the declaration names.

## Child C++ readiness

Class-level acceptance should not require every child to emit C++ immediately, but the class pass resolves enough naming to queue these child updates.

Ready now:

- `0001H3` `HitTestPart(int mouseX, int mouseY) const`: first-draft-ready. See prior B014 hit-test report. It should emit source C++ under the child, not the class page.
- `0001H4` `CommitInteraction()`: first-draft-ready after class-level name resolution. The body is one complete source-authored helper with direct local calls and no split/merge issue. Recommended score `87/90`.
- `00031O` `CanAdjust() const`: first-draft-ready despite raw start, with a simple predicate:

```cpp
bool ScrollVolumePane::CanAdjust() const
{
    return m_enabled && m_range > 0;
}
```

Likely ready if supervisor accepts descriptive names:

```cpp
void ScrollVolumePane::SetLowStateWord(unsigned short state)
{
    if (m_lowStateWord == state)
        return;

    m_lowStateWord = state;
    InvalidateRect(&m_bounds);
}

void ScrollVolumePane::SetStateByte(unsigned char state)
{
    if (m_stateByte == state)
        return;

    m_stateByte = state;
    InvalidateRect(&m_bounds);
}
```

These two helpers should remain capped lower than `CanAdjust` because final source names for the two state fields are not known.

Already emitting and should stay child-owned:

- `0001H5` `NotifyValueChange(int mouseY, int mouseX)`, score already `87/89`.
- `0002LB` `SetHighlightPart`.
- `0002LC` `BeginInteraction`.
- `0002LD` `ResetInteractionState`.

No-code/generated support:

- `0001H2` aggregate remains no-code container.
- `0003CP` vtable data remains no-code generated-binary support.
- `0003CR` resource string remains no-code resource support.
- Excluded `0x005654ec` destructor adjustor remains outside this class page and should not be pulled into `ScrollVolumePane`.

## Recommended target doc changes

For `by-class/ScrollVolumePane.md`:

1. Set metadata to:
   - `COMPLETION:89`
   - `CONFIDENCE:89`
   - keep `RECONSTRUCTABLE:TRUE`
   - keep `CANONICAL_OWNER:0000NK`
   - keep `EMITTER_UIDS:0000NK`
2. Replace "vertical volume slider" wording with "horizontal volume slider."
3. Add/replace formal C++ with the declaration block above.
4. Add a source-quality section stating:
   - stale generated `TextEditPane::*` signatures are rejected as generated-output pollution;
   - source owner is `ScrollVolumePane`;
   - runtime setup/callback route is `NewOptionPane`;
   - destructor-like `0x005654ec` tail is excluded inherited/generated support.
5. Add enum/part map:
   - `0 = leading end`
   - `1 = page before thumb`
   - `2 = thumb`
   - `3 = page after thumb`
   - `4 = trailing end`
   - `-1 = none`
6. Add fixed metric `kScrollVolumeThumbSpan = 38`.
7. Add field map from this report, including the confidence caveat for `+0xf8`, `+0xfa`, `+0xfb`, and `+0x108/+0x10c`.
8. Update method inventory names/signatures to match the recommendations above.
9. Add no-code/defer policy:
   - class declaration emits;
   - aggregate emits no code;
   - method bodies remain on exact children;
   - vtable/resource support remains no-code.

## Recommended support-doc changes

For `by-file/ScrollVolumePane.md`:

- Raise from `88/85` to `89/88` after class update.
- Replace vertical-slider description with horizontal volume-slider description.
- Replace stale caveats about `TextEditPane::*` signatures with resolved rejection language.
- Add source placement: the file owns `ScrollVolumePane` class declaration and exact child method bodies; `NewOptionPane` owns construction/use and callback handling.
- Add enum/part map and thumb span reference, or link to the class page's definitions.
- Add that `0x005654ec` belongs to `ScrollablePane` destructor glue outside this class island.

For `by-memory/0x00564710-0x005654ec.ScrollVolumePane.md`:

- Raise from `86/89` to `87/90`.
- Keep C++ blank with no-code aggregate proof.
- Update role from raw/mixed unresolved container to exact class implementation container with child bodies.
- Add direct boundary/padding facts and rejected successor thunk ownership.
- Add child row corrections: `0001H3` hit-test first-draft-ready, `0001H4` commit first-draft-ready, `00031O` can-adjust first-draft-ready, raw setters descriptive-name-ready if accepted.

For `by-type/by-struct/ScrollVolumePaneLayout.md`:

- Raise from `87/88` to `88/89` if the field names and part enum are inserted.
- Keep `+0xf8` and `+0xfa` as descriptive medium-confidence names.
- Clarify `+0xfb` as thumb-drag override/active flag, read by paint/hit-test/rect helpers; no local writer found.
- Clarify `+0x10c` as the horizontal/track component of `m_thumbDragOffset`.
- Use `m_value` consistently for `+0xfe` so it matches emitted `NotifyValueChange`.

For `by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md`:

- Apply the accepted content from the prior B014 `0001H3` report:
  - raise to `88/90`;
  - correct stale generated signature from `TextEditPane::TrackScrollButtonF` to `ScrollVolumePane::HitTestPart(int mouseX, int mouseY) const`;
  - replace vertical/top-bottom semantics with horizontal part-id map;
  - add first-draft C++ under the child.

For `by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md`:

- Raise from `85/89` to `87/90`.
- Add first-draft C++ under the child if supervisor accepts this class-level name pass.
- Document that it commits current active part, rechecks hit-test for non-thumb parts, notifies through `NotifyValueChange`, then clears transient state/highlight.

For raw helper children:

- `0x005647c0`: raise to `86/89` only if adding descriptive-name C++; otherwise keep current score and replace stale 95/95 gate text with current 85/85 policy plus unresolved-name cap.
- `0x005647f0`: same as above.
- `0x005648f0`: raise to `87/90`; add `CanAdjust() const` first-draft C++.

For `by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md`:

- No score change needed (`87/89` current). Add source-quality cross-link to class enum/field names and ensure coverage row is updated from stale blank-C++ wording.

For `by-type/by-vtable/ScrollVolumePaneVtables.md` and `by-memory/0x006240b4-0x0062415c.ScrollVolumePaneVtableData.md`:

- No score change required.
- Add one sentence that class declaration C++ now belongs on `by-class/ScrollVolumePane.md`, while vtable data remains generated-binary/no-code support.

For `by-memory/0x00624168-0x00624174.ScrollVolumePaneResourceString.md`:

- No score change required.
- Keep as resource/no-code support. Add that `SCRBUTT2.EPF` supports the horizontal volume slider paint path if not already present.

For `by-class/NewOptionPane.md` and `by-file/OptionPane.md`:

- Low-risk optional update: mention that `NewOptionPane` constructs/configures two `ScrollVolumePane` instances and receives `OnVolumeChanged(volumeType, value)` callbacks; slider geometry and interaction remain owned by `ScrollVolumePane`.

## Exact implementation checklist for callback

1. Edit `by-class/ScrollVolumePane.md`.
   - Metadata `89/89`.
   - Replace vertical-slider language.
   - Insert declaration C++ block.
   - Insert part enum, thumb span, field map, helper names, and stale `TextEditPane` rejection.
   - Preserve owner/emitter `0000NK`.
2. Edit `by-file/ScrollVolumePane.md`.
   - Metadata `89/88`.
   - Replace vertical role with horizontal volume slider.
   - Replace stale generated-signature caveats with resolved pollution caveat.
   - Add source placement and child C++ policy.
3. Edit `by-memory/0x00564710-0x005654ec.ScrollVolumePane.md`.
   - Metadata `87/90`.
   - Keep no aggregate C++.
   - Add exact child inventory, padding, route evidence, and no-code aggregate proof.
4. Edit `by-type/by-struct/ScrollVolumePaneLayout.md`.
   - Metadata `88/89`.
   - Update fields and enum names; clarify `+0xfb` and `+0x10c`.
5. Edit child pages if implementation callback includes them:
   - `0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md`: apply prior report, score `88/90`, first-draft C++.
   - `0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md`: score `87/90`, first-draft C++.
   - `0x005648f0-0x0056490a.ScrollVolumePaneCanAdjust.md` or current filename: score `87/90`, first-draft C++.
   - `0x005647c0-0x005647e7.*.md` and `0x005647f0-0x00564814.*.md`: optional first-draft C++ if descriptive names accepted; score `86/89`.
6. Update vtable/resource support docs only with concise no-code/support route notes if touched.
7. Do not edit `by-memory/-coverage-report.md`; apply replacement rows only through supervisor-owned coverage process.
8. Run validators listed below.

## Score and metadata recommendations

| Path | Current | Recommended | Reason |
| --- | --- | --- | --- |
| `by-class/ScrollVolumePane.md` | `87/85` | `89/89` | class declaration ready; owner/source/part names resolved; stale `TextEditPane` rejected |
| `by-file/ScrollVolumePane.md` | `88/85` | `89/88` | source-file role clearer after horizontal/class declaration pass |
| `by-memory/0x00564710-0x005654ec.ScrollVolumePane.md` | `86/89` | `87/90` | aggregate no-code proof and child split stronger |
| `by-type/by-struct/ScrollVolumePaneLayout.md` | `87/88` | `88/89` | enum/field names and horizontal/drag-offset caveats resolved |
| `by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md` | `85/86` | `88/90` | previous B014 hit-test report resolved owner/signature/geometry and C++ readiness |
| `by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md` | `85/89` | `87/90` | source-authored complete helper; names now resolved enough |
| `by-memory/0x005648f0-0x0056490a.*` | `85/88` | `87/90` | simple source predicate, high-confidence `CanAdjust` |
| `by-memory/0x005647c0-0x005647e7.*` | `85/88` | `86/89` if C++ accepted | body ready, final name/field semantic medium confidence |
| `by-memory/0x005647f0-0x00564814.*` | `85/88` | `86/89` if C++ accepted | body ready, final name/field semantic medium confidence |
| `by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md` | `87/89` | no change | already emits; coverage/support wording stale only |

## Exact pending coverage text

Do not edit coverage files during the report pass. Suggested replacement rows for supervisor-owned application:

`by-class/-coverage-report.md`:

```text
- [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md) : reconstructable : 89% : very strong : B014 2026-06-19 class source-quality pass raises to `89/89`, keeps owner/emitter [UID:0000NK], emits declaration-level `Pane`-derived horizontal volume slider C++ with `ScrollVolumePart` enum, `kScrollVolumeThumbSpan = 38`, known field names, helper signatures, and `[[CHILDREN]]`; stale generated `TextEditPane::*` signatures are rejected as owner pollution, child bodies remain on exact by-memory pages, aggregate/vtable/resource support remains no-code.
```

`by-file/-coverage-report.md`:

```text
- [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md) : reconstructable : 89% : very strong : B014 2026-06-19 source-file pass updates role to horizontal volume slider file, keeps class owner [UID:0000CO], resolves `TextEditPane` generated-signature pollution, routes construction/use through `NewOptionPane`, and documents class declaration C++ plus exact child-body ownership; vtable/resource data remains generated/no-code support.
```

`by-memory/-coverage-report.md` row for aggregate:

```text
- [UID:0001H2][ScrollVolumePane](by-memory/0x00564710-0x005654ec.ScrollVolumePane.md) : reconstructable : 87% : very strong : B014 2026-06-19 aggregate/source-routing pass keeps no aggregate C++, confirms exact child split/padding through `0x005654ec`, excludes successor `ScrollablePane` destructor adjustor at `0x005654ec`, resolves horizontal part/field naming route, and points method C++ to child pages under class owner [UID:0000CO].
```

`by-memory/-coverage-report.md` row for hit-test helper:

```text
- [UID:0001H3][ScrollVolumePaneHitTestPart](by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md) : reconstructable : 88% : very strong : B014 2026-06-19 source-quality pass corrects stale generated `TextEditPane::TrackScrollButtonF` signature to `ScrollVolumePane::HitTestPart(int mouseX, int mouseY) const`, resolves horizontal part ids `0..4/-1`, cursor/screen-origin helpers, `kScrollVolumeThumbSpan = 38`, field names, and first-draft child C++ eligibility under [UID:0000CO].
```

`by-memory/-coverage-report.md` row for commit helper:

```text
- [UID:0001H4][ScrollVolumePaneCommitInteraction](by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md) : reconstructable : 87% : very strong : B014 2026-06-19 class source-quality pass resolves stale owner/signature pollution to `ScrollVolumePane::CommitInteraction()`, documents cursor-to-pane conversion, active-part recheck, thumb/direct notify behavior, highlight clearing, and first-draft child C++ readiness under [UID:0000CO].
```

`by-memory/-coverage-report.md` row for notify helper:

```text
- [UID:0001H5][ScrollVolumePaneNotifyValueChange](by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md) : reconstructable : 87% : very strong : B014 2026-06-19 support sync keeps first-draft child C++, rejects stale generated `TextEditPane` owner pollution, names route as `ScrollVolumePane::NotifyValueChange(int mouseY, int mouseX)`, confirms horizontal value mapping, `m_volumeType`, `m_value`, `m_range`, drag-offset component caveat, and callback to `NewOptionPane::OnVolumeChanged`.
```

`by-memory/-coverage-report.md` row for `0x005648f0` helper:

```text
- [UID:00031O][ScrollVolumePaneCanAdjust](by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjust.md) : reconstructable : 87% : very strong : B014 2026-06-19 class source-quality pass resolves raw helper as private `ScrollVolumePane::CanAdjust() const`, source-shaped predicate `m_enabled && m_range > 0`, no external route required, first-draft child C++ ready under [UID:0000CO].
```

If the two raw setter filenames remain unchanged, adjust the link labels to current filenames but use these row bodies:

```text
- [UID:00031M][ScrollVolumePaneLowStateWordSetter](by-memory/0x005647c0-0x005647e7.ScrollVolumePaneLowStateWordSetter.md) : reconstructable : 86% : very strong : B014 2026-06-19 class source-quality pass resolves raw source-shaped helper as private low-state word setter for `+0xf8`, invalidating the pane bounds on change; first-draft child C++ is acceptable if descriptive `SetLowStateWord`/`SetTrackStateWord` naming is accepted, with final semantic name still a confidence cap.
- [UID:00031N][ScrollVolumePaneStateByteSetter](by-memory/0x005647f0-0x00564814.ScrollVolumePaneStateByteSetter.md) : reconstructable : 86% : very strong : B014 2026-06-19 class source-quality pass resolves raw source-shaped helper as private state-byte setter for `+0xfa`, invalidating the pane bounds on change; first-draft child C++ is acceptable if descriptive `SetStateByte` naming is accepted, with final semantic name still a confidence cap.
```

## Validation commands expected after implementation

Run from `source-3/project-documentation` after edits:

> Executable block R001 was removed from this report and preserved verbatim in [0000CO-ScrollVolumePane-class-source-quality-removed.md](0000CO-ScrollVolumePane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the raw setter and `CanAdjust` child pages are edited, also run scoped validators for their exact current filenames:

> Executable block R002 was removed from this report and preserved verbatim in [0000CO-ScrollVolumePane-class-source-quality-removed.md](0000CO-ScrollVolumePane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result: all scoped validators pass; autogen updates `auto-generated/NexusTK/ui/controls/ScrollVolumePane.cpp` so the class marker no longer remains blank and stale `TextEditPane` signatures do not appear for these children.

## IDA rename/type/comment recommendations

High confidence:

- Rename `0x00564e30` to `ScrollVolumePane::HitTestPart`.
- Rename `0x00565010` to `ScrollVolumePane::GetPartRect`.
- Rename `0x00565170` to `ScrollVolumePane::SetHighlightPart`.
- Rename `0x005651e0` to `ScrollVolumePane::BeginInteraction`.
- Rename `0x005652a0` to `ScrollVolumePane::CommitInteraction`.
- Rename `0x00565360` to `ScrollVolumePane::NotifyValueChange`.
- Rename `0x00565490` to `ScrollVolumePane::ResetInteractionState`.
- Rename `0x005648f0` to `ScrollVolumePane::CanAdjust`.
- Name enum values for part ids `0..4/-1` as above.
- Comment `0x005654ec` as `ScrollablePane` adjustor/destructor support outside `ScrollVolumePane`.

Medium confidence:

- Rename `0x005647c0` to `ScrollVolumePane::SetLowStateWord` or `ScrollVolumePane::SetTrackStateWord`.
- Rename `0x005647f0` to `ScrollVolumePane::SetStateByte`.
- Name `+0xf8` as `m_lowStateWord` or `m_trackStateWord`.
- Name `+0xfa` as `m_stateByte`.
- Name `+0xfb` as `m_thumbDragActive` or `m_thumbDragOverrideActive`; add comment "read-only in this island; no local writer found."
- Name `+0x108/+0x10c` as `m_thumbDragOffset` with comment "`+0x10c` is horizontal/track component used by notify/value math."

External/helper comments:

- `0x004a9090`: cursor position helper.
- `0x005447c0`: pane screen origin/offset helper.
- `0x004b7c50`: rect initializer.
- `0x004b7e80`: point-in-rect predicate.
- `0x005975e0`: schedule timer/update helper.
- `0x00597600`: cancel/remove pending timer/update helper.

## Open questions after this pass

No passive blockers remain for the class page.

Still intentionally capped:

- Exact source names for the `+0xf8` word and `+0xfa` byte are not recoverable from the checked docs and PE route. Best implementation direction is descriptive private names with medium confidence.
- No writer for `+0xfb` was found in the class island or direct route scan; best inference is a thumb-drag override/active flag controlled by an external/base input path or a not-yet-modeled helper.
- The exact source declaration for the `+0x108/+0x10c` pair should avoid overclaiming `Point::x/y` ordering until the shared point/layout docs are reconciled.

These do not block class-level declaration C++ or the recommended score increase because the behavior, owner, child split, and helper route are now strong enough under the current 85/85 policy.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/0000CO-ScrollVolumePane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"0000CO"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000CO-ScrollVolumePane-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/0000CO-ScrollVolumePane-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000CO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
