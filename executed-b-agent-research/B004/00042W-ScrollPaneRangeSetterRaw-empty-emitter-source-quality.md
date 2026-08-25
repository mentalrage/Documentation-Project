** TARGET-REPORT-UID:00042W **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00042W ScrollPane Range Setter Raw Empty-Emitter Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: replace the stale blank-C++ no-code disposition on [UID:00042W] with first-draft formal C++ for an inferred private `ScrollPane::SetSkinIndex(unsigned short skinIndex)` helper.
- Final disposition: `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000CM`, `EMITTER_UIDS:0000CM`, formal `RECONSTRUCTION_CPP CODE` populated. The no-function/no-xref facts stay documented as route/confidence caps, not as a C++ blocker.
- Implementation callback result: supervisor accepted this report, and B004 applied the target/support updates at report-level detail. The `+0xf8` source-facing field name is now `m_scrollSkinIndex`, historical `m_trackStateWord`/`NC-02` wording is preserved as superseded caution, and `auto-generated/NexusTK/ui/core/ScrollBar.cpp` no longer lists UID00042W as an `Empty Emitter Marker`.
- Confidence: high for range/body/owner/source-file route and `+0xf8` as the scroll skin/style index; medium-high for the inferred exact method name because no original symbol, caller, function object, or pointer route was recovered.

## Supporting Research

## Target

- Target UID: `00042W`.
- Target path: `by-memory/0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## Files With Empty Emitters`; generated file family `auto-generated/NexusTK/ui/core/ScrollBar.cpp`.
- Current supervisor classification: report-only empty-emitter source-quality research.
- Current scores and parent state: target `85/87`, owner/emitter [UID:0000CM] `ScrollPane`; direct class [UID:0000CM] is `86/87`; source-file root [UID:0000NF] `ScrollBar` is `89/85`; split parent [UID:0001GH] `ScrollPaneInputCore` is non-emitting `88/90`.

## Current Target State

- Existing metadata: `COMPLETION:85`, `CONFIDENCE:87`, `CANONICAL_OWNER:0000CM`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CM`, blank emitter position, `Nested:0`.
- Existing C++/emitter state: formal block is blank under old `NC-02`; generated `ScrollBar.cpp` line for UID00042W is an `Empty Emitter Marker`.
- Existing stale blocker: the page says formal C++ would require inventing an original out-of-line method name and route. Current project practice no longer treats raw no-function/no-xref status as a sufficient blank-C++ blocker when the exact body, owner, field role, and source shape are strong enough.
- Related target/support docs checked: target, [UID:0001GH] `ScrollPaneInputCore`, [UID:00042V] constructor, [UID:00042X] byte setter, [UID:00042Z] comparable raw current setter, [UID:0000CM] `ScrollPane`, [UID:0000CP] `ScrollWidget`, [UID:0000CF] `ScrollablePane`, [UID:0000NF] `ScrollBar`, [UID:0003CK] `ScrollPaneVtableData`, [UID:0001GK] `ScrollPaneGetScrollPartRect`, [UID:0003CQ] `ScrollPaneScrollbarConstantData`, [UID:0000VN] ignored padding, and generated `ScrollBar.cpp`.

## Executive Recommendation

The target is not a range setter. It is the raw `ScrollPane` setter for the signed word at `+0xf8`, now best named `m_scrollSkinIndex`: current MCP confirms the setter body, while current ScrollPane draw/geometry code reads the same word as an index into the shared scrollbar size/style tables at `0x00624144` and `0x0062415c`. The target should be renamed/described as `ScrollPaneSetSkinIndexRaw` or `ScrollPaneSkinIndexSetterRaw`, raised to `88/90`, and populated with exact formal C++:

```cpp
void ScrollPane::SetSkinIndex(unsigned short skinIndex)
{
    if (m_scrollSkinIndex == skinIndex) {
        return;
    }

    m_scrollSkinIndex = skinIndex;
    InvalidateRect(&m_bounds);
}
```

Keep the negative route proof: no IDA function object, zero direct xrefs, and zero VA/RVA pointer-byte hits. That evidence caps confidence and proves the method name is inferred, but it should not keep the emitter blank because the body is exact, class-owned, source-authored, field-resolved, and not covered by another target.

## Supervisor Active Recheck

- Triggering instruction: Agent-B004 report-only research for [UID:00042W] `by-memory/0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md`, required report path in this file.
- Split repair requirement: no new split is required. [UID:0001GH] already split this corridor into exact children; [UID:00042W] has exact pre/post padding and no nested children.
- In-scope source-bearing child status: the assigned child is exact and implementation-ready. Sibling [UID:00042X] remains B006-owned/currently out of scope except as comparison evidence; this report does not recommend editing it beyond optional cross-reference wording if a support page is already touched.

## Inference Research Guidance Check

The current by-structure rule separates ownership from emission and requires source-quality inference instead of preserving raw names only because original symbols are missing. I treated old generated/simroot/source-route wording as lead material only. Current by-* docs and MCP evidence supersede the old `NC-02` blocker. No Wave2/Wave3 instruction or artifact affected the recommendation; old `simroot_v2` mentions in source-file/class docs were treated only as historical recovered-source leads.

Direct IDA/MCP facts are separated below from documentation evidence and inference. The inferred parts are the source-facing method name `SetSkinIndex`, field name `m_scrollSkinIndex`, and parameter name `skinIndex`.

## Heuristic / Inference Reanalysis And Validation

Source-quality issues encountered and resolved:

- Empty emitter: resolved by formal C++. Blank C++ is no longer justified because the target has an exact raw method body, stable owner/emitter route, exact boundary/padding, and resolved field role. A covered-by comment is rejected because no other UID emits this setter's compare/store/invalidate behavior.
- Field/member name: historical `m_trackStateWord` is too storage-shaped for this target. Current MCP shows the word at `+0xf8` indexes shared scrollbar extent/style tables in `ScrollPane::OnDraw` and `ScrollPane::GetScrollPartRect`; existing ScrollNewGroupPane/ScrollCollectionPane support docs already prefer `m_scrollSkinIndex` for the same table-index role. Use `m_scrollSkinIndex` on new ScrollPane support updates and preserve `m_trackStateWord` only as superseded historical wording.
- Method name: `SetSkinIndex(unsigned short skinIndex)` is inferred. It is preferred over `SetRange`, `SetTrackStateWord`, `SetLowStateWord`, `SetStyleByte`, and `SetScrollStyle` because `+0x100` is the scroll range, `+0xfa` is the separate byte style/state setter, and `+0xf8` is the signed word table index.
- Caller/reachability: no live entry route was recovered. Current raw-helper policy in this project allows source-emitting exact raw methods when owner, body, and field role are strong; preserve the no-route evidence as a confidence cap.
- Source placement: direct owner remains [UID:0000CM] `ScrollPane`; source-file ancestor remains [UID:0000NF] `ScrollBar`. `ScrollablePane` is a consumer/constructor owner of child scrollbars, not this setter's owner. `ScrollWidget` owns the separate `+0xfe` current-position setter. TextEditPane and specialized scroll panes consume or mirror the generic scrollbar pattern but do not own this generic `ScrollPane` child.
- Range boundaries: resolved. The target is exactly `0x0055c2b0-0x0055c2d7`; `0x0055c2a1-0x0055c2b0` and `0x0055c2d7-0x0055c2e0` are `0xcc` padding rows in [UID:0000VN].

Rejected alternatives:

- Keep blank under `NC-02`: rejected as stale. It would leave a reconstructable, owner-routed, source-shaped child as an empty emitter after the field-role blocker has been resolved.
- Use a covered-by marker: rejected. Constructor, draw, and geometry read/use the field but do not emit this setter body.
- Rename to `SetRange`: rejected. `m_scrollRange` is at `+0x100` and tested by `IsScrollThumbVisible`.
- Keep `m_trackStateWord` as primary: rejected for new target/support text because current consumers prove `+0xf8` is a scrollbar skin/style table index, not merely an opaque track state word.
- Transfer ownership to `ScrollBar` file, `ScrollablePane`, `ScrollWidget`, TextEditPane, ScrollNewGroupPane, or ScrollCollectionPane: rejected by receiver field layout and class-local source route.

## Evidence Standards Used

Evidence used:

- Current IDA MCP `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `find_bytes`, `get_bytes`, `insn_query`, and paged `disasm`.
- Current by-* docs for exact target, split parent, class owner, file owner, vtable data, geometry helper, constants, padding, and sibling raw helpers.
- Generated output and tracker/coverage rows as stale-state evidence only.
- Executed reports as leads only, especially B004 [UID:0001GH], B010 [UID:0001GI], B005 ScrollNewGroupPane, B006 ScrollCollectionPane, B001 ScrollVolumePane, B003 BaramApp raw constructor, and B015 SoundManager raw helper.

