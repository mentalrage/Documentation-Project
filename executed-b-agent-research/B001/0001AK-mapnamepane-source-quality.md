** TARGET-REPORT-UID:0001AK **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001 Research Report: [UID:0001AK] MapNamePane Source Quality

Assignment: `B001-goal2-mapnamepane-source-quality-0001AK-20260617`

Primary target: [UID:0001AK] `by-memory/0x005031f0-0x005038fd.MapNamePane.md`

Current state: `82/88`, owner/emitter [UID:0000L2] `MapNamePane`, `RECONSTRUCTABLE:TRUE`

Report-only constraint honored: no by-* documentation, generated report, generated source, IDA DB, source file, or `by-memory/-coverage-report.md` edits were made.

## Executive Recommendation

Reclassify [UID:0001AK] from a reconstructable/emitting aggregate to a non-emitting MapNamePane method split/index:

- Recommended [UID:0001AK] score: `88/91`.
- Recommended direct owner: [UID:00007P] `MapNamePane` class, not the [UID:0000L2] file page. The file remains the source module route for exact children.
- Recommended `RECONSTRUCTABLE:FALSE`.
- Recommended `EMITTER_UIDS:` blank.
- Recommended final C++: blank.

Reason: the page is not one source-emittable method and is not a contiguous class-owned executable range. It inventories MapNamePane methods, compiler destructor adjustor thunks, a scalar deleting destructor, and holes that cross MiniMapButtonPane-owned executable code. The current emitting aggregate pollutes generated `NexusTK/map/MapNamePane.cpp` with a range shape that no C++ source unit could directly contain. Source-bearing reconstruction should move to exact child method pages.

The best structural repair is to create exact MapNamePane child pages, then keep [UID:0001AK] as the non-emitting parent/index over those pages. Under this assignment's explicit report-only constraint I did not create child pages; exact proposed child ranges and coverage rows are included below for supervisor execution.

## Evidence Standards Used

Evidence checked:

- Existing docs: target [UID:0001AK], mixed island [UID:0001AL], [UID:00007P] `MapNamePane`, [UID:0000L2] `MapNamePane`, [UID:0000L3] `MapPane`, [UID:00008B] `MiniMapButtonPane`, [UID:0001AM], [UID:0001AN], [UID:00025R], [UID:0003BZ], [UID:0003IL], [UID:0002XC], [UID:0002XD], [UID:00029X], [UID:0000SW], and packet/source support docs.
- Current generated state: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, `project-level/-unresolved.md`, and current `by-memory/-coverage-report.md` rows.
- IDA MCP live facts from active read-only IDB session `b003_00018a_ime_comp_20260617`: function starts/sizes, decompilation, xrefs, vtable references, singleton refs, padding bytes, and adjacent function boundaries.
- `tools/int_convert.py` decimal checks for constants used in the recommendation.

Generated Wave2/Wave3 C++ was not used as naming authority. Existing generated output was treated only as generated-state context.

## IDA MCP Facts

Function/range facts:

- `0x005031f0` `sub_5031F0`, size `0xd3`: MapNamePane constructor body, half-open `0x005031f0-0x005032c3`.
- `0x005032d0` `sub_5032D0`, size `0x7d`: ordinary/non-deleting destructor body, half-open `0x005032d0-0x0050334d`.
- `0x00503350` `sub_503350`, size `0x14f`: render/on-paint virtual body, half-open `0x00503350-0x0050349f`.
- `0x005034a0` `sub_5034A0`, size `0xd4`: secondary-vtable map-name update packet handler, half-open `0x005034a0-0x00503574`.
- `0x005037f0` `sub_5037F0`, size `0x0b`: `g_pMapNamePane = 0` helper, half-open `0x005037f0-0x005037fb`.
- `0x0050380b` and `0x00503816`: two compiler adjustor thunks for destructor dispatch from `+0xa0` and `+0xa4` subobjects.
- `0x00503840` `sub_503840`, size `0xbe`: scalar deleting destructor, half-open `0x00503840-0x005038fe`.
- MiniMapButtonPane interleaves inside the physical island at `0x00503580`, `0x00503620`, `0x00503650`, `0x005036a0`, `0x00503800`, `0x00503821`, `0x0050382c`, and `0x00503900`. These ranges are not MapNamePane-owned.

Data/table/padding facts:

