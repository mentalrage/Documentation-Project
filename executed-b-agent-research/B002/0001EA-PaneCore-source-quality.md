** TARGET-REPORT-UID:0001EA **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002 Report: [UID:0001EA] PaneCore Source-Quality Reanalysis

Assignment: `B002-goal2-pane-core-source-quality-0001EA-20260618`

Primary target: [UID:0001EA] `by-memory/0x00544460-0x00545086.PaneCore.md`

Report-only result: do not directly edit by-* docs, generated reports, generated source, IDA DB, or `by-memory/-coverage-report.md`.

## Recommendation Summary

[UID:0001EA] should be reclassified from a reconstructable/emitting class-method aggregate to a reviewed non-emitting `Pane` core split/index:

- Recommended metadata: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000A2`, `RECONSTRUCTABLE:FALSE`, `EMITTER_UIDS:` blank, formal C++ blank.
- Reason: the range is a physical cluster containing many separate `Pane` methods, one already-emitting exact child ([UID:0002V7] `Pane::SetMode`), an ordinary destructor, EventHandler default-body jump/adjusted-view material, compiler destructor adjustor thunks, and the scalar deleting destructor. Emitting C++ from the parent would either duplicate child emission or force compiler ABI wrappers into handwritten source.
- Correct source route for exact source-bearing children remains [UID:0000A2] `Pane`, emitted through [UID:0000MC] `NexusTK/ui/core/Pane.cpp`.
- [UID:0002V7] `Pane::SetMode(unsigned char)` should remain the existing exact emitting child with formal C++.
- Future exact children should carry first-draft method C++ individually. This parent should document the source map and split plan only.

## Evidence Checked

- Target [UID:0001EA] `PaneCore`: current metadata `84/86`, `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:0000A2], blank C++; current function table omits the ordinary destructor at `0x00544580` and still lists stale `0x004b8d20` as a nearby `Pane` destructor.
- [UID:0000A2] `Pane`: class purpose, field offsets, method-family table, vtable/deferred deletion notes, and stale construction/destruction row using `0x004b8d20`.
- [UID:0000MC] `Pane`: source root `NexusTK/ui/core/Pane.cpp`, proposed contents, dirty/motion ownership, support docs, and stale `0x004b8d20` destructor references.
- [UID:0001VH] `PaneLayout`: current offset evidence, constructor/destructor sizes, `+0xb4/+0xb5/+0xc4/+0xd8/+0xdc/+0xf0/+0xf4/+0xf5/+0xf6/+0xf8` field evidence, and current open names for `+0xb8/+0xc0/+0xf6`.
- [UID:0003JA] `PaneVtables` and [UID:0003CA] `PaneVtableData`: three `Pane` vtables at `0x006219e8`, `0x00621a34`, `0x00621a64`, store xrefs from constructor/destructor/scalar destructor, primary slot `+0x20` resolved to `0x00544800` `Pane::InvalidateRect`, and `PanelPane` successor boundary at `0x00621a6c`.
- [UID:0001YC] `PaneCoreVtableFamily`: already demonstrates the correct treatment for broad mixed aggregates as non-emitting indexes with exact child pages carrying reconstruction.
- [UID:0001EB] `PaneAdjustorThunks`: confirms `0x00544f2e-0x00544f44` are compiler-generated secondary/tertiary destructor adjustor thunks targeting `0x00544f50`.
- [UID:000160] `GrafPort` split index and [UID:00005V]/[UID:0000JR] `GrafPort`: `0x004b8d20-0x004b8dc3` is the `GrafPort` non-deleting cleanup/destructor body, not `Pane::~Pane`.
- [UID:00004N] `EventHandler`: `Pane` constructs/destructs the EventHandler secondary view at `+0xa0`; Pane thunks around `0x00544db0-0x00544e00` route to EventHandler pure-default false bodies.
- [UID:00000W]/[UID:0000HR] `BlackHole`: `QueuePaneForDeferredDeletion` uses pane virtual slots `+0x38` and `+0x40`, resolved as `Pane::RemoveFromLayer` and `Pane::UnregisterEventHandler`, before timer removal and deferred queueing.
- Current generated output check: `auto-generated/NexusTK/ui/core/Pane.cpp` contains only [UID:0002V7] `Pane::SetMode`. That matches exact-child emission and confirms the parent aggregate does not need C++ emission.
- Coverage row check: `by-memory/-coverage-report.md` still lists [UID:0001EA] as `class-method aggregate : reconstructable : 84% : strong`.

No live IDA MCP tool was exposed in this session. The report relies on existing IDA-backed pages and local generated/coverage checks.

## Heuristic / Inference Reanalysis And Validation

### Aggregate classification

