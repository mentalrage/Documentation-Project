*** UID:0000IB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# CollectionDialogPane

## Status

- Confidence: very strong for grouping the dialog and its two private controls, all 22 exact children, singleton behavior, packet-bit entry-state writes, typed collection-data access, compiler-support boundaries, and current `CollectionDialogPane.cpp` route. Historical generated class filenames and possible header folding remain provenance only.
- Proposed module folder: `ui/dialogs/`
- Proposed source file: `ui/dialogs/CollectionDialogPane.cpp`
- Companion file: [UID:0000IC][CollectionPane](by-file/CollectionPane.md)
- Evidence basis: IDA MCP boundary/caller checks, compact address locality, private-control allocation, and collection-dialog resource usage.

## Hypothesis

The collection detail dialog is one source unit containing `CollectionDialogPane` plus its private progress-bar and entry-slot controls. The exact constructor directly allocates one `CollectionBarControlPane` and six `CollectionEntryControlPane` instances, and those controls draw only `CLT*` collection-dialog assets. Historical recovered per-class filenames are search leads, not authority for three source files.

## Proposed Contents

| Entity | Current range | Evidence / ownership note | Role |
| --- | --- | --- | --- |
| [UID:00002V][CollectionDialogPane](by-class/CollectionDialogPane.md) | Seven source children plus EH cleanup, singleton-unwind child, adjustors, and scalar wrapper listed below | Attached class page; exact callers, fields, singleton, and vtable evidence place it in this dialog file. | Paginated 6-entry collection detail dialog, next/previous control handling, singleton lifecycle. |
| [UID:00002W][CollectionEntryControlPane](by-class/CollectionEntryControlPane.md) | Seven source children plus shared adjustors and scalar wrapper listed below | Attached private entry-slot control; constructor callers, collection-only resources, and vtable views point back to this source unit. Shared GrafPort/text routines are dependencies, not contents of this file. | One detail-grid entry control with empty/locked/collected drawing, raw-route page steps, and wrapped text. |
| [UID:00002U][CollectionBarControlPane](by-class/CollectionBarControlPane.md) | Four source children plus shared adjustors and scalar wrapper listed below | Attached private control; construction, resources, and vtable evidence point back to this source unit. | Progress bar and exact `current/total(percent)` label behavior. |
| [UID:0000QL][g_pCollectionDialogPane](by-global/g_pCollectionDialogPane.md) | `0x0069adf0` | global-data alias | Active detail-dialog singleton guard. |
| [UID:0002B8][0x0069adf0-0x0069adf4.g_pCollectionDialogPane](by-memory/0x0069adf0-0x0069adf4.g_pCollectionDialogPane.md) | `0x0069adf0-0x0069adf4` | Exact source-emitting storage carrier for the active detail-dialog singleton; B006 MCP session `ddf5b602` confirms zero-filled storage, exact eight refs, no extra pointer route, and clean neighboring singleton boundaries. | Emits `CollectionDialogPane *g_pCollectionDialogPane;` through this source file. |
| [UID:000250][0x006164f0-0x006168d0.CollectionReadOnlyData](by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md) | `0x006164f0-0x006168d0` | Source-declared/generated-binary `.rdata` attached to this file. | Dialog/control RTTI/vtables plus `DLGCLT`, `CLTNAME`, `CLTVOL`, `CLTENTRY`, `CLTICON`, `CLTBAR`, and font/symbol resource strings. |

[UID:000250][0x006164f0-0x006168d0.CollectionReadOnlyData](by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md) should emit only source-level wide string constants for the collection detail dialog resources. Its `CollectionDialogPane`, `CollectionEntryControlPane`, and `CollectionBarControlPane` RTTI/vtables are compiler-generated from the private dialog/control declarations and must not be hand-authored as raw data.

### Exact Child Inventory

