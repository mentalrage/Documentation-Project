** TARGET-REPORT-UID:0003M2 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003M2 **
# 0003M2 StaticObjImageLibScalarDeletingDestructor Ownership / Split Research

## Finalized Report / Current Recommendation
- Current recommendation: assign [UID:0003M2][0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor](by-memory/0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor.md) to [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md), with `EMITTER_UIDS:0000E2`.
- Final disposition: no split, no reclassification, no new owner, no adjacent ImageLib-family repair required. Keep the item reconstructable, source-declared/generated-binary, and with blank final C++.
- Required action: update target metadata from no-owner/non-emitting to class-owned/emitting through `StaticObjImageLib`; refresh the by-memory coverage row text listed below. Do not hand-port this scalar deleting destructor as final source.
- Confidence: strong. Live IDA MCP confirms the exact function boundary, destructor cleanup parity, vtable slot, constructor/destructor/scalar-destructor vptr refs, singleton clear, delete-flag behavior, guard path, and neighboring padding.

## Supporting Research

## Target
- Target UID: `0003M2`
- Target path: `by-memory/0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor.md`
- Source queue/report row: `auto-generated/-ag-memory-coverage.md`, currently no-owner with `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`.
- Tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, row `0003M2`, assigned to Agent-B001 on 2026-06-13.
- Current scores and parent state: `COMPLETION:82`, `CONFIDENCE:90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`.
- Current generated state: no-owner and non-emitting in `auto-generated/-ag-memory-coverage.md`.

## Executive Recommendation
The best direct semantic owner is [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md). This target is the first slot of the `StaticObjImageLib` vtable, restores the `StaticObjImageLib` vtable inside its own body, performs the same cleanup as the ordinary `StaticObjImageLib` destructor, clears [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md), and then adds compiler scalar-delete flag handling. The downstream source file route is already available because [UID:0000E2] emits through [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md), projected to `NexusTK/render/StaticObjImageLib.cpp`.

Recommended metadata for the target page:

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000E2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000E2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Final C++ should remain blank. The source-authored behavior belongs to the class destructor and class layout; this exact wrapper is source-declared/generated-binary output that the compiler should regenerate.

## Supervisor Active Recheck
- Supervisor instruction: B001-0003M2, research only UID `0003M2`, determine whether this `StaticObjImageLib` scalar deleting destructor should route through `StaticObjImageLib`, stay no-owner/non-emitting, gain emitters, be reclassified, or require adjacent ImageLib parent/child repair.
- Split requirement: no split required. Live IDA reports one exact function `sub_4E6990`, size `0x116`, with alignment before and after.
- Parent repair requirement: no blocking parent repair is required. The direct class parent [UID:0000E2] is `86/85`, the file parent [UID:0000O7] is `86/85`, the vtable page [UID:0001YX] is `85/90`, and the exact vtable-data page [UID:0002OY] is `89/92`.
- Lease handling: read current leases, leased the target page as B001, then released it after concluding no by-* edits were needed. Commands and results are in the validator/lease section.
- Coverage-report handling: `by-memory/-coverage-report.md` was not edited. Exact replacement row text is provided below for supervisor application.

## Inference Research Guidance Check
- IDA facts: function boundaries, vtable dwords, xrefs, decompile/disassembly, singleton writes, and padding are direct live IDA MCP evidence.
- Documentation evidence: existing StaticObjImageLib class/file/vtable/global/destructor pages already identify the class family and parent route. They were treated as hypotheses until live IDA reconfirmed the critical links.
- Inference: under `by-structure.md`, `CANONICAL_OWNER` is semantic ownership and should use the narrowest true owner. A vtable-referenced deleting destructor belongs directly to the class, not directly to the file, even when its exact body is compiler-shaped.
- Rebuild classification: source-declared/generated-binary. The generated nature explains blank final C++; it does not justify `CANONICAL_OWNER:NONE` when the class owner is proven.

## Evidence Standards Used
- IDA MCP tools used: `server_health`, `lookup_funcs`, `decompile`, `disasm`, `callees`, `xrefs_to`, `xref_query`, `entity_query`, `get_int`, and `get_bytes`.
- Project helper used: `tools/int_convert.py --text <value> --size 4 --single` for decimal-to-hex verification of IDA dword reads and the guard-path constant.
- Documentation evidence used: target page, tracker row, generated memory coverage row, by-memory coverage row, StaticObjImageLib class/file pages, vtable/vtable-data pages, ordinary destructor page, singleton helper/global pages, local cluster page, neighboring Riding wrapper, following AUTOBUF helper, and proposed source tree.
- Negative evidence used: no code callers to the target start, no competing vtable owner, broad shared delete/free helpers are not ownership proof, and address adjacency is weaker than class vtable/singleton/destructor evidence.

