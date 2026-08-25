** TARGET-REPORT-UID:0000YH **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000YH AboveFrame Source-Quality Reanalysis

Agent: Agent-B003
Assignment date: 2026-06-19
Refresh date: 2026-06-20
Target: [UID:0000YH] `by-memory/0x004610f0-0x0046178a.AboveFrame.md`
Report path: `tools/leaser/Agents/Agent-B003/research/0000YH-AboveFrame-source-quality.md`

Report-only rule followed: no by-* documentation file was edited, and `by-memory/-coverage-report.md` was not edited.

## Current Recommendation

`0000YH` is a real FrameChrome-routed `AboveFrame` source island, but it is not one clean handwritten source function. The physical interval contains source-authored class methods, source-authored file-level helpers, internal `0xcc` padding, two compiler-generated secondary/tertiary destructor adjustor thunks, and one compiler-generated scalar deleting destructor wrapper.

Recommended target metadata after implementation:

- `COMPLETION:88`
- `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:0000JL`
- Keep `RECONSTRUCTABLE:TRUE` only if the page is retained as a FrameChrome source-bearing split/index over the island.
- Keep `EMITTER_UIDS:0000JL` for the source-authored bodies, with an explicit note that generated thunks/wrappers are not handwritten C++.
- Keep the current aggregate formal `RECONSTRUCTION_CPP` block blank, or use only project-supported child routing such as `[[CHILDREN]]`. Do not paste one monolithic aggregate C++ block that duplicates [UID:0000U2] and [UID:0000YI] or hand-authors compiler ABI glue.

First-draft C++ is eligible for the source-authored bodies now, but the best placement is split/child placement:

- `AboveFrame` constructor/destructor/paint/notify on exact method children or the `AboveFrame` class/source method section.
- `BuildAboveFrameBorder()` on [UID:0000U2].
- `ReleaseDynamicAboveFrame()` and `RecreateDynamicAboveFrame()` on [UID:0000YI].
- No authored C++ for [UID:0000YJ] adjustor thunks or `0x004616e0-0x0046178a` scalar deleting destructor.

## Evidence Checked

Workflow and source-placement rules:

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B003/goal.md`
- `by-structure.md`
- `tools/leaser/Agents/inference_research.md`
- `by-project-structure/proposed-source-tree.md`

Primary target and support docs:

- `by-memory/0x004610f0-0x0046178a.AboveFrame.md`
- `by-class/AboveFrame.md`
- `by-file/FrameChrome.md`
- `by-item/BuildAboveFrameBorder_00461310.md`
- `by-memory/0x004615b0-0x00461657.AboveFrameRefreshHelpers.md`
- `by-memory/0x004616c8-0x004616de.AboveFrameAdjustorThunks.md`
- `by-type/by-vtable/AboveFrameVtables.md`
- `by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md`
- `by-type/by-vtable/FrameChromeVtableFamily.md`
- `by-memory/0x00610f60-0x00610fe8.FrameChromeResourceStrings.md`
- `by-global/FrameChromeSlots.md`
- `by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md`
- `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md`
- `by-memory/0x0067a740-0x0067a744.g_pBackPane.md`
- `by-memory/0x0067a744-0x0067a748.g_pEPFLib.md`
- `by-memory/0x0067a874-0x0067a878.g_pGeneralPurposePanel.md`
- `by-memory/0x0069b364-0x0069b370.MainUiLayerSlotsHead.md`
- `by-memory/0x004f4b30-0x004f4b4c.ApplicationRegisterChangeListener.md`
- `by-memory/0x004f4b50-0x004f4b6c.ApplicationUnregisterChangeListener.md`
- `by-memory/0x004f4b30-0x004f4b6c.ApplicationChangeManRegisterWrappers.md`
- `by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md`
- `by-class/EPFTileContext.md`
- `by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md`
- `by-memory/0x00544460-0x00545086.PaneCore.md`
- `by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md`
- `by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md`
- `by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md`
- `by-memory/0x00504b70-0x00504b8f.MapPaneTagDetachMessage.md`
- Current `by-memory/-coverage-report.md` rows around `0000YH` were read for exact row format only. The coverage report was not edited.

Prior same-target B-agent reports were checked as repository evidence and compared against local PE facts:

- `tools/leaser/Agents/Agent-B006/research/0000YH-AboveFrame-source-quality.md`
- `tools/leaser/Agents/Agent-B007/research/0000YH-AboveFrame-source-quality.md`
- `tools/leaser/Agents/Agent-B008/research/0000YH-AboveFrame-source-quality.md`

Current generated/project-level state docs:

- `auto-generated/NexusTK/ui/core/FrameChrome.cpp`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-item-coverage.md`
- `auto-generated/-ag-class-coverage.md`
- `project-level/-auto-completion-stats.md`
- `project-level/-unresolved.md`

Local binary evidence:

- PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- File size: `2679296` bytes
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- Relevant PE sections: `.text` `0x00401000-0x0060c600`, `.rdata` `0x0060d000-0x0066c200`, `.data` `0x0066d000-0x0069ce24`
- Local Capstone disassembly over `0x004610f0-0x00461790`
- Local scan for direct `E8`/`E9` refs to the target functions
- Local scan for dword pointer refs in `.text`/`.rdata`/`.data` for the virtual methods, deleting-wrapper entries, strings, globals, and slot refs
- IDA MCP was attempted at `http://127.0.0.1:13337/mcp` and was unavailable in this session. This report therefore treats local PE evidence plus current checked-in by-* docs as the active evidence base and keeps confidence below final-audit range.

Generated source/provenance note: current `auto-generated` output and project-level reports were opened only to check current emitter/status/unresolved-name state. They were not used as source authority. No wave2/wave3 source files were used.

## Current Generated / Project-Level State

- `auto-generated/NexusTK/ui/core/FrameChrome.cpp` currently contains empty emitter markers for [UID:0000YH], [UID:0000U2], and [UID:0000YI]. This confirms the route to `FrameChrome.cpp` exists, but no first-draft source has been emitted for the target family yet.
- `auto-generated/-ag-memory-coverage.md` lists [UID:0000YH] as an emitting memory target routed to `FrameChrome.cpp` with no generated code. It still shows [UID:0000YI] under the stale `0x004615b0-0x00461657` path/end and [UID:0000YJ] as non-reconstructable.
- `auto-generated/-ag-item-coverage.md` lists [UID:0000U2] as an emitting item routed to `FrameChrome.cpp` with no generated code.
- `auto-generated/-ag-class-coverage.md` lists `AboveFrame` as an emitting class route to `FrameChrome.cpp` with no generated code.
- `project-level/-auto-completion-stats.md` was generated on 2026-06-19 and still places [UID:0000YH] in low-completion reconstructable work at current `84/90`, average `87.0`.
- `project-level/-unresolved.md` still surfaces raw aliases tied to this target family, including `byte_66DA97`, `dword_67A840`, `dword_67A874`, `sub_4610F0`, `sub_461310`, `sub_4615B0`, and `sub_4615D0`. The report recommendations below are intended to replace those raw names where this target/support family owns the wording.

