** TARGET-REPORT-UID:0001KC **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0001KC] TotemFrame Source-Quality Report

Agent: B005
Target: [UID:0001KC] `by-memory/0x00598cc0-0x00598ecf.TotemFrame.md`
Assignment type: report-only B-preferred source-quality / heuristic-inference pass
Report date: 2026-06-19

## Final Recommendation

Move [UID:0001KC] from `84/88` to `88/90`, keep `RECONSTRUCTABLE:TRUE`, and change the direct owner/emitter from file [UID:0000OV] to class [UID:0000F4] `TotemFrame`.

Recommended metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000F4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000F4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Reason: the executable range is a compact class method cluster. The exact vtable child [UID:0003E3] and resource-string child [UID:0003E4] already route through [UID:0000F4] because the class is the narrow true owner and clears the gate at `88/90`. Keeping [UID:0001KC] directly file-owned through [UID:0000OV] is less precise than the current vtable/resource routing. The file remains the ultimate source path (`NexusTK/ui/panels/TotemFrame.cpp`) through the class parent.

Populate first-draft source C++ for source-authored methods only: constructor, ordinary destructor, and `OnPaint`. Do not hand-author the constructor-unwind singleton clear helper, adjustor thunks, or scalar deleting destructor wrapper. Those are compiler products over the same source destructor and vtable/class declarations.

## Evidence Checked

