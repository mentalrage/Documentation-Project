** TARGET-REPORT-UID:0000YK **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000YK AlphaMaskSurface Raw Default Constructor Source-Quality Audit

## Finalized Report / Current Recommendation
- Current recommendation: raise [UID:0000YK] from `82/88` to `85/90`.
- Final disposition: keep as reconstructable raw constructor-family evidence, not as an IDA-modeled callable method and not as ignored/dead padding.
- Required action: update only the target score/evidence text and the supervisor-owned `by-memory/-coverage-report.md` row; leave owner/emitter metadata and final C++ blank.
- Confidence: high for the recommended disposition; medium for the exact original source declaration form.

## Supporting Research

## Target
- Target UID: `0000YK`
- Target path: `by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md`
- Source queue/report row: `project-level/-auto-completion-stats.md` Low_Completion and Low_Both at `82/88`; `by-memory/-coverage-report.md` row currently `82% : strong`.
- Current supervisor classification: `B001-goal2-alphamask-raw-default-constructor-source-quality-0000YK-20260616`, report-only B-preferred heuristic/source-inference audit.
- Current scores and parent state: `COMPLETION:82`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000HF`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HF`, final C++ blank.

## Executive Recommendation
- Raise [UID:0000YK] to `COMPLETION:85`, `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:0000HF` and `EMITTER_UIDS:0000HF`. The best physical source placement remains [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md).
- Keep `RECONSTRUCTABLE:TRUE`. The bytes are custom source-shaped constructor code in `.text`, not padding, EH glue, CRT/runtime support, or a pure linker artifact.
- Keep `RECONSTRUCTION_CPP CODE` blank. After the score bump the combined score/emitter gate would be numerically satisfied, but the active code-entry rule is only a minimum gate; no direct caller, no IDA function object, no pointer/reference route, and duplicate zero-branch behavior in `0x00462170` still make final source emission unsafe.
- Do not reroute to [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md) or [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md). The vtable/type owner is `IntAlphaSurface`, but the raw body is physically and behaviorally part of the AlphaMaskSurface constructor/helper cluster.
- Do not reclassify as ignored/dead. It has unique constructor-shaped bytes, writes the real alpha-surface vtable, calls the real RectBounds initializer, and documents source-family/layout evidence that remains needed.

## Supervisor Active Recheck
- The user explicitly assigned report-only source-quality work for [UID:0000YK] and forbade direct edits to by-* docs, generated reports, source files, IDA DB, and `by-memory/-coverage-report.md`.
- I did not edit by-* files, generated reports, source files, or IDA DB.
- This target does not need split repair. The range is exact: prior function ends at `0x00462114`, padding occupies `0x00462114-0x00462120`, the raw body occupies `0x00462120-0x00462161`, and alignment padding follows until the modeled `0x00462170` constructor.
- Every source-bearing child in scope already exists: [UID:0000YK], active constructor aggregate [UID:0000YL], EH cleanup [UID:0000YM], view initializer [UID:0002NM], and destructor [UID:0000YP].

## Inference Research Guidance Check
- I treated existing docs as leads and rechecked the key claims against the current IDA MCP session and the raw PE.
- IDA facts: function boundaries, xrefs, bytes, decompilation of neighboring functions, vtable bytes, current executable hash.
- Raw PE facts: no absolute VA, RVA, or rel32 call/jump references to `0x00462120` or `0x004623c0`; section layout confirms `.text` mapping.
- Documentation evidence: related by-file/by-class/by-type pages are now at or above the `85/85` parent gate and already preserve the AlphaMaskSurface versus IntAlphaSurface split caveat.
- Inference: original source likely had a source-authored empty/default constructor or retained constructor clone, but the current binary does not prove the body is ever called.

## Heuristic / Inference Reanalysis And Validation