## Exact Range, Boundary, And Padding Inventory

Local PE bytes confirm these half-open ranges:

| Range | Size | Disposition | Implementation action |
| --- | ---: | --- | --- |
| `0x004610ee-0x004610f0` | `0x02` | predecessor padding | Existing outer padding row remains valid. |
| `0x004610f0-0x00461299` | `0x1a9` | source-authored class method | `AboveFrame::AboveFrame(int frameIndex, int top, int left)`. |
| `0x00461299-0x004612a0` | `0x07` | padding | Seven `0xcc` bytes. Track if the aggregate is split. |
| `0x004612a0-0x00461309` | `0x69` | source-authored class method | Ordinary `AboveFrame::~AboveFrame()`. |
| `0x00461309-0x00461310` | `0x07` | padding | Seven `0xcc` bytes. Track if split. |
| `0x00461310-0x004615aa` | `0x29a` | source-authored file helper | `BuildAboveFrameBorder()`, already [UID:0000U2]. |
| `0x004615aa-0x004615b0` | `0x06` | padding | Six `0xcc` bytes. Track if split. |
| `0x004615b0-0x004615c1` | `0x11` | source-authored file helper | `ReleaseDynamicAboveFrame()` / `ReleaseDynamicAboveFrameSlot()`. |
| `0x004615c1-0x004615d0` | `0x0f` | padding | Fifteen `0xcc` bytes. Current helper page path hides this exact split. |
| `0x004615d0-0x00461658` | `0x88` | source-authored file helper | `RecreateDynamicAboveFrame()` / `RecreateDynamicAboveFrameSlot()`. |
| `0x00461658-0x00461660` | `0x08` | padding | Eight `0xcc` bytes. |
| `0x00461660-0x004616af` | `0x4f` | source-authored virtual method | `AboveFrame::OnPaint()`; old descriptive alias `DrawFrame`. |
| `0x004616af-0x004616b0` | `0x01` | padding | One `0xcc` byte. |
| `0x004616b0-0x004616c8` | `0x18` | source-authored virtual method | `AboveFrame::OnNotify(void *sender, const TaggedPaneMessage *message)`. |
| `0x004616c8-0x004616d3` | `0x0b` | compiler adjustor thunk | `sub ecx, 0xa0; jmp 0x004616e0`; no handwritten source. |
| `0x004616d3-0x004616de` | `0x0b` | compiler adjustor thunk | `sub ecx, 0xa4; jmp 0x004616e0`; no handwritten source. |
| `0x004616de-0x004616e0` | `0x02` | padding | Two `0xcc` bytes. |
| `0x004616e0-0x0046178a` | `0xaa` | compiler scalar deleting destructor wrapper | Generated from virtual destructor/delete semantics; no handwritten source body. |
| `0x0046178a-0x00461790` | `0x06` | successor padding | Existing outer padding row remains valid. |

The current support page `by-memory/0x004615b0-0x00461657.AboveFrameRefreshHelpers.md` should be repaired to the half-open end `0x00461658` if the supervisor authorizes a filename/range correction. The existing body already acknowledges the recreate helper's final byte at `0x00461657` and exclusive end at `0x00461658`.

## Caller, Callee, And Reachability Evidence

Direct local PE rel32 references:

| Target | Direct refs |
| --- | --- |
| `0x004610f0` constructor | Calls at `0x00461368`, `0x004613a0`, `0x004613db`, `0x00461423`, `0x00461476`, `0x004614ae`, `0x004614e9`, `0x00461535`, `0x00461570`, and `0x00461626`. Nine are from `BuildAboveFrameBorder`; one is from `RecreateDynamicAboveFrame`. |
| `0x004612a0` ordinary destructor | No direct rel32 call found in the local scan. Source destructor is reached through compiler lifecycle paths, while the primary vtable points to the scalar deleting destructor wrapper. |
| `0x00461310` factory | Calls at `0x004f802c` and `0x004f8670`, both in the main UI graph/startup route. |
| `0x004615b0` release helper | Calls at `0x004b872e` and `0x004b8a62`, from `GeneralPurposePanel` / `GeneralPurposePanel2` active-child switch helpers. |
| `0x004615d0` recreate helper | Calls at `0x004b8733` and `0x004b8a67`, immediately after release in the same panel switch helpers. |
| `0x00461660` paint | No direct rel32 calls; `.rdata` vtable pointer at `0x00610f20`. |
| `0x004616b0` notify | No direct rel32 calls; `.rdata` vtable pointer at `0x00610ee4`. |
| `0x004616c8` adjustor | `.rdata` vtable pointer at `0x00610f28`. |
| `0x004616d3` adjustor | `.rdata` vtable pointer at `0x00610f58`. |
| `0x004616e0` scalar deleting destructor | `.rdata` vtable pointer at `0x00610edc`; jumps from `0x004616ce` and `0x004616d9`. |

Important callees/dependencies:

- Constructor calls `Pane::Pane` at `0x00544460`, `EPFTileContext::InitTileContext` at `0x00457a60`, `ResourceLayoutTable::LookupLayoutEntry` at `0x004d02f0`, bounds/rect offset helper `0x004b78f0`, `Pane::SetBounds` at `0x00544bd0`, `Pane::AddToLayer` at `0x00544c70`, and `Application::RegisterChangeListener` at `0x004f4b30`.
- Ordinary destructor calls `Application::UnregisterChangeListener` at `0x004f4b50` and `Pane::~Pane` at `0x00544580`.
- Paint calls shared `RenderTileFrame` at `0x004b9980`. This is a Surface/GrafPort render dependency, not source ownership.
- Notify calls `Pane::MarkForDeletion` at `0x00544690` only when the message tag matches `0x676f6f67`.
- The scalar deleting destructor repeats destructor cleanup and conditionally calls delete helpers with object size `0x134`. This is compiler-generated delete support, not a second source destructor.

