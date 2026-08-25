** TARGET-REPORT-UID:00025F **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00025F FrameGrafPortReadOnlyData Source Routing Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00025F] as a non-reconstructable, non-emitting physical `.rdata` index, but repair the remaining parent-only source cells instead of leaving them as vague boundary dwords.
- Final disposition: mixed source-owner container. No single canonical owner or emitter is valid for the whole range.
- Required action: on implementation callback, rename the aggregate to end at `0x0061aad0`, create one exact RectBounds constant child for `0x0061a880-0x0061a884`, widen the CachedHashTable vtable child to include `0x0061aac0`, and widen the successor HelpPanes read-only-data item to start at `0x0061aad0`.
- Score recommendation for [UID:00025F]: `83/93 -> 88/94` after the structural updates. If the implementation only edits prose and leaves the three boundary dwords parent-owned, cap completion at `85`.
- Owner/emitter/C++ recommendation: keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++ on [UID:00025F].
- Confidence: strong. Static exports, raw PE bytes, section mapping, vtable inventory, existing IDA-backed child docs, support docs, and negative pointer/address scans agree. Confidence stays below final-audit because live IDA MCP is not exposed in this session and the target remains a mixed physical container.

## Target

- Target UID: [UID:00025F]
- Current target path: `source-3/project-documentation/by-memory/0x0061a7dc-0x0061aad4.FrameGrafPortReadOnlyData.md`
- Recommended target path: `source-3/project-documentation/by-memory/0x0061a7dc-0x0061aad0.FrameGrafPortReadOnlyData.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B009/research/00025F-FrameGrafPortReadOnlyData-source-routing.md`
- Current metadata: `COMPLETION:83`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++.
- Current documented role: non-reconstructable physical `.rdata` aggregate whose exact children carry reconstructable source ownership.

## Executive Recommendation

The target is no longer a low-evidence broad `.rdata` bucket. Most source-bearing islands already have exact children and source routes:

- `0x0061a7dc-0x0061a7f8`: `FrameHandler` / `FrameMgr`, source route [UID:0000JM] `FrameMgr`.
- `0x0061a7f8-0x0061a880`: `FramePartPane`, source route [UID:00005I] `FramePartPane` / [UID:0000JL] `FrameChrome`.
- `0x0061a884-0x0061a8b8`: mixed panel/GrafPort vtable index, now split into exact class children for [UID:00005Q], [UID:00005R], and [UID:00005V].
- `0x0061a8b8-0x0061a920`: GrafPort `SurfaceDesc` diagnostic string, source route [UID:00005V] `GrafPort`.
- `0x0061a920-0x0061aac0`: software-render mask constants, source route [UID:0000OC] `Surface`.
- `0x0061aac4-0x0061aad0`: `CachedHashTable` vtable body, source route [UID:00001F] `CachedHashTable`.

The remaining issue is not ownership uncertainty for the whole range. The remaining issue is that three exact source cells are still stranded on the non-emitting aggregate:

- `0x0061a880`: exact `0.25f` / `0x3e800000` RectBounds quarter-scale float literal.
- `0x0061aac0`: exact `CachedHashTable` RTTI locator pointer immediately before the `CachedHashTable` vtable.
- `0x0061aad0`: exact `SimpleHelpTextPartPane<HelpPane>` RTTI locator pointer immediately before the successor HelpPanes vtable.

Recommended structural cleanup:

1. Create a new exact child `by-memory/0x0061a880-0x0061a884.RectBoundsQuarterScaleConstant.md`, reconstructable true, owner/emitter [UID:0000N2] `RectBounds`, score `86/92`, blank formal C++ unless the later RectBounds implementation wants a file-local `static const float` declaration.
2. Rename/widen [UID:0002M7] from `0x0061aac4-0x0061aad0.CachedHashTableVtableData.md` to `0x0061aac0-0x0061aad0.CachedHashTableVtableData.md`, keeping owner/emitter [UID:00001F] and raising to `87/92`.
3. Rename/widen [UID:00025G] from `0x0061aad4-0x0061b340.HelpItemHelpReadOnlyData.md` to `0x0061aad0-0x0061b340.HelpItemHelpReadOnlyData.md`, keeping owner/emitter [UID:0000JU] and raising to `89/92`.
4. Rename [UID:00025F] to `0x0061a7dc-0x0061aad0.FrameGrafPortReadOnlyData.md` and keep it non-reconstructable with no owner/emitter/C++. After steps 1-3, the aggregate is a clean index with no parent-only source-bearing dwords.

## Supervisor Active Recheck

- The supervisor assignment explicitly asked for a report-only B-agent pass. I did not edit target/support by-* docs and did not edit `by-memory/-coverage-report.md`.
- The assignment required review of mixed `.rdata` ownership, exact child coverage, the three remaining boundary dwords, source-owner split across FrameMgr/FrameChrome/GeneralPurposePanel/GrafPort/Surface/SoftwareBlend16/CachedHashTable/HelpPane, missing children, support-doc gaps, score cap, and no-code proof.
- I treated existing docs as leads. I rechecked them against static export data and raw PE bytes because no live IDA MCP resources are exposed in this session (`list_mcp_resources` returned no resources).
- Existing executed B reports were searched for this target and boundary dwords. No prior 00025F report exists. B002's executed `00016P-cached-hash-table-raw-helpers-source-quality.md` supports the CachedHashTable tail boundary facts and was used as a lead.

## Inference Research Guidance Check

- Source data from wave2/wave3 was not used as evidence. Generated/source-like output is treated only as route context where existing docs mention it.
- By-structure rules favor exact children when a broad memory range contains source-bearing subranges with different owners. This target is exactly that case.
- The correct result is not to assign [UID:00025F] to the largest source consumer. A single owner would be false because the range crosses frame scheduler vtables, frame chrome vtables, UI panel vtables, GrafPort vtable/string data, software renderer constants, a container utility vtable, and HelpPanes RTTI.
- Current 85/85 gate analysis supports owner/emitter routes for exact reconstructable children, not for this aggregate. The aggregate itself is `RECONSTRUCTABLE:FALSE`.

## Evidence Standards Used

Evidence checked:

- Target and child by-memory docs:
  - [UID:00025F] `0x0061a7dc-0x0061aad4.FrameGrafPortReadOnlyData.md`
  - [UID:0002V3] `0x0061a7dc-0x0061a7f8.FrameHandlerFrameMgrVtableData.md`
  - [UID:0002NH] `0x0061a7f8-0x0061a880.FramePartPaneVtableData.md`
  - [UID:0002V4] `0x0061a884-0x0061a8b8.PanelGrafPortVtableData.md`
  - [UID:0003BC] `0x0061a884-0x0061a894.GeneralPurposePanelVtableData.md`
  - [UID:0003BD] `0x0061a894-0x0061a8a4.GeneralPurposePanel2VtableData.md`
  - [UID:0003BE] `0x0061a8a4-0x0061a8b8.GrafPortVtableData.md`
  - [UID:0002V5] `0x0061a8b8-0x0061a920.GrafPortSurfaceDescStringData.md`
  - [UID:0002V6] `0x0061a920-0x0061aac0.SoftwareRenderMaskConstants.md`
  - [UID:0002M7] `0x0061aac4-0x0061aad0.CachedHashTableVtableData.md`
  - [UID:00025G] `0x0061aad4-0x0061b340.HelpItemHelpReadOnlyData.md`
- Support docs:
  - [UID:0000JM] `by-file/FrameMgr.md`
  - [UID:0000JL] `by-file/FrameChrome.md`
  - [UID:0000JQ] `by-file/GeneralPurposePanel.md`
  - [UID:0000JR] `by-file/GrafPort.md`
  - [UID:0000OC] `by-file/Surface.md`
  - [UID:0000NT] `by-file/SoftwareBlend16.md`
  - [UID:0000HZ] `by-file/CachedHashTable.md`
  - [UID:0000JU] `by-file/HelpPanes.md`
  - [UID:0000N2] `by-file/RectBounds.md`
  - [UID:00022H] `0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md`
  - [UID:0003I3] `by-type/by-vtable/FramePartPaneVtables.md`
- Static export data:
  - `resources/exported_data/master_names.json`
  - `resources/exported_data/master_globals.json`
  - `resources/exported_data/master_vtables.json`
