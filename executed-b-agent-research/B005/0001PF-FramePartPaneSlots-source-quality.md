** TARGET-REPORT-UID:0001PF **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# UID0001PF FramePartPaneSlots Source-Quality Report

## Finalized Report / Current Recommendation

Recommend changing [UID:0001PF] `by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md` from an empty-emitter data page to a source-emitting FrameChrome static-storage page with exact formal insertion text:

```cpp
static FramePartPane* g_framePartPanes[5];
```

Recommended target metadata after implementation: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000JL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JL`, and populated formal `RECONSTRUCTION_CPP CODE` with only the declaration above. The score remains below 90 completion and below 95 confidence because the live route to `BuildFramePartPanes`/raw cleanup and the exact original source spelling (one array versus five equivalent statics) remain unresolved after the reasonable current routes. Those blockers cap score; they do not justify keeping the storage declaration blank because the source model already uses `g_framePartPanes[5]` in accepted FrameChrome helper/method C++.

## Supporting Research

This began as a report-only B-agent pass for Agent-B005 under the project-level `ntk-b-agent-workflow` skill and the updated `goal.md` in `tools/leaser/Agents/Agent-B005`. I read the skill instructions, `references/b-agent-research-and-implementation-workflow.md`, `references/score-blocker-audit-standard.md`, and `references/b-agent-report-template.md`. I also checked `by-structure.md` and the relevant by-* guidance files for source ownership, reconstructability, emitter routing, and score-gate rules.

Gate 1 passed, and the accepted implementation callback edited only `by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md`, `by-file/FrameChrome.md`, `by-memory/0x004b73b0-0x004b7661.FramePartPane.md`, and this B005 report. Leases were taken only for those three by-* files during the edit/validator batch. No generated report, coverage report, supervisor ledger, manual validator state, queue, lock, archive, lifecycle file, IDA DB state, or unrelated by-* support file was manually edited. No `execute_report`, dry-run/probing execute variant, lifecycle/archive/report-move command, or process-management command was run.

Queue context came from `auto-generated/-ag-research-tracker.md` under `## by-memory` / `### Not-Covered Files - Reconstructable`: UID0001PF was listed at Gate 1 as `85/91`, average `88.0`, reconstructable `true`, path `by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md`. The goal notes UID0001PF was the next eligible row after active or skipped rows. Generated-output context at Gate 1 came from `auto-generated/-ag-memory-coverage.md` and `auto-generated/NexusTK/ui/core/FrameChrome.cpp`, which then contained UID0001PF only as an `Empty Emitter Marker`; after callback validation, generated `FrameChrome.cpp` is refreshed at command id `000000008004` / `2026-07-08T17:09:32-04:00` and emits `static FramePartPane* g_framePartPanes[5];` for UID0001PF.

Target/support research covered the target page, `by-file/FrameChrome.md`, `by-global/FrameChromeSlots.md`, `by-class/FramePartPane.md`, `by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md`, `by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md`, `by-memory/0x004b73b0-0x004b7661.FramePartPane.md`, `by-item/BuildFramePartPanes_004B7120.md`, neighboring boundary pages `by-memory/0x0069b339-0x0069b33c.UnreferencedInitializedBytes_69B339.md` and `by-memory/0x0069b350-0x0069b358.StartupClearedUnusedDwords.md`, plus vtable support pages `by-type/by-vtable/FramePartPaneVtables.md` and `by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md`.

Old-report search terms were `0001PF`, `0x0069b33c`, `0069b33c`, `FramePartPaneSlots`, `g_framePartPanes`, and `FramePartPane slots`. Relevant accepted research leads were `executed-b-agent-research/B011/00022F-BuildFramePartPanes-source-quality.md`, `executed-b-agent-research/B007/00015N-FramePartPaneSlotCleanup-source-quality.md`, `executed-b-agent-research/B002/00015O-FramePartPane-source-quality.md`, and `executed-b-agent-research/B002/00029L-StartupClearedUnusedDwords-source-quality.md`. No existing B005 root report for UID0001PF was present at the expected report path before this pass.

