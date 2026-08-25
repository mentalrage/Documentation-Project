** TARGET-REPORT-UID:0000YH **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000YH AboveFrame Source-Quality / Split / Placement Pass

Agent: Agent-B007  
Assignment: [UID:0000YH] `AboveFrame`  
Target: `by-memory/0x004610f0-0x0046178a.AboveFrame.md`  
Required report: `tools/leaser/Agents/Agent-B007/research/0000YH-AboveFrame-source-quality.md`  
Date: 2026-06-19

## Finalized Report / Current Recommendation

`0000YH` is a valid FrameChrome-routed AboveFrame code island, but it is not a clean single source body. The address interval contains:

- source-authored `AboveFrame` constructor, destructor, draw, and notify methods;
- the file-level `BuildAboveFrameBorder` factory;
- the dynamic release/recreate helper pair;
- compiler-generated secondary and tertiary destructor adjustor thunks;
- compiler-generated scalar deleting destructor glue;
- internal `0xcc` alignment padding between the real functions.

Do not populate the current aggregate page's formal C++ block as one monolithic reconstruction. The defensible next step is to split or child-route the source-authored bodies and leave compiler glue as no-code. Keep `CANONICAL_OWNER:0000JL` and `EMITTER_UIDS:0000JL` for the aggregate until the split is applied, because the best source file remains `FrameChrome.cpp`. At method granularity, the direct semantic owner is class UID `000005` (`AboveFrame`); at file-helper granularity, the direct source owner is file UID `0000JL` (`FrameChrome`).

Recommended score after incorporating this pass into the canonical docs: `COMPLETION:86`, `CONFIDENCE:90`. Do not raise higher until exact child pages exist, the stale refresh-helper filename is repaired, and final helper/wrapper names for draw, notify, and the GeneralPurposePanel `+0x20` field are supported by live IDA or equivalent callee evidence.

## Supervisor Active Recheck

- Current code-entry gate: `RECONSTRUCTABLE:TRUE`, nonblank `EMITTER_UIDS`, valid emitter file, and `(COMPLETION + CONFIDENCE) / 2 > 85`.
- Current target stats: `COMPLETION:84`, `CONFIDENCE:90`, average `87.0`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JL`.
- Gate result: the range is eligible in score/metadata terms, but the aggregate is mixed and overlaps separately documented children. Emitting one C++ block at `0000YH` would duplicate or swallow bodies that should be separate first-class source units.
- Required action: move the first-draft C++ into exact method/helper children, or convert `0000YH` into a split-index page whose C++ block stays blank and whose children carry the source.
- Coverage rule: `by-memory/-coverage-report.md` was not edited. Exact replacement rows are included below.
- Lease state: current lease report was checked. Only expired unrelated Supervisor leases were visible. The required report path did not exist and is inside Agent-B007's own research folder; no by-memory or coverage file was edited.

## Evidence Standards Used

Primary documentation reviewed:

- `by-memory/0x004610f0-0x0046178a.AboveFrame.md`
- `by-class/AboveFrame.md`
- `by-file/FrameChrome.md`
- `by-item/BuildAboveFrameBorder_00461310.md`
- `by-memory/0x004615b0-0x00461657.AboveFrameRefreshHelpers.md`
- `by-memory/0x004616c8-0x004616de.AboveFrameAdjustorThunks.md`
- `by-type/by-vtable/AboveFrameVtables.md`
- `by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md`
- `by-memory/0x00610f60-0x00610fe8.FrameChromeResourceStrings.md`
- `by-global/FrameChromeSlots.md`
- `by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md`
- `by-memory/0x0067a874-0x0067a878.g_pGeneralPurposePanel.md`
- `by-file/Pane.md`, `by-class/Pane.md`
- `by-file/EPFTileContext.md`, `by-class/EPFTileContext.md`
- comparable pages for `TotemFrame` and `MapPaneTagDetachMessage`
- refreshed completion stats and auto-generated coverage rows
- generated `simroot_v2/class_AboveFrame.cpp` as a lead only, not source authority

Live IDA/MCP could not be used in this pass: `http://127.0.0.1:13337/mcp` was not reachable. I therefore kept confidence at 90 and treated older IDA-confirmed facts already recorded in canonical docs plus local PE byte checks as the highest available evidence.

## Exact Range And Padding Inventory

