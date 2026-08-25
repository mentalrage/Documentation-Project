** TARGET-REPORT-UID:00019Y **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B004 source-quality report: [UID:00019Y] ScrolledPictureControlPaneCore

Assignment id: `B004-goal2-scrolled-picture-control-pane-core-source-quality-00019Y-20260618`

Target: `by-memory/0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore.md`

Required target range after recheck: `0x004ff7d0-0x004ffa9f` half-open. The existing filename keeps the last-code-byte spelling `0x004ffa9e`; the target body and coverage row already use `0x004ffa9f` half-open text. Supervisor should rename the by-memory file to `by-memory/0x004ff7d0-0x004ffa9f.ScrolledPictureControlPaneCore.md` when incorporating this report, or keep the old filename only as a compatibility link while updating the internal range text.

Report status: final-quality report-only pass. No by-memory, by-file, by-class, generated, IDA DB, or coverage files were edited by this agent.

## Executive recommendation

Raise [UID:00019Y] from `84/88` to `88/90`, keep it reconstructable, change direct owner/emitter from the by-file UID to the class UID, and populate first-draft C++ on the target page.

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000CH
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000CH
EMITTER_POSITION_OPTIONAL:
```

Reasoning:

- The target is not an orphan raw helper. It is a source-authored class method cluster for `ScrolledPictureControlPane`, with constructor, non-deleting destructor, timer handler, paint handler, two internal jump tables, vtable routes, and companion scalar/thunk pages.
- Direct construction route is still absent in the current PE, but class/source ownership does not depend on a caller. The methods are vtable-referenced class methods, the companion scalar deleting destructor is already class-owned, and the class/file support pages already exist above gate.
- The prior 84 score was held down by unresolved field semantics and source-quality questions. This pass resolves the timer interval, scroll step, direction enum, frame-draw record, palette/render state, destination rectangle, base teardown helper, constructor/destructor/timer/paint boundaries, jump-table padding, vtable refs, companion thunk/scalar relationship, and C++ source-shape blockers to incorporation-quality specificity.
- Confidence remains below 95 because IDA MCP was offline for fresh interactive xrefs, original source field names are still inferred/descriptive, and no local caller to the constructor exists. The raw bytes, local PE scans, and existing IDA-backed docs are sufficient for 88/90.

## Inputs checked

Supervisor and policy inputs:

- `tools/leaser/Agents/Agent-B004/goal.md`
- `tools/leaser/Agents/Agent-B004/notes.md`
- `tools/leaser/Agents/Supervisor.md`
- `project-documentation/by-structure.md`
- `project-documentation/inference_research.md`

Primary and support docs:

- `by-memory/0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore.md`
- `by-class/ScrolledPictureControlPane.md`
- `by-file/ScrolledPictureControlPane.md`
- `by-memory/0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks.md`
- `by-memory/0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor.md`
- `by-type/by-struct/PaneLayout.md`
- `by-file/Pane.md`
- `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`
- `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md`
- `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`
- `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`
- `by-file/PaletteLib.md`
- `by-memory/0x00543d30-0x00543f54.ScreenPanePaletteState.md`
- `by-file/ImageFrameTable.md`
- `by-item/LoadImageFrameTable_004D0F50.md`
- `by-item/LoadFrameDrawRecord_004D1600.md`
- `by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md`
- `by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md`
- `by-file/ScrolledTextControlPane.md`
- `by-memory/0x004ff040-0x004ff3fd.ScrolledTextControlPaneCore.md`
- `project-documentation/by-project-structure/proposed-source-tree.md`
- `by-memory/-coverage-report.md` read-only for row replacement text.
- `project-level/-auto-completion-stats.md` read-only for current 84/88 state.
- `auto-generated/-ag-memory-coverage.md` read-only for generated emitter/output state.

Local binary input:

- `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`

IDA MCP status:

- `Test-NetConnection 127.0.0.1 -Port 13337` returned `TcpTestSucceeded : False`; IDA MCP was unavailable. This report therefore uses the local PE bytes, local disassembly/scans, and existing IDA-backed by-* support pages.

## PE mapping and raw byte evidence

Local PE mapping from `NexusTK.exe`:

```text
ImageBase: 0x00400000
.text VirtualAddress: 0x00001000
.text VirtualSize: 0x0020b4ac
.text PointerToRawData: 0x00000400
.text SizeOfRawData: 0x0020b600
VA-to-raw formula for this target:
  raw = 0x00000400 + ((VA - 0x00400000) - 0x00001000)
```

Target start:

```text
VA 0x004ff7d0
RVA 0x000ff7d0
raw file offset 0x000febd0
```

Boundary, padding, hashes, and signatures:

```text
pre-context 0x004ff7c0-0x004ff7d0
  raw 0x000febc0, length 0x10
  sha256 f8aa8e3facc2c9b8120b9513f80526cc9da9604e6cef19c1fe94d72ebab02268
  bytes 5f 33 cd 5e e8 66 7f 0c 00 8b e5 5d c3 cc cc cc

constructor 0x004ff7d0-0x004ff95e
  raw 0x000febd0, length 0x18e
  sha256 446dc73007a983d7e55fccaae178ff22483f2271c1ec370ef1170d54e0187f21

constructor alignment 0x004ff95e-0x004ff960
  raw 0x000fed5e, length 0x02
  sha256 88174ba925c5691bff5cf2698a670490725c2f586fd946282b314ea52d9c24ce
  bytes 66 90

constructor switch table 0x004ff960-0x004ff970
  raw 0x000fed60, length 0x10
  sha256 910f6c43b25fc447f2b81a4d49710c5cde7ef04c0f81512a19395acc2127b9cc
  bytes ee f8 4f 00 fd f8 4f 00 09 f9 4f 00 15 f9 4f 00
  dwords 0x004ff8ee 0x004ff8fd 0x004ff909 0x004ff915

non-deleting destructor 0x004ff970-0x004ff9d7
  raw 0x000fed70, length 0x67
  sha256 45718a4c81f4bbb4cc88586b8165a98d61d223898576e6edb9915e14e63ea354

destructor padding 0x004ff9d7-0x004ff9e0
  raw 0x000fedd7, length 0x09
  sha256 57c1d0aaef1222fc7f655f011049271d3a843395335212156e61d3850beb51ce
  bytes cc cc cc cc cc cc cc cc cc

timer handler 0x004ff9e0-0x004ffa4b
  raw 0x000fede0, length 0x6b
  sha256 30f7384bce580ef7ae85c156dccde3cefc0900dada897ceb3c72839e1a47468d