No IDA mutation tools were used. No by-* docs, generated files, validator/tool state, coverage reports, executed archives, or IDA DB files were edited.

## Evidence Checked

IDA MCP/manual-disassembly/raw-byte checks performed:

- MCP endpoint `http://127.0.0.1:13337/mcp`, session `b6b3c97e`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- `server_health`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- `lookup_funcs`: `0x0055c2b0`, `0x0055c2e0`, and `0x0055c370` are `Not a function`; modeled neighbors include constructor `0x0055c200` size `0xa1`, `ScrollWidget::SetScrollTargetValue` `0x0055c310` size `0x5b`, `ScrollPane::OnDraw` `0x0055c650` size `0x1307`, and `ScrollPane::GetScrollPartRect` `0x0055d9e0` size `0x4b9`.
- `xrefs_to`: zero xrefs to raw starts `0x0055c2b0`, `0x0055c2e0`, and `0x0055c370`; one vtable data xref to `0x0055c650` from `0x00623da0`; fifteen direct xrefs to `0x0055d9e0`.
- `find_bytes`: zero hits for target VA/RVA encodings `B0 C2 55 00` and `B0 C2 15 00`; zero hits for sibling raw VA/RVA encodings `E0 C2 55 00`, `E0 C2 15 00`, `70 C3 55 00`, and `70 C3 15 00`.
- `get_bytes 0x0055c2b0 size 39`: `55 8b ec 66 8b 45 08 66 39 81 f8 00 00 00 74 13 8b 11 66 89 81 f8 00 00 00 8d 41 44 89 45 08 5d ff 62 20 5d c2 04 00`.
- `insn_query 0x0055c2b0-0x0055c2d7`: `push ebp; mov ebp, esp; mov ax,[ebp+8]; cmp [ecx+0F8h],ax; jz loc_55C2D3; mov edx,[ecx]; mov [ecx+0F8h],ax; lea eax,[ecx+44h]; mov [ebp+8],eax; pop ebp; jmp dword ptr [edx+20h]; pop ebp; retn 4`.
- Paged `disasm` for `0x0055c200`: constructor stores `0x10000` at `[esi+0F8h]`, orientation at `[esi+0FCh]`, a dword clear at `[esi+0FEh]`, word `0FF01h` at `[esi+102h]`, and byte `0FFh` at `[esi+104h]`.
- Paged `disasm` for `0x0055c650`: `ScrollPane::OnDraw` repeatedly reads `[esi+0F8h]` as a signed word table index and uses `dword_624144` / `dword_62415C`; it also tests `[esi+0FAh]`, `[esi+0FBh]`, orientation `[esi+0FCh]`, position `[esi+0FEh]`, range `[esi+100h]`, and state bytes `[esi+102h]`.
- `disasm 0x0055d9e0`: `ScrollPane::GetScrollPartRect` reads `[edi+0F8h]` as a signed word table index for `dword_624144` and `dword_62415C`, reads `[edi+0FBh]` as the drag-active byte, orientation `[edi+0FCh]`, position `[edi+0FEh]`, and range `[edi+100h]`.
- `xrefs_to 0x00624144`: 22 data refs including four from `ScrollPane::OnDraw`, one from `ScrollPane::GetScrollPartRect`, and specialized/themed scrollbar consumers.
- `xrefs_to 0x0062415c`: 12 data refs including six from `ScrollPane::OnDraw` and one from `ScrollPane::GetScrollPartRect`.

