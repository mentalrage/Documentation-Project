*** UID:0000IB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# CollectionDialogPane

## Status

- Confidence: strong for grouping the dialog and its two private controls; medium for whether the original source name was `CollectionDialogPane.cpp` or folded into `CollectionPane.cpp`.
- Proposed module folder: `ui/dialogs/` or `ui/panels/`
- Proposed source file: `ui/dialogs/CollectionDialogPane.cpp`
- Companion file: [UID:0000IC][CollectionPane](by-file/CollectionPane.md)
- Evidence basis: generated `Collection*ControlPane` sources, `.meta_wave3`, and IDA MCP boundary/caller checks on 2026-05-24.

## Hypothesis

The collection detail dialog should be one source unit containing `CollectionDialogPane` plus its private progress-bar and entry-slot controls. The generated one-class split is too granular: `CollectionDialogPane::BuildCollectionUI` directly allocates both `CollectionBarControlPane` and six `CollectionEntryControlPane` instances, and those controls draw only `CLT*` collection-dialog assets.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| [UID:00002V][CollectionDialogPane](by-class/CollectionDialogPane.md) | `0x0048c640-0x0048d39e`, destructor `0x0048e250` | `class_CollectionDialogPane.cpp` | Paginated 6-entry collection detail dialog, next/previous button handling, singleton lifecycle. |
| [UID:00002W][CollectionEntryControlPane](by-class/CollectionEntryControlPane.md) | `0x0048d3a0-0x0048dc21`, destructor `0x0048e2b0`, shared GrafPort helpers at `0x004b95e0`, `0x004b9620`, `0x004bab20` | `class_CollectionEntryControlPane.cpp` | One detail-grid entry control. Draws locked/collected states, collection volume sprites, name, short name, and description. |
| [UID:00002U][CollectionBarControlPane](by-class/CollectionBarControlPane.md) | `0x0048dc30-0x0048e243` | `class_CollectionBarControlPane.cpp` | Progress bar and `current/total(percent)` label for the selected collection group. |
| [UID:0000QL][g_pCollectionDialogPane](by-global/g_pCollectionDialogPane.md) | `0x0069adf0` | generated global-data alias | Active detail-dialog singleton guard. |

## Boundary Notes

- IDA MCP confirms a compact dialog/control island from `0x0048c640` through `0x0048e305`.
- The preceding functions ending at `0x0048c63f` are not part of the collection dialog.
- Active Wave3 output omits `0x0048d480`, the non-deleting `CollectionEntryControlPane` destructor body, and `0x0048e140`, the helper that clears `g_pCollectionDialogPane`.
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

## Migration Notes

Use one dialog file and attach the private controls there:

```powershell
python source-3\wave3.py create file CollectionDialogPane.cpp --kind source --simpath ui/dialogs/CollectionDialogPane.cpp --dry-run
python source-3\wave3.py attach class CollectionDialogPane --to-file CollectionDialogPane.cpp --dry-run
python source-3\wave3.py attach class CollectionEntryControlPane --to-file CollectionDialogPane.cpp --dry-run
python source-3\wave3.py attach class CollectionBarControlPane --to-file CollectionDialogPane.cpp --dry-run
```

Review whether final simpath should be `ui/panels/CollectionDialogPane.cpp` if the original project kept collection feature code together under panels instead of dialogs.

## Cross-References

- [UID:0000IC][CollectionPane](by-file/CollectionPane.md)
- [UID:00002V][CollectionDialogPane](by-class/CollectionDialogPane.md)
- [UID:00002W][CollectionEntryControlPane](by-class/CollectionEntryControlPane.md)
- [UID:00002U][CollectionBarControlPane](by-class/CollectionBarControlPane.md)
- [UID:00010X][0x0048c640-0x0048e305.CollectionDialogControls](by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md)
- [UID:00010Y][0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor](by-memory/0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor.md)
- [UID:00010Z][0x0048e140-0x0048e14b.ClearCollectionDialogPaneSingleton](by-memory/0x0048e140-0x0048e14b.ClearCollectionDialogPaneSingleton.md)
- [UID:0000QL][g_pCollectionDialogPane](by-global/g_pCollectionDialogPane.md)
- [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:82`.
  - Summary/evidence: dialog/private-control grouping, compact memory island, omitted helper/destructor bodies, resource family, singleton global, migration commands, and companion file relationship are documented; confidence is below maximum only because final source naming/folder placement may fold into `CollectionPane.cpp`.