timer switch-table alignment 0x004ffa4b-0x004ffa4c
  raw 0x000fee4b, length 0x01
  sha256 9e076ceaf246b6003d9c2680a2b4cf0bffd069805902b0b5edeebf49039fe4bd
  byte 90

timer switch table 0x004ffa4c-0x004ffa5c
  raw 0x000fee4c, length 0x10
  sha256 dfebeaf97f25344a6b2fa304360291d88e4b77901130d2f9083e7d29fc2018c7
  bytes f3 f9 4f 00 fd f9 4f 00 04 fa 4f 00 0b fa 4f 00
  dwords 0x004ff9f3 0x004ff9fd 0x004ffa04 0x004ffa0b

timer/paint padding 0x004ffa5c-0x004ffa60
  raw 0x000fee5c, length 0x04
  sha256 8843b54d2df63ca265cf4a05d27dd2b29a74fb476d296dd44a0e171d74b441ca
  bytes cc cc cc cc

paint handler 0x004ffa60-0x004ffa9f
  raw 0x000fee60, length 0x3f
  sha256 838e6d62ee54b9eda83584d704ec25a2ec85b4e410bf9a0a5b0a3262a09f52a9

post-context 0x004ffa9f-0x004ffaa0
  raw 0x000fee9f, length 0x01
  sha256 1dd8312636f6a0bf3d21fa2855e63072507453e93a5ced4301b364e91c9d87d6
  byte cc

whole target body plus internal tables 0x004ff7d0-0x004ffa9f
  raw 0x000febd0, length 0x2cf
  sha256 0c607f155f88b4d90d06aebfc65fdfcd09f23959a34a8ad20a28acfd74f33298

envelope 0x004ff7c0-0x004ffaa0
  raw 0x000febc0, length 0x2e0
  sha256 48b049c9bfdfdc438bfd2742d25cf32e8f38dd813886383488b9781306b9fb87
```

Boundary conclusion:

- The previous function returns at `0x004ff7cc` and is followed by `cc cc cc` at `0x004ff7cd-0x004ff7cf`.
- [UID:00019Y] starts at `0x004ff7d0`.
- The final executable byte in [UID:00019Y] is the paint-handler `ret` at `0x004ffa9e`.
- `0x004ffa9f` is `cc` padding and should not be included in code-body length.
- Therefore the code/body half-open range is `0x004ff7d0-0x004ffa9f`; the filename `0x004ff7d0-0x004ffa9e` is stale last-byte notation.

## Instruction-shape evidence

### Constructor `0x004ff7d0-0x004ff95e`

The constructor is a `__thiscall` constructor returning with `ret 0x18`, proving six explicit stack arguments after `this`.

Raw-body facts:

- Calls `0x004949e0` after pushing the first explicit argument and constant `8`; this is the inherited `ControlPane(parent, 8)`/pane setup path already established by the support pages.
- Initializes three vtable slots:
  - primary vtable `0x0061d890` at `this+0x00`.
  - adjustor vtable `0x0061d8f8` at `this+0xa0`.
  - timer/handler vtable `0x0061d928` at `this+0xa4`.
- Calls `0x00457a60` on `this+0x118`. Existing support identifies this as a tile/frame context or frame draw record initializer. It initializes the record used immediately by `LoadFrameDrawRecord` and the paint blit path.
- Stores constructor args:
  - `[ebp+0x14]` to `this+0x108`: timer interval/delay.
  - `[ebp+0x18]` to `this+0x10c`: scroll step/pixel delta magnitude.
  - low byte of `[ebp+0x1c]` to `this+0x110`: scroll direction enum byte.
- Loads frame/image data:
  - `dword_67A744` is loaded and `0x004d0f50` is called with the resource path argument `[ebp+0x0c]` and mode `0`.
  - Return is stored at `this+0x114`.
  - `0x004d1600(this+0x114, 0, this+0x118)` fills the first frame draw record.
- Loads palette/render state:
  - If `[ebp+0x10]` is non-null, calls `0x00543d70` through `g_pPaletteLib`/`dword_67A7E0`.
  - If `[ebp+0x10]` is null, calls `0x00543d40` through the same object.
  - Return is stored at `this+0x140`.
- Computes source frame width and height from record fields:
  - width = `[this+0x130] - [this+0x128]`.
  - height = `[this+0x134] - [this+0x12c]`.
  - This is the source rectangle inside the `FrameDrawRecord` at `this+0x118`.
- Computes pane width and height from inherited bounds:
  - width = `[this+0x4c] - [this+0x44]`.
  - height = `[this+0x50] - [this+0x48]`.
- Uses a four-entry jump table at `0x004ff960` to initialize the destination rectangle for one of four scroll directions.
- Calls `0x004b7c50` with `this+0x144` and four coordinates. Support docs identify this helper as `InitRectBounds`.
- Calls `0x005975e0` on `this+0xa4` with event id `0`, delay `[this+0x108]`, and zero payload fields. Support docs identify this as the generic `TimerHandler::ScheduleTimer` wrapper.

Constructor jump-table interpretation:

```text
table at 0x004ff960:
  case 0 -> 0x004ff8ee
  case 1 -> 0x004ff8fd
  case 2 -> 0x004ff909
  case 3 -> 0x004ff915
```

The constructor cases and timer deltas agree:

- Direction `0`: place the image below the pane and later move upward. Recommended enum: `kScrollUp`.
- Direction `1`: place the image left of the pane and later move right. Recommended enum: `kScrollRight`.
- Direction `2`: place the image above the pane and later move downward. Recommended enum: `kScrollDown`.
- Direction `3`: place the image right of the pane and later move left. Recommended enum: `kScrollLeft`.

The names are inferred/descriptive, but the numeric semantics are raw-byte proven by the destination rectangle initialization and timer deltas.

### Non-deleting destructor `0x004ff970-0x004ff9d7`

Raw-body facts:

- Restores the same three vtable values as the constructor:
  - `this+0x00 = 0x0061d890`.
  - `this+0xa0 = 0x0061d8f8`.
  - `this+0xa4 = 0x0061d928`.
- Loads `dword_67A744` and calls `0x004d15d0` with `this+0x114`.
- Calls `0x00544580(this)`.
- Returns.

Support-doc validation:

- `0x004d15d0` is documented as `DestroyOwnedImageBlock` / frame-table destruction in the `ImageFrameTable` family.
- `0x00544580` is documented by the Pane family and B002 PaneCore source-quality report as the ordinary non-deleting `Pane::~Pane` base teardown body. It is not TextButtonEx-specific and is not the old stale `0x004b8d20` GrafPort cleanup label.

Source interpretation:

- Source destructor body should explicitly release the owned frame/image block at `this+0x114`.
- The `Pane::~Pane` call and vtable stores are compiler lowering for base teardown and must not be written as manual source statements.

### Timer handler `0x004ff9e0-0x004ffa4b`

The timer handler is entered through the timer-handler subobject, not the primary object pointer. `ecx` is the subobject at owner `this+0xa4`.

Raw offset map relative to `ecx` in the timer method:

```text
ecx + 0x64  -> owner + 0x108 -> timer interval/delay
ecx + 0x68  -> owner + 0x10c -> scroll step
ecx + 0x6c  -> owner + 0x110 -> scroll direction byte
ecx + 0xa0  -> owner + 0x144 -> destination rectangle
ecx - 0xa4  -> owner pointer
ecx - 0x60  -> owner + 0x44 -> inherited pane bounds
```

Timer switch table:

```text
table at 0x004ffa4c:
  case 0 -> 0x004ff9f3
  case 1 -> 0x004ff9fd
  case 2 -> 0x004ffa04
  case 3 -> 0x004ffa0b
