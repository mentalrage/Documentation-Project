*** UID:0000CA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00036Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00036Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ScreenFadeOut : public Pane
{
public:
    ScreenFadeOut(float startAlpha, int duration);
    virtual ~ScreenFadeOut();

    virtual void OnPaint();
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    int m_halfSteps;
    float m_fadeStepDelta;
    int m_updatesPerStep;
    float m_currentAlpha;
    int m_isActive;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScreenFadeOut

## Status

- Confidence: strong for behavior, layout, vtable identity, and direct source-file placement; medium-high for exact original source spelling because no PDB/source-path metadata survives in the binary.
- Likely source file: [UID:00036Q][ScreenFadeOut](by-file/ScreenFadeOut.md), neighboring [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md).
- Address range: [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md)
- Projected source file: `auto-generated/NexusTK/ui/core/ScreenFadeOut.cpp`.
- Current generated lead file: `source-3/simroot_v2/class_ScreenFadeOut.cpp`
- Imported source hint: `ScreenFadeOut.cpp`

## Class Purpose

`ScreenFadeOut` is a `Pane`-derived full-screen fade overlay. Its constructor computes exact duration-derived fade parameters, schedules inherited timer zero, obtains bounds unconditionally from `g_pScreenPane`, and attaches to `g_pStatusPaneLayer`. Its destructor alone performs g_pBackPane-first/g_pScreenPane-fallback invalidation so the overlay is repainted away.

This class is adjacent to [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md), but it is not the same as the `ScreenEffecter` runtime effect hierarchy documented under [UID:0000IZ][Effects](by-file/Effects.md).

## Layout Notes

| Offset | Field | Evidence |
| --- | --- | --- |
| `0x000` | primary `Pane`/`ScreenFadeOut` vtable | IDA MCP confirms constructor/destructor paths install the primary `ScreenFadeOut` table at object base. |
| `0x000-0x0f7` | inherited Pane/GrafPort/LObject and EventHandler/TimerHandler storage | RTTI and Pane construction prove Pane is the sole direct source base; the first derived write is `+0xf8`. |
| `0x0a0` | inherited EventHandler/secondary facet vtable | Constructor installs `ScreenFadeOut_vtable2`; adjustor thunk at `0x0055a051` subtracts `0xa0`. This facet is inherited through Pane. |
| `0x0a4` | inherited TimerHandler/tertiary facet vtable | Constructor installs `ScreenFadeOut_vtable3`; ScheduleTimer and OnTimer use this facet and the adjustor at `0x0055a05c` subtracts `0xa4`. |
| `0x0f8` | `m_halfSteps` | Constructor stores `duration / 2`. |
| `0x0fc` | `m_fadeStepDelta` | Float fade delta computed from `startAlpha` and half-step count. |
| `0x100` | `m_updatesPerStep` | Constructor stores `duration / halfSteps`. |
| `0x104` | `m_currentAlpha` | Initial alpha state after step-delta calculation. |
| `0x108` | `m_isActive` | Constructor initializes this to `1`. |

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ScreenFadeOut(float startAlpha, int duration)` | [UID:000395][0x00559e50-0x00559f5e.ScreenFadeOutConstructor](by-memory/0x00559e50-0x00559f5e.ScreenFadeOutConstructor.md) | Pane(2), exact signed fade/timer arithmetic and edge behavior, g_pScreenPane bounds, and g_pStatusPaneLayer attachment. |
| `~ScreenFadeOut` | [UID:000396][0x00559f60-0x0055a003.ScreenFadeOutDestructor](by-memory/0x00559f60-0x0055a003.ScreenFadeOutDestructor.md) | Source g_pBackPane-first/g_pScreenPane-fallback bounds invalidation; compiler performs vptr/base teardown. |
| `OnTimer(int,int,int)` | [UID:000397][0x0055a010-0x0055a015.ScreenFadeOutOnTimer](by-memory/0x0055a010-0x0055a015.ScreenFadeOutOnTimer.md) | Exact tertiary TimerHandler override returning false. Historical IsHandled identity is superseded. |
| `OnPaint()` | [UID:000398][0x0055a020-0x0055a021.ScreenFadeOutOnPaint](by-memory/0x0055a020-0x0055a021.ScreenFadeOutOnPaint.md) | Exact empty primary paint override. Historical OnUpdate identity is superseded. |
| `ScalarDeletingDestructor_vtable2_adjustor` | [UID:0001GC][0x0055a051-0x0055a05c.ScreenFadeOutVtable2AdjustorThunk](by-memory/0x0055a051-0x0055a05c.ScreenFadeOutVtable2AdjustorThunk.md) | Adjusts `this` from offset `0xa0` and forwards to the scalar deleting destructor. Current generated output leaves this in the disabled companion. |
| `ScalarDeletingDestructor_vtable3_adjustor` | [UID:0001GD][0x0055a05c-0x0055a067.ScreenFadeOutVtable3AdjustorThunk](by-memory/0x0055a05c-0x0055a067.ScreenFadeOutVtable3AdjustorThunk.md) | Adjusts `this` from offset `0xa4` and forwards to the scalar deleting destructor. |
| `ScalarDeletingDestructor` | `0x0055a180-0x0055a252` | Calls the destructor and conditionally frees heap storage. |

## Data Caveats

- Historical `class_ScreenFadeOut.meta_wave3` marked `0x0055a051` and `0x0055a05c` as disabled methods even though live IDA confirms both are real 11-byte compiler adjustor thunks; their non-emission is a compiler/source decision, not missing executable coverage.
- Historical generated source used `OnUpdate` and a zero-length end for `0x0055a020`; live IDA proves the one-byte body and primary-slot parity resolves it as `OnPaint`.
- Historical generated metadata polluted the destructor chain with `TextButtonExControlPane::~TextButtonExControlPane`. RTTI and the direct constructor/destructor calls prove Pane as the sole direct source base; the stale class name is rejected.
- 2026-05-26 recheck: current `class_ScreenFadeOut.cpp` still omits the `0x0055a051` and `0x0055a05c` adjustor thunks, while IDA MCP still reports them as real 11-byte functions with vtable data xrefs and decompiles them as `this - 0xa0` / `this - 0xa4` forwards to `0x0055a180`.
- [UID:0003H9][ScreenFadeOutLayout](by-type/by-struct/ScreenFadeOutLayout.md) records the exact `0x10c` / 268-byte object layout, fade fields, timer/interface vtable offset at `0xa4`, and IDA vtable bases `0x0062350c`, `0x00623558`, and `0x00623588`. [UID:0001VY][ScreenOverlayPaneLayouts](by-type/by-struct/ScreenOverlayPaneLayouts.md) remains the mixed non-emitting index, and [UID:00026C][0x00623480-0x00623d58.ScreenEffecterReadOnlyData](by-memory/0x00623480-0x00623d58.ScreenEffecterReadOnlyData.md) records the neighboring read-only-data island.
- 2026-06-11 B001-044 live IDA MCP recheck resolves the direct source split in favor of [UID:00036Q][ScreenFadeOut](by-file/ScreenFadeOut.md) as a separate `ui/core/ScreenFadeOut.cpp` file root. IDA confirms no source-path strings for `ScreenFadeOut.cpp`/`ScreenDimmer.cpp`, no `.pdb`/`RSDS`/`NB10` breadcrumbs, and only RTTI/type strings such as `.?AVScreenFadeOut@@`; this is therefore a best source-owner inference, not recovered debug metadata. The split is supported by the self-contained fade class method/vtable set, imported source hint, separate proposed source-tree entry, and negative evidence that `ScreenDimmer` singleton/factory ownership does not touch this class.
- 2026-06-18 supervisor Rule 26 re-audit superseded the older "blank until 95/95" C++ policy. The 2026-07-21 source-closure pass now supersedes that incomplete skeleton: exact OnPaint/OnTimer declarations and the complete natural field tail are resolved, while method bodies remain on by-memory children.

## Exact Source And Compiler Model

- Source direct base: `Pane` only. Pane supplies GrafPort/LObject storage and inherited EventHandler/TimerHandler facets; no multiple-inheritance spelling or explicit embedded interface members are needed in ScreenFadeOut source.
- Source declaration order closes exactly at `0x10c`: five contiguous four-byte fields at `+0xf8`, `+0xfc`, `+0x100`, `+0x104`, and `+0x108`, with types `int`, `float`, `int`, `float`, and `int`.
- Public virtual access is used for the constructor/destructor and overrides. The class formal contains no offset comments, raw padding, vptr members, ABI thunks, decompiler names, or manual compiler data.
- `[[CHILDREN]]` is after the complete class-closing `};`, so UID000395-398 qualified definitions emit at namespace scope.
- The ordinary class/virtual destructor naturally generates UID0001GC/UID0001GD adjustors, UID00039C deleting wrapper, UID0003EG RTTI/vtable data, UID0003H9 covered layout, EH cleanup, and cookies. Those support pages are false/non-emitting and blank-formal.
- Exact negative source evidence rejects constructor g_pBackPane fallback, ScreenDimmer singleton/factory ownership, Effects/ScreenEffecter inheritance, source-authored vtable arrays, explicit base teardown, scalar flags, and raw addresses.

## Assignment Decision

Assigned to registered [UID:00036Q][ScreenFadeOut](by-file/ScreenFadeOut.md). Current closure raises this class from `88/87` to `92/94` after exact method bodies/names, complete 0x10c declaration, class/file route, generated ordering, and source/compiler distinctions were resolved. Owner/emitter UID00036Q, true reconstructable state, and blank optional position remain unchanged.

The assignment deliberately separates this class from [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md). `ScreenDimmer` remains the correct direct owner for [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md), [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md), [UID:0000PJ][CreateScreenDimmer_4A12B0](by-global/CreateScreenDimmer_4A12B0.md), and the dimmer clear helper, but those lifecycle signals do not prove ownership of the fade class. UID0000IZ Effects owns the later ScreenEffecter runtime, not this Pane overlay.

## Score Rationale

- Completion `92`: complete class declaration, exact direct/inherited base model, all five fields/types/order, all four source methods and children, corrected names, globals/helpers/arithmetic/edge behavior, compiler support disposition, source route, generated placement, and historical/negative evidence are documented.
- Confidence `94`: layout, RTTI, vtable slots, method ABIs/bodies, class/file ownership, and compiler generation are direct or multiply corroborated. Exact private lexical spellings and original disk filename remain inferred because no PDB/source path survives.

## Cross-References

- [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)
- [UID:00036Q][ScreenFadeOut](by-file/ScreenFadeOut.md)
- [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md)
- [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md)
- [UID:0001GC][0x0055a051-0x0055a05c.ScreenFadeOutVtable2AdjustorThunk](by-memory/0x0055a051-0x0055a05c.ScreenFadeOutVtable2AdjustorThunk.md)
- [UID:0001GD][0x0055a05c-0x0055a067.ScreenFadeOutVtable3AdjustorThunk](by-memory/0x0055a05c-0x0055a067.ScreenFadeOutVtable3AdjustorThunk.md)
- [UID:0001VY][ScreenOverlayPaneLayouts](by-type/by-struct/ScreenOverlayPaneLayouts.md)
- [UID:0003H9][ScreenFadeOutLayout](by-type/by-struct/ScreenFadeOutLayout.md)
- [UID:00026C][0x00623480-0x00623d58.ScreenEffecterReadOnlyData](by-memory/0x00623480-0x00623d58.ScreenEffecterReadOnlyData.md)
- [UID:0000IZ][Effects](by-file/Effects.md)

## Changes

- 2026-07-21 B003 UID000395 callback: Raised scores to `92/94`, preserved owner/emitter UID00036Q, replaced the incomplete stale-name skeleton with exact R2, moved `[[CHILDREN]]` after the closing brace, resolved Pane-only inheritance and inherited facets, closed the natural 0x10c layout, corrected OnTimer/OnPaint, and preserved all prior source-split/history/compiler evidence.

- 2026-06-18 supervisor Rule 26 C++ readiness repair:
  - Added declaration-only first-draft C++ for the class root because the item is reconstructable, has a valid emitter, and clears the current draft-code gate.
  - The draft intentionally emits only the class skeleton, virtual declarations, fade/timer tail fields, and `[[CHILDREN]]`; method bodies, adjustor thunks, scalar deleting destructor glue, and exact secondary/timer-interface declarations remain on exact children or future type/interface pages.
  - This supersedes the older B001-044 "blank until 95/95" wording while preserving the unresolved interface-name caveat as a final-source-quality issue.

- 2026-06-11 B001-044: Raised completion/confidence from `85/84` to `88/87` and assigned the class to new direct file parent [UID:00036Q][ScreenFadeOut](by-file/ScreenFadeOut.md).
  - Before: the page deliberately stayed unassigned because confidence failed the strict child gate and the `ScreenDimmer.cpp` versus `ScreenFadeOut.cpp` direct-source split was unresolved.
  - After: `AUTOGEN_PARENT_UID:00036Q`; `ScreenFadeOut.cpp` is documented as a narrow UI-core file root, with [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md) reduced to a peer/neighbor rather than this class's direct parent.
  - Evidence: B001-044 live IDA MCP confirmed exact class method boundaries, `ScreenFadeOut` RTTI/COL and vtable refs at `0x00623508`, `0x0062350c`, `0x00623558`, and `0x00623588`, constructor field writes at `+0xf8/+0xfc/+0x100/+0x104/+0x108`, timer initialization through the `+0xa4` interface, and negative source-path metadata (`ScreenFadeOut.cpp`, `ScreenDimmer.cpp`, `.pdb`, `RSDS`, and `NB10` not found). Existing generated/imported documentation names `ScreenFadeOut.cpp`, and no live `ScreenDimmer` singleton/factory evidence touches this class.

- 2026-06-12 A004 Batch303 layout split:
  - Score unchanged at `88/87`; added [UID:0003H9][ScreenFadeOutLayout](by-type/by-struct/ScreenFadeOutLayout.md) as the exact class-local layout child split from mixed [UID:0001VY][ScreenOverlayPaneLayouts](by-type/by-struct/ScreenOverlayPaneLayouts.md).
  - Evidence: A004 live IDA MCP reconfirmed constructor writes at object base, `+0xa0`, `+0xa4`, `+0xf8`, `+0xfc`, `+0x100`, `+0x104`, and `+0x108`, vtable restore refs from constructor/destructor/deleting destructor, and the `0x10c` / 268-byte size.

- 2026-06-07: Batch 095 raised score from `84/82` to `85/84` and left the class unassigned.
  - Before: The page documented the fade overlay class but did not explicitly connect the layout/vtable support pages to the assignment gate.
  - After: The page records the stricter no-assignment decision: behavior and layout coverage are sufficient for `85` completion, but confidence remains below `85` because generated metadata defects and the `ScreenDimmer.cpp` versus `ScreenFadeOut.cpp` source split are unresolved.
  - Evidence: [UID:0001VY][ScreenOverlayPaneLayouts](by-type/by-struct/ScreenOverlayPaneLayouts.md) provides the object layout and vtable-base evidence, [UID:00026C][0x00623480-0x00623d58.ScreenEffecterReadOnlyData](by-memory/0x00623480-0x00623d58.ScreenEffecterReadOnlyData.md) covers the read-only-data/vtable island, and [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md) now explicitly limits its parent-gate refresh to direct `ScreenDimmer` children.

- 2026-05-30: Changed completion/confidence from `0/0` to `84/82`.
  - Before: The page was unevaluated despite documenting fade overlay behavior, timer/layout fields, adjustor thunks, scalar destructor, and metadata caveats.
  - After: Scored as high completion and strong confidence with remaining uncertainty around final source split and generated metadata defects.
  - Evidence: Existing layout notes, method notes, data caveats, IDA recheck notes, dimmer relationship, and overlay layout cross-references support the score.
- 2026-05-31: Marked reconstructable in validator metadata and replaced generated `Pane`-size wording with IDA-backed inherited-storage wording.
  - Before: The page documented source-owned class behavior but left `RECONSTRUCTABLE` blank and described the base span from generated metadata.
  - After: `RECONSTRUCTABLE` is set to `TRUE`; inherited storage is bounded by the first confirmed derived fade field at `0x0f8`; parent UID and C++ remain blank because the final source-file split and final-source-quality code are not at the 95+ gate.
  - Evidence: IDA MCP decompilation of `0x00559e50`, `0x00559f60`, and `0x0055a180` confirms project class construction/destruction, derived fade fields, and `Pane` teardown behavior.
