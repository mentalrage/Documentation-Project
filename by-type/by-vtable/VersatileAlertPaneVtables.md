*** UID:0001Z0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:97 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000FU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# VersatileAlertPane Vtables

## Status

- Entity kind: vtable cluster.
- Covered class: [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md).
- Likely source file: [UID:0000HE][AlertPanes](by-file/AlertPanes.md).
- Confidence: very strong for vtable bases, constructor stores, callback virtual slots, destructor slots, and exact range boundaries.
- Exact memory child: [UID:0002P1][0x00618ba0-0x00618c44.VersatileAlertPaneVtableData](by-memory/0x00618ba0-0x00618c44.VersatileAlertPaneVtableData.md).
- Autogen status: reviewed false/non-emitting vtable model. Canonical owner remains the `VersatileAlertPane` class, but the compiler-data page has blank emitter, position, and formal C++.

## Vtable Bases

| Class view | Base | Constructor store | Object offset | Notes |
| --- | --- | --- | --- | --- |
| primary | `0x00618ba4` | `0x004a06b6` | `+0x00` | Installed after `AlertPane` base construction. |
| secondary | `0x00618c0c` | `0x004a06bc` | `+0xa0` | Secondary dialog/input view. |
| tertiary | `0x00618c3c` | `0x004a06c6` | `+0xa4` | Event/update-handler view. |

The same three vtables are also reinstalled by the cleanup-shaped body at [UID:00012Y][0x004a06e0-0x004a0715.VersatileAlertPaneDestructor](by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneDestructor.md) and by the scalar deleting destructor at `0x004a0cd0-0x004a0d37`.

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| primary `0x00618ba4` | `+0x00` | `0x004a0cd0` | [UID:0004NG][0x004a0cd0-0x004a0d37.VersatileAlertPaneScalarDeletingDestructor](by-memory/0x004a0cd0-0x004a0d37.VersatileAlertPaneScalarDeletingDestructor.md), compiler-regenerated from the source ordinary destructor. |
| primary `0x00618ba4` | `+0x44` | `0x0049f090` | Inherited dialog focus/selection drawing virtual. |
| primary `0x00618ba4` | `+0x48` | `0x004a0580` | Inherited `AlertPane::DismissDialog` action-dispatch path. |
| primary `0x00618ba4` | `+0x50` | `0x0049f1d0` | Inherited dialog content drawing virtual. |
| primary `0x00618ba4` | `+0x54` | `0x0049f2e0` | Inherited dialog border drawing virtual. |
| primary `0x00618ba4` | `+0x58` | `0x0049fc00` | Inherited dialog hover/update virtual. |
| primary `0x00618ba4` | `+0x5c` | `0x004a0720` | `VersatileAlertPane::OnPrimaryButton`; accept/primary behavior, reports unsigned-long result `1` through `m_resultCallback`. |
| primary `0x00618ba4` | `+0x60` | `0x004a0740` | `VersatileAlertPane::OnSecondaryButton`; cancel/secondary behavior, reports unsigned-long result `0` through `m_resultCallback`. |
| secondary `0x00618c0c` | `+0x00` | `0x004a0cb0` | [UID:0004NE][0x004a0cb0-0x004a0cbb.VersatileAlertPaneDestructorAdjustorThunkA0](by-memory/0x004a0cb0-0x004a0cbb.VersatileAlertPaneDestructorAdjustorThunkA0.md), with `this - 0xa0` / decimal `160`. |
| tertiary `0x00618c3c` | `+0x00` | `0x004a0cbb` | [UID:0004NF][0x004a0cbb-0x004a0cc6.VersatileAlertPaneDestructorAdjustorThunkA4](by-memory/0x004a0cbb-0x004a0cc6.VersatileAlertPaneDestructorAdjustorThunkA4.md), with `this - 0xa4` / decimal `164`. |
| tertiary `0x00618c3c` | `+0x04` | `0x00544e90` | Base/default event-update slot. |

Do not read primary `+0x64` as a `VersatileAlertPane` virtual: it is RTTI metadata for the secondary table at `0x00618c0c`. Likewise, secondary `+0x2c` is RTTI metadata for the tertiary table, and tertiary `+0x08` belongs to the following `ModelessDialogPane` RTTI region.

## IDA MCP Evidence

