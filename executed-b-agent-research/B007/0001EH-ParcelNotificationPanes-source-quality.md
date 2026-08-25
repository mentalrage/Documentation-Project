** TARGET-REPORT-UID:0001EH **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001EH ParcelNotificationPanes Ownership / Split Research

## Finalized Report / Current Recommendation

- Current recommendation: reclassify [UID:0001EH] `by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md` from a reconstructable/emitting aggregate to a non-emitting mixed split/index page, and create one missing exact raw-helper child for `0x005460f0-0x005461c0`.
- Final disposition for [UID:0001EH]: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal `RECONSTRUCTION_CPP CODE`.
- Required action: preserve the `ParcelPane.cpp` source-family placement in support docs, but do not let the aggregate itself emit source. Exact child pages carry or block source emission individually.
- Confidence: high for range, child inventory, mixed-container decision, and PatchPane exclusion. Medium-high for the missing raw helper's source-facing role because IDA has no function object and no entry xref for `0x005460f0`.

## Target

- Target UID: `0001EH`.
- Target path: `by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md`.
- Assignment: B007 report-only research for the corrected live path. The goal explicitly warns that generated tracker rows may still show stale `0x005470ac`; do not recreate the stale filename.
- Current metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000MF`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000MF`, blank formal C++.
- Current page state: the page already documents most exact child rows and the `0x005470ad` half-open boundary, but its header still says the broad aggregate is reconstructable/emitting through [UID:0000MF] `by-file/ParcelPane.md`.

## Current Target State

- The target is a broad executable island covering `ParcelIconPane`, `ParcelPane`, `FlyingParcelPane`, raw helper code, compiler cleanup funclets, adjustor thunks, scalar deleting destructor wrappers, and padding.
- It is not a single source-level method, class, global, data object, vtable, or file-scope helper.
- The existing "Container handling" prose already warns not to paste child method C++ into the aggregate. The metadata should match that prose by setting the page non-reconstructable and non-emitting.
- A real executable subrange, `0x005460f0-0x005461c0`, remains documented only as an adjacent raw helper in [UID:0001EJ] and [UID:0000A5], not as its own by-memory child page. This is the main split repair still required before the aggregate child inventory is complete.
- Several support pages still carry stale "class below gate" or `95/95` code-gate language even though current headers already attach `ParcelIconPane` constructor/destructor/scalar-destructor pages to [UID:0000A5], and current by-structure uses the combined-score/emitter gate, not the old `95/95` rule.

## Supervisor Active Recheck

- The user assigned a report-only pass only. No by-* docs, generated files, coverage reports, validator state, tool state, IDA DB state, or project-level files were edited.
- MCP evidence was mandatory. IDA MCP was available and responsive.
- This assignment did not authorize split execution before supervisor acceptance, so the missing child page is proposed here as implementation-callback work rather than created now.

## Inference Research Guidance Check

- `by-structure.md` distinguishes semantic ownership from emission routing. A broad by-memory page may be `RECONSTRUCTABLE:FALSE` when it is only an audit/container over exact children, compiler artifacts, padding, or mixed-source neighborhoods.
- `by-structure.md` also says not to guess UIDs. The new `0x005460f0-0x005461c0` child must be created through the validator UID workflow; references to it from other docs must either be added after validation assigns the UID or authored with a TMP reference.
- Older `AUTOGEN_PARENT_UID` notes are stale combined parent/output terminology. They should be interpreted as current `CANONICAL_OWNER` only where they discuss ownership, and as `EMITTER_UIDS` only where they discuss output routing.
- Older `95/95` or `90/90+` final-C++ gate text is stale. Current C++ eligibility is the combined-score/emitter route rule, but eligibility is only a minimum. Weak raw helper route proof or mixed-container scope still requires blank formal C++.
- No Wave2/Wave3 instruction was used as authority. Old generated pollution and tracker rows were treated as stale unless corroborated by live MCP and current by-* docs.

## Evidence Checked