Local PE byte audit against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` confirms the function and padding boundaries below. The half-open end for source pages should match these values.

| Range | Size | Disposition | Notes |
| --- | ---: | --- | --- |
| `0x004610f0-0x00461299` | `0x1a9` | source-authored | `AboveFrame::AboveFrame` |
| `0x00461299-0x004612a0` | `0x07` | padding | all `0xcc` |
| `0x004612a0-0x00461309` | `0x69` | source-authored | `AboveFrame::~AboveFrame` ordinary destructor body |
| `0x00461309-0x00461310` | `0x07` | padding | all `0xcc` |
| `0x00461310-0x004615aa` | `0x29a` | source-authored helper | `BuildAboveFrameBorder` factory |
| `0x004615aa-0x004615b0` | `0x06` | padding | all `0xcc` |
| `0x004615b0-0x004615c1` | `0x11` | source-authored helper | dynamic slot release helper; current page text has the size but row/path end is stale |
| `0x004615c1-0x004615d0` | `0x0f` | padding | all `0xcc` |
| `0x004615d0-0x00461658` | `0x88` | source-authored helper | dynamic slot recreate helper; current IDA label is false STL label |
| `0x00461658-0x00461660` | `0x08` | padding | all `0xcc` |
| `0x00461660-0x004616af` | `0x4f` | source-authored | `AboveFrame::DrawFrame` |
| `0x004616af-0x004616b0` | `0x01` | padding | all `0xcc` |
| `0x004616b0-0x004616c8` | `0x18` | source-authored | `AboveFrame::OnNotify` |
| `0x004616c8-0x004616de` | `0x16` | compiler-generated | secondary/tertiary destructor adjustor thunks |
| `0x004616de-0x004616e0` | `0x02` | padding | all `0xcc` |
| `0x004616e0-0x0046178a` | `0xaa` | compiler-generated wrapper | scalar deleting destructor; generated from delete semantics, not source-authored method body |
| `0x0046178a-0x00461790` | `0x06` | padding | all `0xcc`; already tracked as following alignment padding |

The current `0x004615b0-0x00461657.AboveFrameRefreshHelpers.md` filename is off by one/end convention. Its body already records the recreate helper's end-exclusive `0x00461658`. Rename/repair to `0x004615b0-0x00461658.AboveFrameRefreshHelpers.md`.

## Function / Helper Inventory

| Body | Best source name | Owner | Emitter | C++ disposition |
| --- | --- | --- | --- | --- |
| `0x004610f0-0x00461299` | `AboveFrame::AboveFrame` | `000005` | `0000JL` | source-authored, eligible after split |
| `0x004612a0-0x00461309` | `AboveFrame::~AboveFrame` | `000005` | `0000JL` | source-authored ordinary destructor, eligible after split |
| `0x00461310-0x004615aa` | `BuildAboveFrameBorder` | `0000JL` | `0000JL` | source-authored file helper, eligible after slot-name support |
| `0x004615b0-0x004615c1` | `ReleaseDynamicAboveFrameSlot` | `0000JL` | `0000JL` | source-authored file helper, eligible after split/rename |
| `0x004615d0-0x00461658` | `RecreateDynamicAboveFrameSlot` | `0000JL` | `0000JL` | source-authored file helper, eligible after split/rename |
| `0x00461660-0x004616af` | `AboveFrame::DrawFrame` | `000005` | `0000JL` | source-authored, eligible after draw-wrapper naming support |
| `0x004616b0-0x004616c8` | `AboveFrame::OnNotify` | `000005` | `0000JL` | source-authored, eligible after notify-destroy helper support |
| `0x004616c8-0x004616de` | adjustor thunks | compiler | none | no handwritten C++; `RECONSTRUCTABLE:FALSE`/ignored |
| `0x004616e0-0x0046178a` | scalar deleting destructor | compiler | none | no handwritten C++; generated wrapper around `~AboveFrame` plus conditional delete |

## Constructor / Destructor / Draw / Notify Facts

Constructor:

- Calls the `Pane` constructor and installs the three AboveFrame vtable views at offsets `+0x000`, `+0x0a0`, and `+0x0a4`.
- Uses `EPFTileContext` storage beginning at object offset `+0x0f8`.
- The tile/context bounds begin at object offset `+0x108`; this matches `EPFTileContext` field offset `+0x10`.
- The positioned pane bounds are at object offset `+0x120`.
- The frame/tab resource mode flag is at object offset `+0x130`.
- For EPF mode and frame indices `< 4`, loads `FRMPART.EPF` and uses frame-parts palette mode.
- For EPF mode and frame indices `>= 4`, loads `TABS.EPF`; the generated lead shows an index adjustment around values `4` and `5`.
- For legacy mode, loads `FRMPART.EPD`.
- Registers for pane tag `0x676f6f67` (`goog`), using the project pattern from `MapPaneTagDetachMessage`.

Destructor:

- Unregisters the same `goog` notification route and chains into the base `Pane` destructor through normal compiler output.
- The ordinary destructor at `0x004612a0-0x00461309` is the only source-authored destructor body in this cluster.
- Vtable reseating and base destructor chaining are compiler output and should not be over-modeled in handwritten source.

Draw:

- Vtable primary slot `+0x44` points to `0x00461660`.
- Chooses palette by resource mode:
  - EPF/frame part: `FRMPART.PAL`
  - EPF/tab: `TABS.PAL`
  - legacy EPD: `NPAL5.PAL`
- Uses the tile context and positioned bounds to draw the frame/tile. The exact source wrapper name should be checked against the FrameChrome/EPF drawing helpers before committing formal C++; `RenderTileFrame` is supported nearby by comparable frame draw docs, while `DrawTileWithPalette` remains descriptive.

Notify:

- Vtable primary slot `+0x08` points to `0x004616b0`.
- Handles `TaggedPaneMessage` tag `0x676f6f67` (`goog`).
- The source-facing message tag pattern should be:

```cpp
struct TaggedPaneMessage
{
    unsigned int unused0;
    unsigned int tag;
};

