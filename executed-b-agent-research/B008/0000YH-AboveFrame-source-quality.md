** TARGET-REPORT-UID:0000YH **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B008 Report: [UID:0000YH] AboveFrame Source Quality

Status: FINISHED
Date: 2026-06-19
Agent: B008

## Target

- Primary target: `source-3/project-documentation/by-memory/0x004610f0-0x0046178a.AboveFrame.md`
- Current metadata observed: `COMPLETION:84`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000JL`, `EMITTER_UIDS:0000JL`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B008/research/0000YH-AboveFrame-source-quality.md`
- Report-only rule followed: no by-* docs were edited, and `by-memory/-coverage-report.md` was not edited.

## Executive Recommendation

Raise the target to `COMPLETION:88`, `CONFIDENCE:91`, keep `RECONSTRUCTABLE:TRUE`, keep `CANONICAL_OWNER:0000JL`, and keep `EMITTER_UIDS:0000JL`.

The range is a FrameChrome-owned `AboveFrame` method/helper island, not a pure single-method target. It contains source-authored `AboveFrame` constructor/destructor/paint/notify bodies, source-authored file-level factory/refresh helper siblings, compiler-generated adjustor thunks, and a compiler-generated scalar/vector deleting destructor wrapper. The existing blank C++ is now stale: the source-authored bodies meet the C++ gate and should receive a first-draft C++ block. The adjustor thunks and scalar deleting destructor should remain documented as generated/no-code.

Recommended source-facing names:

- `AboveFrame::AboveFrame(int frameIndex, int x, int y)`
- `AboveFrame::~AboveFrame()`
- `AboveFrame::OnPaint()` for `0x00461660`; keep `DrawFrame` only as an old descriptive/decompiler name.
- `AboveFrame::OnNotify(ChangeMessage *message)` or project-local equivalent for `0x004616b0`; current `OnNotify` is acceptable if the support docs use that callback name consistently.
- `BuildAboveFrameBorder()` for `0x00461310`.
- `ReleaseDynamicAboveFrame()` for `0x004615b0`.
- `RecreateDynamicAboveFrame()` for `0x004615d0`.
- Compiler-generated only: `0x004616c8`, `0x004616d3`, and `0x004616e0`.

Recommended field/global names:

- `this+0x0f8`: `EPFTileContext m_tileContext`
- `this+0x108`: `m_tileContext.bounds` / frame tile bounds inside `EPFTileContext`
- `this+0x120`: `RectBounds m_positionedBounds` or `m_paneBounds`
- `this+0x130`: `uint8 m_framePaletteMode` / `m_resourceKind`; `0` selects `FRMPART.PAL`, `1` selects `TABS.PAL` in EPF mode
- `0x0066da97`: `g_useEpfAssets`
- `0x0067a740`: `g_pBackPane` / frame change-listener registration scope
- `0x0067a744`: `g_pEPFLib`
- `0x0067a840`: `g_pDynamicAboveFrame`
- `0x0067a874+0x20`: high-probability `GeneralPurposePanel::m_activeChildIndex` / `m_activeTabIndex`; it drives the dynamic AboveFrame resource index as `activeIndex + 5`
- `0x0069b364`: first main UI layer/context slot passed to `Pane::AddToLayer`

## Evidence Checked

Rule and workflow files checked:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B008/goal.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/tools/leaser/Agents/inference_research.md`

Primary and support docs checked:

- `by-memory/0x004610f0-0x0046178a.AboveFrame.md`
- `by-class/AboveFrame.md`
- `by-file/FrameChrome.md`
- `by-item/BuildAboveFrameBorder_00461310.md`
- `by-memory/0x004615b0-0x00461657.AboveFrameRefreshHelpers.md`
- `by-memory/0x004616c8-0x004616de.AboveFrameAdjustorThunks.md`
- `by-type/by-vtable/AboveFrameVtables.md`
- `by-type/by-vtable/FrameChromeVtableFamily.md`
- `by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md`
- `by-memory/0x00610f60-0x00610fe8.FrameChromeResourceStrings.md`
- `by-global/FrameChromeSlots.md`
- `by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md`
- `by-memory/0x0067a874-0x0067a878.g_pGeneralPurposePanel.md`
- `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md`
- `by-memory/0x0067a744-0x0067a748.g_pEPFLib.md`
- `by-global/g_pEPFLib.md`
- `by-memory/0x0067a740-0x0067a744.g_pBackPane.md`
- `by-memory/0x0069b364-0x0069b370.MainUiLayerSlotsHead.md`
- `by-memory/0x00544460-0x00545086.PaneCore.md`
- `by-type/by-struct/PaneLayout.md`
- `by-type/by-vtable/PaneVtables.md`
- `by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md`
- `by-memory/0x004f4b30-0x004f4b7f.ApplicationRegisterChangeListener.md`
- `by-memory/0x004f4b50-0x004f4b9f.ApplicationUnregisterChangeListener.md`
- `by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md`

Binary evidence checked:

- Local PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Image base/sections from local parser: `.text` `0x00401000-0x0060c600`, `.rdata` `0x0060d000-0x0066c200`, `.data` `0x0066d000-0x0069ce24`
- Local Capstone disassembly was used for target instructions, padding, xrefs, and data/string references.
- IDA MCP was attempted at `http://127.0.0.1:13337/mcp` and was unavailable in this session. This report therefore uses local PE/Capstone evidence plus the existing checked-in IDA-derived docs. The target should retain an "IDA MCP unavailable during B008 recheck" caveat if implementation notes mention evidence provenance.

