** TARGET-REPORT-UID:0001Q3 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# [UID:0001Q3] g_pVirusChecker Source-Quality Report

Report-only B004 pass for:

- Target: `by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md`
- Required report: `tools/leaser/Agents/Agent-B004/research/0001Q3-g_pVirusChecker-source-quality.md`
- Current mode: implementation callback complete after Gate 1 acceptance. Target/support by-* docs listed below were edited and scoped validators were run. Generated files were read only, and no coverage reports, validator state, lifecycle state, archives, or supervisor ledgers were manually edited.
- MCP requirement: satisfied with live session `e63ee655` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.

## Finalized Report / Current Recommendation

Keep [UID:0001Q3] as the exact four-byte `.data` storage page for the `VirusChecker *` singleton slot, owned by [UID:0000SO][g_pVirusChecker](by-global/g_pVirusChecker.md). The target should remain reconstructable and should still emit through the global page, but its own formal C++ block should stay blank because the exact memory page represents storage/lifecycle evidence, not a separate source declaration body.

Recommended target metadata after implementation:

```text
COMPLETION:86
CONFIDENCE:89
CANONICAL_OWNER:0000SO
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000SO
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
```

The support global [UID:0000SO] is now source-ready for the actual C++ definition:

```cpp
VirusChecker *g_pVirusChecker;
```

That definition should live in `by-global/g_pVirusChecker.md`, emit through [UID:0000P5][VirusChecker](by-file/VirusChecker.md), and complement the already-present `extern VirusChecker *g_pVirusChecker;` in [UID:0000FW][VirusChecker](by-class/VirusChecker.md). This resolves the previous "final declaration placement" blocker without putting code into the exact storage page. Confidence remains capped below 90 on UID0001Q3 because current MCP still finds no normal static activation/startup caller or external singleton consumer.

## Supporting Research

This pass used current documentation as lead material and rechecked the target-specific binary facts with live IDA MCP session `e63ee655`. Older session IDs such as `86fb854e` and earlier A-agent sessions are historical support only; this report's current evidence is from `e63ee655`.

Current support state read:

- `by-global/g_pVirusChecker.md`: `86/90`, owner/emitter [UID:0000P5], blank formal C++; documents the singleton lifecycle and no external consumer caveat.
- `by-file/VirusChecker.md`: `88/89`, source path `NexusTK/security/`, file role as retained optional AhnLab/V3 scanner wrapper.
- `by-class/VirusChecker.md`: `88/89`, formal class C++ already includes `extern VirusChecker *g_pVirusChecker;` and `[[CHILDREN]]`.
- `by-memory/0x005c0460-0x005c0fe1.VirusChecker.md`: `88/89`, aggregate class island, blank formal C++ because exact method bodies live on children.
- `by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md`: `91/91`, formal V3 load/reset/scan C++ already present.
- `by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md`: `87/91`, helper/callback family with source-local path-set policy.
- `by-memory/0x0069bf7c-0x0069bf94.VirusCheckerDynamicLibraryGlobals.md`: `88/90`, formal typed static V3 function-pointer/module-handle declarations.
- `by-memory/0x006310dc-0x006310e4.VirusCheckerVtableData.md`: `86/91`, exact one-slot vtable data.

Executed report leads checked:

- `executed-b-agent-research/B004/0000FW-VirusChecker-class-source-quality.md`: accepted B004 current-MCP cleanup for the class/source route; useful for class/file/global support direction, but this report redoes UID0001Q3 evidence under `e63ee655`.
- `executed-b-agent-research/B002/0001NV-VirusCheckerV3LoadAndScan-empty-emitter-source-quality.md`: accepted method-body support for V3 load/reset/scan and dynamic globals.
- `executed-b-agent-research/B001/00026Z-VideoVirusReadOnlyData.md`: accepted split evidence for the VirusChecker vtable/string neighborhood around `0x006310dc-0x00631184`.
- `executed-b-agent-research/B009/0001Q4-SnowLookupDescriptorStorage-empty-emitter-source-quality.md`: lead for the successor range beginning at `0x0069bf98`.

Generated lead material checked:

- `auto-generated/-ag-research-tracker.md` lists UID0001Q3 as `85/88`, average `86.5`, reconstructable `true`, reports `0`.
- `auto-generated/-ag-memory-coverage.md` routes UID0001Q3 through [UID:0000SO] to `auto-generated/NexusTK/security/VirusChecker.cpp`, with `emits_code:false`.
- `auto-generated/-ag-global-coverage.md` routes [UID:0000SO] through [UID:0000P5] to `auto-generated/NexusTK/security/VirusChecker.cpp`.
- `auto-generated/NexusTK/security/VirusChecker.cpp` command `000000005393`, refreshed `2026-07-03T12:21:25-04:00`, currently contains the class-level `extern VirusChecker *g_pVirusChecker;` and empty emitter markers for [UID:0000SO] and [UID:0001Q3].

## Target