- IDA MCP `py_eval` on 2026-06-01 confirms the exact RTTI-adjacent data range `0x00618ba0-0x00618c44`: `0x00618ba0`, `0x00618c08`, and `0x00618c38` point to `VersatileAlertPane` RTTI records, while `0x00618c44` points to the following `ModelessDialogPane` RTTI record and is outside this item.
- `list_globals *VersatileAlertPane*` reports vtables at `0x00618ba4`, `0x00618c0c`, and `0x00618c3c`, plus RTTI records at `0x00646644`, `0x006466a8`, and `0x006466bc`.
- `xrefs_to` the three vtable bases reports constructor stores at `0x004a06b6`, `0x004a06bc`, and `0x004a06c6` inside `VersatileAlertPane::VersatileAlertPane` at `0x004a0690`.
- The same vtable bases have data xrefs from `0x004a06e9`, `0x004a06ef`, and `0x004a06f9` inside an unreferenced cleanup-shaped body, and from `0x004a0cdc`, `0x004a0ce2`, and `0x004a0cec` inside the scalar deleting destructor.
- `lookup_funcs` confirms `0x004a0690`, `0x004a0720`, `0x004a0740`, `0x004a0cb0`, `0x004a0cbb`, and `0x004a0cd0` as function starts. IDA does not currently model `0x004a06e0` as a function, and `xrefs_to 0x004a06e0` returns no callers.
- `xrefs_to 0x004a0690` reports constructor calls from `0x005301de` and `0x0058b5c5`.
- `0x00618c44` points to `??_R4ModelessDialogPane@@6B@`, followed by `??_7ModelessDialogPane@@6B@` at `0x00618c48`, proving that the versatile alert vtable cluster ends before `0x00618c44`.

## Reconstruction Notes

Model `VersatileAlertPane` as a thin `AlertPane` subclass with three vtable views at `+0x00`, `+0xa0`, and `+0xa4`. The class-specific behavior is concentrated in `m_resultCallback` at offset `+0x270` and the two primary-table callback extension slots at `+0x5c` and `+0x60`, which are reached virtually by `AlertPane::DismissDialog`.

Keep UID0004NE and UID0004NF as compiler adjustor thunks, not source methods. [UID:00012Y][0x004a06e0-0x004a0715.VersatileAlertPaneDestructor](by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneDestructor.md) is the accepted source ordinary destructor carrier despite zero direct binary entry route; its unique body and the live scalar wrapper share the same vptr, owned-callback, and base-teardown sequence.

Do not emit raw vtable dwords, generated RTTI names, or a comment marker from this type page. The exact memory child [UID:0002P1][0x00618ba0-0x00618c44.VersatileAlertPaneVtableData](by-memory/0x00618ba0-0x00618c44.VersatileAlertPaneVtableData.md), this type model, UID000130, and its three ABI children are all false/non-emitting. The real source is the [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md) declaration plus exact constructor/destructor/callback pages. `OnAccept` and `OnCancel` remain behavior aliases; source-facing overrides remain `OnPrimaryButton` and `OnSecondaryButton`.

## RTTI Hierarchy And Layout

- Complete-object locators `0x00646644`, `0x006466a8`, and `0x006466bc` describe offsets `0`, `0xa0`, and `0xa4` and share type descriptor `0x00675b80` plus class hierarchy descriptor `0x00646658`.
- The eight-entry hierarchy is `VersatileAlertPane`, `AlertPane`, `DialogPane`, `Pane`, `GrafPort`, `LObject`, `EventHandler` at PMD mdisp `0xa0`, and `TimerHandler` at PMD mdisp `0xa4`.
- Direct human inheritance remains `VersatileAlertPane : public AlertPane`; the secondary and tertiary tables are inherited interface views.
- `FunctionObjectT<unsigned long> *m_resultCallback` occupies `+0x270`; the scalar-wrapper guarded-size path uses `0x274`, proving this class size and supporting an `AlertPane` base size of `0x270` for this layout.
- Two constructor sites allocate 628-byte panes and 24-byte concrete unsigned-long callback objects. Primary/secondary slots invoke `1`/`0`; both destructor copies own and delete the callback.

## No-Code Proof And Rejected Alternatives

This page is a source-declared/generated-binary type audit, not a standalone source unit. The compiler regenerates all three address points, RTTI, COLs, hierarchy data, and adjusted destructor slots from inheritance and virtual declarations. A nonblank formal block would either duplicate the class declaration or hand-author ABI data.

Rejected alternatives include raw vtable arrays, explicit RTTI declarations, handwritten adjustor/scalar wrappers, `TransferReplyAlert` or Boost ownership, a pane-local callback interface, bool callback ABI, borrowed callback ownership, and merging the following `ModelessDialogPane` RTTI at `0x00618c44`.

## Parent Rationale

Attach this vtable cluster to [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md) because the primary, secondary, and tertiary tables are installed by the class constructor and destructor paths, and the primary callback slots are the class-specific primary/secondary result behavior. The class page is already reconstructable, attached to [UID:0000HE][AlertPanes](by-file/AlertPanes.md), and records the same exact [UID:0002P1][0x00618ba0-0x00618c44.VersatileAlertPaneVtableData](by-memory/0x00618ba0-0x00618c44.VersatileAlertPaneVtableData.md) child, callback pointer layout, constructor xrefs, and cleanup-shaped caveat. Reject `AlertPane`, `FunctionObjects`, `DialogCoreReadOnlyData`, and neighboring `ModelessDialogPane` as direct owners for the same reasons documented on the exact memory child: they either provide inherited/framework support, contain the bytes, or begin at the next RTTI boundary rather than owning this class-specific vtable cluster.

## Cross-References