Best inference: [UID:0001EA] is a non-emitting `Pane` method-cluster split/index, not a single source-emitting by-memory target.

Evidence:

- The range contains many independent source methods: constructor, ordinary destructor, deletion marker, `SetMode`, visibility methods, redraw/dirty helpers, motion/paint helpers, bounds helpers, layer attach/remove/order/event cleanup methods, EventHandler default bridge thunks, default tertiary slot, destructor adjustor thunks, and scalar deleting destructor.
- [UID:0002V7] is already an exact child with accepted first-draft C++. Parent emission would duplicate that child.
- [UID:0001EB] is already a non-emitting exact child for compiler adjustor thunks inside the same physical neighborhood.
- `0x00544f50-0x00545086` is a scalar deleting destructor wrapper generated from the ordinary destructor and delete flag. It should not be handwritten in formal C++.
- Current `auto-generated/NexusTK/ui/core/Pane.cpp` emits only the exact child `SetMode`, not the parent aggregate.
- Similar broad physical neighborhoods are already modeled as non-emitting indexes when exact child pages carry source ownership, for example [UID:000160] `GrafPort` and [UID:00013D] `EncoderCore`.

Rejected alternative: keep [UID:0001EA] reconstructable/emitting and populate selected methods in the parent. This would make the parent a partial source body while it also encloses exact child [UID:0002V7], compiler thunks, and scalar destructor output. That is an emitter-policy collision, not a source-quality improvement.

Impact: [UID:0001EA] should become `RECONSTRUCTABLE:FALSE` and `EMITTER_UIDS:` blank. Score can rise to `88/90` because the index map and split policy are now more accurate, while formal C++ remains blank.

### Ordinary destructor and stale `0x004b8d20`

Best inference: the ordinary `Pane` destructor/teardown body is `0x00544580-0x00544687`. The `0x004b8d20` address is `GrafPort` cleanup and should be removed from `Pane` method-family rows as the `Pane` destructor.

Evidence:

- [UID:0001VH] records `Pane` non-deleting destructor at `0x00544580`, size `0x107`.
- [UID:0003JA] records `lookup_funcs` for teardown/destructor helper `0x00544580-0x00544687` and store xrefs from `0x005445b4/0x005445ba/0x005445c0` to the three Pane vtables.
- [UID:0001YC] records `Pane` constructor, non-deleting destructor `0x00544580`, and scalar deleting destructor `0x00544f50` all write the three Pane vtables.
- [UID:000160] `GrafPort` identifies `0x004b8d20-0x004b8dc3` as the `GrafPort` non-deleting cleanup/destructor body. `Pane::~Pane` calls/chains to it after destroying Pane-owned regions and handler views.

Rejected alternative: keep `0x004b8d20` as the `Pane` non-deleting destructor. This contradicts vtable store triads, layout docs, and the `GrafPort` split/index evidence. It also creates a false impression that the `Pane` destructor sits outside the target range.

Impact: target function table, [UID:0000A2] method families, and [UID:0000MC] proposed contents should replace the stale destructor reference with `0x00544580-0x00544687`; `0x004b8d20-0x004b8dc3` should be mentioned only as the `GrafPort` base cleanup dependency.

### Source-facing method names and signatures

Best defensible source-facing method map for exact future children:

| Range | Recommended source-facing identity | Confidence and caveats |
| --- | --- | --- |
| `0x00544460-0x00544578` | `Pane::Pane(unsigned char mode)` or `Pane::Pane(PaneMode mode)` | Strong for constructor and mode argument stored at `+0xb5`; enum name remains provisional. |
| `0x00544580-0x00544687` | `virtual Pane::~Pane()` / non-deleting `Pane` destructor body | Strong; source destructor, not scalar wrapper. |
| `0x00544690-0x005446ad` | `void Pane::MarkForDeletion()` | Strong behavior: sets deferred-delete marker `+0xf4`, queues through BlackHole pane deletion path. |
| `0x005446b0-0x005446d4` | `void Pane::SetMode(unsigned char mode)` | Resolved and already emitted by [UID:0002V7]. |
| `0x005446e0-0x00544706` | `void Pane::GetCurrentMotionRegion(Region *outRegion) const` or `Region *Pane::GetCurrentMotionRegion(Region *outRegion) const` | Strong behavior, medium return type. It copies the selected current/pending motion region to caller storage; final return convention should be checked in exact child. |
| `0x00544730-0x00544749` | `virtual void Pane::Show()` | Strong: sets visible byte `+0xb4`, redraw suppressed when mode is `4`. |
| `0x00544750-0x0054479b` | `virtual void Pane::Hide()` | Strong: clears `+0xb4`, handles peer/auxiliary redraw transfer when `+0xb8` is present. |
| `0x005447a0-0x005447b3` | `virtual void Pane::Repaint()` | Medium-high: notifies attached layer; name already used consistently in target docs. |
| `0x00544800-0x005448ab` | `virtual void Pane::InvalidateRect(const Rect *rect)` | Strong: primary slot `+0x20`, called by `SetMode` with `this+0x44`; unions caller/local rectangle into dirty region. |
| `0x00544980-0x005449a5` | `void Pane::SubtractMotionFromDirtyRegion()` | Medium-high: behavior known, exact source name provisional. |
| `0x00544a20-0x00544a34` | `virtual bool/int Pane::OnCommand(...)` default handler | Medium: vtable slot and inherited use are clear, but argument and return spelling should be resolved on an exact child. Do not emit parent C++ for it. |
| `0x00544a40-0x00544ade` | `bool Pane::HasPendingMotion() const` | Medium-high: compares pending/current motion regions for layer traversal; final boolean spelling provisional. |
| `0x00544ae0-0x00544b46` | `void Pane::BeginMotionPaint(...)` | Medium-high: prepares active motion/clip state, origin offset, surface metadata, in-paint byte. Final parameters depend on exact child. |
| `0x00544b50-0x00544b7d` | `void Pane::EndMotionPaint()` | Medium-high: commits pending motion, clears pending, clears in-paint marker. |
| `0x00544b80-0x00544bc0` | `void Pane::GetScreenBounds(Rect *outRect) const` | Strong name/signature direction; converts local bounds through event-handler/screen position. |
| `0x00544bd0-0x00544c42` | `void Pane::SetBounds(const Rect *bounds)` | Strong name/signature direction; stores origin and passes local rectangle to sizing hook. |
| `0x00544c50-0x00544c66` | `bool Pane::IsAttachedToLayer() const` | Medium-high: reads cached `Layer*` at `+0xa8` and asks layer membership; exact source name may be `IsInLayer`/`HasLayer`. |
| `0x00544c70-0x00544ca4` | `virtual void Pane::AddToLayer(...)` | Strong name, medium parameter names; calls `Layer::AddChildAfter`. |
| `0x00544cb0-0x00544cd7` | `virtual void Pane::InsertInLayer(...)` | Strong name, medium parameter names; calls `Layer::AddChildBefore`. |
| `0x00544ce0-0x00544d2a` | `virtual void Pane::RemoveFromLayer()` | Strong: BlackHole slot `+0x38` resolves here. |
| `0x00544d30-0x00544d6f` | `virtual void Pane::SetPaneOrder(...)` / `RegisterEventHandler` side | Medium-high: passes `this+0xa0` to EventDispatcher ordering/registration helpers; exact user-facing name should be coordinated with EventDispatcher. |
| `0x00544d70-0x00544dae` | `virtual void Pane::UnregisterEventHandler()` | Strong: BlackHole slot `+0x40` resolves here. |
| `0x00544db0-0x00544e00` | EventHandler default bridge thunks from Pane adjusted view | Strong as ABI/bridge support; source belongs in Pane/EventHandler virtual declarations and EventHandler default bodies, not standalone handwritten Pane methods. |
| `0x00544e90-0x00544e95` | inherited tertiary handler/update default slot | Strong as inherited/default slot, medium final name. It is repeatedly described as base/default event-update slot; do not promote to feature method. |
| `0x00544f2e-0x00544f44` | compiler destructor adjustor thunks | Strong no-source/no-emitter; already [UID:0001EB]. |
| `0x00544f50-0x00545086` | `Pane` scalar deleting destructor wrapper | Strong compiler wrapper; generated by `virtual ~Pane()` plus delete flag. Formal C++ should stay blank. |

### Field and type reanalysis

Best field directions for `Pane`:

