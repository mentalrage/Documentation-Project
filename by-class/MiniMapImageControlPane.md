*** UID:00008E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// MiniMapImageControlPane class declaration is intentionally withheld: constructor,
// ordinary destructor, OnPaint, and vtable routes are documented, but the ControlPane
// base spelling, image-handle type, and render-helper names are not source-quality yet.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MiniMapImageControlPane

## Status

- Confidence: strong for class behavior, method starts, vtable paint slot, and direct MiniMapDialog construction; medium-high for final source split.
- Direct source parent: [UID:0000LE][MiniMap](by-file/MiniMap.md), probably beside [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md).
- Main memory doc: [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md)

## Class Purpose

`MiniMapImageControlPane` is the image pane used by `MiniMapDialog` when rendering the main minimap image surface. It is a small `ControlPane`-derived widget with an image handle and paint path for the loaded minimap image.

## Methods

| Address | Method | Role |
| --- | --- | --- |
| `0x00453df0-0x00453e87` | constructor | Builds the control, initializes image state, and stores the image handle. |
| `0x00453e90-0x00453eaf` | ordinary destructor | Source destructor body; local listing shows a tail jump to shared pane teardown at `0x00453eaa`, and the scalar deleting destructor wraps this body. |
| `0x00453eb0-0x00453ed0` | `OnPaint` | Paints/blits the minimap image through the current render callback path. |
| `0x00453ed0-0x00453ee6` | adjustor thunks | Compiler-generated destructor adjustors currently disabled in active output. |
| `0x00453ef0-0x00453f45` | scalar deleting destructor | Runs shared pane cleanup and optional delete. |

## Boundary Caveats

- The generated source references fitting-room image-control helper labels for initialization. Treat those labels as shared control/image helper pollution, not evidence that this minimap control belongs to cash-shop or fitting-room source.
- Keep the class with minimap UI unless later caller evidence proves it is a generic reusable image control. Current IDA caller evidence ties construction to [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md) at `0x004523d0`.
- The image handle at object offset `+0x14c` is high-confidence behavior but medium-confidence type. `OnPaint` checks it before calling the shared image/render callback with the image handle, image bounds, and client rectangle. Do not promote generated fitting-room helper casts or labels into source names.
- Source responsibility is the ordinary destructor at `0x00453e90`; `0x00453ef0` is compiler-generated scalar deleting destructor glue and should not emit as handwritten C++.

## B010 Declaration-Shell Audit And C++ Disposition

Current evidence supports a class-index marker with `[[CHILDREN]]`, not a declaration shell or inline source snippet. Three vtable views at `0x0061070c`, `0x00610774`, and `0x006107a4` tie constructor/destructor/scalar paths to this class. The exact class rows are constructor `0x00453df0-0x00453e87`, ordinary destructor `0x00453e90-0x00453eaf`, `OnPaint` `0x00453eb0-0x00453ed0`, adjustor thunks `0x00453ed0-0x00453ee6`, and scalar deleting destructor `0x00453ef0-0x00453f45`.

The class declaration is intentionally withheld because ControlPane base spelling, image-handle type at object offset `+0x14c`, render callback names, and fitting-room helper-label pollution are not source-quality. Constructor/destructor/`OnPaint` can become exact child-method bodies only if split creation is authorized and project-approved image/control helper names are accepted. The old source-style `OnPaint` snippet is removed from this class page to avoid non-formal C++ outside exact child pages.

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000LE][MiniMap](by-file/MiniMap.md). This class is now scored `86/88`, and the direct file parent is scored `87/89`, so both sides satisfy the corrected 85/85 gate. The parent is direct because `MiniMap.md` owns the image-control/renderer/control aggregate [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md), lists this class as a minimap child control, and records the current-pass compact MiniMap source route.

## Batch 092 IDA Evidence

- Live IDA MCP reconfirmed the image-control method cluster: constructor `0x00453df0-0x00453e87`, paint slot `0x00453eb0-0x00453ed0`, adjustor thunks `0x00453ed0-0x00453ee6`, and scalar deleting destructor `0x00453ef0-0x00453f45`. B007's local listing check adds the ordinary destructor at `0x00453e90-0x00453eaf`.
- `callers 0x00453df0` reports construction from [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md) symbol rendering at `0x004524d6` inside `0x004523d0`.
- `xrefs_to 0x00453eb0` reports the paint method in the vtable slot at `0x00610750`, supporting the `ControlPane`-derived paint callback role.
- Callee evidence keeps constructor helper calls to shared control/image helpers outside minimap ownership while preserving this small widget as minimap UI code.
- Boundary bytes show one `0xcc` byte before the class starts and eleven `0xcc` bytes between the scalar deleting destructor and the following [UID:00008F][MiniMapRenderer](by-class/MiniMapRenderer.md) constructor at `0x00453f50`.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The page now has exact half-open method bounds, the ordinary destructor versus scalar deleting wrapper split, direct construction evidence, vtable paint-slot evidence, destructor/thunk handling, helper-pollution caveats, image-handle field guidance, a justified direct file parent, formal class-index marker, and explicit no-declaration-shell disposition. It remains below final-source quality because field names, helper type names, and final minimap file split are not settled. |
| Confidence | 88 | Confidence is strong for identity and ownership from live IDA caller/vtable evidence plus the assigned memory aggregate. It is capped by generic control/image helper reuse and unresolved exact source-file decomposition. |

## Cross-References

- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md)
- [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md)

## Changes

- 2026-06-30 B010 empty-emitter implementation callback:
  - Raised `85/87` to `86/88`, inserted the accepted formal class-index marker with `[[CHILDREN]]`, added the declaration-shell audit, and removed the non-formal `OnPaint` source-style snippet in favor of exact child-method split conditions.
- 2026-06-21 B007 Rule 26 source-quality incorporation:
  - Added the missing ordinary destructor `0x00453e90-0x00453eaf`, separated it from scalar deleting destructor glue, recorded `+0x14c` image-handle guidance, rejected stale fitting-room helper names, and added child-level `OnPaint` draft guidance without changing formal class C++.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed constructor/paint/thunk/deleting-destructor starts at `0x00453df0`, `0x00453eb0`, `0x00453ed0`, `0x00453edb`, and `0x00453ef0`. Left `AUTOGEN_PARENT_UID` blank because likely parent [UID:0000LE][MiniMap](by-file/MiniMap.md) is below the 80 completion attachment gate.
- 2026-05-30: Grading changed from `0/0` to `82/86`.
  - Before: page documented the class purpose, method ranges, and minimap caller ownership but was still unevaluated.
  - After: score reflects the small, well-bounded image-control class, including constructor, paint path, destructor glue, and fitting-room helper pollution caveat.
  - Evidence: linked memory page [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md) records IDA-confirmed method starts and construction from [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md).
- 2026-06-07 A008 Batch 092 class-coverage pass:
  - Before: `82/86`, `AUTOGEN_PARENT_UID:` blank, and the status still referenced generated recovered-file evidence.
  - After: `85/87`, `AUTOGEN_PARENT_UID:0000LE`.
  - Summary/evidence: live IDA MCP reconfirmed exact method bounds, `MiniMapDialog` construction at `0x004524d6`, vtable paint-slot reference at `0x00610750`, helper-pollution boundaries, and padding before the renderer constructor. The direct MiniMap parent is `85/86`, so the corrected 85/85 gate is satisfied.