static const unsigned int kPaneTagGoog = 0x676f6f67;
```

- Avoid a multi-character literal for `goog`; the project already prefers the integer constant form.
- The exact destroy/deferred-delete helper name for this method still needs a live callee check. `DestroySelf()` is acceptable only as draft placeholder text, not a final proven name.

## Factory / Refresh Helper Facts

`BuildAboveFrameBorder` (`0x00461310-0x004615aa`):

- Allocates `AboveFrame` objects with object size `0x134`.
- EPF branch (`g_useEpfAssets == 1`) creates:
  - slot `0x0067a834` with args `(0, 0, 0)`;
  - slot `0x0067a83c` with args `(1, 9, 0)`;
  - slot `0x0067a838` with args `(2, 9, 0x328)`;
  - dynamic slot `0x0067a840` with args `(*(dword_67A874 + 0x20) + 5, 0x4f, 0x328)`.
- Legacy branch creates:
  - slot `0x0067a848` with args `(0, 0x0c, 0x0e)`;
  - slot `0x0067a834` with args `(1, 0x0c, 0x7d)`;
  - slot `0x0067a838` with args `(2, 0x0c, 0x17a)`;
  - array `0x0067a84c-0x0067a860` with frame index `3`, x `0x0e`, y starting `0x5c`, increment `0x3f`, five entries;
  - array `0x0067a860-0x0067a874` with frame index `4`, x `0x1a4`, y starting `0x5c`, increment `0x3f`, five entries.
- The exact original slot variable names are not proven. Keep descriptive `FrameChrome` slot names until a support pass creates declarations.

Refresh helpers (`0x004615b0-0x00461658`):

- `0x004615b0-0x004615c1` deletes/releases the dynamic slot if non-null. Source-level `delete g_pDynamicAboveFrame;` is a reasonable draft; the binary does not require a visible explicit null store in this helper.
- `0x004615d0-0x00461658` recreates the dynamic slot using `g_pGeneralPurposePanel + 0x20`, adds `5`, and constructs `AboveFrame(index, 0x4f, 0x328)`.
- Caller docs place these helpers under GeneralPurposePanel child-switch activity, but caller location is not ownership. The owner remains FrameChrome because the helpers allocate and manage FrameChrome's AboveFrame slot.
- Reject the current false IDA name `__std_parallel_algorithms_hw_threads`; there is no STL/threading semantic in this body.

## FrameChrome Field / Resource / Palette Names

Recommended source-facing names, with confidence:

| Binary/global fact | Recommended name | Confidence | Notes |
| --- | --- | --- | --- |
| `byte_66DA97` | `g_useEpfAssets` | high | Already used as canonical descriptive name; exact original spelling unproven. |
| `0x0067a834` etc. | `FrameChrome` AboveFrame slots | high family, medium individual names | Slot family is proven; exact per-slot variable names need declaration pass. |
| `0x0067a840` | `g_pDynamicAboveFrame` / `g_pRightSideAboveFrame` | medium | Dynamic recreate slot; final source name not proven. |
| `dword_67A874` | `g_pGeneralPurposePanel` | high | Separate canonical global page confirms owner and identity. |
| `dword_67A874 + 0x20` | active child/frame index source | medium | Behavior is proven, exact field name is not. Use a helper or descriptive member until final support exists. |
| `FRMPART.EPF` | `kFramePartEpf` | high value, medium constant spelling | Resource string at `0x00610f60`. |
| `TABS.EPF` | `kTabsEpf` | high value, medium constant spelling | Resource string at `0x00610f78`. |
| `FRMPART.EPD` | `kFramePartEpd` | high value, medium constant spelling | Resource string at `0x00610f8c`. |
| `FRMPART.PAL` | `kFramePartPalette` | high value, medium constant spelling | Palette selected by draw. |
| `TABS.PAL` | `kTabsPalette` | high value, medium constant spelling | Palette selected by tab draw path. |
| `NPAL5.PAL` | `kLegacyFramePalette` | high value, medium constant spelling | Palette selected by legacy EPD path. |
| `0x676f6f67` | `kPaneTagGoog` | high | Project pattern supports integer constant, not multi-character literal. |

## Owner / Emitter Routing

Best route:

- `FrameChrome` (`0000JL`) owns the source file placement for AboveFrame, frame resource strings, palettes, global slots, factories, and refresh helpers.
- `AboveFrame` class (`000005`) owns the class method semantics and generated vtables.
- `FrameChromeSlots` owns the global slot family documentation, but the initializer/rebuilder code still emits through `FrameChrome.cpp`.

Rejected alternatives:

- `GeneralPurposePanel`: rejected as owner. It calls refresh helpers and supplies the `+0x20` state value, but the helpers allocate and manage FrameChrome slots.
- `ResourceLayoutTable` / ImageLib: rejected as owner. These are dependencies used for EPF/EPD lookups, not the source home of the visible frame chrome object.
- `Pane`: rejected as owner. `AboveFrame` derives from Pane and uses Pane notification/draw infrastructure, but the method bodies are derived-class/UI chrome logic.
- `GrafPort`: rejected as owner. Draw helpers are dependencies; palette/resource selection and object state belong to AboveFrame/FrameChrome.
- `FrameMgr` / FrameHandler: rejected as owner. The proposed source tree separates callback/scheduler frame infrastructure from visible frame-border pane construction.
- `TotemFrame`: rejected as owner. It is a comparable pattern only; resource family and slot ownership differ.

## Split / Source-Placement Recommendation

Preferred repair:

1. Keep the aggregate `0x004610f0-0x0046178a.AboveFrame.md` as a split-index/source-quality page or narrow it to an owning cluster with explicit `[[CHILDREN]]`.
2. Create or migrate exact source-authored child pages:
   - `0x004610f0-0x00461299.AboveFrameConstructor.md`
   - `0x004612a0-0x00461309.AboveFrameDestructor.md`
   - `0x00461310-0x004615aa.BuildAboveFrameBorder.md` or a by-memory mirror/migration of UID `0000U2`
   - `0x004615b0-0x00461658.AboveFrameRefreshHelpers.md`
   - `0x00461660-0x004616af.AboveFrameDrawFrame.md`
   - `0x004616b0-0x004616c8.AboveFrameOnNotify.md`
3. Keep `0x004616c8-0x004616de.AboveFrameAdjustorThunks.md` non-reconstructable/ignored.
4. Do not create a source-emitting child for `0x004616e0-0x0046178a` unless it is explicitly marked as compiler scalar-deleting destructor glue with no handwritten C++.
5. Track internal padding only if the aggregate is split into exact children. Otherwise the parent range already contains the padding as internal alignment evidence.

If project policy allows broad class clusters like `TotemFrame`, an alternate route is to keep `0000YH` as the aggregate and place multiple source snippets inside it. I do not recommend that here because `BuildAboveFrameBorder` and the refresh helpers are already separately documented and should not be duplicated by an aggregate C++ emission block.

## Heuristic / Inference Reanalysis And Validation

| Heuristic/inference | Evidence checked | Rejected alternatives | Final disposition |
| --- | --- | --- | --- |
| `0000YH` should emit one monolithic C++ block | Target metadata meets score gate, but range contains class methods, file helpers, padding, thunks, and scalar deleting destructor. | Emitting aggregate body would duplicate `0000U2`, `0000YI`, and `0000YJ` or hide needed child placement. | Reject monolithic emission; split/source-index first. |
| `BuildAboveFrameBorder` is source-authored | By-item page has exact range, constructor call inventory, global slot writes, and prior IDA label save. | Treating as class method is wrong because it constructs many global slots. | Keep as FrameChrome file helper, source-authored. |
| `0x004615d0` is `__std_parallel_algorithms_hw_threads` | Body constructs an `AboveFrame` from GeneralPurposePanel state and stores `0x0067a840`; no threading/STL behavior. | Current IDA label is false. | Rename descriptively to `RecreateDynamicAboveFrameSlot` or equivalent. |
| Refresh helpers belong to GeneralPurposePanel | Caller docs show GeneralPurposePanel switch helpers call the pair. | Caller ownership is not source ownership; helpers manipulate FrameChrome slots. | Keep FrameChrome owner/emitter. |
| `0x004616c8-0x004616de` needs C++ | Vtable docs and thunk page show `this -= 0xa0` / `this -= 0xa4` then jump to scalar deleting destructor. | Handwriting adjustor functions would model compiler ABI, not source. | No C++; ignored/non-reconstructable. |
| `0x004616e0-0x0046178a` is a real destructor body | Ordinary destructor already exists at `0x004612a0`; generated lead duplicates destructor work and conditionally deletes. | Naming it `AboveFrame::ScalarDeletingDestructor` as source would leak compiler glue. | No source body; generated wrapper only. |
| `dword_67A874 + 0x20` can be named exactly now | Canonical global page identifies `g_pGeneralPurposePanel`; docs only establish behavior of `+0x20`. | Pretending exact field name is known would overfit generated output. | Use descriptive active child/frame index wording until live support exists. |
| `goog` should be written as `'goog'` | Comparable `MapPaneTagDetachMessage` page uses integer constant `0x676f6f67`. | Multi-character literal is compiler-dependent and not project style. | Use `kPaneTagGoog = 0x676f6f67`. |
| Resource strings belong in AboveFrame vtable data | Vtable data page proves `0x00610f60` begins UTF-16 `FRMPART.EPF`; resource string page owns the string island. | Extending vtable slots into strings repeats the known bad auto-summary issue. | Keep strings in FrameChrome resource string island. |
| Target can be scored above 90 now | Strong range/resource/owner evidence exists, but no live MCP this session and split is not applied. | Raising to 95+ would violate inference guidance. | Recommend `86/90`, not higher. |

No compiler-generated helper names remain accepted as source names. Where final source names are still not proven, this report records the evidence and keeps the name descriptive instead of pretending exact original spellings are known.

## First-Draft C++ Recommendation

Do not paste this into the current aggregate `0000YH` C++ block. Use it as split-child draft material after the exact pages above exist and helper names are supported. The snippets intentionally avoid generated thunks and scalar deleting destructor code.

```cpp
struct TaggedPaneMessage
{
    unsigned int unused0;
    unsigned int tag;
};