- Re-read current `Supervisor.md`, Agent-B005 `goal.md`/`notes.md`, `by-structure.md`, `inference_research.md`, the target page, TotemFrame class/file pages, `g_pTotemFrame`, `g_pTotemFrameStorage`, `g_pOldUserStatusPane`, `OldUserStatusPane`/`UserStatusPane` pages, resource/vtable children, Pane support, Surface paint helpers, ResourceLayoutTable lookup, EPFTileContext, RectBounds layout, and current memory coverage/stat rows.
- IDA MCP endpoint was checked with a direct request; it was unavailable (`Unable to connect to the remote server`). I therefore used current exported function JSON, cached vtable text, existing IDA-backed docs, generated decompile reports as non-authoritative leads, and a direct local PE byte audit against `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- Local PE byte audit confirmed the external padding and internal seams:

```text
00598cbf-00598cc0: cc
00598d9e-00598da0: cc cc
00598dc9-00598dd0: cc cc cc cc cc cc cc
00598e3b-00598e40: cc cc cc cc cc
00598e61-00598e70: cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc
00598ecf-00598ed0: cc
```

## Boundary And Function Inventory

The broad target boundary is correct as half-open `0x00598cc0-0x00598ecf`. It starts after TimerPane alignment byte `0x00598cbf`, and `0x00598ecf-0x00598ed0` is the one-byte `0xcc` pad before TransferServerDialogPane.

Internal subrange corrections are needed where existing docs use last-byte-style endpoints:

| Correct half-open range | Current/source role | Evidence |
| --- | --- | --- |
| `0x00598cc0-0x00598d9e` | `TotemFrame::TotemFrame()` | Exported size `0xde`; direct calls from `0x005ba809` and `0x005bf933`; calls `Pane::Pane`, `InitRectBounds`, Pane attach/register helpers. |
| `0x00598d9e-0x00598da0` | padding | Two `0xcc` bytes. |
| `0x00598da0-0x00598dc9` | ordinary `TotemFrame::~TotemFrame()` cleanup body | Exported IDA size `0x29`; restores vtables, clears `g_pTotemFrame`, tail-jumps to `Pane::~Pane` at `0x00544580`; no ordinary direct callers. |
| `0x00598dc9-0x00598dd0` | padding | Seven `0xcc` bytes. |
| `0x00598dd0-0x00598e3b` | `TotemFrame::OnPaint()` | Exported size `0x6b`; vtable data xref at `0x0062e420`; calls `EPFTileContext` init, `OldUserStatusPane::GetSpiritId`, `ResourceLayoutTable::LookupLayoutEntry`, and shared `RenderTileFrame`. |
| `0x00598e3b-0x00598e40` | padding | Five `0xcc` bytes. |
| `0x00598e40-0x00598e4b` | constructor-unwind singleton clear helper | Exported size `0x0b`; only xref is unwind path `0x00609bd1`; source effect is `g_pTotemFrame = 0` during failed construction. |
| `0x00598e4b-0x00598e56` | secondary destructor adjustor thunk | Bytes `81 e9 a0 00 00 00 e9 1a 00 00 00`; vtable data xref at `0x0062e428`; adjusts `this -= 0xa0` and jumps to scalar deleting destructor. |
| `0x00598e56-0x00598e61` | tertiary destructor adjustor thunk | Bytes `81 e9 a4 00 00 00 e9 0f 00 00 00`; vtable data xref at `0x0062e458`; adjusts `this -= 0xa4` and jumps to scalar deleting destructor. |
| `0x00598e61-0x00598e70` | padding | Fifteen `0xcc` bytes. |
| `0x00598e70-0x00598ecf` | scalar deleting destructor wrapper | Exported size `0x5f`; primary vtable xref at `0x0062e3dc`; thunk callers at `0x00598e4b`/`0x00598e56`; calls `Pane::~Pane` and MemoryMan-backed `operator delete`. |

## Reachability And Call Routes

The constructor is directly reachable from the status update paths:

- `0x005ba809` inside `0x005ba4a0` / UserStatusPane status payload path.
- `0x005bf933` inside `0x005bf7c0` / OldUserStatusPane status payload path.

`OnPaint` is vtable-reached through the primary TotemFrame vtable. Cached vtable `0x0062e3dc` has slot `+0x44` pointing to `0x00598dd0`. This matches the class method identity `virtual void TotemFrame::OnPaint()`.

Destructor reachability is vtable/compiler-generated:

- Primary TotemFrame vtable base `0x0062e3dc` slot 0 points to `0x00598e70`.
- Secondary table `0x0062e428` points to adjustor `0x00598e4b`.
- Tertiary table `0x0062e458` points to adjustor `0x00598e56`.
- The ordinary cleanup body `0x00598da0-0x00598dc9` has no direct static callers in exported data, but it is the non-deleting destructor body pattern: same class vtable restore, singleton clear, and `Pane::~Pane` chain as the scalar wrapper without delete-flag logic.

`0x00598e40` is not a user-authored helper route. Its sole route is the constructor unwind record; source C++ should express the constructor/destructor ownership, not a named standalone clear function.

## Source-Quality Name And Role Decisions

| Binary/generated item | Best source-facing interpretation | Rejected alternatives |
| --- | --- | --- |
| `sub_598CC0` / generated `ctor_0x598cc0` | `TotemFrame::TotemFrame()` | Raw generated ctor name rejected because class docs, constructor callers, vtable stores, and singleton publish all prove the class constructor. |
| `sub_598DA0` | ordinary `TotemFrame::~TotemFrame()` cleanup body | Treating it as an unrelated helper is rejected by vtable restore + singleton clear + `Pane::~Pane` tail jump. |
| `virt_meth_0x598dd0` | `TotemFrame::OnPaint()` | Generated generic virtual name rejected by primary vtable slot `+0x44`, paint-only callee set, resource load, and shared draw helper use. |
| `sub_598E40` | compiler EH/unwind clear for `g_pTotemFrame` | A source-authored `ClearTotemFrameSingleton()` is rejected because the only route is constructor unwind, not ordinary code or vtable data. |
| `sub_598E4B` / `sub_598E56` | compiler adjustor thunks for secondary/tertiary destructor views | Source virtual methods are rejected: both only adjust `this` and jump to the deleting destructor. |
| `sub_598E70` / `virt_deldtor_0x598e70` | compiler scalar deleting destructor for `TotemFrame` | Do not emit as source. The source-authored destructor is `~TotemFrame()`; delete/free flag handling is compiler output. |
| generated `TextButtonExControlPane::~TextButtonExControlPane` at `0x00544580` | `Pane::~Pane()` / base pane teardown | TextButtonEx ownership is callsite/type pollution. Pane docs and vtable pages identify `0x00544580-0x00544687` as ordinary `Pane` teardown. |
| `FUN_004f4ac0` | MemoryMan-backed global `operator delete(void*)` | Feature-local delete/free helper rejected by MemoryMan docs, 2,129 direct callers, and `GetMemoryMan` -> `FreeBufferMemory` body. |
| `DAT_0069b35c` / `dword_69B35C` | `g_pTotemFrame` | Storage and global docs prove singleton name and address; no better source owner than TotemFrame. |
| `DAT_0069b4ec` / `dword_69B4EC` | `g_pOldUserStatusPane` | UserStatusPane-owned global docs account for all nine xrefs; not TotemFrame-owned storage. |
| `0x005bdc60` | `OldUserStatusPane::GetSpiritId()` | Generic getter/raw address rejected by UserStatusPane docs and decompiled use as the `TOTFRAME.EPD` frame index. Exact enum/frame mapping remains resource semantics, not a blocker for the call name. |
| `L"TOTFRAME.EPD"` | TotemFrame class-local resource filename literal | Generic frame chrome rejected by sole xref from `TotemFrame::OnPaint` and exact [UID:0003E4] class ownership. |
| `L"NPAL7.PAL"` | shared old-HUD/status palette literal consumed by TotemFrame | TotemFrame-private palette ownership rejected by ten xrefs and resource docs. |
| `0x00457a60` | `EPFTileContext` / frame draw context initialization | Caller-specific class names rejected by the shared render support aggregate. |
| `0x004d02f0` | `ResourceLayoutTable::LookupLayoutEntry` | Pane-private loader rejected by hundreds of UI/render callers and ResourceLayoutTable docs. |
| `0x004b9980` | shared Surface `RenderTileFrame` wrapper | Generated `FittingRoomDownloadControlPane::RenderTileFrame` owner is polluted; SurfacePaintHelpers documents it as broad shared render infrastructure. |
| `0x004b7c50` | `InitRectBounds` / `RectBounds::SetLTRB`-style helper | Feature-local rectangle helper rejected by RectBoundsLayout docs and broad helper use. |

## Owner / Source Placement Ranking

1. [UID:0000F4] `TotemFrame` class - best direct owner/emitter for [UID:0001KC]. The range contains only TotemFrame class methods plus compiler support for that class. The exact vtable and resource-string children already use this owner. The class clears the gate (`88/90`) and routes to [UID:0000OV].
2. [UID:0000OV] `TotemFrame.cpp` file - best final source file route, but too broad as direct owner for the memory page. It remains the generated source path `auto-generated/NexusTK/ui/panels/TotemFrame.cpp`.
3. [UID:0000P2] `UserStatusPane` / OldUserStatusPane grouping - plausible original feature neighborhood but rejected as direct owner. UserStatusPane creates/invalidates the singleton and supplies the frame index, but the code, vtables, resource literal, and singleton being cleared are TotemFrame-specific.
4. [UID:0000F4] class-only emission without first-draft method code - rejected under current rules. The class is reconstructable and the authored methods have enough source shape to emit descriptive first-draft C++.
5. Generic Pane/UI core - rejected. `Pane` owns base construction/destruction helpers, not the TotemFrame singleton, status resource, fixed bounds, or paint behavior.
6. FrameChrome or generic resource/render support - rejected. `TOTFRAME.EPD` has a single TotemFrame paint xref; `NPAL7.PAL`, `EPFTileContext`, and Surface render helpers are dependencies, not owners.
7. No-owner/non-emitting fallback - rejected. Constructor callers, vtable reachability, class/resource children, and source path are strong enough for reconstruction.

## First-Draft C++ Recommendation

Populate the formal C++ block with source-authored methods only. The helper names below are source-facing descriptive names backed by current support docs; exact original spellings of the Pane attach/register wrappers can remain annotated as inferred.

```cpp
TotemFrame::TotemFrame()
    : Pane(0)
{
    g_pTotemFrame = this;

    RectBounds bounds;
    InitRectBounds(&bounds, 435, 11, 627, 299);
    AttachToMainUiLayer(bounds, 0);
    RegisterWithPaneDispatcher(0);
}