```

Raw timer deltas:

```text
direction 0: dx = 0,           dy = -m_scrollStep
direction 1: dx = +m_scrollStep, dy = 0
direction 2: dx = 0,           dy = +m_scrollStep
direction 3: dx = -m_scrollStep, dy = 0
```

Post-switch behavior:

- Calls `0x004b7e10` on the destination rectangle with the selected `dx,dy`; support docs identify this as `OffsetRect`.
- Calls virtual slot `+0x20` on the owner object with inherited bounds at owner `+0x44`. Descriptive source meaning is invalidation/refresh of the pane bounds; exact original method name is not proven.
- Calls `0x005975e0` on the timer subobject with event id `0`, delay `m_scrollInterval`, and zero payload fields.
- Returns true with `ret 0x0c`.

Resolved open questions:

- Timer interval is `this+0x108`, copied directly from constructor argument 4 and reused as the delay for both initial and repeat schedule calls.
- Scroll step is `this+0x10c`, copied directly from constructor argument 5 and used as the signed pixel delta magnitude.
- Direction is the byte at `this+0x110`, copied from constructor argument 6 and interpreted by the two matching four-way switches.

### Paint handler `0x004ffa60-0x004ffa9f`

Raw-body facts:

- Calls `0x004b9660(this, 0)`.
- Calls callback/global `dword_69B3FC(this, this+0x44)`.
- Calls callback/global `dword_69B3E8(this, this+0x118, this+0x128, this+0x144, 1, this+0x140, 0)`.
- Returns at `0x004ffa9e`.

Support-doc validation:

- `0x004b9660` is documented by `GrafPortDrawStateAccessors.md` as a GrafPort active draw/fill color setter at object offset `+0x74`. Generated labels that call it `FittingRoomListPane::SetTextColor` are stale and should not be propagated.
- `dword_69B3FC` and `dword_69B3E8` are documented by `SurfaceRenderCallbackTable.md` as surface render callback table entries. The exact original names remain unresolved, but roles are sufficiently strong:
  - `dword_69B3FC`: prepare/fill/present/invalidate region callback using the pane bounds.
  - `dword_69B3E8`: primary tile/frame blit callback using the frame draw record, source rectangle, destination rectangle, flags, palette state, and trailing zero.
- The source rectangle argument is `this+0x128`, a sub-rectangle inside the frame draw record at `this+0x118`.
- The destination rectangle argument is `this+0x144`.
- The palette/render state argument is `this+0x140`.

Resolved open questions:

- Frame draw record: `this+0x118` is the initialized and loaded frame draw record / tile context record. It is initialized by `0x00457a60`, filled by `LoadFrameDrawRecord`, and passed whole to the blit callback.
- Source rectangle: `this+0x128` is the draw record's source rect, used for width/height in the constructor and for paint blit.
- Palette/render state: `this+0x140` is a palette state/render-state pointer returned by `PaletteLib` helpers `0x00543d40` or `0x00543d70`. It is not a total-frame count or integer render mode.
- Destination rectangle: `this+0x144` is the scrolling destination rectangle initialized by `InitRectBounds`, advanced by `OffsetRect`, and passed to the paint blit callback.

## Xrefs, vtables, reachability, and construction route

Fresh IDA MCP xrefs could not be queried because the MCP service was offline. Local PE scans were used instead.

Raw dword hits for method starts:

```text
0x004ff7d0 constructor: 0 dword hits
0x004ff970 non-deleting destructor: 0 dword hits
0x004ff9e0 timer handler: 1 dword hit at VA 0x0061d92c, raw 0x0021c32c
0x004ffa60 paint handler: 1 dword hit at VA 0x0061d8d4, raw 0x0021c2d4
```

Raw dword hits for companion entries:

```text
0x00502ab0 scalar deleting destructor: 1 dword hit at primary vtable cell 0x0061d890
0x00502550 adjustor thunk: 1 dword hit at vtable cell 0x0061d8f8
0x0050255b adjustor thunk: 1 dword hit at vtable cell 0x0061d928
```

Raw dword hits for vtable addresses:

```text
0x0061d890 primary vtable address: appears in constructor, non-deleting destructor, and scalar deleting destructor vtable stores.
0x0061d8f8 adjustor vtable address: appears in constructor, non-deleting destructor, and scalar deleting destructor vtable stores.
0x0061d928 timer/handler vtable address: appears in constructor, non-deleting destructor, and scalar deleting destructor vtable stores.
```

Rel32 control-transfer hits:

```text
0x004ff7d0 constructor: 0 rel32 call/jump hits
0x004ff970 non-deleting destructor: 0 rel32 call/jump hits
0x004ff9e0 timer handler: 0 rel32 call/jump hits
0x004ffa60 paint handler: 0 rel32 call/jump hits
0x00502ab0 scalar deleting destructor: 2 rel32 hits from adjustor thunk jumps at 0x00502556 and 0x00502561
```

Whole-range dword hits inside `0x004ff7d0-0x004ffa9f`:

```text
0x004ff8ee, 0x004ff8fd, 0x004ff909, 0x004ff915
  constructor switch-table entries at 0x004ff960-0x004ff96f
0x004ff960
  constructor jump-table address operand at 0x004ff8ea
0x004ff9e0
  timer vtable cell at 0x0061d92c