- [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md)
- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- [UID:00012X][0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland](by-memory/0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland.md)
- [UID:00012Y][0x004a06e0-0x004a0715.VersatileAlertPaneDestructor](by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneDestructor.md)
- [UID:000130][0x004a0cb0-0x004a0d37.VersatileAlertPaneDeletingDestructorAbiIsland](by-memory/0x004a0cb0-0x004a0d37.VersatileAlertPaneDeletingDestructorAbiIsland.md)
- [UID:0004NE][0x004a0cb0-0x004a0cbb.VersatileAlertPaneDestructorAdjustorThunkA0](by-memory/0x004a0cb0-0x004a0cbb.VersatileAlertPaneDestructorAdjustorThunkA0.md)
- [UID:0004NF][0x004a0cbb-0x004a0cc6.VersatileAlertPaneDestructorAdjustorThunkA4](by-memory/0x004a0cbb-0x004a0cc6.VersatileAlertPaneDestructorAdjustorThunkA4.md)
- [UID:0004NG][0x004a0cd0-0x004a0d37.VersatileAlertPaneScalarDeletingDestructor](by-memory/0x004a0cd0-0x004a0d37.VersatileAlertPaneScalarDeletingDestructor.md)
- [UID:0001WZ][AlertPaneVtables](by-type/by-vtable/AlertPaneVtables.md)
- [UID:00012W][0x0049feb0-0x004a0686.AlertPaneCore](by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md)
- [UID:0002P1][0x00618ba0-0x00618c44.VersatileAlertPaneVtableData](by-memory/0x00618ba0-0x00618c44.VersatileAlertPaneVtableData.md)

## Changes

- 2026-06-07 parent attachment update:
  - What existed before: the vtable cluster was reconstructable but unassigned in generated type coverage despite an established `VersatileAlertPane` class parent.
  - What changed: attached the vtable cluster to [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md), raised completion to `86`, and added an explicit parent rationale.
  - Summary/evidence: constructor stores at `0x004a06b6`, `0x004a06bc`, and `0x004a06c6`, callback slots `0x004a0720` and `0x004a0740`, destructor stores, and exact [UID:0002P1][0x00618ba0-0x00618c44.VersatileAlertPaneVtableData](by-memory/0x00618ba0-0x00618c44.VersatileAlertPaneVtableData.md) prove class ownership; final C++ stays blank until callback interface and alert base type names are source-quality.
- 2026-06-17 B002 source-quality execution:
  - Score unchanged at `86/90`.
  - Clarified primary slots `+0x5c/+0x60` as vtable-only accept/cancel result callbacks that invoke `m_resultCallback` with unsigned-long results `1/0`, and kept adjustor thunks/destructor support out of hand-written source.
- 2026-06-21 B005 source-quality Rule 26 incorporation:
  - Raised from `86/90` to `87/92`.
  - Replaced stale `95/95` blank-C++ wording with current over-85 no-code/comment-only vtable support policy, renamed final source-facing callback slots to `OnPrimaryButton` / `OnSecondaryButton`, preserved accept/cancel as behavior aliases, and kept secondary/tertiary destructor adjustor thunks as generated ABI artifacts with `this - 0xa0` / `this - 0xa4`.
- 2026-06-30 B011 empty-emitter implementation:
  - Score and metadata unchanged at `87/92`, owner/emitter [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md).
  - Added the formal vtable-cluster no-code marker. It preserves vtable bases, primary result slots, constructor/destructor/thunk refs, `m_resultCallback` result semantics, exact [UID:0002P1][0x00618ba0-0x00618c44.VersatileAlertPaneVtableData](by-memory/0x00618ba0-0x00618c44.VersatileAlertPaneVtableData.md) route, and the active no-code/comment-only policy.
- 2026-07-14 B004 phase-two callback:
  - Raised `87/92 -> 94/97`, retained canonical owner UID0000FU, and reclassified the generated vtable model false/non-emitting with blank emitter, position, and formal C++.
  - Added exact COL offsets/eight-entry hierarchy, real ABI-child UIDs, resolved callback type/ownership, class-size evidence, and renamed UID000130 route without changing source-bearing method pages.
  - Historical comment-emitter policy is superseded; all original slot, xref, boundary, and rejected-owner evidence remains preserved.

- What existed before: this page listed the three vtable bases and slot evidence, but kept completion/confidence at `0/0`, cited incomplete Wave3 metadata, and did not have a precise by-memory child range.
- What changed: completion/confidence is now `84/90`, `RECONSTRUCTABLE` is marked `TRUE`, the stale Wave3 caveat was replaced with IDA MCP boundary evidence, and the exact child range [UID:0002P1][0x00618ba0-0x00618c44.VersatileAlertPaneVtableData](by-memory/0x00618ba0-0x00618c44.VersatileAlertPaneVtableData.md) was added.
- Evidence: IDA MCP `py_eval` on 2026-06-01 read the RTTI/vtable dwords and xrefs at `0x00618ba0-0x00618c44`, with `ModelessDialogPane` RTTI beginning at `0x00618c44`.
