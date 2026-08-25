** TARGET-REPORT-UID:0002SH **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# UID0002SH NewUserDialogPane2VtableData Source-Quality Report


## Finalized Report / Current Recommendation

UID0002SH is now implemented as non-emitting compiler-generated vtable support for [UID:00009E][NewUserDialogPane2](../../../by-class/NewUserDialogPane2.md), not as a reconstructable source statement with its own emitted C++ marker. During the B014 callback, the target metadata was changed from reconstructable/emitting `85/89` to non-reconstructable/non-emitting `88/92`, and the direct class owner was preserved.

Current callback result: `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, `CANONICAL_OWNER:00009E`, `COMPLETION:88`, `CONFIDENCE:92`, and a blank formal C++ block with an explicit no-code proof. The source output is represented by the `NewUserDialogPane2` class declaration and exact virtual method children; hand-authoring a vtable array would be less source-quality than letting the compiler regenerate the data.

## Supporting Research

Historical report-only note: the initial Gate 1 artifact edited only this report in `tools/leaser/Agents/Agent-B014/research/` and did not edit by-* docs, generated files, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers.

Implementation callback note: after supervisor Gate 1 approval, B014 leased and edited the target plus direct support docs listed in this report, ran scoped validators for every changed by-* file, released the leases, and updated this report ledger/checklist. B014 did not manually edit generated output, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers, and did not run `execute_report` or lifecycle variants.

Local documentation reviewed:

- `by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md`
- `by-class/NewUserDialogPane2.md`
- `by-file/NewUserDialogPane2.md`
- `by-file/CreateUserDialogs.md`
- `by-memory/0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData.md`
- `by-memory/0x0061fd94-0x0061fd9c.NewUserDialogPane2TertiaryVtableTail.md`
- sibling create-user vtable pages `by-memory/0x0061fda0-0x0061fe30.NewCreateUserDialogPaneVtableData.md` and `by-memory/0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData.md`
- `auto-generated/NexusTK/login/NewUserDialogPane2.cpp`
- `by-structure.md`
- `auto-generated/-ag-research-tracker.md` and `project-level/-auto-completion-stats.md`

Existing-report searches used `0002SH`, `0061fd04`, `0061fd94`, `NewUserDialogPane2VtableData`, `NewUserDialogPane2`, and `??_7NewUserDialogPane2`. Matching historical notes from A001/B004/B010 were treated as leads and rechecked against current target/support docs and active MCP evidence.

## Target

- UID: `0002SH`
- Target: `by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md`
- Pre-callback metadata: `COMPLETION:85`, `CONFIDENCE:89`, `CANONICAL_OWNER:00009E`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009E`
- Post-callback metadata: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:00009E`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++ block.
- Post-callback generated state: validator-owned `auto-generated/NexusTK/login/NewUserDialogPane2.cpp` refresh command `000000006087`, refreshed `2026-07-04T04:34:16-04:00`, no longer includes a UID0002SH empty marker.

## Current Target State

The page now identifies the range as `0x0061fd04-0x0061fd94`, owned by `NewUserDialogPane2`, ending before the separate tertiary tail child at `0x0061fd94-0x0061fd9c`, and implemented as non-reconstructable/non-emitting compiler output. It rejects hand-authored vtable bytes in prose and metadata: the only source representation is the class declaration/virtual method set on [UID:00009E][NewUserDialogPane2](../../../by-class/NewUserDialogPane2.md) and its exact child methods.

Current generated `NewUserDialogPane2.cpp` emits the `NewUserDialogPane2` class declaration, constructor, selector methods, command/event handlers, submit/account packet helper, character request, and reply handler. After the callback validators, UID0002SH no longer contributes an empty marker; unrelated singleton storage pages still have their own empty markers.

## Heuristic / Inference Reanalysis And Validation

The key source-quality question is whether an exact vtable-data page should emit any C++ of its own. Current evidence says no:

- The active IDB has decorated MSVC vtable names at `0x0061fd04`, `0x0061fd64`, and `0x0061fd94`, but no local `NewUserDialogPane2` UDT/type declaration. This proves the data is compiler/RTTI output, not a source array recovered from project code.
- Constructor and destructor code install the vtable addresses as compiler output. Source-quality C++ should express `class NewUserDialogPane2 : public DialogPane` with virtual methods and destructor, not raw assignments to `this`, `this+0xa0`, or `this+0xa4`.
- The class page already has a formal declaration block with `virtual ~NewUserDialogPane2()`, virtual handlers, fields, and `[[CHILDREN]]`. Exact method children already emit or no-code themselves. That is the correct source route that causes the vtable to exist.
- The adjacent tertiary child [UID:000445][0x0061fd94-0x0061fd9c.NewUserDialogPane2TertiaryVtableTail](../../../by-memory/0x0061fd94-0x0061fd9c.NewUserDialogPane2TertiaryVtableTail.md) is already `RECONSTRUCTABLE:FALSE`, blank emitter, blank C++, with the same generated-vtable rationale. UID0002SH should use the same no-code/generated-data policy for the primary/secondary vtable block.
- The current `RECONSTRUCTABLE:TRUE` setting conflicts with the page's own reconstruction note: "Do not hand-author this vtable." Keeping TRUE forces an empty generated marker and keeps the page in the reconstructable not-covered queue despite having no standalone source payload.

Rejected alternatives:

- Do not emit a `static void *NewUserDialogPane2Vtable[]` or similar table. That is not plausible original application source and would fight the compiler's class/vtable generation.
- Do not move ownership back to [UID:0000IK][CreateUserDialogs](../../../by-file/CreateUserDialogs.md). That page is now a non-emitting family/index; the direct owner remains the class [UID:00009E].
- Do not fold this range into [UID:00025Z][0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData](../../../by-memory/0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData.md). The target is already a useful exact child with precise class ownership and boundary evidence.
- Do not merge the `0x0061fd94-0x0061fd9c` tertiary tail back into UID0002SH. The separate child is supported by current names, xrefs, slot values, and the `0x0061fda0` successor boundary.

## Evidence Standards Used

Evidence priority:

1. Current IDA MCP session `aa3930bd` for active IDB/session health, names, function/nonfunction status, xrefs, bytes, dword values, and decompilation.
2. Current by-* target/support docs for established owner/emitter route and existing class declaration/source split.
3. Validator-owned generated `auto-generated/NexusTK/login/NewUserDialogPane2.cpp` as generated-output state, not primary proof.
4. `by-structure.md` for source-declared/generated-binary data, ownership, emitter, and code-entry rules.
5. Historical A001/B004/B010 notes only as leads revalidated by current docs/MCP.

Numeric conversions checked with `tools/int_convert.py`: `0x90` = 144, `0x60` = 96, `0x30` = 48, `0x08` = 8, `0xb07` = 2823, `0x9e9` = 2537, and `0x6c` = 108 (Verified with int_convert.py).

## Evidence Checked

- MCP `idb_list` JSON-RPC id `6`: one active worker session `aa3930bd`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, owned/adopted, not analyzing.
- MCP `server_health` id `7`: status `ok`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- MCP `lookup_funcs` id `8`: `0x0061fd04`, `0x0061fd64`, `0x0061fd94`, and `0x0061fda0` are not functions; `0x0052a540` is `sub_52A540` size `0xb07` / 2823 bytes (Verified with int_convert.py); `0x0052b050` is not a function; `0x0052f8e0` is `sub_52F8E0` size `0x6c` / 108 bytes (Verified with int_convert.py); `0x0052f772` and `0x00544e90` are tiny function slots.
- MCP `xrefs_to` id `13`: `0x0061fd04`, `0x0061fd64`, and `0x0061fd94` each have exactly three data xrefs from the `NewUserDialogPane2` constructor, the unmodeled complete-destructor body, and scalar deleting destructor. `0x0061fda0` has a separate three-ref group from `NewCreateUserDialogPane`.
- MCP `get_int` id `24`: representative dwords are `0x0061fd04 -> 0x0052f8e0`, `0x0061fd08 -> 0x004f4b10`, `0x0061fd0c -> 0x0041b6c0`, `0x0061fd60 -> 0x0064c7e8`, `0x0061fd64 -> 0x0052f767`, `0x0061fd68 -> 0x0052b940`, `0x0061fd90 -> 0x0064c7fc`, `0x0061fd94 -> 0x0052f772`, `0x0061fd98 -> 0x00544e90`, `0x0061fd9c -> 0x0064c810`, and `0x0061fda0 -> 0x0052f870`.
- MCP `get_bytes` id `27`: `0x0061fd04` for 160 bytes shows the full `0x90` / 144-byte primary+secondary target span plus the following `0x0061fd94` tertiary tail and `0x0061fda0` successor control bytes.
- MCP `entity_query` / `list_globals` ids `33` and `34`: active IDB names include `??_7NewUserDialogPane2@@6B@` at `0x0061fd04`, `??_7NewUserDialogPane2@@6B@_0` at `0x0061fd64`, `??_7NewUserDialogPane2@@6B@_1` at `0x0061fd94`, plus NewUserDialogPane2 RTTI and PlainMemberFunctionObject RTTI/vtables. These are compiler decorated names, not source arrays.
- MCP `type_query` id `35` and `search_structs` id `36`: no local UDT/type/structure records for `NewUserDialogPane2`.
- MCP `find_bytes` id `37`: absolute VA pointer bytes for `0x0061fd04`, `0x0061fd64`, `0x0061fd94`, and `0x0061fda0` have exactly three hits each, matching constructor/complete-destructor/scalar-deleting-destructor stores.
- MCP `find_bytes` id `42`: corresponding RVA patterns `04 fd 21 00`, `64 fd 21 00`, `94 fd 21 00`, and `a0 fd 21 00` have zero hits.
- MCP `decompile 0x0052a540` id `39`: constructor writes `NewUserDialogPane2::vftable` to `this`, `this+160`, and `this+164`, publishes/clears `unk_69B4A4`, initializes `+0x278`/`+0x27c`, and constructs UI resources/controls.
- MCP `decompile 0x0052f8e0` id `40`: scalar deleting destructor writes the same three vtable views, destroys `+0x27c`, clears `unk_69B4A4`, calls the base destructor, and conditionally frees.
- MCP `get_bytes` id `41`: raw bytes around `0x0052a5a8`, `0x0052b050`, and `0x0052f8e8` show immediate stores of `04 fd 61 00`, `64 fd 61 00`, and `94 fd 61 00`; bytes around `0x0052c3c8` show the successor `a0 fd 61 00` store for `NewCreateUserDialogPane`.
- Generated output checked locally before callback: `auto-generated/NexusTK/login/NewUserDialogPane2.cpp` included the class declaration and method bodies, then an empty marker for UID0002SH. Post-callback generated refresh command `000000006087` (`validator-refreshed-at: 2026-07-04T04:34:16-04:00`) removes UID0002SH from generated output; only unrelated singleton empty markers remain.

## Claim And Incorporation Ledger

| Claim ID | Claim | Action | Destination | Verification state |
| --- | --- | --- | --- | --- |
| C1 | UID0002SH is exact `.rdata` vtable data range `0x0061fd04-0x0061fd94`, size `0x90` / 144 bytes, covering primary `0x0061fd04` and secondary `0x0061fd64` table views. | incorporate | Target range/boundary/evidence | applied: target Evidence and Score Rationale now record exact range, `0x90`/144 size, slot dwords, and full-byte/span proof; validator `000000006084` ok. |
| C2 | `0x0061fd94` is a separate tertiary `NewUserDialogPane2` vtable-tail child, and `0x0061fda0` starts `NewCreateUserDialogPane` vtable data. | incorporate | Target boundary notes; support tail/aggregate pages | applied/already-present: target Boundary Notes and new Evidence row record the tail/successor boundary; tertiary tail page was already non-emitting and consistent; aggregate row updated; validators `000000006084` and `000000006086` ok. |
| C3 | Current MCP xrefs and pointer-byte scans show only constructor/complete-destructor/scalar-deleting-destructor stores for UID0002SH table bases, with zero RVA-pattern hits. | incorporate | Target evidence and score rationale | applied: target Evidence records the three store groups, VA hits, zero RVA hits, decompile stores, and bytes; validator `000000006084` ok. |
| C4 | Active IDB has decorated vtable/RTTI names for `NewUserDialogPane2` but no local UDT/source type; source output should rely on the inferred class declaration, not hand-authored table data. | incorporate | Target no-code proof and class/file support notes | applied: target no-code proof plus class/file support notes now record decorated table names, no local UDT/type, and class/method source route; validators `000000006084`, `000000006085`, and `000000006087` ok. |
| C5 | The current target metadata causes an empty generated marker; the correct disposition is non-reconstructable/non-emitting generated-binary support under owner [UID:00009E]. | incorporate | Target metadata and support docs | applied: target is now `RECONSTRUCTABLE:FALSE`, blank emitter, `88/92`; generated refresh `000000006087` removed UID0002SH empty marker. |
| C6 | `NewUserDialogPane2` class declaration and exact child virtual methods already provide the source route that regenerates the vtable. | already-present | `by-class/NewUserDialogPane2.md`, `by-file/NewUserDialogPane2.md`, generated C++ | already-present/applied: class declaration and method output already existed; class/file notes were updated to make this route explicit; generated `NewUserDialogPane2.cpp` retains class/method output and no UID0002SH marker. |
| C7 | Recommended target score is `88/92`, preserving `CANONICAL_OWNER:00009E` and blank C++ while changing `RECONSTRUCTABLE:FALSE` and blanking `EMITTER_UIDS`. | incorporate | Target metadata | applied: target header now has `COMPLETION:88`, `CONFIDENCE:92`, owner `00009E`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank emitter position, and blank formal C++; validator `000000006084` ok. |

## Positive Evidence Summary

- Ownership is strong: active IDB decorated names, constructor stores, destructor stores, current class/file docs, and generated output all tie this block to `NewUserDialogPane2`.
- Boundary is strong: the current target covers exactly `0x0061fd04-0x0061fd94`; MCP dwords and names show `0x0061fd94` is the separate tertiary tail and `0x0061fda0` is the next class's vtable block.
- No handwritten source payload is needed: class declaration and virtual methods are already emitted through [UID:00009E] and exact child pages, while the vtable bytes are compiler output.
- Negative pointer-pattern checks are clean: absolute VA hits are limited to the expected three store sites per table base, and RVA patterns have zero hits.
- Local precedent supports the recommendation: adjacent UID000445 is already non-reconstructable/non-emitting for the same generated-vtable reason.

## Negative Evidence Summary

- There is no local recovered `NewUserDialogPane2` UDT/type declaration in the active IDB. Exact original inherited-interface spellings remain inferred from docs and generated output.
- There is no plausible source-level global/table object for the vtable bytes. Emitting a C++ array would be an artificial reconstruction artifact.
- The current target has no source code block to add without duplicating class declaration or child method content owned elsewhere.
- Sibling vtable pages for other create-user classes still contain older `RECONSTRUCTABLE:TRUE` vtable metadata; they are context, not authority for this target's repair.

## Ranked Ownership Analysis

1. [UID:00009E][NewUserDialogPane2](../../../by-class/NewUserDialogPane2.md): best owner. Active IDB names, constructor/destructor vtable stores, class declaration, and exact method children all point here. Keep as `CANONICAL_OWNER`.
2. [UID:0000LW][NewUserDialogPane2](../../../by-file/NewUserDialogPane2.md): correct source root through the class route, but not the direct semantic owner of the vtable block. Use only as generated output context through the class.
3. [UID:0000IK][CreateUserDialogs](../../../by-file/CreateUserDialogs.md): rejected as direct owner. It is a non-emitting family/index page and would reintroduce the old umbrella ambiguity.
4. [UID:00025Z][0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData](../../../by-memory/0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData.md): rejected as owner/emitter because it is a mixed aggregate spanning multiple classes and resources. It should keep a child-link summary only.
5. Standalone by-global/by-type vtable owner: rejected. Current evidence supports compiler-emitted class vtable data, not an original source global declaration.

## Source Placement

The source placement remains `NexusTK/login/NewUserDialogPane2.cpp` through [UID:0000LW], but UID0002SH itself should not emit source. The vtable is regenerated when the project compiles the `NewUserDialogPane2` class declaration and virtual method definitions. Therefore the by-memory page should be a non-emitting support page under [UID:00009E], not a child that contributes an empty marker to the generated `.cpp`.

## First-Draft C++ Recommendation

No source C++ should be inserted for UID0002SH. The exact formal block should remain blank:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

No-code proof: this page represents compiler-emitted vtable and RTTI-adjacent data. The source-level construct is already the `NewUserDialogPane2` class declaration, destructor declaration, virtual handler declarations, and exact method bodies emitted by [UID:00009E] and its children. A raw vtable initializer would use addresses, generated names, and compiler layout artifacts that would not have existed in the original developer source.

## Final Recommendation

This callback was implemented as a metadata/source-disposition repair, not a C++ insertion. UID0002SH is now `88/92`, owner [UID:00009E] is unchanged, `RECONSTRUCTABLE:FALSE`, `EMITTER_UIDS` is blank, the formal C++ block remains empty, and the current MCP no-code/generated-vtable proof is documented. After validation, generated `NewUserDialogPane2.cpp` no longer contains a UID0002SH empty marker.

## Recommended Target Doc Changes

Applied to `by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md`:

- Set `COMPLETION:88`.
- Set `CONFIDENCE:92`.
- Kept `CANONICAL_OWNER:00009E`.
- Changed `RECONSTRUCTABLE:FALSE`.
- Cleared `EMITTER_UIDS`.
- Kept `EMITTER_POSITION_OPTIONAL` blank.
- Kept the formal `RECONSTRUCTION_CPP CODE` block blank.
- Updated the item summary, range/disposition, reconstruction notes, no-code proof, evidence, score rationale, and change log with MCP session `aa3930bd`: active IDB/health, exact range size, named table bases, xrefs, dword slots, byte-span boundary, VA/RVA pointer-pattern results, constructor/destructor vtable-store decompilation, lack of UDT/type records, and generated-output empty-marker rationale.
- Recorded that the class declaration and exact child virtual methods regenerate the data; no hand-authored vtable bytes should be emitted.

## Recommended Support Doc Changes

- `by-class/NewUserDialogPane2.md`: applied a narrow support note that UID0002SH is source-declared/generated-binary vtable support, non-emitting/no-code; the class declaration and virtual method children are the source representation that regenerates the primary/secondary vtable data. Existing class declaration C++ and inherited-interface caveats were preserved.
- `by-file/NewUserDialogPane2.md`: applied boundary/evidence/internal-split/change-log notes so UID0002SH is not expected to emit an empty marker; generated `NewUserDialogPane2.cpp` contains class/method output but no handwritten vtable array. File score was unchanged.
- `by-memory/0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData.md`: applied observed-content, evidence, exact-child, and change-log support rows for UID0002SH as exact non-emitting generated vtable support under `NewUserDialogPane2`; the aggregate remains non-reconstructable/non-emitting.
- `by-memory/0x0061fd94-0x0061fd9c.NewUserDialogPane2TertiaryVtableTail.md`: already-present at same-or-greater detail; no edit required because it already says non-reconstructable/non-emitting generated-vtable support.
- `by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md`: already-present/no contradiction; no edit required because it treats exact children as carrying source/no-code proofs and does not require UID0002SH as a reconstructable empty emitter.
- Sibling `NewCreateUserDialogPane` and `CreateUserDialogPane` vtable pages were not edited; no direct UID0002SH contradiction blocked this callback.

## Score And Metadata Recommendation

| Field | Pre-callback | Post-callback | Rationale |
| --- | --- | --- | --- |
| `COMPLETION` | `85` | `88` | Current MCP refresh adds exact size, slot/name/xref/byte evidence, explicit no-code proof, and generated-empty-marker diagnosis. |
| `CONFIDENCE` | `89` | `92` | Ownership, boundary, and no-code disposition are strongly supported by active IDB names, xrefs, slot values, decompile evidence, generated class output, and local tertiary-tail precedent. |
| `CANONICAL_OWNER` | `00009E` | unchanged | Direct class owner is correct. |
| `RECONSTRUCTABLE` | `TRUE` | `FALSE` | This exact page is compiler-generated vtable data regenerated from class/virtual declarations; it should not emit source or an empty marker. |
| `EMITTER_UIDS` | `00009E` | blank | No source payload belongs to this page. The class page already emits the declaration/method children. |
| `EMITTER_POSITION_OPTIONAL` | blank | blank | No emitter route remains. |
| Formal C++ | blank | blank | Blank is correct, but must be explained as no-code/generated-vtable proof. |

Do not raise to final-audit `95+`: exact original inherited-interface spelling and full class type declaration remain inferred, and the sibling create-user vtable pages still use older metadata that may need separate policy cleanup.

## Open Questions With Attempted Resolution

| Question | Checks attempted | Resolution / impact |
| --- | --- | --- |
| Is UID0002SH still a reconstructable source-bearing page? | Current target/support docs, generated output, class declaration, MCP names/xrefs/bytes/decompilation, tertiary-tail precedent. | No. It is source-declared/generated-binary support and should be `RECONSTRUCTABLE:FALSE`, blank emitter, blank C++. |
| Should any vtable C++ be hand-authored? | MCP decorated vtable names, constructor/destructor vtable stores, class declaration output, by-structure code-entry rules. | No. Hand-authored vtable arrays would be decompiler-shaped/compiler-artifact source. |
| Is the boundary still `0x0061fd04-0x0061fd94`? | MCP `get_int`, `get_bytes`, `xrefs_to`, names, sibling tail page, successor `0x0061fda0` checks. | Yes. `0x0061fd94` is the separate tertiary tail, and `0x0061fda0` starts `NewCreateUserDialogPane`. |
| Are exact original inherited interface/type names recovered? | MCP `entity_query`, `list_globals`, `type_query`, `search_structs`; class/file docs. | No local UDT/type records were found. This is a class-declaration confidence cap, not a reason for UID0002SH to emit bytes. |
| Should sibling vtable pages be repaired too? | Reviewed sibling docs and local policy. | Not in this report's required scope. Note adjacent policy debt but repair only UID0002SH/support unless supervisor expands scope. |

## Validator Results

Scoped validators were run from `source-3/project-documentation` for every changed by-* doc:

| File | Command | command_id | command_timestamp | Exit | ok | Warnings / effects |
| --- | --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md` | `python .\tools\validator.py --mode file --file by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md --apply --queue-timeout 240` | `000000006084` | `2026-07-04T04:34:15-04:00` | 0 | 1 | `completion_update 88`, `confidence_update 92`, registry `reconstructable true -> false`, emitter `00009E ->` blank, stats row removed from `by-memory_Reconstructable`, generated refresh deferred. |
| `by-class/NewUserDialogPane2.md` | `python .\tools\validator.py --mode file --file by-class/NewUserDialogPane2.md --apply --queue-timeout 240` | `000000006085` | `2026-07-04T04:34:15-04:00` | 0 | 1 | `stats_incremental_noop`; generated refresh deferred. |
| `by-file/NewUserDialogPane2.md` | `python .\tools\validator.py --mode file --file by-file/NewUserDialogPane2.md --apply --queue-timeout 240` | `000000006087` | `2026-07-04T04:34:16-04:00` | 0 | 1 | `stats_incremental_noop`; generated refresh deferred. |
| `by-memory/0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData.md` | `python .\tools\validator.py --mode file --file by-memory/0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData.md --apply --queue-timeout 240` | `000000006086` | `2026-07-04T04:34:15-04:00` | 0 | 1 | `stats_incremental_noop`; generated refresh deferred. |