### Raw no-function / no-xref liveness
- Current IDA MCP `lookup_funcs` in session `b001_0000YK_alphamask_raw_default_constructor_20260616` reports `0x00462120`, `0x0046212c`, `0x00462160`, and `0x00462161` as `Not a function`.
- `lookup_funcs` reports previous function `sub_461FE0` at `0x00461fe0` size `0x134`, covering through `0x00462113`; `0x00462114` is not a function; next modeled function is `sub_462170` at `0x00462170` size `0xb7`.
- `xrefs_to 0x00462120` reports no xrefs. `xref_query 0x00462120 both` shows only an internal fall-through edge from the first instruction to `0x00462121`, not an incoming caller or pointer.
- A section-mapped PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` found no absolute VA bytes for `0x00462120`, no RVA bytes for `0x00062120`, and no `E8`/`E9` rel32 call/jump target to `0x00462120`.
- Best inference: the bytes are retained executable code, but current evidence does not prove liveness. Treat the range as raw constructor-family evidence, not a callable method.

### Raw PE / caller / pointer evidence
- PE hash checked: MD5 `4247e04e20b65d6414c7238aa8ff5515`; SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- PE sections from the scan: `.text` RVA `0x1000`, virtual size `0x20b4ac`, raw pointer `0x400`, raw size `0x20b600`; `.rdata`, `.data`, and `.rsrc` follow normally.
- For comparison, the same PE scan also found no VA/RVA/rel32 references to no-xref helper `0x004623c0`, matching the existing support-doc caveat.
- The IDA/map-style export at `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.map` has `sub_462170` at `0001:00061170` and `IntAlphaSurface` RTTI entries, but no symbol at `0001:00061120` / `0x00462120`.
- `find_regex` for `AlphaMask|IntAlpha|Surface\.cpp|\.pdb|RSDS|NB10` only returned the RTTI string `.?AVIntAlphaSurface@@`; no `AlphaMaskSurface`, source file, or PDB/source-path breadcrumb was found through the IDA strings cache.
- Best inference: negative pointer/source-breadcrumb evidence is strong enough to reject final callable/source-map promotion, but not enough to ignore the body.

### Constructor behavior and duplicate treatment
- `get_bytes 0x00462114 size 0x5c` shows twelve `0xcc` bytes, then the raw body, then `0xcc` padding after the `ret`.
- `make_signature_for_range 0x00462120-0x00462161` returns a unique signature for the raw constructor body.
- Raw body bytes perform: `push esi`, `mov esi, ecx`, push zero rectangle arguments, store vtable `0x006112ec`, clear offsets `+0x18`, `+0x1c`, `+0x20`, `+0x14`, set byte `+0x24` to `1`, call `0x004b7c50`, return `this`.
- Current `xrefs_to 0x004b7c50` includes the raw call at `0x00462155` with `fn:null`, plus modeled calls from `0x00462170`, `0x00462320`, `0x004623c0`, and other rectangle users.
- Decompilation of active `0x00462170` shows the same zero-state logic in its `a2 <= 0 || a3 <= 0` branch: clear width/height/stride/pixels, set byte `+36`, call `sub_4B7C50(this + 1, 0, 0, 0, 0)`, return `this`.
- Best inference: this is source-authored constructor-family code or a compiler/linker-retained out-of-line default constructor clone. It is not compiler-generated EH cleanup like [UID:0000YM], because it has a normal prologue/return and initializes the object from scratch.

### AlphaMaskSurface vs IntAlphaSurface vs Surface placement
- Evidence for `AlphaMaskSurface.cpp`: the body sits immediately before active `0x00462170`; active `0x00462170` has four code xrefs from `LightObjImageLibConstructor`, `MapPaneInitialize`, and `sub_5A2530`; the zero branch in `0x00462170` duplicates the raw body semantics; file/class/layout docs place the broader constructor/helper/blitter cluster in [UID:0000HF].
- Evidence for `IntAlphaSurface`: the raw body writes vtable `0x006112ec`, whose RTTI names `IntAlphaSurface`; the vtable's first two slots are `0x00463270` and `0x00462260`; destructor/release helpers use the same owned-pixel fields.
- Evidence for broader `Surface`: the alpha layout is render-surface infrastructure and could ultimately fold into a broader render surface module, but no current caller/source/file evidence specifically requires moving this raw body to [UID:0000OC][Surface](by-file/Surface.md).
- Decision: keep current owner/emitter [UID:0000HF]. The vtable/type owner remains [UID:00006K]/[UID:0001XT], but physical source placement for this raw constructor-family evidence is better represented by AlphaMaskSurface until constructor recovery proves otherwise.

### Vtable / layout / type naming
- `get_bytes 0x006112e8 size 0x18` reads locator pointer `0x00641e9c`, slot 0 `0x00463270`, slot 1 `0x00462260`, then two zero slots.
- `xrefs_to 0x006112ec` reports five stores: raw `0x0046212c`, active constructor `0x0046217b`, EH cleanup/view-init chunk `0x00462237`, view initializer `0x00462415`, and destructor reset `0x0046327a`.
- `0x00463270` decompilation resets vtable `0x006112ec`, tests byte `+36`, frees pointer at dword `+5` / offset `+0x14`, clears it, and optionally deletes storage.
- `0x00462260` decompilation tests byte `+36`, frees pointer `+20` / offset `+0x14`, and clears it.
- Decision: current descriptive name `AlphaMaskSurfaceRawDefaultConstructor` is still acceptable because it reflects the physical AlphaMaskSurface constructor cluster. Do not rename it to final `IntAlphaSurface::IntAlphaSurface()` until a caller/source route proves the original declaration.

### Final C++ eligibility
- Metadata currently has an emitter route to [UID:0000HF], and the recommended `85/90` score would make `(85 + 90) / 2 > 85`.
- The active code-entry rule is a minimum gate, not permission to emit weak code.
- Final C++ should remain blank because no function object, caller, symbol, pointer target, or source-breadcrumb proves the raw body must be emitted as a standalone default constructor. Emitting it now would risk duplicating the active constructor's zero branch or choosing the wrong class name (`AlphaMaskSurface` versus `IntAlphaSurface`).
- Keep the explanatory pseudocode in reconstruction notes as non-emitted documentation only.

### Rejected alternatives
- Lower or keep below 85: rejected. The remaining uncertainty is now well bounded and documented: no liveness/source-form proof, but exact bytes, boundaries, behavior, parent route, PE negatives, and rejected alternatives are strong enough for `85/90`.
- Reclassify ignored/non-reconstructable: rejected. The body is custom source-shaped constructor code in `.text`, not padding, EH-only cleanup, CRT/runtime support, or a pure compiler/linker artifact.
- Create an IDA function at `0x00462120`: rejected for this report. No xref or pointer route proves a callable boundary, and the user forbade IDA DB edits.
- Reroute to `IntAlphaSurface`: rejected for now. RTTI owns the vtable, but the raw body's best source placement is the AlphaMaskSurface constructor/helper cluster.
- Reroute to `Surface`: rejected as too broad and less direct than [UID:0000HF].
- Merge into [UID:0000YL]: rejected. Keeping a distinct raw page preserves the no-function/no-xref caveat and prevents pollution of the active callable constructor page.
- Add emitted final C++: rejected for the source-quality reasons above.

## Evidence Standards Used
- IDA MCP: `idb_open`, `lookup_funcs`, `xrefs_to`, `xref_query`, `get_bytes`, `make_signature_for_range`, `decompile`, and `find_regex`.
- Raw PE inspection: PowerShell section parser plus VA/RVA/rel32 scans against `NexusTK.exe`.
- Documentation evidence: required target, related by-file/by-class/by-type/by-memory pages, `by-memory/-coverage-report.md`, `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, `by-project-structure/proposed-source-tree.md`, and the IDA-export map.
- Negative evidence is material here: no function object, no incoming xrefs, no PE pointer/reference, no map symbol, and no source/PDB strings cap final source emission but make the "raw retained constructor evidence" disposition more defensible.