- MCP session: `80de0a67`, active worker session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- MCP health: `server_health` reported `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, module `NexusTK.exe`, imagebase `0x400000`.
- MCP tools used: `lookup_funcs`, `decompile`, `insn_query`, `get_bytes`, `xrefs_to`, and `int_convert` for sanity checks on selected addresses. No write-capable MCP tools were used.
- Key by-* docs checked: target, `by-file/ParcelPane.md`, `by-class/ParcelPane.md`, `by-class/ParcelIconPane.md`, `by-class/FlyingParcelPane.md`, `by-type/by-vtable/ParcelNotificationVtableFamily.md`, `by-type/by-struct/ParcelNotificationPaneLayouts.md`, `by-global/g_pParcelPane.md`, `by-global/g_pParcelIconPane.md`, exact child by-memory pages, [UID:0001EL] `FlyingParcelPaneRawLifecycleAndStart`, and [UID:0001DE] `LivingObjectPaneCore` as a broad non-emitting container precedent.
- Generated/tracker state checked: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and manual `by-memory/-coverage-report.md` still contain stale `0x005470ac` rows. These are not to be edited manually in this pass.
- Negative checks: `rg` found no existing by-memory page for `0x005460f0-0x005461c0`; current docs only mention it in `by-class/ParcelIconPane.md` and [UID:0001EJ].

## IDA MCP Facts

- `lookup_funcs` confirms IDA function starts and sizes:
  - `0x00545e40` -> `sub_545E40`, size `0x22a`.
  - `0x00546070` -> `sub_546070`, size `0x78`.
  - `0x005461c0` -> `sub_5461C0`, size `0xcd`.
  - `0x00546290` -> `sub_546290`, size `0x1a6`.
  - `0x00546440` -> `sub_546440`, size `0x6c`.
  - `0x005464b0` -> `sub_5464B0`, size `0xc5`.
  - `0x005465e0` -> `sub_5465E0`, size `0x2a`.
  - `0x00546610` -> `sub_546610`, size `0x1f7`.
  - `0x00546810` -> `sub_546810`, size `0x78`.
  - `0x00546890` -> `sub_546890`, size `0xdf`.
  - `0x00546970` -> `sub_546970`, size `0x6b`.
  - `0x005469e0` -> `sub_5469E0`, size `0xcb`.
  - `0x00546ac0` -> `sub_546AC0`, size `0xb4`.
  - `0x00546b80` and `0x00546bc0` -> not IDA functions.
  - `0x00546d70` -> `sub_546D70`, size `0x7e`.
  - `0x00546df0` -> `sub_546DF0`, size `0x7b`.
  - `0x00546e70`, `0x00546e80`, and `0x00546e8b` -> 11-byte modeled entries.
  - `0x00546ed0` -> `sub_546ED0`, size `0x67`.
  - `0x00546f40` -> `sub_546F40`, size `0xb9`.
  - `0x00547000` -> `sub_547000`, size `0xad`.
  - `0x005470ac` is inside `sub_547000`; `0x005470ad` is not a function.
  - `0x005470b0` -> `sub_5470B0`, size `0x33d`.
- MCP decompile confirms class/source roles:
  - `0x00545e40` constructs `ParcelIconPane`, publishes `unk_69B4D0`, allocates `0x124` bytes for child `ParcelPane`, publishes `unk_69BA28`, writes `ParcelPane` vtables, initializes button rectangles, sets pane order, and schedules the initial 100 ms timer through `sub_5975E0`.
  - `0x005461c0` is a `thiscall` callback reached from the `ParcelIconPane` secondary vtable, reads event payload at `a2+12`, validates first byte `8`, decodes packed counts, writes owner bytes at `+0x58/+0x59/+0x5a`, loads child pointer at `+0x5c`, and calls `sub_5464B0`.
  - `0x00546290` constructs standalone `ParcelPane`, publishes `unk_69BA28`, initializes fields and button rectangles, calls paint/order helpers, and schedules the initial timer.
  - `0x005464b0` is `ParcelPane::SetParcelSlotData` behavior: reset/invalidate, write accepted/current counts, reset animation bytes, build rect `630,726,698,751`, conditionally show, and attach its child rect.
  - `0x00546610` is `ParcelPane` mouse/input handling over parcel button rectangles and state bytes, including sound/dialog side effects.
  - `0x00546810` is a timer/animation step that checks state bytes and schedules the next 200 ms timer.
  - `0x00546890` paints alert button resources `ALERTBTN.EPF` and `ALERTBTN.PAL`.
  - `0x00546ac0` constructs `FlyingParcelPane`, writes `FlyingParcelPane` vtables, clears fields at `+0xf8/+0xfc`, allocates an 8-byte child/resource object, and stores it at `+0x100`.
  - `0x00546d70` advances a flying parcel animation, schedules 10 ms steps until count `0x1e`, then removes the child resource, calls `sub_5464B0` on `g_pParcelPane`, and invalidates the parcel pane.
  - `0x00546df0` draws either `ALERTBTN.EPF/PAL` or `LETTER.EPF/PAL`.
  - `0x00546e70` and `0x00546e80` are one-store singleton clear funclets for `unk_69B4D0` and `unk_69BA28`.
  - `0x00546ed0`, `0x00546f40`, and `0x00547000` are scalar deleting destructor wrappers for `FlyingParcelPane`, `ParcelIconPane`, and `ParcelPane`.
  - `0x005470b0` starts `PatchPane` construction, with `PatchPane` vtables, "Auto Patch" setup, and PatchPane-specific memory layout. It is not parcel notification code.
- MCP raw range facts:
  - `0x005460e8-0x005460f0` is eight `0xcc` bytes.
  - `0x005460f0-0x005461c0` is executable code not modeled as an IDA function. It starts with `push ebp; mov ebp, esp; sub esp, 0Ch; push ebx; push esi; push edi`, decodes packed parcel counts from a direct payload pointer, writes owner fields at `+0xf8/+0xf9/+0xfa`, loads child pointer at `+0xfc`, calls `sub_5464B0` at `0x005461b0`, returns zero, and ends with `retn 4` at `0x005461bd`.
  - `xrefs_to 0x005460f0` reports no xrefs; this is a no-modeled-function/no-entry-route raw helper.
  - `0x00546b74-0x00546b80`, `0x00546bb5-0x00546bc0`, and `0x00546d64-0x00546d70` are `0xcc` alignment around the two raw FlyingParcelPane lifecycle/start bodies.
  - `get_bytes 0x005470a0 size 32` shows the `sub_547000` tail ending before three `0xcc` bytes at `0x005470ad-0x005470b0`, followed by `0x55 0x8b 0xec...` for the PatchPane successor.
- MCP xrefs:
  - `xrefs_to 0x005461c0` -> data xref `0x00621c10`, confirming vtable callback route.
  - `xrefs_to 0x005464b0` -> raw helper call at `0x005461b0`, callback call at `0x00546274`, and FlyingParcelPane animation call at `0x00546dcd`.
  - `xrefs_to 0x00546d70` -> data xref `0x00621d4c`, a FlyingParcelPane vtable slot.
  - `xrefs_to 0x00546df0` -> data xref `0x00621d10`, a FlyingParcelPane secondary-table slot.
  - `xrefs_to 0x00547000` -> adjustor-thunk refs at `0x00546ebd` and `0x00546ec8`, plus ParcelPane vtable data xref `0x00621c3c`.
  - `xrefs_to 0x005470b0` -> construction caller in `sub_4F6D80`, not a parcel vtable/global route.
  - Vtable address xrefs separate the three classes: `0x00621bb4` for ParcelIconPane, `0x00621c3c` for ParcelPane, `0x00621ccc` for FlyingParcelPane, and `0x00621d50` for `ALERTBTN.EPF` string/resource data rather than a parcel vtable slot.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Current Status |
| --- | --- | --- | --- | --- | --- |
| `0x00545e40-0x0054606a` | [UID:0001EG] `by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md` | ParcelIconPane constructor and inline child ParcelPane setup | TRUE | `0000A5` | Correct owner in header; stale summary/change text still says file parent/class below gate and old `95/95` blank-C++ gate. |
| `0x00546070-0x005460e8` | [UID:0001EI] `by-memory/0x00546070-0x005460e8.ParcelIconPaneDestructor.md` | ParcelIconPane non-deleting destructor | TRUE | `0000A5` | Correct owner in header; stale summary/change text still says file parent/class below gate and old `95/95` blank-C++ gate. |
| `0x005460e8-0x005460f0` | no page | padding | FALSE / ignored span | none | Eight bytes of `0xcc`; should be documented as padding in parent/raw-helper evidence, not a child page. |
| `0x005460f0-0x005461c0` | proposed new `by-memory/0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper.md` | IDA-missed ParcelIconPane raw parcel-count update helper | TRUE, no C++ | `0000A5`, blank emitter until route/name proof | Missing exact by-memory child. Create through validator UID workflow; do not guess UID. |
| `0x005461c0-0x0054628d` | [UID:0001EJ] `by-memory/0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback.md` | ParcelIconPane secondary-vtable callback wrapping the same packed-count update through event payload | TRUE | currently `0000MF`, should be `0000A5` | Owner/emitter should be corrected to `0000A5`; stale class-gate/`95/95` text should be removed. |
| `0x00546290-0x00546436` | [UID:0002KB] `by-memory/0x00546290-0x00546436.ParcelPaneConstructor.md` | ParcelPane constructor | TRUE | `0000A6` | Already source-bearing child with formal C++. |
| `0x00546440-0x005464ac` | [UID:0001EK] `by-memory/0x00546440-0x005464ac.ParcelPaneDestructor.md` | ParcelPane non-deleting destructor | TRUE | `0000A6` | Child page remains exact; formal C++ blank. |
| `0x005464b0-0x00546575` | [UID:0002KC] `by-memory/0x005464b0-0x00546575.ParcelPaneSetParcelSlotData.md` | ParcelPane slot/count updater | TRUE | `0000A6` | Already source-bearing child with formal C++. |
| `0x005465e0-0x0054660a` | [UID:0002KD] `by-memory/0x005465e0-0x0054660a.ParcelPaneOnKeyDown.md` | ParcelPane key handler | TRUE | `0000A6` | Exact child; C++ blank because behavior/source shape remains blocked. |
| `0x00546610-0x00546807` | [UID:0002KE] `by-memory/0x00546610-0x00546807.ParcelPaneOnMouseEvent.md` | ParcelPane mouse/event handler | TRUE | `0000A6` | Exact child; C++ blank. |
| `0x00546810-0x00546888` | [UID:0002KF] `by-memory/0x00546810-0x00546888.ParcelPaneProcessSlotAnimations.md` | ParcelPane timer/animation step | TRUE | `0000A6` | Exact child; C++ blank pending timer wrapper/signature shape. |
| `0x00546890-0x0054696f` | [UID:0002KG] `by-memory/0x00546890-0x0054696f.ParcelPaneOnPaint.md` | ParcelPane paint method | TRUE | `0000A6` | Already source-bearing child with formal C++. |
| `0x00546970-0x005469db` | [UID:0002KH] `by-memory/0x00546970-0x005469db.ParcelPaneUpdateAnimationCounter.md` | ParcelPane frame counter helper | TRUE | `0000A6` | Exact child; C++ blank. |
| `0x005469e0-0x00546aab` | [UID:0002KI] `by-memory/0x005469e0-0x00546aab.ParcelPaneGetButtonFrameIndex.md` | ParcelPane button frame helper | TRUE | `0000A6` | Exact child; C++ blank. |
| `0x00546ac0-0x00546b74` | [UID:0002KJ] `by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md` | FlyingParcelPane constructor | TRUE | `000058` | Already source-bearing child with formal C++. |
| `0x00546b80-0x00546bb5` | [UID:0002R5] `by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md` | Raw FlyingParcelPane cleanup body | TRUE | `000058` | Exact raw child; C++ blank due raw/no-function/source route caveats. |
| `0x00546bc0-0x00546d64` | [UID:0002R6] `by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md` | Raw FlyingParcelPane start/delivery-animation body | TRUE | `000058` | Exact raw child; C++ blank. |
| `0x00546b80-0x00546d64` | [UID:0001EL] `by-memory/0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart.md` | Non-emitting split inventory over [UID:0002R5]/[UID:0002R6] | FALSE | `000058` | Good precedent for [UID:0001EH] as a non-emitting parent/container. |
| `0x00546d70-0x00546dee` | [UID:0002KK] `by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md` | FlyingParcelPane animation step | TRUE | `000058` | Already source-bearing child with formal C++. |
| `0x00546df0-0x00546e6b` | [UID:0002KL] `by-memory/0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md` | FlyingParcelPane draw helper | TRUE | `000058` | Already source-bearing child with formal C++. |
| `0x00546e70-0x00546e7b` | [UID:0002KM] `by-memory/0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton.md` | Compiler/EH cleanup funclet clearing `g_pParcelIconPane` | FALSE | NONE | Correctly non-emitting. |
| `0x00546e80-0x00546e8b` | [UID:0002KN] `by-memory/0x00546e80-0x00546e8b.ClearParcelPaneSingleton.md` | Compiler/EH cleanup funclet clearing `g_pParcelPane` | FALSE | NONE | Correctly non-emitting; one support global row still calls it a compact file-scope clear helper. |
| `0x00546e8b-0x00546ecd` | [UID:0001EM] `by-memory/0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks.md` | Compiler-generated destructor adjustor thunks | FALSE | NONE | Correctly non-emitting. |
| `0x00546ed0-0x00546f37` | [UID:0001EN] `by-memory/0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md` | FlyingParcelPane scalar deleting destructor wrapper | TRUE | `000058` | Exact wrapper child; formal C++ blank because source ordinary destructor should generate it. |
| `0x00546f40-0x00546ff9` | [UID:0001EO] `by-memory/0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor.md` | ParcelIconPane scalar deleting destructor wrapper | TRUE | `0000A5` | Correct owner in header; stale summary/change text still says file parent/class below gate and old `95/95` blank-C++ gate. |
| `0x00547000-0x005470ad` | [UID:0001EP] `by-memory/0x00547000-0x005470ad.ParcelPaneScalarDeletingDestructor.md` | ParcelPane scalar deleting destructor wrapper | TRUE | `0000A6` | Exact wrapper child. |
| `0x005470ad-0x005470b0` | no page | padding before PatchPane | FALSE / ignored span | none | Three bytes of `0xcc`; intentionally excluded from target. |
| `0x005470b0+` | [UID:0000MH] `by-file/PatchPane.md` area | PatchPane successor | not part of target | PatchPane | Must not be merged into the parcel aggregate. |

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Remaining uncertainty |
| --- | --- | --- | --- | --- |
| [UID:0001EH] is a mixed non-emitting container, not a source emitter | High | Multiple owners, compiler funclets, adjustor thunks, scalar wrappers, raw no-function ranges, padding, and exact child pages; by-structure `RECONSTRUCTABLE:FALSE` container rule | Current header owner/emitter `0000MF`; old B001 note saying not to reclassify solely from the timer/frame pass | None for parent non-emitter after this full aggregate pass. |
| `ParcelPane.cpp` remains the source-family/file placement | High | `by-file/ParcelPane.md`, contiguous class island, shared globals/resources, exact children route through ParcelIconPane/ParcelPane/FlyingParcelPane to file page | Single aggregate owner/emitter to `0000MF` | Source-family placement is retained; only aggregate metadata changes to non-emitting. |
| `0x005460f0-0x005461c0` is real raw code needing its own child | High | MCP `insn_query`, `get_bytes`, no function at start, `sub_5464B0` call, `retn 4`, existing docs mention missing exact page | Possibility it is padding or part of [UID:0001EJ] | Not padding and not in [UID:0001EJ] range. No entry xref remains. |
| New raw helper direct owner is `ParcelIconPane` | Medium-high | Writes owner fields `+0xf8/+0xf9/+0xfa`, reads child pointer `+0xfc`, mirrors callback payload decode, adjacent to ParcelIconPane destructor/callback, existing class page already names it ParcelIconPane-related | No entry xref and no IDA function object | Exact original name/signature/route unresolved, so emitter stays blank and C++ stays blank. |
| [UID:0001EJ] should be owned/emitted by [UID:0000A5] | High | Secondary vtable data xref `0x00621c10`, owner fields `+0x58/+0x59/+0x5a`, child pointer `+0x5c`, callback role documented by class page | Current metadata `0000MF`; old class-below-gate line | Class now clears the current attachment gate; no need to force file owner. |
| `0x005470ad` is the correct parent end | Very high | `lookup_funcs`: `0x005470ac` inside `sub_547000`, `0x005470ad` not a function, `0x005470b0` starts PatchPane; bytes show `0xcc` padding | Stale tracker/manual rows at `0x005470ac` | None. |

## Positive Evidence Summary

- The aggregate is strongly documented as the parcel notification executable island: it contains all known ParcelIconPane, ParcelPane, and FlyingParcelPane bodies and ends before PatchPane.
- Exact child pages already exist for nearly every source-bearing child and compiler-generated child. Several children now carry formal C++; several correctly carry blank no-code proofs.
- The missing `0x005460f0-0x005461c0` helper is a bounded, well-understood raw body with exact pre-padding, exact tail return, no modeled function, and clear `ParcelIconPane` field behavior.
- [UID:0001EL] `FlyingParcelPaneRawLifecycleAndStart` and [UID:0001DE] `LivingObjectPaneCore` prove the current documentation pattern: broad mixed by-memory pages can and should become non-emitting split/index pages when exact children carry the real source decisions.
- Vtable and global evidence separates three class owners while preserving one `ParcelPane.cpp` source-family grouping.

## Negative Evidence Summary

- Reject current aggregate emitter `0000MF`: `ParcelPane.cpp` is the source-family route, but [UID:0001EH] is not itself a file-scope source object. Emitting it would either duplicate exact child source or require an artificial source body that mixes classes, thunks, funclets, wrappers, raw no-function fragments, and padding.
- Reject `ParcelPane` class [UID:0000A6] as aggregate owner: much of the range is `ParcelIconPane`, `FlyingParcelPane`, compiler cleanup, and padding.
- Reject `ParcelIconPane` class [UID:0000A5] as aggregate owner: it owns the constructor/destructor/callback/raw helper/scalar wrapper, but not ParcelPane and FlyingParcelPane bodies.
- Reject `FlyingParcelPane` class [UID:000058] as aggregate owner: it owns only the `0x00546ac0-0x00546f37` subset plus related raw children.
- Reject treating `0x005460f0-0x005461c0` as padding: MCP disassembly shows real instructions and a `sub_5464B0` call.
- Reject folding `0x005460f0-0x005461c0` into [UID:0001EJ]: [UID:0001EJ] starts exactly at `0x005461c0` and has a different event-wrapper signature; the raw helper ends at `0x005461c0` and is a separate code-shaped body.
- Reject folding `0x005470ad-0x005470b0` into parcel source: it is `0xcc` padding.
- Reject extending the aggregate to `0x005470b0+`: MCP decompile of `0x005470b0` shows PatchPane construction and PatchPane vtables/resources.
- Reject old `0x005470ac` rows in generated/manual trackers: they are stale views of the old filename/range and should be refreshed through validator lifecycle, not manually recreated.
- Reject old support-page "class below gate" wording for ParcelIconPane children: [UID:0000A5] is now `85/86`, and the exact child headers already use `CANONICAL_OWNER:0000A5`.
- Reject old `95/95` final-C++ gate language: current by-structure uses combined score and emitter route, but the relevant pages still stay blank for target-specific no-code reasons.

## Ranked Ownership Analysis

### 1. Non-emitting container with `CANONICAL_OWNER:NONE`

- Evidence for: mixed class owners, compiler-generated children, raw helper islands, padding, scalar destructor wrappers, and exact child pages. This matches `by-structure.md` guidance for broad mixed by-memory containers.
- Evidence against: the family source route is still `ParcelPane.cpp`.
- Decision: best disposition for [UID:0001EH]. Keep source placement in docs, but set owner none and no emitter so the page cannot generate artificial aggregate C++.

### 2. [UID:0000MF] `by-file/ParcelPane.md`

- Evidence for: original source-family/file grouping is likely `ParcelPane.cpp`; all classes share parcel globals/resources and are contiguous before PatchPane.
- Evidence against: a by-file route is too broad for the aggregate's semantic owner and would imply output routing for a non-source object.
- Decision: keep as source-family support, reject as `CANONICAL_OWNER`/`EMITTER_UIDS` for the aggregate.

### 3. [UID:0000A5] ParcelIconPane, [UID:0000A6] ParcelPane, [UID:000058] FlyingParcelPane

- Evidence for: each class owns real child ranges inside the aggregate.
- Evidence against: no class owns the whole range.
- Decision: use these as exact child owners only. Do not assign them to the parent aggregate.

## Source Placement

- Recommended source file placement: keep the family under `NexusTK/ui/panels/ParcelPane.cpp` as documented by [UID:0000MF].
- Recommended target placement: [UID:0001EH] should say it is a non-emitting by-memory container/index for the parcel notification executable island.
- Recommended child placement:
  - New raw helper `0x005460f0-0x005461c0` should be a `ParcelIconPane`-owned by-memory child under [UID:0000A5], with blank `EMITTER_UIDS` until original entry route/source signature proof improves.
  - [UID:0001EJ] should also move from file owner/emitter `0000MF` to class owner/emitter `0000A5`.
- Rejected placement: new standalone by-file page. The existing file page already covers `ParcelPane.cpp`, and the raw helper has class-local field behavior.

## Range / Split / Padding / Reclassification Analysis

- Exact aggregate range remains `0x00545e40-0x005470ad`.
- Required new child split:
  - Create `by-memory/0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper.md`.
  - Do not guess a UID. Create through validator UID workflow.
  - Recommended initial metadata after UID assignment: `COMPLETION:84`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000A5`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank formal C++.
  - Recommended item summary: IDA-missed ParcelIconPane raw parcel-count update helper; exact raw code starts after eight bytes of `0xcc` padding, decodes packed direct payload counts, updates `ParcelIconPane` fields `+0xf8/+0xf9/+0xfa`, reads child pointer `+0xfc`, calls `ParcelPane::SetParcelSlotData` at `0x005461b0`, returns zero with `retn 4`, and remains non-emitting because no modeled function/start xref/source signature is proven.