| Offset | Recommendation | Evidence and impact |
| --- | --- | --- |
| `+0xa0` | `EventHandler` secondary view | Constructor/destructor and EventHandler docs agree; derived input handlers subtract `0xa0`. |
| `+0xa4` | tertiary timer/event handler view | Short tertiary vtables carry destructor adjustor plus default/update slot; final base type name should coordinate with TimerHandler/EventHandler docs. |
| `+0xa8` | `Layer *m_layer` / `m_attachedLayer` | Strong: layer attach/remove/membership helpers read/write it. |
| `+0xac` | pane origin point | Strong: constructor initializes `(0,0)`; `SetBounds` stores top-left. |
| `+0xb4` | `bool m_visible` | Strong: `Show`/`Hide` write it. |
| `+0xb5` | `unsigned char m_mode` / `PaneMode m_mode` | Strong: constructor and `SetMode` write; `Show` checks mode `4`; final enum constant names provisional. |
| `+0xb8` | high-probability `Pane *m_peerPane` / `m_redrawPeerPane` | Evidence: constructor clears it; `Hide` transfers bounds/redraw responsibility when present. Rejected: `Layer*` because `+0xa8` is the layer; rejected: region pointer because regions are inline at `+0xc4/+0xdc`. Final name should remain descriptive until exact `Hide` child is audited. |
| `+0xc0` | `unsigned char m_auxiliaryState` tied to the `+0xb8` peer/redraw path | Evidence is currently only constructor zeroing and adjacency to `+0xb8`; no safe final role. Rejected: visibility/mode/delete because `+0xb4/+0xb5/+0xf4` own those roles. Impact: document as auxiliary peer/redraw state, not as a compiler-generated unresolved field. |
| `+0xc4` | `Region m_pendingMotionRegion` / `m_alternateMotionRegion` | Strong: constructed/destroyed as Region; motion helpers copy/compare/subtract it. |
| `+0xd8` | `bool m_inMotionPaint` / motion paint lock | Strong: `BeginMotionPaint` sets, `EndMotionPaint` clears. |
| `+0xdc` | `Region m_committedMotionRegion` / `m_clipMotionRegion` | Strong: constructed/destroyed as Region; begin/end paint copies it into active state. Exact name remains provisional because docs use both clip and committed-motion wording. |
| `+0xf0` | input/focus registration state dword | Strong: destructor tests against `1` before focus cleanup. |
| `+0xf4` | deferred-delete/dismissed marker | Strong: `MarkForDeletion` sets it and BlackHole/deferred deletion path consumes the lifecycle. |
| `+0xf5` | `bool m_hasPendingMotionRegion` / motion dirty selector flag | Strong behavior: `GetCurrentMotionRegion` and `HasPendingMotion` choose current versus pending region behavior from this byte. Prefer this over generic `m_flags`. |
| `+0xf6` | reserved/adjacent motion flag byte | Evidence: constructor clears it as part of a word store with `+0xf5`; no documented consumer. Rejected: visible/mode/delete/layer because those offsets are already proven. Keep as `m_reservedPaneFlag` or document as unresolved with no C++ use. |
| `+0xf8` | first derived-class field | Strong: `DialogPane`, `DialogSession`, and many derived panes start their storage here. |

### Generated owner pollution

The existing docs are directionally correct that generated `MapPane`, `BulletinSession`, `PaneChildRegistry`, `ParcelPane`, and feature-owner labels are caller-biased or stale for these base helpers.

Validated/rejected cases:

- `0x005446e0-0x00544b7d`: generated `MapPane` ownership is rejected; caller evidence in docs ties dirty/motion helpers to Layer recursion and Surface presentation.
- `0x00544690`: generated feature-owner labels are rejected; behavior is base `Pane::MarkForDeletion` plus BlackHole deferred queue.
- `0x00544c50`: generated `ParcelPane::HasParcelData` style ownership is rejected; the helper reads `Pane +0xa8` and asks the attached layer membership question.
- `0x00469180`: `PaneChildRegistry` owner is rejected; current BlackHole docs correctly route it to BlackHole deferred-deletion queue behavior, with Pane virtual detach calls as dependencies.
- Current `auto-generated/NexusTK/ui/core/Pane.cpp` containing only `Pane::SetMode` is not a source corruption by itself. It is evidence that the only currently safe formal C++ is exact-child emission. The coverage child row should drop any stale "zero-byte generated output" wording.

### Support-doc validation and contradictions

Validated:

- [UID:0001VH] layout and [UID:0003JA]/[UID:0003CA] vtable pages are the strongest current sources for offsets and vtable stores.
- [UID:0001YC] vtable family as non-emitting mixed-owner index remains correct.
- [UID:0001EB] adjustor thunk page remains correct and should stay non-emitting.
- [UID:00000W]/[UID:0000HR] BlackHole queue behavior remains correct for deferred deletion.

Contradicted/stale:

- [UID:0001EA] target function table omits `0x00544580-0x00544687` ordinary destructor.
- [UID:0001EA], [UID:0000A2], and [UID:0000MC] mention `0x004b8d20` as a `Pane` non-deleting destructor. This should be replaced with `0x00544580`; `0x004b8d20-0x004b8dc3` belongs to `GrafPort`.
- [UID:0000A2] "GrafPort state block" duplicates/confuses inherited GrafPort offsets with Pane-owned offsets. Keep leading GrafPort state referenced, but the Pane-owned additions should be the `+0xa0..+0xf7` offsets from [UID:0001VH].
- [UID:0001EA] says C++ is blank because of a stale `95/95` final-source gate. Under active Rule 20, the reason should be split/index and exact-child policy, not an obsolete score threshold.

