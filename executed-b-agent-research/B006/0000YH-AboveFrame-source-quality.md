** TARGET-REPORT-UID:0000YH **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000YH AboveFrame Source-Quality / Split / C++ Readiness Report

## Finalized Report / Current Recommendation

- Target UID: `0000YH`
- Target path: `source-3/project-documentation/by-memory/0x004610f0-0x0046178a.AboveFrame.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B006/research/0000YH-AboveFrame-source-quality.md`
- Assignment: `B006-goal2-above-frame-source-quality-0000YH-20260619`
- Current target metadata observed: `COMPLETION:84`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000JL`, `EMITTER_UIDS:0000JL`, blank formal C++.
- Report-only rule followed: no by-* docs, generated docs/source, IDA DB, project-level reports, or `by-memory/-coverage-report.md` were edited.

Current recommendation:

- Keep `CANONICAL_OWNER:0000JL` and `EMITTER_UIDS:0000JL`; the best source route remains [UID:0000JL] `FrameChrome`, likely `NexusTK/ui/core/FrameChrome.cpp`.
- Raise target to `COMPLETION:87`, `CONFIDENCE:91` after implementation. The behavior, names, field meanings, resource routes, xrefs, vtables, and generated-code boundaries are now source-quality enough, but the broad target still overlaps child/helper pages and compiler glue.
- Treat `0000YH` as a mixed `AboveFrame` method/helper split-index, not as one monolithic source body. The target spans class methods, file-level helpers, internal padding, compiler adjustor thunks, and a scalar deleting destructor wrapper.
- Formal C++ for the current aggregate should stay blank or contain only a `[[CHILDREN]]` insertion point if the generator needs one. Put source bodies in exact children or in the class/file pages. Do not paste helper bodies and compiler ABI glue into this aggregate as if it were one method.
- First-draft source-style C++ is feasible for the source-authored bodies and is included below for implementation placement: class declaration in `by-class/AboveFrame.md`, class methods on exact method children or target class-method child pages, `BuildAboveFrameBorder()` in [UID:0000U2], and dynamic refresh helpers in [UID:0000YI]. Exclude `0x004616c8-0x004616de` and `0x004616e0-0x0046178a` from authored C++.

## Supervisor Active Recheck

- Supervisor requested a B-preferred report-only source-quality and heuristic/inference pass for [UID:0000YH] `AboveFrame`.
- Required focus was the full class island, constructor/destructor/draw/notify/deleting-destructor bodies, relationship to [UID:0000U2], [UID:0000YI], [UID:0000YJ], [UID:0001P1], [UID:0000PN], and [UID:0001XO], resource/palette/field validation, owner/emitter/source placement, score, and first-draft C++ policy.
- The current code-entry gate is met in metadata terms: `RECONSTRUCTABLE:TRUE`, valid nonblank emitter `0000JL`, and `(84 + 90) / 2 = 87 > 85`.
- The gate is not enough to justify monolithic aggregate C++, because this exact address interval contains separately documented helper children and compiler-generated ABI bodies. The safe implementation path is split/index C++ policy: exact child pages or `[[CHILDREN]]`, not a duplicate aggregate body.
- IDA MCP was attempted at `http://127.0.0.1:13337/mcp` and was unavailable from this session. I used local PE byte inspection, checked-in exported function records, current by-* docs, and existing checked-in IDA-derived evidence. This keeps confidence strong but below final-audit.

## Evidence Checked

Rule/workflow docs:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B006/goal.md`, including the Implementation Callback Detail Contract
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/tools/leaser/Agents/inference_research.md`
- `source-3/project-documentation/by-project-structure/proposed-source-tree.md`

Primary/support docs:

- `by-memory/0x004610f0-0x0046178a.AboveFrame.md`
- `by-class/AboveFrame.md`
- `by-file/FrameChrome.md`
- `by-item/BuildAboveFrameBorder_00461310.md`
- `by-memory/0x004615b0-0x00461657.AboveFrameRefreshHelpers.md`
- `by-memory/0x004616c8-0x004616de.AboveFrameAdjustorThunks.md`
- `by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md`
- `by-global/FrameChromeSlots.md`
- `by-type/by-vtable/AboveFrameVtables.md`
- `by-type/by-vtable/FrameChromeVtableFamily.md`
- `by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md`
- `by-memory/0x00610f60-0x00610fe8.FrameChromeResourceStrings.md`
- `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md`
- `by-memory/0x0067a740-0x0067a744.g_pBackPane.md` where available through wrapper docs
- `by-memory/0x0067a744-0x0067a748.g_pEPFLib.md`
- `by-memory/0x0067a874-0x0067a878.g_pGeneralPurposePanel.md`
- `by-memory/0x00544460-0x00545086.PaneCore.md`
- `by-class/Pane.md`
- `by-type/by-vtable/PaneVtables.md`
- `by-class/EPFTileContext.md`
- `by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md`
- `by-memory/0x004f4b30-0x004f4b4c.ApplicationRegisterChangeListener.md`
- `by-memory/0x004f4b50-0x004f4b6c.ApplicationUnregisterChangeListener.md`
- `by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md`
- `by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md`
- `by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md`

Local/export evidence:

- Local PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Exported function records under `resources/exported_data/functions/`:
  - `0x004610f0.json`
  - `0x004612a0.json`
  - `0x00461310.json`
  - `0x004615b0.json`
  - `0x004615d0.json`
  - `0x00461660.json`
  - `0x004616b0.json`
  - `0x004616c8.json`
  - `0x004616d3.json`
  - `0x004616e0.json`
- Generated/unrefined output was checked only as pollution evidence, especially `unrefined-source-backup/source/AboveFrame.cpp`; it still uses raw names and wrong owners such as `FittingRoomDownloadControlPane::meth_0x4b9980` and `BulletinSession::meth_0x544690`, so it must not be copied into formal docs.
- Existing B007/B008 repository research files for the same UID were checked as prior repository evidence, not as authority. B006 independently rechecked the PE bytes and exported records. This report agrees with their compiler-glue and FrameChrome ownership direction, rejects the B008 constructor coordinate ordering, and favors the split/index C++ policy rather than a monolithic aggregate block.

## Exact Range And Padding Inventory

Local PE byte audit against `NexusTK.exe` confirms these half-open boundaries and padding spans. The `.text` section has image base `0x00400000`; the relevant VAs map into `.text` and the dumped bytes match function starts/padding.

