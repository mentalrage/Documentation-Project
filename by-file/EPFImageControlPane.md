*** UID:0000J2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# EPFImageControlPane

## 2026-08-14 B003 ChangePassword Dependency Incorporation

- The formerly absent generated H is now owned by UID00004G: a guarded class declaration with ControlPane include, RectBounds forward, exact five-argument constructor, destructor, paint method, and storage. CPP includes the H before children.
- ChangePasswordDialogPane includes this header for both asset-layout constructors. The control implementation remains emitted here; no target constructor body or resource ownership is transferred. Existing file metadata is unchanged.

## Status

- Confidence: strong for the complete class/source shape, exact method children, 0x14c layout, vtable/compiler routes, render dependencies, and UI-control placement; stripped original spellings remain below-95 confidence caps.
- Proposed module: `ui/controls/EPFImageControlPane.cpp`
- Main address range: `0x004991f0-0x004993a5`, plus non-contiguous destructor support at `0x0049af53-0x0049af69` and `0x0049b1b0-0x0049b24f`.
- Evidence basis: accepted live MCP checks for constructor/destructor/OnPaint/wrapper bounds, 120 call sites in 66 caller functions, object allocations, fields/default literal, vtables, callback targets, borrowed frame behavior, padding, and neighboring-class exclusion, plus preserved 2026-06-14 C001 refresh evidence.

## File Role

`EPFImageControlPane` is a UI control for displaying a single EPF/EPD frame with a palette. It should live with UI controls, not with the EPF registry itself.

The reconstructed source root contains, in generated order:

- [UID:00004G][EPFImageControlPane](by-class/EPFImageControlPane.md) complete declaration and exact tail fields.
- [UID:0004JN][0x004991f0-0x004992a8.EPFImageControlPaneConstructor](by-memory/0x004991f0-0x004992a8.EPFImageControlPaneConstructor.md) at position `10`.
- [UID:0004JS][0x004992b0-0x0049930e.EPFImageControlPaneDestructor](by-memory/0x004992b0-0x0049930e.EPFImageControlPaneDestructor.md) at position `20`.
- [UID:0004JW][0x00499310-0x004993a5.EPFImageControlPaneOnPaint](by-memory/0x00499310-0x004993a5.EPFImageControlPaneOnPaint.md) at position `30`.
- [UID:0003LO][0x0049b1b0-0x0049b24f.EPFImageControlPaneScalarDeletingDestructor](by-memory/0x0049b1b0-0x0049b24f.EPFImageControlPaneScalarDeletingDestructor.md) at position `40`.
- References to `g_pEPFLib`, `g_pPaletteLib`, slot-7 `FillRect`, and slot-2 `g_pfnBlitSprite` shared support.

[UID:00011J][0x004991f0-0x004993a5.EPFImageControlPaneCore](by-memory/0x004991f0-0x004993a5.EPFImageControlPaneCore.md) is a non-emitting three-child index. [UID:0003LN][0x0049af53-0x0049af69.EPFImageControlPaneAdjustorThunks](by-memory/0x0049af53-0x0049af69.EPFImageControlPaneAdjustorThunks.md) are non-emitting compiler glue. Neither should create an aggregate or ABI-wrapper duplicate.

The class consumes the [UID:0000K2][ImageLib](by-file/ImageLib.md) / [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) singleton through `g_pEPFLib`, then uses palette and blit services to draw the decoded frame into the pane surface. The surface-prep callback is tracked as [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) slot `dword_69B3FC` rather than owned by this control.

## Behavior

- Constructor calls `ControlPane(8,bounds)`, copies fixed 16-wchar resource/palette arrays, stores signed frame, clears inherited control flags, calls `SetMode(mode)`, and uses exact `BARAM.PAL` when palette is null.
- Destructor explicitly releases inherited `m_surfaceContext`; normal compiler-generated base teardown performs the later safe reset. Scalar delete and adjustors are generated from source declaration/body.
- `OnPaint` initializes a borrowed local frame, sets draw color zero, clears `m_bounds` via slot-7 `FillRect`, performs `LookupLayoutEntry`, conditionally resolves palette and invokes `g_pfnBlitSprite` only for valid pixels, then always runs `BuildEncodedMask`.
- No source flip field, one-argument lock operation, local-frame release, or aggregate source body is present.

## Evidence Notes

- Live IDA `py_eval` on 2026-06-04 used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- IDA confirms local class functions at `0x004991f0-0x004992a8`, `0x004992b0-0x0049930e`, `0x00499310-0x004993a5`, exact non-contiguous adjustors at `0x0049af53-0x0049af69`, and exact scalar deleting destructor `0x0049b1b0-0x0049b24f`.
- The constructor has 120 call sites across 66 unique caller functions, matching a reusable UI image-control widget rather than a one-off dialog helper; representative callers allocate 332 (`0x14c`) bytes.
- Constructor, destructor, and scalar deleting destructor install the three `EPFImageControlPane` vtables at `0x00618248`, `0x006182b0`, and `0x006182e0`; render slot `0x0061828c` points to `0x00499310`.
- Constructor writes signed frame at `this+0x128`, inherited control flags at `this+0xff`, resource array at `this+0x108`, and palette array at `this+0x12a`; natural alignment yields exact object size `0x14c` without a source pad.
- `OnPaint` uses `dword_67A744` (`g_pEPFLib`), `dword_67A7E0` (palette service), callback slot `dword_69B3FC` as `FillRect`, blit callback `dword_69B3E8` as `g_pfnBlitSprite`, and lookup helper `0x004d02f0`.
- Primary vtable cell `0x0061828c` is the sole xref to `0x00499310`, confirming virtual-only `OnPaint`; ordinary destructor zero-xref status is explained by scalar-wrapper/adjustor lowering.
- The adjacent `0x004993b0` constructor installs `TargetOptionEditControlPane` vtables at `0x00618330`, `0x0061834c`, and later TargetOption vtable cells, so the following control code is excluded from this file's class-local method set.