0x004ff9f3, 0x004ff9fd, 0x004ffa04, 0x004ffa0b
  timer switch-table entries at 0x004ffa4c-0x004ffa5b
0x004ffa4c
  timer jump-table address operand at 0x004ff9ef
0x004ffa60
  paint vtable cell at 0x0061d8d4
```

Positive controls:

```text
ScrolledTextControlPane constructor 0x004ff040:
  rel32 calls found at 0x004ffc52, 0x004ffc79, 0x00500207, 0x0050033e

MadeBy control pane constructor 0x004ff400:
  rel32 call found at 0x0050052e

LoadFrameDrawRecord 0x004d1600:
  81 rel32 calls found

TimerHandler::ScheduleTimer wrapper 0x005975e0:
  163 rel32 calls found
```

Reachability conclusion:

- The constructor has no direct rel32 caller and no raw dword pointer in the current PE.
- The destructor has no direct rel32 caller and no raw dword pointer, which is expected for a non-deleting destructor body called by compiler-generated scalar wrapper lowering rather than a public vtable entry.
- Timer and paint are vtable-referenced.
- Companion scalar deleting destructor and adjustor thunks are vtable-referenced and route to the class destructor path.
- The absence of a constructor route is real under the current PE evidence, not a scanner failure, because positive controls find nearby constructor calls and high-fanout helper calls.
- Best interpretation: `ScrolledPictureControlPane` source was compiled into the binary and its virtual methods/destructor metadata are retained, but no currently visible local construction route reaches the constructor. It may be unused optional UI, externally/injected constructed, or retained dead class code. This blocks a feature-level caller attribution, but it does not block class/source ownership or first-draft C++ for the class methods themselves.

## Field and type recommendations

Recommended field map for [UID:00019Y]:

```text
this+0x108  int m_scrollInterval
  Constructor arg 4. Used as TimerHandler::ScheduleTimer delay in constructor and timer handler.

this+0x10c  int m_scrollStep
  Constructor arg 5. Used as signed pixel delta magnitude in timer handler.

this+0x110  unsigned char m_scrollDirection
  Constructor arg 6 low byte. Four-way enum. Values 0..3 are supported; out-of-range falls through the compiler switch default path and leaves constructor/timer local movement values from the initialized/default path visible in the raw code. Source should treat this as a caller-provided enum and not invent validation that is absent.

this+0x114  FrameTable/ImageFrameBlock *m_frameTable
  Return from LoadImageFrameTable/0x004d0f50. Destroyed by DestroyOwnedImageBlock/0x004d15d0. Original exact type name remains inferred from ImageFrameTable docs; `m_frameTable` is the best source-facing field name.

this+0x118  FrameDrawRecord m_frameDrawRecord
  Initialized by 0x00457a60, filled by LoadFrameDrawRecord/0x004d1600, passed whole to dword_69B3E8.

this+0x128  Rect m_frameDrawRecord.sourceRect
  Used for width/height calculation and passed as blit source rectangle.

this+0x140  PaletteState *m_paletteState
  Return from PaletteLib helpers 0x00543d40/0x00543d70. Passed to dword_69B3E8 as palette/render state.

this+0x144  Rect m_destinationRect
  Initialized by InitRectBounds/0x004b7c50, moved by OffsetRect/0x004b7e10, passed to dword_69B3E8 as blit destination rectangle.