| Range | Size | Disposition | Evidence / notes |
| --- | ---: | --- | --- |
| `0x004610ee-0x004610f0` | `0x02` | padding | two `0xcc` bytes before constructor; current outer padding row is valid. |
| `0x004610f0-0x00461299` | `0x1a9` | source-authored class method | `AboveFrame::AboveFrame`. Exported size 425. |
| `0x00461299-0x004612a0` | `0x07` | padding | seven `0xcc` bytes. |
| `0x004612a0-0x00461309` | `0x69` | source-authored class method | `AboveFrame::~AboveFrame` ordinary destructor. Exported size 105. |
| `0x00461309-0x00461310` | `0x07` | padding | seven `0xcc` bytes. |
| `0x00461310-0x004615aa` | `0x29a` | source-authored file helper | `BuildAboveFrameBorder()`. Exported size 666. |
| `0x004615aa-0x004615b0` | `0x06` | padding | six `0xcc` bytes. |
| `0x004615b0-0x004615c1` | `0x11` | source-authored file helper | dynamic release helper. Current [UID:0000YI] page range text should use this subrange. |
| `0x004615c1-0x004615d0` | `0x0f` | padding | fifteen `0xcc` bytes. |
| `0x004615d0-0x00461658` | `0x88` | source-authored file helper | dynamic recreate helper. IDA currently labels it falsely as `___std_parallel_algorithms_hw_threads@0`. |
| `0x00461658-0x00461660` | `0x08` | padding | eight `0xcc` bytes. |
| `0x00461660-0x004616af` | `0x4f` | source-authored virtual method | paint/draw body. Exported size 79. |
| `0x004616af-0x004616b0` | `0x01` | padding | one `0xcc` byte. |
| `0x004616b0-0x004616c8` | `0x18` | source-authored virtual method | notify/change callback. Exported size 24. |
| `0x004616c8-0x004616d3` | `0x0b` | compiler thunk | secondary destructor adjustor, subtracts `0xa0`, jumps to `0x004616e0`. |
| `0x004616d3-0x004616de` | `0x0b` | compiler thunk | tertiary destructor adjustor, subtracts `0xa4`, jumps to `0x004616e0`. |
| `0x004616de-0x004616e0` | `0x02` | padding | two `0xcc` bytes. |
| `0x004616e0-0x0046178a` | `0xaa` | compiler scalar deleting destructor wrapper | generated wrapper around destructor cleanup plus conditional delete. Exported size 170. |
| `0x0046178a-0x00461790` | `0x06` | padding | six `0xcc` bytes before successor AES/helper island; current outer padding row is valid. |

Important range repair: [UID:0000YI] currently uses filename/path `0x004615b0-0x00461657.AboveFrameRefreshHelpers.md`. The recreate function's half-open end is `0x00461658`; the page and coverage row should be renamed/repaired to `0x004615b0-0x00461658.AboveFrameRefreshHelpers.md` when the supervisor accepts a split/range cleanup. The existing page already acknowledges that IDA's exclusive end for the second helper is `0x00461658`.

## Function / Child Inventory