static const unsigned int kPaneTagGoog = 0x676f6f67;

static const wchar_t kFramePartEpf[] = L"FRMPART.EPF";
static const wchar_t kTabsEpf[] = L"TABS.EPF";
static const wchar_t kFramePartEpd[] = L"FRMPART.EPD";
static const wchar_t kFramePartPalette[] = L"FRMPART.PAL";
static const wchar_t kTabsPalette[] = L"TABS.PAL";
static const wchar_t kLegacyFramePalette[] = L"NPAL5.PAL";

AboveFrame::AboveFrame(int frameIndex, int y, int x)
    : Pane(1),
      m_frameResourceMode(0)
{
    m_tileContext.Initialize();

    if (g_useEpfAssets)
    {
        if (frameIndex < 4)
        {
            g_pEPFLib->LoadTile(kFramePartEpf, frameIndex, &m_tileContext);
            m_frameResourceMode = 0;
        }
        else
        {
            int tabIndex = frameIndex - 5;
            if (frameIndex - 4 < 2)
                ++tabIndex;

            g_pEPFLib->LoadTile(kTabsEpf, tabIndex, &m_tileContext);
            m_frameResourceMode = 1;
        }
    }
    else
    {
        g_pEPFLib->LoadTile(kFramePartEpd, frameIndex, &m_tileContext);
        m_frameResourceMode = 0;
    }

    m_frameBounds = m_tileContext.bounds;
    m_positionedBounds = m_frameBounds;
    OffsetRect(&m_positionedBounds, x, y);
    SetPaneBounds(&m_positionedBounds);
    RegisterPaneTag(this, kPaneTagGoog);
}