- Local PE bytes:
  - `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
  - Image base `0x00400000`.
  - `.rdata` maps at VA `0x0060d000`, raw `0x0020ba00`, raw size `0x5f200`.
- Generated coverage as read-only state:
  - `auto-generated/-ag-memory-coverage.md`
  - `by-memory/-coverage-report.md` current rows; no edit performed.
- Negative evidence:
  - No live MCP resources exposed in this session.
  - PE address scans for the boundary cells found no code references to `0x0061aac0` or `0x0061aad0` as addresses.
  - `0x00647de8` and `0x00647eb8` pointed-to RTTI values occur exactly once each in the PE, at `0x0061aac0` and `0x0061aad0`.

## Raw PE And Export Facts

### Section And Raw Offset Facts

| VA | Section | Raw offset | Bytes |
| --- | --- | ---: | --- |
| `0x0061a7dc` | `.rdata` | `0x002191dc` | `28 7b 64 00 50 6d 4b 00 8c a2 5c 00 70 7b 64 00` |
| `0x0061a7f8` | `.rdata` | `0x002191f8` | `10 7c 64 00 b0 75 4b 00 10 4b 4f 00 b0 73 4b 00` |
| `0x0061a880` | `.rdata` | `0x00219280` | `00 00 80 3e 94 7c 64 00 40 8b 4b 00 10 4b 4f 00` |
| `0x0061a884` | `.rdata` | `0x00219284` | `94 7c 64 00 40 8b 4b 00 10 4b 4f 00 c0 b6 41 00` |
| `0x0061a8b8` | `.rdata` | `0x002192b8` | `73 00 75 00 72 00 66 00 61 00 63 00 65 00 44 00` |
| `0x0061a920` | `.rdata` | `0x00219320` | `e0 03 00 00 e0 03 00 00 e0 03 00 00 e0 03 00 00` |
| `0x0061aac0` | `.rdata` | `0x002194c0` | `e8 7d 64 00 f0 64 4c 00 10 4b 4f 00 c0 b6 41 00` |
| `0x0061aac4` | `.rdata` | `0x002194c4` | `f0 64 4c 00 10 4b 4f 00 c0 b6 41 00 b8 7e 64 00` |
| `0x0061aad0` | `.rdata` | `0x002194d0` | `b8 7e 64 00 20 e6 4c 00 10 4b 4f 00 c0 b6 41 00` |
| `0x0061aad4` | `.rdata` | `0x002194d4` | `20 e6 4c 00 10 4b 4f 00 c0 b6 41 00 20 8e 4b 00` |

### Dword Inventory

| Address | Value | Best interpretation |
| --- | ---: | --- |
| `0x0061a7dc` | `0x00647b28` | `??_R4FrameHandler@@6B@` RTTI locator pointer. |
| `0x0061a7e0` | `0x004b6d50` | `FrameHandler` vtable slot 0. |
| `0x0061a7e8` | `0x00647b70` | `??_R4FrameMgr@@6B@` RTTI locator pointer. |
| `0x0061a7ec` | `0x004b70c0` | `FrameMgr` vtable slot 0. |
| `0x0061a7f8` | `0x00647c10` | `??_R4FramePartPane@@6B@` RTTI locator pointer. |
| `0x0061a880` | `0x3e800000` | `0.25f` RectBounds quarter-scale literal. |
| `0x0061a884` | `0x00647c94` | `??_R4GeneralPurposePanel@@6B@` RTTI locator pointer. |
| `0x0061a888` | `0x004b8b40` | `GeneralPurposePanel` scalar deleting destructor slot. |
| `0x0061a894` | `0x00647d34` | `??_R4GeneralPurposePanel2@@6B@` RTTI locator pointer. |
| `0x0061a898` | `0x004b8aa0` | `GeneralPurposePanel2` scalar deleting destructor slot. |
| `0x0061a8a4` | `0x00647dd4` | `??_R4GrafPort@@6B@` RTTI locator pointer. |
| `0x0061a8a8` | `0x004bb7e0` | `GrafPort` scalar deleting destructor slot. |
| `0x0061a8b4` | `0x004b8e20` | `GrafPort::UpdateRenderRegion` virtual slot. |
| `0x0061a8b8` | `0x00750073` | Start of UTF-16 `surfaceDesc...` string. |
| `0x0061a920` | `0x000003e0` | First software-render mask constant. |
| `0x0061aac0` | `0x00647de8` | `??_R4CachedHashTable@@6B@` RTTI locator pointer. |
| `0x0061aac4` | `0x004c64f0` | `CachedHashTable` scalar deleting destructor slot. |
| `0x0061aad0` | `0x00647eb8` | `??_R4SimpleHelpTextPartPane@HelpPane@@6B@` RTTI locator pointer. |
| `0x0061aad4` | `0x004ce620` | `SimpleHelpTextPartPane<HelpPane>` scalar deleting destructor slot. |

### Vtable Export Facts

`master_vtables.json` reports these vtables in the target range:

- `0x0061a7e0`: `FrameHandler`, 2 entries.
- `0x0061a7ec`: `FrameMgr`, 3 entries.
- `0x0061a7fc`: `FramePartPane`, 18 entries.
- `0x0061a848`: `FramePartPane` secondary view, 11 entries.
- `0x0061a878`: `FramePartPane` tertiary view, 2 entries.
- `0x0061a888`: `GeneralPurposePanel`, 3 entries.
- `0x0061a898`: `GeneralPurposePanel2`, 3 entries.
- `0x0061a8a8`: `GrafPort`, 4 entries.
- `0x0061aac4`: `CachedHashTable`, 3 entries.

The export does not list `0x0061aad4` in this target range because that is the first vtable base of the successor HelpPanes item. Raw bytes and existing HelpPanes docs confirm it starts immediately after the `0x0061aad0` RTTI locator.

### Boundary Dword Recheck

`0x0061a880`:

- Raw value: `00 00 80 3e`, little-endian `0x3e800000`, `0.25f`.
- PE address-reference scan for immediate address `0x0061a880` found exactly two `.text` hits: instruction displacements inside `0x004b7af0-0x004b7b88`.
- Capstone disassembly:
  - `0x004b7b15: mulss xmm4, dword ptr [0x61a880]`
  - `0x004b7b43: mulss xmm1, dword ptr [0x61a880]`
- The two use sites are the first raw RectBounds quarter-scale helper. The sibling helper at `0x004b7b90-0x004b7c21` uses `0x006104b0` / `0.5f` in a different way and does not reference `0x0061a880`.
- Rejected owners: FramePartPane, GeneralPurposePanel, GrafPort, and the broad [UID:00025F] aggregate. Physical adjacency to frame/panel vtable data is not source ownership; the only address refs tie the dword to RectBounds helper code.

`0x0061aac0`:

- Raw value: `e8 7d 64 00`, pointer `0x00647de8`.
- `master_names.json` names `0x00647de8` as `??_R4CachedHashTable@@6B@`.
- `master_globals.json` identifies `0x00647de8` as an RTTI complete-object-locator object.
- PE scan for address `0x0061aac0` found no direct hits.
- PE scan for pointed value `0x00647de8` found exactly one hit, at `0x0061aac0`.
- The adjacent vtable base `0x0061aac4` has immediate references from `0x004c61a1`, `0x004c6288`, and `0x004c651f` in CachedHashTable lifecycle code.
- Best structural action: include `0x0061aac0` in [UID:0002M7] instead of leaving it on the aggregate.

`0x0061aad0`:

- Raw value: `b8 7e 64 00`, pointer `0x00647eb8`.
- `master_names.json` names `0x00647eb8` as `??_R4SimpleHelpTextPartPane@HelpPane@@6B@`.
- `master_globals.json` identifies `0x00647eb8` as an RTTI complete-object-locator object.
- PE scan for address `0x0061aad0` found no direct hits.
- PE scan for pointed value `0x00647eb8` found exactly one hit, at `0x0061aad0`.
- The successor vtable base `0x0061aad4` has immediate references from `0x004c65dd` and `0x004c69f7` inside HelpPane / embedded text-part construction code.
- Best structural action: include `0x0061aad0` in successor [UID:00025G] instead of keeping it as the final dword of [UID:00025F].

## Function / Child Inventory

| Range / Item | Current UID / Path | Current role | Recommended role | Reconstructable | Direct owner/emitter | Score direction |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0061a7dc-0x0061a7f8` | [UID:0002V3] `FrameHandlerFrameMgrVtableData` | exact child | unchanged | TRUE | [UID:0000JM] | keep `87/93` |
| `0x0061a7f8-0x0061a880` | [UID:0002NH] `FramePartPaneVtableData` | exact child | unchanged | TRUE | [UID:00005I] | keep `89/93` |
| `0x0061a880-0x0061a884` | none | parent-only boundary dword | create `RectBoundsQuarterScaleConstant` child | TRUE | [UID:0000N2] | new `86/92` |
| `0x0061a884-0x0061a8b8` | [UID:0002V4] `PanelGrafPortVtableData` | mixed index | unchanged non-emitting index over exact children | FALSE | NONE | keep `88/93` |
| `0x0061a884-0x0061a894` | [UID:0003BC] `GeneralPurposePanelVtableData` | exact child | ensure coverage row exists | TRUE | [UID:00005Q] | keep `86/92` |
| `0x0061a894-0x0061a8a4` | [UID:0003BD] `GeneralPurposePanel2VtableData` | exact child | ensure coverage row exists | TRUE | [UID:00005R] | keep `86/93` |
| `0x0061a8a4-0x0061a8b8` | [UID:0003BE] `GrafPortVtableData` | exact child | ensure coverage row exists | TRUE | [UID:00005V] | keep `87/93` |
| `0x0061a8b8-0x0061a920` | [UID:0002V5] `GrafPortSurfaceDescStringData` | exact child | unchanged | TRUE | [UID:00005V] | keep `89/93` |
| `0x0061a920-0x0061aac0` | [UID:0002V6] `SoftwareRenderMaskConstants` | exact child | unchanged | TRUE | [UID:0000OC] | keep `86/91` |
| `0x0061aac0-0x0061aad0` | [UID:0002M7] currently starts at `0x0061aac4` | missing RTTI dword plus exact child | widen to include `0x0061aac0` | TRUE | [UID:00001F] | raise `86/91 -> 87/92` |
| `0x0061aad0-0x0061b340` | [UID:00025G] currently starts at `0x0061aad4` | successor starts after its RTTI | widen successor to include `0x0061aad0` | TRUE | [UID:0000JU] | raise `88/91 -> 89/92` |
| `0x0061a7dc-0x0061aad0` | [UID:00025F] | broad parent | non-emitting index after repairs | FALSE | NONE | raise `83/93 -> 88/94` |