```

Recommended enum:

```cpp
enum ScrolledPictureDirection {
    kScrollUp = 0,
    kScrollRight = 1,
    kScrollDown = 2,
    kScrollLeft = 3
};
```

These names are source-facing and descriptive. The numeric behavior is raw-byte proven; the original symbol spellings are not proven.

## Owner and source-family ranking

1. `ScrolledPictureControlPane` class `[UID:0000CH]` as canonical owner and emitter - recommended.
   Evidence: target is a constructor/destructor/timer/paint cluster for a single class; class support page already exists; vtable cells and companion scalar/thunk pages point to the same class; the methods use class state at derived offsets after the Pane/ControlPane base. By-structure guidance prefers direct class ownership for class method clusters, with the by-file owner as source root.

2. `ScrolledPictureControlPane.cpp` / file UID `[UID:0000NH]` as source root - recommended as file-level support, not direct target owner.
   Evidence: file support page owns the class family and proposed source tree places `ScrolledPictureControlPane.cpp` under `NexusTK/ui/controls/`. Existing metadata uses `0000NH`, but that is coarser than necessary now that class UID `0000CH` is present.

3. `ControlPane` / `Pane` base family - rejected as canonical owner.
   Evidence: constructor delegates to `ControlPane(parent, 8)` and destructor lowers to `Pane::~Pane`, but all open fields and virtual methods are derived `ScrolledPictureControlPane` state. Base classes are dependencies, not owners.

4. `ImageFrameTable`, `PaletteLib`, `SurfaceRenderCallbackTable`, `GrafPort` - rejected as canonical owners.
   Evidence: these are callee/service families for frame loading, palette selection, render callback dispatch, and draw-state setup. The target owns no generic image-frame or palette helper logic; it consumes those services in a pane method cluster.

5. `ScrolledTextControlPane` / adjacent text scroller family - rejected.
   Evidence: adjacency and similar scrolling concept are real, but the text scroller has separate constructor call sites and text-specific drawing. [UID:00019Y] loads image frame records, palette state, and uses image blit callbacks. It must not be merged with the text pane.

6. Feature-specific dialogs such as fitting room, made-by, collection, or character UI - rejected.
   Evidence: generated labels around helpers are polluted, and no constructor caller exists for this target. A feature owner would require a visible construction route or config/factory evidence, neither of which appears in the current PE or support docs.

7. Compiler/linker artifact or ignored raw block - rejected.
   Evidence: this is source-authored C++ method code with visible object state, callee calls, vtables, destructor, timer, and paint behavior. The internal switch tables and padding are compiler artifacts inside the cluster, but the cluster itself is not compiler-only and should remain reconstructable.

## Heuristic / Inference Reanalysis And Validation

### Raw-byte proven facts

- The half-open code range is `0x004ff7d0-0x004ffa9f`; `0x004ffa9f` is `cc` padding.
- Constructor range is `0x004ff7d0-0x004ff95e`; constructor returns with `ret 0x18`.
- Constructor internal alignment is `66 90` at `0x004ff95e-0x004ff960`.
- Constructor switch table is `0x004ff960-0x004ff970`, four dwords to `0x004ff8ee, 0x004ff8fd, 0x004ff909, 0x004ff915`.
- Non-deleting destructor range is `0x004ff970-0x004ff9d7`; destructor padding is nine `cc` bytes at `0x004ff9d7-0x004ff9e0`.
- Timer range is `0x004ff9e0-0x004ffa4b`; timer has a one-byte `90` aligner at `0x004ffa4b`.
- Timer switch table is `0x004ffa4c-0x004ffa5c`, four dwords to `0x004ff9f3, 0x004ff9fd, 0x004ffa04, 0x004ffa0b`.
- Timer/paint padding is four `cc` bytes at `0x004ffa5c-0x004ffa60`.
- Paint range is `0x004ffa60-0x004ffa9f`; final paint `ret` is at `0x004ffa9e`.
- Constructor sets vtables `0x0061d890`, `0x0061d8f8`, and `0x0061d928`.
- Destructor restores the same vtables before derived/base cleanup.
- Constructor stores arg 4 to `this+0x108`, arg 5 to `this+0x10c`, and arg 6 low byte to `this+0x110`.
- Constructor stores frame-table pointer at `this+0x114`, frame draw record at `this+0x118`, palette state at `this+0x140`, and destination rect at `this+0x144`.
- Timer direction deltas are `(0,-step)`, `(+step,0)`, `(0,+step)`, and `(-step,0)` for directions `0,1,2,3`.
- Paint passes `this+0x118`, `this+0x128`, `this+0x144`, and `this+0x140` to the frame blit callback.

### Existing IDA-backed docs validated

- `by-class/ScrolledPictureControlPane.md` correctly identifies the class family, vtable routes, companion thunk/scalar pages, and lack of direct constructor refs.
- `by-file/ScrolledPictureControlPane.md` correctly places the source file in `ui/controls/ScrolledPictureControlPane.cpp`.
- `[UID:0001AD]` correctly identifies the two destructor adjustor thunks at `0x00502550` and `0x0050255b`, adjusting by `0xa0` and `0xa4` before jumping to the scalar deleting destructor.
- `[UID:0001AI]` correctly identifies the scalar deleting destructor at `0x00502ab0-0x00502b58`, with vtable restoration, owned image block cleanup, and `Pane::~Pane` lowering.
- Pane docs and the executed B002 PaneCore report correctly resolve `0x00544580` as ordinary `Pane::~Pane`/base teardown. Stale `TextButtonEx` or old `0x004b8d20` labels are rejected.
- Rect geometry docs correctly identify `0x004b7c50` as rect initialization and `0x004b7e10` as rect offset.
- Timer wrapper docs correctly identify `0x005975e0` as generic timer scheduling, not a fitting-room-specific helper.
- Surface render callback docs correctly place `dword_69B3E8` and `dword_69B3FC` in the global render callback table.
- GrafPort draw-state docs correctly identify `0x004b9660` as a draw/fill color setter and reject generated fitting-room text-color labels.
- PaletteLib docs support `0x00543d40` and `0x00543d70` as palette-state selection helpers through `g_pPaletteLib`.
- ImageFrameTable docs support `0x004d0f50`, `0x004d1600`, and `0x004d15d0` as frame table load, frame draw record load, and owned image/frame block destruction.

### Inferences accepted

- Field names are descriptive rather than original-symbol proven:
  - `m_scrollInterval`, `m_scrollStep`, `m_scrollDirection`, `m_frameTable`, `m_frameDrawRecord`, `m_paletteState`, and `m_destinationRect`.
- Direction enum names are descriptive:
  - `kScrollUp`, `kScrollRight`, `kScrollDown`, `kScrollLeft`.
- The virtual slot `+0x20` call in the timer handler is an invalidate/refresh request on the owner pane bounds. Exact original method name is not proven, but paint/timer behavior and pane bounds argument support this meaning.
- Surface callback names such as `PrepareRenderRegion` and `BlitFrame` are descriptive. The callback roles are proven by arguments and support docs; original callback symbol spellings are not proven.
- Constructor route absence means the class is likely retained but not locally instantiated by visible code. This is a high-probability source-use inference, not a proof of source absence. It should be recorded as a reachability caveat, not a reason to blank C++.

### Alternatives rejected

- Do not keep the target below 85 solely because the constructor has no caller. The target is a class method cluster with vtable routes and companion destructor evidence; source reconstruction is independent of feature reachability.
- Do not leave formal C++ blank. The behavior and source shape are now strong enough for a first-draft source reconstruction with descriptive names.
- Do not classify the target as non-emitting, ignored, or compiler-only. Only the vtable stores, base destructor lowering, jump tables, and padding are compiler artifacts; the methods are source-authored.
- Do not emit scalar deleting destructor, adjustor thunks, vtable stores, or explicit base destructor calls as handwritten source for this target.
- Do not name `0x00544580` as `TextButtonEx::~TextButtonEx`; it is the shared `Pane::~Pane` base teardown.
- Do not name `0x004b9660` as `FittingRoomListPane::SetTextColor`; it is a GrafPort draw/fill state setter.
- Do not infer a feature owner such as fitting room, made-by, collection, or character UI without a constructor route. The reachable sibling `ScrolledTextControlPane` provides a positive-control example of what visible constructor calls look like.
- Do not merge this into `ScrolledTextControlPane`. The raw code loads image frame records, palette state, and blits image frames.

### Remaining blocker and score impact

Only one meaningful blocker remains: no visible local construction route to `0x004ff7d0` in the current PE, and no original source symbol names for the fields/callbacks. This affects feature-placement confidence and exact naming, not class ownership or source-emission eligibility.

Score impact:

- Completion can rise to `88` because all target-specific open questions are resolved or defensibly inferred and first-draft C++ can be populated.
- Confidence should be `90` because raw bytes, vtable routes, callee support docs, and positive-control scans agree. It should not exceed that until a live IDA xref recheck or source/config evidence explains why the constructor is present without visible local callers.

## First-draft C++ recommendation

Populate the target's formal C++ with first-draft code shaped like this. Names marked descriptive should remain subject to later source-symbol refinement, but the control flow and field semantics are target-specific and supported by raw bytes.

```cpp
// Descriptive names; original member names are not yet proven.
enum ScrolledPictureDirection {
    kScrollUp = 0,
    kScrollRight = 1,
    kScrollDown = 2,
    kScrollLeft = 3
};

