** TARGET-REPORT-UID:000428 **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# UID000428 MapPaneGetAdjacentVisibleTileBounds Source-Quality Report

## Executive Recommendation

UID000428 remains the source-emitting child target for `MapPane::GetAdjacentVisibleTileBounds` at exact path `by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md`, owned and emitted by [UID:00007Q] `MapPane`, with `RECONSTRUCTABLE:TRUE` and blank emitter position. The implementation callback has been applied: the target is now `COMPLETION:90`, `CONFIDENCE:92`, the formal C++ body is preserved exactly, and current MCP/local proof has been incorporated at report-level detail.

The critical range detail is that UID000428 covers the code body `0x00505650-0x0050571e` plus the attached switch material `0x0050571e-0x00505730`: a two-byte alignment NOP at `0x0050571e-0x00505720` and the four-entry jump table at `0x00505720-0x00505730`. That jump-table range is child-owned data for this exact target and must not be treated as ignored padding or moved to the successor no-op at `0x00505730`.

This artifact is now post-callback and ready for supervisor execution review. B014 edited only the accepted by-* docs and this report, ran scoped file validators, released leases, and did not run `execute_report`, dry-run/probing variants, lifecycle/archive commands, manual report moves, generated-file manual edits, coverage-report edits, validator-state manual edits, or supervisor-ledger edits.

## Finalized Report / Current Recommendation

- Current post-callback target outcome: applied. `by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md` is now `COMPLETION:90`, `CONFIDENCE:92`, with `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, and blank `EMITTER_POSITION_OPTIONAL` preserved.
- Current C++ outcome: already present/preserved. The target formal block still contains the exact `MapPane::GetAdjacentVisibleTileBounds(unsigned char direction, MapRect *outBounds) const` body from this report; no draft/sample/body-only C++ was left outside the formal block.
- Current evidence outcome: applied. The target now records MCP session `60724697`, function size `0xce`, modeled code range `0x00505650-0x0050571e`, attached switch material `0x0050571e-0x00505730`, callers `0x005a3235` and `0x005ad390`, helper semantics, optional output copy, `m_mapWidth`/`m_mapHeight` reads, no recovered local `MapPane`/`MapRect` UDT, local PE route facts, successor split, and UID alias rejection.
- Current support outcome: applied for stale direct support. The aggregate `MapPaneWeatherCoordinateObjectCore`, `by-class/MapPane.md`, and `by-file/MapPane.md` now record UID000428 source readiness, score, ownership, and jump-table evidence. Caller/checksum pages were checked and left unchanged because no direct stale contradiction was found.
- B014 lifecycle boundary: B014 stopped after scoped validators and report ledger/checklist update. Supervisor owns Gate 2 verification and any later `execute_report` / archive lifecycle.

## Supporting Research

Historical report-only state: this report was originally produced for a B-agent report-only assignment from Agent-B014 `goal.md`. The target is UID000428 at exact path `by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md`; all claims in this report are bound to that path and address range because historical report material also used UID000428 for unrelated RankingDialog/RankingCategoryRecord work.

Current local documentation already has a formal C++ body for this target through the previously executed B009 aggregate report `0001AP-MapPaneWeatherCoordinateObjectCore-source-quality.md`. That earlier report was treated as a lead, not as final proof. This pass rechecked the body, ownership, callers, boundaries, and jump-table range through current IDA MCP session `60724697`, current by-* docs, current generated `auto-generated/NexusTK/map/MapPane.cpp`, and local PE route scanning.

Current callback state: after supervisor Gate 1 acceptance for SHA256 `51B9B58EEB95617624E6A95C58DB85A1711C581516C2C0442FB964A803E9FD17`, B014 edited the accepted target plus stale direct support docs, ran scoped validators `000000006288` through `000000006291`, released the leases, and updated this report's ledger/checklist. No caller/checksum pages were edited because they did not contain a direct stale contradiction.

Generated output remains a consistency lead only. Before callback, `auto-generated/NexusTK/map/MapPane.cpp` command `000000006214` emitted UID000428 at `86/88`. After callback validators, generated `MapPane.cpp` header shows command `000000006290`, refreshed `2026-07-04T12:25:00-04:00`, and UID000428 now appears once at lines 498-540 with `Completion:90 | Confidence:92` and the same source body. The generated header is older than the final support-doc validator command `000000006291`, but the UID000428 target metadata/body refresh is present.

## Supervisor Active Recheck

Current supervisor instruction for this pass: implementation callback for Gate-1-accepted UID000428 report SHA256 `51B9B58EEB95617624E6A95C58DB85A1711C581516C2C0442FB964A803E9FD17`; implement the accepted report at report-level detail; lease editable docs only while editing; run scoped validators for changed by-* docs; update this report ledger/checklist; stop at `READY_FOR_SUPERVISOR_EXECUTE`; do not run `execute_report`, dry-run/probing variants, lifecycle/archive/registry commands, generated manual edits, coverage edits, validator-state edits, or supervisor-ledger edits.

B014 re-read the Agent-B014 `goal.md` and applied the project-level `ntk-b-agent-workflow` skill. The callback used the accepted report's MCP evidence from active IDA MCP session `60724697`, with `server_health` status `ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input executable `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, and `hexrays_ready:true`.

Forbidden-action confirmation for B014: no `execute_report`, no dry-run/probing execute variant, no lifecycle/archive/registry command, no report move, no generated-file manual edit, no `-coverage-report.md` edit, no validator-state manual edit, no supervisor-ledger edit, and no IDA DB/process-management mutation was performed. Scoped file validators produced validator-owned generated/projected-stat side effects only.

## Target

- Target UID: `000428`
- Exact target path: `by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md`
- Exact address range: `0x00505650-0x00505730`
- Current target metadata: `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank `EMITTER_POSITION_OPTIONAL`
- Current source route: [UID:00007Q] `MapPane` under [UID:0000L3] `by-file/MapPane.md` / `NexusTK/map/MapPane.cpp`
- Current emitted function: `unsigned short MapPane::GetAdjacentVisibleTileBounds(unsigned char direction, MapRect *outBounds) const`
- Current classification: implementation callback applied; target/source/support docs updated and scoped validators passed; returned for supervisor execution review.
- Alias-collision caution: UID string `000428` has appeared in unrelated historical RankingDialog/RankingCategoryRecord context. This report applies only to exact path `by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md` and exact range `0x00505650-0x00505730`.

