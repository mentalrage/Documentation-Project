** TARGET-REPORT-UID:00011J **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID00011J EPFImageControlPaneCore Ownership / Split Research


## Finalized Report / Current Recommendation

- Callback implementation is complete. [UID:00011J] is now a `92/94` non-emitting split index with exact children [UID:0004JN] constructor, [UID:0004JS] ordinary destructor, and [UID:0004JW] virtual OnPaint.
- Final disposition is applied: `EPFImageControlPane` is a normal `ControlPane`-derived class owned by [UID:00004G] and emitted through [UID:0000J2] at `NexusTK/ui/controls/EPFImageControlPane.cpp`. UID0003LO is covered-by compiler ABI output and UID0003LN remains non-emitting adjustor glue.
- The three children were created and validator-registered serially before any real UID link was inserted. No UID was predicted or fabricated.
- Final waited generated verification shows one complete class declaration, one constructor, one ordinary destructor, one OnPaint body, one scalar covered-by marker, and zero UID00011J Empty Emitter Marker/aggregate duplicates.
- Confidence remains 94 for range, split, owner, layout, ABI, call order, and source placement; 93 for source-facing `OnPaint`, private-field, and slot-7 fill spellings.

## Supporting Research

- Gate-1 research was performed against streamable IDA MCP database session `59c7e90d` on 2026-07-13. That evidence-time session returned `status: ok`, imagebase `0x00400000`, auto-analysis ready, Hex-Rays ready, and string cache ready; the supervisor later invalidated it after its worker became stale/dead.
- After supervisor recovery, a fresh `idb_list` at `2026-07-13T04:39:58-04:00` returned exactly one active/adopted database and identified session `328356ab` as available at verification time. Fresh read-only `server_health`, target lookup/decompile/disassembly, range-byte, xref, vtable-global, and callback-analysis calls against `328356ab` reproduced the accepted binary evidence. No outage fallback or stale-session substitution supports this artifact.
- Current artifact state records the completed accepted implementation callback. B001 edited only the listed by-* pages under short leases, ran the listed scoped validators and waited generated checks, and made no manual generated/coverage/tracker/supervisor/validator-state edit.
- Historical C001 and older IDA evidence was treated as a lead and checked against current docs, the evidence-time IDB, and the fresh recovery IDB. Stale claims are retained only where explicitly labeled historical or superseded.

## Target

- Target UID: `00011J`.
- Target path: `by-memory/0x004991f0-0x004993a5.EPFImageControlPaneCore.md`.
- Historical queue trigger: the pre-callback generated Empty Emitter Marker in `auto-generated/NexusTK/ui/controls/EPFImageControlPane.cpp`.
- Supervisor classification: accepted split-first implementation callback for exact Gate-1 report SHA256 `3851EA321D832396BCC7548CD163697069BE25A540B23E9EB9976DE6B319805B`.
- Applied scores and parent state: target `92/94`, semantic owner [UID:00004G], reconstructable false, blank emitter/position/formal C++, `Nested:0`.

## Current Target State

