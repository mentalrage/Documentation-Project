** TARGET-REPORT-UID:0002YC **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002YC RadioGroupControlPane Scalar Deleting Destructor Source-Quality Report

## Finalized Report / Current Recommendation

- Report phase: accepted ordinary/support implementation, C2YC-35 source-channel state, and supervisor-owned Gate 2B are complete and reconciled. The independent supervisor Gate 2B passed for exact pre-IDA report artifact `2344A7DF...B0F48`; every actionable/protected IDA row is now `APPLIED_VERIFIED` or `NO_CHANGE_VERIFIED` with saved/reopened readback. B005 only reconciled this report from the supervisor audit/catalog evidence and did not perform any migration, acquire a lease, run validator command `000000017510`, mutate or save IDA, edit any ordinary/coverage/generated/audit/catalog/supervisor/lifecycle file, or execute/archive/move this report.
- Target: [UID:0002YC] `by-memory/0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor.md`.
- Exact recommendation: raise UID0002YC from `87/89` to `93/95`; keep semantic `CANONICAL_OWNER:0000BI`; change `RECONSTRUCTABLE:TRUE` to `FALSE`; blank `EMITTER_UIDS`, emitter position, formal CPP, and formal H; retain `Nested:0`.
- Source reconstruction: exact ordinary-destructor child [UID:0004X2] `[0x00495fd0,0x00496005)` is registered under class UID0000BI. That child, not UID0002YC, carries the source-authored `RadioGroupControlPane::~RadioGroupControlPane()` body.
- Compiler boundary: UID0002YC is the MSVC complete-object deleting wrapper. UID0002YB is its two adjusted-this thunks. Neither is hand-authored source. The virtual destructor declaration in UID0000BI plus the new ordinary-destructor body regenerates them.
- Owned child: `RadioGroupControlPane+0x108` is an owned `List *m_options`. Its records are exactly `0x90`/144 bytes and consist of a 16-byte `RectBounds` followed by `wchar_t text[64]`; `RadioGroupOption` is the strongest current human source-facing record name.
- Source route: UID0000BI -> UID0000HY -> `NexusTK/ui/controls/ButtonControlPane.cpp` and sibling `ButtonControlPane.h`. C2YC-35 moved the class declaration byte-for-text from UID0000BI formal CPP to formal H, while UID0004X2 remains the sole out-of-line destructor definition in CPP. The broad `ButtonControlPane.cpp` versus narrower `ChoiceControlPane.cpp` historical split remains a file-level confidence cap, not a target ownership or source-body blocker.
- Remaining workflow is ordered and actor-bounded: supervisor fresh exact-artifact Gate 1 continuity for this post-Gate2B report revision; supervisor final Gate 1/Gate 2 continuity authorization; supervisor-only report execution/archive; and only then supervisor manual-coverage application/validation. No further ordinary callback, Gate 2A implementation pass, or Gate 2B mutation pass is required unless the fresh continuity audit finds drift. The original pre-callback Gate 1, ordinary/support callback, commands 17470-17494, independently observed command 17510 state, generated CPP/H readback, completed C2YC-01..29/C2YC-33/C2YC-34/C2YC-35 evidence, and supervisor Gate 2B readback remain preserved.

## Supporting Research

