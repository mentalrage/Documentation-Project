*** UID:0000DB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;

class SliderControlPane : public ControlPane
{
public:
    SliderControlPane(const RectBounds *bounds, short maximumValue);

    void SetCurrentValue(short value);

protected:
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnTimer();
    virtual void OnPaint();
    virtual unsigned char HitTestPart(int x, int y);

private:
    void GetPartRect(unsigned char part, RectBounds *rect) const;
    void BeginInteraction(unsigned char part, int localY, int localX);
    void EndInteraction();
    void ProcessScrollInput();
    void UpdateThumbFromDrag();
    void NotifyValueChanged();
    void ScrollLineBackward();
    void ScrollPageForward();
    void ScrollPageBackward();
    void ScrollLineForward();

    bool m_isHorizontal;
    DLPalette *m_palette;
    EPFTileContext m_frames[12];
    unsigned char m_activePart;
    Point m_dragOffset;
};

[[CHILDREN]]
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SliderControlPane

## Status

- Confidence: very strong for behavior, exact `0x2fc` layout, inheritance, vtable identity, constructor callers, setter callers, compiler-support disposition, and control-family placement; exact original private spellings and historical file split remain inferred.
- Current source file: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md). A possible historical `SliderControlPane.cpp` split is retained only as a lower-confidence alternative, not the active route.
- Core memory: [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md)
- Destructor/thunk memory: [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)

## Class Purpose