## Range And Boundary Findings

The physical island is contiguous but internally split by normal `0xcc` padding. There is no evidence that the source-authored functions should merge with the preceding or following ranges.

Function inventory:

| Address range | Source/generation decision | Recommended name |
| --- | --- | --- |
| `0x004610f0-0x00461299` | source-authored class constructor | `AboveFrame::AboveFrame(int frameIndex, int x, int y)` |
| `0x004612a0-0x00461309` | source-authored class destructor body | `AboveFrame::~AboveFrame()` |
| `0x00461310-0x004615aa` | source-authored file-level factory/helper | `BuildAboveFrameBorder()` |
| `0x004615b0-0x004615c1` | source-authored file-level dynamic cleanup helper | `ReleaseDynamicAboveFrame()` |
| `0x004615d0-0x00461657` | source-authored file-level dynamic recreate helper | `RecreateDynamicAboveFrame()` |
| `0x00461660-0x004616af` | source-authored virtual paint/draw body | `AboveFrame::OnPaint()` |
| `0x004616b0-0x004616c8` | source-authored virtual notification body | `AboveFrame::OnNotify(ChangeMessage *message)` |
| `0x004616c8-0x004616de` | compiler-generated adjustor thunk pair | no authored C++ |
| `0x004616e0-0x0046178a` | compiler-generated scalar/vector deleting destructor wrapper | no authored C++ |

Padding/boundary bytes checked:

- `0x004610e0-0x004610ef` ends the prior function and has `0xcc 0xcc` immediately before the constructor.
- `0x00461299-0x0046129f`: seven bytes of `0xcc`.
- `0x00461309-0x0046130f`: seven bytes of `0xcc`.
- `0x004615aa-0x004615af`: six bytes of `0xcc`.
- `0x004615c1-0x004615cf`: fifteen bytes of `0xcc`.
- `0x00461658-0x0046165f`: eight bytes of `0xcc`.
- `0x004616de-0x004616df`: two bytes of `0xcc`.
- `0x0046178a-0x0046178f`: six bytes of `0xcc`.

The adjustor thunk bytes are exact and generated:

- `0x004616c8`: `sub ecx, 0xa0; jmp 0x004616e0`
- `0x004616d3`: `sub ecx, 0xa4; jmp 0x004616e0`

## Xrefs, Callers, And Callees

Direct constructor callers:

- `0x00461368`, `0x004613a0`, `0x004613db`, `0x00461423`, `0x00461476`, `0x004614ae`, `0x004614e9`, `0x00461535`, `0x00461570` from `BuildAboveFrameBorder()`
- `0x00461626` from `RecreateDynamicAboveFrame()`

Direct helper callers:

- `BuildAboveFrameBorder()` at `0x00461310` is called from `0x004f802c` and `0x004f8670` inside the main UI initialization route.
- `ReleaseDynamicAboveFrame()` at `0x004615b0` is called from `0x004b872e` and `0x004b8a62`.
- `RecreateDynamicAboveFrame()` at `0x004615d0` is called from `0x004b8733` and `0x004b8a67`.

Virtual/data refs:

- Primary vtable slot `0x00610edc` points to `0x004616e0`, the scalar deleting destructor wrapper.
- Primary vtable slot `0x00610ee4` points to `0x004616b0`, the notification body.
- Primary vtable slot `0x00610f20` points to `0x00461660`, the paint/draw body.
- Secondary/tertiary vtable refs `0x00610f28` and `0x00610f58` point to the adjustor thunks.

Important callees and dependencies:

- `0x00544460`: `Pane::Pane(unsigned char mode)` / `Pane(PaneMode mode)`
- `0x00544580`: `Pane::~Pane()`
- `0x00544690`: `Pane::MarkForDeletion()`
- `0x00544bd0`: `Pane::SetBounds(...)`
- `0x00544c70`: `Pane::AddToLayer(...)`
- `0x00457a60`: `EPFTileContext` constructor/init for `this+0x0f8`
- `0x004d02f0`: `ResourceLayoutTable::LookupLayoutEntry(...)`
- `0x004b9980`: shared `RenderTileFrame(...)` paint helper
- `0x004f4b30`: register change listener wrapper
- `0x004f4b50`: unregister change listener wrapper
- allocation/free wrappers: class helpers call normal `operator new`/virtual delete routes; these are dependencies, not ownership signals.