- MapNamePane vtable data at `0x0061e5b4` stores `0x00503840` as primary destructor, `0x00503350` in the render slot, `0x0050380b` in a secondary destructor slot, `0x005034a0` in the secondary update/event slot, and `0x00503816` in a tertiary destructor slot.
- Constructor/destructor/scalar destructor write the three MapNamePane vptrs at `this+0x0`, `this+0xa0`, and `this+0xa4`.
- Constructor initializes a resource/context object at `this+0x1f8`, clears the wide display buffer at `this+0xf8`, loads `MAPNAME.EPF` when `g_useEpfAssets` is enabled, and stores a `9X11FONT.BIN`/slot `0x63` font or glyph table at `this+0x220`.
- Destructor and scalar deleting destructor free/release the pointer at `this+0x220`, clear `g_pMapNamePane`, and tail into base Pane cleanup.
- Padding was confirmed at `0x0050349f-0x005034a0`, `0x00503574-0x00503580`, `0x005037fb-0x00503800`, `0x00503837-0x00503840`, and `0x005038fe-0x00503900`. The broader island also has trailing padding before `0x00503960`.
- Decimal constants verified with `tools/int_convert.py`: `0xad` is 173, `0x80` is 128, `0x15` is 21, `0x63` is 99, `0xf8` is 248, `0x1f8` is 504, `0x220` is 544, `0xa0` is 160, and `0xa4` is 164.

Xref facts:

- Constructor `0x005031f0` has direct call sites at `0x004f8051` and `0x004f8695` inside `InitializeMainUiGraph`.
- Render `0x00503350` and update handler `0x005034a0` are vtable-only through `0x0061e5f8` and `0x0061e610`.
- Adjustor thunks `0x0050380b` and `0x00503816` are vtable-only through `0x0061e600` and `0x0061e630`.
- Scalar deleting destructor `0x00503840` is referenced by the primary vtable and the two adjustor thunks.
- `g_pMapNamePane` at `0x0069b4b4` is written in constructor, ordinary destructor, clear helper, and scalar deleting destructor; it is externally consumed by MapPane teardown logic around `0x00504a43`.
- `MAPNAME.EPF` at `0x0061e6c0` has the expected constructor xref at `0x0050328d`.

Negative IDA facts:

- No ordinary direct call site was found for the render, update handler, adjustor thunks, or scalar deleting destructor beyond vtable/thunk routing.
- The MiniMapButtonPane functions inside the same physical island have their own constructor caller, singleton clear route, vtables, and owner docs; MapNamePane does not own those bytes.
- No evidence was found that MapPane.cpp directly implements the MapNamePane class methods; MapPane teardown reads the global pointer as a consumer, not as an owning constructor/destructor route.

## Function / Child Inventory

| Range / Item | Current UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005031f0-0x005038fd` legacy target | [UID:0001AK] `MapNamePane.md` | Current broad MapNamePane aggregate | Recommend `FALSE` | [UID:00007P] | `88/91` | Reclassify to non-emitting split/index |
| `0x005031f0-0x005032c3` | New child needed | Constructor | `TRUE`, blank C++ for now | [UID:00007P] | `86/90` | Create exact page |
| `0x005032d0-0x0050334d` | New child needed | Ordinary destructor | `TRUE`, blank C++ for now | [UID:00007P] | `86/90` | Create exact page |
| `0x00503350-0x0050349f` | New child needed | Render/on-paint virtual | `TRUE`, blank C++ for now | [UID:00007P] | `86/89` | Create exact page |
| `0x005034a0-0x00503574` | New child needed | Map-name update packet handler | `TRUE`, blank C++ for now | [UID:00007P] | `87/90` | Create exact page |
| `0x005037f0-0x005037fb` | New child needed | Singleton clear helper | `TRUE`, blank C++ for now | [UID:00007P] | `85/88` | Create exact page |
| `0x0050380b-0x00503821` | New child or ignored row needed | Destructor adjustor thunks | `FALSE` | [UID:00007P] | `85/90` | Non-emitting compiler-generated thunks |
| `0x00503840-0x005038fe` | New child needed | Scalar deleting destructor | `FALSE` if ordinary destructor child exists | [UID:00007P] | `86/90` | Non-emitting compiler-generated wrapper |
| MiniMapButtonPane ranges inside physical island | Existing [UID:0001AM]/[UID:0001AN] plus class docs | Neighbor owner | N/A | [UID:00008B]/[UID:0000LE] | Existing | Exclude from [UID:0001AK] ownership |

The current target filename uses a legacy last-byte-looking end of `0x005038fd`; IDA function-size evidence shows the scalar deleting destructor's half-open end is `0x005038fe`. I recommend retaining the current path until supervisor decides whether to rename legacy range-index pages, but the body should state the half-open executable child ranges explicitly.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005031f0` | Calls from `InitializeMainUiGraph` at `0x004f8051`, `0x004f8695` | Direct construction of MapNamePane during main UI graph setup |
| `0x00503350` | Data xref from vtable slot `0x0061e5f8` | MapNamePane render/on-paint virtual |
| `0x005034a0` | Data xref from secondary vtable slot `0x0061e610` | MapNamePane update/event/packet handler virtual |
| `0x005037f0` | Code xref from constructor-associated cleanup metadata path | Singleton-clear helper route |
| `0x0050380b` | Data xref from `0x0061e600`; calls `0x00503840(this-0xa0, flag)` | Compiler adjustor thunk |
| `0x00503816` | Data xref from `0x0061e630`; calls `0x00503840(this-0xa4, flag)` | Compiler adjustor thunk |
| `0x00503840` | Primary vtable xref `0x0061e5b4`; thunk callers | Scalar deleting destructor |
| `0x0069b4b4` | Constructor/destructor/helper/scalar destructor writes; MapPane teardown read at `0x00504a43` | Global singleton pointer `g_pMapNamePane` |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:0001AK] already warns that this is a legacy class aggregate and not a contiguous class-owned range.
- [UID:0001AL] already models the broader `MapNameAndMiniMapButtonPanes` physical island as a mixed/non-emitting inventory.
- [UID:00007P] `MapNamePane` has the correct high-level constructor/destructor/render/update/singleton/vtable evidence and already records the `+0xf8`, `+0x1f8`, and `+0x220` roles.
- [UID:0000L2] `MapNamePane` is the proper source module route for MapNamePane class content.
- [UID:00008B], [UID:0001AM], and [UID:0001AN] independently document MiniMapButtonPane ownership inside the same island.
- [UID:0002XC]/[UID:0002XD] support `g_pMapNamePane`; [UID:0003IL] supports `MAPNAME.EPF`; [UID:0000SW] supports `g_useEpfAssets`.