ScrolledPictureControlPane::ScrolledPictureControlPane(
    Pane *parentPane,
    const char *frameResourceName,
    const char *paletteName,
    int scrollInterval,
    int scrollStep,
    int scrollDirection)
    : ControlPane(parentPane, 8),
      m_scrollInterval(scrollInterval),
      m_scrollStep(scrollStep),
      m_scrollDirection((unsigned char)scrollDirection),
      m_frameTable(0),
      m_paletteState(0)
{
    InitTileContext(&m_frameDrawRecord);

    m_frameTable = LoadImageFrameTable(frameResourceName, 0);
    LoadFrameDrawRecord(m_frameTable, 0, &m_frameDrawRecord);

    if (paletteName != 0)
        m_paletteState = g_pPaletteLib->GetPaletteState(paletteName);
    else
        m_paletteState = g_pPaletteLib->GetDefaultPaletteState();

    int frameWidth = m_frameDrawRecord.sourceRect.right -
        m_frameDrawRecord.sourceRect.left;
    int frameHeight = m_frameDrawRecord.sourceRect.bottom -
        m_frameDrawRecord.sourceRect.top;
    int paneWidth = m_bounds.right - m_bounds.left;
    int paneHeight = m_bounds.bottom - m_bounds.top;
    int centeredLeft = (paneWidth / 2) - (frameWidth / 2);
    int centeredTop = (paneHeight / 2) - (frameHeight / 2);

    switch (m_scrollDirection) {
    case kScrollUp:
        InitRectBounds(&m_destinationRect,
            centeredLeft,
            m_bounds.bottom,
            centeredLeft + frameWidth,
            m_bounds.bottom + frameHeight);
        break;

    case kScrollRight:
        InitRectBounds(&m_destinationRect,
            -frameWidth,
            centeredTop,
            0,
            centeredTop + frameHeight);
        break;

    case kScrollDown:
        InitRectBounds(&m_destinationRect,
            centeredLeft,
            -frameHeight,
            centeredLeft + frameWidth,
            0);
        break;

    case kScrollLeft:
        InitRectBounds(&m_destinationRect,
            m_bounds.right,
            centeredTop,
            m_bounds.right + frameWidth,
            centeredTop + frameHeight);
        break;
    }

    m_timerHandler.ScheduleTimer(0, m_scrollInterval, 0, 0);
}

ScrolledPictureControlPane::~ScrolledPictureControlPane()
{
    DestroyOwnedImageBlock(m_frameTable);
}

bool ScrolledPictureControlPane::OnTimerEvent(int eventId, int param1, int param2)
{
    int dx = 0;
    int dy = 0;

    switch (m_scrollDirection) {
    case kScrollUp:
        dy = -m_scrollStep;
        break;

    case kScrollRight:
        dx = m_scrollStep;
        break;

    case kScrollDown:
        dy = m_scrollStep;
        break;

    case kScrollLeft:
        dx = -m_scrollStep;
        break;
    }

    OffsetRect(&m_destinationRect, dx, dy);
    InvalidateRect(&m_bounds);
    m_timerHandler.ScheduleTimer(0, m_scrollInterval, 0, 0);
    return true;
}

void ScrolledPictureControlPane::OnPaintFrame()
{
    SetDrawColor(0);
    PrepareRenderRegion(this, &m_bounds);
    BlitFrame(this,
        &m_frameDrawRecord,
        &m_frameDrawRecord.sourceRect,
        &m_destinationRect,
        1,
        m_paletteState,
        0);
}
```

Notes for incorporation:

- `const char *` versus `const wchar_t *` is not proven by this target alone. The image/palette loader family should decide the exact string type. The report recommends not blocking C++ on this: use the prevailing `ImageFrameTable`/`PaletteLib` support type. If support docs use `char *`, keep `char *`; if the broader client convention proves wide paths, update both callee docs and this signature together.
- `InitTileContext`, `LoadImageFrameTable`, `LoadFrameDrawRecord`, `DestroyOwnedImageBlock`, `InitRectBounds`, `OffsetRect`, `SetDrawColor`, `PrepareRenderRegion`, and `BlitFrame` are source-facing descriptive/helper names backed by current support docs. Original names are not fully proven for all of them.
- `InvalidateRect` is a descriptive name for the virtual slot `+0x20` call. If Pane support later proves a better name, substitute it.
- Do not include explicit calls to `Pane::~Pane`, vtable assignments, switch tables, SEH scaffolding, adjustor thunks, scalar deleting destructor flag logic, or `operator delete` in this source C++ body.

## Companion page recommendations

[UID:0001AD] `ScrolledPictureControlPaneDestructorThunks`:

- Keep non-reconstructable / compiler-generated / non-emitting.
- Existing conclusion is valid: the first thunk adjusts `ecx` by `0xa0` and the second by `0xa4`, then both jump to `0x00502ab0`.
- If adding B004 incorporation text, use:

```text
B004 2026-06-18 revalidation: local PE dword/rel32 scans confirm the two thunk entries are vtable-routed adjustors for ScrolledPictureControlPane only. They should remain compiler-generated, non-reconstructable, and non-emitting; source behavior belongs in [UID:00019Y] and destructor wrapper/source relationship belongs in [UID:0001AI].
```

[UID:0001AI] `ScrolledPictureControlPaneScalarDeletingDestructor`:

- Keep class-owned by `[UID:0000CH]` and reconstructable as ABI/destructor wrapper evidence, but do not duplicate handwritten source C++ there if [UID:00019Y] is populated.
- If adding B004 incorporation text, use:

```text
B004 2026-06-18 revalidation: [UID:00019Y] proves the ordinary destructor body releases `m_frameTable`/`this+0x114` through the ImageFrameTable destroy helper before compiler-lowered `Pane::~Pane` at 0x00544580. The scalar deleting destructor remains target-specific ABI glue for the same class; first-draft handwritten destructor source should live with [UID:00019Y], while this page should document vtable restoration, base teardown lowering, flag-driven delete behavior, and the link to the class destructor.
```

## Exact target-page incorporation text

Recommended target header replacement:

```text
# 0x004ff7d0-0x004ffa9f ScrolledPictureControlPane Core