- Required parent reclassification:
  - [UID:0001EH] should become `RECONSTRUCTABLE:FALSE` with blank emitter and blank C++.
  - Parent should preserve all child rows and add the new raw helper row plus the pre-padding evidence.
- Boundary and padding facts to preserve:
  - `0x005460e8-0x005460f0`: eight `0xcc` bytes after ParcelIconPane destructor and before the raw helper.
  - `0x005460f0-0x005461c0`: raw helper code, not padding.
  - `0x00546b74-0x00546b80`: alignment before FlyingParcelPane cleanup raw body.
  - `0x00546bb5-0x00546bc0`: alignment between FlyingParcelPane cleanup raw body and start-animation raw body.
  - `0x00546d64-0x00546d70`: alignment before `FlyingParcelPane::AnimateStep`.
  - `0x00546e70-0x00546e7b` and `0x00546e80-0x00546e8b`: singleton clear funclets, not handwritten helpers.
  - `0x00546e8b-0x00546ecd`: adjustor thunks, not source-authored methods.
  - `0x005470ad-0x005470b0`: `0xcc` padding, excluded.
  - `0x005470b0`: PatchPane successor, excluded.

## IDA Rename / Type / Comment Recommendations

- No IDA DB edits are requested or safe in this report-only pass.
- Source-facing names to document, not necessarily IDA-renamed:
  - `0x005460f0-0x005461c0`: `ParcelIconPaneParcelUpdateRawHelper` as a descriptive by-memory filename. Mark source name unproven.
  - `0x005461c0-0x0054628d`: `ParcelIconPaneParcelUpdateCallback`; direct owner [UID:0000A5].
  - `0x00546e70-0x00546e7b` and `0x00546e80-0x00546e8b`: compiler/EH singleton clear funclets, not source helpers.