- Pre-callback target baseline: `by-memory/0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor.md`, SHA256 `848604875C8BF206427E4398BA97A009B3CF3A413F4A12A512AE92DB9B937CB5`, 4700 bytes.
- Pre-callback thunk baseline: `by-memory/0x0049afab-0x0049afc1.RadioGroupControlPaneAdjustorThunks.md`, SHA256 `F480D8148EAB3EA8AD244900C023CCE2379EC578C3A77F37E158901F93824BD8`, 3826 bytes.
- Pre-callback class baseline: `by-class/RadioGroupControlPane.md`, SHA256 `08FA0EF2604BF954A6C1340C55C52712A6E104562B1B9A72DC47A92C4EBD9FC0`, 15104 bytes.
- Pre-callback source-root baseline: `by-file/ButtonControlPane.md`, SHA256 `C0E1AAD38E04376905022E1BE76E35242036F212C29EBF58BFB61A498A93AF2D`, 34008 bytes.
- Pre-callback core-aggregate baseline: `by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md`, SHA256 `1F57388E32D9D8358072DE776AA1E7CD2767C9D8306382E855AE2EA20EC93025`, 30323 bytes.
- Pre-callback destructor-aggregate baseline: `by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md`, SHA256 `6CAE062881EB19473460ED08E9C95BEB88D6D4C928F9F22B397D072F3C6BB99E`, 48668 bytes.
- Pre-callback option-helper baseline: `by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md`, SHA256 `957D41639BEC8A7DDA39E79DFF0E166F2841A3E14C19C29E70E1F92BCC4BB844`, 22367 bytes.
- Pre-callback read-only-data baseline: `by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md`, SHA256 `CB11F8B765C08D5823F1475B07FACE3C9692342790006507E4AD099B58453710`.
- Pre-callback shared List-wrapper baseline: [UID:00037L] `by-memory/0x004f3810-0x004f38a7.ListScalarDeletingDestructor.md`, SHA256 `2484CB87DCE1F1C3A22EB4B3C4136B7FDCB89A3E889AC3181609259BEC6504D3`, 8625 bytes, 85 lines. It already had exact wrapper behavior/source disposition but still recorded raw `sub_4F3810` evidence and lacked the accepted `List_scalar_deleting_destructor` name/type/comment mapping. The callback incorporated that mapping without changing its `87/92` score or existing formal/source route; current identity appears under `### Post-callback exact artifacts`.
- Shared Pane support named by the supervisor as UID00015Y: `by-memory/0x00544460-0x00545086.PaneCore.md`, SHA256 `48FF2354735D8F6723ED80543C9CC23788537AB6F097340D9BF61DC7553E002B`, 19486 bytes, 152 lines. The named path actually declares UID0001EA; repository UID00015Y is the unrelated `GeneralPurposePanel2SwitchActiveChild` page. PaneCore already documents `0x00544580-0x00544687` as source-owned `Pane::~Pane`, exact teardown behavior, compiler-generated derived/scalar routes, and the rejected stale `0x004b8d20` alternative, and contains no `ScrollableControlPane` text. This remains same-or-greater-detail proof for the ordinary-doc no-change disposition; supervisor Gate 2B separately replaced the stale IDA function comment and verified the exact Pane-owned poststate.
- Pre-callback generated baseline: `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp`, SHA256 `3C54B90B407C6E2A0AE623FE2A32D5533325976CE062DB120EBFB22E7300607E`, 9572 bytes, 295 lines, physical header `validator-command-id: 000000017440`, `validator-refreshed-at: 2026-07-24T22:15:48-04:00`, and `validator-refresh-source: foreground-generated-refresh`. That historical physical revision had one UID0002YC comment-only marker, zero UID0002YB markers, one `RadioGroupControlPane` declaration, and zero `RadioGroupControlPane::~RadioGroupControlPane` bodies. Current post-callback generated identity and counts appear below.
- Historical reports inspected: B010 `0000HY-ButtonControlPane-empty-emitter-family-source-quality.md`, B001 `0002XV-0002Y6-ui-control-adjustor-thunk-source-quality.md`, B004 `00011E-RadioGroupControlPaneOptionHelpers-source-quality.md`, and the directly analogous B005 `0002YA-PopupMenuControlPaneScalarDeletingDestructor-source-quality.md`. Their facts were rechecked rather than inherited.
- Historical initial report checkpoint: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, SHA256 `9DF44486A6C1DC34A55BDE2EB8E517916E0B073D46712BC7C1B9B1D3ECB9EB4C`, 143186002 bytes, last write `2026-07-24T22:09:37.3164487-04:00`. It is retained only as historical evidence and is not the current Gate 2B prestate.
- Pre-Gate2B saved-IDB checkpoint before and after the complete item-by-item repair reread: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, SHA256 `7509EC8477DC19D5028386F3DE945F319988B275B704DE7AF7A4C0CD10E3B331`, 143186450 bytes, last write `2026-07-24T22:54:09.6318603-04:00`. The hash, size, and mtime remained identical after all bounded B005 read-only MCP calls.
- Supervisor Gate 2B audit source: `tools/leaser/Agents/b-report-validation-audit.md`, entry `B005 UID0002YC Independent Gate 2B - 2026-07-25T22:20:38-04:00`; catalog source: `tools/leaser/Agents/ida-recommendation-implementation-catalog.md`, entry `0314`, state `APPLIED_VERIFIED`.
- Exact supervisor-owned pre-mutation backup: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.pre-0002YC-20260725_221250.bak`, SHA256 `0D1A585975A358156DE06EA9B973B186DCBE4D3DDD9199F936559275BC1FDE78`, 143186049 bytes.
- Exact final saved IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, SHA256 `2C20AAD81BC18DE1FA91B04D7FBEC30A704D377E6E2A2E35344C06EAEE479BC0`, 143186196 bytes, last write `2026-07-25T22:20:13.8438553-04:00`. Reopened healthy session `f085b224` reported `status:ok`, `auto_analysis_ready:true`, and Hex-Rays ready.

### Post-callback exact artifacts

- New UID0004X2 `by-memory/0x00495fd0-0x00496005.RadioGroupControlPaneDestructorRaw.md`: SHA256 `AA8B55B00B4A9758412CE446339FF72DA8D8BC35E1398A13E3AB75529E02F415`, 11816 bytes, 113 lines.
- UID0002YC target: SHA256 `31E143A4F65F8E517B63ABF7F3B8C783A3FB2A7F2E89E0957B7B6B08EBCBB97A`, 11164 bytes, 96 lines.
- UID0002YB thunks: SHA256 `A4E84463E5941B6C735B923659010F9518250E2A0E57B9309B7D582188B48FA8`, 7761 bytes, 79 lines.
- UID0000BI class after C2YC-35: SHA256 `90613076E4D8B39900DEDC3D032576733BA470C0B973B385F3FB1B4706B4A983`, 19879 bytes, 155 lines. Its CPP block is blank; its H block contains the unchanged complete declaration and sole `[[CHILDREN]]` marker.
- UID0000HY file: SHA256 `42D9B78732B953F800983868F886CD6B53572B84D5B8457907EDF33773C4691E`, 38104 bytes, 207 lines.
- UID000118 core index: SHA256 `7E0246766FA8B16E415110DB5CB3C9F2ECA670AF0C22E90C7D9F8CB16E3CF770`, 32477 bytes, 195 lines.
- UID00011Y destructor index: SHA256 `B47C30D6BCC81B6EF7236F5B4C2AC58F808C34813B9BB3177B7EA11320E2E452`, 50501 bytes, 234 lines.
- UID00011E option helpers: SHA256 `444FA584AE4C8295EA95BE02B623B92382EEE67695FC6CF836D41F8E29030BFB`, 25011 bytes, 186 lines.
- UID000252 read-only index: SHA256 `18FA88E199B5251FE22EE953FFB16382075E544F5487D5C952868A541BB53677`, 23932 bytes, 153 lines.
- UID00037L List wrapper: SHA256 `39360B922EF59EA7A613D3B5124E52148AAB0056C3B9AF9F6224E5C8C454AB15`, 10139 bytes, 90 lines.
- Named PaneCore path remains byte-for-byte unchanged at SHA256 `48FF2354735D8F6723ED80543C9CC23788537AB6F097340D9BF61DC7553E002B`, 19486 bytes, 152 lines; it still declares UID0001EA, has four exact `0x00544580-0x00544687` references, and has zero `ScrollableControlPane` matches.
- Generated `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp`: current physical SHA256 `0AFACB6D27C6C2881032C4A40E9E505664AFD3B742D8699CF22949AD1430CF82`, 9051 bytes, 278 lines, command `000000017510`, refresh `2026-07-25T04:52:56-04:00`. It contains zero UID0002YC markers, zero UID0002YB markers, one UID0000BI empty-emitter marker, zero `class RadioGroupControlPane` declarations, one UID0004X2 annotation, exactly one `RadioGroupControlPane::~RadioGroupControlPane` definition, and exactly one `delete m_options;` statement.
- Generated `auto-generated/NexusTK/ui/controls/ButtonControlPane.h`: current physical SHA256 `67DA4E877DD7878961A08146CBA855CD95376485725CC99AB92F590FB6459203`, 862 bytes, 28 lines, command `000000017510`, refresh `2026-07-25T04:52:56-04:00`. It contains one UID0000BI annotation, one complete `RadioGroupControlPane` declaration with every accepted member/method exactly once, one `[[No Children Attached]]` placeholder, zero UID0004X2 annotations, and zero destructor definitions.
- C2YC-35 changed only formal source-channel placement and validator-owned generated topology. The declaration text, marker count in UID0000BI, score, ownership, routing, evidence, and every ordinary child remain unchanged; no unrelated RadioGroup family drift was found.

## Target

- UID: `0002YC`.
- Path: `by-memory/0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor.md`.
- Exact covered range: `[0x0049b420,0x0049b487)`, 103 bytes.
- Entity: compiler-generated RadioGroupControlPane complete-object scalar deleting wrapper.
- Assignment-time metadata: `87/89`, owner/emitter UID0000BI, `RECONSTRUCTABLE:TRUE`, blank position, comment-only CPP, blank H, `Nested:0`.
- Implemented/current metadata: `93/95`, semantic owner UID0000BI, `RECONSTRUCTABLE:FALSE`, blank emitter/position/CPP/H, `Nested:0`.
- Exact target byte SHA256: `D580ABEA82DE09DD1D29EC53D86F4FC079D43A7A32A6CF70E9AB7702AFBE6A2F`.
- Current final IDA function: `RadioGroupControlPane_scalar_deleting_destructor`, exact size `0x67`, current type `RadioGroupControlPane *__thiscall RadioGroupControlPane_scalar_deleting_destructor(RadioGroupControlPane *this, unsigned int deletingFlags)`, seven basic blocks, cyclomatic complexity three. The former `sub_49B420` / `Pane *__thiscall(Pane *Block, char)` state remains preserved in the exact prestate table.

## Current Target State

- UID0002YC is now `93/95`, semantic owner UID0000BI, `RECONSTRUCTABLE:FALSE`, non-emitting, `Nested:0`, with blank CPP/H/position and full wrapper/source-boundary evidence. Its former TRUE/emitter/comment-only route is retained only as superseded history.
- Validator-allocated UID0004X2 now covers exact `[0x00495fd0,0x00496005)` at `92/94`, owner/emitter UID0000BI, position `20`, and emits the sole human body `delete m_options;` with blank H because UID0000BI owns the virtual declaration.
- UID0002YB is `91/95`, NONE/FALSE/non-emitting/blank and records both exact adjusted entries. UID0000BI is `92/94` with its complete declaration text, exact `0x110` layout, owned List lifetime, 144-byte option records, ordinary source child, compiler exclusions, and vtable evidence. C2YC-35 is applied: CPP is blank and H owns the unchanged declaration and sole child marker.
- UID0000HY remains `90/92`; UID000118 and UID00011Y remain `86/90` NONE/FALSE indexes. UID00011E is `90/93`; UID000252 is `86/93`; UID00037L remains `87/92` with the documented stable-7509 prestate and the supervisor-applied `List_scalar_deleting_destructor` final IDA state both recorded.
- Named PaneCore actual UID0001EA remains byte-for-byte unchanged and already contains same-or-greater ordinary Pane destructor evidence with zero stale Scrollable text. The unrelated repository UID00015Y was not edited.
- Current validator-owned command `000000017510` places zero RadioGroup class declarations in `ButtonControlPane.cpp`, exactly one UID0004X2 destructor body there, and exactly one unchanged UID0000BI class declaration in `ButtonControlPane.h`; UID0002YC/UID0002YB remain absent. B005 observed this state read-only and did not run the command or edit either generated file.
- Supervisor Gate 2B is `APPLIED_VERIFIED`: both exact UDTs, five function identities/types/comments, the owned-child local, all 20 instruction-comment results, the Pane comment correction, protected-state checks, persistence recovery, final save, and healthy reopen readback passed. Manual coverage remains pending supervisor action only after report execution/archive.

## Executive Recommendation

1. UID0002YC is now semantic-owner compiler evidence: `FALSE`, non-emitting, no C++.
2. Validator-allocated UID0004X2 now covers `by-memory/0x00495fd0-0x00496005.RadioGroupControlPaneDestructorRaw.md` at `92/94`, owner/emitter UID0000BI, `TRUE`, position `20`, exact destructor CPP, blank H, and `Nested:0`.
3. UID0002YB is now `91/95` while retaining NONE/FALSE/non-emitting/blank formals and `Nested:0`.
4. UID0000BI remains `92/94`; C2YC-35 preserved its complete class declaration byte-for-text while moving that declaration and its sole `[[CHILDREN]]` marker from formal CPP to formal H. CPP is exactly blank, while all destructor/list/record/vtable/compiler-boundary evidence and routing remain unchanged.
5. UID0000HY remains `90/92` and now records the exact ordinary-source versus compiler-support route without claiming the final historical broad/narrow file split is proven.
6. UID000118 and UID00011Y remain `86/90` non-emitting indices with synchronized exact child inventories.
7. UID00011E is now `90/93` with the exact 144-byte option-record and owned-list lifetime facts; its retained raw helper starts still have no invented routes.
8. UID000252 is now `86/93` with the exact 164-byte RadioGroup RTTI/vtable island while retaining NONE/FALSE/non-emitting mixed-index status.
9. C2YC-35 is implemented and reconciled from independently observed current state. Independent supervisor Gate 2B subsequently applied and verified C2YC-30 and every actionable/protected IDA row against the accepted `2344A7DF...B0F48` Gate 1/Gate 2A artifact, including final save/reopen recovery. Fresh exact-artifact Gate 1 continuity for this report revision, execution/archive, and manual coverage remain later ordered supervisor stages.

## Supervisor Active Recheck

- Duplicate screen: no current B001-B005 goal or unexecuted report targets UID0002YC, `0x0049b420`, the exact target path/title, or this report path.
- Exact ordinary-child screen: repository search found no by-memory page for `0x00495fd0-0x00496005` and no `RadioGroupControlPaneDestructor` page.
- Exact vtable-child screen: repository search found no by-memory page for `0x00617e6c-0x00617f10` and no `RadioGroupControlPaneVtableData` page.
- MCP health: database `supervisor_current_20260724_9f6e` reported `status:ok`, Hex-Rays ready, string cache ready, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Stable revisions: `9DF44486...EB4C` is the historical initial-report checkpoint; `7509EC84...B331` is the historical repaired prestate checkpoint; supervisor backup `0D1A5859...DE78` is the exact Gate 2B pre-mutation state; final authoritative saved IDB is `2C20AAD8...BC0`.
- Supervisor Gate 2B readback: reopened session `f085b224` is healthy with `auto_analysis_ready:true` and Hex-Rays ready; exact function/type/comment, UDT, decompiler, xref, byte, vtable, fence, and protected-state checks passed after the persistence repair.
- B005 actor boundary: B005's original MCP work was read-only, and this reconciliation reads only supervisor audit/catalog evidence. B005 did not start, stop, restart, save, rename, type, comment, or otherwise mutate IDA.

## Inference Research Guidance Check

- Exact binary facts and inferred source shape are separated. Bytes, bounds, xrefs, flag tests, vtable cells, field offsets, record width, and current comments/types are exact. Human names and source placement are ranked inferences.
- The report does not leave raw names such as `sub_49B420`, `sub_49AFAB`, `v3`, or `a2` as final source identities. Gate 2B applied the deterministic human names/types and verified typed receiver, `deletingFlags`, `this->m_options`, and `List *options` decompiler renderings.
- Lack of direct xrefs to the ordinary destructor was investigated with code/data xrefs and VA/RVA/raw-file-offset byte searches. It is negative liveness evidence, not grounds to discard source-shaped retained code.
- The ordinary destructor recommendation is not a decompiler transliteration. Authored C++ contains only the semantic cleanup `delete m_options;`; vptr writes, base-destructor tail chaining, hidden flags, storage release, adjustors, and padding remain compiler output.
- Mid-2000s source shape is respected: no C++11 constructs, IDA labels, raw offsets, manual vtable arrays, explicit base-destructor call, or explicit compiler deleting flags appear in authored C++.
- Naming consistency priority: use existing project spelling `RadioGroupControlPane`, `m_options`, `m_selectedIndex`, `RectBounds`, and `List`; infer `RadioGroupOption` for the 144-byte record rather than introducing a conflicting naming style.

## Heuristic / Inference Reanalysis And Validation

### Wrapper disposition alternatives

1. Hand-author UID0002YC as source: rejected. Hidden flags, return-this ABI, conditional operator delete, adjusted entries, three vptr restores, and the one-byte size/no-op path are compiler lowering.
2. Keep a comment-only emitted marker: rejected. It creates generated-source noise, is not authored C++, and conflicts with the false-page blank-formal rule.
3. Keep TRUE as a declaration-side source index: rejected. UID0000BI already carries the declaration; TRUE plus emitter would duplicate source ownership without adding a source construct.
4. Semantic owner UID0000BI plus FALSE/non-emitting/blank formals: accepted. It preserves ownership evidence without emitting compiler ABI as source.

### Ordinary destructor alternatives

1. Treat `[0x495fd0,0x496005)` as dead padding: rejected. The range decodes as a coherent 53-byte destructor with class vptr stores, owned-child virtual deletion, and a tail jump to `Pane__Destructor`.
2. Fold it into UID0002YC: rejected. It is a distinct earlier range separated by code and padding; its source semantics differ from the wrapper's storage dispatch.
3. Omit it because no xref reaches the raw start: rejected. The exact body is class-specific, source-shaped, and compiler-retained; no-xref evidence lowers confidence but does not erase the source definition.
4. Create a dedicated exact child and emit `delete m_options;`: accepted. This reproduces the authored destructor while leaving automatic vptr/base mechanics to the compiler.

### Member/type/name alternatives

- `m_options` versus `m_optionList`: existing class formal, class docs, and support docs consistently use `m_options`; accepted.
- `List *` versus a typed vector/container: constructor allocates the project `List`, invokes `List(144,10)`, stores the pointer at `+0x108`, uses List virtual append, and deletes it through List vtable slot zero; `List *` is exact enough and accepted.
- `RadioGroupOption` versus leaving an anonymous 144-byte blob: `RectBounds` at `+0x00` and `wchar_t[64]` at `+0x10` are exact. `RadioGroupOption` is the highest-probability human name; original spelling remains inferred but no raw IDA placeholder belongs in final source.
- `m_selectedIndex` at `+0x10c`: constructor zeroes it, selection methods read/write it, and current class formal already uses that name; accepted.

### Source placement alternatives

- `NexusTK/ui/controls/ButtonControlPane.cpp`: accepted current route because class UID0000BI already emits through file UID0000HY and the dense button/choice-control neighborhood is documented there.
- `ChoiceControlPane.cpp` or `RadioGroupControlPane.cpp`: plausible historical file names but not supported strongly enough to replace the established route. This uncertainty caps file confidence only.
- Option/dialog feature owners: rejected. Callers construct and consume the reusable control but do not own its class destructor.

## Evidence Standards Used

- Current saved-IDB bytes, item boundaries, modeled functions, decompilation, disassembly, xrefs, type state, comments, and vtable cells are primary binary evidence.
- Current by-* metadata/formals/prose and generated output are primary project-state evidence.
- Executed reports are historical leads only; each material claim was checked against current docs and live MCP.
- Exact range hashes use SHA256 over the stated half-open byte spans.
- Numeric conversions used the required local helper:
  - `python .\tools\int_convert.py --text 0x110 --size 4 --pretty --single` -> decimal `272`, hex `0x110`, bytes `10 01 00 00` (Verified with int_convert.py).
  - `python .\tools\int_convert.py --text 0x90 --size 4 --pretty --single` -> decimal `144`, hex `0x90`, bytes `90 00 00 00` (Verified with int_convert.py).
  - `python .\tools\int_convert.py --text 0xa4 --size 4 --pretty --single` -> decimal `164`, hex `0xa4`, bytes `a4 00 00 00` (Verified with int_convert.py).
- Inference is accepted only when exact evidence converges and rejected alternatives are documented.

## Evidence Checked

- Skill/template/goal: project `ntk-b-agent-workflow`, current B-agent report template, and B005 `goal.md`.
- Current target, class, file, core aggregate, destructor aggregate, thunk, option-helper, and read-only-data documents.
- Generated `ButtonControlPane.cpp` and manual by-memory/by-class/by-file coverage rows.
- Historical pre-C2YC-35 UID0000BI formal readback: complete declaration plus one `[[CHILDREN]]` in CPP, exactly blank H, unchanged `92/94` and owner/emitter UID0000HY; physical generated `ButtonControlPane.h` was absent. Current command `000000017510` readback proves CPP blank, the unchanged declaration and sole marker in H, and separate generated CPP/H artifacts under the independent-channel rule.
- Current generator precedents `by-class/ObjectPane.md`/generated `ObjectPane.h` and `by-class/SoundManager.md`/generated `SoundManager.cpp`/`.h`: blank class CPP does not suppress independently routed child CPP definitions; an H `[[CHILDREN]]` marker with no child H payload renders one `[[No Children Attached]]` placeholder. These are read-only topology evidence for C2YC-35, not support-doc edit targets.
- Current MCP tools: `server_health`, `lookup_funcs`, `analyze_function`, `disasm`, `inspect_items`, `get_comments`, `get_bytes`, `xrefs_to`, `get_int`, `type_inspect`, and `find_bytes`.
- Current-IDB repair reread: every actionable function/type/argument/local/instruction row and every protected vtable/locator/padding/dependency row was independently re-read against stable saved checkpoint `7509EC8477DC19D5028386F3DE945F319988B275B704DE7AF7A4C0CD10E3B331`; the saved hash/size/mtime were unchanged afterward. Historical checkpoint `9DF44486...EB4C` was not used as current prestate.
- Target: exact 103 bytes, function size/prototype/CFG, 35 instructions, xrefs, comments, and callees.
- Ordinary destructor: exact 53 bytes, raw item state, no xrefs, no VA/RVA/raw-offset pointer hits, pre/post fences, and semantic parity with the target prefix.
- Constructor and AddOption: exact layout initialization, `List` allocation/constructor, element size/page size, record copy, and append route.
- Thunks: exact bytes, sizes, offsets, tail target, sole vtable xrefs, types, and comments.
- Vtable island: exact locator/slot dwords, three decorated vtable bases, primary wrapper slot, two thunk slots, RTTI locator fences, current comments, and 164-byte SHA.
- Dependencies: current `ControlPane`, `Pane`, `RectBounds`, incomplete `List`, missing `RadioGroupControlPane`/`RadioGroupOption` types, `Pane__Destructor`, `NexusTK_operator_delete_wrapper`, `_guard_check_icall_nop`, `List` constructor, and List scalar deleting wrapper.
- Shared-support mapping: UID00037L was read in full and records the exact historical-to-accepted identity/type/comment handoff; supervisor Gate 2B applied and verified that List-wrapper mapping. The named PaneCore path was read in full, resolves to actual UID0001EA rather than supplied unrelated UID00015Y, contains no stale Scrollable text, and already carries the corrected Pane destructor fact at same-or-greater detail; Gate 2B also applied and verified the matching generic Pane-owned IDA comment.
- Historical initial report-only pass: no validator or lifecycle command was run before callback authorization. During the accepted ordinary/support callback, B005 ran only its scoped ordinary-document validators recorded under `## Validator Results`; current command `000000017510` is independently observed validator-owned state and is not attributed to B005. No report lifecycle command was run.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C2YC-01 | 0002YC | Exact target is `[0x49b420,0x49b487)`, 103 bytes, SHA256 D580...6A2F. | Exact | get_bytes/function bounds | UID0002YC range/evidence | incorporate | callback-applied/verified |
| C2YC-02 | 0002YC | Target is a compiler complete-object deleting wrapper, not authored destructor source. | Very high | hidden flags/storage paths/vtables | UID0002YC disposition | incorporate | callback-applied/verified |
| C2YC-03 | 0002YC | Target restores vptr views at complete-object offsets `0`, `0xa0`, `0xa4`. | Exact | instructions/vtable cells | UID0002YC behavior | incorporate | callback-applied/verified |
| C2YC-04 | 0002YC | Target deletes owned `List *m_options` at `+0x108` with virtual deleting flag one when non-null. | Exact | load/virtual call/List route | UID0002YC behavior | incorporate | callback-applied/verified |
| C2YC-05 | 0002YC | Target calls `Pane__Destructor` after derived cleanup. | Exact | call 0x49b452 | UID0002YC behavior | incorporate | callback-applied/verified |
| C2YC-06 | 0002YC | Hidden bit one controls storage handling; bit four selects the exact-size no-op branch. | Exact | tests/branches | UID0002YC flags | incorporate | callback-applied/verified |
| C2YC-07 | 0002YC | Normal storage path calls `NexusTK_operator_delete_wrapper(this)`. | Exact | call 0x49b463 | UID0002YC flags | incorporate | callback-applied/verified |
| C2YC-08 | 0002YC | Bit-four path pushes `0x110`/272 and calls the one-byte no-op; it is not sized/vector/guarded delete. | Exact | instructions/helper/int_convert | UID0002YC negative evidence | incorporate | callback-applied/verified |
| C2YC-09 | 0002YC | Inbound routes are two adjustor jumps plus primary vtable cell; there are no ordinary call sites. | Exact | xrefs_to | UID0002YC xrefs | incorporate | callback-applied/verified |
| C2YC-10 | 0002YC | Predecessor and successor fences are separate nine-byte CC spans. | Exact | inspect_items/get_bytes/hashes | UID0002YC boundaries | incorporate | callback-applied/verified |
| C2YC-11 | 0002YC | Semantic owner remains class UID0000BI. | Very high | vtable/class/ordinary body | UID0002YC metadata | incorporate | callback-applied/verified |
| C2YC-12 | 0002YC | Target is now FALSE, non-emitting, blank CPP/H/position, Nested 0. | Very high | compiler role/by-structure | UID0002YC metadata/formals | incorporate | callback-applied/verified |
| C2YC-13 | 0002YC | Existing comment-only CPP is historical and must be removed, not retained as output. | Very high | current formal/false rule | UID0002YC history | historicalize | callback-applied/verified |
| C2YC-14 | 0002YC | `[0x495fd0,0x496005)` is an exact 53-byte ordinary destructor, SHA256 9929...2D1, now validator-allocated as UID0004X2 under the primary target's class owner. | Very high | bytes/vptr/list/base flow | UID0004X2 ordinary child | create/incorporate | callback-applied/verified |
| C2YC-15 | 0002YC | Authored destructor body for UID0004X2 is only `delete m_options;`; vptr stores and base tail-chain are compiler lowering. | Very high | source-shape analysis | UID0004X2 formal CPP | incorporate | callback-applied/verified |
| C2YC-16 | 0002YC | UID0004X2 has no xrefs or VA/RVA/raw-offset pointer hits, but exact class semantics support retained source. | High | xrefs/find_bytes | UID0004X2 negative evidence | incorporate | callback-applied/verified |
| C2YC-17 | 0002YB | Two exact 11-byte thunks subtract `0xa0`/`0xa4` and tail-jump to UID0002YC. | Exact | bytes/hashes/vtable xrefs | UID0002YB | incorporate | callback-applied/verified |
| C2YC-18 | 0002YB | Thunks remain NONE/FALSE/non-emitting/blank, Nested 0, score `91/95`. | Very high | compiler role | UID0002YB metadata/summary | incorporate | callback-applied/verified |
| C2YC-19 | 0000BI | Class is exact `0x110`: ControlPane `0x108`, `m_options` `+0x108`, `m_selectedIndex` `+0x10c`. | Exact | constructor/types/methods | UID0000BI layout | incorporate | callback-applied/verified |
| C2YC-20 | 0000BI | Existing virtual destructor declaration is the source cause for ordinary and deleting entries. | Very high | class formal/compiler routes | UID0000BI destructor notes | incorporate | callback-applied/verified |
| C2YC-21 | 00011E | List records are `0x90` bytes: RectBounds at zero and `wchar_t[64]` at `+0x10`; page is `90/93`. | Very high | AddOption/List(144,10)/paint | UID00011E | incorporate | callback-applied/verified |
| C2YC-22 | 0000HY | Human source remains under ButtonControlPane source route; broad/narrow file split stays explicit. | High | current route/neighborhood | UID0000HY | incorporate | callback-applied/verified |
| C2YC-23 | 000118 | Core aggregate remains NONE/FALSE/non-emitting and gains exact ordinary-destructor child UID0004X2. | Very high | aggregate purpose/ranges | UID000118 | incorporate | callback-applied/verified |
| C2YC-24 | 00011Y | Destructor aggregate remains NONE/FALSE/non-emitting and distinguishes ordinary UID0004X2 source from UID0002YB/YC compiler support. | Very high | exact child roles | UID00011Y | incorporate | callback-applied/verified |
| C2YC-25 | 000252 | Exact RadioGroup vtable island is `[0x617e6c,0x617f10)`, 164 bytes, SHA256 340B...56E. | Exact | get_bytes/get_int/names | UID000252 | incorporate | callback-applied/verified |
| C2YC-26 | 000252 | Primary slot points to UID0002YC; secondary/tertiary slots point to UID0002YB thunks. | Exact | dwords/xrefs | UID000252 | incorporate | callback-applied/verified |
| C2YC-27 | 0002YC | Generated output contains zero UID0002YC/UID0002YB markers or bodies, zero RadioGroup class declarations in CPP, exactly one UID0004X2 ordinary destructor body in CPP, and exactly one UID0000BI class declaration in H. | Very high | retained callback command 000000017480, resumed serial verification through 000000017494, and current command 000000017510 CPP/H physical readback | generated readback | verify | callback-applied/verified |
| C2YC-28 | 0002YC | Target score is `93/95`; no material target blocker remains. | High | all closure evidence | UID0002YC metadata | incorporate | callback-applied/verified |
| C2YC-29 | 0000BI | Class score is `92/94`; exact original private spelling/file split remain only confidence caps. | High | complete layout/source route | UID0000BI metadata | incorporate | callback-applied/verified |
| C2YC-30 | 0002YC | Supervisor Gate 2B applied, read back, saved, reopened, persistence-repaired, and reverified the exact itemized IDA handoff below after Gate 1/Gate 2A acceptance of report artifact `2344A7DF...B0F48`. | Exact | audit entry `B005 UID0002YC Independent Gate 2B - 2026-07-25T22:20:38-04:00`; catalog 0314; backup `0D1A5859...DE78`; final IDB `2C20AAD8...BC0`; healthy session `f085b224` | IDA DB | incorporate | APPLIED_VERIFIED |
| C2YC-31 | 0002YC | After supervisor-only report execution/archive, supervisor applies/validates the exact manual coverage payload already reconciled to callback-allocated UID0004X2. | Exact | current absent/stale rows | coverage reports | incorporate | supervisor-pending |
| C2YC-32 | 0002YC | B005 must not mutate IDA, coverage, generated output, or report lifecycle during report-only research or implementation callback. | Exact | actor boundary | report lifecycle | preserve | complied |
| C2YC-33 | 00037L | Shared `[0x4f3810,0x4f38a7)` List wrapper Gate 2B action is individually mapped and applied: `sub_4F3810` became `List_scalar_deleting_destructor`, exact type is `List *__thiscall List_scalar_deleting_destructor(List *this, unsigned int deletingFlags)`, and function regular comment is `Compiler-generated List complete-object deleting destructor used by List vtable slot zero. Releases List storage, destroys the object, and dispatches hidden deleting flags; no authored standalone source function.` Entry regular, entry repeatable, and function repeatable remain absent. | Exact | stable 7509 function/type/comment/xref prestate, UID00037L full-text reread, final IDB `2C20AAD8...BC0`, and reopened session `f085b224` | UID00037L `Raw Code Evidence` and `Changes`; preserve existing `87/92`, metadata, formal, source body route, and compiler-only disposition | preserve exact doc mapping; supervisor Gate 2B IDA result | doc-incorporated; IDA-APPLIED_VERIFIED |
| C2YC-34 | 0001EA | Shared `Pane__Destructor` `[0x544580,0x544687)` Gate 2B removed stale Scrollable-specific function-comment text and left exact function regular `Source Pane ordinary destructor. Calls from derived destructors are compiler-generated base teardown and must not be handwritten explicitly; ownership remains with Pane.` The supervisor-supplied UID00015Y does not identify the named PaneCore path; that path's current header is UID0001EA. | Exact | stable 7509 comment prestate, PaneCore SHA `48FF...002B`, exact Functions/Neighboring/Changes text, zero `ScrollableControlPane` matches, final 303-xref readback in session `f085b224` | named `by-memory/0x00544460-0x00545086.PaneCore.md` / actual UID0001EA | same-or-greater-detail ordinary-doc no-change; supervisor Gate 2B comment result | doc-NO_CHANGE_VERIFIED; IDA-APPLIED_VERIFIED |
| C2YC-35 | 0000BI | Migrate the complete current `RadioGroupControlPane` declaration byte-for-text, including its sole `[[CHILDREN]]` marker, from formal CPP to formal H. UID0000BI CPP becomes exactly blank; H contains the unchanged declaration and marker exactly once. Preserve `92/94`, owner/emitter UID0000HY, blank position, every field/method/inline accessor, and all unrelated evidence. | Exact | UID0000BI SHA `90613076...A983`, current validator-owned command `000000017510`, and exact generated CPP/H readback | UID0000BI formal CPP/H plus generated ButtonControlPane.cpp/.h readback | incorporate | already-present/read-only-verified |