## Current Target State

The current target page now has the accepted owner/emitter, `90/92` score, formal C++ body, and current evidence. It records MCP session `60724697`, exact code/data split, direct-caller proof, no-UDT/type proof, local PE route facts, generated-output freshness, successor split, and UID alias-collision guardrail.

The current generated output is not an empty marker: `auto-generated/NexusTK/map/MapPane.cpp`, validator command `000000006290`, refreshed `2026-07-04T12:25:00-04:00`, emits UID000428 once at lines 498-540 with `Completion:90 | Confidence:92` and the same formal body. The header is older than final support validator `000000006291`, but the UID000428 generated body/metadata refresh is present.

The current open questions are limited to exact original helper/type/member spelling. MCP did not recover a local `MapPane` or `MapRect` UDT. Helper names such as `IntersectRect` and `ComputeTileRectChecksum` remain source-facing inferred names backed by sibling docs and generated output. These are confidence caps, not blockers to source-shaped first-draft C++.

## Heuristic / Inference Reanalysis And Validation

The function is source-facing `MapPane` logic, not an anonymous raw helper. The function receives `this` in `ecx`, a direction byte as the first stack argument, and an optional output rectangle pointer as the second stack argument. It calls the clamped visible-bounds helper, adjusts the resulting rectangle according to a four-case direction switch, clips the rectangle against map dimensions at `MapPane +0x3f4/+0x3f6`, optionally copies the 16-byte result to the caller, and returns the checksum from the region checksum helper at `0x0050c040`.

The inferred `MapRect` field order is the standard four-int rectangle order used by sibling MapPane helpers and raw helpers: `left`, `top`, `right`, `bottom`. MCP decompile expresses the local rectangle as a 128-bit temporary and raw dword operations; the source-quality form should not emit decompiler-shaped `_OWORD`, `DWORD1`, or raw `sub_` names. The existing formal body uses the correct source shape.

The direction cases are validated instruction-by-instruction:

- Direction `0`: sets `bottom = old top` and decrements `top`, producing the one-row strip above the visible bounds.
- Direction `1`: sets `left = old right` and increments `right`, producing the one-column strip to the right.
- Direction `2`: sets `top = old bottom` and increments `bottom`, producing the one-row strip below.
- Direction `3`: sets `right = old left` and decrements `left`, producing the one-column strip to the left.
- Default: zeroes the rectangle with `SetRect`.

The attached switch material is part of this target's reconstruction. IDA models `sub_505650` as size `0xce` ending at `0x0050571e`, but the modeled target page must continue through `0x00505730` because bytes `0x0050571e-0x00505720` are a two-byte alignment NOP and `0x00505720-0x00505730` is the switch jump table used by the `jmp ds:jpt_505679[eax*4]` instruction at `0x00505679`. The successor `0x00505730` is a separate one-byte no-op function and is not part of UID000428.

Rejected alternatives:

- No-code/no-owner is rejected: the function has two direct code callers, clear MapPane receiver use, source-shaped output, and current generated C++.
- Moving the jump table to successor/padding is rejected: `entity_query` names `jpt_505679` at `0x00505720`, and the target instruction references it directly.
- Treating `0x005a2e00` or `0x005ad360` caller contexts as owners is rejected: those are LivingObjectPane/UserPane call sites that retrieve the `MapPane` pointer and call this MapPane helper.
- Treating historical RankingDialog UID000428 material as evidence is rejected: that material is an alias collision by UID string, not by path or address.
- Emitting decompiler-shaped `_OWORD`, `DWORD1`, `sub_505290`, `sub_4B7C50`, `sub_4B7CC0`, or `sub_50C040` names is rejected; source-facing names already exist in MapPane/support docs and generated output.

## Inference Research Guidance Check

This pass follows the project standard that missing exact original type/member names do not justify blank output when behavior, callers, fields, and support routes are strong. MCP did not recover local `MapPane` or `MapRect` UDTs, but sibling MapPane docs already establish `m_mapWidth`, `m_mapHeight`, visible-bounds helpers, and `MapRect`-style helper use. Therefore the correct recommendation is source-shaped first-draft C++, not a hard no-code result.

The report keeps inference bounded. It does not assert that `MapRect`, `IntersectRect`, or `ComputeTileRectChecksum` are symbol-recovered original names. It recommends preserving them as current source-facing documentation names, with unresolved exact spelling treated as a confidence cap. The semantics and call boundaries are direct evidence; the names are source-quality inference.

The attached jump-table range received special review because range split mistakes would materially affect target ownership. MCP and raw bytes show `0x0050571e-0x00505730` is attached switch material for UID000428, while `0x00505730` starts the next function. The implementation callback now documents this explicitly on the target/support docs.

## Evidence Standards Used

- Direct IDA MCP evidence from active session `60724697`: `idb_list`, `server_health`, `lookup_funcs`, `entity_query`, `decompile`, `disasm`, `callees`, `xrefs_to`, `xref_query`, `get_bytes`, `find_bytes`, and `type_query`.
- Direct local documentation evidence: current target, aggregate MapPane core page, class/file pages, sibling MapPane helper pages, caller pages, generated `MapPane.cpp`, and executed reports used as leads.
- Raw byte and route evidence: target body bytes, predecessor/successor padding, attached jump-table bytes, MCP pointer-pattern checks, and local PE VA/RVA/raw/rel32 scans.
- Source-quality standard: formal C++ expresses plausible developer source and known local abstractions, not decompiler temporaries or raw IDA names.

The combined evidence is strong enough for `90/92`. It remains below final-audit range because exact original helper/type/member spellings are inferred and local IDA still lacks recovered `MapPane`/`MapRect` UDTs.

## Evidence Checked

IDA MCP/session facts:

- `idb_list`: active session `60724697`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, filename `NexusTK.exe.i64`, created `2026-07-04T11:24:09.587439`, active `true`, `is_analyzing:false`, worker PID `13932`.
- `server_health 60724697`: status `ok`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- `lookup_funcs`: `0x00505650` -> `sub_505650`, size `0xce`; `0x0050571d` -> same function; `0x0050571e` not a function; `0x0050572f` not a function; `0x00505730` -> `nullsub_12`, size `0x1`; `0x00505740` -> `nullsub_41`, size `0x3`.
- Boundary context: `0x005055e0` -> `sub_5055E0`, size `0x65`; `0x00505645` not a function; `0x00505750` not a function.
- `entity_query` names in `0x00505640-0x00505760`: `def_505679` at `0x005056b4`, `jpt_505679` at `0x00505720`, `nullsub_12` at `0x00505730`, `nullsub_41` at `0x00505740`.
- `entity_query` functions in `0x005055d0-0x00505760`: `sub_5055D0`, `sub_5055E0`, `sub_505650`, `nullsub_12`, `nullsub_41`.

Decompile/disassembly facts:

- `decompile 0x00505650`: `unsigned __int16 __thiscall sub_505650(unsigned __int16 *this, char a2, _OWORD *a3)`; calls `sub_505290`, switches on `a2`, adjusts local bounds, calls `sub_4B7C50`, `sub_4B7CC0`, optionally copies `v6` to `a3`, returns `sub_50C040(this, &v6)`.
- `disasm 0x00505650`: 81 instructions; prologue/security cookie; `mov edi,[ebp+arg_4]`; `mov esi,ecx`; `call sub_505290`; `movsx eax,[ebp+arg_0]`; `cmp eax,3`; `ja def_505679`; `jmp ds:jpt_505679[eax*4]`; case labels at `0x00505680`, `0x005056a7`, `0x0050568d`, `0x0050569a`; default at `0x005056b4`; return at `0x0050571b`.
- Field reads: `[esi+0x3f4]` and `[esi+0x3f6]` are passed to `SetRect` as map width/height after the direction-specific adjustment.
- Optional output copy: if the second argument is non-null, `movups` copies the 16-byte local rectangle to the caller's buffer.
- Callees: `sub_505290` (clamped visible bounds helper), `sub_4B7C50` (rectangle initializer), `sub_4B7CC0` (rectangle intersection helper), `sub_50C040` (MapPane tile-region checksum helper), and `@__security_check_cookie@4`.

Raw bytes/range facts:

- `get_bytes 0x00505640 size 16`: previous function ends before `0x00505645`, followed by eleven `0xcc` bytes through `0x0050564f`; target starts at `0x00505650`.
- `get_bytes 0x00505650 size 224`: target body includes `retn 8` at `0x0050571b-0x0050571d`; then attached bytes `66 90` at `0x0050571e-0x00505720`, followed by dwords `0x00505680`, `0x005056a7`, `0x0050568d`, `0x0050569a` at `0x00505720-0x00505730`.
- `get_bytes 0x0050571e size 18`: `66 90 80 56 50 00 a7 56 50 00 8d 56 50 00 9a 56 50 00`, confirming two-byte NOP plus four-entry jump table.
- `get_bytes 0x00505730 size 16`: `c3` then `0xcc` padding, confirming `0x00505730` is a separate successor no-op.

Direct caller and route facts:

- `xrefs_to 0x00505650`: two code refs, `0x005a3235` in `sub_5A2E00` and `0x005ad390` in `sub_5AD360`.
- `xrefs_to 0x0050571e`: zero.
- `xrefs_to 0x00505720`: one data xref from `0x00505679` inside `sub_505650`, the switch jump instruction.
- `xrefs_to 0x00505724`, `0x00505728`, `0x0050572c`: zero direct refs; these are remaining jump-table entries used through the base.
- `xrefs_to 0x00505730`: two code refs to successor no-op, from `0x005a79f5` and `0x005ab052`; these do not target UID000428.
- Caller `sub_5A2E00` at `0x005a3227-0x005a3235`: loads `MapPane *` from `[esi+0x1340f8]`, pushes output `MapRect *`, pushes direction in `edi`, calls `sub_505650`, and consumes the returned checksum.
- Caller `sub_5AD360` at `0x005ad380-0x005ad390`: loads `MapPane *` from `[edi+0x1340f8]`, pushes output `MapRect *`, pushes direction from argument, calls `sub_505650`, and uses the returned 16-bit checksum in packet logic.

Negative/pattern facts:

- MCP `find_bytes` found zero hits for target start VA `50 56 50 00`, target start RVA `50 56 10 00`, attached range VA/RVA `1e 57 50 00` / `1e 57 10 00`, and successor start VA/RVA `30 57 50 00` / `30 57 10 00`.
- MCP `find_bytes` for table base VA `20 57 50 00` found the internal switch operand, not an external owner route.
- Local PE scan of `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`: imagebase `0x400000`, file size `2679296`; target RVA `0x105650`, raw offset `0x104a50`.
- Local PE scan found zero target-start VA/RVA/raw-offset dword hits and exactly two exact rel32 calls to `0x00505650`, at raw `0x1a2635` / VA `0x005a3235` and raw `0x1ac790` / VA `0x005ad390`.
- Local PE scan found zero VA/RVA/raw dword hits for `0x0050571e` and `0x00505730`.
- Local PE scan found one table-base VA dword hit for `0x00505720`, at raw `0x104a7c`, which is the internal `jmp ds:jpt_505679[eax*4]` operand in this target.

Type/name facts:

- `type_query *MapRect*`: no local recovered type.
- `type_query *MapPane*`: no local recovered UDT/type records.
- Current by-* docs and generated output use source-facing names `MapPane`, `MapRect`, `GetClampedVisibleTileBounds`, `SetRect`, `IntersectRect`, and `ComputeTileRectChecksum`; these are documentation/source-quality names, not recovered IDA type records.

Documentation/generated facts:

- Current target has formal C++ and metadata `90/92`.
- Current aggregate `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md` says UID000428 is source-ready at `90/92` and includes jump-table bytes `0x0050571e-0x00505730`.
- Current `by-class/MapPane.md` and `by-file/MapPane.md` list UID000428 as a source-ready coordinate/movement helper under `MapPane`.
- Historical pre-callback generated `auto-generated/NexusTK/map/MapPane.cpp`, validator command `000000006214`, refreshed `2026-07-04T11:40:29-04:00`, emitted UID000428 with the formal source body at `86/88`; current generated command `000000006290`, refreshed `2026-07-04T12:25:00-04:00`, emits UID000428 at `90/92`.
- Executed B009 report `0001AP-MapPaneWeatherCoordinateObjectCore-source-quality.md` created the current target/source body as part of aggregate support. This report rechecks that body directly rather than relying on the executed report alone.
- Historical alias-collision search found unrelated UID000428 material in RankingDialog/RankingCategoryRecord context. This report rejects those as evidence for the exact MapPane path/address.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-001 | UID000428 evidence applies only to exact target `by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md`; unrelated historical RankingDialog/RankingCategoryRecord UID000428 material must not be incorporated. | High | Goal.md exact target path/address; alias-collision search found unrelated RankingDialog/RankingCategoryRecord UID000428 references. | Target `Status`/`Evidence`; support docs where stale. | reject-invalid | applied - target line 68 records alias guard; class/file support lines 86 and 95 reject RankingDialog alias material. |
| C-002 | Target metadata is `COMPLETION:90`, `CONFIDENCE:92` while preserving `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, and blank emitter position. | High | MCP session `60724697`; two direct callers; exact behavior; generated source present; only name/UDT caveats remain. | Target metadata block. | incorporate | applied - target lines 2-7 show `90/92` and unchanged owner/emitter/reconstructable/blank position. |
| C-003 | Existing formal C++ body is source-ready and should be preserved/inserted using the exact formal `RECONSTRUCTION_CPP CODE` block in this report. | High | MCP decompile/disasm/callers/helper facts; current target body; generated output emits same body. | Target `RECONSTRUCTION_CPP CODE` block. | already-present | already-present - target formal block begins at line 9 and generated `MapPane.cpp` lines 498-540 emit one matching body. |
| C-004 | Current MCP evidence from session `60724697` should be incorporated at report-level detail. | High | `idb_list` active worker; `server_health` ok; `lookup_funcs`, `entity_query`, `decompile`, `disasm`, `callees`, `xrefs_to`, `xref_query`, `get_bytes`, `find_bytes`, and `type_query` facts recorded in this report. | Target evidence sections; aggregate/class/file support summaries. | incorporate | applied - target evidence starts line 73; aggregate line 172; class line 86; file line 95. |
| C-005 | Attached switch material `0x0050571e-0x00505730` belongs to UID000428: `0x0050571e-0x00505720` is two-byte align NOP and `0x00505720-0x00505730` is the four-entry direction jump table. | High | `get_bytes 0x0050571e`; `entity_query` `jpt_505679` at `0x00505720`; switch jump at `0x00505679`; successor `0x00505730` is separate `nullsub_12`. | Target range/padding notes; aggregate UID000428 row; class/file support. | incorporate | applied - target line 67; aggregate rows/notes lines 62, 168, 172, 183; class line 86; file line 95. |
| C-006 | Direct callers are exactly `0x005a3235` in `sub_5A2E00` and `0x005ad390` in `sub_5AD360`; both consume this MapPane helper and do not own it. | High | MCP `xrefs_to 0x00505650`; caller disassembly; local PE exact rel32 scan. | Target xref/caller evidence; support docs where stale. | incorporate | applied - target evidence line 83 and support lines aggregate 62/174, class 86, file 95. Caller pages were not edited because they had no direct contradiction. |
| C-007 | Local PE/MCP route checks found no extra owner route: zero target/table/successor dword routes except the internal jump-table base operand, and exactly the two rel32 calls to `0x00505650`. | High | MCP `find_bytes`; local PE scan with imagebase `0x400000`, target raw `0x104a50`, two rel32 hits at VA `0x005a3235` and `0x005ad390`. | Target negative evidence and route-scan notes. | incorporate | applied - target evidence line 85 and support lines aggregate 175, class 86, file 95. |
| C-008 | No local recovered `MapPane`/`MapRect` UDT exists; exact helper/type/member spelling is inferred and caps confidence, but does not block source-shaped C++. | Medium-high | MCP `type_query *MapPane*` and `*MapRect*` negative results; current MapPane support docs and generated output use source-facing names. | Target caveats/open questions; class/file support notes. | incorporate | applied - target evidence line 86 and support lines aggregate 62/175, class 86, file 95. |
| C-009 | Decompiled/raw IDA names and decompiler temporaries should not be emitted in target C++. | High | Source-quality rules; current formal C++ avoids `_OWORD`, `DWORD1`, `sub_505290`, `sub_4B7C50`, `sub_4B7CC0`, and `sub_50C040`. | Target formal C++ and implementation notes. | reject-stale | applied - formal C++ preserved at target lines 9-52; raw names remain only in evidence, not emitted C++. |
| C-010 | Aggregate/class/file support docs should sync UID000428 source readiness, score, ownership, and jump-table evidence where stale. | High | Current target/generator; aggregate/class/file rows already contained partial details but not current MCP session and recommended `90/92`. | `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`; `by-class/MapPane.md`; `by-file/MapPane.md`. | incorporate | applied - aggregate lines 62, 172, 272; class lines 86, 305; file lines 95, 357. |
| C-011 | Caller/checksum support docs are verification-only unless stale; if edited, they should identify UID000428 as a MapPane callee/consumer of checksum helper, not move ownership. | Medium-high | Caller disassembly; checksum helper docs; current target source route through MapPane. | Caller/checksum pages. | incorporate | excluded-with-reason - checked `0x005a2e00`, `0x005ad360`, and `0x0066db4c` pages; no direct stale contradiction found, so no edit/validator was needed. Target cross-references include caller/checksum pages. |
| C-012 | Scoped validators should run only for changed by-* docs after implementation callback. | High | Project workflow; changed by-* docs were target, aggregate, class, and file pages. | Callback `Validator Results` section and changed by-* docs. | incorporate | applied - validators `000000006288` through `000000006291`, all exit `0`, all `ok:1`. |
| C-013 | Generated output was rechecked after validators; result is one UID000428 source body in `auto-generated/NexusTK/map/MapPane.cpp` with refreshed `90/92` metadata. | High | Historical generated command `000000006214` emitted source at `86/88`; callback validators refreshed UID000428 metadata. | Callback `Validator Results`; generated freshness note only, no manual generated edit. | incorporate | applied - generated header command `000000006290`, refreshed `2026-07-04T12:25:00-04:00`; UID000428 lines 498-540 show one body at `90/92`. |
| C-014 | Manual coverage/tracker edits are not required and should remain supervisor/validator-owned. | High | Callback forbids manual coverage/tracker edits; no manual coverage text needed. | Coverage/tracker files unchanged by B014. | not-applicable | excluded-with-reason - B014 did not manually edit coverage/tracker files; validator-owned projected stats/generator effects are reported. |
| C-015 | B014 must not run forbidden lifecycle or mutation commands for this report. | High | Current supervisor instruction and B-agent workflow. | B014 process boundary; `Changed Files`/final response. | not-applicable | applied - no execute/probe/lifecycle/archive/manual report move/generated manual edit/coverage edit/validator-state manual edit/supervisor-ledger edit was run. |

## Positive Evidence Summary

- Exact target function exists at `0x00505650` and IDA models code size `0xce`.
- Exact target page range `0x00505650-0x00505730` is justified by attached switch material after the modeled `retn 8`.
- Function body is source-shaped MapPane logic with clear direction cases, map-bound clipping, optional output, and 16-bit checksum return.
- Two direct callers pass a direction and output rectangle through a `MapPane *` receiver loaded from UserPane/LivingObjectPane context.
- Current generated `MapPane.cpp` already emits the source body.
- Sibling/support docs establish `MapPane`, `MapRect`-style helpers, map dimension fields, and checksum helper context.
- Local PE and MCP negative scans found no contradictory route or external owner for the attached jump table.

## IDA MCP Facts

- Session: `60724697`
- IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Input executable: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Imagebase: `0x400000`
- Health: `ok`; auto-analysis and Hex-Rays ready.
- Function lookup: `sub_505650`, start `0x00505650`, size `0xce`; successor `nullsub_12` at `0x00505730`, size `0x1`.
- Function signature from Hex-Rays: `unsigned __int16 __thiscall sub_505650(unsigned __int16 *this, char a2, _OWORD *a3)`.
- Modeled code return: `retn 8` at `0x0050571b`.
- Attached data: NOP `0x0050571e-0x00505720`; jump table `0x00505720-0x00505730`.
- Direct callers: `0x005a3235`, `0x005ad390`.
- Type status: no local recovered `MapPane`/`MapRect` UDT records.

## Function / Child Inventory

| Address/range | IDA name/status | Role for UID000428 |
| --- | --- | --- |
| `0x005055e0-0x00505645` | `sub_5055E0`, size `0x65` | Predecessor sibling. |
| `0x00505645-0x00505650` | not function; `0xcc` padding | Boundary padding before UID000428. |
| `0x00505650-0x0050571e` | `sub_505650`, size `0xce` | UID000428 code body. |
| `0x0050571e-0x00505720` | not function; bytes `66 90` | Alignment NOP attached to UID000428 switch material. |
| `0x00505720-0x00505730` | `jpt_505679` | Four-entry jump table for UID000428 direction switch. |
| `0x00505730-0x00505731` | `nullsub_12`, size `0x1` | Separate successor no-op, not part of UID000428. |
| `0x00505740-0x00505743` | `nullsub_41`, size `0x3` | Later successor sibling. |

## Direct Xref / Caller Inventory

| Target | Xrefs | Interpretation |
| --- | --- | --- |
| `0x00505650` | `0x005a3235`, `0x005ad390` | Two direct code callers to UID000428. |
| `0x0050571e` | none | Alignment NOP has no external route. |
| `0x00505720` | data xref from `0x00505679` | Internal switch jump table base. |
| `0x00505724/28/2c` | none direct | Remaining table entries used through base. |
| `0x00505730` | `0x005a79f5`, `0x005ab052` | Separate successor no-op callers; not UID000428. |

Caller details:

- `0x005a3235` in `sub_5A2E00`: caller loads `MapPane *` from `[esi+0x1340f8]`, pushes output bounds, pushes direction, calls UID000428, then uses the returned checksum.
- `0x005ad390` in `sub_5AD360`: caller loads `MapPane *` from `[edi+0x1340f8]`, pushes output bounds, pushes direction, calls UID000428, then packet code uses the returned 16-bit checksum.

## Documentation Evidence And IDA Status

- Target page: currently source-emitting at `90/92` with current MCP/local evidence.
- Aggregate page `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`: recognizes the child, current score/readiness, and the exact child-owned jump-table range.
- `by-class/MapPane.md`: places UID000428 in the MapPane coordinate/movement family as source-ready at `90/92`.
- `by-file/MapPane.md`: routes UID000428 through `NexusTK/map/MapPane.cpp` as a current source-ready child.
- Caller pages `by-memory/0x005a2e00-0x005a36de.LivingObjectPaneProcessMovement.md` and `by-memory/0x005ad360-0x005ad441.LivingObjectPaneSendAttackTargetPacket.md`: verification support only unless stale wording conflicts with UID000428.
- Current IDA names remain raw (`sub_505650`, `jpt_505679`), and no local `MapPane`/`MapRect` UDT is recovered. Documentation/source-facing names are inferred from surrounding source reconstruction.

## Ranked Ownership Analysis

1. [UID:00007Q] `MapPane` owns/emits UID000428. This is the recommended and current route. Evidence: receiver in `ecx`, map dimension fields, visible-bounds helper call, checksum helper call, source file/class support docs, and generated output.
2. [UID:0000L3] `by-file/MapPane.md` owns source-file placement but should not directly emit the child body except through validator aggregation. Evidence: by-file route and generated `MapPane.cpp`.
3. LivingObjectPane/UserPane caller contexts are consumers, not owners. Evidence: they load a `MapPane *` field and call this helper.
4. No-owner/raw helper is rejected. Evidence: direct callers, coherent MapPane receiver/fields, and source-shaped generated body.
5. Historical RankingDialog/RankingCategoryRecord UID000428 material is rejected for this target. Evidence: different path/address/family.

## Source Placement

Recommended source placement remains `NexusTK/map/MapPane.cpp` under [UID:0000L3] `MapPane`. The target function is a `MapPane` method because it operates on visible tile bounds and map dimensions and is emitted in current generated `auto-generated/NexusTK/map/MapPane.cpp`.

The function should remain a child function emitted through [UID:00007Q] `MapPane`, not an aggregate-only block. The aggregate `MapPaneWeatherCoordinateObjectCore` page can summarize and route the child but should not replace the child formal C++ block.

## Range / Split / Padding / Reclassification Analysis

The modeled IDA function is `0x00505650-0x0050571e`, but the documentation target range `0x00505650-0x00505730` is correct because the compiler placed the switch table immediately after the function return. This is a function-plus-attached-data target, not a pure function-size target.

Range facts:

- Pre-target padding: `0x00505645-0x00505650`, eleven `0xcc` bytes.
- Code body: `0x00505650-0x0050571e`, ending with `retn 8` at `0x0050571b`.
- Alignment: `0x0050571e-0x00505720`, bytes `66 90`.
- Jump table: `0x00505720-0x00505730`, four little-endian dwords to `0x00505680`, `0x005056a7`, `0x0050568d`, and `0x0050569a`.
- Successor: `0x00505730`, `nullsub_12`, one-byte `ret`.

No split or reclassification is recommended. The target path name and range should remain exactly `by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md`.

## Negative Evidence Summary

- No local recovered `MapPane`/`MapRect` UDT/type records exist in IDA.
- No external xrefs target `0x0050571e`; it is internal alignment before the jump table.
- No external dword route points at the function start, attached range start, or successor start in MCP/local PE scans.
- Only two rel32 calls target the function start, matching MCP `xrefs_to`.
- Successor `0x00505730` has its own xrefs and must not be merged into UID000428.
- Historical UID000428 RankingDialog material does not share this target path or address and must not be incorporated.

## IDA Rename / Type / Comment Recommendations

B014 did not mutate IDA names, types, comments, or process state.

Optional IDA-side recommendations if a supervisor/IDA maintainer chooses to apply them later:

- Rename `sub_505650` to a source-facing name equivalent to `MapPane::GetAdjacentVisibleTileBounds`.
- Comment `0x0050571e-0x00505730` as attached switch material for UID000428: two-byte align NOP plus four-entry direction jump table.
- Keep `jpt_505679` associated with `sub_505650`; do not classify the table as successor no-op padding.
- If introducing a local UDT later, model the rectangle as a four-int `MapRect`/`RectBounds` equivalent and `MapPane +0x3f4/+0x3f6` as map width/height fields, consistent with existing MapPane docs.

No IDA rename/type/comment action is required for the documentation callback.

## First-Draft C++ Recommendation

Use the following exact formal target block for `by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md`. This matches the current emitted source body and is the source-ready first-draft C++ preserved by the callback.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
unsigned short MapPane::GetAdjacentVisibleTileBounds(unsigned char direction,
                                                     MapRect *outBounds) const
{
    MapRect bounds;
    GetClampedVisibleTileBounds(&bounds);

    switch (direction)
    {
    case 0:
        bounds.bottom = bounds.top;
        --bounds.top;
        break;

    case 1:
        bounds.left = bounds.right;
        ++bounds.right;
        break;

    case 2:
        bounds.top = bounds.bottom;
        ++bounds.bottom;
        break;

    case 3:
        bounds.right = bounds.left;
        --bounds.left;
        break;

    default:
        SetRect(&bounds, 0, 0, 0, 0);
        break;
    }

    MapRect mapBounds;
    SetRect(&mapBounds, 0, 0, m_mapWidth, m_mapHeight);
    IntersectRect(&bounds, &mapBounds, &bounds);

    if (outBounds != NULL)
        *outBounds = bounds;

    return ComputeTileRectChecksum(&bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Notes for implementation:

- Do not emit raw `sub_505650`, `_OWORD`, `DWORD1`, `jpt_505679`, `sub_505290`, `sub_4B7C50`, `sub_4B7CC0`, or `sub_50C040` names in target C++.
- The exact spelling of `MapRect`, `IntersectRect`, and `ComputeTileRectChecksum` is source-facing/inferred, not IDA type-recovered. Current generated output and local docs already use these names; unresolved exact spelling is a confidence cap only.
- The raw helper call order for the intersection helper is `mapBounds`, adjusted bounds, output bounds. The intersection operation is commutative for this use; the existing source-shaped call is behavior-preserving. If the project later standardizes helper spelling/order globally, do that as a separate support cleanup rather than a UID000428 blocker.

## Final Recommendation

UID000428 callback implementation is applied and ready for supervisor execution review. The target is `COMPLETION:90`, `CONFIDENCE:92`, owner/emitter/reconstructable routing is unchanged, the formal C++ body is preserved, the jump-table range proof is recorded, and stale direct support docs now treat UID000428 as current source-ready MapPane C++.

No range split, ownership move, no-code downgrade, or generated/manual coverage edit is recommended.

## Recommended Target Doc Changes

For `by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md`:

- Applied: set `COMPLETION:90` and `CONFIDENCE:92`.
- Applied: preserved `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, and blank emitter position.
- Already present/preserved: the formal C++ remains the exact formal block from this report.
- Applied: added current MCP evidence for session `60724697`, health ok, exact function size `0xce`, modeled code range `0x00505650-0x0050571e`, attached switch material `0x0050571e-0x00505730`, direct callers `0x005a3235` and `0x005ad390`, callees/helper semantics, optional output copy, map width/height reads, no local UDTs, and local PE scan facts.
- Applied: recorded the attached jump-table bytes exactly: `66 90` at `0x0050571e-0x00505720`, then dwords `0x00505680`, `0x005056a7`, `0x0050568d`, `0x0050569a` at `0x00505720-0x00505730`.
- Applied: recorded that successor `0x00505730` is separate `nullsub_12` and is not part of this target's source body.
- Applied: added an alias-collision warning that this target is exact path/address-bound and must not incorporate unrelated historical RankingDialog/RankingCategoryRecord UID000428 material.