## IDA MCP Facts
- Function/range facts: `0x00462120`, `0x0046212c`, `0x00462160`, and `0x00462161` are not functions; `sub_461FE0` covers `0x00461fe0-0x00462114`; `sub_462170` starts at `0x00462170` size `0xb7`.
- Data/table/padding facts: `0x00462114-0x00462120` and `0x00462161-0x00462170` are `0xcc`; vtable region begins with locator pointer at `0x006112e8`, then slots `0x00463270`, `0x00462260`, `0`, `0`.
- Xref facts: no xrefs to raw start `0x00462120`; vtable base `0x006112ec` has stores at `0x0046212c`, `0x0046217b`, `0x00462237`, `0x00462415`, and `0x0046327a`; active constructor `0x00462170` has four code xrefs.
- Vtable/global/type facts: current IDA strings and map evidence expose `IntAlphaSurface` RTTI, not `AlphaMaskSurface` symbol/source names.
- Negative IDA facts: no function object, no direct callers, no IDA xref to the raw start, and no source/PDB string breadcrumb.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00462120-0x00462161` | [UID:0000YK] `by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md` | raw default-constructor-shaped empty initializer | `TRUE` | [UID:0000HF] | recommend `85/90` | keep raw evidence, final C++ blank |
| `0x00462170-0x00462e03` | [UID:0000YL] | active AlphaMaskSurface constructor/helper aggregate | `TRUE` | [UID:0000HF] | `85/91` | context, no change |
| `0x00462230-0x00462258` | [UID:0000YM] | EH/unwind cleanup | `FALSE` | `NONE` | `85/90` | ignored/generated cleanup, no change |
| `0x004623c0-0x00462514` | [UID:0002NM] | no-xref view initializer/helper | `TRUE` | [UID:0000HF] | `85/89` | context, no change |
| `0x00463270-0x004632b1` | [UID:0000YP] | IntAlphaSurface scalar deleting destructor | `TRUE` | [UID:00006K] | `85/89` | context, no change |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00462120` | no incoming xrefs; only internal fall-through in `xref_query both` | raw start is not proven live |
| `0x0046212c` | data xref to `0x006112ec` | raw body writes IntAlphaSurface vtable |
| `0x00462155` | call to `0x004b7c50` | raw body zero-initializes `RectBounds` at `this+0x04` |
| `0x00462170` | callers `0x004df9a9`, `0x0050442c`, `0x005a288d`, `0x005a2b8e` | active width/height constructor is live |
| `0x006112ec` | stores from raw body, active constructor, cleanup/view helper, destructor | shared alpha-surface vtable family |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion: target page already records raw no-function/no-xref status; [UID:0000HF], [UID:00000C], [UID:0001TP], and [UID:0001XT] all document the same raw constructor caveat and source-family split.
- Existing docs that are stale or incomplete: [UID:0000YK] lacks the current 2026-06-16 PE scan, map/string negative evidence, and explicit "raise to 85 but keep final C++ blank" score rationale.
- Generated/coverage report state: `auto-generated/-ag-memory-coverage.md` lists [UID:0000YK] as emitted through [UID:0000HF]; `project-level/-auto-completion-stats.md` still lists it in Low_Completion and Low_Both at `82/88`.