## 2026-06-14 C001 IDA MCP Refresh

- Current IDA MCP health reports active database `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, imagebase `0x00400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- `lookup_funcs` reconfirmed the compact core and non-contiguous destructor support: constructor `0x004991f0` size `0xb8` / 184 bytes, ordinary destructor `0x004992b0` size `0x5e`, source-facing OnPaint `0x00499310` size `0x95` / 149 bytes, adjustor thunks `0x0049af53` and `0x0049af5e` size `0x0b` each, and scalar deleting destructor `0x0049b1b0` size `0x9f` / 159 bytes. Size conversions were verified with `tools/int_convert.py`.
- `xrefs_to` reconfirmed the render slot at `0x0061828c -> 0x00499310`, scalar-destructor xrefs from the two adjustor thunks plus primary vtable cell `0x00618248`, and constructor/destructor/scalar-destructor stores to vtable cells `0x00618248`, `0x006182b0`, and `0x006182e0`.
- `analyze_component` identifies `0x004991f0` as the component interface, keeps the render/destructor/thunk/scalar-wrapper functions internal, and lists the EPF vtables plus security cookie as shared globals across constructor/destructor/render/destructor-wrapper code.
- `find_regex` found the `EPFImageControlPane` RTTI string at `0x006758d8`. The current string cache did not recover the palette literal, so the default `BARAM.PAL` claim remains based on existing constructor/decompile evidence, not a new string-cache match.

## Score Rationale

Completion is `91` because the page records the exact source declaration, three source children and order, covered-by scalar marker, non-emitting aggregate/adjustors, object layout, callback and failure behavior, vtable/compiler routes, reusable-control caller fanout, and TargetOption exclusion. Confidence is `92` because current evidence agrees across class, memory, and dependencies; original source spellings remain the main cap.

## Generated Output Expectation

- `NexusTK/ui/controls/EPFImageControlPane.cpp` must contain the complete class declaration once.
- Constructor, ordinary destructor, and `OnPaint` bodies must each appear once in positions 10, 20, and 30.
- UID0003LO's position-40 covered-by comment may appear once; no standalone scalar wrapper body or adjustor body may appear.
- UID00011J must not emit an `Empty Emitter Marker` or aggregate duplicate.
- The output must preserve constructor-before-destructor-before-OnPaint source order and all accepted body statements/branches.

## Ownership Decision

Keep this as a consumer in `ui/controls/EPFImageControlPane.cpp`. It is useful evidence for the registry API, but it should not own `ResourceLayoutTable`, `ResourceLayoutEntry`, palette classes, or generic blit helpers.

## Cross-References

- [UID:00004G][EPFImageControlPane](by-class/EPFImageControlPane.md)
- [UID:00011J][0x004991f0-0x004993a5.EPFImageControlPaneCore](by-memory/0x004991f0-0x004993a5.EPFImageControlPaneCore.md)
- [UID:0003LN][0x0049af53-0x0049af69.EPFImageControlPaneAdjustorThunks](by-memory/0x0049af53-0x0049af69.EPFImageControlPaneAdjustorThunks.md)
- [UID:0003LO][0x0049b1b0-0x0049b24f.EPFImageControlPaneScalarDeletingDestructor](by-memory/0x0049b1b0-0x0049b24f.EPFImageControlPaneScalarDeletingDestructor.md)
- [UID:0000K2][ImageLib](by-file/ImageLib.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0000QW][g_pfnLockSurface](by-global/g_pfnLockSurface.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-07-13 B001 UID00011J accepted callback:
  - Raised `87/88 -> 91/92`, retained `NexusTK/ui/controls/` and FILE ownership, and recorded complete source contents/order with real child UIDs.
  - Replaced flip/load/lock/cache wording with inherited control flags, virtual OnPaint, FillRect, borrowed-frame, invalid-frame, palette/blit, and unconditional-mask behavior.
  - Added exact generated-output expectations and preserved compiler-generated scalar/adjustor handling without aggregate duplication.
- 2026-06-12 C001 barrier repair:
  - Changed score from `84/84` to `85/85` after exact by-memory split removed the sparse EPF range crossing over neighboring control/destructor pages.
  - Evidence: the file now routes compact core, adjustor thunks, and scalar deleting destructor through exact pages while retaining TargetOption exclusion and UI-control ownership.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:78` and `CONFIDENCE:78`.
  - Summary/evidence: UI control role, constructor/load-render behavior, `g_pEPFLib`/palette/surface callback dependencies, and non-ownership decisions are documented; completion is lower than larger pages because detailed vtable/layout and caller coverage are still sparse.
- 2026-06-04: Raised from `78/78` to `84/84` and set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/ui/controls/`.
  - Before: the page had a correct proposed module but a blank validator path, stale recovered-source wording, sparse caller/vtable evidence, and no fresh executable identity.
  - After: live IDA evidence records exact local bounds, 66-constructor-caller fanout, vtable stores/slots, default palette, render dependencies, callback shape, and adjacent `TargetOptionEditControlPane` exclusion.
  - Reasoning: `NexusTK/ui/controls/` matches the control role and the existing proposed module. Confidence remains below final-code level because member names and callback typedefs still need source-quality review.
- 2026-06-14 C001 Goal 2 score pass: Raised `85/85 -> 87/88`.
  - Summary/evidence: current IDA 9.1 MCP reconfirmed compact core and non-contiguous destructor support sizes, vtable xrefs, render slot, component interface/internal split, RTTI string, and exact child UIDs. No owner/emitter route changed.