Unresolved blockers after this pass:

- Exact original names for `+0xb8`, `+0xc0`, `+0xf6`, and some region/motion flags remain below final-source certainty. The report gives best descriptive directions and rejected alternatives; these do not block converting [UID:0001EA] to a non-emitting split/index.
- Exact signatures for `OnCommand`, current-motion copy return convention, `BeginMotionPaint` parameters, `AddToLayer`/`InsertInLayer` parameters, and `SetPaneOrder` argument names need exact-child decompilation before formal method-body C++.
- Live IDA MCP was not available in this session; supervisor can apply the listed validation commands or use the cited IDA-backed docs.

## First-Draft C++ Recommendation

Do not populate formal C++ in [UID:0001EA].

Exact target-specific no-code proof:

1. [UID:0001EA] is not one source-authored method. It covers a constructor, ordinary destructor, many virtual methods, non-virtual helpers, EventHandler adjusted-view bridge thunks, destructor adjustor thunks, and scalar deleting destructor output.
2. [UID:0002V7] already emits `Pane::SetMode(unsigned char)` as an exact child. Parent C++ would duplicate a child method.
3. [UID:0001EB] proves part of the parent range is compiler-generated destructor adjustor material. [UID:0001EA] also contains scalar deleting destructor wrapper `0x00544f50-0x00545086`. These should be regenerated from ordinary destructor and class declarations, not handwritten.
4. Active code-entry scoring is not the blocker for the parent. The blocker is by-structure/emitter correctness: the parent should become `RECONSTRUCTABLE:FALSE` and blank-emitter.

Accepted current C++ path:

```cpp
void Pane::SetMode(unsigned char mode)
{
    if (m_mode == mode)
        return;

    m_mode = mode;
    InvalidateRect(&m_bounds);
}
```

This is already present in [UID:0002V7] and should remain there.

Future exact child pages can receive first-draft C++ once split, starting with `Pane::Show`, `Pane::Hide`, `Pane::InvalidateRect`, `Pane::GetScreenBounds`, and `Pane::SetBounds`. Do not place those bodies in [UID:0001EA].

## Exact Supervisor Edits

### Target metadata

Update [UID:0001EA] `by-memory/0x00544460-0x00545086.PaneCore.md` header:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000A2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Leave `RECONSTRUCTION_CPP` blank.

### Target status replacement

Placement: replace the current `## Status` bullets in [UID:0001EA].

```markdown
## Status

- Confidence: strong for the physical `Pane` method cluster and source-owner route.
- Address range: `0x00544460-0x00545086` half-open.
- Entity kind: reviewed non-emitting split/index over the base UI `Pane` method cluster.
- Disposition: not directly reconstructable as a parent page. Exact child method pages carry source emission; compiler thunks and scalar deleting destructor output stay non-emitting.
- Covered class: [UID:0000A2][Pane](by-class/Pane.md)
- Likely source file: [UID:0000MC][Pane](by-file/Pane.md)
- Type docs: [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md), [UID:0003JA][PaneVtables](by-type/by-vtable/PaneVtables.md), [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- Existing source-emitting child: [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md).
- Rebuild handling: reconstruct source-authored `Pane` methods through exact child pages. Reconstruct ordinary `virtual Pane::~Pane()` from `0x00544580-0x00544687`; regenerate `0x00544f2e-0x00544f44` adjustor thunks and `0x00544f50-0x00545086` scalar deleting destructor from class/destructor declarations.
- Formal C++ remains blank because this page is a split/index and would otherwise duplicate exact children or emit compiler ABI material.
```

### Target function table replacement

Placement: replace the current `## Functions` table in [UID:0001EA].