by-* docs, support docs, old reports, generated reports, and trackers checked:

- Target [UID:00042W], split parent [UID:0001GH], siblings [UID:00042V], [UID:00042X], [UID:00042Z].
- [UID:0000CM] `ScrollPane`, [UID:0000CP] `ScrollWidget`, [UID:0000CF] `ScrollablePane`, [UID:0000NF] `ScrollBar`.
- [UID:0003CK] `ScrollPaneVtableData`, [UID:0001GK] `ScrollPaneGetScrollPartRect`, [UID:0003CQ] `ScrollPaneScrollbarConstantData`, [UID:0000VN] ignored padding.
- `auto-generated/NexusTK/ui/core/ScrollBar.cpp`, `auto-generated/-ag-memory-coverage.md`, and `auto-generated/-ag-research-tracker.md`.
- Search terms used for current/historical reports: `00042W`, `0x0055c2b0`, `0055c2b0`, `ScrollPaneRangeSetterRaw`, `ScrollPane`, `ScrollWidget`, `ScrollablePane`, `ScrollBar`, `m_trackStateWord`, `m_scrollSkinIndex`, and `kScrollPanePartExtentBySkin`.
- Relevant matches opened as leads: `executed-b-agent-research/B004/0001GH-ScrollPaneInputCore-source-quality.md`, `executed-b-agent-research/B010/0001GI-ScrollPaneOnDraw-source-quality.md`, `executed-b-agent-research/B005/0001GP-ScrollNewGroupPaneCore-source-quality.md`, `executed-b-agent-research/B006/0001GU-ScrollCollectionPaneHitTestScrollRegion-source-quality.md`, `executed-b-agent-research/B001/00031M-ScrollVolumePaneSetLowStateWordRaw-source-quality.md`, `executed-b-agent-research/B003/0002PZ-BaramAppConstructorRaw-empty-emitter-source-quality.md`, and `executed-b-agent-research/B015/0003ZH-SoundManagerStopRedbookAndCancelTrackTimerRaw-source-quality.md`.

Negative checks performed:

- No direct code/data xrefs to target start.
- No VA/RVA pointer-byte hits for the target start.
- No evidence that `+0xf8` is the scroll range; range is `+0x100`.
- No evidence that the target is compiler padding or covered by constructor/draw/geometry output.
- No evidence that `ScrollablePane`, `ScrollWidget`, TextEditPane, or specialized scroll-pane classes directly own this generic `ScrollPane` setter.

Failed, unavailable, or intentionally skipped checks:

- No failed MCP calls blocked the report. A broad full `ScrollPane::OnDraw` disassembly response was too large for single-response parsing, so it was paged in 200-instruction chunks and filtered for field/table accesses.
- No validators were run during the report-only evidence pass because no by-* edits had been made yet. Callback validators and generated freshness are recorded below in `Validator Results`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| SP-001 | UID00042W is an exact raw source-shaped setter body at `0x0055c2b0-0x0055c2d7`, not padding. | High | Current MCP `get_bytes` and `insn_query`; ignored padding rows before/after. | Applied to target Status/Behavior/Evidence and [UID:0001GH] child row. Proof: target `Evidence` records bytes/instructions and padding; split parent function table now calls it `ScrollPane::SetSkinIndex` raw setter. | incorporate | applied |
| SP-002 | IDA still has no function object, direct xrefs, or pointer-byte route for `0x0055c2b0`. | High | Current `lookup_funcs`, `xrefs_to`, `find_bytes`. | Applied to target Evidence / First-Draft C++ Route Caveat and support caveat notes in [UID:0001GH], [UID:0000CM], and [UID:0000NF]. | incorporate | applied |
| SP-003 | The target writes the signed word at `+0xf8` only on change and invalidates inherited bounds via primary vtable slot `+0x20` with `this+0x44`. | High | Current `insn_query` exact instruction sequence. | Applied to target Behavior, Evidence, formal C++ block, and generated `ScrollBar.cpp` UID00042W emitted code. | incorporate | applied |
| SP-004 | `+0xf8` should be preferred as `m_scrollSkinIndex`, superseding target-local `m_trackStateWord` wording. | Medium-high | Current `ScrollPane::OnDraw`/`GetScrollPartRect` field accesses to `dword_624144` and `dword_62415C`; [UID:0003CQ], B005/B006 support aliases. | Applied to target, constructor [UID:00042V], class [UID:0000CM], file [UID:0000NF], geometry [UID:0001GK], and constants [UID:0003CQ]. | incorporate | applied |
| SP-005 | Existing `NC-02` blank-C++ proof is stale for this target because field role and source shape are now strong enough for first-draft C++. | Medium-high | Current MCP evidence plus current raw-helper policy leads from B001/B003/B015; no covered-by route. | Historicalized in target `First-Draft C++ / Route Caveat`, split parent notes, class/file historical change entries, and support text that now says UID00042W's old blank state is superseded. | historicalize | applied |
| SP-006 | Formal target C++ should be `void ScrollPane::SetSkinIndex(unsigned short skinIndex)` with compare, early return, store, and `InvalidateRect(&m_bounds)`. | Medium-high | Target body, owner/emitter route, field role, source-shape inference. | Applied to target formal `RECONSTRUCTION_CPP CODE` block; generated `ScrollBar.cpp` lines 29-38 emit the same body. | incorporate | applied |
| SP-007 | Target score should raise from `85/87` to `88/90` after implementation. | Medium-high | Score-blocker audit resolves field/name/C++ blocker while preserving no-route confidence cap. | Applied to target metadata and score rationale. Validator `000000000547` reported `completion_update 88`, `confidence_update 90`, exit `0`, `ok: 1`. | incorporate | applied |
| SP-008 | Target owner/emitter route should remain [UID:0000CM] `ScrollPane`; source-file root remains [UID:0000NF] `ScrollBar`. | High | Existing metadata, class/file docs, receiver field layout, sibling ownership split. | Already present and preserved in target metadata, [UID:0001GH], [UID:0000CM], and [UID:0000NF]. No owner/emitter metadata changed. | already-present | already-present |
| SP-009 | Constructor formal C++ should initialize `m_scrollSkinIndex = 0` instead of `m_trackStateWord = 0`. | Medium-high | Constructor writes `0x10000` at `+0xf8`; current field role reanalysis. | Applied to [UID:00042V] formal C++ and evidence/changes; generated `ScrollBar.cpp` constructor now emits `m_scrollSkinIndex = 0;`. | incorporate | applied |
| SP-010 | [UID:00042X] remains a separate `+0xfa` byte-style setter; this report does not resolve its empty-emitter status. | High | Current target/sibling docs; MCP sibling instruction proof; B006 has separate assignment. | Applied to target rejected alternatives and shared support docs [UID:0001GH], [UID:0000CM], [UID:0000NF]. UID00042X target file itself was not edited. | incorporate | applied |
| SP-011 | `ScrollPane::GetScrollPartRect` and constants docs should preserve that `m_scrollSkinIndex` indexes `kScrollPanePartExtentBySkin` / related `0x00624144` and `0x0062415c` slices. | High | Current MCP `disasm`/`xrefs_to`; [UID:0003CQ], [UID:0001GK]. | Applied to [UID:0001GK], [UID:0003CQ], [UID:0000CM], and [UID:0000NF] support notes. | incorporate | applied |
| SP-012 | Generated `ScrollBar.cpp` should stop listing UID00042W as an empty emitter after scoped target/support validators refresh autogen. | High | Current generated line has UID00042W `Empty Emitter Marker`; formal C++ recommendation is nonblank. | Applied/verified read-only after validators. `ScrollBar.cpp` header is `validator-command-id: 000000000553`, `validator-refreshed-at: 2026-06-29T10:12:13-04:00`; UID00042W emits code at lines 29-38 and does not appear as an `Empty Emitter Marker`. | incorporate | applied |
| SP-013 | No manual `-coverage-report.md` or generated-file edit is authorized; refresh should be validator-owned after accepted by-* edits. | High | Goal/workflow rules. | Applied. No manual generated/project/manual coverage/tool-state/IDA/executed-archive edits were made; generated C++ and generated reports refreshed only through scoped validators. | incorporate | applied |

## Positive Evidence Summary

- The target body is exact and simple: one word argument, compare against `this+0xf8`, conditional store, and inherited bounds invalidation.
- The target is already owned/emitted through `ScrollPane`, and the class/file parent gates are satisfied.
- Current MCP proves `+0xf8` is actively consumed by generic `ScrollPane` draw/geometry code as a table index into shared scrollbar constants. This resolves the previous storage-shaped `m_trackStateWord` blocker.
- Existing project source-facing aliases for the same table-index role in specialized scroll panes prefer `m_scrollSkinIndex` and `kScrollPanePartExtentBySkin`.
- Recent accepted raw-helper work treats no function/no xref as a caveat rather than a categorical formal-C++ blocker when target behavior and source placement are strong.

## IDA MCP Facts

