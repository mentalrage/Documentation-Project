*** UID:0000NH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ScrolledPictureControlPane

## Status

- Confidence: very strong for the complete source/compiler inventory, exact core boundaries and hashes, scalar-wrapper ABI, ordinary/source decomposition, constructor parameter and helper types, `0x154` class layout, three-view vtable routes, and source placement. Exact original field spellings/access and the feature-level construction route remain bounded confidence caps.
- Proposed module: `ui/controls/ScrolledPictureControlPane.cpp`
- Proposed header: `ui/controls/ScrolledPictureControlPane.h`
- Current recovered source: `source-3/simroot_v2/class_ScrolledPictureControlPane.cpp`
- Main address clusters: `0x004ff7d0-0x004ffa9e`, `0x00502550-0x00502566`, and `0x00502ab0-0x00502b58`

## File Role

This module owns an auto-scrolling picture control. It is a `ControlPane` type `8` widget that loads an EPF frame resource, optionally loads a palette, computes an off-screen starting rectangle based on scroll direction, starts a timer, offsets the picture rectangle on each tick, invalidates/repaints the control, and blits the frame through shared render callbacks.

It is the picture-resource sibling of [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md). The text control pre-renders DAT text through `TextEditPane`; this class directly loads and scrolls an EPF frame/image resource.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| [UID:00019Y][0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore](by-memory/0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore.md) | `0x004ff7d0-0x004ffa9e` | Source-emitting constructor, one ordinary virtual destructor, timer callback, paint callback, and internal switch tables through class emitter [UID:0000CH][ScrolledPictureControlPane](by-class/ScrolledPictureControlPane.md). |
| [UID:0001AD][0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks](by-memory/0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks.md) | `0x00502550-0x00502566` | Compiler-generated secondary/tertiary receiver-adjusting destructor thunks; class-owned, non-reconstructable, and blank-formal. |
| [UID:0001AI][0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor](by-memory/0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor.md) | `0x00502ab0-0x00502b58` | Compiler-generated MSVC scalar-deleting-destructor clone; class-owned, non-reconstructable, blank-formal, and represented in human source only by the ordinary virtual destructor. |
| [UID:00025Q][0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData](by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md) | ScrolledPicture subrange `0x0061d88c-0x0061d930` | Non-emitting mixed `.rdata` aggregate that preserves the exact primary/secondary/tertiary vtable cells and routes without handwritten vtable/RTTI arrays. |

## Function Map

| Range | Function | Notes |
| --- | --- | --- |
| `0x004ff7d0-0x004ff95d` | `ScrolledPictureControlPane::ScrolledPictureControlPane` | Source definition takes `const RectBounds *`, two `const wchar_t *`, two `int`, and `unsigned char`; calls `ControlPane(8, bounds)`, zeroes the `FrameDrawRecord`, loads frame-table/draw data, resolves `DLPalette *`, computes the exact directional starting rectangle, and starts the timer. |
| `0x004ff970-0x004ff9d7` | `ScrolledPictureControlPane::~ScrolledPictureControlPane` | Sole human source destructor: destroys the owned image block. Base teardown, vptr stores, scalar flags, storage deletion, SEH/cookie mechanics, and receiver-adjusting thunks are compiler output rather than handwritten body statements. |
| `0x004ff9e0-0x004ffa4b` | `ScrolledPictureControlPane::OnTimerEvent` | Moves the destination rectangle in direction `0..3`, refreshes/invalidates the owner view, and schedules the next timer. |
| `0x004ffa60-0x004ffa9e` | `ScrolledPictureControlPane::OnPaintFrame` | Invalidates/fills the control region and blits the current frame with palette state. |
| `0x00502550-0x00502566` | compiler adjustor thunks | Two exact secondary/tertiary vtable entries subtract `0xa0`/`0xa4` and tail-jump to UID0001AI. They are preserved as blank no-code evidence in UID0001AD. |
| `0x00502ab0-0x00502b58` | compiler scalar-deleting-destructor clone | Exact MSVC bit-1/bit-4 ABI wrapper around duplicated ordinary cleanup/base teardown. It returns complete `this`, has no direct source caller or unique source behavior, and remains blank no-code evidence in UID0001AI. |

## Ownership Decision

Keep this as a reusable UI control under `ui/controls`. It shares the scrolled-control pattern with [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md), but its asset pipeline is EPF/palette/frame-table based and should not be merged into text editing or DAT text display code.

Do not attach it to fitting-room or head-selection dialogs based on generated type names alone. Current generated source contains `HeadSelectDialog`, `FittingRoomDialog`, `FittingRoomListPane`, and `TextButtonExControlPane` names in helper paths; IDA evidence shows a generic control/timer/image-scroll body.

## Evidence Notes