## Constructor Source Shape

`AboveFrame::AboveFrame(int frameIndex, int x, int y)` is a real source-authored constructor.

Confirmed behavior:

- Calls `Pane::Pane(1)`.
- Writes the primary and secondary/tertiary `AboveFrame` vtable pointers:
  - `this+0x00 = 0x00610edc`
  - `this+0xa0 = 0x00610f28`
  - `this+0xa4 = 0x00610f58`
- Constructs/initializes the `EPFTileContext` member at `this+0x0f8`.
- Branches on `g_useEpfAssets` (`0x0066da97`).
- In EPF/current mode:
  - `frameIndex < 4`: loads `FRMPART.EPF` through `g_pEPFLib` and sets `this+0x130 = 0`.
  - `frameIndex >= 4`: loads `TABS.EPF` through `g_pEPFLib` and sets `this+0x130 = 1`.
  - The tab frame index is not a raw pass-through: the binary computes a compact tab index from the requested `frameIndex`. For values seen in this island, the dynamic helper passes `activeIndex + 5`, and the factory passes fixed frame values.
- In legacy mode:
  - loads `FRMPART.EPD` through `g_pEPFLib`.
  - does not need `this+0x130`, because paint ignores that byte when `g_useEpfAssets` is false.
- Copies/positions the tile bounds into `this+0x120`.
- Calls the pane bounds/layer helpers.
- Registers this pane for the `0x676f6f67` (`'goog'`) notification tag through the `g_pBackPane`/application-scope listener route.

The constructor signature is best expressed as `AboveFrame::AboveFrame(int frameIndex, int x, int y)`. The helper call sites pass resource/frame index first, then two screen-position coordinates. Existing docs that describe this as frame chrome "part index + position" are valid; source docs should avoid raw parameter names like `param_1`.

## Destructor And Generated Destructor Support

`0x004612a0` is the source destructor body:

- Restores the three `AboveFrame` vtable pointers as expected during destruction.
- Unregisters this instance from the `0x676f6f67` notification tag through the same `g_pBackPane`/application-scope route.
- Calls `Pane::~Pane()`.

The source body should be written as:

```cpp
AboveFrame::~AboveFrame()
{
    g_pBackPane->UnregisterChangeListener(this, kAboveFrameNotifyTag, 0);
}
```

The explicit vtable stores and base destructor call are compiler output, not source text.

`0x004616e0` is not a handwritten source method. It repeats destructor cleanup and then implements compiler-generated deleting behavior:

- If the delete flag requests scalar deletion, it calls the delete wrapper.
- If the vector/EH flag path is active, it routes through the vector/guard delete helper with size `0x134`.

The scalar deleting destructor should be documented in the target and vtable support docs but should not receive separate authored C++.

## Paint And Notify Source Shape

`0x00461660` should be renamed/recast from descriptive `DrawFrame` to source-facing `AboveFrame::OnPaint()` unless the project-wide Pane virtual vocabulary is standardized as `OnDraw`. Evidence favors `OnPaint`:

- It is reached only through primary vtable slot `+0x44`.
- The Pane family support docs commonly describe comparable slot bodies as paint callbacks.
- The body has no factory/setup behavior; it only chooses a palette and calls the shared render helper.

Paint behavior:

- If `g_useEpfAssets` is true:
  - `m_framePaletteMode == 0` selects `FRMPART.PAL`.
  - `m_framePaletteMode != 0` selects `TABS.PAL`.
- If `g_useEpfAssets` is false:
  - always selects `NPAL5.PAL`.
- Calls `RenderTileFrame(...)` with `m_tileContext` and the tile/frame bounds at `this+0x108`.

`0x004616b0` is the source notification callback:

- It returns with `ret 8`, so it is a virtual callback with two stack arguments.
- It reads the notification/message pointer and checks dword `message+4`.
- If the tag is `0x676f6f67` (`'goog'`), it calls `Pane::MarkForDeletion()` on this pane.

Recommended source-facing signature:

```cpp
void AboveFrame::OnNotify(ChangeMessage *message)
```

If the surrounding source model uses `OnNotification` instead of `OnNotify`, use that project-wide spelling; do not keep raw `sub_4616B0`.

## Factory And Refresh Helper Source Shape

`BuildAboveFrameBorder()` at `0x00461310` is source-authored file-level `FrameChrome` code. The existing helper name is acceptable and should no longer be treated as raw unresolved decompiler output.