## Positive Evidence Summary

- Target bytes exactly match the complete-object deleting pattern: derived cleanup, base teardown, hidden flag dispatch, optional operator delete, return `this`.
- Three RadioGroup vptr writes identify the concrete class across primary and two adjusted facets.
- `+0x108` is initialized to null by the constructor, allocated as `List` by AddOption, consumed by option/paint methods, and virtually deleted by both ordinary and deleting bodies.
- `+0x10c` is separately initialized and used as selected index, proving complete size `0x110` rather than merging it with the pointer.
- The 53-byte ordinary body is a semantic prefix of the deleting wrapper after ABI prologue/flag dispatch is removed.
- The primary vtable directly names the target; adjusted vtables route through exact `-0xa0` and `-0xa4` thunks.
- Constructor has ten direct code xrefs and AddOption has broad consumer fan-in, confirming this is a live reusable control rather than an orphaned class guess.
- Existing class/source-root documentation and generated class declaration agree with the binary layout and source route.
- The complete UID0000BI declaration is already source-ready byte-for-text; the Gate 1 defect is only channel placement. Existing ObjectPane/SoundManager generated topology confirms moving the parent declaration to H leaves child CPP definitions independently routed and gives a concrete post-callback CPP/H acceptance shape.

## IDA MCP Facts

- Historical B005 read-only prestate database: `supervisor_current_20260724_9f6e`; saved checkpoint `7509EC84...B331` stayed stable during the complete item-by-item repair pass. The earlier `9DF44486...EB4C` checkpoint is historical only. The detailed prestate below is intentionally retained.
- Historical target `sub_49B420`: size `0x67`; type `Pane *__thiscall(Pane *Block, char)`; 35 instructions; seven blocks; complexity three.
- Target xrefs: code from `0x49afb1` and `0x49afbc`; data from `0x617e70`; no ordinary caller.
- Target historical comments at 7509: `0x49b423` regular `int`; `0x49b450` regular `this`; `0x49b462` regular `block`; every other queried target instruction regular comment absent; every queried instruction repeatable comment absent; target entry regular absent, entry repeatable absent, function regular absent, and function repeatable absent.
- Historical ordinary start `0x495fd0`: code item, not a modeled function, no name/type/comments, no xrefs.
- Raw ordinary bytes decode through `0x496000 jmp Pane__Destructor`; exact pre-padding is 14 CC bytes and post-padding is 11 CC bytes.
- Pointer searches for ordinary start found zero hits for VA `D0 5F 49 00`, RVA `D0 5F 09 00`, and raw-offset `D0 53 09 00`.
- Historical thunks `sub_49AFAB` and `sub_49AFB6`: each size `0xb`; type `Pane *__thiscall(_DWORD *this, char)`; each had entry regular absent, entry repeatable absent, function regular absent, and function repeatable absent; sole xrefs were from `0x617ed8` and `0x617f08` respectively.
- Historical type state: `ControlPane` exists at size `0x108`; `Pane` exists at size `0xf8`; `RectBounds` exists at size 16 with `left/top/right/bottom`; `List` is an incomplete declaration; `RadioGroupControlPane` and `RadioGroupOption` were absent.
- Collision checks returned `Not found` for all proposed RadioGroup target/ordinary/thunk names and `List_scalar_deleting_destructor`.
- Final Gate 2B state is `APPLIED_VERIFIED` in authoritative IDB `2C20AAD8...BC0`, reopened session `f085b224`: exact `RadioGroupOption` size `0x90`, exact `RadioGroupControlPane` size `0x110`, exact wrapper/ordinary/two-adjustor/List identities and prototypes, exact function and instruction comment channels, typed receiver/flags/owned-list decompilation, and all protected no-change rows match the report. The full itemized poststate is recorded under `## IDA Rename / Type / Comment Recommendations` without removing this historical prestate.

## Function / Child Inventory

| Range/address | Current identity | Exact role | Recommended source/compiler disposition |
| --- | --- | --- | --- |
| `[0x495f70,0x495fc2)` | `sub_495F70`, size `0x52` | RadioGroup constructor; base construction, three vptrs, null `m_options`, zero selected index, flag byte | Existing source method; support evidence only |
| `[0x495fc2,0x495fd0)` | 14 CC bytes | Constructor-to-destructor alignment, SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356` | Padding; no source |
| `[0x495fd0,0x496005)` | `RadioGroupControlPane_destructor`, size `0x35` (historical prestate: raw/no function) | Ordinary RadioGroup destructor, SHA256 `9929BB84CEC6A83AF73C86DB74EE61C301EE68F35B804B4AFFE33AAB5E3682D1` | Reconstructable source child UID0004X2; IDA `APPLIED_VERIFIED` |
| `[0x496005,0x496010)` | 11 CC bytes | Destructor-to-AddOption alignment, SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943` | Padding; no source |
| `[0x496010,0x4960e1)` | `sub_496010`, size `0xd1` | AddOption; allocates List(144,10), copies RectBounds/text, appends record | Existing class method/support |
| `[0x496110,0x496185)` | `sub_496110`, size `0x75` | SetSelectedIndex/refresh route | Existing class method/support |
| `[0x496190,0x49626e)` | `sub_496190`, size `0xde` | adjusted-facet mouse handling | Existing class method/support |
| `[0x496270,0x4962fb)` | `sub_496270`, size `0x8b` | hit test/option selection support | Existing class method/support |
| `[0x496300,0x49648d)` | `sub_496300`, size `0x18d` | OnPaint; consumes option records and selected index | Existing class method/support |
| `[0x49afab,0x49afb6)` | `RadioGroupControlPane_scalar_deleting_destructor_adjustor_a0` (historical prestate: `sub_49AFAB`) | `this-0xa0` deleting adjustor, SHA256 `D74639504FED8D843E3830CE0C985ADA6EF6338E75C1E29DBC2286536D011926` | UID0002YB compiler-only; IDA `APPLIED_VERIFIED` |
| `[0x49afb6,0x49afc1)` | `RadioGroupControlPane_scalar_deleting_destructor_adjustor_a4` (historical prestate: `sub_49AFB6`) | `this-0xa4` deleting adjustor, SHA256 `4B993258D87D198FE692B0166467B35CA7E1D021E84D9B0C15FBB49356B436DC` | UID0002YB compiler-only; IDA `APPLIED_VERIFIED` |
| `[0x49b417,0x49b420)` | nine CC bytes | predecessor fence, SHA256 `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE` | Padding |
| `[0x49b420,0x49b487)` | `RadioGroupControlPane_scalar_deleting_destructor` (historical prestate: `sub_49B420`) | complete-object deleting wrapper | UID0002YC compiler-only; IDA `APPLIED_VERIFIED` |
| `[0x49b487,0x49b490)` | nine CC bytes | successor fence, same SHA256 as predecessor | Padding |
| `[0x617e6c,0x617f10)` | mixed locator/vtable data | exact RadioGroup three-view vtable island, SHA256 `340B72245692165BEB327A9FF5AFC63D990F72AE50436C04BC0931FB7B6E356E` | Document in UID000252; compiler data from class declaration |

## Direct Xref / Caller Inventory

- `0x49b420`: three inbound xrefs total: `0x49afb1` code jump, `0x49afbc` code jump, `0x617e70` data slot.
- `0x49afab`: one inbound xref from adjusted vtable base `0x617ed8`.
- `0x49afb6`: one inbound xref from adjusted vtable base `0x617f08`.
- `0x495fd0`: zero inbound code/data xrefs and zero pointer-pattern hits; retained source identity is established structurally.
- `0x617e70`: three binary refs from constructor `0x495f84`, ordinary destructor `0x495fd9`, deleting wrapper `0x49b42c`.
- `0x617ed8`: three binary refs from constructor `0x495f8c`, ordinary destructor `0x495fdf`, deleting wrapper `0x49b432`.
- `0x617f08`: three binary refs from constructor `0x495f96`, ordinary destructor `0x495fe9`, deleting wrapper `0x49b43c`.
- Constructor `0x495f70`: ten direct code xrefs from reusable dialog/control consumers.
- AddOption `0x496010`: 22 direct code xrefs spanning browser/object/profile/new-user/user-list consumers.
- `List` scalar wrapper `0x4f3810`: one data xref from List vtable cell `0x61ce2c`, supporting the virtual delete at `0x49b44e`/`0x495ffb`.

## Documentation Evidence And IDA Status

- UID0000BI already declares a virtual destructor and exact tail fields; the report adds the missing exact ordinary body and compiler/source boundary rather than replacing the class design.
- UID0000HY already says scalar deleting wrappers and adjustor thunks are compiler output. UID0002YC's comment-only emission is therefore a local inconsistency, not file policy.
- UID000118 and UID00011Y are intentionally blank non-emitting indexes. Exact child pages must carry source/compiler decisions.
- UID00011E correctly preserves raw helper no-route evidence. This report adds the record/lifetime facts learned from reachable AddOption/OnPaint and does not falsely promote the raw helper starts.
- UID000252 currently contains the RadioGroup names only in a broad list and has stale `84/90` summary text despite actual `85/91` metadata. The exact island evidence closes that local gap while leaving the mixed aggregate non-emitting.
- Historical IDA lacked human RadioGroup destructor/thunk names and class/record UDTs. Supervisor Gate 2B applied and verified those identities, prototypes, comments, UDTs, and decompiler renderings without moving authored/compiler source ownership.

## Ranked Ownership Analysis

1. [UID:0000BI] RadioGroupControlPane - accepted semantic owner. Exact vtable identities, constructor layout, ordinary/destructor bodies, methods, and current class formal converge.
2. [UID:0000HY] ButtonControlPane - accepted physical source root. It owns the current emitted class family and documented `NexusTK/ui/controls/ButtonControlPane.cpp` path.
3. [UID:000118] ButtonChoiceControlCore - accepted non-emitting address index only; it must link the new ordinary child but cannot own source.
4. [UID:00011Y] ButtonChoiceControlDestructors - accepted non-emitting compiler/destructor index only; it cannot own class source.
5. `List` - owned dependency at `+0x108`, not owner of the RadioGroup destructor.
6. Caller dialogs/features - consumers only; none owns the reusable control class.

## Source Placement

- Class declaration: UID0000BI formal H, emitted through UID0000HY into `NexusTK/ui/controls/ButtonControlPane.h`; its formal CPP is exactly blank.
- Ordinary destructor definition: new exact by-memory child, emitted through UID0000BI at position `20` into `NexusTK/ui/controls/ButtonControlPane.cpp`.
- Complete-object deleting wrapper: UID0002YC, semantic owner UID0000BI but FALSE/non-emitting.
- Adjustor thunks: UID0002YB, NONE/FALSE/non-emitting.
- Vtable/RTTI bytes: compiler-generated from UID0000BI declaration; exact evidence remains under mixed read-only-data index UID000252.
- Rejected source placements: List.cpp, Pane.cpp, any feature/dialog source, destructor aggregate source, and direct vtable-data source.

## Range / Split / Padding / Reclassification Analysis

- Target range stays unchanged: exact modeled function `[0x49b420,0x49b487)` with independent nine-byte CC fences on both sides.
- Target requires metadata/formal reclassification only; no path rename or range split.
- New ordinary child is exact `[0x495fd0,0x496005)`. It excludes 14-byte predecessor and 11-byte successor padding.
- UID000118 broad core already spans the ordinary body. Add the new child to its address-ordered inventory; do not change the broad range.
- UID00011Y broad destructor index already spans UID0002YB/YC. Synchronize child roles; do not change its range.
- UID000252 exact current managed range is `[0x617a38,0x618858)`. Add the `[0x617e6c,0x617f10)` island section without changing the aggregate range or creating overlapping emitted C++.
- The target's `Nested:0` and thunk's `Nested:0` are correct. The new ordinary child should also use `Nested:0`.

## Negative Evidence Summary