- Function/range facts: target start `0x0055c2b0` is not modeled as an IDA function; exact modeled neighbors are constructor `0x0055c200`, sibling raw starts `0x0055c2e0`/`0x0055c370`, draw `0x0055c650`, and geometry `0x0055d9e0`.
- Data/table/padding facts: target bytes begin with normal prologue and end at `retn 4`; pre/post spans are `0xcc` padding; `0x00624144` and `0x0062415c` have current xrefs from generic and specialized scrollbar geometry/draw code.
- Xref facts: zero target-start xrefs; positive controls include constructor two xrefs, `GetScrollPartRect` fifteen xrefs, `OnDraw` vtable data xref, and many constant-table data refs.
- Vtable/global/type facts: invalidation dispatch is through primary slot `+0x20`, same inherited route used by comparable pane state setters; vtable data page links ScrollPane virtuals but has no slot for this private raw setter.
- Negative IDA facts: no pointer-byte hits for VA/RVA target encodings; no function object; no live caller recovered.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0055c200-0x0055c2a1` | [UID:00042V] `ScrollPaneConstructor` | Constructor; now emits formal C++ with `m_scrollSkinIndex = 0`. | TRUE | `0000CM` | `86/88` | Applied support update; packed `0x10000` init documented as `m_scrollSkinIndex = 0`, `m_scrollStyle = 1`, `m_thumbDragActive = false`. |
| `0x0055c2b0-0x0055c2d7` | [UID:00042W] target | Raw `+0xf8` skin-index setter. | TRUE | `0000CM` | `88/90` | Formal `ScrollPane::SetSkinIndex(unsigned short skinIndex)` C++ populated; path intentionally not renamed. |
| `0x0055c2e0-0x0055c304` | [UID:00042X] `ScrollPaneByteStateSetterRaw` | Separate `+0xfa` byte-style setter. | TRUE | `0000CM` | `85/87` | Out of scope except comparison/cross-reference. |
| `0x0055c3e0-0x0055c3fa` | [UID:000432] `ScrollPaneIsScrollThumbVisible` | Range/enabled predicate. | TRUE | `0000CM` | `85/88` | Already emits formal C++; proves range is `+0x100`, not target `+0xf8`. |
| `0x0055d9e0-0x0055de99` | [UID:0001GK] `ScrollPaneGetScrollPartRect` | Geometry consumer of `+0xf8` and tables. | TRUE | `0003A5` | `85/88` | Support update applied for resolved `m_scrollSkinIndex`; helper formal C++ still intentionally blank for its own branch/formula blockers. |
| `0x00624138-0x00624168` | [UID:0003CQ] `ScrollPaneScrollbarConstantData` | Shared scrollbar dimension/style constants. | TRUE | `0000NF` | `85/88` | Support update applied to add UID00042W as setter for the index field. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0055c2b0` | zero xrefs | No live entry route recovered for the target start. |
| `0x0055c200` | xrefs at `0x0055e6f4`, `0x0055e72c` | `ScrollablePane` constructs horizontal/vertical `ScrollPane` children. |
| `0x0055c650` | data xref at `0x00623da0` | `ScrollPane::OnDraw` is vtable-only reached; current draw report is a field-use lead. |
| `0x0055d9e0` | fifteen direct call refs | Generic geometry helper consumes `+0xf8` and is called by draw/input helpers. |
| `0x00624144` | 22 data refs | Shared vertical/fixed extent table slice indexed by `+0xf8` in ScrollPane and sibling scroll panes. |
| `0x0062415c` | 12 data refs | Shared horizontal/style extent table slice indexed by `+0xf8` in ScrollPane paths. |

## Documentation Evidence And IDA Status

- Existing docs supporting the conclusion: [UID:0000CM] already says [UID:00042W] is a direct `ScrollPane` child and [UID:0000NF] places it in `ScrollBar.cpp`; [UID:0003CQ] documents the shared constants and `m_scrollSkinIndex` consumer pattern; [UID:0001GK] identifies the exact geometry helper; [UID:0000VN] confirms padding.
- Pre-callback stale docs found: target `NC-02`, constructor formal `m_trackStateWord`, class/file statements that raw `+0xf8` stayed blank, and `ScrollPaneGetScrollPartRect` final-C++ blocker text that still treated this field name as unresolved.
- Callback incorporation status: those stale statements were either replaced or historicalized. Current `auto-generated/NexusTK/ui/core/ScrollBar.cpp` header is validator command `000000000553`, refreshed `2026-06-29T10:12:13-04:00`; UID00042W emits `ScrollPane::SetSkinIndex(unsigned short skinIndex)` and no longer appears as an `Empty Emitter Marker`.

## Ranked Ownership Analysis

### 1. [UID:0000CM] ScrollPane

- Evidence for: receiver is the same object whose constructor writes `+0xf8`; neighboring constructor/raw byte setter/predicate/mouse/default/timer children are direct `ScrollPane`; draw and geometry methods consume the same field; existing metadata already owns/emits through `ScrollPane`.
- Evidence against: no direct caller or pointer route to the raw start, and no original method name.
- Decision: keep as direct owner/emitter. No-route is a confidence cap, not a blocker.

### 2. [UID:0000NF] ScrollBar file

- Evidence for: file root owns the generic scrollbar source family and receives generated `ScrollBar.cpp`.
- Evidence against: file is too broad as canonical owner for a class-local field setter.
- Decision: keep as source-file ancestor only.

### 3. [UID:0000CF] ScrollablePane

- Evidence for: `ScrollablePane` constructs `ScrollPane(1)` and `ScrollPane(0)` children and has scroll synchronization/layout roles.
- Evidence against: it is a consumer/owner of child objects, not the class whose `+0xf8` is written by target.
- Decision: reject.

### 4. [UID:0000CP] ScrollWidget

- Evidence for: nearby raw setter at `0x0055c370` has the same compare/store/invalidate pattern.
- Evidence against: `ScrollWidget` state is `+0xfe/+0x100/+0x102` in a separate child range. Target sits before the `ScrollWidget` method group and uses `ScrollPane` field layout.
- Decision: reject.

### 5. Specialized scroll panes / TextEditPane

- Evidence for: ScrollNewGroupPane, ScrollCollectionPane, and TextEditPane-related helpers share scrollbar geometry, table-index fields, and generated historical source pollution.
- Evidence against: they are separate source/class routes or consumers of the generic scrollbar API. No specialized caller or object owns this generic `ScrollPane` target.
- Decision: reject.

## Source Placement

- Recommended source placement: `ScrollPane` class under [UID:0000NF] `NexusTK/ui/core/ScrollBar.cpp`.
- Why this fits: constructor, draw, geometry, vtable data, shared constants, and sibling methods are all in the generic scrollbar source family.
- Rejected placements: `ScrollablePane`, `ScrollWidget`, `TextEditPane`, `Group/ScrollNewGroupPane`, `ScrollCollectionPane`, `ScrollVolumePane`, standalone helper file, or no-owner bucket.
- Remaining uncertainty: exact original method spelling is unknown. `SetSkinIndex` is inferred from current field role and source-family naming, not original symbol proof.

## Range / Split / Padding / Reclassification Analysis