## IDA MCP Facts
- Active IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready.
- `lookup_funcs`:
  - `0x004e6990` -> `sub_4E6990`, size `0x116`, end `0x004e6aa6`.
  - `0x004e6981` and `0x004e6aa6` are not function starts.
  - Previous function `0x004e68b0` -> `sub_4E68B0`, size `0xd1`, the RidingImageLib scalar deleting destructor.
  - Next function `0x004e6ab0` -> `sub_4E6AB0`, size `0x27`, the AUTOBUF unsigned-char resize helper.
  - Ordinary destructor `0x004dd1e0` -> `sub_4DD1E0`, size `0xde`.
  - Constructor `0x004dcf60` -> `sub_4DCF60`, size `0x278`.
- Target decompile:
  - Stores `StaticObjImageLib::vftable` at `0x004e69c4`.
  - Frees static-object records and cache chains under object offsets `+0x0c/+0x10`.
  - Frees tile catalog payload and tile catalog object from `+0x04`.
  - Frees tile-class table from `+0x08` through `j_j_j___free_base`.
  - Clears `unk_69B448` / `g_pStaticObjImageLib` at `0x004e6a5e`.
  - Calls base cleanup `sub_4F4A90` at `0x004e6a6a`.
  - Calls delete helper `sub_4F4AC0` only when `(flags & 1) != 0` and `(flags & 4) == 0`.
- Target disassembly tail:
  - `0x004e6a72`: `test al, 1`
  - `0x004e6a76`: `test al, 4`
  - `0x004e6a7b`: optional `call sub_4F4AC0`
  - `0x004e6a85`: guarded path pushes `0x14` and `edi`, calls `@_guard_check_icall_nop@4`, then returns `edi`.
  - `0x14` verified as decimal `20` with `tools/int_convert.py`.
- `callees 0x004e6990`: `0x00516030`, `0x00516170`, `j_j_j___free_base` at `0x005c7799`, base cleanup `0x004f4a90`, delete helper `0x004f4ac0`, and `@_guard_check_icall_nop@4`.
- `xref_query 0x0061b704`:
  - `0x004dcfb8` in constructor `sub_4DCF60` references/stores `??_7StaticObjImageLib@@6B@`.
  - `0x004dd20b` in ordinary destructor `sub_4DD1E0` restores the same vtable.
  - `0x0061b704 -> 0x004e6990` is the vtable data slot to the target.
  - `0x004e69c4` in the target restores the same vtable.
- `xref_query 0x004e6990`: only the data xref from `0x0061b704` points to the function start, consistent with virtual deleting-destructor dispatch.
- `xref_query 0x0069b448`: 13 singleton xrefs, including constructor publish/null-clear (`0x004dcfa3`, `0x004dcfaa`), ordinary destructor clear (`0x004dd29b`), singleton helper clear (`0x004e5c00`), target scalar destructor clear (`0x004e6a5e`), shutdown read (`0x004f65e2`), map/static-object consumers, StaticObjectPane reads, and PhotoPane read.
- Ordinary destructor decompile at `0x004dd1e0`: same cleanup sequence as target through vtable restore, static-object record/cache cleanup, tile catalog cleanup, tile-class free, singleton clear, and base cleanup, but no scalar-delete flag test and no `sub_4F4AC0`.
- Vtable/RTTI dwords, verified with `tools/int_convert.py`:
  - `0x0061b6f0` -> decimal `6589620` -> `0x00648cb4`, Riding RTTI-adjacent word.
  - `0x0061b6f4` -> decimal `5138608` -> `0x004e68b0`, Riding scalar destructor.
  - `0x0061b700` -> decimal `6589780` -> `0x00648d54`, `??_R4StaticObjImageLib@@6B@`.
  - `0x0061b704` -> decimal `5138832` -> `0x004e6990`, target slot.
  - `0x0061b708` -> decimal `5196560` -> `0x004f4b10`, inherited/shared virtual slot.
  - `0x0061b70c` -> decimal `4306624` -> `0x0041b6c0`, `nullsub_18`.
  - `0x0061b710` -> decimal `6590100` -> `0x00648e94`, `ProtectedArray<EffectInfo>` RTTI-adjacent word.
  - `0x0061b714` -> decimal `5136480` -> `0x004e6060`, following `ProtectedArray<EffectInfo>` vtable slot.