UID: 00019Y
FILE: by-memory/0x004ff7d0-0x004ffa9f.ScrolledPictureControlPaneCore.md
COMPLETION: 88
CONFIDENCE: 90
CANONICAL_OWNER: 0000CH
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000CH
EMITTER_POSITION_OPTIONAL:
```

Recommended status paragraph replacement:

```text
Status: source-authored `ScrolledPictureControlPane` class method cluster. The code-body half-open range is `0x004ff7d0-0x004ffa9f`; the final executable byte is the paint-handler `ret` at `0x004ffa9e`, followed by `cc` padding at `0x004ffa9f`. The existing last-byte filename spelling `0x004ffa9e` is stale and should be renamed to the half-open `0x004ffa9f` form during incorporation.
```

Recommended evidence block addition:

```text
Raw PE evidence (B004 2026-06-18):
- ImageBase `0x00400000`; `.text` RVA `0x1000`; `.text` raw pointer `0x400`; VA `0x004ff7d0` maps to raw offset `0x000febd0`.
- Whole target body/tables `0x004ff7d0-0x004ffa9f`: length `0x2cf`, SHA256 `0c607f155f88b4d90d06aebfc65fdfcd09f23959a34a8ad20a28acfd74f33298`.
- Constructor `0x004ff7d0-0x004ff95e`: SHA256 `446dc73007a983d7e55fccaae178ff22483f2271c1ec370ef1170d54e0187f21`.
- Constructor aligner `0x004ff95e-0x004ff960`: bytes `66 90`.
- Constructor switch table `0x004ff960-0x004ff970`: dwords `0x004ff8ee, 0x004ff8fd, 0x004ff909, 0x004ff915`; raw bytes `ee f8 4f 00 fd f8 4f 00 09 f9 4f 00 15 f9 4f 00`.
- Non-deleting destructor `0x004ff970-0x004ff9d7`: SHA256 `45718a4c81f4bbb4cc88586b8165a98d61d223898576e6edb9915e14e63ea354`.
- Destructor padding `0x004ff9d7-0x004ff9e0`: nine `cc` bytes.
- Timer handler `0x004ff9e0-0x004ffa4b`: SHA256 `30f7384bce580ef7ae85c156dccde3cefc0900dada897ceb3c72839e1a47468d`.
- Timer aligner `0x004ffa4b-0x004ffa4c`: byte `90`.
- Timer switch table `0x004ffa4c-0x004ffa5c`: dwords `0x004ff9f3, 0x004ff9fd, 0x004ffa04, 0x004ffa0b`; raw bytes `f3 f9 4f 00 fd f9 4f 00 04 fa 4f 00 0b fa 4f 00`.
- Timer/paint padding `0x004ffa5c-0x004ffa60`: four `cc` bytes.
- Paint handler `0x004ffa60-0x004ffa9f`: SHA256 `838e6d62ee54b9eda83584d704ec25a2ec85b4e410bf9a0a5b0a3262a09f52a9`.
```

Recommended resolved-field block:

```text
Resolved source-facing state map:
- `this+0x108`: `m_scrollInterval`, constructor argument 4, timer delay for initial and repeated `TimerHandler::ScheduleTimer` calls.
- `this+0x10c`: `m_scrollStep`, constructor argument 5, pixel delta magnitude.
- `this+0x110`: `m_scrollDirection`, constructor argument 6 low byte. Direction values are `0=up`, `1=right`, `2=down`, `3=left` by matching constructor off-screen placement with timer deltas.
- `this+0x114`: `m_frameTable` / owned image-frame block, return from `LoadImageFrameTable`, released by `DestroyOwnedImageBlock`.
- `this+0x118`: `m_frameDrawRecord`, initialized by `0x00457a60`, filled by `LoadFrameDrawRecord`, and passed whole to the frame blit callback.
- `this+0x128`: source rectangle inside `m_frameDrawRecord`.
- `this+0x140`: `m_paletteState`, return from `PaletteLib` default/named palette state helpers, passed to the blit callback.
- `this+0x144`: `m_destinationRect`, initialized by `InitRectBounds`, advanced by `OffsetRect`, and passed as the blit destination rectangle.
```

Recommended reachability block:

```text
Reachability recheck: IDA MCP was unavailable on 2026-06-18 (`127.0.0.1:13337` refused/offline), so local PE dword and rel32 scans were used. The constructor at `0x004ff7d0` has no direct rel32 caller and no raw dword pointer in the current PE. Timer `0x004ff9e0` is referenced by vtable cell `0x0061d92c`; paint `0x004ffa60` is referenced by vtable cell `0x0061d8d4`; scalar deleting destructor `0x00502ab0` is referenced by primary vtable cell `0x0061d890`; adjustor thunks `0x00502550` and `0x0050255b` are referenced by vtable cells `0x0061d8f8` and `0x0061d928`. Positive-control scans found nearby `ScrolledTextControlPane` constructor calls and high-fanout helper calls, so the missing constructor route is real under current PE evidence. Treat the class as compiled/retained but with no presently visible local construction route; do not assign a feature-specific caller owner without new evidence.
```

Recommended open-question replacement:

```text
Open questions resolved or narrowed:
- Timer interval, scroll step, direction, frame draw record, palette/render state, and destination rectangle are resolved to the field map above.
- `0x00544580` is the ordinary `Pane::~Pane` base teardown helper. Source destructor code should not call it manually; it is compiler-lowered after the derived destructor body.
- Constructor/destructor/timer/paint boundaries and internal switch tables/padding are raw-byte verified.
- Constructor reachability remains the only material caveat: no local caller or pointer route was found in the current PE. This limits feature placement and exact source-use confidence, not class ownership or source reconstruction.
```

## Exact support-doc incorporation text

`by-class/ScrolledPictureControlPane.md` replacement/addition:

```text
B004 2026-06-18 source-quality recheck resolves the prior field/source blockers for [UID:00019Y]. The class core is a source-authored constructor/destructor/timer/paint cluster at `0x004ff7d0-0x004ffa9f` with raw verified internal tables and padding. Recommended class fields are `m_scrollInterval` at `+0x108`, `m_scrollStep` at `+0x10c`, `m_scrollDirection` at `+0x110`, `m_frameTable` at `+0x114`, `m_frameDrawRecord` at `+0x118`, `m_paletteState` at `+0x140`, and `m_destinationRect` at `+0x144`. Direction values are `0=up`, `1=right`, `2=down`, `3=left` by matching constructor off-screen placement with timer deltas. Constructor reachability remains unresolved: local PE dword/rel32 scans find no direct call or pointer to `0x004ff7d0`, while timer/paint/scalar/thunk vtable cells remain present. This blocks feature-specific caller placement only; class ownership and first-draft C++ are now sufficient for [UID:00019Y].
```

`by-file/ScrolledPictureControlPane.md` replacement/addition:

```text
B004 2026-06-18 source-quality update: [UID:00019Y] should be owned/emitted through class [UID:0000CH] with this file as source root. The implementation belongs in `NexusTK/ui/controls/ScrolledPictureControlPane.cpp` and should include the constructor, ordinary destructor, timer handler, and paint handler. Do not emit the companion adjustor thunks [UID:0001AD] as source; do not duplicate scalar deleting destructor glue [UID:0001AI] as handwritten source. The source should use descriptive names for currently unproven original symbols: `m_scrollInterval`, `m_scrollStep`, `m_scrollDirection`, `m_frameTable`, `m_frameDrawRecord`, `m_paletteState`, `m_destinationRect`, `kScrollUp`, `kScrollRight`, `kScrollDown`, and `kScrollLeft`.
```

`by-memory/0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks.md` addition if desired:

```text
B004 2026-06-18 revalidation: local PE dword/rel32 scans confirm the two thunk entries are vtable-routed adjustors for ScrolledPictureControlPane only. They should remain compiler-generated, non-reconstructable, and non-emitting; source behavior belongs in [UID:00019Y] and destructor wrapper/source relationship belongs in [UID:0001AI].
```

`by-memory/0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor.md` addition if desired:

```text
B004 2026-06-18 revalidation: [UID:00019Y] proves the ordinary destructor body releases `m_frameTable`/`this+0x114` through the ImageFrameTable destroy helper before compiler-lowered `Pane::~Pane` at `0x00544580`. The scalar deleting destructor remains target-specific ABI glue for the same class; first-draft handwritten destructor source should live with [UID:00019Y], while this page should document vtable restoration, base teardown lowering, flag-driven delete behavior, and the link to the class destructor.
```

No Pane, RectGeometry, TimerHandler, PaletteLib, ImageFrameTable, GrafPortDrawState, or SurfaceRenderCallbackTable support-doc changes are required for correctness; their current claims are sufficient. If those docs are later consolidated, cross-link [UID:00019Y] as a consumer of the existing helpers rather than moving ownership.

## Exact coverage row replacement

Do not edit `by-memory/-coverage-report.md` directly as an agent. Supervisor should replace the existing `[UID:00019Y]` row at its current placement in the by-memory coverage report. Current placement is the Scrolled* control cluster near the existing stale row for `0x004ff7d0-0x004ffa9e`.

If the by-memory file is renamed to half-open spelling, use this replacement row:

```text
- [UID:00019Y][0x004ff7d0-0x004ffa9f.ScrolledPictureControlPaneCore](by-memory/0x004ff7d0-0x004ffa9f.ScrolledPictureControlPaneCore.md) 0x004ff7d0-0x004ffa9f | class method cluster | ScrolledPictureControlPaneCore : reconstructable : 88% : strong : B004 2026-06-18 source-quality pass raw-verified constructor/destructor/timer/paint boundaries, internal switch tables/padding, vtable routes, field map, direction semantics, frame/palette/destination rect roles, Pane base teardown at 0x00544580, companion thunk/scalar relationship, and first-draft class C++ through owner [UID:0000CH]; only remaining caveat is no visible local constructor caller/pointer route in the current PE.
```

If the supervisor defers the filename rename, keep the link target spelling but still use the half-open range:

```text
- [UID:00019Y][0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore](by-memory/0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore.md) 0x004ff7d0-0x004ffa9f | class method cluster | ScrolledPictureControlPaneCore : reconstructable : 88% : strong : B004 2026-06-18 source-quality pass raw-verified constructor/destructor/timer/paint boundaries, internal switch tables/padding, vtable routes, field map, direction semantics, frame/palette/destination rect roles, Pane base teardown at 0x00544580, companion thunk/scalar relationship, and first-draft class C++ through owner [UID:0000CH]; only remaining caveat is no visible local constructor caller/pointer route in the current PE.
```

## Metadata and generated-output consequences

Recommended by-memory metadata changes:

```text
COMPLETION:84 -> 88
CONFIDENCE:88 -> 90
CANONICAL_OWNER:0000NH -> 0000CH
RECONSTRUCTABLE:TRUE unchanged
EMITTER_UIDS:0000NH -> 0000CH
Formal C++: blank -> first-draft C++ populated
```

Recommended generated-output consequence after supervisor incorporation:

- `auto-generated/NexusTK/ui/controls/ScrolledPictureControlPane.cpp` should receive source for [UID:00019Y] through class owner `[UID:0000CH]` and file root `[UID:0000NH]`.
- The generated memory coverage should no longer list [UID:00019Y] as a 84/88 blank-C++ class cluster.
- Companion thunk [UID:0001AD] should remain non-emitting.
- Companion scalar wrapper [UID:0001AI] should remain linked to the class but should not duplicate the ordinary destructor body as separate handwritten C++ if [UID:00019Y] is populated.

## Validator commands/results

Commands/results recorded for this report:

> Executable block R001 was removed from this report and preserved verbatim in [00019Y-ScrolledPictureControlPaneCore-source-quality-removed.md](00019Y-ScrolledPictureControlPaneCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Local PE validation:

```text
Input: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
Result: PE image base, .text mapping, raw offsets, hashes, byte signatures, jump-table dwords, dword pointer hits, rel32 hits, and positive controls were derived from the local executable. The raw signatures and hit counts are listed above.
```

No project validator or doc generator was run because this is a report-only assignment and the agent did not edit generated/project-level files.

## Final open question

Only one open question remains after this pass:

```text
Why is there no visible local construction route to ScrolledPictureControlPane::ScrolledPictureControlPane at 0x004ff7d0?
```

Evidence checked:

- Local PE rel32 call/jump scan: no hits to `0x004ff7d0`.
- Local PE dword pointer scan: no hits to `0x004ff7d0`.
- Existing target/class/file docs: no direct IDA constructor refs reported.
- Positive controls: scanner finds nearby ScrolledText constructor calls and high-fanout helper calls, so the absence is not a tooling failure.

Why no stronger inference is safe:

- No feature-specific factory, dialog, config table, callback table, or vtable route to the constructor was found.
- The class vtables and virtual methods prove compiled class presence, not an instantiation site.
- Assigning the constructor to a feature owner would require evidence not present in the current PE/docs.

Impact:

- Blocks exact feature/caller placement only.
- Does not block class owner `[UID:0000CH]`, file root `[UID:0000NH]`, reconstructable status, or first-draft C++.

## Changed files

Only this Agent-B004 report was created/modified:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B004\research\00019Y-ScrolledPictureControlPaneCore-source-quality.md
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/00019Y-ScrolledPictureControlPaneCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:29","uid":"00019Y"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00019Y-ScrolledPictureControlPaneCore-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/00019Y-ScrolledPictureControlPaneCore-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00019Y"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