Current/EPF branch:

- `g_aboveFramePrimary` / slot `0x0067a834` = `new AboveFrame(0, 0, 0)`
- `g_aboveFrameEpfMode` / slot `0x0067a83c` = `new AboveFrame(1, 9, 0)`
- `g_aboveFrameBottom` / slot `0x0067a838` = `new AboveFrame(2, 9, 0x328)`
- `g_pDynamicAboveFrame` / slot `0x0067a840` = `new AboveFrame(g_pGeneralPurposePanel->m_activeChildIndex + 5, 0x4f, 0x328)` when allocation succeeds, else `0`

Legacy branch:

- `0x0067a848` = `new AboveFrame(0, 0x0c, 0x0e)`
- `0x0067a834` = `new AboveFrame(1, 0x0c, 0x7d)`
- `0x0067a838` = `new AboveFrame(2, 0x0c, 0x17a)`
- Loop creates five top/side legacy frames at `0x0067a84c + i*4` with frame index `3` and y positions starting at `0x5c+6`, step `0x3f`.
- Loop creates five bottom/side legacy frames at `0x0067a860 + i*4` with frame index `4` and y positions starting at `0x5c`, step `0x3f`.

`ReleaseDynamicAboveFrame()` at `0x004615b0`:

- Reads `g_pDynamicAboveFrame` at `0x0067a840`.
- If non-null, calls the virtual deleting destructor with delete flag `1`.
- Does not clear the global slot itself. The name "Release" is therefore better than "Clear".

`RecreateDynamicAboveFrame()` at `0x004615d0`:

- Allocates a new `AboveFrame` of size `0x134`.
- Uses `g_pGeneralPurposePanel->m_activeChildIndex + 5` as the resource/frame index.
- Uses coordinates `0x4f, 0x328`.
- Stores the result in `g_pDynamicAboveFrame`; stores `0` on allocation failure.

The source-level relationship is: GeneralPurposePanel switch/update code calls the FrameChrome helper pair after the active panel changes, but the helpers and `g_pDynamicAboveFrame` remain FrameChrome-owned.

## Vtables, Resource Strings, And Global Slots

Class name confidence is higher than the current "medium" language in some support docs. The decorated vtable names and vtable family docs prove the class name `AboveFrame`.

Vtable layout facts:

- Primary vtable base: `0x00610edc`
- Primary slot `+0x00`: scalar deleting destructor wrapper `0x004616e0`
- Primary slot `+0x08`: notification callback `0x004616b0`
- Primary slot `+0x44`: paint/draw callback `0x00461660`
- Secondary vtable: `0x00610f28`, adjustor thunk subtracting `0xa0`
- Tertiary vtable: `0x00610f58`, adjustor thunk subtracting `0xa4`

Resource strings used by this island:

- `0x00610f60`: `FRMPART.EPF`
- `0x00610f78`: `TABS.EPF`
- `0x00610f8c`: `FRMPART.EPD`
- `0x00610fa4`: `FRMPART.PAL`
- `0x00610fbc`: `TABS.PAL`
- `0x00610fd0`: `NPAL5.PAL`

These strings belong to the broader FrameChrome resource string pool, not to an independent AboveFrame source file.

Global slot route:

- `0x0067a834-0x0067a874` are AboveFrame/FrameChrome slots.
- `0x0067a840` is the dynamic AboveFrame pointer.
- `0x0067a874` is not an AboveFrame slot. It is `g_pGeneralPurposePanel`; this target only reads `g_pGeneralPurposePanel+0x20` to derive a dynamic resource frame index.

## Open Questions Resolved Or Capped

### Exact source file

Best answer: keep `FrameChrome.cpp` / [UID:0000JL] as the source/emitter route.

Evidence: the constructor, helper factory, refresh helpers, FramePartPane family, frame resource strings, global slots, `goog` notification, and main UI init callers cluster tightly in the FrameChrome feature. There is no direct source metadata proving a separate `AboveFrame.cpp`, and the support docs already use `FrameChrome.md` as the file owner. A separate class file remains possible but is weaker than the shared FrameChrome source-body inference. This keeps confidence capped below the high 90s but does not block C++ emission.

### `GeneralPurposePanel+0x20`

Best answer: high-probability active child/tab index field.

Evidence: `g_pGeneralPurposePanel` is a real singleton/global at `0x0067a874`. Its constructor stores seven child panes at offsets `+0x04` through `+0x1c`; the next dword at `+0x20` is read after GeneralPurposePanel switch callers invoke `ReleaseDynamicAboveFrame()`/`RecreateDynamicAboveFrame()`. The field feeds `activeIndex + 5`, matching the current-mode `TABS.EPF` dynamic resource route. Exact original spelling is not provable from local binary evidence, so docs should say `m_activeChildIndex` / `m_activeTabIndex` is provisional.