```markdown
## Functions

| Range | Function | Notes |
| --- | --- | --- |
| `0x00544460-0x00544578` | `Pane::Pane` | Constructs the leading `GrafPort`, EventHandler and timer/event views, regions, layer/origin/visible/mode state, and deletion/motion flags. Best source signature direction is `Pane::Pane(unsigned char mode)` / `Pane::Pane(PaneMode mode)`. |
| `0x00544580-0x00544687` | `Pane::~Pane` ordinary destructor | Reinstalls the three Pane vtables, unregisters focus/dispatcher/layer state, destroys `+0xdc` and `+0xc4` regions, tears down handler subobjects, and chains to `GrafPort` cleanup. This replaces stale `0x004b8d20` Pane-destructor wording. |
| `0x00544690-0x005446ad` | `Pane::MarkForDeletion` | Sets deferred-delete marker `+0xf4` and queues through the BlackHole deferred-deletion path. |
| [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md) | `Pane::SetMode` | Exact emitting child; writes mode byte `+0xb5` and calls `Pane::InvalidateRect` through primary slot `+0x20`. |
| `0x005446e0-0x00544706` | `Pane::GetCurrentMotionRegion` | Copies current or pending motion region to caller output. |
| `0x00544730-0x00544749` | `Pane::Show` | Sets visible flag `+0xb4`; redraw is suppressed for mode `4`. |
| `0x00544750-0x0054479b` | `Pane::Hide` | Clears visible flag `+0xb4`; if the auxiliary peer pane at `+0xb8` is present, transfers bounds/redraw context. |
| `0x005447a0-0x005447b3` | `Pane::Repaint` | Notifies the attached layer. |
| `0x00544800-0x005448ab` | `Pane::InvalidateRect` | Unions the caller/local rectangle into dirty region state; primary vtable slot `+0x20`. |
| `0x00544980-0x005449a5` | `Pane::SubtractMotionFromDirtyRegion` | Removes motion region from dirty-region state. |
| `0x00544a20-0x00544a34` | `Pane::OnCommand` default | Inherited/default command slot; exact arguments remain for child-page audit. |
| `0x00544a40-0x00544ade` | `Pane::HasPendingMotion` | Compares pending/current motion regions for layer traversal. |
| `0x00544ae0-0x00544b46` | `Pane::BeginMotionPaint` | Prepares active motion/clip state, applies origin offset, refreshes surface metadata, and sets the in-paint marker. |
| `0x00544b50-0x00544b7d` | `Pane::EndMotionPaint` | Commits pending motion state, clears pending state, and clears the in-paint marker. |
| `0x00544b80-0x00544bc0` | `Pane::GetScreenBounds` | Converts local bounds through event-handler/screen position into caller output. |
| `0x00544bd0-0x00544c42` | `Pane::SetBounds` | Stores origin and updates local bounds/sizing state. |
| `0x00544c50-0x00544c66` | `Pane::IsAttachedToLayer` | Reads `Layer*` at `+0xa8` and asks the layer whether this pane is present. |
| `0x00544c70-0x00544ca4` | `Pane::AddToLayer` | Calls `Layer::AddChildAfter`; direct class/source owner remains Pane. |
| `0x00544cb0-0x00544cd7` | `Pane::InsertInLayer` | Calls `Layer::AddChildBefore`. |
| `0x00544ce0-0x00544d2a` | `Pane::RemoveFromLayer` | Detaches from layer; BlackHole deferred-deletion helper reaches this through primary vtable slot `+0x38`. |
| `0x00544d30-0x00544d6f` | `Pane::SetPaneOrder` / dispatcher order helper | Passes the EventHandler view at `this +0xa0` to EventDispatcher ordering/registration logic; final name should be coordinated with EventDispatcher docs. |
| `0x00544d70-0x00544dae` | `Pane::UnregisterEventHandler` | Unregisters EventHandler view at `this +0xa0`; BlackHole reaches this through primary vtable slot `+0x40`. |
| `0x00544db0-0x00544e00` | Pane/EventHandler default bridge thunks | Adjusted-view bridge thunks to EventHandler source-defined default false bodies; not standalone handwritten Pane methods. |
| `0x00544e90-0x00544e95` | inherited tertiary default event/update slot | Shared default/update slot in short tertiary handler vtables; not feature-owned. |
| `0x00544f2e-0x00544f44` | destructor adjustor thunks | Compiler-generated secondary/tertiary destructor thunks; see [UID:0001EB][0x00544f2e-0x00544f44.PaneAdjustorThunks](by-memory/0x00544f2e-0x00544f44.PaneAdjustorThunks.md). |
| `0x00544f50-0x00545086` | scalar deleting destructor | Compiler-generated deleting destructor wrapper for `Pane`; regenerate from `virtual ~Pane()` and delete flag, do not hand-author. |
```

### Target nearby-method correction

Placement: replace `## Nearby Out-of-Cluster Methods` in [UID:0001EA].

```markdown
## Neighboring And Excluded Methods

- `0x0041d680-0x0041d682`: inherited/default no-op draw-style slot used by Pane-derived primary vtables.
- `0x004b8d20-0x004b8dc3`: `GrafPort` non-deleting cleanup/destructor body. This is a dependency called by Pane teardown, not the `Pane` ordinary destructor. The `Pane` ordinary destructor is `0x00544580-0x00544687` inside this target range.
```

### Target score rationale replacement

Placement: replace `## Score Rationale` in [UID:0001EA].