## Vtable Slice Reanalysis

The exact `AboveFrame` vtable-data child is `0x00610ed8-0x00610f60`.

| Slice | Address | Meaning |
| --- | --- | --- |
| Primary RTTI | `0x00610ed8` | `AboveFrame` RTTI / complete-object locator. |
| Primary base | `0x00610edc` | Slot `+0x00 -> 0x004616e0` scalar deleting destructor wrapper. |
| Primary slot | `0x00610ee4` | Slot `+0x08 -> 0x004616b0` notification/change-message callback. |
| Primary slot | `0x00610f20` | Slot `+0x44 -> 0x00461660` paint/draw callback. |
| Secondary RTTI | `0x00610f24` | Secondary view locator. |
| Secondary base | `0x00610f28` | Slot `+0x00 -> 0x004616c8`, adjustor thunk subtracting `0xa0`. |
| Tertiary RTTI | `0x00610f54` | Tertiary view locator. |
| Tertiary base | `0x00610f58` | Slot `+0x00 -> 0x004616d3`, adjustor thunk subtracting `0xa4`. |
| Tertiary inherited/default slot | `0x00610f5c` | `0x00544e90`, shared default inherited slot. |
| Successor | `0x00610f60` | UTF-16 `FRMPART.EPF`, not a vtable slot. |

Constructor, ordinary destructor, and scalar deleting destructor all store the primary, secondary, and tertiary vtable bases at object offsets `+0x00`, `+0xa0`, and `+0xa4`. These stores are compiler lifecycle output. The source declaration should express the inherited/interface shape and the virtual destructor/notification/paint methods; it should not hand-port vtable writes.

## Constructor And Field Reanalysis

Best source signature:

```cpp
AboveFrame::AboveFrame(int frameIndex, int top, int left);
```

The order is `frameIndex, top, left`, not `frameIndex, left, top`. The call sites push arguments right-to-left; the constructor reads:

- `frameIndex = [ebp+0x08]`
- `top = [ebp+0x0c]`
- `left = [ebp+0x10]`

In the EPF/current branch, `left` is stored at `this+0x120`, `top` at `this+0x124`, `right` is computed as `left + (bounds.right - bounds.left)`, and `bottom` is computed as `top + (bounds.bottom - bounds.top)`. Documentation that names the second and third arguments as generic `x,y` should be corrected or replaced with `top,left` / `y,x` wording.

Best source-facing fields:

| Offset | Best name | Evidence and notes |
| --- | --- | --- |
| `+0x00` | primary `Pane` / `AboveFrame` view | Primary vptr store to `0x00610edc`. |
| `+0xa0` | secondary handler view | Secondary vptr store to `0x00610f28`; adjustor subtracts `0xa0`. |
| `+0xa4` | tertiary handler view | Tertiary vptr store to `0x00610f58`; adjustor subtracts `0xa4`. |
| `+0x0f8` | `EPFTileContext m_tileContext` | Constructor calls `0x00457a60` with `ecx = this+0xf8`; paint passes `this+0xf8` to `RenderTileFrame`. |
| `+0x108` | `m_tileContext.bounds` | This is `EPFTileContext +0x10`, not a separate class field. Paint passes `this+0x108` twice to `RenderTileFrame`. |
| `+0x120` | `RectBounds m_positionedBounds` / `m_paneBounds` | EPF/current branch stores positioned pane bounds here and passes the rectangle to `Pane::SetBounds` / `Pane::AddToLayer`. |
| `+0x130` | `uint8_t m_framePaletteMode` / `m_resourceKind` | EPF branch writes `0` for frame-parts palette and `1` for tabs palette. Legacy paint ignores this byte because it branches on `g_useEpfAssets` first. |

Resource load behavior:

- If `g_useEpfAssets == 1` and `frameIndex < 4`, the constructor calls `ResourceLayoutTable::LookupLayoutEntry(g_pEPFLib, L"FRMPART.EPF", frameIndex, &m_tileContext)` and writes `m_framePaletteMode = 0`.
- If `g_useEpfAssets == 1` and `frameIndex >= 4`, it writes `m_framePaletteMode = 1`, computes `tabIndex = frameIndex + (((frameIndex - 4) < 2) ? 1 : 0) - 5`, and calls `LookupLayoutEntry(g_pEPFLib, L"TABS.EPF", tabIndex, &m_tileContext)`.
- If `g_useEpfAssets != 1`, it calls `LookupLayoutEntry(g_pEPFLib, L"FRMPART.EPD", frameIndex, &m_tileContext)`.
- The object size allocated by all observed callers is `0x134`.

The exact source type of `g_pEPFLib` remains the known ImageLib/ResourceLayoutTable boundary issue, but this target should call the shared lookup API by behavior. Do not reroute constructor ownership to `ResourceLayoutTable` or `ImageLib`; they are dependencies.

## Destructor And Generated Destructor Separation

`0x004612a0-0x00461309` is the source-authored ordinary destructor:

- Restores the three `AboveFrame` vtable views as compiler lifecycle output.
- Calls `Application::UnregisterChangeListener` with `ecx = g_pBackPane`, `listener = this`, message type/tag `0x676f6f67`, and scope byte `0`.
- Calls `Pane::~Pane`.

Source-level intent:

```cpp
AboveFrame::~AboveFrame()
{
    g_pBackPane->UnregisterChangeListener(this, kPaneTagGoog, 0);
}
```

The vtable stores and base destructor call are compiler output and should not be over-modeled in handwritten C++.

`0x004616e0-0x0046178a` is a compiler scalar deleting destructor wrapper:

- It performs the same unregister/base-teardown sequence.
- It checks the delete flag at `[ebp+8]`.
- Flag bit `1` enables deallocation.
- Flag bit `4` routes to the vector/guard delete helper with size `0x134`.
- Otherwise it calls scalar delete helper `0x004f4ac0`.

This wrapper is generated from the virtual destructor and delete expression semantics. It should be documented for binary coverage and vtable interpretation but must not be emitted as a separate source method.

`0x004616c8` and `0x004616d3` are generated adjustor thunks only:

```asm
0x004616c8: sub ecx, 0xa0
0x004616ce: jmp 0x004616e0

0x004616d3: sub ecx, 0xa4
0x004616d9: jmp 0x004616e0
```

Keep [UID:0000YJ] `RECONSTRUCTABLE:FALSE`, owner `NONE`, no emitter, no C++.