- Target UID: `0001Q3`.
- Target path: `by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md`.
- Entity kind: exact four-byte `.data` singleton pointer storage.
- Current target metadata read before this report: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000SO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000SO`, blank formal C++.
- Queue row at assignment time: `85/88`, combined `86.5`, reconstructable `true`, reports `0`.

## Current Target State

The current target page already records the main facts: zero-filled four-byte storage, constructor publish/fallback clear, ordinary/helper/scalar destructor clears, EH cleanup edge, vtable data ref, no normal startup caller, and owner [UID:0000SO].

Stale current-state issue to repair on implementation: the target/support docs still name older MCP session `86fb854e` as "current". That was true for the prior cleanup but is now historical for this report. The current report evidence should be incorporated as session `e63ee655`, while preserving older sessions as historical evidence where useful.

Current generated output still has UID0001Q3 as an empty emitter marker. That remains expected if the exact by-memory page stays blank. The support global [UID:0000SO] should emit the single definition instead, so the generated file can carry a real global definition without duplicating storage-page code.

## Heuristic / Inference Reanalysis And Validation

### Storage Identity And Boundary

The slot identity is now direct rather than heuristic. MCP `get_bytes` on `0x0069bf7c` size `28` returned all zero bytes across the six V3 dynamic globals and the `g_pVirusChecker` successor slot. MCP `get_int u32le` at `0x0069bf94` returned `0`, and `get_int u32le` at `0x0069bf98` returned `0` for the next range start.

`xrefs_to 0x0069bf94` returned exactly five lifecycle writes/clears. `xrefs_to 0x0069bf95` returned no refs, and `xrefs_to 0x0069bf98` returned a separate data ref from `0x005c21f1` in `sub_5C20E0`, proving the exact four-byte boundary and excluding a wider VirusChecker-owned data span.

### Lifecycle Meaning

The constructor, destructor, clear helper, and scalar deleting destructor all support a source-level singleton pointer, not arbitrary scratch storage:

- Constructor `0x005c0460-0x005c04e0` publishes `this` to `unk_69BF94` at `0x005c0496`, clears it at `0x005c049d` on the adjusted-null path, installs the VirusChecker vtable at `0x006310e0`, initializes container header/count fields, and allocates the set sentinel via `sub_5796D0`.
- Ordinary destructor `0x005c04e0-0x005c059d` restores the vtable, frees V3 module handles when present, clears the first three V3 function pointers, destroys the module-path tree, frees the sentinel, and clears `unk_69BF94` at `0x005c0582`.
- Clear helper `0x005c0eb0-0x005c0ebb` is exactly two instructions: `mov dword ptr unk_69BF94, 0; retn`.
- Scalar deleting destructor `0x005c0ec0-0x005c0f94` repeats the destructor cleanup, clears `unk_69BF94` at `0x005c0f63`, and conditionally frees `this`.

### Activation / Startup Caller Investigation

The unresolved activation question was rechecked rather than carried forward. MCP `xrefs_to` returned no xrefs to constructor `0x005c0460`, ordinary destructor `0x005c04e0`, loader `0x005c05a0`, raw reset helper `0x005c0770`, scanner `0x005c07b0`, or direct insertion helper `0x005c0940`. The clear helper has only the compiler EH edge at `0x0060bc76`, and the scalar deleting destructor is vtable-only through data ref `0x006310e0`.

MCP `find_bytes` found no little-endian pointer patterns for the constructor (`60 04 5c 00`), ordinary destructor (`e0 04 5c 00`), V3 loader (`a0 05 5c 00`), raw reset helper (`70 07 5c 00`), scanner (`b0 07 5c 00`), direct insert helper (`40 09 5c 00`), or clear helper (`b0 0e 5c 00`). It did find expected local patterns for the singleton operand (`94 bf 69 00`) at the five lifecycle instruction immediates, for the scalar deleting destructor slot (`c0 0e 5c 00`) at `0x006310e0`, and for the vtable pointer (`e0 10 63 00`) at the three vptr stores.

Decision: keep the optional/disabled scanner activation caveat and keep confidence below 90. This is not a no-owner result: the local lifecycle, vtable, class/file route, and accepted V3 method bodies prove real retained project source.

### Source Declaration / Formal C++ Decision

The source-facing declaration question is now separable into two files:

- Target by-memory page [UID:0001Q3] should stay blank because `by-structure.md` limits by-memory C++ to code or declarations represented by that exact range. This exact range is the compiler/linker storage slot and lifecycle evidence, not a standalone function body.
- Support global page [UID:0000SO] should carry the source definition `VirusChecker *g_pVirusChecker;`. That matches zero-filled static storage, the singleton lifecycle, and the existing file route through [UID:0000P5].
- Class page [UID:0000FW] should keep the existing `extern VirusChecker *g_pVirusChecker;` declaration because the class source-shape block needs the symbol available while the definition belongs to the global/file support route.

This resolves the old "final declaration placement" blocker without requiring a code block on UID0001Q3.

## Evidence Standards Used

- Current IDA MCP session `e63ee655` is treated as ground truth for addresses, function extents, bytes, integer values, xrefs, disassembly, and decompilation/analysis snippets.
- Current by-* docs and executed reports are treated as lead/support material, not substitutes for this report's MCP pass.
- Generated reports and generated C++ are read-only lead material. They identify route and current emitted shape but must refresh through validators after any accepted callback.
- Ownership was judged by write sites, lifecycle, class/vtable relationships, source-file route, and by-structure emitter rules; consumer refs alone were not used as ownership proof.
- Negative activation evidence was bounded: exact xrefs to relevant starts plus exact little-endian pointer-pattern checks, not broad unbounded listing/callgraph.

## Evidence Checked

Instruction/workflow:

- `tools/leaser/Agents/Agent-B004/goal.md`
- `.codex/skills/ntk-b-agent-workflow/SKILL.md`
- `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
- `by-structure.md`, especially IDA MCP Output Discipline and reconstruction/emitter rules.