Active MCP context is session `2cb2455b` over `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, created `2026-07-08T16:30:57.689167`, active and not analyzing. `server_health` returned `status: ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready: true`, and `hexrays_ready: true`. MCP was available and used for current bytes, xrefs, decompile, disassembly, function lookup, callees, and byte-pattern checks.

## Target

- UID: `0001PF`
- Target path: `by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md`
- Queue/source row: `auto-generated/-ag-research-tracker.md` listed UID0001PF in `## by-memory` / `### Not-Covered Files - Reconstructable` as `85/91`, average `88.0`, reconstructable `true` before callback.
- Current classification: reconstructable project global/static storage for five contiguous `FramePartPane*` slots.
- Callback-applied metadata: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000JL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JL`, formal `RECONSTRUCTION_CPP CODE` populated with `static FramePartPane* g_framePartPanes[5];`.
- Current parent/emitter state: parent and emitter route remain [UID:0000JL] `FrameChrome`; generated output `auto-generated/NexusTK/ui/core/FrameChrome.cpp` now emits UID0001PF as a declaration rather than an empty marker.
- Resolved target summary defect: the stale source-initializer wording is replaced with current MCP zero `get_bytes` plus all-`FF` IDB/signature-artifact distinction.

## Current Target State

The target now documents the five dword addresses, the FrameChrome owner, the builder write sites, cleanup clear sites, notification clear sites, and the emitted source-facing `g_framePartPanes[5]` model. It no longer remains an empty-emitter page: the formal C++ declaration was populated during callback and scoped validation refreshed generated `FrameChrome.cpp`.

Current owner/emitter/reconstructable state is coherent and should remain `CANONICAL_OWNER:0000JL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JL`. The direct semantic owner is the FrameChrome source file, not the `FramePartPane` class, because the data is file/static storage used by FrameChrome helper code and `FramePartPane` methods. The class owns method/vtable behavior, but not the global slot storage.

The former C++/empty-emitter state was not coherent with the accepted source model because `BuildFramePartPanes`, `ReleaseFramePartPanes`, and `FramePartPane` method C++ already referred to `g_framePartPanes[5]` while UID0001PF contributed no declaration. The callback resolved that gap by adding the exact file-static declaration.

Open blockers are fully characterized: no direct/static xref to the builder entry `0x004b7120`, no direct/static xref to raw cleanup entry `0x004b7320`, no stored VA/RVA pointer to either entry in current MCP `find_bytes`, and no symbol proof that the original source spelling was exactly one array rather than five equivalent file statics. These blockers are target-specific score caps, not a reason to omit the declaration that downstream C++ already uses.

Related docs checked: `FrameChrome.md`, `FrameChromeSlots.md`, `FramePartPane.md`, builder/cleanup/method by-memory pages, the BuildFramePartPanes by-item redirect, neighboring filler/unused dword pages, and FramePartPane vtable pages. Most support docs already contain same-or-greater slot-family detail. The callback added the explicit UID0001PF declaration-emitter note to `FrameChrome.md` and corrected the stale `FramePartPane` Item Summary phrase that contradicted its formal C++ block.

Current artifact/lifecycle state: Gate 1 passed and this report has been updated for implementation callback. The target and two support docs were validated with scoped file validators, then the target was read back; the stale registry-backed source-initializer wording did not return.

## Heuristic / Inference Reanalysis And Validation

The source declaration recommendation is not based on a lone name heuristic. It is based on a five-element contiguous dword span, uniform xref families, existing accepted helper/method source that already indexes the slots as `g_framePartPanes[5]`, and direct current MCP confirmation of five write/clear families.

The array spelling remains a source-facing reconstruction choice rather than symbol-proven original spelling. However, one private array is the least fabricated form because it avoids inventing five independent names, matches all accepted downstream C++ that indexes the slots, and matches the contiguous storage and uniform lifecycle. The unresolved array-versus-five-statics question caps score below final audit level; it does not require blank C++ because either original form contributes the same private static pointer storage.

The byte-state conflict is also characterized. Current MCP `get_bytes` returns zeros for `0x0069b33c-0x0069b350`, while `make_signature_for_range` over the same range still returns twenty `FF` bytes. The target body and prior B007 cleanup report already identify this as an IDB/listing versus loader/unbacked-tail artifact. For source reconstruction, a file-scope static pointer array without an explicit initializer zero-initializes the storage and does not preserve stale `0xffffffff` wording.

## Evidence Standards Used

- Direct current MCP evidence is preferred for byte state, xrefs, function boundaries, callees, and decompile/disassembly details.
- Accepted prior B-agent reports are used as corroborating research leads, especially for route scans, validator-state caveats, and support-doc incorporation history.
- Generated output is treated as artifact/freshness evidence, not source truth: before callback it showed an Empty Emitter Marker for UID0001PF; after scoped validator/generator refresh command `000000008004`, it emits `static FramePartPane* g_framePartPanes[5];` for UID0001PF.
- Source placement follows direct semantic ownership: file/static FrameChrome storage belongs to `by-file/FrameChrome.md` and UID0000JL, with `FramePartPane` class/method docs as support only.
- Score blockers are resolved to a recommendation, exclusion, or score cap. The remaining blockers are not left as open-ended work.

## Evidence Checked

- MCP session `2cb2455b` health: ok, imagebase `0x400000`, Hex-Rays ready, auto-analysis ready.
- MCP `get_bytes`: `0x0069b330-0x0069b360` returned all zero bytes; individual reads of `0x0069b33c`, `0x0069b340`, `0x0069b344`, `0x0069b348`, and `0x0069b34c` also returned four zero bytes each.
- MCP `make_signature_for_range`: `0x0069b33c-0x0069b350` returned twenty `FF` bytes, matching the known stale IDB/listing byte artifact that must not be promoted into a source initializer.
- MCP `xref_query` slot totals: `0x0069b33c` has 4 refs, `0x0069b340` has 4, `0x0069b344` has 4, `0x0069b348` has 4, and `0x0069b34c` has 5. The next dword `0x0069b350` has only the startup wrapper ref at `0x00419f00`.
- Slot ref families: builder writes at `0x004b719b`, `0x004b71f1`, `0x004b724a`, `0x004b72a3`, `0x004b72f5`, with an allocation-failure clear at `0x004b72fc`; cleanup reads/clears at `0x004b7320/0x004b7330`, `0x004b733a/0x004b734a`, `0x004b7354/0x004b7364`, `0x004b736e/0x004b737e`, and `0x004b7388/0x004b7398`; notification clears at `0x004b73cb`, `0x004b73d5`, `0x004b73df`, `0x004b73e9`, and `0x004b73f3`.
- MCP `decompile 0x004b7120`: five `252`-byte allocations, five `sub_4B7480` constructor calls, and the known rectangle/offset/index sequence `(198,6)+(118,12)->4`, `(56,93)+(14,12)->0`, `(57,93)+(365,12)->1`, `(77,37)+(14,335)->2`, `(79,39)+(343,333)->3`.
- MCP `decompile 0x004b73b0`: notification handler checks tag `1735356263` (`0x676f6f67`), calls `sub_469180`, and clears all five slot addresses.
- MCP `decompile 0x004b7480`: constructor calls `sub_544460`, stores the three FramePartPane vtables, stores the role/index at `this + 248`, calls `sub_544C70` with `unk_69B364`, and registers tag `1735356263` through `sub_4F4B30`.
- MCP `lookup_funcs`: builder `0x004b7120` is `sub_4B7120` size `0x1ff`; notification `0x004b73b0` size `0x51`; paint `0x004b7410` size `0x70`; constructor `0x004b7480` size `0x95`; scalar deleting destructor `0x004b75b0` size `0xb1`; helper `0x004b7c50` size `0x1f`; helper `0x004b7e10` size `0x19`; allocator helper `0x004f4aa0` size `0x14`. Raw cleanup `0x004b7320` is not an IDA function.
- MCP `xref_query`: no cross-references to `0x004b7120` and no cross-references to `0x004b7320`; `0x004b73b0` has its vtable data ref at `0x0061a804`.
- MCP `find_bytes`: no matches for stored VA/RVA patterns `20 71 4B 00`, `20 71 0B 00`, `20 73 4B 00`, or `20 73 0B 00`; positive-control slot-address patterns found the expected 4/4/4/4/5 slot references and one neighbor ref to `0x0069b350`.
- Prior B007 validator note: an `--apply` validator run restored stale registry-backed summary text for UID0001PF before correction; callback must detect and address any repeat of that stale artifact.

## Ranked Ownership Analysis

| Rank | Candidate | Decision | Evidence |
| --- | --- | --- | --- |
| 1 | [UID:0000JL] `FrameChrome` | Keep as canonical owner/emitter. | Builder, cleanup, generated file, and by-file source placement all sit in the FrameChrome source family; generated output route is `NexusTK/ui/core/FrameChrome.cpp`. |
| 2 | [UID:0000PN] `FrameChromeSlots` / `by-global/FrameChromeSlots.md` | Support aggregate, not canonical target owner. | It summarizes multiple FrameChrome global slots and already includes UID0001PF-family detail, but UID0001PF is the exact by-memory storage item. |
| 3 | [UID:00005I] `FramePartPane` | Method/class support only. | Constructor, notification, paint, vtables, and destructor behavior belong to the class, but the global storage is file/static FrameChrome state. |
| 4 | Neighbor filler/unused pages UID0002W2 and UID00029L | Reject merge. | Previous range ends at `0x0069b33c`; target ends at `0x0069b350`; next dword has only startup-wrapper ref at `0x00419f00`. |
| 5 | Generic pane manager / startup wrapper / UI layer slots | Reject as owner. | Their refs are helper/context refs, not ownership of the five FramePartPane storage slots. |

## Source Placement

Place the declaration in the FrameChrome source output, routed through UID0000JL and generated file `NexusTK/ui/core/FrameChrome.cpp`. The declaration should be file-static storage near the FrameChrome/FramePartPane helper declarations, before functions that use `g_framePartPanes`.

Do not place this declaration in the `FramePartPane` class page as a member. The binary accesses absolute storage addresses, and existing accepted helper/method C++ treats the storage as a file/global array.

## First-Draft C++ Recommendation

The following is exact formal `RECONSTRUCTION_CPP CODE` insertion text for UID0001PF, not illustrative or planning-only C++:

```cpp
static FramePartPane* g_framePartPanes[5];
```

No explicit initializer should be added. File-scope static pointer storage zero-initializes and matches the current loader/runtime zero state without preserving stale `0xffffffff` IDB/listing bytes.

## Recommended Target Doc Changes

- Update metadata to `COMPLETION:88`, `CONFIDENCE:92`, while keeping `CANONICAL_OWNER:0000JL`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000JL`.
- Replace the stale Item Summary phrase that says the slots are initialized to `0xffffffff`. The summary should say current MCP `get_bytes` reads the slot span as zeroed, while the IDB/signature artifact still shows `FF` bytes and is not a source initializer.
- Populate the target formal `RECONSTRUCTION_CPP CODE` with exactly `static FramePartPane* g_framePartPanes[5];`.
- Preserve the five-slot address table, roles, builder writes, fifth allocation-failure clear, cleanup read/delete/clear sequences, notification clear sequence, and constructor/helper context.
- Add or update current MCP provenance for session `2cb2455b`, including the zero `get_bytes`, `FF` signature artifact, slot xref counts, no builder/cleanup xrefs, no stored VA/RVA pointer matches, and positive-control slot-address pattern hits.
- Preserve the unresolved but exhausted blockers as score caps: no live static route to builder/cleanup and no symbol proof of original array-versus-five-statics spelling.