| Range / item | UID / path | Role | Reconstructable | Direct owner | Emitter | Recommended status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004610f0-0x00461299` | inside `0000YH`; recommended exact child `AboveFrameConstructor` | constructor | true | `000005` `AboveFrame` | `0000JL` | source-authored; C++ ready after split or class-method child routing. |
| `0x004612a0-0x00461309` | inside `0000YH`; recommended exact child `AboveFrameDestructor` | ordinary destructor | true | `000005` `AboveFrame` | `0000JL` | source-authored; C++ ready; base destructor/vtable reseats stay compiler output. |
| `0x00461310-0x004615aa` | [UID:0000U2] `BuildAboveFrameBorder_00461310` | file helper/factory | true | `0000JL` `FrameChrome` | `0000JL` | source-authored; C++ ready after slot names are accepted as descriptive. |
| `0x004615b0-0x00461658` | [UID:0000YI] `AboveFrameRefreshHelpers` | release/recreate helpers | true | `0000JL` `FrameChrome` | `0000JL` | source-authored; needs path/end repair to `0x00461658`; C++ ready with descriptive names. |
| `0x00461660-0x004616af` | inside `0000YH`; recommended exact child `AboveFrameOnPaint` | virtual paint/draw | true | `000005` `AboveFrame` | `0000JL` | source-authored; prefer `OnPaint()` with `DrawFrame` kept as descriptive alias. |
| `0x004616b0-0x004616c8` | inside `0000YH`; recommended exact child `AboveFrameOnNotify` | virtual notify/change handler | true | `000005` `AboveFrame` | `0000JL` | source-authored; C++ ready with `ChangeMessage`/tag struct caveat. |
| `0x004616c8-0x004616de` | [UID:0000YJ] `AboveFrameAdjustorThunks` | destructor adjustor thunks | false | none/compiler | none | no handwritten C++; keep ignored/non-emitting. |
| `0x004616e0-0x0046178a` | inside `0000YH`; optional no-code child if split | scalar deleting destructor | false as source body | compiler from `AboveFrame` destructor | none | no authored C++; document as generated wrapper only. |

## Direct Xref / Caller Inventory

| Address / item | Xref / caller / callee | Meaning |
| --- | --- | --- |
| `0x004610f0` constructor | direct calls from `0x00461368`, `0x004613a0`, `0x004613db`, `0x00461423`, `0x00461476`, `0x004614ae`, `0x004614e9`, `0x00461535`, `0x00461570` | nine factory calls from `BuildAboveFrameBorder()`. |
| `0x004610f0` constructor | direct call from `0x00461626` | dynamic recreate helper constructs the current right/dynamic tab frame. |
| `0x00461310` factory | direct calls from `0x004f802c` and `0x004f8670` inside main UI initialization | source route is startup/main UI creating frame chrome; not a class method. |
| `0x004615b0` release | direct calls from `0x004b872e` and `0x004b8a62` | called after GeneralPurposePanel child switches; dependency on FrameChrome state, not GeneralPurposePanel ownership. |
| `0x004615d0` recreate | direct calls from `0x004b8733` and `0x004b8a67` | immediately rebuilds `0x0067a840` dynamic AboveFrame slot after switch. |
| `0x00461660` paint/draw | vtable data ref from primary slot `0x00610f20` | virtual paint/draw callback, no ordinary direct callers expected. |
| `0x004616b0` notify | vtable data ref from primary slot `0x00610ee4` | virtual ChangeMan/pane notification callback. |
| `0x004616c8` / `0x004616d3` | vtable refs from `0x00610f28` and `0x00610f58`; jumps to `0x004616e0` | compiler adjustor thunks for secondary/tertiary views. |
| `0x004616e0` | primary vtable slot `0x00610edc`; jumps from adjustors | compiler scalar deleting destructor wrapper. |
| constructor callees | `Pane::Pane(1)`, `EPFTileContext` init `0x00457a60`, `ResourceLayoutTable::LookupLayoutEntry`, `RectBounds::Offset`, `Pane::SetBounds`, `Pane::AddToLayer`, `Application::RegisterChangeListener` | confirms class source shape and external dependencies. |
| destructor/deleting destructor callees | `Application::UnregisterChangeListener`, `Pane::~Pane`, `operator delete` for deleting wrapper | confirms ordinary destructor versus generated deleting wrapper split. |
| paint/draw callee | `RenderTileFrame` at `0x004b9980` | shared Surface/GrafPort dependency, not FittingRoom owner. |
| notify callee | `Pane::MarkForDeletion` at `0x00544690` | generated `BulletinSession` owner is false; this is Pane deferred-deletion infrastructure. |

## Source-Quality Names And Signatures

### Class methods

Best source-facing method names/signatures:

```cpp
class AboveFrame : public Pane
{
public:
    AboveFrame(int frameIndex, int top, int left);
    ~AboveFrame() override;

protected:
    void OnPaint() override;      // old descriptive docs may keep "DrawFrame" as alias
    void OnNotify(void *sender, const ChangeMessage *message) override;

private:
    EPFTileContext m_tileContext; // +0x0f8, with bounds at +0x108
    RectBounds m_positionedBounds; // +0x120, populated in EPF/current layout path
    unsigned char m_framePaletteMode; // +0x130, 0=frame part, 1=tabs in EPF/current mode
};
```

Constructor parameter order must be `frameIndex, top, left`, not `frameIndex, left, top`. Evidence: the constructor stores the second stack argument into `this+0x124`/top and the third into `this+0x120`/left, and computes right/bottom as `left + width` and `top + height`. Factory call sites make this clear:

- current EPF branch: `(0, 0, 0)`, `(1, 9, 0)`, `(2, 9, 0x328)`, `(activeIndex + 5, 0x4f, 0x328)`
- legacy branch: `(0, 0x0c, 0x0e)`, `(1, 0x0c, 0x7d)`, `(2, 0x0c, 0x17a)`, loops `(3, y + 6, 0x0e)` and `(4, y, 0x1a4)`

Rejected alternative: `AboveFrame::AboveFrame(int frameIndex, int x, int y)` is weaker and likely wrong. It would place values like `0x328` / 808 in the vertical coordinate slot for fixed frames. The binary field stores and UI layout constants support `top, left`.

Paint/draw name: prefer `AboveFrame::OnPaint()` for source-facing docs because this body is reached through the Pane-derived primary vtable draw/paint slot and matches the many `OnPaint` by-memory pages. Keep `DrawFrame` as a descriptive or former page label if needed, because the current AboveFrame docs and vtable page already use "frame draw method". Do not keep raw `virt_meth_0x461660`.

Notify name: `AboveFrame::OnNotify(void *sender, const ChangeMessage *message)` or project-wide equivalent. The first stack argument is unused; the second is a record whose dword at `+4` is compared with `0x676f6f67`. `OnNotification` is an acceptable spelling if the Pane/ChangeMan callback vocabulary later standardizes on it. Do not keep raw `virt_meth_0x4616b0`.

### File-level helpers

Best source-facing helper names:

- `BuildAboveFrameBorder()` for `0x00461310-0x004615aa`; current IDA saved label and by-item page already support this.
- `ReleaseDynamicAboveFrame()` or `ReleaseDynamicAboveFrameSlot()` for `0x004615b0-0x004615c1`. I prefer `ReleaseDynamicAboveFrame()` for source spelling, with `Slot` acceptable in docs because the body reads `0x0067a840`.
- `RecreateDynamicAboveFrame()` or `RecreateDynamicAboveFrameSlot()` for `0x004615d0-0x00461658`. Reject `___std_parallel_algorithms_hw_threads@0`; the body allocates `0x134`, calls `AboveFrame::AboveFrame`, and stores `0x0067a840`.

### Globals/resources

| Binary fact | Recommended source-facing name | Confidence | Notes |
| --- | --- | --- | --- |
| `0x0066da97` | `g_useEpfAssets` | high | Existing by-global route documents broad current/legacy EPF mode selector. |
| `0x0067a744` | `g_pEPFLib` | high for global, medium for exact type | Calls `ResourceLayoutTable::LookupLayoutEntry`; final `ImageLib`/`ResourceLayoutTable` boundary remains open. |
| `0x0067a740` | `g_pBackPane` / application change-listener scope | medium-high | Wrapper docs show Application/ChangeMan register/unregister route; exact object name should follow existing global docs. |
| `0x0069b364` | main UI layer/context slot | medium | Passed to `Pane::AddToLayer`; exact source declaration belongs to layer/main UI docs. |
| `0x0067a840` | `g_pDynamicAboveFrame` | high descriptive | Dynamic/right-edge AboveFrame pointer; release/recreate helper target. |
| `0x0067a874` | `g_pGeneralPurposePanel` | high | Exact singleton pointer documented separately. |
| `g_pGeneralPurposePanel + 0x20` | `m_activeChildIndex` / `m_activeTabIndex` | medium-high behavior, provisional spelling | Constructor of GeneralPurposePanel stores child panes at `+0x04..+0x1c`; `+0x20` is read after switch helpers and feeds dynamic frame index `+5`. |
| `0x676f6f67` | `kAboveFrameNotifyTag` / `kPaneTagGoog` | high | The bytes spell `goog`; use integer constant for portability and consistency. |
| `FRMPART.EPF` | `kFramePartEpf` | high value, medium original spelling | UTF-16 resource string at `0x00610f60`. |
| `TABS.EPF` | `kTabsEpf` | high value, medium original spelling | UTF-16 resource string at `0x00610f78`. |
| `FRMPART.EPD` | `kFramePartEpd` | high value, medium original spelling | UTF-16 resource string at `0x00610f8c`. |
| `FRMPART.PAL` | `kFramePartPalette` | high value, medium original spelling | EPF frame-part paint path. |
| `TABS.PAL` | `kTabsPalette` | high value, medium original spelling | EPF tab paint path. |
| `NPAL5.PAL` | `kLegacyFramePalette` | high value, medium original spelling | legacy EPD paint path. |

## Behavior Details For By-* Incorporation

Constructor `0x004610f0-0x00461299`:

- Calls `Pane::Pane(1)`.
- Installs the three `AboveFrame` vtable views at `+0x00`, `+0xa0`, and `+0xa4`.
- Initializes `EPFTileContext` at `+0x0f8`.
- Branches on `g_useEpfAssets`.
- In EPF/current mode:
  - `frameIndex < 4`: calls `ResourceLayoutTable::LookupLayoutEntry(g_pEPFLib, L"FRMPART.EPF", frameIndex, &m_tileContext)` and sets `m_framePaletteMode` at `+0x130` to `0`.
  - `frameIndex >= 4`: sets `m_framePaletteMode` to `1`, loads `TABS.EPF`, and passes the compacted tab-frame expression `frameIndex + ((frameIndex - 4) < 2) - 5`. For observed fixed values, frame `4` maps to tab index `0`, frame `5` maps to `1`, and later dynamic values are derived from `activeChildIndex + 5`.
  - Copies the loaded tile bounds at `+0x108`, builds/stores positioned bounds at `+0x120` from `left/top` plus tile width/height, calls `RectBounds::Offset`, `Pane::SetBounds`, and `Pane::AddToLayer` using the current layer/context argument.
- In legacy mode:
  - loads `FRMPART.EPD`;
  - offsets a local copy of the loaded tile bounds with `left/top`;
  - passes that local rectangle to `Pane::SetBounds` and `Pane::AddToLayer`;
  - does not need the `+0x130` mode byte because paint ignores it when `g_useEpfAssets` is false.
- Registers the pane through `Application::RegisterChangeListener(..., this, 0x676f6f67, 0)`.

Ordinary destructor `0x004612a0-0x00461309`:

- Restores `AboveFrame` vtable views as ordinary compiler destructor output.
- Calls `Application::UnregisterChangeListener(..., this, 0x676f6f67, 0)`.
- Chains to `Pane::~Pane()`.
- Source should be only `AboveFrame::~AboveFrame() { Unregister...; }`; do not model vptr stores or explicit base-destructor call as handwritten source.

Paint/draw method `0x00461660-0x004616af`:

- Vtable-only primary slot `+0x44`.
- If `g_useEpfAssets != 1`, renders with `NPAL5.PAL`.
- If EPF/current mode, uses `TABS.PAL` when `m_framePaletteMode`/`this+0x130` is nonzero; otherwise uses `FRMPART.PAL`.
- Calls shared `RenderTileFrame(EPFTileContext*, RectBounds*, RectBounds*, int, const wchar_t*, int)` style helper at `0x004b9980` with `this+0x0f8` and `this+0x108` passed for both source/destination frame rectangles.
- Reject generated owner `FittingRoomDownloadControlPane`; SurfacePaintHelpers documents `0x004b9980` as broad shared `RenderTileFrame` with 311 callers.

Notify method `0x004616b0-0x004616c8`:

- Vtable-only primary slot `+0x08`.
- Has two stack arguments and returns with `ret 8`.
- Reads dword `message + 4`; if it equals `0x676f6f67`, calls `Pane::MarkForDeletion()` at `0x00544690`.
- Reject generated owner `BulletinSession`; PaneCore documents `0x00544690-0x005446ad` as `Pane::MarkForDeletion`, setting the deferred-delete marker and queuing through BlackHole.

Scalar deleting destructor `0x004616e0-0x0046178a`:

- Vtable primary slot `+0x00`.
- Repeats ordinary destructor cleanup, then checks compiler delete flags and calls global `operator delete` when scalar deletion is requested.
- Also has CFG/guard/vector-delete shaped output in Ghidra. That is compiler ABI, not source.
- Source should emit only `virtual ~AboveFrame()`/ordinary destructor. No formal C++ for this wrapper.

Adjustor thunks `0x004616c8-0x004616de`:

- `0x004616c8`: `sub ecx, 0xa0; jmp 0x004616e0`.
- `0x004616d3`: `sub ecx, 0xa4; jmp 0x004616e0`.
- Only vtable-owned. No direct source.

Build helper `0x00461310-0x004615aa`:

- Allocates `0x134` byte `AboveFrame` instances through the MemoryMan-backed `operator new` wrapper and constructs them into global slot storage.
- EPF/current branch:
  - `0x0067a834 = new AboveFrame(0, 0, 0)`
  - `0x0067a83c = new AboveFrame(1, 9, 0)`
  - `0x0067a838 = new AboveFrame(2, 9, 0x328)`
  - `0x0067a840 = new AboveFrame(g_pGeneralPurposePanel->m_activeChildIndex + 5, 0x4f, 0x328)` or zero on allocation failure.
- Legacy branch:
  - `0x0067a848 = new AboveFrame(0, 0x0c, 0x0e)`
  - `0x0067a834 = new AboveFrame(1, 0x0c, 0x7d)`
  - `0x0067a838 = new AboveFrame(2, 0x0c, 0x17a)`
  - loop y starts `0x5c`, increments `0x3f`, stops when y reaches `0x197`, creating five entries in `0x0067a84c-0x0067a860` with `(3, y + 6, 0x0e)` and five entries in `0x0067a860-0x0067a874` with `(4, y, 0x1a4)`.
- The exact original per-slot variable names are not proven; use descriptive names or keep address-backed table names until slot docs accept declarations.

Refresh helpers `0x004615b0-0x00461658`:

- `ReleaseDynamicAboveFrame()` reads `0x0067a840` and if non-null invokes its first vtable slot with delete flag `1`; it does not clear the global in this body.
- `RecreateDynamicAboveFrame()` allocates `0x134`, constructs `AboveFrame(g_pGeneralPurposePanel->m_activeChildIndex + 5, 0x4f, 0x328)`, stores it in `0x0067a840`, or stores zero on allocation failure.
- Caller location in GeneralPurposePanel switch helpers is trigger evidence only. The helper owns/manages FrameChrome state, so source owner remains FrameChrome.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best inference / decision | Rejected alternatives |
| --- | --- | --- | --- |
| Aggregate C++ policy | Target range contains source methods, file helpers, padding, adjustor thunks, and deleting destructor; child docs already exist for factory, refresh helpers, and thunks. | Keep `0000YH` blank or `[[CHILDREN]]` only; exact source-bearing children/class/file pages should carry C++. | Reject monolithic aggregate C++; it would duplicate [UID:0000U2]/[UID:0000YI], emit compiler glue, and obscure split policy. |
| Constructor parameter order | Exported IDA decompile stores argument 2 into top, argument 3 into left; factory values show horizontal constants in third position. | `AboveFrame(int frameIndex, int top, int left)`. | Reject `(frameIndex, x, y)`; values like `0x328` would become vertical coordinates and contradict field stores. |
| Draw method name | AboveFrame docs say `DrawFrame`; many Pane-derived source pages use `OnPaint`; vtable slot is paint/draw callback and body only renders. | Prefer `OnPaint()` for source-facing method, keep `DrawFrame` as descriptive alias until Pane slot vocabulary is final. | Reject raw `virt_meth_0x461660`; reject FittingRoom-owned method naming. |
| Notify method name/type | Vtable slot `+0x08`, two stack args, tag compare at `message+4`, ChangeMan registration uses same tag. | `OnNotify(void *sender, const ChangeMessage *message)` or project-wide `OnNotification`. | Reject raw `virt_meth_0x4616b0` and authentication/BulletinSession generated-owner summaries. |
| `0x004b9980` owner/name | SurfacePaintHelpers documents function `0x004b9980-0x004b99b1`, 311 callers, callback dispatch through render table. | Shared `RenderTileFrame` dependency under Surface/GrafPort, not AboveFrame owner. | Reject `FittingRoomDownloadControlPane::meth_0x4b9980`. |
| `0x00544690` owner/name | PaneCore documents exact `Pane::MarkForDeletion`, generated owners are artifacts. | `Pane::MarkForDeletion()` / deferred deletion. | Reject `BulletinSession::meth_0x544690`. |
| `0x004615d0` name | Exported record and docs show `operator new(0x134)`, `AboveFrame::AboveFrame`, store to `0x0067a840`. | `RecreateDynamicAboveFrame()` / `RecreateDynamicAboveFrameSlot()`. | Reject IDA `___std_parallel_algorithms_hw_threads@0`; no STL/thread semantics. |
| Refresh helper ownership | Callers are GeneralPurposePanel switch helpers, but body manipulates `FrameChrome` AboveFrame slot. | FrameChrome owner/emitter. | Reject GeneralPurposePanel ownership; caller dependency does not own slot lifecycle. |
| `g_pGeneralPurposePanel + 0x20` | Singleton docs show child panes at `+0x04..+0x1c`; switch helpers update active child; dynamic frame index uses `+5`. | high-probability active child/tab index. | Exact source spelling not provable; do not hard-code as proven original name. |
| `+0x108` and `+0x120` fields | Constructor initializes EPFTileContext at `+0xf8`; `+0x108` is inside context and used by paint; `+0x120` stores current-mode positioned pane bounds. | `m_tileContext.bounds` at `+0x108`; `m_positionedBounds` at `+0x120`. | Reject treating `+0x108` and `+0x120` as interchangeable. Paint uses `+0x108`; Pane bounds use `+0x120` in EPF/current mode. |
| Scalar deleting destructor | Ordinary destructor exists at `0x004612a0`; wrapper repeats cleanup and checks delete flags; vtable slot points to wrapper. | generated/no-code; source is ordinary/virtual destructor only. | Reject formal `ScalarDeletingDestructor` C++ body. |
| Adjustor thunks | Bytes are subtract-and-jump and vtable-only. | compiler-generated/no-code. | Reject handwritten thunk functions. |
| Source file | FrameChrome docs group AboveFrame, FramePartPane, resources, slots, builder, and refresh helpers under UI core FrameChrome. | Keep `FrameChrome.cpp` source route. | Reject ResourceLayoutTable/ImageLib, Surface/GrafPort, Pane, GeneralPurposePanel, FrameMgr, or TotemFrame as owner. |
| Score | Evidence is strong, but child split/range repair and final exact names are not applied. | target `87/91`; class/support docs can also rise modestly after detail incorporation. | Reject 95+ final-audit scoring; reject leaving at 84 after source-shape blockers are resolved. |

Remaining uncertainty that should stay documented:

- Exact original spellings for per-slot global variables and `g_pGeneralPurposePanel + 0x20` cannot be proven from the available binary evidence. Use descriptive names and mark as inferred.
- `g_pEPFLib` concrete source type remains between `ImageLib` and `ResourceLayoutTable` support docs. The target behavior only needs the lookup role, not a final class type.
- `OnPaint` versus project-wide `OnDraw`/`DrawFrame` spelling should follow the Pane-family naming standard when finalized. The source behavior and signature are resolved.

## Ranked Ownership Analysis

### 1. [UID:0000JL] FrameChrome

Evidence for:

- Owns current target metadata and source route.
- Proposed source tree places `FrameChrome.cpp` under `NexusTK/ui/core/`.
- Owns `AboveFrame`, `FramePartPane`, frame resource strings, palette string pool, global slot families, `BuildAboveFrameBorder`, dynamic refresh helpers, and vtable family pages.
- Startup/main UI calls the factory; GeneralPurposePanel only triggers refresh after active child switches.
- Resource/palette strings are frame chrome-specific: `FRMPART`, `TABS`, `NPAL5`.

Evidence against:

- Exact original filename is not proven; separate `AboveFrame.cpp` remains possible.
- Some dependencies live in Surface/GrafPort, Pane, ResourceLayoutTable, and GeneralPurposePanel.

Decision: accepted. Keep owner/emitter `0000JL`.

### 2. [UID:000005] AboveFrame class

Evidence for:

- Direct semantic owner of constructor, ordinary destructor, `OnPaint`/draw, `OnNotify`, and source-local vtables.
- [UID:0003I2] `AboveFrameVtables` already attaches to the class.

Evidence against:

- Not a by-file source root; emitted code routes through `FrameChrome`.
- File-level helpers `BuildAboveFrameBorder` and dynamic refresh are not class methods.

Decision: accepted as class-level direct semantic owner for method children and vtables, but not as the file emitter root.

### 3. GeneralPurposePanel

Evidence for:

- Switch helpers call `ReleaseDynamicAboveFrame()` and `RecreateDynamicAboveFrame()`.
- `g_pGeneralPurposePanel + 0x20` supplies the active child index for dynamic frame selection.

Evidence against:

- Helpers allocate/delete `AboveFrame` and write `FrameChromeSlots` storage.
- `GeneralPurposePanel` is a state provider/trigger, not source owner of frame chrome slots.

Decision: reject as owner; keep as caller/state dependency.

### 4. ResourceLayoutTable / ImageLib / g_pEPFLib

Evidence for:

- Constructor loads EPF/EPD resources through `ResourceLayoutTable::LookupLayoutEntry`.

Evidence against:

- Lookup is shared resource infrastructure; it does not decide frame layout, slots, palettes, notification, or pane lifecycle.

Decision: reject as owner; keep as dependency.

### 5. Surface / GrafPort

Evidence for:

- `OnPaint` calls shared `RenderTileFrame`.

Evidence against:

- Rendering helper is a dependency with broad caller fan-in; resource selection and object state belong to AboveFrame/FrameChrome.

Decision: reject as owner; keep SurfacePaintHelpers cross-link.

### 6. Pane

Evidence for:

- `AboveFrame` derives from `Pane`, uses `Pane::SetBounds`, `Pane::AddToLayer`, `Pane::MarkForDeletion`, and `Pane::~Pane`.

Evidence against:

- Derived class resources, slots, palettes, and notification tag are FrameChrome/AboveFrame behavior.

Decision: reject as owner; keep as base class dependency.

## First-Draft C++ Recommendation

Do not paste this whole section into the current `0000YH` aggregate formal C++ block. The current aggregate should remain blank or `[[CHILDREN]]` only. Use these snippets as exact-child/class/file draft material during the implementation callback.

### AboveFrame class declaration draft

```cpp
struct ChangeMessage
{
    unsigned int reserved;
    unsigned int tag;
};

