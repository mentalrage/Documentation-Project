** TARGET-REPORT-UID:0002TO **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B005 Source Quality Report: 0002TO HumanImageLibConstructor

Target: `[UID:0002TO] by-memory/0x004d2720-0x004d4aca.HumanImageLibConstructor.md`  
Assignment type: report-only B-agent research  
Date: 2026-06-25  
IDA MCP: used, available, and responsive

## Current State

The target currently records `COMPLETION: 86`, `CONFIDENCE: 88`, `CANONICAL_OWNER: 00006A`, `RECONSTRUCTABLE: TRUE`, and `EMITTER_UIDS: 00006A`. The owner and emitter route are correct: this constructor belongs under `[UID:00006A] HumanImageLib` and should emit through the HumanImageLib class/file route, not through DATFile, ImageFrameTable, ImageLib, VectorHelpers, or a generated vtable/RTTI page.

The target's current "blank final C++ below source gate" language is stale under the current project gate. With `86/88` and a valid nonblank emitter route, the target is numerically above the minimum source gate. The reason to keep formal `RECONSTRUCTION_CPP` blank is not the numeric gate; it is a target-specific no-code proof: the constructor is a 9130-byte, 238-block, complexity-86 loader constructor with no local `HumanImageLib`, `ProtectedArray`, or old-human row UDT declarations in the IDB, unresolved source member names for cached resources/frame handles, and still-raw shared helper names and row layouts.

Generated status is also stale relative to the source page. `auto-generated/-ag-research-tracker.md` still lists `0002TO` as `75/86` and not covered, and `auto-generated/-ag-coverage-report-by-memory.md` still lists the by-memory row at `75%`. These generated files should not be edited by hand; they should refresh through the normal validator/report-execution workflow after supervisor acceptance.

## Evidence Checked