- Applied metadata: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:00004G`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional position, blank formal C++, and `Nested:0`.
- Applied split: [UID:0004JN] `0x004991f0-0x004992a8` at position 10, [UID:0004JS] `0x004992b0-0x0049930e` at position 20, and [UID:0004JW] `0x00499310-0x004993a5` at position 30, all owner/emitter UID00004G and reconstructable true.
- Applied source/class state: UID00004G is `92/93` with complete declaration and explicit post-class `[[CHILDREN]]`; UID0000J2 is `91/92`; UID0003LO is `91/94` position 40 with covered-by marker; UID0003LN is `90/94` non-emitting; UID0000QW is `90/92` no-owner/non-emitting.
- Historical generated state at command `000000009078` contained Empty Emitter Markers and no source. B001's authorized waited verification completed at command `000000009188`. At final artifact-audit time, later external foreground refresh command `000000009222`, timestamp `2026-07-13T04:46:03-04:00`, still contained the complete accepted source shape with no aggregate/empty-marker duplicate; this evidence-time observation does not assert that a shared generated header remains indefinitely current.
- Historical stale assumptions are preserved in target/support history as rejected interpretations: local flip, nonvirtual `LoadAndRenderImage`, one-argument `g_pfnLockSurface`, local frame ownership, and blank-until-95.
- Related docs checked and synchronized: target, three new children, class, file, adjustors, scalar wrapper, two callback-table pages, alias, ignored padding, and generated output. ControlPane/Pane/GrafPort/EPFTileContext/ResourceLayoutTable/PaletteLib/ImageLib and UID000172/174 remained unchanged as accepted support; UID00011K remained excluded.
- Current artifact/lifecycle state: B001's callback work is complete and no B001 lease remains. Report validation/execution/count/path/move/archive state is external supervisor/validator-owned and is neither asserted nor directed by this artifact.

## Executive Recommendation

- Applied direct semantic ownership under [UID:00004G][EPFImageControlPane] and retained source placement under [UID:0000J2][EPFImageControlPane].
- Applied UID00011J reviewed non-emitting split index at `92/94`, false, blank emitter/position/formal C++.
- Applied exact UID0004JN constructor child at `92/94`, owner/emitter UID00004G, true, position 10.
- Applied exact UID0004JS ordinary destructor child at `91/94`, owner/emitter UID00004G, true, position 20.
- Applied exact UID0004JW virtual OnPaint child at `92/93`, owner/emitter UID00004G, true, position 30.
- Applied UID00004G `85/87 -> 92/93` complete declaration/placement and UID0000J2 `87/88 -> 91/92` source contents/layout/order/generated expectations.
- Applied UID0003LN `90/94` non-emitting compiler-glue evidence and UID0003LO `91/94` position-40 covered-by marker without a handwritten wrapper.
- Applied UID0000QW `90/92` rejected-alias disposition and slot-7 evidence to UID0000TN/UID0001PI without score inflation.
- Applied both internal `0xcc` spans in `by-memory/-ignored.md`; preserved the existing trailing span and UID00011K exclusion.

## Supervisor Active Recheck

- Gate 1 passed exact report SHA256 `3851EA321D832396BCC7548CD163697069BE25A540B23E9EB9976DE6B319805B`; this artifact now records the accepted callback result.
- The split repair is applied, with independent scores, links, positions, evidence, and source blocks for all three methods.
- No source-bearing child is deferred. Constructor UID0004JN, destructor UID0004JS, and OnPaint UID0004JW are the actual validator-issued identities.
- Child creation/registration was strictly serial. Real UIDs were inserted into parent/class/file/support docs only after each assignment was observed.

## Inference Research Guidance Check

- `by-structure.md` and the project skill require direct binary evidence to outrank generated names and older narrative. Accordingly, raw IDA names such as `sub_4991F0`, `unk_69B3FC`, and `dword_67A744` are evidence labels, not source identifiers.
- Existing claims treated as uncertain were the flip interpretation, load-helper name, callback lock name, aggregate emission, local tile-cache ownership, default palette, object size, and whether the ordinary destructor is source-authored or compiler-only.
- Direct IDA facts are separated below from documentation evidence and source-shape inference. The exact method bodies, boundaries, call shapes, vtable cells, and field offsets are direct facts. `OnPaint`, member spellings, and `FillRect` are source-facing descriptive inferences supported by current project conventions.
- Old reports were searched by UID, class name, and addresses. The executed B007 UID00011I predecessor report and B002 UID00011K successor report were used only for boundary/exclusion context. Neither owns or resolves UID00011J.
- No current Wave2/Wave3 override for this target was found. Any old wave terminology encountered in broad project history was ignored as stale.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis and evidence | Final direction |
| --- | --- | --- |
| Aggregate versus children | Live `lookup_funcs` finds three functions, while byte reads prove two internal `0xcc` gaps. | Split into three exact children; parent becomes non-emitting index. |
| Constructor return/ABI | IDA displays `int __thiscall` returning `this`, but callers use allocation plus constructor and the function ends `retn 14h`. | Source constructor has no explicit return; five explicit parameters after hidden `this`. |
| Constructor argument 4 | Body passes byte argument directly to `0x005446b0`; current PaneSetMode doc proves `Pane::SetMode(unsigned char)`. | Name/type `unsigned char mode`; reject historical flip flag. |
| `+0xff` | ControlPane layout and constructor evidence identify this as inherited control flags. | Use `m_controlFlags = 0`; reject EPF-local flip field. |
| Name arrays | `wcscpy_s` receives extent 16 for `this+0x108` and `this+0x12a`; callers supply wide resource/palette literals. | `wchar_t m_resourceName[16]` and `wchar_t m_paletteName[16]`. |
| Frame field | Constructor writes a word at `+0x128`; render sign-extends it before lookup; caller sample at `0x0048c93d` passes a runtime signed byte/frame value. | `short m_frameIndex`; lookup promotes it to `int`. |
| Default palette | Raw bytes at `0x006108bc` decode exactly as UTF-16LE `BARAM.PAL` plus NUL. | Literal `L"BARAM.PAL"`; no unresolved resource-name blocker. |
| Object size | Representative callers allocate decimal 332 before construction; field end is `0x14a`, naturally rounded to `0x14c`. | `sizeof(EPFImageControlPane) == 0x14c` under observed 32-bit layout; no explicit source pad field. |
| Paint method name | `0x00499310` has one xref, data cell `0x0061828c`, at primary vtable base `0x00618248 + 0x44`; no code callers exist. Neighboring accepted controls use the same slot as paint/draw. | Emit current project-dominant `virtual void OnPaint()`; reject nonvirtual `LoadAndRenderImage`. Exact original spelling remains a confidence cap, not a code blocker. |
| Paint return | Hex-Rays reports `void *` only because the tail call result from `BuildEncodedMask` remains in EAX. The vtable contract and ignored result indicate no semantic return. | Source return type `void`. |
| Stack frame context | `0x00457a60` explicitly initializes the local 0x28-byte context; current EPFTileContext docs say it is not a compiler constructor. | `EPFTileContext frame; frame.Initialize();`. |
| Slot 7 alias | Target calls `(this, this+0x44)`. Installed targets are `0x004be680` and `0x004c4380`, each consumes a destination GrafPort plus rectangle. Current paint children map the same idiom to `FillRect`. | Use `SetDrawColor(0); FillRect(&m_bounds);`; reject `g_pfnLockSurface(drawSurface)`. |
| Resource lookup | `0x004d02f0` is accepted `ResourceLayoutTable::LookupLayoutEntry`; it fills borrowed frame pointers/geometry and clears output on invalid index. | `g_pEPFLib->LookupLayoutEntry(m_resourceName, m_frameIndex, &frame)`. |
| Missing frame | Target tests only `frame.pixelData`; palette/blit are skipped when null, but final mask build still runs. | Preserve unconditional clear and final `m_surfaceContext.BuildEncodedMask()`. |
| Palette failure | `PaletteLib::GetPaletteByName` returns its current/fallback palette on load failure. | Do not add a palette-null branch absent from the binary. |
| Local frame cleanup | Lookup supplies borrowed resource pointers and target has no `ReleaseBuffers` call for the local frame. | Do not add local cleanup; adding it could free borrowed storage. |
| Destructor cleanup | Ordinary destructor explicitly calls `ReleaseBuffers(this+0x1c)` then Pane teardown. GrafPort base teardown later calls the same reset safely. | Source destructor explicitly calls `m_surfaceContext.ReleaseBuffers()`; compiler emits base destruction. |
| Scalar wrapper | `0x0049b1b0` duplicates ordinary teardown then conditionally calls operator delete based on flags. Primary and adjustor routes point here. | Covered-by formal comment only; do not hand-port ABI flags or delete wrapper. |
| Adjustors | `0x0049af53` subtracts `0xa0`; `0x0049af5e` subtracts `0xa4`; both tail-forward to scalar wrapper. | Non-reconstructable compiler glue; class multiple-subobject layout regenerates them. |
| Source placement | Class is a reusable UI control with 66 distinct constructor callers but consumes shared ImageLib/PaletteLib/Surface services. | Keep `NexusTK/ui/controls/EPFImageControlPane.cpp`; reject ResourceLayoutTable, ImageLib, Surface, and dialog-local ownership. |

Rejected alternatives:

- Keep UID00011J as one emitting aggregate: rejected because it hides three source methods and two padding gaps behind one score/block.
- Leave all C++ blank until original symbols are recovered: rejected because behavior, ABI, layout, owner, and source placement are fully recoverable; uncertainty is limited to descriptive spellings.
- Model argument 4 or `+0xff` as flip state: rejected by the direct `Pane::SetMode` call and inherited ControlPane layout.
- Keep `LoadAndRenderImage` as a public helper: rejected by vtable-only reachability at primary slot `+0x44`.
- Emit a standalone scalar deleting destructor or adjustor: rejected as MSVC ABI lowering regenerated by the virtual destructor declaration and multiple subobjects.
- Treat `m_surfaceContext` as EPFImageControlPane-local storage: rejected because it starts at inherited GrafPort offset `+0x1c` and GrafPort teardown owns it.
- Treat local `frame` as owning decoded memory: rejected by `LookupLayoutEntry` borrowed-pointer assignments and the absence of local cleanup.
- Route the class to ImageLib/ResourceLayoutTable/PaletteLib/Surface: rejected because those are broad dependencies and constructor fanout establishes reusable UI-control ownership.
- Merge forward into UID00011K: rejected by eleven `0xcc` bytes and the distinct TargetOption constructor/vtable family at `0x004993b0`.

## Evidence Standards Used

- IDA MCP evidence: the Gate-1 pass used then-healthy database `59c7e90d`, which was later invalidated after worker failure; callback-completion recovery verification used a fresh `idb_list` and only database `328356ab` for `server_health`, `lookup_funcs`, `make_signature_for_range`, `get_global_value`, `xref_query`, `decompile`, `disasm`, and `analyze_function`.
- Binary evidence: exact function extents, return cleanup sizes, padding bytes, vtable slot values, UTF-16 literal bytes, caller allocation size, field offsets, callback targets, and direct/data xrefs.
- Documentation evidence: current accepted class/file/global/memory/type pages and current generated output, with old reports used only as leads.
- Inference ladder: direct body and table facts first; repeated caller and sibling virtual patterns second; current project source-facing conventions third; stripped original spelling last.
- Evidence is strong enough for source-ready first drafts because every control-flow and memory effect is accounted for. Confidence remains below 95 because original private member names, the exact paint spelling, and the original slot-7 typedef name are not present in symbols.

## Evidence Checked

- IDA MCP/manual checks: health; all target/helper/glue function boundaries; target and support decompiles; target disassembly; exact padding bytes; default palette bytes; EPF and ControlPane vtable bytes/values; constructor xrefs; render/destructor/glue xrefs; representative caller decompiles; callback installed-target function analyses.
- Current docs checked: UID00011J, UID00004G, UID0000J2, UID0003LN, UID0003LO, UID0003J8/0003J9 ControlPane vtables, Pane vtables, GrafPort, EPFTileContext, UID0002KP lookup, ResourceLayoutTable, ImageLib/g_pEPFLib, PaletteLib/g_pPaletteLib, UID0000TN/0001PI callback table, UID0000QW alias, UID000172/174, PaneSetMode, ignored padding, coverage, generated EPFImageControlPane.cpp.
- Old reports checked: executed B007 `00011I-StaticTextControlPaneConstructor-source-quality.md` for the predecessor boundary and executed B002 `00011K-target-option-edit-control-pane-source-quality.md` for the successor boundary/class exclusion.
- Negative checks at research time: zero xrefs to ordinary destructor; one data-only xref to paint; no direct code caller to paint; no local frame release; no call into UID00011K; no evidence slot 7 is a one-argument lock callback; no duplicate report at the assigned B001 path.
- Historical report-only boundary: before Gate 1, B001 made no IDA mutation, process-management call, validator call, lease, generated refresh, or by-* edit. The later accepted callback actions are recorded below.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | ---: | --- | --- | --- | --- |
| C11J-001 | Evidence-time MCP session `59c7e90d` was healthy for Gate-1 research but was later invalidated; fresh recovery session `328356ab` is the sole IDB used for callback-completion revalidation. | 100 | Historical and fresh `idb_list`/`server_health`; fresh target probes. | Parent and all three child evidence sections; report recovery record. | Incorporate and reverify. | Applied and reverified: fresh `idb_list` returned only `328356ab`; health reported analysis/Hex-Rays/strings ready, and all target-specific probes reproduced the accepted evidence without by-* changes. |
| C11J-002 | Exact source methods are `0x004991f0-0x004992a8`, `0x004992b0-0x0049930e`, and `0x00499310-0x004993a5`. | 100 | `lookup_funcs`, decompile, disasm. | Parent function inventory; new child pages. | Split. | Applied: serialized validators assigned UID0004JN, UID0004JS, and UID0004JW to the exact three ranges. |
| C11J-003 | Internal gaps are 8 and 2 bytes of `0xcc`; trailing gap is 11 bytes before UID00011K. | 100 | `get_bytes`; current ignored row. | Parent range section; `by-memory/-ignored.md`. | Incorporate/register. | Applied: parent and ignored inventory record both internal spans and preserve the trailing span/UID00011K boundary. |
| C11J-004 | Parent UID00011J must be a non-emitting split index. | 99 | Three functions plus gaps; autogen behavior. | UID00011J metadata/block. | Reclassify. | Applied: UID00011J is `92/94`, false, blank emitter/position/block, `Nested:0`, and generated count is zero. |
| C11J-005 | Constructor source signature has resource name, signed 16-bit frame, byte mode, bounds pointer, palette name. | 97 | `retn 14h`, decompile, callers, helper contracts. | Constructor child/class declaration. | Incorporate. | Applied exactly in UID0004JN and UID00004G formal blocks and full ABI prose. |
| C11J-006 | Base initializer is `ControlPane(8, bounds)`. | 100 | Constructor call to `0x004949e0`; current ControlPane constructor. | Constructor child. | Incorporate. | Applied exactly in UID0004JN formal block and behavior order. |
| C11J-007 | Resource and palette members are 16-wide-character arrays at `+0x108` and `+0x12a`. | 100 | Two `wcscpy_s(...,16,...)` calls. | Constructor child/class/target. | Incorporate. | Applied in UID0004JN, UID00004G layout/declaration, UID00011J, and UID0000J2. |
| C11J-008 | `+0x128` is `short m_frameIndex`; `+0xff` is inherited control flags, not flip. | 98 | Word store/sign extension; PaneSetMode; ControlPane layout. | Constructor child/class/file. | Correct stale wording. | Applied throughout target/constructor/class/file; prior flip wording is retained only as superseded history. |
| C11J-009 | Null palette argument selects exact UTF-16 `BARAM.PAL`. | 100 | Raw bytes at `0x006108bc`. | Constructor child/class/file. | Incorporate. | Applied exactly in UID0004JN formal block and constructor/class/file evidence. |
| C11J-010 | Constructor has 120 call sites in 66 distinct functions. | 100 | Live `xref_query`, full page. | Constructor/parent/class/file evidence. | Incorporate. | Applied without compression to UID0004JN and summarized consistently in UID00011J/UID00004G/UID0000J2. |
| C11J-011 | Representative callers allocate 332 (`0x14c`) bytes and use frame, mode, bounds, and nullable palette in the recovered order. | 99 | Decompile samples at `0x00450ca0`, `0x0046e640`, `0x0048c640`, `0x004f9d30`, `0x00541b30`, `0x00552c10`. | Constructor/class layout evidence. | Incorporate. | Applied to UID0004JN caller inventory and UID00004G/UID0000J2 object-size rationale. |
| C11J-012 | Compiler vptr stores and constructor EH cleanup are not handwritten source. | 99 | Constructor disasm/EH shape and vtable stores. | Constructor negative/compiler notes. | Exclude with reason. | Excluded with reason in UID0004JN and parent negative evidence; absent from generated source. |
| C11J-013 | Ordinary destructor explicitly releases inherited `m_surfaceContext`, then compiler invokes base teardown. | 99 | `0x004992b0` decompile; GrafPort destructor. | Destructor child. | Incorporate. | Applied exactly in UID0004JS body and complete destruction-order evidence. |
| C11J-014 | Ordinary destructor has zero direct/data xrefs but remains source-authored via virtual destructor semantics. | 97 | `xref_query`; scalar/vtable routes. | Destructor child/parent. | Incorporate negative evidence. | Applied to UID0004JS/UID00011J/UID00004G/UID0000J2 with scalar/vtable reachability explanation. |
| C11J-015 | Scalar wrapper is source-declared/generated-binary and must use a formal covered-by marker only. | 100 | `0x0049b1b0` decompile and three xrefs. | UID0003LO block/metadata. | Update. | Applied: UID0003LO is `91/94`, position 40, with exact covered-by marker and no ABI body. |
| C11J-016 | Adjustors subtract `0xa0` and `0xa4` and tail-forward to scalar wrapper. | 100 | Thunk decompiles/vtable cells. | UID0003LN. | Update prose/score, remain non-emitting. | Applied: UID0003LN is `90/94`, NONE/false/blank, with exact adjustment/vtable/regeneration evidence. |
| C11J-017 | EPF primary/secondary/tertiary vtable bases are `0x00618248`, `0x006182b0`, `0x006182e0`. | 100 | Constructor stores, bytes, values, xrefs. | Parent/class/glue docs. | Incorporate. | Applied to UID00011J, UID00004G, UID0004JS, UID0003LN, and UID0003LO. |
| C11J-018 | `0x00499310` is the sole EPF override at primary slot `+0x44`, reached only from `0x0061828c`. | 100 | Vtable comparison and xref query. | Paint child/class. | Rename source-facing method to `OnPaint`. | Applied in UID0004JW/UID00004G/UID0000J2 and generated source; historical helper name count is zero. |
| C11J-019 | Paint initializes a local EPFTileContext explicitly and sets draw color to zero. | 100 | Target decompile and accepted helper docs. | Paint child. | Incorporate. | Applied exactly in UID0004JW formal block and behavior evidence. |
| C11J-020 | Slot 7 call is pane-region fill/presentation over `m_bounds`, not a one-argument lock. | 96 | Call shape, installed targets, 206-slot fanout, sibling paint docs. | Paint child; UID0000TN/0001PI/0000QW. | Use `FillRect`; historicalize lock alias. | Applied to all four destinations; UID0000QW is `90/92` no-owner/no-emitter and generated lock alias count is zero. |
| C11J-021 | Frame lookup is `g_pEPFLib->LookupLayoutEntry(resource, frame, &local)`. | 99 | Target call and UID0002KP exact source. | Paint child. | Incorporate. | Applied exactly in UID0004JW; UID0002KP remained unchanged as sufficient shared support. |
| C11J-022 | Invalid frame skips palette lookup and blit but does not skip clear or final mask build. | 100 | Target control flow. | Paint child/target. | Incorporate. | Applied to UID0004JW branch/body and UID00011J/UID0000J2 behavior. |
| C11J-023 | Palette lookup uses `g_pPaletteLib->GetPaletteByName(m_paletteName)` and supplies fallback behavior. | 98 | Target call and PaletteLib docs/decompile. | Paint child. | Incorporate without extra null branch. | Applied exactly with no extra null branch; PaletteLib support remained unchanged. |
| C11J-024 | Slot 2 call is accepted `g_pfnBlitSprite` with frame/context bounds, pane bounds, mode zero, palette, null options. | 99 | Target call; UID0004H6/UID0000TN contracts. | Paint child. | Incorporate. | Applied exactly in UID0004JW and verified once in generated output. |
| C11J-025 | Final unconditional action is inherited `m_surfaceContext.BuildEncodedMask()`. | 100 | Tail call at `0x00499395`; GrafPort/EPFTileContext layout. | Paint child. | Incorporate. | Applied after the valid-frame branch in UID0004JW and generated output. |
| C11J-026 | Local lookup frame is borrowed and must not be released by this method. | 98 | UID0002KP pointer assignments; no release call. | Paint child negative evidence. | Preserve no-cleanup behavior. | Applied: UID0004JW records borrowed ownership and emits no local release. |
| C11J-027 | Direct owner/emitter is UID00004G; source file is UID0000J2. | 99 | Vtables, class layout, caller fanout, current route. | Parent/children/class/file. | Retain route. | Applied: children/scalar route through UID00004G and class routes through UID0000J2; parent is semantic-owner-only. |
| C11J-028 | Class declaration is complete at observed size `0x14c` without explicit source pad. | 97 | Base size/field offsets/caller allocations. | UID00004G formal block. | Populate. | Applied exactly; explicit post-class `[[CHILDREN]]` placement directive preserves complete class before methods. |
| C11J-029 | UID000172/174 and UID0002KP remain shared support; UID00011K remains excluded. | 100 | Current docs and boundaries. | Parent/support notes. | Already present/excluded. | Verified already-present/excluded; no protected support/successor page was edited. |
| C11J-030 | Internal padding must be added to ignored inventory; trailing padding already exists. | 100 | Byte reads and current ignored page. | `by-memory/-ignored.md`. | Add two rows/preserve one. | Applied in the existing grouped row; both internal spans added and trailing span/UID00011K text preserved. |
| C11J-031 | Generated output should contain class declaration, three source methods, scalar-wrapper marker, and no UID00011J Empty Emitter Marker. | 98 | Proposed owner/order and current validator model. | UID0000J2/generated verification. | Verify after callback validators. | Verified after explicit placement repair: final generated counts are `1/1/1/1/1`, UID00011J/Empty Marker `0/0`, in class/ctor/dtor/OnPaint/scalar order. |
| C11J-032 | No IDA rename/type mutation is necessary for documentation reconstruction. | 100 | Stable doc-level evidence; assignment prohibition. | Report/follow-up. | No IDA edit. | Complete: research and callback made no IDA mutation or MCP process-management call. |

## Positive Evidence Summary

- Direct facts: three exact functions; exact padding; constructor call ABI; 120 call sites/66 caller functions; three vtable bases; one primary paint-slot xref; exact field offsets; exact UTF-16 default palette; exact helper/callback order; destructor/glue relationships; and exact successor boundary.
- Corroborating docs: current ControlPane, PaneSetMode, GrafPort, EPFTileContext, ResourceLayoutTable lookup, PaletteLib, and SurfaceRenderCallbackTable pages provide accepted source-facing contracts for every target callee and touched inherited field.
- Strongest inference chain: primary slot `+0x44` is a virtual paint/draw contract; this method clears the pane region, obtains a named frame/palette, blits it to inherited bounds, and finalizes the inherited render mask. `OnPaint` is therefore safer and more source-shaped than the stale helper-like `LoadAndRenderImage` name.
- Ownership is direct because constructor/destructor/paint all install/use EPFImageControlPane vtables and fields, while shared resource/palette/surface components are only callees/globals.

## IDA MCP Facts

- Session provenance: `59c7e90d` was healthy when the accepted Gate-1 evidence was collected and was later invalidated after its worker failed. Fresh `idb_list` returned only recovery session `328356ab`; its `server_health` was `ok`, imagebase `0x00400000`, with auto-analysis, Hex-Rays, and the 2067-entry string cache ready.
- Recovery boundary/function recheck: `lookup_funcs` reconfirmed constructor `0x004991f0` size `0xb8`, no function at `0x004992a8`, destructor `0x004992b0` size `0x5e`, no function at `0x0049930e`, paint `0x00499310` size `0x95`, no function at `0x004993a5`, successor `0x004993b0` size `0x52`, adjustors `0x0049af53`/`0x0049af5e` size `0x0b`, and scalar wrapper `0x0049b1b0` size `0x9f`; the supervisor probe `0x00401000` also resolved normally.
- Recovery body/byte recheck: fresh decompiles/disassembly reproduced constructor base/vptr/copy/frame/mode/default-palette order, destructor release/base-teardown order, and paint clear/fill/lookup/valid-frame/palette/blit/final-mask control flow. Range signatures were exactly 8, 2, and 11 `cc` bytes, and `0x006108bc-0x006108d0` was exactly UTF-16LE `BARAM.PAL` plus NUL.
- Recovery xref/table recheck: fresh `xref_query` returned constructor `120` code xrefs in `66` caller functions, ordinary destructor `0`, paint one data xref at `0x0061828c`, each adjustor one data xref, and scalar wrapper two adjustor code refs plus primary-vtable data ref. Fresh global reads returned `0x00618248 -> 0x0049b1b0`, `0x0061828c -> 0x00499310`, `0x006182b0 -> 0x0049af53`, and `0x006182e0 -> 0x0049af5e`; fresh callback analyses reconfirmed `0x004be680` size `0x6e7` and `0x004c4380` size `0x340` with destination/rectangle clipping and fill behavior.
- Functions: constructor size `0xb8`; ordinary destructor `0x5e`; paint `0x95`; adjustors `0x0b` each; scalar deleting destructor `0x9f`; successor `0x004993b0` size `0x52`.
- Padding: `0x004992a8-0x004992b0` is 8 `cc`; `0x0049930e-0x00499310` is 2 `cc`; `0x004993a5-0x004993b0` is 11 `cc`.
- Constructor: calls `0x004949e0(this,8,bounds)`, writes three vptrs, performs two extent-16 secure wide copies, writes frame word, clears byte `+0xff`, calls `0x005446b0(this,mode)`, and returns with `retn 14h`.
- Literal: bytes `42 00 41 00 52 00 41 00 4d 00 2e 00 50 00 41 00 4c 00 00 00` at `0x006108bc` are `BARAM.PAL`.
- Xrefs: constructor 120 code xrefs in 66 functions; ordinary destructor 0; paint one data xref at `0x0061828c`; scalar wrapper three refs; each adjustor one vtable ref.
- Vtables: primary `0x00618248`, secondary `0x006182b0`, tertiary `0x006182e0`; paint at primary `+0x44`; scalar at primary slot 0; adjustors at secondary/tertiary slot 0.
- Destructor: ordinary and scalar forms release `this+0x1c` and invoke Pane teardown; scalar wrapper conditionally invokes delete. Adjustors subtract 40 or 41 dwords.
- Paint: explicitly initializes local context, sets draw color zero, calls slot 7 with `(this,this+0x44)`, looks up frame, tests `pixelData`, resolves palette, invokes slot 2, and unconditionally builds mask on `this+0x1c`.
- Callback targets: slot 7 installed functions are `0x004be680` size `0x6e7` and `0x004c4380` size `0x340`; both use GrafPort/rectangle/clip/color behavior. Slot 2 is accepted `g_pfnBlitSprite`.
- Negative facts: no normal paint caller, no ordinary-destructor xref, no local-frame release, no one-argument slot-7 call, and no target instruction beyond `0x004993a5`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004991f0-0x004993a5` | UID00011J existing parent | Non-emitting split index | False | UID00004G semantic owner; no emitter | `92/94` | Applied and validated. |
| `0x004991f0-0x004992a8` | [UID:0004JN] `by-memory/0x004991f0-0x004992a8.EPFImageControlPaneConstructor.md` | Source constructor | True | UID00004G, position 10 | `92/94` | Created/registered first; applied and validated. |
| `0x004992a8-0x004992b0` | `by-memory/-ignored.md` | 8-byte alignment | No source | Ignored inventory | `100/100` convention | Added to existing grouped row. |
| `0x004992b0-0x0049930e` | [UID:0004JS] `by-memory/0x004992b0-0x0049930e.EPFImageControlPaneDestructor.md` | Ordinary source destructor | True | UID00004G, position 20 | `91/94` | Created/registered second; applied and validated. |
| `0x0049930e-0x00499310` | `by-memory/-ignored.md` | 2-byte alignment | No source | Ignored inventory | `100/100` convention | Added to existing grouped row. |
| `0x00499310-0x004993a5` | [UID:0004JW] `by-memory/0x00499310-0x004993a5.EPFImageControlPaneOnPaint.md` | Virtual paint | True | UID00004G, position 30 | `92/93` | Created/registered third; applied and validated. |
| `0x004993a5-0x004993b0` | Existing ignored row | 11-byte alignment before UID00011K | No source | Ignored inventory | Existing | Preserve. |
| `0x0049af53-0x0049af69` | UID0003LN | Two destructor adjustors | False | None; class is source cause | `90/94` | Evidence/score applied; remains non-emitting. |
| `0x0049b1b0-0x0049b24f` | UID0003LO | Scalar deleting destructor ABI lowering | True covered-by | UID00004G, position 40 | `91/94` | Marker applied; no wrapper body. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004991f0` | 120 call sites across 66 functions | Broad reusable-control constructor, not dialog-local ownership. |
| `0x00450e6a/0x00450eb8` | allocate 332 before calls at `0x00450e91/0x00450edf` | Confirms observed class size `0x14c`. |
| `0x0048c93d/0x0048cd3d` | caller passes runtime byte at its `+0x26c` as frame argument | Confirms frame is not always literal zero and is distinct from mode. |
| `0x004f9e00` | resource `DLGNEW01.EPF`, frame 0, mode 1, bounds, null palette | Confirms nullable palette/default path. |
| `0x00541c0a` | `DLGMAC2.EPF`, frame 0, mode 1, bounds, `DLGMACRO.PAL` | Confirms explicit palette path. |
| `0x004992b0` | zero xrefs | Ordinary source destructor is reached through compiler-generated virtual-destruction lowering, not a reason to discard it. |
| `0x0061828c` | only xref to `0x00499310` | Vtable-only primary `+0x44` virtual route. |
| `0x00618248` | primary slot 0 -> `0x0049b1b0` | Scalar deleting destructor route. |
| `0x006182b0` | secondary slot 0 -> `0x0049af53` | `this-0xa0` adjustor route. |
| `0x006182e0` | tertiary slot 0 -> `0x0049af5e` | `this-0xa4` adjustor route. |
| `0x00499310` callees | `0x00457a60`, `0x004b9660`, slots `69b3fc/69b3e8`, `0x004d02f0`, `0x00543d70`, `0x00457ab0` | Complete paint dependency/order inventory. |

## Documentation Evidence And IDA Status

- Current target/class/file docs correctly identify the compact EPF range, three vtable bases, default palette, broad constructor fanout, and UID00011K exclusion.
- Those docs are stale where they call mode/control flags flip state, call paint a load helper, describe slot 7 as clear/lock without final source direction, and treat member/callback naming as a reason for blank source.
- UID0002KP already supplies exact formal `LookupLayoutEntry` behavior, including borrowed pointers and invalid-frame output clearing. No support edit is needed there.
- EPFTileContext already supplies exact 0x28 layout and `Initialize`, `ReleaseBuffers`, and `BuildEncodedMask` source names. No support edit is needed there.
- GrafPort already supplies `m_surfaceContext`, `m_bounds`, `SetDrawColor`, accepted sprite callback types, and current paint children using `FillRect`. No support edit is needed there.
- Surface callback docs correctly reject pane-local ownership but retain stale unresolved slot-7 wording; this assignment can add the exact two-argument fill resolution without trying to finish all 12 slots.
- Generated output is current evidence of the empty-emitter problem only. It must not be edited manually.
- Coverage and project trackers are validator-owned; no manual row text is required.

## Ranked Ownership Analysis

### 1. EPFImageControlPane class UID00004G

- Evidence for: all methods install/use EPF vtables; all added fields are class-local tail fields; constructor fanout creates this concrete type; scalar/adjustor routes name the same RTTI family.
- Evidence against: none affecting ownership. Exact original private spellings are stripped.
- Decision: direct owner and emitter for class declaration, three source children, and scalar covered-by marker.

### 2. EPFImageControlPane source file UID0000J2

- Evidence for: current valid `NexusTK/ui/controls/` path; reusable control role; class-local constructor/destructor/paint set; current generated route.
- Evidence against: exact original header/implementation split is not proven.
- Decision: retain source root and module; emit plausible implementation in `EPFImageControlPane.cpp`.

### 3. ImageLib / ResourceLayoutTable / PaletteLib / Surface

- Evidence for: paint consumes their globals, lookup, palette, and callback services.
- Evidence against: no target function belongs to their vtables/classes; constructor/destructor fields and RTTI are EPFImageControlPane-local; broad service fanout proves dependency rather than ownership.
- Decision: support dependencies only; reject as target owners.

### 4. TargetOptionEditControlPane / neighboring control aggregate

- Evidence for: immediate address adjacency only.
- Evidence against: 11-byte padding, distinct constructor at `0x004993b0`, separate vtables/RTTI/class/file route, executed UID00011K report.
- Decision: excluded.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new source file. Keep `NexusTK/ui/controls/EPFImageControlPane.cpp`.
- Likely full contents: EPFImageControlPane declaration, constructor, ordinary destructor, virtual paint definition, and compiler-generated ABI effects represented by the declaration/covered-by marker.
- Candidate related items that belong: three exact contiguous children plus scalar-wrapper source disposition and adjustor cross-references.
- Candidate related items rejected: shared EPFTileContext, ResourceLayoutTable, PaletteLib, callback-table implementations, TargetOption code.
- Source-file inference: narrow one-class UI-control source is stronger than a broad control aggregate because current file route and generated root already exist.

## Source Placement

- Recommended placement: class declaration and method source under [UID:0000J2] `NexusTK/ui/controls/EPFImageControlPane.cpp`.
- This fits subsystem context because 66 constructors across dialog/control setup paths reuse one control that consumes, but does not own, render and image services.
- Rejected placements: `NexusTK/render/`, ImageLib, ResourceLayoutTable, PaletteLib, Surface, and any specific caller/dialog source.
- Remaining placement uncertainty: original `.h` versus `.cpp` declaration distribution is not provable. It does not alter the validator's current source-root placement.

## Range / Split / Padding / Reclassification Analysis

- Parent exact range remains `0x004991f0-0x004993a5`; it becomes a non-emitting index rather than being deleted or renamed out of history.
- Exact child A is constructor `0x004991f0-0x004992a8`.
- Exact child B is ordinary destructor `0x004992b0-0x0049930e`.
- Exact child C is virtual paint `0x00499310-0x004993a5`.
- Add ignored internal gaps `0x004992a8-0x004992b0` and `0x0049930e-0x00499310` as compiler/linker alignment.
- Preserve existing ignored trailing gap `0x004993a5-0x004993b0`.
- Keep UID0003LN and UID0003LO non-contiguous. Do not merge them back into the contiguous parent.
- Keep UID00011K starting at `0x004993b0`; do not claim or modify any successor bytes.
- Completed registration procedure: constructor was created/registered as UID0004JN, then destructor as UID0004JS, then paint as UID0004JW; links were inserted only afterward.

## Negative Evidence Summary

- No ordinary destructor xref was found. This does not prove dead code because the primary vtable points to a compiler-generated scalar destructor that duplicates/inlines the teardown, and secondary views route through adjustors.
- No direct code caller reaches `0x00499310`; its sole data xref is the EPF primary vtable paint slot, proving virtual dispatch rather than orphan status.
- No instruction supports a flip field. The relevant byte is inherited `m_controlFlags`, and the constructor separately calls PaneSetMode.
- No one-argument lock call exists at this target. The exact call has destination receiver plus rectangle, and installed target bodies implement draw/fill behavior.
- No local `EPFTileContext::ReleaseBuffers` call exists in paint. Adding one would be unsupported and unsafe because lookup assigns borrowed resource pointers.
- No evidence makes the return value of `BuildEncodedMask` a semantic paint return. The vtable method should be `void`.
- No evidence supports manually emitted vptr stores, EH state, scalar delete flags, adjustor math, security cookies, or base destructor calls.
- No evidence supports ResourceLayoutTable, PaletteLib, or Surface ownership of the UI class.
- No evidence supports merging into the predecessor UID00011I or successor UID00011K.

## IDA Rename / Type / Comment Recommendations

- Documentation/source-facing rename: `sub_4991F0` -> `EPFImageControlPane::EPFImageControlPane`.
- Documentation/source-facing rename: `sub_4992B0` -> `EPFImageControlPane::~EPFImageControlPane` ordinary destructor.
- Documentation/source-facing rename: `sub_499310` -> `EPFImageControlPane::OnPaint`; preserve historical `LoadAndRenderImage` only as a superseded descriptive alias.
- Types: `const wchar_t *resourceName`, `short frameIndex`, `unsigned char mode`, `const RectBounds *bounds`, `const wchar_t *paletteName`.
- Fields: `m_resourceName[16]` at `+0x108`, `m_frameIndex` at `+0x128`, `m_paletteName[16]` at `+0x12a`; inherited `m_controlFlags` at `+0xff`; inherited `m_surfaceContext` at `+0x1c` and `m_bounds` at `+0x44`.
- Slot 7 source direction: `FillRect` / pane-region fill-presentation callback over `GrafPort *` and `const RectBounds *`. `g_pfnLockSurface` remains a rejected generated alias.
- Slot 2 source direction: preserve accepted `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` and nullable `SurfaceSpriteBlitOptions *`.
- No IDA DB mutation was requested or performed. These remain documentation/source reconstruction names.

## First-Draft C++ Recommendation

Applied callback C++ consists of the class declaration, constructor child, ordinary destructor child, virtual paint child, and scalar-wrapper covered-by marker. The parent split index and adjustor page remain blank/non-emitting. The sole post-Gate-1 structural addition is the validator directive `[[CHILDREN]]` after the complete class declaration; it changes insertion placement, not any accepted C++ payload.

Destination: `by-class/EPFImageControlPane.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class EPFImageControlPane : public ControlPane
{
public:
    EPFImageControlPane(const wchar_t *resourceName,
                        short frameIndex,
                        unsigned char mode,
                        const RectBounds *bounds,
                        const wchar_t *paletteName);
    virtual ~EPFImageControlPane();

    virtual void OnPaint();

private:
    wchar_t m_resourceName[16];
    short m_frameIndex;
    wchar_t m_paletteName[16];
};
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: [UID:0004JN] `by-memory/0x004991f0-0x004992a8.EPFImageControlPaneConstructor.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
EPFImageControlPane::EPFImageControlPane(const wchar_t *resourceName,
                                         short frameIndex,
                                         unsigned char mode,
                                         const RectBounds *bounds,
                                         const wchar_t *paletteName)
    : ControlPane(8, bounds)
{
    wcscpy_s(m_resourceName, _countof(m_resourceName), resourceName);
    m_frameIndex = frameIndex;
    m_controlFlags = 0;
    SetMode(mode);
    wcscpy_s(m_paletteName,
             _countof(m_paletteName),
             paletteName != NULL ? paletteName : L"BARAM.PAL");
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: [UID:0004JS] `by-memory/0x004992b0-0x0049930e.EPFImageControlPaneDestructor.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
EPFImageControlPane::~EPFImageControlPane()
{
    m_surfaceContext.ReleaseBuffers();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: [UID:0004JW] `by-memory/0x00499310-0x004993a5.EPFImageControlPaneOnPaint.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void EPFImageControlPane::OnPaint()
{
    EPFTileContext frame;
    frame.Initialize();

    SetDrawColor(0);
    FillRect(&m_bounds);

    g_pEPFLib->LookupLayoutEntry(m_resourceName, m_frameIndex, &frame);
    if (frame.pixelData != NULL)
    {
        void *palette = g_pPaletteLib->GetPaletteByName(m_paletteName);
        g_pfnBlitSprite(this,
                        &frame,
                        &frame.bounds,
                        &m_bounds,
                        0,
                        palette,
                        NULL);
    }

    m_surfaceContext.BuildEncodedMask();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: `by-memory/0x0049b1b0-0x0049b24f.EPFImageControlPaneScalarDeletingDestructor.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Source-declared/generated-binary only. EPFImageControlPane's virtual
// destructor declaration and ordinary destructor definition regenerate this
// scalar deleting destructor, conditional operator delete path, and the
// secondary/tertiary adjustor routes. Do not hand-emit an ABI wrapper.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Behavior preservation:

- The constructor preserves base call, secure-copy extents, assignment/call order, null palette fallback, and implicit compiler vptr/EH behavior.
- The destructor preserves the explicit first release; compiler-generated base teardown preserves the observed second safe release in GrafPort teardown.
- Paint preserves clear-before-lookup, signed frame promotion, invalid-frame skip, palette fallback behavior, exact mode/palette/options callback arguments, no local borrowed-buffer free, and unconditional final mask build.
- The class layout naturally ends at `0x14a` and rounds to `0x14c` without an invented source pad member.
- Names are descriptive project conventions rather than claimed original symbols. Their uncertainty is reflected in confidence below 95 and does not change binary behavior.
- Third-party import directive: not applicable; all methods are NexusTK project source, not a vetted third-party embed.

## Final Recommendation

- Applied: UID00011J is a non-emitting split index `92/94`, owner UID00004G, reconstructable false, blank emitter/position/formal block.
- Applied: exact children UID0004JN/UID0004JS/UID0004JW were registered in strict serial order before real links were inserted.
- Applied: three method blocks, one class declaration block, one post-class placement directive, and one scalar-wrapper covered-by block.
- Retained: UI-control owner/source placement, all binary evidence, rejected alternatives, historical names, negative evidence, and protected shared/support content.
- Retained: adjustors no-owner/non-emitting and scalar wrapper source-declared/generated-binary; no compiler ABI body is hand-authored.
- Applied: two internal ignored padding ranges; the existing trailing range and UID00011K boundary remain intact.
- Applied: callback support closes the stale EPF lock alias while broader table uncertainties/scores remain unchanged.
- Future source-symbol discovery may refine descriptive spellings only. No current behavior, split, owner, score, generated-placement, or C++ blocker remains.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004991f0-0x004993a5.EPFImageControlPaneCore.md`.
- Applied: status is a reviewed non-emitting split index; UID and historical range provenance are preserved.
- Applied: `92/94`, owner UID00004G, false, blank emitter/position/formal block, `Nested:0`.
- Applied: real child links were added only after serialized UID assignment.
- Applied: evidence-time and fresh recovery-session facts, three ranges, all padding, 120/66 caller inventory, vtable/layout/callback/destructor/glue facts, source disposition, and generated expectation.
- Applied: flip, `LoadAndRenderImage`, lock-surface, cached-image-local, and blank-until-95 claims are historicalized as rejected interpretations.
- Preserved: UID00011K exclusion, UID0003LN/0003LO non-contiguous relationships, UID000172/174 support, and earlier C001 boundary evidence.

New constructor child:

- Created/registered exact path as UID0004JN before linking.
- Applied `92/94`, owner/emitter UID00004G, true, position 10, `Nested:0`.
- Applied exact constructor block and full range/ABI/caller/layout/default/EH evidence.

New destructor child:

- Created/registered exact path as UID0004JS before linking.
- Applied `91/94`, owner/emitter UID00004G, true, position 20, `Nested:0`.
- Applied exact destructor block and full zero-xref, explicit release, base teardown, scalar-wrapper, adjustor, and double-safe-reset evidence.

New paint child:

- Created/registered exact path as UID0004JW before linking.
- Applied `92/93`, owner/emitter UID00004G, true, position 30, `Nested:0`.
- Applied exact paint block and complete vtable-only, callback, resource/palette, failure, borrowed-context, and final-mask evidence.

## Recommended Support Doc Changes

- Applied to `by-class/EPFImageControlPane.md`: `85/87 -> 92/93`, exact declaration, post-class placement directive, three real child links, 0x14c layout, inherited fields, OnPaint slot, compiler-glue disposition, and corrected blockers.
- Applied to `by-file/EPFImageControlPane.md`: `87/88 -> 91/92`, retained path, complete source order/children/generated expectation/dependencies, and corrected flip/load/lock wording.
- Applied to UID0003LN: `84/90 -> 90/94`, retained NONE/false/blank emitter/block, exact `-0xa0/-0xa4`, vtable, scalar-forward, and regeneration evidence.
- Applied to UID0003LO: `86/90 -> 91/94`, retained owner/emitter UID00004G/true, position 40, exact covered-by block, conditional-delete and ordinary-destructor parity evidence without wrapper body.
- Applied to UID0000QW: `86/88 -> 90/92`, retained NONE/false/blank emitter, and rejected the generated lock alias for exact EPF `FillRect(&m_bounds)` behavior.
- Applied to UID0000TN with score unchanged `89/86`: resolved slot-7 EPF consumer direction while preserving table-wide limits.
- Applied to UID0001PI with score unchanged `89/88`: replaced stale EPF pending-signature text with installed-target/FillRect evidence while preserving wider slot limits.
- Applied to `by-memory/-ignored.md`: added exact internal spans to the existing grouped row and preserved the trailing EPF/TargetOption span.
- UID0002KP, EPFTileContext, GrafPort, PaneSetMode, UID000172/174, g_pEPFLib, and g_pPaletteLib were verified already present/sufficient and remained unedited.
- UID00011K and protected successor docs remained excluded and unedited.
- Generated/coverage/tracker files were never edited manually; validator-owned refresh supplied final proof.

## Score And Metadata Recommendation

| Item | Before | Applied | Metadata disposition |
| --- | --- | --- | --- |
| UID00011J parent | `86/90` | `92/94` | owner retained; false; emitter cleared; blank position/block. |
| UID0004JN constructor | none | `92/94` | owner/emitter 00004G; true; position 10. |
| UID0004JS destructor | none | `91/94` | owner/emitter 00004G; true; position 20. |
| UID0004JW OnPaint | none | `92/93` | owner/emitter 00004G; true; position 30. |
| UID00004G class | `85/87` | `92/93` | owner/emitter route retained; apply declaration. |
| UID0000J2 file | `87/88` | `91/92` | path/FILE owner retained. |
| UID0003LN adjustors | `84/90` | `90/94` | NONE/false/blank retained. |
| UID0003LO scalar wrapper | `86/90` | `91/94` | owner/emitter 00004G retained; true; position 40; covered-by marker. |
| UID0000QW stale alias | `86/88` | `90/92` | NONE/false/blank retained. |
| UID0000TN/0001PI callback table | `89/86`, `89/88` | unchanged | Add one-slot evidence only; broader table still caps scores. |

Score-improvement attempts:

- Field/layout blocker: removed through secure-copy extents, word/sign-extension use, base layout, and 332-byte caller allocation.
- Default palette blocker: removed through raw UTF-16 bytes.
- Mode/flip blocker: removed through exact PaneSetMode call and inherited ControlPane field mapping.
- Callback blocker: removed for this call site through two-argument call shape, installed target analysis, sibling formal paint usage, and accepted slot-2 type. Broader callback-table type completion remains outside target score.
- Method-name blocker: resolved to source-facing `OnPaint` from vtable-only `+0x44` behavior. Original spelling remains a confidence cap only.
- Destructor/compiler-glue blocker: removed by separating ordinary source body, scalar covered-by marker, and non-emitting adjustors.
- Split/emitter blocker: removed by three exact child plans and serialized UID registration procedure.
- Source-placement blocker: removed by current valid file route, vtable identity, and 66-caller reusable-control fanout.
- Scores stay below 95 because private names, exact original paint spelling, and original callback typedef spelling are inferred rather than symbol-proven.

## Open Questions With Attempted Resolution

- Exact original method name at primary `+0x44`: checked EPF/ControlPane vtables, sole xref, neighboring accepted paint/draw children, current class docs, and old reports. `OnPaint` is selected as the current project-dominant control spelling. Original spelling is not provable but no behavior/C++ blocker remains.
- Exact private member spellings: checked offsets, callers, current classes, and resource helper contracts. `m_resourceName`, `m_frameIndex`, and `m_paletteName` are descriptive and layout-exact. Confidence is capped, but source is safe.
- Exact slot-7 global typedef/name: checked both installed targets, 206-reference support docs, and representative pane paint children. `FillRect` is selected at this source call site; the full global table may retain a broader provisional type/name.
- Why explicit release appears before GrafPort base release: checked ordinary destructor, scalar wrapper, Pane teardown, and GrafPort destructor. The most defensible source is an explicit derived-body `ReleaseBuffers()` followed by automatic base destruction; the cleanup is idempotent. No alternative source body better explains the duplicate machine effect.
- Header versus implementation declaration placement: checked current file route and generated architecture. Exact original split is unavailable; current validator model places the class/formal children under one source root. No score/C++ blocker remains.
- No unresolved question affects the recommended owner, source file, range, child set, metadata, or formal blocks.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. No manual coverage-report or supervisor tracker row is requested.
- UID00011J `Item Summary`, child summaries, scores, links, and `Nested` metadata should drive validator-owned coverage/generated updates.
- B001 must not edit `by-memory/-coverage-report.md`, generated `-ag-*` reports, project trackers, or supervisor ledgers.

## Follow-Up Actions

- B001's accepted implementation callback is complete; no B001 by-*, validator, lease, generated-verification, or report-text work remains.
- Exact original private/member/method/slot typedef spellings remain confidence-capped future evidence opportunities only; they do not block the applied source shape.
- Report validation/execution/count/path/move/archive state is external supervisor/validator-owned and is neither asserted nor directed by this artifact.
- B001 did not run `execute_report`, any report lifecycle command/probe, move, or archive.

## Confidence

- Recommendation confidence: 94.
- Score confidence: 93.
- Remaining uncertainty: exact original spellings for `OnPaint`, three private members, and slot-7 typedef/name. These are documented source-facing inferences and justify the below-95 cap; they do not create binary uncertainty or a blank-code reason.

## Validator Results

- All commands ran from `source-3/project-documentation` with `--queue-timeout 240`; every command exited `0`.
- Post-validator MCP recovery verification at `2026-07-13T04:39:58-04:00` was read-only and report-only: fresh `idb_list` count `1` selected `328356ab`; `server_health`, `lookup_funcs`, three target `decompile` calls, three target `disasm` calls, four range signatures, six-target `xref_query`, vtable global reads, and both slot-7 callback analyses all returned HTTP/JSON-RPC success with MCP `isError:false`. A separate final availability check at `2026-07-13T04:48:04-04:00` again returned count `1`, session `328356ab` active, health `ok`, and analysis/Hex-Rays/strings ready. B001 did not manage the MCP process or mutate IDA, and these checks required no by-* edit or validator rerun.

| Command ID | Timestamp | Scoped command / purpose | Exit / ok | Relevant side effects and result |
| --- | --- | --- | --- | --- |
| `000000009117` | `2026-07-13T04:14:54-04:00` | `validator.py --mode file --file by-memory/0x004991f0-0x004992a8.EPFImageControlPaneConstructor.md --apply` | `0`; registration pass | Assigned UID0004JN, recorded `92/94`, owner/emitter/position/block. Validator exposed stale assumed UID00005H support link by rewriting it to its actual FrameMgr target. |
| `000000009120` | `2026-07-13T04:15:18-04:00` | Same constructor after replacing the stale support UID with actual ControlPane UID000038 | `0`; `ok:1` | Removed UID00005H reference, added UID000038; constructor page clean. |
| `000000009123` | `2026-07-13T04:16:13-04:00` | Destructor child registration | `0`; registration pass | Assigned UID0004JS and correct metadata/block. Four `missing_ref_uid` notices referred only to then-unregistered existing UID0003LN/0003LO pages, both registered later. |
| `000000009127` | `2026-07-13T04:17:42-04:00` | OnPaint child registration | `0`; registration pass | Assigned UID0004JW and correct metadata/block; six reference-index additions. |
| `000000009134` | `2026-07-13T04:20:07-04:00` | UID00011J parent | `0`; `ok:1` | Applied `92/94`, true-to-false, emitter clear, real child links. Two notices were the same pre-registration UID0003LN/0003LO condition. |
| `000000009137` | `2026-07-13T04:20:50-04:00` | UID0003LN adjustors | `0`; `ok:1` | Registered existing UID/path, applied `90/94`, NONE/false/blank autogen metadata. |
| `000000009139` | `2026-07-13T04:21:43-04:00` | UID0003LO scalar wrapper | `0`; `ok:1` | Registered existing UID/path, applied `91/94`, owner/emitter UID00004G, position 40, exact marker block. |
| `000000009143` | `2026-07-13T04:22:55-04:00` | UID00004G class | `0`; `ok:1` | Applied `92/93`, declaration block, all five exact child/glue links; validator-owned stats removals only. |
| `000000009147` | `2026-07-13T04:23:57-04:00` | UID0000J2 file | `0`; `ok:1` | Applied `91/92` and all exact source-child references/order. |
| `000000009148` | `2026-07-13T04:24:36-04:00` | UID0000QW alias | `0`; `ok:1` | Applied `90/92`, added UID0004JW reference, retained NONE/false/blank source route. |
| `000000009153` | `2026-07-13T04:25:30-04:00` | UID0000TN global callback table | `0`; `ok:1` | Score unchanged; added UID0004JW and removed stale UID0000J2 load-helper reference. Seven pre-existing notices concern unregistered unrelated UID0003ZP/UID0003XE references. |
| `000000009161` | `2026-07-13T04:26:16-04:00` | UID0001PI callback-table storage | `0`; `ok:1` | Score unchanged; added UID0004JW and current slot-7 evidence. Eight pre-existing notices concern unrelated UID0003ZP/UID0003XE/UID0003PN references. |
| `000000009172` | `2026-07-13T04:27:26-04:00` | `by-memory/-ignored.md` | `0`; `ok:1` | Added reference-index entries for UID0004JN/UID0004JS/UID0004JW. The inventory retains 329 pre-existing missing-registry notices outside this callback. |
| `000000009181` | `2026-07-13T04:28:07-04:00` | Initial `by-file/EPFImageControlPane.md --apply --wait-generated` | `0`; `ok:1`; generated completed | Exposed conservative fallback insertion before the class `};`; all payload counts were present but source placement was invalid. No generated file was edited manually. |
| `000000009187` | `2026-07-13T04:29:26-04:00` | UID00004G after adding post-class `[[CHILDREN]]` placement directive | `0`; `ok:1` | Updated only class autogen block hash; accepted C++ payloads unchanged. |
| `000000009188` | `2026-07-13T04:29:32-04:00` | Final `by-file/EPFImageControlPane.md --apply --wait-generated` | `0`; `ok:1`; generated completed | Explicitly updated `auto-generated/NexusTK/ui/controls/EPFImageControlPane.cpp`; validator-owned refresh only. |

- Generated header observed immediately after B001's waited completion was validator command `000000009189`, refreshed `2026-07-13T04:29:33-04:00`, one second newer than waited command `000000009188` due to a validator-owned refresh. The final artifact audit at `2026-07-13T04:46:03-04:00` observed later external foreground refresh command `000000009222`; its source order and payload were unchanged and newer than the authorized waited check. This is timestamped generated evidence, not an indefinite current-header assertion.
- Final generated order/line proof: class line 8, closing `};` line 24, constructor line 26, ordinary destructor line 43, OnPaint line 49, scalar covered-by marker line 74.
- Final generated exact counts: class `1`; constructor `1`; ordinary destructor `1`; OnPaint `1`; scalar marker `1`; UID00011J `0`; `Empty Emitter Marker` `0`; `LoadAndRenderImage` `0`; `g_pfnLockSurface` `0`; unresolved `[[CHILDREN]]` `0`.
- The generated output preserves constructor call/assignment order, destructor release, paint invalid-frame branch, borrowed frame behavior, palette/blit arguments, and unconditional final mask build.
- Unresolved validator notices are pre-existing registry hygiene in shared callback/ignored pages, not callback defects. All scoped commands returned exit `0` and `ok:1` where the validator emits an `ok` counter.

## Changed Files

- Created and validator-registered:
  - `by-memory/0x004991f0-0x004992a8.EPFImageControlPaneConstructor.md` as UID0004JN.
  - `by-memory/0x004992b0-0x0049930e.EPFImageControlPaneDestructor.md` as UID0004JS.
  - `by-memory/0x00499310-0x004993a5.EPFImageControlPaneOnPaint.md` as UID0004JW.
- Modified and scoped-validated: UID00011J parent, `by-class/EPFImageControlPane.md`, `by-file/EPFImageControlPane.md`, UID0003LN, UID0003LO, UID0000QW, UID0000TN, UID0001PI, and `by-memory/-ignored.md`.
- Modified report: `tools/leaser/Agents/Agent-B001/research/00011J-EPFImageControlPaneCore-empty-emitter-source-quality.md`.
- Renamed: none.
- Protected unchanged: UID000172/174, UID0002KP, ControlPane/Pane/GrafPort/EPFTileContext/PaletteLib/ImageLib support, UID00011K, generated/coverage/tracker/supervisor/validator-state/lifecycle/IDA files by manual edit.
- Validator-owned side effects: generated C++/coverage/research-tracker refreshes. B001 manually edited none of those artifacts; only `auto-generated/NexusTK/ui/controls/EPFImageControlPane.cpp` was read for final content proof.
- Leases: one short edit lease at a time. A malformed cleanup invocation looked for `leaser.py` from the documentation root and changed nothing; the correct release immediately succeeded. Final current lease report contains no B001 row.
- Report execution/lifecycle: B001 did not run `execute_report`, lifecycle probes/commands, move, or archive.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation is recorded.
- [x] Target/support docs to update are enumerated with exact paths and dispositions.
- [x] Current target state and actual evidence checked are recorded.
- [x] Claim And Incorporation Ledger contains destination and report-only verification state for C11J-001 through C11J-032.
- [x] Metadata/score changes are exact for parent, new children, class, file, glue, and alias support.
- [x] Score-limiting blockers were researched to source-ready resolutions; remaining spelling uncertainty is confidence-capped, not deferred.
- [x] Owner/emitter/reconstructable changes are exact.
- [x] Split/new-child changes include exact paths, ranges, positions, serial registration, and no fabricated UIDs.
- [x] Source placement, padding, reclassification, and source-facing rename/type directions are complete.
- [x] Five destination-specific managed C++ blocks are supplied; parent/adjustor no-code dispositions are explicit.
- [x] Third-party import directive is confirmed not applicable.
- [x] Exact target/support facts are specified at report-level detail.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence are preserved.
- [x] Wave2/Wave3 artifacts were not used as current authority.
- [x] Open questions were attempted and closed to defensible source directions with confidence caps.
- [x] Callback validators are specified: one scoped validator per changed by-* page and final authorized `--wait-generated` verification.
- [x] Generated refresh expectation is exact; no manual coverage/tracker text is needed.

Implementation callback pass:

- [x] Exact Gate-1 report SHA accepted by supervisor for implementation.
- [x] Three child pages created and registered serially; actual UID0004JN/UID0004JS/UID0004JW captured before link insertion.
- [x] All accepted target/support details incorporated at report-level detail without substantive compression.
- [x] Claim ledger updated from report-only recommendation to applied/already-present/excluded proof for C11J-001 through C11J-032.
- [x] Metadata/score/owner/emitter/split/C++ changes applied exactly.
- [x] Five accepted managed payloads preserved; post-class `[[CHILDREN]]` directive added only to make generated insertion structurally correct.
- [x] Historical assumptions, rejected alternatives, negative evidence, prior C001 boundary provenance, and UID00011K exclusion preserved.
- [x] Open questions retained as confidence caps rather than stale blockers.
- [x] One scoped validator run for every changed by-* page; command IDs/timestamps/exits/ok and relevant side effects recorded.
- [x] Initial generated fallback placement defect detected and repaired without manual generated editing.
- [x] Final waited generated refresh verified exact ordering/content, singular body counts, and absence of UID00011J Empty Emitter Marker/aggregate duplicate.
- [x] Leases released immediately after each scoped edit/validator; final lease report has no B001 row.
- [x] Same report updated with actual UIDs, validator results, changed files, generated freshness/count proof, and checked callback rows.
- [x] No manual generated/coverage/tracker/supervisor/validator-state/IDA edit and no execute/lifecycle/move/archive command occurred.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000009226","destination_path":"executed-b-agent-research/B001/00011J-EPFImageControlPaneCore-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/00011J-EPFImageControlPaneCore-empty-emitter-source-quality.md","timestamp":"2026-07-13T04:55:05-04:00","uid":"00011J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
