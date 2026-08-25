** TARGET-REPORT-UID:0002NA **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002NA DescPaneVtableData Ownership / Source-Quality Research


## Finalized Report / Current Recommendation

- Current implemented state: the exact path and half-open range
  `by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md` are retained; all 33
  in-range dwords are documented; UID0002NA is `92/94`.
- Final disposition remains `source-declared/generated-binary` data. The
  complete source declaration and ordinary definitions now cause the
  compiler/linker route; NexusTK source contains no handwritten vtable array,
  explicit vptr store, adjustor body, scalar-deleting-destructor body, or
  explicit base teardown.
- Ownership/routing is applied: UID00003Q is the semantic owner, UID0001XC is
  the target emitter/evidence intermediary, target position is 10,
  reconstructable is true, and `Nested:4` is retained.
- Source closure is applied: UID00003Q contains the complete
  `DescPane : public Pane` declaration with its closing `};` before
  `[[CHILDREN]]`; all five source methods are positioned and retained;
  UID0000QR defines `g_pDescPane` once; UID0001U3, UID0001XC, UID0002NA, and
  UID0001PB carry the accepted managed coverage markers.
- Range closure: the primary COL at `0x006189d8` is outside the page, the
  secondary and tertiary COL dwords at `0x00618a24` and `0x00618a54` are
  physically inside it, and the `DialogPane` primary COL at `0x00618a60` is
  the exact successor boundary.
- Confidence: very strong for bytes, section, range, RTTI, inheritance,
  18/11/2 slot extents, every target dword, source/compiler boundary,
  owner/emitter route, and the complete declaration. Human spellings
  `DrawOnTarget` and `GetParentPane` are best-supported source-era inferences,
  not recovered PDB symbols.

## Supporting Research

- Assignment source: the `New Report Assignment Override` in
  `tools/leaser/Agents/Agent-B001/goal.md`.
- Queue source: `auto-generated/-ag-research-tracker.md`, `## by-memory` ->
  `### Not-Covered Files - Reconstructable`, row
  `[UID:0002NA] ... | 86/90 | 88.0 | true | 0`.
- Historical report-only evidence checkpoint: direct target-report count was
  zero before this artifact was written. Current count/path/lifecycle state is
  external validator-owned state and is not asserted here.
- No prior direct report with `TARGET-REPORT-UID:0002NA` was found in active
  B001-B005 roots, central executed reports, Older-Research, or
  SpecialReports.
- Executed supporting reports opened and classified:

| Evidence-time report | SHA256 | Classification and incorporated result |
| --- | --- | --- |
| `executed-b-agent-research/B005/00012J-DescPaneConstructorRaw-source-quality.md` | `02E2B19561C2A27A6187E751E56A1150340EBEE9D49707373D6939B8DA6C7E52` | Direct constructor support. Exact base construction, three vptr stores, `+0xf8/+0xfc`, singleton publish, no-route evidence, and source placement incorporated. Its provisional custom-provider type is superseded by current Pane evidence. |
| `executed-b-agent-research/B008/00012K-DescPane-source-quality.md` | `A4E718E751070CE9791049E233C04EBA5BC4CCADF89C3B9A84EB3230219CDFF0` | Direct class-island support. Child inventory, padding, aggregate route, and generated empty-marker defect incorporated. Its emitting aggregate `[[CHILDREN]]` solution is superseded because the class page is now declaration-ready and the aggregate has no direct children. |
| `executed-b-agent-research/B009/00012L-DescPaneDestructor-source-quality.md` | `9322AF9B928DABA596E1FF8BAB76EA9FF2C966C9378C8CD6E20BD09D3E860968` | Direct ordinary-destructor support. Singleton clear is source-authored; vptr restoration and Pane teardown are compiler lowering. |
| `executed-b-agent-research/B010/00012M-DescPaneGetSingleton-source-quality.md` | `15C335CE2E94972569EC6276E744F057A5007D31C82930E9101FF83EA4B83558` | Direct singleton-getter support. Exact six-byte return of `g_pDescPane`; static class accessor source shape retained. |
| `executed-b-agent-research/B006/00012N-DescPaneSetSourceAndIndexRaw-empty-emitter-source-quality.md` | `D23B924A640AB3A02AE70698440D572BB920AD1F989151EE80B7BD229B2EA40E` | Direct setter support. Correct range, paired field update, inherited `InvalidateRect`, and no-route evidence incorporated. Historical custom-provider type is rejected. |
| `executed-b-agent-research/B003/00012O-DescPaneRefreshDescription-source-quality.md` | `B413ADB364E2B483BC14E568FA4EA3F5DA74F86D452B9205C8E1D404C2A76BE5` | Direct paint-method support. Current `OnPaint`, `Pane *`, `wchar_t[1024]`, clear/fill order, and no-post-read result incorporated. |
| `executed-b-agent-research/B011/00012Q-DescPaneScalarDeletingDestructor-source-quality.md` | `D97CCAA09BC6AB7174429414167E637E44C0B1705E69D0AF7F14E3DB868CB9A1` | Direct compiler-wrapper support. Exact delete flags, adjusted-this routes, duplicate source cleanup, base teardown, optional free, and no-code disposition incorporated. |

- Historical report hashes above are evidence-time artifacts. Current ordinary
  docs, current binary evidence, and the latest observed generated output are
  the authority for this report's current recommendation.
- Wave2/Wave3 material was not used as authority. Current docs that mention
  disabled `simroot_v2` output were treated only as historical/generated leads.

## Target

- Target UID: `0002NA`.
- Target path:
  `by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md`.
- Target range: `[0x006189dc,0x00618a60)`.
- Range length: `0x84` / 132 bytes (Verified with `int_convert.py`).
- Current metadata: `COMPLETION:92`, `CONFIDENCE:94`,
  `CANONICAL_OWNER:00003Q`, `RECONSTRUCTABLE:TRUE`,
  `EMITTER_UIDS:0001XC`, `EMITTER_POSITION_OPTIONAL:10`, exact managed
  no-handwritten-table marker, `Nested:4`.
- Current target SHA256 after scoped validation and the final waited refresh:
  `2569221690FDCDAFA5A4ED0517511BC44A6C64A040D9BB08F6528CCF03E29455`.
- Historical pre-callback target SHA256:
  `E41E2F791A1CC7DDDC7BA130796173DA615A1FC129A98B4D0D4331CD3F573C22`.

## Current Target State

- The target page now records the three table bases, both in-range inter-view
  COL dwords, all 18/11/2 callable slots, RTTI hierarchy, lifecycle stores,
  source/compiler boundary, and `0x00618a60` DialogPane successor.
- UID00003Q is the semantic owner and UID0001XC remains the vtable
  evidence/emitter route. The target formal marker is populated.
- The complete class/file/global/layout/vtable/source union is applied at the
  accepted positions and scores. UID00012K is a blank non-emitting
  split/index; UID00012P/UID00012Q remain blank compiler glue.
- Historical report-only generated checkpoint before callback:
  `auto-generated/NexusTK/ui/controls/DescPane.cpp`, validator command
  `000000014163`, refreshed `2026-07-16T14:24:23-04:00`, SHA256
  `565C4CECDACB69AA9BC49F914D5B4CD90E9A0C0BA94BC4328D5D6716410937AA`,
  2,429 bytes, 65 lines.
- That historical checkpoint had six `Empty Emitter Marker` lines for
  UID00003Q, UID0001U3, UID0001XC, UID0002NA, UID0000QR, and UID0001PB,
  plus one UID00012K `[[No Children Attached]]` line. The five source method
  bodies are present once each.
- B001's final authorized waited target validation was command
  `000000014216`, `2026-07-16T14:49:42-04:00`, exit 0 / ok 1. Its generated
  checkpoint SHA256 was
  `77583FAD5D8E74977254414D24D1CF0706CB93D29A666C18958CB374876270A0`.
- A validator-owned generated checkpoint observed during terminal
  reconciliation was command `000000014231`, refreshed
  `2026-07-16T14:55:39-04:00`, SHA256
  `1B7809B21016EA404BABE7C6217F26F709341E0BCD267E814408EE089DC968B7`,
  3,062 bytes / 85 lines. This is evidence-time provenance rather than an
  assertion that an externally refreshed header can never advance. Structural
  readback is unchanged: one complete class definition, five method
  definitions, one global definition, four support/data comments, zero
  relevant Empty Emitter Markers, and zero `[[No Children Attached]]`.
- During the initial report-only evidence pass, ordinary edits, leases,
  validators, and generated refresh were intentionally not performed. During
  the accepted callback B001 performed the ordinary edits, short leases,
  scoped validators, and final waited refresh enumerated later. B001 performed
  no manual coverage edit, IDA mutation, report execution, report lifecycle
  command, move, or archive action.
- Implementation is complete and no B001 work remains. Current coverage
  application, report validation/execution/count/path/move/archive state
  remains external supervisor/validator-owned state and is neither asserted
  nor directed by this artifact.

## Executive Recommendation

1. Keep the exact target range and filename.
2. Correct the physical inventory to three vtable views plus two in-range COL
   dwords, with no split and no padding.
3. Change the direct semantic owner to UID00003Q and retain UID0001XC as the
   target emitter so the evidence hierarchy remains
   target -> DescPaneVtables -> DescPane -> DescPane.cpp.
4. Make UID00003Q the complete source declaration and place the existing
   method children at positions 10/20/30/40/50.
5. Place UID0001U3 and UID0001XC at positions 60/70 under UID00003Q; place
   UID0002NA at position 10 under UID0001XC.
6. Reclass UID00012K as a non-emitting split/index. It is a physical
   class-island audit page, not a source object and not the direct parent of
   the five method emitters.
7. Define `g_pDescPane` on UID0000QR at file position 20 and route UID0001PB
   beneath it with a covered-storage marker.
8. Preserve the concurrent current Pane union that already resolves primary
   `+0x1c` as `GetParentPane`; add the still-missing `DrawOnTarget` direction
   for primary `+0x10`, and correct the stale `Repaint` row that remains only
   in PaneCore.
9. Preserve EventHandler and TimerHandler declarations at same-or-greater
   detail; DescPane inherits those views through Pane and does not redeclare
   them or directly multiply inherit them.

## Supervisor Active Recheck

- The exact artifact SHA
  `CE0BFCEAF683F0E8006F549D7D5633A825910435A55550CBAC780CCB232C1819`
  passed supervisor Gate 1 and authorized this bounded callback.
- No split, rename, child creation, ignored range, or fabricated UID was
  needed. Every accepted UID already existed in the current canonical tree.
- All accepted target/support edits, 11 managed blocks, 20 scoped ordinary
  validations, final waited refresh, structural generated assertions, manual
  supervisor-owned handoff, and lease releases are complete.
- Lower historical assignments in `goal.md` remain assignment history only.
  B001 did not run report execution or lifecycle commands.

## Inference Research Guidance Check

- IDA/PE fact: bytes, dwords, function boundaries, xrefs, COL offsets, RTTI
  base descriptors, section membership, and absence of a relocation directory.
- Documentation evidence: current class/file/layout/vtable/method/global pages,
  current manual coverage rows, latest observed generated source, and executed
  support reports.
- Inference: original human method spellings and access sections where stripped
  symbols do not survive.
- The source model follows late-1999 through mid-2000s MSVC C++ shape:
  ordinary class declaration, virtual destructor, inherited virtual contracts,
  static/global pointer, no explicit vptr stores, no handwritten RTTI/vtables,
  no modern `override` or `nullptr`.
- Current docs were challenged where they contradicted the physical half-open
  range, inherited caller behavior, or current generated output.
- No Wave2/Wave3 conclusion was accepted as proof. Stale generated labels such
  as `RefreshDescription`, `Repaint`, custom provider types, and blank/full
  aggregate markers were independently checked.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence and reanalysis | Final resolution |
| --- | --- | --- |
| Physical range convention | Raw PE and MCP bytes prove the target starts at the primary vtable base, includes cells through `0x00618a5c`, and excludes the next primary COL at `0x00618a60`. | Keep the path/range. Primary COL is excluded; internal secondary/tertiary COL cells are included because they are physically in range. |
| Section/relocation role | Target maps to `.rdata` at raw file offset `0x2173dc`; PE base relocation directory RVA and size are both zero. | Fixed absolute x86 virtual-address table data, not a relocation directory or source-authored numeric array. |
| Direct inheritance | Three DescPane COLs share one CHD with base order DescPane, Pane, GrafPort, LObject, EventHandler, TimerHandler. PMDs are `0`, `0`, `0`, `0xa0`, `0xa4`. | Source declaration is `class DescPane : public Pane`. EventHandler/TimerHandler views are inherited through Pane, not direct DescPane bases. |
| Primary `+0x10` | Base target `0x0041d680` is a three-argument no-op shared by 381 vtable data refs. Layer render recursion calls that slot only when the pane custom-target flag is set, passing target GrafPort and two rectangle pointers. Weather-derived replacements occupy the same slot and draw into the supplied target. | Highest-probability source contract: inherited `DrawOnTarget(GrafPort *, const RectBounds *, const RectBounds *)`. `RenderToTarget` ranks second. `OnPaint` is rejected because DescPane has a separate `+0x44` OnPaint override. |
| Primary `+0x1c` | `0x005447a0` reads Pane `Layer *` at `+0xa8`, returns null if absent, otherwise calls exact UID0004O9 `Layer::GetParentPane(this)`. | `Pane::GetParentPane() const` direction. Historical `Repaint` is rejected. |
| Primary `+0x24` | Exact UID0004IX body and DescPane consumer prove `(int, wchar_t *)`, writing one wide NUL only for `-1`. | `Pane::GetDescription(int, wchar_t *)`. |
| Primary `+0x44` | Only target data xref is DescPane cell `0x00618a20`; complete body clears/fills then delegates description production. | `DescPane::OnPaint()` override, not `RefreshDescription`. |
| Secondary view | Eleven slots exactly match the EventHandler facet at object `+0xa0`: destructor adjustor, six event-family bridges, dispatcher ordering, local pair, screen pair, acceptance predicate. | No DescPane redeclarations. Source legality comes from Pane's EventHandler inheritance and current EventHandler declaration. |
| Tertiary view | Two slots match TimerHandler facet at `+0xa4`: deleting-destructor adjustor and a three-explicit-argument true-return timer callback default. | Inherited `bool OnTimer(int timerId, int arg0, int arg1)` contract; no DescPane override. |
| Class-local layout | Constructor, setter, and OnPaint agree on `+0xf8` borrowed Pane pointer and `+0xfc` selected index. Destructor never releases the pointer. | `Pane *m_pDescriptionSource; int m_selectedDescriptionIndex;`, private, natural object size `0x100` / 256 bytes (Verified with `int_convert.py`). |
| Class access | Constructor, virtual destructor, static getter, and setter are class API/lifecycle. OnPaint is a framework override. | Public lifecycle/getter/setter; protected `OnPaint`; private fields. |
| Aggregate source route | UID00012K's `[[CHILDREN]]` has no actual emitter children because the method pages emit directly to UID00003Q. | Reclass UID00012K to false/no-emitter/blank C++; UID00003Q owns `[[CHILDREN]]`. |
| Global declaration | All four storage xrefs are confined to the class island. Loader-zero-filled storage is source-level null initialization. | `extern DescPane *g_pDescPane;` in the class/header declaration and one `DescPane *g_pDescPane = NULL;` definition in DescPane.cpp. |
| Target/type/layout/storage output | These pages are evidence views over declarations emitted elsewhere. | Use exact comment-only managed coverage markers, never duplicate declarations or data. |
| Original lexical names | No PDB, local UDT, or original source path string proves every spelling. | Use project-consistent `DescPane`, `GetSingleton`, `SetSourceAndIndex`, `OnPaint`, `GetParentPane`, and `DrawOnTarget`; mark inferred names honestly without leaving placeholders. |