## Recommended Support Doc Changes

- `by-file/FrameChrome.md`: incorporate that UID0001PF should now emit the file-static declaration for `g_framePartPanes[5]` if that statement is not already present at same-or-greater detail; otherwise mark already-present.
- `by-global/FrameChromeSlots.md`: already contains the same-or-greater global-slot family, zero/unbacked, and `g_framePartPanes[5]` context; mark already-present unless callback inspection finds stale empty-emitter wording.
- `by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md`: already contains source-ready builder C++ using `g_framePartPanes[5]`; mark already-present.
- `by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md`: already contains source-ready cleanup C++ and the validator-state caveat; mark already-present.
- `by-memory/0x004b73b0-0x004b7661.FramePartPane.md`: already uses `g_framePartPanes[5]`, but if the stale Item Summary phrase "final C++ remains blank" is still present during callback, correct only that stale summary fact and mark the rest already-present.
- Neighbor boundary docs UID0002W2 and UID00029L: already establish split/no-merge boundaries; no edit recommended.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C001 | Gate 1 baseline UID0001PF was `85/91`, owner/emitter `0000JL`, reconstructable true, with blank formal C++; callback target state is `88/92` with formal C++. | High | Target header and tracker row; callback validator command `000000008002`. | Target metadata | incorporate | applied |
| C002 | Gate 1 generated `FrameChrome.cpp` carried UID0001PF as an `Empty Emitter Marker`; callback generated output now emits the declaration. | High | Generated file command id `000000008004`, refreshed `2026-07-08T17:09:32-04:00`, UID0001PF declaration at generated lines 172-173. | Target status / FrameChrome support | incorporate | applied |
| C003 | The Gate 1 Item Summary source-initializer wording was stale and is now rejected/replaced. | High | Target read-back after validator command `000000008002`; no `0xffffffff` text returned. | Target Item Summary | reject-stale | applied |
| C004 | The slot block is five contiguous dword-sized `FramePartPane*` storage entries at `0x0069b33c-0x0069b350`. | High | Target table, current MCP slot xrefs, neighbor boundaries. | Target layout | incorporate | applied |
| C005 | Current MCP `get_bytes` reads the full target span as zero bytes. | High | Session `2cb2455b`, `get_bytes 0x0069b33c size 20`. | Target evidence / summary | incorporate | applied |
| C006 | Current MCP signature still returns twenty `FF` bytes for the target span, so the implementation preserves the artifact distinction. | High | `make_signature_for_range 0x0069b33c-0x0069b350` returned `FF` x20; target read-back uses all-`FF` artifact wording. | Target evidence / score rationale | incorporate | applied |
| C007 | Slot xref counts are 4, 4, 4, 4, and 5. | High | Current MCP `xref_query` totals for the five addresses. | Target xref evidence | incorporate | applied |
| C008 | Builder writes the five slots at `0x004b719b`, `0x004b71f1`, `0x004b724a`, `0x004b72a3`, and `0x004b72f5`. | High | Current MCP `xref_query` and `decompile 0x004b7120`; target evidence retained. | Target builder evidence / BuildFramePartPanes support | incorporate | applied |
| C009 | The fifth slot has an allocation-failure clear at `0x004b72fc`. | High | Current MCP `xref_query` and builder decompile; target evidence retained. | Target builder evidence | incorporate | applied |
| C010 | Builder constructs five `FramePartPane` objects using allocation size `252`, constructor `0x004b7480`, and role/index sequence `4,0,1,2,3`. | High | Current MCP `decompile 0x004b7120`; target evidence retained and builder doc already has same-or-greater C++ detail. | Target builder table / BuildFramePartPanes support | incorporate | applied |
| C011 | Builder rectangle/offset sequence is `(198,6)+(118,12)`, `(56,93)+(14,12)`, `(57,93)+(365,12)`, `(77,37)+(14,335)`, `(79,39)+(343,333)`. | High | Current MCP `decompile 0x004b7120`; target table retained. | Target layout/evidence | incorporate | applied |
| C012 | Raw cleanup at `0x004b7320` is not an IDA function and has no xrefs, but reads/deletes/clears each slot. | High | Current MCP `lookup_funcs`, `xref_query`, `disasm 0x004b7320`, and slot xrefs; target evidence retained and cleanup support already same-or-greater. | Target cleanup evidence / cleanup support | incorporate | applied |
| C013 | Cleanup deletes through the first vtable slot with flag `1` before clearing each non-null slot. | High | Current cleanup disassembly and B007 report; target evidence retained and cleanup support already same-or-greater. | Target cleanup evidence / cleanup support | incorporate | applied |
| C014 | Notification handler `0x004b73b0` clears all five slots on tag `0x676f6f67` and calls `0x00469180`. | High | Current MCP `decompile 0x004b73b0`; tag decimal `1735356263`; target evidence retained. | Target notification evidence / FramePartPane support | incorporate | applied |
| C015 | Constructor `0x004b7480` sets FramePartPane vtables, stores the role at `this+248`, consumes `0x0069b364`, and registers the same tag. | High | Current MCP `decompile 0x004b7480`; target evidence retained. | Target constructor context / FramePartPane support | incorporate | applied |
| C016 | Helper roles are stable: `0x004b7c50` rectangle set, `0x004b7e10` rectangle offset, `0x004f4aa0` allocator, `0x004b7480` constructor. | Medium-high | Current MCP callees and accepted builder doc naming; target evidence retained. | Target helper context / BuildFramePartPanes support | incorporate | applied |
| C017 | No direct/static xrefs to `0x004b7120` or `0x004b7320` were found in current MCP. | High | Current MCP `xref_query` reports zero refs to both; target score rationale retained. | Target blockers / score rationale | incorporate | applied |
| C018 | No stored VA/RVA patterns for builder or cleanup were found, while positive-control slot-address patterns were found. | High | Current MCP `find_bytes` for `20 71 4B 00`, `20 71 0B 00`, `20 73 4B 00`, `20 73 0B 00` found zero; target B005 note retained. | Target blockers / score rationale | incorporate | applied |
| C019 | Neighbor `0x0069b350` is not part of the slot array and only has startup-wrapper ref `0x00419f00`. | High | Current MCP xref for `0x0069b350` plus UID00029L support doc; target B005 note retains boundary. | Target boundaries / neighbor docs | already-present | already-present |
| C020 | FrameChrome is the correct canonical owner/emitter; FramePartPane is support only for class behavior. | High | by-file, by-global, class, method docs, generated route, and callback FrameChrome note. | Target ownership / FrameChrome support | incorporate | applied |
| C021 | The exact formal target C++ should be `static FramePartPane* g_framePartPanes[5];`. | Medium-high | Accepted helper/method C++ already uses this array, current xrefs prove five contiguous slots, and target formal C++ now contains exact declaration. | Target formal C++ | incorporate | applied |
| C022 | The original source spelling remains unresolved as array versus five equivalent statics, but that is a score cap rather than a no-code proof. | Medium-high | No symbol proof; accepted docs prefer array-family model; target score rationale retains the cap. | Target score rationale / open questions | incorporate | applied |
| C023 | Recommended score is `88/92`, not 90+ or 95+, because route and exact spelling remain unresolved after current checks. | Medium-high | Target metadata and score rationale after command `000000008002`. | Target metadata / score rationale | incorporate | applied |
| C024 | Prior validator `--apply` behavior may restore stale summaries, so callback must validate and read back target/support summaries. | Medium-high | Scoped validators `000000008002`-`000000008004`; target read-back after validation. | Implementation checklist / validator notes | incorporate | applied |