## Paint / Draw Reanalysis

Best source-facing name: `AboveFrame::OnPaint()`.

`DrawFrame` remains a useful descriptive alias because the current docs use it, but `OnPaint` is better source-facing vocabulary:

- The body is reached through a Pane-derived vtable slot.
- It has no setup/factory behavior.
- It selects a palette and calls the shared render helper.
- Comparable Pane-derived docs use paint/draw callback language.

Behavior:

- If `g_useEpfAssets == 1`:
  - `m_framePaletteMode == 0` selects UTF-16 `FRMPART.PAL` at `0x00610fa4`.
  - `m_framePaletteMode != 0` selects UTF-16 `TABS.PAL` at `0x00610fbc`.
- If `g_useEpfAssets != 1`, the body selects UTF-16 `NPAL5.PAL` at `0x00610fd0`.
- Both paths call `RenderTileFrame(0x004b9980)` with:
  - `this+0x0f8` as the tile context;
  - `this+0x108` as both rectangle arguments;
  - mode/flag `1`;
  - selected palette string;
  - trailing `0`.

Reject generated owner pollution such as `FittingRoomDownloadControlPane` for `0x004b9980`. The helper is a shared Surface/GrafPort render dependency.

## Notify / `goog` Reanalysis

Best source-facing name:

```cpp
void AboveFrame::OnNotify(void *sender, const TaggedPaneMessage *message);
```

`OnChangeMessage` is an acceptable project-wide spelling if the ChangeMan callback vocabulary standardizes there, but the current target and support docs already use `OnNotify` / notification language. The important source facts are:

- The method has two explicit stack arguments and returns with `ret 8`.
- The first explicit argument is unused.
- The second explicit argument is dereferenced at `message + 4`.
- If `*(uint32_t *)(message + 4) == 0x676f6f67`, it calls `Pane::MarkForDeletion()` at `0x00544690`.
- If the tag does not match, it returns without side effects.

Use an integer constant for the tag:

```cpp
static const unsigned int kPaneTagGoog = 0x676f6f67;
```

Do not write a multi-character literal as source truth. Existing `MapPaneTagDetachMessage` uses the same message layout and tag value, and the integer constant avoids compiler-dependent spelling while still documenting ASCII/FOURCC `goog`.

Constructor/destructor listener routing:

- Constructor pushes `scope = 0`, `messageType = 0x676f6f67`, `listener = this`, with `ecx = g_pBackPane`, then calls `Application::RegisterChangeListener`.
- Ordinary destructor and scalar deleting destructor push the same scope/tag/listener into `Application::UnregisterChangeListener`.
- The support `ChangeMan` docs define scope `0` as match-type behavior and scope `1` as all-types behavior. This target uses the match-type route.

## Factory And Refresh Helper Relationship

`BuildAboveFrameBorder()` is a file-level FrameChrome factory, not an `AboveFrame` member. It builds global slots and initial dynamic frame state. The current saved name is good and should be retained.

Current/EPF branch (`g_useEpfAssets == 1`):

| Store | Constructor arguments | Meaning |
| --- | --- | --- |
| `0x0067a834` at `0x0046137d` | `(0, 0, 0)` | Fixed AboveFrame slot. |
| `0x0067a83c` at `0x004613b5` | `(1, 9, 0)` | Fixed EPF AboveFrame slot. |
| `0x0067a838` at `0x004613f0` | `(2, 9, 0x328)` | Fixed EPF AboveFrame slot. |
| `0x0067a840` at `0x00461428` | `(g_pGeneralPurposePanel->m_activeChildIndex + 5, 0x4f, 0x328)` | Dynamic/current tab/right-edge frame slot. |
| `0x0067a840` at `0x00461441` | `0` | Allocation-failure clear for the dynamic slot. |

Legacy branch (`g_useEpfAssets != 1`):

| Store | Constructor arguments |
| --- | --- |
| `0x0067a848` at `0x0046148b` | `(0, 0x0c, 0x0e)` |
| `0x0067a834` at `0x004614c3` | `(1, 0x0c, 0x7d)` |
| `0x0067a838` at `0x004614fe` | `(2, 0x0c, 0x17a)` |
| `0x0067a84c + i*4` at `0x0046154a` | `(3, y + 6, 0x0e)` |
| `0x0067a860 + i*4` at `0x00461579` | `(4, y, 0x1a4)` |

The legacy loop uses `y = 0x5c, 0x9b, 0xda, 0x119, 0x158`, increments by `0x3f`, and exits when the post-increment value reaches `0x197`.

Refresh helper pair:

- `0x004615b0-0x004615c1`: `ReleaseDynamicAboveFrame()` reads `0x0067a840`, and if non-null calls the object's primary vtable slot with delete flag `1`. It does not clear the global in this body.
- `0x004615d0-0x00461658`: `RecreateDynamicAboveFrame()` allocates `0x134`, constructs `AboveFrame(g_pGeneralPurposePanel->m_activeChildIndex + 5, 0x4f, 0x328)`, stores the result to `0x0067a840`, and stores zero on allocation failure.
- The pair is called after active child/tab switches in `GeneralPurposePanel::SwitchActiveTab` and `GeneralPurposePanel2::SwitchActiveChild`.
- Caller location does not imply ownership. The helpers manipulate FrameChrome global slots and construct `AboveFrame`, so their owner/emitter remains `FrameChrome`.

Recommended source-facing helper names:

- `BuildAboveFrameBorder()` for `0x00461310-0x004615aa`.
- `ReleaseDynamicAboveFrame()` for `0x004615b0-0x004615c1`.
- `RecreateDynamicAboveFrame()` for `0x004615d0-0x00461658`.

`Slot` suffixes are acceptable in documentation (`ReleaseDynamicAboveFrameSlot`, `RecreateDynamicAboveFrameSlot`) when the discussion emphasizes `0x0067a840`, but the cleaner source name is probably without `Slot`.

Reject the stale IDA/generated label `__std_parallel_algorithms_hw_threads` for `0x004615d0`; the body has no STL/thread semantics.

## Global Slot Ownership And Names

The direct storage family `0x0067a834-0x0067a874` belongs to `FrameChromeSlots` / `AboveFrameSlots`, rooted in FrameChrome source. It must not be extended to `0x0067a874`, which is the separate `g_pGeneralPurposePanel` singleton.

Recommended source-facing global names:

| Address/range | Recommended name | Confidence | Notes |
| --- | --- | --- | --- |
| `0x0067a834` | `g_pAboveFramePrimary` or address-table entry in `g_aboveFrameSlots` | Medium | Written in both current and legacy branches; exact original scalar name is not recoverable from current evidence. |
| `0x0067a838` | `g_pAboveFrameBottom` / fixed frame slot | Medium | Written in both current and legacy branches. Use descriptive slot-table wording if final scalar name is not known. |
| `0x0067a83c` | `g_pAboveFrameTabs` / EPF-only fixed frame slot | Medium | Only written in EPF branch. |
| `0x0067a840` | `g_pDynamicAboveFrame` | High | Written by factory/recreate; released by `ReleaseDynamicAboveFrame`; tracks active panel child index. |
| `0x0067a844` | spacer / unused slot gap | High for non-use | No direct xrefs; keep as internal storage gap/filler, not a source variable. |
| `0x0067a848` | legacy fixed `AboveFrame*` slot | Medium | Legacy-only scalar slot. |
| `0x0067a84c-0x0067a860` | `g_legacyAboveFrameSideTop[5]` / descriptive array | Medium | Five-entry legacy array for frame index `3`; exact name not proven. |
| `0x0067a860-0x0067a874` | `g_legacyAboveFrameSideBottom[5]` / descriptive array | Medium | Five-entry legacy array for frame index `4`; exact name not proven. |
| `0x0067a874` | `g_pGeneralPurposePanel` | High | Separate singleton, not part of `AboveFrameSlots`. |

Recommended field at `g_pGeneralPurposePanel + 0x20`: `m_activeChildIndex`.

Evidence: `GeneralPurposePanel` constructor initializes child pointers at `+0x04..+0x1c` and active index at the next dword; `SwitchActiveTab` docs say the active index is stored at `this[8]`; this target reads `+0x20` after panel switches and maps it to dynamic frame index `+5`. `m_activeTabIndex` is an acceptable UI-facing alias, but `m_activeChildIndex` is the best-supported source field name across current GeneralPurposePanel docs.

## Resource And Palette Literal Placement

The string run `0x00610f60-0x00610fe8` is FrameChrome resource string data, not vtable data and not a separate AboveFrame-only source file.

| Address | Literal | Used by |
| --- | --- | --- |
| `0x00610f60` | `FRMPART.EPF` | Constructor current/EPF frame-part branch. |
| `0x00610f78` | `TABS.EPF` | Constructor current/EPF tab branch. |
| `0x00610f8c` | `FRMPART.EPD` | Constructor legacy branch. |
| `0x00610fa4` | `FRMPART.PAL` | Paint current/EPF frame-part palette. |
| `0x00610fbc` | `TABS.PAL` | Paint current/EPF tab palette. |
| `0x00610fd0` | `NPAL5.PAL` | Paint legacy palette. |

Recommended constant names:

- `kFramePartEpf`
- `kTabsEpf`
- `kFramePartEpd`
- `kFramePartPalette`
- `kTabsPalette`
- `kLegacyFramePalette`

These names are source-quality descriptive names, not proven original spellings.

## Owner / Source Placement

Best source route: [UID:0000JL] `FrameChrome`, likely `NexusTK/ui/core/FrameChrome.cpp`.

Direct semantic owners:

- `AboveFrame` class owns the constructor, ordinary destructor, paint callback, notify callback, and vtable semantics.
- `FrameChrome` file owns `BuildAboveFrameBorder`, dynamic release/recreate helpers, resource literal placement, and frame-chrome global slot construction policy.
- `FrameChromeSlots` / `AboveFrameSlots` owns exact storage documentation for `0x0067a834-0x0067a874`, with FrameChrome as source-file root.
- `GeneralPurposePanel` owns `g_pGeneralPurposePanel` and `m_activeChildIndex`; FrameChrome only reads that field to select the dynamic tab frame.

Rejected owner/source alternatives:

- `GeneralPurposePanel`: rejected as owner for the refresh helpers. It calls them after switching panels, but the helpers allocate/delete FrameChrome `AboveFrame` state.
- `ResourceLayoutTable` / `ImageLib`: rejected as owner for the constructor. They provide the resource lookup dependency.
- `Surface` / `GrafPort`: rejected as owner for the paint callback. `RenderTileFrame` is a shared rendering dependency.
- `Pane`: rejected as owner for the class methods. `AboveFrame` derives from Pane and uses Pane lifecycle infrastructure, but the resource/palette/slot behavior is derived UI chrome logic.
- `ChangeMan` / `Application`: rejected as owner for the notification method. They provide registration and dispatch infrastructure.
- `FrameMgr` or frame scheduler sources: rejected. This island draws visible UI chrome, not frame scheduling.
- Generated/caller-biased labels such as `FittingRoomDownloadControlPane`, `BulletinSession`, and `__std_parallel_algorithms_hw_threads`: rejected by local instruction behavior and support docs.