Target and support docs:

- `by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md`
- `by-global/g_pVirusChecker.md`
- `by-file/VirusChecker.md`
- `by-class/VirusChecker.md`
- `by-memory/0x005c0460-0x005c0fe1.VirusChecker.md`
- `by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md`
- `by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md`
- `by-memory/0x0069bf7c-0x0069bf94.VirusCheckerDynamicLibraryGlobals.md`
- `by-memory/0x006310dc-0x006310e4.VirusCheckerVtableData.md`

Generated/read-only context:

- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-global-coverage.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `auto-generated/NexusTK/security/VirusChecker.cpp`

Executed reports searched/opened:

- Search terms included `0001Q3`, `g_pVirusChecker`, `0x0069bf94`, `0000SO`, `0000P5`, `0000FW`, and `VirusChecker`.
- Opened relevant reports: B004 `0000FW-VirusChecker-class-source-quality.md`, B002 `0001NV-VirusCheckerV3LoadAndScan-empty-emitter-source-quality.md`, B001 `00026Z-VideoVirusReadOnlyData.md`, and B009 `0001Q4-SnowLookupDescriptorStorage-empty-emitter-source-quality.md`.

MCP calls/results under session `e63ee655`:

- `idb_list`: one active/adopted session `e63ee655`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `1848`.
- `server_health`: `status=ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- `lookup_funcs`: constructor `0x005c0460` size `0x80`; ordinary destructor `0x005c04e0` size `0xbd`; loader `0x005c05a0` size `0x1cd`; `0x005c0770` not a function; scanner `0x005c07b0` size `0x187`; insert helper `0x005c0940` size `0xac`; clear helper `0x005c0eb0` size `0xb`; scalar deleting destructor `0x005c0ec0` size `0xd4`; cleanup `0x005c0fa0` size `0x41`; successor `0x005c0ff0` size `0xac`.
- `get_bytes`: `0x0069bf7c` size `28` all zero bytes; `0x0069bf90` size `16` all zero bytes; `0x006310dc` size `8` bytes `08 3f 65 00 c0 0e 5c 00`.
- `get_int`: `0x0069bf94` `u32le` value `0`; `0x0069bf98` `u32le` value `0`.
- `xrefs_to` / `xref_query`: five refs to `0x0069bf94`; zero refs to `0x0069bf95`; one separate ref to `0x0069bf98`; no refs to the constructor/destructor/load/reset/scan/insert starts; one EH code ref to `0x005c0eb0` at `0x0060bc76`; one vtable data ref to `0x005c0ec0` at `0x006310e0`; three vptr refs to `0x006310e0`.
- `disasm 0x005c0eb0`: two-instruction helper stores zero to `unk_69BF94` and returns.
- `analyze_function 0x005c0460`, `0x005c04e0`, `0x005c0ec0`: confirmed constructor publish/fallback clear, ordinary destructor cleanup/clear, and scalar deleting destructor cleanup/clear.
- `find_bytes`: no pointer patterns for `0x005c0460`, `0x005c04e0`, `0x005c05a0`, `0x005c0770`, `0x005c07b0`, `0x005c0940`, or `0x005c0eb0`; expected patterns found for `0x0069bf94`, `0x005c0ec0`, and `0x006310e0`.

Non-authoritative check excluded from proof:

- `make_signature_for_range 0x0069bf94-0x0069bf98` returned an all-`FF` data signature despite direct `get_bytes`/`get_int` proving zero-filled storage in the current session. I treat that helper result as unsuitable for this data-slot proof and do not use it for any recommendation.

## Claim And Incorporation Ledger

| Claim ID | Accepted claim / evidence | Destination doc / section | Action | Verification state |
| --- | --- | --- | --- | --- |
| Q3-001 | Current proof source is MCP session `e63ee655`, not older `86fb854e` current-state wording. | Target Evidence Notes; by-global Purpose/Evidence; class/file/aggregate/helper/vtable/dynamic-global support notes. | incorporate | applied: target and all edited support docs now use `e63ee655` as active proof; older `86fb854e` wording is marked historical/then-current. |
| Q3-002 | UID0001Q3 is exact `.data` range `0x0069bf94-0x0069bf98`, zero-filled, `u32le == 0`. | Target Storage/Evidence Notes; by-global Storage/Evidence. | incorporate | applied: target and by-global record zero-filled bytes and `u32le == 0` from `e63ee655`. |
| Q3-003 | Xrefs to `0x0069bf94` are exactly five lifecycle writes/clears: `0x005c0496`, `0x005c049d`, `0x005c0582`, `0x005c0eb0`, `0x005c0f63`. | Target Evidence Notes/Access Sites; by-global Evidence Notes. | incorporate | applied: target and by-global list the five refs and lifecycle roles. |
| Q3-004 | No interior refs to `0x0069bf95`; successor `0x0069bf98` has separate `0x005c21f1` ref in SnowingLayerPane render path. | Target Evidence Notes; by-global Evidence; dynamic-global successor-boundary support. | incorporate | applied: target/by-global record no interior refs and separate successor ref; dynamic-global page preserves UID0001Q3 as exact successor. |
| Q3-005 | Constructor publishes `this`, fallback-clears, installs `0x006310e0` vtable, initializes path set, and calls `sub_5796D0`. | Target Evidence Notes; by-class/by-file/aggregate VirusChecker support. | incorporate | applied: target evidence expanded; support docs preserve constructor/vtable/source route. |
| Q3-006 | Ordinary destructor and scalar deleting destructor free V3 handles, clear selected V3 pointers, destroy path tree/sentinel, and clear `g_pVirusChecker`. | Target Evidence Notes; by-global Evidence; class/file/aggregate support. | incorporate | applied: target and by-global include ordinary/scalar destructor clears; class/file/aggregate support retains cleanup detail. |
| Q3-007 | `0x005c0eb0` is an EH clear helper with only code xref `0x0060bc76`; do not model as a public method. | Target Evidence Notes; helper support doc. | incorporate | applied: target/by-global record two-instruction helper and EH edge; helper doc preserves non-public helper policy. |
| Q3-008 | `0x005c0ec0` is vtable-only through `0x006310e0`; vptr stores hit `0x006310e0` at `0x005c04a7`, `0x005c050c`, `0x005c0eed`. | Target Evidence Notes; vtable support. | incorporate | applied: target/by-global and vtable page record the `e63ee655` vtable bytes/ref relationship. |
| Q3-009 | No direct startup/activation route found: no xrefs or pointer-pattern hits for constructor/destructor/load/reset/scan/insert/clear starts. | Target Score Rationale; by-global/class/file/helper/aggregate confidence caveats. | incorporate | applied: target/global/class/file/helper/aggregate support record the bounded no-activation xref/pointer-pattern evidence. |
| Q3-010 | Reject no-owner/raw-helper route; source owner stays [UID:0000SO] -> [UID:0000P5], class context [UID:0000FW]. | Target Ownership Decision; by-global/file/class notes. | incorporate | applied: metadata preserved, by-global emits through file, class remains source context. |
| Q3-011 | Target formal C++ stays blank because exact by-memory page represents storage/lifecycle evidence only. | Target Reconstruction section. | incorporate | applied: target formal block remains blank and Reconstruction section contains exact no-code proof. |
| Q3-012 | Support global [UID:0000SO] should emit `VirusChecker *g_pVirusChecker;`; class page keeps `extern VirusChecker *g_pVirusChecker;`. | `by-global/g_pVirusChecker.md` formal C++; `by-class/VirusChecker.md` data note. | incorporate | applied: by-global formal block contains `VirusChecker *g_pVirusChecker;`; class block still contains `extern VirusChecker *g_pVirusChecker;`. |
| Q3-013 | Target score should move from `85/88` to `86/89`; confidence remains below 90 due unresolved activation/consumer route. | Target metadata and Score Rationale. | incorporate | applied: target metadata is `86/89`; Score Rationale records unresolved activation/consumer cap. |
| Q3-014 | Do not add third-party import, Application/LanguageMan ownership, direct Ring/Snow owner, raw fixed-address names, or generated `sub_` names. | Target/support rejected alternatives notes. | reject-invalid / not-applicable | applied/excluded-with-reason: no such ownership/code/import changes were made; file support preserves dynamic AhnLab load and no `third_party_embeds/` import. |
| Q3-015 | Validators must be scoped only to by-* files actually edited during callback; no generated/manual coverage edits by B004. | Validator Results / Implementation Tracking Checklist. | incorporate | applied: scoped validators `000000005492` through `000000005500` ran for edited by-* files only; no generated/manual coverage edits were made. |

## Positive Evidence Summary

- Current MCP session `e63ee655` confirms one active NexusTK IDB and healthy server state.
- The slot is zero-filled four-byte `.data` storage, with current `u32le` value `0`.
- The five xrefs to `0x0069bf94` are all local lifecycle writes/clears in `VirusChecker` constructor/destructor/helper/scalar destructor code.
- The exact boundary is confirmed: no interior byte refs at `0x0069bf95`, and the successor `0x0069bf98` has a separate SnowingLayerPane data ref.
- Constructor, destructor, EH helper, scalar deleting destructor, and vtable evidence all agree with a source-level `VirusChecker *` singleton.
- The source route through [UID:0000SO] -> [UID:0000P5] is coherent with current generated coverage and accepted VirusChecker class/file reports.
- [UID:0000FW] already declares `extern VirusChecker *g_pVirusChecker;`, so adding the actual global definition on [UID:0000SO] is source-shape compatible.

## Negative Evidence Summary

- No direct xrefs to constructor `0x005c0460`, ordinary destructor `0x005c04e0`, V3 loader `0x005c05a0`, raw reset helper `0x005c0770`, scanner `0x005c07b0`, or insert helper `0x005c0940`.
- No little-endian pointer-pattern hits for those same starts or for clear helper `0x005c0eb0`.
- No external read/consumer route to `g_pVirusChecker` was found in the focused pass.
- No proof of normal startup activation was found. The likely explanations remain optional/disabled antivirus integration, distribution-specific activation absent from this build, or an unresolved computed/runtime route.
- No evidence supports moving ownership to Application, LanguageMan, SnowingLayerPane, generic library support, AhnLab vendor source, or a raw-helper/no-owner page.
- No evidence supports putting source for UID0001Q3 itself in a separate `.cpp` or adding fixed-address/decompiler-shaped C++ to the target formal block.

## Ranked Ownership Analysis

### 1. [UID:0000SO] `g_pVirusChecker` global under [UID:0000P5] `VirusChecker` file

Evidence for: exact storage slot, lifecycle refs from VirusChecker constructor/destructor/helper/scalar destructor, existing by-global page, existing generated route to `NexusTK/security/VirusChecker.cpp`, and class page `extern` declaration.

Evidence against: no external read/consumer or normal activation route found.

Decision: keep. The missing activation path caps confidence but does not overcome the local lifecycle and source-file evidence.

### 2. Direct class owner [UID:0000FW] `VirusChecker`

Evidence for: constructor/destructor/vtable code is class-local, and the class page already has the `extern` declaration.

Evidence against: a process-wide singleton pointer is better documented as a by-global symbol, with the class page as source context. Direct class ownership would collapse the separate global page and make the storage page less explicit.

Decision: reject as canonical owner for UID0001Q3, keep as class/source-shape support.

### 3. Direct file owner [UID:0000P5] `VirusChecker`

Evidence for: final generated route is `NexusTK/security/VirusChecker.cpp`, and the source definition should live there.

Evidence against: the project already uses [UID:0000SO] as the narrower durable by-global owner. Bypassing the global page would lose the symbol-level singleton documentation.

Decision: reject as direct target owner; keep as emitter/root file through [UID:0000SO].

### 4. No-owner / raw data helper / no-emitter

Evidence for: no external consumer and no activation caller found.

Evidence against: five precise lifecycle refs, constructor publish, destructor clears, vtable/scalar destructor relationship, and accepted VirusChecker source route.

Decision: reject. This is a reconstructable source global with unresolved activation, not abandoned data.

### 5. SnowingLayerPane or successor data owner

Evidence for: immediate successor `0x0069bf98` belongs to SnowingLayerPane descriptor storage.

Evidence against: no refs to `0x0069bf94` from SnowingLayerPane; no interior refs; exact successor starts at `0x0069bf98`.

Decision: reject. The boundary evidence is strong.

## Source Placement

Final source placement remains `NexusTK/security/VirusChecker.cpp` through:

```text
UID0001Q3 by-memory storage -> UID0000SO by-global symbol -> UID0000P5 by-file VirusChecker
```

The class page [UID:0000FW] should remain the class/source-shape owner for constructor/destructor/method declarations, while [UID:0000SO] should provide the actual global definition. No separate source file is justified. No static third-party import applies because this is client-owned wrapper state for dynamically loaded AhnLab/V3 DLLs.

## First-Draft C++ Recommendation

Target [UID:0001Q3] formal `RECONSTRUCTION_CPP CODE` should remain blank.

Exact no-code proof for the target:

- The target range is a four-byte storage slot, not executable code.
- The exact source declaration should not be duplicated on both the memory page and the by-global symbol page.
- `by-structure.md` requires by-memory code to be limited to declarations/code represented by that page's own range; the more precise source declaration home for a process-wide symbol is `by-global`.
- The current generated file already has an `extern` declaration from [UID:0000FW], so the missing source-shape piece is the by-global definition, not a target-body snippet.

Recommended support formal C++ for [UID:0000SO]:

```cpp
VirusChecker *g_pVirusChecker;
```

Do not add an initializer. The zero initialization is represented by ordinary static storage and current bytes; writing `= 0` is behaviorally equivalent but less necessary and may overstate original spelling.

## Final Recommendation

Implement a small source-quality update, not a split or ownership rewrite:

- Target [UID:0001Q3]: raise to `COMPLETION:86`, `CONFIDENCE:89`; keep owner/emitter/reconstructable as `0000SO` / `0000SO` / `TRUE`; keep formal C++ blank; replace older "current MCP session 86fb854e" wording with current `e63ee655` evidence; preserve no-activation cap.
- Support [UID:0000SO]: add formal C++ definition `VirusChecker *g_pVirusChecker;`, update evidence to current `e63ee655`, and note that class [UID:0000FW] keeps the `extern` declaration.
- Support [UID:0000P5] and [UID:0000FW]: sync source-shape notes only if stale, preserving the route `NexusTK/security/VirusChecker.cpp` and the `extern` declaration.
- Optional support docs: update aggregate/helper/vtable/dynamic global pages only where they still present older session wording as current or omit the UID0001Q3 declaration/activation disposition.
- Do not change successor SnowingLayerPane storage, manual coverage reports, generated files, validator state, or lifecycle state.

## Recommended Target Doc Changes

For `by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md`:

- Set `COMPLETION:86`.
- Set `CONFIDENCE:89`.
- Keep `CANONICAL_OWNER:0000SO`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000SO`.
- Keep `EMITTER_POSITION_OPTIONAL:` blank.
- Keep formal `RECONSTRUCTION_CPP CODE` blank.
- Update status/evidence wording so session `e63ee655` is the current MCP proof source; older `86fb854e` becomes historical.
- Preserve and refresh evidence for:
  - zero-filled `0x0069bf94-0x0069bf98`;
  - `u32le == 0`;
  - five lifecycle xrefs;
  - constructor publish/fallback clear at `0x005c0496`/`0x005c049d`;
  - ordinary destructor clear at `0x005c0582`;
  - EH clear helper `0x005c0eb0` with only edge `0x0060bc76`;
  - scalar deleting destructor clear at `0x005c0f63`;
  - vtable slot/ref evidence at `0x006310e0`/`0x005c0ec0`;
  - no direct activation xrefs/pointer-pattern hits;
  - no interior refs and separate successor `0x0069bf98` ref from `0x005c21f1`.