TotemFrame::~TotemFrame()
{
    g_pTotemFrame = 0;
}

void TotemFrame::OnPaint()
{
    EPFTileContext tile;
    FrameDrawRecord drawRecord;

    tile.Initialize();

    const int frameIndex =
        static_cast<short>(g_pOldUserStatusPane->GetSpiritId());

    g_pEPFLib->LookupLayoutEntry(L"TOTFRAME.EPD", frameIndex, &tile);
    RenderTileFrame(&tile, &drawRecord, &m_bounds, 0, L"NPAL7.PAL", 0);
}
```

Notes for the supervisor when applying:

- `AttachToMainUiLayer` is the source-facing role for the `0x00544c70` call with the fixed bounds, `dword_67A740`, and `dword_69B368`; final spelling may be `Pane::InsertInLayer`, `Pane::AttachToLayer`, or an equivalent existing Pane wrapper. The behavior is not a blocker for first-draft C++ because the rectangle and source role are clear.
- `RegisterWithPaneDispatcher` is the descriptive role for `0x00544d30`. Existing Pane docs call the `0x00544d30/0x00544d70` family dispatcher helpers. Exact original spelling remains a Pane-core naming issue, not a TotemFrame ownership blocker.
- The destructor source body should not mention vtable stores or `Pane::~Pane`; C++ emits those implicitly.
- Do not emit source code for `0x00598e40`, `0x00598e4b`, `0x00598e56`, or `0x00598e70`.
- If the supervisor prefers class declaration placement on [UID:0000F4], add `virtual ~TotemFrame();` and `virtual void OnPaint();` there, with method definitions on [UID:0001KC] or the class page per current generator policy.

## Heuristic / Inference Reanalysis And Validation

### Boundary and padding

Evidence checked: local PE bytes, exported function JSON, target docs, TimerPane and TransferServerDialogPane docs, memory coverage row.

Final inference: broad range `0x00598cc0-0x00598ecf` is correct. Internal function table needs half-open cleanup: cleanup body `0x00598da0-0x00598dc9`, clear helper `0x00598e40-0x00598e4b`, first thunk `0x00598e4b-0x00598e56`, second thunk `0x00598e56-0x00598e61`. This affects score positively because it removes stale boundary ambiguity. It does not require splitting or renaming the target range.

### Raw-start / reachability

Evidence checked: exported callers/xrefs for each function, cached vtable `0062e3dc.txt`, target/class/file pages, vtable child docs.

Final inference: constructor has two ordinary code callers; `OnPaint` and scalar destructor family are vtable-routed; the ordinary cleanup body has no direct callers but matches non-deleting destructor shape; `0x00598e40` is constructor-unwind only. This supports source-authored constructor/destructor/paint C++ and no source for compiler helpers. Score should rise because "no direct caller" is now explained per body instead of left as a blocker.

### Source method names

Evidence checked: OOAnalyzer/class labels, cached vtable primary slot, `OnPaint` callees and resource xrefs, destructor body parity, class docs.

Rejected alternatives: raw names `virt_meth_0x598dd0`, `sub_598DA0`, and source-authored `ClearTotemFrameSingleton`.

Final inference: `TotemFrame::TotemFrame`, `TotemFrame::~TotemFrame`, and `TotemFrame::OnPaint` are safe first-draft source names. The clear helper and deleting destructor should be compiler-generated/no-source. This removes the old blank-C++ blocker.

### Base and delete helper names

Evidence checked: Pane file/vtable docs, PaneVtableData, previous PaneCore support text, OperatorDeleteWrapper page.

Rejected alternatives: generated `TextButtonExControlPane::~TextButtonExControlPane`, feature-local delete helper, and LObject/runtime ownership.

Final inference: `0x00544580` is `Pane::~Pane()`; `0x004f4ac0` is MemoryMan-backed `operator delete(void*)`. Source destructor C++ should not call either explicitly except via ordinary C++ inheritance/delete semantics. This improves C++ readiness and prevents polluted generated names.

### Singleton and storage names

Evidence checked: `g_pTotemFrame`, `g_pTotemFrameStorage`, current xref summaries, constructor/destructor/clear helper writes, external panel-switch/user-input deletion users.

Rejected alternatives: generic frame pointer, UserStatusPane-owned storage, and unnamed `dword_69B35C`.

Final inference: `g_pTotemFrame` is stable and belongs with TotemFrame source. Exact storage child [UID:0002VR] can remain a reconstructable/global-storage page; no split/range change needed. This supports the constructor/destructor C++ and owner route.

### Old-status dependency and frame selector

Evidence checked: `g_pOldUserStatusPane`, OldUserStatusPane aggregate, resource page, function `0x005bdc60` evidence, `OnPaint` generated/IDA decompile.

Rejected alternatives: TotemFrame-owned status state, direct DAT/resource frame table, and `GetTotemFrameIndex` as proven original spelling.

Final inference: source code should call `g_pOldUserStatusPane->GetSpiritId()` and pass the signed/short result as the `TOTFRAME.EPD` frame index. The exact mapping of spirit/totem values to resource frames is not safe to infer from this target alone; it caps resource semantics, not method-source readiness.

### Resource literals and payload ownership

Evidence checked: [UID:0003E4], [UID:0001RR], [UID:00026Q], xref counts for `TOTFRAME.EPD` and `NPAL7.PAL`.

Rejected alternatives: hand-authored C++ arrays for resource bytes, TotemFrame-private `NPAL7.PAL`, generic FrameChrome ownership.

Final inference: `TOTFRAME.EPD` should appear as a source literal in `TotemFrame::OnPaint` / class-local declaration; `NPAL7.PAL` is a shared palette literal passed by this consumer. Payload bytes stay resource-derived. This supports declaration/source text while leaving asset extraction outside the target.

### Vtable and wrapper policy

Evidence checked: [UID:0003E3], cached vtable text, scalar destructor exported JSON, target/class docs.

Rejected alternatives: hand-authored adjustor methods, hand-authored scalar deleting destructor, and source-authored clear helper.

Final inference: class declaration and virtual destructor/paint methods are source-declared; vtable bytes, adjustor thunks, constructor EH helper, and scalar deleting destructor are generated. This should be recorded explicitly so the target no longer has "formal C++ blank because wrappers exist" as a blocker.

### Owner/source-route decision

Evidence checked: target owner [UID:0000OV], class [UID:0000F4], vtable/resource children, file score/path, UserStatusPane/OldUserStatusPane docs, generic Pane/Surface support.

Rejected alternatives: direct file owner, UserStatusPane owner, generic Pane owner, Surface/resource owner, no-owner fallback.

Final inference: direct owner/emitter should be [UID:0000F4] with generated source flowing to [UID:0000OV] `NexusTK/ui/panels/TotemFrame.cpp`. This affects metadata and generated route but not the physical target split.

### Generated output state

Evidence checked: `auto-generated/NexusTK/ui/panels/TotemFrame.cpp` has length `0`; B001 validation logs report `autogen_cpp_noop 0000OV ... no assembled code for root`; re-agent snippets omit `0x00598da0`/`0x00598e40` and use polluted helper names.

Final inference: current zero-byte output is caused by missing formal C++ and old gate policy, not by lack of reconstructability. First-draft C++ should unblock non-empty output for the source-authored methods. Generated snippets are useful for call shape only and must not be copied literally.

### Remaining uncertainty and score impact

Unresolved but non-blocking:

- Exact original spellings for Pane wrapper calls `0x00544c70` and `0x00544d30`.
- Exact enum/semantic mapping from `OldUserStatusPane::GetSpiritId()` values to `TOTFRAME.EPD` frames.
- DAT/archive provenance of `TOTFRAME.EPD` and shared `NPAL7.PAL`.

Why no stronger inference is safe: these require a Pane-core naming pass or resource/status semantics pass across other consumers. They do not change target owner, emitter, range, split decision, or C++ readiness for constructor/destructor/paint. They cap the target below final `95+`, but they do not justify staying at `84/88`.

## Support-Doc Recommendations

### Target page [UID:0001KC]

Replace metadata with the block in "Final Recommendation".

Replace the current `Status` final-C++ and parent attachment bullets with:

```text
- Parent attachment: direct owner/emitter should be [UID:0000F4][TotemFrame](by-class/TotemFrame.md), with source output continuing through [UID:0000OV][TotemFrame](by-file/TotemFrame.md) / `NexusTK/ui/panels/TotemFrame.cpp`. The exact vtable and resource-string children already route through the class parent.
- Final C++: first-draft source C++ is ready for `TotemFrame::TotemFrame()`, `TotemFrame::~TotemFrame()`, and `TotemFrame::OnPaint()`. Do not hand-author `0x00598e40`, `0x00598e4b`, `0x00598e56`, or `0x00598e70`; those are constructor-unwind, adjustor-thunk, and scalar-deleting-destructor compiler output.
```

Replace the function table with:

```text
| Range | Function | Notes |
| --- | --- | --- |
| `0x00598cc0-0x00598d9e` | `TotemFrame::TotemFrame` | Constructs `Pane(0)`, publishes `g_pTotemFrame`, installs TotemFrame views, initializes fixed bounds `435,11,627,299`, and attaches/registers the pane through Pane helpers. |
| `0x00598d9e-0x00598da0` | padding | Two `0xcc` bytes before the ordinary cleanup body. |
| `0x00598da0-0x00598dc9` | `TotemFrame::~TotemFrame` ordinary cleanup body | Reinstalls local vtables, clears `g_pTotemFrame`, and tail-jumps to `Pane::~Pane` at `0x00544580`; source body is `g_pTotemFrame = 0` with implicit base destruction. |
| `0x00598dc9-0x00598dd0` | padding | Seven `0xcc` bytes before `OnPaint`. |
| `0x00598dd0-0x00598e3b` | `TotemFrame::OnPaint` | Initializes an `EPFTileContext`, reads `g_pOldUserStatusPane`, calls `OldUserStatusPane::GetSpiritId`, loads `TOTFRAME.EPD`, and renders through shared `RenderTileFrame` with `NPAL7.PAL`. |
| `0x00598e3b-0x00598e40` | padding | Five `0xcc` bytes before the constructor-unwind clear helper. |
| `0x00598e40-0x00598e4b` | constructor-unwind singleton clear helper | Clears `g_pTotemFrame`; only routed from constructor EH/unwind metadata, so no source helper should be emitted. |
| `0x00598e4b-0x00598e56` | secondary destructor adjustor thunk | Adjusts `this` by `-0xa0` and forwards to `0x00598e70`; compiler-generated. |
| `0x00598e56-0x00598e61` | tertiary destructor adjustor thunk | Adjusts `this` by `-0xa4` and forwards to `0x00598e70`; compiler-generated. |
| `0x00598e61-0x00598e70` | padding | Fifteen `0xcc` bytes before the scalar deleting destructor. |
| `0x00598e70-0x00598ecf` | scalar deleting destructor | Compiler wrapper over `TotemFrame::~TotemFrame()` plus optional MemoryMan-backed `operator delete`; do not hand-author. |
```

Add the first-draft C++ block from this report, or equivalent source with the same three source-authored methods and no helper/wrapper bodies.

### Class page [UID:0000F4]

Update method ranges to the corrected half-open values above. Replace stale "No C++ below 95/95" language with:

```text
First-draft source C++ is now ready for the constructor, ordinary destructor, and `OnPaint` via [UID:0001KC]. The constructor-unwind clear helper, adjustor thunks, and scalar deleting destructor remain compiler-generated and should not be emitted as separate methods.
```

If the class page carries declarations, add:

```cpp
class TotemFrame : public Pane {
public:
    TotemFrame();
    virtual ~TotemFrame();
    virtual void OnPaint();
};
```

### File page [UID:0000OV]

Keep `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/"`. Update the method-family table with the corrected half-open ranges and add:

```text
B005 source-quality pass recommends direct child owner/emitter routing through [UID:0000F4][TotemFrame](by-class/TotemFrame.md); this file remains the final source path. The previous blank generated output is a formal-C++ omission, not evidence against reconstructability.
```

### Resource/support pages

No required score change for [UID:0001RR], [UID:0003E4], [UID:0003E3], [UID:0000SK], [UID:0002VR], or [UID:0000RV]. Optional incorporation text for [UID:0001RR]:

```text
B005 [UID:0001KC] recheck validates that unresolved DAT/archive provenance and exact spirit-to-frame mapping do not block first-draft `TotemFrame::OnPaint` C++; they remain resource-semantic follow-ups only. The source method should preserve `OldUserStatusPane::GetSpiritId()` as the frame selector for `TOTFRAME.EPD` and pass shared `NPAL7.PAL` to the render helper.
```

## Coverage Row Recommendation

Replace the [UID:0001KC] row in `by-memory/-coverage-report.md` under the TimerPane/TotemFrame/TransferServer section with:

```text
    - [UID:0001KC][0x00598cc0-0x00598ecf.TotemFrame](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md) 0x00598cc0-0x00598ecf | class-method-cluster | TotemFrame : reconstructable : 88% : very-strong : B005 source-quality pass keeps the exact half-open TotemFrame executable range, confirms predecessor/successor `0xcc` padding at `0x00598cbf` and `0x00598ecf`, corrects internal half-open subranges for the cleanup body, clear helper, adjustor thunks, and padding, routes direct owner/emitter to [UID:0000F4][TotemFrame](by-class/TotemFrame.md) with source output through [UID:0000OV][TotemFrame](by-file/TotemFrame.md), resolves generated labels to `Pane::~Pane`, MemoryMan-backed `operator delete`, `g_pTotemFrame`, `g_pOldUserStatusPane`, `OldUserStatusPane::GetSpiritId`, `ResourceLayoutTable::LookupLayoutEntry`, and shared `RenderTileFrame`, and recommends first-draft C++ for constructor/destructor/OnPaint while keeping the constructor-unwind clear helper, adjustor thunks, and scalar deleting destructor compiler-generated.
```