Exact original file split remains not literally proven by symbols, but B-agent source placement should not defer generically. Use `FrameChrome.cpp` as the implementation route unless later source evidence proves a narrower `AboveFrame.cpp` under the same UI chrome module. A separate `AboveFrame.cpp` is possible but weaker because the class methods, factory, refresh helpers, slots, vtables, FramePartPane family, and resource strings all cluster in the current FrameChrome documentation route.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best-supported inference | Rejected alternatives / cap |
| --- | --- | --- | --- |
| Class name `AboveFrame` | Decorated vtable pages, target docs, class page, vtable stores, local `.rdata` pointer refs. | Class identity is strong; update any "medium class name" wording. | Do not keep anonymous `sub_4610f0` or caller-biased owners. |
| Source module | `FrameChrome.md`, slots, vtables, resource strings, helper callers, prior B reports, local PE. | Use FrameChrome as source route and emitter. | A separate `AboveFrame.cpp` is possible but weaker and should not block implementation. |
| Constructor argument order | Local constructor disassembly and all factory/recreate push sites. | `frameIndex, top, left`; use coordinate-order caveat anywhere old docs say `x,y`. | Reject `frameIndex, left, top`; it contradicts field stores and screen constants. |
| `this+0xf8` | Constructor passes it to `EPFTileContext` init; paint passes it to render helper; EPFTileContext layout docs. | `EPFTileContext m_tileContext`. | Not an opaque byte array. |
| `this+0x108` | `EPFTileContext +0x10` bounds and paint rectangle args. | `m_tileContext.bounds`. | Do not model as a separate independent field. |
| `this+0x120` | Constructor writes left/top/right/bottom and passes to Pane bounds/layer setup. | `RectBounds m_positionedBounds` / `m_paneBounds`. | Not the tile-context bounds; it is the positioned pane rectangle. |
| `this+0x130` | EPF branch writes 0 or 1; paint reads only in EPF mode to select palette. | `uint8_t m_framePaletteMode` / `m_resourceKind`; 0 frame part, 1 tabs. | Not a persistent legacy-mode flag; legacy paint ignores it. |
| Paint method name | Vtable-only slot, palette selection body, Pane paint conventions, Surface helper dependency. | `AboveFrame::OnPaint()`, with `DrawFrame` as descriptive alias. | Do not route to Surface/GrafPort owner. |
| Notify method name/signature | `ret 8`, unused first explicit arg, second explicit arg read at `+4`, matching MapPane tag callback pattern. | `AboveFrame::OnNotify(void *sender, const TaggedPaneMessage *message)`. | Reject one-arg signature and raw `virt_meth_0x4616b0`; exact `OnChangeMessage` spelling can be harmonized later. |
| `goog` constant | Constructor/destructor register/unregister tag; notify compares `message+4`; MapPane tag callback uses same constant. | `kPaneTagGoog = 0x676f6f67`. | Avoid multi-character literal as source truth. |
| `0x004615d0` helper name | Body allocates `0x134`, reads `g_pGeneralPurposePanel+0x20`, calls constructor, stores `0x0067a840`. | `RecreateDynamicAboveFrame()` / `RecreateDynamicAboveFrameSlot()`. | Reject `__std_parallel_algorithms_hw_threads`. |
| `g_pGeneralPurposePanel+0x20` | GeneralPurposePanel constructor/switch docs and local reads at `0x0046141a`/`0x0046161d`. | `m_activeChildIndex` is the best field name; `m_activeTabIndex` acceptable alias. | Exact original spelling not proven, but behavior is settled enough for source docs. |
| `0x0067a840` global | Factory/recreate writes, release read/delete, allocation-failure clears. | `g_pDynamicAboveFrame`. | Do not treat it as GeneralPurposePanel state. |
| Vtable data boundary | Exact vtable child docs and local pointer scan. | Vtable child ends at `0x00610f60`; strings begin there. | Reject `0x00520046` as a vtable method; it is UTF-16 string bytes. |
| Adjustor thunks | Local bytes show subtract-and-jump only; vtable-only refs. | Compiler-generated no-code. | Do not emit as C++ helpers. |
| Scalar deleting destructor | Ordinary destructor exists separately; wrapper repeats cleanup and tests delete flags. | Compiler-generated no-code; source is virtual destructor only. | Do not add `AboveFrame::ScalarDeletingDestructor` as authored C++. |
| Aggregate C++ placement | Current target spans child helper docs, padding, compiler glue, and source methods. | Source bodies are C++-eligible, but the current aggregate formal block should stay blank/child-routed. | Reject monolithic aggregate emission unless supervisor explicitly defines aggregate child routing and avoids duplicate helper emission. |
| Score | Behavior, ranges, callers, fields, resources, vtables, and generated-code boundary are now settled. | Recommend `88/91`. | Do not raise into final-audit range because exact original file split, exact slot scalar names, and some API spelling remain inferred. |

No open question is left as generic future work. Residual caps are explicitly limited to original spelling or source-file naming where binary behavior is already resolved.

## First-Draft C++ Placement Recommendation

Do not paste the following as the current aggregate's formal C++ block. It is a source-facing reference draft for exact method/helper children or class/file support pages after the supervisor accepts split/child placement.

```cpp
struct TaggedPaneMessage
{
    unsigned int reserved;
    unsigned int tag;
};

static const unsigned int kPaneTagGoog = 0x676f6f67;

enum AboveFramePaletteMode
{
    kAboveFramePaletteFramePart = 0,
    kAboveFramePaletteTabs = 1
};

AboveFrame::AboveFrame(int frameIndex, int top, int left)
    : Pane(1),
      m_tileContext(),
      m_framePaletteMode(kAboveFramePaletteFramePart)
{
    if (g_useEpfAssets)
    {
        if (frameIndex < 4)
        {
            g_pEPFLib->LookupLayoutEntry(L"FRMPART.EPF", frameIndex, &m_tileContext);
            m_framePaletteMode = kAboveFramePaletteFramePart;
        }
        else
        {
            int tabIndex = frameIndex + (((frameIndex - 4) < 2) ? 1 : 0) - 5;
            g_pEPFLib->LookupLayoutEntry(L"TABS.EPF", tabIndex, &m_tileContext);
            m_framePaletteMode = kAboveFramePaletteTabs;
        }
    }
    else
    {
        g_pEPFLib->LookupLayoutEntry(L"FRMPART.EPD", frameIndex, &m_tileContext);
    }

    m_positionedBounds.left = left;
    m_positionedBounds.top = top;
    m_positionedBounds.right = left + (m_tileContext.bounds.right - m_tileContext.bounds.left);
    m_positionedBounds.bottom = top + (m_tileContext.bounds.bottom - m_tileContext.bounds.top);

    RectBounds tileBounds = m_tileContext.bounds;
    tileBounds.Offset(left, top);

    SetBounds(m_positionedBounds, 0);
    AddToLayer(m_positionedBounds, 0, 0, g_mainUiLayerSlots[0]);
    g_pBackPane->RegisterChangeListener(this, kPaneTagGoog, 0);
}

AboveFrame::~AboveFrame()
{
    g_pBackPane->UnregisterChangeListener(this, kPaneTagGoog, 0);
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

void AboveFrame::OnNotify(void *sender, const TaggedPaneMessage *message)
{
    (void)sender;

    if (message != 0 && message->tag == kPaneTagGoog)
        MarkForDeletion();
}
```

Draft caveats:

- `LookupLayoutEntry`, `RectBounds::Offset`, `SetBounds`, `AddToLayer`, `RegisterChangeListener`, `UnregisterChangeListener`, `RenderTileFrame`, and `MarkForDeletion` are source-facing names from support docs. Adjust spelling to final project APIs while preserving argument behavior.
- `g_mainUiLayerSlots[0]` is the source-facing stand-in for the documented `0x0069b364` main UI layer/context slot.
- `g_pEPFLib` should keep its current global name while the exact ImageLib/ResourceLayoutTable type boundary remains documented elsewhere.
- Do not include explicit vtable stores, SEH scaffolding, base destructor calls, scalar deleting destructor wrappers, vector delete branches, or adjustor thunks in source C++.