## Positive Evidence Summary

- Five contiguous slot addresses have the expected 4/4/4/4/5 xref pattern and no merge with either neighbor.
- Current MCP decompile confirms the builder creates five `FramePartPane` objects with role/index values and RectBounds sequences already documented by support pages.
- Current MCP confirms notification clear and constructor registration use the same `goog` tag family.
- Existing accepted source C++ for builder, cleanup, and FramePartPane methods already depends on `g_framePartPanes[5]`.
- A file-static pointer array declaration is source-shaped and zero-initializes correctly without encoding stale `FF` bytes.

## Negative Evidence Summary

- No direct/static caller route to `BuildFramePartPanes` was found by current MCP xrefs or stored VA/RVA byte-pattern checks.
- Raw cleanup `0x004b7320` is not an IDA function and has no incoming xrefs.
- Exact original source spelling of the five storage cells remains unproven.
- IDB/signature bytes still expose the stale `FF` pattern despite current `get_bytes` zero reads, so implementation must avoid stale initializer wording and read back validator-applied summaries.

## Final Recommendation

Promote UID0001PF to a source-emitting FrameChrome storage page. Add the exact formal C++ declaration, update stale zero/`FF` wording, preserve all five-slot lifecycle details, and raise the target to `COMPLETION:88`, `CONFIDENCE:92`. Keep the canonical owner/emitter unchanged at UID0000JL.