- Replace the stale final-declaration blocker with a source-ready support-global definition note: the exact target remains blank because [UID:0000SO] should emit `VirusChecker *g_pVirusChecker;`.

## Recommended Support Doc Changes

For `by-global/g_pVirusChecker.md`:

- Add formal C++:

```cpp
VirusChecker *g_pVirusChecker;
```

- Consider score update from `86/90` to `88/91` because declaration placement is resolved, current bytes/xrefs are refreshed, and support source shape is now implementation-ready; keep the activation caveat as the confidence cap.
- Update active proof source to MCP session `e63ee655`; historicalize older `86fb854e` current-state wording.
- Preserve owner/emitter route through [UID:0000P5] and no external consumer/no startup activation caveat.

For `by-class/VirusChecker.md`:

- Keep metadata `88/89`, owner/emitter [UID:0000P5], reconstructable `TRUE`.
- Keep the existing formal class C++ block unchanged, including `extern VirusChecker *g_pVirusChecker;`.
- Update notes only if stale: the extern declaration is the header/class-facing declaration, while [UID:0000SO] should own the definition.
- If active "current MCP session 86fb854e" wording remains, historicalize it and add current `e63ee655` evidence where the singleton is discussed.

For `by-file/VirusChecker.md`:

- Keep metadata and source path unchanged.
- Sync the file role/source-output note to say `g_pVirusChecker` now has a support-global source definition through [UID:0000SO] if the callback applies the global C++.
- Preserve optional/disabled activation caveat and no third-party import policy.