- `entity_query names`:
  - `0x0061b704` is `??_7StaticObjImageLib@@6B@`.
  - `0x00648d54` is `??_R4StaticObjImageLib@@6B@`.
  - `0x00648da4-0x00648dd8` contains `Singleton<StaticObjImageLib>` RTTI records.
  - `0x00648e94` begins `ProtectedArray<EffectInfo>` RTTI, proving the successor boundary.
- `get_bytes` boundaries:
  - `0x004e6981-0x004e6990`: fifteen `0xcc` bytes after the RidingImageLib scalar deleting destructor.
  - `0x004e6990-0x004e6aa6`: 278 target bytes ending with `retn 4` at `0x004e6aa3`.
  - `0x004e6aa6-0x004e6ab0`: ten `0xcc` bytes.
  - `0x004e6ab0`: next function prologue begins.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004e6990-0x004e6aa6` | [UID:0003M2][0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor](by-memory/0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor.md) | StaticObjImageLib scalar deleting destructor | TRUE | recommend [UID:0000E2] | current `82/90`, recommend `85/90` | exact, assignable |
| `0x004dd1e0-0x004dd2be` | [UID:00017I][0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor](by-memory/0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor.md) | ordinary destructor body | TRUE | [UID:0000O7] currently | `82/90` | cleanup parity evidence |
| `0x0061b700-0x0061b710` | [UID:0002OY][0x0061b700-0x0061b710.StaticObjImageLibVtableData](by-memory/0x0061b700-0x0061b710.StaticObjImageLibVtableData.md) | RTTI/vtable data | TRUE | [UID:0001YX] | `89/92` | supports class route |
| `0x0061b704` | [UID:0001YX][StaticObjImageLibVtable](by-type/by-vtable/StaticObjImageLibVtable.md) | source-level vtable interpretation | TRUE | [UID:0000E2] | `85/90` | first slot points to target |
| `0x004e6aa6-0x004e6ab0` | [UID:0000VN][-ignored](by-memory/-ignored.md) | alignment padding | FALSE/ignored | none | `100/strong` in coverage row | not part of target |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0061b704 -> 0x004e6990` | vtable slot data xref | target is the first StaticObjImageLib vtable slot |
| `0x004dcfb8 -> 0x0061b704` | constructor vptr-store ref | constructor installs StaticObjImageLib vtable |
| `0x004dd20b -> 0x0061b704` | ordinary destructor vptr-store ref | destructor restores StaticObjImageLib vtable |
| `0x004e69c4 -> 0x0061b704` | scalar destructor vptr-store ref | target restores the same class vtable |
| `0x004e6a5e -> 0x0069b448` | singleton clear | target participates in StaticObjImageLib lifecycle |
| `0x004e6a6a -> 0x004f4a90` | base cleanup callee | target follows class/base destructor cleanup |
| `0x004e6a7b -> 0x004f4ac0` | optional delete helper | compiler scalar-delete path |
| `0x004e6a88 -> 0x0041b6a0` | guard path callee | compiler guarded flag-bit path |

## Documentation Evidence And IDA Status
- Target page evidence: already identifies the item as compiler-emitted scalar deleting destructor for [UID:0000E2], likely source file [UID:0000O7], exact function `sub_4E6990`, vtable slot `0x0061b704`, cleanup/delete path, singleton role, and trailing padding. Live IDA confirms these facts.
- Target page stale text: "Autogen parent remains blank because this is compiler-generated destructor glue" is stale under the current owner/emitter model. Compiler-generated destructor glue can still be semantically class-owned and emitter-routed through the class.
- StaticObjImageLib class page evidence: [UID:0000E2] is `86/85`, routes to [UID:0000O7], lists the target scalar deleting destructor, vtable, singleton, ordinary destructor, singleton helper, resource ownership, and consumer separation.
- StaticObjImageLib file page evidence: [UID:0000O7] is `86/85`, projected to `NexusTK/render/`, and lists `0x004e6990-0x004e6aa6` as the scalar destructor for the class.
- Vtable evidence: [UID:0001YX] is `85/90`, owned by [UID:0000E2], and slot `+0x00` points to `0x004e6990`; live IDA reconfirms constructor/destructor/scalar references.
- Vtable-data evidence: [UID:0002OY] is `89/92`, owned by [UID:0001YX], and proves the exact `0x0061b700-0x0061b710` range with Riding before and ProtectedArray after.
- Neighbor evidence: [UID:0002Y4] RidingImageLib scalar deleting destructor before the target is already class-owned; [UID:000188] AUTOBUF unsigned-char resize after target is owned by the AUTOBUF class/template family; the intervening `0xcc` padding is ignored. No mixed ownership exists inside `0003M2`.
- Generated/coverage state: `auto-generated/-ag-memory-coverage.md` lists UID `0003M2` in the no-owner section. `by-memory/-coverage-report.md` lists the target at `82%` between RidingImageLib and ignored padding.

