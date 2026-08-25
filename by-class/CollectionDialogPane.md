*** UID:00002V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class CollectionDialogPane : public DialogPane
{
public:
    CollectionDialogPane(const unsigned char *packet, unsigned char groupVolumeId);
    virtual ~CollectionDialogPane();

    virtual void OnControlCommand(int controlIndex, int notifyCode);

protected:
    virtual void SetHoverControl(int controlId);

private:
    signed char FindCategoryIndex() const;
    void NextPage();
    void PreviousPage();

    unsigned char m_groupVolumeId;
    signed char m_stateByteCount;
    unsigned char m_reservedState;
    signed char m_currentPage;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CollectionDialogPane

## Status

- Likely source file: [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- Address range: [UID:00010X][0x0048c640-0x0048e305.CollectionDialogControls](by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md)
- Historical recovered class filename: `class_CollectionDialogPane.cpp`; this generated name is provenance, not source-file authority.
- Confidence: strong; the UID00010X split resolves the complete declaration, exact source children, compiler-only children, vtable anchors, singleton lifetime, typed collection-data access, and retained no-direct-xref history for the page methods.

## Class Purpose

`CollectionDialogPane` displays one collection group's detail view. It builds a fixed 668x468 dialog, adds next/previous/OK buttons, shows a collection name image, creates a progress bar control, creates six entry controls, pages through entries, and clears [UID:0000QL][g_pCollectionDialogPane](by-global/g_pCollectionDialogPane.md) / exact storage [UID:0002B8][0x0069adf0-0x0069adf4.g_pCollectionDialogPane](by-memory/0x0069adf0-0x0069adf4.g_pCollectionDialogPane.md) on destruction.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `CollectionDialogPane` | [UID:0004JE][0x0048c640-0x0048cf75.CollectionDialogPaneConstructor](by-memory/0x0048c640-0x0048cf75.CollectionDialogPaneConstructor.md) `0x0048c640-0x0048cf75` | Constructs local or network-backed dialog, performs trusted packet-bit decoding without a clamp, builds child controls, and sets the branch-specific loaded flag. |
| constructor-unwind cleanup | [UID:0004JF][0x0048cf80-0x0048cfaa.CollectionDialogPaneConstructorUnwindCleanup](by-memory/0x0048cf80-0x0048cfaa.CollectionDialogPaneConstructorUnwindCleanup.md) `0x0048cf80-0x0048cfaa` | Compiler-generated EH cleanup; no handwritten source body. |
| `OnControlCommand` | [UID:0004JG][0x0048cfb0-0x0048d17e.CollectionDialogPaneOnControlCommand](by-memory/0x0048cfb0-0x0048d17e.CollectionDialogPaneOnControlCommand.md) `0x0048cfb0-0x0048d17e` | Handles previous, close, and next actions. |
| `SetHoverControl` | [UID:0004JH][0x0048d180-0x0048d183.CollectionDialogPaneSetHoverControlNoOp](by-memory/0x0048d180-0x0048d183.CollectionDialogPaneSetHoverControlNoOp.md) `0x0048d180-0x0048d183` | Intentional no-op virtual override. |
| `FindCategoryIndex` | [UID:0004JI][0x0048d190-0x0048d1ce.CollectionDialogPaneFindCategoryIndex](by-memory/0x0048d190-0x0048d1ce.CollectionDialogPaneFindCategoryIndex.md) `0x0048d190-0x0048d1ce` | Finds the selected category in the typed collection player-data view. |
| `NextPage` | [UID:0004JJ][0x0048d1d0-0x0048d2c7.CollectionDialogPaneNextPageRaw](by-memory/0x0048d1d0-0x0048d2c7.CollectionDialogPaneNextPageRaw.md) `0x0048d1d0-0x0048d2c7` | Retained source method that advances the six-entry page and updates controls; historical no-direct-route evidence remains documented. |
| `PreviousPage` | [UID:0004JK][0x0048d2d0-0x0048d39f.CollectionDialogPanePreviousPageRaw](by-memory/0x0048d2d0-0x0048d39f.CollectionDialogPanePreviousPageRaw.md) `0x0048d2d0-0x0048d39f` | Retained source method that moves back one page and updates controls; historical no-direct-route evidence remains documented. |
| constructor-unwind singleton clear | [UID:00010Z][0x0048e140-0x0048e14b.ClearCollectionDialogPaneSingleton](by-memory/0x0048e140-0x0048e14b.ClearCollectionDialogPaneSingleton.md) `0x0048e140-0x0048e14b` | Compiler-generated singleton rollback covered by constructor/destructor source; non-emitting. |
| destructor adjustors | [UID:0004JX][0x0048e14b-0x0048e18d.CollectionDialogControlDestructorAdjustorThunks](by-memory/0x0048e14b-0x0048e18d.CollectionDialogControlDestructorAdjustorThunks.md) `0x0048e14b-0x0048e18d` | Compiler-generated `this` adjustors shared by the three collection controls; no handwritten bodies. |
| normal destructor / scalar wrapper | [UID:0004JZ][0x0048e250-0x0048e2af.CollectionDialogPaneScalarDeletingDestructor](by-memory/0x0048e250-0x0048e2af.CollectionDialogPaneScalarDeletingDestructor.md) `0x0048e250-0x0048e2af` | Source destructor clears the singleton; the deleting wrapper is compiler-generated. |

The 2026-06-16 C001 IDA DB names are historical evidence for the constructor, command handler, category lookup, cleanup helper, and scalar wrapper. The focused 2026-07-13 split audit resolves the source-facing command name as `OnControlCommand`, the no-op slot as `SetHoverControl`, and both page blocks as retained source methods. Their historical absence from the function table and direct-start xrefs is preserved as negative evidence; matching prologues, typed control/data behavior, bounded code, and symmetric page semantics justify source restoration without claiming a proven call edge.

## Data And Globals

- Owns [UID:0002B8][0x0069adf0-0x0069adf4.g_pCollectionDialogPane](by-memory/0x0069adf0-0x0069adf4.g_pCollectionDialogPane.md) as the exact source-emitting storage carrier for `CollectionDialogPane *g_pCollectionDialogPane;`; [UID:0000QL][g_pCollectionDialogPane](by-global/g_pCollectionDialogPane.md) is the global alias/lifecycle support page.
- Reads the [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md) typed feature view through `g_pUserPane->GetCollectionData()`. [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) remains a historical alias of that in-object storage, not a second global object.
- Uses `g_screenWidth`, `g_screenHeight`, `g_pTopMostPane`, and `g_dialogLayoutSentinel` for modeless dialog placement/showing.
- 2026-06-16 live IDA xrefs confirm eight references to [UID:0000QL][g_pCollectionDialogPane](by-global/g_pCollectionDialogPane.md): constructor guard/store sites, scalar-destructor cleanup, the singleton clear helper, and external open helpers at `0x00508cc2`, `0x00514500`, and `0x0056fd15`.
- 2026-07-04 B006 MCP session `ddf5b602` reconfirmed the exact storage facts for [UID:0002B8][0x0069adf0-0x0069adf4.g_pCollectionDialogPane](by-memory/0x0069adf0-0x0069adf4.g_pCollectionDialogPane.md): `0x0069adf0` is not a function, has zero-filled storage/value, has no explicit IDA user global/name row, has the same exact eight refs, has no extra `F0 AD 69 00` pointer-pattern route beyond those operands, and is cleanly bounded before [UID:0002B9][0x0069adf4-0x0069adf8.g_pConnStatusPane](by-memory/0x0069adf4-0x0069adf8.g_pConnStatusPane.md). The two broader refs at `0x00508cc2` and `0x00514500` remain consumer checks, not ownership proof.

## Vtable Data Notes

- The `0x006164f0-0x0061658c` vtable group in [UID:000250][0x006164f0-0x006168d0.CollectionReadOnlyData](by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md) is declaration-generated data for this class. The first primary slot is `CollectionDialogPane_ScalarDeletingDestructor` at `0x0048e250`; inherited base slots should be described through LObject/Pane/DialogPane/GrafPort docs rather than as collection-local raw `sub_*` helpers.
- Exact primary/secondary/tertiary first-slot routes are now recorded in [UID:000250][0x006164f0-0x006168d0.CollectionReadOnlyData](by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md): primary scalar wrapper `0x0048e250` and adjustors `0x0048e161`/`0x0048e16c`, all regenerated from this declaration and normal virtual destructor. No raw vtable cell or adjustor body is handwritten.

## Cross-References

- [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- [UID:00002W][CollectionEntryControlPane](by-class/CollectionEntryControlPane.md)
- [UID:00002U][CollectionBarControlPane](by-class/CollectionBarControlPane.md)
- [UID:00002X][CollectionPane](by-class/CollectionPane.md)
- [UID:00010Z][0x0048e140-0x0048e14b.ClearCollectionDialogPaneSingleton](by-memory/0x0048e140-0x0048e14b.ClearCollectionDialogPaneSingleton.md)
- [UID:0004JE][0x0048c640-0x0048cf75.CollectionDialogPaneConstructor](by-memory/0x0048c640-0x0048cf75.CollectionDialogPaneConstructor.md)
- [UID:0004JG][0x0048cfb0-0x0048d17e.CollectionDialogPaneOnControlCommand](by-memory/0x0048cfb0-0x0048d17e.CollectionDialogPaneOnControlCommand.md)
- [UID:0004JH][0x0048d180-0x0048d183.CollectionDialogPaneSetHoverControlNoOp](by-memory/0x0048d180-0x0048d183.CollectionDialogPaneSetHoverControlNoOp.md)
- [UID:0004JI][0x0048d190-0x0048d1ce.CollectionDialogPaneFindCategoryIndex](by-memory/0x0048d190-0x0048d1ce.CollectionDialogPaneFindCategoryIndex.md)
- [UID:0004JJ][0x0048d1d0-0x0048d2c7.CollectionDialogPaneNextPageRaw](by-memory/0x0048d1d0-0x0048d2c7.CollectionDialogPaneNextPageRaw.md)
- [UID:0004JK][0x0048d2d0-0x0048d39f.CollectionDialogPanePreviousPageRaw](by-memory/0x0048d2d0-0x0048d39f.CollectionDialogPanePreviousPageRaw.md)
- [UID:0004JZ][0x0048e250-0x0048e2af.CollectionDialogPaneScalarDeletingDestructor](by-memory/0x0048e250-0x0048e2af.CollectionDialogPaneScalarDeletingDestructor.md)

## Changes

- What existed before: the page documented collection detail dialog construction, navigation, singleton handling, globals, and child controls, but metadata was still `0/0`.
- What it was changed to: scores were set to `82/88`.
- Summary and evidence: constructor, button handling, page navigation, singleton clear/destructor, child controls, and placement globals are covered; detailed field names and final source declaration remain below exhaustive.
- 2026-06-05: Marked reconstructable and attached to [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md).
  - Before: `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000IB`.
  - Evidence: live IDA MCP confirms modeled method starts at `0x0048c640`, `0x0048cfb0`, `0x0048d190`, and `0x0048e250`, with callers from `0x00508cf6`, `0x00514529`, and `0x0056fd40`; this class and the parent file both meet the 80% completion/confidence attachment gate.
- 2026-06-05: Removed stale recovered-path and alias provenance wording; refined the page-advance/page-back entries to reflect the live IDA state where those address ranges disassemble as standalone prologue-bearing code blocks but are not current function-table entries and have no direct xrefs.
- 2026-06-16 C001 IDA refresh:
  - Before: `82/88`, with the class behavior documented but stale generated names in IDA, a brief support-memory row, and no current written evidence for the singleton/vtable xref set.
  - After: `86/90`, preserving owner/emitter route through [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md) and leaving final C++ blank.
  - Evidence: live IDA MCP in `c001_midiplayer_rdata_20260615` reconfirmed constructor callers `0x00508cf6`, `0x00514529`, and `0x0056fd40`; vtable-data refs at `0x006164f4`, `0x00616554`, and `0x00616584`; singleton xrefs at `0x0048c686`, `0x0048c68d`, `0x0048cf9f`, `0x0048e140`, `0x0048e278`, `0x00508cc2`, `0x00514500`, and `0x0056fd15`; and the no-function/no-start-xref status for `0x0048d1d0` and `0x0048d2d0`.
  - IDA DB: renamed the five CollectionDialogPane-owned functions listed in Method Notes and saved the IDB. No prototype, struct-member, page-step function-creation, vtable, or type edits were applied because page-step reachability and final field/helper names remain provisional.
- 2026-06-20 B001 Rule 26 read-only-data incorporation:
  - Summary/evidence: added explicit [UID:000250][0x006164f0-0x006168d0.CollectionReadOnlyData](by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md) vtable-generation guidance. The class owns its declaration-generated vtable group and scalar deleting destructor route, but the read-only data target emits only file-local resource constants and must not hand-author RTTI/vtable cells.
- 2026-07-04 B006 singleton storage incorporation:
  - Summary/evidence: [UID:0002B8][0x0069adf0-0x0069adf4.g_pCollectionDialogPane](by-memory/0x0069adf0-0x0069adf4.g_pCollectionDialogPane.md) is now the source-ready exact storage carrier for `CollectionDialogPane *g_pCollectionDialogPane;`, while [UID:0000QL][g_pCollectionDialogPane](by-global/g_pCollectionDialogPane.md) remains an alias/support page. Current MCP session `ddf5b602` confirms no-function storage, zero-filled value, exact eight xrefs, no explicit IDA name/global row, no extra pointer-pattern route, and consumer-only status for the CollectionPane duplicate-open guard.
- 2026-07-13 B004 UID00010X split callback: raised from `86/90` to `90/92` and installed the complete accepted class declaration.
  - Exact additions: constructor signature, `OnControlCommand`, no-op `SetHoverControl` override, typed category lookup, retained `NextPage`/`PreviousPage`, four exact tail fields at `+0x26c..+0x26f`, and the complete source/generated child routes.
  - Preserved evidence: singleton ownership/storage, constructor callers, vtable generation, historical IDA naming, page-block no-route history, generated-filename provenance, resources, external open helpers, and rejection of raw global/offset source.