| Exact range | UID / disposition |
| --- | --- |
| `0x0048c640-0x0048cf75` | [UID:0004JE][0x0048c640-0x0048cf75.CollectionDialogPaneConstructor](by-memory/0x0048c640-0x0048cf75.CollectionDialogPaneConstructor.md), source constructor with trusted packet buffer behavior and branch-specific loaded flag. |
| `0x0048cf80-0x0048cfaa` | [UID:0004JF][0x0048cf80-0x0048cfaa.CollectionDialogPaneConstructorUnwindCleanup](by-memory/0x0048cf80-0x0048cfaa.CollectionDialogPaneConstructorUnwindCleanup.md), generated EH cleanup, non-emitting. |
| `0x0048cfb0-0x0048d17e` | [UID:0004JG][0x0048cfb0-0x0048d17e.CollectionDialogPaneOnControlCommand](by-memory/0x0048cfb0-0x0048d17e.CollectionDialogPaneOnControlCommand.md), source command handler. |
| `0x0048d180-0x0048d183` | [UID:0004JH][0x0048d180-0x0048d183.CollectionDialogPaneSetHoverControlNoOp](by-memory/0x0048d180-0x0048d183.CollectionDialogPaneSetHoverControlNoOp.md), empty source override. |
| `0x0048d190-0x0048d1ce` | [UID:0004JI][0x0048d190-0x0048d1ce.CollectionDialogPaneFindCategoryIndex](by-memory/0x0048d190-0x0048d1ce.CollectionDialogPaneFindCategoryIndex.md), typed source lookup. |
| `0x0048d1d0-0x0048d2c7` | [UID:0004JJ][0x0048d1d0-0x0048d2c7.CollectionDialogPaneNextPageRaw](by-memory/0x0048d1d0-0x0048d2c7.CollectionDialogPaneNextPageRaw.md), exact retained source with historical no-direct-route evidence. |
| `0x0048d2d0-0x0048d39f` | [UID:0004JK][0x0048d2d0-0x0048d39f.CollectionDialogPanePreviousPageRaw](by-memory/0x0048d2d0-0x0048d39f.CollectionDialogPanePreviousPageRaw.md), exact retained source with historical no-direct-route evidence. |
| `0x0048d3a0-0x0048d47b` | [UID:0004JL][0x0048d3a0-0x0048d47b.CollectionEntryControlPaneConstructor](by-memory/0x0048d3a0-0x0048d47b.CollectionEntryControlPaneConstructor.md), source constructor. |
| `0x0048d480-0x0048d49f` | [UID:00010Y][0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor](by-memory/0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor.md), empty ordinary source destructor with retained no-route provenance. |
| `0x0048d4a0-0x0048d992` | [UID:0004JM][0x0048d4a0-0x0048d992.CollectionEntryControlPaneOnDraw](by-memory/0x0048d4a0-0x0048d992.CollectionEntryControlPaneOnDraw.md), source draw body. |
| `0x0048d9a0-0x0048d9b1` | [UID:0004JO][0x0048d9a0-0x0048d9b1.CollectionEntryControlPanePreviousPageRaw](by-memory/0x0048d9a0-0x0048d9b1.CollectionEntryControlPanePreviousPageRaw.md), exact retained six-instruction source step. |
| `0x0048d9c0-0x0048d9d1` | [UID:0004JP][0x0048d9c0-0x0048d9d1.CollectionEntryControlPaneNextPageRaw](by-memory/0x0048d9c0-0x0048d9d1.CollectionEntryControlPaneNextPageRaw.md), exact retained six-instruction source step. |
| `0x0048d9e0-0x0048dc22` | [UID:0004JQ][0x0048d9e0-0x0048dc22.CollectionEntryControlPaneDrawWrappedText](by-memory/0x0048d9e0-0x0048dc22.CollectionEntryControlPaneDrawWrappedText.md), source text helper with explicit-newline consumption. |
| `0x0048dc30-0x0048dce0` | [UID:0004JR][0x0048dc30-0x0048dce0.CollectionBarControlPaneConstructor](by-memory/0x0048dc30-0x0048dce0.CollectionBarControlPaneConstructor.md), source constructor. |
| `0x0048dce0-0x0048dd53` | [UID:0004JT][0x0048dce0-0x0048dd53.CollectionBarControlPaneDestructor](by-memory/0x0048dce0-0x0048dd53.CollectionBarControlPaneDestructor.md), source ordinary destructor. |
| `0x0048dd60-0x0048dfec` | [UID:0004JU][0x0048dd60-0x0048dfec.CollectionBarControlPaneOnDraw](by-memory/0x0048dd60-0x0048dfec.CollectionBarControlPaneOnDraw.md), source draw body with unguarded zero-total division. |
| `0x0048dff0-0x0048e133` | [UID:0004JV][0x0048dff0-0x0048e133.CollectionBarControlPaneDrawProgressLabel](by-memory/0x0048dff0-0x0048e133.CollectionBarControlPaneDrawProgressLabel.md), source glyph-label helper. |
| `0x0048e140-0x0048e14b` | [UID:00010Z][0x0048e140-0x0048e14b.ClearCollectionDialogPaneSingleton](by-memory/0x0048e140-0x0048e14b.ClearCollectionDialogPaneSingleton.md), generated constructor-unwind singleton clear, non-emitting. |
| `0x0048e14b-0x0048e18d` | [UID:0004JX][0x0048e14b-0x0048e18d.CollectionDialogControlDestructorAdjustorThunks](by-memory/0x0048e14b-0x0048e18d.CollectionDialogControlDestructorAdjustorThunks.md), six generated adjustors, non-emitting. |
| `0x0048e190-0x0048e244` | [UID:0004JY][0x0048e190-0x0048e244.CollectionBarControlPaneScalarDeletingDestructor](by-memory/0x0048e190-0x0048e244.CollectionBarControlPaneScalarDeletingDestructor.md), source-declared/compiler-generated wrapper. |
| `0x0048e250-0x0048e2af` | [UID:0004JZ][0x0048e250-0x0048e2af.CollectionDialogPaneScalarDeletingDestructor](by-memory/0x0048e250-0x0048e2af.CollectionDialogPaneScalarDeletingDestructor.md), normal destructor source plus compiler wrapper semantics. |
| `0x0048e2b0-0x0048e305` | [UID:0004K0][0x0048e2b0-0x0048e305.CollectionEntryControlPaneScalarDeletingDestructor](by-memory/0x0048e2b0-0x0048e305.CollectionEntryControlPaneScalarDeletingDestructor.md), source-declared/compiler-generated wrapper. |

