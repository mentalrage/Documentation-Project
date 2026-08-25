*** UID:0001U3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00003Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00003Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:60 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// DescPane field declarations are emitted by [UID:00003Q][DescPane](by-class/DescPane.md); do not duplicate a separate layout struct.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DescPane Layout

## Status

- Confidence: strong for the `0x100` extent, class-local tail offsets/types/lifetime, vtable/global anchors, Pane description contract, wide scratch, and source route; original field/method spellings remain inferred.
- Evidence basis: IDA disassembly/decompilation, [UID:0001XC][DescPaneVtables](by-type/by-vtable/DescPaneVtables.md) checks, and generated data only as a lead.
- Autogen status: attached under [UID:00003Q][DescPane](by-class/DescPane.md)
  at position 60. Its managed marker documents that the complete class
  declaration already owns the fields; no duplicate layout struct is emitted.

## Layout Summary

`DescPane` is a 256-byte `Pane`-derived object with three vtable views and a two-field class-local tail.

| Offset | Type | Meaning |
| --- | --- | --- |
| `+0x00` | `Pane` base / primary vtable | Primary pane object. |
| `+0x44` | inherited pane bounds/region | Passed to `InvalidateRect` by the setter and to `FillRect` by `OnPaint`. |
| `+0x70` | inherited draw-mode byte | Cleared by `DescPane::OnPaint`; source-facing name `m_drawMode`. |
| `+0xa0` | secondary vtable | Secondary inherited subobject using vtable base `0x00618a28` and destructor adjustor thunk `0x0049d81e`. |
| `+0xa4` | tertiary vtable | Tertiary inherited subobject using vtable base `0x00618a58` and destructor adjustor thunk `0x0049d829`. |
| `+0xf7` | padding/unknown byte | Wave3/Ghidra residual field before the local tail. |
| `+0xf8` | `Pane *` | Borrowed description source; source-facing name `m_pDescriptionSource`. Constructor clears it; setter compares/stores it; destructor does not release it. |
| `+0xfc` | `int32` | Selected description index, initialized to `-1`; best current source-facing name `m_selectedDescriptionIndex`. |

## Description Source Contract

`DescPane::OnPaint` treats `+0xf8` as a borrowed Pane object and invokes inherited primary slot `+0x24`. Fresh child [UID:0004IX][0x00544a20-0x00544a35.PaneGetDescription](by-memory/0x00544a20-0x00544a35.PaneGetDescription.md) proves the source signature `void Pane::GetDescription(int selectedIndex, wchar_t *outDescription)`: for index `-1` the base default writes one 16-bit NUL, otherwise it writes nothing. DescPane passes an uninitialized `wchar_t description[1024]`, exactly matching the `0x800`-byte stack reservation and 16-bit store evidence.

The prior provisional `DescPaneDescriptionSource` with nine unknown slots and `char *` output is superseded. No standalone provider UDT/vtable exists, while the exact Pane primary slot does. `+0xf8` is not a text buffer, owning pointer, dialog controller, or generic data slot; `+0xfc` is not a count, flag, mode, color, or cached length. No destructor release, persistent text field, local post-call read, fallback, or error handling exists.

[UID:00012N][0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw](by-memory/0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw.md) therefore takes `Pane *source`, compares/stores the exact two tail fields, and calls inherited `InvalidateRect(&m_bounds)` only when either changes. UID00012O separately uses bounds for `FillRect`, not invalidation.

## Notes

- IDA currently has no local `DescPane` struct, while Wave3 metadata reports the Ghidra-derived size and fields. Use this layout as a documentation model, not an IDA-applied type.
- The `+0x44` and `+0x70` rows are inherited `Pane` state, included here because the `DescPane` methods use them directly.
- [UID:0001XC][DescPaneVtables](by-type/by-vtable/DescPaneVtables.md) records the primary table at `0x006189dc`; current `class_DescPane.meta_wave3` still reports `vtable_count: 0`.

## Parent Rationale

Attach this layout declaration to [UID:00003Q][DescPane](by-class/DescPane.md). The page documents only the `DescPane` object layout, including inherited Pane offsets touched by DescPane methods and the class-local `+0xf8/+0xfc` tail. Existing [UID:0000A2][Pane](by-class/Pane.md) owns the description virtual; no separate provider type or file-level declaration is warranted.

## IDA Evidence