Helper draft for [UID:0000U2] / [UID:0000YI]:

```cpp
void BuildAboveFrameBorder()
{
    if (g_useEpfAssets)
    {
        g_pAboveFramePrimary = new AboveFrame(0, 0, 0);
        g_pAboveFrameTabs = new AboveFrame(1, 9, 0);
        g_pAboveFrameBottom = new AboveFrame(2, 9, 0x328);
        g_pDynamicAboveFrame = new AboveFrame(g_pGeneralPurposePanel->m_activeChildIndex + 5,
                                              0x4f,
                                              0x328);
        return;
    }

    g_pLegacyAboveFrameFixed = new AboveFrame(0, 0x0c, 0x0e);
    g_pAboveFramePrimary = new AboveFrame(1, 0x0c, 0x7d);
    g_pAboveFrameBottom = new AboveFrame(2, 0x0c, 0x17a);

    int y = 0x5c;
    for (int i = 0; i < 5; ++i, y += 0x3f)
    {
        g_legacyAboveFrameSideTop[i] = new AboveFrame(3, y + 6, 0x0e);
        g_legacyAboveFrameSideBottom[i] = new AboveFrame(4, y, 0x1a4);
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

Helper caveats:

- Per-slot global names besides `g_pDynamicAboveFrame` are descriptive and should remain provisional unless a later declaration pass proves original scalar names.
- If project reconstruction style models non-throwing allocation/null paths explicitly, keep the proven allocation-failure store to `g_pDynamicAboveFrame = 0`.
- `ReleaseDynamicAboveFrame()` does not clear `g_pDynamicAboveFrame`; do not silently add a null store.

## Target Implementation Checklist

For `by-memory/0x004610f0-0x0046178a.AboveFrame.md`:

1. Update metadata to `COMPLETION:88`, `CONFIDENCE:91`; keep owner/emitter `0000JL`.
2. Change status from a simple class cluster to a FrameChrome `AboveFrame` class/helper split-index/source island.
3. Keep formal aggregate C++ blank or child-routed; document why monolithic aggregate C++ is rejected.
4. Add the exact range/padding table from this report.
5. Update method/function table with:
   - `AboveFrame::AboveFrame(int frameIndex, int top, int left)`
   - `AboveFrame::~AboveFrame()`
   - `BuildAboveFrameBorder()`
   - `ReleaseDynamicAboveFrame()`
   - `RecreateDynamicAboveFrame()`
   - `AboveFrame::OnPaint()` / alias `DrawFrame`
   - `AboveFrame::OnNotify(void *sender, const TaggedPaneMessage *message)`
   - generated adjustor thunks and scalar deleting destructor as no-code
6. Add exact caller/vtable reachability:
   - ten constructor call sites
   - factory callers `0x004f802c` and `0x004f8670`
   - refresh callers `0x004b872e`, `0x004b8733`, `0x004b8a62`, `0x004b8a67`
   - vtable data refs `0x00610edc`, `0x00610ee4`, `0x00610f20`, `0x00610f28`, `0x00610f58`
7. Add field table for `+0xf8`, `+0x108`, `+0x120`, and `+0x130`.
8. Add resource/palette selection details and `tabIndex` expression.
9. Add `goog` registration/unregistration and message+4 handling details.
10. Add generated-name/owner rejection notes.
11. Add score rationale and change log entry for this B003 source-quality pass.

## Support Doc Implementation Checklist

Update these support docs at report-level detail if this report is accepted:

- `by-class/AboveFrame.md`: strengthen class-name proof; add fields/method declarations; correct constructor argument order; document generated destructor/adjustor separation.
- `by-file/FrameChrome.md`: state `0000YH` is a FrameChrome source island with class methods plus file helpers; keep `FrameChrome.cpp` as best route; reject GeneralPurposePanel/Surface/ResourceLayoutTable ownership.
- `by-item/BuildAboveFrameBorder_00461310.md`: correct tuple order to `(frameIndex, top, left)`; add current and legacy branch argument inventory; document dynamic index source as `g_pGeneralPurposePanel->m_activeChildIndex + 5`.
- `by-memory/0x004615b0-0x00461657.AboveFrameRefreshHelpers.md`: repair range/path to `0x00461658` if authorized; document subranges, padding, release no-clear behavior, recreate zero-on-allocation-failure, and reject the false STL label.
- `by-memory/0x004616c8-0x004616de.AboveFrameAdjustorThunks.md`: keep no-code; add exact subtract/jump bytes and scalar-wrapper target.
- `by-type/by-vtable/AboveFrameVtables.md`: update slot `+0x44` to `OnPaint` if accepted; keep scalar deleting destructor and adjustor thunks generated.
- `by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md`: keep the `0x00610f60` string boundary; update paint/notify naming.
- `by-type/by-vtable/FrameChromeVtableFamily.md`: keep non-emitting family index and point to `AboveFrameVtables` for exact class-owned data.
- `by-memory/0x00610f60-0x00610fe8.FrameChromeResourceStrings.md`: add constructor and paint cross-notes for all six literals.
- `by-global/FrameChromeSlots.md` and `by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md`: add `g_pDynamicAboveFrame`, current/legacy constructor argument evidence, `0x0067a844` spacer, and the `0x0067a874` exclusion.
- `by-memory/0x0067a874-0x0067a878.g_pGeneralPurposePanel.md`, `by-class/GeneralPurposePanel.md`, and `by-file/GeneralPurposePanel.md`: cross-note that FrameChrome reads `+0x20` as `m_activeChildIndex` for the dynamic `AboveFrame` frame index.
- `by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md`, `by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md`, and `by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md`: note the FrameChrome helper dependency without transferring ownership.
- `by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md`: add cross-note that `AboveFrame::OnPaint()` calls `RenderTileFrame`.
- `by-memory/0x00544460-0x00545086.PaneCore.md` and `by-class/Pane.md`: optional cross-note that `AboveFrame::OnNotify()` reaches `Pane::MarkForDeletion`.
- `by-memory/0x004f4b30-0x004f4b4c.ApplicationRegisterChangeListener.md`, `by-memory/0x004f4b50-0x004f4b6c.ApplicationUnregisterChangeListener.md`, and ChangeMan support docs: optional cross-note that `AboveFrame` registers/unregisters with `messageType = 0x676f6f67`, scope `0`.
- `by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md`, `by-class/EPFTileContext.md`, `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md`, `by-memory/0x0067a744-0x0067a748.g_pEPFLib.md`, `by-memory/0x0067a740-0x0067a744.g_pBackPane.md`, and `by-memory/0x0069b364-0x0069b370.MainUiLayerSlotsHead.md`: add focused cross-notes only if target/support wording references those dependencies.

Do not edit `by-memory/-coverage-report.md` from the implementation callback unless the supervisor explicitly owns that change. Leave the row text below for supervisor insertion.

## Exact Supervisor-Owned Coverage Row Text

Replace the current `0000YH` row with:

```markdown
    - [UID:0000YH][0x004610f0-0x0046178a.AboveFrame](by-memory/0x004610f0-0x0046178a.AboveFrame.md) 0x004610f0-0x0046178a | class/helper split-index | AboveFrame : reconstructable : 88% : very strong : B003 2026-06-20 source-quality refresh resolves the FrameChrome-routed `AboveFrame` island as source-authored constructor/destructor/OnPaint/OnNotify class methods plus file-level `BuildAboveFrameBorder` and dynamic release/recreate helpers, exact internal padding and helper boundaries including refresh end `0x00461658`, `frameIndex/top/left` constructor argument order, `EPFTileContext` bounds and positioned-bounds fields at `+0xf8/+0x108/+0x120` plus frame palette mode `+0x130`, `FRMPART.EPF`/`TABS.EPF`/`FRMPART.EPD` resource selection, `FRMPART.PAL`/`TABS.PAL`/`NPAL5.PAL` palette selection, `goog` notification registration/unregistration and `message+4` handling through `Pane::MarkForDeletion`, vtable-only paint/notify reachability, ten constructor refs, factory/refresh callers, current generated-output status, FrameChrome slot ownership, `g_pGeneralPurposePanel+0x20` active-child index inference, `RenderTileFrame`/`ResourceLayoutTable`/`ChangeMan` dependency boundaries, rejected GeneralPurposePanel/Surface/ResourceLayoutTable/STL/generated-owner alternatives, and generated-code separation for adjustor thunks/scalar deleting destructor; aggregate formal C++ should stay blank or child-routed while authored bodies are C++-eligible on exact source children/support pages.