## Ranked Ownership Analysis

### 1. [UID:0000E2] StaticObjImageLib class
- Evidence for: IDA names `0x0061b704` as `??_7StaticObjImageLib@@6B@`; the slot points to the target; constructor and ordinary destructor reference the same vtable; target restores the same vtable, clears the StaticObjImageLib singleton, and matches ordinary destructor cleanup plus scalar-delete handling. The direct class parent clears the gate at `86/85`.
- Evidence against: the wrapper is compiler-shaped and should not be hand-written as source. This affects final C++ emission, not ownership.
- Decision: accepted. Set `CANONICAL_OWNER:0000E2` and `EMITTER_UIDS:0000E2`.

### 2. [UID:0000O7] StaticObjImageLib file
- Evidence for: the file page is the downstream source root, projected to `NexusTK/render/StaticObjImageLib.cpp`, and owns the broader static-object image library module.
- Evidence against: by-structure requires the narrowest true owner. This is a class vtable/destructor artifact, so the class is the direct semantic owner. File ownership is the route after the class, not the direct child owner.
- Decision: rejected as direct `CANONICAL_OWNER`; accepted as the final generated source root reached through [UID:0000E2].

### 3. `CANONICAL_OWNER:NONE` / non-emitting generated glue
- Evidence for: the item is compiler-emitted scalar deleting destructor glue and final C++ should stay blank.
- Evidence against: there is a single proven class owner and emitter route. The target is not pooled, shared among source files, or ownerless data. No-owner/non-emitting would hide a class ABI item already proven by vtable and lifecycle evidence.
- Decision: rejected. The current no-owner state is stale.

### 4. Adjacent RidingImageLib, AUTOBUF, or generic ImageLib-family ownership
- Evidence for: the target is in a dense image-library tail island, after RidingImageLib and before AUTOBUF helper code.
- Evidence against: IDA padding separates the ranges; vtable/RTTI names are StaticObjImageLib; neighboring pages have their own owners; the following AUTOBUF helper is utility/template support rather than image-library class code.
- Decision: rejected. No adjacent parent/child repair is needed.

### 5. New file/grouping
- Evidence for: none. Existing `StaticObjImageLib` class and file pages already model the resource family, singleton, vtable, ordinary destructor, and scalar destructor.
- Evidence against: creating a new owner for one compiler-generated class destructor would duplicate the class/file route and violate narrow semantic ownership.
- Decision: rejected.

## Proposed New File/Grouping
- Proposed owner/name/path: none.
- Likely full contents: not applicable; existing `render/StaticObjImageLib.cpp` is the correct source root.
- Candidate related items that belong: target should join the existing StaticObjImageLib constructor/destructor/render/bounds/singleton/vtable/resource inventory through the class route.
- Candidate related items rejected: RidingImageLib wrapper remains [UID:0000BZ]; AUTOBUF resize remains [UID:00000P]; operator-delete helper remains MemoryMan/shared allocation support; ProtectedArray vtables after `0x0061b710` remain ProtectedArray/template support.
- Source-file inference: no standalone file. Direct semantic owner is class [UID:0000E2], downstream file route is [UID:0000O7] `render/StaticObjImageLib.cpp`.

## Negative Evidence Summary
- No code callers reference `0x004e6990`; only the vtable slot references it. That is expected for a virtual deleting destructor and supports, rather than weakens, class-vtable ownership.
- Shared callees `0x00516030`, `0x00516170`, `0x004f4a90`, `0x004f4ac0`, and guard/runtime helpers do not prove ownership because they are cross-class cleanup/allocation support.
- Address adjacency alone would be weak. Here, address adjacency is used only to confirm split boundaries; ownership is from vtable, RTTI, constructor/destructor, singleton, and cleanup parity.
- The ordinary destructor page currently attaches directly to the file, but that does not block assigning this vtable slot wrapper to the class. The class now clears the `85/85` gate and is the narrow semantic owner for vtable/deleting-destructor glue.
- The target is not a mixed aggregate: live IDA reports one exact function and separate padding before/after.