- Generated placeholders to resolve in docs:
  - `sub_5464B0` should be documented as `ParcelPane::SetParcelSlotData` where already accepted.
  - `unk_69B4D0` / `unk_69BA28` should be documented as `g_pParcelIconPane` / `g_pParcelPane` in source-facing prose.
  - Old false vtable/string pollution at `0x00621d50` should remain rejected as `ALERTBTN.EPF` resource data, not a vtable slot.

## First-Draft C++ Recommendation

- Eligible for draft C++: no aggregate C++ for [UID:0001EH].
- Recommended code: none. This report intentionally includes no C++ snippet for the aggregate.
- Reason code should remain blank: the target is a mixed by-memory container/index over exact child functions, raw no-function helpers, compiler cleanup funclets, adjustor thunks, scalar deleting destructor wrappers, padding, and the boundary before a different PatchPane source family.
- Exact no-code proof: there is no original source construct corresponding to "ParcelNotificationPanes" as a single body. Any formal code in [UID:0001EH] would duplicate child pages or synthesize a fake wrapper around unrelated class methods and compiler artifacts. The correct source path is child-level formal C++ or child-level no-code proofs, routed through ParcelIconPane/ParcelPane/FlyingParcelPane and ultimately `ParcelPane.cpp` when individually safe.
- New raw helper C++: the proposed child should also keep formal C++ blank for now because MCP found no function object or entry xref for `0x005460f0`, the original source signature/name is unproven, and the helper mirrors [UID:0001EJ] but has a direct-payload signature that is not yet tied to a source call route.