The 19 alignment/padding gaps remain indexed on [UID:00010X][0x0048c640-0x0048e305.CollectionDialogControls](by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md). They carry no source and are not absorbed into neighboring half-open child ranges. The split preserves every source body and every generated/no-code artifact without making the aggregate or padding an emitter.

[UID:0002B8][0x0069adf0-0x0069adf4.g_pCollectionDialogPane](by-memory/0x0069adf0-0x0069adf4.g_pCollectionDialogPane.md) carries the storage definition for this module's singleton. The related [UID:0000QL][g_pCollectionDialogPane](by-global/g_pCollectionDialogPane.md) page remains the alias/lifecycle support page and should not duplicate the declaration. The definition intentionally uses external linkage under the current split because [UID:0001HF][0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail](by-memory/0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail.md) emits through `CollectionPane.cpp` and checks the singleton before constructing this dialog.

## Boundary Notes

- IDA MCP confirms a compact dialog/control island from `0x0048c640` through `0x0048e305`.
- The preceding functions ending at `0x0048c63f` are not part of the collection dialog.
- Current exact memory documentation separates all 22 half-open children, including ordinary destructor [UID:00010Y][0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor](by-memory/0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor.md), constructor-unwind helper [UID:00010Z][0x0048e140-0x0048e14b.ClearCollectionDialogPaneSingleton](by-memory/0x0048e140-0x0048e14b.ClearCollectionDialogPaneSingleton.md), six adjustors [UID:0004JX][0x0048e14b-0x0048e18d.CollectionDialogControlDestructorAdjustorThunks](by-memory/0x0048e14b-0x0048e18d.CollectionDialogControlDestructorAdjustorThunks.md), and all three scalar-wrapper families.
- 2026-06-16 C001 live IDA refresh confirms current database names for the dialog/private-control island: `CollectionDialogPane_Constructor`, `CollectionDialogPane_OnButtonClick`, `CollectionDialogPane_FindCategoryIndex`, `CollectionEntryControlPane_Constructor`, `CollectionEntryControlPane_OnDraw`, `CollectionEntryControlPane_DrawWrappedText`, `CollectionBarControlPane_Constructor`, `CollectionBarControlPane_OnPaint`, `CollectionBarControlPane_DrawProgressLabel`, `ClearCollectionDialogPaneSingleton`, and `CollectionDialogPane_ScalarDeletingDestructor`.
- 2026-05-25 IDA MCP recheck confirmed exact pages for the omitted entry-control destructor at `0x0048d480-0x0048d49f` and singleton clear helper at `0x0048e140-0x0048e14b`.
- Tiny thunks at `0x0048e14b`, `0x0048e156`, `0x0048e161`, `0x0048e16c`, `0x0048e177`, and `0x0048e182` are compiler/vtable adjustors, not feature behavior.
- The 2026-06-13 raw-offset handoff remains binary evidence, but emitted source now uses [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md): `g_pUserPane->GetCollectionData()`, `groupCount`, `groups[groupIndex].groupType`, `totalEntries`, and `entries[index].collectedFlag`. It preserves the trusted packet length, 32-byte local buffer, no-clamp copy/index behavior, and branch-specific loaded-group write without exposing `g_pUserPane` byte offsets, strides, or byte-index casts.
- The private controls consume the same corrected records: [UID:00002W][CollectionEntryControlPane](by-class/CollectionEntryControlPane.md) reads the three entry-local `SimpleUString` fields at record `+0x18/+0x00/+0x30`, while [UID:00002U][CollectionBarControlPane](by-class/CollectionBarControlPane.md) reads total/collected bytes at group header `+0x02/+0x03` (`+0x3eca/+0x3ecb` absolute).
- `CollectionEntryControlPane` destructor ownership stays in this file's private detail-control cluster: ordinary destructor `0x0048d480`, scalar deleting destructor `0x0048e2b0`, and adjustors `0x0048e177/0x0048e182` all restore/use the `0x00616590`, `0x006165f8`, and `0x00616628` vtable views and route base cleanup to `Pane` teardown `0x00544580`. Do not move this destructor evidence to `CollectionPane.cpp`, `Pane.cpp`, or `TextButtonExControlPane.cpp`.
- 2026-06-21 B010 source-quality reanalysis resolves the private entry-control source shape without changing the file owner: `CollectionEntryControlPane` caches its selected group/entry bytes, formats per-volume `CLTVOL%d.EPF` and `CLTVOL%d.PAL` strings into 128-wide-character buffers, and uses virtual `OnDraw` plus a private wrapped-text helper to render collection entry records. The historical `class_CollectionEntryControlPane.cpp` generated filename remains useful for searching only; current ownership stays in this dialog source unit. The possible fold into [UID:0000IC][CollectionPane](by-file/CollectionPane.md) remains a historical source-layout caveat, not a reason to move the direct owner/emitter.
- The 2026-07-04 B006 singleton storage pass confirmed the exact storage carrier [UID:0002B8][0x0069adf0-0x0069adf4.g_pCollectionDialogPane](by-memory/0x0069adf0-0x0069adf4.g_pCollectionDialogPane.md) is source-ready through this file. MCP session `ddf5b602` was healthy when that evidence was collected and reported no function/name row at `0x0069adf0`, zero-filled storage/value, exact eight lifecycle/consumer xrefs, no extra `F0 AD 69 00` pointer-pattern route, and clean predecessor/successor singleton boundaries. Keep `CollectionPane` as a consumer/checker, not the owner.