`SliderControlPane` is a value selector rendered from `SCRL001` frames. It determines horizontal or vertical orientation from bounds, tracks part hit-testing, draws arrows/track/thumb, handles mouse drag and capture, processes keyboard scroll commands, and runs a 30 ms auto-repeat timer.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SliderControlPane` | `0x00496630-0x004967b1` | Constructs the selector, initializes the frame array, chooses orientation from bounds, loads 12 frames, and clamps initial range/value to `[0, 30000]`. |
| `SetCurrentValue` | `0x004967c0-0x004967f7` | Clamps a requested value to `[0, this+0xfc]`, stores it at `this+0xfa`, and tail-calls the redraw/refresh virtual at slot `+0x20`. |
| `HitTestPart` | `0x00496800-0x00496ae7` | Returns arrow/track/thumb part id under a point. |
| `OnPaint` | `0x00496af0-0x004974a7` | Draws arrows, track, and proportional thumb for horizontal/vertical layouts. |
| `HandlePointerOrMouseEvent` | `0x004974b0-0x00497772` | Starts drag/capture, updates thumb on move, calls the scroll-processing helper, and releases capture on mouse-up. |
| `HandleKeyOrTextEvent` | `0x00497780-0x00497818` | Dispatches keyboard scroll commands through the four offset helpers and notifies the owner callback. |
| `OnTimer` | `0x00497850-0x00497886` | Auto-repeat scroll/update timer; skips when active part is idle and reschedules at 30 ms. |
| `ProcessScrollInput` | `0x00497c60-0x00497d6b` | Mouse/timer scroll helper that reads cursor position, hit-tests current part, updates offset helpers for part ids `13/14/16/17`, and notifies on value changes. |
| `UpdateThumbFromDrag` / `NotifyValueChanged` | `0x00497d80-0x0049803a` | Helper tail used by `ProcessScrollInput` for thumb-position math and final value-change notification. |
| Destructor/thunks | [UID:0002Y2][0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks](by-memory/0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks.md), [UID:0002Y3][0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor](by-memory/0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor.md) | Secondary adjustor thunks and scalar deleting destructor. |

## Evidence Notes

- 2026-06-04 live IDA MCP confirms modeled class functions at `0x00496630-0x004967b1`, `0x004967c0-0x004967f7`, `0x00496800-0x00496ae7`, `0x00496af0-0x004974a7`, `0x004974b0-0x00497772`, `0x00497780-0x00497818`, `0x00497850-0x00497886`, `0x00497c60-0x00497d6b`, `0x00497d80-0x00497fff`, `0x00498000-0x0049803a`, adjustor thunks `0x0049b003-0x0049b00e` and `0x0049b00e-0x0049b019`, and scalar deleting destructor `0x0049b5b0-0x0049b5eb`.
- 2026-06-07 A004 split-recheck created exact destructor-side children [UID:0002Y2][0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks](by-memory/0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks.md) and [UID:0002Y3][0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor](by-memory/0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor.md); the scalar deleting destructor is assigned here because the child is `86/88` and this direct class parent is `86/86`.
- Live IDA names the three vtable views as `??_7SliderControlPane@@6B@` at `0x00617f14`, `??_7SliderControlPane@@6B@_0` at `0x00617f7c`, and `??_7SliderControlPane@@6B@_1` at `0x00617fac`. Key slots are `0x00617f14 -> 0x0049b5b0`, `0x00617f58 -> 0x00496af0`, `0x00617f74 -> 0x00496800`, `0x00617f7c -> 0x0049b003`, `0x00617f80 -> 0x004974b0`, `0x00617f84 -> 0x00497780`, `0x00617fac -> 0x0049b00e`, and `0x00617fb0 -> 0x00497850`.
- Constructor evidence: IDA reports direct callers at `0x00528ffd` and `0x005290f1`. The body calls `ControlPane` construction at `0x004949e0`, installs the three vtable views at `0x00496672/0x0049667d/0x00496687`, initializes twelve `0x28`-byte frame records starting at `this+0x110`, selects vertical orientation through `this+0x108`, loads the frame table through `0x00543d70`/`0x004d02f0`, and clamps the limit field `this+0xfc` to `0x7530` (`30000`).
- Setter evidence: `0x004967c0` has direct callers at `0x00529659` and `0x00529677`, clamps against `this+0xfc`, writes `this+0xfa`, and tail-calls vtable slot `+0x20`.
- Input evidence: `HandleKeyOrTextEvent` maps key cases `0x80/0x81`, `0x82/0x83`, `0x93`, and `0x94` to the four scroll-offset helpers [UID:000223][0x0049b930-0x0049ba2b.SliderControlPaneScrollOffsetHelpers](by-memory/0x0049b930-0x0049ba2b.SliderControlPaneScrollOffsetHelpers.md); `ProcessScrollInput` uses the same helper quartet for hit/drag result cases `13`, `14`, `16`, and `17`.
- Mouse/timer evidence: `HandlePointerOrMouseEvent` calls the process helper at `0x004976e6` and timer `0x00497850` calls it at `0x0049786b`; `0x00497c60` also has a raw/unmodeled caller at `0x00497bff` from the non-padding gap before the modeled helper. The helper reads `g_pEventMan` at `0x0067a754`, calls cursor-position helper `0x004a9090`, and computes owner-relative cursor coordinates through `0x005447c0`.
- 2026-06-12 C001 boundary audit reconfirmed the slider tail and successor boundary: `lookup_funcs` reports `sub_497C60` size `0x10b`, `sub_497D80` size `0x27f`, and `sub_498000` size `0x3a`; `analyze_function 0x00498000` shows it is called only from `0x00497c60`; bytes `0x0049803a-0x00498040` are six `0xcc` padding bytes before [UID:00011F][0x00498040-0x00498599.PopupMenuControlPaneCore](by-memory/0x00498040-0x00498599.PopupMenuControlPaneCore.md).
- The exact raw-tail and helper children now account for the `0x00497890-0x00497c59` source-shaped island and modeled tails through `0x0049803a`. Remaining uncertainty is lexical rather than behavioral or structural.

## Exact Object Layout

`SliderControlPane` has exact complete-object size `0x2fc`:

| Offset | Size | Member / source meaning |
| --- | --- | --- |
| `+0x000` | `0x108` | inherited `ControlPane` base, including inherited `m_rangeCurrent` at `+0xfa` and `m_rangeEnd` at `+0xfc` |
| `+0x108` | `0x01` | `bool m_isHorizontal` |
| `+0x109` | `0x03` | natural alignment; no authored source member |
| `+0x10c` | `0x04` | `DLPalette *m_palette` |
| `+0x110` | `0x1e0` | `EPFTileContext m_frames[12]`, twelve exact `0x28` records |
| `+0x2f0` | `0x01` | `unsigned char m_activePart` |
| `+0x2f1` | `0x03` | natural alignment; no authored source member |
| `+0x2f4` | `0x08` | `Point m_dragOffset` |

- The wrapper's `0x2fc` immediate, constructor writes, frame initialization, `InitPointPair((Point *)(this+0x2f4), ...)`, and paired `+0x2f4/+0x2f8` reads independently converge on this layout.
- Human H intentionally contains no synthetic padding arrays. Natural alignment preserves both three-byte holes.
- The former class CPP declared `m_currentValue` and `m_maximumValue` at `+0xfa/+0xfc`. Current `ControlPane` type evidence proves those words are inherited range state, so the duplicate derived declarations were removed and are retained here only as a superseded historical assumption.

## Applied IDA UDT State

- Supervisor Gate 2B created exact `SliderControlPane` UDT size `0x2fc` in active session `5a570ede` without replacing or resizing any dependency type.
- Current analysis members are `_base ControlPane` `+0x000`; `bool m_isHorizontal` `+0x108`; analysis-only alignment bytes `+0x109[3]`; `DLPalette *m_palette` `+0x10c`; `EPFTileContext m_frames[12]` `+0x110`; byte `m_activePart` `+0x2f0`; analysis-only alignment bytes `+0x2f1[3]`; and `Point m_dragOffset` `+0x2f4`.
- The explicit alignment arrays exist only in the analysis UDT so IDA preserves exact offsets. They are not developer-source members and must not be copied into the human H declaration, where natural alignment remains the source-quality representation.
- Existing `ControlPane`, `Pane`, `EPFTileContext`, `Point`, `DLPalette`, `RectBounds`, `EventHandler`, and `TimerHandler` dependency identities and layouts were verified unchanged.
- Verified prestate backup is `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B003-UID0002Y3-20260728_1634.i64`, 143,189,293 bytes, SHA256 `748FA726F0A2D3358A211EEF4B53B7AFDDD725FFF9DDC0CF6A1C6D4128E47465`.
- Saved IDB is 143,189,451 bytes, SHA256 `CD454696D18CE05CC6C25A480BC48DB72E884A5B7CD87EDB3DE2A47428B6D29C`, last write `2026-07-28T16:31:29.1512841-04:00`; `idb_save` returned `ok:true` and health remained `status:ok`.

## Human Destructor And Compiler Support

- No modeled ordinary `SliderControlPane` destructor body exists, and the exact primary deleting wrapper performs only inherited `Pane` teardown plus deletion-mode dispatch.
- The class owns no member requiring a separate nontrivial cleanup body. The likely original source relied on the implicit derived destructor, which remains virtual through the polymorphic base relationship.
- Do not invent an explicit `~SliderControlPane()` declaration or body merely to explain compiler output. The implicit virtual relationship is sufficient to generate the three deleting entries.
- [UID:0002Y3][0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor](by-memory/0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor.md) and [UID:0002Y2][0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks](by-memory/0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks.md) are physical compiler support, `RECONSTRUCTABLE:FALSE`, and non-emitting. Their source cause is this class; they are not handwritten children.

## Source Placement And Generated Topology

- The destination-ready class declaration belongs in the H channel. CPP carries only `[[CHILDREN]]`, so authored method pages provide implementation bodies without duplicating the class.
- Dense Button/Choice control adjacency, the existing file root, shared resource behavior, and generated organization make `ButtonControlPane.h/.cpp` the strongest current source placement.
- A dedicated historical `SliderControlPane.cpp` remains possible but is unsupported by surviving symbols and does not justify changing the current route.
- Final generated acceptance requires exactly one Slider class declaration in `ButtonControlPane.h`, authored method bodies in `ButtonControlPane.cpp`, and no UID0002Y2 or UID0002Y3 marker/body.

## Negative Evidence And Historical Corrections

- No evidence supports duplicate derived range fields, a `RectBounds` at `+0x2f4`, an explicit authored destructor, or target-level C++ for compiler deleting glue.
- Raw IDA names and inferred private spellings are not original-symbol proof. Descriptive names are used because finalized human source must not retain `sub_` labels or raw offsets.
- The 2026-06-07 direct assignment of the deleting wrapper after an `85/85` gate and the 2026-06-30 minimal CPP class declaration were useful intermediate conclusions but are superseded by the exact inherited layout and current H-channel/no-code policy.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `92` | Exact constructor/setter/input/paint/timer/helper coverage, the `0x2fc` layout, inherited range correction, three vtable views, compiler-wrapper split, complete H declaration, CPP child route, source placement, and historical corrections are documented. |
| Confidence `94` | Independent constructor, wrapper-size, type, helper, vtable, RTTI, caller, and raw-tail evidence converges. Only exact original private spellings and the historical file split remain inferred. |

## Cross-References

- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:0002Y2][0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks](by-memory/0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks.md)
- [UID:0002Y3][0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor](by-memory/0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor.md)
- [UID:000223][0x0049b930-0x0049ba2b.SliderControlPaneScrollOffsetHelpers](by-memory/0x0049b930-0x0049ba2b.SliderControlPaneScrollOffsetHelpers.md)
- [UID:000252][0x00617a38-0x00618858.ControlPaneReadOnlyData](by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md)
- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)

## 2026-06-30 B010 Empty-Emitter Route Decision

Accepted implementation enters a minimal formal class declaration and `[[CHILDREN]]`. Current MCP proves four `0x3b` helpers at `0x0049b930`, `0x0049b970`, `0x0049b9b0`, and `0x0049b9f0`; those helpers update signed words at `+0xfa` and `+0xfc`, are called only by slider `OnKey`/`ProcessScrollInput`, and refresh through vtable slot `+0x20`. `m_currentValue`, `m_maximumValue`, and helper names are inferred source-facing names, not original-symbol proof, but they are now source-quality enough for first-draft route C++.

That 2026-06-30 score move from `86/86` to `88/89` and its minimal CPP declaration are retained as historical progression. The current accepted state is `92/94`, with the complete class in H, CPP `[[CHILDREN]]`, inherited range fields corrected, and compiler-only destructor support excluded from source emission. Owner, emitter, reconstructable state, and [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) source-file route remain unchanged.

## Changes

- 2026-06-04 live IDA recheck:
  - Before: completion/confidence were `82/76`, `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, and the page omitted the `0x004967c0` value setter plus the `0x00497c60` scroll-processing helper family.
  - Changed to: completion `86`, confidence `86`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000HY`.
  - Evidence: live IDA MCP confirmed the full function map, three `SliderControlPane` vtable views at `0x00617f14`, `0x00617f7c`, and `0x00617fac`, constructor xrefs at `0x00528ffd` and `0x005290f1`, setter xrefs at `0x00529659` and `0x00529677`, constructor vtable writes at `0x00496672/0x0049667d/0x00496687`, keyboard and mouse/timer links to the four scroll-offset helpers, and destructor thunks/scalar destructor at `0x0049b003-0x0049b019` and `0x0049b5b0-0x0049b5eb`.
- 2026-06-07 A004 Batch 046 split-recheck:
  - Before: destructor/thunk evidence pointed only to the broad [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md) aggregate.
  - Changed to: linked exact adjustor child [UID:0002Y2][0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks](by-memory/0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks.md) and exact scalar deleting destructor child [UID:0002Y3][0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor](by-memory/0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor.md).
  - Evidence: A004 read-only IDA MCP confirmed two `0x0b` adjustors, `sub_49B5B0` ending at `0x0049b5eb`, vtable cell `0x00617f14`, and padding `0x0049b5eb-0x0049b5f0`.
- 2026-06-12 C001 Goal 2 boundary correction:
  - Scores and parent unchanged.
  - Updated the core memory reference to the corrected `0x00494eb0-0x0049803a` ButtonChoice range and recorded live IDA evidence for the slider tail ending at `0x0049803a`, followed by padding and the `PopupMenuControlPane` successor at `0x00498040`.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `82`, confidence `76`.
- Evidence: the page documents behavior, likely ownership, core/destructor ranges, constructor, hit test, paint, mouse/key/timer methods, destructor thunks, and constructor xrefs; confidence is capped by final class-name/source split uncertainty.