## Direct Xref / Reference Inventory

| Address / item | Direct evidence | Meaning |
| --- | --- | --- |
| `0x004b7b15` | `mulss xmm4, dword ptr [0x61a880]` | First RectBounds quarter-scale helper uses the `0.25f` literal. |
| `0x004b7b43` | `mulss xmm1, dword ptr [0x61a880]` | Same helper's second axis uses the `0.25f` literal. |
| `0x004c61a1` | `mov dword ptr [esi], 0x61aac4` | CachedHashTable constructor installs vtable. |
| `0x004c6288` | `mov dword ptr [esi], 0x61aac4` | CachedHashTable destructor restores vtable. |
| `0x004c651f` | `mov dword ptr [esi], 0x61aac4` | CachedHashTable scalar deleting destructor restores vtable. |
| `0x004c65dd` | `mov dword ptr [esi], 0x61aad4` | HelpPane text-part constructor installs primary vtable. |
| `0x004c65e3` | `mov dword ptr [esi + 0xa0], 0x61ab20` | Same constructor installs secondary vtable. |
| `0x004c65ed` | `mov dword ptr [esi + 0xa4], 0x61ab50` | Same constructor installs tertiary vtable. |
| `0x004c69f7` | `mov dword ptr [edi], 0x61aad4` | `HelpPane` constructor installs embedded text-part primary vtable. |
| `0x004c69fd` | `mov dword ptr [edi + 0xa0], 0x61ab20` | Same embedded text part secondary vtable. |

## Documentation Evidence And Status

### Existing Docs That Are Supported

- [UID:00025F] is correctly marked `RECONSTRUCTABLE:FALSE` and no-owner/non-emitting.
- [UID:0002V3] correctly includes `0x0061a7dc` as the `FrameHandler` RTTI locator and routes the compact scheduler vtables to [UID:0000JM].
- [UID:0002NH] correctly stops at `0x0061a880`; its successor note that `0x0061a880` is not a `FramePartPane` vtable cell is correct.
- [UID:0002V4] is correctly non-reconstructable as a mixed panel/GrafPort vtable index, with exact children [UID:0003BC], [UID:0003BD], and [UID:0003BE].
- [UID:0002V5] correctly routes the `SurfaceDesc` UTF-16 literal to [UID:00005V] `GrafPort`.
- [UID:0002V6] correctly routes software-render mask constants to [UID:0000OC] `Surface` rather than to `GrafPort` or `SoftwareBlend16` alone.
- [UID:0002M7] correctly identifies the three-slot CachedHashTable vtable and lifecycle refs.
- [UID:00025G] correctly identifies `0x0061aad4` as the HelpPanes vtable start and `0x0061aad0` as its predecessor RTTI locator.
- [UID:00022H] correctly ties `dword_61A880` to RectBounds quarter-scale helpers.

### Existing Docs That Need Correction Or Completion

- [UID:00025F] should not say the parent "owns" `0x0061a880`, `0x0061aac0`, and `0x0061aad0` except as a temporary historical state. Those cells have source routes.
- [UID:00025F] should end at `0x0061aad0` after [UID:00025G] widens to include its RTTI locator.
- [UID:0002M7] should include `0x0061aac0`, matching the project pattern where exact vtable-data children include the RTTI/complete-object-locator pointer immediately before the vtable base.
- [UID:00025G] should include `0x0061aad0` for the same reason.
- [UID:00022H] and [UID:0000N2] should link to a new exact `RectBoundsQuarterScaleConstant` data child for `0x0061a880-0x0061a884`.
- `by-memory/-coverage-report.md` is stale for [UID:00025F], [UID:0002V3], [UID:0002NH], [UID:0002V4], [UID:0002V5], [UID:0002V6], [UID:0002M7], [UID:00025G], and [UID:00022H]. It also appears to lack the current exact [UID:0003BC]/[UID:0003BD]/[UID:0003BE] child rows under [UID:0002V4].

## Heuristic / Inference Reanalysis And Validation

### Issue: Should [UID:00025F] Remain No-Owner / Non-Emitting?

- Best inference: yes. [UID:00025F] is a physical linker-layout index, not a source unit.
- Evidence: range crosses unrelated source families with exact children and independent source routes. There is no one class, file, type, or global declaration that can semantically own all data from `FrameHandler` through `CachedHashTable`.
- Rejected alternative, [UID:0000JM] `FrameMgr`: only covers the first compact vtable pair.
- Rejected alternative, [UID:0000JL] `FrameChrome`: covers `FramePartPane`, not GeneralPurposePanel/GrafPort/Surface/CachedHashTable.
- Rejected alternative, [UID:0000JR] `GrafPort`: covers the GrafPort vtable and diagnostic string, not frame scheduler, panel, Surface constants, or CachedHashTable.
- Rejected alternative, [UID:0000OC] `Surface`: covers software-render constants, not vtables/literals before and after.
- Rejected alternative, [UID:0000JU] `HelpPanes`: starts at the successor RTTI/vtable boundary only.
- Score impact: owner/emitter must stay blank. The page can still increase in completion because it is a well-audited index.

### Issue: Meaning And Ownership Of `0x0061a880`

- Best descriptive name: `RectBoundsQuarterScaleConstant` for the by-memory child, and `kRectBoundsQuarterScale` or `flt_RectBoundsQuarterScale` as an IDA/source-facing label.
- Evidence: exact `0.25f` value, exactly two address refs to `0x0061a880`, both from the first RectBounds quarter-scale raw helper at `0x004b7af0-0x004b7b88`.
- Existing `RectBoundsQuarterScaleHelpers.md` already documents the helper behavior and `dword_61A880 == 0.25f`.
- Rejected alternatives:
  - FramePartPane tail: rejected because the previous vtable child ends before it and no FramePartPane code references the dword.
  - GeneralPurposePanel predecessor: rejected because the next RTTI starts at `0x0061a884` and panel lifecycle refs target vtable base `0x0061a888`, not the dword.
  - GrafPort/render constant: rejected because no GrafPort/render code references this address; it is a RectBounds helper literal.
  - Leave only on parent: weak. The parent is non-reconstructable, but this dword is source-generated by RectBounds helper code and can route through [UID:0000N2].
- Recommended child C++ policy: the exact child documents data generation. Formal child C++ can stay blank if the RectBounds helper C++ uses `0.25f` literals; if an emitted marker is required, use a descriptive file-local constant in `RectBounds.cpp`, not the broad [UID:00025F] parent.