Rejected alternatives:

- Handwritten `void *` vtable arrays or literal function-pointer arrays: binary
  artifacts, not plausible original source.
- Explicit constructor/destructor vptr assignments: compiler lowering.
- Direct inheritance from `GrafPort`, `LObject`, `EventHandler`, or
  `TimerHandler`: contradicted by RTTI direct-base structure.
- A new `DescPaneDescriptionSource` interface: contradicted by exact Pane
  `GetDescription` slot and absence of a separate type/vtable.
- `Repaint` at primary `+0x1c`: contradicted by direct `Layer::GetParentPane`
  call.
- `RefreshDescription` at primary `+0x44`: incomplete because the method is the
  paint override and performs unconditional fill work.
- A split at `0x00618a24` or `0x00618a54`: would fragment one coherent
  three-view class table and conflict with current adjacent vtable-page
  convention.
- Extending left to `0x006189d8`: would overlap the preceding string tail and
  change the current primary-base-start convention.
- Extending right to `0x00618a64`: would include `DialogPane` RTTI/table data.

## Evidence Standards Used

- Healthy live IDA MCP: fresh `idb_list`, `server_health`, bounded
  `get_bytes`, `lookup_funcs`, `decompile`, `disasm`, and `xref_query`.
- Raw PE parser: image base, section table, raw file offset, SHA256, data
  directory, COL/CHD/base descriptor/type-descriptor decoding.
- Current by-* docs: target, class, file, layout, vtables, aggregate, methods,
  compiler wrappers, global/storage, Pane, EventHandler, TimerHandler, Layer.
- Current generated source and manual coverage rows, read only.
- Old reports only after target/address/name/source-family search.
- Positive and negative evidence were both required before source naming and
  score movement.
- Numeric conversions used in prose were verified with `tools/int_convert.py`.
- Confidence is capped below 95 because stripped original spellings and
  whole-project final compilation are unavailable; no behavioral, routing, or
  declaration blocker remains in scope.

## Evidence Checked

IDA MCP and raw-binary checks:

- Fresh MCP transport initialization and `idb_list` returned active NexusTK
  session `64c11373`, worker PID `21508`, `is_analyzing:false`.
- `server_health(database:"64c11373")` returned `status:"ok"`, image base
  `0x00400000`, and analysis, Hex-Rays, and string cache ready.
- Bounded `get_bytes(0x006189dc,16)` succeeded before the evidence pass.
- Full bounded reads covered `0x006189d0-0x00618a64`, the DescPane RTTI
  structures, type descriptor, and `g_pDescPane` storage.
- `lookup_funcs` checked every one of the 31 callable target dwords.
- `xref_query` checked all three vtable bases, scalar wrapper, OnPaint,
  all three DescPane COLs, the `DialogPane` successor COL, and singleton
  storage.
- Targeted decompilation checked `0x0041d680`, `0x004f0ff0`,
  `0x005c1810`, `0x005c20e0`, `0x005c26b0`, `0x005447a0`,
  `0x00544db0`, `0x00544e10`, `0x00544e30`, `0x00544e70`,
  `0x00544e90`, `0x0049d840`, `0x0049d81e`, and `0x0049d829`.
- Targeted disassembly checked all 29 scalar-wrapper instructions.
- Raw PE verification independently reproduced target bytes/hash, `.rdata`
  placement, no base relocation directory, all COLs, the CHD, six base
  descriptors, and type names.
- One earlier helper attempt used the reserved PowerShell `$args` name and
  produced a malformed request-shape error. Valid schema-current calls using
  `$toolArgs`/explicit objects succeeded; this was a client request-shape
  limitation, not MCP unavailability.

Current documentation and generated checks:

- Read the target and every named DescPane class/file/type/memory/global support
  page.
- Read Pane class/file/core/vtable data and exact Layer/EventHandler/TimerHandler
  support needed to resolve inherited slots.
- Read all current manual coverage rows in the affected by-memory, by-class,
  by-file, by-vtable, by-struct, and by-global reports.
- Read latest observed generated DescPane.cpp and counted all bodies, empty
  markers, and the aggregate no-children marker.

Historical search roots and results:

- Active roots checked:
  `tools/leaser/Agents/Agent-B001` through `Agent-B005`.
  Result: only the current B001 goal matched; no active direct target report.
- Central executed root checked: `executed-b-agent-research/**`.
  Result: seven exact DescPane support reports listed under Supporting Research;
  each targets a method/aggregate, not UID0002NA.
- Archived/historical roots checked:
  `tools/leaser/Agents/Older-Research/**` and
  `tools/leaser/Agents/SpecialReports/**`.
  Result: no UID0002NA/address/name/source-family match.
- Search terms included `TARGET-REPORT-UID:0002NA`, `0002NA`,
  `0x006189dc`, `0x00618a60`, `DescPaneVtableData`, `DescPaneVtables`,
  `DescPane`, `Pane`, `EventHandler`, `TimerHandler`, `g_pDescPane`,
  `sub_49D840`, and the named support UIDs.
- Explicit conclusion: no historical report is a direct substitute for this
  complete target-level byte/slot/RTTI/source-declaration report.

Phase-qualified action record:

- During the initial report-only evidence pass, no broad unbounded MCP search,
  IDA mutation, ordinary lease/edit, implementation validator, generated
  refresh, manual coverage edit, or report lifecycle command was performed.
- During the accepted implementation callback, the ordinary edits, one-file
  leases, scoped validators, and final generated refresh listed later were
  performed.
- Across both phases, B001 performed no IDA mutation, manual coverage edit,
  report execution, lifecycle/probe/count command, move, or archive action.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C2NA-001 | Target bytes are the exact 132-byte sequence recorded below and hash to `AFE5BFEE1C4D768F45C845EB1A9C27EC394E335691D4C929EE443B982F5CF56C`. | very strong | MCP bytes plus independent PE read | UID0002NA binary evidence | incorporate | applied |