Support docs should mostly be marked already-present. Only touch support docs during an implementation callback if inspection finds stale or missing statements at lower detail than this report, especially the stale FramePartPane Item Summary phrase if still present.

## Score And Metadata Recommendation

| Field | Current | Recommended | Rationale |
| --- | --- | --- | --- |
| `COMPLETION` | `85` | `88` | Formal declaration, current MCP slot evidence, and stale-summary correction make the page source-emitting, but live route/exact spelling remain score caps. |
| `CONFIDENCE` | `91` | `92` | Current MCP confirms the slot lifecycle and route negatives; confidence stays below final audit due unresolved route/spelling and byte-artifact state. |
| `CANONICAL_OWNER` | `0000JL` | `0000JL` | FrameChrome remains direct file/static owner. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Storage is reconstructable source-level static state. |
| `EMITTER_UIDS` | `0000JL` | `0000JL` | Declaration should emit through `FrameChrome.cpp`. |
| Formal C++ | blank | `static FramePartPane* g_framePartPanes[5];` | Required declaration for accepted helper/method C++. |

## Open Questions With Attempted Resolution

| Question | Routes attempted | Resolution for this report |
| --- | --- | --- |
| Is `0xffffffff` the source initializer? | Current MCP `get_bytes`, MCP signature, B007 raw/unbacked-tail report, target body, generated output state. | No. Preserve the `FF` signature as an artifact, but source declaration should zero-initialize without explicit initializer. |
| Is the builder live/reachable by a direct route? | Current MCP `xref_query` to `0x004b7120`, stored VA/RVA `find_bytes`, prior B011 local PE route scan. | No direct/static route found. This caps score and must be documented; it does not negate the slot storage declaration. |
| Is raw cleanup live/reachable by a direct route? | Current MCP `lookup_funcs`, `xref_query` to `0x004b7320`, stored VA/RVA `find_bytes`, prior B011/B007 route checks. | No direct/static route found, and IDA does not define it as a function. Cleanup behavior is still valid lifecycle evidence through slot xrefs. |
| Was the original source exactly one array? | Current xrefs, accepted builder/cleanup/method C++ usage, by-file/by-global support docs, absence of symbol names. | Exact original spelling remains unresolved. Use the array declaration because it is the least fabricated source-facing declaration and matches accepted emitted C++; cap score accordingly. |
| Do support docs require immediate edits? | Read current target/support docs and old reports. | Most support state is same-or-greater detail; only stale/missing support statements should be edited during implementation callback. |