### Issue: Meaning And Boundary Policy For `0x0061aac0`

- Best direction: widen [UID:0002M7] to start at `0x0061aac0`.
- Evidence: `0x0061aac0 -> 0x00647de8`, `??_R4CachedHashTable@@6B@`, uniquely referenced by that dword; vtable base `0x0061aac4` is referenced by only CachedHashTable lifecycle paths.
- Rejected alternatives:
  - Standalone child for `0x0061aac0`: possible but inferior. It is the RTTI locator pointer immediately before the CachedHashTable vtable; project pattern usually groups that with the vtable data.
  - Leave on parent: weak and inconsistent with nearby vtable child pattern.
  - Merge into software-render constants: rejected because `0x0061a920-0x0061aac0` ends exactly before the RTTI locator and is semantically Surface/render data.

### Issue: Meaning And Boundary Policy For `0x0061aad0`

- Best direction: widen [UID:00025G] to start at `0x0061aad0`.
- Evidence: `0x0061aad0 -> 0x00647eb8`, `??_R4SimpleHelpTextPartPane@HelpPane@@6B@`, uniquely referenced by that dword; successor vtable base `0x0061aad4` has constructor refs inside HelpPanes code at `0x004c65dd` and `0x004c69f7`.
- Rejected alternatives:
  - Standalone child for `0x0061aad0`: possible but inferior for the same vtable-pattern reason.
  - Leave as a successor-boundary row in [UID:00025F]: acceptable only as a temporary audit state; final structure should include the RTTI locator with its vtable island.
  - Keep [UID:00025F] end at `0x0061aad4`: rejected after widening [UID:00025G], because it would overlap the successor RTTI locator.

### Issue: Surface Versus SoftwareBlend16 For `0x0061a920-0x0061aac0`

- Best direction: keep [UID:0002V6] assigned to [UID:0000OC] `Surface` with [UID:0000NT] `SoftwareBlend16` as related math context.
- Evidence: child docs and Surface support docs tie direct consumers to software-render callback families selected by Surface/render dispatch. `SoftwareBlend16` owns stateless pixel/span/block math helpers but not the broad callback-local SIMD mask table.
- Rejected alternative, `GrafPort`: physical adjacency and the preceding string do not overcome direct callback-family refs.
- Rejected alternative, `SoftwareBlend16` direct parent: plausible related module, but current project docs explicitly scope `SoftwareBlend16` to stateless blend/math helpers, while the mask table is consumed by Surface callback implementations.

### Issue: Panel/GrafPort Mixed Index

- Best direction: keep [UID:0002V4] non-reconstructable and no-owner, with exact children [UID:0003BC]/[UID:0003BD]/[UID:0003BE] carrying class ownership.
- Evidence: [UID:0002V4] spans three classes and two source files. Its exact child pages already resolve vtable stores and parent gates.
- Rejected alternative, assign [UID:0002V4] to `GeneralPurposePanel` or `GrafPort`: false for the other subrange.
- Coverage gap: the shared coverage report should include current rows for the exact child pages.

### Issue: Parent No-Code Proof

- [UID:00025F] should not emit C++ because it is a mixed physical index over source-declared/generated-binary data from unrelated source families.
- The source-bearing pieces are regenerated by:
  - class declarations and virtual destructors/methods for vtable data,
  - source string literals for `GrafPort` diagnostics,
  - Surface/render callback constants for software masks,
  - RectBounds helper literals for `0x0061a880`,
  - HelpPanes class declarations for the successor RTTI/vtable.
- Hand-porting the parent as a byte array or a single global would be generated-output pollution and would duplicate exact children.
- Formal parent C++ must remain blank.

## Ranked Ownership Analysis

### 1. No Canonical Owner / No Emitter For [UID:00025F]

- Evidence for: source families are mixed and exact children own source-bearing pieces. The parent is only a physical linker-order range map.
- Evidence against: none for whole-range source ownership. It contains reconstructable subdata, but not as one source unit.
- Decision: accepted. Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`.

### 2. [UID:0000N2] RectBounds For `0x0061a880`

- Evidence for: exact address refs from `RectBoundsQuarterScaleHelpers`; helper and file pages clear the gate; value is semantically a rectangle quarter-scale literal.
- Evidence against: raw helper liveness still has no direct callers, which caps child confidence below final-audit.
- Decision: accepted for new exact one-dword child.

### 3. [UID:00001F] CachedHashTable For `0x0061aac0-0x0061aad0`

- Evidence for: RTTI locator, vtable slots, lifecycle vtable refs, class/file support docs, and B002 cached-hash-table report all agree.
- Evidence against: active construction remains unresolved on broader CachedHashTable docs.
- Decision: accepted. Widen [UID:0002M7] to include the RTTI locator.

### 4. [UID:0000JU] HelpPanes For `0x0061aad0` And Successor

- Evidence for: `0x0061aad0` points to `SimpleHelpTextPartPane<HelpPane>` RTTI; vtable base `0x0061aad4` refs are in HelpPanes constructor paths; [UID:00025G] and HelpPanes file docs already clear the parent gate.
- Evidence against: eventual split among `HelpPanes.cpp`, `ItemHelpPane.cpp`, and `WillBeChangedPanes.cpp` remains possible.
- Decision: accepted for current source-family route. Widen [UID:00025G] start.

### 5. Other Whole-Range Owners

- FrameMgr, FrameChrome, GeneralPurposePanel, GrafPort, Surface, SoftwareBlend16, CachedHashTable, and HelpPanes all own specific subranges or dependencies.
- None is valid for [UID:00025F] as a whole.

## Negative Evidence Summary

- No live MCP resources are exposed in this session, so I did not claim new live IDA facts. Prior IDA-backed docs are labeled as documentation evidence and cross-checked where possible.
- PE scans found no direct address refs to `0x0061aac0` or `0x0061aad0`; this is expected for RTTI locator cells and supports treating them as vtable-adjacent data rather than active constants.
- PE scans found direct address refs to `0x0061a880` only in RectBounds helper code, not in frame/panel/GrafPort code.
- No target RVA/raw-offset hits were needed to prove the `.rdata` boundaries; section mapping gives exact raw offsets and dwords.
- Consumer/adjacency evidence was rejected when it conflicted with direct refs. Example: `0x0061a880` sits between FramePartPane and GeneralPurposePanel data, but its only address refs are from RectBounds.

## Score And Metadata Recommendation

### [UID:00025F] Target

Recommended after implementation:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rationale:

- Completion rises because all child islands and formerly parent-only source cells have exact routes after the recommended split/widening.
- Confidence rises only slightly because existing docs were already strong; raw PE now independently rechecks dwords, names, raw offsets, and direct/negative refs.
- Completion should not go above the high 80s because [UID:00025F] is a documentation index, not a final source item, and live IDA MCP was unavailable.
- Confidence should remain below `95` because the parent is a mixed range and exact original source-file splits for some support families still have caveats.

### Child/Support Score Recommendations

- New `RectBoundsQuarterScaleConstant`: `86/92`, `CANONICAL_OWNER:0000N2`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N2`.
- [UID:0002M7] after widening to `0x0061aac0-0x0061aad0`: `87/92`, owner/emitter unchanged [UID:00001F].
- [UID:00025G] after widening to `0x0061aad0-0x0061b340`: `89/92`, owner/emitter unchanged [UID:0000JU].
- [UID:0002V4] remains `88/93`, non-reconstructable index.
- [UID:0003BC]/[UID:0003BD]/[UID:0003BE], [UID:0002V5], [UID:0002V6], [UID:0002V3], and [UID:0002NH] do not need score changes from this report, but their coverage rows should be brought current.