| C2NA-002 | Target lies in `.rdata` at raw offset `0x2173dc`. | very strong | PE section parser | UID0002NA range/section | incorporate | applied |
| C2NA-003 | PE base relocation directory is absent (`RVA 0`, size `0`). | very strong | PE data directory | UID0002NA classification | incorporate | applied |
| C2NA-004 | `0x006189d8 -> 0x00646548` is DescPane primary COL and remains outside the target. | very strong | bytes/COL/xref | UID0002NA boundary | incorporate | applied |
| C2NA-005 | `0x00618a24 -> 0x006465a4` is the secondary COL and is inside the target. | very strong | bytes/COL/xref | UID0002NA inventory | reject-stale | applied |
| C2NA-006 | `0x00618a54 -> 0x006465b8` is the tertiary COL and is inside the target. | very strong | bytes/COL/xref | UID0002NA inventory | reject-stale | applied |
| C2NA-007 | `0x00618a60 -> 0x006465cc` is DialogPane primary COL and exact successor boundary. | very strong | bytes/COL/xref/type | UID0002NA boundary | incorporate | applied |
| C2NA-008 | Range/path remain unchanged; no split or padding exists inside the target. | very strong | complete dword scan | UID0002NA range decision | already-present | already-present |
| C2NA-009 | `Nested:4` is the correct one-level child indentation under UID000254. | strong | current address order/generated coverage | UID0002NA metadata | already-present | already-present |
| C2NA-010 | Direct semantic owner is UID00003Q; emitter route remains UID0001XC. | very strong | RTTI/lifecycle/source hierarchy | UID0002NA metadata | incorporate | applied |
| C2NA-011 | Primary view has exactly 18 callable slots at `0x006189dc-0x00618a24`. | very strong | dword inventory | UID0002NA/UID0001XC | incorporate | applied |
| C2NA-012 | Primary `+0x00` is compiler scalar deleting destructor `0x0049d840`. | very strong | dword, xrefs, wrapper body | UID0002NA/UID0001XC | incorporate | applied |
| C2NA-013 | Primary `+0x04` is inherited LObject runtime-class accessor `0x004f4b10`. | strong | function identity/shared slot | UID0002NA/UID0001XC | incorporate | applied |
| C2NA-014 | Primary `+0x08` is inherited LObject change-message default `0x0041b6c0`. | strong | no-op body/base slot pattern | UID0002NA/UID0001XC | incorporate | applied |
| C2NA-015 | Primary `+0x0c` is `UpdateRenderRegion(const RectBounds *)` at `0x004b8e20`. | very strong | PaneVtables/callers | UID0002NA/Pane support | incorporate | applied |
| C2NA-016 | Primary `+0x10` is inherited `DrawOnTarget(GrafPort *, const RectBounds *, const RectBounds *)` direction at `0x0041d680`. | strong | Layer caller, 381 refs, weather overrides | UID0002NA/Pane support | incorporate | applied |
| C2NA-017 | Primary `+0x14` is `Pane::Show()` at `0x00544730`. | very strong | body/current Pane docs | UID0002NA/UID0001XC | incorporate | applied |
| C2NA-018 | Primary `+0x18` is `Pane::Hide()` at `0x00544750`. | very strong | body/current Pane docs | UID0002NA/UID0001XC | incorporate | applied |
| C2NA-019 | Primary `+0x1c` is `Pane::GetParentPane() const` direction at `0x005447a0`, not Repaint. | very strong | direct Layer::GetParentPane call | UID0002NA/Pane support | reject-stale | applied |
| C2NA-020 | Primary `+0x20` is `Pane::InvalidateRect(const RectBounds *)` at `0x00544800`. | very strong | setter/current exact child evidence | UID0002NA/UID0001XC | incorporate | applied |
| C2NA-021 | Primary `+0x24` is `Pane::GetDescription(int,wchar_t *)` at `0x00544a20`. | very strong | exact child/consumer | UID0002NA/UID0001XC | incorporate | applied |
| C2NA-022 | Primary `+0x28` is `Pane::GetScreenBounds(RectBounds *)` at `0x00544b80`. | very strong | body/current Pane docs | UID0002NA/UID0001XC | incorporate | applied |
| C2NA-023 | Primary `+0x2c` is `Pane::SetBounds(const RectBounds *, const RectBounds *)` at `0x00544bd0`. | very strong | body/current Pane docs | UID0002NA/UID0001XC | incorporate | applied |
| C2NA-024 | Primary `+0x30` is `Pane::AddToLayer(...)` at `0x00544c70`. | very strong | Layer caller evidence | UID0002NA/UID0001XC | incorporate | applied |
| C2NA-025 | Primary `+0x34` is `Pane::InsertInLayer(...)` at `0x00544cb0`. | very strong | Layer caller evidence | UID0002NA/UID0001XC | incorporate | applied |
| C2NA-026 | Primary `+0x38` is `Pane::RemoveFromLayer()` at `0x00544ce0`. | very strong | body/current Pane docs | UID0002NA/UID0001XC | incorporate | applied |
| C2NA-027 | Primary `+0x3c` is `Pane::SetPaneOrder(Pane *,Pane *)` direction at `0x00544d30`. | strong | EventDispatcher forwarding | UID0002NA/UID0001XC | incorporate | applied |
| C2NA-028 | Primary `+0x40` is `Pane::UnregisterEventHandler()` at `0x00544d70`. | very strong | body/current Pane docs | UID0002NA/UID0001XC | incorporate | applied |
| C2NA-029 | Primary `+0x44` is exact `DescPane::OnPaint()` at `0x0049d7c0`. | very strong | sole data xref and complete child | UID0002NA/UID0001XC | incorporate | applied |
| C2NA-030 | Secondary view has exactly 11 callable slots at `0x00618a28-0x00618a54`. | very strong | dword inventory | UID0002NA/UID0001XC | incorporate | applied |
| C2NA-031 | Secondary `+0x00` is `this-0xa0` deleting-destructor adjustor `0x0049d81e`. | very strong | decompile/disasm/xrefs | UID0002NA/UID00012P | incorporate | applied |
| C2NA-032 | Secondary `+0x04` is `HandlePointerOrMouseEvent(Event *)` bridge `0x00544db0`. | very strong | bridge/default body/order | UID0002NA/EventHandler relation | incorporate | applied |
| C2NA-033 | Secondary `+0x08` is `HandleKeyOrTextEvent(Event *)` bridge `0x00544dc0`. | very strong | bridge/default body/order | UID0002NA/EventHandler relation | incorporate | applied |
| C2NA-034 | Secondary `+0x0c` is `HandleImeEvent(Event *)` bridge `0x00544dd0`. | very strong | bridge/default body/order | UID0002NA/EventHandler relation | incorporate | applied |
| C2NA-035 | Secondary `+0x10` is `HandlePacketEvent(Event *)` bridge `0x00544de0`. | very strong | EventHandler declaration/order | UID0002NA/EventHandler relation | incorporate | applied |
| C2NA-036 | Secondary `+0x14` is `HandleSystemOrControlEvent(Event *)` bridge `0x00544df0`. | very strong | EventHandler declaration/order | UID0002NA/EventHandler relation | incorporate | applied |
| C2NA-037 | Secondary `+0x18` is `HandleType19Event(Event *)` bridge `0x00544e00`. | very strong | EventHandler declaration/order | UID0002NA/EventHandler relation | incorporate | applied |
| C2NA-038 | Secondary `+0x1c` is `ForwardHandlerOrder` at `0x004a89f0`. | very strong | exact EventHandler source body | UID0002NA/EventHandler relation | incorporate | applied |
| C2NA-039 | Secondary `+0x20` is `GetLocalEventPair(EventPointPair *)` at `0x00544e10`. | very strong | decompile/current declaration | UID0002NA/EventHandler relation | incorporate | applied |
| C2NA-040 | Secondary `+0x24` is `GetScreenEventPair(EventPointPair *)` at `0x00544e30`. | very strong | decompile/current declaration | UID0002NA/EventHandler relation | incorporate | applied |
| C2NA-041 | Secondary `+0x28` is `ShouldAcceptEvent() const` at `0x00544e70`. | very strong | decompile/current declaration | UID0002NA/EventHandler relation | incorporate | applied |
| C2NA-042 | Tertiary view has exactly two callable slots at `0x00618a58-0x00618a60`. | very strong | dword inventory | UID0002NA/UID0001XC | incorporate | applied |
| C2NA-043 | Tertiary `+0x00` is `this-0xa4` deleting-destructor adjustor `0x0049d829`. | very strong | decompile/disasm/xrefs | UID0002NA/UID00012P | incorporate | applied |
| C2NA-044 | Tertiary `+0x04` is inherited `bool OnTimer(int,int,int)` default `0x00544e90`. | very strong | body and TimerHandler contract | UID0002NA/TimerHandler relation | incorporate | applied |
| C2NA-045 | All three DescPane COLs share type `.?AVDescPane@@` and CHD `0x0064655c`. | very strong | raw RTTI decode | UID0002NA/UID0001XC | incorporate | applied |
| C2NA-046 | CHD has six entries: DescPane, Pane, GrafPort, LObject, EventHandler, TimerHandler. | very strong | raw base-array decode | UID0002NA/class/layout | incorporate | applied |
| C2NA-047 | DescPane directly derives only from Pane. | very strong | RTTI contained-base hierarchy | UID00003Q declaration | incorporate | applied |
| C2NA-048 | EventHandler and TimerHandler facets occur at `+0xa0/+0xa4` through Pane inheritance. | very strong | PMD offsets and Pane docs | UID00003Q/layout/vtables | incorporate | applied |
| C2NA-049 | DescPane class-local tail is borrowed `Pane *` at `+0xf8` and `int` at `+0xfc`; size `0x100`. | very strong | constructor/setter/paint/layout | UID00003Q/UID0001U3 | incorporate | applied |
| C2NA-050 | Complete class declaration belongs on UID00003Q and preserves all five existing method bodies through `[[CHILDREN]]`. | very strong | source route/generated defect | UID00003Q formal | incorporate | applied |
| C2NA-051 | Method positions should be constructor 10, destructor 20, getter 30, setter 40, OnPaint 50. | strong | source order/address order | UID00012J-L-M-N-O metadata | incorporate | applied |
| C2NA-052 | UID0001U3 position 60 and UID0001XC position 70 place declaration support after methods. | strong | source route/order | layout/vtable metadata | incorporate | applied |
| C2NA-053 | UID0002NA position 10 under UID0001XC preserves the exact vtable evidence hierarchy. | strong | ownership/emitter separation | target metadata | incorporate | applied |
| C2NA-054 | UID00012K is a non-emitting split/index, not a source-bearing aggregate. | very strong | current no-children generated output | UID00012K metadata/formal | incorporate | applied |
| C2NA-055 | UID00012J retains its exact constructor body but must historicalize current custom-provider prose. | very strong | current Pane source type | UID00012J prose/score/position | historicalize | applied |
| C2NA-056 | UID00012L retains exact source destructor and gains source position/score closure. | very strong | exact body/wrapper contrast | UID00012L metadata/prose | incorporate | applied |
| C2NA-057 | UID00012M retains exact static getter and gains source position/score closure. | very strong | exact bytes/global | UID00012M metadata/prose | incorporate | applied |
| C2NA-058 | UID00012N retains exact Pane-typed setter and gains source position/score closure. | very strong | raw body/Pane contract | UID00012N metadata/prose | incorporate | applied |
| C2NA-059 | UID00012O retains exact OnPaint body and gains source position/score closure. | very strong | complete body/vtable slot | UID00012O metadata/prose | incorporate | applied |
| C2NA-060 | UID00012P is compiler adjustor glue and should rise to `92/94` without emission. | very strong | exact two thunks | UID00012P score/prose | incorporate | applied |
| C2NA-061 | UID00012Q is compiler scalar deleting glue and should rise to `92/94` without emission. | very strong | exact 29 instructions | UID00012Q score/prose | incorporate | applied |
| C2NA-062 | UID0000QR should emit one `DescPane *g_pDescPane = NULL;` definition at file position 20. | very strong | zero-filled storage/four refs | UID0000QR formal/metadata | incorporate | applied |
| C2NA-063 | UID0001PB should be `92/94`, position 10 under UID0000QR, with covered-storage marker only. | very strong | exact storage/lifecycle | UID0001PB formal/metadata | incorporate | applied |
| C2NA-064 | UID00003Q should be `92/94`, position 10 under UID0000IS, with complete declaration. | very strong | complete class closure | UID00003Q metadata/formal | incorporate | applied |
| C2NA-065 | UID0000IS should be `92/94` and record complete source ordering/output assertions. | strong | complete bounded source union | UID0000IS score/prose | incorporate | applied |
| C2NA-066 | UID0001U3 should be `92/94` with covered-layout marker, not a duplicate struct. | very strong | exact class tail/full declaration | UID0001U3 metadata/formal | incorporate | applied |
| C2NA-067 | UID0001XC should be `92/94` with complete 18/11/2 inventory, `[[CHILDREN]]`, and no table array. | very strong | complete table/RTTI evidence | UID0001XC metadata/formal | incorporate | applied |
| C2NA-068 | Current Pane class/file/vtable docs already preserve `GetParentPane`; support must add the `+0x10` `DrawOnTarget` direction and replace the stale `Repaint` row remaining in PaneCore. | strong | direct caller/override evidence plus concurrent current union | UID0000A2/0000MC/0001EA/0003JA/0003CA | incorporate | applied |
| C2NA-069 | UID0003CA should rise from `85/91` to `90/93` with complete primary/secondary/tertiary slot inventory. | strong | full inherited slot resolution | UID0003CA score/prose | incorporate | applied |
| C2NA-070 | Parent UID000254, EventHandler UID00004N, and TimerHandler UID0000F0 remain verify-only at current metadata/formals. | very strong | current docs agree | verify-only support | already-present | already-present |
| C2NA-071 | Generated DescPane.cpp contains one declaration, five bodies, one global definition, four coverage comments, and no empty/no-children/compiler-body duplicates. | strong | accepted route/order and generated readback | generated verification | incorporate | applied |
| C2NA-072 | Manual coverage rows listed below require supervisor-owned synchronization after accepted implementation; B001 must not edit them. | very strong | current manual row audit | manual coverage handoff | incorporate | applied |

### Callback Verification Notes

| Claim ID | Callback proof |
| --- | --- |
| C2NA-001 | UID0002NA now carries the exact 132-byte sequence and SHA256 `AFE5BFEE1C4D768F45C845EB1A9C27EC394E335691D4C929EE443B982F5CF56C`; validator `000000014174` passed. |
| C2NA-002 | UID0002NA records `.rdata` placement and raw offset `0x2173dc`; validator `000000014174` passed. |
| C2NA-003 | UID0002NA records relocation-directory RVA/size zero and the source-declared/generated-binary disposition; validator `000000014174` passed. |
| C2NA-004 | UID0002NA records the excluded primary COL at `0x006189d8`; validator `000000014174` passed. |
| C2NA-005 | UID0002NA historicalizes the stale exclusion and records the secondary COL at `0x00618a24` as physically in range; validator `000000014174` passed. |
| C2NA-006 | UID0002NA historicalizes the stale exclusion and records the tertiary COL at `0x00618a54` as physically in range; validator `000000014174` passed. |
| C2NA-007 | UID0002NA records the DialogPane COL at `0x00618a60` as the exact successor; validator `000000014174` passed. |
| C2NA-008 | Current target path/range remained unchanged and no split/padding page was created; final target hash is `2569221690FDCDAFA5A4ED0517511BC44A6C64A040D9BB08F6528CCF03E29455`. |
| C2NA-009 | UID0002NA retained `Nested:4`; generated structure is balanced and no hierarchy change was introduced. |
| C2NA-010 | UID0002NA now has owner UID00003Q and emitter UID0001XC; validator `000000014174` passed. |
| C2NA-011 | UID0002NA and UID0001XC contain the complete 18-slot primary inventory; validators `000000014174` and `000000014199` passed. |
| C2NA-012 | Primary `+0x00` scalar-wrapper identity and compiler-only disposition are present in UID0002NA/UID0001XC/UID00012Q; validators `000000014174`, `000000014199`, and `000000014187` passed. |
| C2NA-013 | Primary `+0x04` LObject runtime-class accessor identity is present in UID0002NA and UID0001XC; validators `000000014174` and `000000014199` passed. |
| C2NA-014 | Primary `+0x08` LObject change-message no-op identity is present in UID0002NA and UID0001XC; validators `000000014174` and `000000014199` passed. |
| C2NA-015 | Primary `+0x0c` `UpdateRenderRegion` identity is present in UID0002NA/UID0001XC and preserved in the current Pane union; validators `000000014174`, `000000014199`, and `000000014207` passed. |
| C2NA-016 | `DrawOnTarget` direction is present in UID0002NA, UID0001XC, Pane class/file/core/vtable data; validators `000000014174`, `000000014199`, `000000014207`, `000000014209`, `000000014211`, `000000014213`, and `000000014215` passed. |
| C2NA-017 | Primary `+0x14` `Pane::Show` identity is present in UID0002NA and UID0001XC; validators `000000014174` and `000000014199` passed. |
| C2NA-018 | Primary `+0x18` `Pane::Hide` identity is present in UID0002NA and UID0001XC; validators `000000014174` and `000000014199` passed. |
| C2NA-019 | `GetParentPane` is current in UID0002NA/UID0001XC/Pane support and stale `Repaint` was corrected in PaneCore; validators `000000014174`, `000000014199`, and `000000014211` passed. |
| C2NA-020 | Primary `+0x20` `InvalidateRect` identity is present in UID0002NA/UID0001XC; validators `000000014174` and `000000014199` passed. |
| C2NA-021 | Primary `+0x24` `GetDescription(int,wchar_t *)` identity is present in UID0002NA/UID0001XC and consumed by UID00012O; validators `000000014174`, `000000014199`, and `000000014185` passed. |
| C2NA-022 | Primary `+0x28` `GetScreenBounds` identity is present in UID0002NA/UID0001XC; validators `000000014174` and `000000014199` passed. |
| C2NA-023 | Primary `+0x2c` `SetBounds` identity is present in UID0002NA/UID0001XC; validators `000000014174` and `000000014199` passed. |
| C2NA-024 | Primary `+0x30` `AddToLayer` identity is present in UID0002NA/UID0001XC; validators `000000014174` and `000000014199` passed. |
| C2NA-025 | Primary `+0x34` `InsertInLayer` identity is present in UID0002NA/UID0001XC; validators `000000014174` and `000000014199` passed. |
| C2NA-026 | Primary `+0x38` `RemoveFromLayer` identity is present in UID0002NA/UID0001XC; validators `000000014174` and `000000014199` passed. |
| C2NA-027 | Primary `+0x3c` `SetPaneOrder` direction is present in UID0002NA/UID0001XC; validators `000000014174` and `000000014199` passed. |
| C2NA-028 | Primary `+0x40` `UnregisterEventHandler` identity is present in UID0002NA/UID0001XC; validators `000000014174` and `000000014199` passed. |
| C2NA-029 | Primary `+0x44` is documented as exact `DescPane::OnPaint`; UID00012O retains the accepted body at position 50; validators `000000014174`, `000000014199`, and `000000014185` passed. |
| C2NA-030 | UID0002NA and UID0001XC contain the complete 11-slot secondary inventory; validators `000000014174` and `000000014199` passed. |
| C2NA-031 | Secondary deleting-destructor adjustor identity is present in UID0002NA/UID0001XC/UID00012P; validators `000000014174`, `000000014199`, and `000000014186` passed. |
| C2NA-032 | Secondary pointer/mouse bridge identity is present in UID0002NA/UID0001XC; validators `000000014174` and `000000014199` passed. |
| C2NA-033 | Secondary key/text bridge identity is present in UID0002NA/UID0001XC; validators `000000014174` and `000000014199` passed. |
| C2NA-034 | Secondary IME bridge identity is present in UID0002NA/UID0001XC; validators `000000014174` and `000000014199` passed. |
| C2NA-035 | Secondary packet bridge identity is present in UID0002NA/UID0001XC; validators `000000014174` and `000000014199` passed. |
| C2NA-036 | Secondary system/control bridge identity is present in UID0002NA/UID0001XC; validators `000000014174` and `000000014199` passed. |
| C2NA-037 | Secondary type-19 bridge identity is present in UID0002NA/UID0001XC; validators `000000014174` and `000000014199` passed. |
| C2NA-038 | Secondary `ForwardHandlerOrder` identity is present in UID0002NA/UID0001XC; validators `000000014174` and `000000014199` passed. |
| C2NA-039 | Secondary local-pair identity is present in UID0002NA/UID0001XC; validators `000000014174` and `000000014199` passed. |
| C2NA-040 | Secondary screen-pair identity is present in UID0002NA/UID0001XC; validators `000000014174` and `000000014199` passed. |
| C2NA-041 | Secondary acceptance-predicate identity is present in UID0002NA/UID0001XC; validators `000000014174` and `000000014199` passed. |
| C2NA-042 | UID0002NA and UID0001XC contain the complete two-slot tertiary inventory; validators `000000014174` and `000000014199` passed. |
| C2NA-043 | Tertiary deleting-destructor adjustor identity is present in UID0002NA/UID0001XC/UID00012P; validators `000000014174`, `000000014199`, and `000000014186` passed. |
| C2NA-044 | Tertiary inherited `OnTimer` default is present in UID0002NA/UID0001XC; TimerHandler remained unchanged at accepted detail; validators `000000014174` and `000000014199` passed. |
| C2NA-045 | All three COL/type/CHD facts are present in UID0002NA and UID0001XC; validators `000000014174` and `000000014199` passed. |
| C2NA-046 | Six-entry RTTI hierarchy is present in UID0002NA/UID0001XC/UID0001U3; validators `000000014174`, `000000014199`, and `000000014194` passed. |
| C2NA-047 | UID00003Q now emits `class DescPane : public Pane`; validator `000000014175` passed and generated output contains that declaration once. |
| C2NA-048 | `+0xa0/+0xa4` inherited facet layout is present in UID00003Q/UID0001U3/UID0001XC; validators `000000014175`, `000000014194`, and `000000014199` passed. |
| C2NA-049 | UID00003Q and UID0001U3 record the borrowed `Pane *` at `+0xf8`, index at `+0xfc`, and size `0x100`; validators `000000014175` and `000000014194` passed. |
| C2NA-050 | UID00003Q contains the complete managed declaration, with `};` before `[[CHILDREN]]`; validator `000000014175` passed and current generated lines 26/29 prove closure before qualified definitions. |
| C2NA-051 | UID00012J/L/M/N/O positions are 10/20/30/40/50; validators `000000014178`, `000000014179`, `000000014181`, `000000014183`, and `000000014185` passed. |
| C2NA-052 | UID0001U3 and UID0001XC positions are 60/70; validators `000000014194` and `000000014199` passed. |
| C2NA-053 | UID0002NA position 10 beneath UID0001XC is applied; validator `000000014174` passed. |
| C2NA-054 | UID00012K is `92/93`, false, non-emitting, blank position/formal; validator `000000014176` passed and current generated output has no no-children artifact. |
| C2NA-055 | UID00012J retains the constructor body and historicalizes the superseded custom-provider type; validator `000000014178` passed. |
| C2NA-056 | UID00012L is `92/94`, position 20, with exact destructor source/compiler boundary; validator `000000014179` passed. |
| C2NA-057 | UID00012M is `91/93`, position 30, with exact static getter; validator `000000014181` passed. |
| C2NA-058 | UID00012N is `92/93`, position 40, with exact Pane-typed setter; validator `000000014183` passed. |
| C2NA-059 | UID00012O is `92/94`, position 50, with exact OnPaint body; validator `000000014185` passed. |
| C2NA-060 | UID00012P is `92/94` and remains owner-none/false/non-emitting/blank-formal compiler glue; validator `000000014186` passed. |
| C2NA-061 | UID00012Q is `92/94` and remains owner-none/false/non-emitting/blank-formal compiler glue; validator `000000014187` passed. |
| C2NA-062 | UID0000QR is `92/94`, file position 20, and emits one global definition plus children; validator `000000014202` passed. |
| C2NA-063 | UID0001PB is `92/94`, position 10 under UID0000QR, with one covered-storage marker; validator `000000014204` passed. |
| C2NA-064 | UID00003Q is `92/94`, position 10 under UID0000IS, with the complete declaration; validator `000000014175` passed. |
| C2NA-065 | UID0000IS is `92/94` and records the complete source order/output/compiler exclusions; validator `000000014206` passed. |
| C2NA-066 | UID0001U3 is `92/94`, position 60, with the covered-layout marker and no duplicate struct; validator `000000014194` passed. |
| C2NA-067 | UID0001XC is `92/94`, position 70, with complete 18/11/2 inventory, marker, and `[[CHILDREN]]`; validator `000000014199` passed. |
| C2NA-068 | The no-loss Pane union was preserved while `DrawOnTarget` and PaneCore `GetParentPane` direction were synchronized across five accepted pages; validators `000000014207`, `000000014209`, `000000014211`, `000000014213`, and `000000014215` passed. |
| C2NA-069 | UID0003CA is `90/93` with complete three-view inventory; validator `000000014215` registered/validated its existing page without changing owner/emitter/formal route. |
| C2NA-070 | UID000254, EventHandler, and TimerHandler hashes remain `DE4B279D...E3FEBA`, `38033240...AD9EB1`, and `FBE38D7B...729D017`; no edit was needed. |
| C2NA-071 | B001 final waited target command `000000014216` passed. Evidence-time validator-owned generated checkpoint `000000014231` retained one class, five methods, one global, four markers, and zero empty/no-children/ABI-wrapper duplicates. |
| C2NA-072 | B001 made no manual coverage edit. Current read-only hashes are recorded below; affected rows remain stale and exact external supervisor-owned replacement text is supplied. |