## Recommended Support Doc Changes

Applied where stale after supervisor callback:

- Applied: `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md` UID000428 row now reflects current `90/92` readiness, MCP session `60724697`, two direct callers, and exact attached jump-table split. Aggregate/no-duplicate-emission policy is preserved.
- Applied: `by-class/MapPane.md` coordinate/movement helper inventory now says UID000428 is current source-ready `MapPane::GetAdjacentVisibleTileBounds` with optional output bounds and child-owned jump table. Broader class field/header caveats are preserved.
- Applied: `by-file/MapPane.md` now records UID000428 as source-ready on the `NexusTK/map/MapPane.cpp` route. Unrelated open MapPane helper caveats are preserved.
- Excluded with reason: `by-memory/0x005a2e00-0x005a36de.LivingObjectPaneProcessMovement.md` was checked and not edited; it has no direct stale contradiction to UID000428 ownership/source readiness.
- Excluded with reason: `by-memory/0x005ad360-0x005ad441.LivingObjectPaneSendAttackTargetPacket.md` was checked and not edited; it has no direct stale contradiction to UID000428 ownership/source readiness.
- Excluded with reason: `by-memory/0x0066db4c-0x0066dd50.MapPaneChecksumLookupTable.md` was checked and not edited; it already documents checksum helper uncertainty and MapPane checksum-table ownership without contradicting UID000428.