## Validator Results

Implementation callback scoped validators:

- `python .\tools\validator.py --mode file --file by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md --apply --queue-timeout 240`
  - `command_id: 000000008002`
  - `command_timestamp: 2026-07-08T17:09:12-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Updates: completion `88`, confidence `92`, registry hash update, registry blank-to-block C++ update, projected stats update, generated refresh deferred.
- `python .\tools\validator.py --mode file --file by-file/FrameChrome.md --apply --queue-timeout 240`
  - `command_id: 000000008003`
  - `command_timestamp: 2026-07-08T17:09:21-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Warnings: existing `missing_ref_uid` warnings for `0003I2` and `0003I3`; not introduced by this callback.
  - Updates: projected stats update, generated refresh deferred.
- `python .\tools\validator.py --mode file --file by-memory/0x004b73b0-0x004b7661.FramePartPane.md --apply --queue-timeout 240`
  - `command_id: 000000008004`
  - `command_timestamp: 2026-07-08T17:09:32-04:00`
  - Exit code: `0`
  - `ok: 1`
  - Updates: projected stats update, generated refresh deferred.

Generated freshness: `auto-generated/NexusTK/ui/core/FrameChrome.cpp` header now records `validator-command-id: 000000008004` and `validator-refreshed-at: 2026-07-08T17:09:32-04:00`; UID0001PF now emits `static FramePartPane* g_framePartPanes[5];` and no longer carries an empty marker.