```markdown
## Score Rationale

Completion should be `88` and confidence `90` after reclassifying this page as a non-emitting split/index. The page now has a by-structure-correct purpose: it maps the physical base `Pane` cluster, records the exact ordinary destructor at `0x00544580`, keeps exact source-emitting child [UID:0002V7] separate, separates compiler-generated adjustor/scalar-destructor material, and points future exact child pages to [UID:0000A2][Pane](by-class/Pane.md) / [UID:0000MC][Pane](by-file/Pane.md). The remaining uncertainty is final source spelling for a few fields and method signatures, not ownership or split policy.
```

### Pane class support edits

Placement: in [UID:0000A2] `by-class/Pane.md`, replace the `Construction/destruction` row in `## Method Families`.

```markdown
| Construction/destruction | `0x00544460`, `0x00544580`, scalar wrapper `0x00544f50` | Initializes `GrafPort`, handlers, regions, mode/visibility state; ordinary `Pane::~Pane` at `0x00544580-0x00544687` releases Pane-owned dispatcher/layer/region/handler state and chains to `GrafPort` cleanup. The older `0x004b8d20` reference is `GrafPort` cleanup, not the Pane ordinary destructor. |
```

Placement: in [UID:0000A2] `by-class/Pane.md`, replace the current `GrafPort state block:` subsection in `## Observed State`.

```markdown
Inherited `GrafPort` state lives in the leading subobject and remains documented on [UID:00005V][GrafPort](by-class/GrafPort.md) and [UID:0000JR][GrafPort](by-file/GrafPort.md). Pane-facing uses of that leading state include `+0x44` as local/bounds rectangle and inherited region/draw-state fields used by dirty, clip, and backing-store helpers. Do not treat legacy generated duplicate offsets such as `0x64/0x68/0x6c/0x78/0x79` as separate Pane-owned fields; the Pane-owned additions are the `+0xa0..+0xf7` fields documented in [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md).
```

### Pane file support edits

Placement: in [UID:0000MC] `by-file/Pane.md`, replace the `Main method cluster` status bullet.

```markdown
- Main method cluster: non-emitting split/index [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md), with ordinary `Pane::~Pane` at `0x00544580-0x00544687` and scalar deleting destructor wrapper at `0x00544f50-0x00545086`. `0x004b8d20-0x004b8dc3` is the `GrafPort` base cleanup dependency, not a Pane method.
```

Placement: in [UID:0000MC] `by-file/Pane.md`, replace the `Pane` row in `## Proposed Contents`.

```markdown
| `Pane` | [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md) split/index; exact children under this range | Base pane construction, ordinary destruction, show/hide, repaint, invalidation, bounds, layer attach/remove, input/timer hooks, and default virtual support. Parent page is non-emitting; exact child pages carry C++ bodies. |
```

Placement: in [UID:0000MC] `by-file/Pane.md`, replace the stale A001 refresh bullet that names `0x004b8d20` as the non-deleting destructor.

```markdown
- `lookup_funcs` reconfirmed the core `Pane` starts and sizes: constructor `0x00544460` size `0x118`, ordinary `Pane` destructor `0x00544580` size `0x107`, dirty/motion helpers `0x00544690` size `0x1d`, `0x005446e0` size `0x26`, `0x00544980` size `0x25`, `0x00544a40` size `0x9e`, `0x00544ae0` size `0x66`, `0x00544b50` size `0x2d`, layer membership/attach helpers `0x00544c50` size `0x16`, `0x00544c70` size `0x34`, `0x00544cb0` size `0x27`, `0x00544ce0` size `0x4a`, dispatcher helpers `0x00544d30` size `0x3f` and `0x00544d70` size `0x3e`, default helper `0x00544e90` size `0x5`, adjustor thunks `0x00544f2e`/`0x00544f39` size `0xb`, and scalar/default cleanup body `0x00544f50` size `0x136`. The similarly old `0x004b8d20` destructor reference is now rejected as `GrafPort` cleanup.
```

### Pane layout support edits

Placement: in [UID:0001VH] `by-type/by-struct/PaneLayout.md`, replace rows for `+0xb8`, `+0xc0`, `+0xf5`, and `+0xf6`.

```markdown
| `+0xb8` | auxiliary peer/redraw pane pointer, high-probability `Pane*` | Constructor initializes zero; `Hide` checks this field and transfers bounds/redraw context when present. Rejected alternatives: attached layer (`+0xa8`), inline Region (`+0xc4/+0xdc`), and visibility/mode (`+0xb4/+0xb5`). Final source name remains descriptive, likely `m_peerPane` / `m_redrawPeerPane`. |
| `+0xc0` | auxiliary peer/redraw state byte | Constructor initializes zero near the `+0xb8` peer pointer. No documented consumer proves a final name; document as auxiliary state tied to the peer/redraw path rather than as an unknown compiler artifact. Rejected alternatives: delete marker (`+0xf4`), mode (`+0xb5`), and visible flag (`+0xb4`). |
| `+0xf5` | pending-motion selector flag, likely `m_hasPendingMotionRegion` | `GetCurrentMotionRegion` and `HasPendingMotion` choose current versus pending region behavior from this byte. This is a better source-facing direction than generic `pane flags`. |
| `+0xf6` | reserved/adjacent pane flag byte | Constructor clears it as part of a word store with `+0xf5`, but current docs do not show a consumer. Keep as reserved/adjacent motion flag until an exact use-site proves a stronger name. |
```