Generated freshness check: queue status command `000000006094` at `2026-07-04T04:35:03-04:00` showed generated refreshes still queued/processing, but `auto-generated/NexusTK/login/NewUserDialogPane2.cpp` had already refreshed to `validator-command-id: 000000006087`, `validator-refreshed-at: 2026-07-04T04:34:16-04:00`. Local `rg` confirmed UID0002SH and `NewUserDialogPane2VtableData` no longer appear in the generated file. Only unrelated singleton empty markers for UID0002X3 and UID0002X4 remain.

## Changed Files

Callback changed files:

- `by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md`
- `by-class/NewUserDialogPane2.md`
- `by-file/NewUserDialogPane2.md`
- `by-memory/0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData.md`
- `tools/leaser/Agents/Agent-B014/research/0002SH-NewUserDialogPane2VtableData-source-quality.md`

Validator-owned side effects reported by scoped validators:

- `auto-generated/NexusTK/login/NewUserDialogPane2.cpp` refreshed to command `000000006087` and removed the UID0002SH empty marker.
- `project-level/-auto-completion-stats.md` projected path completion section updated; UID0002SH was removed from the by-memory reconstructable stats row by validator command `000000006084`.
- Validator registry updates were performed by validator command `000000006084` for UID0002SH reconstructable/emitter metadata. B014 did not manually edit validator state.

