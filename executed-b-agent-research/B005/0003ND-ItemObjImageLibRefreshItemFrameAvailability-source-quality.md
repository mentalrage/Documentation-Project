** TARGET-REPORT-UID:0003ND **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003ND ItemObjImageLib Refresh Item Frame Availability Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: implemented. [UID:0003ND] remains a private, source-authored `ItemObjImageLib` helper named descriptively `RefreshItemFrameAvailability`, with direct owner/emitter [UID:00006W] and a populated exact formal C++ block.
- Final disposition: source-ready first draft implemented. The former no-code rationale is superseded because current MCP plus accepted `EPFTileContext`, `ResourceLayoutTable`, `PaletteLib`, `DLPalette`, `ProtectedArray<ItemInfo>`, and `ItemInfo` support resolve every behavior-affecting dependency used by this body.
- Required action: no further B005 implementation action remains. Independent supervisor verification and any later execution/archive transition are external to this report text and validator-owned lifecycle history.
- Confidence: high for behavior, range, ownership, source placement, fields used, and first-draft body; medium-high for the exact original helper spelling because the binary has no symbol, modeled function object, caller, or pointer route to the start.

## Supporting Research

- Historical lifecycle note: supervisor Gate 1 accepted report SHA256 `63B730492C9B614E73F3295CF5A9A4366D194CDDFCBE8632F2407FEE9428798C`, then B005 completed the accepted implementation callback. B005 did not run any report execution, lifecycle, or move command; subsequent execution/archive state is external validator-owned history and is intentionally not asserted here.
- The prior pause for unavailable MCP is historical only. Current mandatory evidence comes from active NexusTK IDB session `359c7886` through MCP transport session `82d19bb1-8cfe-4847-97ae-b5328602498e` on 2026-07-12.
- The source queue is `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`. Its current row reports UID0003ND at `85/88`, reconstructable, zero executed reports.
- Current generated memory coverage reports UID0003ND as `emits` through owner/emitter `00006W` to `auto-generated/NexusTK/render/ItemObjImageLib.cpp`, but code state `no`. The generated file read during this pass had `validator-command-id: 000000008166` and `validator-refreshed-at: 2026-07-12T15:49:51-04:00`; it contains no UID0003ND body.

## Target

- Target UID: `0003ND`.
- Target path: `by-memory/0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability.md`.
- Address range: half-open `0x004df670-0x004df7d2`, `0x162` bytes.
- Source queue/report row: first row in current by-memory not-covered reconstructable bucket, score `85/88`, combined `86.5`, reports `0`.
- Current supervisor classification: report-only source-quality research for a reconstructable empty emitter.
- Current parent state: direct owner/emitter [UID:00006W] `ItemObjImageLib` at `88/89`, flowing to [UID:0000KH] `ItemObjImageLib.cpp` at `90/88`, projected under `NexusTK/render/`.

## Current Target State

