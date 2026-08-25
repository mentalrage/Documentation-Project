# UID0000NQ Removed Operational Material

- Source report: [0000NQ-SimpleListPane-file-source-quality.md](0000NQ-SimpleListPane-file-source-quality.md)
- Source revision: failed Gate 1 artifact SHA256 `665F0A2A2AA9A773E6051194D7BB464A546AB49F6AC881F77D7D00B0CFC01F58`.
- Status: inert, non-authoritative archival companion. The source report's semantic TG/I/P/D/R records remain the only B009 handoff content.
- Warning: never execute or use this material as a runtime, process, backup, mutation, save, verification, or rollback procedure. It receives no Gate 1, Gate 2, coverage, validation, or lifecycle credit and is not an `execute_report` input.
- Preservation rule: the blocks below are retained verbatim from the failed source revision, including stale words such as `Current`; they are historical quotations only.

## Verbatim Removed Section 21 Transaction Block

Transaction contract and failure boundary:

- Immediately before any future mutation, the supervisor must re-list sessions, require the exact canonical database path/session, require `server_health.status:ok`, require Hex-Rays ready, and obtain a fresh schema-1 `runtime_attestation` payload `{expected_database:"<fresh exact session>", expected_canonical_path:"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64"}` with `ok:true` and `errors:[]`. Compare listener nonce/PID/generation, returned worker route, worker nonce/PID/parent/generation, canonical session/path, both implementation manifests, and module `file/spec_origin/resolved_path/SHA256` equality to the accepted runtime. Any mismatch stops before a write.
- Repeat that complete attestation immediately before read-only gate `TG00`, before each of the thirty-two atomic mutation rows, immediately before the single save, and after opening the separate verifier. A nonce may change only with a freshly explained generation/route transition; PID equality without creation-time equality is not process identity. A route, generation, origin, manifest, module hash, canonical-path, or active-session mismatch stops with no further write/save.
- Create and verify a collision-safe supervisor backup before the first mutation row. Record closed-disk canonical and backup SHA256/bytes/last-write identity before opening the mutation worker; do not use or overwrite an existing backup name. The backup is the only rollback source.
- Verify read-only prerequisites `TP00` and `TG00` before mutation step 01. Public `declare_type` is prohibited throughout this transaction: no function type depends on a separately installed `SimpleListPane` declaration. Proposed function names must be absent globally except at their proposed address. Every rename uses the exact row address/name with `pure:true`, `allow_overwrite:false`, `dry_run:false`, and `stop_on_error:true`; no collision may be overwritten or auto-suffixed.
- Execute the thirty-two claim rows in the literal atomic-order table below. For raw functions this preserves `define_func` with explicit start/end, extent readback, `rename`, name readback, self-contained `set_type`, type/frame readback, then comment write and all-channel readback. For modeled functions it preserves `rename`, self-contained `set_type`, then comment write, with readback after each step. No later atomic row may run after any unexpected extent, name, type, AR/AP/FR/FP channel, or frame result.
- Do not save on a prestate, collision, parser, define, rename, type, comment, frame, protection, attestation, or readback mismatch. If TG00, all thirty-two atomic mutation rows, and all twenty-three protection rows pass, perform exactly one supervisor save, close the mutation worker, reopen a separate verifier, repeat the full runtime attestation and final action/protection readback, then close it and record the closed-disk identity.
- Rollback closure is fail-closed: first close mutation/verifier sessions; then require `idb_list` plus a fresh listener attestation to show no active session or worker route for the canonical path. Match process generations, not PIDs: a reused PID with a different creation time is a different process and does not satisfy closure. With no active canonical worker, an exclusive `FileShare.None` open probe on the canonical `.i64` must succeed and be closed before replacement. Reread canonical/backup SHA256/bytes/last-write identities, restore only from the preverified backup, repeat the exclusive probe, and require the restored closed-disk identity to equal the backup before any reopen. A sharing violation, active route, generation ambiguity, identity mismatch, or failed probe blocks rollback/reopen; no in-place repair or second save is allowed.

## Verbatim Removed Collision Payload Introduction

Current destination-name collision-query receipts from dated session `supervisor-uid0000IW-recovery-20260814`; endpoint `lookup_funcs`, payload `database:<that session>, queries:[exact proposed names]`:

## Verbatim Removed Mutation API Schema

Current mutation API schema and exact payload forms; these are declarative records, not an executable transaction:

| Purpose | Endpoint and exact current-schema payload form |
| --- | --- |
| TG00 read-only no-declare gate | `type_inspect` with `{database:D, queries:{name:"SimpleListPane", include_members:true, max_members:16}}` plus `type_query` with `{database:D, queries:{filter:"*SimpleListPane*", kind:"any", count:100, include_decl:true, include_members:true}}`; no `declare_type` call is authorized. |
| Raw I01/I03-I06 definitions | `define_func` with `{database:D, items:{addr:"<row start>", end:"<row exclusive end>"}}`; one call per row and exact extent readback before rename. |
| I01-I09 names | `rename` with `{database:D, batch:{func:{addr:"<row start>", name:"<exact row name>"}, pure:true, allow_overwrite:false, dry_run:false, stop_on_error:true}}`; rerun `lookup_funcs` by address and exact name after each row. |
| I01-I09 function types | `set_type` with `{database:D, edits:{addr:"<row start>", kind:"function", signature:"<exact self-contained row signature>"}}`; require one `ok:true` result with no error, then read back the exact pointer meanings and frame before comments. I01-I06/I09 submit `struct SimpleListPane *` in every class-pointer position; IDA may normalize only the redundant `struct` spelling, never the pointer target, calling convention, name, return, arguments, qualifiers, or frame. |
| I01-I06/I09 function comments | `set_function_comments` with `{database:D, items:{addr:"<row start>", comment:"<exact FR text>"}}`; this changes FR only. |
| I07/I08 address comments | `set_address_comments` with `{database:D, items:{addr:"<row start>", comment:"<exact replacement AR text>"}}`; this changes regular disassembly AR only and never invokes Hex-Rays. |
| Comment verification | `get_comments` with `{database:D, addrs:["<row start>"]}` and require literal regular/repeatable address plus regular/repeatable function channels. |
| Function/frame verification | `lookup_funcs`, function query/profile, and `stack_frame` against each exact row address; require extent/name/type plus every current/expected frame row below. |

## Verbatim Removed Literal 32-Step Order

Literal atomic mutation order; every row is one independently stoppable ledger/checklist claim, and the endpoint payload/readback contract above applies without batching across rows:

| Step | Claim row | One permitted write | Required immediate readback before next step |
| --- | --- | --- | --- |
| 01 | `C0000NQ-038-I01` | `define_func` `0x005739a0-0x005739f6` | exact function extent only |
| 02 | `C0000NQ-038-I01-RENAME` | pure `rename` at `0x005739a0` | exact name/address and no suffix/collision |
| 03 | `C0000NQ-038-I01-TYPE` | `set_type` to the literal self-contained I01 signature | exact pointer meanings and five-row frame |
| 04 | `C0000NQ-038-I01-COMMENT` | `set_function_comments` FR only | literal FR; AR/AP/FP absent |
| 05 | `C0000NQ-038-I02` | pure `rename` at `0x00573a00` | exact name/address and unchanged extent |
| 06 | `C0000NQ-038-I02-TYPE` | `set_type` to the literal self-contained I02 signature | exact pointer meaning and protected four-row frame |
| 07 | `C0000NQ-038-I02-COMMENT` | `set_function_comments` FR only | literal FR; AR/AP/FP absent |
| 08 | `C0000NQ-038-I03` | `define_func` `0x00573aa0-0x00573b08` | exact function extent only |
| 09 | `C0000NQ-038-I03-RENAME` | pure `rename` at `0x00573aa0` | exact name/address and no suffix/collision |
| 10 | `C0000NQ-038-I03-TYPE` | `set_type` to the literal self-contained I03 signature | exact pointer/argument meanings and five-row frame |
| 11 | `C0000NQ-038-I03-COMMENT` | `set_function_comments` FR only | literal FR; AR/AP/FP absent |
| 12 | `C0000NQ-038-I04` | `define_func` `0x00573b10-0x00573b6d` | exact function extent only |
| 13 | `C0000NQ-038-I04-RENAME` | pure `rename` at `0x00573b10` | exact name/address and no suffix/collision |
| 14 | `C0000NQ-038-I04-TYPE` | `set_type` to the literal self-contained I04 signature | exact pointer/argument meanings and five-row frame |
| 15 | `C0000NQ-038-I04-COMMENT` | `set_function_comments` FR only | literal FR; AR/AP/FP absent |
| 16 | `C0000NQ-038-I05` | `define_func` `0x00573b70-0x00573bac` | exact function extent only |
| 17 | `C0000NQ-038-I05-RENAME` | pure `rename` at `0x00573b70` | exact name/address and no suffix/collision |
| 18 | `C0000NQ-038-I05-TYPE` | `set_type` to the literal self-contained I05 signature | exact pointer/argument meanings and three-row frame |
| 19 | `C0000NQ-038-I05-COMMENT` | `set_function_comments` FR only | literal FR; AR/AP/FP absent |
| 20 | `C0000NQ-038-I06` | `define_func` `0x00573bb0-0x00573c38` | exact function extent only |
| 21 | `C0000NQ-038-I06-RENAME` | pure `rename` at `0x00573bb0` | exact name/address and no suffix/collision |
| 22 | `C0000NQ-038-I06-TYPE` | `set_type` to the literal self-contained I06 signature | exact pointer/argument meanings and four-row frame |
| 23 | `C0000NQ-038-I06-COMMENT` | `set_function_comments` FR only | literal FR; AR/AP/FP absent |
| 24 | `C0000NQ-038-I07` | pure `rename` at `0x00573c38` | exact name/address and unchanged extent |
| 25 | `C0000NQ-038-I07-TYPE` | `set_type` to the literal I07 signature | exact type and protected sole frame row |
| 26 | `C0000NQ-038-I07-COMMENT` | `set_address_comments` AR only | literal replacement AR; AP/FR/FP absent |
| 27 | `C0000NQ-038-I08` | pure `rename` at `0x00573c43` | exact name/address and unchanged extent |
| 28 | `C0000NQ-038-I08-TYPE` | `set_type` to the literal I08 signature | exact type and protected sole frame row |
| 29 | `C0000NQ-038-I08-COMMENT` | `set_address_comments` AR only | literal replacement AR; AP/FR/FP absent |
| 30 | `C0000NQ-038-I09` | pure `rename` at `0x00573c50` | exact name/address and unchanged extent |
| 31 | `C0000NQ-038-I09-TYPE` | `set_type` to the literal self-contained I09 signature | exact pointer meanings and sole permitted frame delta |
| 32 | `C0000NQ-038-I09-COMMENT` | `set_function_comments` FR only | literal FR; AR/AP/FP absent |