Existing docs that are stale, incomplete, or contradicted:

- [UID:0001AK] remains `RECONSTRUCTABLE:TRUE` with emitter [UID:0000L2] despite being an aggregate/index and crossing MiniMapButtonPane-owned code.
- No exact MapNamePane executable child pages exist for the constructor, ordinary destructor, render, update handler, singleton helper, adjustor thunks, or scalar deleting destructor.
- The target and support docs still use generated names such as `sub_5031F0`, `sub_5032D0`, `sub_503350`, and `sub_5034A0` as unresolved labels. These now have defensible source-facing/descriptive names.
- Source placement is still phrased as `MapNamePane.cpp` versus private `MapPane.cpp`; current evidence supports `NexusTK/map/MapNamePane.cpp` as the preferred route.
- The target's broad range text should explicitly list MiniMapButtonPane exclusions, padding gaps, and the `0x00503837-0x00503840` padding before the MapName scalar deleting destructor.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` still treats [UID:0001AK] as reconstructable and emits to `auto-generated/NexusTK/map/MapNamePane.cpp`.
- The generated `MapNamePane.cpp` output is empty because the formal C++ block is blank, but the route is still structurally wrong for a broad aggregate.
- `by-memory/-coverage-report.md` has a stale [UID:0001AK] row that calls it reconstructable at `82%`. It should be replaced by the non-emitting split-index row below.

## Ranked Ownership Analysis

### 1. [UID:00007P] `MapNamePane` class

Evidence for:

- Constructor, ordinary destructor, render virtual, secondary update virtual, clear helper, vtable adjustors, scalar deleting destructor, vtable data, `g_pMapNamePane`, and `MAPNAME.EPF` references all point to the MapNamePane class.
- The `this+0xa0` and `this+0xa4` vptr restores and adjustor thunks are class-layout evidence, not file-level evidence.
- Exact child methods would naturally belong to the class and route outward to the source file.

Evidence against:

- The physical address interval includes non-MapName MiniMapButtonPane functions and padding.

Decision:

- Best direct owner for the [UID:0001AK] semantic index and for exact MapNamePane child pages. The physical mixed interval problem is handled by making [UID:0001AK] non-emitting and by excluding MiniMapButtonPane spans.

### 2. [UID:0000L2] `MapNamePane` source file

Evidence for:

- Existing by-file page exists and proposed source tree has `NexusTK/map/MapNamePane.cpp`.
- MapNamePane-specific resources, singleton, vtables, and method family are narrow enough for a standalone file.

Evidence against:

- A by-file page is not the direct semantic owner of individual class methods when a class page exists and clears the owner gate.
- The current aggregate using the file as emitter creates an invalid source-emitting range.

Decision:

- Keep [UID:0000L2] as the source-file/emitter route for exact class children after split, but do not keep it as the direct owner/emitter for [UID:0001AK] itself.

### 3. [UID:0000L3] `MapPane` / private `MapPane.cpp` companion implementation

Evidence for:

- `MapPane.cpp` is the central map UI source family and consumes `g_pMapNamePane` in teardown.
- Main UI graph constructs both MapNamePane and surrounding map UI panes.

Evidence against:

- The MapPane teardown xref is a consumer/removal route, not a class implementation proof.
- `MapNamePane` has its own by-file page, resource literal, singleton global, vtable data, and class page.
- Constructor and vtable evidence do not point to a MapPane class method or MapPane-owned embedded field.

Decision:

- Rejected as direct source owner. It remains a related consumer/parent UI context only.

### 4. [UID:00008B]/[UID:0000LE] `MiniMapButtonPane` / `MiniMap`

Evidence for:

- MiniMapButtonPane functions are interleaved inside the same physical island.

Evidence against:

- MiniMapButtonPane has its own constructor caller, singleton clear helper, vtable/thunk/scalar destructor cluster, and existing docs.
- Its ranges are separated by IDA function starts and padding from MapNamePane ranges.