class AboveFrame : public Pane
{
public:
    AboveFrame(int frameIndex, int top, int left);
    ~AboveFrame() override;

protected:
    void OnPaint() override;
    void OnNotify(void *sender, const ChangeMessage *message) override;

private:
    EPFTileContext m_tileContext;     // +0x0f8; bounds begin at +0x108
    RectBounds m_positionedBounds;    // +0x120; current-layout positioned pane bounds
    unsigned char m_framePaletteMode; // +0x130; 0=frame part, 1=tabs
};
```

### AboveFrame method draft

```cpp
namespace
{
    const unsigned int kAboveFrameNotifyTag = 0x676f6f67;

    enum AboveFramePaletteMode
    {
        kAboveFramePaletteFramePart = 0,
        kAboveFramePaletteTabs = 1
    };

    const wchar_t kFramePartEpf[] = L"FRMPART.EPF";
    const wchar_t kTabsEpf[] = L"TABS.EPF";
    const wchar_t kFramePartEpd[] = L"FRMPART.EPD";
    const wchar_t kFramePartPalette[] = L"FRMPART.PAL";
    const wchar_t kTabsPalette[] = L"TABS.PAL";
    const wchar_t kLegacyFramePalette[] = L"NPAL5.PAL";
}

AboveFrame::AboveFrame(int frameIndex, int top, int left)
    : Pane(1),
      m_framePaletteMode(kAboveFramePaletteFramePart)
{
    m_tileContext.Initialize();

    if (g_useEpfAssets)
    {
        if (frameIndex < 4)
        {
            g_pEPFLib->LookupLayoutEntry(kFramePartEpf, frameIndex, &m_tileContext);
            m_framePaletteMode = kAboveFramePaletteFramePart;
        }
        else
        {
            int tabFrameIndex = frameIndex - 5;
            if (frameIndex - 4 < 2)
                ++tabFrameIndex;

            g_pEPFLib->LookupLayoutEntry(kTabsEpf, tabFrameIndex, &m_tileContext);
            m_framePaletteMode = kAboveFramePaletteTabs;
        }

        m_positionedBounds.left = left;
        m_positionedBounds.top = top;
        m_positionedBounds.right = left + (m_tileContext.bounds.right - m_tileContext.bounds.left);
        m_positionedBounds.bottom = top + (m_tileContext.bounds.bottom - m_tileContext.bounds.top);

        SetBounds(m_positionedBounds, false);
        AddToLayer(m_positionedBounds, 0, 0, g_pMainUiLayer);
    }
    else
    {
        g_pEPFLib->LookupLayoutEntry(kFramePartEpd, frameIndex, &m_tileContext);

        RectBounds bounds = m_tileContext.bounds;
        bounds.Offset(left, top);
        SetBounds(bounds, false);
        AddToLayer(bounds, 0, 0, g_pMainUiLayer);
    }

    g_pBackPane->RegisterChangeListener(this, kAboveFrameNotifyTag, 0);
}