## Exact Future Implementation Checklist

Report-only now. If accepted, the implementation callback should:

1. Lease all existing target/support docs before editing. Do not edit `by-memory/-coverage-report.md`.
2. Rename/update [UID:00025F]:
   - From `by-memory/0x0061a7dc-0x0061aad4.FrameGrafPortReadOnlyData.md`
   - To `by-memory/0x0061a7dc-0x0061aad0.FrameGrafPortReadOnlyData.md`
   - Set `COMPLETION:88`, `CONFIDENCE:94`, keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++.
   - Replace "parent still owns boundary dwords" wording with "historically parent-owned; now delegated to exact children/successor."
   - Update observed-contents table to include all exact children, including new RectBounds constant and widened CachedHashTable child, and to stop before the HelpPanes RTTI locator.
3. Create new child:
   - `by-memory/0x0061a880-0x0061a884.RectBoundsQuarterScaleConstant.md`
   - Metadata: new validator-assigned UID, `COMPLETION:86`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000N2`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N2`.
   - Summary: one-dword `0.25f` constant used by `RectBoundsQuarterScaleHelpers`, with exact refs `0x004b7b15` and `0x004b7b43`.
   - C++ policy: do not hand-port bytes. It should regenerate from RectBounds helper literals or a file-local RectBounds constant.
4. Rename/widen [UID:0002M7]:
   - From `by-memory/0x0061aac4-0x0061aad0.CachedHashTableVtableData.md`
   - To `by-memory/0x0061aac0-0x0061aad0.CachedHashTableVtableData.md`
   - Set `COMPLETION:87`, `CONFIDENCE:92`.
   - Add `0x0061aac0 -> ??_R4CachedHashTable@@6B@`, raw bytes, unique pointed-value scan, no address refs, and vtable-base lifecycle refs.
5. Rename/widen [UID:00025G]:
   - From `by-memory/0x0061aad4-0x0061b340.HelpItemHelpReadOnlyData.md`
   - To `by-memory/0x0061aad0-0x0061b340.HelpItemHelpReadOnlyData.md`
   - Set `COMPLETION:89`, `CONFIDENCE:92`.
   - Add `0x0061aad0 -> ??_R4SimpleHelpTextPartPane@HelpPane@@6B@`, unique pointed-value scan, and successor vtable refs.
6. Update support docs:
   - [UID:00022H] `RectBoundsQuarterScaleHelpers`: link the new constant child and replace unresolved `dword_61A880` wording with `RectBoundsQuarterScaleConstant` / `kRectBoundsQuarterScale`.
   - [UID:0000N2] `RectBounds`: add the one-dword constant child to proposed contents and evidence.
   - [UID:0003I3] `FramePartPaneVtables`: keep successor boundary note but link `0x0061a880` to the RectBounds constant child, not an unresolved dword.
   - [UID:0002NH] `FramePartPaneVtableData`: update the boundary note to link the RectBounds child.
   - [UID:0002V4] `PanelGrafPortVtableData`: predecessor note should mention the RectBounds constant child.
   - [UID:0002V6] `SoftwareRenderMaskConstants`: successor boundary should link widened [UID:0002M7] at `0x0061aac0`.
   - [UID:00001F] `CachedHashTable`, [UID:0000HZ] `CachedHashTable`, [UID:0001X6] `CachedHashTableVtable`: update vtable-data child path/range to `0x0061aac0-0x0061aad0`.
   - [UID:0000JU] `HelpPanes` and [UID:00025G] cross-links: update successor/predecessor boundary and range start to include `0x0061aad0`.
7. Preserve historical assumptions in [UID:00025F] Changes or a "Historical stale state" note:
   - Previous docs treated `0x0061a880`, `0x0061aac0`, and `0x0061aad0` as parent-owned boundary dwords.
   - Current evidence routes them to RectBounds, CachedHashTable, and HelpPanes respectively.