Decision:

- Rejected for MapNamePane ownership; retained as mandatory exclusion/boundary evidence.

## Heuristic / Inference Reanalysis And Validation

Aggregate versus exact children:

- Best inference: [UID:0001AK] should be a non-emitting split/index, not an emitting reconstruction unit. Exact source-bearing behavior belongs in child pages for constructor/destructor/render/update/helper methods.
- Evidence checked: IDA function starts/sizes, mixed MiniMapButtonPane function starts inside the physical island, vtable slots, current [UID:0001AL] split index, coverage/generation state.
- Rejected alternative: keep [UID:0001AK] reconstructable/emitting as a class aggregate. Rejected because it would combine multiple methods, compiler wrappers, and holes over another class's code into one C++ output block.
- Score/source impact: raise [UID:0001AK] documentation quality to `88/91`, but set `RECONSTRUCTABLE:FALSE` and blank emitters. Child pages can carry reconstructable method evidence later.

MiniMapButtonPane boundary:

- Best inference: MapNamePane owns only the seven MapName-specific starts listed above; MiniMapButtonPane begins at `0x00503580`, has its own local methods through `0x00503900`, and must stay under [UID:00008B]/[UID:0000LE].
- Evidence checked: IDA function starts, constructor caller at `0x00503580`, MiniMap singleton helper at `0x00503800`, MiniMap destructor thunks at `0x00503821`/`0x0050382c`, existing [UID:0001AM]/[UID:0001AN] docs, padding bytes.
- Rejected alternative: fold the whole physical island into MapNamePane because the legacy target range spans it. Rejected by distinct constructor/vtable/global evidence.
- Score/source impact: requires split/index treatment and explicit exclusion notes; no MapNamePane final C++ until exact children exist.

Constructor name/signature:

- Best source-facing name/signature: `MapNamePane::MapNamePane()`.
- Evidence checked: direct calls from `InitializeMainUiGraph`, base init call, singleton publish, vptr writes, resource-field init, display-buffer clear.
- Rejected alternatives: generated `sub_5031F0`; file-level free function; MapPane factory body. These lose class constructor evidence.
- Impact: proposed exact child `MapNamePaneConstructor`, `86/90`, class-owned.

Ordinary destructor and scalar deleting destructor:

- Best source-facing destructor: `MapNamePane::~MapNamePane()` represented by `0x005032d0`; `0x00503840` is a compiler-generated scalar deleting destructor wrapper.
- Evidence checked: duplicate cleanup in both bodies, delete-flag test in `0x00503840`, vtable primary destructor slot, adjustor thunk callers, release of `this+0x220`, singleton clear, base Pane cleanup call.
- Rejected alternatives: model only scalar deleting destructor as the source destructor; hand-emit scalar deleting destructor C++. Rejected because source only defines the ordinary destructor; compiler emits delete wrapper/thunks.
- Impact: exact ordinary destructor can be reconstructable, but scalar deleting destructor should be non-emitting/compiler-generated once the ordinary destructor child exists.

Render method name/signature:

- Best source-facing/descriptive name: `MapNamePane::OnPaint()` for the virtual slot, with `DrawMapName` or `RenderMapName` acceptable as behavior wording in notes. Proposed child filename: `MapNamePaneOnPaint`.
- Evidence checked: vtable render slot, no ordinary direct callers, EPF and fallback drawing paths, text measurement, centered X/Y calculation, palette colors, use of pane rectangle fields.
- Rejected alternatives: standalone helper `RenderMapName` as final source method, because the call route is virtual pane paint/render dispatch; generic `sub_503350` should be retired from source-facing docs.
- Impact: source placement remains class/file route; field/helper names are strong enough for documentation but not enough for final C++ yet.

Update handler, opcode `0x15`, and packet layout:

- Best source-facing/descriptive name: `MapNamePane::HandleMapNameUpdatePacket` or `MapNamePane::OnMapNameUpdate`; proposed child filename: `MapNamePaneHandleMapNameUpdatePacket`.
- Best inferred signature shape: secondary-interface virtual receiving an event/update object whose payload pointer is at `event+12`; decompiler shows adjusted `this` at the `+0xa0` subobject, so the source-facing method should be written as a MapNamePane method and not as a raw `this+0xa0` free function.
- Packet semantics: payload byte `0` must equal `0x15` (21). Payload byte `9` is the byte length of the map name, and name bytes begin at payload byte `10`. The handler copies that many bytes into a local `char[256]`, NUL terminates, converts with `MultiByteToWideChar(CP_ACP=0, flags=0)` into the wide display buffer, then ellipsizes/clamps to width `0xad` (173) and capacity `0x80` (128 wide chars) with `L"..."`.
- Return semantics: returns `0` always, including when opcode does not match. The return is not "handled true"; it is more likely a continue/not-consumed result for this secondary interface.
- Evidence checked: decompilation, `this-80` word adjustment back to the primary object, redraw/invalidate vtable call using the primary object and rectangle pointer, constants verified with `int_convert.py`, no direct callers beyond vtable.
- Rejected alternatives: treating `0x15` as the global `MapServerPacketOpcode` effect handler without qualification; treating conversion as UTF-8; treating the handler as a generic FittingRoom/TextEdit/InputMan routine. Rejected because the body writes only the MapNamePane display buffer and uses CP_ACP, while the central MapPane opcode enum documents a separate dispatcher context.
- Impact: enough to name and score the child at `87/90`; exact event/payload type names remain inferred and should block formal C++.