## Positive Evidence Summary

- Exact bytes and independent hash agree between MCP and the PE file.
- All 33 dwords have coherent roles: 31 callable entries and two internal
  DescPane COL pointers.
- Constructor, ordinary destructor, and scalar wrapper each write/restore all
  three vtable bases.
- RTTI directly proves one `DescPane : Pane` source class and inherited
  EventHandler/TimerHandler facets at `+0xa0/+0xa4`.
- All primary slots align with the current Pane virtual order; all secondary
  slots align with the current EventHandler declaration; both tertiary slots
  align with TimerHandler.
- The sole class-specific primary method is exact `DescPane::OnPaint`.
- Existing constructor/destructor/getter/setter/paint bodies already form a
  coherent source union once the missing class/global declaration and source
  ordering are supplied.
- `g_pDescPane` has exactly four refs, all in the DescPane island.
- The implemented class/global source shape naturally causes the compiler to
  regenerate vtables, RTTI, vptr stores, adjustors, and deleting wrapper.

## IDA MCP Facts

MCP provenance:

- Active IDB session: `64c11373`.
- Worker PID: `21508`.
- Input: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Health: `ok`; analysis, Hex-Rays, and string cache ready.

Target bytes:

```text
40 d8 49 00 10 4b 4f 00 c0 b6 41 00 20 8e 4b 00
80 d6 41 00 30 47 54 00 50 47 54 00 a0 47 54 00
00 48 54 00 20 4a 54 00 80 4b 54 00 d0 4b 54 00
70 4c 54 00 b0 4c 54 00 e0 4c 54 00 30 4d 54 00
70 4d 54 00 c0 d7 49 00 a4 65 64 00 1e d8 49 00
b0 4d 54 00 c0 4d 54 00 d0 4d 54 00 e0 4d 54 00
f0 4d 54 00 00 4e 54 00 f0 89 4a 00 10 4e 54 00
30 4e 54 00 70 4e 54 00 b8 65 64 00 29 d8 49 00
90 4e 54 00
```

PE facts:

- Original image SHA256:
  `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- Image base `0x00400000`.
- `.rdata` RVA `0x0020d000`, target raw file offset `0x2173dc`.
- Base-relocation directory RVA `0x00000000`, size `0`.

RTTI facts:

- `0x00646548`: DescPane primary COL, offset `0`.
- `0x006465a4`: DescPane secondary COL, offset `0xa0` / 160
  (Verified with `int_convert.py`).
- `0x006465b8`: DescPane tertiary COL, offset `0xa4` / 164
  (Verified with `int_convert.py`).
- All three use type descriptor `0x00675b68`, `.?AVDescPane@@`, and CHD
  `0x0064655c`.
- CHD attributes `0x1`, six base descriptors:

| Base order | Type | Contained bases | PMD `(mdisp,pdisp,vdisp)` |
| ---: | --- | ---: | --- |
| 0 | DescPane | 5 | `(0,-1,0)` |
| 1 | Pane | 4 | `(0,-1,0)` |
| 2 | GrafPort | 1 | `(0,-1,0)` |
| 3 | LObject | 0 | `(0,-1,0)` |
| 4 | EventHandler | 0 | `(160,-1,0)` |
| 5 | TimerHandler | 0 | `(164,-1,0)` |

Vptr-store xrefs:

- Primary base `0x006189dc`: `0x0049d701`, `0x0049d740`,
  `0x0049d846`.
- Secondary base `0x00618a28`: `0x0049d709`, `0x0049d746`,
  `0x0049d84c`.
- Tertiary base `0x00618a58`: `0x0049d713`, `0x0049d750`,
  `0x0049d856`.

COL xrefs:

- `0x00646548` from `0x006189d8`.
- `0x006465a4` from `0x00618a24`.
- `0x006465b8` from `0x00618a54`.
- `0x006465cc` from `0x00618a60`.

Compiler-wrapper facts:

- `0x0049d81e`, size `0x0b`: subtract `0xa0`, jump to `0x0049d840`.
- `0x0049d829`, size `0x0b`: subtract `0xa4`, jump to `0x0049d840`.
- `0x0049d840`, size `0x5f`, 29 instructions: restore three vptrs,
  clear singleton, call Pane cleanup, test flags `1` and `4`, optionally free,
  return with `retn 4`.
- Xrefs to `0x0049d840`: code jumps `0x0049d824` and `0x0049d82f`,
  data cell `0x006189dc`.

Negative MCP facts:

- No target dword is padding or an executable entry.
- No additional DescPane table slot exists before `0x00618a60`.
- No separate DescPane provider type/vtable is required.
- No ordinary source call targets the deleting wrapper.
- No source evidence supports direct DescPane inheritance from EventHandler or
  TimerHandler.

## Function / Child Inventory

Primary view:

| Cell / offset | Target | Strongest source identity | Source disposition |
| --- | --- | --- | --- |
| `0x006189dc / +0x00` | `0x0049d840` | DescPane scalar deleting destructor | compiler-generated |
| `0x006189e0 / +0x04` | `0x004f4b10` | inherited LObject runtime-class accessor | inherited |
| `0x006189e4 / +0x08` | `0x0041b6c0` | inherited LObject change-message default | inherited no-op |
| `0x006189e8 / +0x0c` | `0x004b8e20` | `UpdateRenderRegion(const RectBounds *)` | inherited |
| `0x006189ec / +0x10` | `0x0041d680` | `DrawOnTarget(GrafPort *, const RectBounds *, const RectBounds *)` direction | inherited no-op |
| `0x006189f0 / +0x14` | `0x00544730` | `Pane::Show()` | inherited |
| `0x006189f4 / +0x18` | `0x00544750` | `Pane::Hide()` | inherited |
| `0x006189f8 / +0x1c` | `0x005447a0` | `Pane::GetParentPane() const` direction | inherited |
| `0x006189fc / +0x20` | `0x00544800` | `Pane::InvalidateRect(const RectBounds *)` | inherited |
| `0x00618a00 / +0x24` | `0x00544a20` | `Pane::GetDescription(int,wchar_t *)` | inherited |
| `0x00618a04 / +0x28` | `0x00544b80` | `Pane::GetScreenBounds(RectBounds *)` | inherited |
| `0x00618a08 / +0x2c` | `0x00544bd0` | `Pane::SetBounds(const RectBounds *,const RectBounds *)` | inherited |
| `0x00618a0c / +0x30` | `0x00544c70` | `Pane::AddToLayer(...)` | inherited |
| `0x00618a10 / +0x34` | `0x00544cb0` | `Pane::InsertInLayer(...)` | inherited |
| `0x00618a14 / +0x38` | `0x00544ce0` | `Pane::RemoveFromLayer()` | inherited |
| `0x00618a18 / +0x3c` | `0x00544d30` | `Pane::SetPaneOrder(Pane *,Pane *)` direction | inherited |
| `0x00618a1c / +0x40` | `0x00544d70` | `Pane::UnregisterEventHandler()` | inherited |
| `0x00618a20 / +0x44` | `0x0049d7c0` | `DescPane::OnPaint()` | source override |

Secondary EventHandler view:

| Cell / offset | Target | Strongest source identity | Source disposition |
| --- | --- | --- | --- |
| `0x00618a28 / +0x00` | `0x0049d81e` | deleting-destructor adjustor `this-0xa0` | compiler-generated |
| `0x00618a2c / +0x04` | `0x00544db0` | `HandlePointerOrMouseEvent(Event *)` | inherited bridge/default |
| `0x00618a30 / +0x08` | `0x00544dc0` | `HandleKeyOrTextEvent(Event *)` | inherited bridge/default |
| `0x00618a34 / +0x0c` | `0x00544dd0` | `HandleImeEvent(Event *)` | inherited bridge/default |
| `0x00618a38 / +0x10` | `0x00544de0` | `HandlePacketEvent(Event *)` | inherited bridge/default |
| `0x00618a3c / +0x14` | `0x00544df0` | `HandleSystemOrControlEvent(Event *)` | inherited bridge/default |
| `0x00618a40 / +0x18` | `0x00544e00` | `HandleType19Event(Event *)` | inherited bridge/default |
| `0x00618a44 / +0x1c` | `0x004a89f0` | `ForwardHandlerOrder(EventHandler *,EventHandler *)` | inherited |
| `0x00618a48 / +0x20` | `0x00544e10` | `GetLocalEventPair(EventPointPair *)` | inherited |
| `0x00618a4c / +0x24` | `0x00544e30` | `GetScreenEventPair(EventPointPair *)` | inherited |
| `0x00618a50 / +0x28` | `0x00544e70` | `ShouldAcceptEvent() const` | inherited |

Tertiary TimerHandler view:

| Cell / offset | Target | Strongest source identity | Source disposition |
| --- | --- | --- | --- |
| `0x00618a58 / +0x00` | `0x0049d829` | deleting-destructor adjustor `this-0xa4` | compiler-generated |
| `0x00618a5c / +0x04` | `0x00544e90` | `bool OnTimer(int timerId,int arg0,int arg1)` default | inherited |

DescPane source/support inventory:

| UID / path | Role | Pre-callback state | Applied state |
| --- | --- | --- | --- |
| UID00003Q `by-class/DescPane.md` | complete class declaration | `88/91`, empty emitter | `92/94`, class block, position 10 |
| UID00012J constructor | source method | `88/90`, body present | `91/93`, body retained, position 10 |
| UID00012L destructor | source method | `88/91`, body present | `92/94`, body retained, position 20 |
| UID00012M getter | source method | `88/90`, body present | `91/93`, body retained, position 30 |
| UID00012N setter | source method | `90/91`, body present | `92/93`, body retained, position 40 |
| UID00012O OnPaint | source override | `90/92`, body present | `92/94`, body retained, position 50 |
| UID0001U3 layout | declaration evidence | `89/92`, empty emitter | `92/94`, coverage marker, position 60 |
| UID0001XC vtables | declaration evidence/route | `88/93`, empty emitter | `92/94`, marker plus children, position 70 |
| UID0002NA target | exact data evidence | `86/90`, empty emitter | `92/94`, marker, position 10 under UID0001XC |
| UID0000QR global | source definition | `88/86`, empty emitter | `92/94`, definition plus children, file position 20 |
| UID0001PB storage | data evidence | `86/90`, empty emitter | `92/94`, storage marker, position 10 |
| UID00012K aggregate | physical index | `89/91`, emits no-children marker | `92/93`, false/no-emitter/blank |
| UID00012P adjustors | compiler glue | `88/92`, false/no-emitter | `92/94`, same disposition |
| UID00012Q scalar wrapper | compiler glue | `86/92`, false/no-emitter | `92/94`, same disposition |

## Direct Xref / Caller Inventory

| Address / item | Xref / caller / callee | Meaning |
| --- | --- | --- |
| `0x006189dc` | stores from `0x0049d701`, `0x0049d740`, `0x0049d846` | primary vptr in constructor, ordinary destructor, scalar wrapper |
| `0x00618a28` | stores from `0x0049d709`, `0x0049d746`, `0x0049d84c` | EventHandler-view vptr at object `+0xa0` |
| `0x00618a58` | stores from `0x0049d713`, `0x0049d750`, `0x0049d856` | TimerHandler-view vptr at object `+0xa4` |
| `0x0049d840` | `0x0049d824`, `0x0049d82f`, `0x006189dc` | two adjustor jumps plus primary vtable cell |
| `0x0049d7c0` | `0x00618a20` only | vtable-only DescPane OnPaint reachability |
| `0x00646548` | `0x006189d8` only | primary DescPane COL |
| `0x006465a4` | `0x00618a24` only | secondary DescPane COL |
| `0x006465b8` | `0x00618a54` only | tertiary DescPane COL |
| `0x006465cc` | `0x00618a60` only | successor DialogPane COL |
| `0x0069adf8` | `0x0049d731`, `0x0049d75a`, `0x0049d770`, `0x0049d860` | constructor publish, ordinary clear, getter read, wrapper clear |
| `0x0041d680` | 381 data refs | shared inherited target-draw default, not DescPane-specific |
| `0x005c1810` | one weather vtable data ref | concrete custom-target draw replacement |
| `0x005c20e0` | one weather vtable data ref | concrete custom-target draw replacement |
| `0x005c26b0` | one weather vtable data ref | concrete custom-target draw replacement |
| `0x005447a0` | calls UID0004O9 `Layer::GetParentPane` | resolves stale Repaint label |

## Documentation Evidence And IDA Status

Historical pre-callback ordinary artifact matrix at the accepted Gate 1
evidence checkpoint:

| Path | SHA256 | Bytes / lines |
| --- | --- | --- |
| `by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md` | `E41E2F791A1CC7DDDC7BA130796173DA615A1FC129A98B4D0D4331CD3F573C22` | 8,935 / 95 |
| `by-class/DescPane.md` | `21FC599730843B41CBB493EA43D91283FA9A46C497605DC933C1951DE1116C67` | 24,377 / 148 |
| `by-file/DescPane.md` | `E0FB94F841F28A150E86EFE97B9B4E02B95BF5583B170A7D624EA6E54012E293` | 18,899 / 172 |
| `by-type/by-vtable/DescPaneVtables.md` | `0571C7EFCF7A48B8564816FB3C83765C14805E4495DBCCE57A8B7805703EA26B` | 14,017 / 113 |
| `by-type/by-struct/DescPaneLayout.md` | `C5694961D9A663CD2CD975A332EA47BF1808DF9C5D654A88BE1ADAB08DC042DE` | 13,479 / 107 |
| `by-memory/0x0049d6f0-0x0049d89f.DescPane.md` | `FD8913FC01491E895334987BA52424C7553FBA6BF5CC0D218B6A8774C82FC3FB` | 29,414 / 174 |
| `by-memory/0x0049d6f0-0x0049d73c.DescPaneConstructorRaw.md` | `7C07D9B318DCDD2578B467F919C49D4E7F60F9AFA484764F945EA5573E7F66E8` | 14,891 / 168 |
| `by-memory/0x0049d740-0x0049d769.DescPaneDestructor.md` | `6AFFB8AB16C2832E1AE0BF04695EC987AA684B2A05BA6F40B85E7687BAC62193` | 13,072 / 116 |
| `by-memory/0x0049d770-0x0049d776.DescPaneGetSingleton.md` | `B775BA62CCAFC247E19328EEA368E735C8738598DF454CFBDDE11AEB32ABBF03` | 10,535 / 96 |
| `by-memory/0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw.md` | `A878CCB9273ACE386B4405F126596A3ADE0769E5E35B8DD8CAC83728DB15B84B` | 13,741 / 145 |
| `by-memory/0x0049d7c0-0x0049d81e.DescPaneOnPaint.md` | `57D9934767404C68F1CD801321D8FF778F4B11FC35BBBF935A4767FDB0D15D66` | 9,061 / 104 |
| `by-memory/0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks.md` | `15DB12441C0B14DB7773A3B813FA6902070BAEB76750E62DC86D1F3668667F28` | 4,452 / 62 |
| `by-memory/0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor.md` | `64BCA963F9F60C7AB35B1101F6F96D42E75542C06D6B4CAC0D52FA97A635CB76` | 8,921 / 81 |
| `by-global/g_pDescPane.md` | `2DECD0442B2049AB8AB0C9190499501B6F88C172E73889CC8F23DBEBABAB71A1` | 4,782 / 58 |
| `by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md` | `8624A489409EFFDF583ECF65C33F79C4409DE8FE0B52E7DEB196ECFA31247D87` | 8,831 / 83 |
| `by-class/Pane.md` | `52DE8ABC62527FFA6995C9EB903BF9D3F3D75DA703BA37DA3E21A690FCC5009C` | 19,439 / 150 |
| `by-file/Pane.md` | `A2F944927689914824683D9413F919384807BB7FFDBBA2E4FAA7D37A6855238E` | 22,260 / 160 |
| `by-memory/0x00544460-0x00545086.PaneCore.md` | `D118C5B2EF39D35359C57003DB2593FCD87CAB3B3111293AE3466DC0EA4EE5E6` | 18,322 / 127 |
| `by-type/by-vtable/PaneVtables.md` | `A1CBCC1A8387C6267F2FDDCDC768B56C6DFDF997BA3295EF7FF74B78E3791D13` | 11,433 / 116 |
| `by-memory/0x006219e8-0x00621a6c.PaneVtableData.md` | `265E92169E7A97054989D05864BF2E930AC86E2F868D09DA315ABD66092572D3` | 7,712 / 90 |
| `by-memory/0x006189dc-0x00618e50.DialogCoreReadOnlyData.md` | `DE4B279DB59A94078594DEFC4A5AFFA2309716F1C09893EF0FAD2811D3E3FEBA` | 16,357 / 128 |
| `by-class/EventHandler.md` | `38033240D695B08EB3404F722953F1243DD2DE6B2C2724FB7B59995873AD9EB1` | 19,864 / 172 |
| `by-class/TimerHandler.md` | `FBE38D7BEB2CCA34E3CF58C4891B526F170CF911CC39F4C065597EB3D729D017` | 17,937 / 114 |

Current post-callback ordinary artifact matrix:

| Path | SHA256 | Bytes / lines |
| --- | --- | --- |
| `by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md` | `2569221690FDCDAFA5A4ED0517511BC44A6C64A040D9BB08F6528CCF03E29455` | 14,981 / 205 |
| `by-class/DescPane.md` | `CE053F4533DB5532D08F7B119BBCBDE7F93DFCD013C9C7363F6549131C2F1EB5` | 26,956 / 220 |
| `by-file/DescPane.md` | `68DFA88ECAE68D57F96ACD1B86031D04FCDAE2A3AAA12B49D3D30F7AA7F59FCE` | 18,503 / 171 |
| `by-type/by-vtable/DescPaneVtables.md` | `CF379545963D60963A94D1F08DBF81561281835387701F401D2820C30F7EA659` | 16,436 / 170 |
| `by-type/by-struct/DescPaneLayout.md` | `E57B4AA1304C5F547827265F353DBF099AD7C71D28F3913B625F1ACAC379979B` | 14,637 / 135 |
| `by-memory/0x0049d6f0-0x0049d89f.DescPane.md` | `73AC04EE00EB76FF9AEF71C0CBC8D9D7B6AC83B9E13FD21561848594AD8A5FE6` | 29,408 / 210 |
| `by-memory/0x0049d6f0-0x0049d73c.DescPaneConstructorRaw.md` | `027423BAC9657FDA785F81716215C7A8C5D97C2D38A64B621AA07230219F4604` | 15,072 / 206 |
| `by-memory/0x0049d740-0x0049d769.DescPaneDestructor.md` | `CCC74457A4616A42E62686E0EEC97065C85B60FA3A35B1CBF9CAE5F7042CE0AC` | 13,719 / 141 |
| `by-memory/0x0049d770-0x0049d776.DescPaneGetSingleton.md` | `E5B1A4E6A2262C585702DF8920F06ADE340E01ED73947AD3B4B45514CFAF6B32` | 11,282 / 115 |
| `by-memory/0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw.md` | `AD055C66B83D02A62B26EDBDC36EC6B8B4395032D796F630EE8C666FBFB5D59F` | 14,494 / 163 |
| `by-memory/0x0049d7c0-0x0049d81e.DescPaneOnPaint.md` | `D62E36AC986F5F93DFE1B12B8F4335A91348B1979BCFEDAABB4ABF102DB6A025` | 10,009 / 127 |
| `by-memory/0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks.md` | `169992A75B94D24A037C8C0A0153DD51D152266E739D7A585171B4AC89DEC123` | 5,066 / 78 |
| `by-memory/0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor.md` | `16FEAF767C362755547DCFC5D451E065A04C9754716DB3B533132B508FBBB8E9` | 10,005 / 102 |
| `by-global/g_pDescPane.md` | `9CDEDBC3AD3A86A85A4E7E43ADAEE205FCA2FAC2A66A1FEA485B0E090EB50BB5` | 5,867 / 82 |
| `by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md` | `B191A127CD26D98155560179BCC761CB87CC1F3097BD2A5888D20DE7A1D04FEB` | 9,534 / 102 |
| `by-class/Pane.md` | `C0A7AFC85C571E1695E93DE021FB183AE65E70E7E931FED605826945981C52EA` | 20,725 / 175 |
| `by-file/Pane.md` | `71F3041CF5DE8FDF2F61F4F902510A1FE46108CE78450955BCD0EDD1BE7C68DB` | 23,383 / 182 |
| `by-memory/0x00544460-0x00545086.PaneCore.md` | `C0DDCBAAA664E4C82D895733E6F9F3798EF99DB3527A3F30486F1F1E6BB4FF36` | 19,346 / 150 |
| `by-type/by-vtable/PaneVtables.md` | `B8381FCA8BC9F44C3D19CA1112CF54A5BA8D3C2BD465A071D3303D31DB763B82` | 12,406 / 137 |
| `by-memory/0x006219e8-0x00621a6c.PaneVtableData.md` | `C5E8F33B43F9D13661C95BD7571AAF0C4B851E4397E03834FDC0887543635467` | 11,095 / 161 |
| `by-memory/0x006189dc-0x00618e50.DialogCoreReadOnlyData.md` | `DE4B279DB59A94078594DEFC4A5AFFA2309716F1C09893EF0FAD2811D3E3FEBA` | 16,357 / 128 |
| `by-class/EventHandler.md` | `38033240D695B08EB3404F722953F1243DD2DE6B2C2724FB7B59995873AD9EB1` | 19,864 / 172 |
| `by-class/TimerHandler.md` | `FBE38D7BEB2CCA34E3CF58C4891B526F170CF911CC39F4C065597EB3D729D017` | 17,937 / 114 |

Historical pre-callback documentation defects, now repaired:

- UID0002NA excluded two physically in-range COL dwords and did not list every
  slot; current target and vtable docs contain the complete inventory.
- Concurrent B004 UID0002NB support synchronization had already corrected
  `GetParentPane` and the inherited EventHandler/TimerHandler order in current
  Pane class/file/vtable docs. This callback added the bounded primary
  `+0x10` `DrawOnTarget` direction without replacing that concurrent union.
- PaneCore retained stale `Pane::Repaint` at `0x005447a0`; current prose names
  `GetParentPane` and records the target-draw default separately.
- UID00012J presented provisional custom-provider declarations as current;
  those assumptions are now explicitly historical.
- UID00012K's marker could not attach children and emitted a no-children
  artifact; it is now a blank non-emitting split/index.
- DescPane class/layout/vtable/global/storage pages were valid evidence pages
  but empty emitters; the accepted declarations/definitions/coverage markers
  are now applied.

Same-or-greater current documentation:

- UID00012N and UID00012O already use concrete `Pane *`.
- UID00012P and UID00012Q already have correct non-emitting compiler
  dispositions.
- UID000254 correctly remains a non-emitting mixed read-only-data index.
- EventHandler and TimerHandler declarations already provide the inherited
  contracts required by the secondary and tertiary views.

## Ranked Ownership Analysis

### 1. UID00003Q DescPane class

- Evidence for: all three COLs name DescPane; constructor/destructor/wrapper
  store all three vptrs; OnPaint is class-specific; layout tail and singleton
  are class-local; source file already exists.
- Evidence against: none material. Original PDB spelling is unavailable but the
  decorated RTTI class name is exact.
- Decision: direct semantic owner for UID0002NA, UID0001XC, and UID0001U3.

### 2. UID0001XC DescPaneVtables

- Evidence for: narrow type page already owns the table layout and routes to
  the class; useful emitter intermediary for target evidence.
- Evidence against: a vtable type page is not the direct semantic owner of the
  class's compiler-emitted bytes.
- Decision: retain as UID0002NA emitter/routing parent, not canonical owner.

### 3. UID0000IS DescPane file

- Evidence for: exact source root for class, methods, and singleton definition.
- Evidence against: broader than the class; by-structure requires the narrowest
  semantic owner.
- Decision: file root only, reached through UID00003Q/UID0000QR.

### 4. UID000254 DialogCoreReadOnlyData

- Evidence for: physical address container and generated nesting parent.
- Evidence against: mixed classes and resource strings; explicitly
  non-reconstructable.
- Decision: retain only as physical parent/index; never source owner/emitter.

### 5. Pane, DialogPane, feature-dialog, or anonymous data owner

- Evidence for: Pane supplies inherited slots; DialogPane is adjacent.
- Evidence against: neither owns DescPane RTTI, local override, fields,
  singleton, or lifecycle island; DialogPane starts at the successor boundary.
- Decision: reject.

## Source Placement

- Header direction: `NexusTK/ui/controls/DescPane.h`, containing the class
  declaration and `extern DescPane *g_pDescPane`.
- Definition direction: `NexusTK/ui/controls/DescPane.cpp`, containing the five
  existing method definitions and one global definition.
- Base dependencies: Pane declaration/header, inherited GrafPort drawing and
  bounds types, EventHandler, TimerHandler.
- No standalone `DescPaneVtables.cpp`, `DescPaneLayout.cpp`, RTTI source,
  compiler-wrapper source, or feature-dialog owner is warranted.
- The class page is the proper source declaration destination. Method pages
  remain the proper source body destinations. UID0000QR is the proper global
  definition destination.
- Remaining source placement uncertainty: exact original include factoring is
  stripped. It does not affect owner, emitter, declaration, or generated source
  correctness.

## Range / Split / Padding / Reclassification Analysis

- Exact target range: `[0x006189dc,0x00618a60)`.
- Predecessor:
  - `0x006189d0-0x006189d8` is UTF-16 `"../"` plus terminator.
  - `0x006189d8-0x006189dc` is primary DescPane COL pointer.
- Target contents:
  - primary 18-slot view `[0x006189dc,0x00618a24)`;
  - secondary COL cell `[0x00618a24,0x00618a28)`;
  - secondary 11-slot view `[0x00618a28,0x00618a54)`;
  - tertiary COL cell `[0x00618a54,0x00618a58)`;
  - tertiary 2-slot view `[0x00618a58,0x00618a60)`.
- Successor: `0x00618a60` is DialogPane primary COL and belongs to UID0003AW
  context.
- No padding exists inside the target.
- No target split or rename is recommended.
- Reclassification:
  - target remains reconstructable source-declared/generated-binary;
  - UID00012K becomes non-reconstructable split/index;
  - UID00012P/UID00012Q remain compiler-generated false/no-emitter pages.
- Parent/container impact: UID000254 and target `Nested:4` remain unchanged.

## Negative Evidence Summary

- No PE relocation directory exists.
- No target dword is a relocation record, string, padding, resource, jump
  table, or source-authored const numeric array.
- No extra DescPane slot exists after `0x00618a5c`.
- No direct DescPane EventHandler or TimerHandler base appears in RTTI.
- No custom DescPane provider UDT/vtable is needed or supported.
- No destructor path releases `m_pDescriptionSource`.
- No current evidence supports a persistent description text field.
- No target source method should contain explicit vptr stores.
- No source method should model `this-0xa0` or `this-0xa4` adjustor thunks.
- No source method should model delete flags or call the storage free helper.
- No separate vtable/layout/storage source definition is needed beyond the
  class/global declarations.
- No feature-dialog caller fanout moves the class out of
  `ui/controls/DescPane`.
- No direct constructor/setter/getter caller was recovered. This remains
  historical reachability evidence and a lexical confidence cap, not an owner,
  body, or source-declaration blocker.
- No original PDB or source file string proves `DrawOnTarget`; the selected name
  is behaviorally strongest and explicitly inferred.

## IDA Rename / Type / Comment Recommendations

- IDA database mutation is not requested and was not performed.
- Documentation source-facing names:
  - `DescPane`;
  - `g_pDescPane`;
  - `m_pDescriptionSource`;
  - `m_selectedDescriptionIndex`;
  - `GetSingleton`;
  - `SetSourceAndIndex`;
  - `OnPaint`;
  - inherited `DrawOnTarget`;
  - inherited `GetParentPane`.
- Keep raw aliases such as `sub_49D840`, `nullsub_19`, `sub_5447A0`, and
  `unk_69ADF8` only in binary evidence/search context.
- Type recommendations:
  - `Pane *` for `+0xf8`;
  - `int` for `+0xfc`;
  - `GrafPort *` and `const RectBounds *` arguments for primary `+0x10`;
  - current EventHandler and TimerHandler declaration types for secondary and
    tertiary views.
- Comments on compiler-evidence pages should state coverage by the source
  declaration and explicitly forbid handwritten table/layout/storage output.

## First-Draft C++ Recommendation

Whole-report managed-block count: exactly 11. No body-only C++ appears in this
report.

Destination 1: UID00003Q `by-class/DescPane.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class DescPane;
extern DescPane *g_pDescPane;