For `by-memory/0x005c0460-0x005c0fe1.VirusChecker.md`, `by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md`, and `by-memory/0x006310dc-0x006310e4.VirusCheckerVtableData.md`:

- Edit only if stale active wording conflicts with this report.
- Preserve constructor/destructor/helper/scalar/vtable evidence and activation cap.
- Do not add method bodies, vtable bytes, or scalar deleting destructor source for UID0001Q3.

For `by-memory/0x0069bf7c-0x0069bf94.VirusCheckerDynamicLibraryGlobals.md`:

- No required code change; it already emits typed static globals.
- Optional evidence sync only if the successor-boundary note still presents old session `86fb854e` as current.

## Score And Metadata Recommendation

Target [UID:0001Q3]:

- Before: `85/88`.
- Recommended: `86/89`.
- Owner/emitter: unchanged `CANONICAL_OWNER:0000SO`, `EMITTER_UIDS:0000SO`.
- Reconstructable: unchanged `TRUE`.
- Formal C++: unchanged blank.

Rationale:

- Completion improves to `86` because this pass refreshes all target-specific lifecycle facts under current MCP session `e63ee655` and resolves the declaration-placement blocker through [UID:0000SO] rather than leaving it as future work.
- Confidence improves to `89` because direct bytes/xrefs/body analysis/negative pointer-pattern evidence strongly confirm singleton identity, exact range, and source route.
- Confidence should not reach `90+` because no normal startup/activation route or external singleton consumer was found after the bounded current-MCP xref and pointer-pattern checks.