## Recommended Target Doc Changes

- Path: `by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md`.
- Metadata:
  - `COMPLETION:88`
  - `CONFIDENCE:91`
  - `CANONICAL_OWNER:NONE`
  - `RECONSTRUCTABLE:FALSE`
  - blank `EMITTER_UIDS`
  - blank formal `RECONSTRUCTION_CPP CODE`
- Item Summary: replace "reconstructable family aggregate" wording with a non-emitting container/index summary that mentions ParcelIconPane, ParcelPane, FlyingParcelPane, raw helper children, compiler cleanup/thunk/wrapper children, padding, exact child pages, and PatchPane exclusion.
- Status: change disposition from "reconstructable NexusTK project code" to "reviewed non-emitting mixed by-memory container/source-family index"; retain `ParcelPane.cpp` as source-family placement.
- Covered Functions:
  - Add `0x005460e8-0x005460f0` padding evidence in text.
  - Add new `0x005460f0-0x005461c0` proposed child row after [UID:0001EI].
  - Keep all existing exact child rows, but make clear exact children own source decisions.
- Evidence:
  - Add MCP session `80de0a67` current-pass evidence for raw helper gap, no function/xref, `sub_5464B0` call, `retn 4`, and bytes.
  - Preserve boundary evidence for `0x005470ad` and PatchPane successor.
- Ownership/score rationale:
  - Replace current file-owner/emitter rationale with mixed-container owner none rationale.
  - Preserve rejected alternatives and historical stale assumptions: old B001 partial "do not reclassify solely from timer/frame pass" caveat, stale `0x005470ac` tracker rows, old generated source pollution, false `0x00621d50` vtable slot.

## Recommended Support Doc Changes

- `by-memory/0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper.md`
  - Create as a new by-memory child through the validator UID workflow; do not hand-write or guess UID.
  - Document exact range, no-function status, no entry xrefs, pre-padding, direct payload decode, field writes `+0xf8/+0xf9/+0xfa`, child pointer `+0xfc`, `ParcelPane::SetParcelSlotData` call at `0x005461b0`, zero return, `retn 4` tail, owner [UID:0000A5], blank emitter, blank C++.