AboveFrame::~AboveFrame()
{
    UnregisterPaneTag(this, kPaneTagGoog);
}

void AboveFrame::DrawFrame()
{
    const wchar_t *paletteName;

    if (!g_useEpfAssets)
        paletteName = kLegacyFramePalette;
    else if (m_frameResourceMode)
        paletteName = kTabsPalette;
    else
        paletteName = kFramePartPalette;

    DrawTileWithPalette(&m_tileContext, &m_positionedBounds, paletteName);
}

void AboveFrame::OnNotify(Pane *sender, const TaggedPaneMessage *message)
{
    (void)sender;

    if (message->tag == kPaneTagGoog)
        DestroySelf();
}
```

Draft caveats before final population:

- `LoadTile`, `SetPaneBounds`, `RegisterPaneTag`, `UnregisterPaneTag`, `DrawTileWithPalette`, and `DestroySelf` are source-facing placeholders. Existing docs establish their semantics but not these exact wrapper spellings for this body.
- The EPF tab-index adjustment is supported by generated output and resource behavior; live IDA should verify the exact high-level expression before final source commit.
- The destructor's base cleanup is implicit C++; do not paste vtable reseats or base destructor calls.

Draft factory/helper shape:

```cpp
void BuildAboveFrameBorder()
{
    if (g_useEpfAssets)
    {
        g_pAboveFrame0 = new AboveFrame(0, 0, 0);
        g_pAboveFrame1 = new AboveFrame(1, 9, 0);
        g_pAboveFrame2 = new AboveFrame(2, 9, 0x328);
        g_pDynamicAboveFrame = new AboveFrame(GetDynamicAboveFrameIndex() + 5, 0x4f, 0x328);
        return;
    }

    g_pLegacyAboveFrame0 = new AboveFrame(0, 0x0c, 0x0e);
    g_pAboveFrame0 = new AboveFrame(1, 0x0c, 0x7d);
    g_pAboveFrame2 = new AboveFrame(2, 0x0c, 0x17a);

    for (int i = 0, y = 0x5c; i < 5; ++i, y += 0x3f)
        g_pLegacyLeftFrames[i] = new AboveFrame(3, y + 6, 0x0e);

    for (int i = 0, y = 0x5c; i < 5; ++i, y += 0x3f)
        g_pLegacyRightFrames[i] = new AboveFrame(4, y, 0x1a4);
}