Support [UID:0000SO]:

- Current: `86/90`.
- Recommended: `88/91` if the formal global definition is applied.
- Reason: [UID:0000SO] becomes the implementation-ready source-definition home while the target memory page remains evidence-only.

No other metadata changes are required. If support docs already contain the same-or-greater detail by callback time, mark those items `already-present` rather than editing.

## Open Questions With Attempted Resolution

### Is the singleton constructed during normal startup?

Attempted resolution: current MCP `xrefs_to` and `find_bytes` checked constructor, destructor, loader, reset, scanner, insert, and clear starts. No direct xrefs or pointer-pattern routes were found.

Disposition: unresolved with evidence. This caps confidence and supports the optional/disabled antivirus integration inference. It does not block source ownership, declaration, or reconstructability.

### Is there an external consumer/read route for `g_pVirusChecker`?

Attempted resolution: current refs to `0x0069bf94` are exactly the five lifecycle writes/clears. No external consumer route was found in the current xref set.

Disposition: unresolved/no consumer found. Keep the caveat; do not use it to mark the global dead because constructor/destructor lifecycle proves it is source-authored singleton storage.

### Should UID0001Q3 emit C++?

Attempted resolution: by-structure source homes and generated output were checked. The class page already emits `extern VirusChecker *g_pVirusChecker;`, while [UID:0000SO] is the appropriate symbol-definition page.