- 2026-05-31 IDA MCP `lookup_funcs` confirms modeled functions at `0x0049d740`, `0x0049d770`, `0x0049d7c0`, `0x0049d81e`, `0x0049d829`, and `0x0049d840`; constructor `0x0049d6f0` and setter/update helper `0x0049d780` remain raw starts.
- Complete accepted analysis of `0x0049d7c0` reads Pane pointer `+0xf8` and selected index `+0xfc`, clears draw-mode byte `+0x70`, calls `FillRect` with bounds `+0x44`, and dispatches Pane slot `+0x24` with `wchar_t[1024]`; historical invalidation/narrow-buffer wording is superseded.
- `xrefs_to 0x0069adf8` confirms `g_pDescPane` stores/clears/reads inside the DescPane island.
- `xrefs_to 0x006189dc` confirms the primary vtable is installed by the constructor/destructor paths.
- 2026-06-14 live IDA MCP session `a001_goal2_class_batch` reconfirmed that constructor-shaped start `0x0049d6f0` and source/index setter-shaped start `0x0049d780` are still raw `Not a function` starts, while modeled methods remain `0x0049d740` size `0x29`, `0x0049d770` size `0x6`, `0x0049d7c0` size `0x5e`, and `0x0049d840` size `0x5f`.
- Live `analyze_function 0x0049d7c0` confirmed the layout-critical refresh path: clear text state, clear inherited byte `+0x70`, invalidate using bounds at `this + 0x44`, read provider pointer `+0xf8`, read selected index `+0xfc`, reject index `-1`, and call provider vtable slot `+0x24` with the local description buffer.
- Live `xrefs_to 0x0069adf8` returned exactly four refs, all inside the DescPane island: raw constructor store `0x0049d731`, non-deleting destructor clear `0x0049d75a`, singleton getter read `0x0049d770`, and scalar deleting destructor clear `0x0049d860`.
- Supporting owner pages clear the route for this class-local layout: [UID:0000IS][DescPane](by-file/DescPane.md) is `88/90`, and [UID:00003Q][DescPane](by-class/DescPane.md) is `88/91`, with the same Pane/index tail, lifetime, setter, OnPaint, and raw-start caveats.
- 2026-06-16 live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed `0x0049d6f0` and `0x0049d780` are still `Not a function`, while `0x0049d740`, `0x0049d770`, `0x0049d7c0`, `0x0049d81e`, `0x0049d829`, and `0x0049d840` remain modeled DescPane-family methods/thunks.
- 2026-06-16 raw instruction scan over `0x0049d6f0-0x0049d73c` shows the constructor-shaped block calling `sub_544460(1)`, installing vtables at `+0x00`, `+0xa0`, and `+0xa4`, clearing `+0xf8`, writing `0xffffffff` to `+0xfc`, and storing `this` to `0x0069adf8`.
- 2026-06-29 B006 current MCP session `46666bf7` confirms the corrected setter range `0x0049d780-0x0049d7b2`: the instruction stream compares arguments against `+0xf8/+0xfc`, stores both when changed, takes bounds at `this+0x44`, dispatches primary vtable slot `+0x20`, and includes the `retn 8` immediate bytes at `0x0049d7b0-0x0049d7b1`.
- 2026-06-16 `xref_query` reconfirmed exact singleton/vtable support: four refs to `0x0069adf8`, three refs each to vtable bases `0x006189dc`, `0x00618a28`, and `0x00618a58`, and the only target ref from vtable cell `0x00618a20`. `type_query`/`search_structs` found no local DescPane/provider UDT; exact Pane slot evidence resolves the concrete source type despite that negative.
- 2026-06-18 B005 raw-memory recheck of the constructor confirmed the layout writes that initialize this tail: `0x0049d71d` clears `this+0xf8`, `0x0049d727` writes `0xffffffff` to `this+0xfc`, and `0x0049d731` stores `this` to `g_pDescPane`. The same report found no pointer/rel32 route to the raw constructor or setter starts, which caps reachability confidence but does not weaken the field-role inference.

## Score Rationale

Completion is `92` because the page records the `0x100` extent, direct Pane
base, inherited EventHandler/TimerHandler facets, inherited bounds/draw-mode
offsets, exact borrowed `Pane *`/index tail, lifetime, wide scratch, Pane slot
contract, singleton/vtable xrefs, complete class declaration coverage,
position, negatives, and no-duplicate-struct disposition. Confidence is `94`
because every layout-critical read/write, constructor/destructor lifetime,
setter, OnPaint, RTTI PMD, and Pane default agrees. Original field spellings
and raw constructor/setter modeling remain the only caps.

## Cross-References

- [UID:00003Q][DescPane](by-class/DescPane.md)
- [UID:0000IS][DescPane](by-file/DescPane.md)
- [UID:00012K][0x0049d6f0-0x0049d89f.DescPane](by-memory/0x0049d6f0-0x0049d89f.DescPane.md)
- [UID:0001XC][DescPaneVtables](by-type/by-vtable/DescPaneVtables.md)
- [UID:0001PB][0x0069adf8-0x0069adfc.g_pDescPane](by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md)

## 2026-07-16 B001 UID0002NA Accepted Callback

- Applied `92/94`, position 60, and the exact managed covered-layout marker.
- RTTI confirms DescPane directly derives only from Pane. EventHandler and
  TimerHandler facets occur at `+0xa0/+0xa4` through Pane and are not repeated
  as direct bases or explicit vptr fields.