- IDA MCP confirms `0x004ff7d0`, `0x004ff970`, `0x004ff9e0`, and `0x004ffa60` as real functions and vtable targets.
- The constructor calls shared image-frame helpers [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md) and [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md), then resolves a `DLPalette *` through the palette library. The earlier `m_paletteState` label was decompiler-shaped and is historicalized; the field at `+0x140` is a pointer.
- No direct constructor caller was found in the current IDA pass. Treat construction as config/factory-driven or unresolved until caller evidence is found.
- The scalar deleting destructor lives in a later control destructor island near other UI vtable wrappers, so it is documented here without expanding the core memory file across unrelated neighbors.
- 2026-05-25 recheck: current `class_ScrolledPictureControlPane.cpp` still contains generated `HeadSelectDialog`, `FittingRoomDialog`, `FittingRoomListPane`, and `TextButtonExControlPane` labels, while IDA still reports no direct callers for `0x004ff7d0`. IDA decompilation shows generic control behavior: `ControlPane` type `8`, frame table load through `0x004d0f50`/`0x004d1600`, palette lookup through `dword_67a7e0`, timer scheduling through `sub_5975e0`, and render callbacks through `dword_69b3fc`/`dword_69b3e8`.
- 2026-06-01 IDA MCP recheck records exact core function sizes and vtable evidence: constructor `0x18e`, destructor `0x67`, timer callback `0x6b`, paint callback `0x3f`; timer method vtable data at `0x0061d92c`; paint method vtable data at `0x0061d8d4`; constructor/destructor/scalar-deleting paths write/reference the `ScrolledPictureControlPane` vtable family at `0x0061d890`.
- The refreshed core memory page records the object-offset state map: timer interval `+0x108`, scroll step `+0x10c`, direction `+0x110`, frame block `+0x114`, frame draw record `+0x118..+0x13f`, palette/render state `+0x140`, and destination rectangle `+0x144..+0x153`.
- 2026-06-11 A007 Batch 161 live IDA refresh reconfirmed the scalar deleting destructor [UID:0001AI][0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor](by-memory/0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor.md) as an exact `0xa8`-byte function with vtable ref `0x0061d890`, thunk jumps from `0x00502556`/`0x00502561`, owned-image cleanup from `this+0x114`, base teardown through `0x00544580`, and delete through `0x004f4ac0` only for the exact bit-1 path. The bit-4 branch reaches a one-byte `_guard_check_icall_nop@4` no-op, not an indirect call or storage release.
- B004 2026-06-18 source-quality update proposed class-emitter routing through [UID:0000CH][ScrolledPictureControlPane](by-class/ScrolledPictureControlPane.md) with this file as source root. The 2026-07-14 B003 callback implements that route: UID00019Y emits the constructor, ordinary destructor, timer handler, and paint handler; UID0001AI and UID0001AD remain class-owned compiler artifacts with blank formal C++; UID00025Q remains a non-emitting `.rdata` index. Descriptive names remain capped where original lexical tokens are unavailable, but the field model is now `m_scrollInterval`, `m_scrollStep`, `m_scrollDirection`, `m_frameTable`, `m_frameDrawRecord`, `m_palette`, and `m_destinationRect`.

## Current Caveats

- Field names are source-facing descriptive first-draft names; exact original spellings and private/public token choices remain unavailable and cap confidence. The complete `0x154` layout and inherited timer-facet adjustment are documented without exposing raw offsets or receiver adjustment in human C++.
- Direct construction path is still unresolved; do not infer final feature ownership from the generated fitting-room/head-selection type names.
- Destructor-generated base names are polluted. The class declares one virtual ordinary destructor, whose human body performs only owned-image cleanup; `Pane::~Pane`, vptr writes, scalar flags, storage release, receiver adjustments, SEH/cookie, vtable, and RTTI mechanics remain compiler-generated and are excluded from the source block.

## Cross-References

- [UID:0000CH][ScrolledPictureControlPane](by-class/ScrolledPictureControlPane.md)
- [UID:00019Y][0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore](by-memory/0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore.md)
- [UID:0001AD][0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks](by-memory/0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks.md)
- [UID:0001AI][0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor](by-memory/0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor.md)
- [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)
- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md)
- [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000MA][Palette](by-file/Palette.md)

## Changes

- 2026-07-14 B003 source-quality implementation callback:
  - Raised `88/85 -> 91/92`; preserved `NexusTK/ui/controls/` and `CANONICAL_OWNER:FILE`.
  - Synchronized the complete source/compiler inventory: UID00019Y emits exactly the constructor, one ordinary virtual destructor, timer, and paint definitions through UID0000CH; UID0001AI and UID0001AD remain class-owned non-reconstructable blank-formal compiler outputs; UID00025Q remains non-emitting read-only-data evidence.
  - Added the exact constructor/type/palette model, scalar-wrapper flag correction, ordinary/source decomposition, source-placement rationale, negative ownership evidence, and bounded lexical/access confidence caps. The unresolved feature-level constructor caller is retained as nonblocking historical evidence.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `78`.
  - Evidence: document covers control role, function map, ownership decision, IDA evidence, generated-name pollution, unresolved construction path, caveats, and cross-references; confidence is capped by provisional field names and owner-offset details.
- 2026-06-01: Raised documentation score to `88/84` and set the projected source folder to `NexusTK/ui/controls/`.
  - Before: source placement was described in prose but the validator-managed projected path was blank, and the file confidence stayed below the parent-link threshold for attached memory ranges.
  - After: the page has a concrete projected folder, exact child rows, refreshed IDA function-size/vtable evidence, and a linked object-offset state map in the core memory page.
  - Evidence: 2026-06-01 IDA MCP `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, `disasm`, and byte checks recorded in [UID:00019Y][0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore](by-memory/0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore.md).
- 2026-06-11 A007 Batch 161: Raised confidence from `84` to `85` after live IDA reconfirmed the scalar deleting destructor's exact boundary, vtable/thunk refs, owned-image cleanup, base teardown, and delete-flag behavior. This clears the strict parent-side `85/85` gate for directly owned ScrolledPicture memory children while keeping field names and construction path below final C++ quality.
- 2026-06-18 B004 source-quality sync: [UID:00019Y][0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore](by-memory/0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore.md) now has first-draft C++ and class-emitter routing through [UID:0000CH][ScrolledPictureControlPane](by-class/ScrolledPictureControlPane.md), while this page remains the file root for `NexusTK/ui/controls/ScrolledPictureControlPane.cpp`.