### Pane vtable support edit

Placement: in [UID:0003JA] `by-type/by-vtable/PaneVtables.md`, add after the `## Evidence` bullets or before `## Assignment Gate`.

```markdown
## Primary Slot Direction

The inherited primary Pane virtual span should be documented with source-facing names where resolved:

| Slot | Target | Direction |
| --- | --- | --- |
| `+0x00` | `0x00544f50` | scalar deleting destructor wrapper for `virtual Pane::~Pane()` |
| `+0x14` | `0x00544730` | `Pane::Show` |
| `+0x18` | `0x00544750` | `Pane::Hide` |
| `+0x1c` | `0x005447a0` | `Pane::Repaint` |
| `+0x20` | `0x00544800` | `Pane::InvalidateRect` |
| `+0x24` | `0x00544a20` | inherited/default command slot |
| `+0x28` | `0x00544b80` | `Pane::GetScreenBounds` |
| `+0x2c` | `0x00544bd0` | `Pane::SetBounds` |
| `+0x30` | `0x00544c70` | `Pane::AddToLayer` |
| `+0x34` | `0x00544cb0` | `Pane::InsertInLayer` |
| `+0x38` | `0x00544ce0` | `Pane::RemoveFromLayer` |
| `+0x3c` | `0x00544d30` | `Pane::SetPaneOrder` / dispatcher order helper |
| `+0x40` | `0x00544d70` | `Pane::UnregisterEventHandler` |

The surrounding inherited/base slots `+0x04`, `+0x08`, `+0x0c`, `+0x10`, `+0x44`, and `+0x48` should stay described as inherited `LObject`/`GrafPort`/default/guard/purecall support until their final class-header names are coordinated.
```

## Coverage Row Recommendation

Placement: replace the existing [UID:0001EA] row under the `0x00544460` block in `by-memory/-coverage-report.md`. Keep the surrounding padding rows and child rows in place unless applying the optional child-row cleanup below.

```markdown
    - [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md) 0x00544460-0x00545086 | class split index | PaneCore exact-child index : not_reconstructable : 88% : strong : B002 source-quality reanalysis recommends reclassifying this broad base Pane method cluster as a non-emitting split/index. It documents the exact Pane constructor/destructor/default/motion/dirty/visibility/bounds/layer/vtable support map, corrects the ordinary Pane destructor to `0x00544580` and rejects stale `0x004b8d20` as GrafPort cleanup, keeps [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md) as the existing source-emitting child, routes exact future Pane method children through [UID:0000A2][Pane](by-class/Pane.md) / [UID:0000MC][Pane](by-file/Pane.md), and leaves parent formal C++ blank to avoid duplicating child methods or emitting compiler thunks/default wrappers.
```

Optional child row cleanup, because current generated output now emits [UID:0002V7] and the existing row's "zero-byte generated output caveat" is stale:

```markdown
        - [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md) 0x005446b0-0x005446d4 | method | PaneSetMode : reconstructable : 88% : very strong : B002 2026-06-17 source-quality reanalysis confirms the exact 0x24-byte `Pane::SetMode` body, source-facing `void Pane::SetMode(unsigned char)` signature, `+0xb5` Pane mode byte, `+0x44` local bounds rectangle, primary vtable slot `+0x20` resolved through `0x00621a08 -> 0x00544800` `Pane::InvalidateRect`, no meaningful return value consumed by callers, broad UI caller xrefs with mode values `0/1/2/3/4` and saved-byte restore paths, Pane class owner/emitter route via [UID:0000A2][Pane](by-class/Pane.md) to `Pane.cpp`, current generated output containing this exact child body, and accepted first-draft C++ already populated.
```

## Validation Commands

Commands used or suitable for supervisor validation:

> Executable block R001 was removed from this report and preserved verbatim in [0001EA-PaneCore-source-quality-removed.md](0001EA-PaneCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Suggested post-application validator commands:

> Executable block R002 was removed from this report and preserved verbatim in [0001EA-PaneCore-source-quality-removed.md](0001EA-PaneCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0001EA-PaneCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"0001EA"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001EA-PaneCore-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0001EA-PaneCore-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001EA"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