## Final Recommendation
- Exact metadata recommendation for target [UID:0003M2]:
  - `COMPLETION:85`
  - `CONFIDENCE:90`
  - `CANONICAL_OWNER:0000E2`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000E2`
  - `EMITTER_POSITION_OPTIONAL:` blank
  - `RECONSTRUCTION_CPP CODE` remains blank
- Rebuild handling: source-declared/generated-binary. The class declaration/ordinary destructor should cause compiler regeneration of this wrapper.
- Score effect: completion rises from `82` to `85` because ownership route, vtable dwords, constructor/destructor/scalar vtable refs, ordinary destructor parity, singleton xrefs, padding boundaries, and neighbor separation are now fully researched. Confidence can remain `90`; final field/helper names and final source declaration quality still prevent higher final-audit confidence.
- Coverage effect: UID `0003M2` moves out of no-owner/non-emitting. No-owner count decreases by one; generated route becomes `auto-generated/NexusTK/render/StaticObjImageLib.cpp`; generated C++ remains absent because final C++ is blank.
- Split/parent repair: none required.

## Exact Pending Coverage / Generated Rows
Do not edit `by-memory/-coverage-report.md` directly in this B-agent pass. Supervisor should replace the current UID `0003M2` row, keeping the same placement after [UID:0002Y4] RidingImageLib and before the ignored `0x004e6aa6-0x004e6ab0` padding row, with:

```text
    - [UID:0003M2][0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor](by-memory/0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor.md) 0x004e6990-0x004e6aa6 | scalar-deleting-destructor | StaticObjImageLibScalarDeletingDestructor : reconstructable : 85% : strong : Exact compiler-emitted StaticObjImageLib scalar deleting destructor; assign to [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md) with emitter [UID:0000E2] after live IDA reconfirmed sub_4E6990 size 0x116, vtable slot 0x0061b704, constructor/destructor/scalar vptr refs at 0x004dcfb8/0x004dd20b/0x004e69c4, ordinary-destructor cleanup parity, singleton clear at 0x004e6a5e, optional operator-delete call at 0x004e6a7b, guard path, and exact padding boundaries between RidingImageLib and AUTOBUF helper code.
```

After metadata is applied and normal validator flow refreshes generated state, the relevant `auto-generated/-ag-memory-coverage.md` main row should become:

```text
| [UID:0003M2][0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor](by-memory/0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor.md) | emits | `0000E2` | `0000E2` |  | no | `auto-generated/NexusTK/render/StaticObjImageLib.cpp` | `by-memory/0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor.md` |  |
```

The no-owner summary row for UID `0003M2` in `auto-generated/-ag-memory-coverage.md` should disappear after generated refresh. Do not hand-edit generated files.

## Recommended Target / Parent Text Cleanup
- Target status should replace "Autogen parent remains blank because this is compiler-generated destructor glue" with: "Direct owner/emitter recommendation: [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md). This is source-declared/generated-binary destructor glue; final C++ remains blank, but the class declaration/destructor shape should regenerate the wrapper."
- Add the live IDA facts for constructor/destructor/scalar vtable refs at `0x004dcfb8`, `0x004dd20b`, and `0x004e69c4`, plus singleton clear at `0x004e6a5e`, to the target page if an A-agent edits it.
- No score changes are required for [UID:0000E2], [UID:0000O7], [UID:0001YX], [UID:0002OY], or [UID:0000SD].

## Follow-Up Actions
- Supervisor actions: apply target metadata, apply the by-memory coverage replacement row above, and run normal live validator `--apply` flow to refresh generated reports. Do not use dry-run mode for this assignment.
- A-agent actions: if assigned to edit the target page, update stale no-owner wording, add the live IDA xref/dword/padding evidence, and keep final C++ blank.
- B001 future research actions: none for UID `0003M2` unless requested for a broader image-library scalar destructor sweep.

## Confidence
- Recommendation confidence: strong (`90`).
- Score confidence: strong for `85/90`.
- Remaining uncertainty: final StaticObjImageLib field names, tile-catalog/cache-chain type names, and final source destructor declaration names remain below final-source audit quality; none of these block the owner/emitter route.

## Validator And Lease Results
- Validator commands run: none. This pass created only a B001 research report and did not edit target by-* documentation or generated coverage files.
- Live IDA validation performed:
  - `server_health`, `lookup_funcs`, `decompile`, `disasm`, `callees`, `xrefs_to`, `xref_query`, `entity_query`, `get_int`, `get_bytes`.
  - `tools/int_convert.py --text <value> --size 4 --single` for vtable dword conversions and guard-path constant.
- Dry-run modes: not used.
- Memory-range modes: not used.
- Lease commands:
  - `python leaser.py B001 lease E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor.md` -> `Success`.
  - `python leaser.py B001 unlease E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor.md` -> `Success`.
- Blockers: none.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B001/research/0003M2-StaticObjImageLibScalarDeletingDestructor.md`
- Modified: none outside the B001 research folder.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003M2","source_path":"executed-b-agent-research/B001/0003M2-StaticObjImageLibScalarDeletingDestructor.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