class DescPane : public Pane
{
public:
    DescPane();
    virtual ~DescPane();

    static DescPane *GetSingleton();
    void SetSourceAndIndex(Pane *source, int selectedIndex);

protected:
    virtual void OnPaint();

private:
    Pane *m_pDescriptionSource;
    int m_selectedDescriptionIndex;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 2: UID00012J constructor, exact retained block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
DescPane::DescPane()
    : Pane(1),
      m_pDescriptionSource(NULL),
      m_selectedDescriptionIndex(-1)
{
    g_pDescPane = this;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 3: UID00012L destructor, exact retained block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
DescPane::~DescPane()
{
    g_pDescPane = NULL;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 4: UID00012M getter, exact retained block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
DescPane *DescPane::GetSingleton()
{
    return g_pDescPane;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 5: UID00012N setter, exact retained block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void DescPane::SetSourceAndIndex(Pane *source, int selectedIndex)
{
    if (m_pDescriptionSource == source && m_selectedDescriptionIndex == selectedIndex)
        return;

    m_pDescriptionSource = source;
    m_selectedDescriptionIndex = selectedIndex;
    InvalidateRect(&m_bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 6: UID00012O OnPaint, exact retained block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void DescPane::OnPaint()
{
    wchar_t description[1024];

    SetDrawColor(0);
    m_drawMode = 0;
    FillRect(&m_bounds);

    if (m_pDescriptionSource != NULL && m_selectedDescriptionIndex != -1)
        m_pDescriptionSource->GetDescription(m_selectedDescriptionIndex, description);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 7: UID0001U3 `by-type/by-struct/DescPaneLayout.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// DescPane field declarations are emitted by [UID:00003Q]; do not duplicate a separate layout struct.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 8: UID0001XC `by-type/by-vtable/DescPaneVtables.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// DescPane virtual-table emission is covered by [UID:00003Q]; do not hand-author table data.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 9: UID0002NA target

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-generated DescPane RTTI and vtable bytes for this range are covered by [UID:00003Q].
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 10: UID0000QR `by-global/g_pDescPane.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
DescPane *g_pDescPane = NULL;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 11: UID0001PB singleton storage page

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Storage for this range is emitted by the g_pDescPane definition in [UID:0000QR].
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Behavior-preservation rationale:

- The class declaration provides the exact single direct base and virtual
  override set needed to emit the observed three-view vtables.
- Existing method bodies remain unchanged.
- The global definition preserves loader-zero null initialization.
- No compiler ABI body or literal table is hand-authored.
- The source uses C++03-era `NULL`, no `override`, and ordinary
  header/source organization.

## Final Recommendation

- The accepted recommendation below is implemented and validated in the
  current ordinary-doc union.
- Keep UID0002NA at its current exact path/range and `Nested:4`.
- Apply the complete 33-dword inventory and correct internal COL wording.
- Apply target `92/94`, owner UID00003Q, emitter UID0001XC, position 10,
  reconstructable true, and Destination 9.
- Apply the complete DescPane declaration/source/global route and positions.
- Reclass UID00012K as a false/no-emitter split/index.
- Raise exact compiler support UID00012P/UID00012Q without emitting them.
- Synchronize only the bounded Pane slot facts required by this target.
- Preserve UID000254, EventHandler, TimerHandler, and unrelated current
  content.
- No new UID, page, source file, split, range extension, ignored row, or IDA
  mutation is recommended.
- There is no remaining in-scope source-quality blocker. Original stripped
  lexical spellings remain a confidence cap, not a deferred task.

## Recommended Target Doc Changes

Target:
`by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md`

Applied current state:

- Metadata:
  - `COMPLETION:92`;
  - `CONFIDENCE:94`;
  - `CANONICAL_OWNER:00003Q`;
  - `RECONSTRUCTABLE:TRUE`;
  - `EMITTER_UIDS:0001XC`;
  - `EMITTER_POSITION_OPTIONAL:10`;
  - Destination 9 formal marker;
  - `Nested:4`.
- Replace the stale "internal COLs are not part" statement with exact physical
  inclusion.
- Add target bytes/hash, `.rdata`/no-relocation facts, COL/CHD/base hierarchy,
  full primary/secondary/tertiary slot tables, all base-store/COL xrefs,
  wrapper/thunk/default evidence, owner/emitter rationale, no-split proof,
  source/compiler boundary, negative evidence, and generated expectations.
- Historicalize old generic inherited slot names and specifically reject
  `Repaint` at `+0x1c`.
- Preserve the current path, parent UID000254, `Nested:4`, all valid
  constructor/destructor store evidence, and `DialogPane` boundary.

## Recommended Support Doc Changes

The accepted support recommendations below are applied or verified at
same-or-greater detail.

| Destination | Exact recommendation |
| --- | --- |
| UID00003Q `by-class/DescPane.md` | `92/94`, file position 10, Destination 1 complete declaration; retain all method behavior/history; replace blank-header rationale and stale custom-provider blockers. |
| UID0000IS `by-file/DescPane.md` | `92/94`; record header/source split, exact positions/order, complete generated expectations, no duplicate arrays/wrappers, and current source union. |
| UID0001XC `by-type/by-vtable/DescPaneVtables.md` | `92/94`, class position 70, Destination 8; full 18/11/2 table plus internal COLs and corrected inherited slot names. |
| UID0001U3 `by-type/by-struct/DescPaneLayout.md` | `92/94`, class position 60, Destination 7; retain `0x100`, exact tail/lifetime, and explain declaration coverage. |
| UID00012K aggregate | `92/93`, owner UID00003Q retained, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal; replace source-bearing aggregate wording with split/index and historicalize no-children marker. |
| UID00012J constructor | `91/93`, position 10; retain Destination 2 and exact evidence; historicalize all remaining current-facing custom-provider/`char *` claims. |
| UID00012L destructor | `92/94`, position 20; retain Destination 3 and source/compiler split. |
| UID00012M getter | `91/93`, position 30; retain Destination 4 and exact no-caller/name cap. |
| UID00012N setter | `92/93`, position 40; retain Destination 5 and raw/no-route evidence. |
| UID00012O OnPaint | `92/94`, position 50; retain Destination 6 and exact negatives. |
| UID00012P adjustors | `92/94`; retain none/false/blank route and exact compiler proof. |
| UID00012Q scalar wrapper | `92/94`; retain none/false/blank route and exact 29-instruction/delete-flag proof. |
| UID0000QR global | `92/94`, file position 20, Destination 10; complete declaration/definition/lifecycle evidence. |
| UID0001PB storage | `92/94`, position 10 under UID0000QR, Destination 11; retain loader-zero and four-ref evidence. |
| UID0000A2 `by-class/Pane.md` | Preserve `90/91`, blank broad formal, and concurrent `GetParentPane`/facet union; add only bounded `DrawOnTarget` source-contract evidence. |
| UID0000MC `by-file/Pane.md` | Preserve `90/91` and concurrent `GetParentPane`/facet union; add only bounded `DrawOnTarget` source-contract evidence. |
| UID0001EA PaneCore | Preserve `89/92`, false/no-emitter; replace `Pane::Repaint` row and name target-draw default. |
| UID0003JA PaneVtables | Preserve `90/94` and concurrent `GetParentPane`/facet union; add only the primary `+0x10` `DrawOnTarget` direction. |
| UID0003CA PaneVtableData | Raise `85/91 -> 90/93`; complete primary/secondary/tertiary table identity and exact slot map; retain class owner, emitter, `Nested:8`, and blank no-handwritten-table formal. |
| UID000254 DialogCoreReadOnlyData | Verify-only; preserve `87/91`, false/no-emitter, range, target link, and mixed index role. |
| UID00004N EventHandler | Verify-only; preserve current interface/formal and exact secondary order. |
| UID0000F0 TimerHandler | Verify-only; preserve current callback contract/formal and source-placement caveat. |

## Score And Metadata Recommendation

| UID | Pre-callback | Applied | Reason |
| --- | --- | --- | --- |
| 0002NA | `86/90` | `92/94` | Complete bytes/hash/section/RTTI/slots/xrefs/source declaration/no-code proof. |
| 00003Q | `88/91` | `92/94` | Complete class declaration, inheritance, layout, methods, global, vtable cause, generated route. |
| 0000IS | `88/90` | `92/94` | Complete bounded file contents and order; remaining only stripped include spelling. |
| 0001XC | `88/93` | `92/94` | Full table and routing closure; original two inferred base spellings cap 95. |
| 0001U3 | `89/92` | `92/94` | Complete layout and declaration coverage. |
| 00012K | `89/91` | `92/93` | Complete index/split/child/padding disposition; physical aggregate is not source. |
| 00012J | `88/90` | `91/93` | Body exact; no direct caller and `Pane(1)` symbolic name cap final audit. |
| 00012L | `88/91` | `92/94` | Exact source body and compiler boundary. |
| 00012M | `88/90` | `91/93` | Exact body/owner; no direct caller/original spelling cap. |
| 00012N | `90/91` | `92/93` | Exact raw body/type/range/source; no direct caller/name cap. |
| 00012O | `90/92` | `92/94` | Exact body/slot/dependencies/negatives. |
| 00012P | `88/92` | `92/94` | Exact two thunks and no-code proof. |
| 00012Q | `86/92` | `92/94` | Exact complete wrapper and no-code proof. |
| 0000QR | `88/86` | `92/94` | Exact type/name/storage/lifecycle and definition. |
| 0001PB | `86/90` | `92/94` | Exact loader-zero storage and complete four-ref route. |
| 0003CA | `85/91` | `90/93` | Complete Pane three-view slot map supplied by direct target research. |

Score-blocker audit:

- Unnamed target slots: resolved.
- Generic Pane slot identities: resolved or ranked with exact inference.
- Source class declaration: resolved.
- Direct inheritance: resolved by RTTI.
- EventHandler/TimerHandler view legality: resolved.
- Range/internal COL contradiction: resolved.
- Owner/emitter distinction: resolved.
- Global declaration/definition: resolved.
- Empty generated markers/no-children artifact: repaired and structurally
  verified.
- Method ordering: applied and structurally verified.
- Compiler/source split: resolved.
- No direct raw caller for constructor/setter/getter: exhaustive historical
  negative evidence retained; does not block behavior/source.
- Original PDB spellings: unavailable after exact source/RTTI/string/report
  checks; best human names selected. This caps scores below 95 but leaves no
  implementation blocker.

## Open Questions With Attempted Resolution

| Question | Checks | Resolution |
| --- | --- | --- |
| Are internal COL dwords in the page? | Arithmetic, bytes, hash, dword map | Yes. They are physically included and must be documented. |
| Should the page widen left? | Predecessor bytes/string/COL convention | No. Keep primary-base start. |
| Should the page split by views? | Adjacent vtable conventions, common class owner, constructor stores | No. One coherent three-view class data page is stronger. |
| Is UID0001XC the semantic owner? | by-structure narrow-owner rule, RTTI class | No; UID00003Q is owner. UID0001XC remains emitter/evidence parent. |
| Is `Nested:4` wrong? | current parent-first address order and generated indentation | No; it is the correct one-level child delta. |
| Does DescPane directly inherit EventHandler/TimerHandler? | CHD/base descriptors/PMDs | No; only Pane is direct. |
| What is primary `+0x10`? | no-op target, Layer caller arguments, weather overrides, 381 refs | `DrawOnTarget` direction with GrafPort and two RectBounds pointers. |
| What is primary `+0x1c`? | target decompile and exact Layer UID0004O9 | `GetParentPane`, not Repaint. |
| Does DescPane override timer/event slots? | table targets and current base declarations | No; all are inherited defaults/bridges. |
| Where does class C++ belong? | source ownership and generated route | UID00003Q complete declaration. |
| Should target/type/layout/storage emit raw source? | compiler/source classification | Only managed coverage comments; actual declaration/definition emit elsewhere. |
| Is a new UID/page needed? | full current inventory | No. |
| What remains unresolved? | all current reasonable evidence routes | Only exact stripped lexical/include spellings; no behavior, type, ownership, range, or C++ blocker. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Read-only coverage checkpoint hashes:

- `by-memory/-coverage-report.md`:
  `6A92D517173EFF0C118A359E3A31293A2280D2F576E550AB7AF806D2DF754D22`,
  1,778,800 bytes / 4,258 lines.
- `by-class/-coverage-report.md`:
  `9FFBA580555349BD5B772434F089DE9F374A83D416FE8BC60D871653A91F077B`,
  230,374 / 622.
- `by-file/-coverage-report.md`:
  `A6C7BC6A44CE868D990A764AB011377BEA2CBA83DB9C0C841DA28153FAF20CE1`,
  132,211 / 316.
- `by-type/by-vtable/-coverage-report.md`:
  `DC5527D90E14571DDBBC02FCF00C932869B3E0A4DD44F9ABA2ABE5E880028017`,
  65,401 / 142.
- `by-type/by-struct/-coverage-report.md`:
  `597DB016B3F1F8DAF76F469B2AA8DA1E58AE58DF4DE38B0B8620708B2ADED1AA`,
  57,352 / 137.
- `by-global/-coverage-report.md`:
  `A450395CD7C0F15D0F0BA6D681B13D2EF92EC30634B8806E638B0FD5C9C42B67`,
  90,088 / 212.

Exact supervisor-owned replacement/addition text after accepted implementation:

The current manual hashes were produced by concurrent
supervisor/validator-owned work. Readback confirmed that the UID0002NA,
DescPane-family, Pane, PaneCore, and PaneVtables rows relevant to this handoff
remain stale in the exact ways described below; concurrent additions are
preserved and unrelated to this target's replacement text.

`by-memory/-coverage-report.md` replacements:

```text
    - [UID:00012K][0x0049d6f0-0x0049d89f.DescPane](by-memory/0x0049d6f0-0x0049d89f.DescPane.md) : ignored : 92% : very-strong : Non-emitting exact DescPane class-island split/index; constructor, destructor, singleton getter, Pane-typed setter, OnPaint, compiler adjustors/wrapper, padding, class declaration route, global, vtables, history, and generated no-duplicate policy are complete on exact children/support pages.
    - [UID:00012J][0x0049d6f0-0x0049d73c.DescPaneConstructorRaw](by-memory/0x0049d6f0-0x0049d73c.DescPaneConstructorRaw.md) : reconstructable : 91% : very-strong : Exact source constructor with Pane(1), class fields, singleton publish, compiler vptr-store exclusion, raw-start/no-caller history, position 10, and complete managed body.
    - [UID:00012L][0x0049d740-0x0049d769.DescPaneDestructor](by-memory/0x0049d740-0x0049d769.DescPaneDestructor.md) : reconstructable : 92% : very-strong : Exact ordinary DescPane destructor source body with unconditional singleton clear, compiler vptr/base-teardown exclusion, position 20, and scalar-wrapper contrast.
    - [UID:00012M][0x0049d770-0x0049d776.DescPaneGetSingleton](by-memory/0x0049d770-0x0049d776.DescPaneGetSingleton.md) : reconstructable : 91% : very-strong : Exact static DescPane singleton accessor returning g_pDescPane, with six-byte body, no-caller/name cap, position 30, and complete managed source.
    - [UID:00012N][0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw](by-memory/0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw.md) : reconstructable : 92% : very-strong : Exact Pane-typed source/index setter, paired update, changed-only InvalidateRect, raw-range/no-route history, position 40, and complete managed source.
    - [UID:00012O][0x0049d7c0-0x0049d81e.DescPaneOnPaint](by-memory/0x0049d7c0-0x0049d81e.DescPaneOnPaint.md) : reconstructable : 92% : very-strong : Exact DescPane OnPaint override, clear/fill order, borrowed Pane GetDescription call, wchar_t[1024] scratch, guards, negatives, position 50, and complete managed source.
    - [UID:00012P][0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks](by-memory/0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks.md) : ignored : 92% : very-strong : Exact this-0xa0/this-0xa4 compiler deleting-destructor adjustor thunks; no handwritten source or emitter.
    - [UID:00012Q][0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor](by-memory/0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor.md) : ignored : 92% : very-strong : Exact compiler scalar deleting destructor with vptr restoration, singleton clear, Pane teardown, delete flags, optional free, adjusted-view routes, and blank no-code disposition.
        - [UID:0002NA][0x006189dc-0x00618a60.DescPaneVtableData](by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md) 0x006189dc-0x00618a60 | source-declared/generated vtable and RTTI data | DescPaneVtableData : reconstructable : 92% : very-strong : Exact 132-byte DescPane three-view range with 18/11/2 callable slots, two in-range internal COL cells, RTTI direct Pane inheritance, all lifecycle stores/xrefs, complete inherited contracts, compiler-only tables/thunks/wrapper, class owner UID00003Q, vtable emitter UID0001XC, and no-handwritten-table marker.
    - [UID:0001PB][0x0069adf8-0x0069adfc.g_pDescPane](by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md) 0x0069adf8-0x0069adfc | global pointer storage | g_pDescPane : reconstructable : 92% : very-strong : Exact loader-zero-filled DescPane singleton storage with four class-island refs, global definition coverage, position 10 under UID0000QR, and no duplicate storage source.
    - [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md) 0x00544460-0x00545086 | class-method split/index | PaneCore : ignored : 89% : very-strong : Non-emitting Pane core index with exact source children, complete primary contracts including DrawOnTarget and GetParentPane, EventHandler/TimerHandler bridges, Layer/deletion/motion evidence, and compiler-wrapper exclusions.
        - [UID:0003CA][0x006219e8-0x00621a6c.PaneVtableData](by-memory/0x006219e8-0x00621a6c.PaneVtableData.md) 0x006219e8-0x00621a6c | source-declared/generated vtable and RTTI data | PaneVtableData : reconstructable : 90% : very-strong : Exact Pane primary/EventHandler/TimerHandler vtable data with complete slot identities, DrawOnTarget at +0x10, GetParentPane at +0x1c, lifecycle stores, RTTI boundaries, and compiler-generated no-array disposition.
```

`by-class/-coverage-report.md` replacements:

```text
- [UID:00003Q][DescPane](by-class/DescPane.md) : reconstructable : 92% : very-strong : Complete Pane-derived DescPane declaration with virtual destructor, singleton API, Pane-typed source/index setter, OnPaint override, exact +0xf8/+0xfc tail, five source method children, global route, RTTI/vtables/layout coverage, compiler exclusions, and generated source closure.
- [UID:0000A2][Pane](by-class/Pane.md) : reconstructable : 90% : very-strong : Base UI Pane with exact constructor/destructor/core child inventory, primary/secondary/tertiary contracts including DrawOnTarget and GetParentPane, Layer/EventHandler/TimerHandler/deferred-deletion relationships, bounds/origin state, source-ready children, and compiler exclusions; broad class formal remains intentionally blank.
```

`by-file/-coverage-report.md` replacements:

```text
- [UID:0000IS][DescPane](by-file/DescPane.md) : reconstructable : 92% : very-strong : Complete NexusTK/ui/controls DescPane source route with one class declaration, constructor/destructor/getter/setter/OnPaint bodies, one g_pDescPane definition, exact positions, layout/vtable/storage coverage markers, compiler-only RTTI/vptr/adjustor/wrapper handling, and no duplicate or empty generated artifacts.
- [UID:0000MC][Pane](by-file/Pane.md) : reconstructable : 90% : very-strong : NexusTK/ui/core Pane source route with exact core split, full primary contracts including DrawOnTarget and GetParentPane, EventHandler/TimerHandler/Layer/deferred-deletion relationships, source-ready children, and compiler-only wrappers/thunks.
```

`by-type/by-vtable/-coverage-report.md` replacements:

```text
- [UID:0001XC][DescPaneVtables](by-type/by-vtable/DescPaneVtables.md) : reconstructable : 92% : very-strong : Complete DescPane 18/11/2 primary/EventHandler/TimerHandler views with two internal COL cells, direct Pane inheritance RTTI, every slot identity, lifecycle stores, adjusted deleting-destructor routes, DialogPane boundary, class coverage marker, and no handwritten table data.
- [UID:0003JA][PaneVtables](by-type/by-vtable/PaneVtables.md) : reconstructable : 90% : very-strong : Source-local Pane primary/EventHandler/TimerHandler vtable page with complete contracts including DrawOnTarget at +0x10 and GetParentPane at +0x1c, exact lifecycle stores, adjusted destructor routes, and compiler-generated table disposition.
```

`by-type/by-struct/-coverage-report.md` replacement:

```text
- [UID:0001U3][DescPaneLayout](by-type/by-struct/DescPaneLayout.md) : reconstructable : 92% : very-strong : Exact 0x100 Pane-derived DescPane layout with EventHandler/TimerHandler facets, borrowed Pane source at +0xf8, selected index at +0xfc, constructor/setter/OnPaint/destructor lifetime evidence, complete class-declaration coverage, and no duplicate layout struct.
```

`by-global/-coverage-report.md` replacement:

```text
- [UID:0000QR][g_pDescPane](by-global/g_pDescPane.md) : reconstructable : 92% : very-strong : Exact DescPane singleton declaration/definition with loader-zero storage UID0001PB, constructor publish, destructor/wrapper clear, getter read, file position 20, complete managed definition, and no external fanout or duplicate storage.
```

Reason B001 must not apply these rows directly:

- Manual `-coverage-report.md` files are supervisor-owned.
- This report records exact replacement text after a read-only comparison.
- Their later application/validation/current hash is external state and is not
  asserted here.

## Follow-Up Actions

- B001 callback work is complete. Independent report validation, callback
  verification, manual coverage application, and all report lifecycle state
  remain external supervisor/validator-owned state and are neither asserted
  nor directed by this artifact.
- A-agent actions: none.
- B001 remaining actions: none.
- This artifact neither directs nor asserts report execution, movement,
  archival, report count, or later MCP/session availability.

## Confidence

- Recommendation confidence: `94`.
- Target score confidence: `94`.
- Range/bytes/RTTI/slot confidence: very strong.
- Source-owner/emitter confidence: very strong.
- Source declaration confidence: very strong.
- Human lexical confidence:
  - `DescPane`, `Pane`, RTTI classes, `OnPaint`: exact or independently fixed.
  - `GetParentPane`: very strong behavioral/project-name inference.
  - `DrawOnTarget`: strong behavioral/project-era inference; `RenderToTarget`
    is the only credible runner-up.
- Remaining uncertainty has no implementation impact and justifies stopping
  below the 95+ final-audit gate.

## Validator Results

All commands were run from
`E:\NTK\GhidraBridge\source-3\project-documentation`. Every ordinary page was
leased only for its immediate edit/validation batch and released immediately
after the validator returned.

| Command ID | Timestamp | Scoped path / purpose | Exit / ok | Result and side effects |
| --- | --- | --- | --- | --- |
| `000000014174` | `2026-07-16T14:35:29-04:00` | `by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md` | `0 / 1` | Target metadata, evidence, and formal validated. |
| `000000014175` | `2026-07-16T14:36:22-04:00` | `by-class/DescPane.md` | `0 / 1` | Complete declaration validated. |
| `000000014176` | `2026-07-16T14:37:09-04:00` | `by-memory/0x0049d6f0-0x0049d89f.DescPane.md` | `0 / 1` | Non-emitting split/index validated. |
| `000000014178` | `2026-07-16T14:38:09-04:00` | `by-memory/0x0049d6f0-0x0049d73c.DescPaneConstructorRaw.md` | `0 / 1` | Constructor body/position/history validated. |
| `000000014179` | `2026-07-16T14:38:40-04:00` | `by-memory/0x0049d740-0x0049d769.DescPaneDestructor.md` | `0 / 1` | Destructor body/position/compiler boundary validated. |
| `000000014181` | `2026-07-16T14:39:10-04:00` | `by-memory/0x0049d770-0x0049d776.DescPaneGetSingleton.md` | `0 / 1` | Getter body/position validated. |
| `000000014183` | `2026-07-16T14:39:46-04:00` | `by-memory/0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw.md` | `0 / 1` | Pane-typed setter body/position validated. |
| `000000014185` | `2026-07-16T14:40:20-04:00` | `by-memory/0x0049d7c0-0x0049d81e.DescPaneOnPaint.md` | `0 / 1` | OnPaint body/position validated. |
| `000000014186` | `2026-07-16T14:40:54-04:00` | `by-memory/0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks.md` | `0 / 1` | Compiler-adjustor no-code state validated. |
| `000000014187` | `2026-07-16T14:41:19-04:00` | `by-memory/0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor.md` | `0 / 1` | Compiler scalar-wrapper no-code state validated. |
| `000000014194` | `2026-07-16T14:41:51-04:00` | `by-type/by-struct/DescPaneLayout.md` | `0 / 1` | Layout score/position/coverage marker validated. |
| `000000014199` | `2026-07-16T14:43:07-04:00` | `by-type/by-vtable/DescPaneVtables.md` | `0 / 1` | Complete 18/11/2 vtable map and marker validated. |
| `000000014202` | `2026-07-16T14:43:41-04:00` | `by-global/g_pDescPane.md` | `0 / 1` | Global definition/position/children validated. |
| `000000014204` | `2026-07-16T14:44:14-04:00` | `by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md` | `0 / 1` | Storage score/position/coverage marker validated. |
| `000000014206` | `2026-07-16T14:45:15-04:00` | `by-file/DescPane.md` | `0 / 1` | Source route/order/output/compiler exclusions validated. |
| `000000014207` | `2026-07-16T14:45:59-04:00` | `by-class/Pane.md` | `0 / 1` | Concurrent union preserved; bounded DrawOnTarget fact validated. |
| `000000014209` | `2026-07-16T14:46:27-04:00` | `by-file/Pane.md` | `0 / 1` | Concurrent union preserved; bounded DrawOnTarget fact validated. A then-current missing-ref warning for UID0003CA was resolved by command `000000014215`. |
| `000000014211` | `2026-07-16T14:47:01-04:00` | `by-memory/0x00544460-0x00545086.PaneCore.md` | `0 / 1` | Stale Repaint row corrected; DrawOnTarget direction validated. |
| `000000014213` | `2026-07-16T14:47:49-04:00` | `by-type/by-vtable/PaneVtables.md` | `0 / 1` | Concurrent union preserved; DrawOnTarget direction validated. A then-current missing-ref warning for UID0003CA was resolved by command `000000014215`. |
| `000000014215` | `2026-07-16T14:49:19-04:00` | `by-memory/0x006219e8-0x00621a6c.PaneVtableData.md` | `0 / 1` | Existing UID0003CA page registered/validated at `90/93`; prior missing-ref warnings resolved. |
| `000000014216` | `2026-07-16T14:49:42-04:00` | final UID0002NA `--wait-generated` | `0 / 1` | Accepted final generated refresh completed. |

Validator side effects were validator-owned generated/projected-stat/registry
updates. B001 did not manually edit those files.

Generated verification:

- B001 final waited command: `000000014216`; generated SHA256 at that
  checkpoint:
  `77583FAD5D8E74977254414D24D1CF0706CB93D29A666C18958CB374876270A0`.
- Evidence-time validator-owned checkpoint observed during terminal reconciliation:
  command `000000014231`, refreshed `2026-07-16T14:55:39-04:00`, SHA256
  `1B7809B21016EA404BABE7C6217F26F709341E0BCD267E814408EE089DC968B7`,
  3,062 bytes / 85 lines. This records an evidence-time checkpoint; later
  validator-owned header refreshes do not change the structural assertions.
- `class DescPane : public Pane` occurs once at line 11; the class closes at
  line 26; the first qualified definition begins at line 29. The class closing
  brace therefore precedes `[[CHILDREN]]` output and every qualified method
  definition.
- Constructor, destructor, getter, setter, and OnPaint each occur once, in
  source positions 10/20/30/40/50.
- One `DescPane *g_pDescPane = NULL;` definition is present.
- UID0001U3 layout, UID0001XC vtable, UID0002NA target, and UID0001PB storage
  markers each occur once.
- `Empty Emitter Marker`, `[[No Children Attached]]`, `sub_49D81E`,
  `sub_49D829`, `sub_49D840`, `vptr`, and `__thiscall` each occur zero times.
- No handwritten table/layout data, explicit vptr assignment, adjustor body,
  scalar-wrapper body, explicit base teardown, duplicate class, or duplicate
  method is emitted.

No report lifecycle/probe/count/execute/move/archive command was run by B001.
The earlier malformed reserved-`$args` MCP request remains honestly recorded
as a corrected client request-shape limitation, not an unresolved tool error.

## Changed Files

- Report modified:
  `tools/leaser/Agents/Agent-B001/research/0002NA-DescPaneVtableData-source-quality.md`.
- Ordinary pages modified and final SHA256:

| Path | Final SHA256 |
| --- | --- |
| `by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md` | `2569221690FDCDAFA5A4ED0517511BC44A6C64A040D9BB08F6528CCF03E29455` |
| `by-class/DescPane.md` | `CE053F4533DB5532D08F7B119BBCBDE7F93DFCD013C9C7363F6549131C2F1EB5` |
| `by-file/DescPane.md` | `68DFA88ECAE68D57F96ACD1B86031D04FCDAE2A3AAA12B49D3D30F7AA7F59FCE` |
| `by-type/by-vtable/DescPaneVtables.md` | `CF379545963D60963A94D1F08DBF81561281835387701F401D2820C30F7EA659` |
| `by-type/by-struct/DescPaneLayout.md` | `E57B4AA1304C5F547827265F353DBF099AD7C71D28F3913B625F1ACAC379979B` |
| `by-memory/0x0049d6f0-0x0049d89f.DescPane.md` | `73AC04EE00EB76FF9AEF71C0CBC8D9D7B6AC83B9E13FD21561848594AD8A5FE6` |
| `by-memory/0x0049d6f0-0x0049d73c.DescPaneConstructorRaw.md` | `027423BAC9657FDA785F81716215C7A8C5D97C2D38A64B621AA07230219F4604` |
| `by-memory/0x0049d740-0x0049d769.DescPaneDestructor.md` | `CCC74457A4616A42E62686E0EEC97065C85B60FA3A35B1CBF9CAE5F7042CE0AC` |
| `by-memory/0x0049d770-0x0049d776.DescPaneGetSingleton.md` | `E5B1A4E6A2262C585702DF8920F06ADE340E01ED73947AD3B4B45514CFAF6B32` |
| `by-memory/0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw.md` | `AD055C66B83D02A62B26EDBDC36EC6B8B4395032D796F630EE8C666FBFB5D59F` |
| `by-memory/0x0049d7c0-0x0049d81e.DescPaneOnPaint.md` | `D62E36AC986F5F93DFE1B12B8F4335A91348B1979BCFEDAABB4ABF102DB6A025` |
| `by-memory/0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks.md` | `169992A75B94D24A037C8C0A0153DD51D152266E739D7A585171B4AC89DEC123` |
| `by-memory/0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor.md` | `16FEAF767C362755547DCFC5D451E065A04C9754716DB3B533132B508FBBB8E9` |
| `by-global/g_pDescPane.md` | `9CDEDBC3AD3A86A85A4E7E43ADAEE205FCA2FAC2A66A1FEA485B0E090EB50BB5` |
| `by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md` | `B191A127CD26D98155560179BCC761CB87CC1F3097BD2A5888D20DE7A1D04FEB` |
| `by-class/Pane.md` | `C0A7AFC85C571E1695E93DE021FB183AE65E70E7E931FED605826945981C52EA` |
| `by-file/Pane.md` | `71F3041CF5DE8FDF2F61F4F902510A1FE46108CE78450955BCD0EDD1BE7C68DB` |
| `by-memory/0x00544460-0x00545086.PaneCore.md` | `C0DDCBAAA664E4C82D895733E6F9F3798EF99DB3527A3F30486F1F1E6BB4FF36` |
| `by-type/by-vtable/PaneVtables.md` | `B8381FCA8BC9F44C3D19CA1112CF54A5BA8D3C2BD465A071D3303D31DB763B82` |
| `by-memory/0x006219e8-0x00621a6c.PaneVtableData.md` | `C5E8F33B43F9D13661C95BD7571AAF0C4B851E4397E03834FDC0887543635467` |

- Verify-only pages remained unchanged:
  UID000254 `DE4B279DB59A94078594DEFC4A5AFFA2309716F1C09893EF0FAD2811D3E3FEBA`,
  EventHandler `38033240D695B08EB3404F722953F1243DD2DE6B2C2724FB7B59995873AD9EB1`,
  and TimerHandler
  `FBE38D7BEB2CCA34E3CF58C4891B526F170CF911CC39F4C065597EB3D729D017`.
- No file was renamed, created, split, or added to `by-memory/-ignored.md`.
- B001 manually modified no manual coverage, generated, tracker, audit,
  supervisor, validator-state, lifecycle, archive, or IDA file.
- Every ordinary lease was released immediately after scoped validation.
  `tools/leaser/Agents/Agent-B001/current_leases.md` reports no active leases.
- Remaining blocked or unapplied claims: none.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validated the exact accepted artifact before implementation.
- [x] Re-read every listed destination immediately before its accepted callback edit.
- [x] Confirmed UID0002NA exact range/path and retained `Nested:4`.
- [x] Applied UID0002NA `92/94`, owner UID00003Q, emitter UID0001XC, position 10.
- [x] Replaced UID0002NA stale internal-COL exclusion with exact physical inclusion.
- [x] Added complete target bytes/hash/section/no-relocation evidence.
- [x] Added complete primary 18-slot inventory.
- [x] Added complete secondary 11-slot inventory.
- [x] Added complete tertiary 2-slot inventory.
- [x] Added exact RTTI/COL/CHD/base-descriptor evidence and direct Pane inheritance.
- [x] Applied Destination 9 target no-handwritten-table managed marker.
- [x] Applied UID00003Q `92/94`, file position 10, and Destination 1 complete class block.
- [x] Preserved and positioned UID00012J constructor at 10 with Destination 2.
- [x] Preserved and positioned UID00012L destructor at 20 with Destination 3.
- [x] Preserved and positioned UID00012M getter at 30 with Destination 4.
- [x] Preserved and positioned UID00012N setter at 40 with Destination 5.
- [x] Preserved and positioned UID00012O OnPaint at 50 with Destination 6.
- [x] Historicalized all remaining current-facing custom-provider/RefreshDescription/Repaint claims.
- [x] Applied UID0001U3 `92/94`, position 60, and Destination 7.
- [x] Applied UID0001XC `92/94`, position 70, and Destination 8 with `[[CHILDREN]]`.
- [x] Reclassified UID00012K to `92/93`, reconstructable false, blank emitter/position/formal.
- [x] Applied UID00012P `92/94` while retaining none/false/blank no-code state.
- [x] Applied UID00012Q `92/94` while retaining none/false/blank no-code state.
- [x] Applied UID0000QR `92/94`, file position 20, and Destination 10.
- [x] Applied UID0001PB `92/94`, position 10 under UID0000QR, and Destination 11.
- [x] Applied UID0000IS `92/94` and complete source-order/generated-output prose.
- [x] Preserved current `GetParentPane`/facet support, added `DrawOnTarget`, and corrected the stale PaneCore `Repaint` row.
- [x] Applied UID0003CA `90/93` with complete three-view slot inventory.
- [x] Preserved UID000254, EventHandler, TimerHandler, and unrelated content at same-or-greater detail.
- [x] Preserved all positive, negative, historical, rejected-alternative, source-placement, and compiler-boundary evidence.
- [x] Confirmed no new UID/page/split/range/ignored row/IDA mutation was required.
- [x] Leased only one ordinary destination immediately before each callback edit.
- [x] Ran one scoped validator per changed ordinary page and released each lease immediately.
- [x] Ran final accepted UID0002NA validation `000000014216` with `--wait-generated`.
- [x] Verified generated DescPane.cpp has one complete class declaration.
- [x] Verified constructor/destructor/getter/setter/OnPaint each occur exactly once in positions 10/20/30/40/50.
- [x] Verified one `g_pDescPane` definition and one storage coverage marker.
- [x] Verified one layout marker, one vtable marker, and one target marker.
- [x] Verified zero `Empty Emitter Marker` and zero `[[No Children Attached]]`.
- [x] Verified zero handwritten vtable arrays, vptr assignments, adjustor bodies, scalar-wrapper body, explicit base teardown, or duplicate methods.
- [x] Recorded exact validator command IDs/timestamps/exits/ok/side effects and generated header/hash/assertions.
- [x] Supplied the exact manual supervisor-owned coverage rows above without editing them.
- [x] Updated all C2NA-001 through C2NA-072 rows to legal callback states with claim-specific proof.
- [x] Updated Changed Files, Validator Results, current-state wording, destination hashes, and lease closure.
- [x] Confirmed all placeholders are absent, all managed blocks are destination-specific, and no body-only C++ exists.
- [x] Confirmed no B001 execute_report/probe/count/lifecycle/move/archive command occurred.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted ordinary destinations updated at report-level detail.
- [x] All 11 accepted managed blocks applied or confirmed exact.
- [x] All 72 ledger claims terminalized with proof.
- [x] Every changed ordinary page scoped-validated under a short lease.
- [x] Final waited generated verification passed.
- [x] Exact supervisor-owned coverage handoff preserved.
- [x] Remaining unapplied claims listed with exact blocker: none.
- [x] All B001 leases released.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000014239","destination_path":"executed-b-agent-research/B001/0002NA-DescPaneVtableData-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0002NA-DescPaneVtableData-source-quality.md","timestamp":"2026-07-16T15:10:08-04:00","uid":"0002NA"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