- Total size remains `0x100`; the only class-local tail is borrowed
  `Pane *m_pDescriptionSource` at `+0xf8` and selected
  `int m_selectedDescriptionIndex` at `+0xfc`.
- The constructor initializes both fields, the setter updates them as a pair,
  `OnPaint` consumes them, and no destructor path releases the pointer.
- Historical provisional provider-interface, `char[2048]`, invalidation,
  RefreshDescription, and blank-until-full-header statements are superseded.
  UID00003Q now supplies the authoritative declaration.

## Changes

- 2026-07-16 B001 UID0002NA accepted callback:
  - Raised `89/92 -> 92/94`, set position 60, inserted the exact declaration
    coverage marker, and preserved every layout/lifetime/negative fact.
- 2026-07-12 B003 UID00012O accepted callback: raised `86/89 -> 89/92`; replaced pointer/dword and provisional custom-interface/`char[2048]` claims with borrowed `Pane *`, exact `GetDescription(int,wchar_t *)`, and `wchar_t[1024]`; resolved `+0x70` as draw mode and `+0x44` OnPaint use as `FillRect`; preserved `0x100` size, all offsets/vtable views, raw-start/no-UDT/no-lifetime/no-post-read negatives, owner/emitter, and blank layout formal block.
- 2026-06-29 B006 setter implementation callback:
  - Before: the page treated raw helper naming as a broad layout/C++ blocker and referenced the old `0x0049d780-0x0049d7b0` setter range.
  - Changed to: documents that `m_pDescriptionSource`, `m_selectedDescriptionIndex`, and provisional `DescPaneDescriptionSource` are sufficient for UID00012N first-draft setter C++; full provider-interface declaration remains provisional.
  - Summary/evidence: current MCP session `46666bf7` confirms the corrected setter range, `+0xf8/+0xfc` compare/store behavior, inherited `this+0x44` bounds invalidation through primary slot `+0x20`, refresh consumption of the same fields, and no local `DescPane`/provider UDT.
- 2026-06-18 B005 constructor source-quality incorporation:
  - Before: `+0xf8/+0xfc` were described generically and the page treated provider naming as a broad final-C++ blocker.
  - Changed to: the layout now records `m_pDescriptionSource` and `m_selectedDescriptionIndex` as best current field names, explains rejected alternatives, and distinguishes layout/header finalization from the constructor child's first-draft C++ readiness.
  - Summary/evidence: B005 used constructor writes, setter comparisons/stores, refresh provider-call consumption, singleton/vtable context, and no-route checks to validate the field meanings.
- 2026-06-16 A002 Goal2 source-quality refresh:
  - Before: `COMPLETION:85`, `CONFIDENCE:88`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:89`, with final C++ still blank.
  - Evidence: live MCP reconfirmed raw starts at `0x0049d6f0` and `0x0049d780`, modeled method sizes through `0x0049d840`, constructor raw writes to `+0xf8/+0xfc` and `g_pDescPane`, setter raw comparisons/stores plus vtable-slot dispatch, exact singleton and vtable xref sets, `RefreshDescription` vtable-only route, and no local `DescPane` or provider UDT/type. Remaining blockers are provider-interface/source names and raw helper source shape.
- 2026-06-14 A002 Goal2 by-type score refresh:
  - Before: `COMPLETION:80`, `CONFIDENCE:86`; the page had the correct layout tail but did not include the current live raw-start/singleton refresh and still referenced the older `95/95` code gate phrasing.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88`, with final C++ still blank.
  - Evidence: live MCP reconfirmed raw starts at `0x0049d6f0` and `0x0049d780`, modeled method sizes through `0x0049d840`, exact four-ref singleton set/read/clear pattern, and `RefreshDescription` reading `+0xf8/+0xfc` before calling provider slot `+0x24`. Remaining blockers are provider-interface/source names and raw helper source shape.
- 2026-06-07 parent attachment update:
  - What existed before: the layout page was reconstructable with strong field-offset evidence, but it had no autogen parent.
  - Changed to: `COMPLETION:80` and `AUTOGEN_PARENT_UID:00003Q`, with an explicit class-parent rationale.
  - Summary/evidence: [UID:00003Q][DescPane](by-class/DescPane.md) owns the documented `+0xf8/+0xfc` fields, clears the attachment gate, and links the same vtable/global/memory evidence; this layout page's C++ remains blank because provider-interface naming and raw helper semantics are not final.
- 2026-05-31 scoring and reconstructability:
  - What existed before: completion/confidence metadata was unevaluated at `0/0`, and `RECONSTRUCTABLE` was blank.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP confirms the field reads/writes, global singleton xrefs, vtable stores, and provider-call shape. The page remains below `95+` because exact provider-interface naming, raw helper naming, and full caller/use-site semantics are not final.