- `by-memory/0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback.md`
  - Change `CANONICAL_OWNER` and `EMITTER_UIDS` from `0000MF` to `0000A5`.
  - Replace stale "class below parent-attachment gate" and `95/95` final-code-gate wording with current evidence: secondary-vtable callback, class owner now valid, formal C++ blank because packet/event wrapper type, exact source signature, raw helper pairing, and field names are still not source-final.
  - Link to the new raw helper child once its UID exists.
- `by-class/ParcelIconPane.md`
  - Update raw-helper blocker wording: `0x005460f0-0x005461c0` should no longer be "needs its own exact by-memory page" after callback; it should be "exact child exists but remains no-entry/no-function/non-emitting pending source route/signature".
  - Add/confirm [UID:0001EJ] class ownership and new raw helper child ownership.
  - Keep broad class formal C++ blank; remaining blockers are field/helper names, raw helper route/signature, packet/event wrapper type, and declaration shape.
- `by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md`
  - Remove stale Item Summary/change-note wording saying parent attachment goes to `0000MF` because class UID `0000A5` is below the gate.
  - Preserve current header owner/emitter `0000A5`.
  - Replace old `95/95` blank-C++ rationale with current no-code proof: constructor source shape is real but final C++ remains blank because child allocation/helper/member names and declaration shape are not source-final despite current score/emitter eligibility.
- `by-memory/0x00546070-0x005460e8.ParcelIconPaneDestructor.md`
  - Same stale class-gate/`95/95` cleanup as constructor.
  - Preserve owner/emitter `0000A5` and blank C++.
- `by-memory/0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor.md`
  - Same stale class-gate/`95/95` cleanup as constructor/destructor.
  - Preserve owner/emitter `0000A5`; formal C++ remains blank because scalar deleting destructor wrapper should be generated from ordinary destructor semantics, not emitted as handwritten source.
- `by-file/ParcelPane.md`
  - Update [UID:0001EH] wording from reconstructable aggregate/emitter to non-emitting source-family index/container.
  - Preserve `ParcelPane.cpp` as the source root for exact children.
  - Add the new raw helper child route as ParcelIconPane-owned, no-function/no-entry, blank C++.
  - Preserve compiler cleanup funclets [UID:0002KM]/[UID:0002KN] as non-emitting EH cleanup, not handwritten helpers.
- `by-class/ParcelPane.md`
  - Update memory-range/source-family wording so [UID:0001EH] is a non-emitting container and [UID:0001EP]/other exact children carry source decisions.
  - No broad class C++ should be added.
- `by-class/FlyingParcelPane.md`
  - Update memory-range/source-family wording so [UID:0001EH] is a non-emitting container and [UID:0001EL]/[UID:0002R5]/[UID:0002R6]/[UID:0002KK]/[UID:0002KL] carry exact child decisions.
  - No broad class C++ should be added.
- `by-global/g_pParcelPane.md`
  - Change lifecycle table row for `0x00546e80-0x00546e8b` from "compact file-scope clear helper" to non-emitting constructor/EH cleanup funclet that clears `g_pParcelPane`.
  - Preserve lifecycle refs from constructor/destructor/scalar destructor and FlyingParcelPane animation use.
- No required edits:
  - `by-global/g_pParcelIconPane.md` already treats [UID:0002KM] as non-emitting EH cleanup.
  - `by-type/by-vtable/ParcelNotificationVtableFamily.md` already rejects `0x00621d50` as `ALERTBTN.EPF` successor/resource data.
  - `by-type/by-struct/ParcelNotificationPaneLayouts.md` already records the accepted layout/vtable offsets needed by this report.
  - `by-memory/0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart.md` already provides the non-emitting raw-child inventory precedent and does not need a callback edit.

## Score And Metadata Recommendation

- Current target metadata: `85/88`, `CANONICAL_OWNER:0000MF`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000MF`.
- Recommended target metadata after implementation: `88/91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`.
- Reason higher:
  - Current MCP pass completes the missing raw-helper inventory gap at `0x005460f0-0x005461c0`.
  - Current MCP pass reconfirms PatchPane boundary and raw/padding distinctions.
  - Current docs now have strong precedents for non-emitting container parents.
  - Support sync can remove stale gate/owner assumptions.
- Reason not higher:
  - The new raw helper still has no entry xref or modeled IDA function, and its exact original source name/signature remains unproven.
  - Several exact child pages still keep C++ blank for child-specific reasons.
  - Exact original source-file split is inferred as `ParcelPane.cpp` source-family placement, not proven by symbols.
  - Some generated/manual tracker rows remain stale until validator lifecycle refresh.
- New raw helper child score recommendation: `84/88`, owner `0000A5`, reconstructable true, blank emitter/C++. This recognizes exact behavior and owner while preserving route/name uncertainty.

## Open Questions With Attempted Resolution

- Is [UID:0001EH] itself a source emitter?
  - Evidence checked: by-structure container rule, exact child docs, current MCP function/raw/padding inventory, source-file support docs, non-emitting container precedents.
  - Resolution: no. It is a non-emitting mixed container.
- Does the target need another child split?
  - Evidence checked: `rg` for `0x005460f0`, MCP lookup/insn/bytes/xrefs, existing [UID:0001EJ] and ParcelIconPane class notes.
  - Resolution: yes. Create `by-memory/0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper.md`.
- Is the new raw helper safe for formal C++?
  - Evidence checked: no function object, no xrefs to start, behavior mirrors callback but with direct payload pointer, no original symbol/name.
  - Resolution: no. Document behavior and owner; leave `EMITTER_UIDS` and formal C++ blank.
- Does `0x005470ad` remain the correct end?
  - Evidence checked: MCP lookup and bytes, PatchPane decompile at `0x005470b0`, stale tracker rows.
  - Resolution: yes. Keep live path `0x00545e40-0x005470ad`; do not recreate `0x005470ac`.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- No manual `-coverage-report.md` replacement text is requested or supplied for B-agent application in this report.
- Stale rows were observed in `by-memory/-coverage-report.md`, `auto-generated/-ag-research-tracker.md`, and `auto-generated/-ag-coverage-report-by-memory.md` using the old `0x005470ac` path/range.
- Required handling: update source by-* pages and run scoped validators after supervisor acceptance; allow validator-owned generated reports to refresh. Do not manually edit generated reports or manual coverage reports unless the supervisor explicitly assigns that separate action.

## Validator Results

- Report-only pass: no validators were run because no by-* docs were edited.
- MCP evidence pass completed successfully; no `PAUSED_MCP_UNAVAILABLE` condition.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B007/research/0001EH-ParcelNotificationPanes-source-quality.md`.
- Modified: none outside Agent-B007 report folder.
- Renamed: none.
- Leases used: none. The workflow says no lease is needed to create/update reports in the agent's own `research` folder.
- Report execution: leave blank. Supervisor runs `python .\tools\validator.py execute_report B007 0001EH-ParcelNotificationPanes-source-quality.md 0001EH --apply` only after verification succeeds.