I used the live IDA MCP endpoint at `http://127.0.0.1:13337/mcp`, session `2ac3cddc-00db-4fcb-a6ed-f0f9f10258a2`, active database `80de0a67`. `server_health` reported the active module as `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, and Hex-Rays ready. `idb_list` reported `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` as the active IDB.

Source/support pages checked in this pass:

- Target by-memory page `0x004d2720-0x004d4aca.HumanImageLibConstructor.md`.
- Guidance page `by-memory/-guidance.md`.
- `by-class/HumanImageLib.md`, `by-file/HumanImageLib.md`, and `by-memory/0x004d2720-0x004dac40.HumanImageLibLocalMethodCluster.md`.
- Layout/vtable/global support pages: `HumanImageLibLayout`, `HumanImageLibVtable`, `g_pHumanImageLib`, singleton slot `0x0069b43c`, destructor `0x004d4ad0`, shared load-error flag `0x0069b420`, and VectorHelpers `0x004e6ae0-0x004e70e9`.
- Loader/dependency support pages: `LoadImageFrameTable_004D0F50`, `ImageFrameTable`, `ImageLib`, `EPFImageResources`, and `DATFile`.
- Prior executed B004 HumanImageLib class report was used only as a documentation lead because that report's own MCP was unavailable; current conclusions below are backed by this pass's live MCP and current support pages.

Live MCP checks performed:

- `lookup_funcs` confirmed `sub_4D2720` at `0x004d2720`, size `0x23aa`; `0x004d4aca` is not a function; `sub_4D4AD0` starts at `0x004d4ad0`, size `0x497`. The constructor range ends exactly at `0x004d4aca`, with the known 6-byte gap before the destructor.
- `xrefs_to` confirmed no direct xrefs to `0x004d2720`; one destructor xref from scalar deleting destructor `0x004e6466`; four singleton-slot refs to `0x0069b43c`; two HumanImageLib vtable-slot refs to `0x0061b6d4`; 25 xrefs to `LoadImageFrameTable` at `0x004d0f50`, including 18 constructor calls; two constructor calls to `sub_4E6AE0`; and six constructor calls to `sub_4E6C50`.
- `analyze_function` and `analyze_component` confirmed constructor metrics and callees: DATFile-style open/read/close/size helpers, `LoadImageFrameTable_004D0F50`, VectorHelpers `sub_4E6AE0`/`sub_4E6C50`, allocation/free/memmove/security-cookie helpers, and no callers.
- `entity_query` over `0x004d2720-0x004dac40` confirmed the local cluster inventory: constructor, destructor, old-human local helpers at `0x004d8ee0`, `0x004d8ef0`, `0x004d8f40`, `0x004d8fb0`, `0x004d90e0`, `0x004d9180`, `0x004da850`, and the next function at `0x004dac40`.
- `disasm` confirmed the constructor prologue, singleton write/clear, HumanImageLib vtable store, ProtectedArray vtable initialization, lower table helper calls, frame-table calls, and fatal error paths.
- `search_text` and `get_bytes` confirmed the important literal strings in the constructor/string block, including lowercase `.txt` tables, uppercase `.TBL` files, and UTF-16 EPF names.
- `search_structs` and `type_query` confirmed no local IDA structs/types named `HumanImageLib`, `HeadInfo`, `BodyInfo`, `WeaponInfo`, `Acc2Info`, or `ProtectedArray`.

## Blocker Reanalysis

### Singleton, Vtable, and Error-State Interpretation

The constructor writes the HumanImageLib singleton slot at `0x0069b43c` early in the prologue. At `0x004d277b` it stores `edi` adjusted back to the containing object, or clears the slot at `0x004d2782` on the null path. Current `xrefs_to` confirms the same four-slot pattern already documented: constructor store/clear, destructor clear, and the clear helper at `0x004e5b80`. This supports the descriptive global route but does not justify duplicate constructor-owned global C++.

The constructor stores `??_7HumanImageLib@@6B@` at `[edi]` at `0x004d278c`. Current support remains correct: vtable slot `0x0061b6d4` is the scalar deleting destructor, `+0x04` is shared/inherited `0x004f4b10`, and `+0x08` is `nullsub_18`. The vtable and adjacent ProtectedArray vtables are generated binary artifacts, not separate source C++ emitters for this constructor.

The load-error flag at `0x0069b420` is not HumanImageLib-owned. It is shared image-library state owned by `ImageLib`/`[UID:0000K2]`, with constructor and helper writes during table loading. The current `ImageLibraryLoadErrorFlag` page body and metadata already route it to ImageLib, but its Item Summary still contains stale "no directly justified parent yet" wording. That summary should be cleaned up if a support-doc edit is accepted.

### Field, Table, and Resource Names

The constructor initializes the HumanImageLib object's array fields through ProtectedArray vtables at these offsets:

- `+0x004` HeadInfo array, current source vocabulary `headArray`.
- `+0x020` HeadInfo special array, current source vocabulary `headSpecialArray`.
- `+0x03c` BodyInfo array, current source vocabulary `bodyArray`.
- `+0x05c` CoatInfo array, current source vocabulary `coatArray`.
- `+0x080`, `+0x0a0`, `+0x0c0`, `+0x0e0`, `+0x100`, `+0x120` WeaponInfo arrays, current source vocabulary `swordWeaponArray`, `spearWeaponArray`, `bowWeaponArray`, `fanWeaponArray`, `shieldWeaponArray`, `arrowWeaponArray`.
- `+0x140` FaceInfo array, `+0x15c` Acc1Info array, `+0x17c` HairInfo array, `+0x19c` Acc2Info array.
- `+0x1c0` HelmetInfo array, `+0x1e0` MantleInfo array, `+0x200` NecklaceInfo array, `+0x220` ShoeInfo array.

The lower table helper calls are now current-session confirmed:

- `headtable.txt` loads into `[edi+0x004]` through `sub_4E6AE0` at `0x004d2b0e`.
- `headsptable.txt` loads into `[edi+0x020]` through `sub_4E6AE0` at `0x004d2b45`.
- `swordtable.txt`, `speartable.txt`, `bowtable.txt`, `fantable.txt`, `shieldtable.txt`, and `arrowtable.txt` load through `sub_4E6C50` into `[edi+0x080]`, `[edi+0x0a0]`, `[edi+0x0c0]`, `[edi+0x0e0]`, `[edi+0x100]`, and `[edi+0x120]` respectively at `0x004d2d74`, `0x004d2dae`, `0x004d2de8`, `0x004d2e22`, `0x004d2e5c`, and `0x004d2e96`.

The constructor's literal/resource block confirms these frame/resources strings: `HEAD.EPF`, `HEADSP.EPF`, `BODY.EPF`, `SWORD.EPF`, `SPEAR.EPF`, `BOW.EPF`, `FAN.EPF`, `SHIELD.EPF`, `ARROW.EPF`, `FACE.EPF`, `HAIR.EPF`, `ACE1.EPF`, `ACE2.EPF`, `HELMET.EPF`, `MANTLE.EPF`, `NECLACE.EPF`, `SHOES.EPF`, and `COAT.EPF`. The binary spelling `NECLACE` should be preserved. The same block also contains `EMOTION.EPF`, `EMOTIOSP.EPF`, `ACC2DRW.TBL`, and `HAIRCOL.TBL`; `search_text` also found `.TBL` references including `SHIELD.TBL`, `XDRWORD.TBL`, `XDRWORD2.TBL`, and `SHOES.TBL`.

This is enough to improve the target documentation, but not enough to emit final C++. The source member names for cached resource fields and the 18 frame-library handles are still accepted vocabulary, not direct symbols. Current support places frame handles at `+0x268` through `+0x2ac` and cached/auxiliary resource fields around the `+0x24c` to `+0x264` area, but final source declarations and declaration order are not locked by a local UDT or original source symbol. The constructor's string evidence identifies resource spellings and call order; it does not by itself prove the exact source field names.

### Loader Roles

`DATFile` remains a dependency, not the owner of the constructor. Constructor calls to `sub_49C180`, `sub_49C240`, `sub_49C2F0`, `sub_49C310`, `sub_49C370`, and `sub_49C4A0` line up with DAT open/close/size/read/read-line/read-all operations from `by-file/DATFile.md`, but they do not change the HumanImageLib source route.

`LoadImageFrameTable_004D0F50` is correctly owned by `ImageFrameTable`/`[UID:0000K1]`. Current `xrefs_to` shows 25 total call sites and 18 constructor calls. The constructor owns the decision to call it for HumanImageLib fields and resource names, while the parser/table allocator remains in ImageFrameTable.

`sub_4E6AE0` and `sub_4E6C50` are correctly routed to `ImageLibVectorSupportHelpers`/VectorHelpers, not the constructor. The constructor owns the call sites and field mapping; the helper bodies own the shared 12-byte/block-array loading behavior. Their current working names are good documentation vocabulary but still not final source-quality function names for C++ emission.

`EPFImageResources` is an umbrella documentation route, not the code owner for this constructor. EPF/DAT string evidence should be cited in the constructor and loader docs, while code emission remains in HumanImageLib, ImageFrameTable, ImageLib, VectorHelpers, and DATFile according to the existing ownership split.

### Child and Split Issues

The constructor itself has a clean function boundary: `0x004d2720-0x004d4aca`, with the destructor starting at `0x004d4ad0`. It has no direct xrefs in the IDB. There is no evidence that a lower local helper should be split out of the constructor range.

The broader `HumanImageLibLocalMethodCluster` remains the right container for nearby old-human local functions. Current `entity_query` confirms the functions after the destructor at `0x004d8ee0`, `0x004d8ef0`, `0x004d8f40`, `0x004d8fb0`, `0x004d90e0`, `0x004d9180`, and `0x004da850`; `0x004dac40` is the next function after the cluster and should stay outside the HumanImageLib local cluster. These lower functions are child/split work for the cluster and their own pages, not blockers to documenting the constructor's exact range and roles.

### C++ Emit Blocker

Formal `RECONSTRUCTION_CPP` should remain blank for this target. This is a no-code proof, not a fallback excuse:

- The numeric source gate is met, but the target lacks required source-quality declarations.
- Live `search_structs` found no local `HumanImageLib` UDT.
- Live `type_query` found no local `HeadInfo`, `BodyInfo`, `WeaponInfo`, `Acc2Info`, or `ProtectedArray` declarations.
- The constructor decompile is raw-local heavy and was only summarized/truncated by `analyze_function`; the function is large enough that a source-quality reconstruction would depend on many unproven helper prototypes and row structs.
- Shared helper names `sub_4E6AE0` and `sub_4E6C50` remain working names, not final source names.
- Frame-handle/cached-resource source member names and declaration order are not locked.
- Exception cleanup/fatal error paths are present and important, but current evidence does not prove original source control-flow shape.

The correct implementation move is to document this no-code proof in the target, keep C++ blank, and raise the target score only to the level justified by binary evidence and resolved ownership.

## Ranked Ownership and Source Placement

1. `[UID:00006A] HumanImageLib` is the canonical owner and source emitter for the constructor. Keep `CANONICAL_OWNER: 00006A`, `RECONSTRUCTABLE: TRUE`, and `EMITTER_UIDS: 00006A`.
2. `[UID:0000JY] by-file/HumanImageLib.md` is the file route. The constructor evidence should roll up to the HumanImageLib file/class pages after supervisor acceptance.
3. `[UID:00017A] HumanImageLibLocalMethodCluster` is a container/neighbor inventory, not the constructor owner and not a C++ emitter for this target.
4. `[UID:0000K1] ImageFrameTable`, `[UID:0000K2] ImageLib`, VectorHelpers, and DATFile are dependency owners for called loaders, shared state, and archive primitives.
5. Generated vtable/RTTI and ProtectedArray artifacts should stay documented as generated binary support, not receive constructor source code.

## Recommendation

Update the target page after supervisor acceptance as follows:

- Raise to `COMPLETION: 89`, `CONFIDENCE: 90`.
- Keep owner/emitter/reconstructability unchanged.
- Replace "below source gate" wording with "above the numeric source gate but intentionally blank under target-specific no-code proof".
- Add a B005 current MCP evidence section with the session/database, boundary, xrefs, helper calls, resource strings, and local type-query negative results.
- Add the confirmed field/table/resource mapping for the lower helper-loaded arrays and the 18 EPF resources.
- Clarify loader ownership: DATFile, ImageFrameTable, ImageLib, and VectorHelpers are dependencies/support owners; HumanImageLib owns the constructor call sequence and field initialization.
- Keep `RECONSTRUCTION_CPP` blank and add the no-code proof above.

Recommended support-doc cleanup if the supervisor accepts broader sync edits:

- In `by-memory/0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag.md`, fix the stale Item Summary wording that still says no parent is justified, since metadata/body route it to `ImageLib`.
- In `by-memory/0x0069b43c-0x0069b440.g_pHumanImageLib.md`, replace stale `95/95` final-code-threshold wording with current code-gate/no-code-proof language.
- Do not hand-edit `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `by-memory/-coverage-report.md`, or any other coverage report. Let validators/report execution refresh them.