## Ranked Ownership Analysis

### 1. [UID:0000HF] AlphaMaskSurface by-file
- Evidence for: physical adjacency to live constructor `0x00462170`; same zero-state body as `0x00462170` zero-dimension branch; existing file/class/layout docs already model this constructor/helper cluster; active constructor callers are render/client users of the AlphaMaskSurface family.
- Evidence against: raw body writes RTTI-backed `IntAlphaSurface` vtable and no caller proves an `AlphaMaskSurface::AlphaMaskSurface()` source declaration.
- Decision: best current direct documentation/source owner; keep owner/emitter unchanged.

### 2. [UID:0000K8] / [UID:00006K] IntAlphaSurface
- Evidence for: vtable `0x006112ec` has RTTI for `IntAlphaSurface`; destructor/release slots target `IntAlphaSurface` docs; raw body writes that vtable.
- Evidence against: no caller, symbol, or source breadcrumb ties the raw constructor body to a final `IntAlphaSurface` constructor declaration; the active source cluster is AlphaMaskSurface; using class/type RTTI alone would conflate vtable ownership with physical source placement.
- Decision: keep as important type/vtable context, not current owner for [UID:0000YK].

### 3. [UID:0000OC] Surface / broader render surface module
- Evidence for: layout is generic render-surface infrastructure and may eventually fold with broader surface code.
- Evidence against: less direct than AlphaMaskSurface; no specific xref/source/file evidence points to `Surface.cpp`.
- Decision: reject for this target.

### Proposed new file/grouping
- Proposed owner/name/path: none.
- Likely full contents: existing [UID:0000HF] and [UID:0000K8] nodes already capture the two plausible source placements.
- Candidate related items that belong: [UID:0000YK], [UID:0000YL], [UID:0002NM], [UID:0001TP], [UID:0001TQ], [UID:0001XT], [UID:0000YP] remain the relevant source-family set.
- Candidate related items rejected: [UID:0000YM] remains compiler-generated cleanup; [UID:0000YQ] remains unrelated application error-state cleanup.
- Standalone, narrow, or broad source-file inference: no new source file is justified.

## Negative Evidence Summary
- Checked IDA function lookup at start/middle/end of raw range: no function.
- Checked IDA xrefs to raw start: none.
- Checked raw PE absolute VA/RVA bytes and rel32 call/jump targets for `0x00462120`: none.
- Checked map/export for `sub_462120` or segment offset `00061120`: none; `sub_462170` is present.
- Checked IDA strings for source/PDB/AlphaMask breadcrumbs: none found; only `IntAlphaSurface` RTTI string matched.
- Checked active constructor decompilation: zero branch duplicates raw-body behavior, so emitting a standalone final default constructor remains risky.

## Final Recommendation
- Exact changes recommended:
  - [UID:0000YK] `COMPLETION:85`.
  - [UID:0000YK] `CONFIDENCE:90`.
  - Leave `CANONICAL_OWNER:0000HF`.
  - Leave `RECONSTRUCTABLE:TRUE`.
  - Leave `EMITTER_UIDS:0000HF`.
  - Leave `RECONSTRUCTION_CPP CODE` blank.