- No direct call reaches UID0002YC; only compiler adjustors and vtable data do.
- No xref or pointer encoding reaches the raw ordinary start. This prevents claiming direct binary liveness but does not contradict retained source because the body is exact class teardown code.
- No evidence makes `0x41b6a0` a guarded deallocator. It is one byte `C3`; the `0x110` path does not release storage.
- No evidence supports hand-authored flag tests, explicit `Pane__Destructor`, explicit vptr restoration, raw adjustor functions, or a manual vtable array.
- No evidence proves the historical file name was exactly `ButtonControlPane.cpp`; existing route remains strongest while the split caveat is preserved.
- No original symbols prove `RadioGroupOption`; this name is inference. Its layout and use are exact.
- Historical pre-Gate2B state had no local `RadioGroupControlPane` or `RadioGroupOption` UDT. Supervisor Gate 2B added and verified exact `0x110` and `0x90` layouts, so this negative evidence remains only as the preserved reason the action was required.
- Historical pre-C2YC-35 generated `ButtonControlPane.cpp` incorrectly contained the complete class declaration while `ButtonControlPane.h` was absent. Command `000000017510` resolved that source-channel defect without duplicating or rewriting source: CPP now has no class declaration and generated H has exactly one unchanged declaration.

## IDA Rename / Type / Comment Recommendations

The initial report used saved checkpoint `9DF44486A6C1DC34A55BDE2EB8E517916E0B073D46712BC7C1B9B1D3ECB9EB4C`; that checkpoint is historical only. Every actionable and protected row below was reread item by item against current saved checkpoint `7509EC8477DC19D5028386F3DE945F319988B275B704DE7AF7A4C0CD10E3B331`, 143186450 bytes, last write `2026-07-24T22:54:09.6318603-04:00`, through live database `supervisor_current_20260724_9f6e`. The saved hash, size, and mtime were identical before and after the bounded pass. B005 made no IDA mutation. For modeled functions, entry regular, entry repeatable, function regular, and function repeatable are independent channels. For instructions/data, regular and repeatable are independent channels. A literal `absent` means the current channel is an empty string. `Not applicable` is used only for a Hex-Rays lvar or stack-frame member that is not an address-backed IDA comment entity; the current MCP stack/lvar result exposed no separate comment field for that entity.

### Actionable type declarations

| Entity | Exact 7509 prestate | Supervisor action | Collision/layout constraints | Expected deterministic readback |
| --- | --- | --- | --- | --- |
| `RadioGroupOption` UDT | `type_inspect` current declaration lookup: absent, exact error `Type not found: RadioGroupOption`; therefore no existing declaration/member collision. | Declare `struct RadioGroupOption { RectBounds bounds; wchar_t text[64]; };`. | `RectBounds` is exact size `0x10`; text is 64 UTF-16 code units/`0x80`; total must be `0x90`, no extra members, overlap, or tail gap. | Complete declaration resolves exactly; UDT size `0x90`; `bounds` offset `0`, type `RectBounds`, size `0x10`; `text` offset `0x10`, type `wchar_t[64]`, size `0x80`. |
| `RadioGroupControlPane` UDT | `type_inspect` current declaration lookup: absent, exact error `Type not found: RadioGroupControlPane`; therefore no existing declaration/member collision. | Declare `struct RadioGroupControlPane { ControlPane _base; List *m_options; int m_selectedIndex; };`. | Existing `ControlPane` is exactly `0x108`; existing `List` is incomplete and is used only through a pointer; total must be exactly `0x110`, with no overlap or gap. | Complete declaration resolves exactly; UDT size `0x110`; `_base` offset `0`, type `ControlPane`, size `0x108`; `m_options` offset `0x108`, type `List *`, size four; `m_selectedIndex` offset `0x10c`, type `int`, size four. |

### Actionable functions, arguments, and local

| Entity | Exact 7509 prestate | Supervisor action | Constraints | Expected deterministic readback |
| --- | --- | --- | --- | --- |
| Function `[0x49b420,0x49b487)` | Name `sub_49B420`; type `Pane *__thiscall(Pane *Block, char)`; exact size `0x67`; xrefs `0x49afb1` code, `0x49afbc` code, `0x617e70` data; proposed-name collision lookup `Not found`; entry regular absent; entry repeatable absent; function regular absent; function repeatable absent. | Rename `RadioGroupControlPane_scalar_deleting_destructor`; apply `RadioGroupControlPane *__thiscall RadioGroupControlPane_scalar_deleting_destructor(RadioGroupControlPane *this, unsigned int deletingFlags)`; function regular `Compiler-generated RadioGroupControlPane complete-object deleting destructor. Performs the cleanup represented in source by virtual ~RadioGroupControlPane(), then dispatches hidden deleting flags between no storage release, project operator delete, and the 0x110-byte compiler no-op path. Binary evidence only; do not hand-author.`; leave the other three comment channels absent. | Preserve exact range, 103-byte SHA256 `D580ABEA82DE09DD1D29EC53D86F4FC079D43A7A32A6CF70E9AB7702AFBE6A2F`, xrefs, and compiler-only disposition. | Exact new name/type/function regular; entry regular absent; entry repeatable absent; function repeatable absent; range/bytes/three xrefs unchanged. |
| Target ECX receiver | No persistent stack member. Hex-Rays lvar/parameter is `Block`, type `Pane *`, carried in ECX. Lvar regular comment: not applicable; lvar repeatable comment: not applicable. | Through the function type, represent the ECX receiver as `this` of `RadioGroupControlPane *`. | Preserve `__thiscall` ECX receiver; do not create a stack copy. | Fresh decompile shows exact `this: RadioGroupControlPane *`; lvar comment channels remain not applicable. `SUPERSEDED_VERIFIED` is allowed only if the typed receiver is rendered directly and the exact `Block` lvar no longer exists. |
| Target physical stack argument | `disasm.stack_frame`: persistent member `arg_0`, frame offset `+0x0c`, size four, type `_DWORD`; Hex-Rays lvar/parameter `a2`, type `char`. Stack-member regular comment: not applicable to the non-address-backed frame member in the current MCP schema; stack-member repeatable comment: not applicable. Hex-Rays lvar regular comment: not applicable; Hex-Rays lvar repeatable comment: not applicable. | Rename/retype the persistent argument and function parameter to `deletingFlags` of `unsigned int`. | Physical slot remains four bytes; only the low byte is tested; do not create a duplicate argument. | Stack/decompile readback shows one four-byte `deletingFlags: unsigned int`; stack-member regular comment remains not applicable; stack-member repeatable comment remains not applicable; lvar regular comment remains not applicable; lvar repeatable comment remains not applicable. `SUPERSEDED_VERIFIED` requires fresh stack/decompile proof that the prototype removed the exact old `arg_0`/`a2` representations. |
| Target owned-child lvar | Hex-Rays register lvar `v3`, type `void (__thiscall ***)(_DWORD, int)`, sourced from `this+0x108`; no persistent stack-frame member exists. Lvar regular comment: not applicable; lvar repeatable comment: not applicable. | Rename/retype to `options` of `List *` after the UDT/function type is applied. | It is the `m_options` load, not an independent object. | Fresh decompile shows exact `options: List *`; lvar comment channels remain not applicable. `SUPERSEDED_VERIFIED` is allowed only if fresh decompile renders `this->m_options` directly and the exact `v3` lvar no longer exists. |
| Raw range `[0x495fd0,0x496005)` | No modeled function, function name, or function type; proposed-name collision lookup `RadioGroupControlPane_destructor` is `Not found`; `0x495fd0` is a one-byte code-item head; xref count zero; entry regular absent; entry repeatable absent; function regular unavailable because no function exists; function repeatable unavailable because no function exists. | Define exact function; name `RadioGroupControlPane_destructor`; type `void __thiscall RadioGroupControlPane_destructor(RadioGroupControlPane *this)`; function regular `Source-authored ordinary RadioGroupControlPane destructor. Deletes owned m_options at +0x108 and relies on automatic Pane base teardown; this declaration causes compiler generation of the complete-object deleting wrapper at 0x0049B420.`; leave entry regular absent; leave entry repeatable absent; leave function repeatable absent. | Do not absorb `[0x495fc2,0x495fd0)` or `[0x496005,0x496010)`; preserve exact 53 bytes, SHA256 `9929BB84CEC6A83AF73C86DB74EE61C301EE68F35B804B4AFFE33AAB5E3682D1`, and zero-xref state. | Exact function `[0x495fd0,0x496005)`, exact name/type/function regular; entry regular absent; entry repeatable absent; function repeatable absent; bytes and zero xrefs unchanged. |
| Ordinary ECX receiver | Before function creation there is no persistent stack member, function argument, or Hex-Rays lvar. Entry bytes `56 8B F1` preserve ECX into ESI. Regular lvar comment: not applicable; repeatable lvar comment: not applicable. | Function type creates `this` of `RadioGroupControlPane *`. | Preserve `__thiscall`; create no stack argument. | Fresh decompile shows typed `this: RadioGroupControlPane *` and `delete this->m_options` semantics; lvar comment channels remain not applicable. |
| Function `[0x49afab,0x49afb6)` | Name `sub_49AFAB`; type `Pane *__thiscall(_DWORD *this, char)`; exact size `0xb`; sole xref `0x617ed8` data; proposed-name collision lookup `Not found`; entry regular absent; entry repeatable absent; function regular absent; function repeatable absent. | Rename `RadioGroupControlPane_scalar_deleting_destructor_adjustor_a0`; type `RadioGroupControlPane *__thiscall RadioGroupControlPane_scalar_deleting_destructor_adjustor_a0(void *facetThis, unsigned int deletingFlags)`; function regular `Compiler-generated RadioGroupControlPane deleting-destructor adjustor for the +0xa0 secondary facet. Subtracts 0xa0 from facetThis and tail-jumps to the complete-object wrapper at 0x0049B420; no authored source body.`; leave other channels absent. | Preserve exact 11 bytes, SHA256 `D74639504FED8D843E3830CE0C985ADA6EF6338E75C1E29DBC2286536D011926`, sole vtable xref, and tail target. | Exact name/type/function regular; entry regular absent; entry repeatable absent; function repeatable absent; bytes, one xref, and tail target unchanged. |
| `0x49afab` ECX receiver | No persistent stack member. Hex-Rays parameter is `this`, type `_DWORD *`, carried in ECX. Lvar regular comment: not applicable; lvar repeatable comment: not applicable. | Rename/retype through the function type to `facetThis` of `void *`. | Preserve physical ECX and exact subtraction `0xa0`. | Fresh decompile shows exact `facetThis: void *`; lvar comments remain not applicable. `SUPERSEDED_VERIFIED` only if the exact old `this` lvar is replaced by the typed receiver expression. |
| `0x49afab` logical stack argument | `disasm.stack_frame` contains only `__return_address` at offset `0`, size four, type `_UNKNOWN *`; no persistent argument member is modeled. Hex-Rays parameter is `a2`, type `char`. Persistent stack-member regular comment: absent item/not applicable; persistent stack-member repeatable comment: absent item/not applicable; Hex-Rays lvar regular comment: not applicable; Hex-Rays lvar repeatable comment: not applicable. | Through the function type, represent one logical `deletingFlags` argument of `unsigned int`. | Preserve low-byte use and target `retn 4`; create no duplicate frame item. | Fresh decompile shows one `deletingFlags: unsigned int`; no persistent argument member is introduced; persistent stack-member regular comment remains absent item/not applicable; persistent stack-member repeatable comment remains absent item/not applicable; lvar regular comment remains not applicable; lvar repeatable comment remains not applicable. |
| Function `[0x49afb6,0x49afc1)` | Name `sub_49AFB6`; type `Pane *__thiscall(_DWORD *this, char)`; exact size `0xb`; sole xref `0x617f08` data; proposed-name collision lookup `Not found`; entry regular absent; entry repeatable absent; function regular absent; function repeatable absent. | Rename `RadioGroupControlPane_scalar_deleting_destructor_adjustor_a4`; type `RadioGroupControlPane *__thiscall RadioGroupControlPane_scalar_deleting_destructor_adjustor_a4(void *facetThis, unsigned int deletingFlags)`; function regular `Compiler-generated RadioGroupControlPane deleting-destructor adjustor for the +0xa4 tertiary facet. Subtracts 0xa4 from facetThis and tail-jumps to the complete-object wrapper at 0x0049B420; no authored source body.`; leave other channels absent. | Preserve exact 11 bytes, SHA256 `4B993258D87D198FE692B0166467B35CA7E1D021E84D9B0C15FBB49356B436DC`, sole vtable xref, and tail target. | Exact name/type/function regular; entry regular absent; entry repeatable absent; function repeatable absent; bytes, one xref, and tail target unchanged. |
| `0x49afb6` ECX receiver | No persistent stack member. Hex-Rays parameter is `this`, type `_DWORD *`, carried in ECX. Lvar regular comment: not applicable; lvar repeatable comment: not applicable. | Rename/retype through the function type to `facetThis` of `void *`. | Preserve physical ECX and exact subtraction `0xa4`. | Fresh decompile shows exact `facetThis: void *`; lvar comments remain not applicable. `SUPERSEDED_VERIFIED` only if the exact old `this` lvar is replaced by the typed receiver expression. |
| `0x49afb6` logical stack argument | `disasm.stack_frame` contains only `__return_address` at offset `0`, size four, type `_UNKNOWN *`; no persistent argument member is modeled. Hex-Rays parameter is `a2`, type `char`. Persistent stack-member regular comment: absent item/not applicable; persistent stack-member repeatable comment: absent item/not applicable; Hex-Rays lvar regular comment: not applicable; Hex-Rays lvar repeatable comment: not applicable. | Through the function type, represent one logical `deletingFlags` argument of `unsigned int`. | Preserve low-byte use and target `retn 4`; create no duplicate frame item. | Fresh decompile shows one `deletingFlags: unsigned int`; no persistent argument member is introduced; persistent stack-member regular comment remains absent item/not applicable; persistent stack-member repeatable comment remains absent item/not applicable; lvar regular comment remains not applicable; lvar repeatable comment remains not applicable. |
| Function `[0x4f3810,0x4f38a7)` | Name `sub_4F3810`; type `_DWORD *__thiscall(_DWORD *Block, char)`; exact size `0x97`; sole xref `0x61ce2c` data; proposed-name collision lookup `List_scalar_deleting_destructor` is `Not found`; entry regular absent; entry repeatable absent; function regular absent; function repeatable absent. | Rename `List_scalar_deleting_destructor`; apply `List *__thiscall List_scalar_deleting_destructor(List *this, unsigned int deletingFlags)`; function regular `Compiler-generated List complete-object deleting destructor used by List vtable slot zero. Releases List storage, destroys the object, and dispatches hidden deleting flags; no authored standalone source function.`; leave other channels absent. | Shared dependency: preserve exact range, 151 bytes, sole vtable xref, and incomplete `List` declaration; do not invent a complete List UDT. | Exact name/type/function regular; entry regular absent; entry repeatable absent; function repeatable absent; range/bytes/one vtable xref unchanged. |
| List wrapper ECX receiver | No persistent stack member. Hex-Rays parameter is `Block`, type `_DWORD *`, carried in ECX. Lvar regular comment: not applicable; lvar repeatable comment: not applicable. | Through the function type, represent as `this` of `List *`. | Preserve `__thiscall` ECX and incomplete `List`; do not create a stack copy. | Fresh decompile shows exact `this: List *`; lvar comments remain not applicable. `SUPERSEDED_VERIFIED` only if the exact `Block` lvar is replaced by the typed receiver expression. |
| List wrapper physical stack argument | `disasm.stack_frame`: persistent `arg_0`, offset `+0x1c`, size four, type `_DWORD`; Hex-Rays parameter `a2`, type `char`. Stack-member regular comment: not applicable to the non-address-backed frame member in the current MCP schema; stack-member repeatable comment: not applicable. Hex-Rays lvar regular comment: not applicable; Hex-Rays lvar repeatable comment: not applicable. | Rename/retype the persistent argument and function parameter to `deletingFlags` of `unsigned int`. | Preserve low-byte tests and `retn 4`; do not create a duplicate argument. | Stack/decompile readback shows one four-byte `deletingFlags: unsigned int`; stack-member regular comment remains not applicable; stack-member repeatable comment remains not applicable; lvar regular comment remains not applicable; lvar repeatable comment remains not applicable. `SUPERSEDED_VERIFIED` requires fresh stack/decompile proof that the exact old `arg_0`/`a2` representations no longer exist. |
| List wrapper current local/frame state | Hex-Rays register local `v3`, type `void *`, register EAX, no persistent stack member; Hex-Rays stack local `v5`, type `void *`, annotation `[esp-4h] [ebp-18h]`. Physical frame separately exposes `var_C`, offset `+0x8`, size four, type `_DWORD`, and `var_4`, offset `+0x10`, size four, type `_DWORD`; no unsafe one-to-one mapping is inferred. Lvar regular comment: not applicable; lvar repeatable comment: not applicable; frame-member regular comment: not applicable under the current MCP schema; frame-member repeatable comment: not applicable. | Protected local state; no rename or type action in this target report. | The shared List wrapper is only a dependency and its incomplete UDT prevents speculative member/local naming. | Fresh readback preserves these exact physical/decompiler observations, lvar regular comment not applicable, lvar repeatable comment not applicable, frame-member regular comment not applicable, and frame-member repeatable comment not applicable unless the accepted List function prototype deterministically changes the rendering; any changed/removed exact lvar requires item-specific `SUPERSEDED_VERIFIED` evidence, not an assumption. |
| `Pane__Destructor` `[0x544580,0x544687)` | Name `Pane__Destructor`; type `void __thiscall(Pane *this)`; exact size `0x107`; 303 xrefs; entry regular absent; entry repeatable absent; function regular `Shared Pane teardown reached from ScrollableControlPane destruction; ownership remains with Pane, not ScrollableControlPane.\nSource Pane ordinary destructor. Calls from derived destructors are compiler-generated base teardown and must not be handwritten explicitly.`; function repeatable absent. | Keep name/type; replace function regular with `Source Pane ordinary destructor. Calls from derived destructors are compiler-generated base teardown and must not be handwritten explicitly; ownership remains with Pane.` | Remove only stale Scrollable-specific wording; preserve shared ownership, range, bytes, and 303 xrefs. | Same name/type/range/303 xrefs; exact new function regular; entry regular absent; entry repeatable absent; function repeatable absent. |