Do not edit unrelated historical RankingDialog/RankingCategoryRecord pages as part of this callback unless a direct stale cross-reference to exact path `by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md` is found.

## Score And Metadata Recommendation

- Applied target score: `COMPLETION:90`, `CONFIDENCE:92`.
- Preserved `CANONICAL_OWNER:00007Q`.
- Preserved `RECONSTRUCTABLE:TRUE`.
- Preserved `EMITTER_UIDS:00007Q`.
- Preserved blank `EMITTER_POSITION_OPTIONAL`.

Rationale:

- Completion rises because the target already has source-shaped formal C++ and current evidence now validates every behavioral block, direct caller, field use, helper call, and attached switch table.
- Confidence rises because current MCP, local PE, generated output, and support docs agree.
- Confidence remains below higher bands because exact original helper/type/member spelling is inferred and no local `MapPane`/`MapRect` UDT was recovered.

## Open Questions With Attempted Resolution

| Question | Attempted resolution | Current disposition |
| --- | --- | --- |
| Are `MapRect`, `IntersectRect`, and `ComputeTileRectChecksum` exact original names? | Checked MCP `type_query` and helper/support docs; no local UDT/type records. Current docs/generated output use these names. | Not blocker; confidence cap only. |
| Does `0x0050571e-0x00505730` belong to UID000428? | Checked `lookup_funcs`, `entity_query`, `disasm`, `get_bytes`, `xrefs_to`, local PE scan. | Solved: yes, attached align NOP plus switch jump table. |
| Is successor `0x00505730` part of this target? | Checked `lookup_funcs`, bytes, xrefs. | Solved: no, it is separate `nullsub_12`. |
| Are the two callers sufficient to establish live use? | Checked MCP xrefs, caller disassembly, local PE rel32 scan. | Solved: yes, callers at `0x005a3235` and `0x005ad390`. |
| Does historical UID000428 RankingDialog material apply? | Searched report/docs for UID/address/name collisions. | Solved: no, reject by exact path/address mismatch. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual supervisor-owned coverage or tracker text is recommended for this callback.