Placement context: replace the existing row between the `TimerPane to TotemFrame alignment` padding row and the `TotemFrame to TransferServerDialogPane alignment` padding row.

## Score Rationale

Completion `88`: exact broad boundary, internal half-open corrections, function inventory, byte padding, direct/vtable reachability, helper source names, singleton/resource/status dependencies, owner/emitter route, generated-output policy, first-draft C++ recommendation, and support/coverage text are now resolved. It stays below `95+` because Pane attach/register original spellings and frame-id resource semantics remain broader support work.

Confidence `90`: current exported function data, existing IDA-backed docs, cached vtable data, resource/global pages, and local PE bytes all agree. Confidence is not higher because live IDA MCP was unavailable during this pass and the Pane wrapper names remain inferred/descriptive.

## Validation Notes

Commands/evidence checks used:

- Direct MCP endpoint request: failed to connect; recorded as MCP unavailable.

> The two removed literal PowerShell commands are preserved only in [0001KC-TotemFrame-source-quality-removed.md](0001KC-TotemFrame-source-quality-removed.md). The archive is non-authoritative and must not be executed.
- `Get-Content` on target, class/file/global/resource/support docs.
- `rg` across project documentation for helper names and previous reports/logs.
- `Get-Content` on exported function JSON for `0x00598cc0`, `0x00598da0`, `0x00598dd0`, `0x00598e40`, `0x00598e4b`, `0x00598e56`, and `0x00598e70`.
- `Get-Content hooks-generation/cached/vtable/0062e3dc.txt`.
- PowerShell PE byte audit for `0x00598cbf`, internal seams, and `0x00598ecf`.
- `Get-Item auto-generated/NexusTK/ui/panels/TotemFrame.cpp` confirmed current generated output length `0`.

No repository validation command was run because this is report-only and no by-* documentation or coverage file was edited.

## Changed Files

- Added this report only: `tools/leaser/Agents/Agent-B005/research/0001KC-TotemFrame-source-quality.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0001KC-TotemFrame-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"0001KC"} -->
<!-- {"agent":"B005","command_id":"000000023047","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001KC-TotemFrame-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/0001KC-TotemFrame-source-quality.md","timestamp":"2026-08-13T02:36:38-04:00","uid":"0001KC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