- Current metadata: `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:00006W`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006W`, `EMITTER_POSITION_OPTIONAL:20`, populated formal C++.
- Existing owner/emitter state: correct. The body uses an `ItemObjImageLib *this` in `ECX`, count at object `+0x08`, row base at `+0x0c`, fallback/default row at `+0x14`, and `0x14`-byte `ItemInfo` rows.
- Current C++/emitter state: the target emits through UID00006W's explicit `[[CHILDREN]]` marker into generated `ItemObjImageLib.cpp`; layout position `1` precedes method position `20`.
- Superseded blocker text: original helper name, final `ItemInfo` field names, and resource/palette helper names were previously cited as reasons to keep code blank. Current support docs and MCP close the behavior-affecting dependency blockers. Exact original spelling remains unknown but is a confidence caveat, not a no-code proof.
- Existing field state: `ItemInfo::paletteSlot` at `+0x04` and `allowPaletteFilter` at `+0x10` are sufficiently supported for first-draft code. The target neither reads nor depends on provisional `itemTableId` at `+0x00` or `renderFlagsOrMode` at `+0x0c`.
- Related docs checked: ItemObjImageLib class/file/layout/ItemInfo pages, adjacent UID0003LZ loader, UID000201 pixel-range method, UID0002KP resource lookup, ProtectedArray support/accessor, EPFTileContext class/file/aggregate, PaletteLib/DLPalette/global support, current generated output, tracker and generated memory coverage.
- Current artifact/lifecycle status: implementation content is complete and archive-neutral. Report execution/archive/validation-status state must be read from external validator-managed history rather than inferred from this report's path or prose.

## Executive Recommendation

Emit a private method body through the existing class/file route. Use the established source-facing API names `g_useEpfAssets`, `g_pEPFLib->LookupLayoutEntry`, `EPFTileContext::Initialize`, `g_pPaletteLib->GetSlotPalette`, `ProtectedArray<ItemInfo>::GetAtOrDefault`, and `EPFTileContext::ContainsIndexedPixelInRanges`. Keep `RefreshItemFrameAvailability` and `allowPaletteFilter` as descriptive inferred names, explicitly labeled as such.

The implemented first draft normalizes only the binary's duplicated EPF/EPD loop by selecting the resource name once. It preserves all observed behavior: no work for nonpositive count, per-row context initialization, frame index equal to row index, no write after failed layout lookup, palette category `10`, row palette slot, super-palette index `0`, two bounds-checked row lookups around the palette call, and boolean storage at row `+0x10`.

## Supervisor Active Recheck

- Trigger: supervisor assigned UID0003ND specifically to determine whether the raw helper should remain an empty emitter or receive formal first-draft C++ after UID000201's `DLPalette *` resolution.
- Split repair: not required. Current MCP reconfirms one prolog-started helper ending at `0x004df7d2`, bounded by eight leading and fourteen trailing `0xcc` bytes.
- Source-bearing children: none. The target is already the exact source-bearing child; the adjacent modeled UID0003LZ loader and following UID0002IU LightObj constructor remain separate.

## Inference Research Guidance Check

- IDA fact, documentation evidence, and inference are separated below.
- Existing docs were treated as leads. Current MCP independently rechecked the raw instruction stream, boundary bytes, function-model status, xrefs, pointer-byte searches, call inventory, resource literals, dependencies, and unique signature.
- No Wave2/Wave3 material was used as evidence. The current generated C++ and generated reports were used only to establish current emitter/output state.
- The lack of original symbols does not justify keeping a source-authored, behavior-complete method empty. The implemented names follow current accepted project vocabulary and remain explicitly inferred.

## Heuristic / Inference Reanalysis And Validation

### Helper role and name

- Direct fact: the method loops every current `ItemInfo` row and conditionally overwrites byte `+0x10` with the result of testing decoded frame pixels against palette entry-move ranges.
- Best source name: `ItemObjImageLib::RefreshItemFrameAvailability()`. It is descriptive rather than symbol-proven and matches current class/file/page vocabulary.
- Rejected names: `LightInfoTableLoader` is contradicted by range, row, and resource evidence; `RefreshPaletteAvailability` is too broad because the operation is per item frame; `ValidateItemResources` is too broad because no table/resource validity state other than the row byte is updated; raw `sub_4DF670` is not source quality.

### Field and type names

- `m_itemInfos`: validated by object layout, count/base/fallback offsets, adjacent constructor/loader behavior, and accepted `ProtectedArray<ItemInfo>` support.
- `paletteSlot`: validated by both branches pushing row `+0x04` as the second argument to `PaletteLib::GetSlotPalette(10, ..., 0)`.
- `allowPaletteFilter`: retained as the current descriptive field name. The target computes it from actual indexed pixels and draw methods test it when palette filtering is active. `hasPaletteFilterPixels` would describe the producer more literally, but changing an already emitted cross-family field for spelling alone is not justified without original-symbol evidence.
- `EPFTileContext`, `DLPalette`, and method signatures are supported by current exact child pages. No raw integer, byte-array, or decompiler temporary type is needed.

### Source placement and ownership

- The receiver and row storage prove class ownership. `ITEM.EPF`/`ITEM.EPD`, `g_pEPFLib`, `g_pPaletteLib`, and EPFTileContext are dependencies, not owners.
- File placement remains `NexusTK/render/ItemObjImageLib.cpp`. No new helper file or free-function route is warranted.
- The method should be declared private in the formal `ItemObjImageLib` layout/declaration route because no caller/public API evidence exists.

### Raw reachability

- Current MCP finds no function object at the start or interior probes, no xrefs to `0x004df670`, and no little-endian VA or RVA pointer-byte hits.
- Those negatives establish that present reachability is unavailable, not that the bytes are dead padding or compiler glue. The independent prolog, stack cookie, two returns, repeated domain calls, table loop, and alignment boundaries prove source-authored code.
- A retained but unreferenced private method is plausible in an old MSVC translation unit, especially when object-level linking/function elimination does not discard every unreferenced member. No synthetic caller should be invented.

### Range and split

- `0x004df668-0x004df670`: eight `0xcc` bytes.
- `0x004df670-0x004df7d2`: one raw helper with two archive-mode branches.
- `0x004df7d2-0x004df7e0`: fourteen `0xcc` bytes.
- No child split is justified for the duplicated EPF/EPD branches; they share one prolog, receiver, stack cookie, behavior, and source responsibility.

### C++ readiness

- The old no-code proof is rejected. All called source APIs now have accepted source-facing names and signatures, the target uses only supported fields, and its branch/loop/write behavior is exact enough for a first draft.
- Exact original helper spelling and missing caller route cap confidence below final-audit range but do not change behavior or make the formal body unsafe.

## Evidence Standards Used

- Authoritative binary evidence: current IDA MCP `idb_list`, `lookup_funcs`, bounded `search_text`, `get_bytes`, `xrefs_to`, `xref_query`, `find_bytes`, bounded `insn_query`, `decompile` on modeled dependencies, `callees`, and `make_signature_for_range`.
- Documentation evidence: current exact by-memory pages, class/file/type/global support pages, current validator-generated tracker/coverage/output, and search-gated matching executed B reports.
- Negative evidence: absent function model, start xrefs, VA/RVA pointer hits, LightObj signals, split boundaries, alternate owners, and target-local type records/symbols.
- Evidence ladder: current binary facts control range and behavior; accepted exact support pages provide source-facing API/type names; source shape and exact original spellings remain inference.

## Evidence Checked

- IDA MCP session: database `359c7886`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active/adopted worker PID `13016`; MCP transport session `82d19bb1-8cfe-4847-97ae-b5328602498e`.
- Raw target checks: exact rendered listing for `0x004df670-0x004df7d2` (`127` instruction/listing hits), boundary bytes at `0x004df668` and `0x004df7c0`, ten bounded call matches, start xref query, VA/RVA pointer-byte searches, and unique range signature.
- Dependency checks: current lookup/decompilation for `0x00457a60`, `0x00458590`, `0x004d02f0`, and `0x00543e40`; xrefs to the two resource literals and key globals; bytes for the wide resource string run.
- by-* docs: target; `by-class/ItemObjImageLib.md`; `by-file/ItemObjImageLib.md`; `by-type/by-struct/ItemObjImageLibLayout.md`; `by-type/by-struct/ItemInfo.md`; UID0003LZ; UID000201; UID0002KP; EPFTileContext and ProtectedArray support; relevant folder guidance and `by-structure.md` MCP/autogen rules.
- Generated/project state: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/NexusTK/render/ItemObjImageLib.cpp`.
- Search terms: `0003ND`, `004df670`, `ItemObjImageLibRefreshItemFrameAvailability`, `RefreshItemFrameAvailability`, `ItemObjImageLib`, and `EPFTileContextPixelRangeTest` across central executed reports and active agent folders.
- Matching old reports opened: B003 `0003LZ-LightInfoTableLoader.md`, B008 `00006W-ItemObjImageLib-class-source-quality.md`, and B005 UID000201 source-quality report/current executed artifact. They were treated as leads and rechecked against current MCP.
- Failed/skipped checks: decompiling UID0003ND itself is unavailable because IDA has no function object. No IDA mutation (`define_func`, rename, type application, comment, or save) was attempted. No broad/unbounded MCP query was used.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Exact source helper range is `0x004df670-0x004df7d2`. | very high | MCP bytes/listing/adjacent lookup | target `Status`, boundary, current-MCP subsection | incorporate | applied |
| C02 | Leading `0x004df668-0x004df670` and trailing `0x004df7d2-0x004df7e0` are `0xcc` padding. | very high | MCP `get_bytes` | target `Boundary And Padding` | already-present | already-present |
| C03 | IDA has no function object, start xref, VA pointer, or RVA pointer route. | very high | `lookup_funcs`, `xref_query`, `find_bytes` | target current-MCP subsection and score rationale | incorporate | applied |
| C04 | Body is source-authored `void __thiscall` ItemObjImageLib helper, not padding/glue. | high | prolog, ECX receiver, stack cookie, two returns, domain calls | target `Status`, current-MCP subsection, ownership | incorporate | applied |
| C05 | EPF and EPD branches differ only by `ITEM.EPF` vs `ITEM.EPD`; both use the same image and palette globals. | very high | full raw listing | target `Behavior` and current-MCP subsection | incorporate | applied |
| C06 | Each branch initializes `EPFTileContext`, looks up frame index equal to row index, and writes only after non-null lookup. | very high | calls/branch at `0x4df6b2..0x4df721` and mirrored branch | target current-MCP subsection/formal C++ | incorporate | applied |
| C07 | Palette call is `GetSlotPalette(10, itemInfo.paletteSlot, 0)` and returns `DLPalette *`. | high | raw pushes plus UID000201/PaletteLib support | target `Behavior`, UID000201 sync, formal C++ | already-present | already-present |
| C08 | Stored result is `ContainsIndexedPixelInRanges(palette)` at `ItemInfo+0x10`. | very high | call/store pairs `0x4df70c/0x4df711`, `0x4df7aa/0x4df7af` | target `Behavior`, UID000201 sync, formal C++ | already-present | already-present |
| C09 | Existing `allowPaletteFilter` is retained as a descriptive field name; no support-wide rename is justified. | high | producer and draw-consumer semantics | target source-quality/current-MCP text; `ItemInfo.md` Notes/Changes | incorporate | applied |
| C10 | `RefreshItemFrameAvailability` remains descriptive, inferred, and first-draft safe. | high | complete behavior plus no symbol evidence | target Status/Score/Changes; class/file notes | incorporate | applied |
| C11 | Direct owner/emitter remain UID00006W; file root remains UID0000KH under `NexusTK/render/`. | very high | receiver layout, resources, current parent chain | target metadata; class/file support | already-present | already-present |
| C12 | First-draft formal method body replaces the empty target block. | high | closed dependencies and exact control/data flow | target formal block; generated `ItemObjImageLib.cpp` UID0003ND block | incorporate | applied |
| C13 | Formal class/layout declaration adds private `void RefreshItemFrameAvailability();`. | high | method has class receiver and no public caller evidence | `ItemObjImageLibLayout.md` formal block/Notes/Changes | incorporate | applied |
| C14 | No split, new child, new owner, free-function route, or LightObj route is warranted. | very high | boundaries and negative ownership evidence | target/class/file ownership and rejected-alternative text | incorporate | applied |
| C15 | Target score moves `85/88 -> 90/92`; support scores stay unchanged. | high | completed MCP/dependency/code pass; remaining name/reachability caveats | target metadata/Score/Changes; support headers | incorporate | applied |
| C16 | UID00006W child routing must produce declaration-before-method generated source. | very high | generated-output inspection after initial callback validators | class formal `[[CHILDREN]]`; layout position `1`; target position `20`; generated header/body | incorporate | applied |