### `g_pEPFLib` type

Best answer: keep global name `g_pEPFLib` and call it through `ResourceLayoutTable::LookupLayoutEntry(...)`.

Evidence: the target uses `g_pEPFLib` as the `ecx` receiver for `0x004d02f0`. Existing support docs still have a live type-name question (`ImageLib*` versus a resource-layout-table object). This is a type naming cap, not a behavior blocker.

### Paint virtual spelling

Best answer: recommend `OnPaint`.

Evidence: vtable primary slot `+0x44`, callback-only reachability, palette selection, and shared render helper call fit the Pane paint callback pattern. `DrawFrame` is useful as a descriptive old name but weaker as source-facing text. If project-wide Pane vocabulary ultimately standardizes on `OnDraw`, only the spelling should change; the signature/source shape is resolved.

### Scalar deleting destructor and adjustor thunks

Best answer: no authored C++.

Evidence: both adjustor thunks are single subtract-and-jump compiler thunks. The scalar deleting destructor duplicates destructor cleanup, tests compiler delete flags, and branches into scalar/vector delete support. The source code is the virtual destructor declaration/body only.

## Rejected Alternatives

- Reject IDA name pollution around nearby helper islands such as `__std_parallel_algorithms_hw_threads`: `0x004615d0` clearly allocates and stores a dynamic `AboveFrame`.
- Reject treating `0x0067a874` as an AboveFrame slot or source object. Existing docs and xrefs identify it as `g_pGeneralPurposePanel`.
- Reject Surface/GrafPort ownership for the paint method. `RenderTileFrame` is a shared rendering dependency; ownership of this virtual callback remains `AboveFrame`/FrameChrome.
- Reject ResourceLayoutTable or EPF library ownership for the constructor. `LookupLayoutEntry` is a dependency used to load frame tile context data.
- Reject GeneralPurposePanel ownership for the refresh helpers. GeneralPurposePanel callers trigger the helper pair, but the global slot and object allocation are FrameChrome/AboveFrame state.
- Reject hand-written source for the adjustor thunks and scalar deleting destructor wrapper.
- Reject `reserve` or collection semantics. This island creates UI pane objects and does not manipulate array capacity.

## First-Draft C++ Readiness

The target meets the C++ gate:

- `RECONSTRUCTABLE:TRUE`
- Nonblank valid emitter route: `EMITTER_UIDS:0000JL`
- Current average score is `(84 + 90) / 2 = 87`, above the `>85` gate.

Recommended policy:

- Emit first-draft source-style C++ for the source-authored class methods and file-level helpers in this island.
- Do not emit authored C++ for `0x004616c8-0x004616de` or `0x004616e0-0x0046178a`.
- If the implementation callback prefers avoiding duplicate helper code because [UID:0000U2] and [UID:0000YI] are separate child pages, put full helper C++ in those child pages and include only class methods in the target formal block. The target should still summarize helper source shape and boundaries.

Recommended first-draft C++ for the target/source island:

```cpp
namespace
{
    const unsigned int kAboveFrameNotifyTag = 0x676f6f67; // 'goog'

    enum AboveFramePaletteMode
    {
        kAboveFramePaletteFrame = 0,
        kAboveFramePaletteTabs = 1
    };
}

AboveFrame::AboveFrame(int frameIndex, int x, int y)
    : Pane(1),
      m_tileContext(),
      m_framePaletteMode(kAboveFramePaletteFrame)
{
    if (g_useEpfAssets)
    {
        if (frameIndex < 4)
        {
            g_pEPFLib->LookupLayoutEntry(L"FRMPART.EPF", frameIndex, &m_tileContext);
            m_framePaletteMode = kAboveFramePaletteFrame;
        }
        else
        {
            int tabFrame = frameIndex - 5;
            if (frameIndex < 6)
                tabFrame = frameIndex - 4;

            g_pEPFLib->LookupLayoutEntry(L"TABS.EPF", tabFrame, &m_tileContext);
            m_framePaletteMode = kAboveFramePaletteTabs;
        }
    }
    else
    {
        g_pEPFLib->LookupLayoutEntry(L"FRMPART.EPD", frameIndex, &m_tileContext);
    }

    m_positionedBounds = m_tileContext.bounds;
    m_positionedBounds.Offset(x, y);

    SetBounds(m_positionedBounds, false);
    AddToLayer(g_mainUiLayerSlots[0], m_positionedBounds, 0, 0);

    g_pBackPane->RegisterChangeListener(this, kAboveFrameNotifyTag, 0);
}

AboveFrame::~AboveFrame()
{
    g_pBackPane->UnregisterChangeListener(this, kAboveFrameNotifyTag, 0);
}

void AboveFrame::OnPaint()
{
    const wchar_t *paletteName = L"NPAL5.PAL";

    if (g_useEpfAssets)
        paletteName = (m_framePaletteMode == kAboveFramePaletteTabs) ? L"TABS.PAL" : L"FRMPART.PAL";

    RenderTileFrame(&m_tileContext,
                    &m_tileContext.bounds,
                    &m_tileContext.bounds,
                    1,
                    paletteName,
                    0);
}

void AboveFrame::OnNotify(ChangeMessage *message)
{
    if (message != 0 && message->tag == kAboveFrameNotifyTag)
        MarkForDeletion();
}

void BuildAboveFrameBorder()
{
    if (g_useEpfAssets)
    {
        g_aboveFramePrimary = new AboveFrame(0, 0, 0);
        g_aboveFrameEpfTop = new AboveFrame(1, 9, 0);
        g_aboveFrameBottom = new AboveFrame(2, 9, 0x328);

        g_pDynamicAboveFrame = new AboveFrame(g_pGeneralPurposePanel->m_activeChildIndex + 5,
                                              0x4f,
                                              0x328);
        return;
    }

    g_aboveFrameLegacyFixed = new AboveFrame(0, 0x0c, 0x0e);
    g_aboveFramePrimary = new AboveFrame(1, 0x0c, 0x7d);
    g_aboveFrameBottom = new AboveFrame(2, 0x0c, 0x17a);

    int y = 0x5c;
    for (int i = 0; i < 5; ++i, y += 0x3f)
    {
        g_aboveFrameLegacyTop[i] = new AboveFrame(3, y + 6, 0x0e);
        g_aboveFrameLegacyBottom[i] = new AboveFrame(4, y, 0x1a4);
    }
}

void ReleaseDynamicAboveFrame()
{
    if (g_pDynamicAboveFrame != 0)
        delete g_pDynamicAboveFrame;
}

void RecreateDynamicAboveFrame()
{
    g_pDynamicAboveFrame = new AboveFrame(g_pGeneralPurposePanel->m_activeChildIndex + 5,
                                          0x4f,
                                          0x328);
}
```

Draft caveats to carry into docs:

- `ChangeMessage`, `m_tileContext.bounds`, `Offset`, `SetBounds`, `AddToLayer`, and `RegisterChangeListener` spellings are source-quality names inferred from behavior/support docs. If the final project types use different method names, adjust spelling but preserve behavior.
- `m_activeChildIndex` is high-probability, not proven original spelling.
- The `new` expressions compile to explicit zero-on-allocation-failure paths in optimized code; the source does not need raw null-assignment scaffolding except where the original style intentionally used it.
- The scalar deleting destructor, vector-delete branch, and adjustor thunks are intentionally omitted from authored C++.

## Recommended Target Doc Changes

For `by-memory/0x004610f0-0x0046178a.AboveFrame.md`:

1. Metadata:
   - `COMPLETION:88`
   - `CONFIDENCE:91`
   - keep `RECONSTRUCTABLE:TRUE`
   - keep `CANONICAL_OWNER:0000JL`
   - keep `EMITTER_UIDS:0000JL`
2. Replace old unresolved source-shape wording with:
   - This is a FrameChrome-owned `AboveFrame` method/helper island.
   - Class methods are source-authored `AboveFrame` bodies.
   - `BuildAboveFrameBorder`, `ReleaseDynamicAboveFrame`, and `RecreateDynamicAboveFrame` are file-level FrameChrome helpers in the same source route.
   - Adjustor thunks and scalar deleting destructor wrapper are compiler-generated/no-code.
3. Add/update field table:
   - `+0x0f8`: `EPFTileContext m_tileContext`; constructor calls the member init helper at `0x00457a60`.
   - `+0x108`: `RectBounds m_tileContext.bounds`; used by paint as both tile source/destination bounds.
   - `+0x120`: `RectBounds m_positionedBounds`; computed from tile bounds plus constructor coordinates and passed to Pane bounds/layer setup.
   - `+0x130`: `uint8 m_framePaletteMode` / `m_resourceKind`; `0` frame palette, `1` tab palette in EPF mode; ignored by legacy paint route.
4. Rename method headings:
   - `DrawFrame` -> `OnPaint` with old `DrawFrame` label preserved as a former/descriptive name if needed.
   - `OnNotify` should have a source-style callback signature and `0x676f6f67` tag semantics.
5. Add exact xref/caller list:
   - constructor refs from `0x00461368`, `0x004613a0`, `0x004613db`, `0x00461423`, `0x00461476`, `0x004614ae`, `0x004614e9`, `0x00461535`, `0x00461570`, `0x00461626`
   - helper refs from `0x004f802c`, `0x004f8670`, `0x004b872e`, `0x004b8a62`, `0x004b8733`, `0x004b8a67`
   - vtable/data refs from `0x00610edc`, `0x00610ee4`, `0x00610f20`, `0x00610f28`, `0x00610f58`