void ReleaseDynamicAboveFrameSlot()
{
    delete g_pDynamicAboveFrame;
}

void RecreateDynamicAboveFrameSlot()
{
    g_pDynamicAboveFrame = new AboveFrame(GetDynamicAboveFrameIndex() + 5, 0x4f, 0x328);
}
```

Factory/helper caveats before final population:

- The slot names above are descriptive placeholders. The proven data is the address family and constructor arguments.
- `GetDynamicAboveFrameIndex()` should be replaced only after `g_pGeneralPurposePanel + 0x20` receives a supported field or accessor name.
- If final reconstruction needs to model old MSVC non-throwing allocation exactly, the `new` expressions may need placement-new/null-check spelling. Do not introduce that decompiler-shaped form unless the project standard requires it.

## Coverage Replacement Text

Do not edit `by-memory/-coverage-report.md` directly for this pass. If the canonical docs are updated with this report's recommendations, replace the existing target-region rows with the following rows.

Replacement for `0000YH`:

```markdown
    - [UID:0000YH][0x004610f0-0x0046178a.AboveFrame](by-memory/0x004610f0-0x0046178a.AboveFrame.md) 0x004610f0-0x0046178a | class/mixed method island | AboveFrame : reconstructable : 86% : strong : B007 source-quality pass confirms FrameChrome-routed AboveFrame method/helper island, exact source-authored body inventory, PE-verified internal `0xcc` padding, FrameChrome resource/palette/global-slot names, and split/C++ readiness policy; keep the aggregate C++ block blank until exact method/helper children or aggregate-child routing are repaired.
