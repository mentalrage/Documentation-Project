*** UID:00008E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

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
| `0x00453eb0-0x00453ed0` | `OnPaint` | Paints/blits the minimap image through the current render callback path. |
| `0x00453ed0-0x00453ee6` | adjustor thunks | Compiler-generated destructor adjustors currently disabled in active output. |
| `0x00453ef0-0x00453f45` | scalar deleting destructor | Runs shared pane cleanup and optional delete. |

## Boundary Caveats

- The generated source references fitting-room image-control helper labels for initialization. Treat those labels as shared control/image helper pollution, not evidence that this minimap control belongs to cash-shop or fitting-room source.
- Keep the class with minimap UI unless later caller evidence proves it is a generic reusable image control. Current IDA caller evidence ties construction to [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md) at `0x004523d0`.

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000LE][MiniMap](by-file/MiniMap.md). This class is now scored `85/87`, and the direct file parent is scored `85/86`, so both sides satisfy the corrected 85/85 gate. The parent is direct because `MiniMap.md` owns the image-control/renderer/control aggregate [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md), lists this class as a minimap child control, and records the final compact-versus-split minimap source caveat.

## Batch 092 IDA Evidence

- Live IDA MCP reconfirmed the image-control method cluster: constructor `0x00453df0-0x00453e87`, paint slot `0x00453eb0-0x00453ed0`, adjustor thunks `0x00453ed0-0x00453ee6`, and scalar deleting destructor `0x00453ef0-0x00453f45`.
- `callers 0x00453df0` reports construction from [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md) symbol rendering at `0x004524d6` inside `0x004523d0`.
- `xrefs_to 0x00453eb0` reports the paint method in the vtable slot at `0x00610750`, supporting the `ControlPane`-derived paint callback role.
- Callee evidence keeps constructor helper calls to shared control/image helpers outside minimap ownership while preserving this small widget as minimap UI code.
- Boundary bytes show one `0xcc` byte before the class starts and eleven `0xcc` bytes between the scalar deleting destructor and the following [UID:00008F][MiniMapRenderer](by-class/MiniMapRenderer.md) constructor at `0x00453f50`.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | The page now has exact half-open method bounds, direct construction evidence, vtable paint-slot evidence, destructor/thunk handling, helper-pollution caveats, and a justified direct file parent. It remains below final-source quality because field names and final minimap file split are not settled. |
| Confidence | 87 | Confidence is strong for identity and ownership from live IDA caller/vtable evidence plus the assigned memory aggregate. It is capped by generic control/image helper reuse and unresolved exact source-file decomposition. |

## Cross-References

- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md)
- [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md)

## Changes

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed constructor/paint/thunk/deleting-destructor starts at `0x00453df0`, `0x00453eb0`, `0x00453ed0`, `0x00453edb`, and `0x00453ef0`. Left `AUTOGEN_PARENT_UID` blank because likely parent [UID:0000LE][MiniMap](by-file/MiniMap.md) is below the 80 completion attachment gate.
- 2026-05-30: Grading changed from `0/0` to `82/86`.
  - Before: page documented the class purpose, method ranges, and minimap caller ownership but was still unevaluated.
  - After: score reflects the small, well-bounded image-control class, including constructor, paint path, destructor glue, and fitting-room helper pollution caveat.
  - Evidence: linked memory page [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md) records IDA-confirmed method starts and construction from [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md).
- 2026-06-07 A008 Batch 092 class-coverage pass:
  - Before: `82/86`, `AUTOGEN_PARENT_UID:` blank, and the status still referenced generated recovered-file evidence.
  - After: `85/87`, `AUTOGEN_PARENT_UID:0000LE`.
  - Summary/evidence: live IDA MCP reconfirmed exact method bounds, `MiniMapDialog` construction at `0x004524d6`, vtable paint-slot reference at `0x00610750`, helper-pollution boundaries, and padding before the renderer constructor. The direct MiniMap parent is `85/86`, so the corrected 85/85 gate is satisfied.