## Implementation Tracking Checklist

Implementation callback pass:

- [x] Supervisor validation/acceptance received for implementation. Proof: user callback accepted `tools/leaser/Agents/Agent-B007/research/0001EH-ParcelNotificationPanes-source-quality.md` for [UID:0001EH].
- [x] Target doc updated: `by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md`.
  - Proof: header now reads `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++.
  - Proof: status now says reviewed non-emitting mixed by-memory container/source-family index; source-family placement remains [UID:0000MF] `ParcelPane.cpp`, but aggregate source emission is rejected.
  - Proof: Covered Functions now includes `0x005460e8-0x005460f0` eight-byte `0xcc` padding and [UID:00043J] `0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper` after [UID:0001EI].
  - Proof: evidence, ownership decision, score rationale, cross-references, and change note preserve compiler cleanup/thunk/wrapper decisions, `0x005470ad` half-open end, `0x005470ad-0x005470b0` padding, PatchPane successor exclusion, false `0x00621d50` vtable-slot rejection, and stale `0x005470ac` tracker-row caveat.
- [x] New child page created through validator UID workflow: `by-memory/0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper.md`.
  - Proof: first validator pass assigned real UID `00043J`; no UID was guessed in report references before assignment.
  - Proof: final header reads `COMPLETION:84`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000A5`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank formal C++.
  - Proof: child page carries no-function/no-xref status, eight-byte pre-padding, direct-payload packed-count decode, fields `+0xf8/+0xf9/+0xfa`, child pointer `+0xfc`, `ParcelPane::SetParcelSlotData` / `sub_5464B0` call at `0x005461b0`, zero return, `retn 4` at `0x005461bd`, and unresolved source name/signature/entry route.
- [x] Support doc updated: `by-memory/0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback.md`.
  - Proof: `CANONICAL_OWNER` and `EMITTER_UIDS` now both read `0000A5`.
  - Proof: stale class-below-gate and `95/95` code-gate wording was replaced with current direct ParcelIconPane owner/emitter evidence and blank-C++ reasons: packet/event wrapper type, exact source signature, raw-helper pairing, side-count field names, and child field declaration.
  - Proof: page links [UID:00043J] and preserves event payload `a2+12`, first byte `8`, packed count decode, fields `+0x58/+0x59/+0x5a`, child pointer `+0x5c`, and `sub_5464B0` call.
- [x] Support doc updated: `by-class/ParcelIconPane.md`.
  - Proof: method inventory now includes [UID:00043J] as an exact raw helper child and [UID:0001EJ] as direct class-owned/emitted callback support.
  - Proof: raw-helper blocker now says exact child exists but remains no-entry/no-function/non-emitting pending route/signature proof.
  - Proof: broad class C++ stays blank for field/helper names, raw helper route/signature, packet/event wrapper type, child field declaration, and private/helper declaration shape.
- [x] Support doc updated: `by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md`.
  - Proof: Item Summary no longer claims parent attachment to UID `0000MF` because class UID `0000A5` is below gate.
  - Proof: 2026-06-26 change note marks the old direct-class deferral and old `95/95` reason as superseded; owner/emitter `0000A5` preserved; C++ remains blank for child allocation/helper/member names and private-helper declaration shape.
- [x] Support doc updated: `by-memory/0x00546070-0x005460e8.ParcelIconPaneDestructor.md`.
  - Proof: Item Summary and changes remove current stale class-gate/`95/95` rationale; owner/emitter `0000A5` preserved; C++ remains blank for object-layout, helper names, and destructor declaration shape.
- [x] Support doc updated: `by-memory/0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor.md`.
  - Proof: Item Summary and rebuild handling now say this is a compiler-emitted scalar deleting destructor wrapper that should be regenerated from ordinary destructor source rather than hand-authored; owner/emitter `0000A5` preserved; old gate wording superseded.
- [x] Support doc updated: `by-file/ParcelPane.md`.
  - Proof: file role and migration notes identify [UID:0001EH] as a non-emitting source-family index, not a `ParcelPane.cpp` aggregate emitter.
  - Proof: Proposed Contents and Evidence add [UID:00043J] as ParcelIconPane-owned no-entry/no-function raw helper with blank emitter/C++; [UID:0002KM]/[UID:0002KN] compiler/EH cleanup funclet policy remains preserved.
- [x] Support doc updated: `by-class/ParcelPane.md`.
  - Proof: status/evidence clarify [UID:0001EH] is non-emitting and exact ParcelPane children carry source decisions.
  - Proof: [UID:00043J] is recorded only as setter caller/data-flow support, not a ParcelPane method or class-C++ trigger; broad class C++ remains blank.
- [x] Support doc updated: `by-class/FlyingParcelPane.md`.
  - Proof: status/evidence/change note clarify [UID:0001EH] is non-emitting and exact FlyingParcelPane children plus [UID:0001EL] carry source decisions.
  - Proof: broad class C++ remains blank for declaration/raw-sibling/destructor-shape reasons.
- [x] Support doc updated: `by-global/g_pParcelPane.md`.
  - Proof: lifecycle row for `0x00546e80-0x00546e8b` now says non-emitting constructor/EH cleanup funclet clearing `g_pParcelPane`, not handwritten compact file-scope helper.
  - Proof: constructor/destructor/scalar destructor and FlyingParcelPane animation refs were preserved.
- [x] Confirmed no edit required: `by-global/g_pParcelIconPane.md`.
  - Proof: current page already treats [UID:0002KM] `0x00546e70` as compiler constructor-unwind cleanup/non-emitting rather than a source helper, and already separates `g_pParcelIconPane` from `g_pParcelPane`.
- [x] Confirmed no edit required: `by-type/by-vtable/ParcelNotificationVtableFamily.md`.
  - Proof: current page already records the `ParcelIconPane` callback slot and rejects the adjacent `0x00621d50` false virtual-slot interpretation as `ALERTBTN.EPF` successor/resource data.