8. Run validators only after implementation edits, scoped to edited files. Recommended commands are listed below.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` as B009. The supervisor owns applying these rows.

Important: the new `RectBoundsQuarterScaleConstant` child needs a real UID assigned by validator during implementation. The exact row text below uses `<NEW_UID_RECT_QUARTER>` as the only placeholder; replace it with the actual UID after creation.

Placement context: replace the current [UID:00025F] block and affected nested rows around the `0x0061a7dc` neighborhood. Also replace the current [UID:00025G] row immediately after this block and update the [UID:00022H] row in its existing `0x004b7af0` location.

```text
    - [UID:00025F][0x0061a7dc-0x0061aad0.FrameGrafPortReadOnlyData](by-memory/0x0061a7dc-0x0061aad0.FrameGrafPortReadOnlyData.md) 0x0061a7dc-0x0061aad0 | vtable/table-data index | FrameGrafPortReadOnlyData : not_reconstructable : 88% : very strong : B009 2026-06-19 source-routing recheck converts this to a non-emitting physical `.rdata` index with no canonical owner: exact children cover FrameHandler/FrameMgr, FramePartPane, RectBounds quarter-scale constant, panel/GrafPort vtables, GrafPort diagnostic string, Surface software-render constants, and CachedHashTable vtable data; the successor HelpPanes RTTI locator is moved to [UID:00025G] at `0x0061aad0`. Parent formal C++ stays blank because source-bearing data is regenerated by the exact children/source declarations, not by hand-porting the aggregate bytes.
        - [UID:0002V3][0x0061a7dc-0x0061a7f8.FrameHandlerFrameMgrVtableData](by-memory/0x0061a7dc-0x0061a7f8.FrameHandlerFrameMgrVtableData.md) 0x0061a7dc-0x0061a7f8 | vtable-data | FrameHandlerFrameMgrVtableData : reconstructable : 87% : very strong : Exact FrameHandler/FrameMgr RTTI/vtable child routed to [UID:0000JM][FrameMgr](by-file/FrameMgr.md); includes `0x0061a7dc -> ??_R4FrameHandler@@6B@`, FrameHandler vtable base `0x0061a7e0`, FrameMgr RTTI/vtable at `0x0061a7e8/0x0061a7ec`, lifecycle/embedding refs, and `0x0061a7f8` FramePartPane successor boundary.
        - [UID:0002NH][0x0061a7f8-0x0061a880.FramePartPaneVtableData](by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md) 0x0061a7f8-0x0061a880 | vtable-data | FramePartPaneVtableData : reconstructable : 89% : very strong : Exact FramePartPane primary/secondary/tertiary RTTI/vtable child routed to [UID:00005I][FramePartPane](by-class/FramePartPane.md), with constructor/destructor/scalar-destructor vptr stores, `goog` notification and paint slots, adjustor thunk slots, inherited/default tertiary slot, and successor boundary now linked to the RectBounds quarter-scale constant child at `0x0061a880-0x0061a884`.
        - [UID:<NEW_UID_RECT_QUARTER>][0x0061a880-0x0061a884.RectBoundsQuarterScaleConstant](by-memory/0x0061a880-0x0061a884.RectBoundsQuarterScaleConstant.md) 0x0061a880-0x0061a884 | read-only-float-constant | RectBoundsQuarterScaleConstant : reconstructable : 86% : very strong : Exact one-dword `0.25f` / `0x3e800000` constant used only by [UID:00022H][RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md), with direct address refs at `0x004b7b15` and `0x004b7b43`; route through [UID:0000N2][RectBounds](by-file/RectBounds.md) and do not attach it to FramePartPane, GeneralPurposePanel, GrafPort, or the non-emitting [UID:00025F] aggregate.
        - [UID:0002V4][0x0061a884-0x0061a8b8.PanelGrafPortVtableData](by-memory/0x0061a884-0x0061a8b8.PanelGrafPortVtableData.md) 0x0061a884-0x0061a8b8 | mixed vtable-data index | PanelGrafPortVtableData : not_reconstructable : 88% : very strong : Non-emitting mixed index over exact GeneralPurposePanel, GeneralPurposePanel2, and GrafPort vtable-data children; starts after the RectBounds quarter-scale constant at `0x0061a880-0x0061a884` and ends before the GrafPort `SurfaceDesc` UTF-16 string at `0x0061a8b8`.
            - [UID:0003BC][0x0061a884-0x0061a894.GeneralPurposePanelVtableData](by-memory/0x0061a884-0x0061a894.GeneralPurposePanelVtableData.md) 0x0061a884-0x0061a894 | vtable-data | GeneralPurposePanelVtableData : reconstructable : 86% : very strong : Exact GeneralPurposePanel RTTI/three-slot vtable child routed to [UID:00005Q][GeneralPurposePanel](by-class/GeneralPurposePanel.md), with lifecycle refs from constructor, destructor, and scalar deleting destructor and successor `GeneralPurposePanel2` RTTI boundary.
            - [UID:0003BD][0x0061a894-0x0061a8a4.GeneralPurposePanel2VtableData](by-memory/0x0061a894-0x0061a8a4.GeneralPurposePanel2VtableData.md) 0x0061a894-0x0061a8a4 | vtable-data | GeneralPurposePanel2VtableData : reconstructable : 86% : very strong : Exact GeneralPurposePanel2 RTTI/three-slot vtable child routed to [UID:00005R][GeneralPurposePanel2](by-class/GeneralPurposePanel2.md), with lifecycle refs from constructor, destructor, and scalar deleting destructor and successor GrafPort RTTI boundary.
            - [UID:0003BE][0x0061a8a4-0x0061a8b8.GrafPortVtableData](by-memory/0x0061a8a4-0x0061a8b8.GrafPortVtableData.md) 0x0061a8a4-0x0061a8b8 | vtable-data | GrafPortVtableData : reconstructable : 87% : very strong : Exact GrafPort RTTI/four-slot vtable child routed to [UID:00005V][GrafPort](by-class/GrafPort.md), with scalar deleting destructor, inherited LObject/default slots, `GrafPort::UpdateRenderRegion` slot `+0x0c`, lifecycle vptr stores, and successor `SurfaceDesc` string boundary.
        - [UID:0002V5][0x0061a8b8-0x0061a920.GrafPortSurfaceDescStringData](by-memory/0x0061a8b8-0x0061a920.GrafPortSurfaceDescStringData.md) 0x0061a8b8-0x0061a920 | diagnostic-string-data | GrafPortSurfaceDescStringData : reconstructable : 89% : very strong : Exact UTF-16 `surfaceDesc.dwWidth : %d, surfaceDesc.dwHeight : %d` diagnostic string routed to [UID:00005V][GrafPort](by-class/GrafPort.md), with sole code xref `0x004b9464` inside `GrafPort::UpdateRenderRegion`, exact `0x68`-byte range, and successor software-render mask boundary.
        - [UID:0002V6][0x0061a920-0x0061aac0.SoftwareRenderMaskConstants](by-memory/0x0061a920-0x0061aac0.SoftwareRenderMaskConstants.md) 0x0061a920-0x0061aac0 | read-only-render-constant-data | SoftwareRenderMaskConstants : reconstructable : 86% : strong : Exact RGB555/RGB565 packed mask and blend constant table routed to [UID:0000OC][Surface](by-file/Surface.md), with compat/RGB555 callback refs at `0x004bd420`, `0x004be680`, and `0x004bee40`, RGB565 callback refs at `0x004c3190` and `0x004c4790`, and successor boundary now widened into [UID:0002M7] at `0x0061aac0`.
        - [UID:0002M7][0x0061aac0-0x0061aad0.CachedHashTableVtableData](by-memory/0x0061aac0-0x0061aad0.CachedHashTableVtableData.md) 0x0061aac0-0x0061aad0 | vtable-data | CachedHashTableVtableData : reconstructable : 87% : very strong : Exact CachedHashTable RTTI/vtable-data range routed to [UID:00001F][CachedHashTable](by-class/CachedHashTable.md), including `0x0061aac0 -> ??_R4CachedHashTable@@6B@`, slots `0x004c64f0`, `0x004f4b10`, and `0x0041b6c0`, lifecycle vtable-base refs at `0x004c61a1`, `0x004c6288`, and `0x004c651f`, and successor HelpPanes RTTI boundary at `0x0061aad0`.
    - [UID:00025G][0x0061aad0-0x0061b340.HelpItemHelpReadOnlyData](by-memory/0x0061aad0-0x0061b340.HelpItemHelpReadOnlyData.md) 0x0061aad0-0x0061b340 | vtable/string-data | HelpItemHelpReadOnlyData : reconstructable : 89% : very strong : HelpPane/SimpleHelpPane/SimpleHelpPane2/WillBeChanged/ItemHelpPane read-only-data island now starts at the `0x0061aad0 -> ??_R4SimpleHelpTextPartPane@HelpPane@@6B@` RTTI locator before the first vtable at `0x0061aad4`; route stays [UID:0000JU][HelpPanes](by-file/HelpPanes.md), with vtable refs into HelpPanes executable clusters, item-help literal consumers, and successor boundary before HierList data at `0x0061b340`.