## Positive Evidence Summary

- Direct facts: one complete prolog/body, receiver in `ECX`, object count/base/fallback accesses, two resource-name branches, ten calls including compiler cookie checks, two returns, and exact alignment.
- Resource facts: current bytes decode `ITEM.EPF` at `0x0061c288` and `ITEM.EPD` at `0x0061c29c`; target data xrefs occur at `0x004df6c2` and `0x004df760`.
- Dependency facts: both branches call the same EPFTileContext initializer, resource lookup, PaletteLib slot lookup, and pixel-range test in the same order.
- State facts: row stride is `0x14`; palette field is `+0x04`; output byte is `+0x10`; count and base are `this+0x08/+0x0c`; fallback is `this+0x14`.
- Strongest inference chain: receiver layout + ItemInfo stride + item archive names + adjacent ItemObj methods + current class/file route jointly outweigh absent caller evidence and establish ItemObjImageLib ownership/source placement.

## IDA MCP Facts

- `idb_list`: one active, non-analyzing NexusTK session, ID `359c7886`.
- `lookup_funcs`: `0x004df500` is `sub_4DF500` size `0x168`; target probes `0x004df670`, `0x004df690`, `0x004df730`, and `0x004df7d0` are not functions; successor `0x004df7e0` is `sub_4DF7E0` size `0x2c6`.
- `get_bytes`: eight `0xcc` bytes precede prolog `55 8b ec 83 ec 38`; target tail is `... 8b e5 5d c3`, followed by fourteen `0xcc` bytes.
- Bounded raw listing: 127 hits cover the entire target. Archive branch test is `cmp byte_66DA97, 1` at `0x004df68c`; EPF loop begins at `0x004df6b2`; EPD loop begins at `0x004df750`.
- Bounded call inventory: branch calls at `0x004df6b5/6c7/6ef/70c` and `0x004df753/765/78d/7aa`, plus security-cookie calls at `0x004df72b` and `0x004df7c9`.
- Write facts: `mov [ebx+10h], al` at `0x004df711` and `0x004df7af`.
- Xref facts: zero xrefs to start; two code xrefs to UID000201 at `0x004df70c` and `0x004df7aa`; item resource literals have target refs at `0x004df6c2` and `0x004df760` plus ItemObj draw/glyph-family refs.
- Pointer negative: no `70 F6 4D 00` VA bytes and no `70 F6 0D 00` RVA bytes found.
- Signature: `make_signature_for_range` reports the full target signature unique.
- Modeled dependency decompilation: UID000201 consumes palette `+0x04/+0x08` range data; UID0002KP returns a layout entry and fills/zeros EPFTileContext; `sub_543E40` implements slot/category palette resolution; `sub_457A60` initializes the `0x28`-byte context.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004df500-0x004df668` | UID0003LZ | modeled ItemInfo table reload helper | true | UID00006W | `85/90` | separate predecessor |
| `0x004df668-0x004df670` | by-memory ignored padding | alignment | false | none | `-1/-1` | eight `0xcc` bytes |
| `0x004df670-0x004df7d2` | UID0003ND | raw item frame availability refresh helper | true | UID00006W | `90/92` | exact target, first-draft emitted |
| `0x004df7d2-0x004df7e0` | by-memory ignored padding | alignment | false | none | `-1/-1` | fourteen `0xcc` bytes |
| `0x004df7e0-0x004dfaa6` | UID0002IU | LightObjImageLib constructor | true | UID000076 | existing | separate successor |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004df670` | zero direct xrefs; zero VA/RVA pointer hits | no proven live route; not ownership-negative enough to override body evidence |
| `0x004df6b5`, `0x004df753` | `EPFTileContext::Initialize` | creates per-row context in both branches |
| `0x004df6c7`, `0x004df765` | `ResourceLayoutTable::LookupLayoutEntry` | resolves row-index frame for selected item archive |
| `0x004df6ef`, `0x004df78d` | `PaletteLib::GetSlotPalette` | returns category-10 `DLPalette *` using row palette slot |
| `0x004df70c`, `0x004df7aa` | `EPFTileContext::ContainsIndexedPixelInRanges` | computes stored row flag |
| `0x004df6c2`, `0x004df760` | `ITEM.EPF` / `ITEM.EPD` literal refs | archive branch evidence |