## Resource Evidence

The dialog/control classes are tied to the collection UI resource family:

- `DLGCLT.EPF` / `DLGCLT.PAL`
- `CLTNAME.EPF` / `CLTNAME.PAL`
- `CLTBAR.EPF` / `CLTBAR.PAL`
- `CLTENTRY.EPF` / `CLTENTRY.PAL`
- `CLTICON.EPF` / `CLTICON.PAL`
- `CLTVOL%d.EPF` / `CLTVOL%d.PAL`
- `FONTSYMB.EPF` / `FONTSYMB.PAL`

See [UID:0001R8][collection-ui-resources](by-resource/collection-ui-resources.md).

The current `.rdata` island [UID:000250][0x006164f0-0x006168d0.CollectionReadOnlyData](by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md) records the exact RTTI/vtable and UTF-16 resource-string addresses. IDA MCP on 2026-06-05 confirms this data begins with the `CollectionDialogPane` RTTI locator at `0x006164f0`, not at the previous `0x006164f4` page boundary.

## Migration Notes

Use one `NexusTK/ui/dialogs/CollectionDialogPane.cpp` source unit and attach both private controls there. A possible historical header or project grouping with [UID:0000IC][CollectionPane](by-file/CollectionPane.md) remains provenance only; it is not a source-route blocker and does not authorize generated `class_*.cpp` output or a second implementation file.