No coverage reports, lifecycle/archive files, supervisor ledgers, or generated files were manually edited. B014 did not run `execute_report` or any lifecycle variant.

## Implementation Tracking Checklist

- [x] Applied in `by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md`: set `COMPLETION:88`, `CONFIDENCE:92`, kept `CANONICAL_OWNER:00009E`, changed `RECONSTRUCTABLE:FALSE`, cleared `EMITTER_UIDS`, kept emitter position blank, and kept formal C++ blank. Validator `000000006084` ok.
- [x] Applied target no-code proof and evidence for MCP session `aa3930bd`: active IDB/health, exact nonfunction range, named table bases, primary/secondary/tertiary/successor boundaries, xrefs, slot dwords, bytes, VA/RVA pattern hits, constructor/destructor decompile stores, no local UDT/type records, and generated empty-marker diagnosis. Validator `000000006084` ok.
- [x] Applied `by-class/NewUserDialogPane2.md` support wording so UID0002SH is non-emitting vtable support regenerated by the class declaration and exact virtual-method children. Validator `000000006085` ok.
- [x] Applied `by-file/NewUserDialogPane2.md` support wording so generated `NewUserDialogPane2.cpp` is expected to contain class/method output but no UID0002SH empty marker or hand-authored vtable array. Validator `000000006087` ok.
- [x] Applied `by-memory/0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData.md` observed-contents/support row for UID0002SH as non-emitting generated-vtable support. Validator `000000006086` ok.
- [x] Verified `by-memory/0x0061fd94-0x0061fd9c.NewUserDialogPane2TertiaryVtableTail.md` and `by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md`; both were already consistent, so no edit was needed.
- [x] Excluded sibling vtable pages outside UID0002SH scope: no direct contradiction blocks UID0002SH, and supervisor explicitly limited sibling edits.
- [x] Ran scoped validators for every changed by-* doc and recorded command, command_id, timestamp, exit code, ok count, warnings, and generated refresh effects in `Validator Results`.
- [x] Checked validator-owned `auto-generated/NexusTK/login/NewUserDialogPane2.cpp` freshness after validation: header is `validator-command-id: 000000006087`, `validator-refreshed-at: 2026-07-04T04:34:16-04:00`, and UID0002SH no longer emits an empty marker.
- [x] Updated this report's Claim And Incorporation Ledger and checklist states as `applied`, `already-present`, or `excluded-with-reason` with proof.
- [x] Confirmed no manual edits to generated files, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers; B014 did not run `execute_report` or lifecycle variants.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000006118","destination_path":"executed-b-agent-research/B014/0002SH-NewUserDialogPane2VtableData-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B014/research/0002SH-NewUserDialogPane2VtableData-source-quality.md","timestamp":"2026-07-04T05:05:02-04:00","uid":"0002SH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