- Exact target range: `0x0055c2b0-0x0055c2d7`.
- Pre-padding: `0x0055c2a1-0x0055c2b0`, already in [UID:0000VN] as `0xcc`.
- Post-padding: `0x0055c2d7-0x0055c2e0`, already in [UID:0000VN] as `0xcc`.
- No split/merge needed. The target is one source-shaped raw helper and has no children.
- Reclassification: keep `RECONSTRUCTABLE:TRUE`; do not convert to non-reconstructable or no-owner.

## Negative Evidence Summary

No route was found that proves a live call to `0x0055c2b0`: no IDA function object, direct xrefs, or pointer-byte hits. That means the final score should remain below final-audit quality and the source name should be marked inferred. It does not prove padding, compiler trash, or covered-by status because the bytes form a normal setter and the field has class-local consumers.

Consumer/read xrefs to `+0xf8` do not prove the setter's caller. They prove the field role, which is enough to replace the storage-shaped target name and write behaviorally exact private setter C++ while preserving the no-route caveat.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes.
- Recommended formal `RECONSTRUCTION_CPP CODE` block:

```cpp
void ScrollPane::SetSkinIndex(unsigned short skinIndex)
{
    if (m_scrollSkinIndex == skinIndex) {
        return;
    }

    m_scrollSkinIndex = skinIndex;
    InvalidateRect(&m_bounds);
}
```

- Reason it preserves exact original behavior: one `unsigned short` argument is compared with `[ecx+0xf8]`; unchanged value returns immediately; changed value stores the word and dispatches the inherited invalidation slot with `this+0x44`, represented as `InvalidateRect(&m_bounds)`.
- Reason it matches plausible original source shape: it is a small private class helper for a skin/style index field, matching neighboring raw setter patterns and the project style used by accepted ScrollVolumePane raw helper C++.
- Inferred source-facing names/types: `ScrollPane::SetSkinIndex`, `unsigned short skinIndex`, `m_scrollSkinIndex`, `InvalidateRect`, `m_bounds`.
- Naming convention evidence: `m_scrollSkinIndex` is already preferred in current ScrollNewGroupPane/ScrollCollectionPane support docs for `+0xf8` table-index fields using `kScrollPanePartExtentBySkin`; `SetSkinIndex` matches the existing ScrollNewGroupPane method-row wording.
- Reason code should remain blank: not applicable. The old blank-C++ proof should be historicalized.
- Exact no-code proof if not eligible: not applicable.

## Final Recommendation

- Update UID00042W target to first-draft C++ emitter, not blank no-code.
- Rename title/summary wording from range/track-word setter to skin-index setter. A file rename to `by-memory/0x0055c2b0-0x0055c2d7.ScrollPaneSetSkinIndexRaw.md` or `...ScrollPaneSkinIndexSetterRaw.md` is recommended if the supervisor accepts path churn; preserve UID `00042W`.
- Keep owner/emitter route unchanged: `0000CM -> 0000NF`.
- Raise target to `COMPLETION:88`, `CONFIDENCE:90`.
- Preserve no-function/no-xref/no-pointer evidence in target and support docs as a confidence cap.

## Recommended Target Doc Changes

Target path: `by-memory/0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md`.

Exact report facts to incorporate:

- Replace `Range Setter Raw` / word-state wording with `ScrollPane SetSkinIndex Raw` or `ScrollPane Skin Index Setter Raw`.
- Replace item summary with: `Raw ScrollPane skin-index setter; updates inferred m_scrollSkinIndex at +0xf8 only on change and invalidates inherited bounds through primary slot +0x20.`
- Set metadata to `COMPLETION:88`, `CONFIDENCE:90`; keep `CANONICAL_OWNER:0000CM`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CM`, `Nested:0`.
- Replace blank formal C++ with the exact `ScrollPane::SetSkinIndex(unsigned short skinIndex)` block above.
- Replace `No-Code Proof` with a `First-Draft C++ / Route Caveat` section that says no function/xref/pointer route is recovered, but the field role and source shape support first-draft private-method emission.
- Preserve target bytes, instruction sequence, route-negative evidence, padding boundaries, and rejected alternatives.

## Recommended Support Doc Changes

- `by-memory/0x0055c200-0x0055c2a1.ScrollPaneConstructor.md`: in formal C++, replace `m_trackStateWord = 0;` with `m_scrollSkinIndex = 0;`; update formal-note text to list `m_scrollSkinIndex` instead of `m_trackStateWord`; explain constructor packed init `0x10000` sets `m_scrollSkinIndex = 0`, `m_scrollStyle = 1`, and `m_thumbDragActive = false`.
- `by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md`: update child row for UID00042W to `ScrollPane::SetSkinIndex(unsigned short skinIndex)`, formal C++ present; historicalize old `NC-02`; preserve no-route evidence.
- `by-class/ScrollPane.md`: update Method Families and 2026-06-26 split wording so UID00042W is first-draft C++ ready/present after callback; add field-role note for `+0xf8 m_scrollSkinIndex`, `+0xfa m_scrollStyle`, `+0xfb m_thumbDragActive`, `+0xfc orientation`, `+0xfe position`, `+0x100 range`, `+0x102 enabled`; preserve that [UID:00042X] remains separate/out of scope.
- `by-file/ScrollBar.md`: update Proposed Contents/Evidence Notes for the input-core split so UID00042W is no longer a blank raw setter; record `m_scrollSkinIndex` and formal `SetSkinIndex` under generic `ScrollPane`; keep file score unchanged unless broader file audit is done.
- `by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md`: update final-C++ blocker text so the `+0xf8` field-name sub-blocker is resolved to `m_scrollSkinIndex`; keep the helper's own formal C++ blank until all branch formulas/helper names are ready.
- `by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md`: add UID00042W as the generic `ScrollPane` setter for the `m_scrollSkinIndex` field that indexes `dword_624144` / `dword_62415C`; score/metadata can remain unchanged.
- `by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md`: no required edit; this setter is not a vtable slot. Optional note only if support text mentions method inventory.
- `by-memory/0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md`: no required edit; if touched for cross-reference consistency, explicitly keep it as the separate `+0xfa` byte-style setter and do not apply UID00042W's C++ decision to UID00042X.

## Score And Metadata Recommendation

- Current target score/metadata: `85/87`, `CANONICAL_OWNER:0000CM`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CM`, blank C++.
- Recommended target score/metadata: `88/90`, same owner/reconstructable/emitter route, formal C++ populated.
- Score rationale: completion increases because range, body, padding, owner, field role, source name, C++ disposition, negative route evidence, generated-output implication, and support-doc updates are now implementation-ready. Confidence increases because current MCP and support docs resolve `+0xf8` as a skin/style index. Confidence does not exceed `90` because no original symbol or live entry route was recovered.
- Score-improvement attempt: caller/reachability, field names, source placement, sibling helpers, range boundaries, generated output, and C++ readiness were all checked. Only original method spelling/live route remain unresolved, and they are confidence caps rather than implementation blockers.