Post-validation target read-back: `by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md` still has `COMPLETION:88`, `CONFIDENCE:92`, exact formal C++ `static FramePartPane* g_framePartPanes[5];`, and the Item Summary uses current zero `get_bytes` plus all-`FF` artifact wording. The stale `0xffffffff` wording did not return.

No `execute_report`, dry-run/probing execute variant, report lifecycle/archive command, manual report move, registry lifecycle command, or IDA DB state-changing command was run.

## Changed Files

- `by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md` - applied target score `88/92`, formal declaration, stale summary/prose repair, B005 evidence, and score-cap rationale.
- `by-file/FrameChrome.md` - added explicit note that UID0001PF now emits the file-static `g_framePartPanes[5]` declaration.
- `by-memory/0x004b73b0-0x004b7661.FramePartPane.md` - corrected only the stale Item Summary statement that contradicted the formal method C++ block.
- `tools/leaser/Agents/Agent-B005/research/0001PF-FramePartPaneSlots-source-quality.md` - updated callback ledger/checklist, validator results, changed-file state, and implementation proof.

Validator-generated side effects observed after scoped validation: `auto-generated/NexusTK/ui/core/FrameChrome.cpp`, `auto-generated/-ag-memory-coverage.md`, and `project-level/-auto-completion-stats.md` refreshed/updated through validator commands. No generated file, coverage report, validator state, supervisor ledger, queue, lock, archive, lifecycle file, or IDA DB state was manually edited.