- Exact parent assignments recommended: no change; keep [UID:0000HF].
- Exact items left no-owner/non-emitting and why: none in this target.
- Exact future work outside scope: recover a caller/pointer/source breadcrumb for `0x00462120` or the no-xref view initializer; only then consider IDA function creation, final source declaration naming, or final C++ emission.

## Follow-Up Actions
- Supervisor actions:
  - Update [UID:0000YK] header scores to `85/90`.
  - Add a short 2026-06-16 B001 evidence/change note summarizing current IDA MCP, PE scan, map/string negative evidence, and final-C++ blank decision.
  - Replace the `by-memory/-coverage-report.md` row below.
- A-agent actions: none required immediately.
- B001 future research actions: none for this target unless a later caller/source-route pass recovers evidence for `0x00462120`.

### Exact target text summary
Add or merge this summary into [UID:0000YK]'s `Evidence` / `Reconstruction Notes` / `Changes` sections:

```text
2026-06-16 B001 source-quality recheck: current IDA MCP session `b001_0000YK_alphamask_raw_default_constructor_20260616` reconfirmed that `0x00462120-0x00462161` is unique retained raw code bytes, not an IDA function, with no incoming xrefs to the start. `xref_query` shows only internal fall-through inside the raw body; `xrefs_to 0x006112ec` still ties the vtable write at `0x0046212c` to the same IntAlphaSurface vtable family as the active constructor, view helper, cleanup, and destructor. A section-mapped PE scan of `NexusTK.exe` (`sha256 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`) found no absolute VA, RVA, or rel32 call/jump references to `0x00462120`; the IDA-export map has `sub_462170` but no symbol at `0x00462120`. The active `0x00462170` constructor's zero-dimension branch duplicates this raw body's empty owning-surface initialization, so keep this page as source-authored/retained constructor-family evidence under AlphaMaskSurface, raise to `85/90`, and keep final C++ blank until a callable source route is proven.
```

### Support-doc updates
No support-doc updates are required. The related [UID:0000HF], [UID:00000C], [UID:0000K8], [UID:00006K], [UID:0001TP], [UID:0001XT], [UID:0000YL], [UID:0000YM], [UID:0002NM], and [UID:0000YP] pages already carry the AlphaMaskSurface/IntAlphaSurface split caveat and are at or above the parent gate.

### Exact `by-memory/-coverage-report.md` replacement row
Replace the current [UID:0000YK] row under the `0x00462114-0x00462170` region with:

```text
    - [UID:0000YK][0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor](by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md) 0x00462120-0x00462161 | raw constructor-shaped range | AlphaMaskSurfaceRawDefaultConstructor : reconstructable : 85% : strong : Unique retained raw default-constructor-family evidence; no IDA function, symbol, xref, VA/RVA, or rel32 pointer target reaches the start, but the bytes initialize the AlphaMaskSurface/IntAlphaSurface layout, write vtable `0x006112ec`, call zero `RectBounds` init, and mirror the active constructor's zero-size branch. Keep owner/emitter [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md); final C++ remains blank until callable/source-form evidence is recovered.
```

### Validation commands
Run after applying the target and coverage row:

> Executable block R001 was removed from this report and preserved verbatim in [0000YK-alphamask-raw-default-constructor-source-quality-removed.md](0000YK-alphamask-raw-default-constructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result: [UID:0000YK] drops out of Low_Completion/Low_Both, `auto-generated/-ag-memory-coverage.md` continues to route it through [UID:0000HF], and no generated C++ body appears for the target.

## Confidence
- Recommendation confidence: high.
- Score confidence: `85/90` is justified; not higher because raw liveness and exact original source declaration remain unproven.
- Remaining uncertainty: whether this body was an unreferenced `AlphaMaskSurface::AlphaMaskSurface()`, an `IntAlphaSurface` default constructor, or a compiler/linker-retained constructor clone. Current evidence supports the retained raw constructor-family disposition but not final source emission.

## Validator Results
- Commands run for this report: none; report-only assignment and no by-* edits were made.
- IDA/PE validation performed: live MCP and raw PE commands listed in this report.
- Any unresolved validator warnings/errors: none observed because no validator-managed files were edited.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B001/research/0000YK-alphamask-raw-default-constructor-source-quality.md`
- Modified: none outside this research report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0000YK-alphamask-raw-default-constructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:18","uid":"0000YK"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000YK-alphamask-raw-default-constructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0000YK-alphamask-raw-default-constructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000YK"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