The exact rename rows are therefore `0x005739a0/SimpleListPane_Constructor`, `0x00573a00/SimpleListPane_Destructor`, `0x00573aa0/SimpleListPane_AppendText`, `0x00573b10/SimpleListPane_InsertText`, `0x00573b70/SimpleListPane_RemoveText`, `0x00573bb0/SimpleListPane_ReplaceText`, `0x00573c38/SimpleListPane_ScalarDeletingDestructor_AdjustA0`, `0x00573c43/SimpleListPane_ScalarDeletingDestructor_AdjustA4`, and `0x00573c50/SimpleListPane_ScalarDeletingDestructor`, each under the transaction-wide pure/collision flags above.

## Verbatim Removed Related Operational Prose

- Runtime availability receipt: at `2026-08-14T16:43:40.502861+00:00`, session `supervisor-uid0000IW-recovery-20260814` was responsive, `server_health.status` was `ok`, Hex-Rays and the strings cache were ready, and schema-1 `runtime_attestation` returned `ok:true` with top-level and worker `errors:[]` for the exact canonical path. `auto_analysis_ready:false` was recorded as context; all required bounded live queries succeeded. This is read-only evidence and must be refreshed at every mutation boundary; it is not a permanent session assertion.

Negative constraints are complete: do not create functions over P01-P07; do not call `declare_type`; do not force a complete `0x14c` UDT; do not rename inherited table slots; do not convert D/R bytes to source globals; do not absorb D07 or code successor `0x00573d20`; do not normalize existing comments. No further caller/type/frame/protection investigation is delegated to Gate 2B: that phase may only verify TG00, compare these literal prestates, apply the thirty-two atomic I claim rows in order, verify all twenty-three P/D/R claim rows, and stop on any divergence.

- Apply only the declarative Gate 2B sequence in section 21: verify `TP00` and read-only no-`declare_type` gate `TG00`, execute the thirty-two atomic I rows in literal order, and verify `P01-P07`, `D01-D07`, `R01-R06`, `R07`, `R07B`, and `R08` unchanged. These are one read-only gate, thirty-two mutation rows, and twenty-three protection rows; all other IDA entities remain outside scope.

- Supervisor Gate 2B: verify `TP00` and C038-TG00, then apply the thirty-two C038 mutation rows directly through MCP in their recorded atomic order; never call `declare_type`; verify the twenty-three C039 protection rows and stop without save on any mismatch.

- [ ] Supervisor Gate 2B IDA handoff remains supervisor-owned and unapplied: one read-only no-`declare_type` gate, thirty-two ordered atomic mutation rows, and twenty-three protected no-change rows.