6. Add exact boundary/padding notes listed in this report.
7. Add first-draft C++ or equivalent source block from this report.
8. Add 2026-06-19 change-log entry:
   - "B008 source-quality recheck resolved the FrameChrome `AboveFrame` island into source-authored constructor/destructor/OnPaint/OnNotify plus source-authored factory/refresh helper siblings, confirmed compiler-generated adjustor/scalar-delete boundaries, rechecked padding/xrefs/vtables/resource strings/global slots from local PE/Capstone after IDA MCP was unavailable, identified `g_pGeneralPurposePanel+0x20` as high-probability active child/tab index for dynamic frame selection, rejected stale helper/source-owner alternatives, and marked first-draft C++ ready for authored bodies."

## Recommended Support Doc Changes

`by-class/AboveFrame.md`:

- Recommend `COMPLETION:87`, `CONFIDENCE:91`.
- Strengthen class-name proof: decorated vtable names and vtable family docs prove `AboveFrame`; remove "medium" class-name wording.
- Add field table details for `m_tileContext`, `m_tileContext.bounds`, `m_positionedBounds`, and `m_framePaletteMode`.
- Method table should use `AboveFrame::OnPaint()` and `AboveFrame::OnNotify(ChangeMessage *message)`.
- Explicitly state scalar deleting destructor and adjustor thunks are compiler output generated from the virtual destructor and secondary base views.

`by-file/FrameChrome.md`:

- Recommend `COMPLETION:88`, `CONFIDENCE:87` if the file doc incorporates this report; keep the exact filename caveat.
- State [UID:0000YH] is a FrameChrome source island containing both `AboveFrame` class methods and nearby file-level helper bodies.
- Keep FrameChrome as the source/emitter route; do not move ownership to Surface, ResourceLayoutTable, or GeneralPurposePanel.
- Note that one-file versus split-file source layout remains unproven, but the evidence favors FrameChrome.cpp as the current source route.

`by-item/BuildAboveFrameBorder_00461310.md`:

- Treat `BuildAboveFrameBorder()` as the best source-facing helper name.
- Add current/EPF branch and legacy branch constructor arguments exactly as listed above.
- Replace any `dword_67A874`/raw source wording with `g_pGeneralPurposePanel->m_activeChildIndex + 5` as a high-probability inferred field route.
- Note that `0x0067a874` is not an AboveFrame slot.

`by-memory/0x004615b0-0x00461657.AboveFrameRefreshHelpers.md`:

- Recommend `COMPLETION:87`, `CONFIDENCE:91`.
- Use `ReleaseDynamicAboveFrame()` and `RecreateDynamicAboveFrame()` as source-facing names.
- State release deletes the current object but does not clear the slot in this helper.
- State recreate uses `g_pGeneralPurposePanel->m_activeChildIndex + 5`, `0x4f`, `0x328`, and stores to `g_pDynamicAboveFrame`.
- Remove/replace any sketch that treats `0x0067a874` as an AboveFrame source object.

`by-memory/0x004616c8-0x004616de.AboveFrameAdjustorThunks.md`:

- Keep `RECONSTRUCTABLE:FALSE` / no-code.
- Add the exact local-byte recheck and cross-link to this report if implementation wants a fresh evidence note.

`by-type/by-vtable/AboveFrameVtables.md`:

- Update slot `+0x44` source-facing name to `AboveFrame::OnPaint()` if accepted.
- Keep slot `+0x00` as scalar deleting destructor wrapper and the secondary/tertiary entries as adjustor thunks.

`by-memory/0x00610f60-0x00610fe8.FrameChromeResourceStrings.md`:

- Add cross-note that `AboveFrame::OnPaint()` selects `FRMPART.PAL`/`TABS.PAL` in EPF mode based on `this+0x130`, and `NPAL5.PAL` in legacy mode.

`by-global/FrameChromeSlots.md` and `by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md`:

- Add/confirm `0x0067a840` as `g_pDynamicAboveFrame`.
- Keep `0x0067a874` outside the AboveFrame slot range and point readers to `g_pGeneralPurposePanel`.
- Add provisional names for legacy frame arrays only if the slot docs already accept descriptive slot names; otherwise keep the address-based table with the constructor argument evidence.

`by-memory/0x0067a874-0x0067a878.g_pGeneralPurposePanel.md`:

- Add cross-note that `+0x20` is read by FrameChrome dynamic AboveFrame creation as an active child/tab index and becomes `TABS.EPF` frame index `+5`.
- Mark exact original field spelling provisional.

`by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md`:

- Add a small cross-note that `AboveFrame::OnPaint()` calls `RenderTileFrame` at `0x004b9980`; this confirms it is a shared paint dependency, not target ownership.

## Exact Coverage Row Text

Do not edit `by-memory/-coverage-report.md` from the B-agent report/implementation unless the supervisor explicitly owns that change. Recommended replacement row:

```text
    - [UID:0000YH][0x004610f0-0x0046178a.AboveFrame](by-memory/0x004610f0-0x0046178a.AboveFrame.md) 0x004610f0-0x0046178a | class/helper island | AboveFrame : reconstructable : 88% : very strong : B008 2026-06-19 source-quality recheck resolves the FrameChrome `AboveFrame` island as class ctor/dtor/OnPaint/OnNotify bodies plus file-level `BuildAboveFrameBorder` and dynamic release/recreate helper siblings, compiler-generated adjustor/scalar-delete support, exact padding/bounds, ten constructor refs, factory/refresh callers, vtable/resource string/global slot routes, `g_pGeneralPurposePanel+0x20` active-child frame-index inference, `g_useEpfAssets`/`g_pEPFLib`/`RenderTileFrame` dependencies, rejected STL/Surface/ResourceLayout/GeneralPurposePanel ownership alternatives, and first-draft C++ readiness for source-authored bodies.
```

## Validator Needs After Implementation

No validators were run for this report-only task because no by-* docs were edited.

Expected scoped validation commands from `E:\NTK\GhidraBridge\source-3\project-documentation` after an implementation callback:

> Executable block R001 was removed from this report and preserved verbatim in [0000YH-AboveFrame-source-quality-removed.md](0000YH-AboveFrame-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If implementation edits the optional cross-note support docs, also run:

> Executable block R002 was removed from this report and preserved verbatim in [0000YH-AboveFrame-source-quality-removed.md](0000YH-AboveFrame-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## IDA Rename, Type, And Comment Recommendations

High confidence:

- Rename/comment `0x004610f0` as `AboveFrame::AboveFrame(int frameIndex, int x, int y)`.
- Rename/comment `0x004612a0` as `AboveFrame::~AboveFrame()`.
- Rename/comment `0x00461660` as `AboveFrame::OnPaint()`.
- Rename/comment `0x004616b0` as `AboveFrame::OnNotify(ChangeMessage *message)` or project-wide callback spelling.
- Rename/comment `0x004615b0` as `ReleaseDynamicAboveFrame()`.
- Rename/comment `0x004615d0` as `RecreateDynamicAboveFrame()`.
- Keep/comment `0x004616e0` as compiler-generated scalar/vector deleting destructor wrapper.
- Keep/comment `0x004616c8` and `0x004616d3` as adjustor thunks for `this-0xa0` and `this-0xa4`.
- Type/comment `this+0x0f8` as `EPFTileContext m_tileContext`.
- Type/comment `this+0x108` as `m_tileContext.bounds`.
- Type/comment `this+0x120` as `RectBounds m_positionedBounds`.
- Type/comment `this+0x130` as `uint8 m_framePaletteMode` / `m_resourceKind`.
- Label/comment `0x0067a840` as `g_pDynamicAboveFrame`.

Medium confidence / provisional:

- Label/comment `g_pGeneralPurposePanel+0x20` as `m_activeChildIndex` or `m_activeTabIndex`.
- Keep `g_pEPFLib` as the global name until the final ImageLib/ResourceLayoutTable concrete type is resolved.
- Slot names for the fixed/legacy AboveFrame globals should be introduced conservatively unless FrameChromeSlots already has accepted source-style names for the whole family.

## Implementation-Callback Checklist

When the supervisor accepts this report and sends an implementation callback:

1. Lease the target/support docs before editing.
2. Do not edit `by-memory/-coverage-report.md`; keep the exact row above in notes for supervisor-owned coverage update.
3. Update target metadata to `88/91`, keeping owner/emitter `0000JL`.
4. Replace stale source-shape uncertainty with the method/helper island decision.
5. Insert the field/global/method names, boundary facts, xrefs, vtable refs, resource strings, rejected alternatives, and open-question resolutions from this report.
6. Add the first-draft C++ block for source-authored bodies, or split helper C++ into [UID:0000U2]/[UID:0000YI] if the supervisor asks to avoid duplicate helper emission.
7. Keep adjustor thunks and scalar deleting destructor as generated/no-code.
8. Update support docs listed above with report-level detail, not compact summaries.
9. Run the scoped validators listed above from `source-3/project-documentation`.
10. Update `Agent-B008/notes.md` with changed files, before/after scores, validator commands/results, the pending coverage row, and any evidence that changed implementation decisions.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0000YH-AboveFrame-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"0000YH"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000YH-AboveFrame-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/0000YH-AboveFrame-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000YH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
