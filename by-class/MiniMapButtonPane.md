*** UID:00008B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// MiniMapButtonPane class declaration is intentionally withheld: constructor,
// destructor, paint, mouse, singleton, and vtable routes are documented, but
// inherited base spellings, hover/down fields, tile-context ownership, and
// click-dispatch names are not source-quality yet.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MiniMapButtonPane

## Status

- Confidence: strong for class behavior, singleton handling, IDA starts, child-page boundaries, and current MiniMap parent attachment; high enough for the strict 85/85 gate, with the exact original source-unit split still open.
- Attached source file: [UID:0000LE][MiniMap](by-file/MiniMap.md)
- Address range: [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md)
- Parent attachment: [UID:0000LE][MiniMap](by-file/MiniMap.md) is now `85/86`, and this class is `85/86`, so the strict 85/85 attachment gate is met while preserving the final split caveat.

## Class Purpose

`MiniMapButtonPane` is the small in-game minimap button created by [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) in the newer layout. It initializes a pane/tile context, paints `MMAPBUT.EPF` with `FRMPART.PAL`, tracks mouse hover/down state, dispatches a click handler, and clears [UID:0000RN][g_pMiniMapButtonPane](by-global/g_pMiniMapButtonPane.md) during teardown.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x00503580-0x0050361d` | Constructs `Pane`, stores `g_pMiniMapButtonPane`, installs vtables, initializes an `EPFTileContext`, and clears state fields. |
| cleanup / ordinary destructor | [UID:0001AM][0x00503620-0x00503649.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503649.MiniMapButtonPaneCleanup.md) | Source-facing `MiniMapButtonPane::~MiniMapButtonPane()` body. The first-draft C++ only clears `g_pMiniMapButtonPane`; vtable restores and base cleanup are compiler/base output. |
| `OnPaint` | `0x00503650-0x00503691` | Loads `MMAPBUT.EPF` frame data and renders it with `FRMPART.PAL`. |
| `OnMouseEvent` | `0x005036a0-0x005037ec` | Handles hover, press, release, state repaint, and click dispatch. |
| singleton clear helper | [UID:00040L][0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton](by-memory/0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton.md) | Exact helper that clears `g_pMiniMapButtonPane`; first-draft descriptive source name is `MiniMapButtonPane::ClearSingleton()` with file-local/static spelling still possible. |
| adjustor thunks | [UID:00040M][0x00503821-0x00503837.MiniMapButtonPaneDestructorAdjustorThunks](by-memory/0x00503821-0x00503837.MiniMapButtonPaneDestructorAdjustorThunks.md) | MiniMapButtonPane destructor adjustors at `0x00503821-0x0050382c` and `0x0050382c-0x00503837`; compiler-generated wrappers forwarding to `0x00503900`. |
| scalar deleting destructor | [UID:00040N][0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor](by-memory/0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor.md) | Compiler-generated deleting destructor wrapper with delete-flag/conditional-free behavior; source destructor is [UID:0001AM][0x00503620-0x00503649.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503649.MiniMapButtonPaneCleanup.md). |

## Boundary Notes

- IDA `callers 0x00503580` reports one constructor caller from `InitializeMainUiGraph` at `0x004f80c2`.
- The local code island is interleaved with [UID:00007P][MapNamePane](by-class/MapNamePane.md): `MapNamePane` owns `0x005031f0`, `0x005032d0`, `0x00503350`, `0x0050380b`, `0x00503816`, and `0x00503840`, while `MiniMapButtonPane` owns `0x00503580`, `0x00503620`, `0x00503650`, `0x005036a0`, `0x00503800`, `0x00503821`, `0x0050382c`, and `0x00503900`.
- The older [UID:0001AK][0x005031f0-0x005038fe.MapNamePane](by-memory/0x005031f0-0x005038fe.MapNamePane.md) is retained as a non-emitting MapNamePane split index, but the shared island doc is the safer migration anchor for mixed MapNamePane/MiniMapButtonPane bytes.

## Evidence Notes

- [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md) records the per-method split, exact padding spans, the single constructor caller from [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md), and `xrefs_to 0x0069b4b8` confirming constructor, cleanup, and destructor singleton writes/clears.
- [UID:0001AM][0x00503620-0x00503649.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503649.MiniMapButtonPaneCleanup.md) ties the cleanup body to MiniMapButtonPane vtables at receiver offsets `0`, `0xa0`, and `0xa4`, the `g_pMiniMapButtonPane` zero write, and the tail transfer to shared pane cleanup at `0x00544580`.
- [UID:0001AN][0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks](by-memory/0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks.md) is now a non-emitting split/index over the exact singleton-clear child [UID:00040L][0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton](by-memory/0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton.md), the already-split MapNamePane adjustor thunks [UID:0003XL][0x0050380b-0x00503821.MapNamePaneDestructorAdjustorThunks](by-memory/0x0050380b-0x00503821.MapNamePaneDestructorAdjustorThunks.md), and the MiniMapButtonPane adjustor-thunk child [UID:00040M][0x00503821-0x00503837.MiniMapButtonPaneDestructorAdjustorThunks](by-memory/0x00503821-0x00503837.MiniMapButtonPaneDestructorAdjustorThunks.md).
- [UID:00040N][0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor](by-memory/0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor.md) preserves the compiler-generated scalar deleting destructor wrapper; its source replacement is the ordinary destructor child [UID:0001AM][0x00503620-0x00503649.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503649.MiniMapButtonPaneCleanup.md).
- [UID:00025R][0x0061e5b4-0x0061e704.MapNameMiniMapButtonReadOnlyData](by-memory/0x0061e5b4-0x0061e704.MapNameMiniMapButtonReadOnlyData.md) provides the MiniMapButtonPane vtable and map/minimap resource-string evidence; [UID:00029X][0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals](by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md) names the singleton storage slot at `0x0069b4b8`.
- 2026-06-11 A003 Batch 163 live IDA recheck reconfirmed the constructor at `0x00503580-0x0050361e` with caller `0x004f80c2`, cleanup at `0x00503620-0x00503649`, paint at `0x00503650-0x00503692`, mouse/interaction handler at `0x005036a0-0x005037ed`, singleton clear/thunks at `0x00503800-0x00503837`, and scalar deleting destructor at `0x00503900-0x0050395f`. `g_pMiniMapButtonPane` refs stay localized to constructor/cleanup/destructor paths plus the external reader at `0x00504a54`, and the MiniMapButtonPane vtable/resource data remains tied to [UID:00025R][0x0061e5b4-0x0061e704.MapNameMiniMapButtonReadOnlyData](by-memory/0x0061e5b4-0x0061e704.MapNameMiniMapButtonReadOnlyData.md).
- 2026-06-12 A002 Batch 325 split ties the paint/resource path xref at `0x0050366c` to exact UTF-16 `MMAPBUT.EPF` child [UID:0003IM][0x0061e6d8-0x0061e6f0.MiniMapButtonPaneEpfResourceString](by-memory/0x0061e6d8-0x0061e6f0.MiniMapButtonPaneEpfResourceString.md), now assigned here after both child and direct class parent cleared the strict `85/85` gate. The containing [UID:0003C1][0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings](by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md) page remains parentless because the same physical span also contains MapName, MapPane, LivingObjectPane, and ObjectList literals.

## Source Placement

The class is attached to [UID:0000LE][MiniMap](by-file/MiniMap.md) because both parent and child clear the strict 85/85 gate, and the singleton, vtable, resource, and button-art evidence belongs to the minimap source family. The exact original unit remains open: the class may have lived in a compact `MiniMap.cpp` or a focused minimap control source, while `ui/MainUiGraph.cpp` should cross-reference construction but not own the class.

## B010 Declaration-Shell Audit

Current MCP-backed evidence supports a class-index marker with `[[CHILDREN]]`, not a declaration shell. MiniMapButtonPane has three vtable views at `0x0061e63c`, `0x0061e688`, and `0x0061e6b8`, and current xrefs confirm three refs to each. The constructor range is `0x00503580-0x0050361d` with one caller from [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md). The ordinary destructor is already emitted by [UID:0001AM][0x00503620-0x00503649.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503649.MiniMapButtonPaneCleanup.md); [UID:00040M][0x00503821-0x00503837.MiniMapButtonPaneDestructorAdjustorThunks](by-memory/0x00503821-0x00503837.MiniMapButtonPaneDestructorAdjustorThunks.md) and [UID:00040N][0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor](by-memory/0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor.md) remain compiler glue.

Known child inventory is constructor, ordinary destructor, `OnPaint`, `OnMouseEvent`, [UID:00040L][0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton](by-memory/0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton.md), adjustor thunks, and scalar deleting destructor. A monolithic class declaration is not emitted in this callback because secondary/tertiary inherited base spellings, hover/down state fields, tile-context member type, and the exact click-dispatch target are not source-quality. Exact source-bearing child pages carry bodies when accepted; this class page now emits only the formal class-index marker.

## Source-Quality Split

B005's 2026-06-20 Rule 26 report resolves the cleanup/thunk cluster policy:

- [UID:0001AM][0x00503620-0x00503649.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503649.MiniMapButtonPaneCleanup.md) is the ordinary source destructor body and now emits first-draft destructor C++ with only `g_pMiniMapButtonPane = NULL;`.
- [UID:00040L][0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton](by-memory/0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton.md) is the exact singleton-clear helper. `MiniMapButtonPane::ClearSingleton()` is the best current source-facing name; exact original static/free spelling remains open.
- [UID:00040M][0x00503821-0x00503837.MiniMapButtonPaneDestructorAdjustorThunks](by-memory/0x00503821-0x00503837.MiniMapButtonPaneDestructorAdjustorThunks.md) and [UID:00040N][0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor](by-memory/0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor.md) are compiler-generated destructor glue. The class declaration/destructor should regenerate them; they must not be hand-authored as source C++.
- [UID:0001AN][0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks](by-memory/0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks.md) is an index only and must not emit through MiniMap because it also contains MapNamePane-owned thunk bytes.

## Current-Pass Class Declaration Exclusions

- [UID:00040L][0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton](by-memory/0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton.md) remains an exact singleton-clear child/helper candidate; source spelling is `MiniMapButtonPane::ClearSingleton()` or file-local helper only after a split callback, not from this class index.
- Secondary/tertiary base names, hover/down field names, tile-context ownership, and click-dispatch target names block a class declaration shell in this callback.
- Destructor adjustor thunks and scalar deleting destructor glue are compiler-generated and must remain non-emitting; this item is closed as a no-code policy, not future research.

## Cross-References

- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:0000RN][g_pMiniMapButtonPane](by-global/g_pMiniMapButtonPane.md)
- [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md)
- [UID:0001AM][0x00503620-0x00503649.MiniMapButtonPaneCleanup](by-memory/0x00503620-0x00503649.MiniMapButtonPaneCleanup.md)
- [UID:0001AN][0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks](by-memory/0x00503800-0x00503837.MiniMapButtonPaneClearAndThunks.md)
- [UID:00040L][0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton](by-memory/0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton.md)
- [UID:00040M][0x00503821-0x00503837.MiniMapButtonPaneDestructorAdjustorThunks](by-memory/0x00503821-0x00503837.MiniMapButtonPaneDestructorAdjustorThunks.md)
- [UID:00040N][0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor](by-memory/0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor.md)
- [UID:00025R][0x0061e5b4-0x0061e704.MapNameMiniMapButtonReadOnlyData](by-memory/0x0061e5b4-0x0061e704.MapNameMiniMapButtonReadOnlyData.md)
- [UID:0003IM][0x0061e6d8-0x0061e6f0.MiniMapButtonPaneEpfResourceString](by-memory/0x0061e6d8-0x0061e6f0.MiniMapButtonPaneEpfResourceString.md)
- [UID:0003C1][0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings](by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md)
- [UID:00029X][0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals](by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md)
- [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md)

## Changes

- 2026-06-30 B010 empty-emitter implementation callback:
  - Raised `85/86` to `86/88`, inserted the accepted formal class-index marker with `[[CHILDREN]]`, added the MCP-backed declaration-shell audit, and converted open questions into current-pass declaration exclusions/no-code policy.
- 2026-06-20 Rule 26 incorporation from B005 report: synced class method inventory and source-quality split policy after exact MiniMapButtonPane children [UID:00040L][0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton](by-memory/0x00503800-0x0050380b.MiniMapButtonPaneClearSingleton.md), [UID:00040M][0x00503821-0x00503837.MiniMapButtonPaneDestructorAdjustorThunks](by-memory/0x00503821-0x00503837.MiniMapButtonPaneDestructorAdjustorThunks.md), and [UID:00040N][0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor](by-memory/0x00503900-0x0050395f.MiniMapButtonPaneScalarDeletingDestructor.md) were created. Removed stale filename warnings and stale `95/95` no-code framing; unresolved work is now limited to helper spelling, final class declaration/base layout, and remaining field/click-dispatch names, not thunk/source policy.
- 2026-06-11 A003 Batch 163: Raised from `82/82` to `85/86` while keeping parent [UID:0000LE][MiniMap](by-file/MiniMap.md). Evidence: live IDA reconfirmed constructor caller, cleanup/clear/thunk/scalar-destructor children, paint and mouse handlers, vtable/resource-data anchors, `g_pMiniMapButtonPane` lifecycle refs, the shared MapName/MiniMap island split, and final source-unit caveats under the strict 85/85 gate.
- 2026-06-12 A001 Batch 271: Added exact `MMAPBUT.EPF` resource-string evidence from [UID:0003C1][0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings](by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md). Score and parent unchanged because the class already clears the strict gate while the exact string child is mixed.
- 2026-06-12 A002 Batch 325: Updated the broad string reference to exact child [UID:0003IM][0x0061e6d8-0x0061e6f0.MiniMapButtonPaneEpfResourceString](by-memory/0x0061e6d8-0x0061e6f0.MiniMapButtonPaneEpfResourceString.md), which is assigned to this class. Score unchanged at `85/86`; the class already cleared the direct-parent gate.
- 2026-06-06: Raised from `80/78` to `82/82`, attached parent [UID:0000LE][MiniMap](by-file/MiniMap.md), removed stale generated-output provenance, and added child-page-backed evidence for singleton storage, vtables, cleanup, clear/thunk ownership, stale child filename caveats, and the remaining source-unit split.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed constructor/cleanup/paint/mouse/singleton-clear/thunk/destructor starts at `0x00503580`, `0x00503620`, `0x00503650`, `0x005036a0`, `0x00503800`, `0x00503821`, `0x0050382c`, and `0x00503900`. Left `AUTOGEN_PARENT_UID` blank because this class confidence is below 80 and the likely parent [UID:0000LE][MiniMap](by-file/MiniMap.md) is below the 80 completion attachment gate.
- 2026-05-28: Corrected the scalar deleting destructor range from `0x00503900-0x0050395e` to `0x00503900-0x0050395f`. Evidence: IDA MCP reports the function end at `0x0050395f`, and raw bytes show `0x0050395e` is the `retn 4` immediate byte.
- Completion/confidence score update: existed before as `0/0`; changed to `80/78`. Summary: the minimap button pane has detailed singleton, constructor, cleanup, paint, mouse, thunk, island-boundary, and source-placement notes, but final source placement between minimap and main UI bootstrap remains medium confidence. Evidence: linked shared MapName/MiniMapButton range, cleanup/clear/thunk memory pages, `g_pMiniMapButtonPane`, constructor caller from `InitializeMainUiGraph`, and interleaved `MapNamePane` boundary notes.
