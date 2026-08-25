*** UID:0000CH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ScrolledPictureControlPane : public ControlPane
{
public:
    ScrolledPictureControlPane(
        const RectBounds *bounds,
        const wchar_t *frameResourceName,
        const wchar_t *paletteName,
        int scrollInterval,
        int scrollStep,
        unsigned char scrollDirection);
    virtual ~ScrolledPictureControlPane();
    virtual void OnPaintFrame();
    virtual bool OnTimerEvent(int eventId, int param1, int param2);

private:
    int m_scrollInterval;
    int m_scrollStep;
    unsigned char m_scrollDirection;
    ArchiveMetadataTable *m_frameTable;
    FrameDrawRecord m_frameDrawRecord;
    DLPalette *m_palette;
    RectBounds m_destinationRect;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScrolledPictureControlPane

## Status

- Confidence: very strong for behavior, exact method boundaries/hashes, class/file ownership, three-view vtable model, constructor ABI/types, exact `0x154` layout, source/compiler destructor split, and complete class declaration; exact original spellings/access/header organization and feature construction remain inferred/absent.
- Likely source file: [UID:0000NH][ScrolledPictureControlPane](by-file/ScrolledPictureControlPane.md)
- Main address ranges: `0x004ff7d0-0x004ffa9f`, `0x00502550-0x00502566`, and `0x00502ab0-0x00502b58`

## Class Purpose

`ScrolledPictureControlPane` is a `ControlPane` type `8` image widget that loads an EPF frame, stores palette/frame draw state, and scrolls the image through the control using timer ticks.

## Method Families

| Range | Function | Role |
| --- | --- | --- |
| `0x004ff7d0-0x004ff95e` | constructor | `ControlPane(8, bounds)`, two wide resource names, frame-table/draw-record load, current/named `DLPalette *`, destination rectangle setup, and timer start. |
| `0x004ff970-0x004ff9d7` | ordinary virtual destructor | Sole human destructor body destroys `m_frameTable`; vptr writes and inherited Pane teardown are compiler lowering. |
| `0x004ff9e0-0x004ffa4b` | `OnTimerEvent` | Offset the image rectangle by scroll step/direction, refresh the owner/control region, and schedule the next tick. |
| `0x004ffa60-0x004ffa9f` | `OnPaintFrame` | Fill/prepare the control region and blit the current image frame. |
| `0x00502550-0x00502566` | adjustor thunks | Class-owned non-emitting compiler entries; subtract `0xa0`/`0xa4` and tail-jump to `0x00502ab0`. |
| `0x00502ab0-0x00502b58` | scalar deleting destructor | Class-owned non-emitting compiler clone over ordinary cleanup plus deletion ABI. |

## Evidence Notes

- 2026-06-04 live IDA MCP on `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` confirms `sub_4FF7D0` as `0x004ff7d0-0x004ff95e`, `sub_4FF970` as `0x004ff970-0x004ff9d7`, `sub_4FF9E0` as `0x004ff9e0-0x004ffa4b`, `sub_4FFA60` as `0x004ffa60-0x004ffa9f`, the two `0xb` adjustor thunks at `0x00502550` and `0x0050255b`, and `sub_502AB0` as `0x00502ab0-0x00502b58`.
- Live refs show no direct code/data refs to the constructor or non-deleting destructor starts; timer and paint are vtable-reached at `0x0061d92c` and `0x0061d8d4`, and the scalar deleting destructor has vtable ref `0x0061d890` plus thunk code refs from `0x00502556` and `0x00502561`.
- The constructor calls [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md) helpers `0x004d0f50` and `0x004d1600`, palette helpers `0x00543d70`/`0x00543d40`, rectangle setup `0x004b7c50`, and timer scheduling `0x005975e0`, confirming an EPF/palette picture control rather than text-edit or DAT text rendering.
- `OnTimerEvent` switches on direction `0..3`, offsets the destination rectangle by the scroll step, invalidates/refreshes through the owner/control subobject, and schedules another timer tick.
- `OnPaintFrame` calls the pane fill/prepare helper and render callbacks through `dword_69B3FC` and `dword_69B3E8`, matching frame blitting with palette state.
- Live boundary bytes confirm constructor switch-table support starts after the constructor at `0x004ff95e`, timer switch-table support starts after `0x004ffa4b`, and the paint method's final `retn` is at `0x004ffa9e` with padding at `0x004ffa9f`.
- 2026-06-11 A007 Batch 161 live IDA refresh reconfirmed `0x00502ab0-0x00502b58` as the scalar deleting destructor with vtable ref `0x0061d890`, thunk jumps from `0x00502556`/`0x00502561`, vtable reset stores at `this+0x00/+0xa0/+0xa4`, owned-image cleanup from `this+0x114`, base teardown through `0x00544580`, and guarded delete through `0x004f4ac0`.
- B004 2026-06-18 source-quality recheck resolved the initial field/source blockers for [UID:00019Y][0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore](by-memory/0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore.md). B003 2026-07-14 live session `1feab207` supersedes the remaining draft types: the constructor takes bounds plus two wide resource names, direction is an unsigned byte, and `+0x140` is `DLPalette *m_palette` from current/named PaletteLib helpers rather than historical `m_paletteState`. Constructor reachability remains absent and limits only feature-specific placement, not class ownership or source readiness.

## Exact Layout

The compiler deleting wrapper's flag-4 path pushes object size `0x154`; constructor/timer/paint/destructor offsets close the source declaration exactly:

| Offset / span | Size | Member | Evidence and disposition |
| --- | ---: | --- | --- |
| `+0x000..+0x107` | `0x108` | `ControlPane` base | Base constructor and current ControlPane layout, including inherited three-view facets. |
| `+0x108..+0x10b` | `4` | `int m_scrollInterval` | Constructor store and initial/repeated timer schedule. |
| `+0x10c..+0x10f` | `4` | `int m_scrollStep` | Constructor store and signed timer deltas. |
| `+0x110` | `1` | `unsigned char m_scrollDirection` | Sixth argument and direction switches `0..3`. |
| `+0x111..+0x113` | `3` | natural alignment | Implicit alignment before a 32-bit pointer; no raw padding member. |
| `+0x114..+0x117` | `4` | `ArchiveMetadataTable *m_frameTable` | Loader result; sole destructor cleanup. |
| `+0x118..+0x13f` | `0x28` | `FrameDrawRecord m_frameDrawRecord` | 40-byte ImageFrameTable projection/render record, semantically distinct from `EPFTileContext`. |
| `+0x140..+0x143` | `4` | `DLPalette *m_palette` | `GetPaletteByName`/`GetCurrentPalette` result passed to paint. |
| `+0x144..+0x153` | `0x10` | `RectBounds m_destinationRect` | Constructor off-screen placement, timer movement, and paint destination. |

The declaration order creates exact natural alignment and final size without raw-layout garbage, offset comments, reserved arrays, or a tail-padding field.

## Source And Compiler Boundary

- Source declares one public virtual destructor and defines it in UID00019Y as `DestroyOwnedImageBlock(m_frameTable)`. Public access is the best current class-lifecycle convention; the exact original access token is not encoded and remains an explicit confidence cap.
- UID0001AI is the primary deleting entry and UID0001AD supplies secondary/tertiary receiver adjustments. They remain class-owned documentation but false/blank/non-emitting.
- Vptr stores at complete-object `+0`, secondary `+0xa0`, and tertiary `+0xa4`, explicit inherited `Pane::~Pane`, deletion flags, storage release, SEH/cookie, vtable/RTTI arrays, and return-this ABI are compiler output and must not appear in human C++.
- The class closes before `[[CHILDREN]]`; UID00019Y definitions therefore emit at namespace scope rather than inside the class.
- `FrameDrawRecord` and `EPFTileContext` share size/zero-initialization but carry different fields and consumers. The class keeps the current ImageFrameTable-owned `FrameDrawRecord` type.

## Vtable And Reachability Evidence

- Exact class `.rdata` span is `[0x0061d88c,0x0061d930)`: primary base `0x61d890`, secondary base `0x61d8f8`, tertiary base `0x61d928`, paint `0x61d8d4 -> 0x4ffa60`, and timer `0x61d92c -> 0x4ff9e0`.
- UID0001AI has exactly the primary data ref and two thunk jumps; constructor/ordinary destructor starts have no direct route. This supports retained class code with absent feature construction, not alternative feature ownership.
- Fitting-room, head-selection, text-control, ImageFrameTable, and PaletteLib ownership are rejected. They are polluted labels, sibling classes, or helper consumers; all three vtable views identify `ScrolledPictureControlPane`.

## Data Caveats

- Prior owner labels include fitting-room and head-selection types. Treat those as data pollution until factory/config construction is found.
- The timer method is reached through an owner/subobject adjustment. B004 resolved the owner-relative fields above, but structure migration should still preserve the `this+0xa4` timer-subobject adjustment.
- 2026-05-25 IDA recheck still finds no direct constructor callers for `0x004ff7d0`; `0x00502ab0` is only directly reached by the two thunk starts at `0x00502550` and `0x0050255b`. The generated fitting-room/head-selection labels remain unsafe because IDA decompilation shows generic frame-table, palette, timer, and render-callback behavior.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 91 | The page now has a complete formal declaration, exact constructor/destructor/timer/paint inventory, exact `0x154` layout, source-facing types/names, vtable/adjustor/source-cause evidence, source/compiler boundary, rejected owners, and current score/emitter rationale. |
| Confidence | 93 | Mandatory live MCP and current ControlPane/ImageFrameTable/PaletteLib support agree on the class, layout, types, and virtual destruction model. Exact original names/access/header organization and feature-level constructor route remain unavailable, preventing final-audit confidence. |

## Cross-References

- [UID:0000NH][ScrolledPictureControlPane](by-file/ScrolledPictureControlPane.md)
- [UID:00019Y][0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore](by-memory/0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore.md)
- [UID:0001AD][0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks](by-memory/0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks.md)
- [UID:0001AI][0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor](by-memory/0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor.md)
- [UID:0000CI][ScrolledTextControlPane](by-class/ScrolledTextControlPane.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)
- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-07-14 B003 UID0001AI support callback:
  - Raised scores from `85/88` to `91/93`; preserved canonical owner/emitter UID0000NH, `RECONSTRUCTABLE:TRUE`, and blank optional position.
  - Inserted the accepted complete class declaration with bounds/wide-resource constructor, one public virtual destructor, timer/paint overrides, exact member order, class close, and `[[CHILDREN]]` at namespace scope.
  - Added exact `0x154` layout, natural alignment, `DLPalette *m_palette`, distinct `FrameDrawRecord`, source/compiler destructor split, three-view vtable routes, negative ownership evidence, and score/name/access caps.
  - Historicalized stale blank-C++, provisional-field blocker, and `m_paletteState` wording while preserving all prior behavior, range, callee, and constructor-reachability evidence.

- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and assigned parent `0000NH`.
  - Before: The EPF picture scroller remained unclassified in autogen coverage even though the class and parent file both met the 80/80 attach gate.
  - After: The class contributes to `ScrolledPictureControlPane.cpp` as a reconstructable child without emitting final C++ yet.
  - Evidence: Live IDA MCP lookup confirms constructor/destructor/timer/paint starts at `0x004ff7d0`, `0x004ff970`, `0x004ff9e0`, `0x004ffa60`, adjustor thunks at `0x00502550` and `0x0050255b`, and scalar deleting destructor `0x00502ab0`; parent [UID:0000NH][ScrolledPictureControlPane](by-file/ScrolledPictureControlPane.md) records the same EPF/palette control ownership.

- 2026-05-30: Changed completion/confidence from `0/0` to `76/76`.
  - Before: The page was unevaluated despite documenting image scrolling behavior, constructor/destructor/timer/paint ranges, destructor thunks, and generated-owner pollution.
  - After: Scored as moderate-high completion and confidence because behavior is strong, while field names and final caller/feature owner remain unresolved.
  - Evidence: Existing method-family table, IDA evidence notes, data caveats, and image/control cross-references support the score.
- 2026-06-04: Changed completion/confidence from `76/76` to `84/88`.
  - Before: The page had a useful function map but stale generated-source wording, final-byte-style method ends, and limited caller/vtable/callee evidence.
  - After: Scored higher because live IDA confirms exact half-open method extents, vtable refs, thunk targets, callee set, switch-table boundaries, scalar deleting destructor behavior, and source-file ownership through the refreshed core memory page.
  - Remaining uncertainty: final C++ stays blank because field names, construction/factory path, and base teardown naming are not proven to the 95/95 reconstruction bar.
- 2026-06-11 A007 Batch 161: Raised completion from `84` to `85` after the live destructor refresh filled the parent-side blocker for [UID:0001AI][0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor](by-memory/0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor.md). The class now clears the strict `85/85` gate while final C++ remains blank due provisional field names, construction/factory path, and base teardown naming.
- 2026-06-18 B004 source-quality sync: [UID:00019Y][0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore](by-memory/0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore.md) now owns first-draft class C++ and a resolved descriptive field map. Constructor route remains unresolved only for feature placement.