```

Replacement for the refresh helper row after renaming the file:

```markdown
    - [UID:0000YI][0x004615b0-0x00461658.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md) 0x004615b0-0x00461658 | helper pair | AboveFrameRefreshHelpers : reconstructable : 86% : strong : Release helper `0x004615b0-0x004615c1` and dynamic recreate helper `0x004615d0-0x00461658`; B007 range audit fixes the stale `0x00461657` end, rejects the false `__std_parallel_algorithms_hw_threads` label, and keeps FrameChrome ownership with final helper/slot names provisional.
```

Replacement for the adjustor-thunk row:

```markdown
    - [UID:0000YJ][0x004616c8-0x004616de.AboveFrameAdjustorThunks](by-memory/0x004616c8-0x004616de.AboveFrameAdjustorThunks.md) 0x004616c8-0x004616de | adjustor thunks | AboveFrameAdjustorThunks : ignored : 86% : strong : Compiler-generated secondary/tertiary destructor adjustor thunks (`this-0xa0` and `this-0xa4`) that jump to `0x004616e0`; no handwritten C++ or emitter route, with `0x004616de-0x004616e0` PE-verified `0xcc` padding.
```

If the aggregate is split into exact child pages, insert the internal padding rows below between the new child rows:

```markdown
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00461299-0x004612a0 | padding | AboveFrame constructor/destructor alignment : ignored : 100% : strong : Local PE byte audit confirms seven `0xcc` bytes between `AboveFrame::AboveFrame` and `AboveFrame::~AboveFrame`.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00461309-0x00461310 | padding | AboveFrame destructor/factory alignment : ignored : 100% : strong : Local PE byte audit confirms seven `0xcc` bytes between `AboveFrame::~AboveFrame` and `BuildAboveFrameBorder`.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004615aa-0x004615b0 | padding | AboveFrame factory/refresh alignment : ignored : 100% : strong : Local PE byte audit confirms six `0xcc` bytes between `BuildAboveFrameBorder` and the dynamic release helper.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004615c1-0x004615d0 | padding | AboveFrame refresh-helper alignment : ignored : 100% : strong : Local PE byte audit confirms fifteen `0xcc` bytes between the dynamic release and recreate helpers.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00461658-0x00461660 | padding | AboveFrame refresh/draw alignment : ignored : 100% : strong : Local PE byte audit confirms eight `0xcc` bytes between the dynamic recreate helper and `AboveFrame::DrawFrame`.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004616af-0x004616b0 | padding | AboveFrame draw/notify alignment : ignored : 100% : strong : Local PE byte audit confirms one `0xcc` byte between `AboveFrame::DrawFrame` and `AboveFrame::OnNotify`.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004616de-0x004616e0 | padding | AboveFrame thunk/scalar-deleting alignment : ignored : 100% : strong : Local PE byte audit confirms two `0xcc` bytes between destructor adjustor thunks and scalar deleting destructor glue.
```

## Support / Coverage Replacement Summary

- `0000YH` support text should explicitly say "mixed method/helper island" and "split before C++ emission".
- `0000YI` support text should fix the half-open end to `0x00461658`.
- `0000YJ` support text should carry the current `86/90` score instead of stale `80%`, and should include the exact range.
- Existing outer padding rows `0x004610ee-0x004610f0` and `0x0046178a-0x00461790` remain valid.

## Validator / Tool Results

- IDA MCP: unavailable in this session; connection to local MCP endpoint failed.
- Local PE byte audit: completed for all internal and trailing padding spans listed above.
- Canonical docs edited: none.
- Coverage report edited: none.
- Validator: not run, because this pass creates only a B-agent research report and intentionally does not alter by-memory/by-file/by-class pages.

## Final Disposition

`0000YH` is source-recoverable but not as a single body. Keep the FrameChrome route, split exact source-authored functions, rename/repair the refresh helper page to `0x00461658`, leave adjustor thunks and scalar deleting destructor glue as no-code, and then populate first-draft C++ only on the eligible source-authored child pages.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0000YH-AboveFrame-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"0000YH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