Disposition: no. UID0001Q3 stays blank; [UID:0000SO] should emit `VirusChecker *g_pVirusChecker;`.

### Should the target split or merge with adjacent dynamic globals or Snowing storage?

Attempted resolution: current bytes and xrefs show `0x0069bf7c-0x0069bf94` is the six-dword V3 dynamic global cluster, `0x0069bf94-0x0069bf98` is the singleton pointer, and `0x0069bf98` is successor SnowingLayerPane storage.

Disposition: no split/merge. Existing exact boundaries are correct.

## Validator Results

Scoped validators were run after the implementation callback for every edited by-* file. All exited `0` with `ok: 1`.

| File | Command | command_id | command_timestamp | Exit | ok | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| `by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md` | `python .\tools\validator.py --mode file --file by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md --apply --queue-timeout 240` | `000000005492` | `2026-07-03T14:19:02-04:00` | `0` | `1` | completion/confidence updated to `86/89`; generated refresh deferred. |
| `by-global/g_pVirusChecker.md` | `python .\tools\validator.py --mode file --file by-global/g_pVirusChecker.md --apply --queue-timeout 240` | `000000005493` | `2026-07-03T14:19:03-04:00` | `0` | `1` | completion/confidence updated to `88/91`; registry updated blank -> block; generated refresh deferred. |
| `by-class/VirusChecker.md` | `python .\tools\validator.py --mode file --file by-class/VirusChecker.md --apply --queue-timeout 240` | `000000005494` | `2026-07-03T14:19:05-04:00` | `0` | `1` | stats incremental noop; generated refresh deferred. |
| `by-file/VirusChecker.md` | `python .\tools\validator.py --mode file --file by-file/VirusChecker.md --apply --queue-timeout 240` | `000000005496` | `2026-07-03T14:19:07-04:00` | `0` | `1` | stats incremental noop; generated refresh deferred. |
| `by-memory/0x005c0460-0x005c0fe1.VirusChecker.md` | `python .\tools\validator.py --mode file --file by-memory/0x005c0460-0x005c0fe1.VirusChecker.md --apply --queue-timeout 240` | `000000005497` | `2026-07-03T14:19:20-04:00` | `0` | `1` | stats incremental noop; generated refresh deferred. |
| `by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md` | `python .\tools\validator.py --mode file --file by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md --apply --queue-timeout 240` | `000000005498` | `2026-07-03T14:19:27-04:00` | `0` | `1` | stats incremental noop; generated refresh deferred. |
| `by-memory/0x006310dc-0x006310e4.VirusCheckerVtableData.md` | `python .\tools\validator.py --mode file --file by-memory/0x006310dc-0x006310e4.VirusCheckerVtableData.md --apply --queue-timeout 240` | `000000005499` | `2026-07-03T14:19:34-04:00` | `0` | `1` | reference index add for UID0001Q3; generated refresh deferred. |
| `by-memory/0x0069bf7c-0x0069bf94.VirusCheckerDynamicLibraryGlobals.md` | `python .\tools\validator.py --mode file --file by-memory/0x0069bf7c-0x0069bf94.VirusCheckerDynamicLibraryGlobals.md --apply --queue-timeout 240` | `000000005500` | `2026-07-03T14:19:38-04:00` | `0` | `1` | stats incremental noop; generated refresh deferred. |

Validator side effects reported: projected stats update on each run; target stats row removals for UID0001Q3; by-global stats row update for UID0000SO; by-global autogen registry hash/type update; vtable reference-index add for UID0001Q3. These were validator-owned side effects, not manual edits.

Generated freshness: `auto-generated/NexusTK/security/VirusChecker.cpp` is read-only and now has header `validator-command-id: 000000005497`, `validator-refreshed-at: 2026-07-03T14:19:20-04:00`, `validator-refresh-source: deferred-generated-refresh`. It contains the expected `// UID:0000SO | by-global/g_pVirusChecker.md | Completion:88 | Confidence:91` block and `VirusChecker *g_pVirusChecker;`. This generated timestamp is newer than the by-global code-change validator command `000000005493` and matches a later validator-generated refresh.

## Changed Files

- Changed during implementation callback:
  - `by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md`
  - `by-global/g_pVirusChecker.md`
  - `by-class/VirusChecker.md`
  - `by-file/VirusChecker.md`
  - `by-memory/0x005c0460-0x005c0fe1.VirusChecker.md`
  - `by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md`
  - `by-memory/0x006310dc-0x006310e4.VirusCheckerVtableData.md`
  - `by-memory/0x0069bf7c-0x0069bf94.VirusCheckerDynamicLibraryGlobals.md`
  - `tools/leaser/Agents/Agent-B004/research/0001Q3-g_pVirusChecker-source-quality.md`