```

If the supervisor also repairs [UID:0000YI], replace its row with:

```markdown
    - [UID:0000YI][0x004615b0-0x00461658.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md) 0x004615b0-0x00461658 | helper pair | AboveFrameRefreshHelpers : reconstructable : 87% : strong : B003 2026-06-20 source-quality refresh repairs the half-open end to `0x00461658`, splits release helper `0x004615b0-0x004615c1`, padding `0x004615c1-0x004615d0`, and recreate helper `0x004615d0-0x00461658`; `ReleaseDynamicAboveFrame` deletes `0x0067a840` when present without clearing it, `RecreateDynamicAboveFrame` constructs `AboveFrame(g_pGeneralPurposePanel->m_activeChildIndex + 5, 0x4f, 0x328)` or stores zero on allocation failure, rejects the false `__std_parallel_algorithms_hw_threads` label, and keeps FrameChrome ownership despite GeneralPurposePanel switch callers.
```

If the supervisor refreshes [UID:0000YJ], replace its row with:

```markdown
    - [UID:0000YJ][0x004616c8-0x004616de.AboveFrameAdjustorThunks](by-memory/0x004616c8-0x004616de.AboveFrameAdjustorThunks.md) 0x004616c8-0x004616de | adjustor thunks | AboveFrameAdjustorThunks : ignored : 86% : strong : Compiler-generated secondary/tertiary `AboveFrame` destructor adjustor thunks, `this-0xa0` and `this-0xa4`, that jump to scalar deleting destructor wrapper `0x004616e0`; vtable-only refs from `0x00610f28` and `0x00610f58`, no handwritten C++ or emitter route, with `0x004616de-0x004616e0` PE-verified `0xcc` padding.
```

If the aggregate is later split into exact child rows, insert these internal padding rows in address order:

```markdown
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00461299-0x004612a0 | padding | AboveFrame constructor/destructor alignment : ignored : 100% : strong : B003 local PE byte audit confirms seven `0xcc` bytes between `AboveFrame::AboveFrame` and `AboveFrame::~AboveFrame`.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00461309-0x00461310 | padding | AboveFrame destructor/factory alignment : ignored : 100% : strong : B003 local PE byte audit confirms seven `0xcc` bytes between `AboveFrame::~AboveFrame` and `BuildAboveFrameBorder`.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004615aa-0x004615b0 | padding | AboveFrame factory/refresh alignment : ignored : 100% : strong : B003 local PE byte audit confirms six `0xcc` bytes between `BuildAboveFrameBorder` and `ReleaseDynamicAboveFrame`.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004615c1-0x004615d0 | padding | AboveFrame refresh-helper alignment : ignored : 100% : strong : B003 local PE byte audit confirms fifteen `0xcc` bytes between `ReleaseDynamicAboveFrame` and `RecreateDynamicAboveFrame`.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00461658-0x00461660 | padding | AboveFrame refresh/draw alignment : ignored : 100% : strong : B003 local PE byte audit confirms eight `0xcc` bytes between `RecreateDynamicAboveFrame` and `AboveFrame::OnPaint`.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004616af-0x004616b0 | padding | AboveFrame draw/notify alignment : ignored : 100% : strong : B003 local PE byte audit confirms one `0xcc` byte between `AboveFrame::OnPaint` and `AboveFrame::OnNotify`.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004616de-0x004616e0 | padding | AboveFrame thunk/scalar-deleting alignment : ignored : 100% : strong : B003 local PE byte audit confirms two `0xcc` bytes between the destructor adjustor thunks and scalar deleting destructor wrapper.
```

Existing outer padding rows for `0x004610ee-0x004610f0` and `0x0046178a-0x00461790` remain valid.

## Scoped Validator Baseline

Command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0000YH-AboveFrame-source-quality-removed.md](0000YH-AboveFrame-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code: `0`
- `ok: 1`
- File-level UID check passed for `0000YH`.
- Dry-run only; no by-* docs, generated docs, or coverage rows were written.

## Changed Files

Modified:

- `tools/leaser/Agents/Agent-B003/research/0000YH-AboveFrame-source-quality.md`

`by-memory/-coverage-report.md` was not edited.

FINISHED

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0000YH-AboveFrame-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:26","uid":"0000YH"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000YH-AboveFrame-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0000YH-AboveFrame-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000YH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