## Implementation Tracking Checklist

Implementation callback state: accepted items are checked as applied, already-present, or validator-confirmed.

| Status | Ledger claims | Callback target | Required verifiable outcome |
| --- | --- | --- | --- |
| [x] | C001, C002, C021, C023 | `by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md` metadata and formal C++ | Applied: target is `88/92`, owner/emitter unchanged, formal C++ contains exactly `static FramePartPane* g_framePartPanes[5];`; generated `FrameChrome.cpp` command `000000008004` emits UID0001PF declaration with no empty marker. |
| [x] | C003, C005, C006, C024 | Target Item Summary and byte-state evidence | Applied: stale source-initializer wording replaced with zero `get_bytes` plus all-`FF` artifact distinction; post-validator read-back confirms stale `0xffffffff` wording did not return. |
| [x] | C004, C007, C008, C009, C010, C011 | Target slot layout/builder evidence | Applied: target preserves five slot addresses, roles, xref counts, write sites, fifth allocation-failure clear, allocation size, constructor calls, role/index values, rectangles, and offsets at report-level detail. |
| [x] | C012, C013, C014, C015, C016 | Target lifecycle/helper evidence and support docs | Applied/already-present: target preserves cleanup, notification, constructor, helper, and tag facts; builder/cleanup support docs already had same-or-greater detail; FramePartPane stale summary was corrected. |
| [x] | C017, C018, C022, C023 | Target score rationale and open blockers | Applied: no-route, no stored VA/RVA, and exact-spelling blockers are documented as exhausted score caps. |
| [x] | C019 | Target boundary notes / neighbor docs | Already-present: UID0002W2 and UID00029L boundary facts already establish no merge/split; no neighbor edit made. |
| [x] | C020 | `by-file/FrameChrome.md`, `by-global/FrameChromeSlots.md`, `by-class/FramePartPane.md` | Applied/already-present: `FrameChrome.md` now records UID0001PF declaration emission; FrameChromeSlots and FramePartPane/class support remain support-only with same-or-greater detail. |
| [x] | C024 | Validator callback notes | Applied: scoped validators `000000008002`, `000000008003`, and `000000008004` ran with exit code `0` and `ok: 1`; post-`--apply` read-back found no restored stale target summary. |

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000008018","destination_path":"executed-b-agent-research/B005/0001PF-FramePartPaneSlots-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0001PF-FramePartPaneSlots-source-quality.md","timestamp":"2026-07-08T17:53:22-04:00","uid":"0001PF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