## Documentation Evidence And IDA Status

- Same-or-greater support already present: UID000201 supplies exact `DLPalette *` parameter and inclusive pixel-range semantics; UID0002KP supplies formal resource lookup; EPFTileContext support supplies `Initialize`; PaletteLib support supplies `GetSlotPalette`; ProtectedArray support supplies `GetAtOrDefault`; ItemInfo supplies emitted fields.
- Stale/incomplete target claims: the target's `C++ reconstruction: intentionally blank` sentence and score rationale still describe names/dependencies as blockers. Those statements should be replaced, not preserved as current truth.
- Current generated state: valid routed code. Generated `NexusTK/render/ItemObjImageLib.cpp` header records validator command `000000008201` / `2026-07-12T16:19:21-04:00`; UID0001UU class declaration precedes UID0003ND method body, and the body matches the target formal block.

## Ranked Ownership Analysis

### 1. UID00006W ItemObjImageLib class

- Evidence for: `this+0x08/+0x0c/+0x14`, `0x14` `ItemInfo` rows, item resource names, row palette/filter fields, local ItemObj method neighborhood, established parent chain.
- Evidence against: no caller/start/pointer route and no original helper symbol.
- Decision: retain as direct owner/emitter. Body/state evidence is specific and stronger than absent reachability.