## Open Questions With Attempted Resolution

- Exact original method spelling: unresolved. Evidence checked includes body shape, field consumers, sibling naming, current support aliases, and raw-helper policy. Best supported source name is `SetSkinIndex`; original-proof absence keeps confidence below final audit.
- Live entry route: unresolved. `lookup_funcs`, `xrefs_to`, and `find_bytes` found no route. This is preserved as a route caveat and does not block formal C++ because the source body is exact and owner/field/source-shape are resolved.
- Whole `ScrollPane::GetScrollPartRect` final C++: not resolved by this report. Only the `+0xf8` field-name sub-blocker is resolved; branch-level formula reconstruction remains a separate target's issue.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual `-coverage-report.md` or supervisor-owned tracker edit is requested for this report-only pass. Validator-owned generated reports should refresh after accepted by-* edits and scoped validators.

## Follow-Up Actions

- Supervisor action: validate this report and, if accepted, send implementation callback for the target/support docs listed above.
- B004 callback action if accepted: apply exact target/support edits, run scoped validators with `--wait-generated`, update this report ledger/checklist with proof, and verify UID00042W no longer appears as an empty emitter in generated `ScrollBar.cpp`.
- Separate future work: B006-owned UID00042X may need its own empty-emitter decision; do not fold that work into UID00042W.

## Confidence

- Recommendation confidence: high for emitting first-draft C++; medium-high for exact method spelling.
- Score confidence: `88/90` after implementation.
- Remaining uncertainty: unrecovered original symbol and live callable route.

## Validator Results

