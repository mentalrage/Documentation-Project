*** UID:0000JX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# HourPane

## Status

- Confidence: very strong for complete source inventory, deterministic emitter order, class/file role, direct inheritance, method behavior, globals, and compiler-only exclusions.
- Proposed module: `ui/panels/HourPane.cpp`
- Main class: [UID:000068][HourPane](by-class/HourPane.md)
- Main address doc: [UID:00016Y][0x004cee60-0x004cf1ef.HourPane](by-memory/0x004cee60-0x004cf1ef.HourPane.md)
- Singleton global: [UID:0000R4][g_pHourPane](by-global/g_pHourPane.md)
- Resource doc: [UID:0001RC][hourpane-time-resources](by-resource/hourpane-time-resources.md)
- Evidence basis: IDA MCP decompilation/function/caller/xref checks.

## File Role

`HourPane.cpp` owns the compact in-game clock/hour HUD pane. It is created by `InitializeMainUiGraph` in both the newer and older main UI layouts, tracks the current server-provided hour byte, paints the matching time icon, and creates a localized hover tooltip using text id `0x4d`.

This should remain a UI panel source. The code is resource/UI behavior rather than timekeeping infrastructure: it consumes a packet/message byte, invalidates its draw region, and selects `TIME.EPF`/`TIME.EPD` frames for display.

## Exact Source Inventory And Order

| Source position | Entity | Evidence / role |
| --- | --- | --- |
| 10 | [UID:000068][HourPane](by-class/HourPane.md) | Complete `Pane, Singleton<HourPane>` declaration, six human methods, signed current-hour field, extern singleton declaration, and `[[CHILDREN]]`. |
| 20 | [UID:0002ZE][g_hourFrameTable](by-global/g_hourFrameTable.md) | File-local writable twelve-short definition `10,11,0-9`. |
| 30 | [UID:0000R4][g_pHourPane](by-global/g_pHourPane.md) | Singleton pointer definition initialized to `NULL`, with storage child insertion. |
| 40 | [UID:0004NJ][0x004cee60-0x004ceeaf.HourPaneConstructor](by-memory/0x004cee60-0x004ceeaf.HourPaneConstructor.md) | Human source constructor. |
| 50 | [UID:0004NK][0x004ceeb0-0x004ceed9.HourPaneDestructor](by-memory/0x004ceeb0-0x004ceed9.HourPaneDestructor.md) | Empty human source destructor. |
| 60 | [UID:0004NL][0x004ceee0-0x004cef25.HourPaneHandlePacketEvent](by-memory/0x004ceee0-0x004cef25.HourPaneHandlePacketEvent.md) | Packet virtual. |
| 70 | [UID:0004NM][0x004cef30-0x004cf009.HourPaneHandlePointerOrMouseEvent](by-memory/0x004cef30-0x004cf009.HourPaneHandlePointerOrMouseEvent.md) | Pointer/mouse virtual. |
| 80 | [UID:0004NN][0x004cf010-0x004cf139.HourPaneOnPaint](by-memory/0x004cf010-0x004cf139.HourPaneOnPaint.md) | Paint virtual. |
| 90 | [UID:0004NO][0x004cf140-0x004cf173.HourPaneUpdateHourRaw](by-memory/0x004cf140-0x004cf173.HourPaneUpdateHourRaw.md) | Retained/inlined private helper with descriptive spelling. |
| 100 | [UID:0003BM][0x0061b36c-0x0061b444.HourPaneVtableResourceData](by-memory/0x0061b36c-0x0061b444.HourPaneVtableResourceData.md) | Class-generated covered-by marker for RTTI/vtables/literals. |
| 110 | [UID:00027K][0x0066db04-0x0066db1c.HourPaneFrameTable](by-memory/0x0066db04-0x0066db1c.HourPaneFrameTable.md) | Global-generated covered-by marker. |

UID00029I singleton storage is source position 10 under the UID0000R4 global route. UID0004NP destructor-adjustor thunks and UID0004NQ scalar deleting destructor remain non-emitting compiler artifacts and therefore have no source position or generated body.