### 2. UID0000KH ItemObjImageLib.cpp file root

- Evidence for: owns class, singleton, item metadata, item resources, draw paths, glyph helper, and adjacent loader; valid generated root under `NexusTK/render/`.
- Evidence against: direct semantic owner is the class because the helper receives `this` and mutates embedded class storage.
- Decision: retain as source root through UID00006W, not direct canonical owner.

### 3. UID0000BY ResourceLayoutTable / UID00004I EPFTileContext / PaletteLib

- Evidence for: each supplies a called dependency.
- Evidence against: none owns the item row loop or output byte; dependencies are generic and widely used.
- Decision: reject ownership; preserve cross-references only.

### 4. UID000076 LightObjImageLib

- Evidence for: address adjacency to constructor at `0x004df7e0` only.
- Evidence against: target ends before that constructor and has no `LIGHT.TBL`, `LightInfo` stride, LightObj vtable/global, or light-frame behavior.
- Decision: reject.

### 5. No-owner/non-emitting or new free-helper file

- Evidence for: no live route and inferred name.
- Evidence against: receiver/class state and valid class/file emitter chain are direct; a new free helper would require exposing class internals or passing them artificially.
- Decision: reject. If forced to choose outside the class, UID0000KH file-local helper would be the least-bad fallback, but it is weaker than the class method route.

## Source Placement

- Recommended placement: private method declaration in `ItemObjImageLib` and method definition in `NexusTK/render/ItemObjImageLib.cpp` through UID00006W -> UID0000KH.
- This fits the translation unit's item metadata constructor/reloader, item archive draw/glyph functions, singleton, and `ItemInfo` type.
- Rejected placements: `ImageLib.cpp`/ResourceLayoutTable (generic lookup dependency), `PaletteLib.cpp` (palette dependency), `EPFTileContext.cpp` (generic pixel query dependency), `LightObjImageLib.cpp` (adjacency only), UI callers (consumer ownership), and a new standalone helper file (unnecessary class-state exposure).
- Remaining uncertainty: exact original header/private-section placement and exact method spelling are inferred. They do not affect the selected existing source root.

## Range / Split / Padding / Reclassification Analysis

- Exact target remains one half-open source range `0x004df670-0x004df7d2`.
- The branch-local returns at `0x004df733` and `0x004df7d1` are two exits from one prolog-selected helper, not two independent functions.
- The EPF and EPD loops should not be split into children; they share identical state and dependency semantics.
- Padding remains outside the target: eight bytes before and fourteen after.
- Reclassification is limited to source-readiness: retain `source-authored`, reconstructable, owner/emitter; change empty formal body to first-draft body.

## Negative Evidence Summary

- No IDA function object exists at target start or interior probes.
- No xref, VA pointer, RVA pointer, vtable entry, callback table entry, or known ordinary caller reaches the target start.
- No source symbol proves the helper or field spellings.
- No LightObj owner signal exists.
- No alternate row stride, mixed data, padding inside the target, nested function, exception funclet, destructor ABI sequence, or compiler-only reason exists.
- Resource/palette/global consumer relationships do not transfer ownership away from ItemObjImageLib.
- These negatives cap scores and require an inferred private-method label; they do not support leaving source-authored behavior unimplemented.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing/raw IDA name if a future separately authorized IDA edit pass allows function creation: `ItemObjImageLib::RefreshItemFrameAvailability` at `0x004df670-0x004df7d2`.
- Proposed prototype: `void __thiscall ItemObjImageLib::RefreshItemFrameAvailability(ItemObjImageLib *this);` in IDA representation; source declaration omits explicit `this`.
- Proposed comment: `Refreshes each ItemInfo palette-filter availability byte from ITEM.EPF/ITEM.EPD decoded pixels and the row's category-10 DLPalette.`
- Keep current support names `g_useEpfAssets`, `g_pEPFLib`, `g_pPaletteLib`, `paletteSlot`, and `allowPaletteFilter` in source-facing docs.
- Do not perform IDA DB edits in this callback/report lifecycle unless separately and explicitly authorized. No IDA mutation was made during this pass.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. Current target average already exceeds the active by-memory code gate, ownership/emitter routing is valid, and current evidence closes every behavior-affecting dependency.
- Exact formal target block implemented:

```cpp
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ItemObjImageLib::RefreshItemFrameAvailability()
{
    const wchar_t *resourceName = g_useEpfAssets ? L"ITEM.EPF" : L"ITEM.EPD";

    for (int itemIndex = 0; itemIndex < m_itemInfos.m_count; ++itemIndex) {
        EPFTileContext tileContext;
        tileContext.Initialize();

        if (g_pEPFLib->LookupLayoutEntry(resourceName, itemIndex, &tileContext) == 0)
            continue;

        DLPalette *palette = g_pPaletteLib->GetSlotPalette(
            10,
            m_itemInfos.GetAtOrDefault(itemIndex)->paletteSlot,
            0);

        m_itemInfos.GetAtOrDefault(itemIndex)->allowPaletteFilter =
            tileContext.ContainsIndexedPixelInRanges(palette);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Behavior preservation: the body does not write a row when resource lookup fails; it uses item index directly; calls `GetAtOrDefault` separately before and after the palette call like the two raw bounds-check sequences; passes category `10` and variant `0`; and stores the bool result at the accepted field.
- Source-shape rationale: a private `void` method, ordinary `for` loop, stack context, early `continue`, pointer local, and current class/container APIs are plausible late-1999 through mid-2000s C++. The resource-name conditional removes compiler-emitted/likely source-level branch duplication without altering observable semantics.
- Inferred names: method and `allowPaletteFilter` are descriptive; all other names are already accepted by current support docs.
- No-code proof: not applicable; the prior no-code proof is superseded.

## Final Recommendation

- Target applied: exact first-draft method body, score `85/88 -> 90/92`, emitter position `20`, current MCP/status/behavior/score evidence, and unchanged owner/emitter/reconstructable/range metadata.
- Class/layout/file applied: private method declaration, UID00006W `[[CHILDREN]]` routing marker, layout position `1`, source-ready method inventory, generated-output disposition, and unchanged support scores/path/ownership.
- ItemInfo applied: retained emitted layout and field spellings; added producer evidence that `allowPaletteFilter` is recomputed from decoded frame pixels by UID0003ND. No score change.
- EPFTileContext, UID000201, ResourceLayoutTable, PaletteLib, DLPalette, ProtectedArray, UID0003LZ: verified as already containing same-or-greater support detail; no edit made.
- No items remain no-owner/non-emitting. Raw reachability remains unknown and must be documented, not repaired by inventing a caller.
- Future work outside scope: an explicitly authorized IDA function-creation/rename pass could model the raw helper, but is not required for source emission.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability.md`.
- Applied the exact first-draft block above and emitter position `20`.
- Applied `COMPLETION:90` and `CONFIDENCE:92`; retained `CANONICAL_OWNER:00006W`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00006W`.
- Replaced blank-C++ status text with source-ready wording while retaining helper/field spellings as inferred confidence caveats.
- Added current MCP session `359c7886` evidence: exact listing/call/write facts, zero start xrefs, zero VA/RVA pointer hits, unique signature, and current dependency decompilations.
- Clarified that both archive branches use the same `g_pEPFLib` and `g_pPaletteLib`; only resource name differs.
- Preserved padding, no-function/no-caller negative evidence, LightObj rejection, UID000201 palette/range semantics, and direct class/file route.

## Recommended Support Doc Changes

- `by-type/by-struct/ItemObjImageLibLayout.md`: applied private declaration `void RefreshItemFrameAvailability();`, exact-child note, and emitter position `1`; kept `87/90`, owner/emitter, and formal layout route.
- `by-class/ItemObjImageLib.md`: applied source-ready method row/current-liveness note and added the required `[[CHILDREN]]` routing marker; kept `88/89` and existing owner/file route.
- `by-file/ItemObjImageLib.md`: applied filled-body/generated-output narrative; kept `90/88`, path, and grouping.
- `by-type/by-struct/ItemInfo.md`: applied producer semantics for `allowPaletteFilter`; declaration, score, owner, emitter, and field names unchanged.
- `by-memory/0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable.md`: verified no edit required; current adjacency/resource/row-layout evidence is already sufficient.
- UID000201, UID0002KP, EPFTileContext class/file/aggregate, PaletteLib/DLPalette/global, ProtectedArray/accessor: verified no edit required; current detail is already sufficient and remains referenced rather than duplicated.

## Score And Metadata Recommendation

- Historical target state before callback: `85/88`, owner/emitter `00006W`, reconstructable true, blank code.
- Implemented target state: `90/92`, owner/emitter and reconstructable unchanged, emitter position `20`, populated formal code.
- Completion `90`: exact raw range, padding, complete branch/loop/call/write behavior, fields, resources, owner/source placement, current negative reachability checks, dependency signatures, and first-draft C++ are all documented. Not higher because no modeled function/caller and exact source spelling remain unavailable.
- Confidence `92`: current MCP directly confirms every instruction-level behavior used by the draft, and accepted exact support docs close called API/type semantics. Not higher because original method/field spelling and live reachability are inferred/absent, and IDA cannot decompile the raw target itself.
- Score-improvement attempt: helper-name blocker was resolved to a defensible descriptive private name; field blocker was narrowed to a nonbehavioral spelling caveat; palette type blocker was resolved by UID000201; resource/context helper blockers were resolved by current exact support; range/split and owner/source placement were revalidated; raw reachability was exhaustively checked through xrefs and VA/RVA pointer bytes.
- Support score recommendation: no support score changes. This narrow method body does not complete the broader draw-method, original filename, class-field spelling, or whole-file audit burdens.

## Open Questions With Attempted Resolution

- Exact original method spelling: no symbol, function model, caller, pointer route, RTTI/vtable slot, or string exposes it. `RefreshItemFrameAvailability` is the best current descriptive name and is safe for first draft; original spelling remains unrecoverable from current evidence and caps confidence only.
- Exact `allowPaletteFilter` spelling: producer semantics could support `hasPaletteFilterPixels`, but current constructor/draw/type output consistently uses `allowPaletteFilter`. No symbol proves a better spelling, so a broad rename would add churn without evidence. Retain it as inferred.
- Why no caller exists: current xrefs and pointer scans exhaust ordinary direct/static routes available in the IDB. The binary body is retained source code but presently unreferenced/unmodeled. No caller should be invented; this does not block faithful reconstruction of the retained method.
- Why the binary duplicates loops: current listing proves duplication but not whether the source used explicit branches or compiler loop unswitching. The draft's selected resource name preserves all observed state and call semantics; exact branch source spelling is not behavior-critical.
- Whether palette can be null: current raw code performs no null check before UID000201, while `GetSlotPalette` decompilation returns a concrete slot or fallback palette. The draft intentionally preserves no-null-check behavior.
- No unresolved question materially blocks score improvement, ownership, source placement, split/range, or first-draft C++.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. No manual `-coverage-report.md` or supervisor-owned tracker text is required.
- Generated memory coverage/output refreshed through scoped validators. Report-coverage and execution/archive state remain external supervisor/validator-owned lifecycle data.

## Follow-Up Actions

- Follow-Up status: implementation callback complete; independent supervisor validation/execution/archive state is external and recorded by validator history; no pending lifecycle action is asserted.
- B005 callback work: complete; no implementation, lease, validator, or report-text item remains.
- No A-agent action is required.
- Optional later IDA action: create/type/name the raw function only under separate explicit authorization.

## Confidence

- Recommendation confidence: high.
- Score confidence: high within the sub-95 standard.
- Remaining uncertainty: exact original method/field spellings and the historical reason the method remains unreferenced. Neither affects the documented body or selected source route.

## Validator Results

- MCP results: active NexusTK IDB session `359c7886`; all bounded calls used in the evidence pass succeeded.
- Final scoped validator result per edited by-* file:

| File | Command ID | Timestamp | Exit / ok | Generated refresh | Target-specific result / diagnostics |
| --- | --- | --- | --- | --- | --- |
| target UID0003ND | `000000008200` | `2026-07-12T16:18:58-04:00` | `0 / 1` | completed | Registered emitter position `20`; retained five pre-existing missing-UID0003LZ diagnostics. |
| `ItemObjImageLibLayout.md` | `000000008201` | `2026-07-12T16:19:21-04:00` | `0 / 1` | completed | Registered emitter position `1`; generated output declaration now precedes UID0003ND body. |
| `ItemObjImageLib.md` class | `000000008199` | `2026-07-12T16:17:47-04:00` | `0 / 1` | completed | Registered `[[CHILDREN]]` route and updated generated `ItemObjImageLib.cpp`; retained four pre-existing missing-UID0003LZ diagnostics. |
| `ItemObjImageLib.md` file | `000000008197` | `2026-07-12T16:15:48-04:00` | `0 / 1` | completed | Support text registered; retained existing UID0003LZ/UID0003ZN diagnostics. |
| `ItemInfo.md` | `000000008198` | `2026-07-12T16:16:13-04:00` | `0 / 1` | completed | Producer support registered; unrelated stale missing UID0000Y4 registry row reported. |

- Earlier successful callback runs `000000008187`, `000000008190`, and `000000008195` validated the initial target/layout/class edits before the generated-routing/order repairs; final rows above supersede them for exact current artifacts.
- Generated freshness: `auto-generated/NexusTK/render/ItemObjImageLib.cpp` header is `validator-command-id: 000000008201`, `validator-refreshed-at: 2026-07-12T16:19:21-04:00`, equal to the latest scoped command and newer than every other callback validator. It contains UID0001UU declaration first, UID0003ND body second, and the expected class-routed UID0002VC/UID0001XW children.
- Validator-owned side effects included generated coverage/research-tracker/statistics/metadata refreshes and, during the ItemInfo scan, an unrelated generated `RankingDialog.cpp` update. No generated, registry, coverage, queue, lock, or lifecycle file was hand-edited.
- Unresolved diagnostics are unrelated validator-owned state: missing UID0003LZ/UID0003ZN references and stale missing UID0000Y4 file registration. They were not used to excuse target behavior and were not hand-repaired.

## Changed Files

- Report updated: `tools/leaser/Agents/Agent-B005/research/0003ND-ItemObjImageLibRefreshItemFrameAvailability-source-quality.md`.
- Modified by B005 under leases:
  - `by-memory/0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability.md`
  - `by-type/by-struct/ItemObjImageLibLayout.md`
  - `by-class/ItemObjImageLib.md`
  - `by-file/ItemObjImageLib.md`
  - `by-type/by-struct/ItemInfo.md`
- Renamed: none.
- Leases: target/layout batch acquired, validated, and released; class/file/ItemInfo batch acquired, validated, and released; class routing repair and target/layout ordering repair were each renewed only for their immediate edit/validator batch and released. No active B005 lease remains.
- Report execution: not run. No `execute_report`, registry lifecycle command, report move/archive, manual generated/coverage edit, or IDA mutation was performed by B005.

## Implementation Tracking Checklist

- [x] Historical supervisor Gate 1 acceptance recorded without asserting current external lifecycle state.
- [x] Target formal C++ inserted; score changed `85/88 -> 90/92`; owner/emitter/reconstructable/range retained; emitter position `20` applied.
- [x] Target MCP session `359c7886`, exact call/write/branch facts, no-function/no-xref/no-pointer evidence, unique signature, and dependency decompilations incorporated.
- [x] Stale no-code text replaced with source-ready disposition while inferred-name caveats remain explicit.
- [x] Claim And Incorporation Ledger rows C01-C16 carry `applied` or `already-present` states with path/section proof.
- [x] `ItemObjImageLibLayout.md` private declaration, UID0003ND cross-reference, and position `1` applied; score/owner/emitter retained.
- [x] `by-class/ItemObjImageLib.md` source-ready child/liveness note and required `[[CHILDREN]]` routing marker applied; score/route retained.
- [x] `by-file/ItemObjImageLib.md` filled-body/generated-output narrative applied; score/path/grouping retained.
- [x] `ItemInfo.md` producer semantics applied; field names/declaration/score/owner/emitter retained.
- [x] UID0003LZ, UID000201, UID0002KP, EPFTileContext, PaletteLib/DLPalette, and ProtectedArray support verified as already present at same-or-greater detail; no edit required.
- [x] Rejected alternatives preserved: LightObj owner, dependency-owner routes, no-owner/non-emitting, new free-helper file, target split, raw IDA name, and speculative field rename.
- [x] Negative evidence preserved: no function object, start xrefs, VA/RVA pointer route, vtable/callback route, or proven original symbol.
- [x] Split/rename/new-child and third-party import changes confirmed not applicable.
- [x] Scoped validators run for every edited by-* file with final command IDs/results recorded above.
- [x] Generated `ItemObjImageLib.cpp` verified at command `000000008201`: declaration precedes exact UID0003ND method body and header freshness equals latest validator metadata.
- [x] No manual coverage/tracker edit required; generated reports refreshed only by validator and lifecycle remains externally owned.
- [x] Every B005 lease released immediately after its edit/validator batch; no active B005 lease remains.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000008217","destination_path":"executed-b-agent-research/B005/0003ND-ItemObjImageLibRefreshItemFrameAvailability-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0003ND-ItemObjImageLibRefreshItemFrameAvailability-source-quality.md","timestamp":"2026-07-12T16:27:15-04:00","uid":"0003ND"} -->
<!-- {"agent":"B005","command_id":"000000008233","destination_path":"tools/leaser/Agents/Agent-B005/research/0003ND-ItemObjImageLibRefreshItemFrameAvailability-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B005/0003ND-ItemObjImageLibRefreshItemFrameAvailability-source-quality.md","timestamp":"2026-07-12T16:35:39-04:00","uid":"0003ND"} -->
<!-- {"agent":"B005","command_id":"000000008235","destination_path":"executed-b-agent-research/B005/0003ND-ItemObjImageLibRefreshItemFrameAvailability-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0003ND-ItemObjImageLibRefreshItemFrameAvailability-source-quality.md","timestamp":"2026-07-12T16:37:35-04:00","uid":"0003ND"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