Callback validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` with `--apply --queue-timeout 240 --wait-generated`. A first unfiltered batch completed with exit `0` for all files and showed existing project-wide warnings (`autogen_registry_stale`, `memory_coverage_metadata_missing_file`, `autogen_emitter_has_no_code`, and `autogen_children_marker_missing`) but no target-specific failure. The filtered rerun below is the recorded callback validation set:

| File | Command | command_id | command_timestamp | Exit | ok | generated_refresh |
| --- | --- | --- | --- | --- | --- | --- |
| `by-memory\0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md` | `python .\tools\validator.py --mode file --file by-memory\0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md --apply --queue-timeout 240 --wait-generated` | `000000000547` | `2026-06-29T10:11:19-04:00` | `0` | `1` | completed, refresh command `000000000547`, timestamp `2026-06-29T10:11:19-04:00` |
| `by-memory\0x0055c200-0x0055c2a1.ScrollPaneConstructor.md` | `python .\tools\validator.py --mode file --file by-memory\0x0055c200-0x0055c2a1.ScrollPaneConstructor.md --apply --queue-timeout 240 --wait-generated` | `000000000548` | `2026-06-29T10:11:28-04:00` | `0` | `1` | completed, refresh command `000000000548`, timestamp `2026-06-29T10:11:28-04:00` |
| `by-memory\0x0055c200-0x0055c643.ScrollPaneInputCore.md` | `python .\tools\validator.py --mode file --file by-memory\0x0055c200-0x0055c643.ScrollPaneInputCore.md --apply --queue-timeout 240 --wait-generated` | `000000000549` | `2026-06-29T10:11:37-04:00` | `0` | `1` | completed, refresh command `000000000549`, timestamp `2026-06-29T10:11:37-04:00` |
| `by-class\ScrollPane.md` | `python .\tools\validator.py --mode file --file by-class\ScrollPane.md --apply --queue-timeout 240 --wait-generated` | `000000000550` | `2026-06-29T10:11:46-04:00` | `0` | `1` | completed, refresh command `000000000550`, timestamp `2026-06-29T10:11:46-04:00` |
| `by-file\ScrollBar.md` | `python .\tools\validator.py --mode file --file by-file\ScrollBar.md --apply --queue-timeout 240 --wait-generated` | `000000000551` | `2026-06-29T10:11:55-04:00` | `0` | `1` | completed, refresh command `000000000551`, timestamp `2026-06-29T10:11:55-04:00` |
| `by-memory\0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md` | `python .\tools\validator.py --mode file --file by-memory\0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md --apply --queue-timeout 240 --wait-generated` | `000000000552` | `2026-06-29T10:12:04-04:00` | `0` | `1` | completed, refresh command `000000000552`, timestamp `2026-06-29T10:12:04-04:00` |
| `by-memory\0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md` | `python .\tools\validator.py --mode file --file by-memory\0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md --apply --queue-timeout 240 --wait-generated` | `000000000553` | `2026-06-29T10:12:13-04:00` | `0` | `1` | completed, refresh command `000000000553`, timestamp `2026-06-29T10:12:13-04:00` |

Generated freshness check:

- `auto-generated/NexusTK/ui/core/ScrollBar.cpp` header: `validator-command-id: 000000000553`, `validator-refreshed-at: 2026-06-29T10:12:13-04:00`, `validator-refresh-source: foreground-generated-refresh`.
- The header is equal to the last scoped validator and newer than the target validator `000000000547`; UID00042W emits real `ScrollPane::SetSkinIndex(unsigned short skinIndex)` code and no UID00042W `Empty Emitter Marker` remains. Other unrelated empty-emitter markers in `ScrollBar.cpp` are unchanged.

Lease proof:

- Initial B004 lease batch for the seven edited by-* files succeeded at `2026-06-29T14:02:24Z` and expired at `2026-06-29T14:07:24Z` during consistency scanning; no further by-* edits were made after expiration until leases were reacquired.
- Second B004 lease batch for the same seven files succeeded at `2026-06-29T14:07:55Z` and expired at `2026-06-29T14:12:55Z`.
- `python .\leaser.py B004 unlease` returned `Success` for all seven files; final `current_leases.md` check at `2026-06-29T14:12:56Z` showed no active leases.

## Changed Files

- Modified by B004 callback:
  - `by-memory/0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md`
  - `by-memory/0x0055c200-0x0055c2a1.ScrollPaneConstructor.md`
  - `by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md`
  - `by-class/ScrollPane.md`
  - `by-file/ScrollBar.md`
  - `by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md`
  - `by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md`
  - `tools/leaser/Agents/Agent-B004/research/00042W-ScrollPaneRangeSetterRaw-empty-emitter-source-quality.md`
- Validator-owned generated/tool-state side effects: generated `auto-generated/NexusTK/ui/core/ScrollBar.cpp`, generated coverage/tracker/stats outputs, and validator registry state refreshed through the scoped validators. These were not manually edited.
- Confirmed no required edit to `by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md`; UID00042W is not a vtable slot.
- Confirmed no direct edit to `by-memory/0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md`; UID00042X remains a separate `+0xfa` byte-style setter.
- Renamed: none. The target file path remained stable per callback instruction.
- Report execution: supervisor-owned; do not run `execute_report` during this pass.

## Implementation Tracking Checklist

- [x] Supervisor validation accepted this report for implementation. Proof: callback assignment `B004-implement-00042W-ScrollPaneRangeSetterRaw-20260629`.
- [x] Target doc updated: [UID:00042W] `by-memory/0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md`; title/summary now describe skin-index setter, metadata is `88/90`, owner/emitter/reconstructable are preserved, path was not renamed, and exact formal `ScrollPane::SetSkinIndex(unsigned short skinIndex)` C++ was inserted.
- [x] Support doc updated: [UID:00042V] constructor formal C++ and notes now use `m_scrollSkinIndex`; packed `0x10000` init is documented as `m_scrollSkinIndex = 0`, `m_scrollStyle = 1`, `m_thumbDragActive = false`.
- [x] Support doc updated: [UID:0001GH] split index child row and parent no-code disposition now record UID00042W formal C++ present and old `NC-02` historicalized.
- [x] Support doc updated: [UID:0000CM] `ScrollPane` method family, field-role notes, and raw setter C++ status now record `+0xf8 m_scrollSkinIndex` / `SetSkinIndex`; UID00042X remains separate.
- [x] Support doc updated: [UID:0000NF] `ScrollBar` source-family evidence and generated-output expectation now record UID00042W as first-draft `SetSkinIndex` instead of blank.
- [x] Support doc updated: [UID:0001GK] `ScrollPaneGetScrollPartRect` field-name blocker status now says `+0xf8` is resolved to `m_scrollSkinIndex`; its own formal C++ remains blank for remaining branch/formula blockers.
- [x] Support doc updated: [UID:0003CQ] scrollbar constants note now lists UID00042W as the generic `ScrollPane::SetSkinIndex` writer for the `m_scrollSkinIndex` table index.
- [x] Confirmed no required edit to [UID:0003CK] `ScrollPaneVtableData` because UID00042W is not a vtable slot; page was read and left unchanged.
- [x] Confirmed no direct edit to [UID:00042X]; shared support docs explicitly preserve it as the separate `+0xfa` byte-style setter and do not apply UID00042W's C++ decision to it.
- [x] Claim And Incorporation Ledger updated during callback with destination/proof and verification state for SP-001 through SP-013.
- [x] Historical/stale assumptions preserved: old `m_trackStateWord`/`NC-02` wording is marked superseded/historical, not silently erased.
- [x] Score-blocker audit applied: no-function/no-xref/no-pointer route preserved as confidence cap; field/name/C++ blocker resolved; no covered-by marker used.
- [x] Scoped validators run for every edited by-* file using `--apply --queue-timeout 240 --wait-generated`; command IDs `000000000547` through `000000000553`, timestamps, exit codes, ok counts, warnings, and generated refresh state are recorded above.
- [x] Generated freshness checked read-only: `auto-generated/NexusTK/ui/core/ScrollBar.cpp` header `000000000553` / `2026-06-29T10:12:13-04:00` is equal/newer than the validator batch, UID00042W emits formal C++ and no longer appears as `Empty Emitter Marker`.
- [x] No manual generated files, project-level generated files, manual `-coverage-report.md` files, validator/tool state, executed archives, lock files, or IDA DB edits. Validator-owned generated/tool-state refreshes were caused only by scoped validator commands.
- [x] Leases were short and edit/validator scoped. First lease batch expired before validation; second lease batch covered the follow-up edit/validator batch; `B004 unlease` returned success and final `current_leases.md` has no active leases.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/00042W-ScrollPaneRangeSetterRaw-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00042W-ScrollPaneRangeSetterRaw-empty-emitter-source-quality.md","timestamp":"2026-06-29T10:17:45","uid":"00042W"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