AboveFrame::~AboveFrame()
{
    g_pBackPane->UnregisterChangeListener(this, kAboveFrameNotifyTag, 0);
}

void AboveFrame::OnPaint()
{
    const wchar_t *paletteName = kLegacyFramePalette;

    if (g_useEpfAssets)
        paletteName = (m_framePaletteMode == kAboveFramePaletteTabs) ? kTabsPalette : kFramePartPalette;

    RenderTileFrame(&m_tileContext,
                    &m_tileContext.bounds,
                    &m_tileContext.bounds,
                    1,
                    paletteName,
                    0);
}

void AboveFrame::OnNotify(void *sender, const ChangeMessage *message)
{
    (void)sender;

    if (message != 0 && message->tag == kAboveFrameNotifyTag)
        MarkForDeletion();
}
```

Draft caveats:

- `Initialize`, `LookupLayoutEntry`, `SetBounds`, `AddToLayer`, `RegisterChangeListener`, `UnregisterChangeListener`, `RenderTileFrame`, and `MarkForDeletion` are source-quality names inferred from support docs. Adjust spelling to the final project API while preserving behavior.
- `g_pMainUiLayer` is a descriptive stand-in for the layer/context slot passed from `0x0069b364`; final global name belongs to layer/main UI support docs.
- The compact `TABS.EPF` index expression is copied source-style from the binary expression. Recheck exact signed/unsigned spelling if final implementation wants bit-identical optimized output.
- Do not include vtable stores, SEH scaffolding, security-cookie code, explicit base destructor calls, adjustor thunks, or scalar deleting destructor wrapper in source.

### FrameChrome helper draft

```cpp
void BuildAboveFrameBorder()
{
    if (g_useEpfAssets)
    {
        g_aboveFrame0 = new AboveFrame(0, 0, 0);
        g_aboveFrameTopTabs = new AboveFrame(1, 9, 0);
        g_aboveFrameRight = new AboveFrame(2, 9, 0x328);
        g_pDynamicAboveFrame = new AboveFrame(g_pGeneralPurposePanel->m_activeChildIndex + 5,
                                              0x4f,
                                              0x328);
        return;
    }

    g_aboveFrameLegacyFixed = new AboveFrame(0, 0x0c, 0x0e);
    g_aboveFrame0 = new AboveFrame(1, 0x0c, 0x7d);
    g_aboveFrameRight = new AboveFrame(2, 0x0c, 0x17a);

    int y = 0x5c;
    for (int i = 0; i < 5; ++i, y += 0x3f)
    {
        g_aboveFrameLeftColumn[i] = new AboveFrame(3, y + 6, 0x0e);
        g_aboveFrameRightColumn[i] = new AboveFrame(4, y, 0x1a4);
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

Helper draft caveats:

- Slot names are descriptive placeholders. Exact storage facts and constructor arguments are proven; original variable names are not.
- Source may have explicit non-throwing allocation/null checks rather than clean `new` expressions. The binary stores zero on allocation failure; use project reconstruction style consistently.
- `ReleaseDynamicAboveFrame()` does not clear `g_pDynamicAboveFrame` in this body.

## Recommended Target Doc Changes

For `by-memory/0x004610f0-0x0046178a.AboveFrame.md`:

1. Metadata:
   - `COMPLETION:87`
   - `CONFIDENCE:91`
   - keep `CANONICAL_OWNER:0000JL`
   - keep `RECONSTRUCTABLE:TRUE`
   - keep `EMITTER_UIDS:0000JL`
2. Change status wording from a simple class method cluster to a mixed source-bearing split-index: class methods plus file helpers plus compiler glue.
3. Keep formal C++ blank or add only `[[CHILDREN]]`; do not emit a monolithic class/helper aggregate block.
4. Add the range/padding inventory from this report, including the internal padding spans and the `0x004615d0-0x00461658` end repair.
5. Update functions table with source-facing names:
   - `AboveFrame::AboveFrame(int frameIndex, int top, int left)`
   - `AboveFrame::~AboveFrame()`
   - `AboveFrame::OnPaint()` / alias `DrawFrame`
   - `AboveFrame::OnNotify(...)`
   - scalar deleting destructor as generated/no-code
6. Add field notes:
   - vtable views at `+0x00/+0xa0/+0xa4`
   - `EPFTileContext m_tileContext` at `+0x0f8`
   - `m_tileContext.bounds` at `+0x108`
   - `RectBounds m_positionedBounds` at `+0x120`
   - `unsigned char m_framePaletteMode` at `+0x130`
7. Add exact constructor caller list and helper caller list.
8. Add generated-name rejection notes for `FittingRoomDownloadControlPane::meth_0x4b9980`, `BulletinSession::meth_0x544690`, and `___std_parallel_algorithms_hw_threads@0`.
9. Add C++ placement note: source-authored method snippets belong on exact method child pages/class declaration; [UID:0000U2]/[UID:0000YI] own helper snippets; [UID:0000YJ] and scalar deleting destructor are no-code.
10. Add change-log entry for this B006 source-quality pass.

## Recommended Support Doc Changes

`by-class/AboveFrame.md`:

- Raise to about `87/91` after incorporation.
- Remove "medium for final class name"; decorated vtables and current class docs prove `AboveFrame` strongly. Remaining uncertainty is exact method/helper spelling, not class identity.
- Add a declaration-level C++ shell with `[[CHILDREN]]`, the field table above, and method declarations for constructor, virtual destructor, `OnPaint`, and `OnNotify`.
- Correct constructor signature and argument semantics to `(frameIndex, top, left)`.
- Document that `+0x108` is tile-context bounds used by paint; `+0x120` is current-layout positioned pane bounds used by Pane registration/layer setup.
- State scalar deleting destructor and adjustor thunks are compiler output from the virtual destructor and inherited secondary/tertiary views.

`by-file/FrameChrome.md`:

- Add that `0000YH` is a mixed FrameChrome source island, not a single pure class-method body.
- State `BuildAboveFrameBorder`, `ReleaseDynamicAboveFrame`, and `RecreateDynamicAboveFrame` are file-level helpers beside `AboveFrame` class methods.
- Keep exact original filename caveat, but `FrameChrome.cpp` remains best source route under `NexusTK/ui/core/`.
- Reject GeneralPurposePanel/Surface/ResourceLayoutTable ownership for the refresh and paint paths.

`by-item/BuildAboveFrameBorder_00461310.md`:

- Correct tuple descriptions to `(frameIndex, top, left)`.
- Add current/legacy constructor argument inventory exactly as listed.
- Use `g_pGeneralPurposePanel->m_activeChildIndex + 5` as high-probability route for dynamic frame selection, with original field spelling provisional.
- Keep helper source ownership as FrameChrome, not class method.

`by-memory/0x004615b0-0x00461657.AboveFrameRefreshHelpers.md`:

- Rename/repair path and range to `0x004615b0-0x00461658.AboveFrameRefreshHelpers.md` when supervisor authorizes file move.
- Use `ReleaseDynamicAboveFrame()` and `RecreateDynamicAboveFrame()` as source-facing names.
- Document subranges `0x004615b0-0x004615c1`, `0x004615c1-0x004615d0` padding, and `0x004615d0-0x00461658`.
- State release deletes but does not clear the global in that helper.
- State recreate stores zero on allocation failure.
- Reject false IDA STL/thread label.

`by-memory/0x004616c8-0x004616de.AboveFrameAdjustorThunks.md`:

- Keep `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, no emitter, no C++.
- Raise row confidence/coverage wording to reflect exact PE byte recheck if not already present.
- Add explicit `this - 0xa0` and `this - 0xa4` adjustment and jump-to-wrapper proof.

`by-type/by-vtable/AboveFrameVtables.md` and `by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md`:

- Update primary slot `+0x44` name to `AboveFrame::OnPaint()` if accepted, with `DrawFrame` as descriptive alias.
- Keep primary slot `+0x00` as scalar deleting destructor wrapper and secondary/tertiary slots as adjustor thunks.
- Keep vtables attached to `AboveFrame`; do not hand-port dwords.

`by-type/by-vtable/FrameChromeVtableFamily.md`:

- Note source-local `AboveFrameVtables` owns exact AboveFrame vtables and `FrameChromeVtableFamily` remains mixed/non-emitting.

`by-global/FrameChromeSlots.md` and `by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md`:

- Add/confirm `0x0067a840` as dynamic/right-edge AboveFrame pointer, high-confidence descriptive `g_pDynamicAboveFrame`.
- Correct tuple semantics to `(frameIndex, top, left)`.
- Keep `0x0067a874` outside the AboveFrame slot range and point to `g_pGeneralPurposePanel`.
- Preserve `0x0067a844` as unreferenced padding/filler.

`by-memory/0x0067a874-0x0067a878.g_pGeneralPurposePanel.md` and class/file GeneralPurposePanel docs:

- Add a cross-note that FrameChrome dynamic AboveFrame creation reads `GeneralPurposePanel +0x20` as the high-probability active child/tab index and converts it to `TABS.EPF` frame index `+5`.
- Keep exact original field spelling provisional.

`by-memory/0x00610f60-0x00610fe8.FrameChromeResourceStrings.md`:

- Add cross-note that `AboveFrame::OnPaint()` chooses `FRMPART.PAL`/`TABS.PAL` in EPF mode and `NPAL5.PAL` in legacy mode.
- Keep strings separate from vtable data; `0x00610f60` begins resource string bytes, not vtable.

`by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md`:

- Add cross-note that `AboveFrame::OnPaint()` calls `RenderTileFrame` at `0x004b9980`; this is a shared Surface/GrafPort helper dependency, not source ownership.

`by-memory/0x00544460-0x00545086.PaneCore.md` / `by-class/Pane.md`:

- Optional cross-note that `AboveFrame::OnNotify()` reaches `Pane::MarkForDeletion()` at `0x00544690`, closing the generated `BulletinSession` owner pollution.

## Exact Coverage Row Text

Do not edit `by-memory/-coverage-report.md` from this B-agent report pass. If accepted, replace the current `0000YH` row with:

```markdown
    - [UID:0000YH][0x004610f0-0x0046178a.AboveFrame](by-memory/0x004610f0-0x0046178a.AboveFrame.md) 0x004610f0-0x0046178a | class/helper split-index | AboveFrame : reconstructable : 87% : very strong : B006 2026-06-19 source-quality pass resolves the FrameChrome-routed `AboveFrame` island as source-authored constructor/destructor/OnPaint/OnNotify class methods plus file-level `BuildAboveFrameBorder` and dynamic release/recreate helpers, PE-verified internal padding, `frameIndex/top/left` constructor argument order, `EPFTileContext`/bounds/palette-mode fields at `+0xf8/+0x108/+0x120/+0x130`, `FRMPART`/`TABS`/`NPAL5` resource and palette routes, `goog` notification handling through `Pane::MarkForDeletion`, shared `RenderTileFrame` dependency, vtable/delete-thunk/scalar-deleting destructor generated-code boundaries, rejected STL/FittingRoom/BulletinSession owner pollution, FrameChrome owner/emitter policy, and split/`[[CHILDREN]]` C++ placement instead of monolithic aggregate emission.
```

If supervisor authorizes the refresh-helper end repair, replace the current `0000YI` row with:

```markdown
    - [UID:0000YI][0x004615b0-0x00461658.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md) 0x004615b0-0x00461658 | helper pair | AboveFrameRefreshHelpers : reconstructable : 87% : strong : B006 source-quality pass repairs the half-open end to `0x00461658`, splits release helper `0x004615b0-0x004615c1`, padding `0x004615c1-0x004615d0`, and recreate helper `0x004615d0-0x00461658`; `ReleaseDynamicAboveFrame` deletes `0x0067a840` when present, `RecreateDynamicAboveFrame` constructs `AboveFrame(g_pGeneralPurposePanel->m_activeChildIndex + 5, 0x4f, 0x328)` or stores zero on allocation failure, rejects the false `___std_parallel_algorithms_hw_threads@0` label, and keeps FrameChrome ownership despite GeneralPurposePanel switch callers.
```

If supervisor refreshes the thunk row, replace the current `0000YJ` row with:

```markdown
    - [UID:0000YJ][0x004616c8-0x004616de.AboveFrameAdjustorThunks](by-memory/0x004616c8-0x004616de.AboveFrameAdjustorThunks.md) 0x004616c8-0x004616de | adjustor thunks | AboveFrameAdjustorThunks : ignored : 86% : strong : Compiler-generated secondary/tertiary `AboveFrame` destructor adjustor thunks, `this-0xa0` and `this-0xa4`, that jump to scalar deleting destructor wrapper `0x004616e0`; vtable-only refs from `0x00610f28` and `0x00610f58`, no handwritten C++ or emitter route, with `0x004616de-0x004616e0` PE-verified `0xcc` padding.
```

If the supervisor splits `0000YH` into exact child rows, insert these padding rows in address order between new child rows:

```markdown
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00461299-0x004612a0 | padding | AboveFrame constructor/destructor alignment : ignored : 100% : strong : B006 local PE byte audit confirms seven `0xcc` bytes between `AboveFrame::AboveFrame` and `AboveFrame::~AboveFrame`.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00461309-0x00461310 | padding | AboveFrame destructor/factory alignment : ignored : 100% : strong : B006 local PE byte audit confirms seven `0xcc` bytes between `AboveFrame::~AboveFrame` and `BuildAboveFrameBorder`.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004615aa-0x004615b0 | padding | AboveFrame factory/refresh alignment : ignored : 100% : strong : B006 local PE byte audit confirms six `0xcc` bytes between `BuildAboveFrameBorder` and `ReleaseDynamicAboveFrame`.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004615c1-0x004615d0 | padding | AboveFrame refresh-helper alignment : ignored : 100% : strong : B006 local PE byte audit confirms fifteen `0xcc` bytes between `ReleaseDynamicAboveFrame` and `RecreateDynamicAboveFrame`.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00461658-0x00461660 | padding | AboveFrame refresh/draw alignment : ignored : 100% : strong : B006 local PE byte audit confirms eight `0xcc` bytes between `RecreateDynamicAboveFrame` and `AboveFrame::OnPaint`.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004616af-0x004616b0 | padding | AboveFrame draw/notify alignment : ignored : 100% : strong : B006 local PE byte audit confirms one `0xcc` byte between `AboveFrame::OnPaint` and `AboveFrame::OnNotify`.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004616de-0x004616e0 | padding | AboveFrame thunk/scalar-deleting alignment : ignored : 100% : strong : B006 local PE byte audit confirms two `0xcc` bytes between the destructor adjustor thunks and scalar deleting destructor wrapper.
```

Existing outer rows for `0x004610ee-0x004610f0` and `0x0046178a-0x00461790` remain valid.

## IDA Rename / Type / Comment Recommendations

High-confidence IDA/source comments:

- `0x004610f0`: `AboveFrame::AboveFrame(int frameIndex, int top, int left)`.
- `0x004612a0`: `AboveFrame::~AboveFrame()`.
- `0x00461660`: `AboveFrame::OnPaint()`; old descriptive alias `DrawFrame`.
- `0x004616b0`: `AboveFrame::OnNotify(void *sender, const ChangeMessage *message)`.
- `0x00461310`: `BuildAboveFrameBorder()`.
- `0x004615b0`: `ReleaseDynamicAboveFrame()`.
- `0x004615d0`: `RecreateDynamicAboveFrame()`.
- `0x004616c8`: compiler adjustor thunk, `this -= 0xa0`, jump to `0x004616e0`.
- `0x004616d3`: compiler adjustor thunk, `this -= 0xa4`, jump to `0x004616e0`.
- `0x004616e0`: compiler scalar deleting destructor wrapper for `AboveFrame`; no source body.
- `this+0x0f8`: `EPFTileContext m_tileContext`.
- `this+0x108`: `m_tileContext.bounds`.
- `this+0x120`: `RectBounds m_positionedBounds`.
- `this+0x130`: `unsigned char m_framePaletteMode`.
- `0x0067a840`: `g_pDynamicAboveFrame`.
- Comment `0x004b9980` use as shared `RenderTileFrame`.
- Comment `0x00544690` use as `Pane::MarkForDeletion`.

Medium/provisional:

- `g_pGeneralPurposePanel + 0x20`: `m_activeChildIndex` or `m_activeTabIndex`.
- Per-slot global names under `0x0067a834-0x0067a874`: keep descriptive until a declaration pass accepts names.
- `OnPaint` versus `OnDraw` spelling should follow final Pane virtual naming convention.

## Implementation Callback Checklist

If the supervisor accepts this report and sends B006 an implementation callback:

1. Lease target/support docs before editing.
2. Do not edit `by-memory/-coverage-report.md`; preserve exact rows above for supervisor-owned application.
3. Update target `0000YH` metadata to `87/91`, owner/emitter unchanged.
4. Convert target status to mixed split-index; formal C++ blank or `[[CHILDREN]]` only.
5. Insert boundary/padding inventory, function inventory, xrefs, field names, resource/palette behavior, helper relationships, rejected alternatives, and score rationale from this report.
6. Add first-draft C++ only to accepted class/exact child/support docs:
   - `by-class/AboveFrame.md`: declaration shell with `[[CHILDREN]]`;
   - exact future method children for constructor/destructor/OnPaint/OnNotify, or target child slots if supervisor creates them;
   - [UID:0000U2] for `BuildAboveFrameBorder`;
   - [UID:0000YI] for `ReleaseDynamicAboveFrame` and `RecreateDynamicAboveFrame`.
7. Keep [UID:0000YJ] and scalar deleting destructor no-code.
8. Repair [UID:0000YI] range/path to `0x00461658` if supervisor authorizes rename.
9. Update support docs listed above at report-level detail, preserving rejected alternatives and generated-name pollution notes.
10. Run scoped validators from `source-3/project-documentation`.

## Validator Needs

No validators were run because this pass creates only a B006 research report and intentionally does not edit by-* docs.

Expected validation commands after implementation from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0000YH-AboveFrame-source-quality-removed.md](0000YH-AboveFrame-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If optional cross-note support docs are edited, also run:

> Executable block R002 was removed from this report and preserved verbatim in [0000YH-AboveFrame-source-quality-removed.md](0000YH-AboveFrame-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If [UID:0000YI] is renamed to `0x004615b0-0x00461658.AboveFrameRefreshHelpers.md`, run validator on the new path after the move and update `tools/validator.ini` through validator registration if required by the project workflow.

## Changed Files

Created:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B006/research/0000YH-AboveFrame-source-quality.md`

Modified:

- None.

Renamed/moved:

- None.

FINISHED

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0000YH-AboveFrame-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"0000YH"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000YH-AboveFrame-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/0000YH-AboveFrame-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000YH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