### Actionable target instruction comments

| Address / exact bytes / containing function | Exact 7509 prestate | Exact action | Preservation constraint and deterministic readback |
| --- | --- | --- | --- |
| `0x49b423`, `56`, target wrapper | regular `int`; repeatable absent | Clear regular comment. | Preserve `push esi`; regular absent; repeatable absent. |
| `0x49b426`, `8B 8E 08 01 00 00`, target wrapper | regular absent; repeatable absent | regular `Load owned List *m_options from RadioGroupControlPane +0x108.` | Preserve exact bytes/offset; regular `Load owned List *m_options from RadioGroupControlPane +0x108.`; repeatable absent. |
| `0x49b42c`, `C7 06 70 7E 61 00`, target wrapper | regular absent; repeatable absent | regular `Restore RadioGroupControlPane primary vptr view at complete-object offset +0x0.` | Preserve target `0x617e70`; regular `Restore RadioGroupControlPane primary vptr view at complete-object offset +0x0.`; repeatable absent. |
| `0x49b432`, `C7 86 A0 00 00 00 D8 7E 61 00`, target wrapper | regular absent; repeatable absent | regular `Restore RadioGroupControlPane secondary vptr view at complete-object offset +0xa0.` | Preserve target `0x617ed8`; regular `Restore RadioGroupControlPane secondary vptr view at complete-object offset +0xa0.`; repeatable absent. |
| `0x49b43c`, `C7 86 A4 00 00 00 08 7F 61 00`, target wrapper | regular absent; repeatable absent | regular `Restore RadioGroupControlPane tertiary vptr view at complete-object offset +0xa4.` | Preserve target `0x617f08`; regular `Restore RadioGroupControlPane tertiary vptr view at complete-object offset +0xa4.`; repeatable absent. |
| `0x49b44e`, `FF 10`, target wrapper | regular absent; repeatable absent | regular `Delete non-null owned m_options through List vtable slot zero with deleting flag 1.` | Preserve indirect call and pushed one; regular `Delete non-null owned m_options through List vtable slot zero with deleting flag 1.`; repeatable absent. |
| `0x49b450`, `8B CE`, target wrapper | regular `this`; repeatable absent | regular `Prepare complete RadioGroupControlPane this for automatic Pane base teardown.` | Preserve instruction; regular `Prepare complete RadioGroupControlPane this for automatic Pane base teardown.`; repeatable absent. |
| `0x49b452`, `E8 29 91 0A 00`, target wrapper | regular absent; repeatable absent | regular `Invoke compiler-expanded Pane base-destructor teardown after RadioGroup cleanup.` | Preserve call target `Pane__Destructor`; regular `Invoke compiler-expanded Pane base-destructor teardown after RadioGroup cleanup.`; repeatable absent. |
| `0x49b45a`, `A8 01`, target wrapper | regular absent; repeatable absent | regular `Test deletingFlags bit 0: clear means destroy without releasing object storage.` | Preserve branch flow; regular `Test deletingFlags bit 0: clear means destroy without releasing object storage.`; repeatable absent. |
| `0x49b45e`, `A8 04`, target wrapper | regular absent; repeatable absent | regular `Test deletingFlags bit 2: set selects the exact-size compiler no-op path.` | Preserve branch flow; regular `Test deletingFlags bit 2: set selects the exact-size compiler no-op path.`; repeatable absent. |
| `0x49b462`, `56`, target wrapper | regular `block`; repeatable absent | regular `Pass complete object pointer to the project operator-delete wrapper.` | Preserve push; regular `Pass complete object pointer to the project operator-delete wrapper.`; repeatable absent. |
| `0x49b463`, `E8 58 96 05 00`, target wrapper | regular absent; repeatable absent | regular `Release RadioGroupControlPane object storage through NexusTK_operator_delete_wrapper.` | Preserve call target `NexusTK_operator_delete_wrapper`; regular `Release RadioGroupControlPane object storage through NexusTK_operator_delete_wrapper.`; repeatable absent. |
| `0x49b472`, `68 10 01 00 00`, target wrapper | regular absent; repeatable absent | regular `Push exact RadioGroupControlPane size 0x110 (272) for the compiler no-op branch.` | Preserve immediate `0x110` (Verified with int_convert.py); regular `Push exact RadioGroupControlPane size 0x110 (272) for the compiler no-op branch.`; repeatable absent. |
| `0x49b478`, `E8 23 02 F8 FF`, target wrapper | regular absent; repeatable absent | regular `Compiler one-byte no-op path; does not release storage and is not sized, vector, or guarded delete.` | Preserve call target `0x41b6a0`; regular `Compiler one-byte no-op path; does not release storage and is not sized, vector, or guarded delete.`; repeatable absent. |

### Actionable ordinary-destructor instruction comments

| Address / exact bytes / future function | Exact 7509 prestate | Exact action | Deterministic readback |
| --- | --- | --- | --- |
| `0x495fd3`, `8B 8E 08 01 00 00`, future ordinary destructor | regular absent; repeatable absent | regular `Load owned List *m_options from RadioGroupControlPane +0x108.` | Preserve exact bytes; regular `Load owned List *m_options from RadioGroupControlPane +0x108.`; repeatable absent. |
| `0x495fd9`, `C7 06 70 7E 61 00`, future ordinary destructor | regular absent; repeatable absent | regular `Restore RadioGroupControlPane primary vptr view before member/base teardown.` | Preserve target `0x617e70`; regular `Restore RadioGroupControlPane primary vptr view before member/base teardown.`; repeatable absent. |
| `0x495fdf`, `C7 86 A0 00 00 00 D8 7E 61 00`, future ordinary destructor | regular absent; repeatable absent | regular `Restore RadioGroupControlPane secondary vptr view at complete-object offset +0xa0.` | Preserve target `0x617ed8`; regular `Restore RadioGroupControlPane secondary vptr view at complete-object offset +0xa0.`; repeatable absent. |
| `0x495fe9`, `C7 86 A4 00 00 00 08 7F 61 00`, future ordinary destructor | regular absent; repeatable absent | regular `Restore RadioGroupControlPane tertiary vptr view at complete-object offset +0xa4.` | Preserve target `0x617f08`; regular `Restore RadioGroupControlPane tertiary vptr view at complete-object offset +0xa4.`; repeatable absent. |
| `0x495ffb`, `FF 10`, future ordinary destructor | regular absent; repeatable absent | regular `Delete non-null owned m_options through List vtable slot zero with deleting flag 1.` | Preserve indirect target/flag; regular `Delete non-null owned m_options through List vtable slot zero with deleting flag 1.`; repeatable absent. |
| `0x496000`, `E9 7B E5 0A 00`, future ordinary destructor | regular absent; repeatable absent | regular `Tail-chain into compiler-generated Pane base-destructor teardown.` | Preserve target `Pane__Destructor`; regular `Tail-chain into compiler-generated Pane base-destructor teardown.`; repeatable absent. |

### Protected vtable, RTTI, boundary, and dependency rows

| Entity | Exact 7509 current state | Disposition | Exact no-change readback |
| --- | --- | --- | --- |
| `0x617e6c`, item `[0x617e6c,0x617e70)` | Unnamed, untyped four-byte data item; value `0x00645b24`; regular absent; repeatable absent; zero xrefs. | Protect; no rename/type/comment. | Exact same head/end/size/name/type/value; regular absent; repeatable absent; zero xrefs. |
| `0x617e70`, item `[0x617e70,0x617e74)` | Name `??_7RadioGroupControlPane@@6B@`; untyped four-byte data item; value `0x0049b420`; regular absent; repeatable absent; three refs from `0x495f84`, `0x495fd9`, `0x49b42c`. | Preserve decorated name, item, bytes, and comments. | Exact same head/end/size/name/type/value; regular absent; repeatable absent; exact three refs unchanged. |
| `0x617ed4`, item `[0x617ed4,0x617ed8)` | Unnamed, untyped four-byte data item; value `0x00645b84`; regular absent; repeatable absent; zero xrefs. | Protect; no rename/type/comment. | Exact same head/end/size/name/type/value; regular absent; repeatable absent; zero xrefs. |
| `0x617ed8`, item `[0x617ed8,0x617edc)` | Name `??_7RadioGroupControlPane@@6B@_0`; untyped four-byte data item; value `0x0049afab`; regular absent; repeatable absent; three refs from `0x495f8c`, `0x495fdf`, `0x49b432`. | Preserve decorated name, item, bytes, and comments. | Exact same head/end/size/name/type/value; regular absent; repeatable absent; exact three refs unchanged. |
| `0x617f04`, item `[0x617f04,0x617f08)` | Unnamed, untyped four-byte data item; value `0x00645b98`; regular absent; repeatable absent; zero xrefs. | Protect; no rename/type/comment. | Exact same head/end/size/name/type/value; regular absent; repeatable absent; zero xrefs. |
| `0x617f08`, item `[0x617f08,0x617f0c)` | Name `??_7RadioGroupControlPane@@6B@_1`; untyped four-byte data item; value `0x0049afb6`; regular absent; repeatable absent; three refs from `0x495f96`, `0x495fe9`, `0x49b43c`. | Preserve decorated name, item, bytes, and comments. | Exact same head/end/size/name/type/value; regular absent; repeatable absent; exact three refs unchanged. |
| `[0x495fc2,0x495fd0)` | One unnamed, untyped 14-byte data item; bytes are fourteen `CC`; regular comment at head absent; repeatable comment at head absent; SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`. | Protect as padding; function creation must start exactly at `0x495fd0`; no comment change. | Same data-item head/end/size/name/type/bytes/hash; regular absent; repeatable absent. |
| `[0x496005,0x496010)` | One unnamed, untyped 11-byte data item; bytes are eleven `CC`; regular comment at head absent; repeatable comment at head absent; SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`. | Protect as padding; function creation must stop exactly at `0x496005`; no comment change. | Same data-item head/end/size/name/type/bytes/hash; regular absent; repeatable absent. |
| `[0x49b417,0x49b420)` | One unnamed, untyped nine-byte data item; bytes are nine `CC`; regular comment at head absent; repeatable comment at head absent; SHA256 `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`. | Protect predecessor fence; no comment change. | Same data-item head/end/size/name/type/bytes/hash; regular absent; repeatable absent. |
| `[0x49b487,0x49b490)` | One unnamed, untyped nine-byte data item; bytes are nine `CC`; regular comment at head absent; repeatable comment at head absent; SHA256 `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`. | Protect successor fence; no comment change. | Same data-item head/end/size/name/type/bytes/hash; regular absent; repeatable absent. |
| `NexusTK_operator_delete_wrapper` `[0x4f4ac0,0x4f4b00)` | Exact name `NexusTK_operator_delete_wrapper`; type `void __cdecl(void *block)`; size `0x40`; entry regular absent; entry repeatable absent; function regular `Project global operator-delete wrapper used by scalar deleting destructors; target ownership does not transfer here.`; function repeatable absent; bounded `xrefs_to(limit=1000)` returned 1000 refs with `more:true`. | Protect; no name/type/comment change. | Exact same name/type/range; entry regular absent; entry repeatable absent; function regular `Project global operator-delete wrapper used by scalar deleting destructors; target ownership does not transfer here.`; function repeatable absent; bounded xref readback still returns 1000 refs with `more:true` unless unrelated later analysis changes the broad shared dependency. |
| `@_guard_check_icall_nop@4` `[0x41b6a0,0x41b6a1)` | Exact one-byte function; name `@_guard_check_icall_nop@4`; type `void()`; entry regular absent; entry repeatable absent; function regular `One-byte compiler/runtime guarded-size path no-op; not a project source method.\nOne-byte compiler/runtime no-op used by deleting-wrapper flag paths; not sized delete, vector delete, guarded delete, or a deallocator.`; function repeatable absent; 682 xrefs. | Protect; no name/type/comment change. | Exact same byte/name/type/range/682 xrefs; entry regular absent; entry repeatable absent; exact function regular preserved; function repeatable absent. |
| List constructor `[0x4f3060,0x4f30d5)` | Name `sub_4F3060`; type `_DWORD *__thiscall(_DWORD *this, int, int)`; size `0x75`; entry regular absent; entry repeatable absent; function regular absent; function repeatable absent; 61 code xrefs including `0x496078`. | Protected dependency in this report; no broad rename/type/comment. Existing List docs own source naming. | Same name/type/range; entry regular absent; entry repeatable absent; function regular absent; function repeatable absent; exact 61 xrefs preserved. |
| `ControlPane` UDT | Declaration lookup resolves `ControlPane`, size `0x108`: `_base` `Pane` at `0x0` size `0xf8`; `m_rangeStart` `__int16` at `0xf8`; `m_rangeCurrent` `__int16` at `0xfa`; `m_rangeEnd` `__int16` at `0xfc`; `m_controlType` `unsigned __int8` at `0xfe`; `m_controlFlags` `unsigned __int8` at `0xff`; `m_reservedControlState` `unsigned __int8` at `0x100`; `m_enabled` `bool` at `0x101`; `m_controlActive` `bool` at `0x102`; `m_visualState` `unsigned __int8` at `0x103`; `m_ignoreHitTesting` `bool` at `0x104`; `_tailAlignment` `unsigned __int8[3]` at `0x105`. | Protect; no declaration/member change. | Exact same declaration, twelve members, offsets/types/sizes, and total size `0x108`. |
| `RectBounds` UDT | Declaration lookup resolves `RectBounds`, size `0x10`: `left` `int` at `0x0`; `top` `int` at `0x4`; `right` `int` at `0x8`; `bottom` `int` at `0xc`; each member size four. | Protect; no declaration/member change. | Exact same declaration, four members, offsets/types/sizes, and total size `0x10`. |
| Incomplete `List` declaration | Declaration lookup resolves `List`; size is IDA unknown sentinel `18446744073709551615`; `is_udt:false`; no members. | Preserve incomplete declaration; RadioGroup UDT uses only `List *`. | Lookup still resolves the same incomplete `List`; no size or members invented. |

### Supervisor Gate 2B applied poststate

The supervisor independently completed Gate 2B from exact accepted report artifact SHA256 `2344A7DFE9C7ABA7A539032BAB349EB6E8B774059EAFDD2095F2876B32DB0F48`. The authoritative audit is `B005 UID0002YC Independent Gate 2B - 2026-07-25T22:20:38-04:00`; catalog entry `0314` is `APPLIED_VERIFIED`. B005 did not perform or direct any IDA mutation.