Expected validation after implementation:

- Run the file validator for the edited target by-memory page.
- Run file validators for any accepted support-doc cleanup pages.
- Refresh generated tracker/coverage outputs only through the normal validator/report-execution workflow.
- Confirm the generated by-memory coverage row and research tracker no longer show stale `75/86` target data after report execution.

## Implementation Tracking Checklist

- [x] Update `by-memory/0x004d2720-0x004d4aca.HumanImageLibConstructor.md` metadata to `COMPLETION: 89` and `CONFIDENCE: 90`, keeping `CANONICAL_OWNER: 00006A`, `RECONSTRUCTABLE: TRUE`, and `EMITTER_UIDS: 00006A`. Proof: target header now records `89/90`, owner/emitter/reconstructable are unchanged, and validator command `000000001660` returned `completion_update`, `confidence_update`, `canonical_owner_update`, exit code `0`, and `ok: 1`.
- [x] Replace target wording that says C++ is blank because it is below the source gate with wording that says the numeric gate is met but formal C++ remains blank under a target-specific no-code proof. Proof: target Item Summary, Parent Gate Rationale, Reconstructability Notes, and 2026-06-25 Changes now state the current gate/no-code-proof distinction.
- [x] Add the B005 current-MCP evidence block for boundary, xrefs, singleton/vtable/error-state facts, helper calls, resource strings, local type-query results, and child/split inventory. Proof: target section `B005 Current MCP Evidence` records database `80de0a67`, boundary, xrefs, helper calls, local cluster inventory, and negative local type/struct lookup results.
- [x] Add the confirmed field/table/resource mapping for `headtable.txt`, `headsptable.txt`, the six weapon `.txt` tables, and the 18 EPF resources while preserving binary spellings such as `NECLACE`. Proof: target section `Confirmed Field / Table / Resource Mapping` records offsets, accepted field vocabulary, table helper sites, EPF/TBL strings, and binary spellings `NECLACE` and `EMOTIOSP`.
- [x] Add the loader ownership paragraph distinguishing HumanImageLib constructor ownership from DATFile, ImageFrameTable, ImageLib, VectorHelpers, EPF umbrella, and generated vtable/RTTI artifacts. Proof: target section `Loader / Source Ownership` now preserves accepted owner/dependency split and rejected owner reroutes.
- [x] Keep `RECONSTRUCTION_CPP` blank and record the no-code proof based on absent local UDTs, unresolved row/helper/source member declarations, and constructor complexity. Proof: target formal code block remains empty and `Reconstructability Notes` lists absent local UDTs, unresolved helper/member/row declarations, 9130-byte raw-local-heavy complexity, and no example/draft C++.
- [x] If accepted, clean up stale support-doc wording in the shared load-error flag and singleton-slot pages without editing generated files by hand. Proof: `by-memory/0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag.md` summary/reconstruction notes now route through ImageLib and remove the stale no-parent/current-gate contradiction; `by-memory/0x0069b43c-0x0069b440.g_pHumanImageLib.md` now uses current no-code-proof wording. Directly contradictory local-cluster wording was also synced in `by-memory/0x004d2720-0x004dac40.HumanImageLibLocalMethodCluster.md`.
- [x] Run file validators for every edited source doc and fix any validator issues. Proof: validators run from `source-3/project-documentation`: `000000001660` for the constructor target, `000000001661` for `ImageLibraryLoadErrorFlag`, `000000001662` for `g_pHumanImageLib`, and `000000001663` for `HumanImageLibLocalMethodCluster`; all returned exit code `0`, `ok: 1`, and `generated_refresh: completed`. Remaining missing-ref/stale-registry diagnostics are pre-existing generated/manual coverage issues, not introduced by this callback.
- [x] Refresh or verify generated tracker/coverage outputs only through the approved validator/report-execution workflow after supervisor acceptance. Proof: no generated files or coverage reports were manually edited. The scoped validators refreshed validator-owned generated files with `generated_refresh_command_id` values matching commands `000000001660` through `000000001663`; final report execution is still supervisor-owned.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0002TO-HumanImageLibConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0002TO-HumanImageLibConstructor-source-quality.md","timestamp":"2026-06-25T15:04:13","uid":"0002TO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