```

Optional support-row replacement for [UID:00022H] in its existing coverage location:

```text
    - [UID:00022H][0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c21.RectBoundsQuarterScaleHelpers.md) 0x004b7af0-0x004b7c21 | raw-function-cluster | RectBoundsQuarterScaleHelpers : reconstructable : 85% : strong : Current RectBounds helper page covers raw quarter-inset/outset helper bodies with corrected `retn 4` endpoints, true padding at `0x004b7b88-0x004b7b90` and `0x004b7c21-0x004b7c30`, no direct xrefs to helper starts, `0x0061a880` / `0.25f` refs at `0x004b7b15` and `0x004b7b43`, and local `0x006104b0` / `0.5f` use sites; B009 2026-06-19 recommends exact child [UID:<NEW_UID_RECT_QUARTER>][RectBoundsQuarterScaleConstant](by-memory/0x0061a880-0x0061a884.RectBoundsQuarterScaleConstant.md) for the source literal.
```

## Validator Commands Needed After Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after the accepted implementation edits:

> Executable block R001 was removed from this report and preserved verbatim in [00025F-FrameGrafPortReadOnlyData-source-routing-removed.md](00025F-FrameGrafPortReadOnlyData-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

If [UID:0002NH], [UID:0002V4], [UID:0002V6], [UID:0003I3], or vtable support docs are edited for boundary/link text, validate each edited file with the same scoped `--mode file --apply --queue-timeout 240` command.

No validators were run for this report-only pass.

## IDA Rename / Type / Comment Recommendations

- `0x0061a880`: rename from `dword_61A880` to `flt_RectBoundsQuarterScale` or `kRectBoundsQuarterScale`. Type `float`. Confidence high for descriptive name and type; original symbol name is not proven.
- `0x0061aac0`: comment/type as `RTTI locator pointer for CachedHashTable`, pointing to `??_R4CachedHashTable@@6B@`. Do not rename as a GrafPort/render constant. Confidence high.
- `0x0061aac4`: keep as `CachedHashTable` vtable base; if IDA still shows `off_61AAC4`, annotate as `??_7CachedHashTable@@6B@` / `CachedHashTable_vftable`. Confidence high.
- `0x0061aad0`: comment/type as `RTTI locator pointer for SimpleHelpTextPartPane<HelpPane>`, pointing to `??_R4SimpleHelpTextPartPane@HelpPane@@6B@`. Confidence high.
- `0x0061aad4`: keep as successor HelpPanes vtable base `??_7SimpleHelpTextPartPane@HelpPane@@6B@`. Confidence high.

## First-Draft C++ / No-Code Recommendation

[UID:00025F] must keep formal C++ blank.

No first-draft source code should be entered for the parent because:

- The target is `RECONSTRUCTABLE:FALSE`.
- It has no valid source emitter.
- It is a mixed physical index, not a source declaration or method body.
- Exact children and support pages already carry the source routes.
- Emitting a byte table or aggregate static data would duplicate vtables, string literals, constants, and RTTI that should be regenerated from class declarations and exact owner code.

For the proposed new `RectBoundsQuarterScaleConstant` child, if the supervisor later requests formal C++ despite the data-literal nature, use this only as source-shape guidance in `RectBounds.cpp` and avoid attaching it to [UID:00025F]:

```cpp
static const float kRectBoundsQuarterScale = 0.25f;
```

However, the safer reconstruction route is to let the RectBounds quarter-scale helper C++ use `0.25f` directly; MSVC can materialize the literal in `.rdata` without a named source global.

## Final Recommendation

- Rename [UID:00025F] to `0x0061a7dc-0x0061aad0.FrameGrafPortReadOnlyData.md`.
- Keep it non-reconstructable, no-owner, non-emitting, and no-code.
- Create `0x0061a880-0x0061a884.RectBoundsQuarterScaleConstant.md` as the only missing exact source-bearing child inside the target range.
- Widen [UID:0002M7] to `0x0061aac0-0x0061aad0`.
- Widen [UID:00025G] to `0x0061aad0-0x0061b340`.
- Update stale support docs and coverage rows exactly as listed above.
- Do not assign [UID:00025F] to FrameMgr, FrameChrome, GeneralPurposePanel, GrafPort, Surface, SoftwareBlend16, CachedHashTable, or HelpPanes.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B009/research/00025F-FrameGrafPortReadOnlyData-source-routing.md`
- Modified: none outside B009 research.
- Not modified: target by-memory doc, support by-* docs, generated reports, `by-memory/-coverage-report.md`, IDA database, and tool files.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/00025F-FrameGrafPortReadOnlyData-source-routing.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"00025F"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00025F-FrameGrafPortReadOnlyData-source-routing-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/00025F-FrameGrafPortReadOnlyData-source-routing.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00025F"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