| Entity | Exact final saved/reopened readback | Result |
| --- | --- | --- |
| `RadioGroupOption` | Complete UDT size `0x90`; `bounds` is `RectBounds` at `0x0`, size `0x10`; `text` is `wchar_t[64]` at `0x10`, size `0x80`; no extra member, overlap, or tail gap. | `APPLIED_VERIFIED` |
| `RadioGroupControlPane` | Complete UDT size `0x110`; `_base` is `ControlPane` at `0x0`, size `0x108`; `m_options` is `List *` at `0x108`, size four; `m_selectedIndex` is `int` at `0x10c`, size four. | `APPLIED_VERIFIED` |
| `[0x49b420,0x49b487)` | Name `RadioGroupControlPane_scalar_deleting_destructor`; exact type `RadioGroupControlPane *__thiscall RadioGroupControlPane_scalar_deleting_destructor(RadioGroupControlPane *this, unsigned int deletingFlags)`; size `0x67`; three xrefs; function regular `Compiler-generated RadioGroupControlPane complete-object deleting destructor. Performs the cleanup represented in source by virtual ~RadioGroupControlPane(), then dispatches hidden deleting flags between no storage release, project operator delete, and the 0x110-byte compiler no-op path. Binary evidence only; do not hand-author.`; entry regular, entry repeatable, and function repeatable empty. Fresh decompile renders typed `this`, typed `deletingFlags`, `this->m_options`, and surviving local `List *options`. | `APPLIED_VERIFIED` |
| `[0x495fd0,0x496005)` | Defined exact function; name `RadioGroupControlPane_destructor`; exact type `void __thiscall RadioGroupControlPane_destructor(RadioGroupControlPane *this)`; size `0x35`; zero xrefs; function regular `Source-authored ordinary RadioGroupControlPane destructor. Deletes owned m_options at +0x108 and relies on automatic Pane base teardown; this declaration causes compiler generation of the complete-object deleting wrapper at 0x0049B420.`; entry regular, entry repeatable, and function repeatable empty. Fresh decompile renders the typed receiver, owned-list delete, and Pane tail teardown. | `APPLIED_VERIFIED` |
| `[0x49afab,0x49afb6)` | Name `RadioGroupControlPane_scalar_deleting_destructor_adjustor_a0`; exact type `RadioGroupControlPane *__thiscall RadioGroupControlPane_scalar_deleting_destructor_adjustor_a0(void *facetThis, unsigned int deletingFlags)`; size `0xb`; one vtable xref; function regular `Compiler-generated RadioGroupControlPane deleting-destructor adjustor for the +0xa0 secondary facet. Subtracts 0xa0 from facetThis and tail-jumps to the complete-object wrapper at 0x0049B420; no authored source body.`; entry regular, entry repeatable, and function repeatable empty. Fresh decompile renders `facetThis - 160` and `deletingFlags`. | `APPLIED_VERIFIED` |
| `[0x49afb6,0x49afc1)` | Name `RadioGroupControlPane_scalar_deleting_destructor_adjustor_a4`; exact type `RadioGroupControlPane *__thiscall RadioGroupControlPane_scalar_deleting_destructor_adjustor_a4(void *facetThis, unsigned int deletingFlags)`; size `0xb`; one vtable xref; function regular `Compiler-generated RadioGroupControlPane deleting-destructor adjustor for the +0xa4 tertiary facet. Subtracts 0xa4 from facetThis and tail-jumps to the complete-object wrapper at 0x0049B420; no authored source body.`; entry regular, entry repeatable, and function repeatable empty. Fresh decompile renders `facetThis - 164` and `deletingFlags`. | `APPLIED_VERIFIED` |
| `[0x4f3810,0x4f38a7)` | Name `List_scalar_deleting_destructor`; exact type `List *__thiscall List_scalar_deleting_destructor(List *this, unsigned int deletingFlags)`; size `0x97`; one vtable xref; function regular `Compiler-generated List complete-object deleting destructor used by List vtable slot zero. Releases List storage, destroys the object, and dispatches hidden deleting flags; no authored standalone source function.`; entry regular, entry repeatable, and function repeatable empty; typed `this`/`deletingFlags` rendering; incomplete `List` declaration preserved. | `APPLIED_VERIFIED` |
| `Pane__Destructor` `[0x544580,0x544687)` | Same name and exact type `void __thiscall Pane__Destructor(Pane *this)` / accepted declaration `void __thiscall(Pane *this)`; size `0x107`; 303 xrefs; function regular `Source Pane ordinary destructor. Calls from derived destructors are compiler-generated base teardown and must not be handwritten explicitly; ownership remains with Pane.`; entry regular, entry repeatable, and function repeatable empty. Reopened decompile displays only the accepted Pane-owned comment. | `APPLIED_VERIFIED` |

All 20 target/ordinary instruction-comment results were read back exactly. The regular text below is literal; every repeatable channel is empty after immediate and both post-save reads.

| Address | Exact final regular-comment state | Result |
| --- | --- | --- |
| `0x49b423` | absent; historical `int` cleared | `APPLIED_VERIFIED` |
| `0x49b426` | `Load owned List *m_options from RadioGroupControlPane +0x108.` | `APPLIED_VERIFIED` |
| `0x49b42c` | `Restore RadioGroupControlPane primary vptr view at complete-object offset +0x0.` | `APPLIED_VERIFIED` |
| `0x49b432` | `Restore RadioGroupControlPane secondary vptr view at complete-object offset +0xa0.` | `APPLIED_VERIFIED` |
| `0x49b43c` | `Restore RadioGroupControlPane tertiary vptr view at complete-object offset +0xa4.` | `APPLIED_VERIFIED` |
| `0x49b44e` | `Delete non-null owned m_options through List vtable slot zero with deleting flag 1.` | `APPLIED_VERIFIED` |
| `0x49b450` | `Prepare complete RadioGroupControlPane this for automatic Pane base teardown.` | `APPLIED_VERIFIED` |
| `0x49b452` | `Invoke compiler-expanded Pane base-destructor teardown after RadioGroup cleanup.` | `APPLIED_VERIFIED` |
| `0x49b45a` | `Test deletingFlags bit 0: clear means destroy without releasing object storage.` | `APPLIED_VERIFIED` |
| `0x49b45e` | `Test deletingFlags bit 2: set selects the exact-size compiler no-op path.` | `APPLIED_VERIFIED` |
| `0x49b462` | `Pass complete object pointer to the project operator-delete wrapper.` | `APPLIED_VERIFIED` |
| `0x49b463` | `Release RadioGroupControlPane object storage through NexusTK_operator_delete_wrapper.` | `APPLIED_VERIFIED` |
| `0x49b472` | `Push exact RadioGroupControlPane size 0x110 (272) for the compiler no-op branch.` | `APPLIED_VERIFIED` |
| `0x49b478` | `Compiler one-byte no-op path; does not release storage and is not sized, vector, or guarded delete.` | `APPLIED_VERIFIED` |
| `0x495fd3` | `Load owned List *m_options from RadioGroupControlPane +0x108.` | `APPLIED_VERIFIED` |
| `0x495fd9` | `Restore RadioGroupControlPane primary vptr view before member/base teardown.` | `APPLIED_VERIFIED` |
| `0x495fdf` | `Restore RadioGroupControlPane secondary vptr view at complete-object offset +0xa0.` | `APPLIED_VERIFIED` |
| `0x495fe9` | `Restore RadioGroupControlPane tertiary vptr view at complete-object offset +0xa4.` | `APPLIED_VERIFIED` |
| `0x495ffb` | `Delete non-null owned m_options through List vtable slot zero with deleting flag 1.` | `APPLIED_VERIFIED` |
| `0x496000` | `Tail-chain into compiler-generated Pane base-destructor teardown.` | `APPLIED_VERIFIED` |

The `set_comments` operation returned secondary decompiler-anchor warnings at `0x49b472` and `0x49b478`. Those warnings did not invalidate the write: immediate readback and both post-save/reopen reads returned the exact regular comments above, with repeatable channels empty.

Protected-state postread is `NO_CHANGE_VERIFIED`: six vtable/RTTI cells retain exact item heads, values, decorated names, empty types/comments, and xref totals `0/3/0/3/0/3`; the three live cells still point to `0x49b420`, `0x49afab`, and `0x49afb6`. Four separate unnamed/untyped/uncommented `0xcc` fences retain exact lengths `14/11/9/9` and hashes `1E875C76...4356`, `3682C0A6...943`, and `57C1D0AA...1CE` twice. `NexusTK_operator_delete_wrapper`, `@_guard_check_icall_nop@4`, the List constructor, `ControlPane`, `RectBounds`, and incomplete `List` retain their exact accepted names/types/layouts/comments and bounded xref totals. Target/ordinary/adjustor byte hashes remain `D580ABEA82DE09DD1D29EC53D86F4FC079D43A7A32A6CF70E9AB7702AFBE6A2F`, `9929BB84CEC6A83AF73C86DB74EE61C301EE68F35B804B4AFFE33AAB5E3682D1`, `D74639504FED8D843E3830CE0C985ADA6EF6338E75C1E29DBC2286536D011926`, and `4B993258D87D198FE692B0166467B35CA7E1D021E84D9B0C15FBB49356B436DC`.

### Gate 2B save/readback requirement and applied result

- Historical requirement preserved: before mutation, supervisor had to reread every APPLY and protected row against the then-current saved IDB, apply one action at a time, read back exact state, save through supervisor-owned MCP, and record backup/final identities. The independent supervisor audit confirms this requirement passed for every row.
- Exact pre-mutation backup: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.pre-0002YC-20260725_221250.bak`, SHA256 `0D1A585975A358156DE06EA9B973B186DCBE4D3DDD9199F936559275BC1FDE78`, 143186049 bytes.
- First supervisor save: authoritative IDB temporarily reached SHA256 `66E9148534CD1C55EFB6CF4ABB44C594765E8825E3B1738FD4CBF092AA83D273`, 143186196 bytes, while function creation left `auto_analysis_ready:false`.
- Persistence recovery: the supervisor used the controlled launcher `-RestartOnce`. The first reopen exposed stale entry-regular `this` comments on both adjustors that the immediate pre-save cache had reported empty. The supervisor cleared exactly those two entry channels, read them back empty, saved again, and reopened a second time. No other item changed during recovery.
- Exact final saved checkpoint: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, SHA256 `2C20AAD81BC18DE1FA91B04D7FBEC30A704D377E6E2A2E35344C06EAEE479BC0`, 143186196 bytes, last write `2026-07-25T22:20:13.8438553-04:00`.
- Final reopened session `f085b224` reports `status:ok`, `auto_analysis_ready:true`, and Hex-Rays ready. Final lookup/type/comment/decompile/xref/byte/vtable/fence readback matches every applied/no-change row, the Pane decompile shows only the accepted Pane-owned comment, and both adjustor entry regular/repeatable channels remain empty. Gate 2B disposition is `APPLIED_VERIFIED`; B005 did not perform any mutation, save, restart, or readback.

## First-Draft C++ Recommendation

### UID0002YC target formal

UID0002YC's own destination CPP and H blocks must both be exactly blank. The wrapper has no authored C++ declaration or body beyond the class's virtual destructor declaration. The exact target destination shape is:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
```

### New exact ordinary-destructor child destination formals