Field/type/global names:

- `g_pMapNamePane` is already a strong global name for `0x0069b4b4`.
- `g_useEpfAssets` is the best global name for `byte_66DA97`; reject narrower names such as `g_useMapNameResources` because [UID:0000SW] documents a process-wide EPF/current-layout selector.
- `this+0xf8`: best field name `m_mapNameText` or `m_displayName`; recommend `wchar_t m_mapNameText[128]`. Evidence: constructor clears first wchar, update writes converted name there, render scans/measures/draws it.
- `this+0x1f8`: best field name `m_mapNameEpfContext` or `m_mapNameResourceContext`; recommend `m_mapNameEpfContext`. Evidence: initialized by resource-context helper, receives `MAPNAME.EPF`, and participates in render resource lookup.
- `this+0x208`/near `this+0x1f8`: likely `m_mapNameLookupBuffer` or a resource-frame scratch buffer used by the EPF draw path. Evidence is render-only, so keep descriptive/inferred.
- `this+0x220`: best field name `m_mapNameGlyphTable` or `m_mapNameFont`; recommend `m_mapNameGlyphTable` with note that it is loaded from `9X11FONT.BIN` slot 99 and released in destructors. Evidence is constructor load, raw glyph renderer sibling reports, and destructor release.
- Remaining blocker: exact concrete C++ types for the EPF context, glyph table, and event/update object are still helper-family inferred. This should not block ownership or score over `85/85`, but it should block formal C++.

Helper names:

- `sub_4BA9A0`: inferred text-width measurement helper for wide/glyph text.
- `sub_4BAB70`: inferred wide/glyph text draw helper.
- `sub_4B9600`/`sub_4B9680`: inferred draw-position and color/palette setup helpers.
- `sub_4B9980`: inferred EPF/resource-frame selection or setup helper for MapNamePane art.
- `sub_4BA820`: inferred `EllipsizeWideTextToPixelWidth`/`ClampWideTextToPixelWidth`.
- `sub_516220`: byte-copy helper.
- Evidence checked: direct argument roles inside render/update. Exact original names are not provable from current docs/IDA, but these descriptive roles are strong enough to replace vague `sub_` blocker text in support docs.

Source placement:

- Best inference: keep standalone `NexusTK/map/MapNamePane.cpp` ([UID:0000L2]) as the source module route for exact class children.
- Evidence checked: existing by-file page, proposed source tree, MapNamePane-specific global/resource/vtables, narrow method family, MapPane only consuming the singleton during teardown.
- Rejected alternatives: private `MapPane.cpp` implementation and generic UI/Input/Text placement. Rejected because the evidence is class/resource-specific and there is no MapPane member-field ownership route.
- Impact: support docs should state `MapNamePane.cpp` is now preferred, not merely unresolved; [UID:0000L2] can remain the file route, but [UID:0001AK] itself should not emit.

Generated-output pollution:

- Best inference: current [UID:0001AK] should not drive any generated C++ output. Generated output being empty today is not a sufficient safety argument, because the metadata route is still wrong and future formal C++ insertion would be applied to a broad aggregate.
- Evidence checked: current autogen route and blank output, by-structure final C++ gate, split-index precedent.
- Impact: blank `EMITTER_UIDS` and final C++ blank for [UID:0001AK].

Remaining blockers:

- No ownership blocker remains for MapNamePane versus MiniMapButtonPane, MapPane, or file placement.
- No range blocker remains for exact child starts/ends; only the legacy parent filename end-style should be handled conservatively.
- Formal C++ remains blocked by missing exact child pages and unresolved concrete helper/interface/resource types. This affects only C++ readiness, not the split/index recommendation or the `85/85+` documentation score.

## Proposed Exact Child Pages

If the supervisor executes the split, I recommend these pages:

1. `by-memory/0x005031f0-0x005032c3.MapNamePaneConstructor.md`
   - Owner: [UID:00007P] `MapNamePane`
   - Emitter route: [UID:00007P] to [UID:0000L2]
   - Score: `86/90`
   - C++: blank for now

2. `by-memory/0x005032d0-0x0050334d.MapNamePaneNonDeletingDestructor.md`
   - Owner: [UID:00007P]
   - Emitter route: [UID:00007P] to [UID:0000L2]
   - Score: `86/90`
   - C++: blank for now

3. `by-memory/0x00503350-0x0050349f.MapNamePaneOnPaint.md`
   - Owner: [UID:00007P]
   - Emitter route: [UID:00007P] to [UID:0000L2]
   - Score: `86/89`
   - C++: blank for now

