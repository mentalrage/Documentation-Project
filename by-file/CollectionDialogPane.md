*** UID:0000IB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# CollectionDialogPane

## Status

- Confidence: strong for grouping the dialog and its two private controls; medium for whether the original source name was `CollectionDialogPane.cpp` or folded into `CollectionPane.cpp`.
- Proposed module folder: `ui/dialogs/` or `ui/panels/`
- Proposed source file: `ui/dialogs/CollectionDialogPane.cpp`
- Companion file: [UID:0000IC][CollectionPane](by-file/CollectionPane.md)
- Evidence basis: IDA MCP boundary/caller checks, compact address locality, private-control allocation, and collection-dialog resource usage.

## Hypothesis

The collection detail dialog should be one source unit containing `CollectionDialogPane` plus its private progress-bar and entry-slot controls. A one-class split is too granular here: `CollectionDialogPane::BuildCollectionUI` directly allocates both `CollectionBarControlPane` and six `CollectionEntryControlPane` instances, and those controls draw only `CLT*` collection-dialog assets.

## Proposed Contents

| Entity | Current range | Evidence / ownership note | Role |
| --- | --- | --- | --- |
| [UID:00002V][CollectionDialogPane](by-class/CollectionDialogPane.md) | `0x0048c640-0x0048d39e`, destructor `0x0048e250` | Attached class page; live IDA method and vtable evidence place it in this dialog file. | Paginated 6-entry collection detail dialog, next/previous button handling, singleton lifecycle. |
| [UID:00002W][CollectionEntryControlPane](by-class/CollectionEntryControlPane.md) | `0x0048d3a0-0x0048dc21`, destructor `0x0048e2b0`, shared GrafPort helpers at `0x004b95e0`, `0x004b9620`, `0x004bab20` | Attached private control; construction and vtable evidence point back to `CollectionDialogPane`. | One detail-grid entry control. Draws locked/collected states, collection volume sprites, name, short name, and description. |
| [UID:00002U][CollectionBarControlPane](by-class/CollectionBarControlPane.md) | `0x0048dc30-0x0048e243` | Attached private control; construction and vtable evidence point back to `CollectionDialogPane`. | Progress bar and `current/total(percent)` label for the selected collection group. |
| [UID:0000QL][g_pCollectionDialogPane](by-global/g_pCollectionDialogPane.md) | `0x0069adf0` | global-data alias | Active detail-dialog singleton guard. |
| [UID:000250][0x006164f0-0x006168d0.CollectionReadOnlyData](by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md) | `0x006164f0-0x006168d0` | Source-declared/generated-binary `.rdata` attached to this file. | Dialog/control RTTI/vtables plus `DLGCLT`, `CLTNAME`, `CLTVOL`, `CLTENTRY`, `CLTICON`, `CLTBAR`, and font/symbol resource strings. |

## Boundary Notes

- IDA MCP confirms a compact dialog/control island from `0x0048c640` through `0x0048e305`.
- The preceding functions ending at `0x0048c63f` are not part of the collection dialog.
- Current exact memory documentation separates `0x0048d480`, the non-deleting `CollectionEntryControlPane` destructor body, and `0x0048e140`, the helper that clears `g_pCollectionDialogPane`.
- 2026-05-25 IDA MCP recheck confirmed exact pages for the omitted entry-control destructor at `0x0048d480-0x0048d49f` and singleton clear helper at `0x0048e140-0x0048e14b`.
- Tiny thunks at `0x0048e14b`, `0x0048e156`, `0x0048e161`, `0x0048e16c`, `0x0048e177`, and `0x0048e182` are compiler/vtable adjustors, not feature behavior.

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

Use one dialog file and attach the private controls there. Review whether final placement should stay `ui/dialogs/CollectionDialogPane.cpp` or fold into `ui/panels/CollectionPane.cpp` if later evidence proves the original project kept collection feature code together under panels instead of dialogs.

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