Registered UID0004X2 owns the only destination-ready C++ body. Its H channel is explicitly blank because class UID0000BI already owns the declaration `virtual ~RadioGroupControlPane();`. The exact applied destination shape keeps the H BEGIN/END pair immediately after CPP END:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
RadioGroupControlPane::~RadioGroupControlPane()
{
    delete m_options;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
```

### UID0000BI support-class CPP-to-H migration formals

UID0000BI previously placed the complete declaration in formal CPP and left H blank. C2YC-35 moved the declaration byte-for-text without rewriting, reordering, summarizing, or duplicating any class line. Its exact current formal shape is:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class RadioGroupControlPane : public ControlPane
{
public:
    explicit RadioGroupControlPane(const RectBounds *bounds);
    virtual ~RadioGroupControlPane();

    void AddOption(const wchar_t *text, const RectBounds *bounds);
    void SetSelectedIndex(int selectedIndex);
    int GetSelectedIndex() const
    {
        return m_selectedIndex;
    }

    virtual void OnPaint();

private:
    List *m_options;
    int m_selectedIndex;
};

[[CHILDREN]]
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
```

The text from `class RadioGroupControlPane : public ControlPane` through `[[CHILDREN]]` is identical to the historical UID0000BI CPP payload. `[[CHILDREN]]` occurs exactly once, only in current H. Metadata remains `92/94`, `CANONICAL_OWNER:0000HY`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HY`, and blank position.

### Verified current generated CPP/H topology

- `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp`, SHA256 `0AFACB6D27C6C2881032C4A40E9E505664AFD3B742D8699CF22949AD1430CF82`, 9051 bytes, 278 lines, remains generated through by-file UID0000HY. Readback shows zero UID0002YC markers, zero UID0002YB markers, zero `class RadioGroupControlPane` declarations, exactly one UID0000BI empty-emitter marker, exactly one UID0004X2 annotation, and exactly one `RadioGroupControlPane::~RadioGroupControlPane()` definition with one `delete m_options;`.
- `auto-generated/NexusTK/ui/controls/ButtonControlPane.h`, SHA256 `67DA4E877DD7878961A08146CBA855CD95376485725CC99AB92F590FB6459203`, 862 bytes, 28 lines, was created by command `000000017510`. It contains exactly one UID0000BI annotation and exactly one complete `class RadioGroupControlPane : public ControlPane` declaration, preserving the constructor, virtual destructor, `AddOption`, `SetSelectedIndex`, inline `GetSelectedIndex`, `OnPaint`, `List *m_options`, and `int m_selectedIndex` text exactly once.
- Because UID0004X2 H is blank and no attached child contributes header text, the formal H `[[CHILDREN]]` marker renders as one `[[No Children Attached]]` placeholder in generated H. Generated H contains zero UID0004X2 annotations, zero destructor definitions, and zero duplicate RadioGroup declarations.
- The validator owns both generated files. B005 must not create, edit, or patch either generated artifact directly.

### Source-shape constraints

- Do not emit deleting flags, return `this`, vptr stores, explicit `Pane__Destructor`, explicit List vtable dispatch, `NexusTK_operator_delete_wrapper`, `_guard_check_icall_nop`, thunk functions, or alignment.
- Do not put the destructor body in UID0000BI or UID0000HY routers; the new by-memory child owns the method body and remains independently routed through the UID0000BI emitter graph when the class CPP channel becomes blank.
- Keep the current class declaration's `List *m_options` and `int m_selectedIndex` fields. Document `RadioGroupOption` as the inferred 144-byte record; do not force it into the destructor body.
- Keep declarations in UID0000BI H and definitions in child CPP. Do not leave the complete class in CPP, duplicate it across channels, move the UID0004X2 body into H, or add speculative includes/guards outside the accepted source shape.

## Final Recommendation

UID0002YC is fully understood as a class-owned compiler complete-object deleting wrapper and now emits no comment marker or body. Human reconstruction is UID0000BI's unchanged complete declaration in formal H plus registered exact child UID0004X2 emitting `delete m_options;` in CPP. C2YC-35 has closed the former CPP-routed declaration defect; UID0002YB remains compiler-only adjusted access. Exact target behavior, ordinary-body source shape, member/record layout, vtable routes, source placement, names, types, scores, and manual rows remain resolved. Independent supervisor Gate 2B applied and verified every accepted IDA action/protected row, final save, persistence recovery, and healthy reopen; only fresh exact-artifact continuity, supervisor execution/archive, and post-execution manual coverage remain pending.

## Recommended Target Doc Changes

- Applied: `COMPLETION:93`, `CONFIDENCE:95`, `CANONICAL_OWNER:0000BI`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS` and position, blank CPP/H, `Nested:0`.
- Exact Item Summary:
  - `Exact 103-byte compiler complete-object deleting wrapper for RadioGroupControlPane: restores primary/+0xa0/+0xa4 vptr views, deletes owned List *m_options at +0x108, invokes Pane teardown, and dispatches hidden flags between no storage release, project operator delete, or the 0x110-byte compiler no-op path; human source is the virtual destructor declaration plus the exact ordinary body at 0x00495fd0, so this page is semantic-owner compiler evidence and emits no C++.`
- Applied exact range/hash/CFG, flag, vptr, list/member, base teardown, no-op, xref, alignment, generated-state, negative-evidence, source-disposition, and historical comment-only decision sections from this report.
- Historicalized the former TRUE/emitter/comment-only route as a superseded workaround without erasing why it existed.

## Recommended Support Doc Changes

1. Applied to registered UID0004X2 `by-memory/0x00495fd0-0x00496005.RadioGroupControlPaneDestructorRaw.md`: `92/94`, owner/emitter UID0000BI, TRUE, position 20, exact CPP above, blank H, Nested 0, and all ordinary-body/fence/no-xref/source-shape evidence.
2. Applied to UID0002YB: `91/95`, NONE/FALSE/blank, exact per-thunk bytes/hashes/offsets/vtable routes/tail target, and compiler-only rationale.
3. Applied C2YC-35 to UID0000BI at retained `92/94`: preserved object size `0x110`, exact destructor child, `m_options` lifetime, 144-byte RadioGroupOption layout, UID0002YB/YC compiler exclusions, vtable island, source route, and every unrelated fact; blanked CPP and moved the complete declaration plus sole `[[CHILDREN]]` marker byte-for-text into H.
4. Applied to UID0000HY at retained `90/92`: synchronized RadioGroup ordinary/compiler split with retained broad/narrow historical file uncertainty.
5. Applied to UID000118 at retained `86/90`: exact ordinary child in address order, separate from padding and option helpers.
6. Applied to UID00011Y at retained `86/90`: exact UID0002YB/YC descriptions with human source linked to UID0004X2/UID0000BI.
7. Applied to UID00011E at `90/93`: List ownership and exact RadioGroupOption layout with raw-helper no-route history and separate-island comment-only policy preserved.
8. Applied to UID000252 at `86/93`: exact `[0x617e6c,0x617f10)` three-view vtable/RTTI island, slot values, xrefs, 164-byte hash, and compiler-data disposition with NONE/FALSE/non-emitting and unrelated aggregate evidence preserved.
9. Applied to UID00037L `by-memory/0x004f3810-0x004f38a7.ListScalarDeletingDestructor.md` at retained `87/92`, owner/emitter/source route, comment-only no-handwritten-wrapper formal, and UID000192 ordinary-source ownership. Its `Raw Code Evidence`/`Changes` preserves this exact historical-to-accepted mapping without deleting existing behavior/history: `At saved-IDB checkpoint 7509EC8477DC19D5028386F3DE945F319988B275B704DE7AF7A4C0CD10E3B331, the wrapper remained sub_4F3810, type _DWORD *__thiscall(_DWORD *Block, char), range [0x004f3810,0x004f38a7), with entry regular, entry repeatable, function regular, and function repeatable comments absent and one vtable xref from 0x0061ce2c. The accepted supervisor Gate 2B mapping is List_scalar_deleting_destructor with type List *__thiscall List_scalar_deleting_destructor(List *this, unsigned int deletingFlags) and function regular comment "Compiler-generated List complete-object deleting destructor used by List vtable slot zero. Releases List storage, destroys the object, and dispatches hidden deleting flags; no authored standalone source function." Entry regular, entry repeatable, and function repeatable remain absent. This IDA identity repair does not move authored List::~List() source from UID000192 or authorize wrapper C++ here.` Supervisor Gate 2B applied that mapping and final reopened session `f085b224` verified exact name/type/comment channels, one vtable xref, and unchanged incomplete-List/compiler-source boundaries; result `APPLIED_VERIFIED`.
10. Verified no ordinary-document edit was required for named Pane support path `by-memory/0x00544460-0x00545086.PaneCore.md`. It still declares UID0001EA, not supervisor-supplied UID00015Y; repository UID00015Y is unrelated `GeneralPurposePanel2SwitchActiveChild` and was not edited. PaneCore SHA256 remains `48FF2354735D8F6723ED80543C9CC23788537AB6F097340D9BF61DC7553E002B` and already records source reconstruction of `virtual Pane::~Pane()` from `[0x00544580,0x00544687)`, exact vptr/unregistration/region/handler/GrafPort teardown, compiler-generated derived/scalar routes, and rejection of stale `0x004b8d20` Pane ownership; a full-text scan still finds zero `ScrollableControlPane` occurrences. Those facts are the accepted corrected `Pane__Destructor` comment at same-or-greater detail. Supervisor Gate 2B removed the stale Scrollable-specific IDA prefix and final reopened readback verified the exact generic Pane-owned function regular comment, empty other channels, unchanged range/type, and 303 xrefs; result `APPLIED_VERIFIED`.

## Score And Metadata Recommendation

| UID/item | Assignment-time baseline | Implemented/current | Owner/emitter/reconstructable | Score rationale/cap |
| --- | --- | --- | --- | --- |
| 0002YC target | `87/89` | `93/95` | semantic 0000BI / blank / FALSE | All wrapper/source/field/type/name/route blockers closed; remaining uncertainty is original compiler spelling only, not behavior. |
| 0004X2 ordinary child | absent | `92/94` | 0000BI / 0000BI / TRUE / position 20 | Exact 53-byte source-shaped body and class semantics; no-xref retention caps confidence below 95. |
| 0002YB thunks | `86/90` | `91/95` | NONE / blank / FALSE | Exact bytes/routes/adjustments/no-source disposition; compiler function naming remains inferred. |
| 0000BI class | `90/91` | `92/94`; formal-channel migration applied | 0000HY / 0000HY / TRUE | Complete class layout, ordinary destructor, List ownership, option record, and vtable routes justify the score. C2YC-35 moved unchanged declaration text from CPP to H without changing metadata; exact original private spelling/file split still caps confidence. |
| 0000HY file | `90/92` | keep `90/92` | FILE | RadioGroup route improves, but final historical broad/narrow source split remains unresolved. |
| 000118 core index | `86/90` | keep `86/90` | NONE / blank / FALSE | New child synchronization improves detail but broad multi-owner index remains intentionally non-emitting. |
| 00011Y destructor index | `86/90` | keep `86/90` | NONE / blank / FALSE | Exact child roles improve; aggregate remains broad compiler/source index. |
| 00011E option helpers | `89/91` | `90/93` | 0000BI / 0000BI / TRUE | Reachable methods prove record/lifetime; retained raw helper starts still have no route. |
| 000252 read-only aggregate | `85/91` | `86/93` | NONE / blank / FALSE | Exact RadioGroup vtable island added; broad mixed data and unsplit neighbors remain completion caps. |
| 00037L List scalar wrapper | `87/92` | keep `87/92`; IDA `APPLIED_VERIFIED` | 000079 / 000079 / TRUE | Exact stable-7509-to-final identity/type/comment mapping is documented and applied while preserving compiler-only wrapper disposition and UID000192 source body; no score or formal change. |
| Named PaneCore path, actual UID0001EA (not supplied unrelated UID00015Y) | `89/92` | keep `89/92`; IDA comment `APPLIED_VERIFIED` | 0000A2 / blank / FALSE | Same-or-greater-detail/no-change proof covers exact Pane ordinary destructor ownership, behavior, compiler boundaries, and rejected stale alternative; supervisor Gate 2B applied and verified the matching generic Pane-owned IDA comment without an ordinary-doc edit. |

## Open Questions With Attempted Resolution

- Is UID0002YC authored source? Resolved no. Hidden ABI flags/storage dispatch and adjusted-vtable routes prove compiler generation.
- Where is authored destructor source? Resolved to raw `[0x495fd0,0x496005)` and a new exact by-memory child.
- Does zero xrefs invalidate the ordinary body? Resolved no. VA/RVA/raw pointer searches are zero, but exact class-specific vptr/member/base teardown makes retained source the highest-probability explanation. Confidence is capped at 94 rather than deferring.
- What is `+0x108`? Resolved `List *m_options`; constructor/AddOption/paint/destruction all agree.
- What is the element layout? Resolved exact 144 bytes: RectBounds plus `wchar_t[64]`; `RadioGroupOption` is the chosen human name.
- Is `0x110` a sized/vector/guarded delete? Resolved no. The target pushes 272 and calls one-byte `C3`; normal deallocation is a different branch.
- Should the wrapper retain comment-only formal C++? Resolved no. FALSE pages require blank formals and the class/ordinary child already express the source cause.
- Which channel owns the complete UID0000BI declaration? Resolved formal H. C2YC-35 migrated the exact declaration and sole child marker from the historical CPP placement without changing source text, metadata, ownership, or child CPP output; command `000000017510` verified the generated H and CPP split.
- What file owns the definition? Resolved current route UID0000HY/ButtonControlPane.cpp. Possible narrower historical split is documented and score-capped, not left as a blocker.
- Should the broad vtable island become a new source emitter? Resolved no for this callback. Exact evidence belongs in UID000252; compiler vtable bytes regenerate from the class and require no authored array.
- Are final source names proven? Original symbols are unavailable. Existing project names plus exact semantics support high-probability names; raw IDA names are rejected from final source.
- Were the accepted IDA recommendations applied and persisted? Resolved yes. Supervisor Gate 2B audit `2026-07-25T22:20:38-04:00` and catalog entry 0314 record exact `APPLIED_VERIFIED`/`NO_CHANGE_VERIFIED` results, backup `0D1A5859...DE78`, first save `66E91485...273`, stale-adjustor-entry-comment recovery, final IDB `2C20AAD8...BC0`, and healthy reopened session `f085b224` with analysis ready.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Current manual state:

- `by-memory/-coverage-report.md` has stale UID00011E `85%`, current UID000118/UID00011Y rows, stale UID000252 `84%`, and no direct UID0002YB/UID0002YC/new ordinary-destructor rows.
- `by-class/-coverage-report.md` has stale UID0000BI `90%` description.
- `by-file/-coverage-report.md` has current UID0000HY `90%` but lacks the exact RadioGroup ordinary/compiler split.
- B005 must not edit these collision-prone files.

Supervisor replacements/inserts only after fresh exact-artifact Gate 1 continuity for this post-Gate2B report revision, final continuity authorization, and supervisor-only report execution/archive. Gate 2A and Gate 2B are already complete for the accepted pre-reconciliation artifact and remain preserved in this report:

1. Insert immediately after the UID00011D row and before UID00011E, which is the exact address-ordered location inside the UID000118 child inventory. The validator-allocated child UID is `0004X2`:

```text
    - [UID:0004X2][0x00495fd0-0x00496005.RadioGroupControlPaneDestructorRaw](by-memory/0x00495fd0-0x00496005.RadioGroupControlPaneDestructorRaw.md) 0x00495fd0-0x00496005 | ordinary class destructor | RadioGroupControlPaneDestructor : reconstructable : 92% : very-strong : Exact 53-byte source-shaped RadioGroupControlPane ordinary destructor restores three class vptr views, deletes owned List *m_options at +0x108, and tail-chains to Pane teardown; authored C++ is only delete m_options, while UID0002YC carries compiler deleting flags/storage dispatch and UID0002YB carries adjusted entries.
```

2. Replace UID00011E in `by-memory/-coverage-report.md` with:

```text
    - [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md) 0x004964a0-0x0049662f | retained raw option-helper island | RadioGroupControlPaneOptionHelpers : reconstructable : 90% : very-strong : Class-owned retained helper island with exact no-start-xref proof and current comment-only no-standalone-body policy; reachable AddOption/OnPaint evidence fixes m_options as an owned List and each 0x90-byte RadioGroupOption record as RectBounds plus wchar_t text[64], while raw helper identities remain documented rather than falsely routed.
```

3. Replace UID00011Y and insert UID0002YB/UID0002YC immediately after it:

```text
    - [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md) 0x0049af11-0x0049b8d5 | destructor/thunk aggregate | ButtonChoiceControlDestructors : ignored : 86% : strong : Reviewed non-reconstructable multi-owner destructor/thunk index whose exact children carry source or compiler disposition; RadioGroup UID0002YB/UID0002YC are compiler-only adjusted/deleting support, while the validator-allocated 0x00495fd0 ordinary child and class UID0000BI carry human destructor source.
    - [UID:0002YB][0x0049afab-0x0049afc1.RadioGroupControlPaneAdjustorThunks](by-memory/0x0049afab-0x0049afc1.RadioGroupControlPaneAdjustorThunks.md) 0x0049afab-0x0049afc1 | compiler adjustor thunk pair | RadioGroupControlPaneAdjustorThunks : not_reconstructable : 91% : very-strong : Exact two 11-byte thunks subtract this by 0xa0/0xa4 and tail-jump to UID0002YC from secondary/tertiary RadioGroupControlPane vtable views; NONE/FALSE/non-emitting with blank source because class UID0000BI regenerates them.
    - [UID:0002YC][0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor](by-memory/0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor.md) 0x0049b420-0x0049b487 | compiler complete-object deleting wrapper | RadioGroupControlPaneScalarDeletingDestructor : not_reconstructable : 93% : very-strong : Exact 103-byte class-owned compiler wrapper restores three RadioGroupControlPane vptr views, deletes owned List *m_options, invokes Pane teardown, and dispatches hidden flags between no free, operator delete, or the 0x110-byte no-op path; human source is the virtual destructor declaration plus the exact 0x00495fd0 ordinary child, so this page emits no C++.
```

4. Replace UID000252 in `by-memory/-coverage-report.md` with:

```text
    - [UID:000252][0x00617a38-0x00618858.ControlPaneReadOnlyData](by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md) 0x00617a38-0x00618858 | mixed vtable/string-data index | ControlPaneReadOnlyData : not_reconstructable : 86% : very-strong : Non-emitting mixed control-family read-only-data index with current named anchors and exact child boundaries; RadioGroupControlPane island 0x00617e6c-0x00617f10 is now byte/slot/hash documented with primary UID0002YC and secondary/tertiary UID0002YB deleting routes, while unrelated unsplit vtable/string neighbors remain explicit completion caps.
```

5. Replace UID0000BI in `by-class/-coverage-report.md` with:

```text
- [UID:0000BI][RadioGroupControlPane](by-class/RadioGroupControlPane.md) : reconstructable : 92% : very-strong : Complete 0x110 ControlPane-derived radio-group declaration with owned List *m_options, int m_selectedIndex, exact 0x90 RadioGroupOption record layout, constructor/AddOption/selection/paint surface, validator-allocated ordinary destructor child, and compiler-only UID0002YB/UID0002YC deleting support routed through ButtonControlPane.
```

6. Replace UID0000HY in `by-file/-coverage-report.md` with:

```text
- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) : reconstructable : 90% : very-strong : Reusable button/choice-control module under NexusTK/ui/controls with complete class declarations and exact method children; RadioGroupControlPane human cleanup is the ordinary destructor at 0x00495fd0 while UID0002YB/UID0002YC are compiler-only adjusted/deleting support with no authored output, and the possible final ChoiceControlPane source split remains explicit.
```

UID0004X2 is the registered child identity in every payload/reference. B005 did not apply these supervisor-only coverage rows.

## Follow-Up Actions

1. Supervisor performs a wholly fresh exact-artifact Gate 1 continuity audit of this post-Gate2B reconciled report.
2. Supervisor confirms that accepted Gate 2A ordinary/support state and supervisor Gate 2B `APPLIED_VERIFIED` state remain continuous with this exact report artifact; no new ordinary callback or IDA mutation is authorized by this reconciliation.
3. Supervisor performs final Gate 1/Gate 2 continuity authorization against the exact report, destination, generated, and final saved/reopened IDB state.
4. Only after final continuity authorization, supervisor alone executes/archives the report; B005 never invokes `execute_report` or another lifecycle command.
5. Only after successful supervisor execution/archive, supervisor applies the already-reconciled UID0004X2 manual coverage payload and validates the changed coverage reports; B005 does not edit coverage reports. C2YC-35 requires no manual coverage-row change because score, ownership, path, reconstructable state, and description remain unchanged.

## Confidence

- Target behavior/range/hash/flags/vtable routes: exact.
- Target compiler-only disposition: very high.
- Ordinary-destructor source identity/body: very high; confidence capped below exact by zero inbound route.
- `List *m_options`, `m_selectedIndex`, object size, record layout: exact to very high.
- `RadioGroupOption` spelling: high-probability inference, not original-symbol proof.
- UID0000BI declaration-channel disposition: exact and applied. The declaration text is preserved byte-for-text in H; CPP is blank under C2YC-35.
- IDA identity/type/comment/UDT/instruction-comment state: exact and `APPLIED_VERIFIED` against final saved IDB `2C20AAD8...BC0` and healthy reopened session `f085b224`; protected bytes/vtables/fences/dependencies are `NO_CHANGE_VERIFIED`.
- IDA persistence: exact. The audit preserves backup `0D1A5859...DE78`, first save `66E91485...273`, controlled-reopen stale-adjustor-comment recovery, second save, and final analysis-ready reopen.
- Current source root: high; original broad/narrow physical filename remains the principal file-level uncertainty.
- Recommended target score `93/95` is justified because no unresolved behavior, ownership, emission, source-placement, member/type, naming, or compiler-boundary blocker remains.

## Validator Results

- Current validator-owned C2YC-35 state records command `000000017510` at `2026-07-25T04:52:56-04:00`, corresponding to `python .\tools\validator.py --mode file --file by-class/RadioGroupControlPane.md --apply --queue-timeout 240 --wait-generated`; recorded exit `0`, `ok: 1`, and generated refresh completed at the same command/timestamp. The recorded result includes the UID0000BI CPP block-to-blank and H blank-to-block registry updates, `autogen_cpp_update:1`, `autogen_header_create:1`, and unrelated pre-existing `missing_ref_uid` warnings for UID0003N6 and UID0003N7. B005 independently observed this current command/artifact state and did not invoke the command.
- Current command `000000017510` state leaves UID0000BI at SHA256 `90613076E4D8B39900DEDC3D032576733BA470C0B973B385F3FB1B4706B4A983`, 19879 bytes, 155 lines. This report-only reconciliation made no lease request and does not attribute the concurrent ordinary edit, lease, validator invocation, or generated refresh to B005.
- All callback validators were run serially from `source-3/project-documentation` as `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`. The retained initial callback used commands `000000017470`-`000000017480`, including final UID0004X2 `--wait-generated`; the resumed pass independently revalidated every exact current destination with commands `000000017482`-`000000017494`.
- Retained initial callback command `000000017470` at `2026-07-25T04:26:19-04:00` registered new `by-memory/0x00495fd0-0x00496005.RadioGroupControlPaneDestructorRaw.md` and allocated UID0004X2; exit `0`; generated refresh completed. Commands `000000017471`-`000000017479` then validated UID0002YC, UID0002YB, UID0000BI, UID0000HY, UID000118, UID00011Y, UID00011E, UID000252, and UID00037L; each exited `0` with `ok: 1`. Command `000000017480` at `2026-07-25T04:34:39-04:00` revalidated UID0004X2 with `--wait-generated`; exit `0`, `ok: 1`, generated refresh completed.
- Resumed exact-current command `000000017482` at `2026-07-25T04:35:51-04:00` validated UID0004X2; exit `0`, `ok: 1`; no target warning.
- Resumed exact-current command `000000017484` at `2026-07-25T04:36:18-04:00` validated UID0002YC; exit `0`, `ok: 1`; no target warning.
- Resumed exact-current command `000000017485` at `2026-07-25T04:36:24-04:00` validated UID0002YB; exit `0`, `ok: 1`; no target warning.
- Resumed exact-current command `000000017486` at `2026-07-25T04:36:38-04:00` validated UID0000BI; exit `0`, `ok: 1`; retained unrelated pre-existing `missing_ref_uid` warnings for UID0003N6 and UID0003N7.
- Resumed exact-current command `000000017488` at `2026-07-25T04:37:01-04:00` validated UID0000HY; exit `0`, `ok: 1`; no target warning.
- Resumed exact-current command `000000017489` at `2026-07-25T04:37:04-04:00` validated UID000118; exit `0`, `ok: 1`; retained unrelated pre-existing `missing_ref_uid` warnings for UID0003NA and UID0003NB.
- Resumed exact-current command `000000017490` at `2026-07-25T04:37:16-04:00` validated UID00011Y; exit `0`, `ok: 1`; no target warning.
- Resumed command `000000017492` at `2026-07-25T04:37:38-04:00` validated UID00011E; exit `0`, `ok: 1`; no target warning. Its deferred generated refresh was the historical pre-C2YC-35 physical ButtonControlPane revision and was superseded by command `000000017510` only for the accepted source-channel migration.
- Resumed exact-current command `000000017493` at `2026-07-25T04:37:49-04:00` validated UID000252; exit `0`, `ok: 1`; retained unrelated pre-existing `missing_ref_uid` warning for UID0003J8.
- Resumed exact-current command `000000017494` at `2026-07-25T04:37:58-04:00` validated UID00037L; exit `0`, `ok: 1`; no target warning.
- Every resumed validator reported a deferred generated refresh plus the expected `stats_incremental_noop` for its UID because that page is absent from generated completion-stat lists; each also reported `projected_stats_update` for the validator-owned projected-path section. No callback claim depends on the unrelated missing-reference warnings.
- Current physical `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp` is SHA256 `0AFACB6D27C6C2881032C4A40E9E505664AFD3B742D8699CF22949AD1430CF82`, 9051 bytes, 278 lines, command `000000017510`, refresh `2026-07-25T04:52:56-04:00`. It contains zero UID0002YC/UID0002YB output, one UID0000BI empty-emitter marker, zero RadioGroup class declarations, one UID0004X2 annotation, one destructor body, and one `delete m_options;` statement.
- Current physical `auto-generated/NexusTK/ui/controls/ButtonControlPane.h` is SHA256 `67DA4E877DD7878961A08146CBA855CD95376485725CC99AB92F590FB6459203`, 862 bytes, 28 lines, command `000000017510`, refresh `2026-07-25T04:52:56-04:00`. It contains one UID0000BI annotation, one unchanged complete class declaration, every accepted constructor/method/field exactly once, one `[[No Children Attached]]` placeholder, zero UID0004X2 annotations, and zero destructor definitions.
- B005 performed no validator, lease, ordinary/coverage/generated edit, IDA mutation, report execution, or lifecycle command during this same-report current-state reconciliation.

## Changed Files

- This post-Gate2B current-state reconciliation changed only this same report. UID0000BI and validator-owned generated CPP/H had already reached the C2YC-35 state recorded under command `000000017510`; supervisor-owned IDA Gate 2B had already reached the final saved/reopened state recorded in audit entry `2026-07-25T22:20:38-04:00` and catalog entry 0314. B005 observed those authoritative records read-only and does not claim any concurrent ordinary edit, lease, validator invocation, generated refresh, IDA mutation/save/restart/readback, audit/catalog edit, or lifecycle action. The ordinary/support artifacts below remain retained completed-callback evidence and were not edited during this reconciliation.
- Created UID0004X2 `by-memory/0x00495fd0-0x00496005.RadioGroupControlPaneDestructorRaw.md` (SHA256 `AA8B55B00B4A9758412CE446339FF72DA8D8BC35E1398A13E3AB75529E02F415`, 11816 bytes, 113 lines).
- Updated UID0002YC `by-memory/0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor.md` (SHA256 `31E143A4F65F8E517B63ABF7F3B8C783A3FB2A7F2E89E0957B7B6B08EBCBB97A`, 11164 bytes, 96 lines) and UID0002YB `by-memory/0x0049afab-0x0049afc1.RadioGroupControlPaneAdjustorThunks.md` (SHA256 `A4E84463E5941B6C735B923659010F9518250E2A0E57B9309B7D582188B48FA8`, 7761 bytes, 79 lines).
- Updated UID0000BI `by-class/RadioGroupControlPane.md` through C2YC-35 (SHA256 `90613076E4D8B39900DEDC3D032576733BA470C0B973B385F3FB1B4706B4A983`, 19879 bytes, 155 lines); UID0000HY `by-file/ButtonControlPane.md` remains SHA256 `42D9B78732B953F800983868F886CD6B53572B84D5B8457907EDF33773C4691E`, 38104 bytes, 207 lines.
- Updated UID000118 `by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md` (SHA256 `7E0246766FA8B16E415110DB5CB3C9F2ECA670AF0C22E90C7D9F8CB16E3CF770`, 32477 bytes, 195 lines) and UID00011Y `by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md` (SHA256 `B47C30D6BCC81B6EF7236F5B4C2AC58F808C34813B9BB3177B7EA11320E2E452`, 50501 bytes, 234 lines).
- Updated UID00011E `by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md` (SHA256 `444FA584AE4C8295EA95BE02B623B92382EEE67695FC6CF836D41F8E29030BFB`, 25011 bytes, 186 lines), UID000252 `by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md` (SHA256 `18FA88E199B5251FE22EE953FFB16382075E544F5487D5C952868A541BB53677`, 23932 bytes, 153 lines), and UID00037L `by-memory/0x004f3810-0x004f38a7.ListScalarDeletingDestructor.md` (SHA256 `39360B922EF59EA7A613D3B5124E52148AAB0056C3B9AF9F6224E5C8C454AB15`, 10139 bytes, 90 lines).
- Read-only no-change verification: actual UID0001EA `by-memory/0x00544460-0x00545086.PaneCore.md` remains SHA256 `48FF2354735D8F6723ED80543C9CC23788537AB6F097340D9BF61DC7553E002B`, 19486 bytes, 152 lines, with four exact `0x00544580-0x00544687` references and zero `ScrollableControlPane` matches.
- Validator-owned generated readback is current at command `000000017510`: `ButtonControlPane.cpp` SHA `0AFACB6D...0CF82`, 9051 bytes, 278 lines, and `ButtonControlPane.h` SHA `67DA4E87...9203`, 862 bytes, 28 lines. B005 reconciled only this same report with C2YC-35 already present/read-only verified and Gate 2B already supervisor-applied/verified. No ordinary by-* document, validator, lease, coverage report, direct generated/tracker/audit/catalog/supervisor/goal/lifecycle state, IDA database, or report location was touched during this reconciliation.

## Implementation Tracking Checklist

- [x] Supervisor verified the three literal TARGET/AUTHOR provenance headers immediately follow the title and that no fourth provenance header is present during accepted pre-callback Gate 1.
- [x] Supervisor verified C2YC-14..C2YC-16 use primary UID0002YC in the ledger while naming the then-planned validator-allocated ordinary child only in claim/destination/action text; callback registration resolved that child to UID0004X2.
- [x] Supervisor verified every actionable/protected IDA row was based on stable saved checkpoint `7509EC84...B331`, with `9DF44486...EB4C` historical only; independent Gate 2B later reread every item against exact backup/prestate `0D1A5859...DE78` before mutation.
- [x] Supervisor verified exact stack/lvar identities, types, absent/not-applicable regular and repeatable comment-channel states, deterministic readbacks, and the four padding-fence comment prestates.
- [x] Supervisor verified both corrected destination shapes: CPP keeps its inline `RECONSTRUCTION_CPP CODE:[[[]]]` plus CPP BEGIN/END, while H has only `RECONSTRUCTION_H CODE:BEGIN` and `END` immediately after CPP END; target H is blank because the wrapper owns no authored declaration, and UID0004X2 H is blank because class UID0000BI owns `virtual ~RadioGroupControlPane();`.
- [x] Supervisor verified read-only pre-callback generated provenance: ButtonControlPane.cpp SHA `3C54B90B...607E`, 9572 bytes, 295 lines, validator command `000000017440`, refreshed `2026-07-24T22:15:48-04:00`; B005 did not run that command.
- [x] Supervisor pre-callback exact-artifact Gate 1 validated this report's literal headings, evidence, scores, open-question closure, ledger, IDA handoff, coverage payload, and marker; that gate did not perform post-implementation Gate 2A.
- [x] After pre-callback Gate 1 passed, supervisor sent B005 the accepted implementation callback for ordinary/support changes and exact no-change verifications.
- [x] Created/registered UID0004X2 `by-memory/0x00495fd0-0x00496005.RadioGroupControlPaneDestructorRaw.md`; replaced the temporary child-UID placeholder everywhere.
- [x] Updated UID0002YC to `93/95`, semantic owner 0000BI, FALSE, blank emitter/position/CPP/H, Nested 0, with full report-level evidence and historicalized comment-only route.
- [x] Updated UID0002YB to `91/95`, NONE/FALSE/non-emitting/blank, Nested 0, with exact per-thunk evidence.
- [x] Historical callback updated UID0000BI to `92/94` without losing its complete class text or unrelated facts; independently observed current C2YC-35 state has that unchanged text in H with CPP blank.
- [x] Updated UID0000HY at retained `90/92` with the exact RadioGroup ordinary/compiler split and file-split caveat.
- [x] Synchronized UID000118 and UID00011Y while retaining NONE/FALSE/non-emitting index roles.
- [x] Updated UID00011E to `90/93` with exact List/RadioGroupOption facts while preserving raw-helper no-route history.
- [x] Updated UID000252 to `86/93` with exact RadioGroup vtable-island evidence while preserving unrelated mixed-index detail.
- [x] Updated UID00037L at retained `87/92` with the exact stable-7509 prestate and accepted `List_scalar_deleting_destructor` rename/type/function-comment mapping; preserved UID000192 as authored `List::~List()` source, existing compiler-only wrapper evidence, metadata, route, and formal.
- [x] Reread named `by-memory/0x00544460-0x00545086.PaneCore.md` as actual UID0001EA, confirmed SHA `48FF...002B`, verified same-or-greater Pane destructor detail and zero stale Scrollable text, and left it unchanged; unrelated UID00015Y was not edited.
- [x] Leased each changed ordinary file only immediately before its edit and released it immediately after its serial scoped validator.
- [x] Ran each changed ordinary file validator serially with `--apply --queue-timeout 240`; recorded exact command IDs/timestamps/exits/ok states/warnings/generated readback above.
- [x] Preserved the historical pre-C2YC-35 generated ButtonControlPane baseline: zero UID0002YC/UID0002YB output, exactly one UID0004X2 ordinary RadioGroup destructor body, one CPP-routed class declaration, no generated H sibling, and no unrelated drift.
- [x] Reconciled completed C2YC-01..34 ledger rows and the historical callback checklist using exact destination hashes and generated counts.
- [x] Recorded the D720 Gate 1 source-channel failure and added continuous C2YC-35 without altering completed callback evidence or the IDA handoff.
- [x] Added exact byte-for-text UID0000BI destination formals: CPP blank; H owns the unchanged complete declaration and `[[CHILDREN]]` exactly once; metadata/evidence unchanged.
- [x] Added implementation-verifiable expected `ButtonControlPane.cpp`/`.h` topology, callback validator requirements, support/source/score/current-state reconciliation, and repair-cycle changed-files boundaries before C2YC-35 authorization.
- [x] Recorded that exact artifact `908F426F...C7EDC` failed Gate 1 only because its pending/future C2YC-35 language lagged the concurrently applied current state.
- [x] Independently observed UID0000BI SHA `90613076...A983`: retained `92/94`/UID0000HY route, CPP exact blank, H byte-for-text class package, and one `[[CHILDREN]]`; B005 did not edit or lease the page.
- [x] Independently observed validator-owned command `000000017510` metadata and recorded result; B005 did not invoke the validator or claim the concurrent ordinary/generated mutation.
- [x] Verified current generated `ButtonControlPane.cpp` has zero RadioGroup class declarations, one UID0004X2 destructor definition, zero UID0002YC/UID0002YB output, one UID0000BI empty marker, and no unrelated RadioGroup drift; verified generated `ButtonControlPane.h` has exactly one unchanged UID0000BI declaration, one no-children placeholder, and zero destructor definitions/duplicates.
- [x] Reconciled C2YC-35 as already present/read-only verified, updated current destination/generated hashes/counts and actor boundaries, and preserved every historical validator/IDA/coverage fact.
- [x] Supervisor exact-artifact Gate 1 and Gate 2A accepted pre-IDA report SHA256 `2344A7DFE9C7ABA7A539032BAB349EB6E8B774059EAFDD2095F2876B32DB0F48` and verified C2YC-01..35 plus every ordinary/support implementation or no-change disposition claim by claim.
- [x] Supervisor reread every Gate 2B action/protected row against exact pre-mutation state, created backup `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.pre-0002YC-20260725_221250.bak` SHA256 `0D1A5859...DE78`, and applied/read back every accepted UDT/function/local/instruction-comment/Pane/List action as `APPLIED_VERIFIED` while preserving every protected row as `NO_CHANGE_VERIFIED`.
- [x] Supervisor recorded all 20 exact target/ordinary instruction-comment outcomes. Secondary decompiler-anchor warnings at `0x49b472`/`0x49b478` were non-fatal because immediate and both post-save reads returned exact regular text with repeatable channels empty.
- [x] Supervisor completed persistence recovery: first save `66E91485...273` left analysis pending; controlled reopen exposed stale entry-regular `this` comments on both adjustors; those two channels were cleared, saved again, and verified empty after the second reopen without any other repair mutation.
- [x] Supervisor final save/readback is `APPLIED_VERIFIED`: authoritative IDB SHA256 `2C20AAD8...BC0`, 143186196 bytes, last write `2026-07-25T22:20:13.8438553-04:00`; reopened session `f085b224` is healthy, analysis-ready, Hex-Rays ready, and matches all final/poststate and no-change rows.
- [x] B005 reconciled the complete supervisor Gate 2B audit/catalog evidence into this same report without mutating IDA or any ordinary/generated/coverage/audit/catalog/supervisor/lifecycle file.
- [ ] Supervisor performs a wholly fresh exact-artifact Gate 1 continuity audit of this post-Gate2B reconciled report.
- [ ] Supervisor performs final Gate 1/Gate 2 continuity authorization before report execution/archive; no new ordinary callback or IDA mutation is authorized unless current-state drift is found.
- [ ] After final continuity authorization, supervisor alone executes/archives the report; B005 never invokes `execute_report` or another lifecycle command.
- [ ] Only after successful supervisor execution/archive, supervisor applies the UID0004X2-reconciled exact coverage rows and validates coverage; B005 does not edit coverage reports.

READY_FOR_SUPERVISOR_GATE1_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000017513","destination_path":"executed-b-agent-research/B005/0002YC-RadioGroupControlPaneScalarDeletingDestructor-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0002YC-RadioGroupControlPaneScalarDeletingDestructor-empty-emitter-source-quality.md","timestamp":"2026-07-25T22:33:01-04:00","uid":"0002YC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