## Cross-References

- [UID:0000IC][CollectionPane](by-file/CollectionPane.md)
- [UID:00002V][CollectionDialogPane](by-class/CollectionDialogPane.md)
- [UID:00002W][CollectionEntryControlPane](by-class/CollectionEntryControlPane.md)
- [UID:00002U][CollectionBarControlPane](by-class/CollectionBarControlPane.md)
- [UID:00010X][0x0048c640-0x0048e305.CollectionDialogControls](by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md)
- [UID:00010Y][0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor](by-memory/0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor.md)
- [UID:00010Z][0x0048e140-0x0048e14b.ClearCollectionDialogPaneSingleton](by-memory/0x0048e140-0x0048e14b.ClearCollectionDialogPaneSingleton.md)
- [UID:000250][0x006164f0-0x006168d0.CollectionReadOnlyData](by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md)
- [UID:0000QL][g_pCollectionDialogPane](by-global/g_pCollectionDialogPane.md)
- [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md)
- [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:82`.
  - Summary/evidence: dialog/private-control grouping, compact memory island, omitted helper/destructor bodies, resource family, singleton global, migration commands, and companion file relationship are documented; confidence is below maximum only because final source naming/folder placement may fold into `CollectionPane.cpp`.
- 2026-06-05 path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, leaving the file row in error state.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `CollectionDialogPane.cpp` under `ui/dialogs`; live IDA MCP xrefs to [UID:0000QL][g_pCollectionDialogPane](by-global/g_pCollectionDialogPane.md) confirm the singleton lifecycle is owned by this dialog island.
- 2026-06-05 read-only data cross-reference:
  - What existed before: the file page listed the resource family but did not link the exact `.rdata` island, and still used older synthetic container wording.
  - Changed to: added [UID:000250][0x006164f0-0x006168d0.CollectionReadOnlyData](by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md) as source-declared/generated-binary data for this file and removed the stale synthetic-container wording from the edited sections.
  - Summary/evidence: IDA MCP byte/name/string/xref review on 2026-06-05 confirms the corrected `0x006164f0` RTTI start, the collection dialog/control vtable views, and the collection resource string cluster.
- 2026-06-13 collection-data evidence update:
  - What existed before: the page grouped the dialog island but did not describe the dialog's entry-state bit writes or the corrected entry-record layout used by its private controls.
  - Changed to: `COMPLETION:85` and `CONFIDENCE:86`, with boundary notes covering singleton checks/writes, group lookup, total/collected readers, packet-bit entry-state writes, and the link to [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md).
  - Summary/evidence: live IDA MCP confirmed `0x0048c640`, `0x0048d190`, `0x0048d3a0`, `0x0048d4a0`, and `0x0048dc30` all consume the same `g_pCollectionData` group/entry layout.
- 2026-06-16 C001 IDA/name refresh:
  - Before: `85/86`, with behavior and source grouping documented but stale IDA function names and a still-brief support-memory evidence row.
  - After: `86/88`, preserving `NexusTK/ui/dialogs/` and the CollectionPane fold caveat.
  - Summary/evidence: live IDA reconfirmed the compact `0x0048c640-0x0048e305` island, three external constructor callers, vtable-store/data refs for the dialog/private controls, eight `g_pCollectionDialogPane` xrefs, resource-family `.rdata` boundary, and the unresolved no-xref page-step blocks. C001 applied and saved conservative IDA names for eleven collection dialog/control functions; no class layout/type/member edits were safe because final field names and source-facing helper signatures remain open.
- 2026-06-16 B001 destructor-family support update:
  - Summary/evidence: source-quality review kept the `CollectionEntryControlPane` destructor family in this private dialog-control file, corrected the base cleanup target to shared `Pane` teardown `0x00544580`, and documented the no-direct-route ordinary destructor plus scalar/adjustor vtable route.
- 2026-06-20 B001 Rule 26 read-only-data incorporation:
  - Summary/evidence: [UID:000250][0x006164f0-0x006168d0.CollectionReadOnlyData](by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md) now emits source-level file-local constants for the dialog/control resource strings while leaving MSVC RTTI, complete-object-locator, and vtable cells to be regenerated from the class declarations. This keeps source placement in `NexusTK/ui/dialogs/CollectionDialogPane.cpp` and rejects a raw vtable-data emission model.
- 2026-06-21 B010 private entry-control incorporation:
  - Summary/evidence: added the resolved `CollectionEntryControlPane` constructor signature, object size, local field/buffer offsets, virtual `OnDraw` role, private `DrawWrappedText` role, vtable route, and shared GrafPort/text dependency boundary. The source path remains `NexusTK/ui/dialogs/CollectionDialogPane.cpp`; the `CollectionPane.cpp` fold remains only a placement caveat because direct constructor/resource/vtable evidence still favors this dialog file.
- 2026-07-04 B006 singleton storage incorporation:
  - Summary/evidence: added [UID:0002B8][0x0069adf0-0x0069adf4.g_pCollectionDialogPane](by-memory/0x0069adf0-0x0069adf4.g_pCollectionDialogPane.md) as the exact source-emitting storage carrier for `CollectionDialogPane *g_pCollectionDialogPane;`, while [UID:0000QL][g_pCollectionDialogPane](by-global/g_pCollectionDialogPane.md) stays the alias/support page. MCP session `ddf5b602` confirms exact storage, eight xrefs, no extra pointer route, and external-linkage rationale under the current separate `CollectionPane.cpp` consumer route.
- 2026-07-13 B004 UID00010X split callback: raised from `86/88` to `90/91` and replaced broad route descriptions with the complete 22-child exact inventory.
  - Source route: `NexusTK/ui/dialogs/CollectionDialogPane.cpp` owns the dialog, both private controls, exact source children, singleton storage, and file-local resource constants; RTTI/vtables, EH cleanup, adjustors, and deleting wrappers remain compiler-generated.
  - Preserved evidence: singleton constants/resources, external `CollectionPane` consumer, all historical names/callers, typed packet behavior, no-clamp and branch-loaded semantics, retained no-route methods, explicit newline consumption, zero-total division, all 19 padding gaps, rejected generated-class-file authority, and historical placement caveats.