- Generated files were read only. `auto-generated/NexusTK/security/VirusChecker.cpp` refreshed through validator side effects and now shows the UID0000SO definition.
- No manual coverage reports, project-level generated files, validator state, report lifecycle/archive state, or supervisor ledgers were manually edited.
- Leases used: B004 leased the eight edited by-* files before editing. Release after validation reported `Rejected[No active lease]` for each path because the short leases had already expired during the validator batch; `tools/leaser/Agents/current_leases.md` was then read and showed no active B004 leases.

## Implementation Tracking Checklist

- [x] Supervisor Gate 1 validates this report before any by-* implementation callback. Proof: supervisor callback accepted this report for implementation.
- [x] Target `by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md`: set `COMPLETION:86`, `CONFIDENCE:89`, keep `CANONICAL_OWNER:0000SO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000SO`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++. Proof: validator `000000005492`, exit `0`, `ok: 1`.
- [x] Target: update active evidence to MCP session `e63ee655`; historicalize older `86fb854e` "current" wording. Proof: target Status/Evidence/Changes now use `e63ee655` as active proof and `86fb854e` as older/historical.
- [x] Target: incorporate zero-filled bytes/current value, exact five lifecycle xrefs, no interior refs, separate successor `0x0069bf98` ref, constructor publish/fallback clear, ordinary/helper/scalar destructor clears, EH cleanup edge, vtable data ref, and no activation xref/pointer-pattern evidence. Proof: target Evidence Notes updated; validator `000000005492`, exit `0`, `ok: 1`.
- [x] Target: replace stale final-declaration blocker with exact no-code proof: target stays blank because [UID:0000SO] owns the source definition. Proof: target Reconstruction section updated and formal block remains blank.
- [x] Support `by-global/g_pVirusChecker.md`: add formal C++ `VirusChecker *g_pVirusChecker;`, update active proof to `e63ee655`, preserve no external consumer/no activation cap, and apply metadata `88/91`. Proof: by-global formal block populated; validator `000000005493`, exit `0`, `ok: 1`.
- [x] Support `by-class/VirusChecker.md`: verify the existing `extern VirusChecker *g_pVirusChecker;` remains; sync notes only if stale or contradictory; do not alter method-body children. Proof: class formal block unchanged; data/change notes clarify extern vs by-global definition; validator `000000005494`, exit `0`, `ok: 1`.
- [x] Support `by-file/VirusChecker.md`: sync source-output note if stale so `g_pVirusChecker` definition routes through [UID:0000SO] into `NexusTK/security/VirusChecker.cpp`. Proof: proposed contents/evidence/change notes updated; validator `000000005496`, exit `0`, `ok: 1`.
- [x] Optional support `by-memory/0x005c0460-0x005c0fe1.VirusChecker.md`, `by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md`, `by-memory/0x006310dc-0x006310e4.VirusCheckerVtableData.md`, and `by-memory/0x0069bf7c-0x0069bf94.VirusCheckerDynamicLibraryGlobals.md`: edit only if active stale session/declaration wording remains. Proof: stale active session wording was present and synced to `e63ee655`/historical `86fb854e`; validators `000000005497`, `000000005498`, `000000005499`, and `000000005500`, all exit `0`, `ok: 1`.
- [x] Preserve rejected alternatives and negative evidence: no no-owner/raw-helper route, no Application/LanguageMan/Snowing owner, no separate source file, no third-party import, no startup caller, no external singleton consumer, no target formal C++ body, and no observed activation route. Proof: metadata/source route preserved; no generated/fixed-address/decompiler source added; target/global/support notes retain no-activation/no-consumer caveats.
- [x] Run scoped validators from `source-3/project-documentation` for each edited by-* file using `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`. Proof: validator table above lists all eight edited by-* files, command IDs, timestamps, exit `0`, and `ok: 1`.
- [x] If [UID:0000SO] code is added, check generated `auto-generated/NexusTK/security/VirusChecker.cpp` freshness after validator refresh; do not hand-edit generated output. Proof: generated file read-only check shows `validator-command-id: 000000005497`, refreshed `2026-07-03T14:19:20-04:00`, and contains `VirusChecker *g_pVirusChecker;` under UID0000SO.
- [x] Do not edit generated files, project-level generated files, manual coverage reports, validator state, report lifecycle/archive state, or supervisor ledgers. Proof: only by-* docs and this report were manually edited; generated/project/validator updates were validator-owned side effects.
- [x] Do not run `execute_report`, dry-run/probing variants, registry lifecycle commands, manual report moves, or archive commands. Proof: only scoped file validators and read-only file checks were run.
- [x] During callback, update this report's Claim And Incorporation Ledger with `applied`, `already-present`, or `excluded-with-reason` proof for each accepted claim. Proof: Q3-001 through Q3-015 ledger rows updated above.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000005515","destination_path":"executed-b-agent-research/B004/0001Q3-g_pVirusChecker-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0001Q3-g_pVirusChecker-source-quality.md","timestamp":"2026-07-03T14:34:05-04:00","uid":"0001Q3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