## Behavior Notes

- The source constructor at `0x004cee60` initializes `Pane(1)` and signed `m_currentHour` to `-1`; its binary singleton publication and three vtable stores are compiler/base consequences.
- The ordinary virtual destructor at `0x004ceeb0` is empty in human source; its binary vptr, Singleton-clear, and Pane-teardown effects are compiler/base consequences.
- `HandlePacketEvent` at `0x004ceee0` accepts only payload discriminator byte `0x20`, passes the packet bytes to retained `UpdateHour`, and preserves the original no-size-check behavior and false return.
- `HandlePointerOrMouseEvent` at `0x004cef30` handles right-button event type `4`, deletes any existing `g_pSimpleHelpPane`, hit-tests in exact y/x argument order, formats `"%s : %02d"` using localized text id `0x4d`, allocates the exact `0xfc` help pane, and creates it for 5000 ms. The old security-callback claim is rejected.
- `OnPaint` at `0x004cf010` branches on [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97`. The new/current branch uses `TIME.EPF` plus `TIME.PAL`; the old branch uses `TIME.EPD`.
- Compiler-only destructor adjustor thunks at `0x004cf173` and `0x004cf17e` subtract `0xa0` and `0xa4` before forwarding to the scalar wrapper at `0x004cf190`; none is handwritten source or an emitted marker/body.

## Source Grouping

Keep this source adjacent to the other main HUD panels:

```text
ui/panels/
  UserStatusPane.cpp
  SoundStatusPane.cpp
  HourPane.cpp
  UserPane.cpp
```

`HourPane` should cross-reference [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md), [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md), and [UID:0000JZ][IconsPane](by-file/IconsPane.md) because all are created by `InitializeMainUiGraph` as persistent HUD/status panes, but they should not be merged. `ConnStatusPane` is network-state UI, `SoundStatusPane` is audio-control UI, `HourPane` is clock/resource display UI, and `IconsPane` is old-layout icon-strip UI.

## Data Caveats

Some recovered symbol naming aliases the singleton as `g_pItemShopPane`, but IDA confirms the global at `0x0069b418` is written by `HourPane` construction/cleanup/destruction and read during main UI shutdown. Use [UID:0000R4][g_pHourPane](by-global/g_pHourPane.md) as the canonical documentation name and preserve `g_pItemShopPane` only as a noncanonical alias.

IDA-confirmed functions at `0x004ceeb0` and `0x004ceee0` remain important to the range even when other source views miss them. Use the memory doc as the range anchor before source migration.

[UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) is the canonical name for the old/new resource selector used by `HourPane::OnPaint`. Preserve `byte_66DA97` only as the IDA lookup alias; do not introduce a local hour-pane-specific name because the same byte is shared by startup, main UI layout, render/resource selection, attached-object cleanup, packet-send side effects, timer digits, spell-input cleanup, and weather/layer construction.

## Complete Source And Generated Contract

- `NexusTK/ui/panels/HourPane.cpp` owns exactly one complete HourPane class declaration, six human method definitions, one file-local frame table, one singleton pointer definition, and three covered-by markers through the accepted emitter graph.
- The class declaration is emitted first and contains `[[CHILDREN]]`; the six method children and class-generated UID0003BM marker occupy positions 40-100 without duplicating declarations.
- The raw aggregate UID00016Y emits no marker/body. UID0004NP and UID0004NQ emit no marker/body because multiple inheritance plus the virtual ordinary destructor regenerates their ABI behavior.
- The global definitions are independent source entities at positions 20 and 30. UID00027K is represented by a marker at position 110; UID00029I is represented under UID0000R4 by its child marker.
- Source must not contain explicit vptr writes, secondary-base owner subtraction, Singleton publication/clear, Pane destructor calls, scalar delete flags, `operator delete`, guard/cookie/SEH machinery, or alignment bytes.

## Caller, Resource, And Teardown Routes

- `InitializeMainUiGraph` creates `HourPane` at `0x004f81a0` and `0x004f877c` after exact `0xfc` allocations. New-layout bounds are `(830,736,885,751)`; legacy bounds are `(14,375,43,387)`; each is attached under its layout-specific root/layer.
- Shutdown reads `g_pHourPane` at `0x00504a18` and removes it from the pane graph at `0x00504a24` before root teardown. Destruction then clears Singleton storage implicitly.
- The frame table has only two refs, both in `OnPaint`; the exact `%s : %02d`, `TIME.EPF`, `TIME.PAL`, and `TIME.EPD` literals and callback routes are documented in the children and independent support pages.
- UID0001OH `g_useEpfAssets` storage and UID00018U LanguageMan aggregate remain verify-only; HourPane links current canonical UID00040P for localized lookup without claiming ownership.

## Source Ownership Rationale

The file is `91/93`: direct inheritance, all source methods, two compiler-only children, two globals, three vtable views, two UI construction routes, shutdown removal, exact resource/callback dependencies, and deterministic generated order are resolved. The confidence cap preserves the unavailable original private-helper spelling and exact original header split; neither affects this source route or emitted behavior.

## Historical And Rejected Alternatives

- `g_pItemShopPane`, `OnMouseEvent`, a security callback at `0x0069ae00`, generic cleanup helper, missing update body, handwritten destructor thunks, and a source scalar wrapper are superseded or rejected.
- The former seven-function aggregate omitted the raw helper and treated blank blocks as score-gate placeholders. Exact children now exhaust the island and distinguish six source bodies from two no-code ABI children.
- The file remains a dedicated HUD-panel source. Do not merge it into timekeeping, ItemShop, IconsPane, SoundStatusPane, ConnStatusPane, shared rendering, resource, or main-UI initializer sources.

## Cross-References

- [UID:000068][HourPane](by-class/HourPane.md)
- [UID:00016Y][0x004cee60-0x004cf1ef.HourPane](by-memory/0x004cee60-0x004cf1ef.HourPane.md)
- [UID:0000R4][g_pHourPane](by-global/g_pHourPane.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0001RC][hourpane-time-resources](by-resource/hourpane-time-resources.md)
- [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md)
- [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md)
- [UID:0000JZ][IconsPane](by-file/IconsPane.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-07-14 B005 callback: raised `88/85 -> 91/93`, preserved `NexusTK/ui/panels/`, recorded deterministic positions 10-110, linked the complete class/six methods/two globals/three markers, excluded ABI wrappers, synchronized caller/resource/teardown evidence, and historicalized stale aliases and missing-body claims.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:82`.
  - Summary/evidence: class/file role, singleton, vtables, frame table, behavior, data caveats, resource dependencies, and main HUD grouping are well documented; confidence is capped by the exact inherited base naming and singleton alias caveat.
- 2026-06-05 reconstruction path classification:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, leaving the file row in error.
  - Changed to: `NexusTK/ui/panels/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `HourPane.cpp` under `NexusTK/ui/panels/`, and live IDA MCP xrefs/decompilation confirm `0x004cee60`, `0x004ceeb0`, and `0x004cf190` write/clear `dword_69B418` from `HourPane` lifecycle code.
- 2026-06-07 A008 alias cleanup:
  - What existed before: the page described the paint branch only as `byte_66DA97`.
  - Changed to: normalized the branch dependency to [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), while preserving `byte_66DA97` as the historical IDA alias.
  - Summary/evidence: the resolved-name report maps `byte_66DA97` to `g_useEpfAssets`, and the global page records the byte's broad old/new EPF/EPD resource-mode role including the `HourPane::OnPaint` xref at `0x004cf020`.
- 2026-06-10 A001 parent-gate repair:
  - Changed confidence from `82` to `85`; completion remains `88`.
  - Summary/evidence: exact HourPane method island, singleton storage, frame table storage, resource docs, and the resolved `g_useEpfAssets` alias now make source ownership strong enough for direct children to clear the strict `85/85` parent gate. Final inherited-base naming and field names remain below the final-code threshold.