- [x] Confirmed no edit required: `by-type/by-struct/ParcelNotificationPaneLayouts.md`.
  - Proof: current page already records accepted `ParcelIconPane` owner offsets, secondary callback normalization, child pointer `+0xfc`, and parcel notification layout/vtable offsets used by this callback.
- [x] Confirmed no edit required: `by-memory/0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart.md`.
  - Proof: current page already has `RECONSTRUCTABLE:FALSE`, blank C++, exact [UID:0002R5]/[UID:0002R6] child inventory, padding evidence, and non-emitting split-inventory policy.
- [x] Metadata/score decisions applied.
  - Proof: [UID:0001EH] `85/88`, owner/emitter `0000MF`, reconstructable true -> `88/91`, owner none, reconstructable false, blank emitter.
  - Proof: [UID:00043J] new raw helper -> `84/88`, owner `0000A5`, reconstructable true, blank emitter.
  - Proof: [UID:0001EJ] owner/emitter `0000MF` -> `0000A5`; score kept `86/90`.
- [x] Owner/emitter/reconstructable decisions preserved.
  - Proof: exact class children keep class owners, compiler cleanup funclets and adjustor thunks remain non-emitting, scalar deleting destructor wrappers remain blank-C++ wrapper pages, and [UID:0001EH] stays blank/non-emitting.
- [x] Historical/stale assumptions and rejected alternatives preserved.
  - Proof: target keeps stale `0x005470ac` tracker-row caveat, old B001 partial caveat context is superseded by full aggregate pass, old `95/95` and class-below-gate wording is marked stale where touched, `0x00621d50` false vtable-slot/resource-data rejection is preserved, and PatchPane successor `0x005470b0` remains excluded.
- [x] First-draft C++/no-code proof applied.
  - Proof: [UID:0001EH] formal C++ remains blank with mixed-container no-code proof.
  - Proof: [UID:00043J] formal C++ remains blank because no function object, xref, source signature, or original helper name is proven.
- [x] Validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`.
  - UID assignment pass: `python .\tools\validator.py --mode file --file by-memory/0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper.md --apply --queue-timeout 240`; command_id `000000002372`; timestamp `2026-06-26T04:32:34-04:00`; exit `0`; assigned UID `00043J`; generated_refresh `deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper.md --apply --queue-timeout 240`; command_id `000000002378`; timestamp `2026-06-26T04:35:41-04:00`; exit `0`; `ok:1`; generated_refresh `deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md --apply --queue-timeout 240`; command_id `000000002379`; timestamp `2026-06-26T04:35:43-04:00`; exit `0`; `ok:1`; path_update repaired UID `0001EH` from stale `0x005470ac` to `0x005470ad`; generated_refresh `deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback.md --apply --queue-timeout 240`; command_id `000000002380`; timestamp `2026-06-26T04:35:47-04:00`; exit `0`; `ok:1`; generated_refresh `deferred`.
  - `python .\tools\validator.py --mode file --file by-class/ParcelIconPane.md --apply --queue-timeout 240`; command_id `000000002381`; timestamp `2026-06-26T04:35:48-04:00`; exit `0`; `ok:1`; generated_refresh `deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md --apply --queue-timeout 240`; command_id `000000002382`; timestamp `2026-06-26T04:37:14-04:00`; exit `0`; `ok:1`; generated_refresh `deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x00546070-0x005460e8.ParcelIconPaneDestructor.md --apply --queue-timeout 240`; command_id `000000002383`; timestamp `2026-06-26T04:37:16-04:00`; exit `0`; `ok:1`; generated_refresh `deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor.md --apply --queue-timeout 240`; command_id `000000002384`; timestamp `2026-06-26T04:37:17-04:00`; exit `0`; `ok:1`; generated_refresh `deferred`.
  - `python .\tools\validator.py --mode file --file by-file/ParcelPane.md --apply --queue-timeout 240`; command_id `000000002391`; timestamp `2026-06-26T04:40:23-04:00`; exit `0`; `ok:1`; generated_refresh `deferred`.
  - `python .\tools\validator.py --mode file --file by-class/ParcelPane.md --apply --queue-timeout 240`; command_id `000000002392`; timestamp `2026-06-26T04:40:25-04:00`; exit `0`; `ok:1`; generated_refresh `deferred`.
  - `python .\tools\validator.py --mode file --file by-class/FlyingParcelPane.md --apply --queue-timeout 240`; command_id `000000002393`; timestamp `2026-06-26T04:40:27-04:00`; exit `0`; `ok:1`; generated_refresh `deferred`.
  - `python .\tools\validator.py --mode file --file by-global/g_pParcelPane.md --apply --queue-timeout 240`; command_id `000000002394`; timestamp `2026-06-26T04:40:29-04:00`; exit `0`; `ok:1`; generated_refresh `deferred`.
- [x] Validator observations recorded.
  - Proof: validators returned `ok:1` for every final edited by-* file validation; initial UID assignment pass inserted UID and metadata for the new child. Existing unrelated missing-reference noise remains for stale [UID:0001EN] `0x00546ed0-0x00546f36` references and broader coverage/ignored files; this callback did not edit those unrelated pages.
- [x] Generated/state restrictions honored.
  - Proof: no manual edits were made to `auto-generated/*`, generated C++ output, IDA DB, `by-memory/-coverage-report.md`, or any coverage-report file. Validator-owned state/generated/projection updates occurred only through the exact scoped validator commands.
- [x] Leases used and released.
  - Proof: leased and released parent during new child creation: `by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md`.
  - Proof: leased and released core batch: new child, target aggregate, callback, `by-class/ParcelIconPane.md`.
  - Proof: leased and released stale-gate batch: constructor, destructor, scalar deleting destructor pages.
  - Proof: leased and released support batch: `by-file/ParcelPane.md`, `by-class/ParcelPane.md`, `by-class/FlyingParcelPane.md`, `by-global/g_pParcelPane.md`.
  - Proof: final `tools/leaser/Agents/current_leases.md` read showed no B007 leases active; only unrelated B002 GrafPort leases were present.
- [x] Remaining unapplied accepted items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0001EH-ParcelNotificationPanes-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0001EH-ParcelNotificationPanes-source-quality.md","timestamp":"2026-06-26T04:44:56","uid":"0001EH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