B014 did not manually edit `-coverage-report.md`, `auto-generated/*`, validator state, lifecycle/archive state, or supervisor ledgers for UID000428. Scoped validators produced validator-owned generated/projected-stat refresh effects only.

## Follow-Up Actions

Callback follow-up state:

1. Applied: leased only the four edited by-* docs and released them after the edit/validator batch.
2. Applied: target metadata/evidence/C++ support changes are in `by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md`.
3. Applied: stale direct support docs were updated; caller/checksum support pages were excluded with reason because no direct stale contradiction was found.
4. Applied: scoped validators ran for every changed by-* doc from `source-3/project-documentation`.
5. Applied: generated `auto-generated/NexusTK/map/MapPane.cpp` was rechecked; UID000428 reflects `90/92` and emits exactly one source body.
6. Applied: this report's ledger/checklist now records applied/already-present/excluded states and validator command metadata.
7. Current required next step: supervisor Gate 2/execution review. B014 must not run `execute_report` or lifecycle/archive commands.

## Confidence

Confidence is high for behavior, owner, source placement, direct callers, range, jump-table ownership, and target C++ readiness. The remaining uncertainty is limited to exact original helper/type/member spelling because IDA has no recovered local `MapPane`/`MapRect` UDT and helper names are documentation/source-quality inferences. That uncertainty caps confidence at `92` rather than blocking the formal C++.

## Validator Results

Scoped validators were run from `source-3/project-documentation` for every changed by-* doc:

| File | Command | Timestamp | Exit | ok | Warnings / side effects |
| --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md` | `python .\tools\validator.py --mode file --file by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md --apply --queue-timeout 240` | `2026-07-04T12:24:55-04:00` / `000000006288` | 0 | 1 | `completion_update:1`, `confidence_update:1`, `missing_ref_uid:2` for caller UIDs `0003U6`/`0003V0`, `uid_link_insert:2`, `reference_index_add:3`, `stats_row_remove:1`, `stats_rescore_recommended:1`, `projected_stats_update:1`, generated refresh deferred. |
| `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md` | `python .\tools\validator.py --mode file --file by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md --apply --queue-timeout 240` | `2026-07-04T12:24:58-04:00` / `000000006289` | 0 | 1 | `uid_link_insert:2` for UID000429, `stats_incremental_noop:1`, `projected_stats_update:1`, generated refresh deferred. |
| `by-class/MapPane.md` | `python .\tools\validator.py --mode file --file by-class/MapPane.md --apply --queue-timeout 240` | `2026-07-04T12:25:00-04:00` / `000000006290` | 0 | 1 | Existing support-page `missing_ref_uid:89` warnings, `stats_row_update:1`, `projected_stats_update:1`, generated refresh deferred. |
| `by-file/MapPane.md` | `python .\tools\validator.py --mode file --file by-file/MapPane.md --apply --queue-timeout 240` | `2026-07-04T12:25:11-04:00` / `000000006291` | 0 | 1 | Existing support-page `missing_ref_uid:100` warnings, `reference_index_add:1` for UID000429, `stats_row_update:1`, `projected_stats_update:1`, generated refresh deferred. |

Generated-output check was read-only:

- File: `auto-generated/NexusTK/map/MapPane.cpp`
- Header command after validators: `validator-command-id: 000000006290`
- Refreshed: `2026-07-04T12:25:00-04:00`
- Current UID000428 generated state: one source body present at lines 498-540 with `Completion:90 | Confidence:92`.
- Freshness caveat: generated header command `000000006290` is older than final support-doc validator `000000006291`, but UID000428 target metadata/body already reflects the callback. No generated file was manually edited.

## Changed Files

Edited by B014 in this callback:

- `by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md`
- `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`
- `by-class/MapPane.md`
- `by-file/MapPane.md`
- `tools/leaser/Agents/Agent-B014/research/000428-MapPaneGetAdjacentVisibleTileBounds-source-quality.md`

Validator-owned side effects reported by scoped validators:

- `auto-generated/NexusTK/map/MapPane.cpp` refreshed by validator; UID000428 now reflects `90/92`.
- `project-level/-auto-completion-stats.md` projected stats were updated by validator output.
- Validator reference/index updates were reported by the validator commands. B014 did not manually edit validator state.

Leases used/released:

- Acquired with `python .\tools\leaser\leaser.py B014 lease ...`: target, aggregate, `by-class/MapPane.md`, and `by-file/MapPane.md` all returned `Success`.
- Released with `python .\tools\leaser\leaser.py B014 unlease ...`: the same four files all returned `Success`.
- Post-release lease report `tools/leaser/Agents/current_leases.md` showed no active B014 leases.

No caller/checksum pages were edited. No `-coverage-report.md`, manual generated file, lifecycle/archive file, report move, or supervisor ledger edit was performed by B014.

## Implementation Tracking Checklist

| Claim ID | Implementation-verifiable item | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- |
| C-001 | Reject historical UID000428 alias material and keep all claims bound to exact MapPane target path/address. | Target evidence/status notes; support docs where stale. | reject-invalid | applied - target/class/file notes now reject the RankingDialog alias for this exact MapPane path/address. |
| C-002 | Set target to `COMPLETION:90`, `CONFIDENCE:92`, preserving owner/emitter/reconstructable/emitter-position metadata. | `by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md` metadata. | incorporate | applied - target metadata lines 2-7. |
| C-003 | Preserve/insert the exact formal C++ block from this report; do not substitute a body-only snippet. | Target `RECONSTRUCTION_CPP CODE` block. | already-present | already-present - target block and generated output preserved. |
| C-004 | Add current MCP session `60724697` evidence at report-level detail. | Target evidence; aggregate/class/file summaries. | incorporate | applied - target, aggregate, class, and file docs now name session `60724697` and exact evidence. |
| C-005 | Document attached switch material `0x0050571e-0x00505730`, including two-byte NOP and jump table entries. | Target range/padding notes; aggregate UID000428 row. | incorporate | applied - target/support docs record `66 90` plus four dwords and successor split. |
| C-006 | Document the two direct callers and confirm they are consumers, not owners. | Target xref/caller evidence; support docs. | incorporate | applied - target/support docs record `0x005a3235` and `0x005ad390` as consumer call sites. |
| C-007 | Document local PE/MCP negative route facts and exact two rel32 hits. | Target negative evidence/route-scan notes. | incorporate | applied - target/support docs record no-extra-route proof and exact two rel32 callers. |
| C-008 | Record absent recovered UDT/type and helper-name spelling caveats as confidence caps only. | Target open questions/caveats; support docs. | incorporate | applied - target/support docs record no recovered local `MapPane`/`MapRect` UDT and confidence-cap caveat. |
| C-009 | Keep decompiler/raw IDA names out of formal C++; preserve source-shaped helper/member names. | Target formal C++ and implementation notes. | reject-stale | applied - formal C++ remains source-shaped; raw names appear only in evidence. |
| C-010 | Sync aggregate/class/file support docs where stale with UID000428 `90/92`, source readiness, and jump-table ownership. | `MapPaneWeatherCoordinateObjectCore`, `by-class/MapPane.md`, `by-file/MapPane.md`. | incorporate | applied - all three support docs updated and validated. |
| C-011 | Edit caller/checksum support pages only if a direct stale contradiction is found. | LivingObjectPane caller pages; checksum table page. | incorporate | excluded-with-reason - pages checked; no direct contradiction found, so no edit/validator required. |
| C-012 | Run scoped file validators only for changed by-* docs after callback. | Callback `Validator Results`; changed by-* docs. | incorporate | applied - commands `000000006288` through `000000006291`, exit `0`, `ok:1`. |
| C-013 | Recheck generated `auto-generated/NexusTK/map/MapPane.cpp` after validators for refreshed UID000428 metadata/body. | Callback generated freshness note. | incorporate | applied - generated UID000428 now shows `90/92` and one source body. |
| C-014 | Leave manual coverage/tracker files untouched; no manual supervisor-owned text is required. | Coverage/tracker files; report coverage section. | not-applicable | excluded-with-reason - no manual coverage/tracker edit was needed or performed. |
| C-015 | Continue respecting forbidden-action boundary: no execute/probe/lifecycle/generated/coverage/validator-state/supervisor-ledger edits by B014. | B014 process boundary; final response. | not-applicable | applied - B014 ran only scoped file validators and no forbidden lifecycle/mutation commands. |

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000006303","destination_path":"executed-b-agent-research/B014/000428-MapPaneGetAdjacentVisibleTileBounds-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B014/research/000428-MapPaneGetAdjacentVisibleTileBounds-source-quality.md","timestamp":"2026-07-04T12:38:03-04:00","uid":"000428"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