4. `by-memory/0x005034a0-0x00503574.MapNamePaneHandleMapNameUpdatePacket.md`
   - Owner: [UID:00007P]
   - Emitter route: [UID:00007P] to [UID:0000L2]
   - Score: `87/90`
   - C++: blank for now

5. `by-memory/0x005037f0-0x005037fb.MapNamePaneClearSingleton.md`
   - Owner: [UID:00007P]
   - Emitter route: [UID:00007P] to [UID:0000L2] only if the project models static cleanup helpers as emitted; otherwise blank emitter is acceptable
   - Score: `85/88`
   - C++: blank for now

6. `by-memory/0x0050380b-0x00503821.MapNamePaneDestructorAdjustorThunks.md`
   - Owner: [UID:00007P]
   - `RECONSTRUCTABLE:FALSE`
   - Emitter: blank
   - Score: `85/90`
   - Reason: compiler-generated thunks from secondary/tertiary vtable slots to scalar deleting destructor.

7. `by-memory/0x00503840-0x005038fe.MapNamePaneScalarDeletingDestructor.md`
   - Owner: [UID:00007P]
   - `RECONSTRUCTABLE:FALSE` once ordinary destructor child exists
   - Emitter: blank
   - Score: `86/90`
   - Reason: compiler-generated scalar deleting destructor wrapper; source destructor is `0x005032d0`.

Ignored padding rows should also be added for the confirmed gaps if the split is executed and the memory-range report requires exact coverage for them.

## First-Draft C++ Recommendation

Do not populate formal C++ for [UID:0001AK].

Reason: [UID:0001AK] should become `RECONSTRUCTABLE:FALSE` and non-emitting. It is a split/index over several functions, compiler wrappers, and holes crossing MiniMapButtonPane bytes; it is not a valid final source C++ unit.

Also do not populate formal C++ for proposed exact children in the first supervisor pass. Although several child methods can clear `85/85`, exact child pages do not yet exist and concrete types for the event/update object, secondary interface, EPF resource context, glyph/font table, and render helper APIs remain descriptive/inferred. The correct next source-facing step is to split and document exact children with blank C++ blocks, then revisit method C++ after shared UI/render/resource types are stabilized.

## Support Docs To Update

Recommended support-doc changes:

- [UID:0001AK] target:
  - Change to `COMPLETION:88`, `CONFIDENCE:91`.
  - Change `CANONICAL_OWNER` to [UID:00007P] if the schema allows class owner for split indexes; otherwise leave [UID:0000L2] only as file route in body text.
  - Change `RECONSTRUCTABLE:FALSE`.
  - Clear `EMITTER_UIDS`.
  - Add exact child inventory and MiniMapButtonPane exclusions.
  - Replace unresolved generated names with the descriptive names above.
- [UID:00007P] `MapNamePane`:
  - Add source-facing method names/signatures and packet/field inference.
  - State that `0x005034a0` is a secondary-vtable map-name update packet handler with adjusted `this`.
  - State that `0x005032d0` is the ordinary destructor and `0x00503840` is compiler-generated scalar deleting destructor evidence.
- [UID:0000L2] `MapNamePane`:
  - Resolve source placement to preferred `NexusTK/map/MapNamePane.cpp`.
  - Note that [UID:0001AK] is non-emitting and exact children should emit through this source route only after type readiness.
- [UID:0001AL] `MapNameAndMiniMapButtonPanes`:
  - Ensure it links the new exact MapNamePane child pages after creation and keeps MiniMapButtonPane exclusions.
- `by-memory/-ignored.md`:
  - Add padding rows and compiler-thunk rows only if the supervisor chooses ignored-ledger treatment for thunk/padding ranges.

## Supervisor-Owned Coverage Rows

Do not edit `by-memory/-coverage-report.md` directly from this report. Suggested replacement rows are below.

Replace the existing [UID:0001AK] row with:

```text
    - [UID:0001AK][0x005031f0-0x005038fd.MapNamePane](by-memory/0x005031f0-0x005038fd.MapNamePane.md) 0x005031f0-0x005038fd | class split index | MapNamePane : ignored : 88% : very-strong : Reviewed non-emitting MapNamePane executable-method split index; 2026-06-17 B001 live IDA rechecked constructor, ordinary destructor, render/on-paint virtual, secondary-vtable map-name update packet handler, singleton-clear helper, compiler destructor adjustor thunks, scalar deleting destructor, vtable/global/resource refs, opcode 0x15 payload conversion/clamp behavior, and MiniMapButtonPane exclusions. Exact source-bearing child pages are recommended before any method C++ emission.
```

Optional stale-row replacement for [UID:0001AL] if supervisor updates the broader island row at the same time:

```text
    - [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md) 0x005031f0-0x0050395f | mixed split index | MapNameAndMiniMapButtonPanes : ignored : 86% : very-strong : Non-emitting split inventory over interleaved MapNamePane and MiniMapButtonPane executable islands; B001 2026-06-17 rechecked MapNamePane child boundaries, MiniMapButtonPane exclusions, singleton/vtable routes, and internal padding. Remains an index only, not a source-emitting owner.
```

If supervisor creates the proposed children, insert rows immediately after [UID:0001AK]. Replace `<NEW:...>` placeholders with the validator-assigned UIDs:

```text
        - [UID:<NEW:MapNamePaneConstructor>][0x005031f0-0x005032c3.MapNamePaneConstructor](by-memory/0x005031f0-0x005032c3.MapNamePaneConstructor.md) 0x005031f0-0x005032c3 | constructor | MapNamePaneConstructor : reconstructable : 86% : strong : Exact MapNamePane constructor; live IDA confirms InitializeMainUiGraph callers, Pane base init, g_pMapNamePane publish, vtable installs at +0/+0xa0/+0xa4, resource context init at +0x1f8, display buffer clear at +0xf8, and EPF/font load gate through g_useEpfAssets.
        - [UID:<NEW:MapNamePaneNonDeletingDestructor>][0x005032d0-0x0050334d.MapNamePaneNonDeletingDestructor](by-memory/0x005032d0-0x0050334d.MapNamePaneNonDeletingDestructor.md) 0x005032d0-0x0050334d | destructor | MapNamePaneNonDeletingDestructor : reconstructable : 86% : strong : Exact ordinary MapNamePane destructor body; live IDA confirms vtable restores, glyph/font table release at +0x220, g_pMapNamePane clear, and base Pane cleanup tail.
        - [UID:<NEW:MapNamePaneOnPaint>][0x00503350-0x0050349f.MapNamePaneOnPaint](by-memory/0x00503350-0x0050349f.MapNamePaneOnPaint.md) 0x00503350-0x0050349f | virtual render method | MapNamePaneOnPaint : reconstructable : 86% : strong : Exact MapNamePane render/on-paint virtual; vtable-only route, EPF and fallback draw paths, centered text measurement, palette selection, and map-name display buffer at +0xf8 confirmed.
        - [UID:<NEW:MapNamePaneHandleMapNameUpdatePacket>][0x005034a0-0x00503574.MapNamePaneHandleMapNameUpdatePacket](by-memory/0x005034a0-0x00503574.MapNamePaneHandleMapNameUpdatePacket.md) 0x005034a0-0x00503574 | secondary virtual packet/update handler | MapNamePaneHandleMapNameUpdatePacket : reconstructable : 87% : strong : Exact secondary-vtable MapNamePane update handler; live IDA confirms adjusted this route from +0xa0, payload pointer at event+12, opcode 0x15, length byte at payload+9, ANSI-to-wide conversion into 128-wchar map-name buffer, 173-pixel ellipsis clamp, and redraw/invalidate callback.
        - [UID:<NEW:MapNamePaneClearSingleton>][0x005037f0-0x005037fb.MapNamePaneClearSingleton](by-memory/0x005037f0-0x005037fb.MapNamePaneClearSingleton.md) 0x005037f0-0x005037fb | singleton helper | MapNamePaneClearSingleton : reconstructable : 85% : strong : Exact MapNamePane singleton-clear helper; live IDA confirms only g_pMapNamePane zeroing and constructor/destructor lifecycle relationship.
        - [UID:<NEW:MapNamePaneDestructorAdjustorThunks>][0x0050380b-0x00503821.MapNamePaneDestructorAdjustorThunks](by-memory/0x0050380b-0x00503821.MapNamePaneDestructorAdjustorThunks.md) 0x0050380b-0x00503821 | compiler thunks | MapNamePaneDestructorAdjustorThunks : ignored : 85% : strong : Compiler-generated destructor adjustor thunks from +0xa0 and +0xa4 secondary/tertiary vtable slots to the scalar deleting destructor; non-emitting evidence only.
        - [UID:<NEW:MapNamePaneScalarDeletingDestructor>][0x00503840-0x005038fe.MapNamePaneScalarDeletingDestructor](by-memory/0x00503840-0x005038fe.MapNamePaneScalarDeletingDestructor.md) 0x00503840-0x005038fe | compiler deleting destructor | MapNamePaneScalarDeletingDestructor : ignored : 86% : strong : Compiler-generated scalar deleting destructor wrapper; live IDA confirms duplicate ordinary destructor cleanup, delete-flag test, primary vtable route, thunk callers, and final delete call. Source destructor is the ordinary destructor child.
```

Recommended ignored padding rows if exact children are created and memory-range coverage needs explicit padding coverage:

```text
        - [padding][0x005032c3-0x005032d0] 0x005032c3-0x005032d0 | padding | MapNamePane constructor/destructor gap : ignored : 100% : certain : Alignment padding between exact MapNamePane constructor and ordinary destructor.
        - [padding][0x0050334d-0x00503350] 0x0050334d-0x00503350 | padding | MapNamePane destructor/render gap : ignored : 100% : certain : Alignment padding between exact MapNamePane ordinary destructor and render method.
        - [padding][0x0050349f-0x005034a0] 0x0050349f-0x005034a0 | padding | MapNamePane render/update gap : ignored : 100% : certain : Single-byte alignment padding between exact render and update-handler methods.
        - [padding][0x00503574-0x00503580] 0x00503574-0x00503580 | padding | MapNamePane-to-MiniMapButton gap : ignored : 100% : certain : Alignment padding before MiniMapButtonPane constructor at 0x00503580.
        - [padding][0x005037fb-0x00503800] 0x005037fb-0x00503800 | padding | MapNamePaneClearSingleton-to-MiniMapButtonClear gap : ignored : 100% : certain : Alignment padding between MapNamePane singleton-clear helper and MiniMapButtonPane singleton-clear helper.
        - [padding][0x00503837-0x00503840] 0x00503837-0x00503840 | padding | MiniMapButton thunks-to-MapName scalar destructor gap : ignored : 100% : certain : Alignment padding before MapNamePane scalar deleting destructor.
        - [padding][0x005038fe-0x00503900] 0x005038fe-0x00503900 | padding | MapNamePane scalar destructor-to-MiniMapButton scalar destructor gap : ignored : 100% : certain : Alignment padding after MapNamePane scalar deleting destructor.
```

## Validation Commands For Supervisor

No validator commands were run in this report-only pass because no by-* files were edited.

Suggested supervisor validation after applying target/support edits:

> Executable block R001 was removed from this report and preserved verbatim in [0001AK-mapnamepane-source-quality-removed.md](0001AK-mapnamepane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If exact child pages are created, run scoped `validator.py --mode file --apply` on each new child before refreshing memory ranges/rescore.

## Negative Evidence Summary

Checked and rejected:

- MapPane direct ownership: rejected because only teardown/global consumer evidence exists.
- MiniMapButtonPane ownership pollution: rejected because exact MiniMapButtonPane functions have independent constructor/vtable/singleton evidence.
- Global packet enum ownership of opcode `0x15`: rejected for this handler context because the handler consumes an event payload pointer and writes only the MapNamePane display buffer.
- UTF-8 interpretation of the map-name update bytes: rejected because `MultiByteToWideChar` uses code page `0`, i.e. CP_ACP/current ANSI code page.
- Treating scalar deleting destructor/thunks as hand-authored C++: rejected by delete-flag and adjustor-thunk structure.
- Leaving generated `sub_5031F0` etc. as open blockers: rejected because context supports stronger descriptive names.

## Final Recommendation

Exact recommended state for [UID:0001AK]:

- `COMPLETION:88`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:00007P` preferred; if the supervisor keeps file ownership for legacy indexes, body text should still say the semantic owner is [UID:00007P].
- `RECONSTRUCTABLE:FALSE`
- `EMITTER_UIDS:` blank
- `RECONSTRUCTION_CPP CODE:` blank

Exact recommended structural action:

- Convert [UID:0001AK] to a non-emitting MapNamePane split/index.
- Create exact child pages listed above when supervisor is ready to execute split repair.
- Keep MiniMapButtonPane child ownership under [UID:00008B]/[UID:0000LE].
- Resolve source placement to standalone `NexusTK/map/MapNamePane.cpp` as preferred file route for future exact child emission.

## Follow-Up Actions

Supervisor actions:

- Apply target/support documentation changes and coverage row replacement.
- Optionally execute the exact child split using the proposed child page list.
- Run scoped validators and memory/range refreshes.

A-agent actions:

- After child split, update exact child behavior docs if more UI/render helper type names become available.
- Do not populate C++ until shared Pane/event/resource/glyph helper declarations are stabilized.

B001 future work:

- No further B001 work is required for [UID:0001AK] unless the supervisor rejects the split/index policy or asks for direct child-page creation.

## Confidence

Recommendation confidence: high. IDA vtables, constructors/destructors, globals, resources, and neighboring MiniMapButtonPane evidence are coherent.

Score confidence: high for [UID:0001AK] as a non-emitting index at `88/91`; medium-high for proposed child scores because pages are not yet created.

Remaining uncertainty: exact original names for helper functions and concrete C++ types for the event/update object, EPF resource context, and glyph/font table. This uncertainty blocks final C++ only; it does not block ownership, source placement, or split/index treatment.

## Validator Results

Commands run:

- None. This was a report-only pass and only the research report was created.

Results:

- Not applicable.

Unresolved validator warnings/errors:

- None observed because no validator was run.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B001/research/0001AK-mapnamepane-source-quality.md`

Modified:

- None outside this report.

Leases used:

- None. `goal.md` says no lease is required for reports inside `Agent-B001/research`.

Blockers:

- No research blocker remains. Supervisor execution is required for by-* edits, child creation, and coverage-report updates.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001AK-mapnamepane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001AK"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001AK-mapnamepane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001AK-mapnamepane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001AK"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
